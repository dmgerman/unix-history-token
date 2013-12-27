begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Bruce M. Simpson.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIBA_SIBA_IDS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SIBA_SIBA_IDS_H_
end_define

begin_comment
comment|/*  * Constants and structures for SiBa bus enumeration.  */
end_comment

begin_struct
struct|struct
name|siba_devid
block|{
name|uint16_t
name|sd_vendor
decl_stmt|;
name|uint16_t
name|sd_device
decl_stmt|;
name|uint8_t
name|sd_rev
decl_stmt|;
name|char
modifier|*
name|sd_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIBA_DEV
parameter_list|(
name|_vendor
parameter_list|,
name|_cid
parameter_list|,
name|_rev
parameter_list|,
name|_msg
parameter_list|)
define|\
value|{ SIBA_VID_##_vendor, SIBA_DEVID_##_cid, _rev, _msg }
end_define

begin_comment
comment|/*  * Device IDs  */
end_comment

begin_define
define|#
directive|define
name|SIBA_DEVID_ANY
value|0xffff
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_CHIPCOMMON
value|0x800
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_ILINE20
value|0x801
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_SDRAM
value|0x803
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_PCI
value|0x804
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_MIPS
value|0x805
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_ETHERNET
value|0x806
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_MODEM
value|0x807
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_USB11_HOSTDEV
value|0x808
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_ADSL
value|0x809
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_ILINE100
value|0x80a
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_IPSEC
value|0x80b
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_PCMCIA
value|0x80d
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_INTERNAL_MEM
value|0x80e
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_SDRAMDDR
value|0x80f
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_EXTIF
value|0x811
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_80211
value|0x812
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_MIPS_3302
value|0x816
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_USB11_HOST
value|0x817
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_USB11_DEV
value|0x818
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_USB20_HOST
value|0x819
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_USB20_DEV
value|0x81a
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_SDIO_HOST
value|0x81b
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_ROBOSWITCH
value|0x81c
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_PARA_ATA
value|0x81d
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_SATA_XORDMA
value|0x81e
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_ETHERNET_GBIT
value|0x81f
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_PCIE
value|0x820
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_MIMO_PHY
value|0x821
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_SRAM_CTRLR
value|0x822
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_MINI_MACPHY
value|0x823
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_ARM_1176
value|0x824
end_define

begin_define
define|#
directive|define
name|SIBA_DEVID_ARM_7TDMI
value|0x825
end_define

begin_comment
comment|/*  * Vendor IDs  */
end_comment

begin_define
define|#
directive|define
name|SIBA_VID_ANY
value|0xffff
end_define

begin_define
define|#
directive|define
name|SIBA_VID_BROADCOM
value|0x4243
end_define

begin_comment
comment|/*  * Revision IDs  */
end_comment

begin_define
define|#
directive|define
name|SIBA_REV_ANY
value|0xff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_SIBA_SIBA_IDS_H_ */
end_comment

end_unit

