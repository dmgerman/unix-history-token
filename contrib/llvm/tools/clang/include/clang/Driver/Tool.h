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
name|LLVM_CLANG_DRIVER_TOOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DRIVER_TOOL_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Program.h"
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
name|public
label|:
comment|// Documents the level of support for response files in this tool.
comment|// Response files are necessary if the command line gets too large,
comment|// requiring the arguments to be transferred to a file.
enum|enum
name|ResponseFileSupport
block|{
comment|// Provides full support for response files, which means we can transfer
comment|// all tool input arguments to a file. E.g.: clang, gcc, binutils and MSVC
comment|// tools.
name|RF_Full
block|,
comment|// Input file names can live in a file, but flags can't. E.g.: ld64 (Mac
comment|// OS X linker).
name|RF_FileList
block|,
comment|// Does not support response files: all arguments must be passed via
comment|// command line.
name|RF_None
block|}
enum|;
name|private
label|:
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
comment|/// The level of support for response files seen in this tool
specifier|const
name|ResponseFileSupport
name|ResponseSupport
decl_stmt|;
comment|/// The encoding to use when writing response files for this tool on Windows
specifier|const
name|llvm
operator|::
name|sys
operator|::
name|WindowsEncodingMethod
name|ResponseEncoding
expr_stmt|;
comment|/// The flag used to pass a response file via command line to this tool
specifier|const
name|char
modifier|*
specifier|const
name|ResponseFlag
decl_stmt|;
name|public
label|:
name|Tool
argument_list|(
argument|const char *Name
argument_list|,
argument|const char *ShortName
argument_list|,
argument|const ToolChain&TC
argument_list|,
argument|ResponseFileSupport ResponseSupport = RF_None
argument_list|,
argument|llvm::sys::WindowsEncodingMethod ResponseEncoding = llvm::sys::WEM_UTF8
argument_list|,
argument|const char *ResponseFlag =
literal|"@"
argument_list|)
empty_stmt|;
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
name|canEmitIR
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
comment|/// \brief Returns the level of support for response files of this tool,
comment|/// whether it accepts arguments to be passed via a file on disk.
name|ResponseFileSupport
name|getResponseFilesSupport
argument_list|()
specifier|const
block|{
return|return
name|ResponseSupport
return|;
block|}
comment|/// \brief Returns which encoding the response file should use. This is only
comment|/// relevant on Windows platforms where there are different encodings being
comment|/// accepted for different tools. On UNIX, UTF8 is universal.
comment|///
comment|/// Windows use cases: - GCC and Binutils on mingw only accept ANSI response
comment|/// files encoded with the system current code page.
comment|/// - MSVC's CL.exe and LINK.exe accept UTF16 on Windows.
comment|/// - Clang accepts both UTF8 and UTF16.
comment|///
comment|/// FIXME: When GNU tools learn how to parse UTF16 on Windows, we should
comment|/// always use UTF16 for Windows, which is the Windows official encoding for
comment|/// international characters.
name|llvm
operator|::
name|sys
operator|::
name|WindowsEncodingMethod
name|getResponseFileEncoding
argument_list|()
specifier|const
block|{
return|return
name|ResponseEncoding
return|;
block|}
comment|/// \brief Returns which prefix to use when passing the name of a response
comment|/// file as a parameter to this tool.
specifier|const
name|char
operator|*
name|getResponseFileFlag
argument_list|()
specifier|const
block|{
return|return
name|ResponseFlag
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
comment|/// Construct jobs to perform the action \p JA, writing to the \p Outputs and
comment|/// with \p Inputs, and add the jobs to \p C. The default implementation
comment|/// assumes a single output and is expected to be overloaded for the tools
comment|/// that support multiple inputs.
comment|///
comment|/// \param TCArgs The argument list for this toolchain, with any
comment|/// tool chain specific translations applied.
comment|/// \param LinkingOutput If this output will eventually feed the
comment|/// linker, then this is the final output name of the linked image.
name|virtual
name|void
name|ConstructJobMultipleOutputs
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
name|InputInfoList
operator|&
name|Outputs
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

