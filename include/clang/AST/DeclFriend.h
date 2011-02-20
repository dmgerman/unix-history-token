begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DeclFriend.h - Classes for C++ friend declarations -*- C++ -*------===//
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
comment|// This file defines the section of the AST representing C++ friend
end_comment

begin_comment
comment|// declarations.
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
name|LLVM_CLANG_AST_DECLFRIEND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_DECLFRIEND_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// FriendDecl - Represents the declaration of a friend entity,
comment|/// which can be a function, a type, or a templated function or type.
comment|//  For example:
comment|///
comment|/// @code
comment|/// template<typename T> class A {
comment|///   friend int foo(T);
comment|///   friend class B;
comment|///   friend T; // only in C++0x
comment|///   template<typename U> friend class C;
comment|///   template<typename U> friend A& operator+=(A&, const U&) { ... }
comment|/// };
comment|/// @endcode
comment|///
comment|/// The semantic context of a friend decl is its declaring class.
name|class
name|FriendDecl
range|:
name|public
name|Decl
block|{
name|public
operator|:
typedef|typedef
name|llvm
operator|::
name|PointerUnion
operator|<
name|NamedDecl
operator|*
operator|,
name|TypeSourceInfo
operator|*
operator|>
name|FriendUnion
expr_stmt|;
name|private
operator|:
comment|// The declaration that's a friend of this class.
name|FriendUnion
name|Friend
decl_stmt|;
comment|// A pointer to the next friend in the sequence.
name|LazyDeclPtr
name|NextFriend
decl_stmt|;
comment|// Location of the 'friend' specifier.
name|SourceLocation
name|FriendLoc
decl_stmt|;
comment|/// True if this 'friend' declaration is unsupported.  Eventually we
comment|/// will support every possible friend declaration, but for now we
comment|/// silently ignore some and set this flag to authorize all access.
name|bool
name|UnsupportedFriend
decl_stmt|;
name|friend
name|class
name|CXXRecordDecl
operator|::
name|friend_iterator
expr_stmt|;
name|friend
name|class
name|CXXRecordDecl
decl_stmt|;
name|FriendDecl
argument_list|(
argument|DeclContext *DC
argument_list|,
argument|SourceLocation L
argument_list|,
argument|FriendUnion Friend
argument_list|,
argument|SourceLocation FriendL
argument_list|)
block|:
name|Decl
argument_list|(
name|Decl
operator|::
name|Friend
argument_list|,
name|DC
argument_list|,
name|L
argument_list|)
operator|,
name|Friend
argument_list|(
name|Friend
argument_list|)
operator|,
name|NextFriend
argument_list|()
operator|,
name|FriendLoc
argument_list|(
name|FriendL
argument_list|)
operator|,
name|UnsupportedFriend
argument_list|(
argument|false
argument_list|)
block|{   }
name|explicit
name|FriendDecl
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Decl
argument_list|(
name|Decl
operator|::
name|Friend
argument_list|,
name|Empty
argument_list|)
operator|,
name|NextFriend
argument_list|()
block|{ }
name|FriendDecl
operator|*
name|getNextFriend
argument_list|()
block|{
return|return
name|cast_or_null
operator|<
name|FriendDecl
operator|>
operator|(
name|NextFriend
operator|.
name|get
argument_list|(
name|getASTContext
argument_list|()
operator|.
name|getExternalSource
argument_list|()
argument_list|)
operator|)
return|;
block|}
name|public
label|:
specifier|static
name|FriendDecl
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|SourceLocation
name|L
parameter_list|,
name|FriendUnion
name|Friend_
parameter_list|,
name|SourceLocation
name|FriendL
parameter_list|)
function_decl|;
specifier|static
name|FriendDecl
modifier|*
name|Create
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|EmptyShell
name|Empty
parameter_list|)
function_decl|;
comment|/// If this friend declaration names an (untemplated but possibly
comment|/// dependent) type, return the type; otherwise return null.  This
comment|/// is used for elaborated-type-specifiers and, in C++0x, for
comment|/// arbitrary friend type declarations.
name|TypeSourceInfo
operator|*
name|getFriendType
argument_list|()
specifier|const
block|{
return|return
name|Friend
operator|.
name|dyn_cast
operator|<
name|TypeSourceInfo
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// If this friend declaration doesn't name a type, return the inner
comment|/// declaration.
name|NamedDecl
operator|*
name|getFriendDecl
argument_list|()
specifier|const
block|{
return|return
name|Friend
operator|.
name|dyn_cast
operator|<
name|NamedDecl
operator|*
operator|>
operator|(
operator|)
return|;
block|}
comment|/// Retrieves the location of the 'friend' keyword.
name|SourceLocation
name|getFriendLoc
argument_list|()
specifier|const
block|{
return|return
name|FriendLoc
return|;
block|}
comment|/// Determines if this friend kind is unsupported.
name|bool
name|isUnsupportedFriend
argument_list|()
specifier|const
block|{
return|return
name|UnsupportedFriend
return|;
block|}
name|void
name|setUnsupportedFriend
parameter_list|(
name|bool
name|Unsupported
parameter_list|)
block|{
name|UnsupportedFriend
operator|=
name|Unsupported
expr_stmt|;
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
name|classof
parameter_list|(
specifier|const
name|FriendDecl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
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
operator|==
name|Decl
operator|::
name|Friend
return|;
block|}
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// An iterator over the friend declarations of a class.
end_comment

begin_expr_stmt
name|class
name|CXXRecordDecl
operator|::
name|friend_iterator
block|{
name|FriendDecl
operator|*
name|Ptr
block|;
name|friend
name|class
name|CXXRecordDecl
block|;
name|explicit
name|friend_iterator
argument_list|(
name|FriendDecl
operator|*
name|Ptr
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|Ptr
argument_list|)
block|{}
name|public
operator|:
name|friend_iterator
argument_list|()
block|{}
typedef|typedef
name|FriendDecl
modifier|*
name|value_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|FriendDecl
modifier|*
name|reference
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|FriendDecl
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|difference_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|forward_iterator_tag
name|iterator_category
expr_stmt|;
end_typedef

begin_expr_stmt
name|reference
name|operator
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
name|friend_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|assert
argument_list|(
name|Ptr
operator|&&
literal|"attempt to increment past end of friend list"
argument_list|)
block|;
name|Ptr
operator|=
name|Ptr
operator|->
name|getNextFriend
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend_iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|friend_iterator
name|tmp
operator|=
operator|*
name|this
block|;
operator|++
operator|*
name|this
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|friend_iterator
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Ptr
operator|==
name|Other
operator|.
name|Ptr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|friend_iterator
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|Ptr
operator|!=
name|Other
operator|.
name|Ptr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend_iterator
operator|&
name|operator
operator|+=
operator|(
name|difference_type
name|N
operator|)
block|{
name|assert
argument_list|(
name|N
operator|>=
literal|0
operator|&&
literal|"cannot rewind a CXXRecordDecl::friend_iterator"
argument_list|)
block|;
while|while
condition|(
name|N
operator|--
condition|)
operator|++
operator|*
name|this
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}    friend_iterator
name|operator
operator|+
operator|(
name|difference_type
name|N
operator|)
specifier|const
block|{
name|friend_iterator
name|tmp
operator|=
operator|*
name|this
block|;
name|tmp
operator|+=
name|N
block|;
return|return
name|tmp
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
specifier|inline
name|CXXRecordDecl
operator|::
name|friend_iterator
name|CXXRecordDecl
operator|::
name|friend_begin
argument_list|()
specifier|const
block|{
return|return
name|friend_iterator
argument_list|(
name|data
argument_list|()
operator|.
name|FirstFriend
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|CXXRecordDecl
operator|::
name|friend_iterator
name|CXXRecordDecl
operator|::
name|friend_end
argument_list|()
specifier|const
block|{
return|return
name|friend_iterator
argument_list|(
literal|0
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|void
name|CXXRecordDecl
operator|::
name|pushFriendDecl
argument_list|(
argument|FriendDecl *FD
argument_list|)
block|{
name|assert
argument_list|(
name|FD
operator|->
name|NextFriend
operator|==
literal|0
operator|&&
literal|"friend already has next friend?"
argument_list|)
block|;
name|FD
operator|->
name|NextFriend
operator|=
name|data
argument_list|()
operator|.
name|FirstFriend
block|;
name|data
argument_list|()
operator|.
name|FirstFriend
operator|=
name|FD
block|; }
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

