begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CallEvent.h - Wrapper for all function and method calls ----*- C++ -*--//
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
comment|/// \file This file defines CallEvent and its subclasses, which represent path-
end_comment

begin_comment
comment|/// sensitive instances of different kinds of function and method calls
end_comment

begin_comment
comment|/// (C, C++, and Objective-C).
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_CALLEVENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_CALLEVENT_H
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
file|"clang/AST/ExprObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/AnalysisContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/ProgramState.h"
end_include

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/PathSensitive/SVals.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ProgramPoint
decl_stmt|;
name|class
name|ProgramPointTag
decl_stmt|;
name|namespace
name|ento
block|{
enum|enum
name|CallEventKind
block|{
name|CE_Function
block|,
name|CE_CXXMember
block|,
name|CE_CXXMemberOperator
block|,
name|CE_CXXDestructor
block|,
name|CE_BEG_CXX_INSTANCE_CALLS
init|=
name|CE_CXXMember
block|,
name|CE_END_CXX_INSTANCE_CALLS
init|=
name|CE_CXXDestructor
block|,
name|CE_CXXConstructor
block|,
name|CE_CXXAllocator
block|,
name|CE_BEG_FUNCTION_CALLS
init|=
name|CE_Function
block|,
name|CE_END_FUNCTION_CALLS
init|=
name|CE_CXXAllocator
block|,
name|CE_Block
block|,
name|CE_ObjCMessage
block|}
enum|;
name|class
name|CallEvent
decl_stmt|;
name|class
name|CallEventManager
decl_stmt|;
comment|/// This class represents a description of a function call using the number of
comment|/// arguments and the name of the function.
name|class
name|CallDescription
block|{
name|friend
name|CallEvent
decl_stmt|;
name|mutable
name|IdentifierInfo
modifier|*
name|II
decl_stmt|;
name|mutable
name|bool
name|IsLookupDone
decl_stmt|;
name|StringRef
name|FuncName
decl_stmt|;
name|unsigned
name|RequiredArgs
decl_stmt|;
name|public
label|:
specifier|const
specifier|static
name|unsigned
name|NoArgRequirement
init|=
operator|~
literal|0
decl_stmt|;
comment|/// \brief Constructs a CallDescription object.
comment|///
comment|/// @param FuncName The name of the function that will be matched.
comment|///
comment|/// @param RequiredArgs The number of arguments that is expected to match a
comment|/// call. Omit this parameter to match every occurance of call with a given
comment|/// name regardless the number of arguments.
name|CallDescription
argument_list|(
argument|StringRef FuncName
argument_list|,
argument|unsigned RequiredArgs = NoArgRequirement
argument_list|)
block|:
name|II
argument_list|(
name|nullptr
argument_list|)
operator|,
name|IsLookupDone
argument_list|(
name|false
argument_list|)
operator|,
name|FuncName
argument_list|(
name|FuncName
argument_list|)
operator|,
name|RequiredArgs
argument_list|(
argument|RequiredArgs
argument_list|)
block|{}
comment|/// \brief Get the name of the function that this object matches.
name|StringRef
name|getFunctionName
argument_list|()
specifier|const
block|{
return|return
name|FuncName
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|=
name|CallEvent
operator|>
name|class
name|CallEventRef
operator|:
name|public
name|IntrusiveRefCntPtr
operator|<
specifier|const
name|T
operator|>
block|{
name|public
operator|:
name|CallEventRef
argument_list|(
specifier|const
name|T
operator|*
name|Call
argument_list|)
operator|:
name|IntrusiveRefCntPtr
operator|<
specifier|const
name|T
operator|>
operator|(
name|Call
operator|)
block|{}
name|CallEventRef
argument_list|(
specifier|const
name|CallEventRef
operator|&
name|Orig
argument_list|)
operator|:
name|IntrusiveRefCntPtr
operator|<
specifier|const
name|T
operator|>
operator|(
name|Orig
operator|)
block|{}
name|CallEventRef
operator|<
name|T
operator|>
name|cloneWithState
argument_list|(
argument|ProgramStateRef State
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|get
argument_list|()
operator|->
name|template
name|cloneWithState
operator|<
name|T
operator|>
operator|(
name|State
operator|)
return|;
block|}
comment|// Allow implicit conversions to a superclass type, since CallEventRef
comment|// behaves like a pointer-to-const.
name|template
operator|<
name|typename
name|SuperT
operator|>
name|operator
name|CallEventRef
operator|<
name|SuperT
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|this
operator|->
name|get
argument_list|()
return|;
block|}
expr|}
block|;
comment|/// \class RuntimeDefinition
comment|/// \brief Defines the runtime definition of the called function.
comment|///
comment|/// Encapsulates the information we have about which Decl will be used
comment|/// when the call is executed on the given path. When dealing with dynamic
comment|/// dispatch, the information is based on DynamicTypeInfo and might not be
comment|/// precise.
name|class
name|RuntimeDefinition
block|{
comment|/// The Declaration of the function which could be called at runtime.
comment|/// NULL if not available.
specifier|const
name|Decl
operator|*
name|D
block|;
comment|/// The region representing an object (ObjC/C++) on which the method is
comment|/// called. With dynamic dispatch, the method definition depends on the
comment|/// runtime type of this object. NULL when the DynamicTypeInfo is
comment|/// precise.
specifier|const
name|MemRegion
operator|*
name|R
block|;
name|public
operator|:
name|RuntimeDefinition
argument_list|()
operator|:
name|D
argument_list|(
name|nullptr
argument_list|)
block|,
name|R
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|RuntimeDefinition
argument_list|(
specifier|const
name|Decl
operator|*
name|InD
argument_list|)
operator|:
name|D
argument_list|(
name|InD
argument_list|)
block|,
name|R
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|RuntimeDefinition
argument_list|(
specifier|const
name|Decl
operator|*
name|InD
argument_list|,
specifier|const
name|MemRegion
operator|*
name|InR
argument_list|)
operator|:
name|D
argument_list|(
name|InD
argument_list|)
block|,
name|R
argument_list|(
argument|InR
argument_list|)
block|{}
specifier|const
name|Decl
operator|*
name|getDecl
argument_list|()
block|{
return|return
name|D
return|;
block|}
comment|/// \brief Check if the definition we have is precise.
comment|/// If not, it is possible that the call dispatches to another definition at
comment|/// execution time.
name|bool
name|mayHaveOtherDefinitions
argument_list|()
block|{
return|return
name|R
operator|!=
name|nullptr
return|;
block|}
comment|/// When other definitions are possible, returns the region whose runtime type
comment|/// determines the method definition.
specifier|const
name|MemRegion
operator|*
name|getDispatchRegion
argument_list|()
block|{
return|return
name|R
return|;
block|}
expr|}
block|;
comment|/// \brief Represents an abstract call to a function or method along a
comment|/// particular path.
comment|///
comment|/// CallEvents are created through the factory methods of CallEventManager.
comment|///
comment|/// CallEvents should always be cheap to create and destroy. In order for
comment|/// CallEventManager to be able to re-use CallEvent-sized memory blocks,
comment|/// subclasses of CallEvent may not add any data members to the base class.
comment|/// Use the "Data" and "Location" fields instead.
name|class
name|CallEvent
block|{
name|public
operator|:
typedef|typedef
name|CallEventKind
name|Kind
typedef|;
name|private
operator|:
name|ProgramStateRef
name|State
block|;
specifier|const
name|LocationContext
operator|*
name|LCtx
block|;
name|llvm
operator|::
name|PointerUnion
operator|<
specifier|const
name|Expr
operator|*
block|,
specifier|const
name|Decl
operator|*
operator|>
name|Origin
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|CallEvent
operator|&
operator|)
operator|=
name|delete
block|;
name|protected
operator|:
comment|// This is user data for subclasses.
specifier|const
name|void
operator|*
name|Data
block|;
comment|// This is user data for subclasses.
comment|// This should come right before RefCount, so that the two fields can be
comment|// packed together on LP64 platforms.
name|SourceLocation
name|Location
block|;
name|private
operator|:
name|mutable
name|unsigned
name|RefCount
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|friend
expr|struct
name|llvm
operator|::
name|IntrusiveRefCntPtrInfo
block|;
name|void
name|Retain
argument_list|()
specifier|const
block|{
operator|++
name|RefCount
block|; }
name|void
name|Release
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|friend
name|class
name|CallEventManager
block|;
name|CallEvent
argument_list|(
argument|const Expr *E
argument_list|,
argument|ProgramStateRef state
argument_list|,
argument|const LocationContext *lctx
argument_list|)
operator|:
name|State
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|state
argument_list|)
argument_list|)
block|,
name|LCtx
argument_list|(
name|lctx
argument_list|)
block|,
name|Origin
argument_list|(
name|E
argument_list|)
block|,
name|RefCount
argument_list|(
literal|0
argument_list|)
block|{}
name|CallEvent
argument_list|(
argument|const Decl *D
argument_list|,
argument|ProgramStateRef state
argument_list|,
argument|const LocationContext *lctx
argument_list|)
operator|:
name|State
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|state
argument_list|)
argument_list|)
block|,
name|LCtx
argument_list|(
name|lctx
argument_list|)
block|,
name|Origin
argument_list|(
name|D
argument_list|)
block|,
name|RefCount
argument_list|(
literal|0
argument_list|)
block|{}
comment|// DO NOT MAKE PUBLIC
name|CallEvent
argument_list|(
specifier|const
name|CallEvent
operator|&
name|Original
argument_list|)
operator|:
name|State
argument_list|(
name|Original
operator|.
name|State
argument_list|)
block|,
name|LCtx
argument_list|(
name|Original
operator|.
name|LCtx
argument_list|)
block|,
name|Origin
argument_list|(
name|Original
operator|.
name|Origin
argument_list|)
block|,
name|Data
argument_list|(
name|Original
operator|.
name|Data
argument_list|)
block|,
name|Location
argument_list|(
name|Original
operator|.
name|Location
argument_list|)
block|,
name|RefCount
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Copies this CallEvent, with vtable intact, into a new block of memory.
name|virtual
name|void
name|cloneTo
argument_list|(
argument|void *Dest
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Get the value of arbitrary expressions at this point in the path.
name|SVal
name|getSVal
argument_list|(
argument|const Stmt *S
argument_list|)
specifier|const
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
typedef|typedef
name|SmallVectorImpl
operator|<
name|SVal
operator|>
name|ValueList
expr_stmt|;
comment|/// \brief Used to specify non-argument regions that will be invalidated as a
comment|/// result of this call.
name|virtual
name|void
name|getExtraInvalidatedValues
argument_list|(
argument|ValueList&Values
argument_list|,
argument|RegionAndSymbolInvalidationTraits *ETraits
argument_list|)
specifier|const
block|{}
name|public
operator|:
name|virtual
operator|~
name|CallEvent
argument_list|()
block|{}
comment|/// \brief Returns the kind of call this is.
name|virtual
name|Kind
name|getKind
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Returns the declaration of the function or method that will be
comment|/// called. May be null.
name|virtual
specifier|const
name|Decl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|Origin
operator|.
name|dyn_cast
operator|<
specifier|const
name|Decl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief The state in which the call is being evaluated.
specifier|const
name|ProgramStateRef
operator|&
name|getState
argument_list|()
specifier|const
block|{
return|return
name|State
return|;
block|}
comment|/// \brief The context in which the call is being evaluated.
specifier|const
name|LocationContext
operator|*
name|getLocationContext
argument_list|()
specifier|const
block|{
return|return
name|LCtx
return|;
block|}
comment|/// \brief Returns the definition of the function or method that will be
comment|/// called.
name|virtual
name|RuntimeDefinition
name|getRuntimeDefinition
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Returns the expression whose value will be the result of this call.
comment|/// May be null.
specifier|const
name|Expr
operator|*
name|getOriginExpr
argument_list|()
specifier|const
block|{
return|return
name|Origin
operator|.
name|dyn_cast
operator|<
specifier|const
name|Expr
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Returns the number of arguments (explicit and implicit).
comment|///
comment|/// Note that this may be greater than the number of parameters in the
comment|/// callee's declaration, and that it may include arguments not written in
comment|/// the source.
name|virtual
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
operator|=
literal|0
block|;
comment|/// \brief Returns true if the callee is known to be from a system header.
name|bool
name|isInSystemHeader
argument_list|()
specifier|const
block|{
specifier|const
name|Decl
operator|*
name|D
operator|=
name|getDecl
argument_list|()
block|;
if|if
condition|(
operator|!
name|D
condition|)
return|return
name|false
return|;
name|SourceLocation
name|Loc
operator|=
name|D
operator|->
name|getLocation
argument_list|()
block|;
if|if
condition|(
name|Loc
operator|.
name|isValid
argument_list|()
condition|)
block|{
specifier|const
name|SourceManager
modifier|&
name|SM
init|=
name|getState
argument_list|()
operator|->
name|getStateManager
argument_list|()
operator|.
name|getContext
argument_list|()
operator|.
name|getSourceManager
argument_list|()
decl_stmt|;
return|return
name|SM
operator|.
name|isInSystemHeader
argument_list|(
name|D
operator|->
name|getLocation
argument_list|()
argument_list|)
return|;
block|}
comment|// Special case for implicitly-declared global operator new/delete.
comment|// These should be considered system functions.
if|if
condition|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
init|=
name|dyn_cast
operator|<
name|FunctionDecl
operator|>
operator|(
name|D
operator|)
condition|)
return|return
name|FD
operator|->
name|isOverloadedOperator
argument_list|()
operator|&&
name|FD
operator|->
name|isImplicit
argument_list|()
operator|&&
name|FD
operator|->
name|isGlobal
argument_list|()
return|;
return|return
name|false
return|;
block|}
comment|/// \brief Returns true if the CallEvent is a call to a function that matches
comment|/// the CallDescription.
comment|///
comment|/// Note that this function is not intended to be used to match Obj-C method
comment|/// calls.
name|bool
name|isCalled
argument_list|(
specifier|const
name|CallDescription
operator|&
name|CD
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns a source range for the entire call, suitable for
comment|/// outputting in diagnostics.
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getSourceRange
argument_list|()
return|;
block|}
comment|/// \brief Returns the value of a given argument at the time of the call.
name|virtual
name|SVal
name|getArgSVal
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns the expression associated with a given argument.
comment|/// May be null if this expression does not appear in the source.
name|virtual
specifier|const
name|Expr
modifier|*
name|getArgExpr
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// \brief Returns the source range for errors associated with this argument.
comment|///
comment|/// May be invalid if the argument is not written in the source.
name|virtual
name|SourceRange
name|getArgSourceRange
argument_list|(
name|unsigned
name|Index
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns the result type, adjusted for references.
name|QualType
name|getResultType
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns the return value of the call.
comment|///
comment|/// This should only be called if the CallEvent was created using a state in
comment|/// which the return value has already been bound to the origin expression.
name|SVal
name|getReturnValue
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns true if the type of any of the non-null arguments satisfies
comment|/// the condition.
name|bool
name|hasNonNullArgumentsWithType
argument_list|(
name|bool
argument_list|(
operator|*
name|Condition
argument_list|)
argument_list|(
name|QualType
argument_list|)
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns true if any of the arguments appear to represent callbacks.
name|bool
name|hasNonZeroCallbackArg
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns true if any of the arguments is void*.
name|bool
name|hasVoidPointerToNonConstArg
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Returns true if any of the arguments are known to escape to long-
comment|/// term storage, even if this method will not modify them.
comment|// NOTE: The exact semantics of this are still being defined!
comment|// We don't really want a list of hardcoded exceptions in the long run,
comment|// but we don't want duplicated lists of known APIs in the short term either.
name|virtual
name|bool
name|argumentsMayEscape
argument_list|()
specifier|const
block|{
return|return
name|hasNonZeroCallbackArg
argument_list|()
return|;
block|}
comment|/// \brief Returns true if the callee is an externally-visible function in the
comment|/// top-level namespace, such as \c malloc.
comment|///
comment|/// You can use this call to determine that a particular function really is
comment|/// a library function and not, say, a C++ member function with the same name.
comment|///
comment|/// If a name is provided, the function must additionally match the given
comment|/// name.
comment|///
comment|/// Note that this deliberately excludes C++ library functions in the \c std
comment|/// namespace, but will include C library functions accessed through the
comment|/// \c std namespace. This also does not check if the function is declared
comment|/// as 'extern "C"', or if it uses C++ name mangling.
comment|// FIXME: Add a helper for checking namespaces.
comment|// FIXME: Move this down to AnyFunctionCall once checkers have more
comment|// precise callbacks.
name|bool
name|isGlobalCFunction
argument_list|(
name|StringRef
name|SpecificName
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Returns the name of the callee, if its name is a simple identifier.
comment|///
comment|/// Note that this will fail for Objective-C methods, blocks, and C++
comment|/// overloaded operators. The former is named by a Selector rather than a
comment|/// simple identifier, and the latter two do not have names.
comment|// FIXME: Move this down to AnyFunctionCall once checkers have more
comment|// precise callbacks.
specifier|const
name|IdentifierInfo
operator|*
name|getCalleeIdentifier
argument_list|()
specifier|const
block|{
specifier|const
name|NamedDecl
operator|*
name|ND
operator|=
name|dyn_cast_or_null
operator|<
name|NamedDecl
operator|>
operator|(
name|getDecl
argument_list|()
operator|)
block|;
if|if
condition|(
operator|!
name|ND
condition|)
return|return
name|nullptr
return|;
return|return
name|ND
operator|->
name|getIdentifier
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns an appropriate ProgramPoint for this call.
end_comment

begin_decl_stmt
name|ProgramPoint
name|getProgramPoint
argument_list|(
name|bool
name|IsPreVisit
operator|=
name|false
argument_list|,
specifier|const
name|ProgramPointTag
operator|*
name|Tag
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Returns a new state with all argument regions invalidated.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This accepts an alternate state in case some processing has already
end_comment

begin_comment
comment|/// occurred.
end_comment

begin_decl_stmt
name|ProgramStateRef
name|invalidateRegions
argument_list|(
name|unsigned
name|BlockCount
argument_list|,
name|ProgramStateRef
name|Orig
operator|=
name|nullptr
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|Loc
operator|,
name|SVal
operator|>
name|FrameBindingTy
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|SmallVectorImpl
operator|<
name|FrameBindingTy
operator|>
name|BindingsTy
expr_stmt|;
end_typedef

begin_comment
comment|/// Populates the given SmallVector with the bindings in the callee's stack
end_comment

begin_comment
comment|/// frame at the start of this call.
end_comment

begin_decl_stmt
name|virtual
name|void
name|getInitialStackFrameContents
argument_list|(
specifier|const
name|StackFrameContext
operator|*
name|CalleeCtx
argument_list|,
name|BindingsTy
operator|&
name|Bindings
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Returns a copy of this CallEvent, but using the given state.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|CallEventRef
operator|<
name|T
operator|>
name|cloneWithState
argument_list|(
argument|ProgramStateRef NewState
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Returns a copy of this CallEvent, but using the given state.
end_comment

begin_expr_stmt
name|CallEventRef
operator|<
operator|>
name|cloneWithState
argument_list|(
argument|ProgramStateRef NewState
argument_list|)
specifier|const
block|{
return|return
name|cloneWithState
operator|<
name|CallEvent
operator|>
operator|(
name|NewState
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns true if this is a statement is a function or method call
end_comment

begin_comment
comment|/// of some kind.
end_comment

begin_function_decl
specifier|static
name|bool
name|isCallStmt
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Returns the result type of a function or method declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This will return a null QualType if the result type cannot be determined.
end_comment

begin_function_decl
specifier|static
name|QualType
name|getDeclaredResultType
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Returns true if the given decl is known to be variadic.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \p D must not be null.
end_comment

begin_function_decl
specifier|static
name|bool
name|isVariadic
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Iterator access to formal parameters and their types.
end_comment

begin_label
name|private
label|:
end_label

begin_struct
struct|struct
name|GetTypeFn
block|{
name|QualType
name|operator
argument_list|()
operator|(
name|ParmVarDecl
operator|*
name|PD
operator|)
specifier|const
block|{
return|return
name|PD
operator|->
name|getType
argument_list|()
return|;
block|}
block|}
struct|;
end_struct

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Return call's formal parameters.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Remember that the number of formal parameters may not match the number
end_comment

begin_comment
comment|/// of arguments for all calls. However, the first parameter will always
end_comment

begin_comment
comment|/// correspond with the argument value returned by \c getArgSVal(0).
end_comment

begin_expr_stmt
name|virtual
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|parameters
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|llvm
operator|::
name|mapped_iterator
operator|<
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
operator|::
name|iterator
operator|,
name|GetTypeFn
operator|>
name|param_type_iterator
expr_stmt|;
end_typedef

begin_comment
comment|/// Returns an iterator over the types of the call's formal parameters.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This uses the callee decl found by default name lookup rather than the
end_comment

begin_comment
comment|/// definition because it represents a public interface, and probably has
end_comment

begin_comment
comment|/// more annotations.
end_comment

begin_expr_stmt
name|param_type_iterator
name|param_type_begin
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|map_iterator
argument_list|(
name|parameters
argument_list|()
operator|.
name|begin
argument_list|()
argument_list|,
name|GetTypeFn
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \sa param_type_begin()
end_comment

begin_expr_stmt
name|param_type_iterator
name|param_type_end
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|map_iterator
argument_list|(
name|parameters
argument_list|()
operator|.
name|end
argument_list|()
argument_list|,
name|GetTypeFn
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// For debugging purposes only
end_comment

begin_decl_stmt
name|void
name|dump
argument_list|(
name|raw_ostream
operator|&
name|Out
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Represents a call to any sort of function that might have a
end_comment

begin_comment
comment|/// FunctionDecl.
end_comment

begin_decl_stmt
name|class
name|AnyFunctionCall
range|:
name|public
name|CallEvent
block|{
name|protected
operator|:
name|AnyFunctionCall
argument_list|(
argument|const Expr *E
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
operator|:
name|CallEvent
argument_list|(
argument|E
argument_list|,
argument|St
argument_list|,
argument|LCtx
argument_list|)
block|{}
name|AnyFunctionCall
argument_list|(
argument|const Decl *D
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
operator|:
name|CallEvent
argument_list|(
argument|D
argument_list|,
argument|St
argument_list|,
argument|LCtx
argument_list|)
block|{}
name|AnyFunctionCall
argument_list|(
specifier|const
name|AnyFunctionCall
operator|&
name|Other
argument_list|)
operator|:
name|CallEvent
argument_list|(
argument|Other
argument_list|)
block|{}
name|public
operator|:
comment|// This function is overridden by subclasses, but they must return
comment|// a FunctionDecl.
specifier|const
name|FunctionDecl
operator|*
name|getDecl
argument_list|()
specifier|const
name|override
block|{
return|return
name|cast
operator|<
name|FunctionDecl
operator|>
operator|(
name|CallEvent
operator|::
name|getDecl
argument_list|()
operator|)
return|;
block|}
name|RuntimeDefinition
name|getRuntimeDefinition
argument_list|()
specifier|const
name|override
block|{
specifier|const
name|FunctionDecl
operator|*
name|FD
operator|=
name|getDecl
argument_list|()
block|;
comment|// Note that the AnalysisDeclContext will have the FunctionDecl with
comment|// the definition (if one exists).
if|if
condition|(
name|FD
condition|)
block|{
name|AnalysisDeclContext
modifier|*
name|AD
init|=
name|getLocationContext
argument_list|()
operator|->
name|getAnalysisDeclContext
argument_list|()
operator|->
name|getManager
argument_list|()
operator|->
name|getContext
argument_list|(
name|FD
argument_list|)
decl_stmt|;
if|if
condition|(
name|AD
operator|->
name|getBody
argument_list|()
condition|)
return|return
name|RuntimeDefinition
argument_list|(
name|AD
operator|->
name|getDecl
argument_list|()
argument_list|)
return|;
block|}
return|return
name|RuntimeDefinition
argument_list|()
return|;
block|}
name|bool
name|argumentsMayEscape
argument_list|()
specifier|const
name|override
block|;
name|void
name|getInitialStackFrameContents
argument_list|(
argument|const StackFrameContext *CalleeCtx
argument_list|,
argument|BindingsTy&Bindings
argument_list|)
specifier|const
name|override
block|;
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|parameters
argument_list|()
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const CallEvent *CA
argument_list|)
block|{
return|return
name|CA
operator|->
name|getKind
argument_list|()
operator|>=
name|CE_BEG_FUNCTION_CALLS
operator|&&
name|CA
operator|->
name|getKind
argument_list|()
operator|<=
name|CE_END_FUNCTION_CALLS
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a C function or static C++ member function call.
comment|///
comment|/// Example: \c fun()
name|class
name|SimpleFunctionCall
operator|:
name|public
name|AnyFunctionCall
block|{
name|friend
name|class
name|CallEventManager
block|;
name|protected
operator|:
name|SimpleFunctionCall
argument_list|(
argument|const CallExpr *CE
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
operator|:
name|AnyFunctionCall
argument_list|(
argument|CE
argument_list|,
argument|St
argument_list|,
argument|LCtx
argument_list|)
block|{}
name|SimpleFunctionCall
argument_list|(
specifier|const
name|SimpleFunctionCall
operator|&
name|Other
argument_list|)
operator|:
name|AnyFunctionCall
argument_list|(
argument|Other
argument_list|)
block|{}
name|void
name|cloneTo
argument_list|(
argument|void *Dest
argument_list|)
specifier|const
name|override
block|{
name|new
argument_list|(
argument|Dest
argument_list|)
name|SimpleFunctionCall
argument_list|(
operator|*
name|this
argument_list|)
block|;   }
name|public
operator|:
name|virtual
specifier|const
name|CallExpr
operator|*
name|getOriginExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CallExpr
operator|>
operator|(
name|AnyFunctionCall
operator|::
name|getOriginExpr
argument_list|()
operator|)
return|;
block|}
specifier|const
name|FunctionDecl
operator|*
name|getDecl
argument_list|()
specifier|const
name|override
block|;
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getNumArgs
argument_list|()
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArgExpr
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getArg
argument_list|(
name|Index
argument_list|)
return|;
block|}
name|Kind
name|getKind
argument_list|()
specifier|const
name|override
block|{
return|return
name|CE_Function
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CallEvent *CA
argument_list|)
block|{
return|return
name|CA
operator|->
name|getKind
argument_list|()
operator|==
name|CE_Function
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a call to a block.
comment|///
comment|/// Example:<tt>^{ /* ... */ }()</tt>
name|class
name|BlockCall
operator|:
name|public
name|CallEvent
block|{
name|friend
name|class
name|CallEventManager
block|;
name|protected
operator|:
name|BlockCall
argument_list|(
argument|const CallExpr *CE
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
operator|:
name|CallEvent
argument_list|(
argument|CE
argument_list|,
argument|St
argument_list|,
argument|LCtx
argument_list|)
block|{}
name|BlockCall
argument_list|(
specifier|const
name|BlockCall
operator|&
name|Other
argument_list|)
operator|:
name|CallEvent
argument_list|(
argument|Other
argument_list|)
block|{}
name|void
name|cloneTo
argument_list|(
argument|void *Dest
argument_list|)
specifier|const
name|override
block|{
name|new
argument_list|(
argument|Dest
argument_list|)
name|BlockCall
argument_list|(
operator|*
name|this
argument_list|)
block|; }
name|void
name|getExtraInvalidatedValues
argument_list|(
argument|ValueList&Values
argument_list|,
argument|RegionAndSymbolInvalidationTraits *ETraits
argument_list|)
specifier|const
name|override
block|;
name|public
operator|:
name|virtual
specifier|const
name|CallExpr
operator|*
name|getOriginExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CallExpr
operator|>
operator|(
name|CallEvent
operator|::
name|getOriginExpr
argument_list|()
operator|)
return|;
block|}
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getNumArgs
argument_list|()
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArgExpr
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getArg
argument_list|(
name|Index
argument_list|)
return|;
block|}
comment|/// \brief Returns the region associated with this instance of the block.
comment|///
comment|/// This may be NULL if the block's origin is unknown.
specifier|const
name|BlockDataRegion
operator|*
name|getBlockRegion
argument_list|()
specifier|const
block|;
specifier|const
name|BlockDecl
operator|*
name|getDecl
argument_list|()
specifier|const
name|override
block|{
specifier|const
name|BlockDataRegion
operator|*
name|BR
operator|=
name|getBlockRegion
argument_list|()
block|;
if|if
condition|(
operator|!
name|BR
condition|)
return|return
name|nullptr
return|;
return|return
name|BR
operator|->
name|getDecl
argument_list|()
return|;
block|}
name|bool
name|isConversionFromLambda
argument_list|()
specifier|const
block|{
specifier|const
name|BlockDecl
operator|*
name|BD
operator|=
name|getDecl
argument_list|()
block|;
if|if
condition|(
operator|!
name|BD
condition|)
return|return
name|false
return|;
return|return
name|BD
operator|->
name|isConversionFromLambda
argument_list|()
return|;
block|}
comment|/// \brief For a block converted from a C++ lambda, returns the block
comment|/// VarRegion for the variable holding the captured C++ lambda record.
specifier|const
name|VarRegion
operator|*
name|getRegionStoringCapturedLambda
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isConversionFromLambda
argument_list|()
argument_list|)
block|;
specifier|const
name|BlockDataRegion
operator|*
name|BR
operator|=
name|getBlockRegion
argument_list|()
block|;
name|assert
argument_list|(
name|BR
operator|&&
literal|"Block converted from lambda must have a block region"
argument_list|)
block|;
name|auto
name|I
operator|=
name|BR
operator|->
name|referenced_vars_begin
argument_list|()
block|;
name|assert
argument_list|(
name|I
operator|!=
name|BR
operator|->
name|referenced_vars_end
argument_list|()
argument_list|)
block|;
return|return
name|I
operator|.
name|getCapturedRegion
argument_list|()
return|;
block|}
name|RuntimeDefinition
name|getRuntimeDefinition
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
operator|!
name|isConversionFromLambda
argument_list|()
condition|)
return|return
name|RuntimeDefinition
argument_list|(
name|getDecl
argument_list|()
argument_list|)
return|;
comment|// Clang converts lambdas to blocks with an implicit user-defined
comment|// conversion operator method on the lambda record that looks (roughly)
comment|// like:
comment|//
comment|// typedef R(^block_type)(P1, P2, ...);
comment|// operator block_type() const {
comment|//   auto Lambda = *this;
comment|//   return ^(P1 p1, P2 p2, ...){
comment|//     /* return Lambda(p1, p2, ...); */
comment|//   };
comment|// }
comment|//
comment|// Here R is the return type of the lambda and P1, P2, ... are
comment|// its parameter types. 'Lambda' is a fake VarDecl captured by the block
comment|// that is initialized to a copy of the lambda.
comment|//
comment|// Sema leaves the body of a lambda-converted block empty (it is
comment|// produced by CodeGen), so we can't analyze it directly. Instead, we skip
comment|// the block body and analyze the operator() method on the captured lambda.
specifier|const
name|VarDecl
operator|*
name|LambdaVD
operator|=
name|getRegionStoringCapturedLambda
argument_list|()
operator|->
name|getDecl
argument_list|()
block|;
specifier|const
name|CXXRecordDecl
operator|*
name|LambdaDecl
operator|=
name|LambdaVD
operator|->
name|getType
argument_list|()
operator|->
name|getAsCXXRecordDecl
argument_list|()
block|;
name|CXXMethodDecl
operator|*
name|LambdaCallOperator
operator|=
name|LambdaDecl
operator|->
name|getLambdaCallOperator
argument_list|()
block|;
return|return
name|RuntimeDefinition
argument_list|(
name|LambdaCallOperator
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|bool
name|argumentsMayEscape
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|getInitialStackFrameContents
argument_list|(
specifier|const
name|StackFrameContext
operator|*
name|CalleeCtx
argument_list|,
name|BindingsTy
operator|&
name|Bindings
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|parameters
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Kind
name|getKind
argument_list|()
specifier|const
name|override
block|{
return|return
name|CE_Block
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|CallEvent
modifier|*
name|CA
parameter_list|)
block|{
return|return
name|CA
operator|->
name|getKind
argument_list|()
operator|==
name|CE_Block
return|;
block|}
end_function

begin_comment
unit|};
comment|/// \brief Represents a non-static C++ member function call, no matter how
end_comment

begin_comment
comment|/// it is written.
end_comment

begin_decl_stmt
name|class
name|CXXInstanceCall
range|:
name|public
name|AnyFunctionCall
block|{
name|protected
operator|:
name|void
name|getExtraInvalidatedValues
argument_list|(
argument|ValueList&Values
argument_list|,
argument|RegionAndSymbolInvalidationTraits *ETraits
argument_list|)
specifier|const
name|override
block|;
name|CXXInstanceCall
argument_list|(
argument|const CallExpr *CE
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
operator|:
name|AnyFunctionCall
argument_list|(
argument|CE
argument_list|,
argument|St
argument_list|,
argument|LCtx
argument_list|)
block|{}
name|CXXInstanceCall
argument_list|(
argument|const FunctionDecl *D
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
operator|:
name|AnyFunctionCall
argument_list|(
argument|D
argument_list|,
argument|St
argument_list|,
argument|LCtx
argument_list|)
block|{}
name|CXXInstanceCall
argument_list|(
specifier|const
name|CXXInstanceCall
operator|&
name|Other
argument_list|)
operator|:
name|AnyFunctionCall
argument_list|(
argument|Other
argument_list|)
block|{}
name|public
operator|:
comment|/// \brief Returns the expression representing the implicit 'this' object.
name|virtual
specifier|const
name|Expr
operator|*
name|getCXXThisExpr
argument_list|()
specifier|const
block|{
return|return
name|nullptr
return|;
block|}
comment|/// \brief Returns the value of the implicit 'this' object.
name|virtual
name|SVal
name|getCXXThisVal
argument_list|()
specifier|const
block|;
specifier|const
name|FunctionDecl
operator|*
name|getDecl
argument_list|()
specifier|const
name|override
block|;
name|RuntimeDefinition
name|getRuntimeDefinition
argument_list|()
specifier|const
name|override
block|;
name|void
name|getInitialStackFrameContents
argument_list|(
argument|const StackFrameContext *CalleeCtx
argument_list|,
argument|BindingsTy&Bindings
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const CallEvent *CA
argument_list|)
block|{
return|return
name|CA
operator|->
name|getKind
argument_list|()
operator|>=
name|CE_BEG_CXX_INSTANCE_CALLS
operator|&&
name|CA
operator|->
name|getKind
argument_list|()
operator|<=
name|CE_END_CXX_INSTANCE_CALLS
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a non-static C++ member function call.
comment|///
comment|/// Example: \c obj.fun()
name|class
name|CXXMemberCall
operator|:
name|public
name|CXXInstanceCall
block|{
name|friend
name|class
name|CallEventManager
block|;
name|protected
operator|:
name|CXXMemberCall
argument_list|(
argument|const CXXMemberCallExpr *CE
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
operator|:
name|CXXInstanceCall
argument_list|(
argument|CE
argument_list|,
argument|St
argument_list|,
argument|LCtx
argument_list|)
block|{}
name|CXXMemberCall
argument_list|(
specifier|const
name|CXXMemberCall
operator|&
name|Other
argument_list|)
operator|:
name|CXXInstanceCall
argument_list|(
argument|Other
argument_list|)
block|{}
name|void
name|cloneTo
argument_list|(
argument|void *Dest
argument_list|)
specifier|const
name|override
block|{
name|new
argument_list|(
argument|Dest
argument_list|)
name|CXXMemberCall
argument_list|(
operator|*
name|this
argument_list|)
block|; }
name|public
operator|:
name|virtual
specifier|const
name|CXXMemberCallExpr
operator|*
name|getOriginExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CXXMemberCallExpr
operator|>
operator|(
name|CXXInstanceCall
operator|::
name|getOriginExpr
argument_list|()
operator|)
return|;
block|}
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
specifier|const
name|CallExpr
modifier|*
name|CE
init|=
name|getOriginExpr
argument_list|()
condition|)
return|return
name|CE
operator|->
name|getNumArgs
argument_list|()
return|;
return|return
literal|0
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArgExpr
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getArg
argument_list|(
name|Index
argument_list|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getCXXThisExpr
argument_list|()
specifier|const
name|override
block|;
name|RuntimeDefinition
name|getRuntimeDefinition
argument_list|()
specifier|const
name|override
block|;
name|Kind
name|getKind
argument_list|()
specifier|const
name|override
block|{
return|return
name|CE_CXXMember
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CallEvent *CA
argument_list|)
block|{
return|return
name|CA
operator|->
name|getKind
argument_list|()
operator|==
name|CE_CXXMember
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a C++ overloaded operator call where the operator is
comment|/// implemented as a non-static member function.
comment|///
comment|/// Example:<tt>iter + 1</tt>
name|class
name|CXXMemberOperatorCall
operator|:
name|public
name|CXXInstanceCall
block|{
name|friend
name|class
name|CallEventManager
block|;
name|protected
operator|:
name|CXXMemberOperatorCall
argument_list|(
argument|const CXXOperatorCallExpr *CE
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
operator|:
name|CXXInstanceCall
argument_list|(
argument|CE
argument_list|,
argument|St
argument_list|,
argument|LCtx
argument_list|)
block|{}
name|CXXMemberOperatorCall
argument_list|(
specifier|const
name|CXXMemberOperatorCall
operator|&
name|Other
argument_list|)
operator|:
name|CXXInstanceCall
argument_list|(
argument|Other
argument_list|)
block|{}
name|void
name|cloneTo
argument_list|(
argument|void *Dest
argument_list|)
specifier|const
name|override
block|{
name|new
argument_list|(
argument|Dest
argument_list|)
name|CXXMemberOperatorCall
argument_list|(
operator|*
name|this
argument_list|)
block|;   }
name|public
operator|:
name|virtual
specifier|const
name|CXXOperatorCallExpr
operator|*
name|getOriginExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CXXOperatorCallExpr
operator|>
operator|(
name|CXXInstanceCall
operator|::
name|getOriginExpr
argument_list|()
operator|)
return|;
block|}
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getNumArgs
argument_list|()
operator|-
literal|1
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArgExpr
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getArg
argument_list|(
name|Index
operator|+
literal|1
argument_list|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getCXXThisExpr
argument_list|()
specifier|const
name|override
block|;
name|Kind
name|getKind
argument_list|()
specifier|const
name|override
block|{
return|return
name|CE_CXXMemberOperator
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CallEvent *CA
argument_list|)
block|{
return|return
name|CA
operator|->
name|getKind
argument_list|()
operator|==
name|CE_CXXMemberOperator
return|;
block|}
expr|}
block|;
comment|/// \brief Represents an implicit call to a C++ destructor.
comment|///
comment|/// This can occur at the end of a scope (for automatic objects), at the end
comment|/// of a full-expression (for temporaries), or as part of a delete.
name|class
name|CXXDestructorCall
operator|:
name|public
name|CXXInstanceCall
block|{
name|friend
name|class
name|CallEventManager
block|;
name|protected
operator|:
typedef|typedef
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
name|MemRegion
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|DtorDataTy
expr_stmt|;
comment|/// Creates an implicit destructor.
comment|///
comment|/// \param DD The destructor that will be called.
comment|/// \param Trigger The statement whose completion causes this destructor call.
comment|/// \param Target The object region to be destructed.
comment|/// \param St The path-sensitive state at this point in the program.
comment|/// \param LCtx The location context at this point in the program.
name|CXXDestructorCall
argument_list|(
argument|const CXXDestructorDecl *DD
argument_list|,
argument|const Stmt *Trigger
argument_list|,
argument|const MemRegion *Target
argument_list|,
argument|bool IsBaseDestructor
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
operator|:
name|CXXInstanceCall
argument_list|(
argument|DD
argument_list|,
argument|St
argument_list|,
argument|LCtx
argument_list|)
block|{
name|Data
operator|=
name|DtorDataTy
argument_list|(
name|Target
argument_list|,
name|IsBaseDestructor
argument_list|)
operator|.
name|getOpaqueValue
argument_list|()
block|;
name|Location
operator|=
name|Trigger
operator|->
name|getLocEnd
argument_list|()
block|;   }
name|CXXDestructorCall
argument_list|(
specifier|const
name|CXXDestructorCall
operator|&
name|Other
argument_list|)
operator|:
name|CXXInstanceCall
argument_list|(
argument|Other
argument_list|)
block|{}
name|void
name|cloneTo
argument_list|(
argument|void *Dest
argument_list|)
specifier|const
name|override
block|{
name|new
argument_list|(
argument|Dest
argument_list|)
name|CXXDestructorCall
argument_list|(
operator|*
name|this
argument_list|)
block|;}
name|public
operator|:
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
block|{
return|return
name|Location
return|;
block|}
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
name|override
block|{
return|return
literal|0
return|;
block|}
name|RuntimeDefinition
name|getRuntimeDefinition
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief Returns the value of the implicit 'this' object.
name|SVal
name|getCXXThisVal
argument_list|()
specifier|const
name|override
block|;
comment|/// Returns true if this is a call to a base class destructor.
name|bool
name|isBaseDestructor
argument_list|()
specifier|const
block|{
return|return
name|DtorDataTy
operator|::
name|getFromOpaqueValue
argument_list|(
name|Data
argument_list|)
operator|.
name|getInt
argument_list|()
return|;
block|}
name|Kind
name|getKind
argument_list|()
specifier|const
name|override
block|{
return|return
name|CE_CXXDestructor
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CallEvent *CA
argument_list|)
block|{
return|return
name|CA
operator|->
name|getKind
argument_list|()
operator|==
name|CE_CXXDestructor
return|;
block|}
expr|}
block|;
comment|/// \brief Represents a call to a C++ constructor.
comment|///
comment|/// Example: \c T(1)
name|class
name|CXXConstructorCall
operator|:
name|public
name|AnyFunctionCall
block|{
name|friend
name|class
name|CallEventManager
block|;
name|protected
operator|:
comment|/// Creates a constructor call.
comment|///
comment|/// \param CE The constructor expression as written in the source.
comment|/// \param Target The region where the object should be constructed. If NULL,
comment|///               a new symbolic region will be used.
comment|/// \param St The path-sensitive state at this point in the program.
comment|/// \param LCtx The location context at this point in the program.
name|CXXConstructorCall
argument_list|(
argument|const CXXConstructExpr *CE
argument_list|,
argument|const MemRegion *Target
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
operator|:
name|AnyFunctionCall
argument_list|(
argument|CE
argument_list|,
argument|St
argument_list|,
argument|LCtx
argument_list|)
block|{
name|Data
operator|=
name|Target
block|;   }
name|CXXConstructorCall
argument_list|(
specifier|const
name|CXXConstructorCall
operator|&
name|Other
argument_list|)
operator|:
name|AnyFunctionCall
argument_list|(
argument|Other
argument_list|)
block|{}
name|void
name|cloneTo
argument_list|(
argument|void *Dest
argument_list|)
specifier|const
name|override
block|{
name|new
argument_list|(
argument|Dest
argument_list|)
name|CXXConstructorCall
argument_list|(
operator|*
name|this
argument_list|)
block|; }
name|void
name|getExtraInvalidatedValues
argument_list|(
argument|ValueList&Values
argument_list|,
argument|RegionAndSymbolInvalidationTraits *ETraits
argument_list|)
specifier|const
name|override
block|;
name|public
operator|:
name|virtual
specifier|const
name|CXXConstructExpr
operator|*
name|getOriginExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CXXConstructExpr
operator|>
operator|(
name|AnyFunctionCall
operator|::
name|getOriginExpr
argument_list|()
operator|)
return|;
block|}
specifier|const
name|CXXConstructorDecl
operator|*
name|getDecl
argument_list|()
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getConstructor
argument_list|()
return|;
block|}
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getNumArgs
argument_list|()
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArgExpr
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getArg
argument_list|(
name|Index
argument_list|)
return|;
block|}
comment|/// \brief Returns the value of the implicit 'this' object.
name|SVal
name|getCXXThisVal
argument_list|()
specifier|const
block|;
name|void
name|getInitialStackFrameContents
argument_list|(
argument|const StackFrameContext *CalleeCtx
argument_list|,
argument|BindingsTy&Bindings
argument_list|)
specifier|const
name|override
block|;
name|Kind
name|getKind
argument_list|()
specifier|const
name|override
block|{
return|return
name|CE_CXXConstructor
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CallEvent *CA
argument_list|)
block|{
return|return
name|CA
operator|->
name|getKind
argument_list|()
operator|==
name|CE_CXXConstructor
return|;
block|}
expr|}
block|;
comment|/// \brief Represents the memory allocation call in a C++ new-expression.
comment|///
comment|/// This is a call to "operator new".
name|class
name|CXXAllocatorCall
operator|:
name|public
name|AnyFunctionCall
block|{
name|friend
name|class
name|CallEventManager
block|;
name|protected
operator|:
name|CXXAllocatorCall
argument_list|(
argument|const CXXNewExpr *E
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
operator|:
name|AnyFunctionCall
argument_list|(
argument|E
argument_list|,
argument|St
argument_list|,
argument|LCtx
argument_list|)
block|{}
name|CXXAllocatorCall
argument_list|(
specifier|const
name|CXXAllocatorCall
operator|&
name|Other
argument_list|)
operator|:
name|AnyFunctionCall
argument_list|(
argument|Other
argument_list|)
block|{}
name|void
name|cloneTo
argument_list|(
argument|void *Dest
argument_list|)
specifier|const
name|override
block|{
name|new
argument_list|(
argument|Dest
argument_list|)
name|CXXAllocatorCall
argument_list|(
operator|*
name|this
argument_list|)
block|; }
name|public
operator|:
name|virtual
specifier|const
name|CXXNewExpr
operator|*
name|getOriginExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|CXXNewExpr
operator|>
operator|(
name|AnyFunctionCall
operator|::
name|getOriginExpr
argument_list|()
operator|)
return|;
block|}
specifier|const
name|FunctionDecl
operator|*
name|getDecl
argument_list|()
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getOperatorNew
argument_list|()
return|;
block|}
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getNumPlacementArgs
argument_list|()
operator|+
literal|1
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArgExpr
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
name|override
block|{
comment|// The first argument of an allocator call is the size of the allocation.
if|if
condition|(
name|Index
operator|==
literal|0
condition|)
return|return
name|nullptr
return|;
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getPlacementArg
argument_list|(
name|Index
operator|-
literal|1
argument_list|)
return|;
block|}
name|Kind
name|getKind
argument_list|()
specifier|const
name|override
block|{
return|return
name|CE_CXXAllocator
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CallEvent *CE
argument_list|)
block|{
return|return
name|CE
operator|->
name|getKind
argument_list|()
operator|==
name|CE_CXXAllocator
return|;
block|}
expr|}
block|;
comment|/// \brief Represents the ways an Objective-C message send can occur.
comment|//
comment|// Note to maintainers: OCM_Message should always be last, since it does not
comment|// need to fit in the Data field's low bits.
block|enum
name|ObjCMessageKind
block|{
name|OCM_PropertyAccess
block|,
name|OCM_Subscript
block|,
name|OCM_Message
block|}
block|;
comment|/// \brief Represents any expression that calls an Objective-C method.
comment|///
comment|/// This includes all of the kinds listed in ObjCMessageKind.
name|class
name|ObjCMethodCall
operator|:
name|public
name|CallEvent
block|{
name|friend
name|class
name|CallEventManager
block|;
specifier|const
name|PseudoObjectExpr
operator|*
name|getContainingPseudoObjectExpr
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|ObjCMethodCall
argument_list|(
argument|const ObjCMessageExpr *Msg
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
operator|:
name|CallEvent
argument_list|(
argument|Msg
argument_list|,
argument|St
argument_list|,
argument|LCtx
argument_list|)
block|{
name|Data
operator|=
name|nullptr
block|;   }
name|ObjCMethodCall
argument_list|(
specifier|const
name|ObjCMethodCall
operator|&
name|Other
argument_list|)
operator|:
name|CallEvent
argument_list|(
argument|Other
argument_list|)
block|{}
name|void
name|cloneTo
argument_list|(
argument|void *Dest
argument_list|)
specifier|const
name|override
block|{
name|new
argument_list|(
argument|Dest
argument_list|)
name|ObjCMethodCall
argument_list|(
operator|*
name|this
argument_list|)
block|; }
name|void
name|getExtraInvalidatedValues
argument_list|(
argument|ValueList&Values
argument_list|,
argument|RegionAndSymbolInvalidationTraits *ETraits
argument_list|)
specifier|const
name|override
block|;
comment|/// Check if the selector may have multiple definitions (may have overrides).
name|virtual
name|bool
name|canBeOverridenInSubclass
argument_list|(
argument|ObjCInterfaceDecl *IDecl
argument_list|,
argument|Selector Sel
argument_list|)
specifier|const
block|;
name|public
operator|:
name|virtual
specifier|const
name|ObjCMessageExpr
operator|*
name|getOriginExpr
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|ObjCMessageExpr
operator|>
operator|(
name|CallEvent
operator|::
name|getOriginExpr
argument_list|()
operator|)
return|;
block|}
specifier|const
name|ObjCMethodDecl
operator|*
name|getDecl
argument_list|()
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getMethodDecl
argument_list|()
return|;
block|}
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getNumArgs
argument_list|()
return|;
block|}
specifier|const
name|Expr
operator|*
name|getArgExpr
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
name|override
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getArg
argument_list|(
name|Index
argument_list|)
return|;
block|}
name|bool
name|isInstanceMessage
argument_list|()
specifier|const
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|isInstanceMessage
argument_list|()
return|;
block|}
name|ObjCMethodFamily
name|getMethodFamily
argument_list|()
specifier|const
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getMethodFamily
argument_list|()
return|;
block|}
name|Selector
name|getSelector
argument_list|()
specifier|const
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getSelector
argument_list|()
return|;
block|}
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|override
block|;
comment|/// \brief Returns the value of the receiver at the time of this call.
name|SVal
name|getReceiverSVal
argument_list|()
specifier|const
block|;
comment|/// \brief Return the value of 'self' if available.
name|SVal
name|getSelfSVal
argument_list|()
specifier|const
block|;
comment|/// \brief Get the interface for the receiver.
comment|///
comment|/// This works whether this is an instance message or a class message.
comment|/// However, it currently just uses the static type of the receiver.
specifier|const
name|ObjCInterfaceDecl
operator|*
name|getReceiverInterface
argument_list|()
specifier|const
block|{
return|return
name|getOriginExpr
argument_list|()
operator|->
name|getReceiverInterface
argument_list|()
return|;
block|}
comment|/// \brief Checks if the receiver refers to 'self' or 'super'.
name|bool
name|isReceiverSelfOrSuper
argument_list|()
specifier|const
block|;
comment|/// Returns how the message was written in the source (property access,
comment|/// subscript, or explicit message send).
name|ObjCMessageKind
name|getMessageKind
argument_list|()
specifier|const
block|;
comment|/// Returns true if this property access or subscript is a setter (has the
comment|/// form of an assignment).
name|bool
name|isSetter
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getMessageKind
argument_list|()
condition|)
block|{
case|case
name|OCM_Message
case|:
name|llvm_unreachable
argument_list|(
literal|"This is not a pseudo-object access!"
argument_list|)
expr_stmt|;
case|case
name|OCM_PropertyAccess
case|:
return|return
name|getNumArgs
argument_list|()
operator|>
literal|0
return|;
case|case
name|OCM_Subscript
case|:
return|return
name|getNumArgs
argument_list|()
operator|>
literal|1
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Unknown message kind"
argument_list|)
expr_stmt|;
block|}
comment|// Returns the property accessed by this method, either explicitly via
comment|// property syntax or implicitly via a getter or setter method. Returns
comment|// nullptr if the call is not a prooperty access.
specifier|const
name|ObjCPropertyDecl
operator|*
name|getAccessedProperty
argument_list|()
specifier|const
block|;
name|RuntimeDefinition
name|getRuntimeDefinition
argument_list|()
specifier|const
name|override
block|;
name|bool
name|argumentsMayEscape
argument_list|()
specifier|const
name|override
block|;
name|void
name|getInitialStackFrameContents
argument_list|(
argument|const StackFrameContext *CalleeCtx
argument_list|,
argument|BindingsTy&Bindings
argument_list|)
specifier|const
name|override
block|;
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|parameters
argument_list|()
specifier|const
name|override
block|;
name|Kind
name|getKind
argument_list|()
specifier|const
name|override
block|{
return|return
name|CE_ObjCMessage
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CallEvent *CA
argument_list|)
block|{
return|return
name|CA
operator|->
name|getKind
argument_list|()
operator|==
name|CE_ObjCMessage
return|;
block|}
expr|}
block|;
comment|/// \brief Manages the lifetime of CallEvent objects.
comment|///
comment|/// CallEventManager provides a way to create arbitrary CallEvents "on the
comment|/// stack" as if they were value objects by keeping a cache of CallEvent-sized
comment|/// memory blocks. The CallEvents created by CallEventManager are only valid
comment|/// for the lifetime of the OwnedCallEvent that holds them; right now these
comment|/// objects cannot be copied and ownership cannot be transferred.
name|class
name|CallEventManager
block|{
name|friend
name|class
name|CallEvent
block|;
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|Alloc
block|;
name|SmallVector
operator|<
name|void
operator|*
block|,
literal|8
operator|>
name|Cache
block|;
typedef|typedef
name|SimpleFunctionCall
name|CallEventTemplateTy
typedef|;
name|void
name|reclaim
argument_list|(
argument|const void *Memory
argument_list|)
block|{
name|Cache
operator|.
name|push_back
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|Memory
operator|)
argument_list|)
block|;   }
comment|/// Returns memory that can be initialized as a CallEvent.
name|void
operator|*
name|allocate
argument_list|()
block|{
if|if
condition|(
name|Cache
operator|.
name|empty
argument_list|()
condition|)
return|return
name|Alloc
operator|.
name|Allocate
operator|<
name|CallEventTemplateTy
operator|>
operator|(
operator|)
return|;
else|else
return|return
name|Cache
operator|.
name|pop_back_val
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|Arg
operator|>
name|T
operator|*
name|create
argument_list|(
argument|Arg A
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
block|{
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|CallEventTemplateTy
argument_list|)
argument_list|,
literal|"CallEvent subclasses are not all the same size"
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|allocate()
argument_list|)
name|T
argument_list|(
name|A
argument_list|,
name|St
argument_list|,
name|LCtx
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|Arg1
block|,
name|typename
name|Arg2
operator|>
name|T
operator|*
name|create
argument_list|(
argument|Arg1 A1
argument_list|,
argument|Arg2 A2
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
block|{
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|CallEventTemplateTy
argument_list|)
argument_list|,
literal|"CallEvent subclasses are not all the same size"
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|allocate()
argument_list|)
name|T
argument_list|(
name|A1
argument_list|,
name|A2
argument_list|,
name|St
argument_list|,
name|LCtx
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|Arg1
block|,
name|typename
name|Arg2
block|,
name|typename
name|Arg3
operator|>
name|T
operator|*
name|create
argument_list|(
argument|Arg1 A1
argument_list|,
argument|Arg2 A2
argument_list|,
argument|Arg3 A3
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
block|{
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|CallEventTemplateTy
argument_list|)
argument_list|,
literal|"CallEvent subclasses are not all the same size"
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|allocate()
argument_list|)
name|T
argument_list|(
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|,
name|St
argument_list|,
name|LCtx
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
block|,
name|typename
name|Arg1
block|,
name|typename
name|Arg2
block|,
name|typename
name|Arg3
block|,
name|typename
name|Arg4
operator|>
name|T
operator|*
name|create
argument_list|(
argument|Arg1 A1
argument_list|,
argument|Arg2 A2
argument_list|,
argument|Arg3 A3
argument_list|,
argument|Arg4 A4
argument_list|,
argument|ProgramStateRef St
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
block|{
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|CallEventTemplateTy
argument_list|)
argument_list|,
literal|"CallEvent subclasses are not all the same size"
argument_list|)
block|;
return|return
name|new
argument_list|(
argument|allocate()
argument_list|)
name|T
argument_list|(
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|,
name|A4
argument_list|,
name|St
argument_list|,
name|LCtx
argument_list|)
return|;
block|}
name|public
operator|:
name|CallEventManager
argument_list|(
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|alloc
argument_list|)
operator|:
name|Alloc
argument_list|(
argument|alloc
argument_list|)
block|{}
name|CallEventRef
operator|<
operator|>
name|getCaller
argument_list|(
argument|const StackFrameContext *CalleeCtx
argument_list|,
argument|ProgramStateRef State
argument_list|)
block|;
name|CallEventRef
operator|<
operator|>
name|getSimpleCall
argument_list|(
argument|const CallExpr *E
argument_list|,
argument|ProgramStateRef State
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
block|;
name|CallEventRef
operator|<
name|ObjCMethodCall
operator|>
name|getObjCMethodCall
argument_list|(
argument|const ObjCMessageExpr *E
argument_list|,
argument|ProgramStateRef State
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
block|{
return|return
name|create
operator|<
name|ObjCMethodCall
operator|>
operator|(
name|E
expr|,
name|State
expr|,
name|LCtx
operator|)
return|;
block|}
name|CallEventRef
operator|<
name|CXXConstructorCall
operator|>
name|getCXXConstructorCall
argument_list|(
argument|const CXXConstructExpr *E
argument_list|,
argument|const MemRegion *Target
argument_list|,
argument|ProgramStateRef State
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
block|{
return|return
name|create
operator|<
name|CXXConstructorCall
operator|>
operator|(
name|E
expr|,
name|Target
expr|,
name|State
expr|,
name|LCtx
operator|)
return|;
block|}
name|CallEventRef
operator|<
name|CXXDestructorCall
operator|>
name|getCXXDestructorCall
argument_list|(
argument|const CXXDestructorDecl *DD
argument_list|,
argument|const Stmt *Trigger
argument_list|,
argument|const MemRegion *Target
argument_list|,
argument|bool IsBase
argument_list|,
argument|ProgramStateRef State
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
block|{
return|return
name|create
operator|<
name|CXXDestructorCall
operator|>
operator|(
name|DD
expr|,
name|Trigger
expr|,
name|Target
expr|,
name|IsBase
expr|,
name|State
expr|,
name|LCtx
operator|)
return|;
block|}
name|CallEventRef
operator|<
name|CXXAllocatorCall
operator|>
name|getCXXAllocatorCall
argument_list|(
argument|const CXXNewExpr *E
argument_list|,
argument|ProgramStateRef State
argument_list|,
argument|const LocationContext *LCtx
argument_list|)
block|{
return|return
name|create
operator|<
name|CXXAllocatorCall
operator|>
operator|(
name|E
expr|,
name|State
expr|,
name|LCtx
operator|)
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|CallEventRef
operator|<
name|T
operator|>
name|CallEvent
operator|::
name|cloneWithState
argument_list|(
argument|ProgramStateRef NewState
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|isa
operator|<
name|T
operator|>
operator|(
operator|*
name|this
operator|)
operator|&&
literal|"Cloning to unrelated type"
argument_list|)
block|;
name|static_assert
argument_list|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|CallEvent
argument_list|)
argument_list|,
literal|"Subclasses may not add fields"
argument_list|)
block|;
if|if
condition|(
name|NewState
operator|==
name|State
condition|)
return|return
name|cast
operator|<
name|T
operator|>
operator|(
name|this
operator|)
return|;
name|CallEventManager
operator|&
name|Mgr
operator|=
name|State
operator|->
name|getStateManager
argument_list|()
operator|.
name|getCallEventManager
argument_list|()
block|;
name|T
operator|*
name|Copy
operator|=
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|Mgr
operator|.
name|allocate
argument_list|()
operator|)
block|;
name|cloneTo
argument_list|(
name|Copy
argument_list|)
block|;
name|assert
argument_list|(
name|Copy
operator|->
name|getKind
argument_list|()
operator|==
name|this
operator|->
name|getKind
argument_list|()
operator|&&
literal|"Bad copy"
argument_list|)
block|;
name|Copy
operator|->
name|State
operator|=
name|NewState
block|;
return|return
name|Copy
return|;
block|}
specifier|inline
name|void
name|CallEvent
operator|::
name|Release
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|RefCount
operator|>
literal|0
operator|&&
literal|"Reference count is already zero."
argument_list|)
block|;
operator|--
name|RefCount
block|;
if|if
condition|(
name|RefCount
operator|>
literal|0
condition|)
return|return;
name|CallEventManager
operator|&
name|Mgr
operator|=
name|State
operator|->
name|getStateManager
argument_list|()
operator|.
name|getCallEventManager
argument_list|()
block|;
name|Mgr
operator|.
name|reclaim
argument_list|(
name|this
argument_list|)
block|;
name|this
operator|->
expr|~
name|CallEvent
argument_list|()
block|; }
block|}
comment|// end namespace ento
block|}
comment|// end namespace clang
name|namespace
name|llvm
block|{
comment|// Support isa<>, cast<>, and dyn_cast<> for CallEventRef.
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|simplify_type
operator|<
name|clang
operator|::
name|ento
operator|::
name|CallEventRef
operator|<
name|T
operator|>
expr|>
block|{
typedef|typedef
specifier|const
name|T
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|clang::ento::CallEventRef<T> Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|get
argument_list|()
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

