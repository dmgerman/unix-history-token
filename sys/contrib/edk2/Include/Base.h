begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Root include file for Mde Package Base type modules    This is the include file for any module of type base. Base modules only use   types defined via this include file and can be ported easily to any   environment. There are a set of base libraries in the Mde Package that can   be used to implement base modules.  Copyright (c) 2006 - 2017, Intel Corporation. All rights reserved.<BR> Portions copyright (c) 2008 - 2009, Apple Inc. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BASE_H__
end_ifndef

begin_define
define|#
directive|define
name|__BASE_H__
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Include processor specific binding
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|<ProcessorBind.h>
end_include

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
comment|// Disable warning when last field of data structure is a zero sized array.
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
name|4200
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Verifies the storage size of a given data type.    This macro generates a divide by zero error or a zero size array declaration in   the preprocessor if the size is incorrect.  These are declared as "extern" so   the space for these arrays will not be in the modules.    @param  TYPE  The date type to determine the size of.   @param  Size  The expected size for the TYPE.  **/
end_comment

begin_define
define|#
directive|define
name|VERIFY_SIZE_OF
parameter_list|(
name|TYPE
parameter_list|,
name|Size
parameter_list|)
value|extern UINT8 _VerifySizeof##TYPE[(sizeof(TYPE) == (Size)) / (sizeof(TYPE) == (Size))]
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Verify that ProcessorBind.h produced UEFI Data Types that are compliant with
end_comment

begin_comment
comment|// Section 2.3.1 of the UEFI 2.3 Specification.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|BOOLEAN
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|INT8
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|UINT8
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|INT16
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|UINT16
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|INT32
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|UINT32
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|INT64
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|UINT64
argument_list|,
literal|8
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|CHAR8
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|CHAR16
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// The following three enum types are used to verify that the compiler
end_comment

begin_comment
comment|// configuration for enum types is compliant with Section 2.3.1 of the
end_comment

begin_comment
comment|// UEFI 2.3 Specification. These enum types and enum values are not
end_comment

begin_comment
comment|// intended to be used. A prefix of '__' is used avoid conflicts with
end_comment

begin_comment
comment|// other types.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|__VerifyUint8EnumValue
init|=
literal|0xff
block|}
name|__VERIFY_UINT8_ENUM_SIZE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|__VerifyUint16EnumValue
init|=
literal|0xffff
block|}
name|__VERIFY_UINT16_ENUM_SIZE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|__VerifyUint32EnumValue
init|=
literal|0xffffffff
block|}
name|__VERIFY_UINT32_ENUM_SIZE
typedef|;
end_typedef

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|__VERIFY_UINT8_ENUM_SIZE
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|__VERIFY_UINT16_ENUM_SIZE
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERIFY_SIZE_OF
argument_list|(
name|__VERIFY_UINT32_ENUM_SIZE
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// The Microsoft* C compiler can removed references to unreferenced data items
end_comment

begin_comment
comment|//  if the /OPT:REF linker option is used. We defined a macro as this is a
end_comment

begin_comment
comment|//  a non standard extension
end_comment

begin_comment
comment|//
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_EXTENSIONS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MDE_CPU_EBC
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// Remove global variable from the linked image if there are no references to
end_comment

begin_comment
comment|/// it after all compiler and linker optimizations have been performed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|GLOBAL_REMOVE_IF_UNREFERENCED
value|__declspec(selectany)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|///
end_comment

begin_comment
comment|/// Remove the global variable from the linked image if there are no references
end_comment

begin_comment
comment|///  to it after all compiler and linker optimizations have been performed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|GLOBAL_REMOVE_IF_UNREFERENCED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//
end_comment

begin_comment
comment|// Should be used in combination with NORETURN to avoid 'noreturn' returns
end_comment

begin_comment
comment|// warnings.
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNREACHABLE
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|>
literal|4
operator|||
operator|(
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|>
literal|4
operator|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signal compilers and analyzers that this call is not reachable.  It is
end_comment

begin_comment
comment|/// up to the compiler to remove any code past that point.
end_comment

begin_comment
comment|/// Not implemented by GCC 4.4 or earlier.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|UNREACHABLE
parameter_list|()
value|__builtin_unreachable ()
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__has_feature
argument_list|)
end_elif

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_unreachable
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signal compilers and analyzers that this call is not reachable.  It is
end_comment

begin_comment
comment|/// up to the compiler to remove any code past that point.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|UNREACHABLE
parameter_list|()
value|__builtin_unreachable ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNREACHABLE
end_ifndef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signal compilers and analyzers that this call is not reachable.  It is
end_comment

begin_comment
comment|/// up to the compiler to remove any code past that point.
end_comment

begin_comment
comment|///
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//
end_comment

begin_comment
comment|// Signaling compilers and analyzers that a certain function cannot return may
end_comment

begin_comment
comment|// remove all following code and thus lead to better optimization and less
end_comment

begin_comment
comment|// false positives.
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NORETURN
end_ifndef

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
comment|/// Signal compilers and analyzers that the function cannot return.
end_comment

begin_comment
comment|/// It is up to the compiler to remove any code past a call to functions
end_comment

begin_comment
comment|/// flagged with this attribute.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|NORETURN
value|__attribute__((noreturn))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_EXTENSIONS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MDE_CPU_EBC
argument_list|)
end_elif

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signal compilers and analyzers that the function cannot return.
end_comment

begin_comment
comment|/// It is up to the compiler to remove any code past a call to functions
end_comment

