begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acutils.h -- prototypes for the common (subsystem-wide) procedures  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|_ACUTILS_H
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|UINT8
name|AcpiGbl_ResourceAmlSizes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|UINT8
name|AcpiGbl_ResourceAmlSerialBusSizes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Strings used by the disassembler and debugger resource dump routines */
end_comment

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
name|ACPI_DISASSEMBLER
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_DEBUGGER
argument_list|)
end_if

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_BmDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_ConfigDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_ConsumeDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_DecDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_HeDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_IoDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_LlDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_MaxDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_MemDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_MinDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_MtpDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_RngDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_RwDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_ShrDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_SizDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_TrsDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_TtpDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_TypDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_PpcDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_IorDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_DtsDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_CtDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_SbtDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_AmDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_SmDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_WmDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_CphDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_CpoDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_DpDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_EdDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_BpbDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_SbDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_FcDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_PtDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_PtypDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For the iASL compiler case, the output is redirected to stderr so that  * any of the various ACPI errors and warnings do not appear in the output  * files, for either the compiler or disassembler portions of the tool.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_ASL_COMPILER
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|ACPI_MSG_REDIRECT_BEGIN
define|\
value|FILE                    *OutputFile = AcpiGbl_OutputFile; \     AcpiOsRedirectOutput (stderr);
end_define

begin_define
define|#
directive|define
name|ACPI_MSG_REDIRECT_END
define|\
value|AcpiOsRedirectOutput (OutputFile);
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * non-iASL case - no redirection, nothing to do  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MSG_REDIRECT_BEGIN
end_define

begin_define
define|#
directive|define
name|ACPI_MSG_REDIRECT_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Common error message prefixes  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MSG_ERROR
end_ifndef

begin_define
define|#
directive|define
name|ACPI_MSG_ERROR
value|"ACPI Error: "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MSG_EXCEPTION
end_ifndef

begin_define
define|#
directive|define
name|ACPI_MSG_EXCEPTION
value|"ACPI Exception: "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MSG_WARNING
end_ifndef

begin_define
define|#
directive|define
name|ACPI_MSG_WARNING
value|"ACPI Warning: "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MSG_INFO
end_ifndef

begin_define
define|#
directive|define
name|ACPI_MSG_INFO
value|"ACPI: "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MSG_BIOS_ERROR
end_ifndef

begin_define
define|#
directive|define
name|ACPI_MSG_BIOS_ERROR
value|"ACPI BIOS Error (bug): "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_MSG_BIOS_WARNING
end_ifndef

begin_define
define|#
directive|define
name|ACPI_MSG_BIOS_WARNING
value|"ACPI BIOS Warning (bug): "
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Common message suffix  */
end_comment

begin_define
define|#
directive|define
name|ACPI_MSG_SUFFIX
define|\
value|AcpiOsPrintf (" (%8.8X/%s-%u)\n", ACPI_CA_VERSION, ModuleName, LineNumber)
end_define

begin_comment
comment|/* Types for Resource descriptor entries */
end_comment

