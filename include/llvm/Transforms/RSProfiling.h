begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RSProfiling.cpp - Various profiling using random sampling ----------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                      The LLVM Compiler Infrastructure
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
comment|// This file defines the abstract interface that a profiler must implement to
end_comment

begin_comment
comment|// support the random profiling transform.
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
name|LLVM_TRANSFORMS_RSPROFILING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_RSPROFILING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|/// RSProfilers - The basic Random Sampling Profiler Interface  Any profiler
comment|/// that implements this interface can be transformed by the random sampling
comment|/// pass to be sample based rather than always on.
comment|///
comment|/// The only exposed function can be queried to find out if an instruction
comment|/// was original or if it was inserted by the profiler.  Implementations of
comment|/// this interface are expected to chain to other implementations, such that
comment|/// multiple profilers can be support simultaniously.
name|struct
name|RSProfilers
range|:
name|public
name|ModulePass
block|{
specifier|static
name|char
name|ID
block|;
comment|// Pass identification, replacement for typeinfo
name|RSProfilers
argument_list|()
operator|:
name|ModulePass
argument_list|(
argument|&ID
argument_list|)
block|{}
comment|/// isProfiling - This method returns true if the value passed it was
comment|/// inserted by the profiler.
name|virtual
name|bool
name|isProfiling
argument_list|(
name|Value
operator|*
name|v
argument_list|)
operator|=
literal|0
block|;   }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

