begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, Oleksandr Tymoshenko<gonzo@FreeBSD.org>  * Copyright (c) 2011, Aleksandr Rybalko<ray@FreeBSD.org>  * Copyright (c) 2013, Alexander A. Mityaev<sansan@adm.ua>  * Copyright (c) 2016, Stanislav Galabov<sgalabov@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MTK_SPIVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MTK_SPIVAR_H_
end_define

begin_comment
comment|/* SPI controller interface */
end_comment

begin_define
define|#
directive|define
name|MTK_SPISTAT
value|0x00
end_define

begin_comment
comment|/* SPIBUSY is alias for SPIBUSY, because SPISTAT have only BUSY bit*/
end_comment

begin_define
define|#
directive|define
name|MTK_SPIBUSY
value|MTK_SPISTAT
end_define

begin_define
define|#
directive|define
name|MTK_SPICFG
value|0x10
end_define

begin_define
define|#
directive|define
name|MSBFIRST
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|SPICLKPOL
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CAPT_ON_CLK_FALL
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|TX_ON_CLK_FALL
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|HIZSPI
value|(1<<3)
end_define

begin_comment
comment|/* Set SPI pins to Tri-state */
end_comment

begin_define
define|#
directive|define
name|SPI_CLK_SHIFT
value|0
end_define

begin_comment
comment|/* SPI clock divide control */
end_comment

begin_define
define|#
directive|define
name|SPI_CLK_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|SPI_CLK_DIV2
value|0
end_define

begin_define
define|#
directive|define
name|SPI_CLK_DIV4
value|1
end_define

begin_define
define|#
directive|define
name|SPI_CLK_DIV8
value|2
end_define

begin_define
define|#
directive|define
name|SPI_CLK_DIV16
value|3
end_define

begin_define
define|#
directive|define
name|SPI_CLK_DIV32
value|4
end_define

begin_define
define|#
directive|define
name|SPI_CLK_DIV64
value|5
end_define

begin_define
define|#
directive|define
name|SPI_CLK_DIV128
value|6
end_define

begin_define
define|#
directive|define
name|SPI_CLK_DISABLED
value|7
end_define

begin_define
define|#
directive|define
name|MTK_SPICTL
value|0x14
end_define

begin_define
define|#
directive|define
name|HIZSMOSI
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|START_WRITE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|START_READ
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CS_HIGH
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|MTK_SPIDATA
value|0x20
end_define

begin_define
define|#
directive|define
name|SPIDATA_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|MTK_SPI_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|MTK_SPI_READ
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MTK_SPIVAR_H_ */
end_comment

end_unit

