begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lint1.h,v 1.6 1995/10/02 17:31:41 jpo Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"lint.h"
end_include

begin_include
include|#
directive|include
file|"op.h"
end_include

begin_comment
comment|/*  * Describes the position of a declaration or anything else.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|p_line
decl_stmt|;
specifier|const
name|char
modifier|*
name|p_file
decl_stmt|;
block|}
name|pos_t
typedef|;
end_typedef

begin_comment
comment|/*  * Strings cannot be referenced to simply by a pointer to its first  * char. This is because strings can contain NUL characters other than the  * trailing NUL.  *  * Strings are stored with a trailing NUL.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|strg
block|{
name|tspec_t
name|st_tspec
decl_stmt|;
comment|/* CHAR or WCHAR */
name|size_t
name|st_len
decl_stmt|;
comment|/* length without trailing NUL */
union|union
block|{
name|u_char
modifier|*
name|_st_cp
decl_stmt|;
name|wchar_t
modifier|*
name|_st_wcp
decl_stmt|;
block|}
name|st_u
union|;
block|}
name|strg_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|st_cp
value|st_u._st_cp
end_define

begin_define
define|#
directive|define
name|st_wcp
value|st_u._st_wcp
end_define

begin_comment
comment|/*  * qualifiers (only for lex/yacc interface)  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CONST
block|,
name|VOLATILE
block|}
name|tqual_t
typedef|;
end_typedef

begin_comment
comment|/*  * Integer and floating point values are stored in this structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|tspec_t
name|v_tspec
decl_stmt|;
name|int
name|v_ansiu
decl_stmt|;
comment|/* set if an integer constant is 					   unsigned in ANSI C */
union|union
block|{
name|quad_t
name|_v_quad
decl_stmt|;
comment|/* integers */
name|ldbl_t
name|_v_ldbl
decl_stmt|;
comment|/* floats */
block|}
name|v_u
union|;
block|}
name|val_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|v_quad
value|v_u._v_quad
end_define

begin_define
define|#
directive|define
name|v_ldbl
value|v_u._v_ldbl
end_define

begin_comment
comment|/*  * Structures of type str_t uniqely identify structures. This can't  * be done in structures of type type_t, because these are copied  * if they must be modified. So it would not be possible to check  * if to structures are identical by comparing the pointers to  * the type structures.  *  * The typename is used if the structure is unnamed to identify  * the structure type in pass 2.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|size
decl_stmt|;
comment|/* size in bit */
name|u_int
name|align
range|:
literal|15
decl_stmt|;
comment|/* alignment in bit */
name|u_int
name|sincompl
range|:
literal|1
decl_stmt|;
comment|/* set if incomplete type */
name|struct
name|sym
modifier|*
name|memb
decl_stmt|;
comment|/* list of members */
name|struct
name|sym
modifier|*
name|stag
decl_stmt|;
comment|/* symbol table entry of tag */
name|struct
name|sym
modifier|*
name|stdef
decl_stmt|;
comment|/* symbol table entry of first typename */
block|}
name|str_t
typedef|;
end_typedef

begin_comment
comment|/*  * same as above for enums  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|eincompl
range|:
literal|1
decl_stmt|;
comment|/* incomplete enum type */
name|struct
name|sym
modifier|*
name|elem
decl_stmt|;
comment|/* list of enumerators */
name|struct
name|sym
modifier|*
name|etag
decl_stmt|;
comment|/* symbol table entry of tag */
name|struct
name|sym
modifier|*
name|etdef
decl_stmt|;
comment|/* symbol table entry of first typename */
block|}
name|enum_t
typedef|;
end_typedef

