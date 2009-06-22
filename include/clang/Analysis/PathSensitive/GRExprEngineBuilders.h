begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GRExprEngineBuilders.h - "Builder" classes for GRExprEngine -*- C++ -*-=
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
comment|//  builders between GRExprEngine objects and their related components.
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
name|LLVM_CLANG_ANALYSIS_GREXPRENGINE_BUILDERS
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_GREXPRENGINE_BUILDERS
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/PathSensitive/GRExprEngine.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|// SaveAndRestore - A utility class that uses RAII to save and restore
comment|//  the value of a variable.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|SaveAndRestore
block|{
name|SaveAndRestore
argument_list|(
name|T
operator|&
name|x
argument_list|)
operator|:
name|X
argument_list|(
name|x
argument_list|)
block|,
name|old_value
argument_list|(
argument|x
argument_list|)
block|{}
operator|~
name|SaveAndRestore
argument_list|()
block|{
name|X
operator|=
name|old_value
block|; }
name|T
name|get
argument_list|()
block|{
return|return
name|old_value
return|;
block|}
name|private
operator|:
name|T
operator|&
name|X
block|;
name|T
name|old_value
block|; }
expr_stmt|;
comment|// SaveOr - Similar to SaveAndRestore.  Operates only on bools; the old
comment|//  value of a variable is saved, and during the dstor the old value is
comment|//  or'ed with the new value.
struct|struct
name|SaveOr
block|{
name|SaveOr
argument_list|(
name|bool
operator|&
name|x
argument_list|)
operator|:
name|X
argument_list|(
name|x
argument_list|)
operator|,
name|old_value
argument_list|(
argument|x
argument_list|)
block|{
name|x
operator|=
name|false
block|; }
operator|~
name|SaveOr
argument_list|()
block|{
name|X
operator||=
name|old_value
block|; }
name|private
operator|:
name|bool
operator|&
name|X
expr_stmt|;
specifier|const
name|bool
name|old_value
decl_stmt|;
block|}
struct|;
name|class
name|GRStmtNodeBuilderRef
block|{
name|GRExprEngine
operator|::
name|NodeSet
operator|&
name|Dst
expr_stmt|;
name|GRExprEngine
operator|::
name|StmtNodeBuilder
operator|&
name|B
expr_stmt|;
name|GRExprEngine
modifier|&
name|Eng
decl_stmt|;
name|GRExprEngine
operator|::
name|NodeTy
operator|*
name|Pred
expr_stmt|;
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
name|SaveAndRestore
operator|<
specifier|const
name|void
operator|*
operator|>
name|OldTag
expr_stmt|;
name|SaveOr
name|OldHasGen
decl_stmt|;
name|private
label|:
name|friend
name|class
name|GRExprEngine
decl_stmt|;
name|GRStmtNodeBuilderRef
argument_list|()
expr_stmt|;
comment|// do not implement
name|void
name|operator
init|=
operator|(
specifier|const
name|GRStmtNodeBuilderRef
operator|&
operator|)
decl_stmt|;
comment|// do not implement
name|GRStmtNodeBuilderRef
argument_list|(
argument|GRExprEngine::NodeSet&dst
argument_list|,
argument|GRExprEngine::StmtNodeBuilder&builder
argument_list|,
argument|GRExprEngine& eng
argument_list|,
argument|GRExprEngine::NodeTy* pred
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
name|OldTag
argument_list|(
name|B
operator|.
name|Tag
argument_list|)
operator|,
name|OldHasGen
argument_list|(
argument|B.HasGeneratedNode
argument_list|)
block|{}
name|public
operator|:
operator|~
name|GRStmtNodeBuilderRef
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
name|HasGeneratedNode
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
name|GRExprEngine
operator|::
name|NodeTy
operator|*
name|MakeNode
argument_list|(
argument|const GRState* state
argument_list|)
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
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

