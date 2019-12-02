const { ipcRenderer } = require('electron');
const common = require('./common.js');

let emailTitle_dom = null;
let emailSubtitle_dom = null;
let emailBody_dom = null;

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
    ipcRenderer.send('detail-refresh', {
        dataId: getDataId()
    });
}

window.onload = function() {
    emailTitle_dom = document.getElementById('email-title');
    emailSubtitle_dom = document.getElementById('email-subtitle');
    emailBody_dom = document.getElementById('email-body');
    common.setTitle('Dear My Professor');
    refreshDetail();
}

ipcRenderer.on('detail-refresh-reply', (event, arg) => {
    common.unsetLoading();
    common.setTitle('Dear My Professor - ' + arg.title);
    emailTitle_dom.innerText = arg.title;
    emailSubtitle_dom.innerText = arg.subtitle;
    emailBody_dom.innerText = arg.body;
});