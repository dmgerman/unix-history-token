begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acconfig.h - Global configuration constants  *       $Revision: 1.234 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACCONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|_ACCONFIG_H
end_define

begin_comment
comment|/******************************************************************************  *  * Configuration options  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * ACPI_DEBUG_OUTPUT    - This switch enables all the debug facilities of the  *                        ACPI subsystem.  This includes the DEBUG_PRINT output  *                        statements.  When disabled, all DEBUG_PRINT  *                        statements are compiled out.  *  * ACPI_APPLICATION     - Use this switch if the subsystem is going to be run  *                        at the application level.  *  */
end_comment

begin_comment
comment|/* Current ACPICA subsystem version in YYYYMMDD format */
end_comment

begin_define
define|#
directive|define
name|ACPI_CA_VERSION
value|0x20070320
end_define

begin_comment
comment|/*  * OS name, used for the _OS object.  The _OS object is essentially obsolete,  * but there is a large base of ASL/AML code in existing machines that check  * for the string below.  The use of this string usually guarantees that  * the ASL will execute down the most tested code path.  Also, there is some  * code that will not execute the _OSI method unless _OS matches the string  * below.  Therefore, change this string at your own risk.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_OS_NAME
value|"Microsoft Windows NT"
end_define

begin_comment
comment|/* Maximum objects in the various object caches */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_STATE_CACHE_DEPTH
value|96
end_define

begin_comment
comment|/* State objects */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_PARSE_CACHE_DEPTH
value|96
end_define

begin_comment
comment|/* Parse tree objects */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_EXTPARSE_CACHE_DEPTH
value|96
end_define

begin_comment
comment|/* Parse tree objects */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_OBJECT_CACHE_DEPTH
value|96
end_define

begin_comment
comment|/* Interpreter operand objects */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_NAMESPACE_CACHE_DEPTH
value|96
end_define

begin_comment
comment|/* Namespace objects */
end_comment

begin_comment
comment|/*  * Should the subsystem abort the loading of an ACPI table if the  * table checksum is incorrect?  */
end_comment

begin_define
define|#
directive|define
name|ACPI_CHECKSUM_ABORT
value|FALSE
end_define

begin_comment
comment|/******************************************************************************  *  * Subsystem Constants  *  *****************************************************************************/
end_comment

begin_comment
comment|/* Version of ACPI supported */
end_comment

begin_define
define|#
directive|define
name|ACPI_CA_SUPPORT_LEVEL
value|3
end_define

begin_comment
comment|/* Maximum count for a semaphore object */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_SEMAPHORE_COUNT
value|256
end_define

begin_comment
comment|/* Maximum object reference count (detects object deletion issues) */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_REFERENCE_COUNT
value|0x800
end_define

begin_comment
comment|/* Size of cached memory mapping for system memory operation region */
end_comment

begin_define
define|#
directive|define
name|ACPI_SYSMEM_REGION_WINDOW_SIZE
value|4096
end_define

begin_comment
comment|/* OwnerId tracking. 8 entries allows for 255 OwnerIds */
end_comment

begin_define
define|#
directive|define
name|ACPI_NUM_OWNERID_MASKS
value|8
end_define

begin_comment
comment|/* Size of the root table array is increased by this increment */
end_comment

begin_define
define|#
directive|define
name|ACPI_ROOT_TABLE_SIZE_INCREMENT
value|4
end_define

begin_comment
comment|/******************************************************************************  *  * ACPI Specification constants (Do not change unless the specification changes)  *  *****************************************************************************/
end_comment

begin_comment
comment|/* Number of distinct GPE register blocks and register width */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_GPE_BLOCKS
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_GPE_REGISTER_WIDTH
value|8
end_define

begin_comment
comment|/* Method info (in WALK_STATE), containing local variables and argumetns */
end_comment

begin_define
define|#
directive|define
name|ACPI_METHOD_NUM_LOCALS
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_METHOD_MAX_LOCAL
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_METHOD_NUM_ARGS
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_METHOD_MAX_ARG
value|6
end_define

