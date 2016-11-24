begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- esan_sideline.h -----------------------------------------*- C++ -*-===//
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
comment|// Esan sideline thread support.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ESAN_SIDELINE_H
end_ifndef

begin_define
define|#
directive|define
name|ESAN_SIDELINE_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_common/sanitizer_atomic.h"
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
typedef|typedef
name|void
function_decl|(
modifier|*
name|SidelineFunc
function_decl|)
parameter_list|(
name|void
modifier|*
name|Arg
parameter_list|)
function_decl|;
comment|// Currently only one sideline thread is supported.
comment|// It calls the SidelineFunc passed to launchThread once on each sample at the
comment|// given frequency in real time (i.e., wall clock time).
name|class
name|SidelineThread
block|{
name|public
label|:
comment|// We cannot initialize any fields in the constructor as it will be called
comment|// *after* launchThread for a static instance, as esan.module_ctor is called
comment|// before static initializers.
name|SidelineThread
argument_list|()
block|{}
operator|~
name|SidelineThread
argument_list|()
block|{}
comment|// To simplify declaration in sanitizer code where we want to avoid
comment|// heap allocations, the constructor and destructor do nothing and
comment|// launchThread and joinThread do the real work.
comment|// They should each be called just once.
name|bool
name|launchThread
argument_list|(
argument|SidelineFunc takeSample
argument_list|,
argument|void *Arg
argument_list|,
argument|u32 FreqMilliSec
argument_list|)
expr_stmt|;
name|bool
name|joinThread
parameter_list|()
function_decl|;
comment|// Must be called from the sideline thread itself.
name|bool
name|adjustTimer
parameter_list|(
name|u32
name|FreqMilliSec
parameter_list|)
function_decl|;
name|private
label|:
specifier|static
name|int
name|runSideline
parameter_list|(
name|void
modifier|*
name|Arg
parameter_list|)
function_decl|;
specifier|static
name|void
name|registerSignal
parameter_list|(
name|int
name|SigNum
parameter_list|)
function_decl|;
specifier|static
name|void
name|handleSidelineSignal
parameter_list|(
name|int
name|SigNum
parameter_list|,
name|void
modifier|*
name|SigInfo
parameter_list|,
name|void
modifier|*
name|Ctx
parameter_list|)
function_decl|;
name|char
modifier|*
name|Stack
decl_stmt|;
name|SidelineFunc
name|sampleFunc
decl_stmt|;
name|void
modifier|*
name|FuncArg
decl_stmt|;
name|u32
name|Freq
decl_stmt|;
name|uptr
name|SidelineId
decl_stmt|;
name|atomic_uintptr_t
name|SidelineExit
decl_stmt|;
block|}
empty_stmt|;
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
comment|// ESAN_SIDELINE_H
end_comment

end_unit

