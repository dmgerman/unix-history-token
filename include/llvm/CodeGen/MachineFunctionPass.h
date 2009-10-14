begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MachineFunctionPass.h - Pass for MachineFunctions --------*-C++ -*-===//
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
comment|// This file defines the MachineFunctionPass class.  MachineFunctionPass's are
end_comment

begin_comment
comment|// just FunctionPass's, except they operate on machine code as part of a code
end_comment

begin_comment
comment|// generator.  Because they operate on machine code, not the LLVM
end_comment

begin_comment
comment|// representation, MachineFunctionPass's are not allowed to modify the LLVM
end_comment

begin_comment
comment|// representation.  Due to this limitation, the MachineFunctionPass class takes
end_comment

begin_comment
comment|// care of declaring that no LLVM passes are invalidated.
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
name|LLVM_CODEGEN_MACHINE_FUNCTION_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINE_FUNCTION_PASS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
comment|/// MachineFunctionPass - This class adapts the FunctionPass interface to
comment|/// allow convenient creation of passes that operate on the MachineFunction
comment|/// representation. Instead of overriding runOnFunction, subclasses
comment|/// override runOnMachineFunction.
name|class
name|MachineFunctionPass
range|:
name|public
name|FunctionPass
block|{
name|protected
operator|:
name|explicit
name|MachineFunctionPass
argument_list|(
argument|intptr_t ID
argument_list|)
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{}
name|explicit
name|MachineFunctionPass
argument_list|(
name|void
operator|*
name|ID
argument_list|)
operator|:
name|FunctionPass
argument_list|(
argument|ID
argument_list|)
block|{}
comment|/// runOnMachineFunction - This method must be overloaded to perform the
comment|/// desired machine code transformation or analysis.
comment|///
name|virtual
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
operator|=
literal|0
block|;
comment|/// getAnalysisUsage - Subclasses that override getAnalysisUsage
comment|/// must call this.
comment|///
comment|/// For MachineFunctionPasses, calling AU.preservesCFG() indicates that
comment|/// the pass does not modify the MachineBasicBlock CFG.
comment|///
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|;
name|private
operator|:
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
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

