begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//= CFGRecStmtDeclVisitor - Recursive visitor of CFG stmts/decls -*- C++ --*-=//
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
comment|// This file implements the template class CFGRecStmtDeclVisitor, which extends
end_comment

begin_comment
comment|// CFGRecStmtVisitor by implementing (typed) visitation of decls.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: This may not be fully complete.  We currently explore only subtypes
end_comment

begin_comment
comment|//        of ScopedDecl.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_ANALYSIS_CFG_REC_STMT_DECL_VISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_CFG_REC_STMT_DECL_VISITOR_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/Visitors/CFGRecStmtVisitor.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_define
define|#
directive|define
name|DISPATCH_CASE
parameter_list|(
name|CLASS
parameter_list|)
define|\
value|case Decl::CLASS:                                             \ static_cast<ImplClass*>(this)->Visit##CLASS##Decl(            \                                static_cast<CLASS##Decl*>(D)); \ break;
end_define

begin_define
define|#
directive|define
name|DEFAULT_DISPATCH
parameter_list|(
name|CLASS
parameter_list|)
value|void Visit##CLASS##Decl(CLASS##Decl *D) {}
end_define

begin_define
define|#
directive|define
name|DEFAULT_DISPATCH_VARDECL
parameter_list|(
name|CLASS
parameter_list|)
value|void Visit##CLASS##Decl(CLASS##Decl *D)\   { static_cast<ImplClass*>(this)->VisitVarDecl(D); }
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|template
operator|<
name|typename
name|ImplClass
operator|>
name|class
name|CFGRecStmtDeclVisitor
operator|:
name|public
name|CFGRecStmtVisitor
operator|<
name|ImplClass
operator|>
block|{
name|public
operator|:
name|void
name|VisitDeclRefExpr
argument_list|(
argument|DeclRefExpr *DR
argument_list|)
block|{
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|VisitDecl
argument_list|(
name|DR
operator|->
name|getDecl
argument_list|()
argument_list|)
block|;   }
name|void
name|VisitDeclStmt
argument_list|(
argument|DeclStmt *DS
argument_list|)
block|{
for|for
control|(
name|DeclStmt
operator|::
name|decl_iterator
name|DI
operator|=
name|DS
operator|->
name|decl_begin
argument_list|()
operator|,
name|DE
operator|=
name|DS
operator|->
name|decl_end
argument_list|()
init|;
name|DI
operator|!=
name|DE
condition|;
operator|++
name|DI
control|)
block|{
name|Decl
modifier|*
name|D
init|=
operator|*
name|DI
decl_stmt|;
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|VisitDecl
argument_list|(
name|D
argument_list|)
expr_stmt|;
comment|// Visit the initializer.
if|if
condition|(
name|VarDecl
modifier|*
name|VD
init|=
name|dyn_cast
operator|<
name|VarDecl
operator|>
operator|(
name|D
operator|)
condition|)
if|if
condition|(
name|Expr
modifier|*
name|I
init|=
name|VD
operator|->
name|getInit
argument_list|()
condition|)
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|Visit
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
block|}
name|void
name|VisitDecl
argument_list|(
argument|Decl *D
argument_list|)
block|{
switch|switch
condition|(
name|D
operator|->
name|getKind
argument_list|()
condition|)
block|{
name|DISPATCH_CASE
argument_list|(
argument|Function
argument_list|)
name|DISPATCH_CASE
argument_list|(
argument|CXXMethod
argument_list|)
name|DISPATCH_CASE
argument_list|(
argument|Var
argument_list|)
name|DISPATCH_CASE
argument_list|(
argument|ParmVar
argument_list|)
comment|// FIXME: (same)
name|DISPATCH_CASE
argument_list|(
argument|ImplicitParam
argument_list|)
name|DISPATCH_CASE
argument_list|(
argument|EnumConstant
argument_list|)
name|DISPATCH_CASE
argument_list|(
argument|Typedef
argument_list|)
name|DISPATCH_CASE
argument_list|(
argument|Record
argument_list|)
comment|// FIXME: Refine.  VisitStructDecl?
name|DISPATCH_CASE
argument_list|(
argument|CXXRecord
argument_list|)
name|DISPATCH_CASE
argument_list|(
argument|Enum
argument_list|)
name|DISPATCH_CASE
argument_list|(
argument|Field
argument_list|)
name|DISPATCH_CASE
argument_list|(
argument|UsingDirective
argument_list|)
name|DISPATCH_CASE
argument_list|(
argument|Using
argument_list|)
name|DISPATCH_CASE
argument_list|(
argument|NamespaceAlias
argument_list|)
default|default:
name|llvm_unreachable
argument_list|(
literal|"Subtype of ScopedDecl not handled."
argument_list|)
expr_stmt|;
block|}
block|}
name|DEFAULT_DISPATCH
argument_list|(
argument|Var
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|Function
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|CXXMethod
argument_list|)
name|DEFAULT_DISPATCH_VARDECL
argument_list|(
argument|ParmVar
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|ImplicitParam
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|EnumConstant
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|Typedef
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|Record
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|Enum
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|Field
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|ObjCInterface
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|ObjCMethod
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|ObjCProtocol
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|ObjCCategory
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|UsingDirective
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|Using
argument_list|)
name|DEFAULT_DISPATCH
argument_list|(
argument|NamespaceAlias
argument_list|)
name|void
name|VisitCXXRecordDecl
argument_list|(
argument|CXXRecordDecl *D
argument_list|)
block|{
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|VisitRecordDecl
argument_list|(
name|D
argument_list|)
block|;   }
block|}
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_undef
undef|#
directive|undef
name|DISPATCH_CASE
end_undef

begin_undef
undef|#
directive|undef
name|DEFAULT_DISPATCH
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

