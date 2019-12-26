const { ipcRenderer } = require('electron');
const common = require('./common.js');

let professorSearch_dom = null;
let professorList_dom = null;

window.onload = function () {
    professorList_dom = document.getElementById('professor-list');
    common.setTitle('Dear My Professor - 교수님 선택');

    
    professorSearch_dom = document.getElementById('professor-search');
    common.Field_preventMultiline(professorSearch_dom);
    common.Field_getValueDom(professorSearch_dom)
        .addEventListener('input', (event) => {
            let value = common.Field_getValue(professorSearch_dom);
            if (value){
                ipcRenderer.send('professor', {
                    query: value
                });
            }
        });
}

let data = null;

ipcRenderer.on('professor-reply', (event, arg) => {
    common.clearChild(professorList_dom);

    if (Object.keys(arg).length == 0) {
        common.Field_setInvalid(professorSearch_dom);
    } else {
        for (let i in arg) {
            let email = i;
            let name = arg[i];
            if (!name)
                name = '알 수 없음';
            let item = common.ItemTwo_new(name, email);
            item.addEventListener('click', (event) => {
                ipcRenderer.send('create-fill-template',  {
                    name: name,
                    to: email
                });
            });
            professorList_dom.appendChild(item);
        }
    }
});