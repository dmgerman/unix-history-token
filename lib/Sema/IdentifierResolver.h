begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IdentifierResolver.h - Lexical Scope Name lookup ---------*- C++ -*-===//
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
comment|// This file defines the IdentifierResolver class, which is used for lexical
end_comment

begin_comment
comment|// scoped lookup, based on declaration names.
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
name|LLVM_CLANG_AST_SEMA_IDENTIFIERRESOLVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_SEMA_IDENTIFIERRESOLVER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/Parse/Scope.h"
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
file|"clang/AST/DeclCXX.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// IdentifierResolver - Keeps track of shadowed decls on enclosing
comment|/// scopes.  It manages the shadowing chains of declaration names and
comment|/// implements efficent decl lookup based on a declaration name.
name|class
name|IdentifierResolver
block|{
comment|/// IdDeclInfo - Keeps track of information about decls associated
comment|/// to a particular declaration name. IdDeclInfos are lazily
comment|/// constructed and assigned to a declaration name the first time a
comment|/// decl with that declaration name is shadowed in some scope.
name|class
name|IdDeclInfo
block|{
name|public
label|:
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|NamedDecl
operator|*
operator|,
literal|2
operator|>
name|DeclsTy
expr_stmt|;
specifier|inline
name|DeclsTy
operator|::
name|iterator
name|decls_begin
argument_list|()
block|{
return|return
name|Decls
operator|.
name|begin
argument_list|()
return|;
block|}
specifier|inline
name|DeclsTy
operator|::
name|iterator
name|decls_end
argument_list|()
block|{
return|return
name|Decls
operator|.
name|end
argument_list|()
return|;
block|}
name|void
name|AddDecl
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
block|{
name|Decls
operator|.
name|push_back
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
comment|/// RemoveDecl - Remove the decl from the scope chain.
comment|/// The decl must already be part of the decl chain.
name|void
name|RemoveDecl
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// Replaces the Old declaration with the New declaration. If the
comment|/// replacement is successful, returns true. If the old
comment|/// declaration was not found, returns false.
name|bool
name|ReplaceDecl
parameter_list|(
name|NamedDecl
modifier|*
name|Old
parameter_list|,
name|NamedDecl
modifier|*
name|New
parameter_list|)
function_decl|;
name|private
label|:
name|DeclsTy
name|Decls
decl_stmt|;
block|}
empty_stmt|;
name|public
label|:
comment|/// iterator - Iterate over the decls of a specified declaration name.
comment|/// It will walk or not the parent declaration contexts depending on how
comment|/// it was instantiated.
name|class
name|iterator
block|{
name|public
label|:
typedef|typedef
name|NamedDecl
modifier|*
name|value_type
typedef|;
typedef|typedef
name|NamedDecl
modifier|*
name|reference
typedef|;
typedef|typedef
name|NamedDecl
modifier|*
name|pointer
typedef|;
typedef|typedef
name|std
operator|::
name|input_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|std
operator|::
name|ptrdiff_t
name|difference_type
expr_stmt|;
comment|/// Ptr - There are 3 forms that 'Ptr' represents:
comment|/// 1) A single NamedDecl. (Ptr& 0x1 == 0)
comment|/// 2) A IdDeclInfo::DeclsTy::iterator that traverses only the decls of the
comment|///    same declaration context. (Ptr& 0x3 == 0x1)
comment|/// 3) A IdDeclInfo::DeclsTy::iterator that traverses the decls of parent
comment|///    declaration contexts too. (Ptr& 0x3 == 0x3)
name|uintptr_t
name|Ptr
decl_stmt|;
typedef|typedef
name|IdDeclInfo
operator|::
name|DeclsTy
operator|::
name|iterator
name|BaseIter
expr_stmt|;
comment|/// A single NamedDecl. (Ptr& 0x1 == 0)
name|iterator
argument_list|(
argument|NamedDecl *D
argument_list|)
block|{
name|Ptr
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|D
operator|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|Ptr
operator|&
literal|0x1
operator|)
operator|==
literal|0
operator|&&
literal|"Invalid Ptr!"
argument_list|)
expr_stmt|;
block|}
comment|/// A IdDeclInfo::DeclsTy::iterator that walks or not the parent declaration
comment|/// contexts depending on 'LookInParentCtx'.
name|iterator
argument_list|(
argument|BaseIter I
argument_list|)
block|{
name|Ptr
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|I
operator|)
operator||
literal|0x1
expr_stmt|;
block|}
name|bool
name|isIterator
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Ptr
operator|&
literal|0x1
operator|)
return|;
block|}
name|BaseIter
name|getIterator
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isIterator
argument_list|()
operator|&&
literal|"Ptr not an iterator!"
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
name|BaseIter
operator|>
operator|(
name|Ptr
operator|&
operator|~
literal|0x3
operator|)
return|;
block|}
name|friend
name|class
name|IdentifierResolver
decl_stmt|;
name|public
label|:
name|iterator
argument_list|()
operator|:
name|Ptr
argument_list|(
literal|0
argument_list|)
block|{}
name|NamedDecl
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
if|if
condition|(
name|isIterator
argument_list|()
condition|)
return|return
operator|*
name|getIterator
argument_list|()
return|;
else|else
return|return
name|reinterpret_cast
operator|<
name|NamedDecl
operator|*
operator|>
operator|(
name|Ptr
operator|)
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Ptr
operator|==
name|RHS
operator|.
name|Ptr
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|Ptr
operator|!=
name|RHS
operator|.
name|Ptr
return|;
block|}
comment|// Preincrement.
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
if|if
condition|(
operator|!
name|isIterator
argument_list|()
condition|)
comment|// common case.
name|Ptr
operator|=
literal|0
expr_stmt|;
else|else
block|{
name|NamedDecl
modifier|*
name|D
init|=
operator|*
operator|*
name|this
decl_stmt|;
name|void
modifier|*
name|InfoPtr
init|=
name|D
operator|->
name|getDeclName
argument_list|()
operator|.
name|getFETokenInfo
operator|<
name|void
operator|>
operator|(
operator|)
decl_stmt|;
name|assert
argument_list|(
operator|!
name|isDeclPtr
argument_list|(
name|InfoPtr
argument_list|)
operator|&&
literal|"Decl with wrong id ?"
argument_list|)
expr_stmt|;
name|IdDeclInfo
modifier|*
name|Info
init|=
name|toIdDeclInfo
argument_list|(
name|InfoPtr
argument_list|)
decl_stmt|;
name|BaseIter
name|I
init|=
name|getIterator
argument_list|()
decl_stmt|;
if|if
condition|(
name|I
operator|!=
name|Info
operator|->
name|decls_begin
argument_list|()
condition|)
operator|*
name|this
operator|=
name|iterator
argument_list|(
name|I
operator|-
literal|1
argument_list|)
expr_stmt|;
else|else
comment|// No more decls.
operator|*
name|this
operator|=
name|iterator
argument_list|()
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
name|uintptr_t
name|getAsOpaqueValue
argument_list|()
specifier|const
block|{
return|return
name|Ptr
return|;
block|}
specifier|static
name|iterator
name|getFromOpaqueValue
parameter_list|(
name|uintptr_t
name|P
parameter_list|)
block|{
name|iterator
name|Result
decl_stmt|;
name|Result
operator|.
name|Ptr
operator|=
name|P
expr_stmt|;
return|return
name|Result
return|;
block|}
block|}
empty_stmt|;
comment|/// begin - Returns an iterator for decls with the name 'Name'.
specifier|static
name|iterator
name|begin
parameter_list|(
name|DeclarationName
name|Name
parameter_list|)
function_decl|;
comment|/// end - Returns an iterator that has 'finished'.
specifier|static
name|iterator
name|end
parameter_list|()
block|{
return|return
name|iterator
argument_list|()
return|;
block|}
comment|/// isDeclInScope - If 'Ctx' is a function/method, isDeclInScope returns true
comment|/// if 'D' is in Scope 'S', otherwise 'S' is ignored and isDeclInScope returns
comment|/// true if 'D' belongs to the given declaration context.
name|bool
name|isDeclInScope
argument_list|(
name|Decl
operator|*
name|D
argument_list|,
name|DeclContext
operator|*
name|Ctx
argument_list|,
name|ASTContext
operator|&
name|Context
argument_list|,
name|Scope
operator|*
name|S
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
comment|/// AddDecl - Link the decl to its shadowed decl chain.
name|void
name|AddDecl
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// RemoveDecl - Unlink the decl from its shadowed decl chain.
comment|/// The decl must already be part of the decl chain.
name|void
name|RemoveDecl
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// Replace the decl Old with the new declaration New on its
comment|/// identifier chain. Returns true if the old declaration was found
comment|/// (and, therefore, replaced).
name|bool
name|ReplaceDecl
parameter_list|(
name|NamedDecl
modifier|*
name|Old
parameter_list|,
name|NamedDecl
modifier|*
name|New
parameter_list|)
function_decl|;
comment|/// \brief Link the declaration into the chain of declarations for
comment|/// the given identifier.
comment|///
comment|/// This is a lower-level routine used by the PCH reader to link a
comment|/// declaration into a specific IdentifierInfo before the
comment|/// declaration actually has a name.
name|void
name|AddDeclToIdentifierChain
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|NamedDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|explicit
name|IdentifierResolver
parameter_list|(
specifier|const
name|LangOptions
modifier|&
name|LangOpt
parameter_list|)
function_decl|;
operator|~
name|IdentifierResolver
argument_list|()
expr_stmt|;
name|private
label|:
specifier|const
name|LangOptions
modifier|&
name|LangOpt
decl_stmt|;
name|class
name|IdDeclInfoMap
decl_stmt|;
name|IdDeclInfoMap
modifier|*
name|IdDeclInfos
decl_stmt|;
comment|/// FETokenInfo contains a Decl pointer if lower bit == 0.
specifier|static
specifier|inline
name|bool
name|isDeclPtr
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
block|{
return|return
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Ptr
operator|)
operator|&
literal|0x1
operator|)
operator|==
literal|0
return|;
block|}
comment|/// FETokenInfo contains a IdDeclInfo pointer if lower bit == 1.
specifier|static
specifier|inline
name|IdDeclInfo
modifier|*
name|toIdDeclInfo
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Ptr
operator|)
operator|&
literal|0x1
operator|)
operator|==
literal|1
operator|&&
literal|"Ptr not a IdDeclInfo* !"
argument_list|)
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
name|IdDeclInfo
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Ptr
operator|)
operator|&
operator|~
literal|0x1
operator|)
return|;
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

