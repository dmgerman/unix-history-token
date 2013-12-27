begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994 Henry Spencer.  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Henry Spencer.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)regex2.h	8.4 (Berkeley) 3/20/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * First, the stuff that ends up in the outside-world include file  = typedef off_t regoff_t;  = typedef struct {  = 	int re_magic;  = 	size_t re_nsub;		// number of parenthesized subexpressions  = 	const char *re_endp;	// end pointer for REG_PEND  = 	struct re_guts *re_g;	// none of your business :-)  = } regex_t;  = typedef struct {  = 	regoff_t rm_so;		// start of match  = 	regoff_t rm_eo;		// end of match  = } regmatch_t;  */
end_comment

begin_comment
comment|/*  * internals of regex_t  */
end_comment

begin_define
define|#
directive|define
name|MAGIC1
value|((('r'^0200)<<8) | 'e')
end_define

begin_comment
comment|/*  * The internal representation is a *strip*, a sequence of  * operators ending with an endmarker.  (Some terminology etc. is a  * historical relic of earlier versions which used multiple strips.)  * Certain oddities in the representation are there to permit running  * the machinery backwards; in particular, any deviation from sequential  * flow must be marked at both its source and its destination.  Some  * fine points:  *  * - OPLUS_ and O_PLUS are *inside* the loop they create.  * - OQUEST_ and O_QUEST are *outside* the bypass they create.  * - OCH_ and O_CH are *outside* the multi-way branch they create, while  *   OOR1 and OOR2 are respectively the end and the beginning of one of  *   the branches.  Note that there is an implicit OOR2 following OCH_  *   and an implicit OOR1 preceding O_CH.  *  * In state representations, an operator's bit is on to signify a state  * immediately *preceding* "execution" of that operator.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|sop
typedef|;
end_typedef

begin_comment
comment|/* strip operator */
end_comment

begin_typedef
typedef|typedef
name|long
name|sopno
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OPRMASK
value|0xf8000000L
end_define

begin_define
define|#
directive|define
name|OPDMASK
value|0x07ffffffL
end_define

begin_define
define|#
directive|define
name|OPSHIFT
value|((unsigned)27)
end_define

begin_define
define|#
directive|define
name|OP
parameter_list|(
name|n
parameter_list|)
value|((n)&OPRMASK)
end_define

begin_define
define|#
directive|define
name|OPND
parameter_list|(
name|n
parameter_list|)
value|((n)&OPDMASK)
end_define

begin_define
define|#
directive|define
name|SOP
parameter_list|(
name|op
parameter_list|,
name|opnd
parameter_list|)
value|((op)|(opnd))
end_define

begin_comment
comment|/* operators			   meaning	operand			*/
end_comment

begin_comment
comment|/*						(back, fwd are offsets)	*/
end_comment

begin_define
define|#
directive|define
name|OEND
value|(1L<<OPSHIFT)
end_define

begin_comment
comment|/* endmarker	-			*/
end_comment

begin_define
define|#
directive|define
name|OCHAR
value|(2L<<OPSHIFT)
end_define

begin_comment
comment|/* character	wide character		*/
end_comment

begin_define
define|#
directive|define
name|OBOL
value|(3L<<OPSHIFT)
end_define

begin_comment
comment|/* left anchor	-			*/
end_comment

begin_define
define|#
directive|define
name|OEOL
value|(4L<<OPSHIFT)
end_define

begin_comment
comment|/* right anchor	-			*/
end_comment

begin_define
define|#
directive|define
name|OANY
value|(5L<<OPSHIFT)
end_define

begin_comment
comment|/* .		-			*/
end_comment

begin_define
define|#
directive|define
name|OANYOF
value|(6L<<OPSHIFT)
end_define

begin_comment
comment|/* [...]	set number		*/
end_comment

begin_define
define|#
directive|define
name|OBACK_
value|(7L<<OPSHIFT)
end_define

begin_comment
comment|/* begin \d	paren number		*/
end_comment

begin_define
define|#
directive|define
name|O_BACK
value|(8L<<OPSHIFT)
end_define

begin_comment
comment|/* end \d	paren number		*/
end_comment

begin_define
define|#
directive|define
name|OPLUS_
value|(9L<<OPSHIFT)
end_define

begin_comment
comment|/* + prefix	fwd to suffix		*/
end_comment

begin_define
define|#
directive|define
name|O_PLUS
value|(10L<<OPSHIFT)
end_define

begin_comment
comment|/* + suffix	back to prefix		*/
end_comment

begin_define
define|#
directive|define
name|OQUEST_
value|(11L<<OPSHIFT)
end_define

begin_comment
comment|/* ? prefix	fwd to suffix		*/
end_comment

begin_define
define|#
directive|define
name|O_QUEST
value|(12L<<OPSHIFT)
end_define

begin_comment
comment|/* ? suffix	back to prefix		*/
end_comment

begin_define
define|#
directive|define
name|OLPAREN
value|(13L<<OPSHIFT)
end_define

begin_comment
comment|/* (		fwd to )		*/
end_comment

begin_define
define|#
directive|define
name|ORPAREN
value|(14L<<OPSHIFT)
end_define

begin_comment
comment|/* )		back to (		*/
end_comment

begin_define
define|#
directive|define
name|OCH_
value|(15L<<OPSHIFT)
end_define

begin_comment
comment|/* begin choice	fwd to OOR2		*/
end_comment

begin_define
define|#
directive|define
name|OOR1
value|(16L<<OPSHIFT)
end_define

begin_comment
comment|/* | pt. 1	back to OOR1 or OCH_	*/
end_comment

begin_define
define|#
directive|define
name|OOR2
value|(17L<<OPSHIFT)
end_define

begin_comment
comment|/* | pt. 2	fwd to OOR2 or O_CH	*/
end_comment

begin_define
define|#
directive|define
name|O_CH
value|(18L<<OPSHIFT)
end_define

begin_comment
comment|/* end choice	back to OOR1		*/
end_comment

begin_define
define|#
directive|define
name|OBOW
value|(19L<<OPSHIFT)
end_define

begin_comment
comment|/* begin word	-			*/
end_comment

begin_define
define|#
directive|define
name|OEOW
value|(20L<<OPSHIFT)
end_define

begin_comment
comment|/* end word	-			*/
end_comment

begin_comment
comment|/*  * Structures for [] character-set representation.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|wint_t
name|min
decl_stmt|;
name|wint_t
name|max
decl_stmt|;
block|}
name|crange
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|bmp
index|[
name|NC
operator|/
literal|8
index|]
decl_stmt|;
name|wctype_t
modifier|*
name|types
decl_stmt|;
name|int
name|ntypes
decl_stmt|;
name|wint_t
modifier|*
name|wides
decl_stmt|;
name|int
name|nwides
decl_stmt|;
name|crange
modifier|*
name|ranges
decl_stmt|;
name|int
name|nranges
decl_stmt|;
name|int
name|invert
decl_stmt|;
name|int
name|icase
decl_stmt|;
block|}
name|cset
typedef|;
end_typedef

begin_function
specifier|static
name|int
name|CHIN1
parameter_list|(
name|cset
modifier|*
name|cs
parameter_list|,
name|wint_t
name|ch
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|assert
argument_list|(
name|ch
operator|>=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ch
operator|<
name|NC
condition|)
return|return
operator|(
operator|(
operator|(
name|cs
operator|->
name|bmp
index|[
name|ch
operator|>>
literal|3
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|ch
operator|&
literal|7
operator|)
operator|)
operator|)
operator|!=
literal|0
operator|)
operator|^
name|cs
operator|->
name|invert
operator|)
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|cs
operator|->
name|nwides
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|ch
operator|==
name|cs
operator|->
name|wides
index|[
name|i
index|]
condition|)
return|return
operator|(
operator|!
name|cs
operator|->
name|invert
operator|)
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|cs
operator|->
name|nranges
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|cs
operator|->
name|ranges
index|[
name|i
index|]
operator|.
name|min
operator|<=
name|ch
operator|&&
name|ch
operator|<=
name|cs
operator|->
name|ranges
index|[
name|i
index|]
operator|.
name|max
condition|)
return|return
operator|(
operator|!
name|cs
operator|->
name|invert
operator|)
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|cs
operator|->
name|ntypes
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|iswctype
argument_list|(
name|ch
argument_list|,
name|cs
operator|->
name|types
index|[
name|i
index|]
argument_list|)
condition|)
return|return
operator|(
operator|!
name|cs
operator|->
name|invert
operator|)
return|;
return|return
operator|(
name|cs
operator|->
name|invert
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|CHIN
parameter_list|(
name|cset
modifier|*
name|cs
parameter_list|,
name|wint_t
name|ch
parameter_list|)
block|{
name|assert
argument_list|(
name|ch
operator|>=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|ch
operator|<
name|NC
condition|)
return|return
operator|(
operator|(
operator|(
name|cs
operator|->
name|bmp
index|[
name|ch
operator|>>
literal|3
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|ch
operator|&
literal|7
operator|)
operator|)
operator|)
operator|!=
literal|0
operator|)
operator|^
name|cs
operator|->
name|invert
operator|)
return|;
elseif|else
if|if
condition|(
name|cs
operator|->
name|icase
condition|)
return|return
operator|(
name|CHIN1
argument_list|(
name|cs
argument_list|,
name|ch
argument_list|)
operator|||
name|CHIN1
argument_list|(
name|cs
argument_list|,
name|towlower
argument_list|(
name|ch
argument_list|)
argument_list|)
operator|||
name|CHIN1
argument_list|(
name|cs
argument_list|,
name|towupper
argument_list|(
name|ch
argument_list|)
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|CHIN1
argument_list|(
name|cs
argument_list|,
name|ch
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * main compiled-expression structure  */
end_comment

begin_struct
struct|struct
name|re_guts
block|{
name|int
name|magic
decl_stmt|;
define|#
directive|define
name|MAGIC2
value|((('R'^0200)<<8)|'E')
name|sop
modifier|*
name|strip
decl_stmt|;
comment|/* malloced area for strip */
name|int
name|ncsets
decl_stmt|;
comment|/* number of csets in use */
name|cset
modifier|*
name|sets
decl_stmt|;
comment|/* -> cset [ncsets] */
name|int
name|cflags
decl_stmt|;
comment|/* copy of regcomp() cflags argument */
name|sopno
name|nstates
decl_stmt|;
comment|/* = number of sops */
name|sopno
name|firststate
decl_stmt|;
comment|/* the initial OEND (normally 0) */
name|sopno
name|laststate
decl_stmt|;
comment|/* the final OEND */
name|int
name|iflags
decl_stmt|;
comment|/* internal flags */
define|#
directive|define
name|USEBOL
value|01
comment|/* used ^ */
define|#
directive|define
name|USEEOL
value|02
comment|/* used $ */
define|#
directive|define
name|BAD
value|04
comment|/* something wrong */
name|int
name|nbol
decl_stmt|;
comment|/* number of ^ used */
name|int
name|neol
decl_stmt|;
comment|/* number of $ used */
name|char
modifier|*
name|must
decl_stmt|;
comment|/* match must contain this string */
name|int
name|moffset
decl_stmt|;
comment|/* latest point at which must may be located */
name|int
modifier|*
name|charjump
decl_stmt|;
comment|/* Boyer-Moore char jump table */
name|int
modifier|*
name|matchjump
decl_stmt|;
comment|/* Boyer-Moore match jump table */
name|int
name|mlen
decl_stmt|;
comment|/* length of must */
name|size_t
name|nsub
decl_stmt|;
comment|/* copy of re_nsub */
name|int
name|backrefs
decl_stmt|;
comment|/* does it use back references? */
name|sopno
name|nplus
decl_stmt|;
comment|/* how deep does it nest +s? */
block|}
struct|;
end_struct

begin_comment
comment|/* misc utilities */
end_comment

begin_define
define|#
directive|define
name|OUT
value|(CHAR_MIN - 1)
end_define

begin_comment
comment|/* a non-character value */
end_comment

begin_define
define|#
directive|define
name|ISWORD
parameter_list|(
name|c
parameter_list|)
value|(iswalnum((uch)(c)) || (c) == '_')
end_define

end_unit

