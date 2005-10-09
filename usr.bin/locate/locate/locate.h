begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995 Wolfram Schneider<wosch@FreeBSD.org>. Berlin.  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)locate.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Symbolic constants shared by locate.c and code.c */
end_comment

begin_define
define|#
directive|define
name|NBG
value|128
end_define

begin_comment
comment|/* number of bigrams considered */
end_comment

begin_define
define|#
directive|define
name|OFFSET
value|14
end_define

begin_comment
comment|/* abs value of max likely diff */
end_comment

begin_define
define|#
directive|define
name|PARITY
value|0200
end_define

begin_comment
comment|/* parity bit */
end_comment

begin_define
define|#
directive|define
name|SWITCH
value|30
end_define

begin_comment
comment|/* switch code */
end_comment

begin_define
define|#
directive|define
name|UMLAUT
value|31
end_define

begin_comment
comment|/* an 8 bit char followed */
end_comment

begin_comment
comment|/* 	0-28	likeliest differential counts + offset to make nonnegative */
end_comment

begin_define
define|#
directive|define
name|LDC_MIN
value|0
end_define

begin_define
define|#
directive|define
name|LDC_MAX
value|28
end_define

begin_comment
comment|/*	128-255 bigram codes (128 most common, as determined by 'updatedb') */
end_comment

begin_define
define|#
directive|define
name|BIGRAM_MIN
value|(UCHAR_MAX - CHAR_MAX)
end_define

begin_define
define|#
directive|define
name|BIGRAM_MAX
value|UCHAR_MAX
end_define

begin_comment
comment|/*	32-127  single character (printable) ascii residue (ie, literal) */
end_comment

begin_define
define|#
directive|define
name|ASCII_MIN
value|32
end_define

begin_define
define|#
directive|define
name|ASCII_MAX
value|CHAR_MAX
end_define

begin_comment
comment|/* #define TO7BIT(x)     (x = ( ((u_char)x)& CHAR_MAX )) */
end_comment

begin_define
define|#
directive|define
name|TO7BIT
parameter_list|(
name|x
parameter_list|)
value|(x = x& CHAR_MAX )
end_define

begin_if
if|#
directive|if
name|UCHAR_MAX
operator|>=
literal|4096
end_if

begin_decl_stmt
name|define
name|TOLOWER
argument_list|(
name|ch
argument_list|)
name|tolower
argument_list|(
name|ch
argument_list|)
else|#
directive|else
name|u_char
name|myctype
index|[
name|UCHAR_MAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TOLOWER
parameter_list|(
name|ch
parameter_list|)
value|(myctype[ch])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INTSIZE
value|(sizeof(int))
end_define

begin_define
define|#
directive|define
name|LOCATE_REG
value|"*?[]\\"
end_define

begin_comment
comment|/* fnmatch(3) meta characters */
end_comment

end_unit

