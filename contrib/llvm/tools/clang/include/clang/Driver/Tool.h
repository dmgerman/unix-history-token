begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Tool.h - Compilation Tools -----------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|CLANG_DRIVER_TOOL_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_TOOL_H_
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|opt
block|{
name|class
name|ArgList
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|class
name|Compilation
decl_stmt|;
name|class
name|InputInfo
decl_stmt|;
name|class
name|Job
decl_stmt|;
name|class
name|JobAction
decl_stmt|;
name|class
name|ToolChain
decl_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|InputInfo
operator|,
literal|4
operator|>
name|InputInfoList
expr_stmt|;
comment|/// Tool - Information on a specific compilation tool.
name|class
name|Tool
block|{
comment|/// The tool name (for debugging).
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|/// The human readable name for the tool, for use in diagnostics.
specifier|const
name|char
modifier|*
name|ShortName
decl_stmt|;
comment|/// The tool chain this tool is a part of.
specifier|const
name|ToolChain
modifier|&
name|TheToolChain
decl_stmt|;
name|public
label|:
name|Tool
argument_list|(
specifier|const
name|char
operator|*
name|Name
argument_list|,
specifier|const
name|char
operator|*
name|ShortName
argument_list|,
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|Tool
argument_list|()
expr_stmt|;
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
specifier|const
name|char
operator|*
name|getShortName
argument_list|()
specifier|const
block|{
return|return
name|ShortName
return|;
block|}
specifier|const
name|ToolChain
operator|&
name|getToolChain
argument_list|()
specifier|const
block|{
return|return
name|TheToolChain
return|;
block|}
name|virtual
name|bool
name|hasIntegratedAssembler
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|isLinkJob
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|isDsymutilJob
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Does this tool have "good" standardized diagnostics, or should the
comment|/// driver add an additional "command failed" diagnostic on failures.
name|virtual
name|bool
name|hasGoodDiagnostics
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// ConstructJob - Construct jobs to perform the action \p JA,
comment|/// writing to \p Output and with \p Inputs, and add the jobs to
comment|/// \p C.
comment|///
comment|/// \param TCArgs - The argument list for this toolchain, with any
comment|/// tool chain specific translations applied.
comment|/// \param LinkingOutput - If this output will eventually feed the
comment|/// linker, then this is the final output name of the linked image.
name|virtual
name|void
name|ConstructJob
argument_list|(
name|Compilation
operator|&
name|C
argument_list|,
specifier|const
name|JobAction
operator|&
name|JA
argument_list|,
specifier|const
name|InputInfo
operator|&
name|Output
argument_list|,
specifier|const
name|InputInfoList
operator|&
name|Inputs
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|TCArgs
argument_list|,
specifier|const
name|char
operator|*
name|LinkingOutput
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace driver
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

