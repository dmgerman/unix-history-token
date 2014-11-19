begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acconfig.h - Global configuration constants  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
comment|/*  * ACPI_DEBUG_OUTPUT    - This switch enables all the debug facilities of the  *                        ACPI subsystem. This includes the DEBUG_PRINT output  *                        statements. When disabled, all DEBUG_PRINT  *                        statements are compiled out.  *  * ACPI_APPLICATION     - Use this switch if the subsystem is going to be run  *                        at the application level.  *  */
end_comment

begin_comment
comment|/*  * OS name, used for the _OS object. The _OS object is essentially obsolete,  * but there is a large base of ASL/AML code in existing machines that check  * for the string below. The use of this string usually guarantees that  * the ASL will execute down the most tested code path. Also, there is some  * code that will not execute the _OSI method unless _OS matches the string  * below. Therefore, change this string at your own risk.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_CHECKSUM_ABORT
end_ifndef

begin_define
define|#
directive|define
name|ACPI_CHECKSUM_ABORT
value|FALSE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Generate a version of ACPICA that only supports "reduced hardware"  * platforms (as defined in ACPI 5.0). Set to TRUE to generate a specialized  * version of ACPICA that ONLY supports the ACPI 5.0 "reduced hardware"  * model. In other words, no ACPI hardware is supported.  *  * If TRUE, this means no support for the following:  *      PM Event and Control registers  *      SCI interrupt (and handler)  *      Fixed Events  *      General Purpose Events (GPEs)  *      Global Lock  *      ACPI PM timer  *      FACS table (Waking vectors and Global Lock)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_REDUCED_HARDWARE
end_ifndef

begin_define
define|#
directive|define
name|ACPI_REDUCED_HARDWARE
value|FALSE
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|5
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
comment|/* Default page size for use in mapping memory for operation regions */
end_comment

begin_define
define|#
directive|define
name|ACPI_DEFAULT_PAGE_SIZE
value|4096
end_define

begin_comment
comment|/* Must be power of 2 */
end_comment

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
comment|/* Maximum number of While() loop iterations before forced abort */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_LOOP_ITERATIONS
value|0xFFFF
end_define

begin_comment
comment|/* Maximum sleep allowed via Sleep() operator */
end_comment

begin_define
define|#
directive|define
name|ACPI_MAX_SLEEP
value|2000
end_define

begin_comment
comment|/* 2000 millisec == two seconds */
end_comment

begin_comment
comment|/* Address Range lists are per-SpaceId (Memory and I/O only) */
end_comment

begin_define
define|#
directive|define
name|ACPI_ADDRESS_RANGE_MAX
value|2
end_define

begin_comment
comment|/******************************************************************************  *  * ACPI Specification constants (Do not change unless the specification changes)  *  *****************************************************************************/
end_comment

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

begin_define
define|#
directive|define
name|ACPI_NUM_DEFAULT_SPACES
value|4
end_define

begin_comment
comment|/* Array sizes. Used for range checking also */
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
comment|/* SMBus, GSBus and IPMI bidirectional buffer size */
end_comment

begin_define
define|#
directive|define
name|ACPI_SMBUS_BUFFER_SIZE
value|34
end_define

begin_define
define|#
directive|define
name|ACPI_GSBUS_BUFFER_SIZE
value|34
end_define

begin_define
define|#
directive|define
name|ACPI_IPMI_BUFFER_SIZE
value|66
end_define

begin_comment
comment|/* _SxD and _SxW control methods */
end_comment

begin_define
define|#
directive|define
name|ACPI_NUM_SxD_METHODS
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_NUM_SxW_METHODS
value|5
end_define

begin_comment
comment|/******************************************************************************  *  * Miscellaneous constants  *  *****************************************************************************/
end_comment

begin_comment
comment|/* UUID constants */
end_comment

begin_define
define|#
directive|define
name|UUID_BUFFER_LENGTH
value|16
end_define

begin_comment
comment|/* Length of UUID in memory */
end_comment

begin_define
define|#
directive|define
name|UUID_STRING_LENGTH
value|36
end_define

begin_comment
comment|/* Total length of a UUID string */
end_comment

begin_comment
comment|/* Positions for required hyphens (dashes) in UUID strings */
end_comment

begin_define
define|#
directive|define
name|UUID_HYPHEN1_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|UUID_HYPHEN2_OFFSET
value|13
end_define

begin_define
define|#
directive|define
name|UUID_HYPHEN3_OFFSET
value|18
end_define

begin_define
define|#
directive|define
name|UUID_HYPHEN4_OFFSET
value|23
end_define

begin_comment
comment|/******************************************************************************  *  * ACPI AML Debugger  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ACPI_DEBUGGER_MAX_ARGS
value|ACPI_METHOD_NUM_ARGS + 4
end_define

begin_comment
comment|/* Max command line arguments */
end_comment

begin_define
define|#
directive|define
name|ACPI_DB_LINE_BUFFER_SIZE
value|512
end_define

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

