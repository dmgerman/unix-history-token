begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: aclocal.h - Internal data types used across the ACPI subsystem  *       $Revision: 145 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999, 2000, 2001, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACLOCAL_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACLOCAL_H__
end_define

begin_define
define|#
directive|define
name|WAIT_FOREVER
value|((UINT32) -1)
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|ACPI_MUTEX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_MUTEX_HANDLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_MEMORY_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_LOGICAL_ADDRESSING
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_PHYSICAL_ADDRESSING
value|0x01
end_define

begin_comment
comment|/* Object descriptor types */
end_comment

begin_define
define|#
directive|define
name|ACPI_CACHED_OBJECT
value|0x11
end_define

begin_comment
comment|/* ORed in when object is cached */
end_comment

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE
value|0x20
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_UPDATE
value|0x21
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_PACKAGE
value|0x22
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_CONTROL
value|0x23
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_RPSCOPE
value|0x24
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_PSCOPE
value|0x25
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_WSCOPE
value|0x26
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_RESULT
value|0x27
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_NOTIFY
value|0x28
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_THREAD
value|0x29
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_WALK
value|0x44
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_PARSER
value|0x66
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_INTERNAL
value|0x88
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_NAMED
value|0xAA
end_define

begin_comment
comment|/*****************************************************************************  *  * Mutex typedefs and structs  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Predefined handles for the mutex objects used within the subsystem  * All mutex objects are automatically created by AcpiUtMutexInitialize.  *  * The acquire/release ordering protocol is implied via this list.  Mutexes  * with a lower value must be acquired before mutexes with a higher value.  *  * NOTE: any changes here must be reflected in the AcpiGbl_MutexNames table also!  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MTX_EXECUTE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_INTERPRETER
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_PARSER
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_DISPATCHER
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_TABLES
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_OP_REGIONS
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_NAMESPACE
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_EVENTS
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_HARDWARE
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_CACHES
value|9
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_MEMORY
value|10
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_DEBUG_CMD_COMPLETE
value|11
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_DEBUG_CMD_READY
value|12
end_define

begin_define
define|#
directive|define
name|MAX_MTX
value|12
end_define

begin_define
define|#
directive|define
name|NUM_MTX
value|MAX_MTX+1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ACPI_DEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|ENABLE_DEBUGGER
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_ACPI_GLOBALS
end_ifdef

begin_comment
comment|/* Names for the mutexes used in the subsystem */
end_comment

begin_decl_stmt
specifier|static
name|NATIVE_CHAR
modifier|*
name|AcpiGbl_MutexNames
index|[]
init|=
block|{
literal|"ACPI_MTX_Execute"
block|,
literal|"ACPI_MTX_Interpreter"
block|,
literal|"ACPI_MTX_Parser"
block|,
literal|"ACPI_MTX_Dispatcher"
block|,
literal|"ACPI_MTX_Tables"
block|,
literal|"ACPI_MTX_OpRegions"
block|,
literal|"ACPI_MTX_Namespace"
block|,
literal|"ACPI_MTX_Events"
block|,
literal|"ACPI_MTX_Hardware"
block|,
literal|"ACPI_MTX_Caches"
block|,
literal|"ACPI_MTX_Memory"
block|,
literal|"ACPI_MTX_DebugCmdComplete"
block|,
literal|"ACPI_MTX_DebugCmdReady"
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Table for the global mutexes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AcpiMutexInfo
block|{
name|ACPI_MUTEX
name|Mutex
decl_stmt|;
name|UINT32
name|UseCount
decl_stmt|;
name|UINT32
name|OwnerId
decl_stmt|;
block|}
name|ACPI_MUTEX_INFO
typedef|;
end_typedef

begin_comment
comment|/* This owner ID means that the mutex is not in use (unlocked) */
end_comment

begin_define
define|#
directive|define
name|ACPI_MUTEX_NOT_ACQUIRED
value|(UINT32) (-1)
end_define

begin_comment
comment|/* Lock flag parameter for various interfaces */
end_comment

begin_define
define|#
directive|define
name|ACPI_MTX_DO_NOT_LOCK
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_MTX_LOCK
value|1
end_define

begin_typedef
typedef|typedef
name|UINT16
name|ACPI_OWNER_ID
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OWNER_TYPE_TABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|OWNER_TYPE_METHOD
value|0x1
end_define

begin_define
define|#
directive|define
name|FIRST_METHOD_ID
value|0x0000
end_define

begin_define
define|#
directive|define
name|FIRST_TABLE_ID
value|0x8000
end_define

begin_comment
comment|/* TBD: [Restructure] get rid of the need for this! */
end_comment

begin_define
define|#
directive|define
name|TABLE_ID_DSDT
value|(ACPI_OWNER_ID) 0x8000
end_define

begin_comment
comment|/* Field access granularities */
end_comment

begin_define
define|#
directive|define
name|ACPI_FIELD_BYTE_GRANULARITY
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_FIELD_WORD_GRANULARITY
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_FIELD_DWORD_GRANULARITY
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_FIELD_QWORD_GRANULARITY
value|8
end_define

begin_comment
comment|/*****************************************************************************  *  * Namespace typedefs and structs  *  ****************************************************************************/
end_comment

begin_comment
comment|/* Operational modes of the AML interpreter/scanner */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IMODE_LOAD_PASS1
init|=
literal|0x01
block|,
name|IMODE_LOAD_PASS2
init|=
literal|0x02
block|,
name|IMODE_EXECUTE
init|=
literal|0x0E
block|}
name|OPERATING_MODE
typedef|;
end_typedef

