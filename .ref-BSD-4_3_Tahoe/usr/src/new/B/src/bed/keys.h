begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: keys.h,v 2.3 85/08/22 16:04:38 timo Exp $ */
end_comment

begin_comment
comment|/*  * B editor -- Function key and control character definitions.  */
end_comment

begin_define
define|#
directive|define
name|Ctl
parameter_list|(
name|x
parameter_list|)
value|('x'&037)
end_define

begin_comment
comment|/*  * Commands bound to control characters.  *  * Not all control characters can be freely used:  * ^Q and ^S are used by the Unix operating system  * for output flow control, and ^Z is used by BSD  * Unix systems for `job control'.  *  * Also note that ^H, ^I and ^M (and somtimes ^J) have their  * own keys on most keyboards and thus usually have a strong  * intuitive meaning.  */
end_comment

begin_define
define|#
directive|define
name|COPY
value|Ctl(C)
end_define

begin_define
define|#
directive|define
name|DELETE
value|Ctl(D)
end_define

begin_define
define|#
directive|define
name|GOTO
value|Ctl(G)
end_define

begin_define
define|#
directive|define
name|UNDO
value|Ctl(H)
end_define

begin_define
define|#
directive|define
name|ACCEPT
value|Ctl(I)
end_define

begin_comment
comment|/* TAB */
end_comment

begin_define
define|#
directive|define
name|NEWLINE
value|Ctl(J)
end_define

begin_define
define|#
directive|define
name|REDRAW
value|Ctl(L)
end_define

begin_define
define|#
directive|define
name|RETURN
value|Ctl(M)
end_define

begin_define
define|#
directive|define
name|RECORD
value|Ctl(R)
end_define

begin_define
define|#
directive|define
name|PLAYBACK
value|Ctl(P)
end_define

begin_define
define|#
directive|define
name|USEMACRO
value|PLAYBACK
end_define

begin_define
define|#
directive|define
name|SAVEMACRO
value|RECORD
end_define

begin_define
define|#
directive|define
name|REDO
value|Ctl(U)
end_define

begin_define
define|#
directive|define
name|EXIT
value|Ctl(X)
end_define

begin_comment
comment|/*  * Commands bound to ESC sequences.  *  * When 'inchar()' in "getc.c" sees an ESC-x sequence, it  * will return (x&0177)|MASK.  */
end_comment

begin_define
define|#
directive|define
name|MASK
value|0200
end_define

begin_comment
comment|/* Must fit in a character! */
end_comment

begin_define
define|#
directive|define
name|WIDEN
value|('w'|MASK)
end_define

begin_comment
comment|/* so "\ew" is recognized as WIDEN */
end_comment

begin_define
define|#
directive|define
name|NARROW
value|('f'|MASK)
end_define

begin_comment
comment|/* FIRST */
end_comment

begin_define
define|#
directive|define
name|RNARROW
value|('l'|MASK)
end_define

begin_comment
comment|/* LAST */
end_comment

begin_define
define|#
directive|define
name|EXTEND
value|('e'|MASK)
end_define

begin_define
define|#
directive|define
name|UPLINE
value|('u'|MASK)
end_define

begin_define
define|#
directive|define
name|PREVIOUS
value|('p'|MASK)
end_define

begin_define
define|#
directive|define
name|NEXT
value|('n'|MASK)
end_define

begin_define
define|#
directive|define
name|DOWNLINE
value|('d'|MASK)
end_define

begin_define
define|#
directive|define
name|LEFTARROW
value|(','|MASK)
end_define

begin_define
define|#
directive|define
name|RITEARROW
value|('.'|MASK)
end_define

begin_define
define|#
directive|define
name|UPARROW
value|('U'|MASK)
end_define

begin_define
define|#
directive|define
name|DOWNARROW
value|('D'|MASK)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HELPFUL
end_ifdef

begin_define
define|#
directive|define
name|HELP
value|('?'|MASK)
end_define

begin_endif
endif|#
directive|endif
endif|HELPFUL
end_endif

end_unit

