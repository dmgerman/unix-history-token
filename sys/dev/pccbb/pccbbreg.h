begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000,2001 Jonathan Chen.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1998, 1999 and 2000  *      HAYAKAWA Koichi.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by HAYAKAWA Koichi.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Register definitions for PCI to Cardbus Bridge chips  */
end_comment

begin_comment
comment|/* PCI header registers */
end_comment

begin_define
define|#
directive|define
name|CBBR_SOCKBASE
value|0x10
end_define

begin_comment
comment|/* len=4 */
end_comment

begin_define
define|#
directive|define
name|CBBR_MEMBASE0
value|0x1c
end_define

begin_comment
comment|/* len=4 */
end_comment

begin_define
define|#
directive|define
name|CBBR_MEMLIMIT0
value|0x20
end_define

begin_comment
comment|/* len=4 */
end_comment

begin_define
define|#
directive|define
name|CBBR_MEMBASE1
value|0x24
end_define

begin_comment
comment|/* len=4 */
end_comment

begin_define
define|#
directive|define
name|CBBR_MEMLIMIT1
value|0x28
end_define

begin_comment
comment|/* len=4 */
end_comment

begin_define
define|#
directive|define
name|CBBR_IOBASE0
value|0x2c
end_define

begin_comment
comment|/* len=4 */
end_comment

begin_define
define|#
directive|define
name|CBBR_IOLIMIT0
value|0x30
end_define

begin_comment
comment|/* len=4 */
end_comment

begin_define
define|#
directive|define
name|CBBR_IOBASE1
value|0x34
end_define

begin_comment
comment|/* len=4 */
end_comment

begin_define
define|#
directive|define
name|CBBR_IOLIMIT1
value|0x38
end_define

begin_comment
comment|/* len=4 */
end_comment

begin_define
define|#
directive|define
name|CBB_MEMALIGN
value|4096
end_define

begin_define
define|#
directive|define
name|CBB_IOALIGN
value|4
end_define

begin_define
define|#
directive|define
name|CBBR_INTRLINE
value|0x3c
end_define

begin_comment
comment|/* len=1 */
end_comment

begin_define
define|#
directive|define
name|CBBR_INTRPIN
value|0x3d
end_define

begin_comment
comment|/* len=1 */
end_comment

begin_define
define|#
directive|define
name|CBBR_BRIDGECTRL
value|0x3e
end_define

begin_comment
comment|/* len=2 */
end_comment

begin_define
define|#
directive|define
name|CBBM_BRIDGECTRL_MASTER_ABORT
value|0x0020
end_define

begin_define
define|#
directive|define
name|CBBM_BRIDGECTRL_RESET
value|0x0040
end_define

begin_define
define|#
directive|define
name|CBBM_BRIDGECTRL_INTR_IREQ_EN
value|0x0080
end_define

begin_define
define|#
directive|define
name|CBBM_BRIDGECTRL_PREFETCH_0
value|0x0100
end_define

begin_define
define|#
directive|define
name|CBBM_BRIDGECTRL_PREFETCH_1
value|0x0200
end_define

begin_define
define|#
directive|define
name|CBBM_BRIDGECTRL_WRITE_POST_EN
value|0x0400
end_define

begin_comment
comment|/* additional bit for RF5C46[567] */
end_comment

begin_define
define|#
directive|define
name|CBBM_BRIDGECTRL_RL_3E0_EN
value|0x0800
end_define

begin_define
define|#
directive|define
name|CBBM_BRIDGECTRL_RL_3E2_EN
value|0x1000
end_define

begin_define
define|#
directive|define
name|CBBR_LEGACY
value|0x44
end_define

begin_comment
comment|/* len=4 */
end_comment

begin_define
define|#
directive|define
name|CBBR_CBCTRL
value|0x91
end_define

begin_comment
comment|/* len=1 */
end_comment

begin_comment
comment|/* bits for TI 113X */
end_comment

begin_define
define|#
directive|define
name|CBBM_CBCTRL_113X_RI_EN
value|0x80
end_define

begin_define
define|#
directive|define
name|CBBM_CBCTRL_113X_ZV_EN
value|0x40
end_define

begin_define
define|#
directive|define
name|CBBM_CBCTRL_113X_PCI_IRQ_EN
value|0x20
end_define

begin_define
define|#
directive|define
name|CBBM_CBCTRL_113X_PCI_INTR
value|0x10
end_define

