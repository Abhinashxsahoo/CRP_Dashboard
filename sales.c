#include "modules.h"

void generateSalesGraph(FILE *f) {
    FILE *data = fopen("sales.csv", "r");
    char product[50];
    int price, units;
    
    fprintf(f, "<div class='card'><h2>📈 Revenue Analytics</h2>");
    fprintf(f, "<svg width='100%%' height='150'>");
    
    int x = 0;
    while(fscanf(data, "%[^,],%d,%d\n", product, &price, &units) != EOF) {
        int revenue = price * units;
        int height = revenue / 500; // Scaling factor
        if (height > 100) height = 100;
        
        fprintf(f, "<rect x='%d' y='%d' width='40' height='%d' fill='#00cf8d' rx='4' />", x, 120-height, height);
        fprintf(f, "<text x='%d' y='140' fill='white' font-size='10'>%s</text>", x, product);
        x += 60;
    }
    
    fprintf(f, "</svg></div>");
    fclose(data);
}