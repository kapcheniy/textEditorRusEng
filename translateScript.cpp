#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

typedef struct {
    char first;
    const char* second;
} TranslitPair;

const TranslitPair eng_to_rus_dict[] = {
    {'q', "й"}, {'w', "ц"}, {'e', "у"}, {'r', "к"}, {'t', "е"},
    {'y', "н"}, {'u', "г"}, {'i', "ш"}, {'o', "щ"}, {'p', "з"},
    {'a', "ф"}, {'s', "ы"}, {'d', "в"}, {'f', "а"}, {'g', "п"},
    {'h', "р"}, {'j', "о"}, {'k', "л"}, {'l', "д"}, {'z', "я"},
    {'x', "ч"}, {'c', "с"}, {'v', "м"}, {'b', "и"}, {'n', "т"},
    {'m', "ь"},
    {',', "б"}, {'.', "ю"}, {';', "ж"}, {'\'', "э"}, {'[', "х"}, {']', "ъ"},
    {'Q', "Й"}, {'W', "Ц"}, {'E', "У"}, {'R', "К"}, {'T', "Е"},
    {'Y', "Н"}, {'U', "Г"}, {'I', "Ш"}, {'O', "Щ"}, {'P', "З"},
    {'A', "Ф"}, {'S', "Ы"}, {'D', "В"}, {'F', "А"}, {'G', "П"},
    {'H', "Р"}, {'J', "О"}, {'K', "Л"}, {'L', "Д"}, {'Z', "Я"},
    {'X', "Ч"}, {'C', "С"}, {'V', "М"}, {'B', "И"}, {'N', "Т"},
    {'M', "Ь"}
};

const TranslitPair rus_to_eng_dict[] = {
    {'й', "q"}, {'ц', "w"}, {'у', "e"}, {'к', "r"}, {'е', "t"},
    {'н', "y"}, {'г', "u"}, {'ш', "i"}, {'щ', "o"}, {'з', "p"},
    {'ф', "a"}, {'ы', "s"}, {'в', "d"}, {'а', "f"}, {'п', "g"},
    {'р', "h"}, {'о', "j"}, {'л', "k"}, {'д', "l"}, {'я', "z"},
    {'ч', "x"}, {'с', "c"}, {'м', "v"}, {'и', "b"}, {'т', "n"},
    {'ь', "m"},
    {'б', ","}, {'ю', "."}, {'ж', ";"}, {'э', "\'"}, {'х', "["}, {'ъ', "]"},
    {'Й', "Q"}, {'Ц', "W"}, {'У', "E"}, {'К', "R"}, {'Е', "T"},
    {'Н', "Y"}, {'Г', "U"}, {'Ш', "I"}, {'Щ', "O"}, {'З', "P"},
    {'Ф', "A"}, {'Ы', "S"}, {'В', "D"}, {'А', "F"}, {'П', "G"},
    {'Р', "H"}, {'О', "J"}, {'Л', "K"}, {'Д', "L"}, {'Я', "Z"},
    {'Ч', "X"}, {'С', "C"}, {'М', "V"}, {'И', "B"}, {'Т', "N"},
    {'Ь', "M"}
};

bool is_english_char(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_russian_char(char c) {
    return (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я');
}

void transliterate(const char* input, char* output, const TranslitPair* dict, size_t dict_size) {
    int input_len = strlen(input);
    int output_pos = 0;

    for (int i = 0; i < input_len; i++) {
        char current_char = input[i];
        int matched = 0;

        for (size_t j = 0; j < dict_size; j++) {
            if (current_char == dict[j].first) {
                strncpy(output + output_pos, dict[j].second, strlen(dict[j].second));
                output_pos += strlen(dict[j].second);
                matched = 1;
                break;
            }
        }

        if (!matched) {
            output[output_pos++] = current_char;
        }
    }

    output[output_pos] = '\0';
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "");

    if (argc < 2) {
        return 1;
    }

    char input[256];
    char output[512];

    strncpy(input, argv[1], sizeof(input) - 1);
    input[sizeof(input) - 1] = '\0';

    const TranslitPair* dict;
    size_t dict_size;

    if (is_english_char(input[0])) {
        dict = eng_to_rus_dict;
        dict_size = sizeof(eng_to_rus_dict) / sizeof(TranslitPair);
    }
    else if (is_russian_char(input[0])) {
        dict = rus_to_eng_dict;
        dict_size = sizeof(rus_to_eng_dict) / sizeof(TranslitPair);
    }
    else {
        strncpy(output, input, sizeof(output));
        printf("%s\n", output);
        return 0;
    }

    transliterate(input, output, dict, dict_size);

    printf("%s", output);

    return 0;
}