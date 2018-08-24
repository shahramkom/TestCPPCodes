// Delete this line if you don't use precompiled header in your project
#include "stdafx.h"

#include <CrashRpt.h>

/*
   +-------------------------------------------------+
   | @ {AppName}                                   X |
   +-------------------------------------------------+
   |                                                 |
   | {AppName} has stopped working                   |
   |                                                 |
   | Sending collected information to the {Company}. |
   | This might take several minutes...   +--------+ |
   |                                      | Cancel | |
   |                                      +--------+ |
   +-------------------------------------------------+
*/

// global crash handler
crash_rpt::CrashRpt g_crashRpt(
	"567a3c8b-e059-46b0-81e6-7b2af929fae6", // GUID assigned to this application.
	L"TestCPP", // Application name that will be used in a message box.
	L"TestCPP" // Company name that will be used in a message box.
	);
