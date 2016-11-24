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
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DebugLoc.h"
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
comment|/// Debug location to be set to any instruction we create.
name|DebugLoc
name|DL
decl_stmt|;
comment|/// Fields describing the insertion point.
comment|/// @{
name|MachineBasicBlock
modifier|*
name|MBB
decl_stmt|;
name|MachineInstr
modifier|*
name|MI
decl_stmt|;
name|bool
name|Before
decl_stmt|;
comment|/// @}
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
expr_stmt|;
comment|/// Setters for the insertion point.
comment|/// @{
comment|/// Set the MachineFunction where to build instructions.
name|void
name|setMF
parameter_list|(
name|MachineFunction
modifier|&
parameter_list|)
function_decl|;
comment|/// Set the insertion point to the beginning (\p Beginning = true) or end
comment|/// (\p Beginning = false) of \p MBB.
comment|/// \pre \p MBB must be contained by getMF().
name|void
name|setMBB
parameter_list|(
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|,
name|bool
name|Beginning
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Set the insertion point to before (\p Before = true) or after
comment|/// (\p Before = false) \p MI.
comment|/// \pre MI must be in getMF().
name|void
name|setInstr
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|bool
name|Before
init|=
name|false
parameter_list|)
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
comment|/// Build and insert<empty> = \p Opcode [\p Ty]<empty>.
comment|/// \p Ty is the type of the instruction if \p Opcode describes
comment|/// a generic machine instruction. \p Ty must be nullptr if \p Opcode
comment|/// does not describe a generic instruction.
comment|/// The insertion point is the one set by the last call of either
comment|/// setBasicBlock or setMI.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre Ty == nullptr or isPreISelGenericOpcode(Opcode)
comment|///
comment|/// \return The newly created instruction.
name|MachineInstr
modifier|*
name|buildInstr
parameter_list|(
name|unsigned
name|Opcode
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|)
function_decl|;
comment|/// Build and insert<empty> = \p Opcode [\p Ty] \p BB.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre Ty == nullptr or isPreISelGenericOpcode(Opcode)
comment|///
comment|/// \return The newly created instruction.
name|MachineInstr
modifier|*
name|buildInstr
parameter_list|(
name|unsigned
name|Opcode
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|,
name|MachineBasicBlock
modifier|&
name|BB
parameter_list|)
function_decl|;
comment|/// Build and insert \p Res<def> = \p Opcode [\p Ty] \p Op0, \p Op1.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre Ty == nullptr or isPreISelGenericOpcode(Opcode)
comment|///
comment|/// \return The newly created instruction.
name|MachineInstr
modifier|*
name|buildInstr
parameter_list|(
name|unsigned
name|Opcode
parameter_list|,
name|Type
modifier|*
name|Ty
parameter_list|,
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
comment|/// Build and insert \p Res<def> = \p Opcode \p Op0, \p Op1.
comment|/// I.e., instruction with a non-generic opcode.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre not isPreISelGenericOpcode(\p Opcode)
comment|///
comment|/// \return The newly created instruction.
name|MachineInstr
modifier|*
name|buildInstr
parameter_list|(
name|unsigned
name|Opcode
parameter_list|,
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
comment|/// Build and insert \p Res<def> = \p Opcode \p Op0.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre not isPreISelGenericOpcode(\p Opcode)
comment|///
comment|/// \return The newly created instruction.
name|MachineInstr
modifier|*
name|buildInstr
parameter_list|(
name|unsigned
name|Opcode
parameter_list|,
name|unsigned
name|Res
parameter_list|,
name|unsigned
name|Op0
parameter_list|)
function_decl|;
comment|/// Build and insert<empty> = \p Opcode<empty>.
comment|///
comment|/// \pre setBasicBlock or setMI must have been called.
comment|/// \pre not isPreISelGenericOpcode(\p Opcode)
comment|///
comment|/// \return The newly created instruction.
name|MachineInstr
modifier|*
name|buildInstr
parameter_list|(
name|unsigned
name|Opcode
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

