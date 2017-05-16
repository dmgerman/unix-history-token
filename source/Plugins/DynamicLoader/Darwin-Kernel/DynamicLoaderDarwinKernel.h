begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DynamicLoaderDarwinKernel.h -----------------------------*- C++ -*-===//
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
name|liblldb_DynamicLoaderDarwinKernel_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DynamicLoaderDarwinKernel_h_
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
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<string>
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
file|"lldb/Utility/UUID.h"
end_include

begin_decl_stmt
name|class
name|DynamicLoaderDarwinKernel
range|:
name|public
name|lldb_private
operator|::
name|DynamicLoader
block|{
name|public
operator|:
name|DynamicLoaderDarwinKernel
argument_list|(
argument|lldb_private::Process *process
argument_list|,
argument|lldb::addr_t kernel_addr
argument_list|)
block|;
operator|~
name|DynamicLoaderDarwinKernel
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
specifier|static
name|void
name|DebuggerInitialize
argument_list|(
name|lldb_private
operator|::
name|Debugger
operator|&
name|debugger
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|addr_t
name|SearchForDarwinKernel
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
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
name|lldb_private
operator|::
name|Status
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
name|UpdateIfNeeded
argument_list|()
block|;
name|void
name|LoadKernelModuleIfNeeded
argument_list|()
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
specifier|static
name|bool
name|BreakpointHitCallback
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
name|bool
name|BreakpointHit
argument_list|(
argument|lldb_private::StoppointCallbackContext *context
argument_list|,
argument|lldb::user_id_t break_id
argument_list|,
argument|lldb::user_id_t break_loc_id
argument_list|)
block|;
name|uint32_t
name|GetAddrByteSize
argument_list|()
block|{
return|return
name|m_kernel
operator|.
name|GetAddressByteSize
argument_list|()
return|;
block|}
specifier|static
name|lldb
operator|::
name|ByteOrder
name|GetByteOrderFromMagic
argument_list|(
argument|uint32_t magic
argument_list|)
block|;    enum
block|{
name|KERNEL_MODULE_MAX_NAME
operator|=
literal|64u
block|,
comment|// Versions less than 2 didn't have an entry size,
comment|// they had a 64 bit name, 16 byte UUID, 8 byte addr,
comment|// 8 byte size, 8 byte version, 4 byte load tag, and
comment|// 4 byte flags
name|KERNEL_MODULE_ENTRY_SIZE_VERSION_1
operator|=
literal|64u
operator|+
literal|16u
operator|+
literal|8u
operator|+
literal|8u
operator|+
literal|8u
operator|+
literal|4u
operator|+
literal|4u
block|}
block|;
comment|// class KextImageInfo represents a single kext or kernel binary image.
comment|// The class was designed to hold the information from the
comment|// OSKextLoadedKextSummary
comment|// structure (in libkern/libkern/OSKextLibPrivate.h from xnu).  The kernel
comment|// maintains
comment|// a list of loded kexts in memory (the OSKextLoadedKextSummaryHeader
comment|// structure,
comment|// which points to an array of OSKextLoadedKextSummary's).
comment|//
comment|// A KextImageInfos may have -
comment|//
comment|// 1. The load address, name, UUID, and size of a kext/kernel binary in memory
comment|//    (read straight out of the kernel's list-of-kexts loaded)
comment|// 2. A ModuleSP based on a MemoryModule read out of the kernel's memory
comment|//    (very unlikely to have any symbolic information)
comment|// 3. A ModuleSP for an on-disk copy of the kext binary, possibly with debug
comment|// info
comment|//    or a dSYM
comment|//
comment|// For performance reasons, the developer may prefer that lldb not load the
comment|// kexts out
comment|// of memory at the start of a kernel session.  But we should build up /
comment|// maintain a
comment|// list of kexts that the kernel has told us about so we can relocate a kext
comment|// module
comment|// later if the user explicitly adds it to the target.
name|class
name|KextImageInfo
block|{
name|public
operator|:
name|KextImageInfo
argument_list|()
operator|:
name|m_name
argument_list|()
block|,
name|m_module_sp
argument_list|()
block|,
name|m_memory_module_sp
argument_list|()
block|,
name|m_load_process_stop_id
argument_list|(
name|UINT32_MAX
argument_list|)
block|,
name|m_uuid
argument_list|()
block|,
name|m_load_address
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
block|,
name|m_size
argument_list|(
literal|0
argument_list|)
block|,
name|m_kernel_image
argument_list|(
argument|false
argument_list|)
block|{}
name|void
name|Clear
argument_list|()
block|{
name|m_load_address
operator|=
name|LLDB_INVALID_ADDRESS
block|;
name|m_size
operator|=
literal|0
block|;
name|m_name
operator|.
name|clear
argument_list|()
block|;
name|m_uuid
operator|.
name|Clear
argument_list|()
block|;
name|m_module_sp
operator|.
name|reset
argument_list|()
block|;
name|m_memory_module_sp
operator|.
name|reset
argument_list|()
block|;
name|m_load_process_stop_id
operator|=
name|UINT32_MAX
block|;     }
name|bool
name|LoadImageAtFileAddress
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
name|bool
name|LoadImageUsingMemoryModule
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
name|bool
name|IsLoaded
argument_list|()
block|{
return|return
name|m_load_process_stop_id
operator|!=
name|UINT32_MAX
return|;
block|}
name|void
name|SetLoadAddress
argument_list|(
argument|lldb::addr_t load_addr
argument_list|)
block|;
comment|// Address of the Mach-O header for this binary
name|lldb
operator|::
name|addr_t
name|GetLoadAddress
argument_list|()
specifier|const
block|;
comment|// Address of the Mach-O header for this binary
name|lldb_private
operator|::
name|UUID
name|GetUUID
argument_list|()
specifier|const
block|;
name|void
name|SetUUID
argument_list|(
specifier|const
name|lldb_private
operator|::
name|UUID
operator|&
name|uuid
argument_list|)
block|;
name|void
name|SetName
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
block|;
name|std
operator|::
name|string
name|GetName
argument_list|()
specifier|const
block|;
name|void
name|SetModule
argument_list|(
argument|lldb::ModuleSP module
argument_list|)
block|;
name|lldb
operator|::
name|ModuleSP
name|GetModule
argument_list|()
block|;
comment|// try to fill in m_memory_module_sp from memory based on the m_load_address
name|bool
name|ReadMemoryModule
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
name|bool
name|IsKernel
argument_list|()
specifier|const
block|;
comment|// true if this is the mach_kernel; false if this is a kext
name|void
name|SetIsKernel
argument_list|(
argument|bool is_kernel
argument_list|)
block|;
name|uint64_t
name|GetSize
argument_list|()
specifier|const
block|;
name|void
name|SetSize
argument_list|(
argument|uint64_t size
argument_list|)
block|;
name|uint32_t
name|GetProcessStopId
argument_list|()
specifier|const
block|;
comment|// the stop-id when this binary was first noticed
name|void
name|SetProcessStopId
argument_list|(
argument|uint32_t stop_id
argument_list|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|KextImageInfo
operator|&
name|rhs
operator|)
block|;
name|uint32_t
name|GetAddressByteSize
argument_list|()
block|;
comment|// as determined by Mach-O header
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
block|;
comment|// as determined by Mach-O header
name|lldb_private
operator|::
name|ArchSpec
name|GetArchitecture
argument_list|()
specifier|const
block|;
comment|// as determined by Mach-O header
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
name|KextImageInfo
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|string
name|m_name
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|ModuleSP
name|m_module_sp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|ModuleSP
name|m_memory_module_sp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint32_t
name|m_load_process_stop_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|// the stop-id when this module was added
end_comment

begin_comment
comment|// to the Target
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|UUID
name|m_uuid
expr_stmt|;
end_expr_stmt

begin_comment
comment|// UUID for this dylib if it has one, else all zeros
end_comment

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|m_load_address
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint64_t
name|m_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_kernel_image
decl_stmt|;
end_decl_stmt

begin_comment
comment|// true if this is the kernel, false if this is a kext
end_comment

begin_struct
unit|};
struct|struct
name|OSKextLoadedKextSummaryHeader
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|entry_size
decl_stmt|;
name|uint32_t
name|entry_count
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|image_infos_addr
expr_stmt|;
name|OSKextLoadedKextSummaryHeader
argument_list|()
operator|:
name|version
argument_list|(
literal|0
argument_list|)
operator|,
name|entry_size
argument_list|(
literal|0
argument_list|)
operator|,
name|entry_count
argument_list|(
literal|0
argument_list|)
operator|,
name|image_infos_addr
argument_list|(
argument|LLDB_INVALID_ADDRESS
argument_list|)
block|{}
name|uint32_t
name|GetSize
argument_list|()
block|{
switch|switch
condition|(
name|version
condition|)
block|{
case|case
literal|0
case|:
return|return
literal|0
return|;
comment|// Can't know the size without a valid version
case|case
literal|1
case|:
return|return
literal|8
return|;
comment|// Version 1 only had a version + entry_count
default|default:
break|break;
block|}
comment|// Version 2 and above has version, entry_size, entry_count, and reserved
return|return
literal|16
return|;
block|}
name|void
name|Clear
argument_list|()
block|{
name|version
operator|=
literal|0
expr_stmt|;
name|entry_size
operator|=
literal|0
expr_stmt|;
name|entry_count
operator|=
literal|0
expr_stmt|;
name|image_infos_addr
operator|=
name|LLDB_INVALID_ADDRESS
expr_stmt|;
block|}
name|bool
name|IsValid
argument_list|()
decl|const
block|{
return|return
name|version
operator|>=
literal|1
operator|||
name|version
operator|<=
literal|2
return|;
block|}
end_struct

begin_function_decl
unit|};
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

begin_function_decl
name|void
name|SetNotificationBreakpointIfNeeded
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ReadAllKextSummaries
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|ReadKextSummaryHeader
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|ParseKextSummaries
argument_list|(
specifier|const
name|lldb_private
operator|::
name|Address
operator|&
name|kext_summary_addr
argument_list|,
name|uint32_t
name|count
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|UpdateImageInfosHeaderAndLoadCommands
argument_list|(
name|KextImageInfo
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
name|uint32_t
name|ReadKextSummaries
argument_list|(
specifier|const
name|lldb_private
operator|::
name|Address
operator|&
name|kext_summary_addr
argument_list|,
name|uint32_t
name|image_infos_count
argument_list|,
name|KextImageInfo
operator|::
name|collection
operator|&
name|image_infos
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|addr_t
name|SearchForKernelAtSameLoadAddr
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|addr_t
name|SearchForKernelWithDebugHints
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|addr_t
name|SearchForKernelNearPC
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|addr_t
name|SearchForKernelViaExhaustiveSearch
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|lldb_private
operator|::
name|UUID
name|CheckForKernelImageAtAddress
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|lldb_private::Process *process
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|m_kernel_load_address
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|KextImageInfo
name|m_kernel
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Info about the current kernel image being used
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|Address
name|m_kext_summary_header_ptr_addr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Address
name|m_kext_summary_header_addr
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|OSKextLoadedKextSummaryHeader
name|m_kext_summary_header
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|KextImageInfo
operator|::
name|collection
name|m_known_kexts
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_mutex
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|user_id_t
name|m_break_id
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DynamicLoaderDarwinKernel
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DynamicLoaderDarwinKernel_h_
end_comment

end_unit

