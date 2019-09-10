#include "video.h"

int main()
{
    const int MAX = 100; // max constant for array length
    int counter = 0; // counter used to keep track of videos added
    Video* videos[MAX]; // Video* array of MAX length

    std::set<std::string> SORT_TYPES = { "rating", "length", "title" };

    // variables for storing video data
    std::string sort;
    std::string title;
    std::string url;
    std::string comment;
    double length;
    int rating;

    std::cin >> sort; // read in desired sort type

    if(SORT_TYPES.find(sort) == SORT_TYPES.end())
    {
        // desired sort type does not persist in the set of types
        std::cerr << sort << " is not a legal sorting method, giving up." << std::endl;
        return 1;
    }

    do
    {
        std::cin.ignore();

        std::getline(std::cin, title); // read in video title
        std::getline(std::cin, url); // read in video url
        std::getline(std::cin, comment); // read in video comment

        std::cin.ignore();
        std::cin >> length; // read in video length (in hrs)
        std::cin >> rating; // read in video rating

        if(counter >= MAX)
        {
            // loop until a total of 100 videos have been provided by the user
            std::cerr << "Too many videos, giving up." << std::endl;
            return 1;
        }
        else
        {
            // create new video instance
            Video *vid = new Video(title, url, comment, length, rating);
            // store new video instance in array by position {counter}
            videos[counter] = vid;
            // increment counter with one element appended
            counter++;
        }

    } while(!std::cin.eof());

    Sort *sorter = new Sort(sort);
    sorter->rating(videos, counter);
    sorter->display(videos, counter);

    return 0;
}
