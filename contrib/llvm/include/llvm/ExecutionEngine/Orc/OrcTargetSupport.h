begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OrcTargetSupport.h - Code to support specific targets  --*- C++ -*-===//
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
comment|// Target specific code for Orc, e.g. callback assembly.
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
name|LLVM_EXECUTIONENGINE_ORC_ORCTARGETSUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_ORCTARGETSUPPORT_H
end_define

begin_include
include|#
directive|include
file|"IndirectionUtils.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
name|class
name|OrcX86_64
block|{
name|public
label|:
specifier|static
specifier|const
name|char
modifier|*
name|ResolverBlockName
decl_stmt|;
comment|/// @brief Insert module-level inline callback asm into module M for the
comment|/// symbols managed by JITResolveCallbackHandler J.
specifier|static
name|void
name|insertResolverBlock
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
name|JITCompileCallbackManagerBase
modifier|&
name|JCBM
parameter_list|)
function_decl|;
comment|/// @brief Get a label name from the given index.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|std
operator|::
name|string
argument_list|(
name|unsigned
argument_list|)
operator|>
name|LabelNameFtor
expr_stmt|;
comment|/// @brief Insert the requested number of trampolines into the given module.
comment|/// @param M Module to insert the call block into.
comment|/// @param NumCalls Number of calls to create in the call block.
comment|/// @param StartIndex Optional argument specifying the index suffix to start
comment|///                   with.
comment|/// @return A functor that provides the symbol name for each entry in the call
comment|///         block.
comment|///
specifier|static
name|LabelNameFtor
name|insertCompileCallbackTrampolines
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
name|TargetAddress
name|TrampolineAddr
parameter_list|,
name|unsigned
name|NumCalls
parameter_list|,
name|unsigned
name|StartIndex
init|=
literal|0
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
comment|// End namespace orc.
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
comment|// LLVM_EXECUTIONENGINE_ORC_ORCTARGETSUPPORT_H
end_comment

end_unit

