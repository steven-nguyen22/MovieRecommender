#ifndef __MULTIMEDIA_HPP__
#define __MULTIMEDIA_HPP__

#include <string>
#include <vector>

using namespace std;

class Multimedia {
  protected:
        string title_of_media; //generic media
        vector<string> genres_list;

  public:
        Multimedia() : title_of_media(""), genres_list() {}; //default
        Multimedia(string title_of_media, vector<string>genres_list) : title_of_media(title_of_media), genres_list(genres_list){};
        virtual string getMultimediaTitle() = 0;

        virtual void setMultimediaTitle(string title_tobe_added) = 0;

        virtual int getMultimediaType() = 0;
    };

#endif
~                

