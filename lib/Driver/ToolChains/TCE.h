begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TCE.h - TCE Tool and ToolChain Implementations ---------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_TCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_TCE_H
end_define

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

begin_include
include|#
directive|include
file|<set>
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
comment|/// TCEToolChain - A tool chain using the llvm bitcode tools to perform
comment|/// all subcommands. See http://tce.cs.tut.fi for our peculiar target.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|TCEToolChain
range|:
name|public
name|ToolChain
block|{
name|public
operator|:
name|TCEToolChain
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
name|TCEToolChain
argument_list|()
name|override
block|;
name|bool
name|IsMathErrnoDefault
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isPICDefault
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isPIEDefault
argument_list|()
specifier|const
name|override
block|;
name|bool
name|isPICDefaultForced
argument_list|()
specifier|const
name|override
block|; }
decl_stmt|;
comment|/// Toolchain for little endian TCE cores.
name|class
name|LLVM_LIBRARY_VISIBILITY
name|TCELEToolChain
range|:
name|public
name|TCEToolChain
block|{
name|public
operator|:
name|TCELEToolChain
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
name|TCELEToolChain
argument_list|()
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_TCE_H
end_comment

end_unit

