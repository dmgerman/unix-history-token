begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ttydefaults.h	8.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * System wide defaults for terminal state.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TTYDEFAULTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TTYDEFAULTS_H_
end_define

begin_comment
comment|/*  * Defaults on "first" open.  */
end_comment

begin_define
define|#
directive|define
name|TTYDEF_IFLAG
value|(BRKINT | ISTRIP | ICRNL | IMAXBEL | IXON | IXANY)
end_define

begin_define
define|#
directive|define
name|TTYDEF_OFLAG
value|(OPOST | ONLCR | OXTABS)
end_define

begin_define
define|#
directive|define
name|TTYDEF_LFLAG
value|(ECHO | ICANON | ISIG | IEXTEN | ECHOE|ECHOKE|ECHOCTL)
end_define

begin_define
define|#
directive|define
name|TTYDEF_CFLAG
value|(CREAD | CS7 | PARENB | HUPCL)
end_define

begin_define
define|#
directive|define
name|TTYDEF_SPEED
value|(B9600)
end_define

begin_comment
comment|/*  * Control Character Defaults  */
end_comment

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|x
parameter_list|)
value|(x&037)
end_define

begin_define
define|#
directive|define
name|CEOF
value|CTRL('d')
end_define

begin_define
define|#
directive|define
name|CEOL
value|((unsigned char)'\377')
end_define

begin_comment
comment|/* XXX avoid _POSIX_VDISABLE */
end_comment

begin_define
define|#
directive|define
name|CERASE
value|0177
end_define

begin_define
define|#
directive|define
name|CINTR
value|CTRL('c')
end_define

begin_define
define|#
directive|define
name|CSTATUS
value|((unsigned char)'\377')
end_define

begin_comment
comment|/* XXX avoid _POSIX_VDISABLE */
end_comment

begin_define
define|#
directive|define
name|CKILL
value|CTRL('u')
end_define

begin_define
define|#
directive|define
name|CMIN
value|1
end_define

begin_define
define|#
directive|define
name|CQUIT
value|034
end_define

begin_comment
comment|/* FS, ^\ */
end_comment

begin_define
define|#
directive|define
name|CSUSP
value|CTRL('z')
end_define

begin_define
define|#
directive|define
name|CTIME
value|0
end_define

begin_define
define|#
directive|define
name|CDSUSP
value|CTRL('y')
end_define

begin_define
define|#
directive|define
name|CSTART
value|CTRL('q')
end_define

begin_define
define|#
directive|define
name|CSTOP
value|CTRL('s')
end_define

begin_define
define|#
directive|define
name|CLNEXT
value|CTRL('v')
end_define

begin_define
define|#
directive|define
name|CDISCARD
value|CTRL('o')
end_define

begin_define
define|#
directive|define
name|CWERASE
value|CTRL('w')
end_define

begin_define
define|#
directive|define
name|CREPRINT
value|CTRL('r')
end_define

begin_define
define|#
directive|define
name|CEOT
value|CEOF
end_define

begin_comment
comment|/* compat */
end_comment

begin_define
define|#
directive|define
name|CBRK
value|CEOL
end_define

begin_define
define|#
directive|define
name|CRPRNT
value|CREPRINT
end_define

begin_define
define|#
directive|define
name|CFLUSH
value|CDISCARD
end_define

begin_comment
comment|/* PROTECTED INCLUSION ENDS HERE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_TTYDEFAULTS_H_ */
end_comment

begin_comment
comment|/*  * #define TTYDEFCHARS to include an array of default control characters.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TTYDEFCHARS
end_ifdef

begin_decl_stmt
name|cc_t
name|ttydefchars
index|[
name|NCCS
index|]
init|=
block|{
name|CEOF
block|,
name|CEOL
block|,
name|CEOL
block|,
name|CERASE
block|,
name|CWERASE
block|,
name|CKILL
block|,
name|CREPRINT
block|,
name|_POSIX_VDISABLE
block|,
name|CINTR
block|,
name|CQUIT
block|,
name|CSUSP
block|,
name|CDSUSP
block|,
name|CSTART
block|,
name|CSTOP
block|,
name|CLNEXT
block|,
name|CDISCARD
block|,
name|CMIN
block|,
name|CTIME
block|,
name|CSTATUS
block|,
name|_POSIX_VDISABLE
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|TTYDEFCHARS
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

