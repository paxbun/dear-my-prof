function Field_addTransition(field) {
    field.firstElementChild.classList.add('transition');
}
module.exports.Field_addTransition = Field_addTransition;

function Field_getValueDom(field) {
    return field.firstElementChild.lastElementChild;
}
module.exports.Field_getValueDom = Field_getValueDom;

function Field_getValue(field) {
    return Field_getValueDom(field).innerHTML;
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
        newElemWithClass('div', 'inner', [
            newElemWithClass('span', 'title', title),
            newElemWithClass('span', 'subtitle', subtitle),
            newElemWithClass('span', 'body', body)
        ])
    );
}
module.exports.ItemThree_new = ItemThree_new;

function setTitle(new_title) {
    document.title = new_title;
    document.getElementById('title-bar-body').innerText = new_title;
}
module.exports.setTitle = setTitle;