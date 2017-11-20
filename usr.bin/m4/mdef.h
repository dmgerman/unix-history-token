begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: mdef.h,v 1.33 2015/11/03 16:21:47 deraadt Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: mdef.h,v 1.7 1996/01/13 23:25:27 pk Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ozan Yigit at York University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mdef.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|UNUSED
value|__attribute__((__unused__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UNUSED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MACRTYPE
value|1
end_define

begin_define
define|#
directive|define
name|DEFITYPE
value|2
end_define

begin_define
define|#
directive|define
name|EXPRTYPE
value|3
end_define

begin_define
define|#
directive|define
name|SUBSTYPE
value|4
end_define

begin_define
define|#
directive|define
name|IFELTYPE
value|5
end_define

begin_define
define|#
directive|define
name|LENGTYPE
value|6
end_define

begin_define
define|#
directive|define
name|CHNQTYPE
value|7
end_define

begin_define
define|#
directive|define
name|SYSCTYPE
value|8
end_define

begin_define
define|#
directive|define
name|UNDFTYPE
value|9
end_define

begin_define
define|#
directive|define
name|INCLTYPE
value|10
end_define

begin_define
define|#
directive|define
name|SINCTYPE
value|11
end_define

begin_define
define|#
directive|define
name|PASTTYPE
value|12
end_define

begin_define
define|#
directive|define
name|SPASTYPE
value|13
end_define

begin_define
define|#
directive|define
name|INCRTYPE
value|14
end_define

begin_define
define|#
directive|define
name|IFDFTYPE
value|15
end_define

begin_define
define|#
directive|define
name|PUSDTYPE
value|16
end_define

begin_define
define|#
directive|define
name|POPDTYPE
value|17
end_define

begin_define
define|#
directive|define
name|SHIFTYPE
value|18
end_define

begin_define
define|#
directive|define
name|DECRTYPE
value|19
end_define

begin_define
define|#
directive|define
name|DIVRTYPE
value|20
end_define

begin_define
define|#
directive|define
name|UNDVTYPE
value|21
end_define

begin_define
define|#
directive|define
name|DIVNTYPE
value|22
end_define

begin_define
define|#
directive|define
name|MKTMTYPE
value|23
end_define

begin_define
define|#
directive|define
name|ERRPTYPE
value|24
end_define

begin_define
define|#
directive|define
name|M4WRTYPE
value|25
end_define

begin_define
define|#
directive|define
name|TRNLTYPE
value|26
end_define

begin_define
define|#
directive|define
name|DNLNTYPE
value|27
end_define

begin_define
define|#
directive|define
name|DUMPTYPE
value|28
end_define

begin_define
define|#
directive|define
name|CHNCTYPE
value|29
end_define

begin_define
define|#
directive|define
name|INDXTYPE
value|30
end_define

begin_define
define|#
directive|define
name|SYSVTYPE
value|31
end_define

begin_define
define|#
directive|define
name|EXITTYPE
value|32
end_define

begin_define
define|#
directive|define
name|DEFNTYPE
value|33
end_define

begin_define
define|#
directive|define
name|SELFTYPE
value|34
end_define

begin_define
define|#
directive|define
name|INDIRTYPE
value|35
end_define

begin_define
define|#
directive|define
name|BUILTINTYPE
value|36
end_define

begin_define
define|#
directive|define
name|PATSTYPE
value|37
end_define

begin_define
define|#
directive|define
name|FILENAMETYPE
value|38
end_define

begin_define
define|#
directive|define
name|LINETYPE
value|39
end_define

begin_define
define|#
directive|define
name|REGEXPTYPE
value|40
end_define

begin_define
define|#
directive|define
name|ESYSCMDTYPE
value|41
end_define

begin_define
define|#
directive|define
name|TRACEONTYPE
value|42
end_define

begin_define
define|#
directive|define
name|TRACEOFFTYPE
value|43
end_define

begin_define
define|#
directive|define
name|FORMATTYPE
value|44
end_define

begin_define
define|#
directive|define
name|BUILTIN_MARKER
value|"__builtin_"
end_define

begin_define
define|#
directive|define
name|TYPEMASK
value|63
end_define

begin_comment
comment|/* Keep bits really corresponding to a type. */
end_comment

begin_define
define|#
directive|define
name|RECDEF
value|256
end_define

begin_comment
comment|/* Pure recursive def, don't expand it */
end_comment

begin_define
define|#
directive|define
name|NOARGS
value|512
end_define

begin_comment
comment|/* builtin needs no args */
end_comment

begin_define
define|#
directive|define
name|NEEDARGS
value|1024
end_define

begin_comment
comment|/* mark builtin that need args with this */
end_comment

begin_comment
comment|/*  * m4 special characters  */
end_comment

begin_define
define|#
directive|define
name|ARGFLAG
value|'$'
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

begin_define
define|#
directive|define
name|LQUOTE
value|'`'
end_define

begin_define
define|#
directive|define
name|RQUOTE
value|'\''
end_define

begin_define
define|#
directive|define
name|COMMA
value|','
end_define

begin_define
define|#
directive|define
name|SCOMMT
value|'#'
end_define

begin_define
define|#
directive|define
name|ECOMMT
value|'\n'
end_define

begin_comment
comment|/*  * other important constants  */
end_comment

begin_define
define|#
directive|define
name|EOS
value|'\0'
end_define

begin_define
define|#
directive|define
name|MAXINP
value|10
end_define

begin_comment
comment|/* maximum include files	    */
end_comment

begin_define
define|#
directive|define
name|MAXOUT
value|10
end_define

begin_comment
comment|/* maximum # of diversions	    */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|4096
end_define

begin_comment
comment|/* starting size of pushback buffer */
end_comment

begin_define
define|#
directive|define
name|INITSTACKMAX
value|4096
end_define

begin_comment
comment|/* starting size of call stack      */
end_comment

begin_define
define|#
directive|define
name|STRSPMAX
value|4096
end_define

begin_comment
comment|/* starting size of string space    */
end_comment

begin_define
define|#
directive|define
name|MAXTOK
value|512
end_define

begin_comment
comment|/* maximum chars in a tokn	    */
end_comment

begin_define
define|#
directive|define
name|MAXCCHARS
value|5
end_define

begin_comment
comment|/* max size of comment/quote delim  */
end_comment

begin_define
define|#
directive|define
name|ALL
value|1
end_define

begin_define
define|#
directive|define
name|TOP
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|cycle
value|for(;;)
end_define

begin_comment
comment|/*  * m4 data structures  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|ndblock
modifier|*
name|ndptr
typedef|;
end_typedef

begin_struct
struct|struct
name|macro_definition
block|{
name|struct
name|macro_definition
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|defn
decl_stmt|;
comment|/* definition..               */
name|unsigned
name|int
name|type
decl_stmt|;
comment|/* type of the entry..        */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ndblock
block|{
comment|/* hashtable structure         */
name|unsigned
name|int
name|builtin_type
decl_stmt|;
name|unsigned
name|int
name|trace_flags
decl_stmt|;
name|struct
name|macro_definition
modifier|*
name|d
decl_stmt|;
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* entry name..               */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
union|union
block|{
comment|/* stack structure */
name|int
name|sfra
decl_stmt|;
comment|/* frame entry  */
name|char
modifier|*
name|sstr
decl_stmt|;
comment|/* string entry */
block|}
name|stae
typedef|;
end_typedef

begin_struct
struct|struct
name|input_file
block|{
name|FILE
modifier|*
name|file
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|long
name|lineno
decl_stmt|;
name|unsigned
name|long
name|synch_lineno
decl_stmt|;
comment|/* used for -s */
name|int
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STORAGE_STRSPACE
value|0
end_define

begin_define
define|#
directive|define
name|STORAGE_MACRO
value|1
end_define

begin_define
define|#
directive|define
name|STORAGE_OTHER
value|2
end_define

begin_define
define|#
directive|define
name|CURRENT_NAME
value|(infile[ilevel].name)
end_define

begin_define
define|#
directive|define
name|CURRENT_LINE
value|(infile[ilevel].lineno)
end_define

begin_comment
comment|/*  * macros for readibility and/or speed  *  *      gpbc()  - get a possibly pushed-back character  *      pushf() - push a call frame entry onto stack  *      pushs() - push a string pointer onto stack  */
end_comment

begin_define
define|#
directive|define
name|gpbc
parameter_list|()
value|(bp> bufbase) ? *--bp : obtain_char(infile+ilevel)
end_define

begin_define
define|#
directive|define
name|pushf
parameter_list|(
name|x
parameter_list|)
define|\
value|do {				\ 		if (++sp == (int)STACKMAX)	\ 			enlarge_stack();\ 		mstack[sp].sfra = (x);	\ 		sstack[sp] = STORAGE_OTHER; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|pushs
parameter_list|(
name|x
parameter_list|)
define|\
value|do {				\ 		if (++sp == (int)STACKMAX)	\ 			enlarge_stack();\ 		mstack[sp].sstr = (x);	\ 		sstack[sp] = STORAGE_STRSPACE; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|pushs1
parameter_list|(
name|x
parameter_list|)
define|\
value|do {				\ 		if (++sp == (int)STACKMAX)	\ 			enlarge_stack();\ 		mstack[sp].sstr = (x);	\ 		sstack[sp] = STORAGE_OTHER; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|pushdef
parameter_list|(
name|p
parameter_list|)
define|\
value|do {				\ 		if (++sp == (int)STACKMAX)	\ 			enlarge_stack();\ 		mstack[sp].sstr = macro_getdef(p)->defn;\ 		sstack[sp] = STORAGE_MACRO; \ 	} while (0)
end_define

begin_comment
comment|/*  *	    .				   .  *	|   .	|<-- sp		|  .  |  *	+-------+			+-----+  *	| arg 3 ----------------------->| str |  *	+-------+			|  .  |  *	| arg 2 ---PREVEP-----+		   .  *	+-------+	      |  *	    .		      |		|     |  *	+-------+	      |		+-----+  *	| plev	|  PARLEV     +-------->| str |  *	+-------+			|  .  |  *	| type	|  CALTYP		   .  *	+-------+  *	| prcf	---PREVFP--+  *	+-------+	   |  *	|   .	|  PREVSP  |  *	    .		   |  *	+-------+	   |  *	|<----------+  *	+-------+  *  */
end_comment

begin_define
define|#
directive|define
name|PARLEV
value|(mstack[fp].sfra)
end_define

begin_define
define|#
directive|define
name|CALTYP
value|(mstack[fp-2].sfra)
end_define

begin_define
define|#
directive|define
name|TRACESTATUS
value|(mstack[fp-1].sfra)
end_define

begin_define
define|#
directive|define
name|PREVEP
value|(mstack[fp+3].sstr)
end_define

begin_define
define|#
directive|define
name|PREVSP
value|(fp-4)
end_define

begin_define
define|#
directive|define
name|PREVFP
value|(mstack[fp-3].sfra)
end_define

end_unit

