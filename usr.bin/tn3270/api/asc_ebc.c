begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)asc_ebc.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Ascii<->Ebcdic translation tables.  */
end_comment

begin_include
include|#
directive|include
file|"asc_ebc.h"
end_include

begin_decl_stmt
name|unsigned
name|char
name|asc_ebc
index|[
name|NASCII
index|]
init|=
block|{
comment|/* 00 */
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
comment|/* 08 */
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
comment|/* 10 */
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
comment|/* 18 */
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
comment|/* 20 */
literal|0x40
block|,
literal|0x5A
block|,
literal|0x7F
block|,
literal|0x7B
block|,
literal|0x5B
block|,
literal|0x6C
block|,
literal|0x50
block|,
literal|0x7D
block|,
comment|/* 28 */
literal|0x4D
block|,
literal|0x5D
block|,
literal|0x5C
block|,
literal|0x4E
block|,
literal|0x6B
block|,
literal|0x60
block|,
literal|0x4B
block|,
literal|0x61
block|,
comment|/* 30 */
literal|0xF0
block|,
literal|0xF1
block|,
literal|0xF2
block|,
literal|0xF3
block|,
literal|0xF4
block|,
literal|0xF5
block|,
literal|0xF6
block|,
literal|0xF7
block|,
comment|/* 38 */
literal|0xF8
block|,
literal|0xF9
block|,
literal|0x7A
block|,
literal|0x5E
block|,
literal|0x4C
block|,
literal|0x7E
block|,
literal|0x6E
block|,
literal|0x6F
block|,
comment|/* 40 */
literal|0x7C
block|,
literal|0xC1
block|,
literal|0xC2
block|,
literal|0xC3
block|,
literal|0xC4
block|,
literal|0xC5
block|,
literal|0xC6
block|,
literal|0xC7
block|,
comment|/* 48 */
literal|0xC8
block|,
literal|0xC9
block|,
literal|0xD1
block|,
literal|0xD2
block|,
literal|0xD3
block|,
literal|0xD4
block|,
literal|0xD5
block|,
literal|0xD6
block|,
comment|/* 50 */
literal|0xD7
block|,
literal|0xD8
block|,
literal|0xD9
block|,
literal|0xE2
block|,
literal|0xE3
block|,
literal|0xE4
block|,
literal|0xE5
block|,
literal|0xE6
block|,
comment|/* 58 */
literal|0xE7
block|,
literal|0xE8
block|,
literal|0xE9
block|,
literal|0xAD
block|,
literal|0xE0
block|,
literal|0xBD
block|,
literal|0x5F
block|,
literal|0x6D
block|,
comment|/* 60 */
literal|0x79
block|,
literal|0x81
block|,
literal|0x82
block|,
literal|0x83
block|,
literal|0x84
block|,
literal|0x85
block|,
literal|0x86
block|,
literal|0x87
block|,
comment|/* 68 */
literal|0x88
block|,
literal|0x89
block|,
literal|0x91
block|,
literal|0x92
block|,
literal|0x93
block|,
literal|0x94
block|,
literal|0x95
block|,
literal|0x96
block|,
comment|/* 70 */
literal|0x97
block|,
literal|0x98
block|,
literal|0x99
block|,
literal|0xA2
block|,
literal|0xA3
block|,
literal|0xA4
block|,
literal|0xA5
block|,
literal|0xA6
block|,
comment|/* 78 */
literal|0xA7
block|,
literal|0xA8
block|,
literal|0xA9
block|,
literal|0xC0
block|,
literal|0x4F
block|,
literal|0xD0
block|,
literal|0xA1
block|,
literal|0x00
block|,  }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ebcdic to ascii translation tables  */
end_comment

