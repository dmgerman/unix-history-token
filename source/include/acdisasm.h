begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acdisasm.h - AML disassembler  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2017, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights. You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code. No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision. In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change. Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee. Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution. In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE. ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT, ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES. INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS. INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES. THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government. In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************  *  * Alternatively, you may choose to be licensed under the terms of the  * following license:  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Alternatively, you may choose to be licensed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  *****************************************************************************/
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
file|"amlresrc.h"
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

begin_comment
comment|/*  * Raw table data header. Used by disassembler and data table compiler.  * Do not change.  */
end_comment

begin_define
define|#
directive|define
name|ACPI_RAW_TABLE_DATA_HEADER
value|"Raw Table Data"
end_define

begin_typedef
typedef|typedef
struct|struct
name|acpi_dmtable_info
block|{
name|UINT8
name|Opcode
decl_stmt|;
name|UINT16
name|Offset
decl_stmt|;
name|char
modifier|*
name|Name
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|ACPI_DMTABLE_INFO
typedef|;
end_typedef

begin_comment
comment|/* Values for Flags field above */
end_comment

begin_define
define|#
directive|define
name|DT_LENGTH
value|0x01
end_define

begin_comment
comment|/* Field is a subtable length */
end_comment

begin_define
define|#
directive|define
name|DT_FLAG
value|0x02
end_define

begin_comment
comment|/* Field is a flag value */
end_comment

begin_define
define|#
directive|define
name|DT_NON_ZERO
value|0x04
end_define

begin_comment
comment|/* Field must be non-zero */
end_comment

begin_define
define|#
directive|define
name|DT_OPTIONAL
value|0x08
end_define

begin_comment
comment|/* Field is optional */
end_comment

begin_define
define|#
directive|define
name|DT_DESCRIBES_OPTIONAL
value|0x10
end_define

begin_comment
comment|/* Field describes an optional field (length, etc.) */
end_comment

begin_define
define|#
directive|define
name|DT_COUNT
value|0x20
end_define

begin_comment
comment|/* Currently not used */
end_comment

begin_comment
comment|/*  * Values for Opcode above.  * Note: 0-7 must not change, they are used as a flag shift value. Other  * than those, new values can be added wherever appropriate.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Simple Data Types */
name|ACPI_DMT_FLAG0
init|=
literal|0
block|,
name|ACPI_DMT_FLAG1
init|=
literal|1
block|,
name|ACPI_DMT_FLAG2
init|=
literal|2
block|,
name|ACPI_DMT_FLAG3
init|=
literal|3
block|,
name|ACPI_DMT_FLAG4
init|=
literal|4
block|,
name|ACPI_DMT_FLAG5
init|=
literal|5
block|,
name|ACPI_DMT_FLAG6
init|=
literal|6
block|,
name|ACPI_DMT_FLAG7
init|=
literal|7
block|,
name|ACPI_DMT_FLAGS0
block|,
name|ACPI_DMT_FLAGS1
block|,
name|ACPI_DMT_FLAGS2
block|,
name|ACPI_DMT_FLAGS4
block|,
name|ACPI_DMT_FLAGS4_0
block|,
name|ACPI_DMT_FLAGS4_4
block|,
name|ACPI_DMT_FLAGS4_8
block|,
name|ACPI_DMT_FLAGS4_12
block|,
name|ACPI_DMT_FLAGS16_16
block|,
name|ACPI_DMT_UINT8
block|,
name|ACPI_DMT_UINT16
block|,
name|ACPI_DMT_UINT24
block|,
name|ACPI_DMT_UINT32
block|,
name|ACPI_DMT_UINT40
block|,
name|ACPI_DMT_UINT48
block|,
name|ACPI_DMT_UINT56
block|,
name|ACPI_DMT_UINT64
block|,
name|ACPI_DMT_BUF7
block|,
name|ACPI_DMT_BUF10
block|,
name|ACPI_DMT_BUF12
block|,
name|ACPI_DMT_BUF16
block|,
name|ACPI_DMT_BUF128
block|,
name|ACPI_DMT_SIG
block|,
name|ACPI_DMT_STRING
block|,
name|ACPI_DMT_NAME4
block|,
name|ACPI_DMT_NAME6
block|,
name|ACPI_DMT_NAME8
block|,
comment|/* Types that are decoded to strings and miscellaneous */
name|ACPI_DMT_ACCWIDTH
block|,
name|ACPI_DMT_CHKSUM
block|,
name|ACPI_DMT_GAS
block|,
name|ACPI_DMT_SPACEID
block|,
name|ACPI_DMT_UNICODE
block|,
name|ACPI_DMT_UUID
block|,
comment|/* Types used only for the Data Table Compiler */
name|ACPI_DMT_BUFFER
block|,
name|ACPI_DMT_RAW_BUFFER
block|,
comment|/* Large, multiple line buffer */
name|ACPI_DMT_DEVICE_PATH
block|,
name|ACPI_DMT_LABEL
block|,
name|ACPI_DMT_PCI_PATH
block|,
comment|/* Types that are specific to particular ACPI tables */
name|ACPI_DMT_ASF
block|,
name|ACPI_DMT_DMAR
block|,
name|ACPI_DMT_DMAR_SCOPE
block|,
name|ACPI_DMT_EINJACT
block|,
name|ACPI_DMT_EINJINST
block|,
name|ACPI_DMT_ERSTACT
block|,
name|ACPI_DMT_ERSTINST
block|,
name|ACPI_DMT_FADTPM
block|,
name|ACPI_DMT_GTDT
block|,
name|ACPI_DMT_HEST
block|,
name|ACPI_DMT_HESTNTFY
block|,
name|ACPI_DMT_HESTNTYP
block|,
name|ACPI_DMT_HMAT
block|,
name|ACPI_DMT_IORTMEM
block|,
name|ACPI_DMT_IVRS
block|,
name|ACPI_DMT_LPIT
block|,
name|ACPI_DMT_MADT
block|,
name|ACPI_DMT_NFIT
block|,
name|ACPI_DMT_PCCT
block|,
name|ACPI_DMT_PMTT
block|,
name|ACPI_DMT_PPTT
block|,
name|ACPI_DMT_SDEI
block|,
name|ACPI_DMT_SLIC
block|,
name|ACPI_DMT_SRAT
block|,
comment|/* Special opcodes */
name|ACPI_DMT_EXTRA_TEXT
block|,
name|ACPI_DMT_EXIT
block|}
name|ACPI_ENTRY_TYPES
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ACPI_DMTABLE_HANDLER
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
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_CMTABLE_HANDLER
function_decl|)
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
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
name|ACPI_DMTABLE_HANDLER
name|TableHandler
decl_stmt|;
name|ACPI_CMTABLE_HANDLER
name|CmTableHandler
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|Template
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
name|ACPI_WALK_STATE
modifier|*
name|WalkState
decl_stmt|;
name|ACPI_PARSE_OBJECT
modifier|*
name|MappingOp
decl_stmt|;
name|UINT8
modifier|*
name|PreviousAml
decl_stmt|;
name|UINT8
modifier|*
name|StartAml
decl_stmt|;
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
name|UINT32
name|AmlOffset
decl_stmt|;
block|}
name|ACPI_OP_WALK_INFO
typedef|;
end_typedef

