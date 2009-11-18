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
name|LLVM_CLANG_PARSE_SCOPE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_PARSE_SCOPE_H
end_define

begin_include
include|#
directive|include
file|"clang/Parse/Action.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
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
comment|/// FnScope - This indicates that the scope corresponds to a function, which
comment|/// means that labels are set here.
name|FnScope
init|=
literal|0x01
block|,
comment|/// BreakScope - This is a while,do,switch,for, etc that can have break
comment|/// stmts embedded into it.
name|BreakScope
init|=
literal|0x02
block|,
comment|/// ContinueScope - This is a while,do,for, which can have continue
comment|/// stmt embedded into it.
name|ContinueScope
init|=
literal|0x04
block|,
comment|/// DeclScope - This is a scope that can contain a declaration.  Some scopes
comment|/// just contain loop constructs but don't contain decls.
name|DeclScope
init|=
literal|0x08
block|,
comment|/// ControlScope - The controlling scope in a if/switch/while/for statement.
name|ControlScope
init|=
literal|0x10
block|,
comment|/// ClassScope - The scope of a struct/union/class definition.
name|ClassScope
init|=
literal|0x20
block|,
comment|/// BlockScope - This is a scope that corresponds to a block object.
comment|/// Blocks serve as top-level scopes for some objects like labels, they
comment|/// also prevent things like break and continue.  BlockScopes have the
comment|/// other flags set as well.
name|BlockScope
init|=
literal|0x40
block|,
comment|/// TemplateParamScope - This is a scope that corresponds to the
comment|/// template parameters of a C++ template. Template parameter
comment|/// scope starts at the 'template' keyword and ends when the
comment|/// template declaration ends.
name|TemplateParamScope
init|=
literal|0x80
block|,
comment|/// FunctionPrototypeScope - This is a scope that corresponds to the
comment|/// parameters within a function prototype.
name|FunctionPrototypeScope
init|=
literal|0x100
block|,
comment|/// AtCatchScope - This is a scope that corresponds to the Objective-C
comment|/// @catch statement.
name|AtCatchScope
init|=
literal|0x200
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
name|Depth
range|:
literal|16
decl_stmt|;
comment|/// Flags - This contains a set of ScopeFlags, which indicates how the scope
comment|/// interrelates with other control flow statements.
name|unsigned
name|Flags
range|:
literal|10
decl_stmt|;
comment|/// WithinElse - Whether this scope is part of the "else" branch in
comment|/// its parent ControlScope.
name|bool
name|WithinElse
range|:
literal|1
decl_stmt|;
comment|/// FnParent - If this scope has a parent scope that is a function body, this
comment|/// pointer is non-null and points to it.  This is used for label processing.
name|Scope
modifier|*
name|FnParent
decl_stmt|;
comment|/// BreakParent/ContinueParent - This is a direct link to the immediately
comment|/// preceeding BreakParent/ContinueParent if this scope is not one, or null if
comment|/// there is no containing break/continue scope.
name|Scope
modifier|*
name|BreakParent
decl_stmt|,
modifier|*
name|ContinueParent
decl_stmt|;
comment|/// ControlParent - This is a direct link to the immediately
comment|/// preceeding ControlParent if this scope is not one, or null if
comment|/// there is no containing control scope.
name|Scope
modifier|*
name|ControlParent
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
name|Action
operator|::
name|DeclPtrTy
operator|,
literal|32
operator|>
name|DeclSetTy
expr_stmt|;
name|DeclSetTy
name|DeclsInScope
decl_stmt|;
comment|/// Entity - The entity with which this scope is associated. For
comment|/// example, the entity of a class scope is the class itself, the
comment|/// entity of a function scope is a function, etc. This field is
comment|/// maintained by the Action implementation.
name|void
modifier|*
name|Entity
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|Action
operator|::
name|DeclPtrTy
operator|,
literal|2
operator|>
name|UsingDirectivesTy
expr_stmt|;
name|UsingDirectivesTy
name|UsingDirectives
decl_stmt|;
name|public
label|:
name|Scope
argument_list|(
argument|Scope *Parent
argument_list|,
argument|unsigned ScopeFlags
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
comment|/// isBlockScope - Return true if this scope does not correspond to a
comment|/// closure.
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
comment|/// would be affected by.  If the closest scope is a closure scope, we know
comment|/// that there is no loop *inside* the closure.
name|Scope
modifier|*
name|getContinueParent
parameter_list|()
block|{
if|if
condition|(
name|ContinueParent
operator|&&
operator|!
name|ContinueParent
operator|->
name|isBlockScope
argument_list|()
condition|)
return|return
name|ContinueParent
return|;
return|return
literal|0
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
comment|/// would be affected by.  If the closest scope is a block scope, we know
comment|/// that there is no loop *inside* the block.
name|Scope
modifier|*
name|getBreakParent
parameter_list|()
block|{
if|if
condition|(
name|BreakParent
operator|&&
operator|!
name|BreakParent
operator|->
name|isBlockScope
argument_list|()
condition|)
return|return
name|BreakParent
return|;
return|return
literal|0
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
name|getControlParent
parameter_list|()
block|{
return|return
name|ControlParent
return|;
block|}
specifier|const
name|Scope
operator|*
name|getControlParent
argument_list|()
specifier|const
block|{
return|return
name|ControlParent
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
argument_list|(
name|Action
operator|::
name|DeclPtrTy
name|D
argument_list|)
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
argument_list|(
name|Action
operator|::
name|DeclPtrTy
name|D
argument_list|)
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
argument_list|(
name|Action
operator|::
name|DeclPtrTy
name|D
argument_list|)
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
name|void
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
name|void
modifier|*
name|E
parameter_list|)
block|{
name|Entity
operator|=
name|E
expr_stmt|;
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
comment|/// isAtCatchScope - Return true if this scope is @catch.
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
comment|/// isWithinElse - Whether we are within the "else" of the
comment|/// ControlParent (if any).
name|bool
name|isWithinElse
argument_list|()
specifier|const
block|{
return|return
name|WithinElse
return|;
block|}
name|void
name|setWithinElse
parameter_list|(
name|bool
name|WE
parameter_list|)
block|{
name|WithinElse
operator|=
name|WE
expr_stmt|;
block|}
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
argument_list|(
name|Action
operator|::
name|DeclPtrTy
name|UDir
argument_list|)
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
name|Parent
parameter_list|,
name|unsigned
name|ScopeFlags
parameter_list|)
block|{
name|AnyParent
operator|=
name|Parent
expr_stmt|;
name|Depth
operator|=
name|AnyParent
condition|?
name|AnyParent
operator|->
name|Depth
operator|+
literal|1
else|:
literal|0
expr_stmt|;
name|Flags
operator|=
name|ScopeFlags
expr_stmt|;
name|WithinElse
operator|=
name|false
expr_stmt|;
if|if
condition|(
name|AnyParent
condition|)
block|{
name|FnParent
operator|=
name|AnyParent
operator|->
name|FnParent
expr_stmt|;
name|BreakParent
operator|=
name|AnyParent
operator|->
name|BreakParent
expr_stmt|;
name|ContinueParent
operator|=
name|AnyParent
operator|->
name|ContinueParent
expr_stmt|;
name|ControlParent
operator|=
name|AnyParent
operator|->
name|ControlParent
expr_stmt|;
name|BlockParent
operator|=
name|AnyParent
operator|->
name|BlockParent
expr_stmt|;
name|TemplateParamParent
operator|=
name|AnyParent
operator|->
name|TemplateParamParent
expr_stmt|;
block|}
else|else
block|{
name|FnParent
operator|=
name|BreakParent
operator|=
name|ContinueParent
operator|=
name|BlockParent
operator|=
literal|0
expr_stmt|;
name|ControlParent
operator|=
literal|0
expr_stmt|;
name|TemplateParamParent
operator|=
literal|0
expr_stmt|;
block|}
comment|// If this scope is a function or contains breaks/continues, remember it.
if|if
condition|(
name|Flags
operator|&
name|FnScope
condition|)
name|FnParent
operator|=
name|this
expr_stmt|;
if|if
condition|(
name|Flags
operator|&
name|BreakScope
condition|)
name|BreakParent
operator|=
name|this
expr_stmt|;
if|if
condition|(
name|Flags
operator|&
name|ContinueScope
condition|)
name|ContinueParent
operator|=
name|this
expr_stmt|;
if|if
condition|(
name|Flags
operator|&
name|ControlScope
condition|)
name|ControlParent
operator|=
name|this
expr_stmt|;
if|if
condition|(
name|Flags
operator|&
name|BlockScope
condition|)
name|BlockParent
operator|=
name|this
expr_stmt|;
if|if
condition|(
name|Flags
operator|&
name|TemplateParamScope
condition|)
name|TemplateParamParent
operator|=
name|this
expr_stmt|;
name|DeclsInScope
operator|.
name|clear
argument_list|()
expr_stmt|;
name|UsingDirectives
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Entity
operator|=
literal|0
expr_stmt|;
block|}
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

