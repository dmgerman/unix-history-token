begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)extern.h	8.3 (Berkeley) %G%  */
end_comment

begin_define
define|#
directive|define
name|OK_EXIT
value|0
end_define

begin_define
define|#
directive|define
name|DIFF_EXIT
value|1
end_define

begin_define
define|#
directive|define
name|ERR_EXIT
value|2
end_define

begin_comment
comment|/* error exit code */
end_comment

begin_decl_stmt
name|void
name|c_regular
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|off_t
operator|,
name|off_t
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|off_t
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|c_special
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|off_t
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|diffmsg
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|off_t
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|eofmsg
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lflag
decl_stmt|,
name|sflag
decl_stmt|;
end_decl_stmt

end_unit

