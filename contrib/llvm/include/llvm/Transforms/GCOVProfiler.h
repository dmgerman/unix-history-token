begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Transforms/GCOVProfiler.h - GCOVProfiler pass  ----------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// This file provides the interface for the GCOV style profiler  pass.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_GCOVPROFILER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_GCOVPROFILER_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/Instrumentation.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// The gcov-style instrumentation pass
name|class
name|GCOVProfilerPass
range|:
name|public
name|PassInfoMixin
operator|<
name|GCOVProfilerPass
operator|>
block|{
name|public
operator|:
name|GCOVProfilerPass
argument_list|(
specifier|const
name|GCOVOptions
operator|&
name|Options
operator|=
name|GCOVOptions
operator|::
name|getDefault
argument_list|()
argument_list|)
operator|:
name|GCOVOpts
argument_list|(
argument|Options
argument_list|)
block|{ }
name|PreservedAnalyses
name|run
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|ModuleAnalysisManager
operator|&
name|AM
argument_list|)
block|;
name|private
operator|:
name|GCOVOptions
name|GCOVOpts
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

