begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Semen Ustimenko (semenu@FreeBSD.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_ACPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_ACPHYREG_H_
end_define

begin_comment
comment|/*  * Register definitions for the Altima Communications AC101  */
end_comment

begin_define
define|#
directive|define
name|MII_ACPHY_POL
value|0x10
end_define

begin_comment
comment|/* Polarity int level */
end_comment

begin_comment
comment|/* High byte is interrupt mask register */
end_comment

begin_define
define|#
directive|define
name|MII_ACPHY_INT
value|0x11
end_define

begin_comment
comment|/* Interrupt control/status */
end_comment

begin_define
define|#
directive|define
name|AC_INT_ACOMP
value|0x0001
end_define

begin_comment
comment|/* Autoneg complete */
end_comment

begin_define
define|#
directive|define
name|AC_INT_REM_FLT
value|0x0002
end_define

begin_comment
comment|/* Remote fault */
end_comment

begin_define
define|#
directive|define
name|AC_INT_LINK_DOWN
value|0x0004
end_define

begin_comment
comment|/* Link not OK */
end_comment

begin_define
define|#
directive|define
name|AC_INT_LP_ACK
value|0x0008
end_define

begin_comment
comment|/* FLP ack recved */
end_comment

begin_define
define|#
directive|define
name|AC_INT_PD_FLT
value|0x0010
end_define

begin_comment
comment|/* Parallel detect fault */
end_comment

begin_define
define|#
directive|define
name|AC_INT_PAGE_RECV
value|0x0020
end_define

begin_comment
comment|/* New page recved */
end_comment

begin_define
define|#
directive|define
name|AC_INT_RX_ER
value|0x0040
end_define

begin_comment
comment|/* RX_ER transitions high */
end_comment

begin_define
define|#
directive|define
name|AC_INT_JAB
value|0x0080
end_define

begin_comment
comment|/* Jabber detected */
end_comment

begin_define
define|#
directive|define
name|MII_ACPHY_DIAG
value|0x12
end_define

begin_comment
comment|/* Diagnostic */
end_comment

begin_define
define|#
directive|define
name|AC_DIAG_RX_LOCK
value|0x0100
end_define

begin_define
define|#
directive|define
name|AC_DIAG_RX_PASS
value|0x0200
end_define

begin_define
define|#
directive|define
name|AC_DIAG_SPEED
value|0x0400
end_define

begin_comment
comment|/* Aneg speed result */
end_comment

begin_define
define|#
directive|define
name|AC_DIAG_DUPLEX
value|0x0800
end_define

begin_comment
comment|/* Aneg duplex result */
end_comment

begin_define
define|#
directive|define
name|MII_ACPHY_PWRLOOP
value|0x13
end_define

begin_comment
comment|/* Power/Loopback */
end_comment

begin_define
define|#
directive|define
name|MII_ACPHY_CBLMEAS
value|0x14
end_define

begin_comment
comment|/* Cable meas. */
end_comment

begin_define
define|#
directive|define
name|MII_ACPHY_MCTL
value|0x15
end_define

begin_comment
comment|/* Mode control */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_FX_SEL
value|0x0001
end_define

begin_comment
comment|/* FX mode */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_BYP_PCS
value|0x0002
end_define

begin_comment
comment|/* Bypass PCS */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_SCRMBL
value|0x0004
end_define

begin_comment
comment|/* Data scrambling */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_REM_LOOP
value|0x0008
end_define

begin_comment
comment|/* Remote loopback */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_DIS_WDT
value|0x0010
end_define

begin_comment
comment|/* Disable watchdog timer */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_DIS_REC
value|0x0020
end_define

begin_comment
comment|/* Disable recv error counter */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_REC_FULL
value|0x0040
end_define

begin_comment
comment|/* Recv error counter full */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_FRC_FEF
value|0x0080
end_define

begin_comment
comment|/* Force Far End Fault Insert. */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_DIS_FEF
value|0x0100
end_define

begin_comment
comment|/* Disable FEF Insertion */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_LED_SEL
value|0x0200
end_define

begin_comment
comment|/* Compat LED config */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_ALED_SEL
value|0x0400
end_define

begin_comment
comment|/* ActLED RX&TX - RX only */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_10BT_SEL
value|0x0800
end_define

begin_comment
comment|/* Enable 7-wire interface */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_DIS_JAB
value|0x1000
end_define

begin_comment
comment|/* Disable jabber */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_FRC_LINK
value|0x2000
end_define

begin_comment
comment|/* Force TX link up */
end_comment

begin_define
define|#
directive|define
name|AC_MCTL_DIS_NLP
value|0x4000
end_define

begin_comment
comment|/* Disable NLP check */
end_comment

begin_define
define|#
directive|define
name|MII_ACPHY_REC
value|0x18
end_define

begin_comment
comment|/* Recv error counter */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_ACPHYREG_H_ */
end_comment

end_unit

