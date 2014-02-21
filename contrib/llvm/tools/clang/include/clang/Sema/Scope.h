begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Scope.h - Scope interface ------------------------------*- C++ -*-===//
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
comment|//  This file defines the Scope interface.
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
name|LLVM_CLANG_SEMA_SCOPE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_SCOPE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
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
name|UsingDirectiveDecl
decl_stmt|;
comment|/// Scope - A scope is a transient data structure that is used while parsing the
comment|/// program.  It assists with resolving identifiers to the appropriate
comment|/// declaration.
comment|///
name|class
name|Scope
block|{
name|public
label|:
comment|/// ScopeFlags - These are bitfields that are or'd together when creating a
comment|/// scope, which defines the sorts of things the scope contains.
enum|enum
name|ScopeFlags
block|{
comment|/// \brief This indicates that the scope corresponds to a function, which
comment|/// means that labels are set here.
name|FnScope
init|=
literal|0x01
block|,
comment|/// \brief This is a while, do, switch, for, etc that can have break
comment|/// statements embedded into it.
name|BreakScope
init|=
literal|0x02
block|,
comment|/// \brief This is a while, do, for, which can have continue statements
comment|/// embedded into it.
name|ContinueScope
init|=
literal|0x04
block|,
comment|/// \brief This is a scope that can contain a declaration.  Some scopes
comment|/// just contain loop constructs but don't contain decls.
name|DeclScope
init|=
literal|0x08
block|,
comment|/// \brief The controlling scope in a if/switch/while/for statement.
name|ControlScope
init|=
literal|0x10
block|,
comment|/// \brief The scope of a struct/union/class definition.
name|ClassScope
init|=
literal|0x20
block|,
comment|/// \brief This is a scope that corresponds to a block/closure object.
comment|/// Blocks serve as top-level scopes for some objects like labels, they
comment|/// also prevent things like break and continue.  BlockScopes always have
comment|/// the FnScope and DeclScope flags set as well.
name|BlockScope
init|=
literal|0x40
block|,
comment|/// \brief This is a scope that corresponds to the
comment|/// template parameters of a C++ template. Template parameter
comment|/// scope starts at the 'template' keyword and ends when the
comment|/// template declaration ends.
name|TemplateParamScope
init|=
literal|0x80
block|,
comment|/// \brief This is a scope that corresponds to the
comment|/// parameters within a function prototype.
name|FunctionPrototypeScope
init|=
literal|0x100
block|,
comment|/// \brief This is a scope that corresponds to the parameters within
comment|/// a function prototype for a function declaration (as opposed to any
comment|/// other kind of function declarator). Always has FunctionPrototypeScope
comment|/// set as well.
name|FunctionDeclarationScope
init|=
literal|0x200
block|,
comment|/// \brief This is a scope that corresponds to the Objective-C
comment|/// \@catch statement.
name|AtCatchScope
init|=
literal|0x400
block|,
comment|/// \brief This scope corresponds to an Objective-C method body.
comment|/// It always has FnScope and DeclScope set as well.
name|ObjCMethodScope
init|=
literal|0x800
block|,
comment|/// \brief This is a scope that corresponds to a switch statement.
name|SwitchScope
init|=
literal|0x1000
block|,
comment|/// \brief This is the scope of a C++ try statement.
name|TryScope
init|=
literal|0x2000
block|,
comment|/// \brief This is the scope for a function-level C++ try or catch scope.
name|FnTryCatchScope
init|=
literal|0x4000
block|,
comment|/// \brief This is the scope of OpenMP executable directive
name|OpenMPDirectiveScope
init|=
literal|0x8000
block|}
enum|;
name|private
label|:
comment|/// The parent scope for this scope.  This is null for the translation-unit
comment|/// scope.
name|Scope
modifier|*
name|AnyParent
decl_stmt|;
comment|/// Depth - This is the depth of this scope.  The translation-unit scope has
comment|/// depth 0.
name|unsigned
name|short
name|Depth
decl_stmt|;
comment|/// Flags - This contains a set of ScopeFlags, which indicates how the scope
comment|/// interrelates with other control flow statements.
name|unsigned
name|short
name|Flags
decl_stmt|;
comment|/// PrototypeDepth - This is the number of function prototype scopes
comment|/// enclosing this scope, including this scope.
name|unsigned
name|short
name|PrototypeDepth
decl_stmt|;
comment|/// PrototypeIndex - This is the number of parameters currently
comment|/// declared in this scope.
name|unsigned
name|short
name|PrototypeIndex
decl_stmt|;
comment|/// FnParent - If this scope has a parent scope that is a function body, this
comment|/// pointer is non-null and points to it.  This is used for label processing.
name|Scope
modifier|*
name|FnParent
decl_stmt|;
comment|/// BreakParent/ContinueParent - This is a direct link to the innermost
comment|/// BreakScope/ContinueScope which contains the contents of this scope
comment|/// for control flow purposes (and might be this scope itself), or null
comment|/// if there is no such scope.
name|Scope
modifier|*
name|BreakParent
decl_stmt|,
modifier|*
name|ContinueParent
decl_stmt|;
comment|/// BlockParent - This is a direct link to the immediately containing
comment|/// BlockScope if this scope is not one, or null if there is none.
name|Scope
modifier|*
name|BlockParent
decl_stmt|;
comment|/// TemplateParamParent - This is a direct link to the
comment|/// immediately containing template parameter scope. In the
comment|/// case of nested templates, template parameter scopes can have
comment|/// other template parameter scopes as parents.
name|Scope
modifier|*
name|TemplateParamParent
decl_stmt|;
comment|/// DeclsInScope - This keeps track of all declarations in this scope.  When
comment|/// the declaration is added to the scope, it is set as the current
comment|/// declaration for the identifier in the IdentifierTable.  When the scope is
comment|/// popped, these declarations are removed from the IdentifierTable's notion
comment|/// of current declaration.  It is up to the current Action implementation to
comment|/// implement these semantics.
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|Decl
operator|*
operator|,
literal|32
operator|>
name|DeclSetTy
expr_stmt|;
name|DeclSetTy
name|DeclsInScope
decl_stmt|;
comment|/// The DeclContext with which this scope is associated. For
comment|/// example, the entity of a class scope is the class itself, the
comment|/// entity of a function scope is a function, etc.
name|DeclContext
modifier|*
name|Entity
decl_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|UsingDirectiveDecl
operator|*
operator|,
literal|2
operator|>
name|UsingDirectivesTy
expr_stmt|;
name|UsingDirectivesTy
name|UsingDirectives
decl_stmt|;
comment|/// \brief Used to determine if errors occurred in this scope.
name|DiagnosticErrorTrap
name|ErrorTrap
decl_stmt|;
name|public
label|:
name|Scope
argument_list|(
argument|Scope *Parent
argument_list|,
argument|unsigned ScopeFlags
argument_list|,
argument|DiagnosticsEngine&Diag
argument_list|)
block|:
name|ErrorTrap
argument_list|(
argument|Diag
argument_list|)
block|{
name|Init
argument_list|(
name|Parent
argument_list|,
name|ScopeFlags
argument_list|)
expr_stmt|;
block|}
comment|/// getFlags - Return the flags for this scope.
comment|///
name|unsigned
name|getFlags
argument_list|()
specifier|const
block|{
return|return
name|Flags
return|;
block|}
name|void
name|setFlags
parameter_list|(
name|unsigned
name|F
parameter_list|)
block|{
name|Flags
operator|=
name|F
expr_stmt|;
block|}
comment|/// isBlockScope - Return true if this scope correspond to a closure.
name|bool
name|isBlockScope
argument_list|()
specifier|const
block|{
return|return
name|Flags
operator|&
name|BlockScope
return|;
block|}
comment|/// getParent - Return the scope that this is nested in.
comment|///
specifier|const
name|Scope
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|AnyParent
return|;
block|}
name|Scope
modifier|*
name|getParent
parameter_list|()
block|{
return|return
name|AnyParent
return|;
block|}
comment|/// getFnParent - Return the closest scope that is a function body.
comment|///
specifier|const
name|Scope
operator|*
name|getFnParent
argument_list|()
specifier|const
block|{
return|return
name|FnParent
return|;
block|}
name|Scope
modifier|*
name|getFnParent
parameter_list|()
block|{
return|return
name|FnParent
return|;
block|}
comment|/// getContinueParent - Return the closest scope that a continue statement
comment|/// would be affected by.
name|Scope
modifier|*
name|getContinueParent
parameter_list|()
block|{
return|return
name|ContinueParent
return|;
block|}
specifier|const
name|Scope
operator|*
name|getContinueParent
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Scope
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getContinueParent
argument_list|()
return|;
block|}
comment|/// getBreakParent - Return the closest scope that a break statement
comment|/// would be affected by.
name|Scope
modifier|*
name|getBreakParent
parameter_list|()
block|{
return|return
name|BreakParent
return|;
block|}
specifier|const
name|Scope
operator|*
name|getBreakParent
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|Scope
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getBreakParent
argument_list|()
return|;
block|}
name|Scope
modifier|*
name|getBlockParent
parameter_list|()
block|{
return|return
name|BlockParent
return|;
block|}
specifier|const
name|Scope
operator|*
name|getBlockParent
argument_list|()
specifier|const
block|{
return|return
name|BlockParent
return|;
block|}
name|Scope
modifier|*
name|getTemplateParamParent
parameter_list|()
block|{
return|return
name|TemplateParamParent
return|;
block|}
specifier|const
name|Scope
operator|*
name|getTemplateParamParent
argument_list|()
specifier|const
block|{
return|return
name|TemplateParamParent
return|;
block|}
comment|/// Returns the number of function prototype scopes in this scope
comment|/// chain.
name|unsigned
name|getFunctionPrototypeDepth
argument_list|()
specifier|const
block|{
return|return
name|PrototypeDepth
return|;
block|}
comment|/// Return the number of parameters declared in this function
comment|/// prototype, increasing it by one for the next call.
name|unsigned
name|getNextFunctionPrototypeIndex
parameter_list|()
block|{
name|assert
argument_list|(
name|isFunctionPrototypeScope
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|PrototypeIndex
operator|++
return|;
block|}
typedef|typedef
name|DeclSetTy
operator|::
name|iterator
name|decl_iterator
expr_stmt|;
name|decl_iterator
name|decl_begin
argument_list|()
specifier|const
block|{
return|return
name|DeclsInScope
operator|.
name|begin
argument_list|()
return|;
block|}
name|decl_iterator
name|decl_end
argument_list|()
specifier|const
block|{
return|return
name|DeclsInScope
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|decl_empty
argument_list|()
specifier|const
block|{
return|return
name|DeclsInScope
operator|.
name|empty
argument_list|()
return|;
block|}
name|void
name|AddDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
block|{
name|DeclsInScope
operator|.
name|insert
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
name|void
name|RemoveDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
block|{
name|DeclsInScope
operator|.
name|erase
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
comment|/// isDeclScope - Return true if this is the scope that the specified decl is
comment|/// declared in.
name|bool
name|isDeclScope
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|DeclsInScope
operator|.
name|count
argument_list|(
name|D
argument_list|)
operator|!=
literal|0
return|;
block|}
name|DeclContext
operator|*
name|getEntity
argument_list|()
specifier|const
block|{
return|return
name|Entity
return|;
block|}
name|void
name|setEntity
parameter_list|(
name|DeclContext
modifier|*
name|E
parameter_list|)
block|{
name|Entity
operator|=
name|E
expr_stmt|;
block|}
name|bool
name|hasErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|ErrorTrap
operator|.
name|hasErrorOccurred
argument_list|()
return|;
block|}
name|bool
name|hasUnrecoverableErrorOccurred
argument_list|()
specifier|const
block|{
return|return
name|ErrorTrap
operator|.
name|hasUnrecoverableErrorOccurred
argument_list|()
return|;
block|}
comment|/// isClassScope - Return true if this scope is a class/struct/union scope.
name|bool
name|isClassScope
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getFlags
argument_list|()
operator|&
name|Scope
operator|::
name|ClassScope
operator|)
return|;
block|}
comment|/// isInCXXInlineMethodScope - Return true if this scope is a C++ inline
comment|/// method scope or is inside one.
name|bool
name|isInCXXInlineMethodScope
argument_list|()
specifier|const
block|{
if|if
condition|(
specifier|const
name|Scope
modifier|*
name|FnS
init|=
name|getFnParent
argument_list|()
condition|)
block|{
name|assert
argument_list|(
name|FnS
operator|->
name|getParent
argument_list|()
operator|&&
literal|"TUScope not created?"
argument_list|)
expr_stmt|;
return|return
name|FnS
operator|->
name|getParent
argument_list|()
operator|->
name|isClassScope
argument_list|()
return|;
block|}
return|return
name|false
return|;
block|}
comment|/// isInObjcMethodScope - Return true if this scope is, or is contained in, an
comment|/// Objective-C method body.  Note that this method is not constant time.
name|bool
name|isInObjcMethodScope
argument_list|()
specifier|const
block|{
for|for
control|(
specifier|const
name|Scope
modifier|*
name|S
init|=
name|this
init|;
name|S
condition|;
name|S
operator|=
name|S
operator|->
name|getParent
argument_list|()
control|)
block|{
comment|// If this scope is an objc method scope, then we succeed.
if|if
condition|(
name|S
operator|->
name|getFlags
argument_list|()
operator|&
name|ObjCMethodScope
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|/// isTemplateParamScope - Return true if this scope is a C++
comment|/// template parameter scope.
name|bool
name|isTemplateParamScope
argument_list|()
specifier|const
block|{
return|return
name|getFlags
argument_list|()
operator|&
name|Scope
operator|::
name|TemplateParamScope
return|;
block|}
comment|/// isFunctionPrototypeScope - Return true if this scope is a
comment|/// function prototype scope.
name|bool
name|isFunctionPrototypeScope
argument_list|()
specifier|const
block|{
return|return
name|getFlags
argument_list|()
operator|&
name|Scope
operator|::
name|FunctionPrototypeScope
return|;
block|}
comment|/// isAtCatchScope - Return true if this scope is \@catch.
name|bool
name|isAtCatchScope
argument_list|()
specifier|const
block|{
return|return
name|getFlags
argument_list|()
operator|&
name|Scope
operator|::
name|AtCatchScope
return|;
block|}
comment|/// isSwitchScope - Return true if this scope is a switch scope.
name|bool
name|isSwitchScope
argument_list|()
specifier|const
block|{
for|for
control|(
specifier|const
name|Scope
modifier|*
name|S
init|=
name|this
init|;
name|S
condition|;
name|S
operator|=
name|S
operator|->
name|getParent
argument_list|()
control|)
block|{
if|if
condition|(
name|S
operator|->
name|getFlags
argument_list|()
operator|&
name|Scope
operator|::
name|SwitchScope
condition|)
return|return
name|true
return|;
elseif|else
if|if
condition|(
name|S
operator|->
name|getFlags
argument_list|()
operator|&
operator|(
name|Scope
operator|::
name|FnScope
operator||
name|Scope
operator|::
name|ClassScope
operator||
name|Scope
operator|::
name|BlockScope
operator||
name|Scope
operator|::
name|TemplateParamScope
operator||
name|Scope
operator|::
name|FunctionPrototypeScope
operator||
name|Scope
operator|::
name|AtCatchScope
operator||
name|Scope
operator|::
name|ObjCMethodScope
operator|)
condition|)
return|return
name|false
return|;
block|}
return|return
name|false
return|;
block|}
comment|/// \brief Determines whether this scope is the OpenMP directive scope
name|bool
name|isOpenMPDirectiveScope
argument_list|()
specifier|const
block|{
return|return
operator|(
name|getFlags
argument_list|()
operator|&
name|Scope
operator|::
name|OpenMPDirectiveScope
operator|)
return|;
block|}
comment|/// \brief Determine whether this scope is a C++ 'try' block.
name|bool
name|isTryScope
argument_list|()
specifier|const
block|{
return|return
name|getFlags
argument_list|()
operator|&
name|Scope
operator|::
name|TryScope
return|;
block|}
comment|/// containedInPrototypeScope - Return true if this or a parent scope
comment|/// is a FunctionPrototypeScope.
name|bool
name|containedInPrototypeScope
argument_list|()
specifier|const
expr_stmt|;
typedef|typedef
name|UsingDirectivesTy
operator|::
name|iterator
name|udir_iterator
expr_stmt|;
typedef|typedef
name|UsingDirectivesTy
operator|::
name|const_iterator
name|const_udir_iterator
expr_stmt|;
name|void
name|PushUsingDirective
parameter_list|(
name|UsingDirectiveDecl
modifier|*
name|UDir
parameter_list|)
block|{
name|UsingDirectives
operator|.
name|push_back
argument_list|(
name|UDir
argument_list|)
expr_stmt|;
block|}
name|udir_iterator
name|using_directives_begin
parameter_list|()
block|{
return|return
name|UsingDirectives
operator|.
name|begin
argument_list|()
return|;
block|}
name|udir_iterator
name|using_directives_end
parameter_list|()
block|{
return|return
name|UsingDirectives
operator|.
name|end
argument_list|()
return|;
block|}
name|const_udir_iterator
name|using_directives_begin
argument_list|()
specifier|const
block|{
return|return
name|UsingDirectives
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_udir_iterator
name|using_directives_end
argument_list|()
specifier|const
block|{
return|return
name|UsingDirectives
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Init - This is used by the parser to implement scope caching.
comment|///
name|void
name|Init
parameter_list|(
name|Scope
modifier|*
name|parent
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

