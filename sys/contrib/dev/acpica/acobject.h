begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acobject.h - Definition of ACPI_OPERAND_OBJECT  (Internal object only)  *       $Revision: 1.143 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACOBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|_ACOBJECT_H
end_define

begin_comment
comment|/* acpisrc:StructDefs -- for acpisrc conversion */
end_comment

begin_comment
comment|/*  * The ACPI_OPERAND_OBJECT is used to pass AML operands from the dispatcher  * to the interpreter, and to keep track of the various handlers such as  * address space handlers and notify handlers. The object is a constant  * size in order to allow it to be cached and reused.  *  * Note: The object is optimized to be aligned and will not work if it is  * byte-packed.  */
end_comment

begin_if
if|#
directive|if
name|ACPI_MACHINE_WIDTH
operator|==
literal|64
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|8
name|)
end_pragma

begin_else
else|#
directive|else
end_else

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|4
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*******************************************************************************  *  * Common Descriptors  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Common area for all objects.  *  * DescriptorType is used to differentiate between internal descriptors, and  * must be in the same place across all descriptors  *  * Note: The DescriptorType and Type fields must appear in the identical  * position in both the ACPI_NAMESPACE_NODE and ACPI_OPERAND_OBJECT  * structures.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_OBJECT_COMMON_HEADER
define|\
value|union acpi_operand_object       *NextObject;
comment|/* Objects linked to parent NS node */
value|\     UINT8                           DescriptorType;
comment|/* To differentiate various internal objs */
value|\     UINT8                           Type;
comment|/* ACPI_OBJECT_TYPE */
value|\     UINT16                          ReferenceCount;
comment|/* For object deletion management */
value|\     UINT8                           Flags;
end_define

begin_comment
comment|/*      * Note: There are 3 bytes available here before the      * next natural alignment boundary (for both 32/64 cases)      */
end_comment

begin_comment
comment|/* Values for Flag byte above */
end_comment

begin_define
define|#
directive|define
name|AOPOBJ_AML_CONSTANT
value|0x01
end_define

begin_define
define|#
directive|define
name|AOPOBJ_STATIC_POINTER
value|0x02
end_define

begin_define
define|#
directive|define
name|AOPOBJ_DATA_VALID
value|0x04
end_define

begin_define
define|#
directive|define
name|AOPOBJ_OBJECT_INITIALIZED
value|0x08
end_define

begin_define
define|#
directive|define
name|AOPOBJ_SETUP_COMPLETE
value|0x10
end_define

begin_define
define|#
directive|define
name|AOPOBJ_SINGLE_DATUM
value|0x20
end_define

begin_define
define|#
directive|define
name|AOPOBJ_INVALID
value|0x40
end_define

begin_comment
comment|/* Used if host OS won't allow an OpRegion address */
end_comment

begin_comment
comment|/******************************************************************************  *  * Basic data types  *  *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_common
block|{
name|ACPI_OBJECT_COMMON_HEADER
block|}
name|ACPI_OBJECT_COMMON
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_integer
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|UINT8
name|Fill
index|[
literal|3
index|]
decl_stmt|;
comment|/* Prevent warning on some compilers */
name|ACPI_INTEGER
name|Value
decl_stmt|;
block|}
name|ACPI_OBJECT_INTEGER
typedef|;
end_typedef

begin_comment
comment|/*  * Note: The String and Buffer object must be identical through the Pointer  * and length elements.  There is code that depends on this.  *  * Fields common to both Strings and Buffers  */
end_comment

