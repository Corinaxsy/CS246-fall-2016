// compile with -E flag to see how preprocessor worked
#define MAX 10
#define BBOS 1
#define OS BBOS // or IOS

int main() {
    int x[MAX];
   #if OS == BBOS
    long long int publicKey; // suppressed if OS != BBOS
   #elif OS == IOS
    short int publicKey;
   #endif
}