begin_comment
comment|/*  * The Node describes a named object that appears in the AML  * An AcpiNode is used to store Nodes.  *  * DataType is used to differentiate between internal descriptors, and MUST  * be the first byte in this structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_node
block|{
name|UINT8
name|DataType
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
comment|/* Type associated with this name */
name|UINT16
name|OwnerId
decl_stmt|;
name|UINT32
name|Name
decl_stmt|;
comment|/* ACPI Name, always 4 chars per ACPI spec */
name|union
name|acpi_operand_obj
modifier|*
name|Object
decl_stmt|;
comment|/* Pointer to attached ACPI object (optional) */
name|struct
name|acpi_node
modifier|*
name|Child
decl_stmt|;
comment|/* first child */
name|struct
name|acpi_node
modifier|*
name|Peer
decl_stmt|;
comment|/* Next peer*/
name|UINT16
name|ReferenceCount
decl_stmt|;
comment|/* Current count of references and children */
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ACPI_NAMESPACE_NODE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ENTRY_NOT_FOUND
value|NULL
end_define

begin_comment
comment|/* Node flags */
end_comment

begin_define
define|#
directive|define
name|ANOBJ_RESERVED
value|0x01
end_define

begin_define
define|#
directive|define
name|ANOBJ_END_OF_PEER_LIST
value|0x02
end_define

begin_define
define|#
directive|define
name|ANOBJ_DATA_WIDTH_32
value|0x04
end_define

begin_comment
comment|/* Parent table is 64-bits */
end_comment

begin_define
define|#
directive|define
name|ANOBJ_METHOD_ARG
value|0x08
end_define

begin_define
define|#
directive|define
name|ANOBJ_METHOD_LOCAL
value|0x10
end_define

begin_define
define|#
directive|define
name|ANOBJ_METHOD_NO_RETVAL
value|0x20
end_define

begin_define
define|#
directive|define
name|ANOBJ_METHOD_SOME_NO_RETVAL
value|0x40
end_define

begin_define
define|#
directive|define
name|ANOBJ_IS_BIT_OFFSET
value|0x80
end_define

begin_comment
comment|/*  * ACPI Table Descriptor.  One per ACPI table  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|AcpiTableDesc
block|{
name|struct
name|AcpiTableDesc
modifier|*
name|Prev
decl_stmt|;
name|struct
name|AcpiTableDesc
modifier|*
name|Next
decl_stmt|;
name|struct
name|AcpiTableDesc
modifier|*
name|InstalledDesc
decl_stmt|;
name|ACPI_TABLE_HEADER
modifier|*
name|Pointer
decl_stmt|;
name|void
modifier|*
name|BasePointer
decl_stmt|;
name|UINT8
modifier|*
name|AmlStart
decl_stmt|;
name|UINT64
name|PhysicalAddress
decl_stmt|;
name|UINT32
name|AmlLength
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT32
name|Count
decl_stmt|;
name|ACPI_OWNER_ID
name|TableId
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
name|UINT8
name|Allocation
decl_stmt|;
name|BOOLEAN
name|LoadedIntoNamespace
decl_stmt|;
block|}
name|ACPI_TABLE_DESC
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|NATIVE_CHAR
modifier|*
name|SearchFor
decl_stmt|;
name|ACPI_HANDLE
modifier|*
name|List
decl_stmt|;
name|UINT32
modifier|*
name|Count
decl_stmt|;
block|}
name|FIND_CONTEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
block|}
name|NS_SEARCH_DATA
typedef|;
end_typedef

begin_comment
comment|/*  * Predefined Namespace items  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|NATIVE_CHAR
modifier|*
name|Name
decl_stmt|;
name|ACPI_OBJECT_TYPE8
name|Type
decl_stmt|;
name|NATIVE_CHAR
modifier|*
name|Val
decl_stmt|;
block|}
name|PREDEFINED_NAMES
typedef|;
end_typedef

begin_comment
comment|/* Object types used during package copies */
end_comment

begin_define
define|#
directive|define
name|ACPI_COPY_TYPE_SIMPLE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_COPY_TYPE_PACKAGE
value|1
end_define

begin_comment
comment|/* Info structure used to convert external<->internal namestrings */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_namestring_info
block|{
name|NATIVE_CHAR
modifier|*
name|ExternalName
decl_stmt|;
name|NATIVE_CHAR
modifier|*
name|NextExternalChar
decl_stmt|;
name|NATIVE_CHAR
modifier|*
name|InternalName
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT32
name|NumSegments
decl_stmt|;
name|UINT32
name|NumCarats
decl_stmt|;
name|BOOLEAN
name|FullyQualified
decl_stmt|;
block|}
name|ACPI_NAMESTRING_INFO
typedef|;
end_typedef

