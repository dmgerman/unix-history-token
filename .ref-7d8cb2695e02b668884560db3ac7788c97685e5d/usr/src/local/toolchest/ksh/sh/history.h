begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)history.h	1.1 */
end_comment

begin_comment
comment|/*  *	UNIX shell  *	Header File for history mechanism  *	written by David Korn  *  */
end_comment

begin_comment
comment|/* structure for fix command files */
end_comment

begin_define
define|#
directive|define
name|HIS_DFLT
value|128
end_define

begin_comment
comment|/* default size of history list */
end_comment

begin_define
define|#
directive|define
name|HISMAX
value|(sizeof(int)*BUFSIZ)
end_define

begin_define
define|#
directive|define
name|HISBIG
value|(0100000-1024)
end_define

begin_comment
comment|/* 1K less than maximum short */
end_comment

begin_define
define|#
directive|define
name|HISLINE
value|16
end_define

begin_comment
comment|/* estimate of average sized history line */
end_comment

begin_define
define|#
directive|define
name|MAXLINE
value|258
end_define

begin_comment
comment|/* longest history line permitted */
end_comment

begin_define
define|#
directive|define
name|H_UNDO
value|0201
end_define

begin_comment
comment|/* invalidate previous command */
end_comment

begin_define
define|#
directive|define
name|H_CMDNO
value|0202
end_define

begin_comment
comment|/* next 3 bytes give command number */
end_comment

begin_define
define|#
directive|define
name|H_VERSION
value|1
end_define

begin_comment
comment|/* history file format version no. */
end_comment

begin_struct
struct|struct
name|fixcmd
block|{
name|FILE
modifier|*
name|fixfd
decl_stmt|;
comment|/* file descriptor for history file */
name|int
name|fixind
decl_stmt|;
comment|/* current command number index */
name|long
name|fixcnt
decl_stmt|;
comment|/* offset into history file */
name|int
name|fixmax
decl_stmt|;
comment|/* number of accessible history lines */
name|int
name|fixline
decl_stmt|;
comment|/* line number within command */
name|long
name|fixcmds
index|[
literal|1
index|]
decl_stmt|;
comment|/* byte offset for recent commands */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|his_command
decl_stmt|;
name|short
name|his_line
decl_stmt|;
block|}
name|histloc
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|fixcmd
modifier|*
name|fc_fix
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|hist_close
parameter_list|()
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|KSHELL
end_ifndef

begin_define
define|#
directive|define
name|FCIO
value|19
end_define

begin_typedef
typedef|typedef
name|char
name|MSG
index|[]
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getenv
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|valup
parameter_list|(
name|s
parameter_list|)
value|getenv("s")
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_define
define|#
directive|define
name|strrchr
value|rindex
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_define
define|#
directive|define
name|NIL
value|((char*)0)
end_define

begin_define
define|#
directive|define
name|setalt
value|e_setalt
end_define

begin_define
define|#
directive|define
name|setraw
value|e_setraw
end_define

begin_define
define|#
directive|define
name|setcooked
value|e_setcooked
end_define

begin_define
define|#
directive|define
name|failed
value|e_failed
end_define

begin_define
define|#
directive|define
name|hread
value|emacs_read
end_define

begin_define
define|#
directive|define
name|vread
value|vi_read
end_define

begin_define
define|#
directive|define
name|movstr
value|e_movstr
end_define

begin_define
define|#
directive|define
name|ungetchar
value|e_ungetchar
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KSHELL */
end_comment

begin_comment
comment|/* the following are readonly */
end_comment

begin_decl_stmt
specifier|extern
name|MSG
name|histfname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|nohistory
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|badcooked
decl_stmt|;
end_decl_stmt

end_unit

