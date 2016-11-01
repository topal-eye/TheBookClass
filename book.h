#ifndef BOOK_H
#define BOOK_H


class book
{
    private:
        std::string title, status, name;
        long due;
    public:
        bool reserve();
        bool unreserve();
        int borrow(std::string&);
        int returnBook();
        bool sameStatus(book&);
        book(std::string,std::string);

};
#endif // BOOK_H