begin_define
define|#
directive|define
name|ACPI_COMMON_BUFFER_INFO
parameter_list|(
name|_Type
parameter_list|)
define|\
value|_Type                           *Pointer; \     UINT32                          Length;
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_string
comment|/* Null terminated, ASCII characters only */
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_COMMON_BUFFER_INFO
argument_list|(
name|char
argument_list|)
comment|/* String in AML stream or allocated string */
block|}
name|ACPI_OBJECT_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_buffer
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_COMMON_BUFFER_INFO
argument_list|(
name|UINT8
argument_list|)
comment|/* Buffer in AML stream or allocated buffer */
name|UINT32
name|AmlLength
decl_stmt|;
name|UINT8
modifier|*
name|AmlStart
decl_stmt|;
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
comment|/* Link back to parent node */
block|}
name|ACPI_OBJECT_BUFFER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_package
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
comment|/* Link back to parent node */
name|union
name|acpi_operand_object
modifier|*
modifier|*
name|Elements
decl_stmt|;
comment|/* Array of pointers to AcpiObjects */
name|UINT8
modifier|*
name|AmlStart
decl_stmt|;
name|UINT32
name|AmlLength
decl_stmt|;
name|UINT32
name|Count
decl_stmt|;
comment|/* # of elements in package */
block|}
name|ACPI_OBJECT_PACKAGE
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************  *  * Complex data types  *  *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_event
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_SEMAPHORE
name|OsSemaphore
decl_stmt|;
comment|/* Actual OS synchronization object */
block|}
name|ACPI_OBJECT_EVENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_mutex
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|UINT8
name|SyncLevel
decl_stmt|;
comment|/* 0-15, specified in Mutex() call */
name|UINT16
name|AcquisitionDepth
decl_stmt|;
comment|/* Allow multiple Acquires, same thread */
name|ACPI_MUTEX
name|OsMutex
decl_stmt|;
comment|/* Actual OS synchronization object */
name|ACPI_THREAD_ID
name|ThreadId
decl_stmt|;
comment|/* Current owner of the mutex */
name|struct
name|acpi_thread_state
modifier|*
name|OwnerThread
decl_stmt|;
comment|/* Current owner of the mutex */
name|union
name|acpi_operand_object
modifier|*
name|Prev
decl_stmt|;
comment|/* Link for list of acquired mutexes */
name|union
name|acpi_operand_object
modifier|*
name|Next
decl_stmt|;
comment|/* Link for list of acquired mutexes */
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
comment|/* Containing namespace node */
name|UINT8
name|OriginalSyncLevel
decl_stmt|;
comment|/* Owner's original sync level (0-15) */
block|}
name|ACPI_OBJECT_MUTEX
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_region
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|UINT8
name|SpaceId
decl_stmt|;
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
comment|/* Containing namespace node */
name|union
name|acpi_operand_object
modifier|*
name|Handler
decl_stmt|;
comment|/* Handler for region access */
name|union
name|acpi_operand_object
modifier|*
name|Next
decl_stmt|;
name|ACPI_PHYSICAL_ADDRESS
name|Address
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
block|}
name|ACPI_OBJECT_REGION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_method
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|UINT8
name|MethodFlags
decl_stmt|;
name|UINT8
name|ParamCount
decl_stmt|;
name|UINT8
name|SyncLevel
decl_stmt|;
name|union
name|acpi_operand_object
modifier|*
name|Mutex
decl_stmt|;
name|UINT8
modifier|*
name|AmlStart
decl_stmt|;
name|ACPI_INTERNAL_METHOD
name|Implementation
decl_stmt|;
name|UINT32
name|AmlLength
decl_stmt|;
name|UINT8
name|ThreadCount
decl_stmt|;
name|ACPI_OWNER_ID
name|OwnerId
decl_stmt|;
block|}
name|ACPI_OBJECT_METHOD
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************  *  * Objects that can be notified.  All share a common NotifyInfo area.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Common fields for objects that support ASL notifications  */
end_comment

begin_define
define|#
directive|define
name|ACPI_COMMON_NOTIFY_INFO
define|\
value|union acpi_operand_object       *SystemNotify;
comment|/* Handler for system notifies */
value|\     union acpi_operand_object       *DeviceNotify;
comment|/* Handler for driver notifies */
value|\     union acpi_operand_object       *Handler;
end_define

