begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: lint2.h,v 1.5 2000/06/14 06:49:23 cgd Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Christopher G. Demetriou.  All Rights Reserved.  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"lint.h"
end_include

begin_comment
comment|/*  * Types are described by structures of type type_t.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|type
block|{
name|tspec_t
name|t_tspec
decl_stmt|;
comment|/* type specifier */
name|u_int
name|t_const
range|:
literal|1
decl_stmt|;
comment|/* constant */
name|u_int
name|t_volatile
range|:
literal|1
decl_stmt|;
comment|/* volatile */
name|u_int
name|t_vararg
range|:
literal|1
decl_stmt|;
comment|/* function has variable number of arguments */
name|u_int
name|t_isenum
range|:
literal|1
decl_stmt|;
comment|/* enum type */
name|u_int
name|t_proto
range|:
literal|1
decl_stmt|;
comment|/* this is a prototype */
name|u_int
name|t_istag
range|:
literal|1
decl_stmt|;
comment|/* tag with _t_tag valid */
name|u_int
name|t_istynam
range|:
literal|1
decl_stmt|;
comment|/* tag with _t_tynam valid */
name|u_int
name|t_isuniqpos
range|:
literal|1
decl_stmt|;
comment|/* tag with _t_uniqpos valid */
union|union
block|{
name|int
name|_t_dim
decl_stmt|;
comment|/* if the type is an ARRAY than this 					   is the dimension of the array. */
name|struct
name|hte
modifier|*
name|_t_tag
decl_stmt|;
comment|/* hash table entry of tag if 					   t_isenum, STRUCT or UNION */
name|struct
name|hte
modifier|*
name|_t_tynam
decl_stmt|;
comment|/* hash table entry of typename if 					   t_isenum, STRUCT or UNION */
struct|struct
block|{
name|int
name|p_line
decl_stmt|;
name|short
name|p_file
decl_stmt|;
name|int
name|p_uniq
decl_stmt|;
block|}
name|_t_uniqpos
struct|;
comment|/* unique position, for untagged 					   untyped STRUCTs, UNIONS, and ENUMs, 					   if t_isuniqpos */
name|struct
name|type
modifier|*
modifier|*
name|_t_args
decl_stmt|;
comment|/* list of argument types if this 					   is a prototype */
block|}
name|t_u
union|;
name|struct
name|type
modifier|*
name|t_subt
decl_stmt|;
comment|/* indirected type (array element, pointed to 				   type, type of return value) */
block|}
name|type_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|t_dim
value|t_u._t_dim
end_define

begin_define
define|#
directive|define
name|t_tag
value|t_u._t_tag
end_define

begin_define
define|#
directive|define
name|t_tynam
value|t_u._t_tynam
end_define

begin_define
define|#
directive|define
name|t_uniqpos
value|t_u._t_uniqpos
end_define

begin_define
define|#
directive|define
name|t_args
value|t_u._t_args
end_define

begin_comment
comment|/*  * argument information  *  * Such a structure is created for each argument of a function call  * which is an integer constant or a constant string.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|arginf
block|{
name|int
name|a_num
decl_stmt|;
comment|/* # of argument (1..) */
name|u_int
name|a_zero
range|:
literal|1
decl_stmt|;
comment|/* argument is 0 */
name|u_int
name|a_pcon
range|:
literal|1
decl_stmt|;
comment|/* msb of argument is not set */
name|u_int
name|a_ncon
range|:
literal|1
decl_stmt|;
comment|/* msb of argument is set */
name|u_int
name|a_fmt
range|:
literal|1
decl_stmt|;
comment|/* a_fstrg points to format string */
name|char
modifier|*
name|a_fstrg
decl_stmt|;
comment|/* format string */
name|struct
name|arginf
modifier|*
name|a_nxt
decl_stmt|;
comment|/* information for next const. argument */
block|}
name|arginf_t
typedef|;
end_typedef

begin_comment
comment|/*  * Keeps information about position in source file.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|p_src
decl_stmt|;
comment|/* index of name of translation unit 				   (the name which was specified at the 				   command line) */
name|u_short
name|p_line
decl_stmt|;
comment|/* line number in p_src */
name|u_short
name|p_isrc
decl_stmt|;
comment|/* index of (included) file */
name|u_short
name|p_iline
decl_stmt|;
comment|/* line number in p_iline */
block|}
name|pos_t
typedef|;
end_typedef

