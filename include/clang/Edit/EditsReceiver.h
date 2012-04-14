begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- EditedSource.h - Collection of source edits ----------*- C++ -*-===//
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
name|LLVM_CLANG_EDIT_EDITSRECEIVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_EDIT_EDITSRECEIVER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|SourceLocation
decl_stmt|;
name|class
name|CharSourceRange
decl_stmt|;
name|namespace
name|edit
block|{
name|class
name|EditsReceiver
block|{
name|public
label|:
name|virtual
operator|~
name|EditsReceiver
argument_list|()
block|{ }
name|virtual
name|void
name|insert
argument_list|(
argument|SourceLocation loc
argument_list|,
argument|StringRef text
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|replace
parameter_list|(
name|CharSourceRange
name|range
parameter_list|,
name|StringRef
name|text
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief By default it calls replace with an empty string.
name|virtual
name|void
name|remove
parameter_list|(
name|CharSourceRange
name|range
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
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

