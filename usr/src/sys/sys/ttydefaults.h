begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ttydefaults.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * System wide defaults of terminal state.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TTYDEFAULTS_
end_ifndef

begin_define
define|#
directive|define
name|_TTYDEFAULTS_
end_define

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|x
parameter_list|)
value|(x&037)
end_define

begin_comment
comment|/*  * Control Character Defaults  */
end_comment

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
value|_POSIX_VDISABLE
end_define

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
name|CERASE2
value|_POSIX_VDISABLE
end_define

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
name|CFLUSHO
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
name|CQUOTE
value|'\\'
end_define

begin_define
define|#
directive|define
name|CEOT
value|CEOF
end_define

begin_comment
comment|/* aliases */
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
value|CFLUSHO
end_define

begin_comment
comment|/*  * Settings on first open of a tty.  */
end_comment

begin_define
define|#
directive|define
name|TTYDEF_IFLAG
value|(BRKINT | ISTRIP | IMAXBEL | IXON)
end_define

begin_define
define|#
directive|define
name|TTYDEF_OFLAG
value|(0)
end_define

begin_define
define|#
directive|define
name|TTYDEF_LFLAG
value|(ECHO | ICANON | ISIG | IEXTEN)
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_TTYDEFAULTS_*/
end_comment

begin_comment
comment|/*  * define TTYDEFCHARS to include an array of default control characters.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TTYDEFCHARS
end_ifdef

begin_decl_stmt
name|u_char
name|ttydefchars
index|[
name|NCC
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
name|CQUOTE
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
name|CFLUSHO
block|,
name|CMIN
block|,
name|CTIME
block|,
name|CERASE2
block|,
name|_POSIX_VDISABLE
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*TTYDEFCHARS*/
end_comment

end_unit

