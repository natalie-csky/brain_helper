/*
Note: Due to this program using <conio.h>, it will only properly work 
on machines running Windows (at least afaik).
Note 2: Also, ignore my print functions. I just wanted to implement a 
print() function similar to Python's :).

I made this program to teach myself what callbacks are and how to implement them.

According to https://developer.mozilla.org/en-US/docs/Glossary/Callback_function:
"A callback function is a function passed into another function as an argument,
which is then invoked inside the outer function to complete some kind of
routine or action."

In this program, do_action() takes in a function and then calls that function,
pretty much doing what the mozilla docs explained.

It's actually really simple, but for some reason I needed to implement it
myself to really understand it.
*/

#include <conio.h>
#include <iostream>


const char ESCAPE_KEY = 27;
const char WALK_KEY = 'w';
const char JUMP_KEY = 'j';


#pragma region print
void print(char* message)
{
    std::cout << message << std::endl;
}

void print(const char* message)
{
    std::cout << message << std::endl;
}

void print(int message)
{
    std::cout << message << std::endl;
}

void print(double message)
{
    std::cout << message << std::endl;
}
#pragma endregion


const void jump()
{
    print("You jump!");
}


const void walk()
{
    print("You walk.");
}


const void print_start()
{
    print("\
\nPress j or w to jump or walk, respectively.\n\
Press esc to exit the game.\n\
");
}


const void print_exit()
{
    print("\
\nGame successfully closed :)\n\
Hit any key to close the window...\
");
}


void do_action(const void(*action)())
{
    action();
}


int main() 
{
    print_start();

    char key_press = ' ';
    while (key_press != ESCAPE_KEY)
    {
        key_press = _getch();
        switch (key_press)
        {
            case WALK_KEY:
                do_action(walk);
                break;
            case JUMP_KEY:
                do_action(jump);
                break;
        }
    }

    print_exit();
    _getch();
    return 0;
}
