begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Action.h - Parser Action Interface ---------------------*- C++ -*-===//
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
comment|//  This file defines the Action and EmptyAction interface.
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
name|LLVM_CLANG_PARSE_ACTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_PARSE_ACTION_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TemplateKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/TypeTraits.h"
end_include

begin_include
include|#
directive|include
file|"clang/Parse/AccessSpecifier.h"
end_include

begin_include
include|#
directive|include
file|"clang/Parse/DeclSpec.h"
end_include

begin_include
include|#
directive|include
file|"clang/Parse/Ownership.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/PrettyStackTrace.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|// Semantic.
name|class
name|DeclSpec
decl_stmt|;
name|class
name|ObjCDeclSpec
decl_stmt|;
name|class
name|CXXScopeSpec
decl_stmt|;
name|class
name|Declarator
decl_stmt|;
name|class
name|AttributeList
decl_stmt|;
struct_decl|struct
name|FieldDeclarator
struct_decl|;
comment|// Parse.
name|class
name|Scope
decl_stmt|;
name|class
name|Action
decl_stmt|;
name|class
name|Selector
decl_stmt|;
name|class
name|Designation
decl_stmt|;
name|class
name|InitListDesignations
decl_stmt|;
comment|// Lex.
name|class
name|Preprocessor
decl_stmt|;
name|class
name|Token
decl_stmt|;
comment|// We can re-use the low bit of expression, statement, base, and
comment|// member-initializer pointers for the "invalid" flag of
comment|// ActionResult.
name|template
operator|<
operator|>
expr|struct
name|IsResultPtrLowBitFree
operator|<
literal|0
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;}
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|IsResultPtrLowBitFree
operator|<
literal|1
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;}
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|IsResultPtrLowBitFree
operator|<
literal|3
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;}
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|IsResultPtrLowBitFree
operator|<
literal|4
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;}
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|IsResultPtrLowBitFree
operator|<
literal|5
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;}
expr_stmt|;
comment|/// Action - As the parser reads the input file and recognizes the productions
comment|/// of the grammar, it invokes methods on this class to turn the parsed input
comment|/// into something useful: e.g. a parse tree.
comment|///
comment|/// The callback methods that this class provides are phrased as actions that
comment|/// the parser has just done or is about to do when the method is called.  They
comment|/// are not requests that the actions module do the specified action.
comment|///
comment|/// All of the methods here are optional except getTypeName() and
comment|/// isCurrentClassName(), which must be specified in order for the
comment|/// parse to complete accurately.  The MinimalAction class does this
comment|/// bare-minimum of tracking to implement this functionality.
name|class
name|Action
range|:
name|public
name|ActionBase
block|{
name|public
operator|:
comment|/// Out-of-line virtual destructor to provide home for this class.
name|virtual
operator|~
name|Action
argument_list|()
block|;
comment|// Types - Though these don't actually enforce strong typing, they document
comment|// what types are required to be identical for the actions.
typedef|typedef
name|ActionBase
operator|::
name|ExprTy
name|ExprTy
expr_stmt|;
typedef|typedef
name|ActionBase
operator|::
name|StmtTy
name|StmtTy
expr_stmt|;
comment|/// Expr/Stmt/Type/BaseResult - Provide a unique type to wrap
comment|/// ExprTy/StmtTy/TypeTy/BaseTy, providing strong typing and
comment|/// allowing for failure.
typedef|typedef
name|ActionResult
operator|<
literal|0
operator|>
name|ExprResult
expr_stmt|;
typedef|typedef
name|ActionResult
operator|<
literal|1
operator|>
name|StmtResult
expr_stmt|;
typedef|typedef
name|ActionResult
operator|<
literal|2
operator|>
name|TypeResult
expr_stmt|;
typedef|typedef
name|ActionResult
operator|<
literal|3
operator|>
name|BaseResult
expr_stmt|;
typedef|typedef
name|ActionResult
operator|<
literal|4
operator|>
name|MemInitResult
expr_stmt|;
typedef|typedef
name|ActionResult
operator|<
literal|5
operator|,
name|DeclPtrTy
operator|>
name|DeclResult
expr_stmt|;
comment|/// Same, but with ownership.
typedef|typedef
name|ASTOwningResult
operator|<
operator|&
name|ActionBase
operator|::
name|DeleteExpr
operator|>
name|OwningExprResult
expr_stmt|;
typedef|typedef
name|ASTOwningResult
operator|<
operator|&
name|ActionBase
operator|::
name|DeleteStmt
operator|>
name|OwningStmtResult
expr_stmt|;
comment|// Note that these will replace ExprResult and StmtResult when the transition
comment|// is complete.
comment|/// Single expressions or statements as arguments.
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DISABLE_SMART_POINTERS
argument_list|)
typedef|typedef
name|ASTOwningResult
operator|<
operator|&
name|ActionBase
operator|::
name|DeleteExpr
operator|>
name|ExprArg
expr_stmt|;
typedef|typedef
name|ASTOwningResult
operator|<
operator|&
name|ActionBase
operator|::
name|DeleteStmt
operator|>
name|StmtArg
expr_stmt|;
else|#
directive|else
typedef|typedef
name|ASTOwningPtr
operator|<
operator|&
name|ActionBase
operator|::
name|DeleteExpr
operator|>
name|ExprArg
expr_stmt|;
typedef|typedef
name|ASTOwningPtr
operator|<
operator|&
name|ActionBase
operator|::
name|DeleteStmt
operator|>
name|StmtArg
expr_stmt|;
endif|#
directive|endif
comment|/// Multiple expressions or statements as arguments.
typedef|typedef
name|ASTMultiPtr
operator|<
operator|&
name|ActionBase
operator|::
name|DeleteExpr
operator|>
name|MultiExprArg
expr_stmt|;
typedef|typedef
name|ASTMultiPtr
operator|<
operator|&
name|ActionBase
operator|::
name|DeleteStmt
operator|>
name|MultiStmtArg
expr_stmt|;
typedef|typedef
name|ASTMultiPtr
operator|<
operator|&
name|ActionBase
operator|::
name|DeleteTemplateParams
operator|>
name|MultiTemplateParamsArg
expr_stmt|;
name|class
name|FullExprArg
block|{
name|public
label|:
comment|// FIXME: The const_cast here is ugly. RValue references would make this
comment|// much nicer (or we could duplicate a bunch of the move semantics
comment|// emulation code from Ownership.h).
name|FullExprArg
argument_list|(
specifier|const
name|FullExprArg
operator|&
name|Other
argument_list|)
operator|:
name|Expr
argument_list|(
argument|move(const_cast<FullExprArg&>(Other).Expr)
argument_list|)
block|{}
name|OwningExprResult
name|release
argument_list|()
block|{
return|return
name|move
argument_list|(
name|Expr
argument_list|)
return|;
block|}
name|ExprArg
operator|*
name|operator
operator|->
expr|(
block|)
block|{
return|return
operator|&
name|Expr
return|;
block|}
name|private
label|:
comment|// FIXME: No need to make the entire Action class a friend when it's just
comment|// Action::FullExpr that needs access to the constructor below.
name|friend
name|class
name|Action
decl_stmt|;
name|explicit
name|FullExprArg
argument_list|(
argument|ExprArg expr
argument_list|)
block|:
name|Expr
argument_list|(
argument|move(expr)
argument_list|)
block|{}
name|ExprArg
name|Expr
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|FullExprArg
name|FullExpr
argument_list|(
argument|T&Arg
argument_list|)
block|{
return|return
name|FullExprArg
argument_list|(
name|ActOnFinishFullExpr
argument_list|(
name|move
argument_list|(
name|Arg
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Utilities for Action implementations to return smart results.
end_comment

begin_function
name|OwningExprResult
name|ExprError
parameter_list|()
block|{
return|return
name|OwningExprResult
argument_list|(
operator|*
name|this
argument_list|,
name|true
argument_list|)
return|;
block|}
end_function

begin_function
name|OwningStmtResult
name|StmtError
parameter_list|()
block|{
return|return
name|OwningStmtResult
argument_list|(
operator|*
name|this
argument_list|,
name|true
argument_list|)
return|;
block|}
end_function

begin_function
name|OwningExprResult
name|ExprError
parameter_list|(
specifier|const
name|DiagnosticBuilder
modifier|&
parameter_list|)
block|{
return|return
name|ExprError
argument_list|()
return|;
block|}
end_function

begin_function
name|OwningStmtResult
name|StmtError
parameter_list|(
specifier|const
name|DiagnosticBuilder
modifier|&
parameter_list|)
block|{
return|return
name|StmtError
argument_list|()
return|;
block|}
end_function

begin_function
name|OwningExprResult
name|ExprEmpty
parameter_list|()
block|{
return|return
name|OwningExprResult
argument_list|(
operator|*
name|this
argument_list|,
name|false
argument_list|)
return|;
block|}
end_function

begin_function
name|OwningStmtResult
name|StmtEmpty
parameter_list|()
block|{
return|return
name|OwningStmtResult
argument_list|(
operator|*
name|this
argument_list|,
name|false
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Statistics.
end_comment

begin_expr_stmt
name|virtual
name|void
name|PrintStats
argument_list|()
specifier|const
block|{}
comment|/// getDeclName - Return a pretty name for the specified decl if possible, or
comment|/// an empty string if not.  This is used for pretty crash reporting.
name|virtual
name|std
operator|::
name|string
name|getDeclName
argument_list|(
argument|DeclPtrTy D
argument_list|)
block|{
return|return
literal|""
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Invoked for each comment in the source code, providing the source
end_comment

begin_comment
comment|/// range that contains the comment.
end_comment

begin_function
name|virtual
name|void
name|ActOnComment
parameter_list|(
name|SourceRange
name|Comment
parameter_list|)
block|{ }
end_function

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Declaration Tracking Callbacks.
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_typedef
typedef|typedef
name|uintptr_t
name|ParsingDeclStackState
typedef|;
end_typedef

begin_comment
comment|/// PushParsingDeclaration - Notes that the parser has begun
end_comment

begin_comment
comment|/// processing a declaration of some sort.  Guaranteed to be matched
end_comment

begin_comment
comment|/// by a call to PopParsingDeclaration with the value returned by
end_comment

begin_comment
comment|/// this method.
end_comment

begin_function
name|virtual
name|ParsingDeclStackState
name|PushParsingDeclaration
parameter_list|()
block|{
return|return
name|ParsingDeclStackState
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// PopParsingDeclaration - Notes that the parser has completed
end_comment

begin_comment
comment|/// processing a declaration of some sort.  The decl will be empty
end_comment

begin_comment
comment|/// if the declaration didn't correspond to a full declaration (or
end_comment

begin_comment
comment|/// if the actions module returned an empty decl for it).
end_comment

begin_function
name|virtual
name|void
name|PopParsingDeclaration
parameter_list|(
name|ParsingDeclStackState
name|S
parameter_list|,
name|DeclPtrTy
name|D
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ConvertDeclToDeclGroup - If the parser has one decl in a context where it
end_comment

begin_comment
comment|/// needs a decl group, it calls this to convert between the two
end_comment

begin_comment
comment|/// representations.
end_comment

begin_function
name|virtual
name|DeclGroupPtrTy
name|ConvertDeclToDeclGroup
parameter_list|(
name|DeclPtrTy
name|Ptr
parameter_list|)
block|{
return|return
name|DeclGroupPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// getTypeName - Return non-null if the specified identifier is a type name
end_comment

begin_comment
comment|/// in the current scope.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param II the identifier for which we are performing name lookup
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NameLoc the location of the identifier
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which this name lookup occurs
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS if non-NULL, the C++ scope specifier that precedes the
end_comment

begin_comment
comment|/// identifier
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param isClassName whether this is a C++ class-name production, in
end_comment

begin_comment
comment|/// which we can end up referring to a member of an unknown specialization
end_comment

begin_comment
comment|/// that we know (from the grammar) is supposed to be a type. For example,
end_comment

begin_comment
comment|/// this occurs when deriving from "std::vector<T>::allocator_type", where T
end_comment

begin_comment
comment|/// is a template parameter.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the type referred to by this identifier, or NULL if the type
end_comment

begin_comment
comment|/// does not name an identifier.
end_comment

begin_function_decl
name|virtual
name|TypeTy
modifier|*
name|getTypeName
parameter_list|(
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|*
name|SS
init|=
literal|0
parameter_list|,
name|bool
name|isClassName
init|=
name|false
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// isTagName() - This method is called *for error recovery purposes only*
end_comment

begin_comment
comment|/// to determine if the specified name is a valid tag name ("struct foo").  If
end_comment

begin_comment
comment|/// so, this returns the TST for the tag corresponding to it (TST_enum,
end_comment

begin_comment
comment|/// TST_union, TST_struct, TST_class).  This is used to diagnose cases in C
end_comment

begin_comment
comment|/// where the user forgot to specify the tag.
end_comment

begin_expr_stmt
name|virtual
name|DeclSpec
operator|::
name|TST
name|isTagName
argument_list|(
argument|IdentifierInfo&II
argument_list|,
argument|Scope *S
argument_list|)
block|{
return|return
name|DeclSpec
operator|::
name|TST_unspecified
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Action called as part of error recovery when the parser has
end_comment

begin_comment
comment|/// determined that the given name must refer to a type, but
end_comment

begin_comment
comment|/// \c getTypeName() did not return a result.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This callback permits the action to give a detailed diagnostic when an
end_comment

begin_comment
comment|/// unknown type name is encountered and, potentially, to try to recover
end_comment

begin_comment
comment|/// by producing a new type in \p SuggestedType.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param II the name that should be a type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IILoc the location of the name in the source.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which name lookup was performed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS if non-NULL, the C++ scope specifier that preceded the name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SuggestedType if the action sets this type to a non-NULL type,
end_comment

begin_comment
comment|/// the parser will recovery by consuming the type name token and then
end_comment

begin_comment
comment|/// pretending that the given type was the type it parsed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns true if a diagnostic was emitted, false otherwise. When false,
end_comment

begin_comment
comment|/// the parser itself will emit a generic "unknown type name" diagnostic.
end_comment

begin_function
name|virtual
name|bool
name|DiagnoseUnknownTypeName
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|SourceLocation
name|IILoc
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|*
name|SS
parameter_list|,
name|TypeTy
modifier|*
modifier|&
name|SuggestedType
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/// isCurrentClassName - Return true if the specified name is the
end_comment

begin_comment
comment|/// name of the innermost C++ class type currently being defined.
end_comment

begin_function_decl
name|virtual
name|bool
name|isCurrentClassName
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|*
name|SS
init|=
literal|0
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether the given name refers to a template.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This callback is used by the parser after it has seen a '<' to determine
end_comment

begin_comment
comment|/// whether the given name refers to a template and, if so, what kind of
end_comment

begin_comment
comment|/// template.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the name occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS the C++ nested-name-specifier that precedes the template name,
end_comment

begin_comment
comment|/// if any.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Name the name that we are querying to determine whether it is
end_comment

begin_comment
comment|/// a template.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ObjectType if we are determining whether the given name is a
end_comment

begin_comment
comment|/// template name in the context of a member access expression (e.g.,
end_comment

begin_comment
comment|/// \c p->X<int>), this is the type of the object referred to by the
end_comment

begin_comment
comment|/// member access (e.g., \c p).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param EnteringContext whether we are potentially entering the context
end_comment

begin_comment
comment|/// referred to by the nested-name-specifier \p SS, which allows semantic
end_comment

begin_comment
comment|/// analysis to look into uninstantiated templates.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Template if the name does refer to a template, the declaration
end_comment

begin_comment
comment|/// of the template that the name refers to.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the kind of template that this name refers to.
end_comment

begin_function_decl
name|virtual
name|TemplateNameKind
name|isTemplateName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|,
name|TypeTy
modifier|*
name|ObjectType
parameter_list|,
name|bool
name|EnteringContext
parameter_list|,
name|TemplateTy
modifier|&
name|Template
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnCXXGlobalScopeSpecifier - Return the object that represents the
end_comment

begin_comment
comment|/// global scope ('::').
end_comment

begin_function
name|virtual
name|CXXScopeTy
modifier|*
name|ActOnCXXGlobalScopeSpecifier
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|CCLoc
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/// \brief Parsed an identifier followed by '::' in a C++
end_comment

begin_comment
comment|/// nested-name-specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the nested-name-specifier was parsed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS the nested-name-specifier that precedes the identifier. For
end_comment

begin_comment
comment|/// example, if we are parsing "foo::bar::", \p SS will describe the "foo::"
end_comment

begin_comment
comment|/// that has already been parsed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IdLoc the location of the identifier we have just parsed (e.g.,
end_comment

begin_comment
comment|/// the "bar" in "foo::bar::".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param CCLoc the location of the '::' at the end of the
end_comment

begin_comment
comment|/// nested-name-specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param II the identifier that represents the scope that this
end_comment

begin_comment
comment|/// nested-name-specifier refers to, e.g., the "bar" in "foo::bar::".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ObjectType if this nested-name-specifier occurs as part of a
end_comment

begin_comment
comment|/// C++ member access expression such as "x->Base::f", the type of the base
end_comment

begin_comment
comment|/// object (e.g., *x in the example, if "x" were a pointer).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param EnteringContext if true, then we intend to immediately enter the
end_comment

begin_comment
comment|/// context of this nested-name-specifier, e.g., for an out-of-line
end_comment

begin_comment
comment|/// definition of a class member.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns a CXXScopeTy* object representing the C++ scope.
end_comment

begin_function
name|virtual
name|CXXScopeTy
modifier|*
name|ActOnCXXNestedNameSpecifier
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|SourceLocation
name|CCLoc
parameter_list|,
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|TypeTy
modifier|*
name|ObjectType
parameter_list|,
name|bool
name|EnteringContext
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/// ActOnCXXNestedNameSpecifier - Called during parsing of a
end_comment

begin_comment
comment|/// nested-name-specifier that involves a template-id, e.g.,
end_comment

begin_comment
comment|/// "foo::bar<int, float>::", and now we need to build a scope
end_comment

begin_comment
comment|/// specifier. \p SS is empty or the previously parsed nested-name
end_comment

begin_comment
comment|/// part ("foo::"), \p Type is the already-parsed class template
end_comment

begin_comment
comment|/// specialization (or other template-id that names a type), \p
end_comment

begin_comment
comment|/// TypeRange is the source range where the type is located, and \p
end_comment

begin_comment
comment|/// CCLoc is the location of the trailing '::'.
end_comment

begin_function
name|virtual
name|CXXScopeTy
modifier|*
name|ActOnCXXNestedNameSpecifier
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|TypeTy
modifier|*
name|Type
parameter_list|,
name|SourceRange
name|TypeRange
parameter_list|,
name|SourceLocation
name|CCLoc
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/// ActOnCXXEnterDeclaratorScope - Called when a C++ scope specifier (global
end_comment

begin_comment
comment|/// scope or nested-name-specifier) is parsed, part of a declarator-id.
end_comment

begin_comment
comment|/// After this method is called, according to [C++ 3.4.3p3], names should be
end_comment

begin_comment
comment|/// looked up in the declarator-id's scope, until the declarator is parsed and
end_comment

begin_comment
comment|/// ActOnCXXExitDeclaratorScope is called.
end_comment

begin_comment
comment|/// The 'SS' should be a non-empty valid CXXScopeSpec.
end_comment

begin_comment
comment|/// \returns true if an error occurred, false otherwise.
end_comment

begin_function
name|virtual
name|bool
name|ActOnCXXEnterDeclaratorScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
block|{
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/// ActOnCXXExitDeclaratorScope - Called when a declarator that previously
end_comment

begin_comment
comment|/// invoked ActOnCXXEnterDeclaratorScope(), is finished. 'SS' is the same
end_comment

begin_comment
comment|/// CXXScopeSpec that was passed to ActOnCXXEnterDeclaratorScope as well.
end_comment

begin_comment
comment|/// Used to indicate that names should revert to being looked up in the
end_comment

begin_comment
comment|/// defining scope.
end_comment

begin_function
name|virtual
name|void
name|ActOnCXXExitDeclaratorScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnCXXEnterDeclInitializer - Invoked when we are about to parse an
end_comment

begin_comment
comment|/// initializer for the declaration 'Dcl'.
end_comment

begin_comment
comment|/// After this method is called, according to [C++ 3.4.1p13], if 'Dcl' is a
end_comment

begin_comment
comment|/// static data member of class X, names should be looked up in the scope of
end_comment

begin_comment
comment|/// class X.
end_comment

begin_function
name|virtual
name|void
name|ActOnCXXEnterDeclInitializer
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Dcl
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnCXXExitDeclInitializer - Invoked after we are finished parsing an
end_comment

begin_comment
comment|/// initializer for the declaration 'Dcl'.
end_comment

begin_function
name|virtual
name|void
name|ActOnCXXExitDeclInitializer
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Dcl
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnDeclarator - This callback is invoked when a declarator is parsed and
end_comment

begin_comment
comment|/// 'Init' specifies the initializer if any.  This is for things like:
end_comment

begin_comment
comment|/// "int X = 4" or "typedef int foo".
end_comment

begin_comment
comment|///
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnParamDeclarator - This callback is invoked when a parameter
end_comment

begin_comment
comment|/// declarator is parsed. This callback only occurs for functions
end_comment

begin_comment
comment|/// with prototypes. S is the function prototype scope for the
end_comment

begin_comment
comment|/// parameters (C++ [basic.scope.proto]).
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnParamDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// AddInitializerToDecl - This action is called immediately after
end_comment

begin_comment
comment|/// ActOnDeclarator (when an initializer is present). The code is factored
end_comment

begin_comment
comment|/// this way to make sure we are able to handle the following:
end_comment

begin_comment
comment|///   void func() { int xx = xx; }
end_comment

begin_comment
comment|/// This allows ActOnDeclarator to register "xx" prior to parsing the
end_comment

begin_comment
comment|/// initializer. The declaration above should still result in a warning,
end_comment

begin_comment
comment|/// since the reference to "xx" is uninitialized.
end_comment

begin_function
name|virtual
name|void
name|AddInitializerToDecl
parameter_list|(
name|DeclPtrTy
name|Dcl
parameter_list|,
name|ExprArg
name|Init
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/// SetDeclDeleted - This action is called immediately after ActOnDeclarator
end_comment

begin_comment
comment|/// if =delete is parsed. C++0x [dcl.fct.def]p10
end_comment

begin_comment
comment|/// Note that this can be called even for variable declarations. It's the
end_comment

begin_comment
comment|/// action's job to reject it.
end_comment

begin_function
name|virtual
name|void
name|SetDeclDeleted
parameter_list|(
name|DeclPtrTy
name|Dcl
parameter_list|,
name|SourceLocation
name|DelLoc
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/// ActOnUninitializedDecl - This action is called immediately after
end_comment

begin_comment
comment|/// ActOnDeclarator (when an initializer is *not* present).
end_comment

begin_comment
comment|/// If TypeContainsUndeducedAuto is true, then the type of the declarator
end_comment

begin_comment
comment|/// has an undeduced 'auto' type somewhere.
end_comment

begin_function
name|virtual
name|void
name|ActOnUninitializedDecl
parameter_list|(
name|DeclPtrTy
name|Dcl
parameter_list|,
name|bool
name|TypeContainsUndeducedAuto
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/// FinalizeDeclaratorGroup - After a sequence of declarators are parsed, this
end_comment

begin_comment
comment|/// gives the actions implementation a chance to process the group as a whole.
end_comment

begin_function
name|virtual
name|DeclGroupPtrTy
name|FinalizeDeclaratorGroup
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|DeclPtrTy
modifier|*
name|Group
parameter_list|,
name|unsigned
name|NumDecls
parameter_list|)
block|{
return|return
name|DeclGroupPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// @brief Indicates that all K&R-style parameter declarations have
end_comment

begin_comment
comment|/// been parsed prior to a function definition.
end_comment

begin_comment
comment|/// @param S  The function prototype scope.
end_comment

begin_comment
comment|/// @param D  The function declarator.
end_comment

begin_function
name|virtual
name|void
name|ActOnFinishKNRParamDeclarations
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|SourceLocation
name|LocAfterDecls
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnStartOfFunctionDef - This is called at the start of a function
end_comment

begin_comment
comment|/// definition, instead of calling ActOnDeclarator.  The Declarator includes
end_comment

begin_comment
comment|/// information about formal arguments that are part of this function.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnStartOfFunctionDef
parameter_list|(
name|Scope
modifier|*
name|FnBodyScope
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
block|{
comment|// Default to ActOnDeclarator.
return|return
name|ActOnStartOfFunctionDef
argument_list|(
name|FnBodyScope
argument_list|,
name|ActOnDeclarator
argument_list|(
name|FnBodyScope
argument_list|,
name|D
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// ActOnStartOfFunctionDef - This is called at the start of a function
end_comment

begin_comment
comment|/// definition, after the FunctionDecl has already been created.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnStartOfFunctionDef
parameter_list|(
name|Scope
modifier|*
name|FnBodyScope
parameter_list|,
name|DeclPtrTy
name|D
parameter_list|)
block|{
return|return
name|D
return|;
block|}
end_function

begin_function
name|virtual
name|void
name|ActOnStartOfObjCMethodDef
parameter_list|(
name|Scope
modifier|*
name|FnBodyScope
parameter_list|,
name|DeclPtrTy
name|D
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/// ActOnFinishFunctionBody - This is called when a function body has
end_comment

begin_comment
comment|/// completed parsing.  Decl is returned by ParseStartOfFunctionDef.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnFinishFunctionBody
parameter_list|(
name|DeclPtrTy
name|Decl
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
block|{
return|return
name|Decl
return|;
block|}
end_function

begin_function
name|virtual
name|DeclPtrTy
name|ActOnFileScopeAsmDecl
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|ExprArg
name|AsmString
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnPopScope - This callback is called immediately before the specified
end_comment

begin_comment
comment|/// scope is popped and deleted.
end_comment

begin_function
name|virtual
name|void
name|ActOnPopScope
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|)
block|{}
end_function

begin_comment
comment|/// ActOnTranslationUnitScope - This callback is called once, immediately
end_comment

begin_comment
comment|/// after creating the translation unit scope (in Parser::Initialize).
end_comment

begin_function
name|virtual
name|void
name|ActOnTranslationUnitScope
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|)
block|{}
end_function

begin_comment
comment|/// ParsedFreeStandingDeclSpec - This method is invoked when a declspec with
end_comment

begin_comment
comment|/// no declarator (e.g. "struct foo;") is parsed.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ParsedFreeStandingDeclSpec
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclSpec
modifier|&
name|DS
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnStartLinkageSpecification - Parsed the beginning of a C++
end_comment

begin_comment
comment|/// linkage specification, including the language and (if present)
end_comment

begin_comment
comment|/// the '{'. ExternLoc is the location of the 'extern', LangLoc is
end_comment

begin_comment
comment|/// the location of the language string literal, which is provided
end_comment

begin_comment
comment|/// by Lang/StrSize. LBraceLoc, if valid, provides the location of
end_comment

begin_comment
comment|/// the '{' brace. Otherwise, this linkage specification does not
end_comment

begin_comment
comment|/// have any braces.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnStartLinkageSpecification
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|ExternLoc
parameter_list|,
name|SourceLocation
name|LangLoc
parameter_list|,
specifier|const
name|char
modifier|*
name|Lang
parameter_list|,
name|unsigned
name|StrSize
parameter_list|,
name|SourceLocation
name|LBraceLoc
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnFinishLinkageSpecification - Completely the definition of
end_comment

begin_comment
comment|/// the C++ linkage specification LinkageSpec. If RBraceLoc is
end_comment

begin_comment
comment|/// valid, it's the position of the closing '}' brace in a linkage
end_comment

begin_comment
comment|/// specification that uses braces.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnFinishLinkageSpecification
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|LinkageSpec
parameter_list|,
name|SourceLocation
name|RBraceLoc
parameter_list|)
block|{
return|return
name|LinkageSpec
return|;
block|}
end_function

begin_comment
comment|/// ActOnEndOfTranslationUnit - This is called at the very end of the
end_comment

begin_comment
comment|/// translation unit when EOF is reached and all but the top-level scope is
end_comment

begin_comment
comment|/// popped.
end_comment

begin_function
name|virtual
name|void
name|ActOnEndOfTranslationUnit
parameter_list|()
block|{}
end_function

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Type Parsing Callbacks.
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// ActOnTypeName - A type-name (type-id in C++) was parsed.
end_comment

begin_function
name|virtual
name|TypeResult
name|ActOnTypeName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
block|{
return|return
name|TypeResult
argument_list|()
return|;
block|}
end_function

begin_enum
enum|enum
name|TagUseKind
block|{
name|TUK_Reference
block|,
comment|// Reference to a tag:  'struct foo *X;'
name|TUK_Declaration
block|,
comment|// Fwd decl of a tag:   'struct foo;'
name|TUK_Definition
block|,
comment|// Definition of a tag: 'struct foo { int X; } Y;'
name|TUK_Friend
comment|// Friend declaration:  'friend struct foo;'
block|}
enum|;
end_enum

begin_comment
comment|/// \brief The parser has encountered a tag (e.g., "class X") that should be
end_comment

begin_comment
comment|/// turned into a declaration by the action module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which this tag occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TagSpec an instance of DeclSpec::TST, indicating what kind of tag
end_comment

begin_comment
comment|/// this is (struct/union/enum/class).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TUK how the tag we have encountered is being used, which
end_comment

begin_comment
comment|/// can be a reference to a (possibly pre-existing) tag, a
end_comment

begin_comment
comment|/// declaration of that tag, or the beginning of a definition of
end_comment

begin_comment
comment|/// that tag.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param KWLoc the location of the "struct", "class", "union", or "enum"
end_comment

begin_comment
comment|/// keyword.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS C++ scope specifier that precedes the name of the tag, e.g.,
end_comment

begin_comment
comment|/// the "std::" in "class std::type_info".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Name the name of the tag, e.g., "X" in "struct X". This parameter
end_comment

begin_comment
comment|/// may be NULL, to indicate an anonymous class/struct/union/enum type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NameLoc the location of the name of the tag.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Attr the set of attributes that appertain to the tag.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param AS when this tag occurs within a C++ class, provides the
end_comment

begin_comment
comment|/// current access specifier (AS_public, AS_private, AS_protected).
end_comment

begin_comment
comment|/// Otherwise, it will be AS_none.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateParameterLists the set of C++ template parameter lists
end_comment

begin_comment
comment|/// that apply to this tag, if the tag is a declaration or definition (see
end_comment

begin_comment
comment|/// the \p TK parameter). The action module is responsible for determining,
end_comment

begin_comment
comment|/// based on the template parameter lists and the scope specifier, whether
end_comment

begin_comment
comment|/// the declared tag is a class template or not.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OwnedDecl the callee should set this flag true when the returned
end_comment

begin_comment
comment|/// declaration is "owned" by this reference. Ownership is handled entirely
end_comment

begin_comment
comment|/// by the action module.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the declaration to which this tag refers.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnTag
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|TagUseKind
name|TUK
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|,
name|bool
modifier|&
name|OwnedDecl
parameter_list|,
name|bool
modifier|&
name|IsDependent
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// Acts on a reference to a dependent tag name.  This arises in
end_comment

begin_comment
comment|/// cases like:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///    template<class T> class A;
end_comment

begin_comment
comment|///    template<class T> class B {
end_comment

begin_comment
comment|///      friend class A<T>::M;  // here
end_comment

begin_comment
comment|///    };
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TagSpec an instance of DeclSpec::TST corresponding to the
end_comment

begin_comment
comment|/// tag specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TUK the tag use kind (either TUK_Friend or TUK_Reference)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS the scope specifier (always defined)
end_comment

begin_function
name|virtual
name|TypeResult
name|ActOnDependentTag
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|TagUseKind
name|TUK
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|)
block|{
return|return
name|TypeResult
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// Act on @defs() element found when parsing a structure.  ClassName is the
end_comment

begin_comment
comment|/// name of the referenced class.
end_comment

begin_decl_stmt
name|virtual
name|void
name|ActOnDefs
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|DeclPtrTy
name|TagD
argument_list|,
name|SourceLocation
name|DeclStart
argument_list|,
name|IdentifierInfo
operator|*
name|ClassName
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|DeclPtrTy
operator|>
operator|&
name|Decls
argument_list|)
block|{}
end_decl_stmt

begin_function
name|virtual
name|DeclPtrTy
name|ActOnField
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|TagD
parameter_list|,
name|SourceLocation
name|DeclStart
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|ExprTy
modifier|*
name|BitfieldWidth
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|virtual
name|DeclPtrTy
name|ActOnIvar
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|DeclStart
argument_list|,
name|DeclPtrTy
name|IntfDecl
argument_list|,
name|Declarator
operator|&
name|D
argument_list|,
name|ExprTy
operator|*
name|BitfieldWidth
argument_list|,
name|tok
operator|::
name|ObjCKeywordKind
name|visibility
argument_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|virtual
name|void
name|ActOnFields
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|RecLoc
parameter_list|,
name|DeclPtrTy
name|TagDecl
parameter_list|,
name|DeclPtrTy
modifier|*
name|Fields
parameter_list|,
name|unsigned
name|NumFields
parameter_list|,
name|SourceLocation
name|LBrac
parameter_list|,
name|SourceLocation
name|RBrac
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
block|{}
end_function

begin_comment
comment|/// ActOnTagStartDefinition - Invoked when we have entered the
end_comment

begin_comment
comment|/// scope of a tag's definition (e.g., for an enumeration, class,
end_comment

begin_comment
comment|/// struct, or union).
end_comment

begin_function
name|virtual
name|void
name|ActOnTagStartDefinition
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|TagDecl
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// ActOnTagFinishDefinition - Invoked once we have finished parsing
end_comment

begin_comment
comment|/// the definition of a tag (enumeration, class, struct, or union).
end_comment

begin_function
name|virtual
name|void
name|ActOnTagFinishDefinition
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|TagDecl
parameter_list|,
name|SourceLocation
name|RBraceLoc
parameter_list|)
block|{ }
end_function

begin_function
name|virtual
name|DeclPtrTy
name|ActOnEnumConstant
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|EnumDecl
parameter_list|,
name|DeclPtrTy
name|LastEnumConstant
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|ExprTy
modifier|*
name|Val
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|void
name|ActOnEnumBody
parameter_list|(
name|SourceLocation
name|EnumLoc
parameter_list|,
name|SourceLocation
name|LBraceLoc
parameter_list|,
name|SourceLocation
name|RBraceLoc
parameter_list|,
name|DeclPtrTy
name|EnumDecl
parameter_list|,
name|DeclPtrTy
modifier|*
name|Elements
parameter_list|,
name|unsigned
name|NumElements
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
block|{}
end_function

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Statement Parsing Callbacks.
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_function
name|virtual
name|OwningStmtResult
name|ActOnNullStmt
parameter_list|(
name|SourceLocation
name|SemiLoc
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnCompoundStmt
parameter_list|(
name|SourceLocation
name|L
parameter_list|,
name|SourceLocation
name|R
parameter_list|,
name|MultiStmtArg
name|Elts
parameter_list|,
name|bool
name|isStmtExpr
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnDeclStmt
parameter_list|(
name|DeclGroupPtrTy
name|Decl
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|SourceLocation
name|EndLoc
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnExprStmt
parameter_list|(
name|FullExprArg
name|Expr
parameter_list|)
block|{
return|return
name|OwningStmtResult
argument_list|(
operator|*
name|this
argument_list|,
name|Expr
operator|->
name|release
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// ActOnCaseStmt - Note that this handles the GNU 'case 1 ... 4' extension,
end_comment

begin_comment
comment|/// which can specify an RHS value.  The sub-statement of the case is
end_comment

begin_comment
comment|/// specified in a separate action.
end_comment

begin_function
name|virtual
name|OwningStmtResult
name|ActOnCaseStmt
parameter_list|(
name|SourceLocation
name|CaseLoc
parameter_list|,
name|ExprArg
name|LHSVal
parameter_list|,
name|SourceLocation
name|DotDotDotLoc
parameter_list|,
name|ExprArg
name|RHSVal
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnCaseStmtBody - This installs a statement as the body of a case.
end_comment

begin_function
name|virtual
name|void
name|ActOnCaseStmtBody
parameter_list|(
name|StmtTy
modifier|*
name|CaseStmt
parameter_list|,
name|StmtArg
name|SubStmt
parameter_list|)
block|{}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnDefaultStmt
parameter_list|(
name|SourceLocation
name|DefaultLoc
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|StmtArg
name|SubStmt
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnLabelStmt
parameter_list|(
name|SourceLocation
name|IdentLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|StmtArg
name|SubStmt
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnIfStmt
parameter_list|(
name|SourceLocation
name|IfLoc
parameter_list|,
name|FullExprArg
name|CondVal
parameter_list|,
name|StmtArg
name|ThenVal
parameter_list|,
name|SourceLocation
name|ElseLoc
parameter_list|,
name|StmtArg
name|ElseVal
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnStartOfSwitchStmt
parameter_list|(
name|ExprArg
name|Cond
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnFinishSwitchStmt
parameter_list|(
name|SourceLocation
name|SwitchLoc
parameter_list|,
name|StmtArg
name|Switch
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnWhileStmt
parameter_list|(
name|SourceLocation
name|WhileLoc
parameter_list|,
name|FullExprArg
name|Cond
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnDoStmt
parameter_list|(
name|SourceLocation
name|DoLoc
parameter_list|,
name|StmtArg
name|Body
parameter_list|,
name|SourceLocation
name|WhileLoc
parameter_list|,
name|SourceLocation
name|CondLParen
parameter_list|,
name|ExprArg
name|Cond
parameter_list|,
name|SourceLocation
name|CondRParen
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnForStmt
parameter_list|(
name|SourceLocation
name|ForLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|StmtArg
name|First
parameter_list|,
name|ExprArg
name|Second
parameter_list|,
name|ExprArg
name|Third
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnObjCForCollectionStmt
parameter_list|(
name|SourceLocation
name|ForColLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|StmtArg
name|First
parameter_list|,
name|ExprArg
name|Second
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnGotoStmt
parameter_list|(
name|SourceLocation
name|GotoLoc
parameter_list|,
name|SourceLocation
name|LabelLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|LabelII
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnIndirectGotoStmt
parameter_list|(
name|SourceLocation
name|GotoLoc
parameter_list|,
name|SourceLocation
name|StarLoc
parameter_list|,
name|ExprArg
name|DestExp
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnContinueStmt
parameter_list|(
name|SourceLocation
name|ContinueLoc
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnBreakStmt
parameter_list|(
name|SourceLocation
name|GotoLoc
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnReturnStmt
parameter_list|(
name|SourceLocation
name|ReturnLoc
parameter_list|,
name|ExprArg
name|RetValExp
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|virtual
name|OwningStmtResult
name|ActOnAsmStmt
argument_list|(
name|SourceLocation
name|AsmLoc
argument_list|,
name|bool
name|IsSimple
argument_list|,
name|bool
name|IsVolatile
argument_list|,
name|unsigned
name|NumOutputs
argument_list|,
name|unsigned
name|NumInputs
argument_list|,
name|std
operator|::
name|string
operator|*
name|Names
argument_list|,
name|MultiExprArg
name|Constraints
argument_list|,
name|MultiExprArg
name|Exprs
argument_list|,
name|ExprArg
name|AsmString
argument_list|,
name|MultiExprArg
name|Clobbers
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|// Objective-c statements
end_comment

begin_function
name|virtual
name|OwningStmtResult
name|ActOnObjCAtCatchStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|,
name|DeclPtrTy
name|Parm
parameter_list|,
name|StmtArg
name|Body
parameter_list|,
name|StmtArg
name|CatchList
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnObjCAtFinallyStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|StmtArg
name|Body
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnObjCAtTryStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|StmtArg
name|Try
parameter_list|,
name|StmtArg
name|Catch
parameter_list|,
name|StmtArg
name|Finally
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnObjCAtThrowStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|ExprArg
name|Throw
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnObjCAtSynchronizedStmt
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|ExprArg
name|SynchExpr
parameter_list|,
name|StmtArg
name|SynchBody
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// C++ Statements
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnExceptionDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnCXXCatchBlock
parameter_list|(
name|SourceLocation
name|CatchLoc
parameter_list|,
name|DeclPtrTy
name|ExceptionDecl
parameter_list|,
name|StmtArg
name|HandlerBlock
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningStmtResult
name|ActOnCXXTryBlock
parameter_list|(
name|SourceLocation
name|TryLoc
parameter_list|,
name|StmtArg
name|TryBlock
parameter_list|,
name|MultiStmtArg
name|Handlers
parameter_list|)
block|{
return|return
name|StmtEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Expression Parsing Callbacks.
end_comment

begin_comment
comment|//===--------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \brief Describes how the expressions currently being parsed are
end_comment

begin_comment
comment|/// evaluated at run-time, if at all.
end_comment

begin_enum
enum|enum
name|ExpressionEvaluationContext
block|{
comment|/// \brief The current expression and its subexpressions occur within an
comment|/// unevaluated operand (C++0x [expr]p8), such as a constant expression
comment|/// or the subexpression of \c sizeof, where the type or the value of the
comment|/// expression may be significant but no code will be generated to evaluate
comment|/// the value of the expression at run time.
name|Unevaluated
block|,
comment|/// \brief The current expression is potentially evaluated at run time,
comment|/// which means that code may be generated to evaluate the value of the
comment|/// expression at run time.
name|PotentiallyEvaluated
block|,
comment|/// \brief The current expression may be potentially evaluated or it may
comment|/// be unevaluated, but it is impossible to tell from the lexical context.
comment|/// This evaluation context is used primary for the operand of the C++
comment|/// \c typeid expression, whose argument is potentially evaluated only when
comment|/// it is an lvalue of polymorphic class type (C++ [basic.def.odr]p2).
name|PotentiallyPotentiallyEvaluated
block|}
enum|;
end_enum

begin_comment
comment|/// \brief The parser is entering a new expression evaluation context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NewContext is the new expression evaluation context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the previous expression evaluation context.
end_comment

begin_function
name|virtual
name|ExpressionEvaluationContext
name|PushExpressionEvaluationContext
parameter_list|(
name|ExpressionEvaluationContext
name|NewContext
parameter_list|)
block|{
return|return
name|PotentiallyEvaluated
return|;
block|}
end_function

begin_comment
comment|/// \brief The parser is existing an expression evaluation context.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OldContext the expression evaluation context that the parser is
end_comment

begin_comment
comment|/// leaving.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NewContext the expression evaluation context that the parser is
end_comment

begin_comment
comment|/// returning to.
end_comment

begin_function
name|virtual
name|void
name|PopExpressionEvaluationContext
parameter_list|(
name|ExpressionEvaluationContext
name|OldContext
parameter_list|,
name|ExpressionEvaluationContext
name|NewContext
parameter_list|)
block|{ }
end_function

begin_comment
comment|// Primary Expressions.
end_comment

begin_comment
comment|/// \brief Retrieve the source range that corresponds to the given
end_comment

begin_comment
comment|/// expression.
end_comment

begin_decl_stmt
name|virtual
name|SourceRange
name|getExprRange
argument_list|(
name|ExprTy
operator|*
name|E
argument_list|)
decl|const
block|{
return|return
name|SourceRange
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Parsed an id-expression (C++) or identifier (C) in expression
end_comment

begin_comment
comment|/// context, e.g., the expression "x" that refers to a variable named "x".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which this id-expression or identifier occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS the C++ nested-name-specifier that qualifies the name of the
end_comment

begin_comment
comment|/// value, e.g., "std::" in "std::sort".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Name the name to which the id-expression refers. In C, this will
end_comment

begin_comment
comment|/// always be an identifier. In C++, it may also be an overloaded operator,
end_comment

begin_comment
comment|/// destructor name (if there is a nested-name-specifier), or template-id.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param HasTrailingLParen whether the next token following the
end_comment

begin_comment
comment|/// id-expression or identifier is a left parentheses ('(').
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IsAddressOfOperand whether the token that precedes this
end_comment

begin_comment
comment|/// id-expression or identifier was an ampersand ('&'), indicating that
end_comment

begin_comment
comment|/// we will be taking the address of this expression.
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnIdExpression
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|,
name|bool
name|HasTrailingLParen
parameter_list|,
name|bool
name|IsAddressOfOperand
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnPredefinedExpr
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|virtual
name|OwningExprResult
name|ActOnCharacterConstant
parameter_list|(
specifier|const
name|Token
modifier|&
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningExprResult
name|ActOnNumericConstant
parameter_list|(
specifier|const
name|Token
modifier|&
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnStringLiteral - The specified tokens were lexed as pasted string
end_comment

begin_comment
comment|/// fragments (e.g. "foo" "bar" L"baz").
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnStringLiteral
parameter_list|(
specifier|const
name|Token
modifier|*
name|Toks
parameter_list|,
name|unsigned
name|NumToks
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningExprResult
name|ActOnParenExpr
parameter_list|(
name|SourceLocation
name|L
parameter_list|,
name|SourceLocation
name|R
parameter_list|,
name|ExprArg
name|Val
parameter_list|)
block|{
return|return
name|move
argument_list|(
name|Val
argument_list|)
return|;
comment|// Default impl returns operand.
block|}
end_function

begin_function
name|virtual
name|OwningExprResult
name|ActOnParenListExpr
parameter_list|(
name|SourceLocation
name|L
parameter_list|,
name|SourceLocation
name|R
parameter_list|,
name|MultiExprArg
name|Val
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Postfix Expressions.
end_comment

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnPostfixUnaryOp
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|,
name|ExprArg
name|Input
argument_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|virtual
name|OwningExprResult
name|ActOnArraySubscriptExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprArg
name|Base
parameter_list|,
name|SourceLocation
name|LLoc
parameter_list|,
name|ExprArg
name|Idx
parameter_list|,
name|SourceLocation
name|RLoc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Parsed a member access expresion (C99 6.5.2.3, C++ [expr.ref])
end_comment

begin_comment
comment|/// of the form \c x.m or \c p->m.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the member access expression occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Base the class or pointer to class into which this member
end_comment

begin_comment
comment|/// access expression refers, e.g., \c x in \c x.m.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OpLoc the location of the "." or "->" operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OpKind the kind of member access operator, which will be either
end_comment

begin_comment
comment|/// tok::arrow ("->") or tok::period (".").
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS in C++, the nested-name-specifier that precedes the member
end_comment

begin_comment
comment|/// name, if any.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Member the name of the member that we are referring to. In C,
end_comment

begin_comment
comment|/// this will always store an identifier; in C++, we may also have operator
end_comment

begin_comment
comment|/// names, conversion function names, destructors, and template names.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ObjCImpDecl the Objective-C implementation declaration.
end_comment

begin_comment
comment|/// FIXME: Do we really need this?
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param HasTrailingLParen whether this member name is immediately followed
end_comment

begin_comment
comment|/// by a left parentheses ('(').
end_comment

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnMemberAccessExpr
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|ExprArg
name|Base
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|OpKind
argument_list|,
specifier|const
name|CXXScopeSpec
operator|&
name|SS
argument_list|,
name|UnqualifiedId
operator|&
name|Member
argument_list|,
name|DeclPtrTy
name|ObjCImpDecl
argument_list|,
name|bool
name|HasTrailingLParen
argument_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// ActOnCallExpr - Handle a call to Fn with the specified array of arguments.
end_comment

begin_comment
comment|/// This provides the location of the left/right parens and a list of comma
end_comment

begin_comment
comment|/// locations.  There are guaranteed to be one fewer commas than arguments,
end_comment

begin_comment
comment|/// unless there are zero arguments.
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnCallExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprArg
name|Fn
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|MultiExprArg
name|Args
parameter_list|,
name|SourceLocation
modifier|*
name|CommaLocs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// Unary Operators.  'Tok' is the token for the operator.
end_comment

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnUnaryOp
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Op
argument_list|,
name|ExprArg
name|Input
argument_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|virtual
name|OwningExprResult
name|ActOnSizeOfAlignOfExpr
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|isSizeof
parameter_list|,
name|bool
name|isType
parameter_list|,
name|void
modifier|*
name|TyOrEx
parameter_list|,
specifier|const
name|SourceRange
modifier|&
name|ArgRange
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningExprResult
name|ActOnCompoundLiteral
parameter_list|(
name|SourceLocation
name|LParen
parameter_list|,
name|TypeTy
modifier|*
name|Ty
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|,
name|ExprArg
name|Op
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningExprResult
name|ActOnInitList
parameter_list|(
name|SourceLocation
name|LParenLoc
parameter_list|,
name|MultiExprArg
name|InitList
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// @brief Parsed a C99 designated initializer.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Desig Contains the designation with one or more designators.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Loc The location of the '=' or ':' prior to the
end_comment

begin_comment
comment|/// initialization expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param GNUSyntax If true, then this designated initializer used
end_comment

begin_comment
comment|/// the deprecated GNU syntax @c fieldname:foo or @c [expr]foo rather
end_comment

begin_comment
comment|/// than the C99 syntax @c .fieldname=foo or @c [expr]=foo.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Init The value that the entity (or entities) described by
end_comment

begin_comment
comment|/// the designation will be initialized with.
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnDesignatedInitializer
parameter_list|(
name|Designation
modifier|&
name|Desig
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|bool
name|GNUSyntax
parameter_list|,
name|OwningExprResult
name|Init
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningExprResult
name|ActOnCastExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|TypeTy
modifier|*
name|Ty
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|,
name|ExprArg
name|Op
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnBinOp
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|TokLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|,
name|ExprArg
name|LHS
argument_list|,
name|ExprArg
name|RHS
argument_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// ActOnConditionalOp - Parse a ?: operation.  Note that 'LHS' may be null
end_comment

begin_comment
comment|/// in the case of a the GNU conditional expr extension.
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnConditionalOp
parameter_list|(
name|SourceLocation
name|QuestionLoc
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|ExprArg
name|Cond
parameter_list|,
name|ExprArg
name|LHS
parameter_list|,
name|ExprArg
name|RHS
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|//===---------------------- GNU Extension Expressions -------------------===//
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnAddrLabel
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|SourceLocation
name|LabLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|LabelII
parameter_list|)
block|{
comment|// "&&foo"
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningExprResult
name|ActOnStmtExpr
parameter_list|(
name|SourceLocation
name|LPLoc
parameter_list|,
name|StmtArg
name|SubStmt
parameter_list|,
name|SourceLocation
name|RPLoc
parameter_list|)
block|{
comment|// "({..})"
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// __builtin_offsetof(type, identifier(.identifier|[expr])*)
end_comment

begin_struct
struct|struct
name|OffsetOfComponent
block|{
name|SourceLocation
name|LocStart
decl_stmt|,
name|LocEnd
decl_stmt|;
name|bool
name|isBrackets
decl_stmt|;
comment|// true if [expr], false if .ident
union|union
block|{
name|IdentifierInfo
modifier|*
name|IdentInfo
decl_stmt|;
name|ExprTy
modifier|*
name|E
decl_stmt|;
block|}
name|U
union|;
block|}
struct|;
end_struct

begin_function
name|virtual
name|OwningExprResult
name|ActOnBuiltinOffsetOf
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|SourceLocation
name|TypeLoc
parameter_list|,
name|TypeTy
modifier|*
name|Arg1
parameter_list|,
name|OffsetOfComponent
modifier|*
name|CompPtr
parameter_list|,
name|unsigned
name|NumComponents
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// __builtin_types_compatible_p(type1, type2)
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnTypesCompatibleExpr
parameter_list|(
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|TypeTy
modifier|*
name|arg1
parameter_list|,
name|TypeTy
modifier|*
name|arg2
parameter_list|,
name|SourceLocation
name|RPLoc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// __builtin_choose_expr(constExpr, expr1, expr2)
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnChooseExpr
parameter_list|(
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|ExprArg
name|cond
parameter_list|,
name|ExprArg
name|expr1
parameter_list|,
name|ExprArg
name|expr2
parameter_list|,
name|SourceLocation
name|RPLoc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// __builtin_va_arg(expr, type)
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnVAArg
parameter_list|(
name|SourceLocation
name|BuiltinLoc
parameter_list|,
name|ExprArg
name|expr
parameter_list|,
name|TypeTy
modifier|*
name|type
parameter_list|,
name|SourceLocation
name|RPLoc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnGNUNullExpr - Parsed the GNU __null expression, the token
end_comment

begin_comment
comment|/// for which is at position TokenLoc.
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnGNUNullExpr
parameter_list|(
name|SourceLocation
name|TokenLoc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|//===------------------------- "Block" Extension ------------------------===//
end_comment

begin_comment
comment|/// ActOnBlockStart - This callback is invoked when a block literal is
end_comment

begin_comment
comment|/// started.  The result pointer is passed into the block finalizers.
end_comment

begin_function
name|virtual
name|void
name|ActOnBlockStart
parameter_list|(
name|SourceLocation
name|CaretLoc
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
block|{}
end_function

begin_comment
comment|/// ActOnBlockArguments - This callback allows processing of block arguments.
end_comment

begin_comment
comment|/// If there are no arguments, this is still invoked.
end_comment

begin_function
name|virtual
name|void
name|ActOnBlockArguments
parameter_list|(
name|Declarator
modifier|&
name|ParamInfo
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
block|{}
end_function

begin_comment
comment|/// ActOnBlockError - If there is an error parsing a block, this callback
end_comment

begin_comment
comment|/// is invoked to pop the information about the block from the action impl.
end_comment

begin_function
name|virtual
name|void
name|ActOnBlockError
parameter_list|(
name|SourceLocation
name|CaretLoc
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
block|{}
end_function

begin_comment
comment|/// ActOnBlockStmtExpr - This is called when the body of a block statement
end_comment

begin_comment
comment|/// literal was successfully completed.  ^(int x){...}
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnBlockStmtExpr
parameter_list|(
name|SourceLocation
name|CaretLoc
parameter_list|,
name|StmtArg
name|Body
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|//===------------------------- C++ Declarations -------------------------===//
end_comment

begin_comment
comment|/// ActOnStartNamespaceDef - This is called at the start of a namespace
end_comment

begin_comment
comment|/// definition.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnStartNamespaceDef
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|IdentLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Ident
parameter_list|,
name|SourceLocation
name|LBrace
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnFinishNamespaceDef - This callback is called after a namespace is
end_comment

begin_comment
comment|/// exited. Decl is returned by ActOnStartNamespaceDef.
end_comment

begin_function
name|virtual
name|void
name|ActOnFinishNamespaceDef
parameter_list|(
name|DeclPtrTy
name|Dcl
parameter_list|,
name|SourceLocation
name|RBrace
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/// ActOnUsingDirective - This is called when using-directive is parsed.
end_comment

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnUsingDirective
parameter_list|(
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|SourceLocation
name|UsingLoc
parameter_list|,
name|SourceLocation
name|NamespcLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|IdentLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|NamespcName
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnNamespaceAliasDef - This is called when a namespace alias definition
end_comment

begin_comment
comment|/// is parsed.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnNamespaceAliasDef
parameter_list|(
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|SourceLocation
name|NamespaceLoc
parameter_list|,
name|SourceLocation
name|AliasLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Alias
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|IdentLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Ident
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnUsingDirective - This is called when using-directive is parsed.
end_comment

begin_function_decl
name|virtual
name|DeclPtrTy
name|ActOnUsingDeclaration
parameter_list|(
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|SourceLocation
name|UsingLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|IdentLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|TargetName
parameter_list|,
name|OverloadedOperatorKind
name|Op
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|,
name|bool
name|IsTypeName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ActOnParamDefaultArgument - Parse default argument for function parameter
end_comment

begin_function
name|virtual
name|void
name|ActOnParamDefaultArgument
parameter_list|(
name|DeclPtrTy
name|param
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|ExprArg
name|defarg
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnParamUnparsedDefaultArgument - We've seen a default
end_comment

begin_comment
comment|/// argument for a function parameter, but we can't parse it yet
end_comment

begin_comment
comment|/// because we're inside a class definition. Note that this default
end_comment

begin_comment
comment|/// argument will be parsed later.
end_comment

begin_function
name|virtual
name|void
name|ActOnParamUnparsedDefaultArgument
parameter_list|(
name|DeclPtrTy
name|param
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|SourceLocation
name|ArgLoc
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// ActOnParamDefaultArgumentError - Parsing or semantic analysis of
end_comment

begin_comment
comment|/// the default argument for the parameter param failed.
end_comment

begin_function
name|virtual
name|void
name|ActOnParamDefaultArgumentError
parameter_list|(
name|DeclPtrTy
name|param
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// AddCXXDirectInitializerToDecl - This action is called immediately after
end_comment

begin_comment
comment|/// ActOnDeclarator, when a C++ direct initializer is present.
end_comment

begin_comment
comment|/// e.g: "int x(1);"
end_comment

begin_function
name|virtual
name|void
name|AddCXXDirectInitializerToDecl
parameter_list|(
name|DeclPtrTy
name|Dcl
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|MultiExprArg
name|Exprs
parameter_list|,
name|SourceLocation
modifier|*
name|CommaLocs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/// \brief Called when we re-enter a template parameter scope.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This action occurs when we are going to parse an member
end_comment

begin_comment
comment|/// function's default arguments or inline definition after the
end_comment

begin_comment
comment|/// outermost class definition has been completed, and when one or
end_comment

begin_comment
comment|/// more of the class definitions enclosing the member function is a
end_comment

begin_comment
comment|/// template. The "entity" in the given scope will be set as it was
end_comment

begin_comment
comment|/// when we entered the scope of the template initially, and should
end_comment

begin_comment
comment|/// be used to, e.g., reintroduce the names of template parameters
end_comment

begin_comment
comment|/// into the current scope so that they can be found by name lookup.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S The (new) template parameter scope.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Template the class template declaration whose template
end_comment

begin_comment
comment|/// parameters should be reintroduced into the current scope.
end_comment

begin_function
name|virtual
name|void
name|ActOnReenterTemplateScope
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Template
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnStartDelayedCXXMethodDeclaration - We have completed
end_comment

begin_comment
comment|/// parsing a top-level (non-nested) C++ class, and we are now
end_comment

begin_comment
comment|/// parsing those parts of the given Method declaration that could
end_comment

begin_comment
comment|/// not be parsed earlier (C++ [class.mem]p2), such as default
end_comment

begin_comment
comment|/// arguments. This action should enter the scope of the given
end_comment

begin_comment
comment|/// Method declaration as if we had just parsed the qualified method
end_comment

begin_comment
comment|/// name. However, it should not bring the parameters into scope;
end_comment

begin_comment
comment|/// that will be performed by ActOnDelayedCXXMethodParameter.
end_comment

begin_function
name|virtual
name|void
name|ActOnStartDelayedCXXMethodDeclaration
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Method
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnDelayedCXXMethodParameter - We've already started a delayed
end_comment

begin_comment
comment|/// C++ method declaration. We're (re-)introducing the given
end_comment

begin_comment
comment|/// function parameter into scope for use in parsing later parts of
end_comment

begin_comment
comment|/// the method declaration. For example, we could see an
end_comment

begin_comment
comment|/// ActOnParamDefaultArgument event for this parameter.
end_comment

begin_function
name|virtual
name|void
name|ActOnDelayedCXXMethodParameter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Param
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnFinishDelayedCXXMethodDeclaration - We have finished
end_comment

begin_comment
comment|/// processing the delayed method declaration for Method. The method
end_comment

begin_comment
comment|/// declaration is now considered finished. There may be a separate
end_comment

begin_comment
comment|/// ActOnStartOfFunctionDef action later (not necessarily
end_comment

begin_comment
comment|/// immediately!) for this method, if it was also defined inside the
end_comment

begin_comment
comment|/// class body.
end_comment

begin_function
name|virtual
name|void
name|ActOnFinishDelayedCXXMethodDeclaration
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|DeclPtrTy
name|Method
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnStaticAssertDeclaration - Parse a C++0x static_assert declaration.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnStaticAssertDeclaration
parameter_list|(
name|SourceLocation
name|AssertLoc
parameter_list|,
name|ExprArg
name|AssertExpr
parameter_list|,
name|ExprArg
name|AssertMessageExpr
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnFriendFunctionDecl - Parsed a friend function declarator.
end_comment

begin_comment
comment|/// The name is actually a slight misnomer, because the declarator
end_comment

begin_comment
comment|/// is not necessarily a function declarator.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnFriendFunctionDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|bool
name|IsDefinition
parameter_list|,
name|MultiTemplateParamsArg
name|TParams
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnFriendTypeDecl - Parsed a friend type declaration.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnFriendTypeDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|DeclSpec
modifier|&
name|DS
parameter_list|,
name|MultiTemplateParamsArg
name|TParams
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|//===------------------------- C++ Expressions --------------------------===//
end_comment

begin_comment
comment|/// ActOnCXXNamedCast - Parse {dynamic,static,reinterpret,const}_cast's.
end_comment

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnCXXNamedCast
argument_list|(
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|,
name|SourceLocation
name|LAngleBracketLoc
argument_list|,
name|TypeTy
operator|*
name|Ty
argument_list|,
name|SourceLocation
name|RAngleBracketLoc
argument_list|,
name|SourceLocation
name|LParenLoc
argument_list|,
name|ExprArg
name|Op
argument_list|,
name|SourceLocation
name|RParenLoc
argument_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// ActOnCXXTypeidOfType - Parse typeid( type-id ).
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnCXXTypeid
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|bool
name|isType
parameter_list|,
name|void
modifier|*
name|TyOrExpr
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnCXXThis - Parse the C++ 'this' pointer.
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnCXXThis
parameter_list|(
name|SourceLocation
name|ThisLoc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnCXXBoolLiteral - Parse {true,false} literals.
end_comment

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnCXXBoolLiteral
argument_list|(
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// ActOnCXXNullPtrLiteral - Parse 'nullptr'.
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnCXXNullPtrLiteral
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnCXXThrow - Parse throw expressions.
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnCXXThrow
parameter_list|(
name|SourceLocation
name|OpLoc
parameter_list|,
name|ExprArg
name|Op
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnCXXTypeConstructExpr - Parse construction of a specified type.
end_comment

begin_comment
comment|/// Can be interpreted either as function-style casting ("int(x)")
end_comment

begin_comment
comment|/// or class type construction ("ClassType(x,y,z)")
end_comment

begin_comment
comment|/// or creation of a value-initialized type ("int()").
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnCXXTypeConstructExpr
parameter_list|(
name|SourceRange
name|TypeRange
parameter_list|,
name|TypeTy
modifier|*
name|TypeRep
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|MultiExprArg
name|Exprs
parameter_list|,
name|SourceLocation
modifier|*
name|CommaLocs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnCXXConditionDeclarationExpr - Parsed a condition declaration of a
end_comment

begin_comment
comment|/// C++ if/switch/while/for statement.
end_comment

begin_comment
comment|/// e.g: "if (int x = f()) {...}"
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnCXXConditionDeclarationExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|StartLoc
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|ExprArg
name|AssignExprVal
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnCXXNew - Parsed a C++ 'new' expression. UseGlobal is true if the
end_comment

begin_comment
comment|/// new was qualified (::new). In a full new like
end_comment

begin_comment
comment|/// @code new (p1, p2) type(c1, c2) @endcode
end_comment

begin_comment
comment|/// the p1 and p2 expressions will be in PlacementArgs and the c1 and c2
end_comment

begin_comment
comment|/// expressions in ConstructorArgs. The type is passed as a declarator.
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnCXXNew
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|bool
name|UseGlobal
parameter_list|,
name|SourceLocation
name|PlacementLParen
parameter_list|,
name|MultiExprArg
name|PlacementArgs
parameter_list|,
name|SourceLocation
name|PlacementRParen
parameter_list|,
name|bool
name|ParenTypeId
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|SourceLocation
name|ConstructorLParen
parameter_list|,
name|MultiExprArg
name|ConstructorArgs
parameter_list|,
name|SourceLocation
name|ConstructorRParen
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnCXXDelete - Parsed a C++ 'delete' expression. UseGlobal is true if
end_comment

begin_comment
comment|/// the delete was qualified (::delete). ArrayForm is true if the array form
end_comment

begin_comment
comment|/// was used (delete[]).
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnCXXDelete
parameter_list|(
name|SourceLocation
name|StartLoc
parameter_list|,
name|bool
name|UseGlobal
parameter_list|,
name|bool
name|ArrayForm
parameter_list|,
name|ExprArg
name|Operand
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|OwningExprResult
name|ActOnUnaryTypeTrait
parameter_list|(
name|UnaryTypeTrait
name|OTT
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
name|SourceLocation
name|LParen
parameter_list|,
name|TypeTy
modifier|*
name|Ty
parameter_list|,
name|SourceLocation
name|RParen
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Invoked when the parser is starting to parse a C++ member access
end_comment

begin_comment
comment|/// expression such as x.f or x->f.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the member access expression occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Base the expression in which a member is being accessed, e.g., the
end_comment

begin_comment
comment|/// "x" in "x.f".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OpLoc the location of the member access operator ("." or "->")
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OpKind the kind of member access operator ("." or "->")
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ObjectType originally NULL. The action should fill in this type
end_comment

begin_comment
comment|/// with the type into which name lookup should look to find the member in
end_comment

begin_comment
comment|/// the member access expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \returns the (possibly modified) \p Base expression
end_comment

begin_decl_stmt
name|virtual
name|OwningExprResult
name|ActOnStartCXXMemberReference
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|ExprArg
name|Base
argument_list|,
name|SourceLocation
name|OpLoc
argument_list|,
name|tok
operator|::
name|TokenKind
name|OpKind
argument_list|,
name|TypeTy
operator|*
operator|&
name|ObjectType
argument_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// ActOnFinishFullExpr - Called whenever a full expression has been parsed.
end_comment

begin_comment
comment|/// (C++ [intro.execution]p12).
end_comment

begin_function
name|virtual
name|OwningExprResult
name|ActOnFinishFullExpr
parameter_list|(
name|ExprArg
name|Expr
parameter_list|)
block|{
return|return
name|move
argument_list|(
name|Expr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|//===---------------------------- C++ Classes ---------------------------===//
end_comment

begin_comment
comment|/// ActOnBaseSpecifier - Parsed a base specifier
end_comment

begin_function
name|virtual
name|BaseResult
name|ActOnBaseSpecifier
parameter_list|(
name|DeclPtrTy
name|classdecl
parameter_list|,
name|SourceRange
name|SpecifierRange
parameter_list|,
name|bool
name|Virtual
parameter_list|,
name|AccessSpecifier
name|Access
parameter_list|,
name|TypeTy
modifier|*
name|basetype
parameter_list|,
name|SourceLocation
name|BaseLoc
parameter_list|)
block|{
return|return
name|BaseResult
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|void
name|ActOnBaseSpecifiers
parameter_list|(
name|DeclPtrTy
name|ClassDecl
parameter_list|,
name|BaseTy
modifier|*
modifier|*
name|Bases
parameter_list|,
name|unsigned
name|NumBases
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnCXXMemberDeclarator - This is invoked when a C++ class member
end_comment

begin_comment
comment|/// declarator is parsed. 'AS' is the access specifier, 'BitfieldWidth'
end_comment

begin_comment
comment|/// specifies the bitfield width if there is one and 'Init' specifies the
end_comment

begin_comment
comment|/// initializer if any.  'Deleted' is true if there's a =delete
end_comment

begin_comment
comment|/// specifier on the function.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnCXXMemberDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|,
name|ExprTy
modifier|*
name|BitfieldWidth
parameter_list|,
name|ExprTy
modifier|*
name|Init
parameter_list|,
name|bool
name|Deleted
init|=
name|false
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|MemInitResult
name|ActOnMemInitializer
parameter_list|(
name|DeclPtrTy
name|ConstructorDecl
parameter_list|,
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|IdentifierInfo
modifier|*
name|MemberOrBase
parameter_list|,
name|TypeTy
modifier|*
name|TemplateTypeTy
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|ExprTy
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|,
name|SourceLocation
modifier|*
name|CommaLocs
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/// ActOnMemInitializers - This is invoked when all of the member
end_comment

begin_comment
comment|/// initializers of a constructor have been parsed. ConstructorDecl
end_comment

begin_comment
comment|/// is the function declaration (which will be a C++ constructor in
end_comment

begin_comment
comment|/// a well-formed program), ColonLoc is the location of the ':' that
end_comment

begin_comment
comment|/// starts the constructor initializer, and MemInit/NumMemInits
end_comment

begin_comment
comment|/// contains the individual member (and base) initializers.
end_comment

begin_function
name|virtual
name|void
name|ActOnMemInitializers
parameter_list|(
name|DeclPtrTy
name|ConstructorDecl
parameter_list|,
name|SourceLocation
name|ColonLoc
parameter_list|,
name|MemInitTy
modifier|*
modifier|*
name|MemInits
parameter_list|,
name|unsigned
name|NumMemInits
parameter_list|)
block|{   }
end_function

begin_function
name|virtual
name|void
name|ActOnDefaultCtorInitializers
parameter_list|(
name|DeclPtrTy
name|CDtorDecl
parameter_list|)
block|{}
end_function

begin_comment
comment|/// ActOnFinishCXXMemberSpecification - Invoked after all member declarators
end_comment

begin_comment
comment|/// are parsed but *before* parsing of inline method definitions.
end_comment

begin_function
name|virtual
name|void
name|ActOnFinishCXXMemberSpecification
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|RLoc
parameter_list|,
name|DeclPtrTy
name|TagDecl
parameter_list|,
name|SourceLocation
name|LBrac
parameter_list|,
name|SourceLocation
name|RBrac
parameter_list|)
block|{   }
end_function

begin_comment
comment|//===---------------------------C++ Templates----------------------------===//
end_comment

begin_comment
comment|/// ActOnTypeParameter - Called when a C++ template type parameter
end_comment

begin_comment
comment|/// (e.g., "typename T") has been parsed. Typename specifies whether
end_comment

begin_comment
comment|/// the keyword "typename" was used to declare the type parameter
end_comment

begin_comment
comment|/// (otherwise, "class" was used), ellipsis specifies whether this is a
end_comment

begin_comment
comment|/// C++0x parameter pack, EllipsisLoc specifies the start of the ellipsis,
end_comment

begin_comment
comment|/// and KeyLoc is the location of the "class" or "typename" keyword.
end_comment

begin_comment
comment|//  ParamName is the name of the parameter (NULL indicates an unnamed template
end_comment

begin_comment
comment|//  parameter) and ParamNameLoc is the location of the parameter name (if any)
end_comment

begin_comment
comment|/// If the type parameter has a default argument, it will be added
end_comment

begin_comment
comment|/// later via ActOnTypeParameterDefault. Depth and Position provide
end_comment

begin_comment
comment|/// the number of enclosing templates (see
end_comment

begin_comment
comment|/// ActOnTemplateParameterList) and the number of previous
end_comment

begin_comment
comment|/// parameters within this template parameter list.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnTypeParameter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|bool
name|Typename
parameter_list|,
name|bool
name|Ellipsis
parameter_list|,
name|SourceLocation
name|EllipsisLoc
parameter_list|,
name|SourceLocation
name|KeyLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|ParamName
parameter_list|,
name|SourceLocation
name|ParamNameLoc
parameter_list|,
name|unsigned
name|Depth
parameter_list|,
name|unsigned
name|Position
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnTypeParameterDefault - Adds a default argument (the type
end_comment

begin_comment
comment|/// Default) to the given template type parameter (TypeParam).
end_comment

begin_function
name|virtual
name|void
name|ActOnTypeParameterDefault
parameter_list|(
name|DeclPtrTy
name|TypeParam
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|SourceLocation
name|DefaultLoc
parameter_list|,
name|TypeTy
modifier|*
name|Default
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnNonTypeTemplateParameter - Called when a C++ non-type
end_comment

begin_comment
comment|/// template parameter (e.g., "int Size" in "template<int Size>
end_comment

begin_comment
comment|/// class Array") has been parsed. S is the current scope and D is
end_comment

begin_comment
comment|/// the parsed declarator. Depth and Position provide the number of
end_comment

begin_comment
comment|/// enclosing templates (see
end_comment

begin_comment
comment|/// ActOnTemplateParameterList) and the number of previous
end_comment

begin_comment
comment|/// parameters within this template parameter list.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnNonTypeTemplateParameter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|,
name|unsigned
name|Depth
parameter_list|,
name|unsigned
name|Position
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds a default argument to the given non-type template
end_comment

begin_comment
comment|/// parameter.
end_comment

begin_function
name|virtual
name|void
name|ActOnNonTypeTemplateParameterDefault
parameter_list|(
name|DeclPtrTy
name|TemplateParam
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|ExprArg
name|Default
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnTemplateTemplateParameter - Called when a C++ template template
end_comment

begin_comment
comment|/// parameter (e.g., "int T" in "template<template<typename> class T> class
end_comment

begin_comment
comment|/// Array") has been parsed. TmpLoc is the location of the "template" keyword,
end_comment

begin_comment
comment|/// TemplateParams is the sequence of parameters required by the template,
end_comment

begin_comment
comment|/// ParamName is the name of the parameter (null if unnamed), and ParamNameLoc
end_comment

begin_comment
comment|/// is the source location of the identifier (if given).
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnTemplateTemplateParameter
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|TmpLoc
parameter_list|,
name|TemplateParamsTy
modifier|*
name|Params
parameter_list|,
name|IdentifierInfo
modifier|*
name|ParamName
parameter_list|,
name|SourceLocation
name|ParamNameLoc
parameter_list|,
name|unsigned
name|Depth
parameter_list|,
name|unsigned
name|Position
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Adds a default argument to the given template template
end_comment

begin_comment
comment|/// parameter.
end_comment

begin_function
name|virtual
name|void
name|ActOnTemplateTemplateParameterDefault
parameter_list|(
name|DeclPtrTy
name|TemplateParam
parameter_list|,
name|SourceLocation
name|EqualLoc
parameter_list|,
name|ExprArg
name|Default
parameter_list|)
block|{   }
end_function

begin_comment
comment|/// ActOnTemplateParameterList - Called when a complete template
end_comment

begin_comment
comment|/// parameter list has been parsed, e.g.,
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// export template<typename T, T Size>
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Depth is the number of enclosing template parameter lists. This
end_comment

begin_comment
comment|/// value does not include templates from outer scopes. For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// template<typename T> // depth = 0
end_comment

begin_comment
comment|///   class A {
end_comment

begin_comment
comment|///     template<typename U> // depth = 0
end_comment

begin_comment
comment|///       class B;
end_comment

begin_comment
comment|///   };
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// template<typename T> // depth = 0
end_comment

begin_comment
comment|///   template<typename U> // depth = 1
end_comment

begin_comment
comment|///     class A<T>::B { ... };
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ExportLoc, if valid, is the position of the "export"
end_comment

begin_comment
comment|/// keyword. Otherwise, "export" was not specified.
end_comment

begin_comment
comment|/// TemplateLoc is the position of the template keyword, LAngleLoc
end_comment

begin_comment
comment|/// is the position of the left angle bracket, and RAngleLoc is the
end_comment

begin_comment
comment|/// position of the corresponding right angle bracket.
end_comment

begin_comment
comment|/// Params/NumParams provides the template parameters that were
end_comment

begin_comment
comment|/// parsed as part of the template-parameter-list.
end_comment

begin_function
name|virtual
name|TemplateParamsTy
modifier|*
name|ActOnTemplateParameterList
parameter_list|(
name|unsigned
name|Depth
parameter_list|,
name|SourceLocation
name|ExportLoc
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|SourceLocation
name|LAngleLoc
parameter_list|,
name|DeclPtrTy
modifier|*
name|Params
parameter_list|,
name|unsigned
name|NumParams
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/// \brief Form a type from a template and a list of template
end_comment

begin_comment
comment|/// arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This action merely forms the type for the template-id, possibly
end_comment

begin_comment
comment|/// checking well-formedness of the template arguments. It does not
end_comment

begin_comment
comment|/// imply the declaration of any entity.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Template  A template whose specialization results in a
end_comment

begin_comment
comment|/// type, e.g., a class template or template template parameter.
end_comment

begin_function
name|virtual
name|TypeResult
name|ActOnTemplateIdType
parameter_list|(
name|TemplateTy
name|Template
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|SourceLocation
name|LAngleLoc
parameter_list|,
name|ASTTemplateArgsPtr
name|TemplateArgs
parameter_list|,
name|SourceLocation
modifier|*
name|TemplateArgLocs
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|)
block|{
return|return
name|TypeResult
argument_list|()
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Note that a template ID was used with a tag.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Type The result of ActOnTemplateIdType.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TUK Either TUK_Reference or TUK_Friend.  Declarations and
end_comment

begin_comment
comment|/// definitions are interpreted as explicit instantiations or
end_comment

begin_comment
comment|/// specializations.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TagSpec The tag keyword that was provided as part of the
end_comment

begin_comment
comment|/// elaborated-type-specifier;  either class, struct, union, or enum.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TagLoc The location of the tag keyword.
end_comment

begin_decl_stmt
name|virtual
name|TypeResult
name|ActOnTagTemplateIdType
argument_list|(
name|TypeResult
name|Type
argument_list|,
name|TagUseKind
name|TUK
argument_list|,
name|DeclSpec
operator|::
name|TST
name|TagSpec
argument_list|,
name|SourceLocation
name|TagLoc
argument_list|)
block|{
return|return
name|TypeResult
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Form a dependent template name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This action forms a dependent template name given the template
end_comment

begin_comment
comment|/// name and its (presumably dependent) scope specifier. For
end_comment

begin_comment
comment|/// example, given "MetaFun::template apply", the scope specifier \p
end_comment

begin_comment
comment|/// SS will be "MetaFun::", \p TemplateKWLoc contains the location
end_comment

begin_comment
comment|/// of the "template" keyword, and "apply" is the \p Name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateKWLoc the location of the "template" keyword (if any).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS the nested-name-specifier that precedes the "template" keyword
end_comment

begin_comment
comment|/// or the template name. If the dependent template name occurs in
end_comment

begin_comment
comment|/// a member access expression, e.g., "x.template f<T>", this
end_comment

begin_comment
comment|/// nested-name-specifier will be empty.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Name the name of the template.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ObjectType if this dependent template name occurs in the
end_comment

begin_comment
comment|/// context of a member access expression, the type of the object being
end_comment

begin_comment
comment|/// accessed.
end_comment

begin_function
name|virtual
name|TemplateTy
name|ActOnDependentTemplateName
parameter_list|(
name|SourceLocation
name|TemplateKWLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|UnqualifiedId
modifier|&
name|Name
parameter_list|,
name|TypeTy
modifier|*
name|ObjectType
parameter_list|)
block|{
return|return
name|TemplateTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Process the declaration or definition of an explicit
end_comment

begin_comment
comment|/// class template specialization or a class template partial
end_comment

begin_comment
comment|/// specialization.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine is invoked when an explicit class template
end_comment

begin_comment
comment|/// specialization or a class template partial specialization is
end_comment

begin_comment
comment|/// declared or defined, to introduce the (partial) specialization
end_comment

begin_comment
comment|/// and produce a declaration for it. In the following example,
end_comment

begin_comment
comment|/// ActOnClassTemplateSpecialization will be invoked for the
end_comment

begin_comment
comment|/// declarations at both A and B:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template<typename T> class X;
end_comment

begin_comment
comment|/// template<> class X<int> { }; // A: explicit specialization
end_comment

begin_comment
comment|/// template<typename T> class X<T*> { }; // B: partial specialization
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that it is the job of semantic analysis to determine which
end_comment

begin_comment
comment|/// of the two cases actually occurred in the source code, since
end_comment

begin_comment
comment|/// they are parsed through the same path. The formulation of the
end_comment

begin_comment
comment|/// template parameter lists describes which case we are in.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the current scope
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TagSpec whether this declares a class, struct, or union
end_comment

begin_comment
comment|/// (template)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TUK whether this is a declaration or a definition
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param KWLoc the location of the 'class', 'struct', or 'union'
end_comment

begin_comment
comment|/// keyword.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS the scope specifier preceding the template-id
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Template the declaration of the class template that we
end_comment

begin_comment
comment|/// are specializing.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Attr attributes on the specialization
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateParameterLists the set of template parameter
end_comment

begin_comment
comment|/// lists that apply to this declaration. In a well-formed program,
end_comment

begin_comment
comment|/// the number of template parameter lists will be one more than the
end_comment

begin_comment
comment|/// number of template-ids in the scope specifier. However, it is
end_comment

begin_comment
comment|/// common for users to provide the wrong number of template
end_comment

begin_comment
comment|/// parameter lists (such as a missing \c template<> prior to a
end_comment

begin_comment
comment|/// specialization); the parser does not check this condition.
end_comment

begin_function
name|virtual
name|DeclResult
name|ActOnClassTemplateSpecialization
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|TagUseKind
name|TUK
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|TemplateTy
name|Template
parameter_list|,
name|SourceLocation
name|TemplateNameLoc
parameter_list|,
name|SourceLocation
name|LAngleLoc
parameter_list|,
name|ASTTemplateArgsPtr
name|TemplateArgs
parameter_list|,
name|SourceLocation
modifier|*
name|TemplateArgLocs
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|)
block|{
return|return
name|DeclResult
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Invoked when a declarator that has one or more template parameter
end_comment

begin_comment
comment|/// lists has been parsed.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This action is similar to ActOnDeclarator(), except that the declaration
end_comment

begin_comment
comment|/// being created somehow involves a template, e.g., it is a template
end_comment

begin_comment
comment|/// declaration or specialization.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnTemplateDeclarator
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Invoked when the parser is beginning to parse a function template
end_comment

begin_comment
comment|/// or function template specialization definition.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnStartOfFunctionTemplateDef
parameter_list|(
name|Scope
modifier|*
name|FnBodyScope
parameter_list|,
name|MultiTemplateParamsArg
name|TemplateParameterLists
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Process the explicit instantiation of a class template
end_comment

begin_comment
comment|/// specialization.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine is invoked when an explicit instantiation of a
end_comment

begin_comment
comment|/// class template specialization is encountered. In the following
end_comment

begin_comment
comment|/// example, ActOnExplicitInstantiation will be invoked to force the
end_comment

begin_comment
comment|/// instantiation of X<int>:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template<typename T> class X { /* ... */ };
end_comment

begin_comment
comment|/// template class X<int>; // explicit instantiation
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the current scope
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ExternLoc the location of the 'extern' keyword that specifies that
end_comment

begin_comment
comment|/// this is an extern template (if any).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateLoc the location of the 'template' keyword that
end_comment

begin_comment
comment|/// specifies that this is an explicit instantiation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TagSpec whether this declares a class, struct, or union
end_comment

begin_comment
comment|/// (template).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param KWLoc the location of the 'class', 'struct', or 'union'
end_comment

begin_comment
comment|/// keyword.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS the scope specifier preceding the template-id.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Template the declaration of the class template that we
end_comment

begin_comment
comment|/// are instantiation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param LAngleLoc the location of the '<' token in the template-id.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateArgs the template arguments used to form the
end_comment

begin_comment
comment|/// template-id.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateArgLocs the locations of the template arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param RAngleLoc the location of the '>' token in the template-id.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Attr attributes that apply to this instantiation.
end_comment

begin_function
name|virtual
name|DeclResult
name|ActOnExplicitInstantiation
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|ExternLoc
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|TemplateTy
name|Template
parameter_list|,
name|SourceLocation
name|TemplateNameLoc
parameter_list|,
name|SourceLocation
name|LAngleLoc
parameter_list|,
name|ASTTemplateArgsPtr
name|TemplateArgs
parameter_list|,
name|SourceLocation
modifier|*
name|TemplateArgLocs
parameter_list|,
name|SourceLocation
name|RAngleLoc
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|)
block|{
return|return
name|DeclResult
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Process the explicit instantiation of a member class of a
end_comment

begin_comment
comment|/// class template specialization.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine is invoked when an explicit instantiation of a
end_comment

begin_comment
comment|/// member class of a class template specialization is
end_comment

begin_comment
comment|/// encountered. In the following example,
end_comment

begin_comment
comment|/// ActOnExplicitInstantiation will be invoked to force the
end_comment

begin_comment
comment|/// instantiation of X<int>::Inner:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template<typename T> class X { class Inner { /* ... */}; };
end_comment

begin_comment
comment|/// template class X<int>::Inner; // explicit instantiation
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the current scope
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ExternLoc the location of the 'extern' keyword that specifies that
end_comment

begin_comment
comment|/// this is an extern template (if any).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateLoc the location of the 'template' keyword that
end_comment

begin_comment
comment|/// specifies that this is an explicit instantiation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TagSpec whether this declares a class, struct, or union
end_comment

begin_comment
comment|/// (template).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param KWLoc the location of the 'class', 'struct', or 'union'
end_comment

begin_comment
comment|/// keyword.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS the scope specifier preceding the template-id.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Template the declaration of the class template that we
end_comment

begin_comment
comment|/// are instantiation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param LAngleLoc the location of the '<' token in the template-id.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateArgs the template arguments used to form the
end_comment

begin_comment
comment|/// template-id.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateArgLocs the locations of the template arguments.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param RAngleLoc the location of the '>' token in the template-id.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Attr attributes that apply to this instantiation.
end_comment

begin_function
name|virtual
name|DeclResult
name|ActOnExplicitInstantiation
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|ExternLoc
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|,
name|SourceLocation
name|KWLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|SourceLocation
name|NameLoc
parameter_list|,
name|AttributeList
modifier|*
name|Attr
parameter_list|)
block|{
return|return
name|DeclResult
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Process the explicit instantiation of a function template or a
end_comment

begin_comment
comment|/// member of a class template.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This routine is invoked when an explicit instantiation of a
end_comment

begin_comment
comment|/// function template or member function of a class template specialization
end_comment

begin_comment
comment|/// is encountered. In the following example,
end_comment

begin_comment
comment|/// ActOnExplicitInstantiation will be invoked to force the
end_comment

begin_comment
comment|/// instantiation of X<int>:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// template<typename T> void f(T);
end_comment

begin_comment
comment|/// template void f(int); // explicit instantiation
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the current scope
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param ExternLoc the location of the 'extern' keyword that specifies that
end_comment

begin_comment
comment|/// this is an extern template (if any).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TemplateLoc the location of the 'template' keyword that
end_comment

begin_comment
comment|/// specifies that this is an explicit instantiation.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param D the declarator describing the declaration to be implicitly
end_comment

begin_comment
comment|/// instantiated.
end_comment

begin_function
name|virtual
name|DeclResult
name|ActOnExplicitInstantiation
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|SourceLocation
name|ExternLoc
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|Declarator
modifier|&
name|D
parameter_list|)
block|{
return|return
name|DeclResult
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Called when the parser has parsed a C++ typename
end_comment

begin_comment
comment|/// specifier that ends in an identifier, e.g., "typename T::type".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TypenameLoc the location of the 'typename' keyword
end_comment

begin_comment
comment|/// \param SS the nested-name-specifier following the typename (e.g., 'T::').
end_comment

begin_comment
comment|/// \param II the identifier we're retrieving (e.g., 'type' in the example).
end_comment

begin_comment
comment|/// \param IdLoc the location of the identifier.
end_comment

begin_function
name|virtual
name|TypeResult
name|ActOnTypenameType
parameter_list|(
name|SourceLocation
name|TypenameLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
specifier|const
name|IdentifierInfo
modifier|&
name|II
parameter_list|,
name|SourceLocation
name|IdLoc
parameter_list|)
block|{
return|return
name|TypeResult
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Called when the parser has parsed a C++ typename
end_comment

begin_comment
comment|/// specifier that ends in a template-id, e.g.,
end_comment

begin_comment
comment|/// "typename MetaFun::template apply<T1, T2>".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TypenameLoc the location of the 'typename' keyword
end_comment

begin_comment
comment|/// \param SS the nested-name-specifier following the typename (e.g., 'T::').
end_comment

begin_comment
comment|/// \param TemplateLoc the location of the 'template' keyword, if any.
end_comment

begin_comment
comment|/// \param Ty the type that the typename specifier refers to.
end_comment

begin_function
name|virtual
name|TypeResult
name|ActOnTypenameType
parameter_list|(
name|SourceLocation
name|TypenameLoc
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|SourceLocation
name|TemplateLoc
parameter_list|,
name|TypeTy
modifier|*
name|Ty
parameter_list|)
block|{
return|return
name|TypeResult
argument_list|()
return|;
block|}
end_function

begin_comment
comment|//===----------------------- Obj-C Declarations -------------------------===//
end_comment

begin_comment
comment|// ActOnStartClassInterface - this action is called immediately after parsing
end_comment

begin_comment
comment|// the prologue for a class interface (before parsing the instance
end_comment

begin_comment
comment|// variables). Instance variables are processed by ActOnFields().
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnStartClassInterface
parameter_list|(
name|SourceLocation
name|AtInterfaceLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|SuperName
parameter_list|,
name|SourceLocation
name|SuperLoc
parameter_list|,
specifier|const
name|DeclPtrTy
modifier|*
name|ProtoRefs
parameter_list|,
name|unsigned
name|NumProtoRefs
parameter_list|,
name|SourceLocation
name|EndProtoLoc
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// ActOnCompatiblityAlias - this action is called after complete parsing of
end_comment

begin_comment
comment|/// @compaatibility_alias declaration. It sets up the alias relationships.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnCompatiblityAlias
parameter_list|(
name|SourceLocation
name|AtCompatibilityAliasLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|AliasName
parameter_list|,
name|SourceLocation
name|AliasLocation
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassLocation
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// ActOnStartProtocolInterface - this action is called immdiately after
end_comment

begin_comment
comment|// parsing the prologue for a protocol interface.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnStartProtocolInterface
parameter_list|(
name|SourceLocation
name|AtProtoLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|ProtocolName
parameter_list|,
name|SourceLocation
name|ProtocolLoc
parameter_list|,
specifier|const
name|DeclPtrTy
modifier|*
name|ProtoRefs
parameter_list|,
name|unsigned
name|NumProtoRefs
parameter_list|,
name|SourceLocation
name|EndProtoLoc
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// ActOnStartCategoryInterface - this action is called immdiately after
end_comment

begin_comment
comment|// parsing the prologue for a category interface.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnStartCategoryInterface
parameter_list|(
name|SourceLocation
name|AtInterfaceLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|CategoryName
parameter_list|,
name|SourceLocation
name|CategoryLoc
parameter_list|,
specifier|const
name|DeclPtrTy
modifier|*
name|ProtoRefs
parameter_list|,
name|unsigned
name|NumProtoRefs
parameter_list|,
name|SourceLocation
name|EndProtoLoc
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// ActOnStartClassImplementation - this action is called immdiately after
end_comment

begin_comment
comment|// parsing the prologue for a class implementation. Instance variables are
end_comment

begin_comment
comment|// processed by ActOnFields().
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnStartClassImplementation
parameter_list|(
name|SourceLocation
name|AtClassImplLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|SuperClassname
parameter_list|,
name|SourceLocation
name|SuperClassLoc
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// ActOnStartCategoryImplementation - this action is called immdiately after
end_comment

begin_comment
comment|// parsing the prologue for a category implementation.
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnStartCategoryImplementation
parameter_list|(
name|SourceLocation
name|AtCatImplLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|ClassName
parameter_list|,
name|SourceLocation
name|ClassLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|CatName
parameter_list|,
name|SourceLocation
name|CatLoc
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// ActOnPropertyImplDecl - called for every property implementation
end_comment

begin_function
name|virtual
name|DeclPtrTy
name|ActOnPropertyImplDecl
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
comment|// location of the @synthesize/@dynamic
name|SourceLocation
name|PropertyNameLoc
parameter_list|,
comment|// location for the property name
name|bool
name|ImplKind
parameter_list|,
comment|// true for @synthesize, false for
comment|// @dynamic
name|DeclPtrTy
name|ClassImplDecl
parameter_list|,
comment|// class or category implementation
name|IdentifierInfo
modifier|*
name|propertyId
parameter_list|,
comment|// name of property
name|IdentifierInfo
modifier|*
name|propertyIvar
parameter_list|)
block|{
comment|// name of the ivar
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_struct
struct|struct
name|ObjCArgInfo
block|{
name|IdentifierInfo
modifier|*
name|Name
decl_stmt|;
name|SourceLocation
name|NameLoc
decl_stmt|;
comment|// The Type is null if no type was specified, and the DeclSpec is invalid
comment|// in this case.
name|TypeTy
modifier|*
name|Type
decl_stmt|;
name|ObjCDeclSpec
name|DeclSpec
decl_stmt|;
comment|/// ArgAttrs - Attribute list for this argument.
name|AttributeList
modifier|*
name|ArgAttrs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// ActOnMethodDeclaration - called for all method declarations.
end_comment

begin_decl_stmt
name|virtual
name|DeclPtrTy
name|ActOnMethodDeclaration
argument_list|(
name|SourceLocation
name|BeginLoc
argument_list|,
comment|// location of the + or -.
name|SourceLocation
name|EndLoc
argument_list|,
comment|// location of the ; or {.
name|tok
operator|::
name|TokenKind
name|MethodType
argument_list|,
comment|// tok::minus for instance, tok::plus for class.
name|DeclPtrTy
name|ClassDecl
argument_list|,
comment|// class this methods belongs to.
name|ObjCDeclSpec
operator|&
name|ReturnQT
argument_list|,
comment|// for return type's in inout etc.
name|TypeTy
operator|*
name|ReturnType
argument_list|,
comment|// the method return type.
name|Selector
name|Sel
argument_list|,
comment|// a unique name for the method.
name|ObjCArgInfo
operator|*
name|ArgInfo
argument_list|,
comment|// ArgInfo: Has 'Sel.getNumArgs()' entries.
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|Declarator
operator|>
operator|&
name|Cdecls
argument_list|,
comment|// c-style args
name|AttributeList
operator|*
name|MethodAttrList
argument_list|,
comment|// optional
comment|// tok::objc_not_keyword, tok::objc_optional, tok::objc_required
name|tok
operator|::
name|ObjCKeywordKind
name|impKind
argument_list|,
name|bool
name|isVariadic
operator|=
name|false
argument_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|// ActOnAtEnd - called to mark the @end. For declarations (interfaces,
end_comment

begin_comment
comment|// protocols, categories), the parser passes all methods/properties.
end_comment

begin_comment
comment|// For class implementations, these values default to 0. For implementations,
end_comment

begin_comment
comment|// methods are processed incrementally (by ActOnMethodDeclaration above).
end_comment

begin_function
name|virtual
name|void
name|ActOnAtEnd
parameter_list|(
name|SourceLocation
name|AtEndLoc
parameter_list|,
name|DeclPtrTy
name|classDecl
parameter_list|,
name|DeclPtrTy
modifier|*
name|allMethods
init|=
literal|0
parameter_list|,
name|unsigned
name|allNum
init|=
literal|0
parameter_list|,
name|DeclPtrTy
modifier|*
name|allProperties
init|=
literal|0
parameter_list|,
name|unsigned
name|pNum
init|=
literal|0
parameter_list|,
name|DeclGroupPtrTy
modifier|*
name|allTUVars
init|=
literal|0
parameter_list|,
name|unsigned
name|tuvNum
init|=
literal|0
parameter_list|)
block|{   }
end_function

begin_comment
comment|// ActOnProperty - called to build one property AST
end_comment

begin_decl_stmt
name|virtual
name|DeclPtrTy
name|ActOnProperty
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|SourceLocation
name|AtLoc
argument_list|,
name|FieldDeclarator
operator|&
name|FD
argument_list|,
name|ObjCDeclSpec
operator|&
name|ODS
argument_list|,
name|Selector
name|GetterSel
argument_list|,
name|Selector
name|SetterSel
argument_list|,
name|DeclPtrTy
name|ClassCategory
argument_list|,
name|bool
operator|*
name|OverridingProperty
argument_list|,
name|tok
operator|::
name|ObjCKeywordKind
name|MethodImplKind
argument_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|virtual
name|OwningExprResult
name|ActOnClassPropertyRefExpr
parameter_list|(
name|IdentifierInfo
modifier|&
name|receiverName
parameter_list|,
name|IdentifierInfo
modifier|&
name|propertyName
parameter_list|,
name|SourceLocation
modifier|&
name|receiverNameLoc
parameter_list|,
name|SourceLocation
modifier|&
name|propertyNameLoc
parameter_list|)
block|{
return|return
name|ExprEmpty
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// ActOnClassMessage - used for both unary and keyword messages.
end_comment

begin_comment
comment|// ArgExprs is optional - if it is present, the number of expressions
end_comment

begin_comment
comment|// is obtained from NumArgs.
end_comment

begin_function
name|virtual
name|ExprResult
name|ActOnClassMessage
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|IdentifierInfo
modifier|*
name|receivingClassName
parameter_list|,
name|Selector
name|Sel
parameter_list|,
name|SourceLocation
name|lbrac
parameter_list|,
name|SourceLocation
name|receiverLoc
parameter_list|,
name|SourceLocation
name|selectorLoc
parameter_list|,
name|SourceLocation
name|rbrac
parameter_list|,
name|ExprTy
modifier|*
modifier|*
name|ArgExprs
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|)
block|{
return|return
name|ExprResult
argument_list|()
return|;
block|}
end_function

begin_comment
comment|// ActOnInstanceMessage - used for both unary and keyword messages.
end_comment

begin_comment
comment|// ArgExprs is optional - if it is present, the number of expressions
end_comment

begin_comment
comment|// is obtained from NumArgs.
end_comment

begin_function
name|virtual
name|ExprResult
name|ActOnInstanceMessage
parameter_list|(
name|ExprTy
modifier|*
name|receiver
parameter_list|,
name|Selector
name|Sel
parameter_list|,
name|SourceLocation
name|lbrac
parameter_list|,
name|SourceLocation
name|selectorLoc
parameter_list|,
name|SourceLocation
name|rbrac
parameter_list|,
name|ExprTy
modifier|*
modifier|*
name|ArgExprs
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|)
block|{
return|return
name|ExprResult
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|DeclPtrTy
name|ActOnForwardClassDeclaration
parameter_list|(
name|SourceLocation
name|AtClassLoc
parameter_list|,
name|IdentifierInfo
modifier|*
modifier|*
name|IdentList
parameter_list|,
name|unsigned
name|NumElts
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|DeclPtrTy
name|ActOnForwardProtocolDeclaration
parameter_list|(
name|SourceLocation
name|AtProtocolLoc
parameter_list|,
specifier|const
name|IdentifierLocPair
modifier|*
name|IdentList
parameter_list|,
name|unsigned
name|NumElts
parameter_list|,
name|AttributeList
modifier|*
name|AttrList
parameter_list|)
block|{
return|return
name|DeclPtrTy
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// FindProtocolDeclaration - This routine looks up protocols and
end_comment

begin_comment
comment|/// issues error if they are not declared. It returns list of valid
end_comment

begin_comment
comment|/// protocols found.
end_comment

begin_decl_stmt
name|virtual
name|void
name|FindProtocolDeclaration
argument_list|(
name|bool
name|WarnOnDeclarations
argument_list|,
specifier|const
name|IdentifierLocPair
operator|*
name|ProtocolId
argument_list|,
name|unsigned
name|NumProtocols
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|DeclPtrTy
operator|>
operator|&
name|ResProtos
argument_list|)
block|{   }
end_decl_stmt

begin_comment
comment|//===----------------------- Obj-C Expressions --------------------------===//
end_comment

begin_function
name|virtual
name|ExprResult
name|ParseObjCStringLiteral
parameter_list|(
name|SourceLocation
modifier|*
name|AtLocs
parameter_list|,
name|ExprTy
modifier|*
modifier|*
name|Strings
parameter_list|,
name|unsigned
name|NumStrings
parameter_list|)
block|{
return|return
name|ExprResult
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|ExprResult
name|ParseObjCEncodeExpression
parameter_list|(
name|SourceLocation
name|AtLoc
parameter_list|,
name|SourceLocation
name|EncLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|TypeTy
modifier|*
name|Ty
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return
name|ExprResult
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|ExprResult
name|ParseObjCSelectorExpression
parameter_list|(
name|Selector
name|Sel
parameter_list|,
name|SourceLocation
name|AtLoc
parameter_list|,
name|SourceLocation
name|SelLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return
name|ExprResult
argument_list|()
return|;
block|}
end_function

begin_function
name|virtual
name|ExprResult
name|ParseObjCProtocolExpression
parameter_list|(
name|IdentifierInfo
modifier|*
name|ProtocolId
parameter_list|,
name|SourceLocation
name|AtLoc
parameter_list|,
name|SourceLocation
name|ProtoLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return
name|ExprResult
argument_list|()
return|;
block|}
end_function

begin_comment
comment|//===---------------------------- Pragmas -------------------------------===//
end_comment

begin_enum
enum|enum
name|PragmaPackKind
block|{
name|PPK_Default
block|,
comment|// #pragma pack([n])
name|PPK_Show
block|,
comment|// #pragma pack(show), only supported by MSVC.
name|PPK_Push
block|,
comment|// #pragma pack(push, [identifier], [n])
name|PPK_Pop
comment|// #pragma pack(pop, [identifier], [n])
block|}
enum|;
end_enum

begin_comment
comment|/// ActOnPragmaPack - Called on well formed #pragma pack(...).
end_comment

begin_function
name|virtual
name|void
name|ActOnPragmaPack
parameter_list|(
name|PragmaPackKind
name|Kind
parameter_list|,
name|IdentifierInfo
modifier|*
name|Name
parameter_list|,
name|ExprTy
modifier|*
name|Alignment
parameter_list|,
name|SourceLocation
name|PragmaLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/// ActOnPragmaUnused - Called on well formed #pragma unused(...).
end_comment

begin_function
name|virtual
name|void
name|ActOnPragmaUnused
parameter_list|(
specifier|const
name|Token
modifier|*
name|Identifiers
parameter_list|,
name|unsigned
name|NumIdentifiers
parameter_list|,
name|Scope
modifier|*
name|CurScope
parameter_list|,
name|SourceLocation
name|PragmaLoc
parameter_list|,
name|SourceLocation
name|LParenLoc
parameter_list|,
name|SourceLocation
name|RParenLoc
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/// ActOnPragmaWeakID - Called on well formed #pragma weak ident.
end_comment

begin_function
name|virtual
name|void
name|ActOnPragmaWeakID
parameter_list|(
name|IdentifierInfo
modifier|*
name|WeakName
parameter_list|,
name|SourceLocation
name|PragmaLoc
parameter_list|,
name|SourceLocation
name|WeakNameLoc
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/// ActOnPragmaWeakAlias - Called on well formed #pragma weak ident = ident.
end_comment

begin_function
name|virtual
name|void
name|ActOnPragmaWeakAlias
parameter_list|(
name|IdentifierInfo
modifier|*
name|WeakName
parameter_list|,
name|IdentifierInfo
modifier|*
name|AliasName
parameter_list|,
name|SourceLocation
name|PragmaLoc
parameter_list|,
name|SourceLocation
name|WeakNameLoc
parameter_list|,
name|SourceLocation
name|AliasNameLoc
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/// \name Code completion actions
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These actions are used to signal that a code-completion token has been
end_comment

begin_comment
comment|/// found at a point in the grammar where the Action implementation is
end_comment

begin_comment
comment|/// likely to be able to provide a list of possible completions, e.g.,
end_comment

begin_comment
comment|/// after the "." or "->" of a member access expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \todo Code completion for designated field initializers
end_comment

begin_comment
comment|/// \todo Code completion for call arguments after a function template-id
end_comment

begin_comment
comment|/// \todo Code completion within a call expression, object construction, etc.
end_comment

begin_comment
comment|/// \todo Code completion within a template argument list.
end_comment

begin_comment
comment|/// \todo Code completion for attributes.
end_comment

begin_comment
comment|//@{
end_comment

begin_comment
comment|/// \brief Code completion for an ordinary name that occurs within the given
end_comment

begin_comment
comment|/// scope.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the name occurs.
end_comment

begin_function
name|virtual
name|void
name|CodeCompleteOrdinaryName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// \brief Code completion for a member access expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This code completion action is invoked when the code-completion token
end_comment

begin_comment
comment|/// is found after the "." or "->" of a member access expression.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the member access expression occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Base the base expression (e.g., the x in "x.foo") of the member
end_comment

begin_comment
comment|/// access.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param OpLoc the location of the "." or "->" operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param IsArrow true when the operator is "->", false when it is ".".
end_comment

begin_function
name|virtual
name|void
name|CodeCompleteMemberReferenceExpr
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprTy
modifier|*
name|Base
parameter_list|,
name|SourceLocation
name|OpLoc
parameter_list|,
name|bool
name|IsArrow
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// \brief Code completion for a reference to a tag.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This code completion action is invoked when the code-completion
end_comment

begin_comment
comment|/// token is found after a tag keyword (struct, union, enum, or class).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the tag reference occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param TagSpec an instance of DeclSpec::TST, indicating what kind of tag
end_comment

begin_comment
comment|/// this is (struct/union/enum/class).
end_comment

begin_function
name|virtual
name|void
name|CodeCompleteTag
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|unsigned
name|TagSpec
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// \brief Code completion for a case statement.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \brief S the scope in which the case statement occurs.
end_comment

begin_function
name|virtual
name|void
name|CodeCompleteCase
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// \brief Code completion for a call.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \brief S the scope in which the call occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Fn the expression describing the function being called.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param Args the arguments to the function call (so far).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param NumArgs the number of arguments in \p Args.
end_comment

begin_function
name|virtual
name|void
name|CodeCompleteCall
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ExprTy
modifier|*
name|Fn
parameter_list|,
name|ExprTy
modifier|*
modifier|*
name|Args
parameter_list|,
name|unsigned
name|NumArgs
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// \brief Code completion for a C++ nested-name-specifier that precedes a
end_comment

begin_comment
comment|/// qualified-id of some form.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This code completion action is invoked when the code-completion token
end_comment

begin_comment
comment|/// is found after the "::" of a nested-name-specifier.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the nested-name-specifier occurs.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param SS the scope specifier ending with "::".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \parame EnteringContext whether we're entering the context of this
end_comment

begin_comment
comment|/// scope specifier.
end_comment

begin_function
name|virtual
name|void
name|CodeCompleteQualifiedId
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
specifier|const
name|CXXScopeSpec
modifier|&
name|SS
parameter_list|,
name|bool
name|EnteringContext
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// \brief Code completion for a C++ "using" declaration or directive.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This code completion action is invoked when the code-completion token is
end_comment

begin_comment
comment|/// found after the "using" keyword.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the "using" occurs.
end_comment

begin_function
name|virtual
name|void
name|CodeCompleteUsing
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// \brief Code completion for a C++ using directive.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This code completion action is invoked when the code-completion token is
end_comment

begin_comment
comment|/// found after "using namespace".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the "using namespace" occurs.
end_comment

begin_function
name|virtual
name|void
name|CodeCompleteUsingDirective
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// \brief Code completion for a C++ namespace declaration or namespace
end_comment

begin_comment
comment|/// alias declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This code completion action is invoked when the code-completion token is
end_comment

begin_comment
comment|/// found after "namespace".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the "namespace" token occurs.
end_comment

begin_function
name|virtual
name|void
name|CodeCompleteNamespaceDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// \brief Code completion for a C++ namespace alias declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This code completion action is invoked when the code-completion token is
end_comment

begin_comment
comment|/// found after "namespace identifier = ".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the namespace alias declaration occurs.
end_comment

begin_function
name|virtual
name|void
name|CodeCompleteNamespaceAliasDecl
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// \brief Code completion for an operator name.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This code completion action is invoked when the code-completion token is
end_comment

begin_comment
comment|/// found after the keyword "operator".
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the operator keyword occurs.
end_comment

begin_function
name|virtual
name|void
name|CodeCompleteOperatorName
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|)
block|{ }
end_function

begin_comment
comment|/// \brief Code completion for an ObjC property decl.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This code completion action is invoked when the code-completion token is
end_comment

begin_comment
comment|/// found after the left paren.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param S the scope in which the operator keyword occurs.
end_comment

begin_function
name|virtual
name|void
name|CodeCompleteObjCProperty
parameter_list|(
name|Scope
modifier|*
name|S
parameter_list|,
name|ObjCDeclSpec
modifier|&
name|ODS
parameter_list|)
block|{ }
end_function

begin_comment
comment|//@}
end_comment

begin_comment
unit|};
comment|/// MinimalAction - Minimal actions are used by light-weight clients of the
end_comment

begin_comment
comment|/// parser that do not need name resolution or significant semantic analysis to
end_comment

begin_comment
comment|/// be performed.  The actions implemented here are in the form of unresolved
end_comment

begin_comment
comment|/// identifiers.  By using a simpler interface than the SemanticAction class,
end_comment

begin_comment
comment|/// the parser doesn't have to build complex data structures and thus runs more
end_comment

begin_comment
comment|/// quickly.
end_comment

begin_decl_stmt
name|class
name|MinimalAction
range|:
name|public
name|Action
block|{
comment|/// Translation Unit Scope - useful to Objective-C actions that need
comment|/// to lookup file scope declarations in the "ordinary" C decl namespace.
comment|/// For example, user-defined classes, built-in "id" type, etc.
name|Scope
operator|*
name|TUScope
block|;
name|IdentifierTable
operator|&
name|Idents
block|;
name|Preprocessor
operator|&
name|PP
block|;
name|void
operator|*
name|TypeNameInfoTablePtr
block|;
name|public
operator|:
name|MinimalAction
argument_list|(
name|Preprocessor
operator|&
name|pp
argument_list|)
block|;
operator|~
name|MinimalAction
argument_list|()
block|;
comment|/// getTypeName - This looks at the IdentifierInfo::FETokenInfo field to
comment|/// determine whether the name is a typedef or not in this scope.
comment|///
comment|/// \param II the identifier for which we are performing name lookup
comment|///
comment|/// \param NameLoc the location of the identifier
comment|///
comment|/// \param S the scope in which this name lookup occurs
comment|///
comment|/// \param SS if non-NULL, the C++ scope specifier that precedes the
comment|/// identifier
comment|///
comment|/// \param isClassName whether this is a C++ class-name production, in
comment|/// which we can end up referring to a member of an unknown specialization
comment|/// that we know (from the grammar) is supposed to be a type. For example,
comment|/// this occurs when deriving from "std::vector<T>::allocator_type", where T
comment|/// is a template parameter.
comment|///
comment|/// \returns the type referred to by this identifier, or NULL if the type
comment|/// does not name an identifier.
name|virtual
name|TypeTy
operator|*
name|getTypeName
argument_list|(
argument|IdentifierInfo&II
argument_list|,
argument|SourceLocation NameLoc
argument_list|,
argument|Scope *S
argument_list|,
argument|const CXXScopeSpec *SS
argument_list|,
argument|bool isClassName = false
argument_list|)
block|;
comment|/// isCurrentClassName - Always returns false, because MinimalAction
comment|/// does not support C++ classes with constructors.
name|virtual
name|bool
name|isCurrentClassName
argument_list|(
specifier|const
name|IdentifierInfo
operator|&
name|II
argument_list|,
name|Scope
operator|*
name|S
argument_list|,
specifier|const
name|CXXScopeSpec
operator|*
name|SS
argument_list|)
block|;
name|virtual
name|TemplateNameKind
name|isTemplateName
argument_list|(
argument|Scope *S
argument_list|,
argument|const CXXScopeSpec&SS
argument_list|,
argument|UnqualifiedId&Name
argument_list|,
argument|TypeTy *ObjectType
argument_list|,
argument|bool EnteringContext
argument_list|,
argument|TemplateTy&Template
argument_list|)
block|;
comment|/// ActOnDeclarator - If this is a typedef declarator, we modify the
comment|/// IdentifierInfo::FETokenInfo field to keep track of this fact, until S is
comment|/// popped.
name|virtual
name|DeclPtrTy
name|ActOnDeclarator
argument_list|(
name|Scope
operator|*
name|S
argument_list|,
name|Declarator
operator|&
name|D
argument_list|)
block|;
comment|/// ActOnPopScope - When a scope is popped, if any typedefs are now
comment|/// out-of-scope, they are removed from the IdentifierInfo::FETokenInfo field.
name|virtual
name|void
name|ActOnPopScope
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|Scope *S
argument_list|)
block|;
name|virtual
name|void
name|ActOnTranslationUnitScope
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|Scope *S
argument_list|)
block|;
name|virtual
name|DeclPtrTy
name|ActOnForwardClassDeclaration
argument_list|(
argument|SourceLocation AtClassLoc
argument_list|,
argument|IdentifierInfo **IdentList
argument_list|,
argument|unsigned NumElts
argument_list|)
block|;
name|virtual
name|DeclPtrTy
name|ActOnStartClassInterface
argument_list|(
argument|SourceLocation interLoc
argument_list|,
argument|IdentifierInfo *ClassName
argument_list|,
argument|SourceLocation ClassLoc
argument_list|,
argument|IdentifierInfo *SuperName
argument_list|,
argument|SourceLocation SuperLoc
argument_list|,
argument|const DeclPtrTy *ProtoRefs
argument_list|,
argument|unsigned NumProtoRefs
argument_list|,
argument|SourceLocation EndProtoLoc
argument_list|,
argument|AttributeList *AttrList
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// PrettyStackTraceActionsDecl - If a crash occurs in the parser while parsing
end_comment

begin_comment
comment|/// something related to a virtualized decl, include that virtualized decl in
end_comment

begin_comment
comment|/// the stack trace.
end_comment

begin_decl_stmt
name|class
name|PrettyStackTraceActionsDecl
range|:
name|public
name|llvm
operator|::
name|PrettyStackTraceEntry
block|{
name|Action
operator|::
name|DeclPtrTy
name|TheDecl
block|;
name|SourceLocation
name|Loc
block|;
name|Action
operator|&
name|Actions
block|;
name|SourceManager
operator|&
name|SM
block|;
specifier|const
name|char
operator|*
name|Message
block|;
name|public
operator|:
name|PrettyStackTraceActionsDecl
argument_list|(
argument|Action::DeclPtrTy Decl
argument_list|,
argument|SourceLocation L
argument_list|,
argument|Action&actions
argument_list|,
argument|SourceManager&sm
argument_list|,
argument|const char *Msg
argument_list|)
operator|:
name|TheDecl
argument_list|(
name|Decl
argument_list|)
block|,
name|Loc
argument_list|(
name|L
argument_list|)
block|,
name|Actions
argument_list|(
name|actions
argument_list|)
block|,
name|SM
argument_list|(
name|sm
argument_list|)
block|,
name|Message
argument_list|(
argument|Msg
argument_list|)
block|{}
name|virtual
name|void
name|print
argument_list|(
argument|llvm::raw_ostream&OS
argument_list|)
specifier|const
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief RAII object that enters a new expression evaluation context.
end_comment

begin_decl_stmt
name|class
name|EnterExpressionEvaluationContext
block|{
comment|/// \brief The action object.
name|Action
modifier|&
name|Actions
decl_stmt|;
comment|/// \brief The previous expression evaluation context.
name|Action
operator|::
name|ExpressionEvaluationContext
name|PrevContext
expr_stmt|;
comment|/// \brief The current expression evaluation context.
name|Action
operator|::
name|ExpressionEvaluationContext
name|CurContext
expr_stmt|;
name|public
label|:
name|EnterExpressionEvaluationContext
argument_list|(
argument|Action&Actions
argument_list|,
argument|Action::ExpressionEvaluationContext NewContext
argument_list|)
block|:
name|Actions
argument_list|(
name|Actions
argument_list|)
operator|,
name|CurContext
argument_list|(
argument|NewContext
argument_list|)
block|{
name|PrevContext
operator|=
name|Actions
operator|.
name|PushExpressionEvaluationContext
argument_list|(
name|NewContext
argument_list|)
block|;   }
operator|~
name|EnterExpressionEvaluationContext
argument_list|()
block|{
name|Actions
operator|.
name|PopExpressionEvaluationContext
argument_list|(
name|CurContext
argument_list|,
name|PrevContext
argument_list|)
block|;   }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

