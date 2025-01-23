# Транслитератор текста (C++)

Этот проект представляет собой программу на языке C++, которая выполняет транслитерацию текста между английской и русской раскладками клавиатуры. Программа автоматически определяет направление транслитерации (английский → русский или русский → английский) на основе первого символа введённого текста.

This project is a C++ program that transliterates text between English and Russian keyboard layouts. Russian Russian Transliteration The program automatically determines the transliteration direction (English → Russian or Russian → English) based on the first character of the entered text.
## Возможности

### Транслитерация с английского на русский:

Пример:
```
qwerty → йцукен.
```

### Транслитерация с русского на английский:

Пример:
```
йцукен → qwerty.
```

### Поддержка заглавных букв:

Пример:
```
QwErTy → ЙцУкЕн.
```

### Поддержка специальных символов:

Пример:
```
,.;'[] → бюжэхъ.
```

## Как использовать

### Скомпилируйте программу:
1. Убедитесь, что у вас установлен компилятор C++ (например, g++).
2. Перейдите в папку с проектом и выполните команду:

```bash
g++ translateScript.cpp -o translateScript
```

### Запустите программу:
В командной строке выполните:

```bash
./translateScript "текст для транслитерации"
```

Пример:

```bash
./translateScript "qwerty"
```

Вывод:

```
йцукен
```

### Использование в скриптах:
Программа может быть интегрирована в скрипты (например, AutoHotkey) для автоматической транслитерации выделенного текста.
