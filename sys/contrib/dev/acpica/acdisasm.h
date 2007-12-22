begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acdisasm.h - AML disassembler  *       $Revision: 1.39 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACDISASM_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACDISASM_H__
end_define

begin_include
include|#
directive|include
file|<contrib/dev/acpica/amlresrc.h>
end_include

begin_define
define|#
directive|define
name|BLOCK_NONE
value|0
end_define

begin_define
define|#
directive|define
name|BLOCK_PAREN
value|1
end_define

begin_define
define|#
directive|define
name|BLOCK_BRACE
value|2
end_define

begin_define
define|#
directive|define
name|BLOCK_COMMA_LIST
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_DEFAULT_RESNAME
value|*(UINT32 *) "__RD"
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_external_list
block|{
name|char
modifier|*
name|Path
decl_stmt|;
name|char
modifier|*
name|InternalPath
decl_stmt|;
name|struct
name|acpi_external_list
modifier|*
name|Next
decl_stmt|;
name|UINT32
name|Value
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
block|}
name|ACPI_EXTERNAL_LIST
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|ACPI_EXTERNAL_LIST
modifier|*
name|AcpiGbl_ExternalList
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
specifier|const
struct|struct
name|acpi_dmtable_info
block|{
name|UINT8
name|Opcode
decl_stmt|;
name|UINT8
name|Offset
decl_stmt|;
name|char
modifier|*
name|Name
decl_stmt|;
block|}
name|ACPI_DMTABLE_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * Values for Opcode above.  * Note: 0-7 must not change, used as a flag shift value  */
end_comment

begin_define
define|#
directive|define
name|ACPI_DMT_FLAG0
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_FLAG1
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_FLAG2
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_FLAG3
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_FLAG4
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_FLAG5
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_FLAG6
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_FLAG7
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_FLAGS0
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_FLAGS2
value|9
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_UINT8
value|10
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_UINT16
value|11
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_UINT24
value|12
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_UINT32
value|13
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_UINT56
value|14
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_UINT64
value|15
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_STRING
value|16
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_NAME4
value|17
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_NAME6
value|18
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_NAME8
value|19
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_CHKSUM
value|20
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_SPACEID
value|21
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_GAS
value|22
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_DMAR
value|23
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_MADT
value|24
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_SRAT
value|25
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_EXIT
value|26
end_define

begin_define
define|#
directive|define
name|ACPI_DMT_SIG
value|27
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ACPI_TABLE_HANDLER
function_decl|)
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_dmtable_data
block|{
name|char
modifier|*
name|Signature
decl_stmt|;
name|ACPI_DMTABLE_INFO
modifier|*
name|TableInfo
decl_stmt|;
name|ACPI_TABLE_HANDLER
name|TableHandler
decl_stmt|;
name|char
modifier|*
name|Name
decl_stmt|;
block|}
name|ACPI_DMTABLE_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|acpi_op_walk_info
block|{
name|UINT32
name|Level
decl_stmt|;
name|UINT32
name|LastLevel
decl_stmt|;
name|UINT32
name|Count
decl_stmt|;
name|UINT32
name|BitOffset
decl_stmt|;
name|UINT32
name|Flags
decl_stmt|;
name|ACPI_WALK_STATE
modifier|*
name|WalkState
decl_stmt|;
block|}
name|ACPI_OP_WALK_INFO
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ASL_WALK_CALLBACK
function_decl|)
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT32
name|Level
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
name|acpi_resource_tag
block|{
name|UINT32
name|BitIndex
decl_stmt|;
name|char
modifier|*
name|Tag
decl_stmt|;
block|}
name|ACPI_RESOURCE_TAG
typedef|;
end_typedef

begin_comment
comment|/* Strings used for decoding flags to ASL keywords */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_WordDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_IrqDecode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_LockRule
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_AccessTypes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_UpdateRules
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|AcpiGbl_MatchOps
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoAsf0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoAsf1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoAsf1a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoAsf2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoAsf2a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoAsf3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoAsf4
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoAsfHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoBoot
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoCpep
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoCpep0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDbgp
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDmar
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDmarHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDmarScope
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDmar0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDmar1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoEcdt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoFacs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoFadt1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoFadt2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoGas
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHeader
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHpet
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt4
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt5
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt6
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt7
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt8
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadtHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMcfg
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMcfg0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoRsdp1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoRsdp2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoSbst
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoSlit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoSpcr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoSpmi
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoSrat
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoSrat0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoSrat1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoTcpa
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoWdrt
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * dmtable  */
end_comment