begin_comment
comment|/*  * Types are represented by concatenation of structures of type type_t  * via t_subt.  */
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
name|t_aincompl
range|:
literal|1
decl_stmt|;
comment|/* incomplete array type */
name|u_int
name|t_const
range|:
literal|1
decl_stmt|;
comment|/* const modifier */
name|u_int
name|t_volatile
range|:
literal|1
decl_stmt|;
comment|/* volatile modifier */
name|u_int
name|t_proto
range|:
literal|1
decl_stmt|;
comment|/* function prototype (t_args valid) */
name|u_int
name|t_vararg
range|:
literal|1
decl_stmt|;
comment|/* protoype with ... */
name|u_int
name|t_typedef
range|:
literal|1
decl_stmt|;
comment|/* type defined with typedef */
name|u_int
name|t_isfield
range|:
literal|1
decl_stmt|;
comment|/* type is bitfield */
name|u_int
name|t_isenum
range|:
literal|1
decl_stmt|;
comment|/* type is (or was) enum (t_enum valid) */
union|union
block|{
name|int
name|_t_dim
decl_stmt|;
comment|/* dimension */
name|str_t
modifier|*
name|_t_str
decl_stmt|;
comment|/* struct/union tag */
name|enum_t
modifier|*
name|_t_enum
decl_stmt|;
comment|/* enum tag */
name|struct
name|sym
modifier|*
name|_t_args
decl_stmt|;
comment|/* arguments (if t_proto) */
struct|struct
block|{
name|u_int
name|_t_flen
range|:
literal|8
decl_stmt|;
comment|/* length of bit-field */
name|u_int
name|_t_foffs
range|:
literal|24
decl_stmt|;
comment|/* offset of bit-field */
block|}
name|_t_u
struct|;
block|}
name|t_u
union|;
name|struct
name|type
modifier|*
name|t_subt
decl_stmt|;
comment|/* element type (arrays), return value 				   (functions), or type pointer points to */
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
name|t_str
value|t_u._t_str
end_define

begin_define
define|#
directive|define
name|t_field
value|t_u._t_field
end_define

begin_define
define|#
directive|define
name|t_enum
value|t_u._t_enum
end_define

begin_define
define|#
directive|define
name|t_args
value|t_u._t_args
end_define

begin_define
define|#
directive|define
name|t_flen
value|t_u._t_u._t_flen
end_define

begin_define
define|#
directive|define
name|t_foffs
value|t_u._t_u._t_foffs
end_define

begin_comment
comment|/*  * types of symbols  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|FVFT
block|,
comment|/* variables, functions, type names, enums */
name|FMOS
block|,
comment|/* members of structs or unions */
name|FTAG
block|,
comment|/* tags */
name|FLAB
comment|/* labels */
block|}
name|symt_t
typedef|;
end_typedef

begin_comment
comment|/*  * storage classes  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NOSCL
block|,
name|EXTERN
block|,
comment|/* external symbols (indep. of decl_t) */
name|STATIC
block|,
comment|/* static symbols (local and global) */
name|AUTO
block|,
comment|/* automatic symbols (except register) */
name|REG
block|,
comment|/* register */
name|TYPEDEF
block|,
comment|/* typedef */
name|STRTAG
block|,
name|UNIONTAG
block|,
name|ENUMTAG
block|,
name|MOS
block|,
comment|/* member of struct */
name|MOU
block|,
comment|/* member of union */
name|ENUMCON
block|,
comment|/* enumerator */
name|ABSTRACT
block|,
comment|/* abstract symbol (sizeof, casts, unnamed argument) */
name|ARG
block|,
comment|/* argument */
name|PARG
block|,
comment|/* used in declaration stack during prototype 			   declaration */
name|INLINE
comment|/* only used by the parser */
block|}
name|scl_t
typedef|;
end_typedef

