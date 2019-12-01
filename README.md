# Dear My Professor

![Logo](./gui/Asset/Icon.png)

Dear My Professor는 교수님들께 이메일을 보내는데 어려움을 겪는 학생들을 위한
프로그램입니다.

## 개발 동기

DGIST 학생들은 면담 약속, 질문 등을 위하여 교수님들과 메일로 많은 소통을 하여야 합니다.
지금까지 이메일로 소통할 일이 없었던 신입생들은 이러한 상황을 매우 힘들어 합니다. 그럼에도
불구하고, 신입생들이 이메일 쓰기 실력을 기를 수 있는 기화는 많지 않습니다. 자신이 쓴
이메일에 자신감을 가지지 못한 DGIST 학생은 교수님들께 이메일을 보낼 때,
'이렇게 보내도 되나?' 라는 생각에 짧은 이메일에도 수십 분을 쏟습니다.
이러한 문제를 해결하기 위해, 학생들에게 양식에 빈 칸만 채워 이메일을 보낼 수 있는
프로그램을 제공하고자 합니다. 이를 통해 학생들이 이메일에 갖는 반감을 줄이고, 학생들의
이메일 작성 실력을 늘릴 수 있을 것입니다.

## 주요 기능

### 교수님들과 빠른 소통을 위한 메일 클라이언트

Dear My Professor는 이메일을 보내고 받을 수 있는 메일 클라이언트입니다. 사용자는 Dear
My Professor를 이용하여 교수님들과 이메일로 소통할 수 있습니다. 교수님들과 더 빠른
소통을 위해, Dear My Professor는 교수님들의 연락처를 성함이나 맡으신 수업으로 검색하는
기능을 지원합니다.

### 교수님들과 원활한 소통을 위한 템플릿 기반 자동 완성

Dear My Professor는 교수님들과 소통할 때 보내게 될 이메일들을 미리 템플릿 형태로
저장하고 있습니다. 템플릿은 구조와 매개변수로 이루어져 있는데, 매개변수들 중엔 '이름'이나
'학번', '오늘 날짜'처럼 Dear My Professor가 자동으로 채워주는 것도 있고, '사유'나
'질문하고 싶은 것'처럼 사용자가 채워야 하는 항목들도 있습니다. 이를 통해 사용자가
교수님들과 더 원활하게 소통할 수 있도록 돕습니다.

## 개발 준비하기

Dear My Professor의 개발 언어는 C++17이며, 다음 프로그램이 전부 필요합니다. Windows에서
CMake는 Visual Studio의 Extension을 활용하는 것이 편합니다.

* [CMake 3.13](https://cmake.org/download/)
* [Node.js 13](https://nodejs.org/)
* [Python 3](https://www.python.org/downloads/release)

Node.js를 설치한 후, 콘솔에서 다음 명령어를 입력해주세요. 리눅스에선 루트 권한이 필요할
수도 있습니다.

```
npm install -g node-gyp
```

이 저장소를 로컬로 복사합니다.

```
git clone https://github.com/paxbun/dear-my-prof
```

## 콘솔에서 빌드하기

빌드용 디렉토리를 만듭니다.

```
cd dear-my-prof
mkdir build
cd build
```

### 디버그용으로 빌드하기

```
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
```

디버그 빌드가 끝나면 소스 폴더에 링크가 완료된 네이티브 모듈이 복사됩니다. 이를 통해 소스
폴더에서 바로 디버그를 할 수 있습니다.

### 릴리즈용으로 빌드하기

```
cmake ..
cmake --build . --config Release
```

릴리즈 빌드가 끝나면 빌드용 디렉토리에서 `gui_out` 디렉토리 안에 `Dear My Professor-*`
라는 이름의 디렉토리가 생성됩니다. 이 디렉토리 안에 실행 파일이 있습니다.

## 소스 구조

소스는 [`core`](./core), [`bind`](./bind), [`gui`](./gui) 세 부분으로 나눠져
있습니다.

* `core`: 프로그램의 로직을 구현합니다.
* `bind`: `core`를 Node.js 네이티브 모듈로 랩핑합니다.
* `gui`: Electron을 사용하여 GUI를 구현합니다.

## 코드 스타일

일관성 있는 코드를 위해, 이 프로젝트에선 정해진 코드 스타일만을 사용합니다.

### C++

C++ 코드 스타일은 프로젝트의 루트에 있는 `.clang-format`에 정의되어있습니다. 로컬
저장소에 커밋하기 전, `clang-format`으로 소스에 서식을 적용하여야 합니다.
Visual Studio에서 `Ctrl + K`, `Ctrl + D`를 눌러 현재 편집 중인 코드에 서식을 적용할 수
있습니다. 동일한 맥락에서, 프로젝트 전체의 C++ 코드에선 다음 명명 규약을 지켜야 합니다.

#### 명명 규약

본 명명 규약에서 사용되는 명명 스타일은 크게 일곱 가지입니다.

* `PascalCase`: 단어의 첫 글자는 대문자이고, 나머지는 모두 소문자입니다.
* `_PascalCase`: PascalCase에 언더바가 추가되어있습니다.
* `camelCase`: PascalCase와 동일하지만, 식별자의 맨 첫 글자도 소문자입니다.
* `_camelCase`: camelCase에 언더바가 추가되어있습니다.
* `snake_case`: 모든 글자가 소문자이고, 단어 사이에 언더바를 넣습니다.
* `BIG_SNAKE_CASE`: snake_case와 동일하지만, 모든 글자가 대문자입니다.
* `__H_HEADER_GUARD__`: 헤더 가드에 사용됩니다. BIG_SNAKE_CASE와 동일하지만, 앞
                          뒤로 언더바를 두 개씩 더 넣습니다.

| Type | Style | Example |
| --- | --- | --- |
| `class`/`struct`/`union`/`enum` | `PascalCase` | `MyClass` |
| Nested Public `class`/`struct`/`union`/`enum` | `PascalCase` | `MyClass::InnerClass` |
| Nested Public Type Alias | `PascalCase` + `Type` | `MyClass::IntegerType` |
| Nested Protected/Private `class`/`struct`/`union`/`enum` | `_PascalCase` | `MyClass::_InClass` |
| Nested Protected/Private Type Alias | `_PascalCase` + `Type` | `MyClass::_InType` |
| Template Parameter | `PascalCase` + `T` | `template <typename DataT>` |
| Template Parameter Pack | `PascalCase` + `Ts` | `template <typename ... DataTs>` |
| Public Member Variable | `camelCase` | `MyClass::userName` |
| Protected/Private Member Variable | `_camelCase` | `MyClass::_password` |
| Getter/Setter | `camelCase` | `MyClass::password` |
| Public Member Function | `PascalCase` | `MyClass::Print` |
| Protected/Private Member Function | `_PascalCase` | `MyClass::_Change` |
| Namespace | `camelCase` | `myNamespace` |
| Global Function | `PascalCase` | `FooFunction` |
| Function Parameter | `snake_case` | `my_param` |
| Local Variable | `snake_case` | `my_temp` |
| Preprocessor Macro | `BIG_SNAKE_CASE` | `MY_MACRO` |
| Header Guard | `__H_FILE_NAME__` | See Below |

#### `const` 붙이기

`const`를 일관적인 위치에서 사용하기 위해, `const` 는 타입의 **뒤에** 붙입니다.

* Good: `T const *`
* Good: `T * const`
* Good: `T const &`
* Bad: `const T &`
