begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/GlobalISel/IRTranslator.h - IRTranslator ---*- C++ -*-===//
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
comment|/// This file declares the IRTranslator pass.
end_comment

begin_comment
comment|/// This pass is responsible for translating LLVM IR into MachineInstr.
end_comment

begin_comment
comment|/// It uses target hooks to lower the ABI but aside from that, the pass
end_comment

begin_comment
comment|/// generated code is generic. This is the default translator used for
end_comment

begin_comment
comment|/// GlobalISel.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \todo Replace the comments with actual doxygen comments.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_GLOBALISEL_IRTRANSLATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_IRTRANSLATOR_H
end_define

begin_include
include|#
directive|include
file|"Types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/MachineIRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Forward declarations.
name|class
name|BasicBlock
decl_stmt|;
name|class
name|CallLowering
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|TargetPassConfig
decl_stmt|;
comment|// Technically the pass should run on an hypothetical MachineModule,
comment|// since it should translate Global into some sort of MachineGlobal.
comment|// The MachineGlobal should ultimately just be a transfer of ownership of
comment|// the interesting bits that are relevant to represent a global value.
comment|// That being said, we could investigate what would it cost to just duplicate
comment|// the information from the LLVM IR.
comment|// The idea is that ultimately we would be able to free up the memory used
comment|// by the LLVM IR as soon as the translation is over.
name|class
name|IRTranslator
range|:
name|public
name|MachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|private
operator|:
comment|/// Interface used to lower the everything related to calls.
specifier|const
name|CallLowering
operator|*
name|CLI
block|;
comment|/// Mapping of the values of the current LLVM IR function
comment|/// to the related virtual registers.
name|ValueToVReg
name|ValToVReg
block|;
comment|// Constants are special because when we encounter one,
comment|// we do not know at first where to insert the definition since
comment|// this depends on all its uses.
comment|// Thus, we will insert the sequences to materialize them when
comment|// we know all their users.
comment|// In the meantime, just keep it in a set.
comment|// Note: Constants that end up as immediate in the related instructions,
comment|// do not appear in that map.
name|SmallSetVector
operator|<
specifier|const
name|Constant
operator|*
block|,
literal|8
operator|>
name|Constants
block|;
comment|// N.b. it's not completely obvious that this will be sufficient for every
comment|// LLVM IR construct (with "invoke" being the obvious candidate to mess up our
comment|// lives.
name|DenseMap
operator|<
specifier|const
name|BasicBlock
operator|*
block|,
name|MachineBasicBlock
operator|*
operator|>
name|BBToMBB
block|;
comment|// List of stubbed PHI instructions, for values and basic blocks to be filled
comment|// in once all MachineBasicBlocks have been created.
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
specifier|const
name|PHINode
operator|*
block|,
name|MachineInstr
operator|*
operator|>
block|,
literal|4
operator|>
name|PendingPHIs
block|;
comment|/// Record of what frame index has been allocated to specified allocas for
comment|/// this function.
name|DenseMap
operator|<
specifier|const
name|AllocaInst
operator|*
block|,
name|int
operator|>
name|FrameIndices
block|;
comment|/// Methods for translating form LLVM IR to MachineInstr.
comment|/// \see ::translate for general information on the translate methods.
comment|/// @{
comment|/// Translate \p Inst into its corresponding MachineInstr instruction(s).
comment|/// Insert the newly translated instruction(s) right where the CurBuilder
comment|/// is set.
comment|///
comment|/// The general algorithm is:
comment|/// 1. Look for a virtual register for each operand or
comment|///    create one.
comment|/// 2 Update the ValToVReg accordingly.
comment|/// 2.alt. For constant arguments, if they are compile time constants,
comment|///   produce an immediate in the right operand and do not touch
comment|///   ValToReg. Actually we will go with a virtual register for each
comment|///   constants because it may be expensive to actually materialize the
comment|///   constant. Moreover, if the constant spans on several instructions,
comment|///   CSE may not catch them.
comment|///   => Update ValToVReg and remember that we saw a constant in Constants.
comment|///   We will materialize all the constants in finalize.
comment|/// Note: we would need to do something so that we can recognize such operand
comment|///       as constants.
comment|/// 3. Create the generic instruction.
comment|///
comment|/// \return true if the translation succeeded.
name|bool
name|translate
argument_list|(
specifier|const
name|Instruction
operator|&
name|Inst
argument_list|)
block|;
comment|/// Materialize \p C into virtual-register \p Reg. The generic instructions
comment|/// performing this materialization will be inserted into the entry block of
comment|/// the function.
comment|///
comment|/// \return true if the materialization succeeded.
name|bool
name|translate
argument_list|(
argument|const Constant&C
argument_list|,
argument|unsigned Reg
argument_list|)
block|;
comment|/// Translate an LLVM bitcast into generic IR. Either a COPY or a G_BITCAST is
comment|/// emitted.
name|bool
name|translateBitCast
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
comment|/// Translate an LLVM load instruction into generic IR.
name|bool
name|translateLoad
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
comment|/// Translate an LLVM store instruction into generic IR.
name|bool
name|translateStore
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
name|bool
name|translateMemcpy
argument_list|(
specifier|const
name|CallInst
operator|&
name|CI
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
name|void
name|getStackGuard
argument_list|(
argument|unsigned DstReg
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|;
name|bool
name|translateOverflowIntrinsic
argument_list|(
argument|const CallInst&CI
argument_list|,
argument|unsigned Op
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|;
name|bool
name|translateKnownIntrinsic
argument_list|(
argument|const CallInst&CI
argument_list|,
argument|Intrinsic::ID ID
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|;
comment|/// Translate call instruction.
comment|/// \pre \p U is a call instruction.
name|bool
name|translateCall
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
name|bool
name|translateInvoke
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
name|bool
name|translateLandingPad
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
comment|/// Translate one of LLVM's cast instructions into MachineInstrs, with the
comment|/// given generic Opcode.
name|bool
name|translateCast
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|;
comment|/// Translate static alloca instruction (i.e. one  of constant size and in the
comment|/// first basic block).
name|bool
name|translateStaticAlloca
argument_list|(
specifier|const
name|AllocaInst
operator|&
name|Inst
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
comment|/// Translate a phi instruction.
name|bool
name|translatePHI
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
comment|/// Translate a comparison (icmp or fcmp) instruction or constant.
name|bool
name|translateCompare
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
comment|/// Translate an integer compare instruction (or constant).
name|bool
name|translateICmp
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCompare
argument_list|(
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
comment|/// Translate a floating-point compare instruction (or constant).
name|bool
name|translateFCmp
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCompare
argument_list|(
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
comment|/// Add remaining operands onto phis we've translated. Executed after all
comment|/// MachineBasicBlocks for the function have been created.
name|void
name|finishPendingPhis
argument_list|()
block|;
comment|/// Translate \p Inst into a binary operation \p Opcode.
comment|/// \pre \p U is a binary operation.
name|bool
name|translateBinaryOp
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|;
comment|/// Translate branch (br) instruction.
comment|/// \pre \p U is a branch instruction.
name|bool
name|translateBr
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
name|bool
name|translateSwitch
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
name|bool
name|translateExtractValue
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
name|bool
name|translateInsertValue
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
name|bool
name|translateSelect
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
name|bool
name|translateGetElementPtr
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
comment|/// Translate return (ret) instruction.
comment|/// The target needs to implement CallLowering::lowerReturn for
comment|/// this to succeed.
comment|/// \pre \p U is a return instruction.
name|bool
name|translateRet
argument_list|(
specifier|const
name|User
operator|&
name|U
argument_list|,
name|MachineIRBuilder
operator|&
name|MIRBuilder
argument_list|)
block|;
name|bool
name|translateAdd
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_ADD
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateSub
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_SUB
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateAnd
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_AND
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateMul
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_MUL
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateOr
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_OR
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateXor
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_XOR
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateUDiv
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_UDIV
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateSDiv
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_SDIV
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateURem
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_UREM
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateSRem
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_SREM
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateAlloca
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateStaticAlloca
argument_list|(
name|cast
operator|<
name|AllocaInst
operator|>
operator|(
name|U
operator|)
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateIntToPtr
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCast
argument_list|(
name|TargetOpcode
operator|::
name|G_INTTOPTR
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translatePtrToInt
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCast
argument_list|(
name|TargetOpcode
operator|::
name|G_PTRTOINT
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateTrunc
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCast
argument_list|(
name|TargetOpcode
operator|::
name|G_TRUNC
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateFPTrunc
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCast
argument_list|(
name|TargetOpcode
operator|::
name|G_FPTRUNC
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateFPExt
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCast
argument_list|(
name|TargetOpcode
operator|::
name|G_FPEXT
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateFPToUI
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCast
argument_list|(
name|TargetOpcode
operator|::
name|G_FPTOUI
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateFPToSI
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCast
argument_list|(
name|TargetOpcode
operator|::
name|G_FPTOSI
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateUIToFP
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCast
argument_list|(
name|TargetOpcode
operator|::
name|G_UITOFP
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateSIToFP
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCast
argument_list|(
name|TargetOpcode
operator|::
name|G_SITOFP
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateUnreachable
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|bool
name|translateSExt
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCast
argument_list|(
name|TargetOpcode
operator|::
name|G_SEXT
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateZExt
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateCast
argument_list|(
name|TargetOpcode
operator|::
name|G_ZEXT
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateShl
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_SHL
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateLShr
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_LSHR
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateAShr
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_ASHR
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateFAdd
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_FADD
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateFSub
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_FSUB
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateFMul
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_FMUL
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateFDiv
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_FDIV
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
name|bool
name|translateFRem
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|translateBinaryOp
argument_list|(
name|TargetOpcode
operator|::
name|G_FREM
argument_list|,
name|U
argument_list|,
name|MIRBuilder
argument_list|)
return|;
block|}
comment|// Stubs to keep the compiler happy while we implement the rest of the
comment|// translation.
name|bool
name|translateIndirectBr
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateResume
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateCleanupRet
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateCatchRet
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateCatchSwitch
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateFence
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateAtomicCmpXchg
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateAtomicRMW
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateAddrSpaceCast
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateCleanupPad
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateCatchPad
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateUserOp1
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateUserOp2
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateVAArg
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateExtractElement
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateInsertElement
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
name|bool
name|translateShuffleVector
argument_list|(
argument|const User&U
argument_list|,
argument|MachineIRBuilder&MIRBuilder
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// @}
comment|// Builder for machine instruction a la IRBuilder.
comment|// I.e., compared to regular MIBuilder, this one also inserts the instruction
comment|// in the current block, it can creates block, etc., basically a kind of
comment|// IRBuilder, but for Machine IR.
name|MachineIRBuilder
name|CurBuilder
block|;
comment|// Builder set to the entry block (just after ABI lowering instructions). Used
comment|// as a convenient location for Constants.
name|MachineIRBuilder
name|EntryBuilder
block|;
comment|// The MachineFunction currently being translated.
name|MachineFunction
operator|*
name|MF
block|;
comment|/// MachineRegisterInfo used to create virtual registers.
name|MachineRegisterInfo
operator|*
name|MRI
block|;
specifier|const
name|DataLayout
operator|*
name|DL
block|;
comment|/// Current target configuration. Controls how the pass handles errors.
specifier|const
name|TargetPassConfig
operator|*
name|TPC
block|;
comment|// * Insert all the code needed to materialize the constants
comment|// at the proper place. E.g., Entry block or dominator block
comment|// of each constant depending on how fancy we want to be.
comment|// * Clear the different maps.
name|void
name|finalizeFunction
argument_list|()
block|;
comment|/// Get the VReg that represents \p Val.
comment|/// If such VReg does not exist, it is created.
name|unsigned
name|getOrCreateVReg
argument_list|(
specifier|const
name|Value
operator|&
name|Val
argument_list|)
block|;
comment|/// Get the frame index that represents \p Val.
comment|/// If such VReg does not exist, it is created.
name|int
name|getOrCreateFrameIndex
argument_list|(
specifier|const
name|AllocaInst
operator|&
name|AI
argument_list|)
block|;
comment|/// Get the alignment of the given memory operation instruction. This will
comment|/// either be the explicitly specified value or the ABI-required alignment for
comment|/// the type being accessed (according to the Module's DataLayout).
name|unsigned
name|getMemOpAlignment
argument_list|(
specifier|const
name|Instruction
operator|&
name|I
argument_list|)
block|;
comment|/// Get the MachineBasicBlock that represents \p BB.
comment|/// If such basic block does not exist, it is created.
name|MachineBasicBlock
operator|&
name|getOrCreateBB
argument_list|(
specifier|const
name|BasicBlock
operator|&
name|BB
argument_list|)
block|;
name|public
operator|:
comment|// Ctor, nothing fancy.
name|IRTranslator
argument_list|()
block|;
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"IRTranslator"
return|;
block|}
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
comment|// Algo:
comment|//   CallLowering = MF.subtarget.getCallLowering()
comment|//   F = MF.getParent()
comment|//   MIRBuilder.reset(MF)
comment|//   MIRBuilder.getOrCreateBB(F.getEntryBB())
comment|//   CallLowering->translateArguments(MIRBuilder, F, ValToVReg)
comment|//   for each bb in F
comment|//     MIRBuilder.getOrCreateBB(bb)
comment|//     for each inst in bb
comment|//       if (!translate(MIRBuilder, inst, ValToVReg, ConstantToSequence))
comment|//         report_fatal_error(âDonât know how to translate input");
comment|//   finalize()
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

