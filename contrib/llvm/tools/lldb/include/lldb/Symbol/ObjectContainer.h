begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjectContainer.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_ObjectContainer_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ObjectContainer_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ModuleChild.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Endian.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ObjectContainer ObjectContainer.h "lldb/Symbol/ObjectContainer.h"
comment|/// @brief A plug-in interface definition class for object containers.
comment|///
comment|/// Object containers contain object files from one or more
comment|/// architectures, and also can contain one or more named objects.
comment|///
comment|/// Typical object containers are static libraries (.a files) that
comment|/// contain multiple named object files, and universal files that contain
comment|/// multiple architectures.
comment|//----------------------------------------------------------------------
name|class
name|ObjectContainer
range|:
name|public
name|PluginInterface
decl_stmt|,
name|public
name|ModuleChild
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Construct with a parent module, offset, and header data.
comment|///
comment|/// Object files belong to modules and a valid module must be
comment|/// supplied upon construction. The at an offset within a file for
comment|/// objects that contain more than one architecture or object.
comment|//------------------------------------------------------------------
name|ObjectContainer
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|const FileSpec *file
argument_list|,
argument|lldb::offset_t file_offset
argument_list|,
argument|lldb::offset_t length
argument_list|,
argument|lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::offset_t data_offset
argument_list|)
block|:
name|ModuleChild
argument_list|(
name|module_sp
argument_list|)
operator|,
name|m_file
argument_list|()
operator|,
comment|// This file can be different than the module's file spec
name|m_offset
argument_list|(
name|file_offset
argument_list|)
operator|,
name|m_length
argument_list|(
name|length
argument_list|)
operator|,
name|m_data
argument_list|()
block|{
if|if
condition|(
name|file
condition|)
name|m_file
operator|=
operator|*
name|file
expr_stmt|;
if|if
condition|(
name|data_sp
condition|)
name|m_data
operator|.
name|SetData
argument_list|(
name|data_sp
argument_list|,
name|data_offset
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual since this class is designed to be
comment|/// inherited from by the plug-in instance.
comment|//------------------------------------------------------------------
operator|~
name|ObjectContainer
argument_list|()
name|override
operator|=
expr|default
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dump a description of this object to a Stream.
comment|///
comment|/// Dump a description of the current contents of this object
comment|/// to the supplied stream \a s. The dumping should include the
comment|/// section list if it has been parsed, and the symbol table
comment|/// if it has been parsed.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the architecture given an index.
comment|///
comment|/// Copies the architecture specification for index \a idx.
comment|///
comment|/// @param[in] idx
comment|///     The architecture index to extract.
comment|///
comment|/// @param[out] arch
comment|///     A architecture object that will be filled in if \a idx is a
comment|///     architecture valid index.
comment|///
comment|/// @return
comment|///     Returns \b true if \a idx is valid and \a arch has been
comment|///     filled in, \b false otherwise.
comment|///
comment|/// @see ObjectContainer::GetNumArchitectures() const
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetArchitectureAtIndex
argument_list|(
name|uint32_t
name|idx
argument_list|,
name|ArchSpec
operator|&
name|arch
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Returns the offset into a file at which this object resides.
comment|///
comment|/// Some files contain many object files, and this function allows
comment|/// access to an object's offset within the file.
comment|///
comment|/// @return
comment|///     The offset in bytes into the file. Defaults to zero for
comment|///     simple object files that a represented by an entire file.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|addr_t
name|GetOffset
argument_list|()
specifier|const
block|{
return|return
name|m_offset
return|;
block|}
name|virtual
name|lldb
operator|::
name|addr_t
name|GetByteSize
argument_list|()
specifier|const
block|{
return|return
name|m_length
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the number of objects within this object file (archives).
comment|///
comment|/// @return
comment|///     Zero for object files that are not archives, or the number
comment|///     of objects contained in the archive.
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|GetNumObjects
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the number of architectures in this object file.
comment|///
comment|/// The default implementation returns 1 as for object files that
comment|/// contain a single architecture. ObjectContainer instances that
comment|/// contain more than one architecture should override this function
comment|/// and return an appropriate value.
comment|///
comment|/// @return
comment|///     The number of architectures contained in this object file.
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|GetNumArchitectures
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Attempts to parse the object header.
comment|///
comment|/// This function is used as a test to see if a given plug-in
comment|/// instance can parse the header data already contained in
comment|/// ObjectContainer::m_data. If an object file parser does not
comment|/// recognize that magic bytes in a header, false should be returned
comment|/// and the next plug-in can attempt to parse an object file.
comment|///
comment|/// @return
comment|///     Returns \b true if the header was parsed successfully, \b
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|ParseHeader
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Selects an architecture in an object file.
comment|///
comment|/// Object files that contain a single architecture should verify
comment|/// that the specified \a arch matches the architecture in in
comment|/// object file and return \b true or \b false accordingly.
comment|///
comment|/// Object files that contain more than one architecture should
comment|/// attempt to select that architecture, and if successful, clear
comment|/// out any previous state from any previously selected architecture
comment|/// and prepare to return information for the new architecture.
comment|///
comment|/// @return
comment|///     Returns a pointer to the object file of the requested \a
comment|///     arch and optional \a name. Returns nullptr of no such object
comment|///     file exists in the container.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ObjectFileSP
name|GetObjectFile
argument_list|(
specifier|const
name|FileSpec
operator|*
name|file
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|ObjectAtIndexIsContainer
parameter_list|(
name|uint32_t
name|object_idx
parameter_list|)
block|{
return|return
name|false
return|;
block|}
name|virtual
name|ObjectFile
modifier|*
name|GetObjectFileAtIndex
parameter_list|(
name|uint32_t
name|object_idx
parameter_list|)
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|ObjectContainer
modifier|*
name|GetObjectContainerAtIndex
parameter_list|(
name|uint32_t
name|object_idx
parameter_list|)
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
specifier|const
name|char
modifier|*
name|GetObjectNameAtIndex
argument_list|(
name|uint32_t
name|object_idx
argument_list|)
decl|const
block|{
return|return
name|nullptr
return|;
block|}
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|FileSpec
name|m_file
decl_stmt|;
comment|///< The file that represents this container objects (which
comment|///can be different from the module's file).
name|lldb
operator|::
name|addr_t
name|m_offset
expr_stmt|;
comment|///< The offset in bytes into the file, or the address in memory
name|lldb
operator|::
name|addr_t
name|m_length
expr_stmt|;
comment|///< The size in bytes if known (can be zero).
name|DataExtractor
name|m_data
decl_stmt|;
comment|///< The data for this object file so things can be parsed lazily.
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ObjectContainer
argument_list|)
expr_stmt|;
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
comment|// liblldb_ObjectContainer_h_
end_comment

end_unit

