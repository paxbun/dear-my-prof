const { ipcRenderer } = require('electron');
const common = require('./common.js');

let templateList_dom = null;

function refreshMailList() {
    common.setLoading();
    ipcRenderer.send('template-refresh');
}

window.onload = function () {
    templateList_dom = document.getElementById('template-list');
    common.setTitle('Dear My Professor - 템플릿 목록');
    refreshMailList();
}

ipcRenderer.on('template-refresh-reply', (event, arg) => {
    for (let i in arg) {
        let item = common.ItemThree_new(arg[i].theme, arg[i].subject, arg[i].content);
        item.addEventListener('click', (event) => {
            ipcRenderer.send('create-detail-template-window',  {
                id: arg[i].id
            });
        });
        templateList_dom.appendChild(item);
    }

    common.unsetLoading();
});