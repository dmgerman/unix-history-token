begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DynamicLoaderMacOSXDYLD.h -------------------------------*- C++ -*-===//
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
name|liblldb_DynamicLoaderMacOSXDYLD_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DynamicLoaderMacOSXDYLD_h_
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
file|"lldb/Target/DynamicLoader.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StructuredData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/UUID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Process.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/SafeMachO.h"
end_include

begin_decl_stmt
name|class
name|DynamicLoaderMacOSXDYLD
range|:
name|public
name|lldb_private
operator|::
name|DynamicLoader
block|{
name|public
operator|:
name|DynamicLoaderMacOSXDYLD
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
operator|~
name|DynamicLoaderMacOSXDYLD
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
name|DynamicLoader
operator|*
name|CreateInstance
argument_list|(
argument|lldb_private::Process *process
argument_list|,
argument|bool force
argument_list|)
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
name|bool
name|ProcessDidExec
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
name|lldb_private
operator|::
name|Error
name|CanLoadImage
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
name|bool
name|AlwaysRelyOnEHUnwindInfo
argument_list|(
argument|lldb_private::SymbolContext&sym_ctx
argument_list|)
name|override
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
name|bool
name|LocateDYLD
argument_list|()
block|;
name|bool
name|DidSetNotificationBreakpoint
argument_list|()
specifier|const
block|;
name|void
name|Clear
argument_list|(
argument|bool clear_process
argument_list|)
block|;
name|void
name|PutToLog
argument_list|(
argument|lldb_private::Log *log
argument_list|)
specifier|const
block|;
name|bool
name|ReadDYLDInfoFromMemoryAndSetNotificationCallback
argument_list|(
argument|lldb::addr_t addr
argument_list|)
block|;
specifier|static
name|bool
name|NotifyBreakpointHit
argument_list|(
argument|void *baton
argument_list|,
argument|lldb_private::StoppointCallbackContext *context
argument_list|,
argument|lldb::user_id_t break_id
argument_list|,
argument|lldb::user_id_t break_loc_id
argument_list|)
block|;
name|uint32_t
name|AddrByteSize
argument_list|()
block|;
specifier|static
name|lldb
operator|::
name|ByteOrder
name|GetByteOrderFromMagic
argument_list|(
argument|uint32_t magic
argument_list|)
block|;
name|bool
name|ReadMachHeader
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|llvm::MachO::mach_header *header
argument_list|,
argument|lldb_private::DataExtractor *load_command_data
argument_list|)
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
block|{         }
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
block|;      }
block|;      struct
name|DYLDImageInfo
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
comment|// The amount to slide all segments by if there is a global slide.
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
comment|// All segment vmaddr and vmsize pairs for this executable (from memory of inferior)
name|uint32_t
name|load_stop_id
block|;
comment|// The process stop ID that the sections for this image were loaded
name|DYLDImageInfo
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
block|{         }
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
block|;         }
name|bool
name|operator
operator|==
operator|(
specifier|const
name|DYLDImageInfo
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
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
block|;
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
name|DYLDImageInfo
operator|>
name|collection
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
end_typedef

begin_struct
unit|};
struct|struct
name|DYLDAllImageInfos
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|dylib_info_count
decl_stmt|;
comment|// Version>= 1
name|lldb
operator|::
name|addr_t
name|dylib_info_addr
expr_stmt|;
comment|// Version>= 1
name|lldb
operator|::
name|addr_t
name|notification
expr_stmt|;
comment|// Version>= 1
name|bool
name|processDetachedFromSharedRegion
decl_stmt|;
comment|// Version>= 1
name|bool
name|libSystemInitialized
decl_stmt|;
comment|// Version>= 2
name|lldb
operator|::
name|addr_t
name|dyldImageLoadAddress
expr_stmt|;
comment|// Version>= 2
name|DYLDAllImageInfos
argument_list|()
operator|:
name|version
argument_list|(
literal|0
argument_list|)
operator|,
name|dylib_info_count
argument_list|(
literal|0
argument_list|)
operator|,
name|dylib_info_addr
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|notification
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|processDetachedFromSharedRegion
argument_list|(
name|false
argument_list|)
operator|,
name|libSystemInitialized
argument_list|(
name|false
argument_list|)
operator|,
name|dyldImageLoadAddress
argument_list|(
argument|LLDB_INVALID_ADDRESS
argument_list|)
block|{         }
name|void
name|Clear
argument_list|()
block|{
name|version
operator|=
literal|0
block|;
name|dylib_info_count
operator|=
literal|0
block|;
name|dylib_info_addr
operator|=
name|LLDB_INVALID_ADDRESS
block|;
name|notification
operator|=
name|LLDB_INVALID_ADDRESS
block|;
name|processDetachedFromSharedRegion
operator|=
name|false
block|;
name|libSystemInitialized
operator|=
name|false
block|;
name|dyldImageLoadAddress
operator|=
name|LLDB_INVALID_ADDRESS
block|;         }
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|version
operator|>=
literal|1
operator|||
name|version
operator|<=
literal|6
return|;
block|}
block|}
struct|;
end_struct

