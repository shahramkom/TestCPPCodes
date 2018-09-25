

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 06:44:07 2038
 */
/* Compiler settings for ShPackage.idl:
    Oicf, W0, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data , no_format_optimization
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __ShPackage_h__
#define __ShPackage_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISingleViewEditor_FWD_DEFINED__
#define __ISingleViewEditor_FWD_DEFINED__
typedef interface ISingleViewEditor ISingleViewEditor;

#endif 	/* __ISingleViewEditor_FWD_DEFINED__ */


#ifndef __ShPackagePackage_FWD_DEFINED__
#define __ShPackagePackage_FWD_DEFINED__

#ifdef __cplusplus
typedef class ShPackagePackage ShPackagePackage;
#else
typedef struct ShPackagePackage ShPackagePackage;
#endif /* __cplusplus */

#endif 	/* __ShPackagePackage_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "vsshell.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ShPackage_0000_0000 */
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_ShPackage_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ShPackage_0000_0000_v0_0_s_ifspec;


#ifndef __ShPackageLib_LIBRARY_DEFINED__
#define __ShPackageLib_LIBRARY_DEFINED__

/* library ShPackageLib */
/* [helpstring][version][uuid] */ 



EXTERN_C const IID LIBID_ShPackageLib;

#ifndef __ISingleViewEditor_INTERFACE_DEFINED__
#define __ISingleViewEditor_INTERFACE_DEFINED__

/* interface ISingleViewEditor */
/* [unique][helpstring][nonextensible][oleautomation][uuid][object] */ 


