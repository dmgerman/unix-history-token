begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Processor or compiler specific defines and types for EBC.    We currently only have one EBC compiler so there may be some Intel compiler   specific functions in this file.  Copyright (c) 2006 - 2013, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
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
name|MDE_CPU_EBC
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Native integer types
end_comment

begin_comment
comment|//
end_comment

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
comment|/// Signed value of native width.  (4 bytes on supported 32-bit processor instructions,
end_comment

begin_comment
comment|/// 8 bytes on supported 64-bit processor instructions)
end_comment

begin_comment
comment|/// "long" type scales to the processor native size with EBC compiler
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|long
name|INTN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The unsigned value of native width.  (4 bytes on supported 32-bit processor instructions;
end_comment

begin_comment
comment|/// 8 bytes on supported 64-bit processor instructions)
end_comment

begin_comment
comment|/// "long" type scales to the processor native size with the EBC compiler.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|UINTN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A value of native width with the highest bit set.
end_comment

begin_comment
comment|/// Scalable macro to set the most significant bit in a natural number.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MAX_BIT
value|(1ULL<< (sizeof (INTN) * 8 - 1))
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// A value of native width with the two highest bits set.
end_comment

begin_comment
comment|/// Scalable macro to set the most 2 significant bits in a natural number.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MAX_2_BITS
value|(3ULL<< (sizeof (INTN) * 8 - 2))
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Maximum legal EBC address
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MAX_ADDRESS
value|((UINTN) ~0)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Maximum legal EBC INTN and UINTN values.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|MAX_UINTN
value|((UINTN) ~0)
end_define

begin_define
define|#
directive|define
name|MAX_INTN
value|((INTN)~MAX_BIT)
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The stack alignment required for EBC
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
comment|/// Page allocation granularity for EBC
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
comment|///
end_comment

begin_comment
comment|/// Modifier to ensure that all protocol member functions and EFI intrinsics
end_comment

begin_comment
comment|/// use the correct C calling convention. All protocol member functions and
end_comment

begin_comment
comment|/// EFI intrinsics are required to modify their member functions with EFIAPI.
end_comment

begin_comment
comment|///
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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EFIAPI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Return the pointer to the first instruction of a function given a function pointer.   On EBC architectures, these two pointer values are the same,    so the implementation of this macro is very simple.      @param  FunctionPointer   A pointer to a function.    @return The pointer to the first instruction of a function given a function pointer. **/
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

