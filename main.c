#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "graph.h"
#include "hash.h"
#include "memory_report.h"

int main() {
    printf("--- LogiGraph: Lojistik Agi ve Paket Takip Sistemi ---\n\n");

    Graph* logiGraph = create_graph(5);
    add_city(logiGraph, 0, "Kirklareli");
    add_city(logiGraph, 1, "Edirne");
    add_city(logiGraph, 2, "Bursa");
    add_city(logiGraph, 3, "Istanbul");
    add_city(logiGraph, 4, "Ankara");

    add_edge(logiGraph, 0, 1, 60);
    add_edge(logiGraph, 0, 3, 210);
    add_edge(logiGraph, 3, 2, 150);
    add_edge(logiGraph, 3, 4, 450);
    add_edge(logiGraph, 2, 4, 380);

    HashEntry* hashTable[TABLE_SIZE];
    init_hash_table(hashTable);

    Package* p1 = (Package*)malloc(sizeof(Package));
    strcpy(p1->package_id, "TR1001"); strcpy(p1->content, "Elektronik"); strcpy(p1->current_city, "Istanbul"); strcpy(p1->destination, "Ankara"); p1->status = 0;

    Package* p2 = (Package*)malloc(sizeof(Package));
    strcpy(p2->package_id, "TR1002"); strcpy(p2->content, "Tekstil"); strcpy(p2->current_city, "Bursa"); strcpy(p2->destination, "Edirne"); p2->status = 0;

    Package* p3 = (Package*)malloc(sizeof(Package));
    strcpy(p3->package_id, "TR1003"); strcpy(p3->content, "Yedek Parca"); strcpy(p3->current_city, "Kirklareli"); strcpy(p3->destination, "Bursa"); p3->status = 0;

    Package* p4 = (Package*)malloc(sizeof(Package));
    strcpy(p4->package_id, "TR1004"); strcpy(p4->content, "Kitap"); strcpy(p4->current_city, "Ankara"); strcpy(p4->destination, "Istanbul"); p4->status = 1;

    Package* p5 = (Package*)malloc(sizeof(Package));
    strcpy(p5->package_id, "TR1005"); strcpy(p5->content, "Gida"); strcpy(p5->current_city, "Edirne"); strcpy(p5->destination, "Kirklareli"); p5->status = 0;

    insert_package(hashTable, p1);
    insert_package(hashTable, p2);
    insert_package(hashTable, p3);
    insert_package(hashTable, p4);
    insert_package(hashTable, p5);

    bfs_traversal(logiGraph, 0);

    print_memory_report(hashTable, logiGraph);

    printf("[Paket Sorgulama Testi]\n");
    Package* found = search_package(hashTable, "TR1003");
    if (found) {
        printf("Aranan Paket: TR1003 | Icerik: %s | Su anki Sehir: %s | Hedef: %s\n\n",
               found->content, found->current_city, found->destination);
    } else {
        printf("Aranan Paket: TR1003 bulunamadi.\n\n");
    }

    return 0;
}