begin_comment
comment|/*  * symbol table entry  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sym
block|{
specifier|const
name|char
modifier|*
name|s_name
decl_stmt|;
comment|/* name */
name|pos_t
name|s_dpos
decl_stmt|;
comment|/* position of last (prototype)definition, 				   prototypedeclaration, no-prototype-def., 				   tentative definition or declaration, 				   in this order */
name|pos_t
name|s_spos
decl_stmt|;
comment|/* position of first initialisation */
name|pos_t
name|s_upos
decl_stmt|;
comment|/* position of first use */
name|symt_t
name|s_kind
decl_stmt|;
comment|/* type of symbol */
name|u_int
name|s_keyw
range|:
literal|1
decl_stmt|;
comment|/* keyword */
name|u_int
name|s_field
range|:
literal|1
decl_stmt|;
comment|/* bit-field */
name|u_int
name|s_set
range|:
literal|1
decl_stmt|;
comment|/* variable set, label defined */
name|u_int
name|s_used
range|:
literal|1
decl_stmt|;
comment|/* variable/label used */
name|u_int
name|s_arg
range|:
literal|1
decl_stmt|;
comment|/* symbol is function argument */
name|u_int
name|s_reg
range|:
literal|1
decl_stmt|;
comment|/* symbol is register variable */
name|u_int
name|s_defarg
range|:
literal|1
decl_stmt|;
comment|/* undefined symbol in old style function 				   definition */
name|u_int
name|s_rimpl
range|:
literal|1
decl_stmt|;
comment|/* return value of function implizit decl. */
name|u_int
name|s_osdef
range|:
literal|1
decl_stmt|;
comment|/* symbol stems from old style function def. */
name|u_int
name|s_inline
range|:
literal|1
decl_stmt|;
comment|/* true if this is a inline function */
name|struct
name|sym
modifier|*
name|s_xsym
decl_stmt|;
comment|/* for local declared external symbols pointer 				   to external symbol with same name */
name|def_t
name|s_def
decl_stmt|;
comment|/* declared, tentative defined, defined */
name|scl_t
name|s_scl
decl_stmt|;
comment|/* storage class */
name|int
name|s_blklev
decl_stmt|;
comment|/* level of declaration, -1 if not in symbol 				   table */
name|type_t
modifier|*
name|s_type
decl_stmt|;
comment|/* type */
name|val_t
name|s_value
decl_stmt|;
comment|/* value (if enumcon) */
union|union
block|{
name|str_t
modifier|*
name|_s_st
decl_stmt|;
comment|/* tag, if it is a struct/union member */
name|enum_t
modifier|*
name|_s_et
decl_stmt|;
comment|/* tag, if it is a enumerator */
name|tspec_t
name|_s_tsp
decl_stmt|;
comment|/* type (only for keywords) */
name|tqual_t
name|_s_tqu
decl_stmt|;
comment|/* qualifier (only for keywords) */
name|struct
name|sym
modifier|*
name|_s_args
decl_stmt|;
comment|/* arguments in old style function 					 definitions */
block|}
name|u
union|;
name|struct
name|sym
modifier|*
name|s_link
decl_stmt|;
comment|/* next symbol with same hash value */
name|struct
name|sym
modifier|*
modifier|*
name|s_rlink
decl_stmt|;
comment|/* pointer to s_link of prev. symbol */
name|struct
name|sym
modifier|*
name|s_nxt
decl_stmt|;
comment|/* next struct/union member, enumerator, 				   argument */
name|struct
name|sym
modifier|*
name|s_dlnxt
decl_stmt|;
comment|/* next symbol declared on same level */
block|}
name|sym_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|s_styp
value|u._s_st
end_define

begin_define
define|#
directive|define
name|s_etyp
value|u._s_et
end_define

begin_define
define|#
directive|define
name|s_tspec
value|u._s_tsp
end_define

begin_define
define|#
directive|define
name|s_tqual
value|u._s_tqu
end_define

begin_define
define|#
directive|define
name|s_args
value|u._s_args
end_define

begin_comment
comment|/*  * Used to keep some informations about symbols before they are entered  * into the symbol table.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sbuf
block|{
specifier|const
name|char
modifier|*
name|sb_name
decl_stmt|;
comment|/* name of symbol */
name|size_t
name|sb_len
decl_stmt|;
comment|/* length (without '\0') */
name|int
name|sb_hash
decl_stmt|;
comment|/* hash value */
name|sym_t
modifier|*
name|sb_sym
decl_stmt|;
comment|/* symbol table entry */
name|struct
name|sbuf
modifier|*
name|sb_nxt
decl_stmt|;
comment|/* for freelist */
block|}
name|sbuf_t
typedef|;
end_typedef

