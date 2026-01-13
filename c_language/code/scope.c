// these definitions have FILE scope
enum color {RED, BLUE, GREEN, PINK};
struct vehicle {
    enum color color;
    int wheel;
    int door;
};

// this variable can be accessed anywhere in the same file
int global_variable = 10;

int main (int argc, char **argv) {
    // we can use `struct vehicle` here because it is inside the same file scope
    // that it was declared in
    struct vehicle car;

    {
        // `{}` that encapsulate statements are in a new BLOCK scope
        // this BLOCK scope exists inside of mains FUNCTION scope
        // inner scopes can "shadow" outer scope labels
        struct vehicle car; // this is a different label in memory
    } // when this block scope ends, the inner car is "destroyed"

} // at the end of the function, the "outer" car is destroyed

// at the end of the file, `enum color`, `struct vehicle` and `global_variable`
// leave scope and are destroyed
