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