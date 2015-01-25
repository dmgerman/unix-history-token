begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//= ObjCNoReturn.h - Handling of Cocoa APIs known not to return --*- C++ -*---//
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
comment|//
end_comment

begin_comment
comment|// This file implements special handling of recognizing ObjC API hooks that
end_comment

begin_comment
comment|// do not return but aren't marked as such in API headers.
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
name|LLVM_CLANG_ANALYSIS_DOMAINSPECIFIC_OBJCNORETURN_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_DOMAINSPECIFIC_OBJCNORETURN_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|ObjCMessageExpr
decl_stmt|;
name|class
name|ObjCNoReturn
block|{
comment|/// Cached "raise" selector.
name|Selector
name|RaiseSel
decl_stmt|;
comment|/// Cached identifier for "NSException".
name|IdentifierInfo
modifier|*
name|NSExceptionII
decl_stmt|;
enum|enum
block|{
name|NUM_RAISE_SELECTORS
init|=
literal|2
block|}
enum|;
comment|/// Cached set of selectors in NSException that are 'noreturn'.
name|Selector
name|NSExceptionInstanceRaiseSelectors
index|[
name|NUM_RAISE_SELECTORS
index|]
decl_stmt|;
name|public
label|:
name|ObjCNoReturn
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
expr_stmt|;
comment|/// Return true if the given message expression is known to never
comment|/// return.
name|bool
name|isImplicitNoReturn
parameter_list|(
specifier|const
name|ObjCMessageExpr
modifier|*
name|ME
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

