begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: aclocal.h - Internal data types used across the ACPI subsystem  *       $Revision: 1.247 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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

begin_comment
comment|/* acpisrc:StructDefs -- for acpisrc conversion */
end_comment

begin_define
define|#
directive|define
name|ACPI_WAIT_FOREVER
value|0xFFFF
end_define

begin_comment
comment|/* UINT16, as per ACPI spec */
end_comment

begin_define
define|#
directive|define
name|ACPI_DO_NOT_WAIT
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_SERIALIZED
value|0xFF
end_define

begin_typedef
typedef|typedef
name|UINT32
name|ACPI_MUTEX_HANDLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_GLOBAL_LOCK
value|(ACPI_SEMAPHORE) (-1)
end_define

begin_comment
comment|/* Total number of aml opcodes defined */
end_comment

begin_define
define|#
directive|define
name|AML_NUM_OPCODES
value|0x7F
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
name|acpi_obj_mutex
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|acpi_parse_object
union_decl|;
end_union_decl

begin_comment
comment|/*****************************************************************************  *  * Mutex typedefs and structs  *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * Predefined handles for the mutex objects used within the subsystem  * All mutex objects are automatically created by AcpiUtMutexInitialize.  *  * The acquire/release ordering protocol is implied via this list. Mutexes  * with a lower value must be acquired before mutexes with a higher value.  *  * NOTE: any changes here must be reflected in the AcpiGbl_MutexNames  * table below also!  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MTX_INTERPRETER
value|0
end_define

begin_comment
comment|/* AML Interpreter, main lock */
end_comment

begin_define
define|#
directive|define
name|ACPI_MTX_NAMESPACE
value|1
end_define

begin_comment
comment|/* ACPI Namespace */
end_comment

begin_define
define|#
directive|define
name|ACPI_MTX_TABLES
value|2
end_define

begin_comment
comment|/* Data for ACPI tables */
end_comment

begin_define
define|#
directive|define
name|ACPI_MTX_EVENTS
value|3
end_define

begin_comment
comment|/* Data for ACPI events */
end_comment

begin_define
define|#
directive|define
name|ACPI_MTX_CACHES
value|4
end_define

begin_comment
comment|/* Internal caches, general purposes */
end_comment

begin_define
define|#
directive|define
name|ACPI_MTX_MEMORY
value|5
end_define

begin_comment
comment|/* Debug memory tracking lists */
end_comment

begin_define
define|#
directive|define
name|ACPI_MTX_DEBUG_CMD_COMPLETE
value|6
end_define

begin_comment
comment|/* AML debugger */
end_comment

begin_define
define|#
directive|define
name|ACPI_MTX_DEBUG_CMD_READY
value|7
end_define

begin_comment
comment|/* AML debugger */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_MUTEX
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_MUTEX
value|ACPI_MAX_MUTEX+1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ACPI_DEBUG_OUTPUT
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_DEBUGGER
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DEFINE_ACPI_GLOBALS
end_ifdef

begin_comment
comment|/* Debug names for the mutexes above */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|AcpiGbl_MutexNames
index|[
name|ACPI_NUM_MUTEX
index|]
init|=
block|{
literal|"ACPI_MTX_Interpreter"
block|,
literal|"ACPI_MTX_Tables"
block|,
literal|"ACPI_MTX_Namespace"
block|,
literal|"ACPI_MTX_Events"
block|,
literal|"ACPI_MTX_Caches"
block|,
literal|"ACPI_MTX_Memory"
block|,
literal|"ACPI_MTX_CommandComplete"
block|,
literal|"ACPI_MTX_CommandReady"
block|}
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
comment|/*  * Predefined handles for spinlocks used within the subsystem.  * These spinlocks are created by AcpiUtMutexInitialize  */
end_comment

begin_define
define|#
directive|define
name|ACPI_LOCK_GPES
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_LOCK_HARDWARE
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_LOCK
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_LOCK
value|ACPI_MAX_LOCK+1
end_define

begin_comment
comment|/* Owner IDs are used to track namespace nodes for selective deletion */
end_comment

begin_typedef
typedef|typedef
name|UINT8
name|ACPI_OWNER_ID
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_OWNER_ID_MAX
value|0xFF
end_define

begin_comment
comment|/* This Thread ID means that the mutex is not in use (unlocked) */
end_comment

begin_define
define|#
directive|define
name|ACPI_MUTEX_NOT_ACQUIRED
value|(UINT32) -1
end_define

