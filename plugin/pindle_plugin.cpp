#include "stdafx.h"
#include "pindle_plugin.h"
#include "pindle_log.h"
#include "npapi\npfunctions.h"

NPError pindle_new(NPMIMEType pluginType, NPP instance, uint16_t mode, int16_t argc, char* argn[], char* argv[], NPSavedData* saved) {
	log("->pindle_new");
	NPObject *window = NULL;
	pindle_getBrowser()->getvalue(instance, NPNVWindowNPObject, window);
	return NPERR_NO_ERROR;
}

NPError pindle_destroy(NPP instance, NPSavedData** save) {
	log("->pindle_destroy");
	return NPERR_NO_ERROR;
}
NPError pindle_setWindow(NPP instance, NPWindow* window) {
	log("->pindle_setWindow");
	return NPERR_NO_ERROR;
}
NPError pindle_newStream(NPP instance, NPMIMEType type, NPStream* stream, NPBool seekable, uint16_t* stype) {
	log("->pindle_newStream");
	return NPERR_NO_ERROR;
}
NPError pindle_destroyStream(NPP instance, NPStream* stream, NPReason reason) {
	log("->pindle_destroyStream");
	return NPERR_NO_ERROR;
}

int32_t pindle_writeReady(NPP instance, NPStream* stream) {
	log("->pindle_writeReady");
	return -1;
}
int32_t pindle_write(NPP instance, NPStream* stream, int32_t offset, int32_t len, void* buffer) {
	log("->pindle_write");
	return -1;
}
void pindle_streamAsFile(NPP instance, NPStream* stream, const char* fname) {
	log("->pindle_streamAsFile");
}
void pindle_print(NPP instance, NPPrint* platformPrint) {
	log("->pindle_print");
}
int16_t pindle_handleEvent(NPP instance, void* event) {
	log("->pindle_handleEvent");
	return 0;
}
void pindle_urlNotify(NPP instance, const char* url, NPReason reason, void* notifyData) {
	log("->pindle_urlNotify");
}
/* Any NPObjects returned to the browser via NPP_GetValue should be retained
   by the plugin on the way out. The browser is responsible for releasing. */
NPError pindle_getValue(NPP instance, NPPVariable variable, void *ret_value) {
	log("->pindle_getValue");
	return NPERR_NO_ERROR;
}
NPError pindle_setValue(NPP instance, NPNVariable variable, void *value) {
	log("->pindle_setValue");
	return NPERR_NO_ERROR;
}

static NPNetscapeFuncs* our_browser = NULL;

void pindle_setBrowser(NPNetscapeFuncs* browser) {
	our_browser = browser;
}

NPNetscapeFuncs* pindle_getBrowser() {
	return our_browser;
}