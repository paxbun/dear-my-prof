const { ipcRenderer } = require('electron');
const common = require('./common.js');

let mailList_dom = null;

function refreshMailList() {
    common.setLoading();
    ipcRenderer.send('mail-refresh');
}

function openNewEmail() {
    ipcRenderer.send('create-new-email-window');
}

function openTemplates() {
    ipcRenderer.send('create-templates-window');
}

window.onload = function () {
    mailList_dom = document.getElementById('mail-list');
    common.setTitle('Dear My Professor - 메일함');
    refreshMailList();
}

ipcRenderer.on('mail-refresh-reply', (event, arg) => {
    for (let i in arg) {
        let item = common.ItemThree_new(arg[i].title, arg[i].subtitle, arg[i].body);
        item.addEventListener('click', (event) => {
            ipcRenderer.send('create-detail-window',  {
                dataId: arg[i].dataId
            });
        });
        mailList_dom.appendChild(item);
    }

    common.unsetLoading();
});