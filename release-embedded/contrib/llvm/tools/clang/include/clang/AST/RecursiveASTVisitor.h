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
file|"clang/AST/DeclOpenMP.h"
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
file|"clang/AST/StmtOpenMP.h"
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
value|OPERATOR(PostInc)   OPERATOR(PostDec)         \   OPERATOR(PreInc)    OPERATOR(PreDec)          \   OPERATOR(AddrOf)    OPERATOR(Deref)           \   OPERATOR(Plus)      OPERATOR(Minus)           \   OPERATOR(Not)       OPERATOR(LNot)            \   OPERATOR(Real)      OPERATOR(Imag)            \   OPERATOR(Extension)
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
comment|/// top-down order (e.g. for a node of type NamespaceDecl, the order will
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
comment|///
comment|/// By default, this visitor tries to visit every part of the explicit
comment|/// source code exactly once.  The default policy towards templates
comment|/// is to descend into the 'pattern' class or function body, not any
comment|/// explicit or implicit instantiations.  Explicit specializations
comment|/// are still visited, and the patterns of partial specializations
comment|/// are visited separately.  This behavior can be changed by
comment|/// overriding shouldVisitTemplateInstantiations() in the derived class
comment|/// to return true, in which case all known implicit and explicit
comment|/// instantiations will be visited at the same time as the pattern
comment|/// from which they were produced.
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
comment|/// \brief Return whether this visitor should recurse into
comment|/// template instantiations.
name|bool
name|shouldVisitTemplateInstantiations
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Return whether this visitor should recurse into the types of
comment|/// TypeLocs.
name|bool
name|shouldWalkTypesOfTypeLocs
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Return whether this visitor should recurse into implicit
comment|/// code, e.g., implicit constructors and destructors.
name|bool
name|shouldVisitImplicitCode
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Return whether \param S should be traversed using data recursion
comment|/// to avoid a stack overflow with extreme cases.
name|bool
name|shouldUseDataRecursionFor
argument_list|(
argument|Stmt *S
argument_list|)
specifier|const
block|{
return|return
name|isa
operator|<
name|BinaryOperator
operator|>
operator|(
name|S
operator|)
operator|||
name|isa
operator|<
name|UnaryOperator
operator|>
operator|(
name|S
operator|)
operator|||
name|isa
operator|<
name|CaseStmt
operator|>
operator|(
name|S
operator|)
operator|||
name|isa
operator|<
name|CXXOperatorCallExpr
operator|>
operator|(
name|S
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
comment|/// \brief Recursively visit a C++ nested-name-specifier with location
comment|/// information.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseNestedNameSpecifierLoc
argument_list|(
argument|NestedNameSpecifierLoc NNS
argument_list|)
block|;
comment|/// \brief Recursively visit a name with its location information.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseDeclarationNameInfo
argument_list|(
argument|DeclarationNameInfo NameInfo
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
name|CXXCtorInitializer
operator|*
name|Init
argument_list|)
block|;
comment|/// \brief Recursively visit a lambda capture.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseLambdaCapture
argument_list|(
name|LambdaExpr
operator|*
name|LE
argument_list|,
specifier|const
name|LambdaExpr
operator|::
name|Capture
operator|*
name|C
argument_list|)
block|;
comment|/// \brief Recursively visit the body of a lambda expression.
comment|///
comment|/// This provides a hook for visitors that need more context when visiting
comment|/// \c LE->getBody().
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseLambdaBody
argument_list|(
name|LambdaExpr
operator|*
name|LE
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
comment|// Declare Traverse*() for all concrete TypeLoc classes.
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
define|#
directive|define
name|DEF_TRAVERSE_TMPL_INST
parameter_list|(
name|TMPLDECLKIND
parameter_list|)
define|\
value|bool TraverseTemplateInstantiations(TMPLDECLKIND##TemplateDecl *D);
name|DEF_TRAVERSE_TMPL_INST
argument_list|(
argument|Class
argument_list|)
name|DEF_TRAVERSE_TMPL_INST
argument_list|(
argument|Var
argument_list|)
name|DEF_TRAVERSE_TMPL_INST
argument_list|(
argument|Function
argument_list|)
undef|#
directive|undef
name|DEF_TRAVERSE_TMPL_INST
name|bool
name|TraverseTemplateArgumentLocsHelper
argument_list|(
argument|const TemplateArgumentLoc *TAL
argument_list|,
argument|unsigned Count
argument_list|)
block|;
name|bool
name|TraverseArrayTypeLocHelper
argument_list|(
argument|ArrayTypeLoc TL
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
block|;
name|bool
name|TraverseOMPClause
argument_list|(
name|OMPClause
operator|*
name|C
argument_list|)
block|;
define|#
directive|define
name|OPENMP_CLAUSE
parameter_list|(
name|Name
parameter_list|,
name|Class
parameter_list|)
define|\
value|bool Visit##Class(Class *C);
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
comment|/// \brief Process clauses with list of variables.
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|VisitOMPClauseList
argument_list|(
name|T
operator|*
name|Node
argument_list|)
block|;    struct
name|EnqueueJob
block|{
name|Stmt
operator|*
name|S
block|;
name|Stmt
operator|::
name|child_iterator
name|StmtIt
block|;
name|EnqueueJob
argument_list|(
name|Stmt
operator|*
name|S
argument_list|)
operator|:
name|S
argument_list|(
name|S
argument_list|)
block|,
name|StmtIt
argument_list|()
block|{}
block|}
block|;
name|bool
name|dataTraverse
argument_list|(
name|Stmt
operator|*
name|S
argument_list|)
block|;
name|bool
name|dataTraverseNode
argument_list|(
name|Stmt
operator|*
name|S
argument_list|,
name|bool
operator|&
name|EnqueueChildren
argument_list|)
block|; }
expr_stmt|;
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
name|dataTraverse
argument_list|(
argument|Stmt *S
argument_list|)
block|{
name|SmallVector
operator|<
name|EnqueueJob
block|,
literal|16
operator|>
name|Queue
block|;
name|Queue
operator|.
name|push_back
argument_list|(
name|S
argument_list|)
block|;
while|while
condition|(
operator|!
name|Queue
operator|.
name|empty
argument_list|()
condition|)
block|{
name|EnqueueJob
modifier|&
name|job
init|=
name|Queue
operator|.
name|back
argument_list|()
decl_stmt|;
name|Stmt
modifier|*
name|CurrS
init|=
name|job
operator|.
name|S
decl_stmt|;
if|if
condition|(
operator|!
name|CurrS
condition|)
block|{
name|Queue
operator|.
name|pop_back
argument_list|()
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|getDerived
argument_list|()
operator|.
name|shouldUseDataRecursionFor
argument_list|(
name|CurrS
argument_list|)
condition|)
block|{
if|if
condition|(
name|job
operator|.
name|StmtIt
operator|==
name|Stmt
operator|::
name|child_iterator
argument_list|()
condition|)
block|{
name|bool
name|EnqueueChildren
init|=
name|true
decl_stmt|;
if|if
condition|(
operator|!
name|dataTraverseNode
argument_list|(
name|CurrS
argument_list|,
name|EnqueueChildren
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
operator|!
name|EnqueueChildren
condition|)
block|{
name|Queue
operator|.
name|pop_back
argument_list|()
expr_stmt|;
continue|continue;
block|}
name|job
operator|.
name|StmtIt
operator|=
name|CurrS
operator|->
name|child_begin
argument_list|()
expr_stmt|;
block|}
else|else
block|{
operator|++
name|job
operator|.
name|StmtIt
expr_stmt|;
block|}
if|if
condition|(
name|job
operator|.
name|StmtIt
operator|!=
name|CurrS
operator|->
name|child_end
argument_list|()
condition|)
name|Queue
operator|.
name|push_back
argument_list|(
operator|*
name|job
operator|.
name|StmtIt
argument_list|)
expr_stmt|;
else|else
name|Queue
operator|.
name|pop_back
argument_list|()
expr_stmt|;
continue|continue;
block|}
name|Queue
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|CurrS
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
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
name|dataTraverseNode
argument_list|(
argument|Stmt *S
argument_list|,
argument|bool&EnqueueChildren
argument_list|)
block|{
comment|// Dispatch to the corresponding WalkUpFrom* function only if the derived
comment|// class didn't override Traverse* (and thus the traversal is trivial).
define|#
directive|define
name|DISPATCH_WALK
parameter_list|(
name|NAME
parameter_list|,
name|CLASS
parameter_list|,
name|VAR
parameter_list|)
define|\
value|{ \     bool (Derived::*DerivedFn)(CLASS*) =&Derived::Traverse##NAME; \     bool (Derived::*BaseFn)(CLASS*) =&RecursiveASTVisitor::Traverse##NAME; \     if (DerivedFn == BaseFn) \       return getDerived().WalkUpFrom##NAME(static_cast<CLASS*>(VAR)); \   } \   EnqueueChildren = false; \   return getDerived().Traverse##NAME(static_cast<CLASS*>(VAR));
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
value|case BO_##NAME: DISPATCH_WALK(Bin##NAME, BinaryOperator, S);
name|BINOP_LIST
argument_list|()
undef|#
directive|undef
name|OPERATOR
define|#
directive|define
name|OPERATOR
parameter_list|(
name|NAME
parameter_list|)
define|\
value|case BO_##NAME##Assign:                          \     DISPATCH_WALK(Bin##NAME##Assign, CompoundAssignOperator, S);
name|CAO_LIST
argument_list|()
undef|#
directive|undef
name|OPERATOR
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
value|case UO_##NAME: DISPATCH_WALK(Unary##NAME, UnaryOperator, S);
name|UNARYOP_LIST
argument_list|()
undef|#
directive|undef
name|OPERATOR
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
value|case Stmt::CLASS##Class: DISPATCH_WALK(CLASS, CLASS, S);
include|#
directive|include
file|"clang/AST/StmtNodes.inc"
block|}
undef|#
directive|undef
name|DISPATCH_WALK
return|return
name|true
return|;
block|}
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
if|if
condition|(
name|getDerived
argument_list|()
operator|.
name|shouldUseDataRecursionFor
argument_list|(
name|S
argument_list|)
condition|)
return|return
name|dataTraverse
argument_list|(
name|S
argument_list|)
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
value|case BO_##NAME: DISPATCH(Bin##NAME, BinaryOperator, S);
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
value|case BO_##NAME##Assign:                          \       DISPATCH(Bin##NAME##Assign, CompoundAssignOperator, S);
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
value|case UO_##NAME: DISPATCH(Unary##NAME, UnaryOperator, S);
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
value|case Type::CLASS: DISPATCH(CLASS##Type, CLASS##Type, \                              const_cast<Type*>(T.getTypePtr()));
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
value|case TypeLoc::CLASS: \     return getDerived().Traverse##CLASS##TypeLoc(TL.castAs<CLASS##TypeLoc>());
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
comment|// As a syntax visitor, by default we want to ignore declarations for
end_comment

begin_comment
comment|// implicit declarations (ones not typed explicitly by the user).
end_comment

begin_if
if|if
condition|(
operator|!
name|getDerived
argument_list|()
operator|.
name|shouldVisitImplicitCode
argument_list|()
operator|&&
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
name|NamespaceAlias
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
name|TraverseNestedNameSpecifierLoc
argument_list|(
argument|NestedNameSpecifierLoc NNS
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
name|NestedNameSpecifierLoc
name|Prefix
init|=
name|NNS
operator|.
name|getPrefix
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|TraverseNestedNameSpecifierLoc
argument_list|(
name|Prefix
argument_list|)
argument_list|)
expr_stmt|;
end_if

begin_switch
switch|switch
condition|(
name|NNS
operator|.
name|getNestedNameSpecifier
argument_list|()
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
name|NamespaceAlias
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
name|TraverseTypeLoc
argument_list|(
name|NNS
operator|.
name|getTypeLoc
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
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
name|TraverseDeclarationNameInfo
argument_list|(
argument|DeclarationNameInfo NameInfo
argument_list|)
block|{
switch|switch
condition|(
name|NameInfo
operator|.
name|getName
argument_list|()
operator|.
name|getNameKind
argument_list|()
condition|)
block|{
case|case
name|DeclarationName
operator|::
name|CXXConstructorName
case|:
case|case
name|DeclarationName
operator|::
name|CXXDestructorName
case|:
case|case
name|DeclarationName
operator|::
name|CXXConversionFunctionName
case|:
if|if
condition|(
name|TypeSourceInfo
modifier|*
name|TSInfo
init|=
name|NameInfo
operator|.
name|getNamedTypeInfo
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|TraverseTypeLoc
argument_list|(
name|TSInfo
operator|->
name|getTypeLoc
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|DeclarationName
operator|::
name|Identifier
case|:
case|case
name|DeclarationName
operator|::
name|ObjCZeroArgSelector
case|:
case|case
name|DeclarationName
operator|::
name|ObjCOneArgSelector
case|:
case|case
name|DeclarationName
operator|::
name|ObjCMultiArgSelector
case|:
case|case
name|DeclarationName
operator|::
name|CXXOperatorName
case|:
case|case
name|DeclarationName
operator|::
name|CXXLiteralOperatorName
case|:
case|case
name|DeclarationName
operator|::
name|CXXUsingDirective
case|:
break|break;
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
case|case
name|TemplateArgument
operator|::
name|NullPtr
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
case|case
name|TemplateArgument
operator|::
name|TemplateExpansion
case|:
return|return
name|getDerived
argument_list|()
operator|.
name|TraverseTemplateName
argument_list|(
name|Arg
operator|.
name|getAsTemplateOrTemplatePattern
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
case|case
name|TemplateArgument
operator|::
name|NullPtr
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
comment|// FIXME: how can TSI ever be NULL?
if|if
condition|(
name|TypeSourceInfo
modifier|*
name|TSI
init|=
name|ArgLoc
operator|.
name|getTypeSourceInfo
argument_list|()
condition|)
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
else|else
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
block|}
end_expr_stmt

begin_case
case|case
name|TemplateArgument
operator|::
name|Template
case|:
end_case

begin_case
case|case
name|TemplateArgument
operator|::
name|TemplateExpansion
case|:
end_case

begin_if
if|if
condition|(
name|ArgLoc
operator|.
name|getTemplateQualifierLoc
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|getDerived
argument_list|()
operator|.
name|TraverseNestedNameSpecifierLoc
argument_list|(
name|ArgLoc
operator|.
name|getTemplateQualifierLoc
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_if

begin_return
return|return
name|getDerived
argument_list|()
operator|.
name|TraverseTemplateName
argument_list|(
name|Arg
operator|.
name|getAsTemplateOrTemplatePattern
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
argument|CXXCtorInitializer *Init
argument_list|)
block|{
if|if
condition|(
name|TypeSourceInfo
modifier|*
name|TInfo
init|=
name|Init
operator|->
name|getTypeSourceInfo
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|TraverseTypeLoc
argument_list|(
name|TInfo
operator|->
name|getTypeLoc
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Init
operator|->
name|isWritten
argument_list|()
operator|||
name|getDerived
argument_list|()
operator|.
name|shouldVisitImplicitCode
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
end_if

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
name|TraverseLambdaCapture
argument_list|(
argument|LambdaExpr *LE
argument_list|,
argument|const LambdaExpr::Capture *C
argument_list|)
block|{
if|if
condition|(
name|C
operator|->
name|isInitCapture
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
name|C
operator|->
name|getCapturedVar
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
name|TraverseLambdaBody
argument_list|(
argument|LambdaExpr *LE
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|LE
operator|->
name|getBody
argument_list|()
argument_list|)
argument_list|)
block|;
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
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

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|BuiltinType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ComplexType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|PointerType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getPointeeType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|BlockPointerType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getPointeeType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|LValueReferenceType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getPointeeType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|RValueReferenceType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getPointeeType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|MemberPointerType
argument_list|,
argument|{     TRY_TO(TraverseType(QualType(T->getClass(),
literal|0
argument|)));     TRY_TO(TraverseType(T->getPointeeType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DecayedType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getOriginalType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ConstantArrayType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|IncompleteArrayType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|VariableArrayType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));     TRY_TO(TraverseStmt(T->getSizeExpr()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DependentSizedArrayType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));     if (T->getSizeExpr())       TRY_TO(TraverseStmt(T->getSizeExpr()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DependentSizedExtVectorType
argument_list|,
argument|{     if (T->getSizeExpr())       TRY_TO(TraverseStmt(T->getSizeExpr()));     TRY_TO(TraverseType(T->getElementType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|VectorType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ExtVectorType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getElementType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|FunctionNoProtoType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getResultType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|FunctionProtoType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getResultType()));      for (FunctionProtoType::arg_type_iterator A = T->arg_type_begin(),                                            AEnd = T->arg_type_end();          A != AEnd; ++A) {       TRY_TO(TraverseType(*A));     }      for (FunctionProtoType::exception_iterator E = T->exception_begin(),                                             EEnd = T->exception_end();          E != EEnd; ++E) {       TRY_TO(TraverseType(*E));     }   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|UnresolvedUsingType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TypedefType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TypeOfExprType
argument_list|,
argument|{     TRY_TO(TraverseStmt(T->getUnderlyingExpr()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TypeOfType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getUnderlyingType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DecltypeType
argument_list|,
argument|{     TRY_TO(TraverseStmt(T->getUnderlyingExpr()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|UnaryTransformType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getBaseType()));     TRY_TO(TraverseType(T->getUnderlyingType()));     }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|AutoType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getDeducedType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|RecordType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|EnumType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TemplateTypeParmType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|SubstTemplateTypeParmType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|SubstTemplateTypeParmPackType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TemplateSpecializationType
argument_list|,
argument|{     TRY_TO(TraverseTemplateName(T->getTemplateName()));     TRY_TO(TraverseTemplateArguments(T->getArgs(), T->getNumArgs()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|InjectedClassNameType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|AttributedType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getModifiedType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ParenType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getInnerType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ElaboratedType
argument_list|,
argument|{     if (T->getQualifier()) {       TRY_TO(TraverseNestedNameSpecifier(T->getQualifier()));     }     TRY_TO(TraverseType(T->getNamedType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DependentNameType
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifier(T->getQualifier()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DependentTemplateSpecializationType
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifier(T->getQualifier()));     TRY_TO(TraverseTemplateArguments(T->getArgs(), T->getNumArgs()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|PackExpansionType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getPattern()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ObjCInterfaceType
argument_list|,
argument|{ }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ObjCObjectType
argument_list|,
argument|{
comment|// We have to watch out here because an ObjCInterfaceType's base
comment|// type is itself.
argument|if (T->getBaseType().getTypePtr() != T)       TRY_TO(TraverseType(T->getBaseType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ObjCObjectPointerType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getPointeeType()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|AtomicType
argument_list|,
argument|{     TRY_TO(TraverseType(T->getValueType()));   }
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|DEF_TRAVERSE_TYPE
end_undef

begin_comment
comment|// ----------------- TypeLoc traversal -----------------
end_comment

begin_comment
comment|// This macro makes available a variable TL, the passed-in TypeLoc.
end_comment

begin_comment
comment|// If requested, it calls WalkUpFrom* for the Type in the given TypeLoc,
end_comment

begin_comment
comment|// in addition to WalkUpFrom* for the TypeLoc itself, such that existing
end_comment

begin_comment
comment|// clients that override the WalkUpFrom*Type() and/or Visit*Type() methods
end_comment

begin_comment
comment|// continue to work.
end_comment

begin_define
define|#
directive|define
name|DEF_TRAVERSE_TYPELOC
parameter_list|(
name|TYPE
parameter_list|,
name|CODE
parameter_list|)
define|\
value|template<typename Derived>                                            \   bool RecursiveASTVisitor<Derived>::Traverse##TYPE##Loc(TYPE##Loc TL) { \     if (getDerived().shouldWalkTypesOfTypeLocs())                       \       TRY_TO(WalkUpFrom##TYPE(const_cast<TYPE*>(TL.getTypePtr())));     \     TRY_TO(WalkUpFrom##TYPE##Loc(TL));                                  \     { CODE; }                                                           \     return true;                                                        \   }
end_define

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
argument|DecayedType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getOriginalLoc()));   }
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
name|TraverseArrayTypeLocHelper
argument_list|(
argument|ArrayTypeLoc TL
argument_list|)
block|{
comment|// This isn't available for ArrayType, but is for the ArrayTypeLoc.
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|TL
operator|.
name|getSizeExpr
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
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ConstantArrayType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getElementLoc()));     return TraverseArrayTypeLocHelper(TL);   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|IncompleteArrayType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getElementLoc()));     return TraverseArrayTypeLocHelper(TL);   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|VariableArrayType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getElementLoc()));     return TraverseArrayTypeLocHelper(TL);   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DependentSizedArrayType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getElementLoc()));     return TraverseArrayTypeLocHelper(TL);   }
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
comment|// FIXME: location of exception specifications (attributes?)
end_comment

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|FunctionProtoType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getResultLoc()));      const FunctionProtoType *T = TL.getTypePtr();      for (unsigned I =
literal|0
argument|, E = TL.getNumArgs(); I != E; ++I) {       if (TL.getArg(I)) {         TRY_TO(TraverseDecl(TL.getArg(I)));       } else if (I< T->getNumArgs()) {         TRY_TO(TraverseType(T->getArgType(I)));       }     }      for (FunctionProtoType::exception_iterator E = T->exception_begin(),                                             EEnd = T->exception_end();          E != EEnd; ++E) {       TRY_TO(TraverseType(*E));     }   }
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
argument|UnaryTransformType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getUnderlyingTInfo()->getTypeLoc()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|AutoType
argument_list|,
argument|{     TRY_TO(TraverseType(TL.getTypePtr()->getDeducedType()));   }
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

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|SubstTemplateTypeParmPackType
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

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ParenType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getInnerLoc()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|AttributedType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getModifiedLoc()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ElaboratedType
argument_list|,
argument|{     if (TL.getQualifierLoc()) {       TRY_TO(TraverseNestedNameSpecifierLoc(TL.getQualifierLoc()));     }     TRY_TO(TraverseTypeLoc(TL.getNamedTypeLoc()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DependentNameType
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifierLoc(TL.getQualifierLoc()));   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DependentTemplateSpecializationType
argument_list|,
argument|{     if (TL.getQualifierLoc()) {       TRY_TO(TraverseNestedNameSpecifierLoc(TL.getQualifierLoc()));     }      for (unsigned I =
literal|0
argument|, E = TL.getNumArgs(); I != E; ++I) {       TRY_TO(TraverseTemplateArgumentLoc(TL.getArgLoc(I)));     }   }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|PackExpansionType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getPatternLoc()));   }
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

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|AtomicType
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(TL.getValueLoc()));   }
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
comment|// BlockDecls and CapturedDecls are traversed through BlockExprs and
comment|// CapturedStmts respectively.
if|if
condition|(
operator|!
name|isa
operator|<
name|BlockDecl
operator|>
operator|(
operator|*
name|Child
operator|)
operator|&&
operator|!
name|isa
operator|<
name|CapturedDecl
operator|>
operator|(
operator|*
name|Child
operator|)
condition|)
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
argument|{     if (TypeSourceInfo *TInfo = D->getSignatureAsWritten())       TRY_TO(TraverseTypeLoc(TInfo->getTypeLoc()));     TRY_TO(TraverseStmt(D->getBody()));
comment|// This return statement makes sure the traversal of nodes in
comment|// decls_begin()/decls_end() (done in the DEF_TRAVERSE_DECL macro)
comment|// is skipped - don't remove it.
argument|return true;   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CapturedDecl
argument_list|,
argument|{     TRY_TO(TraverseStmt(D->getBody()));
comment|// This return statement makes sure the traversal of nodes in
comment|// decls_begin()/decls_end() (done in the DEF_TRAVERSE_DECL macro)
comment|// is skipped - don't remove it.
argument|return true;   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|EmptyDecl
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|FileScopeAsmDecl
argument_list|,
argument|{     TRY_TO(TraverseStmt(D->getAsmString()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ImportDecl
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|FriendDecl
argument_list|,
argument|{
comment|// Friend is either decl or a type.
argument|if (D->getFriendType())       TRY_TO(TraverseTypeLoc(D->getFriendType()->getTypeLoc()));     else       TRY_TO(TraverseDecl(D->getFriendDecl()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|FriendTemplateDecl
argument_list|,
argument|{     if (D->getFriendType())       TRY_TO(TraverseTypeLoc(D->getFriendType()->getTypeLoc()));     else       TRY_TO(TraverseDecl(D->getFriendDecl()));     for (unsigned I =
literal|0
argument|, E = D->getNumTemplateParameters(); I< E; ++I) {       TemplateParameterList *TPL = D->getTemplateParameterList(I);       for (TemplateParameterList::iterator ITPL = TPL->begin(),                                            ETPL = TPL->end();            ITPL != ETPL; ++ITPL) {         TRY_TO(TraverseDecl(*ITPL));       }     }   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ClassScopeFunctionSpecializationDecl
argument_list|,
argument|{     TRY_TO(TraverseDecl(D->getSpecialization()));      if (D->hasExplicitTemplateArgs()) {       const TemplateArgumentListInfo& args = D->templateArgs();       TRY_TO(TraverseTemplateArgumentLocsHelper(           args.getArgumentArray(), args.size()));     }  }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|LinkageSpecDecl
argument_list|,
argument|{ }
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
argument|LabelDecl
argument_list|,
argument|{
comment|// There is no code in a LabelDecl.
argument|}
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
argument|{     if (D->getResultTypeSourceInfo()) {       TRY_TO(TraverseTypeLoc(D->getResultTypeSourceInfo()->getTypeLoc()));     }     for (ObjCMethodDecl::param_iterator            I = D->param_begin(), E = D->param_end(); I != E; ++I) {       TRY_TO(TraverseDecl(*I));     }     if (D->isThisDeclarationADefinition()) {       TRY_TO(TraverseStmt(D->getBody()));     }     return true;   }
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
argument|{     TRY_TO(TraverseNestedNameSpecifierLoc(D->getQualifierLoc()));     TRY_TO(TraverseDeclarationNameInfo(D->getNameInfo()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UsingDirectiveDecl
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifierLoc(D->getQualifierLoc()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UsingShadowDecl
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|OMPThreadPrivateDecl
argument_list|,
argument|{     for (OMPThreadPrivateDecl::varlist_iterator I = D->varlist_begin(),                                                 E = D->varlist_end();          I != E; ++I) {       TRY_TO(TraverseStmt(*I));     }   }
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

begin_define
unit|}
define|#
directive|define
name|DEF_TRAVERSE_TMPL_INST
parameter_list|(
name|TMPLDECLKIND
parameter_list|)
define|\
comment|/* A helper method for traversing the implicit instantiations of a    class or variable template. */
define|\
value|template<typename Derived>                                                   \ bool RecursiveASTVisitor<Derived>::TraverseTemplateInstantiations(           \     TMPLDECLKIND##TemplateDecl *D) {                                         \   TMPLDECLKIND##TemplateDecl::spec_iterator end = D->spec_end();             \   for (TMPLDECLKIND##TemplateDecl::spec_iterator it = D->spec_begin();       \        it != end; ++it) {                                                    \     TMPLDECLKIND##TemplateSpecializationDecl* SD = *it;                      \                                                                              \     switch (SD->getSpecializationKind()) {                                   \
comment|/* Visit the implicit instantiations with the requested pattern. */
value|\     case TSK_Undeclared:                                                     \     case TSK_ImplicitInstantiation:                                          \       TRY_TO(TraverseDecl(SD));                                              \       break;                                                                 \                                                                              \
comment|/* We don't need to do anything on an explicit instantiation                     or explicit specialization because there will be an explicit        node for it elsewhere. */
value|\     case TSK_ExplicitInstantiationDeclaration:                               \     case TSK_ExplicitInstantiationDefinition:                                \     case TSK_ExplicitSpecialization:                                         \       break;                                                                 \     }                                                                        \   }                                                                          \                                                                              \   return true;                                                               \ }
end_define

begin_expr_stmt
unit|DEF_TRAVERSE_TMPL_INST
operator|(
name|Class
operator|)
name|DEF_TRAVERSE_TMPL_INST
argument_list|(
argument|Var
argument_list|)
comment|// A helper method for traversing the instantiations of a
comment|// function while skipping its specializations.
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
name|TraverseTemplateInstantiations
argument_list|(
argument|FunctionTemplateDecl *D
argument_list|)
block|{
name|FunctionTemplateDecl
operator|::
name|spec_iterator
name|end
operator|=
name|D
operator|->
name|spec_end
argument_list|()
block|;
for|for
control|(
name|FunctionTemplateDecl
operator|::
name|spec_iterator
name|it
operator|=
name|D
operator|->
name|spec_begin
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|FunctionDecl
modifier|*
name|FD
init|=
operator|*
name|it
decl_stmt|;
switch|switch
condition|(
name|FD
operator|->
name|getTemplateSpecializationKind
argument_list|()
condition|)
block|{
case|case
name|TSK_Undeclared
case|:
case|case
name|TSK_ImplicitInstantiation
case|:
comment|// We don't know what kind of FunctionDecl this is.
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
name|FD
argument_list|)
argument_list|)
expr_stmt|;
break|break;
comment|// FIXME: For now traverse explicit instantiations here. Change that
comment|// once they are represented as dedicated nodes in the AST.
case|case
name|TSK_ExplicitInstantiationDeclaration
case|:
case|case
name|TSK_ExplicitInstantiationDefinition
case|:
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
name|FD
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|TSK_ExplicitSpecialization
case|:
break|break;
block|}
end_expr_stmt

begin_expr_stmt
unit|}    return
name|true
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// This macro unifies the traversal of class, variable and function
end_comment

begin_comment
comment|// template declarations.
end_comment

begin_define
define|#
directive|define
name|DEF_TRAVERSE_TMPL_DECL
parameter_list|(
name|TMPLDECLKIND
parameter_list|)
define|\
value|DEF_TRAVERSE_DECL(TMPLDECLKIND##TemplateDecl, {                              \     TRY_TO(TraverseDecl(D->getTemplatedDecl()));                             \     TRY_TO(TraverseTemplateParameterListHelper(D->getTemplateParameters())); \                                                                              \
comment|/* By default, we do not traverse the instantiations of        class templates since they do not appear in the user code. The        following code optionally traverses them.                We only traverse the class instantiations when we see the canonical        declaration of the template, to ensure we only visit them once. */
value|\     if (getDerived().shouldVisitTemplateInstantiations()&&                  \         D == D->getCanonicalDecl())                                          \       TRY_TO(TraverseTemplateInstantiations(D));                             \                                                                              \
comment|/* Note that getInstantiatedFromMemberTemplate() is just a link        from a template instantiation back to the template from which        it was instantiated, and thus should not be traversed. */
value|\   })
end_define

begin_expr_stmt
unit|DEF_TRAVERSE_TMPL_DECL
operator|(
name|Class
operator|)
name|DEF_TRAVERSE_TMPL_DECL
argument_list|(
argument|Var
argument_list|)
name|DEF_TRAVERSE_TMPL_DECL
argument_list|(
argument|Function
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TemplateTemplateParmDecl
argument_list|,
argument|{
comment|// D is the "T" in something like
comment|//   template<template<typename> class T> class container { };
argument|TRY_TO(TraverseDecl(D->getTemplatedDecl()));     if (D->hasDefaultArgument()&& !D->defaultArgumentWasInherited()) {       TRY_TO(TraverseTemplateArgumentLoc(D->getDefaultArgument()));     }     TRY_TO(TraverseTemplateParameterListHelper(D->getTemplateParameters()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TemplateTypeParmDecl
argument_list|,
argument|{
comment|// D is the "T" in something like "template<typename T> class vector;"
argument|if (D->getTypeForDecl())       TRY_TO(TraverseType(QualType(D->getTypeForDecl(),
literal|0
argument|)));     if (D->hasDefaultArgument()&& !D->defaultArgumentWasInherited())       TRY_TO(TraverseTypeLoc(D->getDefaultArgumentInfo()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TypedefDecl
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(D->getTypeSourceInfo()->getTypeLoc()));
comment|// We shouldn't traverse D->getTypeForDecl(); it's a result of
comment|// declaring the typedef, not something that was written in the
comment|// source.
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TypeAliasDecl
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(D->getTypeSourceInfo()->getTypeLoc()));
comment|// We shouldn't traverse D->getTypeForDecl(); it's a result of
comment|// declaring the type alias, not something that was written in the
comment|// source.
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TypeAliasTemplateDecl
argument_list|,
argument|{     TRY_TO(TraverseDecl(D->getTemplatedDecl()));     TRY_TO(TraverseTemplateParameterListHelper(D->getTemplateParameters()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UnresolvedUsingTypenameDecl
argument_list|,
argument|{
comment|// A dependent using declaration which was marked with 'typename'.
comment|//   template<class T> class A : public B<T> { using typename B<T>::foo; };
argument|TRY_TO(TraverseNestedNameSpecifierLoc(D->getQualifierLoc()));
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
argument|)));      TRY_TO(TraverseNestedNameSpecifierLoc(D->getQualifierLoc()));
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
name|TRY_TO
argument_list|(
name|TraverseNestedNameSpecifierLoc
argument_list|(
name|D
operator|->
name|getQualifierLoc
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
name|isCompleteDefinition
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
name|TraverseTypeLoc
argument_list|(
name|I
operator|->
name|getTypeSourceInfo
argument_list|()
operator|->
name|getTypeLoc
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
define|#
directive|define
name|DEF_TRAVERSE_TMPL_SPEC_DECL
parameter_list|(
name|TMPLDECLKIND
parameter_list|)
define|\
value|DEF_TRAVERSE_DECL(TMPLDECLKIND##TemplateSpecializationDecl, {                \
comment|/* For implicit instantiations ("set<int> x;"), we don't want to        recurse at all, since the instatiated template isn't written in        the source code anywhere.  (Note the instatiated *type* --        set<int> -- is written, and will still get a callback of        TemplateSpecializationType).  For explicit instantiations        ("template set<int>;"), we do need a callback, since this        is the only callback that's made for this instantiation.        We use getTypeAsWritten() to distinguish. */
value|\     if (TypeSourceInfo *TSI = D->getTypeAsWritten())                         \       TRY_TO(TraverseTypeLoc(TSI->getTypeLoc()));                            \                                                                              \     if (!getDerived().shouldVisitTemplateInstantiations()&&                 \         D->getTemplateSpecializationKind() != TSK_ExplicitSpecialization)    \
comment|/* Returning from here skips traversing the          declaration context of the *TemplateSpecializationDecl          (embedded in the DEF_TRAVERSE_DECL() macro)          which contains the instantiated members of the template. */
value|\       return true;                                                           \   })
name|DEF_TRAVERSE_TMPL_SPEC_DECL
argument_list|(
argument|Class
argument_list|)
name|DEF_TRAVERSE_TMPL_SPEC_DECL
argument_list|(
argument|Var
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

begin_define
unit|}
define|#
directive|define
name|DEF_TRAVERSE_TMPL_PART_SPEC_DECL
parameter_list|(
name|TMPLDECLKIND
parameter_list|,
name|DECLKIND
parameter_list|)
define|\
value|DEF_TRAVERSE_DECL(TMPLDECLKIND##TemplatePartialSpecializationDecl, {         \
comment|/* The partial specialization. */
value|\     if (TemplateParameterList *TPL = D->getTemplateParameters()) {           \       for (TemplateParameterList::iterator I = TPL->begin(), E = TPL->end(); \            I != E; ++I) {                                                    \         TRY_TO(TraverseDecl(*I));                                            \       }                                                                      \     }                                                                        \
comment|/* The args that remains unspecialized. */
value|\     TRY_TO(TraverseTemplateArgumentLocsHelper(                               \                       D->getTemplateArgsAsWritten()->getTemplateArgs(),      \                       D->getTemplateArgsAsWritten()->NumTemplateArgs));      \                                                                              \
comment|/* Don't need the *TemplatePartialSpecializationHelper, even        though that's our parent class -- we already visit all the        template args here. */
value|\     TRY_TO(Traverse##DECLKIND##Helper(D));                                   \                                                                              \
comment|/* Instantiations will have been visited with the primary template. */
value|\   })
end_define

begin_expr_stmt
unit|DEF_TRAVERSE_TMPL_PART_SPEC_DECL
operator|(
name|Class
operator|,
name|CXXRecord
operator|)
name|DEF_TRAVERSE_TMPL_PART_SPEC_DECL
argument_list|(
argument|Var
argument_list|,
argument|Var
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|EnumConstantDecl
argument_list|,
argument|{     TRY_TO(TraverseStmt(D->getInitExpr()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UnresolvedUsingValueDecl
argument_list|,
argument|{
comment|// Like UnresolvedUsingTypenameDecl, but without the 'typename':
comment|//    template<class T> Class A : public Base<T> { using Base<T>::foo; };
argument|TRY_TO(TraverseNestedNameSpecifierLoc(D->getQualifierLoc()));     TRY_TO(TraverseDeclarationNameInfo(D->getNameInfo()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|IndirectFieldDecl
argument_list|,
argument|{}
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
name|TraverseDeclaratorHelper
argument_list|(
argument|DeclaratorDecl *D
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseNestedNameSpecifierLoc
argument_list|(
name|D
operator|->
name|getQualifierLoc
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
else|else
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
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_expr_stmt
unit|}  DEF_TRAVERSE_DECL
operator|(
name|MSPropertyDecl
operator|,
block|{
name|TRY_TO
argument_list|(
name|TraverseDeclaratorHelper
argument_list|(
name|D
argument_list|)
argument_list|)
block|;   }
operator|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|FieldDecl
argument_list|,
argument|{     TRY_TO(TraverseDeclaratorHelper(D));     if (D->isBitField())       TRY_TO(TraverseStmt(D->getBitWidth()));     else if (D->hasInClassInitializer())       TRY_TO(TraverseStmt(D->getInClassInitializer()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCAtDefsFieldDecl
argument_list|,
argument|{     TRY_TO(TraverseDeclaratorHelper(D));     if (D->isBitField())       TRY_TO(TraverseStmt(D->getBitWidth()));
comment|// FIXME: implement the rest.
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCIvarDecl
argument_list|,
argument|{     TRY_TO(TraverseDeclaratorHelper(D));     if (D->isBitField())       TRY_TO(TraverseStmt(D->getBitWidth()));
comment|// FIXME: implement the rest.
argument|}
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
name|TraverseFunctionHelper
argument_list|(
argument|FunctionDecl *D
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseNestedNameSpecifierLoc
argument_list|(
name|D
operator|->
name|getQualifierLoc
argument_list|()
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseDeclarationNameInfo
argument_list|(
name|D
operator|->
name|getNameInfo
argument_list|()
argument_list|)
argument_list|)
block|;
comment|// If we're an explicit template specialization, iterate over the
comment|// template args that were explicitly specified.  If we were doing
comment|// this in typing order, we'd do it between the return type and
comment|// the function args, but both are handled by the FunctionTypeLoc
comment|// above, so we have to choose one side.  I've decided to do before.
if|if
condition|(
specifier|const
name|FunctionTemplateSpecializationInfo
modifier|*
name|FTSI
init|=
name|D
operator|->
name|getTemplateSpecializationInfo
argument_list|()
condition|)
block|{
if|if
condition|(
name|FTSI
operator|->
name|getTemplateSpecializationKind
argument_list|()
operator|!=
name|TSK_Undeclared
operator|&&
name|FTSI
operator|->
name|getTemplateSpecializationKind
argument_list|()
operator|!=
name|TSK_ImplicitInstantiation
condition|)
block|{
comment|// A specialization might not have explicit template arguments if it has
comment|// a templated return type and concrete arguments.
if|if
condition|(
specifier|const
name|ASTTemplateArgumentListInfo
modifier|*
name|TALI
init|=
name|FTSI
operator|->
name|TemplateArgumentsAsWritten
condition|)
block|{
name|TRY_TO
argument_list|(
name|TraverseTemplateArgumentLocsHelper
argument_list|(
name|TALI
operator|->
name|getTemplateArgs
argument_list|()
argument_list|,
name|TALI
operator|->
name|NumTemplateArgs
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}   }
comment|// Visit the function type itself, which can be either
end_comment

begin_comment
comment|// FunctionNoProtoType or FunctionProtoType, or a typedef.  This
end_comment

begin_comment
comment|// also covers the return type and the function parameters,
end_comment

begin_comment
comment|// including exception specifications.
end_comment

begin_if
if|if
condition|(
name|TypeSourceInfo
modifier|*
name|TSI
init|=
name|D
operator|->
name|getTypeSourceInfo
argument_list|()
condition|)
block|{
name|TRY_TO
argument_list|(
name|TraverseTypeLoc
argument_list|(
name|TSI
operator|->
name|getTypeLoc
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|getDerived
argument_list|()
operator|.
name|shouldVisitImplicitCode
argument_list|()
condition|)
block|{
comment|// Visit parameter variable declarations of the implicit function
comment|// if the traverser is visiting implicit code. Parameter variable
comment|// declarations do not have valid TypeSourceInfo, so to visit them
comment|// we need to traverse the declarations explicitly.
for|for
control|(
name|FunctionDecl
operator|::
name|param_const_iterator
name|I
operator|=
name|D
operator|->
name|param_begin
argument_list|()
operator|,
name|E
operator|=
name|D
operator|->
name|param_end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
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
end_if

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
comment|// Default params are taken care of when we traverse the ParmVarDecl.
if|if
condition|(
operator|!
name|isa
operator|<
name|ParmVarDecl
operator|>
operator|(
name|D
operator|)
operator|&&
operator|(
operator|!
name|D
operator|->
name|isCXXForRangeDecl
argument_list|()
operator|||
name|getDerived
argument_list|()
operator|.
name|shouldVisitImplicitCode
argument_list|()
operator|)
condition|)
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
name|VarDecl
operator|,
block|{
name|TRY_TO
argument_list|(
name|TraverseVarHelper
argument_list|(
name|D
argument_list|)
argument_list|)
block|;   }
operator|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ImplicitParamDecl
argument_list|,
argument|{     TRY_TO(TraverseVarHelper(D));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|NonTypeTemplateParmDecl
argument_list|,
argument|{
comment|// A non-type template parameter, e.g. "S" in template<int S> class Foo ...
argument|TRY_TO(TraverseDeclaratorHelper(D));     if (D->hasDefaultArgument()&& !D->defaultArgumentWasInherited())       TRY_TO(TraverseStmt(D->getDefaultArgument()));   }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ParmVarDecl
argument_list|,
argument|{     TRY_TO(TraverseVarHelper(D));      if (D->hasDefaultArg()&&         D->hasUninstantiatedDefaultArg()&&         !D->hasUnparsedDefaultArg())       TRY_TO(TraverseStmt(D->getUninstantiatedDefaultArg()));      if (D->hasDefaultArg()&&         !D->hasUninstantiatedDefaultArg()&&         !D->hasUnparsedDefaultArg())       TRY_TO(TraverseStmt(D->getDefaultArg()));   }
argument_list|)
undef|#
directive|undef
name|DEF_TRAVERSE_DECL
comment|// ----------------- Stmt traversal -----------------
comment|//
comment|// For stmts, we automate (in the DEF_TRAVERSE_STMT macro) iterating
comment|// over the children defined in children() (every stmt defines these,
comment|// though sometimes the range is empty).  Each individual Traverse*
comment|// method only needs to worry about children other than those.  To see
comment|// what children() does for a given class, see, e.g.,
comment|//   http://clang.llvm.org/doxygen/Stmt_8cpp_source.html
comment|// This macro makes available a variable S, the passed-in stmt.
define|#
directive|define
name|DEF_TRAVERSE_STMT
parameter_list|(
name|STMT
parameter_list|,
name|CODE
parameter_list|)
define|\
value|template<typename Derived>                                              \ bool RecursiveASTVisitor<Derived>::Traverse##STMT (STMT *S) {           \   TRY_TO(WalkUpFrom##STMT(S));                                          \   { CODE; }                                                             \   for (Stmt::child_range range = S->children(); range; ++range) {       \     TRY_TO(TraverseStmt(*range));                                       \   }                                                                     \   return true;                                                          \ }
name|DEF_TRAVERSE_STMT
argument_list|(
argument|GCCAsmStmt
argument_list|,
argument|{     TRY_TO(TraverseStmt(S->getAsmString()));     for (unsigned I =
literal|0
argument|, E = S->getNumInputs(); I< E; ++I) {       TRY_TO(TraverseStmt(S->getInputConstraintLiteral(I)));     }     for (unsigned I =
literal|0
argument|, E = S->getNumOutputs(); I< E; ++I) {       TRY_TO(TraverseStmt(S->getOutputConstraintLiteral(I)));     }     for (unsigned I =
literal|0
argument|, E = S->getNumClobbers(); I< E; ++I) {       TRY_TO(TraverseStmt(S->getClobberStringLiteral(I)));     }
comment|// children() iterates over inputExpr and outputExpr.
argument|}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|MSAsmStmt
argument_list|,
argument|{
comment|// FIXME: MS Asm doesn't currently parse Constraints, Clobbers, etc.  Once
comment|// added this needs to be implemented.
argument|}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXCatchStmt
argument_list|,
argument|{     TRY_TO(TraverseDecl(S->getExceptionDecl()));
comment|// children() iterates over the handler block.
argument|}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DeclStmt
argument_list|,
argument|{     for (DeclStmt::decl_iterator I = S->decl_begin(), E = S->decl_end();          I != E; ++I) {       TRY_TO(TraverseDecl(*I));     }
comment|// Suppress the default iteration over children() by
comment|// returning.  Here's why: A DeclStmt looks like 'type var [=
comment|// initializer]'.  The decls above already traverse over the
comment|// initializers, so we don't have to do it again (which
comment|// children() would do).
argument|return true;   }
argument_list|)
comment|// These non-expr stmts (most of them), do not need any action except
comment|// iterating over the children.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|BreakStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXTryStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CaseStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CompoundStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ContinueStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DefaultStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DoStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ForStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|GotoStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|IfStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|IndirectGotoStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|LabelStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|AttributedStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|NullStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtCatchStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtFinallyStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtSynchronizedStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtThrowStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtTryStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCForCollectionStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAutoreleasePoolStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXForRangeStmt
argument_list|,
argument|{   if (!getDerived().shouldVisitImplicitCode()) {     TRY_TO(TraverseStmt(S->getLoopVarStmt()));     TRY_TO(TraverseStmt(S->getRangeInit()));     TRY_TO(TraverseStmt(S->getBody()));
comment|// Visit everything else only if shouldVisitImplicitCode().
argument|return true;   } }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|MSDependentExistsStmt
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));     TRY_TO(TraverseDeclarationNameInfo(S->getNameInfo())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ReturnStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SwitchStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|WhileStmt
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDependentScopeMemberExpr
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));     TRY_TO(TraverseDeclarationNameInfo(S->getMemberNameInfo()));     if (S->hasExplicitTemplateArgs()) {       TRY_TO(TraverseTemplateArgumentLocsHelper(           S->getTemplateArgs(), S->getNumTemplateArgs()));     }   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DeclRefExpr
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));     TRY_TO(TraverseDeclarationNameInfo(S->getNameInfo()));     TRY_TO(TraverseTemplateArgumentLocsHelper(         S->getTemplateArgs(), S->getNumTemplateArgs()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DependentScopeDeclRefExpr
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));     TRY_TO(TraverseDeclarationNameInfo(S->getNameInfo()));     if (S->hasExplicitTemplateArgs()) {       TRY_TO(TraverseTemplateArgumentLocsHelper(           S->getExplicitTemplateArgs().getTemplateArgs(),           S->getNumTemplateArgs()));     }   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|MemberExpr
argument_list|,
argument|{     TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));     TRY_TO(TraverseDeclarationNameInfo(S->getMemberNameInfo()));     TRY_TO(TraverseTemplateArgumentLocsHelper(         S->getTemplateArgs(), S->getNumTemplateArgs()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ImplicitCastExpr
argument_list|,
argument|{
comment|// We don't traverse the cast type, as it's not written in the
comment|// source code.
argument|}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CStyleCastExpr
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXFunctionalCastExpr
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXConstCastExpr
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDynamicCastExpr
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXReinterpretCastExpr
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXStaticCastExpr
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc()));   }
argument_list|)
comment|// InitListExpr is a tricky one, because we want to do all our work on
comment|// the syntactic form of the listexpr, but this method takes the
comment|// semantic form by default.  We can't use the macro helper because it
comment|// calls WalkUp*() on the semantic form, before our code can convert
comment|// to the syntactic form.
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
name|child_range
name|range
operator|=
name|S
operator|->
name|children
argument_list|()
init|;
name|range
condition|;
operator|++
name|range
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
operator|*
name|range
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
comment|// GenericSelectionExpr is a special case because the types and expressions
end_comment

begin_comment
comment|// are interleaved.  We also need to watch out for null types (default
end_comment

begin_comment
comment|// generic associations).
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
name|TraverseGenericSelectionExpr
argument_list|(
argument|GenericSelectionExpr *S
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|WalkUpFromGenericSelectionExpr
argument_list|(
name|S
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|S
operator|->
name|getControllingExpr
argument_list|()
argument_list|)
argument_list|)
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|S
operator|->
name|getNumAssocs
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|TypeSourceInfo
modifier|*
name|TS
init|=
name|S
operator|->
name|getAssocTypeSourceInfo
argument_list|(
name|i
argument_list|)
condition|)
name|TRY_TO
argument_list|(
name|TraverseTypeLoc
argument_list|(
name|TS
operator|->
name|getTypeLoc
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|S
operator|->
name|getAssocExpr
argument_list|(
name|i
argument_list|)
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

begin_comment
unit|}
comment|// PseudoObjectExpr is a special case because of the wierdness with
end_comment

begin_comment
comment|// syntactic expressions and opaque values.
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
name|TraversePseudoObjectExpr
argument_list|(
argument|PseudoObjectExpr *S
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|WalkUpFromPseudoObjectExpr
argument_list|(
name|S
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|S
operator|->
name|getSyntacticForm
argument_list|()
argument_list|)
argument_list|)
block|;
for|for
control|(
name|PseudoObjectExpr
operator|::
name|semantics_iterator
name|i
operator|=
name|S
operator|->
name|semantics_begin
argument_list|()
operator|,
name|e
operator|=
name|S
operator|->
name|semantics_end
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
name|Expr
modifier|*
name|sub
init|=
operator|*
name|i
decl_stmt|;
if|if
condition|(
name|OpaqueValueExpr
modifier|*
name|OVE
init|=
name|dyn_cast
operator|<
name|OpaqueValueExpr
operator|>
operator|(
name|sub
operator|)
condition|)
name|sub
operator|=
name|OVE
operator|->
name|getSourceExpr
argument_list|()
expr_stmt|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|sub
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
unit|}  DEF_TRAVERSE_STMT
operator|(
name|CXXScalarValueInitExpr
operator|,
block|{
comment|// This is called for code like 'return T()' where T is a built-in
comment|// (i.e. non-class) type.
name|TRY_TO
argument_list|(
name|TraverseTypeLoc
argument_list|(
name|S
operator|->
name|getTypeSourceInfo
argument_list|()
operator|->
name|getTypeLoc
argument_list|()
argument_list|)
argument_list|)
block|;   }
operator|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXNewExpr
argument_list|,
argument|{
comment|// The child-iterator will pick up the other arguments.
argument|TRY_TO(TraverseTypeLoc(S->getAllocatedTypeSourceInfo()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OffsetOfExpr
argument_list|,
argument|{
comment|// The child-iterator will pick up the expression representing
comment|// the field.
comment|// FIMXE: for code like offsetof(Foo, a.b.c), should we get
comment|// making a MemberExpr callbacks for Foo.a, Foo.a.b, and Foo.a.b.c?
argument|TRY_TO(TraverseTypeLoc(S->getTypeSourceInfo()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UnaryExprOrTypeTraitExpr
argument_list|,
argument|{
comment|// The child-iterator will pick up the arg if it's an expression,
comment|// but not if it's a type.
argument|if (S->isArgumentType())       TRY_TO(TraverseTypeLoc(S->getArgumentTypeInfo()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXTypeidExpr
argument_list|,
argument|{
comment|// The child-iterator will pick up the arg if it's an expression,
comment|// but not if it's a type.
argument|if (S->isTypeOperand())       TRY_TO(TraverseTypeLoc(S->getTypeOperandSourceInfo()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|MSPropertyRefExpr
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXUuidofExpr
argument_list|,
argument|{
comment|// The child-iterator will pick up the arg if it's an expression,
comment|// but not if it's a type.
argument|if (S->isTypeOperand())       TRY_TO(TraverseTypeLoc(S->getTypeOperandSourceInfo()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UnaryTypeTraitExpr
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(S->getQueriedTypeSourceInfo()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|BinaryTypeTraitExpr
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(S->getLhsTypeSourceInfo()->getTypeLoc()));     TRY_TO(TraverseTypeLoc(S->getRhsTypeSourceInfo()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|TypeTraitExpr
argument_list|,
argument|{   for (unsigned I =
literal|0
argument|, N = S->getNumArgs(); I != N; ++I)     TRY_TO(TraverseTypeLoc(S->getArg(I)->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ArrayTypeTraitExpr
argument_list|,
argument|{     TRY_TO(TraverseTypeLoc(S->getQueriedTypeSourceInfo()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ExpressionTraitExpr
argument_list|,
argument|{     TRY_TO(TraverseStmt(S->getQueriedExpression()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|VAArgExpr
argument_list|,
argument|{
comment|// The child-iterator will pick up the expression argument.
argument|TRY_TO(TraverseTypeLoc(S->getWrittenTypeInfo()->getTypeLoc()));   }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXTemporaryObjectExpr
argument_list|,
argument|{
comment|// This is called for code like 'return T()' where T is a class type.
argument|TRY_TO(TraverseTypeLoc(S->getTypeSourceInfo()->getTypeLoc()));   }
argument_list|)
comment|// Walk only the visible parts of lambda expressions.
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
name|TraverseLambdaExpr
argument_list|(
argument|LambdaExpr *S
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|WalkUpFromLambdaExpr
argument_list|(
name|S
argument_list|)
argument_list|)
block|;
for|for
control|(
name|LambdaExpr
operator|::
name|capture_iterator
name|C
operator|=
name|S
operator|->
name|explicit_capture_begin
argument_list|()
operator|,
name|CEnd
operator|=
name|S
operator|->
name|explicit_capture_end
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
name|TraverseLambdaCapture
argument_list|(
name|S
argument_list|,
name|C
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
name|S
operator|->
name|hasExplicitParameters
argument_list|()
operator|||
name|S
operator|->
name|hasExplicitResultType
argument_list|()
condition|)
block|{
name|TypeLoc
name|TL
init|=
name|S
operator|->
name|getCallOperator
argument_list|()
operator|->
name|getTypeSourceInfo
argument_list|()
operator|->
name|getTypeLoc
argument_list|()
decl_stmt|;
if|if
condition|(
name|S
operator|->
name|hasExplicitParameters
argument_list|()
operator|&&
name|S
operator|->
name|hasExplicitResultType
argument_list|()
condition|)
block|{
comment|// Visit the whole type.
name|TRY_TO
argument_list|(
name|TraverseTypeLoc
argument_list|(
name|TL
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|FunctionProtoTypeLoc
name|Proto
init|=
name|TL
operator|.
name|getAs
operator|<
name|FunctionProtoTypeLoc
operator|>
operator|(
operator|)
condition|)
block|{
if|if
condition|(
name|S
operator|->
name|hasExplicitParameters
argument_list|()
condition|)
block|{
comment|// Visit parameters.
for|for
control|(
name|unsigned
name|I
init|=
literal|0
init|,
name|N
init|=
name|Proto
operator|.
name|getNumArgs
argument_list|()
init|;
name|I
operator|!=
name|N
condition|;
operator|++
name|I
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
name|Proto
operator|.
name|getArg
argument_list|(
name|I
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|TRY_TO
argument_list|(
name|TraverseTypeLoc
argument_list|(
name|Proto
operator|.
name|getResultLoc
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_if

begin_expr_stmt
name|TRY_TO
argument_list|(
name|TraverseLambdaBody
argument_list|(
name|S
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
unit|}  DEF_TRAVERSE_STMT
operator|(
name|CXXUnresolvedConstructExpr
operator|,
block|{
comment|// This is called for code like 'T()', where T is a template argument.
name|TRY_TO
argument_list|(
name|TraverseTypeLoc
argument_list|(
name|S
operator|->
name|getTypeSourceInfo
argument_list|()
operator|->
name|getTypeLoc
argument_list|()
argument_list|)
argument_list|)
block|;   }
operator|)
comment|// These expressions all might take explicit template arguments.
comment|// We traverse those if so.  FIXME: implement these.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXConstructExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CallExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXMemberCallExpr
argument_list|,
argument|{ }
argument_list|)
comment|// These exprs (most of them), do not need any action except iterating
comment|// over the children.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|AddrLabelExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ArraySubscriptExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|BlockExpr
argument_list|,
argument|{   TRY_TO(TraverseDecl(S->getBlockDecl()));   return true;
comment|// no child statements to loop through.
argument|}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ChooseExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CompoundLiteralExpr
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(S->getTypeSourceInfo()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXBindTemporaryExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXBoolLiteralExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDefaultArgExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDefaultInitExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDeleteExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ExprWithCleanups
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXNullPtrLiteralExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXStdInitializerListExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXPseudoDestructorExpr
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));   if (TypeSourceInfo *ScopeInfo = S->getScopeTypeInfo())     TRY_TO(TraverseTypeLoc(ScopeInfo->getTypeLoc()));   if (TypeSourceInfo *DestroyedTypeInfo = S->getDestroyedTypeInfo())     TRY_TO(TraverseTypeLoc(DestroyedTypeInfo->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXThisExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXThrowExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UserDefinedLiteral
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DesignatedInitExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ExtVectorElementExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|GNUNullExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ImplicitValueInitExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCBoolLiteralExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCEncodeExpr
argument_list|,
argument|{   if (TypeSourceInfo *TInfo = S->getEncodedTypeSourceInfo())     TRY_TO(TraverseTypeLoc(TInfo->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCIsaExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCIvarRefExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCMessageExpr
argument_list|,
argument|{   if (TypeSourceInfo *TInfo = S->getClassReceiverTypeInfo())     TRY_TO(TraverseTypeLoc(TInfo->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCPropertyRefExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCSubscriptRefExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCProtocolExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCSelectorExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCIndirectCopyRestoreExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCBridgedCastExpr
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ParenExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ParenListExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|PredefinedExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ShuffleVectorExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ConvertVectorExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|StmtExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UnresolvedLookupExpr
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));   if (S->hasExplicitTemplateArgs()) {     TRY_TO(TraverseTemplateArgumentLocsHelper(S->getTemplateArgs(),                                               S->getNumTemplateArgs()));   } }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UnresolvedMemberExpr
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));   if (S->hasExplicitTemplateArgs()) {     TRY_TO(TraverseTemplateArgumentLocsHelper(S->getTemplateArgs(),                                               S->getNumTemplateArgs()));   } }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SEHTryStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SEHExceptStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SEHFinallyStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CapturedStmt
argument_list|,
argument|{   TRY_TO(TraverseDecl(S->getCapturedDecl())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXOperatorCallExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OpaqueValueExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CUDAKernelCallExpr
argument_list|,
argument|{ }
argument_list|)
comment|// These operators (all of them) do not need any action except
comment|// iterating over the children.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|BinaryConditionalOperator
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ConditionalOperator
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UnaryOperator
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|BinaryOperator
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CompoundAssignOperator
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXNoexceptExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|PackExpansionExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SizeOfPackExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SubstNonTypeTemplateParmPackExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SubstNonTypeTemplateParmExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|FunctionParmPackExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|MaterializeTemporaryExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|AtomicExpr
argument_list|,
argument|{ }
argument_list|)
comment|// These literals (all of them) do not need any action.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|IntegerLiteral
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CharacterLiteral
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|FloatingLiteral
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ImaginaryLiteral
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|StringLiteral
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCStringLiteral
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCBoxedExpr
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCArrayLiteral
argument_list|,
argument|{ }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCDictionaryLiteral
argument_list|,
argument|{ }
argument_list|)
comment|// Traverse OpenCL: AsType, Convert.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|AsTypeExpr
argument_list|,
argument|{ }
argument_list|)
comment|// OpenMP directives.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPParallelDirective
argument_list|,
argument|{   ArrayRef<OMPClause *> Clauses = S->clauses();   for (ArrayRef<OMPClause *>::iterator I = Clauses.begin(), E = Clauses.end();        I != E; ++I)     if (!TraverseOMPClause(*I)) return false; }
argument_list|)
comment|// OpenMP clauses.
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
name|TraverseOMPClause
argument_list|(
argument|OMPClause *C
argument_list|)
block|{
if|if
condition|(
operator|!
name|C
condition|)
return|return
name|true
return|;
end_expr_stmt

begin_switch
switch|switch
condition|(
name|C
operator|->
name|getClauseKind
argument_list|()
condition|)
block|{
define|#
directive|define
name|OPENMP_CLAUSE
parameter_list|(
name|Name
parameter_list|,
name|Class
parameter_list|)
define|\
value|case OMPC_##Name:                                                     \     return getDerived().Visit##Class(static_cast<Class*>(C));
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
default|default:
break|break;
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
name|VisitOMPDefaultClause
argument_list|(
argument|OMPDefaultClause *C
argument_list|)
block|{
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
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPClauseList
argument_list|(
argument|T *Node
argument_list|)
block|{
for|for
control|(
name|typename
name|T
operator|::
name|varlist_iterator
name|I
operator|=
name|Node
operator|->
name|varlist_begin
argument_list|()
operator|,
name|E
operator|=
name|Node
operator|->
name|varlist_end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
name|TraverseStmt
argument_list|(
operator|*
name|I
argument_list|)
expr_stmt|;
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
name|VisitOMPPrivateClause
argument_list|(
argument|OMPPrivateClause *C
argument_list|)
block|{
name|VisitOMPClauseList
argument_list|(
name|C
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
name|VisitOMPFirstprivateClause
argument_list|(
argument|OMPFirstprivateClause *C
argument_list|)
block|{
name|VisitOMPClauseList
argument_list|(
name|C
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
name|VisitOMPSharedClause
argument_list|(
argument|OMPSharedClause *C
argument_list|)
block|{
name|VisitOMPClauseList
argument_list|(
name|C
argument_list|)
block|;
return|return
name|true
return|;
block|}
end_expr_stmt

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
comment|//    http://clang.llvm.org/doxygen/classclang_1_1UnaryExprOrTypeTraitExpr.html
end_comment

begin_comment
comment|//    http://clang.llvm.org/doxygen/classclang_1_1TypesCompatibleExpr.html
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

