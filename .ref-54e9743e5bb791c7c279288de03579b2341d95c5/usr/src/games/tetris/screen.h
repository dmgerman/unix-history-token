begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek and Darren F. Provine.  *  * %sccs.include.redist.c%  *  *	@(#)screen.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Capabilities from TERMCAP (used in the score code).  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SEstr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end standout mode */
end_comment

begin_decl_stmt
name|char
modifier|*
name|SOstr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* begin standout mode */
end_comment

begin_comment
comment|/*  * putpad() is for padded strings with count=1.  */
end_comment

begin_define
define|#
directive|define
name|putpad
parameter_list|(
name|s
parameter_list|)
value|tputs(s, 1, put)
end_define

begin_decl_stmt
name|int
name|put
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* just calls putchar; for tputs */
end_comment

begin_decl_stmt
name|void
name|scr_clear
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scr_end
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scr_init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scr_msg
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scr_set
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|scr_update
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

