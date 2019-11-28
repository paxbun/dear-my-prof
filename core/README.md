# 메인 로직 구현

`core`는 메인 로직을 구현합니다.

## 소스 구조

모든 헤더 파일들의 확장자는 `.hpp`, 구현 파일들의 확장자는 `.cpp`입니다.

* `Private`: 내부적으로 사용하는 헤더 파일들입니다. 이 파일들은 외부로 노출되지
             않습니다.
* `Public`: 외부에 노출되는 헤더 파일들입니다.
* `Source`: 구현 파일들입니다.

하나의 파일에서 여러 개의 클래스(구조체)를 정의하거나 구현하면 안됩니다. 단, 클래스
내부에 클래스를 정의하는 경우(Nested class)는 있을 수 있습니다. 헤더 파일들이
순환 참조되는 경우엔 디자인이 잘못되었다고 의심하여야 합니다.

## 클래스 목록

* `User`
* `Receiver`
* `Sender`
* `Collection`
* `Template`
* `Item`

## 코드 스타일

일관성 있는 코드를 위해, 이 프로젝트에선 정해진 코드 스타일만을 사용합니다. 코드
스타일은 프로젝트의 루트에 있는 `.clang-format`에 정의되어있습니다. 로컬 저장소에
커밋하기 전, `clang-format`으로 소스에 서식을 적용하여야 합니다. Visual Studio에서
`Ctrl + K`, `Ctrl + D`를 눌러 현재 편집 중인 코드에 서식을 적용할 수 있습니다. 동일한
맥락에서, 프로젝트 전체의 C++ 코드에선 다음 명명 규약을 지켜야 합니다.

### 명명 규약

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

### `const` 붙이기

`const`를 일관적인 위치에서 사용하기 위해, `const` 는 타입의 **뒤에** 붙입니다.

* Good: `T const *`
* Good: `T * const`
* Good: `T const &`
* Bad: `const T &`
