begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Tycho Nightingale<tycho.nightingale@pluribusnetworks.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<md5.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<uuid.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmm.h>
end_include

begin_include
include|#
directive|include
file|<vmmapi.h>
end_include

begin_include
include|#
directive|include
file|"bhyverun.h"
end_include

begin_include
include|#
directive|include
file|"smbiostbl.h"
end_include

begin_define
define|#
directive|define
name|MB
value|(1024*1024)
end_define

begin_define
define|#
directive|define
name|GB
value|(1024ULL*1024*1024)
end_define

begin_define
define|#
directive|define
name|SMBIOS_BASE
value|0xF1000
end_define

begin_comment
comment|/* BHYVE_ACPI_BASE - SMBIOS_BASE) */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_MAX_LENGTH
value|(0xF2400 - 0xF1000)
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_BIOS
value|0
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_SYSTEM
value|1
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_CHASSIS
value|3
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_PROCESSOR
value|4
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MEMARRAY
value|16
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MEMDEVICE
value|17
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_MEMARRAYMAP
value|19
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_BOOT
value|32
end_define

begin_define
define|#
directive|define
name|SMBIOS_TYPE_EOT
value|127
end_define

begin_struct
struct|struct
name|smbios_structure
block|{
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|uint16_t
name|handle
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|initializer_func_t
function_decl|)
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|smbios_template_entry
block|{
name|struct
name|smbios_structure
modifier|*
name|entry
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|strings
decl_stmt|;
name|initializer_func_t
name|initializer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * SMBIOS Structure Table Entry Point  */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_ENTRY_EANCHOR
value|"_SM_"
end_define

begin_define
define|#
directive|define
name|SMBIOS_ENTRY_EANCHORLEN
value|4
end_define

begin_define
define|#
directive|define
name|SMBIOS_ENTRY_IANCHOR
value|"_DMI_"
end_define

begin_define
define|#
directive|define
name|SMBIOS_ENTRY_IANCHORLEN
value|5
end_define

begin_struct
struct|struct
name|smbios_entry_point
block|{
name|char
name|eanchor
index|[
literal|4
index|]
decl_stmt|;
comment|/* anchor tag */
name|uint8_t
name|echecksum
decl_stmt|;
comment|/* checksum of entry point structure */
name|uint8_t
name|eplen
decl_stmt|;
comment|/* length in bytes of entry point */
name|uint8_t
name|major
decl_stmt|;
comment|/* major version of the SMBIOS spec */
name|uint8_t
name|minor
decl_stmt|;
comment|/* minor version of the SMBIOS spec */
name|uint16_t
name|maxssize
decl_stmt|;
comment|/* maximum size in bytes of a struct */
name|uint8_t
name|revision
decl_stmt|;
comment|/* entry point structure revision */
name|uint8_t
name|format
index|[
literal|5
index|]
decl_stmt|;
comment|/* entry point rev-specific data */
name|char
name|ianchor
index|[
literal|5
index|]
decl_stmt|;
comment|/* intermediate anchor tag */
name|uint8_t
name|ichecksum
decl_stmt|;
comment|/* intermediate checksum */
name|uint16_t
name|stlen
decl_stmt|;
comment|/* len in bytes of structure table */
name|uint32_t
name|staddr
decl_stmt|;
comment|/* physical addr of structure table */
name|uint16_t
name|stnum
decl_stmt|;
comment|/* number of structure table entries */
name|uint8_t
name|bcdrev
decl_stmt|;
comment|/* BCD value representing DMI ver */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * BIOS Information  */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_FL_ISA
value|0x00000010
end_define

begin_comment
comment|/* ISA is supported */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_FL_PCI
value|0x00000080
end_define

begin_comment
comment|/* PCI is supported */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_FL_SHADOW
value|0x00001000
end_define

begin_comment
comment|/* BIOS shadowing is allowed */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_FL_CDBOOT
value|0x00008000
end_define

begin_comment
comment|/* Boot from CD is supported */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_FL_SELBOOT
value|0x00010000
end_define

begin_comment
comment|/* Selectable Boot supported */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_FL_EDD
value|0x00080000
end_define

begin_comment
comment|/* EDD Spec is supported */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_XB1_FL_ACPI
value|0x00000001
end_define

begin_comment
comment|/* ACPI is supported */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_XB2_FL_BBS
value|0x00000001
end_define

begin_comment
comment|/* BIOS Boot Specification */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_XB2_FL_VM
value|0x00000010
end_define

begin_comment
comment|/* Virtual Machine */
end_comment

begin_struct
struct|struct
name|smbios_table_type0
block|{
name|struct
name|smbios_structure
name|header
decl_stmt|;
name|uint8_t
name|vendor
decl_stmt|;
comment|/* vendor string */
name|uint8_t
name|version
decl_stmt|;
comment|/* version string */
name|uint16_t
name|segment
decl_stmt|;
comment|/* address segment location */
name|uint8_t
name|rel_date
decl_stmt|;
comment|/* release date */
name|uint8_t
name|size
decl_stmt|;
comment|/* rom size */
name|uint64_t
name|cflags
decl_stmt|;
comment|/* characteristics */
name|uint8_t
name|xc_bytes
index|[
literal|2
index|]
decl_stmt|;
comment|/* characteristics ext bytes */
name|uint8_t
name|sb_major_rel
decl_stmt|;
comment|/* system bios version */
name|uint8_t
name|sb_minor_rele
decl_stmt|;
name|uint8_t
name|ecfw_major_rel
decl_stmt|;
comment|/* embedded ctrl fw version */
name|uint8_t
name|ecfw_minor_rel
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * System Information  */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_WAKEUP_SWITCH
value|0x06
end_define

begin_comment
comment|/* power switch */
end_comment

begin_struct
struct|struct
name|smbios_table_type1
block|{
name|struct
name|smbios_structure
name|header
decl_stmt|;
name|uint8_t
name|manufacturer
decl_stmt|;
comment|/* manufacturer string */
name|uint8_t
name|product
decl_stmt|;
comment|/* product name string */
name|uint8_t
name|version
decl_stmt|;
comment|/* version string */
name|uint8_t
name|serial
decl_stmt|;
comment|/* serial number string */
name|uint8_t
name|uuid
index|[
literal|16
index|]
decl_stmt|;
comment|/* uuid byte array */
name|uint8_t
name|wakeup
decl_stmt|;
comment|/* wake-up event */
name|uint8_t
name|sku
decl_stmt|;
comment|/* sku number string */
name|uint8_t
name|family
decl_stmt|;
comment|/* family name string */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * System Enclosure or Chassis  */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_CHT_UNKNOWN
value|0x02
end_define

begin_comment
comment|/* unknown */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_CHST_SAFE
value|0x03
end_define

begin_comment
comment|/* safe */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_CHSC_NONE
value|0x03
end_define

begin_comment
comment|/* none */
end_comment

begin_struct
struct|struct
name|smbios_table_type3
block|{
name|struct
name|smbios_structure
name|header
decl_stmt|;
name|uint8_t
name|manufacturer
decl_stmt|;
comment|/* manufacturer string */
name|uint8_t
name|type
decl_stmt|;
comment|/* type */
name|uint8_t
name|version
decl_stmt|;
comment|/* version string */
name|uint8_t
name|serial
decl_stmt|;
comment|/* serial number string */
name|uint8_t
name|asset
decl_stmt|;
comment|/* asset tag string */
name|uint8_t
name|bustate
decl_stmt|;
comment|/* boot-up state */
name|uint8_t
name|psstate
decl_stmt|;
comment|/* power supply state */
name|uint8_t
name|tstate
decl_stmt|;
comment|/* thermal state */
name|uint8_t
name|security
decl_stmt|;
comment|/* security status */
name|uint8_t
name|uheight
decl_stmt|;
comment|/* height in 'u's */
name|uint8_t
name|cords
decl_stmt|;
comment|/* number of power cords */
name|uint8_t
name|elems
decl_stmt|;
comment|/* number of element records */
name|uint8_t
name|elemlen
decl_stmt|;
comment|/* length of records */
name|uint8_t
name|sku
decl_stmt|;
comment|/* sku number string */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Processor Information  */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_PRT_CENTRAL
value|0x03
end_define

begin_comment
comment|/* central processor */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_PRF_OTHER
value|0x01
end_define

begin_comment
comment|/* other */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_PRS_PRESENT
value|0x40
end_define

begin_comment
comment|/* socket is populated */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_PRS_ENABLED
value|0x1
end_define

begin_comment
comment|/* enabled */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_PRU_NONE
value|0x06
end_define

begin_comment
comment|/* none */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_PFL_64B
value|0x04
end_define

begin_comment
comment|/* 64-bit capable */
end_comment

begin_struct
struct|struct
name|smbios_table_type4
block|{
name|struct
name|smbios_structure
name|header
decl_stmt|;
name|uint8_t
name|socket
decl_stmt|;
comment|/* socket designation string */
name|uint8_t
name|type
decl_stmt|;
comment|/* processor type */
name|uint8_t
name|family
decl_stmt|;
comment|/* processor family */
name|uint8_t
name|manufacturer
decl_stmt|;
comment|/* manufacturer string */
name|uint64_t
name|cpuid
decl_stmt|;
comment|/* processor cpuid */
name|uint8_t
name|version
decl_stmt|;
comment|/* version string */
name|uint8_t
name|voltage
decl_stmt|;
comment|/* voltage */
name|uint16_t
name|clkspeed
decl_stmt|;
comment|/* ext clock speed in mhz */
name|uint16_t
name|maxspeed
decl_stmt|;
comment|/* maximum speed in mhz */
name|uint16_t
name|curspeed
decl_stmt|;
comment|/* current speed in mhz */
name|uint8_t
name|status
decl_stmt|;
comment|/* status */
name|uint8_t
name|upgrade
decl_stmt|;
comment|/* upgrade */
name|uint16_t
name|l1handle
decl_stmt|;
comment|/* l1 cache handle */
name|uint16_t
name|l2handle
decl_stmt|;
comment|/* l2 cache handle */
name|uint16_t
name|l3handle
decl_stmt|;
comment|/* l3 cache handle */
name|uint8_t
name|serial
decl_stmt|;
comment|/* serial number string */
name|uint8_t
name|asset
decl_stmt|;
comment|/* asset tag string */
name|uint8_t
name|part
decl_stmt|;
comment|/* part number string */
name|uint8_t
name|cores
decl_stmt|;
comment|/* cores per socket */
name|uint8_t
name|ecores
decl_stmt|;
comment|/* enabled cores */
name|uint8_t
name|threads
decl_stmt|;
comment|/* threads per socket */
name|uint16_t
name|cflags
decl_stmt|;
comment|/* processor characteristics */
name|uint16_t
name|family2
decl_stmt|;
comment|/* processor family 2 */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Physical Memory Array  */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_MAL_SYSMB
value|0x03
end_define

begin_comment
comment|/* system board or motherboard */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_MAU_SYSTEM
value|0x03
end_define

begin_comment
comment|/* system memory */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_MAE_NONE
value|0x03
end_define

begin_comment
comment|/* none */
end_comment

begin_struct
struct|struct
name|smbios_table_type16
block|{
name|struct
name|smbios_structure
name|header
decl_stmt|;
name|uint8_t
name|location
decl_stmt|;
comment|/* physical device location */
name|uint8_t
name|use
decl_stmt|;
comment|/* device functional purpose */
name|uint8_t
name|ecc
decl_stmt|;
comment|/* err detect/correct method */
name|uint32_t
name|size
decl_stmt|;
comment|/* max mem capacity in kb */
name|uint16_t
name|errhand
decl_stmt|;
comment|/* handle of error (if any) */
name|uint16_t
name|ndevs
decl_stmt|;
comment|/* num of slots or sockets */
name|uint64_t
name|xsize
decl_stmt|;
comment|/* max mem capacity in bytes */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Memory Device  */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_MDFF_UNKNOWN
value|0x02
end_define

begin_comment
comment|/* unknown */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_MDT_UNKNOWN
value|0x02
end_define

begin_comment
comment|/* unknown */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_MDF_UNKNOWN
value|0x0004
end_define

begin_comment
comment|/* unknown */
end_comment

begin_struct
struct|struct
name|smbios_table_type17
block|{
name|struct
name|smbios_structure
name|header
decl_stmt|;
name|uint16_t
name|arrayhand
decl_stmt|;
comment|/* handle of physl mem array */
name|uint16_t
name|errhand
decl_stmt|;
comment|/* handle of mem error data */
name|uint16_t
name|twidth
decl_stmt|;
comment|/* total width in bits */
name|uint16_t
name|dwidth
decl_stmt|;
comment|/* data width in bits */
name|uint16_t
name|size
decl_stmt|;
comment|/* size in bytes */
name|uint8_t
name|form
decl_stmt|;
comment|/* form factor */
name|uint8_t
name|set
decl_stmt|;
comment|/* set */
name|uint8_t
name|dloc
decl_stmt|;
comment|/* device locator string */
name|uint8_t
name|bloc
decl_stmt|;
comment|/* phys bank locator string */
name|uint8_t
name|type
decl_stmt|;
comment|/* memory type */
name|uint16_t
name|flags
decl_stmt|;
comment|/* memory characteristics */
name|uint16_t
name|maxspeed
decl_stmt|;
comment|/* maximum speed in mhz */
name|uint8_t
name|manufacturer
decl_stmt|;
comment|/* manufacturer string */
name|uint8_t
name|serial
decl_stmt|;
comment|/* serial number string */
name|uint8_t
name|asset
decl_stmt|;
comment|/* asset tag string */
name|uint8_t
name|part
decl_stmt|;
comment|/* part number string */
name|uint8_t
name|attributes
decl_stmt|;
comment|/* attributes */
name|uint32_t
name|xsize
decl_stmt|;
comment|/* extended size in mbs */
name|uint16_t
name|curspeed
decl_stmt|;
comment|/* current speed in mhz */
name|uint16_t
name|minvoltage
decl_stmt|;
comment|/* minimum voltage */
name|uint16_t
name|maxvoltage
decl_stmt|;
comment|/* maximum voltage */
name|uint16_t
name|curvoltage
decl_stmt|;
comment|/* configured voltage */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Memory Array Mapped Address  */
end_comment

begin_struct
struct|struct
name|smbios_table_type19
block|{
name|struct
name|smbios_structure
name|header
decl_stmt|;
name|uint32_t
name|saddr
decl_stmt|;
comment|/* start phys addr in kb */
name|uint32_t
name|eaddr
decl_stmt|;
comment|/* end phys addr in kb */
name|uint16_t
name|arrayhand
decl_stmt|;
comment|/* physical mem array handle */
name|uint8_t
name|width
decl_stmt|;
comment|/* num of dev in row */
name|uint64_t
name|xsaddr
decl_stmt|;
comment|/* start phys addr in bytes */
name|uint64_t
name|xeaddr
decl_stmt|;
comment|/* end phys addr in bytes */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * System Boot Information  */
end_comment

begin_define
define|#
directive|define
name|SMBIOS_BOOT_NORMAL
value|0
end_define

begin_comment
comment|/* no errors detected */
end_comment

begin_struct
struct|struct
name|smbios_table_type32
block|{
name|struct
name|smbios_structure
name|header
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
comment|/* boot status */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * End-of-Table  */
end_comment

begin_struct
struct|struct
name|smbios_table_type127
block|{
name|struct
name|smbios_structure
name|header
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_decl_stmt
name|struct
name|smbios_table_type0
name|smbios_type0_template
init|=
block|{
block|{
name|SMBIOS_TYPE_BIOS
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_table_type0
argument_list|)
block|,
literal|0
block|}
block|,
literal|1
block|,
comment|/* bios vendor string */
literal|2
block|,
comment|/* bios version string */
literal|0xF000
block|,
comment|/* bios address segment location */
literal|3
block|,
comment|/* bios release date */
literal|0x0
block|,
comment|/* bios size (64k * (n + 1) is the size in bytes) */
name|SMBIOS_FL_ISA
operator||
name|SMBIOS_FL_PCI
operator||
name|SMBIOS_FL_SHADOW
operator||
name|SMBIOS_FL_CDBOOT
operator||
name|SMBIOS_FL_EDD
block|,
block|{
name|SMBIOS_XB1_FL_ACPI
block|,
name|SMBIOS_XB2_FL_BBS
operator||
name|SMBIOS_XB2_FL_VM
block|}
block|,
literal|0x0
block|,
comment|/* bios major release */
literal|0x0
block|,
comment|/* bios minor release */
literal|0xff
block|,
comment|/* embedded controller firmware major release */
literal|0xff
comment|/* embedded controller firmware minor release */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|smbios_type0_strings
index|[]
init|=
block|{
literal|"BHYVE"
block|,
comment|/* vendor string */
name|__TIME__
block|,
comment|/* bios version string */
name|__DATE__
block|,
comment|/* bios release date string */
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|smbios_table_type1
name|smbios_type1_template
init|=
block|{
block|{
name|SMBIOS_TYPE_SYSTEM
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_table_type1
argument_list|)
block|,
literal|0
block|}
block|,
literal|1
block|,
comment|/* manufacturer string */
literal|2
block|,
comment|/* product string */
literal|3
block|,
comment|/* version string */
literal|4
block|,
comment|/* serial number string */
block|{
literal|0
block|}
block|,
name|SMBIOS_WAKEUP_SWITCH
block|,
literal|5
block|,
comment|/* sku string */
literal|6
comment|/* family string */
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|smbios_type1_initializer
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|const
name|char
modifier|*
name|smbios_type1_strings
index|[]
init|=
block|{
literal|" "
block|,
comment|/* manufacturer string */
literal|"BHYVE"
block|,
comment|/* product name string */
literal|"1.0"
block|,
comment|/* version string */
literal|"None"
block|,
comment|/* serial number string */
literal|"None"
block|,
comment|/* sku string */
literal|" "
block|,
comment|/* family name string */
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|smbios_table_type3
name|smbios_type3_template
init|=
block|{
block|{
name|SMBIOS_TYPE_CHASSIS
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_table_type3
argument_list|)
block|,
literal|0
block|}
block|,
literal|1
block|,
comment|/* manufacturer string */
name|SMBIOS_CHT_UNKNOWN
block|,
literal|2
block|,
comment|/* version string */
literal|3
block|,
comment|/* serial number string */
literal|4
block|,
comment|/* asset tag string */
name|SMBIOS_CHST_SAFE
block|,
name|SMBIOS_CHST_SAFE
block|,
name|SMBIOS_CHST_SAFE
block|,
name|SMBIOS_CHSC_NONE
block|,
literal|0
block|,
comment|/* height in 'u's (0=enclosure height unspecified) */
literal|0
block|,
comment|/* number of power cords (0=number unspecified) */
literal|0
block|,
comment|/* number of contained element records */
literal|0
block|,
comment|/* length of records */
literal|5
comment|/* sku number string */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|smbios_type3_strings
index|[]
init|=
block|{
literal|" "
block|,
comment|/* manufacturer string */
literal|"1.0"
block|,
comment|/* version string */
literal|"None"
block|,
comment|/* serial number string */
literal|"None"
block|,
comment|/* asset tag string */
literal|"None"
block|,
comment|/* sku number string */
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|smbios_table_type4
name|smbios_type4_template
init|=
block|{
block|{
name|SMBIOS_TYPE_PROCESSOR
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_table_type4
argument_list|)
block|,
literal|0
block|}
block|,
literal|1
block|,
comment|/* socket designation string */
name|SMBIOS_PRT_CENTRAL
block|,
name|SMBIOS_PRF_OTHER
block|,
literal|2
block|,
comment|/* manufacturer string */
literal|0
block|,
comment|/* cpuid */
literal|3
block|,
comment|/* version string */
literal|0
block|,
comment|/* voltage */
literal|0
block|,
comment|/* external clock frequency in mhz (0=unknown) */
literal|0
block|,
comment|/* maximum frequency in mhz (0=unknown) */
literal|0
block|,
comment|/* current frequency in mhz (0=unknown) */
name|SMBIOS_PRS_PRESENT
operator||
name|SMBIOS_PRS_ENABLED
block|,
name|SMBIOS_PRU_NONE
block|,
operator|-
literal|1
block|,
comment|/* l1 cache handle */
operator|-
literal|1
block|,
comment|/* l2 cache handle */
operator|-
literal|1
block|,
comment|/* l3 cache handle */
literal|4
block|,
comment|/* serial number string */
literal|5
block|,
comment|/* asset tag string */
literal|6
block|,
comment|/* part number string */
literal|0
block|,
comment|/* cores per socket (0=unknown) */
literal|0
block|,
comment|/* enabled cores per socket (0=unknown) */
literal|0
block|,
comment|/* threads per socket (0=unknown) */
name|SMBIOS_PFL_64B
block|,
name|SMBIOS_PRF_OTHER
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|smbios_type4_strings
index|[]
init|=
block|{
literal|" "
block|,
comment|/* socket designation string */
literal|" "
block|,
comment|/* manufacturer string */
literal|" "
block|,
comment|/* version string */
literal|"None"
block|,
comment|/* serial number string */
literal|"None"
block|,
comment|/* asset tag string */
literal|"None"
block|,
comment|/* part number string */
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|smbios_type4_initializer
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|smbios_table_type16
name|smbios_type16_template
init|=
block|{
block|{
name|SMBIOS_TYPE_MEMARRAY
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_table_type16
argument_list|)
block|,
literal|0
block|}
block|,
name|SMBIOS_MAL_SYSMB
block|,
name|SMBIOS_MAU_SYSTEM
block|,
name|SMBIOS_MAE_NONE
block|,
literal|0x80000000
block|,
comment|/* max mem capacity in kb (0x80000000=use extended) */
operator|-
literal|1
block|,
comment|/* handle of error (if any) */
literal|0
block|,
comment|/* number of slots or sockets (TBD) */
literal|0
comment|/* extended maximum memory capacity in bytes (TBD) */
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|smbios_type16_initializer
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|smbios_table_type17
name|smbios_type17_template
init|=
block|{
block|{
name|SMBIOS_TYPE_MEMDEVICE
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_table_type17
argument_list|)
block|,
literal|0
block|}
block|,
operator|-
literal|1
block|,
comment|/* handle of physical memory array */
operator|-
literal|1
block|,
comment|/* handle of memory error data */
literal|64
block|,
comment|/* total width in bits including ecc */
literal|64
block|,
comment|/* data width in bits */
literal|0x7fff
block|,
comment|/* size in bytes (0x7fff=use extended)*/
name|SMBIOS_MDFF_UNKNOWN
block|,
literal|0
block|,
comment|/* set (0x00=none, 0xff=unknown) */
literal|1
block|,
comment|/* device locator string */
literal|2
block|,
comment|/* physical bank locator string */
name|SMBIOS_MDT_UNKNOWN
block|,
name|SMBIOS_MDF_UNKNOWN
block|,
literal|0
block|,
comment|/* maximum memory speed in mhz (0=unknown) */
literal|3
block|,
comment|/* manufacturer string */
literal|4
block|,
comment|/* serial number string */
literal|5
block|,
comment|/* asset tag string */
literal|6
block|,
comment|/* part number string */
literal|0
block|,
comment|/* attributes (0=unknown rank information) */
literal|0
block|,
comment|/* extended size in mb (TBD) */
literal|0
block|,
comment|/* current speed in mhz (0=unknown) */
literal|0
block|,
comment|/* minimum voltage in mv (0=unknown) */
literal|0
block|,
comment|/* maximum voltage in mv (0=unknown) */
literal|0
comment|/* configured voltage in mv (0=unknown) */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|smbios_type17_strings
index|[]
init|=
block|{
literal|" "
block|,
comment|/* device locator string */
literal|" "
block|,
comment|/* physical bank locator string */
literal|" "
block|,
comment|/* manufacturer string */
literal|"None"
block|,
comment|/* serial number string */
literal|"None"
block|,
comment|/* asset tag string */
literal|"None"
block|,
comment|/* part number string */
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|smbios_type17_initializer
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|smbios_table_type19
name|smbios_type19_template
init|=
block|{
block|{
name|SMBIOS_TYPE_MEMARRAYMAP
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_table_type19
argument_list|)
block|,
literal|0
block|}
block|,
literal|0xffffffff
block|,
comment|/* starting phys addr in kb (0xffffffff=use ext) */
literal|0xffffffff
block|,
comment|/* ending phys addr in kb (0xffffffff=use ext) */
operator|-
literal|1
block|,
comment|/* physical memory array handle */
literal|1
block|,
comment|/* number of devices that form a row */
literal|0
block|,
comment|/* extended starting phys addr in bytes (TDB) */
literal|0
comment|/* extended ending phys addr in bytes (TDB) */
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|smbios_type19_initializer
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|smbios_table_type32
name|smbios_type32_template
init|=
block|{
block|{
name|SMBIOS_TYPE_BOOT
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_table_type32
argument_list|)
block|,
literal|0
block|}
block|,
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
name|SMBIOS_BOOT_NORMAL
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|smbios_table_type127
name|smbios_type127_template
init|=
block|{
block|{
name|SMBIOS_TYPE_EOT
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_table_type127
argument_list|)
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|smbios_generic_initializer
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|struct
name|smbios_template_entry
name|smbios_template
index|[]
init|=
block|{
block|{
operator|(
expr|struct
name|smbios_structure
operator|*
operator|)
operator|&
name|smbios_type0_template
block|,
name|smbios_type0_strings
block|,
name|smbios_generic_initializer
block|}
block|,
block|{
operator|(
expr|struct
name|smbios_structure
operator|*
operator|)
operator|&
name|smbios_type1_template
block|,
name|smbios_type1_strings
block|,
name|smbios_type1_initializer
block|}
block|,
block|{
operator|(
expr|struct
name|smbios_structure
operator|*
operator|)
operator|&
name|smbios_type3_template
block|,
name|smbios_type3_strings
block|,
name|smbios_generic_initializer
block|}
block|,
block|{
operator|(
expr|struct
name|smbios_structure
operator|*
operator|)
operator|&
name|smbios_type4_template
block|,
name|smbios_type4_strings
block|,
name|smbios_type4_initializer
block|}
block|,
block|{
operator|(
expr|struct
name|smbios_structure
operator|*
operator|)
operator|&
name|smbios_type16_template
block|,
name|NULL
block|,
name|smbios_type16_initializer
block|}
block|,
block|{
operator|(
expr|struct
name|smbios_structure
operator|*
operator|)
operator|&
name|smbios_type17_template
block|,
name|smbios_type17_strings
block|,
name|smbios_type17_initializer
block|}
block|,
block|{
operator|(
expr|struct
name|smbios_structure
operator|*
operator|)
operator|&
name|smbios_type19_template
block|,
name|NULL
block|,
name|smbios_type19_initializer
block|}
block|,
block|{
operator|(
expr|struct
name|smbios_structure
operator|*
operator|)
operator|&
name|smbios_type32_template
block|,
name|NULL
block|,
name|smbios_generic_initializer
block|}
block|,
block|{
operator|(
expr|struct
name|smbios_structure
operator|*
operator|)
operator|&
name|smbios_type127_template
block|,
name|NULL
block|,
name|smbios_generic_initializer
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint64_t
name|guest_lomem
decl_stmt|,
name|guest_himem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint16_t
name|type16_handle
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|smbios_generic_initializer
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
block|{
name|struct
name|smbios_structure
modifier|*
name|entry
decl_stmt|;
name|memcpy
argument_list|(
name|curaddr
argument_list|,
name|template_entry
argument_list|,
name|template_entry
operator|->
name|length
argument_list|)
expr_stmt|;
name|entry
operator|=
operator|(
expr|struct
name|smbios_structure
operator|*
operator|)
name|curaddr
expr_stmt|;
name|entry
operator|->
name|handle
operator|=
operator|*
name|n
operator|+
literal|1
expr_stmt|;
name|curaddr
operator|+=
name|entry
operator|->
name|length
expr_stmt|;
if|if
condition|(
name|template_strings
operator|!=
name|NULL
condition|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|template_strings
index|[
name|i
index|]
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
name|int
name|len
decl_stmt|;
name|string
operator|=
name|template_strings
index|[
name|i
index|]
expr_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|string
argument_list|)
operator|+
literal|1
expr_stmt|;
name|memcpy
argument_list|(
name|curaddr
argument_list|,
name|string
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|curaddr
operator|+=
name|len
expr_stmt|;
block|}
operator|*
name|curaddr
operator|=
literal|'\0'
expr_stmt|;
name|curaddr
operator|++
expr_stmt|;
block|}
else|else
block|{
comment|/* Minimum string section is double nul */
operator|*
name|curaddr
operator|=
literal|'\0'
expr_stmt|;
name|curaddr
operator|++
expr_stmt|;
operator|*
name|curaddr
operator|=
literal|'\0'
expr_stmt|;
name|curaddr
operator|++
expr_stmt|;
block|}
operator|(
operator|*
name|n
operator|)
operator|++
expr_stmt|;
operator|*
name|endaddr
operator|=
name|curaddr
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|smbios_type1_initializer
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
block|{
name|struct
name|smbios_table_type1
modifier|*
name|type1
decl_stmt|;
name|smbios_generic_initializer
argument_list|(
name|template_entry
argument_list|,
name|template_strings
argument_list|,
name|curaddr
argument_list|,
name|endaddr
argument_list|,
name|n
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|type1
operator|=
operator|(
expr|struct
name|smbios_table_type1
operator|*
operator|)
name|curaddr
expr_stmt|;
if|if
condition|(
name|guest_uuid_str
operator|!=
name|NULL
condition|)
block|{
name|uuid_t
name|uuid
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
name|uuid_from_string
argument_list|(
name|guest_uuid_str
argument_list|,
operator|&
name|uuid
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|!=
name|uuid_s_ok
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|uuid_enc_le
argument_list|(
operator|&
name|type1
operator|->
name|uuid
argument_list|,
operator|&
name|uuid
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|MD5_CTX
name|mdctx
decl_stmt|;
name|u_char
name|digest
index|[
literal|16
index|]
decl_stmt|;
name|char
name|hostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
comment|/* 		 * Universally unique and yet reproducible are an 		 * oxymoron, however reproducible is desirable in 		 * this case. 		 */
if|if
condition|(
name|gethostname
argument_list|(
name|hostname
argument_list|,
sizeof|sizeof
argument_list|(
name|hostname
argument_list|)
argument_list|)
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
name|MD5Init
argument_list|(
operator|&
name|mdctx
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|mdctx
argument_list|,
name|vmname
argument_list|,
name|strlen
argument_list|(
name|vmname
argument_list|)
argument_list|)
expr_stmt|;
name|MD5Update
argument_list|(
operator|&
name|mdctx
argument_list|,
name|hostname
argument_list|,
sizeof|sizeof
argument_list|(
name|hostname
argument_list|)
argument_list|)
expr_stmt|;
name|MD5Final
argument_list|(
name|digest
argument_list|,
operator|&
name|mdctx
argument_list|)
expr_stmt|;
comment|/* 		 * Set the variant and version number. 		 */
name|digest
index|[
literal|6
index|]
operator|&=
literal|0x0F
expr_stmt|;
name|digest
index|[
literal|6
index|]
operator||=
literal|0x30
expr_stmt|;
comment|/* version 3 */
name|digest
index|[
literal|8
index|]
operator|&=
literal|0x3F
expr_stmt|;
name|digest
index|[
literal|8
index|]
operator||=
literal|0x80
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|type1
operator|->
name|uuid
argument_list|,
name|digest
argument_list|,
sizeof|sizeof
argument_list|(
name|digest
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|smbios_type4_initializer
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|guest_ncpus
condition|;
name|i
operator|++
control|)
block|{
name|struct
name|smbios_table_type4
modifier|*
name|type4
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
name|int
name|nstrings
decl_stmt|,
name|len
decl_stmt|;
name|smbios_generic_initializer
argument_list|(
name|template_entry
argument_list|,
name|template_strings
argument_list|,
name|curaddr
argument_list|,
name|endaddr
argument_list|,
name|n
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|type4
operator|=
operator|(
expr|struct
name|smbios_table_type4
operator|*
operator|)
name|curaddr
expr_stmt|;
name|p
operator|=
name|curaddr
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_table_type4
argument_list|)
expr_stmt|;
name|nstrings
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|p
operator|<
operator|*
name|endaddr
operator|-
literal|1
condition|)
block|{
if|if
condition|(
operator|*
name|p
operator|++
operator|==
literal|'\0'
condition|)
name|nstrings
operator|++
expr_stmt|;
block|}
name|len
operator|=
name|sprintf
argument_list|(
operator|*
name|endaddr
operator|-
literal|1
argument_list|,
literal|"CPU #%d"
argument_list|,
name|i
argument_list|)
operator|+
literal|1
expr_stmt|;
operator|*
name|endaddr
operator|+=
name|len
operator|-
literal|1
expr_stmt|;
operator|*
operator|(
operator|*
name|endaddr
operator|)
operator|=
literal|'\0'
expr_stmt|;
operator|(
operator|*
name|endaddr
operator|)
operator|++
expr_stmt|;
name|type4
operator|->
name|socket
operator|=
name|nstrings
operator|+
literal|1
expr_stmt|;
name|curaddr
operator|=
operator|*
name|endaddr
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|smbios_type16_initializer
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
block|{
name|struct
name|smbios_table_type16
modifier|*
name|type16
decl_stmt|;
name|type16_handle
operator|=
operator|*
name|n
expr_stmt|;
name|smbios_generic_initializer
argument_list|(
name|template_entry
argument_list|,
name|template_strings
argument_list|,
name|curaddr
argument_list|,
name|endaddr
argument_list|,
name|n
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|type16
operator|=
operator|(
expr|struct
name|smbios_table_type16
operator|*
operator|)
name|curaddr
expr_stmt|;
name|type16
operator|->
name|xsize
operator|=
name|guest_lomem
operator|+
name|guest_himem
expr_stmt|;
name|type16
operator|->
name|ndevs
operator|=
name|guest_himem
operator|>
literal|0
condition|?
literal|2
else|:
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|smbios_type17_initializer
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
block|{
name|struct
name|smbios_table_type17
modifier|*
name|type17
decl_stmt|;
name|smbios_generic_initializer
argument_list|(
name|template_entry
argument_list|,
name|template_strings
argument_list|,
name|curaddr
argument_list|,
name|endaddr
argument_list|,
name|n
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|type17
operator|=
operator|(
expr|struct
name|smbios_table_type17
operator|*
operator|)
name|curaddr
expr_stmt|;
name|type17
operator|->
name|arrayhand
operator|=
name|type16_handle
expr_stmt|;
name|type17
operator|->
name|xsize
operator|=
name|guest_lomem
expr_stmt|;
if|if
condition|(
name|guest_himem
operator|>
literal|0
condition|)
block|{
name|curaddr
operator|=
operator|*
name|endaddr
expr_stmt|;
name|smbios_generic_initializer
argument_list|(
name|template_entry
argument_list|,
name|template_strings
argument_list|,
name|curaddr
argument_list|,
name|endaddr
argument_list|,
name|n
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|type17
operator|=
operator|(
expr|struct
name|smbios_table_type17
operator|*
operator|)
name|curaddr
expr_stmt|;
name|type17
operator|->
name|arrayhand
operator|=
name|type16_handle
expr_stmt|;
name|type17
operator|->
name|xsize
operator|=
name|guest_himem
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|smbios_type19_initializer
parameter_list|(
name|struct
name|smbios_structure
modifier|*
name|template_entry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|template_strings
parameter_list|,
name|char
modifier|*
name|curaddr
parameter_list|,
name|char
modifier|*
modifier|*
name|endaddr
parameter_list|,
name|uint16_t
modifier|*
name|n
parameter_list|,
name|uint16_t
modifier|*
name|size
parameter_list|)
block|{
name|struct
name|smbios_table_type19
modifier|*
name|type19
decl_stmt|;
name|smbios_generic_initializer
argument_list|(
name|template_entry
argument_list|,
name|template_strings
argument_list|,
name|curaddr
argument_list|,
name|endaddr
argument_list|,
name|n
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|type19
operator|=
operator|(
expr|struct
name|smbios_table_type19
operator|*
operator|)
name|curaddr
expr_stmt|;
name|type19
operator|->
name|arrayhand
operator|=
name|type16_handle
expr_stmt|;
name|type19
operator|->
name|xsaddr
operator|=
literal|0
expr_stmt|;
name|type19
operator|->
name|xeaddr
operator|=
name|guest_lomem
expr_stmt|;
if|if
condition|(
name|guest_himem
operator|>
literal|0
condition|)
block|{
name|curaddr
operator|=
operator|*
name|endaddr
expr_stmt|;
name|smbios_generic_initializer
argument_list|(
name|template_entry
argument_list|,
name|template_strings
argument_list|,
name|curaddr
argument_list|,
name|endaddr
argument_list|,
name|n
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|type19
operator|=
operator|(
expr|struct
name|smbios_table_type19
operator|*
operator|)
name|curaddr
expr_stmt|;
name|type19
operator|->
name|arrayhand
operator|=
name|type16_handle
expr_stmt|;
name|type19
operator|->
name|xsaddr
operator|=
literal|4
operator|*
name|GB
expr_stmt|;
name|type19
operator|->
name|xeaddr
operator|=
name|guest_himem
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|smbios_ep_initializer
parameter_list|(
name|struct
name|smbios_entry_point
modifier|*
name|smbios_ep
parameter_list|,
name|uint32_t
name|staddr
parameter_list|)
block|{
name|memset
argument_list|(
name|smbios_ep
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|smbios_ep
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|smbios_ep
operator|->
name|eanchor
argument_list|,
name|SMBIOS_ENTRY_EANCHOR
argument_list|,
name|SMBIOS_ENTRY_EANCHORLEN
argument_list|)
expr_stmt|;
name|smbios_ep
operator|->
name|eplen
operator|=
literal|0x1F
expr_stmt|;
name|assert
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_entry_point
argument_list|)
operator|==
name|smbios_ep
operator|->
name|eplen
argument_list|)
expr_stmt|;
name|smbios_ep
operator|->
name|major
operator|=
literal|2
expr_stmt|;
name|smbios_ep
operator|->
name|minor
operator|=
literal|4
expr_stmt|;
name|smbios_ep
operator|->
name|revision
operator|=
literal|0
expr_stmt|;
name|memcpy
argument_list|(
name|smbios_ep
operator|->
name|ianchor
argument_list|,
name|SMBIOS_ENTRY_IANCHOR
argument_list|,
name|SMBIOS_ENTRY_IANCHORLEN
argument_list|)
expr_stmt|;
name|smbios_ep
operator|->
name|staddr
operator|=
name|staddr
expr_stmt|;
name|smbios_ep
operator|->
name|bcdrev
operator|=
literal|0x24
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|smbios_ep_finalizer
parameter_list|(
name|struct
name|smbios_entry_point
modifier|*
name|smbios_ep
parameter_list|,
name|uint16_t
name|len
parameter_list|,
name|uint16_t
name|num
parameter_list|,
name|uint16_t
name|maxssize
parameter_list|)
block|{
name|uint8_t
name|checksum
decl_stmt|;
name|int
name|i
decl_stmt|;
name|smbios_ep
operator|->
name|maxssize
operator|=
name|maxssize
expr_stmt|;
name|smbios_ep
operator|->
name|stlen
operator|=
name|len
expr_stmt|;
name|smbios_ep
operator|->
name|stnum
operator|=
name|num
expr_stmt|;
name|checksum
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0x10
init|;
name|i
operator|<
literal|0x1f
condition|;
name|i
operator|++
control|)
block|{
name|checksum
operator|-=
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|smbios_ep
operator|)
index|[
name|i
index|]
expr_stmt|;
block|}
name|smbios_ep
operator|->
name|ichecksum
operator|=
name|checksum
expr_stmt|;
name|checksum
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|0x1f
condition|;
name|i
operator|++
control|)
block|{
name|checksum
operator|-=
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|smbios_ep
operator|)
index|[
name|i
index|]
expr_stmt|;
block|}
name|smbios_ep
operator|->
name|echecksum
operator|=
name|checksum
expr_stmt|;
block|}
end_function

begin_function
name|int
name|smbios_build
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|)
block|{
name|struct
name|smbios_entry_point
modifier|*
name|smbios_ep
decl_stmt|;
name|uint16_t
name|n
decl_stmt|;
name|uint16_t
name|maxssize
decl_stmt|;
name|char
modifier|*
name|curaddr
decl_stmt|,
modifier|*
name|startaddr
decl_stmt|,
modifier|*
name|ststartaddr
decl_stmt|;
name|int
name|i
decl_stmt|;
name|int
name|err
decl_stmt|;
name|guest_lomem
operator|=
name|vm_get_lowmem_size
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|guest_himem
operator|=
name|vm_get_highmem_size
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|startaddr
operator|=
name|paddr_guest2host
argument_list|(
name|ctx
argument_list|,
name|SMBIOS_BASE
argument_list|,
name|SMBIOS_MAX_LENGTH
argument_list|)
expr_stmt|;
if|if
condition|(
name|startaddr
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"smbios table requires mapped mem\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENOMEM
operator|)
return|;
block|}
name|curaddr
operator|=
name|startaddr
expr_stmt|;
name|smbios_ep
operator|=
operator|(
expr|struct
name|smbios_entry_point
operator|*
operator|)
name|curaddr
expr_stmt|;
name|smbios_ep_initializer
argument_list|(
name|smbios_ep
argument_list|,
name|SMBIOS_BASE
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_entry_point
argument_list|)
argument_list|)
expr_stmt|;
name|curaddr
operator|+=
sizeof|sizeof
argument_list|(
expr|struct
name|smbios_entry_point
argument_list|)
expr_stmt|;
name|ststartaddr
operator|=
name|curaddr
expr_stmt|;
name|n
operator|=
literal|0
expr_stmt|;
name|maxssize
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|smbios_template
index|[
name|i
index|]
operator|.
name|entry
operator|!=
name|NULL
condition|;
name|i
operator|++
control|)
block|{
name|struct
name|smbios_structure
modifier|*
name|entry
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|strings
decl_stmt|;
name|initializer_func_t
name|initializer
decl_stmt|;
name|char
modifier|*
name|endaddr
decl_stmt|;
name|uint16_t
name|size
decl_stmt|;
name|entry
operator|=
name|smbios_template
index|[
name|i
index|]
operator|.
name|entry
expr_stmt|;
name|strings
operator|=
name|smbios_template
index|[
name|i
index|]
operator|.
name|strings
expr_stmt|;
name|initializer
operator|=
name|smbios_template
index|[
name|i
index|]
operator|.
name|initializer
expr_stmt|;
name|err
operator|=
call|(
modifier|*
name|initializer
call|)
argument_list|(
name|entry
argument_list|,
name|strings
argument_list|,
name|curaddr
argument_list|,
operator|&
name|endaddr
argument_list|,
operator|&
name|n
argument_list|,
operator|&
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
return|return
operator|(
name|err
operator|)
return|;
if|if
condition|(
name|size
operator|>
name|maxssize
condition|)
name|maxssize
operator|=
name|size
expr_stmt|;
name|curaddr
operator|=
name|endaddr
expr_stmt|;
block|}
name|assert
argument_list|(
name|curaddr
operator|-
name|startaddr
operator|<
name|SMBIOS_MAX_LENGTH
argument_list|)
expr_stmt|;
name|smbios_ep_finalizer
argument_list|(
name|smbios_ep
argument_list|,
name|curaddr
operator|-
name|ststartaddr
argument_list|,
name|n
argument_list|,
name|maxssize
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

