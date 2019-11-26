const { ipcRenderer } = require('electron');

var contentList;

function createDivWithClass(data, className) {
    
    let dom = document.createElement('div');
    dom.className = className;
    
    if (typeof(data) === 'string') {
        let domText = document.createTextNode(data);
        dom.appendChild(domText);
    } else {
        for (let i in data) dom.appendChild(data[i]);
    }

    return dom;
}

function addElement(title, subtitle, body) {

    let innerDom = createDivWithClass([
        createDivWithClass(title, 'title'),
        createDivWithClass(subtitle, 'subtitle'),
        createDivWithClass(body, 'body')],
        'inner'
    );
    
    let dataId = Math.random().toString(36).substring(2);

    let liDom = document.createElement('li');
    liDom.className = 'content-list-item';
    liDom.appendChild(innerDom);
    liDom.setAttribute('data-id', dataId);
    liDom.onclick = function() {
        ipcRenderer.send('new-window', {
            dataId: dataId,
            title: title,
            subtitle: subtitle,
            body: body
        });
    }

    contentList.appendChild(liDom);

    return dataId;
}

function removeElement(dataId) {
    for (let i = 0; i < contentList.children.length; ++i) {
        if (contentList.children[i].getAttribute('data-id') == dataId) {
            contentList.removeChild(contentList.children[i]);
            break;
        }
    }
}

function onReady() {
    contentList = document.getElementById('content-list');
}

window.onload = onReady;

function foo() {
    return addElement(
        '홍길동',
        '이번 과제 공지',
        '안녕하세요, 홍길동 교수입니다. 이번 프로젝트 과제를 공지합니다.'
    );
}