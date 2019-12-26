function documentPreventInput(event) {
    event.preventDefault();
}

function setLoading() {
    document.addEventListener('keydown', documentPreventInput);
    document.getElementById('loading').classList.add('loading');
}
module.exports.setLoading = setLoading;

function unsetLoading() {
    document.removeEventListener('keydown', documentPreventInput);
    document.getElementById('loading').classList.remove('loading');
}
module.exports.unsetLoading = unsetLoading;

function Field_addTransition(field) {
    field.firstElementChild.classList.add('transition');
}
module.exports.Field_addTransition = Field_addTransition;

function Field_getValueDom(field) {
    return field.firstElementChild.lastElementChild;
}
module.exports.Field_getValueDom = Field_getValueDom;

function Field_getValue(field) {
    return Field_getValueDom(field).innerText;
}
module.exports.Field_getValue = Field_getValue;

function Field_preventMultiline(field) {
    Field_getValueDom(field).addEventListener('keydown',
        (event) => {
            if (event.keyCode === 13) {
                event.preventDefault();
            }
        }
    );
}
module.exports.Field_preventMultiline = Field_preventMultiline;

function Field_preventInput(field) {
    Field_getValueDom(field).addEventListener('keydown',
        (event) => {
            event.preventDefault();
        }
    );
}
module.exports.Field_preventInput = Field_preventInput;

function Field_invokeWithEnter(field, func) {
    Field_getValueDom(field).addEventListener('keydown',
        (event) => {
            if (event.keyCode === 13) {
                func();
                event.preventDefault();
            }
        }
    );
}
module.exports.Field_invokeWithEnter = Field_invokeWithEnter;

function Field_setInvalid(field) {
    field.classList.add('value-error');
    Field_getValueDom(field).addEventListener('input',
        (event) => {
            field.classList.remove('value-error');
        }
    );
}
module.exports.Field_setInvalid = Field_setInvalid;

function newElemWithClass(tagName, className, data) {
    let dom = document.createElement(tagName);
    dom.className = className;

    if (typeof(data) === 'string') {
        let domText = document.createTextNode(data);
        dom.appendChild(domText);
    } else {
        for (let i in data) dom.appendChild(data[i]);
    }

    return dom;
}
module.exports.newElemWithClass = newElemWithClass;

function ItemThree_new(title, subtitle, body) {
    return newElemWithClass('li', 'item-three',
        [newElemWithClass('div', 'inner', [
            newElemWithClass('span', 'title', title),
            newElemWithClass('span', 'subtitle', subtitle),
            newElemWithClass('span', 'body', body)
        ])]
    );
}
module.exports.ItemThree_new = ItemThree_new;

function ItemTwo_new(title, body) {
    return newElemWithClass('li', 'item-three item-two',
        [newElemWithClass('div', 'inner', [
            newElemWithClass('span', 'title', title),
            newElemWithClass('span', 'subtitle', body)
        ])]
    );
}
module.exports.ItemTwo_new = ItemTwo_new;

function ItemTwoEditable_new(title) {
    let body = newElemWithClass('span', 'subtitle');
    body.setAttribute('contenteditable', 'true');
    return newElemWithClass('li', 'item-three item-two',
        [newElemWithClass('div', 'inner', [
            newElemWithClass('span', 'title', title),
            body
        ])]
    );
}
module.exports.ItemTwoEditable_new = ItemTwoEditable_new;

function ItemTwoEditable_getValueDom(elem) {
    return elem.lastElementChild.lastElementChild;
}
module.exports.ItemTwoEditable_getValueDom = ItemTwoEditable_getValueDom;

function ItemTwoEditable_getValue(elem) {
    return ItemTwoEditable_getValueDom(elem).innerText;
}
module.exports.ItemTwoEditable_getValue = ItemTwoEditable_getValue;

function setTitle(new_title) {
    document.title = new_title;
    document.getElementById('title-bar-body').innerText = new_title;
}
module.exports.setTitle = setTitle;

function clearChild(elem) {
    while (elem.firstChild) {
        elem.removeChild(elem.firstChild);
    }
}
module.exports.clearChild = clearChild;