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
file|"llvm/ADT/STLExtras.h"
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
name|AttributeList
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
name|ObjCListBase
block|{
name|void
name|operator
init|=
operator|(
specifier|const
name|ObjCListBase
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|ObjCListBase
argument_list|(
specifier|const
name|ObjCListBase
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
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
operator|~
name|ObjCListBase
argument_list|()
block|{
name|assert
argument_list|(
name|List
operator|==
literal|0
operator|&&
literal|"Destroy should have been called before dtor"
argument_list|)
block|;   }
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
expr_stmt|;
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
comment|/// ObjCMethodDecl - Represents an instance or class method declaration.
comment|/// ObjC methods can be declared within 4 contexts: class interfaces,
comment|/// categories, protocols, and class implementations. While C++ member
comment|/// functions leverage C syntax, Objective-C method syntax is modeled after
comment|/// Smalltalk (using colons to specify argument types/expressions).
comment|/// Here are some brief examples:
comment|///
comment|/// Setter/getter instance methods:
comment|/// - (void)setMenu:(NSMenu *)menu;
comment|/// - (NSMenu *)menu;
comment|///
comment|/// Instance method that takes 2 NSView arguments:
comment|/// - (void)replaceSubview:(NSView *)oldView with:(NSView *)newView;
comment|///
comment|/// Getter class method:
comment|/// + (NSMenu *)defaultMenu;
comment|///
comment|/// A selector represents a unique name for a method. The selector names for
comment|/// the above methods are setMenu:, menu, replaceSubview:with:, and defaultMenu.
comment|///
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
comment|/// Bitfields must be first fields in this class so they pack with those
comment|/// declared in class Decl.
comment|/// instance (true) or class (false) method.
name|bool
name|IsInstance
range|:
literal|1
decl_stmt|;
name|bool
name|IsVariadic
range|:
literal|1
decl_stmt|;
comment|// Synthesized declaration method for a property setter/getter
name|bool
name|IsSynthesized
range|:
literal|1
decl_stmt|;
comment|// NOTE: VC++ treats enums as signed, avoid using ImplementationControl enum
comment|/// @required/@optional
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
comment|// Type of this method.
name|QualType
name|MethodDeclType
decl_stmt|;
comment|/// ParamInfo - List of pointers to VarDecls for the formal parameters of this
comment|/// Method.
name|ObjCList
operator|<
name|ParmVarDecl
operator|>
name|ParamInfo
expr_stmt|;
comment|/// List of attributes for this method declaration.
name|SourceLocation
name|EndLoc
decl_stmt|;
comment|// the location of the ';' or '}'.
comment|// The following are only used for method definitions, null otherwise.
comment|// FIXME: space savings opportunity, consider a sub-class.
name|Stmt
modifier|*
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
argument|DeclContext *contextDecl
argument_list|,
argument|bool isInstance = true
argument_list|,
argument|bool isVariadic = false
argument_list|,
argument|bool isSynthesized = false
argument_list|,
argument|ImplementationControl impControl = None
argument_list|)
block|:
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
name|IsSynthesized
argument_list|(
name|isSynthesized
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
name|MethodDeclType
argument_list|(
name|T
argument_list|)
operator|,
name|EndLoc
argument_list|(
name|endLoc
argument_list|)
operator|,
name|Body
argument_list|(
literal|0
argument_list|)
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
block|{}
name|virtual
operator|~
name|ObjCMethodDecl
argument_list|()
block|{}
comment|/// \brief A definition will return its interface declaration.
comment|/// An interface declaration will return its definition.
comment|/// Otherwise it will return itself.
name|virtual
name|ObjCMethodDecl
operator|*
name|getNextRedeclaration
argument_list|()
expr_stmt|;
name|public
label|:
comment|/// Destroy - Call destructors and release memory.
name|virtual
name|void
name|Destroy
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|)
function_decl|;
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
name|isSynthesized
init|=
name|false
parameter_list|,
name|ImplementationControl
name|impControl
init|=
name|None
parameter_list|)
function_decl|;
name|virtual
name|ObjCMethodDecl
modifier|*
name|getCanonicalDecl
parameter_list|()
function_decl|;
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
comment|// Location information, modeled after the Stmt API.
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
block|{
return|return
name|getLocation
argument_list|()
return|;
block|}
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
block|{
return|return
name|EndLoc
return|;
block|}
name|void
name|setEndLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|EndLoc
operator|=
name|Loc
expr_stmt|;
block|}
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
name|EndLoc
argument_list|)
return|;
block|}
name|ObjCInterfaceDecl
modifier|*
name|getClassInterface
parameter_list|()
function_decl|;
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
name|QualType
name|getResultType
argument_list|()
specifier|const
block|{
return|return
name|MethodDeclType
return|;
block|}
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
comment|// Iterator access to formal parameters.
name|unsigned
name|param_size
argument_list|()
specifier|const
block|{
return|return
name|ParamInfo
operator|.
name|size
argument_list|()
return|;
block|}
typedef|typedef
name|ObjCList
operator|<
name|ParmVarDecl
operator|>
operator|::
name|iterator
name|param_iterator
expr_stmt|;
name|param_iterator
name|param_begin
argument_list|()
specifier|const
block|{
return|return
name|ParamInfo
operator|.
name|begin
argument_list|()
return|;
block|}
name|param_iterator
name|param_end
argument_list|()
specifier|const
block|{
return|return
name|ParamInfo
operator|.
name|end
argument_list|()
return|;
block|}
name|void
name|setMethodParams
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|ParmVarDecl
modifier|*
specifier|const
modifier|*
name|List
parameter_list|,
name|unsigned
name|Num
parameter_list|)
block|{
name|ParamInfo
operator|.
name|set
argument_list|(
name|List
argument_list|,
name|Num
argument_list|,
name|C
argument_list|)
expr_stmt|;
block|}
comment|// Iterator access to parameter types.
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
typedef|typedef
name|llvm
operator|::
name|mapped_iterator
operator|<
name|param_iterator
operator|,
name|deref_fun
operator|>
name|arg_type_iterator
expr_stmt|;
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
comment|/// createImplicitParams - Used to lazily create the self and cmd
comment|/// implict parameters. This must be called prior to using getSelfDecl()
comment|/// or getCmdDecl(). The call is ignored if the implicit paramters
comment|/// have already been created.
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
name|bool
name|isInstanceMethod
argument_list|()
specifier|const
block|{
return|return
name|IsInstance
return|;
block|}
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
name|bool
name|isVariadic
argument_list|()
specifier|const
block|{
return|return
name|IsVariadic
return|;
block|}
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
name|bool
name|isSynthesized
argument_list|()
specifier|const
block|{
return|return
name|IsSynthesized
return|;
block|}
name|void
name|setSynthesized
parameter_list|(
name|bool
name|isSynth
parameter_list|)
block|{
name|IsSynthesized
operator|=
name|isSynth
expr_stmt|;
block|}
comment|// Related to protocols declared in  @protocol
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
name|virtual
name|Stmt
operator|*
name|getBody
argument_list|()
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
name|Body
return|;
block|}
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
comment|/// \brief Returns whether this specific method is a definition.
name|bool
name|isThisDeclarationADefinition
argument_list|()
specifier|const
block|{
return|return
name|Body
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
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|ObjCMethod
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|ObjCMethodDecl
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
block|}
empty_stmt|;
comment|/// ObjCMethodList - a linked list of methods with different signatures.
struct|struct
name|ObjCMethodList
block|{
name|ObjCMethodDecl
modifier|*
name|Method
decl_stmt|;
name|ObjCMethodList
modifier|*
name|Next
decl_stmt|;
name|ObjCMethodList
argument_list|()
block|{
name|Method
operator|=
literal|0
expr_stmt|;
name|Next
operator|=
literal|0
expr_stmt|;
block|}
name|ObjCMethodList
argument_list|(
argument|ObjCMethodDecl *M
argument_list|,
argument|ObjCMethodList *C
argument_list|)
block|{
name|Method
operator|=
name|M
expr_stmt|;
name|Next
operator|=
name|C
expr_stmt|;
block|}
block|}
struct|;
comment|/// ObjCContainerDecl - Represents a container for method declarations.
comment|/// Current sub-classes are ObjCInterfaceDecl, ObjCCategoryDecl,
comment|/// ObjCProtocolDecl, and ObjCImplDecl.
comment|///
name|class
name|ObjCContainerDecl
range|:
name|public
name|NamedDecl
decl_stmt|,
name|public
name|DeclContext
block|{
name|SourceLocation
name|AtEndLoc
decl_stmt|;
comment|// marks the end of the method container.
name|public
label|:
name|ObjCContainerDecl
argument_list|(
argument|Kind DK
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
block|:
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
operator|,
name|DeclContext
argument_list|(
argument|DK
argument_list|)
block|{}
name|virtual
operator|~
name|ObjCContainerDecl
argument_list|()
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
argument_list|)
decl|const
decl_stmt|;
name|ObjCMethodDecl
modifier|*
name|getInstanceMethod
argument_list|(
name|Selector
name|Sel
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
argument_list|)
return|;
block|}
name|ObjCMethodDecl
modifier|*
name|getClassMethod
argument_list|(
name|Selector
name|Sel
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
argument_list|)
return|;
block|}
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
comment|// Marks the end of the container.
name|SourceLocation
name|getAtEndLoc
argument_list|()
specifier|const
block|{
return|return
name|AtEndLoc
return|;
block|}
name|void
name|setAtEndLoc
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|AtEndLoc
operator|=
name|L
expr_stmt|;
block|}
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
name|getAtEndLoc
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
name|D
operator|->
name|getKind
argument_list|()
operator|>=
name|ObjCContainerFirst
operator|&&
name|D
operator|->
name|getKind
argument_list|()
operator|<=
name|ObjCContainerLast
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|ObjCContainerDecl
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
empty_stmt|;
comment|/// ObjCInterfaceDecl - Represents an ObjC class declaration. For example:
comment|///
comment|///   // MostPrimitive declares no super class (not particularly useful).
comment|///   @interface MostPrimitive
comment|///     // no instance variables or methods.
comment|///   @end
comment|///
comment|///   // NSResponder inherits from NSObject& implements NSCoding (a protocol).
comment|///   @interface NSResponder : NSObject<NSCoding>
comment|///   { // instance variables are represented by ObjCIvarDecl.
comment|///     id nextResponder; // nextResponder instance variable.
comment|///   }
comment|///   - (NSResponder *)nextResponder; // return a pointer to NSResponder.
comment|///   - (void)mouseMoved:(NSEvent *)theEvent; // return void, takes a pointer
comment|///   @end                                    // to an NSEvent.
comment|///
comment|///   Unlike C/C++, forward class declarations are accomplished with @class.
comment|///   Unlike C/C++, @class allows for a list of classes to be forward declared.
comment|///   Unlike C++, ObjC is a single-rooted class model. In Cocoa, classes
comment|///   typically inherit from NSObject (an exception is NSProxy).
comment|///
name|class
name|ObjCInterfaceDecl
range|:
name|public
name|ObjCContainerDecl
block|{
comment|/// TypeForDecl - This indicates the Type object that represents this
comment|/// TypeDecl.  It is a cache maintained by ASTContext::getObjCInterfaceType
name|mutable
name|Type
operator|*
name|TypeForDecl
block|;
name|friend
name|class
name|ASTContext
block|;
comment|/// Class's super class.
name|ObjCInterfaceDecl
operator|*
name|SuperClass
block|;
comment|/// Protocols referenced in interface header declaration
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
name|ReferencedProtocols
block|;
comment|/// Instance variables in the interface.
name|ObjCList
operator|<
name|ObjCIvarDecl
operator|>
name|IVars
block|;
comment|/// List of categories defined for this class.
comment|/// FIXME: Why is this a linked list??
name|ObjCCategoryDecl
operator|*
name|CategoryList
block|;
name|bool
name|ForwardDecl
operator|:
literal|1
block|;
comment|// declared with @class.
name|bool
name|InternalInterface
operator|:
literal|1
block|;
comment|// true - no @interface for @implementation
name|SourceLocation
name|ClassLoc
block|;
comment|// location of the class identifier.
name|SourceLocation
name|SuperClassLoc
block|;
comment|// location of the super class identifier.
name|SourceLocation
name|EndLoc
block|;
comment|// marks the '>', '}', or identifier.
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
argument|bool FD
argument_list|,
argument|bool isInternal
argument_list|)
block|;
name|virtual
operator|~
name|ObjCInterfaceDecl
argument_list|()
block|{}
name|public
operator|:
comment|/// Destroy - Call destructors and release memory.
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
specifier|static
name|ObjCInterfaceDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation atLoc
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|SourceLocation ClassLoc = SourceLocation()
argument_list|,
argument|bool ForwardDecl = false
argument_list|,
argument|bool isInternal = false
argument_list|)
block|;
specifier|const
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
operator|&
name|getReferencedProtocols
argument_list|()
specifier|const
block|{
return|return
name|ReferencedProtocols
return|;
block|}
name|ObjCImplementationDecl
operator|*
name|getImplementation
argument_list|()
specifier|const
block|;
name|void
name|setImplementation
argument_list|(
name|ObjCImplementationDecl
operator|*
name|ImplD
argument_list|)
block|;
name|ObjCCategoryDecl
operator|*
name|FindCategoryDeclaration
argument_list|(
argument|IdentifierInfo *CategoryId
argument_list|)
specifier|const
block|;
comment|// Get the local instance/class method declared in a category.
name|ObjCMethodDecl
operator|*
name|getCategoryInstanceMethod
argument_list|(
argument|Selector Sel
argument_list|)
specifier|const
block|;
name|ObjCMethodDecl
operator|*
name|getCategoryClassMethod
argument_list|(
argument|Selector Sel
argument_list|)
specifier|const
block|;
name|ObjCMethodDecl
operator|*
name|getCategoryMethod
argument_list|(
argument|Selector Sel
argument_list|,
argument|bool isInstance
argument_list|)
specifier|const
block|{
return|return
name|isInstance
operator|?
name|getInstanceMethod
argument_list|(
name|Sel
argument_list|)
operator|:
name|getClassMethod
argument_list|(
name|Sel
argument_list|)
return|;
block|}
typedef|typedef
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
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
typedef|typedef
name|ObjCList
operator|<
name|ObjCIvarDecl
operator|>
operator|::
name|iterator
name|ivar_iterator
expr_stmt|;
name|ivar_iterator
name|ivar_begin
argument_list|()
specifier|const
block|{
return|return
name|IVars
operator|.
name|begin
argument_list|()
return|;
block|}
name|ivar_iterator
name|ivar_end
argument_list|()
specifier|const
block|{
return|return
name|IVars
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|ivar_size
argument_list|()
specifier|const
block|{
return|return
name|IVars
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|ivar_empty
argument_list|()
specifier|const
block|{
return|return
name|IVars
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// setProtocolList - Set the list of protocols that this interface
comment|/// implements.
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
name|ASTContext
modifier|&
name|C
parameter_list|)
block|{
name|ReferencedProtocols
operator|.
name|set
argument_list|(
name|List
argument_list|,
name|Num
argument_list|,
name|C
argument_list|)
expr_stmt|;
block|}
comment|/// mergeClassExtensionProtocolList - Merge class extension's protocol list
comment|/// into the protocol list for this class.
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
name|void
name|setIVarList
parameter_list|(
name|ObjCIvarDecl
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
block|{
name|IVars
operator|.
name|set
argument_list|(
name|List
argument_list|,
name|Num
argument_list|,
name|C
argument_list|)
expr_stmt|;
block|}
name|bool
name|isForwardDecl
argument_list|()
specifier|const
block|{
return|return
name|ForwardDecl
return|;
block|}
name|void
name|setForwardDecl
parameter_list|(
name|bool
name|val
parameter_list|)
block|{
name|ForwardDecl
operator|=
name|val
expr_stmt|;
block|}
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
name|ObjCCategoryDecl
operator|*
name|getCategoryList
argument_list|()
specifier|const
block|{
return|return
name|CategoryList
return|;
block|}
name|void
name|setCategoryList
parameter_list|(
name|ObjCCategoryDecl
modifier|*
name|category
parameter_list|)
block|{
name|CategoryList
operator|=
name|category
expr_stmt|;
block|}
comment|/// isSuperClassOf - Return true if this class is the specified class or is a
comment|/// super class of the specified interface class.
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
name|this
operator|==
name|I
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
comment|// Lookup a method. First, we search locally. If a method isn't
comment|// found, we search referenced protocols and class categories.
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
comment|// Lookup a method in the classes implementation hierarchy.
name|ObjCMethodDecl
modifier|*
name|lookupPrivateInstanceMethod
parameter_list|(
specifier|const
name|Selector
modifier|&
name|Sel
parameter_list|)
function_decl|;
comment|// Location information, modeled after the Stmt API.
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
block|{
return|return
name|getLocation
argument_list|()
return|;
block|}
comment|// '@'interface
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
block|{
return|return
name|EndLoc
return|;
block|}
name|void
name|setLocEnd
parameter_list|(
name|SourceLocation
name|LE
parameter_list|)
block|{
name|EndLoc
operator|=
name|LE
expr_stmt|;
block|}
empty_stmt|;
name|void
name|setClassLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|ClassLoc
operator|=
name|Loc
expr_stmt|;
block|}
name|SourceLocation
name|getClassLoc
argument_list|()
specifier|const
block|{
return|return
name|ClassLoc
return|;
block|}
name|void
name|setSuperClassLoc
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|)
block|{
name|SuperClassLoc
operator|=
name|Loc
expr_stmt|;
block|}
name|SourceLocation
name|getSuperClassLoc
argument_list|()
specifier|const
block|{
return|return
name|SuperClassLoc
return|;
block|}
comment|/// isImplicitInterfaceDecl - check that this is an implicitly declared
comment|/// ObjCInterfaceDecl node. This is for legacy objective-c @implementation
comment|/// declaration without an @interface declaration.
name|bool
name|isImplicitInterfaceDecl
argument_list|()
specifier|const
block|{
return|return
name|InternalInterface
return|;
block|}
name|void
name|setImplicitInterfaceDecl
parameter_list|(
name|bool
name|val
parameter_list|)
block|{
name|InternalInterface
operator|=
name|val
expr_stmt|;
block|}
comment|/// ClassImplementsProtocol - Checks that 'lProto' protocol
comment|/// has been implemented in IDecl class, its super class or categories (if
comment|/// lookupCategory is true).
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
name|ObjCInterface
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|ObjCInterfaceDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
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
comment|///   @interface IvarExample : NSObject
end_comment

begin_comment
comment|///   {
end_comment

begin_comment
comment|///     id defaultToProtected;
end_comment

begin_comment
comment|///   @public:
end_comment

begin_comment
comment|///     id canBePublic; // same as C++.
end_comment

begin_comment
comment|///   @protected:
end_comment

begin_comment
comment|///     id canBeProtected; // same as C++.
end_comment

begin_comment
comment|///   @package:
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
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|DeclaratorInfo *DInfo
argument_list|,
argument|AccessControl ac
argument_list|,
argument|Expr *BW
argument_list|)
operator|:
name|FieldDecl
argument_list|(
name|ObjCIvar
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|,
name|T
argument_list|,
name|DInfo
argument_list|,
name|BW
argument_list|,
comment|/*Mutable=*/
name|false
argument_list|)
block|,
name|DeclAccess
argument_list|(
argument|ac
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
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|DeclaratorInfo *DInfo
argument_list|,
argument|AccessControl ac
argument_list|,
argument|Expr *BW = NULL
argument_list|)
block|;
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
name|ObjCIvar
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCIvarDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|private
operator|:
comment|// NOTE: VC++ treats enums as signed, avoid using the AccessControl enum
name|unsigned
name|DeclAccess
operator|:
literal|3
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ObjCAtDefsFieldDecl - Represents a field declaration created by an
end_comment