begin_comment
comment|/* Handler for Address space */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_notify_common
comment|/* COMMON NOTIFY for POWER, PROCESSOR, DEVICE, and THERMAL */
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_COMMON_NOTIFY_INFO
block|}
name|ACPI_OBJECT_NOTIFY_COMMON
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_device
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_COMMON_NOTIFY_INFO
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|GpeBlock
decl_stmt|;
block|}
name|ACPI_OBJECT_DEVICE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_power_resource
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_COMMON_NOTIFY_INFO
name|UINT32
name|SystemLevel
decl_stmt|;
name|UINT32
name|ResourceOrder
decl_stmt|;
block|}
name|ACPI_OBJECT_POWER_RESOURCE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_processor
block|{
name|ACPI_OBJECT_COMMON_HEADER
comment|/* The next two fields take advantage of the 3-byte space before NOTIFY_INFO */
name|UINT8
name|ProcId
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
name|ACPI_COMMON_NOTIFY_INFO
name|ACPI_IO_ADDRESS
name|Address
decl_stmt|;
block|}
name|ACPI_OBJECT_PROCESSOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_thermal_zone
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_COMMON_NOTIFY_INFO
block|}
name|ACPI_OBJECT_THERMAL_ZONE
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************  *  * Fields.  All share a common header/info field.  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Common bitfield for the field objects  * "Field Datum"  -- a datum from the actual field object  * "Buffer Datum" -- a datum from a user buffer, read from or to be written to the field  */
end_comment

begin_define
define|#
directive|define
name|ACPI_COMMON_FIELD_INFO
define|\
value|UINT8                           FieldFlags;
comment|/* Access, update, and lock bits */
value|\     UINT8                           Attribute;
comment|/* From AccessAs keyword */
value|\     UINT8                           AccessByteWidth;
comment|/* Read/Write size in bytes */
value|\     ACPI_NAMESPACE_NODE             *Node;
comment|/* Link back to parent node */
value|\     UINT32                          BitLength;
comment|/* Length of field in bits */
value|\     UINT32                          BaseByteOffset;
comment|/* Byte offset within containing object */
value|\     UINT32                          Value;
comment|/* Value to store into the Bank or Index register */
value|\     UINT8                           StartFieldBitOffset;
comment|/* Bit offset within first field datum (0-63) */
value|\     UINT8                           AccessBitWidth;
end_define

begin_comment
comment|/* Read/Write size in bits (8-64) */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_field_common
comment|/* COMMON FIELD (for BUFFER, REGION, BANK, and INDEX fields) */
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_COMMON_FIELD_INFO
expr|union
name|acpi_operand_object
operator|*
name|RegionObj
expr_stmt|;
comment|/* Parent Operation Region object (REGION/BANK fields only) */
block|}
name|ACPI_OBJECT_FIELD_COMMON
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_region_field
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_COMMON_FIELD_INFO
expr|union
name|acpi_operand_object
operator|*
name|RegionObj
expr_stmt|;
comment|/* Containing OpRegion object */
block|}
name|ACPI_OBJECT_REGION_FIELD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_bank_field
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_COMMON_FIELD_INFO
expr|union
name|acpi_operand_object
operator|*
name|RegionObj
expr_stmt|;
comment|/* Containing OpRegion object */
name|union
name|acpi_operand_object
modifier|*
name|BankObj
decl_stmt|;
comment|/* BankSelect Register object */
block|}
name|ACPI_OBJECT_BANK_FIELD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_index_field
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_COMMON_FIELD_INFO
comment|/*      * No "RegionObj" pointer needed since the Index and Data registers      * are each field definitions unto themselves.      */
expr|union
name|acpi_operand_object
operator|*
name|IndexObj
expr_stmt|;
comment|/* Index register */
name|union
name|acpi_operand_object
modifier|*
name|DataObj
decl_stmt|;
comment|/* Data register */
block|}
name|ACPI_OBJECT_INDEX_FIELD
typedef|;
end_typedef

