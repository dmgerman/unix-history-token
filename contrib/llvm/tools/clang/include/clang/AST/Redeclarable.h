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
file|"clang/AST/ExternalASTSource.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
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
name|class
name|ASTContext
decl_stmt|;
comment|// Some notes on redeclarables:
comment|//
comment|//  - Every redeclarable is on a circular linked list.
comment|//
comment|//  - Every decl has a pointer to the first element of the chain _and_ a
comment|//    DeclLink that may point to one of 3 possible states:
comment|//      - the "previous" (temporal) element in the chain
comment|//      - the "latest" (temporal) element in the chain
comment|//      - the an "uninitialized-latest" value (when newly-constructed)
comment|//
comment|//  - The first element is also often called the canonical element. Every
comment|//    element has a pointer to it so that "getCanonical" can be fast.
comment|//
comment|//  - Most links in the chain point to previous, except the link out of
comment|//    the first; it points to latest.
comment|//
comment|//  - Elements are called "first", "previous", "latest" or
comment|//    "most-recent" when referring to temporal order: order of addition
comment|//    to the chain.
comment|//
comment|//  - To make matters confusing, the DeclLink type uses the term "next"
comment|//    for its pointer-storage internally (thus functions like
comment|//    NextIsPrevious). It's easiest to just ignore the implementation of
comment|//    DeclLink when making sense of the redeclaration chain.
comment|//
comment|//  - There's also a "definition" link for several types of
comment|//    redeclarable, where only one definition should exist at any given
comment|//    time (and the defn pointer is stored in the decl's "data" which
comment|//    is copied to every element on the chain when it's changed).
comment|//
comment|//    Here is some ASCII art:
comment|//
comment|//      "first"                                     "latest"
comment|//      "canonical"                                 "most recent"
comment|//      +------------+         first                +--------------+
comment|//      |            |<--------------------------- |              |
comment|//      |            |                              |              |
comment|//      |            |                              |              |
comment|//      |            |       +--------------+       |              |
comment|//      |            | first |              |       |              |
comment|//      |            |<---- |              |       |              |
comment|//      |            |       |              |       |              |
comment|//      | @class A   |  link | @interface A |  link | @class A     |
comment|//      | seen first |<---- | seen second  |<---- | seen third   |
comment|//      |            |       |              |       |              |
comment|//      +------------+       +--------------+       +--------------+
comment|//      | data       | defn  | data         |  defn | data         |
comment|//      |            | ----> |              |<---- |              |
comment|//      +------------+       +--------------+       +--------------+
comment|//        |                     |     ^                  ^
comment|//        |                     |defn |                  |
comment|//        | link                +-----+                  |
comment|//        +-->-------------------------------------------+
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
name|class
name|DeclLink
block|{
comment|/// A pointer to a known latest declaration, either statically known or
comment|/// generationally updated as decls are added by an external source.
typedef|typedef
name|LazyGenerationalUpdatePtr
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|Decl
operator|*
operator|,
operator|&
name|ExternalASTSource
operator|::
name|CompleteRedeclChain
operator|>
name|KnownLatest
expr_stmt|;
comment|/// We store a pointer to the ASTContext in the UninitializedLatest
comment|/// pointer, but to avoid circular type dependencies when we steal the low
comment|/// bits of this pointer, we use a raw void* here.
typedef|typedef
specifier|const
name|void
modifier|*
name|UninitializedLatest
typedef|;
typedef|typedef
name|Decl
modifier|*
name|Previous
typedef|;
comment|/// A pointer to either an uninitialized latest declaration (where either
comment|/// we've not yet set the previous decl or there isn't one), or to a known
comment|/// previous declaration.
typedef|typedef
name|llvm
operator|::
name|PointerUnion
operator|<
name|Previous
operator|,
name|UninitializedLatest
operator|>
name|NotKnownLatest
expr_stmt|;
name|mutable
name|llvm
operator|::
name|PointerUnion
operator|<
name|NotKnownLatest
operator|,
name|KnownLatest
operator|>
name|Next
expr_stmt|;
name|public
label|:
enum|enum
name|PreviousTag
block|{
name|PreviousLink
block|}
enum|;
enum|enum
name|LatestTag
block|{
name|LatestLink
block|}
enum|;
name|DeclLink
argument_list|(
name|LatestTag
argument_list|,
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|)
operator|:
name|Next
argument_list|(
argument|NotKnownLatest(reinterpret_cast<UninitializedLatest>(&Ctx))
argument_list|)
block|{}
name|DeclLink
argument_list|(
name|PreviousTag
argument_list|,
name|decl_type
operator|*
name|D
argument_list|)
operator|:
name|Next
argument_list|(
argument|NotKnownLatest(Previous(D))
argument_list|)
block|{}
name|bool
name|NextIsPrevious
argument_list|()
specifier|const
block|{
return|return
name|Next
operator|.
name|is
operator|<
name|NotKnownLatest
operator|>
operator|(
operator|)
operator|&&
comment|// FIXME: 'template' is required on the next line due to an
comment|// apparent clang bug.
name|Next
operator|.
name|get
operator|<
name|NotKnownLatest
operator|>
operator|(
operator|)
operator|.
name|template
name|is
operator|<
name|Previous
operator|>
operator|(
operator|)
return|;
block|}
name|bool
name|NextIsLatest
argument_list|()
specifier|const
block|{
return|return
operator|!
name|NextIsPrevious
argument_list|()
return|;
block|}
name|decl_type
modifier|*
name|getNext
argument_list|(
specifier|const
name|decl_type
operator|*
name|D
argument_list|)
decl|const
block|{
if|if
condition|(
name|Next
operator|.
name|is
operator|<
name|NotKnownLatest
operator|>
operator|(
operator|)
condition|)
block|{
name|NotKnownLatest
name|NKL
init|=
name|Next
operator|.
name|get
operator|<
name|NotKnownLatest
operator|>
operator|(
operator|)
decl_stmt|;
if|if
condition|(
name|NKL
operator|.
name|is
operator|<
name|Previous
operator|>
operator|(
operator|)
condition|)
return|return
name|static_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|NKL
operator|.
name|get
operator|<
name|Previous
operator|>
operator|(
operator|)
operator|)
return|;
comment|// Allocate the generational 'most recent' cache now, if needed.
name|Next
operator|=
name|KnownLatest
argument_list|(
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|ASTContext
operator|*
operator|>
operator|(
name|NKL
operator|.
name|get
operator|<
name|UninitializedLatest
operator|>
operator|(
operator|)
operator|)
argument_list|,
name|const_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|D
operator|)
argument_list|)
expr_stmt|;
block|}
return|return
name|static_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|Next
operator|.
name|get
operator|<
name|KnownLatest
operator|>
operator|(
operator|)
operator|.
name|get
argument_list|(
name|D
argument_list|)
operator|)
return|;
block|}
name|void
name|setPrevious
parameter_list|(
name|decl_type
modifier|*
name|D
parameter_list|)
block|{
name|assert
argument_list|(
name|NextIsPrevious
argument_list|()
operator|&&
literal|"decl became non-canonical unexpectedly"
argument_list|)
expr_stmt|;
name|Next
operator|=
name|Previous
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
name|void
name|setLatest
parameter_list|(
name|decl_type
modifier|*
name|D
parameter_list|)
block|{
name|assert
argument_list|(
name|NextIsLatest
argument_list|()
operator|&&
literal|"decl became canonical unexpectedly"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Next
operator|.
name|is
operator|<
name|NotKnownLatest
operator|>
operator|(
operator|)
condition|)
block|{
name|NotKnownLatest
name|NKL
init|=
name|Next
operator|.
name|get
operator|<
name|NotKnownLatest
operator|>
operator|(
operator|)
decl_stmt|;
name|Next
operator|=
name|KnownLatest
argument_list|(
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|ASTContext
operator|*
operator|>
operator|(
name|NKL
operator|.
name|get
operator|<
name|UninitializedLatest
operator|>
operator|(
operator|)
operator|)
argument_list|,
name|D
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|auto
name|Latest
init|=
name|Next
operator|.
name|get
operator|<
name|KnownLatest
operator|>
operator|(
operator|)
decl_stmt|;
name|Latest
operator|.
name|set
argument_list|(
name|D
argument_list|)
expr_stmt|;
name|Next
operator|=
name|Latest
expr_stmt|;
block|}
block|}
name|void
name|markIncomplete
parameter_list|()
block|{
name|Next
operator|.
name|get
operator|<
name|KnownLatest
operator|>
operator|(
operator|)
operator|.
name|markIncomplete
argument_list|()
expr_stmt|;
block|}
name|Decl
operator|*
name|getLatestNotUpdated
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|NextIsLatest
argument_list|()
operator|&&
literal|"expected a canonical decl"
argument_list|)
block|;
if|if
condition|(
name|Next
operator|.
name|is
operator|<
name|NotKnownLatest
operator|>
operator|(
operator|)
condition|)
return|return
name|nullptr
return|;
return|return
name|Next
operator|.
name|get
operator|<
name|KnownLatest
operator|>
operator|(
operator|)
operator|.
name|getNotUpdated
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
unit|};
specifier|static
name|DeclLink
name|PreviousDeclLink
parameter_list|(
name|decl_type
modifier|*
name|D
parameter_list|)
block|{
return|return
name|DeclLink
argument_list|(
name|DeclLink
operator|::
name|PreviousLink
argument_list|,
name|D
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|DeclLink
name|LatestDeclLink
parameter_list|(
specifier|const
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
block|{
return|return
name|DeclLink
argument_list|(
name|DeclLink
operator|::
name|LatestLink
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// \brief Points to the next redeclaration in the chain.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If NextIsPrevious() is true, this is a link to the previous declaration
end_comment

begin_comment
comment|/// of this same Decl. If NextIsLatest() is true, this is the first
end_comment

begin_comment
comment|/// declaration and Link points to the latest declaration. For example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///  #1 int f(int x, int y = 1); //<pointer to #3, true>
end_comment

begin_comment
comment|///  #2 int f(int x = 0, int y); //<pointer to #1, false>
end_comment

begin_comment
comment|///  #3 int f(int x, int y) { return x + y; } //<pointer to #2, false>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If there is only one declaration, it is<pointer to self, true>
end_comment

begin_decl_stmt
name|DeclLink
name|RedeclLink
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|decl_type
modifier|*
name|First
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|decl_type
operator|*
name|getNextRedeclaration
argument_list|()
specifier|const
block|{
return|return
name|RedeclLink
operator|.
name|getNext
argument_list|(
name|static_cast
operator|<
specifier|const
name|decl_type
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|Redeclarable
argument_list|(
specifier|const
name|ASTContext
operator|&
name|Ctx
argument_list|)
operator|:
name|RedeclLink
argument_list|(
name|LatestDeclLink
argument_list|(
name|Ctx
argument_list|)
argument_list|)
operator|,
name|First
argument_list|(
argument|static_cast<decl_type *>(this)
argument_list|)
block|{}
comment|/// \brief Return the previous declaration of this declaration or NULL if this
comment|/// is the first declaration.
name|decl_type
operator|*
name|getPreviousDecl
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
name|getNextRedeclaration
argument_list|()
return|;
end_expr_stmt

begin_return
return|return
name|nullptr
return|;
end_return

begin_expr_stmt
unit|}   const
name|decl_type
operator|*
name|getPreviousDecl
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
name|getPreviousDecl
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the first declaration of this declaration or itself if this
end_comment

begin_comment
comment|/// is the only declaration.
end_comment

begin_function
name|decl_type
modifier|*
name|getFirstDecl
parameter_list|()
block|{
return|return
name|First
return|;
block|}
end_function

begin_comment
comment|/// \brief Return the first declaration of this declaration or itself if this
end_comment

begin_comment
comment|/// is the only declaration.
end_comment

begin_expr_stmt
specifier|const
name|decl_type
operator|*
name|getFirstDecl
argument_list|()
specifier|const
block|{
return|return
name|First
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief True if this is the first declaration in its redeclaration chain.
end_comment

begin_expr_stmt
name|bool
name|isFirstDecl
argument_list|()
specifier|const
block|{
return|return
name|RedeclLink
operator|.
name|NextIsLatest
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns the most recent (re)declaration of this declaration.
end_comment

begin_function
name|decl_type
modifier|*
name|getMostRecentDecl
parameter_list|()
block|{
return|return
name|getFirstDecl
argument_list|()
operator|->
name|getNextRedeclaration
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns the most recent (re)declaration of this declaration.
end_comment

begin_expr_stmt
specifier|const
name|decl_type
operator|*
name|getMostRecentDecl
argument_list|()
specifier|const
block|{
return|return
name|getFirstDecl
argument_list|()
operator|->
name|getNextRedeclaration
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

begin_function_decl
name|void
name|setPreviousDecl
parameter_list|(
name|decl_type
modifier|*
name|PrevDecl
parameter_list|)
function_decl|;
end_function_decl

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
name|bool
name|PassedFirst
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
argument|nullptr
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
name|C
argument_list|)
operator|,
name|PassedFirst
argument_list|(
argument|false
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
comment|// Sanity check to avoid infinite loop on invalid redecl chain.
if|if
condition|(
name|Current
operator|->
name|isFirstDecl
argument_list|()
condition|)
block|{
if|if
condition|(
name|PassedFirst
condition|)
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"Passed first decl twice, invalid redecl chain!"
argument_list|)
expr_stmt|;
name|Current
operator|=
name|nullptr
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
name|PassedFirst
operator|=
name|true
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// Get either previous decl or latest decl.
end_comment

begin_expr_stmt
unit|decl_type
operator|*
name|Next
operator|=
name|Current
operator|->
name|getNextRedeclaration
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Current
operator|=
operator|(
name|Next
operator|!=
name|Starter
operator|)
condition|?
name|Next
else|:
name|nullptr
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}      redecl_iterator
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

begin_typedef
unit|};
typedef|typedef
name|llvm
operator|::
name|iterator_range
operator|<
name|redecl_iterator
operator|>
name|redecl_range
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief Returns an iterator range for all the redeclarations of the same
end_comment

begin_comment
comment|/// decl. It will iterate at least once (when this decl is the only one).
end_comment

begin_expr_stmt
name|redecl_range
name|redecls
argument_list|()
specifier|const
block|{
return|return
name|redecl_range
argument_list|(
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
argument_list|,
name|redecl_iterator
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|redecl_iterator
name|redecls_begin
argument_list|()
specifier|const
block|{
return|return
name|redecls
argument_list|()
operator|.
name|begin
argument_list|()
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
name|redecls
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

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
comment|/// \brief Get the primary declaration for a declaration from an AST file. That
end_comment

begin_comment
comment|/// will be the first-loaded declaration.
end_comment

begin_function_decl
name|Decl
modifier|*
name|getPrimaryMergedDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief Provides common interface for the Decls that cannot be redeclared,
end_comment

begin_comment
comment|/// but can be merged if the same declaration is brought in from multiple
end_comment

begin_comment
comment|/// modules.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|decl_type
operator|>
name|class
name|Mergeable
block|{
name|public
operator|:
name|Mergeable
argument_list|()
block|{}
comment|/// \brief Return the first declaration of this declaration or itself if this
comment|/// is the only declaration.
name|decl_type
operator|*
name|getFirstDecl
argument_list|()
block|{
name|decl_type
operator|*
name|D
operator|=
name|static_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|this
operator|)
block|;
if|if
condition|(
operator|!
name|D
operator|->
name|isFromASTFile
argument_list|()
condition|)
return|return
name|D
return|;
return|return
name|cast
operator|<
name|decl_type
operator|>
operator|(
name|getPrimaryMergedDecl
argument_list|(
name|const_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|D
operator|)
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return the first declaration of this declaration or itself if this
end_comment

begin_comment
comment|/// is the only declaration.
end_comment

begin_expr_stmt
specifier|const
name|decl_type
operator|*
name|getFirstDecl
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
if|if
condition|(
operator|!
name|D
operator|->
name|isFromASTFile
argument_list|()
condition|)
return|return
name|D
return|;
end_expr_stmt

begin_return
return|return
name|cast
operator|<
name|decl_type
operator|>
operator|(
name|getPrimaryMergedDecl
argument_list|(
name|const_cast
operator|<
name|decl_type
operator|*
operator|>
operator|(
name|D
operator|)
argument_list|)
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// \brief Returns true if this is the first declaration.
end_comment

begin_macro
unit|bool
name|isFirstDecl
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|getFirstDecl
argument_list|()
operator|==
name|this
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// A wrapper class around a pointer that always points to its canonical
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// CanonicalDeclPtr<decl_type> behaves just like decl_type*, except we call
end_comment

begin_comment
comment|/// decl_type::getCanonicalDecl() on construction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is useful for hashtables that you want to be keyed on a declaration's
end_comment

begin_comment
comment|/// canonical decl -- if you use CanonicalDeclPtr as the key, you don't need to
end_comment

begin_comment
comment|/// remember to call getCanonicalDecl() everywhere.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|decl_type
operator|>
name|class
name|CanonicalDeclPtr
block|{
name|public
operator|:
name|CanonicalDeclPtr
argument_list|()
operator|:
name|Ptr
argument_list|(
argument|nullptr
argument_list|)
block|{}
name|CanonicalDeclPtr
argument_list|(
name|decl_type
operator|*
name|Ptr
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|Ptr ? Ptr->getCanonicalDecl() : nullptr
argument_list|)
block|{}
name|CanonicalDeclPtr
argument_list|(
specifier|const
name|CanonicalDeclPtr
operator|&
argument_list|)
operator|=
expr|default
block|;
name|CanonicalDeclPtr
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CanonicalDeclPtr
operator|&
operator|)
operator|=
expr|default
block|;
name|operator
name|decl_type
operator|*
operator|(
operator|)
block|{
return|return
name|Ptr
return|;
block|}
name|operator
specifier|const
name|decl_type
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|Ptr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|decl_type
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_block
unit|)
block|{
return|return
name|Ptr
return|;
block|}
end_block

begin_expr_stmt
specifier|const
name|decl_type
operator|*
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
return|return
name|Ptr
return|;
block|}
end_expr_stmt

begin_function
name|decl_type
modifier|&
name|operator
modifier|*
parameter_list|()
block|{
return|return
operator|*
name|Ptr
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|decl_type
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|Ptr
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_macro
name|friend
end_macro

begin_expr_stmt
unit|struct
name|llvm
operator|::
name|DenseMapInfo
operator|<
name|CanonicalDeclPtr
operator|<
name|decl_type
operator|>>
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|decl_type
modifier|*
name|Ptr
decl_stmt|;
end_decl_stmt

begin_comment
unit|}; }
comment|// namespace clang
end_comment

begin_macro
unit|namespace
name|llvm
end_macro

begin_block
block|{
name|template
operator|<
name|typename
name|decl_type
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|CanonicalDeclPtr
operator|<
name|decl_type
operator|>>
block|{
name|using
name|CanonicalDeclPtr
operator|=
name|clang
operator|::
name|CanonicalDeclPtr
operator|<
name|decl_type
operator|>
block|;
name|using
name|BaseInfo
operator|=
name|DenseMapInfo
operator|<
name|decl_type
operator|*
operator|>
block|;
specifier|static
name|CanonicalDeclPtr
name|getEmptyKey
argument_list|()
block|{
comment|// Construct our CanonicalDeclPtr this way because the regular constructor
comment|// would dereference P.Ptr, which is not allowed.
name|CanonicalDeclPtr
name|P
block|;
name|P
operator|.
name|Ptr
operator|=
name|BaseInfo
operator|::
name|getEmptyKey
argument_list|()
block|;
return|return
name|P
return|;
block|}
specifier|static
name|CanonicalDeclPtr
name|getTombstoneKey
argument_list|()
block|{
name|CanonicalDeclPtr
name|P
block|;
name|P
operator|.
name|Ptr
operator|=
name|BaseInfo
operator|::
name|getTombstoneKey
argument_list|()
block|;
return|return
name|P
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
parameter_list|(
specifier|const
name|CanonicalDeclPtr
modifier|&
name|P
parameter_list|)
block|{
return|return
name|BaseInfo
operator|::
name|getHashValue
argument_list|(
name|P
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isEqual
parameter_list|(
specifier|const
name|CanonicalDeclPtr
modifier|&
name|LHS
parameter_list|,
specifier|const
name|CanonicalDeclPtr
modifier|&
name|RHS
parameter_list|)
block|{
return|return
name|BaseInfo
operator|::
name|isEqual
argument_list|(
name|LHS
argument_list|,
name|RHS
argument_list|)
return|;
block|}
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

