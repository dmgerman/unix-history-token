begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Copyright (c) 1997, 1999 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Distantly from :  *	@(#)lptreg.h      1.1 (Berkeley) 12/19/90  *	Id: lptreg.h,v 1.6 1997/02/22 09:36:52 peter Exp   *	From Id: nlpt.h,v 1.3 1999/01/10 12:04:54 nsouch Exp  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * AT Parallel Port (for lineprinter)  * Interface port and bit definitions  * Written by William Jolitz 12/18/90  * Copyright (C) William Jolitz 1990  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LPT_H
end_ifndef

begin_define
define|#
directive|define
name|__LPT_H
end_define

begin_comment
comment|/* machine independent definitions, it shall only depend on the ppbus  * parallel port model */
end_comment

begin_comment
comment|/* PIN */
end_comment

begin_define
define|#
directive|define
name|LPS_NERR
value|0x08
end_define

begin_comment
comment|/* 15  printer no error */
end_comment

begin_define
define|#
directive|define
name|LPS_SEL
value|0x10
end_define

begin_comment
comment|/* 13  printer selected */
end_comment

begin_define
define|#
directive|define
name|LPS_OUT
value|0x20
end_define

begin_comment
comment|/* 12  printer out of paper */
end_comment

begin_define
define|#
directive|define
name|LPS_NACK
value|0x40
end_define

begin_comment
comment|/* 10  printer no ack of data */
end_comment

begin_define
define|#
directive|define
name|LPS_NBSY
value|0x80
end_define

begin_comment
comment|/* 11  printer busy */
end_comment

begin_define
define|#
directive|define
name|LPC_STB
value|0x01
end_define

begin_comment
comment|/*  1  strobe data to printer */
end_comment

begin_define
define|#
directive|define
name|LPC_AUTOL
value|0x02
end_define

begin_comment
comment|/* 14  automatic linefeed */
end_comment

begin_define
define|#
directive|define
name|LPC_NINIT
value|0x04
end_define

begin_comment
comment|/* 16  initialize printer */
end_comment

begin_define
define|#
directive|define
name|LPC_SEL
value|0x08
end_define

begin_comment
comment|/* 17  printer selected */
end_comment

begin_define
define|#
directive|define
name|LPC_ENA
value|0x10
end_define

begin_comment
comment|/*  -  enable IRQ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