begin_comment
comment|/* Field creation info */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ACPI_NAMESPACE_NODE
modifier|*
name|RegionNode
decl_stmt|;
name|ACPI_NAMESPACE_NODE
modifier|*
name|FieldNode
decl_stmt|;
name|ACPI_NAMESPACE_NODE
modifier|*
name|RegisterNode
decl_stmt|;
name|ACPI_NAMESPACE_NODE
modifier|*
name|DataRegisterNode
decl_stmt|;
name|UINT32
name|BankValue
decl_stmt|;
name|UINT32
name|FieldBitPosition
decl_stmt|;
name|UINT32
name|FieldBitLength
decl_stmt|;
name|UINT8
name|FieldFlags
decl_stmt|;
name|UINT8
name|Attribute
decl_stmt|;
name|UINT8
name|FieldType
decl_stmt|;
block|}
name|ACPI_CREATE_FIELD_INFO
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************  *  * Event typedefs and structs  *  ****************************************************************************/
end_comment

begin_comment
comment|/* Status bits. */
end_comment

begin_define
define|#
directive|define
name|ACPI_STATUS_PMTIMER
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_STATUS_BUSMASTER
value|0x0010
end_define

begin_define
define|#
directive|define
name|ACPI_STATUS_GLOBAL
value|0x0020
end_define

begin_define
define|#
directive|define
name|ACPI_STATUS_POWER_BUTTON
value|0x0100
end_define

begin_define
define|#
directive|define
name|ACPI_STATUS_SLEEP_BUTTON
value|0x0200
end_define

begin_define
define|#
directive|define
name|ACPI_STATUS_RTC_ALARM
value|0x0400
end_define

begin_comment
comment|/* Enable bits. */
end_comment

begin_define
define|#
directive|define
name|ACPI_ENABLE_PMTIMER
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_ENABLE_GLOBAL
value|0x0020
end_define

begin_define
define|#
directive|define
name|ACPI_ENABLE_POWER_BUTTON
value|0x0100
end_define

begin_define
define|#
directive|define
name|ACPI_ENABLE_SLEEP_BUTTON
value|0x0200
end_define

begin_define
define|#
directive|define
name|ACPI_ENABLE_RTC_ALARM
value|0x0400
end_define

begin_comment
comment|/* Values and addresses of the GPE registers (both banks) */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|StatusAddr
decl_stmt|;
comment|/* Address of status reg */
name|UINT16
name|EnableAddr
decl_stmt|;
comment|/* Address of enable reg */
name|UINT8
name|Status
decl_stmt|;
comment|/* Current value of status reg */
name|UINT8
name|Enable
decl_stmt|;
comment|/* Current value of enable reg */
name|UINT8
name|WakeEnable
decl_stmt|;
comment|/* Mask of bits to keep enabled when sleeping */
name|UINT8
name|GpeBase
decl_stmt|;
comment|/* Base GPE number */
block|}
name|ACPI_GPE_REGISTERS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_GPE_LEVEL_TRIGGERED
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_EDGE_TRIGGERED
value|2
end_define

begin_comment
comment|/* Information about each particular GPE level */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Type
decl_stmt|;
comment|/* Level or Edge */
name|ACPI_HANDLE
name|MethodHandle
decl_stmt|;
comment|/* Method handle for direct (fast) execution */
name|ACPI_GPE_HANDLER
name|Handler
decl_stmt|;
comment|/* Address of handler, if any */
name|void
modifier|*
name|Context
decl_stmt|;
comment|/* Context to be passed to handler */
block|}
name|ACPI_GPE_LEVEL_INFO
typedef|;
end_typedef

begin_comment
comment|/* Information about each particular fixed event */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|ACPI_EVENT_HANDLER
name|Handler
decl_stmt|;
comment|/* Address of handler. */
name|void
modifier|*
name|Context
decl_stmt|;
comment|/* Context to be passed to handler */
block|}
name|ACPI_FIXED_EVENT_INFO
typedef|;
end_typedef

begin_comment
comment|/* Information used during field processing */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|SkipField
decl_stmt|;
name|UINT8
name|FieldFlag
decl_stmt|;
name|UINT32
name|PkgLength
decl_stmt|;
block|}
name|ACPI_FIELD_INFO
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************  *  * Generic "state" object for stacks  *  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CONTROL_NORMAL
value|0xC0
end_define

begin_define
define|#
directive|define
name|CONTROL_CONDITIONAL_EXECUTING
value|0xC1
end_define

begin_define
define|#
directive|define
name|CONTROL_PREDICATE_EXECUTING
value|0xC2
end_define

begin_define
define|#
directive|define
name|CONTROL_PREDICATE_FALSE
value|0xC3
end_define

begin_define
define|#
directive|define
name|CONTROL_PREDICATE_TRUE
value|0xC4
end_define

begin_comment
comment|/* Forward declarations */
end_comment

begin_struct_decl
struct_decl|struct
name|acpi_walk_state
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|acpi_parse_obj
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|acpi_obj_mutex
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|ACPI_STATE_COMMON
comment|/* Two 32-bit fields and a pointer */
define|\
value|UINT8                   DataType;
comment|/* To differentiate various internal objs */
value|\     UINT8                   Flags; \     UINT16                  Value; \     UINT16                  State; \     UINT16                  AcpiEval;  \     void                    *Next; \  typedef struct acpi_common_state
end_define

