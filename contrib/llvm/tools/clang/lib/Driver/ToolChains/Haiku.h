begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Haiku.h - Haiku ToolChain Implementations --------------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_HAIKU_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_HAIKU_H
end_define

begin_include
include|#
directive|include
file|"Gnu.h"
end_include

begin_include
include|#
directive|include
file|"clang/Driver/Driver.h"
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
name|toolchains
block|{
name|class
name|LLVM_LIBRARY_VISIBILITY
name|Haiku
range|:
name|public
name|Generic_ELF
block|{
name|public
operator|:
name|Haiku
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
name|bool
name|isPIEDefault
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
name|x86_64
return|;
block|}
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_HAIKU_H
end_comment

end_unit

