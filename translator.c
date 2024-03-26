#include <stdio.h>
#include <string.h>

// Function to convert a character to Morse code
const char *char_to_morse(char c)
{
    // Define Morse code for each alphabet and digit
    static const char *morseCode[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                                        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                                        "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
                                        "...--", "....-", ".....", "-....", "--...", "---..", "----."};

    if ((c >= 'a' && c <= 'z') || (c>='A' && c<="Z")) //Harsh made it for both cases.
    {
        return morseCode[c - 'a'];
    }
    else if (c >= '0' && c <= '9')
    {
        return morseCode[c - '0' + 26];
    }
    else
    {
        return ""; // Return empty string for other characters
    }
}

// Function to convert a word to Morse code
// Use the delimiter / for any spaces between words
void translate_to_morse(const char *text, char *morseOutput, int morseOutputSize)
{
    // Loop through the text to convert each
    // charactor to morse code.
    // char_to_morse function is provided above but may not
    // handle all cases.
}