begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *      Copyright (c) 1984, 1985, 1986 AT&T  *      All Rights Reserved   *      THIS IS UNPUBLISHED PROPRIETARY SOURCE   *      CODE OF AT&T.  *      The copyright notice above does not   *      evidence any actual or intended  *      publication of such source code.   */
end_comment

begin_comment
comment|/* @(#)sym.h	1.1 */
end_comment

begin_comment
comment|/*  *	UNIX shell  *	S. R. Bourne  *	Rewritten by David Korn  */
end_comment

begin_comment
comment|/* symbols for parsing */
end_comment

begin_define
define|#
directive|define
name|DOSYM
value|0405
end_define

begin_define
define|#
directive|define
name|FISYM
value|0420
end_define

begin_define
define|#
directive|define
name|EFSYM
value|0422
end_define

begin_define
define|#
directive|define
name|ELSYM
value|0421
end_define

begin_define
define|#
directive|define
name|INSYM
value|0412
end_define

begin_define
define|#
directive|define
name|BRSYM
value|0406
end_define

begin_define
define|#
directive|define
name|KTSYM
value|0450
end_define

begin_define
define|#
directive|define
name|THSYM
value|0444
end_define

begin_define
define|#
directive|define
name|ODSYM
value|0441
end_define

begin_define
define|#
directive|define
name|ESSYM
value|0442
end_define

begin_define
define|#
directive|define
name|IFSYM
value|0436
end_define

begin_define
define|#
directive|define
name|FORSYM
value|0435
end_define

begin_define
define|#
directive|define
name|WHSYM
value|0433
end_define

begin_define
define|#
directive|define
name|UNSYM
value|0427
end_define

begin_define
define|#
directive|define
name|CASYM
value|0417
end_define

begin_define
define|#
directive|define
name|PROCSYM
value|0460
end_define

begin_define
define|#
directive|define
name|SELSYM
value|0470
end_define

begin_define
define|#
directive|define
name|TIMSYM
value|0474
end_define

begin_define
define|#
directive|define
name|SYMREP
value|04000
end_define

begin_define
define|#
directive|define
name|ECSYM
value|(SYMREP|';')
end_define

begin_define
define|#
directive|define
name|ANDFSYM
value|(SYMREP|'&')
end_define

begin_define
define|#
directive|define
name|ORFSYM
value|(SYMREP|'|')
end_define

begin_define
define|#
directive|define
name|APPSYM
value|(SYMREP|'>')
end_define

begin_define
define|#
directive|define
name|DOCSYM
value|(SYMREP|'<')
end_define

begin_define
define|#
directive|define
name|SYMALT1
value|01000
end_define

begin_define
define|#
directive|define
name|SYMALT2
value|010000
end_define

begin_define
define|#
directive|define
name|COOPSYM
value|(SYMALT1|'|')
end_define

begin_define
define|#
directive|define
name|IPROC
value|(SYMALT1|'(')
end_define

begin_define
define|#
directive|define
name|OPROC
value|(SYMALT2|'(')
end_define

begin_define
define|#
directive|define
name|EOFSYM
value|02000
end_define

begin_define
define|#
directive|define
name|SYMFLG
value|0400
end_define

begin_comment
comment|/* arg to `cmd' */
end_comment

begin_define
define|#
directive|define
name|NLFLG
value|1
end_define

begin_define
define|#
directive|define
name|MTFLG
value|2
end_define

begin_comment
comment|/* for peekc */
end_comment

begin_define
define|#
directive|define
name|MARK
value|0100000
end_define

begin_comment
comment|/* odd chars */
end_comment

begin_define
define|#
directive|define
name|DQUOTE
value|'"'
end_define

begin_define
define|#
directive|define
name|SQUOTE
value|'`'
end_define

begin_define
define|#
directive|define
name|DOLLAR
value|'$'
end_define

begin_define
define|#
directive|define
name|BRACE
value|'{'
end_define

begin_define
define|#
directive|define
name|LPAREN
value|'('
end_define

begin_define
define|#
directive|define
name|RPAREN
value|')'
end_define

begin_struct
struct|struct
name|sysnod
block|{
ifdef|#
directive|ifdef
name|apollo
comment|/* pointers can not be in readonly sections */
name|char
name|sysnam
index|[
literal|28
index|]
decl_stmt|;
else|#
directive|else
name|char
modifier|*
name|sysnam
decl_stmt|;
endif|#
directive|endif
comment|/* apollo */
name|unsigned
name|sysval
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|A_RAW
value|1
end_define

begin_comment
comment|/* string needs no processing */
end_comment

begin_define
define|#
directive|define
name|A_MAKE
value|2
end_define

begin_comment
comment|/* bit set during argument expansion */
end_comment

begin_define
define|#
directive|define
name|A_MAC
value|4
end_define

begin_comment
comment|/* string needs macro expansion */
end_comment

begin_define
define|#
directive|define
name|A_EXP
value|8
end_define

begin_comment
comment|/* string needs file expansion */
end_comment

begin_comment
comment|/* dummy for access only */
end_comment

begin_struct
struct|struct
name|argnod
block|{
name|struct
name|argnod
modifier|*
name|argnxt
decl_stmt|;
name|struct
name|argnod
modifier|*
name|argchn
decl_stmt|;
name|char
name|argflag
decl_stmt|;
name|char
name|argval
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|sysnod
name|SYSTAB
index|[]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|argnod
modifier|*
name|ARGPTR
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|wdval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wdnum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ARGPTR
name|wdarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ARGPTR
name|gchain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|subflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SYSTAB
name|reserved
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SYSTAB
name|commands
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SYSTAB
name|option_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SYSTAB
name|signal_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SYSTAB
name|sig_messages
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SYSTAB
name|testops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SYSTAB
name|attributes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|let_syntax
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|unexpected
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|MSG
name|unmatched
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEVFD
end_ifdef

begin_decl_stmt
specifier|extern
name|MSG
name|devfd
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEVFD */
end_comment

end_unit