begin_comment
comment|/// flagged with this attribute.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|NORETURN
value|__declspec(noreturn)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signal compilers and analyzers that the function cannot return.
end_comment

begin_comment
comment|/// It is up to the compiler to remove any code past a call to functions
end_comment

begin_comment
comment|/// flagged with this attribute.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|NORETURN
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
comment|//
end_comment

begin_comment
comment|// Should be used in combination with ANALYZER_NORETURN to avoid 'noreturn'
end_comment

begin_comment
comment|// returns warnings.
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ANALYZER_UNREACHABLE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__clang_analyzer__
end_ifdef

begin_if
if|#
directive|if
name|__has_builtin
argument_list|(
name|__builtin_unreachable
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signal the analyzer that this call is not reachable.
end_comment

begin_comment
comment|/// This excludes compilers.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ANALYZER_UNREACHABLE
parameter_list|()
value|__builtin_unreachable ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ANALYZER_UNREACHABLE
end_ifndef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signal the analyzer that this call is not reachable.
end_comment

begin_comment
comment|/// This excludes compilers.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ANALYZER_UNREACHABLE
parameter_list|()
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
comment|//
end_comment

begin_comment
comment|// Static Analyzers may issue errors about potential NULL-dereferences when
end_comment

begin_comment
comment|// dereferencing a pointer, that has been checked before, outside of a
end_comment

begin_comment
comment|// NULL-check.  This may lead to false positives, such as when using ASSERT()
end_comment

begin_comment
comment|// for verification.
end_comment

begin_comment
comment|//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ANALYZER_NORETURN
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__has_feature
end_ifdef

begin_if
if|#
directive|if
name|__has_feature
argument_list|(
name|attribute_analyzer_noreturn
argument_list|)
end_if

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signal analyzers that the function cannot return.
end_comment

begin_comment
comment|/// This excludes compilers.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ANALYZER_NORETURN
value|__attribute__((analyzer_noreturn))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ANALYZER_NORETURN
end_ifndef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Signal the analyzer that the function cannot return.
end_comment

begin_comment
comment|/// This excludes compilers.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|ANALYZER_NORETURN
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
comment|//
end_comment

begin_comment
comment|// For symbol name in assembly code, an extra "_" is sometimes necessary
end_comment

begin_comment
comment|//
end_comment

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

begin_if
if|#
directive|if
name|__APPLE__
end_if

begin_comment
comment|//
end_comment

begin_comment
comment|// Apple extension that is used by the linker to optimize code size
end_comment

begin_comment
comment|// with assembly functions. Put at the end of your .S files
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|ASM_FUNCTION_REMOVE_IF_UNREFERENCED
value|.subsections_via_symbols
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_FUNCTION_REMOVE_IF_UNREFERENCED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__CC_ARM
end_ifdef

begin_comment
comment|//
end_comment

begin_comment
comment|// Older RVCT ARM compilers don't fully support #pragma pack and require __packed
end_comment

begin_comment
comment|// as a prefix for the structure.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|PACKED
value|__packed
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PACKED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|///
end_comment

begin_comment
comment|/// 128 bit buffer containing a unique identifier value.
end_comment

begin_comment
comment|/// Unless otherwise specified, aligned on a 64 bit boundary.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Data1
decl_stmt|;
name|UINT16
name|Data2
decl_stmt|;
name|UINT16
name|Data3
decl_stmt|;
name|UINT8
name|Data4
index|[
literal|8
index|]
decl_stmt|;
block|}
name|GUID
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 4-byte buffer. An IPv4 internet protocol address.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Addr
index|[
literal|4
index|]
decl_stmt|;
block|}
name|IPv4_ADDRESS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// 16-byte buffer. An IPv6 internet protocol address.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Addr
index|[
literal|16
index|]
decl_stmt|;
block|}
name|IPv6_ADDRESS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// 8-bytes unsigned value that represents a physical system address.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|UINT64
name|PHYSICAL_ADDRESS
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// LIST_ENTRY structure definition.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_LIST_ENTRY
name|LIST_ENTRY
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// _LIST_ENTRY structure definition.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_LIST_ENTRY
block|{
name|LIST_ENTRY
modifier|*
name|ForwardLink
decl_stmt|;
name|LIST_ENTRY
modifier|*
name|BackLink
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|//
end_comment

begin_comment
comment|// Modifiers to abstract standard types to aid in debug of problems
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Datum is read-only.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|CONST
value|const
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Datum is scoped to the current file or function.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|STATIC
value|static
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Undeclared type.
end_comment

begin_comment
comment|///
end_comment

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
comment|// Modifiers for Data Types used to self document code.
end_comment

begin_comment
comment|// This concept is borrowed for UEFI specification.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Datum is passed to the function.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IN
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Datum is returned from the function.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|OUT
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Passing the datum to the function is optional, and a NULL
end_comment

begin_comment
comment|/// is passed if the value is not supplied.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|OPTIONAL
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  UEFI specification claims 1 and 0. We are concerned about the
end_comment

begin_comment
comment|//  compiler portability so we did it this way.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Boolean true value.  UEFI Specification defines this value to be 1,
end_comment

begin_comment
comment|/// but this form is more portable.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|TRUE
value|((BOOLEAN)(1==1))
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Boolean false value.  UEFI Specification defines this value to be 0,
end_comment

begin_comment
comment|/// but this form is more portable.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|FALSE
value|((BOOLEAN)(0==1))
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// NULL pointer (VOID *)
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|NULL
value|((VOID *) 0)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Null character
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|CHAR_NULL
value|0x0000
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Maximum values for common UEFI Data Types
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MAX_INT8
value|((INT8)0x7F)
end_define

begin_define
define|#
directive|define
name|MAX_UINT8
value|((UINT8)0xFF)
end_define

begin_define
define|#
directive|define
name|MAX_INT16
value|((INT16)0x7FFF)
end_define

begin_define
define|#
directive|define
name|MAX_UINT16
value|((UINT16)0xFFFF)
end_define

begin_define
define|#
directive|define
name|MAX_INT32
value|((INT32)0x7FFFFFFF)
end_define

begin_define
define|#
directive|define
name|MAX_UINT32
value|((UINT32)0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|MAX_INT64
value|((INT64)0x7FFFFFFFFFFFFFFFULL)
end_define

begin_define
define|#
directive|define
name|MAX_UINT64
value|((UINT64)0xFFFFFFFFFFFFFFFFULL)
end_define

begin_define
define|#
directive|define
name|BIT0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BIT1
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BIT2
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BIT3
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BIT4
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BIT5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BIT6
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BIT7
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BIT8
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BIT9
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BIT10
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BIT11
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BIT12
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BIT13
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BIT14
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BIT15
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BIT16
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BIT17
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BIT18
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BIT19
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BIT20
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BIT21
value|0x00200000
end_define

begin_define
define|#
directive|define
name|BIT22
value|0x00400000
end_define

begin_define
define|#
directive|define
name|BIT23
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BIT24
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BIT25
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BIT26
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BIT27
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BIT28
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BIT29
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BIT30
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BIT31
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BIT32
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|BIT33
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|BIT34
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|BIT35
value|0x0000000800000000ULL
end_define

begin_define
define|#
directive|define
name|BIT36
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT37
value|0x0000002000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT38
value|0x0000004000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT39
value|0x0000008000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT40
value|0x0000010000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT41
value|0x0000020000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT42
value|0x0000040000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT43
value|0x0000080000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT44
value|0x0000100000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT45
value|0x0000200000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT46
value|0x0000400000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT47
value|0x0000800000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT48
value|0x0001000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT49
value|0x0002000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT50
value|0x0004000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT51
value|0x0008000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT52
value|0x0010000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT53
value|0x0020000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT54
value|0x0040000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT55
value|0x0080000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT56
value|0x0100000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT57
value|0x0200000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT58
value|0x0400000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT59
value|0x0800000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT60
value|0x1000000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT61
value|0x2000000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT62
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|BIT63
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_1KB
value|0x00000400
end_define

begin_define
define|#
directive|define
name|SIZE_2KB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|SIZE_4KB
value|0x00001000
end_define

begin_define
define|#
directive|define
name|SIZE_8KB
value|0x00002000
end_define

begin_define
define|#
directive|define
name|SIZE_16KB
value|0x00004000
end_define

begin_define
define|#
directive|define
name|SIZE_32KB
value|0x00008000
end_define

begin_define
define|#
directive|define
name|SIZE_64KB
value|0x00010000
end_define

begin_define
define|#
directive|define
name|SIZE_128KB
value|0x00020000
end_define

begin_define
define|#
directive|define
name|SIZE_256KB
value|0x00040000
end_define

begin_define
define|#
directive|define
name|SIZE_512KB
value|0x00080000
end_define

begin_define
define|#
directive|define
name|SIZE_1MB
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SIZE_2MB
value|0x00200000
end_define

begin_define
define|#
directive|define
name|SIZE_4MB
value|0x00400000
end_define

begin_define
define|#
directive|define
name|SIZE_8MB
value|0x00800000
end_define

begin_define
define|#
directive|define
name|SIZE_16MB
value|0x01000000
end_define

begin_define
define|#
directive|define
name|SIZE_32MB
value|0x02000000
end_define

begin_define
define|#
directive|define
name|SIZE_64MB
value|0x04000000
end_define

begin_define
define|#
directive|define
name|SIZE_128MB
value|0x08000000
end_define

begin_define
define|#
directive|define
name|SIZE_256MB
value|0x10000000
end_define

begin_define
define|#
directive|define
name|SIZE_512MB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SIZE_1GB
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SIZE_2GB
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SIZE_4GB
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_8GB
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_16GB
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_32GB
value|0x0000000800000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_64GB
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_128GB
value|0x0000002000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_256GB
value|0x0000004000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_512GB
value|0x0000008000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_1TB
value|0x0000010000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_2TB
value|0x0000020000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_4TB
value|0x0000040000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_8TB
value|0x0000080000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_16TB
value|0x0000100000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_32TB
value|0x0000200000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_64TB
value|0x0000400000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_128TB
value|0x0000800000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_256TB
value|0x0001000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_512TB
value|0x0002000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_1PB
value|0x0004000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_2PB
value|0x0008000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_4PB
value|0x0010000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_8PB
value|0x0020000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_16PB
value|0x0040000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_32PB
value|0x0080000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_64PB
value|0x0100000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_128PB
value|0x0200000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_256PB
value|0x0400000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_512PB
value|0x0800000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_1EB
value|0x1000000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_2EB
value|0x2000000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_4EB
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|SIZE_8EB
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_1KB
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BASE_2KB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BASE_4KB
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BASE_8KB
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BASE_16KB
value|0x00004000
end_define

begin_define
define|#
directive|define
name|BASE_32KB
value|0x00008000
end_define

begin_define
define|#
directive|define
name|BASE_64KB
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BASE_128KB
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BASE_256KB
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BASE_512KB
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BASE_1MB
value|0x00100000
end_define

begin_define
define|#
directive|define
name|BASE_2MB
value|0x00200000
end_define

begin_define
define|#
directive|define
name|BASE_4MB
value|0x00400000
end_define

begin_define
define|#
directive|define
name|BASE_8MB
value|0x00800000
end_define

begin_define
define|#
directive|define
name|BASE_16MB
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BASE_32MB
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BASE_64MB
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BASE_128MB
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BASE_256MB
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BASE_512MB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|BASE_1GB
value|0x40000000
end_define

begin_define
define|#
directive|define
name|BASE_2GB
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BASE_4GB
value|0x0000000100000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_8GB
value|0x0000000200000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_16GB
value|0x0000000400000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_32GB
value|0x0000000800000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_64GB
value|0x0000001000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_128GB
value|0x0000002000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_256GB
value|0x0000004000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_512GB
value|0x0000008000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_1TB
value|0x0000010000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_2TB
value|0x0000020000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_4TB
value|0x0000040000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_8TB
value|0x0000080000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_16TB
value|0x0000100000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_32TB
value|0x0000200000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_64TB
value|0x0000400000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_128TB
value|0x0000800000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_256TB
value|0x0001000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_512TB
value|0x0002000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_1PB
value|0x0004000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_2PB
value|0x0008000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_4PB
value|0x0010000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_8PB
value|0x0020000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_16PB
value|0x0040000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_32PB
value|0x0080000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_64PB
value|0x0100000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_128PB
value|0x0200000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_256PB
value|0x0400000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_512PB
value|0x0800000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_1EB
value|0x1000000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_2EB
value|0x2000000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_4EB
value|0x4000000000000000ULL
end_define

begin_define
define|#
directive|define
name|BASE_8EB
value|0x8000000000000000ULL
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|//  Support for variable length argument lists using the ANSI standard.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Since we are using the ANSI standard we used the standard naming and
end_comment

begin_comment
comment|//  did not follow the coding convention
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  VA_LIST  - typedef for argument list.
end_comment

begin_comment
comment|//  VA_START (VA_LIST Marker, argument before the ...) - Init Marker for use.
end_comment

begin_comment
comment|//  VA_END (VA_LIST Marker) - Clear Marker
end_comment

begin_comment
comment|//  VA_ARG (VA_LIST Marker, var arg size) - Use Marker to get an argument from
end_comment

begin_comment
comment|//    the ... list. You must know the size and pass it in this macro.
end_comment

begin_comment
comment|//  VA_COPY (VA_LIST Dest, VA_LIST Start) - Initialize Dest as a copy of Start.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  UINTN
end_comment

begin_comment
comment|//  ExampleVarArg (
end_comment

begin_comment
comment|//    IN UINTN  NumberOfArgs,
end_comment

begin_comment
comment|//    ...
end_comment

begin_comment
comment|//    )
end_comment

begin_comment
comment|//  {
end_comment

begin_comment
comment|//    VA_LIST Marker;
end_comment

begin_comment
comment|//    UINTN   Index;
end_comment

begin_comment
comment|//    UINTN   Result;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    //
end_comment

begin_comment
comment|//    // Initialize the Marker
end_comment

begin_comment
comment|//    //
end_comment

begin_comment
comment|//    VA_START (Marker, NumberOfArgs);
end_comment

begin_comment
comment|//    for (Index = 0, Result = 0; Index< NumberOfArgs; Index++) {
end_comment

begin_comment
comment|//      //
end_comment

begin_comment
comment|//      // The ... list is a series of UINTN values, so average them up.
end_comment

begin_comment
comment|//      //
end_comment

begin_comment
comment|//      Result += VA_ARG (Marker, UINTN);
end_comment

begin_comment
comment|//    }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    VA_END (Marker);
end_comment

begin_comment
comment|//    return Result
end_comment

begin_comment
comment|//  }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Return the size of argument that has been aligned to sizeof (UINTN).    @param  n    The parameter size to be aligned.    @return The aligned size. **/
end_comment

begin_define
define|#
directive|define
name|_INT_SIZE_OF
parameter_list|(
name|n
parameter_list|)
value|((sizeof (n) + sizeof (UINTN) - 1)&~(sizeof (UINTN) - 1))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CC_ARM
argument_list|)
end_if

begin_comment
comment|//
end_comment

begin_comment
comment|// RVCT ARM variable argument list support.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Variable used to traverse the list of arguments. This type can vary by
end_comment

begin_comment
comment|/// implementation and could be an array or structure.
end_comment

begin_comment
comment|///
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__APCS_ADSABI
end_ifdef

begin_typedef
typedef|typedef
name|int
modifier|*
name|va_list
index|[
literal|1
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VA_LIST
value|va_list
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
name|__va_list
block|{
name|void
modifier|*
name|__ap
decl_stmt|;
block|}
name|va_list
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VA_LIST
value|va_list
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|Marker
parameter_list|,
name|Parameter
parameter_list|)
value|__va_start(Marker, Parameter)
end_define

begin_define
define|#
directive|define
name|VA_ARG
parameter_list|(
name|Marker
parameter_list|,
name|TYPE
parameter_list|)
value|__va_arg(Marker, TYPE)
end_define

begin_define
define|#
directive|define
name|VA_END
parameter_list|(
name|Marker
parameter_list|)
value|((void)0)
end_define

begin_comment
comment|// For some ARM RVCT compilers, __va_copy is not defined
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__va_copy
end_ifndef

begin_define
define|#
directive|define
name|__va_copy
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|((void)((dest) = (src)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VA_COPY
parameter_list|(
name|Dest
parameter_list|,
name|Start
parameter_list|)
value|__va_copy (Dest, Start)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_X64
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_MSABI_VA_FUNCS
argument_list|)
end_if

begin_comment
comment|//
end_comment

begin_comment
comment|// X64 only. Use MS ABI version of GCC built-in macros for variable argument lists.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Both GCC and LLVM 3.8 for X64 support new variable argument intrinsics for Microsoft ABI
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Variable used to traverse the list of arguments. This type can vary by
end_comment

begin_comment
comment|/// implementation and could be an array or structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|__builtin_ms_va_list
name|VA_LIST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|Marker
parameter_list|,
name|Parameter
parameter_list|)
value|__builtin_ms_va_start (Marker, Parameter)
end_define

begin_define
define|#
directive|define
name|VA_ARG
parameter_list|(
name|Marker
parameter_list|,
name|TYPE
parameter_list|)
value|((sizeof (TYPE)< sizeof (UINTN)) ? (TYPE)(__builtin_va_arg (Marker, UINTN)) : (TYPE)(__builtin_va_arg (Marker, TYPE)))
end_define

begin_define
define|#
directive|define
name|VA_END
parameter_list|(
name|Marker
parameter_list|)
value|__builtin_ms_va_end (Marker)
end_define

begin_define
define|#
directive|define
name|VA_COPY
parameter_list|(
name|Dest
parameter_list|,
name|Start
parameter_list|)
value|__builtin_ms_va_copy (Dest, Start)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|//
end_comment

begin_comment
comment|// Use GCC built-in macros for variable argument lists.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Variable used to traverse the list of arguments. This type can vary by
end_comment

begin_comment
comment|/// implementation and could be an array or structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|__builtin_va_list
name|VA_LIST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|Marker
parameter_list|,
name|Parameter
parameter_list|)
value|__builtin_va_start (Marker, Parameter)
end_define

