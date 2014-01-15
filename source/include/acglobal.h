begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acglobal.h - Declarations for global variables  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACGLOBAL_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACGLOBAL_H__
end_define

begin_comment
comment|/*  * Ensure that the globals are actually defined and initialized only once.  *  * The use of these macros allows a single list of globals (here) in order  * to simplify maintenance of the code.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_ACPI_GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|ACPI_EXTERN
end_define

begin_define
define|#
directive|define
name|ACPI_INIT_GLOBAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a=b
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_EXTERN
value|extern
end_define

begin_define
define|#
directive|define
name|ACPI_INIT_GLOBAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_ACPI_GLOBALS
end_ifdef

begin_comment
comment|/* Public globals, available from outside ACPICA subsystem */
end_comment

begin_comment
comment|/*****************************************************************************  *  * Runtime configuration (static defaults that can be overriden at runtime)  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Enable "slack" in the AML interpreter?  Default is FALSE, and the  * interpreter strictly follows the ACPI specification. Setting to TRUE  * allows the interpreter to ignore certain errors and/or bad AML constructs.  *  * Currently, these features are enabled by this flag:  *  * 1) Allow "implicit return" of last value in a control method  * 2) Allow access beyond the end of an operation region  * 3) Allow access to uninitialized locals/args (auto-init to integer 0)  * 4) Allow ANY object type to be a source operand for the Store() operator  * 5) Allow unresolved references (invalid target name) in package objects  * 6) Enable warning messages for behavior that is not ACPI spec compliant  */
end_comment

begin_function_decl
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_EnableInterpreterSlack
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Automatically serialize ALL control methods? Default is FALSE, meaning  * to use the Serialized/NotSerialized method flags on a per method basis.  * Only change this if the ASL code is poorly written and cannot handle  * reentrancy even though methods are marked "NotSerialized".  */
end_comment

begin_function_decl
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_AllMethodsSerialized
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create the predefined _OSI method in the namespace? Default is TRUE  * because ACPI CA is fully compatible with other ACPI implementations.  * Changing this will revert ACPI CA (and machine ASL) to pre-OSI behavior.  */
end_comment

begin_function_decl
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_CreateOsiMethod
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Optionally use default values for the ACPI register widths. Set this to  * TRUE to use the defaults, if an FADT contains incorrect widths/lengths.  */
end_comment

begin_function_decl
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_UseDefaultRegisterWidths
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Optionally enable output from the AML Debug Object.  */
end_comment

begin_function_decl
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_EnableAmlDebugObject
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Optionally copy the entire DSDT to local memory (instead of simply  * mapping it.) There are some BIOSs that corrupt or replace the original  * DSDT, creating the need for this option. Default is FALSE, do not copy  * the DSDT.  */
end_comment

begin_function_decl
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_CopyDsdtLocally
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Optionally ignore an XSDT if present and use the RSDT instead.  * Although the ACPI specification requires that an XSDT be used instead  * of the RSDT, the XSDT has been found to be corrupt or ill-formed on  * some machines. Default behavior is to use the XSDT if present.  */
end_comment

begin_function_decl
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_DoNotUseXsdt
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Optionally use 32-bit FADT addresses if and when there is a conflict  * (address mismatch) between the 32-bit and 64-bit versions of the  * address. Although ACPICA adheres to the ACPI specification which  * requires the use of the corresponding 64-bit address if it is non-zero,  * some machines have been found to have a corrupted non-zero 64-bit  * address. Default is FALSE, do not favor the 32-bit addresses.  */
end_comment

begin_function_decl
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_Use32BitFadtAddresses
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Optionally truncate I/O addresses to 16 bits. Provides compatibility  * with other ACPI implementations. NOTE: During ACPICA initialization,  * this value is set to TRUE if any Windows OSI strings have been  * requested by the BIOS.  */
end_comment

begin_function_decl
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_TruncateIoAddresses
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Disable runtime checking and repair of values returned by control methods.  * Use only if the repair is causing a problem on a particular machine.  */
end_comment

begin_function_decl
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_DisableAutoRepair
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Optionally do not load any SSDTs from the RSDT/XSDT during initialization.  * This can be useful for debugging ACPI problems on some machines.  */
end_comment

begin_function_decl
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_DisableSsdtTableLoad
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * We keep track of the latest version of Windows that has been requested by  * the BIOS.  */
end_comment

