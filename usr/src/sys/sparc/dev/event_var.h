begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)event_var.h	7.3 (Berkeley) %G%  *  * from: $Header: event_var.h,v 1.5 92/11/26 01:11:51 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Internal `Firm_event' interface for the keyboard and mouse drivers.  * The drivers are expected not to place events in the queue above spltty(),  * i.e., are expected to run off serial ports.  */
end_comment

begin_comment
comment|/* EV_QSIZE should be a power of two so that `%' is fast */
end_comment

begin_define
define|#
directive|define
name|EV_QSIZE
value|256
end_define

begin_comment
comment|/* may need tuning; this uses 2k */
end_comment

begin_struct
struct|struct
name|evvar
block|{
name|u_int
name|ev_get
decl_stmt|;
comment|/* get (read) index (modified synchronously) */
specifier|volatile
name|u_int
name|ev_put
decl_stmt|;
comment|/* put (write) index (modified by interrupt) */
name|struct
name|selinfo
name|ev_sel
decl_stmt|;
comment|/* process selecting */
name|struct
name|proc
modifier|*
name|ev_io
decl_stmt|;
comment|/* process that opened queue (can get SIGIO) */
name|char
name|ev_wanted
decl_stmt|;
comment|/* wake up on input ready */
name|char
name|ev_async
decl_stmt|;
comment|/* send SIGIO on input ready */
name|struct
name|firm_event
modifier|*
name|ev_q
decl_stmt|;
comment|/* circular buffer (queue) of events */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|splev
parameter_list|()
value|spltty()
end_define

begin_define
define|#
directive|define
name|EV_WAKEUP
parameter_list|(
name|ev
parameter_list|)
value|{ \ 	selwakeup(&(ev)->ev_sel); \ 	if ((ev)->ev_wanted) { \ 		(ev)->ev_wanted = 0; \ 		wakeup((caddr_t)(ev)); \ 	} \ 	if ((ev)->ev_async) \ 		psignal((ev)->ev_io, SIGIO); \ }
end_define

begin_decl_stmt
name|void
name|ev_init
name|__P
argument_list|(
operator|(
expr|struct
name|evvar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ev_fini
name|__P
argument_list|(
operator|(
expr|struct
name|evvar
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ev_read
name|__P
argument_list|(
operator|(
expr|struct
name|evvar
operator|*
operator|,
expr|struct
name|uio
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ev_select
name|__P
argument_list|(
operator|(
expr|struct
name|evvar
operator|*
operator|,
name|int
operator|,
expr|struct
name|proc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * PEVENT is set just above PSOCK, which is just above TTIPRI, on the  * theory that mouse and keyboard `user' input should be quick.  */
end_comment

begin_define
define|#
directive|define
name|PEVENT
value|23
end_define

end_unit

