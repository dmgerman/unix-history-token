begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/X86COFFMachineModuleInfo.h -----------------*- C++ -*-===//
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
comment|// This is an MMI implementation for X86 COFF (windows) targets.
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
name|X86COFF_MACHINEMODULEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|X86COFF_MACHINEMODULEINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineModuleInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"X86MachineFunctionInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|X86MachineFunctionInfo
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
comment|/// X86COFFMachineModuleInfo - This is a MachineModuleInfoImpl implementation
comment|/// for X86 COFF targets.
name|class
name|X86COFFMachineModuleInfo
range|:
name|public
name|MachineModuleInfoImpl
block|{
name|StringSet
operator|<
operator|>
name|CygMingStubs
block|;
name|public
operator|:
name|X86COFFMachineModuleInfo
argument_list|(
argument|const MachineModuleInfo&
argument_list|)
block|{}
name|virtual
operator|~
name|X86COFFMachineModuleInfo
argument_list|()
block|;
name|void
name|addExternalFunction
argument_list|(
argument|StringRef Name
argument_list|)
block|{
name|CygMingStubs
operator|.
name|insert
argument_list|(
name|Name
argument_list|)
block|;   }
typedef|typedef
name|StringSet
operator|<
operator|>
operator|::
name|const_iterator
name|stub_iterator
expr_stmt|;
name|stub_iterator
name|stub_begin
argument_list|()
specifier|const
block|{
return|return
name|CygMingStubs
operator|.
name|begin
argument_list|()
return|;
block|}
name|stub_iterator
name|stub_end
argument_list|()
specifier|const
block|{
return|return
name|CygMingStubs
operator|.
name|end
argument_list|()
return|;
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

