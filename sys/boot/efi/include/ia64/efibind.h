begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*++  Copyright (c) 1998  Intel Corporation  Module Name:      efefind.h  Abstract:      EFI to compile bindings     Revision History  --*/
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Basic int types of various widths
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

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

begin_comment
comment|//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
end_comment

begin_comment
comment|// BugBug: Code to debug
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|BIT63
value|0x8000000000000000
end_define

begin_define
define|#
directive|define
name|PLATFORM_IOBASE_ADDRESS
value|(0xffffc000000 | BIT63)
end_define

begin_define
define|#
directive|define
name|PORT_TO_MEMD
parameter_list|(
name|_Port
parameter_list|)
value|(PLATFORM_IOBASE_ADDRESS | ( ( ( (_Port)& 0xfffc)<< 10 ) | ( (_Port)& 0x0fff) ) )
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Macro's with casts make this much easier to use and read.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PORT_TO_MEM8D
parameter_list|(
name|_Port
parameter_list|)
value|(*(UINT8  *)(PORT_TO_MEMD(_Port)))
end_define

begin_define
define|#
directive|define
name|POST_CODE
parameter_list|(
name|_Data
parameter_list|)
value|(PORT_TO_MEM8D(0x80) = (_Data))
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// BugBug: End Debug Code!!!
end_comment

begin_comment
comment|//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
end_comment

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
value|while (TRUE)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Pointers must be aligned to these address to function
end_comment

begin_comment
comment|//  you will get an alignment fault if this value is less than 8
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|MIN_ALIGNMENT_SIZE
value|8
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
value|(UINTN) Adjustment = 0; \             if((UINTN)Value % MIN_ALIGNMENT_SIZE) \                 (UINTN)Adjustment = MIN_ALIGNMENT_SIZE - ((UINTN)Value % MIN_ALIGNMENT_SIZE); \             Value = (UINTN)Value + (UINTN)Adjustment
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define macros to create data structure signatures.
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
comment|// To export& import functions in the EFI emulator environment
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EXPORTAPI
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

begin_comment
comment|//
end_comment

begin_comment
comment|// BugBug: Need to find out if this is portable accross compliers.
end_comment

begin_comment
comment|//
end_comment

begin_function_decl
name|void
name|__mf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|__mf
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MEMORY_FENCE
parameter_list|()
value|__mf()
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
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

end_unit

