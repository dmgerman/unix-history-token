begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- STLUtils.h ----------------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_STLUtils_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_STLUtils_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<ostream>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// C string less than compare function object
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_struct
struct|struct
name|CStringCompareFunctionObject
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|char
operator|*
name|s1
operator|,
specifier|const
name|char
operator|*
name|s2
operator|)
specifier|const
block|{
return|return
name|strcmp
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
operator|<
literal|0
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// C string equality function object (binary predicate).
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_struct
struct|struct
name|CStringEqualBinaryPredicate
block|{
name|bool
name|operator
argument_list|()
operator|(
specifier|const
name|char
operator|*
name|s1
operator|,
specifier|const
name|char
operator|*
name|s2
operator|)
specifier|const
block|{
return|return
name|strcmp
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|)
operator|==
literal|0
return|;
block|}
block|}
struct|;
end_struct

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Templated type for finding an entry in a std::map<F,S> whose value
end_comment

begin_comment
comment|// is equal to something
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|F
operator|,
name|class
name|S
operator|>
name|class
name|ValueEquals
block|{
name|private
operator|:
name|S
name|second_value
block|;
name|public
operator|:
name|ValueEquals
argument_list|(
specifier|const
name|S
operator|&
name|val
argument_list|)
operator|:
name|second_value
argument_list|(
argument|val
argument_list|)
block|{}
comment|// Compare the second item
name|bool
name|operator
argument_list|()
operator|(
name|std
operator|::
name|pair
operator|<
specifier|const
name|F
operator|,
name|S
operator|>
name|elem
operator|)
block|{
return|return
name|elem
operator|.
name|second
operator|==
name|second_value
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|void
name|PrintAllCollectionElements
argument_list|(
argument|std::ostream&s
argument_list|,
argument|const T& coll
argument_list|,
argument|const char* header_cstr=NULL
argument_list|,
argument|const char* separator_cstr=
literal|" "
argument_list|)
block|{
name|typename
name|T
operator|::
name|const_iterator
name|pos
block|;
if|if
condition|(
name|header_cstr
condition|)
name|s
operator|<<
name|header_cstr
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|pos
operator|=
name|coll
operator|.
name|begin
argument_list|()
init|;
name|pos
operator|!=
name|coll
operator|.
name|end
argument_list|()
condition|;
operator|++
name|pos
control|)
block|{
name|s
operator|<<
operator|*
name|pos
operator|<<
name|separator_cstr
expr_stmt|;
block|}
end_for

begin_expr_stmt
name|s
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// The function object below can be used to delete a STL container that
end_comment

begin_comment
comment|// contains C++ object pointers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Usage: std::for_each(vector.begin(), vector.end(), for_each_delete());
end_comment

begin_macro
unit|struct
name|for_each_cplusplus_delete
end_macro

begin_block
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|operator
argument_list|()
operator|(
name|T
operator|*
name|ptr
operator|)
block|{
name|delete
name|ptr
block|;}
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|STLStringArray
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
specifier|const
name|char
operator|*
operator|>
name|CStringArray
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_STLUtils_h_
end_comment

end_unit

