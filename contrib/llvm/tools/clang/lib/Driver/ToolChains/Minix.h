begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Minix.h - Minix ToolChain Implementations --------------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_MINIX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_MINIX_H
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
comment|/// minix -- Directly call GNU Binutils assembler and linker
name|namespace
name|minix
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Assembler
range|:
name|public
name|GnuTool
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
name|GnuTool
argument_list|(
literal|"minix::Assembler"
argument_list|,
literal|"assembler"
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
literal|"minix::Linker"
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
comment|// end namespace minix
block|}
comment|// end namespace tools
name|namespace
name|toolchains
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Minix
range|:
name|public
name|Generic_ELF
block|{
name|public
operator|:
name|Minix
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
name|protected
operator|:
name|Tool
operator|*
name|buildAssembler
argument_list|()
specifier|const
name|override
block|;
name|Tool
operator|*
name|buildLinker
argument_list|()
specifier|const
name|override
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_MINIX_H
end_comment

end_unit

