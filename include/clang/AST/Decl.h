begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Decl.h - Classes for representing declarations ---------*- C++ -*-===//
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
comment|//  This file defines the Decl subclasses.
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
name|LLVM_CLANG_AST_DECL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_DECL_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/APValue.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclBase.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ExternalASTSource.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Expr
decl_stmt|;
name|class
name|FunctionTemplateDecl
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|CompoundStmt
decl_stmt|;
name|class
name|StringLiteral
decl_stmt|;
comment|/// TranslationUnitDecl - The top declaration context.
name|class
name|TranslationUnitDecl
range|:
name|public
name|Decl
decl_stmt|,
name|public
name|DeclContext
block|{
name|TranslationUnitDecl
argument_list|()
operator|:
name|Decl
argument_list|(
name|TranslationUnit
argument_list|,
literal|0
argument_list|,
name|SourceLocation
argument_list|()
argument_list|)
operator|,
name|DeclContext
argument_list|(
argument|TranslationUnit
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|TranslationUnitDecl
operator|*
name|Create
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
expr_stmt|;
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|TranslationUnit
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|TranslationUnitDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|DeclContext
modifier|*
name|castToDeclContext
parameter_list|(
specifier|const
name|TranslationUnitDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|TranslationUnitDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|TranslationUnitDecl
modifier|*
name|castFromDeclContext
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|TranslationUnitDecl
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|DC
operator|)
operator|)
return|;
block|}
block|}
empty_stmt|;
comment|/// NamedDecl - This represents a decl with a name.  Many decls have names such
comment|/// as ObjCMethodDecl, but not @class, etc.
name|class
name|NamedDecl
range|:
name|public
name|Decl
block|{
comment|/// Name - The name of this declaration, which is typically a normal
comment|/// identifier but may also be a special kind of name (C++
comment|/// constructor, Objective-C selector, etc.)
name|DeclarationName
name|Name
block|;
name|protected
operator|:
name|NamedDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|)
operator|:
name|Decl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|)
block|,
name|Name
argument_list|(
argument|N
argument_list|)
block|{ }
name|public
operator|:
comment|/// getIdentifier - Get the identifier that names this declaration,
comment|/// if there is one. This will return NULL if this declaration has
comment|/// no name (e.g., for an unnamed class) or if the name is a special
comment|/// name (C++ constructor, Objective-C selector, etc.).
name|IdentifierInfo
operator|*
name|getIdentifier
argument_list|()
specifier|const
block|{
return|return
name|Name
operator|.
name|getAsIdentifierInfo
argument_list|()
return|;
block|}
comment|/// getNameAsCString - Get the name of identifier for this declaration as a
comment|/// C string (const char*).  This requires that the declaration have a name
comment|/// and that it be a simple identifier.
specifier|const
name|char
operator|*
name|getNameAsCString
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|getIdentifier
argument_list|()
operator|&&
literal|"Name is not a simple identifier"
argument_list|)
block|;
return|return
name|getIdentifier
argument_list|()
operator|->
name|getName
argument_list|()
return|;
block|}
comment|/// getDeclName - Get the actual, stored name of the declaration,
comment|/// which may be a special name.
name|DeclarationName
name|getDeclName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
comment|/// \brief Set the name of this declaration.
name|void
name|setDeclName
argument_list|(
argument|DeclarationName N
argument_list|)
block|{
name|Name
operator|=
name|N
block|; }
comment|/// getNameAsString - Get a human-readable name for the declaration, even if
comment|/// it is one of the special kinds of names (C++ constructor, Objective-C
comment|/// selector, etc).  Creating this name requires expensive string
comment|/// manipulation, so it should be called only when performance doesn't matter.
comment|/// For simple declarations, getNameAsCString() should suffice.
name|std
operator|::
name|string
name|getNameAsString
argument_list|()
specifier|const
block|{
return|return
name|Name
operator|.
name|getAsString
argument_list|()
return|;
block|}
comment|/// getQualifiedNameAsString - Returns human-readable qualified name for
comment|/// declaration, like A::B::i, for i being member of namespace A::B.
comment|/// If declaration is not member of context which can be named (record,
comment|/// namespace), it will return same result as getNameAsString().
comment|/// Creating this name is expensive, so it should be called only when
comment|/// performance doesn't matter.
name|std
operator|::
name|string
name|getQualifiedNameAsString
argument_list|()
specifier|const
block|;
comment|/// declarationReplaces - Determine whether this declaration, if
comment|/// known to be well-formed within its context, will replace the
comment|/// declaration OldD if introduced into scope. A declaration will
comment|/// replace another declaration if, for example, it is a
comment|/// redeclaration of the same variable or function, but not if it is
comment|/// a declaration of a different kind (function vs. class) or an
comment|/// overloaded function.
name|bool
name|declarationReplaces
argument_list|(
argument|NamedDecl *OldD
argument_list|)
specifier|const
block|;
comment|/// \brief Determine whether this declaration has linkage.
name|bool
name|hasLinkage
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|>=
name|NamedFirst
operator|&&
name|D
operator|->
name|getKind
argument_list|()
operator|<=
name|NamedLast
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const NamedDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// NamespaceDecl - Represent a C++ namespace.
name|class
name|NamespaceDecl
operator|:
name|public
name|NamedDecl
block|,
name|public
name|DeclContext
block|{
name|SourceLocation
name|LBracLoc
block|,
name|RBracLoc
block|;
comment|// For extended namespace definitions:
comment|//
comment|// namespace A { int x; }
comment|// namespace A { int y; }
comment|//
comment|// there will be one NamespaceDecl for each declaration.
comment|// NextNamespace points to the next extended declaration.
comment|// OrigNamespace points to the original namespace declaration.
comment|// OrigNamespace of the first namespace decl points to itself.
name|NamespaceDecl
operator|*
name|OrigNamespace
block|,
operator|*
name|NextNamespace
block|;
name|NamespaceDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|Namespace
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|DeclContext
argument_list|(
argument|Namespace
argument_list|)
block|{
name|OrigNamespace
operator|=
name|this
block|;
name|NextNamespace
operator|=
literal|0
block|;   }
name|public
operator|:
specifier|static
name|NamespaceDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
block|;
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|NamespaceDecl
operator|*
name|getNextNamespace
argument_list|()
block|{
return|return
name|NextNamespace
return|;
block|}
specifier|const
name|NamespaceDecl
operator|*
name|getNextNamespace
argument_list|()
specifier|const
block|{
return|return
name|NextNamespace
return|;
block|}
name|void
name|setNextNamespace
argument_list|(
argument|NamespaceDecl *ND
argument_list|)
block|{
name|NextNamespace
operator|=
name|ND
block|; }
name|NamespaceDecl
operator|*
name|getOriginalNamespace
argument_list|()
specifier|const
block|{
return|return
name|OrigNamespace
return|;
block|}
name|void
name|setOriginalNamespace
argument_list|(
argument|NamespaceDecl *ND
argument_list|)
block|{
name|OrigNamespace
operator|=
name|ND
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|getLocation
argument_list|()
argument_list|,
name|RBracLoc
argument_list|)
return|;
block|}
name|SourceLocation
name|getLBracLoc
argument_list|()
specifier|const
block|{
return|return
name|LBracLoc
return|;
block|}
name|SourceLocation
name|getRBracLoc
argument_list|()
specifier|const
block|{
return|return
name|RBracLoc
return|;
block|}
name|void
name|setLBracLoc
argument_list|(
argument|SourceLocation LBrace
argument_list|)
block|{
name|LBracLoc
operator|=
name|LBrace
block|; }
name|void
name|setRBracLoc
argument_list|(
argument|SourceLocation RBrace
argument_list|)
block|{
name|RBracLoc
operator|=
name|RBrace
block|; }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|Namespace
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const NamespaceDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|DeclContext
operator|*
name|castToDeclContext
argument_list|(
argument|const NamespaceDecl *D
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|NamespaceDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|NamespaceDecl
operator|*
name|castFromDeclContext
argument_list|(
argument|const DeclContext *DC
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|NamespaceDecl
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|DC
operator|)
operator|)
return|;
block|}
expr|}
block|;
comment|/// ValueDecl - Represent the declaration of a variable (in which case it is
comment|/// an lvalue) a function (in which case it is a function designator) or
comment|/// an enum constant.
name|class
name|ValueDecl
operator|:
name|public
name|NamedDecl
block|{
name|QualType
name|DeclType
block|;
name|protected
operator|:
name|ValueDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|N
argument_list|)
block|,
name|DeclType
argument_list|(
argument|T
argument_list|)
block|{}
name|public
operator|:
name|QualType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|DeclType
return|;
block|}
name|void
name|setType
argument_list|(
argument|QualType newType
argument_list|)
block|{
name|DeclType
operator|=
name|newType
block|; }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|>=
name|ValueFirst
operator|&&
name|D
operator|->
name|getKind
argument_list|()
operator|<=
name|ValueLast
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ValueDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// \brief Structure used to store a statement, the constant value to
comment|/// which it was evaluated (if any), and whether or not the statement
comment|/// is an integral constant expression (if known).
block|struct
name|EvaluatedStmt
block|{
name|EvaluatedStmt
argument_list|()
operator|:
name|WasEvaluated
argument_list|(
name|false
argument_list|)
block|,
name|CheckedICE
argument_list|(
name|false
argument_list|)
block|,
name|IsICE
argument_list|(
argument|false
argument_list|)
block|{ }
comment|/// \brief Whether this statement was already evaluated.
name|bool
name|WasEvaluated
operator|:
literal|1
block|;
comment|/// \brief Whether we already checked whether this statement was an
comment|/// integral constant expression.
name|bool
name|CheckedICE
operator|:
literal|1
block|;
comment|/// \brief Whether this statement is an integral constant
comment|/// expression. Only valid if CheckedICE is true.
name|bool
name|IsICE
operator|:
literal|1
block|;
name|Stmt
operator|*
name|Value
block|;
name|APValue
name|Evaluated
block|; }
block|;
comment|/// VarDecl - An instance of this class is created to represent a variable
comment|/// declaration or definition.
name|class
name|VarDecl
operator|:
name|public
name|ValueDecl
block|{
name|public
operator|:
expr|enum
name|StorageClass
block|{
name|None
block|,
name|Auto
block|,
name|Register
block|,
name|Extern
block|,
name|Static
block|,
name|PrivateExtern
block|}
block|;
comment|/// getStorageClassSpecifierString - Return the string used to
comment|/// specify the storage class \arg SC.
comment|///
comment|/// It is illegal to call this function with SC == None.
specifier|static
specifier|const
name|char
operator|*
name|getStorageClassSpecifierString
argument_list|(
argument|StorageClass SC
argument_list|)
block|;
name|private
operator|:
name|mutable
name|llvm
operator|::
name|PointerUnion
operator|<
name|Stmt
operator|*
block|,
name|EvaluatedStmt
operator|*
operator|>
name|Init
block|;
comment|// FIXME: This can be packed into the bitfields in Decl.
name|unsigned
name|SClass
operator|:
literal|3
block|;
name|bool
name|ThreadSpecified
operator|:
literal|1
block|;
name|bool
name|HasCXXDirectInit
operator|:
literal|1
block|;
comment|/// DeclaredInCondition - Whether this variable was declared in a
comment|/// condition, e.g., if (int x = foo()) { ... }.
name|bool
name|DeclaredInCondition
operator|:
literal|1
block|;
comment|/// \brief The previous declaration of this variable.
name|VarDecl
operator|*
name|PreviousDeclaration
block|;
comment|// Move to DeclGroup when it is implemented.
name|SourceLocation
name|TypeSpecStartLoc
block|;
name|friend
name|class
name|StmtIteratorBase
block|;
name|protected
operator|:
name|VarDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|StorageClass SC
argument_list|,
argument|SourceLocation TSSL = SourceLocation()
argument_list|)
operator|:
name|ValueDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|T
argument_list|)
block|,
name|Init
argument_list|()
block|,
name|ThreadSpecified
argument_list|(
name|false
argument_list|)
block|,
name|HasCXXDirectInit
argument_list|(
name|false
argument_list|)
block|,
name|DeclaredInCondition
argument_list|(
name|false
argument_list|)
block|,
name|PreviousDeclaration
argument_list|(
literal|0
argument_list|)
block|,
name|TypeSpecStartLoc
argument_list|(
argument|TSSL
argument_list|)
block|{
name|SClass
operator|=
name|SC
block|;    }
name|public
operator|:
specifier|static
name|VarDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|StorageClass S
argument_list|,
argument|SourceLocation TypeSpecStartLoc = SourceLocation()
argument_list|)
block|;
name|virtual
operator|~
name|VarDecl
argument_list|()
block|;
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|StorageClass
name|getStorageClass
argument_list|()
specifier|const
block|{
return|return
operator|(
name|StorageClass
operator|)
name|SClass
return|;
block|}
name|void
name|setStorageClass
argument_list|(
argument|StorageClass SC
argument_list|)
block|{
name|SClass
operator|=
name|SC
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|;
name|SourceLocation
name|getTypeSpecStartLoc
argument_list|()
specifier|const
block|{
return|return
name|TypeSpecStartLoc
return|;
block|}
name|void
name|setTypeSpecStartLoc
argument_list|(
argument|SourceLocation SL
argument_list|)
block|{
name|TypeSpecStartLoc
operator|=
name|SL
block|;   }
specifier|const
name|Expr
operator|*
name|getInit
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Init
operator|.
name|isNull
argument_list|()
condition|)
return|return
literal|0
return|;
specifier|const
name|Stmt
operator|*
name|S
operator|=
name|Init
operator|.
name|dyn_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
block|;
if|if
condition|(
operator|!
name|S
condition|)
name|S
operator|=
name|Init
operator|.
name|get
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
operator|->
name|Value
expr_stmt|;
return|return
operator|(
specifier|const
name|Expr
operator|*
operator|)
name|S
return|;
block|}
name|Expr
operator|*
name|getInit
argument_list|()
block|{
if|if
condition|(
name|Init
operator|.
name|isNull
argument_list|()
condition|)
return|return
literal|0
return|;
name|Stmt
operator|*
name|S
operator|=
name|Init
operator|.
name|dyn_cast
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
block|;
if|if
condition|(
operator|!
name|S
condition|)
name|S
operator|=
name|Init
operator|.
name|get
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
operator|->
name|Value
expr_stmt|;
return|return
operator|(
name|Expr
operator|*
operator|)
name|S
return|;
block|}
comment|/// \brief Retrieve the address of the initializer expression.
name|Stmt
modifier|*
modifier|*
name|getInitAddress
parameter_list|()
block|{
if|if
condition|(
name|Init
operator|.
name|is
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|reinterpret_cast
operator|<
name|Stmt
operator|*
operator|*
operator|>
operator|(
operator|&
name|Init
operator|)
return|;
comment|// FIXME: ugly hack
return|return
operator|&
name|Init
operator|.
name|get
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
operator|->
name|Value
return|;
block|}
name|void
name|setInit
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|Expr
modifier|*
name|I
parameter_list|)
function_decl|;
comment|/// \brief Note that constant evaluation has computed the given
comment|/// value for this variable's initializer.
name|void
name|setEvaluatedValue
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|,
specifier|const
name|APValue
operator|&
name|Value
argument_list|)
decl|const
block|{
name|EvaluatedStmt
modifier|*
name|Eval
init|=
name|Init
operator|.
name|dyn_cast
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|Eval
condition|)
block|{
name|Stmt
modifier|*
name|S
init|=
name|Init
operator|.
name|get
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
decl_stmt|;
name|Eval
operator|=
name|new
argument_list|(
argument|C
argument_list|)
name|EvaluatedStmt
expr_stmt|;
name|Eval
operator|->
name|Value
operator|=
name|S
expr_stmt|;
name|Init
operator|=
name|Eval
expr_stmt|;
block|}
name|Eval
operator|->
name|WasEvaluated
operator|=
name|true
expr_stmt|;
name|Eval
operator|->
name|Evaluated
operator|=
name|Value
expr_stmt|;
block|}
comment|/// \brief Return the already-evaluated value of this variable's
comment|/// initializer, or NULL if the value is not yet known.
name|APValue
operator|*
name|getEvaluatedValue
argument_list|()
specifier|const
block|{
if|if
condition|(
name|EvaluatedStmt
modifier|*
name|Eval
init|=
name|Init
operator|.
name|dyn_cast
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
condition|)
if|if
condition|(
name|Eval
operator|->
name|WasEvaluated
condition|)
return|return
operator|&
name|Eval
operator|->
name|Evaluated
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Determines whether it is already known whether the
end_comment

begin_comment
comment|/// initializer is an integral constant expression or not.
end_comment

begin_expr_stmt
name|bool
name|isInitKnownICE
argument_list|()
specifier|const
block|{
if|if
condition|(
name|EvaluatedStmt
modifier|*
name|Eval
init|=
name|Init
operator|.
name|dyn_cast
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
condition|)
return|return
name|Eval
operator|->
name|CheckedICE
return|;
end_expr_stmt

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// \brief Determines whether the initializer is an integral
end_comment

begin_comment
comment|/// constant expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre isInitKnownICE()
end_comment

begin_macro
unit|bool
name|isInitICE
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
name|assert
argument_list|(
name|isInitKnownICE
argument_list|()
operator|&&
literal|"Check whether we already know that the initializer is an ICE"
argument_list|)
block|;
return|return
name|Init
operator|.
name|get
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
operator|->
name|IsICE
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Note that we now know whether the initializer is an
end_comment

begin_comment
comment|/// integral constant expression.
end_comment

begin_decl_stmt
name|void
name|setInitKnownICE
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|,
name|bool
name|IsICE
argument_list|)
decl|const
block|{
name|EvaluatedStmt
modifier|*
name|Eval
init|=
name|Init
operator|.
name|dyn_cast
operator|<
name|EvaluatedStmt
operator|*
operator|>
operator|(
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|Eval
condition|)
block|{
name|Stmt
modifier|*
name|S
init|=
name|Init
operator|.
name|get
operator|<
name|Stmt
operator|*
operator|>
operator|(
operator|)
decl_stmt|;
name|Eval
operator|=
name|new
argument_list|(
argument|C
argument_list|)
name|EvaluatedStmt
expr_stmt|;
name|Eval
operator|->
name|Value
operator|=
name|S
expr_stmt|;
name|Init
operator|=
name|Eval
expr_stmt|;
block|}
name|Eval
operator|->
name|CheckedICE
operator|=
name|true
expr_stmt|;
name|Eval
operator|->
name|IsICE
operator|=
name|IsICE
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Retrieve the definition of this variable, which may come
end_comment

begin_comment
comment|/// from a previous declaration. Def will be set to the VarDecl that
end_comment

begin_comment
comment|/// contains the initializer, and the result will be that
end_comment

begin_comment
comment|/// initializer.
end_comment

begin_decl_stmt
specifier|const
name|Expr
modifier|*
name|getDefinition
argument_list|(
specifier|const
name|VarDecl
operator|*
operator|&
name|Def
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|setThreadSpecified
parameter_list|(
name|bool
name|T
parameter_list|)
block|{
name|ThreadSpecified
operator|=
name|T
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|isThreadSpecified
argument_list|()
specifier|const
block|{
return|return
name|ThreadSpecified
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setCXXDirectInitializer
parameter_list|(
name|bool
name|T
parameter_list|)
block|{
name|HasCXXDirectInit
operator|=
name|T
expr_stmt|;
block|}
end_function

begin_comment
comment|/// hasCXXDirectInitializer - If true, the initializer was a direct
end_comment

begin_comment
comment|/// initializer, e.g: "int x(1);". The Init expression will be the expression
end_comment

begin_comment
comment|/// inside the parens or a "ClassType(a,b,c)" class constructor expression for
end_comment

begin_comment
comment|/// class types. Clients can distinguish between "int x(1);" and "int x=1;"
end_comment

begin_comment
comment|/// by checking hasCXXDirectInitializer.
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|bool
name|hasCXXDirectInitializer
argument_list|()
specifier|const
block|{
return|return
name|HasCXXDirectInit
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isDeclaredInCondition - Whether this variable was declared as
end_comment

begin_comment
comment|/// part of a condition in an if/switch/while statement, e.g.,
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// if (int x = foo()) { ... }
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_expr_stmt
name|bool
name|isDeclaredInCondition
argument_list|()
specifier|const
block|{
return|return
name|DeclaredInCondition
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDeclaredInCondition
parameter_list|(
name|bool
name|InCondition
parameter_list|)
block|{
name|DeclaredInCondition
operator|=
name|InCondition
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getPreviousDeclaration - Return the previous declaration of this
end_comment

begin_comment
comment|/// variable.
end_comment

begin_expr_stmt
specifier|const
name|VarDecl
operator|*
name|getPreviousDeclaration
argument_list|()
specifier|const
block|{
return|return
name|PreviousDeclaration
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setPreviousDeclaration
parameter_list|(
name|VarDecl
modifier|*
name|PrevDecl
parameter_list|)
block|{
name|PreviousDeclaration
operator|=
name|PrevDecl
expr_stmt|;
block|}
end_function

begin_comment
comment|/// hasLocalStorage - Returns true if a variable with function scope
end_comment

begin_comment
comment|///  is a non-static local variable.
end_comment

begin_expr_stmt
name|bool
name|hasLocalStorage
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getStorageClass
argument_list|()
operator|==
name|None
condition|)
return|return
operator|!
name|isFileVarDecl
argument_list|()
return|;
end_expr_stmt

begin_comment
comment|// Return true for:  Auto, Register.
end_comment

begin_comment
comment|// Return false for: Extern, Static, PrivateExtern.
end_comment

begin_return
return|return
name|getStorageClass
argument_list|()
operator|<=
name|Register
return|;
end_return

begin_comment
unit|}
comment|/// hasExternStorage - Returns true if a variable has extern or
end_comment

begin_comment
comment|/// __private_extern__ storage.
end_comment

begin_macro
unit|bool
name|hasExternalStorage
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|getStorageClass
argument_list|()
operator|==
name|Extern
operator|||
name|getStorageClass
argument_list|()
operator|==
name|PrivateExtern
return|;
block|}
end_expr_stmt

begin_comment
comment|/// hasGlobalStorage - Returns true for all variables that do not
end_comment

begin_comment
comment|///  have local storage.  This includs all global variables as well
end_comment

begin_comment
comment|///  as static variables declared within a function.
end_comment

begin_expr_stmt
name|bool
name|hasGlobalStorage
argument_list|()
specifier|const
block|{
return|return
operator|!
name|hasLocalStorage
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isBlockVarDecl - Returns true for local variable declarations.  Note that
end_comment

begin_comment
comment|/// this includes static variables inside of functions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   void foo() { int x; static int y; extern int z; }
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|bool
name|isBlockVarDecl
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getKind
argument_list|()
operator|!=
name|Decl
operator|::
name|Var
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_if
if|if
condition|(
specifier|const
name|DeclContext
modifier|*
name|DC
init|=
name|getDeclContext
argument_list|()
condition|)
return|return
name|DC
operator|->
name|getLookupContext
argument_list|()
operator|->
name|isFunctionOrMethod
argument_list|()
return|;
end_if

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// \brief Determines whether this is a static data member.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This will only be true in C++, and applies to, e.g., the
end_comment

begin_comment
comment|/// variable 'x' in:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// struct S {
end_comment

begin_comment
comment|///   static int x;
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_macro
unit|bool
name|isStaticDataMember
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|getDeclContext
argument_list|()
operator|->
name|isRecord
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isFileVarDecl - Returns true for file scoped variable declaration.
end_comment

begin_expr_stmt
name|bool
name|isFileVarDecl
argument_list|()
specifier|const
block|{
if|if
condition|(
name|getKind
argument_list|()
operator|!=
name|Decl
operator|::
name|Var
condition|)
return|return
name|false
return|;
end_expr_stmt

begin_if
if|if
condition|(
specifier|const
name|DeclContext
modifier|*
name|Ctx
init|=
name|getDeclContext
argument_list|()
condition|)
block|{
name|Ctx
operator|=
name|Ctx
operator|->
name|getLookupContext
argument_list|()
expr_stmt|;
if|if
condition|(
name|isa
operator|<
name|TranslationUnitDecl
operator|>
operator|(
name|Ctx
operator|)
operator|||
name|isa
operator|<
name|NamespaceDecl
operator|>
operator|(
name|Ctx
operator|)
condition|)
return|return
name|true
return|;
block|}
end_if

begin_return
return|return
name|false
return|;
end_return

begin_comment
unit|}
comment|/// \brief Determine whether this is a tentative definition of a
end_comment

begin_comment
comment|/// variable in C.
end_comment

begin_macro
unit|bool
name|isTentativeDefinition
argument_list|(
argument|ASTContext&Context
argument_list|)
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Determines whether this variable is a variable with
end_comment

begin_comment
comment|/// external, C linkage.
end_comment

begin_decl_stmt
name|bool
name|isExternC
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Implement isa/cast/dyncast/etc.
end_comment

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|>=
name|VarFirst
operator|&&
name|D
operator|->
name|getKind
argument_list|()
operator|<=
name|VarLast
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_decl_stmt
unit|};
name|class
name|ImplicitParamDecl
range|:
name|public
name|VarDecl
block|{
name|protected
operator|:
name|ImplicitParamDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType Tw
argument_list|)
operator|:
name|VarDecl
argument_list|(
argument|DK
argument_list|,
argument|DC
argument_list|,
argument|L
argument_list|,
argument|Id
argument_list|,
argument|Tw
argument_list|,
argument|VarDecl::None
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ImplicitParamDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|)
block|;
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const ImplicitParamDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|ImplicitParam
return|;
block|}
expr|}
block|;
comment|/// ParmVarDecl - Represent a parameter to a function.
name|class
name|ParmVarDecl
operator|:
name|public
name|VarDecl
block|{
comment|// NOTE: VC++ treats enums as signed, avoid using the ObjCDeclQualifier enum
comment|/// FIXME: Also can be paced into the bitfields in Decl.
comment|/// in, inout, etc.
name|unsigned
name|objcDeclQualifier
operator|:
literal|6
block|;
comment|/// Default argument, if any.  [C++ Only]
name|Expr
operator|*
name|DefaultArg
block|;
name|protected
operator|:
name|ParmVarDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|StorageClass S
argument_list|,
argument|Expr *DefArg
argument_list|)
operator|:
name|VarDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|T
argument_list|,
name|S
argument_list|)
block|,
name|objcDeclQualifier
argument_list|(
name|OBJC_TQ_None
argument_list|)
block|,
name|DefaultArg
argument_list|(
argument|DefArg
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ParmVarDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|StorageClass S
argument_list|,
argument|Expr *DefArg
argument_list|)
block|;
name|ObjCDeclQualifier
name|getObjCDeclQualifier
argument_list|()
specifier|const
block|{
return|return
name|ObjCDeclQualifier
argument_list|(
name|objcDeclQualifier
argument_list|)
return|;
block|}
name|void
name|setObjCDeclQualifier
argument_list|(
argument|ObjCDeclQualifier QTVal
argument_list|)
block|{
name|objcDeclQualifier
operator|=
name|QTVal
block|;   }
specifier|const
name|Expr
operator|*
name|getDefaultArg
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|hasUnparsedDefaultArg
argument_list|()
operator|&&
literal|"Default argument is not yet parsed!"
argument_list|)
block|;
return|return
name|DefaultArg
return|;
block|}
name|Expr
operator|*
name|getDefaultArg
argument_list|()
block|{
name|assert
argument_list|(
operator|!
name|hasUnparsedDefaultArg
argument_list|()
operator|&&
literal|"Default argument is not yet parsed!"
argument_list|)
block|;
return|return
name|DefaultArg
return|;
block|}
name|void
name|setDefaultArg
argument_list|(
argument|Expr *defarg
argument_list|)
block|{
name|DefaultArg
operator|=
name|defarg
block|; }
comment|/// hasDefaultArg - Determines whether this parameter has a default argument,
comment|/// either parsed or not.
name|bool
name|hasDefaultArg
argument_list|()
specifier|const
block|{
return|return
name|DefaultArg
operator|!=
literal|0
return|;
block|}
comment|/// hasUnparsedDefaultArg - Determines whether this parameter has a
comment|/// default argument that has not yet been parsed. This will occur
comment|/// during the processing of a C++ class whose member functions have
comment|/// default arguments, e.g.,
comment|/// @code
comment|///   class X {
comment|///   public:
comment|///     void f(int x = 17); // x has an unparsed default argument now
comment|///   }; // x has a regular default argument now
comment|/// @endcode
name|bool
name|hasUnparsedDefaultArg
argument_list|()
specifier|const
block|{
return|return
name|DefaultArg
operator|==
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/// setUnparsedDefaultArg - Specify that this parameter has an
comment|/// unparsed default argument. The argument will be replaced with a
comment|/// real default argument via setDefaultArg when the class
comment|/// definition enclosing the function declaration that owns this
comment|/// default argument is completed.
name|void
name|setUnparsedDefaultArg
argument_list|()
block|{
name|DefaultArg
operator|=
name|reinterpret_cast
operator|<
name|Expr
operator|*
operator|>
operator|(
operator|-
literal|1
operator|)
block|; }
name|QualType
name|getOriginalType
argument_list|()
specifier|const
block|;
comment|/// setOwningFunction - Sets the function declaration that owns this
comment|/// ParmVarDecl. Since ParmVarDecls are often created before the
comment|/// FunctionDecls that own them, this routine is required to update
comment|/// the DeclContext appropriately.
name|void
name|setOwningFunction
argument_list|(
argument|DeclContext *FD
argument_list|)
block|{
name|setDeclContext
argument_list|(
name|FD
argument_list|)
block|; }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
operator|(
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|ParmVar
operator|||
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|OriginalParmVar
operator|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ParmVarDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// OriginalParmVarDecl - Represent a parameter to a function, when
comment|/// the type of the parameter has been promoted. This node represents the
comment|/// parameter to the function with its original type.
comment|///
name|class
name|OriginalParmVarDecl
operator|:
name|public
name|ParmVarDecl
block|{
name|friend
name|class
name|ParmVarDecl
block|;
name|protected
operator|:
name|QualType
name|OriginalType
block|;
name|private
operator|:
name|OriginalParmVarDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|QualType OT
argument_list|,
argument|StorageClass S
argument_list|,
argument|Expr *DefArg
argument_list|)
operator|:
name|ParmVarDecl
argument_list|(
name|OriginalParmVar
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|T
argument_list|,
name|S
argument_list|,
name|DefArg
argument_list|)
block|,
name|OriginalType
argument_list|(
argument|OT
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|OriginalParmVarDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|QualType OT
argument_list|,
argument|StorageClass S
argument_list|,
argument|Expr *DefArg
argument_list|)
block|;
name|void
name|setOriginalType
argument_list|(
argument|QualType T
argument_list|)
block|{
name|OriginalType
operator|=
name|T
block|; }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|OriginalParmVar
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const OriginalParmVarDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// FunctionDecl - An instance of this class is created to represent a
comment|/// function declaration or definition.
comment|///
comment|/// Since a given function can be declared several times in a program,
comment|/// there may be several FunctionDecls that correspond to that
comment|/// function. Only one of those FunctionDecls will be found when
comment|/// traversing the list of declarations in the context of the
comment|/// FunctionDecl (e.g., the translation unit); this FunctionDecl
comment|/// contains all of the information known about the function. Other,
comment|/// previous declarations of the function are available via the
comment|/// getPreviousDeclaration() chain.
name|class
name|FunctionDecl
operator|:
name|public
name|ValueDecl
block|,
name|public
name|DeclContext
block|{
name|public
operator|:
expr|enum
name|StorageClass
block|{
name|None
block|,
name|Extern
block|,
name|Static
block|,
name|PrivateExtern
block|}
block|;
name|private
operator|:
comment|/// ParamInfo - new[]'d array of pointers to VarDecls for the formal
comment|/// parameters of this function.  This is null if a prototype or if there are
comment|/// no formals.  TODO: we could allocate this space immediately after the
comment|/// FunctionDecl object to save an allocation like FunctionType does.
name|ParmVarDecl
operator|*
operator|*
name|ParamInfo
block|;
name|LazyDeclStmtPtr
name|Body
block|;
comment|/// PreviousDeclaration - A link to the previous declaration of this
comment|/// same function, NULL if this is the first declaration. For
comment|/// example, in the following code, the PreviousDeclaration can be
comment|/// traversed several times to see all three declarations of the
comment|/// function "f", the last of which is also a definition.
comment|///
comment|///   int f(int x, int y = 1);
comment|///   int f(int x = 0, int y);
comment|///   int f(int x, int y) { return x + y; }
name|FunctionDecl
operator|*
name|PreviousDeclaration
block|;
comment|// FIXME: This can be packed into the bitfields in Decl.
comment|// NOTE: VC++ treats enums as signed, avoid using the StorageClass enum
name|unsigned
name|SClass
operator|:
literal|2
block|;
name|bool
name|IsInline
operator|:
literal|1
block|;
name|bool
name|C99InlineDefinition
operator|:
literal|1
block|;
name|bool
name|IsVirtualAsWritten
operator|:
literal|1
block|;
name|bool
name|IsPure
operator|:
literal|1
block|;
name|bool
name|HasInheritedPrototype
operator|:
literal|1
block|;
name|bool
name|HasWrittenPrototype
operator|:
literal|1
block|;
name|bool
name|IsDeleted
operator|:
literal|1
block|;
comment|// Move to DeclGroup when it is implemented.
name|SourceLocation
name|TypeSpecStartLoc
block|;
name|SourceLocation
name|EndRangeLoc
block|;
comment|/// \brief The template or declaration that this declaration
comment|/// describes or was instantiated from, respectively.
comment|///
comment|/// For non-templates, this value will be NULL. For function
comment|/// declarations that describe a function template, this will be a
comment|/// pointer to a FunctionTemplateDecl. For member functions
comment|/// of class template specializations, this will be the
comment|/// FunctionDecl from which the member function was instantiated.
name|llvm
operator|::
name|PointerUnion
operator|<
name|FunctionTemplateDecl
operator|*
block|,
name|FunctionDecl
operator|*
operator|>
name|TemplateOrInstantiation
block|;
name|protected
operator|:
name|FunctionDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
argument_list|,
argument|StorageClass S
argument_list|,
argument|bool isInline
argument_list|,
argument|SourceLocation TSSL = SourceLocation()
argument_list|)
operator|:
name|ValueDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|N
argument_list|,
name|T
argument_list|)
block|,
name|DeclContext
argument_list|(
name|DK
argument_list|)
block|,
name|ParamInfo
argument_list|(
literal|0
argument_list|)
block|,
name|Body
argument_list|()
block|,
name|PreviousDeclaration
argument_list|(
literal|0
argument_list|)
block|,
name|SClass
argument_list|(
name|S
argument_list|)
block|,
name|IsInline
argument_list|(
name|isInline
argument_list|)
block|,
name|C99InlineDefinition
argument_list|(
name|false
argument_list|)
block|,
name|IsVirtualAsWritten
argument_list|(
name|false
argument_list|)
block|,
name|IsPure
argument_list|(
name|false
argument_list|)
block|,
name|HasInheritedPrototype
argument_list|(
name|false
argument_list|)
block|,
name|HasWrittenPrototype
argument_list|(
name|true
argument_list|)
block|,
name|IsDeleted
argument_list|(
name|false
argument_list|)
block|,
name|TypeSpecStartLoc
argument_list|(
name|TSSL
argument_list|)
block|,
name|EndRangeLoc
argument_list|(
name|L
argument_list|)
block|,
name|TemplateOrInstantiation
argument_list|()
block|{}
name|virtual
operator|~
name|FunctionDecl
argument_list|()
block|{}
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|public
operator|:
specifier|static
name|FunctionDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|DeclarationName N
argument_list|,
argument|QualType T
argument_list|,
argument|StorageClass S = None
argument_list|,
argument|bool isInline = false
argument_list|,
argument|bool hasWrittenPrototype = true
argument_list|,
argument|SourceLocation TSStartLoc = SourceLocation()
argument_list|)
block|;
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|getLocation
argument_list|()
argument_list|,
name|EndRangeLoc
argument_list|)
return|;
block|}
name|void
name|setLocEnd
argument_list|(
argument|SourceLocation E
argument_list|)
block|{
name|assert
argument_list|(
name|getLocation
argument_list|()
operator|<=
name|E
operator|&&
literal|"Invalid end location"
argument_list|)
block|;
name|EndRangeLoc
operator|=
name|E
block|;   }
name|SourceLocation
name|getTypeSpecStartLoc
argument_list|()
specifier|const
block|{
return|return
name|TypeSpecStartLoc
return|;
block|}
name|void
name|setTypeSpecStartLoc
argument_list|(
argument|SourceLocation TS
argument_list|)
block|{
name|TypeSpecStartLoc
operator|=
name|TS
block|; }
comment|/// getBody - Retrieve the body (definition) of the function. The
comment|/// function body might be in any of the (re-)declarations of this
comment|/// function. The variant that accepts a FunctionDecl pointer will
comment|/// set that function declaration to the actual declaration
comment|/// containing the body (if there is one).
name|Stmt
operator|*
name|getBody
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|const FunctionDecl *&Definition
argument_list|)
specifier|const
block|;
name|virtual
name|Stmt
operator|*
name|getBody
argument_list|(
argument|ASTContext&Context
argument_list|)
specifier|const
block|{
specifier|const
name|FunctionDecl
operator|*
name|Definition
block|;
return|return
name|getBody
argument_list|(
name|Context
argument_list|,
name|Definition
argument_list|)
return|;
block|}
comment|/// \brief If the function has a body that is immediately available,
comment|/// return it.
name|Stmt
operator|*
name|getBodyIfAvailable
argument_list|()
specifier|const
block|;
comment|/// isThisDeclarationADefinition - Returns whether this specific
comment|/// declaration of the function is also a definition. This does not
comment|/// determine whether the function has been defined (e.g., in a
comment|/// previous definition); for that information, use getBody.
comment|/// FIXME: Should return true if function is deleted or defaulted. However,
comment|/// CodeGenModule.cpp uses it, and I don't know if this would break it.
name|bool
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|Body
return|;
block|}
name|void
name|setBody
argument_list|(
name|Stmt
operator|*
name|B
argument_list|)
block|;
name|void
name|setLazyBody
argument_list|(
argument|uint64_t Offset
argument_list|)
block|{
name|Body
operator|=
name|Offset
block|; }
comment|/// Whether this function is marked as virtual explicitly.
name|bool
name|isVirtualAsWritten
argument_list|()
specifier|const
block|{
return|return
name|IsVirtualAsWritten
return|;
block|}
name|void
name|setVirtualAsWritten
argument_list|(
argument|bool V
argument_list|)
block|{
name|IsVirtualAsWritten
operator|=
name|V
block|; }
comment|/// Whether this virtual function is pure, i.e. makes the containing class
comment|/// abstract.
name|bool
name|isPure
argument_list|()
specifier|const
block|{
return|return
name|IsPure
return|;
block|}
name|void
name|setPure
argument_list|(
argument|bool P = true
argument_list|)
block|{
name|IsPure
operator|=
name|P
block|; }
comment|/// \brief Whether this function has a prototype, either because one
comment|/// was explicitly written or because it was "inherited" by merging
comment|/// a declaration without a prototype with a declaration that has a
comment|/// prototype.
name|bool
name|hasPrototype
argument_list|()
specifier|const
block|{
return|return
name|HasWrittenPrototype
operator|||
name|HasInheritedPrototype
return|;
block|}
name|bool
name|hasWrittenPrototype
argument_list|()
specifier|const
block|{
return|return
name|HasWrittenPrototype
return|;
block|}
name|void
name|setHasWrittenPrototype
argument_list|(
argument|bool P
argument_list|)
block|{
name|HasWrittenPrototype
operator|=
name|P
block|; }
comment|/// \brief Whether this function inherited its prototype from a
comment|/// previous declaration.
name|bool
name|hasInheritedPrototype
argument_list|()
specifier|const
block|{
return|return
name|HasInheritedPrototype
return|;
block|}
name|void
name|setHasInheritedPrototype
argument_list|(
argument|bool P = true
argument_list|)
block|{
name|HasInheritedPrototype
operator|=
name|P
block|; }
comment|/// \brief Whether this function has been deleted.
comment|///
comment|/// A function that is "deleted" (via the C++0x "= delete" syntax)
comment|/// acts like a normal function, except that it cannot actually be
comment|/// called or have its address taken. Deleted functions are
comment|/// typically used in C++ overload resolution to attract arguments
comment|/// whose type or lvalue/rvalue-ness would permit the use of a
comment|/// different overload that would behave incorrectly. For example,
comment|/// one might use deleted functions to ban implicit conversion from
comment|/// a floating-point number to an Integer type:
comment|///
comment|/// @code
comment|/// struct Integer {
comment|///   Integer(long); // construct from a long
comment|///   Integer(double) = delete; // no construction from float or double
comment|///   Integer(long double) = delete; // no construction from long double
comment|/// };
comment|/// @endcode
name|bool
name|isDeleted
argument_list|()
specifier|const
block|{
return|return
name|IsDeleted
return|;
block|}
name|void
name|setDeleted
argument_list|(
argument|bool D = true
argument_list|)
block|{
name|IsDeleted
operator|=
name|D
block|; }
comment|/// \brief Determines whether this is a function "main", which is
comment|/// the entry point into an executable program.
name|bool
name|isMain
argument_list|()
specifier|const
block|;
comment|/// \brief Determines whether this function is a function with
comment|/// external, C linkage.
name|bool
name|isExternC
argument_list|(
argument|ASTContext&Context
argument_list|)
specifier|const
block|;
comment|/// \brief Determines whether this is a global function.
name|bool
name|isGlobal
argument_list|()
specifier|const
block|;
comment|/// getPreviousDeclaration - Return the previous declaration of this
comment|/// function.
specifier|const
name|FunctionDecl
operator|*
name|getPreviousDeclaration
argument_list|()
specifier|const
block|{
return|return
name|PreviousDeclaration
return|;
block|}
name|void
name|setPreviousDeclaration
argument_list|(
argument|FunctionDecl * PrevDecl
argument_list|)
block|{
name|PreviousDeclaration
operator|=
name|PrevDecl
block|;   }
name|unsigned
name|getBuiltinID
argument_list|(
argument|ASTContext&Context
argument_list|)
specifier|const
block|;
name|unsigned
name|getNumParmVarDeclsFromType
argument_list|()
specifier|const
block|;
comment|// Iterator access to formal parameters.
name|unsigned
name|param_size
argument_list|()
specifier|const
block|{
return|return
name|getNumParams
argument_list|()
return|;
block|}
typedef|typedef
name|ParmVarDecl
modifier|*
modifier|*
name|param_iterator
typedef|;
typedef|typedef
name|ParmVarDecl
modifier|*
specifier|const
modifier|*
name|param_const_iterator
typedef|;
name|param_iterator
name|param_begin
argument_list|()
block|{
return|return
name|ParamInfo
return|;
block|}
name|param_iterator
name|param_end
argument_list|()
block|{
return|return
name|ParamInfo
operator|+
name|param_size
argument_list|()
return|;
block|}
name|param_const_iterator
name|param_begin
argument_list|()
specifier|const
block|{
return|return
name|ParamInfo
return|;
block|}
name|param_const_iterator
name|param_end
argument_list|()
specifier|const
block|{
return|return
name|ParamInfo
operator|+
name|param_size
argument_list|()
return|;
block|}
comment|/// getNumParams - Return the number of parameters this function must have
comment|/// based on its functiontype.  This is the length of the PararmInfo array
comment|/// after it has been created.
name|unsigned
name|getNumParams
argument_list|()
specifier|const
block|;
specifier|const
name|ParmVarDecl
operator|*
name|getParamDecl
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumParams
argument_list|()
operator|&&
literal|"Illegal param #"
argument_list|)
block|;
return|return
name|ParamInfo
index|[
name|i
index|]
return|;
block|}
name|ParmVarDecl
operator|*
name|getParamDecl
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumParams
argument_list|()
operator|&&
literal|"Illegal param #"
argument_list|)
block|;
return|return
name|ParamInfo
index|[
name|i
index|]
return|;
block|}
name|void
name|setParams
argument_list|(
argument|ASTContext& C
argument_list|,
argument|ParmVarDecl **NewParamInfo
argument_list|,
argument|unsigned NumParams
argument_list|)
block|;
comment|/// getMinRequiredArguments - Returns the minimum number of arguments
comment|/// needed to call this function. This may be fewer than the number of
comment|/// function parameters, if some of the parameters have default
comment|/// arguments (in C++).
name|unsigned
name|getMinRequiredArguments
argument_list|()
specifier|const
block|;
name|QualType
name|getResultType
argument_list|()
specifier|const
block|{
return|return
name|getType
argument_list|()
operator|->
name|getAsFunctionType
argument_list|()
operator|->
name|getResultType
argument_list|()
return|;
block|}
name|StorageClass
name|getStorageClass
argument_list|()
specifier|const
block|{
return|return
name|StorageClass
argument_list|(
name|SClass
argument_list|)
return|;
block|}
name|void
name|setStorageClass
argument_list|(
argument|StorageClass SC
argument_list|)
block|{
name|SClass
operator|=
name|SC
block|; }
name|bool
name|isInline
argument_list|()
specifier|const
block|{
return|return
name|IsInline
return|;
block|}
name|void
name|setInline
argument_list|(
argument|bool I
argument_list|)
block|{
name|IsInline
operator|=
name|I
block|; }
comment|/// \brief Whether this function is an "inline definition" as
comment|/// defined by C99.
name|bool
name|isC99InlineDefinition
argument_list|()
specifier|const
block|{
return|return
name|C99InlineDefinition
return|;
block|}
name|void
name|setC99InlineDefinition
argument_list|(
argument|bool I
argument_list|)
block|{
name|C99InlineDefinition
operator|=
name|I
block|; }
comment|/// \brief Determines whether this function has a gnu_inline
comment|/// attribute that affects its semantics.
comment|///
comment|/// The gnu_inline attribute only introduces GNU inline semantics
comment|/// when all of the inline declarations of the function are marked
comment|/// gnu_inline.
name|bool
name|hasActiveGNUInlineAttribute
argument_list|(
argument|ASTContext&Context
argument_list|)
specifier|const
block|;
comment|/// \brief Determines whether this function is a GNU "extern
comment|/// inline", which is roughly the opposite of a C99 "extern inline"
comment|/// function.
name|bool
name|isExternGNUInline
argument_list|(
argument|ASTContext&Context
argument_list|)
specifier|const
block|;
comment|/// isOverloadedOperator - Whether this function declaration
comment|/// represents an C++ overloaded operator, e.g., "operator+".
name|bool
name|isOverloadedOperator
argument_list|()
specifier|const
block|{
return|return
name|getOverloadedOperator
argument_list|()
operator|!=
name|OO_None
return|;
block|}
block|;
name|OverloadedOperatorKind
name|getOverloadedOperator
argument_list|()
specifier|const
block|;
comment|/// \brief If this function is an instantiation of a member function
comment|/// of a class template specialization, retrieves the function from
comment|/// which it was instantiated.
comment|///
comment|/// This routine will return non-NULL for (non-templated) member
comment|/// functions of class templates and for instantiations of function
comment|/// templates. For example, given:
comment|///
comment|/// \code
comment|/// template<typename T>
comment|/// struct X {
comment|///   void f(T);
comment|/// };
comment|/// \endcode
comment|///
comment|/// The declaration for X<int>::f is a (non-templated) FunctionDecl
comment|/// whose parent is the class template specialization X<int>. For
comment|/// this declaration, getInstantiatedFromFunction() will return
comment|/// the FunctionDecl X<T>::A. When a complete definition of
comment|/// X<int>::A is required, it will be instantiated from the
comment|/// declaration returned by getInstantiatedFromMemberFunction().
name|FunctionDecl
operator|*
name|getInstantiatedFromMemberFunction
argument_list|()
specifier|const
block|{
return|return
name|TemplateOrInstantiation
operator|.
name|dyn_cast
operator|<
name|FunctionDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// \brief Specify that this record is an instantiation of the
comment|/// member function RD.
name|void
name|setInstantiationOfMemberFunction
argument_list|(
argument|FunctionDecl *RD
argument_list|)
block|{
name|TemplateOrInstantiation
operator|=
name|RD
block|;   }
comment|/// \brief Retrieves the function template that is described by this
comment|/// function declaration.
comment|///
comment|/// Every function template is represented as a FunctionTemplateDecl
comment|/// and a FunctionDecl (or something derived from FunctionDecl). The
comment|/// former contains template properties (such as the template
comment|/// parameter lists) while the latter contains the actual
comment|/// description of the template's
comment|/// contents. FunctionTemplateDecl::getTemplatedDecl() retrieves the
comment|/// FunctionDecl that describes the function template,
comment|/// getDescribedFunctionTemplate() retrieves the
comment|/// FunctionTemplateDecl from a FunctionDecl.
name|FunctionTemplateDecl
operator|*
name|getDescribedFunctionTemplate
argument_list|()
specifier|const
block|{
return|return
name|TemplateOrInstantiation
operator|.
name|dyn_cast
operator|<
name|FunctionTemplateDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
name|void
name|setDescribedFunctionTemplate
argument_list|(
argument|FunctionTemplateDecl *Template
argument_list|)
block|{
name|TemplateOrInstantiation
operator|=
name|Template
block|;   }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|>=
name|FunctionFirst
operator|&&
name|D
operator|->
name|getKind
argument_list|()
operator|<=
name|FunctionLast
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const FunctionDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|DeclContext
operator|*
name|castToDeclContext
argument_list|(
argument|const FunctionDecl *D
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|FunctionDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|FunctionDecl
operator|*
name|castFromDeclContext
argument_list|(
argument|const DeclContext *DC
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|FunctionDecl
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|DC
operator|)
operator|)
return|;
block|}
expr|}
block|;
comment|/// FieldDecl - An instance of this class is created by Sema::ActOnField to
comment|/// represent a member of a struct/union/class.
name|class
name|FieldDecl
operator|:
name|public
name|ValueDecl
block|{
comment|// FIXME: This can be packed into the bitfields in Decl.
name|bool
name|Mutable
operator|:
literal|1
block|;
name|Expr
operator|*
name|BitWidth
block|;
name|protected
operator|:
name|FieldDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|Expr *BW
argument_list|,
argument|bool Mutable
argument_list|)
operator|:
name|ValueDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|T
argument_list|)
block|,
name|Mutable
argument_list|(
name|Mutable
argument_list|)
block|,
name|BitWidth
argument_list|(
argument|BW
argument_list|)
block|{ }
name|public
operator|:
specifier|static
name|FieldDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|Expr *BW
argument_list|,
argument|bool Mutable
argument_list|)
block|;
comment|/// isMutable - Determines whether this field is mutable (C++ only).
name|bool
name|isMutable
argument_list|()
specifier|const
block|{
return|return
name|Mutable
return|;
block|}
comment|/// \brief Set whether this field is mutable (C++ only).
name|void
name|setMutable
argument_list|(
argument|bool M
argument_list|)
block|{
name|Mutable
operator|=
name|M
block|; }
comment|/// isBitfield - Determines whether this field is a bitfield.
name|bool
name|isBitField
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
operator|!=
name|NULL
return|;
block|}
comment|/// @brief Determines whether this is an unnamed bitfield.
name|bool
name|isUnnamedBitfield
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
operator|!=
name|NULL
operator|&&
operator|!
name|getDeclName
argument_list|()
return|;
block|}
comment|/// isAnonymousStructOrUnion - Determines whether this field is a
comment|/// representative for an anonymous struct or union. Such fields are
comment|/// unnamed and are implicitly generated by the implementation to
comment|/// store the data for the anonymous union or struct.
name|bool
name|isAnonymousStructOrUnion
argument_list|()
specifier|const
block|;
name|Expr
operator|*
name|getBitWidth
argument_list|()
specifier|const
block|{
return|return
name|BitWidth
return|;
block|}
name|void
name|setBitWidth
argument_list|(
argument|Expr *BW
argument_list|)
block|{
name|BitWidth
operator|=
name|BW
block|; }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|>=
name|FieldFirst
operator|&&
name|D
operator|->
name|getKind
argument_list|()
operator|<=
name|FieldLast
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const FieldDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// EnumConstantDecl - An instance of this object exists for each enum constant
comment|/// that is defined.  For example, in "enum X {a,b}", each of a/b are
comment|/// EnumConstantDecl's, X is an instance of EnumDecl, and the type of a/b is a
comment|/// TagType for the X EnumDecl.
name|class
name|EnumConstantDecl
operator|:
name|public
name|ValueDecl
block|{
name|Stmt
operator|*
name|Init
block|;
comment|// an integer constant expression
name|llvm
operator|::
name|APSInt
name|Val
block|;
comment|// The value.
name|protected
operator|:
name|EnumConstantDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|Expr *E
argument_list|,
argument|const llvm::APSInt&V
argument_list|)
operator|:
name|ValueDecl
argument_list|(
name|EnumConstant
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|T
argument_list|)
block|,
name|Init
argument_list|(
operator|(
name|Stmt
operator|*
operator|)
name|E
argument_list|)
block|,
name|Val
argument_list|(
argument|V
argument_list|)
block|{}
name|virtual
operator|~
name|EnumConstantDecl
argument_list|()
block|{}
name|public
operator|:
specifier|static
name|EnumConstantDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|EnumDecl *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|Expr *E
argument_list|,
argument|const llvm::APSInt&V
argument_list|)
block|;
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
specifier|const
name|Expr
operator|*
name|getInitExpr
argument_list|()
specifier|const
block|{
return|return
operator|(
specifier|const
name|Expr
operator|*
operator|)
name|Init
return|;
block|}
name|Expr
operator|*
name|getInitExpr
argument_list|()
block|{
return|return
operator|(
name|Expr
operator|*
operator|)
name|Init
return|;
block|}
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|getInitVal
argument_list|()
specifier|const
block|{
return|return
name|Val
return|;
block|}
name|void
name|setInitExpr
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Init
operator|=
operator|(
name|Stmt
operator|*
operator|)
name|E
block|; }
name|void
name|setInitVal
argument_list|(
argument|const llvm::APSInt&V
argument_list|)
block|{
name|Val
operator|=
name|V
block|; }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|EnumConstant
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const EnumConstantDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|friend
name|class
name|StmtIteratorBase
block|; }
block|;
comment|/// TypeDecl - Represents a declaration of a type.
comment|///
name|class
name|TypeDecl
operator|:
name|public
name|NamedDecl
block|{
comment|/// TypeForDecl - This indicates the Type object that represents
comment|/// this TypeDecl.  It is a cache maintained by
comment|/// ASTContext::getTypedefType, ASTContext::getTagDeclType, and
comment|/// ASTContext::getTemplateTypeParmType, and TemplateTypeParmDecl.
name|mutable
name|Type
operator|*
name|TypeForDecl
block|;
name|friend
name|class
name|ASTContext
block|;
name|friend
name|class
name|DeclContext
block|;
name|friend
name|class
name|TagDecl
block|;
name|friend
name|class
name|TemplateTypeParmDecl
block|;
name|friend
name|class
name|ClassTemplateSpecializationDecl
block|;
name|friend
name|class
name|TagType
block|;
name|protected
operator|:
name|TypeDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|TypeForDecl
argument_list|(
literal|0
argument_list|)
block|{}
name|public
operator|:
comment|// Low-level accessor
name|Type
operator|*
name|getTypeForDecl
argument_list|()
specifier|const
block|{
return|return
name|TypeForDecl
return|;
block|}
name|void
name|setTypeForDecl
argument_list|(
argument|Type *TD
argument_list|)
block|{
name|TypeForDecl
operator|=
name|TD
block|; }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|>=
name|TypeFirst
operator|&&
name|D
operator|->
name|getKind
argument_list|()
operator|<=
name|TypeLast
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const TypeDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|TypedefDecl
operator|:
name|public
name|TypeDecl
block|{
comment|/// UnderlyingType - This is the type the typedef is set to.
name|QualType
name|UnderlyingType
block|;
name|TypedefDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|)
operator|:
name|TypeDecl
argument_list|(
name|Typedef
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|UnderlyingType
argument_list|(
argument|T
argument_list|)
block|{}
name|virtual
operator|~
name|TypedefDecl
argument_list|()
block|{}
name|public
operator|:
specifier|static
name|TypedefDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|)
block|;
name|QualType
name|getUnderlyingType
argument_list|()
specifier|const
block|{
return|return
name|UnderlyingType
return|;
block|}
name|void
name|setUnderlyingType
argument_list|(
argument|QualType newType
argument_list|)
block|{
name|UnderlyingType
operator|=
name|newType
block|; }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|Typedef
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const TypedefDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|TypedefDecl
block|;
comment|/// TagDecl - Represents the declaration of a struct/union/class/enum.
name|class
name|TagDecl
operator|:
name|public
name|TypeDecl
block|,
name|public
name|DeclContext
block|{
name|public
operator|:
expr|enum
name|TagKind
block|{
name|TK_struct
block|,
name|TK_union
block|,
name|TK_class
block|,
name|TK_enum
block|}
block|;
name|private
operator|:
comment|// FIXME: This can be packed into the bitfields in Decl.
comment|/// TagDeclKind - The TagKind enum.
name|unsigned
name|TagDeclKind
operator|:
literal|2
block|;
comment|/// IsDefinition - True if this is a definition ("struct foo {};"), false if
comment|/// it is a declaration ("struct foo;").
name|bool
name|IsDefinition
operator|:
literal|1
block|;
comment|/// TypedefForAnonDecl - If a TagDecl is anonymous and part of a typedef,
comment|/// this points to the TypedefDecl. Used for mangling.
name|TypedefDecl
operator|*
name|TypedefForAnonDecl
block|;
name|protected
operator|:
name|TagDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|TagKind TK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
operator|:
name|TypeDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|DeclContext
argument_list|(
name|DK
argument_list|)
block|,
name|TypedefForAnonDecl
argument_list|(
literal|0
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|DK
operator|!=
name|Enum
operator|||
name|TK
operator|==
name|TK_enum
operator|)
operator|&&
literal|"EnumDecl not matched with TK_enum"
argument_list|)
block|;
name|TagDeclKind
operator|=
name|TK
block|;
name|IsDefinition
operator|=
name|false
block|;   }
name|public
operator|:
comment|/// isDefinition - Return true if this decl has its body specified.
name|bool
name|isDefinition
argument_list|()
specifier|const
block|{
return|return
name|IsDefinition
return|;
block|}
comment|/// \brief Whether this declaration declares a type that is
comment|/// dependent, i.e., a type that somehow depends on template
comment|/// parameters.
name|bool
name|isDependentType
argument_list|()
specifier|const
block|{
return|return
name|isDependentContext
argument_list|()
return|;
block|}
comment|/// @brief Starts the definition of this tag declaration.
comment|///
comment|/// This method should be invoked at the beginning of the definition
comment|/// of this tag declaration. It will set the tag type into a state
comment|/// where it is in the process of being defined.
name|void
name|startDefinition
argument_list|()
block|;
comment|/// @brief Completes the definition of this tag declaration.
name|void
name|completeDefinition
argument_list|()
block|;
comment|/// getDefinition - Returns the TagDecl that actually defines this
comment|///  struct/union/class/enum.  When determining whether or not a
comment|///  struct/union/class/enum is completely defined, one should use this method
comment|///  as opposed to 'isDefinition'.  'isDefinition' indicates whether or not a
comment|///  specific TagDecl is defining declaration, not whether or not the
comment|///  struct/union/class/enum type is defined.  This method returns NULL if
comment|///  there is no TagDecl that defines the struct/union/class/enum.
name|TagDecl
operator|*
name|getDefinition
argument_list|(
argument|ASTContext& C
argument_list|)
specifier|const
block|;
specifier|const
name|char
operator|*
name|getKindName
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|getTagKind
argument_list|()
condition|)
block|{
default|default:
name|assert
argument_list|(
literal|0
operator|&&
literal|"Unknown TagKind!"
argument_list|)
expr_stmt|;
case|case
name|TK_struct
case|:
return|return
literal|"struct"
return|;
case|case
name|TK_union
case|:
return|return
literal|"union"
return|;
case|case
name|TK_class
case|:
return|return
literal|"class"
return|;
case|case
name|TK_enum
case|:
return|return
literal|"enum"
return|;
block|}
block|}
name|TagKind
name|getTagKind
argument_list|()
specifier|const
block|{
return|return
name|TagKind
argument_list|(
name|TagDeclKind
argument_list|)
return|;
block|}
name|void
name|setTagKind
argument_list|(
argument|TagKind TK
argument_list|)
block|{
name|TagDeclKind
operator|=
name|TK
block|; }
name|bool
name|isStruct
argument_list|()
specifier|const
block|{
return|return
name|getTagKind
argument_list|()
operator|==
name|TK_struct
return|;
block|}
name|bool
name|isClass
argument_list|()
specifier|const
block|{
return|return
name|getTagKind
argument_list|()
operator|==
name|TK_class
return|;
block|}
name|bool
name|isUnion
argument_list|()
specifier|const
block|{
return|return
name|getTagKind
argument_list|()
operator|==
name|TK_union
return|;
block|}
name|bool
name|isEnum
argument_list|()
specifier|const
block|{
return|return
name|getTagKind
argument_list|()
operator|==
name|TK_enum
return|;
block|}
name|TypedefDecl
operator|*
name|getTypedefForAnonDecl
argument_list|()
specifier|const
block|{
return|return
name|TypedefForAnonDecl
return|;
block|}
name|void
name|setTypedefForAnonDecl
argument_list|(
argument|TypedefDecl *TDD
argument_list|)
block|{
name|TypedefForAnonDecl
operator|=
name|TDD
block|; }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|>=
name|TagFirst
operator|&&
name|D
operator|->
name|getKind
argument_list|()
operator|<=
name|TagLast
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const TagDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|DeclContext
operator|*
name|castToDeclContext
argument_list|(
argument|const TagDecl *D
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|TagDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|TagDecl
operator|*
name|castFromDeclContext
argument_list|(
argument|const DeclContext *DC
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|TagDecl
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|DC
operator|)
operator|)
return|;
block|}
name|void
name|setDefinition
argument_list|(
argument|bool V
argument_list|)
block|{
name|IsDefinition
operator|=
name|V
block|; }
expr|}
block|;
comment|/// EnumDecl - Represents an enum.  As an extension, we allow forward-declared
comment|/// enums.
name|class
name|EnumDecl
operator|:
name|public
name|TagDecl
block|{
comment|/// IntegerType - This represent the integer type that the enum corresponds
comment|/// to for code generation purposes.  Note that the enumerator constants may
comment|/// have a different type than this does.
name|QualType
name|IntegerType
block|;
comment|/// \brief If the enumeration was instantiated from an enumeration
comment|/// within a class or function template, this pointer refers to the
comment|/// enumeration declared within the template.
name|EnumDecl
operator|*
name|InstantiatedFrom
block|;
name|EnumDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
operator|:
name|TagDecl
argument_list|(
name|Enum
argument_list|,
name|TK_enum
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|InstantiatedFrom
argument_list|(
literal|0
argument_list|)
block|{
name|IntegerType
operator|=
name|QualType
argument_list|()
block|;     }
name|public
operator|:
specifier|static
name|EnumDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|EnumDecl *PrevDecl
argument_list|)
block|;
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
comment|/// completeDefinition - When created, the EnumDecl corresponds to a
comment|/// forward-declared enum. This method is used to mark the
comment|/// declaration as being defined; it's enumerators have already been
comment|/// added (via DeclContext::addDecl). NewType is the new underlying
comment|/// type of the enumeration type.
name|void
name|completeDefinition
argument_list|(
argument|ASTContext&C
argument_list|,
argument|QualType NewType
argument_list|)
block|;
comment|// enumerator_iterator - Iterates through the enumerators of this
comment|// enumeration.
typedef|typedef
name|specific_decl_iterator
operator|<
name|EnumConstantDecl
operator|>
name|enumerator_iterator
expr_stmt|;
name|enumerator_iterator
name|enumerator_begin
argument_list|(
argument|ASTContext&Context
argument_list|)
specifier|const
block|{
return|return
name|enumerator_iterator
argument_list|(
name|this
operator|->
name|decls_begin
argument_list|(
name|Context
argument_list|)
argument_list|)
return|;
block|}
name|enumerator_iterator
name|enumerator_end
argument_list|(
argument|ASTContext&Context
argument_list|)
specifier|const
block|{
return|return
name|enumerator_iterator
argument_list|(
name|this
operator|->
name|decls_end
argument_list|(
name|Context
argument_list|)
argument_list|)
return|;
block|}
comment|/// getIntegerType - Return the integer type this enum decl corresponds to.
comment|/// This returns a null qualtype for an enum forward definition.
name|QualType
name|getIntegerType
argument_list|()
specifier|const
block|{
return|return
name|IntegerType
return|;
block|}
comment|/// \brief Set the underlying integer type.
name|void
name|setIntegerType
argument_list|(
argument|QualType T
argument_list|)
block|{
name|IntegerType
operator|=
name|T
block|; }
comment|/// \brief Returns the enumeration (declared within the template)
comment|/// from which this enumeration type was instantiated, or NULL if
comment|/// this enumeration was not instantiated from any template.
name|EnumDecl
operator|*
name|getInstantiatedFromMemberEnum
argument_list|()
specifier|const
block|{
return|return
name|InstantiatedFrom
return|;
block|}
name|void
name|setInstantiationOfMemberEnum
argument_list|(
argument|EnumDecl *IF
argument_list|)
block|{
name|InstantiatedFrom
operator|=
name|IF
block|; }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|Enum
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const EnumDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// RecordDecl - Represents a struct/union/class.  For example:
comment|///   struct X;                  // Forward declaration, no "body".
comment|///   union Y { int A, B; };     // Has body with members A and B (FieldDecls).
comment|/// This decl will be marked invalid if *any* members are invalid.
comment|///
name|class
name|RecordDecl
operator|:
name|public
name|TagDecl
block|{
comment|// FIXME: This can be packed into the bitfields in Decl.
comment|/// HasFlexibleArrayMember - This is true if this struct ends with a flexible
comment|/// array member (e.g. int X[]) or if this union contains a struct that does.
comment|/// If so, this cannot be contained in arrays or other structs as a member.
name|bool
name|HasFlexibleArrayMember
operator|:
literal|1
block|;
comment|/// AnonymousStructOrUnion - Whether this is the type of an
comment|/// anonymous struct or union.
name|bool
name|AnonymousStructOrUnion
operator|:
literal|1
block|;
name|protected
operator|:
name|RecordDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|TagKind TK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
block|;
name|virtual
operator|~
name|RecordDecl
argument_list|()
block|;
name|public
operator|:
specifier|static
name|RecordDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|TagKind TK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|RecordDecl* PrevDecl =
literal|0
argument_list|)
block|;
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|bool
name|hasFlexibleArrayMember
argument_list|()
specifier|const
block|{
return|return
name|HasFlexibleArrayMember
return|;
block|}
name|void
name|setHasFlexibleArrayMember
argument_list|(
argument|bool V
argument_list|)
block|{
name|HasFlexibleArrayMember
operator|=
name|V
block|; }
comment|/// isAnonymousStructOrUnion - Whether this is an anonymous struct
comment|/// or union. To be an anonymous struct or union, it must have been
comment|/// declared without a name and there must be no objects of this
comment|/// type declared, e.g.,
comment|/// @code
comment|///   union { int i; float f; };
comment|/// @endcode
comment|/// is an anonymous union but neither of the following are:
comment|/// @code
comment|///  union X { int i; float f; };
comment|///  union { int i; float f; } obj;
comment|/// @endcode
name|bool
name|isAnonymousStructOrUnion
argument_list|()
specifier|const
block|{
return|return
name|AnonymousStructOrUnion
return|;
block|}
name|void
name|setAnonymousStructOrUnion
argument_list|(
argument|bool Anon
argument_list|)
block|{
name|AnonymousStructOrUnion
operator|=
name|Anon
block|;   }
comment|/// \brief Determines whether this declaration represents the
comment|/// injected class name.
comment|///
comment|/// The injected class name in C++ is the name of the class that
comment|/// appears inside the class itself. For example:
comment|///
comment|/// \code
comment|/// struct C {
comment|///   // C is implicitly declared here as a synonym for the class name.
comment|/// };
comment|///
comment|/// C::C c; // same as "C c;"
comment|/// \endcode
name|bool
name|isInjectedClassName
argument_list|()
specifier|const
block|;
comment|/// getDefinition - Returns the RecordDecl that actually defines this
comment|///  struct/union/class.  When determining whether or not a struct/union/class
comment|///  is completely defined, one should use this method as opposed to
comment|///  'isDefinition'.  'isDefinition' indicates whether or not a specific
comment|///  RecordDecl is defining declaration, not whether or not the record
comment|///  type is defined.  This method returns NULL if there is no RecordDecl
comment|///  that defines the struct/union/tag.
name|RecordDecl
operator|*
name|getDefinition
argument_list|(
argument|ASTContext& C
argument_list|)
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|RecordDecl
operator|>
operator|(
name|TagDecl
operator|::
name|getDefinition
argument_list|(
name|C
argument_list|)
operator|)
return|;
block|}
comment|// Iterator access to field members. The field iterator only visits
comment|// the non-static data members of this class, ignoring any static
comment|// data members, functions, constructors, destructors, etc.
typedef|typedef
name|specific_decl_iterator
operator|<
name|FieldDecl
operator|>
name|field_iterator
expr_stmt|;
name|field_iterator
name|field_begin
argument_list|(
argument|ASTContext&Context
argument_list|)
specifier|const
block|{
return|return
name|field_iterator
argument_list|(
name|decls_begin
argument_list|(
name|Context
argument_list|)
argument_list|)
return|;
block|}
name|field_iterator
name|field_end
argument_list|(
argument|ASTContext&Context
argument_list|)
specifier|const
block|{
return|return
name|field_iterator
argument_list|(
name|decls_end
argument_list|(
name|Context
argument_list|)
argument_list|)
return|;
block|}
comment|// field_empty - Whether there are any fields (non-static data
comment|// members) in this record.
name|bool
name|field_empty
argument_list|(
argument|ASTContext&Context
argument_list|)
specifier|const
block|{
return|return
name|field_begin
argument_list|(
name|Context
argument_list|)
operator|==
name|field_end
argument_list|(
name|Context
argument_list|)
return|;
block|}
comment|/// completeDefinition - Notes that the definition of this type is
comment|/// now complete.
name|void
name|completeDefinition
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|>=
name|RecordFirst
operator|&&
name|D
operator|->
name|getKind
argument_list|()
operator|<=
name|RecordLast
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const RecordDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|FileScopeAsmDecl
operator|:
name|public
name|Decl
block|{
name|StringLiteral
operator|*
name|AsmString
block|;
name|FileScopeAsmDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|StringLiteral *asmstring
argument_list|)
operator|:
name|Decl
argument_list|(
name|FileScopeAsm
argument_list|,
name|DC
argument_list|,
name|L
argument_list|)
block|,
name|AsmString
argument_list|(
argument|asmstring
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|FileScopeAsmDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|StringLiteral *Str
argument_list|)
block|;
specifier|const
name|StringLiteral
operator|*
name|getAsmString
argument_list|()
specifier|const
block|{
return|return
name|AsmString
return|;
block|}
name|StringLiteral
operator|*
name|getAsmString
argument_list|()
block|{
return|return
name|AsmString
return|;
block|}
name|void
name|setAsmString
argument_list|(
argument|StringLiteral *Asm
argument_list|)
block|{
name|AsmString
operator|=
name|Asm
block|; }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|FileScopeAsm
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const FileScopeAsmDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// BlockDecl - This represents a block literal declaration, which is like an
comment|/// unnamed FunctionDecl.  For example:
comment|/// ^{ statement-body }   or   ^(int arg1, float arg2){ statement-body }
comment|///
name|class
name|BlockDecl
operator|:
name|public
name|Decl
block|,
name|public
name|DeclContext
block|{
comment|// FIXME: This can be packed into the bitfields in Decl.
name|bool
name|isVariadic
operator|:
literal|1
block|;
comment|/// ParamInfo - new[]'d array of pointers to ParmVarDecls for the formal
comment|/// parameters of this function.  This is null if a prototype or if there are
comment|/// no formals.
name|ParmVarDecl
operator|*
operator|*
name|ParamInfo
block|;
name|unsigned
name|NumParams
block|;
name|Stmt
operator|*
name|Body
block|;
name|protected
operator|:
name|BlockDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation CaretLoc
argument_list|)
operator|:
name|Decl
argument_list|(
name|Block
argument_list|,
name|DC
argument_list|,
name|CaretLoc
argument_list|)
block|,
name|DeclContext
argument_list|(
name|Block
argument_list|)
block|,
name|isVariadic
argument_list|(
name|false
argument_list|)
block|,
name|ParamInfo
argument_list|(
literal|0
argument_list|)
block|,
name|NumParams
argument_list|(
literal|0
argument_list|)
block|,
name|Body
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|BlockDecl
argument_list|()
block|;
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
name|public
operator|:
specifier|static
name|BlockDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|)
block|;
name|SourceLocation
name|getCaretLocation
argument_list|()
specifier|const
block|{
return|return
name|getLocation
argument_list|()
return|;
block|}
name|bool
name|IsVariadic
argument_list|()
specifier|const
block|{
return|return
name|isVariadic
return|;
block|}
name|void
name|setIsVariadic
argument_list|(
argument|bool value
argument_list|)
block|{
name|isVariadic
operator|=
name|value
block|; }
name|CompoundStmt
operator|*
name|getBody
argument_list|()
specifier|const
block|{
return|return
operator|(
name|CompoundStmt
operator|*
operator|)
name|Body
return|;
block|}
name|Stmt
operator|*
name|getBody
argument_list|(
argument|ASTContext&C
argument_list|)
specifier|const
block|{
return|return
operator|(
name|Stmt
operator|*
operator|)
name|Body
return|;
block|}
name|void
name|setBody
argument_list|(
argument|CompoundStmt *B
argument_list|)
block|{
name|Body
operator|=
operator|(
name|Stmt
operator|*
operator|)
name|B
block|; }
comment|// Iterator access to formal parameters.
name|unsigned
name|param_size
argument_list|()
specifier|const
block|{
return|return
name|getNumParams
argument_list|()
return|;
block|}
typedef|typedef
name|ParmVarDecl
modifier|*
modifier|*
name|param_iterator
typedef|;
typedef|typedef
name|ParmVarDecl
modifier|*
specifier|const
modifier|*
name|param_const_iterator
typedef|;
name|bool
name|param_empty
argument_list|()
specifier|const
block|{
return|return
name|NumParams
operator|==
literal|0
return|;
block|}
name|param_iterator
name|param_begin
argument_list|()
block|{
return|return
name|ParamInfo
return|;
block|}
name|param_iterator
name|param_end
argument_list|()
block|{
return|return
name|ParamInfo
operator|+
name|param_size
argument_list|()
return|;
block|}
name|param_const_iterator
name|param_begin
argument_list|()
specifier|const
block|{
return|return
name|ParamInfo
return|;
block|}
name|param_const_iterator
name|param_end
argument_list|()
specifier|const
block|{
return|return
name|ParamInfo
operator|+
name|param_size
argument_list|()
return|;
block|}
name|unsigned
name|getNumParams
argument_list|()
specifier|const
block|;
specifier|const
name|ParmVarDecl
operator|*
name|getParamDecl
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumParams
argument_list|()
operator|&&
literal|"Illegal param #"
argument_list|)
block|;
return|return
name|ParamInfo
index|[
name|i
index|]
return|;
block|}
name|ParmVarDecl
operator|*
name|getParamDecl
argument_list|(
argument|unsigned i
argument_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumParams
argument_list|()
operator|&&
literal|"Illegal param #"
argument_list|)
block|;
return|return
name|ParamInfo
index|[
name|i
index|]
return|;
block|}
name|void
name|setParams
argument_list|(
argument|ASTContext& C
argument_list|,
argument|ParmVarDecl **NewParamInfo
argument_list|,
argument|unsigned NumParams
argument_list|)
block|;
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|Block
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const BlockDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|DeclContext
operator|*
name|castToDeclContext
argument_list|(
argument|const BlockDecl *D
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|BlockDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|BlockDecl
operator|*
name|castFromDeclContext
argument_list|(
argument|const DeclContext *DC
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|BlockDecl
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|DeclContext
operator|*
operator|>
operator|(
name|DC
operator|)
operator|)
return|;
block|}
expr|}
block|;
comment|/// Insertion operator for diagnostics.  This allows sending NamedDecl's
comment|/// into a diagnostic with<<.
specifier|inline
specifier|const
name|DiagnosticBuilder
operator|&
name|operator
operator|<<
operator|(
specifier|const
name|DiagnosticBuilder
operator|&
name|DB
expr|,
name|NamedDecl
operator|*
name|ND
operator|)
block|{
name|DB
operator|.
name|AddTaggedVal
argument_list|(
name|reinterpret_cast
operator|<
name|intptr_t
operator|>
operator|(
name|ND
operator|)
argument_list|,
name|Diagnostic
operator|::
name|ak_nameddecl
argument_list|)
block|;
return|return
name|DB
return|;
block|}
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

