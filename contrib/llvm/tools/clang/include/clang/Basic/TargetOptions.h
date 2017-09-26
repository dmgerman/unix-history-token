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
name|LLVM_CLANG_BASIC_TARGETOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_TARGETOPTIONS_H
end_define

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

begin_include
include|#
directive|include
file|"clang/Basic/OpenCLOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetOptions.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Options for controlling the target.
name|class
name|TargetOptions
block|{
name|public
label|:
comment|/// The name of the target triple to compile for.
name|std
operator|::
name|string
name|Triple
expr_stmt|;
comment|/// When compiling for the device side, contains the triple used to compile
comment|/// for the host.
name|std
operator|::
name|string
name|HostTriple
expr_stmt|;
comment|/// If given, the name of the target CPU to generate code for.
name|std
operator|::
name|string
name|CPU
expr_stmt|;
comment|/// If given, the unit to use for floating point math.
name|std
operator|::
name|string
name|FPMath
expr_stmt|;
comment|/// If given, the name of the target ABI to use.
name|std
operator|::
name|string
name|ABI
expr_stmt|;
comment|/// The EABI version to use
name|llvm
operator|::
name|EABI
name|EABIVersion
expr_stmt|;
comment|/// If given, the version string of the linker in use.
name|std
operator|::
name|string
name|LinkerVersion
expr_stmt|;
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
expr_stmt|;
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
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Reciprocals
expr_stmt|;
comment|/// Supported OpenCL extensions and optional core features.
name|OpenCLOptions
name|SupportedOpenCLOptions
decl_stmt|;
comment|/// \brief The list of OpenCL extensions to enable or disable, as written on
comment|/// the command line.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|OpenCLExtensionsAsWritten
expr_stmt|;
block|}
empty_stmt|;
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