begin_comment
comment|/*  * TBD - another copy of this is in asltypes.h, fix  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASL_WALK_CALLBACK_DEFINED
end_ifndef

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

begin_define
define|#
directive|define
name|ASL_WALK_CALLBACK_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ACPI_RESOURCE_HANDLER
function_decl|)
parameter_list|(
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|AcpiDmTableInfoBert
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoBgrt
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
name|AcpiDmTableInfoCsrt0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoCsrt1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoCsrt2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoCsrt2a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDbg2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDbg2Device
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDbg2Addr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDbg2Size
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDbg2Name
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDbg2OemData
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
name|AcpiDmTableInfoDmar2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDmar3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDmar4
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDrtm
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDrtm0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDrtm0a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDrtm1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDrtm1a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoDrtm2
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
name|AcpiDmTableInfoEinj
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoEinj0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoErst
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoErst0
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
name|AcpiDmTableInfoFadt3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoFadt5
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoFadt6
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoFpdt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoFpdtHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoFpdt0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoFpdt1
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
name|AcpiDmTableInfoGtdt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoGtdtHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoGtdt0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoGtdt0a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoGtdt1
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
name|AcpiDmTableInfoHest
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHest0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHest1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHest2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHest6
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHest7
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHest8
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHest9
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHest10
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHest11
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHestNotify
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHestBank
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
name|AcpiDmTableInfoLpitHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoLpit0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoLpit1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHmat
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHmat0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHmat1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHmat1a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHmat1b
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHmat1c
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHmat2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHmat2a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoHmatHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIort
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIort0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIort0a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIort1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIort1a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIort2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIort3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIort3a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIort3b
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIort3c
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIort4
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIortAcc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIortHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIortMap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIortPad
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIvrs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIvrs0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIvrs1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIvrs4
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIvrs8a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIvrs8b
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIvrs8c
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoIvrsHdr
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
name|AcpiDmTableInfoMadt9
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt10
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt11
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt12
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt13
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt14
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMadt15
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
name|AcpiDmTableInfoMchi
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMpst
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMpst0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMpst0A
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMpst0B
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMpst1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMpst2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMsct
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMsct0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMtmr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoMtmr0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoNfit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoNfitHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoNfit0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoNfit1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoNfit2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoNfit2a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoNfit3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoNfit3a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoNfit4
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoNfit5
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoNfit6
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoNfit6a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPmtt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPmtt0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPmtt1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPmtt1a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPmtt2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPmttHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPcct
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPcctHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPcct0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPcct1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPcct2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPcct3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPcct4
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPptt0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPptt0a
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPptt1
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPptt2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoPpttHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoRasf
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
name|AcpiDmTableInfoS3pt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoS3ptHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoS3pt0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoS3pt1
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
name|AcpiDmTableInfoSdei
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoSlic
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
name|AcpiDmTableInfoSratHdr
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
name|AcpiDmTableInfoSrat2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoSrat3
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoSrat4
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoStao
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoStaoStr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoTcpaHdr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoTcpaClient
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoTcpaServer
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoTpm2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoUefi
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoVrtc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoVrtc0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoWaet
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoWdat
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoWdat0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoWddt
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

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoWpbt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoWpbt0
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoWsmt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoXenv
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_DMTABLE_INFO
name|AcpiDmTableInfoGeneric
index|[]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * dmtable and ahtable  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|ACPI_DMTABLE_DATA
name|AcpiDmTableData
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|AH_TABLE
name|Gbl_AcpiSupportedTables
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|UINT8
name|AcpiDmGenerateChecksum
parameter_list|(
name|void
modifier|*
name|Table
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT8
name|OriginalChecksum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|ACPI_DMTABLE_DATA
modifier|*
name|AcpiDmGetTableData
parameter_list|(
name|char
modifier|*
name|Signature
parameter_list|)
function_decl|;
end_function_decl

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
name|ACPI_STATUS
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
name|AcpiDmDumpBuffer
parameter_list|(
name|void
modifier|*
name|Table
parameter_list|,
name|UINT32
name|BufferOffset
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|AbsoluteOffset
parameter_list|,
name|char
modifier|*
name|Header
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpUnicode
parameter_list|(
name|void
modifier|*
name|Table
parameter_list|,
name|UINT32
name|BufferOffset
parameter_list|,
name|UINT32
name|ByteLength
parameter_list|)
function_decl|;
end_function_decl

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
name|AcpiDmDumpCsrt
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpDbg2
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
name|AcpiDmDumpDrtm
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpEinj
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpErst
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
name|AcpiDmDumpFpdt
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpGtdt
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpHest
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpHmat
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpIort
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpIvrs
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpLpit
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
name|AcpiDmDumpMpst
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpMsct
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpMtmr
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpNfit
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpPcct
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpPmtt
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpPptt
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
name|UINT32
name|AcpiDmDumpS3pt
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpSlic
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
name|AcpiDmDumpStao
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpTcpa
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpVrtc
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpWdat
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDumpWpbt
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
name|AcpiDmDisplayTargetPathname
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmNotifyDescription
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmPredefinedDescription
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmFieldPredefinedDescription
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

begin_comment
comment|/*  * dmnames  */
end_comment