begin_comment
comment|/* The BufferField is different in that it is part of a Buffer, not an OpRegion */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_buffer_field
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_COMMON_FIELD_INFO
expr|union
name|acpi_operand_object
operator|*
name|BufferObj
expr_stmt|;
comment|/* Containing Buffer object */
block|}
name|ACPI_OBJECT_BUFFER_FIELD
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************  *  * Objects for handlers  *  *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_notify_handler
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
comment|/* Parent device */
name|ACPI_NOTIFY_HANDLER
name|Handler
decl_stmt|;
name|void
modifier|*
name|Context
decl_stmt|;
block|}
name|ACPI_OBJECT_NOTIFY_HANDLER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_addr_handler
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|UINT8
name|SpaceId
decl_stmt|;
name|UINT8
name|HandlerFlags
decl_stmt|;
name|ACPI_ADR_SPACE_HANDLER
name|Handler
decl_stmt|;
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
comment|/* Parent device */
name|void
modifier|*
name|Context
decl_stmt|;
name|ACPI_ADR_SPACE_SETUP
name|Setup
decl_stmt|;
name|union
name|acpi_operand_object
modifier|*
name|RegionList
decl_stmt|;
comment|/* regions using this handler */
name|union
name|acpi_operand_object
modifier|*
name|Next
decl_stmt|;
block|}
name|ACPI_OBJECT_ADDR_HANDLER
typedef|;
end_typedef

begin_comment
comment|/* Flags for address handler (HandlerFlags) */
end_comment

begin_define
define|#
directive|define
name|ACPI_ADDR_HANDLER_DEFAULT_INSTALLED
value|0x01
end_define

begin_comment
comment|/******************************************************************************  *  * Special internal objects  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * The Reference object type is used for these opcodes:  * Arg[0-6], Local[0-7], IndexOp, NameOp, ZeroOp, OneOp, OnesOp, DebugOp  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_reference
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|UINT8
name|TargetType
decl_stmt|;
comment|/* Used for IndexOp */
name|UINT16
name|Opcode
decl_stmt|;
name|void
modifier|*
name|Object
decl_stmt|;
comment|/* NameOp=>HANDLE to obj, IndexOp=>ACPI_OPERAND_OBJECT  */
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
name|union
name|acpi_operand_object
modifier|*
modifier|*
name|Where
decl_stmt|;
name|UINT32
name|Offset
decl_stmt|;
comment|/* Used for ArgOp, LocalOp, and IndexOp */
block|}
name|ACPI_OBJECT_REFERENCE
typedef|;
end_typedef

begin_comment
comment|/*  * Extra object is used as additional storage for types that  * have AML code in their declarations (TermArgs) that must be  * evaluated at run time.  *  * Currently: Region and FieldUnit types  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_extra
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_NAMESPACE_NODE
modifier|*
name|Method_REG
decl_stmt|;
comment|/* _REG method for this region (if any) */
name|void
modifier|*
name|RegionContext
decl_stmt|;
comment|/* Region-specific data */
name|UINT8
modifier|*
name|AmlStart
decl_stmt|;
name|UINT32
name|AmlLength
decl_stmt|;
block|}
name|ACPI_OBJECT_EXTRA
typedef|;
end_typedef

begin_comment
comment|/* Additional data that can be attached to namespace nodes */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_data
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|ACPI_OBJECT_HANDLER
name|Handler
decl_stmt|;
name|void
modifier|*
name|Pointer
decl_stmt|;
block|}
name|ACPI_OBJECT_DATA
typedef|;
end_typedef

begin_comment
comment|/* Structure used when objects are cached for reuse */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|acpi_object_cache_list
block|{
name|ACPI_OBJECT_COMMON_HEADER
name|union
name|acpi_operand_object
modifier|*
name|Next
decl_stmt|;
comment|/* Link for object cache and internal lists*/
block|}
name|ACPI_OBJECT_CACHE_LIST
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************  *  * ACPI_OPERAND_OBJECT Descriptor - a giant union of all of the above  *  *****************************************************************************/
end_comment

