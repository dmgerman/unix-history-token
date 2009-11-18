begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ToolChain.h - Collections of tools for one platform ----*- C++ -*-===//
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
name|CLANG_DRIVER_TOOLCHAIN_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_TOOLCHAIN_H_
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/Path.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

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
name|DerivedArgList
decl_stmt|;
name|class
name|HostInfo
decl_stmt|;
name|class
name|InputArgList
decl_stmt|;
name|class
name|JobAction
decl_stmt|;
name|class
name|Tool
decl_stmt|;
comment|/// ToolChain - Access to tools for a single platform.
name|class
name|ToolChain
block|{
name|public
label|:
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|string
operator|,
literal|4
operator|>
name|path_list
expr_stmt|;
name|private
label|:
specifier|const
name|HostInfo
modifier|&
name|Host
decl_stmt|;
specifier|const
name|llvm
operator|::
name|Triple
name|Triple
expr_stmt|;
comment|/// The list of toolchain specific path prefixes to search for
comment|/// files.
name|path_list
name|FilePaths
decl_stmt|;
comment|/// The list of toolchain specific path prefixes to search for
comment|/// programs.
name|path_list
name|ProgramPaths
decl_stmt|;
name|protected
label|:
name|ToolChain
argument_list|(
specifier|const
name|HostInfo
operator|&
name|Host
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|_Triple
argument_list|)
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|ToolChain
argument_list|()
expr_stmt|;
comment|// Accessors
specifier|const
name|HostInfo
operator|&
name|getHost
argument_list|()
specifier|const
block|{
return|return
name|Host
return|;
block|}
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|getTriple
argument_list|()
specifier|const
block|{
return|return
name|Triple
return|;
block|}
name|std
operator|::
name|string
name|getArchName
argument_list|()
specifier|const
block|{
return|return
name|Triple
operator|.
name|getArchName
argument_list|()
return|;
block|}
name|std
operator|::
name|string
name|getPlatform
argument_list|()
specifier|const
block|{
return|return
name|Triple
operator|.
name|getVendorName
argument_list|()
return|;
block|}
name|std
operator|::
name|string
name|getOS
argument_list|()
specifier|const
block|{
return|return
name|Triple
operator|.
name|getOSName
argument_list|()
return|;
block|}
name|std
operator|::
name|string
name|getTripleString
argument_list|()
specifier|const
block|{
return|return
name|Triple
operator|.
name|getTriple
argument_list|()
return|;
block|}
name|path_list
modifier|&
name|getFilePaths
parameter_list|()
block|{
return|return
name|FilePaths
return|;
block|}
specifier|const
name|path_list
operator|&
name|getFilePaths
argument_list|()
specifier|const
block|{
return|return
name|FilePaths
return|;
block|}
name|path_list
modifier|&
name|getProgramPaths
parameter_list|()
block|{
return|return
name|ProgramPaths
return|;
block|}
specifier|const
name|path_list
operator|&
name|getProgramPaths
argument_list|()
specifier|const
block|{
return|return
name|ProgramPaths
return|;
block|}
comment|// Tool access.
comment|/// TranslateArgs - Create a new derived argument list for any argument
comment|/// translations this ToolChain may wish to perform.
comment|///
comment|/// \param BoundArch - The bound architecture name, or 0.
name|virtual
name|DerivedArgList
modifier|*
name|TranslateArgs
argument_list|(
name|InputArgList
operator|&
name|Args
argument_list|,
specifier|const
name|char
operator|*
name|BoundArch
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// SelectTool - Choose a tool to use to handle the action \arg JA.
name|virtual
name|Tool
modifier|&
name|SelectTool
argument_list|(
specifier|const
name|Compilation
operator|&
name|C
argument_list|,
specifier|const
name|JobAction
operator|&
name|JA
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|// Helper methods
name|std
operator|::
name|string
name|GetFilePath
argument_list|(
argument|const Compilation&C
argument_list|,
argument|const char *Name
argument_list|)
specifier|const
expr_stmt|;
name|std
operator|::
name|string
name|GetProgramPath
argument_list|(
argument|const Compilation&C
argument_list|,
argument|const char *Name
argument_list|,
argument|bool WantFile = false
argument_list|)
specifier|const
expr_stmt|;
comment|// Platform defaults information
comment|/// IsMathErrnoDefault - Does this tool chain set -fmath-errno by
comment|/// default.
name|virtual
name|bool
name|IsMathErrnoDefault
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// IsBlocksDefault - Does this tool chain enable -fblocks by default.
name|virtual
name|bool
name|IsBlocksDefault
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// IsObjCNonFragileABIDefault - Does this tool chain set
comment|/// -fobjc-nonfragile-abi by default.
name|virtual
name|bool
name|IsObjCNonFragileABIDefault
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// GetDefaultStackProtectorLevel - Get the default stack protector level for
comment|/// this tool chain (0=off, 1=on, 2=all).
name|virtual
name|unsigned
name|GetDefaultStackProtectorLevel
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|/// IsUnwindTablesDefault - Does this tool chain use -funwind-tables
comment|/// by default.
name|virtual
name|bool
name|IsUnwindTablesDefault
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// GetDefaultRelocationModel - Return the LLVM name of the default
comment|/// relocation model for this tool chain.
name|virtual
specifier|const
name|char
operator|*
name|GetDefaultRelocationModel
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// GetForcedPicModel - Return the LLVM name of the forced PIC model
comment|/// for this tool chain, or 0 if this tool chain does not force a
comment|/// particular PIC mode.
name|virtual
specifier|const
name|char
operator|*
name|GetForcedPicModel
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
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

