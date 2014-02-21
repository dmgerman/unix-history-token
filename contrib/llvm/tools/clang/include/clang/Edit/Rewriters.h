begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Rewriters.h - Rewritings     ---------------------------*- C++ -*-===//
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
name|LLVM_CLANG_EDIT_REWRITERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_EDIT_REWRITERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ObjCMessageExpr
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCProtocolDecl
decl_stmt|;
name|class
name|NSAPI
decl_stmt|;
name|class
name|EnumDecl
decl_stmt|;
name|class
name|TypedefDecl
decl_stmt|;
name|class
name|ParentMap
decl_stmt|;
name|namespace
name|edit
block|{
name|class
name|Commit
decl_stmt|;
name|bool
name|rewriteObjCRedundantCallWithLiteral
parameter_list|(
specifier|const
name|ObjCMessageExpr
modifier|*
name|Msg
parameter_list|,
specifier|const
name|NSAPI
modifier|&
name|NS
parameter_list|,
name|Commit
modifier|&
name|commit
parameter_list|)
function_decl|;
name|bool
name|rewriteToObjCLiteralSyntax
parameter_list|(
specifier|const
name|ObjCMessageExpr
modifier|*
name|Msg
parameter_list|,
specifier|const
name|NSAPI
modifier|&
name|NS
parameter_list|,
name|Commit
modifier|&
name|commit
parameter_list|,
specifier|const
name|ParentMap
modifier|*
name|PMap
parameter_list|)
function_decl|;
name|bool
name|rewriteToObjCSubscriptSyntax
parameter_list|(
specifier|const
name|ObjCMessageExpr
modifier|*
name|Msg
parameter_list|,
specifier|const
name|NSAPI
modifier|&
name|NS
parameter_list|,
name|Commit
modifier|&
name|commit
parameter_list|)
function_decl|;
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

