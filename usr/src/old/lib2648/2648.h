begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)2648.h	5.1 (Berkeley) 4/26/85  */
end_comment

begin_comment
comment|/*  * lib2648: routines to deal directly with the HP 2648 Graphics terminal.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|ESC
value|'\033'
end_define

begin_comment
comment|/* Escape */
end_comment

begin_comment
comment|/* Normal/inverse video */
end_comment

begin_define
define|#
directive|define
name|NORMAL
value|0
end_define

begin_comment
comment|/* not inverse video */
end_comment

begin_define
define|#
directive|define
name|INVERSE
value|1
end_define

begin_comment
comment|/* inverse video */
end_comment

begin_comment
comment|/* Kinds of lines we can draw */
end_comment

begin_define
define|#
directive|define
name|MX
value|10
end_define

begin_comment
comment|/* exclusive or what's on screen */
end_comment

begin_define
define|#
directive|define
name|MC
value|11
end_define

begin_comment
comment|/* clear what's on screen */
end_comment

begin_define
define|#
directive|define
name|MS
value|12
end_define

begin_comment
comment|/* set what's on screen */
end_comment

begin_comment
comment|/* Escape sequence modes the terminal might be in */
end_comment

begin_define
define|#
directive|define
name|NONE
value|20
end_define

begin_comment
comment|/* not in an escape sequence */
end_comment

begin_define
define|#
directive|define
name|ESCD
value|21
end_define

begin_comment
comment|/* in an escape * d sequence */
end_comment

begin_define
define|#
directive|define
name|ESCP
value|22
end_define

begin_comment
comment|/* in an escape * p sequence */
end_comment

begin_define
define|#
directive|define
name|ESCM
value|23
end_define

begin_comment
comment|/* in an escape * m sequence */
end_comment

begin_define
define|#
directive|define
name|TEXT
value|24
end_define

begin_comment
comment|/* in graphics text mode */
end_comment

begin_comment
comment|/*  * Constants for 2648 ^E/^F handshaking.  */
end_comment

begin_define
define|#
directive|define
name|ENQ
value|5
end_define

begin_comment
comment|/* ^E sent by system to terminal */
end_comment

begin_define
define|#
directive|define
name|ACK
value|6
end_define

begin_comment
comment|/* ^F reply by terminal to system */
end_comment

begin_define
define|#
directive|define
name|TBLKSIZ
value|32
end_define

begin_comment
comment|/* Max # chars between handshakes */
end_comment

begin_comment
comment|/*  * Misc. variables used by lib2648.  */
end_comment

begin_decl_stmt
name|int
name|_on2648
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if getenv("TERM") is hp2648 */
end_comment

begin_decl_stmt
name|int
name|_video
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* are we in inverse video mode? */
end_comment

begin_decl_stmt
name|int
name|_actsmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line type mode screen actually in */
end_comment

begin_decl_stmt
name|int
name|_supsmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line type mode screen supposed to be in */
end_comment

begin_decl_stmt
name|int
name|_escmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flavor of escape sequence currently in */
end_comment

begin_decl_stmt
name|int
name|_cursoron
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if cursor is on */
end_comment

begin_decl_stmt
name|int
name|_outcount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of consecutive chars without read sent */
end_comment

begin_decl_stmt
name|char
name|_pushback
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* queue of chars pushed back onto the input */
end_comment

begin_decl_stmt
name|char
modifier|*
name|_pb_front
decl_stmt|,
modifier|*
name|_pb_back
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_penx
decl_stmt|,
name|_peny
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where pen is really at */
end_comment

begin_decl_stmt
name|int
name|_curx
decl_stmt|,
name|_cury
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where cursor is really at */
end_comment

begin_decl_stmt
name|int
name|_supx
decl_stmt|,
name|_supy
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where pen and cursor are supposed to be */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_decl_stmt
name|FILE
modifier|*
name|trace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trace file for debugging */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

