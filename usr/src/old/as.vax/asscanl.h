begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)asscanl.h	5.1 (Berkeley) 4/30/85  */
end_comment

begin_comment
comment|/*  *	This file contains definitions local to the files implementing  *	the character scanner and the token buffer managers.  *	It is not intended to be shared with any other parts of the  *	assembler.  *	The file ``asscan.h'' is shared with other parts of the assembler  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"as.h"
end_include

begin_include
include|#
directive|include
file|"asscan.h"
end_include

begin_define
define|#
directive|define
name|EOFCHAR
value|(-1)
end_define

begin_comment
comment|/*  *	The table of possible uses for each character to test set inclusion.  */
end_comment

begin_define
define|#
directive|define
name|HEXFLAG
value|01
end_define

begin_comment
comment|/* 'x' or 'X' */
end_comment

begin_define
define|#
directive|define
name|HEXLDIGIT
value|02
end_define

begin_comment
comment|/* 'a' .. 'f' */
end_comment

begin_define
define|#
directive|define
name|HEXUDIGIT
value|04
end_define

begin_comment
comment|/* 'A' .. 'F' */
end_comment

begin_define
define|#
directive|define
name|ALPHA
value|010
end_define

begin_comment
comment|/* 'A' .. 'Z', 'a' .. 'z', '_'*/
end_comment

begin_define
define|#
directive|define
name|DIGIT
value|020
end_define

begin_comment
comment|/* '0' .. '9' */
end_comment

begin_define
define|#
directive|define
name|FLOATEXP
value|040
end_define

begin_comment
comment|/* 'd' 'e' 'D' 'E' 'g' 'h' 'G' 'H' */
end_comment

begin_define
define|#
directive|define
name|SIGN
value|0100
end_define

begin_comment
comment|/* '+' .. '-'*/
end_comment

begin_define
define|#
directive|define
name|REGDIGIT
value|0200
end_define

begin_comment
comment|/* '0' .. '5' */
end_comment

begin_define
define|#
directive|define
name|SZSPECBEGIN
value|0400
end_define

begin_comment
comment|/* 'b', 'B', 'l', 'L', 'w', 'W' */
end_comment

begin_define
define|#
directive|define
name|POINT
value|01000
end_define

begin_comment
comment|/* '.' */
end_comment

begin_define
define|#
directive|define
name|SPACE
value|02000
end_define

begin_comment
comment|/* '\t' or ' ' */
end_comment

begin_define
define|#
directive|define
name|BSESCAPE
value|04000
end_define

begin_comment
comment|/* bnrtf */
end_comment

begin_define
define|#
directive|define
name|STRESCAPE
value|010000
end_define

begin_comment
comment|/* '"', '\\', '\n' */
end_comment

begin_define
define|#
directive|define
name|OCTDIGIT
value|020000
end_define

begin_comment
comment|/* '0' .. '7' */
end_comment

begin_define
define|#
directive|define
name|FLOATFLAG
value|040000
end_define

begin_comment
comment|/* 'd', 'D', 'f', 'F' */
end_comment

begin_define
define|#
directive|define
name|INCHARSET
parameter_list|(
name|val
parameter_list|,
name|kind
parameter_list|)
value|(charsets[val]& (kind) )
end_define

begin_comment
comment|/*  *	We use our own version of getchar/ungetc to get  *	some speed improvement  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Ginbufptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Ginbufcnt
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REGTOMEMBUF
value|Ginbufptr = inbufptr, Ginbufcnt = inbufcnt
end_define

begin_define
define|#
directive|define
name|MEMTOREGBUF
value|inbufptr = Ginbufptr, inbufcnt = Ginbufcnt
end_define

begin_undef
undef|#
directive|undef
name|getchar
end_undef

begin_define
define|#
directive|define
name|getchar
parameter_list|()
define|\
value|(inbufcnt--> 0 ? (*inbufptr++) : \ 		(fillinbuffer(), \ 		MEMTOREGBUF, \ 		inbufptr[-1]))
end_define

begin_undef
undef|#
directive|undef
name|ungetc
end_undef

begin_define
define|#
directive|define
name|ungetc
parameter_list|(
name|ch
parameter_list|)
define|\
value|(++inbufcnt, *--inbufptr = ch)
end_define

begin_escape
end_escape

begin_comment
comment|/*  *	Variables and definitions to manage the token buffering.  *	We scan (lexically analyze) a large number of tokens, and  *	then parse all of the tokens in the scan buffer.  *	This reduces procedure call overhead when the parser  *	demands a token, allows for an efficient reread during  *	the second pass, and confuses the line number reporting  *	for errors encountered in the scanner and in the parser.  */
end_comment

