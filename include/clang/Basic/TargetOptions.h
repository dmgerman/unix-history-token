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
comment|/// TargetOptions - Options for controlling the target.
name|class
name|TargetOptions
block|{
name|public
label|:
comment|/// If given, the name of the target triple to compile for. If not given the
comment|/// target will be selected to match the host.
name|std
operator|::
name|string
name|Triple
expr_stmt|;
comment|/// If given, the name of the target CPU to generate code for.
name|std
operator|::
name|string
name|CPU
expr_stmt|;
comment|/// If given, the name of the target ABI to use.
name|std
operator|::
name|string
name|ABI
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

