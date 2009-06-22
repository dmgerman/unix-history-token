begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCInst.h - MCInst class -------------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCInst and MCOperand classes, which
end_comment

begin_comment
comment|// is the basic representation used to represent low-level machine code
end_comment

begin_comment
comment|// instructions.
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
name|LLVM_MC_MCINST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCINST_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DebugLoc.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MCOperand - Instances of this class represent operands of the MCInst class.
comment|/// This is a simple discriminated union.
name|class
name|MCOperand
block|{
enum|enum
name|MachineOperandType
block|{
name|kInvalid
block|,
comment|///< Uninitialized.
name|kRegister
block|,
comment|///< Register operand.
name|kImmediate
block|,
comment|///< Immediate operand.
name|kMBBLabel
comment|///< Basic block label.
block|}
enum|;
name|unsigned
name|char
name|Kind
decl_stmt|;
union|union
block|{
name|unsigned
name|RegVal
decl_stmt|;
name|int64_t
name|ImmVal
decl_stmt|;
struct|struct
block|{
name|unsigned
name|FunctionNo
decl_stmt|;
name|unsigned
name|BlockNo
decl_stmt|;
block|}
name|MBBLabel
struct|;
block|}
union|;
name|public
label|:
name|MCOperand
argument_list|()
operator|:
name|Kind
argument_list|(
argument|kInvalid
argument_list|)
block|{}
name|MCOperand
argument_list|(
argument|const MCOperand&RHS
argument_list|)
block|{
operator|*
name|this
operator|=
name|RHS
block|; }
name|bool
name|isReg
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|kRegister
return|;
block|}
name|bool
name|isImm
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|kImmediate
return|;
block|}
name|bool
name|isMBBLabel
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|kMBBLabel
return|;
block|}
comment|/// getReg - Returns the register number.
name|unsigned
name|getReg
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isReg
argument_list|()
operator|&&
literal|"This is not a register operand!"
argument_list|)
block|;
return|return
name|RegVal
return|;
block|}
comment|/// setReg - Set the register number.
name|void
name|setReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|assert
argument_list|(
name|isReg
argument_list|()
operator|&&
literal|"This is not a register operand!"
argument_list|)
expr_stmt|;
name|RegVal
operator|=
name|Reg
expr_stmt|;
block|}
name|int64_t
name|getImm
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isImm
argument_list|()
operator|&&
literal|"This is not an immediate"
argument_list|)
block|;
return|return
name|ImmVal
return|;
block|}
name|void
name|setImm
parameter_list|(
name|int64_t
name|Val
parameter_list|)
block|{
name|assert
argument_list|(
name|isImm
argument_list|()
operator|&&
literal|"This is not an immediate"
argument_list|)
expr_stmt|;
name|ImmVal
operator|=
name|Val
expr_stmt|;
block|}
name|unsigned
name|getMBBLabelFunction
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isMBBLabel
argument_list|()
operator|&&
literal|"Wrong accessor"
argument_list|)
block|;
return|return
name|MBBLabel
operator|.
name|FunctionNo
return|;
block|}
name|unsigned
name|getMBBLabelBlock
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isMBBLabel
argument_list|()
operator|&&
literal|"Wrong accessor"
argument_list|)
block|;
return|return
name|MBBLabel
operator|.
name|BlockNo
return|;
block|}
name|void
name|MakeReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|Kind
operator|=
name|kRegister
expr_stmt|;
name|RegVal
operator|=
name|Reg
expr_stmt|;
block|}
name|void
name|MakeImm
parameter_list|(
name|int64_t
name|Val
parameter_list|)
block|{
name|Kind
operator|=
name|kImmediate
expr_stmt|;
name|ImmVal
operator|=
name|Val
expr_stmt|;
block|}
name|void
name|MakeMBBLabel
parameter_list|(
name|unsigned
name|Fn
parameter_list|,
name|unsigned
name|MBB
parameter_list|)
block|{
name|Kind
operator|=
name|kMBBLabel
expr_stmt|;
name|MBBLabel
operator|.
name|FunctionNo
operator|=
name|Fn
expr_stmt|;
name|MBBLabel
operator|.
name|BlockNo
operator|=
name|MBB
expr_stmt|;
block|}
block|}
empty_stmt|;
comment|/// MCInst - Instances of this class represent a single low-level machine
comment|/// instruction.
name|class
name|MCInst
block|{
name|unsigned
name|Opcode
decl_stmt|;
name|SmallVector
operator|<
name|MCOperand
operator|,
literal|8
operator|>
name|Operands
expr_stmt|;
name|public
label|:
name|MCInst
argument_list|()
operator|:
name|Opcode
argument_list|(
argument|~
literal|0U
argument_list|)
block|{}
name|void
name|setOpcode
argument_list|(
argument|unsigned Op
argument_list|)
block|{
name|Opcode
operator|=
name|Op
block|; }
name|unsigned
name|getOpcode
argument_list|()
specifier|const
block|{
return|return
name|Opcode
return|;
block|}
name|DebugLoc
name|getDebugLoc
argument_list|()
specifier|const
block|{
return|return
name|DebugLoc
argument_list|()
return|;
block|}
specifier|const
name|MCOperand
modifier|&
name|getOperand
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
return|return
name|Operands
index|[
name|i
index|]
return|;
block|}
name|MCOperand
modifier|&
name|getOperand
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
return|return
name|Operands
index|[
name|i
index|]
return|;
block|}
name|void
name|addOperand
parameter_list|(
specifier|const
name|MCOperand
modifier|&
name|Op
parameter_list|)
block|{
name|Operands
operator|.
name|push_back
argument_list|(
name|Op
argument_list|)
expr_stmt|;
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

