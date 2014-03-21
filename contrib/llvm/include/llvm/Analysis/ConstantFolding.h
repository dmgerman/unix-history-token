begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ConstantFolding.h - Fold instructions into constants ----*- C++ -*-===//
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
comment|// This file declares routines for folding instructions into constants when all
end_comment

begin_comment
comment|// operands are constants, for example "sub i32 1, 0" -> "1".
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Also, to supplement the basic VMCore ConstantExpr simplifications,
end_comment

begin_comment
comment|// this file declares some additional folding routines that can make use of
end_comment

begin_comment
comment|// DataLayout information. These functions cannot go in VMCore due to library
end_comment

begin_comment
comment|// dependency issues.
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
name|LLVM_ANALYSIS_CONSTANTFOLDING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_CONSTANTFOLDING_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Constant
decl_stmt|;
name|class
name|ConstantExpr
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
comment|/// ConstantFoldInstruction - Try to constant fold the specified instruction.
comment|/// If successful, the constant result is returned, if not, null is returned.
comment|/// Note that this fails if not all of the operands are constant.  Otherwise,
comment|/// this function can only fail when attempting to fold instructions like loads
comment|/// and stores, which have no constant expression form.
name|Constant
modifier|*
name|ConstantFoldInstruction
parameter_list|(
name|Instruction
modifier|*
name|I
parameter_list|,
specifier|const
name|DataLayout
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// ConstantFoldConstantExpression - Attempt to fold the constant expression
comment|/// using the specified DataLayout.  If successful, the constant result is
comment|/// result is returned, if not, null is returned.
name|Constant
modifier|*
name|ConstantFoldConstantExpression
parameter_list|(
specifier|const
name|ConstantExpr
modifier|*
name|CE
parameter_list|,
specifier|const
name|DataLayout
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// ConstantFoldInstOperands - Attempt to constant fold an instruction with the
comment|/// specified operands.  If successful, the constant result is returned, if not,
comment|/// null is returned.  Note that this function can fail when attempting to
comment|/// fold instructions like loads and stores, which have no constant expression
comment|/// form.
comment|///
name|Constant
modifier|*
name|ConstantFoldInstOperands
argument_list|(
name|unsigned
name|Opcode
argument_list|,
name|Type
operator|*
name|DestTy
argument_list|,
name|ArrayRef
operator|<
name|Constant
operator|*
operator|>
name|Ops
argument_list|,
specifier|const
name|DataLayout
operator|*
name|TD
operator|=
literal|0
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// ConstantFoldCompareInstOperands - Attempt to constant fold a compare
comment|/// instruction (icmp/fcmp) with the specified operands.  If it fails, it
comment|/// returns a constant expression of the specified operands.
comment|///
name|Constant
modifier|*
name|ConstantFoldCompareInstOperands
parameter_list|(
name|unsigned
name|Predicate
parameter_list|,
name|Constant
modifier|*
name|LHS
parameter_list|,
name|Constant
modifier|*
name|RHS
parameter_list|,
specifier|const
name|DataLayout
modifier|*
name|TD
init|=
literal|0
parameter_list|,
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// ConstantFoldInsertValueInstruction - Attempt to constant fold an insertvalue
comment|/// instruction with the specified operands and indices.  The constant result is
comment|/// returned if successful; if not, null is returned.
name|Constant
modifier|*
name|ConstantFoldInsertValueInstruction
argument_list|(
name|Constant
operator|*
name|Agg
argument_list|,
name|Constant
operator|*
name|Val
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Idxs
argument_list|)
decl_stmt|;
comment|/// ConstantFoldLoadFromConstPtr - Return the value that a load from C would
comment|/// produce if it is constant and determinable.  If this is not determinable,
comment|/// return null.
name|Constant
modifier|*
name|ConstantFoldLoadFromConstPtr
parameter_list|(
name|Constant
modifier|*
name|C
parameter_list|,
specifier|const
name|DataLayout
modifier|*
name|TD
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// ConstantFoldLoadThroughGEPConstantExpr - Given a constant and a
comment|/// getelementptr constantexpr, return the constant value being addressed by the
comment|/// constant expression, or null if something is funny and we can't decide.
name|Constant
modifier|*
name|ConstantFoldLoadThroughGEPConstantExpr
parameter_list|(
name|Constant
modifier|*
name|C
parameter_list|,
name|ConstantExpr
modifier|*
name|CE
parameter_list|)
function_decl|;
comment|/// ConstantFoldLoadThroughGEPIndices - Given a constant and getelementptr
comment|/// indices (with an *implied* zero pointer index that is not in the list),
comment|/// return the constant value being addressed by a virtual load, or null if
comment|/// something is funny and we can't decide.
name|Constant
modifier|*
name|ConstantFoldLoadThroughGEPIndices
argument_list|(
name|Constant
operator|*
name|C
argument_list|,
name|ArrayRef
operator|<
name|Constant
operator|*
operator|>
name|Indices
argument_list|)
decl_stmt|;
comment|/// canConstantFoldCallTo - Return true if its even possible to fold a call to
comment|/// the specified function.
name|bool
name|canConstantFoldCallTo
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|)
function_decl|;
comment|/// ConstantFoldCall - Attempt to constant fold a call to the specified function
comment|/// with the specified arguments, returning null if unsuccessful.
name|Constant
modifier|*
name|ConstantFoldCall
argument_list|(
name|Function
operator|*
name|F
argument_list|,
name|ArrayRef
operator|<
name|Constant
operator|*
operator|>
name|Operands
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
operator|=
literal|0
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

