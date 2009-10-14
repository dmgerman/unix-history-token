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
comment|// We have to propagate some information about MachineFunction to
comment|// AsmPrinter. It's ok, when we're printing the function, since we have
comment|// access to MachineFunction and can get the appropriate MachineFunctionInfo.
comment|// Unfortunately, this is not possible when we're printing reference to
comment|// Function (e.g. calling it and so on). Even more, there is no way to get the
comment|// corresponding MachineFunctions: it can even be not created at all. That's
comment|// why we should use additional structure, when we're collecting all necessary
comment|// information.
comment|//
comment|// This structure is using e.g. for name decoration for stdcall& fastcall'ed
comment|// function, since we have to use arguments' size for decoration.
typedef|typedef
name|std
operator|::
name|map
operator|<
specifier|const
name|Function
operator|*
operator|,
name|X86MachineFunctionInfo
operator|>
name|FMFInfoMap
expr_stmt|;
name|FMFInfoMap
name|FunctionInfoMap
decl_stmt|;
name|public
label|:
name|X86COFFMachineModuleInfo
argument_list|(
specifier|const
name|MachineModuleInfo
operator|&
argument_list|)
expr_stmt|;
operator|~
name|X86COFFMachineModuleInfo
argument_list|()
expr_stmt|;
name|void
name|DecorateCygMingName
argument_list|(
name|std
operator|::
name|string
operator|&
name|Name
argument_list|,
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
specifier|const
name|TargetData
operator|&
name|TD
argument_list|)
decl_stmt|;
name|void
name|DecorateCygMingName
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Name
argument_list|,
specifier|const
name|GlobalValue
operator|*
name|GV
argument_list|,
specifier|const
name|TargetData
operator|&
name|TD
argument_list|)
decl_stmt|;
name|void
name|AddFunctionInfo
parameter_list|(
specifier|const
name|Function
modifier|*
name|F
parameter_list|,
specifier|const
name|X86MachineFunctionInfo
modifier|&
name|Val
parameter_list|)
function_decl|;
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

