begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*++  Copyright (c) 2004 - 2012, Intel Corporation. All rights reserved.  This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  Module Name:    EfiBind.h  Abstract:    Processor or Compiler specific defines and types for IA-32.   We are using the ANSI C 2000 _t type definitions for basic types.   This it technically a violation of the coding standard, but they   are used to make EfiTypes.h portable. Code other than EfiTypes.h   should never use any ANSI C 2000 _t integer types.  --*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_BIND_H_
end_ifndef

begin_define
define|#
directive|define
name|_EFI_BIND_H_
end_define

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
name|EFI_APPLICATION_ENTRY_POINT
value|EFI_DRIVER_ENTRY_POINT
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Make sure we are using the correct packing rules per EFI specification
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

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
comment|// Assume standard IA-32 alignment.
end_comment

begin_comment
comment|// BugBug: Need to check portability of long long
end_comment

begin_comment
comment|//
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
name|signed
name|char
name|int8_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|//
end_comment

begin_comment
comment|// Native integer size in stdint.h
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|UINTN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|INTN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFIERR
parameter_list|(
name|a
parameter_list|)
value|(0x80000000 | a)
end_define

begin_define
define|#
directive|define
name|EFI_ERROR_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|EFIERR_OEM
parameter_list|(
name|a
parameter_list|)
value|(0xc0000000 | a)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Processor specific defines
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_MAX_BIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MAX_2_BITS
value|0xC0000000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Maximum legal IA-32 address
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_MAX_ADDRESS
value|0xFFFFFFFF
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Bad pointer value to use in check builds.
end_comment

begin_comment
comment|//  if you see this value you are using uninitialized or free'ed data
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_BAD_POINTER
value|0xAFAFAFAF
end_define

begin_define
define|#
directive|define
name|EFI_BAD_POINTER_AS_BYTE
value|0xAF
end_define

begin_define
define|#
directive|define
name|EFI_DEADLOOP
parameter_list|()
value|{ volatile UINTN __iii; __iii = 1; while (__iii); }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Inject a break point in the code to assist debugging for NT Emulation Environment
end_comment

begin_comment
comment|// For real hardware, just put in a halt loop. Don't do a while(1) because the
end_comment

begin_comment
comment|// compiler will optimize away the rest of the function following, so that you run out in
end_comment

begin_comment
comment|// the weeds if you skip over it with a debugger.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_BREAKPOINT
value|EFI_DEADLOOP()
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Memory Fence forces serialization, and is needed to support out of order
end_comment

begin_comment
comment|//  memory transactions. The Memory Fence is mainly used to make sure IO
end_comment

begin_comment
comment|//  transactions complete in a deterministic sequence, and to syncronize locks
end_comment

begin_comment
comment|//  an other MP code. Currently no memory fencing is required.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|MEMORY_FENCE
parameter_list|()
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Some compilers don't support the forward reference construct:
end_comment

begin_comment
comment|//  typedef struct XXXXX. The forward reference is required for
end_comment

begin_comment
comment|//  ANSI compatibility.
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//
end_comment

begin_comment
comment|// Some C compilers optimize the calling conventions to increase performance.
end_comment

begin_comment
comment|// EFIAPI is used to make all public APIs follow the standard C calling
end_comment

begin_comment
comment|// convention.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFIAPI
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// For symbol name in GNU assembly code, an extra "_" is necessary
end_comment

begin_comment
comment|//
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// Private worker functions for ASM_PFX()
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|_CONCATENATE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__CONCATENATE(a, b)
end_define

begin_define
define|#
directive|define
name|__CONCATENATE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a ## b
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The __USER_LABEL_PREFIX__ macro predefined by GNUC represents the prefix
end_comment

begin_comment
comment|/// on symbols in assembly language.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ASM_PFX
parameter_list|(
name|name
parameter_list|)
value|_CONCATENATE (__USER_LABEL_PREFIX__, name)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INTERFACE_DECL
parameter_list|(
name|x
parameter_list|)
value|struct x
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

