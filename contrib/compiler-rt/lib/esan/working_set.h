begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- working_set.h -------------------------------------------*- C++ -*-===//
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
comment|// Header for working-set-specific code.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WORKING_SET_H
end_ifndef

begin_define
define|#
directive|define
name|WORKING_SET_H
end_define

begin_include
include|#
directive|include
file|"interception/interception.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_internal_defs.h"
end_include

begin_decl_stmt
name|namespace
name|__esan
block|{
name|void
name|initializeWorkingSet
parameter_list|()
function_decl|;
name|void
name|initializeShadowWorkingSet
parameter_list|()
function_decl|;
name|int
name|finalizeWorkingSet
parameter_list|()
function_decl|;
name|void
name|reportWorkingSet
parameter_list|()
function_decl|;
name|unsigned
name|int
name|getSampleCountWorkingSet
parameter_list|()
function_decl|;
name|void
name|processRangeAccessWorkingSet
parameter_list|(
name|uptr
name|PC
parameter_list|,
name|uptr
name|Addr
parameter_list|,
name|SIZE_T
name|Size
parameter_list|,
name|bool
name|IsWrite
parameter_list|)
function_decl|;
comment|// Platform-dependent.
name|void
name|registerMemoryFaultHandler
parameter_list|()
function_decl|;
name|bool
name|processWorkingSetSignal
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
name|processWorkingSetSigaction
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
name|processWorkingSetSigprocmask
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
comment|// WORKING_SET_H
end_comment

end_unit