EXTERN_C const IID IID_ISingleViewEditor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("84fc9108-da74-44ae-9490-bfe4d5af19f7")
    ISingleViewEditor : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DTE( 
            /* [retval][out] */ /* external definition not present */ _DTE **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Parent( 
            /* [retval][out] */ /* external definition not present */ _DTE **pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DefaultTabStop( 
            /* [retval][out] */ float *pdVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DefaultTabStop( 
            /* [in] */ float dVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Range( 
            /* [retval][out] */ IDispatch **ppRange) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Selection( 
            /* [retval][out] */ IDispatch **ppSelection) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [retval][out] */ long *plFlags) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Flags( 
            /* [in] */ long lFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindText( 
            /* [in] */ BSTR pStr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetText( 
            /* [in] */ BSTR pStr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TypeText( 
            /* [in] */ BSTR pStr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cut( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Copy( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Paste( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Delete( 
            /* [in] */ long lUnit,
            /* [in] */ long cUnit) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveUp( 
            /* [in] */ long lUnit,
            /* [in] */ long cUnit,
            /* [in] */ long lExtend) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveDown( 
            /* [in] */ long lUnit,
            /* [in] */ long cUnit,
            /* [in] */ long lExtend) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveLeft( 
            /* [in] */ long lUnit,
            /* [in] */ long cUnit,
            /* [in] */ long lExtend) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE MoveRight( 
            /* [in] */ long lUnit,
            /* [in] */ long cUnit,
            /* [in] */ long lExtend) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EndKey( 
            /* [in] */ long lUnit,
            /* [in] */ long lExtend) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HomeKey( 
            /* [in] */ long lUnit,
            /* [in] */ long lExtend) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISingleViewEditorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISingleViewEditor * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISingleViewEditor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISingleViewEditor * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISingleViewEditor * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISingleViewEditor * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISingleViewEditor * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISingleViewEditor * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DTE )( 
            ISingleViewEditor * This,
            /* [retval][out] */ /* external definition not present */ _DTE **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Parent )( 
            ISingleViewEditor * This,
            /* [retval][out] */ /* external definition not present */ _DTE **pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultTabStop )( 
            ISingleViewEditor * This,
            /* [retval][out] */ float *pdVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultTabStop )( 
            ISingleViewEditor * This,
            /* [in] */ float dVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Range )( 
            ISingleViewEditor * This,
            /* [retval][out] */ IDispatch **ppRange);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Selection )( 
            ISingleViewEditor * This,
            /* [retval][out] */ IDispatch **ppSelection);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            ISingleViewEditor * This,
            /* [retval][out] */ long *plFlags);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Flags )( 
            ISingleViewEditor * This,
            /* [in] */ long lFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindText )( 
            ISingleViewEditor * This,
            /* [in] */ BSTR pStr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetText )( 
            ISingleViewEditor * This,
            /* [in] */ BSTR pStr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *TypeText )( 
            ISingleViewEditor * This,
            /* [in] */ BSTR pStr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Cut )( 
            ISingleViewEditor * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Copy )( 
            ISingleViewEditor * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Paste )( 
            ISingleViewEditor * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Delete )( 
            ISingleViewEditor * This,
            /* [in] */ long lUnit,
            /* [in] */ long cUnit);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveUp )( 
            ISingleViewEditor * This,
            /* [in] */ long lUnit,
            /* [in] */ long cUnit,
            /* [in] */ long lExtend);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveDown )( 
            ISingleViewEditor * This,
            /* [in] */ long lUnit,
            /* [in] */ long cUnit,
            /* [in] */ long lExtend);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveLeft )( 
            ISingleViewEditor * This,
            /* [in] */ long lUnit,
            /* [in] */ long cUnit,
            /* [in] */ long lExtend);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *MoveRight )( 
            ISingleViewEditor * This,
            /* [in] */ long lUnit,
            /* [in] */ long cUnit,
            /* [in] */ long lExtend);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EndKey )( 
            ISingleViewEditor * This,
            /* [in] */ long lUnit,
            /* [in] */ long lExtend);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HomeKey )( 
            ISingleViewEditor * This,
            /* [in] */ long lUnit,
            /* [in] */ long lExtend);
        
        END_INTERFACE
    } ISingleViewEditorVtbl;

    interface ISingleViewEditor
    {
        CONST_VTBL struct ISingleViewEditorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISingleViewEditor_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISingleViewEditor_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISingleViewEditor_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISingleViewEditor_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISingleViewEditor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISingleViewEditor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISingleViewEditor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISingleViewEditor_get_DTE(This,pVal)	\
    ( (This)->lpVtbl -> get_DTE(This,pVal) ) 

#define ISingleViewEditor_get_Parent(This,pVal)	\
    ( (This)->lpVtbl -> get_Parent(This,pVal) ) 

#define ISingleViewEditor_get_DefaultTabStop(This,pdVal)	\
    ( (This)->lpVtbl -> get_DefaultTabStop(This,pdVal) ) 

#define ISingleViewEditor_put_DefaultTabStop(This,dVal)	\
    ( (This)->lpVtbl -> put_DefaultTabStop(This,dVal) ) 

#define ISingleViewEditor_get_Range(This,ppRange)	\
    ( (This)->lpVtbl -> get_Range(This,ppRange) ) 

#define ISingleViewEditor_get_Selection(This,ppSelection)	\
    ( (This)->lpVtbl -> get_Selection(This,ppSelection) ) 

#define ISingleViewEditor_get_Flags(This,plFlags)	\
    ( (This)->lpVtbl -> get_Flags(This,plFlags) ) 

#define ISingleViewEditor_put_Flags(This,lFlags)	\
    ( (This)->lpVtbl -> put_Flags(This,lFlags) ) 

#define ISingleViewEditor_FindText(This,pStr)	\
    ( (This)->lpVtbl -> FindText(This,pStr) ) 

#define ISingleViewEditor_SetText(This,pStr)	\
    ( (This)->lpVtbl -> SetText(This,pStr) ) 

#define ISingleViewEditor_TypeText(This,pStr)	\
    ( (This)->lpVtbl -> TypeText(This,pStr) ) 

#define ISingleViewEditor_Cut(This)	\
    ( (This)->lpVtbl -> Cut(This) ) 

#define ISingleViewEditor_Copy(This)	\
    ( (This)->lpVtbl -> Copy(This) ) 

#define ISingleViewEditor_Paste(This)	\
    ( (This)->lpVtbl -> Paste(This) ) 

#define ISingleViewEditor_Delete(This,lUnit,cUnit)	\
    ( (This)->lpVtbl -> Delete(This,lUnit,cUnit) ) 

#define ISingleViewEditor_MoveUp(This,lUnit,cUnit,lExtend)	\
    ( (This)->lpVtbl -> MoveUp(This,lUnit,cUnit,lExtend) ) 

#define ISingleViewEditor_MoveDown(This,lUnit,cUnit,lExtend)	\
    ( (This)->lpVtbl -> MoveDown(This,lUnit,cUnit,lExtend) ) 

#define ISingleViewEditor_MoveLeft(This,lUnit,cUnit,lExtend)	\
    ( (This)->lpVtbl -> MoveLeft(This,lUnit,cUnit,lExtend) ) 

#define ISingleViewEditor_MoveRight(This,lUnit,cUnit,lExtend)	\
    ( (This)->lpVtbl -> MoveRight(This,lUnit,cUnit,lExtend) ) 

#define ISingleViewEditor_EndKey(This,lUnit,lExtend)	\
    ( (This)->lpVtbl -> EndKey(This,lUnit,lExtend) ) 

#define ISingleViewEditor_HomeKey(This,lUnit,lExtend)	\
    ( (This)->lpVtbl -> HomeKey(This,lUnit,lExtend) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISingleViewEditor_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ShPackagePackage;

#ifdef __cplusplus

class DECLSPEC_UUID("99b32a0f-4993-4e51-bece-fb41a31e181a")
ShPackagePackage;
#endif
#endif /* __ShPackageLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


