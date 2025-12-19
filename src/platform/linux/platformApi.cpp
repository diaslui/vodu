#include "../platformApi.h"
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <string>

namespace platformApi{

std::string getHostname(){

    char hostname[HOST_NAME_MAX];

    if (gethostname(hostname, HOST_NAME_MAX) == 0) {
        return std::string(hostname);
    } else {
        return std::string();
    }
}

std::string getUsername(){

    char username[LOGIN_NAME_MAX];

    if (getlogin_r(username, LOGIN_NAME_MAX) == 0){
        return std::string(username);
    }else{
        return std::string();
    }
}
}

std::string getprogramid(){
    return std::to_string(getpid());
}