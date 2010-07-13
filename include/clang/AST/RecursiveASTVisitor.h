begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- RecursiveASTVisitor.h - Recursive AST Visitor ----------*- C++ -*-===//
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
comment|//  This file defines the RecursiveASTVisitor interface, which recursively
end_comment

begin_comment
comment|//  traverses the entire AST.
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
name|LLVM_CLANG_AST_RECURSIVEASTVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_RECURSIVEASTVISITOR_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclFriend.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclTemplate.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
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
file|"clang/AST/NestedNameSpecifier.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Stmt.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/StmtCXX.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/StmtObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateBase.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TypeLoc.h"
end_include

begin_comment
comment|// The following three macros are used for meta programming.  The code
end_comment

begin_comment
comment|// using them is responsible for defining macro OPERATOR().
end_comment

begin_comment
comment|// All unary operators.
end_comment

begin_define
define|#
directive|define
name|UNARYOP_LIST
parameter_list|()
define|\
value|OPERATOR(PostInc)   OPERATOR(PostDec)         \   OPERATOR(PreInc)    OPERATOR(PreDec)          \   OPERATOR(AddrOf)    OPERATOR(Deref)           \   OPERATOR(Plus)      OPERATOR(Minus)           \   OPERATOR(Not)       OPERATOR(LNot)            \   OPERATOR(Real)      OPERATOR(Imag)            \   OPERATOR(Extension) OPERATOR(OffsetOf)
end_define

begin_comment
comment|// All binary operators (excluding compound assign operators).
end_comment

begin_define
define|#
directive|define
name|BINOP_LIST
parameter_list|()
define|\
value|OPERATOR(PtrMemD)              OPERATOR(PtrMemI)    \   OPERATOR(Mul)   OPERATOR(Div)  OPERATOR(Rem)        \   OPERATOR(Add)   OPERATOR(Sub)  OPERATOR(Shl)        \   OPERATOR(Shr)                                       \                                                       \   OPERATOR(LT)    OPERATOR(GT)   OPERATOR(LE)         \   OPERATOR(GE)    OPERATOR(EQ)   OPERATOR(NE)         \   OPERATOR(And)   OPERATOR(Xor)  OPERATOR(Or)         \   OPERATOR(LAnd)  OPERATOR(LOr)                       \                                                       \   OPERATOR(Assign)                                    \   OPERATOR(Comma)
end_define

begin_comment
comment|// All compound assign operators.
end_comment

