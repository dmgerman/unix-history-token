begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *      from: i386/include/pc bios.h,v 1.2  */
end_comment

begin_comment
comment|/*   * Signature structure for the BIOS32 Service Directory header   */
end_comment

begin_struct
struct|struct
name|bios32_SDheader
block|{
name|u_int8_t
name|sig
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|entry
decl_stmt|;
name|u_int8_t
name|revision
decl_stmt|;
name|u_int8_t
name|len
decl_stmt|;
name|u_int8_t
name|cksum
decl_stmt|;
name|u_int8_t
name|pad
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*   * BIOS32 Service Directory entry.  Caller supplies name, bios32_SDlookup  * fills in the rest of the details.  */
end_comment

begin_struct
struct|struct
name|bios32_SDentry
block|{
union|union
block|{
name|u_int8_t
name|name
index|[
literal|4
index|]
decl_stmt|;
comment|/* service identifier */
name|u_int32_t
name|id
decl_stmt|;
comment|/* as a 32-bit value */
block|}
name|ident
union|;
name|u_int32_t
name|base
decl_stmt|;
comment|/* base of service */
name|u_int32_t
name|len
decl_stmt|;
comment|/* service length */
name|u_int32_t
name|entry
decl_stmt|;
comment|/* entrypoint offset from base */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|bios32_SDlookup
parameter_list|(
name|struct
name|bios32_SDentry
modifier|*
name|ent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32_t
name|bios_sigsearch
parameter_list|(
name|u_int32_t
name|start
parameter_list|,
name|u_char
modifier|*
name|sig
parameter_list|,
name|int
name|siglen
parameter_list|,
name|int
name|paralen
parameter_list|,
name|int
name|sigofs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Call a 32-bit BIOS function  */
end_comment

begin_struct
struct|struct
name|bios32_args
block|{
name|u_long
name|eax
decl_stmt|;
name|u_long
name|ebx
decl_stmt|;
name|u_long
name|ecx
decl_stmt|;
name|u_long
name|edx
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|bios32
parameter_list|(
name|caddr_t
name|func_addr
parameter_list|,
name|struct
name|bios32_args
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|BIOS_PADDRTOVADDR
parameter_list|(
name|x
parameter_list|)
value|(((x) - ISA_HOLE_START) + atdevbase)
end_define

begin_define
define|#
directive|define
name|BIOS_VADDRTOPADDR
parameter_list|(
name|x
parameter_list|)
value|(((x) - atdevbase) + ISA_HOLE_START)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BIOS_PADDRTOVADDR
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|BIOS_VADDRTOPADDR
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * System Management BIOS / Desktop Management Interface tables  */
end_comment

begin_struct
struct|struct
name|DMI_table
block|{
name|u_int8_t
name|sig
index|[
literal|5
index|]
decl_stmt|;
comment|/* "_DMI_" */
name|u_int8_t
name|cksum
decl_stmt|;
comment|/* checksum */
name|u_int16_t
name|st_size
decl_stmt|;
comment|/* total length of SMBIOS table (bytes)*/
name|u_int32_t
name|st_base
decl_stmt|;
comment|/* base address of the SMBIOS table (physical) */
name|u_int16_t
name|st_entries
decl_stmt|;
comment|/* total number of structures present in the table */
name|u_int8_t
name|bcd_revision
decl_stmt|;
comment|/* interface revision number */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|SMBIOS_table
block|{
name|u_int8_t
name|sig
index|[
literal|4
index|]
decl_stmt|;
comment|/* "_SM_" */
name|u_int8_t
name|cksum
decl_stmt|;
comment|/* checksum */
name|u_int8_t
name|len
decl_stmt|;
comment|/* structure length */
name|u_int8_t
name|major
decl_stmt|,
name|minor
decl_stmt|;
comment|/* major/minor revision numbers */
name|u_int16_t
name|st_maxsize
decl_stmt|;
comment|/* largest structure size (bytes) */
name|u_int8_t
name|revision
decl_stmt|;
comment|/* entrypoint revision */
name|u_int8_t
name|pad
index|[
literal|5
index|]
decl_stmt|;
name|struct
name|DMI_table
name|dmi
decl_stmt|;
comment|/* follows immediately */
block|}
struct|;
end_struct

begin_comment
comment|/*   * Exported lookup results   */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bios32_SDentry
name|PCIbios
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|SMBIOS_table
modifier|*
name|SMBIOS_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|DMI_table
modifier|*
name|DMI_table
decl_stmt|;
end_decl_stmt

end_unit

