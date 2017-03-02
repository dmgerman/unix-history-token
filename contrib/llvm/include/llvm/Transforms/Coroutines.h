begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Coroutines.h - Coroutine Transformations ----------------*- C++ -*-===//
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
comment|// Declare accessor functions for coroutine lowering passes.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_COROUTINES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_COROUTINES_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Pass
decl_stmt|;
name|class
name|PassManagerBuilder
decl_stmt|;
comment|/// Add all coroutine passes to appropriate extension points.
name|void
name|addCoroutinePassesToExtensionPoints
parameter_list|(
name|PassManagerBuilder
modifier|&
name|Builder
parameter_list|)
function_decl|;
comment|/// Lower coroutine intrinsics that are not needed by later passes.
name|Pass
modifier|*
name|createCoroEarlyPass
parameter_list|()
function_decl|;
comment|/// Split up coroutines into multiple functions driving their state machines.
name|Pass
modifier|*
name|createCoroSplitPass
parameter_list|()
function_decl|;
comment|/// Analyze coroutines use sites, devirtualize resume/destroy calls and elide
comment|/// heap allocation for coroutine frame where possible.
name|Pass
modifier|*
name|createCoroElidePass
parameter_list|()
function_decl|;
comment|/// Lower all remaining coroutine intrinsics.
name|Pass
modifier|*
name|createCoroCleanupPass
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

