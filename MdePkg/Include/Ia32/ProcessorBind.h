begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Processor or Compiler specific defines and types for IA-32 architecture.  Copyright (c) 2006 - 2015, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
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
comment|/// Define the processor type so other code can make processor based choices.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MDE_CPU_IA32
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_comment
comment|//
end_comment

begin_comment
comment|// Disable ICC's remark #869: "Parameter" was never referenced warning.
end_comment

begin_comment
comment|// This is legal ANSI C code so we disable the remark that is turned on with -Wall
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|869
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Disable ICC's remark #1418: external function definition with no prior declaration.
end_comment

begin_comment
comment|// This is legal ANSI C code so we disable the remark that is turned on with /W4
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|1418
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Disable ICC's remark #1419: external declaration in primary source file
end_comment

begin_comment
comment|// This is legal ANSI C code so we disable the remark that is turned on with /W4
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|1419
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Disable ICC's remark #593: "Variable" was set but never used.
end_comment

begin_comment
comment|// This is legal ANSI C code so we disable the remark that is turned on with /W4
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|593
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_EXTENSIONS
argument_list|)
end_if

begin_comment
comment|//
end_comment

begin_comment
comment|// Disable warning that make it impossible to compile at /W4
end_comment

begin_comment
comment|// This only works for Microsoft* tools
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Disabling bitfield type checking warnings.
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4214
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Disabling the unreferenced formal parameter warnings.
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4100
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Disable slightly different base types warning as CHAR8 * can not be set
end_comment

begin_comment
comment|// to a constant string.
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4057
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// ASSERT(FALSE) or while (TRUE) are legal constructs so suppress this warning
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4127
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// This warning is caused by functions defined but not used. For precompiled header only.
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4505
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// This warning is caused by empty (after preprocessing) source file. For precompiled header only.
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4206
name|)
end_pragma

begin_if
if|#
directive|if
name|_MSC_VER
operator|==
literal|1800
operator|||
name|_MSC_VER
operator|==
literal|1900
end_if

begin_comment
comment|//
end_comment

begin_comment
comment|// Disable these warnings for VS2013.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This warning is for potentially uninitialized local variable, and it may cause false
end_comment

begin_comment
comment|// positive issues in VS2013 and VS2015 build
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4701
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// This warning is for potentially uninitialized local pointer variable, and it may cause
end_comment

begin_comment
comment|// false positive issues in VS2013 and VS2015 build
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4703
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_EXTENSIONS
argument_list|)
end_if

begin_comment
comment|//
end_comment

begin_comment
comment|// use Microsoft C compiler dependent integer width types
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// 8-byte unsigned value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|UINT64
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 8-byte signed value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|__int64
name|INT64
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 4-byte unsigned value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|UINT32
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 4-byte signed value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|__int32
name|INT32
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 2-byte unsigned value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|UINT16
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 2-byte Character.  Unless otherwise specified all strings are stored in the
end_comment

begin_comment
comment|/// UTF-16 encoding format as defined by Unicode 2.1 and ISO/IEC 10646 standards.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|CHAR16
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 2-byte signed value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|short
name|INT16
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Logical Boolean.  1-byte value containing 0 for FALSE or a 1 for TRUE.  Other
end_comment

begin_comment
comment|/// values are undefined.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BOOLEAN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 1-byte unsigned value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UINT8
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 1-byte Character.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|char
name|CHAR8
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 1-byte signed value.
end_comment

begin_comment
comment|///
end_comment

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
comment|///
end_comment

begin_comment
comment|/// 8-byte unsigned value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|UINT64
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 8-byte signed value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|long
name|long
name|INT64
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 4-byte unsigned value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT32
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 4-byte signed value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|int
name|INT32
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 2-byte unsigned value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|UINT16
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 2-byte Character.  Unless otherwise specified all strings are stored in the
end_comment

begin_comment
comment|/// UTF-16 encoding format as defined by Unicode 2.1 and ISO/IEC 10646 standards.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|CHAR16
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 2-byte signed value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|short
name|INT16
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Logical Boolean.  1-byte value containing 0 for FALSE or a 1 for TRUE.  Other
end_comment

begin_comment
comment|/// values are undefined.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BOOLEAN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 1-byte unsigned value.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|UINT8
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 1-byte Character
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|char
name|CHAR8
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 1-byte signed value
end_comment

begin_comment
comment|///
end_comment

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
comment|/// Unsigned value of native width.  (4 bytes on supported 32-bit processor instructions;
end_comment

begin_comment
comment|/// 8 bytes on supported 64-bit processor instructions.)
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
comment|/// Signed value of native width.  (4 bytes on supported 32-bit processor instructions;
end_comment

begin_comment
comment|/// 8 bytes on supported 64-bit processor instructions.)
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
comment|/// Maximum legal IA-32 address.
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
comment|/// Maximum legal IA-32 INTN and UINTN values.
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
comment|/// The stack alignment required for IA-32.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|CPU_STACK_ALIGNMENT
value|sizeof(UINTN)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Page allocation granularity for IA-32.
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

begin_ifdef
ifdef|#
directive|ifdef
name|EFIAPI
end_ifdef

begin_comment
comment|///
end_comment

begin_comment
comment|/// If EFIAPI is already defined, then we use that definition.
end_comment

begin_comment
comment|///
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_EXTENSIONS
argument_list|)
end_elif

begin_comment
comment|///
end_comment

begin_comment
comment|/// Microsoft* compiler specific method for EFIAPI calling convention.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFIAPI
value|__cdecl
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_comment
comment|///
end_comment

begin_comment
comment|/// GCC specific method for EFIAPI calling convention.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFIAPI
value|__attribute__((cdecl))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|///
end_comment

begin_comment
comment|/// The default for a non Microsoft* or GCC compiler is to assume the EFI ABI
end_comment

begin_comment
comment|/// is the standard.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFIAPI
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Return the pointer to the first instruction of a function given a function pointer.   On IA-32 CPU architectures, these two pointer values are the same,    so the implementation of this macro is very simple.      @param  FunctionPointer   A pointer to a function.    @return The pointer to the first instruction of a function given a function pointer.    **/
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
value|_
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

