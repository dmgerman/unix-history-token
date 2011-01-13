begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aetables.h - Precompiled AML ACPI tables for acpiexec  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2011, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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

