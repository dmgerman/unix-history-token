begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)tcp_seq.h	7.3 (Berkeley) 6/29/88  */
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

begin_define
define|#
directive|define
name|TCP_ISSINCR
value|(125*1024)
end_define

begin_comment
comment|/* increment for tcp_iss each second */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|tcp_seq
name|tcp_iss
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tcp initial send seq # */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

