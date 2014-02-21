begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Consumed.h ----------------------------------------------*- C++ --*-===//
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
comment|// A intra-procedural analysis for checking consumed properties.  This is based,
end_comment

begin_comment
comment|// in part, on research on linear types.
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
name|LLVM_CLANG_CONSUMED_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CONSUMED_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExprCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/StmtCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/AnalysisContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/Analyses/PostOrderCFGView.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|consumed
block|{
enum|enum
name|ConsumedState
block|{
comment|// No state information for the given variable.
name|CS_None
block|,
name|CS_Unknown
block|,
name|CS_Unconsumed
block|,
name|CS_Consumed
block|}
enum|;
name|class
name|ConsumedStmtVisitor
decl_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|PartialDiagnosticAt
operator|,
literal|1
operator|>
name|OptionalNotes
expr_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|PartialDiagnosticAt
operator|,
name|OptionalNotes
operator|>
name|DelayedDiag
expr_stmt|;
typedef|typedef
name|std
operator|::
name|list
operator|<
name|DelayedDiag
operator|>
name|DiagList
expr_stmt|;
name|class
name|ConsumedWarningsHandlerBase
block|{
name|public
label|:
name|virtual
operator|~
name|ConsumedWarningsHandlerBase
argument_list|()
expr_stmt|;
comment|/// \brief Emit the warnings and notes left by the analysis.
name|virtual
name|void
name|emitDiagnostics
parameter_list|()
block|{}
comment|/// \brief Warn that a variable's state doesn't match at the entry and exit
comment|/// of a loop.
comment|///
comment|/// \param Loc -- The location of the end of the loop.
comment|///
comment|/// \param VariableName -- The name of the variable that has a mismatched
comment|/// state.
name|virtual
name|void
name|warnLoopStateMismatch
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|VariableName
parameter_list|)
block|{}
comment|/// \brief Warn about parameter typestate mismatches upon return.
comment|///
comment|/// \param Loc -- The SourceLocation of the return statement.
comment|///
comment|/// \param ExpectedState -- The state the return value was expected to be
comment|/// in.
comment|///
comment|/// \param ObservedState -- The state the return value was observed to be
comment|/// in.
name|virtual
name|void
name|warnParamReturnTypestateMismatch
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|VariableName
parameter_list|,
name|StringRef
name|ExpectedState
parameter_list|,
name|StringRef
name|ObservedState
parameter_list|)
block|{}
empty_stmt|;
comment|// FIXME: Add documentation.
name|virtual
name|void
name|warnParamTypestateMismatch
parameter_list|(
name|SourceLocation
name|LOC
parameter_list|,
name|StringRef
name|ExpectedState
parameter_list|,
name|StringRef
name|ObservedState
parameter_list|)
block|{}
comment|// FIXME: This can be removed when the attr propagation fix for templated
comment|//        classes lands.
comment|/// \brief Warn about return typestates set for unconsumable types.
comment|///
comment|/// \param Loc -- The location of the attributes.
comment|///
comment|/// \param TypeName -- The name of the unconsumable type.
name|virtual
name|void
name|warnReturnTypestateForUnconsumableType
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|TypeName
parameter_list|)
block|{}
comment|/// \brief Warn about return typestate mismatches.
comment|///
comment|/// \param Loc -- The SourceLocation of the return statement.
comment|///
comment|/// \param ExpectedState -- The state the return value was expected to be
comment|/// in.
comment|///
comment|/// \param ObservedState -- The state the return value was observed to be
comment|/// in.
name|virtual
name|void
name|warnReturnTypestateMismatch
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|ExpectedState
parameter_list|,
name|StringRef
name|ObservedState
parameter_list|)
block|{}
comment|/// \brief Warn about use-while-consumed errors.
comment|/// \param MethodName -- The name of the method that was incorrectly
comment|/// invoked.
comment|///
comment|/// \param State -- The state the object was used in.
comment|///
comment|/// \param Loc -- The SourceLocation of the method invocation.
name|virtual
name|void
name|warnUseOfTempInInvalidState
parameter_list|(
name|StringRef
name|MethodName
parameter_list|,
name|StringRef
name|State
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
block|{}
comment|/// \brief Warn about use-while-consumed errors.
comment|/// \param MethodName -- The name of the method that was incorrectly
comment|/// invoked.
comment|///
comment|/// \param State -- The state the object was used in.
comment|///
comment|/// \param VariableName -- The name of the variable that holds the unique
comment|/// value.
comment|///
comment|/// \param Loc -- The SourceLocation of the method invocation.
name|virtual
name|void
name|warnUseInInvalidState
parameter_list|(
name|StringRef
name|MethodName
parameter_list|,
name|StringRef
name|VariableName
parameter_list|,
name|StringRef
name|State
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|)
block|{}
block|}
empty_stmt|;
name|class
name|ConsumedStateMap
block|{
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|VarDecl
operator|*
operator|,
name|ConsumedState
operator|>
name|VarMapType
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXBindTemporaryExpr
operator|*
operator|,
name|ConsumedState
operator|>
name|TmpMapType
expr_stmt|;
name|protected
label|:
name|bool
name|Reachable
decl_stmt|;
specifier|const
name|Stmt
modifier|*
name|From
decl_stmt|;
name|VarMapType
name|VarMap
decl_stmt|;
name|TmpMapType
name|TmpMap
decl_stmt|;
name|public
label|:
name|ConsumedStateMap
argument_list|()
operator|:
name|Reachable
argument_list|(
name|true
argument_list|)
operator|,
name|From
argument_list|(
argument|NULL
argument_list|)
block|{}
name|ConsumedStateMap
argument_list|(
specifier|const
name|ConsumedStateMap
operator|&
name|Other
argument_list|)
operator|:
name|Reachable
argument_list|(
name|Other
operator|.
name|Reachable
argument_list|)
operator|,
name|From
argument_list|(
name|Other
operator|.
name|From
argument_list|)
operator|,
name|VarMap
argument_list|(
name|Other
operator|.
name|VarMap
argument_list|)
operator|,
name|TmpMap
argument_list|()
block|{}
comment|/// \brief Warn if any of the parameters being tracked are not in the state
comment|/// they were declared to be in upon return from a function.
name|void
name|checkParamsForReturnTypestate
argument_list|(
argument|SourceLocation BlameLoc
argument_list|,
argument|ConsumedWarningsHandlerBase&WarningsHandler
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Clear the TmpMap.
name|void
name|clearTemporaries
parameter_list|()
function_decl|;
comment|/// \brief Get the consumed state of a given variable.
name|ConsumedState
name|getState
argument_list|(
specifier|const
name|VarDecl
operator|*
name|Var
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the consumed state of a given temporary value.
name|ConsumedState
name|getState
argument_list|(
specifier|const
name|CXXBindTemporaryExpr
operator|*
name|Tmp
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Merge this state map with another map.
name|void
name|intersect
parameter_list|(
specifier|const
name|ConsumedStateMap
modifier|*
name|Other
parameter_list|)
function_decl|;
name|void
name|intersectAtLoopHead
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|LoopHead
parameter_list|,
specifier|const
name|CFGBlock
modifier|*
name|LoopBack
parameter_list|,
specifier|const
name|ConsumedStateMap
modifier|*
name|LoopBackStates
parameter_list|,
name|ConsumedWarningsHandlerBase
modifier|&
name|WarningsHandler
parameter_list|)
function_decl|;
comment|/// \brief Return true if this block is reachable.
name|bool
name|isReachable
argument_list|()
specifier|const
block|{
return|return
name|Reachable
return|;
block|}
comment|/// \brief Mark the block as unreachable.
name|void
name|markUnreachable
parameter_list|()
function_decl|;
comment|/// \brief Set the source for a decision about the branching of states.
comment|/// \param Source -- The statement that was the origin of a branching
comment|/// decision.
name|void
name|setSource
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|Source
parameter_list|)
block|{
name|this
operator|->
name|From
operator|=
name|Source
expr_stmt|;
block|}
comment|/// \brief Set the consumed state of a given variable.
name|void
name|setState
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|Var
parameter_list|,
name|ConsumedState
name|State
parameter_list|)
function_decl|;
comment|/// \brief Set the consumed state of a given temporary value.
name|void
name|setState
parameter_list|(
specifier|const
name|CXXBindTemporaryExpr
modifier|*
name|Tmp
parameter_list|,
name|ConsumedState
name|State
parameter_list|)
function_decl|;
comment|/// \brief Remove the variable from our state map.
name|void
name|remove
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|Var
parameter_list|)
function_decl|;
comment|/// \brief Tests to see if there is a mismatch in the states stored in two
comment|/// maps.
comment|///
comment|/// \param Other -- The second map to compare against.
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|ConsumedStateMap
operator|*
name|Other
operator|)
specifier|const
expr_stmt|;
block|}
empty_stmt|;
name|class
name|ConsumedBlockInfo
block|{
name|std
operator|::
name|vector
operator|<
name|ConsumedStateMap
operator|*
operator|>
name|StateMapsArray
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|unsigned
name|int
operator|>
name|VisitOrder
expr_stmt|;
name|public
label|:
name|ConsumedBlockInfo
argument_list|()
block|{ }
name|ConsumedBlockInfo
argument_list|(
argument|unsigned int NumBlocks
argument_list|,
argument|PostOrderCFGView *SortedGraph
argument_list|)
block|:
name|StateMapsArray
argument_list|(
name|NumBlocks
argument_list|,
literal|0
argument_list|)
operator|,
name|VisitOrder
argument_list|(
argument|NumBlocks
argument_list|,
literal|0
argument_list|)
block|{
name|unsigned
name|int
name|VisitOrderCounter
operator|=
literal|0
block|;
for|for
control|(
name|PostOrderCFGView
operator|::
name|iterator
name|BI
operator|=
name|SortedGraph
operator|->
name|begin
argument_list|()
operator|,
name|BE
operator|=
name|SortedGraph
operator|->
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
block|{
name|VisitOrder
index|[
operator|(
operator|*
name|BI
operator|)
operator|->
name|getBlockID
argument_list|()
index|]
operator|=
name|VisitOrderCounter
operator|++
expr_stmt|;
block|}
block|}
name|bool
name|allBackEdgesVisited
argument_list|(
specifier|const
name|CFGBlock
operator|*
name|CurrBlock
argument_list|,
specifier|const
name|CFGBlock
operator|*
name|TargetBlock
argument_list|)
expr_stmt|;
name|void
name|addInfo
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|Block
parameter_list|,
name|ConsumedStateMap
modifier|*
name|StateMap
parameter_list|,
name|bool
modifier|&
name|AlreadyOwned
parameter_list|)
function_decl|;
name|void
name|addInfo
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|Block
parameter_list|,
name|ConsumedStateMap
modifier|*
name|StateMap
parameter_list|)
function_decl|;
name|ConsumedStateMap
modifier|*
name|borrowInfo
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|Block
parameter_list|)
function_decl|;
name|void
name|discardInfo
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|Block
parameter_list|)
function_decl|;
name|ConsumedStateMap
modifier|*
name|getInfo
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|Block
parameter_list|)
function_decl|;
name|bool
name|isBackEdge
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|From
parameter_list|,
specifier|const
name|CFGBlock
modifier|*
name|To
parameter_list|)
function_decl|;
name|bool
name|isBackEdgeTarget
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|Block
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// A class that handles the analysis of uniqueness violations.
name|class
name|ConsumedAnalyzer
block|{
name|ConsumedBlockInfo
name|BlockInfo
decl_stmt|;
name|ConsumedStateMap
modifier|*
name|CurrStates
decl_stmt|;
name|ConsumedState
name|ExpectedReturnState
decl_stmt|;
name|void
name|determineExpectedReturnState
parameter_list|(
name|AnalysisDeclContext
modifier|&
name|AC
parameter_list|,
specifier|const
name|FunctionDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|bool
name|hasConsumableAttributes
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|bool
name|splitState
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|CurrBlock
parameter_list|,
specifier|const
name|ConsumedStmtVisitor
modifier|&
name|Visitor
parameter_list|)
function_decl|;
name|public
label|:
name|ConsumedWarningsHandlerBase
modifier|&
name|WarningsHandler
decl_stmt|;
name|ConsumedAnalyzer
argument_list|(
name|ConsumedWarningsHandlerBase
operator|&
name|WarningsHandler
argument_list|)
operator|:
name|WarningsHandler
argument_list|(
argument|WarningsHandler
argument_list|)
block|{}
name|ConsumedState
name|getExpectedReturnState
argument_list|()
specifier|const
block|{
return|return
name|ExpectedReturnState
return|;
block|}
comment|/// \brief Check a function's CFG for consumed violations.
comment|///
comment|/// We traverse the blocks in the CFG, keeping track of the state of each
comment|/// value who's type has uniquness annotations.  If methods are invoked in
comment|/// the wrong state a warning is issued.  Each block in the CFG is traversed
comment|/// exactly once.
name|void
name|run
parameter_list|(
name|AnalysisDeclContext
modifier|&
name|AC
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang::consumed
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

