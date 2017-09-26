begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Sparc.h - Sparc-specific Tool Helpers ----------------------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_ARCH_SPARC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_ARCH_SPARC_H
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
name|sparc
block|{
name|enum
name|class
name|FloatABI
block|{
name|Invalid
operator|,
name|Soft
operator|,
name|Hard
operator|,
block|}
empty_stmt|;
name|FloatABI
name|getSparcFloatABI
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
argument_list|)
decl_stmt|;
name|void
name|getSparcTargetFeatures
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
specifier|const
name|char
modifier|*
name|getSparcAsmModeForCPU
argument_list|(
name|llvm
operator|::
name|StringRef
name|Name
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
block|}
comment|// end namespace sparc
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_ARCH_SPARC_H
end_comment

end_unit

