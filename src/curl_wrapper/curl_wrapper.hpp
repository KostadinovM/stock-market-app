#include <curl/curl.h>
#include <string>

size_t curl_handler(char *content, size_t size, size_t nmemb, void *userdata)
{
    static_cast<std::string *>(userdata)->append(content, size * nmemb);
    return size * nmemb;
}

class CurlWrapper
{
public:
    CurlWrapper()
    {
        curl = curl_easy_init();
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, nullptr);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    }
    ~CurlWrapper()
    {
        curl_easy_cleanup(curl);
    }

private:
    CURL *curl;
    std::string response;
};
