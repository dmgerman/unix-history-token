begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*   * ARGO TP  *  * $Header: tp_seq.h,v 5.1 88/10/12 12:20:59 root Exp $  * $Source: /usr/argo/sys/netiso/RCS/tp_seq.h,v $  *	@(#)tp_seq.h	7.3 (Berkeley) %G% *  *  * These macros perform sequence number arithmetic modulo (2**7 or 2**31).  * The relevant fields in the tpcb are:  *  	tp_seqmask : the mask of bits that define the sequence space.  *  	tp_seqbit  : 1 + tp_seqmask  *  	tp_seqhalf : tp_seqbit / 2 or half the sequence space (rounded up)  * Not exactly fast, but at least it's maintainable.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TP_SEQ__
end_ifndef

begin_define
define|#
directive|define
name|__TP_SEQ__
end_define

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
endif|__TP_SEQ__
end_endif

end_unit

