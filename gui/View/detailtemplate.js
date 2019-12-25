const { ipcRenderer } = require('electron');
const common = require('./common.js');

let templateTitle_dom = null;
let templateSubtitle_dom = null;
let templateBody_dom = null;

function getDataId() {
    const prefix = '---data-id=';
    for (let i in window.process.argv) {
        let str = window.process.argv[i];
        if (str.startsWith(prefix))
            return str.substring(prefix.length);
    }
    return 'null';
}

function refreshDetail() {
    common.setLoading();
    ipcRenderer.send('detail-template-refresh', {
        id: getDataId()
    });
}

window.onload = function() {
    templateTitle_dom = document.getElementById('template-title');
    templateSubtitle_dom = document.getElementById('template-subtitle');
    templateBody_dom = document.getElementById('template-body');
    common.setTitle('Dear My Professor');
    refreshDetail();
}

ipcRenderer.on('detail-refresh-reply', (event, arg) => {
    common.unsetLoading();
    common.setTitle('Dear My Professor - ' + arg.theme);
    templateTitle_dom.innerText = arg.theme;
    templateSubtitle_dom.innerText = arg.subject;
    templateBody_dom.innerText = arg.content;
});