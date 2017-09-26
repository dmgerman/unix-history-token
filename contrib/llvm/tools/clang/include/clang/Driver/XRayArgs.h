begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- XRayArgs.h - Arguments for XRay ------------------------*- C++ -*-===//
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
name|LLVM_CLANG_DRIVER_XRAYARGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_DRIVER_XRAYARGS_H
end_define

begin_include
include|#
directive|include
file|"clang/Driver/Types.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/Arg.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Option/ArgList.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|class
name|ToolChain
decl_stmt|;
name|class
name|XRayArgs
block|{
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|AlwaysInstrumentFiles
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|NeverInstrumentFiles
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ExtraDeps
expr_stmt|;
name|bool
name|XRayInstrument
init|=
name|false
decl_stmt|;
name|int
name|InstructionThreshold
init|=
literal|200
decl_stmt|;
name|public
label|:
comment|/// Parses the XRay arguments from an argument list.
name|XRayArgs
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
expr_stmt|;
name|void
name|addArgs
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
argument_list|,
name|llvm
operator|::
name|opt
operator|::
name|ArgStringList
operator|&
name|CmdArgs
argument_list|,
name|types
operator|::
name|ID
name|InputType
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace driver
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_DRIVER_XRAYARGS_H
end_comment

end_unit

