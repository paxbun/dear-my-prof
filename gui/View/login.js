const { ipcRenderer } = require('electron');
const common = require('./common.js');

let loginId_dom = null;
let loginPw_dom = null;

function login() {
    let id = common.Field_getValue(loginId_dom);
    let pw = common.Field_getValue(loginPw_dom);

    if (!id || !pw) {
        if (!id) {
            common.Field_setInvalid(loginId_dom);
        }
        if (!pw) {
            common.Field_setInvalid(loginPw_dom);
        }
    } else {
        ipcRenderer.send('login', {
            id: common.Field_getValue(loginId_dom),
            pw: common.Field_getValue(loginPw_dom)
        });
    }
}

window.onload = function() {
    loginId_dom = document.getElementById('login-id');
    loginPw_dom = document.getElementById('login-pw');

    common.Field_addTransition(loginId_dom);
    common.Field_addTransition(loginPw_dom);

    common.Field_invokeWithEnter(loginId_dom, login);
    common.Field_invokeWithEnter(loginPw_dom, login);
}
