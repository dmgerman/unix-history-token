begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- AArch64.h - AArch64-specific (not ARM) Tool Helpers ----*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_ARCH_AARCH64_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_ARCH_AARCH64_H
end_define

begin_include
include|#
directive|include
file|"clang/Driver/Driver.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/Option.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
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
name|aarch64
block|{
name|void
name|getAArch64TargetFeatures
argument_list|(
specifier|const
name|Driver
operator|&
name|D
argument_list|,
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|StringRef
operator|>
operator|&
name|Features
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|getAArch64TargetCPU
argument_list|(
specifier|const
name|llvm
operator|::
name|opt
operator|::
name|ArgList
operator|&
name|Args
argument_list|,
name|llvm
operator|::
name|opt
operator|::
name|Arg
operator|*
operator|&
name|A
argument_list|)
expr_stmt|;
block|}
comment|// end namespace aarch64
block|}
comment|// end namespace target
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_ARCH_AARCH64_H
end_comment

end_unit

