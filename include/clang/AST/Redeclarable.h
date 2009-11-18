begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Redeclarable.h - Base for Decls that can be redeclared -*- C++ -*-====//
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
comment|//  This file defines the Redeclarable interface.
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
name|LLVM_CLANG_AST_REDECLARABLE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_REDECLARABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Provides common interface for the Decls that can be redeclared.
name|template
operator|<
name|typename
name|decl_type
operator|>
name|class
name|Redeclarable
block|{
name|protected
operator|:
comment|// FIXME: PointerIntPair is a value class that should not be inherited from.
comment|// This should change to using containment.
expr|struct
name|DeclLink
operator|:
name|public
name|llvm
operator|::
name|PointerIntPair
operator|<
name|decl_type
operator|*
block|,
literal|1
block|,
name|bool
operator|>
block|{
name|DeclLink
argument_list|(
argument|decl_type *D
argument_list|,
argument|bool isLatest
argument_list|)
operator|:
name|llvm
operator|::
name|PointerIntPair
operator|<
name|decl_type
operator|*
block|,
literal|1
block|,
name|bool
operator|>
operator|(
name|D
operator|,
name|isLatest
operator|)
block|{ }
typedef|typedef
name|llvm
operator|::
name|PointerIntPair
operator|<
name|decl_type
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|base_type
expr_stmt|;
name|bool
name|NextIsPrevious
argument_list|()
specifier|const
block|{
return|return
name|base_type
operator|::
name|getInt
argument_list|()
operator|==
name|false
return|;
block|}
name|bool
name|NextIsLatest
argument_list|()
specifier|const
block|{
return|return
name|base_type
operator|::
name|getInt
argument_list|()
operator|==
name|true
return|;
block|}
name|decl_type
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|base_type
operator|::
name|getPointer
argument_list|()
return|;
block|}
expr|}
block|;    struct
name|PreviousDeclLink
operator|:
name|public
name|DeclLink
block|{
name|PreviousDeclLink
argument_list|(
name|decl_type
operator|*
name|D
argument_list|)
operator|:
name|DeclLink
argument_list|(
argument|D
argument_list|,
argument|false
argument_list|)
block|{ }
block|}
block|;    struct
name|LatestDeclLink
operator|:
name|public
name|DeclLink
block|{
name|LatestDeclLink
argument_list|(
name|decl_type
operator|*
name|D
argument_list|)
operator|:
name|DeclLink
argument_list|(
argument|D
argument_list|,
argument|true
argument_list|)
block|{ }
block|}
block|;
comment|/// \brief Points to the next redeclaration in the chain.
comment|///
comment|/// If NextIsPrevious() is true, this is a link to the previous declaration
comment|/// of this same Decl. If NextIsLatest() is true, this is the first
comment|/// declaration and Link points to the latest declaration. For example:
comment|///
comment|///  #1 int f(int x, int y = 1); //<pointer to #3, true>
comment|///  #2 int f(int x = 0, int y); //<pointer to #1, false>
comment|///  #3 int f(int x, int y) { return x + y; } //<pointer to #2, false>
comment|///
comment|/// If there is only one declaration, it is<pointer to self, true>
name|DeclLink
name|RedeclLink
block|;
name|public
operator|:
name|Redeclarable
argument_list|()
operator|:
name|RedeclLink
argument_list|(
argument|LatestDeclLink(static_cast<decl_type*>(this))
argument_list|)
block|{ }
comment|/// \brief Return the previous declaration of this declaration or NULL if this
comment|/// is the first declaration.
name|decl_type
operator|*
name|getPreviousDeclaration
argument_list|()
block|{
if|if
condition|(
name|RedeclLink
operator|.
name|NextIsPrevious
argument_list|()
condition|)
return|return
name|RedeclLink
operator|.
name|getNext
argument_list|()
return|;
return|return
literal|0
return|;
block|}
specifier|const
name|decl_type
operator|*
name|getPreviousDeclaration
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|decl_type
operator|*
operator|>
operator|(
name|this
operator|)
operator|)
operator|->
name|getPreviousDeclaration
argument_list|()
return|;
block|}
comment|/// \brief Return the first declaration of this declaration or itself if this
comment|/// is the only declaration.
name|decl_type
modifier|*
name|getFirstDeclaration
parameter_list|()
block|{
name|decl_type
modifier|*
name|D
init|=
name|static_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|this
operator|)
decl_stmt|;
while|while
condition|(
name|D
operator|->
name|getPreviousDeclaration
argument_list|()
condition|)
name|D
operator|=
name|D
operator|->
name|getPreviousDeclaration
argument_list|()
expr_stmt|;
return|return
name|D
return|;
block|}
comment|/// \brief Return the first declaration of this declaration or itself if this
comment|/// is the only declaration.
specifier|const
name|decl_type
operator|*
name|getFirstDeclaration
argument_list|()
specifier|const
block|{
specifier|const
name|decl_type
operator|*
name|D
operator|=
name|static_cast
operator|<
specifier|const
name|decl_type
operator|*
operator|>
operator|(
name|this
operator|)
block|;
while|while
condition|(
name|D
operator|->
name|getPreviousDeclaration
argument_list|()
condition|)
name|D
operator|=
name|D
operator|->
name|getPreviousDeclaration
argument_list|()
expr_stmt|;
return|return
name|D
return|;
block|}
end_decl_stmt

