#include "tree.h"
#include "pes.h"
#include <string.h>
#include <stdlib.h>

#define MODE_FILE 0100644

// forward declaration (important)
int object_write(ObjectType type, const void *data, size_t len, ObjectID *id_out);

int main() {
    Tree tree = {0};

    TreeEntry *te = &tree.entries[tree.count++];
    te->mode = MODE_FILE;
    strcpy(te->name, "hello.txt");

    memset(te->hash.hash, 1, HASH_SIZE);

    void *data;
    size_t len;
    ObjectID id;

    if (tree_serialize(&tree, &data, &len) != 0) return -1;
    if (object_write(OBJ_TREE, data, len, &id) != 0) return -1;

    free(data);
    return 0;
}
