#include <stdio.h>
#include <string.h>
#include "blink.h"
#include "delay.h"
// Function to convert a character to Morse code
const char *char_to_morse(char c)
{
    // Define Morse code for each alphabet and digit
    static const char *morseCode[36] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                                        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                                        "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---",
                                        "...--", "....-", ".....", "-....", "--...", "---..", "----."};

    if ((c >= 'a' && c <= 'z'))
    {
        return morseCode[c - 'a'];
    }
    else if ((c >= 'A' && c <= 'Z'))
    {
        return morseCode[c - 'A'];
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

    // size of text array
    int len = strlen(text);
    // intialize to an empty array
    morseOutput[0] = '\0'; 
    for (int i = 0; i < len; i++)
    {
        // make sure its not binary and ASCII
        if (text[i] >= 32 && text[i] <= 126) 
        {
            //for space between words
            if (text[i] == ' ') 
            {
                strcat(morseOutput, "/ ");
            }

            //regular conversion between letters
            else if (i!=len-1)
            {
                const char *morseChar = char_to_morse(text[i]);
                strcat(morseOutput, morseChar);
                strcat(morseOutput, " ");
            }
            else
            {
                const char *morseChar = char_to_morse(text[i]);
                strcat(morseOutput, morseChar);
                
            }
        }

        //return empty string if its not ASCII
        else
        {
            strcat(morseOutput, "");
        }
    }
    // Loop through the text to convert each
    // charactor to morse code.
    // char_to_morse function is provided above but may not
    // handle all cases.
}

void morse_blink_led(const char *morseCode)
{
    // Blink LED based on the timing needed
    // 1 Unit = 1 Second
    int len = strlen(morseCode);
    printf("%s\n", morseCode);
    INIT_LED();
    for (int i = 0; i < len; i++)
    {
        // dots will be 1 unit
        if (morseCode[i] == '.') 
        {
            LED_HIGH();
            DELAY(1);
            printf("dot\n");
            LED_LOW();

            //if it is the same letter, add the space
            if(morseCode[i+1] != ' ' && morseCode[i+1]!='\0')
            {
                DELAY(1);
                printf("space\n");
            }
        }

        // dashes will be 3 units
        else if (morseCode[i] == '-') 
        {
            LED_HIGH();
            DELAY(3);
            printf("dash\n");
            LED_LOW();

            //if it is the right letter, add the space
            if(morseCode[i+1] != ' ' && morseCode[i+1]!='\0')
            {
                DELAY(1);
                printf("space\n");
            }
        }

        // space between letters will be 3 units
        else if (morseCode[i] == ' ') 
        {
            DELAY(3);
            printf("lspace\n");
        }

        // space between words will be 7 units (3 unit for space x2 + 1 unit)
        else if (morseCode[i] == '/') 
        {
            DELAY(1);
            printf("wspace\n");
        }
        else
        {
            LED_LOW();
        }

        
    }

    // Use LED_HIGH() to turn on led
    // Use LED_LOW() to turn off led
    // LED_HIGH();
    // LED_LOW();

    // int duration = 1 or w/e value you need
    // Use DELAY(duration) to sleep the appropriate units
    // Rmemeber 1 unit = 1 second for this assignment
}
