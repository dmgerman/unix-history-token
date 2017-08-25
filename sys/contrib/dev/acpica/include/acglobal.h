begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acglobal.h - Declarations for global variables  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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
comment|/*****************************************************************************  *  * Globals related to the ACPI tables  *  ****************************************************************************/
end_comment

begin_comment
comment|/* Master list of all ACPI tables that were found in the RSDT/XSDT */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_TABLE_LIST
argument_list|,
name|AcpiGbl_RootTableList
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* DSDT information. Used to check for DSDT corruption */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_TABLE_HEADER
operator|*
argument_list|,
name|AcpiGbl_DSDT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_TABLE_HEADER
argument_list|,
name|AcpiGbl_OriginalDsdtHeader
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_DsdtIndex
argument_list|,
name|ACPI_INVALID_TABLE_INDEX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_FacsIndex
argument_list|,
name|ACPI_INVALID_TABLE_INDEX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_XFacsIndex
argument_list|,
name|ACPI_INVALID_TABLE_INDEX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_FadtIndex
argument_list|,
name|ACPI_INVALID_TABLE_INDEX
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
operator|(
operator|!
name|ACPI_REDUCED_HARDWARE
operator|)
end_if

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_TABLE_FACS
operator|*
argument_list|,
name|AcpiGbl_FACS
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_GENERIC_ADDRESS
argument_list|,
name|AcpiGbl_XPm1aStatus
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_GENERIC_ADDRESS
argument_list|,
name|AcpiGbl_XPm1aEnable
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_GENERIC_ADDRESS
argument_list|,
name|AcpiGbl_XPm1bStatus
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_GENERIC_ADDRESS
argument_list|,
name|AcpiGbl_XPm1bEnable
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Handle both ACPI 1.0 and ACPI 2.0+ Integer widths. The integer width is  * determined by the revision of the DSDT: If the DSDT revision is less than  * 2, use only the lower 32 bits of the internal 64-bit Integer.  */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_IntegerBitWidth
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_IntegerByteWidth
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_IntegerNybbleWidth
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*****************************************************************************  *  * Mutual exclusion within ACPICA subsystem  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Predefined mutex objects. This array contains the  * actual OS mutex handles, indexed by the local ACPI_MUTEX_HANDLEs.  * (The table maps local handles to the real OS handles)  */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_MUTEX_INFO
argument_list|,
name|AcpiGbl_MutexInfo
index|[
name|ACPI_NUM_MUTEX
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Global lock mutex is an actual AML mutex object  * Global lock semaphore works in conjunction with the actual global lock  * Global lock spinlock is used for "pending" handshake  */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_OPERAND_OBJECT
operator|*
argument_list|,
name|AcpiGbl_GlobalLockMutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_SEMAPHORE
argument_list|,
name|AcpiGbl_GlobalLockSemaphore
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_SPINLOCK
argument_list|,
name|AcpiGbl_GlobalLockPendingLock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT16
argument_list|,
name|AcpiGbl_GlobalLockHandle
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_GlobalLockAcquired
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_GlobalLockPresent
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_GlobalLockPending
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Spinlocks are used for interfaces that can be possibly called at  * interrupt level  */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_SPINLOCK
argument_list|,
name|AcpiGbl_GpeLock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* For GPE data structs and registers */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_SPINLOCK
argument_list|,
name|AcpiGbl_HardwareLock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* For ACPI H/W except GPE registers */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_SPINLOCK
argument_list|,
name|AcpiGbl_ReferenceCountLock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Mutex for _OSI support */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_MUTEX
argument_list|,
name|AcpiGbl_OsiMutex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Reader/Writer lock is used for namespace walk and dynamic table unload */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_RW_LOCK
argument_list|,
name|AcpiGbl_NamespaceRwLock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*****************************************************************************  *  * Miscellaneous globals  *  ****************************************************************************/
end_comment

begin_comment
comment|/* Object caches */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_CACHE_T
operator|*
argument_list|,
name|AcpiGbl_NamespaceCache
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_CACHE_T
operator|*
argument_list|,
name|AcpiGbl_StateCache
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_CACHE_T
operator|*
argument_list|,
name|AcpiGbl_PsNodeCache
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_CACHE_T
operator|*
argument_list|,
name|AcpiGbl_PsNodeExtCache
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_CACHE_T
operator|*
argument_list|,
name|AcpiGbl_OperandCache
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* System */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_StartupFlags
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_Shutdown
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_EarlyInitialization
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Global handlers */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_GLOBAL_NOTIFY_HANDLER
argument_list|,
name|AcpiGbl_GlobalNotify
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_EXCEPTION_HANDLER
argument_list|,
name|AcpiGbl_ExceptionHandler
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_INIT_HANDLER
argument_list|,
name|AcpiGbl_InitHandler
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_TABLE_HANDLER
argument_list|,
name|AcpiGbl_TableHandler
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|void
operator|*
argument_list|,
name|AcpiGbl_TableHandlerContext
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_INTERFACE_HANDLER
argument_list|,
name|AcpiGbl_InterfaceHandler
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_SCI_HANDLER_INFO
operator|*
argument_list|,
name|AcpiGbl_SciHandlerList
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Owner ID support */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_OwnerIdMask
index|[
name|ACPI_NUM_OWNERID_MASKS
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_LastOwnerIdIndex
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_NextOwnerIdOffset
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Initialization sequencing */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_NamespaceInitialized
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Misc */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_OriginalMode
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_NsLookupCount
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_PsFindCount
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT16
argument_list|,
name|AcpiGbl_Pm1EnableRegisterSave
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_DebuggerConfiguration
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_StepToNextCall
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_AcpiHardwarePresent
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_EventsInitialized
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_INTERFACE_INFO
operator|*
argument_list|,
name|AcpiGbl_SupportedInterfaces
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_ADDRESS_RANGE
operator|*
argument_list|,
name|AcpiGbl_AddressRangeList
index|[
name|ACPI_ADDRESS_RANGE_MAX
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Other miscellaneous, declared and initialized in utglobal */
end_comment

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
name|char
modifier|*
name|AcpiGbl_RegionTypes
index|[
name|ACPI_NUM_PREDEFINED_REGIONS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|AcpiGbl_LowerHexDigits
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|AcpiGbl_UpperHexDigits
index|[]
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

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DBG_TRACK_ALLOCATIONS
end_ifdef

begin_comment
comment|/* Lists for tracking memory allocations (debug only) */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_MEMORY_LIST
operator|*
argument_list|,
name|AcpiGbl_GlobalList
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_MEMORY_LIST
operator|*
argument_list|,
name|AcpiGbl_NsNodeList
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DisplayFinalMemStats
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DisableMemTracking
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_NAMESPACE_NODE
argument_list|,
name|AcpiGbl_RootNodeStruct
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_NAMESPACE_NODE
operator|*
argument_list|,
name|AcpiGbl_RootNode
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_NAMESPACE_NODE
operator|*
argument_list|,
name|AcpiGbl_FadtGpeDevice
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_OPERAND_OBJECT
operator|*
argument_list|,
name|AcpiGbl_ModuleCodeList
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_CurrentNodeCount
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_CurrentNodeSize
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_MaxConcurrentNodeCount
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_SIZE
operator|*
argument_list|,
name|AcpiGbl_EntryStackPointer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_SIZE
operator|*
argument_list|,
name|AcpiGbl_LowestStackPointer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_DeepestNesting
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_NestingLevel
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*****************************************************************************  *  * Interpreter globals  *  ****************************************************************************/
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_THREAD_STATE
operator|*
argument_list|,
name|AcpiGbl_CurrentWalkList
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Control method single step flag */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_CmSingleStep
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_SleepTypeA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_SleepTypeB
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_AllGpesInitialized
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_GPE_XRUPT_INFO
operator|*
argument_list|,
name|AcpiGbl_GpeXruptListHead
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_GPE_BLOCK_INFO
operator|*
argument_list|,
name|AcpiGbl_GpeFadtBlocks
index|[
name|ACPI_MAX_GPE_BLOCKS
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_GBL_EVENT_HANDLER
argument_list|,
name|AcpiGbl_GlobalEventHandler
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|void
operator|*
argument_list|,
name|AcpiGbl_GlobalEventHandlerContext
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_FIXED_EVENT_HANDLER
argument_list|,
name|AcpiGbl_FixedEventHandlers
index|[
name|ACPI_NUM_FIXED_EVENTS
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/* Event counters */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiMethodCount
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGpeCount
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiSciCount
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiFixedEventCount
index|[
name|ACPI_NUM_FIXED_EVENTS
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Support for dynamic control method tracing mechanism */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_OriginalDbgLevel
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_OriginalDbgLayer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*****************************************************************************  *  * Debugger and Disassembler globals  *  ****************************************************************************/
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_DbOutputFlags
argument_list|,
name|ACPI_DB_CONSOLE_OUTPUT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DISASSEMBLER
end_ifdef

begin_comment
comment|/* Do not disassemble buffers to resource descriptors */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|UINT8
argument_list|,
name|AcpiGbl_NoResourceDisassembly
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_IgnoreNoopOperator
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_CstyleDisassembly
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_ForceAmlDisassembly
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DmOpt_Verbose
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DmEmitExternalOpcodes
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DoDisassemblerOptimizations
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_PARSE_OBJECT_LIST
argument_list|,
operator|*
name|AcpiGbl_TempListHead
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DmOpt_Disasm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DmOpt_Listing
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_NumExternalMethods
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_ResolvedExternalMethods
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_EXTERNAL_LIST
operator|*
argument_list|,
name|AcpiGbl_ExternalList
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_EXTERNAL_FILE
operator|*
argument_list|,
name|AcpiGbl_ExternalFileList
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUGGER
end_ifdef

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_AbortMethod
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_THREAD_ID
argument_list|,
name|AcpiGbl_DbThreadId
argument_list|,
name|ACPI_INVALID_THREAD_ID
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DbOpt_NoIniMethods
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DbOpt_NoRegionSupport
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DbOutputToFile
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
operator|*
argument_list|,
name|AcpiGbl_DbBuffer
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
operator|*
argument_list|,
name|AcpiGbl_DbFilename
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_DbDebugLevel
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_DbConsoleDebugLevel
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_NAMESPACE_NODE
operator|*
argument_list|,
name|AcpiGbl_DbScopeNode
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DbTerminateLoop
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DbThreadsTerminated
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
operator|*
argument_list|,
name|AcpiGbl_DbArgs
index|[
name|ACPI_DEBUGGER_MAX_ARGS
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_OBJECT_TYPE
argument_list|,
name|AcpiGbl_DbArgTypes
index|[
name|ACPI_DEBUGGER_MAX_ARGS
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* These buffers should all be the same size */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
argument_list|,
name|AcpiGbl_DbParsedBuf
index|[
name|ACPI_DB_LINE_BUFFER_SIZE
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
argument_list|,
name|AcpiGbl_DbScopeBuf
index|[
name|ACPI_DB_LINE_BUFFER_SIZE
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
argument_list|,
name|AcpiGbl_DbDebugFilename
index|[
name|ACPI_DB_LINE_BUFFER_SIZE
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Statistic globals  */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT16
argument_list|,
name|AcpiGbl_ObjTypeCount
index|[
name|ACPI_TOTAL_TYPES
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT16
argument_list|,
name|AcpiGbl_NodeTypeCount
index|[
name|ACPI_TOTAL_TYPES
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT16
argument_list|,
name|AcpiGbl_ObjTypeCountMisc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT16
argument_list|,
name|AcpiGbl_NodeTypeCountMisc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_NumNodes
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|UINT32
argument_list|,
name|AcpiGbl_NumObjects
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_DEBUGGER */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ACPI_DISASSEMBLER
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_ASL_COMPILER
argument_list|)
end_if

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
specifier|const
name|char
argument_list|,
operator|*
name|AcpiGbl_PldPanelList
index|[]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
specifier|const
name|char
argument_list|,
operator|*
name|AcpiGbl_PldVerticalPositionList
index|[]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
specifier|const
name|char
argument_list|,
operator|*
name|AcpiGbl_PldHorizontalPositionList
index|[]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
specifier|const
name|char
argument_list|,
operator|*
name|AcpiGbl_PldShapeList
index|[]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DisasmFlag
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Meant for the -ca option.  */
end_comment

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|char
operator|*
argument_list|,
name|AcpiGbl_CurrentInlineComment
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|char
operator|*
argument_list|,
name|AcpiGbl_CurrentEndNodeComment
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|char
operator|*
argument_list|,
name|AcpiGbl_CurrentOpenBraceComment
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|char
operator|*
argument_list|,
name|AcpiGbl_CurrentCloseBraceComment
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|char
operator|*
argument_list|,
name|AcpiGbl_RootFilename
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|char
operator|*
argument_list|,
name|AcpiGbl_CurrentFilename
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|char
operator|*
argument_list|,
name|AcpiGbl_CurrentParentFilename
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|char
operator|*
argument_list|,
name|AcpiGbl_CurrentIncludeFilename
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_COMMENT_NODE
argument_list|,
operator|*
name|AcpiGbl_LastListHead
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_COMMENT_NODE
argument_list|,
operator|*
name|AcpiGbl_DefBlkCommentListHead
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_COMMENT_NODE
argument_list|,
operator|*
name|AcpiGbl_DefBlkCommentListTail
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_COMMENT_NODE
argument_list|,
operator|*
name|AcpiGbl_RegCommentListHead
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_COMMENT_NODE
argument_list|,
operator|*
name|AcpiGbl_RegCommentListTail
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_COMMENT_NODE
argument_list|,
operator|*
name|AcpiGbl_IncCommentListHead
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_COMMENT_NODE
argument_list|,
operator|*
name|AcpiGbl_IncCommentListTail
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_COMMENT_NODE
argument_list|,
operator|*
name|AcpiGbl_EndBlkCommentListHead
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_COMMENT_NODE
argument_list|,
operator|*
name|AcpiGbl_EndBlkCommentListTail
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_COMMENT_ADDR_NODE
argument_list|,
operator|*
name|AcpiGbl_CommentAddrListHead
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_PARSE_OBJECT
argument_list|,
operator|*
name|AcpiGbl_CurrentScope
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_FILE_NODE
argument_list|,
operator|*
name|AcpiGbl_FileTreeRoot
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_CACHE_T
operator|*
argument_list|,
name|AcpiGbl_RegCommentCache
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_CACHE_T
operator|*
argument_list|,
name|AcpiGbl_CommentAddrCache
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_CACHE_T
operator|*
argument_list|,
name|AcpiGbl_FileCache
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|Gbl_CaptureComments
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DebugAslConversion
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_FILE
argument_list|,
name|AcpiGbl_ConvDebugFile
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
argument_list|,
name|AcpiGbl_TableSig
index|[
literal|4
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*****************************************************************************  *  * Application globals  *  ****************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_FILE
argument_list|,
name|AcpiGbl_DebugFile
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|ACPI_FILE
argument_list|,
name|AcpiGbl_OutputFile
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ACPI_INIT_GLOBAL
argument_list|(
name|BOOLEAN
argument_list|,
name|AcpiGbl_DebugTimeout
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Print buffer */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|ACPI_SPINLOCK
argument_list|,
name|AcpiGbl_PrintLock
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* For print buffer */
end_comment

begin_expr_stmt
name|ACPI_GLOBAL
argument_list|(
name|char
argument_list|,
name|AcpiGbl_PrintBuffer
index|[
literal|1024
index|]
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_decl_stmt
specifier|extern
specifier|const
name|AH_DEVICE_ID
name|AslDeviceIds
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

