const { ipcRenderer } = require('electron');
const common = require('./common.js');

let emailTitle_dom = null;
let emailSubtitle_dom = null;
let emailBody_dom = null;

function refreshDetail() {
    common.setLoading();
    ipcRenderer.send('detail-refresh');
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
    common.setTitle('Dear My Professor - ' + arg.subject);
    emailTitle_dom.innerText = arg.subject;
    emailSubtitle_dom.innerText = arg.from;
    emailBody_dom.innerText = arg.content;
});