#include "stdafx.h"
#include "pindle.h"
#include "pindle_log.h"
#include "pindle_plugin.h"
#include "npapi\npfunctions.h"

short _stdcall NP_GetEntryPoints(NPPluginFuncs *nppfuncs)
{	
	log("NP_GetEntryPoints");
	// set version
	nppfuncs->version = 1;
	// set up all functions with stubs.
	nppfuncs->newp = pindle_new;
	nppfuncs->destroy = pindle_destroy;
	nppfuncs->setwindow = pindle_setWindow;
	nppfuncs->newstream = pindle_newStream;
	nppfuncs->destroystream = pindle_destroyStream;
	nppfuncs->asfile = pindle_streamAsFile;
	nppfuncs->writeready = pindle_writeReady;
	nppfuncs->write = pindle_write;
	nppfuncs->print = pindle_print;
	nppfuncs->event = pindle_handleEvent;
	nppfuncs->urlnotify = pindle_urlNotify;
	nppfuncs->setvalue = pindle_setValue;
	nppfuncs->getvalue = pindle_getValue;

	return NPERR_NO_ERROR;
}

short _stdcall NP_Initialize(NPNetscapeFuncs *npnfuncs)
{	
	log("NP_Initialize");
	// check version
	// store reference to the browser functions.
	pindle_setBrowser(npnfuncs);
	// start USB tracking.
	return NPERR_NO_ERROR;
}

short _stdcall NP_Shutdown() 
{
	log("NP_Shutdown");

	pindle_setBrowser(NULL);
	// stop USB tracking.
	return NPERR_NO_ERROR;
}

