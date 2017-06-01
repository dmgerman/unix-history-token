begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- MachineFunctionInitializer.h - machine function initializer --*- C++ -*-=//
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
comment|// This file declares an interface that allows custom machine function
end_comment

begin_comment
comment|// initialization.
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
name|LLVM_CODEGEN_MACHINEFUNCTIONINITIALIZER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINEFUNCTIONINITIALIZER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineFunction
decl_stmt|;
comment|/// This interface provides a way to initialize machine functions after they are
comment|/// created by the machine function analysis pass.
name|class
name|MachineFunctionInitializer
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|public
label|:
name|virtual
operator|~
name|MachineFunctionInitializer
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Initialize the machine function.
comment|///
comment|/// Return true if error occurred.
name|virtual
name|bool
name|initializeMachineFunction
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
init|=
literal|0
function_decl|;
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

begin_comment
comment|// LLVM_CODEGEN_MACHINEFUNCTIONINITIALIZER_H
end_comment

end_unit

