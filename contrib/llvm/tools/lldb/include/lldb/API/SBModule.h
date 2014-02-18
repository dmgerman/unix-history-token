begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBModule.h ----------------------------------------------*- C++ -*-===//
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
name|LLDB_SBModule_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBModule_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBError.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBSection.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBSymbolContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBValueList.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBModule
block|{
name|public
label|:
name|SBModule
argument_list|()
expr_stmt|;
name|SBModule
argument_list|(
specifier|const
name|SBModule
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|SBModule
argument_list|(
specifier|const
name|SBModuleSpec
operator|&
name|module_spec
argument_list|)
expr_stmt|;
specifier|const
name|SBModule
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SBModule
operator|&
name|rhs
operator|)
decl_stmt|;
name|SBModule
argument_list|(
argument|lldb::SBProcess&process
argument_list|,
argument|lldb::addr_t header_addr
argument_list|)
empty_stmt|;
operator|~
name|SBModule
argument_list|()
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the module file specification.
comment|///
comment|/// This function returns the file for the module on the host system
comment|/// that is running LLDB. This can differ from the path on the
comment|/// platform since we might be doing remote debugging.
comment|///
comment|/// @return
comment|///     A const reference to the file specification object.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBFileSpec
name|GetFileSpec
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the module platform file specification.
comment|///
comment|/// Platform file refers to the path of the module as it is known on
comment|/// the remote system on which it is being debugged. For local
comment|/// debugging this is always the same as Module::GetFileSpec(). But
comment|/// remote debugging might mention a file '/usr/lib/liba.dylib'
comment|/// which might be locally downloaded and cached. In this case the
comment|/// platform file could be something like:
comment|/// '/tmp/lldb/platform-cache/remote.host.computer/usr/lib/liba.dylib'
comment|/// The file could also be cached in a local developer kit directory.
comment|///
comment|/// @return
comment|///     A const reference to the file specification object.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBFileSpec
name|GetPlatformFileSpec
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|SetPlatformFileSpec
argument_list|(
specifier|const
name|lldb
operator|::
name|SBFileSpec
operator|&
name|platform_file
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the remote install path for a module.
comment|///
comment|/// When debugging to a remote platform by connecting to a remote
comment|/// platform, the install path of the module can be set. If the
comment|/// install path is set, every time the process is about to launch
comment|/// the target will install this module on the remote platform prior
comment|/// to launching.
comment|///
comment|/// @return
comment|///     A file specification object.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBFileSpec
name|GetRemoteInstallFileSpec
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set accessor for the remote install path for a module.
comment|///
comment|/// When debugging to a remote platform by connecting to a remote
comment|/// platform, the install path of the module can be set. If the
comment|/// install path is set, every time the process is about to launch
comment|/// the target will install this module on the remote platform prior
comment|/// to launching.
comment|///
comment|/// If \a file specifies a full path to an install location, the
comment|/// module will be installed to this path. If the path is relative
comment|/// (no directory specified, or the path is partial like "usr/lib"
comment|/// or "./usr/lib", then the install path will be resolved using
comment|/// the platform's current working directory as the base path.
comment|///
comment|/// @param[in]
comment|///     A file specification object.
comment|//------------------------------------------------------------------
name|bool
name|SetRemoteInstallFileSpec
argument_list|(
name|lldb
operator|::
name|SBFileSpec
operator|&
name|file
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
expr_stmt|;
name|uint32_t
name|GetAddressByteSize
parameter_list|()
function_decl|;
specifier|const
name|char
modifier|*
name|GetTriple
parameter_list|()
function_decl|;
specifier|const
name|uint8_t
operator|*
name|GetUUIDBytes
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
operator|*
name|GetUUIDString
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|lldb
operator|::
name|SBModule
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|lldb
operator|::
name|SBModule
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|lldb
operator|::
name|SBSection
name|FindSection
argument_list|(
specifier|const
name|char
operator|*
name|sect_name
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBAddress
name|ResolveFileAddress
argument_list|(
argument|lldb::addr_t vm_addr
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBSymbolContext
name|ResolveSymbolContextForAddress
argument_list|(
argument|const lldb::SBAddress& addr
argument_list|,
argument|uint32_t resolve_scope
argument_list|)
expr_stmt|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
name|uint32_t
name|GetNumCompileUnits
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBCompileUnit
name|GetCompileUnitAtIndex
argument_list|(
name|uint32_t
argument_list|)
expr_stmt|;
name|size_t
name|GetNumSymbols
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBSymbol
name|GetSymbolAtIndex
argument_list|(
argument|size_t idx
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBSymbol
name|FindSymbol
argument_list|(
argument|const char *name
argument_list|,
argument|lldb::SymbolType type = eSymbolTypeAny
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBSymbolContextList
name|FindSymbols
argument_list|(
argument|const char *name
argument_list|,
argument|lldb::SymbolType type = eSymbolTypeAny
argument_list|)
expr_stmt|;
name|size_t
name|GetNumSections
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBSection
name|GetSectionAtIndex
argument_list|(
argument|size_t idx
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find functions by name.
comment|///
comment|/// @param[in] name
comment|///     The name of the function we are looking for.
comment|///
comment|/// @param[in] name_type_mask
comment|///     A logical OR of one or more FunctionNameType enum bits that
comment|///     indicate what kind of names should be used when doing the
comment|///     lookup. Bits include fully qualified names, base names,
comment|///     C++ methods, or ObjC selectors.
comment|///     See FunctionNameType for more details.
comment|///
comment|/// @return
comment|///     A lldb::SBSymbolContextList that gets filled in with all of
comment|///     the symbol contexts for all the matches.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBSymbolContextList
name|FindFunctions
argument_list|(
argument|const char *name
argument_list|,
argument|uint32_t name_type_mask = lldb::eFunctionNameTypeAny
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find global and static variables by name.
comment|///
comment|/// @param[in] target
comment|///     A valid SBTarget instance representing the debuggee.
comment|///
comment|/// @param[in] name
comment|///     The name of the global or static variable we are looking
comment|///     for.
comment|///
comment|/// @param[in] max_matches
comment|///     Allow the number of matches to be limited to \a max_matches.
comment|///
comment|/// @return
comment|///     A list of matched variables in an SBValueList.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBValueList
name|FindGlobalVariables
argument_list|(
argument|lldb::SBTarget&target
argument_list|,
argument|const char *name
argument_list|,
argument|uint32_t max_matches
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find the first global (or static) variable by name.
comment|///
comment|/// @param[in] target
comment|///     A valid SBTarget instance representing the debuggee.
comment|///
comment|/// @param[in] name
comment|///     The name of the global or static variable we are looking
comment|///     for.
comment|///
comment|/// @return
comment|///     An SBValue that gets filled in with the found variable (if any).
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBValue
name|FindFirstGlobalVariable
argument_list|(
name|lldb
operator|::
name|SBTarget
operator|&
name|target
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBType
name|FindFirstType
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBTypeList
name|FindTypes
argument_list|(
specifier|const
name|char
operator|*
name|type
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get a type using its type ID.
comment|///
comment|/// Each symbol file reader will assign different user IDs to their
comment|/// types, but it is sometimes useful when debugging type issues to
comment|/// be able to grab a type using its type ID.
comment|///
comment|/// For DWARF debug info, the type ID is the DIE offset.
comment|///
comment|/// @param[in] uid
comment|///     The type user ID.
comment|///
comment|/// @return
comment|///     An SBType for the given type ID, or an empty SBType if the
comment|///     type was not found.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBType
name|GetTypeByID
argument_list|(
argument|lldb::user_id_t uid
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SBType
name|GetBasicType
argument_list|(
argument|lldb::BasicType type
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get all types matching \a type_mask from debug info in this
comment|/// module.
comment|///
comment|/// @param[in] type_mask
comment|///     A bitfield that consists of one or more bits logically OR'ed
comment|///     together from the lldb::TypeClass enumeration. This allows
comment|///     you to request only structure types, or only class, struct
comment|///     and union types. Passing in lldb::eTypeClassAny will return
comment|///     all types found in the debug information for this module.
comment|///
comment|/// @return
comment|///     A list of types in this module that match \a type_mask
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|SBTypeList
name|GetTypes
argument_list|(
argument|uint32_t type_mask = lldb::eTypeClassAny
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the module version numbers.
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
function_decl|;
name|private
label|:
name|friend
name|class
name|SBAddress
decl_stmt|;
name|friend
name|class
name|SBFrame
decl_stmt|;
name|friend
name|class
name|SBSection
decl_stmt|;
name|friend
name|class
name|SBSymbolContext
decl_stmt|;
name|friend
name|class
name|SBTarget
decl_stmt|;
name|explicit
name|SBModule
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
decl_stmt|;
name|ModuleSP
name|GetSP
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetSP
parameter_list|(
specifier|const
name|ModuleSP
modifier|&
name|module_sp
parameter_list|)
function_decl|;
name|lldb
operator|::
name|ModuleSP
name|m_opaque_sp
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBModule_h_
end_comment

end_unit