begin_define
define|#
directive|define
name|VA_ARG
parameter_list|(
name|Marker
parameter_list|,
name|TYPE
parameter_list|)
value|((sizeof (TYPE)< sizeof (UINTN)) ? (TYPE)(__builtin_va_arg (Marker, UINTN)) : (TYPE)(__builtin_va_arg (Marker, TYPE)))
end_define

begin_define
define|#
directive|define
name|VA_END
parameter_list|(
name|Marker
parameter_list|)
value|__builtin_va_end (Marker)
end_define

begin_define
define|#
directive|define
name|VA_COPY
parameter_list|(
name|Dest
parameter_list|,
name|Start
parameter_list|)
value|__builtin_va_copy (Dest, Start)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|///
end_comment

begin_comment
comment|/// Variable used to traverse the list of arguments. This type can vary by
end_comment

begin_comment
comment|/// implementation and could be an array or structure.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|CHAR8
modifier|*
name|VA_LIST
typedef|;
end_typedef

begin_comment
comment|/**   Retrieves a pointer to the beginning of a variable argument list, based on   the name of the parameter that immediately precedes the variable argument list.    This function initializes Marker to point to the beginning of the variable   argument list that immediately follows Parameter.  The method for computing the   pointer to the next argument in the argument list is CPU-specific following the   EFIAPI ABI.    @param   Marker       The VA_LIST used to traverse the list of arguments.   @param   Parameter    The name of the parameter that immediately precedes                         the variable argument list.    @return  A pointer to the beginning of a variable argument list.  **/
end_comment

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|Marker
parameter_list|,
name|Parameter
parameter_list|)
value|(Marker = (VA_LIST) ((UINTN)& (Parameter) + _INT_SIZE_OF (Parameter)))
end_define

