begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  */
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
literal|"@(#)ebctab.c	1.3 (Berkeley) 3/28/88"
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
comment|/*  * ebcdic to ascii translation tables  */
end_comment

begin_include
include|#
directive|include
file|"ascebc.h"
end_include

begin_decl_stmt
name|unsigned
name|char
name|ebcasc
index|[
name|NEBCASC
index|]
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

