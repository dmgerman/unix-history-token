begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DynamicLoaderDarwin.h -------------------------------*- C++ -*-===//
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
name|liblldb_DynamicLoaderDarwin_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DynamicLoaderDarwin_h_
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
file|<mutex>
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
file|"lldb/Core/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/DynamicLoader.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/SafeMachO.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UUID.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|DynamicLoaderDarwin
range|:
name|public
name|lldb_private
operator|::
name|DynamicLoader
block|{
name|public
operator|:
name|DynamicLoaderDarwin
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
name|virtual
operator|~
name|DynamicLoaderDarwin
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Called after attaching a process.
comment|///
comment|/// Allow DynamicLoader plug-ins to execute some code after
comment|/// attaching to a process.
comment|//------------------------------------------------------------------
name|void
name|DidAttach
argument_list|()
name|override
block|;
name|void
name|DidLaunch
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ThreadPlanSP
name|GetStepThroughTrampolinePlan
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|bool stop_others
argument_list|)
name|override
block|;
name|size_t
name|FindEquivalentSymbols
argument_list|(
argument|lldb_private::Symbol *original_symbol
argument_list|,
argument|lldb_private::ModuleList&module_list
argument_list|,
argument|lldb_private::SymbolContextList&equivalent_symbols
argument_list|)
name|override
block|;
name|lldb
operator|::
name|addr_t
name|GetThreadLocalData
argument_list|(
argument|const lldb::ModuleSP module
argument_list|,
argument|const lldb::ThreadSP thread
argument_list|,
argument|lldb::addr_t tls_file_addr
argument_list|)
name|override
block|;
name|bool
name|AlwaysRelyOnEHUnwindInfo
argument_list|(
argument|lldb_private::SymbolContext&sym_ctx
argument_list|)
name|override
block|;
name|virtual
name|void
name|DoInitialImageFetch
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|NeedToDoInitialImageFetch
argument_list|()
operator|=
literal|0
block|;
name|protected
operator|:
name|void
name|PrivateInitialize
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
name|void
name|PrivateProcessStateChanged
argument_list|(
argument|lldb_private::Process *process
argument_list|,
argument|lldb::StateType state
argument_list|)
block|;
name|void
name|Clear
argument_list|(
argument|bool clear_process
argument_list|)
block|;
comment|// Clear method for classes derived from this one
name|virtual
name|void
name|DoClear
argument_list|()
operator|=
literal|0
block|;
name|void
name|SetDYLDModule
argument_list|(
name|lldb
operator|::
name|ModuleSP
operator|&
name|dyld_module_sp
argument_list|)
block|;
name|lldb
operator|::
name|ModuleSP
name|GetDYLDModule
argument_list|()
block|;
name|class
name|Segment
block|{
name|public
operator|:
name|Segment
argument_list|()
operator|:
name|name
argument_list|()
block|,
name|vmaddr
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
block|,
name|vmsize
argument_list|(
literal|0
argument_list|)
block|,
name|fileoff
argument_list|(
literal|0
argument_list|)
block|,
name|filesize
argument_list|(
literal|0
argument_list|)
block|,
name|maxprot
argument_list|(
literal|0
argument_list|)
block|,
name|initprot
argument_list|(
literal|0
argument_list|)
block|,
name|nsects
argument_list|(
literal|0
argument_list|)
block|,
name|flags
argument_list|(
literal|0
argument_list|)
block|{}
name|lldb_private
operator|::
name|ConstString
name|name
block|;
name|lldb
operator|::
name|addr_t
name|vmaddr
block|;
name|lldb
operator|::
name|addr_t
name|vmsize
block|;
name|lldb
operator|::
name|addr_t
name|fileoff
block|;
name|lldb
operator|::
name|addr_t
name|filesize
block|;
name|uint32_t
name|maxprot
block|;
name|uint32_t
name|initprot
block|;
name|uint32_t
name|nsects
block|;
name|uint32_t
name|flags
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Segment
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|name
operator|==
name|rhs
operator|.
name|name
operator|&&
name|vmaddr
operator|==
name|rhs
operator|.
name|vmaddr
operator|&&
name|vmsize
operator|==
name|rhs
operator|.
name|vmsize
return|;
block|}
name|void
name|PutToLog
argument_list|(
argument|lldb_private::Log *log
argument_list|,
argument|lldb::addr_t slide
argument_list|)
specifier|const
block|;   }
block|;    struct
name|ImageInfo
block|{
name|lldb
operator|::
name|addr_t
name|address
block|;
comment|// Address of mach header for this dylib
name|lldb
operator|::
name|addr_t
name|slide
block|;
comment|// The amount to slide all segments by if there is a
comment|// global slide.
name|lldb
operator|::
name|addr_t
name|mod_date
block|;
comment|// Modification date for this dylib
name|lldb_private
operator|::
name|FileSpec
name|file_spec
block|;
comment|// Resolved path for this dylib
name|lldb_private
operator|::
name|UUID
name|uuid
block|;
comment|// UUID for this dylib if it has one, else all zeros
name|llvm
operator|::
name|MachO
operator|::
name|mach_header
name|header
block|;
comment|// The mach header for this image
name|std
operator|::
name|vector
operator|<
name|Segment
operator|>
name|segments
block|;
comment|// All segment vmaddr and vmsize pairs for
comment|// this executable (from memory of inferior)
name|uint32_t
name|load_stop_id
block|;
comment|// The process stop ID that the sections for this
comment|// image were loaded
name|llvm
operator|::
name|Triple
operator|::
name|OSType
name|os_type
block|;
comment|// LC_VERSION_MIN_... load command os type
name|std
operator|::
name|string
name|min_version_os_sdk
block|;
comment|// LC_VERSION_MIN_... sdk value
name|ImageInfo
argument_list|()
operator|:
name|address
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
block|,
name|slide
argument_list|(
literal|0
argument_list|)
block|,
name|mod_date
argument_list|(
literal|0
argument_list|)
block|,
name|file_spec
argument_list|()
block|,
name|uuid
argument_list|()
block|,
name|header
argument_list|()
block|,
name|segments
argument_list|()
block|,
name|load_stop_id
argument_list|(
literal|0
argument_list|)
block|,
name|os_type
argument_list|(
name|llvm
operator|::
name|Triple
operator|::
name|OSType
operator|::
name|UnknownOS
argument_list|)
block|,
name|min_version_os_sdk
argument_list|()
block|{}
name|void
name|Clear
argument_list|(
argument|bool load_cmd_data_only
argument_list|)
block|{
if|if
condition|(
operator|!
name|load_cmd_data_only
condition|)
block|{
name|address
operator|=
name|LLDB_INVALID_ADDRESS
expr_stmt|;
name|slide
operator|=
literal|0
expr_stmt|;
name|mod_date
operator|=
literal|0
expr_stmt|;
name|file_spec
operator|.
name|Clear
argument_list|()
expr_stmt|;
operator|::
name|memset
argument_list|(
operator|&
name|header
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|header
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|uuid
operator|.
name|Clear
argument_list|()
expr_stmt|;
name|segments
operator|.
name|clear
argument_list|()
block|;
name|load_stop_id
operator|=
literal|0
block|;
name|os_type
operator|=
name|llvm
operator|::
name|Triple
operator|::
name|OSType
operator|::
name|UnknownOS
block|;
name|min_version_os_sdk
operator|.
name|clear
argument_list|()
block|;     }
name|bool
name|operator
operator|==
operator|(
specifier|const
name|ImageInfo
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
name|address
operator|==
name|rhs
operator|.
name|address
operator|&&
name|slide
operator|==
name|rhs
operator|.
name|slide
operator|&&
name|mod_date
operator|==
name|rhs
operator|.
name|mod_date
operator|&&
name|file_spec
operator|==
name|rhs
operator|.
name|file_spec
operator|&&
name|uuid
operator|==
name|rhs
operator|.
name|uuid
operator|&&
name|memcmp
argument_list|(
operator|&
name|header
argument_list|,
operator|&
name|rhs
operator|.
name|header
argument_list|,
sizeof|sizeof
argument_list|(
name|header
argument_list|)
argument_list|)
operator|==
literal|0
operator|&&
name|segments
operator|==
name|rhs
operator|.
name|segments
operator|&&
name|os_type
operator|==
name|rhs
operator|.
name|os_type
return|;
block|}
name|bool
name|UUIDValid
argument_list|()
specifier|const
block|{
return|return
name|uuid
operator|.
name|IsValid
argument_list|()
return|;
block|}
name|uint32_t
name|GetAddressByteSize
argument_list|()
block|{
if|if
condition|(
name|header
operator|.
name|cputype
condition|)
block|{
if|if
condition|(
name|header
operator|.
name|cputype
operator|&
name|llvm
operator|::
name|MachO
operator|::
name|CPU_ARCH_ABI64
condition|)
return|return
literal|8
return|;
else|else
return|return
literal|4
return|;
block|}
return|return
literal|0
return|;
block|}
name|lldb_private
operator|::
name|ArchSpec
name|GetArchitecture
argument_list|()
specifier|const
block|{
return|return
name|lldb_private
operator|::
name|ArchSpec
argument_list|(
name|lldb_private
operator|::
name|eArchTypeMachO
argument_list|,
name|header
operator|.
name|cputype
argument_list|,
name|header
operator|.
name|cpusubtype
argument_list|)
return|;
block|}
specifier|const
name|Segment
operator|*
name|FindSegment
argument_list|(
argument|const lldb_private::ConstString&name
argument_list|)
specifier|const
block|;
name|void
name|PutToLog
argument_list|(
argument|lldb_private::Log *log
argument_list|)
specifier|const
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|ImageInfo
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|bool
name|UpdateImageLoadAddress
argument_list|(
name|lldb_private
operator|::
name|Module
operator|*
name|module
argument_list|,
name|ImageInfo
operator|&
name|info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|UnloadModuleSections
argument_list|(
name|lldb_private
operator|::
name|Module
operator|*
name|module
argument_list|,
name|ImageInfo
operator|&
name|info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ModuleSP
name|FindTargetModuleForImageInfo
argument_list|(
argument|ImageInfo&image_info
argument_list|,
argument|bool can_create
argument_list|,
argument|bool *did_create_ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|UnloadImages
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|addr_t
operator|>
operator|&
name|solib_addresses
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|UnloadAllImages
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|bool
name|SetNotificationBreakpoint
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|void
name|ClearNotificationBreakpoint
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|bool
name|DidSetNotificationBreakpoint
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint64_t
operator|,
name|lldb
operator|::
name|addr_t
operator|>
name|PthreadKeyToTLSMap
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|user_id_t
operator|,
name|PthreadKeyToTLSMap
operator|>
name|ThreadIDToTLSMap
expr_stmt|;
end_typedef

begin_expr_stmt
name|std
operator|::
name|recursive_mutex
operator|&
name|GetMutex
argument_list|()
specifier|const
block|{
return|return
name|m_mutex
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|ModuleSP
name|GetPThreadLibraryModule
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Address
name|GetPthreadSetSpecificAddress
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|JSONImageInformationIntoImageInfo
argument_list|(
name|lldb_private
operator|::
name|StructuredData
operator|::
name|ObjectSP
name|image_details
argument_list|,
name|ImageInfo
operator|::
name|collection
operator|&
name|image_infos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// If image_infos contains / may contain dyld or executable image, call this
end_comment

begin_comment
comment|// method
end_comment

begin_comment
comment|// to keep our internal record keeping of the special binaries up-to-date.
end_comment

begin_decl_stmt
name|void
name|UpdateSpecialBinariesFromNewImageInfos
argument_list|(
name|ImageInfo
operator|::
name|collection
operator|&
name|image_infos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// if image_info is a dyld binary, call this method
end_comment

begin_function_decl
name|void
name|UpdateDYLDImageInfoFromNewImageInfo
parameter_list|(
name|ImageInfo
modifier|&
name|image_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// If image_infos contains / may contain executable image, call this method
end_comment

begin_comment
comment|// to keep our internal record keeping of the special dyld binary up-to-date.
end_comment

begin_decl_stmt
name|void
name|AddExecutableModuleIfInImageInfos
argument_list|(
name|ImageInfo
operator|::
name|collection
operator|&
name|image_infos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|AddModulesUsingImageInfos
argument_list|(
name|ImageInfo
operator|::
name|collection
operator|&
name|image_infos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Whether we should use the new dyld SPI to get shared library information,
end_comment

begin_comment
comment|// or read
end_comment

begin_comment
comment|// it directly out of the dyld_all_image_infos.  Whether we use the (newer)
end_comment

begin_comment
comment|// DynamicLoaderMacOS
end_comment

begin_comment
comment|// plugin or the (older) DynamicLoaderMacOSX plugin.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|UseDYLDSPI
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ModuleWP
name|m_dyld_module_wp
expr_stmt|;
end_expr_stmt

begin_comment
comment|// the dyld whose file type (mac, ios, etc)
end_comment

begin_comment
comment|// matches the process
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ModuleWP
name|m_libpthread_module_wp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Address
name|m_pthread_getspecific_addr
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|ThreadIDToTLSMap
name|m_tid_to_tls_map
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|ImageInfo
operator|::
name|collection
name|m_dyld_image_infos
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Current shared libraries information
end_comment

begin_decl_stmt
name|uint32_t
name|m_dyld_image_infos_stop_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The process stop ID that
end_comment

begin_comment
comment|// "m_dyld_image_infos" is valid for
end_comment

begin_decl_stmt
name|ImageInfo
name|m_dyld
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DynamicLoaderDarwin
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DynamicLoaderDarwin_h_
end_comment

end_unit

