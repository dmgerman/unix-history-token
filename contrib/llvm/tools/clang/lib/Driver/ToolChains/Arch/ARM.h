begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ARM.h - ARM-specific (not AArch64) Tool Helpers --------*- C++ -*-===//
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
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_ARCH_ARM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_ARCH_ARM_H
end_define

begin_include
include|#
directive|include
file|"clang/Driver/ToolChain.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
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
name|arm
block|{
name|std
operator|::
name|string
name|getARMTargetCPU
argument_list|(
argument|StringRef CPU
argument_list|,
argument|llvm::StringRef Arch
argument_list|,
argument|const llvm::Triple&Triple
argument_list|)
expr_stmt|;
specifier|const
name|std
operator|::
name|string
name|getARMArch
argument_list|(
argument|llvm::StringRef Arch
argument_list|,
argument|const llvm::Triple&Triple
argument_list|)
expr_stmt|;
name|StringRef
name|getARMCPUForMArch
argument_list|(
name|llvm
operator|::
name|StringRef
name|Arch
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
name|StringRef
name|getLLVMArchSuffixForARM
argument_list|(
name|llvm
operator|::
name|StringRef
name|CPU
argument_list|,
name|llvm
operator|::
name|StringRef
name|Arch
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
name|void
name|appendEBLinkFlags
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
name|ArgStringList
operator|&
name|CmdArgs
argument_list|,
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
name|enum
name|class
name|FloatABI
block|{
name|Invalid
operator|,
name|Soft
operator|,
name|SoftFP
operator|,
name|Hard
operator|,
block|}
empty_stmt|;
name|FloatABI
name|getARMFloatABI
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
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
name|bool
name|useAAPCSForMachO
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|T
argument_list|)
decl_stmt|;
name|void
name|getARMArchCPUFromArgs
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
name|StringRef
operator|&
name|Arch
argument_list|,
name|llvm
operator|::
name|StringRef
operator|&
name|CPU
argument_list|,
name|bool
name|FromAs
operator|=
name|false
argument_list|)
decl_stmt|;
name|void
name|getARMTargetFeatures
argument_list|(
specifier|const
name|ToolChain
operator|&
name|TC
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
argument_list|,
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
operator|&
name|CmdArgs
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
argument_list|,
name|bool
name|ForAS
argument_list|)
decl_stmt|;
name|int
name|getARMSubArchVersionNumber
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
name|bool
name|isARMMProfile
argument_list|(
specifier|const
name|llvm
operator|::
name|Triple
operator|&
name|Triple
argument_list|)
decl_stmt|;
block|}
comment|// end namespace arm
block|}
comment|// end namespace tools
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
comment|// LLVM_CLANG_LIB_DRIVER_TOOLCHAINS_ARCH_ARM_H
end_comment

end_unit

