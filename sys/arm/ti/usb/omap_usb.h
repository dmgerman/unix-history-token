begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010  *	Ben Gray<ben.r.gray@gmail.com>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Ben Gray.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BEN GRAY ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BEN GRAY BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OMAP_USB_H_
end_ifndef

begin_define
define|#
directive|define
name|_OMAP_USB_H_
end_define

begin_comment
comment|/*  * USB TTL Module  */
end_comment

begin_define
define|#
directive|define
name|OMAP_USBTLL_REVISION
value|0x0000
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_SYSCONFIG
value|0x0010
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_SYSSTATUS
value|0x0014
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_IRQSTATUS
value|0x0018
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_IRQENABLE
value|0x001C
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_TLL_SHARED_CONF
value|0x0030
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_TLL_CHANNEL_CONF
parameter_list|(
name|i
parameter_list|)
value|(0x0040 + (0x04 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_SAR_CNTX
parameter_list|(
name|i
parameter_list|)
value|(0x0400 + (0x04 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_ID_LO
parameter_list|(
name|i
parameter_list|)
value|(0x0800 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_ID_HI
parameter_list|(
name|i
parameter_list|)
value|(0x0801 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_PRODUCT_ID_LO
parameter_list|(
name|i
parameter_list|)
value|(0x0802 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_PRODUCT_ID_HI
parameter_list|(
name|i
parameter_list|)
value|(0x0803 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_FUNCTION_CTRL
parameter_list|(
name|i
parameter_list|)
value|(0x0804 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_FUNCTION_CTRL_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0805 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_FUNCTION_CTRL_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0806 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_INTERFACE_CTRL
parameter_list|(
name|i
parameter_list|)
value|(0x0807 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_INTERFACE_CTRL_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0808 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_INTERFACE_CTRL_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0809 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_OTG_CTRL
parameter_list|(
name|i
parameter_list|)
value|(0x080A + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_OTG_CTRL_SET
parameter_list|(
name|i
parameter_list|)
value|(0x080B + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_OTG_CTRL_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x080C + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_EN_RISE
parameter_list|(
name|i
parameter_list|)
value|(0x080D + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_EN_RISE_SET
parameter_list|(
name|i
parameter_list|)
value|(0x080E + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_EN_RISE_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x080F + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_EN_FALL
parameter_list|(
name|i
parameter_list|)
value|(0x0810 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_EN_FALL_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0811 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_EN_FALL_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0812 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_STATUS
parameter_list|(
name|i
parameter_list|)
value|(0x0813 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_LATCH
parameter_list|(
name|i
parameter_list|)
value|(0x0814 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_DEBUG
parameter_list|(
name|i
parameter_list|)
value|(0x0815 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_SCRATCH_REGISTER
parameter_list|(
name|i
parameter_list|)
value|(0x0816 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_SCRATCH_REGISTER_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0817 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_SCRATCH_REGISTER_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0818 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_EXTENDED_SET_ACCESS
parameter_list|(
name|i
parameter_list|)
value|(0x082F + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VCONTROL_EN
parameter_list|(
name|i
parameter_list|)
value|(0x0830 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VCONTROL_EN_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0831 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VCONTROL_EN_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0832 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VCONTROL_STATUS
parameter_list|(
name|i
parameter_list|)
value|(0x0833 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VCONTROL_LATCH
parameter_list|(
name|i
parameter_list|)
value|(0x0834 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VSTATUS
parameter_list|(
name|i
parameter_list|)
value|(0x0835 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VSTATUS_SET
parameter_list|(
name|i
parameter_list|)
value|(0x0836 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_UTMI_VSTATUS_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x0837 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_USB_INT_LATCH_NOCLR
parameter_list|(
name|i
parameter_list|)
value|(0x0838 + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_INT_EN
parameter_list|(
name|i
parameter_list|)
value|(0x083B + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_INT_EN_SET
parameter_list|(
name|i
parameter_list|)
value|(0x083C + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_INT_EN_CLR
parameter_list|(
name|i
parameter_list|)
value|(0x083D + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_INT_STATUS
parameter_list|(
name|i
parameter_list|)
value|(0x083E + (0x100 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBTLL_ULPI_VENDOR_INT_LATCH
parameter_list|(
name|i
parameter_list|)
value|(0x083F + (0x100 * (i)))
end_define

begin_comment
comment|/*  * USB Host Module  */
end_comment

begin_comment
comment|/* UHH */
end_comment

begin_define
define|#
directive|define
name|OMAP_USBHOST_UHH_REVISION
value|0x0000
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_UHH_SYSCONFIG
value|0x0010
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_UHH_SYSSTATUS
value|0x0014
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_UHH_HOSTCONFIG
value|0x0040
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_UHH_DEBUG_CSR
value|0x0044
end_define

begin_comment
comment|/* EHCI */
end_comment

begin_define
define|#
directive|define
name|OMAP_USBHOST_HCCAPBASE
value|0x0000
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_HCSPARAMS
value|0x0004
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_HCCPARAMS
value|0x0008
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_USBCMD
value|0x0010
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_USBSTS
value|0x0014
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_USBINTR
value|0x0018
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_FRINDEX
value|0x001C
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_CTRLDSSEGMENT
value|0x0020
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_PERIODICLISTBASE
value|0x0024
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_ASYNCLISTADDR
value|0x0028
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_CONFIGFLAG
value|0x0050
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_PORTSC
parameter_list|(
name|i
parameter_list|)
value|(0x0054 + (0x04 * (i)))
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG00
value|0x0090
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG01
value|0x0094
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG02
value|0x0098
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG03
value|0x009C
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG04
value|0x00A0
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG05_UTMI
value|0x00A4
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG05_ULPI
value|0x00A4
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG06
value|0x00A8
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG07
value|0x00AC
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG08
value|0x00B0
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG04_DISABLE_UNSUSPEND
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG05_ULPI_CONTROL_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG05_ULPI_PORTSEL_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG05_ULPI_OPSEL_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG05_ULPI_REGADD_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG05_ULPI_EXTREGADD_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|OMAP_USBHOST_INSNREG05_ULPI_WRDATA_SHIFT
value|0
end_define

begin_comment
comment|/* TLL Register Set */
end_comment

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_CACTIVITY
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_SIDLE_SMART_IDLE
value|(2UL<< 3)
end_define

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_SIDLE_NO_IDLE
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_SIDLE_FORCED_IDLE
value|(0UL<< 3)
end_define

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_ENAWAKEUP
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_SOFTRESET
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|TLL_SYSCONFIG_AUTOIDLE
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|TLL_SYSSTATUS_RESETDONE
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_90D_DDR_EN
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_180D_SDR_EN
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_MASK
value|(7UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_128
value|(7UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_64
value|(6UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_32
value|(5UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_16
value|(4UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_8
value|(3UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_4
value|(2UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_2
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_USB_DIVRATIO_1
value|(0UL<< 2)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_FCLK_REQ
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|TLL_SHARED_CONF_FCLK_IS_ON
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_DRVVBUS
value|(1UL<< 16)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_CHRGVBUS
value|(1UL<< 15)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_ULPINOBITSTUFF
value|(1UL<< 11)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_ULPIAUTOIDLE
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_UTMIAUTOIDLE
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_ULPIDDRMODE
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_ULPIOUTCLKMODE
value|(1UL<< 7)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_TLLFULLSPEED
value|(1UL<< 6)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_TLLCONNECT
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_TLLATTACH
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_UTMIISADEV
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|TLL_CHANNEL_CONF_CHANEN
value|(1UL<< 0)
end_define

begin_comment
comment|/* UHH Register Set */
end_comment

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_MIDLEMODE_MASK
value|(3UL<< 12)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_MIDLEMODE_SMARTSTANDBY
value|(2UL<< 12)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_MIDLEMODE_NOSTANDBY
value|(1UL<< 12)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_MIDLEMODE_FORCESTANDBY
value|(0UL<< 12)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_CLOCKACTIVITY
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_SIDLEMODE_MASK
value|(3UL<< 3)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_SIDLEMODE_SMARTIDLE
value|(2UL<< 3)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_SIDLEMODE_NOIDLE
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_SIDLEMODE_FORCEIDLE
value|(0UL<< 3)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_ENAWAKEUP
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_SOFTRESET
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_AUTOIDLE
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_APP_START_CLK
value|(1UL<< 31)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_P3_CONNECT_STATUS
value|(1UL<< 10)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_P2_CONNECT_STATUS
value|(1UL<< 9)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_P1_CONNECT_STATUS
value|(1UL<< 8)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_ENA_INCR_ALIGN
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_ENA_INCR16
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_ENA_INCR8
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_ENA_INCR4
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_AUTOPPD_ON_OVERCUR_EN
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_P1_ULPI_BYPASS
value|(1UL<< 0)
end_define

begin_comment
comment|/* The following are on rev2 (OMAP44xx) of the EHCI only */
end_comment

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_IDLEMODE_MASK
value|(3UL<< 2)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_IDLEMODE_NOIDLE
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_STANDBYMODE_MASK
value|(3UL<< 4)
end_define

begin_define
define|#
directive|define
name|UHH_SYSCONFIG_STANDBYMODE_NOSTDBY
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_P1_MODE_MASK
value|(3UL<< 16)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_P1_MODE_ULPI_PHY
value|(0UL<< 16)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_P1_MODE_UTMI_PHY
value|(1UL<< 16)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_P1_MODE_HSIC
value|(3UL<< 16)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_P2_MODE_MASK
value|(3UL<< 18)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_P2_MODE_ULPI_PHY
value|(0UL<< 18)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_P2_MODE_UTMI_PHY
value|(1UL<< 18)
end_define

begin_define
define|#
directive|define
name|UHH_HOSTCONFIG_P2_MODE_HSIC
value|(3UL<< 18)
end_define

begin_define
define|#
directive|define
name|ULPI_FUNC_CTRL_RESET
value|(1<< 5)
end_define

begin_comment
comment|/*-------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*  * Macros for Set and Clear  * See ULPI 1.1 specification to find the registers with Set and Clear offsets  */
end_comment

begin_define
define|#
directive|define
name|ULPI_SET
parameter_list|(
name|a
parameter_list|)
value|(a + 1)
end_define

begin_define
define|#
directive|define
name|ULPI_CLR
parameter_list|(
name|a
parameter_list|)
value|(a + 2)
end_define

begin_comment
comment|/*-------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*  * Register Map  */
end_comment

begin_define
define|#
directive|define
name|ULPI_VENDOR_ID_LOW
value|0x00
end_define

begin_define
define|#
directive|define
name|ULPI_VENDOR_ID_HIGH
value|0x01
end_define

begin_define
define|#
directive|define
name|ULPI_PRODUCT_ID_LOW
value|0x02
end_define

begin_define
define|#
directive|define
name|ULPI_PRODUCT_ID_HIGH
value|0x03
end_define

begin_define
define|#
directive|define
name|ULPI_FUNC_CTRL
value|0x04
end_define

begin_define
define|#
directive|define
name|ULPI_IFC_CTRL
value|0x07
end_define

begin_define
define|#
directive|define
name|ULPI_OTG_CTRL
value|0x0a
end_define

begin_define
define|#
directive|define
name|ULPI_USB_INT_EN_RISE
value|0x0d
end_define

begin_define
define|#
directive|define
name|ULPI_USB_INT_EN_FALL
value|0x10
end_define

begin_define
define|#
directive|define
name|ULPI_USB_INT_STS
value|0x13
end_define

begin_define
define|#
directive|define
name|ULPI_USB_INT_LATCH
value|0x14
end_define

begin_define
define|#
directive|define
name|ULPI_DEBUG
value|0x15
end_define

begin_define
define|#
directive|define
name|ULPI_SCRATCH
value|0x16
end_define

begin_comment
comment|/*   * Values of UHH_REVISION - Note: these are not given in the TRM but taken  * from the linux OMAP EHCI driver (thanks guys).  It has been verified on  * a Panda and Beagle board.  */
end_comment

begin_define
define|#
directive|define
name|OMAP_EHCI_REV1
value|0x00000010
end_define

begin_comment
comment|/* OMAP3 */
end_comment

begin_define
define|#
directive|define
name|OMAP_EHCI_REV2
value|0x50700100
end_define

begin_comment
comment|/* OMAP4 */
end_comment

begin_define
define|#
directive|define
name|EHCI_VENDORID_OMAP3
value|0x42fa05
end_define

begin_define
define|#
directive|define
name|OMAP_EHCI_HC_DEVSTR
value|"TI OMAP USB 2.0 controller"
end_define

begin_define
define|#
directive|define
name|EHCI_HCD_OMAP_MODE_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|EHCI_HCD_OMAP_MODE_PHY
value|1
end_define

begin_define
define|#
directive|define
name|EHCI_HCD_OMAP_MODE_TLL
value|2
end_define

begin_define
define|#
directive|define
name|EHCI_HCD_OMAP_MODE_HSIC
value|3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OMAP_USB_H_ */
end_comment

end_unit

