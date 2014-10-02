begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acnames.h - Global names and strings  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACNAMES_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACNAMES_H__
end_define

begin_comment
comment|/* Method names - these methods can appear anywhere in the namespace */
end_comment

begin_define
define|#
directive|define
name|METHOD_NAME__ADR
value|"_ADR"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__AEI
value|"_AEI"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__BBN
value|"_BBN"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__CBA
value|"_CBA"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__CID
value|"_CID"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__CRS
value|"_CRS"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__DDN
value|"_DDN"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__HID
value|"_HID"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__INI
value|"_INI"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__PLD
value|"_PLD"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__DSD
value|"_DSD"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__PRS
value|"_PRS"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__PRT
value|"_PRT"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__PRW
value|"_PRW"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__PS0
value|"_PS0"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__PS1
value|"_PS1"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__PS2
value|"_PS2"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__PS3
value|"_PS3"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__REG
value|"_REG"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__SB_
value|"_SB_"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__SEG
value|"_SEG"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__SRS
value|"_SRS"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__STA
value|"_STA"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__SUB
value|"_SUB"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__UID
value|"_UID"
end_define

begin_comment
comment|/* Method names - these methods must appear at the namespace root */
end_comment

begin_define
define|#
directive|define
name|METHOD_PATHNAME__PTS
value|"\\_PTS"
end_define

begin_define
define|#
directive|define
name|METHOD_PATHNAME__SST
value|"\\_SI._SST"
end_define

begin_define
define|#
directive|define
name|METHOD_PATHNAME__WAK
value|"\\_WAK"
end_define

begin_comment
comment|/* Definitions of the predefined namespace names  */
end_comment

begin_define
define|#
directive|define
name|ACPI_UNKNOWN_NAME
value|(UINT32) 0x3F3F3F3F
end_define

begin_comment
comment|/* Unknown name is "????" */
end_comment

begin_define
define|#
directive|define
name|ACPI_ROOT_NAME
value|(UINT32) 0x5F5F5F5C
end_define

begin_comment
comment|/* Root name is    "\___" */
end_comment

begin_define
define|#
directive|define
name|ACPI_PREFIX_MIXED
value|(UINT32) 0x69706341
end_define

begin_comment
comment|/* "Acpi" */
end_comment

begin_define
define|#
directive|define
name|ACPI_PREFIX_LOWER
value|(UINT32) 0x69706361
end_define

begin_comment
comment|/* "acpi" */
end_comment

begin_define
define|#
directive|define
name|ACPI_NS_ROOT_PATH
value|"\\"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACNAMES_H__  */
end_comment

end_unit

