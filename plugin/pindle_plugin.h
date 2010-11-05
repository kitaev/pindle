#include "npapi\npfunctions.h"

void pindle_setBrowser(NPNetscapeFuncs* browser);
NPNetscapeFuncs* pindle_getBrowser();

NPError pindle_new(NPMIMEType pluginType, NPP instance, uint16_t mode, int16_t argc, char* argn[], char* argv[], NPSavedData* saved);
NPError pindle_destroy(NPP instance, NPSavedData** save);
NPError pindle_setWindow(NPP instance, NPWindow* window);
NPError pindle_newStream(NPP instance, NPMIMEType type, NPStream* stream, NPBool seekable, uint16_t* stype);
NPError pindle_destroyStream(NPP instance, NPStream* stream, NPReason reason);
int32_t pindle_writeReady(NPP instance, NPStream* stream);
int32_t pindle_write(NPP instance, NPStream* stream, int32_t offset, int32_t len, void* buffer);
void pindle_streamAsFile(NPP instance, NPStream* stream, const char* fname);
void pindle_print(NPP instance, NPPrint* platformPrint);
int16_t pindle_handleEvent(NPP instance, void* event);
void pindle_urlNotify(NPP instance, const char* url, NPReason reason, void* notifyData);
/* Any NPObjects returned to the browser via NPP_GetValue should be retained
   by the plugin on the way out. The browser is responsible for releasing. */
NPError pindle_getValue(NPP instance, NPPVariable variable, void *ret_value);
NPError pindle_setValue(NPP instance, NPNVariable variable, void *value);
