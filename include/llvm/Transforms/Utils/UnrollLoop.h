begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/Utils/UnrollLoop.h - Unrolling utilities -*- C++ -*-===//
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
comment|// This file defines some loop unrolling utilities. It does not define any
end_comment

begin_comment
comment|// actual pass or policy, but provides a single function to perform loop
end_comment

begin_comment
comment|// unrolling.
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
name|LLVM_TRANSFORMS_UTILS_UNROLLLOOP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_UNROLLLOOP_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
name|class
name|LPPassManager
decl_stmt|;
name|bool
name|UnrollLoop
parameter_list|(
name|Loop
modifier|*
name|L
parameter_list|,
name|unsigned
name|Count
parameter_list|,
name|LoopInfo
modifier|*
name|LI
parameter_list|,
name|LPPassManager
modifier|*
name|LPM
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