begin_comment
comment|///  @defs(...).
end_comment

begin_decl_stmt
name|class
name|ObjCAtDefsFieldDecl
range|:
name|public
name|FieldDecl
block|{
name|private
operator|:
name|ObjCAtDefsFieldDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
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
argument|L
argument_list|,
argument|Id
argument_list|,
argument|T
argument_list|,
comment|/*DInfo=*/
literal|0
argument_list|,
comment|// FIXME: Do ObjCAtDefs have declarators ?
argument|BW
argument_list|,
comment|/*Mutable=*/
argument|false
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
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|QualType T
argument_list|,
argument|Expr *BW
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
name|ObjCAtDefsField
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCAtDefsFieldDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// ObjCProtocolDecl - Represents a protocol declaration. ObjC protocols
comment|/// declare a pure abstract type (i.e no instance variables are permitted).
comment|/// Protocols orginally drew inspiration from C++ pure virtual functions (a C++
comment|/// feature with nice semantics and lousy syntax:-). Here is an example:
comment|///
comment|/// @protocol NSDraggingInfo<refproto1, refproto2>
comment|/// - (NSWindow *)draggingDestinationWindow;
comment|/// - (NSImage *)draggedImage;
comment|/// @end
comment|///
comment|/// This says that NSDraggingInfo requires two methods and requires everything
comment|/// that the two "referenced protocols" 'refproto1' and 'refproto2' require as
comment|/// well.
comment|///
comment|/// @interface ImplementsNSDraggingInfo : NSObject<NSDraggingInfo>
comment|/// @end
comment|///
comment|/// ObjC protocols inspired Java interfaces. Unlike Java, ObjC classes and
comment|/// protocols are in distinct namespaces. For example, Cocoa defines both
comment|/// an NSObject protocol and class (which isn't allowed in Java). As a result,
comment|/// protocols are referenced using angle brackets as follows:
comment|///
comment|/// id<NSDraggingInfo> anyObjectThatImplementsNSDraggingInfo;
comment|///
name|class
name|ObjCProtocolDecl
operator|:
name|public
name|ObjCContainerDecl
block|{
comment|/// Referenced protocols
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
name|ReferencedProtocols
block|;
name|bool
name|isForwardProtoDecl
block|;
comment|// declared with @protocol.
name|SourceLocation
name|EndLoc
block|;
comment|// marks the '>' or identifier.
name|ObjCProtocolDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
operator|:
name|ObjCContainerDecl
argument_list|(
name|ObjCProtocol
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|isForwardProtoDecl
argument_list|(
argument|true
argument_list|)
block|{   }
name|virtual
operator|~
name|ObjCProtocolDecl
argument_list|()
block|{}
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
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
block|;
comment|/// Destroy - Call destructors and release memory.
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
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
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
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
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
comment|/// setProtocolList - Set the list of protocols that this interface
comment|/// implements.
name|void
name|setProtocolList
argument_list|(
argument|ObjCProtocolDecl *const*List
argument_list|,
argument|unsigned Num
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
name|C
argument_list|)
block|;   }
name|ObjCProtocolDecl
operator|*
name|lookupProtocolNamed
argument_list|(
name|IdentifierInfo
operator|*
name|PName
argument_list|)
block|;
comment|// Lookup a method. First, we search locally. If a method isn't
comment|// found, we search referenced protocols and class categories.
name|ObjCMethodDecl
operator|*
name|lookupMethod
argument_list|(
argument|Selector Sel
argument_list|,
argument|bool isInstance
argument_list|)
specifier|const
block|;
name|ObjCMethodDecl
operator|*
name|lookupInstanceMethod
argument_list|(
argument|Selector Sel
argument_list|)
specifier|const
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
name|ObjCMethodDecl
operator|*
name|lookupClassMethod
argument_list|(
argument|Selector Sel
argument_list|)
specifier|const
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
name|bool
name|isForwardDecl
argument_list|()
specifier|const
block|{
return|return
name|isForwardProtoDecl
return|;
block|}
name|void
name|setForwardDecl
argument_list|(
argument|bool val
argument_list|)
block|{
name|isForwardProtoDecl
operator|=
name|val
block|; }
comment|// Location information, modeled after the Stmt API.
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
block|{
return|return
name|getLocation
argument_list|()
return|;
block|}
comment|// '@'protocol
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
block|{
return|return
name|EndLoc
return|;
block|}
name|void
name|setLocEnd
argument_list|(
argument|SourceLocation LE
argument_list|)
block|{
name|EndLoc
operator|=
name|LE
block|; }
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
operator|==
name|ObjCProtocol
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCProtocolDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// ObjCClassDecl - Specifies a list of forward class declarations. For example:
comment|///
comment|/// @class NSCursor, NSImage, NSPasteboard, NSWindow;
comment|///
name|class
name|ObjCClassDecl
operator|:
name|public
name|Decl
block|{
name|public
operator|:
name|class
name|ObjCClassRef
block|{
name|ObjCInterfaceDecl
operator|*
name|ID
block|;
name|SourceLocation
name|L
block|;
name|public
operator|:
name|ObjCClassRef
argument_list|(
argument|ObjCInterfaceDecl *d
argument_list|,
argument|SourceLocation l
argument_list|)
operator|:
name|ID
argument_list|(
name|d
argument_list|)
block|,
name|L
argument_list|(
argument|l
argument_list|)
block|{}
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|L
return|;
block|}
name|ObjCInterfaceDecl
operator|*
name|getInterface
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
expr|}
block|;
name|private
operator|:
name|ObjCClassRef
operator|*
name|ForwardDecls
block|;
name|unsigned
name|NumDecls
block|;
name|ObjCClassDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|ObjCInterfaceDecl *const *Elts
argument_list|,
argument|const SourceLocation *Locs
argument_list|,
argument|unsigned nElts
argument_list|,
argument|ASTContext&C
argument_list|)
block|;
name|virtual
operator|~
name|ObjCClassDecl
argument_list|()
block|{}
name|public
operator|:
comment|/// Destroy - Call destructors and release memory.
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
specifier|static
name|ObjCClassDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|ObjCInterfaceDecl *const *Elts =
literal|0
argument_list|,
argument|const SourceLocation *Locs =
literal|0
argument_list|,
argument|unsigned nElts =
literal|0
argument_list|)
block|;
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|;
typedef|typedef
specifier|const
name|ObjCClassRef
modifier|*
name|iterator
typedef|;
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|ForwardDecls
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|ForwardDecls
operator|+
name|NumDecls
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|NumDecls
return|;
block|}
comment|/// setClassList - Set the list of forward classes.
name|void
name|setClassList
argument_list|(
argument|ASTContext&C
argument_list|,
argument|ObjCInterfaceDecl*const*List
argument_list|,
argument|const SourceLocation *Locs
argument_list|,
argument|unsigned Num
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
operator|==
name|ObjCClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCClassDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// ObjCForwardProtocolDecl - Specifies a list of forward protocol declarations.
comment|/// For example:
comment|///
comment|/// @protocol NSTextInput, NSChangeSpelling, NSDraggingInfo;
comment|///
name|class
name|ObjCForwardProtocolDecl
operator|:
name|public
name|Decl
block|{
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
name|ReferencedProtocols
block|;
name|ObjCForwardProtocolDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|ObjCProtocolDecl *const *Elts
argument_list|,
argument|unsigned nElts
argument_list|,
argument|ASTContext&C
argument_list|)
block|;
name|virtual
operator|~
name|ObjCForwardProtocolDecl
argument_list|()
block|{}
name|public
operator|:
specifier|static
name|ObjCForwardProtocolDecl
operator|*
name|Create
argument_list|(
argument|ASTContext&C
argument_list|,
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|ObjCProtocolDecl *const *Elts =
literal|0
argument_list|,
argument|unsigned Num =
literal|0
argument_list|)
block|;
comment|/// Destroy - Call destructors and release memory.
name|virtual
name|void
name|Destroy
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
block|;
typedef|typedef
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
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
comment|/// setProtocolList - Set the list of forward protocols.
name|void
name|setProtocolList
argument_list|(
argument|ObjCProtocolDecl *const*List
argument_list|,
argument|unsigned Num
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
name|C
argument_list|)
block|;   }
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
name|ObjCForwardProtocol
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCForwardProtocolDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// ObjCCategoryDecl - Represents a category declaration. A category allows
comment|/// you to add methods to an existing class (without subclassing or modifying
comment|/// the original class interface or implementation:-). Categories don't allow
comment|/// you to add instance data. The following example adds "myMethod" to all
comment|/// NSView's within a process:
comment|///
comment|/// @interface NSView (MyViewMethods)
comment|/// - myMethod;
comment|/// @end
comment|///
comment|/// Cateogries also allow you to split the implementation of a class across
comment|/// several files (a feature more naturally supported in C++).
comment|///
comment|/// Categories were originally inspired by dynamic languages such as Common
comment|/// Lisp and Smalltalk.  More traditional class-based languages (C++, Java)
comment|/// don't support this level of dynamism, which is both powerful and dangerous.
comment|///
name|class
name|ObjCCategoryDecl
operator|:
name|public
name|ObjCContainerDecl
block|{
comment|/// Interface belonging to this category
name|ObjCInterfaceDecl
operator|*
name|ClassInterface
block|;
comment|/// referenced protocols in this category.
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
name|ReferencedProtocols
block|;
comment|/// Next category belonging to this class.
comment|/// FIXME: this should not be a singly-linked list.  Move storage elsewhere.
name|ObjCCategoryDecl
operator|*
name|NextClassCategory
block|;
name|SourceLocation
name|EndLoc
block|;
comment|// marks the '>' or identifier.
name|ObjCCategoryDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|)
operator|:
name|ObjCContainerDecl
argument_list|(
name|ObjCCategory
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|Id
argument_list|)
block|,
name|ClassInterface
argument_list|(
literal|0
argument_list|)
block|,
name|NextClassCategory
argument_list|(
literal|0
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
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
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
name|void
name|setClassInterface
argument_list|(
argument|ObjCInterfaceDecl *IDecl
argument_list|)
block|{
name|ClassInterface
operator|=
name|IDecl
block|; }
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
name|C
argument_list|)
block|;   }
specifier|const
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
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
name|ObjCList
operator|<
name|ObjCProtocolDecl
operator|>
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
name|void
name|setNextClassCategory
argument_list|(
argument|ObjCCategoryDecl *Cat
argument_list|)
block|{
name|NextClassCategory
operator|=
name|Cat
block|;   }
name|void
name|insertNextClassCategory
argument_list|()
block|{
name|NextClassCategory
operator|=
name|ClassInterface
operator|->
name|getCategoryList
argument_list|()
block|;
name|ClassInterface
operator|->
name|setCategoryList
argument_list|(
name|this
argument_list|)
block|;   }
comment|// Location information, modeled after the Stmt API.
name|SourceLocation
name|getLocStart
argument_list|()
specifier|const
block|{
return|return
name|getLocation
argument_list|()
return|;
block|}
comment|// '@'interface
name|SourceLocation
name|getLocEnd
argument_list|()
specifier|const
block|{
return|return
name|EndLoc
return|;
block|}
name|void
name|setLocEnd
argument_list|(
argument|SourceLocation LE
argument_list|)
block|{
name|EndLoc
operator|=
name|LE
block|; }
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
operator|==
name|ObjCCategory
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCCategoryDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
name|class
name|ObjCImplDecl
operator|:
name|public
name|ObjCContainerDecl
block|{
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
argument|SourceLocation L
argument_list|,
argument|ObjCInterfaceDecl *classInterface
argument_list|)
operator|:
name|ObjCContainerDecl
argument_list|(
name|DK
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|classInterface
condition|?
name|classInterface
operator|->
name|getIdentifier
argument_list|()
else|:
literal|0
argument_list|)
block|,
name|ClassInterface
argument_list|(
argument|classInterface
argument_list|)
block|{}
name|public
operator|:
name|virtual
operator|~
name|ObjCImplDecl
argument_list|()
block|{}
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
name|D
operator|->
name|getKind
argument_list|()
operator|>=
name|ObjCImplFirst
operator|&&
name|D
operator|->
name|getKind
argument_list|()
operator|<=
name|ObjCImplLast
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCImplDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// ObjCCategoryImplDecl - An object of this class encapsulates a category
comment|/// @implementation declaration. If a category class has declaration of a
comment|/// property, its implementation must be specified in the category's
comment|/// @implementation declaration. Example:
comment|/// @interface I @end
comment|/// @interface I(CATEGORY)
comment|///    @property int p1, d1;
comment|/// @end
comment|/// @implementation I(CATEGORY)
comment|///  @dynamic p1,d1;
comment|/// @end
comment|///
comment|/// ObjCCategoryImplDecl
name|class
name|ObjCCategoryImplDecl
operator|:
name|public
name|ObjCImplDecl
block|{
comment|// Category name
name|IdentifierInfo
operator|*
name|Id
block|;
name|ObjCCategoryImplDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|ObjCInterfaceDecl *classInterface
argument_list|)
operator|:
name|ObjCImplDecl
argument_list|(
name|ObjCCategoryImpl
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|classInterface
argument_list|)
block|,
name|Id
argument_list|(
argument|Id
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
argument|SourceLocation L
argument_list|,
argument|IdentifierInfo *Id
argument_list|,
argument|ObjCInterfaceDecl *classInterface
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
comment|/// getName - Get the name of identifier for the class interface associated
comment|/// with this implementation as a StringRef.
comment|//
comment|// FIXME: This is a bad API, we are overriding the NamedDecl::getName, to mean
comment|// something different.
name|llvm
operator|::
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
comment|/// getNameAsCString - Get the name of identifier for the class
comment|/// interface associated with this implementation as a C string
comment|/// (const char*).
comment|//
comment|// FIXME: Deprecated, move clients to getName().
specifier|const
name|char
operator|*
name|getNameAsCString
argument_list|()
specifier|const
block|{
return|return
name|Id
condition|?
name|Id
operator|->
name|getNameStart
argument_list|()
else|:
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
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|ObjCCategoryImpl
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCCategoryImplDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// ObjCImplementationDecl - Represents a class definition - this is where
comment|/// method definitions are specified. For example:
comment|///
comment|/// @code
comment|/// @implementation MyClass
comment|/// - (void)myMethod { /* do something */ }
comment|/// @end
comment|/// @endcode
comment|///
comment|/// Typically, instance variables are specified in the class interface,
comment|/// *not* in the implementation. Nevertheless (for legacy reasons), we
comment|/// allow instance variables to be specified in the implementation.  When
comment|/// specified, they need to be *identical* to the interface.
comment|///
name|class
name|ObjCImplementationDecl
operator|:
name|public
name|ObjCImplDecl
block|{
comment|/// Implementation Class's super class.
name|ObjCInterfaceDecl
operator|*
name|SuperClass
block|;
name|ObjCImplementationDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|ObjCInterfaceDecl *classInterface
argument_list|,
argument|ObjCInterfaceDecl *superDecl
argument_list|)
operator|:
name|ObjCImplDecl
argument_list|(
name|ObjCImplementation
argument_list|,
name|DC
argument_list|,
name|L
argument_list|,
name|classInterface
argument_list|)
block|,
name|SuperClass
argument_list|(
argument|superDecl
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
argument|SourceLocation L
argument_list|,
argument|ObjCInterfaceDecl *classInterface
argument_list|,
argument|ObjCInterfaceDecl *superDecl
argument_list|)
block|;
comment|/// getIdentifier - Get the identifier that names the class
comment|/// interface associated with this implementation.
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
comment|/// getName - Get the name of identifier for the class interface associated
comment|/// with this implementation as a StringRef.
comment|//
comment|// FIXME: This is a bad API, we are overriding the NamedDecl::getName, to mean
comment|// something different.
name|llvm
operator|::
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
comment|/// getNameAsCString - Get the name of identifier for the class
comment|/// interface associated with this implementation as a C string
comment|/// (const char*).
comment|//
comment|// FIXME: Move to StringRef API.
specifier|const
name|char
operator|*
name|getNameAsCString
argument_list|()
specifier|const
block|{
return|return
name|getName
argument_list|()
operator|.
name|data
argument_list|()
return|;
block|}
comment|/// @brief Get the name of the class associated with this interface.
comment|//
comment|// FIXME: Move to StringRef API.
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
name|ObjCInterfaceDecl
operator|*
name|getSuperClass
argument_list|()
block|{
return|return
name|SuperClass
return|;
block|}
name|void
name|setSuperClass
argument_list|(
argument|ObjCInterfaceDecl * superCls
argument_list|)
block|{
name|SuperClass
operator|=
name|superCls
block|; }
typedef|typedef
name|specific_decl_iterator
operator|<
name|ObjCIvarDecl
operator|>
name|ivar_iterator
expr_stmt|;
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
name|ObjCImplementation
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCImplementationDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// ObjCCompatibleAliasDecl - Represents alias of a class. This alias is
comment|/// declared as @compatibility_alias alias class.
name|class
name|ObjCCompatibleAliasDecl
operator|:
name|public
name|NamedDecl
block|{
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
name|D
operator|->
name|getKind
argument_list|()
operator|==
name|ObjCCompatibleAlias
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCCompatibleAliasDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// ObjCPropertyDecl - Represents one property declaration in an interface.
comment|/// For example:
comment|/// @property (assign, readwrite) int MyProperty;
comment|///
name|class
name|ObjCPropertyDecl
operator|:
name|public
name|NamedDecl
block|{
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
block|}
block|;    enum
name|SetterKind
block|{
name|Assign
block|,
name|Retain
block|,
name|Copy
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
name|QualType
name|DeclType
block|;
name|unsigned
name|PropertyAttributes
operator|:
literal|8
block|;
comment|// @required/@optional
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
argument|QualType T
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
argument|QualType T
argument_list|,
argument|PropertyControl propControl = None
argument_list|)
block|;
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
argument|QualType T
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
name|void
name|makeitReadWriteAttribute
argument_list|(
argument|void
argument_list|)
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
return|return
name|Assign
return|;
block|}
name|Selector
name|getGetterName
argument_list|()
specifier|const
block|{
return|return
name|GetterName
return|;
block|}
name|void
name|setGetterName
argument_list|(
argument|Selector Sel
argument_list|)
block|{
name|GetterName
operator|=
name|Sel
block|; }
name|Selector
name|getSetterName
argument_list|()
specifier|const
block|{
return|return
name|SetterName
return|;
block|}
name|void
name|setSetterName
argument_list|(
argument|Selector Sel
argument_list|)
block|{
name|SetterName
operator|=
name|Sel
block|; }
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
name|void
name|setGetterMethodDecl
argument_list|(
argument|ObjCMethodDecl *gDecl
argument_list|)
block|{
name|GetterMethodDecl
operator|=
name|gDecl
block|; }
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
name|void
name|setSetterMethodDecl
argument_list|(
argument|ObjCMethodDecl *gDecl
argument_list|)
block|{
name|SetterMethodDecl
operator|=
name|gDecl
block|; }
comment|// Related to @optional/@required declared in @protocol
name|void
name|setPropertyImplementation
argument_list|(
argument|PropertyControl pc
argument_list|)
block|{
name|PropertyImplementation
operator|=
name|pc
block|;   }
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
name|void
name|setPropertyIvarDecl
argument_list|(
argument|ObjCIvarDecl *Ivar
argument_list|)
block|{
name|PropertyIvarDecl
operator|=
name|Ivar
block|;   }
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
name|ObjCProperty
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCPropertyDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// ObjCPropertyImplDecl - Represents implementation declaration of a property
comment|/// in a class or category implementation block. For example:
comment|/// @synthesize prop1 = ivar1;
comment|///
name|class
name|ObjCPropertyImplDecl
operator|:
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
comment|// location of @synthesize or @dynamic
comment|/// Property declaration being implemented
name|ObjCPropertyDecl
operator|*
name|PropertyDecl
block|;
comment|/// Null for @dynamic. Required for @synthesize.
name|ObjCIvarDecl
operator|*
name|PropertyIvarDecl
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
name|PropertyDecl
argument_list|(
name|property
argument_list|)
block|,
name|PropertyIvarDecl
argument_list|(
argument|ivarDecl
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
name|AtLoc
argument_list|,
name|getLocation
argument_list|()
argument_list|)
return|;
block|}
name|SourceLocation
name|getLocStart
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
name|void
name|setPropertyIvarDecl
argument_list|(
argument|ObjCIvarDecl *Ivar
argument_list|)
block|{
name|PropertyIvarDecl
operator|=
name|Ivar
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
name|ObjCPropertyImpl
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCPropertyImplDecl *D
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

