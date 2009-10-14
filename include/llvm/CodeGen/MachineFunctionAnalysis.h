begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MachineFunctionAnalysis.h - Owner of MachineFunctions ----*-C++ -*-===//
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
comment|// This file declares the MachineFunctionAnalysis class.
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
name|LLVM_CODEGEN_MACHINE_FUNCTION_ANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINE_FUNCTION_ANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
comment|/// MachineFunctionAnalysis - This class is a Pass that manages a
comment|/// MachineFunction object.
name|struct
name|MachineFunctionAnalysis
range|:
name|public
name|FunctionPass
block|{
name|private
operator|:
specifier|const
name|TargetMachine
operator|&
name|TM
block|;
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
block|;
name|MachineFunction
operator|*
name|MF
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|explicit
name|MachineFunctionAnalysis
argument_list|(
argument|TargetMachine&tm
argument_list|,
argument|CodeGenOpt::Level OL = CodeGenOpt::Default
argument_list|)
block|;
operator|~
name|MachineFunctionAnalysis
argument_list|()
block|;
name|MachineFunction
operator|&
name|getMF
argument_list|()
specifier|const
block|{
return|return
operator|*
name|MF
return|;
block|}
name|CodeGenOpt
operator|::
name|Level
name|getOptLevel
argument_list|()
specifier|const
block|{
return|return
name|OptLevel
return|;
block|}
name|private
operator|:
name|virtual
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
name|virtual
name|void
name|releaseMemory
argument_list|()
block|;
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|; }
decl_stmt|;
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

