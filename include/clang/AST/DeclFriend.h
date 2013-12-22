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

begin_include
include|#
directive|include
file|"clang/AST/DeclTemplate.h"
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
name|virtual
name|void
name|anchor
argument_list|()
block|;
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
range|:
literal|1
decl_stmt|;
comment|// The number of "outer" template parameter lists in non-templatic
comment|// (currently unsupported) friend type declarations, such as
comment|//     template<class T> friend class A<T>::B;
name|unsigned
name|NumTPLists
range|:
literal|31
decl_stmt|;
comment|// The tail-allocated friend type template parameter lists (if any).
name|TemplateParameterList
operator|*
specifier|const
operator|*
name|getTPLists
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|TemplateParameterList
operator|*
specifier|const
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
name|TemplateParameterList
modifier|*
modifier|*
name|getTPLists
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|TemplateParameterList
operator|*
operator|*
operator|>
operator|(
name|this
operator|+
literal|1
operator|)
return|;
block|}
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
argument_list|,
argument|ArrayRef<TemplateParameterList*> FriendTypeTPLists
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
name|false
argument_list|)
operator|,
name|NumTPLists
argument_list|(
argument|FriendTypeTPLists.size()
argument_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumTPLists
condition|;
operator|++
name|i
control|)
name|getTPLists
argument_list|()
index|[
name|i
index|]
operator|=
name|FriendTypeTPLists
index|[
name|i
index|]
expr_stmt|;
block|}
name|FriendDecl
argument_list|(
argument|EmptyShell Empty
argument_list|,
argument|unsigned NumFriendTypeTPLists
argument_list|)
block|:
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
operator|,
name|NumTPLists
argument_list|(
argument|NumFriendTypeTPLists
argument_list|)
block|{ }
name|FriendDecl
operator|*
name|getNextFriend
argument_list|()
block|{
if|if
condition|(
operator|!
name|NextFriend
operator|.
name|isOffset
argument_list|()
condition|)
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
literal|0
argument_list|)
operator|)
return|;
return|return
name|getNextFriendSlowCase
argument_list|()
return|;
block|}
end_decl_stmt

begin_function_decl
name|FriendDecl
modifier|*
name|getNextFriendSlowCase
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_decl_stmt
specifier|static
name|FriendDecl
modifier|*
name|Create
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|,
name|DeclContext
operator|*
name|DC
argument_list|,
name|SourceLocation
name|L
argument_list|,
name|FriendUnion
name|Friend_
argument_list|,
name|SourceLocation
name|FriendL
argument_list|,
name|ArrayRef
operator|<
name|TemplateParameterList
operator|*
operator|>
name|FriendTypeTPLists
operator|=
name|None
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|FriendDecl
modifier|*
name|CreateDeserialized
parameter_list|(
name|ASTContext
modifier|&
name|C
parameter_list|,
name|unsigned
name|ID
parameter_list|,
name|unsigned
name|FriendTypeNumTPLists
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// If this friend declaration names an (untemplated but possibly
end_comment

begin_comment
comment|/// dependent) type, return the type; otherwise return null.  This
end_comment

begin_comment
comment|/// is used for elaborated-type-specifiers and, in C++0x, for
end_comment

begin_comment
comment|/// arbitrary friend type declarations.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_expr_stmt
name|unsigned
name|getFriendTypeNumTemplateParameterLists
argument_list|()
specifier|const
block|{
return|return
name|NumTPLists
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|TemplateParameterList
modifier|*
name|getFriendTypeTemplateParameterList
argument_list|(
name|unsigned
name|N
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|N
operator|<
name|NumTPLists
argument_list|)
expr_stmt|;
return|return
name|getTPLists
argument_list|()
index|[
name|N
index|]
return|;
block|}
end_decl_stmt

begin_comment
comment|/// If this friend declaration doesn't name a type, return the inner
end_comment

begin_comment
comment|/// declaration.
end_comment

begin_expr_stmt
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
end_expr_stmt

begin_comment
comment|/// Retrieves the location of the 'friend' keyword.
end_comment

begin_expr_stmt
name|SourceLocation
name|getFriendLoc
argument_list|()
specifier|const
block|{
return|return
name|FriendLoc
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Retrieves the source range for the friend declaration.
end_comment

begin_expr_stmt
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
name|LLVM_READONLY
block|{
if|if
condition|(
name|NamedDecl
modifier|*
name|ND
init|=
name|getFriendDecl
argument_list|()
condition|)
block|{
if|if
condition|(
name|FunctionTemplateDecl
modifier|*
name|FTD
init|=
name|dyn_cast
operator|<
name|FunctionTemplateDecl
operator|>
operator|(
name|ND
operator|)
condition|)
return|return
name|FTD
operator|->
name|getSourceRange
argument_list|()
return|;
if|if
condition|(
name|DeclaratorDecl
modifier|*
name|DD
init|=
name|dyn_cast
operator|<
name|DeclaratorDecl
operator|>
operator|(
name|ND
operator|)
condition|)
block|{
if|if
condition|(
name|DD
operator|->
name|getOuterLocStart
argument_list|()
operator|!=
name|DD
operator|->
name|getInnerLocStart
argument_list|()
condition|)
return|return
name|DD
operator|->
name|getSourceRange
argument_list|()
return|;
block|}
end_expr_stmt

begin_return
return|return
name|SourceRange
argument_list|(
name|getFriendLoc
argument_list|()
argument_list|,
name|ND
operator|->
name|getLocEnd
argument_list|()
argument_list|)
return|;
end_return

begin_if
unit|}     else
if|if
condition|(
name|TypeSourceInfo
modifier|*
name|TInfo
init|=
name|getFriendType
argument_list|()
condition|)
block|{
name|SourceLocation
name|StartL
init|=
operator|(
name|NumTPLists
operator|==
literal|0
operator|)
condition|?
name|getFriendLoc
argument_list|()
else|:
name|getTPLists
argument_list|()
index|[
literal|0
index|]
operator|->
name|getTemplateLoc
argument_list|()
decl_stmt|;
return|return
name|SourceRange
argument_list|(
name|StartL
argument_list|,
name|TInfo
operator|->
name|getTypeLoc
argument_list|()
operator|.
name|getEndLoc
argument_list|()
argument_list|)
return|;
block|}
else|else
return|return
name|SourceRange
argument_list|(
name|getFriendLoc
argument_list|()
argument_list|,
name|getLocation
argument_list|()
argument_list|)
return|;
end_if

begin_comment
unit|}
comment|/// Determines if this friend kind is unsupported.
end_comment

begin_macro
unit|bool
name|isUnsupportedFriend
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|UnsupportedFriend
return|;
block|}
end_expr_stmt

begin_function
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
end_function

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
name|Decl
operator|::
name|Friend
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
name|getFirstFriend
argument_list|()
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
operator|!
name|FD
operator|->
name|NextFriend
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

