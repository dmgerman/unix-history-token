begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego and Lance  * Visser of Convex Computer Corporation.  *  * %sccs.include.redist.c%  *  *	@(#)extern.h	8.3 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|void
name|block
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
name|block_close
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
name|dd_out
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|def
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
name|def_close
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
name|jcl
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pos_in
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
name|pos_out
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
name|summary
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
name|summaryx
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|terminate
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unblock
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
name|unblock_close
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|IO
name|in
decl_stmt|,
name|out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|STAT
name|st
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|cfunc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|u_long
name|cpy_cnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|cbsz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|ddflags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|files_cnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
modifier|*
name|ctab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|a2e_32V
index|[]
decl_stmt|,
name|a2e_POSIX
index|[]
decl_stmt|,
name|a2ibm_32V
index|[]
decl_stmt|,
name|a2ibm_POSIX
index|[]
decl_stmt|,
name|e2a_32V
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_char
name|e2a_POSIX
index|[]
decl_stmt|,
name|l2u
index|[]
decl_stmt|,
name|u2l
index|[]
decl_stmt|;
end_decl_stmt

end_unit

