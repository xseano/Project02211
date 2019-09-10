#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <iomanip>
#include <set>

// global maxima for array length
#define MAX 100

// Main class for handling creation and interfacing of video data
class Video
{
    public:
        // constructor/destructor
        Video(std::string t, std::string u, std::string c, double l, int r);
        ~Video();

        // data output
        void print();

        // public methods for obtaining video data
        int getRating();
        double getLength();
        std::string getTitle();
        std::string getUrl();
        std::string getComment();
        std::string asterisk();
    private:
        std::string title;
        std::string url;
        std::string comment;
        double length;
        int rating;
};

// Class for handling sorting, pointer reassignment and display
class Sort
{
    public:
        // constructor/destructor
        Sort(std::string t);
        ~Sort();

        // public methods for sorting and displaying data in videos list
        void sort(Video *videos[], int length);
        void display(Video *videos[], int length);
        void destroy(Video *video);
    private:
        std::string type;
        void reassign(Video *vp1, Video *vp2);
};

#endif
