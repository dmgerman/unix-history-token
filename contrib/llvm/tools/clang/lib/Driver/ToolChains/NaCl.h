begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- NaCl.h - Native Client ToolChain Implementations -------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_NACL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_NACL_H
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
name|namespace
name|nacltools
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|AssemblerARM
range|:
name|public
name|gnutools
operator|::
name|Assembler
block|{
name|public
operator|:
name|AssemblerARM
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
argument_list|)
operator|:
name|gnutools
operator|::
name|Assembler
argument_list|(
argument|TC
argument_list|)
block|{}
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
literal|"NaCl::Linker"
argument_list|,
literal|"linker"
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
comment|// end namespace nacltools
block|}
comment|// end namespace tools
name|namespace
name|toolchains
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|NaClToolChain
range|:
name|public
name|Generic_ELF
block|{
name|public
operator|:
name|NaClToolChain
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
name|CXXStdlibType
name|GetCXXStdlibType
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|)
specifier|const
name|override
block|;
name|void
name|AddCXXStdlibLibArgs
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|llvm::opt::ArgStringList&CmdArgs
argument_list|)
specifier|const
name|override
block|;
name|bool
name|IsIntegratedAssemblerDefault
argument_list|()
specifier|const
name|override
block|{
return|return
name|getTriple
argument_list|()
operator|.
name|getArch
argument_list|()
operator|==
name|llvm
operator|::
name|Triple
operator|::
name|mipsel
return|;
block|}
comment|// Get the path to the file containing NaCl's ARM macros.
comment|// It lives in NaClToolChain because the ARMAssembler tool needs a
comment|// const char * that it can pass around,
specifier|const
name|char
operator|*
name|GetNaClArmMacrosPath
argument_list|()
specifier|const
block|{
return|return
name|NaClArmMacrosPath
operator|.
name|c_str
argument_list|()
return|;
block|}
name|std
operator|::
name|string
name|ComputeEffectiveClangTriple
argument_list|(
argument|const llvm::opt::ArgList&Args
argument_list|,
argument|types::ID InputType
argument_list|)
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
name|Tool
operator|*
name|buildAssembler
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|std
operator|::
name|string
name|NaClArmMacrosPath
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_NACL_H
end_comment

end_unit

