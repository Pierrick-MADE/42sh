#include <openssl/md5.h>
#include <stdio.h>

#include "../data_structures/hash_map.h"
#include "../input_output/get_next_line.h"
#include "../data_structures/array_list.h"
#include "md5.h"

#define BUF_SIZE 1024

void insert_hash(const char *file_name)
{
    char hash[MD5_DIGEST_LENGTH];

    FILE *file = fopen(file_name, "r");
    if (fille == NULL)
        return;

    MD5_CTX md_context;
    int bytes;
    char data[BUF_SIZE];

    MD5_Init(&md_context);

    while ((bytes = fread(data, 1, BUF_SIZE, file)) != 0)
        MD5_Update(&md_context, data, bytes);

    MD5_Final(c, &md_context);

    fclose (inFile);

    struct array_list *ast_list = array_list_init();
    hash_insert(g_env.cached_ast, hash, ast_list, CACHE)

    return 0;
}