begin_comment
comment|/**   Returns an argument of a specified type from a variable argument list and updates   the pointer to the variable argument list to point to the next argument.    This function returns an argument of the type specified by TYPE from the beginning   of the variable argument list specified by Marker.  Marker is then updated to point   to the next argument in the variable argument list.  The method for computing the   pointer to the next argument in the argument list is CPU-specific following the EFIAPI ABI.    @param   Marker   VA_LIST used to traverse the list of arguments.   @param   TYPE     The type of argument to retrieve from the beginning                     of the variable argument list.    @return  An argument of the type specified by TYPE.  **/
end_comment

begin_define
define|#
directive|define
name|VA_ARG
parameter_list|(
name|Marker
parameter_list|,
name|TYPE
parameter_list|)
value|(*(TYPE *) ((Marker += _INT_SIZE_OF (TYPE)) - _INT_SIZE_OF (TYPE)))
end_define

begin_comment
comment|/**   Terminates the use of a variable argument list.    This function initializes Marker so it can no longer be used with VA_ARG().   After this macro is used, the only way to access the variable argument list is   by using VA_START() again.    @param   Marker   VA_LIST used to traverse the list of arguments.  **/
end_comment

begin_define
define|#
directive|define
name|VA_END
parameter_list|(
name|Marker
parameter_list|)
value|(Marker = (VA_LIST) 0)
end_define