begin_comment
comment|/*  * Used for definitions and declarations  *  * To save memory, variable sized structures are used. If  * all s_va, s_prfl and s_scfl are not set, the memory allocated  * for a symbol is only large enough to keep the first member of  * struct sym, s_s.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sym
block|{
struct|struct
block|{
name|pos_t
name|s_pos
decl_stmt|;
comment|/* pos of def./decl. */
ifndef|#
directive|ifndef
name|lint
name|u_int
name|s_def
range|:
literal|3
decl_stmt|;
comment|/* DECL, TDEF or DEF */
else|#
directive|else
name|def_t
name|s_def
decl_stmt|;
endif|#
directive|endif
name|u_int
name|s_rval
range|:
literal|1
decl_stmt|;
comment|/* function has return value */
name|u_int
name|s_osdef
range|:
literal|1
decl_stmt|;
comment|/* old style function definition */
name|u_int
name|s_static
range|:
literal|1
decl_stmt|;
comment|/* symbol is static */
name|u_int
name|s_va
range|:
literal|1
decl_stmt|;
comment|/* check only first s_nva arguments */
name|u_int
name|s_prfl
range|:
literal|1
decl_stmt|;
comment|/* printflike */
name|u_int
name|s_scfl
range|:
literal|1
decl_stmt|;
comment|/* scanflike */
name|u_short
name|s_type
decl_stmt|;
comment|/* type */
name|struct
name|sym
modifier|*
name|s_nxt
decl_stmt|;
comment|/* next symbol with same name */
block|}
name|s_s
struct|;
name|short
name|s_nva
decl_stmt|;
name|short
name|s_nprfl
decl_stmt|;
name|short
name|s_nscfl
decl_stmt|;
block|}
name|sym_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|s_pos
value|s_s.s_pos
end_define

begin_define
define|#
directive|define
name|s_rval
value|s_s.s_rval
end_define

begin_define
define|#
directive|define
name|s_osdef
value|s_s.s_osdef
end_define

begin_define
define|#
directive|define
name|s_static
value|s_s.s_static
end_define

begin_define
define|#
directive|define
name|s_def
value|s_s.s_def
end_define

begin_define
define|#
directive|define
name|s_va
value|s_s.s_va
end_define

begin_define
define|#
directive|define
name|s_prfl
value|s_s.s_prfl
end_define

begin_define
define|#
directive|define
name|s_scfl
value|s_s.s_scfl
end_define

begin_define
define|#
directive|define
name|s_type
value|s_s.s_type
end_define

begin_define
define|#
directive|define
name|s_nxt
value|s_s.s_nxt
end_define

begin_comment
comment|/*  * Used to store informations about function calls.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|fcall
block|{
name|pos_t
name|f_pos
decl_stmt|;
comment|/* position of call */
name|u_int
name|f_rused
range|:
literal|1
decl_stmt|;
comment|/* return value used */
name|u_int
name|f_rdisc
range|:
literal|1
decl_stmt|;
comment|/* return value discarded (casted to void) */
name|u_short
name|f_type
decl_stmt|;
comment|/* types of expected return value and args */
name|arginf_t
modifier|*
name|f_args
decl_stmt|;
comment|/* information about constant arguments */
name|struct
name|fcall
modifier|*
name|f_nxt
decl_stmt|;
comment|/* next call of same function */
block|}
name|fcall_t
typedef|;
end_typedef

begin_comment
comment|/*  * Used to store information about usage of symbols other  * than for function calls.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|usym
block|{
name|pos_t
name|u_pos
decl_stmt|;
comment|/* position */
name|struct
name|usym
modifier|*
name|u_nxt
decl_stmt|;
comment|/* next usage */
block|}
name|usym_t
typedef|;
end_typedef

begin_comment
comment|/*  * hash table entry  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hte
block|{
specifier|const
name|char
modifier|*
name|h_name
decl_stmt|;
comment|/* name */
name|u_int
name|h_used
range|:
literal|1
decl_stmt|;
comment|/* symbol is used */
name|u_int
name|h_def
range|:
literal|1
decl_stmt|;
comment|/* symbol is defined */
name|u_int
name|h_static
range|:
literal|1
decl_stmt|;
comment|/* static symbol */
name|sym_t
modifier|*
name|h_syms
decl_stmt|;
comment|/* declarations and definitions */
name|sym_t
modifier|*
modifier|*
name|h_lsym
decl_stmt|;
comment|/* points to s_nxt of last decl./def. */
name|fcall_t
modifier|*
name|h_calls
decl_stmt|;
comment|/* function calls */
name|fcall_t
modifier|*
modifier|*
name|h_lcall
decl_stmt|;
comment|/* points to f_nxt of last call */
name|usym_t
modifier|*
name|h_usyms
decl_stmt|;
comment|/* usage info */
name|usym_t
modifier|*
modifier|*
name|h_lusym
decl_stmt|;
comment|/* points to u_nxt of last usage info */
name|struct
name|hte
modifier|*
name|h_link
decl_stmt|;
comment|/* next hte with same hash function */
name|struct
name|hte
modifier|*
name|h_hte
decl_stmt|;
comment|/* pointer to other htes (for renames */
block|}
name|hte_t
typedef|;
end_typedef

begin_comment
comment|/* maps type indices into pointers to type structs */
end_comment

begin_define
define|#
directive|define
name|TP
parameter_list|(
name|idx
parameter_list|)
value|(tlst[idx])
end_define

begin_include
include|#
directive|include
file|"externs2.h"
end_include

end_unit

