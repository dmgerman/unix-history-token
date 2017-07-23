begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjectContainerBSDArchive.h -----------------------------*- C++ -*-===//
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
name|liblldb_ObjectContainerBSDArchive_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ObjectContainerBSDArchive_h_
end_define

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UniqueCStringMap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ObjectContainer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/Chrono.h"
end_include

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
file|<memory>
end_include

begin_include
include|#
directive|include
file|<mutex>
end_include

begin_decl_stmt
name|class
name|ObjectContainerBSDArchive
range|:
name|public
name|lldb_private
operator|::
name|ObjectContainer
block|{
name|public
operator|:
name|ObjectContainerBSDArchive
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::offset_t data_offset
argument_list|,
argument|const lldb_private::FileSpec *file
argument_list|,
argument|lldb::offset_t offset
argument_list|,
argument|lldb::offset_t length
argument_list|)
block|;
operator|~
name|ObjectContainerBSDArchive
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Static Functions
comment|//------------------------------------------------------------------
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetPluginDescriptionStatic
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ObjectContainer
operator|*
name|CreateInstance
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::offset_t data_offset
argument_list|,
argument|const lldb_private::FileSpec *file
argument_list|,
argument|lldb::offset_t offset
argument_list|,
argument|lldb::offset_t length
argument_list|)
block|;
specifier|static
name|size_t
name|GetModuleSpecifications
argument_list|(
argument|const lldb_private::FileSpec&file
argument_list|,
argument|lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::offset_t data_offset
argument_list|,
argument|lldb::offset_t file_offset
argument_list|,
argument|lldb::offset_t length
argument_list|,
argument|lldb_private::ModuleSpecList&specs
argument_list|)
block|;
specifier|static
name|bool
name|MagicBytesMatch
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Member Functions
comment|//------------------------------------------------------------------
name|bool
name|ParseHeader
argument_list|()
name|override
block|;
name|size_t
name|GetNumObjects
argument_list|()
specifier|const
name|override
block|{
if|if
condition|(
name|m_archive_sp
condition|)
return|return
name|m_archive_sp
operator|->
name|GetNumObjects
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|Dump
argument_list|(
name|lldb_private
operator|::
name|Stream
operator|*
name|s
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ObjectFileSP
name|GetObjectFile
argument_list|(
argument|const lldb_private::FileSpec *file
argument_list|)
name|override
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// PluginInterface protocol
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_struct
struct|struct
name|Object
block|{
name|Object
argument_list|()
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|lldb
operator|::
name|offset_t
name|Extract
argument_list|(
argument|const lldb_private::DataExtractor&data
argument_list|,
argument|lldb::offset_t offset
argument_list|)
expr_stmt|;
name|lldb_private
operator|::
name|ConstString
name|ar_name
expr_stmt|;
comment|// name
name|uint32_t
name|ar_date
decl_stmt|;
comment|// modification time
name|uint16_t
name|ar_uid
decl_stmt|;
comment|// user id
name|uint16_t
name|ar_gid
decl_stmt|;
comment|// group id
name|uint16_t
name|ar_mode
decl_stmt|;
comment|// octal file permissions
name|uint32_t
name|ar_size
decl_stmt|;
comment|// size in bytes
name|lldb
operator|::
name|offset_t
name|ar_file_offset
expr_stmt|;
comment|// file offset in bytes from the beginning of
comment|// the file of the object data
name|lldb
operator|::
name|offset_t
name|ar_file_size
expr_stmt|;
comment|// length of the object data
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Object
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
block|}
struct|;
end_struct

begin_decl_stmt
name|class
name|Archive
block|{
name|public
label|:
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|Archive
operator|>
name|shared_ptr
expr_stmt|;
typedef|typedef
name|std
operator|::
name|multimap
operator|<
name|lldb_private
operator|::
name|FileSpec
operator|,
name|shared_ptr
operator|>
name|Map
expr_stmt|;
name|Archive
argument_list|(
argument|const lldb_private::ArchSpec&arch
argument_list|,
argument|const llvm::sys::TimePoint<>&mod_time
argument_list|,
argument|lldb::offset_t file_offset
argument_list|,
argument|lldb_private::DataExtractor&data
argument_list|)
empty_stmt|;
operator|~
name|Archive
argument_list|()
expr_stmt|;
specifier|static
name|Map
modifier|&
name|GetArchiveCache
parameter_list|()
function_decl|;
specifier|static
name|std
operator|::
name|recursive_mutex
operator|&
name|GetArchiveCacheMutex
argument_list|()
expr_stmt|;
specifier|static
name|Archive
operator|::
name|shared_ptr
name|FindCachedArchive
argument_list|(
argument|const lldb_private::FileSpec&file
argument_list|,
argument|const lldb_private::ArchSpec&arch
argument_list|,
argument|const llvm::sys::TimePoint<>&mod_time
argument_list|,
argument|lldb::offset_t file_offset
argument_list|)
expr_stmt|;
specifier|static
name|Archive
operator|::
name|shared_ptr
name|ParseAndCacheArchiveForFile
argument_list|(
argument|const lldb_private::FileSpec&file
argument_list|,
argument|const lldb_private::ArchSpec&arch
argument_list|,
argument|const llvm::sys::TimePoint<>&mod_time
argument_list|,
argument|lldb::offset_t file_offset
argument_list|,
argument|lldb_private::DataExtractor&data
argument_list|)
expr_stmt|;
name|size_t
name|GetNumObjects
argument_list|()
specifier|const
block|{
return|return
name|m_objects
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|Object
modifier|*
name|GetObjectAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|)
block|{
if|if
condition|(
name|idx
operator|<
name|m_objects
operator|.
name|size
argument_list|()
condition|)
return|return
operator|&
name|m_objects
index|[
name|idx
index|]
return|;
return|return
name|NULL
return|;
block|}
name|size_t
name|ParseObjects
parameter_list|()
function_decl|;
name|Object
modifier|*
name|FindObject
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ConstString
operator|&
name|object_name
argument_list|,
specifier|const
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
operator|&
name|object_mod_time
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|offset_t
name|GetFileOffset
argument_list|()
specifier|const
block|{
return|return
name|m_file_offset
return|;
block|}
specifier|const
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
operator|&
name|GetModificationTime
argument_list|()
block|{
return|return
name|m_time
return|;
block|}
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|GetArchitecture
argument_list|()
specifier|const
block|{
return|return
name|m_arch
return|;
block|}
name|void
name|SetArchitecture
argument_list|(
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
block|{
name|m_arch
operator|=
name|arch
expr_stmt|;
block|}
name|bool
name|HasNoExternalReferences
argument_list|()
specifier|const
expr_stmt|;
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|GetData
argument_list|()
block|{
return|return
name|m_data
return|;
block|}
name|protected
label|:
typedef|typedef
name|lldb_private
operator|::
name|UniqueCStringMap
operator|<
name|uint32_t
operator|>
name|ObjectNameToIndexMap
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|// Member Variables
comment|//----------------------------------------------------------------------
name|lldb_private
operator|::
name|ArchSpec
name|m_arch
expr_stmt|;
name|llvm
operator|::
name|sys
operator|::
name|TimePoint
operator|<
operator|>
name|m_time
expr_stmt|;
name|lldb
operator|::
name|offset_t
name|m_file_offset
expr_stmt|;
name|Object
operator|::
name|collection
name|m_objects
expr_stmt|;
name|ObjectNameToIndexMap
name|m_object_name_to_index_map
decl_stmt|;
name|lldb_private
operator|::
name|DataExtractor
name|m_data
expr_stmt|;
comment|///< The data for this object container
comment|///so we don't lose data if the .a files
comment|///gets modified
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|SetArchive
argument_list|(
name|Archive
operator|::
name|shared_ptr
operator|&
name|archive_sp
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Archive
operator|::
name|shared_ptr
name|m_archive_sp
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ObjectContainerBSDArchive_h_
end_comment

end_unit

