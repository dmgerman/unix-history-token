begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DNB.h ---------------------------------------------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Greg Clayton on 3/23/07.
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
name|__DNB_h__
end_ifndef

begin_define
define|#
directive|define
name|__DNB_h__
end_define

begin_include
include|#
directive|include
file|"DNBDefs.h"
end_include

begin_include
include|#
directive|include
file|"JSONGenerator.h"
end_include

begin_include
include|#
directive|include
file|"MacOSX/DarwinLog/DarwinLogEvent.h"
end_include

begin_include
include|#
directive|include
file|"MacOSX/Genealogy.h"
end_include

begin_include
include|#
directive|include
file|"MacOSX/ThreadInfo.h"
end_include

begin_include
include|#
directive|include
file|<mach/thread_info.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_define
define|#
directive|define
name|DNB_EXPORT
value|__attribute__((visibility("default")))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CPU_TYPE_ARM64
end_ifndef

begin_define
define|#
directive|define
name|CPU_TYPE_ARM64
value|((cpu_type_t)12 | 0x01000000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|DNBShouldCancelCallback
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|DNBInitialize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DNBTerminate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|nub_bool_t
name|DNBSetArchitecture
parameter_list|(
specifier|const
name|char
modifier|*
name|arch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Process control
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_function_decl
name|nub_process_t
name|DNBProcessLaunch
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|char
specifier|const
modifier|*
name|argv
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
name|envp
index|[]
parameter_list|,
specifier|const
name|char
modifier|*
name|working_directory
parameter_list|,
comment|// NULL => don't change, non-NULL => set
comment|// working directory for inferior to this
specifier|const
name|char
modifier|*
name|stdin_path
parameter_list|,
specifier|const
name|char
modifier|*
name|stdout_path
parameter_list|,
specifier|const
name|char
modifier|*
name|stderr_path
parameter_list|,
name|bool
name|no_stdio
parameter_list|,
name|nub_launch_flavor_t
name|launch_flavor
parameter_list|,
name|int
name|disable_aslr
parameter_list|,
specifier|const
name|char
modifier|*
name|event_data
parameter_list|,
name|char
modifier|*
name|err_str
parameter_list|,
name|size_t
name|err_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_process_t
name|DNBProcessGetPIDByName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_process_t
name|DNBProcessAttach
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|,
name|char
modifier|*
name|err_str
parameter_list|,
name|size_t
name|err_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_process_t
name|DNBProcessAttachByName
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|,
name|char
modifier|*
name|err_str
parameter_list|,
name|size_t
name|err_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_process_t
name|DNBProcessAttachWait
parameter_list|(
specifier|const
name|char
modifier|*
name|wait_name
parameter_list|,
name|nub_launch_flavor_t
name|launch_flavor
parameter_list|,
name|bool
name|ignore_existing
parameter_list|,
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|,
name|useconds_t
name|interval
parameter_list|,
name|char
modifier|*
name|err_str
parameter_list|,
name|size_t
name|err_len
parameter_list|,
name|DNBShouldCancelCallback
name|should_cancel
init|=
name|NULL
parameter_list|,
name|void
modifier|*
name|callback_data
init|=
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Resume a process with exact instructions on what to do with each thread:
end_comment

begin_comment
comment|// - If no thread actions are supplied (actions is NULL or num_actions is zero),
end_comment

begin_comment
comment|//   then all threads are continued.
end_comment

begin_comment
comment|// - If any thread actions are supplied, then each thread will do as it is told
end_comment

begin_comment
comment|//   by the action. A default actions for any threads that don't have an
end_comment

begin_comment
comment|//   explicit thread action can be made by making a thread action with a tid of
end_comment

begin_comment
comment|//   INVALID_NUB_THREAD. If there is no default action, those threads will
end_comment

begin_comment
comment|//   remain stopped.
end_comment

begin_decl_stmt
name|nub_bool_t
name|DNBProcessResume
argument_list|(
name|nub_process_t
name|pid
argument_list|,
specifier|const
name|DNBThreadResumeAction
operator|*
name|actions
argument_list|,
name|size_t
name|num_actions
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessHalt
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessDetach
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessSignal
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|int
name|signal
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessInterrupt
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessKill
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessSendEvent
argument_list|(
name|nub_process_t
name|pid
argument_list|,
specifier|const
name|char
operator|*
name|event
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_size_t
name|DNBProcessMemoryRead
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_addr_t
name|addr
argument_list|,
name|nub_size_t
name|size
argument_list|,
name|void
operator|*
name|buf
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint64_t
name|DNBProcessMemoryReadInteger
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_addr_t
name|addr
argument_list|,
name|nub_size_t
name|integer_size
argument_list|,
name|uint64_t
name|fail_value
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_addr_t
name|DNBProcessMemoryReadPointer
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_addr_t
name|addr
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|DNBProcessMemoryReadCString
argument_list|(
argument|nub_process_t pid
argument_list|,
argument|nub_addr_t addr
argument_list|)
name|DNB_EXPORT
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|DNBProcessMemoryReadCStringFixed
argument_list|(
argument|nub_process_t pid
argument_list|,
argument|nub_addr_t addr
argument_list|,
argument|nub_size_t fixed_length
argument_list|)
name|DNB_EXPORT
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|nub_size_t
name|DNBProcessMemoryWrite
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_addr_t
name|addr
argument_list|,
name|nub_size_t
name|size
argument_list|,
specifier|const
name|void
operator|*
name|buf
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_addr_t
name|DNBProcessMemoryAllocate
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_size_t
name|size
argument_list|,
name|uint32_t
name|permissions
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessMemoryDeallocate
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_addr_t
name|addr
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|DNBProcessMemoryRegionInfo
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_addr_t
name|addr
argument_list|,
name|DNBRegionInfo
operator|*
name|region_info
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|DNBProcessGetProfileData
argument_list|(
argument|nub_process_t pid
argument_list|,
argument|DNBProfileDataScanType scanType
argument_list|)
name|DNB_EXPORT
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessSetEnableAsyncProfiling
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_bool_t
name|enable
argument_list|,
name|uint64_t
name|interval_usec
argument_list|,
name|DNBProfileDataScanType
name|scan_type
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_function_decl
name|DarwinLogEventVector
name|DNBProcessGetAvailableDarwinLogEvents
parameter_list|(
name|nub_process_t
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Process status
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|nub_bool_t
name|DNBProcessIsAlive
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_state_t
name|DNBProcessGetState
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessGetExitStatus
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|int
operator|*
name|status
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessSetExitStatus
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|int
name|status
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|DNBProcessGetExitInfo
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessSetExitInfo
argument_list|(
name|nub_process_t
name|pid
argument_list|,
specifier|const
name|char
operator|*
name|info
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_size_t
name|DNBProcessGetNumThreads
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_thread_t
name|DNBProcessGetCurrentThread
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_thread_t
name|DNBProcessGetCurrentThreadMachPort
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_thread_t
name|DNBProcessSetCurrentThread
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_thread_t
name|tid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_thread_t
name|DNBProcessGetThreadAtIndex
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_size_t
name|thread_idx
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessSyncThreadState
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_thread_t
name|tid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_addr_t
name|DNBProcessGetSharedLibraryInfoAddress
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessSharedLibrariesUpdated
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_size_t
name|DNBProcessGetSharedLibraryInfo
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|nub_bool_t
name|only_changed
argument_list|,
name|DNBExecutableImageInfo
operator|*
operator|*
name|image_infos
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessSetNameToAddressCallback
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|DNBCallbackNameToAddress
name|callback
argument_list|,
name|void
operator|*
name|baton
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_bool_t
name|DNBProcessSetSharedLibraryInfoCallback
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|DNBCallbackCopyExecutableImageInfos
name|callback
argument_list|,
name|void
operator|*
name|baton
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_addr_t
name|DNBProcessLookupAddress
argument_list|(
name|nub_process_t
name|pid
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|shlib
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_size_t
name|DNBProcessGetAvailableSTDOUT
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|char
operator|*
name|buf
argument_list|,
name|nub_size_t
name|buf_size
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_size_t
name|DNBProcessGetAvailableSTDERR
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|char
operator|*
name|buf
argument_list|,
name|nub_size_t
name|buf_size
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_size_t
name|DNBProcessGetAvailableProfileData
argument_list|(
name|nub_process_t
name|pid
argument_list|,
name|char
operator|*
name|buf
argument_list|,
name|nub_size_t
name|buf_size
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|nub_size_t
name|DNBProcessGetStopCount
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|DNBProcessGetCPUType
argument_list|(
name|nub_process_t
name|pid
argument_list|)
name|DNB_EXPORT
decl_stmt|;
end_decl_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Process executable and arguments
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|DNBProcessGetExecutablePath
parameter_list|(
name|nub_process_t
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|DNBProcessGetArgumentAtIndex
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_size_t
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_size_t
name|DNBProcessGetArgumentCount
parameter_list|(
name|nub_process_t
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Process events
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_function_decl
name|nub_event_t
name|DNBProcessWaitForEvents
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_event_t
name|event_mask
parameter_list|,
name|bool
name|wait_for_set
parameter_list|,
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DNBProcessResetEvents
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_event_t
name|event_mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Thread functions
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|DNBThreadGetName
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_bool_t
name|DNBThreadGetIdentifierInfo
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|,
name|thread_identifier_info_data_t
modifier|*
name|ident_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_state_t
name|DNBThreadGetState
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_bool_t
name|DNBThreadGetRegisterValueByID
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|,
name|uint32_t
name|set
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|DNBRegisterValue
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_bool_t
name|DNBThreadSetRegisterValueByID
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|,
name|uint32_t
name|set
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
specifier|const
name|DNBRegisterValue
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_size_t
name|DNBThreadGetRegisterContext
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_size_t
name|DNBThreadSetRegisterContext
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|buf_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|DNBThreadSaveRegisterState
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_bool_t
name|DNBThreadRestoreRegisterState
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|,
name|uint32_t
name|save_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_bool_t
name|DNBThreadGetRegisterValueByName
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|,
name|uint32_t
name|set
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|DNBRegisterValue
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_bool_t
name|DNBThreadGetStopReason
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|,
name|DNBThreadStopInfo
modifier|*
name|stop_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|DNBThreadGetInfo
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|Genealogy
operator|::
name|ThreadActivitySP
name|DNBGetGenealogyInfoForThread
argument_list|(
argument|nub_process_t pid
argument_list|,
argument|nub_thread_t tid
argument_list|,
argument|bool&timed_out
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Genealogy
operator|::
name|ProcessExecutableInfoSP
name|DNBGetGenealogyImageInfo
argument_list|(
argument|nub_process_t pid
argument_list|,
argument|size_t idx
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ThreadInfo
operator|::
name|QoS
name|DNBGetRequestedQoSForThread
argument_list|(
argument|nub_process_t pid
argument_list|,
argument|nub_thread_t tid
argument_list|,
argument|nub_addr_t tsd
argument_list|,
argument|uint64_t dti_qos_class_index
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|nub_addr_t
name|DNBGetPThreadT
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_addr_t
name|DNBGetDispatchQueueT
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_addr_t
name|DNBGetTSDAddressForThread
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_thread_t
name|tid
parameter_list|,
name|uint64_t
name|plo_pthread_tsd_base_address_offset
parameter_list|,
name|uint64_t
name|plo_pthread_tsd_base_offset
parameter_list|,
name|uint64_t
name|plo_pthread_tsd_entry_size
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|JSONGenerator
operator|::
name|ObjectSP
name|DNBGetLoadedDynamicLibrariesInfos
argument_list|(
argument|nub_process_t pid
argument_list|,
argument|nub_addr_t image_list_address
argument_list|,
argument|nub_addr_t image_count
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|JSONGenerator
operator|::
name|ObjectSP
name|DNBGetAllLoadedLibrariesInfos
argument_list|(
argument|nub_process_t pid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|JSONGenerator
operator|::
name|ObjectSP
name|DNBGetLibrariesInfoForAddresses
argument_list|(
argument|nub_process_t pid
argument_list|,
argument|std::vector<uint64_t>&macho_addresses
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|JSONGenerator
operator|::
name|ObjectSP
name|DNBGetSharedCacheInfo
argument_list|(
argument|nub_process_t pid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Breakpoint functions
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_function_decl
name|nub_bool_t
name|DNBBreakpointSet
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_addr_t
name|addr
parameter_list|,
name|nub_size_t
name|size
parameter_list|,
name|nub_bool_t
name|hardware
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_bool_t
name|DNBBreakpointClear
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_addr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Watchpoint functions
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_function_decl
name|nub_bool_t
name|DNBWatchpointSet
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_addr_t
name|addr
parameter_list|,
name|nub_size_t
name|size
parameter_list|,
name|uint32_t
name|watch_flags
parameter_list|,
name|nub_bool_t
name|hardware
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_bool_t
name|DNBWatchpointClear
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|nub_addr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|DNBWatchpointGetNumSupportedHWP
parameter_list|(
name|nub_process_t
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|DNBGetRegisterCPUType
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|DNBRegisterSetInfo
modifier|*
name|DNBGetRegisterSetInfo
parameter_list|(
name|nub_size_t
modifier|*
name|num_reg_sets
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_bool_t
name|DNBGetRegisterInfoByName
parameter_list|(
specifier|const
name|char
modifier|*
name|reg_name
parameter_list|,
name|DNBRegisterInfo
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Other static nub information calls.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|DNBStateAsString
parameter_list|(
name|nub_state_t
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|nub_bool_t
name|DNBResolveExecutablePath
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|resolved_path
parameter_list|,
name|size_t
name|resolved_path_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|DNBGetOSVersionNumbers
parameter_list|(
name|uint64_t
modifier|*
name|major
parameter_list|,
name|uint64_t
modifier|*
name|minor
parameter_list|,
name|uint64_t
modifier|*
name|patch
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

