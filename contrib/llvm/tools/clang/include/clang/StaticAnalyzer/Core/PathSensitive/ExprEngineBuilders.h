begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ExprEngineBuilders.h - "Builder" classes for ExprEngine ---*- C++ -*-=//
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
comment|//  This file defines smart builder "references" which are used to marshal
end_comment

begin_comment
comment|//  builders between ExprEngine objects and their related components.
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
name|LLVM_CLANG_GR_EXPRENGINE_BUILDERS
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_GR_EXPRENGINE_BUILDERS
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ExprEngine.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/Support/SaveAndRestore.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|StmtNodeBuilderRef
block|{
name|ExplodedNodeSet
modifier|&
name|Dst
decl_stmt|;
name|StmtNodeBuilder
modifier|&
name|B
decl_stmt|;
name|ExprEngine
modifier|&
name|Eng
decl_stmt|;
name|ExplodedNode
modifier|*
name|Pred
decl_stmt|;
specifier|const
name|GRState
modifier|*
name|state
decl_stmt|;
specifier|const
name|Stmt
modifier|*
name|stmt
decl_stmt|;
specifier|const
name|unsigned
name|OldSize
decl_stmt|;
specifier|const
name|bool
name|AutoCreateNode
decl_stmt|;
name|SaveAndRestore
operator|<
name|bool
operator|>
name|OldSink
expr_stmt|;
name|SaveOr
name|OldHasGen
decl_stmt|;
name|private
label|:
name|friend
name|class
name|ExprEngine
decl_stmt|;
name|StmtNodeBuilderRef
argument_list|()
expr_stmt|;
comment|// do not implement
name|void
name|operator
init|=
operator|(
specifier|const
name|StmtNodeBuilderRef
operator|&
operator|)
decl_stmt|;
comment|// do not implement
name|StmtNodeBuilderRef
argument_list|(
argument|ExplodedNodeSet&dst
argument_list|,
argument|StmtNodeBuilder&builder
argument_list|,
argument|ExprEngine& eng
argument_list|,
argument|ExplodedNode* pred
argument_list|,
argument|const GRState *st
argument_list|,
argument|const Stmt* s
argument_list|,
argument|bool auto_create_node
argument_list|)
block|:
name|Dst
argument_list|(
name|dst
argument_list|)
operator|,
name|B
argument_list|(
name|builder
argument_list|)
operator|,
name|Eng
argument_list|(
name|eng
argument_list|)
operator|,
name|Pred
argument_list|(
name|pred
argument_list|)
operator|,
name|state
argument_list|(
name|st
argument_list|)
operator|,
name|stmt
argument_list|(
name|s
argument_list|)
operator|,
name|OldSize
argument_list|(
name|Dst
operator|.
name|size
argument_list|()
argument_list|)
operator|,
name|AutoCreateNode
argument_list|(
name|auto_create_node
argument_list|)
operator|,
name|OldSink
argument_list|(
name|B
operator|.
name|BuildSinks
argument_list|)
operator|,
name|OldHasGen
argument_list|(
argument|B.hasGeneratedNode
argument_list|)
block|{}
name|public
operator|:
operator|~
name|StmtNodeBuilderRef
argument_list|()
block|{
comment|// Handle the case where no nodes where generated.  Auto-generate that
comment|// contains the updated state if we aren't generating sinks.
if|if
condition|(
operator|!
name|B
operator|.
name|BuildSinks
operator|&&
name|Dst
operator|.
name|size
argument_list|()
operator|==
name|OldSize
operator|&&
operator|!
name|B
operator|.
name|hasGeneratedNode
condition|)
block|{
if|if
condition|(
name|AutoCreateNode
condition|)
name|B
operator|.
name|MakeNode
argument_list|(
name|Dst
argument_list|,
name|const_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
name|stmt
operator|)
argument_list|,
name|Pred
argument_list|,
name|state
argument_list|)
expr_stmt|;
else|else
name|Dst
operator|.
name|Add
argument_list|(
name|Pred
argument_list|)
expr_stmt|;
block|}
block|}
specifier|const
name|GRState
operator|*
name|getState
argument_list|()
block|{
return|return
name|state
return|;
block|}
name|GRStateManager
modifier|&
name|getStateManager
parameter_list|()
block|{
return|return
name|Eng
operator|.
name|getStateManager
argument_list|()
return|;
block|}
name|ExplodedNode
modifier|*
name|MakeNode
parameter_list|(
specifier|const
name|GRState
modifier|*
name|state
parameter_list|)
block|{
return|return
name|B
operator|.
name|MakeNode
argument_list|(
name|Dst
argument_list|,
name|const_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
name|stmt
operator|)
argument_list|,
name|Pred
argument_list|,
name|state
argument_list|)
return|;
block|}
block|}
empty_stmt|;
block|}
comment|// end GR namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

