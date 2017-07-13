begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CheckerManager.h - Static Analyzer Checker Manager -----*- C++ -*-===//
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
comment|// Defines the Static Analyzer Checker Manager.
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
name|LLVM_CLANG_STATICANALYZER_CORE_CHECKERMANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_CHECKERMANAGER_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/ProgramPoint.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/AnalyzerOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/Store.h"
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

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|CallExpr
decl_stmt|;
name|namespace
name|ento
block|{
name|class
name|CheckerBase
decl_stmt|;
name|class
name|CheckerRegistry
decl_stmt|;
name|class
name|ExprEngine
decl_stmt|;
name|class
name|AnalysisManager
decl_stmt|;
name|class
name|BugReporter
decl_stmt|;
name|class
name|CheckerContext
decl_stmt|;
name|class
name|ObjCMethodCall
decl_stmt|;
name|class
name|SVal
decl_stmt|;
name|class
name|ExplodedNode
decl_stmt|;
name|class
name|ExplodedNodeSet
decl_stmt|;
name|class
name|ExplodedGraph
decl_stmt|;
name|class
name|ProgramState
decl_stmt|;
name|class
name|NodeBuilder
decl_stmt|;
struct_decl|struct
name|NodeBuilderContext
struct_decl|;
name|class
name|MemRegion
decl_stmt|;
name|class
name|SymbolReaper
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|CheckerFn
expr_stmt|;
name|template
operator|<
name|typename
name|RET
operator|,
name|typename
operator|...
name|Ps
operator|>
name|class
name|CheckerFn
operator|<
name|RET
argument_list|(
name|Ps
operator|...
argument_list|)
operator|>
block|{
typedef|typedef
name|RET
function_decl|(
modifier|*
name|Func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|Ps
modifier|...
parameter_list|)
function_decl|;
name|Func
name|Fn
expr_stmt|;
name|public
label|:
name|CheckerBase
modifier|*
name|Checker
decl_stmt|;
name|CheckerFn
argument_list|(
argument|CheckerBase *checker
argument_list|,
argument|Func fn
argument_list|)
block|:
name|Fn
argument_list|(
name|fn
argument_list|)
operator|,
name|Checker
argument_list|(
argument|checker
argument_list|)
block|{ }
name|RET
name|operator
argument_list|()
operator|(
name|Ps
operator|...
name|ps
operator|)
specifier|const
block|{
return|return
name|Fn
argument_list|(
name|Checker
argument_list|,
name|ps
operator|...
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Describes the different reasons a pointer escapes
comment|/// during analysis.
enum|enum
name|PointerEscapeKind
block|{
comment|/// A pointer escapes due to binding its value to a location
comment|/// that the analyzer cannot track.
name|PSK_EscapeOnBind
block|,
comment|/// The pointer has been passed to a function call directly.
name|PSK_DirectEscapeOnCall
block|,
comment|/// The pointer has been passed to a function indirectly.
comment|/// For example, the pointer is accessible through an
comment|/// argument to a function.
name|PSK_IndirectEscapeOnCall
block|,
comment|/// The reason for pointer escape is unknown. For example,
comment|/// a region containing this pointer is invalidated.
name|PSK_EscapeOther
block|}
enum|;
comment|// This wrapper is used to ensure that only StringRefs originating from the
comment|// CheckerRegistry are used as check names. We want to make sure all check
comment|// name strings have a lifetime that keeps them alive at least until the path
comment|// diagnostics have been processed.
name|class
name|CheckName
block|{
name|StringRef
name|Name
decl_stmt|;
name|friend
name|class
operator|::
name|clang
operator|::
name|ento
operator|::
name|CheckerRegistry
expr_stmt|;
name|explicit
name|CheckName
argument_list|(
argument|StringRef Name
argument_list|)
block|:
name|Name
argument_list|(
argument|Name
argument_list|)
block|{}
name|public
label|:
name|CheckName
argument_list|()
operator|=
expr|default
expr_stmt|;
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
block|}
empty_stmt|;
name|enum
name|class
name|ObjCMessageVisitKind
block|{
name|Pre
operator|,
name|Post
operator|,
name|MessageNil
block|}
empty_stmt|;
name|class
name|CheckerManager
block|{
specifier|const
name|LangOptions
name|LangOpts
decl_stmt|;
name|AnalyzerOptions
modifier|&
name|AOptions
decl_stmt|;
name|CheckName
name|CurrentCheckName
decl_stmt|;
name|public
label|:
name|CheckerManager
argument_list|(
specifier|const
name|LangOptions
operator|&
name|langOpts
argument_list|,
name|AnalyzerOptions
operator|&
name|AOptions
argument_list|)
operator|:
name|LangOpts
argument_list|(
name|langOpts
argument_list|)
operator|,
name|AOptions
argument_list|(
argument|AOptions
argument_list|)
block|{}
operator|~
name|CheckerManager
argument_list|()
expr_stmt|;
name|void
name|setCurrentCheckName
parameter_list|(
name|CheckName
name|name
parameter_list|)
block|{
name|CurrentCheckName
operator|=
name|name
expr_stmt|;
block|}
name|CheckName
name|getCurrentCheckName
argument_list|()
specifier|const
block|{
return|return
name|CurrentCheckName
return|;
block|}
name|bool
name|hasPathSensitiveCheckers
argument_list|()
specifier|const
expr_stmt|;
name|void
name|finishedCheckerRegistration
parameter_list|()
function_decl|;
specifier|const
name|LangOptions
operator|&
name|getLangOpts
argument_list|()
specifier|const
block|{
return|return
name|LangOpts
return|;
block|}
name|AnalyzerOptions
modifier|&
name|getAnalyzerOptions
parameter_list|()
block|{
return|return
name|AOptions
return|;
block|}
typedef|typedef
name|CheckerBase
modifier|*
name|CheckerRef
typedef|;
typedef|typedef
specifier|const
name|void
modifier|*
name|CheckerTag
typedef|;
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|()
operator|>
name|CheckerDtor
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// registerChecker
comment|//===----------------------------------------------------------------------===//
comment|/// \brief Used to register checkers.
comment|///
comment|/// \returns a pointer to the checker object.
name|template
operator|<
name|typename
name|CHECKER
operator|>
name|CHECKER
operator|*
name|registerChecker
argument_list|()
block|{
name|CheckerTag
name|tag
operator|=
name|getTag
operator|<
name|CHECKER
operator|>
operator|(
operator|)
block|;
name|CheckerRef
operator|&
name|ref
operator|=
name|CheckerTags
index|[
name|tag
index|]
block|;
if|if
condition|(
name|ref
condition|)
return|return
name|static_cast
operator|<
name|CHECKER
operator|*
operator|>
operator|(
name|ref
operator|)
return|;
comment|// already registered.
name|CHECKER
operator|*
name|checker
operator|=
name|new
name|CHECKER
argument_list|()
expr_stmt|;
name|checker
operator|->
name|Name
operator|=
name|CurrentCheckName
expr_stmt|;
name|CheckerDtors
operator|.
name|push_back
argument_list|(
name|CheckerDtor
argument_list|(
name|checker
argument_list|,
name|destruct
operator|<
name|CHECKER
operator|>
argument_list|)
argument_list|)
expr_stmt|;
name|CHECKER
operator|::
name|_register
argument_list|(
name|checker
argument_list|,
operator|*
name|this
argument_list|)
expr_stmt|;
name|ref
operator|=
name|checker
expr_stmt|;
return|return
name|checker
return|;
block|}
name|template
operator|<
name|typename
name|CHECKER
operator|>
name|CHECKER
operator|*
name|registerChecker
argument_list|(
argument|AnalyzerOptions&AOpts
argument_list|)
block|{
name|CheckerTag
name|tag
operator|=
name|getTag
operator|<
name|CHECKER
operator|>
operator|(
operator|)
block|;
name|CheckerRef
operator|&
name|ref
operator|=
name|CheckerTags
index|[
name|tag
index|]
block|;
if|if
condition|(
name|ref
condition|)
return|return
name|static_cast
operator|<
name|CHECKER
operator|*
operator|>
operator|(
name|ref
operator|)
return|;
comment|// already registered.
name|CHECKER
operator|*
name|checker
operator|=
name|new
name|CHECKER
argument_list|(
name|AOpts
argument_list|)
expr_stmt|;
name|checker
operator|->
name|Name
operator|=
name|CurrentCheckName
expr_stmt|;
name|CheckerDtors
operator|.
name|push_back
argument_list|(
name|CheckerDtor
argument_list|(
name|checker
argument_list|,
name|destruct
operator|<
name|CHECKER
operator|>
argument_list|)
argument_list|)
expr_stmt|;
name|CHECKER
operator|::
name|_register
argument_list|(
name|checker
argument_list|,
operator|*
name|this
argument_list|)
expr_stmt|;
name|ref
operator|=
name|checker
expr_stmt|;
return|return
name|checker
return|;
block|}
end_decl_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Functions for running checkers for AST traversing..
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief Run checkers handling Decls.
end_comment

begin_function_decl
name|void
name|runCheckersOnASTDecl
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
name|AnalysisManager
modifier|&
name|mgr
parameter_list|,
name|BugReporter
modifier|&
name|BR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers handling Decls containing a Stmt body.
end_comment

begin_function_decl
name|void
name|runCheckersOnASTBody
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
name|AnalysisManager
modifier|&
name|mgr
parameter_list|,
name|BugReporter
modifier|&
name|BR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Functions for running checkers for path-sensitive checking.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief Run checkers for pre-visiting Stmts.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The notification is performed for every explored CFGElement, which does
end_comment

begin_comment
comment|/// not include the control flow statements such as IfStmt.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \sa runCheckersForBranchCondition, runCheckersForPostStmt
end_comment

begin_function
name|void
name|runCheckersForPreStmt
parameter_list|(
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
block|{
name|runCheckersForStmt
argument_list|(
comment|/*isPreVisit=*/
name|true
argument_list|,
name|Dst
argument_list|,
name|Src
argument_list|,
name|S
argument_list|,
name|Eng
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Run checkers for post-visiting Stmts.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The notification is performed for every explored CFGElement, which does
end_comment

begin_comment
comment|/// not include the control flow statements such as IfStmt.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \sa runCheckersForBranchCondition, runCheckersForPreStmt
end_comment

begin_function
name|void
name|runCheckersForPostStmt
parameter_list|(
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|,
name|bool
name|wasInlined
init|=
name|false
parameter_list|)
block|{
name|runCheckersForStmt
argument_list|(
comment|/*isPreVisit=*/
name|false
argument_list|,
name|Dst
argument_list|,
name|Src
argument_list|,
name|S
argument_list|,
name|Eng
argument_list|,
name|wasInlined
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Run checkers for visiting Stmts.
end_comment

begin_function_decl
name|void
name|runCheckersForStmt
parameter_list|(
name|bool
name|isPreVisit
parameter_list|,
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|,
name|bool
name|wasInlined
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers for pre-visiting obj-c messages.
end_comment

begin_function
name|void
name|runCheckersForPreObjCMessage
parameter_list|(
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
specifier|const
name|ObjCMethodCall
modifier|&
name|msg
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
block|{
name|runCheckersForObjCMessage
argument_list|(
name|ObjCMessageVisitKind
operator|::
name|Pre
argument_list|,
name|Dst
argument_list|,
name|Src
argument_list|,
name|msg
argument_list|,
name|Eng
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Run checkers for post-visiting obj-c messages.
end_comment

begin_function
name|void
name|runCheckersForPostObjCMessage
parameter_list|(
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
specifier|const
name|ObjCMethodCall
modifier|&
name|msg
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|,
name|bool
name|wasInlined
init|=
name|false
parameter_list|)
block|{
name|runCheckersForObjCMessage
argument_list|(
name|ObjCMessageVisitKind
operator|::
name|Post
argument_list|,
name|Dst
argument_list|,
name|Src
argument_list|,
name|msg
argument_list|,
name|Eng
argument_list|,
name|wasInlined
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Run checkers for visiting an obj-c message to nil.
end_comment

begin_function
name|void
name|runCheckersForObjCMessageNil
parameter_list|(
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
specifier|const
name|ObjCMethodCall
modifier|&
name|msg
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
block|{
name|runCheckersForObjCMessage
argument_list|(
name|ObjCMessageVisitKind
operator|::
name|MessageNil
argument_list|,
name|Dst
argument_list|,
name|Src
argument_list|,
name|msg
argument_list|,
name|Eng
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Run checkers for visiting obj-c messages.
end_comment

begin_function_decl
name|void
name|runCheckersForObjCMessage
parameter_list|(
name|ObjCMessageVisitKind
name|visitKind
parameter_list|,
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
specifier|const
name|ObjCMethodCall
modifier|&
name|msg
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|,
name|bool
name|wasInlined
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers for pre-visiting obj-c messages.
end_comment

begin_function
name|void
name|runCheckersForPreCall
parameter_list|(
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
specifier|const
name|CallEvent
modifier|&
name|Call
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
block|{
name|runCheckersForCallEvent
argument_list|(
comment|/*isPreVisit=*/
name|true
argument_list|,
name|Dst
argument_list|,
name|Src
argument_list|,
name|Call
argument_list|,
name|Eng
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Run checkers for post-visiting obj-c messages.
end_comment

begin_function
name|void
name|runCheckersForPostCall
parameter_list|(
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
specifier|const
name|CallEvent
modifier|&
name|Call
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|,
name|bool
name|wasInlined
init|=
name|false
parameter_list|)
block|{
name|runCheckersForCallEvent
argument_list|(
comment|/*isPreVisit=*/
name|false
argument_list|,
name|Dst
argument_list|,
name|Src
argument_list|,
name|Call
argument_list|,
name|Eng
argument_list|,
name|wasInlined
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Run checkers for visiting obj-c messages.
end_comment

begin_function_decl
name|void
name|runCheckersForCallEvent
parameter_list|(
name|bool
name|isPreVisit
parameter_list|,
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
specifier|const
name|CallEvent
modifier|&
name|Call
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|,
name|bool
name|wasInlined
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers for load/store of a location.
end_comment

begin_function_decl
name|void
name|runCheckersForLocation
parameter_list|(
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
name|SVal
name|location
parameter_list|,
name|bool
name|isLoad
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|NodeEx
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|BoundEx
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers for binding of a value to a location.
end_comment

begin_function_decl
name|void
name|runCheckersForBind
parameter_list|(
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
name|SVal
name|location
parameter_list|,
name|SVal
name|val
parameter_list|,
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|,
specifier|const
name|ProgramPoint
modifier|&
name|PP
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers for end of analysis.
end_comment

begin_function_decl
name|void
name|runCheckersForEndAnalysis
parameter_list|(
name|ExplodedGraph
modifier|&
name|G
parameter_list|,
name|BugReporter
modifier|&
name|BR
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers on beginning of function.
end_comment

begin_function_decl
name|void
name|runCheckersForBeginFunction
parameter_list|(
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|BlockEdge
modifier|&
name|L
parameter_list|,
name|ExplodedNode
modifier|*
name|Pred
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers on end of function.
end_comment

begin_function_decl
name|void
name|runCheckersForEndFunction
parameter_list|(
name|NodeBuilderContext
modifier|&
name|BC
parameter_list|,
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
name|ExplodedNode
modifier|*
name|Pred
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers for branch condition.
end_comment

begin_function_decl
name|void
name|runCheckersForBranchCondition
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|condition
parameter_list|,
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
name|ExplodedNode
modifier|*
name|Pred
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers for live symbols.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Allows modifying SymbolReaper object. For example, checkers can explicitly
end_comment

begin_comment
comment|/// register symbols of interest as live. These symbols will not be marked
end_comment

begin_comment
comment|/// dead and removed.
end_comment

begin_function_decl
name|void
name|runCheckersForLiveSymbols
parameter_list|(
name|ProgramStateRef
name|state
parameter_list|,
name|SymbolReaper
modifier|&
name|SymReaper
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers for dead symbols.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Notifies checkers when symbols become dead. For example, this allows
end_comment

begin_comment
comment|/// checkers to aggressively clean up/reduce the checker state and produce
end_comment

begin_comment
comment|/// precise diagnostics.
end_comment

begin_decl_stmt
name|void
name|runCheckersForDeadSymbols
argument_list|(
name|ExplodedNodeSet
operator|&
name|Dst
argument_list|,
specifier|const
name|ExplodedNodeSet
operator|&
name|Src
argument_list|,
name|SymbolReaper
operator|&
name|SymReaper
argument_list|,
specifier|const
name|Stmt
operator|*
name|S
argument_list|,
name|ExprEngine
operator|&
name|Eng
argument_list|,
name|ProgramPoint
operator|::
name|Kind
name|K
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Run checkers for region changes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This corresponds to the check::RegionChanges callback.
end_comment

begin_comment
comment|/// \param state The current program state.
end_comment

begin_comment
comment|/// \param invalidated A set of all symbols potentially touched by the change.
end_comment

begin_comment
comment|/// \param ExplicitRegions The regions explicitly requested for invalidation.
end_comment

begin_comment
comment|///   For example, in the case of a function call, these would be arguments.
end_comment

begin_comment
comment|/// \param Regions The transitive closure of accessible regions,
end_comment

begin_comment
comment|///   i.e. all regions that may have been touched by this change.
end_comment

begin_comment
comment|/// \param Call The call expression wrapper if the regions are invalidated
end_comment

begin_comment
comment|///   by a call.
end_comment

begin_decl_stmt
name|ProgramStateRef
name|runCheckersForRegionChanges
argument_list|(
name|ProgramStateRef
name|state
argument_list|,
specifier|const
name|InvalidatedSymbols
operator|*
name|invalidated
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|MemRegion
operator|*
operator|>
name|ExplicitRegions
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|MemRegion
operator|*
operator|>
name|Regions
argument_list|,
specifier|const
name|LocationContext
operator|*
name|LCtx
argument_list|,
specifier|const
name|CallEvent
operator|*
name|Call
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Run checkers when pointers escape.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This notifies the checkers about pointer escape, which occurs whenever
end_comment

begin_comment
comment|/// the analyzer cannot track the symbol any more. For example, as a
end_comment

begin_comment
comment|/// result of assigning a pointer into a global or when it's passed to a
end_comment

begin_comment
comment|/// function call the analyzer cannot model.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param State The state at the point of escape.
end_comment

begin_comment
comment|/// \param Escaped The list of escaped symbols.
end_comment

begin_comment
comment|/// \param Call The corresponding CallEvent, if the symbols escape as
end_comment

begin_comment
comment|///        parameters to the given call.
end_comment

begin_comment
comment|/// \param Kind The reason of pointer escape.
end_comment

begin_comment
comment|/// \param ITraits Information about invalidation for a particular
end_comment

begin_comment
comment|///        region/symbol.
end_comment

begin_comment
comment|/// \returns Checkers can modify the state by returning a new one.
end_comment

begin_function_decl
name|ProgramStateRef
name|runCheckersForPointerEscape
parameter_list|(
name|ProgramStateRef
name|State
parameter_list|,
specifier|const
name|InvalidatedSymbols
modifier|&
name|Escaped
parameter_list|,
specifier|const
name|CallEvent
modifier|*
name|Call
parameter_list|,
name|PointerEscapeKind
name|Kind
parameter_list|,
name|RegionAndSymbolInvalidationTraits
modifier|*
name|ITraits
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers for handling assumptions on symbolic values.
end_comment

begin_function_decl
name|ProgramStateRef
name|runCheckersForEvalAssume
parameter_list|(
name|ProgramStateRef
name|state
parameter_list|,
name|SVal
name|Cond
parameter_list|,
name|bool
name|Assumption
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers for evaluating a call.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Warning: Currently, the CallEvent MUST come from a CallExpr!
end_comment

begin_function_decl
name|void
name|runCheckersForEvalCall
parameter_list|(
name|ExplodedNodeSet
modifier|&
name|Dst
parameter_list|,
specifier|const
name|ExplodedNodeSet
modifier|&
name|Src
parameter_list|,
specifier|const
name|CallEvent
modifier|&
name|CE
parameter_list|,
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers for the entire Translation Unit.
end_comment

begin_function_decl
name|void
name|runCheckersOnEndOfTranslationUnit
parameter_list|(
specifier|const
name|TranslationUnitDecl
modifier|*
name|TU
parameter_list|,
name|AnalysisManager
modifier|&
name|mgr
parameter_list|,
name|BugReporter
modifier|&
name|BR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Run checkers for debug-printing a ProgramState.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Unlike most other callbacks, any checker can simply implement the virtual
end_comment

begin_comment
comment|/// method CheckerBase::printState if it has custom data to print.
end_comment

begin_comment
comment|/// \param Out The output stream
end_comment

begin_comment
comment|/// \param State The state being printed
end_comment

begin_comment
comment|/// \param NL The preferred representation of a newline.
end_comment

begin_comment
comment|/// \param Sep The preferred separator between different kinds of data.
end_comment

begin_function_decl
name|void
name|runCheckersForPrintState
parameter_list|(
name|raw_ostream
modifier|&
name|Out
parameter_list|,
name|ProgramStateRef
name|State
parameter_list|,
specifier|const
name|char
modifier|*
name|NL
parameter_list|,
specifier|const
name|char
modifier|*
name|Sep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Internal registration functions for AST traversing.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Functions used by the registration mechanism, checkers should not touch
end_comment

begin_comment
comment|// these directly.
end_comment

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
specifier|const
name|Decl
operator|*
argument_list|,
name|AnalysisManager
operator|&
argument_list|,
name|BugReporter
operator|&
argument_list|)
operator|>
name|CheckDeclFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|HandlesDeclFunc
function_decl|)
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|_registerForDecl
parameter_list|(
name|CheckDeclFunc
name|checkfn
parameter_list|,
name|HandlesDeclFunc
name|isForDeclFn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForBody
parameter_list|(
name|CheckDeclFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Internal registration functions for path-sensitive checking.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
specifier|const
name|Stmt
operator|*
argument_list|,
name|CheckerContext
operator|&
argument_list|)
operator|>
name|CheckStmtFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
specifier|const
name|ObjCMethodCall
operator|&
argument_list|,
name|CheckerContext
operator|&
argument_list|)
operator|>
name|CheckObjCMessageFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
specifier|const
name|CallEvent
operator|&
argument_list|,
name|CheckerContext
operator|&
argument_list|)
operator|>
name|CheckCallFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
argument|const SVal&location
argument_list|,
argument|bool isLoad
argument_list|,
argument|const Stmt *S
argument_list|,
argument|CheckerContext&
argument_list|)
operator|>
name|CheckLocationFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
specifier|const
name|SVal
operator|&
name|location
argument_list|,
specifier|const
name|SVal
operator|&
name|val
argument_list|,
specifier|const
name|Stmt
operator|*
name|S
argument_list|,
name|CheckerContext
operator|&
argument_list|)
operator|>
name|CheckBindFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
name|ExplodedGraph
operator|&
argument_list|,
name|BugReporter
operator|&
argument_list|,
name|ExprEngine
operator|&
argument_list|)
operator|>
name|CheckEndAnalysisFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
name|CheckerContext
operator|&
argument_list|)
operator|>
name|CheckBeginFunctionFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
name|CheckerContext
operator|&
argument_list|)
operator|>
name|CheckEndFunctionFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
specifier|const
name|Stmt
operator|*
argument_list|,
name|CheckerContext
operator|&
argument_list|)
operator|>
name|CheckBranchConditionFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
name|SymbolReaper
operator|&
argument_list|,
name|CheckerContext
operator|&
argument_list|)
operator|>
name|CheckDeadSymbolsFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
name|ProgramStateRef
argument_list|,
name|SymbolReaper
operator|&
argument_list|)
operator|>
name|CheckLiveSymbolsFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|ProgramStateRef
argument_list|(
name|ProgramStateRef
argument_list|,
specifier|const
name|InvalidatedSymbols
operator|*
name|symbols
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|MemRegion
operator|*
operator|>
name|ExplicitRegions
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|MemRegion
operator|*
operator|>
name|Regions
argument_list|,
specifier|const
name|LocationContext
operator|*
name|LCtx
argument_list|,
specifier|const
name|CallEvent
operator|*
name|Call
argument_list|)
operator|>
name|CheckRegionChangesFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|ProgramStateRef
argument_list|(
argument|ProgramStateRef
argument_list|,
argument|const InvalidatedSymbols&Escaped
argument_list|,
argument|const CallEvent *Call
argument_list|,
argument|PointerEscapeKind Kind
argument_list|,
argument|RegionAndSymbolInvalidationTraits *ITraits
argument_list|)
operator|>
name|CheckPointerEscapeFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|ProgramStateRef
argument_list|(
argument|ProgramStateRef
argument_list|,
argument|const SVal&cond
argument_list|,
argument|bool assumption
argument_list|)
operator|>
name|EvalAssumeFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|bool
argument_list|(
specifier|const
name|CallExpr
operator|*
argument_list|,
name|CheckerContext
operator|&
argument_list|)
operator|>
name|EvalCallFunc
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
specifier|const
name|TranslationUnitDecl
operator|*
argument_list|,
name|AnalysisManager
operator|&
argument_list|,
name|BugReporter
operator|&
argument_list|)
operator|>
name|CheckEndOfTranslationUnit
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|HandlesStmtFunc
function_decl|)
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|D
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|_registerForPreStmt
parameter_list|(
name|CheckStmtFunc
name|checkfn
parameter_list|,
name|HandlesStmtFunc
name|isForStmtFn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForPostStmt
parameter_list|(
name|CheckStmtFunc
name|checkfn
parameter_list|,
name|HandlesStmtFunc
name|isForStmtFn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForPreObjCMessage
parameter_list|(
name|CheckObjCMessageFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForPostObjCMessage
parameter_list|(
name|CheckObjCMessageFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForObjCMessageNil
parameter_list|(
name|CheckObjCMessageFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForPreCall
parameter_list|(
name|CheckCallFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForPostCall
parameter_list|(
name|CheckCallFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForLocation
parameter_list|(
name|CheckLocationFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForBind
parameter_list|(
name|CheckBindFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForEndAnalysis
parameter_list|(
name|CheckEndAnalysisFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForBeginFunction
parameter_list|(
name|CheckEndFunctionFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForEndFunction
parameter_list|(
name|CheckEndFunctionFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForBranchCondition
parameter_list|(
name|CheckBranchConditionFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForLiveSymbols
parameter_list|(
name|CheckLiveSymbolsFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForDeadSymbols
parameter_list|(
name|CheckDeadSymbolsFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForRegionChanges
parameter_list|(
name|CheckRegionChangesFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForPointerEscape
parameter_list|(
name|CheckPointerEscapeFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForConstPointerEscape
parameter_list|(
name|CheckPointerEscapeFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForEvalAssume
parameter_list|(
name|EvalAssumeFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForEvalCall
parameter_list|(
name|EvalCallFunc
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_registerForEndOfTranslationUnit
parameter_list|(
name|CheckEndOfTranslationUnit
name|checkfn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Internal registration functions for events.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|EventTag
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CheckerFn
operator|<
name|void
argument_list|(
specifier|const
name|void
operator|*
name|event
argument_list|)
operator|>
name|CheckEventFunc
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|typename
name|EVENT
operator|>
name|void
name|_registerListenerForEvent
argument_list|(
argument|CheckEventFunc checkfn
argument_list|)
block|{
name|EventInfo
operator|&
name|info
operator|=
name|Events
index|[
name|getTag
operator|<
name|EVENT
operator|>
operator|(
operator|)
index|]
block|;
name|info
operator|.
name|Checkers
operator|.
name|push_back
argument_list|(
name|checkfn
argument_list|)
block|;       }
name|template
operator|<
name|typename
name|EVENT
operator|>
name|void
name|_registerDispatcherForEvent
argument_list|()
block|{
name|EventInfo
operator|&
name|info
operator|=
name|Events
index|[
name|getTag
operator|<
name|EVENT
operator|>
operator|(
operator|)
index|]
block|;
name|info
operator|.
name|HasDispatcher
operator|=
name|true
block|;   }
name|template
operator|<
name|typename
name|EVENT
operator|>
name|void
name|_dispatchEvent
argument_list|(
argument|const EVENT&event
argument_list|)
specifier|const
block|{
name|EventsTy
operator|::
name|const_iterator
name|I
operator|=
name|Events
operator|.
name|find
argument_list|(
name|getTag
operator|<
name|EVENT
operator|>
operator|(
operator|)
argument_list|)
block|;
if|if
condition|(
name|I
operator|==
name|Events
operator|.
name|end
argument_list|()
condition|)
return|return;
specifier|const
name|EventInfo
operator|&
name|info
operator|=
name|I
operator|->
name|second
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|info
operator|.
name|Checkers
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
name|info
operator|.
name|Checkers
index|[
name|i
index|]
operator|(
operator|&
name|event
operator|)
expr_stmt|;
end_for

begin_comment
unit|}
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Implementation details.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_expr_stmt
unit|private:
name|template
operator|<
name|typename
name|CHECKER
operator|>
specifier|static
name|void
name|destruct
argument_list|(
argument|void *obj
argument_list|)
block|{
name|delete
name|static_cast
operator|<
name|CHECKER
operator|*
operator|>
operator|(
name|obj
operator|)
block|; }
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|void
operator|*
name|getTag
argument_list|()
block|{
specifier|static
name|int
name|tag
block|;
return|return
operator|&
name|tag
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|DenseMap
operator|<
name|CheckerTag
operator|,
name|CheckerRef
operator|>
name|CheckerTags
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckerDtor
operator|>
name|CheckerDtors
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|DeclCheckerInfo
block|{
name|CheckDeclFunc
name|CheckFn
decl_stmt|;
name|HandlesDeclFunc
name|IsForDeclFn
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|DeclCheckerInfo
operator|>
name|DeclCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckDeclFunc
operator|>
name|BodyCheckers
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|SmallVector
operator|<
name|CheckDeclFunc
operator|,
literal|4
operator|>
name|CachedDeclCheckers
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|CachedDeclCheckers
operator|>
name|CachedDeclCheckersMapTy
expr_stmt|;
end_typedef

begin_decl_stmt
name|CachedDeclCheckersMapTy
name|CachedDeclCheckersMap
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|StmtCheckerInfo
block|{
name|CheckStmtFunc
name|CheckFn
decl_stmt|;
name|HandlesStmtFunc
name|IsForStmtFn
decl_stmt|;
name|bool
name|IsPreVisit
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|StmtCheckerInfo
operator|>
name|StmtCheckers
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|SmallVector
operator|<
name|CheckStmtFunc
operator|,
literal|4
operator|>
name|CachedStmtCheckers
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|unsigned
operator|,
name|CachedStmtCheckers
operator|>
name|CachedStmtCheckersMapTy
expr_stmt|;
end_typedef

begin_decl_stmt
name|CachedStmtCheckersMapTy
name|CachedStmtCheckersMap
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|const
name|CachedStmtCheckers
modifier|&
name|getCachedStmtCheckersFor
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|,
name|bool
name|isPreVisit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Returns the checkers that have registered for callbacks of the
end_comment

begin_comment
comment|/// given \p Kind.
end_comment

begin_expr_stmt
specifier|const
name|std
operator|::
name|vector
operator|<
name|CheckObjCMessageFunc
operator|>
operator|&
name|getObjCMessageCheckers
argument_list|(
argument|ObjCMessageVisitKind Kind
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckObjCMessageFunc
operator|>
name|PreObjCMessageCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckObjCMessageFunc
operator|>
name|PostObjCMessageCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckObjCMessageFunc
operator|>
name|ObjCMessageNilCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckCallFunc
operator|>
name|PreCallCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckCallFunc
operator|>
name|PostCallCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckLocationFunc
operator|>
name|LocationCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckBindFunc
operator|>
name|BindCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckEndAnalysisFunc
operator|>
name|EndAnalysisCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckBeginFunctionFunc
operator|>
name|BeginFunctionCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckEndFunctionFunc
operator|>
name|EndFunctionCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckBranchConditionFunc
operator|>
name|BranchConditionCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckLiveSymbolsFunc
operator|>
name|LiveSymbolsCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckDeadSymbolsFunc
operator|>
name|DeadSymbolsCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckRegionChangesFunc
operator|>
name|RegionChangesCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckPointerEscapeFunc
operator|>
name|PointerEscapeCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|EvalAssumeFunc
operator|>
name|EvalAssumeCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|EvalCallFunc
operator|>
name|EvalCallCheckers
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|CheckEndOfTranslationUnit
operator|>
name|EndOfTranslationUnitCheckers
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|EventInfo
block|{
name|SmallVector
operator|<
name|CheckEventFunc
operator|,
literal|4
operator|>
name|Checkers
expr_stmt|;
name|bool
name|HasDispatcher
decl_stmt|;
name|EventInfo
argument_list|()
operator|:
name|HasDispatcher
argument_list|(
argument|false
argument_list|)
block|{ }
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|EventTag
operator|,
name|EventInfo
operator|>
name|EventsTy
expr_stmt|;
end_typedef

begin_decl_stmt
name|EventsTy
name|Events
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// end ento namespace
end_comment

begin_comment
unit|}
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