begin_comment
comment|/*  * tree node  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|tnode
block|{
name|op_t
name|tn_op
decl_stmt|;
comment|/* operator */
name|type_t
modifier|*
name|tn_type
decl_stmt|;
comment|/* type */
name|u_int
name|tn_lvalue
range|:
literal|1
decl_stmt|;
comment|/* node is lvalue */
name|u_int
name|tn_cast
range|:
literal|1
decl_stmt|;
comment|/* if tn_op == CVT its an explizit cast */
name|u_int
name|tn_parn
range|:
literal|1
decl_stmt|;
comment|/* node parenthesized */
union|union
block|{
struct|struct
block|{
name|struct
name|tnode
modifier|*
name|_tn_left
decl_stmt|;
comment|/* (left) operand */
name|struct
name|tnode
modifier|*
name|_tn_right
decl_stmt|;
comment|/* right operand */
block|}
name|tn_s
struct|;
name|sym_t
modifier|*
name|_tn_sym
decl_stmt|;
comment|/* symbol if op == NAME */
name|val_t
modifier|*
name|_tn_val
decl_stmt|;
comment|/* value if op == CON */
name|strg_t
modifier|*
name|_tn_strg
decl_stmt|;
comment|/* string if op == STRING */
block|}
name|tn_u
union|;
block|}
name|tnode_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|tn_left
value|tn_u.tn_s._tn_left
end_define

begin_define
define|#
directive|define
name|tn_right
value|tn_u.tn_s._tn_right
end_define

begin_define
define|#
directive|define
name|tn_sym
value|tn_u._tn_sym
end_define

begin_define
define|#
directive|define
name|tn_val
value|tn_u._tn_val
end_define

begin_define
define|#
directive|define
name|tn_strg
value|tn_u._tn_strg
end_define

begin_comment
comment|/*  * For nested declarations a stack exists, which holds all information  * needed for the current level. dcs points to the top element of this  * stack.  *  * ctx describes the context of the current declaration. Its value is  * one of  *	EXTERN	global declarations  *	MOS oder MOU declarations of struct or union members  *	ENUMCON	declarations of enums  *	ARG	declaration of arguments in old style function definitions  *	PARG	declaration of arguments in function prototypes  *	AUTO	declaration of local symbols  *	ABSTRACT abstract declarations (sizeof, casts)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dinfo
block|{
name|tspec_t
name|d_atyp
decl_stmt|;
comment|/* VOID, CHAR, INT, FLOAT or DOUBLE */
name|tspec_t
name|d_smod
decl_stmt|;
comment|/* SIGNED or UNSIGN */
name|tspec_t
name|d_lmod
decl_stmt|;
comment|/* SHORT, LONG or QUAD */
name|scl_t
name|d_scl
decl_stmt|;
comment|/* storage class */
name|type_t
modifier|*
name|d_type
decl_stmt|;
comment|/* after deftyp() pointer to the type used 				   for all declarators */
name|sym_t
modifier|*
name|d_rdcsym
decl_stmt|;
comment|/* redeclared symbol */
name|int
name|d_offset
decl_stmt|;
comment|/* offset of next structure member */
name|int
name|d_stralign
decl_stmt|;
comment|/* alignment required for current structure */
name|scl_t
name|d_ctx
decl_stmt|;
comment|/* context of declaration */
name|u_int
name|d_const
range|:
literal|1
decl_stmt|;
comment|/* const in declaration specifiers */
name|u_int
name|d_volatile
range|:
literal|1
decl_stmt|;
comment|/* volatile in declaration specifiers */
name|u_int
name|d_inline
range|:
literal|1
decl_stmt|;
comment|/* inline in declaration specifiers */
name|u_int
name|d_mscl
range|:
literal|1
decl_stmt|;
comment|/* multiple storage classes */
name|u_int
name|d_terr
range|:
literal|1
decl_stmt|;
comment|/* invalid type combination */
name|u_int
name|d_nedecl
range|:
literal|1
decl_stmt|;
comment|/* 1 if at least a tag is declared */
name|u_int
name|d_vararg
range|:
literal|1
decl_stmt|;
comment|/* ... in in current function decl. */
name|u_int
name|d_proto
range|:
literal|1
decl_stmt|;
comment|/* current funct. decl. is prototype */
name|u_int
name|d_notyp
range|:
literal|1
decl_stmt|;
comment|/* set if no type specifier was present */
name|u_int
name|d_asm
range|:
literal|1
decl_stmt|;
comment|/* set if d_ctx == AUTO and asm() present */
name|type_t
modifier|*
name|d_tagtyp
decl_stmt|;
comment|/* tag during member declaration */
name|sym_t
modifier|*
name|d_fargs
decl_stmt|;
comment|/* list of arguments during function def. */
name|pos_t
name|d_fdpos
decl_stmt|;
comment|/* position of function definition */
name|sym_t
modifier|*
name|d_dlsyms
decl_stmt|;
comment|/* first symbol declared at this level */
name|sym_t
modifier|*
modifier|*
name|d_ldlsym
decl_stmt|;
comment|/* points to s_dlnxt in last symbol decl. 				   at this level */
name|sym_t
modifier|*
name|d_fpsyms
decl_stmt|;
comment|/* symbols defined in prototype */
name|struct
name|dinfo
modifier|*
name|d_nxt
decl_stmt|;
comment|/* next level */
block|}
name|dinfo_t
typedef|;
end_typedef