begin_function_decl
name|UINT32
name|AcpiDmDumpName
parameter_list|(
name|UINT32
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
name|AcpiDmCheckForHardwareId
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmDecompressEisaId
parameter_list|(
name|UINT32
name|EncodedId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiDmIsUuidBuffer
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
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

begin_function_decl
name|BOOLEAN
name|AcpiDmIsPldBuffer
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmdeferred  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiDmParseDeferredOps
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Root
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmextern  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiDmAddToExternalFileList
parameter_list|(
name|char
modifier|*
name|PathList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmClearExternalFileList
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmAddOpToExternalList
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|char
modifier|*
name|Path
parameter_list|,
name|UINT8
name|Type
parameter_list|,
name|UINT32
name|Value
parameter_list|,
name|UINT16
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmCreateSubobjectForExternal
parameter_list|(
name|UINT8
name|Type
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
modifier|*
name|Node
parameter_list|,
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmAddNodeToExternalList
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|UINT8
name|Type
parameter_list|,
name|UINT32
name|Value
parameter_list|,
name|UINT16
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmAddExternalListToNamespace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmAddOneExternalToNamespace
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

begin_function_decl
name|UINT32
name|AcpiDmGetUnresolvedExternalMethodCount
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmClearExternalList
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmEmitExternals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmEmitExternal
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|NameOp
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|TypeOp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmUnresolvedWarning
parameter_list|(
name|UINT8
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmGetExternalsFromFile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmMarkExternalConflict
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
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
specifier|const
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
specifier|const
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
specifier|const
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
specifier|const
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
name|AcpiDmBitList
parameter_list|(
name|UINT16
name|Mask
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|AcpiDmGpioDescriptor
parameter_list|(
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|AcpiDmPinFunctionDescriptor
parameter_list|(
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|AcpiDmPinConfigDescriptor
parameter_list|(
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|AcpiDmPinGroupDescriptor
parameter_list|(
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|AcpiDmPinGroupFunctionDescriptor
parameter_list|(
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|AcpiDmPinGroupConfigDescriptor
parameter_list|(
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|AcpiDmSerialBusDescriptor
parameter_list|(
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
specifier|const
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|AcpiDmFixedDmaDescriptor
parameter_list|(
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
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
name|AcpiDmDecodeAttribute
parameter_list|(
name|UINT8
name|Attribute
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

begin_comment
comment|/*  * dmcstyle  */
end_comment

begin_function_decl
name|BOOLEAN
name|AcpiDmCheckForSymbolicOpcode
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmCloseOperator
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmtables  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiDmProcessSwitch
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiDmClearTempList
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmtables  */
end_comment

begin_function_decl
name|void
name|AdDisassemblerHeader
parameter_list|(
name|char
modifier|*
name|Filename
parameter_list|,
name|UINT8
name|TableType
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ACPI_IS_AML_TABLE
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_IS_DATA_TABLE
value|1
end_define

begin_comment
comment|/*  * adisasm  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AdAmlDisassemble
parameter_list|(
name|BOOLEAN
name|OutToFile
parameter_list|,
name|char
modifier|*
name|Filename
parameter_list|,
name|char
modifier|*
name|Prefix
parameter_list|,
name|char
modifier|*
modifier|*
name|OutFilename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AdGetLocalTables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AdParseTable
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|,
name|ACPI_OWNER_ID
modifier|*
name|OwnerId
parameter_list|,
name|BOOLEAN
name|LoadTable
parameter_list|,
name|BOOLEAN
name|External
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AdDisplayTables
parameter_list|(
name|char
modifier|*
name|Filename
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AdDisplayStatistics
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * dmwalk  */
end_comment

begin_function_decl
name|UINT32
name|AcpiDmBlockType
parameter_list|(
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
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

