begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andriy Gapon<avg@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The following registers, bits and magic values are defined in Register  * Reference Guide documents for SB600, SB7x0, SB8x0, SB9x0 southbridges and  * various versions of Fusion Controller Hubs (FCHs).  FCHs integrated into  * CPUs are documented in BIOS and Kernel Development Guide documents for  * the corresponding processor families.  *  * At present there are three classes of supported chipsets:  * - SB600 and S7x0 southbridges where the SMBus controller device has  *   a PCI Device ID of 0x43851002 and a revision less than 0x40  * - several types of southbridges and FCHs:  *   o SB8x0, SB9x0 southbridges where the SMBus controller device has a PCI  *     Device ID of 0x43851002 and a revision greater than or equal to 0x40  *   o FCHs where the controller has an ID of 0x780b1022 and a revision less  *     than 0x41 (various variants of "Hudson" and "Bolton" as well as FCHs  *     integrated into processors, e.g. "Kabini")  *   o FCHs where the controller has an ID of 0x790b1022 and a revision less  *     than 0x49  * - several types of FCHs:  *   o FCHs where the SMBus controller device has a PCI Device ID of 0x780b1022  *     and a revision greater than or equal to 0x41 (integrated into "Mullins"  *     processors, code named "ML")  *   o FCHs where the controller has an ID of 0x790b1022 and a revision greater  *     than or equal to 0x49 (integrated into "Carrizo" processors, code named  *     "KERNCZ" or "CZ")  *  * The register definitions are compatible within the classes and may be  * incompatible accross them.  */
end_comment

begin_comment
comment|/*  * IO registers for accessing the PMIO space.  * See SB7xx RRG 2.3.3.1.1, for instance.  */
end_comment

begin_define
define|#
directive|define
name|AMDSB_PMIO_INDEX
value|0xcd6
end_define

begin_define
define|#
directive|define
name|AMDSB_PMIO_DATA
value|(PMIO_INDEX + 1)
end_define

begin_define
define|#
directive|define
name|AMDSB_PMIO_WIDTH
value|2
end_define

begin_comment
comment|/*  * SB7x0 and compatible registers in the PMIO space.  * See SB7xx RRG 2.3.3.2.  */
end_comment

begin_define
define|#
directive|define
name|AMDSB_PM_RESET_STATUS0
value|0x44
end_define

begin_define
define|#
directive|define
name|AMDSB_PM_RESET_STATUS1
value|0x45
end_define

begin_define
define|#
directive|define
name|AMDSB_WD_RST_STS
value|0x02
end_define

begin_define
define|#
directive|define
name|AMDSB_PM_WDT_CTRL
value|0x69
end_define

begin_define
define|#
directive|define
name|AMDSB_WDT_DISABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|AMDSB_WDT_RES_MASK
value|(0x02 | 0x04)
end_define

begin_define
define|#
directive|define
name|AMDSB_WDT_RES_32US
value|0x00
end_define

begin_define
define|#
directive|define
name|AMDSB_WDT_RES_10MS
value|0x02
end_define

begin_define
define|#
directive|define
name|AMDSB_WDT_RES_100MS
value|0x04
end_define

begin_define
define|#
directive|define
name|AMDSB_WDT_RES_1S
value|0x06
end_define

begin_define
define|#
directive|define
name|AMDSB_PM_WDT_BASE_LSB
value|0x6c
end_define

begin_define
define|#
directive|define
name|AMDSB_PM_WDT_BASE_MSB
value|0x6f
end_define

begin_comment
comment|/*  * SB8x0 and compatible registers in the PMIO space.  * See SB8xx RRG 2.3.3, for instance.  */
end_comment

begin_define
define|#
directive|define
name|AMDSB8_PM_SMBUS_EN
value|0x2c
end_define

begin_define
define|#
directive|define
name|AMDSB8_SMBUS_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|AMDSB8_SMBUS_ADDR_MASK
value|0xffe0u
end_define

begin_define
define|#
directive|define
name|AMDSB8_PM_WDT_EN
value|0x48
end_define

begin_define
define|#
directive|define
name|AMDSB8_WDT_DEC_EN
value|0x01
end_define

begin_define
define|#
directive|define
name|AMDSB8_WDT_DISABLE
value|0x02
end_define

