begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1993, 1995  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)tcp_seq.h	8.2 (Berkeley) %G%  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Increment for tcp_iss each second.  * This is designed to increment at the standard 250 KB/s,  * but with a random component averaging 128 KB.  * We also increment tcp_iss by a quarter of this amount  * each time we use the value for a new connection.  * If defined, the tcp_random18() macro should produce a  * number in the range [0-0x3ffff] that is hard to predict.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tcp_tandom18
end_ifndef

begin_define
define|#
directive|define
name|tcp_random18
parameter_list|()
value|((random()>> 14)& 0x3ffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TCP_ISSINCR
value|(122*1024 + tcp_random18())
end_define

begin_decl_stmt
name|tcp_seq
name|tcp_iss
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tcp initial send seq # */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TCP_ISSINCR
value|(250*1024)
end_define

begin_comment
comment|/* increment for tcp_iss each second */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

