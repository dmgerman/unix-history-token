begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*++  Copyright (c)  1999 - 2003 Intel Corporation. All rights reserved This software and associated documentation (if any) is furnished under a license and may only be used or copied in accordance with the terms of the license. Except as permitted by such license, no part of this software or documentation may be reproduced, stored in a retrieval system, or transmitted in any form or by any means without the express written consent of Intel Corporation.  Module Name:      efefind.h  Abstract:      EFI to compile bindings     Revision History  --*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|//
end_comment

begin_comment
comment|// Basic int types of various widths
end_comment

begin_comment
comment|//
end_comment

begin_if
if|#
directive|if
operator|(
name|__STDC_VERSION__
operator|<
literal|199901L
operator|)
end_if

begin_comment
comment|// No ANSI C 1999/2000 stdint.h integer width declarations
end_comment

begin_if
if|#
directive|if
name|_MSC_EXTENSIONS
end_if

begin_comment
comment|// Use Microsoft C compiler integer width declarations
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|int8_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|UNIX_LP64
end_ifdef

begin_comment
comment|// Use LP64 programming model from C_FLAGS for integer width declarations
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|int8_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|// Assume P64 programming model from C_FLAGS for integer width declarations
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|int8_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Basic EFI types of various widths
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|INT64
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_BASETSD_H_
end_ifndef

begin_typedef
typedef|typedef
name|uint32_t
name|UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|INT32
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint16_t
name|UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|INT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int8_t
name|INT8
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|VOID
end_undef

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_typedef
typedef|typedef
name|int64_t
name|INTN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|UINTN
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|EFI_NT_EMULATOR
end_ifdef

begin_define
define|#
directive|define
name|POST_CODE
parameter_list|(
name|_Data
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|EFI_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|POST_CODE
parameter_list|(
name|_Data
parameter_list|)
value|__asm mov eax,(_Data) __asm out 0x80,al
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|POST_CODE
parameter_list|(
name|_Data
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EFIERR
parameter_list|(
name|a
parameter_list|)
value|(0x8000000000000000 | a)
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_MASK
value|0x8000000000000000
end_define

begin_define
define|#
directive|define
name|EFIERR_OEM
parameter_list|(
name|a
parameter_list|)
value|(0xc000000000000000 | a)
end_define

begin_define
define|#
directive|define
name|BAD_POINTER
value|0xFBFBFBFBFBFBFBFB
end_define

begin_define
define|#
directive|define
name|MAX_ADDRESS
value|0xFFFFFFFFFFFFFFFF
end_define

begin_define
define|#
directive|define
name|BREAKPOINT
parameter_list|()
value|__asm { int 3 }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Pointers must be aligned to these address to function
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|MIN_ALIGNMENT_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|ALIGN_VARIABLE
parameter_list|(
name|Value
parameter_list|,
name|Adjustment
parameter_list|)
define|\
value|(UINTN)Adjustment = 0; \             if((UINTN)Value % MIN_ALIGNMENT_SIZE) \                 (UINTN)Adjustment = MIN_ALIGNMENT_SIZE - ((UINTN)Value % MIN_ALIGNMENT_SIZE); \             Value = (UINTN)Value + (UINTN)Adjustment
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define macros to build data structure signatures from characters.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SIGNATURE_16
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|((A) | (B<<8))
end_define

begin_define
define|#
directive|define
name|EFI_SIGNATURE_32
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|)
value|(EFI_SIGNATURE_16(A,B)     | (EFI_SIGNATURE_16(C,D)<< 16))
end_define

begin_define
define|#
directive|define
name|EFI_SIGNATURE_64
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|,
name|E
parameter_list|,
name|F
parameter_list|,
name|G
parameter_list|,
name|H
parameter_list|)
value|(EFI_SIGNATURE_32(A,B,C,D) | ((UINT64)(EFI_SIGNATURE_32(E,F,G,H))<< 32))
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFIAPI - prototype calling convention for EFI function pointers
end_comment

begin_comment
comment|// BOOTSERVICE - prototype for implementation of a boot service interface
end_comment

begin_comment
comment|// RUNTIMESERVICE - prototype for implementation of a runtime service interface
end_comment

begin_comment
comment|// RUNTIMEFUNCTION - prototype for implementation of a runtime function that is not a service
end_comment

begin_comment
comment|// RUNTIME_CODE - pragma macro for declaring runtime code
end_comment

begin_comment
comment|//
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_define
define|#
directive|define
name|EFIAPI
value|__attribute__((ms_abi))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EFIAPI
end_ifndef

begin_comment
comment|// Forces EFI calling conventions reguardless of compiler options
end_comment

begin_if
if|#
directive|if
name|_MSC_EXTENSIONS
end_if