begin_block
block|{
name|ACPI_STATE_COMMON
block|}
end_block

begin_expr_stmt
name|ACPI_COMMON_STATE
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Update state - used to traverse complex objects such as packages  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_update_state
block|{
name|ACPI_STATE_COMMON
name|union
name|acpi_operand_obj
modifier|*
name|Object
decl_stmt|;
block|}
name|ACPI_UPDATE_STATE
typedef|;
end_typedef

begin_comment
comment|/*  * Pkg state - used to traverse nested package structures  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_pkg_state
block|{
name|ACPI_STATE_COMMON
name|union
name|acpi_operand_obj
modifier|*
name|SourceObject
decl_stmt|;
name|union
name|acpi_operand_obj
modifier|*
name|DestObject
decl_stmt|;
name|struct
name|acpi_walk_state
modifier|*
name|WalkState
decl_stmt|;
name|void
modifier|*
name|ThisTargetObj
decl_stmt|;
name|UINT32
name|NumPackages
decl_stmt|;
name|UINT16
name|Index
decl_stmt|;
block|}
name|ACPI_PKG_STATE
typedef|;
end_typedef

begin_comment
comment|/*  * Control state - one per if/else and while constructs.  * Allows nesting of these constructs  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_control_state
block|{
name|ACPI_STATE_COMMON
name|struct
name|acpi_parse_obj
modifier|*
name|PredicateOp
decl_stmt|;
name|UINT8
modifier|*
name|AmlPredicateStart
decl_stmt|;
comment|/* Start of if/while predicate */
block|}
name|ACPI_CONTROL_STATE
typedef|;
end_typedef

begin_comment
comment|/*  * Scope state - current scope during namespace lookups  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_scope_state
block|{
name|ACPI_STATE_COMMON
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
block|}
name|ACPI_SCOPE_STATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_pscope_state
block|{
name|ACPI_STATE_COMMON
name|struct
name|acpi_parse_obj
modifier|*
name|Op
decl_stmt|;
comment|/* current op being parsed */
name|UINT8
modifier|*
name|ArgEnd
decl_stmt|;
comment|/* current argument end */
name|UINT8
modifier|*
name|PkgEnd
decl_stmt|;
comment|/* current package end */
name|UINT32
name|ArgList
decl_stmt|;
comment|/* next argument to parse */
name|UINT32
name|ArgCount
decl_stmt|;
comment|/* Number of fixed arguments */
block|}
name|ACPI_PSCOPE_STATE
typedef|;
end_typedef

begin_comment
comment|/*  * Thread state - one per thread across multiple walk states.  Multiple walk   * states are created when there are nested control methods executing.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_thread_state
block|{
name|ACPI_STATE_COMMON
name|struct
name|acpi_walk_state
modifier|*
name|WalkStateList
decl_stmt|;
comment|/* Head of list of WalkStates for this thread */
name|union
name|acpi_operand_obj
modifier|*
name|AcquiredMutexList
decl_stmt|;
comment|/* List of all currently acquired mutexes */
name|UINT32
name|ThreadId
decl_stmt|;
comment|/* Running thread ID */
name|UINT16
name|CurrentSyncLevel
decl_stmt|;
comment|/* Mutex Sync (nested acquire) level */
block|}
name|ACPI_THREAD_STATE
typedef|;
end_typedef

begin_comment
comment|/*  * Result values - used to accumulate the results of nested  * AML arguments  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_result_values
block|{
name|ACPI_STATE_COMMON
name|union
name|acpi_operand_obj
modifier|*
name|ObjDesc
index|[
name|OBJ_NUM_OPERANDS
index|]
decl_stmt|;
name|UINT8
name|NumResults
decl_stmt|;
name|UINT8
name|LastInsert
decl_stmt|;
block|}
name|ACPI_RESULT_VALUES
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_PARSE_DOWNWARDS
function_decl|)
parameter_list|(
name|struct
name|acpi_walk_state
modifier|*
name|WalkState
parameter_list|,
name|struct
name|acpi_parse_obj
modifier|*
modifier|*
name|OutOp
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_PARSE_UPWARDS
function_decl|)
parameter_list|(
name|struct
name|acpi_walk_state
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Notify info - used to pass info to the deferred notify  * handler/dispatcher.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_notify_info
block|{
name|ACPI_STATE_COMMON
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
name|union
name|acpi_operand_obj
modifier|*
name|HandlerObj
decl_stmt|;
block|}
name|ACPI_NOTIFY_INFO
typedef|;
end_typedef

begin_comment
comment|/* Generic state is union of structs above */
end_comment

