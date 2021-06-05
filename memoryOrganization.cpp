#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
typedef void (*StatusFunction)();

void one(long number);
void two(long number);
void pass() { cout << "You pass :)\n"; }
void fail() { cout << "You've failed :(\n"; }
const char * passMessage = ":)";
const char * failMessage = ":(";

/**********************************************
 * MAIN : The top of the callstack.
 **********************************************/
int main() {
   char text[8] = "*MAIN**";
   long number = 123456;
   void (*pointerFunction)() = fail;
   const char * message = failMessage;

   char x = 'X';

   char * pointer = new char[10];

   *pointer = 'X';

   cout << "Code Address: " << (const void*)&x << endl;
   cout << "Stack Address: " << &pointer << endl;
   cout << "Heap Pointer: " << (const void*)(pointer) << endl;

   // display the initial values of the local variables
   cout << "main() : " << (void *)main << endl;
   cout << "\ttext:             " << text              << endl;
   cout << "\tnumber:           " << number            << endl;
   cout << "\tmessage:          " << message           << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   // call the other functions
   one(number + 111111);     // 234567

   // display the new values of the local variables
   cout << "main() - after\n";
   cout << "\ttext:             " << text              << endl;
   cout << "\tnumber:           " << number            << endl;
   cout << "\tmessage:          " << message           << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   return 0;
}

/************************************************
 * CONVERT TO STRING
 * Convert the data from p into a human-readable string
 * by removing all the unprintable characters and replacing
 * them with a dot
 ***********************************************/
string displayCharArray(const char * p)
{
   string output;
   for (int i = 0; i < 8; i++)
       output += string(" ") + (p[i] >= ' ' && p[i] <= 'z' ? p[i] : '.');
   return output;
}

/**********************************************
 * ONE : The next item on the call stack
 **********************************************/
void one(long number)               // 234567
{
   char text[8] = "**ONE**";

   cout << "one() : " << (void *)one << endl;
   cout << "\tmessage: " << (void *)failMessage << endl;
   cout << "\tfail():  " << (void *)fail        << endl;

   two(number + 111111);    // 345678
}

/**********************************************
 * TWO : The bottom of the call stack
 **********************************************/
void two(long number)              // 345678
{
   // start your display of the stack from this point
   long bow = number + 111111;     // 456789
   char text[8] = "**TWO**";
   long * pLong = NULL;
   char * pChar = NULL;

   // header for our table. Use these setw() offsets in your table
   cout << '[' << setw(4) << 'i' << ']'
        << setw(15) << "address"
        << setw(20) << "hexadecimal"
        << setw(20) << "decimal"
        << setw(18) << "characters"
        << endl;
   cout << "----+"
        << "---------------+"
        << "-------------------+"
        << "-------------------+"
        << "-----------------+\n";

   char* pText = NULL;
   long* pNumber = NULL;
   void (*pointerFunction)() = NULL;
   const char* message = NULL;
   cout << "FAIL: " << (void*)fail << endl;
   for (long i = 150; i >= -4; i--) {  // You may need to change 24 to another number
      ////////////////////////////////////////////////
      // Insert code here to display the callstack
      long * pTemp = (&bow) + i;
      pLong = pTemp;
      pChar = (char*)(pTemp);

      if (displayCharArray(pChar) == displayCharArray("*MAIN**")) {
         cout << "Found pText\n";
         pText = pChar;
      }
      else if (*pLong == 123456) {
         cout << "Found number\n";
         pNumber = pLong;
      }
      else if (*((StatusFunction)pTemp) == (void*)fail) {
         cout << "Found pointerFunction\n";
         pointerFunction = (StatusFunction)pTemp;
      }
      else if (displayCharArray(pChar) == displayCharArray(":(")) {
         cout << "Found message\n";
         message = pChar;
      }

      cout << '[' << setw(4) << i << ']'
        << setw(15) << pTemp
        << setw(20) << hex << *pLong
        << setw(20) << dec << *pLong
        << setw(18) << displayCharArray(pChar)
      //   << setw(18) << *pChar
        << endl;
      //
      ////////////////////////////////////////////////
   }

   ////////////////////////////////////////////////
   // Insert code here to change the variables in main()

   // change text in main() to "*main**" index 53
   
   // change number in main() to 654321 index 60

   // change pointerFunction in main() to point to pass

   // change message in main() to point to passMessage

   //
   ////////////////////////////////////////////////
}