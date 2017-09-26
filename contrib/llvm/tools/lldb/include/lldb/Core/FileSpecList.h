begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FileSpecList.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_FileSpecList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_FileSpecList_h_
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
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class FileSpecList FileSpecList.h "lldb/Core/FileSpecList.h"
comment|/// @brief A file collection class.
comment|///
comment|/// A class that contains a mutable list of FileSpec objects.
comment|//----------------------------------------------------------------------
name|class
name|FileSpecList
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Initialize this object with an empty file list.
comment|//------------------------------------------------------------------
name|FileSpecList
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Copy constructor.
comment|///
comment|/// Initialize this object with a copy of the file list from \a rhs.
comment|///
comment|/// @param[in] rhs
comment|///     A const reference to another file list object.
comment|//------------------------------------------------------------------
name|FileSpecList
argument_list|(
specifier|const
name|FileSpecList
operator|&
name|rhs
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|FileSpecList
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Assignment operator.
comment|///
comment|/// Replace the file list in this object with the file list from
comment|/// \a rhs.
comment|///
comment|/// @param[in] rhs
comment|///     A file list object to copy.
comment|///
comment|/// @return
comment|///     A const reference to this object.
comment|//------------------------------------------------------------------
specifier|const
name|FileSpecList
modifier|&
name|operator
init|=
operator|(
specifier|const
name|FileSpecList
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Append a FileSpec object to the list.
comment|///
comment|/// Appends \a file to the end of the file list.
comment|///
comment|/// @param[in] file
comment|///     A new file to append to this file list.
comment|//------------------------------------------------------------------
name|void
name|Append
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Append a FileSpec object if unique.
comment|///
comment|/// Appends \a file to the end of the file list if it doesn't
comment|/// already exist in the file list.
comment|///
comment|/// @param[in] file
comment|///     A new file to append to this file list.
comment|///
comment|/// @return
comment|///     \b true if the file was appended, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|AppendIfUnique
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Clears the file list.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Dumps the file list to the supplied stream pointer "s".
comment|///
comment|/// @param[in] s
comment|///     The stream that will be used to dump the object description.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
specifier|const
name|char
operator|*
name|separator_cstr
operator|=
literal|"\n"
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find a file index.
comment|///
comment|/// Find the index of the file in the file spec list that matches
comment|/// \a file starting \a idx entries into the file spec list.
comment|///
comment|/// @param[in] idx
comment|///     An index into the file list.
comment|///
comment|/// @param[in] file
comment|///     The file specification to search for.
comment|///
comment|/// @param[in] full
comment|///     Should FileSpec::Equal be called with "full" true or false.
comment|///
comment|/// @param[in] remove_backup_dots
comment|///     Should FileSpec::Equal be called with "remove_backup_dots" true or
comment|///     false.
comment|///
comment|/// @return
comment|///     The index of the file that matches \a file if it is found,
comment|///     else UINT32_MAX is returned.
comment|//------------------------------------------------------------------
name|size_t
name|FindFileIndex
argument_list|(
name|size_t
name|idx
argument_list|,
specifier|const
name|FileSpec
operator|&
name|file
argument_list|,
name|bool
name|full
argument_list|,
name|bool
name|remove_backup_dots
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get file at index.
comment|///
comment|/// Gets a file from the file list. If \a idx is not a valid index,
comment|/// an empty FileSpec object will be returned. The file objects
comment|/// that are returned can be tested using
comment|/// FileSpec::operator void*().
comment|///
comment|/// @param[in] idx
comment|///     An index into the file list.
comment|///
comment|/// @return
comment|///     A copy of the FileSpec object at index \a idx. If \a idx
comment|///     is out of range, then an empty FileSpec object will be
comment|///     returned.
comment|//------------------------------------------------------------------
specifier|const
name|FileSpec
modifier|&
name|GetFileSpecAtIndex
argument_list|(
name|size_t
name|idx
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get file specification pointer at index.
comment|///
comment|/// Gets a file from the file list. The file objects that are
comment|/// returned can be tested using FileSpec::operator void*().
comment|///
comment|/// @param[in] idx
comment|///     An index into the file list.
comment|///
comment|/// @return
comment|///     A pointer to a contained FileSpec object at index \a idx.
comment|///     If \a idx is out of range, then an NULL is returned.
comment|//------------------------------------------------------------------
specifier|const
name|FileSpec
modifier|*
name|GetFileSpecPointerAtIndex
argument_list|(
name|size_t
name|idx
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the memory cost of this object.
comment|///
comment|/// Return the size in bytes that this object takes in memory. This
comment|/// returns the size in bytes of this object, not any shared string
comment|/// values it may refer to.
comment|///
comment|/// @return
comment|///     The number of bytes that this object occupies in memory.
comment|///
comment|/// @see ConstString::StaticMemorySize ()
comment|//------------------------------------------------------------------
name|size_t
name|MemorySize
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|IsEmpty
argument_list|()
specifier|const
block|{
return|return
name|m_files
operator|.
name|empty
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the number of files in the file list.
comment|///
comment|/// @return
comment|///     The number of files in the file spec list.
comment|//------------------------------------------------------------------
name|size_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|Insert
parameter_list|(
name|size_t
name|idx
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|file
parameter_list|)
block|{
if|if
condition|(
name|idx
operator|<
name|m_files
operator|.
name|size
argument_list|()
condition|)
block|{
name|m_files
operator|.
name|insert
argument_list|(
name|m_files
operator|.
name|begin
argument_list|()
operator|+
name|idx
argument_list|,
name|file
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
elseif|else
if|if
condition|(
name|idx
operator|==
name|m_files
operator|.
name|size
argument_list|()
condition|)
block|{
name|m_files
operator|.
name|push_back
argument_list|(
name|file
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|bool
name|Replace
parameter_list|(
name|size_t
name|idx
parameter_list|,
specifier|const
name|FileSpec
modifier|&
name|file
parameter_list|)
block|{
if|if
condition|(
name|idx
operator|<
name|m_files
operator|.
name|size
argument_list|()
condition|)
block|{
name|m_files
index|[
name|idx
index|]
operator|=
name|file
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
name|bool
name|Remove
parameter_list|(
name|size_t
name|idx
parameter_list|)
block|{
if|if
condition|(
name|idx
operator|<
name|m_files
operator|.
name|size
argument_list|()
condition|)
block|{
name|m_files
operator|.
name|erase
argument_list|(
name|m_files
operator|.
name|begin
argument_list|()
operator|+
name|idx
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
specifier|static
name|size_t
name|GetFilesMatchingPartialPath
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|bool
name|dir_okay
parameter_list|,
name|FileSpecList
modifier|&
name|matches
parameter_list|)
function_decl|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|FileSpec
operator|>
name|collection
expr_stmt|;
comment|///< The collection type for the file list.
name|collection
name|m_files
decl_stmt|;
comment|///< A collection of FileSpec objects.
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
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_FileSpecList_h_
end_comment

end_unit

