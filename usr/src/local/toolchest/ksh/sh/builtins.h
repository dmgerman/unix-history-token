begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)builtins.h	1.1 */
end_comment

begin_comment
comment|/* table of shell builtins */
end_comment

begin_comment
comment|/* currently can not be more than SYSMAX */
end_comment

begin_define
define|#
directive|define
name|SYSMAX
value|255
end_define

begin_comment
comment|/* The following commands up to SYSSPECIAL treat parameter lists specially */
end_comment

begin_comment
comment|/* They do not evaluate in-line with command substitution */
end_comment

begin_comment
comment|/* Also, commands below SYSNULL cause a script to abort on errors */
end_comment

begin_define
define|#
directive|define
name|SYSEXEC
value|1
end_define

begin_define
define|#
directive|define
name|SYSLOGIN
value|2
end_define

begin_define
define|#
directive|define
name|SYSFC
value|3
end_define

begin_define
define|#
directive|define
name|SYSEVAL
value|4
end_define

begin_define
define|#
directive|define
name|SYSDOT
value|5
end_define

begin_define
define|#
directive|define
name|SYSRETURN
value|6
end_define

begin_define
define|#
directive|define
name|SYSRDONLY
value|7
end_define

begin_define
define|#
directive|define
name|SYSXPORT
value|8
end_define

begin_define
define|#
directive|define
name|SYSTYPESET
value|9
end_define

begin_define
define|#
directive|define
name|SYSNULL
value|10
end_define

begin_define
define|#
directive|define
name|SYSSHFT
value|11
end_define

begin_define
define|#
directive|define
name|SYSCD
value|12
end_define

begin_define
define|#
directive|define
name|SYSSPECIAL
value|12
end_define

begin_comment
comment|/* end of special commands */
end_comment

begin_define
define|#
directive|define
name|SYSEXIT
value|13
end_define

begin_define
define|#
directive|define
name|SYSULIMIT
value|14
end_define

begin_define
define|#
directive|define
name|SYSCONT
value|15
end_define

begin_define
define|#
directive|define
name|SYSBREAK
value|16
end_define

begin_define
define|#
directive|define
name|SYSTRAP
value|17
end_define

begin_define
define|#
directive|define
name|SYSTIMES
value|18
end_define

begin_define
define|#
directive|define
name|SYSUMASK
value|19
end_define

begin_define
define|#
directive|define
name|SYSWAIT
value|20
end_define

begin_define
define|#
directive|define
name|SYSREAD
value|21
end_define

begin_define
define|#
directive|define
name|SYSSET
value|22
end_define

begin_define
define|#
directive|define
name|SYSUNSET
value|23
end_define

begin_define
define|#
directive|define
name|SYSLET
value|24
end_define

begin_define
define|#
directive|define
name|SYSALIAS
value|25
end_define

begin_define
define|#
directive|define
name|SYSUNALIAS
value|26
end_define

begin_define
define|#
directive|define
name|SYSWHENCE
value|27
end_define

begin_define
define|#
directive|define
name|SYSTEST
value|28
end_define

begin_define
define|#
directive|define
name|SYSPRINT
value|29
end_define

begin_define
define|#
directive|define
name|SYSECHO
value|30
end_define

begin_define
define|#
directive|define
name|SYSPWD
value|31
end_define

begin_define
define|#
directive|define
name|SYSFG
value|32
end_define

begin_define
define|#
directive|define
name|SYSBG
value|33
end_define

begin_define
define|#
directive|define
name|SYSJOBS
value|34
end_define

begin_define
define|#
directive|define
name|SYSKILL
value|35
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|apollo
end_ifdef

begin_define
define|#
directive|define
name|SYSINLIB
value|36
end_define

begin_define
define|#
directive|define
name|SYSINPROCESS
value|37
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* apollo */
end_comment

begin_comment
comment|/* structure for builtin shell variable names and aliases */
end_comment

