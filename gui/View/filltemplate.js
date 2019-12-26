const { ipcRenderer } = require('electron');
const common = require('./common.js');

let templateParamsList_dom = null;
let templateSubject_dom = null;
let templateContent_dom = null;
let initialized = false;
let paramMap = {};
let data = null;
let environment = null;
let fillSent = false;
let subject = null;
let content = null;

function loadParams() {
    let rtn = {};
    for (let param_name in paramMap) {
        let value = common.ItemTwoEditable_getValue(paramMap[param_name]);
        if (value)
            rtn[param_name] = value;
    }
    return rtn;
}

function fillTemplate() {
    if (!fillSent) {
        fillSent = true;
        ipcRenderer.send('template-fill', loadParams());
    }
}

function newEmail() {
    ipcRenderer.send('create-new-email', {
        to: data.to,
        subject: subject,
        content: content
    });
}

window.onload = function () {
    templateParamsList_dom = document.getElementById('template-params-list');
    templateSubject_dom = document.getElementById('template-subject');
    templateContent_dom = document.getElementById('template-content');
    common.setTitle('Dear My Professor');
    common.setLoading();
    ipcRenderer.send('data');
}

ipcRenderer.on('data-reply', (event, arg) => {
    data = arg;
    common.setTitle('Dear My Professor - ' + data.theme);
    ipcRenderer.send('environment');
}).on('environment-reply', (event, arg) => {
    environment = arg;
    ipcRenderer.send('template-init');
}).on('template-out', (event, arg) => {
    fillSent = false;
    templateSubject_dom.innerText = subject = arg.subject;
    templateContent_dom.innerText = content = arg.content;
    if (!initialized) {
        ipcRenderer.send('template-params');
        initialized = true;
    }
}).on('template-params-reply', (event, arg) => {
    for (let i in arg) {
        let param_name = arg[i];
        let param_dom = common.ItemTwoEditable_new(param_name);
        paramMap[param_name] = param_dom;
        let value_dom = common.ItemTwoEditable_getValueDom(param_dom);
        if (environment[param_name] != undefined)
            value_dom.innerText = environment[param_name];
        value_dom.addEventListener('input', (event) => {
            fillTemplate();
        });
        templateParamsList_dom.appendChild(param_dom);
        ipcRenderer.send('template-fill', environment);
    }
    common.unsetLoading();
})