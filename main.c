#include <stdio.h>
#include "modules.h" // Links the other files

int main() {
    FILE *f = fopen("index.html", "w");
    if (f == NULL) return 1;

    // 1. Write HTML Header & CSS
    fprintf(f, "<!DOCTYPE html><html><head><title>CRP Dashboard</title>");
    fprintf(f, "<style>");
    fprintf(f, "body { font-family: sans-serif; background: #121212; color: white; margin: 0; padding: 20px; }");
    fprintf(f, ".grid { display: grid; grid-template-columns: repeat(auto-fit, minmax(300px, 1fr)); gap: 20px; }");
    fprintf(f, ".card { background: #1e1e1e; padding: 20px; border-radius: 12px; border: 1px solid #333; }");
    fprintf(f, "h2 { border-bottom: 2px solid #00cf8d; padding-bottom: 10px; margin-top: 0; }");
    fprintf(f, ".alert { color: #ff4d4d; font-weight: bold; }");
    fprintf(f, ".safe { color: #00cf8d; }");
    fprintf(f, "table { width: 100%%; border-collapse: collapse; }");
    fprintf(f, "td, th { padding: 8px; border-bottom: 1px solid #444; text-align: left; }");
    fprintf(f, "</style></head><body>");
    
    fprintf(f, "<h1>🚀 Enterprise Resource Dashboard</h1>");
    fprintf(f, "<div class='grid'>");

    // 2. Call the Modules to inject their HTML
    generateSalesGraph(f);
    checkInventoryHealth(f);
    parseSecurityLogs(f);

    // 3. Close tags
    fprintf(f, "</div></body></html>");
    fclose(f);
    
    printf("Build Complete! Open index.html to view project.\n");
    return 0;
}