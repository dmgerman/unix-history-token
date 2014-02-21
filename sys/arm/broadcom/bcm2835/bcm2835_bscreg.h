begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Oleksandr Tymoshenko<gonzo@freebsd.org>  * Copyright (c) 2013 Luiz Otavio O Souza<loos@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BCM2835_BSCREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BCM2835_BSCREG_H_
end_define

begin_define
define|#
directive|define
name|BCM_BSC_CORE_CLK
value|150000000U
end_define

begin_define
define|#
directive|define
name|BCM_BSC_CTRL
value|0x00
end_define

begin_define
define|#
directive|define
name|BCM_BSC_CTRL_I2CEN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_CTRL_INTR
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_CTRL_INTT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_CTRL_INTD
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_CTRL_ST
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_CTRL_CLEAR1
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_CTRL_CLEAR0
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_CTRL_READ
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_STATUS
value|0x04
end_define

begin_define
define|#
directive|define
name|BCM_BSC_STATUS_CLKT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_STATUS_ERR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_STATUS_RXF
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_STATUS_TXE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_STATUS_RXD
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_STATUS_TXD
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_STATUS_RXR
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_STATUS_TXW
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_STATUS_DONE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_STATUS_TA
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|BCM_BSC_DLEN
value|0x08
end_define

begin_define
define|#
directive|define
name|BCM_BSC_SLAVE
value|0x0c
end_define

begin_define
define|#
directive|define
name|BCM_BSC_DATA
value|0x10
end_define

begin_define
define|#
directive|define
name|BCM_BSC_CLOCK
value|0x14
end_define

begin_define
define|#
directive|define
name|BCM_BSC_DELAY
value|0x18
end_define

begin_define
define|#
directive|define
name|BCM_BSC_CLKT
value|0x1c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BCM2835_BSCREG_H_ */
end_comment

end_unit

