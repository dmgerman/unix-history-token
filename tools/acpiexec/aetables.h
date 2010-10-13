begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aetables.h - Precompiled AML ACPI tables for acpiexec  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2010, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AETABLES_H__
end_ifndef

begin_define
define|#
directive|define
name|__AETABLES_H__
end_define

begin_comment
comment|/*  * Miscellaneous pre-compiled AML ACPI tables to be installed  */
end_comment

begin_comment
comment|/* Default DSDT. This will be replaced with the input DSDT */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|DsdtCode
index|[]
init|=
block|{
literal|0x44
block|,
literal|0x53
block|,
literal|0x44
block|,
literal|0x54
block|,
literal|0x24
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000000    "DSDT$..." */
literal|0x02
block|,
literal|0x6F
block|,
literal|0x49
block|,
literal|0x6E
block|,
literal|0x74
block|,
literal|0x65
block|,
literal|0x6C
block|,
literal|0x00
block|,
comment|/* 00000008    ".oIntel." */
literal|0x4E
block|,
literal|0x75
block|,
literal|0x6C
block|,
literal|0x6C
block|,
literal|0x44
block|,
literal|0x53
block|,
literal|0x44
block|,
literal|0x54
block|,
comment|/* 00000010    "NullDSDT" */
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x49
block|,
literal|0x4E
block|,
literal|0x54
block|,
literal|0x4C
block|,
comment|/* 00000018    "....INTL" */
literal|0x04
block|,
literal|0x12
block|,
literal|0x08
block|,
literal|0x20
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|LocalDsdtCode
index|[]
init|=
block|{
literal|0x44
block|,
literal|0x53
block|,
literal|0x44
block|,
literal|0x54
block|,
literal|0x24
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000000    "DSDT$..." */
literal|0x02
block|,
literal|0x2C
block|,
literal|0x49
block|,
literal|0x6E
block|,
literal|0x74
block|,
literal|0x65
block|,
literal|0x6C
block|,
literal|0x00
block|,
comment|/* 00000008    ".,Intel." */
literal|0x4C
block|,
literal|0x6F
block|,
literal|0x63
block|,
literal|0x61
block|,
literal|0x6C
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000010    "Local..." */
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x49
block|,
literal|0x4E
block|,
literal|0x54
block|,
literal|0x4C
block|,
comment|/* 00000018    "....INTL" */
literal|0x30
block|,
literal|0x07
block|,
literal|0x09
block|,
literal|0x20
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Several example SSDTs */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|Ssdt1Code
index|[]
init|=
comment|/* Has method _T98 */
block|{
literal|0x53
block|,
literal|0x53
block|,
literal|0x44
block|,
literal|0x54
block|,
literal|0x30
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000000    "SSDT0..." */
literal|0x01
block|,
literal|0xB8
block|,
literal|0x49
block|,
literal|0x6E
block|,
literal|0x74
block|,
literal|0x65
block|,
literal|0x6C
block|,
literal|0x00
block|,
comment|/* 00000008    "..Intel." */
literal|0x4D
block|,
literal|0x61
block|,
literal|0x6E
block|,
literal|0x79
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000010    "Many...." */
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x49
block|,
literal|0x4E
block|,
literal|0x54
block|,
literal|0x4C
block|,
comment|/* 00000018    "....INTL" */
literal|0x24
block|,
literal|0x04
block|,
literal|0x03
block|,
literal|0x20
block|,
literal|0x14
block|,
literal|0x0B
block|,
literal|0x5F
block|,
literal|0x54
block|,
comment|/* 00000020    "$.. .._T" */
literal|0x39
block|,
literal|0x38
block|,
literal|0x00
block|,
literal|0x70
block|,
literal|0x0A
block|,
literal|0x04
block|,
literal|0x60
block|,
literal|0xA4
block|,
comment|/* 00000028    "98.p..`." */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|Ssdt2Code
index|[]
init|=
comment|/* Has method _T99 */
block|{
literal|0x53
block|,
literal|0x53
block|,
literal|0x44
block|,
literal|0x54
block|,
literal|0x30
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000000    "SSDT0..." */
literal|0x01
block|,
literal|0xB7
block|,
literal|0x49
block|,
literal|0x6E
block|,
literal|0x74
block|,
literal|0x65
block|,
literal|0x6C
block|,
literal|0x00
block|,
comment|/* 00000008    "..Intel." */
literal|0x4D
block|,
literal|0x61
block|,
literal|0x6E
block|,
literal|0x79
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000010    "Many...." */
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x49
block|,
literal|0x4E
block|,
literal|0x54
block|,
literal|0x4C
block|,
comment|/* 00000018    "....INTL" */
literal|0x24
block|,
literal|0x04
block|,
literal|0x03
block|,
literal|0x20
block|,
literal|0x14
block|,
literal|0x0B
block|,
literal|0x5F
block|,
literal|0x54
block|,
comment|/* 00000020    "$.. .._T" */
literal|0x39
block|,
literal|0x39
block|,
literal|0x00
block|,
literal|0x70
block|,
literal|0x0A
block|,
literal|0x04
block|,
literal|0x60
block|,
literal|0xA4
block|,
comment|/* 00000028    "99.p..`." */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|char
name|Ssdt3Code
index|[]
init|=
comment|/* Has method _T97 */
block|{
literal|0x54
block|,
literal|0x53
block|,
literal|0x44
block|,
literal|0x54
block|,
literal|0x30
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000000    "TSDT0..." */
literal|0x01
block|,
literal|0xB8
block|,
literal|0x49
block|,
literal|0x6E
block|,
literal|0x74
block|,
literal|0x65
block|,
literal|0x6C
block|,
literal|0x00
block|,
comment|/* 00000008    "..Intel." */
literal|0x4D
block|,
literal|0x61
block|,
literal|0x6E
block|,
literal|0x79
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000010    "Many...." */
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x49
block|,
literal|0x4E
block|,
literal|0x54
block|,
literal|0x4C
block|,
comment|/* 00000018    "....INTL" */
literal|0x24
block|,
literal|0x04
block|,
literal|0x03
block|,
literal|0x20
block|,
literal|0x14
block|,
literal|0x0B
block|,
literal|0x5F
block|,
literal|0x54
block|,
comment|/* 00000020    "$.. .._T" */
literal|0x39
block|,
literal|0x37
block|,
literal|0x00
block|,
literal|0x70
block|,
literal|0x0A
block|,
literal|0x04
block|,
literal|0x60
block|,
literal|0xA4
block|,
comment|/* 00000028    "97.p..`." */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Example OEM table */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|Oem1Code
index|[]
init|=
block|{
literal|0x4F
block|,
literal|0x45
block|,
literal|0x4D
block|,
literal|0x31
block|,
literal|0x38
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000000    "OEM18..." */
literal|0x01
block|,
literal|0x4B
block|,
literal|0x49
block|,
literal|0x6E
block|,
literal|0x74
block|,
literal|0x65
block|,
literal|0x6C
block|,
literal|0x00
block|,
comment|/* 00000008    ".KIntel." */
literal|0x4D
block|,
literal|0x61
block|,
literal|0x6E
block|,
literal|0x79
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000010    "Many...." */
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x49
block|,
literal|0x4E
block|,
literal|0x54
block|,
literal|0x4C
block|,
comment|/* 00000018    "....INTL" */
literal|0x18
block|,
literal|0x09
block|,
literal|0x03
block|,
literal|0x20
block|,
literal|0x08
block|,
literal|0x5F
block|,
literal|0x58
block|,
literal|0x54
block|,
comment|/* 00000020    "... ._XT" */
literal|0x32
block|,
literal|0x0A
block|,
literal|0x04
block|,
literal|0x14
block|,
literal|0x0C
block|,
literal|0x5F
block|,
literal|0x58
block|,
literal|0x54
block|,
comment|/* 00000028    "2...._XT" */
literal|0x31
block|,
literal|0x00
block|,
literal|0x70
block|,
literal|0x01
block|,
literal|0x5F
block|,
literal|0x58
block|,
literal|0x54
block|,
literal|0x32
block|,
comment|/* 00000030    "1.p._XT2" */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ASL source for this table is at the end of this file */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|OemxCode
index|[]
init|=
block|{
literal|0x4F
block|,
literal|0x45
block|,
literal|0x4D
block|,
literal|0x58
block|,
literal|0xB0
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000000    "OEMX...." */
literal|0x02
block|,
literal|0x54
block|,
literal|0x4D
block|,
literal|0x79
block|,
literal|0x4F
block|,
literal|0x45
block|,
literal|0x4D
block|,
literal|0x00
block|,
comment|/* 00000008    ".TMyOEM." */
literal|0x54
block|,
literal|0x65
block|,
literal|0x73
block|,
literal|0x74
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000010    "Test...." */
literal|0x32
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x49
block|,
literal|0x4E
block|,
literal|0x54
block|,
literal|0x4C
block|,
comment|/* 00000018    "2...INTL" */
literal|0x31
block|,
literal|0x03
block|,
literal|0x10
block|,
literal|0x20
block|,
literal|0x14
block|,
literal|0x1D
block|,
literal|0x5F
block|,
literal|0x49
block|,
comment|/* 00000020    "1.. .._I" */
literal|0x4E
block|,
literal|0x49
block|,
literal|0x00
block|,
literal|0x70
block|,
literal|0x0D
block|,
literal|0x54
block|,
literal|0x61
block|,
literal|0x62
block|,
comment|/* 00000028    "NI.p.Tab" */
literal|0x6C
block|,
literal|0x65
block|,
literal|0x20
block|,
literal|0x4F
block|,
literal|0x45
block|,
literal|0x4D
block|,
literal|0x58
block|,
literal|0x20
block|,
comment|/* 00000030    "le OEMX " */
literal|0x72
block|,
literal|0x75
block|,
literal|0x6E
block|,
literal|0x6E
block|,
literal|0x69
block|,
literal|0x6E
block|,
literal|0x67
block|,
literal|0x00
block|,
comment|/* 00000038    "running." */
literal|0x5B
block|,
literal|0x31
block|,
literal|0x10
block|,
literal|0x22
block|,
literal|0x5C
block|,
literal|0x5F
block|,
literal|0x47
block|,
literal|0x50
block|,
comment|/* 00000040    "[1."\_GP" */
literal|0x45
block|,
literal|0x14
block|,
literal|0x06
block|,
literal|0x5F
block|,
literal|0x45
block|,
literal|0x30
block|,
literal|0x37
block|,
literal|0x00
block|,
comment|/* 00000048    "E.._E07." */
literal|0x14
block|,
literal|0x06
block|,
literal|0x5F
block|,
literal|0x45
block|,
literal|0x32
block|,
literal|0x32
block|,
literal|0x00
block|,
literal|0x14
block|,
comment|/* 00000050    ".._E22.." */
literal|0x06
block|,
literal|0x5F
block|,
literal|0x4C
block|,
literal|0x33
block|,
literal|0x31
block|,
literal|0x00
block|,
literal|0x14
block|,
literal|0x06
block|,
comment|/* 00000058    "._L31..." */
literal|0x5F
block|,
literal|0x4C
block|,
literal|0x36
block|,
literal|0x36
block|,
literal|0x00
block|,
literal|0x5B
block|,
literal|0x82
block|,
literal|0x10
block|,
comment|/* 00000060    "_L66.[.." */
literal|0x4F
block|,
literal|0x45
block|,
literal|0x4D
block|,
literal|0x31
block|,
literal|0x08
block|,
literal|0x5F
block|,
literal|0x50
block|,
literal|0x52
block|,
comment|/* 00000068    "OEM1._PR" */
literal|0x57
block|,
literal|0x12
block|,
literal|0x05
block|,
literal|0x02
block|,
literal|0x0A
block|,
literal|0x07
block|,
literal|0x00
block|,
literal|0x5B
block|,
comment|/* 00000070    "W......[" */
literal|0x82
block|,
literal|0x10
block|,
literal|0x4F
block|,
literal|0x45
block|,
literal|0x4D
block|,
literal|0x32
block|,
literal|0x08
block|,
literal|0x5F
block|,
comment|/* 00000078    "..OEM2._" */
literal|0x50
block|,
literal|0x52
block|,
literal|0x57
block|,
literal|0x12
block|,
literal|0x05
block|,
literal|0x02
block|,
literal|0x0A
block|,
literal|0x66
block|,
comment|/* 00000080    "PRW....f" */
literal|0x00
block|,
literal|0x10
block|,
literal|0x26
block|,
literal|0x5C
block|,
literal|0x47
block|,
literal|0x50
block|,
literal|0x45
block|,
literal|0x32
block|,
comment|/* 00000088    "..&\GPE2" */
literal|0x14
block|,
literal|0x06
block|,
literal|0x5F
block|,
literal|0x4C
block|,
literal|0x30
block|,
literal|0x31
block|,
literal|0x00
block|,
literal|0x14
block|,
comment|/* 00000090    ".._L01.." */
literal|0x06
block|,
literal|0x5F
block|,
literal|0x45
block|,
literal|0x30
block|,
literal|0x37
block|,
literal|0x00
block|,
literal|0x08
block|,
literal|0x5F
block|,
comment|/* 00000098    "._E07.._" */
literal|0x50
block|,
literal|0x52
block|,
literal|0x57
block|,
literal|0x12
block|,
literal|0x0C
block|,
literal|0x02
block|,
literal|0x12
block|,
literal|0x08
block|,
comment|/* 000000A0    "PRW....." */
literal|0x02
block|,
literal|0x5C
block|,
literal|0x47
block|,
literal|0x50
block|,
literal|0x45
block|,
literal|0x32
block|,
literal|0x01
block|,
literal|0x00
comment|/* 000000A8    ".\GPE2.." */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Example installable control method  *  * DefinitionBlock ("", "DSDT", 2, "Intel", "MTHDTEST", 0x20090512)  * {  *     Method (\_SI_._T97, 1, Serialized)  *     {  *         Store ("Example installed method", Debug)  *         Store (Arg0, Debug)  *         Return ()  *     }  * }  *  * Compiled byte code below.  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|MethodCode
index|[]
init|=
block|{
literal|0x44
block|,
literal|0x53
block|,
literal|0x44
block|,
literal|0x54
block|,
literal|0x53
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* 00000000    "DSDTS..." */
literal|0x02
block|,
literal|0xF9
block|,
literal|0x49
block|,
literal|0x6E
block|,
literal|0x74
block|,
literal|0x65
block|,
literal|0x6C
block|,
literal|0x00
block|,
comment|/* 00000008    "..Intel." */
literal|0x4D
block|,
literal|0x54
block|,
literal|0x48
block|,
literal|0x44
block|,
literal|0x54
block|,
literal|0x45
block|,
literal|0x53
block|,
literal|0x54
block|,
comment|/* 00000010    "MTHDTEST" */
literal|0x12
block|,
literal|0x05
block|,
literal|0x09
block|,
literal|0x20
block|,
literal|0x49
block|,
literal|0x4E
block|,
literal|0x54
block|,
literal|0x4C
block|,
comment|/* 00000018    "... INTL" */
literal|0x22
block|,
literal|0x04
block|,
literal|0x09
block|,
literal|0x20
block|,
literal|0x14
block|,
literal|0x2E
block|,
literal|0x2E
block|,
literal|0x5F
block|,
comment|/* 00000020    "".. ..._" */
literal|0x54
block|,
literal|0x49
block|,
literal|0x5F
block|,
literal|0x5F
block|,
literal|0x54
block|,
literal|0x39
block|,
literal|0x37
block|,
literal|0x09
block|,
comment|/* 00000028    "SI__T97." */
literal|0x70
block|,
literal|0x0D
block|,
literal|0x45
block|,
literal|0x78
block|,
literal|0x61
block|,
literal|0x6D
block|,
literal|0x70
block|,
literal|0x6C
block|,
comment|/* 00000030    "p.Exampl" */
literal|0x65
block|,
literal|0x20
block|,
literal|0x69
block|,
literal|0x6E
block|,
literal|0x73
block|,
literal|0x74
block|,
literal|0x61
block|,
literal|0x6C
block|,
comment|/* 00000038    "e instal" */
literal|0x6C
block|,
literal|0x65
block|,
literal|0x64
block|,
literal|0x20
block|,
literal|0x6D
block|,
literal|0x65
block|,
literal|0x74
block|,
literal|0x68
block|,
comment|/* 00000040    "led meth" */
literal|0x6F
block|,
literal|0x64
block|,
literal|0x00
block|,
literal|0x5B
block|,
literal|0x31
block|,
literal|0x70
block|,
literal|0x68
block|,
literal|0x5B
block|,
comment|/* 00000048    "od.[1ph[" */
literal|0x31
block|,
literal|0xA4
block|,
literal|0x00
block|, }
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/******************************************************************************  *  * DESCRIPTION: ASL tables that are used in RSDT/XSDT, also used to test  *              Load/LoadTable operators.  *  *****************************************************************************/
end_comment

begin_comment
unit|DefinitionBlock ("", "OEMX", 2, "MyOEM", "Test", 0x00000432) {     External (GPE2, DeviceObj)      Method (_INI)     {         Store ("Table OEMX running", Debug)     }      Scope (\_GPE)     {         Method (_E07) {}         Method (_E22) {}         Method (_L31) {}         Method (_L66) {}     }      Device (OEM1)     {         Name (_PRW, Package(){7,0})     }     Device (OEM2)     {         Name (_PRW, Package(){0x66,0})     }      Scope (\GPE2)     {         Method (_L01) {}         Method (_E07) {}          Name (_PRW, Package() {Package() {\GPE2, 1}, 0})     } }
comment|/* Parent gr.asl file */
end_comment

begin_comment
unit|DefinitionBlock ("", "DSDT", 2, "Intel", "Many", 0x00000001) {     Name (BUF1, Buffer()     {         0x4F,0x45,0x4D,0x58,0xB0,0x00,0x00,0x00,
comment|/* 00000000    "OEMX...." */
end_comment

begin_comment
unit|0x02,0x54,0x4D,0x79,0x4F,0x45,0x4D,0x00,
comment|/* 00000008    ".TMyOEM." */
end_comment

begin_comment
unit|0x54,0x65,0x73,0x74,0x00,0x00,0x00,0x00,
comment|/* 00000010    "Test...." */
end_comment

begin_comment
unit|0x32,0x04,0x00,0x00,0x49,0x4E,0x54,0x4C,
comment|/* 00000018    "2...INTL" */
end_comment

begin_comment
unit|0x31,0x03,0x10,0x20,0x14,0x1D,0x5F,0x49,
comment|/* 00000020    "1.. .._I" */
end_comment

begin_comment
unit|0x4E,0x49,0x00,0x70,0x0D,0x54,0x61,0x62,
comment|/* 00000028    "NI.p.Tab" */
end_comment

begin_comment
unit|0x6C,0x65,0x20,0x4F,0x45,0x4D,0x58,0x20,
comment|/* 00000030    "le OEMX " */
end_comment

begin_comment
unit|0x72,0x75,0x6E,0x6E,0x69,0x6E,0x67,0x00,
comment|/* 00000038    "running." */
end_comment

begin_comment
unit|0x5B,0x31,0x10,0x22,0x5C,0x5F,0x47,0x50,
comment|/* 00000040    "[1."\_GP" */
end_comment

begin_comment
unit|0x45,0x14,0x06,0x5F,0x45,0x30,0x37,0x00,
comment|/* 00000048    "E.._E07." */
end_comment

begin_comment
unit|0x14,0x06,0x5F,0x45,0x32,0x32,0x00,0x14,
comment|/* 00000050    ".._E22.." */
end_comment

begin_comment
unit|0x06,0x5F,0x4C,0x33,0x31,0x00,0x14,0x06,
comment|/* 00000058    "._L31..." */
end_comment

begin_comment
unit|0x5F,0x4C,0x36,0x36,0x00,0x5B,0x82,0x10,
comment|/* 00000060    "_L66.[.." */
end_comment

begin_comment
unit|0x4F,0x45,0x4D,0x31,0x08,0x5F,0x50,0x52,
comment|/* 00000068    "OEM1._PR" */
end_comment

begin_comment
unit|0x57,0x12,0x05,0x02,0x0A,0x07,0x00,0x5B,
comment|/* 00000070    "W......[" */
end_comment

begin_comment
unit|0x82,0x10,0x4F,0x45,0x4D,0x32,0x08,0x5F,
comment|/* 00000078    "..OEM2._" */
end_comment

begin_comment
unit|0x50,0x52,0x57,0x12,0x05,0x02,0x0A,0x66,
comment|/* 00000080    "PRW....f" */
end_comment

begin_comment
unit|0x00,0x10,0x26,0x5C,0x47,0x50,0x45,0x32,
comment|/* 00000088    "..&\GPE2" */
end_comment

begin_comment
unit|0x14,0x06,0x5F,0x4C,0x30,0x31,0x00,0x14,
comment|/* 00000090    ".._L01.." */
end_comment

begin_comment
unit|0x06,0x5F,0x45,0x30,0x37,0x00,0x08,0x5F,
comment|/* 00000098    "._E07.._" */
end_comment

begin_comment
unit|0x50,0x52,0x57,0x12,0x0C,0x02,0x12,0x08,
comment|/* 000000A0    "PRW....." */
end_comment

begin_comment
unit|0x02,0x5C,0x47,0x50,0x45,0x32,0x01,0x00
comment|/* 000000A8    ".\GPE2.." */
end_comment

begin_endif
unit|})      Name (HNDL, 0)     Method (LD)     {         Load (BUF1, HNDL)         Store ("Load operator, handle:", Debug)         Store (HNDL, Debug)     }      Method (MAIN, 0, NotSerialized)     {         Store ("Loading OEMX table", Debug)         Store (LoadTable ("OEMX", "MyOEM", "Test"), Debug)     }      Scope (\_GPE)     {         Method (_L08) {}         Method (_E08) {}         Method (_L0B) {}     }      Device (DEV0)     {         Name (_PRW, Package() {0x11, 0})     }      Device (\GPE2)     {         Method (_L00) {}     } }
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AETABLES_H__ */
end_comment

end_unit