begin_typedef
typedef|typedef
union|union
name|acpi_operand_object
block|{
name|ACPI_OBJECT_COMMON
name|Common
decl_stmt|;
name|ACPI_OBJECT_INTEGER
name|Integer
decl_stmt|;
name|ACPI_OBJECT_STRING
name|String
decl_stmt|;
name|ACPI_OBJECT_BUFFER
name|Buffer
decl_stmt|;
name|ACPI_OBJECT_PACKAGE
name|Package
decl_stmt|;
name|ACPI_OBJECT_EVENT
name|Event
decl_stmt|;
name|ACPI_OBJECT_METHOD
name|Method
decl_stmt|;
name|ACPI_OBJECT_MUTEX
name|Mutex
decl_stmt|;
name|ACPI_OBJECT_REGION
name|Region
decl_stmt|;
name|ACPI_OBJECT_NOTIFY_COMMON
name|CommonNotify
decl_stmt|;
name|ACPI_OBJECT_DEVICE
name|Device
decl_stmt|;
name|ACPI_OBJECT_POWER_RESOURCE
name|PowerResource
decl_stmt|;
name|ACPI_OBJECT_PROCESSOR
name|Processor
decl_stmt|;
name|ACPI_OBJECT_THERMAL_ZONE
name|ThermalZone
decl_stmt|;
name|ACPI_OBJECT_FIELD_COMMON
name|CommonField
decl_stmt|;
name|ACPI_OBJECT_REGION_FIELD
name|Field
decl_stmt|;
name|ACPI_OBJECT_BUFFER_FIELD
name|BufferField
decl_stmt|;
name|ACPI_OBJECT_BANK_FIELD
name|BankField
decl_stmt|;
name|ACPI_OBJECT_INDEX_FIELD
name|IndexField
decl_stmt|;
name|ACPI_OBJECT_NOTIFY_HANDLER
name|Notify
decl_stmt|;
name|ACPI_OBJECT_ADDR_HANDLER
name|AddressSpace
decl_stmt|;
name|ACPI_OBJECT_REFERENCE
name|Reference
decl_stmt|;
name|ACPI_OBJECT_EXTRA
name|Extra
decl_stmt|;
name|ACPI_OBJECT_DATA
name|Data
decl_stmt|;
name|ACPI_OBJECT_CACHE_LIST
name|Cache
decl_stmt|;
block|}
name|ACPI_OPERAND_OBJECT
typedef|;
end_typedef

begin_comment
comment|/******************************************************************************  *  * ACPI_DESCRIPTOR - objects that share a common descriptor identifier  *  *****************************************************************************/
end_comment

begin_comment
comment|/* Object descriptor types */
end_comment

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_CACHED
value|0x01
end_define

begin_comment
comment|/* Used only when object is cached */
end_comment

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_UPDATE
value|0x03
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_PACKAGE
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_CONTROL
value|0x05
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_RPSCOPE
value|0x06
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_PSCOPE
value|0x07
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_WSCOPE
value|0x08
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_RESULT
value|0x09
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_NOTIFY
value|0x0A
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_STATE_THREAD
value|0x0B
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_WALK
value|0x0C
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_PARSER
value|0x0D
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_OPERAND
value|0x0E
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_NAMED
value|0x0F
end_define

begin_define
define|#
directive|define
name|ACPI_DESC_TYPE_MAX
value|0x0F
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_common_descriptor
block|{
name|void
modifier|*
name|CommonPointer
decl_stmt|;
name|UINT8
name|DescriptorType
decl_stmt|;
comment|/* To differentiate various internal objs */
block|}
name|ACPI_COMMON_DESCRIPTOR
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|acpi_descriptor
block|{
name|ACPI_COMMON_DESCRIPTOR
name|Common
decl_stmt|;
name|ACPI_OPERAND_OBJECT
name|Object
decl_stmt|;
name|ACPI_NAMESPACE_NODE
name|Node
decl_stmt|;
name|ACPI_PARSE_OBJECT
name|Op
decl_stmt|;
block|}
name|ACPI_DESCRIPTOR
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ACOBJECT_H */
end_comment

end_unit

