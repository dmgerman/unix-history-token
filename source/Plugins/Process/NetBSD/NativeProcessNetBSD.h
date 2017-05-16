begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NativeProcessNetBSD.h --------------------------------- -*- C++ -*-===//
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
name|liblldb_NativeProcessNetBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_NativeProcessNetBSD_H_
end_define

begin_comment
comment|// C++ Includes
end_comment

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/MemoryRegionInfo.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"NativeThreadNetBSD.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/common/NativeProcessProtocol.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|process_netbsd
block|{
comment|/// @class NativeProcessNetBSD
comment|/// @brief Manages communication with the inferior (debugee) process.
comment|///
comment|/// Upon construction, this class prepares and launches an inferior process for
comment|/// debugging.
comment|///
comment|/// Changes in the inferior process state are broadcasted.
name|class
name|NativeProcessNetBSD
range|:
name|public
name|NativeProcessProtocol
block|{
name|friend
name|Status
name|NativeProcessProtocol
operator|::
name|Launch
argument_list|(
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|,
name|NativeDelegate
operator|&
name|native_delegate
argument_list|,
name|MainLoop
operator|&
name|mainloop
argument_list|,
name|NativeProcessProtocolSP
operator|&
name|process_sp
argument_list|)
block|;
name|friend
name|Status
name|NativeProcessProtocol
operator|::
name|Attach
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|NativeProcessProtocol::NativeDelegate&native_delegate
argument_list|,
argument|MainLoop&mainloop
argument_list|,
argument|NativeProcessProtocolSP&process_sp
argument_list|)
block|;
name|public
operator|:
comment|// ---------------------------------------------------------------------
comment|// NativeProcessProtocol Interface
comment|// ---------------------------------------------------------------------
name|Status
name|Resume
argument_list|(
argument|const ResumeActionList&resume_actions
argument_list|)
name|override
block|;
name|Status
name|Halt
argument_list|()
name|override
block|;
name|Status
name|Detach
argument_list|()
name|override
block|;
name|Status
name|Signal
argument_list|(
argument|int signo
argument_list|)
name|override
block|;
name|Status
name|Kill
argument_list|()
name|override
block|;
name|Status
name|GetMemoryRegionInfo
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|MemoryRegionInfo&range_info
argument_list|)
name|override
block|;
name|Status
name|ReadMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|size_t&bytes_read
argument_list|)
name|override
block|;
name|Status
name|ReadMemoryWithoutTrap
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|size_t&bytes_read
argument_list|)
name|override
block|;
name|Status
name|WriteMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|const void *buf
argument_list|,
argument|size_t size
argument_list|,
argument|size_t&bytes_written
argument_list|)
name|override
block|;
name|Status
name|AllocateMemory
argument_list|(
argument|size_t size
argument_list|,
argument|uint32_t permissions
argument_list|,
argument|lldb::addr_t&addr
argument_list|)
name|override
block|;
name|Status
name|DeallocateMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|)
name|override
block|;
name|lldb
operator|::
name|addr_t
name|GetSharedLibraryInfoAddress
argument_list|()
name|override
block|;
name|size_t
name|UpdateThreads
argument_list|()
name|override
block|;
name|bool
name|GetArchitecture
argument_list|(
argument|ArchSpec&arch
argument_list|)
specifier|const
name|override
block|;
name|Status
name|SetBreakpoint
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|uint32_t size
argument_list|,
argument|bool hardware
argument_list|)
name|override
block|;
name|Status
name|GetLoadedModuleFileSpec
argument_list|(
argument|const char *module_path
argument_list|,
argument|FileSpec&file_spec
argument_list|)
name|override
block|;
name|Status
name|GetFileLoadAddress
argument_list|(
argument|const llvm::StringRef&file_name
argument_list|,
argument|lldb::addr_t&load_addr
argument_list|)
name|override
block|;
name|llvm
operator|::
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>>
name|GetAuxvData
argument_list|()
specifier|const
name|override
block|;
comment|// ---------------------------------------------------------------------
comment|// Interface used by NativeRegisterContext-derived classes.
comment|// ---------------------------------------------------------------------
specifier|static
name|Status
name|PtraceWrapper
argument_list|(
argument|int req
argument_list|,
argument|lldb::pid_t pid
argument_list|,
argument|void *addr = nullptr
argument_list|,
argument|int data =
literal|0
argument_list|,
argument|int *result = nullptr
argument_list|)
block|;
name|protected
operator|:
comment|// ---------------------------------------------------------------------
comment|// NativeProcessProtocol protected interface
comment|// ---------------------------------------------------------------------
name|Status
name|GetSoftwareBreakpointTrapOpcode
argument_list|(
argument|size_t trap_opcode_size_hint
argument_list|,
argument|size_t&actual_opcode_size
argument_list|,
argument|const uint8_t *&trap_opcode_bytes
argument_list|)
name|override
block|;
name|private
operator|:
name|MainLoop
operator|::
name|SignalHandleUP
name|m_sigchld_handle
block|;
name|ArchSpec
name|m_arch
block|;
name|LazyBool
name|m_supports_mem_region
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MemoryRegionInfo
block|,
name|FileSpec
operator|>>
name|m_mem_region_cache
block|;
comment|// ---------------------------------------------------------------------
comment|// Private Instance Methods
comment|// ---------------------------------------------------------------------
name|NativeProcessNetBSD
argument_list|()
block|;
name|NativeThreadNetBSDSP
name|AddThread
argument_list|(
argument|lldb::tid_t thread_id
argument_list|)
block|;
name|Status
name|LaunchInferior
argument_list|(
name|MainLoop
operator|&
name|mainloop
argument_list|,
name|ProcessLaunchInfo
operator|&
name|launch_info
argument_list|)
block|;
name|void
name|AttachToInferior
argument_list|(
argument|MainLoop&mainloop
argument_list|,
argument|lldb::pid_t pid
argument_list|,
argument|Status&error
argument_list|)
block|;
name|void
name|MonitorCallback
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|int signal
argument_list|)
block|;
name|void
name|MonitorExited
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|int signal
argument_list|,
argument|int status
argument_list|)
block|;
name|void
name|MonitorSIGSTOP
argument_list|(
argument|lldb::pid_t pid
argument_list|)
block|;
name|void
name|MonitorSIGTRAP
argument_list|(
argument|lldb::pid_t pid
argument_list|)
block|;
name|void
name|MonitorSignal
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|int signal
argument_list|)
block|;
name|Status
name|GetSoftwareBreakpointPCOffset
argument_list|(
name|uint32_t
operator|&
name|actual_opcode_size
argument_list|)
block|;
name|Status
name|FixupBreakpointPCAsNeeded
argument_list|(
name|NativeThreadNetBSD
operator|&
name|thread
argument_list|)
block|;
name|Status
name|PopulateMemoryRegionCache
argument_list|()
block|;
name|void
name|SigchldHandler
argument_list|()
block|;
operator|::
name|pid_t
name|Attach
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|Status&error
argument_list|)
block|;
name|Status
name|ReinitializeThreads
argument_list|()
block|; }
decl_stmt|;
block|}
comment|// namespace process_netbsd
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
comment|// #ifndef liblldb_NativeProcessNetBSD_H_
end_comment

end_unit