begin_function_decl
name|void
name|AcpiDmDumpDataTable
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpTable
parameter_list|(
name|UINT32
name|TableLength
parameter_list|,
name|UINT32
name|TableOffset
parameter_list|,
name|void
modifier|*
name|Table
parameter_list|,
name|UINT32
name|SubTableLength
parameter_list|,
name|ACPI_DMTABLE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmLineHeader
parameter_list|(
name|UINT32
name|Offset
parameter_list|,
name|UINT32
name|ByteLength
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmLineHeader2
parameter_list|(
name|UINT32
name|Offset
parameter_list|,
name|UINT32
name|ByteLength
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|,
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmtbdump  */
end_comment

begin_function_decl
name|void
name|AcpiDmDumpAsf
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpCpep
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpDmar
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpFadt
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpSrat
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpMcfg
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpMadt
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiDmDumpRsdp
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpRsdt
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpSlit
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpXsdt
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmwalk  */
end_comment

begin_function_decl
name|void
name|AcpiDmDisassemble
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Origin
parameter_list|,
name|UINT32
name|NumOpcodes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmWalkParseTree
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|ASL_WALK_CALLBACK
name|DescendingCallback
parameter_list|,
name|ASL_WALK_CALLBACK
name|AscendingCallback
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmopcode  */
end_comment

begin_function_decl
name|void
name|AcpiDmDisassembleOneOp
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDecodeInternalObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiDmListType
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmMethodFlags
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmFieldFlags
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmAddressSpace
parameter_list|(
name|UINT8
name|SpaceId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmRegionFlags
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmMatchOp
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiDmCommaIfListMember
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmCommaIfFieldMember
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmnames  */
end_comment

begin_function_decl
name|UINT32
name|AcpiDmDumpName
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiPsDisplayObjectPathname
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmNamestring
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmobject  */
end_comment

begin_function_decl
name|void
name|AcpiDmDisplayInternalObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDisplayArguments
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDisplayLocals
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpMethodInfo
parameter_list|(
name|ACPI_STATUS
name|Status
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmbuffer  */
end_comment

begin_function_decl
name|void
name|AcpiDmDisasmByteList
parameter_list|(
name|UINT32
name|Level
parameter_list|,
name|UINT8
modifier|*
name|ByteData
parameter_list|,
name|UINT32
name|ByteCount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmByteList
parameter_list|(
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmIsEisaId
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmEisaId
parameter_list|(
name|UINT32
name|EncodedId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiDmIsUnicodeBuffer
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiDmIsStringBuffer
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmresrc  */
end_comment

begin_function_decl
name|void
name|AcpiDmDumpInteger8
parameter_list|(
name|UINT8
name|Value
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpInteger16
parameter_list|(
name|UINT16
name|Value
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpInteger32
parameter_list|(
name|UINT32
name|Value
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpInteger64
parameter_list|(
name|UINT64
name|Value
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmResourceTemplate
parameter_list|(
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT8
modifier|*
name|ByteData
parameter_list|,
name|UINT32
name|ByteCount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDmIsResourceTemplate
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmIndent
parameter_list|(
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmBitList
parameter_list|(
name|UINT16
name|Mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDecodeAttribute
parameter_list|(
name|UINT8
name|Attribute
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDescriptorName
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmresrcl  */
end_comment

begin_function_decl
name|void
name|AcpiDmWordDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDwordDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmExtendedDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmQwordDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmMemory24Descriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmMemory32Descriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmFixedMemory32Descriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmGenericRegisterDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmInterruptDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmVendorLargeDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmVendorCommon
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|,
name|UINT8
modifier|*
name|ByteData
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmresrcs  */
end_comment

begin_function_decl
name|void
name|AcpiDmIrqDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDmaDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmIoDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmFixedIoDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmStartDependentDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmEndDependentDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmVendorSmallDescriptor
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmutils  */
end_comment

begin_function_decl
name|void
name|AcpiDmAddToExternalList
parameter_list|(
name|char
modifier|*
name|Path
parameter_list|,
name|UINT8
name|Type
parameter_list|,
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmrestag  */
end_comment

begin_function_decl
name|void
name|AcpiDmFindResources
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Root
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmCheckResourceReference
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACDISASM_H__ */
end_comment

end_unit

