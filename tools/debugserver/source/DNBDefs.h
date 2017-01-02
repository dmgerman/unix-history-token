begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DNBDefs.h -----------------------------------------------*- C++ -*-===//
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
comment|//  Created by Greg Clayton on 6/26/07.
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
name|__DNBDefs_h__
end_ifndef

begin_define
define|#
directive|define
name|__DNBDefs_h__
end_define

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslimits.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Define nub_addr_t and the invalid address value from the architecture
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__arm64__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_if

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// 64 bit address architectures
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|nub_addr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INVALID_NUB_ADDRESS
value|((nub_addr_t)~0ull)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// 32 bit address architectures
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|nub_addr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INVALID_NUB_ADDRESS
value|((nub_addr_t)~0ul)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Default to 64 bit address for unrecognized architectures.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_warning
warning|#
directive|warning
warning|undefined architecture, defaulting to 8 byte addresses
end_warning

begin_typedef
typedef|typedef
name|uint64_t
name|nub_addr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INVALID_NUB_ADDRESS
value|((nub_addr_t)~0ull)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|size_t
name|nub_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ssize_t
name|nub_ssize_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|nub_index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pid_t
name|nub_process_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|nub_thread_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|nub_event_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|nub_bool_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INVALID_NUB_PROCESS
value|((nub_process_t)0)
end_define

begin_define
define|#
directive|define
name|INVALID_NUB_THREAD
value|((nub_thread_t)0)
end_define

begin_define
define|#
directive|define
name|INVALID_NUB_WATCH_ID
value|((nub_watch_t)0)
end_define

begin_define
define|#
directive|define
name|INVALID_NUB_HW_INDEX
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|INVALID_NUB_REGNUM
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|NUB_GENERIC_ERROR
value|UINT32_MAX
end_define

begin_comment
comment|// Watchpoint types
end_comment

begin_define
define|#
directive|define
name|WATCH_TYPE_READ
value|(1u<< 0)
end_define

begin_define
define|#
directive|define
name|WATCH_TYPE_WRITE
value|(1u<< 1)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|eStateInvalid
init|=
literal|0
block|,
name|eStateUnloaded
block|,
name|eStateAttaching
block|,
name|eStateLaunching
block|,
name|eStateStopped
block|,
name|eStateRunning
block|,
name|eStateStepping
block|,
name|eStateCrashed
block|,
name|eStateDetached
block|,
name|eStateExited
block|,
name|eStateSuspended
block|}
name|nub_state_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|eLaunchFlavorDefault
init|=
literal|0
block|,
name|eLaunchFlavorPosixSpawn
init|=
literal|1
block|,
name|eLaunchFlavorForkExec
init|=
literal|2
block|,
ifdef|#
directive|ifdef
name|WITH_SPRINGBOARD
name|eLaunchFlavorSpringBoard
init|=
literal|3
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|WITH_BKS
name|eLaunchFlavorBKS
init|=
literal|4
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|WITH_FBS
name|eLaunchFlavorFBS
init|=
literal|5
endif|#
directive|endif
block|}
name|nub_launch_flavor_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NUB_STATE_IS_RUNNING
parameter_list|(
name|s
parameter_list|)
define|\
value|((s) == eStateAttaching || (s) == eStateLaunching || (s) == eStateRunning || \    (s) == eStateStepping || (s) == eStateDetached)
end_define

begin_define
define|#
directive|define
name|NUB_STATE_IS_STOPPED
parameter_list|(
name|s
parameter_list|)
define|\
value|((s) == eStateUnloaded || (s) == eStateStopped || (s) == eStateCrashed ||    \    (s) == eStateExited)
end_define