begin_struct
struct|struct
name|name_value
block|{
ifdef|#
directive|ifdef
name|apollo
comment|/* you can't readonly pointers */
name|char
name|nv_name
index|[
literal|12
index|]
decl_stmt|;
name|char
name|nv_value
index|[
literal|20
index|]
decl_stmt|;
else|#
directive|else
name|char
modifier|*
name|nv_name
decl_stmt|;
name|char
modifier|*
name|nv_value
decl_stmt|;
endif|#
directive|endif
comment|/* apollo */
block|}
struct|;
end_struct

begin_comment
comment|/* The following defines are coordinated with data in msg.c */
end_comment

begin_define
define|#
directive|define
name|PATHNOD
value|(bltin_nodes)
end_define

begin_define
define|#
directive|define
name|PS1NOD
value|(bltin_nodes+1)
end_define

begin_define
define|#
directive|define
name|PS2NOD
value|(bltin_nodes+2)
end_define

begin_define
define|#
directive|define
name|IFSNOD
value|(bltin_nodes+3)
end_define

begin_define
define|#
directive|define
name|PWDNOD
value|(bltin_nodes+4)
end_define

begin_define
define|#
directive|define
name|HOME
value|(bltin_nodes+5)
end_define

begin_define
define|#
directive|define
name|MAILNOD
value|(bltin_nodes+6)
end_define

begin_define
define|#
directive|define
name|REPLYNOD
value|(bltin_nodes+7)
end_define

begin_define
define|#
directive|define
name|SHELLNOD
value|(bltin_nodes+8)
end_define

begin_define
define|#
directive|define
name|EDITNOD
value|(bltin_nodes+9)
end_define

begin_define
define|#
directive|define
name|MCHKNOD
value|(bltin_nodes+10)
end_define

begin_define
define|#
directive|define
name|RANDNOD
value|(bltin_nodes+11)
end_define

begin_define
define|#
directive|define
name|ENVNOD
value|(bltin_nodes+12)
end_define

begin_define
define|#
directive|define
name|HISTFILE
value|(bltin_nodes+13)
end_define

begin_define
define|#
directive|define
name|HISTSIZE
value|(bltin_nodes+14)
end_define

begin_define
define|#
directive|define
name|FCEDNOD
value|(bltin_nodes+15)
end_define

begin_define
define|#
directive|define
name|CDPNOD
value|(bltin_nodes+16)
end_define

begin_define
define|#
directive|define
name|MAILPNOD
value|(bltin_nodes+17)
end_define

begin_define
define|#
directive|define
name|PS3NOD
value|(bltin_nodes+18)
end_define

begin_define
define|#
directive|define
name|OLDPWDNOD
value|(bltin_nodes+19)
end_define

begin_define
define|#
directive|define
name|VISINOD
value|(bltin_nodes+20)
end_define

begin_define
define|#
directive|define
name|COLUMNS
value|(bltin_nodes+21)
end_define

begin_define
define|#
directive|define
name|LINES
value|(bltin_nodes+22)
end_define

begin_define
define|#
directive|define
name|PPIDNOD
value|(bltin_nodes+23)
end_define

begin_define
define|#
directive|define
name|L_ARGNOD
value|(bltin_nodes+24)
end_define

begin_define
define|#
directive|define
name|TMOUTNOD
value|(bltin_nodes+25)
end_define

begin_define
define|#
directive|define
name|SECONDS
value|(bltin_nodes+26)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ACCT
end_ifdef

begin_define
define|#
directive|define
name|ACCTNOD
value|(bltin_nodes+27)
end_define

begin_define
define|#
directive|define
name|NNODES
value|28
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NNODES
value|27
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACCT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_define
define|#
directive|define
name|NALIAS
value|29
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NALIAS
value|28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|Namnod
modifier|*
name|bltin_nodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|name_value
name|node_names
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|name_value
name|alias_names
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|limit_names
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD */
end_comment

end_unit

