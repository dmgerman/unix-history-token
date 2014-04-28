begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-defines.h ------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_lldb_defines_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_lldb_defines_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|UINT32_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|UINT32_MAX
value|4294967295U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|UINT64_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|UINT64_MAX
value|18446744073709551615ULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// LLDB version
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A build script phase can modify this version number if needed.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|//#define LLDB_VERSION
end_comment

begin_comment
comment|//#define LLDB_REVISION
end_comment

begin_comment
comment|//#define LLDB_VERSION_STRING
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// LLDB defines
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|LLDB_GENERIC_ERROR
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|LLDB_DEFAULT_SHELL
value|"/bin/sh"
end_define

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Breakpoints
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|LLDB_INVALID_BREAK_ID
value|0
end_define

begin_define
define|#
directive|define
name|LLDB_DEFAULT_BREAK_SIZE
value|0
end_define

begin_define
define|#
directive|define
name|LLDB_BREAK_ID_IS_VALID
parameter_list|(
name|bid
parameter_list|)
value|((bid) != (LLDB_INVALID_BREAK_ID))
end_define

begin_define
define|#
directive|define
name|LLDB_BREAK_ID_IS_INTERNAL
parameter_list|(
name|bid
parameter_list|)
value|((bid)< 0)
end_define

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Watchpoints
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|LLDB_INVALID_WATCH_ID
value|0
end_define

begin_define
define|#
directive|define
name|LLDB_WATCH_ID_IS_VALID
parameter_list|(
name|uid
parameter_list|)
value|((uid) != (LLDB_INVALID_WATCH_ID))
end_define

begin_define
define|#
directive|define
name|LLDB_WATCH_TYPE_READ
value|(1u<< 0)
end_define

begin_define
define|#
directive|define
name|LLDB_WATCH_TYPE_WRITE
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|LLDB_WATCH_TYPE_IS_VALID
parameter_list|(
name|type
parameter_list|)
value|((type | LLDB_WATCH_TYPE_READ) || (type | LLDB_WATCH_TYPE_WRITE))
end_define

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Generic Register Numbers
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_PC
value|0
end_define

begin_comment
comment|// Program Counter
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_SP
value|1
end_define

begin_comment
comment|// Stack Pointer
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_FP
value|2
end_define

begin_comment
comment|// Frame Pointer
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_RA
value|3
end_define

begin_comment
comment|// Return Address
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_FLAGS
value|4
end_define

begin_comment
comment|// Processor flags register
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_ARG1
value|5
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 1 (if any)
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_ARG2
value|6
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 2 (if any)
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_ARG3
value|7
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 3 (if any)
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_ARG4
value|8
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 4 (if any)
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_ARG5
value|9
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 5 (if any)
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_ARG6
value|10
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 6 (if any)
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_ARG7
value|11
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 7 (if any)
end_comment

begin_define
define|#
directive|define
name|LLDB_REGNUM_GENERIC_ARG8
value|12
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 8 (if any)
end_comment

begin_comment
comment|//---------------------------------------------------------------------
end_comment

begin_comment
comment|/// Invalid value definitions
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|LLDB_INVALID_ADDRESS
value|UINT64_MAX
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_INDEX32
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_IVAR_OFFSET
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_IMAGE_TOKEN
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_REGNUM
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_UID
value|UINT64_MAX
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_PROCESS_ID
value|0
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_THREAD_ID
value|0
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_FRAME_ID
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_SIGNAL_NUMBER
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_OFFSET
value|UINT64_MAX
end_define

begin_comment
comment|// Must match max of lldb::offset_t
end_comment

begin_define
define|#
directive|define
name|LLDB_INVALID_LINE_NUMBER
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_QUEUE_ID
value|0
end_define

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// CPU Type defintions
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|LLDB_ARCH_DEFAULT
value|"systemArch"
end_define

begin_define
define|#
directive|define
name|LLDB_ARCH_DEFAULT_32BIT
value|"systemArch32"
end_define

begin_define
define|#
directive|define
name|LLDB_ARCH_DEFAULT_64BIT
value|"systemArch64"
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_CPUTYPE
value|(0xFFFFFFFEu)
end_define

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// Option Set defintions
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// FIXME: I'm sure there's some #define magic that can create all 32 sets on the
end_comment

begin_comment
comment|// fly.  That would have the added benefit of making this unreadable.
end_comment

begin_define
define|#
directive|define
name|LLDB_MAX_NUM_OPTION_SETS
value|32
end_define

begin_define
define|#
directive|define
name|LLDB_OPT_SET_ALL
value|0xFFFFFFFFU
end_define

begin_define
define|#
directive|define
name|LLDB_OPT_SET_1
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|LLDB_OPT_SET_2
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|LLDB_OPT_SET_3
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|LLDB_OPT_SET_4
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|LLDB_OPT_SET_5
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|LLDB_OPT_SET_6
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|LLDB_OPT_SET_7
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|LLDB_OPT_SET_8
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|LLDB_OPT_SET_9
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|LLDB_OPT_SET_10
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|LLDB_OPT_SET_FROM_TO
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|(((1U<< (B)) - 1) ^ (((1U<< (A))-1)>> 1))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_define
define|#
directive|define
name|MAX_PATH
value|260
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_comment
comment|// ignore GCC function attributes
end_comment

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|X
parameter_list|)
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
name|__cplusplus
argument_list|)
end_if

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// @def DISALLOW_COPY_AND_ASSIGN(TypeName)
end_comment

begin_comment
comment|///     Macro definition for easily disallowing copy constructor and
end_comment

begin_comment
comment|///     assignment operators in C++ classes.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_define
define|#
directive|define
name|DISALLOW_COPY_AND_ASSIGN
parameter_list|(
name|TypeName
parameter_list|)
define|\
value|TypeName(const TypeName&); \     const TypeName& operator=(const TypeName&)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_lldb_defines_h_
end_comment

end_unit

