begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Greg Clayton on 12/12/07.
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
name|__RNBRemote_h__
end_ifndef

begin_define
define|#
directive|define
name|__RNBRemote_h__
end_define

begin_include
include|#
directive|include
file|"DNB.h"
end_include

begin_include
include|#
directive|include
file|"PThreadMutex.h"
end_include

begin_include
include|#
directive|include
file|"RNBContext.h"
end_include

begin_include
include|#
directive|include
file|"RNBDefs.h"
end_include

begin_include
include|#
directive|include
file|"RNBSocket.h"
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_include
include|#
directive|include
file|<map>
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

begin_decl_stmt
name|class
name|RNBSocket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|RNBContext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|PThreadEvents
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|event_loop_mode
block|{
name|debug_nub
block|,
name|gdb_remote_protocol
block|,
name|done
block|}
enum|;
end_enum

begin_decl_stmt
name|enum
name|class
name|compression_types
block|{
name|zlib_deflate
operator|,
name|lz4
operator|,
name|lzma
operator|,
name|lzfse
operator|,
name|none
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|RNBRemote
block|{
name|public
label|:
typedef|typedef
enum|enum
block|{
name|invalid_packet
init|=
literal|0
block|,
name|ack
block|,
comment|// '+'
name|nack
block|,
comment|// '-'
name|halt
block|,
comment|// ^C  (async halt)
name|use_extended_mode
block|,
comment|// '!'
name|why_halted
block|,
comment|// '?'
name|set_argv
block|,
comment|// 'A'
name|set_bp
block|,
comment|// 'B'
name|cont
block|,
comment|// 'c'
name|continue_with_sig
block|,
comment|// 'C'
name|detach
block|,
comment|// 'D'
name|read_general_regs
block|,
comment|// 'g'
name|write_general_regs
block|,
comment|// 'G'
name|set_thread
block|,
comment|// 'H'
name|step_inferior_one_cycle
block|,
comment|// 'i'
name|signal_and_step_inf_one_cycle
block|,
comment|// 'I'
name|kill
block|,
comment|// 'k'
name|read_memory
block|,
comment|// 'm'
name|write_memory
block|,
comment|// 'M'
name|read_register
block|,
comment|// 'p'
name|write_register
block|,
comment|// 'P'
name|restart
block|,
comment|// 'R'
name|single_step
block|,
comment|// 's'
name|single_step_with_sig
block|,
comment|// 'S'
name|search_mem_backwards
block|,
comment|// 't'
name|thread_alive_p
block|,
comment|// 'T'
name|vattach
block|,
comment|// 'vAttach;pid'
name|vattachwait
block|,
comment|// 'vAttachWait:XX...' where XX is one or more hex encoded
comment|// process name ASCII bytes
name|vattachorwait
block|,
comment|// 'vAttachOrWait:XX...' where XX is one or more hex encoded
comment|// process name ASCII bytes
name|vattachname
block|,
comment|// 'vAttachName:XX...' where XX is one or more hex encoded
comment|// process name ASCII bytes
name|vcont
block|,
comment|// 'vCont'
name|vcont_list_actions
block|,
comment|// 'vCont?'
name|read_data_from_memory
block|,
comment|// 'x'
name|write_data_to_memory
block|,
comment|// 'X'
name|insert_mem_bp
block|,
comment|// 'Z0'
name|remove_mem_bp
block|,
comment|// 'z0'
name|insert_hardware_bp
block|,
comment|// 'Z1'
name|remove_hardware_bp
block|,
comment|// 'z1'
name|insert_write_watch_bp
block|,
comment|// 'Z2'
name|remove_write_watch_bp
block|,
comment|// 'z2'
name|insert_read_watch_bp
block|,
comment|// 'Z3'
name|remove_read_watch_bp
block|,
comment|// 'z3'
name|insert_access_watch_bp
block|,
comment|// 'Z4'
name|remove_access_watch_bp
block|,
comment|// 'z4'
name|query_monitor
block|,
comment|// 'qRcmd'
name|query_current_thread_id
block|,
comment|// 'qC'
name|query_get_pid
block|,
comment|// 'qGetPid'
name|query_echo
block|,
comment|// 'qEcho'
name|query_thread_ids_first
block|,
comment|// 'qfThreadInfo'
name|query_thread_ids_subsequent
block|,
comment|// 'qsThreadInfo'
name|query_thread_extra_info
block|,
comment|// 'qThreadExtraInfo'
name|query_thread_stop_info
block|,
comment|// 'qThreadStopInfo'
name|query_image_offsets
block|,
comment|// 'qOffsets'
name|query_symbol_lookup
block|,
comment|// 'qSymbol'
name|query_launch_success
block|,
comment|// 'qLaunchSuccess'
name|query_register_info
block|,
comment|// 'qRegisterInfo'
name|query_shlib_notify_info_addr
block|,
comment|// 'qShlibInfoAddr'
name|query_step_packet_supported
block|,
comment|// 'qStepPacketSupported'
name|query_supported_features
block|,
comment|// 'qSupported'
name|query_vattachorwait_supported
block|,
comment|// 'qVAttachOrWaitSupported'
name|query_sync_thread_state_supported
block|,
comment|// 'QSyncThreadState'
name|query_host_info
block|,
comment|// 'qHostInfo'
name|query_gdb_server_version
block|,
comment|// 'qGDBServerVersion'
name|query_process_info
block|,
comment|// 'qProcessInfo'
name|json_query_thread_extended_info
block|,
comment|// 'jThreadExtendedInfo'
name|json_query_get_loaded_dynamic_libraries_infos
block|,
comment|// 'jGetLoadedDynamicLibrariesInfos'
name|json_query_threads_info
block|,
comment|// 'jThreadsInfo'
name|json_query_get_shared_cache_info
block|,
comment|// 'jGetSharedCacheInfo'
name|pass_signals_to_inferior
block|,
comment|// 'QPassSignals'
name|start_noack_mode
block|,
comment|// 'QStartNoAckMode'
name|prefix_reg_packets_with_tid
block|,
comment|// 'QPrefixRegisterPacketsWithThreadID
name|set_logging_mode
block|,
comment|// 'QSetLogging:'
name|set_max_packet_size
block|,
comment|// 'QSetMaxPacketSize:'
name|set_max_payload_size
block|,
comment|// 'QSetMaxPayloadSize:'
name|set_environment_variable
block|,
comment|// 'QEnvironment:'
name|set_environment_variable_hex
block|,
comment|// 'QEnvironmentHexEncoded:'
name|set_launch_arch
block|,
comment|// 'QLaunchArch:'
name|set_disable_aslr
block|,
comment|// 'QSetDisableASLR:'
name|set_stdin
block|,
comment|// 'QSetSTDIN:'
name|set_stdout
block|,
comment|// 'QSetSTDOUT:'
name|set_stderr
block|,
comment|// 'QSetSTDERR:'
name|set_working_dir
block|,
comment|// 'QSetWorkingDir:'
name|set_list_threads_in_stop_reply
block|,
comment|// 'QListThreadsInStopReply:'
name|sync_thread_state
block|,
comment|// 'QSyncThreadState:'
name|memory_region_info
block|,
comment|// 'qMemoryRegionInfo:'
name|get_profile_data
block|,
comment|// 'qGetProfileData'
name|set_enable_profiling
block|,
comment|// 'QSetEnableAsyncProfiling'
name|enable_compression
block|,
comment|// 'QEnableCompression:'
name|watchpoint_support_info
block|,
comment|// 'qWatchpointSupportInfo:'
name|allocate_memory
block|,
comment|// '_M'
name|deallocate_memory
block|,
comment|// '_m'
name|set_process_event
block|,
comment|// 'QSetProcessEvent:'
name|save_register_state
block|,
comment|// '_g'
name|restore_register_state
block|,
comment|// '_G'
name|speed_test
block|,
comment|// 'qSpeedTest:'
name|set_detach_on_error
block|,
comment|// 'QSetDetachOnError:'
name|query_transfer
block|,
comment|// 'qXfer:'
name|query_supported_async_json_packets
block|,
comment|// 'QSupportedAsyncJSONPackets'
name|configure_darwin_log
block|,
comment|// 'ConfigureDarwinLog:'
name|unknown_type
block|}
name|PacketEnum
typedef|;
typedef|typedef
name|rnb_err_t
argument_list|(
name|RNBRemote
operator|::
operator|*
name|HandlePacketCallback
argument_list|)
argument_list|(
specifier|const
name|char
operator|*
name|p
argument_list|)
expr_stmt|;
name|RNBRemote
argument_list|()
expr_stmt|;
operator|~
name|RNBRemote
argument_list|()
expr_stmt|;
name|void
name|Initialize
parameter_list|()
function_decl|;
name|bool
name|InitializeRegisters
parameter_list|(
name|bool
name|force
init|=
name|false
parameter_list|)
function_decl|;
name|rnb_err_t
name|HandleAsyncPacket
parameter_list|(
name|PacketEnum
modifier|*
name|type
init|=
name|NULL
parameter_list|)
function_decl|;
name|rnb_err_t
name|HandleReceivedPacket
parameter_list|(
name|PacketEnum
modifier|*
name|type
init|=
name|NULL
parameter_list|)
function_decl|;
name|nub_thread_t
name|GetContinueThread
argument_list|()
specifier|const
block|{
return|return
name|m_continue_thread
return|;
block|}
name|void
name|SetContinueThread
parameter_list|(
name|nub_thread_t
name|tid
parameter_list|)
block|{
name|m_continue_thread
operator|=
name|tid
expr_stmt|;
block|}
name|nub_thread_t
name|GetCurrentThread
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_thread
operator|==
literal|0
operator|||
name|m_thread
operator|==
operator|(
name|nub_thread_t
operator|)
operator|-
literal|1
condition|)
return|return
name|DNBProcessGetCurrentThread
argument_list|(
name|m_ctx
operator|.
name|ProcessID
argument_list|()
argument_list|)
return|;
return|return
name|m_thread
return|;
block|}
end_decl_stmt

