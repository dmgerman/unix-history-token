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
comment|/// Methods for translating form LLVM IR to MachineInstr.
comment|/// \see ::translate for general information on the translate methods.
comment|/// @{
comment|/// Translate \p Inst into its corresponding MachineInstr instruction(s).
comment|/// Insert the newly translated instruction(s) right where the MIRBuilder
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
comment|/// Translate \p Inst into a binary operation \p Opcode.
comment|/// \pre \p Inst is a binary operation.
name|bool
name|translateBinaryOp
argument_list|(
argument|unsigned Opcode
argument_list|,
argument|const Instruction&Inst
argument_list|)
block|;
comment|/// Translate branch (br) instruction.
comment|/// \pre \p Inst is a branch instruction.
name|bool
name|translateBr
argument_list|(
specifier|const
name|Instruction
operator|&
name|Inst
argument_list|)
block|;
comment|/// Translate return (ret) instruction.
comment|/// The target needs to implement CallLowering::lowerReturn for
comment|/// this to succeed.
comment|/// \pre \p Inst is a return instruction.
name|bool
name|translateReturn
argument_list|(
specifier|const
name|Instruction
operator|&
name|Inst
argument_list|)
block|;
comment|/// @}
comment|// Builder for machine instruction a la IRBuilder.
comment|// I.e., compared to regular MIBuilder, this one also inserts the instruction
comment|// in the current block, it can creates block, etc., basically a kind of
comment|// IRBuilder, but for Machine IR.
name|MachineIRBuilder
name|MIRBuilder
block|;
comment|/// MachineRegisterInfo used to create virtual registers.
name|MachineRegisterInfo
operator|*
name|MRI
block|;
comment|// * Insert all the code needed to materialize the constants
comment|// at the proper place. E.g., Entry block or dominator block
comment|// of each constant depending on how fancy we want to be.
comment|// * Clear the different maps.
name|void
name|finalize
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
specifier|const
name|char
operator|*
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"IRTranslator"
return|;
block|}
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

