begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)qfont.c	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	derived from:  "@(#)qfont.c	6.2	ULTRIX	2/4/88"  */
end_comment

begin_comment
comment|/************************************************************************  *									*  *			Copyright (c) 1984, 1987 by			*  *		Digital Equipment Corporation, Maynard, MA		*  *			All rights reserved.				*  *									*  *   This software is furnished under a license and may be used and	*  *   copied  only  in accordance with the terms of such license and	*  *   with the  inclusion  of  the  above  copyright  notice.   This	*  *   software  or  any  other copies thereof may not be provided or	*  *   otherwise made available to any other person.  No title to and	*  *   ownership of the software is hereby transferred.			*  *									*  *   This software is  derived  from  software  received  from  the	*  *   University    of   California,   Berkeley,   and   from   Bell	*  *   Laboratories.  Use, duplication, or disclosure is  subject  to	*  *   restrictions  under  license  agreements  with  University  of	*  *   California and with AT&T.						*  *									*  *   The information in this software is subject to change  without	*  *   notice  and should not be construed as a commitment by Digital	*  *   Equipment Corporation.						*  *									*  *   Digital assumes no responsibility for the use  or  reliability	*  *   of its software on equipment which is not supplied by Digital.	*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*  * The following tables are used to translate LK201 key strokes  * into ascii characters. The tables also support the special  * function keys.  */
end_comment

