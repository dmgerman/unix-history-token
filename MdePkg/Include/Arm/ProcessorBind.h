begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Processor or Compiler specific defines and types for ARM.    Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR>   Portions copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PROCESSOR_BIND_H__
end_ifndef

begin_define
define|#
directive|define
name|__PROCESSOR_BIND_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Define the processor type so other code can make processor based choices
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MDE_CPU_ARM
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

begin_comment
comment|//
end_comment

begin_comment
comment|// RVCT does not support the __builtin_unreachable() macro
end_comment

begin_comment
comment|//
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ARMCC_VERSION
end_ifdef

begin_define
define|#
directive|define
name|UNREACHABLE
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|_MSC_EXTENSIONS
end_if

begin_comment
comment|//
end_comment

begin_comment
comment|// use Microsoft* C compiler dependent integer width types
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64
name|INT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32
name|INT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|CHAR16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|INT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BOOLEAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|CHAR8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|char
name|INT8
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|//
end_comment

begin_comment
comment|// Assume standard ARM alignment.
end_comment

begin_comment
comment|// Need to check portability of long long
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|INT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|INT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|CHAR16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|INT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BOOLEAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
name|CHAR8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|char
name|INT8
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|///
end_comment

begin_comment
comment|/// Unsigned value of native width.  (4 bytes on supported 32-bit processor instructions,
end_comment

begin_comment
comment|/// 8 bytes on supported 64-bit processor instructions)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|UINTN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signed value of native width.  (4 bytes on supported 32-bit processor instructions,
end_comment

begin_comment
comment|/// 8 bytes on supported 64-bit processor instructions)
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|INT32
name|INTN
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Processor specific defines
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A value of native width with the highest bit set.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MAX_BIT
value|0x80000000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A value of native width with the two highest bits set.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MAX_2_BITS
value|0xC0000000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Maximum legal ARM address
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MAX_ADDRESS
value|0xFFFFFFFF
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Maximum legal ARM INTN and UINTN values.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MAX_INTN
value|((INTN)0x7FFFFFFF)
end_define

begin_define
define|#
directive|define
name|MAX_UINTN
value|((UINTN)0xFFFFFFFF)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The stack alignment required for ARM
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|CPU_STACK_ALIGNMENT
value|sizeof(UINT64)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Page allocation granularity for ARM
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PAGE_ALLOCATION_GRANULARITY
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|RUNTIME_PAGE_ALLOCATION_GRANULARITY
value|(0x1000)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Modifier to ensure that all protocol member functions and EFI intrinsics
end_comment

begin_comment
comment|// use the correct C calling convention. All protocol member functions and
end_comment

begin_comment
comment|// EFI intrinsics are required to modify their member functions with EFIAPI.
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
comment|// When compiling with Clang, we still use GNU as for the assembler, so we still
end_comment

begin_comment
comment|// need to define the GCC_ASM* macros.
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// For GNU assembly code, .global or .globl can declare global symbols.
end_comment

begin_comment
comment|/// Define this macro to unify the usage.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ASM_GLOBAL
value|.globl
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// ARM EABI defines that the linker should not manipulate call relocations
end_comment

begin_comment
comment|/// (do bl/blx conversion) unless the target symbol has function type.
end_comment

begin_comment
comment|/// CodeSourcery 2010.09 started requiring the .type to function properly
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|INTERWORK_FUNC
parameter_list|(
name|func__
parameter_list|)
value|.type ASM_PFX(func__), %function
end_define

begin_define
define|#
directive|define
name|GCC_ASM_EXPORT
parameter_list|(
name|func__
parameter_list|)
define|\
value|.global  _CONCATENATE (__USER_LABEL_PREFIX__, func__)    ;\              .type ASM_PFX(func__), %function
end_define

begin_define
define|#
directive|define
name|GCC_ASM_IMPORT
parameter_list|(
name|func__
parameter_list|)
define|\
value|.extern  _CONCATENATE (__USER_LABEL_PREFIX__, func__)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|//
end_comment

begin_comment
comment|// .type not supported by Apple Xcode tools
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|INTERWORK_FUNC
parameter_list|(
name|func__
parameter_list|)
end_define

begin_define
define|#
directive|define
name|GCC_ASM_EXPORT
parameter_list|(
name|func__
parameter_list|)
define|\
value|.globl  _CONCATENATE (__USER_LABEL_PREFIX__, func__)
end_define

begin_define
unit|\
define|#
directive|define
name|GCC_ASM_IMPORT
parameter_list|(
name|name
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

begin_comment
comment|/**   Return the pointer to the first instruction of a function given a function pointer.   On ARM CPU architectures, these two pointer values are the same,    so the implementation of this macro is very simple.      @param  FunctionPointer   A pointer to a function.    @return The pointer to the first instruction of a function given a function pointer.    **/
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ENTRY_POINT
parameter_list|(
name|FunctionPointer
parameter_list|)
value|(VOID *)(UINTN)(FunctionPointer)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__USER_LABEL_PREFIX__
end_ifndef

begin_define
define|#
directive|define
name|__USER_LABEL_PREFIX__
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

