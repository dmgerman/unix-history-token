begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Rubicon Communications, LLC (Netgate)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TI_SPIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_TI_SPIREG_H_
end_define

begin_define
define|#
directive|define
name|TI_SPI_GCLK
value|48000000U
end_define

begin_define
define|#
directive|define
name|TI_SPI_FIFOSZ
value|32
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION
value|0x0
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION_SCHEME_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION_SCHEME_MSK
value|0x3
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION_FUNC_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION_FUNC_MSK
value|0xfff
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION_RTL_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION_RTL_MSK
value|0x1f
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION_MAJOR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION_MAJOR_MSK
value|0x7
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION_CUSTOM_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION_CUSTOM_MSK
value|0x3
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION_MINOR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|MCSPI_REVISION_MINOR_MSK
value|0x3f
end_define

begin_define
define|#
directive|define
name|MCSPI_SYSCONFIG
value|0x110
end_define

begin_define
define|#
directive|define
name|MCSPI_SYSCONFIG_SOFTRESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MCSPI_SYSSTATUS
value|0x114
end_define

begin_define
define|#
directive|define
name|MCSPI_SYSSTATUS_RESETDONE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MCSPI_MODULCTRL
value|0x128
end_define

begin_define
define|#
directive|define
name|MCSPI_MODULCTRL_SLAVE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MCSPI_MODULCTRL_SINGLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MCSPI_IRQSTATUS
value|0x118
end_define

begin_define
define|#
directive|define
name|MCSPI_IRQENABLE
value|0x11c
end_define

begin_define
define|#
directive|define
name|MCSPI_IRQ_EOW
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|MCSPI_IRQ_RX0_OVERFLOW
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MCSPI_IRQ_RX0_FULL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MCSPI_IRQ_TX0_UNDERFLOW
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MCSPI_IRQ_TX0_EMPTY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_CH
parameter_list|(
name|_c
parameter_list|)
value|(0x12c + 0x14 * (_c))
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_CLKG
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_FFER
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_FFEW
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_SBPOL
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_SBE
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_FORCE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_TURBO
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_IS
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_DPE1
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_DPE0
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_DMAR
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_DMAW
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_WL_MSK
value|0x1f
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_WL_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_WL8BITS
value|(7<< MCSPI_CONF_WL_SHIFT)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_EPOL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_CLK_MSK
value|0xf
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_CLK_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_POL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MCSPI_CONF_PHA
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MCSPI_STAT_CH
parameter_list|(
name|_c
parameter_list|)
value|(0x130 + 0x14 * (_c))
end_define

begin_define
define|#
directive|define
name|MCSPI_STAT_TXFFF
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MCSPI_STAT_TXS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MCSPI_STAT_RXS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MCSPI_CTRL_CH
parameter_list|(
name|_c
parameter_list|)
value|(0x134 + 0x14 * (_c))
end_define

begin_define
define|#
directive|define
name|MCSPI_EXTCLK_MSK
value|0xfff
end_define

begin_define
define|#
directive|define
name|MCSPI_CTRL_EXTCLK_MSK
value|0xff
end_define

begin_define
define|#
directive|define
name|MCSPI_CTRL_EXTCLK_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MCSPI_CTRL_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MCSPI_TX_CH
parameter_list|(
name|_c
parameter_list|)
value|(0x138 + 0x14 * (_c))
end_define

begin_define
define|#
directive|define
name|MCSPI_RX_CH
parameter_list|(
name|_c
parameter_list|)
value|(0x13c + 0x14 * (_c))
end_define

begin_define
define|#
directive|define
name|MCSPI_XFERLEVEL
value|0x17c
end_define

begin_define
define|#
directive|define
name|MCSPI_XFERLEVEL_AFL
parameter_list|(
name|_a
parameter_list|)
value|(((_a)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|MCSPI_XFERLEVEL_AEL
parameter_list|(
name|_a
parameter_list|)
value|(((_a)>> 0)& 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _TI_SPIREG_H_ */
end_comment

end_unit

