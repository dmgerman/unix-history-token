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
name|VarDecl
decl_stmt|;
name|class
name|DeclRefExpr
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
decl_stmt|;
comment|/// \brief Whether this function contains a VLA, \@try, try, C++
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
comment|/// \brief Whether a statement was dropped because it was invalid.
name|bool
name|HasDroppedStmt
decl_stmt|;
comment|/// A flag that is set when parsing a method that must call super's
comment|/// implementation, such as \c -dealloc, \c -finalize, or any method marked
comment|/// with \c __attribute__((objc_requires_super)).
name|bool
name|ObjCShouldCallSuper
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
comment|// For use in DenseMap.
name|friend
name|class
name|DenseMapInfo
decl_stmt|;
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
name|ObjCShouldCallSuper
argument_list|(
name|false
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
comment|// There are two categories of capture: capturing 'this', and capturing
comment|// local variables.  There are three ways to capture a local variable:
comment|// capture by copy in the C++11 sense, capture by reference
comment|// in the C++11 sense, and __block capture.  Lambdas explicitly specify
comment|// capture by copy or capture by reference.  For blocks, __block capture
comment|// applies to variables with that annotation, variables of reference type
comment|// are captured by reference, and other variables are captured by copy.
block|enum
name|CaptureKind
block|{
name|Cap_This
block|,
name|Cap_ByCopy
block|,
name|Cap_ByRef
block|,
name|Cap_Block
block|}
block|;
comment|// The variable being captured (if we are not capturing 'this'),
comment|// and misc bits descibing the capture.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|VarDecl
operator|*
block|,
literal|2
block|,
name|CaptureKind
operator|>
name|VarAndKind
block|;
comment|// Expression to initialize a field of the given type, and whether this
comment|// is a nested capture; the expression is only required if we are
comment|// capturing ByVal and the variable's type has a non-trivial
comment|// copy constructor.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|Expr
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|CopyExprAndNested
block|;
comment|/// \brief The source location at which the first capture occurred..
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
name|public
operator|:
name|Capture
argument_list|(
argument|VarDecl *Var
argument_list|,
argument|bool block
argument_list|,
argument|bool byRef
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
operator|:
name|VarAndKind
argument_list|(
name|Var
argument_list|,
name|block
condition|?
name|Cap_Block
else|:
name|byRef
condition|?
name|Cap_ByRef
else|:
name|Cap_ByCopy
argument_list|)
block|,
name|CopyExprAndNested
argument_list|(
name|Cpy
argument_list|,
name|isNested
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
argument|CaptureType
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
argument|bool isNested
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|QualType CaptureType
argument_list|,
argument|Expr *Cpy
argument_list|)
operator|:
name|VarAndKind
argument_list|(
literal|0
argument_list|,
name|Cap_This
argument_list|)
block|,
name|CopyExprAndNested
argument_list|(
name|Cpy
argument_list|,
name|isNested
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
argument|CaptureType
argument_list|)
block|{ }
name|bool
name|isThisCapture
argument_list|()
specifier|const
block|{
return|return
name|VarAndKind
operator|.
name|getInt
argument_list|()
operator|==
name|Cap_This
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
return|;
block|}
name|bool
name|isCopyCapture
argument_list|()
specifier|const
block|{
return|return
name|VarAndKind
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
name|VarAndKind
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
name|VarAndKind
operator|.
name|getInt
argument_list|()
operator|==
name|Cap_Block
return|;
block|}
name|bool
name|isNested
argument_list|()
block|{
return|return
name|CopyExprAndNested
operator|.
name|getInt
argument_list|()
return|;
block|}
name|VarDecl
operator|*
name|getVariable
argument_list|()
specifier|const
block|{
return|return
name|VarAndKind
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
return|return
name|CaptureType
return|;
block|}
name|Expr
operator|*
name|getCopyExpr
argument_list|()
specifier|const
block|{
return|return
name|CopyExprAndNested
operator|.
name|getPointer
argument_list|()
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
name|addThisCapture
argument_list|(
argument|bool isNested
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|QualType CaptureType
argument_list|,
argument|Expr *Cpy
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
name|CapturedRegionKind
name|CapRegionKind
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
argument|K
argument_list|)
block|{
name|Kind
operator|=
name|SK_CapturedRegion
block|;   }
name|virtual
operator|~
name|CapturedRegionScopeInfo
argument_list|()
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
comment|/// \brief The class that describes the lambda.
name|CXXMethodDecl
operator|*
name|CallOperator
block|;
comment|/// \brief Source range covering the lambda introducer [...].
name|SourceRange
name|IntroducerRange
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
name|bool
name|ExprNeedsCleanups
block|;
comment|/// \brief Whether the lambda contains an unexpanded parameter pack.
name|bool
name|ContainsUnexpandedParameterPack
block|;
comment|/// \brief Variables used to index into by-copy array captures.
name|SmallVector
operator|<
name|VarDecl
operator|*
block|,
literal|4
operator|>
name|ArrayIndexVars
block|;
comment|/// \brief Offsets into the ArrayIndexVars array at which each capture starts
comment|/// its list of array index variables.
name|SmallVector
operator|<
name|unsigned
block|,
literal|4
operator|>
name|ArrayIndexStarts
block|;
name|LambdaScopeInfo
argument_list|(
name|DiagnosticsEngine
operator|&
name|Diag
argument_list|,
name|CXXRecordDecl
operator|*
name|Lambda
argument_list|,
name|CXXMethodDecl
operator|*
name|CallOperator
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
name|Lambda
argument_list|)
block|,
name|CallOperator
argument_list|(
name|CallOperator
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
name|ExprNeedsCleanups
argument_list|(
name|false
argument_list|)
block|,
name|ContainsUnexpandedParameterPack
argument_list|(
argument|false
argument_list|)
block|{
name|Kind
operator|=
name|SK_Lambda
block|;   }
name|virtual
operator|~
name|LambdaScopeInfo
argument_list|()
block|;
comment|/// \brief Note when
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
expr|}
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
literal|0
argument_list|,
name|false
argument_list|)
block|,
name|Property
argument_list|(
literal|0
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
name|Capture
operator|::
name|ThisCapture
argument_list|,
name|isNested
argument_list|,
name|Loc
argument_list|,
name|CaptureType
argument_list|,
name|Cpy
argument_list|)
argument_list|)
block|;
name|CXXThisCaptureIndex
operator|=
name|Captures
operator|.
name|size
argument_list|()
block|;
if|if
condition|(
name|LambdaScopeInfo
modifier|*
name|LSI
init|=
name|dyn_cast
operator|<
name|LambdaScopeInfo
operator|>
operator|(
name|this
operator|)
condition|)
name|LSI
operator|->
name|ArrayIndexStarts
operator|.
name|push_back
argument_list|(
name|LSI
operator|->
name|ArrayIndexVars
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
block|}
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

