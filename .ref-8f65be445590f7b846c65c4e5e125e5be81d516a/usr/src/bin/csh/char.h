begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)char.h	5.5 (Berkeley) %G%  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|_cmap
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_Q
value|0x001
end_define

begin_comment
comment|/* '" */
end_comment

begin_define
define|#
directive|define
name|_Q1
value|0x002
end_define

begin_comment
comment|/* ` */
end_comment

begin_define
define|#
directive|define
name|_SP
value|0x004
end_define

begin_comment
comment|/* space and tab */
end_comment

begin_define
define|#
directive|define
name|_NL
value|0x008
end_define

begin_comment
comment|/* \n */
end_comment

begin_define
define|#
directive|define
name|_META
value|0x010
end_define

begin_comment
comment|/* lex meta characters, sp #'`";&<>()|\t\n */
end_comment

begin_define
define|#
directive|define
name|_GLOB
value|0x020
end_define

begin_comment
comment|/* glob characters, *?{[` */
end_comment

begin_define
define|#
directive|define
name|_ESC
value|0x040
end_define

begin_comment
comment|/* \ */
end_comment

begin_define
define|#
directive|define
name|_DOL
value|0x080
end_define

begin_comment
comment|/* $ */
end_comment

begin_define
define|#
directive|define
name|_DIG
value|0x100
end_define

begin_comment
comment|/* 0-9 */
end_comment

begin_define
define|#
directive|define
name|_LET
value|0x200
end_define

begin_comment
comment|/* a-z, A-Z, _ */
end_comment

begin_define
define|#
directive|define
name|cmap
parameter_list|(
name|c
parameter_list|,
name|bits
parameter_list|)
value|(_cmap[(unsigned char)(c)]& (bits))
end_define

begin_define
define|#
directive|define
name|isglob
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _GLOB)
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _SP)
end_define

begin_define
define|#
directive|define
name|isspnl
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _SP|_NL)
end_define

begin_define
define|#
directive|define
name|ismeta
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _META)
end_define

begin_define
define|#
directive|define
name|digit
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _DIG)
end_define

begin_define
define|#
directive|define
name|letter
parameter_list|(
name|c
parameter_list|)
value|cmap(c, _LET)
end_define

begin_define
define|#
directive|define
name|alnum
parameter_list|(
name|c
parameter_list|)
value|(digit(c) || letter(c))
end_define

begin_define
define|#
directive|define
name|LINELEN
value|128
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|linp
decl_stmt|,
name|linbuf
index|[
name|LINELEN
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CSHPUTCHAR
value|{ \ 	if (!(ch&QUOTE)&& (ch == 0177 || ch< ' '&& ch != '\t'&& \ 	    ch != '\n')) { \ 		*linp++ = '^'; \ 		if (ch == 0177) \ 			ch = '?'; \ 		else \ 			ch |= 'A' - 1; \ 		if (linp>=&linbuf[sizeof linbuf - 2]) \ 			flush(); \ 	} \ 	ch&= TRIM; \ 	*linp++ = ch; \ 	if (ch == '\n' || linp>=&linbuf[sizeof(linbuf) - 2]) \ 		flush(); \ }
end_define

end_unit

