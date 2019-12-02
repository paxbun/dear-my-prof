const { ipcRenderer } = require('electron');
const common = require('./common.js');

let mailList_dom = null;

function refreshMailList() {
    common.setLoading();
    ipcRenderer.send('mail-refresh');
}

window.onload = function () {
    mailList_dom = document.getElementById('mail-list');
    common.setTitle('Dear My Professor - 메일함');
    refreshMailList();
}

ipcRenderer.on('mail-refresh-reply', (event, arg) => {
    for (let i in arg) {
        mailList_dom.appendChild(
            common.ItemThree_new(arg[i].title, arg[i].subtitle, arg[i].body)
        );
    }

    common.unsetLoading();
});