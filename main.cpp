#include "video.h"

int main()
{
    const int MAX = 100;
    int counter = 0;
    Video* videos[MAX];

    std::string sort;
    std::string title;
    std::string url;
    std::string comment;
    double length;
    int rating;
    std::set<std::string> sort_types = {"rating", "length", "title"};

    std::cin >> sort; // read in sort type

    if(sort_types.find(sort) == sort_types.end())
    {
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
            Video *vid = new Video(title, url, comment, length, rating);
            videos[counter] = vid;
            counter++;
        }

    } while(!std::cin.eof());

    for (int i = 0; i < counter; i++)
    {
        Video* video = videos[i];
        video->print();
    }

    return 0;
}
