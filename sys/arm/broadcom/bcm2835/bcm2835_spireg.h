begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Oleksandr Tymoshenko<gonzo@freebsd.org>  * Copyright (c) 2013 Luiz Otavio O Souza<loos@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BCM2835_SPIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BCM2835_SPIREG_H_
end_define

begin_define
define|#
directive|define
name|SPI_CORE_CLK
value|250000000U
end_define

begin_define
define|#
directive|define
name|SPI_CS
value|0x00
end_define

begin_define
define|#
directive|define
name|SPI_CS_LEN_LONG
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|SPI_CS_DMA_LEN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|SPI_CS_CSPOL2
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|SPI_CS_CSPOL1
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|SPI_CS_CSPOL0
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|SPI_CS_RXF
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|SPI_CS_RXR
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|SPI_CS_TXD
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|SPI_CS_RXD
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|SPI_CS_DONE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SPI_CS_LEN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|SPI_CS_REN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|SPI_CS_ADCS
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|SPI_CS_INTR
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SPI_CS_INTD
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SPI_CS_DMAEN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SPI_CS_TA
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SPI_CS_CSPOL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SPI_CS_CLEAR_RXFIFO
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SPI_CS_CLEAR_TXFIFO
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SPI_CS_CPOL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SPI_CS_CPHA
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SPI_CS_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|SPI_FIFO
value|0x04
end_define

begin_define
define|#
directive|define
name|SPI_CLK
value|0x08
end_define

begin_define
define|#
directive|define
name|SPI_CLK_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|SPI_DLEN
value|0x0c
end_define

begin_define
define|#
directive|define
name|SPI_DLEN_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|SPI_LTOH
value|0x10
end_define

begin_define
define|#
directive|define
name|SPI_LTOH_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|SPI_DC
value|0x14
end_define

begin_define
define|#
directive|define
name|SPI_DC_RPANIC_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SPI_DC_RPANIC_MASK
value|(0xff<< SPI_DC_RPANIC_SHIFT)
end_define

begin_define
define|#
directive|define
name|SPI_DC_RDREQ_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SPI_DC_RDREQ_MASK
value|(0xff<< SPI_DC_RDREQ_SHIFT)
end_define

begin_define
define|#
directive|define
name|SPI_DC_TPANIC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SPI_DC_TPANIC_MASK
value|(0xff<< SPI_DC_TPANIC_SHIFT)
end_define

begin_define
define|#
directive|define
name|SPI_DC_TDREQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SPI_DC_TDREQ_MASK
value|0xff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BCM2835_SPIREG_H_ */
end_comment

end_unit

