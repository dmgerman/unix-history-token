begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UniqueCStringMap.h --------------------------------------*- C++ -*-===//
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
name|liblldb_UniqueCStringMap_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_UniqueCStringMap_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/RegularExpression.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// Templatized uniqued string map.
comment|//
comment|// This map is useful for mapping unique C string names to values of
comment|// type T. Each "const char *" name added must be unique for a given
comment|// C string value. ConstString::GetCString() can provide such strings.
comment|// Any other string table that has guaranteed unique values can also
comment|// be used.
comment|//----------------------------------------------------------------------
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|UniqueCStringMap
block|{
name|public
operator|:
expr|struct
name|Entry
block|{
name|Entry
argument_list|()
block|{}
name|Entry
argument_list|(
argument|llvm::StringRef cstr
argument_list|)
operator|:
name|cstring
argument_list|(
name|cstr
argument_list|)
block|,
name|value
argument_list|()
block|{}
name|Entry
argument_list|(
argument|llvm::StringRef cstr
argument_list|,
argument|const T&v
argument_list|)
operator|:
name|cstring
argument_list|(
name|cstr
argument_list|)
block|,
name|value
argument_list|(
argument|v
argument_list|)
block|{}
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Entry
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|cstring
operator|<
name|rhs
operator|.
name|cstring
return|;
block|}
name|llvm
operator|::
name|StringRef
name|cstring
block|;
name|T
name|value
block|;   }
block|;
comment|//------------------------------------------------------------------
comment|// Call this function multiple times to add a bunch of entries to
comment|// this map, then later call UniqueCStringMap<T>::Sort() before doing
comment|// any searches by name.
comment|//------------------------------------------------------------------
name|void
name|Append
argument_list|(
argument|llvm::StringRef unique_cstr
argument_list|,
argument|const T&value
argument_list|)
block|{
name|m_map
operator|.
name|push_back
argument_list|(
argument|typename UniqueCStringMap<T>::Entry(unique_cstr, value)
argument_list|)
block|;   }
name|void
name|Append
argument_list|(
argument|const Entry&e
argument_list|)
block|{
name|m_map
operator|.
name|push_back
argument_list|(
name|e
argument_list|)
block|; }
name|void
name|Clear
argument_list|()
block|{
name|m_map
operator|.
name|clear
argument_list|()
block|; }
comment|//------------------------------------------------------------------
comment|// Call this function to always keep the map sorted when putting
comment|// entries into the map.
comment|//------------------------------------------------------------------
name|void
name|Insert
argument_list|(
argument|llvm::StringRef unique_cstr
argument_list|,
argument|const T&value
argument_list|)
block|{
name|typename
name|UniqueCStringMap
operator|<
name|T
operator|>
operator|::
name|Entry
name|e
argument_list|(
name|unique_cstr
argument_list|,
name|value
argument_list|)
block|;
name|m_map
operator|.
name|insert
argument_list|(
name|std
operator|::
name|upper_bound
argument_list|(
name|m_map
operator|.
name|begin
argument_list|()
argument_list|,
name|m_map
operator|.
name|end
argument_list|()
argument_list|,
name|e
argument_list|)
argument_list|,
name|e
argument_list|)
block|;   }
name|void
name|Insert
argument_list|(
argument|const Entry&e
argument_list|)
block|{
name|m_map
operator|.
name|insert
argument_list|(
name|std
operator|::
name|upper_bound
argument_list|(
name|m_map
operator|.
name|begin
argument_list|()
argument_list|,
name|m_map
operator|.
name|end
argument_list|()
argument_list|,
name|e
argument_list|)
argument_list|,
name|e
argument_list|)
block|;   }
comment|//------------------------------------------------------------------
comment|// Get an entries by index in a variety of forms.
comment|//
comment|// The caller is responsible for ensuring that the collection does
comment|// not change during while using the returned values.
comment|//------------------------------------------------------------------
name|bool
name|GetValueAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|T&value
argument_list|)
specifier|const
block|{
if|if
condition|(
name|idx
operator|<
name|m_map
operator|.
name|size
argument_list|()
condition|)
block|{
name|value
operator|=
name|m_map
index|[
name|idx
index|]
operator|.
name|value
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|llvm
operator|::
name|StringRef
name|GetCStringAtIndexUnchecked
argument_list|(
argument|uint32_t idx
argument_list|)
specifier|const
block|{
return|return
name|m_map
index|[
name|idx
index|]
operator|.
name|cstring
return|;
block|}
comment|// Use this function if you have simple types in your map that you
comment|// can easily copy when accessing values by index.
name|T
name|GetValueAtIndexUnchecked
argument_list|(
argument|uint32_t idx
argument_list|)
specifier|const
block|{
return|return
name|m_map
index|[
name|idx
index|]
operator|.
name|value
return|;
block|}
comment|// Use this function if you have complex types in your map that you
comment|// don't want to copy when accessing values by index.
specifier|const
name|T
operator|&
name|GetValueRefAtIndexUnchecked
argument_list|(
argument|uint32_t idx
argument_list|)
specifier|const
block|{
return|return
name|m_map
index|[
name|idx
index|]
operator|.
name|value
return|;
block|}
name|llvm
operator|::
name|StringRef
name|GetCStringAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
specifier|const
block|{
return|return
operator|(
operator|(
name|idx
operator|<
name|m_map
operator|.
name|size
argument_list|()
operator|)
operator|?
name|m_map
index|[
name|idx
index|]
operator|.
name|cstring
operator|:
name|llvm
operator|::
name|StringRef
argument_list|()
operator|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Find the value for the unique string in the map.
comment|//
comment|// Return the value for \a unique_cstr if one is found, return
comment|// \a fail_value otherwise. This method works well for simple type
comment|// T values and only if there is a sensible failure value that can
comment|// be returned and that won't match any existing values.
comment|//------------------------------------------------------------------
name|T
name|Find
argument_list|(
argument|llvm::StringRef unique_cstr
argument_list|,
argument|T fail_value
argument_list|)
specifier|const
block|{
name|Entry
name|search_entry
argument_list|(
name|unique_cstr
argument_list|)
block|;
name|const_iterator
name|end
operator|=
name|m_map
operator|.
name|end
argument_list|()
block|;
name|const_iterator
name|pos
operator|=
name|std
operator|::
name|lower_bound
argument_list|(
name|m_map
operator|.
name|begin
argument_list|()
argument_list|,
name|end
argument_list|,
name|search_entry
argument_list|)
block|;
if|if
condition|(
name|pos
operator|!=
name|end
condition|)
block|{
if|if
condition|(
name|pos
operator|->
name|cstring
operator|==
name|unique_cstr
condition|)
return|return
name|pos
operator|->
name|value
return|;
block|}
return|return
name|fail_value
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Get a pointer to the first entry that matches "name". nullptr will
comment|// be returned if there is no entry that matches "name".
comment|//
comment|// The caller is responsible for ensuring that the collection does
comment|// not change during while using the returned pointer.
comment|//------------------------------------------------------------------
specifier|const
name|Entry
operator|*
name|FindFirstValueForName
argument_list|(
argument|llvm::StringRef unique_cstr
argument_list|)
specifier|const
block|{
name|Entry
name|search_entry
argument_list|(
name|unique_cstr
argument_list|)
block|;
name|const_iterator
name|end
operator|=
name|m_map
operator|.
name|end
argument_list|()
block|;
name|const_iterator
name|pos
operator|=
name|std
operator|::
name|lower_bound
argument_list|(
name|m_map
operator|.
name|begin
argument_list|()
argument_list|,
name|end
argument_list|,
name|search_entry
argument_list|)
block|;
if|if
condition|(
name|pos
operator|!=
name|end
condition|)
block|{
name|llvm
operator|::
name|StringRef
name|pos_cstr
operator|=
name|pos
operator|->
name|cstring
expr_stmt|;
if|if
condition|(
name|pos_cstr
operator|==
name|unique_cstr
condition|)
return|return
operator|&
operator|(
operator|*
name|pos
operator|)
return|;
block|}
return|return
name|nullptr
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Get a pointer to the next entry that matches "name" from a
comment|// previously returned Entry pointer. nullptr will be returned if there
comment|// is no subsequent entry that matches "name".
comment|//
comment|// The caller is responsible for ensuring that the collection does
comment|// not change during while using the returned pointer.
comment|//------------------------------------------------------------------
specifier|const
name|Entry
operator|*
name|FindNextValueForName
argument_list|(
argument|const Entry *entry_ptr
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|m_map
operator|.
name|empty
argument_list|()
condition|)
block|{
specifier|const
name|Entry
modifier|*
name|first_entry
init|=
operator|&
name|m_map
index|[
literal|0
index|]
decl_stmt|;
specifier|const
name|Entry
modifier|*
name|after_last_entry
init|=
name|first_entry
operator|+
name|m_map
operator|.
name|size
argument_list|()
decl_stmt|;
specifier|const
name|Entry
modifier|*
name|next_entry
init|=
name|entry_ptr
operator|+
literal|1
decl_stmt|;
if|if
condition|(
name|first_entry
operator|<=
name|next_entry
operator|&&
name|next_entry
operator|<
name|after_last_entry
condition|)
block|{
if|if
condition|(
name|next_entry
operator|->
name|cstring
operator|==
name|entry_ptr
operator|->
name|cstring
condition|)
return|return
name|next_entry
return|;
block|}
block|}
return|return
name|nullptr
return|;
block|}
name|size_t
name|GetValues
argument_list|(
argument|llvm::StringRef unique_cstr
argument_list|,
argument|std::vector<T>&values
argument_list|)
specifier|const
block|{
specifier|const
name|size_t
name|start_size
operator|=
name|values
operator|.
name|size
argument_list|()
block|;
name|Entry
name|search_entry
argument_list|(
name|unique_cstr
argument_list|)
block|;
name|const_iterator
name|pos
block|,
name|end
operator|=
name|m_map
operator|.
name|end
argument_list|()
block|;
for|for
control|(
name|pos
operator|=
name|std
operator|::
name|lower_bound
argument_list|(
name|m_map
operator|.
name|begin
argument_list|()
argument_list|,
name|end
argument_list|,
name|search_entry
argument_list|)
init|;
name|pos
operator|!=
name|end
condition|;
operator|++
name|pos
control|)
block|{
if|if
condition|(
name|pos
operator|->
name|cstring
operator|==
name|unique_cstr
condition|)
name|values
operator|.
name|push_back
argument_list|(
name|pos
operator|->
name|value
argument_list|)
expr_stmt|;
else|else
break|break;
block|}
return|return
name|values
operator|.
name|size
argument_list|()
operator|-
name|start_size
return|;
block|}
name|size_t
name|GetValues
argument_list|(
argument|const RegularExpression&regex
argument_list|,
argument|std::vector<T>&values
argument_list|)
specifier|const
block|{
specifier|const
name|size_t
name|start_size
operator|=
name|values
operator|.
name|size
argument_list|()
block|;
name|const_iterator
name|pos
block|,
name|end
operator|=
name|m_map
operator|.
name|end
argument_list|()
block|;
for|for
control|(
name|pos
operator|=
name|m_map
operator|.
name|begin
argument_list|()
init|;
name|pos
operator|!=
name|end
condition|;
operator|++
name|pos
control|)
block|{
if|if
condition|(
name|regex
operator|.
name|Execute
argument_list|(
name|pos
operator|->
name|cstring
argument_list|)
condition|)
name|values
operator|.
name|push_back
argument_list|(
name|pos
operator|->
name|value
argument_list|)
expr_stmt|;
block|}
return|return
name|values
operator|.
name|size
argument_list|()
operator|-
name|start_size
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Get the total number of entries in this map.
comment|//------------------------------------------------------------------
name|size_t
name|GetSize
argument_list|()
specifier|const
block|{
return|return
name|m_map
operator|.
name|size
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Returns true if this map is empty.
comment|//------------------------------------------------------------------
name|bool
name|IsEmpty
argument_list|()
specifier|const
block|{
return|return
name|m_map
operator|.
name|empty
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Reserve memory for at least "n" entries in the map. This is
comment|// useful to call when you know you will be adding a lot of entries
comment|// using UniqueCStringMap::Append() (which should be followed by a
comment|// call to UniqueCStringMap::Sort()) or to UniqueCStringMap::Insert().
comment|//------------------------------------------------------------------
name|void
name|Reserve
argument_list|(
argument|size_t n
argument_list|)
block|{
name|m_map
operator|.
name|reserve
argument_list|(
name|n
argument_list|)
block|; }
comment|//------------------------------------------------------------------
comment|// Sort the unsorted contents in this map. A typical code flow would
comment|// be:
comment|// size_t approximate_num_entries = ....
comment|// UniqueCStringMap<uint32_t> my_map;
comment|// my_map.Reserve (approximate_num_entries);
comment|// for (...)
comment|// {
comment|//      my_map.Append (UniqueCStringMap::Entry(GetName(...), GetValue(...)));
comment|// }
comment|// my_map.Sort();
comment|//------------------------------------------------------------------
name|void
name|Sort
argument_list|()
block|{
name|std
operator|::
name|sort
argument_list|(
name|m_map
operator|.
name|begin
argument_list|()
argument_list|,
name|m_map
operator|.
name|end
argument_list|()
argument_list|)
block|; }
comment|//------------------------------------------------------------------
comment|// Since we are using a vector to contain our items it will always
comment|// double its memory consumption as things are added to the vector,
comment|// so if you intend to keep a UniqueCStringMap around and have
comment|// a lot of entries in the map, you will want to call this function
comment|// to create a new vector and copy _only_ the exact size needed as
comment|// part of the finalization of the string map.
comment|//------------------------------------------------------------------
name|void
name|SizeToFit
argument_list|()
block|{
if|if
condition|(
name|m_map
operator|.
name|size
argument_list|()
operator|<
name|m_map
operator|.
name|capacity
argument_list|()
condition|)
block|{
name|collection
name|temp
argument_list|(
name|m_map
operator|.
name|begin
argument_list|()
argument_list|,
name|m_map
operator|.
name|end
argument_list|()
argument_list|)
decl_stmt|;
name|m_map
operator|.
name|swap
argument_list|(
name|temp
argument_list|)
expr_stmt|;
block|}
block|}
name|size_t
name|Erase
argument_list|(
argument|llvm::StringRef unique_cstr
argument_list|)
block|{
name|size_t
name|num_removed
operator|=
literal|0
block|;
name|Entry
name|search_entry
argument_list|(
name|unique_cstr
argument_list|)
block|;
name|iterator
name|end
operator|=
name|m_map
operator|.
name|end
argument_list|()
block|;
name|iterator
name|begin
operator|=
name|m_map
operator|.
name|begin
argument_list|()
block|;
name|iterator
name|lower_pos
operator|=
name|std
operator|::
name|lower_bound
argument_list|(
name|begin
argument_list|,
name|end
argument_list|,
name|search_entry
argument_list|)
block|;
if|if
condition|(
name|lower_pos
operator|!=
name|end
condition|)
block|{
if|if
condition|(
name|lower_pos
operator|->
name|cstring
operator|==
name|unique_cstr
condition|)
block|{
name|iterator
name|upper_pos
init|=
name|std
operator|::
name|upper_bound
argument_list|(
name|lower_pos
argument_list|,
name|end
argument_list|,
name|search_entry
argument_list|)
decl_stmt|;
if|if
condition|(
name|lower_pos
operator|==
name|upper_pos
condition|)
block|{
name|m_map
operator|.
name|erase
argument_list|(
name|lower_pos
argument_list|)
expr_stmt|;
name|num_removed
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|num_removed
operator|=
name|std
operator|::
name|distance
argument_list|(
name|lower_pos
argument_list|,
name|upper_pos
argument_list|)
expr_stmt|;
name|m_map
operator|.
name|erase
argument_list|(
name|lower_pos
argument_list|,
name|upper_pos
argument_list|)
expr_stmt|;
block|}
block|}
block|}
return|return
name|num_removed
return|;
block|}
name|protected
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Entry
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|typename
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|typename
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|collection
name|m_map
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_UniqueCStringMap_h_
end_comment

end_unit