begin_typedef
typedef|typedef
union|union
name|acpi_gen_state
block|{
name|ACPI_COMMON_STATE
name|Common
decl_stmt|;
name|ACPI_CONTROL_STATE
name|Control
decl_stmt|;
name|ACPI_UPDATE_STATE
name|Update
decl_stmt|;
name|ACPI_SCOPE_STATE
name|Scope
decl_stmt|;
name|ACPI_PSCOPE_STATE
name|ParseScope
decl_stmt|;
name|ACPI_PKG_STATE
name|Pkg
decl_stmt|;
name|ACPI_THREAD_STATE
name|Thread
decl_stmt|;
name|ACPI_RESULT_VALUES
name|Results
decl_stmt|;
name|ACPI_NOTIFY_INFO
name|Notify
decl_stmt|;
block|}
name|ACPI_GENERIC_STATE
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************  *  * Interpreter typedefs and structs  *  ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_EXECUTE_OP
function_decl|)
parameter_list|(
name|struct
name|acpi_walk_state
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*****************************************************************************  *  * Parser typedefs and structs  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * AML opcode, name, and argument layout  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_opcode_info
block|{
ifdef|#
directive|ifdef
name|_OPCODE_NAMES
name|NATIVE_CHAR
modifier|*
name|Name
decl_stmt|;
comment|/* Opcode name (debug only) */
endif|#
directive|endif
name|UINT32
name|ParseArgs
decl_stmt|;
comment|/* Grammar/Parse time arguments */
name|UINT32
name|RuntimeArgs
decl_stmt|;
comment|/* Interpret time arguments */
name|UINT32
name|Flags
decl_stmt|;
comment|/* Misc flags */
name|UINT8
name|ObjectType
decl_stmt|;
comment|/* Corresponding internal object type */
name|UINT8
name|Class
decl_stmt|;
comment|/* Opcode class */
name|UINT8
name|Type
decl_stmt|;
comment|/* Opcode type */
block|}
name|ACPI_OPCODE_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|acpi_parse_val
block|{
name|ACPI_INTEGER
name|Integer
decl_stmt|;
comment|/* integer constant (Up to 64 bits) */
name|UINT64_STRUCT
name|Integer64
decl_stmt|;
comment|/* Structure overlay for 2 32-bit Dwords */
name|UINT32
name|Integer32
decl_stmt|;
comment|/* integer constant, 32 bits only */
name|UINT16
name|Integer16
decl_stmt|;
comment|/* integer constant, 16 bits only */
name|UINT8
name|Integer8
decl_stmt|;
comment|/* integer constant, 8 bits only */
name|UINT32
name|Size
decl_stmt|;
comment|/* bytelist or field size */
name|NATIVE_CHAR
modifier|*
name|String
decl_stmt|;
comment|/* NULL terminated string */
name|UINT8
modifier|*
name|Buffer
decl_stmt|;
comment|/* buffer or string */
name|NATIVE_CHAR
modifier|*
name|Name
decl_stmt|;
comment|/* NULL terminated string */
name|struct
name|acpi_parse_obj
modifier|*
name|Arg
decl_stmt|;
comment|/* arguments and contained ops */
block|}
name|ACPI_PARSE_VALUE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_PARSE_COMMON
define|\
value|UINT8                   DataType;
comment|/* To differentiate various internal objs */
value|\     UINT8                   Flags;
comment|/* Type of Op */
value|\     UINT16                  Opcode;
comment|/* AML opcode */
value|\     UINT32                  AmlOffset;
comment|/* offset of declaration in AML */
value|\     struct acpi_parse_obj   *Parent;
comment|/* parent op */
value|\     struct acpi_parse_obj   *Next;
comment|/* next op */
value|\     DEBUG_ONLY_MEMBERS (\     NATIVE_CHAR             OpName[16])
comment|/* op name (debug only) */
value|\
comment|/* NON-DEBUG members below: */
value|\     ACPI_NAMESPACE_NODE     *Node;
comment|/* for use by interpreter */
value|\     ACPI_PARSE_VALUE        Value;
end_define

begin_comment
comment|/* Value or args associated with the opcode */
end_comment

begin_comment
unit|\
comment|/*  * generic operation (eg. If, While, Store)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_parse_obj
block|{
name|ACPI_PARSE_COMMON
block|}
name|ACPI_PARSE_OBJECT
typedef|;
end_typedef

begin_comment
comment|/*  * Extended Op for named ops (Scope, Method, etc.), deferred ops (Methods and OpRegions),  * and bytelists.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_parse2_obj
block|{
name|ACPI_PARSE_COMMON
name|UINT8
modifier|*
name|Data
decl_stmt|;
comment|/* AML body or bytelist data */
name|UINT32
name|Length
decl_stmt|;
comment|/* AML length */
name|UINT32
name|Name
decl_stmt|;
comment|/* 4-byte name or zero if no name */
block|}
name|ACPI_PARSE2_OBJECT
typedef|;
end_typedef

