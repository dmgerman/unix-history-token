begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Damjan Marion<dmarion@Freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AM335X_DMTREG_H
end_ifndef

begin_define
define|#
directive|define
name|AM335X_DMTREG_H
end_define

begin_define
define|#
directive|define
name|AM335X_NUM_TIMERS
value|8
end_define

begin_define
define|#
directive|define
name|DMT_TIDR
value|0x00
end_define

begin_comment
comment|/* Identification Register */
end_comment

begin_define
define|#
directive|define
name|DMT_TIOCP_CFG
value|0x10
end_define

begin_comment
comment|/* OCP Configuration Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TIOCP_RESET
value|(1<< 0)
end_define

begin_comment
comment|/* TIOCP perform soft reset */
end_comment

begin_define
define|#
directive|define
name|DMT_IQR_EOI
value|0x20
end_define

begin_comment
comment|/* IRQ End-Of-Interrupt Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQSTATUS_RAW
value|0x24
end_define

begin_comment
comment|/* IRQSTATUS Raw Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQSTATUS
value|0x28
end_define

begin_comment
comment|/* IRQSTATUS Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQENABLE_SET
value|0x2c
end_define

begin_comment
comment|/* IRQSTATUS Set Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQENABLE_CLR
value|0x30
end_define

begin_comment
comment|/* IRQSTATUS Clear Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQWAKEEN
value|0x34
end_define

begin_comment
comment|/* IRQ Wakeup Enable Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQ_MAT
value|(1<< 0)
end_define

begin_comment
comment|/* IRQ: Match */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQ_OVF
value|(1<< 1)
end_define

begin_comment
comment|/* IRQ: Overflow */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQ_TCAR
value|(1<< 2)
end_define

begin_comment
comment|/* IRQ: Capture */
end_comment

begin_define
define|#
directive|define
name|DMT_IRQ_MASK
value|(DMT_IRQ_TCAR | DMT_IRQ_OVF | DMT_IRQ_MAT)
end_define

begin_define
define|#
directive|define
name|DMT_TCLR
value|0x38
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_START
value|(1<< 0)
end_define

begin_comment
comment|/* Start timer */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_AUTOLOAD
value|(1<< 1)
end_define

begin_comment
comment|/* Auto-reload on overflow */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_PRES_MASK
value|(7<< 2)
end_define

begin_comment
comment|/* Prescaler mask */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_PRES_ENABLE
value|(1<< 5)
end_define

begin_comment
comment|/* Prescaler enable */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_COMP_ENABLE
value|(1<< 6)
end_define

begin_comment
comment|/* Compare enable */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_PWM_HIGH
value|(1<< 7)
end_define

begin_comment
comment|/* PWM default output high */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_CAPTRAN_MASK
value|(3<< 8)
end_define

begin_comment
comment|/* Capture transition mask */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_CAPTRAN_NONE
value|(0<< 8)
end_define

begin_comment
comment|/* Capture: none */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_CAPTRAN_LOHI
value|(1<< 8)
end_define

begin_comment
comment|/* Capture lo->hi transition */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_CAPTRAN_HILO
value|(2<< 8)
end_define

begin_comment
comment|/* Capture hi->lo transition */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_CAPTRAN_BOTH
value|(3<< 8)
end_define

begin_comment
comment|/* Capture both transitions */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_TRGMODE_MASK
value|(3<< 10)
end_define

begin_comment
comment|/* Trigger output mode mask */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_TRGMODE_NONE
value|(0<< 10)
end_define

begin_comment
comment|/* Trigger off */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_TRGMODE_OVFL
value|(1<< 10)
end_define

begin_comment
comment|/* Trigger on overflow */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_TRGMODE_BOTH
value|(2<< 10)
end_define

begin_comment
comment|/* Trigger on match + ovflow */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_PWM_PTOGGLE
value|(1<< 12)
end_define

begin_comment
comment|/* PWM toggles */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_CAP_MODE_2ND
value|(1<< 13)
end_define

begin_comment
comment|/* Capture second event mode */
end_comment

begin_define
define|#
directive|define
name|DMT_TCLR_GPO_CFG
value|(1<< 14)
end_define

begin_comment
comment|/* Tmr pin conf, 0=out, 1=in */
end_comment

begin_define
define|#
directive|define
name|DMT_TCRR
value|0x3C
end_define

begin_comment
comment|/* Counter Register */
end_comment

begin_define
define|#
directive|define
name|DMT_TLDR
value|0x40
end_define

begin_comment
comment|/* Load Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TTGR
value|0x44
end_define

begin_comment
comment|/* Trigger Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TWPS
value|0x48
end_define

begin_comment
comment|/* Write Posted Status Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TMAR
value|0x4C
end_define

begin_comment
comment|/* Match Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TCAR1
value|0x50
end_define

begin_comment
comment|/* Capture Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TSICR
value|0x54
end_define

begin_comment
comment|/* Synchr. Interface Ctrl Reg */
end_comment

begin_define
define|#
directive|define
name|DMT_TSICR_RESET
value|(1<< 1)
end_define

begin_comment
comment|/* TSICR perform soft reset */
end_comment

begin_define
define|#
directive|define
name|DMT_TCAR2
value|0x48
end_define

begin_comment
comment|/* Capture Reg */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AM335X_DMTREG_H */
end_comment

end_unit

