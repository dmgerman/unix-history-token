begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ozan Yigit at York University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)mdef.h	8.1 (Berkeley) 6/6/93  */
end_comment

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
name|STATIC
value|128
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|msdos
end_ifdef

begin_define
define|#
directive|define
name|system
parameter_list|(
name|str
parameter_list|)
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * other important constants  */
end_comment

begin_define
define|#
directive|define
name|EOS
value|(char) 0
end_define

begin_define
define|#
directive|define
name|MAXINP
value|10
end_define

begin_comment
comment|/* maximum include files   */
end_comment

begin_define
define|#
directive|define
name|MAXOUT
value|10
end_define

begin_comment
comment|/* maximum # of diversions */
end_comment

begin_define
define|#
directive|define
name|MAXSTR
value|512
end_define

begin_comment
comment|/* maximum size of string  */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|4096
end_define

begin_comment
comment|/* size of pushback buffer */
end_comment

begin_define
define|#
directive|define
name|STACKMAX
value|1024
end_define

begin_comment
comment|/* size of call stack      */
end_comment

begin_define
define|#
directive|define
name|STRSPMAX
value|4096
end_define

begin_comment
comment|/* size of string space    */
end_comment

begin_define
define|#
directive|define
name|MAXTOK
value|MAXSTR
end_define

begin_comment
comment|/* maximum chars in a tokn */
end_comment

begin_define
define|#
directive|define
name|HASHSIZE
value|199
end_define

begin_comment
comment|/* maximum size of hashtab */
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
name|ndblock
block|{
comment|/* hastable structure         */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* entry name..               */
name|char
modifier|*
name|defn
decl_stmt|;
comment|/* definition..               */
name|int
name|type
decl_stmt|;
comment|/* type of the entry..        */
name|ndptr
name|nxtptr
decl_stmt|;
comment|/* link to next entry..       */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nil
value|((ndptr) 0)
end_define

begin_struct
struct|struct
name|keyblk
block|{
name|char
modifier|*
name|knam
decl_stmt|;
comment|/* keyword name */
name|int
name|ktyp
decl_stmt|;
comment|/* keyword type */
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

begin_comment
comment|/*  * macros for readibility and/or speed  *  *      gpbc()  - get a possibly pushed-back character  *      pushf() - push a call frame entry onto stack  *      pushs() - push a string pointer onto stack  */
end_comment

begin_define
define|#
directive|define
name|gpbc
parameter_list|()
value|(bp> bufbase) ? (*--bp ? *bp : EOF) : getc(infile[ilevel])
end_define

begin_define
define|#
directive|define
name|pushf
parameter_list|(
name|x
parameter_list|)
value|if (sp< STACKMAX) mstack[++sp].sfra = (x)
end_define

begin_define
define|#
directive|define
name|pushs
parameter_list|(
name|x
parameter_list|)
value|if (sp< STACKMAX) mstack[++sp].sstr = (x)
end_define

begin_comment
comment|/*  *	    .				   .  *	|   .	|<-- sp		|  .  |  *	+-------+			+-----+  *	| arg 3 ----------------------->| str |  *	+-------+			|  .  |  *	| arg 2 ---PREVEP-----+ 	   .  *	+-------+	      |  *	    .		      |		|     |  *	+-------+	      | 	+-----+  *	| plev	|  PARLEV     +-------->| str |  *	+-------+			|  .  |  *	| type	|  CALTYP		   .  *	+-------+  *	| prcf	---PREVFP--+  *	+-------+  	   |  *	|   .	|  PREVSP  |  *	    .	   	   |  *	+-------+	   |  *	|<----------+  *	+-------+  *  */
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
value|(fp-3)
end_define

begin_define
define|#
directive|define
name|PREVFP
value|(mstack[fp-2].sfra)
end_define

end_unit