begin_comment
comment|/* Table for the global mutexes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_mutex_info
block|{
name|ACPI_MUTEX
name|Mutex
decl_stmt|;
name|UINT32
name|UseCount
decl_stmt|;
name|ACPI_THREAD_ID
name|ThreadId
decl_stmt|;
block|}
name|ACPI_MUTEX_INFO
typedef|;
end_typedef

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

begin_define
define|#
directive|define
name|ACPI_ENTRY_NOT_FOUND
value|NULL
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
name|ACPI_IMODE_LOAD_PASS1
init|=
literal|0x01
block|,
name|ACPI_IMODE_LOAD_PASS2
init|=
literal|0x02
block|,
name|ACPI_IMODE_EXECUTE
init|=
literal|0x03
block|}
name|ACPI_INTERPRETER_MODE
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|acpi_name_union
block|{
name|UINT32
name|Integer
decl_stmt|;
name|char
name|Ascii
index|[
literal|4
index|]
decl_stmt|;
block|}
name|ACPI_NAME_UNION
typedef|;
end_typedef

begin_comment
comment|/*  * The Namespace Node describes a named object that appears in the AML.  * DescriptorType is used to differentiate between internal descriptors.  *  * The node is optimized for both 32-bit and 64-bit platforms:  * 20 bytes for the 32-bit case, 32 bytes for the 64-bit case.  *  * Note: The DescriptorType and Type fields must appear in the identical  * position in both the ACPI_NAMESPACE_NODE and ACPI_OPERAND_OBJECT  * structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_namespace_node
block|{
name|union
name|acpi_operand_object
modifier|*
name|Object
decl_stmt|;
comment|/* Interpreter object */
name|UINT8
name|DescriptorType
decl_stmt|;
comment|/* Differentiate object descriptor types */
name|UINT8
name|Type
decl_stmt|;
comment|/* ACPI Type associated with this name */
name|UINT8
name|Flags
decl_stmt|;
comment|/* Miscellaneous flags */
name|ACPI_OWNER_ID
name|OwnerId
decl_stmt|;
comment|/* Node creator */
name|ACPI_NAME_UNION
name|Name
decl_stmt|;
comment|/* ACPI Name, always 4 chars per ACPI spec */
name|struct
name|acpi_namespace_node
modifier|*
name|Child
decl_stmt|;
comment|/* First child */
name|struct
name|acpi_namespace_node
modifier|*
name|Peer
decl_stmt|;
comment|/* Peer. Parent if ANOBJ_END_OF_PEER_LIST set */
comment|/*      * The following fields are used by the ASL compiler and disassembler only      */
ifdef|#
directive|ifdef
name|ACPI_LARGE_NAMESPACE_NODE
name|union
name|acpi_parse_object
modifier|*
name|Op
decl_stmt|;
name|UINT32
name|Value
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
endif|#
directive|endif
block|}
name|ACPI_NAMESPACE_NODE
typedef|;
end_typedef

begin_comment
comment|/* Namespace Node flags */
end_comment

begin_define
define|#
directive|define
name|ANOBJ_END_OF_PEER_LIST
value|0x01
end_define

begin_comment
comment|/* End-of-list, Peer field points to parent */
end_comment

begin_define
define|#
directive|define
name|ANOBJ_TEMPORARY
value|0x02
end_define

begin_comment
comment|/* Node is create by a method and is temporary */
end_comment

begin_define
define|#
directive|define
name|ANOBJ_METHOD_ARG
value|0x04
end_define

begin_comment
comment|/* Node is a method argument */
end_comment

begin_define
define|#
directive|define
name|ANOBJ_METHOD_LOCAL
value|0x08
end_define

begin_comment
comment|/* Node is a method local */
end_comment

begin_define
define|#
directive|define
name|ANOBJ_SUBTREE_HAS_INI
value|0x10
end_define

begin_comment
comment|/* Used to optimize device initialization */
end_comment

begin_define
define|#
directive|define
name|ANOBJ_IS_EXTERNAL
value|0x08
end_define

begin_comment
comment|/* iASL only: This object created via External() */
end_comment

begin_define
define|#
directive|define
name|ANOBJ_METHOD_NO_RETVAL
value|0x10
end_define

begin_comment
comment|/* iASL only: Method has no return value */
end_comment

begin_define
define|#
directive|define
name|ANOBJ_METHOD_SOME_NO_RETVAL
value|0x20
end_define

begin_comment
comment|/* iASL only: Method has at least one return value */
end_comment

begin_define
define|#
directive|define
name|ANOBJ_IS_BIT_OFFSET
value|0x40
end_define

begin_comment
comment|/* iASL only: Reference is a bit offset */
end_comment

begin_define
define|#
directive|define
name|ANOBJ_IS_REFERENCED
value|0x80
end_define

begin_comment
comment|/* iASL only: Object was referenced */
end_comment

begin_comment
comment|/*  * ACPI Table Descriptor.  One per ACPI table  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_table_desc
block|{
name|ACPI_PHYSICAL_ADDRESS
name|Address
decl_stmt|;
name|ACPI_TABLE_HEADER
modifier|*
name|Pointer
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
comment|/* Length fixed at 32 bits */
name|ACPI_NAME_UNION
name|Signature
decl_stmt|;
name|ACPI_OWNER_ID
name|OwnerId
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ACPI_TABLE_DESC
typedef|;
end_typedef

begin_comment
comment|/* Flags for above */
end_comment

begin_define
define|#
directive|define
name|ACPI_TABLE_ORIGIN_UNKNOWN
value|(0)
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_ORIGIN_MAPPED
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_ORIGIN_ALLOCATED
value|(2)
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_ORIGIN_MASK
value|(3)
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_IS_LOADED
value|(4)
end_define

