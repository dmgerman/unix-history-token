begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)timeout.h	1.1 */
end_comment

begin_comment
comment|/*  *	UNIX shell  *  *	S. R. Bourne  *	AT&T Bell Laboratories  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IH
end_ifdef

begin_define
define|#
directive|define
name|TIMEOUT
value|7000
end_define

begin_comment
comment|/* seconds elapsing before termination */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TIMEOUT
value|0
end_define

begin_comment
comment|/* seconds elapsing before termination */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TGRACE
value|60
end_define

begin_comment
comment|/* grace period before termination */
end_comment

begin_comment
comment|/* The time_warn message contains this number */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|timeout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|timed_out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|time_warn
decl_stmt|;
end_decl_stmt

end_unit

