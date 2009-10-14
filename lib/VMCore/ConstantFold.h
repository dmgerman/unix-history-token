begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ConstantFolding.h - Internal Constant Folding Interface -*- C++ -*-===//
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
comment|// This file defines the (internal) constant folding interfaces for LLVM.  These
end_comment

begin_comment
comment|// interfaces are used by the ConstantExpr::get* methods to automatically fold
end_comment

begin_comment
comment|// constants when possible.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// These operators may return a null object if they don't know how to perform
end_comment

begin_comment
comment|// the specified operation on the specified constant types.
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
name|CONSTANTFOLDING_H
end_ifndef

begin_define
define|#
directive|define
name|CONSTANTFOLDING_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
comment|// Constant fold various types of instruction...
name|Constant
modifier|*
name|ConstantFoldCastInstruction
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|unsigned
name|opcode
parameter_list|,
comment|///< The opcode of the cast
name|Constant
modifier|*
name|V
parameter_list|,
comment|///< The source constant
specifier|const
name|Type
modifier|*
name|DestTy
comment|///< The destination type
parameter_list|)
function_decl|;
name|Constant
modifier|*
name|ConstantFoldSelectInstruction
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|Constant
modifier|*
name|Cond
parameter_list|,
name|Constant
modifier|*
name|V1
parameter_list|,
name|Constant
modifier|*
name|V2
parameter_list|)
function_decl|;
name|Constant
modifier|*
name|ConstantFoldExtractElementInstruction
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|Constant
modifier|*
name|Val
parameter_list|,
name|Constant
modifier|*
name|Idx
parameter_list|)
function_decl|;
name|Constant
modifier|*
name|ConstantFoldInsertElementInstruction
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|Constant
modifier|*
name|Val
parameter_list|,
name|Constant
modifier|*
name|Elt
parameter_list|,
name|Constant
modifier|*
name|Idx
parameter_list|)
function_decl|;
name|Constant
modifier|*
name|ConstantFoldShuffleVectorInstruction
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|Constant
modifier|*
name|V1
parameter_list|,
name|Constant
modifier|*
name|V2
parameter_list|,
name|Constant
modifier|*
name|Mask
parameter_list|)
function_decl|;
name|Constant
modifier|*
name|ConstantFoldExtractValueInstruction
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|Constant
modifier|*
name|Agg
parameter_list|,
specifier|const
name|unsigned
modifier|*
name|Idxs
parameter_list|,
name|unsigned
name|NumIdx
parameter_list|)
function_decl|;
name|Constant
modifier|*
name|ConstantFoldInsertValueInstruction
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|Constant
modifier|*
name|Agg
parameter_list|,
name|Constant
modifier|*
name|Val
parameter_list|,
specifier|const
name|unsigned
modifier|*
name|Idxs
parameter_list|,
name|unsigned
name|NumIdx
parameter_list|)
function_decl|;
name|Constant
modifier|*
name|ConstantFoldBinaryInstruction
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|unsigned
name|Opcode
parameter_list|,
name|Constant
modifier|*
name|V1
parameter_list|,
name|Constant
modifier|*
name|V2
parameter_list|)
function_decl|;
name|Constant
modifier|*
name|ConstantFoldCompareInstruction
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|unsigned
name|short
name|predicate
parameter_list|,
name|Constant
modifier|*
name|C1
parameter_list|,
name|Constant
modifier|*
name|C2
parameter_list|)
function_decl|;
name|Constant
modifier|*
name|ConstantFoldGetElementPtr
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|Constant
modifier|*
name|C
parameter_list|,
name|bool
name|inBounds
parameter_list|,
name|Constant
modifier|*
specifier|const
modifier|*
name|Idxs
parameter_list|,
name|unsigned
name|NumIdx
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

