begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acglobal.h - Declarations for global variables  *       $Revision: 1.194 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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

begin_comment
comment|/*****************************************************************************  *  * Runtime configuration (static defaults that can be overriden at runtime)  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Enable "slack" in the AML interpreter?  Default is FALSE, and the  * interpreter strictly follows the ACPI specification.  Setting to TRUE  * allows the interpreter to ignore certain errors and/or bad AML constructs.  *  * Currently, these features are enabled by this flag:  *  * 1) Allow "implicit return" of last value in a control method  * 2) Allow access beyond the end of an operation region  * 3) Allow access to uninitialized locals/args (auto-init to integer 0)  * 4) Allow ANY object type to be a source operand for the Store() operator  * 5) Allow unresolved references (invalid target name) in package objects  * 6) Enable warning messages for behavior that is not ACPI spec compliant  */
end_comment

begin_function_decl
name|ACPI_EXTERN
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
name|ACPI_EXTERN
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
name|ACPI_EXTERN
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
comment|/*  * Disable wakeup GPEs during runtime? Default is TRUE because WAKE and  * RUNTIME GPEs should never be shared, and WAKE GPEs should typically only  * be enabled just before going to sleep.  */
end_comment

begin_function_decl
name|ACPI_EXTERN
name|UINT8
name|ACPI_INIT_GLOBAL
parameter_list|(
name|AcpiGbl_LeaveWakeGpesDisabled
parameter_list|,
name|TRUE
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*****************************************************************************  *  * ACPI Table globals  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * AcpiGbl_RootTableList is the master list of ACPI tables found in the  * RSDT/XSDT.  *  * AcpiGbl_FADT is a local copy of the FADT, converted to a common format.  */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_INTERNAL_RSDT
name|AcpiGbl_RootTableList
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_TABLE_FADT
name|AcpiGbl_FADT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These addresses are calculated from FADT address values */
end_comment

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_GENERIC_ADDRESS
name|AcpiGbl_XPm1aEnable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_GENERIC_ADDRESS
name|AcpiGbl_XPm1bEnable
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
comment|/*****************************************************************************  *  * Mutual exlusion within ACPICA subsystem  *  ****************************************************************************/
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
comment|/*  * Global lock mutex is an actual AML mutex object  * Global lock semaphore works in conjunction with the HW global lock  */
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
name|ACPI_OBJECT_NOTIFY_HANDLER
name|AcpiGbl_DeviceNotify
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_OBJECT_NOTIFY_HANDLER
name|AcpiGbl_SystemNotify
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
name|ACPI_WALK_STATE
modifier|*
name|AcpiGbl_BreakpointWalk
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
name|BOOLEAN
name|AcpiGbl_SystemAwakeAndRunning
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|DEFINE_ACPI_GLOBALS
end_ifndef

begin_comment
comment|/* Exception codes */
end_comment

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|AcpiGbl_ExceptionNames_Env
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|AcpiGbl_ExceptionNames_Pgm
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|AcpiGbl_ExceptionNames_Tbl
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|AcpiGbl_ExceptionNames_Aml
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
name|AcpiGbl_ExceptionNames_Ctrl
index|[]
decl_stmt|;
end_decl_stmt

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
name|AcpiGbl_HighestDstateNames
index|[
literal|4
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * Namespace globals  *  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NUM_NS_TYPES
value|ACPI_TYPE_INVALID+1
end_define

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
specifier|extern
specifier|const
name|UINT8
name|AcpiGbl_NsProperties
index|[
name|NUM_NS_TYPES
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
name|AcpiGbl_EntryStackPointer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_SIZE
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

begin_decl_stmt
specifier|extern
name|ACPI_FIXED_EVENT_INFO
name|AcpiGbl_FixedEventInfo
index|[
name|ACPI_NUM_FIXED_EVENTS
index|]
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

begin_comment
comment|/*****************************************************************************  *  * Debug support  *  ****************************************************************************/
end_comment

begin_comment
comment|/* Runtime configuration of debug print levels */
end_comment

begin_decl_stmt
specifier|extern
name|UINT32
name|AcpiDbgLevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|AcpiDbgLayer
decl_stmt|;
end_decl_stmt

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
name|AcpiGpeCount
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
name|ACPI_NAME
name|AcpiGbl_TraceMethodName
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

begin_decl_stmt
name|ACPI_EXTERN
name|UINT32
name|AcpiGbl_TraceFlags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*****************************************************************************  *  * Debugger globals  *  ****************************************************************************/
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
name|int
name|optind
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|char
modifier|*
name|optarg
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
name|char
name|AcpiGbl_DbLineBuf
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|char
name|AcpiGbl_DbParsedBuf
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|char
name|AcpiGbl_DbScopeBuf
index|[
literal|40
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|char
name|AcpiGbl_DbDebugFilename
index|[
literal|40
index|]
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
name|ACPI_TABLE_HEADER
modifier|*
name|AcpiGbl_DbTablePtr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_EXTERN
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiGbl_DbScopeNode
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACGLOBAL_H__ */
end_comment

end_unit

