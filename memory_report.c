#include "memory_report.h"

void print_memory_report(HashEntry* table[], Graph* g) {
    printf("\n========================================================\n");
    printf("              BELLEK IZLEME RAPORU (RAM DURUMU)         \n");
    printf("========================================================\n");

    printf("\n[HASH TABLOSU BELLEK HARITASI - Acik Adresleme]\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL) {
            printf("Index %02d | HashEntry: %p | Key: %-10s | Package Data: %p\n",
                   i, (void*)table[i], table[i]->key, (void*)table[i]->data);
        } else {
            printf("Index %02d | [BOS]\n", i);
        }
    }

    printf("\n[GRAF BELLEK HARITASI - Komsuluk Listesi]\n");
    for (int i = 0; i < g->num_vertices; i++) {
        printf("Sehir: %-15s (Adres: %p)\n", g->cities[i].city_name, (void*)&g->cities[i]);
        Edge* temp = g->cities[i].head;
        while (temp != NULL) {
            printf("    |-- Baglanti -> Hedef Index: %d, Kenar Adresi: %p\n",
                   temp->destination_vertex, (void*)temp);
            temp = temp->next;
        }
    }
    printf("========================================================\n\n");
}
