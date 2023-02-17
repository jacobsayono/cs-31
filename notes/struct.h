// class: book
// author (string), title (string)

// define blueprint for creating a book
// cookie-cutter

// blueprint DataType {}
struct Book {
    // define the "fields" that make up a book
    // "member variables"
    string mAuthor;
    string mTitle;
    Color mJacketColor;
    int mNumberOfPages;
};

enum Color {
    BLACK,
    RED,
    GREEN,
    YELLOW
};