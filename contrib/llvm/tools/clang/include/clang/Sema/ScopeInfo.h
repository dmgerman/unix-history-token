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
name|BlockDecl
decl_stmt|;
name|class
name|CXXMethodDecl
decl_stmt|;
name|class
name|IdentifierInfo
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
block|}
enum|;
name|public
label|:
comment|/// \brief What kind of scope we are describing.
comment|///
name|ScopeKind
name|Kind
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
comment|/// optimization.
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
block|;   }
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
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const CapturingScopeInfo *BSI
argument_list|)
block|{
return|return
name|true
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
comment|/// \brief Variables used to index into by-copy array captures.
name|llvm
operator|::
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
name|llvm
operator|::
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
specifier|static
name|bool
name|classof
argument_list|(
argument|const LambdaScopeInfo *BSI
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

