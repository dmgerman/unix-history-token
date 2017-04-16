begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ProcessElfCore.h ----------------------------------------*- C++ -*-===//
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
comment|// Notes about Linux Process core dumps:
end_comment

begin_comment
comment|//  1) Linux core dump is stored as ELF file.
end_comment

begin_comment
comment|//  2) The ELF file's PT_NOTE and PT_LOAD segments describes the program's
end_comment

begin_comment
comment|//     address space and thread contexts.
end_comment

begin_comment
comment|//  3) PT_NOTE segment contains note entries which describes a thread context.
end_comment

begin_comment
comment|//  4) PT_LOAD segment describes a valid contiguous range of process address
end_comment

begin_comment
comment|//     space.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_ProcessElfCore_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ProcessElfCore_h_
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
file|<list>
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
file|"lldb/Target/Process.h"
end_include

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

begin_include
include|#
directive|include
file|"Plugins/ObjectFile/ELF/ELFHeader.h"
end_include

begin_struct_decl
struct_decl|struct
name|ThreadData
struct_decl|;
end_struct_decl

begin_decl_stmt
name|class
name|ProcessElfCore
range|:
name|public
name|lldb_private
operator|::
name|Process
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
specifier|static
name|lldb
operator|::
name|ProcessSP
name|CreateInstance
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener_sp
argument_list|,
argument|const lldb_private::FileSpec *crash_file_path
argument_list|)
block|;
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
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|ProcessElfCore
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|lldb::ListenerSP listener_sp
argument_list|,
argument|const lldb_private::FileSpec&core_file
argument_list|)
block|;
operator|~
name|ProcessElfCore
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Check if a given Process
comment|//------------------------------------------------------------------
name|bool
name|CanDebug
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|,
argument|bool plugin_specified_by_name
argument_list|)
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Creating a new process, or attaching to an existing one
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|Error
name|DoLoadCore
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|DynamicLoader
operator|*
name|GetDynamicLoader
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
comment|//------------------------------------------------------------------
comment|// Process Control
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|Error
name|DoDestroy
argument_list|()
name|override
block|;
name|void
name|RefreshStateAfterStop
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Process Queries
comment|//------------------------------------------------------------------
name|bool
name|IsAlive
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// Process Memory
comment|//------------------------------------------------------------------
name|size_t
name|ReadMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|size_t
name|DoReadMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|lldb_private::Error&error
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|lldb_private::MemoryRegionInfo&region_info
argument_list|)
name|override
block|;
name|lldb
operator|::
name|addr_t
name|GetImageInfoAddress
argument_list|()
name|override
block|;
name|lldb_private
operator|::
name|ArchSpec
name|GetArchitecture
argument_list|()
block|;
comment|// Returns AUXV structure found in the core file
specifier|const
name|lldb
operator|::
name|DataBufferSP
name|GetAuxvData
argument_list|()
name|override
block|;
name|bool
name|GetProcessInfo
argument_list|(
argument|lldb_private::ProcessInstanceInfo&info
argument_list|)
name|override
block|;
name|protected
operator|:
name|void
name|Clear
argument_list|()
block|;
name|bool
name|UpdateThreadList
argument_list|(
argument|lldb_private::ThreadList&old_thread_list
argument_list|,
argument|lldb_private::ThreadList&new_thread_list
argument_list|)
name|override
block|;
name|private
operator|:
expr|struct
name|NT_FILE_Entry
block|{
name|lldb
operator|::
name|addr_t
name|start
block|;
name|lldb
operator|::
name|addr_t
name|end
block|;
name|lldb
operator|::
name|addr_t
name|file_ofs
block|;
name|lldb_private
operator|::
name|ConstString
name|path
block|;   }
block|;
comment|//------------------------------------------------------------------
comment|// For ProcessElfCore only
comment|//------------------------------------------------------------------
typedef|typedef
name|lldb_private
operator|::
name|Range
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|>
name|FileRange
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|lldb_private
operator|::
name|RangeDataArray
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|,
name|FileRange
operator|,
literal|1
operator|>
name|VMRangeToFileOffset
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|lldb_private
operator|::
name|RangeDataVector
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|lldb
operator|::
name|addr_t
operator|,
name|uint32_t
operator|>
name|VMRangeToPermissions
expr_stmt|;
end_typedef

begin_expr_stmt
name|lldb
operator|::
name|ModuleSP
name|m_core_module_sp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|FileSpec
name|m_core_file
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_dyld_plugin_name
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ProcessElfCore
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|llvm
operator|::
name|Triple
operator|::
name|OSType
name|m_os
expr_stmt|;
end_expr_stmt

begin_comment
comment|// True if m_thread_contexts contains valid entries
end_comment

begin_decl_stmt
name|bool
name|m_thread_data_valid
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Contain thread data read from NOTE segments
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|ThreadData
operator|>
name|m_thread_data
expr_stmt|;
end_expr_stmt

begin_comment
comment|// AUXV structure found from the NOTE segment
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|DataExtractor
name|m_auxv
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Address ranges found in the core
end_comment

begin_decl_stmt
name|VMRangeToFileOffset
name|m_core_aranges
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Permissions for all ranges
end_comment

begin_decl_stmt
name|VMRangeToPermissions
name|m_core_range_infos
decl_stmt|;
end_decl_stmt

begin_comment
comment|// NT_FILE entries found from the NOTE segment
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|NT_FILE_Entry
operator|>
name|m_nt_file_entries
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Parse thread(s) data structures(prstatus, prpsinfo) from given NOTE segment
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|Error
name|ParseThreadContextsFromNoteSegment
argument_list|(
argument|const elf::ELFProgramHeader *segment_header
argument_list|,
argument|lldb_private::DataExtractor segment_data
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Returns number of thread contexts stored in the core file
end_comment

begin_function_decl
name|uint32_t
name|GetNumThreadContexts
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Parse a contiguous address range of the process from LOAD segment
end_comment

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|AddAddressRangeFromLoadSegment
argument_list|(
specifier|const
name|elf
operator|::
name|ELFProgramHeader
operator|*
name|header
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ProcessElfCore_h_
end_comment

end_unit