begin_define
define|#
directive|define
name|TOKDALLOP
value|8
end_define

begin_decl_stmt
name|struct
name|tokbufdesc
modifier|*
name|bufstart
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*where the buffer list begins*/
end_comment

begin_decl_stmt
name|struct
name|tokbufdesc
modifier|*
name|buftail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*last one on the list*/
end_comment

begin_decl_stmt
name|struct
name|tokbufdesc
modifier|*
name|emptybuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*the one being filled*/
end_comment

begin_comment
comment|/*  *	If we are using VM, during the second pass we reclaim the used  *	token buffers for saving the relocation information  */
end_comment

begin_decl_stmt
name|struct
name|tokbufdesc
modifier|*
name|tok_free
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* free pool */
end_comment

begin_decl_stmt
name|struct
name|tokbufdesc
modifier|*
name|tok_temp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temporary for doing list manipulation */
end_comment

begin_comment
comment|/*  *	Other token buffer managers  */
end_comment

begin_decl_stmt
name|int
name|bufno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*which buffer number: 0,1 for tmp file*/
end_comment

begin_decl_stmt
name|struct
name|tokbufdesc
name|tokbuf
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*our initial increment of buffers*/
end_comment

begin_decl_stmt
name|ptrall
name|tokptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*where the current token comes from*/
end_comment

begin_decl_stmt
name|ptrall
name|tokub
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*the last token in the current token buffer*/
end_comment

begin_comment
comment|/*  *	as does not use fread and fwrite for the token buffering.  *	The token buffers are integrals of BUFSIZ  *	at all times, so we use direct read and write.  *	fread and fwrite in stdio are HORRENDOUSLY inefficient,  *	as they use putchar for each character, nested two deep in loops.  */
end_comment

begin_define
define|#
directive|define
name|writeTEST
parameter_list|(
name|pointer
parameter_list|,
name|size
parameter_list|,
name|nelements
parameter_list|,
name|ioptr
parameter_list|)
define|\
value|write(ioptr->_file, pointer, nelements * size) != nelements * size
end_define

begin_define
define|#
directive|define
name|readTEST
parameter_list|(
name|pointer
parameter_list|,
name|size
parameter_list|,
name|nelements
parameter_list|,
name|ioptr
parameter_list|)
define|\
value|read(ioptr->_file, pointer, nelements * size) != nelements * size
end_define

begin_define
define|#
directive|define
name|bskiplg
parameter_list|(
name|from
parameter_list|,
name|length
parameter_list|)
define|\
value|*(lgtype *)from = length; \ 	(bytetoktype *)from += sizeof(lgtype) + length
end_define

begin_define
define|#
directive|define
name|bskipfromto
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|)
define|\
value|*(lgtype *)from = (bytetoktype *)to - (bytetoktype *)from - sizeof(lgtype); \ 	(bytetoktype *)from += sizeof (lgtype) + (bytetoktype *)to - (bytetoktype *)from
end_define

begin_define
define|#
directive|define
name|eatskiplg
parameter_list|(
name|from
parameter_list|)
define|\
value|(bytetoktype *)from += sizeof(lgtype) + *(lgtype *)from
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|ptrall
name|firsttoken
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|DEBUG
end_endif

begin_comment
comment|/*  *	The following three variables are the slots for global  *	communication with the parser.  *	They are the semantic values associated with a particular token.  *	The token itself is the return value from yylex()  */
end_comment

begin_decl_stmt
name|int
name|yylval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* normal semantic value */
end_comment

begin_decl_stmt
name|Bignum
name|yybignum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a big number */
end_comment

begin_decl_stmt
name|struct
name|Opcode
name|yyopcode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a structure opcode */
end_comment

begin_decl_stmt
name|int
name|newfflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|newfname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|scanlineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*the scanner's linenumber*/
end_comment

begin_comment
comment|/*  *	Definitions for sets of characters  */
end_comment

begin_decl_stmt
name|readonly
name|short
name|charsets
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|readonly
name|short
name|type
index|[]
decl_stmt|;
end_decl_stmt

end_unit