begin_decl_stmt
name|UINT8
name|ACPI_INIT_GLOBAL
argument_list|(
name|AcpiGbl_OsiData
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* AcpiGbl_FADT is a local copy of the FADT, converted to a common format. */
end_comment

begin_decl_stmt
name|ACPI_TABLE_FADT
name|AcpiGbl_FADT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UINT32
name|AcpiCurrentGpeCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UINT32
name|AcpiGbl_TraceFlags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_NAME
name|AcpiGbl_TraceMethodName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BOOLEAN
name|AcpiGbl_SystemAwakeAndRunning
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ACPI 5.0 introduces the concept of a "reduced hardware platform", meaning  * that the ACPI hardware is no longer required. A flag in the FADT indicates  * a reduced HW machine, and that flag is duplicated here for convenience.  */
end_comment

begin_decl_stmt
name|BOOLEAN
name|AcpiGbl_ReducedHardware
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEFINE_ACPI_GLOBALS */
end_comment

begin_comment
comment|/* Do not disassemble buffers to resource descriptors */
end_comment

begin_function_decl
name|ACPI_EXTERN
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_NoResourceDisassembly
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*****************************************************************************  *  * ACPI Table globals  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * AcpiGbl_RootTableList is the master list of ACPI tables that were  * found in the RSDT/XSDT.  */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_TABLE_LIST
name|AcpiGbl_RootTableList
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|(
operator|!
name|ACPI_REDUCED_HARDWARE
operator|)
end_if

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_TABLE_FACS
modifier|*
name|AcpiGbl_FACS
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ACPI_REDUCED_HARDWARE */
end_comment

begin_comment
comment|/* These addresses are calculated from the FADT Event Block addresses */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_GENERIC_ADDRESS
name|AcpiGbl_XPm1aStatus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_GENERIC_ADDRESS
name|AcpiGbl_XPm1aEnable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_GENERIC_ADDRESS
name|AcpiGbl_XPm1bStatus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_GENERIC_ADDRESS
name|AcpiGbl_XPm1bEnable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DSDT information. Used to check for DSDT corruption */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_TABLE_HEADER
modifier|*
name|AcpiGbl_DSDT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_TABLE_HEADER
name|AcpiGbl_OriginalDsdtHeader
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Handle both ACPI 1.0 and ACPI 2.0 Integer widths. The integer width is  * determined by the revision of the DSDT: If the DSDT revision is less than  * 2, use only the lower 32 bits of the internal 64-bit Integer.  */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|UINT8
name|AcpiGbl_IntegerBitWidth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT8
name|AcpiGbl_IntegerByteWidth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT8
name|AcpiGbl_IntegerNybbleWidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*****************************************************************************  *  * Mutual exclusion within ACPICA subsystem  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Predefined mutex objects. This array contains the  * actual OS mutex handles, indexed by the local ACPI_MUTEX_HANDLEs.  * (The table maps local handles to the real OS handles)  */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_MUTEX_INFO
name|AcpiGbl_MutexInfo
index|[
name|ACPI_NUM_MUTEX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Global lock mutex is an actual AML mutex object  * Global lock semaphore works in conjunction with the actual global lock  * Global lock spinlock is used for "pending" handshake  */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_OPERAND_OBJECT
modifier|*
name|AcpiGbl_GlobalLockMutex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_SEMAPHORE
name|AcpiGbl_GlobalLockSemaphore
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_SPINLOCK
name|AcpiGbl_GlobalLockPendingLock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT16
name|AcpiGbl_GlobalLockHandle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_GlobalLockAcquired
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_GlobalLockPresent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_GlobalLockPending
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Spinlocks are used for interfaces that can be possibly called at  * interrupt level  */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_SPINLOCK
name|AcpiGbl_GpeLock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For GPE data structs and registers */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_SPINLOCK
name|AcpiGbl_HardwareLock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For ACPI H/W except GPE registers */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_SPINLOCK
name|AcpiGbl_ReferenceCountLock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mutex for _OSI support */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_MUTEX
name|AcpiGbl_OsiMutex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reader/Writer lock is used for namespace walk and dynamic table unload */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_RW_LOCK
name|AcpiGbl_NamespaceRwLock
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*****************************************************************************  *  * Miscellaneous globals  *  ****************************************************************************/
end_comment

begin_comment
comment|/* Object caches */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_CACHE_T
modifier|*
name|AcpiGbl_NamespaceCache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_CACHE_T
modifier|*
name|AcpiGbl_StateCache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_CACHE_T
modifier|*
name|AcpiGbl_PsNodeCache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_CACHE_T
modifier|*
name|AcpiGbl_PsNodeExtCache
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_CACHE_T
modifier|*
name|AcpiGbl_OperandCache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global handlers */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_GLOBAL_NOTIFY_HANDLER
name|AcpiGbl_GlobalNotify
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_EXCEPTION_HANDLER
name|AcpiGbl_ExceptionHandler
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_INIT_HANDLER
name|AcpiGbl_InitHandler
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_TABLE_HANDLER
name|AcpiGbl_TableHandler
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|void
modifier|*
name|AcpiGbl_TableHandlerContext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_WALK_STATE
modifier|*
name|AcpiGbl_BreakpointWalk
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_INTERFACE_HANDLER
name|AcpiGbl_InterfaceHandler
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_SCI_HANDLER_INFO
modifier|*
name|AcpiGbl_SciHandlerList
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Owner ID support */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_OwnerIdMask
index|[
name|ACPI_NUM_OWNERID_MASKS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT8
name|AcpiGbl_LastOwnerIdIndex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT8
name|AcpiGbl_NextOwnerIdOffset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialization sequencing */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_RegMethodsExecuted
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Misc */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_OriginalMode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_RsdpOriginalLocation
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_NsLookupCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_PsFindCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT16
name|AcpiGbl_Pm1EnableRegisterSave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT8
name|AcpiGbl_DebuggerConfiguration
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_StepToNextCall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_AcpiHardwarePresent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_EventsInitialized
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_INTERFACE_INFO
modifier|*
name|AcpiGbl_SupportedInterfaces
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_ADDRESS_RANGE
modifier|*
name|AcpiGbl_AddressRangeList
index|[
name|ACPI_ADDRESS_RANGE_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|DEFINE_ACPI_GLOBALS
end_ifndef

begin_comment
comment|/* Other miscellaneous */
end_comment

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|AcpiGbl_Shutdown
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|AcpiGbl_StartupFlags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_SleepStateNames
index|[
name|ACPI_S_STATE_COUNT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_LowestDstateNames
index|[
name|ACPI_NUM_SxW_METHODS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_HighestDstateNames
index|[
name|ACPI_NUM_SxD_METHODS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|ACPI_OPCODE_INFO
name|AcpiGbl_AmlOpInfo
index|[
name|AML_NUM_OPCODES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_RegionTypes
index|[
name|ACPI_NUM_PREDEFINED_REGIONS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DBG_TRACK_ALLOCATIONS
end_ifdef

begin_comment
comment|/* Lists for tracking memory allocations */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_MEMORY_LIST
modifier|*
name|AcpiGbl_GlobalList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_MEMORY_LIST
modifier|*
name|AcpiGbl_NsNodeList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_DisplayFinalMemStats
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_DisableMemTracking
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * Namespace globals  *  ****************************************************************************/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ACPI_NO_METHOD_EXECUTION
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_CONSTANT_EVAL_ONLY
argument_list|)
end_if

begin_define
define|#
directive|define
name|NUM_PREDEFINED_NAMES
value|10
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NUM_PREDEFINED_NAMES
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_NAMESPACE_NODE
name|AcpiGbl_RootNodeStruct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiGbl_RootNode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiGbl_FadtGpeDevice
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_OPERAND_OBJECT
modifier|*
name|AcpiGbl_ModuleCodeList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|UINT8
name|AcpiGbl_NsProperties
index|[
name|ACPI_NUM_NS_TYPES
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|ACPI_PREDEFINED_NAMES
name|AcpiGbl_PreDefinedNames
index|[
name|NUM_PREDEFINED_NAMES
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_OUTPUT
end_ifdef

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_CurrentNodeCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_CurrentNodeSize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_MaxConcurrentNodeCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_SIZE
modifier|*
name|AcpiGbl_EntryStackPointer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_SIZE
modifier|*
name|AcpiGbl_LowestStackPointer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_DeepestNesting
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * Interpreter globals  *  ****************************************************************************/
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_THREAD_STATE
modifier|*
name|AcpiGbl_CurrentWalkList
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Control method single step flag */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|UINT8
name|AcpiGbl_CmSingleStep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*****************************************************************************  *  * Hardware globals  *  ****************************************************************************/
end_comment

begin_decl_stmt
specifier|extern
name|ACPI_BIT_REGISTER_INFO
name|AcpiGbl_BitRegisterInfo
index|[
name|ACPI_NUM_BITREG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT8
name|AcpiGbl_SleepTypeA
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT8
name|AcpiGbl_SleepTypeB
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*****************************************************************************  *  * Event and GPE globals  *  ****************************************************************************/
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|ACPI_REDUCED_HARDWARE
operator|)
end_if

begin_decl_stmt
name|ACPI_EXTERN
name|UINT8
name|AcpiGbl_AllGpesInitialized
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|AcpiGbl_GpeXruptListHead
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|AcpiGbl_GpeFadtBlocks
index|[
name|ACPI_MAX_GPE_BLOCKS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_GBL_EVENT_HANDLER
name|AcpiGbl_GlobalEventHandler
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|void
modifier|*
name|AcpiGbl_GlobalEventHandlerContext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_FIXED_EVENT_HANDLER
name|AcpiGbl_FixedEventHandlers
index|[
name|ACPI_NUM_FIXED_EVENTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_FIXED_EVENT_INFO
name|AcpiGbl_FixedEventInfo
index|[
name|ACPI_NUM_FIXED_EVENTS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ACPI_REDUCED_HARDWARE */
end_comment

begin_comment
comment|/*****************************************************************************  *  * Debug support  *  ****************************************************************************/
end_comment

begin_comment
comment|/* Procedure nesting level for debug output */
end_comment

begin_decl_stmt
specifier|extern
name|UINT32
name|AcpiGbl_NestingLevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Event counters */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiMethodCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGpeCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiSciCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiFixedEventCount
index|[
name|ACPI_NUM_FIXED_EVENTS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Support for dynamic control method tracing mechanism */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_OriginalDbgLevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_OriginalDbgLayer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_TraceDbgLevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_TraceDbgLayer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*****************************************************************************  *  * Debugger and Disassembler globals  *  ****************************************************************************/
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|UINT8
name|AcpiGbl_DbOutputFlags
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DISASSEMBLER
end_ifdef

begin_function_decl
name|ACPI_EXTERN
name|BOOLEAN
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_IgnoreNoopOperator
parameter_list|,
name|FALSE
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_DbOpt_disasm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_DbOpt_verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_NumExternalMethods
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_ResolvedExternalMethods
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_EXTERNAL_LIST
modifier|*
name|AcpiGbl_ExternalList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_EXTERNAL_FILE
modifier|*
name|AcpiGbl_ExternalFileList
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUGGER
end_ifdef

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|AcpiGbl_MethodExecuting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|AcpiGbl_AbortMethod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|AcpiGbl_DbTerminateThreads
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_DbOpt_tables
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_DbOpt_stats
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_DbOpt_ini_methods
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_DbOpt_NoRegionSupport
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|BOOLEAN
name|AcpiGbl_DbOutputToFile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|char
modifier|*
name|AcpiGbl_DbBuffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|char
modifier|*
name|AcpiGbl_DbFilename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_DbDebugLevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_DbConsoleDebugLevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiGbl_DbScopeNode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|char
modifier|*
name|AcpiGbl_DbArgs
index|[
name|ACPI_DEBUGGER_MAX_ARGS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_OBJECT_TYPE
name|AcpiGbl_DbArgTypes
index|[
name|ACPI_DEBUGGER_MAX_ARGS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These buffers should all be the same size */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|char
name|AcpiGbl_DbLineBuf
index|[
name|ACPI_DB_LINE_BUFFER_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|char
name|AcpiGbl_DbParsedBuf
index|[
name|ACPI_DB_LINE_BUFFER_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|char
name|AcpiGbl_DbScopeBuf
index|[
name|ACPI_DB_LINE_BUFFER_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|char
name|AcpiGbl_DbDebugFilename
index|[
name|ACPI_DB_LINE_BUFFER_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Statistic globals  */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|UINT16
name|AcpiGbl_ObjTypeCount
index|[
name|ACPI_TYPE_NS_NODE_MAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT16
name|AcpiGbl_NodeTypeCount
index|[
name|ACPI_TYPE_NS_NODE_MAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT16
name|AcpiGbl_ObjTypeCountMisc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT16
name|AcpiGbl_NodeTypeCountMisc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_NumNodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_NumObjects
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_SizeOfParseTree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_SizeOfMethodTrees
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_SizeOfNodeEntries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_SizeOfAcpiObjects
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_DEBUGGER */
end_comment

begin_comment
comment|/*****************************************************************************  *  * Application globals  *  ****************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_function_decl
name|ACPI_FILE
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_DebugFile
parameter_list|,
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_APPLICATION */
end_comment

begin_comment
comment|/*****************************************************************************  *  * Info/help support  *  ****************************************************************************/
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|AH_PREDEFINED_NAME
name|AslPredefinedInfo
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACGLOBAL_H__ */
end_comment

end_unit

