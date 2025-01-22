; Горячая клавиша: Ctrl+T
^t::
    
    savedClipboard := ClipboardAll

    Send, ^c
    ClipWait, 1  ; Ждем, пока текст появится в буфере обмена

    text := clipboard

    ; Вместо translateScript.exe вставьте путь к исполняемому файлу
    RunWait, %ComSpec% /c translateScript.exe "%text%" > output.txt,, Hide

    FileRead, result, output.txt

    FileDelete, output.txt

    result := StrReplace(result, "`r", "")  ; Удаляем возврат каретки
    result := StrReplace(result, "`n", "")  ; Удаляем символ новой строки

    clipboard := result

    Send, ^v

    clipboard := savedClipboard
return
