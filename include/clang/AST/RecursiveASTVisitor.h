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
file|"clang/AST/Attr.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclBase.h"
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
file|"clang/AST/ExprOpenMP.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/LambdaCapture.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/NestedNameSpecifier.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/OpenMPClause.h"
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

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/OpenMPKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Specifiers.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<type_traits>
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
value|OPERATOR(PostInc) OPERATOR(PostDec) OPERATOR(PreInc) OPERATOR(PreDec)        \       OPERATOR(AddrOf) OPERATOR(Deref) OPERATOR(Plus) OPERATOR(Minus)          \       OPERATOR(Not) OPERATOR(LNot) OPERATOR(Real) OPERATOR(Imag)               \       OPERATOR(Extension) OPERATOR(Coawait)
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
value|OPERATOR(PtrMemD) OPERATOR(PtrMemI) OPERATOR(Mul) OPERATOR(Div)              \       OPERATOR(Rem) OPERATOR(Add) OPERATOR(Sub) OPERATOR(Shl) OPERATOR(Shr)    \       OPERATOR(LT) OPERATOR(GT) OPERATOR(LE) OPERATOR(GE) OPERATOR(EQ)         \       OPERATOR(NE) OPERATOR(And) OPERATOR(Xor) OPERATOR(Or) OPERATOR(LAnd)     \       OPERATOR(LOr) OPERATOR(Assign) OPERATOR(Comma)
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
value|OPERATOR(Mul) OPERATOR(Div) OPERATOR(Rem) OPERATOR(Add) OPERATOR(Sub)        \       OPERATOR(Shl) OPERATOR(Shr) OPERATOR(And) OPERATOR(Or) OPERATOR(Xor)
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
value|do {                                                                         \     if (!getDerived().CALL_EXPR)                                               \       return false;                                                            \   } while (false)
comment|/// \brief A class that does preordor or postorder
comment|/// depth-first traversal on the entire Clang AST and visits each node.
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
comment|///
comment|/// By default, this visitor preorder traverses the AST. If postorder traversal
comment|/// is needed, the \c shouldTraversePostOrder method needs to be overriden
comment|/// to return \c true.
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
comment|/// A queue used for performing data recursion over statements.
comment|/// Parameters involving this type are used to implement data
comment|/// recursion over Stmts and Exprs within this class, and should
comment|/// typically not be explicitly specified by derived classes.
comment|/// The bool bit indicates whether the statement has been traversed or not.
typedef|typedef
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|PointerIntPair
operator|<
name|Stmt
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>>
name|DataRecursionQueue
expr_stmt|;
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
comment|/// \brief Return whether this visitor should traverse post-order.
name|bool
name|shouldTraversePostOrder
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Recursively visit a statement or expression, by
comment|/// dispatching to Traverse*() based on the argument's dynamic type.
comment|///
comment|/// \returns false if the visitation was terminated early, true
comment|/// otherwise (including when the argument is nullptr).
name|bool
name|TraverseStmt
argument_list|(
name|Stmt
operator|*
name|S
argument_list|,
name|DataRecursionQueue
operator|*
name|Queue
operator|=
name|nullptr
argument_list|)
expr_stmt|;
comment|/// Invoked before visiting a statement or expression via data recursion.
comment|///
comment|/// \returns false to skip visiting the node, true otherwise.
name|bool
name|dataTraverseStmtPre
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// Invoked after visiting a statement or expression via data recursion.
comment|/// This is not invoked if the previously invoked \c dataTraverseStmtPre
comment|/// returned false.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|dataTraverseStmtPost
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Recursively visit a type, by dispatching to
comment|/// Traverse*Type() based on the argument's getTypeClass() property.
comment|///
comment|/// \returns false if the visitation was terminated early, true
comment|/// otherwise (including when the argument is a Null type).
name|bool
name|TraverseType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit a type with location, by dispatching to
comment|/// Traverse*TypeLoc() based on the argument type's getTypeClass() property.
comment|///
comment|/// \returns false if the visitation was terminated early, true
comment|/// otherwise (including when the argument is a Null type location).
name|bool
name|TraverseTypeLoc
parameter_list|(
name|TypeLoc
name|TL
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit an attribute, by dispatching to
comment|/// Traverse*Attr() based on the argument's dynamic type.
comment|///
comment|/// \returns false if the visitation was terminated early, true
comment|/// otherwise (including when the argument is a Null type location).
name|bool
name|TraverseAttr
parameter_list|(
name|Attr
modifier|*
name|At
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit a declaration, by dispatching to
comment|/// Traverse*Decl() based on the argument's dynamic type.
comment|///
comment|/// \returns false if the visitation was terminated early, true
comment|/// otherwise (including when the argument is NULL).
name|bool
name|TraverseDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit a C++ nested-name-specifier.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseNestedNameSpecifier
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit a C++ nested-name-specifier with location
comment|/// information.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseNestedNameSpecifierLoc
parameter_list|(
name|NestedNameSpecifierLoc
name|NNS
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit a name with its location information.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseDeclarationNameInfo
parameter_list|(
name|DeclarationNameInfo
name|NameInfo
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit a template name and dispatch to the
comment|/// appropriate method.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseTemplateName
parameter_list|(
name|TemplateName
name|Template
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit a template argument and dispatch to the
comment|/// appropriate method for the argument type.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
comment|// FIXME: migrate callers to TemplateArgumentLoc instead.
name|bool
name|TraverseTemplateArgument
parameter_list|(
specifier|const
name|TemplateArgument
modifier|&
name|Arg
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit a template argument location and dispatch to the
comment|/// appropriate method for the argument type.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseTemplateArgumentLoc
parameter_list|(
specifier|const
name|TemplateArgumentLoc
modifier|&
name|ArgLoc
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit a set of template arguments.
comment|/// This can be overridden by a subclass, but it's not expected that
comment|/// will be needed -- this visitor always dispatches to another.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
comment|// FIXME: take a TemplateArgumentLoc* (or TemplateArgumentListInfo) instead.
name|bool
name|TraverseTemplateArguments
parameter_list|(
specifier|const
name|TemplateArgument
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit a constructor initializer.  This
comment|/// automatically dispatches to another visitor for the initializer
comment|/// expression, but not for the name of the initializer, so may
comment|/// be overridden for clients that need access to the name.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseConstructorInitializer
parameter_list|(
name|CXXCtorInitializer
modifier|*
name|Init
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit a lambda capture. \c Init is the expression that
comment|/// will be used to initialize the capture.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseLambdaCapture
parameter_list|(
name|LambdaExpr
modifier|*
name|LE
parameter_list|,
specifier|const
name|LambdaCapture
modifier|*
name|C
parameter_list|,
name|Expr
modifier|*
name|Init
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit the body of a lambda expression.
comment|///
comment|/// This provides a hook for visitors that need more context when visiting
comment|/// \c LE->getBody().
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseLambdaBody
parameter_list|(
name|LambdaExpr
modifier|*
name|LE
parameter_list|,
name|DataRecursionQueue
modifier|*
name|Queue
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// \brief Recursively visit the syntactic or semantic form of an
comment|/// initialization list.
comment|///
comment|/// \returns false if the visitation was terminated early, true otherwise.
name|bool
name|TraverseSynOrSemInitListExpr
parameter_list|(
name|InitListExpr
modifier|*
name|S
parameter_list|,
name|DataRecursionQueue
modifier|*
name|Queue
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|// ---- Methods on Attrs ----
comment|// \brief Visit an attribute.
name|bool
name|VisitAttr
parameter_list|(
name|Attr
modifier|*
name|A
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Declare Traverse* and empty Visit* for all Attr classes.
define|#
directive|define
name|ATTR_VISITOR_DECLS_ONLY
include|#
directive|include
file|"clang/AST/AttrVisitor.inc"
undef|#
directive|undef
name|ATTR_VISITOR_DECLS_ONLY
comment|// ---- Methods on Stmts ----
name|private
label|:
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|>
expr|struct
name|has_same_member_pointer_type
operator|:
name|std
operator|::
name|false_type
block|{}
expr_stmt|;
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|U
operator|,
name|typename
name|R
operator|,
name|typename
operator|...
name|P
operator|>
expr|struct
name|has_same_member_pointer_type
operator|<
name|R
argument_list|(
name|T
operator|::
operator|*
argument_list|)
argument_list|(
name|P
operator|...
argument_list|)
operator|,
name|R
argument_list|(
name|U
operator|::
operator|*
argument_list|)
argument_list|(
name|P
operator|...
argument_list|)
operator|>
operator|:
name|std
operator|::
name|true_type
block|{}
expr_stmt|;
comment|// Traverse the given statement. If the most-derived traverse function takes a
comment|// data recursion queue, pass it on; otherwise, discard it. Note that the
comment|// first branch of this conditional must compile whether or not the derived
comment|// class can take a queue, so if we're taking the second arm, make the first
comment|// arm call our function rather than the derived class version.
define|#
directive|define
name|TRAVERSE_STMT_BASE
parameter_list|(
name|NAME
parameter_list|,
name|CLASS
parameter_list|,
name|VAR
parameter_list|,
name|QUEUE
parameter_list|)
define|\
value|(has_same_member_pointer_type<decltype(                                      \&RecursiveASTVisitor::Traverse##NAME),     \                                 decltype(&Derived::Traverse##NAME)>::value     \        ? static_cast<typename std::conditional<                                \              has_same_member_pointer_type<                                     \                  decltype(&RecursiveASTVisitor::Traverse##NAME),               \                  decltype(&Derived::Traverse##NAME)>::value,                   \              Derived&, RecursiveASTVisitor&>::type>(*this)                   \              .Traverse##NAME(static_cast<CLASS *>(VAR), QUEUE)                 \        : getDerived().Traverse##NAME(static_cast<CLASS *>(VAR)))
comment|// Try to traverse the given statement, or enqueue it if we're performing data
comment|// recursion in the middle of traversing another statement. Can only be called
comment|// from within a DEF_TRAVERSE_STMT body or similar context.
define|#
directive|define
name|TRY_TO_TRAVERSE_OR_ENQUEUE_STMT
parameter_list|(
name|S
parameter_list|)
define|\
value|do {                                                                         \     if (!TRAVERSE_STMT_BASE(Stmt, Stmt, S, Queue))                             \       return false;                                                            \   } while (false)
name|public
label|:
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
value|bool Traverse##CLASS(CLASS *S, DataRecursionQueue *Queue = nullptr);
include|#
directive|include
file|"clang/AST/StmtNodes.inc"
comment|// The above header #undefs ABSTRACT_STMT and STMT upon exit.
comment|// Define WalkUpFrom*() and empty Visit*() for all Stmt classes.
name|bool
name|WalkUpFromStmt
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
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
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
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
value|bool WalkUpFrom##CLASS(CLASS *S) {                                           \     TRY_TO(WalkUpFrom##PARENT(S));                                             \     TRY_TO(Visit##CLASS(S));                                                   \     return true;                                                               \   }                                                                            \   bool Visit##CLASS(CLASS *S) { return true; }
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
value|bool TraverseUnary##NAME(UnaryOperator *S,                                   \                            DataRecursionQueue *Queue = nullptr) {              \     if (!getDerived().shouldTraversePostOrder())                               \       TRY_TO(WalkUpFromUnary##NAME(S));                                        \     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getSubExpr());                          \     return true;                                                               \   }                                                                            \   bool WalkUpFromUnary##NAME(UnaryOperator *S) {                               \     TRY_TO(WalkUpFromUnaryOperator(S));                                        \     TRY_TO(VisitUnary##NAME(S));                                               \     return true;                                                               \   }                                                                            \   bool VisitUnary##NAME(UnaryOperator *S) { return true; }
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
value|bool TraverseBin##NAME(BINOP_TYPE *S, DataRecursionQueue *Queue = nullptr) { \     if (!getDerived().shouldTraversePostOrder())                               \       TRY_TO(WalkUpFromBin##NAME(S));                                          \     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getLHS());                              \     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getRHS());                              \     return true;                                                               \   }                                                                            \   bool WalkUpFromBin##NAME(BINOP_TYPE *S) {                                    \     TRY_TO(WalkUpFrom##BINOP_TYPE(S));                                         \     TRY_TO(VisitBin##NAME(S));                                                 \     return true;                                                               \   }                                                                            \   bool VisitBin##NAME(BINOP_TYPE *S) { return true; }
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
value|bool Traverse##CLASS##Type(CLASS##Type *T);
include|#
directive|include
file|"clang/AST/TypeNodes.def"
comment|// The above header #undefs ABSTRACT_TYPE and TYPE upon exit.
comment|// Define WalkUpFrom*() and empty Visit*() for all Type classes.
name|bool
name|WalkUpFromType
parameter_list|(
name|Type
modifier|*
name|T
parameter_list|)
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
parameter_list|(
name|Type
modifier|*
name|T
parameter_list|)
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
value|bool WalkUpFrom##CLASS##Type(CLASS##Type *T) {                               \     TRY_TO(WalkUpFrom##BASE(T));                                               \     TRY_TO(Visit##CLASS##Type(T));                                             \     return true;                                                               \   }                                                                            \   bool Visit##CLASS##Type(CLASS##Type *T) { return true; }
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
value|bool Traverse##CLASS##TypeLoc(CLASS##TypeLoc TL);
include|#
directive|include
file|"clang/AST/TypeLocNodes.def"
comment|// The above header #undefs ABSTRACT_TYPELOC and TYPELOC upon exit.
comment|// Define WalkUpFrom*() and empty Visit*() for all TypeLoc classes.
name|bool
name|WalkUpFromTypeLoc
parameter_list|(
name|TypeLoc
name|TL
parameter_list|)
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
parameter_list|(
name|TypeLoc
name|TL
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|// QualifiedTypeLoc and UnqualTypeLoc are not declared in
comment|// TypeNodes.def and thus need to be handled specially.
name|bool
name|WalkUpFromQualifiedTypeLoc
parameter_list|(
name|QualifiedTypeLoc
name|TL
parameter_list|)
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
parameter_list|(
name|QualifiedTypeLoc
name|TL
parameter_list|)
block|{
return|return
name|true
return|;
block|}
name|bool
name|WalkUpFromUnqualTypeLoc
parameter_list|(
name|UnqualTypeLoc
name|TL
parameter_list|)
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
parameter_list|(
name|UnqualTypeLoc
name|TL
parameter_list|)
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
value|bool WalkUpFrom##CLASS##TypeLoc(CLASS##TypeLoc TL) {                         \     TRY_TO(WalkUpFrom##BASE##Loc(TL));                                         \     TRY_TO(Visit##CLASS##TypeLoc(TL));                                         \     return true;                                                               \   }                                                                            \   bool Visit##CLASS##TypeLoc(CLASS##TypeLoc TL) { return true; }
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
value|bool Traverse##CLASS##Decl(CLASS##Decl *D);
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
comment|// The above header #undefs ABSTRACT_DECL and DECL upon exit.
comment|// Define WalkUpFrom*() and empty Visit*() for all Decl classes.
name|bool
name|WalkUpFromDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
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
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
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
value|bool WalkUpFrom##CLASS##Decl(CLASS##Decl *D) {                               \     TRY_TO(WalkUpFrom##BASE(D));                                               \     TRY_TO(Visit##CLASS##Decl(D));                                             \     return true;                                                               \   }                                                                            \   bool Visit##CLASS##Decl(CLASS##Decl *D) { return true; }
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
name|private
label|:
comment|// These are helper methods used by more than one Traverse* method.
name|bool
name|TraverseTemplateParameterListHelper
parameter_list|(
name|TemplateParameterList
modifier|*
name|TPL
parameter_list|)
function_decl|;
comment|// Traverses template parameter lists of either a DeclaratorDecl or TagDecl.
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|TraverseDeclTemplateParameterLists
argument_list|(
name|T
operator|*
name|D
argument_list|)
expr_stmt|;
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
parameter_list|(
specifier|const
name|TemplateArgumentLoc
modifier|*
name|TAL
parameter_list|,
name|unsigned
name|Count
parameter_list|)
function_decl|;
name|bool
name|TraverseArrayTypeLocHelper
parameter_list|(
name|ArrayTypeLoc
name|TL
parameter_list|)
function_decl|;
name|bool
name|TraverseRecordHelper
parameter_list|(
name|RecordDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|bool
name|TraverseCXXRecordHelper
parameter_list|(
name|CXXRecordDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|bool
name|TraverseDeclaratorHelper
parameter_list|(
name|DeclaratorDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|bool
name|TraverseDeclContextHelper
parameter_list|(
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
name|bool
name|TraverseFunctionHelper
parameter_list|(
name|FunctionDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|bool
name|TraverseVarHelper
parameter_list|(
name|VarDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|bool
name|TraverseOMPExecutableDirective
parameter_list|(
name|OMPExecutableDirective
modifier|*
name|S
parameter_list|)
function_decl|;
name|bool
name|TraverseOMPLoopDirective
parameter_list|(
name|OMPLoopDirective
modifier|*
name|S
parameter_list|)
function_decl|;
name|bool
name|TraverseOMPClause
parameter_list|(
name|OMPClause
modifier|*
name|C
parameter_list|)
function_decl|;
define|#
directive|define
name|OPENMP_CLAUSE
parameter_list|(
name|Name
parameter_list|,
name|Class
parameter_list|)
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
name|bool
name|VisitOMPClauseList
argument_list|(
name|T
operator|*
name|Node
argument_list|)
expr_stmt|;
comment|/// Process clauses with pre-initis.
name|bool
name|VisitOMPClauseWithPreInit
parameter_list|(
name|OMPClauseWithPreInit
modifier|*
name|Node
parameter_list|)
function_decl|;
name|bool
name|VisitOMPClauseWithPostUpdate
parameter_list|(
name|OMPClauseWithPostUpdate
modifier|*
name|Node
parameter_list|)
function_decl|;
name|bool
name|dataTraverseNode
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|,
name|DataRecursionQueue
modifier|*
name|Queue
parameter_list|)
function_decl|;
name|bool
name|PostVisitStmt
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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
name|dataTraverseNode
argument_list|(
argument|Stmt *S
argument_list|,
argument|DataRecursionQueue *Queue
argument_list|)
block|{
define|#
directive|define
name|DISPATCH_STMT
parameter_list|(
name|NAME
parameter_list|,
name|CLASS
parameter_list|,
name|VAR
parameter_list|)
define|\
value|return TRAVERSE_STMT_BASE(NAME, CLASS, VAR, Queue);
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
value|case BO_##NAME:                                                              \     DISPATCH_STMT(Bin##NAME, BinaryOperator, S);
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
value|case BO_##NAME##Assign:                                                      \     DISPATCH_STMT(Bin##NAME##Assign, CompoundAssignOperator, S);
name|CAO_LIST
argument_list|()
undef|#
directive|undef
name|OPERATOR
undef|#
directive|undef
name|CAO_LIST
block|}
end_expr_stmt

begin_if
unit|} else
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
value|case UO_##NAME:                                                              \     DISPATCH_STMT(Unary##NAME, UnaryOperator, S);
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
end_if

begin_comment
comment|// Top switch stmt: dispatch to TraverseFooStmt for each concrete FooStmt.
end_comment

begin_switch
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
value|case Stmt::CLASS##Class:                                                     \     DISPATCH_STMT(CLASS, CLASS, S);
include|#
directive|include
file|"clang/AST/StmtNodes.inc"
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
name|DISPATCH_STMT
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
name|PostVisitStmt
argument_list|(
argument|Stmt *S
argument_list|)
block|{
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
value|case Stmt::CLASS##Class:                                                     \     TRY_TO(WalkUpFrom##CLASS(static_cast<CLASS *>(S))); break;
include|#
directive|include
file|"clang/AST/StmtNodes.inc"
block|}
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_undef
unit|}
undef|#
directive|undef
name|DISPATCH_STMT
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
name|TraverseStmt
argument_list|(
argument|Stmt *S
argument_list|,
argument|DataRecursionQueue *Queue
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
end_expr_stmt

begin_if
if|if
condition|(
name|Queue
condition|)
block|{
name|Queue
operator|->
name|push_back
argument_list|(
block|{
name|S
block|,
name|false
block|}
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_if

begin_expr_stmt
name|SmallVector
operator|<
name|llvm
operator|::
name|PointerIntPair
operator|<
name|Stmt
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
operator|,
literal|8
operator|>
name|LocalQueue
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LocalQueue
operator|.
name|push_back
argument_list|(
block|{
name|S
block|,
name|false
block|}
argument_list|)
expr_stmt|;
end_expr_stmt

begin_while
while|while
condition|(
operator|!
name|LocalQueue
operator|.
name|empty
argument_list|()
condition|)
block|{
name|auto
operator|&
name|CurrSAndVisited
operator|=
name|LocalQueue
operator|.
name|back
argument_list|()
expr_stmt|;
name|Stmt
modifier|*
name|CurrS
init|=
name|CurrSAndVisited
operator|.
name|getPointer
argument_list|()
decl_stmt|;
name|bool
name|Visited
init|=
name|CurrSAndVisited
operator|.
name|getInt
argument_list|()
decl_stmt|;
if|if
condition|(
name|Visited
condition|)
block|{
name|LocalQueue
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|TRY_TO
argument_list|(
name|dataTraverseStmtPost
argument_list|(
name|CurrS
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|getDerived
argument_list|()
operator|.
name|shouldTraversePostOrder
argument_list|()
condition|)
block|{
name|TRY_TO
argument_list|(
name|PostVisitStmt
argument_list|(
name|CurrS
argument_list|)
argument_list|)
expr_stmt|;
block|}
continue|continue;
block|}
if|if
condition|(
name|getDerived
argument_list|()
operator|.
name|dataTraverseStmtPre
argument_list|(
name|CurrS
argument_list|)
condition|)
block|{
name|CurrSAndVisited
operator|.
name|setInt
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|size_t
name|N
init|=
name|LocalQueue
operator|.
name|size
argument_list|()
decl_stmt|;
name|TRY_TO
argument_list|(
name|dataTraverseNode
argument_list|(
name|CurrS
argument_list|,
operator|&
name|LocalQueue
argument_list|)
argument_list|)
expr_stmt|;
comment|// Process new children in the order they were added.
name|std
operator|::
name|reverse
argument_list|(
name|LocalQueue
operator|.
name|begin
argument_list|()
operator|+
name|N
argument_list|,
name|LocalQueue
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|LocalQueue
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
block|}
end_while

begin_return
return|return
name|true
return|;
end_return

begin_define
unit|}
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
value|return getDerived().Traverse##NAME(static_cast<CLASS *>(VAR))
end_define

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
value|case Type::CLASS:                                                            \     DISPATCH(CLASS##Type, CLASS##Type, const_cast<Type *>(T.getTypePtr()));
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
value|case TypeLoc::CLASS:                                                         \     return getDerived().Traverse##CLASS##TypeLoc(TL.castAs<CLASS##TypeLoc>());
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

begin_comment
unit|}
comment|// Define the Traverse*Attr(Attr* A) methods
end_comment

begin_define
define|#
directive|define
name|VISITORCLASS
value|RecursiveASTVisitor
end_define

begin_include
include|#
directive|include
file|"clang/AST/AttrVisitor.inc"
end_include

begin_undef
undef|#
directive|undef
name|VISITORCLASS
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
value|case Decl::CLASS:                                                            \     if (!getDerived().Traverse##CLASS##Decl(static_cast<CLASS##Decl *>(D)))    \       return false;                                                            \     break;
include|#
directive|include
file|"clang/AST/DeclNodes.inc"
block|}
end_switch

begin_comment
comment|// Visit any attributes attached to this declaration.
end_comment

begin_for
for|for
control|(
name|auto
operator|*
name|I
operator|:
name|D
operator|->
name|attrs
argument_list|()
control|)
block|{
if|if
condition|(
operator|!
name|getDerived
argument_list|()
operator|.
name|TraverseAttr
argument_list|(
name|I
argument_list|)
condition|)
return|return
name|false
return|;
block|}
end_for

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
case|case
name|NestedNameSpecifier
operator|::
name|Super
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
case|case
name|NestedNameSpecifier
operator|::
name|Super
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
name|CXXDeductionGuideName
case|:
name|TRY_TO
argument_list|(
name|TraverseTemplateName
argument_list|(
name|TemplateName
argument_list|(
name|NameInfo
operator|.
name|getName
argument_list|()
operator|.
name|getCXXDeductionGuideTemplate
argument_list|()
argument_list|)
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
argument|const LambdaCapture *C
argument_list|,
argument|Expr *Init
argument_list|)
block|{
if|if
condition|(
name|LE
operator|->
name|isInitCapture
argument_list|(
name|C
argument_list|)
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
else|else
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|Init
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
argument_list|,
argument|DataRecursionQueue *Queue
argument_list|)
block|{
name|TRY_TO_TRAVERSE_OR_ENQUEUE_STMT
argument_list|(
name|LE
operator|->
name|getBody
argument_list|()
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
value|template<typename Derived>                                                  \   bool RecursiveASTVisitor<Derived>::Traverse##TYPE(TYPE *T) {                 \     if (!getDerived().shouldTraversePostOrder())                               \       TRY_TO(WalkUpFrom##TYPE(T));                                             \     { CODE; }                                                                  \     if (getDerived().shouldTraversePostOrder())                                \       TRY_TO(WalkUpFrom##TYPE(T));                                             \     return true;                                                               \   }
end_define

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|BuiltinType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ComplexType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getElementType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|PointerType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getPointeeType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|BlockPointerType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getPointeeType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|LValueReferenceType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getPointeeType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|RValueReferenceType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getPointeeType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|MemberPointerType
argument_list|,
argument|{   TRY_TO(TraverseType(QualType(T->getClass(),
literal|0
argument|)));   TRY_TO(TraverseType(T->getPointeeType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|AdjustedType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getOriginalType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DecayedType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getOriginalType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ConstantArrayType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getElementType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|IncompleteArrayType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getElementType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|VariableArrayType
argument_list|,
argument|{   TRY_TO(TraverseType(T->getElementType()));   TRY_TO(TraverseStmt(T->getSizeExpr())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DependentSizedArrayType
argument_list|,
argument|{   TRY_TO(TraverseType(T->getElementType()));   if (T->getSizeExpr())     TRY_TO(TraverseStmt(T->getSizeExpr())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DependentSizedExtVectorType
argument_list|,
argument|{   if (T->getSizeExpr())     TRY_TO(TraverseStmt(T->getSizeExpr()));   TRY_TO(TraverseType(T->getElementType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|VectorType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getElementType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ExtVectorType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getElementType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|FunctionNoProtoType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getReturnType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|FunctionProtoType
argument_list|,
argument|{   TRY_TO(TraverseType(T->getReturnType()));    for (const auto&A : T->param_types()) {     TRY_TO(TraverseType(A));   }    for (const auto&E : T->exceptions()) {     TRY_TO(TraverseType(E));   }    if (Expr *NE = T->getNoexceptExpr())     TRY_TO(TraverseStmt(NE)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|UnresolvedUsingType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TypedefType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TypeOfExprType
argument_list|,
argument|{ TRY_TO(TraverseStmt(T->getUnderlyingExpr())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TypeOfType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getUnderlyingType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DecltypeType
argument_list|,
argument|{ TRY_TO(TraverseStmt(T->getUnderlyingExpr())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|UnaryTransformType
argument_list|,
argument|{   TRY_TO(TraverseType(T->getBaseType()));   TRY_TO(TraverseType(T->getUnderlyingType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|AutoType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getDeducedType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DeducedTemplateSpecializationType
argument_list|,
argument|{   TRY_TO(TraverseTemplateName(T->getTemplateName()));   TRY_TO(TraverseType(T->getDeducedType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|RecordType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|EnumType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TemplateTypeParmType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|SubstTemplateTypeParmType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|SubstTemplateTypeParmPackType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|TemplateSpecializationType
argument_list|,
argument|{   TRY_TO(TraverseTemplateName(T->getTemplateName()));   TRY_TO(TraverseTemplateArguments(T->getArgs(), T->getNumArgs())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|InjectedClassNameType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|AttributedType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getModifiedType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ParenType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getInnerType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ElaboratedType
argument_list|,
argument|{   if (T->getQualifier()) {     TRY_TO(TraverseNestedNameSpecifier(T->getQualifier()));   }   TRY_TO(TraverseType(T->getNamedType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DependentNameType
argument_list|,
argument|{ TRY_TO(TraverseNestedNameSpecifier(T->getQualifier())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|DependentTemplateSpecializationType
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifier(T->getQualifier()));   TRY_TO(TraverseTemplateArguments(T->getArgs(), T->getNumArgs())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|PackExpansionType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getPattern())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ObjCTypeParamType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ObjCInterfaceType
argument_list|,
argument|{}
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
argument|if (T->getBaseType().getTypePtr() != T)     TRY_TO(TraverseType(T->getBaseType()));   for (auto typeArg : T->getTypeArgsAsWritten()) {     TRY_TO(TraverseType(typeArg));   } }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|ObjCObjectPointerType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getPointeeType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|AtomicType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getValueType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPE
argument_list|(
argument|PipeType
argument_list|,
argument|{ TRY_TO(TraverseType(T->getElementType())); }
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
value|template<typename Derived>                                                  \   bool RecursiveASTVisitor<Derived>::Traverse##TYPE##Loc(TYPE##Loc TL) {       \     if (getDerived().shouldWalkTypesOfTypeLocs())                              \       TRY_TO(WalkUpFrom##TYPE(const_cast<TYPE *>(TL.getTypePtr())));           \     TRY_TO(WalkUpFrom##TYPE##Loc(TL));                                         \     { CODE; }                                                                  \     return true;                                                               \   }
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
argument|{}
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
argument|{   TRY_TO(TraverseType(TL.getTypePtr()->getElementType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|PointerType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getPointeeLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|BlockPointerType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getPointeeLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|LValueReferenceType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getPointeeLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|RValueReferenceType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getPointeeLoc())); }
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
argument|{   TRY_TO(TraverseType(QualType(TL.getTypePtr()->getClass(),
literal|0
argument|)));   TRY_TO(TraverseTypeLoc(TL.getPointeeLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|AdjustedType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getOriginalLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DecayedType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getOriginalLoc())); }
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
argument|{   TRY_TO(TraverseTypeLoc(TL.getElementLoc()));   return TraverseArrayTypeLocHelper(TL); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|IncompleteArrayType
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(TL.getElementLoc()));   return TraverseArrayTypeLocHelper(TL); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|VariableArrayType
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(TL.getElementLoc()));   return TraverseArrayTypeLocHelper(TL); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DependentSizedArrayType
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(TL.getElementLoc()));   return TraverseArrayTypeLocHelper(TL); }
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
argument|{   if (TL.getTypePtr()->getSizeExpr())     TRY_TO(TraverseStmt(TL.getTypePtr()->getSizeExpr()));   TRY_TO(TraverseType(TL.getTypePtr()->getElementType())); }
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
argument|{   TRY_TO(TraverseType(TL.getTypePtr()->getElementType())); }
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
argument|{   TRY_TO(TraverseType(TL.getTypePtr()->getElementType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|FunctionNoProtoType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getReturnLoc())); }
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
argument|{   TRY_TO(TraverseTypeLoc(TL.getReturnLoc()));    const FunctionProtoType *T = TL.getTypePtr();    for (unsigned I =
literal|0
argument|, E = TL.getNumParams(); I != E; ++I) {     if (TL.getParam(I)) {       TRY_TO(TraverseDecl(TL.getParam(I)));     } else if (I< T->getNumParams()) {       TRY_TO(TraverseType(T->getParamType(I)));     }   }    for (const auto&E : T->exceptions()) {     TRY_TO(TraverseType(E));   }    if (Expr *NE = T->getNoexceptExpr())     TRY_TO(TraverseStmt(NE)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|UnresolvedUsingType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|TypedefType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|TypeOfExprType
argument_list|,
argument|{ TRY_TO(TraverseStmt(TL.getUnderlyingExpr())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|TypeOfType
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(TL.getUnderlyingTInfo()->getTypeLoc())); }
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
argument|{   TRY_TO(TraverseStmt(TL.getTypePtr()->getUnderlyingExpr())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|UnaryTransformType
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(TL.getUnderlyingTInfo()->getTypeLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|AutoType
argument_list|,
argument|{   TRY_TO(TraverseType(TL.getTypePtr()->getDeducedType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DeducedTemplateSpecializationType
argument_list|,
argument|{   TRY_TO(TraverseTemplateName(TL.getTypePtr()->getTemplateName()));   TRY_TO(TraverseType(TL.getTypePtr()->getDeducedType())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|RecordType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|EnumType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|TemplateTypeParmType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|SubstTemplateTypeParmType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|SubstTemplateTypeParmPackType
argument_list|,
argument|{}
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
argument|{   TRY_TO(TraverseTemplateName(TL.getTypePtr()->getTemplateName()));   for (unsigned I =
literal|0
argument|, E = TL.getNumArgs(); I != E; ++I) {     TRY_TO(TraverseTemplateArgumentLoc(TL.getArgLoc(I)));   } }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|InjectedClassNameType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ParenType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getInnerLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|AttributedType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getModifiedLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ElaboratedType
argument_list|,
argument|{   if (TL.getQualifierLoc()) {     TRY_TO(TraverseNestedNameSpecifierLoc(TL.getQualifierLoc()));   }   TRY_TO(TraverseTypeLoc(TL.getNamedTypeLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DependentNameType
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(TL.getQualifierLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|DependentTemplateSpecializationType
argument_list|,
argument|{   if (TL.getQualifierLoc()) {     TRY_TO(TraverseNestedNameSpecifierLoc(TL.getQualifierLoc()));   }    for (unsigned I =
literal|0
argument|, E = TL.getNumArgs(); I != E; ++I) {     TRY_TO(TraverseTemplateArgumentLoc(TL.getArgLoc(I)));   } }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|PackExpansionType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getPatternLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ObjCTypeParamType
argument_list|,
argument|{}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ObjCInterfaceType
argument_list|,
argument|{}
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
argument|if (TL.getTypePtr()->getBaseType().getTypePtr() != TL.getTypePtr())     TRY_TO(TraverseTypeLoc(TL.getBaseLoc()));   for (unsigned i =
literal|0
argument|, n = TL.getNumTypeArgs(); i != n; ++i)     TRY_TO(TraverseTypeLoc(TL.getTypeArgTInfo(i)->getTypeLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|ObjCObjectPointerType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getPointeeLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|AtomicType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getValueLoc())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_TYPELOC
argument_list|(
argument|PipeType
argument_list|,
argument|{ TRY_TO(TraverseTypeLoc(TL.getValueLoc())); }
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
name|auto
operator|*
name|Child
operator|:
name|DC
operator|->
name|decls
argument_list|()
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
name|Child
operator|)
operator|&&
operator|!
name|isa
operator|<
name|CapturedDecl
operator|>
operator|(
name|Child
operator|)
condition|)
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
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
value|template<typename Derived>                                                  \   bool RecursiveASTVisitor<Derived>::Traverse##DECL(DECL *D) {                 \     bool ShouldVisitChildren = true;                                           \     bool ReturnValue = true;                                                   \     if (!getDerived().shouldTraversePostOrder())                               \       TRY_TO(WalkUpFrom##DECL(D));                                             \     { CODE; }                                                                  \     if (ReturnValue&& ShouldVisitChildren)                                    \       TRY_TO(TraverseDeclContextHelper(dyn_cast<DeclContext>(D)));             \     if (ReturnValue&& getDerived().shouldTraversePostOrder())                 \       TRY_TO(WalkUpFrom##DECL(D));                                             \     return ReturnValue;                                                        \   }
end_define

begin_expr_stmt
unit|DEF_TRAVERSE_DECL
operator|(
name|AccessSpecDecl
operator|,
block|{}
operator|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|BlockDecl
argument_list|,
argument|{   if (TypeSourceInfo *TInfo = D->getSignatureAsWritten())     TRY_TO(TraverseTypeLoc(TInfo->getTypeLoc()));   TRY_TO(TraverseStmt(D->getBody()));   for (const auto&I : D->captures()) {     if (I.hasCopyExpr()) {       TRY_TO(TraverseStmt(I.getCopyExpr()));     }   }   ShouldVisitChildren = false; }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CapturedDecl
argument_list|,
argument|{   TRY_TO(TraverseStmt(D->getBody()));   ShouldVisitChildren = false; }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|EmptyDecl
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|FileScopeAsmDecl
argument_list|,
argument|{ TRY_TO(TraverseStmt(D->getAsmString())); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ImportDecl
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|FriendDecl
argument_list|,
argument|{
comment|// Friend is either decl or a type.
argument|if (D->getFriendType())     TRY_TO(TraverseTypeLoc(D->getFriendType()->getTypeLoc()));   else     TRY_TO(TraverseDecl(D->getFriendDecl())); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|FriendTemplateDecl
argument_list|,
argument|{   if (D->getFriendType())     TRY_TO(TraverseTypeLoc(D->getFriendType()->getTypeLoc()));   else     TRY_TO(TraverseDecl(D->getFriendDecl()));   for (unsigned I =
literal|0
argument|, E = D->getNumTemplateParameters(); I< E; ++I) {     TemplateParameterList *TPL = D->getTemplateParameterList(I);     for (TemplateParameterList::iterator ITPL = TPL->begin(), ETPL = TPL->end();          ITPL != ETPL; ++ITPL) {       TRY_TO(TraverseDecl(*ITPL));     }   } }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ClassScopeFunctionSpecializationDecl
argument_list|,
argument|{   TRY_TO(TraverseDecl(D->getSpecialization()));    if (D->hasExplicitTemplateArgs()) {     const TemplateArgumentListInfo&args = D->templateArgs();     TRY_TO(TraverseTemplateArgumentLocsHelper(args.getArgumentArray(),                                               args.size()));   } }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|LinkageSpecDecl
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ExportDecl
argument_list|,
argument|{}
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
argument|{   TRY_TO(TraverseStmt(D->getAssertExpr()));   TRY_TO(TraverseStmt(D->getMessage())); }
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
argument|PragmaCommentDecl
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|PragmaDetectMismatchDecl
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ExternCContextDecl
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|NamespaceAliasDecl
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(D->getQualifierLoc()));
comment|// We shouldn't traverse an aliased namespace, since it will be
comment|// defined (and, therefore, traversed) somewhere else.
argument|ShouldVisitChildren = false; }
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
argument|if (ObjCTypeParamList *typeParamList = D->getTypeParamList()) {     for (auto typeParam : *typeParamList) {       TRY_TO(TraverseObjCTypeParamDecl(typeParam));     }   } }
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
argument|if (ObjCTypeParamList *typeParamList = D->getTypeParamListAsWritten()) {     for (auto typeParam : *typeParamList) {       TRY_TO(TraverseObjCTypeParamDecl(typeParam));     }   }    if (TypeSourceInfo *superTInfo = D->getSuperClassTInfo()) {     TRY_TO(TraverseTypeLoc(superTInfo->getTypeLoc()));   } }
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
argument|{   if (D->getReturnTypeSourceInfo()) {     TRY_TO(TraverseTypeLoc(D->getReturnTypeSourceInfo()->getTypeLoc()));   }   for (ParmVarDecl *Parameter : D->parameters()) {     TRY_TO(TraverseDecl(Parameter));   }   if (D->isThisDeclarationADefinition()) {     TRY_TO(TraverseStmt(D->getBody()));   }   ShouldVisitChildren = false; }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCTypeParamDecl
argument_list|,
argument|{   if (D->hasExplicitBound()) {     TRY_TO(TraverseTypeLoc(D->getTypeSourceInfo()->getTypeLoc()));
comment|// We shouldn't traverse D->getTypeForDecl(); it's a result of
comment|// declaring the type alias, not something that was written in the
comment|// source.
argument|} }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCPropertyDecl
argument_list|,
argument|{   if (D->getTypeSourceInfo())     TRY_TO(TraverseTypeLoc(D->getTypeSourceInfo()->getTypeLoc()));   else     TRY_TO(TraverseType(D->getType()));   ShouldVisitChildren = false; }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UsingDecl
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(D->getQualifierLoc()));   TRY_TO(TraverseDeclarationNameInfo(D->getNameInfo())); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UsingPackDecl
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UsingDirectiveDecl
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(D->getQualifierLoc())); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UsingShadowDecl
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ConstructorUsingShadowDecl
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|OMPThreadPrivateDecl
argument_list|,
argument|{   for (auto *I : D->varlists()) {     TRY_TO(TraverseStmt(I));   } }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|OMPDeclareReductionDecl
argument_list|,
argument|{   TRY_TO(TraverseStmt(D->getCombiner()));   if (auto *Initializer = D->getInitializer())     TRY_TO(TraverseStmt(Initializer));   TRY_TO(TraverseType(D->getType()));   return true; }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|OMPCapturedExprDecl
argument_list|,
argument|{ TRY_TO(TraverseVarHelper(D)); }
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
unit|}  template
operator|<
name|typename
name|Derived
operator|>
name|template
operator|<
name|typename
name|T
operator|>
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|TraverseDeclTemplateParameterLists
argument_list|(
argument|T *D
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|D
operator|->
name|getNumTemplateParameterLists
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|TemplateParameterList
modifier|*
name|TPL
init|=
name|D
operator|->
name|getTemplateParameterList
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|TraverseTemplateParameterListHelper
argument_list|(
name|TPL
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
name|TraverseTemplateInstantiations
argument_list|(
argument|ClassTemplateDecl *D
argument_list|)
block|{
for|for
control|(
name|auto
operator|*
name|SD
operator|:
name|D
operator|->
name|specializations
argument_list|()
control|)
block|{
for|for
control|(
name|auto
operator|*
name|RD
operator|:
name|SD
operator|->
name|redecls
argument_list|()
control|)
block|{
comment|// We don't want to visit injected-class-names in this traversal.
if|if
condition|(
name|cast
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|RD
operator|)
operator|->
name|isInjectedClassName
argument_list|()
condition|)
continue|continue;
switch|switch
condition|(
name|cast
operator|<
name|ClassTemplateSpecializationDecl
operator|>
operator|(
name|RD
operator|)
operator|->
name|getSpecializationKind
argument_list|()
condition|)
block|{
comment|// Visit the implicit instantiations with the requested pattern.
case|case
name|TSK_Undeclared
case|:
case|case
name|TSK_ImplicitInstantiation
case|:
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
name|RD
argument_list|)
argument_list|)
expr_stmt|;
break|break;
comment|// We don't need to do anything on an explicit instantiation
comment|// or explicit specialization because there will be an explicit
comment|// node for it elsewhere.
case|case
name|TSK_ExplicitInstantiationDeclaration
case|:
case|case
name|TSK_ExplicitInstantiationDefinition
case|:
case|case
name|TSK_ExplicitSpecialization
case|:
break|break;
block|}
end_expr_stmt

begin_return
unit|}   }
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
name|TraverseTemplateInstantiations
argument_list|(
argument|VarTemplateDecl *D
argument_list|)
block|{
for|for
control|(
name|auto
operator|*
name|SD
operator|:
name|D
operator|->
name|specializations
argument_list|()
control|)
block|{
for|for
control|(
name|auto
operator|*
name|RD
operator|:
name|SD
operator|->
name|redecls
argument_list|()
control|)
block|{
switch|switch
condition|(
name|cast
operator|<
name|VarTemplateSpecializationDecl
operator|>
operator|(
name|RD
operator|)
operator|->
name|getSpecializationKind
argument_list|()
condition|)
block|{
case|case
name|TSK_Undeclared
case|:
case|case
name|TSK_ImplicitInstantiation
case|:
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
name|RD
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|TSK_ExplicitInstantiationDeclaration
case|:
case|case
name|TSK_ExplicitInstantiationDefinition
case|:
case|case
name|TSK_ExplicitSpecialization
case|:
break|break;
block|}
end_expr_stmt

begin_return
unit|}   }
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|// A helper method for traversing the instantiations of a
end_comment

begin_comment
comment|// function while skipping its specializations.
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
name|TraverseTemplateInstantiations
argument_list|(
argument|FunctionTemplateDecl *D
argument_list|)
block|{
for|for
control|(
name|auto
operator|*
name|FD
operator|:
name|D
operator|->
name|specializations
argument_list|()
control|)
block|{
for|for
control|(
name|auto
operator|*
name|RD
operator|:
name|FD
operator|->
name|redecls
argument_list|()
control|)
block|{
switch|switch
condition|(
name|RD
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
name|RD
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
name|RD
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

begin_return
unit|}   }
return|return
name|true
return|;
end_return

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
value|DEF_TRAVERSE_DECL(TMPLDECLKIND##TemplateDecl, {                              \     TRY_TO(TraverseDecl(D->getTemplatedDecl()));                               \     TRY_TO(TraverseTemplateParameterListHelper(D->getTemplateParameters()));   \                                                                                \
comment|/* By default, we do not traverse the instantiations of                    \        class templates since they do not appear in the user code. The          \        following code optionally traverses them.                               \                                                                                \        We only traverse the class instantiations when we see the canonical     \        declaration of the template, to ensure we only visit them once. */
value|\     if (getDerived().shouldVisitTemplateInstantiations()&&                    \         D == D->getCanonicalDecl())                                            \       TRY_TO(TraverseTemplateInstantiations(D));                               \                                                                                \
comment|/* Note that getInstantiatedFromMemberTemplate() is just a link            \        from a template instantiation back to the template from which           \        it was instantiated, and thus should not be traversed. */
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
argument|TRY_TO(TraverseDecl(D->getTemplatedDecl()));   if (D->hasDefaultArgument()&& !D->defaultArgumentWasInherited()) {     TRY_TO(TraverseTemplateArgumentLoc(D->getDefaultArgument()));   }   TRY_TO(TraverseTemplateParameterListHelper(D->getTemplateParameters())); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|BuiltinTemplateDecl
argument_list|,
argument|{   TRY_TO(TraverseTemplateParameterListHelper(D->getTemplateParameters())); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TemplateTypeParmDecl
argument_list|,
argument|{
comment|// D is the "T" in something like "template<typename T> class vector;"
argument|if (D->getTypeForDecl())     TRY_TO(TraverseType(QualType(D->getTypeForDecl(),
literal|0
argument|)));   if (D->hasDefaultArgument()&& !D->defaultArgumentWasInherited())     TRY_TO(TraverseTypeLoc(D->getDefaultArgumentInfo()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TypedefDecl
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(D->getTypeSourceInfo()->getTypeLoc()));
comment|// We shouldn't traverse D->getTypeForDecl(); it's a result of
comment|// declaring the typedef, not something that was written in the
comment|// source.
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TypeAliasDecl
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(D->getTypeSourceInfo()->getTypeLoc()));
comment|// We shouldn't traverse D->getTypeForDecl(); it's a result of
comment|// declaring the type alias, not something that was written in the
comment|// source.
argument|}
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|TypeAliasTemplateDecl
argument_list|,
argument|{   TRY_TO(TraverseDecl(D->getTemplatedDecl()));   TRY_TO(TraverseTemplateParameterListHelper(D->getTemplateParameters())); }
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
argument|{   TRY_TO(TraverseDeclTemplateParameterLists(D));    if (D->getTypeForDecl())     TRY_TO(TraverseType(QualType(D->getTypeForDecl(),
literal|0
argument|)));    TRY_TO(TraverseNestedNameSpecifierLoc(D->getQualifierLoc()));
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
name|TraverseDeclTemplateParameterLists
argument_list|(
name|D
argument_list|)
argument_list|)
block|;
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
specifier|const
specifier|auto
modifier|&
name|I
range|:
name|D
operator|->
name|bases
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseTypeLoc
argument_list|(
name|I
operator|.
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
block|; }
operator|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CXXRecordDecl
argument_list|,
argument|{ TRY_TO(TraverseCXXRecordHelper(D)); }
argument_list|)
define|#
directive|define
name|DEF_TRAVERSE_TMPL_SPEC_DECL
parameter_list|(
name|TMPLDECLKIND
parameter_list|)
define|\
value|DEF_TRAVERSE_DECL(TMPLDECLKIND##TemplateSpecializationDecl, {                \
comment|/* For implicit instantiations ("set<int> x;"), we don't want to           \        recurse at all, since the instatiated template isn't written in         \        the source code anywhere.  (Note the instatiated *type* --              \        set<int> -- is written, and will still get a callback of                \        TemplateSpecializationType).  For explicit instantiations               \        ("template set<int>;"), we do need a callback, since this               \        is the only callback that's made for this instantiation.                \        We use getTypeAsWritten() to distinguish. */
value|\     if (TypeSourceInfo *TSI = D->getTypeAsWritten())                           \       TRY_TO(TraverseTypeLoc(TSI->getTypeLoc()));                              \                                                                                \     if (!getDerived().shouldVisitTemplateInstantiations()&&                   \         D->getTemplateSpecializationKind() != TSK_ExplicitSpecialization)      \
comment|/* Returning from here skips traversing the                              \          declaration context of the *TemplateSpecializationDecl                \          (embedded in the DEF_TRAVERSE_DECL() macro)                           \          which contains the instantiated members of the template. */
value|\       return true;                                                             \   })
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
value|\     if (TemplateParameterList *TPL = D->getTemplateParameters()) {             \       for (TemplateParameterList::iterator I = TPL->begin(), E = TPL->end();   \            I != E; ++I) {                                                      \         TRY_TO(TraverseDecl(*I));                                              \       }                                                                        \     }                                                                          \
comment|/* The args that remains unspecialized. */
value|\     TRY_TO(TraverseTemplateArgumentLocsHelper(                                 \         D->getTemplateArgsAsWritten()->getTemplateArgs(),                      \         D->getTemplateArgsAsWritten()->NumTemplateArgs));                      \                                                                                \
comment|/* Don't need the *TemplatePartialSpecializationHelper, even               \        though that's our parent class -- we already visit all the              \        template args here. */
value|\     TRY_TO(Traverse##DECLKIND##Helper(D));                                     \                                                                                \
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
argument|{ TRY_TO(TraverseStmt(D->getInitExpr())); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|UnresolvedUsingValueDecl
argument_list|,
argument|{
comment|// Like UnresolvedUsingTypenameDecl, but without the 'typename':
comment|//    template<class T> Class A : public Base<T> { using Base<T>::foo; };
argument|TRY_TO(TraverseNestedNameSpecifierLoc(D->getQualifierLoc()));   TRY_TO(TraverseDeclarationNameInfo(D->getNameInfo())); }
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
name|TraverseDeclTemplateParameterLists
argument_list|(
name|D
argument_list|)
argument_list|)
block|;
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
name|DecompositionDecl
operator|,
block|{
name|TRY_TO
argument_list|(
name|TraverseVarHelper
argument_list|(
name|D
argument_list|)
argument_list|)
block|;
for|for
control|(
name|auto
operator|*
name|Binding
operator|:
name|D
operator|->
name|bindings
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
name|Binding
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_macro
unit|})
name|DEF_TRAVERSE_DECL
argument_list|(
argument|BindingDecl
argument_list|,
argument|{   if (getDerived().shouldVisitImplicitCode())     TRY_TO(TraverseStmt(D->getBinding())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|MSPropertyDecl
argument_list|,
argument|{ TRY_TO(TraverseDeclaratorHelper(D)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|FieldDecl
argument_list|,
argument|{   TRY_TO(TraverseDeclaratorHelper(D));   if (D->isBitField())     TRY_TO(TraverseStmt(D->getBitWidth()));   else if (D->hasInClassInitializer())     TRY_TO(TraverseStmt(D->getInClassInitializer())); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCAtDefsFieldDecl
argument_list|,
argument|{   TRY_TO(TraverseDeclaratorHelper(D));   if (D->isBitField())     TRY_TO(TraverseStmt(D->getBitWidth()));
comment|// FIXME: implement the rest.
argument|}
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ObjCIvarDecl
argument_list|,
argument|{   TRY_TO(TraverseDeclaratorHelper(D));   if (D->isBitField())     TRY_TO(TraverseStmt(D->getBitWidth()));
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
name|TraverseDeclTemplateParameterLists
argument_list|(
name|D
argument_list|)
argument_list|)
block|;
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
name|ParmVarDecl
modifier|*
name|Parameter
range|:
name|D
operator|->
name|parameters
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseDecl
argument_list|(
name|Parameter
argument_list|)
argument_list|)
expr_stmt|;
block|}
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
name|auto
operator|*
name|I
operator|:
name|Ctor
operator|->
name|inits
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseConstructorInitializer
argument_list|(
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
name|ShouldVisitChildren
operator|=
name|false
block|;
name|ReturnValue
operator|=
name|TraverseFunctionHelper
argument_list|(
name|D
argument_list|)
block|; }
operator|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CXXDeductionGuideDecl
argument_list|,
argument|{
comment|// We skip decls_begin/decls_end, which are already covered by
comment|// TraverseFunctionHelper().
argument|ShouldVisitChildren = false;   ReturnValue = TraverseFunctionHelper(D); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CXXMethodDecl
argument_list|,
argument|{
comment|// We skip decls_begin/decls_end, which are already covered by
comment|// TraverseFunctionHelper().
argument|ShouldVisitChildren = false;   ReturnValue = TraverseFunctionHelper(D); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CXXConstructorDecl
argument_list|,
argument|{
comment|// We skip decls_begin/decls_end, which are already covered by
comment|// TraverseFunctionHelper().
argument|ShouldVisitChildren = false;   ReturnValue = TraverseFunctionHelper(D); }
argument_list|)
comment|// CXXConversionDecl is the declaration of a type conversion operator.
comment|// It's not a cast expression.
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CXXConversionDecl
argument_list|,
argument|{
comment|// We skip decls_begin/decls_end, which are already covered by
comment|// TraverseFunctionHelper().
argument|ShouldVisitChildren = false;   ReturnValue = TraverseFunctionHelper(D); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|CXXDestructorDecl
argument_list|,
argument|{
comment|// We skip decls_begin/decls_end, which are already covered by
comment|// TraverseFunctionHelper().
argument|ShouldVisitChildren = false;   ReturnValue = TraverseFunctionHelper(D); }
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
block|; }
operator|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ImplicitParamDecl
argument_list|,
argument|{ TRY_TO(TraverseVarHelper(D)); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|NonTypeTemplateParmDecl
argument_list|,
argument|{
comment|// A non-type template parameter, e.g. "S" in template<int S> class Foo ...
argument|TRY_TO(TraverseDeclaratorHelper(D));   if (D->hasDefaultArgument()&& !D->defaultArgumentWasInherited())     TRY_TO(TraverseStmt(D->getDefaultArgument())); }
argument_list|)
name|DEF_TRAVERSE_DECL
argument_list|(
argument|ParmVarDecl
argument_list|,
argument|{   TRY_TO(TraverseVarHelper(D));    if (D->hasDefaultArg()&& D->hasUninstantiatedDefaultArg()&&       !D->hasUnparsedDefaultArg())     TRY_TO(TraverseStmt(D->getUninstantiatedDefaultArg()));    if (D->hasDefaultArg()&& !D->hasUninstantiatedDefaultArg()&&       !D->hasUnparsedDefaultArg())     TRY_TO(TraverseStmt(D->getDefaultArg())); }
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
value|template<typename Derived>                                                  \   bool RecursiveASTVisitor<Derived>::Traverse##STMT(                           \       STMT *S, DataRecursionQueue *Queue) {                                    \     bool ShouldVisitChildren = true;                                           \     bool ReturnValue = true;                                                   \     if (!getDerived().shouldTraversePostOrder())                               \       TRY_TO(WalkUpFrom##STMT(S));                                             \     { CODE; }                                                                  \     if (ShouldVisitChildren) {                                                 \       for (Stmt *SubStmt : S->children()) {                                    \         TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(SubStmt);                              \       }                                                                        \     }                                                                          \     if (!Queue&& ReturnValue&& getDerived().shouldTraversePostOrder())       \       TRY_TO(WalkUpFrom##STMT(S));                                             \     return ReturnValue;                                                        \   }
name|DEF_TRAVERSE_STMT
argument_list|(
argument|GCCAsmStmt
argument_list|,
argument|{   TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getAsmString());   for (unsigned I =
literal|0
argument|, E = S->getNumInputs(); I< E; ++I) {     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getInputConstraintLiteral(I));   }   for (unsigned I =
literal|0
argument|, E = S->getNumOutputs(); I< E; ++I) {     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getOutputConstraintLiteral(I));   }   for (unsigned I =
literal|0
argument|, E = S->getNumClobbers(); I< E; ++I) {     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getClobberStringLiteral(I));   }
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
argument|{   TRY_TO(TraverseDecl(S->getExceptionDecl()));
comment|// children() iterates over the handler block.
argument|}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DeclStmt
argument_list|,
argument|{   for (auto *I : S->decls()) {     TRY_TO(TraverseDecl(I));   }
comment|// Suppress the default iteration over children() by
comment|// returning.  Here's why: A DeclStmt looks like 'type var [=
comment|// initializer]'.  The decls above already traverse over the
comment|// initializers, so we don't have to do it again (which
comment|// children() would do).
argument|ShouldVisitChildren = false; }
argument_list|)
comment|// These non-expr stmts (most of them), do not need any action except
comment|// iterating over the children.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|BreakStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXTryStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CaseStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CompoundStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ContinueStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DefaultStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DoStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ForStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|GotoStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|IfStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|IndirectGotoStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|LabelStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|AttributedStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|NullStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtCatchStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtFinallyStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtSynchronizedStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtThrowStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAtTryStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCForCollectionStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAutoreleasePoolStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXForRangeStmt
argument_list|,
argument|{   if (!getDerived().shouldVisitImplicitCode()) {     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getLoopVarStmt());     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getRangeInit());     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getBody());
comment|// Visit everything else only if shouldVisitImplicitCode().
argument|ShouldVisitChildren = false;   } }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|MSDependentExistsStmt
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));   TRY_TO(TraverseDeclarationNameInfo(S->getNameInfo())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ReturnStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SwitchStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|WhileStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDependentScopeMemberExpr
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));   TRY_TO(TraverseDeclarationNameInfo(S->getMemberNameInfo()));   if (S->hasExplicitTemplateArgs()) {     TRY_TO(TraverseTemplateArgumentLocsHelper(S->getTemplateArgs(),                                               S->getNumTemplateArgs()));   } }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DeclRefExpr
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));   TRY_TO(TraverseDeclarationNameInfo(S->getNameInfo()));   TRY_TO(TraverseTemplateArgumentLocsHelper(S->getTemplateArgs(),                                             S->getNumTemplateArgs())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DependentScopeDeclRefExpr
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));   TRY_TO(TraverseDeclarationNameInfo(S->getNameInfo()));   if (S->hasExplicitTemplateArgs()) {     TRY_TO(TraverseTemplateArgumentLocsHelper(S->getTemplateArgs(),                                               S->getNumTemplateArgs()));   } }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|MemberExpr
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc()));   TRY_TO(TraverseDeclarationNameInfo(S->getMemberNameInfo()));   TRY_TO(TraverseTemplateArgumentLocsHelper(S->getTemplateArgs(),                                             S->getNumTemplateArgs())); }
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
argument|{   TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXFunctionalCastExpr
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXConstCastExpr
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDynamicCastExpr
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXReinterpretCastExpr
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXStaticCastExpr
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc())); }
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
name|TraverseSynOrSemInitListExpr
argument_list|(
argument|InitListExpr *S
argument_list|,
argument|DataRecursionQueue *Queue
argument_list|)
block|{
if|if
condition|(
name|S
condition|)
block|{
comment|// Skip this if we traverse postorder. We will visit it later
comment|// in PostVisitStmt.
if|if
condition|(
operator|!
name|getDerived
argument_list|()
operator|.
name|shouldTraversePostOrder
argument_list|()
condition|)
name|TRY_TO
argument_list|(
name|WalkUpFromInitListExpr
argument_list|(
name|S
argument_list|)
argument_list|)
expr_stmt|;
comment|// All we need are the default actions.  FIXME: use a helper function.
for|for
control|(
name|Stmt
modifier|*
name|SubStmt
range|:
name|S
operator|->
name|children
argument_list|()
control|)
block|{
name|TRY_TO_TRAVERSE_OR_ENQUEUE_STMT
argument_list|(
name|SubStmt
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
unit|}   return
name|true
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// This method is called once for each pair of syntactic and semantic
end_comment

begin_comment
comment|// InitListExpr, and it traverses the subtrees defined by the two forms. This
end_comment

begin_comment
comment|// may cause some of the children to be visited twice, if they appear both in
end_comment

begin_comment
comment|// the syntactic and the semantic form.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// There is no guarantee about which form \p S takes when this method is called.
end_comment

begin_expr_stmt
unit|DEF_TRAVERSE_STMT
operator|(
name|InitListExpr
operator|,
block|{
name|TRY_TO
argument_list|(
name|TraverseSynOrSemInitListExpr
argument_list|(
name|S
operator|->
name|isSemanticForm
argument_list|()
condition|?
name|S
operator|->
name|getSyntacticForm
argument_list|()
else|:
name|S
argument_list|,
name|Queue
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseSynOrSemInitListExpr
argument_list|(
name|S
operator|->
name|isSemanticForm
argument_list|()
condition|?
name|S
else|:
name|S
operator|->
name|getSemanticForm
argument_list|()
argument_list|,
name|Queue
argument_list|)
argument_list|)
block|;
name|ShouldVisitChildren
operator|=
name|false
block|; }
operator|)
comment|// GenericSelectionExpr is a special case because the types and expressions
comment|// are interleaved.  We also need to watch out for null types (default
comment|// generic associations).
name|DEF_TRAVERSE_STMT
argument_list|(
argument|GenericSelectionExpr
argument_list|,
argument|{   TRY_TO(TraverseStmt(S->getControllingExpr()));   for (unsigned i =
literal|0
argument|; i != S->getNumAssocs(); ++i) {     if (TypeSourceInfo *TS = S->getAssocTypeSourceInfo(i))       TRY_TO(TraverseTypeLoc(TS->getTypeLoc()));     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getAssocExpr(i));   }   ShouldVisitChildren = false; }
argument_list|)
comment|// PseudoObjectExpr is a special case because of the weirdness with
comment|// syntactic expressions and opaque values.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|PseudoObjectExpr
argument_list|,
argument|{   TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getSyntacticForm());   for (PseudoObjectExpr::semantics_iterator i = S->semantics_begin(),                                             e = S->semantics_end();        i != e; ++i) {     Expr *sub = *i;     if (OpaqueValueExpr *OVE = dyn_cast<OpaqueValueExpr>(sub))       sub = OVE->getSourceExpr();     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(sub);   }   ShouldVisitChildren = false; }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXScalarValueInitExpr
argument_list|,
argument|{
comment|// This is called for code like 'return T()' where T is a built-in
comment|// (i.e. non-class) type.
argument|TRY_TO(TraverseTypeLoc(S->getTypeSourceInfo()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXNewExpr
argument_list|,
argument|{
comment|// The child-iterator will pick up the other arguments.
argument|TRY_TO(TraverseTypeLoc(S->getAllocatedTypeSourceInfo()->getTypeLoc())); }
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
argument|TRY_TO(TraverseTypeLoc(S->getTypeSourceInfo()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UnaryExprOrTypeTraitExpr
argument_list|,
argument|{
comment|// The child-iterator will pick up the arg if it's an expression,
comment|// but not if it's a type.
argument|if (S->isArgumentType())     TRY_TO(TraverseTypeLoc(S->getArgumentTypeInfo()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXTypeidExpr
argument_list|,
argument|{
comment|// The child-iterator will pick up the arg if it's an expression,
comment|// but not if it's a type.
argument|if (S->isTypeOperand())     TRY_TO(TraverseTypeLoc(S->getTypeOperandSourceInfo()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|MSPropertyRefExpr
argument_list|,
argument|{   TRY_TO(TraverseNestedNameSpecifierLoc(S->getQualifierLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|MSPropertySubscriptExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXUuidofExpr
argument_list|,
argument|{
comment|// The child-iterator will pick up the arg if it's an expression,
comment|// but not if it's a type.
argument|if (S->isTypeOperand())     TRY_TO(TraverseTypeLoc(S->getTypeOperandSourceInfo()->getTypeLoc())); }
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
argument|{   TRY_TO(TraverseTypeLoc(S->getQueriedTypeSourceInfo()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ExpressionTraitExpr
argument_list|,
argument|{ TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getQueriedExpression()); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|VAArgExpr
argument_list|,
argument|{
comment|// The child-iterator will pick up the expression argument.
argument|TRY_TO(TraverseTypeLoc(S->getWrittenTypeInfo()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXTemporaryObjectExpr
argument_list|,
argument|{
comment|// This is called for code like 'return T()' where T is a class type.
argument|TRY_TO(TraverseTypeLoc(S->getTypeSourceInfo()->getTypeLoc())); }
argument_list|)
comment|// Walk only the visible parts of lambda expressions.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|LambdaExpr
argument_list|,
argument|{   for (unsigned I =
literal|0
argument|, N = S->capture_size(); I != N; ++I) {     const LambdaCapture *C = S->capture_begin() + I;     if (C->isExplicit() || getDerived().shouldVisitImplicitCode()) {       TRY_TO(TraverseLambdaCapture(S, C, S->capture_init_begin()[I]));     }   }    TypeLoc TL = S->getCallOperator()->getTypeSourceInfo()->getTypeLoc();   FunctionProtoTypeLoc Proto = TL.castAs<FunctionProtoTypeLoc>();    if (S->hasExplicitParameters()&& S->hasExplicitResultType()) {
comment|// Visit the whole type.
argument|TRY_TO(TraverseTypeLoc(TL));   } else {     if (S->hasExplicitParameters()) {
comment|// Visit parameters.
argument|for (unsigned I =
literal|0
argument|, N = Proto.getNumParams(); I != N; ++I) {         TRY_TO(TraverseDecl(Proto.getParam(I)));       }     } else if (S->hasExplicitResultType()) {       TRY_TO(TraverseTypeLoc(Proto.getReturnLoc()));     }      auto *T = Proto.getTypePtr();     for (const auto&E : T->exceptions()) {       TRY_TO(TraverseType(E));     }      if (Expr *NE = T->getNoexceptExpr())       TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(NE);   }    ReturnValue = TRAVERSE_STMT_BASE(LambdaBody, LambdaExpr, S, Queue);   ShouldVisitChildren = false; }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXUnresolvedConstructExpr
argument_list|,
argument|{
comment|// This is called for code like 'T()', where T is a template argument.
argument|TRY_TO(TraverseTypeLoc(S->getTypeSourceInfo()->getTypeLoc())); }
argument_list|)
comment|// These expressions all might take explicit template arguments.
comment|// We traverse those if so.  FIXME: implement these.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXConstructExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CallExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXMemberCallExpr
argument_list|,
argument|{}
argument_list|)
comment|// These exprs (most of them), do not need any action except iterating
comment|// over the children.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|AddrLabelExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ArraySubscriptExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPArraySectionExpr
argument_list|,
argument|{}
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
argument|{}
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
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXBoolLiteralExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDefaultArgExpr
argument_list|,
argument|{   if (getDerived().shouldVisitImplicitCode())     TRY_TO(TraverseStmt(S->getExpr())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDefaultInitExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXDeleteExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ExprWithCleanups
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXInheritedCtorInitExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXNullPtrLiteralExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXStdInitializerListExpr
argument_list|,
argument|{}
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
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXThrowExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UserDefinedLiteral
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DesignatedInitExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DesignatedInitUpdateExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ExtVectorElementExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|GNUNullExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ImplicitValueInitExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|NoInitExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ArrayInitLoopExpr
argument_list|,
argument|{
comment|// FIXME: The source expression of the OVE should be listed as
comment|// a child of the ArrayInitLoopExpr.
argument|if (OpaqueValueExpr *OVE = S->getCommonExpr())     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(OVE->getSourceExpr()); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ArrayInitIndexExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCBoolLiteralExpr
argument_list|,
argument|{}
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
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCIvarRefExpr
argument_list|,
argument|{}
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
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCSubscriptRefExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCProtocolExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCSelectorExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCIndirectCopyRestoreExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCBridgedCastExpr
argument_list|,
argument|{   TRY_TO(TraverseTypeLoc(S->getTypeInfoAsWritten()->getTypeLoc())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCAvailabilityCheckExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ParenExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ParenListExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|PredefinedExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ShuffleVectorExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ConvertVectorExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|StmtExpr
argument_list|,
argument|{}
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
argument|SEHLeaveStmt
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CapturedStmt
argument_list|,
argument|{ TRY_TO(TraverseDecl(S->getCapturedDecl())); }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXOperatorCallExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OpaqueValueExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|TypoExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CUDAKernelCallExpr
argument_list|,
argument|{}
argument_list|)
comment|// These operators (all of them) do not need any action except
comment|// iterating over the children.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|BinaryConditionalOperator
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ConditionalOperator
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|UnaryOperator
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|BinaryOperator
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CompoundAssignOperator
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXNoexceptExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|PackExpansionExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SizeOfPackExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SubstNonTypeTemplateParmPackExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|SubstNonTypeTemplateParmExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|FunctionParmPackExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|MaterializeTemporaryExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CXXFoldExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|AtomicExpr
argument_list|,
argument|{}
argument_list|)
comment|// For coroutines expressions, traverse either the operand
comment|// as written or the implied calls, depending on what the
comment|// derived class requests.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CoroutineBodyStmt
argument_list|,
argument|{   if (!getDerived().shouldVisitImplicitCode()) {     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getBody());     ShouldVisitChildren = false;   } }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CoreturnStmt
argument_list|,
argument|{   if (!getDerived().shouldVisitImplicitCode()) {     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getOperand());     ShouldVisitChildren = false;   } }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CoawaitExpr
argument_list|,
argument|{   if (!getDerived().shouldVisitImplicitCode()) {     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getOperand());     ShouldVisitChildren = false;   } }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|DependentCoawaitExpr
argument_list|,
argument|{   if (!getDerived().shouldVisitImplicitCode()) {     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getOperand());     ShouldVisitChildren = false;   } }
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CoyieldExpr
argument_list|,
argument|{   if (!getDerived().shouldVisitImplicitCode()) {     TRY_TO_TRAVERSE_OR_ENQUEUE_STMT(S->getOperand());     ShouldVisitChildren = false;   } }
argument_list|)
comment|// These literals (all of them) do not need any action.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|IntegerLiteral
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|CharacterLiteral
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|FloatingLiteral
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ImaginaryLiteral
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|StringLiteral
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCStringLiteral
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCBoxedExpr
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCArrayLiteral
argument_list|,
argument|{}
argument_list|)
name|DEF_TRAVERSE_STMT
argument_list|(
argument|ObjCDictionaryLiteral
argument_list|,
argument|{}
argument_list|)
comment|// Traverse OpenCL: AsType, Convert.
name|DEF_TRAVERSE_STMT
argument_list|(
argument|AsTypeExpr
argument_list|,
argument|{}
argument_list|)
comment|// OpenMP directives.
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
name|TraverseOMPExecutableDirective
argument_list|(
argument|OMPExecutableDirective *S
argument_list|)
block|{
for|for
control|(
name|auto
operator|*
name|C
operator|:
name|S
operator|->
name|clauses
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseOMPClause
argument_list|(
name|C
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
name|TraverseOMPLoopDirective
argument_list|(
argument|OMPLoopDirective *S
argument_list|)
block|{
return|return
name|TraverseOMPExecutableDirective
argument_list|(
name|S
argument_list|)
return|;
block|}
end_expr_stmt

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPParallelDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPSimdDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPForDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPForSimdDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPSectionsDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPSectionDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPSingleDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPMasterDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPCriticalDirective
argument_list|,
argument|{   TRY_TO(TraverseDeclarationNameInfo(S->getDirectiveName()));   TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPParallelForDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPParallelForSimdDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPParallelSectionsDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTaskDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTaskyieldDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPBarrierDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTaskwaitDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTaskgroupDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPCancellationPointDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPCancelDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPFlushDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPOrderedDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPAtomicDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetDataDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetEnterDataDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetExitDataDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetParallelDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetParallelForDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTeamsDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetUpdateDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTaskLoopDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTaskLoopSimdDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPDistributeDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPDistributeParallelForDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPDistributeParallelForSimdDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPDistributeSimdDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetParallelForSimdDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetSimdDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTeamsDistributeDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTeamsDistributeSimdDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTeamsDistributeParallelForSimdDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTeamsDistributeParallelForDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetTeamsDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetTeamsDistributeDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetTeamsDistributeParallelForDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetTeamsDistributeParallelForSimdDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_macro
name|DEF_TRAVERSE_STMT
argument_list|(
argument|OMPTargetTeamsDistributeSimdDirective
argument_list|,
argument|{ TRY_TO(TraverseOMPExecutableDirective(S)); }
argument_list|)
end_macro

begin_comment
comment|// OpenMP clauses.
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
value|case OMPC_##Name:                                                            \     TRY_TO(Visit##Class(static_cast<Class *>(C)));                             \     break;
include|#
directive|include
file|"clang/Basic/OpenMPKinds.def"
case|case
name|OMPC_threadprivate
case|:
case|case
name|OMPC_uniform
case|:
case|case
name|OMPC_unknown
case|:
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
name|VisitOMPClauseWithPreInit
argument_list|(
argument|OMPClauseWithPreInit *Node
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|Node
operator|->
name|getPreInitStmt
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
name|VisitOMPClauseWithPostUpdate
argument_list|(
argument|OMPClauseWithPostUpdate *Node
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseWithPreInit
argument_list|(
name|Node
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|Node
operator|->
name|getPostUpdateExpr
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
name|VisitOMPIfClause
argument_list|(
argument|OMPIfClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseWithPreInit
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getCondition
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
name|VisitOMPFinalClause
argument_list|(
argument|OMPFinalClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getCondition
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
name|VisitOMPNumThreadsClause
argument_list|(
argument|OMPNumThreadsClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseWithPreInit
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getNumThreads
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
name|VisitOMPSafelenClause
argument_list|(
argument|OMPSafelenClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getSafelen
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
name|VisitOMPSimdlenClause
argument_list|(
argument|OMPSimdlenClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getSimdlen
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
name|VisitOMPCollapseClause
argument_list|(
argument|OMPCollapseClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getNumForLoops
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
name|VisitOMPDefaultClause
argument_list|(
argument|OMPDefaultClause *
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPProcBindClause
argument_list|(
argument|OMPProcBindClause *
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPScheduleClause
argument_list|(
argument|OMPScheduleClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseWithPreInit
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getChunkSize
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
name|VisitOMPOrderedClause
argument_list|(
argument|OMPOrderedClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getNumForLoops
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
name|VisitOMPNowaitClause
argument_list|(
argument|OMPNowaitClause *
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPUntiedClause
argument_list|(
argument|OMPUntiedClause *
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPMergeableClause
argument_list|(
argument|OMPMergeableClause *
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPReadClause
argument_list|(
argument|OMPReadClause *
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPWriteClause
argument_list|(
argument|OMPWriteClause *
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPUpdateClause
argument_list|(
argument|OMPUpdateClause *
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPCaptureClause
argument_list|(
argument|OMPCaptureClause *
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPSeqCstClause
argument_list|(
argument|OMPSeqCstClause *
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPThreadsClause
argument_list|(
argument|OMPThreadsClause *
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPSIMDClause
argument_list|(
argument|OMPSIMDClause *
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPNogroupClause
argument_list|(
argument|OMPNogroupClause *
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
name|bool
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
name|auto
operator|*
name|E
operator|:
name|Node
operator|->
name|varlists
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
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
name|VisitOMPPrivateClause
argument_list|(
argument|OMPPrivateClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|private_copies
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
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
name|VisitOMPFirstprivateClause
argument_list|(
argument|OMPFirstprivateClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|VisitOMPClauseWithPreInit
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|private_copies
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|inits
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
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
name|VisitOMPLastprivateClause
argument_list|(
argument|OMPLastprivateClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|VisitOMPClauseWithPostUpdate
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|private_copies
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|source_exprs
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|destination_exprs
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|assignment_ops
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
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
name|VisitOMPSharedClause
argument_list|(
argument|OMPSharedClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
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
name|VisitOMPLinearClause
argument_list|(
argument|OMPLinearClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getStep
argument_list|()
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getCalcStep
argument_list|()
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|VisitOMPClauseWithPostUpdate
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|privates
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|inits
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|updates
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|finals
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
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
name|VisitOMPAlignedClause
argument_list|(
argument|OMPAlignedClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getAlignment
argument_list|()
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
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
name|VisitOMPCopyinClause
argument_list|(
argument|OMPCopyinClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|source_exprs
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|destination_exprs
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|assignment_ops
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
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
name|VisitOMPCopyprivateClause
argument_list|(
argument|OMPCopyprivateClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|source_exprs
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|destination_exprs
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|assignment_ops
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
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
name|VisitOMPReductionClause
argument_list|(
argument|OMPReductionClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseNestedNameSpecifierLoc
argument_list|(
name|C
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
name|C
operator|->
name|getNameInfo
argument_list|()
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|VisitOMPClauseWithPostUpdate
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|privates
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|lhs_exprs
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|rhs_exprs
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_for

begin_for
for|for
control|(
name|auto
operator|*
name|E
operator|:
name|C
operator|->
name|reduction_ops
argument_list|()
control|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|E
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
name|VisitOMPFlushClause
argument_list|(
argument|OMPFlushClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
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
name|VisitOMPDependClause
argument_list|(
argument|OMPDependClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
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
name|VisitOMPDeviceClause
argument_list|(
argument|OMPDeviceClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getDevice
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
name|VisitOMPMapClause
argument_list|(
argument|OMPMapClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
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
name|VisitOMPNumTeamsClause
argument_list|(
argument|OMPNumTeamsClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseWithPreInit
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getNumTeams
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
name|VisitOMPThreadLimitClause
argument_list|(
argument|OMPThreadLimitClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseWithPreInit
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getThreadLimit
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
name|VisitOMPPriorityClause
argument_list|(
argument|OMPPriorityClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getPriority
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
name|VisitOMPGrainsizeClause
argument_list|(
argument|OMPGrainsizeClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getGrainsize
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
name|VisitOMPNumTasksClause
argument_list|(
argument|OMPNumTasksClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getNumTasks
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
name|VisitOMPHintClause
argument_list|(
argument|OMPHintClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getHint
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
name|VisitOMPDistScheduleClause
argument_list|(
argument|OMPDistScheduleClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseWithPreInit
argument_list|(
name|C
argument_list|)
argument_list|)
block|;
name|TRY_TO
argument_list|(
name|TraverseStmt
argument_list|(
name|C
operator|->
name|getChunkSize
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
name|VisitOMPDefaultmapClause
argument_list|(
argument|OMPDefaultmapClause *C
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
name|bool
name|RecursiveASTVisitor
operator|<
name|Derived
operator|>
operator|::
name|VisitOMPToClause
argument_list|(
argument|OMPToClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
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
name|VisitOMPFromClause
argument_list|(
argument|OMPFromClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
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
name|VisitOMPUseDevicePtrClause
argument_list|(
argument|OMPUseDevicePtrClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
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
name|VisitOMPIsDevicePtrClause
argument_list|(
argument|OMPIsDevicePtrClause *C
argument_list|)
block|{
name|TRY_TO
argument_list|(
name|VisitOMPClauseList
argument_list|(
name|C
argument_list|)
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
name|TRAVERSE_STMT
end_undef

begin_undef
undef|#
directive|undef
name|TRAVERSE_STMT_BASE
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

