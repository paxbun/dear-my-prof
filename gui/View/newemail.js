const { ipcRenderer } = require('electron');
const common = require('./common.js');

let data = null;
let subjectField_dom = null;
let toField_dom = null;
let ccField_dom = null;
let bccField_dom = null;
let contentField_dom = null;

function splitAndTrim(arr) {
    let split = arr.split(';');
    let rtn = [];
    for (let i in split) {
        let trim = split[i].trim();
        if (trim)
            rtn.push([trim, '']);
    }
    return rtn;
}

function sendEmail() {
    let subject = common.Field_getValue(subjectField_dom);
    let to = [common.Field_getValue(toField_dom), ''];
    let cc = splitAndTrim(common.Field_getValue(ccField_dom));
    let bcc = splitAndTrim(common.Field_getValue(bccField_dom));
    let content = common.Field_getValue(contentField_dom);
    ipcRenderer.send('send-email', {
        subject: subject,
        to: to,
        cc: cc,
        bcc: bcc,
        content: content
    });
}

window.onload = function () {
    subjectField_dom = document.getElementById('subject-field');
    toField_dom = document.getElementById('to-field');
    ccField_dom = document.getElementById('cc-field');
    bccField_dom = document.getElementById('bcc-field');
    contentField_dom = document.getElementById('content-field');

    common.Field_preventMultiline(subjectField_dom);
    common.Field_preventMultiline(toField_dom);
    common.Field_preventMultiline(ccField_dom);
    common.Field_preventMultiline(bccField_dom);
    common.setTitle('Dear My Professor - 새 메일 작성하기');
    common.setLoading();
    ipcRenderer.send('data');
}

ipcRenderer.on('data-reply', (event, arg) => {
    data = arg;
    common.Field_getValueDom(subjectField_dom).innerText = data.subject;
    common.Field_getValueDom(toField_dom).innerText = data.to;
    common.Field_getValueDom(contentField_dom).innerText = data.content;
    common.unsetLoading();
}).on('send-email-failed', (event, arg) => {
    alert('전송에 실패하였습니다.');
})