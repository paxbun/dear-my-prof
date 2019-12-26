const { ipcRenderer } = require('electron');
const common = require('./common.js');

let templateTitle_dom = null;
let templateSubtitle_dom = null;
let templateBody_dom = null;

function refreshDetail() {
    common.setLoading();
    ipcRenderer.send('detail-template-refresh');
}

window.onload = function() {
    templateTitle_dom = document.getElementById('template-title');
    templateSubtitle_dom = document.getElementById('template-subtitle');
    templateBody_dom = document.getElementById('template-body');
    common.setTitle('Dear My Professor');
    refreshDetail();
}

ipcRenderer.on('detail-template-refresh-reply', (event, arg) => {
    common.unsetLoading();
    common.setTitle('Dear My Professor - ' + arg.theme);
    templateTitle_dom.innerText = arg.theme;
    templateSubtitle_dom.innerText = arg.subject;
    templateBody_dom.innerText = arg.content;
});