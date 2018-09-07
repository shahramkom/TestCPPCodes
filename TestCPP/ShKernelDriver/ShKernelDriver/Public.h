/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_ShKernelDriver,
    0x9d3021be,0x5c13,0x41eb,0x87,0xab,0x35,0x18,0xa7,0xda,0x8f,0x30);
// {9d3021be-5c13-41eb-87ab-3518a7da8f30}
