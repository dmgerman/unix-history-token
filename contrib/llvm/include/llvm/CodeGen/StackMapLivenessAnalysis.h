begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- StackMapLivenessAnalysis - StackMap Liveness Analysis --*- C++ -*-===//
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
comment|// This pass calculates the liveness for each basic block in a function and
end_comment

begin_comment
comment|// attaches the register live-out information to a patchpoint intrinsic (if
end_comment

begin_comment
comment|// present).
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
name|LLVM_CODEGEN_STACKMAP_LIVENESS_ANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_STACKMAP_LIVENESS_ANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/LivePhysRegs.h"
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
comment|/// \brief This pass calculates the liveness information for each basic block in
comment|/// a function and attaches the register live-out information to a patchpoint
comment|/// intrinsic if present.
comment|///
comment|/// This pass can be disabled via the -enable-patchpoint-liveness=false flag.
comment|/// The pass skips functions that don't have any patchpoint intrinsics. The
comment|/// information provided by this pass is optional and not required by the
comment|/// aformentioned intrinsic to function.
name|class
name|StackMapLiveness
range|:
name|public
name|MachineFunctionPass
block|{
name|MachineFunction
operator|*
name|MF
block|;
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
name|LivePhysRegs
name|LiveRegs
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|/// \brief Default construct and initialize the pass.
name|StackMapLiveness
argument_list|()
block|;
comment|/// \brief Tell the pass manager which passes we depend on and what
comment|/// information we preserve.
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
comment|/// \brief Calculate the liveness information for the given machine function.
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&MF
argument_list|)
name|override
block|;
name|private
operator|:
comment|/// \brief Performs the actual liveness calculation for the function.
name|bool
name|calculateLiveness
argument_list|()
block|;
comment|/// \brief Add the current register live set to the instruction.
name|void
name|addLiveOutSetToMI
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|)
block|;
comment|/// \brief Create a register mask and initialize it with the registers from
comment|/// the register live set.
name|uint32_t
operator|*
name|createRegisterMask
argument_list|()
specifier|const
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_STACKMAP_LIVENESS_ANALYSIS_H
end_comment

end_unit

