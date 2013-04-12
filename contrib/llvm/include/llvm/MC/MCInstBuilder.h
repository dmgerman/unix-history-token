begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCInstBuilder.h - Simplify creation of MCInsts --*- C++ -*-===//
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
comment|// This file contains the MCInstBuilder class for convenient creation of
end_comment

begin_comment
comment|// MCInsts.
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
name|LLVM_MC_MCINSTBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCINSTBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCInst.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInstBuilder
block|{
name|MCInst
name|Inst
decl_stmt|;
name|public
label|:
comment|/// \brief Create a new MCInstBuilder for an MCInst with a specific opcode.
name|MCInstBuilder
argument_list|(
argument|unsigned Opcode
argument_list|)
block|{
name|Inst
operator|.
name|setOpcode
argument_list|(
name|Opcode
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Add a new register operand.
name|MCInstBuilder
modifier|&
name|addReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|Inst
operator|.
name|addOperand
argument_list|(
name|MCOperand
operator|::
name|CreateReg
argument_list|(
name|Reg
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Add a new integer immediate operand.
name|MCInstBuilder
modifier|&
name|addImm
parameter_list|(
name|int64_t
name|Val
parameter_list|)
block|{
name|Inst
operator|.
name|addOperand
argument_list|(
name|MCOperand
operator|::
name|CreateImm
argument_list|(
name|Val
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Add a new floating point immediate operand.
name|MCInstBuilder
modifier|&
name|addFPImm
parameter_list|(
name|double
name|Val
parameter_list|)
block|{
name|Inst
operator|.
name|addOperand
argument_list|(
name|MCOperand
operator|::
name|CreateFPImm
argument_list|(
name|Val
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Add a new MCExpr operand.
name|MCInstBuilder
modifier|&
name|addExpr
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Val
parameter_list|)
block|{
name|Inst
operator|.
name|addOperand
argument_list|(
name|MCOperand
operator|::
name|CreateExpr
argument_list|(
name|Val
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Add a new MCInst operand.
name|MCInstBuilder
modifier|&
name|addInst
parameter_list|(
specifier|const
name|MCInst
modifier|*
name|Val
parameter_list|)
block|{
name|Inst
operator|.
name|addOperand
argument_list|(
name|MCOperand
operator|::
name|CreateInst
argument_list|(
name|Val
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|operator
name|MCInst
function|&()
block|{
return|return
name|Inst
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

