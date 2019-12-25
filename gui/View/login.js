const { ipcRenderer } = require('electron');
const common = require('./common.js');

let loginId_dom = null;
let loginPw_dom = null;
let loginName_dom = null;
let loginSid_dom = null;

function login() {
    let id = common.Field_getValue(loginId_dom);
    let pw = common.Field_getValue(loginPw_dom);
    let name = common.Field_getValue(loginName_dom);
    let sid = common.Field_getValue(loginSid_dom);

    if (!id || !pw || !name || !sid) {
        if (!id) {
            common.Field_setInvalid(loginId_dom);
        }
        if (!pw) {
            common.Field_setInvalid(loginPw_dom);
        }
        if (!name) {
            common.Field_setInvalid(loginName_dom);
        }
        if (!sid) {
            common.Field_setInvalid(loginSid_dom);
        }
    } else {
        common.setLoading();
        ipcRenderer.send('login', {
            id: common.Field_getValue(loginId_dom),
            pw: common.Field_getValue(loginPw_dom),
            name: common.Field_getValue(loginName_dom),
            sid: common.Field_getValue(loginSid_dom)
        });
    }
}

window.onload = function () {
    loginId_dom = document.getElementById('login-id');
    loginPw_dom = document.getElementById('login-pw');
    loginName_dom = document.getElementById('login-name');
    loginSid_dom = document.getElementById('login-sid');

    common.Field_addTransition(loginId_dom);
    common.Field_addTransition(loginPw_dom);
    common.Field_addTransition(loginName_dom);
    common.Field_addTransition(loginSid_dom);

    common.Field_invokeWithEnter(loginId_dom, login);
    common.Field_invokeWithEnter(loginPw_dom, login);
    common.Field_invokeWithEnter(loginName_dom, login);
    common.Field_invokeWithEnter(loginSid_dom, login);

    common.setTitle('Dear My Professor - 로그인');
};

ipcRenderer.on('login-failed', (event, arg) => {
    common.Field_setInvalid(loginId_dom);
    common.Field_setInvalid(loginPw_dom);
    common.Field_setInvalid(loginName_dom);
    common.Field_setInvalid(loginSid_dom);
    common.unsetLoading();
});