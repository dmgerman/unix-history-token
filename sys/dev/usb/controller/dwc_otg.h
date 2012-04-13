begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2012 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DWC_OTG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DWC_OTG_H_
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MAX_DEVICES
value|(USB_MIN_DEVICES + 1)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_FRAME_MASK
value|0x7FF
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MAX_TXP
value|4
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MAX_TXN
value|(0x200 * DWC_OTG_MAX_TXP)
end_define

begin_comment
comment|/* Global CSR registers */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_REG_GOTGCTL
value|0x0000
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GOTGCTL_CHIRP_ON
value|(1U<< 27)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GOTGCTL_BSESS_VALID
value|(1U<< 19)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GOTGCTL_ASESS_VALID
value|(1U<< 18)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GOTGCTL_CONN_ID_STATUS
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GOTGCTL_SESS_REQ
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GOTGCTL_SESS_VALID
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GOTGINT
value|0x0004
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GAHBCFG
value|0x0008
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GAHBCFG_GLOBAL_IRQ
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GUSBCFG
value|0x000C
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_FORCE_DEVICE
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_FORCE_HOST
value|(1U<< 29)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_NO_PULLUP
value|(1U<< 27)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_NO_PULLUP
value|(1U<< 27)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_IC_USB_CAP
value|(1U<< 26)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_ULPI_FS_LS
value|(1U<< 17)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_TRD_TIM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 15U)<< 10)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_HRP
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_SRP
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_HS_PHY
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_FS_INTF
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_ULPI_UMTI_SEL
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GUSBCFG_PHY_INTF
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GRSTCTL
value|0x0010
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRSTCTL_TXFIFO
parameter_list|(
name|n
parameter_list|)
value|(((n)& 31U)<< 6)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRSTCTL_TXFFLUSH
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRSTCTL_RXFFLUSH
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRSTCTL_FRMCNTRRST
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRSTCTL_CSFTRST
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GINTSTS
value|0x0014
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GINTMSK
value|0x0018
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_WKUPINT
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_SESSREQINT
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_DISCONNINT
value|(1U<< 29)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_CONNIDSTSCHNG
value|(1U<< 28)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_LPM
value|(1U<< 27)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_PTXFEMP
value|(1U<< 26)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_HCHINT
value|(1U<< 25)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_PRTINT
value|(1U<< 24)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_RESETDET
value|(1U<< 23)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_FETSUSP
value|(1U<< 22)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_INCOMPL_P
value|(1U<< 21)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_INCOMPL_ISO_IN
value|(1U<< 20)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_OUTEP
value|(1U<< 19)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_INEP
value|(1U<< 18)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_EP_MISMATCH
value|(1U<< 17)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_RESTORE_DONE
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_EOP_FRAME
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_ISO_OUT_DROP
value|(1U<< 14)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_ENUM_DONE
value|(1U<< 13)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_USB_RESET
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_USB_SUSPEND
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_EARLY_SUSPEND
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_I2C_INT
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_ULPI_CARKIT
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_GLOBAL_OUT_NAK
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_GLOBAL_IN_NAK
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_NPTXFEMP
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_RXFLVL
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_SOF
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_OTG
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_MODE_MISMATCH
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GINT_CUR_MODE
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GRXSTSR
value|0x001C
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GRXSTSP
value|0x0020
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_PACKET_STS
value|(15U<< 17)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_HST_IN_DATA
value|(2U<< 17)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_HST_IN_COMPLETE
value|(3U<< 17)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_HST_DT_ERROR
value|(5U<< 17)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_HST_HALTED
value|(7U<< 17)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_DEV_GLOB_OUT_NAK
value|(1U<< 17)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_DEV_OUT_DATA
value|(2U<< 17)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_DEV_OUT_COMPLETE
value|(3U<< 17)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_DEV_STP_COMPLETE
value|(4U<< 17)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_DEV_STP_DATA
value|(6U<< 17)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_PID
value|(3U<< 15)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_PID_DATA0
value|(0U<< 15)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_PID_DATA1
value|(2U<< 15)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_PID_DATA2
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_PID_MDATA
value|(3U<< 15)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_GET_BYTE_CNT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x7FFU)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_GET_CHANNEL
parameter_list|(
name|x
parameter_list|)
value|((x)& 15U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GRXSTS_GET_FRNUM
value|(x)	(((x)>> 21)& 15U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GRXFSIZ
value|0x0024
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GNPTXFSIZ
value|0x0028
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GNPTXSTS
value|0x002C
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GI2CCTL
value|0x0030
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GPVNDCTL
value|0x0034
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GGPIO
value|0x0038
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GUID
value|0x003C
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GSNPSID
value|0x0040
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GHWCFG1
value|0x0044
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG1_GET_DIR
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|(((x)>> (2 * (n)))& 3U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG1_BIDIR
value|(0U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG1_IN
value|(1U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG1_OUT
value|(2U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GHWCFG2
value|0x0048
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG2_NUM_DEV_EP
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 10)& 15) + 1)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG2_NUM_HOST_EP
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 14)& 15) + 1)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG2_DYN_FIFO
value|(1U<< 19)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG2_MPI
value|(1U<< 20)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GHWCFG3
value|0x004C
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG3_GET_DFIFO
parameter_list|(
name|x
parameter_list|)
value|((x)>> 16)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG3_PKT_SIZE
value|(0x10U<< (((x)>> 4)& 7))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG3_XFR_SIZE
value|(0x400U<< (((x)>> 0)& 15))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GHWCFG4
value|0x0050
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG4_NUM_IN_EPS
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 26)& 15U) + 1U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG4_NUM_CTRL_EPS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 15U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GHWCFG4_NUM_IN_PERIODIC_EPS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 15U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GLPMCFG
value|0x0054
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GLPMCFG_HSIC_CONN
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GPWRDN
value|0x0058
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_BVALID
value|(1U<< 22)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_IDDIG
value|(1U<< 21)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_CONNDET_INT
value|(1U<< 14)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_CONNDET
value|(1U<< 13)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_DISCONN_INT
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_DISCONN
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_RESETDET_INT
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_RESETDET
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_LINESTATE_INT
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_LINESTATE
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_DISABLE_VBUS
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_POWER_DOWN
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_POWER_DOWN_RST
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_POWER_DOWN_CLAMP
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_RESTORE
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_PMU_ACTIVE
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_GPWRDN_PMU_IRQ_SEL
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GDFIFOCFG
value|0x005C
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_GADPCTL
value|0x0060
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HPTXFSIZ
value|0x0100
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DPTXFSIZ
parameter_list|(
name|n
parameter_list|)
value|(0x0100 + (4*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DIEPTXF
parameter_list|(
name|n
parameter_list|)
value|(0x0100 + (4*(n)))
end_define

begin_comment
comment|/* Host Mode CSR registers */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_REG_HCFG
value|0x0400
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HFIR
value|0x0404
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HFNUM
value|0x0408
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HPTXSTS
value|0x0410
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HAINT
value|0x0414
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HAINTMSK
value|0x0418
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HPRT
value|0x0440
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HCCHAR
parameter_list|(
name|n
parameter_list|)
value|(0x0500 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HCSPLT
parameter_list|(
name|n
parameter_list|)
value|(0x0504 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HCINT
parameter_list|(
name|n
parameter_list|)
value|(0x0508 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HCINTMSK
parameter_list|(
name|n
parameter_list|)
value|(0x050C + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HCTSIZ
parameter_list|(
name|n
parameter_list|)
value|(0x0510 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HCDMA
parameter_list|(
name|n
parameter_list|)
value|(0x0514 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_HCDMAB
parameter_list|(
name|n
parameter_list|)
value|(0x051C + (32*(n)))
end_define

begin_comment
comment|/* Device Mode CSR registers */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_REG_DCFG
value|0x0800
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DCFG_SET_DEV_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FU)<< 4)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DCFG_SET_DEV_SPEED
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x3U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DCFG_DEV_SPEED_HI
value|(0U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DCFG_DEV_SPEED_FULL20
value|(1U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DCFG_DEV_SPEED_FULL10
value|(3U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DCTL
value|0x0804
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DCTL_PWRON_PROG_DONE
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DCTL_CGOUT_NAK
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DCTL_CGNPIN_NAK
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DCTL_SOFT_DISC
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DCTL_REMOTE_WAKEUP
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DSTS
value|0x0808
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DSTS_GET_FNUM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x3FFF)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DSTS_GET_ENUM_SPEED
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 3U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DSTS_ENUM_SPEED_HI
value|(0U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DSTS_ENUM_SPEED_FULL20
value|(1U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DSTS_ENUM_SPEED_LOW10
value|(2U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DSTS_ENUM_SPEED_FULL10
value|(3U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DSTS_SUSPEND
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DIEPMSK
value|0x0810
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEP_FIFO_EMPTY
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEP_XFER_COMPLETE
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DOEPMSK
value|0x0814
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEP_FIFO_EMPTY
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEP_XFER_COMPLETE
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DAINT
value|0x0818
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DAINTMSK
value|0x081C
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_ENDPOINT
parameter_list|(
name|x
parameter_list|,
name|in
parameter_list|)
define|\
value|((in) ? (1U<< ((x)& 15U)) : \ 	 (0x10000U<< ((x)& 15U)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DTKNQR1
value|0x0820
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DTKNQR2
value|0x0824
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DTKNQR3
value|0x0830
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DTKNQR4
value|0x0834
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DVBUSDIS
value|0x0828
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DVBUSPULSE
value|0x082C
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DTHRCTL
value|0x0830
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DIEPEMPMSK
value|0x0834
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DEACHINT
value|0x0838
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DEACHINTMSK
value|0x083C
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DIEPEACHMSK
parameter_list|(
name|n
parameter_list|)
value|(0x0840 + (4*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DOEPEACHMSK
parameter_list|(
name|n
parameter_list|)
value|(0x0880 + (4*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DIEPCTL
parameter_list|(
name|n
parameter_list|)
value|(0x0900 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_DISABLE
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_SET_DATA1
value|(1U<< 29)
end_define

begin_comment
comment|/* non-control */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_SET_DATA0
value|(1U<< 28)
end_define

begin_comment
comment|/* non-control */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_SET_NAK
value|(1U<< 27)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_CLR_NAK
value|(1U<< 26)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_FNUM
parameter_list|(
name|n
parameter_list|)
value|(((n)& 15U)<< 22)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_STALL
value|(1U<< 21)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_EP_SET_TYPE
parameter_list|(
name|n
parameter_list|)
value|(((n)& 3)<< 18)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_EP_TYPE_CONTROL
value|(0U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_EP_TYPE_ISOC
value|(1U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_EP_TYPE_BULK
value|(2U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_EP_TYPE_INTERRUPT
value|(3U)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_USB_AEP
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_MPS_64
value|(0U<< 0)
end_define

begin_comment
comment|/* control-only */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_MPS_32
value|(1U<< 0)
end_define

begin_comment
comment|/* control-only */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_MPS_16
value|(2U<< 0)
end_define

begin_comment
comment|/* control-only */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_MPS_8
value|(3U<< 0)
end_define

begin_comment
comment|/* control-only */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DIEPCTL_MPS
parameter_list|(
name|n
parameter_list|)
value|((n)& 0x7FF)
end_define

begin_comment
comment|/* non-control */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_REG_DIEPINT
parameter_list|(
name|n
parameter_list|)
value|(0x0908 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DXEPINT_TXFEMP
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DXEPINT_SETUP
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DXEPINT_XFER_COMPL
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DIEPTSIZ
parameter_list|(
name|n
parameter_list|)
value|(0x0910 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DXEPTSIZ_SET_MULTI
parameter_list|(
name|n
parameter_list|)
value|(((n)& 3)<< 29)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DXEPTSIZ_SET_NPKT
parameter_list|(
name|n
parameter_list|)
value|(((n)& 0x3FF)<< 19)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DXEPTSIZ_GET_NPKT
parameter_list|(
name|n
parameter_list|)
value|(((n)>> 19)& 0x3FF)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DXEPTSIZ_SET_NBYTES
parameter_list|(
name|n
parameter_list|)
value|(((n)& 0x7FFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DXEPTSIZ_GET_NBYTES
parameter_list|(
name|n
parameter_list|)
value|(((n)>> 0)& 0x7FFFFF)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DIEPDMA
parameter_list|(
name|n
parameter_list|)
value|(0x0914 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DTXFSTS
parameter_list|(
name|n
parameter_list|)
value|(0x0918 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DIEPDMAB0
value|(0x091C + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DOEPCTL
parameter_list|(
name|n
parameter_list|)
value|(0x0B00 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_ENABLE
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_DISABLE
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_SET_DATA1
value|(1U<< 29)
end_define

begin_comment
comment|/* non-control */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_SET_DATA0
value|(1U<< 28)
end_define

begin_comment
comment|/* non-control */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_SET_NAK
value|(1U<< 27)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_CLR_NAK
value|(1U<< 26)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_FNUM
parameter_list|(
name|n
parameter_list|)
value|(((n)& 15U)<< 22)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_STALL
value|(1U<< 21)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_EP_TYPE
parameter_list|(
name|n
parameter_list|)
value|(((n)& 3)<< 18)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_USB_AEP
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_MPS_64
value|(0U<< 0)
end_define

begin_comment
comment|/* control-only */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_MPS_32
value|(1U<< 0)
end_define

begin_comment
comment|/* control-only */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_MPS_16
value|(2U<< 0)
end_define

begin_comment
comment|/* control-only */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_MPS_8
value|(3U<< 0)
end_define

begin_comment
comment|/* control-only */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_MSK_DOEPCTL_MPS
parameter_list|(
name|n
parameter_list|)
value|((n)& 0x7FF)
end_define

begin_comment
comment|/* non-control */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_REG_DOEPINT
parameter_list|(
name|n
parameter_list|)
value|(0x0B08 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DOEPTSIZ
parameter_list|(
name|n
parameter_list|)
value|(0x0B10 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DOEPDMA
parameter_list|(
name|n
parameter_list|)
value|(0x0B14 + (32*(n)))
end_define

begin_define
define|#
directive|define
name|DWC_OTG_REG_DOEPDMAB
parameter_list|(
name|n
parameter_list|)
value|(0x0B1C + (32*(n)))
end_define

begin_comment
comment|/* FIFO access registers */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_REG_DFIFO
parameter_list|(
name|n
parameter_list|)
value|(0x1000 + (0x1000 * (n)))
end_define

begin_comment
comment|/* Power and clock gating CSR */
end_comment

begin_define
define|#
directive|define
name|DWC_OTG_REG_PCGCCTL
value|0x0E00
end_define

begin_define
define|#
directive|define
name|DWC_OTG_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_io_tag, (sc)->sc_io_hdl, reg)
end_define

begin_define
define|#
directive|define
name|DWC_OTG_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|data
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_io_tag, (sc)->sc_io_hdl, reg, data)
end_define

begin_struct_decl
struct_decl|struct
name|dwc_otg_td
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dwc_otg_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|uint8_t
function_decl|(
name|dwc_otg_cmd_t
function_decl|)
parameter_list|(
name|struct
name|dwc_otg_td
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|dwc_otg_td
block|{
name|struct
name|dwc_otg_td
modifier|*
name|obj_next
decl_stmt|;
name|dwc_otg_cmd_t
modifier|*
name|func
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|pc
decl_stmt|;
name|uint32_t
name|tx_bytes
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint32_t
name|remainder
decl_stmt|;
name|uint16_t
name|max_packet_size
decl_stmt|;
comment|/* packet_size */
name|uint16_t
name|npkt
decl_stmt|;
name|uint8_t
name|ep_no
decl_stmt|;
name|uint8_t
name|error
range|:
literal|1
decl_stmt|;
name|uint8_t
name|alt_next
range|:
literal|1
decl_stmt|;
name|uint8_t
name|short_pkt
range|:
literal|1
decl_stmt|;
name|uint8_t
name|did_stall
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dwc_otg_std_temp
block|{
name|dwc_otg_cmd_t
modifier|*
name|func
decl_stmt|;
name|struct
name|usb_page_cache
modifier|*
name|pc
decl_stmt|;
name|struct
name|dwc_otg_td
modifier|*
name|td
decl_stmt|;
name|struct
name|dwc_otg_td
modifier|*
name|td_next
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|offset
decl_stmt|;
name|uint16_t
name|max_frame_size
decl_stmt|;
name|uint8_t
name|short_pkt
decl_stmt|;
comment|/* 	 * short_pkt = 0: transfer should be short terminated 	 * short_pkt = 1: transfer should not be short terminated 	 */
name|uint8_t
name|setup_alt_next
decl_stmt|;
name|uint8_t
name|did_stall
decl_stmt|;
name|uint8_t
name|bulk_or_control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dwc_otg_config_desc
block|{
name|struct
name|usb_config_descriptor
name|confd
decl_stmt|;
name|struct
name|usb_interface_descriptor
name|ifcd
decl_stmt|;
name|struct
name|usb_endpoint_descriptor
name|endpd
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_union
union|union
name|dwc_otg_hub_temp
block|{
name|uWord
name|wValue
decl_stmt|;
name|struct
name|usb_port_status
name|ps
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|dwc_otg_flags
block|{
name|uint8_t
name|change_connect
range|:
literal|1
decl_stmt|;
name|uint8_t
name|change_suspend
range|:
literal|1
decl_stmt|;
name|uint8_t
name|status_suspend
range|:
literal|1
decl_stmt|;
comment|/* set if suspended */
name|uint8_t
name|status_vbus
range|:
literal|1
decl_stmt|;
comment|/* set if present */
name|uint8_t
name|status_bus_reset
range|:
literal|1
decl_stmt|;
comment|/* set if reset complete */
name|uint8_t
name|status_high_speed
range|:
literal|1
decl_stmt|;
comment|/* set if High Speed is selected */
name|uint8_t
name|remote_wakeup
range|:
literal|1
decl_stmt|;
name|uint8_t
name|self_powered
range|:
literal|1
decl_stmt|;
name|uint8_t
name|clocks_off
range|:
literal|1
decl_stmt|;
name|uint8_t
name|port_powered
range|:
literal|1
decl_stmt|;
name|uint8_t
name|port_enabled
range|:
literal|1
decl_stmt|;
name|uint8_t
name|d_pulled_up
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dwc_otg_profile
block|{
name|struct
name|usb_hw_ep_profile
name|usb
decl_stmt|;
name|uint16_t
name|max_buffer
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dwc_otg_softc
block|{
name|struct
name|usb_bus
name|sc_bus
decl_stmt|;
name|union
name|dwc_otg_hub_temp
name|sc_hub_temp
decl_stmt|;
name|struct
name|dwc_otg_profile
name|sc_hw_ep_profile
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|usb_device
modifier|*
name|sc_devices
index|[
name|DWC_OTG_MAX_DEVICES
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_io_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|void
modifier|*
name|sc_intr_hdl
decl_stmt|;
name|bus_size_t
name|sc_io_size
decl_stmt|;
name|bus_space_tag_t
name|sc_io_tag
decl_stmt|;
name|bus_space_handle_t
name|sc_io_hdl
decl_stmt|;
name|uint32_t
name|sc_rx_bounce_buffer
index|[
literal|1024
operator|/
literal|4
index|]
decl_stmt|;
name|uint32_t
name|sc_tx_bounce_buffer
index|[
operator|(
literal|512
operator|*
name|DWC_OTG_MAX_TXP
operator|)
operator|/
literal|4
index|]
decl_stmt|;
name|uint32_t
name|sc_fifo_size
decl_stmt|;
name|uint32_t
name|sc_irq_mask
decl_stmt|;
name|uint32_t
name|sc_last_rx_status
decl_stmt|;
name|uint32_t
name|sc_out_ctl
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|sc_in_ctl
index|[
literal|16
index|]
decl_stmt|;
name|uint16_t
name|sc_active_out_ep
decl_stmt|;
name|uint8_t
name|sc_dev_ep_max
decl_stmt|;
name|uint8_t
name|sc_dev_in_ep_max
decl_stmt|;
name|uint8_t
name|sc_rt_addr
decl_stmt|;
comment|/* root HUB address */
name|uint8_t
name|sc_conf
decl_stmt|;
comment|/* root HUB config */
name|uint8_t
name|sc_hub_idata
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|dwc_otg_flags
name|sc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|void
name|dwc_otg_interrupt
parameter_list|(
name|struct
name|dwc_otg_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dwc_otg_init
parameter_list|(
name|struct
name|dwc_otg_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dwc_otg_uninit
parameter_list|(
name|struct
name|dwc_otg_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DWC_OTG_H_ */
end_comment

end_unit

