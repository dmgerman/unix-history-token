begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/CodeGen/GlobalISel/Utils.h ---------------------------*- C++ -*-==//
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
comment|/// \file This file declares the API of helper functions used throughout the
end_comment

begin_comment
comment|/// GlobalISel pipeline.
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
name|LLVM_CODEGEN_GLOBALISEL_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_UTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineOptimizationRemarkEmitter
decl_stmt|;
name|class
name|MachineOptimizationRemarkMissed
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|MCInstrDesc
decl_stmt|;
name|class
name|RegisterBankInfo
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetPassConfig
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|Twine
decl_stmt|;
comment|/// Try to constrain Reg so that it is usable by argument OpIdx of the
comment|/// provided MCInstrDesc \p II. If this fails, create a new virtual
comment|/// register in the correct class and insert a COPY before \p InsertPt.
comment|/// The debug location of \p InsertPt is used for the new copy.
comment|///
comment|/// \return The virtual register constrained to the right register class.
name|unsigned
name|constrainOperandRegClass
parameter_list|(
specifier|const
name|MachineFunction
modifier|&
name|MF
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
parameter_list|,
name|MachineRegisterInfo
modifier|&
name|MRI
parameter_list|,
specifier|const
name|TargetInstrInfo
modifier|&
name|TII
parameter_list|,
specifier|const
name|RegisterBankInfo
modifier|&
name|RBI
parameter_list|,
name|MachineInstr
modifier|&
name|InsertPt
parameter_list|,
specifier|const
name|MCInstrDesc
modifier|&
name|II
parameter_list|,
name|unsigned
name|Reg
parameter_list|,
name|unsigned
name|OpIdx
parameter_list|)
function_decl|;
comment|/// Check whether an instruction \p MI is dead: it only defines dead virtual
comment|/// registers, and doesn't have other side effects.
name|bool
name|isTriviallyDead
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|,
specifier|const
name|MachineRegisterInfo
modifier|&
name|MRI
parameter_list|)
function_decl|;
comment|/// Report an ISel error as a missed optimization remark to the LLVMContext's
comment|/// diagnostic stream.  Set the FailedISel MachineFunction property.
name|void
name|reportGISelFailure
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|,
specifier|const
name|TargetPassConfig
modifier|&
name|TPC
parameter_list|,
name|MachineOptimizationRemarkEmitter
modifier|&
name|MORE
parameter_list|,
name|MachineOptimizationRemarkMissed
modifier|&
name|R
parameter_list|)
function_decl|;
name|void
name|reportGISelFailure
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|,
specifier|const
name|TargetPassConfig
modifier|&
name|TPC
parameter_list|,
name|MachineOptimizationRemarkEmitter
modifier|&
name|MORE
parameter_list|,
specifier|const
name|char
modifier|*
name|PassName
parameter_list|,
name|StringRef
name|Msg
parameter_list|,
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
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

