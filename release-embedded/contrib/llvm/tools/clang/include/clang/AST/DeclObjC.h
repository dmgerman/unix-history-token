begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DeclObjC.h - Classes for representing declarations -----*- C++ -*-===//
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
comment|//  This file defines the DeclObjC interface and subclasses.
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
name|LLVM_CLANG_AST_DECLOBJC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_DECLOBJC_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/SelectorLocationsKind.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Expr
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|RecordDecl
decl_stmt|;
name|class
name|ObjCIvarDecl
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCProtocolDecl
decl_stmt|;
name|class
name|ObjCCategoryDecl
decl_stmt|;
name|class
name|ObjCPropertyDecl
decl_stmt|;
name|class
name|ObjCPropertyImplDecl
decl_stmt|;
name|class
name|CXXCtorInitializer
decl_stmt|;
name|class
name|ObjCListBase
block|{
name|ObjCListBase
argument_list|(
argument|const ObjCListBase&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|ObjCListBase
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|protected
label|:
comment|/// List is an array of pointers to objects that are not owned by this object.
name|void
modifier|*
modifier|*
name|List
decl_stmt|;
name|unsigned
name|NumElts
decl_stmt|;
name|public
label|:
name|ObjCListBase
argument_list|()
operator|:
name|List
argument_list|(
literal|0
argument_list|)
operator|,
name|NumElts
argument_list|(
literal|0
argument_list|)
block|{}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|NumElts
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|NumElts
operator|==
literal|0
return|;
block|}
name|protected
label|:
name|void
name|set
parameter_list|(
name|void
modifier|*
specifier|const
modifier|*
name|InList
parameter_list|,
name|unsigned
name|Elts
parameter_list|,
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// ObjCList - This is a simple template class used to hold various lists of
comment|/// decls etc, which is heavily used by the ObjC front-end.  This only use case
comment|/// this supports is setting the list all at once and then reading elements out
comment|/// of it.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ObjCList
operator|:
name|public
name|ObjCListBase
block|{
name|public
operator|:
name|void
name|set
argument_list|(
argument|T* const* InList
argument_list|,
argument|unsigned Elts
argument_list|,
argument|ASTContext&Ctx
argument_list|)
block|{
name|ObjCListBase
operator|::
name|set
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
specifier|const
operator|*
operator|>
operator|(
name|InList
operator|)
argument_list|,
name|Elts
argument_list|,
name|Ctx
argument_list|)
block|;   }
typedef|typedef
name|T
modifier|*
specifier|const
modifier|*
name|iterator
typedef|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
operator|(
name|iterator
operator|)
name|List
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
operator|(
name|iterator
operator|)
name|List
operator|+
name|NumElts
return|;
block|}
name|T
operator|*
name|operator
index|[]
operator|(
name|unsigned
name|Idx
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|Idx
operator|<
name|NumElts
operator|&&
literal|"Invalid access"
argument_list|)
block|;
return|return
operator|(
name|T
operator|*
operator|)
name|List
index|[
name|Idx
index|]
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief A list of Objective-C protocols, along with the source
comment|/// locations at which they were referenced.
name|class
name|ObjCProtocolList
range|:
name|public
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
block|{
name|SourceLocation
operator|*
name|Locations
block|;
name|using
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
operator|::
name|set
block|;
name|public
operator|:
name|ObjCProtocolList
argument_list|()
operator|:
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
operator|(
operator|)
block|,
name|Locations
argument_list|(
literal|0
argument_list|)
block|{ }
typedef|typedef
specifier|const
name|SourceLocation
modifier|*
name|loc_iterator
typedef|;
name|loc_iterator
name|loc_begin
argument_list|()
specifier|const
block|{
return|return
name|Locations
return|;
block|}
name|loc_iterator
name|loc_end
argument_list|()
specifier|const
block|{
return|return
name|Locations
operator|+
name|size
argument_list|()
return|;
block|}
name|void
name|set
argument_list|(
argument|ObjCProtocolDecl* const* InList
argument_list|,
argument|unsigned Elts
argument_list|,
argument|const SourceLocation *Locs
argument_list|,
argument|ASTContext&Ctx
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// ObjCMethodDecl - Represents an instance or class method declaration.
end_comment

begin_comment
comment|/// ObjC methods can be declared within 4 contexts: class interfaces,
end_comment

begin_comment
comment|/// categories, protocols, and class implementations. While C++ member
end_comment

begin_comment
comment|/// functions leverage C syntax, Objective-C method syntax is modeled after
end_comment

begin_comment
comment|/// Smalltalk (using colons to specify argument types/expressions).
end_comment

begin_comment
comment|/// Here are some brief examples:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Setter/getter instance methods:
end_comment

begin_comment
comment|/// - (void)setMenu:(NSMenu *)menu;
end_comment

begin_comment
comment|/// - (NSMenu *)menu;
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Instance method that takes 2 NSView arguments:
end_comment

begin_comment
comment|/// - (void)replaceSubview:(NSView *)oldView with:(NSView *)newView;
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Getter class method:
end_comment

begin_comment
comment|/// + (NSMenu *)defaultMenu;
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A selector represents a unique name for a method. The selector names for
end_comment

begin_comment
comment|/// the above methods are setMenu:, menu, replaceSubview:with:, and defaultMenu.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ObjCMethodDecl
range|:
name|public
name|NamedDecl
decl_stmt|,
name|public
name|DeclContext
block|{
name|public
label|:
enum|enum
name|ImplementationControl
block|{
name|None
block|,
name|Required
block|,
name|Optional
block|}
enum|;
name|private
label|:
comment|// The conventional meaning of this method; an ObjCMethodFamily.
comment|// This is not serialized; instead, it is computed on demand and
comment|// cached.
name|mutable
name|unsigned
name|Family
range|:
name|ObjCMethodFamilyBitWidth
decl_stmt|;
comment|/// instance (true) or class (false) method.
name|unsigned
name|IsInstance
range|:
literal|1
decl_stmt|;
name|unsigned
name|IsVariadic
range|:
literal|1
decl_stmt|;
comment|/// True if this method is the getter or setter for an explicit property.
name|unsigned
name|IsPropertyAccessor
range|:
literal|1
decl_stmt|;
comment|// Method has a definition.
name|unsigned
name|IsDefined
range|:
literal|1
decl_stmt|;
comment|/// \brief Method redeclaration in the same interface.
name|unsigned
name|IsRedeclaration
range|:
literal|1
decl_stmt|;
comment|/// \brief Is redeclared in the same interface.
name|mutable
name|unsigned
name|HasRedeclaration
range|:
literal|1
decl_stmt|;
comment|// NOTE: VC++ treats enums as signed, avoid using ImplementationControl enum
comment|/// \@required/\@optional
name|unsigned
name|DeclImplementation
range|:
literal|2
decl_stmt|;
comment|// NOTE: VC++ treats enums as signed, avoid using the ObjCDeclQualifier enum
comment|/// in, inout, etc.
name|unsigned
name|objcDeclQualifier
range|:
literal|6
decl_stmt|;
comment|/// \brief Indicates whether this method has a related result type.
name|unsigned
name|RelatedResultType
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether the locations of the selector identifiers are in a
comment|/// "standard" position, a enum SelectorLocationsKind.
name|unsigned
name|SelLocsKind
range|:
literal|2
decl_stmt|;
comment|/// \brief Whether this method overrides any other in the class hierarchy.
comment|///
comment|/// A method is said to override any method in the class's
comment|/// base classes, its protocols, or its categories' protocols, that has
comment|/// the same selector and is of the same kind (class or instance).
comment|/// A method in an implementation is not considered as overriding the same
comment|/// method in the interface or its categories.
name|unsigned
name|IsOverriding
range|:
literal|1
decl_stmt|;
comment|/// \brief Indicates if the method was a definition but its body was skipped.
name|unsigned
name|HasSkippedBody
range|:
literal|1
decl_stmt|;
comment|// Result type of this method.
name|QualType
name|MethodDeclType
decl_stmt|;
comment|// Type source information for the result type.
name|TypeSourceInfo
modifier|*
name|ResultTInfo
decl_stmt|;
comment|/// \brief Array of ParmVarDecls for the formal parameters of this method
comment|/// and optionally followed by selector locations.
name|void
modifier|*
name|ParamsAndSelLocs
decl_stmt|;
name|unsigned
name|NumParams
decl_stmt|;
comment|/// List of attributes for this method declaration.
name|SourceLocation
name|DeclEndLoc
decl_stmt|;
comment|// the location of the ';' or '{'.
comment|// The following are only used for method definitions, null otherwise.
name|LazyDeclStmtPtr
name|Body
decl_stmt|;
comment|/// SelfDecl - Decl for the implicit self parameter. This is lazily
comment|/// constructed by createImplicitParams.
name|ImplicitParamDecl
modifier|*
name|SelfDecl
decl_stmt|;
comment|/// CmdDecl - Decl for the implicit _cmd parameter. This is lazily
comment|/// constructed by createImplicitParams.
name|ImplicitParamDecl
modifier|*
name|CmdDecl
decl_stmt|;
name|SelectorLocationsKind
name|getSelLocsKind
argument_list|()
specifier|const
block|{
return|return
operator|(
name|SelectorLocationsKind
operator|)
name|SelLocsKind
return|;
block|}
name|bool
name|hasStandardSelLocs
argument_list|()
specifier|const
block|{
return|return
name|getSelLocsKind
argument_list|()
operator|!=
name|SelLoc_NonStandard
return|;
block|}
comment|/// \brief Get a pointer to the stored selector identifiers locations array.
comment|/// No locations will be stored if HasStandardSelLocs is true.
name|SourceLocation
modifier|*
name|getStoredSelLocs
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|SourceLocation
operator|*
operator|>
operator|(
name|getParams
argument_list|()
operator|+
name|NumParams
operator|)
return|;
block|}
specifier|const
name|SourceLocation
operator|*
name|getStoredSelLocs
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|SourceLocation
operator|*
operator|>
operator|(
name|getParams
argument_list|()
operator|+
name|NumParams
operator|)
return|;
block|}
comment|/// \brief Get a pointer to the stored selector identifiers locations array.
comment|/// No locations will be stored if HasStandardSelLocs is true.
name|ParmVarDecl
modifier|*
modifier|*
name|getParams
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|ParmVarDecl
operator|*
operator|*
operator|>
operator|(
name|ParamsAndSelLocs
operator|)
return|;
block|}
specifier|const
name|ParmVarDecl
operator|*
specifier|const
operator|*
name|getParams
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
name|ParmVarDecl
operator|*
specifier|const
operator|*
operator|>
operator|(
name|ParamsAndSelLocs
operator|)
return|;
block|}
comment|/// \brief Get the number of stored selector identifiers locations.
comment|/// No locations will be stored if HasStandardSelLocs is true.
name|unsigned
name|getNumStoredSelLocs
argument_list|()
specifier|const
block|{
if|if
condition|(
name|hasStandardSelLocs
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|getNumSelectorLocs
argument_list|()
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|setParamsAndSelLocs
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|,
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|Params
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|SelLocs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|ObjCMethodDecl
argument_list|(
argument|SourceLocation beginLoc
argument_list|,
argument|SourceLocation endLoc
argument_list|,
argument|Selector SelInfo
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *ResultTInfo
argument_list|,
argument|DeclContext *contextDecl
argument_list|,
argument|bool isInstance = true
argument_list|,
argument|bool isVariadic = false
argument_list|,
argument|bool isPropertyAccessor = false
argument_list|,
argument|bool isImplicitlyDeclared = false
argument_list|,
argument|bool isDefined = false
argument_list|,
argument|ImplementationControl impControl = None
argument_list|,
argument|bool HasRelatedResultType = false
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|NamedDecl
argument_list|(
name|ObjCMethod
argument_list|,
name|contextDecl
argument_list|,
name|beginLoc
argument_list|,
name|SelInfo
argument_list|)
operator|,
name|DeclContext
argument_list|(
name|ObjCMethod
argument_list|)
operator|,
name|Family
argument_list|(
name|InvalidObjCMethodFamily
argument_list|)
operator|,
name|IsInstance
argument_list|(
name|isInstance
argument_list|)
operator|,
name|IsVariadic
argument_list|(
name|isVariadic
argument_list|)
operator|,
name|IsPropertyAccessor
argument_list|(
name|isPropertyAccessor
argument_list|)
operator|,
name|IsDefined
argument_list|(
name|isDefined
argument_list|)
operator|,
name|IsRedeclaration
argument_list|(
literal|0
argument_list|)
operator|,
name|HasRedeclaration
argument_list|(
literal|0
argument_list|)
operator|,
name|DeclImplementation
argument_list|(
name|impControl
argument_list|)
operator|,
name|objcDeclQualifier
argument_list|(
name|OBJC_TQ_None
argument_list|)
operator|,
name|RelatedResultType
argument_list|(
name|HasRelatedResultType
argument_list|)
operator|,
name|SelLocsKind
argument_list|(
name|SelLoc_StandardNoSpace
argument_list|)
operator|,
name|IsOverriding
argument_list|(
literal|0
argument_list|)
operator|,
name|HasSkippedBody
argument_list|(
literal|0
argument_list|)
operator|,
name|MethodDeclType
argument_list|(
name|T
argument_list|)
operator|,
name|ResultTInfo
argument_list|(
name|ResultTInfo
argument_list|)
operator|,
name|ParamsAndSelLocs
argument_list|(
literal|0
argument_list|)
operator|,
name|NumParams
argument_list|(
literal|0
argument_list|)
operator|,
name|DeclEndLoc
argument_list|(
name|endLoc
argument_list|)
operator|,
name|Body
argument_list|()
operator|,
name|SelfDecl
argument_list|(
literal|0
argument_list|)
operator|,
name|CmdDecl
argument_list|(
literal|0
argument_list|)
block|{
name|setImplicit
argument_list|(
name|isImplicitlyDeclared
argument_list|)
block|;   }
comment|/// \brief A definition will return its interface declaration.
comment|/// An interface declaration will return its definition.
comment|/// Otherwise it will return itself.
name|virtual
name|ObjCMethodDecl
operator|*
name|getNextRedeclaration
argument_list|()
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_function_decl
specifier|static
name|ObjCMethodDecl
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|SourceLocation
name|beginLoc
parameter_list|,
name|SourceLocation
name|endLoc
parameter_list|,
name|Selector
name|SelInfo
parameter_list|,
name|QualType
name|T
parameter_list|,
name|TypeSourceInfo
modifier|*
name|ResultTInfo
parameter_list|,
name|DeclContext
modifier|*
name|contextDecl
parameter_list|,
name|bool
name|isInstance
init|=
name|true
parameter_list|,
name|bool
name|isVariadic
init|=
name|false
parameter_list|,
name|bool
name|isPropertyAccessor
init|=
name|false
parameter_list|,
name|bool
name|isImplicitlyDeclared
init|=
name|false
parameter_list|,
name|bool
name|isDefined
init|=
name|false
parameter_list|,
name|ImplementationControl
name|impControl
init|=
name|None
parameter_list|,
name|bool
name|HasRelatedResultType
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|ObjCMethodDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|ObjCMethodDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|ObjCMethodDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ObjCMethodDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getCanonicalDecl
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
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
end_expr_stmt

begin_function
name|void
name|setObjCDeclQualifier
parameter_list|(
name|ObjCDeclQualifier
name|QV
parameter_list|)
block|{
name|objcDeclQualifier
operator|=
name|QV
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine whether this method has a result type that is related
end_comment

begin_comment
comment|/// to the message receiver's type.
end_comment

begin_expr_stmt
name|bool
name|hasRelatedResultType
argument_list|()
specifier|const
block|{
return|return
name|RelatedResultType
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Note whether this method has a related result type.
end_comment

begin_function
name|void
name|SetRelatedResultType
parameter_list|(
name|bool
name|RRT
init|=
name|true
parameter_list|)
block|{
name|RelatedResultType
operator|=
name|RRT
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief True if this is a method redeclaration in the same interface.
end_comment

begin_expr_stmt
name|bool
name|isRedeclaration
argument_list|()
specifier|const
block|{
return|return
name|IsRedeclaration
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|setAsRedeclaration
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|PrevMethod
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Returns the location where the declarator ends. It will be
end_comment

begin_comment
comment|/// the location of ';' for a method declaration and the location of '{'
end_comment

begin_comment
comment|/// for a method definition.
end_comment

begin_expr_stmt
name|SourceLocation
name|getDeclaratorEndLoc
argument_list|()
specifier|const
block|{
return|return
name|DeclEndLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|// Location information, modeled after the Stmt API.
end_comment

begin_expr_stmt
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|getLocation
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
name|LLVM_READONLY
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|getLocation
argument_list|()
argument_list|,
name|getLocEnd
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getSelectorStartLoc
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isImplicit
argument_list|()
condition|)
return|return
name|getLocStart
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|getSelectorLoc
argument_list|(
literal|0
argument_list|)
return|;
end_return

begin_macro
unit|}   SourceLocation
name|getSelectorLoc
argument_list|(
argument|unsigned Index
argument_list|)
end_macro

begin_expr_stmt
specifier|const
block|{
name|assert
argument_list|(
name|Index
operator|<
name|getNumSelectorLocs
argument_list|()
operator|&&
literal|"Index out of range!"
argument_list|)
block|;
if|if
condition|(
name|hasStandardSelLocs
argument_list|()
condition|)
return|return
name|getStandardSelectorLoc
argument_list|(
name|Index
argument_list|,
name|getSelector
argument_list|()
argument_list|,
name|getSelLocsKind
argument_list|()
operator|==
name|SelLoc_StandardWithSpace
argument_list|,
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|const_cast
operator|<
name|ParmVarDecl
operator|*
operator|*
operator|>
operator|(
name|getParams
argument_list|()
operator|)
argument_list|,
name|NumParams
argument_list|)
argument_list|,
name|DeclEndLoc
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|getStoredSelLocs
argument_list|()
index|[
name|Index
index|]
return|;
end_return

begin_macro
unit|}    void
name|getSelectorLocs
argument_list|(
argument|SmallVectorImpl<SourceLocation>&SelLocs
argument_list|)
end_macro

begin_decl_stmt
specifier|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|unsigned
name|getNumSelectorLocs
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isImplicit
argument_list|()
condition|)
return|return
literal|0
return|;
name|Selector
name|Sel
operator|=
name|getSelector
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Sel
operator|.
name|isUnarySelector
argument_list|()
condition|)
return|return
literal|1
return|;
end_if

begin_return
return|return
name|Sel
operator|.
name|getNumArgs
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    ObjCInterfaceDecl
operator|*
name|getClassInterface
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|ObjCInterfaceDecl
operator|*
name|getClassInterface
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ObjCMethodDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getClassInterface
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|Selector
name|getSelector
argument_list|()
specifier|const
block|{
return|return
name|getDeclName
argument_list|()
operator|.
name|getObjCSelector
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|QualType
name|getResultType
argument_list|()
specifier|const
block|{
return|return
name|MethodDeclType
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setResultType
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|MethodDeclType
operator|=
name|T
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Determine the type of an expression that sends a message to this
end_comment

begin_comment
comment|/// function.
end_comment

begin_expr_stmt
name|QualType
name|getSendResultType
argument_list|()
specifier|const
block|{
return|return
name|getResultType
argument_list|()
operator|.
name|getNonLValueExprType
argument_list|(
name|getASTContext
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|TypeSourceInfo
operator|*
name|getResultTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|ResultTInfo
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setResultTypeSourceInfo
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|)
block|{
name|ResultTInfo
operator|=
name|TInfo
expr_stmt|;
block|}
end_function

begin_comment
comment|// Iterator access to formal parameters.
end_comment

begin_expr_stmt
name|unsigned
name|param_size
argument_list|()
specifier|const
block|{
return|return
name|NumParams
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
specifier|const
name|ParmVarDecl
modifier|*
specifier|const
modifier|*
name|param_const_iterator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ParmVarDecl
modifier|*
specifier|const
modifier|*
name|param_iterator
typedef|;
end_typedef

begin_expr_stmt
name|param_const_iterator
name|param_begin
argument_list|()
specifier|const
block|{
return|return
name|getParams
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|param_const_iterator
name|param_end
argument_list|()
specifier|const
block|{
return|return
name|getParams
argument_list|()
operator|+
name|NumParams
return|;
block|}
end_expr_stmt

begin_function
name|param_iterator
name|param_begin
parameter_list|()
block|{
return|return
name|getParams
argument_list|()
return|;
block|}
end_function

begin_function
name|param_iterator
name|param_end
parameter_list|()
block|{
return|return
name|getParams
argument_list|()
operator|+
name|NumParams
return|;
block|}
end_function

begin_comment
comment|// This method returns and of the parameters which are part of the selector
end_comment

begin_comment
comment|// name mangling requirements.
end_comment

begin_expr_stmt
name|param_const_iterator
name|sel_param_end
argument_list|()
specifier|const
block|{
return|return
name|param_begin
argument_list|()
operator|+
name|getSelector
argument_list|()
operator|.
name|getNumArgs
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Sets the method's parameters and selector source locations.
end_comment

begin_comment
comment|/// If the method is implicit (not coming from source) \p SelLocs is
end_comment

begin_comment
comment|/// ignored.
end_comment

begin_decl_stmt
name|void
name|setMethodParams
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|,
name|ArrayRef
operator|<
name|ParmVarDecl
operator|*
operator|>
name|Params
argument_list|,
name|ArrayRef
operator|<
name|SourceLocation
operator|>
name|SelLocs
operator|=
name|ArrayRef
operator|<
name|SourceLocation
operator|>
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Iterator access to parameter types.
end_comment

begin_typedef
typedef|typedef
name|std
operator|::
name|const_mem_fun_t
operator|<
name|QualType
operator|,
name|ParmVarDecl
operator|>
name|deref_fun
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|llvm
operator|::
name|mapped_iterator
operator|<
name|param_const_iterator
operator|,
name|deref_fun
operator|>
name|arg_type_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|arg_type_iterator
name|arg_type_begin
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|map_iterator
argument_list|(
name|param_begin
argument_list|()
argument_list|,
name|deref_fun
argument_list|(
operator|&
name|ParmVarDecl
operator|::
name|getType
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|arg_type_iterator
name|arg_type_end
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|map_iterator
argument_list|(
name|param_end
argument_list|()
argument_list|,
name|deref_fun
argument_list|(
operator|&
name|ParmVarDecl
operator|::
name|getType
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// createImplicitParams - Used to lazily create the self and cmd
end_comment

begin_comment
comment|/// implict parameters. This must be called prior to using getSelfDecl()
end_comment

begin_comment
comment|/// or getCmdDecl(). The call is ignored if the implicit paramters
end_comment

begin_comment
comment|/// have already been created.
end_comment

begin_function_decl
name|void
name|createImplicitParams
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|ID
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|ImplicitParamDecl
operator|*
name|getSelfDecl
argument_list|()
specifier|const
block|{
return|return
name|SelfDecl
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setSelfDecl
parameter_list|(
name|ImplicitParamDecl
modifier|*
name|SD
parameter_list|)
block|{
name|SelfDecl
operator|=
name|SD
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ImplicitParamDecl
operator|*
name|getCmdDecl
argument_list|()
specifier|const
block|{
return|return
name|CmdDecl
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setCmdDecl
parameter_list|(
name|ImplicitParamDecl
modifier|*
name|CD
parameter_list|)
block|{
name|CmdDecl
operator|=
name|CD
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Determines the family of this method.
end_comment

begin_expr_stmt
name|ObjCMethodFamily
name|getMethodFamily
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|isInstanceMethod
argument_list|()
specifier|const
block|{
return|return
name|IsInstance
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setInstanceMethod
parameter_list|(
name|bool
name|isInst
parameter_list|)
block|{
name|IsInstance
operator|=
name|isInst
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|isVariadic
argument_list|()
specifier|const
block|{
return|return
name|IsVariadic
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setVariadic
parameter_list|(
name|bool
name|isVar
parameter_list|)
block|{
name|IsVariadic
operator|=
name|isVar
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|isClassMethod
argument_list|()
specifier|const
block|{
return|return
operator|!
name|IsInstance
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isPropertyAccessor
argument_list|()
specifier|const
block|{
return|return
name|IsPropertyAccessor
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setPropertyAccessor
parameter_list|(
name|bool
name|isAccessor
parameter_list|)
block|{
name|IsPropertyAccessor
operator|=
name|isAccessor
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|bool
name|isDefined
argument_list|()
specifier|const
block|{
return|return
name|IsDefined
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setDefined
parameter_list|(
name|bool
name|isDefined
parameter_list|)
block|{
name|IsDefined
operator|=
name|isDefined
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Whether this method overrides any other in the class hierarchy.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A method is said to override any method in the class's
end_comment

begin_comment
comment|/// base classes, its protocols, or its categories' protocols, that has
end_comment

begin_comment
comment|/// the same selector and is of the same kind (class or instance).
end_comment

begin_comment
comment|/// A method in an implementation is not considered as overriding the same
end_comment

begin_comment
comment|/// method in the interface or its categories.
end_comment

begin_expr_stmt
name|bool
name|isOverriding
argument_list|()
specifier|const
block|{
return|return
name|IsOverriding
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setOverriding
parameter_list|(
name|bool
name|isOverriding
parameter_list|)
block|{
name|IsOverriding
operator|=
name|isOverriding
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Return overridden methods for the given \p Method.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// An ObjC method is considered to override any method in the class's
end_comment

begin_comment
comment|/// base classes (and base's categories), its protocols, or its categories'
end_comment

begin_comment
comment|/// protocols, that has
end_comment

begin_comment
comment|/// the same selector and is of the same kind (class or instance).
end_comment

begin_comment
comment|/// A method in an implementation is not considered as overriding the same
end_comment

begin_comment
comment|/// method in the interface or its categories.
end_comment

begin_decl_stmt
name|void
name|getOverriddenMethods
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|ObjCMethodDecl
operator|*
operator|>
operator|&
name|Overridden
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief True if the method was a definition but its body was skipped.
end_comment

begin_expr_stmt
name|bool
name|hasSkippedBody
argument_list|()
specifier|const
block|{
return|return
name|HasSkippedBody
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setHasSkippedBody
parameter_list|(
name|bool
name|Skipped
init|=
name|true
parameter_list|)
block|{
name|HasSkippedBody
operator|=
name|Skipped
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Returns the property associated with this method's selector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Note that even if this particular method is not marked as a property
end_comment

begin_comment
comment|/// accessor, it is still possible for it to match a property declared in a
end_comment

begin_comment
comment|/// superclass. Pass \c false if you only want to check the current class.
end_comment

begin_decl_stmt
specifier|const
name|ObjCPropertyDecl
modifier|*
name|findPropertyDecl
argument_list|(
name|bool
name|CheckOverrides
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Related to protocols declared in  \@protocol
end_comment

begin_function
name|void
name|setDeclImplementation
parameter_list|(
name|ImplementationControl
name|ic
parameter_list|)
block|{
name|DeclImplementation
operator|=
name|ic
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ImplementationControl
name|getImplementationControl
argument_list|()
specifier|const
block|{
return|return
name|ImplementationControl
argument_list|(
name|DeclImplementation
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this method has a body.
end_comment

begin_expr_stmt
name|virtual
name|bool
name|hasBody
argument_list|()
specifier|const
block|{
return|return
name|Body
operator|.
name|isValid
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the body of this method, if it has one.
end_comment

begin_expr_stmt
name|virtual
name|Stmt
operator|*
name|getBody
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|setLazyBody
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
block|{
name|Body
operator|=
name|Offset
expr_stmt|;
block|}
end_function

begin_function
name|CompoundStmt
modifier|*
name|getCompoundBody
parameter_list|()
block|{
return|return
operator|(
name|CompoundStmt
operator|*
operator|)
name|getBody
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|setBody
parameter_list|(
name|Stmt
modifier|*
name|B
parameter_list|)
block|{
name|Body
operator|=
name|B
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Returns whether this specific method is a definition.
end_comment

begin_expr_stmt
name|bool
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|hasBody
argument_list|()
return|;
block|}
end_expr_stmt

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
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|ObjCMethod
return|;
block|}
end_function

begin_function
specifier|static
name|DeclContext
modifier|*
name|castToDeclContext
parameter_list|(
specifier|const
name|ObjCMethodDecl
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
name|ObjCMethodDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|ObjCMethodDecl
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
name|ObjCMethodDecl
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
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// ObjCContainerDecl - Represents a container for method declarations.
end_comment

begin_comment
comment|/// Current sub-classes are ObjCInterfaceDecl, ObjCCategoryDecl,
end_comment

begin_comment
comment|/// ObjCProtocolDecl, and ObjCImplDecl.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ObjCContainerDecl
range|:
name|public
name|NamedDecl
decl_stmt|,
name|public
name|DeclContext
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|SourceLocation
name|AtStart
decl_stmt|;
comment|// These two locations in the range mark the end of the method container.
comment|// The first points to the '@' token, and the second to the 'end' token.
name|SourceRange
name|AtEnd
decl_stmt|;
name|public
label|:
name|ObjCContainerDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|SourceLocation nameLoc
argument_list|,
argument|SourceLocation atStartLoc
argument_list|)
block|:
name|NamedDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|nameLoc
argument_list|,
name|Id
argument_list|)
operator|,
name|DeclContext
argument_list|(
name|DK
argument_list|)
operator|,
name|AtStart
argument_list|(
argument|atStartLoc
argument_list|)
block|{}
comment|// Iterator access to properties.
typedef|typedef
name|specific_decl_iterator
operator|<
name|ObjCPropertyDecl
operator|>
name|prop_iterator
expr_stmt|;
name|prop_iterator
name|prop_begin
argument_list|()
specifier|const
block|{
return|return
name|prop_iterator
argument_list|(
name|decls_begin
argument_list|()
argument_list|)
return|;
block|}
name|prop_iterator
name|prop_end
argument_list|()
specifier|const
block|{
return|return
name|prop_iterator
argument_list|(
name|decls_end
argument_list|()
argument_list|)
return|;
block|}
comment|// Iterator access to instance/class methods.
typedef|typedef
name|specific_decl_iterator
operator|<
name|ObjCMethodDecl
operator|>
name|method_iterator
expr_stmt|;
name|method_iterator
name|meth_begin
argument_list|()
specifier|const
block|{
return|return
name|method_iterator
argument_list|(
name|decls_begin
argument_list|()
argument_list|)
return|;
block|}
name|method_iterator
name|meth_end
argument_list|()
specifier|const
block|{
return|return
name|method_iterator
argument_list|(
name|decls_end
argument_list|()
argument_list|)
return|;
block|}
typedef|typedef
name|filtered_decl_iterator
operator|<
name|ObjCMethodDecl
operator|,
operator|&
name|ObjCMethodDecl
operator|::
name|isInstanceMethod
operator|>
name|instmeth_iterator
expr_stmt|;
name|instmeth_iterator
name|instmeth_begin
argument_list|()
specifier|const
block|{
return|return
name|instmeth_iterator
argument_list|(
name|decls_begin
argument_list|()
argument_list|)
return|;
block|}
name|instmeth_iterator
name|instmeth_end
argument_list|()
specifier|const
block|{
return|return
name|instmeth_iterator
argument_list|(
name|decls_end
argument_list|()
argument_list|)
return|;
block|}
typedef|typedef
name|filtered_decl_iterator
operator|<
name|ObjCMethodDecl
operator|,
operator|&
name|ObjCMethodDecl
operator|::
name|isClassMethod
operator|>
name|classmeth_iterator
expr_stmt|;
name|classmeth_iterator
name|classmeth_begin
argument_list|()
specifier|const
block|{
return|return
name|classmeth_iterator
argument_list|(
name|decls_begin
argument_list|()
argument_list|)
return|;
block|}
name|classmeth_iterator
name|classmeth_end
argument_list|()
specifier|const
block|{
return|return
name|classmeth_iterator
argument_list|(
name|decls_end
argument_list|()
argument_list|)
return|;
block|}
comment|// Get the local instance/class method declared in this interface.
name|ObjCMethodDecl
modifier|*
name|getMethod
argument_list|(
name|Selector
name|Sel
argument_list|,
name|bool
name|isInstance
argument_list|,
name|bool
name|AllowHidden
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|ObjCMethodDecl
modifier|*
name|getInstanceMethod
argument_list|(
name|Selector
name|Sel
argument_list|,
name|bool
name|AllowHidden
operator|=
name|false
argument_list|)
decl|const
block|{
return|return
name|getMethod
argument_list|(
name|Sel
argument_list|,
name|true
comment|/*isInstance*/
argument_list|,
name|AllowHidden
argument_list|)
return|;
block|}
name|ObjCMethodDecl
modifier|*
name|getClassMethod
argument_list|(
name|Selector
name|Sel
argument_list|,
name|bool
name|AllowHidden
operator|=
name|false
argument_list|)
decl|const
block|{
return|return
name|getMethod
argument_list|(
name|Sel
argument_list|,
name|false
comment|/*isInstance*/
argument_list|,
name|AllowHidden
argument_list|)
return|;
block|}
name|bool
name|HasUserDeclaredSetterMethod
argument_list|(
specifier|const
name|ObjCPropertyDecl
operator|*
name|P
argument_list|)
decl|const
decl_stmt|;
name|ObjCIvarDecl
modifier|*
name|getIvarDecl
argument_list|(
name|IdentifierInfo
operator|*
name|Id
argument_list|)
decl|const
decl_stmt|;
name|ObjCPropertyDecl
modifier|*
name|FindPropertyDeclaration
argument_list|(
name|IdentifierInfo
operator|*
name|PropertyId
argument_list|)
decl|const
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|ObjCPropertyDecl
operator|*
operator|>
name|PropertyMap
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|ObjCProtocolDecl
operator|*
operator|,
name|ObjCPropertyDecl
operator|*
operator|>
name|ProtocolPropertyMap
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|ObjCPropertyDecl
operator|*
operator|,
literal|8
operator|>
name|PropertyDeclOrder
expr_stmt|;
comment|/// This routine collects list of properties to be implemented in the class.
comment|/// This includes, class's and its conforming protocols' properties.
comment|/// Note, the superclass's properties are not included in the list.
name|virtual
name|void
name|collectPropertiesToImplement
argument_list|(
name|PropertyMap
operator|&
name|PM
argument_list|,
name|PropertyDeclOrder
operator|&
name|PO
argument_list|)
decl|const
block|{}
name|SourceLocation
name|getAtStartLoc
argument_list|()
specifier|const
block|{
return|return
name|AtStart
return|;
block|}
name|void
name|setAtStartLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|AtStart
operator|=
name|Loc
expr_stmt|;
block|}
comment|// Marks the end of the container.
name|SourceRange
name|getAtEndRange
argument_list|()
specifier|const
block|{
return|return
name|AtEnd
return|;
block|}
name|void
name|setAtEndRange
parameter_list|(
name|SourceRange
name|atEnd
parameter_list|)
block|{
name|AtEnd
operator|=
name|atEnd
expr_stmt|;
block|}
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|AtStart
argument_list|,
name|getAtEndRange
argument_list|()
operator|.
name|getEnd
argument_list|()
argument_list|)
return|;
block|}
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
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|>=
name|firstObjCContainer
operator|&&
name|K
operator|<=
name|lastObjCContainer
return|;
block|}
specifier|static
name|DeclContext
modifier|*
name|castToDeclContext
parameter_list|(
specifier|const
name|ObjCContainerDecl
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
name|ObjCContainerDecl
operator|*
operator|>
operator|(
name|D
operator|)
operator|)
return|;
block|}
specifier|static
name|ObjCContainerDecl
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
name|ObjCContainerDecl
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief Represents an ObjC class declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///   // MostPrimitive declares no super class (not particularly useful).
end_comment

begin_comment
comment|///   \@interface MostPrimitive
end_comment

begin_comment
comment|///     // no instance variables or methods.
end_comment

begin_comment
comment|///   \@end
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   // NSResponder inherits from NSObject& implements NSCoding (a protocol).
end_comment

begin_comment
comment|///   \@interface NSResponder : NSObject \<NSCoding>
end_comment

begin_comment
comment|///   { // instance variables are represented by ObjCIvarDecl.
end_comment

begin_comment
comment|///     id nextResponder; // nextResponder instance variable.
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|///   - (NSResponder *)nextResponder; // return a pointer to NSResponder.
end_comment

begin_comment
comment|///   - (void)mouseMoved:(NSEvent *)theEvent; // return void, takes a pointer
end_comment

begin_comment
comment|///   \@end                                    // to an NSEvent.
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   Unlike C/C++, forward class declarations are accomplished with \@class.
end_comment

begin_comment
comment|///   Unlike C/C++, \@class allows for a list of classes to be forward declared.
end_comment

begin_comment
comment|///   Unlike C++, ObjC is a single-rooted class model. In Cocoa, classes
end_comment

begin_comment
comment|///   typically inherit from NSObject (an exception is NSProxy).
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ObjCInterfaceDecl
range|:
name|public
name|ObjCContainerDecl
decl_stmt|,
name|public
name|Redeclarable
decl|<
name|ObjCInterfaceDecl
decl|>
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
comment|/// TypeForDecl - This indicates the Type object that represents this
comment|/// TypeDecl.  It is a cache maintained by ASTContext::getObjCInterfaceType
name|mutable
specifier|const
name|Type
modifier|*
name|TypeForDecl
decl_stmt|;
name|friend
name|class
name|ASTContext
decl_stmt|;
struct|struct
name|DefinitionData
block|{
comment|/// \brief The definition of this class, for quick access from any
comment|/// declaration.
name|ObjCInterfaceDecl
modifier|*
name|Definition
decl_stmt|;
comment|/// Class's super class.
name|ObjCInterfaceDecl
modifier|*
name|SuperClass
decl_stmt|;
comment|/// Protocols referenced in the \@interface  declaration
name|ObjCProtocolList
name|ReferencedProtocols
decl_stmt|;
comment|/// Protocols reference in both the \@interface and class extensions.
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
name|AllReferencedProtocols
expr_stmt|;
comment|/// \brief List of categories and class extensions defined for this class.
comment|///
comment|/// Categories are stored as a linked list in the AST, since the categories
comment|/// and class extensions come long after the initial interface declaration,
comment|/// and we avoid dynamically-resized arrays in the AST wherever possible.
name|ObjCCategoryDecl
modifier|*
name|CategoryList
decl_stmt|;
comment|/// IvarList - List of all ivars defined by this class; including class
comment|/// extensions and implementation. This list is built lazily.
name|ObjCIvarDecl
modifier|*
name|IvarList
decl_stmt|;
comment|/// \brief Indicates that the contents of this Objective-C class will be
comment|/// completed by the external AST source when required.
name|mutable
name|bool
name|ExternallyCompleted
range|:
literal|1
decl_stmt|;
comment|/// \brief Indicates that the ivar cache does not yet include ivars
comment|/// declared in the implementation.
name|mutable
name|bool
name|IvarListMissingImplementation
range|:
literal|1
decl_stmt|;
comment|/// \brief The location of the superclass, if any.
name|SourceLocation
name|SuperClassLoc
decl_stmt|;
comment|/// \brief The location of the last location in this declaration, before
comment|/// the properties/methods. For example, this will be the '>', '}', or
comment|/// identifier,
name|SourceLocation
name|EndLoc
decl_stmt|;
name|DefinitionData
argument_list|()
operator|:
name|Definition
argument_list|()
operator|,
name|SuperClass
argument_list|()
operator|,
name|CategoryList
argument_list|()
operator|,
name|IvarList
argument_list|()
operator|,
name|ExternallyCompleted
argument_list|()
operator|,
name|IvarListMissingImplementation
argument_list|(
argument|true
argument_list|)
block|{ }
block|}
struct|;
name|ObjCInterfaceDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation atLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|SourceLocation CLoc
argument_list|,
argument|ObjCInterfaceDecl *PrevDecl
argument_list|,
argument|bool isInternal
argument_list|)
empty_stmt|;
name|void
name|LoadExternalDefinition
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Contains a pointer to the data associated with this class,
comment|/// which will be NULL if this class has not yet been defined.
comment|///
comment|/// The bit indicates when we don't need to check for out-of-date
comment|/// declarations. It will be set unless modules are enabled.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|DefinitionData
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|Data
expr_stmt|;
name|DefinitionData
operator|&
name|data
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Data
operator|.
name|getPointer
argument_list|()
operator|&&
literal|"Declaration has no definition!"
argument_list|)
block|;
return|return
operator|*
name|Data
operator|.
name|getPointer
argument_list|()
return|;
block|}
comment|/// \brief Allocate the definition data for this class.
name|void
name|allocateDefinitionData
parameter_list|()
function_decl|;
typedef|typedef
name|Redeclarable
operator|<
name|ObjCInterfaceDecl
operator|>
name|redeclarable_base
expr_stmt|;
name|virtual
name|ObjCInterfaceDecl
modifier|*
name|getNextRedeclaration
parameter_list|()
block|{
return|return
name|RedeclLink
operator|.
name|getNext
argument_list|()
return|;
block|}
name|virtual
name|ObjCInterfaceDecl
modifier|*
name|getPreviousDeclImpl
parameter_list|()
block|{
return|return
name|getPreviousDecl
argument_list|()
return|;
block|}
name|virtual
name|ObjCInterfaceDecl
modifier|*
name|getMostRecentDeclImpl
parameter_list|()
block|{
return|return
name|getMostRecentDecl
argument_list|()
return|;
block|}
name|public
label|:
specifier|static
name|ObjCInterfaceDecl
modifier|*
name|Create
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|C
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|atLoc
parameter_list|,
name|IdentifierInfo
modifier|*
name|Id
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
name|PrevDecl
parameter_list|,
name|SourceLocation
name|ClassLoc
init|=
name|SourceLocation
argument_list|()
parameter_list|,
name|bool
name|isInternal
init|=
name|false
parameter_list|)
function_decl|;
specifier|static
name|ObjCInterfaceDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
name|isThisDeclarationADefinition
argument_list|()
condition|)
return|return
name|ObjCContainerDecl
operator|::
name|getSourceRange
argument_list|()
return|;
return|return
name|SourceRange
argument_list|(
name|getAtStartLoc
argument_list|()
argument_list|,
name|getLocation
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Indicate that this Objective-C class is complete, but that
end_comment

begin_comment
comment|/// the external AST source will be responsible for filling in its contents
end_comment

begin_comment
comment|/// when a complete class is required.
end_comment

begin_function_decl
name|void
name|setExternallyCompleted
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|ObjCProtocolList
operator|&
name|getReferencedProtocols
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasDefinition
argument_list|()
operator|&&
literal|"Caller did not check for forward reference!"
argument_list|)
block|;
if|if
condition|(
name|data
argument_list|()
operator|.
name|ExternallyCompleted
condition|)
name|LoadExternalDefinition
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|data
argument_list|()
operator|.
name|ReferencedProtocols
return|;
end_return

begin_expr_stmt
unit|}    ObjCImplementationDecl
operator|*
name|getImplementation
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|setImplementation
parameter_list|(
name|ObjCImplementationDecl
modifier|*
name|ImplD
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ObjCCategoryDecl
modifier|*
name|FindCategoryDeclaration
argument_list|(
name|IdentifierInfo
operator|*
name|CategoryId
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Get the local instance/class method declared in a category.
end_comment

begin_decl_stmt
name|ObjCMethodDecl
modifier|*
name|getCategoryInstanceMethod
argument_list|(
name|Selector
name|Sel
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ObjCMethodDecl
modifier|*
name|getCategoryClassMethod
argument_list|(
name|Selector
name|Sel
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ObjCMethodDecl
modifier|*
name|getCategoryMethod
argument_list|(
name|Selector
name|Sel
argument_list|,
name|bool
name|isInstance
argument_list|)
decl|const
block|{
return|return
name|isInstance
condition|?
name|getInstanceMethod
argument_list|(
name|Sel
argument_list|)
else|:
name|getClassMethod
argument_list|(
name|Sel
argument_list|)
return|;
block|}
end_decl_stmt

begin_typedef
typedef|typedef
name|ObjCProtocolList
operator|::
name|iterator
name|protocol_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|protocol_iterator
name|protocol_begin
argument_list|()
specifier|const
block|{
comment|// FIXME: Should make sure no callers ever do this.
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
name|protocol_iterator
argument_list|()
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|data
argument_list|()
operator|.
name|ExternallyCompleted
condition|)
name|LoadExternalDefinition
argument_list|()
expr_stmt|;
end_if

begin_return
return|return
name|data
argument_list|()
operator|.
name|ReferencedProtocols
operator|.
name|begin
argument_list|()
return|;
end_return

begin_macro
unit|}   protocol_iterator
name|protocol_end
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
comment|// FIXME: Should make sure no callers ever do this.
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
name|protocol_iterator
argument_list|()
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|data
argument_list|()
operator|.
name|ExternallyCompleted
condition|)
name|LoadExternalDefinition
argument_list|()
expr_stmt|;
end_if

begin_return
return|return
name|data
argument_list|()
operator|.
name|ReferencedProtocols
operator|.
name|end
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    typedef
name|ObjCProtocolList
operator|::
name|loc_iterator
name|protocol_loc_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|protocol_loc_iterator
name|protocol_loc_begin
argument_list|()
specifier|const
block|{
comment|// FIXME: Should make sure no callers ever do this.
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
name|protocol_loc_iterator
argument_list|()
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|data
argument_list|()
operator|.
name|ExternallyCompleted
condition|)
name|LoadExternalDefinition
argument_list|()
expr_stmt|;
end_if

begin_return
return|return
name|data
argument_list|()
operator|.
name|ReferencedProtocols
operator|.
name|loc_begin
argument_list|()
return|;
end_return

begin_macro
unit|}    protocol_loc_iterator
name|protocol_loc_end
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
comment|// FIXME: Should make sure no callers ever do this.
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
name|protocol_loc_iterator
argument_list|()
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|data
argument_list|()
operator|.
name|ExternallyCompleted
condition|)
name|LoadExternalDefinition
argument_list|()
expr_stmt|;
end_if

begin_return
return|return
name|data
argument_list|()
operator|.
name|ReferencedProtocols
operator|.
name|loc_end
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    typedef
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
operator|::
name|iterator
name|all_protocol_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|all_protocol_iterator
name|all_referenced_protocol_begin
argument_list|()
specifier|const
block|{
comment|// FIXME: Should make sure no callers ever do this.
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
name|all_protocol_iterator
argument_list|()
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|data
argument_list|()
operator|.
name|ExternallyCompleted
condition|)
name|LoadExternalDefinition
argument_list|()
expr_stmt|;
end_if

begin_return
return|return
name|data
argument_list|()
operator|.
name|AllReferencedProtocols
operator|.
name|empty
argument_list|()
condition|?
name|protocol_begin
argument_list|()
else|:
name|data
argument_list|()
operator|.
name|AllReferencedProtocols
operator|.
name|begin
argument_list|()
return|;
end_return

begin_macro
unit|}   all_protocol_iterator
name|all_referenced_protocol_end
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
comment|// FIXME: Should make sure no callers ever do this.
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
name|all_protocol_iterator
argument_list|()
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|data
argument_list|()
operator|.
name|ExternallyCompleted
condition|)
name|LoadExternalDefinition
argument_list|()
expr_stmt|;
end_if

begin_return
return|return
name|data
argument_list|()
operator|.
name|AllReferencedProtocols
operator|.
name|empty
argument_list|()
condition|?
name|protocol_end
argument_list|()
else|:
name|data
argument_list|()
operator|.
name|AllReferencedProtocols
operator|.
name|end
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    typedef
name|specific_decl_iterator
operator|<
name|ObjCIvarDecl
operator|>
name|ivar_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ivar_iterator
name|ivar_begin
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|Def
init|=
name|getDefinition
argument_list|()
condition|)
return|return
name|ivar_iterator
argument_list|(
name|Def
operator|->
name|decls_begin
argument_list|()
argument_list|)
return|;
end_expr_stmt

begin_comment
comment|// FIXME: Should make sure no callers ever do this.
end_comment

begin_return
return|return
name|ivar_iterator
argument_list|()
return|;
end_return

begin_macro
unit|}   ivar_iterator
name|ivar_end
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|Def
init|=
name|getDefinition
argument_list|()
condition|)
return|return
name|ivar_iterator
argument_list|(
name|Def
operator|->
name|decls_end
argument_list|()
argument_list|)
return|;
end_expr_stmt

begin_comment
comment|// FIXME: Should make sure no callers ever do this.
end_comment

begin_return
return|return
name|ivar_iterator
argument_list|()
return|;
end_return

begin_macro
unit|}    unsigned
name|ivar_size
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|std
operator|::
name|distance
argument_list|(
name|ivar_begin
argument_list|()
argument_list|,
name|ivar_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|ivar_empty
argument_list|()
specifier|const
block|{
return|return
name|ivar_begin
argument_list|()
operator|==
name|ivar_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_function_decl
name|ObjCIvarDecl
modifier|*
name|all_declared_ivar_begin
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|const
name|ObjCIvarDecl
operator|*
name|all_declared_ivar_begin
argument_list|()
specifier|const
block|{
comment|// Even though this modifies IvarList, it's conceptually const:
comment|// the ivar chain is essentially a cached property of ObjCInterfaceDecl.
return|return
name|const_cast
operator|<
name|ObjCInterfaceDecl
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|all_declared_ivar_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setIvarList
parameter_list|(
name|ObjCIvarDecl
modifier|*
name|ivar
parameter_list|)
block|{
name|data
argument_list|()
operator|.
name|IvarList
operator|=
name|ivar
expr_stmt|;
block|}
end_function

begin_comment
comment|/// setProtocolList - Set the list of protocols that this interface
end_comment

begin_comment
comment|/// implements.
end_comment

begin_function
name|void
name|setProtocolList
parameter_list|(
name|ObjCProtocolDecl
modifier|*
specifier|const
modifier|*
name|List
parameter_list|,
name|unsigned
name|Num
parameter_list|,
specifier|const
name|SourceLocation
modifier|*
name|Locs
parameter_list|,
name|ASTContext
modifier|&
name|C
parameter_list|)
block|{
name|data
argument_list|()
operator|.
name|ReferencedProtocols
operator|.
name|set
argument_list|(
name|List
argument_list|,
name|Num
argument_list|,
name|Locs
argument_list|,
name|C
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// mergeClassExtensionProtocolList - Merge class extension's protocol list
end_comment

begin_comment
comment|/// into the protocol list for this class.
end_comment

begin_function_decl
name|void
name|mergeClassExtensionProtocolList
parameter_list|(
name|ObjCProtocolDecl
modifier|*
specifier|const
modifier|*
name|List
parameter_list|,
name|unsigned
name|Num
parameter_list|,
name|ASTContext
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Determine whether this particular declaration of this class is
end_comment

begin_comment
comment|/// actually also a definition.
end_comment

begin_expr_stmt
name|bool
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|getDefinition
argument_list|()
operator|==
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this class has been defined.
end_comment

begin_expr_stmt
name|bool
name|hasDefinition
argument_list|()
specifier|const
block|{
comment|// If the name of this class is out-of-date, bring it up-to-date, which
comment|// might bring in a definition.
comment|// Note: a null value indicates that we don't have a definition and that
comment|// modules are enabled.
if|if
condition|(
operator|!
name|Data
operator|.
name|getOpaqueValue
argument_list|()
condition|)
block|{
if|if
condition|(
name|IdentifierInfo
modifier|*
name|II
init|=
name|getIdentifier
argument_list|()
condition|)
block|{
if|if
condition|(
name|II
operator|->
name|isOutOfDate
argument_list|()
condition|)
block|{
name|updateOutOfDate
argument_list|(
operator|*
name|II
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
unit|}     }
return|return
name|Data
operator|.
name|getPointer
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the definition of this class, or NULL if this class
end_comment

begin_comment
comment|/// has been forward-declared (with \@class) but not yet defined (with
end_comment

begin_comment
comment|/// \@interface).
end_comment

begin_expr_stmt
unit|ObjCInterfaceDecl
operator|*
name|getDefinition
argument_list|()
block|{
return|return
name|hasDefinition
argument_list|()
operator|?
name|Data
operator|.
name|getPointer
argument_list|()
operator|->
name|Definition
operator|:
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the definition of this class, or NULL if this class
end_comment

begin_comment
comment|/// has been forward-declared (with \@class) but not yet defined (with
end_comment

begin_comment
comment|/// \@interface).
end_comment

begin_expr_stmt
specifier|const
name|ObjCInterfaceDecl
operator|*
name|getDefinition
argument_list|()
specifier|const
block|{
return|return
name|hasDefinition
argument_list|()
operator|?
name|Data
operator|.
name|getPointer
argument_list|()
operator|->
name|Definition
operator|:
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Starts the definition of this Objective-C class, taking it from
end_comment

begin_comment
comment|/// a forward declaration (\@class) to a definition (\@interface).
end_comment

begin_function_decl
name|void
name|startDefinition
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|ObjCInterfaceDecl
operator|*
name|getSuperClass
argument_list|()
specifier|const
block|{
comment|// FIXME: Should make sure no callers ever do this.
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|data
argument_list|()
operator|.
name|ExternallyCompleted
condition|)
name|LoadExternalDefinition
argument_list|()
expr_stmt|;
end_if

begin_return
return|return
name|data
argument_list|()
operator|.
name|SuperClass
return|;
end_return

begin_macro
unit|}    void
name|setSuperClass
argument_list|(
argument|ObjCInterfaceDecl * superCls
argument_list|)
end_macro

begin_block
block|{
name|data
argument_list|()
operator|.
name|SuperClass
operator|=
operator|(
name|superCls
operator|&&
name|superCls
operator|->
name|hasDefinition
argument_list|()
operator|)
condition|?
name|superCls
operator|->
name|getDefinition
argument_list|()
else|:
name|superCls
expr_stmt|;
block|}
end_block

begin_comment
comment|/// \brief Iterator that walks over the list of categories, filtering out
end_comment

begin_comment
comment|/// those that do not meet specific criteria.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class template is used for the various permutations of category
end_comment

begin_comment
comment|/// and extension iterators.
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
argument_list|(
operator|*
name|Filter
argument_list|)
argument_list|(
name|ObjCCategoryDecl
operator|*
argument_list|)
operator|>
name|class
name|filtered_category_iterator
block|{
name|ObjCCategoryDecl
operator|*
name|Current
block|;
name|void
name|findAcceptableCategory
argument_list|()
block|;
name|public
operator|:
typedef|typedef
name|ObjCCategoryDecl
modifier|*
name|value_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|value_type
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|value_type
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|ptrdiff_t
name|difference_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|input_iterator_tag
name|iterator_category
expr_stmt|;
end_typedef

begin_expr_stmt
name|filtered_category_iterator
argument_list|()
operator|:
name|Current
argument_list|(
literal|0
argument_list|)
block|{ }
name|explicit
name|filtered_category_iterator
argument_list|(
name|ObjCCategoryDecl
operator|*
name|Current
argument_list|)
operator|:
name|Current
argument_list|(
argument|Current
argument_list|)
block|{
name|findAcceptableCategory
argument_list|()
block|;     }
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Current
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|pointer
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|Current
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|filtered_category_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|filtered_category_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|filtered_category_iterator
name|Tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|Tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
name|filtered_category_iterator
name|X
operator|,
name|filtered_category_iterator
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Current
operator|==
name|Y
operator|.
name|Current
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
name|filtered_category_iterator
name|X
operator|,
name|filtered_category_iterator
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Current
operator|!=
name|Y
operator|.
name|Current
return|;
block|}
end_expr_stmt

begin_label
unit|};
name|private
label|:
end_label

begin_comment
comment|/// \brief Test whether the given category is visible.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used in the \c visible_categories_iterator.
end_comment

begin_function_decl
specifier|static
name|bool
name|isVisibleCategory
parameter_list|(
name|ObjCCategoryDecl
modifier|*
name|Cat
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Iterator that walks over the list of categories and extensions
end_comment

begin_comment
comment|/// that are visible, i.e., not hidden in a non-imported submodule.
end_comment

begin_typedef
typedef|typedef
name|filtered_category_iterator
operator|<
name|isVisibleCategory
operator|>
name|visible_categories_iterator
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Retrieve an iterator to the beginning of the visible-categories
end_comment

begin_comment
comment|/// list.
end_comment

begin_expr_stmt
name|visible_categories_iterator
name|visible_categories_begin
argument_list|()
specifier|const
block|{
return|return
name|visible_categories_iterator
argument_list|(
name|getCategoryListRaw
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve an iterator to the end of the visible-categories list.
end_comment

begin_expr_stmt
name|visible_categories_iterator
name|visible_categories_end
argument_list|()
specifier|const
block|{
return|return
name|visible_categories_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether the visible-categories list is empty.
end_comment

begin_expr_stmt
name|bool
name|visible_categories_empty
argument_list|()
specifier|const
block|{
return|return
name|visible_categories_begin
argument_list|()
operator|==
name|visible_categories_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Test whether the given category... is a category.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used in the \c known_categories_iterator.
end_comment

begin_function
specifier|static
name|bool
name|isKnownCategory
parameter_list|(
name|ObjCCategoryDecl
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Iterator that walks over all of the known categories and
end_comment

begin_comment
comment|/// extensions, including those that are hidden.
end_comment

begin_typedef
typedef|typedef
name|filtered_category_iterator
operator|<
name|isKnownCategory
operator|>
name|known_categories_iterator
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Retrieve an iterator to the beginning of the known-categories
end_comment

begin_comment
comment|/// list.
end_comment

begin_expr_stmt
name|known_categories_iterator
name|known_categories_begin
argument_list|()
specifier|const
block|{
return|return
name|known_categories_iterator
argument_list|(
name|getCategoryListRaw
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve an iterator to the end of the known-categories list.
end_comment

begin_expr_stmt
name|known_categories_iterator
name|known_categories_end
argument_list|()
specifier|const
block|{
return|return
name|known_categories_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether the known-categories list is empty.
end_comment

begin_expr_stmt
name|bool
name|known_categories_empty
argument_list|()
specifier|const
block|{
return|return
name|known_categories_begin
argument_list|()
operator|==
name|known_categories_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Test whether the given category is a visible extension.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used in the \c visible_extensions_iterator.
end_comment

begin_function_decl
specifier|static
name|bool
name|isVisibleExtension
parameter_list|(
name|ObjCCategoryDecl
modifier|*
name|Cat
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Iterator that walks over all of the visible extensions, skipping
end_comment

begin_comment
comment|/// any that are known but hidden.
end_comment

begin_typedef
typedef|typedef
name|filtered_category_iterator
operator|<
name|isVisibleExtension
operator|>
name|visible_extensions_iterator
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Retrieve an iterator to the beginning of the visible-extensions
end_comment

begin_comment
comment|/// list.
end_comment

begin_expr_stmt
name|visible_extensions_iterator
name|visible_extensions_begin
argument_list|()
specifier|const
block|{
return|return
name|visible_extensions_iterator
argument_list|(
name|getCategoryListRaw
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve an iterator to the end of the visible-extensions list.
end_comment

begin_expr_stmt
name|visible_extensions_iterator
name|visible_extensions_end
argument_list|()
specifier|const
block|{
return|return
name|visible_extensions_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether the visible-extensions list is empty.
end_comment

begin_expr_stmt
name|bool
name|visible_extensions_empty
argument_list|()
specifier|const
block|{
return|return
name|visible_extensions_begin
argument_list|()
operator|==
name|visible_extensions_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// \brief Test whether the given category is an extension.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Used in the \c known_extensions_iterator.
end_comment

begin_function_decl
specifier|static
name|bool
name|isKnownExtension
parameter_list|(
name|ObjCCategoryDecl
modifier|*
name|Cat
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_comment
comment|/// \brief Iterator that walks over all of the known extensions.
end_comment

begin_typedef
typedef|typedef
name|filtered_category_iterator
operator|<
name|isKnownExtension
operator|>
name|known_extensions_iterator
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Retrieve an iterator to the beginning of the known-extensions
end_comment

begin_comment
comment|/// list.
end_comment

begin_expr_stmt
name|known_extensions_iterator
name|known_extensions_begin
argument_list|()
specifier|const
block|{
return|return
name|known_extensions_iterator
argument_list|(
name|getCategoryListRaw
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve an iterator to the end of the known-extensions list.
end_comment

begin_expr_stmt
name|known_extensions_iterator
name|known_extensions_end
argument_list|()
specifier|const
block|{
return|return
name|known_extensions_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether the known-extensions list is empty.
end_comment

begin_expr_stmt
name|bool
name|known_extensions_empty
argument_list|()
specifier|const
block|{
return|return
name|known_extensions_begin
argument_list|()
operator|==
name|known_extensions_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the raw pointer to the start of the category/extension
end_comment

begin_comment
comment|/// list.
end_comment

begin_expr_stmt
name|ObjCCategoryDecl
operator|*
name|getCategoryListRaw
argument_list|()
specifier|const
block|{
comment|// FIXME: Should make sure no callers ever do this.
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_if
if|if
condition|(
name|data
argument_list|()
operator|.
name|ExternallyCompleted
condition|)
name|LoadExternalDefinition
argument_list|()
expr_stmt|;
end_if

begin_return
return|return
name|data
argument_list|()
operator|.
name|CategoryList
return|;
end_return

begin_comment
unit|}
comment|/// \brief Set the raw pointer to the start of the category/extension
end_comment

begin_comment
comment|/// list.
end_comment

begin_macro
unit|void
name|setCategoryListRaw
argument_list|(
argument|ObjCCategoryDecl *category
argument_list|)
end_macro

begin_block
block|{
name|data
argument_list|()
operator|.
name|CategoryList
operator|=
name|category
expr_stmt|;
block|}
end_block

begin_decl_stmt
name|ObjCPropertyDecl
modifier|*
name|FindPropertyVisibleInPrimaryClass
argument_list|(
name|IdentifierInfo
operator|*
name|PropertyId
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|void
name|collectPropertiesToImplement
argument_list|(
name|PropertyMap
operator|&
name|PM
argument_list|,
name|PropertyDeclOrder
operator|&
name|PO
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// isSuperClassOf - Return true if this class is the specified class or is a
end_comment

begin_comment
comment|/// super class of the specified interface class.
end_comment

begin_decl_stmt
name|bool
name|isSuperClassOf
argument_list|(
specifier|const
name|ObjCInterfaceDecl
operator|*
name|I
argument_list|)
decl|const
block|{
comment|// If RHS is derived from LHS it is OK; else it is not OK.
while|while
condition|(
name|I
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|declaresSameEntity
argument_list|(
name|this
argument_list|,
name|I
argument_list|)
condition|)
return|return
name|true
return|;
name|I
operator|=
name|I
operator|->
name|getSuperClass
argument_list|()
expr_stmt|;
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|/// isArcWeakrefUnavailable - Checks for a class or one of its super classes
end_comment

begin_comment
comment|/// to be incompatible with __weak references. Returns true if it is.
end_comment

begin_expr_stmt
name|bool
name|isArcWeakrefUnavailable
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// isObjCRequiresPropertyDefs - Checks that a class or one of its super
end_comment

begin_comment
comment|/// classes must not be auto-synthesized. Returns class decl. if it must not
end_comment

begin_comment
comment|/// be; 0, otherwise.
end_comment

begin_expr_stmt
specifier|const
name|ObjCInterfaceDecl
operator|*
name|isObjCRequiresPropertyDefs
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|ObjCIvarDecl
modifier|*
name|lookupInstanceVariable
parameter_list|(
name|IdentifierInfo
modifier|*
name|IVarName
parameter_list|,
name|ObjCInterfaceDecl
modifier|*
modifier|&
name|ClassDeclared
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|ObjCIvarDecl
modifier|*
name|lookupInstanceVariable
parameter_list|(
name|IdentifierInfo
modifier|*
name|IVarName
parameter_list|)
block|{
name|ObjCInterfaceDecl
modifier|*
name|ClassDeclared
decl_stmt|;
return|return
name|lookupInstanceVariable
argument_list|(
name|IVarName
argument_list|,
name|ClassDeclared
argument_list|)
return|;
block|}
end_function

begin_function_decl
name|ObjCProtocolDecl
modifier|*
name|lookupNestedProtocol
parameter_list|(
name|IdentifierInfo
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Lookup a method. First, we search locally. If a method isn't
end_comment

begin_comment
comment|// found, we search referenced protocols and class categories.
end_comment

begin_decl_stmt
name|ObjCMethodDecl
modifier|*
name|lookupMethod
argument_list|(
name|Selector
name|Sel
argument_list|,
name|bool
name|isInstance
argument_list|,
name|bool
name|shallowCategoryLookup
operator|=
name|false
argument_list|,
specifier|const
name|ObjCCategoryDecl
operator|*
name|C
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ObjCMethodDecl
modifier|*
name|lookupInstanceMethod
argument_list|(
name|Selector
name|Sel
argument_list|,
name|bool
name|shallowCategoryLookup
operator|=
name|false
argument_list|)
decl|const
block|{
return|return
name|lookupMethod
argument_list|(
name|Sel
argument_list|,
name|true
comment|/*isInstance*/
argument_list|,
name|shallowCategoryLookup
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|ObjCMethodDecl
modifier|*
name|lookupClassMethod
argument_list|(
name|Selector
name|Sel
argument_list|,
name|bool
name|shallowCategoryLookup
operator|=
name|false
argument_list|)
decl|const
block|{
return|return
name|lookupMethod
argument_list|(
name|Sel
argument_list|,
name|false
comment|/*isInstance*/
argument_list|,
name|shallowCategoryLookup
argument_list|)
return|;
block|}
end_decl_stmt

begin_function_decl
name|ObjCInterfaceDecl
modifier|*
name|lookupInheritedClass
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|ICName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Lookup a method in the classes implementation hierarchy.
end_comment

begin_decl_stmt
name|ObjCMethodDecl
modifier|*
name|lookupPrivateMethod
argument_list|(
specifier|const
name|Selector
operator|&
name|Sel
argument_list|,
name|bool
name|Instance
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function
name|ObjCMethodDecl
modifier|*
name|lookupPrivateClassMethod
parameter_list|(
specifier|const
name|Selector
modifier|&
name|Sel
parameter_list|)
block|{
return|return
name|lookupPrivateMethod
argument_list|(
name|Sel
argument_list|,
name|false
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Lookup a setter or getter in the class hierarchy,
end_comment

begin_comment
comment|/// including in all categories except for category passed
end_comment

begin_comment
comment|/// as argument.
end_comment

begin_decl_stmt
name|ObjCMethodDecl
modifier|*
name|lookupPropertyAccessor
argument_list|(
specifier|const
name|Selector
name|Sel
argument_list|,
specifier|const
name|ObjCCategoryDecl
operator|*
name|Cat
argument_list|)
decl|const
block|{
return|return
name|lookupMethod
argument_list|(
name|Sel
argument_list|,
name|true
comment|/*isInstance*/
argument_list|,
name|false
comment|/*shallowCategoryLookup*/
argument_list|,
name|Cat
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|SourceLocation
name|getEndOfDefinitionLoc
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
name|getLocation
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|data
argument_list|()
operator|.
name|EndLoc
return|;
end_return

begin_macro
unit|}                              void
name|setEndOfDefinitionLoc
argument_list|(
argument|SourceLocation LE
argument_list|)
end_macro

begin_block
block|{
name|data
argument_list|()
operator|.
name|EndLoc
operator|=
name|LE
expr_stmt|;
block|}
end_block

begin_function
name|void
name|setSuperClassLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|data
argument_list|()
operator|.
name|SuperClassLoc
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SourceLocation
name|getSuperClassLoc
argument_list|()
specifier|const
block|{
return|return
name|data
argument_list|()
operator|.
name|SuperClassLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isImplicitInterfaceDecl - check that this is an implicitly declared
end_comment

begin_comment
comment|/// ObjCInterfaceDecl node. This is for legacy objective-c \@implementation
end_comment

begin_comment
comment|/// declaration without an \@interface declaration.
end_comment

begin_expr_stmt
name|bool
name|isImplicitInterfaceDecl
argument_list|()
specifier|const
block|{
return|return
name|hasDefinition
argument_list|()
operator|?
name|data
argument_list|()
operator|.
name|Definition
operator|->
name|isImplicit
argument_list|()
operator|:
name|isImplicit
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// ClassImplementsProtocol - Checks that 'lProto' protocol
end_comment

begin_comment
comment|/// has been implemented in IDecl class, its super class or categories (if
end_comment

begin_comment
comment|/// lookupCategory is true).
end_comment

begin_function_decl
name|bool
name|ClassImplementsProtocol
parameter_list|(
name|ObjCProtocolDecl
modifier|*
name|lProto
parameter_list|,
name|bool
name|lookupCategory
parameter_list|,
name|bool
name|RHSIsQualifiedID
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|redeclarable_base
operator|::
name|redecl_iterator
name|redecl_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls_begin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls_end
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getPreviousDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getMostRecentDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|isFirstDecl
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Retrieves the canonical declaration of this Objective-C class.
end_comment

begin_function
name|ObjCInterfaceDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
block|{
return|return
name|getFirstDecl
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|ObjCInterfaceDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|getFirstDecl
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Low-level accessor
end_comment

begin_expr_stmt
specifier|const
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
end_expr_stmt

begin_decl_stmt
name|void
name|setTypeForDecl
argument_list|(
specifier|const
name|Type
operator|*
name|TD
argument_list|)
decl|const
block|{
name|TypeForDecl
operator|=
name|TD
expr_stmt|;
block|}
end_decl_stmt

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
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|ObjCInterface
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// ObjCIvarDecl - Represents an ObjC instance variable. In general, ObjC
end_comment

begin_comment
comment|/// instance variables are identical to C. The only exception is Objective-C
end_comment

begin_comment
comment|/// supports C++ style access control. For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   \@interface IvarExample : NSObject
end_comment

begin_comment
comment|///   {
end_comment

begin_comment
comment|///     id defaultToProtected;
end_comment

begin_comment
comment|///   \@public:
end_comment

begin_comment
comment|///     id canBePublic; // same as C++.
end_comment

begin_comment
comment|///   \@protected:
end_comment

begin_comment
comment|///     id canBeProtected; // same as C++.
end_comment

begin_comment
comment|///   \@package:
end_comment

begin_comment
comment|///     id canBePackage; // framework visibility (not available in C++).
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ObjCIvarDecl
range|:
name|public
name|FieldDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
expr|enum
name|AccessControl
block|{
name|None
block|,
name|Private
block|,
name|Protected
block|,
name|Public
block|,
name|Package
block|}
block|;
name|private
operator|:
name|ObjCIvarDecl
argument_list|(
argument|ObjCContainerDecl *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|AccessControl ac
argument_list|,
argument|Expr *BW
argument_list|,
argument|bool synthesized
argument_list|,
argument|bool backingIvarReferencedInAccessor
argument_list|)
operator|:
name|FieldDecl
argument_list|(
name|ObjCIvar
argument_list|,
name|DC
argument_list|,
name|StartLoc
argument_list|,
name|IdLoc
argument_list|,
name|Id
argument_list|,
name|T
argument_list|,
name|TInfo
argument_list|,
name|BW
argument_list|,
comment|/*Mutable=*/
name|false
argument_list|,
comment|/*HasInit=*/
name|ICIS_NoInit
argument_list|)
block|,
name|NextIvar
argument_list|(
literal|0
argument_list|)
block|,
name|DeclAccess
argument_list|(
name|ac
argument_list|)
block|,
name|Synthesized
argument_list|(
name|synthesized
argument_list|)
block|,
name|BackingIvarReferencedInAccessor
argument_list|(
argument|backingIvarReferencedInAccessor
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ObjCIvarDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|ObjCContainerDecl *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|,
argument|AccessControl ac
argument_list|,
argument|Expr *BW = NULL
argument_list|,
argument|bool synthesized=false
argument_list|,
argument|bool backingIvarReferencedInAccessor=false
argument_list|)
block|;
specifier|static
name|ObjCIvarDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
comment|/// \brief Return the class interface that this ivar is logically contained
comment|/// in; this is either the interface where the ivar was declared, or the
comment|/// interface the ivar is conceptually a part of in the case of synthesized
comment|/// ivars.
specifier|const
name|ObjCInterfaceDecl
operator|*
name|getContainingInterface
argument_list|()
specifier|const
block|;
name|ObjCIvarDecl
operator|*
name|getNextIvar
argument_list|()
block|{
return|return
name|NextIvar
return|;
block|}
specifier|const
name|ObjCIvarDecl
operator|*
name|getNextIvar
argument_list|()
specifier|const
block|{
return|return
name|NextIvar
return|;
block|}
name|void
name|setNextIvar
argument_list|(
argument|ObjCIvarDecl *ivar
argument_list|)
block|{
name|NextIvar
operator|=
name|ivar
block|; }
name|void
name|setAccessControl
argument_list|(
argument|AccessControl ac
argument_list|)
block|{
name|DeclAccess
operator|=
name|ac
block|; }
name|AccessControl
name|getAccessControl
argument_list|()
specifier|const
block|{
return|return
name|AccessControl
argument_list|(
name|DeclAccess
argument_list|)
return|;
block|}
name|AccessControl
name|getCanonicalAccessControl
argument_list|()
specifier|const
block|{
return|return
name|DeclAccess
operator|==
name|None
operator|?
name|Protected
operator|:
name|AccessControl
argument_list|(
name|DeclAccess
argument_list|)
return|;
block|}
name|void
name|setBackingIvarReferencedInAccessor
argument_list|(
argument|bool val
argument_list|)
block|{
name|BackingIvarReferencedInAccessor
operator|=
name|val
block|;   }
name|bool
name|getBackingIvarReferencedInAccessor
argument_list|()
specifier|const
block|{
return|return
name|BackingIvarReferencedInAccessor
return|;
block|}
name|void
name|setSynthesize
argument_list|(
argument|bool synth
argument_list|)
block|{
name|Synthesized
operator|=
name|synth
block|; }
name|bool
name|getSynthesize
argument_list|()
specifier|const
block|{
return|return
name|Synthesized
return|;
block|}
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|ObjCIvar
return|;
block|}
name|private
operator|:
comment|/// NextIvar - Next Ivar in the list of ivars declared in class; class's
comment|/// extensions and class's implementation
name|ObjCIvarDecl
operator|*
name|NextIvar
block|;
comment|// NOTE: VC++ treats enums as signed, avoid using the AccessControl enum
name|unsigned
name|DeclAccess
operator|:
literal|3
block|;
name|unsigned
name|Synthesized
operator|:
literal|1
block|;
name|unsigned
name|BackingIvarReferencedInAccessor
operator|:
literal|1
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Represents a field declaration created by an \@defs(...).
end_comment

begin_decl_stmt
name|class
name|ObjCAtDefsFieldDecl
range|:
name|public
name|FieldDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|ObjCAtDefsFieldDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|Expr *BW
argument_list|)
operator|:
name|FieldDecl
argument_list|(
argument|ObjCAtDefsField
argument_list|,
argument|DC
argument_list|,
argument|StartLoc
argument_list|,
argument|IdLoc
argument_list|,
argument|Id
argument_list|,
argument|T
argument_list|,
comment|/*TInfo=*/
literal|0
argument_list|,
comment|// FIXME: Do ObjCAtDefs have declarators ?
argument|BW
argument_list|,
comment|/*Mutable=*/
argument|false
argument_list|,
comment|/*HasInit=*/
argument|ICIS_NoInit
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ObjCAtDefsFieldDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation StartLoc
argument_list|,
argument|SourceLocation IdLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|Expr *BW
argument_list|)
block|;
specifier|static
name|ObjCAtDefsFieldDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
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
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|ObjCAtDefsField
return|;
block|}
expr|}
block|;
comment|/// \brief Represents an Objective-C protocol declaration.
comment|///
comment|/// Objective-C protocols declare a pure abstract type (i.e., no instance
comment|/// variables are permitted).  Protocols originally drew inspiration from
comment|/// C++ pure virtual functions (a C++ feature with nice semantics and lousy
comment|/// syntax:-). Here is an example:
comment|///
comment|/// \code
comment|/// \@protocol NSDraggingInfo<refproto1, refproto2>
comment|/// - (NSWindow *)draggingDestinationWindow;
comment|/// - (NSImage *)draggedImage;
comment|/// \@end
comment|/// \endcode
comment|///
comment|/// This says that NSDraggingInfo requires two methods and requires everything
comment|/// that the two "referenced protocols" 'refproto1' and 'refproto2' require as
comment|/// well.
comment|///
comment|/// \code
comment|/// \@interface ImplementsNSDraggingInfo : NSObject \<NSDraggingInfo>
comment|/// \@end
comment|/// \endcode
comment|///
comment|/// ObjC protocols inspired Java interfaces. Unlike Java, ObjC classes and
comment|/// protocols are in distinct namespaces. For example, Cocoa defines both
comment|/// an NSObject protocol and class (which isn't allowed in Java). As a result,
comment|/// protocols are referenced using angle brackets as follows:
comment|///
comment|/// id \<NSDraggingInfo> anyObjectThatImplementsNSDraggingInfo;
comment|///
name|class
name|ObjCProtocolDecl
operator|:
name|public
name|ObjCContainerDecl
block|,
name|public
name|Redeclarable
operator|<
name|ObjCProtocolDecl
operator|>
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;    struct
name|DefinitionData
block|{
comment|// \brief The declaration that defines this protocol.
name|ObjCProtocolDecl
operator|*
name|Definition
block|;
comment|/// \brief Referenced protocols
name|ObjCProtocolList
name|ReferencedProtocols
block|;       }
block|;
comment|/// \brief Contains a pointer to the data associated with this class,
comment|/// which will be NULL if this class has not yet been defined.
comment|///
comment|/// The bit indicates when we don't need to check for out-of-date
comment|/// declarations. It will be set unless modules are enabled.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|DefinitionData
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|Data
block|;
name|DefinitionData
operator|&
name|data
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Data
operator|.
name|getPointer
argument_list|()
operator|&&
literal|"Objective-C protocol has no definition!"
argument_list|)
block|;
return|return
operator|*
name|Data
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|ObjCProtocolDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|SourceLocation nameLoc
argument_list|,
argument|SourceLocation atStartLoc
argument_list|,
argument|ObjCProtocolDecl *PrevDecl
argument_list|)
block|;
name|void
name|allocateDefinitionData
argument_list|()
block|;
typedef|typedef
name|Redeclarable
operator|<
name|ObjCProtocolDecl
operator|>
name|redeclarable_base
expr_stmt|;
name|virtual
name|ObjCProtocolDecl
operator|*
name|getNextRedeclaration
argument_list|()
block|{
return|return
name|RedeclLink
operator|.
name|getNext
argument_list|()
return|;
block|}
name|virtual
name|ObjCProtocolDecl
operator|*
name|getPreviousDeclImpl
argument_list|()
block|{
return|return
name|getPreviousDecl
argument_list|()
return|;
block|}
name|virtual
name|ObjCProtocolDecl
operator|*
name|getMostRecentDeclImpl
argument_list|()
block|{
return|return
name|getMostRecentDecl
argument_list|()
return|;
block|}
name|public
operator|:
specifier|static
name|ObjCProtocolDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|SourceLocation nameLoc
argument_list|,
argument|SourceLocation atStartLoc
argument_list|,
argument|ObjCProtocolDecl *PrevDecl
argument_list|)
block|;
specifier|static
name|ObjCProtocolDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
specifier|const
name|ObjCProtocolList
operator|&
name|getReferencedProtocols
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|hasDefinition
argument_list|()
operator|&&
literal|"No definition available!"
argument_list|)
block|;
return|return
name|data
argument_list|()
operator|.
name|ReferencedProtocols
return|;
block|}
typedef|typedef
name|ObjCProtocolList
operator|::
name|iterator
name|protocol_iterator
expr_stmt|;
name|protocol_iterator
name|protocol_begin
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
name|protocol_iterator
argument_list|()
return|;
end_decl_stmt

begin_return
return|return
name|data
argument_list|()
operator|.
name|ReferencedProtocols
operator|.
name|begin
argument_list|()
return|;
end_return

begin_macro
unit|}   protocol_iterator
name|protocol_end
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
name|protocol_iterator
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|data
argument_list|()
operator|.
name|ReferencedProtocols
operator|.
name|end
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}   typedef
name|ObjCProtocolList
operator|::
name|loc_iterator
name|protocol_loc_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|protocol_loc_iterator
name|protocol_loc_begin
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
name|protocol_loc_iterator
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|data
argument_list|()
operator|.
name|ReferencedProtocols
operator|.
name|loc_begin
argument_list|()
return|;
end_return

begin_macro
unit|}   protocol_loc_iterator
name|protocol_loc_end
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
name|protocol_loc_iterator
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|data
argument_list|()
operator|.
name|ReferencedProtocols
operator|.
name|loc_end
argument_list|()
return|;
end_return

begin_macro
unit|}   unsigned
name|protocol_size
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
if|if
condition|(
operator|!
name|hasDefinition
argument_list|()
condition|)
return|return
literal|0
return|;
end_expr_stmt

begin_return
return|return
name|data
argument_list|()
operator|.
name|ReferencedProtocols
operator|.
name|size
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// setProtocolList - Set the list of protocols that this interface
end_comment

begin_comment
comment|/// implements.
end_comment

begin_macro
unit|void
name|setProtocolList
argument_list|(
argument|ObjCProtocolDecl *const*List
argument_list|,
argument|unsigned Num
argument_list|,
argument|const SourceLocation *Locs
argument_list|,
argument|ASTContext&C
argument_list|)
end_macro

begin_block
block|{
name|assert
argument_list|(
name|hasDefinition
argument_list|()
operator|&&
literal|"Protocol is not defined"
argument_list|)
expr_stmt|;
name|data
argument_list|()
operator|.
name|ReferencedProtocols
operator|.
name|set
argument_list|(
name|List
argument_list|,
name|Num
argument_list|,
name|Locs
argument_list|,
name|C
argument_list|)
expr_stmt|;
block|}
end_block

begin_function_decl
name|ObjCProtocolDecl
modifier|*
name|lookupProtocolNamed
parameter_list|(
name|IdentifierInfo
modifier|*
name|PName
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Lookup a method. First, we search locally. If a method isn't
end_comment

begin_comment
comment|// found, we search referenced protocols and class categories.
end_comment

begin_decl_stmt
name|ObjCMethodDecl
modifier|*
name|lookupMethod
argument_list|(
name|Selector
name|Sel
argument_list|,
name|bool
name|isInstance
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ObjCMethodDecl
modifier|*
name|lookupInstanceMethod
argument_list|(
name|Selector
name|Sel
argument_list|)
decl|const
block|{
return|return
name|lookupMethod
argument_list|(
name|Sel
argument_list|,
name|true
comment|/*isInstance*/
argument_list|)
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|ObjCMethodDecl
modifier|*
name|lookupClassMethod
argument_list|(
name|Selector
name|Sel
argument_list|)
decl|const
block|{
return|return
name|lookupMethod
argument_list|(
name|Sel
argument_list|,
name|false
comment|/*isInstance*/
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Determine whether this protocol has a definition.
end_comment

begin_expr_stmt
name|bool
name|hasDefinition
argument_list|()
specifier|const
block|{
comment|// If the name of this protocol is out-of-date, bring it up-to-date, which
comment|// might bring in a definition.
comment|// Note: a null value indicates that we don't have a definition and that
comment|// modules are enabled.
if|if
condition|(
operator|!
name|Data
operator|.
name|getOpaqueValue
argument_list|()
condition|)
block|{
if|if
condition|(
name|IdentifierInfo
modifier|*
name|II
init|=
name|getIdentifier
argument_list|()
condition|)
block|{
if|if
condition|(
name|II
operator|->
name|isOutOfDate
argument_list|()
condition|)
block|{
name|updateOutOfDate
argument_list|(
operator|*
name|II
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
unit|}     }
return|return
name|Data
operator|.
name|getPointer
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// \brief Retrieve the definition of this protocol, if any.
end_comment

begin_expr_stmt
unit|ObjCProtocolDecl
operator|*
name|getDefinition
argument_list|()
block|{
return|return
name|hasDefinition
argument_list|()
operator|?
name|Data
operator|.
name|getPointer
argument_list|()
operator|->
name|Definition
operator|:
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the definition of this protocol, if any.
end_comment

begin_expr_stmt
specifier|const
name|ObjCProtocolDecl
operator|*
name|getDefinition
argument_list|()
specifier|const
block|{
return|return
name|hasDefinition
argument_list|()
operator|?
name|Data
operator|.
name|getPointer
argument_list|()
operator|->
name|Definition
operator|:
literal|0
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Determine whether this particular declaration is also the
end_comment

begin_comment
comment|/// definition.
end_comment

begin_expr_stmt
name|bool
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|getDefinition
argument_list|()
operator|==
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Starts the definition of this Objective-C protocol.
end_comment

begin_function_decl
name|void
name|startDefinition
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
name|isThisDeclarationADefinition
argument_list|()
condition|)
return|return
name|ObjCContainerDecl
operator|::
name|getSourceRange
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|SourceRange
argument_list|(
name|getAtStartLoc
argument_list|()
argument_list|,
name|getLocation
argument_list|()
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}       typedef
name|redeclarable_base
operator|::
name|redecl_iterator
name|redecl_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls_begin
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|redecls_end
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getPreviousDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|getMostRecentDecl
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|redeclarable_base
operator|::
name|isFirstDecl
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Retrieves the canonical declaration of this Objective-C protocol.
end_comment

begin_function
name|ObjCProtocolDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
block|{
return|return
name|getFirstDecl
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|ObjCProtocolDecl
operator|*
name|getCanonicalDecl
argument_list|()
specifier|const
block|{
return|return
name|getFirstDecl
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|virtual
name|void
name|collectPropertiesToImplement
argument_list|(
name|PropertyMap
operator|&
name|PM
argument_list|,
name|PropertyDeclOrder
operator|&
name|PO
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|collectInheritedProtocolProperties
argument_list|(
specifier|const
name|ObjCPropertyDecl
operator|*
name|Property
argument_list|,
name|ProtocolPropertyMap
operator|&
name|PM
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|ObjCProtocol
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// ObjCCategoryDecl - Represents a category declaration. A category allows
end_comment

begin_comment
comment|/// you to add methods to an existing class (without subclassing or modifying
end_comment

begin_comment
comment|/// the original class interface or implementation:-). Categories don't allow
end_comment

begin_comment
comment|/// you to add instance data. The following example adds "myMethod" to all
end_comment

begin_comment
comment|/// NSView's within a process:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \@interface NSView (MyViewMethods)
end_comment

begin_comment
comment|/// - myMethod;
end_comment

begin_comment
comment|/// \@end
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Categories also allow you to split the implementation of a class across
end_comment

begin_comment
comment|/// several files (a feature more naturally supported in C++).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Categories were originally inspired by dynamic languages such as Common
end_comment

begin_comment
comment|/// Lisp and Smalltalk.  More traditional class-based languages (C++, Java)
end_comment

begin_comment
comment|/// don't support this level of dynamism, which is both powerful and dangerous.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ObjCCategoryDecl
range|:
name|public
name|ObjCContainerDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// Interface belonging to this category
name|ObjCInterfaceDecl
operator|*
name|ClassInterface
block|;
comment|/// referenced protocols in this category.
name|ObjCProtocolList
name|ReferencedProtocols
block|;
comment|/// Next category belonging to this class.
comment|/// FIXME: this should not be a singly-linked list.  Move storage elsewhere.
name|ObjCCategoryDecl
operator|*
name|NextClassCategory
block|;
comment|/// \brief The location of the category name in this declaration.
name|SourceLocation
name|CategoryNameLoc
block|;
comment|/// class extension may have private ivars.
name|SourceLocation
name|IvarLBraceLoc
block|;
name|SourceLocation
name|IvarRBraceLoc
block|;
name|ObjCCategoryDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation AtLoc
argument_list|,
argument|SourceLocation ClassNameLoc
argument_list|,
argument|SourceLocation CategoryNameLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|ObjCInterfaceDecl *IDecl
argument_list|,
argument|SourceLocation IvarLBraceLoc=SourceLocation()
argument_list|,
argument|SourceLocation IvarRBraceLoc=SourceLocation()
argument_list|)
operator|:
name|ObjCContainerDecl
argument_list|(
name|ObjCCategory
argument_list|,
name|DC
argument_list|,
name|Id
argument_list|,
name|ClassNameLoc
argument_list|,
name|AtLoc
argument_list|)
block|,
name|ClassInterface
argument_list|(
name|IDecl
argument_list|)
block|,
name|NextClassCategory
argument_list|(
literal|0
argument_list|)
block|,
name|CategoryNameLoc
argument_list|(
name|CategoryNameLoc
argument_list|)
block|,
name|IvarLBraceLoc
argument_list|(
name|IvarLBraceLoc
argument_list|)
block|,
name|IvarRBraceLoc
argument_list|(
argument|IvarRBraceLoc
argument_list|)
block|{   }
name|public
operator|:
specifier|static
name|ObjCCategoryDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation AtLoc
argument_list|,
argument|SourceLocation ClassNameLoc
argument_list|,
argument|SourceLocation CategoryNameLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|ObjCInterfaceDecl *IDecl
argument_list|,
argument|SourceLocation IvarLBraceLoc=SourceLocation()
argument_list|,
argument|SourceLocation IvarRBraceLoc=SourceLocation()
argument_list|)
block|;
specifier|static
name|ObjCCategoryDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|ObjCInterfaceDecl
operator|*
name|getClassInterface
argument_list|()
block|{
return|return
name|ClassInterface
return|;
block|}
specifier|const
name|ObjCInterfaceDecl
operator|*
name|getClassInterface
argument_list|()
specifier|const
block|{
return|return
name|ClassInterface
return|;
block|}
name|ObjCCategoryImplDecl
operator|*
name|getImplementation
argument_list|()
specifier|const
block|;
name|void
name|setImplementation
argument_list|(
name|ObjCCategoryImplDecl
operator|*
name|ImplD
argument_list|)
block|;
comment|/// setProtocolList - Set the list of protocols that this interface
comment|/// implements.
name|void
name|setProtocolList
argument_list|(
argument|ObjCProtocolDecl *const*List
argument_list|,
argument|unsigned Num
argument_list|,
argument|const SourceLocation *Locs
argument_list|,
argument|ASTContext&C
argument_list|)
block|{
name|ReferencedProtocols
operator|.
name|set
argument_list|(
name|List
argument_list|,
name|Num
argument_list|,
name|Locs
argument_list|,
name|C
argument_list|)
block|;   }
specifier|const
name|ObjCProtocolList
operator|&
name|getReferencedProtocols
argument_list|()
specifier|const
block|{
return|return
name|ReferencedProtocols
return|;
block|}
typedef|typedef
name|ObjCProtocolList
operator|::
name|iterator
name|protocol_iterator
expr_stmt|;
name|protocol_iterator
name|protocol_begin
argument_list|()
specifier|const
block|{
return|return
name|ReferencedProtocols
operator|.
name|begin
argument_list|()
return|;
block|}
name|protocol_iterator
name|protocol_end
argument_list|()
specifier|const
block|{
return|return
name|ReferencedProtocols
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|protocol_size
argument_list|()
specifier|const
block|{
return|return
name|ReferencedProtocols
operator|.
name|size
argument_list|()
return|;
block|}
end_decl_stmt

begin_typedef
typedef|typedef
name|ObjCProtocolList
operator|::
name|loc_iterator
name|protocol_loc_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|protocol_loc_iterator
name|protocol_loc_begin
argument_list|()
specifier|const
block|{
return|return
name|ReferencedProtocols
operator|.
name|loc_begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|protocol_loc_iterator
name|protocol_loc_end
argument_list|()
specifier|const
block|{
return|return
name|ReferencedProtocols
operator|.
name|loc_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ObjCCategoryDecl
operator|*
name|getNextClassCategory
argument_list|()
specifier|const
block|{
return|return
name|NextClassCategory
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Retrieve the pointer to the next stored category (or extension),
end_comment

begin_comment
comment|/// which may be hidden.
end_comment

begin_expr_stmt
name|ObjCCategoryDecl
operator|*
name|getNextClassCategoryRaw
argument_list|()
specifier|const
block|{
return|return
name|NextClassCategory
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|IsClassExtension
argument_list|()
specifier|const
block|{
return|return
name|getIdentifier
argument_list|()
operator|==
literal|0
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|specific_decl_iterator
operator|<
name|ObjCIvarDecl
operator|>
name|ivar_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|ivar_iterator
name|ivar_begin
argument_list|()
specifier|const
block|{
return|return
name|ivar_iterator
argument_list|(
name|decls_begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ivar_iterator
name|ivar_end
argument_list|()
specifier|const
block|{
return|return
name|ivar_iterator
argument_list|(
name|decls_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|ivar_size
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|distance
argument_list|(
name|ivar_begin
argument_list|()
argument_list|,
name|ivar_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|ivar_empty
argument_list|()
specifier|const
block|{
return|return
name|ivar_begin
argument_list|()
operator|==
name|ivar_end
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getCategoryNameLoc
argument_list|()
specifier|const
block|{
return|return
name|CategoryNameLoc
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setCategoryNameLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|CategoryNameLoc
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setIvarLBraceLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|IvarLBraceLoc
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SourceLocation
name|getIvarLBraceLoc
argument_list|()
specifier|const
block|{
return|return
name|IvarLBraceLoc
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setIvarRBraceLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|IvarRBraceLoc
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SourceLocation
name|getIvarRBraceLoc
argument_list|()
specifier|const
block|{
return|return
name|IvarRBraceLoc
return|;
block|}
end_expr_stmt

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
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|ObjCCategory
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
unit|};
name|class
name|ObjCImplDecl
range|:
name|public
name|ObjCContainerDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// Class interface for this class/category implementation
name|ObjCInterfaceDecl
operator|*
name|ClassInterface
block|;
name|protected
operator|:
name|ObjCImplDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|ObjCInterfaceDecl *classInterface
argument_list|,
argument|SourceLocation nameLoc
argument_list|,
argument|SourceLocation atStartLoc
argument_list|)
operator|:
name|ObjCContainerDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|classInterface
condition|?
name|classInterface
operator|->
name|getIdentifier
argument_list|()
else|:
literal|0
argument_list|,
name|nameLoc
argument_list|,
name|atStartLoc
argument_list|)
block|,
name|ClassInterface
argument_list|(
argument|classInterface
argument_list|)
block|{}
name|public
operator|:
specifier|const
name|ObjCInterfaceDecl
operator|*
name|getClassInterface
argument_list|()
specifier|const
block|{
return|return
name|ClassInterface
return|;
block|}
name|ObjCInterfaceDecl
operator|*
name|getClassInterface
argument_list|()
block|{
return|return
name|ClassInterface
return|;
block|}
name|void
name|setClassInterface
argument_list|(
name|ObjCInterfaceDecl
operator|*
name|IFace
argument_list|)
block|;
name|void
name|addInstanceMethod
argument_list|(
argument|ObjCMethodDecl *method
argument_list|)
block|{
comment|// FIXME: Context should be set correctly before we get here.
name|method
operator|->
name|setLexicalDeclContext
argument_list|(
name|this
argument_list|)
block|;
name|addDecl
argument_list|(
name|method
argument_list|)
block|;   }
name|void
name|addClassMethod
argument_list|(
argument|ObjCMethodDecl *method
argument_list|)
block|{
comment|// FIXME: Context should be set correctly before we get here.
name|method
operator|->
name|setLexicalDeclContext
argument_list|(
name|this
argument_list|)
block|;
name|addDecl
argument_list|(
name|method
argument_list|)
block|;   }
name|void
name|addPropertyImplementation
argument_list|(
name|ObjCPropertyImplDecl
operator|*
name|property
argument_list|)
block|;
name|ObjCPropertyImplDecl
operator|*
name|FindPropertyImplDecl
argument_list|(
argument|IdentifierInfo *propertyId
argument_list|)
specifier|const
block|;
name|ObjCPropertyImplDecl
operator|*
name|FindPropertyImplIvarDecl
argument_list|(
argument|IdentifierInfo *ivarId
argument_list|)
specifier|const
block|;
comment|// Iterator access to properties.
typedef|typedef
name|specific_decl_iterator
operator|<
name|ObjCPropertyImplDecl
operator|>
name|propimpl_iterator
expr_stmt|;
name|propimpl_iterator
name|propimpl_begin
argument_list|()
specifier|const
block|{
return|return
name|propimpl_iterator
argument_list|(
name|decls_begin
argument_list|()
argument_list|)
return|;
block|}
name|propimpl_iterator
name|propimpl_end
argument_list|()
specifier|const
block|{
return|return
name|propimpl_iterator
argument_list|(
name|decls_end
argument_list|()
argument_list|)
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
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|>=
name|firstObjCImpl
operator|&&
name|K
operator|<=
name|lastObjCImpl
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// ObjCCategoryImplDecl - An object of this class encapsulates a category
end_comment

begin_comment
comment|/// \@implementation declaration. If a category class has declaration of a
end_comment

begin_comment
comment|/// property, its implementation must be specified in the category's
end_comment

begin_comment
comment|/// \@implementation declaration. Example:
end_comment

begin_comment
comment|/// \@interface I \@end
end_comment

begin_comment
comment|/// \@interface I(CATEGORY)
end_comment

begin_comment
comment|///    \@property int p1, d1;
end_comment

begin_comment
comment|/// \@end
end_comment

begin_comment
comment|/// \@implementation I(CATEGORY)
end_comment

begin_comment
comment|///  \@dynamic p1,d1;
end_comment

begin_comment
comment|/// \@end
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ObjCCategoryImplDecl
end_comment

begin_decl_stmt
name|class
name|ObjCCategoryImplDecl
range|:
name|public
name|ObjCImplDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|// Category name
name|IdentifierInfo
operator|*
name|Id
block|;
comment|// Category name location
name|SourceLocation
name|CategoryNameLoc
block|;
name|ObjCCategoryImplDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|ObjCInterfaceDecl *classInterface
argument_list|,
argument|SourceLocation nameLoc
argument_list|,
argument|SourceLocation atStartLoc
argument_list|,
argument|SourceLocation CategoryNameLoc
argument_list|)
operator|:
name|ObjCImplDecl
argument_list|(
name|ObjCCategoryImpl
argument_list|,
name|DC
argument_list|,
name|classInterface
argument_list|,
name|nameLoc
argument_list|,
name|atStartLoc
argument_list|)
block|,
name|Id
argument_list|(
name|Id
argument_list|)
block|,
name|CategoryNameLoc
argument_list|(
argument|CategoryNameLoc
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ObjCCategoryImplDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|ObjCInterfaceDecl *classInterface
argument_list|,
argument|SourceLocation nameLoc
argument_list|,
argument|SourceLocation atStartLoc
argument_list|,
argument|SourceLocation CategoryNameLoc
argument_list|)
block|;
specifier|static
name|ObjCCategoryImplDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
comment|/// getIdentifier - Get the identifier that names the category
comment|/// interface associated with this implementation.
comment|/// FIXME: This is a bad API, we are overriding the NamedDecl::getIdentifier()
comment|/// to mean something different. For example:
comment|/// ((NamedDecl *)SomeCategoryImplDecl)->getIdentifier()
comment|/// returns the class interface name, whereas
comment|/// ((ObjCCategoryImplDecl *)SomeCategoryImplDecl)->getIdentifier()
comment|/// returns the category name.
name|IdentifierInfo
operator|*
name|getIdentifier
argument_list|()
specifier|const
block|{
return|return
name|Id
return|;
block|}
name|void
name|setIdentifier
argument_list|(
argument|IdentifierInfo *II
argument_list|)
block|{
name|Id
operator|=
name|II
block|; }
name|ObjCCategoryDecl
operator|*
name|getCategoryDecl
argument_list|()
specifier|const
block|;
name|SourceLocation
name|getCategoryNameLoc
argument_list|()
specifier|const
block|{
return|return
name|CategoryNameLoc
return|;
block|}
comment|/// getName - Get the name of identifier for the class interface associated
comment|/// with this implementation as a StringRef.
comment|//
comment|// FIXME: This is a bad API, we are overriding the NamedDecl::getName, to mean
comment|// something different.
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Id
operator|?
name|Id
operator|->
name|getNameStart
argument_list|()
operator|:
literal|""
return|;
block|}
comment|/// @brief Get the name of the class associated with this interface.
comment|//
comment|// FIXME: Deprecated, move clients to getName().
name|std
operator|::
name|string
name|getNameAsString
argument_list|()
specifier|const
block|{
return|return
name|getName
argument_list|()
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
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|ObjCCategoryImpl
return|;
block|}
name|friend
name|class
name|ASTDeclReader
block|;
name|friend
name|class
name|ASTDeclWriter
block|; }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|ObjCCategoryImplDecl
operator|&
name|CID
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// ObjCImplementationDecl - Represents a class definition - this is where
end_comment

begin_comment
comment|/// method definitions are specified. For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @code
end_comment

begin_comment
comment|/// \@implementation MyClass
end_comment

begin_comment
comment|/// - (void)myMethod { /* do something */ }
end_comment

begin_comment
comment|/// \@end
end_comment

begin_comment
comment|/// @endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Typically, instance variables are specified in the class interface,
end_comment

begin_comment
comment|/// *not* in the implementation. Nevertheless (for legacy reasons), we
end_comment

begin_comment
comment|/// allow instance variables to be specified in the implementation.  When
end_comment

begin_comment
comment|/// specified, they need to be *identical* to the interface.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ObjCImplementationDecl
range|:
name|public
name|ObjCImplDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// Implementation Class's super class.
name|ObjCInterfaceDecl
operator|*
name|SuperClass
block|;
name|SourceLocation
name|SuperLoc
block|;
comment|/// \@implementation may have private ivars.
name|SourceLocation
name|IvarLBraceLoc
block|;
name|SourceLocation
name|IvarRBraceLoc
block|;
comment|/// Support for ivar initialization.
comment|/// IvarInitializers - The arguments used to initialize the ivars
name|CXXCtorInitializer
operator|*
operator|*
name|IvarInitializers
block|;
name|unsigned
name|NumIvarInitializers
block|;
comment|/// Do the ivars of this class require initialization other than
comment|/// zero-initialization?
name|bool
name|HasNonZeroConstructors
operator|:
literal|1
block|;
comment|/// Do the ivars of this class require non-trivial destruction?
name|bool
name|HasDestructors
operator|:
literal|1
block|;
name|ObjCImplementationDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|ObjCInterfaceDecl *classInterface
argument_list|,
argument|ObjCInterfaceDecl *superDecl
argument_list|,
argument|SourceLocation nameLoc
argument_list|,
argument|SourceLocation atStartLoc
argument_list|,
argument|SourceLocation superLoc = SourceLocation()
argument_list|,
argument|SourceLocation IvarLBraceLoc=SourceLocation()
argument_list|,
argument|SourceLocation IvarRBraceLoc=SourceLocation()
argument_list|)
operator|:
name|ObjCImplDecl
argument_list|(
name|ObjCImplementation
argument_list|,
name|DC
argument_list|,
name|classInterface
argument_list|,
name|nameLoc
argument_list|,
name|atStartLoc
argument_list|)
block|,
name|SuperClass
argument_list|(
name|superDecl
argument_list|)
block|,
name|SuperLoc
argument_list|(
name|superLoc
argument_list|)
block|,
name|IvarLBraceLoc
argument_list|(
name|IvarLBraceLoc
argument_list|)
block|,
name|IvarRBraceLoc
argument_list|(
name|IvarRBraceLoc
argument_list|)
block|,
name|IvarInitializers
argument_list|(
literal|0
argument_list|)
block|,
name|NumIvarInitializers
argument_list|(
literal|0
argument_list|)
block|,
name|HasNonZeroConstructors
argument_list|(
name|false
argument_list|)
block|,
name|HasDestructors
argument_list|(
argument|false
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ObjCImplementationDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|ObjCInterfaceDecl *classInterface
argument_list|,
argument|ObjCInterfaceDecl *superDecl
argument_list|,
argument|SourceLocation nameLoc
argument_list|,
argument|SourceLocation atStartLoc
argument_list|,
argument|SourceLocation superLoc = SourceLocation()
argument_list|,
argument|SourceLocation IvarLBraceLoc=SourceLocation()
argument_list|,
argument|SourceLocation IvarRBraceLoc=SourceLocation()
argument_list|)
block|;
specifier|static
name|ObjCImplementationDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
comment|/// init_iterator - Iterates through the ivar initializer list.
typedef|typedef
name|CXXCtorInitializer
modifier|*
modifier|*
name|init_iterator
typedef|;
end_decl_stmt

begin_comment
comment|/// init_const_iterator - Iterates through the ivar initializer list.
end_comment

begin_typedef
typedef|typedef
name|CXXCtorInitializer
modifier|*
specifier|const
modifier|*
name|init_const_iterator
typedef|;
end_typedef

begin_comment
comment|/// init_begin() - Retrieve an iterator to the first initializer.
end_comment

begin_function
name|init_iterator
name|init_begin
parameter_list|()
block|{
return|return
name|IvarInitializers
return|;
block|}
end_function

begin_comment
comment|/// begin() - Retrieve an iterator to the first initializer.
end_comment

begin_expr_stmt
name|init_const_iterator
name|init_begin
argument_list|()
specifier|const
block|{
return|return
name|IvarInitializers
return|;
block|}
end_expr_stmt

begin_comment
comment|/// init_end() - Retrieve an iterator past the last initializer.
end_comment

begin_function
name|init_iterator
name|init_end
parameter_list|()
block|{
return|return
name|IvarInitializers
operator|+
name|NumIvarInitializers
return|;
block|}
end_function

begin_comment
comment|/// end() - Retrieve an iterator past the last initializer.
end_comment

begin_expr_stmt
name|init_const_iterator
name|init_end
argument_list|()
specifier|const
block|{
return|return
name|IvarInitializers
operator|+
name|NumIvarInitializers
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getNumArgs - Number of ivars which must be initialized.
end_comment

begin_expr_stmt
name|unsigned
name|getNumIvarInitializers
argument_list|()
specifier|const
block|{
return|return
name|NumIvarInitializers
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setNumIvarInitializers
parameter_list|(
name|unsigned
name|numNumIvarInitializers
parameter_list|)
block|{
name|NumIvarInitializers
operator|=
name|numNumIvarInitializers
expr_stmt|;
block|}
end_function

begin_function_decl
name|void
name|setIvarInitializers
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|CXXCtorInitializer
modifier|*
modifier|*
name|initializers
parameter_list|,
name|unsigned
name|numInitializers
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Do any of the ivars of this class (not counting its base classes)
end_comment

begin_comment
comment|/// require construction other than zero-initialization?
end_comment

begin_expr_stmt
name|bool
name|hasNonZeroConstructors
argument_list|()
specifier|const
block|{
return|return
name|HasNonZeroConstructors
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setHasNonZeroConstructors
parameter_list|(
name|bool
name|val
parameter_list|)
block|{
name|HasNonZeroConstructors
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Do any of the ivars of this class (not counting its base classes)
end_comment

begin_comment
comment|/// require non-trivial destruction?
end_comment

begin_expr_stmt
name|bool
name|hasDestructors
argument_list|()
specifier|const
block|{
return|return
name|HasDestructors
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setHasDestructors
parameter_list|(
name|bool
name|val
parameter_list|)
block|{
name|HasDestructors
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getIdentifier - Get the identifier that names the class
end_comment

begin_comment
comment|/// interface associated with this implementation.
end_comment

begin_expr_stmt
name|IdentifierInfo
operator|*
name|getIdentifier
argument_list|()
specifier|const
block|{
return|return
name|getClassInterface
argument_list|()
operator|->
name|getIdentifier
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getName - Get the name of identifier for the class interface associated
end_comment

begin_comment
comment|/// with this implementation as a StringRef.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: This is a bad API, we are overriding the NamedDecl::getName, to mean
end_comment

begin_comment
comment|// something different.
end_comment

begin_expr_stmt
name|StringRef
name|getName
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
end_expr_stmt

begin_comment
comment|/// @brief Get the name of the class associated with this interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FIXME: Move to StringRef API.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getNameAsString
argument_list|()
specifier|const
block|{
return|return
name|getName
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|ObjCInterfaceDecl
operator|*
name|getSuperClass
argument_list|()
specifier|const
block|{
return|return
name|SuperClass
return|;
block|}
end_expr_stmt

begin_function
name|ObjCInterfaceDecl
modifier|*
name|getSuperClass
parameter_list|()
block|{
return|return
name|SuperClass
return|;
block|}
end_function

begin_expr_stmt
name|SourceLocation
name|getSuperClassLoc
argument_list|()
specifier|const
block|{
return|return
name|SuperLoc
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setSuperClass
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|superCls
parameter_list|)
block|{
name|SuperClass
operator|=
name|superCls
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setIvarLBraceLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|IvarLBraceLoc
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SourceLocation
name|getIvarLBraceLoc
argument_list|()
specifier|const
block|{
return|return
name|IvarLBraceLoc
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setIvarRBraceLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|IvarRBraceLoc
operator|=
name|Loc
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SourceLocation
name|getIvarRBraceLoc
argument_list|()
specifier|const
block|{
return|return
name|IvarRBraceLoc
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|specific_decl_iterator
operator|<
name|ObjCIvarDecl
operator|>
name|ivar_iterator
expr_stmt|;
end_typedef

begin_expr_stmt
name|ivar_iterator
name|ivar_begin
argument_list|()
specifier|const
block|{
return|return
name|ivar_iterator
argument_list|(
name|decls_begin
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|ivar_iterator
name|ivar_end
argument_list|()
specifier|const
block|{
return|return
name|ivar_iterator
argument_list|(
name|decls_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|unsigned
name|ivar_size
argument_list|()
specifier|const
block|{
return|return
name|std
operator|::
name|distance
argument_list|(
name|ivar_begin
argument_list|()
argument_list|,
name|ivar_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|ivar_empty
argument_list|()
specifier|const
block|{
return|return
name|ivar_begin
argument_list|()
operator|==
name|ivar_end
argument_list|()
return|;
block|}
end_expr_stmt

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
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|ObjCImplementation
return|;
block|}
end_function

begin_decl_stmt
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
end_decl_stmt

begin_expr_stmt
unit|};
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|ObjCImplementationDecl
operator|&
name|ID
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// ObjCCompatibleAliasDecl - Represents alias of a class. This alias is
end_comment

begin_comment
comment|/// declared as \@compatibility_alias alias class.
end_comment

begin_decl_stmt
name|class
name|ObjCCompatibleAliasDecl
range|:
name|public
name|NamedDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
comment|/// Class that this is an alias of.
name|ObjCInterfaceDecl
operator|*
name|AliasedClass
block|;
name|ObjCCompatibleAliasDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|ObjCInterfaceDecl* aliasedClass
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|ObjCCompatibleAlias
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|AliasedClass
argument_list|(
argument|aliasedClass
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ObjCCompatibleAliasDecl
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
argument|ObjCInterfaceDecl* aliasedClass
argument_list|)
block|;
specifier|static
name|ObjCCompatibleAliasDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
specifier|const
name|ObjCInterfaceDecl
operator|*
name|getClassInterface
argument_list|()
specifier|const
block|{
return|return
name|AliasedClass
return|;
block|}
name|ObjCInterfaceDecl
operator|*
name|getClassInterface
argument_list|()
block|{
return|return
name|AliasedClass
return|;
block|}
name|void
name|setClassInterface
argument_list|(
argument|ObjCInterfaceDecl *D
argument_list|)
block|{
name|AliasedClass
operator|=
name|D
block|; }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|ObjCCompatibleAlias
return|;
block|}
expr|}
block|;
comment|/// \brief Represents one property declaration in an Objective-C interface.
comment|///
comment|/// For example:
comment|/// \code{.mm}
comment|/// \@property (assign, readwrite) int MyProperty;
comment|/// \endcode
name|class
name|ObjCPropertyDecl
operator|:
name|public
name|NamedDecl
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
expr|enum
name|PropertyAttributeKind
block|{
name|OBJC_PR_noattr
operator|=
literal|0x00
block|,
name|OBJC_PR_readonly
operator|=
literal|0x01
block|,
name|OBJC_PR_getter
operator|=
literal|0x02
block|,
name|OBJC_PR_assign
operator|=
literal|0x04
block|,
name|OBJC_PR_readwrite
operator|=
literal|0x08
block|,
name|OBJC_PR_retain
operator|=
literal|0x10
block|,
name|OBJC_PR_copy
operator|=
literal|0x20
block|,
name|OBJC_PR_nonatomic
operator|=
literal|0x40
block|,
name|OBJC_PR_setter
operator|=
literal|0x80
block|,
name|OBJC_PR_atomic
operator|=
literal|0x100
block|,
name|OBJC_PR_weak
operator|=
literal|0x200
block|,
name|OBJC_PR_strong
operator|=
literal|0x400
block|,
name|OBJC_PR_unsafe_unretained
operator|=
literal|0x800
comment|// Adding a property should change NumPropertyAttrsBits
block|}
block|;    enum
block|{
comment|/// \brief Number of bits fitting all the property attributes.
name|NumPropertyAttrsBits
operator|=
literal|12
block|}
block|;    enum
name|SetterKind
block|{
name|Assign
block|,
name|Retain
block|,
name|Copy
block|,
name|Weak
block|}
block|;   enum
name|PropertyControl
block|{
name|None
block|,
name|Required
block|,
name|Optional
block|}
block|;
name|private
operator|:
name|SourceLocation
name|AtLoc
block|;
comment|// location of \@property
name|SourceLocation
name|LParenLoc
block|;
comment|// location of '(' starting attribute list or null.
name|TypeSourceInfo
operator|*
name|DeclType
block|;
name|unsigned
name|PropertyAttributes
operator|:
name|NumPropertyAttrsBits
block|;
name|unsigned
name|PropertyAttributesAsWritten
operator|:
name|NumPropertyAttrsBits
block|;
comment|// \@required/\@optional
name|unsigned
name|PropertyImplementation
operator|:
literal|2
block|;
name|Selector
name|GetterName
block|;
comment|// getter name of NULL if no getter
name|Selector
name|SetterName
block|;
comment|// setter name of NULL if no setter
name|ObjCMethodDecl
operator|*
name|GetterMethodDecl
block|;
comment|// Declaration of getter instance method
name|ObjCMethodDecl
operator|*
name|SetterMethodDecl
block|;
comment|// Declaration of setter instance method
name|ObjCIvarDecl
operator|*
name|PropertyIvarDecl
block|;
comment|// Synthesize ivar for this property
name|ObjCPropertyDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|SourceLocation AtLocation
argument_list|,
argument|SourceLocation LParenLocation
argument_list|,
argument|TypeSourceInfo *T
argument_list|)
operator|:
name|NamedDecl
argument_list|(
name|ObjCProperty
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|AtLoc
argument_list|(
name|AtLocation
argument_list|)
block|,
name|LParenLoc
argument_list|(
name|LParenLocation
argument_list|)
block|,
name|DeclType
argument_list|(
name|T
argument_list|)
block|,
name|PropertyAttributes
argument_list|(
name|OBJC_PR_noattr
argument_list|)
block|,
name|PropertyAttributesAsWritten
argument_list|(
name|OBJC_PR_noattr
argument_list|)
block|,
name|PropertyImplementation
argument_list|(
name|None
argument_list|)
block|,
name|GetterName
argument_list|(
name|Selector
argument_list|()
argument_list|)
block|,
name|SetterName
argument_list|(
name|Selector
argument_list|()
argument_list|)
block|,
name|GetterMethodDecl
argument_list|(
literal|0
argument_list|)
block|,
name|SetterMethodDecl
argument_list|(
literal|0
argument_list|)
block|,
name|PropertyIvarDecl
argument_list|(
literal|0
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|ObjCPropertyDecl
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
argument|SourceLocation AtLocation
argument_list|,
argument|SourceLocation LParenLocation
argument_list|,
argument|TypeSourceInfo *T
argument_list|,
argument|PropertyControl propControl = None
argument_list|)
block|;
specifier|static
name|ObjCPropertyDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|SourceLocation
name|getAtLoc
argument_list|()
specifier|const
block|{
return|return
name|AtLoc
return|;
block|}
name|void
name|setAtLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|AtLoc
operator|=
name|L
block|; }
name|SourceLocation
name|getLParenLoc
argument_list|()
specifier|const
block|{
return|return
name|LParenLoc
return|;
block|}
name|void
name|setLParenLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|LParenLoc
operator|=
name|L
block|; }
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|DeclType
return|;
block|}
name|QualType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|DeclType
operator|->
name|getType
argument_list|()
return|;
block|}
name|void
name|setType
argument_list|(
argument|TypeSourceInfo *T
argument_list|)
block|{
name|DeclType
operator|=
name|T
block|; }
name|PropertyAttributeKind
name|getPropertyAttributes
argument_list|()
specifier|const
block|{
return|return
name|PropertyAttributeKind
argument_list|(
name|PropertyAttributes
argument_list|)
return|;
block|}
name|void
name|setPropertyAttributes
argument_list|(
argument|PropertyAttributeKind PRVal
argument_list|)
block|{
name|PropertyAttributes
operator||=
name|PRVal
block|;   }
name|PropertyAttributeKind
name|getPropertyAttributesAsWritten
argument_list|()
specifier|const
block|{
return|return
name|PropertyAttributeKind
argument_list|(
name|PropertyAttributesAsWritten
argument_list|)
return|;
block|}
name|bool
name|hasWrittenStorageAttribute
argument_list|()
specifier|const
block|{
return|return
name|PropertyAttributesAsWritten
operator|&
operator|(
name|OBJC_PR_assign
operator||
name|OBJC_PR_copy
operator||
name|OBJC_PR_unsafe_unretained
operator||
name|OBJC_PR_retain
operator||
name|OBJC_PR_strong
operator||
name|OBJC_PR_weak
operator|)
return|;
block|}
name|void
name|setPropertyAttributesAsWritten
argument_list|(
argument|PropertyAttributeKind PRVal
argument_list|)
block|{
name|PropertyAttributesAsWritten
operator|=
name|PRVal
block|;   }
name|void
name|makeitReadWriteAttribute
argument_list|()
block|{
name|PropertyAttributes
operator|&=
operator|~
name|OBJC_PR_readonly
block|;
name|PropertyAttributes
operator||=
name|OBJC_PR_readwrite
block|;  }
comment|// Helper methods for accessing attributes.
comment|/// isReadOnly - Return true iff the property has a setter.
name|bool
name|isReadOnly
argument_list|()
specifier|const
block|{
return|return
operator|(
name|PropertyAttributes
operator|&
name|OBJC_PR_readonly
operator|)
return|;
block|}
comment|/// isAtomic - Return true if the property is atomic.
name|bool
name|isAtomic
argument_list|()
specifier|const
block|{
return|return
operator|(
name|PropertyAttributes
operator|&
name|OBJC_PR_atomic
operator|)
return|;
block|}
comment|/// isRetaining - Return true if the property retains its value.
name|bool
name|isRetaining
argument_list|()
specifier|const
block|{
return|return
operator|(
name|PropertyAttributes
operator|&
operator|(
name|OBJC_PR_retain
operator||
name|OBJC_PR_strong
operator||
name|OBJC_PR_copy
operator|)
operator|)
return|;
block|}
comment|/// getSetterKind - Return the method used for doing assignment in
comment|/// the property setter. This is only valid if the property has been
comment|/// defined to have a setter.
name|SetterKind
name|getSetterKind
argument_list|()
specifier|const
block|{
if|if
condition|(
name|PropertyAttributes
operator|&
name|OBJC_PR_strong
condition|)
return|return
name|getType
argument_list|()
operator|->
name|isBlockPointerType
argument_list|()
operator|?
name|Copy
operator|:
name|Retain
return|;
if|if
condition|(
name|PropertyAttributes
operator|&
name|OBJC_PR_retain
condition|)
return|return
name|Retain
return|;
if|if
condition|(
name|PropertyAttributes
operator|&
name|OBJC_PR_copy
condition|)
return|return
name|Copy
return|;
end_decl_stmt

begin_if
if|if
condition|(
name|PropertyAttributes
operator|&
name|OBJC_PR_weak
condition|)
return|return
name|Weak
return|;
end_if

begin_return
return|return
name|Assign
return|;
end_return

begin_macro
unit|}    Selector
name|getGetterName
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|GetterName
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setGetterName
parameter_list|(
name|Selector
name|Sel
parameter_list|)
block|{
name|GetterName
operator|=
name|Sel
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|Selector
name|getSetterName
argument_list|()
specifier|const
block|{
return|return
name|SetterName
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setSetterName
parameter_list|(
name|Selector
name|Sel
parameter_list|)
block|{
name|SetterName
operator|=
name|Sel
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ObjCMethodDecl
operator|*
name|getGetterMethodDecl
argument_list|()
specifier|const
block|{
return|return
name|GetterMethodDecl
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setGetterMethodDecl
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|gDecl
parameter_list|)
block|{
name|GetterMethodDecl
operator|=
name|gDecl
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ObjCMethodDecl
operator|*
name|getSetterMethodDecl
argument_list|()
specifier|const
block|{
return|return
name|SetterMethodDecl
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setSetterMethodDecl
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|gDecl
parameter_list|)
block|{
name|SetterMethodDecl
operator|=
name|gDecl
expr_stmt|;
block|}
end_function

begin_comment
comment|// Related to \@optional/\@required declared in \@protocol
end_comment

begin_function
name|void
name|setPropertyImplementation
parameter_list|(
name|PropertyControl
name|pc
parameter_list|)
block|{
name|PropertyImplementation
operator|=
name|pc
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|PropertyControl
name|getPropertyImplementation
argument_list|()
specifier|const
block|{
return|return
name|PropertyControl
argument_list|(
name|PropertyImplementation
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setPropertyIvarDecl
parameter_list|(
name|ObjCIvarDecl
modifier|*
name|Ivar
parameter_list|)
block|{
name|PropertyIvarDecl
operator|=
name|Ivar
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|ObjCIvarDecl
operator|*
name|getPropertyIvarDecl
argument_list|()
specifier|const
block|{
return|return
name|PropertyIvarDecl
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|SourceRange
argument_list|(
name|AtLoc
argument_list|,
name|getLocation
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Get the default name of the synthesized ivar.
end_comment

begin_decl_stmt
name|IdentifierInfo
modifier|*
name|getDefaultSynthIvarName
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Lookup a property by name in the specified DeclContext.
end_comment

begin_function_decl
specifier|static
name|ObjCPropertyDecl
modifier|*
name|findPropertyDecl
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|IdentifierInfo
modifier|*
name|propertyID
parameter_list|)
function_decl|;
end_function_decl

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
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classofKind
parameter_list|(
name|Kind
name|K
parameter_list|)
block|{
return|return
name|K
operator|==
name|ObjCProperty
return|;
block|}
end_function

begin_comment
unit|};
comment|/// ObjCPropertyImplDecl - Represents implementation declaration of a property
end_comment

begin_comment
comment|/// in a class or category implementation block. For example:
end_comment

begin_comment
comment|/// \@synthesize prop1 = ivar1;
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ObjCPropertyImplDecl
range|:
name|public
name|Decl
block|{
name|public
operator|:
expr|enum
name|Kind
block|{
name|Synthesize
block|,
name|Dynamic
block|}
block|;
name|private
operator|:
name|SourceLocation
name|AtLoc
block|;
comment|// location of \@synthesize or \@dynamic
comment|/// \brief For \@synthesize, the location of the ivar, if it was written in
comment|/// the source code.
comment|///
comment|/// \code
comment|/// \@synthesize int a = b
comment|/// \endcode
name|SourceLocation
name|IvarLoc
block|;
comment|/// Property declaration being implemented
name|ObjCPropertyDecl
operator|*
name|PropertyDecl
block|;
comment|/// Null for \@dynamic. Required for \@synthesize.
name|ObjCIvarDecl
operator|*
name|PropertyIvarDecl
block|;
comment|/// Null for \@dynamic. Non-null if property must be copy-constructed in
comment|/// getter.
name|Expr
operator|*
name|GetterCXXConstructor
block|;
comment|/// Null for \@dynamic. Non-null if property has assignment operator to call
comment|/// in Setter synthesis.
name|Expr
operator|*
name|SetterCXXAssignment
block|;
name|ObjCPropertyImplDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation atLoc
argument_list|,
argument|SourceLocation L
argument_list|,
argument|ObjCPropertyDecl *property
argument_list|,
argument|Kind PK
argument_list|,
argument|ObjCIvarDecl *ivarDecl
argument_list|,
argument|SourceLocation ivarLoc
argument_list|)
operator|:
name|Decl
argument_list|(
name|ObjCPropertyImpl
argument_list|,
name|DC
argument_list|,
name|L
argument_list|)
block|,
name|AtLoc
argument_list|(
name|atLoc
argument_list|)
block|,
name|IvarLoc
argument_list|(
name|ivarLoc
argument_list|)
block|,
name|PropertyDecl
argument_list|(
name|property
argument_list|)
block|,
name|PropertyIvarDecl
argument_list|(
name|ivarDecl
argument_list|)
block|,
name|GetterCXXConstructor
argument_list|(
literal|0
argument_list|)
block|,
name|SetterCXXAssignment
argument_list|(
literal|0
argument_list|)
block|{
name|assert
argument_list|(
name|PK
operator|==
name|Dynamic
operator|||
name|PropertyIvarDecl
argument_list|)
block|;   }
name|public
operator|:
specifier|static
name|ObjCPropertyImplDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation atLoc
argument_list|,
argument|SourceLocation L
argument_list|,
argument|ObjCPropertyDecl *property
argument_list|,
argument|Kind PK
argument_list|,
argument|ObjCIvarDecl *ivarDecl
argument_list|,
argument|SourceLocation ivarLoc
argument_list|)
block|;
specifier|static
name|ObjCPropertyImplDecl
operator|*
name|CreateDeserialized
argument_list|(
argument|ASTContext&C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|;
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
return|return
name|AtLoc
return|;
block|}
name|void
name|setAtLoc
argument_list|(
argument|SourceLocation Loc
argument_list|)
block|{
name|AtLoc
operator|=
name|Loc
block|; }
name|ObjCPropertyDecl
operator|*
name|getPropertyDecl
argument_list|()
specifier|const
block|{
return|return
name|PropertyDecl
return|;
block|}
name|void
name|setPropertyDecl
argument_list|(
argument|ObjCPropertyDecl *Prop
argument_list|)
block|{
name|PropertyDecl
operator|=
name|Prop
block|; }
name|Kind
name|getPropertyImplementation
argument_list|()
specifier|const
block|{
return|return
name|PropertyIvarDecl
operator|?
name|Synthesize
operator|:
name|Dynamic
return|;
block|}
name|ObjCIvarDecl
operator|*
name|getPropertyIvarDecl
argument_list|()
specifier|const
block|{
return|return
name|PropertyIvarDecl
return|;
block|}
name|SourceLocation
name|getPropertyIvarDeclLoc
argument_list|()
specifier|const
block|{
return|return
name|IvarLoc
return|;
block|}
name|void
name|setPropertyIvarDecl
argument_list|(
argument|ObjCIvarDecl *Ivar
argument_list|,
argument|SourceLocation IvarLoc
argument_list|)
block|{
name|PropertyIvarDecl
operator|=
name|Ivar
block|;
name|this
operator|->
name|IvarLoc
operator|=
name|IvarLoc
block|;   }
comment|/// \brief For \@synthesize, returns true if an ivar name was explicitly
comment|/// specified.
comment|///
comment|/// \code
comment|/// \@synthesize int a = b; // true
comment|/// \@synthesize int a; // false
comment|/// \endcode
name|bool
name|isIvarNameSpecified
argument_list|()
specifier|const
block|{
return|return
name|IvarLoc
operator|.
name|isValid
argument_list|()
operator|&&
name|IvarLoc
operator|!=
name|getLocation
argument_list|()
return|;
block|}
name|Expr
operator|*
name|getGetterCXXConstructor
argument_list|()
specifier|const
block|{
return|return
name|GetterCXXConstructor
return|;
block|}
name|void
name|setGetterCXXConstructor
argument_list|(
argument|Expr *getterCXXConstructor
argument_list|)
block|{
name|GetterCXXConstructor
operator|=
name|getterCXXConstructor
block|;   }
name|Expr
operator|*
name|getSetterCXXAssignment
argument_list|()
specifier|const
block|{
return|return
name|SetterCXXAssignment
return|;
block|}
name|void
name|setSetterCXXAssignment
argument_list|(
argument|Expr *setterCXXAssignment
argument_list|)
block|{
name|SetterCXXAssignment
operator|=
name|setterCXXAssignment
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const Decl *D
argument_list|)
block|{
return|return
name|classofKind
argument_list|(
name|D
operator|->
name|getKind
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classofKind
argument_list|(
argument|Decl::Kind K
argument_list|)
block|{
return|return
name|K
operator|==
name|ObjCPropertyImpl
return|;
block|}
name|friend
name|class
name|ASTDeclReader
block|; }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|bool
argument_list|(
operator|*
name|Filter
argument_list|)
argument_list|(
name|ObjCCategoryDecl
operator|*
argument_list|)
operator|>
name|void
name|ObjCInterfaceDecl
operator|::
name|filtered_category_iterator
operator|<
name|Filter
operator|>
operator|::
name|findAcceptableCategory
argument_list|()
block|{
while|while
condition|(
name|Current
operator|&&
operator|!
name|Filter
argument_list|(
name|Current
argument_list|)
condition|)
name|Current
operator|=
name|Current
operator|->
name|getNextClassCategoryRaw
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|bool
argument_list|(
operator|*
name|Filter
argument_list|)
argument_list|(
name|ObjCCategoryDecl
operator|*
argument_list|)
operator|>
specifier|inline
name|ObjCInterfaceDecl
operator|::
name|filtered_category_iterator
operator|<
name|Filter
operator|>
operator|&
name|ObjCInterfaceDecl
operator|::
name|filtered_category_iterator
operator|<
name|Filter
operator|>
operator|::
name|operator
operator|++
operator|(
operator|)
block|{
name|Current
operator|=
name|Current
operator|->
name|getNextClassCategoryRaw
argument_list|()
block|;
name|findAcceptableCategory
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|ObjCInterfaceDecl
operator|::
name|isVisibleCategory
argument_list|(
argument|ObjCCategoryDecl *Cat
argument_list|)
block|{
return|return
operator|!
name|Cat
operator|->
name|isHidden
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|ObjCInterfaceDecl
operator|::
name|isVisibleExtension
argument_list|(
argument|ObjCCategoryDecl *Cat
argument_list|)
block|{
return|return
name|Cat
operator|->
name|IsClassExtension
argument_list|()
operator|&&
operator|!
name|Cat
operator|->
name|isHidden
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|bool
name|ObjCInterfaceDecl
operator|::
name|isKnownExtension
argument_list|(
argument|ObjCCategoryDecl *Cat
argument_list|)
block|{
return|return
name|Cat
operator|->
name|IsClassExtension
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

