begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_iwmreg.h,v 1.4 2015/06/15 08:06:11 stsp Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/******************************************************************************  *  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2005 - 2014 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110,  * USA  *  * The full GNU General Public License is included in this distribution  * in the file called COPYING.  *  * Contact Information:  *  Intel Linux Wireless<ilw@linux.intel.com>  * Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497  *  * BSD LICENSE  *  * Copyright(c) 2005 - 2014 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *  * Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * Neither the name Intel Corporation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_IWM_REG_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_IWM_REG_H__
end_define

begin_define
define|#
directive|define
name|le16_to_cpup
parameter_list|(
name|_a_
parameter_list|)
value|(le16toh(*(const uint16_t *)(_a_)))
end_define

begin_define
define|#
directive|define
name|le32_to_cpup
parameter_list|(
name|_a_
parameter_list|)
value|(le32toh(*(const uint32_t *)(_a_)))
end_define

begin_comment
comment|/*  * BEGIN iwl-csr.h  */
end_comment

begin_comment
comment|/*  * CSR (control and status registers)  *  * CSR registers are mapped directly into PCI bus space, and are accessible  * whenever platform supplies power to device, even when device is in  * low power states due to driver-invoked device resets  * (e.g. IWM_CSR_RESET_REG_FLAG_SW_RESET) or uCode-driven power-saving modes.  *  * Use iwl_write32() and iwl_read32() family to access these registers;  * these provide simple PCI bus access, without waking up the MAC.  * Do not use iwl_write_direct32() family for these registers;  * no need to "grab nic access" via IWM_CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ.  * The MAC (uCode processor, etc.) does not need to be powered up for accessing  * the CSR registers.  *  * NOTE:  Device does need to be awake in order to read this memory  *        via IWM_CSR_EEPROM and IWM_CSR_OTP registers  */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG
value|(0x000)
end_define

begin_comment
comment|/* hardware interface config */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_COALESCING
value|(0x004)
end_define

begin_comment
comment|/* accum ints, 32-usec units */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT
value|(0x008)
end_define

begin_comment
comment|/* host interrupt status/ack */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_MASK
value|(0x00c)
end_define

begin_comment
comment|/* host interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_FH_INT_STATUS
value|(0x010)
end_define

begin_comment
comment|/* busmaster int status/ack*/
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_GPIO_IN
value|(0x018)
end_define

begin_comment
comment|/* read external chip pins */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_RESET
value|(0x020)
end_define

begin_comment
comment|/* busmaster enable, NMI, etc*/
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_GP_CNTRL
value|(0x024)
end_define

begin_comment
comment|/* 2nd byte of IWM_CSR_INT_COALESCING, not accessible via iwl_write32()! */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_PERIODIC_REG
value|(0x005)
end_define

begin_comment
comment|/*  * Hardware revision info  * Bit fields:  * 31-16:  Reserved  *  15-4:  Type of device:  see IWM_CSR_HW_REV_TYPE_xxx definitions  *  3-2:  Revision step:  0 = A, 1 = B, 2 = C, 3 = D  *  1-0:  "Dash" (-) value, as in A-1, etc.  */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV
value|(0x028)
end_define

begin_comment
comment|/*  * EEPROM and OTP (one-time-programmable) memory reads  *  * NOTE:  Device must be awake, initialized via apm_ops.init(),  *        in order to read.  */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_EEPROM_REG
value|(0x02c)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_EEPROM_GP
value|(0x030)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_OTP_GP_REG
value|(0x034)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GIO_REG
value|(0x03C)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_UCODE_REG
value|(0x048)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_DRIVER_REG
value|(0x050)
end_define

begin_comment
comment|/*  * UCODE-DRIVER GP (general purpose) mailbox registers.  * SET/CLR registers set/clear bit(s) if "1" is written.  */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_UCODE_DRV_GP1
value|(0x054)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_UCODE_DRV_GP1_SET
value|(0x058)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_UCODE_DRV_GP1_CLR
value|(0x05c)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_UCODE_DRV_GP2
value|(0x060)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_MBOX_SET_REG
value|(0x088)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_MBOX_SET_REG_OS_ALIVE
value|0x20
end_define

begin_define
define|#
directive|define
name|IWM_CSR_LED_REG
value|(0x094)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_DRAM_INT_TBL_REG
value|(0x0A0)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_MAC_SHADOW_REG_CTRL
value|(0x0A8)
end_define

begin_comment
comment|/* 6000 and up */
end_comment

begin_comment
comment|/* GIO Chicken Bits (PCI Express bus link power management) */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_GIO_CHICKEN_BITS
value|(0x100)
end_define

begin_comment
comment|/* Analog phase-lock-loop configuration  */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_ANA_PLL_CFG
value|(0x20c)
end_define

begin_comment
comment|/*  * CSR Hardware Revision Workaround Register.  Indicates hardware rev;  * "step" determines CCK backoff for txpower calculation.  Used for 4965 only.  * See also IWM_CSR_HW_REV register.  * Bit fields:  *  3-2:  0 = A, 1 = B, 2 = C, 3 = D step  *  1-0:  "Dash" (-) value, as in C-1, etc.  */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_WA_REG
value|(0x22C)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_DBG_HPET_MEM_REG
value|(0x240)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_DBG_LINK_PWR_MGMT_REG
value|(0x250)
end_define

begin_comment
comment|/* Bits for IWM_CSR_HW_IF_CONFIG_REG */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_MSK_MAC_DASH
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_MSK_MAC_STEP
value|(0x0000000C)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_MSK_BOARD_VER
value|(0x000000C0)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_BIT_MAC_SI
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_BIT_RADIO_SI
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_MSK_PHY_TYPE
value|(0x00000C00)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_MSK_PHY_DASH
value|(0x00003000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_MSK_PHY_STEP
value|(0x0000C000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_POS_MAC_DASH
value|(0)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_POS_MAC_STEP
value|(2)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_POS_BOARD_VER
value|(6)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_POS_PHY_TYPE
value|(10)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_POS_PHY_DASH
value|(12)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_POS_PHY_STEP
value|(14)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_BIT_HAP_WAKE_L1A
value|(0x00080000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_BIT_EEPROM_OWN_SEM
value|(0x00200000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_BIT_NIC_READY
value|(0x00400000)
end_define

begin_comment
comment|/* PCI_OWN_SEM */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_BIT_NIC_PREPARE_DONE
value|(0x02000000)
end_define

begin_comment
comment|/* ME_OWN */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_PREPARE
value|(0x08000000)
end_define

begin_comment
comment|/* WAKE_ME */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_ENABLE_PME
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_IF_CONFIG_REG_PERSIST_MODE
value|(0x40000000)
end_define

begin_comment
comment|/* PERSISTENCE */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_PERIODIC_DIS
value|(0x00)
end_define

begin_comment
comment|/* disable periodic int*/
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_PERIODIC_ENA
value|(0xFF)
end_define

begin_comment
comment|/* 255*32 usec ~ 8 msec*/
end_comment

begin_comment
comment|/* interrupt flags in INTA, set by uCode or hardware (e.g. dma),  * acknowledged (reset) by host writing "1" to flagged bits. */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_BIT_FH_RX
value|(1<< 31)
end_define

begin_comment
comment|/* Rx DMA, cmd responses, FH_INT[17:16] */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_BIT_HW_ERR
value|(1<< 29)
end_define

begin_comment
comment|/* DMA hardware error FH_INT[31] */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_BIT_RX_PERIODIC
value|(1<< 28)
end_define

begin_comment
comment|/* Rx periodic */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_BIT_FH_TX
value|(1<< 27)
end_define

begin_comment
comment|/* Tx DMA FH_INT[1:0] */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_BIT_SCD
value|(1<< 26)
end_define

begin_comment
comment|/* TXQ pointer advanced */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_BIT_SW_ERR
value|(1<< 25)
end_define

begin_comment
comment|/* uCode error */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_BIT_RF_KILL
value|(1<< 7)
end_define

begin_comment
comment|/* HW RFKILL switch GP_CNTRL[27] toggled */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_BIT_CT_KILL
value|(1<< 6)
end_define

begin_comment
comment|/* Critical temp (chip too hot) rfkill */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_BIT_SW_RX
value|(1<< 3)
end_define

begin_comment
comment|/* Rx, command responses */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_BIT_WAKEUP
value|(1<< 1)
end_define

begin_comment
comment|/* NIC controller waking up (pwr mgmt) */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INT_BIT_ALIVE
value|(1<< 0)
end_define

begin_comment
comment|/* uCode interrupts once it initializes */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_INI_SET_MASK
value|(IWM_CSR_INT_BIT_FH_RX   | \ 				 IWM_CSR_INT_BIT_HW_ERR  | \ 				 IWM_CSR_INT_BIT_FH_TX   | \ 				 IWM_CSR_INT_BIT_SW_ERR  | \ 				 IWM_CSR_INT_BIT_RF_KILL | \ 				 IWM_CSR_INT_BIT_SW_RX   | \ 				 IWM_CSR_INT_BIT_WAKEUP  | \ 				 IWM_CSR_INT_BIT_ALIVE   | \ 				 IWM_CSR_INT_BIT_RX_PERIODIC)
end_define

begin_comment
comment|/* interrupt flags in FH (flow handler) (PCI busmaster DMA) */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_FH_INT_BIT_ERR
value|(1<< 31)
end_define

begin_comment
comment|/* Error */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_FH_INT_BIT_HI_PRIOR
value|(1<< 30)
end_define

begin_comment
comment|/* High priority Rx, bypass coalescing */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_FH_INT_BIT_RX_CHNL1
value|(1<< 17)
end_define

begin_comment
comment|/* Rx channel 1 */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_FH_INT_BIT_RX_CHNL0
value|(1<< 16)
end_define

begin_comment
comment|/* Rx channel 0 */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_FH_INT_BIT_TX_CHNL1
value|(1<< 1)
end_define

begin_comment
comment|/* Tx channel 1 */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_FH_INT_BIT_TX_CHNL0
value|(1<< 0)
end_define

begin_comment
comment|/* Tx channel 0 */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_FH_INT_RX_MASK
value|(IWM_CSR_FH_INT_BIT_HI_PRIOR | \ 				IWM_CSR_FH_INT_BIT_RX_CHNL1 | \ 				IWM_CSR_FH_INT_BIT_RX_CHNL0)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_FH_INT_TX_MASK
value|(IWM_CSR_FH_INT_BIT_TX_CHNL1 | \ 				IWM_CSR_FH_INT_BIT_TX_CHNL0)
end_define

begin_comment
comment|/* GPIO */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_GPIO_IN_BIT_AUX_POWER
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GPIO_IN_VAL_VAUX_PWR_SRC
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GPIO_IN_VAL_VMAIN_PWR_SRC
value|(0x00000200)
end_define

begin_comment
comment|/* RESET */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_RESET_REG_FLAG_NEVO_RESET
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_RESET_REG_FLAG_FORCE_NMI
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_RESET_REG_FLAG_SW_RESET
value|(0x00000080)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_RESET_REG_FLAG_MASTER_DISABLED
value|(0x00000100)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_RESET_REG_FLAG_STOP_MASTER
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_RESET_LINK_PWR_MGMT_DISABLED
value|(0x80000000)
end_define

begin_comment
comment|/*  * GP (general purpose) CONTROL REGISTER  * Bit fields:  *    27:  HW_RF_KILL_SW  *         Indicates state of (platform's) hardware RF-Kill switch  * 26-24:  POWER_SAVE_TYPE  *         Indicates current power-saving mode:  *         000 -- No power saving  *         001 -- MAC power-down  *         010 -- PHY (radio) power-down  *         011 -- Error  *   9-6:  SYS_CONFIG  *         Indicates current system configuration, reflecting pins on chip  *         as forced high/low by device circuit board.  *     4:  GOING_TO_SLEEP  *         Indicates MAC is entering a power-saving sleep power-down.  *         Not a good time to access device-internal resources.  *     3:  MAC_ACCESS_REQ  *         Host sets this to request and maintain MAC wakeup, to allow host  *         access to device-internal resources.  Host must wait for  *         MAC_CLOCK_READY (and !GOING_TO_SLEEP) before accessing non-CSR  *         device registers.  *     2:  INIT_DONE  *         Host sets this to put device into fully operational D0 power mode.  *         Host resets this after SW_RESET to put device into low power mode.  *     0:  MAC_CLOCK_READY  *         Indicates MAC (ucode processor, etc.) is powered up and can run.  *         Internal resources are accessible.  *         NOTE:  This does not indicate that the processor is actually running.  *         NOTE:  This does not indicate that device has completed  *                init or post-power-down restore of internal SRAM memory.  *                Use IWM_CSR_UCODE_DRV_GP1_BIT_MAC_SLEEP as indication that  *                SRAM is restored and uCode is in normal operation mode.  *                Later devices (5xxx/6xxx/1xxx) use non-volatile SRAM, and  *                do not need to save/restore it.  *         NOTE:  After device reset, this bit remains "0" until host sets  *                INIT_DONE  */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_GP_CNTRL_REG_FLAG_MAC_CLOCK_READY
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_CNTRL_REG_FLAG_INIT_DONE
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_CNTRL_REG_FLAG_GOING_TO_SLEEP
value|(0x00000010)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_CNTRL_REG_VAL_MAC_ACCESS_EN
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_CNTRL_REG_MSK_POWER_SAVE_TYPE
value|(0x07000000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_CNTRL_REG_FLAG_MAC_POWER_SAVE
value|(0x04000000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_CNTRL_REG_FLAG_HW_RF_KILL_SW
value|(0x08000000)
end_define

begin_comment
comment|/* HW REV */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_DASH
parameter_list|(
name|_val
parameter_list|)
value|(((_val)& 0x0000003)>> 0)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_STEP
parameter_list|(
name|_val
parameter_list|)
value|(((_val)& 0x000000C)>> 2)
end_define

begin_comment
comment|/**  *  hw_rev values  */
end_comment

begin_enum
enum|enum
block|{
name|IWM_SILICON_A_STEP
init|=
literal|0
block|,
name|IWM_SILICON_B_STEP
block|,
name|IWM_SILICON_C_STEP
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_MSK
value|(0x000FFF0)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_5300
value|(0x0000020)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_5350
value|(0x0000030)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_5100
value|(0x0000050)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_5150
value|(0x0000040)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_1000
value|(0x0000060)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_6x00
value|(0x0000070)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_6x50
value|(0x0000080)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_6150
value|(0x0000084)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_6x05
value|(0x00000B0)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_6x30
value|IWM_CSR_HW_REV_TYPE_6x05
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_6x35
value|IWM_CSR_HW_REV_TYPE_6x05
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_2x30
value|(0x00000C0)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_2x00
value|(0x0000100)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_105
value|(0x0000110)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_135
value|(0x0000120)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_7265D
value|(0x0000210)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_HW_REV_TYPE_NONE
value|(0x00001F0)
end_define

begin_comment
comment|/* EEPROM REG */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_EEPROM_REG_READ_VALID_MSK
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_EEPROM_REG_BIT_CMD
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_EEPROM_REG_MSK_ADDR
value|(0x0000FFFC)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_EEPROM_REG_MSK_DATA
value|(0xFFFF0000)
end_define

begin_comment
comment|/* EEPROM GP */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_EEPROM_GP_VALID_MSK
value|(0x00000007)
end_define

begin_comment
comment|/* signature */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_EEPROM_GP_IF_OWNER_MSK
value|(0x00000180)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_EEPROM_GP_BAD_SIGNATURE_BOTH_EEP_AND_OTP
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_EEPROM_GP_BAD_SIG_EEP_GOOD_SIG_OTP
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_EEPROM_GP_GOOD_SIG_EEP_LESS_THAN_4K
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_EEPROM_GP_GOOD_SIG_EEP_MORE_THAN_4K
value|(0x00000004)
end_define

begin_comment
comment|/* One-time-programmable memory general purpose reg */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_OTP_GP_REG_DEVICE_SELECT
value|(0x00010000)
end_define

begin_comment
comment|/* 0 - EEPROM, 1 - OTP */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_OTP_GP_REG_OTP_ACCESS_MODE
value|(0x00020000)
end_define

begin_comment
comment|/* 0 - absolute, 1 - relative */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_OTP_GP_REG_ECC_CORR_STATUS_MSK
value|(0x00100000)
end_define

begin_comment
comment|/* bit 20 */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_OTP_GP_REG_ECC_UNCORR_STATUS_MSK
value|(0x00200000)
end_define

begin_comment
comment|/* bit 21 */
end_comment

begin_comment
comment|/* GP REG */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_GP_REG_POWER_SAVE_STATUS_MSK
value|(0x03000000)
end_define

begin_comment
comment|/* bit 24/25 */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_GP_REG_NO_POWER_SAVE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_REG_MAC_POWER_SAVE
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_REG_PHY_POWER_SAVE
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_REG_POWER_SAVE_ERROR
value|(0x03000000)
end_define

begin_comment
comment|/* CSR GIO */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_GIO_REG_VAL_L0S_ENABLED
value|(0x00000002)
end_define

begin_comment
comment|/*  * UCODE-DRIVER GP (general purpose) mailbox register 1  * Host driver and uCode write and/or read this register to communicate with  * each other.  * Bit fields:  *     4:  UCODE_DISABLE  *         Host sets this to request permanent halt of uCode, same as  *         sending CARD_STATE command with "halt" bit set.  *     3:  CT_KILL_EXIT  *         Host sets this to request exit from CT_KILL state, i.e. host thinks  *         device temperature is low enough to continue normal operation.  *     2:  CMD_BLOCKED  *         Host sets this during RF KILL power-down sequence (HW, SW, CT KILL)  *         to release uCode to clear all Tx and command queues, enter  *         unassociated mode, and power down.  *         NOTE:  Some devices also use HBUS_TARG_MBX_C register for this bit.  *     1:  SW_BIT_RFKILL  *         Host sets this when issuing CARD_STATE command to request  *         device sleep.  *     0:  MAC_SLEEP  *         uCode sets this when preparing a power-saving power-down.  *         uCode resets this when power-up is complete and SRAM is sane.  *         NOTE:  device saves internal SRAM data to host when powering down,  *                and must restore this data after powering back up.  *                MAC_SLEEP is the best indication that restore is complete.  *                Later devices (5xxx/6xxx/1xxx) use non-volatile SRAM, and  *                do not need to save/restore it.  */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_UCODE_DRV_GP1_BIT_MAC_SLEEP
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_UCODE_SW_BIT_RFKILL
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_UCODE_DRV_GP1_BIT_CMD_BLOCKED
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_UCODE_DRV_GP1_REG_BIT_CT_KILL_EXIT
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_UCODE_DRV_GP1_BIT_D3_CFG_COMPLETE
value|(0x00000020)
end_define

begin_comment
comment|/* GP Driver */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_GP_DRIVER_REG_BIT_RADIO_SKU_MSK
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_DRIVER_REG_BIT_RADIO_SKU_3x3_HYB
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_DRIVER_REG_BIT_RADIO_SKU_2x2_HYB
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_DRIVER_REG_BIT_RADIO_SKU_2x2_IPA
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_DRIVER_REG_BIT_CALIB_VERSION6
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_DRIVER_REG_BIT_6050_1x2
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GP_DRIVER_REG_BIT_RADIO_IQ_INVER
value|(0x00000080)
end_define

begin_comment
comment|/* GIO Chicken Bits (PCI Express bus link power management) */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_GIO_CHICKEN_BITS_REG_BIT_L1A_NO_L0S_RX
value|(0x00800000)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_GIO_CHICKEN_BITS_REG_BIT_DIS_L0S_EXIT_TIMER
value|(0x20000000)
end_define

begin_comment
comment|/* LED */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_LED_BSM_CTRL_MSK
value|(0xFFFFFFDF)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_LED_REG_TURN_ON
value|(0x60)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_LED_REG_TURN_OFF
value|(0x20)
end_define

begin_comment
comment|/* ANA_PLL */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR50_ANA_PLL_CFG_VAL
value|(0x00880300)
end_define

begin_comment
comment|/* HPET MEM debug */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_DBG_HPET_MEM_REG_VAL
value|(0xFFFF0000)
end_define

begin_comment
comment|/* DRAM INT TABLE */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_DRAM_INT_TBL_ENABLE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_DRAM_INIT_TBL_WRITE_POINTER
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_DRAM_INIT_TBL_WRAP_CHECK
value|(1<< 27)
end_define

begin_comment
comment|/* SECURE boot registers */
end_comment

begin_define
define|#
directive|define
name|IWM_CSR_SECURE_BOOT_CONFIG_ADDR
value|(0x100)
end_define

begin_enum
enum|enum
name|iwm_secure_boot_config_reg
block|{
name|IWM_CSR_SECURE_BOOT_CONFIG_INSPECTOR_BURNED_IN_OTP
init|=
literal|0x00000001
block|,
name|IWM_CSR_SECURE_BOOT_CONFIG_INSPECTOR_NOT_REQ
init|=
literal|0x00000002
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_CSR_SECURE_BOOT_CPU1_STATUS_ADDR
value|(0x100)
end_define

begin_define
define|#
directive|define
name|IWM_CSR_SECURE_BOOT_CPU2_STATUS_ADDR
value|(0x100)
end_define

begin_enum
enum|enum
name|iwm_secure_boot_status_reg
block|{
name|IWM_CSR_SECURE_BOOT_CPU_STATUS_VERF_STATUS
init|=
literal|0x00000003
block|,
name|IWM_CSR_SECURE_BOOT_CPU_STATUS_VERF_COMPLETED
init|=
literal|0x00000002
block|,
name|IWM_CSR_SECURE_BOOT_CPU_STATUS_VERF_SUCCESS
init|=
literal|0x00000004
block|,
name|IWM_CSR_SECURE_BOOT_CPU_STATUS_VERF_FAIL
init|=
literal|0x00000008
block|,
name|IWM_CSR_SECURE_BOOT_CPU_STATUS_SIGN_VERF_FAIL
init|=
literal|0x00000010
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_FH_UCODE_LOAD_STATUS
value|0x1af0
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_TB_MAX_LENGTH
value|0x20000
end_define

begin_define
define|#
directive|define
name|IWM_LMPM_SECURE_UCODE_LOAD_CPU1_HDR_ADDR
value|0x1e78
end_define

begin_define
define|#
directive|define
name|IWM_LMPM_SECURE_UCODE_LOAD_CPU2_HDR_ADDR
value|0x1e7c
end_define

begin_define
define|#
directive|define
name|IWM_LMPM_SECURE_CPU1_HDR_MEM_SPACE
value|0x420000
end_define

begin_define
define|#
directive|define
name|IWM_LMPM_SECURE_CPU2_HDR_MEM_SPACE
value|0x420400
end_define

begin_define
define|#
directive|define
name|IWM_CSR_SECURE_TIME_OUT
value|(100)
end_define

begin_comment
comment|/* extended range in FW SRAM */
end_comment

begin_define
define|#
directive|define
name|IWM_FW_MEM_EXTENDED_START
value|0x40000
end_define

begin_define
define|#
directive|define
name|IWM_FW_MEM_EXTENDED_END
value|0x57FFF
end_define

begin_comment
comment|/* FW chicken bits */
end_comment

begin_define
define|#
directive|define
name|IWM_LMPM_CHICK
value|0xa01ff8
end_define

begin_define
define|#
directive|define
name|IWM_LMPM_CHICK_EXTENDED_ADDR_SPACE
value|0x01
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_0_REG0
value|(0x1D00)
end_define

begin_comment
comment|/*  * HBUS (Host-side Bus)  *  * HBUS registers are mapped directly into PCI bus space, but are used  * to indirectly access device's internal memory or registers that  * may be powered-down.  *  * Use iwl_write_direct32()/iwl_read_direct32() family for these registers;  * host must "grab nic access" via CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ  * to make sure the MAC (uCode processor, etc.) is powered up for accessing  * internal resources.  *  * Do not use iwl_write32()/iwl_read32() family to access these registers;  * these provide only simple PCI bus access, without waking up the MAC.  */
end_comment

begin_define
define|#
directive|define
name|IWM_HBUS_BASE
value|(0x400)
end_define

begin_comment
comment|/*  * Registers for accessing device's internal SRAM memory (e.g. SCD SRAM  * structures, error log, event log, verifying uCode load).  * First write to address register, then read from or write to data register  * to complete the job.  Once the address register is set up, accesses to  * data registers auto-increment the address by one dword.  * Bit usage for address registers (read or write):  *  0-31:  memory address within device  */
end_comment

begin_define
define|#
directive|define
name|IWM_HBUS_TARG_MEM_RADDR
value|(IWM_HBUS_BASE+0x00c)
end_define

begin_define
define|#
directive|define
name|IWM_HBUS_TARG_MEM_WADDR
value|(IWM_HBUS_BASE+0x010)
end_define

begin_define
define|#
directive|define
name|IWM_HBUS_TARG_MEM_WDAT
value|(IWM_HBUS_BASE+0x018)
end_define

begin_define
define|#
directive|define
name|IWM_HBUS_TARG_MEM_RDAT
value|(IWM_HBUS_BASE+0x01c)
end_define

begin_comment
comment|/* Mailbox C, used as workaround alternative to CSR_UCODE_DRV_GP1 mailbox */
end_comment

begin_define
define|#
directive|define
name|IWM_HBUS_TARG_MBX_C
value|(IWM_HBUS_BASE+0x030)
end_define

begin_define
define|#
directive|define
name|IWM_HBUS_TARG_MBX_C_REG_BIT_CMD_BLOCKED
value|(0x00000004)
end_define

begin_comment
comment|/*  * Registers for accessing device's internal peripheral registers  * (e.g. SCD, BSM, etc.).  First write to address register,  * then read from or write to data register to complete the job.  * Bit usage for address registers (read or write):  *  0-15:  register address (offset) within device  * 24-25:  (# bytes - 1) to read or write (e.g. 3 for dword)  */
end_comment

begin_define
define|#
directive|define
name|IWM_HBUS_TARG_PRPH_WADDR
value|(IWM_HBUS_BASE+0x044)
end_define

begin_define
define|#
directive|define
name|IWM_HBUS_TARG_PRPH_RADDR
value|(IWM_HBUS_BASE+0x048)
end_define

begin_define
define|#
directive|define
name|IWM_HBUS_TARG_PRPH_WDAT
value|(IWM_HBUS_BASE+0x04c)
end_define

begin_define
define|#
directive|define
name|IWM_HBUS_TARG_PRPH_RDAT
value|(IWM_HBUS_BASE+0x050)
end_define

begin_comment
comment|/* enable the ID buf for read */
end_comment

begin_define
define|#
directive|define
name|IWM_WFPM_PS_CTL_CLR
value|0xa0300c
end_define

begin_define
define|#
directive|define
name|IWM_WFMP_MAC_ADDR_0
value|0xa03080
end_define

begin_define
define|#
directive|define
name|IWM_WFMP_MAC_ADDR_1
value|0xa03084
end_define

begin_define
define|#
directive|define
name|IWM_LMPM_PMG_EN
value|0xa01cec
end_define

begin_define
define|#
directive|define
name|IWM_RADIO_REG_SYS_MANUAL_DFT_0
value|0xad4078
end_define

begin_define
define|#
directive|define
name|IWM_RFIC_REG_RD
value|0xad0470
end_define

begin_define
define|#
directive|define
name|IWM_WFPM_CTRL_REG
value|0xa03030
end_define

begin_define
define|#
directive|define
name|IWM_WFPM_AUX_CTL_AUX_IF_MAC_OWNER_MSK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IWM_ENABLE_WFPM
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IWM_AUX_MISC_REG
value|0xa200b0
end_define

begin_define
define|#
directive|define
name|IWM_HW_STEP_LOCATION_BITS
value|24
end_define

begin_define
define|#
directive|define
name|IWM_AUX_MISC_MASTER1_EN
value|0xa20818
end_define

begin_define
define|#
directive|define
name|IWM_AUX_MISC_MASTER1_EN_SBE_MSK
value|0x1
end_define

begin_define
define|#
directive|define
name|IWM_AUX_MISC_MASTER1_SMPHR_STATUS
value|0xa20800
end_define

begin_define
define|#
directive|define
name|IWM_RSA_ENABLE
value|0xa24b08
end_define

begin_define
define|#
directive|define
name|IWM_PREG_AUX_BUS_WPROT_0
value|0xa04cc0
end_define

begin_define
define|#
directive|define
name|IWM_SB_CFG_OVERRIDE_ADDR
value|0xa26c78
end_define

begin_define
define|#
directive|define
name|IWM_SB_CFG_OVERRIDE_ENABLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|IWM_SB_CFG_BASE_OVERRIDE
value|0xa20000
end_define

begin_define
define|#
directive|define
name|IWM_SB_MODIFY_CFG_FLAG
value|0xa03088
end_define

begin_define
define|#
directive|define
name|IWM_SB_CPU_1_STATUS
value|0xa01e30
end_define

begin_define
define|#
directive|define
name|IWM_SB_CPU_2_STATUS
value|0Xa01e34
end_define

begin_comment
comment|/* Used to enable DBGM */
end_comment

begin_define
define|#
directive|define
name|IWM_HBUS_TARG_TEST_REG
value|(IWM_HBUS_BASE+0x05c)
end_define

begin_comment
comment|/*  * Per-Tx-queue write pointer (index, really!)  * Indicates index to next TFD that driver will fill (1 past latest filled).  * Bit usage:  *  0-7:  queue write index  * 11-8:  queue selector  */
end_comment

begin_define
define|#
directive|define
name|IWM_HBUS_TARG_WRPTR
value|(IWM_HBUS_BASE+0x060)
end_define

begin_comment
comment|/**********************************************************  * CSR values  **********************************************************/
end_comment

begin_comment
comment|/*  * host interrupt timeout value  * used with setting interrupt coalescing timer  * the CSR_INT_COALESCING is an 8 bit register in 32-usec unit  *  * default interrupt coalescing timer is 64 x 32 = 2048 usecs  */
end_comment

begin_define
define|#
directive|define
name|IWM_HOST_INT_TIMEOUT_MAX
value|(0xFF)
end_define

begin_define
define|#
directive|define
name|IWM_HOST_INT_TIMEOUT_DEF
value|(0x40)
end_define

begin_define
define|#
directive|define
name|IWM_HOST_INT_TIMEOUT_MIN
value|(0x0)
end_define

begin_define
define|#
directive|define
name|IWM_HOST_INT_OPER_MODE
value|(1<< 31)
end_define

begin_comment
comment|/*****************************************************************************  *                        7000/3000 series SHR DTS addresses                 *  *****************************************************************************/
end_comment

begin_comment
comment|/* Diode Results Register Structure: */
end_comment

begin_enum
enum|enum
name|iwm_dtd_diode_reg
block|{
name|IWM_DTS_DIODE_REG_DIG_VAL
init|=
literal|0x000000FF
block|,
comment|/* bits [7:0] */
name|IWM_DTS_DIODE_REG_VREF_LOW
init|=
literal|0x0000FF00
block|,
comment|/* bits [15:8] */
name|IWM_DTS_DIODE_REG_VREF_HIGH
init|=
literal|0x00FF0000
block|,
comment|/* bits [23:16] */
name|IWM_DTS_DIODE_REG_VREF_ID
init|=
literal|0x03000000
block|,
comment|/* bits [25:24] */
name|IWM_DTS_DIODE_REG_PASS_ONCE
init|=
literal|0x80000000
block|,
comment|/* bits [31:31] */
name|IWM_DTS_DIODE_REG_FLAGS_MSK
init|=
literal|0xFF000000
block|,
comment|/* bits [31:24] */
comment|/* Those are the masks INSIDE the flags bit-field: */
name|IWM_DTS_DIODE_REG_FLAGS_VREFS_ID_POS
init|=
literal|0
block|,
name|IWM_DTS_DIODE_REG_FLAGS_VREFS_ID
init|=
literal|0x00000003
block|,
comment|/* bits [1:0] */
name|IWM_DTS_DIODE_REG_FLAGS_PASS_ONCE_POS
init|=
literal|7
block|,
name|IWM_DTS_DIODE_REG_FLAGS_PASS_ONCE
init|=
literal|0x00000080
block|,
comment|/* bits [7:7] */
block|}
enum|;
end_enum

begin_comment
comment|/*  * END iwl-csr.h  */
end_comment

begin_comment
comment|/*  * BEGIN iwl-fw.h  */
end_comment

begin_comment
comment|/**  * enum iwm_ucode_tlv_flag - ucode API flags  * @IWM_UCODE_TLV_FLAGS_PAN: This is PAN capable microcode; this previously  *	was a separate TLV but moved here to save space.  * @IWM_UCODE_TLV_FLAGS_NEWSCAN: new uCode scan behaviour on hidden SSID,  *	treats good CRC threshold as a boolean  * @IWM_UCODE_TLV_FLAGS_MFP: This uCode image supports MFP (802.11w).  * @IWM_UCODE_TLV_FLAGS_UAPSD: This uCode image supports uAPSD  * @IWM_UCODE_TLV_FLAGS_SHORT_BL: 16 entries of black list instead of 64 in scan  *	offload profile config command.  * @IWM_UCODE_TLV_FLAGS_D3_6_IPV6_ADDRS: D3 image supports up to six  *	(rather than two) IPv6 addresses  * @IWM_UCODE_TLV_FLAGS_NO_BASIC_SSID: not sending a probe with the SSID element  *	from the probe request template.  * @IWM_UCODE_TLV_FLAGS_NEW_NSOFFL_SMALL: new NS offload (small version)  * @IWM_UCODE_TLV_FLAGS_NEW_NSOFFL_LARGE: new NS offload (large version)  * @IWM_UCODE_TLV_FLAGS_UAPSD_SUPPORT: General support for uAPSD  * @IWM_UCODE_TLV_FLAGS_EBS_SUPPORT: this uCode image supports EBS.  * @IWM_UCODE_TLV_FLAGS_P2P_PS_UAPSD: P2P client supports uAPSD power save  * @IWM_UCODE_TLV_FLAGS_BCAST_FILTERING: uCode supports broadcast filtering.  */
end_comment

begin_enum
enum|enum
name|iwm_ucode_tlv_flag
block|{
name|IWM_UCODE_TLV_FLAGS_PAN
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_UCODE_TLV_FLAGS_NEWSCAN
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_UCODE_TLV_FLAGS_MFP
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_UCODE_TLV_FLAGS_SHORT_BL
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
name|IWM_UCODE_TLV_FLAGS_D3_6_IPV6_ADDRS
init|=
operator|(
literal|1
operator|<<
literal|10
operator|)
block|,
name|IWM_UCODE_TLV_FLAGS_NO_BASIC_SSID
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|,
name|IWM_UCODE_TLV_FLAGS_NEW_NSOFFL_SMALL
init|=
operator|(
literal|1
operator|<<
literal|15
operator|)
block|,
name|IWM_UCODE_TLV_FLAGS_NEW_NSOFFL_LARGE
init|=
operator|(
literal|1
operator|<<
literal|16
operator|)
block|,
name|IWM_UCODE_TLV_FLAGS_UAPSD_SUPPORT
init|=
operator|(
literal|1
operator|<<
literal|24
operator|)
block|,
name|IWM_UCODE_TLV_FLAGS_EBS_SUPPORT
init|=
operator|(
literal|1
operator|<<
literal|25
operator|)
block|,
name|IWM_UCODE_TLV_FLAGS_P2P_PS_UAPSD
init|=
operator|(
literal|1
operator|<<
literal|26
operator|)
block|,
name|IWM_UCODE_TLV_FLAGS_BCAST_FILTERING
init|=
operator|(
literal|1
operator|<<
literal|29
operator|)
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_UCODE_TLV_FLAG_BITS
define|\
value|"\020\1PAN\2NEWSCAN\3MFP\4P2P\5DW_BC_TABLE\6NEWBT_COEX\7PM_CMD\10SHORT_BL\11RX_ENERG \ Y\12TIME_EVENT_V2\13D3_6_IPV6\14BF_UPDATED\15NO_BASIC_SSID\17D3_CONTINUITY\20NEW_NSOFF \ L_S\21NEW_NSOFFL_L\22SCHED_SCAN\24STA_KEY_CMD\25DEVICE_PS_CMD\26P2P_PS\27P2P_PS_DCM\30 \ P2P_PS_SCM\31UAPSD_SUPPORT\32EBS\33P2P_PS_UAPSD\36BCAST_FILTERING\37GO_UAPSD\40LTE_COEX"
end_define

begin_comment
comment|/**  * enum iwm_ucode_tlv_api - ucode api  * @IWM_UCODE_TLV_API_FRAGMENTED_SCAN: This ucode supports active dwell time  *	longer than the passive one, which is essential for fragmented scan.  * @IWM_UCODE_TLV_API_WIFI_MCC_UPDATE: ucode supports MCC updates with source.  * @IWM_UCODE_TLV_API_LQ_SS_PARAMS: Configure STBC/BFER via LQ CMD ss_params  *  * @IWM_NUM_UCODE_TLV_API: number of bits used  */
end_comment

begin_enum
enum|enum
name|iwm_ucode_tlv_api
block|{
name|IWM_UCODE_TLV_API_FRAGMENTED_SCAN
init|=
literal|8
block|,
name|IWM_UCODE_TLV_API_WIFI_MCC_UPDATE
init|=
literal|9
block|,
name|IWM_UCODE_TLV_API_LQ_SS_PARAMS
init|=
literal|18
block|,
name|IWM_NUM_UCODE_TLV_API
init|=
literal|32
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_UCODE_TLV_API_BITS
define|\
value|"\020\10FRAGMENTED_SCAN\11WIFI_MCC_UPDATE\16WIDE_CMD_HDR\22LQ_SS_PARAMS\30EXT_SCAN_PRIO\33TX_POWER_CHAIN"
end_define

begin_comment
comment|/**  * enum iwm_ucode_tlv_capa - ucode capabilities  * @IWM_UCODE_TLV_CAPA_D0I3_SUPPORT: supports D0i3  * @IWM_UCODE_TLV_CAPA_LAR_SUPPORT: supports Location Aware Regulatory  * @IWM_UCODE_TLV_CAPA_UMAC_SCAN: supports UMAC scan.  * @IWM_UCODE_TLV_CAPA_BEAMFORMER: supports Beamformer  * @IWM_UCODE_TLV_CAPA_TOF_SUPPORT: supports Time of Flight (802.11mc FTM)  * @IWM_UCODE_TLV_CAPA_TDLS_SUPPORT: support basic TDLS functionality  * @IWM_UCODE_TLV_CAPA_TXPOWER_INSERTION_SUPPORT: supports insertion of current  *	tx power value into TPC Report action frame and Link Measurement Report  *	action frame  * @IWM_UCODE_TLV_CAPA_DS_PARAM_SET_IE_SUPPORT: supports updating current  *	channel in DS parameter set element in probe requests.  * @IWM_UCODE_TLV_CAPA_WFA_TPC_REP_IE_SUPPORT: supports adding TPC Report IE in  *	probe requests.  * @IWM_UCODE_TLV_CAPA_QUIET_PERIOD_SUPPORT: supports Quiet Period requests  * @IWM_UCODE_TLV_CAPA_DQA_SUPPORT: supports dynamic queue allocation (DQA),  *	which also implies support for the scheduler configuration command  * @IWM_UCODE_TLV_CAPA_TDLS_CHANNEL_SWITCH: supports TDLS channel switching  * @IWM_UCODE_TLV_CAPA_CNSLDTD_D3_D0_IMG: Consolidated D3-D0 image  * @IWM_UCODE_TLV_CAPA_HOTSPOT_SUPPORT: supports Hot Spot Command  * @IWM_UCODE_TLV_CAPA_DC2DC_SUPPORT: supports DC2DC Command  * @IWM_UCODE_TLV_CAPA_2G_COEX_SUPPORT: supports 2G coex Command  * @IWM_UCODE_TLV_CAPA_CSUM_SUPPORT: supports TCP Checksum Offload  * @IWM_UCODE_TLV_CAPA_RADIO_BEACON_STATS: support radio and beacon statistics  * @IWM_UCODE_TLV_CAPA_P2P_STANDALONE_UAPSD: support p2p standalone U-APSD  * @IWM_UCODE_TLV_CAPA_BT_COEX_PLCR: enabled BT Coex packet level co-running  * @IWM_UCODE_TLV_CAPA_LAR_MULTI_MCC: ucode supports LAR updates with different  *	sources for the MCC. This TLV bit is a future replacement to  *	IWM_UCODE_TLV_API_WIFI_MCC_UPDATE. When either is set, multi-source LAR  *	is supported.  * @IWM_UCODE_TLV_CAPA_BT_COEX_RRC: supports BT Coex RRC  * @IWM_UCODE_TLV_CAPA_GSCAN_SUPPORT: supports gscan  * @IWM_UCODE_TLV_CAPA_NAN_SUPPORT: supports NAN  * @IWM_UCODE_TLV_CAPA_UMAC_UPLOAD: supports upload mode in umac (1=supported,  *	0=no support)  * @IWM_UCODE_TLV_CAPA_EXTENDED_DTS_MEASURE: extended DTS measurement  * @IWM_UCODE_TLV_CAPA_SHORT_PM_TIMEOUTS: supports short PM timeouts  * @IWM_UCODE_TLV_CAPA_BT_MPLUT_SUPPORT: supports bt-coex Multi-priority LUT  * @IWM_UCODE_TLV_CAPA_BEACON_ANT_SELECTION: firmware will decide on what  *	antenna the beacon should be transmitted  * @IWM_UCODE_TLV_CAPA_BEACON_STORING: firmware will store the latest beacon  *	from AP and will send it upon d0i3 exit.  * @IWM_UCODE_TLV_CAPA_LAR_SUPPORT_V2: support LAR API V2  * @IWM_UCODE_TLV_CAPA_CT_KILL_BY_FW: firmware responsible for CT-kill  * @IWM_UCODE_TLV_CAPA_TEMP_THS_REPORT_SUPPORT: supports temperature  *	thresholds reporting  * @IWM_UCODE_TLV_CAPA_CTDP_SUPPORT: supports cTDP command  * @IWM_UCODE_TLV_CAPA_USNIFFER_UNIFIED: supports usniffer enabled in  *	regular image.  * @IWM_UCODE_TLV_CAPA_EXTEND_SHARED_MEM_CFG: support getting more shared  *	memory addresses from the firmware.  * @IWM_UCODE_TLV_CAPA_LQM_SUPPORT: supports Link Quality Measurement  * @IWM_UCODE_TLV_CAPA_LMAC_UPLOAD: supports upload mode in lmac (1=supported,  *	0=no support)  *  * @IWM_NUM_UCODE_TLV_CAPA: number of bits used  */
end_comment

begin_enum
enum|enum
name|iwm_ucode_tlv_capa
block|{
name|IWM_UCODE_TLV_CAPA_D0I3_SUPPORT
init|=
literal|0
block|,
name|IWM_UCODE_TLV_CAPA_LAR_SUPPORT
init|=
literal|1
block|,
name|IWM_UCODE_TLV_CAPA_UMAC_SCAN
init|=
literal|2
block|,
name|IWM_UCODE_TLV_CAPA_BEAMFORMER
init|=
literal|3
block|,
name|IWM_UCODE_TLV_CAPA_TOF_SUPPORT
init|=
literal|5
block|,
name|IWM_UCODE_TLV_CAPA_TDLS_SUPPORT
init|=
literal|6
block|,
name|IWM_UCODE_TLV_CAPA_TXPOWER_INSERTION_SUPPORT
init|=
literal|8
block|,
name|IWM_UCODE_TLV_CAPA_DS_PARAM_SET_IE_SUPPORT
init|=
literal|9
block|,
name|IWM_UCODE_TLV_CAPA_WFA_TPC_REP_IE_SUPPORT
init|=
literal|10
block|,
name|IWM_UCODE_TLV_CAPA_QUIET_PERIOD_SUPPORT
init|=
literal|11
block|,
name|IWM_UCODE_TLV_CAPA_DQA_SUPPORT
init|=
literal|12
block|,
name|IWM_UCODE_TLV_CAPA_TDLS_CHANNEL_SWITCH
init|=
literal|13
block|,
name|IWM_UCODE_TLV_CAPA_CNSLDTD_D3_D0_IMG
init|=
literal|17
block|,
name|IWM_UCODE_TLV_CAPA_HOTSPOT_SUPPORT
init|=
literal|18
block|,
name|IWM_UCODE_TLV_CAPA_DC2DC_CONFIG_SUPPORT
init|=
literal|19
block|,
name|IWM_UCODE_TLV_CAPA_2G_COEX_SUPPORT
init|=
literal|20
block|,
name|IWM_UCODE_TLV_CAPA_CSUM_SUPPORT
init|=
literal|21
block|,
name|IWM_UCODE_TLV_CAPA_RADIO_BEACON_STATS
init|=
literal|22
block|,
name|IWM_UCODE_TLV_CAPA_P2P_STANDALONE_UAPSD
init|=
literal|26
block|,
name|IWM_UCODE_TLV_CAPA_BT_COEX_PLCR
init|=
literal|28
block|,
name|IWM_UCODE_TLV_CAPA_LAR_MULTI_MCC
init|=
literal|29
block|,
name|IWM_UCODE_TLV_CAPA_BT_COEX_RRC
init|=
literal|30
block|,
name|IWM_UCODE_TLV_CAPA_GSCAN_SUPPORT
init|=
literal|31
block|,
name|IWM_UCODE_TLV_CAPA_NAN_SUPPORT
init|=
literal|34
block|,
name|IWM_UCODE_TLV_CAPA_UMAC_UPLOAD
init|=
literal|35
block|,
name|IWM_UCODE_TLV_CAPA_EXTENDED_DTS_MEASURE
init|=
literal|64
block|,
name|IWM_UCODE_TLV_CAPA_SHORT_PM_TIMEOUTS
init|=
literal|65
block|,
name|IWM_UCODE_TLV_CAPA_BT_MPLUT_SUPPORT
init|=
literal|67
block|,
name|IWM_UCODE_TLV_CAPA_MULTI_QUEUE_RX_SUPPORT
init|=
literal|68
block|,
name|IWM_UCODE_TLV_CAPA_BEACON_ANT_SELECTION
init|=
literal|71
block|,
name|IWM_UCODE_TLV_CAPA_BEACON_STORING
init|=
literal|72
block|,
name|IWM_UCODE_TLV_CAPA_LAR_SUPPORT_V2
init|=
literal|73
block|,
name|IWM_UCODE_TLV_CAPA_CT_KILL_BY_FW
init|=
literal|74
block|,
name|IWM_UCODE_TLV_CAPA_TEMP_THS_REPORT_SUPPORT
init|=
literal|75
block|,
name|IWM_UCODE_TLV_CAPA_CTDP_SUPPORT
init|=
literal|76
block|,
name|IWM_UCODE_TLV_CAPA_USNIFFER_UNIFIED
init|=
literal|77
block|,
name|IWM_UCODE_TLV_CAPA_LMAC_UPLOAD
init|=
literal|79
block|,
name|IWM_UCODE_TLV_CAPA_EXTEND_SHARED_MEM_CFG
init|=
literal|80
block|,
name|IWM_UCODE_TLV_CAPA_LQM_SUPPORT
init|=
literal|81
block|,
name|IWM_NUM_UCODE_TLV_CAPA
init|=
literal|128
block|}
enum|;
end_enum

begin_comment
comment|/* The default calibrate table size if not specified by firmware file */
end_comment

begin_define
define|#
directive|define
name|IWM_DEFAULT_STANDARD_PHY_CALIBRATE_TBL_SIZE
value|18
end_define

begin_define
define|#
directive|define
name|IWM_MAX_STANDARD_PHY_CALIBRATE_TBL_SIZE
value|19
end_define

begin_define
define|#
directive|define
name|IWM_MAX_PHY_CALIBRATE_TBL_SIZE
value|253
end_define

begin_comment
comment|/* The default max probe length if not specified by the firmware file */
end_comment

begin_define
define|#
directive|define
name|IWM_DEFAULT_MAX_PROBE_LENGTH
value|200
end_define

begin_comment
comment|/*  * enumeration of ucode section.  * This enumeration is used directly for older firmware (before 16.0).  * For new firmware, there can be up to 4 sections (see below) but the  * first one packaged into the firmware file is the DATA section and  * some debugging code accesses that.  */
end_comment

begin_enum
enum|enum
name|iwm_ucode_sec
block|{
name|IWM_UCODE_SECTION_DATA
block|,
name|IWM_UCODE_SECTION_INST
block|, }
enum|;
end_enum

begin_comment
comment|/*  * For 16.0 uCode and above, there is no differentiation between sections,  * just an offset to the HW address.  */
end_comment

begin_define
define|#
directive|define
name|IWM_CPU1_CPU2_SEPARATOR_SECTION
value|0xFFFFCCCC
end_define

begin_define
define|#
directive|define
name|IWM_PAGING_SEPARATOR_SECTION
value|0xAAAABBBB
end_define

begin_comment
comment|/* uCode version contains 4 values: Major/Minor/API/Serial */
end_comment

begin_define
define|#
directive|define
name|IWM_UCODE_MAJOR
parameter_list|(
name|ver
parameter_list|)
value|(((ver)& 0xFF000000)>> 24)
end_define

begin_define
define|#
directive|define
name|IWM_UCODE_MINOR
parameter_list|(
name|ver
parameter_list|)
value|(((ver)& 0x00FF0000)>> 16)
end_define

begin_define
define|#
directive|define
name|IWM_UCODE_API
parameter_list|(
name|ver
parameter_list|)
value|(((ver)& 0x0000FF00)>> 8)
end_define

begin_define
define|#
directive|define
name|IWM_UCODE_SERIAL
parameter_list|(
name|ver
parameter_list|)
value|((ver)& 0x000000FF)
end_define

begin_comment
comment|/*  * Calibration control struct.  * Sent as part of the phy configuration command.  * @flow_trigger: bitmap for which calibrations to perform according to  *		flow triggers.  * @event_trigger: bitmap for which calibrations to perform according to  *		event triggers.  */
end_comment

begin_struct
struct|struct
name|iwm_tlv_calib_ctrl
block|{
name|uint32_t
name|flow_trigger
decl_stmt|;
name|uint32_t
name|event_trigger
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_enum
enum|enum
name|iwm_fw_phy_cfg
block|{
name|IWM_FW_PHY_CFG_RADIO_TYPE_POS
init|=
literal|0
block|,
name|IWM_FW_PHY_CFG_RADIO_TYPE
init|=
literal|0x3
operator|<<
name|IWM_FW_PHY_CFG_RADIO_TYPE_POS
block|,
name|IWM_FW_PHY_CFG_RADIO_STEP_POS
init|=
literal|2
block|,
name|IWM_FW_PHY_CFG_RADIO_STEP
init|=
literal|0x3
operator|<<
name|IWM_FW_PHY_CFG_RADIO_STEP_POS
block|,
name|IWM_FW_PHY_CFG_RADIO_DASH_POS
init|=
literal|4
block|,
name|IWM_FW_PHY_CFG_RADIO_DASH
init|=
literal|0x3
operator|<<
name|IWM_FW_PHY_CFG_RADIO_DASH_POS
block|,
name|IWM_FW_PHY_CFG_TX_CHAIN_POS
init|=
literal|16
block|,
name|IWM_FW_PHY_CFG_TX_CHAIN
init|=
literal|0xf
operator|<<
name|IWM_FW_PHY_CFG_TX_CHAIN_POS
block|,
name|IWM_FW_PHY_CFG_RX_CHAIN_POS
init|=
literal|20
block|,
name|IWM_FW_PHY_CFG_RX_CHAIN
init|=
literal|0xf
operator|<<
name|IWM_FW_PHY_CFG_RX_CHAIN_POS
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_UCODE_MAX_CS
value|1
end_define

begin_comment
comment|/**  * struct iwm_fw_cipher_scheme - a cipher scheme supported by FW.  * @cipher: a cipher suite selector  * @flags: cipher scheme flags (currently reserved for a future use)  * @hdr_len: a size of MPDU security header  * @pn_len: a size of PN  * @pn_off: an offset of pn from the beginning of the security header  * @key_idx_off: an offset of key index byte in the security header  * @key_idx_mask: a bit mask of key_idx bits  * @key_idx_shift: bit shift needed to get key_idx  * @mic_len: mic length in bytes  * @hw_cipher: a HW cipher index used in host commands  */
end_comment

begin_struct
struct|struct
name|iwm_fw_cipher_scheme
block|{
name|uint32_t
name|cipher
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|hdr_len
decl_stmt|;
name|uint8_t
name|pn_len
decl_stmt|;
name|uint8_t
name|pn_off
decl_stmt|;
name|uint8_t
name|key_idx_off
decl_stmt|;
name|uint8_t
name|key_idx_mask
decl_stmt|;
name|uint8_t
name|key_idx_shift
decl_stmt|;
name|uint8_t
name|mic_len
decl_stmt|;
name|uint8_t
name|hw_cipher
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * struct iwm_fw_cscheme_list - a cipher scheme list  * @size: a number of entries  * @cs: cipher scheme entries  */
end_comment

begin_struct
struct|struct
name|iwm_fw_cscheme_list
block|{
name|uint8_t
name|size
decl_stmt|;
name|struct
name|iwm_fw_cipher_scheme
name|cs
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * END iwl-fw.h  */
end_comment

begin_comment
comment|/*  * BEGIN iwl-fw-file.h  */
end_comment

begin_comment
comment|/* v1/v2 uCode file layout */
end_comment

begin_struct
struct|struct
name|iwm_ucode_header
block|{
name|uint32_t
name|ver
decl_stmt|;
comment|/* major/minor/API/serial */
union|union
block|{
struct|struct
block|{
name|uint32_t
name|inst_size
decl_stmt|;
comment|/* bytes of runtime code */
name|uint32_t
name|data_size
decl_stmt|;
comment|/* bytes of runtime data */
name|uint32_t
name|init_size
decl_stmt|;
comment|/* bytes of init code */
name|uint32_t
name|init_data_size
decl_stmt|;
comment|/* bytes of init data */
name|uint32_t
name|boot_size
decl_stmt|;
comment|/* bytes of bootstrap code */
name|uint8_t
name|data
index|[
literal|0
index|]
decl_stmt|;
comment|/* in same order as sizes */
block|}
name|v1
struct|;
struct|struct
block|{
name|uint32_t
name|build
decl_stmt|;
comment|/* build number */
name|uint32_t
name|inst_size
decl_stmt|;
comment|/* bytes of runtime code */
name|uint32_t
name|data_size
decl_stmt|;
comment|/* bytes of runtime data */
name|uint32_t
name|init_size
decl_stmt|;
comment|/* bytes of init code */
name|uint32_t
name|init_data_size
decl_stmt|;
comment|/* bytes of init data */
name|uint32_t
name|boot_size
decl_stmt|;
comment|/* bytes of bootstrap code */
name|uint8_t
name|data
index|[
literal|0
index|]
decl_stmt|;
comment|/* in same order as sizes */
block|}
name|v2
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * new TLV uCode file layout  *  * The new TLV file format contains TLVs, that each specify  * some piece of data.  */
end_comment

begin_enum
enum|enum
name|iwm_ucode_tlv_type
block|{
name|IWM_UCODE_TLV_INVALID
init|=
literal|0
block|,
comment|/* unused */
name|IWM_UCODE_TLV_INST
init|=
literal|1
block|,
name|IWM_UCODE_TLV_DATA
init|=
literal|2
block|,
name|IWM_UCODE_TLV_INIT
init|=
literal|3
block|,
name|IWM_UCODE_TLV_INIT_DATA
init|=
literal|4
block|,
name|IWM_UCODE_TLV_BOOT
init|=
literal|5
block|,
name|IWM_UCODE_TLV_PROBE_MAX_LEN
init|=
literal|6
block|,
comment|/* a uint32_t value */
name|IWM_UCODE_TLV_PAN
init|=
literal|7
block|,
name|IWM_UCODE_TLV_RUNT_EVTLOG_PTR
init|=
literal|8
block|,
name|IWM_UCODE_TLV_RUNT_EVTLOG_SIZE
init|=
literal|9
block|,
name|IWM_UCODE_TLV_RUNT_ERRLOG_PTR
init|=
literal|10
block|,
name|IWM_UCODE_TLV_INIT_EVTLOG_PTR
init|=
literal|11
block|,
name|IWM_UCODE_TLV_INIT_EVTLOG_SIZE
init|=
literal|12
block|,
name|IWM_UCODE_TLV_INIT_ERRLOG_PTR
init|=
literal|13
block|,
name|IWM_UCODE_TLV_ENHANCE_SENS_TBL
init|=
literal|14
block|,
name|IWM_UCODE_TLV_PHY_CALIBRATION_SIZE
init|=
literal|15
block|,
name|IWM_UCODE_TLV_WOWLAN_INST
init|=
literal|16
block|,
name|IWM_UCODE_TLV_WOWLAN_DATA
init|=
literal|17
block|,
name|IWM_UCODE_TLV_FLAGS
init|=
literal|18
block|,
name|IWM_UCODE_TLV_SEC_RT
init|=
literal|19
block|,
name|IWM_UCODE_TLV_SEC_INIT
init|=
literal|20
block|,
name|IWM_UCODE_TLV_SEC_WOWLAN
init|=
literal|21
block|,
name|IWM_UCODE_TLV_DEF_CALIB
init|=
literal|22
block|,
name|IWM_UCODE_TLV_PHY_SKU
init|=
literal|23
block|,
name|IWM_UCODE_TLV_SECURE_SEC_RT
init|=
literal|24
block|,
name|IWM_UCODE_TLV_SECURE_SEC_INIT
init|=
literal|25
block|,
name|IWM_UCODE_TLV_SECURE_SEC_WOWLAN
init|=
literal|26
block|,
name|IWM_UCODE_TLV_NUM_OF_CPU
init|=
literal|27
block|,
name|IWM_UCODE_TLV_CSCHEME
init|=
literal|28
block|,
comment|/* 	 * Following two are not in our base tag, but allow 	 * handling ucode version 9. 	 */
name|IWM_UCODE_TLV_API_CHANGES_SET
init|=
literal|29
block|,
name|IWM_UCODE_TLV_ENABLED_CAPABILITIES
init|=
literal|30
block|,
name|IWM_UCODE_TLV_N_SCAN_CHANNELS
init|=
literal|31
block|,
name|IWM_UCODE_TLV_PAGING
init|=
literal|32
block|,
name|IWM_UCODE_TLV_SEC_RT_USNIFFER
init|=
literal|34
block|,
name|IWM_UCODE_TLV_SDIO_ADMA_ADDR
init|=
literal|35
block|,
name|IWM_UCODE_TLV_FW_VERSION
init|=
literal|36
block|,
name|IWM_UCODE_TLV_FW_DBG_DEST
init|=
literal|38
block|,
name|IWM_UCODE_TLV_FW_DBG_CONF
init|=
literal|39
block|,
name|IWM_UCODE_TLV_FW_DBG_TRIGGER
init|=
literal|40
block|,
name|IWM_UCODE_TLV_FW_GSCAN_CAPA
init|=
literal|50
block|,
name|IWM_UCODE_TLV_FW_MEM_SEG
init|=
literal|51
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|iwm_ucode_tlv
block|{
name|uint32_t
name|type
decl_stmt|;
comment|/* see above */
name|uint32_t
name|length
decl_stmt|;
comment|/* not including type/length fields */
name|uint8_t
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|iwm_ucode_api
block|{
name|uint32_t
name|api_index
decl_stmt|;
name|uint32_t
name|api_flags
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwm_ucode_capa
block|{
name|uint32_t
name|api_index
decl_stmt|;
name|uint32_t
name|api_capa
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWM_TLV_UCODE_MAGIC
value|0x0a4c5749
end_define

begin_struct
struct|struct
name|iwm_tlv_ucode_header
block|{
comment|/* 	 * The TLV style ucode header is distinguished from 	 * the v1/v2 style header by first four bytes being 	 * zero, as such is an invalid combination of 	 * major/minor/API/serial versions. 	 */
name|uint32_t
name|zero
decl_stmt|;
name|uint32_t
name|magic
decl_stmt|;
name|uint8_t
name|human_readable
index|[
literal|64
index|]
decl_stmt|;
name|uint32_t
name|ver
decl_stmt|;
comment|/* major/minor/API/serial */
name|uint32_t
name|build
decl_stmt|;
name|uint64_t
name|ignore
decl_stmt|;
comment|/* 	 * The data contained herein has a TLV layout, 	 * see above for the TLV header and types. 	 * Note that each TLV is padded to a length 	 * that is a multiple of 4 for alignment. 	 */
name|uint8_t
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * END iwl-fw-file.h  */
end_comment

begin_comment
comment|/*  * BEGIN iwl-prph.h  */
end_comment

begin_comment
comment|/*  * Registers in this file are internal, not PCI bus memory mapped.  * Driver accesses these via IWM_HBUS_TARG_PRPH_* registers.  */
end_comment

begin_define
define|#
directive|define
name|IWM_PRPH_BASE
value|(0x00000)
end_define

begin_define
define|#
directive|define
name|IWM_PRPH_END
value|(0xFFFFF)
end_define

begin_comment
comment|/* APMG (power management) constants */
end_comment

begin_define
define|#
directive|define
name|IWM_APMG_BASE
value|(IWM_PRPH_BASE + 0x3000)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_CLK_CTRL_REG
value|(IWM_APMG_BASE + 0x0000)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_CLK_EN_REG
value|(IWM_APMG_BASE + 0x0004)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_CLK_DIS_REG
value|(IWM_APMG_BASE + 0x0008)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_PS_CTRL_REG
value|(IWM_APMG_BASE + 0x000c)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_PCIDEV_STT_REG
value|(IWM_APMG_BASE + 0x0010)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_RFKILL_REG
value|(IWM_APMG_BASE + 0x0014)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_RTC_INT_STT_REG
value|(IWM_APMG_BASE + 0x001c)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_RTC_INT_MSK_REG
value|(IWM_APMG_BASE + 0x0020)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_DIGITAL_SVR_REG
value|(IWM_APMG_BASE + 0x0058)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_ANALOG_SVR_REG
value|(IWM_APMG_BASE + 0x006C)
end_define

begin_define
define|#
directive|define
name|IWM_APMS_CLK_VAL_MRB_FUNC_MODE
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_CLK_VAL_DMA_CLK_RQT
value|(0x00000200)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_CLK_VAL_BSM_CLK_RQT
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_PS_CTRL_EARLY_PWR_OFF_RESET_DIS
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_PS_CTRL_VAL_RESET_REQ
value|(0x04000000)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_PS_CTRL_MSK_PWR_SRC
value|(0x03000000)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_PS_CTRL_VAL_PWR_SRC_VMAIN
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_PS_CTRL_VAL_PWR_SRC_VAUX
value|(0x02000000)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_SVR_VOLTAGE_CONFIG_BIT_MSK
value|(0x000001E0)
end_define

begin_comment
comment|/* bit 8:5 */
end_comment

begin_define
define|#
directive|define
name|IWM_APMG_SVR_DIGITAL_VOLTAGE_1_32
value|(0x00000060)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_PCIDEV_STT_VAL_L1_ACT_DIS
value|(0x00000800)
end_define

begin_define
define|#
directive|define
name|IWM_APMG_RTC_INT_STT_RFKILL
value|(0x10000000)
end_define

begin_comment
comment|/* Device system time */
end_comment

begin_define
define|#
directive|define
name|IWM_DEVICE_SYSTEM_TIME_REG
value|0xA0206C
end_define

begin_comment
comment|/* Device NMI register */
end_comment

begin_define
define|#
directive|define
name|IWM_DEVICE_SET_NMI_REG
value|0x00a01c30
end_define

begin_define
define|#
directive|define
name|IWM_DEVICE_SET_NMI_VAL_HW
value|0x01
end_define

begin_define
define|#
directive|define
name|IWM_DEVICE_SET_NMI_VAL_DRV
value|0x80
end_define

begin_define
define|#
directive|define
name|IWM_DEVICE_SET_NMI_8000_REG
value|0x00a01c24
end_define

begin_define
define|#
directive|define
name|IWM_DEVICE_SET_NMI_8000_VAL
value|0x1000000
end_define

begin_comment
comment|/*  * Device reset for family 8000  * write to bit 24 in order to reset the CPU  */
end_comment

begin_define
define|#
directive|define
name|IWM_RELEASE_CPU_RESET
value|0x300c
end_define

begin_define
define|#
directive|define
name|IWM_RELEASE_CPU_RESET_BIT
value|0x1000000
end_define

begin_comment
comment|/*****************************************************************************  *                        7000/3000 series SHR DTS addresses                 *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|IWM_SHR_MISC_WFM_DTS_EN
value|(0x00a10024)
end_define

begin_define
define|#
directive|define
name|IWM_DTSC_CFG_MODE
value|(0x00a10604)
end_define

begin_define
define|#
directive|define
name|IWM_DTSC_VREF_AVG
value|(0x00a10648)
end_define

begin_define
define|#
directive|define
name|IWM_DTSC_VREF5_AVG
value|(0x00a1064c)
end_define

begin_define
define|#
directive|define
name|IWM_DTSC_CFG_MODE_PERIODIC
value|(0x2)
end_define

begin_define
define|#
directive|define
name|IWM_DTSC_PTAT_AVG
value|(0x00a10650)
end_define

begin_comment
comment|/**  * Tx Scheduler  *  * The Tx Scheduler selects the next frame to be transmitted, choosing TFDs  * (Transmit Frame Descriptors) from up to 16 circular Tx queues resident in  * host DRAM.  It steers each frame's Tx command (which contains the frame  * data) into one of up to 7 prioritized Tx DMA FIFO channels within the  * device.  A queue maps to only one (selectable by driver) Tx DMA channel,  * but one DMA channel may take input from several queues.  *  * Tx DMA FIFOs have dedicated purposes.  *  * For 5000 series and up, they are used differently  * (cf. iwl5000_default_queue_to_tx_fifo in iwl-5000.c):  *  * 0 -- EDCA BK (background) frames, lowest priority  * 1 -- EDCA BE (best effort) frames, normal priority  * 2 -- EDCA VI (video) frames, higher priority  * 3 -- EDCA VO (voice) and management frames, highest priority  * 4 -- unused  * 5 -- unused  * 6 -- unused  * 7 -- Commands  *  * Driver should normally map queues 0-6 to Tx DMA/FIFO channels 0-6.  * In addition, driver can map the remaining queues to Tx DMA/FIFO  * channels 0-3 to support 11n aggregation via EDCA DMA channels.  *  * The driver sets up each queue to work in one of two modes:  *  * 1)  Scheduler-Ack, in which the scheduler automatically supports a  *     block-ack (BA) window of up to 64 TFDs.  In this mode, each queue  *     contains TFDs for a unique combination of Recipient Address (RA)  *     and Traffic Identifier (TID), that is, traffic of a given  *     Quality-Of-Service (QOS) priority, destined for a single station.  *  *     In scheduler-ack mode, the scheduler keeps track of the Tx status of  *     each frame within the BA window, including whether it's been transmitted,  *     and whether it's been acknowledged by the receiving station.  The device  *     automatically processes block-acks received from the receiving STA,  *     and reschedules un-acked frames to be retransmitted (successful  *     Tx completion may end up being out-of-order).  *  *     The driver must maintain the queue's Byte Count table in host DRAM  *     for this mode.  *     This mode does not support fragmentation.  *  * 2)  FIFO (a.k.a. non-Scheduler-ACK), in which each TFD is processed in order.  *     The device may automatically retry Tx, but will retry only one frame  *     at a time, until receiving ACK from receiving station, or reaching  *     retry limit and giving up.  *  *     The command queue (#4/#9) must use this mode!  *     This mode does not require use of the Byte Count table in host DRAM.  *  * Driver controls scheduler operation via 3 means:  * 1)  Scheduler registers  * 2)  Shared scheduler data base in internal SRAM  * 3)  Shared data in host DRAM  *  * Initialization:  *  * When loading, driver should allocate memory for:  * 1)  16 TFD circular buffers, each with space for (typically) 256 TFDs.  * 2)  16 Byte Count circular buffers in 16 KBytes contiguous memory  *     (1024 bytes for each queue).  *  * After receiving "Alive" response from uCode, driver must initialize  * the scheduler (especially for queue #4/#9, the command queue, otherwise  * the driver can't issue commands!):  */
end_comment

begin_define
define|#
directive|define
name|IWM_SCD_MEM_LOWER_BOUND
value|(0x0000)
end_define

begin_comment
comment|/**  * Max Tx window size is the max number of contiguous TFDs that the scheduler  * can keep track of at one time when creating block-ack chains of frames.  * Note that "64" matches the number of ack bits in a block-ack packet.  */
end_comment

begin_define
define|#
directive|define
name|IWM_SCD_WIN_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|IWM_SCD_FRAME_LIMIT
value|64
end_define

begin_define
define|#
directive|define
name|IWM_SCD_TXFIFO_POS_TID
value|(0)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_TXFIFO_POS_RA
value|(4)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_RA_TID_MAP_RATID_MSK
value|(0x01FF)
end_define

begin_comment
comment|/* agn SCD */
end_comment

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_STTS_REG_POS_TXF
value|(0)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_STTS_REG_POS_ACTIVE
value|(3)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_STTS_REG_POS_WSL
value|(4)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_STTS_REG_POS_SCD_ACT_EN
value|(19)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_STTS_REG_MSK
value|(0x017F0000)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_CTX_REG1_CREDIT_POS
value|(8)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_CTX_REG1_CREDIT_MSK
value|(0x00FFFF00)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_CTX_REG1_SUPER_CREDIT_POS
value|(24)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_CTX_REG1_SUPER_CREDIT_MSK
value|(0xFF000000)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_CTX_REG2_WIN_SIZE_POS
value|(0)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_CTX_REG2_WIN_SIZE_MSK
value|(0x0000007F)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_CTX_REG2_FRAME_LIMIT_POS
value|(16)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUE_CTX_REG2_FRAME_LIMIT_MSK
value|(0x007F0000)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_GP_CTRL_ENABLE_31_QUEUES
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_GP_CTRL_AUTO_ACTIVE_MODE
value|(1<< 18)
end_define

begin_comment
comment|/* Context Data */
end_comment

begin_define
define|#
directive|define
name|IWM_SCD_CONTEXT_MEM_LOWER_BOUND
value|(IWM_SCD_MEM_LOWER_BOUND + 0x600)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_CONTEXT_MEM_UPPER_BOUND
value|(IWM_SCD_MEM_LOWER_BOUND + 0x6A0)
end_define

begin_comment
comment|/* Tx status */
end_comment

begin_define
define|#
directive|define
name|IWM_SCD_TX_STTS_MEM_LOWER_BOUND
value|(IWM_SCD_MEM_LOWER_BOUND + 0x6A0)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_TX_STTS_MEM_UPPER_BOUND
value|(IWM_SCD_MEM_LOWER_BOUND + 0x7E0)
end_define

begin_comment
comment|/* Translation Data */
end_comment

begin_define
define|#
directive|define
name|IWM_SCD_TRANS_TBL_MEM_LOWER_BOUND
value|(IWM_SCD_MEM_LOWER_BOUND + 0x7E0)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_TRANS_TBL_MEM_UPPER_BOUND
value|(IWM_SCD_MEM_LOWER_BOUND + 0x808)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_CONTEXT_QUEUE_OFFSET
parameter_list|(
name|x
parameter_list|)
define|\
value|(IWM_SCD_CONTEXT_MEM_LOWER_BOUND + ((x) * 8))
end_define

begin_define
define|#
directive|define
name|IWM_SCD_TX_STTS_QUEUE_OFFSET
parameter_list|(
name|x
parameter_list|)
define|\
value|(IWM_SCD_TX_STTS_MEM_LOWER_BOUND + ((x) * 16))
end_define

begin_define
define|#
directive|define
name|IWM_SCD_TRANS_TBL_OFFSET_QUEUE
parameter_list|(
name|x
parameter_list|)
define|\
value|((IWM_SCD_TRANS_TBL_MEM_LOWER_BOUND + ((x) * 2))& 0xfffc)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_BASE
value|(IWM_PRPH_BASE + 0xa02c00)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_SRAM_BASE_ADDR
value|(IWM_SCD_BASE + 0x0)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_DRAM_BASE_ADDR
value|(IWM_SCD_BASE + 0x8)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_AIT
value|(IWM_SCD_BASE + 0x0c)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_TXFACT
value|(IWM_SCD_BASE + 0x10)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_ACTIVE
value|(IWM_SCD_BASE + 0x14)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_QUEUECHAIN_SEL
value|(IWM_SCD_BASE + 0xe8)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_CHAINEXT_EN
value|(IWM_SCD_BASE + 0x244)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_AGGR_SEL
value|(IWM_SCD_BASE + 0x248)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_INTERRUPT_MASK
value|(IWM_SCD_BASE + 0x108)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_GP_CTRL
value|(IWM_SCD_BASE + 0x1a8)
end_define

begin_define
define|#
directive|define
name|IWM_SCD_EN_CTRL
value|(IWM_SCD_BASE + 0x254)
end_define

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|IWM_SCD_QUEUE_WRPTR
parameter_list|(
name|unsigned
name|int
name|chnl
parameter_list|)
block|{
if|if
condition|(
name|chnl
operator|<
literal|20
condition|)
return|return
name|IWM_SCD_BASE
operator|+
literal|0x18
operator|+
name|chnl
operator|*
literal|4
return|;
return|return
name|IWM_SCD_BASE
operator|+
literal|0x284
operator|+
operator|(
name|chnl
operator|-
literal|20
operator|)
operator|*
literal|4
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|IWM_SCD_QUEUE_RDPTR
parameter_list|(
name|unsigned
name|int
name|chnl
parameter_list|)
block|{
if|if
condition|(
name|chnl
operator|<
literal|20
condition|)
return|return
name|IWM_SCD_BASE
operator|+
literal|0x68
operator|+
name|chnl
operator|*
literal|4
return|;
return|return
name|IWM_SCD_BASE
operator|+
literal|0x2B4
operator|+
operator|(
name|chnl
operator|-
literal|20
operator|)
operator|*
literal|4
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|IWM_SCD_QUEUE_STATUS_BITS
parameter_list|(
name|unsigned
name|int
name|chnl
parameter_list|)
block|{
if|if
condition|(
name|chnl
operator|<
literal|20
condition|)
return|return
name|IWM_SCD_BASE
operator|+
literal|0x10c
operator|+
name|chnl
operator|*
literal|4
return|;
return|return
name|IWM_SCD_BASE
operator|+
literal|0x384
operator|+
operator|(
name|chnl
operator|-
literal|20
operator|)
operator|*
literal|4
return|;
block|}
end_function

begin_comment
comment|/*********************** END TX SCHEDULER *************************************/
end_comment

begin_comment
comment|/* Oscillator clock */
end_comment

begin_define
define|#
directive|define
name|IWM_OSC_CLK
value|(0xa04068)
end_define

begin_define
define|#
directive|define
name|IWM_OSC_CLK_FORCE_CONTROL
value|(0x8)
end_define

begin_comment
comment|/*  * END iwl-prph.h  */
end_comment

begin_comment
comment|/*  * BEGIN iwl-fh.h  */
end_comment

begin_comment
comment|/****************************/
end_comment

begin_comment
comment|/* Flow Handler Definitions */
end_comment

begin_comment
comment|/****************************/
end_comment

begin_comment
comment|/**  * This I/O area is directly read/writable by driver (e.g. Linux uses writel())  * Addresses are offsets from device's PCI hardware base address.  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_MEM_LOWER_BOUND
value|(0x1000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_UPPER_BOUND
value|(0x2000)
end_define

begin_comment
comment|/**  * Keep-Warm (KW) buffer base address.  *  * Driver must allocate a 4KByte buffer that is for keeping the  * host DRAM powered on (via dummy accesses to DRAM) to maintain low-latency  * DRAM access when doing Txing or Rxing.  The dummy accesses prevent host  * from going into a power-savings mode that would cause higher DRAM latency,  * and possible data over/under-runs, before all Tx/Rx is complete.  *  * Driver loads IWM_FH_KW_MEM_ADDR_REG with the physical address (bits 35:4)  * of the buffer, which must be 4K aligned.  Once this is set up, the device  * automatically invokes keep-warm accesses when normal accesses might not  * be sufficient to maintain fast DRAM response.  *  * Bit fields:  *  31-0:  Keep-warm buffer physical base address [35:4], must be 4K aligned  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_KW_MEM_ADDR_REG
value|(IWM_FH_MEM_LOWER_BOUND + 0x97C)
end_define

begin_comment
comment|/**  * TFD Circular Buffers Base (CBBC) addresses  *  * Device has 16 base pointer registers, one for each of 16 host-DRAM-resident  * circular buffers (CBs/queues) containing Transmit Frame Descriptors (TFDs)  * (see struct iwm_tfd_frame).  These 16 pointer registers are offset by 0x04  * bytes from one another.  Each TFD circular buffer in DRAM must be 256-byte  * aligned (address bits 0-7 must be 0).  * Later devices have 20 (5000 series) or 30 (higher) queues, but the registers  * for them are in different places.  *  * Bit fields in each pointer register:  *  27-0: TFD CB physical base address [35:8], must be 256-byte aligned  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_MEM_CBBC_0_15_LOWER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0x9D0)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_CBBC_0_15_UPPER_BOUN
value|(IWM_FH_MEM_LOWER_BOUND + 0xA10)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_CBBC_16_19_LOWER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xBF0)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_CBBC_16_19_UPPER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xC00)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_CBBC_20_31_LOWER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xB20)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_CBBC_20_31_UPPER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xB80)
end_define

begin_comment
comment|/* Find TFD CB base pointer for given queue */
end_comment

begin_function
specifier|static
specifier|inline
name|unsigned
name|int
name|IWM_FH_MEM_CBBC_QUEUE
parameter_list|(
name|unsigned
name|int
name|chnl
parameter_list|)
block|{
if|if
condition|(
name|chnl
operator|<
literal|16
condition|)
return|return
name|IWM_FH_MEM_CBBC_0_15_LOWER_BOUND
operator|+
literal|4
operator|*
name|chnl
return|;
if|if
condition|(
name|chnl
operator|<
literal|20
condition|)
return|return
name|IWM_FH_MEM_CBBC_16_19_LOWER_BOUND
operator|+
literal|4
operator|*
operator|(
name|chnl
operator|-
literal|16
operator|)
return|;
return|return
name|IWM_FH_MEM_CBBC_20_31_LOWER_BOUND
operator|+
literal|4
operator|*
operator|(
name|chnl
operator|-
literal|20
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Rx SRAM Control and Status Registers (RSCSR)  *  * These registers provide handshake between driver and device for the Rx queue  * (this queue handles *all* command responses, notifications, Rx data, etc.  * sent from uCode to host driver).  Unlike Tx, there is only one Rx  * queue, and only one Rx DMA/FIFO channel.  Also unlike Tx, which can  * concatenate up to 20 DRAM buffers to form a Tx frame, each Receive Buffer  * Descriptor (RBD) points to only one Rx Buffer (RB); there is a 1:1  * mapping between RBDs and RBs.  *  * Driver must allocate host DRAM memory for the following, and set the  * physical address of each into device registers:  *  * 1)  Receive Buffer Descriptor (RBD) circular buffer (CB), typically with 256  *     entries (although any power of 2, up to 4096, is selectable by driver).  *     Each entry (1 dword) points to a receive buffer (RB) of consistent size  *     (typically 4K, although 8K or 16K are also selectable by driver).  *     Driver sets up RB size and number of RBDs in the CB via Rx config  *     register IWM_FH_MEM_RCSR_CHNL0_CONFIG_REG.  *  *     Bit fields within one RBD:  *     27-0:  Receive Buffer physical address bits [35:8], 256-byte aligned  *  *     Driver sets physical address [35:8] of base of RBD circular buffer  *     into IWM_FH_RSCSR_CHNL0_RBDCB_BASE_REG [27:0].  *  * 2)  Rx status buffer, 8 bytes, in which uCode indicates which Rx Buffers  *     (RBs) have been filled, via a "write pointer", actually the index of  *     the RB's corresponding RBD within the circular buffer.  Driver sets  *     physical address [35:4] into IWM_FH_RSCSR_CHNL0_STTS_WPTR_REG [31:0].  *  *     Bit fields in lower dword of Rx status buffer (upper dword not used  *     by driver:  *     31-12:  Not used by driver  *     11- 0:  Index of last filled Rx buffer descriptor  *             (device writes, driver reads this value)  *  * As the driver prepares Receive Buffers (RBs) for device to fill, driver must  * enter pointers to these RBs into contiguous RBD circular buffer entries,  * and update the device's "write" index register,  * IWM_FH_RSCSR_CHNL0_RBDCB_WPTR_REG.  *  * This "write" index corresponds to the *next* RBD that the driver will make  * available, i.e. one RBD past the tail of the ready-to-fill RBDs within  * the circular buffer.  This value should initially be 0 (before preparing any  * RBs), should be 8 after preparing the first 8 RBs (for example), and must  * wrap back to 0 at the end of the circular buffer (but don't wrap before  * "read" index has advanced past 1!  See below).  * NOTE:  DEVICE EXPECTS THE WRITE INDEX TO BE INCREMENTED IN MULTIPLES OF 8.  *  * As the device fills RBs (referenced from contiguous RBDs within the circular  * buffer), it updates the Rx status buffer in host DRAM, 2) described above,  * to tell the driver the index of the latest filled RBD.  The driver must  * read this "read" index from DRAM after receiving an Rx interrupt from device  *  * The driver must also internally keep track of a third index, which is the  * next RBD to process.  When receiving an Rx interrupt, driver should process  * all filled but unprocessed RBs up to, but not including, the RB  * corresponding to the "read" index.  For example, if "read" index becomes "1",  * driver may process the RB pointed to by RBD 0.  Depending on volume of  * traffic, there may be many RBs to process.  *  * If read index == write index, device thinks there is no room to put new data.  * Due to this, the maximum number of filled RBs is 255, instead of 256.  To  * be safe, make sure that there is a gap of at least 2 RBDs between "write"  * and "read" indexes; that is, make sure that there are no more than 254  * buffers waiting to be filled.  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_MEM_RSCSR_LOWER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xBC0)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_RSCSR_UPPER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xC00)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_RSCSR_CHNL0
value|(IWM_FH_MEM_RSCSR_LOWER_BOUND)
end_define

begin_comment
comment|/**  * Physical base address of 8-byte Rx Status buffer.  * Bit fields:  *  31-0: Rx status buffer physical base address [35:4], must 16-byte aligned.  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_RSCSR_CHNL0_STTS_WPTR_REG
value|(IWM_FH_MEM_RSCSR_CHNL0)
end_define

begin_comment
comment|/**  * Physical base address of Rx Buffer Descriptor Circular Buffer.  * Bit fields:  *  27-0:  RBD CD physical base address [35:8], must be 256-byte aligned.  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_RSCSR_CHNL0_RBDCB_BASE_REG
value|(IWM_FH_MEM_RSCSR_CHNL0 + 0x004)
end_define

begin_comment
comment|/**  * Rx write pointer (index, really!).  * Bit fields:  *  11-0:  Index of driver's most recent prepared-to-be-filled RBD, + 1.  *         NOTE:  For 256-entry circular buffer, use only bits [7:0].  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_RSCSR_CHNL0_RBDCB_WPTR_REG
value|(IWM_FH_MEM_RSCSR_CHNL0 + 0x008)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RSCSR_CHNL0_WPTR
value|(IWM_FH_RSCSR_CHNL0_RBDCB_WPTR_REG)
end_define

begin_define
define|#
directive|define
name|IWM_FW_RSCSR_CHNL0_RXDCB_RDPTR_REG
value|(IWM_FH_MEM_RSCSR_CHNL0 + 0x00c)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RSCSR_CHNL0_RDPTR
value|IWM_FW_RSCSR_CHNL0_RXDCB_RDPTR_REG
end_define

begin_comment
comment|/**  * Rx Config/Status Registers (RCSR)  * Rx Config Reg for channel 0 (only channel used)  *  * Driver must initialize IWM_FH_MEM_RCSR_CHNL0_CONFIG_REG as follows for  * normal operation (see bit fields).  *  * Clearing IWM_FH_MEM_RCSR_CHNL0_CONFIG_REG to 0 turns off Rx DMA.  * Driver should poll IWM_FH_MEM_RSSR_RX_STATUS_REG	for  * IWM_FH_RSSR_CHNL0_RX_STATUS_CHNL_IDLE (bit 24) before continuing.  *  * Bit fields:  * 31-30: Rx DMA channel enable: '00' off/pause, '01' pause at end of frame,  *        '10' operate normally  * 29-24: reserved  * 23-20: # RBDs in circular buffer = 2^value; use "8" for 256 RBDs (normal),  *        min "5" for 32 RBDs, max "12" for 4096 RBDs.  * 19-18: reserved  * 17-16: size of each receive buffer; '00' 4K (normal), '01' 8K,  *        '10' 12K, '11' 16K.  * 15-14: reserved  * 13-12: IRQ destination; '00' none, '01' host driver (normal operation)  * 11- 4: timeout for closing Rx buffer and interrupting host (units 32 usec)  *        typical value 0x10 (about 1/2 msec)  *  3- 0: reserved  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_MEM_RCSR_LOWER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xC00)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_RCSR_UPPER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xCC0)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_RCSR_CHNL0
value|(IWM_FH_MEM_RCSR_LOWER_BOUND)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_RCSR_CHNL0_CONFIG_REG
value|(IWM_FH_MEM_RCSR_CHNL0)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_RCSR_CHNL0_RBDCB_WPTR
value|(IWM_FH_MEM_RCSR_CHNL0 + 0x8)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_RCSR_CHNL0_FLUSH_RB_REQ
value|(IWM_FH_MEM_RCSR_CHNL0 + 0x10)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RCSR_CHNL0_RX_CONFIG_RB_TIMEOUT_MSK
value|(0x00000FF0)
end_define

begin_comment
comment|/* bits 4-11 */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_RCSR_CHNL0_RX_CONFIG_IRQ_DEST_MSK
value|(0x00001000)
end_define

begin_comment
comment|/* bits 12 */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_RCSR_CHNL0_RX_CONFIG_SINGLE_FRAME_MSK
value|(0x00008000)
end_define

begin_comment
comment|/* bit 15 */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_RCSR_CHNL0_RX_CONFIG_RB_SIZE_MSK
value|(0x00030000)
end_define

begin_comment
comment|/* bits 16-17 */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_RCSR_CHNL0_RX_CONFIG_RBDBC_SIZE_MSK
value|(0x00F00000)
end_define

begin_comment
comment|/* bits 20-23 */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_RCSR_CHNL0_RX_CONFIG_DMA_CHNL_EN_MSK
value|(0xC0000000)
end_define

begin_comment
comment|/* bits 30-31*/
end_comment

begin_define
define|#
directive|define
name|IWM_FH_RCSR_RX_CONFIG_RBDCB_SIZE_POS
value|(20)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RCSR_RX_CONFIG_REG_IRQ_RBTH_POS
value|(4)
end_define

begin_define
define|#
directive|define
name|IWM_RX_RB_TIMEOUT
value|(0x11)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RCSR_RX_CONFIG_CHNL_EN_PAUSE_VAL
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RCSR_RX_CONFIG_CHNL_EN_PAUSE_EOF_VAL
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RCSR_RX_CONFIG_CHNL_EN_ENABLE_VAL
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RCSR_RX_CONFIG_REG_VAL_RB_SIZE_4K
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RCSR_RX_CONFIG_REG_VAL_RB_SIZE_8K
value|(0x00010000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RCSR_RX_CONFIG_REG_VAL_RB_SIZE_12K
value|(0x00020000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RCSR_RX_CONFIG_REG_VAL_RB_SIZE_16K
value|(0x00030000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RCSR_CHNL0_RX_IGNORE_RXF_EMPTY
value|(0x00000004)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RCSR_CHNL0_RX_CONFIG_IRQ_DEST_NO_INT_VAL
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RCSR_CHNL0_RX_CONFIG_IRQ_DEST_INT_HOST_VAL
value|(0x00001000)
end_define

begin_comment
comment|/**  * Rx Shared Status Registers (RSSR)  *  * After stopping Rx DMA channel (writing 0 to  * IWM_FH_MEM_RCSR_CHNL0_CONFIG_REG), driver must poll  * IWM_FH_MEM_RSSR_RX_STATUS_REG until Rx channel is idle.  *  * Bit fields:  *  24:  1 = Channel 0 is idle  *  * IWM_FH_MEM_RSSR_SHARED_CTRL_REG and IWM_FH_MEM_RSSR_RX_ENABLE_ERR_IRQ2DRV  * contain default values that should not be altered by the driver.  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_MEM_RSSR_LOWER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xC40)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_RSSR_UPPER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xD00)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_RSSR_SHARED_CTRL_REG
value|(IWM_FH_MEM_RSSR_LOWER_BOUND)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_RSSR_RX_STATUS_REG
value|(IWM_FH_MEM_RSSR_LOWER_BOUND + 0x004)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_RSSR_RX_ENABLE_ERR_IRQ2DRV
define|\
value|(IWM_FH_MEM_RSSR_LOWER_BOUND + 0x008)
end_define

begin_define
define|#
directive|define
name|IWM_FH_RSSR_CHNL0_RX_STATUS_CHNL_IDLE
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_MEM_TFDIB_REG1_ADDR_BITSHIFT
value|28
end_define

begin_comment
comment|/* TFDB  Area - TFDs buffer table */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_MEM_TFDIB_DRAM_ADDR_LSB_MSK
value|(0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TFDIB_LOWER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0x900)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TFDIB_UPPER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0x958)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TFDIB_CTRL0_REG
parameter_list|(
name|_chnl
parameter_list|)
value|(IWM_FH_TFDIB_LOWER_BOUND + 0x8 * (_chnl))
end_define

begin_define
define|#
directive|define
name|IWM_FH_TFDIB_CTRL1_REG
parameter_list|(
name|_chnl
parameter_list|)
value|(IWM_FH_TFDIB_LOWER_BOUND + 0x8 * (_chnl) + 0x4)
end_define

begin_comment
comment|/**  * Transmit DMA Channel Control/Status Registers (TCSR)  *  * Device has one configuration register for each of 8 Tx DMA/FIFO channels  * supported in hardware (don't confuse these with the 16 Tx queues in DRAM,  * which feed the DMA/FIFO channels); config regs are separated by 0x20 bytes.  *  * To use a Tx DMA channel, driver must initialize its  * IWM_FH_TCSR_CHNL_TX_CONFIG_REG(chnl) with:  *  * IWM_FH_TCSR_TX_CONFIG_REG_VAL_DMA_CHNL_ENABLE |  * IWM_FH_TCSR_TX_CONFIG_REG_VAL_DMA_CREDIT_ENABLE_VAL  *  * All other bits should be 0.  *  * Bit fields:  * 31-30: Tx DMA channel enable: '00' off/pause, '01' pause at end of frame,  *        '10' operate normally  * 29- 4: Reserved, set to "0"  *     3: Enable internal DMA requests (1, normal operation), disable (0)  *  2- 0: Reserved, set to "0"  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_TCSR_LOWER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xD00)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_UPPER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xE60)
end_define

begin_comment
comment|/* Find Control/Status reg for given Tx DMA/FIFO channel */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_TCSR_CHNL_NUM
value|(8)
end_define

begin_comment
comment|/* TCSR: tx_config register values */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_TCSR_CHNL_TX_CONFIG_REG
parameter_list|(
name|_chnl
parameter_list|)
define|\
value|(IWM_FH_TCSR_LOWER_BOUND + 0x20 * (_chnl))
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_CHNL_TX_CREDIT_REG
parameter_list|(
name|_chnl
parameter_list|)
define|\
value|(IWM_FH_TCSR_LOWER_BOUND + 0x20 * (_chnl) + 0x4)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_CHNL_TX_BUF_STS_REG
parameter_list|(
name|_chnl
parameter_list|)
define|\
value|(IWM_FH_TCSR_LOWER_BOUND + 0x20 * (_chnl) + 0x8)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_MSG_MODE_TXF
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_MSG_MODE_DRV
value|(0x00000001)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_DMA_CREDIT_DISABLE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_DMA_CREDIT_ENABLE
value|(0x00000008)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_CIRQ_HOST_NOINT
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_CIRQ_HOST_ENDTFD
value|(0x00100000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_CIRQ_HOST_IFTFD
value|(0x00200000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_CIRQ_RTC_NOINT
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_CIRQ_RTC_ENDTFD
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_CIRQ_RTC_IFTFD
value|(0x00800000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_DMA_CHNL_PAUSE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_DMA_CHNL_PAUSE_EOF
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_TX_CONFIG_REG_VAL_DMA_CHNL_ENABLE
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_CHNL_TX_BUF_STS_REG_VAL_TFDB_EMPTY
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_CHNL_TX_BUF_STS_REG_VAL_TFDB_WAIT
value|(0x00002000)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_CHNL_TX_BUF_STS_REG_VAL_TFDB_VALID
value|(0x00000003)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_CHNL_TX_BUF_STS_REG_POS_TB_NUM
value|(20)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TCSR_CHNL_TX_BUF_STS_REG_POS_TB_IDX
value|(12)
end_define

begin_comment
comment|/**  * Tx Shared Status Registers (TSSR)  *  * After stopping Tx DMA channel (writing 0 to  * IWM_FH_TCSR_CHNL_TX_CONFIG_REG(chnl)), driver must poll  * IWM_FH_TSSR_TX_STATUS_REG until selected Tx channel is idle  * (channel's buffers empty | no pending requests).  *  * Bit fields:  * 31-24:  1 = Channel buffers empty (channel 7:0)  * 23-16:  1 = No pending requests (channel 7:0)  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_TSSR_LOWER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xEA0)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TSSR_UPPER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0xEC0)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TSSR_TX_STATUS_REG
value|(IWM_FH_TSSR_LOWER_BOUND + 0x010)
end_define

begin_comment
comment|/**  * Bit fields for TSSR(Tx Shared Status& Control) error status register:  * 31:  Indicates an address error when accessed to internal memory  *	uCode/driver must write "1" in order to clear this flag  * 30:  Indicates that Host did not send the expected number of dwords to FH  *	uCode/driver must write "1" in order to clear this flag  * 16-9:Each status bit is for one channel. Indicates that an (Error) ActDMA  *	command was received from the scheduler while the TRB was already full  *	with previous command  *	uCode/driver must write "1" in order to clear this flag  * 7-0: Each status bit indicates a channel's TxCredit error. When an error  *	bit is set, it indicates that the FH has received a full indication  *	from the RTC TxFIFO and the current value of the TxCredit counter was  *	not equal to zero. This mean that the credit mechanism was not  *	synchronized to the TxFIFO status  *	uCode/driver must write "1" in order to clear this flag  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_TSSR_TX_ERROR_REG
value|(IWM_FH_TSSR_LOWER_BOUND + 0x018)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TSSR_TX_MSG_CONFIG_REG
value|(IWM_FH_TSSR_LOWER_BOUND + 0x008)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TSSR_TX_STATUS_REG_MSK_CHNL_IDLE
parameter_list|(
name|_chnl
parameter_list|)
value|((1<< (_chnl))<< 16)
end_define

begin_comment
comment|/* Tx service channels */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_SRVC_CHNL
value|(9)
end_define

begin_define
define|#
directive|define
name|IWM_FH_SRVC_LOWER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0x9C8)
end_define

begin_define
define|#
directive|define
name|IWM_FH_SRVC_UPPER_BOUND
value|(IWM_FH_MEM_LOWER_BOUND + 0x9D0)
end_define

begin_define
define|#
directive|define
name|IWM_FH_SRVC_CHNL_SRAM_ADDR_REG
parameter_list|(
name|_chnl
parameter_list|)
define|\
value|(IWM_FH_SRVC_LOWER_BOUND + ((_chnl) - 9) * 0x4)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TX_CHICKEN_BITS_REG
value|(IWM_FH_MEM_LOWER_BOUND + 0xE98)
end_define

begin_define
define|#
directive|define
name|IWM_FH_TX_TRB_REG
parameter_list|(
name|_chan
parameter_list|)
value|(IWM_FH_MEM_LOWER_BOUND + 0x958 + \ 					(_chan) * 4)
end_define

begin_comment
comment|/* Instruct FH to increment the retry count of a packet when  * it is brought from the memory to TX-FIFO  */
end_comment

begin_define
define|#
directive|define
name|IWM_FH_TX_CHICKEN_BITS_SCD_AUTO_RETRY_EN
value|(0x00000002)
end_define

begin_define
define|#
directive|define
name|IWM_RX_QUEUE_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|IWM_RX_QUEUE_MASK
value|255
end_define

begin_define
define|#
directive|define
name|IWM_RX_QUEUE_SIZE_LOG
value|8
end_define

begin_comment
comment|/*  * RX related structures and functions  */
end_comment

begin_define
define|#
directive|define
name|IWM_RX_FREE_BUFFERS
value|64
end_define

begin_define
define|#
directive|define
name|IWM_RX_LOW_WATERMARK
value|8
end_define

begin_comment
comment|/**  * struct iwm_rb_status - reseve buffer status  * 	host memory mapped FH registers  * @closed_rb_num [0:11] - Indicates the index of the RB which was closed  * @closed_fr_num [0:11] - Indicates the index of the RX Frame which was closed  * @finished_rb_num [0:11] - Indicates the index of the current RB  * 	in which the last frame was written to  * @finished_fr_num [0:11] - Indicates the index of the RX Frame  * 	which was transferred  */
end_comment

begin_struct
struct|struct
name|iwm_rb_status
block|{
name|uint16_t
name|closed_rb_num
decl_stmt|;
name|uint16_t
name|closed_fr_num
decl_stmt|;
name|uint16_t
name|finished_rb_num
decl_stmt|;
name|uint16_t
name|finished_fr_nam
decl_stmt|;
name|uint32_t
name|unused
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWM_TFD_QUEUE_SIZE_MAX
value|(256)
end_define

begin_define
define|#
directive|define
name|IWM_TFD_QUEUE_SIZE_BC_DUP
value|(64)
end_define

begin_define
define|#
directive|define
name|IWM_TFD_QUEUE_BC_SIZE
value|(IWM_TFD_QUEUE_SIZE_MAX + \ 					IWM_TFD_QUEUE_SIZE_BC_DUP)
end_define

begin_define
define|#
directive|define
name|IWM_TX_DMA_MASK
value|DMA_BIT_MASK(36)
end_define

begin_define
define|#
directive|define
name|IWM_NUM_OF_TBS
value|20
end_define

begin_function
specifier|static
specifier|inline
name|uint8_t
name|iwm_get_dma_hi_addr
parameter_list|(
name|bus_addr_t
name|addr
parameter_list|)
block|{
return|return
operator|(
sizeof|sizeof
argument_list|(
name|addr
argument_list|)
operator|>
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
condition|?
operator|(
name|addr
operator|>>
literal|16
operator|)
operator|>>
literal|16
else|:
literal|0
operator|)
operator|&
literal|0xF
return|;
block|}
end_function

begin_comment
comment|/**  * struct iwm_tfd_tb transmit buffer descriptor within transmit frame descriptor  *  * This structure contains dma address and length of transmission address  *  * @lo: low [31:0] portion of the dma address of TX buffer  * 	every even is unaligned on 16 bit boundary  * @hi_n_len 0-3 [35:32] portion of dma  *	     4-15 length of the tx buffer  */
end_comment

begin_struct
struct|struct
name|iwm_tfd_tb
block|{
name|uint32_t
name|lo
decl_stmt|;
name|uint16_t
name|hi_n_len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * struct iwm_tfd  *  * Transmit Frame Descriptor (TFD)  *  * @ __reserved1[3] reserved  * @ num_tbs 0-4 number of active tbs  *	     5   reserved  * 	     6-7 padding (not used)  * @ tbs[20]	transmit frame buffer descriptors  * @ __pad 	padding  *  * Each Tx queue uses a circular buffer of 256 TFDs stored in host DRAM.  * Both driver and device share these circular buffers, each of which must be  * contiguous 256 TFDs x 128 bytes-per-TFD = 32 KBytes  *  * Driver must indicate the physical address of the base of each  * circular buffer via the IWM_FH_MEM_CBBC_QUEUE registers.  *  * Each TFD contains pointer/size information for up to 20 data buffers  * in host DRAM.  These buffers collectively contain the (one) frame described  * by the TFD.  Each buffer must be a single contiguous block of memory within  * itself, but buffers may be scattered in host DRAM.  Each buffer has max size  * of (4K - 4).  The concatenates all of a TFD's buffers into a single  * Tx frame, up to 8 KBytes in size.  *  * A maximum of 255 (not 256!) TFDs may be on a queue waiting for Tx.  */
end_comment

begin_struct
struct|struct
name|iwm_tfd
block|{
name|uint8_t
name|__reserved1
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|num_tbs
decl_stmt|;
name|struct
name|iwm_tfd_tb
name|tbs
index|[
name|IWM_NUM_OF_TBS
index|]
decl_stmt|;
name|uint32_t
name|__pad
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Keep Warm Size */
end_comment

begin_define
define|#
directive|define
name|IWM_KW_SIZE
value|0x1000
end_define

begin_comment
comment|/* 4k */
end_comment

begin_comment
comment|/* Fixed (non-configurable) rx data from phy */
end_comment

begin_comment
comment|/**  * struct iwm_agn_schedq_bc_tbl scheduler byte count table  *	base physical address provided by IWM_SCD_DRAM_BASE_ADDR  * @tfd_offset  0-12 - tx command byte count  *	       12-16 - station index  */
end_comment

begin_struct
struct|struct
name|iwm_agn_scd_bc_tbl
block|{
name|uint16_t
name|tfd_offset
index|[
name|IWM_TFD_QUEUE_BC_SIZE
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * END iwl-fh.h  */
end_comment

begin_comment
comment|/*  * BEGIN mvm/fw-api.h  */
end_comment

begin_comment
comment|/* Maximum number of Tx queues. */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_MAX_QUEUES
value|31
end_define

begin_comment
comment|/* Tx queue numbers */
end_comment

begin_enum
enum|enum
block|{
name|IWM_MVM_OFFCHANNEL_QUEUE
init|=
literal|8
block|,
name|IWM_MVM_CMD_QUEUE
init|=
literal|9
block|,
name|IWM_MVM_AUX_QUEUE
init|=
literal|15
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|iwm_mvm_tx_fifo
block|{
name|IWM_MVM_TX_FIFO_BK
init|=
literal|0
block|,
name|IWM_MVM_TX_FIFO_BE
block|,
name|IWM_MVM_TX_FIFO_VI
block|,
name|IWM_MVM_TX_FIFO_VO
block|,
name|IWM_MVM_TX_FIFO_MCAST
init|=
literal|5
block|,
name|IWM_MVM_TX_FIFO_CMD
init|=
literal|7
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_MVM_STATION_COUNT
value|16
end_define

begin_comment
comment|/* commands */
end_comment

begin_enum
enum|enum
block|{
name|IWM_MVM_ALIVE
init|=
literal|0x1
block|,
name|IWM_REPLY_ERROR
init|=
literal|0x2
block|,
name|IWM_INIT_COMPLETE_NOTIF
init|=
literal|0x4
block|,
comment|/* PHY context commands */
name|IWM_PHY_CONTEXT_CMD
init|=
literal|0x8
block|,
name|IWM_DBG_CFG
init|=
literal|0x9
block|,
comment|/* UMAC scan commands */
name|IWM_SCAN_ITERATION_COMPLETE_UMAC
init|=
literal|0xb5
block|,
name|IWM_SCAN_CFG_CMD
init|=
literal|0xc
block|,
name|IWM_SCAN_REQ_UMAC
init|=
literal|0xd
block|,
name|IWM_SCAN_ABORT_UMAC
init|=
literal|0xe
block|,
name|IWM_SCAN_COMPLETE_UMAC
init|=
literal|0xf
block|,
comment|/* station table */
name|IWM_ADD_STA_KEY
init|=
literal|0x17
block|,
name|IWM_ADD_STA
init|=
literal|0x18
block|,
name|IWM_REMOVE_STA
init|=
literal|0x19
block|,
comment|/* TX */
name|IWM_TX_CMD
init|=
literal|0x1c
block|,
name|IWM_TXPATH_FLUSH
init|=
literal|0x1e
block|,
name|IWM_MGMT_MCAST_KEY
init|=
literal|0x1f
block|,
comment|/* scheduler config */
name|IWM_SCD_QUEUE_CFG
init|=
literal|0x1d
block|,
comment|/* global key */
name|IWM_WEP_KEY
init|=
literal|0x20
block|,
comment|/* MAC and Binding commands */
name|IWM_MAC_CONTEXT_CMD
init|=
literal|0x28
block|,
name|IWM_TIME_EVENT_CMD
init|=
literal|0x29
block|,
comment|/* both CMD and response */
name|IWM_TIME_EVENT_NOTIFICATION
init|=
literal|0x2a
block|,
name|IWM_BINDING_CONTEXT_CMD
init|=
literal|0x2b
block|,
name|IWM_TIME_QUOTA_CMD
init|=
literal|0x2c
block|,
name|IWM_NON_QOS_TX_COUNTER_CMD
init|=
literal|0x2d
block|,
name|IWM_LQ_CMD
init|=
literal|0x4e
block|,
comment|/* paging block to FW cpu2 */
name|IWM_FW_PAGING_BLOCK_CMD
init|=
literal|0x4f
block|,
comment|/* Scan offload */
name|IWM_SCAN_OFFLOAD_REQUEST_CMD
init|=
literal|0x51
block|,
name|IWM_SCAN_OFFLOAD_ABORT_CMD
init|=
literal|0x52
block|,
name|IWM_HOT_SPOT_CMD
init|=
literal|0x53
block|,
name|IWM_SCAN_OFFLOAD_COMPLETE
init|=
literal|0x6d
block|,
name|IWM_SCAN_OFFLOAD_UPDATE_PROFILES_CMD
init|=
literal|0x6e
block|,
name|IWM_SCAN_OFFLOAD_CONFIG_CMD
init|=
literal|0x6f
block|,
name|IWM_MATCH_FOUND_NOTIFICATION
init|=
literal|0xd9
block|,
name|IWM_SCAN_ITERATION_COMPLETE
init|=
literal|0xe7
block|,
comment|/* Phy */
name|IWM_PHY_CONFIGURATION_CMD
init|=
literal|0x6a
block|,
name|IWM_CALIB_RES_NOTIF_PHY_DB
init|=
literal|0x6b
block|,
name|IWM_PHY_DB_CMD
init|=
literal|0x6c
block|,
comment|/* Power - legacy power table command */
name|IWM_POWER_TABLE_CMD
init|=
literal|0x77
block|,
name|IWM_PSM_UAPSD_AP_MISBEHAVING_NOTIFICATION
init|=
literal|0x78
block|,
comment|/* Thermal Throttling*/
name|IWM_REPLY_THERMAL_MNG_BACKOFF
init|=
literal|0x7e
block|,
comment|/* Scanning */
name|IWM_SCAN_ABORT_CMD
init|=
literal|0x81
block|,
name|IWM_SCAN_START_NOTIFICATION
init|=
literal|0x82
block|,
name|IWM_SCAN_RESULTS_NOTIFICATION
init|=
literal|0x83
block|,
comment|/* NVM */
name|IWM_NVM_ACCESS_CMD
init|=
literal|0x88
block|,
name|IWM_SET_CALIB_DEFAULT_CMD
init|=
literal|0x8e
block|,
name|IWM_BEACON_NOTIFICATION
init|=
literal|0x90
block|,
name|IWM_BEACON_TEMPLATE_CMD
init|=
literal|0x91
block|,
name|IWM_TX_ANT_CONFIGURATION_CMD
init|=
literal|0x98
block|,
name|IWM_BT_CONFIG
init|=
literal|0x9b
block|,
name|IWM_STATISTICS_NOTIFICATION
init|=
literal|0x9d
block|,
name|IWM_REDUCE_TX_POWER_CMD
init|=
literal|0x9f
block|,
comment|/* RF-KILL commands and notifications */
name|IWM_CARD_STATE_CMD
init|=
literal|0xa0
block|,
name|IWM_CARD_STATE_NOTIFICATION
init|=
literal|0xa1
block|,
name|IWM_MISSED_BEACONS_NOTIFICATION
init|=
literal|0xa2
block|,
name|IWM_MFUART_LOAD_NOTIFICATION
init|=
literal|0xb1
block|,
comment|/* Power - new power table command */
name|IWM_MAC_PM_POWER_TABLE
init|=
literal|0xa9
block|,
name|IWM_REPLY_RX_PHY_CMD
init|=
literal|0xc0
block|,
name|IWM_REPLY_RX_MPDU_CMD
init|=
literal|0xc1
block|,
name|IWM_BA_NOTIF
init|=
literal|0xc5
block|,
comment|/* Location Aware Regulatory */
name|IWM_MCC_UPDATE_CMD
init|=
literal|0xc8
block|,
name|IWM_MCC_CHUB_UPDATE_CMD
init|=
literal|0xc9
block|,
comment|/* BT Coex */
name|IWM_BT_COEX_PRIO_TABLE
init|=
literal|0xcc
block|,
name|IWM_BT_COEX_PROT_ENV
init|=
literal|0xcd
block|,
name|IWM_BT_PROFILE_NOTIFICATION
init|=
literal|0xce
block|,
name|IWM_BT_COEX_CI
init|=
literal|0x5d
block|,
name|IWM_REPLY_SF_CFG_CMD
init|=
literal|0xd1
block|,
name|IWM_REPLY_BEACON_FILTERING_CMD
init|=
literal|0xd2
block|,
comment|/* DTS measurements */
name|IWM_CMD_DTS_MEASUREMENT_TRIGGER
init|=
literal|0xdc
block|,
name|IWM_DTS_MEASUREMENT_NOTIFICATION
init|=
literal|0xdd
block|,
name|IWM_REPLY_DEBUG_CMD
init|=
literal|0xf0
block|,
name|IWM_DEBUG_LOG_MSG
init|=
literal|0xf7
block|,
name|IWM_MCAST_FILTER_CMD
init|=
literal|0xd0
block|,
comment|/* D3 commands/notifications */
name|IWM_D3_CONFIG_CMD
init|=
literal|0xd3
block|,
name|IWM_PROT_OFFLOAD_CONFIG_CMD
init|=
literal|0xd4
block|,
name|IWM_OFFLOADS_QUERY_CMD
init|=
literal|0xd5
block|,
name|IWM_REMOTE_WAKE_CONFIG_CMD
init|=
literal|0xd6
block|,
comment|/* for WoWLAN in particular */
name|IWM_WOWLAN_PATTERNS
init|=
literal|0xe0
block|,
name|IWM_WOWLAN_CONFIGURATION
init|=
literal|0xe1
block|,
name|IWM_WOWLAN_TSC_RSC_PARAM
init|=
literal|0xe2
block|,
name|IWM_WOWLAN_TKIP_PARAM
init|=
literal|0xe3
block|,
name|IWM_WOWLAN_KEK_KCK_MATERIAL
init|=
literal|0xe4
block|,
name|IWM_WOWLAN_GET_STATUSES
init|=
literal|0xe5
block|,
name|IWM_WOWLAN_TX_POWER_PER_DB
init|=
literal|0xe6
block|,
comment|/* and for NetDetect */
name|IWM_NET_DETECT_CONFIG_CMD
init|=
literal|0x54
block|,
name|IWM_NET_DETECT_PROFILES_QUERY_CMD
init|=
literal|0x56
block|,
name|IWM_NET_DETECT_PROFILES_CMD
init|=
literal|0x57
block|,
name|IWM_NET_DETECT_HOTSPOTS_CMD
init|=
literal|0x58
block|,
name|IWM_NET_DETECT_HOTSPOTS_QUERY_CMD
init|=
literal|0x59
block|,
name|IWM_REPLY_MAX
init|=
literal|0xff
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|iwm_phy_ops_subcmd_ids
block|{
name|IWM_CMD_DTS_MEASUREMENT_TRIGGER_WIDE
init|=
literal|0x0
block|,
name|IWM_CTDP_CONFIG_CMD
init|=
literal|0x03
block|,
name|IWM_TEMP_REPORTING_THRESHOLDS_CMD
init|=
literal|0x04
block|,
name|IWM_CT_KILL_NOTIFICATION
init|=
literal|0xFE
block|,
name|IWM_DTS_MEASUREMENT_NOTIF_WIDE
init|=
literal|0xFF
block|, }
enum|;
end_enum

begin_comment
comment|/* command groups */
end_comment

begin_enum
enum|enum
block|{
name|IWM_LEGACY_GROUP
init|=
literal|0x0
block|,
name|IWM_LONG_GROUP
init|=
literal|0x1
block|,
name|IWM_SYSTEM_GROUP
init|=
literal|0x2
block|,
name|IWM_MAC_CONF_GROUP
init|=
literal|0x3
block|,
name|IWM_PHY_OPS_GROUP
init|=
literal|0x4
block|,
name|IWM_DATA_PATH_GROUP
init|=
literal|0x5
block|,
name|IWM_PROT_OFFLOAD_GROUP
init|=
literal|0xb
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_cmd_response - generic response struct for most commands  * @status: status of the command asked, changes for each one  */
end_comment

begin_struct
struct|struct
name|iwm_cmd_response
block|{
name|uint32_t
name|status
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * struct iwm_tx_ant_cfg_cmd  * @valid: valid antenna configuration  */
end_comment

begin_struct
struct|struct
name|iwm_tx_ant_cfg_cmd
block|{
name|uint32_t
name|valid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * struct iwm_reduce_tx_power_cmd - TX power reduction command  * IWM_REDUCE_TX_POWER_CMD = 0x9f  * @flags: (reserved for future implementation)  * @mac_context_id: id of the mac ctx for which we are reducing TX power.  * @pwr_restriction: TX power restriction in dBms.  */
end_comment

begin_struct
struct|struct
name|iwm_reduce_tx_power_cmd
block|{
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|mac_context_id
decl_stmt|;
name|uint16_t
name|pwr_restriction
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_TX_REDUCED_POWER_API_S_VER_1 */
end_comment

begin_comment
comment|/*  * Calibration control struct.  * Sent as part of the phy configuration command.  * @flow_trigger: bitmap for which calibrations to perform according to  *		flow triggers.  * @event_trigger: bitmap for which calibrations to perform according to  *		event triggers.  */
end_comment

begin_struct
struct|struct
name|iwm_calib_ctrl
block|{
name|uint32_t
name|flow_trigger
decl_stmt|;
name|uint32_t
name|event_trigger
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* This enum defines the bitmap of various calibrations to enable in both  * init ucode and runtime ucode through IWM_CALIBRATION_CFG_CMD.  */
end_comment

begin_enum
enum|enum
name|iwm_calib_cfg
block|{
name|IWM_CALIB_CFG_XTAL_IDX
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_CALIB_CFG_TEMPERATURE_IDX
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_CALIB_CFG_VOLTAGE_READ_IDX
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_CALIB_CFG_PAPD_IDX
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_CALIB_CFG_TX_PWR_IDX
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|IWM_CALIB_CFG_DC_IDX
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|IWM_CALIB_CFG_BB_FILTER_IDX
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|IWM_CALIB_CFG_LO_LEAKAGE_IDX
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
name|IWM_CALIB_CFG_TX_IQ_IDX
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
name|IWM_CALIB_CFG_TX_IQ_SKEW_IDX
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
name|IWM_CALIB_CFG_RX_IQ_IDX
init|=
operator|(
literal|1
operator|<<
literal|10
operator|)
block|,
name|IWM_CALIB_CFG_RX_IQ_SKEW_IDX
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|,
name|IWM_CALIB_CFG_SENSITIVITY_IDX
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|,
name|IWM_CALIB_CFG_CHAIN_NOISE_IDX
init|=
operator|(
literal|1
operator|<<
literal|13
operator|)
block|,
name|IWM_CALIB_CFG_DISCONNECTED_ANT_IDX
init|=
operator|(
literal|1
operator|<<
literal|14
operator|)
block|,
name|IWM_CALIB_CFG_ANT_COUPLING_IDX
init|=
operator|(
literal|1
operator|<<
literal|15
operator|)
block|,
name|IWM_CALIB_CFG_DAC_IDX
init|=
operator|(
literal|1
operator|<<
literal|16
operator|)
block|,
name|IWM_CALIB_CFG_ABS_IDX
init|=
operator|(
literal|1
operator|<<
literal|17
operator|)
block|,
name|IWM_CALIB_CFG_AGC_IDX
init|=
operator|(
literal|1
operator|<<
literal|18
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Phy configuration command.  */
end_comment

begin_struct
struct|struct
name|iwm_phy_cfg_cmd
block|{
name|uint32_t
name|phy_cfg
decl_stmt|;
name|struct
name|iwm_calib_ctrl
name|calib_control
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWM_PHY_CFG_RADIO_TYPE
value|((1<< 0) | (1<< 1))
end_define

begin_define
define|#
directive|define
name|IWM_PHY_CFG_RADIO_STEP
value|((1<< 2) | (1<< 3))
end_define

begin_define
define|#
directive|define
name|IWM_PHY_CFG_RADIO_DASH
value|((1<< 4) | (1<< 5))
end_define

begin_define
define|#
directive|define
name|IWM_PHY_CFG_PRODUCT_NUMBER
value|((1<< 6) | (1<< 7))
end_define

begin_define
define|#
directive|define
name|IWM_PHY_CFG_TX_CHAIN_A
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_CFG_TX_CHAIN_B
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_CFG_TX_CHAIN_C
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_CFG_RX_CHAIN_A
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_CFG_RX_CHAIN_B
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_CFG_RX_CHAIN_C
value|(1<< 14)
end_define

begin_comment
comment|/* Target of the IWM_NVM_ACCESS_CMD */
end_comment

begin_enum
enum|enum
block|{
name|IWM_NVM_ACCESS_TARGET_CACHE
init|=
literal|0
block|,
name|IWM_NVM_ACCESS_TARGET_OTP
init|=
literal|1
block|,
name|IWM_NVM_ACCESS_TARGET_EEPROM
init|=
literal|2
block|, }
enum|;
end_enum

begin_comment
comment|/* Section types for IWM_NVM_ACCESS_CMD */
end_comment

begin_enum
enum|enum
block|{
name|IWM_NVM_SECTION_TYPE_SW
init|=
literal|1
block|,
name|IWM_NVM_SECTION_TYPE_REGULATORY
init|=
literal|3
block|,
name|IWM_NVM_SECTION_TYPE_CALIBRATION
init|=
literal|4
block|,
name|IWM_NVM_SECTION_TYPE_PRODUCTION
init|=
literal|5
block|,
name|IWM_NVM_SECTION_TYPE_MAC_OVERRIDE
init|=
literal|11
block|,
name|IWM_NVM_SECTION_TYPE_PHY_SKU
init|=
literal|12
block|,
name|IWM_NVM_MAX_NUM_SECTIONS
init|=
literal|13
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_nvm_access_cmd_ver2 - Request the device to send an NVM section  * @op_code: 0 - read, 1 - write  * @target: IWM_NVM_ACCESS_TARGET_*  * @type: IWM_NVM_SECTION_TYPE_*  * @offset: offset in bytes into the section  * @length: in bytes, to read/write  * @data: if write operation, the data to write. On read its empty  */
end_comment

begin_struct
struct|struct
name|iwm_nvm_access_cmd
block|{
name|uint8_t
name|op_code
decl_stmt|;
name|uint8_t
name|target
decl_stmt|;
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|offset
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint8_t
name|data
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_NVM_ACCESS_CMD_API_S_VER_2 */
end_comment

begin_define
define|#
directive|define
name|IWM_NUM_OF_FW_PAGING_BLOCKS
value|33
end_define

begin_comment
comment|/* 32 for data and 1 block for CSS */
end_comment

begin_comment
comment|/*  * struct iwm_fw_paging_cmd - paging layout  *  * (IWM_FW_PAGING_BLOCK_CMD = 0x4f)  *  * Send to FW the paging layout in the driver.  *  * @flags: various flags for the command  * @block_size: the block size in powers of 2  * @block_num: number of blocks specified in the command.  * @device_phy_addr: virtual addresses from device side */
end_comment

begin_struct
struct|struct
name|iwm_fw_paging_cmd
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|block_size
decl_stmt|;
name|uint32_t
name|block_num
decl_stmt|;
name|uint32_t
name|device_phy_addr
index|[
name|IWM_NUM_OF_FW_PAGING_BLOCKS
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_FW_PAGING_BLOCK_CMD_API_S_VER_1 */
end_comment

begin_comment
comment|/*  * Fw items ID's  *  * @IWM_FW_ITEM_ID_PAGING: Address of the pages that the FW will upload  *      download  */
end_comment

begin_enum
enum|enum
name|iwm_fw_item_id
block|{
name|IWM_FW_ITEM_ID_PAGING
init|=
literal|3
block|, }
enum|;
end_enum

begin_comment
comment|/*  * struct iwm_fw_get_item_cmd - get an item from the fw  */
end_comment

begin_struct
struct|struct
name|iwm_fw_get_item_cmd
block|{
name|uint32_t
name|item_id
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_FW_GET_ITEM_CMD_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_nvm_access_resp_ver2 - response to IWM_NVM_ACCESS_CMD  * @offset: offset in bytes into the section  * @length: in bytes, either how much was written or read  * @type: IWM_NVM_SECTION_TYPE_*  * @status: 0 for success, fail otherwise  * @data: if read operation, the data returned. Empty on write.  */
end_comment

begin_struct
struct|struct
name|iwm_nvm_access_resp
block|{
name|uint16_t
name|offset
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint16_t
name|type
decl_stmt|;
name|uint16_t
name|status
decl_stmt|;
name|uint8_t
name|data
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_NVM_ACCESS_CMD_RESP_API_S_VER_2 */
end_comment

begin_comment
comment|/* IWM_MVM_ALIVE 0x1 */
end_comment

begin_comment
comment|/* alive response is_valid values */
end_comment

begin_define
define|#
directive|define
name|IWM_ALIVE_RESP_UCODE_OK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWM_ALIVE_RESP_RFKILL
value|(1<< 1)
end_define

begin_comment
comment|/* alive response ver_type values */
end_comment

begin_enum
enum|enum
block|{
name|IWM_FW_TYPE_HW
init|=
literal|0
block|,
name|IWM_FW_TYPE_PROT
init|=
literal|1
block|,
name|IWM_FW_TYPE_AP
init|=
literal|2
block|,
name|IWM_FW_TYPE_WOWLAN
init|=
literal|3
block|,
name|IWM_FW_TYPE_TIMING
init|=
literal|4
block|,
name|IWM_FW_TYPE_WIPAN
init|=
literal|5
block|}
enum|;
end_enum

begin_comment
comment|/* alive response ver_subtype values */
end_comment

begin_enum
enum|enum
block|{
name|IWM_FW_SUBTYPE_FULL_FEATURE
init|=
literal|0
block|,
name|IWM_FW_SUBTYPE_BOOTSRAP
init|=
literal|1
block|,
comment|/* Not valid */
name|IWM_FW_SUBTYPE_REDUCED
init|=
literal|2
block|,
name|IWM_FW_SUBTYPE_ALIVE_ONLY
init|=
literal|3
block|,
name|IWM_FW_SUBTYPE_WOWLAN
init|=
literal|4
block|,
name|IWM_FW_SUBTYPE_AP_SUBTYPE
init|=
literal|5
block|,
name|IWM_FW_SUBTYPE_WIPAN
init|=
literal|6
block|,
name|IWM_FW_SUBTYPE_INITIALIZE
init|=
literal|9
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_ALIVE_STATUS_ERR
value|0xDEAD
end_define

begin_define
define|#
directive|define
name|IWM_ALIVE_STATUS_OK
value|0xCAFE
end_define

begin_define
define|#
directive|define
name|IWM_ALIVE_FLG_RFKILL
value|(1<< 0)
end_define

begin_struct
struct|struct
name|iwm_mvm_alive_resp_ver1
block|{
name|uint16_t
name|status
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
name|uint8_t
name|ucode_minor
decl_stmt|;
name|uint8_t
name|ucode_major
decl_stmt|;
name|uint16_t
name|id
decl_stmt|;
name|uint8_t
name|api_minor
decl_stmt|;
name|uint8_t
name|api_major
decl_stmt|;
name|uint8_t
name|ver_subtype
decl_stmt|;
name|uint8_t
name|ver_type
decl_stmt|;
name|uint8_t
name|mac
decl_stmt|;
name|uint8_t
name|opt
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint32_t
name|timestamp
decl_stmt|;
name|uint32_t
name|error_event_table_ptr
decl_stmt|;
comment|/* SRAM address for error log */
name|uint32_t
name|log_event_table_ptr
decl_stmt|;
comment|/* SRAM address for event log */
name|uint32_t
name|cpu_register_ptr
decl_stmt|;
name|uint32_t
name|dbgm_config_ptr
decl_stmt|;
name|uint32_t
name|alive_counter_ptr
decl_stmt|;
name|uint32_t
name|scd_base_ptr
decl_stmt|;
comment|/* SRAM address for SCD */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_ALIVE_RES_API_S_VER_1 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_alive_resp_ver2
block|{
name|uint16_t
name|status
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
name|uint8_t
name|ucode_minor
decl_stmt|;
name|uint8_t
name|ucode_major
decl_stmt|;
name|uint16_t
name|id
decl_stmt|;
name|uint8_t
name|api_minor
decl_stmt|;
name|uint8_t
name|api_major
decl_stmt|;
name|uint8_t
name|ver_subtype
decl_stmt|;
name|uint8_t
name|ver_type
decl_stmt|;
name|uint8_t
name|mac
decl_stmt|;
name|uint8_t
name|opt
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint32_t
name|timestamp
decl_stmt|;
name|uint32_t
name|error_event_table_ptr
decl_stmt|;
comment|/* SRAM address for error log */
name|uint32_t
name|log_event_table_ptr
decl_stmt|;
comment|/* SRAM address for LMAC event log */
name|uint32_t
name|cpu_register_ptr
decl_stmt|;
name|uint32_t
name|dbgm_config_ptr
decl_stmt|;
name|uint32_t
name|alive_counter_ptr
decl_stmt|;
name|uint32_t
name|scd_base_ptr
decl_stmt|;
comment|/* SRAM address for SCD */
name|uint32_t
name|st_fwrd_addr
decl_stmt|;
comment|/* pointer to Store and forward */
name|uint32_t
name|st_fwrd_size
decl_stmt|;
name|uint8_t
name|umac_minor
decl_stmt|;
comment|/* UMAC version: minor */
name|uint8_t
name|umac_major
decl_stmt|;
comment|/* UMAC version: major */
name|uint16_t
name|umac_id
decl_stmt|;
comment|/* UMAC version: id */
name|uint32_t
name|error_info_addr
decl_stmt|;
comment|/* SRAM address for UMAC error log */
name|uint32_t
name|dbg_print_buff_addr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* ALIVE_RES_API_S_VER_2 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_alive_resp
block|{
name|uint16_t
name|status
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
name|uint32_t
name|ucode_minor
decl_stmt|;
name|uint32_t
name|ucode_major
decl_stmt|;
name|uint8_t
name|ver_subtype
decl_stmt|;
name|uint8_t
name|ver_type
decl_stmt|;
name|uint8_t
name|mac
decl_stmt|;
name|uint8_t
name|opt
decl_stmt|;
name|uint32_t
name|timestamp
decl_stmt|;
name|uint32_t
name|error_event_table_ptr
decl_stmt|;
comment|/* SRAM address for error log */
name|uint32_t
name|log_event_table_ptr
decl_stmt|;
comment|/* SRAM address for LMAC event log */
name|uint32_t
name|cpu_register_ptr
decl_stmt|;
name|uint32_t
name|dbgm_config_ptr
decl_stmt|;
name|uint32_t
name|alive_counter_ptr
decl_stmt|;
name|uint32_t
name|scd_base_ptr
decl_stmt|;
comment|/* SRAM address for SCD */
name|uint32_t
name|st_fwrd_addr
decl_stmt|;
comment|/* pointer to Store and forward */
name|uint32_t
name|st_fwrd_size
decl_stmt|;
name|uint32_t
name|umac_minor
decl_stmt|;
comment|/* UMAC version: minor */
name|uint32_t
name|umac_major
decl_stmt|;
comment|/* UMAC version: major */
name|uint32_t
name|error_info_addr
decl_stmt|;
comment|/* SRAM address for UMAC error log */
name|uint32_t
name|dbg_print_buff_addr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* ALIVE_RES_API_S_VER_3 */
end_comment

begin_comment
comment|/* Error response/notification */
end_comment

begin_enum
enum|enum
block|{
name|IWM_FW_ERR_UNKNOWN_CMD
init|=
literal|0x0
block|,
name|IWM_FW_ERR_INVALID_CMD_PARAM
init|=
literal|0x1
block|,
name|IWM_FW_ERR_SERVICE
init|=
literal|0x2
block|,
name|IWM_FW_ERR_ARC_MEMORY
init|=
literal|0x3
block|,
name|IWM_FW_ERR_ARC_CODE
init|=
literal|0x4
block|,
name|IWM_FW_ERR_WATCH_DOG
init|=
literal|0x5
block|,
name|IWM_FW_ERR_WEP_GRP_KEY_INDX
init|=
literal|0x10
block|,
name|IWM_FW_ERR_WEP_KEY_SIZE
init|=
literal|0x11
block|,
name|IWM_FW_ERR_OBSOLETE_FUNC
init|=
literal|0x12
block|,
name|IWM_FW_ERR_UNEXPECTED
init|=
literal|0xFE
block|,
name|IWM_FW_ERR_FATAL
init|=
literal|0xFF
block|}
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_error_resp - FW error indication  * ( IWM_REPLY_ERROR = 0x2 )  * @error_type: one of IWM_FW_ERR_*  * @cmd_id: the command ID for which the error occurred  * @bad_cmd_seq_num: sequence number of the erroneous command  * @error_service: which service created the error, applicable only if  *	error_type = 2, otherwise 0  * @timestamp: TSF in usecs.  */
end_comment

begin_struct
struct|struct
name|iwm_error_resp
block|{
name|uint32_t
name|error_type
decl_stmt|;
name|uint8_t
name|cmd_id
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint16_t
name|bad_cmd_seq_num
decl_stmt|;
name|uint32_t
name|error_service
decl_stmt|;
name|uint64_t
name|timestamp
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Common PHY, MAC and Bindings definitions */
end_comment

begin_define
define|#
directive|define
name|IWM_MAX_MACS_IN_BINDING
value|(3)
end_define

begin_define
define|#
directive|define
name|IWM_MAX_BINDINGS
value|(4)
end_define

begin_define
define|#
directive|define
name|IWM_AUX_BINDING_INDEX
value|(3)
end_define

begin_define
define|#
directive|define
name|IWM_MAX_PHYS
value|(4)
end_define

begin_comment
comment|/* Used to extract ID and color from the context dword */
end_comment

begin_define
define|#
directive|define
name|IWM_FW_CTXT_ID_POS
value|(0)
end_define

begin_define
define|#
directive|define
name|IWM_FW_CTXT_ID_MSK
value|(0xff<< IWM_FW_CTXT_ID_POS)
end_define

begin_define
define|#
directive|define
name|IWM_FW_CTXT_COLOR_POS
value|(8)
end_define

begin_define
define|#
directive|define
name|IWM_FW_CTXT_COLOR_MSK
value|(0xff<< IWM_FW_CTXT_COLOR_POS)
end_define

begin_define
define|#
directive|define
name|IWM_FW_CTXT_INVALID
value|(0xffffffff)
end_define

begin_define
define|#
directive|define
name|IWM_FW_CMD_ID_AND_COLOR
parameter_list|(
name|_id
parameter_list|,
name|_color
parameter_list|)
value|((_id<< IWM_FW_CTXT_ID_POS) |\ 					  (_color<< IWM_FW_CTXT_COLOR_POS))
end_define

begin_comment
comment|/* Possible actions on PHYs, MACs and Bindings */
end_comment

begin_enum
enum|enum
block|{
name|IWM_FW_CTXT_ACTION_STUB
init|=
literal|0
block|,
name|IWM_FW_CTXT_ACTION_ADD
block|,
name|IWM_FW_CTXT_ACTION_MODIFY
block|,
name|IWM_FW_CTXT_ACTION_REMOVE
block|,
name|IWM_FW_CTXT_ACTION_NUM
block|}
enum|;
end_enum

begin_comment
comment|/* COMMON_CONTEXT_ACTION_API_E_VER_1 */
end_comment

begin_comment
comment|/* Time Events */
end_comment

begin_comment
comment|/* Time Event types, according to MAC type */
end_comment

begin_enum
enum|enum
name|iwm_time_event_type
block|{
comment|/* BSS Station Events */
name|IWM_TE_BSS_STA_AGGRESSIVE_ASSOC
block|,
name|IWM_TE_BSS_STA_ASSOC
block|,
name|IWM_TE_BSS_EAP_DHCP_PROT
block|,
name|IWM_TE_BSS_QUIET_PERIOD
block|,
comment|/* P2P Device Events */
name|IWM_TE_P2P_DEVICE_DISCOVERABLE
block|,
name|IWM_TE_P2P_DEVICE_LISTEN
block|,
name|IWM_TE_P2P_DEVICE_ACTION_SCAN
block|,
name|IWM_TE_P2P_DEVICE_FULL_SCAN
block|,
comment|/* P2P Client Events */
name|IWM_TE_P2P_CLIENT_AGGRESSIVE_ASSOC
block|,
name|IWM_TE_P2P_CLIENT_ASSOC
block|,
name|IWM_TE_P2P_CLIENT_QUIET_PERIOD
block|,
comment|/* P2P GO Events */
name|IWM_TE_P2P_GO_ASSOC_PROT
block|,
name|IWM_TE_P2P_GO_REPETITIVE_NOA
block|,
name|IWM_TE_P2P_GO_CT_WINDOW
block|,
comment|/* WiDi Sync Events */
name|IWM_TE_WIDI_TX_SYNC
block|,
name|IWM_TE_MAX
block|}
enum|;
end_enum

begin_comment
comment|/* IWM_MAC_EVENT_TYPE_API_E_VER_1 */
end_comment

begin_comment
comment|/* Time event - defines for command API v1 */
end_comment

begin_comment
comment|/*  * @IWM_TE_V1_FRAG_NONE: fragmentation of the time event is NOT allowed.  * @IWM_TE_V1_FRAG_SINGLE: fragmentation of the time event is allowed, but only  *	the first fragment is scheduled.  * @IWM_TE_V1_FRAG_DUAL: fragmentation of the time event is allowed, but only  *	the first 2 fragments are scheduled.  * @IWM_TE_V1_FRAG_ENDLESS: fragmentation of the time event is allowed, and any  *	number of fragments are valid.  *  * Other than the constant defined above, specifying a fragmentation value 'x'  * means that the event can be fragmented but only the first 'x' will be  * scheduled.  */
end_comment

begin_enum
enum|enum
block|{
name|IWM_TE_V1_FRAG_NONE
init|=
literal|0
block|,
name|IWM_TE_V1_FRAG_SINGLE
init|=
literal|1
block|,
name|IWM_TE_V1_FRAG_DUAL
init|=
literal|2
block|,
name|IWM_TE_V1_FRAG_ENDLESS
init|=
literal|0xffffffff
block|}
enum|;
end_enum

begin_comment
comment|/* If a Time Event can be fragmented, this is the max number of fragments */
end_comment

begin_define
define|#
directive|define
name|IWM_TE_V1_FRAG_MAX_MSK
value|0x0fffffff
end_define

begin_comment
comment|/* Repeat the time event endlessly (until removed) */
end_comment

begin_define
define|#
directive|define
name|IWM_TE_V1_REPEAT_ENDLESS
value|0xffffffff
end_define

begin_comment
comment|/* If a Time Event has bounded repetitions, this is the maximal value */
end_comment

begin_define
define|#
directive|define
name|IWM_TE_V1_REPEAT_MAX_MSK_V1
value|0x0fffffff
end_define

begin_comment
comment|/* Time Event dependencies: none, on another TE, or in a specific time */
end_comment

begin_enum
enum|enum
block|{
name|IWM_TE_V1_INDEPENDENT
init|=
literal|0
block|,
name|IWM_TE_V1_DEP_OTHER
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_TE_V1_DEP_TSF
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_TE_V1_EVENT_SOCIOPATHIC
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/* IWM_MAC_EVENT_DEPENDENCY_POLICY_API_E_VER_2 */
end_comment

begin_comment
comment|/*  * @IWM_TE_V1_NOTIF_NONE: no notifications  * @IWM_TE_V1_NOTIF_HOST_EVENT_START: request/receive notification on event start  * @IWM_TE_V1_NOTIF_HOST_EVENT_END:request/receive notification on event end  * @IWM_TE_V1_NOTIF_INTERNAL_EVENT_START: internal FW use  * @IWM_TE_V1_NOTIF_INTERNAL_EVENT_END: internal FW use.  * @IWM_TE_V1_NOTIF_HOST_FRAG_START: request/receive notification on frag start  * @IWM_TE_V1_NOTIF_HOST_FRAG_END:request/receive notification on frag end  * @IWM_TE_V1_NOTIF_INTERNAL_FRAG_START: internal FW use.  * @IWM_TE_V1_NOTIF_INTERNAL_FRAG_END: internal FW use.  *  * Supported Time event notifications configuration.  * A notification (both event and fragment) includes a status indicating weather  * the FW was able to schedule the event or not. For fragment start/end  * notification the status is always success. There is no start/end fragment  * notification for monolithic events.  */
end_comment

begin_enum
enum|enum
block|{
name|IWM_TE_V1_NOTIF_NONE
init|=
literal|0
block|,
name|IWM_TE_V1_NOTIF_HOST_EVENT_START
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_TE_V1_NOTIF_HOST_EVENT_END
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_TE_V1_NOTIF_INTERNAL_EVENT_START
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_TE_V1_NOTIF_INTERNAL_EVENT_END
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_TE_V1_NOTIF_HOST_FRAG_START
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|IWM_TE_V1_NOTIF_HOST_FRAG_END
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|IWM_TE_V1_NOTIF_INTERNAL_FRAG_START
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|IWM_TE_V1_NOTIF_INTERNAL_FRAG_END
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
name|IWM_T2_V2_START_IMMEDIATELY
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/* IWM_MAC_EVENT_ACTION_API_E_VER_2 */
end_comment

begin_comment
comment|/* Time event - defines for command API */
end_comment

begin_comment
comment|/*  * @IWM_TE_V2_FRAG_NONE: fragmentation of the time event is NOT allowed.  * @IWM_TE_V2_FRAG_SINGLE: fragmentation of the time event is allowed, but only  *  the first fragment is scheduled.  * @IWM_TE_V2_FRAG_DUAL: fragmentation of the time event is allowed, but only  *  the first 2 fragments are scheduled.  * @IWM_TE_V2_FRAG_ENDLESS: fragmentation of the time event is allowed, and any  *  number of fragments are valid.  *  * Other than the constant defined above, specifying a fragmentation value 'x'  * means that the event can be fragmented but only the first 'x' will be  * scheduled.  */
end_comment

begin_enum
enum|enum
block|{
name|IWM_TE_V2_FRAG_NONE
init|=
literal|0
block|,
name|IWM_TE_V2_FRAG_SINGLE
init|=
literal|1
block|,
name|IWM_TE_V2_FRAG_DUAL
init|=
literal|2
block|,
name|IWM_TE_V2_FRAG_MAX
init|=
literal|0xfe
block|,
name|IWM_TE_V2_FRAG_ENDLESS
init|=
literal|0xff
block|}
enum|;
end_enum

begin_comment
comment|/* Repeat the time event endlessly (until removed) */
end_comment

begin_define
define|#
directive|define
name|IWM_TE_V2_REPEAT_ENDLESS
value|0xff
end_define

begin_comment
comment|/* If a Time Event has bounded repetitions, this is the maximal value */
end_comment

begin_define
define|#
directive|define
name|IWM_TE_V2_REPEAT_MAX
value|0xfe
end_define

begin_define
define|#
directive|define
name|IWM_TE_V2_PLACEMENT_POS
value|12
end_define

begin_define
define|#
directive|define
name|IWM_TE_V2_ABSENCE_POS
value|15
end_define

begin_comment
comment|/* Time event policy values  * A notification (both event and fragment) includes a status indicating weather  * the FW was able to schedule the event or not. For fragment start/end  * notification the status is always success. There is no start/end fragment  * notification for monolithic events.  *  * @IWM_TE_V2_DEFAULT_POLICY: independent, social, present, unoticable  * @IWM_TE_V2_NOTIF_HOST_EVENT_START: request/receive notification on event start  * @IWM_TE_V2_NOTIF_HOST_EVENT_END:request/receive notification on event end  * @IWM_TE_V2_NOTIF_INTERNAL_EVENT_START: internal FW use  * @IWM_TE_V2_NOTIF_INTERNAL_EVENT_END: internal FW use.  * @IWM_TE_V2_NOTIF_HOST_FRAG_START: request/receive notification on frag start  * @IWM_TE_V2_NOTIF_HOST_FRAG_END:request/receive notification on frag end  * @IWM_TE_V2_NOTIF_INTERNAL_FRAG_START: internal FW use.  * @IWM_TE_V2_NOTIF_INTERNAL_FRAG_END: internal FW use.  * @IWM_TE_V2_DEP_OTHER: depends on another time event  * @IWM_TE_V2_DEP_TSF: depends on a specific time  * @IWM_TE_V2_EVENT_SOCIOPATHIC: can't co-exist with other events of tha same MAC  * @IWM_TE_V2_ABSENCE: are we present or absent during the Time Event.  */
end_comment

begin_enum
enum|enum
block|{
name|IWM_TE_V2_DEFAULT_POLICY
init|=
literal|0x0
block|,
comment|/* notifications (event start/stop, fragment start/stop) */
name|IWM_TE_V2_NOTIF_HOST_EVENT_START
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_TE_V2_NOTIF_HOST_EVENT_END
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_TE_V2_NOTIF_INTERNAL_EVENT_START
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_TE_V2_NOTIF_INTERNAL_EVENT_END
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_TE_V2_NOTIF_HOST_FRAG_START
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|IWM_TE_V2_NOTIF_HOST_FRAG_END
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|IWM_TE_V2_NOTIF_INTERNAL_FRAG_START
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|IWM_TE_V2_NOTIF_INTERNAL_FRAG_END
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
name|IWM_TE_V2_NOTIF_MSK
init|=
literal|0xff
block|,
comment|/* placement characteristics */
name|IWM_TE_V2_DEP_OTHER
init|=
operator|(
literal|1
operator|<<
name|IWM_TE_V2_PLACEMENT_POS
operator|)
block|,
name|IWM_TE_V2_DEP_TSF
init|=
operator|(
literal|1
operator|<<
operator|(
name|IWM_TE_V2_PLACEMENT_POS
operator|+
literal|1
operator|)
operator|)
block|,
name|IWM_TE_V2_EVENT_SOCIOPATHIC
init|=
operator|(
literal|1
operator|<<
operator|(
name|IWM_TE_V2_PLACEMENT_POS
operator|+
literal|2
operator|)
operator|)
block|,
comment|/* are we present or absent during the Time Event. */
name|IWM_TE_V2_ABSENCE
init|=
operator|(
literal|1
operator|<<
name|IWM_TE_V2_ABSENCE_POS
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_time_event_cmd_api - configuring Time Events  * with struct IWM_MAC_TIME_EVENT_DATA_API_S_VER_2 (see also  * with version 1. determined by IWM_UCODE_TLV_FLAGS)  * ( IWM_TIME_EVENT_CMD = 0x29 )  * @id_and_color: ID and color of the relevant MAC  * @action: action to perform, one of IWM_FW_CTXT_ACTION_*  * @id: this field has two meanings, depending on the action:  *	If the action is ADD, then it means the type of event to add.  *	For all other actions it is the unique event ID assigned when the  *	event was added by the FW.  * @apply_time: When to start the Time Event (in GP2)  * @max_delay: maximum delay to event's start (apply time), in TU  * @depends_on: the unique ID of the event we depend on (if any)  * @interval: interval between repetitions, in TU  * @duration: duration of event in TU  * @repeat: how many repetitions to do, can be IWM_TE_REPEAT_ENDLESS  * @max_frags: maximal number of fragments the Time Event can be divided to  * @policy: defines whether uCode shall notify the host or other uCode modules  *	on event and/or fragment start and/or end  *	using one of IWM_TE_INDEPENDENT, IWM_TE_DEP_OTHER, IWM_TE_DEP_TSF  *	IWM_TE_EVENT_SOCIOPATHIC  *	using IWM_TE_ABSENCE and using IWM_TE_NOTIF_*  */
end_comment

begin_struct
struct|struct
name|iwm_time_event_cmd
block|{
comment|/* COMMON_INDEX_HDR_API_S_VER_1 */
name|uint32_t
name|id_and_color
decl_stmt|;
name|uint32_t
name|action
decl_stmt|;
name|uint32_t
name|id
decl_stmt|;
comment|/* IWM_MAC_TIME_EVENT_DATA_API_S_VER_2 */
name|uint32_t
name|apply_time
decl_stmt|;
name|uint32_t
name|max_delay
decl_stmt|;
name|uint32_t
name|depends_on
decl_stmt|;
name|uint32_t
name|interval
decl_stmt|;
name|uint32_t
name|duration
decl_stmt|;
name|uint8_t
name|repeat
decl_stmt|;
name|uint8_t
name|max_frags
decl_stmt|;
name|uint16_t
name|policy
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_MAC_TIME_EVENT_CMD_API_S_VER_2 */
end_comment

begin_comment
comment|/**  * struct iwm_time_event_resp - response structure to iwm_time_event_cmd  * @status: bit 0 indicates success, all others specify errors  * @id: the Time Event type  * @unique_id: the unique ID assigned (in ADD) or given (others) to the TE  * @id_and_color: ID and color of the relevant MAC  */
end_comment

begin_struct
struct|struct
name|iwm_time_event_resp
block|{
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|id
decl_stmt|;
name|uint32_t
name|unique_id
decl_stmt|;
name|uint32_t
name|id_and_color
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_MAC_TIME_EVENT_RSP_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_time_event_notif - notifications of time event start/stop  * ( IWM_TIME_EVENT_NOTIFICATION = 0x2a )  * @timestamp: action timestamp in GP2  * @session_id: session's unique id  * @unique_id: unique id of the Time Event itself  * @id_and_color: ID and color of the relevant MAC  * @action: one of IWM_TE_NOTIF_START or IWM_TE_NOTIF_END  * @status: true if scheduled, false otherwise (not executed)  */
end_comment

begin_struct
struct|struct
name|iwm_time_event_notif
block|{
name|uint32_t
name|timestamp
decl_stmt|;
name|uint32_t
name|session_id
decl_stmt|;
name|uint32_t
name|unique_id
decl_stmt|;
name|uint32_t
name|id_and_color
decl_stmt|;
name|uint32_t
name|action
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_MAC_TIME_EVENT_NTFY_API_S_VER_1 */
end_comment

begin_comment
comment|/* Bindings and Time Quota */
end_comment

begin_comment
comment|/**  * struct iwm_binding_cmd - configuring bindings  * ( IWM_BINDING_CONTEXT_CMD = 0x2b )  * @id_and_color: ID and color of the relevant Binding  * @action: action to perform, one of IWM_FW_CTXT_ACTION_*  * @macs: array of MAC id and colors which belong to the binding  * @phy: PHY id and color which belongs to the binding  */
end_comment

begin_struct
struct|struct
name|iwm_binding_cmd
block|{
comment|/* COMMON_INDEX_HDR_API_S_VER_1 */
name|uint32_t
name|id_and_color
decl_stmt|;
name|uint32_t
name|action
decl_stmt|;
comment|/* IWM_BINDING_DATA_API_S_VER_1 */
name|uint32_t
name|macs
index|[
name|IWM_MAX_MACS_IN_BINDING
index|]
decl_stmt|;
name|uint32_t
name|phy
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_BINDING_CMD_API_S_VER_1 */
end_comment

begin_comment
comment|/* The maximal number of fragments in the FW's schedule session */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_MAX_QUOTA
value|128
end_define

begin_comment
comment|/**  * struct iwm_time_quota_data - configuration of time quota per binding  * @id_and_color: ID and color of the relevant Binding  * @quota: absolute time quota in TU. The scheduler will try to divide the  *	remainig quota (after Time Events) according to this quota.  * @max_duration: max uninterrupted context duration in TU  */
end_comment

begin_struct
struct|struct
name|iwm_time_quota_data
block|{
name|uint32_t
name|id_and_color
decl_stmt|;
name|uint32_t
name|quota
decl_stmt|;
name|uint32_t
name|max_duration
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_TIME_QUOTA_DATA_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_time_quota_cmd - configuration of time quota between bindings  * ( IWM_TIME_QUOTA_CMD = 0x2c )  * @quotas: allocations per binding  */
end_comment

begin_struct
struct|struct
name|iwm_time_quota_cmd
block|{
name|struct
name|iwm_time_quota_data
name|quotas
index|[
name|IWM_MAX_BINDINGS
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_TIME_QUOTA_ALLOCATION_CMD_API_S_VER_1 */
end_comment

begin_comment
comment|/* PHY context */
end_comment

begin_comment
comment|/* Supported bands */
end_comment

begin_define
define|#
directive|define
name|IWM_PHY_BAND_5
value|(0)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_BAND_24
value|(1)
end_define

begin_comment
comment|/* Supported channel width, vary if there is VHT support */
end_comment

begin_define
define|#
directive|define
name|IWM_PHY_VHT_CHANNEL_MODE20
value|(0x0)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_VHT_CHANNEL_MODE40
value|(0x1)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_VHT_CHANNEL_MODE80
value|(0x2)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_VHT_CHANNEL_MODE160
value|(0x3)
end_define

begin_comment
comment|/*  * Control channel position:  * For legacy set bit means upper channel, otherwise lower.  * For VHT - bit-2 marks if the control is lower/upper relative to center-freq  *   bits-1:0 mark the distance from the center freq. for 20Mhz, offset is 0.  *                                   center_freq  *                                        |  * 40Mhz                          |_______|_______|  * 80Mhz                  |_______|_______|_______|_______|  * 160Mhz |_______|_______|_______|_______|_______|_______|_______|_______|  * code      011     010     001     000  |  100     101     110    111  */
end_comment

begin_define
define|#
directive|define
name|IWM_PHY_VHT_CTRL_POS_1_BELOW
value|(0x0)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_VHT_CTRL_POS_2_BELOW
value|(0x1)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_VHT_CTRL_POS_3_BELOW
value|(0x2)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_VHT_CTRL_POS_4_BELOW
value|(0x3)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_VHT_CTRL_POS_1_ABOVE
value|(0x4)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_VHT_CTRL_POS_2_ABOVE
value|(0x5)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_VHT_CTRL_POS_3_ABOVE
value|(0x6)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_VHT_CTRL_POS_4_ABOVE
value|(0x7)
end_define

begin_comment
comment|/*  * @band: IWM_PHY_BAND_*  * @channel: channel number  * @width: PHY_[VHT|LEGACY]_CHANNEL_*  * @ctrl channel: PHY_[VHT|LEGACY]_CTRL_*  */
end_comment

begin_struct
struct|struct
name|iwm_fw_channel_info
block|{
name|uint8_t
name|band
decl_stmt|;
name|uint8_t
name|channel
decl_stmt|;
name|uint8_t
name|width
decl_stmt|;
name|uint8_t
name|ctrl_pos
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_DRIVER_FORCE_POS
value|(0)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_DRIVER_FORCE_MSK
define|\
value|(0x1<< IWM_PHY_RX_CHAIN_DRIVER_FORCE_POS)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_VALID_POS
value|(1)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_VALID_MSK
define|\
value|(0x7<< IWM_PHY_RX_CHAIN_VALID_POS)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_FORCE_SEL_POS
value|(4)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_FORCE_SEL_MSK
define|\
value|(0x7<< IWM_PHY_RX_CHAIN_FORCE_SEL_POS)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_FORCE_MIMO_SEL_POS
value|(7)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_FORCE_MIMO_SEL_MSK
define|\
value|(0x7<< IWM_PHY_RX_CHAIN_FORCE_MIMO_SEL_POS)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_CNT_POS
value|(10)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_CNT_MSK
define|\
value|(0x3<< IWM_PHY_RX_CHAIN_CNT_POS)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_MIMO_CNT_POS
value|(12)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_MIMO_CNT_MSK
define|\
value|(0x3<< IWM_PHY_RX_CHAIN_MIMO_CNT_POS)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_MIMO_FORCE_POS
value|(14)
end_define

begin_define
define|#
directive|define
name|IWM_PHY_RX_CHAIN_MIMO_FORCE_MSK
define|\
value|(0x1<< IWM_PHY_RX_CHAIN_MIMO_FORCE_POS)
end_define

begin_comment
comment|/* TODO: fix the value, make it depend on firmware at runtime? */
end_comment

begin_define
define|#
directive|define
name|IWM_NUM_PHY_CTX
value|3
end_define

begin_comment
comment|/* TODO: complete missing documentation */
end_comment

begin_comment
comment|/**  * struct iwm_phy_context_cmd - config of the PHY context  * ( IWM_PHY_CONTEXT_CMD = 0x8 )  * @id_and_color: ID and color of the relevant Binding  * @action: action to perform, one of IWM_FW_CTXT_ACTION_*  * @apply_time: 0 means immediate apply and context switch.  *	other value means apply new params after X usecs  * @tx_param_color: ???  * @channel_info:  * @txchain_info: ???  * @rxchain_info: ???  * @acquisition_data: ???  * @dsp_cfg_flags: set to 0  */
end_comment

begin_struct
struct|struct
name|iwm_phy_context_cmd
block|{
comment|/* COMMON_INDEX_HDR_API_S_VER_1 */
name|uint32_t
name|id_and_color
decl_stmt|;
name|uint32_t
name|action
decl_stmt|;
comment|/* IWM_PHY_CONTEXT_DATA_API_S_VER_1 */
name|uint32_t
name|apply_time
decl_stmt|;
name|uint32_t
name|tx_param_color
decl_stmt|;
name|struct
name|iwm_fw_channel_info
name|ci
decl_stmt|;
name|uint32_t
name|txchain_info
decl_stmt|;
name|uint32_t
name|rxchain_info
decl_stmt|;
name|uint32_t
name|acquisition_data
decl_stmt|;
name|uint32_t
name|dsp_cfg_flags
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_PHY_CONTEXT_CMD_API_VER_1 */
end_comment

begin_define
define|#
directive|define
name|IWM_RX_INFO_PHY_CNT
value|8
end_define

begin_define
define|#
directive|define
name|IWM_RX_INFO_ENERGY_ANT_ABC_IDX
value|1
end_define

begin_define
define|#
directive|define
name|IWM_RX_INFO_ENERGY_ANT_A_MSK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|IWM_RX_INFO_ENERGY_ANT_B_MSK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|IWM_RX_INFO_ENERGY_ANT_C_MSK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|IWM_RX_INFO_ENERGY_ANT_A_POS
value|0
end_define

begin_define
define|#
directive|define
name|IWM_RX_INFO_ENERGY_ANT_B_POS
value|8
end_define

begin_define
define|#
directive|define
name|IWM_RX_INFO_ENERGY_ANT_C_POS
value|16
end_define

begin_define
define|#
directive|define
name|IWM_RX_INFO_AGC_IDX
value|1
end_define

begin_define
define|#
directive|define
name|IWM_RX_INFO_RSSI_AB_IDX
value|2
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_AGC_A_MSK
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_AGC_A_POS
value|0
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_AGC_B_MSK
value|0x00003f80
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_AGC_B_POS
value|7
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_AGC_CODE_MSK
value|0x3fe00000
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_AGC_CODE_POS
value|20
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_RSSI_INBAND_A_MSK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_RSSI_A_POS
value|0
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_RSSI_ALLBAND_A_MSK
value|0xff00
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_RSSI_ALLBAND_A_POS
value|8
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_RSSI_INBAND_B_MSK
value|0xff0000
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_RSSI_B_POS
value|16
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_RSSI_ALLBAND_B_MSK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|IWM_OFDM_RSSI_ALLBAND_B_POS
value|24
end_define

begin_comment
comment|/**  * struct iwm_rx_phy_info - phy info  * (IWM_REPLY_RX_PHY_CMD = 0xc0)  * @non_cfg_phy_cnt: non configurable DSP phy data byte count  * @cfg_phy_cnt: configurable DSP phy data byte count  * @stat_id: configurable DSP phy data set ID  * @reserved1:  * @system_timestamp: GP2  at on air rise  * @timestamp: TSF at on air rise  * @beacon_time_stamp: beacon at on-air rise  * @phy_flags: general phy flags: band, modulation, ...  * @channel: channel number  * @non_cfg_phy_buf: for various implementations of non_cfg_phy  * @rate_n_flags: IWM_RATE_MCS_*  * @byte_count: frame's byte-count  * @frame_time: frame's time on the air, based on byte count and frame rate  *	calculation  * @mac_active_msk: what MACs were active when the frame was received  *  * Before each Rx, the device sends this data. It contains PHY information  * about the reception of the packet.  */
end_comment

begin_struct
struct|struct
name|iwm_rx_phy_info
block|{
name|uint8_t
name|non_cfg_phy_cnt
decl_stmt|;
name|uint8_t
name|cfg_phy_cnt
decl_stmt|;
name|uint8_t
name|stat_id
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint32_t
name|system_timestamp
decl_stmt|;
name|uint64_t
name|timestamp
decl_stmt|;
name|uint32_t
name|beacon_time_stamp
decl_stmt|;
name|uint16_t
name|phy_flags
decl_stmt|;
define|#
directive|define
name|IWM_PHY_INFO_FLAG_SHPREAMBLE
value|(1<< 2)
name|uint16_t
name|channel
decl_stmt|;
name|uint32_t
name|non_cfg_phy
index|[
name|IWM_RX_INFO_PHY_CNT
index|]
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|rflags
decl_stmt|;
name|uint16_t
name|xrflags
decl_stmt|;
name|uint32_t
name|byte_count
decl_stmt|;
name|uint16_t
name|mac_active_msk
decl_stmt|;
name|uint16_t
name|frame_time
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwm_rx_mpdu_res_start
block|{
name|uint16_t
name|byte_count
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * enum iwm_rx_phy_flags - to parse %iwm_rx_phy_info phy_flags  * @IWM_RX_RES_PHY_FLAGS_BAND_24: true if the packet was received on 2.4 band  * @IWM_RX_RES_PHY_FLAGS_MOD_CCK:  * @IWM_RX_RES_PHY_FLAGS_SHORT_PREAMBLE: true if packet's preamble was short  * @IWM_RX_RES_PHY_FLAGS_NARROW_BAND:  * @IWM_RX_RES_PHY_FLAGS_ANTENNA: antenna on which the packet was received  * @IWM_RX_RES_PHY_FLAGS_AGG: set if the packet was part of an A-MPDU  * @IWM_RX_RES_PHY_FLAGS_OFDM_HT: The frame was an HT frame  * @IWM_RX_RES_PHY_FLAGS_OFDM_GF: The frame used GF preamble  * @IWM_RX_RES_PHY_FLAGS_OFDM_VHT: The frame was a VHT frame  */
end_comment

begin_enum
enum|enum
name|iwm_rx_phy_flags
block|{
name|IWM_RX_RES_PHY_FLAGS_BAND_24
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_RX_RES_PHY_FLAGS_MOD_CCK
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_RX_RES_PHY_FLAGS_SHORT_PREAMBLE
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_RX_RES_PHY_FLAGS_NARROW_BAND
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_RX_RES_PHY_FLAGS_ANTENNA
init|=
operator|(
literal|0x7
operator|<<
literal|4
operator|)
block|,
name|IWM_RX_RES_PHY_FLAGS_ANTENNA_POS
init|=
literal|4
block|,
name|IWM_RX_RES_PHY_FLAGS_AGG
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
name|IWM_RX_RES_PHY_FLAGS_OFDM_HT
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
name|IWM_RX_RES_PHY_FLAGS_OFDM_GF
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
name|IWM_RX_RES_PHY_FLAGS_OFDM_VHT
init|=
operator|(
literal|1
operator|<<
literal|10
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum iwm_mvm_rx_status - written by fw for each Rx packet  * @IWM_RX_MPDU_RES_STATUS_CRC_OK: CRC is fine  * @IWM_RX_MPDU_RES_STATUS_OVERRUN_OK: there was no RXE overflow  * @IWM_RX_MPDU_RES_STATUS_SRC_STA_FOUND:  * @IWM_RX_MPDU_RES_STATUS_KEY_VALID:  * @IWM_RX_MPDU_RES_STATUS_KEY_PARAM_OK:  * @IWM_RX_MPDU_RES_STATUS_ICV_OK: ICV is fine, if not, the packet is destroyed  * @IWM_RX_MPDU_RES_STATUS_MIC_OK: used for CCM alg only. TKIP MIC is checked  *	in the driver.  * @IWM_RX_MPDU_RES_STATUS_TTAK_OK: TTAK is fine  * @IWM_RX_MPDU_RES_STATUS_MNG_FRAME_REPLAY_ERR:  valid for alg = CCM_CMAC or  *	alg = CCM only. Checks replay attack for 11w frames. Relevant only if  *	%IWM_RX_MPDU_RES_STATUS_ROBUST_MNG_FRAME is set.  * @IWM_RX_MPDU_RES_STATUS_SEC_NO_ENC: this frame is not encrypted  * @IWM_RX_MPDU_RES_STATUS_SEC_WEP_ENC: this frame is encrypted using WEP  * @IWM_RX_MPDU_RES_STATUS_SEC_CCM_ENC: this frame is encrypted using CCM  * @IWM_RX_MPDU_RES_STATUS_SEC_TKIP_ENC: this frame is encrypted using TKIP  * @IWM_RX_MPDU_RES_STATUS_SEC_CCM_CMAC_ENC: this frame is encrypted using CCM_CMAC  * @IWM_RX_MPDU_RES_STATUS_SEC_ENC_ERR: this frame couldn't be decrypted  * @IWM_RX_MPDU_RES_STATUS_SEC_ENC_MSK: bitmask of the encryption algorithm  * @IWM_RX_MPDU_RES_STATUS_DEC_DONE: this frame has been successfully decrypted  * @IWM_RX_MPDU_RES_STATUS_PROTECT_FRAME_BIT_CMP:  * @IWM_RX_MPDU_RES_STATUS_EXT_IV_BIT_CMP:  * @IWM_RX_MPDU_RES_STATUS_KEY_ID_CMP_BIT:  * @IWM_RX_MPDU_RES_STATUS_ROBUST_MNG_FRAME: this frame is an 11w management frame  * @IWM_RX_MPDU_RES_STATUS_HASH_INDEX_MSK:  * @IWM_RX_MPDU_RES_STATUS_STA_ID_MSK:  * @IWM_RX_MPDU_RES_STATUS_RRF_KILL:  * @IWM_RX_MPDU_RES_STATUS_FILTERING_MSK:  * @IWM_RX_MPDU_RES_STATUS2_FILTERING_MSK:  */
end_comment

begin_enum
enum|enum
name|iwm_mvm_rx_status
block|{
name|IWM_RX_MPDU_RES_STATUS_CRC_OK
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_OVERRUN_OK
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_SRC_STA_FOUND
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_KEY_VALID
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_KEY_PARAM_OK
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_ICV_OK
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_MIC_OK
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_TTAK_OK
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_MNG_FRAME_REPLAY_ERR
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_SEC_NO_ENC
init|=
operator|(
literal|0
operator|<<
literal|8
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_SEC_WEP_ENC
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_SEC_CCM_ENC
init|=
operator|(
literal|2
operator|<<
literal|8
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_SEC_TKIP_ENC
init|=
operator|(
literal|3
operator|<<
literal|8
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_SEC_EXT_ENC
init|=
operator|(
literal|4
operator|<<
literal|8
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_SEC_CCM_CMAC_ENC
init|=
operator|(
literal|6
operator|<<
literal|8
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_SEC_ENC_ERR
init|=
operator|(
literal|7
operator|<<
literal|8
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_SEC_ENC_MSK
init|=
operator|(
literal|7
operator|<<
literal|8
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_DEC_DONE
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_PROTECT_FRAME_BIT_CMP
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_EXT_IV_BIT_CMP
init|=
operator|(
literal|1
operator|<<
literal|13
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_KEY_ID_CMP_BIT
init|=
operator|(
literal|1
operator|<<
literal|14
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_ROBUST_MNG_FRAME
init|=
operator|(
literal|1
operator|<<
literal|15
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_HASH_INDEX_MSK
init|=
operator|(
literal|0x3F0000
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_STA_ID_MSK
init|=
operator|(
literal|0x1f000000
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_RRF_KILL
init|=
operator|(
literal|1
operator|<<
literal|29
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS_FILTERING_MSK
init|=
operator|(
literal|0xc00000
operator|)
block|,
name|IWM_RX_MPDU_RES_STATUS2_FILTERING_MSK
init|=
operator|(
literal|0xc0000000
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_radio_version_notif - information on the radio version  * ( IWM_RADIO_VERSION_NOTIFICATION = 0x68 )  * @radio_flavor:  * @radio_step:  * @radio_dash:  */
end_comment

begin_struct
struct|struct
name|iwm_radio_version_notif
block|{
name|uint32_t
name|radio_flavor
decl_stmt|;
name|uint32_t
name|radio_step
decl_stmt|;
name|uint32_t
name|radio_dash
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_RADIO_VERSION_NOTOFICATION_S_VER_1 */
end_comment

begin_enum
enum|enum
name|iwm_card_state_flags
block|{
name|IWM_CARD_ENABLED
init|=
literal|0x00
block|,
name|IWM_HW_CARD_DISABLED
init|=
literal|0x01
block|,
name|IWM_SW_CARD_DISABLED
init|=
literal|0x02
block|,
name|IWM_CT_KILL_CARD_DISABLED
init|=
literal|0x04
block|,
name|IWM_HALT_CARD_DISABLED
init|=
literal|0x08
block|,
name|IWM_CARD_DISABLED_MSK
init|=
literal|0x0f
block|,
name|IWM_CARD_IS_RX_ON
init|=
literal|0x10
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_radio_version_notif - information on the radio version  * (IWM_CARD_STATE_NOTIFICATION = 0xa1 )  * @flags: %iwm_card_state_flags  */
end_comment

begin_struct
struct|struct
name|iwm_card_state_notif
block|{
name|uint32_t
name|flags
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* CARD_STATE_NTFY_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_missed_beacons_notif - information on missed beacons  * ( IWM_MISSED_BEACONS_NOTIFICATION = 0xa2 )  * @mac_id: interface ID  * @consec_missed_beacons_since_last_rx: number of consecutive missed  *	beacons since last RX.  * @consec_missed_beacons: number of consecutive missed beacons  * @num_expected_beacons:  * @num_recvd_beacons:  */
end_comment

begin_struct
struct|struct
name|iwm_missed_beacons_notif
block|{
name|uint32_t
name|mac_id
decl_stmt|;
name|uint32_t
name|consec_missed_beacons_since_last_rx
decl_stmt|;
name|uint32_t
name|consec_missed_beacons
decl_stmt|;
name|uint32_t
name|num_expected_beacons
decl_stmt|;
name|uint32_t
name|num_recvd_beacons
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_MISSED_BEACON_NTFY_API_S_VER_3 */
end_comment

begin_comment
comment|/**  * struct iwm_mfuart_load_notif - mfuart image version& status  * ( IWM_MFUART_LOAD_NOTIFICATION = 0xb1 )  * @installed_ver: installed image version  * @external_ver: external image version  * @status: MFUART loading status  * @duration: MFUART loading time */
end_comment

begin_struct
struct|struct
name|iwm_mfuart_load_notif
block|{
name|uint32_t
name|installed_ver
decl_stmt|;
name|uint32_t
name|external_ver
decl_stmt|;
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|duration
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*MFU_LOADER_NTFY_API_S_VER_1*/
end_comment

begin_comment
comment|/**  * struct iwm_set_calib_default_cmd - set default value for calibration.  * ( IWM_SET_CALIB_DEFAULT_CMD = 0x8e )  * @calib_index: the calibration to set value for  * @length: of data  * @data: the value to set for the calibration result  */
end_comment

begin_struct
struct|struct
name|iwm_set_calib_default_cmd
block|{
name|uint16_t
name|calib_index
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint8_t
name|data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_PHY_CALIB_OVERRIDE_VALUES_S */
end_comment

begin_define
define|#
directive|define
name|IWM_MAX_PORT_ID_NUM
value|2
end_define

begin_define
define|#
directive|define
name|IWM_MAX_MCAST_FILTERING_ADDRESSES
value|256
end_define

begin_comment
comment|/**  * struct iwm_mcast_filter_cmd - configure multicast filter.  * @filter_own: Set 1 to filter out multicast packets sent by station itself  * @port_id:	Multicast MAC addresses array specifier. This is a strange way  *		to identify network interface adopted in host-device IF.  *		It is used by FW as index in array of addresses. This array has  *		IWM_MAX_PORT_ID_NUM members.  * @count:	Number of MAC addresses in the array  * @pass_all:	Set 1 to pass all multicast packets.  * @bssid:	current association BSSID.  * @addr_list:	Place holder for array of MAC addresses.  *		IMPORTANT: add padding if necessary to ensure DWORD alignment.  */
end_comment

begin_struct
struct|struct
name|iwm_mcast_filter_cmd
block|{
name|uint8_t
name|filter_own
decl_stmt|;
name|uint8_t
name|port_id
decl_stmt|;
name|uint8_t
name|count
decl_stmt|;
name|uint8_t
name|pass_all
decl_stmt|;
name|uint8_t
name|bssid
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|addr_list
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_MCAST_FILTERING_CMD_API_S_VER_1 */
end_comment

begin_comment
comment|/*  * The first MAC indices (starting from 0)  * are available to the driver, AUX follows  */
end_comment

begin_define
define|#
directive|define
name|IWM_MAC_INDEX_AUX
value|4
end_define

begin_define
define|#
directive|define
name|IWM_MAC_INDEX_MIN_DRIVER
value|0
end_define

begin_define
define|#
directive|define
name|IWM_NUM_MAC_INDEX_DRIVER
value|IWM_MAC_INDEX_AUX
end_define

begin_define
define|#
directive|define
name|IWM_NUM_MAC_INDEX
value|(IWM_MAC_INDEX_AUX + 1)
end_define

begin_comment
comment|/***********************************  * Statistics API  ***********************************/
end_comment

begin_struct
struct|struct
name|iwm_mvm_statistics_dbg
block|{
name|uint32_t
name|burst_check
decl_stmt|;
name|uint32_t
name|burst_count
decl_stmt|;
name|uint32_t
name|wait_for_silence_timeout_cnt
decl_stmt|;
name|uint32_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_DEBUG_API_S_VER_2 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_statistics_div
block|{
name|uint32_t
name|tx_on_a
decl_stmt|;
name|uint32_t
name|tx_on_b
decl_stmt|;
name|uint32_t
name|exec_time
decl_stmt|;
name|uint32_t
name|probe_time
decl_stmt|;
name|uint32_t
name|rssi_ant
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_SLOW_DIV_API_S_VER_2 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_statistics_rx_non_phy
block|{
name|uint32_t
name|bogus_cts
decl_stmt|;
comment|/* CTS received when not expecting CTS */
name|uint32_t
name|bogus_ack
decl_stmt|;
comment|/* ACK received when not expecting ACK */
name|uint32_t
name|non_bssid_frames
decl_stmt|;
comment|/* number of frames with BSSID that 					 * doesn't belong to the STA BSSID */
name|uint32_t
name|filtered_frames
decl_stmt|;
comment|/* count frames that were dumped in the 				 * filtering process */
name|uint32_t
name|non_channel_beacons
decl_stmt|;
comment|/* beacons with our bss id but not on 					 * our serving channel */
name|uint32_t
name|channel_beacons
decl_stmt|;
comment|/* beacons with our bss id and in our 				 * serving channel */
name|uint32_t
name|num_missed_bcon
decl_stmt|;
comment|/* number of missed beacons */
name|uint32_t
name|adc_rx_saturation_time
decl_stmt|;
comment|/* count in 0.8us units the time the 					 * ADC was in saturation */
name|uint32_t
name|ina_detection_search_time
decl_stmt|;
comment|/* total time (in 0.8us) searched 					  * for INA */
name|uint32_t
name|beacon_silence_rssi
index|[
literal|3
index|]
decl_stmt|;
comment|/* RSSI silence after beacon frame */
name|uint32_t
name|interference_data_flag
decl_stmt|;
comment|/* flag for interference data 					 * availability. 1 when data is 					 * available. */
name|uint32_t
name|channel_load
decl_stmt|;
comment|/* counts RX Enable time in uSec */
name|uint32_t
name|dsp_false_alarms
decl_stmt|;
comment|/* DSP false alarm (both OFDM 					 * and CCK) counter */
name|uint32_t
name|beacon_rssi_a
decl_stmt|;
name|uint32_t
name|beacon_rssi_b
decl_stmt|;
name|uint32_t
name|beacon_rssi_c
decl_stmt|;
name|uint32_t
name|beacon_energy_a
decl_stmt|;
name|uint32_t
name|beacon_energy_b
decl_stmt|;
name|uint32_t
name|beacon_energy_c
decl_stmt|;
name|uint32_t
name|num_bt_kills
decl_stmt|;
name|uint32_t
name|mac_id
decl_stmt|;
name|uint32_t
name|directed_data_mpdu
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_RX_NON_PHY_API_S_VER_3 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_statistics_rx_phy
block|{
name|uint32_t
name|ina_cnt
decl_stmt|;
name|uint32_t
name|fina_cnt
decl_stmt|;
name|uint32_t
name|plcp_err
decl_stmt|;
name|uint32_t
name|crc32_err
decl_stmt|;
name|uint32_t
name|overrun_err
decl_stmt|;
name|uint32_t
name|early_overrun_err
decl_stmt|;
name|uint32_t
name|crc32_good
decl_stmt|;
name|uint32_t
name|false_alarm_cnt
decl_stmt|;
name|uint32_t
name|fina_sync_err_cnt
decl_stmt|;
name|uint32_t
name|sfd_timeout
decl_stmt|;
name|uint32_t
name|fina_timeout
decl_stmt|;
name|uint32_t
name|unresponded_rts
decl_stmt|;
name|uint32_t
name|rxe_frame_limit_overrun
decl_stmt|;
name|uint32_t
name|sent_ack_cnt
decl_stmt|;
name|uint32_t
name|sent_cts_cnt
decl_stmt|;
name|uint32_t
name|sent_ba_rsp_cnt
decl_stmt|;
name|uint32_t
name|dsp_self_kill
decl_stmt|;
name|uint32_t
name|mh_format_err
decl_stmt|;
name|uint32_t
name|re_acq_main_rssi_sum
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_RX_PHY_API_S_VER_2 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_statistics_rx_ht_phy
block|{
name|uint32_t
name|plcp_err
decl_stmt|;
name|uint32_t
name|overrun_err
decl_stmt|;
name|uint32_t
name|early_overrun_err
decl_stmt|;
name|uint32_t
name|crc32_good
decl_stmt|;
name|uint32_t
name|crc32_err
decl_stmt|;
name|uint32_t
name|mh_format_err
decl_stmt|;
name|uint32_t
name|agg_crc32_good
decl_stmt|;
name|uint32_t
name|agg_mpdu_cnt
decl_stmt|;
name|uint32_t
name|agg_cnt
decl_stmt|;
name|uint32_t
name|unsupport_mcs
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_HT_RX_PHY_API_S_VER_1 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_statistics_tx_non_phy
block|{
name|uint32_t
name|preamble_cnt
decl_stmt|;
name|uint32_t
name|rx_detected_cnt
decl_stmt|;
name|uint32_t
name|bt_prio_defer_cnt
decl_stmt|;
name|uint32_t
name|bt_prio_kill_cnt
decl_stmt|;
name|uint32_t
name|few_bytes_cnt
decl_stmt|;
name|uint32_t
name|cts_timeout
decl_stmt|;
name|uint32_t
name|ack_timeout
decl_stmt|;
name|uint32_t
name|expected_ack_cnt
decl_stmt|;
name|uint32_t
name|actual_ack_cnt
decl_stmt|;
name|uint32_t
name|dump_msdu_cnt
decl_stmt|;
name|uint32_t
name|burst_abort_next_frame_mismatch_cnt
decl_stmt|;
name|uint32_t
name|burst_abort_missing_next_frame_cnt
decl_stmt|;
name|uint32_t
name|cts_timeout_collision
decl_stmt|;
name|uint32_t
name|ack_or_ba_timeout_collision
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_TX_NON_PHY_API_S_VER_3 */
end_comment

begin_define
define|#
directive|define
name|IWM_MAX_CHAINS
value|3
end_define

begin_struct
struct|struct
name|iwm_mvm_statistics_tx_non_phy_agg
block|{
name|uint32_t
name|ba_timeout
decl_stmt|;
name|uint32_t
name|ba_reschedule_frames
decl_stmt|;
name|uint32_t
name|scd_query_agg_frame_cnt
decl_stmt|;
name|uint32_t
name|scd_query_no_agg
decl_stmt|;
name|uint32_t
name|scd_query_agg
decl_stmt|;
name|uint32_t
name|scd_query_mismatch
decl_stmt|;
name|uint32_t
name|frame_not_ready
decl_stmt|;
name|uint32_t
name|underrun
decl_stmt|;
name|uint32_t
name|bt_prio_kill
decl_stmt|;
name|uint32_t
name|rx_ba_rsp_cnt
decl_stmt|;
name|int8_t
name|txpower
index|[
name|IWM_MAX_CHAINS
index|]
decl_stmt|;
name|int8_t
name|reserved
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_TX_NON_PHY_AGG_API_S_VER_1 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_statistics_tx_channel_width
block|{
name|uint32_t
name|ext_cca_narrow_ch20
index|[
literal|1
index|]
decl_stmt|;
name|uint32_t
name|ext_cca_narrow_ch40
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|ext_cca_narrow_ch80
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|ext_cca_narrow_ch160
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|last_tx_ch_width_indx
decl_stmt|;
name|uint32_t
name|rx_detected_per_ch_width
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|success_per_ch_width
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|fail_per_ch_width
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_TX_CHANNEL_WIDTH_API_S_VER_1 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_statistics_tx
block|{
name|struct
name|iwm_mvm_statistics_tx_non_phy
name|general
decl_stmt|;
name|struct
name|iwm_mvm_statistics_tx_non_phy_agg
name|agg
decl_stmt|;
name|struct
name|iwm_mvm_statistics_tx_channel_width
name|channel_width
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_TX_API_S_VER_4 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_statistics_bt_activity
block|{
name|uint32_t
name|hi_priority_tx_req_cnt
decl_stmt|;
name|uint32_t
name|hi_priority_tx_denied_cnt
decl_stmt|;
name|uint32_t
name|lo_priority_tx_req_cnt
decl_stmt|;
name|uint32_t
name|lo_priority_tx_denied_cnt
decl_stmt|;
name|uint32_t
name|hi_priority_rx_req_cnt
decl_stmt|;
name|uint32_t
name|hi_priority_rx_denied_cnt
decl_stmt|;
name|uint32_t
name|lo_priority_rx_req_cnt
decl_stmt|;
name|uint32_t
name|lo_priority_rx_denied_cnt
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_BT_ACTIVITY_API_S_VER_1 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_statistics_general_v8
block|{
name|uint32_t
name|radio_temperature
decl_stmt|;
name|uint32_t
name|radio_voltage
decl_stmt|;
name|struct
name|iwm_mvm_statistics_dbg
name|dbg
decl_stmt|;
name|uint32_t
name|sleep_time
decl_stmt|;
name|uint32_t
name|slots_out
decl_stmt|;
name|uint32_t
name|slots_idle
decl_stmt|;
name|uint32_t
name|ttl_timestamp
decl_stmt|;
name|struct
name|iwm_mvm_statistics_div
name|slow_div
decl_stmt|;
name|uint32_t
name|rx_enable_counter
decl_stmt|;
comment|/* 	 * num_of_sos_states: 	 *  count the number of times we have to re-tune 	 *  in order to get out of bad PHY status 	 */
name|uint32_t
name|num_of_sos_states
decl_stmt|;
name|uint32_t
name|beacon_filtered
decl_stmt|;
name|uint32_t
name|missed_beacons
decl_stmt|;
name|uint8_t
name|beacon_filter_average_energy
decl_stmt|;
name|uint8_t
name|beacon_filter_reason
decl_stmt|;
name|uint8_t
name|beacon_filter_current_energy
decl_stmt|;
name|uint8_t
name|beacon_filter_reserved
decl_stmt|;
name|uint32_t
name|beacon_filter_delta_time
decl_stmt|;
name|struct
name|iwm_mvm_statistics_bt_activity
name|bt_activity
decl_stmt|;
name|uint64_t
name|rx_time
decl_stmt|;
name|uint64_t
name|on_time_rf
decl_stmt|;
name|uint64_t
name|on_time_scan
decl_stmt|;
name|uint64_t
name|tx_time
decl_stmt|;
name|uint32_t
name|beacon_counter
index|[
name|IWM_NUM_MAC_INDEX
index|]
decl_stmt|;
name|uint8_t
name|beacon_average_energy
index|[
name|IWM_NUM_MAC_INDEX
index|]
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|4
operator|-
operator|(
name|IWM_NUM_MAC_INDEX
operator|%
literal|4
operator|)
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_GENERAL_API_S_VER_8 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_statistics_rx
block|{
name|struct
name|iwm_mvm_statistics_rx_phy
name|ofdm
decl_stmt|;
name|struct
name|iwm_mvm_statistics_rx_phy
name|cck
decl_stmt|;
name|struct
name|iwm_mvm_statistics_rx_non_phy
name|general
decl_stmt|;
name|struct
name|iwm_mvm_statistics_rx_ht_phy
name|ofdm_ht
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_RX_API_S_VER_3 */
end_comment

begin_comment
comment|/*  * IWM_STATISTICS_NOTIFICATION = 0x9d (notification only, not a command)  *  * By default, uCode issues this notification after receiving a beacon  * while associated.  To disable this behavior, set DISABLE_NOTIF flag in the  * IWM_STATISTICS_CMD (0x9c), below.  */
end_comment

begin_struct
struct|struct
name|iwm_notif_statistics_v10
block|{
name|uint32_t
name|flag
decl_stmt|;
name|struct
name|iwm_mvm_statistics_rx
name|rx
decl_stmt|;
name|struct
name|iwm_mvm_statistics_tx
name|tx
decl_stmt|;
name|struct
name|iwm_mvm_statistics_general_v8
name|general
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_NTFY_API_S_VER_10 */
end_comment

begin_define
define|#
directive|define
name|IWM_STATISTICS_FLG_CLEAR
value|0x1
end_define

begin_define
define|#
directive|define
name|IWM_STATISTICS_FLG_DISABLE_NOTIF
value|0x2
end_define

begin_struct
struct|struct
name|iwm_statistics_cmd
block|{
name|uint32_t
name|flags
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STATISTICS_CMD_API_S_VER_1 */
end_comment

begin_comment
comment|/***********************************  * Smart Fifo API  ***********************************/
end_comment

begin_comment
comment|/* Smart Fifo state */
end_comment

begin_enum
enum|enum
name|iwm_sf_state
block|{
name|IWM_SF_LONG_DELAY_ON
init|=
literal|0
block|,
comment|/* should never be called by driver */
name|IWM_SF_FULL_ON
block|,
name|IWM_SF_UNINIT
block|,
name|IWM_SF_INIT_OFF
block|,
name|IWM_SF_HW_NUM_STATES
block|}
enum|;
end_enum

begin_comment
comment|/* Smart Fifo possible scenario */
end_comment

begin_enum
enum|enum
name|iwm_sf_scenario
block|{
name|IWM_SF_SCENARIO_SINGLE_UNICAST
block|,
name|IWM_SF_SCENARIO_AGG_UNICAST
block|,
name|IWM_SF_SCENARIO_MULTICAST
block|,
name|IWM_SF_SCENARIO_BA_RESP
block|,
name|IWM_SF_SCENARIO_TX_RESP
block|,
name|IWM_SF_NUM_SCENARIO
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_SF_TRANSIENT_STATES_NUMBER
value|2
end_define

begin_comment
comment|/* IWM_SF_LONG_DELAY_ON and IWM_SF_FULL_ON */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_NUM_TIMEOUT_TYPES
value|2
end_define

begin_comment
comment|/* Aging timer and Idle timer */
end_comment

begin_comment
comment|/* smart FIFO default values */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_W_MARK_SISO
value|4096
end_define

begin_define
define|#
directive|define
name|IWM_SF_W_MARK_MIMO2
value|8192
end_define

begin_define
define|#
directive|define
name|IWM_SF_W_MARK_MIMO3
value|6144
end_define

begin_define
define|#
directive|define
name|IWM_SF_W_MARK_LEGACY
value|4096
end_define

begin_define
define|#
directive|define
name|IWM_SF_W_MARK_SCAN
value|4096
end_define

begin_comment
comment|/* SF Scenarios timers for default configuration (aligned to 32 uSec) */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_SINGLE_UNICAST_IDLE_TIMER_DEF
value|160
end_define

begin_comment
comment|/* 150 uSec  */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_SINGLE_UNICAST_AGING_TIMER_DEF
value|400
end_define

begin_comment
comment|/* 0.4 mSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_AGG_UNICAST_IDLE_TIMER_DEF
value|160
end_define

begin_comment
comment|/* 150 uSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_AGG_UNICAST_AGING_TIMER_DEF
value|400
end_define

begin_comment
comment|/* 0.4 mSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_MCAST_IDLE_TIMER_DEF
value|160
end_define

begin_comment
comment|/* 150 uSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_MCAST_AGING_TIMER_DEF
value|400
end_define

begin_comment
comment|/* 0.4 mSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_BA_IDLE_TIMER_DEF
value|160
end_define

begin_comment
comment|/* 150 uSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_BA_AGING_TIMER_DEF
value|400
end_define

begin_comment
comment|/* 0.4 mSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_TX_RE_IDLE_TIMER_DEF
value|160
end_define

begin_comment
comment|/* 150 uSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_TX_RE_AGING_TIMER_DEF
value|400
end_define

begin_comment
comment|/* 0.4 mSec */
end_comment

begin_comment
comment|/* SF Scenarios timers for FULL_ON state (aligned to 32 uSec) */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_SINGLE_UNICAST_IDLE_TIMER
value|320
end_define

begin_comment
comment|/* 300 uSec  */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_SINGLE_UNICAST_AGING_TIMER
value|2016
end_define

begin_comment
comment|/* 2 mSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_AGG_UNICAST_IDLE_TIMER
value|320
end_define

begin_comment
comment|/* 300 uSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_AGG_UNICAST_AGING_TIMER
value|2016
end_define

begin_comment
comment|/* 2 mSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_MCAST_IDLE_TIMER
value|2016
end_define

begin_comment
comment|/* 2 mSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_MCAST_AGING_TIMER
value|10016
end_define

begin_comment
comment|/* 10 mSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_BA_IDLE_TIMER
value|320
end_define

begin_comment
comment|/* 300 uSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_BA_AGING_TIMER
value|2016
end_define

begin_comment
comment|/* 2 mSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_TX_RE_IDLE_TIMER
value|320
end_define

begin_comment
comment|/* 300 uSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_TX_RE_AGING_TIMER
value|2016
end_define

begin_comment
comment|/* 2 mSec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_LONG_DELAY_AGING_TIMER
value|1000000
end_define

begin_comment
comment|/* 1 Sec */
end_comment

begin_define
define|#
directive|define
name|IWM_SF_CFG_DUMMY_NOTIF_OFF
value|(1<< 16)
end_define

begin_comment
comment|/**  * Smart Fifo configuration command.  * @state: smart fifo state, types listed in iwm_sf_state.  * @watermark: Minimum allowed available free space in RXF for transient state.  * @long_delay_timeouts: aging and idle timer values for each scenario  * in long delay state.  * @full_on_timeouts: timer values for each scenario in full on state.  */
end_comment

begin_struct
struct|struct
name|iwm_sf_cfg_cmd
block|{
name|uint32_t
name|state
decl_stmt|;
name|uint32_t
name|watermark
index|[
name|IWM_SF_TRANSIENT_STATES_NUMBER
index|]
decl_stmt|;
name|uint32_t
name|long_delay_timeouts
index|[
name|IWM_SF_NUM_SCENARIO
index|]
index|[
name|IWM_SF_NUM_TIMEOUT_TYPES
index|]
decl_stmt|;
name|uint32_t
name|full_on_timeouts
index|[
name|IWM_SF_NUM_SCENARIO
index|]
index|[
name|IWM_SF_NUM_TIMEOUT_TYPES
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_SF_CFG_API_S_VER_2 */
end_comment

begin_comment
comment|/*  * END mvm/fw-api.h  */
end_comment

begin_comment
comment|/*  * BEGIN mvm/fw-api-mac.h  */
end_comment

begin_enum
enum|enum
name|iwm_ac
block|{
name|IWM_AC_BK
block|,
name|IWM_AC_BE
block|,
name|IWM_AC_VI
block|,
name|IWM_AC_VO
block|,
name|IWM_AC_NUM
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum iwm_mac_protection_flags - MAC context flags  * @IWM_MAC_PROT_FLG_TGG_PROTECT: 11g protection when transmitting OFDM frames,  *	this will require CCK RTS/CTS2self.  *	RTS/CTS will protect full burst time.  * @IWM_MAC_PROT_FLG_HT_PROT: enable HT protection  * @IWM_MAC_PROT_FLG_FAT_PROT: protect 40 MHz transmissions  * @IWM_MAC_PROT_FLG_SELF_CTS_EN: allow CTS2self  */
end_comment

begin_enum
enum|enum
name|iwm_mac_protection_flags
block|{
name|IWM_MAC_PROT_FLG_TGG_PROTECT
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_MAC_PROT_FLG_HT_PROT
init|=
operator|(
literal|1
operator|<<
literal|23
operator|)
block|,
name|IWM_MAC_PROT_FLG_FAT_PROT
init|=
operator|(
literal|1
operator|<<
literal|24
operator|)
block|,
name|IWM_MAC_PROT_FLG_SELF_CTS_EN
init|=
operator|(
literal|1
operator|<<
literal|30
operator|)
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_MAC_FLG_SHORT_SLOT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|IWM_MAC_FLG_SHORT_PREAMBLE
value|(1<< 5)
end_define

begin_comment
comment|/**  * enum iwm_mac_types - Supported MAC types  * @IWM_FW_MAC_TYPE_FIRST: lowest supported MAC type  * @IWM_FW_MAC_TYPE_AUX: Auxiliary MAC (internal)  * @IWM_FW_MAC_TYPE_LISTENER: monitor MAC type (?)  * @IWM_FW_MAC_TYPE_PIBSS: Pseudo-IBSS  * @IWM_FW_MAC_TYPE_IBSS: IBSS  * @IWM_FW_MAC_TYPE_BSS_STA: BSS (managed) station  * @IWM_FW_MAC_TYPE_P2P_DEVICE: P2P Device  * @IWM_FW_MAC_TYPE_P2P_STA: P2P client  * @IWM_FW_MAC_TYPE_GO: P2P GO  * @IWM_FW_MAC_TYPE_TEST: ?  * @IWM_FW_MAC_TYPE_MAX: highest support MAC type  */
end_comment

begin_enum
enum|enum
name|iwm_mac_types
block|{
name|IWM_FW_MAC_TYPE_FIRST
init|=
literal|1
block|,
name|IWM_FW_MAC_TYPE_AUX
init|=
name|IWM_FW_MAC_TYPE_FIRST
block|,
name|IWM_FW_MAC_TYPE_LISTENER
block|,
name|IWM_FW_MAC_TYPE_PIBSS
block|,
name|IWM_FW_MAC_TYPE_IBSS
block|,
name|IWM_FW_MAC_TYPE_BSS_STA
block|,
name|IWM_FW_MAC_TYPE_P2P_DEVICE
block|,
name|IWM_FW_MAC_TYPE_P2P_STA
block|,
name|IWM_FW_MAC_TYPE_GO
block|,
name|IWM_FW_MAC_TYPE_TEST
block|,
name|IWM_FW_MAC_TYPE_MAX
init|=
name|IWM_FW_MAC_TYPE_TEST
block|}
enum|;
end_enum

begin_comment
comment|/* IWM_MAC_CONTEXT_TYPE_API_E_VER_1 */
end_comment

begin_comment
comment|/**  * enum iwm_tsf_id - TSF hw timer ID  * @IWM_TSF_ID_A: use TSF A  * @IWM_TSF_ID_B: use TSF B  * @IWM_TSF_ID_C: use TSF C  * @IWM_TSF_ID_D: use TSF D  * @IWM_NUM_TSF_IDS: number of TSF timers available  */
end_comment

begin_enum
enum|enum
name|iwm_tsf_id
block|{
name|IWM_TSF_ID_A
init|=
literal|0
block|,
name|IWM_TSF_ID_B
init|=
literal|1
block|,
name|IWM_TSF_ID_C
init|=
literal|2
block|,
name|IWM_TSF_ID_D
init|=
literal|3
block|,
name|IWM_NUM_TSF_IDS
init|=
literal|4
block|, }
enum|;
end_enum

begin_comment
comment|/* IWM_TSF_ID_API_E_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_mac_data_ap - configuration data for AP MAC context  * @beacon_time: beacon transmit time in system time  * @beacon_tsf: beacon transmit time in TSF  * @bi: beacon interval in TU  * @bi_reciprocal: 2^32 / bi  * @dtim_interval: dtim transmit time in TU  * @dtim_reciprocal: 2^32 / dtim_interval  * @mcast_qid: queue ID for multicast traffic  * @beacon_template: beacon template ID  */
end_comment

begin_struct
struct|struct
name|iwm_mac_data_ap
block|{
name|uint32_t
name|beacon_time
decl_stmt|;
name|uint64_t
name|beacon_tsf
decl_stmt|;
name|uint32_t
name|bi
decl_stmt|;
name|uint32_t
name|bi_reciprocal
decl_stmt|;
name|uint32_t
name|dtim_interval
decl_stmt|;
name|uint32_t
name|dtim_reciprocal
decl_stmt|;
name|uint32_t
name|mcast_qid
decl_stmt|;
name|uint32_t
name|beacon_template
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* AP_MAC_DATA_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_mac_data_ibss - configuration data for IBSS MAC context  * @beacon_time: beacon transmit time in system time  * @beacon_tsf: beacon transmit time in TSF  * @bi: beacon interval in TU  * @bi_reciprocal: 2^32 / bi  * @beacon_template: beacon template ID  */
end_comment

begin_struct
struct|struct
name|iwm_mac_data_ibss
block|{
name|uint32_t
name|beacon_time
decl_stmt|;
name|uint64_t
name|beacon_tsf
decl_stmt|;
name|uint32_t
name|bi
decl_stmt|;
name|uint32_t
name|bi_reciprocal
decl_stmt|;
name|uint32_t
name|beacon_template
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IBSS_MAC_DATA_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_mac_data_sta - configuration data for station MAC context  * @is_assoc: 1 for associated state, 0 otherwise  * @dtim_time: DTIM arrival time in system time  * @dtim_tsf: DTIM arrival time in TSF  * @bi: beacon interval in TU, applicable only when associated  * @bi_reciprocal: 2^32 / bi , applicable only when associated  * @dtim_interval: DTIM interval in TU, applicable only when associated  * @dtim_reciprocal: 2^32 / dtim_interval , applicable only when associated  * @listen_interval: in beacon intervals, applicable only when associated  * @assoc_id: unique ID assigned by the AP during association  */
end_comment

begin_struct
struct|struct
name|iwm_mac_data_sta
block|{
name|uint32_t
name|is_assoc
decl_stmt|;
name|uint32_t
name|dtim_time
decl_stmt|;
name|uint64_t
name|dtim_tsf
decl_stmt|;
name|uint32_t
name|bi
decl_stmt|;
name|uint32_t
name|bi_reciprocal
decl_stmt|;
name|uint32_t
name|dtim_interval
decl_stmt|;
name|uint32_t
name|dtim_reciprocal
decl_stmt|;
name|uint32_t
name|listen_interval
decl_stmt|;
name|uint32_t
name|assoc_id
decl_stmt|;
name|uint32_t
name|assoc_beacon_arrive_time
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_STA_MAC_DATA_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_mac_data_go - configuration data for P2P GO MAC context  * @ap: iwm_mac_data_ap struct with most config data  * @ctwin: client traffic window in TU (period after TBTT when GO is present).  *	0 indicates that there is no CT window.  * @opp_ps_enabled: indicate that opportunistic PS allowed  */
end_comment

begin_struct
struct|struct
name|iwm_mac_data_go
block|{
name|struct
name|iwm_mac_data_ap
name|ap
decl_stmt|;
name|uint32_t
name|ctwin
decl_stmt|;
name|uint32_t
name|opp_ps_enabled
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* GO_MAC_DATA_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_mac_data_p2p_sta - configuration data for P2P client MAC context  * @sta: iwm_mac_data_sta struct with most config data  * @ctwin: client traffic window in TU (period after TBTT when GO is present).  *	0 indicates that there is no CT window.  */
end_comment

begin_struct
struct|struct
name|iwm_mac_data_p2p_sta
block|{
name|struct
name|iwm_mac_data_sta
name|sta
decl_stmt|;
name|uint32_t
name|ctwin
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* P2P_STA_MAC_DATA_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_mac_data_pibss - Pseudo IBSS config data  * @stats_interval: interval in TU between statistics notifications to host.  */
end_comment

begin_struct
struct|struct
name|iwm_mac_data_pibss
block|{
name|uint32_t
name|stats_interval
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* PIBSS_MAC_DATA_API_S_VER_1 */
end_comment

begin_comment
comment|/*  * struct iwm_mac_data_p2p_dev - configuration data for the P2P Device MAC  * context.  * @is_disc_extended: if set to true, P2P Device discoverability is enabled on  *	other channels as well. This should be to true only in case that the  *	device is discoverable and there is an active GO. Note that setting this  *	field when not needed, will increase the number of interrupts and have  *	effect on the platform power, as this setting opens the Rx filters on  *	all macs.  */
end_comment

begin_struct
struct|struct
name|iwm_mac_data_p2p_dev
block|{
name|uint32_t
name|is_disc_extended
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* _P2P_DEV_MAC_DATA_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * enum iwm_mac_filter_flags - MAC context filter flags  * @IWM_MAC_FILTER_IN_PROMISC: accept all data frames  * @IWM_MAC_FILTER_IN_CONTROL_AND_MGMT: pass all mangement and  *	control frames to the host  * @IWM_MAC_FILTER_ACCEPT_GRP: accept multicast frames  * @IWM_MAC_FILTER_DIS_DECRYPT: don't decrypt unicast frames  * @IWM_MAC_FILTER_DIS_GRP_DECRYPT: don't decrypt multicast frames  * @IWM_MAC_FILTER_IN_BEACON: transfer foreign BSS's beacons to host  *	(in station mode when associated)  * @IWM_MAC_FILTER_OUT_BCAST: filter out all broadcast frames  * @IWM_MAC_FILTER_IN_CRC32: extract FCS and append it to frames  * @IWM_MAC_FILTER_IN_PROBE_REQUEST: pass probe requests to host  */
end_comment

begin_enum
enum|enum
name|iwm_mac_filter_flags
block|{
name|IWM_MAC_FILTER_IN_PROMISC
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_MAC_FILTER_IN_CONTROL_AND_MGMT
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_MAC_FILTER_ACCEPT_GRP
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_MAC_FILTER_DIS_DECRYPT
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_MAC_FILTER_DIS_GRP_DECRYPT
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|IWM_MAC_FILTER_IN_BEACON
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|IWM_MAC_FILTER_OUT_BCAST
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
name|IWM_MAC_FILTER_IN_CRC32
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|,
name|IWM_MAC_FILTER_IN_PROBE_REQUEST
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum iwm_mac_qos_flags - QoS flags  * @IWM_MAC_QOS_FLG_UPDATE_EDCA: ?  * @IWM_MAC_QOS_FLG_TGN: HT is enabled  * @IWM_MAC_QOS_FLG_TXOP_TYPE: ?  *  */
end_comment

begin_enum
enum|enum
name|iwm_mac_qos_flags
block|{
name|IWM_MAC_QOS_FLG_UPDATE_EDCA
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_MAC_QOS_FLG_TGN
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_MAC_QOS_FLG_TXOP_TYPE
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_ac_qos - QOS timing params for IWM_MAC_CONTEXT_CMD  * @cw_min: Contention window, start value in numbers of slots.  *	Should be a power-of-2, minus 1.  Device's default is 0x0f.  * @cw_max: Contention window, max value in numbers of slots.  *	Should be a power-of-2, minus 1.  Device's default is 0x3f.  * @aifsn:  Number of slots in Arbitration Interframe Space (before  *	performing random backoff timing prior to Tx).  Device default 1.  * @fifos_mask: FIFOs used by this MAC for this AC  * @edca_txop:  Length of Tx opportunity, in uSecs.  Device default is 0.  *  * One instance of this config struct for each of 4 EDCA access categories  * in struct iwm_qosparam_cmd.  *  * Device will automatically increase contention window by (2*CW) + 1 for each  * transmission retry.  Device uses cw_max as a bit mask, ANDed with new CW  * value, to cap the CW value.  */
end_comment

begin_struct
struct|struct
name|iwm_ac_qos
block|{
name|uint16_t
name|cw_min
decl_stmt|;
name|uint16_t
name|cw_max
decl_stmt|;
name|uint8_t
name|aifsn
decl_stmt|;
name|uint8_t
name|fifos_mask
decl_stmt|;
name|uint16_t
name|edca_txop
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_AC_QOS_API_S_VER_2 */
end_comment

begin_comment
comment|/**  * struct iwm_mac_ctx_cmd - command structure to configure MAC contexts  * ( IWM_MAC_CONTEXT_CMD = 0x28 )  * @id_and_color: ID and color of the MAC  * @action: action to perform, one of IWM_FW_CTXT_ACTION_*  * @mac_type: one of IWM_FW_MAC_TYPE_*  * @tsd_id: TSF HW timer, one of IWM_TSF_ID_*  * @node_addr: MAC address  * @bssid_addr: BSSID  * @cck_rates: basic rates available for CCK  * @ofdm_rates: basic rates available for OFDM  * @protection_flags: combination of IWM_MAC_PROT_FLG_FLAG_*  * @cck_short_preamble: 0x20 for enabling short preamble, 0 otherwise  * @short_slot: 0x10 for enabling short slots, 0 otherwise  * @filter_flags: combination of IWM_MAC_FILTER_*  * @qos_flags: from IWM_MAC_QOS_FLG_*  * @ac: one iwm_mac_qos configuration for each AC  * @mac_specific: one of struct iwm_mac_data_*, according to mac_type  */
end_comment

begin_struct
struct|struct
name|iwm_mac_ctx_cmd
block|{
comment|/* COMMON_INDEX_HDR_API_S_VER_1 */
name|uint32_t
name|id_and_color
decl_stmt|;
name|uint32_t
name|action
decl_stmt|;
comment|/* IWM_MAC_CONTEXT_COMMON_DATA_API_S_VER_1 */
name|uint32_t
name|mac_type
decl_stmt|;
name|uint32_t
name|tsf_id
decl_stmt|;
name|uint8_t
name|node_addr
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|reserved_for_node_addr
decl_stmt|;
name|uint8_t
name|bssid_addr
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|reserved_for_bssid_addr
decl_stmt|;
name|uint32_t
name|cck_rates
decl_stmt|;
name|uint32_t
name|ofdm_rates
decl_stmt|;
name|uint32_t
name|protection_flags
decl_stmt|;
name|uint32_t
name|cck_short_preamble
decl_stmt|;
name|uint32_t
name|short_slot
decl_stmt|;
name|uint32_t
name|filter_flags
decl_stmt|;
comment|/* IWM_MAC_QOS_PARAM_API_S_VER_1 */
name|uint32_t
name|qos_flags
decl_stmt|;
name|struct
name|iwm_ac_qos
name|ac
index|[
name|IWM_AC_NUM
operator|+
literal|1
index|]
decl_stmt|;
comment|/* IWM_MAC_CONTEXT_COMMON_DATA_API_S */
union|union
block|{
name|struct
name|iwm_mac_data_ap
name|ap
decl_stmt|;
name|struct
name|iwm_mac_data_go
name|go
decl_stmt|;
name|struct
name|iwm_mac_data_sta
name|sta
decl_stmt|;
name|struct
name|iwm_mac_data_p2p_sta
name|p2p_sta
decl_stmt|;
name|struct
name|iwm_mac_data_p2p_dev
name|p2p_dev
decl_stmt|;
name|struct
name|iwm_mac_data_pibss
name|pibss
decl_stmt|;
name|struct
name|iwm_mac_data_ibss
name|ibss
decl_stmt|;
block|}
union|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_MAC_CONTEXT_CMD_API_S_VER_1 */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|iwm_mvm_reciprocal
parameter_list|(
name|uint32_t
name|v
parameter_list|)
block|{
if|if
condition|(
operator|!
name|v
condition|)
return|return
literal|0
return|;
return|return
literal|0xFFFFFFFF
operator|/
name|v
return|;
block|}
end_function

begin_define
define|#
directive|define
name|IWM_NONQOS_SEQ_GET
value|0x1
end_define

begin_define
define|#
directive|define
name|IWM_NONQOS_SEQ_SET
value|0x2
end_define

begin_struct
struct|struct
name|iwm_nonqos_seq_query_cmd
block|{
name|uint32_t
name|get_set_flag
decl_stmt|;
name|uint32_t
name|mac_id_n_color
decl_stmt|;
name|uint16_t
name|value
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_NON_QOS_TX_COUNTER_GET_SET_API_S_VER_1 */
end_comment

begin_comment
comment|/*  * END mvm/fw-api-mac.h  */
end_comment

begin_comment
comment|/*  * BEGIN mvm/fw-api-power.h  */
end_comment

begin_comment
comment|/* Power Management Commands, Responses, Notifications */
end_comment

begin_comment
comment|/* Radio LP RX Energy Threshold measured in dBm */
end_comment

begin_define
define|#
directive|define
name|IWM_POWER_LPRX_RSSI_THRESHOLD
value|75
end_define

begin_define
define|#
directive|define
name|IWM_POWER_LPRX_RSSI_THRESHOLD_MAX
value|94
end_define

begin_define
define|#
directive|define
name|IWM_POWER_LPRX_RSSI_THRESHOLD_MIN
value|30
end_define

begin_comment
comment|/**  * enum iwm_scan_flags - masks for power table command flags  * @IWM_POWER_FLAGS_POWER_SAVE_ENA_MSK: '1' Allow to save power by turning off  *		receiver and transmitter. '0' - does not allow.  * @IWM_POWER_FLAGS_POWER_MANAGEMENT_ENA_MSK: '0' Driver disables power management,  *		'1' Driver enables PM (use rest of parameters)  * @IWM_POWER_FLAGS_SKIP_OVER_DTIM_MSK: '0' PM have to walk up every DTIM,  *		'1' PM could sleep over DTIM till listen Interval.  * @IWM_POWER_FLAGS_SNOOZE_ENA_MSK: Enable snoozing only if uAPSD is enabled and all  *		access categories are both delivery and trigger enabled.  * @IWM_POWER_FLAGS_BT_SCO_ENA: Enable BT SCO coex only if uAPSD and  *		PBW Snoozing enabled  * @IWM_POWER_FLAGS_ADVANCE_PM_ENA_MSK: Advanced PM (uAPSD) enable mask  * @IWM_POWER_FLAGS_LPRX_ENA_MSK: Low Power RX enable.  * @IWM_POWER_FLAGS_AP_UAPSD_MISBEHAVING_ENA_MSK: AP/GO's uAPSD misbehaving  *		detection enablement */
end_comment

begin_enum
enum|enum
name|iwm_power_flags
block|{
name|IWM_POWER_FLAGS_POWER_SAVE_ENA_MSK
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_POWER_FLAGS_POWER_MANAGEMENT_ENA_MSK
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_POWER_FLAGS_SKIP_OVER_DTIM_MSK
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_POWER_FLAGS_SNOOZE_ENA_MSK
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|IWM_POWER_FLAGS_BT_SCO_ENA
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
name|IWM_POWER_FLAGS_ADVANCE_PM_ENA_MSK
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
name|IWM_POWER_FLAGS_LPRX_ENA_MSK
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|,
name|IWM_POWER_FLAGS_UAPSD_MISBEHAVING_ENA_MSK
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_POWER_VEC_SIZE
value|5
end_define

begin_comment
comment|/**  * struct iwm_powertable_cmd - legacy power command. Beside old API support this  *	is used also with a new	power API for device wide power settings.  * IWM_POWER_TABLE_CMD = 0x77 (command, has simple generic response)  *  * @flags:		Power table command flags from IWM_POWER_FLAGS_*  * @keep_alive_seconds: Keep alive period in seconds. Default - 25 sec.  *			Minimum allowed:- 3 * DTIM. Keep alive period must be  *			set regardless of power scheme or current power state.  *			FW use this value also when PM is disabled.  * @rx_data_timeout:    Minimum time (usec) from last Rx packet for AM to  *			PSM transition - legacy PM  * @tx_data_timeout:    Minimum time (usec) from last Tx packet for AM to  *			PSM transition - legacy PM  * @sleep_interval:	not in use  * @skip_dtim_periods:	Number of DTIM periods to skip if Skip over DTIM flag  *			is set. For example, if it is required to skip over  *			one DTIM, this value need to be set to 2 (DTIM periods).  * @lprx_rssi_threshold: Signal strength up to which LP RX can be enabled.  *			Default: 80dbm  */
end_comment

begin_struct
struct|struct
name|iwm_powertable_cmd
block|{
comment|/* PM_POWER_TABLE_CMD_API_S_VER_6 */
name|uint16_t
name|flags
decl_stmt|;
name|uint8_t
name|keep_alive_seconds
decl_stmt|;
name|uint8_t
name|debug_flags
decl_stmt|;
name|uint32_t
name|rx_data_timeout
decl_stmt|;
name|uint32_t
name|tx_data_timeout
decl_stmt|;
name|uint32_t
name|sleep_interval
index|[
name|IWM_POWER_VEC_SIZE
index|]
decl_stmt|;
name|uint32_t
name|skip_dtim_periods
decl_stmt|;
name|uint32_t
name|lprx_rssi_threshold
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * enum iwm_device_power_flags - masks for device power command flags  * @IWM_DEVICE_POWER_FLAGS_POWER_SAVE_ENA_MSK: '1' Allow to save power by turning off  *	receiver and transmitter. '0' - does not allow.  */
end_comment

begin_enum
enum|enum
name|iwm_device_power_flags
block|{
name|IWM_DEVICE_POWER_FLAGS_POWER_SAVE_ENA_MSK
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_device_power_cmd - device wide power command.  * IWM_DEVICE_POWER_CMD = 0x77 (command, has simple generic response)  *  * @flags:	Power table command flags from IWM_DEVICE_POWER_FLAGS_*  */
end_comment

begin_struct
struct|struct
name|iwm_device_power_cmd
block|{
comment|/* PM_POWER_TABLE_CMD_API_S_VER_6 */
name|uint16_t
name|flags
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * struct iwm_mac_power_cmd - New power command containing uAPSD support  * IWM_MAC_PM_POWER_TABLE = 0xA9 (command, has simple generic response)  * @id_and_color:	MAC contex identifier  * @flags:		Power table command flags from POWER_FLAGS_*  * @keep_alive_seconds:	Keep alive period in seconds. Default - 25 sec.  *			Minimum allowed:- 3 * DTIM. Keep alive period must be  *			set regardless of power scheme or current power state.  *			FW use this value also when PM is disabled.  * @rx_data_timeout:    Minimum time (usec) from last Rx packet for AM to  *			PSM transition - legacy PM  * @tx_data_timeout:    Minimum time (usec) from last Tx packet for AM to  *			PSM transition - legacy PM  * @sleep_interval:	not in use  * @skip_dtim_periods:	Number of DTIM periods to skip if Skip over DTIM flag  *			is set. For example, if it is required to skip over  *			one DTIM, this value need to be set to 2 (DTIM periods).  * @rx_data_timeout_uapsd: Minimum time (usec) from last Rx packet for AM to  *			PSM transition - uAPSD  * @tx_data_timeout_uapsd: Minimum time (usec) from last Tx packet for AM to  *			PSM transition - uAPSD  * @lprx_rssi_threshold: Signal strength up to which LP RX can be enabled.  *			Default: 80dbm  * @num_skip_dtim:	Number of DTIMs to skip if Skip over DTIM flag is set  * @snooze_interval:	Maximum time between attempts to retrieve buffered data  *			from the AP [msec]  * @snooze_window:	A window of time in which PBW snoozing insures that all  *			packets received. It is also the minimum time from last  *			received unicast RX packet, before client stops snoozing  *			for data. [msec]  * @snooze_step:	TBD  * @qndp_tid:		TID client shall use for uAPSD QNDP triggers  * @uapsd_ac_flags:	Set trigger-enabled and delivery-enabled indication for  *			each corresponding AC.  *			Use IEEE80211_WMM_IE_STA_QOSINFO_AC* for correct values.  * @uapsd_max_sp:	Use IEEE80211_WMM_IE_STA_QOSINFO_SP_* for correct  *			values.  * @heavy_tx_thld_packets:	TX threshold measured in number of packets  * @heavy_rx_thld_packets:	RX threshold measured in number of packets  * @heavy_tx_thld_percentage:	TX threshold measured in load's percentage  * @heavy_rx_thld_percentage:	RX threshold measured in load's percentage  * @limited_ps_threshold: */
end_comment

begin_struct
struct|struct
name|iwm_mac_power_cmd
block|{
comment|/* CONTEXT_DESC_API_T_VER_1 */
name|uint32_t
name|id_and_color
decl_stmt|;
comment|/* CLIENT_PM_POWER_TABLE_S_VER_1 */
name|uint16_t
name|flags
decl_stmt|;
name|uint16_t
name|keep_alive_seconds
decl_stmt|;
name|uint32_t
name|rx_data_timeout
decl_stmt|;
name|uint32_t
name|tx_data_timeout
decl_stmt|;
name|uint32_t
name|rx_data_timeout_uapsd
decl_stmt|;
name|uint32_t
name|tx_data_timeout_uapsd
decl_stmt|;
name|uint8_t
name|lprx_rssi_threshold
decl_stmt|;
name|uint8_t
name|skip_dtim_periods
decl_stmt|;
name|uint16_t
name|snooze_interval
decl_stmt|;
name|uint16_t
name|snooze_window
decl_stmt|;
name|uint8_t
name|snooze_step
decl_stmt|;
name|uint8_t
name|qndp_tid
decl_stmt|;
name|uint8_t
name|uapsd_ac_flags
decl_stmt|;
name|uint8_t
name|uapsd_max_sp
decl_stmt|;
name|uint8_t
name|heavy_tx_thld_packets
decl_stmt|;
name|uint8_t
name|heavy_rx_thld_packets
decl_stmt|;
name|uint8_t
name|heavy_tx_thld_percentage
decl_stmt|;
name|uint8_t
name|heavy_rx_thld_percentage
decl_stmt|;
name|uint8_t
name|limited_ps_threshold
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * struct iwm_uapsd_misbehaving_ap_notif - FW sends this notification when  * associated AP is identified as improperly implementing uAPSD protocol.  * IWM_PSM_UAPSD_AP_MISBEHAVING_NOTIFICATION = 0x78  * @sta_id: index of station in uCode's station table - associated AP ID in  *	    this context.  */
end_comment

begin_struct
struct|struct
name|iwm_uapsd_misbehaving_ap_notif
block|{
name|uint32_t
name|sta_id
decl_stmt|;
name|uint8_t
name|mac_id
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * struct iwm_beacon_filter_cmd  * IWM_REPLY_BEACON_FILTERING_CMD = 0xd2 (command)  * @id_and_color: MAC contex identifier  * @bf_energy_delta: Used for RSSI filtering, if in 'normal' state. Send beacon  *      to driver if delta in Energy values calculated for this and last  *      passed beacon is greater than this threshold. Zero value means that  *      the Energy change is ignored for beacon filtering, and beacon will  *      not be forced to be sent to driver regardless of this delta. Typical  *      energy delta 5dB.  * @bf_roaming_energy_delta: Used for RSSI filtering, if in 'roaming' state.  *      Send beacon to driver if delta in Energy values calculated for this  *      and last passed beacon is greater than this threshold. Zero value  *      means that the Energy change is ignored for beacon filtering while in  *      Roaming state, typical energy delta 1dB.  * @bf_roaming_state: Used for RSSI filtering. If absolute Energy values  *      calculated for current beacon is less than the threshold, use  *      Roaming Energy Delta Threshold, otherwise use normal Energy Delta  *      Threshold. Typical energy threshold is -72dBm.  * @bf_temp_threshold: This threshold determines the type of temperature  *	filtering (Slow or Fast) that is selected (Units are in Celsuis):  *      If the current temperature is above this threshold - Fast filter  *	will be used, If the current temperature is below this threshold -  *	Slow filter will be used.  * @bf_temp_fast_filter: Send Beacon to driver if delta in temperature values  *      calculated for this and the last passed beacon is greater than this  *      threshold. Zero value means that the temperature change is ignored for  *      beacon filtering; beacons will not be  forced to be sent to driver  *      regardless of whether its temperature has been changed.  * @bf_temp_slow_filter: Send Beacon to driver if delta in temperature values  *      calculated for this and the last passed beacon is greater than this  *      threshold. Zero value means that the temperature change is ignored for  *      beacon filtering; beacons will not be forced to be sent to driver  *      regardless of whether its temperature has been changed.  * @bf_enable_beacon_filter: 1, beacon filtering is enabled; 0, disabled.  * @bf_filter_escape_timer: Send beacons to to driver if no beacons were passed  *      for a specific period of time. Units: Beacons.  * @ba_escape_timer: Fully receive and parse beacon if no beacons were passed  *      for a longer period of time then this escape-timeout. Units: Beacons.  * @ba_enable_beacon_abort: 1, beacon abort is enabled; 0, disabled.  */
end_comment

begin_struct
struct|struct
name|iwm_beacon_filter_cmd
block|{
name|uint32_t
name|bf_energy_delta
decl_stmt|;
name|uint32_t
name|bf_roaming_energy_delta
decl_stmt|;
name|uint32_t
name|bf_roaming_state
decl_stmt|;
name|uint32_t
name|bf_temp_threshold
decl_stmt|;
name|uint32_t
name|bf_temp_fast_filter
decl_stmt|;
name|uint32_t
name|bf_temp_slow_filter
decl_stmt|;
name|uint32_t
name|bf_enable_beacon_filter
decl_stmt|;
name|uint32_t
name|bf_debug_flag
decl_stmt|;
name|uint32_t
name|bf_escape_timer
decl_stmt|;
name|uint32_t
name|ba_escape_timer
decl_stmt|;
name|uint32_t
name|ba_enable_beacon_abort
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Beacon filtering and beacon abort */
end_comment

begin_define
define|#
directive|define
name|IWM_BF_ENERGY_DELTA_DEFAULT
value|5
end_define

begin_define
define|#
directive|define
name|IWM_BF_ENERGY_DELTA_MAX
value|255
end_define

begin_define
define|#
directive|define
name|IWM_BF_ENERGY_DELTA_MIN
value|0
end_define

begin_define
define|#
directive|define
name|IWM_BF_ROAMING_ENERGY_DELTA_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|IWM_BF_ROAMING_ENERGY_DELTA_MAX
value|255
end_define

begin_define
define|#
directive|define
name|IWM_BF_ROAMING_ENERGY_DELTA_MIN
value|0
end_define

begin_define
define|#
directive|define
name|IWM_BF_ROAMING_STATE_DEFAULT
value|72
end_define

begin_define
define|#
directive|define
name|IWM_BF_ROAMING_STATE_MAX
value|255
end_define

begin_define
define|#
directive|define
name|IWM_BF_ROAMING_STATE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|IWM_BF_TEMP_THRESHOLD_DEFAULT
value|112
end_define

begin_define
define|#
directive|define
name|IWM_BF_TEMP_THRESHOLD_MAX
value|255
end_define

begin_define
define|#
directive|define
name|IWM_BF_TEMP_THRESHOLD_MIN
value|0
end_define

begin_define
define|#
directive|define
name|IWM_BF_TEMP_FAST_FILTER_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|IWM_BF_TEMP_FAST_FILTER_MAX
value|255
end_define

begin_define
define|#
directive|define
name|IWM_BF_TEMP_FAST_FILTER_MIN
value|0
end_define

begin_define
define|#
directive|define
name|IWM_BF_TEMP_SLOW_FILTER_DEFAULT
value|5
end_define

begin_define
define|#
directive|define
name|IWM_BF_TEMP_SLOW_FILTER_MAX
value|255
end_define

begin_define
define|#
directive|define
name|IWM_BF_TEMP_SLOW_FILTER_MIN
value|0
end_define

begin_define
define|#
directive|define
name|IWM_BF_ENABLE_BEACON_FILTER_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|IWM_BF_DEBUG_FLAG_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|IWM_BF_ESCAPE_TIMER_DEFAULT
value|50
end_define

begin_define
define|#
directive|define
name|IWM_BF_ESCAPE_TIMER_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|IWM_BF_ESCAPE_TIMER_MIN
value|0
end_define

begin_define
define|#
directive|define
name|IWM_BA_ESCAPE_TIMER_DEFAULT
value|6
end_define

begin_define
define|#
directive|define
name|IWM_BA_ESCAPE_TIMER_D3
value|9
end_define

begin_define
define|#
directive|define
name|IWM_BA_ESCAPE_TIMER_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|IWM_BA_ESCAPE_TIMER_MIN
value|0
end_define

begin_define
define|#
directive|define
name|IWM_BA_ENABLE_BEACON_ABORT_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|IWM_BF_CMD_CONFIG_DEFAULTS
define|\
value|.bf_energy_delta = htole32(IWM_BF_ENERGY_DELTA_DEFAULT),	     \ 	.bf_roaming_energy_delta =					     \ 		htole32(IWM_BF_ROAMING_ENERGY_DELTA_DEFAULT),	     \ 	.bf_roaming_state = htole32(IWM_BF_ROAMING_STATE_DEFAULT),	     \ 	.bf_temp_threshold = htole32(IWM_BF_TEMP_THRESHOLD_DEFAULT),     \ 	.bf_temp_fast_filter = htole32(IWM_BF_TEMP_FAST_FILTER_DEFAULT), \ 	.bf_temp_slow_filter = htole32(IWM_BF_TEMP_SLOW_FILTER_DEFAULT), \ 	.bf_debug_flag = htole32(IWM_BF_DEBUG_FLAG_DEFAULT),	     \ 	.bf_escape_timer = htole32(IWM_BF_ESCAPE_TIMER_DEFAULT),	     \ 	.ba_escape_timer = htole32(IWM_BA_ESCAPE_TIMER_DEFAULT)
end_define

begin_comment
comment|/*  * END mvm/fw-api-power.h  */
end_comment

begin_comment
comment|/*  * BEGIN mvm/fw-api-rs.h  */
end_comment

begin_comment
comment|/*  * These serve as indexes into  * struct iwm_rate_info fw_rate_idx_to_plcp[IWM_RATE_COUNT];  * TODO: avoid overlap between legacy and HT rates  */
end_comment

begin_enum
enum|enum
block|{
name|IWM_RATE_1M_INDEX
init|=
literal|0
block|,
name|IWM_FIRST_CCK_RATE
init|=
name|IWM_RATE_1M_INDEX
block|,
name|IWM_RATE_2M_INDEX
block|,
name|IWM_RATE_5M_INDEX
block|,
name|IWM_RATE_11M_INDEX
block|,
name|IWM_LAST_CCK_RATE
init|=
name|IWM_RATE_11M_INDEX
block|,
name|IWM_RATE_6M_INDEX
block|,
name|IWM_FIRST_OFDM_RATE
init|=
name|IWM_RATE_6M_INDEX
block|,
name|IWM_RATE_MCS_0_INDEX
init|=
name|IWM_RATE_6M_INDEX
block|,
name|IWM_FIRST_HT_RATE
init|=
name|IWM_RATE_MCS_0_INDEX
block|,
name|IWM_FIRST_VHT_RATE
init|=
name|IWM_RATE_MCS_0_INDEX
block|,
name|IWM_RATE_9M_INDEX
block|,
name|IWM_RATE_12M_INDEX
block|,
name|IWM_RATE_MCS_1_INDEX
init|=
name|IWM_RATE_12M_INDEX
block|,
name|IWM_RATE_18M_INDEX
block|,
name|IWM_RATE_MCS_2_INDEX
init|=
name|IWM_RATE_18M_INDEX
block|,
name|IWM_RATE_24M_INDEX
block|,
name|IWM_RATE_MCS_3_INDEX
init|=
name|IWM_RATE_24M_INDEX
block|,
name|IWM_RATE_36M_INDEX
block|,
name|IWM_RATE_MCS_4_INDEX
init|=
name|IWM_RATE_36M_INDEX
block|,
name|IWM_RATE_48M_INDEX
block|,
name|IWM_RATE_MCS_5_INDEX
init|=
name|IWM_RATE_48M_INDEX
block|,
name|IWM_RATE_54M_INDEX
block|,
name|IWM_RATE_MCS_6_INDEX
init|=
name|IWM_RATE_54M_INDEX
block|,
name|IWM_LAST_NON_HT_RATE
init|=
name|IWM_RATE_54M_INDEX
block|,
name|IWM_RATE_60M_INDEX
block|,
name|IWM_RATE_MCS_7_INDEX
init|=
name|IWM_RATE_60M_INDEX
block|,
name|IWM_LAST_HT_RATE
init|=
name|IWM_RATE_MCS_7_INDEX
block|,
name|IWM_RATE_MCS_8_INDEX
block|,
name|IWM_RATE_MCS_9_INDEX
block|,
name|IWM_LAST_VHT_RATE
init|=
name|IWM_RATE_MCS_9_INDEX
block|,
name|IWM_RATE_COUNT_LEGACY
init|=
name|IWM_LAST_NON_HT_RATE
operator|+
literal|1
block|,
name|IWM_RATE_COUNT
init|=
name|IWM_LAST_VHT_RATE
operator|+
literal|1
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_RATE_BIT_MSK
parameter_list|(
name|r
parameter_list|)
value|(1<< (IWM_RATE_##r##M_INDEX))
end_define

begin_comment
comment|/* fw API values for legacy bit rates, both OFDM and CCK */
end_comment

begin_enum
enum|enum
block|{
name|IWM_RATE_6M_PLCP
init|=
literal|13
block|,
name|IWM_RATE_9M_PLCP
init|=
literal|15
block|,
name|IWM_RATE_12M_PLCP
init|=
literal|5
block|,
name|IWM_RATE_18M_PLCP
init|=
literal|7
block|,
name|IWM_RATE_24M_PLCP
init|=
literal|9
block|,
name|IWM_RATE_36M_PLCP
init|=
literal|11
block|,
name|IWM_RATE_48M_PLCP
init|=
literal|1
block|,
name|IWM_RATE_54M_PLCP
init|=
literal|3
block|,
name|IWM_RATE_1M_PLCP
init|=
literal|10
block|,
name|IWM_RATE_2M_PLCP
init|=
literal|20
block|,
name|IWM_RATE_5M_PLCP
init|=
literal|55
block|,
name|IWM_RATE_11M_PLCP
init|=
literal|110
block|,
name|IWM_RATE_INVM_PLCP
init|=
operator|-
literal|1
block|, }
enum|;
end_enum

begin_comment
comment|/*  * rate_n_flags bit fields  *  * The 32-bit value has different layouts in the low 8 bites depending on the  * format. There are three formats, HT, VHT and legacy (11abg, with subformats  * for CCK and OFDM).  *  * High-throughput (HT) rate format  *	bit 8 is 1, bit 26 is 0, bit 9 is 0 (OFDM)  * Very High-throughput (VHT) rate format  *	bit 8 is 0, bit 26 is 1, bit 9 is 0 (OFDM)  * Legacy OFDM rate format for bits 7:0  *	bit 8 is 0, bit 26 is 0, bit 9 is 0 (OFDM)  * Legacy CCK rate format for bits 7:0:  *	bit 8 is 0, bit 26 is 0, bit 9 is 1 (CCK)  */
end_comment

begin_comment
comment|/* Bit 8: (1) HT format, (0) legacy or VHT format */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_MCS_HT_POS
value|8
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_HT_MSK
value|(1<< IWM_RATE_MCS_HT_POS)
end_define

begin_comment
comment|/* Bit 9: (1) CCK, (0) OFDM.  HT (bit 8) must be "0" for this bit to be valid */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_MCS_CCK_POS
value|9
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_CCK_MSK
value|(1<< IWM_RATE_MCS_CCK_POS)
end_define

begin_comment
comment|/* Bit 26: (1) VHT format, (0) legacy format in bits 8:0 */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_MCS_VHT_POS
value|26
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_VHT_MSK
value|(1<< IWM_RATE_MCS_VHT_POS)
end_define

begin_comment
comment|/*  * High-throughput (HT) rate format for bits 7:0  *  *  2-0:  MCS rate base  *        0)   6 Mbps  *        1)  12 Mbps  *        2)  18 Mbps  *        3)  24 Mbps  *        4)  36 Mbps  *        5)  48 Mbps  *        6)  54 Mbps  *        7)  60 Mbps  *  4-3:  0)  Single stream (SISO)  *        1)  Dual stream (MIMO)  *        2)  Triple stream (MIMO)  *    5:  Value of 0x20 in bits 7:0 indicates 6 Mbps HT40 duplicate data  *  (bits 7-6 are zero)  *  * Together the low 5 bits work out to the MCS index because we don't  * support MCSes above 15/23, and 0-7 have one stream, 8-15 have two  * streams and 16-23 have three streams. We could also support MCS 32  * which is the duplicate 20 MHz MCS (bit 5 set, all others zero.)  */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_HT_MCS_RATE_CODE_MSK
value|0x7
end_define

begin_define
define|#
directive|define
name|IWM_RATE_HT_MCS_NSS_POS
value|3
end_define

begin_define
define|#
directive|define
name|IWM_RATE_HT_MCS_NSS_MSK
value|(3<< IWM_RATE_HT_MCS_NSS_POS)
end_define

begin_comment
comment|/* Bit 10: (1) Use Green Field preamble */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_HT_MCS_GF_POS
value|10
end_define

begin_define
define|#
directive|define
name|IWM_RATE_HT_MCS_GF_MSK
value|(1<< IWM_RATE_HT_MCS_GF_POS)
end_define

begin_define
define|#
directive|define
name|IWM_RATE_HT_MCS_INDEX_MSK
value|0x3f
end_define

begin_comment
comment|/*  * Very High-throughput (VHT) rate format for bits 7:0  *  *  3-0:  VHT MCS (0-9)  *  5-4:  number of streams - 1:  *        0)  Single stream (SISO)  *        1)  Dual stream (MIMO)  *        2)  Triple stream (MIMO)  */
end_comment

begin_comment
comment|/* Bit 4-5: (0) SISO, (1) MIMO2 (2) MIMO3 */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_VHT_MCS_RATE_CODE_MSK
value|0xf
end_define

begin_define
define|#
directive|define
name|IWM_RATE_VHT_MCS_NSS_POS
value|4
end_define

begin_define
define|#
directive|define
name|IWM_RATE_VHT_MCS_NSS_MSK
value|(3<< IWM_RATE_VHT_MCS_NSS_POS)
end_define

begin_comment
comment|/*  * Legacy OFDM rate format for bits 7:0  *  *  3-0:  0xD)   6 Mbps  *        0xF)   9 Mbps  *        0x5)  12 Mbps  *        0x7)  18 Mbps  *        0x9)  24 Mbps  *        0xB)  36 Mbps  *        0x1)  48 Mbps  *        0x3)  54 Mbps  * (bits 7-4 are 0)  *  * Legacy CCK rate format for bits 7:0:  * bit 8 is 0, bit 26 is 0, bit 9 is 1 (CCK):  *  *  6-0:   10)  1 Mbps  *         20)  2 Mbps  *         55)  5.5 Mbps  *        110)  11 Mbps  * (bit 7 is 0)  */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_LEGACY_RATE_MSK
value|0xff
end_define

begin_comment
comment|/*  * Bit 11-12: (0) 20MHz, (1) 40MHz, (2) 80MHz, (3) 160MHz  * 0 and 1 are valid for HT and VHT, 2 and 3 only for VHT  */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_MCS_CHAN_WIDTH_POS
value|11
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_CHAN_WIDTH_MSK
value|(3<< IWM_RATE_MCS_CHAN_WIDTH_POS)
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_CHAN_WIDTH_20
value|(0<< IWM_RATE_MCS_CHAN_WIDTH_POS)
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_CHAN_WIDTH_40
value|(1<< IWM_RATE_MCS_CHAN_WIDTH_POS)
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_CHAN_WIDTH_80
value|(2<< IWM_RATE_MCS_CHAN_WIDTH_POS)
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_CHAN_WIDTH_160
value|(3<< IWM_RATE_MCS_CHAN_WIDTH_POS)
end_define

begin_comment
comment|/* Bit 13: (1) Short guard interval (0.4 usec), (0) normal GI (0.8 usec) */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_MCS_SGI_POS
value|13
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_SGI_MSK
value|(1<< IWM_RATE_MCS_SGI_POS)
end_define

begin_comment
comment|/* Bit 14-16: Antenna selection (1) Ant A, (2) Ant B, (4) Ant C */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_MCS_ANT_POS
value|14
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_ANT_A_MSK
value|(1<< IWM_RATE_MCS_ANT_POS)
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_ANT_B_MSK
value|(2<< IWM_RATE_MCS_ANT_POS)
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_ANT_C_MSK
value|(4<< IWM_RATE_MCS_ANT_POS)
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_ANT_AB_MSK
value|(IWM_RATE_MCS_ANT_A_MSK | \ 					 IWM_RATE_MCS_ANT_B_MSK)
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_ANT_ABC_MSK
value|(IWM_RATE_MCS_ANT_AB_MSK | \ 					 IWM_RATE_MCS_ANT_C_MSK)
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_ANT_MSK
value|IWM_RATE_MCS_ANT_ABC_MSK
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_ANT_NUM
value|3
end_define

begin_comment
comment|/* Bit 17-18: (0) SS, (1) SS*2 */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_MCS_STBC_POS
value|17
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_STBC_MSK
value|(1<< IWM_RATE_MCS_STBC_POS)
end_define

begin_comment
comment|/* Bit 19: (0) Beamforming is off, (1) Beamforming is on */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_MCS_BF_POS
value|19
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_BF_MSK
value|(1<< IWM_RATE_MCS_BF_POS)
end_define

begin_comment
comment|/* Bit 20: (0) ZLF is off, (1) ZLF is on */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_MCS_ZLF_POS
value|20
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_ZLF_MSK
value|(1<< IWM_RATE_MCS_ZLF_POS)
end_define

begin_comment
comment|/* Bit 24-25: (0) 20MHz (no dup), (1) 2x20MHz, (2) 4x20MHz, 3 8x20MHz */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_MCS_DUP_POS
value|24
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_DUP_MSK
value|(3<< IWM_RATE_MCS_DUP_POS)
end_define

begin_comment
comment|/* Bit 27: (1) LDPC enabled, (0) LDPC disabled */
end_comment

begin_define
define|#
directive|define
name|IWM_RATE_MCS_LDPC_POS
value|27
end_define

begin_define
define|#
directive|define
name|IWM_RATE_MCS_LDPC_MSK
value|(1<< IWM_RATE_MCS_LDPC_POS)
end_define

begin_comment
comment|/* Link Quality definitions */
end_comment

begin_comment
comment|/* # entries in rate scale table to support Tx retries */
end_comment

begin_define
define|#
directive|define
name|IWM_LQ_MAX_RETRY_NUM
value|16
end_define

begin_comment
comment|/* Link quality command flags bit fields */
end_comment

begin_comment
comment|/* Bit 0: (0) Don't use RTS (1) Use RTS */
end_comment

begin_define
define|#
directive|define
name|IWM_LQ_FLAG_USE_RTS_POS
value|0
end_define

begin_define
define|#
directive|define
name|IWM_LQ_FLAG_USE_RTS_MSK
value|(1<< IWM_LQ_FLAG_USE_RTS_POS)
end_define

begin_comment
comment|/* Bit 1-3: LQ command color. Used to match responses to LQ commands */
end_comment

begin_define
define|#
directive|define
name|IWM_LQ_FLAG_COLOR_POS
value|1
end_define

begin_define
define|#
directive|define
name|IWM_LQ_FLAG_COLOR_MSK
value|(7<< IWM_LQ_FLAG_COLOR_POS)
end_define

begin_comment
comment|/* Bit 4-5: Tx RTS BW Signalling  * (0) No RTS BW signalling  * (1) Static BW signalling  * (2) Dynamic BW signalling  */
end_comment

begin_define
define|#
directive|define
name|IWM_LQ_FLAG_RTS_BW_SIG_POS
value|4
end_define

begin_define
define|#
directive|define
name|IWM_LQ_FLAG_RTS_BW_SIG_NONE
value|(0<< IWM_LQ_FLAG_RTS_BW_SIG_POS)
end_define

begin_define
define|#
directive|define
name|IWM_LQ_FLAG_RTS_BW_SIG_STATIC
value|(1<< IWM_LQ_FLAG_RTS_BW_SIG_POS)
end_define

begin_define
define|#
directive|define
name|IWM_LQ_FLAG_RTS_BW_SIG_DYNAMIC
value|(2<< IWM_LQ_FLAG_RTS_BW_SIG_POS)
end_define

begin_comment
comment|/* Bit 6: (0) No dynamic BW selection (1) Allow dynamic BW selection  * Dyanmic BW selection allows Tx with narrower BW then requested in rates  */
end_comment

begin_define
define|#
directive|define
name|IWM_LQ_FLAG_DYNAMIC_BW_POS
value|6
end_define

begin_define
define|#
directive|define
name|IWM_LQ_FLAG_DYNAMIC_BW_MSK
value|(1<< IWM_LQ_FLAG_DYNAMIC_BW_POS)
end_define

begin_comment
comment|/**  * struct iwm_lq_cmd - link quality command  * @sta_id: station to update  * @control: not used  * @flags: combination of IWM_LQ_FLAG_*  * @mimo_delim: the first SISO index in rs_table, which separates MIMO  *	and SISO rates  * @single_stream_ant_msk: best antenna for SISO (can be dual in CDD).  *	Should be ANT_[ABC]  * @dual_stream_ant_msk: best antennas for MIMO, combination of ANT_[ABC]  * @initial_rate_index: first index from rs_table per AC category  * @agg_time_limit: aggregation max time threshold in usec/100, meaning  *	value of 100 is one usec. Range is 100 to 8000  * @agg_disable_start_th: try-count threshold for starting aggregation.  *	If a frame has higher try-count, it should not be selected for  *	starting an aggregation sequence.  * @agg_frame_cnt_limit: max frame count in an aggregation.  *	0: no limit  *	1: no aggregation (one frame per aggregation)  *	2 - 0x3f: maximal number of frames (up to 3f == 63)  * @rs_table: array of rates for each TX try, each is rate_n_flags,  *	meaning it is a combination of IWM_RATE_MCS_* and IWM_RATE_*_PLCP  * @bf_params: beam forming params, currently not used  */
end_comment

begin_struct
struct|struct
name|iwm_lq_cmd
block|{
name|uint8_t
name|sta_id
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint16_t
name|control
decl_stmt|;
comment|/* LINK_QUAL_GENERAL_PARAMS_API_S_VER_1 */
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|mimo_delim
decl_stmt|;
name|uint8_t
name|single_stream_ant_msk
decl_stmt|;
name|uint8_t
name|dual_stream_ant_msk
decl_stmt|;
name|uint8_t
name|initial_rate_index
index|[
name|IWM_AC_NUM
index|]
decl_stmt|;
comment|/* LINK_QUAL_AGG_PARAMS_API_S_VER_1 */
name|uint16_t
name|agg_time_limit
decl_stmt|;
name|uint8_t
name|agg_disable_start_th
decl_stmt|;
name|uint8_t
name|agg_frame_cnt_limit
decl_stmt|;
name|uint32_t
name|reserved2
decl_stmt|;
name|uint32_t
name|rs_table
index|[
name|IWM_LQ_MAX_RETRY_NUM
index|]
decl_stmt|;
name|uint32_t
name|bf_params
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* LINK_QUALITY_CMD_API_S_VER_1 */
end_comment

begin_comment
comment|/*  * END mvm/fw-api-rs.h  */
end_comment

begin_comment
comment|/*  * BEGIN mvm/fw-api-tx.h  */
end_comment

begin_comment
comment|/**  * enum iwm_tx_flags - bitmasks for tx_flags in TX command  * @IWM_TX_CMD_FLG_PROT_REQUIRE: use RTS or CTS-to-self to protect the frame  * @IWM_TX_CMD_FLG_ACK: expect ACK from receiving station  * @IWM_TX_CMD_FLG_STA_RATE: use RS table with initial index from the TX command.  *	Otherwise, use rate_n_flags from the TX command  * @IWM_TX_CMD_FLG_BA: this frame is a block ack  * @IWM_TX_CMD_FLG_BAR: this frame is a BA request, immediate BAR is expected  *	Must set IWM_TX_CMD_FLG_ACK with this flag.  * @IWM_TX_CMD_FLG_TXOP_PROT: protect frame with full TXOP protection  * @IWM_TX_CMD_FLG_VHT_NDPA: mark frame is NDPA for VHT beamformer sequence  * @IWM_TX_CMD_FLG_HT_NDPA: mark frame is NDPA for HT beamformer sequence  * @IWM_TX_CMD_FLG_CSI_FDBK2HOST: mark to send feedback to host (only if good CRC)  * @IWM_TX_CMD_FLG_BT_DIS: disable BT priority for this frame  * @IWM_TX_CMD_FLG_SEQ_CTL: set if FW should override the sequence control.  *	Should be set for mgmt, non-QOS data, mcast, bcast and in scan command  * @IWM_TX_CMD_FLG_MORE_FRAG: this frame is non-last MPDU  * @IWM_TX_CMD_FLG_NEXT_FRAME: this frame includes information of the next frame  * @IWM_TX_CMD_FLG_TSF: FW should calculate and insert TSF in the frame  *	Should be set for beacons and probe responses  * @IWM_TX_CMD_FLG_CALIB: activate PA TX power calibrations  * @IWM_TX_CMD_FLG_KEEP_SEQ_CTL: if seq_ctl is set, don't increase inner seq count  * @IWM_TX_CMD_FLG_AGG_START: allow this frame to start aggregation  * @IWM_TX_CMD_FLG_MH_PAD: driver inserted 2 byte padding after MAC header.  *	Should be set for 26/30 length MAC headers  * @IWM_TX_CMD_FLG_RESP_TO_DRV: zero this if the response should go only to FW  * @IWM_TX_CMD_FLG_TKIP_MIC_DONE: FW already performed TKIP MIC calculation  * @IWM_TX_CMD_FLG_DUR: disable duration overwriting used in PS-Poll Assoc-id  * @IWM_TX_CMD_FLG_FW_DROP: FW should mark frame to be dropped  * @IWM_TX_CMD_FLG_EXEC_PAPD: execute PAPD  * @IWM_TX_CMD_FLG_PAPD_TYPE: 0 for reference power, 1 for nominal power  * @IWM_TX_CMD_FLG_HCCA_CHUNK: mark start of TSPEC chunk  */
end_comment

begin_enum
enum|enum
name|iwm_tx_flags
block|{
name|IWM_TX_CMD_FLG_PROT_REQUIRE
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_TX_CMD_FLG_ACK
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_TX_CMD_FLG_STA_RATE
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|IWM_TX_CMD_FLG_BA
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|IWM_TX_CMD_FLG_BAR
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|IWM_TX_CMD_FLG_TXOP_PROT
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
name|IWM_TX_CMD_FLG_VHT_NDPA
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
name|IWM_TX_CMD_FLG_HT_NDPA
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
name|IWM_TX_CMD_FLG_CSI_FDBK2HOST
init|=
operator|(
literal|1
operator|<<
literal|10
operator|)
block|,
name|IWM_TX_CMD_FLG_BT_DIS
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|,
name|IWM_TX_CMD_FLG_SEQ_CTL
init|=
operator|(
literal|1
operator|<<
literal|13
operator|)
block|,
name|IWM_TX_CMD_FLG_MORE_FRAG
init|=
operator|(
literal|1
operator|<<
literal|14
operator|)
block|,
name|IWM_TX_CMD_FLG_NEXT_FRAME
init|=
operator|(
literal|1
operator|<<
literal|15
operator|)
block|,
name|IWM_TX_CMD_FLG_TSF
init|=
operator|(
literal|1
operator|<<
literal|16
operator|)
block|,
name|IWM_TX_CMD_FLG_CALIB
init|=
operator|(
literal|1
operator|<<
literal|17
operator|)
block|,
name|IWM_TX_CMD_FLG_KEEP_SEQ_CTL
init|=
operator|(
literal|1
operator|<<
literal|18
operator|)
block|,
name|IWM_TX_CMD_FLG_AGG_START
init|=
operator|(
literal|1
operator|<<
literal|19
operator|)
block|,
name|IWM_TX_CMD_FLG_MH_PAD
init|=
operator|(
literal|1
operator|<<
literal|20
operator|)
block|,
name|IWM_TX_CMD_FLG_RESP_TO_DRV
init|=
operator|(
literal|1
operator|<<
literal|21
operator|)
block|,
name|IWM_TX_CMD_FLG_TKIP_MIC_DONE
init|=
operator|(
literal|1
operator|<<
literal|23
operator|)
block|,
name|IWM_TX_CMD_FLG_DUR
init|=
operator|(
literal|1
operator|<<
literal|25
operator|)
block|,
name|IWM_TX_CMD_FLG_FW_DROP
init|=
operator|(
literal|1
operator|<<
literal|26
operator|)
block|,
name|IWM_TX_CMD_FLG_EXEC_PAPD
init|=
operator|(
literal|1
operator|<<
literal|27
operator|)
block|,
name|IWM_TX_CMD_FLG_PAPD_TYPE
init|=
operator|(
literal|1
operator|<<
literal|28
operator|)
block|,
name|IWM_TX_CMD_FLG_HCCA_CHUNK
init|=
operator|(
literal|1
operator|<<
literal|31
operator|)
block|}
enum|;
end_enum

begin_comment
comment|/* IWM_TX_FLAGS_BITS_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * enum iwm_tx_pm_timeouts - pm timeout values in TX command  * @IWM_PM_FRAME_NONE: no need to suspend sleep mode  * @IWM_PM_FRAME_MGMT: fw suspend sleep mode for 100TU  * @IWM_PM_FRAME_ASSOC: fw suspend sleep mode for 10sec  */
end_comment

begin_enum
enum|enum
name|iwm_tx_pm_timeouts
block|{
name|IWM_PM_FRAME_NONE
init|=
literal|0
block|,
name|IWM_PM_FRAME_MGMT
init|=
literal|2
block|,
name|IWM_PM_FRAME_ASSOC
init|=
literal|3
block|, }
enum|;
end_enum

begin_comment
comment|/*  * TX command security control  */
end_comment

begin_define
define|#
directive|define
name|IWM_TX_CMD_SEC_WEP
value|0x01
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_SEC_CCM
value|0x02
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_SEC_TKIP
value|0x03
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_SEC_EXT
value|0x04
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_SEC_MSK
value|0x07
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_SEC_WEP_KEY_IDX_POS
value|6
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_SEC_WEP_KEY_IDX_MSK
value|0xc0
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_SEC_KEY128
value|0x08
end_define

begin_comment
comment|/* TODO: how does these values are OK with only 16 bit variable??? */
end_comment

begin_comment
comment|/*  * TX command next frame info  *  * bits 0:2 - security control (IWM_TX_CMD_SEC_*)  * bit 3 - immediate ACK required  * bit 4 - rate is taken from STA table  * bit 5 - frame belongs to BA stream  * bit 6 - immediate BA response expected  * bit 7 - unused  * bits 8:15 - Station ID  * bits 16:31 - rate  */
end_comment

begin_define
define|#
directive|define
name|IWM_TX_CMD_NEXT_FRAME_ACK_MSK
value|(0x8)
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_NEXT_FRAME_STA_RATE_MSK
value|(0x10)
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_NEXT_FRAME_BA_MSK
value|(0x20)
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_NEXT_FRAME_IMM_BA_RSP_MSK
value|(0x40)
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_NEXT_FRAME_FLAGS_MSK
value|(0xf8)
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_NEXT_FRAME_STA_ID_MSK
value|(0xff00)
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_NEXT_FRAME_STA_ID_POS
value|(8)
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_NEXT_FRAME_RATE_MSK
value|(0xffff0000)
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_NEXT_FRAME_RATE_POS
value|(16)
end_define

begin_comment
comment|/*  * TX command Frame life time in us - to be written in pm_frame_timeout  */
end_comment

begin_define
define|#
directive|define
name|IWM_TX_CMD_LIFE_TIME_INFINITE
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|IWM_TX_CMD_LIFE_TIME_DEFAULT
value|2000000
end_define

begin_comment
comment|/* 2000 ms*/
end_comment

begin_define
define|#
directive|define
name|IWM_TX_CMD_LIFE_TIME_PROBE_RESP
value|40000
end_define

begin_comment
comment|/* 40 ms */
end_comment

begin_define
define|#
directive|define
name|IWM_TX_CMD_LIFE_TIME_EXPIRED_FRAME
value|0
end_define

begin_comment
comment|/*  * TID for non QoS frames - to be written in tid_tspec  */
end_comment

begin_define
define|#
directive|define
name|IWM_TID_NON_QOS
value|IWM_MAX_TID_COUNT
end_define

begin_comment
comment|/*  * Limits on the retransmissions - to be written in {data,rts}_retry_limit  */
end_comment

begin_define
define|#
directive|define
name|IWM_DEFAULT_TX_RETRY
value|15
end_define

begin_define
define|#
directive|define
name|IWM_MGMT_DFAULT_RETRY_LIMIT
value|3
end_define

begin_define
define|#
directive|define
name|IWM_RTS_DFAULT_RETRY_LIMIT
value|60
end_define

begin_define
define|#
directive|define
name|IWM_BAR_DFAULT_RETRY_LIMIT
value|60
end_define

begin_define
define|#
directive|define
name|IWM_LOW_RETRY_LIMIT
value|7
end_define

begin_comment
comment|/* TODO: complete documentation for try_cnt and btkill_cnt */
end_comment

begin_comment
comment|/**  * struct iwm_tx_cmd - TX command struct to FW  * ( IWM_TX_CMD = 0x1c )  * @len: in bytes of the payload, see below for details  * @next_frame_len: same as len, but for next frame (0 if not applicable)  *	Used for fragmentation and bursting, but not in 11n aggregation.  * @tx_flags: combination of IWM_TX_CMD_FLG_*  * @rate_n_flags: rate for *all* Tx attempts, if IWM_TX_CMD_FLG_STA_RATE_MSK is  *	cleared. Combination of IWM_RATE_MCS_*  * @sta_id: index of destination station in FW station table  * @sec_ctl: security control, IWM_TX_CMD_SEC_*  * @initial_rate_index: index into the rate table for initial TX attempt.  *	Applied if IWM_TX_CMD_FLG_STA_RATE_MSK is set, normally 0 for data frames.  * @key: security key  * @next_frame_flags: IWM_TX_CMD_SEC_* and IWM_TX_CMD_NEXT_FRAME_*  * @life_time: frame life time (usecs??)  * @dram_lsb_ptr: Physical address of scratch area in the command (try_cnt +  *	btkill_cnd + reserved), first 32 bits. "0" disables usage.  * @dram_msb_ptr: upper bits of the scratch physical address  * @rts_retry_limit: max attempts for RTS  * @data_retry_limit: max attempts to send the data packet  * @tid_spec: TID/tspec  * @pm_frame_timeout: PM TX frame timeout  * @driver_txop: duration od EDCA TXOP, in 32-usec units. Set this if not  *	specified by HCCA protocol  *  * The byte count (both len and next_frame_len) includes MAC header  * (24/26/30/32 bytes)  * + 2 bytes pad if 26/30 header size  * + 8 byte IV for CCM or TKIP (not used for WEP)  * + Data payload  * + 8-byte MIC (not used for CCM/WEP)  * It does not include post-MAC padding, i.e.,  * MIC (CCM) 8 bytes, ICV (WEP/TKIP/CKIP) 4 bytes, CRC 4 bytes.  * Range of len: 14-2342 bytes.  *  * After the struct fields the MAC header is placed, plus any padding,  * and then the actial payload.  */
end_comment

begin_struct
struct|struct
name|iwm_tx_cmd
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|next_frame_len
decl_stmt|;
name|uint32_t
name|tx_flags
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|try_cnt
decl_stmt|;
name|uint8_t
name|btkill_cnt
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|scratch
struct|;
comment|/* DRAM_SCRATCH_API_U_VER_1 */
name|uint32_t
name|rate_n_flags
decl_stmt|;
name|uint8_t
name|sta_id
decl_stmt|;
name|uint8_t
name|sec_ctl
decl_stmt|;
name|uint8_t
name|initial_rate_index
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint8_t
name|key
index|[
literal|16
index|]
decl_stmt|;
name|uint16_t
name|next_frame_flags
decl_stmt|;
name|uint16_t
name|reserved3
decl_stmt|;
name|uint32_t
name|life_time
decl_stmt|;
name|uint32_t
name|dram_lsb_ptr
decl_stmt|;
name|uint8_t
name|dram_msb_ptr
decl_stmt|;
name|uint8_t
name|rts_retry_limit
decl_stmt|;
name|uint8_t
name|data_retry_limit
decl_stmt|;
name|uint8_t
name|tid_tspec
decl_stmt|;
name|uint16_t
name|pm_frame_timeout
decl_stmt|;
name|uint16_t
name|driver_txop
decl_stmt|;
name|uint8_t
name|payload
index|[
literal|0
index|]
decl_stmt|;
name|struct
name|ieee80211_frame
name|hdr
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_TX_CMD_API_S_VER_3 */
end_comment

begin_comment
comment|/*  * TX response related data  */
end_comment

begin_comment
comment|/*  * enum iwm_tx_status - status that is returned by the fw after attempts to Tx  * @IWM_TX_STATUS_SUCCESS:  * @IWM_TX_STATUS_DIRECT_DONE:  * @IWM_TX_STATUS_POSTPONE_DELAY:  * @IWM_TX_STATUS_POSTPONE_FEW_BYTES:  * @IWM_TX_STATUS_POSTPONE_BT_PRIO:  * @IWM_TX_STATUS_POSTPONE_QUIET_PERIOD:  * @IWM_TX_STATUS_POSTPONE_CALC_TTAK:  * @IWM_TX_STATUS_FAIL_INTERNAL_CROSSED_RETRY:  * @IWM_TX_STATUS_FAIL_SHORT_LIMIT:  * @IWM_TX_STATUS_FAIL_LONG_LIMIT:  * @IWM_TX_STATUS_FAIL_UNDERRUN:  * @IWM_TX_STATUS_FAIL_DRAIN_FLOW:  * @IWM_TX_STATUS_FAIL_RFKILL_FLUSH:  * @IWM_TX_STATUS_FAIL_LIFE_EXPIRE:  * @IWM_TX_STATUS_FAIL_DEST_PS:  * @IWM_TX_STATUS_FAIL_HOST_ABORTED:  * @IWM_TX_STATUS_FAIL_BT_RETRY:  * @IWM_TX_STATUS_FAIL_STA_INVALID:  * @IWM_TX_TATUS_FAIL_FRAG_DROPPED:  * @IWM_TX_STATUS_FAIL_TID_DISABLE:  * @IWM_TX_STATUS_FAIL_FIFO_FLUSHED:  * @IWM_TX_STATUS_FAIL_SMALL_CF_POLL:  * @IWM_TX_STATUS_FAIL_FW_DROP:  * @IWM_TX_STATUS_FAIL_STA_COLOR_MISMATCH: mismatch between color of Tx cmd and  *	STA table  * @IWM_TX_FRAME_STATUS_INTERNAL_ABORT:  * @IWM_TX_MODE_MSK:  * @IWM_TX_MODE_NO_BURST:  * @IWM_TX_MODE_IN_BURST_SEQ:  * @IWM_TX_MODE_FIRST_IN_BURST:  * @IWM_TX_QUEUE_NUM_MSK:  *  * Valid only if frame_count =1  * TODO: complete documentation  */
end_comment

begin_enum
enum|enum
name|iwm_tx_status
block|{
name|IWM_TX_STATUS_MSK
init|=
literal|0x000000ff
block|,
name|IWM_TX_STATUS_SUCCESS
init|=
literal|0x01
block|,
name|IWM_TX_STATUS_DIRECT_DONE
init|=
literal|0x02
block|,
comment|/* postpone TX */
name|IWM_TX_STATUS_POSTPONE_DELAY
init|=
literal|0x40
block|,
name|IWM_TX_STATUS_POSTPONE_FEW_BYTES
init|=
literal|0x41
block|,
name|IWM_TX_STATUS_POSTPONE_BT_PRIO
init|=
literal|0x42
block|,
name|IWM_TX_STATUS_POSTPONE_QUIET_PERIOD
init|=
literal|0x43
block|,
name|IWM_TX_STATUS_POSTPONE_CALC_TTAK
init|=
literal|0x44
block|,
comment|/* abort TX */
name|IWM_TX_STATUS_FAIL_INTERNAL_CROSSED_RETRY
init|=
literal|0x81
block|,
name|IWM_TX_STATUS_FAIL_SHORT_LIMIT
init|=
literal|0x82
block|,
name|IWM_TX_STATUS_FAIL_LONG_LIMIT
init|=
literal|0x83
block|,
name|IWM_TX_STATUS_FAIL_UNDERRUN
init|=
literal|0x84
block|,
name|IWM_TX_STATUS_FAIL_DRAIN_FLOW
init|=
literal|0x85
block|,
name|IWM_TX_STATUS_FAIL_RFKILL_FLUSH
init|=
literal|0x86
block|,
name|IWM_TX_STATUS_FAIL_LIFE_EXPIRE
init|=
literal|0x87
block|,
name|IWM_TX_STATUS_FAIL_DEST_PS
init|=
literal|0x88
block|,
name|IWM_TX_STATUS_FAIL_HOST_ABORTED
init|=
literal|0x89
block|,
name|IWM_TX_STATUS_FAIL_BT_RETRY
init|=
literal|0x8a
block|,
name|IWM_TX_STATUS_FAIL_STA_INVALID
init|=
literal|0x8b
block|,
name|IWM_TX_STATUS_FAIL_FRAG_DROPPED
init|=
literal|0x8c
block|,
name|IWM_TX_STATUS_FAIL_TID_DISABLE
init|=
literal|0x8d
block|,
name|IWM_TX_STATUS_FAIL_FIFO_FLUSHED
init|=
literal|0x8e
block|,
name|IWM_TX_STATUS_FAIL_SMALL_CF_POLL
init|=
literal|0x8f
block|,
name|IWM_TX_STATUS_FAIL_FW_DROP
init|=
literal|0x90
block|,
name|IWM_TX_STATUS_FAIL_STA_COLOR_MISMATCH
init|=
literal|0x91
block|,
name|IWM_TX_STATUS_INTERNAL_ABORT
init|=
literal|0x92
block|,
name|IWM_TX_MODE_MSK
init|=
literal|0x00000f00
block|,
name|IWM_TX_MODE_NO_BURST
init|=
literal|0x00000000
block|,
name|IWM_TX_MODE_IN_BURST_SEQ
init|=
literal|0x00000100
block|,
name|IWM_TX_MODE_FIRST_IN_BURST
init|=
literal|0x00000200
block|,
name|IWM_TX_QUEUE_NUM_MSK
init|=
literal|0x0001f000
block|,
name|IWM_TX_NARROW_BW_MSK
init|=
literal|0x00060000
block|,
name|IWM_TX_NARROW_BW_1DIV2
init|=
literal|0x00020000
block|,
name|IWM_TX_NARROW_BW_1DIV4
init|=
literal|0x00040000
block|,
name|IWM_TX_NARROW_BW_1DIV8
init|=
literal|0x00060000
block|, }
enum|;
end_enum

begin_comment
comment|/*  * enum iwm_tx_agg_status - TX aggregation status  * @IWM_AGG_TX_STATE_STATUS_MSK:  * @IWM_AGG_TX_STATE_TRANSMITTED:  * @IWM_AGG_TX_STATE_UNDERRUN:  * @IWM_AGG_TX_STATE_BT_PRIO:  * @IWM_AGG_TX_STATE_FEW_BYTES:  * @IWM_AGG_TX_STATE_ABORT:  * @IWM_AGG_TX_STATE_LAST_SENT_TTL:  * @IWM_AGG_TX_STATE_LAST_SENT_TRY_CNT:  * @IWM_AGG_TX_STATE_LAST_SENT_BT_KILL:  * @IWM_AGG_TX_STATE_SCD_QUERY:  * @IWM_AGG_TX_STATE_TEST_BAD_CRC32:  * @IWM_AGG_TX_STATE_RESPONSE:  * @IWM_AGG_TX_STATE_DUMP_TX:  * @IWM_AGG_TX_STATE_DELAY_TX:  * @IWM_AGG_TX_STATE_TRY_CNT_MSK: Retry count for 1st frame in aggregation (retries  *	occur if tx failed for this frame when it was a member of a previous  *	aggregation block). If rate scaling is used, retry count indicates the  *	rate table entry used for all frames in the new agg.  *@ IWM_AGG_TX_STATE_SEQ_NUM_MSK: Command ID and sequence number of Tx command for  *	this frame  *  * TODO: complete documentation  */
end_comment

begin_enum
enum|enum
name|iwm_tx_agg_status
block|{
name|IWM_AGG_TX_STATE_STATUS_MSK
init|=
literal|0x00fff
block|,
name|IWM_AGG_TX_STATE_TRANSMITTED
init|=
literal|0x000
block|,
name|IWM_AGG_TX_STATE_UNDERRUN
init|=
literal|0x001
block|,
name|IWM_AGG_TX_STATE_BT_PRIO
init|=
literal|0x002
block|,
name|IWM_AGG_TX_STATE_FEW_BYTES
init|=
literal|0x004
block|,
name|IWM_AGG_TX_STATE_ABORT
init|=
literal|0x008
block|,
name|IWM_AGG_TX_STATE_LAST_SENT_TTL
init|=
literal|0x010
block|,
name|IWM_AGG_TX_STATE_LAST_SENT_TRY_CNT
init|=
literal|0x020
block|,
name|IWM_AGG_TX_STATE_LAST_SENT_BT_KILL
init|=
literal|0x040
block|,
name|IWM_AGG_TX_STATE_SCD_QUERY
init|=
literal|0x080
block|,
name|IWM_AGG_TX_STATE_TEST_BAD_CRC32
init|=
literal|0x0100
block|,
name|IWM_AGG_TX_STATE_RESPONSE
init|=
literal|0x1ff
block|,
name|IWM_AGG_TX_STATE_DUMP_TX
init|=
literal|0x200
block|,
name|IWM_AGG_TX_STATE_DELAY_TX
init|=
literal|0x400
block|,
name|IWM_AGG_TX_STATE_TRY_CNT_POS
init|=
literal|12
block|,
name|IWM_AGG_TX_STATE_TRY_CNT_MSK
init|=
literal|0xf
operator|<<
name|IWM_AGG_TX_STATE_TRY_CNT_POS
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_AGG_TX_STATE_LAST_SENT_MSK
value|(IWM_AGG_TX_STATE_LAST_SENT_TTL| \ 				     IWM_AGG_TX_STATE_LAST_SENT_TRY_CNT| \ 				     IWM_AGG_TX_STATE_LAST_SENT_BT_KILL)
end_define

begin_comment
comment|/*  * The mask below describes a status where we are absolutely sure that the MPDU  * wasn't sent. For BA/Underrun we cannot be that sure. All we know that we've  * written the bytes to the TXE, but we know nothing about what the DSP did.  */
end_comment

begin_define
define|#
directive|define
name|IWM_AGG_TX_STAT_FRAME_NOT_SENT
value|(IWM_AGG_TX_STATE_FEW_BYTES | \ 				    IWM_AGG_TX_STATE_ABORT | \ 				    IWM_AGG_TX_STATE_SCD_QUERY)
end_define

begin_comment
comment|/*  * IWM_REPLY_TX = 0x1c (response)  *  * This response may be in one of two slightly different formats, indicated  * by the frame_count field:  *  * 1)	No aggregation (frame_count == 1).  This reports Tx results for a single  *	frame. Multiple attempts, at various bit rates, may have been made for  *	this frame.  *  * 2)	Aggregation (frame_count> 1).  This reports Tx results for two or more  *	frames that used block-acknowledge.  All frames were transmitted at  *	same rate. Rate scaling may have been used if first frame in this new  *	agg block failed in previous agg block(s).  *  *	Note that, for aggregation, ACK (block-ack) status is not delivered  *	here; block-ack has not been received by the time the device records  *	this status.  *	This status relates to reasons the tx might have been blocked or aborted  *	within the device, rather than whether it was received successfully by  *	the destination station.  */
end_comment

begin_comment
comment|/**  * struct iwm_agg_tx_status - per packet TX aggregation status  * @status: enum iwm_tx_agg_status  * @sequence: Sequence # for this frame's Tx cmd (not SSN!)  */
end_comment

begin_struct
struct|struct
name|iwm_agg_tx_status
block|{
name|uint16_t
name|status
decl_stmt|;
name|uint16_t
name|sequence
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * definitions for initial rate index field  * bits [3:0] initial rate index  * bits [6:4] rate table color, used for the initial rate  * bit-7 invalid rate indication  */
end_comment

begin_define
define|#
directive|define
name|IWM_TX_RES_INIT_RATE_INDEX_MSK
value|0x0f
end_define

begin_define
define|#
directive|define
name|IWM_TX_RES_RATE_TABLE_COLOR_MSK
value|0x70
end_define

begin_define
define|#
directive|define
name|IWM_TX_RES_INV_RATE_INDEX_MSK
value|0x80
end_define

begin_define
define|#
directive|define
name|IWM_MVM_TX_RES_GET_TID
parameter_list|(
name|_ra_tid
parameter_list|)
value|((_ra_tid)& 0x0f)
end_define

begin_define
define|#
directive|define
name|IWM_MVM_TX_RES_GET_RA
parameter_list|(
name|_ra_tid
parameter_list|)
value|((_ra_tid)>> 4)
end_define

begin_comment
comment|/**  * struct iwm_mvm_tx_resp - notifies that fw is TXing a packet  * ( IWM_REPLY_TX = 0x1c )  * @frame_count: 1 no aggregation,>1 aggregation  * @bt_kill_count: num of times blocked by bluetooth (unused for agg)  * @failure_rts: num of failures due to unsuccessful RTS  * @failure_frame: num failures due to no ACK (unused for agg)  * @initial_rate: for non-agg: rate of the successful Tx. For agg: rate of the  *	Tx of all the batch. IWM_RATE_MCS_*  * @wireless_media_time: for non-agg: RTS + CTS + frame tx attempts time + ACK.  *	for agg: RTS + CTS + aggregation tx time + block-ack time.  *	in usec.  * @pa_status: tx power info  * @pa_integ_res_a: tx power info  * @pa_integ_res_b: tx power info  * @pa_integ_res_c: tx power info  * @measurement_req_id: tx power info  * @tfd_info: TFD information set by the FH  * @seq_ctl: sequence control from the Tx cmd  * @byte_cnt: byte count from the Tx cmd  * @tlc_info: TLC rate info  * @ra_tid: bits [3:0] = ra, bits [7:4] = tid  * @frame_ctrl: frame control  * @status: for non-agg:  frame status IWM_TX_STATUS_*  *	for agg: status of 1st frame, IWM_AGG_TX_STATE_*; other frame status fields  *	follow this one, up to frame_count.  *  * After the array of statuses comes the SSN of the SCD. Look at  * %iwm_mvm_get_scd_ssn for more details.  */
end_comment

begin_struct
struct|struct
name|iwm_mvm_tx_resp
block|{
name|uint8_t
name|frame_count
decl_stmt|;
name|uint8_t
name|bt_kill_count
decl_stmt|;
name|uint8_t
name|failure_rts
decl_stmt|;
name|uint8_t
name|failure_frame
decl_stmt|;
name|uint32_t
name|initial_rate
decl_stmt|;
name|uint16_t
name|wireless_media_time
decl_stmt|;
name|uint8_t
name|pa_status
decl_stmt|;
name|uint8_t
name|pa_integ_res_a
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|pa_integ_res_b
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|pa_integ_res_c
index|[
literal|3
index|]
decl_stmt|;
name|uint16_t
name|measurement_req_id
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint32_t
name|tfd_info
decl_stmt|;
name|uint16_t
name|seq_ctl
decl_stmt|;
name|uint16_t
name|byte_cnt
decl_stmt|;
name|uint8_t
name|tlc_info
decl_stmt|;
name|uint8_t
name|ra_tid
decl_stmt|;
name|uint16_t
name|frame_ctrl
decl_stmt|;
name|struct
name|iwm_agg_tx_status
name|status
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_TX_RSP_API_S_VER_3 */
end_comment

begin_comment
comment|/**  * struct iwm_mvm_ba_notif - notifies about reception of BA  * ( IWM_BA_NOTIF = 0xc5 )  * @sta_addr_lo32: lower 32 bits of the MAC address  * @sta_addr_hi16: upper 16 bits of the MAC address  * @sta_id: Index of recipient (BA-sending) station in fw's station table  * @tid: tid of the session  * @seq_ctl:  * @bitmap: the bitmap of the BA notification as seen in the air  * @scd_flow: the tx queue this BA relates to  * @scd_ssn: the index of the last contiguously sent packet  * @txed: number of Txed frames in this batch  * @txed_2_done: number of Acked frames in this batch  */
end_comment

begin_struct
struct|struct
name|iwm_mvm_ba_notif
block|{
name|uint32_t
name|sta_addr_lo32
decl_stmt|;
name|uint16_t
name|sta_addr_hi16
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint8_t
name|sta_id
decl_stmt|;
name|uint8_t
name|tid
decl_stmt|;
name|uint16_t
name|seq_ctl
decl_stmt|;
name|uint64_t
name|bitmap
decl_stmt|;
name|uint16_t
name|scd_flow
decl_stmt|;
name|uint16_t
name|scd_ssn
decl_stmt|;
name|uint8_t
name|txed
decl_stmt|;
name|uint8_t
name|txed_2_done
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * struct iwm_mac_beacon_cmd - beacon template command  * @tx: the tx commands associated with the beacon frame  * @template_id: currently equal to the mac context id of the coresponding  *  mac.  * @tim_idx: the offset of the tim IE in the beacon  * @tim_size: the length of the tim IE  * @frame: the template of the beacon frame  */
end_comment

begin_struct
struct|struct
name|iwm_mac_beacon_cmd
block|{
name|struct
name|iwm_tx_cmd
name|tx
decl_stmt|;
name|uint32_t
name|template_id
decl_stmt|;
name|uint32_t
name|tim_idx
decl_stmt|;
name|uint32_t
name|tim_size
decl_stmt|;
name|struct
name|ieee80211_frame
name|frame
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwm_beacon_notif
block|{
name|struct
name|iwm_mvm_tx_resp
name|beacon_notify_hdr
decl_stmt|;
name|uint64_t
name|tsf
decl_stmt|;
name|uint32_t
name|ibss_mgr_status
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * enum iwm_dump_control - dump (flush) control flags  * @IWM_DUMP_TX_FIFO_FLUSH: Dump MSDUs until the FIFO is empty  *	and the TFD queues are empty.  */
end_comment

begin_enum
enum|enum
name|iwm_dump_control
block|{
name|IWM_DUMP_TX_FIFO_FLUSH
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_tx_path_flush_cmd -- queue/FIFO flush command  * @queues_ctl: bitmap of queues to flush  * @flush_ctl: control flags  * @reserved: reserved  */
end_comment

begin_struct
struct|struct
name|iwm_tx_path_flush_cmd
block|{
name|uint32_t
name|queues_ctl
decl_stmt|;
name|uint16_t
name|flush_ctl
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_TX_PATH_FLUSH_CMD_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * iwm_mvm_get_scd_ssn - returns the SSN of the SCD  * @tx_resp: the Tx response from the fw (agg or non-agg)  *  * When the fw sends an AMPDU, it fetches the MPDUs one after the other. Since  * it can't know that everything will go well until the end of the AMPDU, it  * can't know in advance the number of MPDUs that will be sent in the current  * batch. This is why it writes the agg Tx response while it fetches the MPDUs.  * Hence, it can't know in advance what the SSN of the SCD will be at the end  * of the batch. This is why the SSN of the SCD is written at the end of the  * whole struct at a variable offset. This function knows how to cope with the  * variable offset and returns the SSN of the SCD.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|iwm_mvm_get_scd_ssn
parameter_list|(
name|struct
name|iwm_mvm_tx_resp
modifier|*
name|tx_resp
parameter_list|)
block|{
return|return
name|le32_to_cpup
argument_list|(
operator|(
name|uint32_t
operator|*
operator|)
operator|&
name|tx_resp
operator|->
name|status
operator|+
name|tx_resp
operator|->
name|frame_count
argument_list|)
operator|&
literal|0xfff
return|;
block|}
end_function

begin_comment
comment|/*  * END mvm/fw-api-tx.h  */
end_comment

begin_comment
comment|/*  * BEGIN mvm/fw-api-scan.h  */
end_comment

begin_comment
comment|/**  * struct iwm_scd_txq_cfg_cmd - New txq hw scheduler config command  * @token:  * @sta_id: station id  * @tid:  * @scd_queue: scheduler queue to confiug  * @enable: 1 queue enable, 0 queue disable  * @aggregate: 1 aggregated queue, 0 otherwise  * @tx_fifo: %enum iwm_mvm_tx_fifo  * @window: BA window size  * @ssn: SSN for the BA agreement  */
end_comment

begin_struct
struct|struct
name|iwm_scd_txq_cfg_cmd
block|{
name|uint8_t
name|token
decl_stmt|;
name|uint8_t
name|sta_id
decl_stmt|;
name|uint8_t
name|tid
decl_stmt|;
name|uint8_t
name|scd_queue
decl_stmt|;
name|uint8_t
name|enable
decl_stmt|;
name|uint8_t
name|aggregate
decl_stmt|;
name|uint8_t
name|tx_fifo
decl_stmt|;
name|uint8_t
name|window
decl_stmt|;
name|uint16_t
name|ssn
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SCD_QUEUE_CFG_CMD_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_scd_txq_cfg_rsp  * @token: taken from the command  * @sta_id: station id from the command  * @tid: tid from the command  * @scd_queue: scd_queue from the command  */
end_comment

begin_struct
struct|struct
name|iwm_scd_txq_cfg_rsp
block|{
name|uint8_t
name|token
decl_stmt|;
name|uint8_t
name|sta_id
decl_stmt|;
name|uint8_t
name|tid
decl_stmt|;
name|uint8_t
name|scd_queue
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SCD_QUEUE_CFG_RSP_API_S_VER_1 */
end_comment

begin_comment
comment|/* Scan Commands, Responses, Notifications */
end_comment

begin_comment
comment|/* Masks for iwm_scan_channel.type flags */
end_comment

begin_define
define|#
directive|define
name|IWM_SCAN_CHANNEL_TYPE_ACTIVE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IWM_SCAN_CHANNEL_NSSIDS
parameter_list|(
name|x
parameter_list|)
value|(((1<< (x)) - 1)<< 1)
end_define

begin_comment
comment|/* Max number of IEs for direct SSID scans in a command */
end_comment

begin_define
define|#
directive|define
name|IWM_PROBE_OPTION_MAX
value|20
end_define

begin_comment
comment|/**  * struct iwm_ssid_ie - directed scan network information element  *  * Up to 20 of these may appear in IWM_REPLY_SCAN_CMD,  * selected by "type" bit field in struct iwm_scan_channel;  * each channel may select different ssids from among the 20 entries.  * SSID IEs get transmitted in reverse order of entry.  */
end_comment

begin_struct
struct|struct
name|iwm_ssid_ie
block|{
name|uint8_t
name|id
decl_stmt|;
name|uint8_t
name|len
decl_stmt|;
name|uint8_t
name|ssid
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_SCAN_DIRECT_SSID_IE_API_S_VER_1 */
end_comment

begin_comment
comment|/* scan offload */
end_comment

begin_define
define|#
directive|define
name|IWM_SCAN_MAX_BLACKLIST_LEN
value|64
end_define

begin_define
define|#
directive|define
name|IWM_SCAN_SHORT_BLACKLIST_LEN
value|16
end_define

begin_define
define|#
directive|define
name|IWM_SCAN_MAX_PROFILES
value|11
end_define

begin_define
define|#
directive|define
name|IWM_SCAN_OFFLOAD_PROBE_REQ_SIZE
value|512
end_define

begin_comment
comment|/* Default watchdog (in MS) for scheduled scan iteration */
end_comment

begin_define
define|#
directive|define
name|IWM_SCHED_SCAN_WATCHDOG
value|cpu_to_le16(15000)
end_define

begin_define
define|#
directive|define
name|IWM_GOOD_CRC_TH_DEFAULT
value|cpu_to_le16(1)
end_define

begin_define
define|#
directive|define
name|IWM_CAN_ABORT_STATUS
value|1
end_define

begin_define
define|#
directive|define
name|IWM_FULL_SCAN_MULTIPLIER
value|5
end_define

begin_define
define|#
directive|define
name|IWM_FAST_SCHED_SCAN_ITERATIONS
value|3
end_define

begin_define
define|#
directive|define
name|IWM_MAX_SCHED_SCAN_PLANS
value|2
end_define

begin_comment
comment|/**  * iwm_scan_schedule_lmac - schedule of scan offload  * @delay:		delay between iterations, in seconds.  * @iterations:		num of scan iterations  * @full_scan_mul:	number of partial scans before each full scan  */
end_comment

begin_struct
struct|struct
name|iwm_scan_schedule_lmac
block|{
name|uint16_t
name|delay
decl_stmt|;
name|uint8_t
name|iterations
decl_stmt|;
name|uint8_t
name|full_scan_mul
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SCAN_SCHEDULE_API_S */
end_comment

begin_comment
comment|/**  * iwm_scan_req_tx_cmd - SCAN_REQ_TX_CMD_API_S  * @tx_flags: combination of TX_CMD_FLG_*  * @rate_n_flags: rate for *all* Tx attempts, if TX_CMD_FLG_STA_RATE_MSK is  *	cleared. Combination of RATE_MCS_*  * @sta_id: index of destination station in FW station table  * @reserved: for alignment and future use  */
end_comment

begin_struct
struct|struct
name|iwm_scan_req_tx_cmd
block|{
name|uint32_t
name|tx_flags
decl_stmt|;
name|uint32_t
name|rate_n_flags
decl_stmt|;
name|uint8_t
name|sta_id
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_enum
enum|enum
name|iwm_scan_channel_flags_lmac
block|{
name|IWM_UNIFIED_SCAN_CHANNEL_FULL
init|=
operator|(
literal|1
operator|<<
literal|27
operator|)
block|,
name|IWM_UNIFIED_SCAN_CHANNEL_PARTIAL
init|=
operator|(
literal|1
operator|<<
literal|28
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * iwm_scan_channel_cfg_lmac - SCAN_CHANNEL_CFG_S_VER2  * @flags:		bits 1-20: directed scan to i'th ssid  *			other bits&enum iwm_scan_channel_flags_lmac  * @channel_number:	channel number 1-13 etc  * @iter_count:		scan iteration on this channel  * @iter_interval:	interval in seconds between iterations on one channel  */
end_comment

begin_struct
struct|struct
name|iwm_scan_channel_cfg_lmac
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint16_t
name|channel_num
decl_stmt|;
name|uint16_t
name|iter_count
decl_stmt|;
name|uint32_t
name|iter_interval
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * iwm_scan_probe_segment - PROBE_SEGMENT_API_S_VER_1  * @offset: offset in the data block  * @len: length of the segment  */
end_comment

begin_struct
struct|struct
name|iwm_scan_probe_segment
block|{
name|uint16_t
name|offset
decl_stmt|;
name|uint16_t
name|len
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* iwm_scan_probe_req - PROBE_REQUEST_FRAME_API_S_VER_2  * @mac_header: first (and common) part of the probe  * @band_data: band specific data  * @common_data: last (and common) part of the probe  * @buf: raw data block  */
end_comment

begin_struct
struct|struct
name|iwm_scan_probe_req
block|{
name|struct
name|iwm_scan_probe_segment
name|mac_header
decl_stmt|;
name|struct
name|iwm_scan_probe_segment
name|band_data
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|iwm_scan_probe_segment
name|common_data
decl_stmt|;
name|uint8_t
name|buf
index|[
name|IWM_SCAN_OFFLOAD_PROBE_REQ_SIZE
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_enum
enum|enum
name|iwm_scan_channel_flags
block|{
name|IWM_SCAN_CHANNEL_FLAG_EBS
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_SCAN_CHANNEL_FLAG_EBS_ACCURATE
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_SCAN_CHANNEL_FLAG_CACHE_ADD
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/* iwm_scan_channel_opt - CHANNEL_OPTIMIZATION_API_S  * @flags: enum iwm_scan_channel_flags  * @non_ebs_ratio: defines the ratio of number of scan iterations where EBS is  *	involved.  *	1 - EBS is disabled.  *	2 - every second scan will be full scan(and so on).  */
end_comment

begin_struct
struct|struct
name|iwm_scan_channel_opt
block|{
name|uint16_t
name|flags
decl_stmt|;
name|uint16_t
name|non_ebs_ratio
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * iwm_mvm_lmac_scan_flags  * @IWM_MVM_LMAC_SCAN_FLAG_PASS_ALL: pass all beacons and probe responses  *      without filtering.  * @IWM_MVM_LMAC_SCAN_FLAG_PASSIVE: force passive scan on all channels  * @IWM_MVM_LMAC_SCAN_FLAG_PRE_CONNECTION: single channel scan  * @IWM_MVM_LMAC_SCAN_FLAG_ITER_COMPLETE: send iteration complete notification  * @IWM_MVM_LMAC_SCAN_FLAG_MULTIPLE_SSIDS multiple SSID matching  * @IWM_MVM_LMAC_SCAN_FLAG_FRAGMENTED: all passive scans will be fragmented  * @IWM_MVM_LMAC_SCAN_FLAGS_RRM_ENABLED: insert WFA vendor-specific TPC report  *      and DS parameter set IEs into probe requests.  * @IWM_MVM_LMAC_SCAN_FLAG_EXTENDED_DWELL: use extended dwell time on channels  *      1, 6 and 11.  * @IWM_MVM_LMAC_SCAN_FLAG_MATCH: Send match found notification on matches  */
end_comment

begin_enum
enum|enum
name|iwm_mvm_lmac_scan_flags
block|{
name|IWM_MVM_LMAC_SCAN_FLAG_PASS_ALL
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_MVM_LMAC_SCAN_FLAG_PASSIVE
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_MVM_LMAC_SCAN_FLAG_PRE_CONNECTION
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_MVM_LMAC_SCAN_FLAG_ITER_COMPLETE
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_MVM_LMAC_SCAN_FLAG_MULTIPLE_SSIDS
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|IWM_MVM_LMAC_SCAN_FLAG_FRAGMENTED
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|IWM_MVM_LMAC_SCAN_FLAGS_RRM_ENABLED
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|IWM_MVM_LMAC_SCAN_FLAG_EXTENDED_DWELL
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
name|IWM_MVM_LMAC_SCAN_FLAG_MATCH
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|iwm_scan_priority
block|{
name|IWM_SCAN_PRIORITY_LOW
block|,
name|IWM_SCAN_PRIORITY_MEDIUM
block|,
name|IWM_SCAN_PRIORITY_HIGH
block|, }
enum|;
end_enum

begin_comment
comment|/**  * iwm_scan_req_lmac - SCAN_REQUEST_CMD_API_S_VER_1  * @reserved1: for alignment and future use  * @channel_num: num of channels to scan  * @active-dwell: dwell time for active channels  * @passive-dwell: dwell time for passive channels  * @fragmented-dwell: dwell time for fragmented passive scan  * @extended_dwell: dwell time for channels 1, 6 and 11 (in certain cases)  * @reserved2: for alignment and future use  * @rx_chain_selct: PHY_RX_CHAIN_* flags  * @scan_flags:&enum iwm_mvm_lmac_scan_flags  * @max_out_time: max time (in TU) to be out of associated channel  * @suspend_time: pause scan this long (TUs) when returning to service channel  * @flags: RXON flags  * @filter_flags: RXON filter  * @tx_cmd: tx command for active scan; for 2GHz and for 5GHz  * @direct_scan: list of SSIDs for directed active scan  * @scan_prio: enum iwm_scan_priority  * @iter_num: number of scan iterations  * @delay: delay in seconds before first iteration  * @schedule: two scheduling plans. The first one is finite, the second one can  *	be infinite.  * @channel_opt: channel optimization options, for full and partial scan  * @data: channel configuration and probe request packet.  */
end_comment

begin_struct
struct|struct
name|iwm_scan_req_lmac
block|{
comment|/* SCAN_REQUEST_FIXED_PART_API_S_VER_7 */
name|uint32_t
name|reserved1
decl_stmt|;
name|uint8_t
name|n_channels
decl_stmt|;
name|uint8_t
name|active_dwell
decl_stmt|;
name|uint8_t
name|passive_dwell
decl_stmt|;
name|uint8_t
name|fragmented_dwell
decl_stmt|;
name|uint8_t
name|extended_dwell
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint16_t
name|rx_chain_select
decl_stmt|;
name|uint32_t
name|scan_flags
decl_stmt|;
name|uint32_t
name|max_out_time
decl_stmt|;
name|uint32_t
name|suspend_time
decl_stmt|;
comment|/* RX_ON_FLAGS_API_S_VER_1 */
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|filter_flags
decl_stmt|;
name|struct
name|iwm_scan_req_tx_cmd
name|tx_cmd
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|iwm_ssid_ie
name|direct_scan
index|[
name|IWM_PROBE_OPTION_MAX
index|]
decl_stmt|;
name|uint32_t
name|scan_prio
decl_stmt|;
comment|/* SCAN_REQ_PERIODIC_PARAMS_API_S */
name|uint32_t
name|iter_num
decl_stmt|;
name|uint32_t
name|delay
decl_stmt|;
name|struct
name|iwm_scan_schedule_lmac
name|schedule
index|[
name|IWM_MAX_SCHED_SCAN_PLANS
index|]
decl_stmt|;
name|struct
name|iwm_scan_channel_opt
name|channel_opt
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|data
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * iwm_scan_offload_complete - PERIODIC_SCAN_COMPLETE_NTF_API_S_VER_2  * @last_schedule_line: last schedule line executed (fast or regular)  * @last_schedule_iteration: last scan iteration executed before scan abort  * @status: enum iwm_scan_offload_complete_status  * @ebs_status: EBS success status&enum iwm_scan_ebs_status  * @time_after_last_iter; time in seconds elapsed after last iteration  */
end_comment

begin_struct
struct|struct
name|iwm_periodic_scan_complete
block|{
name|uint8_t
name|last_schedule_line
decl_stmt|;
name|uint8_t
name|last_schedule_iteration
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|ebs_status
decl_stmt|;
name|uint32_t
name|time_after_last_iter
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* How many statistics are gathered for each channel */
end_comment

begin_define
define|#
directive|define
name|IWM_SCAN_RESULTS_STATISTICS
value|1
end_define

begin_comment
comment|/**  * enum iwm_scan_complete_status - status codes for scan complete notifications  * @IWM_SCAN_COMP_STATUS_OK:  scan completed successfully  * @IWM_SCAN_COMP_STATUS_ABORT: scan was aborted by user  * @IWM_SCAN_COMP_STATUS_ERR_SLEEP: sending null sleep packet failed  * @IWM_SCAN_COMP_STATUS_ERR_CHAN_TIMEOUT: timeout before channel is ready  * @IWM_SCAN_COMP_STATUS_ERR_PROBE: sending probe request failed  * @IWM_SCAN_COMP_STATUS_ERR_WAKEUP: sending null wakeup packet failed  * @IWM_SCAN_COMP_STATUS_ERR_ANTENNAS: invalid antennas chosen at scan command  * @IWM_SCAN_COMP_STATUS_ERR_INTERNAL: internal error caused scan abort  * @IWM_SCAN_COMP_STATUS_ERR_COEX: medium was lost ot WiMax  * @IWM_SCAN_COMP_STATUS_P2P_ACTION_OK: P2P public action frame TX was successful  *	(not an error!)  * @IWM_SCAN_COMP_STATUS_ITERATION_END: indicates end of one repeatition the driver  *	asked for  * @IWM_SCAN_COMP_STATUS_ERR_ALLOC_TE: scan could not allocate time events */
end_comment

begin_enum
enum|enum
name|iwm_scan_complete_status
block|{
name|IWM_SCAN_COMP_STATUS_OK
init|=
literal|0x1
block|,
name|IWM_SCAN_COMP_STATUS_ABORT
init|=
literal|0x2
block|,
name|IWM_SCAN_COMP_STATUS_ERR_SLEEP
init|=
literal|0x3
block|,
name|IWM_SCAN_COMP_STATUS_ERR_CHAN_TIMEOUT
init|=
literal|0x4
block|,
name|IWM_SCAN_COMP_STATUS_ERR_PROBE
init|=
literal|0x5
block|,
name|IWM_SCAN_COMP_STATUS_ERR_WAKEUP
init|=
literal|0x6
block|,
name|IWM_SCAN_COMP_STATUS_ERR_ANTENNAS
init|=
literal|0x7
block|,
name|IWM_SCAN_COMP_STATUS_ERR_INTERNAL
init|=
literal|0x8
block|,
name|IWM_SCAN_COMP_STATUS_ERR_COEX
init|=
literal|0x9
block|,
name|IWM_SCAN_COMP_STATUS_P2P_ACTION_OK
init|=
literal|0xA
block|,
name|IWM_SCAN_COMP_STATUS_ITERATION_END
init|=
literal|0x0B
block|,
name|IWM_SCAN_COMP_STATUS_ERR_ALLOC_TE
init|=
literal|0x0C
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_scan_results_notif - scan results for one channel  * ( IWM_SCAN_RESULTS_NOTIFICATION = 0x83 )  * @channel: which channel the results are from  * @band: 0 for 5.2 GHz, 1 for 2.4 GHz  * @probe_status: IWM_SCAN_PROBE_STATUS_*, indicates success of probe request  * @num_probe_not_sent: # of request that weren't sent due to not enough time  * @duration: duration spent in channel, in usecs  * @statistics: statistics gathered for this channel  */
end_comment

begin_struct
struct|struct
name|iwm_scan_results_notif
block|{
name|uint8_t
name|channel
decl_stmt|;
name|uint8_t
name|band
decl_stmt|;
name|uint8_t
name|probe_status
decl_stmt|;
name|uint8_t
name|num_probe_not_sent
decl_stmt|;
name|uint32_t
name|duration
decl_stmt|;
name|uint32_t
name|statistics
index|[
name|IWM_SCAN_RESULTS_STATISTICS
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_SCAN_RESULT_NTF_API_S_VER_2 */
end_comment

begin_enum
enum|enum
name|iwm_scan_framework_client
block|{
name|IWM_SCAN_CLIENT_SCHED_SCAN
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_SCAN_CLIENT_NETDETECT
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_SCAN_CLIENT_ASSET_TRACKING
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * iwm_scan_offload_blacklist - IWM_SCAN_OFFLOAD_BLACKLIST_S  * @ssid:		MAC address to filter out  * @reported_rssi:	AP rssi reported to the host  * @client_bitmap: clients ignore this entry  - enum scan_framework_client  */
end_comment

begin_struct
struct|struct
name|iwm_scan_offload_blacklist
block|{
name|uint8_t
name|ssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|reported_rssi
decl_stmt|;
name|uint8_t
name|client_bitmap
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_enum
enum|enum
name|iwm_scan_offload_network_type
block|{
name|IWM_NETWORK_TYPE_BSS
init|=
literal|1
block|,
name|IWM_NETWORK_TYPE_IBSS
init|=
literal|2
block|,
name|IWM_NETWORK_TYPE_ANY
init|=
literal|3
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|iwm_scan_offload_band_selection
block|{
name|IWM_SCAN_OFFLOAD_SELECT_2_4
init|=
literal|0x4
block|,
name|IWM_SCAN_OFFLOAD_SELECT_5_2
init|=
literal|0x8
block|,
name|IWM_SCAN_OFFLOAD_SELECT_ANY
init|=
literal|0xc
block|, }
enum|;
end_enum

begin_comment
comment|/**  * iwm_scan_offload_profile - IWM_SCAN_OFFLOAD_PROFILE_S  * @ssid_index:		index to ssid list in fixed part  * @unicast_cipher:	encryption olgorithm to match - bitmap  * @aut_alg:		authentication olgorithm to match - bitmap  * @network_type:	enum iwm_scan_offload_network_type  * @band_selection:	enum iwm_scan_offload_band_selection  * @client_bitmap:	clients waiting for match - enum scan_framework_client  */
end_comment

begin_struct
struct|struct
name|iwm_scan_offload_profile
block|{
name|uint8_t
name|ssid_index
decl_stmt|;
name|uint8_t
name|unicast_cipher
decl_stmt|;
name|uint8_t
name|auth_alg
decl_stmt|;
name|uint8_t
name|network_type
decl_stmt|;
name|uint8_t
name|band_selection
decl_stmt|;
name|uint8_t
name|client_bitmap
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * iwm_scan_offload_profile_cfg - IWM_SCAN_OFFLOAD_PROFILES_CFG_API_S_VER_1  * @blaclist:		AP list to filter off from scan results  * @profiles:		profiles to search for match  * @blacklist_len:	length of blacklist  * @num_profiles:	num of profiles in the list  * @match_notify:	clients waiting for match found notification  * @pass_match:		clients waiting for the results  * @active_clients:	active clients bitmap - enum scan_framework_client  * @any_beacon_notify:	clients waiting for match notification without match  */
end_comment

begin_struct
struct|struct
name|iwm_scan_offload_profile_cfg
block|{
name|struct
name|iwm_scan_offload_profile
name|profiles
index|[
name|IWM_SCAN_MAX_PROFILES
index|]
decl_stmt|;
name|uint8_t
name|blacklist_len
decl_stmt|;
name|uint8_t
name|num_profiles
decl_stmt|;
name|uint8_t
name|match_notify
decl_stmt|;
name|uint8_t
name|pass_match
decl_stmt|;
name|uint8_t
name|active_clients
decl_stmt|;
name|uint8_t
name|any_beacon_notify
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_enum
enum|enum
name|iwm_scan_offload_complete_status
block|{
name|IWM_SCAN_OFFLOAD_COMPLETED
init|=
literal|1
block|,
name|IWM_SCAN_OFFLOAD_ABORTED
init|=
literal|2
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|iwm_scan_ebs_status
block|{
name|IWM_SCAN_EBS_SUCCESS
block|,
name|IWM_SCAN_EBS_FAILED
block|,
name|IWM_SCAN_EBS_CHAN_NOT_FOUND
block|,
name|IWM_SCAN_EBS_INACTIVE
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_lmac_scan_complete_notif - notifies end of scanning (all channels)  *	SCAN_COMPLETE_NTF_API_S_VER_3  * @scanned_channels: number of channels scanned (and number of valid results)  * @status: one of SCAN_COMP_STATUS_*  * @bt_status: BT on/off status  * @last_channel: last channel that was scanned  * @tsf_low: TSF timer (lower half) in usecs  * @tsf_high: TSF timer (higher half) in usecs  * @results: an array of scan results, only "scanned_channels" of them are valid  */
end_comment

begin_struct
struct|struct
name|iwm_lmac_scan_complete_notif
block|{
name|uint8_t
name|scanned_channels
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|bt_status
decl_stmt|;
name|uint8_t
name|last_channel
decl_stmt|;
name|uint32_t
name|tsf_low
decl_stmt|;
name|uint32_t
name|tsf_high
decl_stmt|;
name|struct
name|iwm_scan_results_notif
name|results
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * END mvm/fw-api-scan.h  */
end_comment

begin_comment
comment|/*  * BEGIN mvm/fw-api-sta.h  */
end_comment

begin_comment
comment|/* UMAC Scan API */
end_comment

begin_comment
comment|/* The maximum of either of these cannot exceed 8, because we use an  * 8-bit mask (see IWM_MVM_SCAN_MASK).  */
end_comment

begin_define
define|#
directive|define
name|IWM_MVM_MAX_UMAC_SCANS
value|8
end_define

begin_define
define|#
directive|define
name|IWM_MVM_MAX_LMAC_SCANS
value|1
end_define

begin_enum
enum|enum
name|iwm_scan_config_flags
block|{
name|IWM_SCAN_CONFIG_FLAG_ACTIVATE
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_DEACTIVATE
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_FORBID_CHUB_REQS
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_ALLOW_CHUB_REQS
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_SET_TX_CHAINS
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_SET_RX_CHAINS
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_SET_AUX_STA_ID
init|=
operator|(
literal|1
operator|<<
literal|10
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_SET_ALL_TIMES
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_SET_EFFECTIVE_TIMES
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_SET_CHANNEL_FLAGS
init|=
operator|(
literal|1
operator|<<
literal|13
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_SET_LEGACY_RATES
init|=
operator|(
literal|1
operator|<<
literal|14
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_SET_MAC_ADDR
init|=
operator|(
literal|1
operator|<<
literal|15
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_SET_FRAGMENTED
init|=
operator|(
literal|1
operator|<<
literal|16
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_CLEAR_FRAGMENTED
init|=
operator|(
literal|1
operator|<<
literal|17
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_SET_CAM_MODE
init|=
operator|(
literal|1
operator|<<
literal|18
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_CLEAR_CAM_MODE
init|=
operator|(
literal|1
operator|<<
literal|19
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_SET_PROMISC_MODE
init|=
operator|(
literal|1
operator|<<
literal|20
operator|)
block|,
name|IWM_SCAN_CONFIG_FLAG_CLEAR_PROMISC_MODE
init|=
operator|(
literal|1
operator|<<
literal|21
operator|)
block|,
comment|/* Bits 26-31 are for num of channels in channel_array */
define|#
directive|define
name|IWM_SCAN_CONFIG_N_CHANNELS
parameter_list|(
name|n
parameter_list|)
value|((n)<< 26)
block|}
enum|;
end_enum

begin_enum
enum|enum
name|iwm_scan_config_rates
block|{
comment|/* OFDM basic rates */
name|IWM_SCAN_CONFIG_RATE_6M
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_SCAN_CONFIG_RATE_9M
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_SCAN_CONFIG_RATE_12M
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_SCAN_CONFIG_RATE_18M
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_SCAN_CONFIG_RATE_24M
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|IWM_SCAN_CONFIG_RATE_36M
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|IWM_SCAN_CONFIG_RATE_48M
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|IWM_SCAN_CONFIG_RATE_54M
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
comment|/* CCK basic rates */
name|IWM_SCAN_CONFIG_RATE_1M
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
name|IWM_SCAN_CONFIG_RATE_2M
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
name|IWM_SCAN_CONFIG_RATE_5M
init|=
operator|(
literal|1
operator|<<
literal|10
operator|)
block|,
name|IWM_SCAN_CONFIG_RATE_11M
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|,
comment|/* Bits 16-27 are for supported rates */
define|#
directive|define
name|IWM_SCAN_CONFIG_SUPPORTED_RATE
parameter_list|(
name|rate
parameter_list|)
value|((rate)<< 16)
block|}
enum|;
end_enum

begin_enum
enum|enum
name|iwm_channel_flags
block|{
name|IWM_CHANNEL_FLAG_EBS
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_CHANNEL_FLAG_ACCURATE_EBS
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_CHANNEL_FLAG_EBS_ADD
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_CHANNEL_FLAG_PRE_SCAN_PASSIVE2ACTIVE
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_scan_config  * @flags:			enum scan_config_flags  * @tx_chains:			valid_tx antenna - ANT_* definitions  * @rx_chains:			valid_rx antenna - ANT_* definitions  * @legacy_rates:		default legacy rates - enum scan_config_rates  * @out_of_channel_time:	default max out of serving channel time  * @suspend_time:		default max suspend time  * @dwell_active:		default dwell time for active scan  * @dwell_passive:		default dwell time for passive scan  * @dwell_fragmented:		default dwell time for fragmented scan  * @dwell_extended:		default dwell time for channels 1, 6 and 11  * @mac_addr:			default mac address to be used in probes  * @bcast_sta_id:		the index of the station in the fw  * @channel_flags:		default channel flags - enum iwm_channel_flags  *				scan_config_channel_flag  * @channel_array:		default supported channels  */
end_comment

begin_struct
struct|struct
name|iwm_scan_config
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|tx_chains
decl_stmt|;
name|uint32_t
name|rx_chains
decl_stmt|;
name|uint32_t
name|legacy_rates
decl_stmt|;
name|uint32_t
name|out_of_channel_time
decl_stmt|;
name|uint32_t
name|suspend_time
decl_stmt|;
name|uint8_t
name|dwell_active
decl_stmt|;
name|uint8_t
name|dwell_passive
decl_stmt|;
name|uint8_t
name|dwell_fragmented
decl_stmt|;
name|uint8_t
name|dwell_extended
decl_stmt|;
name|uint8_t
name|mac_addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|bcast_sta_id
decl_stmt|;
name|uint8_t
name|channel_flags
decl_stmt|;
name|uint8_t
name|channel_array
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SCAN_CONFIG_DB_CMD_API_S */
end_comment

begin_comment
comment|/**  * iwm_umac_scan_flags  *@IWM_UMAC_SCAN_FLAG_PREEMPTIVE: scan process triggered by this scan request  *	can be preempted by other scan requests with higher priority.  *	The low priority scan will be resumed when the higher proirity scan is  *	completed.  *@IWM_UMAC_SCAN_FLAG_START_NOTIF: notification will be sent to the driver  *	when scan starts.  */
end_comment

begin_enum
enum|enum
name|iwm_umac_scan_flags
block|{
name|IWM_UMAC_SCAN_FLAG_PREEMPTIVE
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_UMAC_SCAN_FLAG_START_NOTIF
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|iwm_umac_scan_uid_offsets
block|{
name|IWM_UMAC_SCAN_UID_TYPE_OFFSET
init|=
literal|0
block|,
name|IWM_UMAC_SCAN_UID_SEQ_OFFSET
init|=
literal|8
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|iwm_umac_scan_general_flags
block|{
name|IWM_UMAC_SCAN_GEN_FLAGS_PERIODIC
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_UMAC_SCAN_GEN_FLAGS_OVER_BT
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_UMAC_SCAN_GEN_FLAGS_PASS_ALL
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_UMAC_SCAN_GEN_FLAGS_PASSIVE
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_UMAC_SCAN_GEN_FLAGS_PRE_CONNECT
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|IWM_UMAC_SCAN_GEN_FLAGS_ITER_COMPLETE
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|IWM_UMAC_SCAN_GEN_FLAGS_MULTIPLE_SSID
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|IWM_UMAC_SCAN_GEN_FLAGS_FRAGMENTED
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|,
name|IWM_UMAC_SCAN_GEN_FLAGS_RRM_ENABLED
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
name|IWM_UMAC_SCAN_GEN_FLAGS_MATCH
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
name|IWM_UMAC_SCAN_GEN_FLAGS_EXTENDED_DWELL
init|=
operator|(
literal|1
operator|<<
literal|10
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_scan_channel_cfg_umac  * @flags:		bitmap - 0-19:	directed scan to i'th ssid.  * @channel_num:	channel number 1-13 etc.  * @iter_count:		repetition count for the channel.  * @iter_interval:	interval between two scan iterations on one channel.  */
end_comment

begin_struct
struct|struct
name|iwm_scan_channel_cfg_umac
block|{
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|IWM_SCAN_CHANNEL_UMAC_NSSIDS
parameter_list|(
name|x
parameter_list|)
value|((1<< (x)) - 1)
name|uint8_t
name|channel_num
decl_stmt|;
name|uint8_t
name|iter_count
decl_stmt|;
name|uint16_t
name|iter_interval
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SCAN_CHANNEL_CFG_S_VER2 */
end_comment

begin_comment
comment|/**  * struct iwm_scan_umac_schedule  * @interval: interval in seconds between scan iterations  * @iter_count: num of scan iterations for schedule plan, 0xff for infinite loop  * @reserved: for alignment and future use  */
end_comment

begin_struct
struct|struct
name|iwm_scan_umac_schedule
block|{
name|uint16_t
name|interval
decl_stmt|;
name|uint8_t
name|iter_count
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SCAN_SCHED_PARAM_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_scan_req_umac_tail - the rest of the UMAC scan request command  *      parameters following channels configuration array.  * @schedule: two scheduling plans.  * @delay: delay in TUs before starting the first scan iteration  * @reserved: for future use and alignment  * @preq: probe request with IEs blocks  * @direct_scan: list of SSIDs for directed active scan  */
end_comment

begin_struct
struct|struct
name|iwm_scan_req_umac_tail
block|{
comment|/* SCAN_PERIODIC_PARAMS_API_S_VER_1 */
name|struct
name|iwm_scan_umac_schedule
name|schedule
index|[
name|IWM_MAX_SCHED_SCAN_PLANS
index|]
decl_stmt|;
name|uint16_t
name|delay
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
comment|/* SCAN_PROBE_PARAMS_API_S_VER_1 */
name|struct
name|iwm_scan_probe_req
name|preq
decl_stmt|;
name|struct
name|iwm_ssid_ie
name|direct_scan
index|[
name|IWM_PROBE_OPTION_MAX
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * struct iwm_scan_req_umac  * @flags:&enum iwm_umac_scan_flags  * @uid: scan id,&enum iwm_umac_scan_uid_offsets  * @ooc_priority: out of channel priority -&enum iwm_scan_priority  * @general_flags:&enum iwm_umac_scan_general_flags  * @extended_dwell: dwell time for channels 1, 6 and 11  * @active_dwell: dwell time for active scan  * @passive_dwell: dwell time for passive scan  * @fragmented_dwell: dwell time for fragmented passive scan  * @max_out_time: max out of serving channel time  * @suspend_time: max suspend time  * @scan_priority: scan internal prioritization&enum iwm_scan_priority  * @channel_flags:&enum iwm_scan_channel_flags  * @n_channels: num of channels in scan request  * @reserved: for future use and alignment  * @data:&struct iwm_scan_channel_cfg_umac and  *&struct iwm_scan_req_umac_tail  */
end_comment

begin_struct
struct|struct
name|iwm_scan_req_umac
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|uid
decl_stmt|;
name|uint32_t
name|ooc_priority
decl_stmt|;
comment|/* SCAN_GENERAL_PARAMS_API_S_VER_1 */
name|uint32_t
name|general_flags
decl_stmt|;
name|uint8_t
name|extended_dwell
decl_stmt|;
name|uint8_t
name|active_dwell
decl_stmt|;
name|uint8_t
name|passive_dwell
decl_stmt|;
name|uint8_t
name|fragmented_dwell
decl_stmt|;
name|uint32_t
name|max_out_time
decl_stmt|;
name|uint32_t
name|suspend_time
decl_stmt|;
name|uint32_t
name|scan_priority
decl_stmt|;
comment|/* SCAN_CHANNEL_PARAMS_API_S_VER_1 */
name|uint8_t
name|channel_flags
decl_stmt|;
name|uint8_t
name|n_channels
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint8_t
name|data
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SCAN_REQUEST_CMD_UMAC_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_umac_scan_abort  * @uid: scan id,&enum iwm_umac_scan_uid_offsets  * @flags: reserved  */
end_comment

begin_struct
struct|struct
name|iwm_umac_scan_abort
block|{
name|uint32_t
name|uid
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SCAN_ABORT_CMD_UMAC_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_umac_scan_complete  * @uid: scan id,&enum iwm_umac_scan_uid_offsets  * @last_schedule: last scheduling line  * @last_iter:	last scan iteration number  * @scan status:&enum iwm_scan_offload_complete_status  * @ebs_status:&enum iwm_scan_ebs_status  * @time_from_last_iter: time elapsed from last iteration  * @reserved: for future use  */
end_comment

begin_struct
struct|struct
name|iwm_umac_scan_complete
block|{
name|uint32_t
name|uid
decl_stmt|;
name|uint8_t
name|last_schedule
decl_stmt|;
name|uint8_t
name|last_iter
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|ebs_status
decl_stmt|;
name|uint32_t
name|time_from_last_iter
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SCAN_COMPLETE_NTF_UMAC_API_S_VER_1 */
end_comment

begin_define
define|#
directive|define
name|IWM_SCAN_OFFLOAD_MATCHING_CHANNELS_LEN
value|5
end_define

begin_comment
comment|/**  * struct iwm_scan_offload_profile_match - match information  * @bssid: matched bssid  * @channel: channel where the match occurred  * @energy:  * @matching_feature:  * @matching_channels: bitmap of channels that matched, referencing  *	the channels passed in tue scan offload request  */
end_comment

begin_struct
struct|struct
name|iwm_scan_offload_profile_match
block|{
name|uint8_t
name|bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint8_t
name|channel
decl_stmt|;
name|uint8_t
name|energy
decl_stmt|;
name|uint8_t
name|matching_feature
decl_stmt|;
name|uint8_t
name|matching_channels
index|[
name|IWM_SCAN_OFFLOAD_MATCHING_CHANNELS_LEN
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SCAN_OFFLOAD_PROFILE_MATCH_RESULTS_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_scan_offload_profiles_query - match results query response  * @matched_profiles: bitmap of matched profiles, referencing the  *	matches passed in the scan offload request  * @last_scan_age: age of the last offloaded scan  * @n_scans_done: number of offloaded scans done  * @gp2_d0u: GP2 when D0U occurred  * @gp2_invoked: GP2 when scan offload was invoked  * @resume_while_scanning: not used  * @self_recovery: obsolete  * @reserved: reserved  * @matches: array of match information, one for each match  */
end_comment

begin_struct
struct|struct
name|iwm_scan_offload_profiles_query
block|{
name|uint32_t
name|matched_profiles
decl_stmt|;
name|uint32_t
name|last_scan_age
decl_stmt|;
name|uint32_t
name|n_scans_done
decl_stmt|;
name|uint32_t
name|gp2_d0u
decl_stmt|;
name|uint32_t
name|gp2_invoked
decl_stmt|;
name|uint8_t
name|resume_while_scanning
decl_stmt|;
name|uint8_t
name|self_recovery
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|struct
name|iwm_scan_offload_profile_match
name|matches
index|[
name|IWM_SCAN_MAX_PROFILES
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SCAN_OFFLOAD_PROFILES_QUERY_RSP_S_VER_2 */
end_comment

begin_comment
comment|/**  * struct iwm_umac_scan_iter_complete_notif - notifies end of scanning iteration  * @uid: scan id,&enum iwm_umac_scan_uid_offsets  * @scanned_channels: number of channels scanned and number of valid elements in  *	results array  * @status: one of SCAN_COMP_STATUS_*  * @bt_status: BT on/off status  * @last_channel: last channel that was scanned  * @tsf_low: TSF timer (lower half) in usecs  * @tsf_high: TSF timer (higher half) in usecs  * @results: array of scan results, only "scanned_channels" of them are valid  */
end_comment

begin_struct
struct|struct
name|iwm_umac_scan_iter_complete_notif
block|{
name|uint32_t
name|uid
decl_stmt|;
name|uint8_t
name|scanned_channels
decl_stmt|;
name|uint8_t
name|status
decl_stmt|;
name|uint8_t
name|bt_status
decl_stmt|;
name|uint8_t
name|last_channel
decl_stmt|;
name|uint32_t
name|tsf_low
decl_stmt|;
name|uint32_t
name|tsf_high
decl_stmt|;
name|struct
name|iwm_scan_results_notif
name|results
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SCAN_ITER_COMPLETE_NTF_UMAC_API_S_VER_1 */
end_comment

begin_comment
comment|/* Please keep this enum *SORTED* by hex value.  * Needed for binary search, otherwise a warning will be triggered.  */
end_comment

begin_enum
enum|enum
name|iwm_scan_subcmd_ids
block|{
name|IWM_GSCAN_START_CMD
init|=
literal|0x0
block|,
name|IWM_GSCAN_STOP_CMD
init|=
literal|0x1
block|,
name|IWM_GSCAN_SET_HOTLIST_CMD
init|=
literal|0x2
block|,
name|IWM_GSCAN_RESET_HOTLIST_CMD
init|=
literal|0x3
block|,
name|IWM_GSCAN_SET_SIGNIFICANT_CHANGE_CMD
init|=
literal|0x4
block|,
name|IWM_GSCAN_RESET_SIGNIFICANT_CHANGE_CMD
init|=
literal|0x5
block|,
name|IWM_GSCAN_SIGNIFICANT_CHANGE_EVENT
init|=
literal|0xFD
block|,
name|IWM_GSCAN_HOTLIST_CHANGE_EVENT
init|=
literal|0xFE
block|,
name|IWM_GSCAN_RESULTS_AVAILABLE_EVENT
init|=
literal|0xFF
block|, }
enum|;
end_enum

begin_comment
comment|/* STA API */
end_comment

begin_comment
comment|/**  * enum iwm_sta_flags - flags for the ADD_STA host command  * @IWM_STA_FLG_REDUCED_TX_PWR_CTRL:  * @IWM_STA_FLG_REDUCED_TX_PWR_DATA:  * @IWM_STA_FLG_DISABLE_TX: set if TX should be disabled  * @IWM_STA_FLG_PS: set if STA is in Power Save  * @IWM_STA_FLG_INVALID: set if STA is invalid  * @IWM_STA_FLG_DLP_EN: Direct Link Protocol is enabled  * @IWM_STA_FLG_SET_ALL_KEYS: the current key applies to all key IDs  * @IWM_STA_FLG_DRAIN_FLOW: drain flow  * @IWM_STA_FLG_PAN: STA is for PAN interface  * @IWM_STA_FLG_CLASS_AUTH:  * @IWM_STA_FLG_CLASS_ASSOC:  * @IWM_STA_FLG_CLASS_MIMO_PROT:  * @IWM_STA_FLG_MAX_AGG_SIZE_MSK: maximal size for A-MPDU  * @IWM_STA_FLG_AGG_MPDU_DENS_MSK: maximal MPDU density for Tx aggregation  * @IWM_STA_FLG_FAT_EN_MSK: support for channel width (for Tx). This flag is  *	initialised by driver and can be updated by fw upon reception of  *	action frames that can change the channel width. When cleared the fw  *	will send all the frames in 20MHz even when FAT channel is requested.  * @IWM_STA_FLG_MIMO_EN_MSK: support for MIMO. This flag is initialised by the  *	driver and can be updated by fw upon reception of action frames.  * @IWM_STA_FLG_MFP_EN: Management Frame Protection  */
end_comment

begin_enum
enum|enum
name|iwm_sta_flags
block|{
name|IWM_STA_FLG_REDUCED_TX_PWR_CTRL
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_STA_FLG_REDUCED_TX_PWR_DATA
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|IWM_STA_FLG_DISABLE_TX
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|IWM_STA_FLG_PS
init|=
operator|(
literal|1
operator|<<
literal|8
operator|)
block|,
name|IWM_STA_FLG_DRAIN_FLOW
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|,
name|IWM_STA_FLG_PAN
init|=
operator|(
literal|1
operator|<<
literal|13
operator|)
block|,
name|IWM_STA_FLG_CLASS_AUTH
init|=
operator|(
literal|1
operator|<<
literal|14
operator|)
block|,
name|IWM_STA_FLG_CLASS_ASSOC
init|=
operator|(
literal|1
operator|<<
literal|15
operator|)
block|,
name|IWM_STA_FLG_RTS_MIMO_PROT
init|=
operator|(
literal|1
operator|<<
literal|17
operator|)
block|,
name|IWM_STA_FLG_MAX_AGG_SIZE_SHIFT
init|=
literal|19
block|,
name|IWM_STA_FLG_MAX_AGG_SIZE_8K
init|=
operator|(
literal|0
operator|<<
name|IWM_STA_FLG_MAX_AGG_SIZE_SHIFT
operator|)
block|,
name|IWM_STA_FLG_MAX_AGG_SIZE_16K
init|=
operator|(
literal|1
operator|<<
name|IWM_STA_FLG_MAX_AGG_SIZE_SHIFT
operator|)
block|,
name|IWM_STA_FLG_MAX_AGG_SIZE_32K
init|=
operator|(
literal|2
operator|<<
name|IWM_STA_FLG_MAX_AGG_SIZE_SHIFT
operator|)
block|,
name|IWM_STA_FLG_MAX_AGG_SIZE_64K
init|=
operator|(
literal|3
operator|<<
name|IWM_STA_FLG_MAX_AGG_SIZE_SHIFT
operator|)
block|,
name|IWM_STA_FLG_MAX_AGG_SIZE_128K
init|=
operator|(
literal|4
operator|<<
name|IWM_STA_FLG_MAX_AGG_SIZE_SHIFT
operator|)
block|,
name|IWM_STA_FLG_MAX_AGG_SIZE_256K
init|=
operator|(
literal|5
operator|<<
name|IWM_STA_FLG_MAX_AGG_SIZE_SHIFT
operator|)
block|,
name|IWM_STA_FLG_MAX_AGG_SIZE_512K
init|=
operator|(
literal|6
operator|<<
name|IWM_STA_FLG_MAX_AGG_SIZE_SHIFT
operator|)
block|,
name|IWM_STA_FLG_MAX_AGG_SIZE_1024K
init|=
operator|(
literal|7
operator|<<
name|IWM_STA_FLG_MAX_AGG_SIZE_SHIFT
operator|)
block|,
name|IWM_STA_FLG_MAX_AGG_SIZE_MSK
init|=
operator|(
literal|7
operator|<<
name|IWM_STA_FLG_MAX_AGG_SIZE_SHIFT
operator|)
block|,
name|IWM_STA_FLG_AGG_MPDU_DENS_SHIFT
init|=
literal|23
block|,
name|IWM_STA_FLG_AGG_MPDU_DENS_2US
init|=
operator|(
literal|4
operator|<<
name|IWM_STA_FLG_AGG_MPDU_DENS_SHIFT
operator|)
block|,
name|IWM_STA_FLG_AGG_MPDU_DENS_4US
init|=
operator|(
literal|5
operator|<<
name|IWM_STA_FLG_AGG_MPDU_DENS_SHIFT
operator|)
block|,
name|IWM_STA_FLG_AGG_MPDU_DENS_8US
init|=
operator|(
literal|6
operator|<<
name|IWM_STA_FLG_AGG_MPDU_DENS_SHIFT
operator|)
block|,
name|IWM_STA_FLG_AGG_MPDU_DENS_16US
init|=
operator|(
literal|7
operator|<<
name|IWM_STA_FLG_AGG_MPDU_DENS_SHIFT
operator|)
block|,
name|IWM_STA_FLG_AGG_MPDU_DENS_MSK
init|=
operator|(
literal|7
operator|<<
name|IWM_STA_FLG_AGG_MPDU_DENS_SHIFT
operator|)
block|,
name|IWM_STA_FLG_FAT_EN_20MHZ
init|=
operator|(
literal|0
operator|<<
literal|26
operator|)
block|,
name|IWM_STA_FLG_FAT_EN_40MHZ
init|=
operator|(
literal|1
operator|<<
literal|26
operator|)
block|,
name|IWM_STA_FLG_FAT_EN_80MHZ
init|=
operator|(
literal|2
operator|<<
literal|26
operator|)
block|,
name|IWM_STA_FLG_FAT_EN_160MHZ
init|=
operator|(
literal|3
operator|<<
literal|26
operator|)
block|,
name|IWM_STA_FLG_FAT_EN_MSK
init|=
operator|(
literal|3
operator|<<
literal|26
operator|)
block|,
name|IWM_STA_FLG_MIMO_EN_SISO
init|=
operator|(
literal|0
operator|<<
literal|28
operator|)
block|,
name|IWM_STA_FLG_MIMO_EN_MIMO2
init|=
operator|(
literal|1
operator|<<
literal|28
operator|)
block|,
name|IWM_STA_FLG_MIMO_EN_MIMO3
init|=
operator|(
literal|2
operator|<<
literal|28
operator|)
block|,
name|IWM_STA_FLG_MIMO_EN_MSK
init|=
operator|(
literal|3
operator|<<
literal|28
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum iwm_sta_key_flag - key flags for the ADD_STA host command  * @IWM_STA_KEY_FLG_NO_ENC: no encryption  * @IWM_STA_KEY_FLG_WEP: WEP encryption algorithm  * @IWM_STA_KEY_FLG_CCM: CCMP encryption algorithm  * @IWM_STA_KEY_FLG_TKIP: TKIP encryption algorithm  * @IWM_STA_KEY_FLG_EXT: extended cipher algorithm (depends on the FW support)  * @IWM_STA_KEY_FLG_CMAC: CMAC encryption algorithm  * @IWM_STA_KEY_FLG_ENC_UNKNOWN: unknown encryption algorithm  * @IWM_STA_KEY_FLG_EN_MSK: mask for encryption algorithmi value  * @IWM_STA_KEY_FLG_WEP_KEY_MAP: wep is either a group key (0 - legacy WEP) or from  *	station info array (1 - n 1X mode)  * @IWM_STA_KEY_FLG_KEYID_MSK: the index of the key  * @IWM_STA_KEY_NOT_VALID: key is invalid  * @IWM_STA_KEY_FLG_WEP_13BYTES: set for 13 bytes WEP key  * @IWM_STA_KEY_MULTICAST: set for multical key  * @IWM_STA_KEY_MFP: key is used for Management Frame Protection  */
end_comment

begin_enum
enum|enum
name|iwm_sta_key_flag
block|{
name|IWM_STA_KEY_FLG_NO_ENC
init|=
operator|(
literal|0
operator|<<
literal|0
operator|)
block|,
name|IWM_STA_KEY_FLG_WEP
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_STA_KEY_FLG_CCM
init|=
operator|(
literal|2
operator|<<
literal|0
operator|)
block|,
name|IWM_STA_KEY_FLG_TKIP
init|=
operator|(
literal|3
operator|<<
literal|0
operator|)
block|,
name|IWM_STA_KEY_FLG_EXT
init|=
operator|(
literal|4
operator|<<
literal|0
operator|)
block|,
name|IWM_STA_KEY_FLG_CMAC
init|=
operator|(
literal|6
operator|<<
literal|0
operator|)
block|,
name|IWM_STA_KEY_FLG_ENC_UNKNOWN
init|=
operator|(
literal|7
operator|<<
literal|0
operator|)
block|,
name|IWM_STA_KEY_FLG_EN_MSK
init|=
operator|(
literal|7
operator|<<
literal|0
operator|)
block|,
name|IWM_STA_KEY_FLG_WEP_KEY_MAP
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_STA_KEY_FLG_KEYID_POS
init|=
literal|8
block|,
name|IWM_STA_KEY_FLG_KEYID_MSK
init|=
operator|(
literal|3
operator|<<
name|IWM_STA_KEY_FLG_KEYID_POS
operator|)
block|,
name|IWM_STA_KEY_NOT_VALID
init|=
operator|(
literal|1
operator|<<
literal|11
operator|)
block|,
name|IWM_STA_KEY_FLG_WEP_13BYTES
init|=
operator|(
literal|1
operator|<<
literal|12
operator|)
block|,
name|IWM_STA_KEY_MULTICAST
init|=
operator|(
literal|1
operator|<<
literal|14
operator|)
block|,
name|IWM_STA_KEY_MFP
init|=
operator|(
literal|1
operator|<<
literal|15
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum iwm_sta_modify_flag - indicate to the fw what flag are being changed  * @IWM_STA_MODIFY_QUEUE_REMOVAL: this command removes a queue  * @IWM_STA_MODIFY_TID_DISABLE_TX: this command modifies %tid_disable_tx  * @IWM_STA_MODIFY_TX_RATE: unused  * @IWM_STA_MODIFY_ADD_BA_TID: this command modifies %add_immediate_ba_tid  * @IWM_STA_MODIFY_REMOVE_BA_TID: this command modifies %remove_immediate_ba_tid  * @IWM_STA_MODIFY_SLEEPING_STA_TX_COUNT: this command modifies %sleep_tx_count  * @IWM_STA_MODIFY_PROT_TH:  * @IWM_STA_MODIFY_QUEUES: modify the queues used by this station  */
end_comment

begin_enum
enum|enum
name|iwm_sta_modify_flag
block|{
name|IWM_STA_MODIFY_QUEUE_REMOVAL
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_STA_MODIFY_TID_DISABLE_TX
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_STA_MODIFY_TX_RATE
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_STA_MODIFY_ADD_BA_TID
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_STA_MODIFY_REMOVE_BA_TID
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|IWM_STA_MODIFY_SLEEPING_STA_TX_COUNT
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
name|IWM_STA_MODIFY_PROT_TH
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
name|IWM_STA_MODIFY_QUEUES
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_STA_MODE_MODIFY
value|1
end_define

begin_comment
comment|/**  * enum iwm_sta_sleep_flag - type of sleep of the station  * @IWM_STA_SLEEP_STATE_AWAKE:  * @IWM_STA_SLEEP_STATE_PS_POLL:  * @IWM_STA_SLEEP_STATE_UAPSD:  * @IWM_STA_SLEEP_STATE_MOREDATA: set more-data bit on  *	(last) released frame  */
end_comment

begin_enum
enum|enum
name|iwm_sta_sleep_flag
block|{
name|IWM_STA_SLEEP_STATE_AWAKE
init|=
literal|0
block|,
name|IWM_STA_SLEEP_STATE_PS_POLL
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_STA_SLEEP_STATE_UAPSD
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_STA_SLEEP_STATE_MOREDATA
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/* STA ID and color bits definitions */
end_comment

begin_define
define|#
directive|define
name|IWM_STA_ID_SEED
value|(0x0f)
end_define

begin_define
define|#
directive|define
name|IWM_STA_ID_POS
value|(0)
end_define

begin_define
define|#
directive|define
name|IWM_STA_ID_MSK
value|(IWM_STA_ID_SEED<< IWM_STA_ID_POS)
end_define

begin_define
define|#
directive|define
name|IWM_STA_COLOR_SEED
value|(0x7)
end_define

begin_define
define|#
directive|define
name|IWM_STA_COLOR_POS
value|(4)
end_define

begin_define
define|#
directive|define
name|IWM_STA_COLOR_MSK
value|(IWM_STA_COLOR_SEED<< IWM_STA_COLOR_POS)
end_define

begin_define
define|#
directive|define
name|IWM_STA_ID_N_COLOR_GET_COLOR
parameter_list|(
name|id_n_color
parameter_list|)
define|\
value|(((id_n_color)& IWM_STA_COLOR_MSK)>> IWM_STA_COLOR_POS)
end_define

begin_define
define|#
directive|define
name|IWM_STA_ID_N_COLOR_GET_ID
parameter_list|(
name|id_n_color
parameter_list|)
define|\
value|(((id_n_color)& IWM_STA_ID_MSK)>> IWM_STA_ID_POS)
end_define

begin_define
define|#
directive|define
name|IWM_STA_KEY_MAX_NUM
value|(16)
end_define

begin_define
define|#
directive|define
name|IWM_STA_KEY_IDX_INVALID
value|(0xff)
end_define

begin_define
define|#
directive|define
name|IWM_STA_KEY_MAX_DATA_KEY_NUM
value|(4)
end_define

begin_define
define|#
directive|define
name|IWM_MAX_GLOBAL_KEYS
value|(4)
end_define

begin_define
define|#
directive|define
name|IWM_STA_KEY_LEN_WEP40
value|(5)
end_define

begin_define
define|#
directive|define
name|IWM_STA_KEY_LEN_WEP104
value|(13)
end_define

begin_comment
comment|/**  * struct iwm_mvm_keyinfo - key information  * @key_flags: type %iwm_sta_key_flag  * @tkip_rx_tsc_byte2: TSC[2] for key mix ph1 detection  * @tkip_rx_ttak: 10-byte unicast TKIP TTAK for Rx  * @key_offset: key offset in the fw's key table  * @key: 16-byte unicast decryption key  * @tx_secur_seq_cnt: initial RSC / PN needed for replay check  * @hw_tkip_mic_rx_key: byte: MIC Rx Key - used for TKIP only  * @hw_tkip_mic_tx_key: byte: MIC Tx Key - used for TKIP only  */
end_comment

begin_struct
struct|struct
name|iwm_mvm_keyinfo
block|{
name|uint16_t
name|key_flags
decl_stmt|;
name|uint8_t
name|tkip_rx_tsc_byte2
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
name|uint16_t
name|tkip_rx_ttak
index|[
literal|5
index|]
decl_stmt|;
name|uint8_t
name|key_offset
decl_stmt|;
name|uint8_t
name|reserved2
decl_stmt|;
name|uint8_t
name|key
index|[
literal|16
index|]
decl_stmt|;
name|uint64_t
name|tx_secur_seq_cnt
decl_stmt|;
name|uint64_t
name|hw_tkip_mic_rx_key
decl_stmt|;
name|uint64_t
name|hw_tkip_mic_tx_key
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWM_ADD_STA_STATUS_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|IWM_ADD_STA_BAID_VALID_MASK
value|0x8000
end_define

begin_define
define|#
directive|define
name|IWM_ADD_STA_BAID_MASK
value|0x7F00
end_define

begin_define
define|#
directive|define
name|IWM_ADD_STA_BAID_SHIFT
value|8
end_define

begin_comment
comment|/**  * struct iwm_mvm_add_sta_cmd - Add/modify a station in the fw's sta table.  * ( REPLY_ADD_STA = 0x18 )  * @add_modify: 1: modify existing, 0: add new station  * @awake_acs:  * @tid_disable_tx: is tid BIT(tid) enabled for Tx. Clear BIT(x) to enable  *	AMPDU for tid x. Set %IWM_STA_MODIFY_TID_DISABLE_TX to change this field.  * @mac_id_n_color: the Mac context this station belongs to  * @addr[IEEE80211_ADDR_LEN]: station's MAC address  * @sta_id: index of station in uCode's station table  * @modify_mask: IWM_STA_MODIFY_*, selects which parameters to modify vs. leave  *	alone. 1 - modify, 0 - don't change.  * @station_flags: look at %iwm_sta_flags  * @station_flags_msk: what of %station_flags have changed  * @add_immediate_ba_tid: tid for which to add block-ack support (Rx)  *	Set %IWM_STA_MODIFY_ADD_BA_TID to use this field, and also set  *	add_immediate_ba_ssn.  * @remove_immediate_ba_tid: tid for which to remove block-ack support (Rx)  *	Set %IWM_STA_MODIFY_REMOVE_BA_TID to use this field  * @add_immediate_ba_ssn: ssn for the Rx block-ack session. Used together with  *	add_immediate_ba_tid.  * @sleep_tx_count: number of packets to transmit to station even though it is  *	asleep. Used to synchronise PS-poll and u-APSD responses while ucode  *	keeps track of STA sleep state.  * @sleep_state_flags: Look at %iwm_sta_sleep_flag.  * @assoc_id: assoc_id to be sent in VHT PLCP (9-bit), for grp use 0, for AP  *	mac-addr.  * @beamform_flags: beam forming controls  * @tfd_queue_msk: tfd queues used by this station  *  * The device contains an internal table of per-station information, with info  * on security keys, aggregation parameters, and Tx rates for initial Tx  * attempt and any retries (set by IWM_REPLY_TX_LINK_QUALITY_CMD).  *  * ADD_STA sets up the table entry for one station, either creating a new  * entry, or modifying a pre-existing one.  */
end_comment

begin_struct
struct|struct
name|iwm_mvm_add_sta_cmd
block|{
name|uint8_t
name|add_modify
decl_stmt|;
name|uint8_t
name|awake_acs
decl_stmt|;
name|uint16_t
name|tid_disable_tx
decl_stmt|;
name|uint32_t
name|mac_id_n_color
decl_stmt|;
name|uint8_t
name|addr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
comment|/* _STA_ID_MODIFY_INFO_API_S_VER_1 */
name|uint16_t
name|reserved2
decl_stmt|;
name|uint8_t
name|sta_id
decl_stmt|;
name|uint8_t
name|modify_mask
decl_stmt|;
name|uint16_t
name|reserved3
decl_stmt|;
name|uint32_t
name|station_flags
decl_stmt|;
name|uint32_t
name|station_flags_msk
decl_stmt|;
name|uint8_t
name|add_immediate_ba_tid
decl_stmt|;
name|uint8_t
name|remove_immediate_ba_tid
decl_stmt|;
name|uint16_t
name|add_immediate_ba_ssn
decl_stmt|;
name|uint16_t
name|sleep_tx_count
decl_stmt|;
name|uint16_t
name|sleep_state_flags
decl_stmt|;
name|uint16_t
name|assoc_id
decl_stmt|;
name|uint16_t
name|beamform_flags
decl_stmt|;
name|uint32_t
name|tfd_queue_msk
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* ADD_STA_CMD_API_S_VER_7 */
end_comment

begin_comment
comment|/**  * struct iwm_mvm_add_sta_key_cmd - add/modify sta key  * ( IWM_REPLY_ADD_STA_KEY = 0x17 )  * @sta_id: index of station in uCode's station table  * @key_offset: key offset in key storage  * @key_flags: type %iwm_sta_key_flag  * @key: key material data  * @key2: key material data  * @rx_secur_seq_cnt: RX security sequence counter for the key  * @tkip_rx_tsc_byte2: TSC[2] for key mix ph1 detection  * @tkip_rx_ttak: 10-byte unicast TKIP TTAK for Rx  */
end_comment

begin_struct
struct|struct
name|iwm_mvm_add_sta_key_cmd
block|{
name|uint8_t
name|sta_id
decl_stmt|;
name|uint8_t
name|key_offset
decl_stmt|;
name|uint16_t
name|key_flags
decl_stmt|;
name|uint8_t
name|key
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|key2
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|rx_secur_seq_cnt
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|tkip_rx_tsc_byte2
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint16_t
name|tkip_rx_ttak
index|[
literal|5
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_ADD_MODIFY_STA_KEY_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * enum iwm_mvm_add_sta_rsp_status - status in the response to ADD_STA command  * @IWM_ADD_STA_SUCCESS: operation was executed successfully  * @IWM_ADD_STA_STATIONS_OVERLOAD: no room left in the fw's station table  * @IWM_ADD_STA_IMMEDIATE_BA_FAILURE: can't add Rx block ack session  * @IWM_ADD_STA_MODIFY_NON_EXISTING_STA: driver requested to modify a station  *	that doesn't exist.  */
end_comment

begin_enum
enum|enum
name|iwm_mvm_add_sta_rsp_status
block|{
name|IWM_ADD_STA_SUCCESS
init|=
literal|0x1
block|,
name|IWM_ADD_STA_STATIONS_OVERLOAD
init|=
literal|0x2
block|,
name|IWM_ADD_STA_IMMEDIATE_BA_FAILURE
init|=
literal|0x4
block|,
name|IWM_ADD_STA_MODIFY_NON_EXISTING_STA
init|=
literal|0x8
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_mvm_rm_sta_cmd - Add / modify a station in the fw's station table  * ( IWM_REMOVE_STA = 0x19 )  * @sta_id: the station id of the station to be removed  */
end_comment

begin_struct
struct|struct
name|iwm_mvm_rm_sta_cmd
block|{
name|uint8_t
name|sta_id
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* IWM_REMOVE_STA_CMD_API_S_VER_2 */
end_comment

begin_comment
comment|/**  * struct iwm_mvm_mgmt_mcast_key_cmd  * ( IWM_MGMT_MCAST_KEY = 0x1f )  * @ctrl_flags: %iwm_sta_key_flag  * @IGTK:  * @K1: IGTK master key  * @K2: IGTK sub key  * @sta_id: station ID that support IGTK  * @key_id:  * @receive_seq_cnt: initial RSC/PN needed for replay check  */
end_comment

begin_struct
struct|struct
name|iwm_mvm_mgmt_mcast_key_cmd
block|{
name|uint32_t
name|ctrl_flags
decl_stmt|;
name|uint8_t
name|IGTK
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|K1
index|[
literal|16
index|]
decl_stmt|;
name|uint8_t
name|K2
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|key_id
decl_stmt|;
name|uint32_t
name|sta_id
decl_stmt|;
name|uint64_t
name|receive_seq_cnt
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SEC_MGMT_MULTICAST_KEY_CMD_API_S_VER_1 */
end_comment

begin_struct
struct|struct
name|iwm_mvm_wep_key
block|{
name|uint8_t
name|key_index
decl_stmt|;
name|uint8_t
name|key_offset
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint8_t
name|key_size
decl_stmt|;
name|uint8_t
name|reserved2
index|[
literal|3
index|]
decl_stmt|;
name|uint8_t
name|key
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwm_mvm_wep_key_cmd
block|{
name|uint32_t
name|mac_id_n_color
decl_stmt|;
name|uint8_t
name|num_keys
decl_stmt|;
name|uint8_t
name|decryption_type
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|struct
name|iwm_mvm_wep_key
name|wep_key
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* SEC_CURR_WEP_KEY_CMD_API_S_VER_2 */
end_comment

begin_comment
comment|/*  * END mvm/fw-api-sta.h  */
end_comment

begin_comment
comment|/*  * BT coex  */
end_comment

begin_enum
enum|enum
name|iwm_bt_coex_mode
block|{
name|IWM_BT_COEX_DISABLE
init|=
literal|0x0
block|,
name|IWM_BT_COEX_NW
init|=
literal|0x1
block|,
name|IWM_BT_COEX_BT
init|=
literal|0x2
block|,
name|IWM_BT_COEX_WIFI
init|=
literal|0x3
block|, }
enum|;
end_enum

begin_comment
comment|/* BT_COEX_MODES_E */
end_comment

begin_enum
enum|enum
name|iwm_bt_coex_enabled_modules
block|{
name|IWM_BT_COEX_MPLUT_ENABLED
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|IWM_BT_COEX_MPLUT_BOOST_ENABLED
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|IWM_BT_COEX_SYNC2SCO_ENABLED
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
name|IWM_BT_COEX_CORUN_ENABLED
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|IWM_BT_COEX_HIGH_BAND_RET
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/* BT_COEX_MODULES_ENABLE_E_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_bt_coex_cmd - bt coex configuration command  * @mode: enum %iwm_bt_coex_mode  * @enabled_modules: enum %iwm_bt_coex_enabled_modules  *  * The structure is used for the BT_COEX command.  */
end_comment

begin_struct
struct|struct
name|iwm_bt_coex_cmd
block|{
name|uint32_t
name|mode
decl_stmt|;
name|uint32_t
name|enabled_modules
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* BT_COEX_CMD_API_S_VER_6 */
end_comment

begin_comment
comment|/*  * Location Aware Regulatory (LAR) API - MCC updates  */
end_comment

begin_comment
comment|/**  * struct iwm_mcc_update_cmd_v1 - Request the device to update geographic  * regulatory profile according to the given MCC (Mobile Country Code).  * The MCC is two letter-code, ascii upper case[A-Z] or '00' for world domain.  * 'ZZ' MCC will be used to switch to NVM default profile; in this case, the  * MCC in the cmd response will be the relevant MCC in the NVM.  * @mcc: given mobile country code  * @source_id: the source from where we got the MCC, see iwm_mcc_source  * @reserved: reserved for alignment  */
end_comment

begin_struct
struct|struct
name|iwm_mcc_update_cmd_v1
block|{
name|uint16_t
name|mcc
decl_stmt|;
name|uint8_t
name|source_id
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* LAR_UPDATE_MCC_CMD_API_S_VER_1 */
end_comment

begin_comment
comment|/**  * struct iwm_mcc_update_cmd - Request the device to update geographic  * regulatory profile according to the given MCC (Mobile Country Code).  * The MCC is two letter-code, ascii upper case[A-Z] or '00' for world domain.  * 'ZZ' MCC will be used to switch to NVM default profile; in this case, the  * MCC in the cmd response will be the relevant MCC in the NVM.  * @mcc: given mobile country code  * @source_id: the source from where we got the MCC, see iwm_mcc_source  * @reserved: reserved for alignment  * @key: integrity key for MCC API OEM testing  * @reserved2: reserved  */
end_comment

begin_struct
struct|struct
name|iwm_mcc_update_cmd
block|{
name|uint16_t
name|mcc
decl_stmt|;
name|uint8_t
name|source_id
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint32_t
name|key
decl_stmt|;
name|uint32_t
name|reserved2
index|[
literal|5
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* LAR_UPDATE_MCC_CMD_API_S_VER_2 */
end_comment

begin_comment
comment|/**  * iwm_mcc_update_resp_v1  - response to MCC_UPDATE_CMD.  * Contains the new channel control profile map, if changed, and the new MCC  * (mobile country code).  * The new MCC may be different than what was requested in MCC_UPDATE_CMD.  * @status: see&enum iwm_mcc_update_status  * @mcc: the new applied MCC  * @cap: capabilities for all channels which matches the MCC  * @source_id: the MCC source, see iwm_mcc_source  * @n_channels: number of channels in @channels_data (may be 14, 39, 50 or 51  *		channels, depending on platform)  * @channels: channel control data map, DWORD for each channel. Only the first  *	16bits are used.  */
end_comment

begin_struct
struct|struct
name|iwm_mcc_update_resp_v1
block|{
name|uint32_t
name|status
decl_stmt|;
name|uint16_t
name|mcc
decl_stmt|;
name|uint8_t
name|cap
decl_stmt|;
name|uint8_t
name|source_id
decl_stmt|;
name|uint32_t
name|n_channels
decl_stmt|;
name|uint32_t
name|channels
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* LAR_UPDATE_MCC_CMD_RESP_S_VER_1 */
end_comment

begin_comment
comment|/**  * iwm_mcc_update_resp - response to MCC_UPDATE_CMD.  * Contains the new channel control profile map, if changed, and the new MCC  * (mobile country code).  * The new MCC may be different than what was requested in MCC_UPDATE_CMD.  * @status: see&enum iwm_mcc_update_status  * @mcc: the new applied MCC  * @cap: capabilities for all channels which matches the MCC  * @source_id: the MCC source, see iwm_mcc_source  * @time: time elapsed from the MCC test start (in 30 seconds TU)  * @reserved: reserved.  * @n_channels: number of channels in @channels_data (may be 14, 39, 50 or 51  *		channels, depending on platform)  * @channels: channel control data map, DWORD for each channel. Only the first  *	16bits are used.  */
end_comment

begin_struct
struct|struct
name|iwm_mcc_update_resp
block|{
name|uint32_t
name|status
decl_stmt|;
name|uint16_t
name|mcc
decl_stmt|;
name|uint8_t
name|cap
decl_stmt|;
name|uint8_t
name|source_id
decl_stmt|;
name|uint16_t
name|time
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint32_t
name|n_channels
decl_stmt|;
name|uint32_t
name|channels
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* LAR_UPDATE_MCC_CMD_RESP_S_VER_2 */
end_comment

begin_comment
comment|/**  * struct iwm_mcc_chub_notif - chub notifies of mcc change  * (MCC_CHUB_UPDATE_CMD = 0xc9)  * The Chub (Communication Hub, CommsHUB) is a HW component that connects to  * the cellular and connectivity cores that gets updates of the mcc, and  * notifies the ucode directly of any mcc change.  * The ucode requests the driver to request the device to update geographic  * regulatory  profile according to the given MCC (Mobile Country Code).  * The MCC is two letter-code, ascii upper case[A-Z] or '00' for world domain.  * 'ZZ' MCC will be used to switch to NVM default profile; in this case, the  * MCC in the cmd response will be the relevant MCC in the NVM.  * @mcc: given mobile country code  * @source_id: identity of the change originator, see iwm_mcc_source  * @reserved1: reserved for alignment  */
end_comment

begin_struct
struct|struct
name|iwm_mcc_chub_notif
block|{
name|uint16_t
name|mcc
decl_stmt|;
name|uint8_t
name|source_id
decl_stmt|;
name|uint8_t
name|reserved1
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* LAR_MCC_NOTIFY_S */
end_comment

begin_enum
enum|enum
name|iwm_mcc_update_status
block|{
name|IWM_MCC_RESP_NEW_CHAN_PROFILE
block|,
name|IWM_MCC_RESP_SAME_CHAN_PROFILE
block|,
name|IWM_MCC_RESP_INVALID
block|,
name|IWM_MCC_RESP_NVM_DISABLED
block|,
name|IWM_MCC_RESP_ILLEGAL
block|,
name|IWM_MCC_RESP_LOW_PRIORITY
block|,
name|IWM_MCC_RESP_TEST_MODE_ACTIVE
block|,
name|IWM_MCC_RESP_TEST_MODE_NOT_ACTIVE
block|,
name|IWM_MCC_RESP_TEST_MODE_DENIAL_OF_SERVICE
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|iwm_mcc_source
block|{
name|IWM_MCC_SOURCE_OLD_FW
init|=
literal|0
block|,
name|IWM_MCC_SOURCE_ME
init|=
literal|1
block|,
name|IWM_MCC_SOURCE_BIOS
init|=
literal|2
block|,
name|IWM_MCC_SOURCE_3G_LTE_HOST
init|=
literal|3
block|,
name|IWM_MCC_SOURCE_3G_LTE_DEVICE
init|=
literal|4
block|,
name|IWM_MCC_SOURCE_WIFI
init|=
literal|5
block|,
name|IWM_MCC_SOURCE_RESERVED
init|=
literal|6
block|,
name|IWM_MCC_SOURCE_DEFAULT
init|=
literal|7
block|,
name|IWM_MCC_SOURCE_UNINITIALIZED
init|=
literal|8
block|,
name|IWM_MCC_SOURCE_MCC_API
init|=
literal|9
block|,
name|IWM_MCC_SOURCE_GET_CURRENT
init|=
literal|0x10
block|,
name|IWM_MCC_SOURCE_GETTING_MCC_TEST_MODE
init|=
literal|0x11
block|, }
enum|;
end_enum

begin_comment
comment|/**  * struct iwm_dts_measurement_notif_v1 - measurements notification  *  * @temp: the measured temperature  * @voltage: the measured voltage  */
end_comment

begin_struct
struct|struct
name|iwm_dts_measurement_notif_v1
block|{
name|int32_t
name|temp
decl_stmt|;
name|int32_t
name|voltage
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* TEMPERATURE_MEASUREMENT_TRIGGER_NTFY_S_VER_1*/
end_comment

begin_comment
comment|/**  * struct iwm_dts_measurement_notif_v2 - measurements notification  *  * @temp: the measured temperature  * @voltage: the measured voltage  * @threshold_idx: the trip index that was crossed  */
end_comment

begin_struct
struct|struct
name|iwm_dts_measurement_notif_v2
block|{
name|int32_t
name|temp
decl_stmt|;
name|int32_t
name|voltage
decl_stmt|;
name|int32_t
name|threshold_idx
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* TEMPERATURE_MEASUREMENT_TRIGGER_NTFY_S_VER_2 */
end_comment

begin_comment
comment|/*  * Some cherry-picked definitions  */
end_comment

begin_define
define|#
directive|define
name|IWM_FRAME_LIMIT
value|64
end_define

begin_comment
comment|/*  * These functions retrieve specific information from the id field in  * the iwm_host_cmd struct which contains the command id, the group id,  * and the version of the command and vice versa. */
end_comment

begin_function
specifier|static
specifier|inline
name|uint8_t
name|iwm_cmd_opcode
parameter_list|(
name|uint32_t
name|cmdid
parameter_list|)
block|{
return|return
name|cmdid
operator|&
literal|0xff
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint8_t
name|iwm_cmd_groupid
parameter_list|(
name|uint32_t
name|cmdid
parameter_list|)
block|{
return|return
operator|(
operator|(
name|cmdid
operator|&
literal|0xff00
operator|)
operator|>>
literal|8
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint8_t
name|iwm_cmd_version
parameter_list|(
name|uint32_t
name|cmdid
parameter_list|)
block|{
return|return
operator|(
operator|(
name|cmdid
operator|&
literal|0xff0000
operator|)
operator|>>
literal|16
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|iwm_cmd_id
parameter_list|(
name|uint8_t
name|opcode
parameter_list|,
name|uint8_t
name|groupid
parameter_list|,
name|uint8_t
name|version
parameter_list|)
block|{
return|return
name|opcode
operator|+
operator|(
name|groupid
operator|<<
literal|8
operator|)
operator|+
operator|(
name|version
operator|<<
literal|16
operator|)
return|;
block|}
end_function

begin_comment
comment|/* make uint16_t wide id out of uint8_t group and opcode */
end_comment

begin_define
define|#
directive|define
name|IWM_WIDE_ID
parameter_list|(
name|grp
parameter_list|,
name|opcode
parameter_list|)
value|((grp<< 8) | opcode)
end_define

begin_comment
comment|/* due to the conversion, this group is special */
end_comment

begin_define
define|#
directive|define
name|IWM_ALWAYS_LONG_GROUP
value|1
end_define

begin_struct
struct|struct
name|iwm_cmd_header
block|{
name|uint8_t
name|code
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|uint8_t
name|idx
decl_stmt|;
name|uint8_t
name|qid
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwm_cmd_header_wide
block|{
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|group_id
decl_stmt|;
name|uint8_t
name|idx
decl_stmt|;
name|uint8_t
name|qid
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|version
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/**  * enum iwm_power_scheme  * @IWM_POWER_LEVEL_CAM - Continuously Active Mode  * @IWM_POWER_LEVEL_BPS - Balanced Power Save (default)  * @IWM_POWER_LEVEL_LP  - Low Power  */
end_comment

begin_enum
enum|enum
name|iwm_power_scheme
block|{
name|IWM_POWER_SCHEME_CAM
init|=
literal|1
block|,
name|IWM_POWER_SCHEME_BPS
block|,
name|IWM_POWER_SCHEME_LP
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|IWM_DEF_CMD_PAYLOAD_SIZE
value|320
end_define

begin_define
define|#
directive|define
name|IWM_MAX_CMD_PAYLOAD_SIZE
value|((4096 - 4) - sizeof(struct iwm_cmd_header))
end_define

begin_define
define|#
directive|define
name|IWM_CMD_FAILED_MSK
value|0x40
end_define

begin_comment
comment|/**  * struct iwm_device_cmd  *  * For allocation of the command and tx queues, this establishes the overall  * size of the largest command we send to uCode, except for commands that  * aren't fully copied and use other TFD space.  */
end_comment

begin_struct
struct|struct
name|iwm_device_cmd
block|{
union|union
block|{
struct|struct
block|{
name|struct
name|iwm_cmd_header
name|hdr
decl_stmt|;
name|uint8_t
name|data
index|[
name|IWM_DEF_CMD_PAYLOAD_SIZE
index|]
decl_stmt|;
block|}
struct|;
struct|struct
block|{
name|struct
name|iwm_cmd_header_wide
name|hdr_wide
decl_stmt|;
name|uint8_t
name|data_wide
index|[
name|IWM_DEF_CMD_PAYLOAD_SIZE
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|iwm_cmd_header_wide
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|iwm_cmd_header
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
block|}
union|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|iwm_rx_packet
block|{
comment|/* 	 * The first 4 bytes of the RX frame header contain both the RX frame 	 * size and some flags. 	 * Bit fields: 	 * 31:    flag flush RB request 	 * 30:    flag ignore TC (terminal counter) request 	 * 29:    flag fast IRQ request 	 * 28-14: Reserved 	 * 13-00: RX frame size 	 */
name|uint32_t
name|len_n_flags
decl_stmt|;
name|struct
name|iwm_cmd_header
name|hdr
decl_stmt|;
name|uint8_t
name|data
index|[]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|IWM_FH_RSCSR_FRAME_SIZE_MSK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|IWM_FH_RSCSR_FRAME_INVALID
value|0x55550000
end_define

begin_define
define|#
directive|define
name|IWM_FH_RSCSR_FRAME_ALIGN
value|0x40
end_define

begin_function
specifier|static
specifier|inline
name|uint32_t
name|iwm_rx_packet_len
parameter_list|(
specifier|const
name|struct
name|iwm_rx_packet
modifier|*
name|pkt
parameter_list|)
block|{
return|return
name|le32toh
argument_list|(
name|pkt
operator|->
name|len_n_flags
argument_list|)
operator|&
name|IWM_FH_RSCSR_FRAME_SIZE_MSK
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|iwm_rx_packet_payload_len
parameter_list|(
specifier|const
name|struct
name|iwm_rx_packet
modifier|*
name|pkt
parameter_list|)
block|{
return|return
name|iwm_rx_packet_len
argument_list|(
name|pkt
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|pkt
operator|->
name|hdr
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|IWM_MIN_DBM
value|-100
end_define

begin_define
define|#
directive|define
name|IWM_MAX_DBM
value|-33
end_define

begin_comment
comment|/* realistic guess */
end_comment

begin_define
define|#
directive|define
name|IWM_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_st, (sc)->sc_sh, (reg))
end_define

begin_define
define|#
directive|define
name|IWM_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_st, (sc)->sc_sh, (reg), (val))
end_define

begin_define
define|#
directive|define
name|IWM_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1((sc)->sc_st, (sc)->sc_sh, (reg), (val))
end_define

begin_define
define|#
directive|define
name|IWM_SETBITS
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|mask
parameter_list|)
define|\
value|IWM_WRITE(sc, reg, IWM_READ(sc, reg) | (mask))
end_define

begin_define
define|#
directive|define
name|IWM_CLRBITS
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|mask
parameter_list|)
define|\
value|IWM_WRITE(sc, reg, IWM_READ(sc, reg)& ~(mask))
end_define

begin_define
define|#
directive|define
name|IWM_BARRIER_WRITE
parameter_list|(
name|sc
parameter_list|)
define|\
value|bus_space_barrier((sc)->sc_st, (sc)->sc_sh, 0, (sc)->sc_sz,	\ 	    BUS_SPACE_BARRIER_WRITE)
end_define

begin_define
define|#
directive|define
name|IWM_BARRIER_READ_WRITE
parameter_list|(
name|sc
parameter_list|)
define|\
value|bus_space_barrier((sc)->sc_st, (sc)->sc_sh, 0, (sc)->sc_sz,	\ 	    BUS_SPACE_BARRIER_READ | BUS_SPACE_BARRIER_WRITE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_IWM_REG_H__ */
end_comment

end_unit