begin_comment
comment|/* Length of _HID, _UID, _CID, and UUID values */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEVICE_ID_LENGTH
value|0x09
end_define

begin_define
define|#
directive|define
name|ACPI_MAX_CID_LENGTH
value|48
end_define

begin_define
define|#
directive|define
name|ACPI_UUID_LENGTH
value|16
end_define

begin_comment
comment|/*  * Operand Stack (in WALK_STATE), Must be large enough to contain METHOD_MAX_ARG  */
end_comment

begin_define
define|#
directive|define
name|ACPI_OBJ_NUM_OPERANDS
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_OBJ_MAX_OPERAND
value|7
end_define

begin_comment
comment|/* Number of elements in the Result Stack frame, can be an arbitrary value */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESULTS_FRAME_OBJ_NUM
value|8
end_define

begin_comment
comment|/*  * Maximal number of elements the Result Stack can contain,  * it may be an arbitray value not exceeding the types of  * ResultSize and ResultCount (now UINT8).  */
end_comment

begin_define
define|#
directive|define
name|ACPI_RESULTS_OBJ_NUM_MAX
value|255
end_define

begin_comment
comment|/* Names within the namespace are 4 bytes long */
end_comment

begin_define
define|#
directive|define
name|ACPI_NAME_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_PATH_SEGMENT_LENGTH
value|5
end_define

begin_comment
comment|/* 4 chars for name + 1 char for separator */
end_comment

begin_define
define|#
directive|define
name|ACPI_PATH_SEPARATOR
value|'.'
end_define

begin_comment
comment|/* Sizes for ACPI table headers */
end_comment

begin_define
define|#
directive|define
name|ACPI_OEM_ID_SIZE
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_OEM_TABLE_ID_SIZE
value|8
end_define

begin_comment
comment|/* Constants used in searching for the RSDP in low memory */
end_comment

begin_define
define|#
directive|define
name|ACPI_EBDA_PTR_LOCATION
value|0x0000040E
end_define

begin_comment
comment|/* Physical Address */
end_comment

begin_define
define|#
directive|define
name|ACPI_EBDA_PTR_LENGTH
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_EBDA_WINDOW_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|ACPI_HI_RSDP_WINDOW_BASE
value|0x000E0000
end_define

begin_comment
comment|/* Physical Address */
end_comment

begin_define
define|#
directive|define
name|ACPI_HI_RSDP_WINDOW_SIZE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ACPI_RSDP_SCAN_STEP
value|16
end_define

begin_comment
comment|/* Operation regions */
end_comment

begin_define
define|#
directive|define
name|ACPI_NUM_PREDEFINED_REGIONS
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_USER_REGION_BEGIN
value|0x80
end_define

begin_comment
comment|/* Maximum SpaceIds for Operation Regions */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_ADDRESS_SPACE
value|255
end_define

begin_comment
comment|/* Array sizes.  Used for range checking also */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_MATCH_OPCODE
value|5
end_define

begin_comment
comment|/* RSDP checksums */
end_comment

begin_define
define|#
directive|define
name|ACPI_RSDP_CHECKSUM_LENGTH
value|20
end_define

begin_define
define|#
directive|define
name|ACPI_RSDP_XCHECKSUM_LENGTH
value|36
end_define

begin_comment
comment|/* SMBus bidirectional buffer size */
end_comment

begin_define
define|#
directive|define
name|ACPI_SMBUS_BUFFER_SIZE
value|34
end_define

begin_comment
comment|/******************************************************************************  *  * ACPI AML Debugger  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUGGER_MAX_ARGS
value|8
end_define

begin_comment
comment|/* Must be max method args + 1 */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUGGER_COMMAND_PROMPT
value|'-'
end_define

begin_define
define|#
directive|define
name|ACPI_DEBUGGER_EXECUTE_PROMPT
value|'%'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ACCONFIG_H */
end_comment

end_unit

