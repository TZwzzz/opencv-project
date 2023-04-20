#include "putUrlPic.h"

FILE *json_file;
static int write_data(void *ptr, size_t size, size_t nmemb, void *userdata)
{
    json_data_t *data = (json_data_t*) userdata;
    const char *key = "MD5:";
    size_t key_len = strlen(key);
    // 找到 json 数据中的 MD5 字段
    char *pos = strstr((char *)ptr, key); 
    if(pos != NULL) { 
        pos += key_len + 1;
        char *end_pos = strchr(pos, '<');
        if(end_pos != NULL) {
            data->md5 = strndup(pos, end_pos - pos);
        }
    }

    // 返回实际读取的字节数
    return size * nmemb;
}

int putUrlPic(const char *picName)
{
    FILE *image_file = fopen(picName, "rb");
    if(!image_file) {
        printf("Failed to open image file %s\n", picName);
        return 1;
    }

    CURL *curl_handle = curl_easy_init();
    if(!curl_handle) {
        printf("Failed to initialze curl\n");
        fclose(image_file);
        return 1;
    }

    // 打开 json 文件用于写入
    json_file = fopen("response.json", "a");
    if(!json_file) {
        printf("Failed to create json file\n");
        return 1;
    }

    json_data_t json_data;

    struct curl_httppost *formpost = NULL;
    struct curl_httppost *lastptr = NULL;
    struct curl_slist *headerlist = NULL;
    static const char buf[] = "Expect:";

    curl_global_init(CURL_GLOBAL_ALL);

    curl_formadd(&formpost, &lastptr,
                 CURLFORM_COPYNAME, "uploadfile",
                 CURLFORM_FILE, picName,
                 CURLFORM_CONTENTTYPE, "image/jpeg",
                 CURLFORM_END);

    headerlist = curl_slist_append(headerlist, buf);

    curl_easy_setopt(curl_handle, CURLOPT_URL, "http://192.168.156.222:4869/upload");
    curl_easy_setopt(curl_handle, CURLOPT_HTTPHEADER, headerlist);
    curl_easy_setopt(curl_handle, CURLOPT_HTTPPOST, formpost);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, &json_data);

    CURLcode res = curl_easy_perform(curl_handle);
    if(res != CURLE_OK) {
        printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    } else {
        printf("Upload succeeded\n");
        fprintf(json_file, "%s\n", json_data.md5);
        printf("MD5: %s\n", json_data.md5);
        system("rm *.jpg");
    }

    curl_formfree(formpost);
    curl_slist_free_all(headerlist);
    curl_easy_cleanup(curl_handle);
    fclose(image_file);
    fclose(json_file);

    curl_global_cleanup();

    return 0;
}