begin_decl_stmt
name|unsigned
name|char
name|ebc_asc
index|[
name|NEBC
index|]
init|=
block|{
comment|/* 00 */
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* 08 */
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* 10 */
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* 18 */
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'*'
block|,
literal|' '
block|,
literal|';'
block|,
literal|' '
block|,
comment|/* 20 */
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* 28 */
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* 30 */
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* 38 */
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* 40 */
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* 48 */
literal|' '
block|,
literal|' '
block|,
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MSDOS
argument_list|)
comment|/* 4A */
literal|'\\'
block|,
else|#
directive|else
comment|/* !defined(MSDOS) */
comment|/* 4A */
literal|'\233'
block|,
comment|/* PC cent sign */
endif|#
directive|endif
comment|/* !defined(MSDOS) */
comment|/* 4B */
literal|'.'
block|,
literal|'<'
block|,
literal|'('
block|,
literal|'+'
block|,
literal|'|'
block|,
comment|/* 50 */
literal|'&'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* 58 */
literal|' '
block|,
literal|' '
block|,
literal|'!'
block|,
literal|'$'
block|,
literal|'*'
block|,
literal|')'
block|,
literal|';'
block|,
literal|'^'
block|,
comment|/* 60 */
literal|'-'
block|,
literal|'/'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* 68 */
literal|' '
block|,
literal|' '
block|,
literal|'|'
block|,
literal|','
block|,
literal|'%'
block|,
literal|'_'
block|,
literal|'>'
block|,
literal|'?'
block|,
comment|/* 70 */
literal|' '
block|,
literal|'^'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* 78 */
literal|' '
block|,
literal|'`'
block|,
literal|':'
block|,
literal|'#'
block|,
literal|'@'
block|,
literal|'\''
block|,
literal|'='
block|,
literal|'"'
block|,
comment|/* 80 */
literal|' '
block|,
literal|'a'
block|,
literal|'b'
block|,
literal|'c'
block|,
literal|'d'
block|,
literal|'e'
block|,
literal|'f'
block|,
literal|'g'
block|,
comment|/* 88 */
literal|'h'
block|,
literal|'i'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* 90 */
literal|' '
block|,
literal|'j'
block|,
literal|'k'
block|,
literal|'l'
block|,
literal|'m'
block|,
literal|'n'
block|,
literal|'o'
block|,
literal|'p'
block|,
comment|/* 98 */
literal|'q'
block|,
literal|'r'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* A0 */
literal|' '
block|,
literal|'~'
block|,
literal|'s'
block|,
literal|'t'
block|,
literal|'u'
block|,
literal|'v'
block|,
literal|'w'
block|,
literal|'x'
block|,
comment|/* A8 */
literal|'y'
block|,
literal|'z'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|'['
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* B0 */
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* B8 */
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|']'
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* C0 */
literal|'{'
block|,
literal|'A'
block|,
literal|'B'
block|,
literal|'C'
block|,
literal|'D'
block|,
literal|'E'
block|,
literal|'F'
block|,
literal|'G'
block|,
comment|/* C8 */
literal|'H'
block|,
literal|'I'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* D0 */
literal|'}'
block|,
literal|'J'
block|,
literal|'K'
block|,
literal|'L'
block|,
literal|'M'
block|,
literal|'N'
block|,
literal|'O'
block|,
literal|'P'
block|,
comment|/* D8 */
literal|'Q'
block|,
literal|'R'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* E0 */
literal|'\\'
block|,
literal|' '
block|,
literal|'S'
block|,
literal|'T'
block|,
literal|'U'
block|,
literal|'V'
block|,
literal|'W'
block|,
literal|'X'
block|,
comment|/* E8 */
literal|'Y'
block|,
literal|'Z'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
comment|/* F0 */
literal|'0'
block|,
literal|'1'
block|,
literal|'2'
block|,
literal|'3'
block|,
literal|'4'
block|,
literal|'5'
block|,
literal|'6'
block|,
literal|'7'
block|,
comment|/* F8 */
literal|'8'
block|,
literal|'9'
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|,
literal|' '
block|, }
decl_stmt|;
end_decl_stmt

end_unit

