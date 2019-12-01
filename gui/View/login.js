const { ipcRenderer } = require('electron');
const common = require('./common.js');

let loginID_dom = null;
let loginPW_dom = null;

function login() {
    let id = common.Field_getValue(loginID_dom);
    let pw = common.Field_getValue(loginPW_dom);

    if (!id || !pw) {
        if (!id) {
            common.Field_setInvalid(loginID_dom);
        }
        if (!pw) {
            common.Field_setInvalid(loginPW_dom);
        }
    } else {
        ipcRenderer.send('login', {
            id: common.Field_getValue(loginID_dom),
            pw: common.Field_getValue(loginPW_dom)
        });
    }
}

window.onload = function() {
    loginID_dom = document.getElementById('login-id');
    loginPW_dom = document.getElementById('login-pw');

    common.Field_addTransition(loginID_dom);
    common.Field_addTransition(loginPW_dom);

    common.Field_invokeWithEnter(loginID_dom, login);
    common.Field_invokeWithEnter(loginPW_dom, login);
}
