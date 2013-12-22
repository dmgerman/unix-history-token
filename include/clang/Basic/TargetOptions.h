begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TargetOptions.h ----------------------------------------*- C++ -*-===//
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::TargetOptions class.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_FRONTEND_TARGETOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_TARGETOPTIONS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
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
comment|/// \brief Options for controlling the target.
name|class
name|TargetOptions
range|:
name|public
name|RefCountedBase
operator|<
name|TargetOptions
operator|>
block|{
name|public
operator|:
comment|/// If given, the name of the target triple to compile for. If not given the
comment|/// target will be selected to match the host.
name|std
operator|::
name|string
name|Triple
block|;
comment|/// If given, the name of the target CPU to generate code for.
name|std
operator|::
name|string
name|CPU
block|;
comment|/// If given, the unit to use for floating point math.
name|std
operator|::
name|string
name|FPMath
block|;
comment|/// If given, the name of the target ABI to use.
name|std
operator|::
name|string
name|ABI
block|;
comment|/// If given, the name of the target C++ ABI to use. If not given, defaults
comment|/// to "itanium".
name|std
operator|::
name|string
name|CXXABI
block|;
comment|/// If given, the version string of the linker in use.
name|std
operator|::
name|string
name|LinkerVersion
block|;
comment|/// \brief The list of target specific features to enable or disable, as written on the command line.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|FeaturesAsWritten
block|;
comment|/// The list of target specific features to enable or disable -- this should
comment|/// be a list of strings starting with by '+' or '-'.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Features
block|; }
decl_stmt|;
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

