begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- CFGVarDeclVisitor - Generic visitor of VarDecls in a CFG --*- C++ --*-==//
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
comment|// This file implements the template class CFGVarDeclVisitor, which provides
end_comment

begin_comment
comment|// a generic way to visit all the VarDecl's in a CFG.
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
name|LLVM_CLANG_ANALYSIS_CFG_VARDECL_VISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_CFG_VARDECL_VISITOR_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/Visitors/CFGStmtVisitor.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Stmt.h"
end_include

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
name|CFGVarDeclVisitor
operator|:
name|public
name|CFGStmtVisitor
operator|<
name|ImplClass
operator|>
block|{
specifier|const
name|CFG
operator|&
name|cfg
block|;
name|public
operator|:
name|CFGVarDeclVisitor
argument_list|(
specifier|const
name|CFG
operator|&
name|c
argument_list|)
operator|:
name|cfg
argument_list|(
argument|c
argument_list|)
block|{}
name|void
name|VisitStmt
argument_list|(
argument|Stmt* S
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
name|VisitChildren
argument_list|(
name|S
argument_list|)
block|;   }
name|void
name|VisitDeclRefExpr
argument_list|(
argument|DeclRefExpr* DR
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
name|VisitDeclChain
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
argument|DeclStmt* DS
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
name|VisitDeclChain
argument_list|(
name|DS
operator|->
name|getDecl
argument_list|()
argument_list|)
block|;   }
name|void
name|VisitDeclChain
argument_list|(
argument|ScopedDecl* D
argument_list|)
block|{
for|for
control|(
init|;
name|D
operator|!=
name|NULL
condition|;
name|D
operator|=
name|D
operator|->
name|getNextDeclarator
argument_list|()
control|)
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|VisitScopedDecl
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
name|void
name|VisitScopedDecl
argument_list|(
argument|ScopedDecl* D
argument_list|)
block|{
if|if
condition|(
name|VarDecl
modifier|*
name|V
init|=
name|dyn_cast
operator|<
name|VarDecl
operator|>
operator|(
name|D
operator|)
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
name|VisitVarDecl
argument_list|(
name|V
argument_list|)
expr_stmt|;
block|}
name|void
name|VisitVarDecl
argument_list|(
argument|VarDecl* D
argument_list|)
block|{}
name|void
name|VisitAllDecls
argument_list|()
block|{
for|for
control|(
name|CFG
operator|::
name|const_iterator
name|BI
operator|=
name|cfg
operator|.
name|begin
argument_list|()
operator|,
name|BE
operator|=
name|cfg
operator|.
name|end
argument_list|()
init|;
name|BI
operator|!=
name|BE
condition|;
operator|++
name|BI
control|)
for|for
control|(
name|CFGBlock
operator|::
name|const_iterator
name|SI
operator|=
name|BI
operator|->
name|begin
argument_list|()
operator|,
name|SE
operator|=
name|BI
operator|->
name|end
argument_list|()
init|;
name|SI
operator|!=
name|SE
condition|;
operator|++
name|SI
control|)
name|static_cast
operator|<
name|ImplClass
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|BlockStmt_Visit
argument_list|(
name|const_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|*
name|SI
operator|)
argument_list|)
expr_stmt|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

