begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tp_seq.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETISO_TP_SEQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETISO_TP_SEQ_H_
end_define

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*  * ARGO TP  *  * $FreeBSD$  * $Source: /pub/FreeBSD/FreeBSD-CVS/src/sys/netiso/Attic/tp_seq.h,v $  *  * These macros perform sequence number arithmetic modulo (2**7 or 2**31).  * The relevant fields in the tpcb are:  *  	tp_seqmask : the mask of bits that define the sequence space.  *  	tp_seqbit  : 1 + tp_seqmask  *  	tp_seqhalf : tp_seqbit / 2 or half the sequence space (rounded up)  * Not exactly fast, but at least it's maintainable.  */
end_comment

begin_define
define|#
directive|define
name|SEQ
parameter_list|(
name|tpcb
parameter_list|,
name|x
parameter_list|)
define|\
value|((x)& (tpcb)->tp_seqmask)
end_define

begin_define
define|#
directive|define
name|SEQ_GT
parameter_list|(
name|tpcb
parameter_list|,
name|seq
parameter_list|,
name|operand
parameter_list|)
define|\
value|( ((int)((seq)-(operand))> 0)\ ? ((int)((seq)-(operand))< (int)(tpcb)->tp_seqhalf)\ : !(-((int)(seq)-(operand))< (int)(tpcb)->tp_seqhalf))
end_define

begin_define
define|#
directive|define
name|SEQ_GEQ
parameter_list|(
name|tpcb
parameter_list|,
name|seq
parameter_list|,
name|operand
parameter_list|)
define|\
value|( ((int)((seq)-(operand))>= 0)\ ? ((int)((seq)-(operand))< (int)(tpcb)->tp_seqhalf)\ : !((-((int)(seq)-(operand)))< (int)(tpcb)->tp_seqhalf))
end_define

begin_define
define|#
directive|define
name|SEQ_LEQ
parameter_list|(
name|tpcb
parameter_list|,
name|seq
parameter_list|,
name|operand
parameter_list|)
define|\
value|( ((int)((seq)-(operand))<= 0)\ ? ((-(int)((seq)-(operand)))< (int)(tpcb)->tp_seqhalf)\ : !(((int)(seq)-(operand))< (int)(tpcb)->tp_seqhalf))
end_define

begin_define
define|#
directive|define
name|SEQ_LT
parameter_list|(
name|tpcb
parameter_list|,
name|seq
parameter_list|,
name|operand
parameter_list|)
define|\
value|( ((int)((seq)-(operand))< 0)\ ? ((-(int)((seq)-(operand)))< (int)(tpcb)->tp_seqhalf)\ : !(((int)(seq)-(operand))< (int)(tpcb)->tp_seqhalf))
end_define

begin_define
define|#
directive|define
name|SEQ_MIN
parameter_list|(
name|tpcb
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|( SEQ_GT(tpcb, a, b) ? b : a)
end_define

begin_define
define|#
directive|define
name|SEQ_MAX
parameter_list|(
name|tpcb
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|)
value|( SEQ_GT(tpcb, a, b) ? a : b)
end_define

begin_define
define|#
directive|define
name|SEQ_INC
parameter_list|(
name|tpcb
parameter_list|,
name|Seq
parameter_list|)
value|((++Seq), ((Seq)&= (tpcb)->tp_seqmask))
end_define

begin_define
define|#
directive|define
name|SEQ_DEC
parameter_list|(
name|tpcb
parameter_list|,
name|Seq
parameter_list|)
define|\
value|((Seq) = (((Seq)+(unsigned)((int)(tpcb)->tp_seqbit - 1))&(tpcb)->tp_seqmask))
end_define

begin_comment
comment|/* (amt) had better be less than the seq bit ! */
end_comment

begin_define
define|#
directive|define
name|SEQ_SUB
parameter_list|(
name|tpcb
parameter_list|,
name|Seq
parameter_list|,
name|amt
parameter_list|)
define|\
value|(((Seq) + (unsigned)((int)(tpcb)->tp_seqbit - amt))& (tpcb)->tp_seqmask)
end_define

begin_define
define|#
directive|define
name|SEQ_ADD
parameter_list|(
name|tpcb
parameter_list|,
name|Seq
parameter_list|,
name|amt
parameter_list|)
value|(((Seq) + (unsigned)amt)& (tpcb)->tp_seqmask)
end_define

begin_define
define|#
directive|define
name|IN_RWINDOW
parameter_list|(
name|tpcb
parameter_list|,
name|seq
parameter_list|,
name|lwe
parameter_list|,
name|uwe
parameter_list|)
define|\
value|( SEQ_GEQ(tpcb, seq, lwe)&& SEQ_LT(tpcb, seq, uwe) )
end_define

begin_define
define|#
directive|define
name|IN_SWINDOW
parameter_list|(
name|tpcb
parameter_list|,
name|seq
parameter_list|,
name|lwe
parameter_list|,
name|uwe
parameter_list|)
define|\
value|( SEQ_GT(tpcb, seq, lwe)&& SEQ_LEQ(tpcb, seq, uwe) )
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