begin_enum
enum|enum
block|{
name|eEventProcessRunningStateChanged
init|=
literal|1
operator|<<
literal|0
block|,
comment|// The process has changed state to running
name|eEventProcessStoppedStateChanged
init|=
literal|1
operator|<<
literal|1
block|,
comment|// The process has changed state to stopped
name|eEventSharedLibsStateChange
init|=
literal|1
operator|<<
literal|2
block|,
comment|// Shared libraries loaded/unloaded state has changed
name|eEventStdioAvailable
init|=
literal|1
operator|<<
literal|3
block|,
comment|// Something is available on stdout/stderr
name|eEventProfileDataAvailable
init|=
literal|1
operator|<<
literal|4
block|,
comment|// Profile data ready for retrieval
name|kAllEventsMask
init|=
name|eEventProcessRunningStateChanged
operator||
name|eEventProcessStoppedStateChanged
operator||
name|eEventSharedLibsStateChange
operator||
name|eEventStdioAvailable
operator||
name|eEventProfileDataAvailable
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|LOG_VERBOSE
value|(1u<< 0)
end_define

begin_define
define|#
directive|define
name|LOG_PROCESS
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|LOG_THREAD
value|(1u<< 2)
end_define

begin_define
define|#
directive|define
name|LOG_EXCEPTIONS
value|(1u<< 3)
end_define

begin_define
define|#
directive|define
name|LOG_SHLIB
value|(1u<< 4)
end_define

begin_define
define|#
directive|define
name|LOG_MEMORY
value|(1u<< 5)
end_define

begin_comment
comment|// Log memory reads/writes calls
end_comment

begin_define
define|#
directive|define
name|LOG_MEMORY_DATA_SHORT
value|(1u<< 6)
end_define

begin_comment
comment|// Log short memory reads/writes bytes
end_comment

begin_define
define|#
directive|define
name|LOG_MEMORY_DATA_LONG
value|(1u<< 7)
end_define

begin_comment
comment|// Log all memory reads/writes bytes
end_comment

begin_define
define|#
directive|define
name|LOG_MEMORY_PROTECTIONS
value|(1u<< 8)
end_define

begin_comment
comment|// Log memory protection changes
end_comment

begin_define
define|#
directive|define
name|LOG_BREAKPOINTS
value|(1u<< 9)
end_define

begin_define
define|#
directive|define
name|LOG_EVENTS
value|(1u<< 10)
end_define

begin_define
define|#
directive|define
name|LOG_WATCHPOINTS
value|(1u<< 11)
end_define

begin_define
define|#
directive|define
name|LOG_STEP
value|(1u<< 12)
end_define

begin_define
define|#
directive|define
name|LOG_TASK
value|(1u<< 13)
end_define

begin_define
define|#
directive|define
name|LOG_DARWIN_LOG
value|(1u<< 14)
end_define

begin_define
define|#
directive|define
name|LOG_LO_USER
value|(1u<< 16)
end_define

begin_define
define|#
directive|define
name|LOG_HI_USER
value|(1u<< 31)
end_define

begin_define
define|#
directive|define
name|LOG_ALL
value|0xFFFFFFFFu
end_define

begin_define
define|#
directive|define
name|LOG_DEFAULT
define|\
value|((LOG_PROCESS) | (LOG_TASK) | (LOG_THREAD) | (LOG_EXCEPTIONS) |              \    (LOG_SHLIB) | (LOG_MEMORY) | (LOG_BREAKPOINTS) | (LOG_WATCHPOINTS) |        \    (LOG_STEP))
end_define

begin_define
define|#
directive|define
name|REGISTER_SET_ALL
value|0
end_define

begin_comment
comment|// Generic Register set to be defined by each architecture for access to common
end_comment

begin_comment
comment|// register values.
end_comment

begin_define
define|#
directive|define
name|REGISTER_SET_GENERIC
value|((uint32_t)0xFFFFFFFFu)
end_define

begin_define
define|#
directive|define
name|GENERIC_REGNUM_PC
value|0
end_define

begin_comment
comment|// Program Counter
end_comment

begin_define
define|#
directive|define
name|GENERIC_REGNUM_SP
value|1
end_define

begin_comment
comment|// Stack Pointer
end_comment

begin_define
define|#
directive|define
name|GENERIC_REGNUM_FP
value|2
end_define

begin_comment
comment|// Frame Pointer
end_comment

begin_define
define|#
directive|define
name|GENERIC_REGNUM_RA
value|3
end_define

begin_comment
comment|// Return Address
end_comment

begin_define
define|#
directive|define
name|GENERIC_REGNUM_FLAGS
value|4
end_define

begin_comment
comment|// Processor flags register
end_comment

begin_define
define|#
directive|define
name|GENERIC_REGNUM_ARG1
define|\
value|5
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 1 (if any)
end_comment

begin_define
define|#
directive|define
name|GENERIC_REGNUM_ARG2
define|\
value|6
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 2 (if any)
end_comment

begin_define
define|#
directive|define
name|GENERIC_REGNUM_ARG3
define|\
value|7
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 3 (if any)
end_comment

begin_define
define|#
directive|define
name|GENERIC_REGNUM_ARG4
define|\
value|8
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 4 (if any)
end_comment

begin_define
define|#
directive|define
name|GENERIC_REGNUM_ARG5
define|\
value|9
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 5 (if any)
end_comment

begin_define
define|#
directive|define
name|GENERIC_REGNUM_ARG6
define|\
value|10
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 6 (if any)
end_comment

begin_define
define|#
directive|define
name|GENERIC_REGNUM_ARG7
define|\
value|11
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 7 (if any)
end_comment

begin_define
define|#
directive|define
name|GENERIC_REGNUM_ARG8
define|\
value|12
end_define

begin_comment
comment|// The register that would contain pointer size or less argument 8 (if any)
end_comment

begin_enum
enum|enum
name|DNBRegisterType
block|{
name|InvalidRegType
init|=
literal|0
block|,
name|Uint
block|,
comment|// unsigned integer
name|Sint
block|,
comment|// signed integer
name|IEEE754
block|,
comment|// float
name|Vector
comment|// vector registers
block|}
enum|;
end_enum

begin_enum
enum|enum
name|DNBRegisterFormat
block|{
name|InvalidRegFormat
init|=
literal|0
block|,
name|Binary
block|,
name|Decimal
block|,
name|Hex
block|,
name|Float
block|,
name|VectorOfSInt8
block|,
name|VectorOfUInt8
block|,
name|VectorOfSInt16
block|,
name|VectorOfUInt16
block|,
name|VectorOfSInt32
block|,
name|VectorOfUInt32
block|,
name|VectorOfFloat32
block|,
name|VectorOfUInt128
block|}
enum|;
end_enum

begin_struct
struct|struct
name|DNBRegisterInfo
block|{
name|uint32_t
name|set
decl_stmt|;
comment|// Register set
name|uint32_t
name|reg
decl_stmt|;
comment|// Register number
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|// Name of this register
specifier|const
name|char
modifier|*
name|alt
decl_stmt|;
comment|// Alternate name
name|uint16_t
name|type
decl_stmt|;
comment|// Type of the register bits (DNBRegisterType)
name|uint16_t
name|format
decl_stmt|;
comment|// Default format for display (DNBRegisterFormat),
name|uint32_t
name|size
decl_stmt|;
comment|// Size in bytes of the register
name|uint32_t
name|offset
decl_stmt|;
comment|// Offset from the beginning of the register context
name|uint32_t
name|reg_ehframe
decl_stmt|;
comment|// eh_frame register number (INVALID_NUB_REGNUM when none)
name|uint32_t
name|reg_dwarf
decl_stmt|;
comment|// DWARF register number (INVALID_NUB_REGNUM when none)
name|uint32_t
name|reg_generic
decl_stmt|;
comment|// Generic register number (INVALID_NUB_REGNUM when none)
name|uint32_t
name|reg_debugserver
decl_stmt|;
comment|// The debugserver register number we'll use over
comment|// gdb-remote protocol (INVALID_NUB_REGNUM when
comment|// none)
specifier|const
name|char
modifier|*
modifier|*
name|value_regs
decl_stmt|;
comment|// If this register is a part of other registers,
comment|// list the register names terminated by NULL
specifier|const
name|char
modifier|*
modifier|*
name|update_regs
decl_stmt|;
comment|// If modifying this register will invalidate other
comment|// registers, list the register names terminated by
comment|// NULL
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DNBRegisterSetInfo
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|// Name of this register set
specifier|const
name|struct
name|DNBRegisterInfo
modifier|*
name|registers
decl_stmt|;
comment|// An array of register descriptions
name|nub_size_t
name|num_registers
decl_stmt|;
comment|// The number of registers in REGISTERS array above
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DNBThreadResumeAction
block|{
name|nub_thread_t
name|tid
decl_stmt|;
comment|// The thread ID that this action applies to,
comment|// INVALID_NUB_THREAD for the default thread action
name|nub_state_t
name|state
decl_stmt|;
comment|// Valid values are eStateStopped/eStateSuspended,
comment|// eStateRunning, and eStateStepping.
name|int
name|signal
decl_stmt|;
comment|// When resuming this thread, resume it with this signal
name|nub_addr_t
name|addr
decl_stmt|;
comment|// If not INVALID_NUB_ADDRESS, then set the PC for the thread
comment|// to ADDR before resuming/stepping
block|}
struct|;
end_struct

begin_enum
enum|enum
name|DNBThreadStopType
block|{
name|eStopTypeInvalid
init|=
literal|0
block|,
name|eStopTypeSignal
block|,
name|eStopTypeException
block|,
name|eStopTypeExec
block|}
enum|;
end_enum

begin_enum
enum|enum
name|DNBMemoryPermissions
block|{
name|eMemoryPermissionsWritable
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|eMemoryPermissionsReadable
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|eMemoryPermissionsExecutable
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|DNB_THREAD_STOP_INFO_MAX_DESC_LENGTH
value|256
end_define

begin_define
define|#
directive|define
name|DNB_THREAD_STOP_INFO_MAX_EXC_DATA
value|8
end_define

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// DNBThreadStopInfo
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Describes the reason a thread stopped.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_struct
struct|struct
name|DNBThreadStopInfo
block|{
name|DNBThreadStopType
name|reason
decl_stmt|;
name|char
name|description
index|[
name|DNB_THREAD_STOP_INFO_MAX_DESC_LENGTH
index|]
decl_stmt|;
union|union
block|{
comment|// eStopTypeSignal
struct|struct
block|{
name|uint32_t
name|signo
decl_stmt|;
block|}
name|signal
struct|;
comment|// eStopTypeException
struct|struct
block|{
name|uint32_t
name|type
decl_stmt|;
name|nub_size_t
name|data_count
decl_stmt|;
name|nub_addr_t
name|data
index|[
name|DNB_THREAD_STOP_INFO_MAX_EXC_DATA
index|]
decl_stmt|;
block|}
name|exception
struct|;
block|}
name|details
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DNBRegisterValue
block|{
name|struct
name|DNBRegisterInfo
name|info
decl_stmt|;
comment|// Register information for this register
union|union
block|{
name|int8_t
name|sint8
decl_stmt|;
name|int16_t
name|sint16
decl_stmt|;
name|int32_t
name|sint32
decl_stmt|;
name|int64_t
name|sint64
decl_stmt|;
name|uint8_t
name|uint8
decl_stmt|;
name|uint16_t
name|uint16
decl_stmt|;
name|uint32_t
name|uint32
decl_stmt|;
name|uint64_t
name|uint64
decl_stmt|;
name|float
name|float32
decl_stmt|;
name|double
name|float64
decl_stmt|;
name|int8_t
name|v_sint8
index|[
literal|32
index|]
decl_stmt|;
name|int16_t
name|v_sint16
index|[
literal|16
index|]
decl_stmt|;
name|int32_t
name|v_sint32
index|[
literal|8
index|]
decl_stmt|;
name|int64_t
name|v_sint64
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|v_uint8
index|[
literal|32
index|]
decl_stmt|;
name|uint16_t
name|v_uint16
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|v_uint32
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|v_uint64
index|[
literal|4
index|]
decl_stmt|;
name|float
name|v_float32
index|[
literal|8
index|]
decl_stmt|;
name|double
name|v_float64
index|[
literal|4
index|]
decl_stmt|;
name|void
modifier|*
name|pointer
decl_stmt|;
name|char
modifier|*
name|c_str
decl_stmt|;
block|}
name|value
union|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|DNBSharedLibraryState
block|{
name|eShlibStateUnloaded
init|=
literal|0
block|,
name|eShlibStateLoaded
init|=
literal|1
block|}
enum|;
end_enum

begin_ifndef
ifndef|#
directive|ifndef
name|DNB_MAX_SEGMENT_NAME_LENGTH
end_ifndef

begin_define
define|#
directive|define
name|DNB_MAX_SEGMENT_NAME_LENGTH
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|DNBSegment
block|{
name|char
name|name
index|[
name|DNB_MAX_SEGMENT_NAME_LENGTH
index|]
decl_stmt|;
name|nub_addr_t
name|addr
decl_stmt|;
name|nub_addr_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DNBExecutableImageInfo
block|{
name|char
name|name
index|[
name|PATH_MAX
index|]
decl_stmt|;
comment|// Name of the executable image (usually a full path)
name|uint32_t
name|state
decl_stmt|;
comment|// State of the executable image (see enum DNBSharedLibraryState)
name|nub_addr_t
name|header_addr
decl_stmt|;
comment|// Executable header address
name|uuid_t
name|uuid
decl_stmt|;
comment|// Unique identifier for matching with symbols
name|uint32_t
name|num_segments
decl_stmt|;
comment|// Number of contiguous memory segments to in SEGMENTS array
name|DNBSegment
modifier|*
name|segments
decl_stmt|;
comment|// Array of contiguous memory segments in executable
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DNBRegionInfo
block|{
name|nub_addr_t
name|addr
decl_stmt|;
name|nub_addr_t
name|size
decl_stmt|;
name|uint32_t
name|permissions
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|DNBProfileDataScanType
block|{
name|eProfileHostCPU
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|eProfileCPU
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|eProfileThreadsCPU
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|// By default excludes eProfileThreadName and eProfileQueueName.
name|eProfileThreadName
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
comment|// Assume eProfileThreadsCPU, get thread name as well.
name|eProfileQueueName
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
comment|// Assume eProfileThreadsCPU, get queue name as well.
name|eProfileHostMemory
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|eProfileMemory
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
comment|// By default, excludes eProfileMemoryDirtyPage.
name|eProfileMemoryDirtyPage
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
comment|// Assume eProfileMemory, get Dirty Page size as well.
name|eProfileMemoryAnonymous
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
comment|// Assume eProfileMemory, get Anonymous memory as well.
name|eProfileEnergy
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
name|eProfileAll
init|=
literal|0xffffffff
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|nub_addr_t
function_decl|(
modifier|*
name|DNBCallbackNameToAddress
function_decl|)
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|shlib_regex
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|nub_size_t
function_decl|(
modifier|*
name|DNBCallbackCopyExecutableImageInfos
function_decl|)
parameter_list|(
name|nub_process_t
name|pid
parameter_list|,
name|struct
name|DNBExecutableImageInfo
modifier|*
modifier|*
name|image_infos
parameter_list|,
name|nub_bool_t
name|only_changed
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|DNBCallbackLog
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
name|uint32_t
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|UNUSED_IF_ASSERT_DISABLED
parameter_list|(
name|x
parameter_list|)
value|((void)(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __DNBDefs_h__
end_comment

end_unit

