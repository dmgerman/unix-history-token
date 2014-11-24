begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== CheckerContext.h - Context info for path-sensitive checkers--*- C++ -*--=//
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
comment|//  This file defines CheckerContext that provides contextual info for
end_comment

begin_comment
comment|// path-sensitive checkers.
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
name|LLVM_CLANG_SA_CORE_PATHSENSITIVE_CHECKERCONTEXT
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SA_CORE_PATHSENSITIVE_CHECKERCONTEXT
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ExprEngine.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ProgramStateTrait.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
comment|/// Declares an immutable map of type \p NameTy, suitable for placement into
comment|/// the ProgramState. This is implementing using llvm::ImmutableMap.
comment|///
comment|/// \code
comment|/// State = State->set<Name>(K, V);
comment|/// const Value *V = State->get<Name>(K); // Returns NULL if not in the map.
comment|/// State = State->remove<Name>(K);
comment|/// NameTy Map = State->get<Name>();
comment|/// \endcode
comment|///
comment|/// The macro should not be used inside namespaces, or for traits that must
comment|/// be accessible from more than one translation unit.
define|#
directive|define
name|REGISTER_MAP_WITH_PROGRAMSTATE
parameter_list|(
name|Name
parameter_list|,
name|Key
parameter_list|,
name|Value
parameter_list|)
define|\
value|REGISTER_TRAIT_WITH_PROGRAMSTATE(Name, \                                      CLANG_ENTO_PROGRAMSTATE_MAP(Key, Value))
comment|/// Declares an immutable set of type \p NameTy, suitable for placement into
comment|/// the ProgramState. This is implementing using llvm::ImmutableSet.
comment|///
comment|/// \code
comment|/// State = State->add<Name>(E);
comment|/// State = State->remove<Name>(E);
comment|/// bool Present = State->contains<Name>(E);
comment|/// NameTy Set = State->get<Name>();
comment|/// \endcode
comment|///
comment|/// The macro should not be used inside namespaces, or for traits that must
comment|/// be accessible from more than one translation unit.
define|#
directive|define
name|REGISTER_SET_WITH_PROGRAMSTATE
parameter_list|(
name|Name
parameter_list|,
name|Elem
parameter_list|)
define|\
value|REGISTER_TRAIT_WITH_PROGRAMSTATE(Name, llvm::ImmutableSet<Elem>)
comment|/// Declares an immutable list of type \p NameTy, suitable for placement into
comment|/// the ProgramState. This is implementing using llvm::ImmutableList.
comment|///
comment|/// \code
comment|/// State = State->add<Name>(E); // Adds to the /end/ of the list.
comment|/// bool Present = State->contains<Name>(E);
comment|/// NameTy List = State->get<Name>();
comment|/// \endcode
comment|///
comment|/// The macro should not be used inside namespaces, or for traits that must
comment|/// be accessible from more than one translation unit.
define|#
directive|define
name|REGISTER_LIST_WITH_PROGRAMSTATE
parameter_list|(
name|Name
parameter_list|,
name|Elem
parameter_list|)
define|\
value|REGISTER_TRAIT_WITH_PROGRAMSTATE(Name, llvm::ImmutableList<Elem>)
name|class
name|CheckerContext
block|{
name|ExprEngine
modifier|&
name|Eng
decl_stmt|;
comment|/// The current exploded(symbolic execution) graph node.
name|ExplodedNode
modifier|*
name|Pred
decl_stmt|;
comment|/// The flag is true if the (state of the execution) has been modified
comment|/// by the checker using this context. For example, a new transition has been
comment|/// added or a bug report issued.
name|bool
name|Changed
decl_stmt|;
comment|/// The tagged location, which is used to generate all new nodes.
specifier|const
name|ProgramPoint
name|Location
decl_stmt|;
name|NodeBuilder
modifier|&
name|NB
decl_stmt|;
name|public
label|:
comment|/// If we are post visiting a call, this flag will be set if the
comment|/// call was inlined.  In all other cases it will be false.
specifier|const
name|bool
name|wasInlined
decl_stmt|;
name|CheckerContext
argument_list|(
argument|NodeBuilder&builder
argument_list|,
argument|ExprEngine&eng
argument_list|,
argument|ExplodedNode *pred
argument_list|,
argument|const ProgramPoint&loc
argument_list|,
argument|bool wasInlined = false
argument_list|)
block|:
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
name|Changed
argument_list|(
name|false
argument_list|)
operator|,
name|Location
argument_list|(
name|loc
argument_list|)
operator|,
name|NB
argument_list|(
name|builder
argument_list|)
operator|,
name|wasInlined
argument_list|(
argument|wasInlined
argument_list|)
block|{
name|assert
argument_list|(
name|Pred
operator|->
name|getState
argument_list|()
operator|&&
literal|"We should not call the checkers on an empty state."
argument_list|)
block|;   }
name|AnalysisManager
operator|&
name|getAnalysisManager
argument_list|()
block|{
return|return
name|Eng
operator|.
name|getAnalysisManager
argument_list|()
return|;
block|}
name|ConstraintManager
modifier|&
name|getConstraintManager
parameter_list|()
block|{
return|return
name|Eng
operator|.
name|getConstraintManager
argument_list|()
return|;
block|}
name|StoreManager
modifier|&
name|getStoreManager
parameter_list|()
block|{
return|return
name|Eng
operator|.
name|getStoreManager
argument_list|()
return|;
block|}
comment|/// \brief Returns the previous node in the exploded graph, which includes
comment|/// the state of the program before the checker ran. Note, checkers should
comment|/// not retain the node in their state since the nodes might get invalidated.
name|ExplodedNode
modifier|*
name|getPredecessor
parameter_list|()
block|{
return|return
name|Pred
return|;
block|}
specifier|const
name|ProgramStateRef
operator|&
name|getState
argument_list|()
specifier|const
block|{
return|return
name|Pred
operator|->
name|getState
argument_list|()
return|;
block|}
comment|/// \brief Check if the checker changed the state of the execution; ex: added
comment|/// a new transition or a bug report.
name|bool
name|isDifferent
parameter_list|()
block|{
return|return
name|Changed
return|;
block|}
comment|/// \brief Returns the number of times the current block has been visited
comment|/// along the analyzed path.
name|unsigned
name|blockCount
argument_list|()
specifier|const
block|{
return|return
name|NB
operator|.
name|getContext
argument_list|()
operator|.
name|blockCount
argument_list|()
return|;
block|}
name|ASTContext
modifier|&
name|getASTContext
parameter_list|()
block|{
return|return
name|Eng
operator|.
name|getContext
argument_list|()
return|;
block|}
specifier|const
name|LangOptions
operator|&
name|getLangOpts
argument_list|()
specifier|const
block|{
return|return
name|Eng
operator|.
name|getContext
argument_list|()
operator|.
name|getLangOpts
argument_list|()
return|;
block|}
specifier|const
name|LocationContext
operator|*
name|getLocationContext
argument_list|()
specifier|const
block|{
return|return
name|Pred
operator|->
name|getLocationContext
argument_list|()
return|;
block|}
specifier|const
name|StackFrameContext
operator|*
name|getStackFrame
argument_list|()
specifier|const
block|{
return|return
name|Pred
operator|->
name|getStackFrame
argument_list|()
return|;
block|}
comment|/// Return true if the current LocationContext has no caller context.
name|bool
name|inTopFrame
argument_list|()
specifier|const
block|{
return|return
name|getLocationContext
argument_list|()
operator|->
name|inTopFrame
argument_list|()
return|;
block|}
name|BugReporter
modifier|&
name|getBugReporter
parameter_list|()
block|{
return|return
name|Eng
operator|.
name|getBugReporter
argument_list|()
return|;
block|}
name|SourceManager
modifier|&
name|getSourceManager
parameter_list|()
block|{
return|return
name|getBugReporter
argument_list|()
operator|.
name|getSourceManager
argument_list|()
return|;
block|}
name|SValBuilder
modifier|&
name|getSValBuilder
parameter_list|()
block|{
return|return
name|Eng
operator|.
name|getSValBuilder
argument_list|()
return|;
block|}
name|SymbolManager
modifier|&
name|getSymbolManager
parameter_list|()
block|{
return|return
name|getSValBuilder
argument_list|()
operator|.
name|getSymbolManager
argument_list|()
return|;
block|}
name|bool
name|isObjCGCEnabled
argument_list|()
specifier|const
block|{
return|return
name|Eng
operator|.
name|isObjCGCEnabled
argument_list|()
return|;
block|}
name|ProgramStateManager
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
name|AnalysisDeclContext
operator|*
name|getCurrentAnalysisDeclContext
argument_list|()
specifier|const
block|{
return|return
name|Pred
operator|->
name|getLocationContext
argument_list|()
operator|->
name|getAnalysisDeclContext
argument_list|()
return|;
block|}
comment|/// \brief Get the blockID.
name|unsigned
name|getBlockID
argument_list|()
specifier|const
block|{
return|return
name|NB
operator|.
name|getContext
argument_list|()
operator|.
name|getBlock
argument_list|()
operator|->
name|getBlockID
argument_list|()
return|;
block|}
comment|/// \brief If the given node corresponds to a PostStore program point,
comment|/// retrieve the location region as it was uttered in the code.
comment|///
comment|/// This utility can be useful for generating extensive diagnostics, for
comment|/// example, for finding variables that the given symbol was assigned to.
specifier|static
specifier|const
name|MemRegion
modifier|*
name|getLocationRegionIfPostStore
parameter_list|(
specifier|const
name|ExplodedNode
modifier|*
name|N
parameter_list|)
block|{
name|ProgramPoint
name|L
init|=
name|N
operator|->
name|getLocation
argument_list|()
decl_stmt|;
if|if
condition|(
name|Optional
operator|<
name|PostStore
operator|>
name|PSL
operator|=
name|L
operator|.
name|getAs
operator|<
name|PostStore
operator|>
operator|(
operator|)
condition|)
return|return
name|reinterpret_cast
operator|<
specifier|const
name|MemRegion
operator|*
operator|>
operator|(
name|PSL
operator|->
name|getLocationValue
argument_list|()
operator|)
return|;
return|return
name|nullptr
return|;
block|}
comment|/// \brief Get the value of arbitrary expressions at this point in the path.
name|SVal
name|getSVal
argument_list|(
specifier|const
name|Stmt
operator|*
name|S
argument_list|)
decl|const
block|{
return|return
name|getState
argument_list|()
operator|->
name|getSVal
argument_list|(
name|S
argument_list|,
name|getLocationContext
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Generates a new transition in the program state graph
comment|/// (ExplodedGraph). Uses the default CheckerContext predecessor node.
comment|///
comment|/// @param State The state of the generated node. If not specified, the state
comment|///        will not be changed, but the new node will have the checker's tag.
comment|/// @param Tag The tag is used to uniquely identify the creation site. If no
comment|///        tag is specified, a default tag, unique to the given checker,
comment|///        will be used. Tags are used to prevent states generated at
comment|///        different sites from caching out.
name|ExplodedNode
modifier|*
name|addTransition
parameter_list|(
name|ProgramStateRef
name|State
init|=
name|nullptr
parameter_list|,
specifier|const
name|ProgramPointTag
modifier|*
name|Tag
init|=
name|nullptr
parameter_list|)
block|{
return|return
name|addTransitionImpl
argument_list|(
name|State
condition|?
name|State
else|:
name|getState
argument_list|()
argument_list|,
name|false
argument_list|,
name|nullptr
argument_list|,
name|Tag
argument_list|)
return|;
block|}
comment|/// \brief Generates a new transition with the given predecessor.
comment|/// Allows checkers to generate a chain of nodes.
comment|///
comment|/// @param State The state of the generated node.
comment|/// @param Pred The transition will be generated from the specified Pred node
comment|///             to the newly generated node.
comment|/// @param Tag The tag to uniquely identify the creation site.
name|ExplodedNode
modifier|*
name|addTransition
parameter_list|(
name|ProgramStateRef
name|State
parameter_list|,
name|ExplodedNode
modifier|*
name|Pred
parameter_list|,
specifier|const
name|ProgramPointTag
modifier|*
name|Tag
init|=
name|nullptr
parameter_list|)
block|{
return|return
name|addTransitionImpl
argument_list|(
name|State
argument_list|,
name|false
argument_list|,
name|Pred
argument_list|,
name|Tag
argument_list|)
return|;
block|}
comment|/// \brief Generate a sink node. Generating a sink stops exploration of the
comment|/// given path.
name|ExplodedNode
modifier|*
name|generateSink
parameter_list|(
name|ProgramStateRef
name|State
init|=
name|nullptr
parameter_list|,
name|ExplodedNode
modifier|*
name|Pred
init|=
name|nullptr
parameter_list|,
specifier|const
name|ProgramPointTag
modifier|*
name|Tag
init|=
name|nullptr
parameter_list|)
block|{
return|return
name|addTransitionImpl
argument_list|(
name|State
condition|?
name|State
else|:
name|getState
argument_list|()
argument_list|,
name|true
argument_list|,
name|Pred
argument_list|,
name|Tag
argument_list|)
return|;
block|}
comment|/// \brief Emit the diagnostics report.
name|void
name|emitReport
parameter_list|(
name|BugReport
modifier|*
name|R
parameter_list|)
block|{
name|Changed
operator|=
name|true
expr_stmt|;
name|Eng
operator|.
name|getBugReporter
argument_list|()
operator|.
name|emitReport
argument_list|(
name|R
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Get the declaration of the called function (path-sensitive).
specifier|const
name|FunctionDecl
modifier|*
name|getCalleeDecl
argument_list|(
specifier|const
name|CallExpr
operator|*
name|CE
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the name of the called function (path-sensitive).
name|StringRef
name|getCalleeName
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|FunDecl
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Get the identifier of the called function (path-sensitive).
specifier|const
name|IdentifierInfo
modifier|*
name|getCalleeIdentifier
argument_list|(
specifier|const
name|CallExpr
operator|*
name|CE
argument_list|)
decl|const
block|{
specifier|const
name|FunctionDecl
modifier|*
name|FunDecl
init|=
name|getCalleeDecl
argument_list|(
name|CE
argument_list|)
decl_stmt|;
if|if
condition|(
name|FunDecl
condition|)
return|return
name|FunDecl
operator|->
name|getIdentifier
argument_list|()
return|;
else|else
return|return
name|nullptr
return|;
block|}
comment|/// \brief Get the name of the called function (path-sensitive).
name|StringRef
name|getCalleeName
argument_list|(
specifier|const
name|CallExpr
operator|*
name|CE
argument_list|)
decl|const
block|{
specifier|const
name|FunctionDecl
modifier|*
name|FunDecl
init|=
name|getCalleeDecl
argument_list|(
name|CE
argument_list|)
decl_stmt|;
return|return
name|getCalleeName
argument_list|(
name|FunDecl
argument_list|)
return|;
block|}
comment|/// \brief Returns true if the callee is an externally-visible function in the
comment|/// top-level namespace, such as \c malloc.
comment|///
comment|/// If a name is provided, the function must additionally match the given
comment|/// name.
comment|///
comment|/// Note that this deliberately excludes C++ library functions in the \c std
comment|/// namespace, but will include C library functions accessed through the
comment|/// \c std namespace. This also does not check if the function is declared
comment|/// as 'extern "C"', or if it uses C++ name mangling.
specifier|static
name|bool
name|isCLibraryFunction
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|,
name|StringRef
name|Name
init|=
name|StringRef
argument_list|()
parameter_list|)
function_decl|;
comment|/// \brief Depending on wither the location corresponds to a macro, return
comment|/// either the macro name or the token spelling.
comment|///
comment|/// This could be useful when checkers' logic depends on whether a function
comment|/// is called with a given macro argument. For example:
comment|///   s = socket(AF_INET,..)
comment|/// If AF_INET is a macro, the result should be treated as a source of taint.
comment|///
comment|/// \sa clang::Lexer::getSpelling(), clang::Lexer::getImmediateMacroName().
name|StringRef
name|getMacroNameOrSpelling
parameter_list|(
name|SourceLocation
modifier|&
name|Loc
parameter_list|)
function_decl|;
name|private
label|:
name|ExplodedNode
modifier|*
name|addTransitionImpl
parameter_list|(
name|ProgramStateRef
name|State
parameter_list|,
name|bool
name|MarkAsSink
parameter_list|,
name|ExplodedNode
modifier|*
name|P
init|=
name|nullptr
parameter_list|,
specifier|const
name|ProgramPointTag
modifier|*
name|Tag
init|=
name|nullptr
parameter_list|)
block|{
if|if
condition|(
operator|!
name|State
operator|||
operator|(
name|State
operator|==
name|Pred
operator|->
name|getState
argument_list|()
operator|&&
operator|!
name|Tag
operator|&&
operator|!
name|MarkAsSink
operator|)
condition|)
return|return
name|Pred
return|;
name|Changed
operator|=
name|true
expr_stmt|;
specifier|const
name|ProgramPoint
modifier|&
name|LocalLoc
init|=
operator|(
name|Tag
condition|?
name|Location
operator|.
name|withTag
argument_list|(
name|Tag
argument_list|)
else|:
name|Location
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|P
condition|)
name|P
operator|=
name|Pred
expr_stmt|;
name|ExplodedNode
modifier|*
name|node
decl_stmt|;
if|if
condition|(
name|MarkAsSink
condition|)
name|node
operator|=
name|NB
operator|.
name|generateSink
argument_list|(
name|LocalLoc
argument_list|,
name|State
argument_list|,
name|P
argument_list|)
expr_stmt|;
else|else
name|node
operator|=
name|NB
operator|.
name|generateNode
argument_list|(
name|LocalLoc
argument_list|,
name|State
argument_list|,
name|P
argument_list|)
expr_stmt|;
return|return
name|node
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

