begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 Marc Horowitz.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Marc Horowitz.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * CIS Tuples */
end_comment

begin_comment
comment|/* Layer 1 Basic Compatibility Tuples */
end_comment

begin_define
define|#
directive|define
name|CISTPL_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|CISTPL_DEVICE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCCARD_DTYPE_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|PCCARD_DTYPE_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|PCCARD_DTYPE_ROM
value|0x10
end_define

begin_define
define|#
directive|define
name|PCCARD_DTYPE_OTPROM
value|0x20
end_define

begin_define
define|#
directive|define
name|PCCARD_DTYPE_EPROM
value|0x30
end_define

begin_define
define|#
directive|define
name|PCCARD_DTYPE_EEPROM
value|0x40
end_define

begin_define
define|#
directive|define
name|PCCARD_DTYPE_FLASH
value|0x50
end_define

begin_define
define|#
directive|define
name|PCCARD_DTYPE_SRAM
value|0x60
end_define

begin_define
define|#
directive|define
name|PCCARD_DTYPE_DRAM
value|0x70
end_define

begin_define
define|#
directive|define
name|PCCARD_DTYPE_FUNCSPEC
value|0xD0
end_define

begin_define
define|#
directive|define
name|PCCARD_DTYPE_EXTEND
value|0xE0
end_define

begin_define
define|#
directive|define
name|PCCARD_DSPEED_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|PCCARD_DSPEED_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|PCCARD_DSPEED_250NS
value|0x01
end_define

begin_define
define|#
directive|define
name|PCCARD_DSPEED_200NS
value|0x02
end_define

begin_define
define|#
directive|define
name|PCCARD_DSPEED_150NS
value|0x03
end_define

begin_define
define|#
directive|define
name|PCCARD_DSPEED_100NS
value|0x04
end_define

begin_define
define|#
directive|define
name|PCCARD_DSPEED_EXT
value|0x07
end_define

begin_comment
comment|/*  * the 2.1 docs have 0x02-0x07 as reserved, but the linux drivers list the  * follwing tuple code values.  I have at least one card (3com 3c562  * lan+modem) which has a code 0x06 tuple, so I'm going to assume that these  * are for real  */
end_comment

begin_define
define|#
directive|define
name|CISTPL_LONGLINK_CB
value|0x02
end_define

begin_define
define|#
directive|define
name|CISTPL_INDIRECT
value|0x03
end_define

begin_define
define|#
directive|define
name|CISTPL_CONFIG_CB
value|0x04
end_define

begin_define
define|#
directive|define
name|CISTPL_CFTABLE_ENTRY_CB
value|0x05
end_define

begin_define
define|#
directive|define
name|CISTPL_LONGLINK_MFC
value|0x06
end_define

begin_define
define|#
directive|define
name|PCCARD_MFC_MEM_ATTR
value|0x00
end_define

begin_define
define|#
directive|define
name|PCCARD_MFC_MEM_COMMON
value|0x01
end_define

begin_define
define|#
directive|define
name|CISTPL_BAR
value|0x07
end_define

begin_define
define|#
directive|define
name|CISTPL_PWR_MGMNT
value|0x08
end_define

begin_define
define|#
directive|define
name|CISTPL_EXTDEVICE
value|0x09
end_define

begin_define
define|#
directive|define
name|CISTPL_CHECKSUM
value|0x10
end_define

begin_define
define|#
directive|define
name|CISTPL_LONGLINK_A
value|0x11
end_define

begin_define
define|#
directive|define
name|CISTPL_LONGLINK_C
value|0x12
end_define

begin_define
define|#
directive|define
name|CISTPL_LINKTARGET
value|0x13
end_define

begin_define
define|#
directive|define
name|CISTPL_NO_LINK
value|0x14
end_define

begin_define
define|#
directive|define
name|CISTPL_VERS_1
value|0x15
end_define

begin_define
define|#
directive|define
name|CISTPL_ALTSTR
value|0x16
end_define

begin_define
define|#
directive|define
name|CISTPL_DEVICE_A
value|0x17
end_define