begin_comment
comment|/*  * Parse state - one state per parser invocation and each control  * method.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_parse_state
block|{
name|UINT32
name|AmlSize
decl_stmt|;
name|UINT8
modifier|*
name|AmlStart
decl_stmt|;
comment|/* first AML byte */
name|UINT8
modifier|*
name|Aml
decl_stmt|;
comment|/* next AML byte */
name|UINT8
modifier|*
name|AmlEnd
decl_stmt|;
comment|/* (last + 1) AML byte */
name|UINT8
modifier|*
name|PkgStart
decl_stmt|;
comment|/* current package begin */
name|UINT8
modifier|*
name|PkgEnd
decl_stmt|;
comment|/* current package end */
name|struct
name|acpi_parse_obj
modifier|*
name|StartOp
decl_stmt|;
comment|/* root of parse tree */
name|struct
name|acpi_node
modifier|*
name|StartNode
decl_stmt|;
name|union
name|acpi_gen_state
modifier|*
name|Scope
decl_stmt|;
comment|/* current scope */
name|struct
name|acpi_parse_obj
modifier|*
name|StartScope
decl_stmt|;
block|}
name|ACPI_PARSE_STATE
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************  *  * Hardware and PNP  *  ****************************************************************************/
end_comment

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|PCI_ROOT_HID_STRING
value|"PNP0A03"
end_define

begin_comment
comment|/*  * The #define's and enum below establish an abstract way of identifying what  * register block and register is to be accessed.  Do not change any of the  * values as they are used in switch statements and offset calculations.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BLOCK_MASK
value|0xFF00
end_define

begin_comment
comment|/* Register Block Id    */
end_comment

begin_define
define|#
directive|define
name|BIT_IN_REGISTER_MASK
value|0x00FF
end_define

begin_comment
comment|/* Bit Id in the Register Block Id    */
end_comment

begin_define
define|#
directive|define
name|BYTE_IN_REGISTER_MASK
value|0x00FF
end_define

begin_comment
comment|/* Register Offset in the Register Block    */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BLOCK_ID
parameter_list|(
name|RegId
parameter_list|)
value|(RegId& REGISTER_BLOCK_MASK)
end_define

begin_define
define|#
directive|define
name|REGISTER_BIT_ID
parameter_list|(
name|RegId
parameter_list|)
value|(RegId& BIT_IN_REGISTER_MASK)
end_define

begin_define
define|#
directive|define
name|REGISTER_OFFSET
parameter_list|(
name|RegId
parameter_list|)
value|(RegId& BYTE_IN_REGISTER_MASK)
end_define

begin_comment
comment|/*  * Access Rule  *  To access a Register Bit:  *  -> Use Bit Name (= Register Block Id | Bit Id) defined in the enum.  *  *  To access a Register:  *  -> Use Register Id (= Register Block Id | Register Offset)  */
end_comment

begin_comment
comment|/*  * Register Block Id  */
end_comment

begin_define
define|#
directive|define
name|PM1_STS
value|0x0100
end_define

begin_define
define|#
directive|define
name|PM1_EN
value|0x0200
end_define

begin_define
define|#
directive|define
name|PM1_CONTROL
value|0x0300
end_define

begin_define
define|#
directive|define
name|PM1A_CONTROL
value|0x0400
end_define

begin_define
define|#
directive|define
name|PM1B_CONTROL
value|0x0500
end_define

begin_define
define|#
directive|define
name|PM2_CONTROL
value|0x0600
end_define

begin_define
define|#
directive|define
name|PM_TIMER
value|0x0700
end_define

begin_define
define|#
directive|define
name|PROCESSOR_BLOCK
value|0x0800
end_define

begin_define
define|#
directive|define
name|GPE0_STS_BLOCK
value|0x0900
end_define

begin_define
define|#
directive|define
name|GPE0_EN_BLOCK
value|0x0A00
end_define

begin_define
define|#
directive|define
name|GPE1_STS_BLOCK
value|0x0B00
end_define

begin_define
define|#
directive|define
name|GPE1_EN_BLOCK
value|0x0C00
end_define

begin_define
define|#
directive|define
name|SMI_CMD_BLOCK
value|0x0D00
end_define

begin_comment
comment|/*  * Address space bitmasks for mmio or io spaces  */
end_comment

begin_define
define|#
directive|define
name|SMI_CMD_ADDRESS_SPACE
value|0x01
end_define

begin_define
define|#
directive|define
name|PM1_BLK_ADDRESS_SPACE
value|0x02
end_define

begin_define
define|#
directive|define
name|PM2_CNT_BLK_ADDRESS_SPACE
value|0x04
end_define

begin_define
define|#
directive|define
name|PM_TMR_BLK_ADDRESS_SPACE
value|0x08
end_define

begin_define
define|#
directive|define
name|GPE0_BLK_ADDRESS_SPACE
value|0x10
end_define

begin_define
define|#
directive|define
name|GPE1_BLK_ADDRESS_SPACE
value|0x20
end_define

begin_comment
comment|/*  * Control bit definitions  */
end_comment

begin_define
define|#
directive|define
name|TMR_STS
value|(PM1_STS | 0x01)
end_define

begin_define
define|#
directive|define
name|BM_STS
value|(PM1_STS | 0x02)
end_define

begin_define
define|#
directive|define
name|GBL_STS
value|(PM1_STS | 0x03)
end_define

begin_define
define|#
directive|define
name|PWRBTN_STS
value|(PM1_STS | 0x04)
end_define

begin_define
define|#
directive|define
name|SLPBTN_STS
value|(PM1_STS | 0x05)
end_define

begin_define
define|#
directive|define
name|RTC_STS
value|(PM1_STS | 0x06)
end_define

begin_define
define|#
directive|define
name|WAK_STS
value|(PM1_STS | 0x07)
end_define

