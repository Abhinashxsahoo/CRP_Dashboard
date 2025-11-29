#include "modules.h"

void checkInventoryHealth(FILE *f) {
    FILE *data = fopen("inventory.csv", "r");
    char product[50];
    int stock;

    fprintf(f, "<div class='card'><h2>📦 Inventory Health</h2><table>");
    fprintf(f, "<tr><th>Item</th><th>Stock</th><th>Status</th></tr>");

    while(fscanf(data, "%[^,],%d\n", product, &stock) != EOF) {
        fprintf(f, "<tr><td>%s</td><td>%d</td>", product, stock);
        
        if(stock < 10) {
            fprintf(f, "<td class='alert'>LOW STOCK</td>");
        } else {
            fprintf(f, "<td class='safe'>Healthy</td>");
        }
        fprintf(f, "</tr>");
    }
    
    fprintf(f, "</table></div>");
    fclose(data);
}