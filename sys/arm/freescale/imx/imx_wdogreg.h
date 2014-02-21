begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012, 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Oleksandr Rybalko under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.	Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2.	Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|WDOG_CLK_FREQ
value|32768
end_define

begin_define
define|#
directive|define
name|WDOG_CR_REG
value|0x00
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|WDOG_CR_WT_MASK
value|0xff00
end_define

begin_comment
comment|/* Count of 0.5 sec */
end_comment

begin_define
define|#
directive|define
name|WDOG_CR_WT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|WDOG_CR_WDW
value|(1<< 7)
end_define

begin_comment
comment|/* Suspend WDog */
end_comment

begin_define
define|#
directive|define
name|WDOG_CR_WDA
value|(1<< 5)
end_define

begin_comment
comment|/* Don't touch ipp_wdog */
end_comment

begin_define
define|#
directive|define
name|WDOG_CR_SRS
value|(1<< 4)
end_define

begin_comment
comment|/* Don't touch sys_reset */
end_comment

begin_define
define|#
directive|define
name|WDOG_CR_WDT
value|(1<< 3)
end_define

begin_comment
comment|/* Assert ipp_wdog on tout */
end_comment

begin_define
define|#
directive|define
name|WDOG_CR_WDE
value|(1<< 2)
end_define

begin_comment
comment|/* WDog Enable */
end_comment

begin_define
define|#
directive|define
name|WDOG_CR_WDBG
value|(1<< 1)
end_define

begin_comment
comment|/* Suspend when DBG mode */
end_comment

begin_define
define|#
directive|define
name|WDOG_CR_WDZST
value|(1<< 0)
end_define

begin_comment
comment|/* Suspend when LP mode */
end_comment

begin_define
define|#
directive|define
name|WDOG_SR_REG
value|0x02
end_define

begin_comment
comment|/* Service Register */
end_comment

begin_define
define|#
directive|define
name|WDOG_SR_STEP1
value|0x5555
end_define

begin_define
define|#
directive|define
name|WDOG_SR_STEP2
value|0xaaaa
end_define

begin_define
define|#
directive|define
name|WDOG_RSR_REG
value|0x04
end_define

begin_comment
comment|/* Reset Status Register */
end_comment

begin_define
define|#
directive|define
name|WDOG_RSR_TOUT
value|(1<< 1)
end_define

begin_comment
comment|/* Due WDog timeout reset */
end_comment

begin_define
define|#
directive|define
name|WDOG_RSR_SFTW
value|(1<< 0)
end_define

begin_comment
comment|/* Due Soft reset */
end_comment

begin_define
define|#
directive|define
name|WDOG_ICR_REG
value|0x06
end_define

begin_comment
comment|/* Interrupt Control Register */
end_comment

begin_define
define|#
directive|define
name|WDOG_ICR_WIE
value|(1<< 15)
end_define

begin_comment
comment|/* Enable Interrupt */
end_comment

begin_define
define|#
directive|define
name|WDOG_ICR_WTIS
value|(1<< 14)
end_define

begin_comment
comment|/* Interrupt has occurred */
end_comment

begin_define
define|#
directive|define
name|WDOG_ICR_WTCT_MASK
value|0x00ff
end_define

begin_define
define|#
directive|define
name|WDOG_ICR_WTCT_SHIFT
value|0
end_define

begin_comment
comment|/* Interrupt hold time */
end_comment

begin_define
define|#
directive|define
name|WDOG_MCR_REG
value|0x08
end_define

begin_comment
comment|/* Miscellaneous Control Register */
end_comment

begin_define
define|#
directive|define
name|WDOG_MCR_PDE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|READ
parameter_list|(
name|_sc
parameter_list|,
name|_r
parameter_list|)
define|\
value|bus_space_read_2((_sc)->sc_bst, (_sc)->sc_bsh, (_r))
end_define

begin_define
define|#
directive|define
name|WRITE
parameter_list|(
name|_sc
parameter_list|,
name|_r
parameter_list|,
name|_v
parameter_list|)
define|\
value|bus_space_write_2((_sc)->sc_bst, (_sc)->sc_bsh, (_r), (_v))
end_define

end_unit