begin_comment
comment|/*  * Type of stack which is used for initialisation of aggregate types.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|istk
block|{
name|type_t
modifier|*
name|i_type
decl_stmt|;
comment|/* type of initialisation */
name|type_t
modifier|*
name|i_subt
decl_stmt|;
comment|/* type of next level */
name|u_int
name|i_brace
range|:
literal|1
decl_stmt|;
comment|/* need } for pop */
name|u_int
name|i_nolimit
range|:
literal|1
decl_stmt|;
comment|/* incomplete array type */
name|sym_t
modifier|*
name|i_mem
decl_stmt|;
comment|/* next structure member */
name|int
name|i_cnt
decl_stmt|;
comment|/* # of remaining elements */
name|struct
name|istk
modifier|*
name|i_nxt
decl_stmt|;
comment|/* previous level */
block|}
name|istk_t
typedef|;
end_typedef

begin_comment
comment|/*  * Used to collect information about pointers and qualifiers in  * declarators.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pqinf
block|{
name|int
name|p_pcnt
decl_stmt|;
comment|/* number of asterisks */
name|u_int
name|p_const
range|:
literal|1
decl_stmt|;
name|u_int
name|p_volatile
range|:
literal|1
decl_stmt|;
name|struct
name|pqinf
modifier|*
name|p_nxt
decl_stmt|;
block|}
name|pqinf_t
typedef|;
end_typedef

begin_comment
comment|/*  * Case values are stored in a list of type clst_t.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|clst
block|{
name|val_t
name|cl_val
decl_stmt|;
name|struct
name|clst
modifier|*
name|cl_nxt
decl_stmt|;
block|}
name|clst_t
typedef|;
end_typedef

begin_comment
comment|/*  * Used to keep informations about nested control statements.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cstk
block|{
name|int
name|c_env
decl_stmt|;
comment|/* type of statement (T_IF, ...) */
name|u_int
name|c_loop
range|:
literal|1
decl_stmt|;
comment|/* continue&& break are valid */
name|u_int
name|c_switch
range|:
literal|1
decl_stmt|;
comment|/* case&& break are valid */
name|u_int
name|c_break
range|:
literal|1
decl_stmt|;
comment|/* loop/switch has break */
name|u_int
name|c_cont
range|:
literal|1
decl_stmt|;
comment|/* loop has continue */
name|u_int
name|c_default
range|:
literal|1
decl_stmt|;
comment|/* switch has default */
name|u_int
name|c_infinite
range|:
literal|1
decl_stmt|;
comment|/* break condition always false 					   (for (;;), while (1)) */
name|u_int
name|c_rchif
range|:
literal|1
decl_stmt|;
comment|/* end of if-branch reached */
name|u_int
name|c_noretval
range|:
literal|1
decl_stmt|;
comment|/* had "return;" */
name|u_int
name|c_retval
range|:
literal|1
decl_stmt|;
comment|/* had "return (e);" */
name|type_t
modifier|*
name|c_swtype
decl_stmt|;
comment|/* type of switch expression */
name|clst_t
modifier|*
name|c_clst
decl_stmt|;
comment|/* list of case values */
name|struct
name|mbl
modifier|*
name|c_fexprm
decl_stmt|;
comment|/* saved memory for end of loop 					   expression in for() */
name|tnode_t
modifier|*
name|c_f3expr
decl_stmt|;
comment|/* end of loop expr in for() */
name|pos_t
name|c_fpos
decl_stmt|;
comment|/* position of end of loop expr */
name|pos_t
name|c_cfpos
decl_stmt|;
comment|/* same for csrc_pos */
name|struct
name|cstk
modifier|*
name|c_nxt
decl_stmt|;
comment|/* outer control statement */
block|}
name|cstk_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"externs1.h"
end_include

end_unit