begin_decl_stmt
name|unsigned
name|short
name|q_key
index|[]
init|=
block|{
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*   0 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*   8 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  16 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  24 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  32 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  40 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  48 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  56 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  64 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  72 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x101
block|,
literal|0x102
comment|/*  80 */
block|,
literal|0x103
block|,
literal|0x104
block|,
literal|0x105
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  88 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x106
block|,
literal|0x107
block|,
literal|0x108
block|,
literal|0x109
comment|/*  96 */
block|,
literal|0x10a
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/* 104 */
block|,
literal|0x00
block|,
literal|0x1b
block|,
literal|0x08
block|,
literal|0x0a
block|,
literal|0x10b
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/* 112 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x10c
block|,
literal|0x10d
block|,
literal|0x00
block|,
literal|0x00
comment|/* 120 */
block|,
literal|0x10e
block|,
literal|0x10f
block|,
literal|0x110
block|,
literal|0x111
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/* 128 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x112
block|,
literal|0x113
block|,
literal|0x114
block|,
literal|0x115
block|,
literal|0x116
block|,
literal|0x117
comment|/* 136 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x120
block|,
literal|0x00
block|,
literal|0x121
block|,
literal|0x122
block|,
literal|0x123
block|,
literal|0x124
comment|/* 144 */
block|,
literal|0x125
block|,
literal|0x126
block|,
literal|0x127
block|,
literal|0x128
block|,
literal|0x129
block|,
literal|0x12a
block|,
literal|0x12b
block|,
literal|0x12c
comment|/* 152 */
block|,
literal|0x12d
block|,
literal|0x118
block|,
literal|0x119
block|,
literal|0x11a
block|,
literal|0x11b
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x11c
comment|/* 160 */
block|,
literal|0x11d
block|,
literal|0x11e
block|,
literal|0x11f
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/* 168 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/* 176 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x7f
block|,
literal|'\r'
block|,
literal|0x09
block|,
literal|'`'
comment|/* 184 */
block|,
literal|'1'
block|,
literal|'q'
block|,
literal|'a'
block|,
literal|'z'
block|,
literal|0x00
block|,
literal|'2'
block|,
literal|'w'
block|,
literal|'s'
comment|/* 192 */
block|,
literal|'x'
block|,
literal|'<'
block|,
literal|0x00
block|,
literal|'3'
block|,
literal|'e'
block|,
literal|'d'
block|,
literal|'c'
block|,
literal|0x00
comment|/* 200 */
block|,
literal|'4'
block|,
literal|'r'
block|,
literal|'f'
block|,
literal|'v'
block|,
literal|' '
block|,
literal|0x00
block|,
literal|'5'
block|,
literal|'t'
comment|/* 208 */
block|,
literal|'g'
block|,
literal|'b'
block|,
literal|0x00
block|,
literal|'6'
block|,
literal|'y'
block|,
literal|'h'
block|,
literal|'n'
block|,
literal|0x00
comment|/* 216 */
block|,
literal|'7'
block|,
literal|'u'
block|,
literal|'j'
block|,
literal|'m'
block|,
literal|0x00
block|,
literal|'8'
block|,
literal|'i'
block|,
literal|'k'
comment|/* 224 */
block|,
literal|','
block|,
literal|0x00
block|,
literal|'9'
block|,
literal|'o'
block|,
literal|'l'
block|,
literal|'.'
block|,
literal|0x00
block|,
literal|'0'
comment|/* 232 */
block|,
literal|'p'
block|,
literal|0x00
block|,
literal|';'
block|,
literal|'/'
block|,
literal|0x00
block|,
literal|'='
block|,
literal|']'
block|,
literal|'\\'
comment|/* 240 */
block|,
literal|0x00
block|,
literal|'-'
block|,
literal|'['
block|,
literal|'\''
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/* 248 */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|short
name|q_shift_key
index|[]
init|=
block|{
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*   0 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*   8 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  16 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  24 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  32 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  40 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  48 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  56 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  64 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  72 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x101
block|,
literal|0x102
comment|/*  80 */
block|,
literal|0x103
block|,
literal|0x104
block|,
literal|0x105
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/*  88 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x106
block|,
literal|0x107
block|,
literal|0x108
block|,
literal|0x109
comment|/*  96 */
block|,
literal|0x10a
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/* 104 */
block|,
literal|0x00
block|,
literal|0x1b
block|,
literal|0x08
block|,
literal|0x0a
block|,
literal|0x10b
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/* 112 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x10c
block|,
literal|0x10d
block|,
literal|0x00
block|,
literal|0x00
comment|/* 120 */
block|,
literal|0x10e
block|,
literal|0x10f
block|,
literal|0x110
block|,
literal|0x111
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/* 128 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x112
block|,
literal|0x113
block|,
literal|0x114
block|,
literal|0x115
block|,
literal|0x116
block|,
literal|0x117
comment|/* 136 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x120
block|,
literal|0x00
block|,
literal|0x121
block|,
literal|0x122
block|,
literal|0x123
block|,
literal|0x124
comment|/* 144 */
block|,
literal|0x125
block|,
literal|0x126
block|,
literal|0x127
block|,
literal|0x128
block|,
literal|0x129
block|,
literal|0x12a
block|,
literal|0x12b
block|,
literal|0x12c
comment|/* 152 */
block|,
literal|0x12d
block|,
literal|0x118
block|,
literal|0x119
block|,
literal|0x11a
block|,
literal|0x11b
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x11c
comment|/* 160 */
block|,
literal|0x11d
block|,
literal|0x11e
block|,
literal|0x11f
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/* 168 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/* 176 */
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x7f
block|,
literal|'\r'
block|,
literal|0x09
block|,
literal|'~'
comment|/* 184 */
block|,
literal|'!'
block|,
literal|'Q'
block|,
literal|'A'
block|,
literal|'Z'
block|,
literal|0x00
block|,
literal|'@'
block|,
literal|'W'
block|,
literal|'S'
comment|/* 192 */
block|,
literal|'X'
block|,
literal|'>'
block|,
literal|0x00
block|,
literal|'#'
block|,
literal|'E'
block|,
literal|'D'
block|,
literal|'C'
block|,
literal|0x00
comment|/* 200 */
block|,
literal|'$'
block|,
literal|'R'
block|,
literal|'F'
block|,
literal|'V'
block|,
literal|' '
block|,
literal|0x00
block|,
literal|'%'
block|,
literal|'T'
comment|/* 208 */
block|,
literal|'G'
block|,
literal|'B'
block|,
literal|0x00
block|,
literal|'^'
block|,
literal|'Y'
block|,
literal|'H'
block|,
literal|'N'
block|,
literal|0x00
comment|/* 216 */
block|,
literal|'&'
block|,
literal|'U'
block|,
literal|'J'
block|,
literal|'M'
block|,
literal|0x00
block|,
literal|'*'
block|,
literal|'I'
block|,
literal|'K'
comment|/* 224 */
block|,
literal|','
block|,
literal|0x00
block|,
literal|'('
block|,
literal|'O'
block|,
literal|'L'
block|,
literal|'.'
block|,
literal|0x00
block|,
literal|')'
comment|/* 232 */
block|,
literal|'P'
block|,
literal|0x00
block|,
literal|':'
block|,
literal|'?'
block|,
literal|0x00
block|,
literal|'+'
block|,
literal|'}'
block|,
literal|'|'
comment|/* 240 */
block|,
literal|0x00
block|,
literal|'_'
block|,
literal|'{'
block|,
literal|'"'
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
comment|/* 248 */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * LK201 special purpose keys. Translations from the tables above  * includes codes for the function keys and other goodies. They can  * be determined by the presence of the 8th bit being set.  The   * following table is accessed by removing that bit and using the   * result as the index to the following table. Note that table begins  * a null entry.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|q_special
index|[]
init|=
block|{
literal|0
block|,
literal|"\33[11~"
block|,
comment|/* f1 */
literal|"\33[12~"
block|,
comment|/* f2 */
literal|"\33[13~"
block|,
comment|/* f3 */
literal|"\33[14~"
block|,
comment|/* f4 */
literal|"\33[15~"
block|,
comment|/* f5 */
literal|"\33[17~"
block|,
comment|/* f6 */
literal|"\33[18~"
block|,
comment|/* f7 */
literal|"\33[19~"
block|,
comment|/* f8 */
literal|"\33[20~"
block|,
comment|/* f9 */
literal|"\33[21~"
block|,
comment|/* f10 */
literal|"\33[26~"
block|,
comment|/* f14 */
literal|"\33[28~"
block|,
comment|/* f15 */
literal|"\33[29~"
block|,
comment|/* f16 */
literal|"\33[31~"
block|,
comment|/* f17 */
literal|"\33[32~"
block|,
comment|/* f18 */
literal|"\33[33~"
block|,
comment|/* f19 */
literal|"\33[34~"
block|,
comment|/* f20 */
literal|"\33[1~"
block|,
comment|/* find */
literal|"\33[2~"
block|,
comment|/* insert */
literal|"\33[3~"
block|,
comment|/* remove */
literal|"\33[4~"
block|,
comment|/* select */
literal|"\33[5~"
block|,
comment|/* prev */
literal|"\33[6~"
block|,
comment|/* next */
literal|"\33OP"
block|,
comment|/* pf1 */
literal|"\33OQ"
block|,
comment|/* pf2 */
literal|"\33OR"
block|,
comment|/* pf3 */
literal|"\33OS"
block|,
comment|/* pf4 */
literal|"\33[D"
block|,
comment|/* left */
literal|"\33[C"
block|,
comment|/* right */
literal|"\33[B"
block|,
comment|/* down */
literal|"\33[A"
block|,
comment|/* up */
literal|"\33Op"
block|,
comment|/* key pad 0 */
literal|"\33On"
block|,
comment|/* key pad . */
literal|"\33OM"
block|,
comment|/* key pad enter */
literal|"\33Oq"
block|,
comment|/* key pad 1 */
literal|"\33Or"
block|,
comment|/* key pad 2 */
literal|"\33Os"
block|,
comment|/* key pad 3 */
literal|"\33Ot"
block|,
comment|/* key pad 4 */
literal|"\33Ou"
block|,
comment|/* key pad 5 */
literal|"\33Ov"
block|,
comment|/* key pad 6 */
literal|"\33O/*"
block|,
comment|/* key pad , */
literal|"\33Ow"
block|,
comment|/* key pad 7 */
literal|"\33Ox"
block|,
comment|/* key pad 8 */
literal|"\33Oy"
block|,
comment|/* key pad 9 */
literal|"\33Om"
block|,
comment|/* key pad - */
comment|/* 	 * The following strings are to allow a numeric keypad 	 * mode and still use the same translation tables 	 */
literal|"0"
block|,
literal|"."
block|,
literal|"\r"
block|,
literal|"1"
block|,
literal|"2"
block|,
literal|"3"
block|,
literal|"4"
block|,
literal|"5"
block|,
literal|"6"
block|,
literal|","
block|,
literal|"7"
block|,
literal|"8"
block|,
literal|"9"
block|,
literal|"-"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * QVSS font table of displayable characters.  */
end_comment

begin_decl_stmt
name|char
name|q_font
index|[]
init|=
block|{
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
literal|0x00
block|,
comment|/* 0x00000000	   */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  ! */
literal|0x00
block|,
comment|/* 0x00000000	  ! */
literal|0x08
block|,
comment|/* 0x00001000	  ! */
literal|0x08
block|,
comment|/* 0x00001000	  ! */
literal|0x08
block|,
comment|/* 0x00001000	  ! */
literal|0x08
block|,
comment|/* 0x00001000	  ! */
literal|0x08
block|,
comment|/* 0x00001000	  ! */
literal|0x08
block|,
comment|/* 0x00001000	  ! */
literal|0x08
block|,
comment|/* 0x00001000	  ! */
literal|0x08
block|,
comment|/* 0x00001000	  ! */
literal|0x00
block|,
comment|/* 0x00000000	  ! */
literal|0x08
block|,
comment|/* 0x00001000	  ! */
literal|0x00
block|,
comment|/* 0x00000000	  ! */
literal|0x00
block|,
comment|/* 0x00000000	  ! */
literal|0x00
block|,
comment|/* 0x00000000	  ! */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  " */
literal|0x00
block|,
comment|/* 0x00000000	  " */
literal|0x24
block|,
comment|/* 0x00100100	  " */
literal|0x24
block|,
comment|/* 0x00100100	  " */
literal|0x24
block|,
comment|/* 0x00100100	  " */
literal|0x00
block|,
comment|/* 0x00000000	  " */
literal|0x00
block|,
comment|/* 0x00000000	  " */
literal|0x00
block|,
comment|/* 0x00000000	  " */
literal|0x00
block|,
comment|/* 0x00000000	  " */
literal|0x00
block|,
comment|/* 0x00000000	  " */
literal|0x00
block|,
comment|/* 0x00000000	  " */
literal|0x00
block|,
comment|/* 0x00000000	  " */
literal|0x00
block|,
comment|/* 0x00000000	  " */
literal|0x00
block|,
comment|/* 0x00000000	  " */
literal|0x00
block|,
comment|/* 0x00000000	  " */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  # */
literal|0x00
block|,
comment|/* 0x00000000	  # */
literal|0x00
block|,
comment|/* 0x00000000	  # */
literal|0x12
block|,
comment|/* 0x00010010	  # */
literal|0x12
block|,
comment|/* 0x00010010	  # */
literal|0x3f
block|,
comment|/* 0x00111111	  # */
literal|0x12
block|,
comment|/* 0x00010010	  # */
literal|0x12
block|,
comment|/* 0x00010010	  # */
literal|0x3f
block|,
comment|/* 0x00111111	  # */
literal|0x12
block|,
comment|/* 0x00010010	  # */
literal|0x12
block|,
comment|/* 0x00010010	  # */
literal|0x00
block|,
comment|/* 0x00000000	  # */
literal|0x00
block|,
comment|/* 0x00000000	  # */
literal|0x00
block|,
comment|/* 0x00000000	  # */
literal|0x00
block|,
comment|/* 0x00000000	  # */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  $ */
literal|0x00
block|,
comment|/* 0x00000000	  $ */
literal|0x00
block|,
comment|/* 0x00000000	  $ */
literal|0x08
block|,
comment|/* 0x00001000	  $ */
literal|0x3e
block|,
comment|/* 0x00111110	  $ */
literal|0x09
block|,
comment|/* 0x00001001	  $ */
literal|0x09
block|,
comment|/* 0x00001001	  $ */
literal|0x3e
block|,
comment|/* 0x00111110	  $ */
literal|0x48
block|,
comment|/* 0x01001000	  $ */
literal|0x48
block|,
comment|/* 0x01001000	  $ */
literal|0x3e
block|,
comment|/* 0x00111110	  $ */
literal|0x08
block|,
comment|/* 0x00001000	  $ */
literal|0x00
block|,
comment|/* 0x00000000	  $ */
literal|0x00
block|,
comment|/* 0x00000000	  $ */
literal|0x00
block|,
comment|/* 0x00000000	  $ */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  % */
literal|0x00
block|,
comment|/* 0x00000000	  % */
literal|0x42
block|,
comment|/* 0x01000010	  % */
literal|0x25
block|,
comment|/* 0x00100101	  % */
literal|0x25
block|,
comment|/* 0x00100101	  % */
literal|0x12
block|,
comment|/* 0x00010010	  % */
literal|0x08
block|,
comment|/* 0x00001000	  % */
literal|0x08
block|,
comment|/* 0x00001000	  % */
literal|0x24
block|,
comment|/* 0x00100100	  % */
literal|0x52
block|,
comment|/* 0x01010010	  % */
literal|0x52
block|,
comment|/* 0x01010010	  % */
literal|0x21
block|,
comment|/* 0x00100001	  % */
literal|0x00
block|,
comment|/* 0x00000000	  % */
literal|0x00
block|,
comment|/* 0x00000000	  % */
literal|0x00
block|,
comment|/* 0x00000000	  % */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000& */
literal|0x00
block|,
comment|/* 0x00000000& */
literal|0x0e
block|,
comment|/* 0x00001110& */
literal|0x11
block|,
comment|/* 0x00010001& */
literal|0x11
block|,
comment|/* 0x00010001& */
literal|0x11
block|,
comment|/* 0x00010001& */
literal|0x0e
block|,
comment|/* 0x00001110& */
literal|0x11
block|,
comment|/* 0x00010001& */
literal|0x51
block|,
comment|/* 0x01010001& */
literal|0x21
block|,
comment|/* 0x00100001& */
literal|0x31
block|,
comment|/* 0x00110001& */
literal|0x4e
block|,
comment|/* 0x01001110& */
literal|0x00
block|,
comment|/* 0x00000000& */
literal|0x00
block|,
comment|/* 0x00000000& */
literal|0x00
block|,
comment|/* 0x00000000& */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  ' */
literal|0x00
block|,
comment|/* 0x00000000	  ' */
literal|0x38
block|,
comment|/* 0x00111000	  ' */
literal|0x18
block|,
comment|/* 0x00011000	  ' */
literal|0x04
block|,
comment|/* 0x00000100	  ' */
literal|0x00
block|,
comment|/* 0x00000000	  ' */
literal|0x00
block|,
comment|/* 0x00000000	  ' */
literal|0x00
block|,
comment|/* 0x00000000	  ' */
literal|0x00
block|,
comment|/* 0x00000000	  ' */
literal|0x00
block|,
comment|/* 0x00000000	  ' */
literal|0x00
block|,
comment|/* 0x00000000	  ' */
literal|0x00
block|,
comment|/* 0x00000000	  ' */
literal|0x00
block|,
comment|/* 0x00000000	  ' */
literal|0x00
block|,
comment|/* 0x00000000	  ' */
literal|0x00
block|,
comment|/* 0x00000000	  ' */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  ( */
literal|0x00
block|,
comment|/* 0x00000000	  ( */
literal|0x10
block|,
comment|/* 0x00010000	  ( */
literal|0x08
block|,
comment|/* 0x00001000	  ( */
literal|0x08
block|,
comment|/* 0x00001000	  ( */
literal|0x04
block|,
comment|/* 0x00000100	  ( */
literal|0x04
block|,
comment|/* 0x00000100	  ( */
literal|0x04
block|,
comment|/* 0x00000100	  ( */
literal|0x04
block|,
comment|/* 0x00000100	  ( */
literal|0x08
block|,
comment|/* 0x00001000	  ( */
literal|0x08
block|,
comment|/* 0x00001000	  ( */
literal|0x10
block|,
comment|/* 0x00010000	  ( */
literal|0x00
block|,
comment|/* 0x00000000	  ( */
literal|0x00
block|,
comment|/* 0x00000000	  ( */
literal|0x00
block|,
comment|/* 0x00000000	  ( */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  ) */
literal|0x00
block|,
comment|/* 0x00000000	  ) */
literal|0x04
block|,
comment|/* 0x00000100	  ) */
literal|0x08
block|,
comment|/* 0x00001000	  ) */
literal|0x08
block|,
comment|/* 0x00001000	  ) */
literal|0x10
block|,
comment|/* 0x00010000	  ) */
literal|0x10
block|,
comment|/* 0x00010000	  ) */
literal|0x10
block|,
comment|/* 0x00010000	  ) */
literal|0x10
block|,
comment|/* 0x00010000	  ) */
literal|0x08
block|,
comment|/* 0x00001000	  ) */
literal|0x08
block|,
comment|/* 0x00001000	  ) */
literal|0x04
block|,
comment|/* 0x00000100	  ) */
literal|0x00
block|,
comment|/* 0x00000000	  ) */
literal|0x00
block|,
comment|/* 0x00000000	  ) */
literal|0x00
block|,
comment|/* 0x00000000	  ) */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  * */
literal|0x00
block|,
comment|/* 0x00000000	  * */
literal|0x00
block|,
comment|/* 0x00000000	  * */
literal|0x00
block|,
comment|/* 0x00000000	  * */
literal|0x00
block|,
comment|/* 0x00000000	  * */
literal|0x22
block|,
comment|/* 0x00100010	  * */
literal|0x14
block|,
comment|/* 0x00010100	  * */
literal|0x7f
block|,
comment|/* 0x01111111	  * */
literal|0x14
block|,
comment|/* 0x00010100	  * */
literal|0x22
block|,
comment|/* 0x00100010	  * */
literal|0x00
block|,
comment|/* 0x00000000	  * */
literal|0x00
block|,
comment|/* 0x00000000	  * */
literal|0x00
block|,
comment|/* 0x00000000	  * */
literal|0x00
block|,
comment|/* 0x00000000	  * */
literal|0x00
block|,
comment|/* 0x00000000	  * */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  + */
literal|0x00
block|,
comment|/* 0x00000000	  + */
literal|0x00
block|,
comment|/* 0x00000000	  + */
literal|0x00
block|,
comment|/* 0x00000000	  + */
literal|0x08
block|,
comment|/* 0x00001000	  + */
literal|0x08
block|,
comment|/* 0x00001000	  + */
literal|0x08
block|,
comment|/* 0x00001000	  + */
literal|0x7f
block|,
comment|/* 0x01111111	  + */
literal|0x08
block|,
comment|/* 0x00001000	  + */
literal|0x08
block|,
comment|/* 0x00001000	  + */
literal|0x08
block|,
comment|/* 0x00001000	  + */
literal|0x00
block|,
comment|/* 0x00000000	  + */
literal|0x00
block|,
comment|/* 0x00000000	  + */
literal|0x00
block|,
comment|/* 0x00000000	  + */
literal|0x00
block|,
comment|/* 0x00000000	  + */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  , */
literal|0x00
block|,
comment|/* 0x00000000	  , */
literal|0x00
block|,
comment|/* 0x00000000	  , */
literal|0x00
block|,
comment|/* 0x00000000	  , */
literal|0x00
block|,
comment|/* 0x00000000	  , */
literal|0x00
block|,
comment|/* 0x00000000	  , */
literal|0x00
block|,
comment|/* 0x00000000	  , */
literal|0x00
block|,
comment|/* 0x00000000	  , */
literal|0x00
block|,
comment|/* 0x00000000	  , */
literal|0x00
block|,
comment|/* 0x00000000	  , */
literal|0x1c
block|,
comment|/* 0x00011100	  , */
literal|0x0c
block|,
comment|/* 0x00001100	  , */
literal|0x02
block|,
comment|/* 0x00000010	  , */
literal|0x00
block|,
comment|/* 0x00000000	  , */
literal|0x00
block|,
comment|/* 0x00000000	  , */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x7f
block|,
comment|/* 0x01111111	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
literal|0x00
block|,
comment|/* 0x00000000	  - */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  . */
literal|0x00
block|,
comment|/* 0x00000000	  . */
literal|0x00
block|,
comment|/* 0x00000000	  . */
literal|0x00
block|,
comment|/* 0x00000000	  . */
literal|0x00
block|,
comment|/* 0x00000000	  . */
literal|0x00
block|,
comment|/* 0x00000000	  . */
literal|0x00
block|,
comment|/* 0x00000000	  . */
literal|0x00
block|,
comment|/* 0x00000000	  . */
literal|0x00
block|,
comment|/* 0x00000000	  . */
literal|0x00
block|,
comment|/* 0x00000000	  . */
literal|0x08
block|,
comment|/* 0x00001000	  . */
literal|0x1c
block|,
comment|/* 0x00011100	  . */
literal|0x08
block|,
comment|/* 0x00001000	  . */
literal|0x00
block|,
comment|/* 0x00000000	  . */
literal|0x00
block|,
comment|/* 0x00000000	  . */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  / */
literal|0x00
block|,
comment|/* 0x00000000	  / */
literal|0x40
block|,
comment|/* 0x01000000	  / */
literal|0x40
block|,
comment|/* 0x01000000	  / */
literal|0x20
block|,
comment|/* 0x00100000	  / */
literal|0x10
block|,
comment|/* 0x00010000	  / */
literal|0x08
block|,
comment|/* 0x00001000	  / */
literal|0x04
block|,
comment|/* 0x00000100	  / */
literal|0x02
block|,
comment|/* 0x00000010	  / */
literal|0x01
block|,
comment|/* 0x00000001	  / */
literal|0x01
block|,
comment|/* 0x00000001	  / */
literal|0x01
block|,
comment|/* 0x00000001	  / */
literal|0x00
block|,
comment|/* 0x00000000	  / */
literal|0x00
block|,
comment|/* 0x00000000	  / */
literal|0x00
block|,
comment|/* 0x00000000	  / */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  0 */
literal|0x00
block|,
comment|/* 0x00000000	  0 */
literal|0x0c
block|,
comment|/* 0x00001100	  0 */
literal|0x12
block|,
comment|/* 0x00010010	  0 */
literal|0x21
block|,
comment|/* 0x00100001	  0 */
literal|0x21
block|,
comment|/* 0x00100001	  0 */
literal|0x21
block|,
comment|/* 0x00100001	  0 */
literal|0x21
block|,
comment|/* 0x00100001	  0 */
literal|0x21
block|,
comment|/* 0x00100001	  0 */
literal|0x21
block|,
comment|/* 0x00100001	  0 */
literal|0x12
block|,
comment|/* 0x00010010	  0 */
literal|0x0c
block|,
comment|/* 0x00001100	  0 */
literal|0x00
block|,
comment|/* 0x00000000	  0 */
literal|0x00
block|,
comment|/* 0x00000000	  0 */
literal|0x00
block|,
comment|/* 0x00000000	  0 */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  1 */
literal|0x00
block|,
comment|/* 0x00000000	  1 */
literal|0x08
block|,
comment|/* 0x00001000	  1 */
literal|0x0c
block|,
comment|/* 0x00001100	  1 */
literal|0x0a
block|,
comment|/* 0x00001010	  1 */
literal|0x08
block|,
comment|/* 0x00001000	  1 */
literal|0x08
block|,
comment|/* 0x00001000	  1 */
literal|0x08
block|,
comment|/* 0x00001000	  1 */
literal|0x08
block|,
comment|/* 0x00001000	  1 */
literal|0x08
block|,
comment|/* 0x00001000	  1 */
literal|0x08
block|,
comment|/* 0x00001000	  1 */
literal|0x3e
block|,
comment|/* 0x00111110	  1 */
literal|0x00
block|,
comment|/* 0x00000000	  1 */
literal|0x00
block|,
comment|/* 0x00000000	  1 */
literal|0x00
block|,
comment|/* 0x00000000	  1 */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  2 */
literal|0x00
block|,
comment|/* 0x00000000	  2 */
literal|0x3e
block|,
comment|/* 0x00111110	  2 */
literal|0x41
block|,
comment|/* 0x01000001	  2 */
literal|0x41
block|,
comment|/* 0x01000001	  2 */
literal|0x40
block|,
comment|/* 0x01000000	  2 */
literal|0x20
block|,
comment|/* 0x00100000	  2 */
literal|0x10
block|,
comment|/* 0x00010000	  2 */
literal|0x0c
block|,
comment|/* 0x00001100	  2 */
literal|0x02
block|,
comment|/* 0x00000010	  2 */
literal|0x01
block|,
comment|/* 0x00000001	  2 */
literal|0x7f
block|,
comment|/* 0x01111111	  2 */
literal|0x00
block|,
comment|/* 0x00000000	  2 */
literal|0x00
block|,
comment|/* 0x00000000	  2 */
literal|0x00
block|,
comment|/* 0x00000000	  2 */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  3 */
literal|0x00
block|,
comment|/* 0x00000000	  3 */
literal|0x7f
block|,
comment|/* 0x01111111	  3 */
literal|0x40
block|,
comment|/* 0x01000000	  3 */
literal|0x20
block|,
comment|/* 0x00100000	  3 */
literal|0x10
block|,
comment|/* 0x00010000	  3 */
literal|0x38
block|,
comment|/* 0x00111000	  3 */
literal|0x40
block|,
comment|/* 0x01000000	  3 */
literal|0x40
block|,
comment|/* 0x01000000	  3 */
literal|0x40
block|,
comment|/* 0x01000000	  3 */
literal|0x41
block|,
comment|/* 0x01000001	  3 */
literal|0x3e
block|,
comment|/* 0x00111110	  3 */
literal|0x00
block|,
comment|/* 0x00000000	  3 */
literal|0x00
block|,
comment|/* 0x00000000	  3 */
literal|0x00
block|,
comment|/* 0x00000000	  3 */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  4 */
literal|0x00
block|,
comment|/* 0x00000000	  4 */
literal|0x20
block|,
comment|/* 0x00100000	  4 */
literal|0x30
block|,
comment|/* 0x00110000	  4 */
literal|0x28
block|,
comment|/* 0x00101000	  4 */
literal|0x24
block|,
comment|/* 0x00100100	  4 */
literal|0x22
block|,
comment|/* 0x00100010	  4 */
literal|0x21
block|,
comment|/* 0x00100001	  4 */
literal|0x7f
block|,
comment|/* 0x01111111	  4 */
literal|0x20
block|,
comment|/* 0x00100000	  4 */
literal|0x20
block|,
comment|/* 0x00100000	  4 */
literal|0x20
block|,
comment|/* 0x00100000	  4 */
literal|0x00
block|,
comment|/* 0x00000000	  4 */
literal|0x00
block|,
comment|/* 0x00000000	  4 */
literal|0x00
block|,
comment|/* 0x00000000	  4 */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  5 */
literal|0x00
block|,
comment|/* 0x00000000	  5 */
literal|0x7f
block|,
comment|/* 0x01111111	  5 */
literal|0x01
block|,
comment|/* 0x00000001	  5 */
literal|0x01
block|,
comment|/* 0x00000001	  5 */
literal|0x3d
block|,
comment|/* 0x00111101	  5 */
literal|0x43
block|,
comment|/* 0x01000011	  5 */
literal|0x40
block|,
comment|/* 0x01000000	  5 */
literal|0x40
block|,
comment|/* 0x01000000	  5 */
literal|0x40
block|,
comment|/* 0x01000000	  5 */
literal|0x41
block|,
comment|/* 0x01000001	  5 */
literal|0x3e
block|,
comment|/* 0x00111110	  5 */
literal|0x00
block|,
comment|/* 0x00000000	  5 */
literal|0x00
block|,
comment|/* 0x00000000	  5 */
literal|0x00
block|,
comment|/* 0x00000000	  5 */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  6 */
literal|0x00
block|,
comment|/* 0x00000000	  6 */
literal|0x3c
block|,
comment|/* 0x00111100	  6 */
literal|0x02
block|,
comment|/* 0x00000010	  6 */
literal|0x01
block|,
comment|/* 0x00000001	  6 */
literal|0x01
block|,
comment|/* 0x00000001	  6 */
literal|0x3d
block|,
comment|/* 0x00111101	  6 */
literal|0x43
block|,
comment|/* 0x01000011	  6 */
literal|0x41
block|,
comment|/* 0x01000001	  6 */
literal|0x41
block|,
comment|/* 0x01000001	  6 */
literal|0x41
block|,
comment|/* 0x01000001	  6 */
literal|0x3e
block|,
comment|/* 0x00111110	  6 */
literal|0x00
block|,
comment|/* 0x00000000	  6 */
literal|0x00
block|,
comment|/* 0x00000000	  6 */
literal|0x00
block|,
comment|/* 0x00000000	  6 */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  7 */
literal|0x00
block|,
comment|/* 0x00000000	  7 */
literal|0x7f
block|,
comment|/* 0x01111111	  7 */
literal|0x40
block|,
comment|/* 0x01000000	  7 */
literal|0x40
block|,
comment|/* 0x01000000	  7 */
literal|0x20
block|,
comment|/* 0x00100000	  7 */
literal|0x10
block|,
comment|/* 0x00010000	  7 */
literal|0x08
block|,
comment|/* 0x00001000	  7 */
literal|0x04
block|,
comment|/* 0x00000100	  7 */
literal|0x04
block|,
comment|/* 0x00000100	  7 */
literal|0x02
block|,
comment|/* 0x00000010	  7 */
literal|0x02
block|,
comment|/* 0x00000010	  7 */
literal|0x00
block|,
comment|/* 0x00000000	  7 */
literal|0x00
block|,
comment|/* 0x00000000	  7 */
literal|0x00
block|,
comment|/* 0x00000000	  7 */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  8 */
literal|0x00
block|,
comment|/* 0x00000000	  8 */
literal|0x3e
block|,
comment|/* 0x00111110	  8 */
literal|0x41
block|,
comment|/* 0x01000001	  8 */
literal|0x41
block|,
comment|/* 0x01000001	  8 */
literal|0x41
block|,
comment|/* 0x01000001	  8 */
literal|0x3e
block|,
comment|/* 0x00111110	  8 */
literal|0x41
block|,
comment|/* 0x01000001	  8 */
literal|0x41
block|,
comment|/* 0x01000001	  8 */
literal|0x41
block|,
comment|/* 0x01000001	  8 */
literal|0x41
block|,
comment|/* 0x01000001	  8 */
literal|0x3e
block|,
comment|/* 0x00111110	  8 */
literal|0x00
block|,
comment|/* 0x00000000	  8 */
literal|0x00
block|,
comment|/* 0x00000000	  8 */
literal|0x00
block|,
comment|/* 0x00000000	  8 */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  9 */
literal|0x00
block|,
comment|/* 0x00000000	  9 */
literal|0x3e
block|,
comment|/* 0x00111110	  9 */
literal|0x41
block|,
comment|/* 0x01000001	  9 */
literal|0x41
block|,
comment|/* 0x01000001	  9 */
literal|0x41
block|,
comment|/* 0x01000001	  9 */
literal|0x61
block|,
comment|/* 0x01100001	  9 */
literal|0x5e
block|,
comment|/* 0x01011110	  9 */
literal|0x40
block|,
comment|/* 0x01000000	  9 */
literal|0x40
block|,
comment|/* 0x01000000	  9 */
literal|0x20
block|,
comment|/* 0x00100000	  9 */
literal|0x1e
block|,
comment|/* 0x00011110	  9 */
literal|0x00
block|,
comment|/* 0x00000000	  9 */
literal|0x00
block|,
comment|/* 0x00000000	  9 */
literal|0x00
block|,
comment|/* 0x00000000	  9 */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  : */
literal|0x00
block|,
comment|/* 0x00000000	  : */
literal|0x00
block|,
comment|/* 0x00000000	  : */
literal|0x00
block|,
comment|/* 0x00000000	  : */
literal|0x00
block|,
comment|/* 0x00000000	  : */
literal|0x08
block|,
comment|/* 0x00001000	  : */
literal|0x1c
block|,
comment|/* 0x00011100	  : */
literal|0x08
block|,
comment|/* 0x00001000	  : */
literal|0x00
block|,
comment|/* 0x00000000	  : */
literal|0x00
block|,
comment|/* 0x00000000	  : */
literal|0x08
block|,
comment|/* 0x00001000	  : */
literal|0x1c
block|,
comment|/* 0x00011100	  : */
literal|0x08
block|,
comment|/* 0x00001000	  : */
literal|0x00
block|,
comment|/* 0x00000000	  : */
literal|0x00
block|,
comment|/* 0x00000000	  : */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  /* */
literal|0x00
block|,
comment|/* 0x00000000	  /* */
literal|0x00
block|,
comment|/* 0x00000000	  /* */
literal|0x00
block|,
comment|/* 0x00000000	  /* */
literal|0x00
block|,
comment|/* 0x00000000	  /* */
literal|0x08
block|,
comment|/* 0x00001000	  /* */
literal|0x1c
block|,
comment|/* 0x00011100	  /* */
literal|0x08
block|,
comment|/* 0x00001000	  /* */
literal|0x00
block|,
comment|/* 0x00000000	  /* */
literal|0x00
block|,
comment|/* 0x00000000	  /* */
literal|0x1c
block|,
comment|/* 0x00011100	  /* */
literal|0x0c
block|,
comment|/* 0x00001100	  /* */
literal|0x02
block|,
comment|/* 0x00000010	  /* */
literal|0x00
block|,
comment|/* 0x00000000	  /* */
literal|0x00
block|,
comment|/* 0x00000000	  /* */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000< */
literal|0x00
block|,
comment|/* 0x00000000< */
literal|0x20
block|,
comment|/* 0x00100000< */
literal|0x10
block|,
comment|/* 0x00010000< */
literal|0x08
block|,
comment|/* 0x00001000< */
literal|0x04
block|,
comment|/* 0x00000100< */
literal|0x02
block|,
comment|/* 0x00000010< */
literal|0x02
block|,
comment|/* 0x00000010< */
literal|0x04
block|,
comment|/* 0x00000100< */
literal|0x08
block|,
comment|/* 0x00001000< */
literal|0x10
block|,
comment|/* 0x00010000< */
literal|0x20
block|,
comment|/* 0x00100000< */
literal|0x00
block|,
comment|/* 0x00000000< */
literal|0x00
block|,
comment|/* 0x00000000< */
literal|0x00
block|,
comment|/* 0x00000000< */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  = */
literal|0x00
block|,
comment|/* 0x00000000	  = */
literal|0x00
block|,
comment|/* 0x00000000	  = */
literal|0x00
block|,
comment|/* 0x00000000	  = */
literal|0x00
block|,
comment|/* 0x00000000	  = */
literal|0x00
block|,
comment|/* 0x00000000	  = */
literal|0x7f
block|,
comment|/* 0x01111111	  = */
literal|0x00
block|,
comment|/* 0x00000000	  = */
literal|0x00
block|,
comment|/* 0x00000000	  = */
literal|0x7f
block|,
comment|/* 0x01111111	  = */
literal|0x00
block|,
comment|/* 0x00000000	  = */
literal|0x00
block|,
comment|/* 0x00000000	  = */
literal|0x00
block|,
comment|/* 0x00000000	  = */
literal|0x00
block|,
comment|/* 0x00000000	  = */
literal|0x00
block|,
comment|/* 0x00000000	  = */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000> */
literal|0x00
block|,
comment|/* 0x00000000> */
literal|0x02
block|,
comment|/* 0x00000010> */
literal|0x04
block|,
comment|/* 0x00000100> */
literal|0x08
block|,
comment|/* 0x00001000> */
literal|0x10
block|,
comment|/* 0x00010000> */
literal|0x20
block|,
comment|/* 0x00100000> */
literal|0x20
block|,
comment|/* 0x00100000> */
literal|0x10
block|,
comment|/* 0x00010000> */
literal|0x08
block|,
comment|/* 0x00001000> */
literal|0x04
block|,
comment|/* 0x00000100> */
literal|0x02
block|,
comment|/* 0x00000010> */
literal|0x00
block|,
comment|/* 0x00000000> */
literal|0x00
block|,
comment|/* 0x00000000> */
literal|0x00
block|,
comment|/* 0x00000000> */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  ? */
literal|0x00
block|,
comment|/* 0x00000000	  ? */
literal|0x3e
block|,
comment|/* 0x00111110	  ? */
literal|0x41
block|,
comment|/* 0x01000001	  ? */
literal|0x41
block|,
comment|/* 0x01000001	  ? */
literal|0x40
block|,
comment|/* 0x01000000	  ? */
literal|0x20
block|,
comment|/* 0x00100000	  ? */
literal|0x10
block|,
comment|/* 0x00010000	  ? */
literal|0x08
block|,
comment|/* 0x00001000	  ? */
literal|0x08
block|,
comment|/* 0x00001000	  ? */
literal|0x00
block|,
comment|/* 0x00000000	  ? */
literal|0x08
block|,
comment|/* 0x00001000	  ? */
literal|0x00
block|,
comment|/* 0x00000000	  ? */
literal|0x00
block|,
comment|/* 0x00000000	  ? */
literal|0x00
block|,
comment|/* 0x00000000	  ? */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  @ */
literal|0x00
block|,
comment|/* 0x00000000	  @ */
literal|0x3e
block|,
comment|/* 0x00111110	  @ */
literal|0x41
block|,
comment|/* 0x01000001	  @ */
literal|0x41
block|,
comment|/* 0x01000001	  @ */
literal|0x79
block|,
comment|/* 0x01111001	  @ */
literal|0x45
block|,
comment|/* 0x01000101	  @ */
literal|0x65
block|,
comment|/* 0x01100101	  @ */
literal|0x59
block|,
comment|/* 0x01011001	  @ */
literal|0x01
block|,
comment|/* 0x00000001	  @ */
literal|0x01
block|,
comment|/* 0x00000001	  @ */
literal|0x3e
block|,
comment|/* 0x00111110	  @ */
literal|0x00
block|,
comment|/* 0x00000000	  @ */
literal|0x00
block|,
comment|/* 0x00000000	  @ */
literal|0x00
block|,
comment|/* 0x00000000	  @ */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  A */
literal|0x00
block|,
comment|/* 0x00000000	  A */
literal|0x08
block|,
comment|/* 0x00001000	  A */
literal|0x14
block|,
comment|/* 0x00010100	  A */
literal|0x22
block|,
comment|/* 0x00100010	  A */
literal|0x41
block|,
comment|/* 0x01000001	  A */
literal|0x41
block|,
comment|/* 0x01000001	  A */
literal|0x41
block|,
comment|/* 0x01000001	  A */
literal|0x7f
block|,
comment|/* 0x01111111	  A */
literal|0x41
block|,
comment|/* 0x01000001	  A */
literal|0x41
block|,
comment|/* 0x01000001	  A */
literal|0x41
block|,
comment|/* 0x01000001	  A */
literal|0x00
block|,
comment|/* 0x00000000	  A */
literal|0x00
block|,
comment|/* 0x00000000	  A */
literal|0x00
block|,
comment|/* 0x00000000	  A */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  B */
literal|0x00
block|,
comment|/* 0x00000000	  B */
literal|0x3f
block|,
comment|/* 0x00111111	  B */
literal|0x42
block|,
comment|/* 0x01000010	  B */
literal|0x42
block|,
comment|/* 0x01000010	  B */
literal|0x42
block|,
comment|/* 0x01000010	  B */
literal|0x3e
block|,
comment|/* 0x00111110	  B */
literal|0x42
block|,
comment|/* 0x01000010	  B */
literal|0x42
block|,
comment|/* 0x01000010	  B */
literal|0x42
block|,
comment|/* 0x01000010	  B */
literal|0x42
block|,
comment|/* 0x01000010	  B */
literal|0x3f
block|,
comment|/* 0x00111111	  B */
literal|0x00
block|,
comment|/* 0x00000000	  B */
literal|0x00
block|,
comment|/* 0x00000000	  B */
literal|0x00
block|,
comment|/* 0x00000000	  B */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  C */
literal|0x00
block|,
comment|/* 0x00000000	  C */
literal|0x3e
block|,
comment|/* 0x00111110	  C */
literal|0x41
block|,
comment|/* 0x01000001	  C */
literal|0x01
block|,
comment|/* 0x00000001	  C */
literal|0x01
block|,
comment|/* 0x00000001	  C */
literal|0x01
block|,
comment|/* 0x00000001	  C */
literal|0x01
block|,
comment|/* 0x00000001	  C */
literal|0x01
block|,
comment|/* 0x00000001	  C */
literal|0x01
block|,
comment|/* 0x00000001	  C */
literal|0x41
block|,
comment|/* 0x01000001	  C */
literal|0x3e
block|,
comment|/* 0x00111110	  C */
literal|0x00
block|,
comment|/* 0x00000000	  C */
literal|0x00
block|,
comment|/* 0x00000000	  C */
literal|0x00
block|,
comment|/* 0x00000000	  C */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  D */
literal|0x00
block|,
comment|/* 0x00000000	  D */
literal|0x3f
block|,
comment|/* 0x00111111	  D */
literal|0x42
block|,
comment|/* 0x01000010	  D */
literal|0x42
block|,
comment|/* 0x01000010	  D */
literal|0x42
block|,
comment|/* 0x01000010	  D */
literal|0x42
block|,
comment|/* 0x01000010	  D */
literal|0x42
block|,
comment|/* 0x01000010	  D */
literal|0x42
block|,
comment|/* 0x01000010	  D */
literal|0x42
block|,
comment|/* 0x01000010	  D */
literal|0x42
block|,
comment|/* 0x01000010	  D */
literal|0x3f
block|,
comment|/* 0x00111111	  D */
literal|0x00
block|,
comment|/* 0x00000000	  D */
literal|0x00
block|,
comment|/* 0x00000000	  D */
literal|0x00
block|,
comment|/* 0x00000000	  D */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  E */
literal|0x00
block|,
comment|/* 0x00000000	  E */
literal|0x7e
block|,
comment|/* 0x01111110	  E */
literal|0x02
block|,
comment|/* 0x00000010	  E */
literal|0x02
block|,
comment|/* 0x00000010	  E */
literal|0x02
block|,
comment|/* 0x00000010	  E */
literal|0x1e
block|,
comment|/* 0x00011110	  E */
literal|0x02
block|,
comment|/* 0x00000010	  E */
literal|0x02
block|,
comment|/* 0x00000010	  E */
literal|0x02
block|,
comment|/* 0x00000010	  E */
literal|0x02
block|,
comment|/* 0x00000010	  E */
literal|0x7e
block|,
comment|/* 0x01111110	  E */
literal|0x00
block|,
comment|/* 0x00000000	  E */
literal|0x00
block|,
comment|/* 0x00000000	  E */
literal|0x00
block|,
comment|/* 0x00000000	  E */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  F */
literal|0x00
block|,
comment|/* 0x00000000	  F */
literal|0x7e
block|,
comment|/* 0x01111110	  F */
literal|0x02
block|,
comment|/* 0x00000010	  F */
literal|0x02
block|,
comment|/* 0x00000010	  F */
literal|0x02
block|,
comment|/* 0x00000010	  F */
literal|0x1e
block|,
comment|/* 0x00011110	  F */
literal|0x02
block|,
comment|/* 0x00000010	  F */
literal|0x02
block|,
comment|/* 0x00000010	  F */
literal|0x02
block|,
comment|/* 0x00000010	  F */
literal|0x02
block|,
comment|/* 0x00000010	  F */
literal|0x02
block|,
comment|/* 0x00000010	  F */
literal|0x00
block|,
comment|/* 0x00000000	  F */
literal|0x00
block|,
comment|/* 0x00000000	  F */
literal|0x00
block|,
comment|/* 0x00000000	  F */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  G */
literal|0x00
block|,
comment|/* 0x00000000	  G */
literal|0x3e
block|,
comment|/* 0x00111110	  G */
literal|0x41
block|,
comment|/* 0x01000001	  G */
literal|0x01
block|,
comment|/* 0x00000001	  G */
literal|0x01
block|,
comment|/* 0x00000001	  G */
literal|0x01
block|,
comment|/* 0x00000001	  G */
literal|0x71
block|,
comment|/* 0x01110001	  G */
literal|0x41
block|,
comment|/* 0x01000001	  G */
literal|0x41
block|,
comment|/* 0x01000001	  G */
literal|0x41
block|,
comment|/* 0x01000001	  G */
literal|0x3e
block|,
comment|/* 0x00111110	  G */
literal|0x00
block|,
comment|/* 0x00000000	  G */
literal|0x00
block|,
comment|/* 0x00000000	  G */
literal|0x00
block|,
comment|/* 0x00000000	  G */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  H */
literal|0x00
block|,
comment|/* 0x00000000	  H */
literal|0x41
block|,
comment|/* 0x01000001	  H */
literal|0x41
block|,
comment|/* 0x01000001	  H */
literal|0x41
block|,
comment|/* 0x01000001	  H */
literal|0x41
block|,
comment|/* 0x01000001	  H */
literal|0x7f
block|,
comment|/* 0x01111111	  H */
literal|0x41
block|,
comment|/* 0x01000001	  H */
literal|0x41
block|,
comment|/* 0x01000001	  H */
literal|0x41
block|,
comment|/* 0x01000001	  H */
literal|0x41
block|,
comment|/* 0x01000001	  H */
literal|0x41
block|,
comment|/* 0x01000001	  H */
literal|0x00
block|,
comment|/* 0x00000000	  H */
literal|0x00
block|,
comment|/* 0x00000000	  H */
literal|0x00
block|,
comment|/* 0x00000000	  H */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  I */
literal|0x00
block|,
comment|/* 0x00000000	  I */
literal|0x3e
block|,
comment|/* 0x00111110	  I */
literal|0x08
block|,
comment|/* 0x00001000	  I */
literal|0x08
block|,
comment|/* 0x00001000	  I */
literal|0x08
block|,
comment|/* 0x00001000	  I */
literal|0x08
block|,
comment|/* 0x00001000	  I */
literal|0x08
block|,
comment|/* 0x00001000	  I */
literal|0x08
block|,
comment|/* 0x00001000	  I */
literal|0x08
block|,
comment|/* 0x00001000	  I */
literal|0x08
block|,
comment|/* 0x00001000	  I */
literal|0x3e
block|,
comment|/* 0x00111110	  I */
literal|0x00
block|,
comment|/* 0x00000000	  I */
literal|0x00
block|,
comment|/* 0x00000000	  I */
literal|0x00
block|,
comment|/* 0x00000000	  I */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  J */
literal|0x00
block|,
comment|/* 0x00000000	  J */
literal|0x78
block|,
comment|/* 0x01111000	  J */
literal|0x20
block|,
comment|/* 0x00100000	  J */
literal|0x20
block|,
comment|/* 0x00100000	  J */
literal|0x20
block|,
comment|/* 0x00100000	  J */
literal|0x20
block|,
comment|/* 0x00100000	  J */
literal|0x20
block|,
comment|/* 0x00100000	  J */
literal|0x20
block|,
comment|/* 0x00100000	  J */
literal|0x20
block|,
comment|/* 0x00100000	  J */
literal|0x21
block|,
comment|/* 0x00100001	  J */
literal|0x1e
block|,
comment|/* 0x00011110	  J */
literal|0x00
block|,
comment|/* 0x00000000	  J */
literal|0x00
block|,
comment|/* 0x00000000	  J */
literal|0x00
block|,
comment|/* 0x00000000	  J */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  K */
literal|0x00
block|,
comment|/* 0x00000000	  K */
literal|0x41
block|,
comment|/* 0x01000001	  K */
literal|0x21
block|,
comment|/* 0x00100001	  K */
literal|0x11
block|,
comment|/* 0x00010001	  K */
literal|0x09
block|,
comment|/* 0x00001001	  K */
literal|0x07
block|,
comment|/* 0x00000111	  K */
literal|0x05
block|,
comment|/* 0x00000101	  K */
literal|0x09
block|,
comment|/* 0x00001001	  K */
literal|0x11
block|,
comment|/* 0x00010001	  K */
literal|0x21
block|,
comment|/* 0x00100001	  K */
literal|0x41
block|,
comment|/* 0x01000001	  K */
literal|0x00
block|,
comment|/* 0x00000000	  K */
literal|0x00
block|,
comment|/* 0x00000000	  K */
literal|0x00
block|,
comment|/* 0x00000000	  K */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  L */
literal|0x00
block|,
comment|/* 0x00000000	  L */
literal|0x01
block|,
comment|/* 0x00000001	  L */
literal|0x01
block|,
comment|/* 0x00000001	  L */
literal|0x01
block|,
comment|/* 0x00000001	  L */
literal|0x01
block|,
comment|/* 0x00000001	  L */
literal|0x01
block|,
comment|/* 0x00000001	  L */
literal|0x01
block|,
comment|/* 0x00000001	  L */
literal|0x01
block|,
comment|/* 0x00000001	  L */
literal|0x01
block|,
comment|/* 0x00000001	  L */
literal|0x01
block|,
comment|/* 0x00000001	  L */
literal|0x7f
block|,
comment|/* 0x01111111	  L */
literal|0x00
block|,
comment|/* 0x00000000	  L */
literal|0x00
block|,
comment|/* 0x00000000	  L */
literal|0x00
block|,
comment|/* 0x00000000	  L */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  M */
literal|0x00
block|,
comment|/* 0x00000000	  M */
literal|0x41
block|,
comment|/* 0x01000001	  M */
literal|0x41
block|,
comment|/* 0x01000001	  M */
literal|0x63
block|,
comment|/* 0x01100011	  M */
literal|0x55
block|,
comment|/* 0x01010101	  M */
literal|0x55
block|,
comment|/* 0x01010101	  M */
literal|0x49
block|,
comment|/* 0x01001001	  M */
literal|0x49
block|,
comment|/* 0x01001001	  M */
literal|0x41
block|,
comment|/* 0x01000001	  M */
literal|0x41
block|,
comment|/* 0x01000001	  M */
literal|0x41
block|,
comment|/* 0x01000001	  M */
literal|0x00
block|,
comment|/* 0x00000000	  M */
literal|0x00
block|,
comment|/* 0x00000000	  M */
literal|0x00
block|,
comment|/* 0x00000000	  M */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  N */
literal|0x00
block|,
comment|/* 0x00000000	  N */
literal|0x41
block|,
comment|/* 0x01000001	  N */
literal|0x41
block|,
comment|/* 0x01000001	  N */
literal|0x43
block|,
comment|/* 0x01000011	  N */
literal|0x45
block|,
comment|/* 0x01000101	  N */
literal|0x49
block|,
comment|/* 0x01001001	  N */
literal|0x51
block|,
comment|/* 0x01010001	  N */
literal|0x61
block|,
comment|/* 0x01100001	  N */
literal|0x41
block|,
comment|/* 0x01000001	  N */
literal|0x41
block|,
comment|/* 0x01000001	  N */
literal|0x41
block|,
comment|/* 0x01000001	  N */
literal|0x00
block|,
comment|/* 0x00000000	  N */
literal|0x00
block|,
comment|/* 0x00000000	  N */
literal|0x00
block|,
comment|/* 0x00000000	  N */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  O */
literal|0x00
block|,
comment|/* 0x00000000	  O */
literal|0x3e
block|,
comment|/* 0x00111110	  O */
literal|0x41
block|,
comment|/* 0x01000001	  O */
literal|0x41
block|,
comment|/* 0x01000001	  O */
literal|0x41
block|,
comment|/* 0x01000001	  O */
literal|0x41
block|,
comment|/* 0x01000001	  O */
literal|0x41
block|,
comment|/* 0x01000001	  O */
literal|0x41
block|,
comment|/* 0x01000001	  O */
literal|0x41
block|,
comment|/* 0x01000001	  O */
literal|0x41
block|,
comment|/* 0x01000001	  O */
literal|0x3e
block|,
comment|/* 0x00111110	  O */
literal|0x00
block|,
comment|/* 0x00000000	  O */
literal|0x00
block|,
comment|/* 0x00000000	  O */
literal|0x00
block|,
comment|/* 0x00000000	  O */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  P */
literal|0x00
block|,
comment|/* 0x00000000	  P */
literal|0x3f
block|,
comment|/* 0x00111111	  P */
literal|0x41
block|,
comment|/* 0x01000001	  P */
literal|0x41
block|,
comment|/* 0x01000001	  P */
literal|0x41
block|,
comment|/* 0x01000001	  P */
literal|0x3f
block|,
comment|/* 0x00111111	  P */
literal|0x01
block|,
comment|/* 0x00000001	  P */
literal|0x01
block|,
comment|/* 0x00000001	  P */
literal|0x01
block|,
comment|/* 0x00000001	  P */
literal|0x01
block|,
comment|/* 0x00000001	  P */
literal|0x01
block|,
comment|/* 0x00000001	  P */
literal|0x00
block|,
comment|/* 0x00000000	  P */
literal|0x00
block|,
comment|/* 0x00000000	  P */
literal|0x00
block|,
comment|/* 0x00000000	  P */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  Q */
literal|0x00
block|,
comment|/* 0x00000000	  Q */
literal|0x3e
block|,
comment|/* 0x00111110	  Q */
literal|0x41
block|,
comment|/* 0x01000001	  Q */
literal|0x41
block|,
comment|/* 0x01000001	  Q */
literal|0x41
block|,
comment|/* 0x01000001	  Q */
literal|0x41
block|,
comment|/* 0x01000001	  Q */
literal|0x41
block|,
comment|/* 0x01000001	  Q */
literal|0x41
block|,
comment|/* 0x01000001	  Q */
literal|0x49
block|,
comment|/* 0x01001001	  Q */
literal|0x51
block|,
comment|/* 0x01010001	  Q */
literal|0x3e
block|,
comment|/* 0x00111110	  Q */
literal|0x40
block|,
comment|/* 0x01000000	  Q */
literal|0x00
block|,
comment|/* 0x00000000	  Q */
literal|0x00
block|,
comment|/* 0x00000000	  Q */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  R */
literal|0x00
block|,
comment|/* 0x00000000	  R */
literal|0x3f
block|,
comment|/* 0x00111111	  R */
literal|0x41
block|,
comment|/* 0x01000001	  R */
literal|0x41
block|,
comment|/* 0x01000001	  R */
literal|0x41
block|,
comment|/* 0x01000001	  R */
literal|0x3f
block|,
comment|/* 0x00111111	  R */
literal|0x09
block|,
comment|/* 0x00001001	  R */
literal|0x11
block|,
comment|/* 0x00010001	  R */
literal|0x21
block|,
comment|/* 0x00100001	  R */
literal|0x41
block|,
comment|/* 0x01000001	  R */
literal|0x41
block|,
comment|/* 0x01000001	  R */
literal|0x00
block|,
comment|/* 0x00000000	  R */
literal|0x00
block|,
comment|/* 0x00000000	  R */
literal|0x00
block|,
comment|/* 0x00000000	  R */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  S */
literal|0x00
block|,
comment|/* 0x00000000	  S */
literal|0x3e
block|,
comment|/* 0x00111110	  S */
literal|0x41
block|,
comment|/* 0x01000001	  S */
literal|0x01
block|,
comment|/* 0x00000001	  S */
literal|0x01
block|,
comment|/* 0x00000001	  S */
literal|0x3e
block|,
comment|/* 0x00111110	  S */
literal|0x40
block|,
comment|/* 0x01000000	  S */
literal|0x40
block|,
comment|/* 0x01000000	  S */
literal|0x40
block|,
comment|/* 0x01000000	  S */
literal|0x41
block|,
comment|/* 0x01000001	  S */
literal|0x3e
block|,
comment|/* 0x00111110	  S */
literal|0x00
block|,
comment|/* 0x00000000	  S */
literal|0x00
block|,
comment|/* 0x00000000	  S */
literal|0x00
block|,
comment|/* 0x00000000	  S */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  T */
literal|0x00
block|,
comment|/* 0x00000000	  T */
literal|0x7f
block|,
comment|/* 0x01111111	  T */
literal|0x08
block|,
comment|/* 0x00001000	  T */
literal|0x08
block|,
comment|/* 0x00001000	  T */
literal|0x08
block|,
comment|/* 0x00001000	  T */
literal|0x08
block|,
comment|/* 0x00001000	  T */
literal|0x08
block|,
comment|/* 0x00001000	  T */
literal|0x08
block|,
comment|/* 0x00001000	  T */
literal|0x08
block|,
comment|/* 0x00001000	  T */
literal|0x08
block|,
comment|/* 0x00001000	  T */
literal|0x08
block|,
comment|/* 0x00001000	  T */
literal|0x00
block|,
comment|/* 0x00000000	  T */
literal|0x00
block|,
comment|/* 0x00000000	  T */
literal|0x00
block|,
comment|/* 0x00000000	  T */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  U */
literal|0x00
block|,
comment|/* 0x00000000	  U */
literal|0x41
block|,
comment|/* 0x01000001	  U */
literal|0x41
block|,
comment|/* 0x01000001	  U */
literal|0x41
block|,
comment|/* 0x01000001	  U */
literal|0x41
block|,
comment|/* 0x01000001	  U */
literal|0x41
block|,
comment|/* 0x01000001	  U */
literal|0x41
block|,
comment|/* 0x01000001	  U */
literal|0x41
block|,
comment|/* 0x01000001	  U */
literal|0x41
block|,
comment|/* 0x01000001	  U */
literal|0x41
block|,
comment|/* 0x01000001	  U */
literal|0x3e
block|,
comment|/* 0x00111110	  U */
literal|0x00
block|,
comment|/* 0x00000000	  U */
literal|0x00
block|,
comment|/* 0x00000000	  U */
literal|0x00
block|,
comment|/* 0x00000000	  U */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  V */
literal|0x00
block|,
comment|/* 0x00000000	  V */
literal|0x41
block|,
comment|/* 0x01000001	  V */
literal|0x41
block|,
comment|/* 0x01000001	  V */
literal|0x41
block|,
comment|/* 0x01000001	  V */
literal|0x22
block|,
comment|/* 0x00100010	  V */
literal|0x22
block|,
comment|/* 0x00100010	  V */
literal|0x22
block|,
comment|/* 0x00100010	  V */
literal|0x14
block|,
comment|/* 0x00010100	  V */
literal|0x14
block|,
comment|/* 0x00010100	  V */
literal|0x14
block|,
comment|/* 0x00010100	  V */
literal|0x08
block|,
comment|/* 0x00001000	  V */
literal|0x00
block|,
comment|/* 0x00000000	  V */
literal|0x00
block|,
comment|/* 0x00000000	  V */
literal|0x00
block|,
comment|/* 0x00000000	  V */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  W */
literal|0x00
block|,
comment|/* 0x00000000	  W */
literal|0x41
block|,
comment|/* 0x01000001	  W */
literal|0x41
block|,
comment|/* 0x01000001	  W */
literal|0x41
block|,
comment|/* 0x01000001	  W */
literal|0x41
block|,
comment|/* 0x01000001	  W */
literal|0x49
block|,
comment|/* 0x01001001	  W */
literal|0x49
block|,
comment|/* 0x01001001	  W */
literal|0x49
block|,
comment|/* 0x01001001	  W */
literal|0x49
block|,
comment|/* 0x01001001	  W */
literal|0x55
block|,
comment|/* 0x01010101	  W */
literal|0x22
block|,
comment|/* 0x00100010	  W */
literal|0x00
block|,
comment|/* 0x00000000	  W */
literal|0x00
block|,
comment|/* 0x00000000	  W */
literal|0x00
block|,
comment|/* 0x00000000	  W */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  X */
literal|0x00
block|,
comment|/* 0x00000000	  X */
literal|0x41
block|,
comment|/* 0x01000001	  X */
literal|0x41
block|,
comment|/* 0x01000001	  X */
literal|0x22
block|,
comment|/* 0x00100010	  X */
literal|0x14
block|,
comment|/* 0x00010100	  X */
literal|0x08
block|,
comment|/* 0x00001000	  X */
literal|0x08
block|,
comment|/* 0x00001000	  X */
literal|0x14
block|,
comment|/* 0x00010100	  X */
literal|0x22
block|,
comment|/* 0x00100010	  X */
literal|0x41
block|,
comment|/* 0x01000001	  X */
literal|0x41
block|,
comment|/* 0x01000001	  X */
literal|0x00
block|,
comment|/* 0x00000000	  X */
literal|0x00
block|,
comment|/* 0x00000000	  X */
literal|0x00
block|,
comment|/* 0x00000000	  X */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  Y */
literal|0x00
block|,
comment|/* 0x00000000	  Y */
literal|0x41
block|,
comment|/* 0x01000001	  Y */
literal|0x41
block|,
comment|/* 0x01000001	  Y */
literal|0x22
block|,
comment|/* 0x00100010	  Y */
literal|0x14
block|,
comment|/* 0x00010100	  Y */
literal|0x08
block|,
comment|/* 0x00001000	  Y */
literal|0x08
block|,
comment|/* 0x00001000	  Y */
literal|0x08
block|,
comment|/* 0x00001000	  Y */
literal|0x08
block|,
comment|/* 0x00001000	  Y */
literal|0x08
block|,
comment|/* 0x00001000	  Y */
literal|0x08
block|,
comment|/* 0x00001000	  Y */
literal|0x00
block|,
comment|/* 0x00000000	  Y */
literal|0x00
block|,
comment|/* 0x00000000	  Y */
literal|0x00
block|,
comment|/* 0x00000000	  Y */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  Z */
literal|0x00
block|,
comment|/* 0x00000000	  Z */
literal|0x7f
block|,
comment|/* 0x01111111	  Z */
literal|0x40
block|,
comment|/* 0x01000000	  Z */
literal|0x20
block|,
comment|/* 0x00100000	  Z */
literal|0x10
block|,
comment|/* 0x00010000	  Z */
literal|0x08
block|,
comment|/* 0x00001000	  Z */
literal|0x04
block|,
comment|/* 0x00000100	  Z */
literal|0x02
block|,
comment|/* 0x00000010	  Z */
literal|0x01
block|,
comment|/* 0x00000001	  Z */
literal|0x01
block|,
comment|/* 0x00000001	  Z */
literal|0x7f
block|,
comment|/* 0x01111111	  Z */
literal|0x00
block|,
comment|/* 0x00000000	  Z */
literal|0x00
block|,
comment|/* 0x00000000	  Z */
literal|0x00
block|,
comment|/* 0x00000000	  Z */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  [ */
literal|0x00
block|,
comment|/* 0x00000000	  [ */
literal|0x3c
block|,
comment|/* 0x00111100	  [ */
literal|0x04
block|,
comment|/* 0x00000100	  [ */
literal|0x04
block|,
comment|/* 0x00000100	  [ */
literal|0x04
block|,
comment|/* 0x00000100	  [ */
literal|0x04
block|,
comment|/* 0x00000100	  [ */
literal|0x04
block|,
comment|/* 0x00000100	  [ */
literal|0x04
block|,
comment|/* 0x00000100	  [ */
literal|0x04
block|,
comment|/* 0x00000100	  [ */
literal|0x04
block|,
comment|/* 0x00000100	  [ */
literal|0x3c
block|,
comment|/* 0x00111100	  [ */
literal|0x00
block|,
comment|/* 0x00000000	  [ */
literal|0x00
block|,
comment|/* 0x00000000	  [ */
literal|0x00
block|,
comment|/* 0x00000000	  [ */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  \ */
literal|0x00
block|,
comment|/* 0x00000000	  \ */
literal|0x01
block|,
comment|/* 0x00000001	  \ */
literal|0x02
block|,
comment|/* 0x00000010	  \ */
literal|0x02
block|,
comment|/* 0x00000010	  \ */
literal|0x04
block|,
comment|/* 0x00000100	  \ */
literal|0x08
block|,
comment|/* 0x00001000	  \ */
literal|0x08
block|,
comment|/* 0x00001000	  \ */
literal|0x10
block|,
comment|/* 0x00010000	  \ */
literal|0x20
block|,
comment|/* 0x00100000	  \ */
literal|0x20
block|,
comment|/* 0x00100000	  \ */
literal|0x40
block|,
comment|/* 0x01000000	  \ */
literal|0x00
block|,
comment|/* 0x00000000	  \ */
literal|0x00
block|,
comment|/* 0x00000000	  \ */
literal|0x00
block|,
comment|/* 0x00000000	  \ */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  ] */
literal|0x00
block|,
comment|/* 0x00000000	  ] */
literal|0x1e
block|,
comment|/* 0x00011110	  ] */
literal|0x10
block|,
comment|/* 0x00010000	  ] */
literal|0x10
block|,
comment|/* 0x00010000	  ] */
literal|0x10
block|,
comment|/* 0x00010000	  ] */
literal|0x10
block|,
comment|/* 0x00010000	  ] */
literal|0x10
block|,
comment|/* 0x00010000	  ] */
literal|0x10
block|,
comment|/* 0x00010000	  ] */
literal|0x10
block|,
comment|/* 0x00010000	  ] */
literal|0x10
block|,
comment|/* 0x00010000	  ] */
literal|0x1e
block|,
comment|/* 0x00011110	  ] */
literal|0x00
block|,
comment|/* 0x00000000	  ] */
literal|0x00
block|,
comment|/* 0x00000000	  ] */
literal|0x00
block|,
comment|/* 0x00000000	  ] */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  ^ */
literal|0x00
block|,
comment|/* 0x00000000	  ^ */
literal|0x08
block|,
comment|/* 0x00001000	  ^ */
literal|0x14
block|,
comment|/* 0x00010100	  ^ */
literal|0x22
block|,
comment|/* 0x00100010	  ^ */
literal|0x41
block|,
comment|/* 0x01000001	  ^ */
literal|0x00
block|,
comment|/* 0x00000000	  ^ */
literal|0x00
block|,
comment|/* 0x00000000	  ^ */
literal|0x00
block|,
comment|/* 0x00000000	  ^ */
literal|0x00
block|,
comment|/* 0x00000000	  ^ */
literal|0x00
block|,
comment|/* 0x00000000	  ^ */
literal|0x00
block|,
comment|/* 0x00000000	  ^ */
literal|0x00
block|,
comment|/* 0x00000000	  ^ */
literal|0x00
block|,
comment|/* 0x00000000	  ^ */
literal|0x00
block|,
comment|/* 0x00000000	  ^ */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x7f
block|,
comment|/* 0x01111111	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
literal|0x00
block|,
comment|/* 0x00000000	  _ */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  ` */
literal|0x00
block|,
comment|/* 0x00000000	  ` */
literal|0x0e
block|,
comment|/* 0x00001110	  ` */
literal|0x0c
block|,
comment|/* 0x00001100	  ` */
literal|0x10
block|,
comment|/* 0x00010000	  ` */
literal|0x00
block|,
comment|/* 0x00000000	  ` */
literal|0x00
block|,
comment|/* 0x00000000	  ` */
literal|0x00
block|,
comment|/* 0x00000000	  ` */
literal|0x00
block|,
comment|/* 0x00000000	  ` */
literal|0x00
block|,
comment|/* 0x00000000	  ` */
literal|0x00
block|,
comment|/* 0x00000000	  ` */
literal|0x00
block|,
comment|/* 0x00000000	  ` */
literal|0x00
block|,
comment|/* 0x00000000	  ` */
literal|0x00
block|,
comment|/* 0x00000000	  ` */
literal|0x00
block|,
comment|/* 0x00000000	  ` */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  a */
literal|0x00
block|,
comment|/* 0x00000000	  a */
literal|0x00
block|,
comment|/* 0x00000000	  a */
literal|0x00
block|,
comment|/* 0x00000000	  a */
literal|0x00
block|,
comment|/* 0x00000000	  a */
literal|0x3e
block|,
comment|/* 0x00111110	  a */
literal|0x40
block|,
comment|/* 0x01000000	  a */
literal|0x40
block|,
comment|/* 0x01000000	  a */
literal|0x7e
block|,
comment|/* 0x01111110	  a */
literal|0x41
block|,
comment|/* 0x01000001	  a */
literal|0x61
block|,
comment|/* 0x01100001	  a */
literal|0x5e
block|,
comment|/* 0x01011110	  a */
literal|0x00
block|,
comment|/* 0x00000000	  a */
literal|0x00
block|,
comment|/* 0x00000000	  a */
literal|0x00
block|,
comment|/* 0x00000000	  a */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  b */
literal|0x00
block|,
comment|/* 0x00000000	  b */
literal|0x01
block|,
comment|/* 0x00000001	  b */
literal|0x01
block|,
comment|/* 0x00000001	  b */
literal|0x01
block|,
comment|/* 0x00000001	  b */
literal|0x3d
block|,
comment|/* 0x00111101	  b */
literal|0x43
block|,
comment|/* 0x01000011	  b */
literal|0x41
block|,
comment|/* 0x01000001	  b */
literal|0x41
block|,
comment|/* 0x01000001	  b */
literal|0x41
block|,
comment|/* 0x01000001	  b */
literal|0x43
block|,
comment|/* 0x01000011	  b */
literal|0x3d
block|,
comment|/* 0x00111101	  b */
literal|0x00
block|,
comment|/* 0x00000000	  b */
literal|0x00
block|,
comment|/* 0x00000000	  b */
literal|0x00
block|,
comment|/* 0x00000000	  b */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  c */
literal|0x00
block|,
comment|/* 0x00000000	  c */
literal|0x00
block|,
comment|/* 0x00000000	  c */
literal|0x00
block|,
comment|/* 0x00000000	  c */
literal|0x00
block|,
comment|/* 0x00000000	  c */
literal|0x3e
block|,
comment|/* 0x00111110	  c */
literal|0x41
block|,
comment|/* 0x01000001	  c */
literal|0x01
block|,
comment|/* 0x00000001	  c */
literal|0x01
block|,
comment|/* 0x00000001	  c */
literal|0x01
block|,
comment|/* 0x00000001	  c */
literal|0x41
block|,
comment|/* 0x01000001	  c */
literal|0x3e
block|,
comment|/* 0x00111110	  c */
literal|0x00
block|,
comment|/* 0x00000000	  c */
literal|0x00
block|,
comment|/* 0x00000000	  c */
literal|0x00
block|,
comment|/* 0x00000000	  c */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  d */
literal|0x00
block|,
comment|/* 0x00000000	  d */
literal|0x40
block|,
comment|/* 0x01000000	  d */
literal|0x40
block|,
comment|/* 0x01000000	  d */
literal|0x40
block|,
comment|/* 0x01000000	  d */
literal|0x5e
block|,
comment|/* 0x01011110	  d */
literal|0x61
block|,
comment|/* 0x01100001	  d */
literal|0x41
block|,
comment|/* 0x01000001	  d */
literal|0x41
block|,
comment|/* 0x01000001	  d */
literal|0x41
block|,
comment|/* 0x01000001	  d */
literal|0x61
block|,
comment|/* 0x01100001	  d */
literal|0x5e
block|,
comment|/* 0x01011110	  d */
literal|0x00
block|,
comment|/* 0x00000000	  d */
literal|0x00
block|,
comment|/* 0x00000000	  d */
literal|0x00
block|,
comment|/* 0x00000000	  d */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  e */
literal|0x00
block|,
comment|/* 0x00000000	  e */
literal|0x00
block|,
comment|/* 0x00000000	  e */
literal|0x00
block|,
comment|/* 0x00000000	  e */
literal|0x00
block|,
comment|/* 0x00000000	  e */
literal|0x3e
block|,
comment|/* 0x00111110	  e */
literal|0x41
block|,
comment|/* 0x01000001	  e */
literal|0x41
block|,
comment|/* 0x01000001	  e */
literal|0x7f
block|,
comment|/* 0x01111111	  e */
literal|0x01
block|,
comment|/* 0x00000001	  e */
literal|0x01
block|,
comment|/* 0x00000001	  e */
literal|0x3e
block|,
comment|/* 0x00111110	  e */
literal|0x00
block|,
comment|/* 0x00000000	  e */
literal|0x00
block|,
comment|/* 0x00000000	  e */
literal|0x00
block|,
comment|/* 0x00000000	  e */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  f */
literal|0x00
block|,
comment|/* 0x00000000	  f */
literal|0x38
block|,
comment|/* 0x00111000	  f */
literal|0x44
block|,
comment|/* 0x01000100	  f */
literal|0x44
block|,
comment|/* 0x01000100	  f */
literal|0x04
block|,
comment|/* 0x00000100	  f */
literal|0x04
block|,
comment|/* 0x00000100	  f */
literal|0x1f
block|,
comment|/* 0x00011111	  f */
literal|0x04
block|,
comment|/* 0x00000100	  f */
literal|0x04
block|,
comment|/* 0x00000100	  f */
literal|0x04
block|,
comment|/* 0x00000100	  f */
literal|0x04
block|,
comment|/* 0x00000100	  f */
literal|0x00
block|,
comment|/* 0x00000000	  f */
literal|0x00
block|,
comment|/* 0x00000000	  f */
literal|0x00
block|,
comment|/* 0x00000000	  f */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  g */
literal|0x00
block|,
comment|/* 0x00000000	  g */
literal|0x00
block|,
comment|/* 0x00000000	  g */
literal|0x00
block|,
comment|/* 0x00000000	  g */
literal|0x00
block|,
comment|/* 0x00000000	  g */
literal|0x5e
block|,
comment|/* 0x01011110	  g */
literal|0x21
block|,
comment|/* 0x00100001	  g */
literal|0x21
block|,
comment|/* 0x00100001	  g */
literal|0x21
block|,
comment|/* 0x00100001	  g */
literal|0x1e
block|,
comment|/* 0x00011110	  g */
literal|0x01
block|,
comment|/* 0x00000001	  g */
literal|0x3e
block|,
comment|/* 0x00111110	  g */
literal|0x41
block|,
comment|/* 0x01000001	  g */
literal|0x41
block|,
comment|/* 0x01000001	  g */
literal|0x3e
block|,
comment|/* 0x00111110	  g */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  h */
literal|0x00
block|,
comment|/* 0x00000000	  h */
literal|0x01
block|,
comment|/* 0x00000001	  h */
literal|0x01
block|,
comment|/* 0x00000001	  h */
literal|0x01
block|,
comment|/* 0x00000001	  h */
literal|0x3d
block|,
comment|/* 0x00111101	  h */
literal|0x43
block|,
comment|/* 0x01000011	  h */
literal|0x41
block|,
comment|/* 0x01000001	  h */
literal|0x41
block|,
comment|/* 0x01000001	  h */
literal|0x41
block|,
comment|/* 0x01000001	  h */
literal|0x41
block|,
comment|/* 0x01000001	  h */
literal|0x41
block|,
comment|/* 0x01000001	  h */
literal|0x00
block|,
comment|/* 0x00000000	  h */
literal|0x00
block|,
comment|/* 0x00000000	  h */
literal|0x00
block|,
comment|/* 0x00000000	  h */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  i */
literal|0x00
block|,
comment|/* 0x00000000	  i */
literal|0x00
block|,
comment|/* 0x00000000	  i */
literal|0x08
block|,
comment|/* 0x00001000	  i */
literal|0x00
block|,
comment|/* 0x00000000	  i */
literal|0x0c
block|,
comment|/* 0x00001100	  i */
literal|0x08
block|,
comment|/* 0x00001000	  i */
literal|0x08
block|,
comment|/* 0x00001000	  i */
literal|0x08
block|,
comment|/* 0x00001000	  i */
literal|0x08
block|,
comment|/* 0x00001000	  i */
literal|0x08
block|,
comment|/* 0x00001000	  i */
literal|0x3e
block|,
comment|/* 0x00111110	  i */
literal|0x00
block|,
comment|/* 0x00000000	  i */
literal|0x00
block|,
comment|/* 0x00000000	  i */
literal|0x00
block|,
comment|/* 0x00000000	  i */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  j */
literal|0x00
block|,
comment|/* 0x00000000	  j */
literal|0x00
block|,
comment|/* 0x00000000	  j */
literal|0x20
block|,
comment|/* 0x00100000	  j */
literal|0x00
block|,
comment|/* 0x00000000	  j */
literal|0x38
block|,
comment|/* 0x00111000	  j */
literal|0x20
block|,
comment|/* 0x00100000	  j */
literal|0x20
block|,
comment|/* 0x00100000	  j */
literal|0x20
block|,
comment|/* 0x00100000	  j */
literal|0x20
block|,
comment|/* 0x00100000	  j */
literal|0x20
block|,
comment|/* 0x00100000	  j */
literal|0x21
block|,
comment|/* 0x00100001	  j */
literal|0x21
block|,
comment|/* 0x00100001	  j */
literal|0x21
block|,
comment|/* 0x00100001	  j */
literal|0x1e
block|,
comment|/* 0x00011110	  j */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  k */
literal|0x00
block|,
comment|/* 0x00000000	  k */
literal|0x01
block|,
comment|/* 0x00000001	  k */
literal|0x01
block|,
comment|/* 0x00000001	  k */
literal|0x01
block|,
comment|/* 0x00000001	  k */
literal|0x41
block|,
comment|/* 0x01000001	  k */
literal|0x31
block|,
comment|/* 0x00110001	  k */
literal|0x0d
block|,
comment|/* 0x00001101	  k */
literal|0x03
block|,
comment|/* 0x00000011	  k */
literal|0x0d
block|,
comment|/* 0x00001101	  k */
literal|0x31
block|,
comment|/* 0x00110001	  k */
literal|0x41
block|,
comment|/* 0x01000001	  k */
literal|0x00
block|,
comment|/* 0x00000000	  k */
literal|0x00
block|,
comment|/* 0x00000000	  k */
literal|0x00
block|,
comment|/* 0x00000000	  k */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  l */
literal|0x00
block|,
comment|/* 0x00000000	  l */
literal|0x0c
block|,
comment|/* 0x00001100	  l */
literal|0x08
block|,
comment|/* 0x00001000	  l */
literal|0x08
block|,
comment|/* 0x00001000	  l */
literal|0x08
block|,
comment|/* 0x00001000	  l */
literal|0x08
block|,
comment|/* 0x00001000	  l */
literal|0x08
block|,
comment|/* 0x00001000	  l */
literal|0x08
block|,
comment|/* 0x00001000	  l */
literal|0x08
block|,
comment|/* 0x00001000	  l */
literal|0x08
block|,
comment|/* 0x00001000	  l */
literal|0x3e
block|,
comment|/* 0x00111110	  l */
literal|0x00
block|,
comment|/* 0x00000000	  l */
literal|0x00
block|,
comment|/* 0x00000000	  l */
literal|0x00
block|,
comment|/* 0x00000000	  l */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  m */
literal|0x00
block|,
comment|/* 0x00000000	  m */
literal|0x00
block|,
comment|/* 0x00000000	  m */
literal|0x00
block|,
comment|/* 0x00000000	  m */
literal|0x00
block|,
comment|/* 0x00000000	  m */
literal|0x37
block|,
comment|/* 0x00110111	  m */
literal|0x49
block|,
comment|/* 0x01001001	  m */
literal|0x49
block|,
comment|/* 0x01001001	  m */
literal|0x49
block|,
comment|/* 0x01001001	  m */
literal|0x49
block|,
comment|/* 0x01001001	  m */
literal|0x49
block|,
comment|/* 0x01001001	  m */
literal|0x41
block|,
comment|/* 0x01000001	  m */
literal|0x00
block|,
comment|/* 0x00000000	  m */
literal|0x00
block|,
comment|/* 0x00000000	  m */
literal|0x00
block|,
comment|/* 0x00000000	  m */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  n */
literal|0x00
block|,
comment|/* 0x00000000	  n */
literal|0x00
block|,
comment|/* 0x00000000	  n */
literal|0x00
block|,
comment|/* 0x00000000	  n */
literal|0x00
block|,
comment|/* 0x00000000	  n */
literal|0x3d
block|,
comment|/* 0x00111101	  n */
literal|0x43
block|,
comment|/* 0x01000011	  n */
literal|0x41
block|,
comment|/* 0x01000001	  n */
literal|0x41
block|,
comment|/* 0x01000001	  n */
literal|0x41
block|,
comment|/* 0x01000001	  n */
literal|0x41
block|,
comment|/* 0x01000001	  n */
literal|0x41
block|,
comment|/* 0x01000001	  n */
literal|0x00
block|,
comment|/* 0x00000000	  n */
literal|0x00
block|,
comment|/* 0x00000000	  n */
literal|0x00
block|,
comment|/* 0x00000000	  n */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  o */
literal|0x00
block|,
comment|/* 0x00000000	  o */
literal|0x00
block|,
comment|/* 0x00000000	  o */
literal|0x00
block|,
comment|/* 0x00000000	  o */
literal|0x00
block|,
comment|/* 0x00000000	  o */
literal|0x3e
block|,
comment|/* 0x00111110	  o */
literal|0x41
block|,
comment|/* 0x01000001	  o */
literal|0x41
block|,
comment|/* 0x01000001	  o */
literal|0x41
block|,
comment|/* 0x01000001	  o */
literal|0x41
block|,
comment|/* 0x01000001	  o */
literal|0x41
block|,
comment|/* 0x01000001	  o */
literal|0x3e
block|,
comment|/* 0x00111110	  o */
literal|0x00
block|,
comment|/* 0x00000000	  o */
literal|0x00
block|,
comment|/* 0x00000000	  o */
literal|0x00
block|,
comment|/* 0x00000000	  o */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  p */
literal|0x00
block|,
comment|/* 0x00000000	  p */
literal|0x00
block|,
comment|/* 0x00000000	  p */
literal|0x00
block|,
comment|/* 0x00000000	  p */
literal|0x00
block|,
comment|/* 0x00000000	  p */
literal|0x3d
block|,
comment|/* 0x00111101	  p */
literal|0x43
block|,
comment|/* 0x01000011	  p */
literal|0x41
block|,
comment|/* 0x01000001	  p */
literal|0x41
block|,
comment|/* 0x01000001	  p */
literal|0x41
block|,
comment|/* 0x01000001	  p */
literal|0x43
block|,
comment|/* 0x01000011	  p */
literal|0x3d
block|,
comment|/* 0x00111101	  p */
literal|0x01
block|,
comment|/* 0x00000001	  p */
literal|0x01
block|,
comment|/* 0x00000001	  p */
literal|0x01
block|,
comment|/* 0x00000001	  p */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  q */
literal|0x00
block|,
comment|/* 0x00000000	  q */
literal|0x00
block|,
comment|/* 0x00000000	  q */
literal|0x00
block|,
comment|/* 0x00000000	  q */
literal|0x00
block|,
comment|/* 0x00000000	  q */
literal|0x5e
block|,
comment|/* 0x01011110	  q */
literal|0x61
block|,
comment|/* 0x01100001	  q */
literal|0x41
block|,
comment|/* 0x01000001	  q */
literal|0x41
block|,
comment|/* 0x01000001	  q */
literal|0x41
block|,
comment|/* 0x01000001	  q */
literal|0x61
block|,
comment|/* 0x01100001	  q */
literal|0x5e
block|,
comment|/* 0x01011110	  q */
literal|0x40
block|,
comment|/* 0x01000000	  q */
literal|0x40
block|,
comment|/* 0x01000000	  q */
literal|0x40
block|,
comment|/* 0x01000000	  q */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  r */
literal|0x00
block|,
comment|/* 0x00000000	  r */
literal|0x00
block|,
comment|/* 0x00000000	  r */
literal|0x00
block|,
comment|/* 0x00000000	  r */
literal|0x00
block|,
comment|/* 0x00000000	  r */
literal|0x39
block|,
comment|/* 0x00111001	  r */
literal|0x46
block|,
comment|/* 0x01000110	  r */
literal|0x42
block|,
comment|/* 0x01000010	  r */
literal|0x02
block|,
comment|/* 0x00000010	  r */
literal|0x02
block|,
comment|/* 0x00000010	  r */
literal|0x02
block|,
comment|/* 0x00000010	  r */
literal|0x02
block|,
comment|/* 0x00000010	  r */
literal|0x00
block|,
comment|/* 0x00000000	  r */
literal|0x00
block|,
comment|/* 0x00000000	  r */
literal|0x00
block|,
comment|/* 0x00000000	  r */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  s */
literal|0x00
block|,
comment|/* 0x00000000	  s */
literal|0x00
block|,
comment|/* 0x00000000	  s */
literal|0x00
block|,
comment|/* 0x00000000	  s */
literal|0x00
block|,
comment|/* 0x00000000	  s */
literal|0x3e
block|,
comment|/* 0x00111110	  s */
literal|0x41
block|,
comment|/* 0x01000001	  s */
literal|0x01
block|,
comment|/* 0x00000001	  s */
literal|0x3e
block|,
comment|/* 0x00111110	  s */
literal|0x40
block|,
comment|/* 0x01000000	  s */
literal|0x41
block|,
comment|/* 0x01000001	  s */
literal|0x3e
block|,
comment|/* 0x00111110	  s */
literal|0x00
block|,
comment|/* 0x00000000	  s */
literal|0x00
block|,
comment|/* 0x00000000	  s */
literal|0x00
block|,
comment|/* 0x00000000	  s */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  t */
literal|0x00
block|,
comment|/* 0x00000000	  t */
literal|0x00
block|,
comment|/* 0x00000000	  t */
literal|0x04
block|,
comment|/* 0x00000100	  t */
literal|0x04
block|,
comment|/* 0x00000100	  t */
literal|0x3f
block|,
comment|/* 0x00111111	  t */
literal|0x04
block|,
comment|/* 0x00000100	  t */
literal|0x04
block|,
comment|/* 0x00000100	  t */
literal|0x04
block|,
comment|/* 0x00000100	  t */
literal|0x04
block|,
comment|/* 0x00000100	  t */
literal|0x44
block|,
comment|/* 0x01000100	  t */
literal|0x38
block|,
comment|/* 0x00111000	  t */
literal|0x00
block|,
comment|/* 0x00000000	  t */
literal|0x00
block|,
comment|/* 0x00000000	  t */
literal|0x00
block|,
comment|/* 0x00000000	  t */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  u */
literal|0x00
block|,
comment|/* 0x00000000	  u */
literal|0x00
block|,
comment|/* 0x00000000	  u */
literal|0x00
block|,
comment|/* 0x00000000	  u */
literal|0x00
block|,
comment|/* 0x00000000	  u */
literal|0x21
block|,
comment|/* 0x00100001	  u */
literal|0x21
block|,
comment|/* 0x00100001	  u */
literal|0x21
block|,
comment|/* 0x00100001	  u */
literal|0x21
block|,
comment|/* 0x00100001	  u */
literal|0x21
block|,
comment|/* 0x00100001	  u */
literal|0x21
block|,
comment|/* 0x00100001	  u */
literal|0x5e
block|,
comment|/* 0x01011110	  u */
literal|0x00
block|,
comment|/* 0x00000000	  u */
literal|0x00
block|,
comment|/* 0x00000000	  u */
literal|0x00
block|,
comment|/* 0x00000000	  u */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  v */
literal|0x00
block|,
comment|/* 0x00000000	  v */
literal|0x00
block|,
comment|/* 0x00000000	  v */
literal|0x00
block|,
comment|/* 0x00000000	  v */
literal|0x00
block|,
comment|/* 0x00000000	  v */
literal|0x41
block|,
comment|/* 0x01000001	  v */
literal|0x41
block|,
comment|/* 0x01000001	  v */
literal|0x22
block|,
comment|/* 0x00100010	  v */
literal|0x22
block|,
comment|/* 0x00100010	  v */
literal|0x14
block|,
comment|/* 0x00010100	  v */
literal|0x14
block|,
comment|/* 0x00010100	  v */
literal|0x08
block|,
comment|/* 0x00001000	  v */
literal|0x00
block|,
comment|/* 0x00000000	  v */
literal|0x00
block|,
comment|/* 0x00000000	  v */
literal|0x00
block|,
comment|/* 0x00000000	  v */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  w */
literal|0x00
block|,
comment|/* 0x00000000	  w */
literal|0x00
block|,
comment|/* 0x00000000	  w */
literal|0x00
block|,
comment|/* 0x00000000	  w */
literal|0x00
block|,
comment|/* 0x00000000	  w */
literal|0x41
block|,
comment|/* 0x01000001	  w */
literal|0x41
block|,
comment|/* 0x01000001	  w */
literal|0x49
block|,
comment|/* 0x01001001	  w */
literal|0x49
block|,
comment|/* 0x01001001	  w */
literal|0x49
block|,
comment|/* 0x01001001	  w */
literal|0x55
block|,
comment|/* 0x01010101	  w */
literal|0x22
block|,
comment|/* 0x00100010	  w */
literal|0x00
block|,
comment|/* 0x00000000	  w */
literal|0x00
block|,
comment|/* 0x00000000	  w */
literal|0x00
block|,
comment|/* 0x00000000	  w */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  x */
literal|0x00
block|,
comment|/* 0x00000000	  x */
literal|0x00
block|,
comment|/* 0x00000000	  x */
literal|0x00
block|,
comment|/* 0x00000000	  x */
literal|0x00
block|,
comment|/* 0x00000000	  x */
literal|0x41
block|,
comment|/* 0x01000001	  x */
literal|0x22
block|,
comment|/* 0x00100010	  x */
literal|0x14
block|,
comment|/* 0x00010100	  x */
literal|0x08
block|,
comment|/* 0x00001000	  x */
literal|0x14
block|,
comment|/* 0x00010100	  x */
literal|0x22
block|,
comment|/* 0x00100010	  x */
literal|0x41
block|,
comment|/* 0x01000001	  x */
literal|0x00
block|,
comment|/* 0x00000000	  x */
literal|0x00
block|,
comment|/* 0x00000000	  x */
literal|0x00
block|,
comment|/* 0x00000000	  x */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  y */
literal|0x00
block|,
comment|/* 0x00000000	  y */
literal|0x00
block|,
comment|/* 0x00000000	  y */
literal|0x00
block|,
comment|/* 0x00000000	  y */
literal|0x00
block|,
comment|/* 0x00000000	  y */
literal|0x21
block|,
comment|/* 0x00100001	  y */
literal|0x21
block|,
comment|/* 0x00100001	  y */
literal|0x21
block|,
comment|/* 0x00100001	  y */
literal|0x21
block|,
comment|/* 0x00100001	  y */
literal|0x21
block|,
comment|/* 0x00100001	  y */
literal|0x31
block|,
comment|/* 0x00110001	  y */
literal|0x2e
block|,
comment|/* 0x00101110	  y */
literal|0x20
block|,
comment|/* 0x00100000	  y */
literal|0x21
block|,
comment|/* 0x00100001	  y */
literal|0x1e
block|,
comment|/* 0x00011110	  y */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  z */
literal|0x00
block|,
comment|/* 0x00000000	  z */
literal|0x00
block|,
comment|/* 0x00000000	  z */
literal|0x00
block|,
comment|/* 0x00000000	  z */
literal|0x00
block|,
comment|/* 0x00000000	  z */
literal|0x7f
block|,
comment|/* 0x01111111	  z */
literal|0x20
block|,
comment|/* 0x00100000	  z */
literal|0x10
block|,
comment|/* 0x00010000	  z */
literal|0x08
block|,
comment|/* 0x00001000	  z */
literal|0x04
block|,
comment|/* 0x00000100	  z */
literal|0x02
block|,
comment|/* 0x00000010	  z */
literal|0x7f
block|,
comment|/* 0x01111111	  z */
literal|0x00
block|,
comment|/* 0x00000000	  z */
literal|0x00
block|,
comment|/* 0x00000000	  z */
literal|0x00
block|,
comment|/* 0x00000000	  z */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  { */
literal|0x00
block|,
comment|/* 0x00000000	  { */
literal|0x70
block|,
comment|/* 0x01110000	  { */
literal|0x08
block|,
comment|/* 0x00001000	  { */
literal|0x08
block|,
comment|/* 0x00001000	  { */
literal|0x10
block|,
comment|/* 0x00010000	  { */
literal|0x0c
block|,
comment|/* 0x00001100	  { */
literal|0x0c
block|,
comment|/* 0x00001100	  { */
literal|0x10
block|,
comment|/* 0x00010000	  { */
literal|0x08
block|,
comment|/* 0x00001000	  { */
literal|0x08
block|,
comment|/* 0x00001000	  { */
literal|0x70
block|,
comment|/* 0x01110000	  { */
literal|0x00
block|,
comment|/* 0x00000000	  { */
literal|0x00
block|,
comment|/* 0x00000000	  { */
literal|0x00
block|,
comment|/* 0x00000000	  { */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  | */
literal|0x00
block|,
comment|/* 0x00000000	  | */
literal|0x08
block|,
comment|/* 0x00001000	  | */
literal|0x08
block|,
comment|/* 0x00001000	  | */
literal|0x08
block|,
comment|/* 0x00001000	  | */
literal|0x08
block|,
comment|/* 0x00001000	  | */
literal|0x08
block|,
comment|/* 0x00001000	  | */
literal|0x08
block|,
comment|/* 0x00001000	  | */
literal|0x08
block|,
comment|/* 0x00001000	  | */
literal|0x08
block|,
comment|/* 0x00001000	  | */
literal|0x08
block|,
comment|/* 0x00001000	  | */
literal|0x08
block|,
comment|/* 0x00001000	  | */
literal|0x00
block|,
comment|/* 0x00000000	  | */
literal|0x00
block|,
comment|/* 0x00000000	  | */
literal|0x00
block|,
comment|/* 0x00000000	  | */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  } */
literal|0x00
block|,
comment|/* 0x00000000	  } */
literal|0x07
block|,
comment|/* 0x00000111	  } */
literal|0x08
block|,
comment|/* 0x00001000	  } */
literal|0x08
block|,
comment|/* 0x00001000	  } */
literal|0x04
block|,
comment|/* 0x00000100	  } */
literal|0x18
block|,
comment|/* 0x00011000	  } */
literal|0x18
block|,
comment|/* 0x00011000	  } */
literal|0x04
block|,
comment|/* 0x00000100	  } */
literal|0x08
block|,
comment|/* 0x00001000	  } */
literal|0x08
block|,
comment|/* 0x00001000	  } */
literal|0x07
block|,
comment|/* 0x00000111	  } */
literal|0x00
block|,
comment|/* 0x00000000	  } */
literal|0x00
block|,
comment|/* 0x00000000	  } */
literal|0x00
block|,
comment|/* 0x00000000	  } */
comment|/* */
literal|0x00
block|,
comment|/* 0x00000000	  ~ */
literal|0x00
block|,
comment|/* 0x00000000	  ~ */
literal|0x46
block|,
comment|/* 0x01000110	  ~ */
literal|0x49
block|,
comment|/* 0x01001001	  ~ */
literal|0x31
block|,
comment|/* 0x00110001	  ~ */
literal|0x00
block|,
comment|/* 0x00000000	  ~ */
literal|0x00
block|,
comment|/* 0x00000000	  ~ */
literal|0x00
block|,
comment|/* 0x00000000	  ~ */
literal|0x00
block|,
comment|/* 0x00000000	  ~ */
literal|0x00
block|,
comment|/* 0x00000000	  ~ */
literal|0x00
block|,
comment|/* 0x00000000	  ~ */
literal|0x00
block|,
comment|/* 0x00000000	  ~ */
literal|0x00
block|,
comment|/* 0x00000000	  ~ */
literal|0x00
block|,
comment|/* 0x00000000	  ~ */
literal|0x00
block|,
comment|/* 0x00000000	  ~ */
comment|/* */
comment|/* ascii0241 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0242 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
comment|/* ascii0243 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x70
block|,
literal|0x88
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x3e
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0xdc
block|,
literal|0x76
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0244 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0245 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x44
block|,
literal|0x44
block|,
literal|0x44
block|,
literal|0x28
block|,
literal|0x10
block|,
literal|0x7c
block|,
literal|0x10
block|,
literal|0x7c
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0246 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0247 */
literal|0x00
block|,
literal|0x1c
block|,
literal|0x22
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x1c
block|,
literal|0x22
block|,
literal|0x22
block|,
literal|0x1c
block|,
literal|0x10
block|,
literal|0x20
block|,
literal|0x22
block|,
literal|0x1c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0250 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x82
block|,
literal|0x44
block|,
literal|0x38
block|,
literal|0x44
block|,
literal|0x44
block|,
literal|0x44
block|,
literal|0x38
block|,
literal|0x44
block|,
literal|0x82
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0251 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x7c
block|,
literal|0x82
block|,
literal|0xb2
block|,
literal|0x8a
block|,
literal|0x8a
block|,
literal|0xb2
block|,
literal|0x82
block|,
literal|0x7c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0252 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x40
block|,
literal|0x7c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7c
block|,
literal|0x00
block|,
literal|0x7c
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0253 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x48
block|,
literal|0x24
block|,
literal|0x12
block|,
literal|0x09
block|,
literal|0x12
block|,
literal|0x24
block|,
literal|0x48
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0254 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0255 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0256 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0257 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0260 */
literal|0x00
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x24
block|,
literal|0x18
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0261 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x3e
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x00
block|,
literal|0x3e
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0262 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x0c
block|,
literal|0x12
block|,
literal|0x08
block|,
literal|0x04
block|,
literal|0x02
block|,
literal|0x1e
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0263 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x1e
block|,
literal|0x10
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x12
block|,
literal|0x0c
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0264 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0265 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x44
block|,
literal|0x44
block|,
literal|0x44
block|,
literal|0x44
block|,
literal|0x44
block|,
literal|0x7c
block|,
literal|0xc2
block|,
literal|0x01
block|,
comment|/* ascii0266 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x7c
block|,
literal|0x4e
block|,
literal|0x4e
block|,
literal|0x4e
block|,
literal|0x4e
block|,
literal|0x7c
block|,
literal|0x48
block|,
literal|0x48
block|,
literal|0x48
block|,
literal|0x48
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0267 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x18
block|,
literal|0x18
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0270 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0271 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x08
block|,
literal|0x0c
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x1c
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0272 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0273 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x12
block|,
literal|0x24
block|,
literal|0x48
block|,
literal|0x90
block|,
literal|0x48
block|,
literal|0x24
block|,
literal|0x12
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0274 */
literal|0x00
block|,
literal|0x04
block|,
literal|0x06
block|,
literal|0x04
block|,
literal|0x04
block|,
literal|0x4e
block|,
literal|0x20
block|,
literal|0x10
block|,
literal|0x48
block|,
literal|0x64
block|,
literal|0x52
block|,
literal|0xf8
block|,
literal|0x40
block|,
literal|0x40
block|,
literal|0x00
block|,
comment|/* ascii0275 */
literal|0x00
block|,
literal|0x04
block|,
literal|0x06
block|,
literal|0x04
block|,
literal|0x04
block|,
literal|0x4e
block|,
literal|0x20
block|,
literal|0x10
block|,
literal|0x08
block|,
literal|0x74
block|,
literal|0x82
block|,
literal|0x60
block|,
literal|0x10
block|,
literal|0xf0
block|,
literal|0x00
block|,
comment|/* ascii0276 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0277 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x08
block|,
literal|0x04
block|,
literal|0x02
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0300 */
literal|0x00
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x20
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7e
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0301 */
literal|0x00
block|,
literal|0x10
block|,
literal|0x08
block|,
literal|0x04
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7e
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0302 */
literal|0x00
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7e
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0303 */
literal|0x00
block|,
literal|0x4c
block|,
literal|0x32
block|,
literal|0x00
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7e
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0304 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x66
block|,
literal|0x00
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7e
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0305 */
literal|0x18
block|,
literal|0x24
block|,
literal|0x18
block|,
literal|0x00
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7e
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0306 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xf8
block|,
literal|0x14
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x7e
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0xf2
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0307 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x10
block|,
literal|0x0c
block|,
comment|/* ascii0310 */
literal|0x08
block|,
literal|0x10
block|,
literal|0x20
block|,
literal|0x00
block|,
literal|0x7e
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x1e
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x7e
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0311 */
literal|0x10
block|,
literal|0x08
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x7e
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x1e
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x7e
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0312 */
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x7e
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x1e
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x7e
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0313 */
literal|0x00
block|,
literal|0x66
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x7e
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x1e
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x7e
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0314 */
literal|0x08
block|,
literal|0x10
block|,
literal|0x20
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0315 */
literal|0x40
block|,
literal|0x20
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0316 */
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0317 */
literal|0x00
block|,
literal|0x66
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0320 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0321 */
literal|0x00
block|,
literal|0x4c
block|,
literal|0x32
block|,
literal|0x00
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x46
block|,
literal|0x4a
block|,
literal|0x52
block|,
literal|0x62
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0322 */
literal|0x08
block|,
literal|0x10
block|,
literal|0x20
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0323 */
literal|0x10
block|,
literal|0x08
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0324 */
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0325 */
literal|0x00
block|,
literal|0x4c
block|,
literal|0x32
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0326 */
literal|0x00
block|,
literal|0x66
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0327 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xfc
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x72
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0xfc
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0330 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xbc
block|,
literal|0x42
block|,
literal|0x62
block|,
literal|0x52
block|,
literal|0x52
block|,
literal|0x4a
block|,
literal|0x46
block|,
literal|0x42
block|,
literal|0x3d
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0331 */
literal|0x00
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0332 */
literal|0x00
block|,
literal|0x20
block|,
literal|0x10
block|,
literal|0x08
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0333 */
literal|0x00
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0334 */
literal|0x00
block|,
literal|0x66
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0335 */
literal|0x00
block|,
literal|0xc6
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x82
block|,
literal|0x82
block|,
literal|0x44
block|,
literal|0x28
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0336 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0337 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x70
block|,
literal|0x88
block|,
literal|0x84
block|,
literal|0x84
block|,
literal|0x44
block|,
literal|0x74
block|,
literal|0x84
block|,
literal|0x84
block|,
literal|0x84
block|,
literal|0x94
block|,
literal|0x74
block|,
literal|0x04
block|,
literal|0x02
block|,
comment|/* ascii0340 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x20
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x40
block|,
literal|0x7c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0341 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x08
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x40
block|,
literal|0x7c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0342 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x40
block|,
literal|0x7c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0343 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x4c
block|,
literal|0x32
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x40
block|,
literal|0x7c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0344 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x66
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x40
block|,
literal|0x7c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0345 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x18
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x40
block|,
literal|0x7c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x7c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0346 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x6e
block|,
literal|0x90
block|,
literal|0xfc
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0xec
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0347 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x10
block|,
literal|0x0c
block|,
comment|/* ascii0350 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x20
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x7e
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0351 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x08
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x7e
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0352 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x7e
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0353 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x66
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x7e
block|,
literal|0x02
block|,
literal|0x02
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0354 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0355 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x08
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0356 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0357 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x66
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x08
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0360 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0361 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x4c
block|,
literal|0x32
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3e
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0362 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x20
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0363 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x08
block|,
literal|0x04
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0364 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0365 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x4c
block|,
literal|0x32
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0366 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x66
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0367 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x6c
block|,
literal|0x92
block|,
literal|0xf2
block|,
literal|0x12
block|,
literal|0x12
block|,
literal|0xec
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0370 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0xbc
block|,
literal|0x62
block|,
literal|0x52
block|,
literal|0x4a
block|,
literal|0x46
block|,
literal|0x3c
block|,
literal|0x02
block|,
literal|0x00
block|,
comment|/* ascii0371 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0372 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x20
block|,
literal|0x10
block|,
literal|0x08
block|,
literal|0x00
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0373 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x18
block|,
literal|0x24
block|,
literal|0x42
block|,
literal|0x00
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0374 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x66
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0375 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x66
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x3c
block|,
literal|0x40
block|,
literal|0x40
block|,
literal|0x3e
block|,
comment|/* ascii0376 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,
comment|/* ascii0377 */
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x3c
block|,
literal|0x42
block|,
literal|0x42
block|,
literal|0x02
block|,
literal|0x04
block|,
literal|0x08
block|,
literal|0x10
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x10
block|,
literal|0x00
block|,
literal|0x00
block|,  }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *	Default Cursor  */
end_comment

begin_decl_stmt
name|unsigned
name|short
name|q_cursor
index|[]
init|=
block|{
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x00ff
block|,
literal|0x00ff
block|,
literal|0x00ff
block|,
literal|0x00ff
block|,
literal|0x00ff
block|,
literal|0x00ff
block|,
literal|0x00ff
block|,
literal|0x00ff
block|,
literal|0x00ff
block|,
literal|0x00ff
block|,
literal|0x00ff
block|,
literal|0x0000
block|,
literal|0x0000
block|,
literal|0x0000
block|}
decl_stmt|;
end_decl_stmt

end_unit