begin_define
define|#
directive|define
name|CBBM_CBCTRL_113X_PCI_CSC
value|0x08
end_define

begin_define
define|#
directive|define
name|CBBM_CBCTRL_113X_PCI_CSC_D
value|0x04
end_define

begin_define
define|#
directive|define
name|CBBM_CBCTRL_113X_SPEAKER_EN
value|0x02
end_define

begin_define
define|#
directive|define
name|CBBM_CBCTRL_113X_INTR_DET
value|0x01
end_define

begin_comment
comment|/* bits for TI 12XX */
end_comment

begin_define
define|#
directive|define
name|CBBM_CBCTRL_12XX_RI_EN
value|0x80
end_define

begin_define
define|#
directive|define
name|CBBM_CBCTRL_12XX_ZV_EN
value|0x40
end_define

begin_define
define|#
directive|define
name|CBBM_CBCTRL_12XX_AUD2MUX
value|0x04
end_define

begin_define
define|#
directive|define
name|CBBM_CBCTRL_12XX_SPEAKER_EN
value|0x02
end_define

begin_define
define|#
directive|define
name|CBBM_CBCTRL_12XX_INTR_DET
value|0x01
end_define

begin_define
define|#
directive|define
name|CBBR_DEVCTRL
value|0x92
end_define

begin_comment
comment|/* len=1 */
end_comment

begin_define
define|#
directive|define
name|CBBM_DEVCTRL_INT_SERIAL
value|0x04
end_define

begin_define
define|#
directive|define
name|CBBM_DEVCTRL_INT_PCI
value|0x02
end_define

begin_comment
comment|/* ToPIC 95 ONLY */
end_comment

begin_define
define|#
directive|define
name|CBBR_TOPIC_SOCKETCTRL
value|0x90
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_SOCKETCTRL_SCR_IRQSEL
value|0x00000001
end_define

begin_comment
comment|/* PCI intr */
end_comment

begin_comment
comment|/* ToPIC 97, 100 */
end_comment

begin_define
define|#
directive|define
name|CBBR_TOPIC_ZV_CONTROL
value|0x9c
end_define

begin_comment
comment|/* 1 byte */
end_comment

begin_define
define|#
directive|define
name|CBBM_TOPIC_ZVC_ENABLE
value|0x1
end_define

begin_comment
comment|/* TOPIC 95+ */
end_comment

begin_define
define|#
directive|define
name|CBBR_TOPIC_SLOTCTRL
value|0xa0
end_define

begin_comment
comment|/* 1 byte */
end_comment

begin_define
define|#
directive|define
name|CBBM_TOPIC_SLOTCTRL_SLOTON
value|0x80
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_SLOTCTRL_SLOTEN
value|0x40
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_SLOTCTRL_ID_LOCK
value|0x20
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_SLOTCTRL_ID_WP
value|0x10
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_SLOTCTRL_PORT_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_SLOTCTRL_PORT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_SLOTCTRL_OSF_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_SLOTCTRL_OSF_SHIFT
value|0
end_define

begin_comment
comment|/* TOPIC 95+ */
end_comment

begin_define
define|#
directive|define
name|CBBR_TOPIC_INTCTRL
value|0xa1
end_define

begin_comment
comment|/* 1 byte */
end_comment

begin_define
define|#
directive|define
name|CBBM_TOPIC_INTCTRL_INTB
value|0x20
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_INTCTRL_INTA
value|0x10
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_INTCTRL_INT_MASK
value|0x30
end_define

begin_comment
comment|/* The following bits may be for ToPIC 95 only */
end_comment

begin_define
define|#
directive|define
name|CBBM_TOPIC_INTCTRL_CLOCK_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_INTCTRL_CLOCK_2
value|0x08
end_define

begin_comment
comment|/* PCI Clk/2 */
end_comment

begin_define
define|#
directive|define
name|CBBM_TOPIC_INTCTRL_CLOCK_1
value|0x04
end_define

begin_comment
comment|/* PCI Clk */
end_comment

begin_define
define|#
directive|define
name|CBBM_TOPIC_INTCTRL_CLOCK_0
value|0x00
end_define

begin_comment
comment|/* no clock */
end_comment

begin_comment
comment|/* ToPIC97, 100 defines the following bits */
end_comment

