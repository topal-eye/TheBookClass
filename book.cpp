#include<iostream>
#include<ctime>
#include<string>
#include "book.h"

using namespace std;

string name;
long due;
book::book(string atitle, string astatus): title(atitle), status(astatus){
    name="";
    if (status!="loaned")
        due=-1;
}

bool book::reserve(){
    if (status=="shelved"){
        status= "reserved-available";
    }
    if(status=="loaned"){
        return false;
    }
     return true;
}

bool book::unreserve(){
    if (status!="reserved-available")return false;
    return true;
}

int book::borrow(string& bname){
    if(status=="loaned"|| status=="reserved-unavailable")
        return -1;
    if (status=="reserved")
        due=time(0)+72000;

    due= time(0)+1209600;

    if(status=="shelved")
            status="loaned";

    if (status=="reserved-available")
        status="reserved-unavailable";

    name=bname;

    return 0;
}

int book::returnBook(){
    if(status=="shelved"||status=="reserved-available")
        return -1;
    long rtime=time(0);

    long fine= (rtime-due)/60;

    if(rtime>due){
        if(status=="reserved-unavailable"){
            fine*=50;
            status="reserved-available";
        }
        else{
            fine*=100;
            status="shelved";
        }
    }
   return 0;
}

bool book::sameStatus(book&anotherBook){
    if(status==anotherBook.status)
        return true;
    return false;
}

