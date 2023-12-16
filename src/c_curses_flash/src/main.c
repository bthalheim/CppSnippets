
#include <ncurses.h>


int main() {

    // Initialize the screen
    initscr(); 

    // Print "hello, world" ad the center of the screen
    int row,col; 
    getmaxyx(stdscr, row, col);
    mvprintw(row/2, (col - 13) / 2, "Hello, world");


    // Refresh the screen
    refresh(); 

    // Wait for a key press before exiting
    getch(); 


    // End Curses mode 
    endwin(); 

    return 0;

}