begin_define
define|#
directive|define
name|AMDSB8_PM_WDT_CTRL
value|0x4c
end_define

begin_define
define|#
directive|define
name|AMDSB8_WDT_32KHZ
value|0x00
end_define

begin_define
define|#
directive|define
name|AMDSB8_WDT_1HZ
value|0x03
end_define

begin_define
define|#
directive|define
name|AMDSB8_WDT_RES_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|AMDSB8_PM_RESET_STATUS0
value|0xc0
end_define

begin_define
define|#
directive|define
name|AMDSB8_PM_RESET_STATUS1
value|0xc1
end_define

begin_define
define|#
directive|define
name|AMDSB8_WD_RST_STS
value|0x20
end_define

begin_comment
comment|/*  * Newer FCH registers in the PMIO space.  * See BKDG for Family 16h Models 30h-3Fh 3.26.13 PMx00 and PMx04.  */
end_comment

begin_define
define|#
directive|define
name|AMDFCH41_PM_DECODE_EN0
value|0x00
end_define

begin_define
define|#
directive|define
name|AMDFCH41_SMBUS_EN
value|0x10
end_define

begin_define
define|#
directive|define
name|AMDFCH41_WDT_EN
value|0x80
end_define

begin_define
define|#
directive|define
name|AMDFCH41_PM_DECODE_EN1
value|0x01
end_define

begin_define
define|#
directive|define
name|AMDFCH41_PM_DECODE_EN3
value|0x03
end_define

begin_define
define|#
directive|define
name|AMDFCH41_WDT_RES_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|AMDFCH41_WDT_RES_32US
value|0x00
end_define

begin_define
define|#
directive|define
name|AMDFCH41_WDT_RES_10MS
value|0x01
end_define

begin_define
define|#
directive|define
name|AMDFCH41_WDT_RES_100MS
value|0x02
end_define

begin_define
define|#
directive|define
name|AMDFCH41_WDT_RES_1S
value|0x03
end_define

begin_define
define|#
directive|define
name|AMDFCH41_WDT_EN_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|AMDFCH41_WDT_ENABLE
value|0x00
end_define

begin_define
define|#
directive|define
name|AMDFCH41_PM_ISA_CTRL
value|0x04
end_define

begin_define
define|#
directive|define
name|AMDFCH41_MMIO_EN
value|0x02
end_define

begin_comment
comment|/*  * Fixed MMIO addresses for accessing Watchdog and SMBus registers.  * See BKDG for Family 16h Models 30h-3Fh 3.26.13 PMx00 and PMx04.  */
end_comment

begin_define
define|#
directive|define
name|AMDFCH41_WDT_FIXED_ADDR
value|0xfeb00000u
end_define

begin_define
define|#
directive|define
name|AMDFCH41_MMIO_ADDR
value|0xfed80000u
end_define

begin_define
define|#
directive|define
name|AMDFCH41_MMIO_SMBUS_OFF
value|0x0a00
end_define

begin_define
define|#
directive|define
name|AMDFCH41_MMIO_WDT_OFF
value|0x0b00
end_define

begin_comment
comment|/*  * PCI Device IDs and revisions.  * SB600 RRG 2.3.1.1,  * SB7xx RRG 2.3.1.1,  * SB8xx RRG 2.3.1,  * BKDG for Family 15h Models 60h-6Fh 3.26.6.1,  * BKDG for Family 15h Models 70h-7Fh 3.26.6.1,  * BKDG for Family 16h Models 00h-0Fh 3.26.7.1,  * BKDG for Family 16h Models 30h-3Fh 3.26.7.1.  * Also, see i2c-piix4 aka piix4_smbus Linux driver.  */
end_comment

begin_define
define|#
directive|define
name|AMDSB_SMBUS_DEVID
value|0x43851002
end_define

begin_define
define|#
directive|define
name|AMDSB8_SMBUS_REVID
value|0x40
end_define

begin_define
define|#
directive|define
name|AMDFCH_SMBUS_DEVID
value|0x780b1022
end_define

begin_define
define|#
directive|define
name|AMDFCH41_SMBUS_REVID
value|0x41
end_define

begin_define
define|#
directive|define
name|AMDCZ_SMBUS_DEVID
value|0x790b1022
end_define

begin_define
define|#
directive|define
name|AMDCZ49_SMBUS_REVID
value|0x49
end_define

end_unit