begin_define
define|#
directive|define
name|CAO_LIST
parameter_list|()
define|\
value|OPERATOR(Mul) OPERATOR(Div) OPERATOR(Rem) OPERATOR(Add) OPERATOR(Sub) \   OPERATOR(Shl) OPERATOR(Shr) OPERATOR(And) OPERATOR(Or)  OPERATOR(Xor)
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|// A helper macro to implement short-circuiting when recursing.  It
comment|// invokes CALL_EXPR, which must be a method call, on the derived
comment|// object (s.t. a user of RecursiveASTVisitor can override the method
comment|// in CALL_EXPR).
define|#
directive|define
name|TRY_TO
parameter_list|(
name|CALL_EXPR
parameter_list|)
define|\
value|do { if (!getDerived().CALL_EXPR) return false; } while (0)
comment|/// \brief A class that does preorder depth-first traversal on the
comment|/// entire Clang AST and visits each node.
comment|///
comment|/// This class performs three distinct tasks:
comment|///   1. traverse the AST (i.e. go to each node);
comment|///   2. at a given node, walk up the class hierarchy, starting from
comment|///      the node's dynamic type, until the top-most class (e.g. Stmt,
comment|///      Decl, or Type) is reached.
comment|///   3. given a (node, class) combination, where 'class' is some base
comment|///      class of the dynamic type of 'node', call a user-overridable
comment|///      function to actually visit the node.
comment|///
comment|/// These tasks are done by three groups of methods, respectively:
comment|///   1. TraverseDecl(Decl *x) does task #1.  It is the entry point
comment|///      for traversing an AST rooted at x.  This method simply
comment|///      dispatches (i.e. forwards) to TraverseFoo(Foo *x) where Foo
comment|///      is the dynamic type of *x, which calls WalkUpFromFoo(x) and
comment|///      then recursively visits the child nodes of x.
comment|///      TraverseStmt(Stmt *x) and TraverseType(QualType x) work
comment|///      similarly.
comment|///   2. WalkUpFromFoo(Foo *x) does task #2.  It does not try to visit
comment|///      any child node of x.  Instead, it first calls WalkUpFromBar(x)
comment|///      where Bar is the direct parent class of Foo (unless Foo has
comment|///      no parent), and then calls VisitFoo(x) (see the next list item).
comment|///   3. VisitFoo(Foo *x) does task #3.
comment|///
comment|/// These three method groups are tiered (Traverse*> WalkUpFrom*>
comment|/// Visit*).  A method (e.g. Traverse*) may call methods from the same
comment|/// tier (e.g. other Traverse*) or one tier lower (e.g. WalkUpFrom*).
comment|/// It may not call methods from a higher tier.
comment|///
comment|/// Note that since WalkUpFromFoo() calls WalkUpFromBar() (where Bar
comment|/// is Foo's super class) before calling VisitFoo(), the result is
comment|/// that the Visit*() methods for a given node are called in the
comment|/// top-down order (e.g. for a node of type NamedDecl, the order will
comment|/// be VisitDecl(), VisitNamedDecl(), and then VisitNamespaceDecl()).
comment|///
comment|/// This scheme guarantees that all Visit*() calls for the same AST
comment|/// node are grouped together.  In other words, Visit*() methods for
comment|/// different nodes are never interleaved.
comment|///
comment|/// Clients of this visitor should subclass the visitor (providing
comment|/// themselves as the template argument, using the curiously recurring
comment|/// template pattern) and override any of the Traverse*, WalkUpFrom*,
comment|/// and Visit* methods for declarations, types, statements,
comment|/// expressions, or other AST nodes where the visitor should customize
comment|/// behavior.  Most users only need to override Visit*.  Advanced
comment|/// users may override Traverse* and WalkUpFrom* to implement custom
comment|/// traversal strategies.  Returning false from one of these overridden
comment|/// functions will abort the entire traversal.
name|template
operator|<
name|typename
name|Derived
operator|>
name|class
name|RecursiveASTVisitor
block|{
name|public
operator|:
comment|/// \brief Return a reference to the derived class.
name|Derived
operator|&
name|getDerived
argument_list|()
block|{
return|return
operator|*
name|static_cast
operator|<
name|Derived
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
comment|/// \brief Recursively visit a statement or expression, by
comment|/// dispatching to Traverse*() based on the argument's dynamic type.
comment|///
comment|/// \returns false if the visitation was terminated early, true
comment|/// otherwise (including when the argument is NULL).
name|bool
name|TraverseStmt
argument_list|(
name|Stmt
operator|*
name|S
argument_list|)
block|;
comment|/// \brief Recursively visit a type, by dispatching to
comment|/// Traverse*Type() based on the argument's getTypeClass() property.
comment|///
comment|/// \returns false if the visitation was terminated early, true
comment|/// otherwise (including when the argument is a Null type).
name|bool
name|TraverseType
argument_list|(
argument|QualType T
argument_list|)
block|;
comment|/// \brief Recursively visit a type with location, by dispatching to
comment|/// Traverse*TypeLoc() based on the argument type's getTypeClass() property.
comment|///
comment|/// \returns false if the visitation was terminated early, true
comment|/// otherwise (including when the argument is a Null type location).
name|bool
name|TraverseTypeLoc
argument_list|(
argument|TypeLoc TL
argument_list|)
block|;
comment|/// \brief Recursively visit a declaration, by dispatching to
comment|/// Traverse*Decl() based on the argument's dynamic type.
comment|///
comment|/// \returns false if the visitation was terminated early, true
comment|/// otherwise (including when the argument is NULL).
name|bool
name|TraverseDecl
argument_list|(
name|Decl
operator|*
name|D
argument_list|)
block|;
comment|/// \brief Recursively visit a C++ nested-name-specifier.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseNestedNameSpecifier
argument_list|(
name|NestedNameSpecifier
operator|*
name|NNS
argument_list|)
block|;
comment|/// \brief Recursively visit a template name and dispatch to the
comment|/// appropriate method.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseTemplateName
argument_list|(
argument|TemplateName Template
argument_list|)
block|;
comment|/// \brief Recursively visit a template argument and dispatch to the
comment|/// appropriate method for the argument type.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
comment|// FIXME: migrate callers to TemplateArgumentLoc instead.
name|bool
name|TraverseTemplateArgument
argument_list|(
specifier|const
name|TemplateArgument
operator|&
name|Arg
argument_list|)
block|;
comment|/// \brief Recursively visit a template argument location and dispatch to the
comment|/// appropriate method for the argument type.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseTemplateArgumentLoc
argument_list|(
specifier|const
name|TemplateArgumentLoc
operator|&
name|ArgLoc
argument_list|)
block|;
comment|/// \brief Recursively visit a set of template arguments.
comment|/// This can be overridden by a subclass, but it's not expected that
comment|/// will be needed -- this visitor always dispatches to another.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
comment|// FIXME: take a TemplateArgumentLoc* (or TemplateArgumentListInfo) instead.
name|bool
name|TraverseTemplateArguments
argument_list|(
argument|const TemplateArgument *Args
argument_list|,
argument|unsigned NumArgs
argument_list|)
block|;
comment|/// \brief Recursively visit a constructor initializer.  This
comment|/// automatically dispatches to another visitor for the initializer
comment|/// expression, but not for the name of the initializer, so may
comment|/// be overridden for clients that need access to the name.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseConstructorInitializer
argument_list|(
name|CXXBaseOrMemberInitializer
operator|*
name|Init
argument_list|)
block|;
comment|// ---- Methods on Stmts ----
comment|// Declare Traverse*() for all concrete Stmt classes.
define|#
directive|define
name|ABSTRACT_STMT
parameter_list|(
name|STMT
parameter_list|)
define|#
directive|define
name|STMT
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
define|\
value|bool Traverse##CLASS(CLASS *S);
include|#
directive|include
file|"clang/AST/StmtNodes.inc"
comment|// The above header #undefs ABSTRACT_STMT and STMT upon exit.
comment|// Define WalkUpFrom*() and empty Visit*() for all Stmt classes.
name|bool
name|WalkUpFromStmt
argument_list|(
argument|Stmt *S
argument_list|)
block|{
return|return
name|getDerived
argument_list|()
operator|.
name|VisitStmt
argument_list|(
name|S
argument_list|)
return|;
block|}
name|bool
name|VisitStmt
argument_list|(
argument|Stmt *S
argument_list|)
block|{
return|return
name|true
return|;
block|}
define|#
directive|define
name|STMT
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
define|\
value|bool WalkUpFrom##CLASS(CLASS *S) {                            \     TRY_TO(WalkUpFrom##PARENT(S));                              \     TRY_TO(Visit##CLASS(S));                                    \     return true;                                                \   }                                                             \   bool Visit##CLASS(CLASS *S) { return true; }
include|#
directive|include
file|"clang/AST/StmtNodes.inc"
comment|// Define Traverse*(), WalkUpFrom*(), and Visit*() for unary
comment|// operator methods.  Unary operators are not classes in themselves
comment|// (they're all opcodes in UnaryOperator) but do have visitors.
define|#
directive|define
name|OPERATOR
parameter_list|(
name|NAME
parameter_list|)
define|\
value|bool TraverseUnary##NAME(UnaryOperator *S) {                  \     TRY_TO(WalkUpFromUnary##NAME(S));                           \     TRY_TO(TraverseStmt(S->getSubExpr()));                      \     return true;                                                \   }                                                             \   bool WalkUpFromUnary##NAME(UnaryOperator *S) {                \     TRY_TO(WalkUpFromUnaryOperator(S));                         \     TRY_TO(VisitUnary##NAME(S));                                \     return true;                                                \   }                                                             \   bool VisitUnary##NAME(UnaryOperator *S) { return true; }
name|UNARYOP_LIST
argument_list|()
undef|#
directive|undef
name|OPERATOR
comment|// Define Traverse*(), WalkUpFrom*(), and Visit*() for binary
comment|// operator methods.  Binary operators are not classes in themselves
comment|// (they're all opcodes in BinaryOperator) but do have visitors.
define|#
directive|define
name|GENERAL_BINOP_FALLBACK
parameter_list|(
name|NAME
parameter_list|,
name|BINOP_TYPE
parameter_list|)
define|\
value|bool TraverseBin##NAME(BINOP_TYPE *S) {                       \     TRY_TO(WalkUpFromBin##NAME(S));                             \     TRY_TO(TraverseStmt(S->getLHS()));                          \     TRY_TO(TraverseStmt(S->getRHS()));                          \     return true;                                                \   }                                                             \   bool WalkUpFromBin##NAME(BINOP_TYPE *S) {                     \     TRY_TO(WalkUpFrom##BINOP_TYPE(S));                          \     TRY_TO(VisitBin##NAME(S));                                  \     return true;                                                \   }                                                             \   bool VisitBin##NAME(BINOP_TYPE *S) { return true; }
define|#
directive|define
name|OPERATOR
parameter_list|(
name|NAME
parameter_list|)
value|GENERAL_BINOP_FALLBACK(NAME, BinaryOperator)
name|BINOP_LIST
argument_list|()
undef|#
directive|undef
name|OPERATOR
comment|// Define Traverse*(), WalkUpFrom*(), and Visit*() for compound
comment|// assignment methods.  Compound assignment operators are not
comment|// classes in themselves (they're all opcodes in
comment|// CompoundAssignOperator) but do have visitors.
define|#
directive|define
name|OPERATOR
parameter_list|(
name|NAME
parameter_list|)
define|\
value|GENERAL_BINOP_FALLBACK(NAME##Assign, CompoundAssignOperator)
name|CAO_LIST
argument_list|()
undef|#
directive|undef
name|OPERATOR
undef|#
directive|undef
name|GENERAL_BINOP_FALLBACK
comment|// ---- Methods on Types ----
comment|// FIXME: revamp to take TypeLoc's rather than Types.
comment|// Declare Traverse*() for all concrete Type classes.
define|#
directive|define
name|ABSTRACT_TYPE
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|TYPE
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|\
value|bool Traverse##CLASS##Type(CLASS##Type *T);
include|#
directive|include
file|"clang/AST/TypeNodes.def"
comment|// The above header #undefs ABSTRACT_TYPE and TYPE upon exit.
comment|// Define WalkUpFrom*() and empty Visit*() for all Type classes.
name|bool
name|WalkUpFromType
argument_list|(
argument|Type *T
argument_list|)
block|{
return|return
name|getDerived
argument_list|()
operator|.
name|VisitType
argument_list|(
name|T
argument_list|)
return|;
block|}
name|bool
name|VisitType
argument_list|(
argument|Type *T
argument_list|)
block|{
return|return
name|true
return|;
block|}
define|#
directive|define
name|TYPE
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|\
value|bool WalkUpFrom##CLASS##Type(CLASS##Type *T) {                \     TRY_TO(WalkUpFrom##BASE(T));                                \     TRY_TO(Visit##CLASS##Type(T));                              \     return true;                                                \   }                                                             \   bool Visit##CLASS##Type(CLASS##Type *T) { return true; }
include|#
directive|include
file|"clang/AST/TypeNodes.def"
comment|// ---- Methods on TypeLocs ----
comment|// FIXME: this currently just calls the matching Type methods
comment|// Declare Traverse*() for all concrete Type classes.
define|#
directive|define
name|ABSTRACT_TYPELOC
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|TYPELOC
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|\
value|bool Traverse##CLASS##TypeLoc(CLASS##TypeLoc TL);
include|#
directive|include
file|"clang/AST/TypeLocNodes.def"
comment|// The above header #undefs ABSTRACT_TYPELOC and TYPELOC upon exit.
comment|// Define WalkUpFrom*() and empty Visit*() for all TypeLoc classes.
name|bool
name|WalkUpFromTypeLoc
argument_list|(
argument|TypeLoc TL
argument_list|)
block|{
return|return
name|getDerived
argument_list|()
operator|.
name|VisitTypeLoc
argument_list|(
name|TL
argument_list|)
return|;
block|}
name|bool
name|VisitTypeLoc
argument_list|(
argument|TypeLoc TL
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// QualifiedTypeLoc and UnqualTypeLoc are not declared in
comment|// TypeNodes.def and thus need to be handled specially.
name|bool
name|WalkUpFromQualifiedTypeLoc
argument_list|(
argument|QualifiedTypeLoc TL
argument_list|)
block|{
return|return
name|getDerived
argument_list|()
operator|.
name|VisitUnqualTypeLoc
argument_list|(
name|TL
operator|.
name|getUnqualifiedLoc
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|VisitQualifiedTypeLoc
argument_list|(
argument|QualifiedTypeLoc TL
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|bool
name|WalkUpFromUnqualTypeLoc
argument_list|(
argument|UnqualTypeLoc TL
argument_list|)
block|{
return|return
name|getDerived
argument_list|()
operator|.
name|VisitUnqualTypeLoc
argument_list|(
name|TL
operator|.
name|getUnqualifiedLoc
argument_list|()
argument_list|)
return|;
block|}
name|bool
name|VisitUnqualTypeLoc
argument_list|(
argument|UnqualTypeLoc TL
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Note that BASE includes trailing 'Type' which CLASS doesn't.
define|#
directive|define
name|TYPE
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|\
value|bool WalkUpFrom##CLASS##TypeLoc(CLASS##TypeLoc TL) {          \     TRY_TO(WalkUpFrom##BASE##Loc(TL));                          \     TRY_TO(Visit##CLASS##TypeLoc(TL));                          \     return true;                                                \   }                                                             \   bool Visit##CLASS##TypeLoc(CLASS##TypeLoc TL) { return true; }
include|#
directive|include
file|"clang/AST/TypeNodes.def"
comment|// ---- Methods on Decls ----
comment|// Declare Traverse*() for all concrete Decl classes.
define|#
directive|define
name|ABSTRACT_DECL
parameter_list|(
name|DECL
parameter_list|)
define|#
directive|define
name|DECL
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|\
value|bool Traverse##CLASS##Decl(CLASS##Decl *D);
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
comment|// The above header #undefs ABSTRACT_DECL and DECL upon exit.
comment|// Define WalkUpFrom*() and empty Visit*() for all Decl classes.
name|bool
name|WalkUpFromDecl
argument_list|(
argument|Decl *D
argument_list|)
block|{
return|return
name|getDerived
argument_list|()
operator|.
name|VisitDecl
argument_list|(
name|D
argument_list|)
return|;
block|}
name|bool
name|VisitDecl
argument_list|(
argument|Decl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
define|#
directive|define
name|DECL
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|\
value|bool WalkUpFrom##CLASS##Decl(CLASS##Decl *D) {                \     TRY_TO(WalkUpFrom##BASE(D));                                \     TRY_TO(Visit##CLASS##Decl(D));                              \     return true;                                                \   }                                                             \   bool Visit##CLASS##Decl(CLASS##Decl *D) { return true; }
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
name|private
operator|:
comment|// These are helper methods used by more than one Traverse* method.
name|bool
name|TraverseTemplateParameterListHelper
argument_list|(
name|TemplateParameterList
operator|*
name|TPL
argument_list|)
block|;
name|bool
name|TraverseTemplateArgumentLocsHelper
argument_list|(
argument|const TemplateArgumentLoc *TAL
argument_list|,
argument|unsigned Count
argument_list|)
block|;
name|bool
name|TraverseRecordHelper
argument_list|(
name|RecordDecl
operator|*
name|D
argument_list|)
block|;
name|bool
name|TraverseCXXRecordHelper
argument_list|(
name|CXXRecordDecl
operator|*
name|D
argument_list|)
block|;
name|bool
name|TraverseDeclaratorHelper
argument_list|(
name|DeclaratorDecl
operator|*
name|D
argument_list|)
block|;
name|bool
name|TraverseDeclContextHelper
argument_list|(
name|DeclContext
operator|*
name|DC
argument_list|)
block|;
name|bool
name|TraverseFunctionHelper
argument_list|(
name|FunctionDecl
operator|*
name|D
argument_list|)
block|;
name|bool
name|TraverseVarHelper
argument_list|(
name|VarDecl
operator|*
name|D
argument_list|)
block|; }
expr_stmt|;
define|#
directive|define
name|DISPATCH
parameter_list|(
name|NAME
parameter_list|,
name|CLASS
parameter_list|,
name|VAR
parameter_list|)
define|\
value|return getDerived().Traverse##NAME(static_cast<CLASS*>(VAR))
name|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseStmt
argument_list|(
argument|Stmt *S
argument_list|)
block|{
if|if
condition|(
operator|!
name|S
condition|)
return|return
name|true
return|;
comment|// If we have a binary expr, dispatch to the subcode of the binop.  A smart
comment|// optimizer (e.g. LLVM) will fold this comparison into the switch stmt
comment|// below.
if|if
condition|(
name|BinaryOperator
modifier|*
name|BinOp
init|=
name|dyn_cast
operator|<
name|BinaryOperator
operator|>
operator|(
name|S
operator|)
condition|)
block|{
switch|switch
condition|(
name|BinOp
operator|->
name|getOpcode
argument_list|()
condition|)
block|{
define|#
directive|define
name|OPERATOR
parameter_list|(
name|NAME
parameter_list|)
define|\
value|case BinaryOperator::NAME: DISPATCH(Bin##PtrMemD, BinaryOperator, S);
name|BINOP_LIST
argument_list|()
undef|#
directive|undef
name|OPERATOR
undef|#
directive|undef
name|BINOP_LIST
define|#
directive|define
name|OPERATOR
parameter_list|(
name|NAME
parameter_list|)
define|\
value|case BinaryOperator::NAME##Assign:                          \       DISPATCH(Bin##NAME##Assign, CompoundAssignOperator, S);
name|CAO_LIST
argument_list|()
undef|#
directive|undef
name|OPERATOR
undef|#
directive|undef
name|CAO_LIST
block|}
block|}
elseif|else
if|if
condition|(
name|UnaryOperator
modifier|*
name|UnOp
init|=
name|dyn_cast
operator|<
name|UnaryOperator
operator|>
operator|(
name|S
operator|)
condition|)
block|{
switch|switch
condition|(
name|UnOp
operator|->
name|getOpcode
argument_list|()
condition|)
block|{
define|#
directive|define
name|OPERATOR
parameter_list|(
name|NAME
parameter_list|)
define|\
value|case UnaryOperator::NAME: DISPATCH(Unary##NAME, UnaryOperator, S);
name|UNARYOP_LIST
argument_list|()
undef|#
directive|undef
name|OPERATOR
undef|#
directive|undef
name|UNARYOP_LIST
block|}
block|}
comment|// Top switch stmt: dispatch to TraverseFooStmt for each concrete FooStmt.
switch|switch
condition|(
name|S
operator|->
name|getStmtClass
argument_list|()
condition|)
block|{
case|case
name|Stmt
operator|::
name|NoStmtClass
case|:
break|break;
define|#
directive|define
name|ABSTRACT_STMT
parameter_list|(
name|STMT
parameter_list|)
define|#
directive|define
name|STMT
parameter_list|(
name|CLASS
parameter_list|,
name|PARENT
parameter_list|)
define|\
value|case Stmt::CLASS##Class: DISPATCH(CLASS, CLASS, S);
include|#
directive|include
file|"clang/AST/StmtNodes.inc"
block|}
return|return
name|true
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseType
argument_list|(
argument|QualType T
argument_list|)
block|{
if|if
condition|(
name|T
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_switch
switch|switch
condition|(
name|T
operator|->
name|getTypeClass
argument_list|()
condition|)
block|{
define|#
directive|define
name|ABSTRACT_TYPE
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|TYPE
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|\
value|case Type::CLASS: DISPATCH(CLASS##Type, CLASS##Type, T.getTypePtr());
include|#
directive|include
file|"clang/AST/TypeNodes.def"
block|}
end_switch

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseTypeLoc
argument_list|(
argument|TypeLoc TL
argument_list|)
block|{
if|if
condition|(
name|TL
operator|.
name|isNull
argument_list|()
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_switch
switch|switch
condition|(
name|TL
operator|.
name|getTypeLocClass
argument_list|()
condition|)
block|{
define|#
directive|define
name|ABSTRACT_TYPELOC
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|#
directive|define
name|TYPELOC
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|\
value|case TypeLoc::CLASS: \     return getDerived().Traverse##CLASS##TypeLoc(*cast<CLASS##TypeLoc>(&TL));
include|#
directive|include
file|"clang/AST/TypeLocNodes.def"
block|}
end_switch

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}   template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseDecl
argument_list|(
argument|Decl *D
argument_list|)
block|{
if|if
condition|(
operator|!
name|D
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_comment
comment|// As a syntax visitor, we want to ignore declarations for
end_comment

begin_comment
comment|// implicitly-defined declarations (ones not typed explicitly by the
end_comment

begin_comment
comment|// user).
end_comment

begin_if
if|if
condition|(
name|D
operator|->
name|isImplicit
argument_list|()
condition|)
return|return
name|true
return|;
end_if

begin_switch
switch|switch
condition|(
name|D
operator|->
name|getKind
argument_list|()
condition|)
block|{
define|#
directive|define
name|ABSTRACT_DECL
parameter_list|(
name|DECL
parameter_list|)
define|#
directive|define
name|DECL
parameter_list|(
name|CLASS
parameter_list|,
name|BASE
parameter_list|)
define|\
value|case Decl::CLASS: DISPATCH(CLASS##Decl, CLASS##Decl, D);
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
block|}
end_switch

begin_return
return|return
name|true
return|;
end_return

begin_undef
unit|}
undef|#
directive|undef
name|DISPATCH
end_undef

begin_expr_stmt
unit|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseNestedNameSpecifier
argument_list|(
argument|NestedNameSpecifier *NNS
argument_list|)
block|{
if|if
condition|(
operator|!
name|NNS
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|NNS
operator|->
name|getPrefix
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|TraverseNestedNameSpecifier
argument_list|(
name|NNS
operator|->
name|getPrefix
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_if

begin_switch
switch|switch
condition|(
name|NNS
operator|->
name|getKind
argument_list|()
condition|)
block|{
case|case
name|NestedNameSpecifier
operator|::
name|Identifier
case|:
case|case
name|NestedNameSpecifier
operator|::
name|Namespace
case|:
case|case
name|NestedNameSpecifier
operator|::
name|Global
case|:
return|return
name|true
return|;
case|case
name|NestedNameSpecifier
operator|::
name|TypeSpec
case|:
case|case
name|NestedNameSpecifier
operator|::
name|TypeSpecWithTemplate
case|:
name|TRY_TO
argument_list|(
name|TraverseType
argument_list|(
name|QualType
argument_list|(
name|NNS
operator|->
name|getAsType
argument_list|()
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_switch

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseTemplateName
argument_list|(
argument|TemplateName Template
argument_list|)
block|{
if|if
condition|(
name|DependentTemplateName
modifier|*
name|DTN
init|=
name|Template
operator|.
name|getAsDependentTemplateName
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|TraverseNestedNameSpecifier
argument_list|(
name|DTN
operator|->
name|getQualifier
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|QualifiedTemplateName
modifier|*
name|QTN
init|=
name|Template
operator|.
name|getAsQualifiedTemplateName
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|TraverseNestedNameSpecifier
argument_list|(
name|QTN
operator|->
name|getQualifier
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseTemplateArgument
argument_list|(
argument|const TemplateArgument&Arg
argument_list|)
block|{
switch|switch
condition|(
name|Arg
operator|.
name|getKind
argument_list|()
condition|)
block|{
case|case
name|TemplateArgument
operator|::
name|Null
case|:
case|case
name|TemplateArgument
operator|::
name|Declaration
case|:
case|case
name|TemplateArgument
operator|::
name|Integral
case|:
return|return
name|true
return|;
case|case
name|TemplateArgument
operator|::
name|Type
case|:
return|return
name|getDerived
argument_list|()
operator|.
name|TraverseType
argument_list|(
name|Arg
operator|.
name|getAsType
argument_list|()
argument_list|)
return|;
case|case
name|TemplateArgument
operator|::
name|Template
case|:
return|return
name|getDerived
argument_list|()
operator|.
name|TraverseTemplateName
argument_list|(
name|Arg
operator|.
name|getAsTemplate
argument_list|()
argument_list|)
return|;
case|case
name|TemplateArgument
operator|::
name|Expression
case|:
return|return
name|getDerived
argument_list|()
operator|.
name|TraverseStmt
argument_list|(
name|Arg
operator|.
name|getAsExpr
argument_list|()
argument_list|)
return|;
case|case
name|TemplateArgument
operator|::
name|Pack
case|:
return|return
name|getDerived
argument_list|()
operator|.
name|TraverseTemplateArguments
argument_list|(
name|Arg
operator|.
name|pack_begin
argument_list|()
argument_list|,
name|Arg
operator|.
name|pack_size
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|// FIXME: no template name location?
end_comment

begin_comment
comment|// FIXME: no source locations for a template argument pack?
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseTemplateArgumentLoc
argument_list|(
argument|const TemplateArgumentLoc&ArgLoc
argument_list|)
block|{
specifier|const
name|TemplateArgument
operator|&
name|Arg
operator|=
name|ArgLoc
operator|.
name|getArgument
argument_list|()
block|;
switch|switch
condition|(
name|Arg
operator|.
name|getKind
argument_list|()
condition|)
block|{
case|case
name|TemplateArgument
operator|::
name|Null
case|:
case|case
name|TemplateArgument
operator|::
name|Declaration
case|:
case|case
name|TemplateArgument
operator|::
name|Integral
case|:
return|return
name|true
return|;
case|case
name|TemplateArgument
operator|::
name|Type
case|:
block|{
name|TypeSourceInfo
modifier|*
name|TSI
init|=
name|ArgLoc
operator|.
name|getTypeSourceInfo
argument_list|()
decl_stmt|;
return|return
name|getDerived
argument_list|()
operator|.
name|TraverseTypeLoc
argument_list|(
name|TSI
operator|->
name|getTypeLoc
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_case
case|case
name|TemplateArgument
operator|::
name|Template
case|:
end_case

begin_return
return|return
name|getDerived
argument_list|()
operator|.
name|TraverseTemplateName
argument_list|(
name|Arg
operator|.
name|getAsTemplate
argument_list|()
argument_list|)
return|;
end_return

begin_case
case|case
name|TemplateArgument
operator|::
name|Expression
case|:
end_case

begin_return
return|return
name|getDerived
argument_list|()
operator|.
name|TraverseStmt
argument_list|(
name|ArgLoc
operator|.
name|getSourceExpression
argument_list|()
argument_list|)
return|;
end_return

begin_case
case|case
name|TemplateArgument
operator|::
name|Pack
case|:
end_case

begin_return
return|return
name|getDerived
argument_list|()
operator|.
name|TraverseTemplateArguments
argument_list|(
name|Arg
operator|.
name|pack_begin
argument_list|()
argument_list|,
name|Arg
operator|.
name|pack_size
argument_list|()
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    return
name|true
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseTemplateArguments
argument_list|(
argument|const TemplateArgument *Args
argument_list|,
argument|unsigned NumArgs
argument_list|)
block|{
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|!=
name|NumArgs
condition|;
operator|++
name|I
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseTemplateArgument
argument_list|(
name|Args
index|[
name|I
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseConstructorInitializer
argument_list|(
argument|CXXBaseOrMemberInitializer *Init
argument_list|)
block|{
comment|// FIXME: recurse on TypeLoc of the base initializer if isBaseInitializer()?
if|if
condition|(
name|Init
operator|->
name|isWritten
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|Init
operator|->
name|getInit
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|// ----------------- Type traversal -----------------
end_comment

begin_comment
comment|// This macro makes available a variable T, the passed-in type.
end_comment

begin_define
define|#
directive|define
name|DEF_TRAVERSE_TYPE
parameter_list|(
name|TYPE
parameter_list|,
name|CODE
parameter_list|)
define|\
value|template<typename Derived>                                           \   bool RecursiveASTVisitor<Derived>::Traverse##TYPE (TYPE *T) {        \     TRY_TO(WalkUpFrom##TYPE (T));                                      \     { CODE; }                                                          \     return true;                                                       \   }
end_define

begin_expr_stmt
unit|DEF_TRAVERSE_TYPE
operator|(
name|BuiltinType
operator|,
block|{ }
operator|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ComplexType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|PointerType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getPointeeType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|BlockPointerType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getPointeeType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|LValueReferenceType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getPointeeType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|RValueReferenceType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getPointeeType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|MemberPointerType
argument_list|,
argument|{     TRY_TO(TraverseType(QualType(T->getClass(),
literal|0
argument|)));     TRY_TO(TraverseType(T->getPointeeType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ConstantArrayType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|IncompleteArrayType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|VariableArrayType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));     TRY_TO(TraverseStmt(T->getSizeExpr()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DependentSizedArrayType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));     if (T->getSizeExpr())       TRY_TO(TraverseStmt(T->getSizeExpr()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DependentSizedExtVectorType
argument_list|,
argument|{     if (T->getSizeExpr())       TRY_TO(TraverseStmt(T->getSizeExpr()));     TRY_TO(TraverseType(T->getElementType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|VectorType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ExtVectorType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|FunctionNoProtoType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getResultType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|FunctionProtoType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getResultType()));      for (FunctionProtoType::arg_type_iterator A = T->arg_type_begin(),                                            AEnd = T->arg_type_end();          A != AEnd; ++A) {       TRY_TO(TraverseType(*A));     }      for (FunctionProtoType::exception_iterator E = T->exception_begin(),                                             EEnd = T->exception_end();          E != EEnd; ++E) {       TRY_TO(TraverseType(*E));     }   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|UnresolvedUsingType
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TypedefType
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TypeOfExprType
argument_list|,
argument|{     TRY_TO(TraverseStmt(T->getUnderlyingExpr()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TypeOfType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getUnderlyingType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DecltypeType
argument_list|,
argument|{     TRY_TO(TraverseStmt(T->getUnderlyingExpr()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|RecordType
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|EnumType
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TemplateTypeParmType
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|SubstTemplateTypeParmType
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TemplateSpecializationType
argument_list|,
argument|{     TRY_TO(TraverseTemplateName(T->getTemplateName()));     TRY_TO(TraverseTemplateArguments(T->getArgs(), T->getNumArgs()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|InjectedClassNameType
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ElaboratedType
argument_list|,
argument|{     if (T->getQualifier()) {       TRY_TO(TraverseNestedNameSpecifier(T->getQualifier()));     }     TRY_TO(TraverseType(T->getNamedType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DependentNameType
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifier(T->getQualifier()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DependentTemplateSpecializationType
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifier(T->getQualifier()));     TRY_TO(TraverseTemplateArguments(T->getArgs(), T->getNumArgs()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ObjCInterfaceType
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ObjCObjectType
argument_list|,
argument|{
comment|// We have to watch out here because an ObjCInterfaceType's base
comment|// type is itself.
argument|if (T->getBaseType().getTypePtr() != T)       TRY_TO(TraverseType(T->getBaseType()));   }
argument_list|)
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ObjCObjectPointerType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getPointeeType()));   }
argument_list|)
undef|#
directive|undef
name|DEF_TRAVERSE_TYPE
comment|// ----------------- TypeLoc traversal -----------------
comment|// This macro makes available a variable TL, the passed-in TypeLoc.
comment|// It calls WalkUpFrom* for the Type in the given TypeLoc, in addition
comment|// to WalkUpFrom* for the TypeLoc itself, such that existing clients
comment|// that override the WalkUpFrom*Type() and/or Visit*Type() methods
comment|// continue to work.
define|#
directive|define
name|DEF_TRAVERSE_TYPELOC
parameter_list|(
name|TYPE
parameter_list|,
name|CODE
parameter_list|)
define|\
value|template<typename Derived>                                            \   bool RecursiveASTVisitor<Derived>::Traverse##TYPE##Loc(TYPE##Loc TL) { \     TRY_TO(WalkUpFrom##TYPE(TL.getTypePtr()));                          \     TRY_TO(WalkUpFrom##TYPE##Loc(TL));                                  \     { CODE; }                                                           \     return true;                                                        \   }
name|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseQualifiedTypeLoc
argument_list|(
argument|QualifiedTypeLoc TL
argument_list|)
block|{
comment|// Move this over to the 'main' typeloc tree.  Note that this is a
comment|// move -- we pretend that we were really looking at the unqualified
comment|// typeloc all along -- rather than a recursion, so we don't follow
comment|// the normal CRTP plan of going through
comment|// getDerived().TraverseTypeLoc.  If we did, we'd be traversing
comment|// twice for the same type (once as a QualifiedTypeLoc version of
comment|// the type, once as an UnqualifiedTypeLoc version of the type),
comment|// which in effect means we'd call VisitTypeLoc twice with the
comment|// 'same' type.  This solves that problem, at the cost of never
comment|// seeing the qualified version of the type (unless the client
comment|// subclasses TraverseQualifiedTypeLoc themselves).  It's not a
comment|// perfect solution.  A perfect solution probably requires making
comment|// QualifiedTypeLoc a wrapper around TypeLoc -- like QualType is a
comment|// wrapper around Type* -- rather than being its own class in the
comment|// type hierarchy.
return|return
name|TraverseTypeLoc
argument_list|(
name|TL
operator|.
name|getUnqualifiedLoc
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|BuiltinType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_comment
comment|// FIXME: ComplexTypeLoc is unfinished
end_comment

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ComplexType
argument_list|,
argument|{     TRY_TO(TraverseType(TL.getTypePtr()->getElementType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|PointerType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getPointeeLoc()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|BlockPointerType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getPointeeLoc()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|LValueReferenceType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getPointeeLoc()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|RValueReferenceType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getPointeeLoc()));   }
argument_list|)
end_macro

begin_comment
comment|// FIXME: location of base class?
end_comment

begin_comment
comment|// We traverse this in the type case as well, but how is it not reached through
end_comment

begin_comment
comment|// the pointee type?
end_comment

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|MemberPointerType
argument_list|,
argument|{     TRY_TO(TraverseType(QualType(TL.getTypePtr()->getClass(),
literal|0
argument|)));     TRY_TO(TraverseTypeLoc(TL.getPointeeLoc()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ConstantArrayType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getElementLoc()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|IncompleteArrayType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getElementLoc()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|VariableArrayType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getElementLoc()));     TRY_TO(TraverseStmt(TL.getTypePtr()->getSizeExpr()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DependentSizedArrayType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getElementLoc()));     if (TL.getTypePtr()->getSizeExpr())       TRY_TO(TraverseStmt(TL.getTypePtr()->getSizeExpr()));   }
argument_list|)
end_macro

begin_comment
comment|// FIXME: order? why not size expr first?
end_comment

begin_comment
comment|// FIXME: base VectorTypeLoc is unfinished
end_comment

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DependentSizedExtVectorType
argument_list|,
argument|{     if (TL.getTypePtr()->getSizeExpr())       TRY_TO(TraverseStmt(TL.getTypePtr()->getSizeExpr()));     TRY_TO(TraverseType(TL.getTypePtr()->getElementType()));   }
argument_list|)
end_macro

begin_comment
comment|// FIXME: VectorTypeLoc is unfinished
end_comment

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|VectorType
argument_list|,
argument|{     TRY_TO(TraverseType(TL.getTypePtr()->getElementType()));   }
argument_list|)
end_macro

begin_comment
comment|// FIXME: size and attributes
end_comment

begin_comment
comment|// FIXME: base VectorTypeLoc is unfinished
end_comment

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ExtVectorType
argument_list|,
argument|{     TRY_TO(TraverseType(TL.getTypePtr()->getElementType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|FunctionNoProtoType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getResultLoc()));   }
argument_list|)
end_macro

begin_comment
comment|// FIXME: location of arguments, exception specifications (attributes?)
end_comment

begin_comment
comment|// Note that we have the ParmVarDecl's here. Do we want to use them?
end_comment

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|FunctionProtoType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getResultLoc()));      FunctionProtoType *T = TL.getTypePtr();
comment|/*     for (unsigned I = 0, E = TL.getNumArgs(); I != E; ++I) {       TRY_TO(TraverseDecl(TL.getArg(I)));     } */
argument|for (FunctionProtoType::arg_type_iterator A = T->arg_type_begin(),                                            AEnd = T->arg_type_end();          A != AEnd; ++A) {       TRY_TO(TraverseType(*A));     }     for (FunctionProtoType::exception_iterator E = T->exception_begin(),                                             EEnd = T->exception_end();          E != EEnd; ++E) {       TRY_TO(TraverseType(*E));     }   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|UnresolvedUsingType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|TypedefType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|TypeOfExprType
argument_list|,
argument|{     TRY_TO(TraverseStmt(TL.getUnderlyingExpr()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|TypeOfType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getUnderlyingTInfo()->getTypeLoc()));   }
argument_list|)
end_macro

begin_comment
comment|// FIXME: location of underlying expr
end_comment

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DecltypeType
argument_list|,
argument|{     TRY_TO(TraverseStmt(TL.getTypePtr()->getUnderlyingExpr()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|RecordType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|EnumType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|TemplateTypeParmType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|SubstTemplateTypeParmType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_comment
comment|// FIXME: use the loc for the template name?
end_comment

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|TemplateSpecializationType
argument_list|,
argument|{     TRY_TO(TraverseTemplateName(TL.getTypePtr()->getTemplateName()));     for (unsigned I =
literal|0
argument|, E = TL.getNumArgs(); I != E; ++I) {       TRY_TO(TraverseTemplateArgumentLoc(TL.getArgLoc(I)));     }   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|InjectedClassNameType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_comment
comment|// FIXME: use the sourceloc on qualifier?
end_comment

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ElaboratedType
argument_list|,
argument|{     if (TL.getTypePtr()->getQualifier()) {       TRY_TO(TraverseNestedNameSpecifier(TL.getTypePtr()->getQualifier()));     }     TRY_TO(TraverseTypeLoc(TL.getNamedTypeLoc()));   }
argument_list|)
end_macro

begin_comment
comment|// FIXME: use the sourceloc on qualifier?
end_comment

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DependentNameType
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifier(TL.getTypePtr()->getQualifier()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DependentTemplateSpecializationType
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifier(TL.getTypePtr()->getQualifier()));     for (unsigned I =
literal|0
argument|, E = TL.getNumArgs(); I != E; ++I) {       TRY_TO(TraverseTemplateArgumentLoc(TL.getArgLoc(I)));     }   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ObjCInterfaceType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ObjCObjectType
argument_list|,
argument|{
comment|// We have to watch out here because an ObjCInterfaceType's base
comment|// type is itself.
argument|if (TL.getTypePtr()->getBaseType().getTypePtr() != TL.getTypePtr())       TRY_TO(TraverseTypeLoc(TL.getBaseLoc()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ObjCObjectPointerType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getPointeeLoc()));   }
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|DEF_TRAVERSE_TYPELOC
end_undef

begin_comment
comment|// ----------------- Decl traversal -----------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For a Decl, we automate (in the DEF_TRAVERSE_DECL macro) traversing
end_comment

begin_comment
comment|// the children that come from the DeclContext associated with it.
end_comment

begin_comment
comment|// Therefore each Traverse* only needs to worry about children other
end_comment

begin_comment
comment|// than those.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseDeclContextHelper
argument_list|(
argument|DeclContext *DC
argument_list|)
block|{
if|if
condition|(
operator|!
name|DC
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_for
for|for
control|(
name|DeclContext
operator|::
name|decl_iterator
name|Child
operator|=
name|DC
operator|->
name|decls_begin
argument_list|()
operator|,
name|ChildEnd
operator|=
name|DC
operator|->
name|decls_end
argument_list|()
init|;
name|Child
operator|!=
name|ChildEnd
condition|;
operator|++
name|Child
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
operator|*
name|Child
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|// This macro makes available a variable D, the passed-in decl.
end_comment

begin_define
define|#
directive|define
name|DEF_TRAVERSE_DECL
parameter_list|(
name|DECL
parameter_list|,
name|CODE
parameter_list|)
define|\
value|template<typename Derived>                                      \ bool RecursiveASTVisitor<Derived>::Traverse##DECL (DECL *D) {   \   TRY_TO(WalkUpFrom##DECL (D));                                 \   { CODE; }                                                     \   TRY_TO(TraverseDeclContextHelper(dyn_cast<DeclContext>(D)));  \   return true;                                                  \ }
end_define

begin_expr_stmt
unit|DEF_TRAVERSE_DECL
operator|(
name|AccessSpecDecl
operator|,
block|{ }
operator|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|BlockDecl
argument_list|,
argument|{
comment|// We don't traverse nodes in param_begin()/param_end(), as they
comment|// appear in decls_begin()/decls_end() and thus are handled by the
comment|// DEF_TRAVERSE_DECL macro already.
argument|TRY_TO(TraverseStmt(D->getBody()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|FileScopeAsmDecl
argument_list|,
argument|{     TRY_TO(TraverseStmt(D->getAsmString()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|FriendDecl
argument_list|,
argument|{     TRY_TO(TraverseDecl(D->getFriendDecl()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|FriendTemplateDecl
argument_list|,
argument|{     TRY_TO(TraverseDecl(D->getFriendDecl()));     for (unsigned I =
literal|0
argument|, E = D->getNumTemplateParameters(); I< E; ++I) {       TemplateParameterList *TPL = D->getTemplateParameterList(I);       for (TemplateParameterList::iterator ITPL = TPL->begin(),                                            ETPL = TPL->end();            ITPL != ETPL; ++ITPL) {         TRY_TO(TraverseDecl(*ITPL));       }     }   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|LinkageSpecDecl
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCClassDecl
argument_list|,
argument|{
comment|// FIXME: implement this
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCForwardProtocolDecl
argument_list|,
argument|{
comment|// FIXME: implement this
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCPropertyImplDecl
argument_list|,
argument|{
comment|// FIXME: implement this
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|StaticAssertDecl
argument_list|,
argument|{     TRY_TO(TraverseStmt(D->getAssertExpr()));     TRY_TO(TraverseStmt(D->getMessage()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TranslationUnitDecl
argument_list|,
argument|{
comment|// Code in an unnamed namespace shows up automatically in
comment|// decls_begin()/decls_end().  Thus we don't need to recurse on
comment|// D->getAnonymousNamespace().
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|NamespaceAliasDecl
argument_list|,
argument|{
comment|// We shouldn't traverse an aliased namespace, since it will be
comment|// defined (and, therefore, traversed) somewhere else.
comment|//
comment|// This return statement makes sure the traversal of nodes in
comment|// decls_begin()/decls_end() (done in the DEF_TRAVERSE_DECL macro)
comment|// is skipped - don't remove it.
argument|return true;   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|NamespaceDecl
argument_list|,
argument|{
comment|// Code in an unnamed namespace shows up automatically in
comment|// decls_begin()/decls_end().  Thus we don't need to recurse on
comment|// D->getAnonymousNamespace().
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCCompatibleAliasDecl
argument_list|,
argument|{
comment|// FIXME: implement
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCCategoryDecl
argument_list|,
argument|{
comment|// FIXME: implement
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCCategoryImplDecl
argument_list|,
argument|{
comment|// FIXME: implement
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCImplementationDecl
argument_list|,
argument|{
comment|// FIXME: implement
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCInterfaceDecl
argument_list|,
argument|{
comment|// FIXME: implement
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCProtocolDecl
argument_list|,
argument|{
comment|// FIXME: implement
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCMethodDecl
argument_list|,
argument|{
comment|// FIXME: implement
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCPropertyDecl
argument_list|,
argument|{
comment|// FIXME: implement
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UsingDecl
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifier(D->getTargetNestedNameDecl()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UsingDirectiveDecl
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifier(D->getQualifier()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UsingShadowDecl
argument_list|,
argument|{ }
argument_list|)
comment|// A helper method for TemplateDecl's children.
name|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseTemplateParameterListHelper
argument_list|(
argument|TemplateParameterList *TPL
argument_list|)
block|{
if|if
condition|(
name|TPL
condition|)
block|{
for|for
control|(
name|TemplateParameterList
operator|::
name|iterator
name|I
operator|=
name|TPL
operator|->
name|begin
argument_list|()
operator|,
name|E
operator|=
name|TPL
operator|->
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
operator|*
name|I
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}   return
name|true
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|}  DEF_TRAVERSE_DECL
operator|(
name|ClassTemplateDecl
operator|,
block|{
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
name|D
operator|->
name|getTemplatedDecl
argument_list|()
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseTemplateParameterListHelper
argument_list|(
name|D
operator|->
name|getTemplateParameters
argument_list|()
argument_list|)
argument_list|)
block|;
comment|// We should not traverse the specializations/partial
comment|// specializations.  Those will show up in other contexts.
comment|// getInstantiatedFromMemberTemplate() is just a link from a
comment|// template instantiation back to the template from which it was
comment|// instantiated, and thus should not be traversed either.
block|}
operator|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|FunctionTemplateDecl
argument_list|,
argument|{     TRY_TO(TraverseDecl(D->getTemplatedDecl()));     TRY_TO(TraverseTemplateParameterListHelper(D->getTemplateParameters()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TemplateTemplateParmDecl
argument_list|,
argument|{
comment|// D is the "T" in something like
comment|//   template<template<typename> class T> class container { };
argument|TRY_TO(TraverseDecl(D->getTemplatedDecl()));     if (D->hasDefaultArgument()) {       TRY_TO(TraverseTemplateArgumentLoc(D->getDefaultArgument()));     }     TRY_TO(TraverseTemplateParameterListHelper(D->getTemplateParameters()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TemplateTypeParmDecl
argument_list|,
argument|{
comment|// D is the "T" in something like "template<typename T> class vector;"
argument|if (D->hasDefaultArgument())       TRY_TO(TraverseTypeLoc(D->getDefaultArgumentInfo()->getTypeLoc()));     if (D->getTypeForDecl())       TRY_TO(TraverseType(QualType(D->getTypeForDecl(),
literal|0
argument|)));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TypedefDecl
argument_list|,
argument|{     TRY_TO(TraverseType(D->getUnderlyingType()));
comment|// We shouldn't traverse D->getTypeForDecl(); it's a result of
comment|// declaring the typedef, not something that was written in the
comment|// source.
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UnresolvedUsingTypenameDecl
argument_list|,
argument|{
comment|// A dependent using declaration which was marked with 'typename'.
comment|//   template<class T> class A : public B<T> { using typename B<T>::foo; };
argument|TRY_TO(TraverseNestedNameSpecifier(D->getTargetNestedNameSpecifier()));
comment|// We shouldn't traverse D->getTypeForDecl(); it's a result of
comment|// declaring the type, not something that was written in the
comment|// source.
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|EnumDecl
argument_list|,
argument|{     if (D->getTypeForDecl())       TRY_TO(TraverseType(QualType(D->getTypeForDecl(),
literal|0
argument|)));      TRY_TO(TraverseNestedNameSpecifier(D->getQualifier()));
comment|// The enumerators are already traversed by
comment|// decls_begin()/decls_end().
argument|}
argument_list|)
comment|// Helper methods for RecordDecl and its children.
name|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseRecordHelper
argument_list|(
argument|RecordDecl *D
argument_list|)
block|{
comment|// We shouldn't traverse D->getTypeForDecl(); it's a result of
comment|// declaring the type, not something that was written in the source.
comment|//
comment|// The anonymous struct or union object is the variable or field
comment|// whose type is the anonymous struct or union.  We shouldn't
comment|// traverse D->getAnonymousStructOrUnionObject(), as it's not
comment|// something that is explicitly written in the source.
name|TRY_TO
argument_list|(
name|TraverseNestedNameSpecifier
argument_list|(
name|D
operator|->
name|getQualifier
argument_list|()
argument_list|)
argument_list|)
block|;
return|return
name|true
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseCXXRecordHelper
argument_list|(
argument|CXXRecordDecl *D
argument_list|)
block|{
if|if
condition|(
operator|!
name|TraverseRecordHelper
argument_list|(
name|D
argument_list|)
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|D
operator|->
name|hasDefinition
argument_list|()
condition|)
block|{
for|for
control|(
name|CXXRecordDecl
operator|::
name|base_class_iterator
name|I
operator|=
name|D
operator|->
name|bases_begin
argument_list|()
operator|,
name|E
operator|=
name|D
operator|->
name|bases_end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseType
argument_list|(
name|I
operator|->
name|getType
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// We don't traverse the friends or the conversions, as they are
comment|// already in decls_begin()/decls_end().
block|}
end_if

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  DEF_TRAVERSE_DECL
operator|(
name|RecordDecl
operator|,
block|{
name|TRY_TO
argument_list|(
name|TraverseRecordHelper
argument_list|(
name|D
argument_list|)
argument_list|)
block|;   }
operator|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CXXRecordDecl
argument_list|,
argument|{     TRY_TO(TraverseCXXRecordHelper(D));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ClassTemplateSpecializationDecl
argument_list|,
argument|{
comment|// For implicit instantiations ("set<int> x;"), we don't want to
comment|// recurse at all, since the instatiated class isn't written in
comment|// the source code anywhere.  (Note the instatiated *type* --
comment|// set<int> -- is written, and will still get a callback of
comment|// TemplateSpecializationType).  For explicit instantiations
comment|// ("template set<int>;"), we do need a callback, since this
comment|// is the only callback that's made for this instantiation.
comment|// We use getTypeAsWritten() to distinguish.
comment|// FIXME: see how we want to handle template specializations.
argument|if (TypeSourceInfo *TSI = D->getTypeAsWritten())       TRY_TO(TraverseTypeLoc(TSI->getTypeLoc()));     return true;   }
argument_list|)
name|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseTemplateArgumentLocsHelper
argument_list|(
argument|const TemplateArgumentLoc *TAL
argument_list|,
argument|unsigned Count
argument_list|)
block|{
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|;
name|I
operator|<
name|Count
condition|;
operator|++
name|I
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseTemplateArgumentLoc
argument_list|(
name|TAL
index|[
name|I
index|]
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  DEF_TRAVERSE_DECL
operator|(
name|ClassTemplatePartialSpecializationDecl
operator|,
block|{
comment|// The partial specialization.
if|if
condition|(
name|TemplateParameterList
modifier|*
name|TPL
init|=
name|D
operator|->
name|getTemplateParameters
argument_list|()
condition|)
block|{
for|for
control|(
name|TemplateParameterList
operator|::
name|iterator
name|I
operator|=
name|TPL
operator|->
name|begin
argument_list|()
operator|,
name|E
operator|=
name|TPL
operator|->
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
operator|*
name|I
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// The args that remains unspecialized.
end_comment

begin_expr_stmt
unit|TRY_TO
operator|(
name|TraverseTemplateArgumentLocsHelper
argument_list|(
name|D
operator|->
name|getTemplateArgsAsWritten
argument_list|()
argument_list|,
name|D
operator|->
name|getNumTemplateArgsAsWritten
argument_list|()
argument_list|)
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Don't need the ClassTemplatePartialSpecializationHelper, even
end_comment

begin_comment
comment|// though that's our parent class -- we already visit all the
end_comment

begin_comment
comment|// template args here.
end_comment

begin_expr_stmt
name|TRY_TO
argument_list|(
name|TraverseCXXRecordHelper
argument_list|(
name|D
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
unit|})
name|DEF_TRAVERSE_DECL
argument_list|(
argument|EnumConstantDecl
argument_list|,
argument|{     TRY_TO(TraverseStmt(D->getInitExpr()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UnresolvedUsingValueDecl
argument_list|,
argument|{
comment|// Like UnresolvedUsingTypenameDecl, but without the 'typename':
comment|//    template<class T> Class A : public Base<T> { using Base<T>::foo; };
argument|TRY_TO(TraverseNestedNameSpecifier(D->getTargetNestedNameSpecifier()));   }
argument_list|)
end_macro

begin_expr_stmt
name|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseDeclaratorHelper
argument_list|(
argument|DeclaratorDecl *D
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseNestedNameSpecifier
argument_list|(
name|D
operator|->
name|getQualifier
argument_list|()
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|D
operator|->
name|getTypeSourceInfo
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|TraverseTypeLoc
argument_list|(
name|D
operator|->
name|getTypeSourceInfo
argument_list|()
operator|->
name|getTypeLoc
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  DEF_TRAVERSE_DECL
operator|(
name|FieldDecl
operator|,
block|{
name|TRY_TO
argument_list|(
name|TraverseDeclaratorHelper
argument_list|(
name|D
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|D
operator|->
name|isBitField
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|D
operator|->
name|getBitWidth
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_macro
unit|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCAtDefsFieldDecl
argument_list|,
argument|{     TRY_TO(TraverseDeclaratorHelper(D));     if (D->isBitField())       TRY_TO(TraverseStmt(D->getBitWidth()));
comment|// FIXME: implement the rest.
argument|}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCIvarDecl
argument_list|,
argument|{     TRY_TO(TraverseDeclaratorHelper(D));     if (D->isBitField())       TRY_TO(TraverseStmt(D->getBitWidth()));
comment|// FIXME: implement the rest.
argument|}
argument_list|)
end_macro

begin_expr_stmt
name|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseFunctionHelper
argument_list|(
argument|FunctionDecl *D
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseNestedNameSpecifier
argument_list|(
name|D
operator|->
name|getQualifier
argument_list|()
argument_list|)
argument_list|)
block|;
comment|// Visit the function type itself, which can be either
comment|// FunctionNoProtoType or FunctionProtoType, or a typedef.  If it's
comment|// not a Function*ProtoType, then it can't have a body or arguments,
comment|// so we have to do less work.
name|Type
operator|*
name|FuncType
operator|=
name|D
operator|->
name|getType
argument_list|()
operator|.
name|getTypePtr
argument_list|()
block|;
if|if
condition|(
name|FunctionProtoType
modifier|*
name|FuncProto
init|=
name|dyn_cast
operator|<
name|FunctionProtoType
operator|>
operator|(
name|FuncType
operator|)
condition|)
block|{
if|if
condition|(
name|D
operator|->
name|isThisDeclarationADefinition
argument_list|()
condition|)
block|{
comment|// Don't call Traverse*, or the result type and parameter types
comment|// will be double counted.
name|TRY_TO
argument_list|(
name|WalkUpFromFunctionProtoType
argument_list|(
name|FuncProto
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_else
else|else
block|{
comment|// This works around a bug in Clang that does not add the parameters
comment|// to decls_begin/end for function declarations (as opposed to
comment|// definitions):
comment|//    http://llvm.org/PR7442
comment|// We work around this here by traversing the function type.
comment|// This isn't perfect because we don't traverse the default
comment|// values, if any.  It also may not interact great with
comment|// templates.  But it's the best we can do until the bug is
comment|// fixed.
comment|// FIXME: replace the entire 'if' statement with
comment|//   TRY_TO(WalkUpFromFunctionProtoType(FuncProto));
comment|// when the bug is fixed.
name|TRY_TO
argument_list|(
name|TraverseFunctionProtoType
argument_list|(
name|FuncProto
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_else

begin_if
unit|} else
if|if
condition|(
name|FunctionNoProtoType
modifier|*
name|FuncNoProto
init|=
name|dyn_cast
operator|<
name|FunctionNoProtoType
operator|>
operator|(
name|FuncType
operator|)
condition|)
block|{
comment|// Don't call Traverse*, or the result type will be double
comment|// counted.
name|TRY_TO
argument_list|(
name|WalkUpFromFunctionNoProtoType
argument_list|(
name|FuncNoProto
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// a typedef type, or who knows what
name|assert
argument_list|(
operator|!
name|D
operator|->
name|isThisDeclarationADefinition
argument_list|()
operator|&&
literal|"Unexpected function type"
argument_list|)
expr_stmt|;
name|TRY_TO
argument_list|(
name|TraverseType
argument_list|(
name|D
operator|->
name|getType
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_if

begin_expr_stmt
name|TRY_TO
argument_list|(
name|TraverseType
argument_list|(
name|D
operator|->
name|getResultType
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TRY_TO
argument_list|(
name|TraverseDeclContextHelper
argument_list|(
name|D
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Parameters.
end_comment

begin_if
if|if
condition|(
name|CXXConstructorDecl
modifier|*
name|Ctor
init|=
name|dyn_cast
operator|<
name|CXXConstructorDecl
operator|>
operator|(
name|D
operator|)
condition|)
block|{
comment|// Constructor initializers.
for|for
control|(
name|CXXConstructorDecl
operator|::
name|init_iterator
name|I
operator|=
name|Ctor
operator|->
name|init_begin
argument_list|()
operator|,
name|E
operator|=
name|Ctor
operator|->
name|init_end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseConstructorInitializer
argument_list|(
operator|*
name|I
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_if

begin_if
if|if
condition|(
name|D
operator|->
name|isThisDeclarationADefinition
argument_list|()
condition|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|D
operator|->
name|getBody
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// Function body.
block|}
end_if

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  DEF_TRAVERSE_DECL
operator|(
name|FunctionDecl
operator|,
block|{
comment|// We skip decls_begin/decls_end, which are already covered by
comment|// TraverseFunctionHelper().
return|return
name|TraverseFunctionHelper
argument_list|(
name|D
argument_list|)
return|;
block|}
end_expr_stmt

begin_macro
unit|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CXXMethodDecl
argument_list|,
argument|{
comment|// We skip decls_begin/decls_end, which are already covered by
comment|// TraverseFunctionHelper().
argument|return TraverseFunctionHelper(D);   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CXXConstructorDecl
argument_list|,
argument|{
comment|// We skip decls_begin/decls_end, which are already covered by
comment|// TraverseFunctionHelper().
argument|return TraverseFunctionHelper(D);   }
argument_list|)
end_macro

begin_comment
comment|// CXXConversionDecl is the declaration of a type conversion operator.
end_comment

begin_comment
comment|// It's not a cast expression.
end_comment

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CXXConversionDecl
argument_list|,
argument|{
comment|// We skip decls_begin/decls_end, which are already covered by
comment|// TraverseFunctionHelper().
argument|return TraverseFunctionHelper(D);   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CXXDestructorDecl
argument_list|,
argument|{
comment|// We skip decls_begin/decls_end, which are already covered by
comment|// TraverseFunctionHelper().
argument|return TraverseFunctionHelper(D);   }
argument_list|)
end_macro

begin_expr_stmt
name|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseVarHelper
argument_list|(
argument|VarDecl *D
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseDeclaratorHelper
argument_list|(
name|D
argument_list|)
argument_list|)
block|;
comment|// FIXME: This often double-counts -- for instance, for all local
comment|// vars, though not for global vars -- because the initializer is
comment|// also captured when the var-decl is in a DeclStmt.
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|D
operator|->
name|getInit
argument_list|()
argument_list|)
argument_list|)
block|;
return|return
name|true
return|;
block|}
end_expr_stmt

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|VarDecl
argument_list|,
argument|{     TRY_TO(TraverseVarHelper(D));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ImplicitParamDecl
argument_list|,
argument|{     TRY_TO(TraverseVarHelper(D));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|NonTypeTemplateParmDecl
argument_list|,
argument|{
comment|// A non-type template parameter, e.g. "S" in template<int S> class Foo ...
argument|TRY_TO(TraverseStmt(D->getDefaultArgument()));     TRY_TO(TraverseVarHelper(D));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ParmVarDecl
argument_list|,
argument|{     if (D->hasDefaultArg()&&         D->hasUninstantiatedDefaultArg()&&         !D->hasUnparsedDefaultArg())       TRY_TO(TraverseStmt(D->getUninstantiatedDefaultArg()));      if (D->hasDefaultArg()&&         !D->hasUninstantiatedDefaultArg()&&         !D->hasUnparsedDefaultArg())       TRY_TO(TraverseStmt(D->getDefaultArg()));      TRY_TO(TraverseVarHelper(D));   }
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|DEF_TRAVERSE_DECL
end_undef

begin_comment
comment|// ----------------- Stmt traversal -----------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For stmts, we automate (in the DEF_TRAVERSE_STMT macro) iterating
end_comment

begin_comment
comment|// over the children defined in child_begin/child_end (every stmt
end_comment

begin_comment
comment|// defines these, though sometimes the range is empty).  Each
end_comment

begin_comment
comment|// individual Traverse* method only needs to worry about children
end_comment

begin_comment
comment|// other than those.  To see what child_begin()/end() does for a given
end_comment

begin_comment
comment|// class, see, e.g.,
end_comment

begin_comment
comment|// http://clang.llvm.org/doxygen/Stmt_8cpp_source.html
end_comment

begin_comment
comment|// This macro makes available a variable S, the passed-in stmt.
end_comment

begin_define
define|#
directive|define
name|DEF_TRAVERSE_STMT
parameter_list|(
name|STMT
parameter_list|,
name|CODE
parameter_list|)
define|\
value|template<typename Derived>                                              \ bool RecursiveASTVisitor<Derived>::Traverse##STMT (STMT *S) {           \   TRY_TO(WalkUpFrom##STMT(S));                                          \   { CODE; }                                                             \   for (Stmt::child_iterator C = S->child_begin(), CEnd = S->child_end(); \        C != CEnd; ++C) {                                                \     TRY_TO(TraverseStmt(*C));                                           \   }                                                                     \   return true;                                                          \ }
end_define

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|AsmStmt
argument_list|,
argument|{     TRY_TO(TraverseStmt(S->getAsmString()));     for (unsigned I =
literal|0
argument|, E = S->getNumInputs(); I< E; ++I) {       TRY_TO(TraverseStmt(S->getInputConstraintLiteral(I)));     }     for (unsigned I =
literal|0
argument|, E = S->getNumOutputs(); I< E; ++I) {       TRY_TO(TraverseStmt(S->getOutputConstraintLiteral(I)));     }     for (unsigned I =
literal|0
argument|, E = S->getNumClobbers(); I< E; ++I) {       TRY_TO(TraverseStmt(S->getClobber(I)));     }
comment|// child_begin()/end() iterates over inputExpr and outputExpr.
argument|}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXCatchStmt
argument_list|,
argument|{
comment|// We don't traverse S->getCaughtType(), as we are already
comment|// traversing the exception object, which has this type.
comment|// child_begin()/end() iterates over the handler block.
argument|}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ForStmt
argument_list|,
argument|{     TRY_TO(TraverseDecl(S->getConditionVariable()));
comment|// child_begin()/end() iterates over init, cond, inc, and body stmts.
argument|}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|IfStmt
argument_list|,
argument|{     TRY_TO(TraverseDecl(S->getConditionVariable()));
comment|// child_begin()/end() iterates over cond, then, and else stmts.
argument|}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|WhileStmt
argument_list|,
argument|{     TRY_TO(TraverseDecl(S->getConditionVariable()));
comment|// child_begin()/end() iterates over cond, then, and else stmts.
argument|}
argument_list|)
end_macro

begin_comment
comment|// These non-expr stmts (most of them), do not need any action except
end_comment

begin_comment
comment|// iterating over the children.
end_comment

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|BreakStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CompoundStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ContinueStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXTryStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DeclStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DoStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|GotoStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|IndirectGotoStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|LabelStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|NullStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtCatchStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtFinallyStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtSynchronizedStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtThrowStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtTryStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCForCollectionStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ReturnStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SwitchStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SwitchCase
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CaseStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DefaultStmt
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDependentScopeMemberExpr
argument_list|,
argument|{     if (S->hasExplicitTemplateArgs()) {       TRY_TO(TraverseTemplateArgumentLocsHelper(           S->getTemplateArgs(), S->getNumTemplateArgs()));     }     TRY_TO(TraverseNestedNameSpecifier(S->getQualifier()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DeclRefExpr
argument_list|,
argument|{     TRY_TO(TraverseTemplateArgumentLocsHelper(         S->getTemplateArgs(), S->getNumTemplateArgs()));
comment|// FIXME: Should we be recursing on the qualifier?
argument|TRY_TO(TraverseNestedNameSpecifier(S->getQualifier()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DependentScopeDeclRefExpr
argument_list|,
argument|{
comment|// FIXME: Should we be recursing on these two things?
argument|if (S->hasExplicitTemplateArgs()) {       TRY_TO(TraverseTemplateArgumentLocsHelper(           S->getExplicitTemplateArgs().getTemplateArgs(),           S->getNumTemplateArgs()));     }     TRY_TO(TraverseNestedNameSpecifier(S->getQualifier()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|MemberExpr
argument_list|,
argument|{     TRY_TO(TraverseTemplateArgumentLocsHelper(         S->getTemplateArgs(), S->getNumTemplateArgs()));
comment|// FIXME: Should we be recursing on the qualifier?
argument|TRY_TO(TraverseNestedNameSpecifier(S->getQualifier()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ImplicitCastExpr
argument_list|,
argument|{
comment|// We don't traverse the cast type, as it's not written in the
comment|// source code.
argument|}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CStyleCastExpr
argument_list|,
argument|{     TRY_TO(TraverseType(S->getTypeAsWritten()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXFunctionalCastExpr
argument_list|,
argument|{     TRY_TO(TraverseType(S->getTypeAsWritten()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXConstCastExpr
argument_list|,
argument|{     TRY_TO(TraverseType(S->getTypeAsWritten()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDynamicCastExpr
argument_list|,
argument|{     TRY_TO(TraverseType(S->getTypeAsWritten()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXReinterpretCastExpr
argument_list|,
argument|{     TRY_TO(TraverseType(S->getTypeAsWritten()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXStaticCastExpr
argument_list|,
argument|{     TRY_TO(TraverseType(S->getTypeAsWritten()));   }
argument_list|)
end_macro

begin_comment
comment|// InitListExpr is a tricky one, because we want to do all our work on
end_comment

begin_comment
comment|// the syntactic form of the listexpr, but this method takes the
end_comment

begin_comment
comment|// semantic form by default.  We can't use the macro helper because it
end_comment

begin_comment
comment|// calls WalkUp*() on the semantic form, before our code can convert
end_comment

begin_comment
comment|// to the syntactic form.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Derived
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseInitListExpr
argument_list|(
argument|InitListExpr *S
argument_list|)
block|{
if|if
condition|(
name|InitListExpr
modifier|*
name|Syn
init|=
name|S
operator|->
name|getSyntacticForm
argument_list|()
condition|)
name|S
operator|=
name|Syn
expr_stmt|;
name|TRY_TO
argument_list|(
name|WalkUpFromInitListExpr
argument_list|(
name|S
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// All we need are the default actions.  FIXME: use a helper function.
end_comment

begin_for
for|for
control|(
name|Stmt
operator|::
name|child_iterator
name|C
operator|=
name|S
operator|->
name|child_begin
argument_list|()
operator|,
name|CEnd
operator|=
name|S
operator|->
name|child_end
argument_list|()
init|;
name|C
operator|!=
name|CEnd
condition|;
operator|++
name|C
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
operator|*
name|C
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  DEF_TRAVERSE_STMT
operator|(
name|CXXScalarValueInitExpr
operator|,
block|{
comment|// This is called for code like 'return T()' where T is a built-in
comment|// (i.e. non-class) type.
if|if
condition|(
operator|!
name|S
operator|->
name|isImplicit
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|TraverseType
argument_list|(
name|S
operator|->
name|getType
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_macro
unit|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXNewExpr
argument_list|,
argument|{     TRY_TO(TraverseType(S->getAllocatedType()));   }
argument_list|)
end_macro

begin_comment
comment|// These exprs (most of them), do not need any action except iterating
end_comment

begin_comment
comment|// over the children.
end_comment

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|AddrLabelExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ArraySubscriptExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|BlockDeclRefExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|BlockExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ChooseExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CompoundLiteralExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXBindReferenceExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXBindTemporaryExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXBoolLiteralExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDefaultArgExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDeleteExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXExprWithTemporaries
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXNullPtrLiteralExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXPseudoDestructorExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXThisExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXThrowExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXTypeidExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXUnresolvedConstructExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DesignatedInitExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ExtVectorElementExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|GNUNullExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ImplicitValueInitExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCEncodeExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCImplicitSetterGetterRefExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCIsaExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCIvarRefExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCMessageExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCPropertyRefExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCProtocolExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCSelectorExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCSuperExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OffsetOfExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ParenExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ParenListExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|PredefinedExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ShuffleVectorExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SizeOfAlignOfExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|StmtExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|TypesCompatibleExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UnaryTypeTraitExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UnresolvedLookupExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UnresolvedMemberExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|VAArgExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXConstructExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXTemporaryObjectExpr
argument_list|,
argument|{
comment|// This is called for code like 'return T()' where T is a class type.
argument|TRY_TO(TraverseType(S->getType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CallExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXMemberCallExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXOperatorCallExpr
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_comment
comment|// These operators (all of them) do not need any action except
end_comment

begin_comment
comment|// iterating over the children.
end_comment

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ConditionalOperator
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UnaryOperator
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|BinaryOperator
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CompoundAssignOperator
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_comment
comment|// These literals (all of them) do not need any action.
end_comment

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|IntegerLiteral
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CharacterLiteral
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|FloatingLiteral
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ImaginaryLiteral
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|StringLiteral
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCStringLiteral
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_comment
comment|// FIXME: look at the following tricky-seeming exprs to see if we
end_comment

begin_comment
comment|// need to recurse on anything.  These are ones that have methods
end_comment

begin_comment
comment|// returning decls or qualtypes or nestednamespecifier -- though I'm
end_comment

begin_comment
comment|// not sure if they own them -- or just seemed very complicated, or
end_comment

begin_comment
comment|// had lots of sub-types to explore.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// VisitOverloadExpr and its children: recurse on template args? etc?
end_comment

begin_comment
comment|// FIXME: go through all the stmts and exprs again, and see which of them
end_comment

begin_comment
comment|// create new types, and recurse on the types (TypeLocs?) of those.
end_comment

begin_comment
comment|// Candidates:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    http://clang.llvm.org/doxygen/classclang_1_1CXXTypeidExpr.html
end_comment

begin_comment
comment|//    http://clang.llvm.org/doxygen/classclang_1_1SizeOfAlignOfExpr.html
end_comment

begin_comment
comment|//    http://clang.llvm.org/doxygen/classclang_1_1TypesCompatibleExpr.html
end_comment

begin_comment
comment|//    http://clang.llvm.org/doxygen/classclang_1_1CXXUnresolvedConstructExpr.html
end_comment

begin_comment
comment|//    Every class that has getQualifier.
end_comment

begin_undef
undef|#
directive|undef
name|DEF_TRAVERSE_STMT
end_undef

begin_undef
undef|#
directive|undef
name|TRY_TO
end_undef

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_RECURSIVEASTVISITOR_H
end_comment

end_unit

