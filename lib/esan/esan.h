begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- esan.h --------------------------------------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is a part of EfficiencySanitizer, a family of performance tuners.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Main internal esan header file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Ground rules:
end_comment

begin_comment
comment|//   - C++ run-time should not be used (static CTORs, RTTI, exceptions, static
end_comment

begin_comment
comment|//     function-scope locals)
end_comment

begin_comment
comment|//   - All functions/classes/etc reside in namespace __esan, except for those
end_comment

begin_comment
comment|//     declared in esan_interface_internal.h.
end_comment

begin_comment
comment|//   - Platform-specific files should be used instead of ifdefs (*).
end_comment

begin_comment
comment|//   - No system headers included in header files (*).
end_comment

begin_comment
comment|//   - Platform specific headers included only into platform-specific files (*).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  (*) Except when inlining is critical for performance.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ESAN_H
end_ifndef

begin_define
define|#
directive|define
name|ESAN_H
end_define

begin_include
include|#
directive|include
file|"interception/interception.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"esan_interface_internal.h"
end_include

begin_decl_stmt
name|namespace
name|__esan
block|{
specifier|extern
name|bool
name|EsanIsInitialized
decl_stmt|;
specifier|extern
name|bool
name|EsanDuringInit
decl_stmt|;
specifier|extern
name|uptr
name|VmaSize
decl_stmt|;
name|void
name|initializeLibrary
parameter_list|(
name|ToolType
name|Tool
parameter_list|)
function_decl|;
name|int
name|finalizeLibrary
parameter_list|()
function_decl|;
name|void
name|reportResults
parameter_list|()
function_decl|;
name|unsigned
name|int
name|getSampleCount
parameter_list|()
function_decl|;
comment|// Esan creates the variable per tool per compilation unit at compile time
comment|// and passes its pointer Ptr to the runtime library.
name|void
name|processCompilationUnitInit
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
function_decl|;
name|void
name|processCompilationUnitExit
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
function_decl|;
name|void
name|processRangeAccess
parameter_list|(
name|uptr
name|PC
parameter_list|,
name|uptr
name|Addr
parameter_list|,
name|int
name|Size
parameter_list|,
name|bool
name|IsWrite
parameter_list|)
function_decl|;
name|void
name|initializeInterceptors
parameter_list|()
function_decl|;
comment|// Platform-dependent routines.
name|void
name|verifyAddressSpace
parameter_list|()
function_decl|;
name|bool
name|fixMmapAddr
parameter_list|(
name|void
modifier|*
modifier|*
name|Addr
parameter_list|,
name|SIZE_T
name|Size
parameter_list|,
name|int
name|Flags
parameter_list|)
function_decl|;
name|uptr
name|checkMmapResult
parameter_list|(
name|uptr
name|Addr
parameter_list|,
name|SIZE_T
name|Size
parameter_list|)
function_decl|;
comment|// The return value indicates whether to call the real version or not.
name|bool
name|processSignal
parameter_list|(
name|int
name|SigNum
parameter_list|,
name|void
function_decl|(
modifier|*
name|Handler
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|,
name|void
function_decl|(
modifier|*
modifier|*
name|Result
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
name|bool
name|processSigaction
parameter_list|(
name|int
name|SigNum
parameter_list|,
specifier|const
name|void
modifier|*
name|Act
parameter_list|,
name|void
modifier|*
name|OldAct
parameter_list|)
function_decl|;
name|bool
name|processSigprocmask
parameter_list|(
name|int
name|How
parameter_list|,
name|void
modifier|*
name|Set
parameter_list|,
name|void
modifier|*
name|OldSet
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __esan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ESAN_H
end_comment

end_unit