begin_define
define|#
directive|define
name|EFIAPI
value|__cdecl
end_define

begin_comment
comment|// Force C calling convention for Microsoft C compiler
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EFIAPI
end_define

begin_comment
comment|// Substitute expresion to force C calling convention
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BOOTSERVICE
end_define

begin_comment
comment|//#define RUNTIMESERVICE(proto,a)    alloc_text("rtcode",a); proto a
end_comment

begin_comment
comment|//#define RUNTIMEFUNCTION(proto,a)   alloc_text("rtcode",a); proto a
end_comment

begin_define
define|#
directive|define
name|RUNTIMESERVICE
end_define

begin_define
define|#
directive|define
name|RUNTIMEFUNCTION
end_define

begin_define
define|#
directive|define
name|RUNTIME_CODE
parameter_list|(
name|a
parameter_list|)
value|alloc_text("rtcode", a)
end_define

begin_define
define|#
directive|define
name|BEGIN_RUNTIME_DATA
parameter_list|()
value|data_seg("rtdata")
end_define

begin_define
define|#
directive|define
name|END_RUNTIME_DATA
parameter_list|()
value|data_seg("")
end_define

begin_define
define|#
directive|define
name|VOLATILE
value|volatile
end_define

begin_define
define|#
directive|define
name|MEMORY_FENCE
parameter_list|()
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|EFI_NO_INTERFACE_DECL
end_ifdef

begin_define
define|#
directive|define
name|EFI_FORWARD_DECLARATION
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|EFI_INTERFACE_DECL
parameter_list|(
name|x
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EFI_FORWARD_DECLARATION
parameter_list|(
name|x
parameter_list|)
value|typedef struct _##x x
end_define

begin_define
define|#
directive|define
name|EFI_INTERFACE_DECL
parameter_list|(
name|x
parameter_list|)
value|typedef struct x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EFI_NT_EMULATOR
end_ifdef

begin_comment
comment|//
end_comment

begin_comment
comment|// To help ensure proper coding of integrated drivers, they are
end_comment

begin_comment
comment|// compiled as DLLs.  In NT they require a dll init entry pointer.
end_comment

begin_comment
comment|// The macro puts a stub entry point into the DLL so it will load.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_DRIVER_ENTRY_POINT
parameter_list|(
name|InitFunction
parameter_list|)
define|\
value|EFI_STATUS                                          \     InitFunction (                                      \       EFI_HANDLE  ImageHandle,                          \       EFI_SYSTEM_TABLE  *SystemTable                    \       );                                                \                                                         \     UINTN                                               \     __stdcall                                           \     _DllMainCRTStartup (                                \         UINTN    Inst,                                  \         UINTN    reason_for_call,                       \         VOID    *rserved                                \         )                                               \     {                                                   \         return 1;                                       \     }                                                   \                                                         \     int                                                 \     __declspec( dllexport )                             \     __cdecl                                             \     InitializeDriver (                                  \         void *ImageHandle,                              \         void *SystemTable                               \         )                                               \     {                                                   \         return InitFunction(ImageHandle, SystemTable);  \     }
end_define

begin_define
define|#
directive|define
name|LOAD_INTERNAL_DRIVER
parameter_list|(
name|_if
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|entry
parameter_list|)
define|\
value|(_if)->LoadInternal(type, name, NULL)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|// EFI_NT_EMULATOR
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When build similiar to FW, then link everything together as
end_comment

begin_comment
comment|// one big module.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_DRIVER_ENTRY_POINT
parameter_list|(
name|InitFunction
parameter_list|)
end_define

begin_define
define|#
directive|define
name|LOAD_INTERNAL_DRIVER
parameter_list|(
name|_if
parameter_list|,
name|type
parameter_list|,
name|name
parameter_list|,
name|entry
parameter_list|)
define|\
value|(_if)->LoadInternal(type, name, entry)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// EFI_FW_NT
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|INTERFACE_DECL
parameter_list|(
name|x
parameter_list|)
value|struct x
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|//
end_comment

begin_comment
comment|// Some compilers don't support the forward reference construct:
end_comment

begin_comment
comment|//  typedef struct XXXXX
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The following macro provide a workaround for such cases.
end_comment

begin_comment
comment|//
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_INTERFACE_DECL
end_ifdef

begin_define
define|#
directive|define
name|INTERFACE_DECL
parameter_list|(
name|x
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INTERFACE_DECL
parameter_list|(
name|x
parameter_list|)
value|typedef struct x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_if
if|#
directive|if
name|_MSC_EXTENSIONS
end_if

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4731
name|)
end_pragma

begin_comment
comment|// Suppress warnings about modification of EBP
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

