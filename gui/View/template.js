const { ipcRenderer } = require('electron');
const common = require('./common.js');

let templateList_dom = null;

function refreshTemplateList() {
    common.setLoading();
    ipcRenderer.send('template-refresh');
}

window.onload = function () {
    templateList_dom = document.getElementById('template-list');
    common.setTitle('Dear My Professor - 템플릿 목록');
    refreshTemplateList();
}

ipcRenderer.on('template-refresh-reply', (event, arg) => {
    common.clearChild(templateList_dom);

    for (let i in arg) {
        let item = common.ItemThree_new(arg[i].theme, arg[i].subject, arg[i].content);
        item.addEventListener('click', (event) => {
            ipcRenderer.send('create-detail-template-window',  {
                theme: arg[i].theme
            });
        });
        templateList_dom.appendChild(item);
    }

    common.unsetLoading();
});