begin_function_decl
name|void
name|RegisterNotificationCallbacks
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UnregisterNotificationCallbacks
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|uint32_t
name|ParseLoadCommands
argument_list|(
specifier|const
name|lldb_private
operator|::
name|DataExtractor
operator|&
name|data
argument_list|,
name|DYLDImageInfo
operator|&
name|dylib_info
argument_list|,
name|lldb_private
operator|::
name|FileSpec
operator|*
name|lc_id_dylinker
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|DYLDImageInfo
operator|&
name|info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|UnloadImageLoadAddress
argument_list|(
name|lldb_private
operator|::
name|Module
operator|*
name|module
argument_list|,
name|DYLDImageInfo
operator|&
name|info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ModuleSP
name|FindTargetModuleForDYLDImageInfo
argument_list|(
argument|DYLDImageInfo&image_info
argument_list|,
argument|bool can_create
argument_list|,
argument|bool *did_create_ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|DYLDImageInfo
modifier|*
name|GetImageInfo
argument_list|(
name|lldb_private
operator|::
name|Module
operator|*
name|module
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|bool
name|NeedToLocateDYLD
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|bool
name|SetNotificationBreakpoint
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// There is a little tricky bit where you might initially attach while dyld is updating
end_comment

begin_comment
comment|// the all_image_infos, and you can't read the infos, so you have to continue and pick it
end_comment

begin_comment
comment|// up when you hit the update breakpoint.  At that point, you need to run this initialize
end_comment

begin_comment
comment|// function, but when you do it that way you DON'T need to do the extra work you would at
end_comment

begin_comment
comment|// the breakpoint.
end_comment

begin_comment
comment|// So this function will only do actual work if the image infos haven't been read yet.
end_comment

begin_comment
comment|// If it does do any work, then it will return true, and false otherwise.  That way you can
end_comment

begin_comment
comment|// call it in the breakpoint action, and if it returns true you're done.
end_comment

begin_function_decl
name|bool
name|InitializeFromAllImageInfos
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ReadAllImageInfosStructure
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|AddModulesUsingInfosFromDebugserver
argument_list|(
name|lldb_private
operator|::
name|StructuredData
operator|::
name|ObjectSP
name|image_details
argument_list|,
name|DYLDImageInfo
operator|::
name|collection
operator|&
name|image_infos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|AddModulesUsingImageInfosAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|image_infos_addr
argument_list|,
name|uint32_t
name|image_infos_count
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|AddModulesUsingImageInfos
argument_list|(
name|DYLDImageInfo
operator|::
name|collection
operator|&
name|image_infos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|RemoveModulesUsingImageInfosAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|image_infos_addr
argument_list|,
name|uint32_t
name|image_infos_count
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|UpdateImageInfosHeaderAndLoadCommands
argument_list|(
name|DYLDImageInfo
operator|::
name|collection
operator|&
name|image_infos
argument_list|,
name|uint32_t
name|infos_count
argument_list|,
name|bool
name|update_executable
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|ReadImageInfos
argument_list|(
name|lldb
operator|::
name|addr_t
name|image_infos_addr
argument_list|,
name|uint32_t
name|image_infos_count
argument_list|,
name|DYLDImageInfo
operator|::
name|collection
operator|&
name|image_infos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DYLDImageInfo
name|m_dyld
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Info about the current dyld being used
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ModuleWP
name|m_dyld_module_wp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|m_dyld_all_image_infos_addr
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|DYLDAllImageInfos
name|m_dyld_all_image_infos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_dyld_all_image_infos_stop_id
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|user_id_t
name|m_break_id
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DYLDImageInfo
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
comment|// The process stop ID that "m_dyld_image_infos" is valid for
end_comment

begin_expr_stmt
name|mutable
name|lldb_private
operator|::
name|Mutex
name|m_mutex
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Process
operator|::
name|Notifications
name|m_notification_callbacks
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|m_process_image_addr_is_all_images_infos
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DynamicLoaderMacOSXDYLD
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DynamicLoaderMacOSXDYLD_h_
end_comment

end_unit