begin_define
define|#
directive|define
name|TMR_EN
value|(PM1_EN | 0x01)
end_define

begin_comment
comment|/* no BM_EN */
end_comment

begin_define
define|#
directive|define
name|GBL_EN
value|(PM1_EN | 0x03)
end_define

begin_define
define|#
directive|define
name|PWRBTN_EN
value|(PM1_EN | 0x04)
end_define

begin_define
define|#
directive|define
name|SLPBTN_EN
value|(PM1_EN | 0x05)
end_define

begin_define
define|#
directive|define
name|RTC_EN
value|(PM1_EN | 0x06)
end_define

begin_define
define|#
directive|define
name|WAK_EN
value|(PM1_EN | 0x07)
end_define

begin_define
define|#
directive|define
name|SCI_EN
value|(PM1_CONTROL | 0x01)
end_define

begin_define
define|#
directive|define
name|BM_RLD
value|(PM1_CONTROL | 0x02)
end_define

begin_define
define|#
directive|define
name|GBL_RLS
value|(PM1_CONTROL | 0x03)
end_define

begin_define
define|#
directive|define
name|SLP_TYPE_A
value|(PM1_CONTROL | 0x04)
end_define

begin_define
define|#
directive|define
name|SLP_TYPE_B
value|(PM1_CONTROL | 0x05)
end_define

begin_define
define|#
directive|define
name|SLP_EN
value|(PM1_CONTROL | 0x06)
end_define

begin_define
define|#
directive|define
name|ARB_DIS
value|(PM2_CONTROL | 0x01)
end_define

begin_define
define|#
directive|define
name|TMR_VAL
value|(PM_TIMER | 0x01)
end_define

begin_define
define|#
directive|define
name|GPE0_STS
value|(GPE0_STS_BLOCK | 0x01)
end_define

begin_define
define|#
directive|define
name|GPE0_EN
value|(GPE0_EN_BLOCK  | 0x01)
end_define

begin_define
define|#
directive|define
name|GPE1_STS
value|(GPE1_STS_BLOCK | 0x01)
end_define

begin_define
define|#
directive|define
name|GPE1_EN
value|(GPE1_EN_BLOCK  | 0x01)
end_define

begin_define
define|#
directive|define
name|TMR_STS_MASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|BM_STS_MASK
value|0x0010
end_define

begin_define
define|#
directive|define
name|GBL_STS_MASK
value|0x0020
end_define

begin_define
define|#
directive|define
name|PWRBTN_STS_MASK
value|0x0100
end_define

begin_define
define|#
directive|define
name|SLPBTN_STS_MASK
value|0x0200
end_define

begin_define
define|#
directive|define
name|RTC_STS_MASK
value|0x0400
end_define

begin_define
define|#
directive|define
name|WAK_STS_MASK
value|0x8000
end_define

begin_define
define|#
directive|define
name|ALL_FIXED_STS_BITS
value|(TMR_STS_MASK   | BM_STS_MASK  | GBL_STS_MASK \                                         | PWRBTN_STS_MASK | SLPBTN_STS_MASK \                                         | RTC_STS_MASK | WAK_STS_MASK)
end_define

begin_define
define|#
directive|define
name|TMR_EN_MASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|GBL_EN_MASK
value|0x0020
end_define

begin_define
define|#
directive|define
name|PWRBTN_EN_MASK
value|0x0100
end_define

begin_define
define|#
directive|define
name|SLPBTN_EN_MASK
value|0x0200
end_define

begin_define
define|#
directive|define
name|RTC_EN_MASK
value|0x0400
end_define

begin_define
define|#
directive|define
name|SCI_EN_MASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|BM_RLD_MASK
value|0x0002
end_define

begin_define
define|#
directive|define
name|GBL_RLS_MASK
value|0x0004
end_define

begin_define
define|#
directive|define
name|SLP_TYPE_X_MASK
value|0x1C00
end_define

begin_define
define|#
directive|define
name|SLP_EN_MASK
value|0x2000
end_define

begin_define
define|#
directive|define
name|ARB_DIS_MASK
value|0x0001
end_define

begin_define
define|#
directive|define
name|TMR_VAL_MASK
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|GPE0_STS_MASK
end_define

begin_define
define|#
directive|define
name|GPE0_EN_MASK
end_define

begin_define
define|#
directive|define
name|GPE1_STS_MASK
end_define

begin_define
define|#
directive|define
name|GPE1_EN_MASK
end_define

begin_comment
comment|/*****************************************************************************  *  * Resource descriptors  *  ****************************************************************************/
end_comment

begin_comment
comment|/* ResourceType values */
end_comment

begin_define
define|#
directive|define
name|RESOURCE_TYPE_MEMORY_RANGE
value|0
end_define

begin_define
define|#
directive|define
name|RESOURCE_TYPE_IO_RANGE
value|1
end_define

begin_define
define|#
directive|define
name|RESOURCE_TYPE_BUS_NUMBER_RANGE
value|2
end_define

begin_comment
comment|/* Resource descriptor types and masks */
end_comment

begin_define
define|#
directive|define
name|RESOURCE_DESC_TYPE_LARGE
value|0x80
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_TYPE_SMALL
value|0x00
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_TYPE_MASK
value|0x80
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_SMALL_MASK
value|0x78
end_define