begin_comment
comment|/**   Initializes a VA_LIST as a copy of an existing VA_LIST.    This macro initializes Dest as a copy of Start, as if the VA_START macro had been applied to Dest   followed by the same sequence of uses of the VA_ARG macro as had previously been used to reach   the present state of Start.     @param   Dest   VA_LIST used to traverse the list of arguments.   @param   Start  VA_LIST used to traverse the list of arguments.  **/
end_comment

begin_define
define|#
directive|define
name|VA_COPY
parameter_list|(
name|Dest
parameter_list|,
name|Start
parameter_list|)
value|((void)((Dest) = (Start)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|///
end_comment

begin_comment
comment|/// Pointer to the start of a variable argument list stored in a memory buffer. Same as UINT8 *.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINTN
modifier|*
name|BASE_LIST
typedef|;
end_typedef

begin_comment
comment|/**   Returns the size of a data type in sizeof(UINTN) units rounded up to the nearest UINTN boundary.    @param  TYPE  The date type to determine the size of.    @return The size of TYPE in sizeof (UINTN) units rounded up to the nearest UINTN boundary. **/
end_comment

begin_define
define|#
directive|define
name|_BASE_INT_SIZE_OF
parameter_list|(
name|TYPE
parameter_list|)
value|((sizeof (TYPE) + sizeof (UINTN) - 1) / sizeof (UINTN))
end_define

begin_comment
comment|/**   Returns an argument of a specified type from a variable argument list and updates   the pointer to the variable argument list to point to the next argument.    This function returns an argument of the type specified by TYPE from the beginning   of the variable argument list specified by Marker.  Marker is then updated to point   to the next argument in the variable argument list.  The method for computing the   pointer to the next argument in the argument list is CPU specific following the EFIAPI ABI.    @param   Marker   The pointer to the beginning of a variable argument list.   @param   TYPE     The type of argument to retrieve from the beginning                     of the variable argument list.    @return  An argument of the type specified by TYPE.  **/
end_comment

begin_define
define|#
directive|define
name|BASE_ARG
parameter_list|(
name|Marker
parameter_list|,
name|TYPE
parameter_list|)
value|(*(TYPE *) ((Marker += _BASE_INT_SIZE_OF (TYPE)) - _BASE_INT_SIZE_OF (TYPE)))
end_define

begin_comment
comment|/**   The macro that returns the byte offset of a field in a data structure.    This function returns the offset, in bytes, of field specified by Field from the   beginning of the  data structure specified by TYPE. If TYPE does not contain Field,   the module will not compile.    @param   TYPE     The name of the data structure that contains the field specified by Field.   @param   Field    The name of the field in the data structure.    @return  Offset, in bytes, of field.  **/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|4
end_if

begin_define
define|#
directive|define
name|OFFSET_OF
parameter_list|(
name|TYPE
parameter_list|,
name|Field
parameter_list|)
value|((UINTN) __builtin_offsetof(TYPE, Field))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OFFSET_OF
end_ifndef

begin_define
define|#
directive|define
name|OFFSET_OF
parameter_list|(
name|TYPE
parameter_list|,
name|Field
parameter_list|)
value|((UINTN)&(((TYPE *)0)->Field))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Macro that returns a pointer to the data structure that contains a specified field of   that data structure.  This is a lightweight method to hide information by placing a   public data structure inside a larger private data structure and using a pointer to   the public data structure to retrieve a pointer to the private data structure.    This function computes the offset, in bytes, of field specified by Field from the beginning   of the  data structure specified by TYPE.  This offset is subtracted from Record, and is   used to return a pointer to a data structure of the type specified by TYPE. If the data type   specified by TYPE does not contain the field specified by Field, then the module will not compile.    @param   Record   Pointer to the field specified by Field within a data structure of type TYPE.   @param   TYPE     The name of the data structure type to return.  This data structure must                     contain the field specified by Field.   @param   Field    The name of the field in the data structure specified by TYPE to which Record points.    @return  A pointer to the structure from one of it's elements.  **/
end_comment

begin_define
define|#
directive|define
name|BASE_CR
parameter_list|(
name|Record
parameter_list|,
name|TYPE
parameter_list|,
name|Field
parameter_list|)
value|((TYPE *) ((CHAR8 *) (Record) - (CHAR8 *)&(((TYPE *) 0)->Field)))
end_define

begin_comment
comment|/**   Rounds a value up to the next boundary using a specified alignment.    This function rounds Value up to the next boundary using the specified Alignment.   This aligned value is returned.    @param   Value      The value to round up.   @param   Alignment  The alignment boundary used to return the aligned value.    @return  A value up to the next boundary.  **/
end_comment

begin_define
define|#
directive|define
name|ALIGN_VALUE
parameter_list|(
name|Value
parameter_list|,
name|Alignment
parameter_list|)
value|((Value) + (((Alignment) - (Value))& ((Alignment) - 1)))
end_define

begin_comment
comment|/**   Adjust a pointer by adding the minimum offset required for it to be aligned on   a specified alignment boundary.    This function rounds the pointer specified by Pointer to the next alignment boundary   specified by Alignment. The pointer to the aligned address is returned.    @param   Pointer    The pointer to round up.   @param   Alignment  The alignment boundary to use to return an aligned pointer.    @return  Pointer to the aligned address.  **/
end_comment

begin_define
define|#
directive|define
name|ALIGN_POINTER
parameter_list|(
name|Pointer
parameter_list|,
name|Alignment
parameter_list|)
value|((VOID *) (ALIGN_VALUE ((UINTN)(Pointer), (Alignment))))
end_define

begin_comment
comment|/**   Rounds a value up to the next natural boundary for the current CPU.   This is 4-bytes for 32-bit CPUs and 8-bytes for 64-bit CPUs.    This function rounds the value specified by Value up to the next natural boundary for the   current CPU. This rounded value is returned.    @param   Value      The value to round up.    @return  Rounded value specified by Value.  **/
end_comment

begin_define
define|#
directive|define
name|ALIGN_VARIABLE
parameter_list|(
name|Value
parameter_list|)
value|ALIGN_VALUE ((Value), sizeof (UINTN))
end_define

begin_comment
comment|/**   Return the maximum of two operands.    This macro returns the maximum of two operand specified by a and b.   Both a and b must be the same numerical types, signed or unsigned.    @param   a        The first operand with any numerical type.   @param   b        The second operand. Can be any numerical type as long as is                     the same type as a.    @return  Maximum of two operands.  **/
end_comment

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(((a)> (b)) ? (a) : (b))
end_define

begin_comment
comment|/**   Return the minimum of two operands.    This macro returns the minimal of two operand specified by a and b.   Both a and b must be the same numerical types, signed or unsigned.    @param   a        The first operand with any numerical type.   @param   b        The second operand. It should be the same any numerical type with a.    @return  Minimum of two operands.  **/
end_comment

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|(((a)< (b)) ? (a) : (b))
end_define

begin_comment
comment|/**   Return the absolute value of a signed operand.    This macro returns the absolute value of the signed operand specified by a.    @param   a        The signed operand.    @return  The absolute value of the signed operand.  **/
end_comment

begin_define
define|#
directive|define
name|ABS
parameter_list|(
name|a
parameter_list|)
define|\
value|(((a)< 0) ? (-(a)) : (a))
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Status codes common to all execution phases
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|UINTN
name|RETURN_STATUS
typedef|;
end_typedef

begin_comment
comment|/**   Produces a RETURN_STATUS code with the highest bit set.    @param  StatusCode    The status code value to convert into a warning code.                         StatusCode must be in the range 0x00000000..0x7FFFFFFF.    @return The value specified by StatusCode with the highest bit set.  **/
end_comment

begin_define
define|#
directive|define
name|ENCODE_ERROR
parameter_list|(
name|StatusCode
parameter_list|)
value|((RETURN_STATUS)(MAX_BIT | (StatusCode)))
end_define

begin_comment
comment|/**   Produces a RETURN_STATUS code with the highest bit clear.    @param  StatusCode    The status code value to convert into a warning code.                         StatusCode must be in the range 0x00000000..0x7FFFFFFF.    @return The value specified by StatusCode with the highest bit clear.  **/
end_comment

begin_define
define|#
directive|define
name|ENCODE_WARNING
parameter_list|(
name|StatusCode
parameter_list|)
value|((RETURN_STATUS)(StatusCode))
end_define

begin_comment
comment|/**   Returns TRUE if a specified RETURN_STATUS code is an error code.    This function returns TRUE if StatusCode has the high bit set.  Otherwise, FALSE is returned.    @param  StatusCode    The status code value to evaluate.    @retval TRUE          The high bit of StatusCode is set.   @retval FALSE         The high bit of StatusCode is clear.  **/
end_comment

begin_define
define|#
directive|define
name|RETURN_ERROR
parameter_list|(
name|StatusCode
parameter_list|)
value|(((INTN)(RETURN_STATUS)(StatusCode))< 0)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The operation completed successfully.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_SUCCESS
value|0
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The image failed to load.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_LOAD_ERROR
value|ENCODE_ERROR (1)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The parameter was incorrect.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_INVALID_PARAMETER
value|ENCODE_ERROR (2)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The operation is not supported.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_UNSUPPORTED
value|ENCODE_ERROR (3)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The buffer was not the proper size for the request.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_BAD_BUFFER_SIZE
value|ENCODE_ERROR (4)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The buffer was not large enough to hold the requested data.
end_comment

begin_comment
comment|/// The required buffer size is returned in the appropriate
end_comment

begin_comment
comment|/// parameter when this error occurs.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_BUFFER_TOO_SMALL
value|ENCODE_ERROR (5)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// There is no data pending upon return.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_NOT_READY
value|ENCODE_ERROR (6)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The physical device reported an error while attempting the
end_comment

begin_comment
comment|/// operation.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_DEVICE_ERROR
value|ENCODE_ERROR (7)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The device can not be written to.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_WRITE_PROTECTED
value|ENCODE_ERROR (8)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The resource has run out.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_OUT_OF_RESOURCES
value|ENCODE_ERROR (9)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// An inconsistency was detected on the file system causing the
end_comment

begin_comment
comment|/// operation to fail.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_VOLUME_CORRUPTED
value|ENCODE_ERROR (10)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// There is no more space on the file system.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_VOLUME_FULL
value|ENCODE_ERROR (11)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The device does not contain any medium to perform the
end_comment

begin_comment
comment|/// operation.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_NO_MEDIA
value|ENCODE_ERROR (12)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The medium in the device has changed since the last
end_comment

begin_comment
comment|/// access.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_MEDIA_CHANGED
value|ENCODE_ERROR (13)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The item was not found.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_NOT_FOUND
value|ENCODE_ERROR (14)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Access was denied.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_ACCESS_DENIED
value|ENCODE_ERROR (15)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The server was not found or did not respond to the request.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_NO_RESPONSE
value|ENCODE_ERROR (16)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A mapping to the device does not exist.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_NO_MAPPING
value|ENCODE_ERROR (17)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A timeout time expired.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_TIMEOUT
value|ENCODE_ERROR (18)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The protocol has not been started.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_NOT_STARTED
value|ENCODE_ERROR (19)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The protocol has already been started.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_ALREADY_STARTED
value|ENCODE_ERROR (20)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The operation was aborted.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_ABORTED
value|ENCODE_ERROR (21)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// An ICMP error occurred during the network operation.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_ICMP_ERROR
value|ENCODE_ERROR (22)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A TFTP error occurred during the network operation.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_TFTP_ERROR
value|ENCODE_ERROR (23)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A protocol error occurred during the network operation.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_PROTOCOL_ERROR
value|ENCODE_ERROR (24)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A function encountered an internal version that was
end_comment

begin_comment
comment|/// incompatible with a version requested by the caller.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_INCOMPATIBLE_VERSION
value|ENCODE_ERROR (25)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The function was not performed due to a security violation.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_SECURITY_VIOLATION
value|ENCODE_ERROR (26)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A CRC error was detected.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_CRC_ERROR
value|ENCODE_ERROR (27)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The beginning or end of media was reached.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_END_OF_MEDIA
value|ENCODE_ERROR (28)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The end of the file was reached.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_END_OF_FILE
value|ENCODE_ERROR (31)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The language specified was invalid.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_INVALID_LANGUAGE
value|ENCODE_ERROR (32)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The security status of the data is unknown or compromised
end_comment

begin_comment
comment|/// and the data must be updated or replaced to restore a valid
end_comment

begin_comment
comment|/// security status.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_COMPROMISED_DATA
value|ENCODE_ERROR (33)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A HTTP error occurred during the network operation.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_HTTP_ERROR
value|ENCODE_ERROR (35)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The string contained one or more characters that
end_comment

begin_comment
comment|/// the device could not render and were skipped.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_WARN_UNKNOWN_GLYPH
value|ENCODE_WARNING (1)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The handle was closed, but the file was not deleted.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_WARN_DELETE_FAILURE
value|ENCODE_WARNING (2)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The handle was closed, but the data to the file was not
end_comment

begin_comment
comment|/// flushed properly.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_WARN_WRITE_FAILURE
value|ENCODE_WARNING (3)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The resulting buffer was too small, and the data was
end_comment

begin_comment
comment|/// truncated to the buffer size.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_WARN_BUFFER_TOO_SMALL
value|ENCODE_WARNING (4)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The data has not been updated within the timeframe set by
end_comment

begin_comment
comment|/// local policy for this type of data.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_WARN_STALE_DATA
value|ENCODE_WARNING (5)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The resulting buffer contains UEFI-compliant file system.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|RETURN_WARN_FILE_SYSTEM
value|ENCODE_WARNING (6)
end_define

begin_comment
comment|/**   Returns a 16-bit signature built from 2 ASCII characters.    This macro returns a 16-bit value built from the two ASCII characters specified   by A and B.    @param  A    The first ASCII character.   @param  B    The second ASCII character.    @return A 16-bit value built from the two ASCII characters specified by A and B.  **/
end_comment

begin_define
define|#
directive|define
name|SIGNATURE_16
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|((A) | (B<< 8))
end_define

begin_comment
comment|/**   Returns a 32-bit signature built from 4 ASCII characters.    This macro returns a 32-bit value built from the four ASCII characters specified   by A, B, C, and D.    @param  A    The first ASCII character.   @param  B    The second ASCII character.   @param  C    The third ASCII character.   @param  D    The fourth ASCII character.    @return A 32-bit value built from the two ASCII characters specified by A, B,           C and D.  **/
end_comment

begin_define
define|#
directive|define
name|SIGNATURE_32
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|)
value|(SIGNATURE_16 (A, B) | (SIGNATURE_16 (C, D)<< 16))
end_define

begin_comment
comment|/**   Returns a 64-bit signature built from 8 ASCII characters.    This macro returns a 64-bit value built from the eight ASCII characters specified   by A, B, C, D, E, F, G,and H.    @param  A    The first ASCII character.   @param  B    The second ASCII character.   @param  C    The third ASCII character.   @param  D    The fourth ASCII character.   @param  E    The fifth ASCII character.   @param  F    The sixth ASCII character.   @param  G    The seventh ASCII character.   @param  H    The eighth ASCII character.    @return A 64-bit value built from the two ASCII characters specified by A, B,           C, D, E, F, G and H.  **/
end_comment

begin_define
define|#
directive|define
name|SIGNATURE_64
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
define|\
value|(SIGNATURE_32 (A, B, C, D) | ((UINT64) (SIGNATURE_32 (E, F, G, H))<< 32))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_EXTENSIONS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MDE_CPU_EBC
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_ReturnAddress
name|)
end_pragma

