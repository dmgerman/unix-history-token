begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Michael Smith  * Copyright (c) 1998 Jonathan Lemon  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|vm_offset_t
name|ventry
decl_stmt|;
comment|/* entrypoint in kernel virtual segment */
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
comment|/*   * PnP BIOS presence structure  */
end_comment

begin_struct
struct|struct
name|PnPBIOS_table
block|{
name|u_int8_t
name|sig
index|[
literal|4
index|]
decl_stmt|;
comment|/* "$PnP */
name|u_int8_t
name|version
decl_stmt|;
comment|/* should be 0x10 */
name|u_int8_t
name|len
decl_stmt|;
comment|/* total structure length */
name|u_int16_t
name|control
decl_stmt|;
comment|/* BIOS feature flags */
name|u_int8_t
name|cksum
decl_stmt|;
comment|/* checksum */
name|u_int32_t
name|evflagaddr
decl_stmt|;
comment|/* address of event notificaton flag */
name|u_int16_t
name|rmentryoffset
decl_stmt|;
comment|/* real-mode entry offset */
name|u_int16_t
name|rmentryseg
decl_stmt|;
comment|/*                 segment */
name|u_int16_t
name|pmentryoffset
decl_stmt|;
comment|/* protected-mode entry offset */
name|u_int32_t
name|pmentrybase
decl_stmt|;
comment|/*                segment base */
name|u_int32_t
name|oemdevid
decl_stmt|;
comment|/* motherboard EISA ID */
name|u_int16_t
name|rmbiosseg
decl_stmt|;
comment|/* real-mode BIOS segment */
name|u_int32_t
name|pmdataseg
decl_stmt|;
comment|/* protected-mode data segment */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
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
name|PnPBIOS_table
modifier|*
name|PnPBIOStable
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
comment|/*  * PnP BIOS return codes  */
end_comment

begin_define
define|#
directive|define
name|PNP_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|PNP_NOT_SET_STATICALLY
value|0x7f
end_define

begin_define
define|#
directive|define
name|PNP_UNKNOWN_FUNCTION
value|0x81
end_define

begin_define
define|#
directive|define
name|PNP_FUNTION_NOT_SUPPORTED
value|0x82
end_define

begin_define
define|#
directive|define
name|PNP_INVALID_HANDLE
value|0x83
end_define

begin_define
define|#
directive|define
name|PNP_BAD_PARAMETER
value|0x84
end_define

begin_define
define|#
directive|define
name|PNP_SET_FAILED
value|0x85
end_define

begin_define
define|#
directive|define
name|PNP_EVENTS_NOT_PENDING
value|0x86
end_define

begin_define
define|#
directive|define
name|PNP_SYSTEM_NOT_DOCKED
value|0x87
end_define

begin_define
define|#
directive|define
name|PNP_NO_ISA_PNP_CARDS
value|0x88
end_define

begin_define
define|#
directive|define
name|PNP_UNABLE_TO_DETERMINE_DOCK_CAPABILITIES
value|0x89
end_define

begin_define
define|#
directive|define
name|PNP_CONFIG_CHANGE_FAILED_NO_BATTERY
value|0x8a
end_define

begin_define
define|#
directive|define
name|PNP_CONFIG_CHANGE_FAILED_RESOURCE_CONFLICT
value|0x8b
end_define

begin_define
define|#
directive|define
name|PNP_BUFFER_TOO_SMALL
value|0x8c
end_define

begin_define
define|#
directive|define
name|PNP_USE_ESCD_SUPPORT
value|0x8d
end_define

begin_define
define|#
directive|define
name|PNP_MESSAGE_NOT_SUPPORTED
value|0x8e
end_define

begin_define
define|#
directive|define
name|PNP_HARDWARE_ERROR
value|0x8f
end_define

begin_comment
comment|/*  * DMI return codes  */
end_comment

begin_define
define|#
directive|define
name|DMI_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|DMI_UNKNOWN_FUNCTION
value|0x81
end_define

begin_define
define|#
directive|define
name|DMI_FUNCTION_NOT_SUPPORTED
value|0x82
end_define

begin_define
define|#
directive|define
name|DMI_INVALID_HANDLE
value|0x83
end_define

begin_define
define|#
directive|define
name|DMI_BAD_PARAMETER
value|0x84
end_define

begin_define
define|#
directive|define
name|DMI_INVALID_SUBFUNCTION
value|0x85
end_define

begin_define
define|#
directive|define
name|DMI_NO_CHANGE
value|0x86
end_define

begin_define
define|#
directive|define
name|DMI_ADD_STRUCTURE_FAILED
value|0x87
end_define

begin_define
define|#
directive|define
name|DMI_READ_ONLY
value|0x8d
end_define

begin_define
define|#
directive|define
name|DMI_LOCK_NOT_SUPPORTED
value|0x90
end_define

begin_define
define|#
directive|define
name|DMI_CURRENTLY_LOCKED
value|0x91
end_define

begin_define
define|#
directive|define
name|DMI_INVALID_LOCK
value|0x92
end_define

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
value|"sspsD",	0x02
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
name|PNP_GET_DMI_STRUCTURE
value|"sppUD",	0x51
end_define

begin_define
define|#
directive|define
name|PNP_SET_DMI_STRUCTURE
value|"sppsUD"	0x52
end_define

begin_define
define|#
directive|define
name|PNP_GET_DMI_CHANGE
value|"spUD"		0x53
end_define

begin_define
define|#
directive|define
name|PNP_DMI_CONTROL
value|"sspsUD"	0x54
end_define

begin_define
define|#
directive|define
name|PNP_GET_GPNV_INFO
value|"sppppD"	0x55
end_define

begin_define
define|#
directive|define
name|PNP_READ_GPNV_DATA
value|"ssppUD"	0x56
end_define

begin_define
define|#
directive|define
name|PNP_WRITE_GPNV_DATA
value|"sspsUD"	0x57
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

begin_comment
comment|/*  * PCI BIOS functions  */
end_comment

begin_define
define|#
directive|define
name|PCIBIOS_BIOS_PRESENT
value|0xb101
end_define

begin_define
define|#
directive|define
name|PCIBIOS_READ_CONFIG_BYTE
value|0xb108
end_define

begin_define
define|#
directive|define
name|PCIBIOS_READ_CONFIG_WORD
value|0xb109
end_define

begin_define
define|#
directive|define
name|PCIBIOS_READ_CONFIG_DWORD
value|0xb10a
end_define

begin_define
define|#
directive|define
name|PCIBIOS_WRITE_CONFIG_BYTE
value|0xb10b
end_define

begin_define
define|#
directive|define
name|PCIBIOS_WRITE_CONFIG_WORD
value|0xb10c
end_define

begin_define
define|#
directive|define
name|PCIBIOS_WRITE_CONFIG_DWORD
value|0xb10d
end_define

begin_define
define|#
directive|define
name|PCIBIOS_GET_IRQ_ROUTING
value|0xb10e
end_define

begin_define
define|#
directive|define
name|PCIBIOS_ROUTE_INTERRUPT
value|0xb10f
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

begin_comment
comment|/*  * PCI interrupt routing table.  *  * $PIR in the BIOS segment contains a PIR_table  * int 1a:b106 returns PIR_table in buffer at es:(e)di   * int 1a:b18e returns PIR_table in buffer at es:(e)di   * int 1a:b406 returns es:di pointing to the BIOS PIR_table  */
end_comment

begin_struct
struct|struct
name|PIR_header
block|{
name|int8_t
name|ph_signature
index|[
literal|4
index|]
decl_stmt|;
name|u_int16_t
name|ph_version
decl_stmt|;
name|u_int16_t
name|ph_length
decl_stmt|;
name|u_int8_t
name|ph_router_bus
decl_stmt|;
name|u_int8_t
name|ph_router_dev_fn
decl_stmt|;
name|u_int16_t
name|ph_pci_irqs
decl_stmt|;
name|u_int16_t
name|ph_router_vendor
decl_stmt|;
name|u_int16_t
name|ph_router_device
decl_stmt|;
name|u_int32_t
name|ph_miniport
decl_stmt|;
name|u_int8_t
name|ph_res
index|[
literal|11
index|]
decl_stmt|;
name|u_int8_t
name|ph_checksum
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|PIR_intpin
block|{
name|u_int8_t
name|link
decl_stmt|;
name|u_int16_t
name|irqs
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|PIR_entry
block|{
name|u_int8_t
name|pe_bus
decl_stmt|;
name|u_int8_t
name|pe_res1
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|pe_device
range|:
literal|5
decl_stmt|;
name|struct
name|PIR_intpin
name|pe_intpin
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|pe_slot
decl_stmt|;
name|u_int8_t
name|pe_res3
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|PIR_table
block|{
name|struct
name|PIR_header
name|pt_header
decl_stmt|;
name|struct
name|PIR_entry
name|pt_entry
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * Int 15:E820 'SMAP' structure  *  * XXX add constants for type  */
end_comment

begin_define
define|#
directive|define
name|SMAP_SIG
value|0x534D4150
end_define

begin_comment
comment|/* 'SMAP' */
end_comment

begin_struct
struct|struct
name|bios_smap
block|{
name|u_int64_t
name|base
decl_stmt|;
name|u_int64_t
name|length
decl_stmt|;
name|u_int32_t
name|type
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

end_unit