begin_define
define|#
directive|define
name|CISTPL_JEDEC_C
value|0x18
end_define

begin_define
define|#
directive|define
name|CISTPL_JEDEC_A
value|0x19
end_define

begin_define
define|#
directive|define
name|CISTPL_CONFIG
value|0x1A
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCC_RASZ_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCC_RASZ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCC_RMSZ_MASK
value|0x3C
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCC_RMSZ_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCC_RFSZ_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCC_RFSZ_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CISTPL_CFTABLE_ENTRY
value|0x1B
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_INDX_INTFACE
value|0x80
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_INDX_DEFAULT
value|0x40
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_INDX_NUM_MASK
value|0x3F
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IF_MWAIT
value|0x80
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IF_RDYBSY
value|0x40
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IF_WP
value|0x20
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IF_BVD
value|0x10
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IF_IFTYPE
value|0x0F
end_define

begin_define
define|#
directive|define
name|PCCARD_IFTYPE_MEMORY
value|0
end_define

begin_define
define|#
directive|define
name|PCCARD_IFTYPE_IO
value|1
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_MISC
value|0x80
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_MEMSPACE_MASK
value|0x60
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_MEMSPACE_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_MEMSPACE_LENGTH
value|0x20
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_MEMSPACE_LENGTHADDR
value|0x40
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_MEMSPACE_TABLE
value|0x60
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_IRQ
value|0x10
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_IOSPACE
value|0x08
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_TIMING
value|0x04
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_POWER_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_POWER_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_POWER_VCC
value|0x01
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_POWER_VCCVPP1
value|0x02
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_FS_POWER_VCCVPP1VPP2
value|0x03
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_TD_RESERVED_MASK
value|0xE0
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_TD_RDYBSY_MASK
value|0x1C
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_TD_WAIT_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_HASRANGE
value|0x80
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_BUSWIDTH_16BIT
value|0x40
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_BUSWIDTH_8BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_IOADDRLINES_MASK
value|0x1F
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_RANGE_LENGTHSIZE_MASK
value|0xC0
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_RANGE_LENGTHSIZE_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_RANGE_LENGTHSIZE_ONE
value|0x40
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_RANGE_LENGTHSIZE_TWO
value|0x80
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_RANGE_LENGTHSIZE_FOUR
value|0xC0
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_RANGE_ADDRSIZE_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_RANGE_ADDRSIZE_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_RANGE_ADDRSIZE_ONE
value|0x10
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_RANGE_ADDRSIZE_TWO
value|0x20
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_RANGE_ADDRSIZE_FOUR
value|0x30
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IO_RANGE_COUNT
value|0x0F
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IR_SHARE
value|0x80
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IR_PULSE
value|0x40
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IR_LEVEL
value|0x20
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IR_HASMASK
value|0x10
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_IR_IRQ
value|0x0F
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_MS_HOSTADDR
value|0x80
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_MS_CARDADDR_SIZE_MASK
value|0x60
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_MS_CARDADDR_SIZE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_MS_LENGTH_SIZE_MASK
value|0x18
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_MS_LENGTH_SIZE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_MS_COUNT
value|0x07
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_MI_EXT
value|0x80
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_MI_RESERVED
value|0x40
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_MI_PWRDOWN
value|0x20
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_MI_READONLY
value|0x10
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_MI_AUDIO
value|0x08
end_define

begin_define
define|#
directive|define
name|PCCARD_TPCE_MI_MAXTWINS
value|0x07
end_define

begin_define
define|#
directive|define
name|CISTPL_DEVICE_OC
value|0x1C
end_define

begin_define
define|#
directive|define
name|CISTPL_DEVICE_OA
value|0x1D
end_define

begin_define
define|#
directive|define
name|CISTPL_DEVICE_GEO
value|0x1E
end_define

begin_define
define|#
directive|define
name|CISTPL_DEVICE_GEO_A
value|0x1F
end_define

begin_define
define|#
directive|define
name|CISTPL_MANFID
value|0x20
end_define

begin_define
define|#
directive|define
name|CISTPL_FUNCID
value|0x21
end_define

