begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Michael Smith  * Copyright (c) 1998 Jonathan Lemon  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $Id: bios.h,v 1.2 1997/08/04 03:31:23 msmith Exp $  */
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

begin_struct
struct|struct
name|segment_info
block|{
name|u_int
name|base
decl_stmt|;
name|u_int
name|limit
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIOSCODE_FLAG
value|0x01
end_define

begin_define
define|#
directive|define
name|BIOSDATA_FLAG
value|0x02
end_define

begin_define
define|#
directive|define
name|BIOSUTIL_FLAG
value|0x04
end_define

begin_define
define|#
directive|define
name|BIOSARGS_FLAG
value|0x08
end_define

begin_struct
struct|struct
name|bios_segments
block|{
name|u_int
name|generation
decl_stmt|;
name|struct
name|segment_info
name|code32
decl_stmt|;
comment|/* 32-bit code (mandatory) */
name|struct
name|segment_info
name|code16
decl_stmt|;
comment|/* 16-bit code */
name|struct
name|segment_info
name|data
decl_stmt|;
comment|/* 16-bit data */
name|struct
name|segment_info
name|util
decl_stmt|;
comment|/* 16-bit utility */
name|struct
name|segment_info
name|args
decl_stmt|;
comment|/* 16-bit args */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bios_regs
block|{
name|u_int
name|eax
decl_stmt|;
name|u_int
name|ebx
decl_stmt|;
name|u_int
name|ecx
decl_stmt|;
name|u_int
name|edx
decl_stmt|;
name|u_int
name|esi
decl_stmt|;
name|u_int
name|edi
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bios_args
block|{
name|u_int
name|entry
decl_stmt|;
comment|/* entry point of routine */
name|struct
name|bios_regs
name|r
decl_stmt|;
name|struct
name|bios_segments
name|seg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * format specifiers and defines for bios16()  *     s	= short (16 bits)  *     i	= int (32 bits)  *     p	= pointer (converted to seg:offset)  *     C,D,U 	= selector (corresponding to code/data/utility segment)  */
end_comment

begin_define
define|#
directive|define
name|PNP_COUNT_DEVNODES
value|"sppD",		0x00
end_define

begin_define
define|#
directive|define
name|PNP_GET_DEVNODE
value|"sppsD",	0x01
end_define

begin_define
define|#
directive|define
name|PNP_SET_DEVNODE
value|"sppsD",	0x02
end_define

begin_define
define|#
directive|define
name|PNP_GET_EVENT
value|"spD",		0x03
end_define

begin_define
define|#
directive|define
name|PNP_SEND_MSG
value|"ssD",		0x04
end_define

begin_define
define|#
directive|define
name|PNP_GET_DOCK_INFO
value|"spD",		0x05
end_define

begin_define
define|#
directive|define
name|PNP_SEL_PRIBOOT
value|"ssiiisspD",	0x07
end_define

begin_define
define|#
directive|define
name|PNP_GET_PRIBOOT
value|"sspppppD",	0x08
end_define

begin_define
define|#
directive|define
name|PNP_SET_RESINFO
value|"spD",		0x09
end_define

begin_define
define|#
directive|define
name|PNP_GET_RESINFO
value|"spD",		0x0A
end_define

begin_define
define|#
directive|define
name|PNP_GET_APM_ID
value|"sppD",		0x0B
end_define

begin_define
define|#
directive|define
name|PNP_GET_ISA_INFO
value|"spD",		0x40
end_define

begin_define
define|#
directive|define
name|PNP_GET_ECSD_INFO
value|"spppD",	0x41
end_define

begin_define
define|#
directive|define
name|PNP_READ_ESCD
value|"spUD",		0x42
end_define

begin_define
define|#
directive|define
name|PNP_WRITE_ESCD
value|"spUD",		0x43
end_define

begin_define
define|#
directive|define
name|PNP_GET_DMI_INFO
value|"spppppD",	0x50
end_define

begin_define
define|#
directive|define
name|PNP_GET_DMI
value|"sppUD",	0x51
end_define

begin_define
define|#
directive|define
name|PNP_BOOT_CHECK
value|"sp",		0x60
end_define

begin_define
define|#
directive|define
name|PNP_COUNT_IPL
value|"sppp",		0x61
end_define

begin_define
define|#
directive|define
name|PNP_GET_BOOTPRI
value|"spp",		0x62
end_define

begin_define
define|#
directive|define
name|PNP_SET_BOOTPRI
value|"sp",		0x63
end_define

begin_define
define|#
directive|define
name|PNP_GET_LASTBOOT
value|"sp",		0x64
end_define

begin_define
define|#
directive|define
name|PNP_GET_BOOTFIRST
value|"sp",		0x65
end_define

begin_define
define|#
directive|define
name|PNP_SET_BOOTFIRST
value|"sp",		0x66
end_define

begin_function_decl
specifier|extern
name|int
name|bios16
parameter_list|(
name|struct
name|bios_args
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bios16_call
parameter_list|(
name|struct
name|bios_regs
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bios32
parameter_list|(
name|struct
name|bios_regs
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_bios_selectors
parameter_list|(
name|struct
name|bios_segments
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

