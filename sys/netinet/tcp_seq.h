begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993, 1995  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tcp_seq.h	8.3 (Berkeley) 6/21/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_TCP_SEQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_TCP_SEQ_H_
end_define

begin_comment
comment|/*  * TCP sequence numbers are 32 bit integers operated  * on with modular arithmetic.  These macros can be  * used to compare such integers.  */
end_comment

begin_define
define|#
directive|define
name|SEQ_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))< 0)
end_define

begin_define
define|#
directive|define
name|SEQ_LEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))<= 0)
end_define

begin_define
define|#
directive|define
name|SEQ_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))> 0)
end_define

begin_define
define|#
directive|define
name|SEQ_GEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))>= 0)
end_define

begin_comment
comment|/* for modulo comparisons of timestamps */
end_comment

begin_define
define|#
directive|define
name|TSTMP_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))< 0)
end_define

begin_define
define|#
directive|define
name|TSTMP_GEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))>= 0)
end_define

begin_comment
comment|/*  * TCP connection counts are 32 bit integers operated  * on with modular arithmetic.  These macros can be  * used to compare such integers.  */
end_comment

begin_define
define|#
directive|define
name|CC_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))< 0)
end_define

begin_define
define|#
directive|define
name|CC_LEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))<= 0)
end_define

begin_define
define|#
directive|define
name|CC_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))> 0)
end_define

begin_define
define|#
directive|define
name|CC_GEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))>= 0)
end_define

begin_comment
comment|/* Macro to increment a CC: skip 0 which has a special meaning */
end_comment

begin_define
define|#
directive|define
name|CC_INC
parameter_list|(
name|c
parameter_list|)
value|(++(c) == 0 ? ++(c) : (c))
end_define

begin_comment
comment|/*  * Macros to initialize tcp sequence numbers for  * send and receive from initial send and receive  * sequence numbers.  */
end_comment

begin_define
define|#
directive|define
name|tcp_rcvseqinit
parameter_list|(
name|tp
parameter_list|)
define|\
value|(tp)->rcv_adv = (tp)->rcv_nxt = (tp)->irs + 1
end_define

begin_define
define|#
directive|define
name|tcp_sendseqinit
parameter_list|(
name|tp
parameter_list|)
define|\
value|(tp)->snd_una = (tp)->snd_nxt = (tp)->snd_max = (tp)->snd_up = \ 	    (tp)->iss
end_define

begin_define
define|#
directive|define
name|TCP_PAWS_IDLE
value|(24 * 24 * 60 * 60 * hz)
end_define

begin_comment
comment|/* timestamp wrap-around time */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|tcp_cc
name|tcp_ccgen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global connection count */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETINET_TCP_SEQ_H_ */
end_comment

end_unit