begin_comment
comment|/**     Get the return address of the calling function.      Based on intrinsic function _ReturnAddress that provides the address of     the instruction in the calling function that will be executed after     control returns to the caller.      @param L    Return Level.      @return The return address of the calling function or 0 if L != 0.    **/
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDRESS
parameter_list|(
name|L
parameter_list|)
value|((L == 0) ? _ReturnAddress() : (VOID *) 0)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_elif

begin_function_decl
name|void
modifier|*
name|__builtin_return_address
parameter_list|(
name|unsigned
name|int
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**     Get the return address of the calling function.      Based on built-in Function __builtin_return_address that returns     the return address of the current function, or of one of its callers.      @param L    Return Level.      @return The return address of the calling function.    **/
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDRESS
parameter_list|(
name|L
parameter_list|)
value|__builtin_return_address (L)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/**     Get the return address of the calling function.      @param L    Return Level.      @return 0 as compilers don't support this feature.    **/
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDRESS
parameter_list|(
name|L
parameter_list|)
value|((VOID *) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Return the number of elements in an array.    @param  Array  An object of array type. Array is only used as an argument to                  the sizeof operator, therefore Array is never evaluated. The                  caller is responsible for ensuring that Array's type is not                  incomplete; that is, Array must have known constant size.    @return The number of elements in Array. The result has type UINTN.  **/
end_comment

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|Array
parameter_list|)
value|(sizeof (Array) / sizeof ((Array)[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

