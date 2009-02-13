begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Takanori Watanabe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *        notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *        notice, this list of conditions and the following disclaimer in the  *        documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.    IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__INTPMREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__INTPMREG_H__
end_define

begin_comment
comment|/* Register definitions for non-ICH Intel Chipset SMBUS controllers. */
end_comment

begin_comment
comment|/* PCI Config Registers. */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDR_SMB
value|0x90
end_define

begin_comment
comment|/* IO BAR. */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_ADDR_PM
value|0x40
end_define

begin_define
define|#
directive|define
name|PCI_HST_CFG_SMB
value|0xd2
end_define

begin_comment
comment|/* Host Configuration */
end_comment

begin_define
define|#
directive|define
name|PCI_INTR_SMB_SMI
value|0
end_define

begin_define
define|#
directive|define
name|PCI_INTR_SMB_IRQ9
value|8
end_define

begin_define
define|#
directive|define
name|PCI_INTR_SMB_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|PCI_SLV_CMD_SMB
value|0xd3
end_define

begin_comment
comment|/*SLAVE COMMAND*/
end_comment

begin_define
define|#
directive|define
name|PCI_SLV_SDW_SMB_1
value|0xd4
end_define

begin_comment
comment|/*SLAVE SHADOW PORT 1*/
end_comment

begin_define
define|#
directive|define
name|PCI_SLV_SDW_SMB_2
value|0xd5
end_define

begin_comment
comment|/*SLAVE SHADOW PORT 2*/
end_comment

begin_define
define|#
directive|define
name|PCI_REVID_SMB
value|0xd6
end_define

begin_comment
comment|/* PIXX4 SMBus Registers in the SMB BAR. */
end_comment

begin_define
define|#
directive|define
name|PIIX4_SMBHSTSTS
value|0x00
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTSTAT_BUSY
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTSTAT_INTR
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTSTAT_ERR
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTSTAT_BUSC
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTSTAT_FAIL
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVSTS
value|0x01
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVSTS_ALART
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVSTS_SDW2
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVSTS_SDW1
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVSTS_SLV
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVSTS_BUSY
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTCNT
value|0x02
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTCNT_START
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTCNT_PROT_QUICK
value|0
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTCNT_PROT_BYTE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTCNT_PROT_BDATA
value|(2<<2)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTCNT_PROT_WDATA
value|(3<<2)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTCNT_PROT_BLOCK
value|(5<<2)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTCNT_KILL
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTCNT_INTREN
value|(1)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTCMD
value|0x03
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTADD
value|0x04
end_define

begin_define
define|#
directive|define
name|LSB
value|0x1
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTDAT0
value|0x05
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBHSTDAT1
value|0x06
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBBLKDAT
value|0x07
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVCNT
value|0x08
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVCNT_ALTEN
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVCNT_SD2EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVCNT_SD1EN
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVCNT_SLVEN
value|(1)
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVCMD
value|0x09
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVEVT
value|0x0a
end_define

begin_define
define|#
directive|define
name|PIIX4_SMBSLVDAT
value|0x0c
end_define

begin_comment
comment|/* SMBus alert response address. */
end_comment

begin_define
define|#
directive|define
name|SMBALTRESP
value|0x18
end_define

begin_define
define|#
directive|define
name|SMBBLOCKTRANS_MAX
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__INTPMREG_H__ */
end_comment

end_unit