begin_define
define|#
directive|define
name|CBBM_TOPIC_INTCTRL_STSIRQNP
value|0x04
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_INTCTRL_IRQNP
value|0x02
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_INTCTRL_INTIRQSEL
value|0x01
end_define

begin_comment
comment|/* TOPIC 95+ */
end_comment

begin_define
define|#
directive|define
name|CBBR_TOPIC_CDC
value|0xa3
end_define

begin_comment
comment|/* 1 byte */
end_comment

begin_define
define|#
directive|define
name|CBBM_TOPIC_CDC_CARDBUS
value|0x80
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_CDC_VS1
value|0x04
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_CDC_VS2
value|0x02
end_define

begin_define
define|#
directive|define
name|CBBM_TOPIC_CDC_SWDETECT
value|0x01
end_define

begin_comment
comment|/* Socket definitions */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_EVENT_CSTS
value|0x01
end_define

begin_comment
comment|/* Card Status Change */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_EVENT_CD1
value|0x02
end_define

begin_comment
comment|/* Card Detect 1 */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_EVENT_CD2
value|0x04
end_define

begin_comment
comment|/* Card Detect 2 */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_EVENT_CD
value|0x06
end_define

begin_comment
comment|/* Card Detect all */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_EVENT_POWER
value|0x08
end_define

begin_comment
comment|/* Power Cycle */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_MASK_CSTS
value|0x01
end_define

begin_comment
comment|/* Card Status Change */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_MASK_CD
value|0x06
end_define

begin_comment
comment|/* Card Detect */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_MASK_POWER
value|0x08
end_define

begin_comment
comment|/* Power Cycle */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_CARDSTS
value|0x00000001
end_define

begin_comment
comment|/* Card Status Change */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_CD1
value|0x00000002
end_define

begin_comment
comment|/* Card Detect 1 */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_CD2
value|0x00000004
end_define

begin_comment
comment|/* Card Detect 2 */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_CD
value|0x00000006
end_define

begin_comment
comment|/* Card Detect all */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_PWRCYCLE
value|0x00000008
end_define

begin_comment
comment|/* Power Cycle */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_16BIT
value|0x00000010
end_define

begin_comment
comment|/* 16-bit Card */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_CB
value|0x00000020
end_define

begin_comment
comment|/* Cardbus Card */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_IREQ
value|0x00000040
end_define

begin_comment
comment|/* Ready */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_NOTCARD
value|0x00000080
end_define

begin_comment
comment|/* Unrecognized Card */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_DATALOST
value|0x00000100
end_define

begin_comment
comment|/* Data Lost */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_BADVCC
value|0x00000200
end_define

begin_comment
comment|/* Bad VccRequest */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_5VCARD
value|0x00000400
end_define

begin_comment
comment|/* 5 V Card */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_3VCARD
value|0x00000800
end_define

begin_comment
comment|/* 3.3 V Card */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_XVCARD
value|0x00001000
end_define

begin_comment
comment|/* X.X V Card */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_YVCARD
value|0x00002000
end_define

begin_comment
comment|/* Y.Y V Card */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_5VSOCK
value|0x10000000
end_define

begin_comment
comment|/* 5 V Socket */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_3VSOCK
value|0x20000000
end_define

begin_comment
comment|/* 3.3 V Socket */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_XVSOCK
value|0x40000000
end_define

begin_comment
comment|/* X.X V Socket */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_STAT_YVSOCK
value|0x80000000
end_define

begin_comment
comment|/* Y.Y V Socket */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_FORCE_BADVCC
value|0x0200
end_define

begin_comment
comment|/* Bad Vcc Request */
end_comment

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VPPMASK
value|0x07
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VPP_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VPP_12V
value|0x01
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VPP_5V
value|0x02
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VPP_3V
value|0x03
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VPP_XV
value|0x04
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VPP_YV
value|0x05
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VCCMASK
value|0x70
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VCC_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VCC_5V
value|0x20
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VCC_3V
value|0x30
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VCC_XV
value|0x40
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_VCC_YV
value|0x50
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CTRL_STOPCLK
value|0x80
end_define

begin_include
include|#
directive|include
file|<dev/pccbb/pccbbdevid.h>
end_include

begin_define
define|#
directive|define
name|CBB_SOCKET_EVENT
value|0x00
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_STATE
value|0x08
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_FORCE
value|0x0c
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_CONTROL
value|0x10
end_define

begin_define
define|#
directive|define
name|CBB_SOCKET_POWER
value|0x14
end_define

end_unit