begin_comment
comment|/* Only bits 6:3 contain the type */
end_comment

begin_comment
comment|/*  * Small resource descriptor types  * Note: The 3 length bits (2:0) must be zero  */
end_comment

begin_define
define|#
directive|define
name|RESOURCE_DESC_IRQ_FORMAT
value|0x20
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_DMA_FORMAT
value|0x28
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_START_DEPENDENT
value|0x30
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_END_DEPENDENT
value|0x38
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_IO_PORT
value|0x40
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_FIXED_IO_PORT
value|0x48
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_SMALL_VENDOR
value|0x70
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_END_TAG
value|0x78
end_define

begin_comment
comment|/*  * Large resource descriptor types  */
end_comment

begin_define
define|#
directive|define
name|RESOURCE_DESC_MEMORY_24
value|0x81
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_GENERAL_REGISTER
value|0x82
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_LARGE_VENDOR
value|0x84
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_MEMORY_32
value|0x85
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_FIXED_MEMORY_32
value|0x86
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_DWORD_ADDRESS_SPACE
value|0x87
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_WORD_ADDRESS_SPACE
value|0x88
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_EXTENDED_XRUPT
value|0x89
end_define

begin_define
define|#
directive|define
name|RESOURCE_DESC_QWORD_ADDRESS_SPACE
value|0x8A
end_define

begin_comment
comment|/* String version of device HIDs and UIDs */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEVICE_ID_LENGTH
value|0x09
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|Buffer
index|[
name|ACPI_DEVICE_ID_LENGTH
index|]
decl_stmt|;
block|}
name|ACPI_DEVICE_ID
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************  *  * Miscellaneous  *  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ASCII_ZERO
value|0x30
end_define

begin_comment
comment|/*****************************************************************************  *  * Debugger  *  ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dbmethodinfo
block|{
name|ACPI_HANDLE
name|ThreadGate
decl_stmt|;
name|NATIVE_CHAR
modifier|*
name|Name
decl_stmt|;
name|NATIVE_CHAR
modifier|*
modifier|*
name|Args
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|NumLoops
decl_stmt|;
name|NATIVE_CHAR
name|Pathname
index|[
literal|128
index|]
decl_stmt|;
block|}
name|DB_METHOD_INFO
typedef|;
end_typedef

begin_comment
comment|/*****************************************************************************  *  * Debug  *  ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|ComponentId
decl_stmt|;
name|NATIVE_CHAR
modifier|*
name|ProcName
decl_stmt|;
name|NATIVE_CHAR
modifier|*
name|ModuleName
decl_stmt|;
block|}
name|ACPI_DEBUG_PRINT_INFO
typedef|;
end_typedef

begin_comment
comment|/* Entry for a memory allocation (debug only) */
end_comment

begin_define
define|#
directive|define
name|MEM_MALLOC
value|0
end_define

begin_define
define|#
directive|define
name|MEM_CALLOC
value|1
end_define

begin_define
define|#
directive|define
name|MAX_MODULE_NAME
value|16
end_define

begin_define
define|#
directive|define
name|ACPI_COMMON_DEBUG_MEM_HEADER
define|\
value|struct AcpiDebugMemBlock    *Previous; \     struct AcpiDebugMemBlock    *Next; \     UINT32                      Size; \     UINT32                      Component; \     UINT32                      Line; \     NATIVE_CHAR                 Module[MAX_MODULE_NAME]; \     UINT8                       AllocType;
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|ACPI_COMMON_DEBUG_MEM_HEADER
block|}
name|ACPI_DEBUG_MEM_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|AcpiDebugMemBlock
block|{
name|ACPI_COMMON_DEBUG_MEM_HEADER
name|UINT64
name|UserSpace
decl_stmt|;
block|}
name|ACPI_DEBUG_MEM_BLOCK
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_MEM_LIST_GLOBAL
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_LIST_NSNODE
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_LIST_FIRST_CACHE_LIST
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_LIST_STATE
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_LIST_PSNODE
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_LIST_PSNODE_EXT
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_LIST_OPERAND
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_LIST_WALK
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_LIST_MAX
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_MEM_LISTS
value|7
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|ListHead
decl_stmt|;
name|UINT16
name|LinkOffset
decl_stmt|;
name|UINT16
name|MaxCacheDepth
decl_stmt|;
name|UINT16
name|CacheDepth
decl_stmt|;
name|UINT16
name|ObjectSize
decl_stmt|;
ifdef|#
directive|ifdef
name|ACPI_DBG_TRACK_ALLOCATIONS
comment|/* Statistics for debug memory tracking only */
name|UINT32
name|TotalAllocated
decl_stmt|;
name|UINT32
name|TotalFreed
decl_stmt|;
name|UINT32
name|CurrentTotalSize
decl_stmt|;
name|UINT32
name|CacheRequests
decl_stmt|;
name|UINT32
name|CacheHits
decl_stmt|;
name|char
modifier|*
name|ListName
decl_stmt|;
endif|#
directive|endif
block|}
name|ACPI_MEMORY_LIST
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACLOCAL_H__ */
end_comment

end_unit