begin_comment
comment|/// \brief Returns the most recent (re)declaration of this declaration.
end_comment

begin_expr_stmt
specifier|const
name|decl_type
operator|*
name|getMostRecentDeclaration
argument_list|()
specifier|const
block|{
return|return
name|getFirstDeclaration
argument_list|()
operator|->
name|RedeclLink
operator|.
name|getNext
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Set the previous declaration. If PrevDecl is NULL, set this as the
end_comment

begin_comment
comment|/// first and only declaration.
end_comment

begin_function
name|void
name|setPreviousDeclaration
parameter_list|(
name|decl_type
modifier|*
name|PrevDecl
parameter_list|)
block|{
name|decl_type
modifier|*
name|First
decl_stmt|;
if|if
condition|(
name|PrevDecl
condition|)
block|{
comment|// Point to previous.
name|RedeclLink
operator|=
name|PreviousDeclLink
argument_list|(
name|PrevDecl
argument_list|)
expr_stmt|;
name|First
operator|=
name|PrevDecl
operator|->
name|getFirstDeclaration
argument_list|()
expr_stmt|;
name|assert
argument_list|(
name|First
operator|->
name|RedeclLink
operator|.
name|NextIsLatest
argument_list|()
operator|&&
literal|"Expected first"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Make this first.
name|First
operator|=
name|static_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|this
operator|)
expr_stmt|;
block|}
comment|// First one will point to this one as latest.
name|First
operator|->
name|RedeclLink
operator|=
name|LatestDeclLink
argument_list|(
name|static_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// \brief Iterates through all the redeclarations of the same decl.
end_comment

begin_decl_stmt
name|class
name|redecl_iterator
block|{
comment|/// Current - The current declaration.
name|decl_type
modifier|*
name|Current
decl_stmt|;
name|decl_type
modifier|*
name|Starter
decl_stmt|;
name|public
label|:
typedef|typedef
name|decl_type
modifier|*
name|value_type
typedef|;
typedef|typedef
name|decl_type
modifier|*
name|reference
typedef|;
typedef|typedef
name|decl_type
modifier|*
name|pointer
typedef|;
typedef|typedef
name|std
operator|::
name|forward_iterator_tag
name|iterator_category
expr_stmt|;
typedef|typedef
name|std
operator|::
name|ptrdiff_t
name|difference_type
expr_stmt|;
name|redecl_iterator
argument_list|()
operator|:
name|Current
argument_list|(
literal|0
argument_list|)
block|{ }
name|explicit
name|redecl_iterator
argument_list|(
name|decl_type
operator|*
name|C
argument_list|)
operator|:
name|Current
argument_list|(
name|C
argument_list|)
operator|,
name|Starter
argument_list|(
argument|C
argument_list|)
block|{ }
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
name|pointer
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|Current
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|redecl_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|assert
argument_list|(
name|Current
operator|&&
literal|"Advancing while iterator has reached end"
argument_list|)
block|;
comment|// Get either previous decl or latest decl.
name|decl_type
operator|*
name|Next
operator|=
name|Current
operator|->
name|RedeclLink
operator|.
name|getNext
argument_list|()
block|;
name|Current
operator|=
operator|(
name|Next
operator|!=
name|Starter
condition|?
name|Next
else|:
literal|0
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|redecl_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|redecl_iterator
name|tmp
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
operator|(
operator|*
name|this
operator|)
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
name|redecl_iterator
name|x
operator|,
name|redecl_iterator
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|==
name|y
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
name|redecl_iterator
name|x
operator|,
name|redecl_iterator
name|y
operator|)
block|{
return|return
name|x
operator|.
name|Current
operator|!=
name|y
operator|.
name|Current
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// \brief Returns iterator for all the redeclarations of the same decl.
end_comment

begin_comment
comment|/// It will iterate at least once (when this decl is the only one).
end_comment

begin_expr_stmt
name|redecl_iterator
name|redecls_begin
argument_list|()
specifier|const
block|{
return|return
name|redecl_iterator
argument_list|(
name|const_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|static_cast
operator|<
specifier|const
name|decl_type
operator|*
operator|>
operator|(
name|this
operator|)
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|redecl_iterator
name|redecls_end
argument_list|()
specifier|const
block|{
return|return
name|redecl_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_endif
unit|};  }
endif|#
directive|endif
end_endif

end_unit

