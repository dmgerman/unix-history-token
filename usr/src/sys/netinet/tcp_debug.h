begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)tcp_debug.h	7.2 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|tcp_debug
block|{
name|n_time
name|td_time
decl_stmt|;
name|short
name|td_act
decl_stmt|;
name|short
name|td_ostate
decl_stmt|;
name|caddr_t
name|td_tcb
decl_stmt|;
name|struct
name|tcpiphdr
name|td_ti
decl_stmt|;
name|short
name|td_req
decl_stmt|;
name|struct
name|tcpcb
name|td_cb
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TA_INPUT
value|0
end_define

begin_define
define|#
directive|define
name|TA_OUTPUT
value|1
end_define

begin_define
define|#
directive|define
name|TA_USER
value|2
end_define

begin_define
define|#
directive|define
name|TA_RESPOND
value|3
end_define

begin_define
define|#
directive|define
name|TA_DROP
value|4
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TANAMES
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|tanames
index|[]
init|=
block|{
literal|"input"
block|,
literal|"output"
block|,
literal|"user"
block|,
literal|"respond"
block|,
literal|"drop"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TCP_NDEBUG
value|100
end_define

begin_decl_stmt
name|struct
name|tcp_debug
name|tcp_debug
index|[
name|TCP_NDEBUG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tcp_debx
decl_stmt|;
end_decl_stmt

end_unit