begin_comment
comment|/* One internal RSDT for table management */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_internal_rsdt
block|{
name|ACPI_TABLE_DESC
modifier|*
name|Tables
decl_stmt|;
name|UINT32
name|Count
decl_stmt|;
name|UINT32
name|Size
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ACPI_INTERNAL_RSDT
typedef|;
end_typedef

begin_comment
comment|/* Flags for above */
end_comment

begin_define
define|#
directive|define
name|ACPI_ROOT_ORIGIN_UNKNOWN
value|(0)
end_define

begin_comment
comment|/* ~ORIGIN_ALLOCATED */
end_comment

begin_define
define|#
directive|define
name|ACPI_ROOT_ORIGIN_ALLOCATED
value|(1)
end_define

begin_define
define|#
directive|define
name|ACPI_ROOT_ALLOW_RESIZE
value|(2)
end_define

begin_comment
comment|/* Predefined (fixed) table indexes */
end_comment

begin_define
define|#
directive|define
name|ACPI_TABLE_INDEX_DSDT
value|(0)
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_INDEX_FACS
value|(1)
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_find_context
block|{
name|char
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
name|ACPI_FIND_CONTEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_ns_search_data
block|{
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
block|}
name|ACPI_NS_SEARCH_DATA
typedef|;
end_typedef

begin_comment
comment|/*  * Predefined Namespace items  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_predefined_names
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
name|char
modifier|*
name|Val
decl_stmt|;
block|}
name|ACPI_PREDEFINED_NAMES
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
name|char
modifier|*
name|ExternalName
decl_stmt|;
name|char
modifier|*
name|NextExternalChar
decl_stmt|;
name|char
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
name|acpi_create_field_info
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

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_INTERNAL_METHOD
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
comment|/*  * Bitmapped ACPI types.  Used internally only  */
end_comment

begin_define
define|#
directive|define
name|ACPI_BTYPE_ANY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_INTEGER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_STRING
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_BUFFER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_PACKAGE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_FIELD_UNIT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_DEVICE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_EVENT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_METHOD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_MUTEX
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_REGION
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_POWER
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_PROCESSOR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_THERMAL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_BUFFER_FIELD
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_DDB_HANDLE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_DEBUG_OBJECT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_REFERENCE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_RESOURCE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_COMPUTE_DATA
value|(ACPI_BTYPE_INTEGER | ACPI_BTYPE_STRING | ACPI_BTYPE_BUFFER)
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_DATA
value|(ACPI_BTYPE_COMPUTE_DATA  | ACPI_BTYPE_PACKAGE)
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_DATA_REFERENCE
value|(ACPI_BTYPE_DATA | ACPI_BTYPE_REFERENCE | ACPI_BTYPE_DDB_HANDLE)
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_DEVICE_OBJECTS
value|(ACPI_BTYPE_DEVICE | ACPI_BTYPE_THERMAL | ACPI_BTYPE_PROCESSOR)
end_define

begin_define
define|#
directive|define
name|ACPI_BTYPE_OBJECTS_AND_REFS
value|0x0001FFFF
end_define

begin_comment
comment|/* ARG or LOCAL */
end_comment

begin_define
define|#
directive|define
name|ACPI_BTYPE_ALL_OBJECTS
value|0x0000FFFF
end_define

begin_comment
comment|/*****************************************************************************  *  * Event typedefs and structs  *  ****************************************************************************/
end_comment

begin_comment
comment|/* Dispatch info for each GPE -- either a method or handler, cannot be both */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_handler_info
block|{
name|ACPI_EVENT_HANDLER
name|Address
decl_stmt|;
comment|/* Address of handler, if any */
name|void
modifier|*
name|Context
decl_stmt|;
comment|/* Context to be passed to handler */
name|ACPI_NAMESPACE_NODE
modifier|*
name|MethodNode
decl_stmt|;
comment|/* Method node for this GPE level (saved) */
block|}
name|ACPI_HANDLER_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|acpi_gpe_dispatch_info
block|{
name|ACPI_NAMESPACE_NODE
modifier|*
name|MethodNode
decl_stmt|;
comment|/* Method node for this GPE level */
name|struct
name|acpi_handler_info
modifier|*
name|Handler
decl_stmt|;
block|}
name|ACPI_GPE_DISPATCH_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * Information about a GPE, one per each GPE in an array.  * NOTE: Important to keep this struct as small as possible.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_gpe_event_info
block|{
name|union
name|acpi_gpe_dispatch_info
name|Dispatch
decl_stmt|;
comment|/* Either Method or Handler */
name|struct
name|acpi_gpe_register_info
modifier|*
name|RegisterInfo
decl_stmt|;
comment|/* Backpointer to register info */
name|UINT8
name|Flags
decl_stmt|;
comment|/* Misc info about this GPE */
name|UINT8
name|GpeNumber
decl_stmt|;
comment|/* This GPE */
block|}
name|ACPI_GPE_EVENT_INFO
typedef|;
end_typedef

begin_comment
comment|/* Information about a GPE register pair, one per each status/enable pair in an array */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_gpe_register_info
block|{
name|ACPI_GENERIC_ADDRESS
name|StatusAddress
decl_stmt|;
comment|/* Address of status reg */
name|ACPI_GENERIC_ADDRESS
name|EnableAddress
decl_stmt|;
comment|/* Address of enable reg */
name|UINT8
name|EnableForWake
decl_stmt|;
comment|/* GPEs to keep enabled when sleeping */
name|UINT8
name|EnableForRun
decl_stmt|;
comment|/* GPEs to keep enabled when running */
name|UINT8
name|BaseGpeNumber
decl_stmt|;
comment|/* Base GPE number for this register */
block|}
name|ACPI_GPE_REGISTER_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * Information about a GPE register block, one per each installed block --  * GPE0, GPE1, and one per each installed GPE Block Device.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_gpe_block_info
block|{
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
name|struct
name|acpi_gpe_block_info
modifier|*
name|Previous
decl_stmt|;
name|struct
name|acpi_gpe_block_info
modifier|*
name|Next
decl_stmt|;
name|struct
name|acpi_gpe_xrupt_info
modifier|*
name|XruptBlock
decl_stmt|;
comment|/* Backpointer to interrupt block */
name|ACPI_GPE_REGISTER_INFO
modifier|*
name|RegisterInfo
decl_stmt|;
comment|/* One per GPE register pair */
name|ACPI_GPE_EVENT_INFO
modifier|*
name|EventInfo
decl_stmt|;
comment|/* One for each GPE */
name|ACPI_GENERIC_ADDRESS
name|BlockAddress
decl_stmt|;
comment|/* Base address of the block */
name|UINT32
name|RegisterCount
decl_stmt|;
comment|/* Number of register pairs in block */
name|UINT8
name|BlockBaseNumber
decl_stmt|;
comment|/* Base GPE number for this block */
block|}
name|ACPI_GPE_BLOCK_INFO
typedef|;
end_typedef

begin_comment
comment|/* Information about GPE interrupt handlers, one per each interrupt level used for GPEs */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_gpe_xrupt_info
block|{
name|struct
name|acpi_gpe_xrupt_info
modifier|*
name|Previous
decl_stmt|;
name|struct
name|acpi_gpe_xrupt_info
modifier|*
name|Next
decl_stmt|;
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|GpeBlockListHead
decl_stmt|;
comment|/* List of GPE blocks for this xrupt */
name|UINT32
name|InterruptNumber
decl_stmt|;
comment|/* System interrupt number */
block|}
name|ACPI_GPE_XRUPT_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_gpe_walk_info
block|{
name|ACPI_NAMESPACE_NODE
modifier|*
name|GpeDevice
decl_stmt|;
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|GpeBlock
decl_stmt|;
block|}
name|ACPI_GPE_WALK_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_GPE_CALLBACK
function_decl|)
parameter_list|(
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|GpeXruptInfo
parameter_list|,
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|GpeBlock
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Information about each particular fixed event */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_fixed_event_handler
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
name|ACPI_FIXED_EVENT_HANDLER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_fixed_event_info
block|{
name|UINT8
name|StatusRegisterId
decl_stmt|;
name|UINT8
name|EnableRegisterId
decl_stmt|;
name|UINT16
name|StatusBitMask
decl_stmt|;
name|UINT16
name|EnableBitMask
decl_stmt|;
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
name|acpi_field_info
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
name|ACPI_CONTROL_NORMAL
value|0xC0
end_define

begin_define
define|#
directive|define
name|ACPI_CONTROL_CONDITIONAL_EXECUTING
value|0xC1
end_define

begin_define
define|#
directive|define
name|ACPI_CONTROL_PREDICATE_EXECUTING
value|0xC2
end_define

begin_define
define|#
directive|define
name|ACPI_CONTROL_PREDICATE_FALSE
value|0xC3
end_define

begin_define
define|#
directive|define
name|ACPI_CONTROL_PREDICATE_TRUE
value|0xC4
end_define

begin_define
define|#
directive|define
name|ACPI_STATE_COMMON
define|\
value|void                            *Next; \     UINT8                           DescriptorType;
comment|/* To differentiate various internal objs */
value|\     UINT8                           Flags; \     UINT16                          Value; \     UINT16                          State;
end_define

begin_comment
comment|/* There are 2 bytes available here until the next natural alignment boundary */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_common_state
block|{
name|ACPI_STATE_COMMON
block|}
name|ACPI_COMMON_STATE
typedef|;
end_typedef

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
name|acpi_operand_object
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
name|UINT16
name|Index
decl_stmt|;
name|union
name|acpi_operand_object
modifier|*
name|SourceObject
decl_stmt|;
name|union
name|acpi_operand_object
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
name|UINT16
name|Opcode
decl_stmt|;
name|union
name|acpi_parse_object
modifier|*
name|PredicateOp
decl_stmt|;
name|UINT8
modifier|*
name|AmlPredicateStart
decl_stmt|;
comment|/* Start of if/while predicate */
name|UINT8
modifier|*
name|PackageEnd
decl_stmt|;
comment|/* End of if/while block */
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
name|UINT32
name|ArgCount
decl_stmt|;
comment|/* Number of fixed arguments */
name|union
name|acpi_parse_object
modifier|*
name|Op
decl_stmt|;
comment|/* Current op being parsed */
name|UINT8
modifier|*
name|ArgEnd
decl_stmt|;
comment|/* Current argument end */
name|UINT8
modifier|*
name|PkgEnd
decl_stmt|;
comment|/* Current package end */
name|UINT32
name|ArgList
decl_stmt|;
comment|/* Next argument to parse */
block|}
name|ACPI_PSCOPE_STATE
typedef|;
end_typedef

begin_comment
comment|/*  * Thread state - one per thread across multiple walk states.  Multiple walk  * states are created when there are nested control methods executing.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_thread_state
block|{
name|ACPI_STATE_COMMON
name|UINT8
name|CurrentSyncLevel
decl_stmt|;
comment|/* Mutex Sync (nested acquire) level */
name|struct
name|acpi_walk_state
modifier|*
name|WalkStateList
decl_stmt|;
comment|/* Head of list of WalkStates for this thread */
name|union
name|acpi_operand_object
modifier|*
name|AcquiredMutexList
decl_stmt|;
comment|/* List of all currently acquired mutexes */
name|ACPI_THREAD_ID
name|ThreadId
decl_stmt|;
comment|/* Running thread ID */
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
name|acpi_operand_object
modifier|*
name|ObjDesc
index|[
name|ACPI_RESULTS_FRAME_OBJ_NUM
index|]
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
name|union
name|acpi_parse_object
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
name|acpi_operand_object
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
name|acpi_generic_state
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
if|#
directive|if
name|defined
argument_list|(
name|ACPI_DISASSEMBLER
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_DEBUG_OUTPUT
argument_list|)
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* Opcode name (disassembler/debug only) */
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
name|UINT16
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
name|acpi_parse_value
block|{
name|ACPI_INTEGER
name|Integer
decl_stmt|;
comment|/* Integer constant (Up to 64 bits) */
name|UINT64_STRUCT
name|Integer64
decl_stmt|;
comment|/* Structure overlay for 2 32-bit Dwords */
name|UINT32
name|Size
decl_stmt|;
comment|/* bytelist or field size */
name|char
modifier|*
name|String
decl_stmt|;
comment|/* NULL terminated string */
name|UINT8
modifier|*
name|Buffer
decl_stmt|;
comment|/* buffer or string */
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* NULL terminated string */
name|union
name|acpi_parse_object
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
value|union acpi_parse_object         *Parent;
comment|/* Parent op */
value|\     UINT8                           DescriptorType;
comment|/* To differentiate various internal objs */
value|\     UINT8                           Flags;
comment|/* Type of Op */
value|\     UINT16                          AmlOpcode;
comment|/* AML opcode */
value|\     UINT32                          AmlOffset;
comment|/* Offset of declaration in AML */
value|\     union acpi_parse_object         *Next;
comment|/* Next op */
value|\     ACPI_NAMESPACE_NODE             *Node;
comment|/* For use by interpreter */
value|\     ACPI_PARSE_VALUE                Value;
comment|/* Value or args associated with the opcode */
value|\     UINT8                           ArgListLength;
comment|/* Number of elements in the arg list */
value|\     ACPI_DISASM_ONLY_MEMBERS (\     UINT8                           DisasmFlags;
comment|/* Used during AML disassembly */
value|\     UINT8                           DisasmOpcode;
comment|/* Subtype used for disassembly */
value|\     char                            AmlOpName[16])
end_define

begin_comment
comment|/* Op name (debug only) */
end_comment

begin_define
define|#
directive|define
name|ACPI_DASM_BUFFER
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_DASM_RESOURCE
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_DASM_STRING
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_DASM_UNICODE
value|0x03
end_define

begin_define
define|#
directive|define
name|ACPI_DASM_EISAID
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_DASM_MATCHOP
value|0x05
end_define

begin_define
define|#
directive|define
name|ACPI_DASM_LNOT_PREFIX
value|0x06
end_define

begin_define
define|#
directive|define
name|ACPI_DASM_LNOT_SUFFIX
value|0x07
end_define

begin_define
define|#
directive|define
name|ACPI_DASM_IGNORE
value|0x08
end_define

begin_comment
comment|/*  * Generic operation (for example:  If, While, Store)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_parse_obj_common
block|{
name|ACPI_PARSE_COMMON
block|}
name|ACPI_PARSE_OBJ_COMMON
typedef|;
end_typedef

begin_comment
comment|/*  * Extended Op for named ops (Scope, Method, etc.), deferred ops (Methods and OpRegions),  * and bytelists.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_parse_obj_named
block|{
name|ACPI_PARSE_COMMON
name|UINT8
modifier|*
name|Path
decl_stmt|;
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
name|ACPI_PARSE_OBJ_NAMED
typedef|;
end_typedef

begin_comment
comment|/* This version is used by the iASL compiler only */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_PARSEOP_NAME
value|20
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_parse_obj_asl
block|{
name|ACPI_PARSE_COMMON
name|union
name|acpi_parse_object
modifier|*
name|Child
decl_stmt|;
name|union
name|acpi_parse_object
modifier|*
name|ParentMethod
decl_stmt|;
name|char
modifier|*
name|Filename
decl_stmt|;
name|char
modifier|*
name|ExternalName
decl_stmt|;
name|char
modifier|*
name|Namepath
decl_stmt|;
name|char
name|NameSeg
index|[
literal|4
index|]
decl_stmt|;
name|UINT32
name|ExtraValue
decl_stmt|;
name|UINT32
name|Column
decl_stmt|;
name|UINT32
name|LineNumber
decl_stmt|;
name|UINT32
name|LogicalLineNumber
decl_stmt|;
name|UINT32
name|LogicalByteOffset
decl_stmt|;
name|UINT32
name|EndLine
decl_stmt|;
name|UINT32
name|EndLogicalLine
decl_stmt|;
name|UINT32
name|AcpiBtype
decl_stmt|;
name|UINT32
name|AmlLength
decl_stmt|;
name|UINT32
name|AmlSubtreeLength
decl_stmt|;
name|UINT32
name|FinalAmlLength
decl_stmt|;
name|UINT32
name|FinalAmlOffset
decl_stmt|;
name|UINT32
name|CompileFlags
decl_stmt|;
name|UINT16
name|ParseOpcode
decl_stmt|;
name|UINT8
name|AmlOpcodeLength
decl_stmt|;
name|UINT8
name|AmlPkgLenBytes
decl_stmt|;
name|UINT8
name|Extra
decl_stmt|;
name|char
name|ParseOpName
index|[
name|ACPI_MAX_PARSEOP_NAME
index|]
decl_stmt|;
block|}
name|ACPI_PARSE_OBJ_ASL
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|acpi_parse_object
block|{
name|ACPI_PARSE_OBJ_COMMON
name|Common
decl_stmt|;
name|ACPI_PARSE_OBJ_NAMED
name|Named
decl_stmt|;
name|ACPI_PARSE_OBJ_ASL
name|Asl
decl_stmt|;
block|}
name|ACPI_PARSE_OBJECT
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
name|UINT8
modifier|*
name|AmlStart
decl_stmt|;
comment|/* First AML byte */
name|UINT8
modifier|*
name|Aml
decl_stmt|;
comment|/* Next AML byte */
name|UINT8
modifier|*
name|AmlEnd
decl_stmt|;
comment|/* (last + 1) AML byte */
name|UINT8
modifier|*
name|PkgStart
decl_stmt|;
comment|/* Current package begin */
name|UINT8
modifier|*
name|PkgEnd
decl_stmt|;
comment|/* Current package end */
name|union
name|acpi_parse_object
modifier|*
name|StartOp
decl_stmt|;
comment|/* Root of parse tree */
name|struct
name|acpi_namespace_node
modifier|*
name|StartNode
decl_stmt|;
name|union
name|acpi_generic_state
modifier|*
name|Scope
decl_stmt|;
comment|/* Current scope */
name|union
name|acpi_parse_object
modifier|*
name|StartScope
decl_stmt|;
name|UINT32
name|AmlSize
decl_stmt|;
block|}
name|ACPI_PARSE_STATE
typedef|;
end_typedef

begin_comment
comment|/* Parse object flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_PARSEOP_GENERIC
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_PARSEOP_NAMED
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_PARSEOP_DEFERRED
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_PARSEOP_BYTELIST
value|0x08
end_define

begin_define
define|#
directive|define
name|ACPI_PARSEOP_IN_STACK
value|0x10
end_define

begin_define
define|#
directive|define
name|ACPI_PARSEOP_TARGET
value|0x20
end_define

begin_define
define|#
directive|define
name|ACPI_PARSEOP_IN_CACHE
value|0x80
end_define

begin_comment
comment|/* Parse object DisasmFlags */
end_comment

begin_define
define|#
directive|define
name|ACPI_PARSEOP_IGNORE
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_PARSEOP_PARAMLIST
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_PARSEOP_EMPTY_TERMLIST
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_PARSEOP_SPECIAL
value|0x10
end_define

begin_comment
comment|/*****************************************************************************  *  * Hardware (ACPI registers) and PNP  *  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PCI_ROOT_HID_STRING
value|"PNP0A03"
end_define

begin_define
define|#
directive|define
name|PCI_EXPRESS_ROOT_HID_STRING
value|"PNP0A08"
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_bit_register_info
block|{
name|UINT8
name|ParentRegister
decl_stmt|;
name|UINT8
name|BitPosition
decl_stmt|;
name|UINT16
name|AccessBitMask
decl_stmt|;
block|}
name|ACPI_BIT_REGISTER_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * Some ACPI registers have bits that must be ignored -- meaning that they  * must be preserved.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_PM1_STATUS_PRESERVED_BITS
value|0x0800
end_define

begin_comment
comment|/* Bit 11 */
end_comment

begin_define
define|#
directive|define
name|ACPI_PM1_CONTROL_PRESERVED_BITS
value|0x0201
end_define

begin_comment
comment|/* Bit 9, Bit 0 (SCI_EN) */
end_comment

begin_comment
comment|/*  * Register IDs  * These are the full ACPI registers  */
end_comment

begin_define
define|#
directive|define
name|ACPI_REGISTER_PM1_STATUS
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_REGISTER_PM1_ENABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_REGISTER_PM1_CONTROL
value|0x03
end_define

begin_define
define|#
directive|define
name|ACPI_REGISTER_PM1A_CONTROL
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_REGISTER_PM1B_CONTROL
value|0x05
end_define

begin_define
define|#
directive|define
name|ACPI_REGISTER_PM2_CONTROL
value|0x06
end_define

begin_define
define|#
directive|define
name|ACPI_REGISTER_PM_TIMER
value|0x07
end_define

begin_define
define|#
directive|define
name|ACPI_REGISTER_PROCESSOR_BLOCK
value|0x08
end_define

begin_define
define|#
directive|define
name|ACPI_REGISTER_SMI_COMMAND_BLOCK
value|0x09
end_define

begin_comment
comment|/* Masks used to access the BitRegisters */
end_comment

begin_define
define|#
directive|define
name|ACPI_BITMASK_TIMER_STATUS
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_BUS_MASTER_STATUS
value|0x0010
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_GLOBAL_LOCK_STATUS
value|0x0020
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_POWER_BUTTON_STATUS
value|0x0100
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_SLEEP_BUTTON_STATUS
value|0x0200
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_RT_CLOCK_STATUS
value|0x0400
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_PCIEXP_WAKE_STATUS
value|0x4000
end_define

begin_comment
comment|/* ACPI 3.0 */
end_comment

begin_define
define|#
directive|define
name|ACPI_BITMASK_WAKE_STATUS
value|0x8000
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_ALL_FIXED_STATUS
value|(\     ACPI_BITMASK_TIMER_STATUS          | \     ACPI_BITMASK_BUS_MASTER_STATUS     | \     ACPI_BITMASK_GLOBAL_LOCK_STATUS    | \     ACPI_BITMASK_POWER_BUTTON_STATUS   | \     ACPI_BITMASK_SLEEP_BUTTON_STATUS   | \     ACPI_BITMASK_RT_CLOCK_STATUS       | \     ACPI_BITMASK_WAKE_STATUS)
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_TIMER_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_GLOBAL_LOCK_ENABLE
value|0x0020
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_POWER_BUTTON_ENABLE
value|0x0100
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_SLEEP_BUTTON_ENABLE
value|0x0200
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_RT_CLOCK_ENABLE
value|0x0400
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_PCIEXP_WAKE_DISABLE
value|0x4000
end_define

begin_comment
comment|/* ACPI 3.0 */
end_comment

begin_define
define|#
directive|define
name|ACPI_BITMASK_SCI_ENABLE
value|0x0001
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_BUS_MASTER_RLD
value|0x0002
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_GLOBAL_LOCK_RELEASE
value|0x0004
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_SLEEP_TYPE_X
value|0x1C00
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_SLEEP_ENABLE
value|0x2000
end_define

begin_define
define|#
directive|define
name|ACPI_BITMASK_ARB_DISABLE
value|0x0001
end_define

begin_comment
comment|/* Raw bit position of each BitRegister */
end_comment

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_TIMER_STATUS
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_BUS_MASTER_STATUS
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_GLOBAL_LOCK_STATUS
value|0x05
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_POWER_BUTTON_STATUS
value|0x08
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_SLEEP_BUTTON_STATUS
value|0x09
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_RT_CLOCK_STATUS
value|0x0A
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_PCIEXP_WAKE_STATUS
value|0x0E
end_define

begin_comment
comment|/* ACPI 3.0 */
end_comment

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_WAKE_STATUS
value|0x0F
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_TIMER_ENABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_GLOBAL_LOCK_ENABLE
value|0x05
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_POWER_BUTTON_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_SLEEP_BUTTON_ENABLE
value|0x09
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_RT_CLOCK_ENABLE
value|0x0A
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_PCIEXP_WAKE_DISABLE
value|0x0E
end_define

begin_comment
comment|/* ACPI 3.0 */
end_comment

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_SCI_ENABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_BUS_MASTER_RLD
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_GLOBAL_LOCK_RELEASE
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_SLEEP_TYPE_X
value|0x0A
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_SLEEP_ENABLE
value|0x0D
end_define

begin_define
define|#
directive|define
name|ACPI_BITPOSITION_ARB_DISABLE
value|0x00
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
name|ACPI_ADDRESS_TYPE_MEMORY_RANGE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_ADDRESS_TYPE_IO_RANGE
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_ADDRESS_TYPE_BUS_NUMBER_RANGE
value|2
end_define

begin_comment
comment|/* Resource descriptor types and masks */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_LARGE
value|0x80
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_SMALL
value|0x00
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_SMALL_MASK
value|0x78
end_define

begin_comment
comment|/* Bits 6:3 contain the type */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_SMALL_LENGTH_MASK
value|0x07
end_define

begin_comment
comment|/* Bits 2:0 contain the length */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_LARGE_MASK
value|0x7F
end_define

begin_comment
comment|/* Bits 6:0 contain the type */
end_comment

begin_comment
comment|/*  * Small resource descriptor "names" as defined by the ACPI specification.  * Note: Bits 2:0 are used for the descriptor length  */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_IRQ
value|0x20
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_DMA
value|0x28
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_START_DEPENDENT
value|0x30
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_END_DEPENDENT
value|0x38
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_IO
value|0x40
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_FIXED_IO
value|0x48
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_RESERVED_S1
value|0x50
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_RESERVED_S2
value|0x58
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_RESERVED_S3
value|0x60
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_RESERVED_S4
value|0x68
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_VENDOR_SMALL
value|0x70
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_END_TAG
value|0x78
end_define

begin_comment
comment|/*  * Large resource descriptor "names" as defined by the ACPI specification.  * Note: includes the Large Descriptor bit in bit[7]  */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_MEMORY24
value|0x81
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_GENERIC_REGISTER
value|0x82
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_RESERVED_L1
value|0x83
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_VENDOR_LARGE
value|0x84
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_MEMORY32
value|0x85
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_FIXED_MEMORY32
value|0x86
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_ADDRESS32
value|0x87
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_ADDRESS16
value|0x88
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_EXTENDED_IRQ
value|0x89
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_ADDRESS64
value|0x8A
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_EXTENDED_ADDRESS64
value|0x8B
end_define

begin_define
define|#
directive|define
name|ACPI_RESOURCE_NAME_LARGE_MAX
value|0x8B
end_define

begin_comment
comment|/*****************************************************************************  *  * Miscellaneous  *  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACPI_ASCII_ZERO
value|0x30
end_define

begin_comment
comment|/*****************************************************************************  *  * Debugger  *  ****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_db_method_info
block|{
name|ACPI_HANDLE
name|MainThreadGate
decl_stmt|;
name|ACPI_HANDLE
name|ThreadCompleteGate
decl_stmt|;
name|UINT32
modifier|*
name|Threads
decl_stmt|;
name|UINT32
name|NumThreads
decl_stmt|;
name|UINT32
name|NumCreated
decl_stmt|;
name|UINT32
name|NumCompleted
decl_stmt|;
name|char
modifier|*
name|Name
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|UINT32
name|NumLoops
decl_stmt|;
name|char
name|Pathname
index|[
literal|128
index|]
decl_stmt|;
name|char
modifier|*
modifier|*
name|Args
decl_stmt|;
comment|/*      * Arguments to be passed to method for the command      * Threads -      *   the Number of threads, ID of current thread and      *   Index of current thread inside all them created.      */
name|char
name|InitArgs
decl_stmt|;
name|char
modifier|*
name|Arguments
index|[
literal|4
index|]
decl_stmt|;
name|char
name|NumThreadsStr
index|[
literal|11
index|]
decl_stmt|;
name|char
name|IdOfThreadStr
index|[
literal|11
index|]
decl_stmt|;
name|char
name|IndexOfThreadStr
index|[
literal|11
index|]
decl_stmt|;
block|}
name|ACPI_DB_METHOD_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_integrity_info
block|{
name|UINT32
name|Nodes
decl_stmt|;
name|UINT32
name|Objects
decl_stmt|;
block|}
name|ACPI_INTEGRITY_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACPI_DB_REDIRECTABLE_OUTPUT
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_DB_CONSOLE_OUTPUT
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_DB_DUPLICATE_OUTPUT
value|0x03
end_define

begin_comment
comment|/*****************************************************************************  *  * Debug  *  ****************************************************************************/
end_comment

begin_comment
comment|/* Entry for a memory allocation (debug only) */
end_comment

begin_define
define|#
directive|define
name|ACPI_MEM_MALLOC
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_MEM_CALLOC
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_MODULE_NAME
value|16
end_define

begin_define
define|#
directive|define
name|ACPI_COMMON_DEBUG_MEM_HEADER
define|\
value|struct acpi_debug_mem_block     *Previous; \     struct acpi_debug_mem_block     *Next; \     UINT32                          Size; \     UINT32                          Component; \     UINT32                          Line; \     char                            Module[ACPI_MAX_MODULE_NAME]; \     UINT8                           AllocType;
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_debug_mem_header
block|{
name|ACPI_COMMON_DEBUG_MEM_HEADER
block|}
name|ACPI_DEBUG_MEM_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_debug_mem_block
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
name|ACPI_MEM_LIST_MAX
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_MEM_LISTS
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_memory_list
block|{
name|char
modifier|*
name|ListName
decl_stmt|;
name|void
modifier|*
name|ListHead
decl_stmt|;
name|UINT16
name|ObjectSize
decl_stmt|;
name|UINT16
name|MaxDepth
decl_stmt|;
name|UINT16
name|CurrentDepth
decl_stmt|;
name|UINT16
name|LinkOffset
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
name|MaxOccupied
decl_stmt|;
name|UINT32
name|TotalSize
decl_stmt|;
name|UINT32
name|CurrentTotalSize
decl_stmt|;
name|UINT32
name|Requests
decl_stmt|;
name|UINT32
name|Hits
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

