begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Nicolas Souchu  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Distantly from :  *	@(#)lptreg.h      1.1 (Berkeley) 12/19/90  *	Id: lptreg.h,v 1.6 1997/02/22 09:36:52 peter Exp   *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLPT_H
end_ifndef

begin_define
define|#
directive|define
name|__NLPT_H
end_define

begin_define
define|#
directive|define
name|LPS_NERR
value|0x08
end_define

begin_comment
comment|/* printer no error */
end_comment

begin_define
define|#
directive|define
name|LPS_SEL
value|0x10
end_define

begin_comment
comment|/* printer selected */
end_comment

begin_define
define|#
directive|define
name|LPS_OUT
value|0x20
end_define

begin_comment
comment|/* printer out of paper */
end_comment

begin_define
define|#
directive|define
name|LPS_NACK
value|0x40
end_define

begin_comment
comment|/* printer no ack of data */
end_comment

begin_define
define|#
directive|define
name|LPS_NBSY
value|0x80
end_define

begin_comment
comment|/* printer no ack of data */
end_comment

begin_define
define|#
directive|define
name|LPC_STB
value|0x01
end_define

begin_comment
comment|/* strobe data to printer */
end_comment

begin_define
define|#
directive|define
name|LPC_AUTOL
value|0x02
end_define

begin_comment
comment|/* automatic linefeed */
end_comment

begin_define
define|#
directive|define
name|LPC_NINIT
value|0x04
end_define

begin_comment
comment|/* initialize printer */
end_comment

begin_define
define|#
directive|define
name|LPC_SEL
value|0x08
end_define

begin_comment
comment|/* printer selected */
end_comment

begin_define
define|#
directive|define
name|LPC_ENA
value|0x10
end_define

begin_comment
comment|/* enable IRQ */
end_comment

begin_struct
struct|struct
name|lpt_data
block|{
name|unsigned
name|short
name|lpt_unit
decl_stmt|;
name|struct
name|ppb_device
name|lpt_dev
decl_stmt|;
name|short
name|sc_state
decl_stmt|;
comment|/* default case: negative prime, negative ack, handshake strobe, 	   prime once */
name|u_char
name|sc_control
decl_stmt|;
name|char
name|sc_flags
decl_stmt|;
define|#
directive|define
name|LP_POS_INIT
value|0x04
comment|/* if we are a postive init signal */
define|#
directive|define
name|LP_POS_ACK
value|0x08
comment|/* if we are a positive going ack */
define|#
directive|define
name|LP_NO_PRIME
value|0x10
comment|/* don't prime the printer at all */
define|#
directive|define
name|LP_PRIMEOPEN
value|0x20
comment|/* prime on every open */
define|#
directive|define
name|LP_AUTOLF
value|0x40
comment|/* tell printer to do an automatic lf */
define|#
directive|define
name|LP_BYPASS
value|0x80
comment|/* bypass  printer ready checks */
name|struct
name|buf
modifier|*
name|sc_inbuf
decl_stmt|;
name|struct
name|buf
modifier|*
name|sc_statbuf
decl_stmt|;
name|short
name|sc_xfercnt
decl_stmt|;
name|char
name|sc_primed
decl_stmt|;
name|char
modifier|*
name|sc_cp
decl_stmt|;
name|u_short
name|sc_irq
decl_stmt|;
comment|/* IRQ status of port */
define|#
directive|define
name|LP_HAS_IRQ
value|0x01
comment|/* we have an irq available */
define|#
directive|define
name|LP_USE_IRQ
value|0x02
comment|/* we are using our irq */
define|#
directive|define
name|LP_ENABLE_IRQ
value|0x04
comment|/* enable IRQ on open */
define|#
directive|define
name|LP_ENABLE_EXT
value|0x10
comment|/* we shall use advanced mode when possible */
name|u_char
name|sc_backoff
decl_stmt|;
comment|/* time to call lptout() again */
ifdef|#
directive|ifdef
name|DEVFS
name|void
modifier|*
name|devfs_token
decl_stmt|;
name|void
modifier|*
name|devfs_token_ctl
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

