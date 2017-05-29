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
comment|// This file defines FunctionScopeInfo and its subclasses, which contain
end_comment

begin_comment
comment|// information about a single function, block, lambda, or method body.
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
name|LLVM_CLANG_SEMA_SCOPEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_SCOPEINFO_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/CapturedStmt.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/PartialDiagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/CleanupInfo.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Ownership.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSwitch.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|BlockDecl
decl_stmt|;
name|class
name|CapturedDecl
decl_stmt|;
name|class
name|CXXMethodDecl
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|ObjCPropertyDecl
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|ImplicitParamDecl
decl_stmt|;
name|class
name|LabelDecl
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
name|class
name|TemplateTypeParmDecl
decl_stmt|;
name|class
name|TemplateParameterList
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|class
name|ObjCIvarRefExpr
decl_stmt|;
name|class
name|ObjCPropertyRefExpr
decl_stmt|;
name|class
name|ObjCMessageExpr
decl_stmt|;
name|namespace
name|sema
block|{
comment|/// \brief Contains information about the compound statement currently being
comment|/// parsed.
name|class
name|CompoundScopeInfo
block|{
name|public
label|:
name|CompoundScopeInfo
argument_list|()
operator|:
name|HasEmptyLoopBodies
argument_list|(
argument|false
argument_list|)
block|{ }
comment|/// \brief Whether this compound stamement contains `for' or `while' loops
comment|/// with empty bodies.
name|bool
name|HasEmptyLoopBodies
expr_stmt|;
name|void
name|setHasEmptyLoopBodies
parameter_list|()
block|{
name|HasEmptyLoopBodies
operator|=
name|true
expr_stmt|;
block|}
block|}
empty_stmt|;
name|class
name|PossiblyUnreachableDiag
block|{
name|public
label|:
name|PartialDiagnostic
name|PD
decl_stmt|;
name|SourceLocation
name|Loc
decl_stmt|;
specifier|const
name|Stmt
modifier|*
name|stmt
decl_stmt|;
name|PossiblyUnreachableDiag
argument_list|(
argument|const PartialDiagnostic&PD
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|const Stmt *stmt
argument_list|)
block|:
name|PD
argument_list|(
name|PD
argument_list|)
operator|,
name|Loc
argument_list|(
name|Loc
argument_list|)
operator|,
name|stmt
argument_list|(
argument|stmt
argument_list|)
block|{}
block|}
empty_stmt|;
comment|/// \brief Retains information about a function, method, or block that is
comment|/// currently being parsed.
name|class
name|FunctionScopeInfo
block|{
name|protected
label|:
enum|enum
name|ScopeKind
block|{
name|SK_Function
block|,
name|SK_Block
block|,
name|SK_Lambda
block|,
name|SK_CapturedRegion
block|}
enum|;
name|public
label|:
comment|/// \brief What kind of scope we are describing.
comment|///
name|ScopeKind
name|Kind
range|:
literal|3
decl_stmt|;
comment|/// \brief Whether this function contains a VLA, \@try, try, C++
comment|/// initializer, or anything else that can't be jumped past.
name|bool
name|HasBranchProtectedScope
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this function contains any switches or direct gotos.
name|bool
name|HasBranchIntoScope
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this function contains any indirect gotos.
name|bool
name|HasIndirectGoto
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether a statement was dropped because it was invalid.
name|bool
name|HasDroppedStmt
range|:
literal|1
decl_stmt|;
comment|/// \brief True if current scope is for OpenMP declare reduction combiner.
name|bool
name|HasOMPDeclareReductionCombiner
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether there is a fallthrough statement in this function.
name|bool
name|HasFallthroughStmt
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether we make reference to a declaration that could be
comment|/// unavailable.
name|bool
name|HasPotentialAvailabilityViolations
range|:
literal|1
decl_stmt|;
comment|/// A flag that is set when parsing a method that must call super's
comment|/// implementation, such as \c -dealloc, \c -finalize, or any method marked
comment|/// with \c __attribute__((objc_requires_super)).
name|bool
name|ObjCShouldCallSuper
range|:
literal|1
decl_stmt|;
comment|/// True when this is a method marked as a designated initializer.
name|bool
name|ObjCIsDesignatedInit
range|:
literal|1
decl_stmt|;
comment|/// This starts true for a method marked as designated initializer and will
comment|/// be set to false if there is an invocation to a designated initializer of
comment|/// the super class.
name|bool
name|ObjCWarnForNoDesignatedInitChain
range|:
literal|1
decl_stmt|;
comment|/// True when this is an initializer method not marked as a designated
comment|/// initializer within a class that has at least one initializer marked as a
comment|/// designated initializer.
name|bool
name|ObjCIsSecondaryInit
range|:
literal|1
decl_stmt|;
comment|/// This starts true for a secondary initializer method and will be set to
comment|/// false if there is an invocation of an initializer on 'self'.
name|bool
name|ObjCWarnForNoInitDelegation
range|:
literal|1
decl_stmt|;
comment|/// \brief True only when this function has not already built, or attempted
comment|/// to build, the initial and final coroutine suspend points
name|bool
name|NeedsCoroutineSuspends
range|:
literal|1
decl_stmt|;
comment|/// \brief An enumeration represeting the kind of the first coroutine statement
comment|/// in the function. One of co_return, co_await, or co_yield.
name|unsigned
name|char
name|FirstCoroutineStmtKind
range|:
literal|2
decl_stmt|;
comment|/// First coroutine statement in the current function.
comment|/// (ex co_return, co_await, co_yield)
name|SourceLocation
name|FirstCoroutineStmtLoc
decl_stmt|;
comment|/// First 'return' statement in the current function.
name|SourceLocation
name|FirstReturnLoc
decl_stmt|;
comment|/// First C++ 'try' statement in the current function.
name|SourceLocation
name|FirstCXXTryLoc
decl_stmt|;
comment|/// First SEH '__try' statement in the current function.
name|SourceLocation
name|FirstSEHTryLoc
decl_stmt|;
comment|/// \brief Used to determine if errors occurred in this function or block.
name|DiagnosticErrorTrap
name|ErrorTrap
decl_stmt|;
comment|/// SwitchStack - This is the current set of active switch statements in the
comment|/// block.
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
comment|/// optimization, or if we need to infer a return type.
name|SmallVector
operator|<
name|ReturnStmt
operator|*
operator|,
literal|4
operator|>
name|Returns
expr_stmt|;
comment|/// \brief The promise object for this coroutine, if any.
name|VarDecl
modifier|*
name|CoroutinePromise
init|=
name|nullptr
decl_stmt|;
comment|/// \brief The initial and final coroutine suspend points.
name|std
operator|::
name|pair
operator|<
name|Stmt
operator|*
operator|,
name|Stmt
operator|*
operator|>
name|CoroutineSuspends
expr_stmt|;
comment|/// \brief The stack of currently active compound stamement scopes in the
comment|/// function.
name|SmallVector
operator|<
name|CompoundScopeInfo
operator|,
literal|4
operator|>
name|CompoundScopes
expr_stmt|;
comment|/// \brief A list of PartialDiagnostics created but delayed within the
comment|/// current function scope.  These diagnostics are vetted for reachability
comment|/// prior to being emitted.
name|SmallVector
operator|<
name|PossiblyUnreachableDiag
operator|,
literal|4
operator|>
name|PossiblyUnreachableDiags
expr_stmt|;
comment|/// \brief A list of parameters which have the nonnull attribute and are
comment|/// modified in the function.
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|ParmVarDecl
operator|*
operator|,
literal|8
operator|>
name|ModifiedNonNullParams
expr_stmt|;
name|public
label|:
comment|/// Represents a simple identification of a weak object.
comment|///
comment|/// Part of the implementation of -Wrepeated-use-of-weak.
comment|///
comment|/// This is used to determine if two weak accesses refer to the same object.
comment|/// Here are some examples of how various accesses are "profiled":
comment|///
comment|/// Access Expression |     "Base" Decl     |          "Property" Decl
comment|/// :---------------: | :-----------------: | :------------------------------:
comment|/// self.property     | self (VarDecl)      | property (ObjCPropertyDecl)
comment|/// self.implicitProp | self (VarDecl)      | -implicitProp (ObjCMethodDecl)
comment|/// self->ivar.prop   | ivar (ObjCIvarDecl) | prop (ObjCPropertyDecl)
comment|/// cxxObj.obj.prop   | obj (FieldDecl)     | prop (ObjCPropertyDecl)
comment|/// [self foo].prop   | 0 (unknown)         | prop (ObjCPropertyDecl)
comment|/// self.prop1.prop2  | prop1 (ObjCPropertyDecl)    | prop2 (ObjCPropertyDecl)
comment|/// MyClass.prop      | MyClass (ObjCInterfaceDecl) | -prop (ObjCMethodDecl)
comment|/// MyClass.foo.prop  | +foo (ObjCMethodDecl)       | -prop (ObjCPropertyDecl)
comment|/// weakVar           | 0 (known)           | weakVar (VarDecl)
comment|/// self->weakIvar    | self (VarDecl)      | weakIvar (ObjCIvarDecl)
comment|///
comment|/// Objects are identified with only two Decls to make it reasonably fast to
comment|/// compare them.
name|class
name|WeakObjectProfileTy
block|{
comment|/// The base object decl, as described in the class documentation.
comment|///
comment|/// The extra flag is "true" if the Base and Property are enough to uniquely
comment|/// identify the object in memory.
comment|///
comment|/// \sa isExactProfile()
typedef|typedef
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
name|NamedDecl
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|BaseInfoTy
expr_stmt|;
name|BaseInfoTy
name|Base
decl_stmt|;
comment|/// The "property" decl, as described in the class documentation.
comment|///
comment|/// Note that this may not actually be an ObjCPropertyDecl, e.g. in the
comment|/// case of "implicit" properties (regular methods accessed via dot syntax).
specifier|const
name|NamedDecl
modifier|*
name|Property
decl_stmt|;
comment|/// Used to find the proper base profile for a given base expression.
specifier|static
name|BaseInfoTy
name|getBaseInfo
parameter_list|(
specifier|const
name|Expr
modifier|*
name|BaseE
parameter_list|)
function_decl|;
specifier|inline
name|WeakObjectProfileTy
argument_list|()
expr_stmt|;
specifier|static
specifier|inline
name|WeakObjectProfileTy
name|getSentinel
parameter_list|()
function_decl|;
name|public
label|:
name|WeakObjectProfileTy
argument_list|(
specifier|const
name|ObjCPropertyRefExpr
operator|*
name|RE
argument_list|)
expr_stmt|;
name|WeakObjectProfileTy
argument_list|(
specifier|const
name|Expr
operator|*
name|Base
argument_list|,
specifier|const
name|ObjCPropertyDecl
operator|*
name|Property
argument_list|)
expr_stmt|;
name|WeakObjectProfileTy
argument_list|(
specifier|const
name|DeclRefExpr
operator|*
name|RE
argument_list|)
expr_stmt|;
name|WeakObjectProfileTy
argument_list|(
specifier|const
name|ObjCIvarRefExpr
operator|*
name|RE
argument_list|)
expr_stmt|;
specifier|const
name|NamedDecl
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|Base
operator|.
name|getPointer
argument_list|()
return|;
block|}
specifier|const
name|NamedDecl
operator|*
name|getProperty
argument_list|()
specifier|const
block|{
return|return
name|Property
return|;
block|}
comment|/// Returns true if the object base specifies a known object in memory,
comment|/// rather than, say, an instance variable or property of another object.
comment|///
comment|/// Note that this ignores the effects of aliasing; that is, \c foo.bar is
comment|/// considered an exact profile if \c foo is a local variable, even if
comment|/// another variable \c foo2 refers to the same object as \c foo.
comment|///
comment|/// For increased precision, accesses with base variables that are
comment|/// properties or ivars of 'self' (e.g. self.prop1.prop2) are considered to
comment|/// be exact, though this is not true for arbitrary variables
comment|/// (foo.prop1.prop2).
name|bool
name|isExactProfile
argument_list|()
specifier|const
block|{
return|return
name|Base
operator|.
name|getInt
argument_list|()
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|WeakObjectProfileTy
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Base
operator|==
name|Other
operator|.
name|Base
operator|&&
name|Property
operator|==
name|Other
operator|.
name|Property
return|;
block|}
comment|// For use in DenseMap.
comment|// We can't specialize the usual llvm::DenseMapInfo at the end of the file
comment|// because by that point the DenseMap in FunctionScopeInfo has already been
comment|// instantiated.
name|class
name|DenseMapInfo
block|{
name|public
label|:
specifier|static
specifier|inline
name|WeakObjectProfileTy
name|getEmptyKey
parameter_list|()
block|{
return|return
name|WeakObjectProfileTy
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|WeakObjectProfileTy
name|getTombstoneKey
parameter_list|()
block|{
return|return
name|WeakObjectProfileTy
operator|::
name|getSentinel
argument_list|()
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|WeakObjectProfileTy
modifier|&
name|Val
parameter_list|)
block|{
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|BaseInfoTy
operator|,
specifier|const
name|NamedDecl
operator|*
operator|>
name|Pair
expr_stmt|;
return|return
name|llvm
operator|::
name|DenseMapInfo
operator|<
name|Pair
operator|>
operator|::
name|getHashValue
argument_list|(
name|Pair
argument_list|(
name|Val
operator|.
name|Base
argument_list|,
name|Val
operator|.
name|Property
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isEqual
parameter_list|(
specifier|const
name|WeakObjectProfileTy
modifier|&
name|LHS
parameter_list|,
specifier|const
name|WeakObjectProfileTy
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
block|}
empty_stmt|;
block|}
empty_stmt|;
comment|/// Represents a single use of a weak object.
comment|///
comment|/// Stores both the expression and whether the access is potentially unsafe
comment|/// (i.e. it could potentially be warned about).
comment|///
comment|/// Part of the implementation of -Wrepeated-use-of-weak.
name|class
name|WeakUseTy
block|{
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
name|Expr
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|Rep
expr_stmt|;
name|public
label|:
name|WeakUseTy
argument_list|(
argument|const Expr *Use
argument_list|,
argument|bool IsRead
argument_list|)
block|:
name|Rep
argument_list|(
argument|Use
argument_list|,
argument|IsRead
argument_list|)
block|{}
specifier|const
name|Expr
operator|*
name|getUseExpr
argument_list|()
specifier|const
block|{
return|return
name|Rep
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|bool
name|isUnsafe
argument_list|()
specifier|const
block|{
return|return
name|Rep
operator|.
name|getInt
argument_list|()
return|;
block|}
name|void
name|markSafe
parameter_list|()
block|{
name|Rep
operator|.
name|setInt
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|WeakUseTy
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Rep
operator|==
name|Other
operator|.
name|Rep
return|;
block|}
block|}
empty_stmt|;
comment|/// Used to collect uses of a particular weak object in a function body.
comment|///
comment|/// Part of the implementation of -Wrepeated-use-of-weak.
typedef|typedef
name|SmallVector
operator|<
name|WeakUseTy
operator|,
literal|4
operator|>
name|WeakUseVector
expr_stmt|;
comment|/// Used to collect all uses of weak objects in a function body.
comment|///
comment|/// Part of the implementation of -Wrepeated-use-of-weak.
typedef|typedef
name|llvm
operator|::
name|SmallDenseMap
operator|<
name|WeakObjectProfileTy
operator|,
name|WeakUseVector
operator|,
literal|8
operator|,
name|WeakObjectProfileTy
operator|::
name|DenseMapInfo
operator|>
name|WeakObjectUseMap
expr_stmt|;
name|private
label|:
comment|/// Used to collect all uses of weak objects in this function body.
comment|///
comment|/// Part of the implementation of -Wrepeated-use-of-weak.
name|WeakObjectUseMap
name|WeakObjectUses
decl_stmt|;
name|protected
label|:
name|FunctionScopeInfo
argument_list|(
specifier|const
name|FunctionScopeInfo
operator|&
argument_list|)
operator|=
expr|default
expr_stmt|;
name|public
label|:
comment|/// Record that a weak object was accessed.
comment|///
comment|/// Part of the implementation of -Wrepeated-use-of-weak.
name|template
operator|<
name|typename
name|ExprT
operator|>
specifier|inline
name|void
name|recordUseOfWeak
argument_list|(
argument|const ExprT *E
argument_list|,
argument|bool IsRead = true
argument_list|)
expr_stmt|;
name|void
name|recordUseOfWeak
parameter_list|(
specifier|const
name|ObjCMessageExpr
modifier|*
name|Msg
parameter_list|,
specifier|const
name|ObjCPropertyDecl
modifier|*
name|Prop
parameter_list|)
function_decl|;
comment|/// Record that a given expression is a "safe" access of a weak object (e.g.
comment|/// assigning it to a strong variable.)
comment|///
comment|/// Part of the implementation of -Wrepeated-use-of-weak.
name|void
name|markSafeWeakUse
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
specifier|const
name|WeakObjectUseMap
operator|&
name|getWeakObjectUses
argument_list|()
specifier|const
block|{
return|return
name|WeakObjectUses
return|;
block|}
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
name|void
name|setHasDroppedStmt
parameter_list|()
block|{
name|HasDroppedStmt
operator|=
name|true
expr_stmt|;
block|}
name|void
name|setHasOMPDeclareReductionCombiner
parameter_list|()
block|{
name|HasOMPDeclareReductionCombiner
operator|=
name|true
expr_stmt|;
block|}
name|void
name|setHasFallthroughStmt
parameter_list|()
block|{
name|HasFallthroughStmt
operator|=
name|true
expr_stmt|;
block|}
name|void
name|setHasCXXTry
parameter_list|(
name|SourceLocation
name|TryLoc
parameter_list|)
block|{
name|setHasBranchProtectedScope
argument_list|()
expr_stmt|;
name|FirstCXXTryLoc
operator|=
name|TryLoc
expr_stmt|;
block|}
name|void
name|setHasSEHTry
parameter_list|(
name|SourceLocation
name|TryLoc
parameter_list|)
block|{
name|setHasBranchProtectedScope
argument_list|()
expr_stmt|;
name|FirstSEHTryLoc
operator|=
name|TryLoc
expr_stmt|;
block|}
name|bool
name|NeedsScopeChecking
argument_list|()
specifier|const
block|{
return|return
operator|!
name|HasDroppedStmt
operator|&&
operator|(
name|HasIndirectGoto
operator|||
operator|(
name|HasBranchProtectedScope
operator|&&
name|HasBranchIntoScope
operator|)
operator|)
return|;
block|}
name|bool
name|isCoroutine
argument_list|()
specifier|const
block|{
return|return
operator|!
name|FirstCoroutineStmtLoc
operator|.
name|isInvalid
argument_list|()
return|;
block|}
name|void
name|setFirstCoroutineStmt
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|StringRef
name|Keyword
parameter_list|)
block|{
name|assert
argument_list|(
name|FirstCoroutineStmtLoc
operator|.
name|isInvalid
argument_list|()
operator|&&
literal|"first coroutine statement location already set"
argument_list|)
expr_stmt|;
name|FirstCoroutineStmtLoc
operator|=
name|Loc
expr_stmt|;
name|FirstCoroutineStmtKind
operator|=
name|llvm
operator|::
name|StringSwitch
operator|<
name|unsigned
name|char
operator|>
operator|(
name|Keyword
operator|)
operator|.
name|Case
argument_list|(
literal|"co_return"
argument_list|,
literal|0
argument_list|)
operator|.
name|Case
argument_list|(
literal|"co_await"
argument_list|,
literal|1
argument_list|)
operator|.
name|Case
argument_list|(
literal|"co_yield"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
name|StringRef
name|getFirstCoroutineStmtKeyword
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|FirstCoroutineStmtLoc
operator|.
name|isValid
argument_list|()
operator|&&
literal|"no coroutine statement available"
argument_list|)
block|;
switch|switch
condition|(
name|FirstCoroutineStmtKind
condition|)
block|{
case|case
literal|0
case|:
return|return
literal|"co_return"
return|;
case|case
literal|1
case|:
return|return
literal|"co_await"
return|;
case|case
literal|2
case|:
return|return
literal|"co_yield"
return|;
default|default:
name|llvm_unreachable
argument_list|(
literal|"FirstCoroutineStmtKind has an invalid value"
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
name|void
name|setNeedsCoroutineSuspends
argument_list|(
argument|bool value = true
argument_list|)
block|{
name|assert
argument_list|(
operator|(
operator|!
name|value
operator|||
name|CoroutineSuspends
operator|.
name|first
operator|==
name|nullptr
operator|)
operator|&&
literal|"we already have valid suspend points"
argument_list|)
block|;
name|NeedsCoroutineSuspends
operator|=
name|value
block|;   }
name|bool
name|hasInvalidCoroutineSuspends
argument_list|()
specifier|const
block|{
return|return
operator|!
name|NeedsCoroutineSuspends
operator|&&
name|CoroutineSuspends
operator|.
name|first
operator|==
name|nullptr
return|;
block|}
name|void
name|setCoroutineSuspends
parameter_list|(
name|Stmt
modifier|*
name|Initial
parameter_list|,
name|Stmt
modifier|*
name|Final
parameter_list|)
block|{
name|assert
argument_list|(
name|Initial
operator|&&
name|Final
operator|&&
literal|"suspend points cannot be null"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|CoroutineSuspends
operator|.
name|first
operator|==
name|nullptr
operator|&&
literal|"suspend points already set"
argument_list|)
expr_stmt|;
name|NeedsCoroutineSuspends
operator|=
name|false
expr_stmt|;
name|CoroutineSuspends
operator|.
name|first
operator|=
name|Initial
expr_stmt|;
name|CoroutineSuspends
operator|.
name|second
operator|=
name|Final
expr_stmt|;
block|}
name|FunctionScopeInfo
argument_list|(
name|DiagnosticsEngine
operator|&
name|Diag
argument_list|)
operator|:
name|Kind
argument_list|(
name|SK_Function
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
name|HasDroppedStmt
argument_list|(
name|false
argument_list|)
operator|,
name|HasOMPDeclareReductionCombiner
argument_list|(
name|false
argument_list|)
operator|,
name|HasFallthroughStmt
argument_list|(
name|false
argument_list|)
operator|,
name|HasPotentialAvailabilityViolations
argument_list|(
name|false
argument_list|)
operator|,
name|ObjCShouldCallSuper
argument_list|(
name|false
argument_list|)
operator|,
name|ObjCIsDesignatedInit
argument_list|(
name|false
argument_list|)
operator|,
name|ObjCWarnForNoDesignatedInitChain
argument_list|(
name|false
argument_list|)
operator|,
name|ObjCIsSecondaryInit
argument_list|(
name|false
argument_list|)
operator|,
name|ObjCWarnForNoInitDelegation
argument_list|(
name|false
argument_list|)
operator|,
name|NeedsCoroutineSuspends
argument_list|(
name|true
argument_list|)
operator|,
name|ErrorTrap
argument_list|(
argument|Diag
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
parameter_list|()
function_decl|;
block|}
empty_stmt|;
name|class
name|CapturingScopeInfo
range|:
name|public
name|FunctionScopeInfo
block|{
name|protected
operator|:
name|CapturingScopeInfo
argument_list|(
specifier|const
name|CapturingScopeInfo
operator|&
argument_list|)
operator|=
expr|default
block|;
name|public
operator|:
expr|enum
name|ImplicitCaptureStyle
block|{
name|ImpCap_None
block|,
name|ImpCap_LambdaByval
block|,
name|ImpCap_LambdaByref
block|,
name|ImpCap_Block
block|,
name|ImpCap_CapturedRegion
block|}
block|;
name|ImplicitCaptureStyle
name|ImpCaptureStyle
block|;
name|class
name|Capture
block|{
comment|// There are three categories of capture: capturing 'this', capturing
comment|// local variables, and C++1y initialized captures (which can have an
comment|// arbitrary initializer, and don't really capture in the traditional
comment|// sense at all).
comment|//
comment|// There are three ways to capture a local variable:
comment|//  - capture by copy in the C++11 sense,
comment|//  - capture by reference in the C++11 sense, and
comment|//  - __block capture.
comment|// Lambdas explicitly specify capture by copy or capture by reference.
comment|// For blocks, __block capture applies to variables with that annotation,
comment|// variables of reference type are captured by reference, and other
comment|// variables are captured by copy.
block|enum
name|CaptureKind
block|{
name|Cap_ByCopy
block|,
name|Cap_ByRef
block|,
name|Cap_Block
block|,
name|Cap_VLA
block|}
block|;     enum
block|{
name|IsNestedCapture
operator|=
literal|0x1
block|,
name|IsThisCaptured
operator|=
literal|0x2
block|}
block|;
comment|/// The variable being captured (if we are not capturing 'this') and whether
comment|/// this is a nested capture, and whether we are capturing 'this'
name|llvm
operator|::
name|PointerIntPair
operator|<
name|VarDecl
operator|*
block|,
literal|2
operator|>
name|VarAndNestedAndThis
block|;
comment|/// Expression to initialize a field of the given type, and the kind of
comment|/// capture (if this is a capture and not an init-capture). The expression
comment|/// is only required if we are capturing ByVal and the variable's type has
comment|/// a non-trivial copy constructor.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|void
operator|*
block|,
literal|2
block|,
name|CaptureKind
operator|>
name|InitExprAndCaptureKind
block|;
comment|/// \brief The source location at which the first capture occurred.
name|SourceLocation
name|Loc
block|;
comment|/// \brief The location of the ellipsis that expands a parameter pack.
name|SourceLocation
name|EllipsisLoc
block|;
comment|/// \brief The type as it was captured, which is in effect the type of the
comment|/// non-static data member that would hold the capture.
name|QualType
name|CaptureType
block|;
comment|/// \brief Whether an explicit capture has been odr-used in the body of the
comment|/// lambda.
name|bool
name|ODRUsed
block|;
comment|/// \brief Whether an explicit capture has been non-odr-used in the body of
comment|/// the lambda.
name|bool
name|NonODRUsed
block|;
name|public
operator|:
name|Capture
argument_list|(
argument|VarDecl *Var
argument_list|,
argument|bool Block
argument_list|,
argument|bool ByRef
argument_list|,
argument|bool IsNested
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|SourceLocation EllipsisLoc
argument_list|,
argument|QualType CaptureType
argument_list|,
argument|Expr *Cpy
argument_list|)
operator|:
name|VarAndNestedAndThis
argument_list|(
name|Var
argument_list|,
name|IsNested
condition|?
name|IsNestedCapture
else|:
literal|0
argument_list|)
block|,
name|InitExprAndCaptureKind
argument_list|(
name|Cpy
argument_list|,
operator|!
name|Var
condition|?
name|Cap_VLA
else|:
name|Block
condition|?
name|Cap_Block
else|:
name|ByRef
condition|?
name|Cap_ByRef
else|:
name|Cap_ByCopy
argument_list|)
block|,
name|Loc
argument_list|(
name|Loc
argument_list|)
block|,
name|EllipsisLoc
argument_list|(
name|EllipsisLoc
argument_list|)
block|,
name|CaptureType
argument_list|(
name|CaptureType
argument_list|)
block|,
name|ODRUsed
argument_list|(
name|false
argument_list|)
block|,
name|NonODRUsed
argument_list|(
argument|false
argument_list|)
block|{}
expr|enum
name|IsThisCapture
block|{
name|ThisCapture
block|}
block|;
name|Capture
argument_list|(
argument|IsThisCapture
argument_list|,
argument|bool IsNested
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|QualType CaptureType
argument_list|,
argument|Expr *Cpy
argument_list|,
argument|const bool ByCopy
argument_list|)
operator|:
name|VarAndNestedAndThis
argument_list|(
name|nullptr
argument_list|,
operator|(
name|IsThisCaptured
operator||
operator|(
name|IsNested
condition|?
name|IsNestedCapture
else|:
literal|0
operator|)
operator|)
argument_list|)
block|,
name|InitExprAndCaptureKind
argument_list|(
name|Cpy
argument_list|,
name|ByCopy
condition|?
name|Cap_ByCopy
else|:
name|Cap_ByRef
argument_list|)
block|,
name|Loc
argument_list|(
name|Loc
argument_list|)
block|,
name|EllipsisLoc
argument_list|()
block|,
name|CaptureType
argument_list|(
name|CaptureType
argument_list|)
block|,
name|ODRUsed
argument_list|(
name|false
argument_list|)
block|,
name|NonODRUsed
argument_list|(
argument|false
argument_list|)
block|{}
name|bool
name|isThisCapture
argument_list|()
specifier|const
block|{
return|return
name|VarAndNestedAndThis
operator|.
name|getInt
argument_list|()
operator|&
name|IsThisCaptured
return|;
block|}
name|bool
name|isVariableCapture
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isThisCapture
argument_list|()
operator|&&
operator|!
name|isVLATypeCapture
argument_list|()
return|;
block|}
name|bool
name|isCopyCapture
argument_list|()
specifier|const
block|{
return|return
name|InitExprAndCaptureKind
operator|.
name|getInt
argument_list|()
operator|==
name|Cap_ByCopy
return|;
block|}
name|bool
name|isReferenceCapture
argument_list|()
specifier|const
block|{
return|return
name|InitExprAndCaptureKind
operator|.
name|getInt
argument_list|()
operator|==
name|Cap_ByRef
return|;
block|}
name|bool
name|isBlockCapture
argument_list|()
specifier|const
block|{
return|return
name|InitExprAndCaptureKind
operator|.
name|getInt
argument_list|()
operator|==
name|Cap_Block
return|;
block|}
name|bool
name|isVLATypeCapture
argument_list|()
specifier|const
block|{
return|return
name|InitExprAndCaptureKind
operator|.
name|getInt
argument_list|()
operator|==
name|Cap_VLA
return|;
block|}
name|bool
name|isNested
argument_list|()
specifier|const
block|{
return|return
name|VarAndNestedAndThis
operator|.
name|getInt
argument_list|()
operator|&
name|IsNestedCapture
return|;
block|}
name|bool
name|isODRUsed
argument_list|()
specifier|const
block|{
return|return
name|ODRUsed
return|;
block|}
name|bool
name|isNonODRUsed
argument_list|()
specifier|const
block|{
return|return
name|NonODRUsed
return|;
block|}
name|void
name|markUsed
argument_list|(
argument|bool IsODRUse
argument_list|)
block|{
operator|(
name|IsODRUse
condition|?
name|ODRUsed
else|:
name|NonODRUsed
operator|)
operator|=
name|true
block|; }
name|VarDecl
operator|*
name|getVariable
argument_list|()
specifier|const
block|{
return|return
name|VarAndNestedAndThis
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Retrieve the location at which this variable was captured.
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
comment|/// \brief Retrieve the source location of the ellipsis, whose presence
comment|/// indicates that the capture is a pack expansion.
name|SourceLocation
name|getEllipsisLoc
argument_list|()
specifier|const
block|{
return|return
name|EllipsisLoc
return|;
block|}
comment|/// \brief Retrieve the capture type for this capture, which is effectively
comment|/// the type of the non-static data member in the lambda/block structure
comment|/// that would store this capture.
name|QualType
name|getCaptureType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isThisCapture
argument_list|()
argument_list|)
block|;
return|return
name|CaptureType
return|;
block|}
name|Expr
operator|*
name|getInitExpr
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isVLATypeCapture
argument_list|()
operator|&&
literal|"no init expression for type capture"
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
name|InitExprAndCaptureKind
operator|.
name|getPointer
argument_list|()
operator|)
return|;
block|}
expr|}
block|;
name|CapturingScopeInfo
argument_list|(
argument|DiagnosticsEngine&Diag
argument_list|,
argument|ImplicitCaptureStyle Style
argument_list|)
operator|:
name|FunctionScopeInfo
argument_list|(
name|Diag
argument_list|)
block|,
name|ImpCaptureStyle
argument_list|(
name|Style
argument_list|)
block|,
name|CXXThisCaptureIndex
argument_list|(
literal|0
argument_list|)
block|,
name|HasImplicitReturnType
argument_list|(
argument|false
argument_list|)
block|{}
comment|/// CaptureMap - A map of captured variables to (index+1) into Captures.
name|llvm
operator|::
name|DenseMap
operator|<
name|VarDecl
operator|*
block|,
name|unsigned
operator|>
name|CaptureMap
block|;
comment|/// CXXThisCaptureIndex - The (index+1) of the capture of 'this';
comment|/// zero if 'this' is not captured.
name|unsigned
name|CXXThisCaptureIndex
block|;
comment|/// Captures - The captures.
name|SmallVector
operator|<
name|Capture
block|,
literal|4
operator|>
name|Captures
block|;
comment|/// \brief - Whether the target type of return statements in this context
comment|/// is deduced (e.g. a lambda or block with omitted return type).
name|bool
name|HasImplicitReturnType
block|;
comment|/// ReturnType - The target type of return statements in this context,
comment|/// or null if unknown.
name|QualType
name|ReturnType
block|;
name|void
name|addCapture
argument_list|(
argument|VarDecl *Var
argument_list|,
argument|bool isBlock
argument_list|,
argument|bool isByref
argument_list|,
argument|bool isNested
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|SourceLocation EllipsisLoc
argument_list|,
argument|QualType CaptureType
argument_list|,
argument|Expr *Cpy
argument_list|)
block|{
name|Captures
operator|.
name|push_back
argument_list|(
name|Capture
argument_list|(
name|Var
argument_list|,
name|isBlock
argument_list|,
name|isByref
argument_list|,
name|isNested
argument_list|,
name|Loc
argument_list|,
name|EllipsisLoc
argument_list|,
name|CaptureType
argument_list|,
name|Cpy
argument_list|)
argument_list|)
block|;
name|CaptureMap
index|[
name|Var
index|]
operator|=
name|Captures
operator|.
name|size
argument_list|()
block|;   }
name|void
name|addVLATypeCapture
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|QualType CaptureType
argument_list|)
block|{
name|Captures
operator|.
name|push_back
argument_list|(
name|Capture
argument_list|(
comment|/*Var*/
name|nullptr
argument_list|,
comment|/*isBlock*/
name|false
argument_list|,
comment|/*isByref*/
name|false
argument_list|,
comment|/*isNested*/
name|false
argument_list|,
name|Loc
argument_list|,
comment|/*EllipsisLoc*/
name|SourceLocation
argument_list|()
argument_list|,
name|CaptureType
argument_list|,
comment|/*Cpy*/
name|nullptr
argument_list|)
argument_list|)
block|;   }
comment|// Note, we do not need to add the type of 'this' since that is always
comment|// retrievable from Sema::getCurrentThisType - and is also encoded within the
comment|// type of the corresponding FieldDecl.
name|void
name|addThisCapture
argument_list|(
argument|bool isNested
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|Expr *Cpy
argument_list|,
argument|bool ByCopy
argument_list|)
block|;
comment|/// \brief Determine whether the C++ 'this' is captured.
name|bool
name|isCXXThisCaptured
argument_list|()
specifier|const
block|{
return|return
name|CXXThisCaptureIndex
operator|!=
literal|0
return|;
block|}
comment|/// \brief Retrieve the capture of C++ 'this', if it has been captured.
name|Capture
operator|&
name|getCXXThisCapture
argument_list|()
block|{
name|assert
argument_list|(
name|isCXXThisCaptured
argument_list|()
operator|&&
literal|"this has not been captured"
argument_list|)
block|;
return|return
name|Captures
index|[
name|CXXThisCaptureIndex
operator|-
literal|1
index|]
return|;
block|}
comment|/// \brief Determine whether the given variable has been captured.
name|bool
name|isCaptured
argument_list|(
argument|VarDecl *Var
argument_list|)
specifier|const
block|{
return|return
name|CaptureMap
operator|.
name|count
argument_list|(
name|Var
argument_list|)
return|;
block|}
comment|/// \brief Determine whether the given variable-array type has been captured.
name|bool
name|isVLATypeCaptured
argument_list|(
argument|const VariableArrayType *VAT
argument_list|)
specifier|const
block|;
comment|/// \brief Retrieve the capture of the given variable, if it has been
comment|/// captured already.
name|Capture
operator|&
name|getCapture
argument_list|(
argument|VarDecl *Var
argument_list|)
block|{
name|assert
argument_list|(
name|isCaptured
argument_list|(
name|Var
argument_list|)
operator|&&
literal|"Variable has not been captured"
argument_list|)
block|;
return|return
name|Captures
index|[
name|CaptureMap
index|[
name|Var
index|]
operator|-
literal|1
index|]
return|;
block|}
specifier|const
name|Capture
operator|&
name|getCapture
argument_list|(
argument|VarDecl *Var
argument_list|)
specifier|const
block|{
name|llvm
operator|::
name|DenseMap
operator|<
name|VarDecl
operator|*
block|,
name|unsigned
operator|>
operator|::
name|const_iterator
name|Known
operator|=
name|CaptureMap
operator|.
name|find
argument_list|(
name|Var
argument_list|)
block|;
name|assert
argument_list|(
name|Known
operator|!=
name|CaptureMap
operator|.
name|end
argument_list|()
operator|&&
literal|"Variable has not been captured"
argument_list|)
block|;
return|return
name|Captures
index|[
name|Known
operator|->
name|second
operator|-
literal|1
index|]
return|;
block|}
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
name|Kind
operator|==
name|SK_Block
operator|||
name|FSI
operator|->
name|Kind
operator|==
name|SK_Lambda
operator|||
name|FSI
operator|->
name|Kind
operator|==
name|SK_CapturedRegion
return|;
block|}
expr|}
block|;
comment|/// \brief Retains information about a block that is currently being parsed.
name|class
name|BlockScopeInfo
name|final
operator|:
name|public
name|CapturingScopeInfo
block|{
name|public
operator|:
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
comment|/// BlockType - The function type of the block, if one was given.
comment|/// Its return type may be BuiltinType::Dependent.
name|QualType
name|FunctionType
block|;
name|BlockScopeInfo
argument_list|(
name|DiagnosticsEngine
operator|&
name|Diag
argument_list|,
name|Scope
operator|*
name|BlockScope
argument_list|,
name|BlockDecl
operator|*
name|Block
argument_list|)
operator|:
name|CapturingScopeInfo
argument_list|(
name|Diag
argument_list|,
name|ImpCap_Block
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
name|Kind
operator|=
name|SK_Block
block|;   }
operator|~
name|BlockScopeInfo
argument_list|()
name|override
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
name|Kind
operator|==
name|SK_Block
return|;
block|}
expr|}
block|;
comment|/// \brief Retains information about a captured region.
name|class
name|CapturedRegionScopeInfo
name|final
operator|:
name|public
name|CapturingScopeInfo
block|{
name|public
operator|:
comment|/// \brief The CapturedDecl for this statement.
name|CapturedDecl
operator|*
name|TheCapturedDecl
block|;
comment|/// \brief The captured record type.
name|RecordDecl
operator|*
name|TheRecordDecl
block|;
comment|/// \brief This is the enclosing scope of the captured region.
name|Scope
operator|*
name|TheScope
block|;
comment|/// \brief The implicit parameter for the captured variables.
name|ImplicitParamDecl
operator|*
name|ContextParam
block|;
comment|/// \brief The kind of captured region.
name|unsigned
name|short
name|CapRegionKind
block|;
name|unsigned
name|short
name|OpenMPLevel
block|;
name|CapturedRegionScopeInfo
argument_list|(
argument|DiagnosticsEngine&Diag
argument_list|,
argument|Scope *S
argument_list|,
argument|CapturedDecl *CD
argument_list|,
argument|RecordDecl *RD
argument_list|,
argument|ImplicitParamDecl *Context
argument_list|,
argument|CapturedRegionKind K
argument_list|,
argument|unsigned OpenMPLevel
argument_list|)
operator|:
name|CapturingScopeInfo
argument_list|(
name|Diag
argument_list|,
name|ImpCap_CapturedRegion
argument_list|)
block|,
name|TheCapturedDecl
argument_list|(
name|CD
argument_list|)
block|,
name|TheRecordDecl
argument_list|(
name|RD
argument_list|)
block|,
name|TheScope
argument_list|(
name|S
argument_list|)
block|,
name|ContextParam
argument_list|(
name|Context
argument_list|)
block|,
name|CapRegionKind
argument_list|(
name|K
argument_list|)
block|,
name|OpenMPLevel
argument_list|(
argument|OpenMPLevel
argument_list|)
block|{
name|Kind
operator|=
name|SK_CapturedRegion
block|;   }
operator|~
name|CapturedRegionScopeInfo
argument_list|()
name|override
block|;
comment|/// \brief A descriptive name for the kind of captured region this is.
name|StringRef
name|getRegionName
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|CapRegionKind
condition|)
block|{
case|case
name|CR_Default
case|:
return|return
literal|"default captured statement"
return|;
case|case
name|CR_OpenMP
case|:
return|return
literal|"OpenMP region"
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"Invalid captured region kind!"
argument_list|)
expr_stmt|;
block|}
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
name|Kind
operator|==
name|SK_CapturedRegion
return|;
block|}
expr|}
block|;
name|class
name|LambdaScopeInfo
name|final
operator|:
name|public
name|CapturingScopeInfo
block|{
name|public
operator|:
comment|/// \brief The class that describes the lambda.
name|CXXRecordDecl
operator|*
name|Lambda
block|;
comment|/// \brief The lambda's compiler-generated \c operator().
name|CXXMethodDecl
operator|*
name|CallOperator
block|;
comment|/// \brief Source range covering the lambda introducer [...].
name|SourceRange
name|IntroducerRange
block|;
comment|/// \brief Source location of the '&' or '=' specifying the default capture
comment|/// type, if any.
name|SourceLocation
name|CaptureDefaultLoc
block|;
comment|/// \brief The number of captures in the \c Captures list that are
comment|/// explicit captures.
name|unsigned
name|NumExplicitCaptures
block|;
comment|/// \brief Whether this is a mutable lambda.
name|bool
name|Mutable
block|;
comment|/// \brief Whether the (empty) parameter list is explicit.
name|bool
name|ExplicitParams
block|;
comment|/// \brief Whether any of the capture expressions requires cleanups.
name|CleanupInfo
name|Cleanup
block|;
comment|/// \brief Whether the lambda contains an unexpanded parameter pack.
name|bool
name|ContainsUnexpandedParameterPack
block|;
comment|/// \brief If this is a generic lambda, use this as the depth of
comment|/// each 'auto' parameter, during initial AST construction.
name|unsigned
name|AutoTemplateParameterDepth
block|;
comment|/// \brief Store the list of the auto parameters for a generic lambda.
comment|/// If this is a generic lambda, store the list of the auto
comment|/// parameters converted into TemplateTypeParmDecls into a vector
comment|/// that can be used to construct the generic lambda's template
comment|/// parameter list, during initial AST construction.
name|SmallVector
operator|<
name|TemplateTypeParmDecl
operator|*
block|,
literal|4
operator|>
name|AutoTemplateParams
block|;
comment|/// If this is a generic lambda, and the template parameter
comment|/// list has been created (from the AutoTemplateParams) then
comment|/// store a reference to it (cache it to avoid reconstructing it).
name|TemplateParameterList
operator|*
name|GLTemplateParameterList
block|;
comment|/// \brief Contains all variable-referring-expressions (i.e. DeclRefExprs
comment|///  or MemberExprs) that refer to local variables in a generic lambda
comment|///  or a lambda in a potentially-evaluated-if-used context.
comment|///
comment|///  Potentially capturable variables of a nested lambda that might need
comment|///   to be captured by the lambda are housed here.
comment|///  This is specifically useful for generic lambdas or
comment|///  lambdas within a a potentially evaluated-if-used context.
comment|///  If an enclosing variable is named in an expression of a lambda nested
comment|///  within a generic lambda, we don't always know know whether the variable
comment|///  will truly be odr-used (i.e. need to be captured) by that nested lambda,
comment|///  until its instantiation. But we still need to capture it in the
comment|///  enclosing lambda if all intervening lambdas can capture the variable.
name|llvm
operator|::
name|SmallVector
operator|<
name|Expr
operator|*
block|,
literal|4
operator|>
name|PotentiallyCapturingExprs
block|;
comment|/// \brief Contains all variable-referring-expressions that refer
comment|///  to local variables that are usable as constant expressions and
comment|///  do not involve an odr-use (they may still need to be captured
comment|///  if the enclosing full-expression is instantiation dependent).
name|llvm
operator|::
name|SmallSet
operator|<
name|Expr
operator|*
block|,
literal|8
operator|>
name|NonODRUsedCapturingExprs
block|;
comment|/// Contains all of the variables defined in this lambda that shadow variables
comment|/// that were defined in parent contexts. Used to avoid warnings when the
comment|/// shadowed variables are uncaptured by this lambda.
block|struct
name|ShadowedOuterDecl
block|{
specifier|const
name|VarDecl
operator|*
name|VD
block|;
specifier|const
name|VarDecl
operator|*
name|ShadowedDecl
block|;   }
block|;
name|llvm
operator|::
name|SmallVector
operator|<
name|ShadowedOuterDecl
block|,
literal|4
operator|>
name|ShadowingDecls
block|;
name|SourceLocation
name|PotentialThisCaptureLocation
block|;
name|LambdaScopeInfo
argument_list|(
name|DiagnosticsEngine
operator|&
name|Diag
argument_list|)
operator|:
name|CapturingScopeInfo
argument_list|(
name|Diag
argument_list|,
name|ImpCap_None
argument_list|)
block|,
name|Lambda
argument_list|(
name|nullptr
argument_list|)
block|,
name|CallOperator
argument_list|(
name|nullptr
argument_list|)
block|,
name|NumExplicitCaptures
argument_list|(
literal|0
argument_list|)
block|,
name|Mutable
argument_list|(
name|false
argument_list|)
block|,
name|ExplicitParams
argument_list|(
name|false
argument_list|)
block|,
name|Cleanup
block|{}
block|,
name|ContainsUnexpandedParameterPack
argument_list|(
name|false
argument_list|)
block|,
name|AutoTemplateParameterDepth
argument_list|(
literal|0
argument_list|)
block|,
name|GLTemplateParameterList
argument_list|(
argument|nullptr
argument_list|)
block|{
name|Kind
operator|=
name|SK_Lambda
block|;   }
comment|/// \brief Note when all explicit captures have been added.
name|void
name|finishedExplicitCaptures
argument_list|()
block|{
name|NumExplicitCaptures
operator|=
name|Captures
operator|.
name|size
argument_list|()
block|;   }
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
name|Kind
operator|==
name|SK_Lambda
return|;
block|}
comment|///
comment|/// \brief Add a variable that might potentially be captured by the
comment|/// lambda and therefore the enclosing lambdas.
comment|///
comment|/// This is also used by enclosing lambda's to speculatively capture
comment|/// variables that nested lambda's - depending on their enclosing
comment|/// specialization - might need to capture.
comment|/// Consider:
comment|/// void f(int, int);<-- don't capture
comment|/// void f(const int&, double);<-- capture
comment|/// void foo() {
comment|///   const int x = 10;
comment|///   auto L = [=](auto a) { // capture 'x'
comment|///      return [=](auto b) {
comment|///        f(x, a);  // we may or may not need to capture 'x'
comment|///      };
comment|///   };
comment|/// }
name|void
name|addPotentialCapture
argument_list|(
argument|Expr *VarExpr
argument_list|)
block|{
name|assert
argument_list|(
name|isa
operator|<
name|DeclRefExpr
operator|>
operator|(
name|VarExpr
operator|)
operator|||
name|isa
operator|<
name|MemberExpr
operator|>
operator|(
name|VarExpr
operator|)
argument_list|)
block|;
name|PotentiallyCapturingExprs
operator|.
name|push_back
argument_list|(
name|VarExpr
argument_list|)
block|;   }
name|void
name|addPotentialThisCapture
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|PotentialThisCaptureLocation
operator|=
name|Loc
block|;   }
name|bool
name|hasPotentialThisCapture
argument_list|()
specifier|const
block|{
return|return
name|PotentialThisCaptureLocation
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|/// \brief Mark a variable's reference in a lambda as non-odr using.
comment|///
comment|/// For generic lambdas, if a variable is named in a potentially evaluated
comment|/// expression, where the enclosing full expression is dependent then we
comment|/// must capture the variable (given a default capture).
comment|/// This is accomplished by recording all references to variables
comment|/// (DeclRefExprs or MemberExprs) within said nested lambda in its array of
comment|/// PotentialCaptures. All such variables have to be captured by that lambda,
comment|/// except for as described below.
comment|/// If that variable is usable as a constant expression and is named in a
comment|/// manner that does not involve its odr-use (e.g. undergoes
comment|/// lvalue-to-rvalue conversion, or discarded) record that it is so. Upon the
comment|/// act of analyzing the enclosing full expression (ActOnFinishFullExpr)
comment|/// if we can determine that the full expression is not instantiation-
comment|/// dependent, then we can entirely avoid its capture.
comment|///
comment|///   const int n = 0;
comment|///   [&] (auto x) {
comment|///     (void)+n + x;
comment|///   };
comment|/// Interestingly, this strategy would involve a capture of n, even though
comment|/// it's obviously not odr-used here, because the full-expression is
comment|/// instantiation-dependent.  It could be useful to avoid capturing such
comment|/// variables, even when they are referred to in an instantiation-dependent
comment|/// expression, if we can unambiguously determine that they shall never be
comment|/// odr-used.  This would involve removal of the variable-referring-expression
comment|/// from the array of PotentialCaptures during the lvalue-to-rvalue
comment|/// conversions.  But per the working draft N3797, (post-chicago 2013) we must
comment|/// capture such variables.
comment|/// Before anyone is tempted to implement a strategy for not-capturing 'n',
comment|/// consider the insightful warning in:
comment|///    /cfe-commits/Week-of-Mon-20131104/092596.html
comment|/// "The problem is that the set of captures for a lambda is part of the ABI
comment|///  (since lambda layout can be made visible through inline functions and the
comment|///  like), and there are no guarantees as to which cases we'll manage to build
comment|///  an lvalue-to-rvalue conversion in, when parsing a template -- some
comment|///  seemingly harmless change elsewhere in Sema could cause us to start or stop
comment|///  building such a node. So we need a rule that anyone can implement and get
comment|///  exactly the same result".
comment|///
name|void
name|markVariableExprAsNonODRUsed
argument_list|(
argument|Expr *CapturingVarExpr
argument_list|)
block|{
name|assert
argument_list|(
name|isa
operator|<
name|DeclRefExpr
operator|>
operator|(
name|CapturingVarExpr
operator|)
operator|||
name|isa
operator|<
name|MemberExpr
operator|>
operator|(
name|CapturingVarExpr
operator|)
argument_list|)
block|;
name|NonODRUsedCapturingExprs
operator|.
name|insert
argument_list|(
name|CapturingVarExpr
argument_list|)
block|;   }
name|bool
name|isVariableExprMarkedAsNonODRUsed
argument_list|(
argument|Expr *CapturingVarExpr
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|isa
operator|<
name|DeclRefExpr
operator|>
operator|(
name|CapturingVarExpr
operator|)
operator|||
name|isa
operator|<
name|MemberExpr
operator|>
operator|(
name|CapturingVarExpr
operator|)
argument_list|)
block|;
return|return
name|NonODRUsedCapturingExprs
operator|.
name|count
argument_list|(
name|CapturingVarExpr
argument_list|)
return|;
block|}
name|void
name|removePotentialCapture
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|PotentiallyCapturingExprs
operator|.
name|erase
argument_list|(
name|std
operator|::
name|remove
argument_list|(
name|PotentiallyCapturingExprs
operator|.
name|begin
argument_list|()
argument_list|,
name|PotentiallyCapturingExprs
operator|.
name|end
argument_list|()
argument_list|,
name|E
argument_list|)
argument_list|,
name|PotentiallyCapturingExprs
operator|.
name|end
argument_list|()
argument_list|)
block|;   }
name|void
name|clearPotentialCaptures
argument_list|()
block|{
name|PotentiallyCapturingExprs
operator|.
name|clear
argument_list|()
block|;
name|PotentialThisCaptureLocation
operator|=
name|SourceLocation
argument_list|()
block|;   }
name|unsigned
name|getNumPotentialVariableCaptures
argument_list|()
specifier|const
block|{
return|return
name|PotentiallyCapturingExprs
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|hasPotentialCaptures
argument_list|()
specifier|const
block|{
return|return
name|getNumPotentialVariableCaptures
argument_list|()
operator|||
name|PotentialThisCaptureLocation
operator|.
name|isValid
argument_list|()
return|;
block|}
comment|// When passed the index, returns the VarDecl and Expr associated
comment|// with the index.
name|void
name|getPotentialVariableCapture
argument_list|(
argument|unsigned Idx
argument_list|,
argument|VarDecl *&VD
argument_list|,
argument|Expr *&E
argument_list|)
specifier|const
block|; }
block|;
name|FunctionScopeInfo
operator|::
name|WeakObjectProfileTy
operator|::
name|WeakObjectProfileTy
argument_list|()
operator|:
name|Base
argument_list|(
name|nullptr
argument_list|,
name|false
argument_list|)
block|,
name|Property
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|FunctionScopeInfo
operator|::
name|WeakObjectProfileTy
name|FunctionScopeInfo
operator|::
name|WeakObjectProfileTy
operator|::
name|getSentinel
argument_list|()
block|{
name|FunctionScopeInfo
operator|::
name|WeakObjectProfileTy
name|Result
block|;
name|Result
operator|.
name|Base
operator|.
name|setInt
argument_list|(
name|true
argument_list|)
block|;
return|return
name|Result
return|;
block|}
name|template
operator|<
name|typename
name|ExprT
operator|>
name|void
name|FunctionScopeInfo
operator|::
name|recordUseOfWeak
argument_list|(
argument|const ExprT *E
argument_list|,
argument|bool IsRead
argument_list|)
block|{
name|assert
argument_list|(
name|E
argument_list|)
block|;
name|WeakUseVector
operator|&
name|Uses
operator|=
name|WeakObjectUses
index|[
name|WeakObjectProfileTy
argument_list|(
name|E
argument_list|)
index|]
block|;
name|Uses
operator|.
name|push_back
argument_list|(
name|WeakUseTy
argument_list|(
name|E
argument_list|,
name|IsRead
argument_list|)
argument_list|)
block|; }
specifier|inline
name|void
name|CapturingScopeInfo
operator|::
name|addThisCapture
argument_list|(
argument|bool isNested
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|Expr *Cpy
argument_list|,
argument|const bool ByCopy
argument_list|)
block|{
name|Captures
operator|.
name|push_back
argument_list|(
name|Capture
argument_list|(
name|Capture
operator|::
name|ThisCapture
argument_list|,
name|isNested
argument_list|,
name|Loc
argument_list|,
name|QualType
argument_list|()
argument_list|,
name|Cpy
argument_list|,
name|ByCopy
argument_list|)
argument_list|)
block|;
name|CXXThisCaptureIndex
operator|=
name|Captures
operator|.
name|size
argument_list|()
block|; }
expr|}
comment|// end namespace sema
expr|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

