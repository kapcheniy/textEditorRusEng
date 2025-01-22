; Горячая клавиша: Ctrl+T
^t::
    
    ; Сохраняем текущее содержимое буфера обмена
    savedClipboard := ClipboardAll

    ; Копируем выделенный текст
    Send, ^c
    ClipWait, 1  ; Ждем, пока текст появится в буфере обмена

    ; Сохраняем текст из буфера обмена в переменную
    text := clipboard

    ; Запускаем C-программу и передаем текст
    ; Убедитесь, что путь к программе указан правильно
    RunWait, %ComSpec% /c C:\Users\Klloo\source\repos\translateScript\x64\Debug\translateScript.exe "%text%" > output.txt,, Hide

    ; Читаем результат из файла output.txt
    FileRead, result, output.txt

    ; Удаляем временный файл
    FileDelete, output.txt

    ; Удаляем лишние символы (например, \n и \r)
    result := StrReplace(result, "`r", "")  ; Удаляем возврат каретки
    result := StrReplace(result, "`n", "")  ; Удаляем символ новой строки

    ; Копируем результат в буфер обмена
    clipboard := result

    ; Вставляем результат
    Send, ^v

    ; Восстанавливаем исходное содержимое буфера обмена
    clipboard := savedClipboard
return