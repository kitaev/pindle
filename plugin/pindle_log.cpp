#include "stdafx.h"
#include "pindle_log.h"

void log(char *logMessage) {
	FILE* file = NULL;
	fopen_s(&file, LOG_FILE_PATH, "a");

	if (file) {
		fputs(logMessage, file);
		fputs("\n", file);
		fclose(file);
	}
}