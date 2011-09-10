#include <iostream>
#include <limits>

using namespace std;


// A little known fact: during the cin below, the newline

// is still in the cin buffer.
//
// If we do a cin now, we will retrieve the newline, which screws
// up our trying to do a "Hit any key to continue."
//
// So, use cin.ignore() to grab and discard everything in the
// cin buffer.  The line below throws away everything in the cin
// buffer up to the max buffer size or up to a newline,
// whichever comes first.
//
// We also need to use cin.clear() because the cin stream will be in a
// FALSE state, since a newline was reached without any data.
//


int main()
{
       string cmd;

       while (1) {
               cout << "Enter command (q to quit) ==>" << flush;
               if (cin >> noskipws >> cmd) {
                       if (cmd == "q") {
                               cin.clear();

                               cin.ignore(numeric_limits<streamsize>::max(), '\n');
                               cout << "stop" << endl ;

                               break;
                       }
                       cout << "You entered: " << cmd << endl ;
               }
               cin.clear();

               cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }
       while (1) {

               cout << "Enter return to continue ==>" << flush;
               if (cin >> noskipws >> cmd) {
                       cout << "You entered: " << cmd << endl ;
               } else {
                       cout << "Done!" << endl ;
                       break;
               }
               cin.clear();

               cin.ignore(numeric_limits<streamsize>::max(), '\n');
       }
       return 0;
}

