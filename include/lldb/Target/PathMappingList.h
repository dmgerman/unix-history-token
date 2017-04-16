begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PathMappingList.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_PathMappingList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_PathMappingList_h_
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
file|<map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|PathMappingList
block|{
name|public
label|:
typedef|typedef
name|void
function_decl|(
modifier|*
name|ChangedCallback
function_decl|)
parameter_list|(
specifier|const
name|PathMappingList
modifier|&
name|path_list
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|PathMappingList
argument_list|()
expr_stmt|;
name|PathMappingList
argument_list|(
argument|ChangedCallback callback
argument_list|,
argument|void *callback_baton
argument_list|)
empty_stmt|;
name|PathMappingList
argument_list|(
specifier|const
name|PathMappingList
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|PathMappingList
argument_list|()
expr_stmt|;
specifier|const
name|PathMappingList
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PathMappingList
operator|&
name|rhs
operator|)
decl_stmt|;
name|void
name|Append
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|path
parameter_list|,
specifier|const
name|ConstString
modifier|&
name|replacement
parameter_list|,
name|bool
name|notify
parameter_list|)
function_decl|;
name|void
name|Append
parameter_list|(
specifier|const
name|PathMappingList
modifier|&
name|rhs
parameter_list|,
name|bool
name|notify
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|(
name|bool
name|notify
parameter_list|)
function_decl|;
comment|// By default, dump all pairs.
name|void
name|Dump
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|,
name|int
name|pair_index
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
name|bool
name|IsEmpty
argument_list|()
specifier|const
block|{
return|return
name|m_pairs
operator|.
name|empty
argument_list|()
return|;
block|}
name|size_t
name|GetSize
argument_list|()
specifier|const
block|{
return|return
name|m_pairs
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|GetPathsAtIndex
argument_list|(
name|uint32_t
name|idx
argument_list|,
name|ConstString
operator|&
name|path
argument_list|,
name|ConstString
operator|&
name|new_path
argument_list|)
decl|const
decl_stmt|;
name|void
name|Insert
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|path
parameter_list|,
specifier|const
name|ConstString
modifier|&
name|replacement
parameter_list|,
name|uint32_t
name|insert_idx
parameter_list|,
name|bool
name|notify
parameter_list|)
function_decl|;
name|bool
name|Remove
parameter_list|(
name|size_t
name|index
parameter_list|,
name|bool
name|notify
parameter_list|)
function_decl|;
name|bool
name|Remove
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|path
parameter_list|,
name|bool
name|notify
parameter_list|)
function_decl|;
name|bool
name|Replace
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|path
parameter_list|,
specifier|const
name|ConstString
modifier|&
name|replacement
parameter_list|,
name|bool
name|notify
parameter_list|)
function_decl|;
name|bool
name|Replace
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|path
parameter_list|,
specifier|const
name|ConstString
modifier|&
name|replacement
parameter_list|,
name|uint32_t
name|index
parameter_list|,
name|bool
name|notify
parameter_list|)
function_decl|;
name|bool
name|RemapPath
argument_list|(
specifier|const
name|ConstString
operator|&
name|path
argument_list|,
name|ConstString
operator|&
name|new_path
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Remaps a source file given \a path into \a new_path.
comment|///
comment|/// Remaps \a path if any source remappings match. This function
comment|/// does NOT stat the file system so it can be used in tight loops
comment|/// where debug info is being parsed.
comment|///
comment|/// @param[in] path
comment|///     The original source file path to try and remap.
comment|///
comment|/// @param[out] new_path
comment|///     The newly remapped filespec that is may or may not exist.
comment|///
comment|/// @return
comment|///     /b true if \a path was successfully located and \a new_path
comment|///     is filled in with a new source path, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|RemapPath
argument_list|(
name|llvm
operator|::
name|StringRef
name|path
argument_list|,
name|std
operator|::
name|string
operator|&
name|new_path
argument_list|)
decl|const
decl_stmt|;
name|bool
name|RemapPath
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|std
operator|::
name|string
operator|&
argument_list|)
decl|const
init|=
name|delete
decl_stmt|;
name|bool
name|ReverseRemapPath
argument_list|(
specifier|const
name|ConstString
operator|&
name|path
argument_list|,
name|ConstString
operator|&
name|new_path
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Finds a source file given a file spec using the path remappings.
comment|///
comment|/// Tries to resolve \a orig_spec by checking the path remappings.
comment|/// It makes sure the file exists by checking with the file system,
comment|/// so this call can be expensive if the remappings are on a network
comment|/// or are even on the local file system, so use this function
comment|/// sparingly (not in a tight debug info parsing loop).
comment|///
comment|/// @param[in] orig_spec
comment|///     The original source file path to try and remap.
comment|///
comment|/// @param[out] new_spec
comment|///     The newly remapped filespec that is guaranteed to exist.
comment|///
comment|/// @return
comment|///     /b true if \a orig_spec was successfully located and
comment|///     \a new_spec is filled in with an existing file spec,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|FindFile
argument_list|(
specifier|const
name|FileSpec
operator|&
name|orig_spec
argument_list|,
name|FileSpec
operator|&
name|new_spec
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|FindIndexForPath
argument_list|(
specifier|const
name|ConstString
operator|&
name|path
argument_list|)
decl|const
decl_stmt|;
name|uint32_t
name|GetModificationID
argument_list|()
specifier|const
block|{
return|return
name|m_mod_id
return|;
block|}
name|protected
label|:
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ConstString
operator|,
name|ConstString
operator|>
name|pair
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|pair
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|iterator
name|FindIteratorForPath
parameter_list|(
specifier|const
name|ConstString
modifier|&
name|path
parameter_list|)
function_decl|;
name|const_iterator
name|FindIteratorForPath
argument_list|(
specifier|const
name|ConstString
operator|&
name|path
argument_list|)
decl|const
decl_stmt|;
name|collection
name|m_pairs
decl_stmt|;
name|ChangedCallback
name|m_callback
decl_stmt|;
name|void
modifier|*
name|m_callback_baton
decl_stmt|;
name|uint32_t
name|m_mod_id
decl_stmt|;
comment|// Incremented anytime anything is added or removed.
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_PathMappingList_h_
end_comment

end_unit

