begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lint.h,v 1.3 2002/01/31 22:44:00 tv Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAVE_DECL_SYS_SIGNAME
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_comment
comment|/*  * Type specifiers, used in type structures (type_t) and otherwere.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NOTSPEC
init|=
literal|0
block|,
name|SIGNED
block|,
comment|/* keyword "signed", only used in the parser */
name|UNSIGN
block|,
comment|/* keyword "unsigned", only used in the parser */
name|CHAR
block|,
comment|/* char */
name|SCHAR
block|,
comment|/* signed char */
name|UCHAR
block|,
comment|/* unsigned char */
name|SHORT
block|,
comment|/* (signed) short */
name|USHORT
block|,
comment|/* unsigned short */
name|INT
block|,
comment|/* (signed) int */
name|UINT
block|,
comment|/* unsigned int */
name|LONG
block|,
comment|/* (signed) long */
name|ULONG
block|,
comment|/* unsigned long */
name|QUAD
block|,
comment|/* (signed) long long */
name|UQUAD
block|,
comment|/* unsigned long long */
name|FLOAT
block|,
comment|/* float */
name|DOUBLE
block|,
comment|/* double or, with tflag, long float */
name|LDOUBLE
block|,
comment|/* long double */
name|VOID
block|,
comment|/* void */
name|STRUCT
block|,
comment|/* structure tag */
name|UNION
block|,
comment|/* union tag */
name|ENUM
block|,
comment|/* enum tag */
name|PTR
block|,
comment|/* pointer */
name|ARRAY
block|,
comment|/* array */
name|FUNC
block|,
comment|/* function */
name|NTSPEC
block|}
name|tspec_t
typedef|;
end_typedef

begin_comment
comment|/*  * size of types, name and classification  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|tt_sz
decl_stmt|;
comment|/* size in bits */
name|int
name|tt_psz
decl_stmt|;
comment|/* size, different from tt_sz 					   if pflag is set */
name|tspec_t
name|tt_styp
decl_stmt|;
comment|/* signed counterpart */
name|tspec_t
name|tt_utyp
decl_stmt|;
comment|/* unsigned counterpart */
name|u_int
name|tt_isityp
range|:
literal|1
decl_stmt|;
comment|/* 1 if integer type */
name|u_int
name|tt_isutyp
range|:
literal|1
decl_stmt|;
comment|/* 1 if unsigned integer type */
name|u_int
name|tt_isftyp
range|:
literal|1
decl_stmt|;
comment|/* 1 if floating point type */
name|u_int
name|tt_isatyp
range|:
literal|1
decl_stmt|;
comment|/* 1 if arithmetic type */
name|u_int
name|tt_issclt
range|:
literal|1
decl_stmt|;
comment|/* 1 if scalar type */
name|char
modifier|*
name|tt_name
decl_stmt|;
comment|/* Bezeichnung des Typs */
block|}
name|ttab_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|size
parameter_list|(
name|t
parameter_list|)
value|(ttab[t].tt_sz)
end_define

begin_define
define|#
directive|define
name|psize
parameter_list|(
name|t
parameter_list|)
value|(ttab[t].tt_psz)
end_define

begin_define
define|#
directive|define
name|styp
parameter_list|(
name|t
parameter_list|)
value|(ttab[t].tt_styp)
end_define

begin_define
define|#
directive|define
name|utyp
parameter_list|(
name|t
parameter_list|)
value|(ttab[t].tt_utyp)
end_define

begin_define
define|#
directive|define
name|isityp
parameter_list|(
name|t
parameter_list|)
value|(ttab[t].tt_isityp)
end_define

begin_define
define|#
directive|define
name|isutyp
parameter_list|(
name|t
parameter_list|)
value|(ttab[t].tt_isutyp)
end_define

begin_define
define|#
directive|define
name|isftyp
parameter_list|(
name|t
parameter_list|)
value|(ttab[t].tt_isftyp)
end_define

begin_define
define|#
directive|define
name|isatyp
parameter_list|(
name|t
parameter_list|)
value|(ttab[t].tt_isatyp)
end_define

begin_define
define|#
directive|define
name|issclt
parameter_list|(
name|t
parameter_list|)
value|(ttab[t].tt_issclt)
end_define

begin_decl_stmt
specifier|extern
name|ttab_t
name|ttab
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
block|{
name|NODECL
block|,
comment|/* until now not declared */
name|DECL
block|,
comment|/* declared */
name|TDEF
block|,
comment|/* tentative defined */
name|DEF
comment|/* defined */
block|}
name|def_t
typedef|;
end_typedef

begin_comment
comment|/*  * Following structure contains some data used for the output buffer.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ob
block|{
name|char
modifier|*
name|o_buf
decl_stmt|;
comment|/* buffer */
name|char
modifier|*
name|o_end
decl_stmt|;
comment|/* first byte after buffer */
name|size_t
name|o_len
decl_stmt|;
comment|/* length of buffer */
name|char
modifier|*
name|o_nxt
decl_stmt|;
comment|/* next free byte in buffer */
block|}
name|ob_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"externs.h"
end_include

end_unit

