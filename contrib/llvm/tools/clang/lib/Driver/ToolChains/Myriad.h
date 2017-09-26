begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Myriad.h - Myriad ToolChain Implementations ------------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_MYRIAD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_MYRIAD_H
end_define

begin_include
include|#
directive|include
file|"Gnu.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Tool.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/ToolChain.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|namespace
name|tools
block|{
comment|/// SHAVE tools -- Directly call moviCompile and moviAsm
name|namespace
name|SHAVE
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Compiler
range|:
name|public
name|Tool
block|{
name|public
operator|:
name|Compiler
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Tool
argument_list|(
literal|"moviCompile"
argument_list|,
literal|"movicompile"
argument_list|,
argument|TC
argument_list|)
block|{}
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|void
name|ConstructJob
argument_list|(
argument|Compilation&C
argument_list|,
argument|const JobAction&JA
argument_list|,
argument|const InputInfo&Output
argument_list|,
argument|const InputInfoList&Inputs
argument_list|,
argument|const llvm::opt::ArgList&TCArgs
argument_list|,
argument|const char *LinkingOutput
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
range|:
name|public
name|Tool
block|{
name|public
operator|:
name|Assembler
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|Tool
argument_list|(
literal|"moviAsm"
argument_list|,
literal|"moviAsm"
argument_list|,
argument|TC
argument_list|)
block|{}
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
comment|// not sure.
name|void
name|ConstructJob
argument_list|(
argument|Compilation&C
argument_list|,
argument|const JobAction&JA
argument_list|,
argument|const InputInfo&Output
argument_list|,
argument|const InputInfoList&Inputs
argument_list|,
argument|const llvm::opt::ArgList&TCArgs
argument_list|,
argument|const char *LinkingOutput
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
comment|// end namespace SHAVE
comment|/// The Myriad toolchain uses tools that are in two different namespaces.
comment|/// The Compiler and Assembler as defined above are in the SHAVE namespace,
comment|/// whereas the linker, which accepts code for a mixture of Sparc and SHAVE,
comment|/// is in the Myriad namespace.
name|namespace
name|Myriad
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Linker
range|:
name|public
name|GnuTool
block|{
name|public
operator|:
name|Linker
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|GnuTool
argument_list|(
literal|"shave::Linker"
argument_list|,
literal|"ld"
argument_list|,
argument|TC
argument_list|)
block|{}
name|bool
name|hasIntegratedCPP
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|bool
name|isLinkJob
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
name|void
name|ConstructJob
argument_list|(
argument|Compilation&C
argument_list|,
argument|const JobAction&JA
argument_list|,
argument|const InputInfo&Output
argument_list|,
argument|const InputInfoList&Inputs
argument_list|,
argument|const llvm::opt::ArgList&TCArgs
argument_list|,
argument|const char *LinkingOutput
argument_list|)
specifier|const
name|override
block|; }
decl_stmt|;
block|}
comment|// end namespace Myriad
block|}
comment|// end namespace tools
name|namespace
name|toolchains
block|{
comment|/// MyriadToolChain - A tool chain using either clang or the external compiler
comment|/// installed by the Movidius SDK to perform all subcommands.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|MyriadToolChain
range|:
name|public
name|Generic_ELF
block|{
name|public
operator|:
name|MyriadToolChain
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|)
block|;
operator|~
name|MyriadToolChain
argument_list|()
name|override
block|;
name|void
name|AddClangSystemIncludeArgs
argument_list|(
argument|const llvm::opt::ArgList&DriverArgs
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|string
name|findLibCxxIncludePath
argument_list|()
specifier|const
name|override
block|;
name|void
name|addLibStdCxxIncludePaths
argument_list|(
argument|const llvm::opt::ArgList&DriverArgs
argument_list|,
argument|llvm::opt::ArgStringList&CC1Args
argument_list|)
specifier|const
name|override
block|;
name|Tool
operator|*
name|SelectTool
argument_list|(
argument|const JobAction&JA
argument_list|)
specifier|const
name|override
block|;
name|unsigned
name|GetDefaultDwarfVersion
argument_list|()
specifier|const
name|override
block|{
return|return
literal|2
return|;
block|}
name|SanitizerMask
name|getSupportedSanitizers
argument_list|()
specifier|const
name|override
block|;
name|protected
operator|:
name|Tool
operator|*
name|buildLinker
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isShaveCompilation
argument_list|(
argument|const llvm::Triple&T
argument_list|)
specifier|const
block|{
return|return
name|T
operator|.
name|getArch
argument_list|()
operator|==
name|llvm
operator|::
name|Triple
operator|::
name|shave
return|;
block|}
name|private
operator|:
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|Tool
operator|>
name|Compiler
block|;
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|Tool
operator|>
name|Assembler
block|; }
decl_stmt|;
block|}
comment|// end namespace toolchains
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

begin_comment
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_MYRIAD_H
end_comment

end_unit

