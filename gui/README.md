# GUI 구현

`gui`는 `core`와 `bind`에서 구현된 로직을 GUI로 노출합니다.

## 소스 구조

* `Asset`: 프로그램에 사용되는 이미지 파일들이 있습니다.
* `Resource`: `Asset`에 들어갈 파일들을 만들기 위해 사용되는 파일들이 있습니다.
* `Script`: Electron의 Main 스레드에서 동작하는 JavaScript 파일들이 있습니다.
* `Style`: CSS 파일들이 있습니다.
* `View`: HTML 파일과 Electron의 Renderer 스레드에서 동작하는 JavaScript 파일들이
          있습니다. 하나의 HTML 파일은 하나의 JavaScript 파일에 대응됩니다.

## 뷰 구조

* `login.html`: 아이디와 비밀번호를 입력하는 폼이 있습니다. 로그인 이후 `root.html`
                을 엽니다.
* `root.html`: 메일 목록과 메인 메뉴가 있는 뷰입니다. 메인 메뉴에서 `newemail.html`,
               `template.html`을 열 수 있으며, 메일 목록의 아이템을 클릭하면
               `detail.html`이 열립니다.
* `detail.html`: 각 메일을 보여주는 뷰입니다.
* `newemail.html`: 새 메일을 입력하는 뷰입니다.
* `template.html`: 템플릿 목록을 보여주는 뷰입니다. 템플릿 목록의 아이템을 클릭하면
                   `detailtemplate.html`이 열립니다.
* `detailtemplate.html`: 각 템플릿을 보여주는 뷰입니다.
* `newtemplate.html`: 새 템플릿을 입력하는 뷰입니다.