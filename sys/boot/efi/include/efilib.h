begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<efifpswa.h>
end_include

begin_decl_stmt
specifier|extern
name|EFI_HANDLE
name|IH
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_SYSTEM_TABLE
modifier|*
name|ST
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_BOOT_SERVICES
modifier|*
name|BS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_RUNTIME_SERVICES
modifier|*
name|RS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DIG64 Headless Console& Debug Port Table. */
end_comment

begin_define
define|#
directive|define
name|HCDP_TABLE_GUID
define|\
value|{0xf951938d,0x620b,0x42ef,{0x82,0x79,0xa8,0x4b,0x79,0x61,0x78,0x98}}
end_define

begin_function_decl
name|void
modifier|*
name|efi_get_table
parameter_list|(
name|EFI_GUID
modifier|*
name|tbl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|efi_main
parameter_list|(
name|EFI_HANDLE
name|image_handle
parameter_list|,
name|EFI_SYSTEM_TABLE
modifier|*
name|system_table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EFI_PHYSICAL_ADDRESS
name|efimd_va2pa
parameter_list|(
name|EFI_VIRTUAL_ADDRESS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EFI_STATUS
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|CHAR16
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exit
parameter_list|(
name|EFI_STATUS
name|status
parameter_list|)
function_decl|;
end_function_decl

end_unit

