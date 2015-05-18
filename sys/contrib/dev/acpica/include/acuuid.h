begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acuuid.h - ACPI-related UUID/GUID definitions  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2015, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACUUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACUUID_H__
end_define

begin_comment
comment|/*  * Note1: UUIDs and GUIDs are defined to be identical in ACPI.  *  * Note2: This file is standalone and should remain that way.  */
end_comment

begin_comment
comment|/* NFIT/NVDIMM */
end_comment

begin_define
define|#
directive|define
name|UUID_VOLATILE_MEMORY
value|"4F940573-DAFD-E344-B16C-3F22D252E5D0"
end_define

begin_define
define|#
directive|define
name|UUID_PERSISTENT_MEMORY
value|"79D3F066-F3B4-7440-AC43-0D3318B78CDB"
end_define

begin_define
define|#
directive|define
name|UUID_CONTROL_REGION
value|"F601F792-B413-5D40-910B-299367E8234C"
end_define

begin_define
define|#
directive|define
name|UUID_DATA_REGION
value|"3005AF91-865D-0E47-A6B0-0A2DB9408249"
end_define

begin_define
define|#
directive|define
name|UUID_VOLATILE_VIRTUAL_DISK
value|"5A53AB77-FC45-4B62-5560-F7B281D1F96E"
end_define

begin_define
define|#
directive|define
name|UUID_VOLATILE_VIRTUAL_CD
value|"30BD5A3D-7541-CE87-6D64-D2ADE523C4BB"
end_define

begin_define
define|#
directive|define
name|UUID_PERSISTENT_VIRTUAL_DISK
value|"C902EA5C-074D-69D3-269F-4496FBE096F9"
end_define

begin_define
define|#
directive|define
name|UUID_PERSISTENT_VIRTUAL_CD
value|"88810108-CD42-48BB-100F-5387D53DED3D"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AUUID_H__ */
end_comment

end_unit

