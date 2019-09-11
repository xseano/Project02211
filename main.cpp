#include "video.h"

int main()
{
    // counter used to keep track of videos added
    size_t counter = 0;

    // Dynamic array of Video pointers
    Video** videos = (Video**) malloc(MAX * sizeof(Video*));

    // valid sorting types
    std::set<std::string> SORT_TYPES =
    {
        "rating",
        "length",
        "title"
    };

    // variables for storing video data
    std::string sort;
    std::string title;
    std::string url;
    std::string comment;
    double length;
    int rating;

    // read in desired sort type
    std::cin >> sort;

    if(SORT_TYPES.find(sort) == SORT_TYPES.end())
    {
        // desired sort type does not persist in the set of types
        std::cerr << sort << " is not a legal sorting method, giving up." << std::endl;
        return 1;
    }

    do
    {
        std::cin.ignore();

        // read in video title
        std::getline(std::cin, title);
        // read in video url
        std::getline(std::cin, url);
        // read in video comment
        std::getline(std::cin, comment);

        // read in video length (in hrs)
        std::cin >> length;
        // read in video rating
        std::cin >> rating;

        if(counter > MAX)
        {
            // loop until a total of 100 videos have been provided by the user
            std::cerr << "Too many videos, giving up." << std::endl;
            return 1;
        }
        else if (std::cin.eof())
        {
            // prevent double input bug on eof
            break;
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

    // handler instantiated with validated sort type
    VideoHandler *vh = new VideoHandler(sort);
    // rearrange the array
    vh->sort(videos, counter);
    // display the ordered video data
    vh->display(videos, counter);

    return 0;
}