begin_define
define|#
directive|define
name|ACPI_INVALID_RESOURCE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_FIXED_LENGTH
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_VARIABLE_LENGTH
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_SMALL_VARIABLE_LENGTH
value|3
end_define

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_WALK_AML_CALLBACK
function_decl|)
parameter_list|(
name|UINT8
modifier|*
name|Aml
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Offset
parameter_list|,
name|UINT8
name|ResourceIndex
parameter_list|,
name|void
modifier|*
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_PKG_CALLBACK
function_decl|)
parameter_list|(
name|UINT8
name|ObjectType
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceObject
parameter_list|,
name|ACPI_GENERIC_STATE
modifier|*
name|State
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_pkg_info
block|{
name|UINT8
modifier|*
name|FreeSpace
decl_stmt|;
name|ACPI_SIZE
name|Length
decl_stmt|;
name|UINT32
name|ObjectSpace
decl_stmt|;
name|UINT32
name|NumPackages
decl_stmt|;
block|}
name|ACPI_PKG_INFO
typedef|;
end_typedef

begin_comment
comment|/* Object reference counts */
end_comment

begin_define
define|#
directive|define
name|REF_INCREMENT
value|(UINT16) 0
end_define

begin_define
define|#
directive|define
name|REF_DECREMENT
value|(UINT16) 1
end_define

begin_comment
comment|/* AcpiUtDumpBuffer */
end_comment

begin_define
define|#
directive|define
name|DB_BYTE_DISPLAY
value|1
end_define

begin_define
define|#
directive|define
name|DB_WORD_DISPLAY
value|2
end_define

begin_define
define|#
directive|define
name|DB_DWORD_DISPLAY
value|4
end_define

begin_define
define|#
directive|define
name|DB_QWORD_DISPLAY
value|8
end_define

begin_comment
comment|/*  * utascii - ASCII utilities  */
end_comment

begin_function_decl
name|BOOLEAN
name|AcpiUtValidNameseg
parameter_list|(
name|char
modifier|*
name|Signature
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiUtValidNameChar
parameter_list|(
name|char
name|Character
parameter_list|,
name|UINT32
name|Position
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtCheckAndRepairAscii
parameter_list|(
name|UINT8
modifier|*
name|Name
parameter_list|,
name|char
modifier|*
name|RepairedName
parameter_list|,
name|UINT32
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utnonansi - Non-ANSI C library functions  */
end_comment

begin_function_decl
name|void
name|AcpiUtStrupr
parameter_list|(
name|char
modifier|*
name|SrcString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtStrlwr
parameter_list|(
name|char
modifier|*
name|SrcString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AcpiUtStricmp
parameter_list|(
name|char
modifier|*
name|String1
parameter_list|,
name|char
modifier|*
name|String2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtStrtoul64
parameter_list|(
name|char
modifier|*
name|String
parameter_list|,
name|UINT32
name|Flags
parameter_list|,
name|UINT64
modifier|*
name|RetInteger
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Values for Flags above  * Note: LIMIT values correspond to AcpiGbl_IntegerByteWidth values (4/8)  */
end_comment

begin_define
define|#
directive|define
name|ACPI_STRTOUL_32BIT
value|0x04
end_define

begin_comment
comment|/* 4 bytes */
end_comment

begin_define
define|#
directive|define
name|ACPI_STRTOUL_64BIT
value|0x08
end_define

begin_comment
comment|/* 8 bytes */
end_comment

begin_define
define|#
directive|define
name|ACPI_STRTOUL_BASE16
value|0x10
end_define

begin_comment
comment|/* Default: Base10/16 */
end_comment

begin_comment
comment|/*  * utglobal - Global data structures and procedures  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtInitGlobals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiUtGetMutexName
parameter_list|(
name|UINT32
name|MutexId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiUtGetNotifyName
parameter_list|(
name|UINT32
name|NotifyValue
parameter_list|,
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiUtGetTypeName
parameter_list|(
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiUtGetNodeName
parameter_list|(
name|void
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiUtGetDescriptorName
parameter_list|(
name|void
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiUtGetReferenceName
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiUtGetObjectTypeName
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiUtGetRegionName
parameter_list|(
name|UINT8
name|SpaceId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiUtGetEventName
parameter_list|(
name|UINT32
name|EventId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiUtGetArgumentTypeName
parameter_list|(
name|UINT32
name|ArgType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
name|AcpiUtHexToAsciiChar
parameter_list|(
name|UINT64
name|Integer
parameter_list|,
name|UINT32
name|Position
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtAsciiToHexByte
parameter_list|(
name|char
modifier|*
name|TwoAsciiChars
parameter_list|,
name|UINT8
modifier|*
name|ReturnByte
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
name|AcpiUtAsciiCharToHex
parameter_list|(
name|int
name|HexChar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiUtValidObjectType
parameter_list|(
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utinit - miscellaneous initialization and shutdown  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtHardwareInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtSubsystemShutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utcopy - Object construction and conversion interfaces  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtBuildSimpleObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Obj
parameter_list|,
name|ACPI_OBJECT
modifier|*
name|UserObj
parameter_list|,
name|UINT8
modifier|*
name|DataSpace
parameter_list|,
name|UINT32
modifier|*
name|BufferSpaceUsed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtBuildPackageObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Obj
parameter_list|,
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|UINT32
modifier|*
name|SpaceUsed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtCopyIobjectToEobject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Obj
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtCopyEobjectToIobject
parameter_list|(
name|ACPI_OBJECT
modifier|*
name|Obj
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|InternalObj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtCopyISimpleToIsimple
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceObj
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|DestObj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtCopyIobjectToIobject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|DestDesc
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utcreate - Object creation  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtUpdateObjectReference
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|,
name|UINT16
name|Action
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utdebug - Debug interfaces  */
end_comment

begin_function_decl
name|void
name|AcpiUtInitStackPtrTrace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtTrackStackPtr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtTrace
parameter_list|(
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|,
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtTracePtr
parameter_list|(
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|,
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
specifier|const
name|void
modifier|*
name|Pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtTraceU32
parameter_list|(
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|,
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|UINT32
name|Integer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtTraceStr
parameter_list|(
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|,
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
specifier|const
name|char
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtExit
parameter_list|(
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|,
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtStatusExit
parameter_list|(
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|,
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|ACPI_STATUS
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtValueExit
parameter_list|(
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|,
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtPtrExit
parameter_list|(
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|,
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|UINT8
modifier|*
name|Ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtStrExit
parameter_list|(
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|,
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
specifier|const
name|char
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtDebugDumpBuffer
parameter_list|(
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|Count
parameter_list|,
name|UINT32
name|Display
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtDumpBuffer
parameter_list|(
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|Count
parameter_list|,
name|UINT32
name|Display
parameter_list|,
name|UINT32
name|Offset
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_APPLICATION
end_ifdef

begin_function_decl
name|void
name|AcpiUtDumpBufferToFile
parameter_list|(
name|ACPI_FILE
name|File
parameter_list|,
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|Count
parameter_list|,
name|UINT32
name|Display
parameter_list|,
name|UINT32
name|BaseOffset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|AcpiUtReportError
parameter_list|(
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtReportInfo
parameter_list|(
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtReportWarning
parameter_list|(
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utdelete - Object deletion and reference counts  */
end_comment

begin_function_decl
name|void
name|AcpiUtAddReference
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtRemoveReference
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtDeleteInternalPackageObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtDeleteInternalSimpleObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtDeleteInternalObjectList
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ObjList
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * uteval - object evaluation  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtEvaluateObject
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|PrefixNode
parameter_list|,
specifier|const
name|char
modifier|*
name|Path
parameter_list|,
name|UINT32
name|ExpectedReturnBtypes
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtEvaluateNumericObject
parameter_list|(
specifier|const
name|char
modifier|*
name|ObjectName
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|DeviceNode
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtExecute_STA
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|DeviceNode
parameter_list|,
name|UINT32
modifier|*
name|StatusFlags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtExecutePowerMethods
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|DeviceNode
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|MethodNames
parameter_list|,
name|UINT8
name|MethodCount
parameter_list|,
name|UINT8
modifier|*
name|OutValues
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utids - device ID support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtExecute_HID
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|DeviceNode
parameter_list|,
name|ACPI_PNP_DEVICE_ID
modifier|*
modifier|*
name|ReturnId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtExecute_UID
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|DeviceNode
parameter_list|,
name|ACPI_PNP_DEVICE_ID
modifier|*
modifier|*
name|ReturnId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtExecute_CID
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|DeviceNode
parameter_list|,
name|ACPI_PNP_DEVICE_ID_LIST
modifier|*
modifier|*
name|ReturnCidList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtExecute_CLS
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|DeviceNode
parameter_list|,
name|ACPI_PNP_DEVICE_ID
modifier|*
modifier|*
name|ReturnId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utlock - reader/writer locks  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtCreateRwLock
parameter_list|(
name|ACPI_RW_LOCK
modifier|*
name|Lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtDeleteRwLock
parameter_list|(
name|ACPI_RW_LOCK
modifier|*
name|Lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtAcquireReadLock
parameter_list|(
name|ACPI_RW_LOCK
modifier|*
name|Lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtReleaseReadLock
parameter_list|(
name|ACPI_RW_LOCK
modifier|*
name|Lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtAcquireWriteLock
parameter_list|(
name|ACPI_RW_LOCK
modifier|*
name|Lock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtReleaseWriteLock
parameter_list|(
name|ACPI_RW_LOCK
modifier|*
name|Lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utobject - internal object create/delete/cache routines  */
end_comment

begin_function_decl
name|ACPI_OPERAND_OBJECT
modifier|*
name|AcpiUtCreateInternalObjectDbg
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|AcpiUtAllocateObjectDescDbg
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AcpiUtCreateInternalObject
parameter_list|(
name|t
parameter_list|)
value|AcpiUtCreateInternalObjectDbg (_AcpiModuleName,__LINE__,_COMPONENT,t)
end_define

begin_define
define|#
directive|define
name|AcpiUtAllocateObjectDesc
parameter_list|()
value|AcpiUtAllocateObjectDescDbg (_AcpiModuleName,__LINE__,_COMPONENT)
end_define

begin_function_decl
name|void
name|AcpiUtDeleteObjectDesc
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiUtValidInternalObject
parameter_list|(
name|void
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_OPERAND_OBJECT
modifier|*
name|AcpiUtCreatePackageObject
parameter_list|(
name|UINT32
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_OPERAND_OBJECT
modifier|*
name|AcpiUtCreateIntegerObject
parameter_list|(
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_OPERAND_OBJECT
modifier|*
name|AcpiUtCreateBufferObject
parameter_list|(
name|ACPI_SIZE
name|BufferSize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_OPERAND_OBJECT
modifier|*
name|AcpiUtCreateStringObject
parameter_list|(
name|ACPI_SIZE
name|StringSize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtGetObjectSize
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Obj
parameter_list|,
name|ACPI_SIZE
modifier|*
name|ObjLength
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utosi - Support for the _OSI predefined control method  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtInitializeInterfaces
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtInterfaceTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtInstallInterface
parameter_list|(
name|ACPI_STRING
name|InterfaceName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtRemoveInterface
parameter_list|(
name|ACPI_STRING
name|InterfaceName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtUpdateInterfaces
parameter_list|(
name|UINT8
name|Action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_INTERFACE_INFO
modifier|*
name|AcpiUtGetInterface
parameter_list|(
name|ACPI_STRING
name|InterfaceName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtOsiImplementation
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utpredef - support for predefined names  */
end_comment

begin_function_decl
specifier|const
name|ACPI_PREDEFINED_INFO
modifier|*
name|AcpiUtGetNextPredefinedMethod
parameter_list|(
specifier|const
name|ACPI_PREDEFINED_INFO
modifier|*
name|ThisName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|ACPI_PREDEFINED_INFO
modifier|*
name|AcpiUtMatchPredefinedMethod
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtGetExpectedReturnTypes
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|ExpectedBtypes
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|defined
name|ACPI_ASL_COMPILER
operator|||
name|defined
name|ACPI_HELP_APP
operator|)
end_if

begin_function_decl
specifier|const
name|ACPI_PREDEFINED_INFO
modifier|*
name|AcpiUtMatchResourceName
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtDisplayPredefinedMethod
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
specifier|const
name|ACPI_PREDEFINED_INFO
modifier|*
name|ThisName
parameter_list|,
name|BOOLEAN
name|MultiLine
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiUtGetResourceBitWidth
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|,
name|UINT16
name|Types
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * utstate - Generic state creation/cache routines  */
end_comment

begin_function_decl
name|void
name|AcpiUtPushGenericState
parameter_list|(
name|ACPI_GENERIC_STATE
modifier|*
modifier|*
name|ListHead
parameter_list|,
name|ACPI_GENERIC_STATE
modifier|*
name|State
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_GENERIC_STATE
modifier|*
name|AcpiUtPopGenericState
parameter_list|(
name|ACPI_GENERIC_STATE
modifier|*
modifier|*
name|ListHead
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_GENERIC_STATE
modifier|*
name|AcpiUtCreateGenericState
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_THREAD_STATE
modifier|*
name|AcpiUtCreateThreadState
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_GENERIC_STATE
modifier|*
name|AcpiUtCreateUpdateState
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|,
name|UINT16
name|Action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_GENERIC_STATE
modifier|*
name|AcpiUtCreatePkgState
parameter_list|(
name|void
modifier|*
name|InternalObject
parameter_list|,
name|void
modifier|*
name|ExternalObject
parameter_list|,
name|UINT32
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtCreateUpdateStateAndPush
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|,
name|UINT16
name|Action
parameter_list|,
name|ACPI_GENERIC_STATE
modifier|*
modifier|*
name|StateList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_GENERIC_STATE
modifier|*
name|AcpiUtCreateControlState
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtDeleteGenericState
parameter_list|(
name|ACPI_GENERIC_STATE
modifier|*
name|State
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utmath  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtDivide
parameter_list|(
name|UINT64
name|InDividend
parameter_list|,
name|UINT64
name|InDivisor
parameter_list|,
name|UINT64
modifier|*
name|OutQuotient
parameter_list|,
name|UINT64
modifier|*
name|OutRemainder
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtShortDivide
parameter_list|(
name|UINT64
name|InDividend
parameter_list|,
name|UINT32
name|Divisor
parameter_list|,
name|UINT64
modifier|*
name|OutQuotient
parameter_list|,
name|UINT32
modifier|*
name|OutRemainder
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtShortMultiply
parameter_list|(
name|UINT64
name|InMultiplicand
parameter_list|,
name|UINT32
name|Multiplier
parameter_list|,
name|UINT64
modifier|*
name|Outproduct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtShortShiftLeft
parameter_list|(
name|UINT64
name|Operand
parameter_list|,
name|UINT32
name|Count
parameter_list|,
name|UINT64
modifier|*
name|OutResult
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtShortShiftRight
parameter_list|(
name|UINT64
name|Operand
parameter_list|,
name|UINT32
name|Count
parameter_list|,
name|UINT64
modifier|*
name|OutResult
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utmisc  */
end_comment

begin_function_decl
specifier|const
name|ACPI_EXCEPTION_INFO
modifier|*
name|AcpiUtValidateException
parameter_list|(
name|ACPI_STATUS
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiUtIsPciRootBridge
parameter_list|(
name|char
modifier|*
name|Id
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|defined
name|ACPI_ASL_COMPILER
operator|||
name|defined
name|ACPI_EXEC_APP
operator|||
name|defined
name|ACPI_NAMES_APP
operator|)
end_if

begin_function_decl
name|BOOLEAN
name|AcpiUtIsAmlTable
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|ACPI_STATUS
name|AcpiUtWalkPackageTree
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceObject
parameter_list|,
name|void
modifier|*
name|TargetObject
parameter_list|,
name|ACPI_PKG_CALLBACK
name|WalkCallback
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Values for Base above (16=Hex, 10=Decimal) */
end_comment

begin_define
define|#
directive|define
name|ACPI_ANY_BASE
value|0
end_define

begin_function_decl
name|UINT32
name|AcpiUtDwordByteSwap
parameter_list|(
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtSetIntegerWidth
parameter_list|(
name|UINT8
name|Revision
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_OUTPUT
end_ifdef

begin_function_decl
name|void
name|AcpiUtDisplayInitPathname
parameter_list|(
name|UINT8
name|Type
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|ObjHandle
parameter_list|,
specifier|const
name|char
modifier|*
name|Path
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * utownerid - Support for Table/Method Owner IDs  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtAllocateOwnerId
parameter_list|(
name|ACPI_OWNER_ID
modifier|*
name|OwnerId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtReleaseOwnerId
parameter_list|(
name|ACPI_OWNER_ID
modifier|*
name|OwnerId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utresrc  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtWalkAmlResources
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|UINT8
modifier|*
name|Aml
parameter_list|,
name|ACPI_SIZE
name|AmlLength
parameter_list|,
name|ACPI_WALK_AML_CALLBACK
name|UserFunction
parameter_list|,
name|void
modifier|*
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtValidateResource
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|void
modifier|*
name|Aml
parameter_list|,
name|UINT8
modifier|*
name|ReturnIndex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiUtGetDescriptorLength
parameter_list|(
name|void
modifier|*
name|Aml
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT16
name|AcpiUtGetResourceLength
parameter_list|(
name|void
modifier|*
name|Aml
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
name|AcpiUtGetResourceHeaderLength
parameter_list|(
name|void
modifier|*
name|Aml
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
name|AcpiUtGetResourceType
parameter_list|(
name|void
modifier|*
name|Aml
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtGetResourceEndTag
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|UINT8
modifier|*
modifier|*
name|EndTag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utstring - String and character utilities  */
end_comment

begin_function_decl
name|void
name|AcpiUtPrintString
parameter_list|(
name|char
modifier|*
name|String
parameter_list|,
name|UINT16
name|MaxLength
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
name|ACPI_ASL_COMPILER
operator|||
name|defined
name|ACPI_EXEC_APP
end_if

begin_function_decl
name|void
name|UtConvertBackslashes
parameter_list|(
name|char
modifier|*
name|Pathname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|AcpiUtRepairName
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ACPI_DEBUGGER
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_APPLICATION
argument_list|)
end_if

begin_function_decl
name|BOOLEAN
name|AcpiUtSafeStrcpy
parameter_list|(
name|char
modifier|*
name|Dest
parameter_list|,
name|ACPI_SIZE
name|DestSize
parameter_list|,
name|char
modifier|*
name|Source
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiUtSafeStrcat
parameter_list|(
name|char
modifier|*
name|Dest
parameter_list|,
name|ACPI_SIZE
name|DestSize
parameter_list|,
name|char
modifier|*
name|Source
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiUtSafeStrncat
parameter_list|(
name|char
modifier|*
name|Dest
parameter_list|,
name|ACPI_SIZE
name|DestSize
parameter_list|,
name|char
modifier|*
name|Source
parameter_list|,
name|ACPI_SIZE
name|MaxTransferLength
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * utmutex - mutex support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtMutexInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtMutexTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtAcquireMutex
parameter_list|(
name|ACPI_MUTEX_HANDLE
name|MutexId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtReleaseMutex
parameter_list|(
name|ACPI_MUTEX_HANDLE
name|MutexId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utalloc - memory allocation and object caching  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtCreateCaches
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtDeleteCaches
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtValidateBuffer
parameter_list|(
name|ACPI_BUFFER
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtInitializeBuffer
parameter_list|(
name|ACPI_BUFFER
modifier|*
name|Buffer
parameter_list|,
name|ACPI_SIZE
name|RequiredLength
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DBG_TRACK_ALLOCATIONS
end_ifdef

begin_function_decl
name|void
modifier|*
name|AcpiUtAllocateAndTrack
parameter_list|(
name|ACPI_SIZE
name|Size
parameter_list|,
name|UINT32
name|Component
parameter_list|,
specifier|const
name|char
modifier|*
name|Module
parameter_list|,
name|UINT32
name|Line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|AcpiUtAllocateZeroedAndTrack
parameter_list|(
name|ACPI_SIZE
name|Size
parameter_list|,
name|UINT32
name|Component
parameter_list|,
specifier|const
name|char
modifier|*
name|Module
parameter_list|,
name|UINT32
name|Line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtFreeAndTrack
parameter_list|(
name|void
modifier|*
name|Address
parameter_list|,
name|UINT32
name|Component
parameter_list|,
specifier|const
name|char
modifier|*
name|Module
parameter_list|,
name|UINT32
name|Line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtDumpAllocationInfo
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtDumpAllocations
parameter_list|(
name|UINT32
name|Component
parameter_list|,
specifier|const
name|char
modifier|*
name|Module
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUtCreateList
parameter_list|(
specifier|const
name|char
modifier|*
name|ListName
parameter_list|,
name|UINT16
name|ObjectSize
parameter_list|,
name|ACPI_MEMORY_LIST
modifier|*
modifier|*
name|ReturnCache
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_DBG_TRACK_ALLOCATIONS */
end_comment

begin_comment
comment|/*  * utaddress - address range check  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiUtAddAddressRange
parameter_list|(
name|ACPI_ADR_SPACE_TYPE
name|SpaceId
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|RegionNode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtRemoveAddressRange
parameter_list|(
name|ACPI_ADR_SPACE_TYPE
name|SpaceId
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|RegionNode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiUtCheckAddressRange
parameter_list|(
name|ACPI_ADR_SPACE_TYPE
name|SpaceId
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|BOOLEAN
name|Warn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtDeleteAddressLists
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utxferror - various error/warning output functions  */
end_comment

begin_function_decl
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiUtPredefinedWarning
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|char
modifier|*
name|Pathname
parameter_list|,
name|UINT8
name|NodeFlags
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiUtPredefinedInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|char
modifier|*
name|Pathname
parameter_list|,
name|UINT8
name|NodeFlags
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiUtPredefinedBiosError
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|char
modifier|*
name|Pathname
parameter_list|,
name|UINT8
name|NodeFlags
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtNamespaceError
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|InternalName
parameter_list|,
name|ACPI_STATUS
name|LookupStatus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiUtMethodError
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|Message
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
specifier|const
name|char
modifier|*
name|Path
parameter_list|,
name|ACPI_STATUS
name|LookupStatus
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Utility functions for ACPI names and IDs  */
end_comment

begin_function_decl
specifier|const
name|AH_PREDEFINED_NAME
modifier|*
name|AcpiAhMatchPredefinedName
parameter_list|(
name|char
modifier|*
name|Nameseg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|AH_DEVICE_ID
modifier|*
name|AcpiAhMatchHardwareId
parameter_list|(
name|char
modifier|*
name|Hid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiAhMatchUuid
parameter_list|(
name|UINT8
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * utuuid -- UUID support functions  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
name|ACPI_ASL_COMPILER
operator|||
name|defined
name|ACPI_DISASSEMBLER
operator|||
name|defined
name|ACPI_EXEC_APP
operator|||
name|defined
name|ACPI_HELP_APP
operator|)
end_if

begin_function_decl
name|void
name|AcpiUtConvertStringToUuid
parameter_list|(
name|char
modifier|*
name|InString
parameter_list|,
name|UINT8
modifier|*
name|UuidBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ACUTILS_H */
end_comment

end_unit

