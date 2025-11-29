#include "modules.h"
#include <string.h>

void parseSecurityLogs(FILE *f) {
    FILE *data = fopen("server.log", "r");
    char line[256];
    int errorCount = 0;
    int warningCount = 0;

    // Logic: Read line by line and look for keywords
    while(fgets(line, sizeof(line), data)) {
        if(strstr(line, "[ERROR]")) errorCount++;
        if(strstr(line, "[WARNING]")) warningCount++;
    }

    fprintf(f, "<div class='card'><h2>🛡️ Security Overview</h2>");
    fprintf(f, "<p>System Log Scan Completed.</p>");
    fprintf(f, "<h3>Errors Found: <span style='color:red; font-size: 24px;'>%d</span></h3>", errorCount);
    fprintf(f, "<h3>Warnings: <span style='color:orange;'>%d</span></h3>", warningCount);
    
    if(errorCount == 0) fprintf(f, "<p class='safe'>System Secure.</p>");
    else fprintf(f, "<p class='alert'>Attention Required!</p>");
    
    fprintf(f, "</div>");
    fclose(data);
}