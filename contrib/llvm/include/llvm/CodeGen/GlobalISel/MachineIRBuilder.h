begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/GlobalISel/MachineIRBuilder.h - MIBuilder --*- C++ -*-===//
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
comment|/// This file declares the MachineIRBuilder class.
end_comment

begin_comment
comment|/// This is a helper class to build MachineInstr.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_GLOBALISEL_MACHINEIRBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_MACHINEIRBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/Types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LowLevelType.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstrBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Constants.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugLoc.h"
end_include

begin_include
include|#
directive|include
file|<queue>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declarations.
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
comment|/// Helper class to build MachineInstr.
comment|/// It keeps internally the insertion point and debug location for all
comment|/// the new instructions we want to create.
comment|/// This information can be modify via the related setters.
name|class
name|MachineIRBuilder
block|{
comment|/// MachineFunction under construction.
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
comment|/// Information used to access the description of the opcodes.
specifier|const
name|TargetInstrInfo
modifier|*
name|TII
decl_stmt|;
comment|/// Information used to verify types are consistent.
specifier|const
name|MachineRegisterInfo
modifier|*
name|MRI
decl_stmt|;
comment|/// Debug location to be set to any instruction we create.
name|DebugLoc
name|DL
decl_stmt|;
comment|/// \name Fields describing the insertion point.
comment|/// @{
name|MachineBasicBlock
modifier|*
name|MBB
decl_stmt|;
name|MachineBasicBlock
operator|::
name|iterator
name|II
expr_stmt|;
comment|/// @}
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|MachineInstr
operator|*
argument_list|)
operator|>
name|InsertedInstr
expr_stmt|;
specifier|const
name|TargetInstrInfo
modifier|&
name|getTII
parameter_list|()
block|{
name|assert
argument_list|(
name|TII
operator|&&
literal|"TargetInstrInfo is not set"
argument_list|)
expr_stmt|;
return|return
operator|*
name|TII
return|;
block|}
name|void
name|validateTruncExt
parameter_list|(
name|unsigned
name|Dst
parameter_list|,
name|unsigned
name|Src
parameter_list|,
name|bool
name|IsExtend
parameter_list|)
function_decl|;
name|public
label|:
comment|/// Getter for the function we currently build.
name|MachineFunction
modifier|&
name|getMF
parameter_list|()
block|{
name|assert
argument_list|(
name|MF
operator|&&
literal|"MachineFunction is not set"
argument_list|)
expr_stmt|;
return|return
operator|*
name|MF
return|;
block|}
comment|/// Getter for the basic block we currently build.
name|MachineBasicBlock
modifier|&
name|getMBB
parameter_list|()
block|{
name|assert
argument_list|(
name|MBB
operator|&&
literal|"MachineBasicBlock is not set"
argument_list|)
expr_stmt|;
return|return
operator|*
name|MBB
return|;
block|}
comment|/// Current insertion point for new instructions.
name|MachineBasicBlock
operator|::
name|iterator
name|getInsertPt
argument_list|()
block|{
return|return
name|II
return|;
block|}
comment|/// Set the insertion point before the specified position.
comment|/// \pre MBB must be in getMF().
comment|/// \pre II must be a valid iterator in MBB.
name|void
name|setInsertPt
argument_list|(
name|MachineBasicBlock
operator|&
name|MBB
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|II
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// \name Setters for the insertion point.
comment|/// @{
comment|/// Set the MachineFunction where to build instructions.
name|void
name|setMF
parameter_list|(
name|MachineFunction
modifier|&
parameter_list|)
function_decl|;
comment|/// Set the insertion point to the  end of \p MBB.
comment|/// \pre \p MBB must be contained by getMF().
name|void
name|setMBB
parameter_list|(
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
comment|/// Set the insertion point to before MI.
comment|/// \pre MI must be in getMF().
name|void
name|setInstr
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|/// @}
comment|/// \name Control where instructions we create are recorded (typically for
comment|/// visiting again later during legalization).
comment|/// @{
name|void
name|recordInsertions
argument_list|(
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|MachineInstr
operator|*
argument_list|)
operator|>
name|InsertedInstr
argument_list|)
decl_stmt|;
name|void
name|stopRecordingInsertions
parameter_list|()
function_decl|;
comment|/// @}
comment|/// Set the debug location to \p DL for all the next build instructions.
name|void
name|setDebugLoc
parameter_list|(
specifier|const
name|DebugLoc
modifier|&
name|DL
parameter_list|)
block|{
name|this
operator|->
name|DL
operator|=
name|DL
expr_stmt|;
block|}
comment|/// Get the current instruction's debug location.
name|DebugLoc
name|getDebugLoc
parameter_list|()
block|{
return|return
name|DL
return|;
block|}
comment|/// Build and insert<empty> = \p Opcode<empty>.
comment|/// The insertion point is the one set by the last call of either
comment|/// setBasicBlock or setMI.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildInstr
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
function_decl|;
comment|/// Build but don't insert<empty> = \p Opcode<empty>.
comment|///
comment|/// \pre setMF, setBasicBlock or setMI  must have been called.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildInstrNoInsert
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
function_decl|;
comment|/// Insert an existing instruction at the insertion point.
name|MachineInstrBuilder
name|insertInstr
parameter_list|(
name|MachineInstrBuilder
name|MIB
parameter_list|)
function_decl|;
comment|/// Build and insert a DBG_VALUE instruction expressing the fact that the
comment|/// associated \p Variable lives in \p Reg (suitably modified by \p Expr).
name|MachineInstrBuilder
name|buildDirectDbgValue
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|Variable
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|Expr
parameter_list|)
function_decl|;
comment|/// Build and insert a DBG_VALUE instruction expressing the fact that the
comment|/// associated \p Variable lives in memory at \p Reg + \p Offset (suitably
comment|/// modified by \p Expr).
name|MachineInstrBuilder
name|buildIndirectDbgValue
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|unsigned
name|Offset
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|Variable
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|Expr
parameter_list|)
function_decl|;
comment|/// Build and insert a DBG_VALUE instruction expressing the fact that the
comment|/// associated \p Variable lives in the stack slot specified by \p FI
comment|/// (suitably modified by \p Expr).
name|MachineInstrBuilder
name|buildFIDbgValue
parameter_list|(
name|int
name|FI
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|Variable
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|Expr
parameter_list|)
function_decl|;
comment|/// Build and insert a DBG_VALUE instructions specifying that \p Variable is
comment|/// given by \p C (suitably modified by \p Expr).
name|MachineInstrBuilder
name|buildConstDbgValue
parameter_list|(
specifier|const
name|Constant
modifier|&
name|C
parameter_list|,
name|unsigned
name|Offset
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|Variable
parameter_list|,
specifier|const
name|MDNode
modifier|*
name|Expr
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_FRAME_INDEX \p Idx
comment|///
comment|/// G_FRAME_INDEX materializes the address of an alloca value or other
comment|/// stack-based object.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with pointer type.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildFrameIndex
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|int
name|Idx
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_GLOBAL_VALUE \p GV
comment|///
comment|/// G_GLOBAL_VALUE materializes the address of the specified global
comment|/// into \p Res.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with pointer type
comment|///      in the same address space as \p GV.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildGlobalValue
parameter_list|(
name|unsigned
name|Res
parameter_list|,
specifier|const
name|GlobalValue
modifier|*
name|GV
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_ADD \p Op0, \p Op1
comment|///
comment|/// G_ADD sets \p Res to the sum of integer parameters \p Op0 and \p Op1,
comment|/// truncated to their width.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res, \p Op0 and \p Op1 must be generic virtual registers
comment|///      with the same (scalar or vector) type).
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildAdd
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|unsigned
name|Op1
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_SUB \p Op0, \p Op1
comment|///
comment|/// G_SUB sets \p Res to the sum of integer parameters \p Op0 and \p Op1,
comment|/// truncated to their width.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res, \p Op0 and \p Op1 must be generic virtual registers
comment|///      with the same (scalar or vector) type).
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildSub
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|unsigned
name|Op1
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_MUL \p Op0, \p Op1
comment|///
comment|/// G_MUL sets \p Res to the sum of integer parameters \p Op0 and \p Op1,
comment|/// truncated to their width.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res, \p Op0 and \p Op1 must be generic virtual registers
comment|///      with the same (scalar or vector) type).
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildMul
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|unsigned
name|Op1
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_GEP \p Op0, \p Op1
comment|///
comment|/// G_GEP adds \p Op1 bytes to the pointer specified by \p Op0,
comment|/// storing the resulting pointer in \p Res.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res and \p Op0 must be generic virtual registers with pointer
comment|///      type.
comment|/// \pre \p Op1 must be a generic virtual register with scalar type.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildGEP
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|unsigned
name|Op1
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_PTR_MASK \p Op0, \p NumBits
comment|///
comment|/// G_PTR_MASK clears the low bits of a pointer operand without destroying its
comment|/// pointer properties. This has the effect of rounding the address *down* to
comment|/// a specified alignment in bits.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res and \p Op0 must be generic virtual registers with pointer
comment|///      type.
comment|/// \pre \p NumBits must be an integer representing the number of low bits to
comment|///      be cleared in \p Op0.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildPtrMask
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|uint32_t
name|NumBits
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def>, \p CarryOut<def> = G_UADDE \p Op0,
comment|/// \p Op1, \p CarryIn
comment|///
comment|/// G_UADDE sets \p Res to \p Op0 + \p Op1 + \p CarryIn (truncated to the bit
comment|/// width) and sets \p CarryOut to 1 if the result overflowed in unsigned
comment|/// arithmetic.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res, \p Op0 and \p Op1 must be generic virtual registers
comment|///      with the same scalar type.
comment|/// \pre \p CarryOut and \p CarryIn must be generic virtual
comment|///      registers with the same scalar type (typically s1)
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildUAdde
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|CarryOut
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|unsigned
name|Op1
parameter_list|,
name|unsigned
name|CarryIn
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_AND \p Op0, \p Op1
comment|///
comment|/// G_AND sets \p Res to the bitwise and of integer parameters \p Op0 and \p
comment|/// Op1.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res, \p Op0 and \p Op1 must be generic virtual registers
comment|///      with the same (scalar or vector) type).
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildAnd
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|unsigned
name|Op1
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_ANYEXT \p Op0
comment|///
comment|/// G_ANYEXT produces a register of the specified width, with bits 0 to
comment|/// sizeof(\p Ty) * 8 set to \p Op. The remaining bits are unspecified
comment|/// (i.e. this is neither zero nor sign-extension). For a vector register,
comment|/// each element is extended individually.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar or vector type.
comment|/// \pre \p Op must be a generic virtual register with scalar or vector type.
comment|/// \pre \p Op must be smaller than \p Res
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildAnyExt
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_SEXT \p Op
comment|///
comment|/// G_SEXT produces a register of the specified width, with bits 0 to
comment|/// sizeof(\p Ty) * 8 set to \p Op. The remaining bits are duplicated from the
comment|/// high bit of \p Op (i.e. 2s-complement sign extended).
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar or vector type.
comment|/// \pre \p Op must be a generic virtual register with scalar or vector type.
comment|/// \pre \p Op must be smaller than \p Res
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildSExt
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_ZEXT \p Op
comment|///
comment|/// G_ZEXT produces a register of the specified width, with bits 0 to
comment|/// sizeof(\p Ty) * 8 set to \p Op. The remaining bits are 0. For a vector
comment|/// register, each element is extended individually.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar or vector type.
comment|/// \pre \p Op must be a generic virtual register with scalar or vector type.
comment|/// \pre \p Op must be smaller than \p Res
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildZExt
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_SEXT \p Op, \p Res = G_TRUNC \p Op, or
comment|/// \p Res = COPY \p Op depending on the differing sizes of \p Res and \p Op.
comment|///  ///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar or vector type.
comment|/// \pre \p Op must be a generic virtual register with scalar or vector type.
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildSExtOrTrunc
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_ZEXT \p Op, \p Res = G_TRUNC \p Op, or
comment|/// \p Res = COPY \p Op depending on the differing sizes of \p Res and \p Op.
comment|///  ///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar or vector type.
comment|/// \pre \p Op must be a generic virtual register with scalar or vector type.
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildZExtOrTrunc
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op
parameter_list|)
function_decl|;
comment|/// Build and insert an appropriate cast between two registers of equal size.
name|MachineInstrBuilder
name|buildCast
parameter_list|(
name|unsigned
name|Dst
parameter_list|,
name|unsigned
name|Src
parameter_list|)
function_decl|;
comment|/// Build and insert G_BR \p Dest
comment|///
comment|/// G_BR is an unconditional branch to \p Dest.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildBr
parameter_list|(
name|MachineBasicBlock
modifier|&
name|BB
parameter_list|)
function_decl|;
comment|/// Build and insert G_BRCOND \p Tst, \p Dest
comment|///
comment|/// G_BRCOND is a conditional branch to \p Dest.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Tst must be a generic virtual register with scalar
comment|///      type. At the beginning of legalization, this will be a single
comment|///      bit (s1). Targets with interesting flags registers may change
comment|///      this. For a wider type, whether the branch is taken must only
comment|///      depend on bit 0 (for now).
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildBrCond
parameter_list|(
name|unsigned
name|Tst
parameter_list|,
name|MachineBasicBlock
modifier|&
name|BB
parameter_list|)
function_decl|;
comment|/// Build and insert G_BRINDIRECT \p Tgt
comment|///
comment|/// G_BRINDIRECT is an indirect branch to \p Tgt.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Tgt must be a generic virtual register with pointer type.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildBrIndirect
parameter_list|(
name|unsigned
name|Tgt
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res = G_CONSTANT \p Val
comment|///
comment|/// G_CONSTANT is an integer constant with the specified size and value. \p
comment|/// Val will be extended or truncated to the size of \p Reg.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar or pointer
comment|///      type.
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildConstant
parameter_list|(
name|unsigned
name|Res
parameter_list|,
specifier|const
name|ConstantInt
modifier|&
name|Val
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res = G_CONSTANT \p Val
comment|///
comment|/// G_CONSTANT is an integer constant with the specified size and value.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar type.
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildConstant
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|int64_t
name|Val
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res = G_FCONSTANT \p Val
comment|///
comment|/// G_FCONSTANT is a floating-point constant with the specified size and
comment|/// value.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar type.
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildFConstant
parameter_list|(
name|unsigned
name|Res
parameter_list|,
specifier|const
name|ConstantFP
modifier|&
name|Val
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = COPY Op
comment|///
comment|/// Register-to-register COPY sets \p Res to \p Op.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildCopy
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op
parameter_list|)
function_decl|;
comment|/// Build and insert `Res<def> = G_LOAD Addr, MMO`.
comment|///
comment|/// Loads the value stored at \p Addr. Puts the result in \p Res.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register.
comment|/// \pre \p Addr must be a generic virtual register with pointer type.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildLoad
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Addr
parameter_list|,
name|MachineMemOperand
modifier|&
name|MMO
parameter_list|)
function_decl|;
comment|/// Build and insert `G_STORE Val, Addr, MMO`.
comment|///
comment|/// Stores the value \p Val to \p Addr.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Val must be a generic virtual register.
comment|/// \pre \p Addr must be a generic virtual register with pointer type.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildStore
parameter_list|(
name|unsigned
name|Val
parameter_list|,
name|unsigned
name|Addr
parameter_list|,
name|MachineMemOperand
modifier|&
name|MMO
parameter_list|)
function_decl|;
comment|/// Build and insert `Res0<def>, ... = G_EXTRACT Src, Idx0`.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res and \p Src must be generic virtual registers.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildExtract
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Src
parameter_list|,
name|uint64_t
name|Index
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res = IMPLICIT_DEF.
name|MachineInstrBuilder
name|buildUndef
parameter_list|(
name|unsigned
name|Dst
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_SEQUENCE \p Op0, \p Idx0...
comment|///
comment|/// G_SEQUENCE inserts each element of Ops into an IMPLICIT_DEF register,
comment|/// where each entry starts at the bit-index specified by \p Indices.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre The final element of the sequence must not extend past the end of the
comment|///      destination register.
comment|/// \pre The bits defined by each Op (derived from index and scalar size) must
comment|///      not overlap.
comment|/// \pre \p Indices must be in ascending order of bit position.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildSequence
argument_list|(
name|unsigned
name|Res
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Ops
argument_list|,
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|Indices
argument_list|)
decl_stmt|;
comment|/// Build and insert \p Res<def> = G_MERGE_VALUES \p Op0, ...
comment|///
comment|/// G_MERGE_VALUES combines the input elements contiguously into a larger
comment|/// register.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre The entire register \p Res (and no more) must be covered by the input
comment|///      registers.
comment|/// \pre The type of all \p Ops registers must be identical.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildMerge
argument_list|(
name|unsigned
name|Res
argument_list|,
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Ops
argument_list|)
decl_stmt|;
comment|/// Build and insert \p Res0<def>, ... = G_UNMERGE_VALUES \p Op
comment|///
comment|/// G_UNMERGE_VALUES splits contiguous bits of the input into multiple
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre The entire register \p Res (and no more) must be covered by the input
comment|///      registers.
comment|/// \pre The type of all \p Res registers must be identical.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildUnmerge
argument_list|(
name|ArrayRef
operator|<
name|unsigned
operator|>
name|Res
argument_list|,
name|unsigned
name|Op
argument_list|)
decl_stmt|;
name|void
name|addUsesWithIndices
parameter_list|(
name|MachineInstrBuilder
name|MIB
parameter_list|)
block|{}
name|template
operator|<
name|typename
operator|...
name|ArgTys
operator|>
name|void
name|addUsesWithIndices
argument_list|(
argument|MachineInstrBuilder MIB
argument_list|,
argument|unsigned Reg
argument_list|,
argument|unsigned BitIndex
argument_list|,
argument|ArgTys... Args
argument_list|)
block|{
name|MIB
operator|.
name|addUse
argument_list|(
name|Reg
argument_list|)
operator|.
name|addImm
argument_list|(
name|BitIndex
argument_list|)
block|;
name|addUsesWithIndices
argument_list|(
name|MIB
argument_list|,
name|Args
operator|...
argument_list|)
block|;   }
name|template
operator|<
name|typename
operator|...
name|ArgTys
operator|>
name|MachineInstrBuilder
name|buildSequence
argument_list|(
argument|unsigned Res
argument_list|,
argument|unsigned Op
argument_list|,
argument|unsigned Index
argument_list|,
argument|ArgTys... Args
argument_list|)
block|{
name|MachineInstrBuilder
name|MIB
operator|=
name|buildInstr
argument_list|(
name|TargetOpcode
operator|::
name|G_SEQUENCE
argument_list|)
operator|.
name|addDef
argument_list|(
name|Res
argument_list|)
block|;
name|addUsesWithIndices
argument_list|(
name|MIB
argument_list|,
name|Op
argument_list|,
name|Index
argument_list|,
name|Args
operator|...
argument_list|)
block|;
return|return
name|MIB
return|;
block|}
name|MachineInstrBuilder
name|buildInsert
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Src
parameter_list|,
name|unsigned
name|Op
parameter_list|,
name|unsigned
name|Index
parameter_list|)
function_decl|;
comment|/// Build and insert either a G_INTRINSIC (if \p HasSideEffects is false) or
comment|/// G_INTRINSIC_W_SIDE_EFFECTS instruction. Its first operand will be the
comment|/// result register definition unless \p Reg is NoReg (== 0). The second
comment|/// operand will be the intrinsic's ID.
comment|///
comment|/// Callers are expected to add the required definitions and uses afterwards.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildIntrinsic
argument_list|(
name|Intrinsic
operator|::
name|ID
name|ID
argument_list|,
name|unsigned
name|Res
argument_list|,
name|bool
name|HasSideEffects
argument_list|)
decl_stmt|;
comment|/// Build and insert \p Res<def> = G_FPTRUNC \p Op
comment|///
comment|/// G_FPTRUNC converts a floating-point value into one with a smaller type.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar or vector type.
comment|/// \pre \p Op must be a generic virtual register with scalar or vector type.
comment|/// \pre \p Res must be smaller than \p Op
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildFPTrunc
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_TRUNC \p Op
comment|///
comment|/// G_TRUNC extracts the low bits of a type. For a vector type each element is
comment|/// truncated independently before being packed into the destination.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar or vector type.
comment|/// \pre \p Op must be a generic virtual register with scalar or vector type.
comment|/// \pre \p Res must be smaller than \p Op
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildTrunc
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op
parameter_list|)
function_decl|;
comment|/// Build and insert a \p Res = G_ICMP \p Pred, \p Op0, \p Op1
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar or
comment|///      vector type. Typically this starts as s1 or<N x s1>.
comment|/// \pre \p Op0 and Op1 must be generic virtual registers with the
comment|///      same number of elements as \p Res. If \p Res is a scalar,
comment|///      \p Op0 must be either a scalar or pointer.
comment|/// \pre \p Pred must be an integer predicate.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildICmp
argument_list|(
name|CmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
name|unsigned
name|Res
argument_list|,
name|unsigned
name|Op0
argument_list|,
name|unsigned
name|Op1
argument_list|)
decl_stmt|;
comment|/// Build and insert a \p Res = G_FCMP \p Pred\p Op0, \p Op1
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar or
comment|///      vector type. Typically this starts as s1 or<N x s1>.
comment|/// \pre \p Op0 and Op1 must be generic virtual registers with the
comment|///      same number of elements as \p Res (or scalar, if \p Res is
comment|///      scalar).
comment|/// \pre \p Pred must be a floating-point predicate.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildFCmp
argument_list|(
name|CmpInst
operator|::
name|Predicate
name|Pred
argument_list|,
name|unsigned
name|Res
argument_list|,
name|unsigned
name|Op0
argument_list|,
name|unsigned
name|Op1
argument_list|)
decl_stmt|;
comment|/// Build and insert a \p Res = G_SELECT \p Tst, \p Op0, \p Op1
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res, \p Op0 and \p Op1 must be generic virtual registers
comment|///      with the same type.
comment|/// \pre \p Tst must be a generic virtual register with scalar, pointer or
comment|///      vector type. If vector then it must have the same number of
comment|///      elements as the other parameters.
comment|///
comment|/// \return a MachineInstrBuilder for the newly created instruction.
name|MachineInstrBuilder
name|buildSelect
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Tst
parameter_list|,
name|unsigned
name|Op0
parameter_list|,
name|unsigned
name|Op1
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_INSERT_VECTOR_ELT \p Val,
comment|/// \p Elt, \p Idx
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res and \p Val must be a generic virtual register
comment|//       with the same vector type.
comment|/// \pre \p Elt and \p Idx must be a generic virtual register
comment|///      with scalar type.
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildInsertVectorElement
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Val
parameter_list|,
name|unsigned
name|Elt
parameter_list|,
name|unsigned
name|Idx
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = G_EXTRACT_VECTOR_ELT \p Val, \p Idx
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre \p Res must be a generic virtual register with scalar type.
comment|/// \pre \p Val must be a generic virtual register with vector type.
comment|/// \pre \p Idx must be a generic virtual register with scalar type.
comment|///
comment|/// \return The newly created instruction.
name|MachineInstrBuilder
name|buildExtractVectorElement
parameter_list|(
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Val
parameter_list|,
name|unsigned
name|Idx
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_GLOBALISEL_MACHINEIRBUILDER_H
end_comment

end_unit

