begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ScopeInfo.h - Information about a semantic context -----*- C++ -*-===//
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
comment|//  This file defines FunctionScopeInfo and BlockScopeInfo.
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
name|LLVM_CLANG_SEMA_SCOPE_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_SCOPE_INFO_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

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
name|BlockDecl
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|LabelStmt
decl_stmt|;
name|class
name|ReturnStmt
decl_stmt|;
name|class
name|Scope
decl_stmt|;
name|class
name|SwitchStmt
decl_stmt|;
name|namespace
name|sema
block|{
comment|/// \brief Retains information about a function, method, or block that is
comment|/// currently being parsed.
name|class
name|FunctionScopeInfo
block|{
name|public
label|:
comment|/// \brief Whether this scope information structure defined information for
comment|/// a block.
name|bool
name|IsBlockInfo
decl_stmt|;
comment|/// \brief Whether this function contains a VLA, @try, try, C++
comment|/// initializer, or anything else that can't be jumped past.
name|bool
name|HasBranchProtectedScope
decl_stmt|;
comment|/// \brief Whether this function contains any switches or direct gotos.
name|bool
name|HasBranchIntoScope
decl_stmt|;
comment|/// \brief Whether this function contains any indirect gotos.
name|bool
name|HasIndirectGoto
decl_stmt|;
comment|/// \brief The number of errors that had occurred before starting this
comment|/// function or block.
name|unsigned
name|NumErrorsAtStartOfFunction
decl_stmt|;
comment|/// LabelMap - This is a mapping from label identifiers to the LabelStmt for
comment|/// it (which acts like the label decl in some ways).  Forward referenced
comment|/// labels have a LabelStmt created for them with a null location& SubStmt.
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|LabelStmt
operator|*
operator|>
name|LabelMap
expr_stmt|;
comment|/// SwitchStack - This is the current set of active switch statements in the
comment|/// block.
name|llvm
operator|::
name|SmallVector
operator|<
name|SwitchStmt
operator|*
operator|,
literal|8
operator|>
name|SwitchStack
expr_stmt|;
comment|/// \brief The list of return statements that occur within the function or
comment|/// block, if there is any chance of applying the named return value
comment|/// optimization.
name|llvm
operator|::
name|SmallVector
operator|<
name|ReturnStmt
operator|*
operator|,
literal|4
operator|>
name|Returns
expr_stmt|;
name|void
name|setHasBranchIntoScope
parameter_list|()
block|{
name|HasBranchIntoScope
operator|=
name|true
expr_stmt|;
block|}
name|void
name|setHasBranchProtectedScope
parameter_list|()
block|{
name|HasBranchProtectedScope
operator|=
name|true
expr_stmt|;
block|}
name|void
name|setHasIndirectGoto
parameter_list|()
block|{
name|HasIndirectGoto
operator|=
name|true
expr_stmt|;
block|}
name|bool
name|NeedsScopeChecking
argument_list|()
specifier|const
block|{
return|return
name|HasIndirectGoto
operator|||
operator|(
name|HasBranchProtectedScope
operator|&&
name|HasBranchIntoScope
operator|)
return|;
block|}
name|FunctionScopeInfo
argument_list|(
argument|unsigned NumErrors
argument_list|)
block|:
name|IsBlockInfo
argument_list|(
name|false
argument_list|)
operator|,
name|HasBranchProtectedScope
argument_list|(
name|false
argument_list|)
operator|,
name|HasBranchIntoScope
argument_list|(
name|false
argument_list|)
operator|,
name|HasIndirectGoto
argument_list|(
name|false
argument_list|)
operator|,
name|NumErrorsAtStartOfFunction
argument_list|(
argument|NumErrors
argument_list|)
block|{ }
name|virtual
operator|~
name|FunctionScopeInfo
argument_list|()
expr_stmt|;
comment|/// \brief Clear out the information in this function scope, making it
comment|/// suitable for reuse.
name|void
name|Clear
parameter_list|(
name|unsigned
name|NumErrors
parameter_list|)
function_decl|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|FunctionScopeInfo
modifier|*
name|FSI
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Retains information about a block that is currently being parsed.
name|class
name|BlockScopeInfo
range|:
name|public
name|FunctionScopeInfo
block|{
name|public
operator|:
name|bool
name|hasBlockDeclRefExprs
block|;
name|BlockDecl
operator|*
name|TheDecl
block|;
comment|/// TheScope - This is the scope for the block itself, which contains
comment|/// arguments etc.
name|Scope
operator|*
name|TheScope
block|;
comment|/// ReturnType - The return type of the block, or null if the block
comment|/// signature didn't provide an explicit return type.
name|QualType
name|ReturnType
block|;
comment|/// BlockType - The function type of the block, if one was given.
comment|/// Its return type may be BuiltinType::Dependent.
name|QualType
name|FunctionType
block|;
name|BlockScopeInfo
argument_list|(
argument|unsigned NumErrors
argument_list|,
argument|Scope *BlockScope
argument_list|,
argument|BlockDecl *Block
argument_list|)
operator|:
name|FunctionScopeInfo
argument_list|(
name|NumErrors
argument_list|)
block|,
name|hasBlockDeclRefExprs
argument_list|(
name|false
argument_list|)
block|,
name|TheDecl
argument_list|(
name|Block
argument_list|)
block|,
name|TheScope
argument_list|(
argument|BlockScope
argument_list|)
block|{
name|IsBlockInfo
operator|=
name|true
block|;   }
name|virtual
operator|~
name|BlockScopeInfo
argument_list|()
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const FunctionScopeInfo *FSI
argument_list|)
block|{
return|return
name|FSI
operator|->
name|IsBlockInfo
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const BlockScopeInfo *BSI
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;  }
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

