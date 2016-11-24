begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- IndexDataConsumer.h - Abstract index data consumer ---------------===//
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
name|LLVM_CLANG_INDEX_INDEXDATACONSUMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_INDEXDATACONSUMER_H
end_define

begin_include
include|#
directive|include
file|"clang/Index/IndexSymbol.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|FileID
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|ImportDecl
decl_stmt|;
name|class
name|MacroInfo
decl_stmt|;
name|namespace
name|index
block|{
name|class
name|IndexDataConsumer
block|{
name|public
label|:
struct|struct
name|ASTNodeInfo
block|{
specifier|const
name|Expr
modifier|*
name|OrigE
decl_stmt|;
specifier|const
name|Decl
modifier|*
name|OrigD
decl_stmt|;
specifier|const
name|Decl
modifier|*
name|Parent
decl_stmt|;
specifier|const
name|DeclContext
modifier|*
name|ContainerDC
decl_stmt|;
block|}
struct|;
name|virtual
operator|~
name|IndexDataConsumer
argument_list|()
block|{}
name|virtual
name|void
name|initialize
argument_list|(
argument|ASTContext&Ctx
argument_list|)
block|{}
comment|/// \returns true to continue indexing, or false to abort.
name|virtual
name|bool
name|handleDeclOccurence
argument_list|(
argument|const Decl *D
argument_list|,
argument|SymbolRoleSet Roles
argument_list|,
argument|ArrayRef<SymbolRelation> Relations
argument_list|,
argument|FileID FID
argument_list|,
argument|unsigned Offset
argument_list|,
argument|ASTNodeInfo ASTNode
argument_list|)
expr_stmt|;
comment|/// \returns true to continue indexing, or false to abort.
name|virtual
name|bool
name|handleMacroOccurence
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
specifier|const
name|MacroInfo
modifier|*
name|MI
parameter_list|,
name|SymbolRoleSet
name|Roles
parameter_list|,
name|FileID
name|FID
parameter_list|,
name|unsigned
name|Offset
parameter_list|)
function_decl|;
comment|/// \returns true to continue indexing, or false to abort.
name|virtual
name|bool
name|handleModuleOccurence
parameter_list|(
specifier|const
name|ImportDecl
modifier|*
name|ImportD
parameter_list|,
name|SymbolRoleSet
name|Roles
parameter_list|,
name|FileID
name|FID
parameter_list|,
name|unsigned
name|Offset
parameter_list|)
function_decl|;
name|virtual
name|void
name|finish
parameter_list|()
block|{}
name|private
label|:
name|virtual
name|void
name|_anchor
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
comment|// namespace index
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

