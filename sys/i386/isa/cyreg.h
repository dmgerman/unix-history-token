begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Bruce Evans.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for Cyclades Cyclom-Y serial boards.  */
end_comment

begin_define
define|#
directive|define
name|CY8_SVCACKR
value|0x100
end_define

begin_define
define|#
directive|define
name|CY8_SVCACKT
value|0x200
end_define

begin_define
define|#
directive|define
name|CY8_SVCACKM
value|0x300
end_define

begin_define
define|#
directive|define
name|CY16_RESET
value|0x0a00
end_define

begin_define
define|#
directive|define
name|CY_CLEAR_INTR
value|0x0c00
end_define

begin_comment
comment|/* intr ack address */
end_comment

begin_define
define|#
directive|define
name|CY_MAX_CD1400s
value|8
end_define

begin_comment
comment|/* for Cyclom-32Y */
end_comment

begin_define
define|#
directive|define
name|CY_CLOCK
value|25000000
end_define

begin_comment
comment|/* baud rate clock */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CyDebug
end_ifdef

begin_define
define|#
directive|define
name|cd_inb
parameter_list|(
name|iobase
parameter_list|,
name|reg
parameter_list|,
name|cy_align
parameter_list|)
value|(++cd_inbs, *((iobase) + ((reg)*2<< (cy_align))))
end_define

begin_define
define|#
directive|define
name|cy_inb
parameter_list|(
name|iobase
parameter_list|,
name|reg
parameter_list|)
value|(++cy_inbs, *((iobase) + (reg)))
end_define

begin_define
define|#
directive|define
name|cd_outb
parameter_list|(
name|iobase
parameter_list|,
name|reg
parameter_list|,
name|cy_align
parameter_list|,
name|val
parameter_list|)
value|(++cd_outbs, (void)(*((iobase) + ((reg)*2<< (cy_align))) = (val)))
end_define

begin_define
define|#
directive|define
name|cy_outb
parameter_list|(
name|iobase
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|(++cy_outbs, (void)(*((iobase) + (reg)) = (val)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cd_inb
parameter_list|(
name|iobase
parameter_list|,
name|reg
parameter_list|,
name|cy_align
parameter_list|)
value|(*((iobase) + ((reg)*2<< (cy_align))))
end_define

begin_define
define|#
directive|define
name|cy_inb
parameter_list|(
name|iobase
parameter_list|,
name|reg
parameter_list|)
value|(*((iobase) + (reg)))
end_define

begin_define
define|#
directive|define
name|cd_outb
parameter_list|(
name|iobase
parameter_list|,
name|reg
parameter_list|,
name|cy_align
parameter_list|,
name|val
parameter_list|)
value|((void)(*((iobase) + ((reg)*2<< (cy_align))) = (val)))
end_define

begin_define
define|#
directive|define
name|cy_outb
parameter_list|(
name|iobase
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|((void)(*((iobase) + (reg)) = (val)))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