begin_define
define|#
directive|define
name|PCCARD_FUNCTION_UNSPEC
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_FUNCTION_MULTIFUNCTION
value|0
end_define

begin_define
define|#
directive|define
name|PCCARD_FUNCTION_MEMORY
value|1
end_define

begin_define
define|#
directive|define
name|PCCARD_FUNCTION_SERIAL
value|2
end_define

begin_define
define|#
directive|define
name|PCCARD_FUNCTION_PARALLEL
value|3
end_define

begin_define
define|#
directive|define
name|PCCARD_FUNCTION_DISK
value|4
end_define

begin_define
define|#
directive|define
name|PCCARD_FUNCTION_VIDEO
value|5
end_define

begin_define
define|#
directive|define
name|PCCARD_FUNCTION_NETWORK
value|6
end_define

begin_define
define|#
directive|define
name|PCCARD_FUNCTION_AIMS
value|7
end_define

begin_define
define|#
directive|define
name|PCCARD_FUNCTION_SCSI
value|8
end_define

begin_define
define|#
directive|define
name|PCCARD_FUNCTION_SECURITY
value|9
end_define

begin_define
define|#
directive|define
name|PCCARD_FUNCTION_INSTRUMENT
value|10
end_define

begin_define
define|#
directive|define
name|CISTPL_FUNCE
value|0x22
end_define

begin_define
define|#
directive|define
name|PCCARD_TPLFE_TYPE_LAN_TECH
value|0x01
end_define

begin_define
define|#
directive|define
name|PCCARD_TPLFE_TYPE_LAN_SPEED
value|0x02
end_define

begin_define
define|#
directive|define
name|PCCARD_TPLFE_TYPE_LAN_MEDIA
value|0x03
end_define

begin_define
define|#
directive|define
name|PCCARD_TPLFE_TYPE_LAN_NID
value|0x04
end_define

begin_define
define|#
directive|define
name|PCCARD_TPLFE_TYPE_LAN_CONN
value|0x05
end_define

begin_define
define|#
directive|define
name|PCCARD_TPLFE_TYPE_DISK_DEVICE_INTERFACE
value|0x01
end_define

begin_define
define|#
directive|define
name|PCCARD_TPLFE_DDI_PCCARD_ATA
value|0x01
end_define

begin_define
define|#
directive|define
name|CISTPL_END
value|0xFF
end_define

begin_comment
comment|/* Layer 2 Data Recording Format Tuples */
end_comment

begin_define
define|#
directive|define
name|CISTPL_SWIL
value|0x23
end_define

begin_comment
comment|/* #define	CISTPL_RESERVED		0x24-0x3F */
end_comment

begin_define
define|#
directive|define
name|CISTPL_VERS_2
value|0x40
end_define

begin_define
define|#
directive|define
name|CISTPL_FORMAT
value|0x41
end_define

begin_define
define|#
directive|define
name|CISTPL_GEOMETRY
value|0x42
end_define

begin_define
define|#
directive|define
name|CISTPL_BYTEORDER
value|0x43
end_define

begin_define
define|#
directive|define
name|CISTPL_DATE
value|0x44
end_define

begin_define
define|#
directive|define
name|CISTPL_BATTERY
value|0x45
end_define

begin_define
define|#
directive|define
name|CISTPL_FORAMT_A
value|0x47
end_define

begin_comment
comment|/* Layer 3 Data Organization Tuples */
end_comment

begin_define
define|#
directive|define
name|CISTPL_ORG
value|0x46
end_define

begin_comment
comment|/* #define	CISTPL_RESERVED		0x47-0x7F */
end_comment

begin_comment
comment|/* Layer 4 System-Specific Standard Tuples */
end_comment

begin_comment
comment|/* #define	CISTPL_RESERVED		0x80-0x8F */
end_comment

begin_define
define|#
directive|define
name|CISTPL_SPCL
value|0x90
end_define

begin_comment
comment|/* #define	CISTPL_RESERVED		0x90-0xFE */
end_comment

begin_define
define|#
directive|define
name|CISTPL_GENERIC
value|-1
end_define

end_unit

