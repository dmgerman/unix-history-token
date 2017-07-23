begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ObjectFile.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_ObjectFile_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ObjectFile_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/FileSpecList.h"
end_include

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
file|"lldb/Symbol/Symtab.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/UnwindTable.h"
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
file|"lldb/Utility/UUID.h"
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
name|class
name|ObjectFileJITDelegate
block|{
name|public
label|:
name|ObjectFileJITDelegate
argument_list|()
block|{}
name|virtual
operator|~
name|ObjectFileJITDelegate
argument_list|()
block|{}
name|virtual
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|GetAddressByteSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|PopulateSymtab
argument_list|(
name|lldb_private
operator|::
name|ObjectFile
operator|*
name|obj_file
argument_list|,
name|lldb_private
operator|::
name|Symtab
operator|&
name|symtab
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|PopulateSectionList
argument_list|(
name|lldb_private
operator|::
name|ObjectFile
operator|*
name|obj_file
argument_list|,
name|lldb_private
operator|::
name|SectionList
operator|&
name|section_list
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|bool
name|GetArchitecture
argument_list|(
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class ObjectFile ObjectFile.h "lldb/Symbol/ObjectFile.h"
comment|/// @brief A plug-in interface definition class for object file parsers.
comment|///
comment|/// Object files belong to Module objects and know how to extract
comment|/// information from executable, shared library, and object (.o) files
comment|/// used by operating system runtime. The symbol table and section list
comment|/// for an object file.
comment|///
comment|/// Object files can be represented by the entire file, or by part of a
comment|/// file. An example of a partial file ObjectFile is one that contains
comment|/// information for one of multiple architectures in the same file.
comment|///
comment|/// Once an architecture is selected the object file information can be
comment|/// extracted from this abstract class.
comment|//----------------------------------------------------------------------
name|class
name|ObjectFile
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|ObjectFile
operator|>
decl_stmt|,
name|public
name|PluginInterface
decl_stmt|,
name|public
name|ModuleChild
block|{
name|friend
name|class
name|lldb_private
operator|::
name|Module
expr_stmt|;
name|public
label|:
typedef|typedef
enum|enum
block|{
name|eTypeInvalid
init|=
literal|0
block|,
name|eTypeCoreFile
block|,
comment|/// A core file that has a checkpoint of a program's
comment|/// execution state
name|eTypeExecutable
block|,
comment|/// A normal executable
name|eTypeDebugInfo
block|,
comment|/// An object file that contains only debug information
name|eTypeDynamicLinker
block|,
comment|/// The platform's dynamic linker executable
name|eTypeObjectFile
block|,
comment|/// An intermediate object file
name|eTypeSharedLibrary
block|,
comment|/// A shared library that can be used during execution
name|eTypeStubLibrary
block|,
comment|/// A library that can be linked against but not used for
comment|/// execution
name|eTypeJIT
block|,
comment|/// JIT code that has symbols, sections and possibly debug info
name|eTypeUnknown
block|}
name|Type
typedef|;
typedef|typedef
enum|enum
block|{
name|eStrataInvalid
init|=
literal|0
block|,
name|eStrataUnknown
block|,
name|eStrataUser
block|,
name|eStrataKernel
block|,
name|eStrataRawImage
block|,
name|eStrataJIT
block|}
name|Strata
typedef|;
comment|//------------------------------------------------------------------
comment|/// Construct with a parent module, offset, and header data.
comment|///
comment|/// Object files belong to modules and a valid module must be
comment|/// supplied upon construction. The at an offset within a file for
comment|/// objects that contain more than one architecture or object.
comment|//------------------------------------------------------------------
name|ObjectFile
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|const FileSpec *file_spec_ptr
argument_list|,
argument|lldb::offset_t file_offset
argument_list|,
argument|lldb::offset_t length
argument_list|,
argument|const lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::offset_t data_offset
argument_list|)
empty_stmt|;
name|ObjectFile
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|const lldb::ProcessSP&process_sp
argument_list|,
argument|lldb::addr_t header_addr
argument_list|,
argument|lldb::DataBufferSP&data_sp
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual since this class is designed to be
comment|/// inherited from by the plug-in instance.
comment|//------------------------------------------------------------------
operator|~
name|ObjectFile
argument_list|()
name|override
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
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Find a ObjectFile plug-in that can parse \a file_spec.
comment|///
comment|/// Scans all loaded plug-in interfaces that implement versions of
comment|/// the ObjectFile plug-in interface and returns the first
comment|/// instance that can parse the file.
comment|///
comment|/// @param[in] module
comment|///     The parent module that owns this object file.
comment|///
comment|/// @param[in] file_spec
comment|///     A file specification that indicates which file to use as the
comment|///     object file.
comment|///
comment|/// @param[in] file_offset
comment|///     The offset into the file at which to start parsing the
comment|///     object. This is for files that contain multiple
comment|///     architectures or objects.
comment|///
comment|/// @param[in] file_size
comment|///     The size of the current object file if it can be determined
comment|///     or if it is known. This can be zero.
comment|///
comment|/// @see ObjectFile::ParseHeader()
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|ObjectFileSP
name|FindPlugin
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|const FileSpec *file_spec
argument_list|,
argument|lldb::offset_t file_offset
argument_list|,
argument|lldb::offset_t file_size
argument_list|,
argument|lldb::DataBufferSP&data_sp
argument_list|,
argument|lldb::offset_t&data_offset
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find a ObjectFile plug-in that can parse a file in memory.
comment|///
comment|/// Scans all loaded plug-in interfaces that implement versions of
comment|/// the ObjectFile plug-in interface and returns the first
comment|/// instance that can parse the file.
comment|///
comment|/// @param[in] module
comment|///     The parent module that owns this object file.
comment|///
comment|/// @param[in] process_sp
comment|///     A shared pointer to the process whose memory space contains
comment|///     an object file. This will be stored as a std::weak_ptr.
comment|///
comment|/// @param[in] header_addr
comment|///     The address of the header for the object file in memory.
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|ObjectFileSP
name|FindPlugin
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|,
argument|const lldb::ProcessSP&process_sp
argument_list|,
argument|lldb::addr_t header_addr
argument_list|,
argument|lldb::DataBufferSP&file_data_sp
argument_list|)
expr_stmt|;
specifier|static
name|size_t
name|GetModuleSpecifications
argument_list|(
specifier|const
name|FileSpec
operator|&
name|file
argument_list|,
name|lldb
operator|::
name|offset_t
name|file_offset
argument_list|,
name|lldb
operator|::
name|offset_t
name|file_size
argument_list|,
name|ModuleSpecList
operator|&
name|specs
argument_list|)
decl_stmt|;
specifier|static
name|size_t
name|GetModuleSpecifications
argument_list|(
specifier|const
name|lldb_private
operator|::
name|FileSpec
operator|&
name|file
argument_list|,
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_sp
argument_list|,
name|lldb
operator|::
name|offset_t
name|data_offset
argument_list|,
name|lldb
operator|::
name|offset_t
name|file_offset
argument_list|,
name|lldb
operator|::
name|offset_t
name|file_size
argument_list|,
name|lldb_private
operator|::
name|ModuleSpecList
operator|&
name|specs
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Split a path into a file path with object name.
comment|///
comment|/// For paths like "/tmp/foo.a(bar.o)" we often need to split a path
comment|/// up into the actual path name and into the object name so we can
comment|/// make a valid object file from it.
comment|///
comment|/// @param[in] path_with_object
comment|///     A path that might contain an archive path with a .o file
comment|///     specified in parens in the basename of the path.
comment|///
comment|/// @param[out] archive_file
comment|///     If \b true is returned, \a file_spec will be filled in with
comment|///     the path to the archive.
comment|///
comment|/// @param[out] archive_object
comment|///     If \b true is returned, \a object will be filled in with
comment|///     the name of the object inside the archive.
comment|///
comment|/// @return
comment|///     \b true if the path matches the pattern of archive + object
comment|///     and \a archive_file and \a archive_object are modified,
comment|///     \b false otherwise and \a archive_file and \a archive_object
comment|///     are guaranteed to be remain unchanged.
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|SplitArchivePathWithObject
argument_list|(
specifier|const
name|char
operator|*
name|path_with_object
argument_list|,
name|lldb_private
operator|::
name|FileSpec
operator|&
name|archive_file
argument_list|,
name|lldb_private
operator|::
name|ConstString
operator|&
name|archive_object
argument_list|,
name|bool
name|must_exist
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the address size in bytes for the current object file.
comment|///
comment|/// @return
comment|///     The size of an address in bytes for the currently selected
comment|///     architecture (and object for archives). Returns zero if no
comment|///     architecture or object has been selected.
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|GetAddressByteSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the address type given a file address in an object file.
comment|///
comment|/// Many binary file formats know what kinds
comment|/// This is primarily for ARM binaries, though it can be applied to
comment|/// any executable file format that supports different opcode types
comment|/// within the same binary. ARM binaries support having both ARM and
comment|/// Thumb within the same executable container. We need to be able
comment|/// to get
comment|/// @return
comment|///     The size of an address in bytes for the currently selected
comment|///     architecture (and object for archives). Returns zero if no
comment|///     architecture or object has been selected.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|AddressClass
name|GetAddressClass
argument_list|(
argument|lldb::addr_t file_addr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Extract the dependent modules from an object file.
comment|///
comment|/// If an object file has information about which other images it
comment|/// depends on (such as shared libraries), this function will
comment|/// provide the list. Since many executables or shared libraries
comment|/// may depend on the same files,
comment|/// FileSpecList::AppendIfUnique(const FileSpec&) should be
comment|/// used to make sure any files that are added are not already in
comment|/// the list.
comment|///
comment|/// @param[out] file_list
comment|///     A list of file specification objects that gets dependent
comment|///     files appended to.
comment|///
comment|/// @return
comment|///     The number of new files that were appended to \a file_list.
comment|///
comment|/// @see FileSpecList::AppendIfUnique(const FileSpec&)
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|GetDependentModules
parameter_list|(
name|FileSpecList
modifier|&
name|file_list
parameter_list|)
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Tells whether this object file is capable of being the main executable
comment|/// for a process.
comment|///
comment|/// @return
comment|///     \b true if it is, \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|IsExecutable
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
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
name|GetFileOffset
argument_list|()
specifier|const
block|{
return|return
name|m_file_offset
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
comment|/// Get accessor to the object file specification.
comment|///
comment|/// @return
comment|///     The file specification object pointer if there is one, or
comment|///     NULL if this object is only from memory.
comment|//------------------------------------------------------------------
name|virtual
name|FileSpec
modifier|&
name|GetFileSpec
parameter_list|()
block|{
return|return
name|m_file
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get const accessor to the object file specification.
comment|///
comment|/// @return
comment|///     The const file specification object pointer if there is one,
comment|///     or NULL if this object is only from memory.
comment|//------------------------------------------------------------------
name|virtual
specifier|const
name|FileSpec
operator|&
name|GetFileSpec
argument_list|()
specifier|const
block|{
return|return
name|m_file
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the name of the cpu, vendor and OS for this object file.
comment|///
comment|/// This value is a string that represents the target triple where
comment|/// the cpu type, the vendor and the OS are encoded into a string.
comment|///
comment|/// @param[out] target_triple
comment|///     The string value of the target triple.
comment|///
comment|/// @return
comment|///     \b True if the target triple was able to be computed, \b
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetArchitecture
parameter_list|(
name|ArchSpec
modifier|&
name|arch
parameter_list|)
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Gets the section list for the currently selected architecture
comment|/// (and object for archives).
comment|///
comment|/// Section list parsing can be deferred by ObjectFile instances
comment|/// until this accessor is called the first time.
comment|///
comment|/// @return
comment|///     The list of sections contained in this object file.
comment|//------------------------------------------------------------------
name|virtual
name|SectionList
modifier|*
name|GetSectionList
parameter_list|(
name|bool
name|update_module_section_list
init|=
name|true
parameter_list|)
function_decl|;
name|virtual
name|void
name|CreateSections
parameter_list|(
name|SectionList
modifier|&
name|unified_section_list
parameter_list|)
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Notify the ObjectFile that the file addresses in the Sections
comment|/// for this module have been changed.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|SectionFileAddressesChanged
parameter_list|()
block|{}
comment|//------------------------------------------------------------------
comment|/// Gets the symbol table for the currently selected architecture
comment|/// (and object for archives).
comment|///
comment|/// Symbol table parsing can be deferred by ObjectFile instances
comment|/// until this accessor is called the first time.
comment|///
comment|/// @return
comment|///     The symbol table for this object file.
comment|//------------------------------------------------------------------
name|virtual
name|Symtab
modifier|*
name|GetSymtab
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Appends a Symbol for the specified so_addr to the symbol table.
comment|///
comment|/// If verify_unique is false, the symbol table is not searched
comment|/// to determine if a Symbol found at this address has already been
comment|/// added to the symbol table.  When verify_unique is true, this
comment|/// method resolves the Symbol as the first match in the SymbolTable
comment|/// and appends a Symbol only if required/found.
comment|///
comment|/// @return
comment|///     The resolved symbol or nullptr.  Returns nullptr if a
comment|///     a Symbol could not be found for the specified so_addr.
comment|//------------------------------------------------------------------
name|virtual
name|Symbol
modifier|*
name|ResolveSymbolForAddress
parameter_list|(
specifier|const
name|Address
modifier|&
name|so_addr
parameter_list|,
name|bool
name|verify_unique
parameter_list|)
block|{
comment|// Typically overridden to lazily add stripped symbols recoverable from
comment|// the exception handling unwind information (i.e. without parsing
comment|// the entire eh_frame section.
comment|//
comment|// The availability of LC_FUNCTION_STARTS allows ObjectFileMachO
comment|// to efficiently add stripped symbols when the symbol table is
comment|// first constructed.  Poorer cousins are PECoff and ELF.
return|return
name|nullptr
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Detect if this object file has been stripped of local symbols.
comment|//------------------------------------------------------------------
comment|/// Detect if this object file has been stripped of local symbols.
comment|///
comment|/// @return
comment|///     Return \b true if the object file has been stripped of local
comment|///     symbols.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|IsStripped
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Frees the symbol table.
comment|///
comment|/// This function should only be used when an object file is
comment|///
comment|/// @param[in] flags
comment|///     eSymtabFromUnifiedSectionList: Whether to clear symbol table
comment|///     for unified module section list, or object file.
comment|///
comment|/// @return
comment|///     The symbol table for this object file.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|ClearSymtab
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Gets the UUID for this object file.
comment|///
comment|/// If the object file format contains a UUID, the value should be
comment|/// returned. Else ObjectFile instances should return the MD5
comment|/// checksum of all of the bytes for the object file (or memory for
comment|/// memory based object files).
comment|///
comment|/// @return
comment|///     Returns \b true if a UUID was successfully extracted into
comment|///     \a uuid, \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetUUID
argument_list|(
name|lldb_private
operator|::
name|UUID
operator|*
name|uuid
argument_list|)
init|=
literal|0
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Gets the symbol file spec list for this object file.
comment|///
comment|/// If the object file format contains a debug symbol file link,
comment|/// the values will be returned in the FileSpecList.
comment|///
comment|/// @return
comment|///     Returns filespeclist.
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|FileSpecList
name|GetDebugSymbolFilePaths
argument_list|()
block|{
return|return
name|FileSpecList
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Gets the file spec list of libraries re-exported by this object file.
comment|///
comment|/// If the object file format has the notion of one library re-exporting the
comment|/// symbols from another,
comment|/// the re-exported libraries will be returned in the FileSpecList.
comment|///
comment|/// @return
comment|///     Returns filespeclist.
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|FileSpecList
name|GetReExportedLibraries
argument_list|()
block|{
return|return
name|FileSpecList
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Sets the load address for an entire module, assuming a rigid
comment|/// slide of sections, if possible in the implementation.
comment|///
comment|/// @return
comment|///     Returns true iff any section's load address changed.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|SetLoadAddress
argument_list|(
name|Target
operator|&
name|target
argument_list|,
name|lldb
operator|::
name|addr_t
name|value
argument_list|,
name|bool
name|value_is_offset
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Gets whether endian swapping should occur when extracting data
comment|/// from this object file.
comment|///
comment|/// @return
comment|///     Returns \b true if endian swapping is needed, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Attempts to parse the object header.
comment|///
comment|/// This function is used as a test to see if a given plug-in
comment|/// instance can parse the header data already contained in
comment|/// ObjectFile::m_data. If an object file parser does not
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
comment|/// Returns a reference to the UnwindTable for this ObjectFile
comment|///
comment|/// The UnwindTable contains FuncUnwinders objects for any function in
comment|/// this ObjectFile.  If a FuncUnwinders object hasn't been created yet
comment|/// (i.e. the function has yet to be unwound in a stack walk), it
comment|/// will be created when requested.  Specifically, we do not create
comment|/// FuncUnwinders objects for functions until they are needed.
comment|///
comment|/// @return
comment|///     Returns the unwind table for this object file.
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|UnwindTable
operator|&
name|GetUnwindTable
argument_list|()
block|{
return|return
name|m_unwind_table
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Returns if the function bounds for symbols in this symbol file
comment|/// are likely accurate.
comment|///
comment|/// The unwinder can emulate the instructions of functions to understand
comment|/// prologue/epilogue code sequences, where registers are spilled on
comment|/// the stack, etc.  This feature relies on having the correct start
comment|/// addresses of all functions.  If the ObjectFile has a way to tell
comment|/// that symbols have been stripped and there's no way to reconstruct
comment|/// start addresses (e.g. LC_FUNCTION_STARTS on Mach-O, or eh_frame
comment|/// unwind info), the ObjectFile should indicate that assembly emulation
comment|/// should not be used for this module.
comment|///
comment|/// It is uncommon for this to return false.  An ObjectFile needs to
comment|/// be sure that symbol start addresses are unavailable before false
comment|/// is returned.  If it is unclear, this should return true.
comment|///
comment|/// @return
comment|///     Returns true if assembly emulation should be used for this
comment|///     module.
comment|///     Only returns false if the ObjectFile is sure that symbol
comment|///     addresses are insufficient for accurate assembly emulation.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|AllowAssemblyEmulationUnwindPlans
parameter_list|()
block|{
return|return
name|true
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Similar to Process::GetImageInfoAddress().
comment|///
comment|/// Some platforms embed auxiliary structures useful to debuggers in the
comment|/// address space of the inferior process.  This method returns the address
comment|/// of such a structure if the information can be resolved via entries in
comment|/// the object file.  ELF, for example, provides a means to hook into the
comment|/// runtime linker so that a debugger may monitor the loading and unloading
comment|/// of shared libraries.
comment|///
comment|/// @return
comment|///     The address of any auxiliary tables, or an invalid address if this
comment|///     object file format does not support or contain such information.
name|virtual
name|lldb_private
operator|::
name|Address
name|GetImageInfoAddress
argument_list|(
argument|Target *target
argument_list|)
block|{
return|return
name|Address
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Returns the address of the Entry Point in this object file - if
comment|/// the object file doesn't have an entry point (because it is not an
comment|/// executable file) then an invalid address is returned.
comment|///
comment|/// @return
comment|///     Returns the entry address for this module.
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|Address
name|GetEntryPointAddress
argument_list|()
block|{
return|return
name|Address
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Returns the address that represents the header of this object
comment|/// file.
comment|///
comment|/// The header address is defined as where the header for the object
comment|/// file is that describes the content of the file. If the header
comment|/// doesn't appear in a section that is defined in the object file,
comment|/// an address with no section is returned that has the file offset
comment|/// set in the m_file_offset member of the lldb_private::Address object.
comment|///
comment|/// @return
comment|///     Returns the entry address for this module.
comment|//------------------------------------------------------------------
name|virtual
name|lldb_private
operator|::
name|Address
name|GetHeaderAddress
argument_list|()
block|{
return|return
name|Address
argument_list|(
name|m_memory_addr
argument_list|)
return|;
block|}
name|virtual
name|uint32_t
name|GetNumThreadContexts
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Some object files may have an identifier string embedded in them,
comment|/// e.g. in a Mach-O core file using the LC_IDENT load command (which
comment|/// is obsolete, but can still be found in some old files)
comment|///
comment|/// @return
comment|///     Returns the identifier string if one exists, else an empty
comment|///     string.
comment|//------------------------------------------------------------------
name|virtual
name|std
operator|::
name|string
name|GetIdentifierString
argument_list|()
block|{
return|return
name|std
operator|::
name|string
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// When the ObjectFile is a core file, lldb needs to locate the
comment|/// "binary" in the core file.  lldb can iterate over the pages looking
comment|/// for a valid binary, but some core files may have metadata
comment|/// describing where the main binary is exactly which removes ambiguity
comment|/// when there are multiple binaries present in the captured memory pages.
comment|///
comment|/// @param[out] address
comment|///   If the address of the binary is specified, this will be set.
comment|///   This is an address is the virtual address space of the core file
comment|///   memory segments; it is not an offset into the object file.
comment|///   If no address is available, will be set to LLDB_INVALID_ADDRESS.
comment|///
comment|/// @param[out] uuid
comment|///   If the uuid of the binary is specified, this will be set.
comment|///   If no UUID is available, will be cleared.
comment|///
comment|/// @return
comment|///   Returns true if either address or uuid has been set.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetCorefileMainBinaryInfo
argument_list|(
name|lldb
operator|::
name|addr_t
operator|&
name|address
argument_list|,
name|UUID
operator|&
name|uuid
argument_list|)
block|{
name|address
operator|=
name|LLDB_INVALID_ADDRESS
expr_stmt|;
name|uuid
operator|.
name|Clear
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
name|virtual
name|lldb
operator|::
name|RegisterContextSP
name|GetThreadContextAtIndex
argument_list|(
argument|uint32_t idx
argument_list|,
argument|lldb_private::Thread&thread
argument_list|)
block|{
return|return
name|lldb
operator|::
name|RegisterContextSP
argument_list|()
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// The object file should be able to calculate its type by looking
comment|/// at its file header and possibly the sections or other data in
comment|/// the object file. The file type is used in the debugger to help
comment|/// select the correct plug-ins for the job at hand, so this is
comment|/// important to get right. If any eTypeXXX definitions do not match
comment|/// up with the type of file you are loading, please feel free to
comment|/// add a new enumeration value.
comment|///
comment|/// @return
comment|///     The calculated file type for the current object file.
comment|//------------------------------------------------------------------
name|virtual
name|Type
name|CalculateType
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// In cases where the type can't be calculated (elf files), this
comment|/// routine allows someone to explicitly set it. As an example,
comment|/// SymbolVendorELF uses this routine to set eTypeDebugInfo when
comment|/// loading debug link files.
name|virtual
name|void
name|SetType
parameter_list|(
name|Type
name|type
parameter_list|)
block|{
name|m_type
operator|=
name|type
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// The object file should be able to calculate the strata of the
comment|/// object file.
comment|///
comment|/// Many object files for platforms might be for either user space
comment|/// debugging or for kernel debugging. If your object file subclass
comment|/// can figure this out, it will help with debugger plug-in selection
comment|/// when it comes time to debug.
comment|///
comment|/// @return
comment|///     The calculated object file strata for the current object
comment|///     file.
comment|//------------------------------------------------------------------
name|virtual
name|Strata
name|CalculateStrata
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the object file version numbers.
comment|///
comment|/// Many object files have a set of version numbers that describe
comment|/// the version of the executable or shared library. Typically there
comment|/// are major, minor and build, but there may be more. This function
comment|/// will extract the versions from object files if they are available.
comment|///
comment|/// If \a versions is NULL, or if \a num_versions is 0, the return
comment|/// value will indicate how many version numbers are available in
comment|/// this object file. Then a subsequent call can be made to this
comment|/// function with a value of \a versions and \a num_versions that
comment|/// has enough storage to store some or all version numbers.
comment|///
comment|/// @param[out] versions
comment|///     A pointer to an array of uint32_t types that is \a num_versions
comment|///     long. If this value is NULL, the return value will indicate
comment|///     how many version numbers are required for a subsequent call
comment|///     to this function so that all versions can be retrieved. If
comment|///     the value is non-NULL, then at most \a num_versions of the
comment|///     existing versions numbers will be filled into \a versions.
comment|///     If there is no version information available, \a versions
comment|///     will be filled with \a num_versions UINT32_MAX values
comment|///     and zero will be returned.
comment|///
comment|/// @param[in] num_versions
comment|///     The maximum number of entries to fill into \a versions. If
comment|///     this value is zero, then the return value will indicate
comment|///     how many version numbers there are in total so another call
comment|///     to this function can be make with adequate storage in
comment|///     \a versions to get all of the version numbers. If \a
comment|///     num_versions is less than the actual number of version
comment|///     numbers in this object file, only \a num_versions will be
comment|///     filled into \a versions (if \a versions is non-NULL).
comment|///
comment|/// @return
comment|///     This function always returns the number of version numbers
comment|///     that this object file has regardless of the number of
comment|///     version numbers that were copied into \a versions.
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|GetVersion
parameter_list|(
name|uint32_t
modifier|*
name|versions
parameter_list|,
name|uint32_t
name|num_versions
parameter_list|)
block|{
if|if
condition|(
name|versions
operator|&&
name|num_versions
condition|)
block|{
for|for
control|(
name|uint32_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|num_versions
condition|;
operator|++
name|i
control|)
name|versions
index|[
name|i
index|]
operator|=
name|UINT32_MAX
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the minimum OS version this object file can run on.
comment|///
comment|/// Some object files have information that specifies the minimum OS
comment|/// version that they can be used on.
comment|///
comment|/// If \a versions is NULL, or if \a num_versions is 0, the return
comment|/// value will indicate how many version numbers are available in
comment|/// this object file. Then a subsequent call can be made to this
comment|/// function with a value of \a versions and \a num_versions that
comment|/// has enough storage to store some or all version numbers.
comment|///
comment|/// @param[out] versions
comment|///     A pointer to an array of uint32_t types that is \a num_versions
comment|///     long. If this value is NULL, the return value will indicate
comment|///     how many version numbers are required for a subsequent call
comment|///     to this function so that all versions can be retrieved. If
comment|///     the value is non-NULL, then at most \a num_versions of the
comment|///     existing versions numbers will be filled into \a versions.
comment|///     If there is no version information available, \a versions
comment|///     will be filled with \a num_versions UINT32_MAX values
comment|///     and zero will be returned.
comment|///
comment|/// @param[in] num_versions
comment|///     The maximum number of entries to fill into \a versions. If
comment|///     this value is zero, then the return value will indicate
comment|///     how many version numbers there are in total so another call
comment|///     to this function can be make with adequate storage in
comment|///     \a versions to get all of the version numbers. If \a
comment|///     num_versions is less than the actual number of version
comment|///     numbers in this object file, only \a num_versions will be
comment|///     filled into \a versions (if \a versions is non-NULL).
comment|///
comment|/// @return
comment|///     This function always returns the number of version numbers
comment|///     that this object file has regardless of the number of
comment|///     version numbers that were copied into \a versions.
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|GetMinimumOSVersion
parameter_list|(
name|uint32_t
modifier|*
name|versions
parameter_list|,
name|uint32_t
name|num_versions
parameter_list|)
block|{
if|if
condition|(
name|versions
operator|&&
name|num_versions
condition|)
block|{
for|for
control|(
name|uint32_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|num_versions
condition|;
operator|++
name|i
control|)
name|versions
index|[
name|i
index|]
operator|=
name|UINT32_MAX
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the SDK OS version this object file was built with.
comment|///
comment|/// The versions arguments and returns values are the same as the
comment|/// GetMinimumOSVersion()
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|GetSDKVersion
parameter_list|(
name|uint32_t
modifier|*
name|versions
parameter_list|,
name|uint32_t
name|num_versions
parameter_list|)
block|{
if|if
condition|(
name|versions
operator|&&
name|num_versions
condition|)
block|{
for|for
control|(
name|uint32_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|num_versions
condition|;
operator|++
name|i
control|)
name|versions
index|[
name|i
index|]
operator|=
name|UINT32_MAX
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Return true if this file is a dynamic link editor (dyld)
comment|///
comment|/// Often times dyld has symbols that mirror symbols in libc and
comment|/// other shared libraries (like "malloc" and "free") and the user
comment|/// does _not_ want to stop in these shared libraries by default.
comment|/// We can ask the ObjectFile if it is such a file and should be
comment|/// avoided for things like settings breakpoints and doing function
comment|/// lookups for expressions.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetIsDynamicLinkEditor
parameter_list|()
block|{
return|return
name|false
return|;
block|}
comment|//------------------------------------------------------------------
comment|// Member Functions
comment|//------------------------------------------------------------------
name|Type
name|GetType
parameter_list|()
block|{
if|if
condition|(
name|m_type
operator|==
name|eTypeInvalid
condition|)
name|m_type
operator|=
name|CalculateType
argument_list|()
expr_stmt|;
return|return
name|m_type
return|;
block|}
name|Strata
name|GetStrata
parameter_list|()
block|{
if|if
condition|(
name|m_strata
operator|==
name|eStrataInvalid
condition|)
name|m_strata
operator|=
name|CalculateStrata
argument_list|()
expr_stmt|;
return|return
name|m_strata
return|;
block|}
comment|// When an object file is in memory, subclasses should try and lock
comment|// the process weak pointer. If the process weak pointer produces a
comment|// valid ProcessSP, then subclasses can call this function to read
comment|// memory.
specifier|static
name|lldb
operator|::
name|DataBufferSP
name|ReadMemory
argument_list|(
argument|const lldb::ProcessSP&process_sp
argument_list|,
argument|lldb::addr_t addr
argument_list|,
argument|size_t byte_size
argument_list|)
expr_stmt|;
name|size_t
name|GetData
argument_list|(
name|lldb
operator|::
name|offset_t
name|offset
argument_list|,
name|size_t
name|length
argument_list|,
name|DataExtractor
operator|&
name|data
argument_list|)
decl|const
decl_stmt|;
name|size_t
name|CopyData
argument_list|(
name|lldb
operator|::
name|offset_t
name|offset
argument_list|,
name|size_t
name|length
argument_list|,
name|void
operator|*
name|dst
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|size_t
name|ReadSectionData
argument_list|(
specifier|const
name|Section
operator|*
name|section
argument_list|,
name|lldb
operator|::
name|offset_t
name|section_offset
argument_list|,
name|void
operator|*
name|dst
argument_list|,
name|size_t
name|dst_len
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|size_t
name|ReadSectionData
argument_list|(
specifier|const
name|Section
operator|*
name|section
argument_list|,
name|DataExtractor
operator|&
name|section_data
argument_list|)
decl|const
decl_stmt|;
name|size_t
name|MemoryMapSectionData
argument_list|(
specifier|const
name|Section
operator|*
name|section
argument_list|,
name|DataExtractor
operator|&
name|section_data
argument_list|)
decl|const
decl_stmt|;
name|bool
name|IsInMemory
argument_list|()
specifier|const
block|{
return|return
name|m_memory_addr
operator|!=
name|LLDB_INVALID_ADDRESS
return|;
block|}
comment|// Strip linker annotations (such as @@VERSION) from symbol names.
name|virtual
name|llvm
operator|::
name|StringRef
name|StripLinkerSymbolAnnotations
argument_list|(
argument|llvm::StringRef symbol_name
argument_list|)
specifier|const
block|{
return|return
name|symbol_name
return|;
block|}
specifier|static
name|lldb
operator|::
name|SymbolType
name|GetSymbolTypeFromName
argument_list|(
argument|llvm::StringRef name
argument_list|,
argument|lldb::SymbolType symbol_type_hint = lldb::eSymbolTypeUndefined
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Loads this objfile to memory.
comment|///
comment|/// Loads the bits needed to create an executable image to the memory.
comment|/// It is useful with bare-metal targets where target does not have the
comment|/// ability to start a process itself.
comment|///
comment|/// @param[in] target
comment|///     Target where to load.
comment|///
comment|/// @return
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|LoadInMemory
parameter_list|(
name|Target
modifier|&
name|target
parameter_list|,
name|bool
name|set_pc
parameter_list|)
function_decl|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|FileSpec
name|m_file
decl_stmt|;
name|Type
name|m_type
decl_stmt|;
name|Strata
name|m_strata
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|m_file_offset
expr_stmt|;
comment|///< The offset in bytes into the file, or the
comment|///address in memory
name|lldb
operator|::
name|addr_t
name|m_length
expr_stmt|;
comment|///< The length of this object file if it is known (can
comment|///be zero if length is unknown or can't be
comment|///determined).
name|DataExtractor
name|m_data
decl_stmt|;
comment|///< The data for this object file so things can be parsed lazily.
name|lldb_private
operator|::
name|UnwindTable
name|m_unwind_table
expr_stmt|;
comment|///< Table of FuncUnwinders objects
comment|/// created for this ObjectFile's
comment|/// functions
name|lldb
operator|::
name|ProcessWP
name|m_process_wp
expr_stmt|;
specifier|const
name|lldb
operator|::
name|addr_t
name|m_memory_addr
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|SectionList
operator|>
name|m_sections_ap
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|Symtab
operator|>
name|m_symtab_ap
expr_stmt|;
name|uint32_t
name|m_synthetic_symbol_idx
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Sets the architecture for a module.  At present the architecture
comment|/// can only be set if it is invalid.  It is not allowed to switch from
comment|/// one concrete architecture to another.
comment|///
comment|/// @param[in] new_arch
comment|///     The architecture this module will be set to.
comment|///
comment|/// @return
comment|///     Returns \b true if the architecture was changed, \b
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|SetModulesArchitecture
parameter_list|(
specifier|const
name|ArchSpec
modifier|&
name|new_arch
parameter_list|)
function_decl|;
name|ConstString
name|GetNextSyntheticSymbolName
parameter_list|()
function_decl|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ObjectFile
argument_list|)
expr_stmt|;
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
comment|// liblldb_ObjectFile_h_
end_comment

end_unit

