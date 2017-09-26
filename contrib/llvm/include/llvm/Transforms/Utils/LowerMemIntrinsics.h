begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Transforms/Utils/LowerMemintrinsics.h ---------------*- C++ -*-===//
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
comment|// Lower memset, memcpy, memmov intrinsics to loops (e.g. for targets without
end_comment

begin_comment
comment|// library support).
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
name|LLVM_TRANSFORMS_UTILS_LOWERMEMINTRINSICS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_LOWERMEMINTRINSICS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ConstantInt
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|MemCpyInst
decl_stmt|;
name|class
name|MemMoveInst
decl_stmt|;
name|class
name|MemSetInst
decl_stmt|;
name|class
name|TargetTransformInfo
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// Emit a loop implementing the semantics of llvm.memcpy with the equivalent
comment|/// arguments at \p InsertBefore.
name|void
name|createMemCpyLoop
parameter_list|(
name|Instruction
modifier|*
name|InsertBefore
parameter_list|,
name|Value
modifier|*
name|SrcAddr
parameter_list|,
name|Value
modifier|*
name|DstAddr
parameter_list|,
name|Value
modifier|*
name|CopyLen
parameter_list|,
name|unsigned
name|SrcAlign
parameter_list|,
name|unsigned
name|DestAlign
parameter_list|,
name|bool
name|SrcIsVolatile
parameter_list|,
name|bool
name|DstIsVolatile
parameter_list|)
function_decl|;
comment|/// Emit a loop implementing the semantics of llvm.memcpy where the size is not
comment|/// a compile-time constant. Loop will be insterted at \p InsertBefore.
name|void
name|createMemCpyLoopUnknownSize
parameter_list|(
name|Instruction
modifier|*
name|InsertBefore
parameter_list|,
name|Value
modifier|*
name|SrcAddr
parameter_list|,
name|Value
modifier|*
name|DstAddr
parameter_list|,
name|Value
modifier|*
name|CopyLen
parameter_list|,
name|unsigned
name|SrcAlign
parameter_list|,
name|unsigned
name|DestAlign
parameter_list|,
name|bool
name|SrcIsVolatile
parameter_list|,
name|bool
name|DstIsVolatile
parameter_list|,
specifier|const
name|TargetTransformInfo
modifier|&
name|TTI
parameter_list|)
function_decl|;
comment|/// Emit a loop implementing the semantics of an llvm.memcpy whose size is a
comment|/// compile time constant. Loop is inserted at \p InsertBefore.
name|void
name|createMemCpyLoopKnownSize
parameter_list|(
name|Instruction
modifier|*
name|InsertBefore
parameter_list|,
name|Value
modifier|*
name|SrcAddr
parameter_list|,
name|Value
modifier|*
name|DstAddr
parameter_list|,
name|ConstantInt
modifier|*
name|CopyLen
parameter_list|,
name|unsigned
name|SrcAlign
parameter_list|,
name|unsigned
name|DestAlign
parameter_list|,
name|bool
name|SrcIsVolatile
parameter_list|,
name|bool
name|DstIsVolatile
parameter_list|,
specifier|const
name|TargetTransformInfo
modifier|&
name|TTI
parameter_list|)
function_decl|;
comment|/// Expand \p MemCpy as a loop. \p MemCpy is not deleted.
name|void
name|expandMemCpyAsLoop
parameter_list|(
name|MemCpyInst
modifier|*
name|MemCpy
parameter_list|,
specifier|const
name|TargetTransformInfo
modifier|&
name|TTI
parameter_list|)
function_decl|;
comment|/// Expand \p MemMove as a loop. \p MemMove is not deleted.
name|void
name|expandMemMoveAsLoop
parameter_list|(
name|MemMoveInst
modifier|*
name|MemMove
parameter_list|)
function_decl|;
comment|/// Expand \p MemSet as a loop. \p MemSet is not deleted.
name|void
name|expandMemSetAsLoop
parameter_list|(
name|MemSetInst
modifier|*
name|MemSet
parameter_list|)
function_decl|;
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