begin_function
name|void
name|SetCurrentThread
parameter_list|(
name|nub_thread_t
name|tid
parameter_list|)
block|{
name|DNBProcessSetCurrentThread
argument_list|(
name|m_ctx
operator|.
name|ProcessID
argument_list|()
argument_list|,
name|tid
argument_list|)
expr_stmt|;
name|m_thread
operator|=
name|tid
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|static
name|void
modifier|*
name|ThreadFunctionReadRemoteData
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|StartReadRemoteDataThread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|StopReadRemoteDataThread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|NotifyThatProcessStopped
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_A
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_H
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qC
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qRcmd
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qGetPid
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qEcho
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qLaunchSuccess
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qRegisterInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qShlibInfoAddr
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qStepPacketSupported
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qVAttachOrWaitSupported
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qSyncThreadStateSupported
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qThreadInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_jThreadExtendedInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_jGetLoadedDynamicLibrariesInfos
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_jThreadsInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_jGetSharedCacheInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qThreadExtraInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qThreadStopInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qHostInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qGDBServerVersion
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qProcessInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qSymbol
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QStartNoAckMode
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QThreadSuffixSupported
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QSetLogging
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QSetDisableASLR
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QSetSTDIO
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QSetWorkingDir
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QSetMaxPayloadSize
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QSetMaxPacketSize
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QEnvironment
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QEnvironmentHexEncoded
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QLaunchArch
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QListThreadsInStopReply
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QSyncThreadState
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QPrefixRegisterPacketsWithThreadID
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QSetProcessEvent
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_last_signal
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_m
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_M
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_x
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_X
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_g
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_G
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_z
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_T
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_p
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_P
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_c
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_C
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_D
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_k
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_s
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_S
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qSupported
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_v
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_UNIMPLEMENTED
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_ILLFORMED
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|p
parameter_list|,
specifier|const
name|char
modifier|*
name|description
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_AllocateMemory
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_DeallocateMemory
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_SaveRegisterState
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_RestoreRegisterState
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_MemoryRegionInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_GetProfileData
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_SetEnableAsyncProfiling
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QEnableCompression
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_WatchpointSupportInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qSpeedTest
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qXfer
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_stop_process
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QSetDetachOnError
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_qStructuredDataPlugins
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|HandlePacket_QConfigureDarwinLog
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|SendStopReplyPacketForThread
parameter_list|(
name|nub_thread_t
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|SendHexEncodedBytePacket
parameter_list|(
specifier|const
name|char
modifier|*
name|header
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_len
parameter_list|,
specifier|const
name|char
modifier|*
name|footer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|SendSTDOUTPacket
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|nub_size_t
name|buf_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|SendSTDERRPacket
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|nub_size_t
name|buf_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FlushSTDIO
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SendAsyncProfileData
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|rnb_err_t
name|SendAsyncProfileDataPacket
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|,
name|nub_size_t
name|buf_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SendAsyncDarwinLogData
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|rnb_err_t
name|SendAsyncJSONPacket
argument_list|(
specifier|const
name|JSONGenerator
operator|::
name|Dictionary
operator|&
name|dictionary
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|RNBContext
modifier|&
name|Context
parameter_list|()
block|{
return|return
name|m_ctx
return|;
block|}
end_function

begin_function
name|RNBSocket
modifier|&
name|Comm
parameter_list|()
block|{
return|return
name|m_comm
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_comment
comment|// Outlaw some constructors
end_comment

begin_expr_stmt
name|RNBRemote
argument_list|(
specifier|const
name|RNBRemote
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_function_decl
name|rnb_err_t
name|GetCommData
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|CommDataReceived
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|data
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|Packet
block|{
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Packet
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
name|PacketEnum
name|type
decl_stmt|;
name|HandlePacketCallback
name|normal
decl_stmt|;
comment|// Function to call when inferior is halted
name|HandlePacketCallback
name|async
decl_stmt|;
comment|// Function to call when inferior is running
name|std
operator|::
name|string
name|abbrev
expr_stmt|;
name|std
operator|::
name|string
name|printable_name
expr_stmt|;
name|bool
name|IsPlatformPacket
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|set_logging_mode
case|:
case|case
name|query_host_info
case|:
return|return
name|true
return|;
default|default:
break|break;
block|}
return|return
name|false
return|;
block|}
name|Packet
argument_list|()
range|:
name|type
argument_list|(
name|invalid_packet
argument_list|)
struct|,
name|normal
argument_list|(
name|NULL
argument_list|)
struct|,
name|async
argument_list|(
name|NULL
argument_list|)
struct|,
name|abbrev
argument_list|()
struct|,
name|printable_name
argument_list|()
block|{}
name|Packet
argument_list|(
name|PacketEnum
name|in_type
argument_list|,
name|HandlePacketCallback
name|in_normal
argument_list|,
name|HandlePacketCallback
name|in_async
argument_list|,
specifier|const
name|char
operator|*
name|in_abbrev
argument_list|,
specifier|const
name|char
operator|*
name|in_printable_name
argument_list|)
range|:
name|type
argument_list|(
name|in_type
argument_list|)
struct|,
name|normal
argument_list|(
name|in_normal
argument_list|)
struct|,
name|async
argument_list|(
name|in_async
argument_list|)
struct|,
name|abbrev
argument_list|(
name|in_abbrev
argument_list|)
struct|,
name|printable_name
argument_list|(
name|in_printable_name
argument_list|)
block|{}
end_struct

begin_struct
unit|};
struct|struct
name|DispatchQueueOffsets
block|{
name|uint16_t
name|dqo_version
decl_stmt|;
name|uint16_t
name|dqo_label
decl_stmt|;
name|uint16_t
name|dqo_label_size
decl_stmt|;
name|uint16_t
name|dqo_flags
decl_stmt|;
name|uint16_t
name|dqo_flags_size
decl_stmt|;
name|uint16_t
name|dqo_serialnum
decl_stmt|;
name|uint16_t
name|dqo_serialnum_size
decl_stmt|;
name|uint16_t
name|dqo_width
decl_stmt|;
name|uint16_t
name|dqo_width_size
decl_stmt|;
name|uint16_t
name|dqo_running
decl_stmt|;
name|uint16_t
name|dqo_running_size
decl_stmt|;
name|uint16_t
name|dqo_suspend_cnt
decl_stmt|;
comment|// version 5 and later, starting with Mac OS X
comment|// 10.10/iOS 8
name|uint16_t
name|dqo_suspend_cnt_size
decl_stmt|;
comment|// version 5 and later, starting with Mac OS
comment|// X 10.10/iOS 8
name|uint16_t
name|dqo_target_queue
decl_stmt|;
comment|// version 5 and later, starting with Mac OS X
comment|// 10.10/iOS 8
name|uint16_t
name|dqo_target_queue_size
decl_stmt|;
comment|// version 5 and later, starting with Mac OS
comment|// X 10.10/iOS 8
name|uint16_t
name|dqo_priority
decl_stmt|;
comment|// version 5 and later, starting with Mac OS X 10.10/iOS 8
name|uint16_t
name|dqo_priority_size
decl_stmt|;
comment|// version 5 and later, starting with Mac OS X
comment|// 10.10/iOS 8
name|DispatchQueueOffsets
argument_list|()
block|{
name|Clear
argument_list|()
expr_stmt|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|dqo_version
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_label
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_label_size
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_flags
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_flags_size
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_serialnum
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_serialnum_size
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_width
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_width_size
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_running
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_running_size
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_suspend_cnt
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_suspend_cnt_size
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_target_queue
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_target_queue_size
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_priority
operator|=
name|UINT16_MAX
expr_stmt|;
name|dqo_priority_size
operator|=
name|UINT16_MAX
expr_stmt|;
block|}
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|dqo_version
operator|!=
name|UINT16_MAX
return|;
block|}
name|void
name|GetThreadQueueInfo
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_addr_t
name|dispatch_qaddr
argument_list|,
name|nub_addr_t
operator|&
name|dispatch_queue_t
argument_list|,
name|std
operator|::
name|string
operator|&
name|queue_name
argument_list|,
name|uint64_t
operator|&
name|queue_width
argument_list|,
name|uint64_t
operator|&
name|queue_serialnum
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|rnb_err_t
name|GetPacket
argument_list|(
name|std
operator|::
name|string
operator|&
name|packet_data
argument_list|,
name|RNBRemote
operator|::
name|Packet
operator|&
name|packet_info
argument_list|,
name|bool
name|wait
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rnb_err_t
name|SendPacket
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|CompressString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|CreatePacketTable
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|rnb_err_t
name|GetPacketPayload
argument_list|(
name|std
operator|::
name|string
operator|&
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|nub_thread_t
name|ExtractThreadIDFromThreadSuffix
parameter_list|(
specifier|const
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EnableCompressionNextSendPacket
parameter_list|(
name|compression_types
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|compression_types
name|GetCompressionType
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|DispatchQueueOffsets
modifier|*
name|GetDispatchQueueOffsets
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|JSONGenerator
operator|::
name|ObjectSP
name|GetJSONThreadsInfo
argument_list|(
argument|bool threads_with_valid_stop_info_only
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|RNBContext
name|m_ctx
decl_stmt|;
end_decl_stmt

begin_comment
comment|// process context
end_comment

begin_decl_stmt
name|RNBSocket
name|m_comm
decl_stmt|;
end_decl_stmt

begin_comment
comment|// communication port
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|m_arch
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|nub_thread_t
name|m_continue_thread
decl_stmt|;
end_decl_stmt

begin_comment
comment|// thread to continue; 0 for any, -1 for all
end_comment

begin_decl_stmt
name|nub_thread_t
name|m_thread
decl_stmt|;
end_decl_stmt

begin_comment
comment|// thread for other ops; 0 for any, -1 for all
end_comment

begin_decl_stmt
name|PThreadMutex
name|m_mutex
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Mutex that protects
end_comment

begin_decl_stmt
name|DispatchQueueOffsets
name|m_dispatch_queue_offsets
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_addr_t
name|m_dispatch_queue_offsets_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_qSymbol_index
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_packets_recvd
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Packet
operator|::
name|collection
name|m_packets
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|deque
operator|<
name|std
operator|::
name|string
operator|>
name|m_rx_packets
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|m_rx_partial_data
expr_stmt|;
end_expr_stmt

begin_comment
comment|// For packets that may come in more than one
end_comment

begin_comment
comment|// batch, anything left over can be left here
end_comment

begin_decl_stmt
name|pthread_t
name|m_rx_pthread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|m_max_payload_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|// the maximum sized payload we should send to gdb
end_comment

begin_decl_stmt
name|bool
name|m_extended_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|// are we in extended mode?
end_comment

begin_decl_stmt
name|bool
name|m_noack_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|// are we in no-ack mode?
end_comment

begin_decl_stmt
name|bool
name|m_thread_suffix_supported
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Set to true if the 'p', 'P', 'g', and 'G'
end_comment

begin_comment
comment|// packets should be prefixed with the thread
end_comment

begin_comment
comment|// ID and colon:
end_comment

begin_comment
comment|// "$pRR;thread:TTTT;" instead of "$pRR"
end_comment

begin_comment
comment|// "$PRR=VVVVVVVV;thread:TTTT;" instead of "$PRR=VVVVVVVV"
end_comment

begin_comment
comment|// "$g;thread:TTTT" instead of "$g"
end_comment

begin_comment
comment|// "$GVVVVVVVVVVVVVV;thread:TTTT;#00 instead of "$GVVVVVVVVVVVVVV"
end_comment

begin_decl_stmt
name|bool
name|m_list_threads_in_stop_reply
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|m_compression_minsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|// only packets larger than this size will be
end_comment

begin_comment
comment|// compressed
end_comment

begin_decl_stmt
name|bool
name|m_enable_compression_next_send_packet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|compression_types
name|m_compression_mode
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/* We translate the /usr/include/mach/exception_types.h exception types    (e.g. EXC_BAD_ACCESS) to the fake BSD signal numbers that gdb uses    in include/gdb/signals.h (e.g. TARGET_EXC_BAD_ACCESS).  These hard    coded values for TARGET_EXC_BAD_ACCESS et al must match the gdb    values in its include/gdb/signals.h.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_EXC_BAD_ACCESS
value|0x91
end_define

begin_define
define|#
directive|define
name|TARGET_EXC_BAD_INSTRUCTION
value|0x92
end_define

begin_define
define|#
directive|define
name|TARGET_EXC_ARITHMETIC
value|0x93
end_define

begin_define
define|#
directive|define
name|TARGET_EXC_EMULATION
value|0x94
end_define

begin_define
define|#
directive|define
name|TARGET_EXC_SOFTWARE
value|0x95
end_define

begin_define
define|#
directive|define
name|TARGET_EXC_BREAKPOINT
value|0x96
end_define

begin_comment
comment|/* Generally speaking, you can't assume gdb can receive more than 399 bytes    at a time with a random gdb.  This bufsize constant is only specifying    how many bytes gdb can *receive* from debugserver -- it tells us nothing    about how many bytes gdb might try to send in a single packet.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_GDB_REMOTE_PROTOCOL_BUFSIZE
value|399
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __RNBRemote_h__
end_comment

end_unit

