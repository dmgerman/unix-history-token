begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 OMRON Corporation.  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * OMRON Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)rcvbuf.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * rcvbuf.h -- receive buffer control structure definition  *	by A.Fujita, Dec-12-1992  */
end_comment

begin_define
define|#
directive|define
name|RBUF_SIZE
value|128
end_define

begin_struct
struct|struct
name|rcvbuf
block|{
name|u_char
modifier|*
name|rb_push
decl_stmt|;
name|u_char
modifier|*
name|rb_pop
decl_stmt|;
name|u_char
name|rb_buf
index|[
name|RBUF_SIZE
operator|+
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RBUF_INIT
parameter_list|(
name|n
parameter_list|)
value|rcvbuf[n].rb_pop = rcvbuf[n].rb_push =&rcvbuf[n].rb_buf[RBUF_SIZE]
end_define

begin_define
define|#
directive|define
name|PUSH_RBUF
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|)
value|*(--rcvbuf[n].rb_push) = c ; \ 			if (rcvbuf[n].rb_push == rcvbuf[n].rb_buf) \ 				rcvbuf[n].rb_push =&rcvbuf[n].rb_buf[RBUF_SIZE]
end_define

begin_define
define|#
directive|define
name|POP_RBUF
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|)
value|c= *(--rcvbuf[n].rb_pop); \ 			if (rcvbuf[n].rb_pop == rcvbuf[n].rb_buf) \ 				rcvbuf[n].rb_pop =&rcvbuf[n].rb_buf[RBUF_SIZE]
end_define

begin_define
define|#
directive|define
name|RBUF_EMPTY
parameter_list|(
name|n
parameter_list|)
value|(rcvbuf[n].rb_push == rcvbuf[n].rb_pop ? 1: 0)
end_define

end_unit

