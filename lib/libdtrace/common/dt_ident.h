begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_IDENT_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_IDENT_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<libctf.h>
end_include

begin_include
include|#
directive|include
file|<dtrace.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<dt_list.h>
struct_decl|struct
name|dt_node
struct_decl|;
struct_decl|struct
name|dt_ident
struct_decl|;
struct_decl|struct
name|dt_idhash
struct_decl|;
struct_decl|struct
name|dt_irlist
struct_decl|;
struct_decl|struct
name|dt_regset
struct_decl|;
typedef|typedef
struct|struct
name|dt_idsig
block|{
name|int
name|dis_varargs
decl_stmt|;
comment|/* argument index of start of varargs (or -1) */
name|int
name|dis_optargs
decl_stmt|;
comment|/* argument index of start of optargs (or -1) */
name|int
name|dis_argc
decl_stmt|;
comment|/* number of types in this signature */
name|struct
name|dt_node
modifier|*
name|dis_args
decl_stmt|;
comment|/* array of nodes representing formal types */
name|uint64_t
name|dis_auxinfo
decl_stmt|;
comment|/* auxiliary signature information, if any */
block|}
name|dt_idsig_t
typedef|;
typedef|typedef
struct|struct
name|dt_idnode
block|{
name|struct
name|dt_node
modifier|*
name|din_list
decl_stmt|;
comment|/* allocation list for parse tree nodes */
name|struct
name|dt_node
modifier|*
name|din_root
decl_stmt|;
comment|/* root of this identifier's parse tree */
name|struct
name|dt_idhash
modifier|*
name|din_hash
decl_stmt|;
comment|/* identifiers private to this subtree */
name|struct
name|dt_ident
modifier|*
modifier|*
name|din_argv
decl_stmt|;
comment|/* identifiers in din_hash for arguments */
name|int
name|din_argc
decl_stmt|;
comment|/* length of din_argv[] array */
block|}
name|dt_idnode_t
typedef|;
typedef|typedef
struct|struct
name|dt_idops
block|{
name|void
function_decl|(
modifier|*
name|di_cook
function_decl|)
parameter_list|(
name|struct
name|dt_node
modifier|*
parameter_list|,
name|struct
name|dt_ident
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|dt_node
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|di_dtor
function_decl|)
parameter_list|(
name|struct
name|dt_ident
modifier|*
parameter_list|)
function_decl|;
name|size_t
function_decl|(
modifier|*
name|di_size
function_decl|)
parameter_list|(
name|struct
name|dt_ident
modifier|*
parameter_list|)
function_decl|;
block|}
name|dt_idops_t
typedef|;
typedef|typedef
struct|struct
name|dt_ident
block|{
name|char
modifier|*
name|di_name
decl_stmt|;
comment|/* identifier name */
name|ushort_t
name|di_kind
decl_stmt|;
comment|/* identifier kind (see below) */
name|ushort_t
name|di_flags
decl_stmt|;
comment|/* identifier flags (see below) */
name|uint_t
name|di_id
decl_stmt|;
comment|/* variable or subr id (see<sys/dtrace.h>) */
name|dtrace_attribute_t
name|di_attr
decl_stmt|;
comment|/* identifier stability attributes */
name|uint_t
name|di_vers
decl_stmt|;
comment|/* identifier version number (dt_version_t) */
specifier|const
name|dt_idops_t
modifier|*
name|di_ops
decl_stmt|;
comment|/* identifier's class-specific ops vector */
name|void
modifier|*
name|di_iarg
decl_stmt|;
comment|/* initial argument pointer for ops vector */
name|void
modifier|*
name|di_data
decl_stmt|;
comment|/* private data pointer for ops vector */
name|ctf_file_t
modifier|*
name|di_ctfp
decl_stmt|;
comment|/* CTF container for the variable data type */
name|ctf_id_t
name|di_type
decl_stmt|;
comment|/* CTF identifier for the variable data type */
name|struct
name|dt_ident
modifier|*
name|di_next
decl_stmt|;
comment|/* pointer to next ident in hash chain */
name|ulong_t
name|di_gen
decl_stmt|;
comment|/* generation number (pass that created me) */
name|int
name|di_lineno
decl_stmt|;
comment|/* line number that defined this identifier */
block|}
name|dt_ident_t
typedef|;
define|#
directive|define
name|DT_IDENT_ARRAY
value|0
comment|/* identifier is an array variable */
define|#
directive|define
name|DT_IDENT_SCALAR
value|1
comment|/* identifier is a scalar variable */
define|#
directive|define
name|DT_IDENT_PTR
value|2
comment|/* identifier is a magic pointer */
define|#
directive|define
name|DT_IDENT_FUNC
value|3
comment|/* identifier is a built-in function */
define|#
directive|define
name|DT_IDENT_AGG
value|4
comment|/* identifier is an aggregation */
define|#
directive|define
name|DT_IDENT_AGGFUNC
value|5
comment|/* identifier is an aggregating function */
define|#
directive|define
name|DT_IDENT_ACTFUNC
value|6
comment|/* identifier is an action function */
define|#
directive|define
name|DT_IDENT_XLSOU
value|7
comment|/* identifier is a translated struct or union */
define|#
directive|define
name|DT_IDENT_XLPTR
value|8
comment|/* identifier is a translated pointer */
define|#
directive|define
name|DT_IDENT_SYMBOL
value|9
comment|/* identifier is an external symbol */
define|#
directive|define
name|DT_IDENT_ENUM
value|10
comment|/* identifier is an enumerator */
define|#
directive|define
name|DT_IDENT_PRAGAT
value|11
comment|/* identifier is #pragma attributes */
define|#
directive|define
name|DT_IDENT_PRAGBN
value|12
comment|/* identifier is #pragma binding */
define|#
directive|define
name|DT_IDENT_PROBE
value|13
comment|/* identifier is a probe definition */
define|#
directive|define
name|DT_IDFLG_TLS
value|0x0001
comment|/* variable is thread-local storage */
define|#
directive|define
name|DT_IDFLG_LOCAL
value|0x0002
comment|/* variable is local storage */
define|#
directive|define
name|DT_IDFLG_WRITE
value|0x0004
comment|/* variable is writable (can be modified) */
define|#
directive|define
name|DT_IDFLG_INLINE
value|0x0008
comment|/* variable is an inline definition */
define|#
directive|define
name|DT_IDFLG_REF
value|0x0010
comment|/* variable is referenced by this program */
define|#
directive|define
name|DT_IDFLG_MOD
value|0x0020
comment|/* variable is modified by this program */
define|#
directive|define
name|DT_IDFLG_DIFR
value|0x0040
comment|/* variable is referenced by current DIFO */
define|#
directive|define
name|DT_IDFLG_DIFW
value|0x0080
comment|/* variable is modified by current DIFO */
define|#
directive|define
name|DT_IDFLG_CGREG
value|0x0100
comment|/* variable is inlined by code generator */
define|#
directive|define
name|DT_IDFLG_USER
value|0x0200
comment|/* variable is associated with userland */
define|#
directive|define
name|DT_IDFLG_PRIM
value|0x0400
comment|/* variable is associated with primary object */
define|#
directive|define
name|DT_IDFLG_DECL
value|0x0800
comment|/* variable is associated with explicit decl */
define|#
directive|define
name|DT_IDFLG_ORPHAN
value|0x1000
comment|/* variable is in a dt_node and not dt_idhash */
typedef|typedef
struct|struct
name|dt_idhash
block|{
name|dt_list_t
name|dh_list
decl_stmt|;
comment|/* list prev/next pointers for dt_idstack */
specifier|const
name|char
modifier|*
name|dh_name
decl_stmt|;
comment|/* name of this hash table */
name|void
function_decl|(
modifier|*
name|dh_defer
function_decl|)
parameter_list|(
name|struct
name|dt_idhash
modifier|*
parameter_list|,
name|dt_ident_t
modifier|*
parameter_list|)
function_decl|;
comment|/* defer callback */
specifier|const
name|dt_ident_t
modifier|*
name|dh_tmpl
decl_stmt|;
comment|/* template for initial ident population */
name|uint_t
name|dh_nextid
decl_stmt|;
comment|/* next id to be returned by idhash_nextid() */
name|uint_t
name|dh_minid
decl_stmt|;
comment|/* min id to be returned by idhash_nextid() */
name|uint_t
name|dh_maxid
decl_stmt|;
comment|/* max id to be returned by idhash_nextid() */
name|ulong_t
name|dh_nelems
decl_stmt|;
comment|/* number of identifiers in hash table */
name|ulong_t
name|dh_hashsz
decl_stmt|;
comment|/* number of entries in dh_buckets array */
name|dt_ident_t
modifier|*
name|dh_hash
index|[
literal|1
index|]
decl_stmt|;
comment|/* array of hash table bucket pointers */
block|}
name|dt_idhash_t
typedef|;
typedef|typedef
struct|struct
name|dt_idstack
block|{
name|dt_list_t
name|dids_list
decl_stmt|;
comment|/* list meta-data for dt_idhash_t stack */
block|}
name|dt_idstack_t
typedef|;
specifier|extern
specifier|const
name|dt_idops_t
name|dt_idops_assc
decl_stmt|;
comment|/* associative array or aggregation */
specifier|extern
specifier|const
name|dt_idops_t
name|dt_idops_func
decl_stmt|;
comment|/* function call built-in */
specifier|extern
specifier|const
name|dt_idops_t
name|dt_idops_args
decl_stmt|;
comment|/* args[] built-in */
specifier|extern
specifier|const
name|dt_idops_t
name|dt_idops_regs
decl_stmt|;
comment|/* regs[]/uregs[] built-in */
specifier|extern
specifier|const
name|dt_idops_t
name|dt_idops_type
decl_stmt|;
comment|/* predefined type name string */
specifier|extern
specifier|const
name|dt_idops_t
name|dt_idops_thaw
decl_stmt|;
comment|/* prefrozen type identifier */
specifier|extern
specifier|const
name|dt_idops_t
name|dt_idops_inline
decl_stmt|;
comment|/* inline variable */
specifier|extern
specifier|const
name|dt_idops_t
name|dt_idops_probe
decl_stmt|;
comment|/* probe definition */
specifier|extern
name|dt_idhash_t
modifier|*
name|dt_idhash_create
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|dt_ident_t
modifier|*
parameter_list|,
name|uint_t
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_idhash_destroy
parameter_list|(
name|dt_idhash_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_idhash_update
parameter_list|(
name|dt_idhash_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_ident_t
modifier|*
name|dt_idhash_lookup
parameter_list|(
name|dt_idhash_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_idhash_nextid
parameter_list|(
name|dt_idhash_t
modifier|*
parameter_list|,
name|uint_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|ulong_t
name|dt_idhash_size
parameter_list|(
specifier|const
name|dt_idhash_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|char
modifier|*
name|dt_idhash_name
parameter_list|(
specifier|const
name|dt_idhash_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_ident_t
modifier|*
name|dt_idhash_insert
parameter_list|(
name|dt_idhash_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|ushort_t
parameter_list|,
name|ushort_t
parameter_list|,
name|uint_t
parameter_list|,
name|dtrace_attribute_t
parameter_list|,
name|uint_t
parameter_list|,
specifier|const
name|dt_idops_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|ulong_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_idhash_xinsert
parameter_list|(
name|dt_idhash_t
modifier|*
parameter_list|,
name|dt_ident_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_idhash_delete
parameter_list|(
name|dt_idhash_t
modifier|*
parameter_list|,
name|dt_ident_t
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|int
name|dt_idhash_f
parameter_list|(
name|dt_idhash_t
modifier|*
parameter_list|,
name|dt_ident_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_idhash_iter
parameter_list|(
name|dt_idhash_t
modifier|*
parameter_list|,
name|dt_idhash_f
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_ident_t
modifier|*
name|dt_idstack_lookup
parameter_list|(
name|dt_idstack_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_idstack_push
parameter_list|(
name|dt_idstack_t
modifier|*
parameter_list|,
name|dt_idhash_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_idstack_pop
parameter_list|(
name|dt_idstack_t
modifier|*
parameter_list|,
name|dt_idhash_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_ident_t
modifier|*
name|dt_ident_create
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|ushort_t
parameter_list|,
name|ushort_t
parameter_list|,
name|uint_t
parameter_list|,
name|dtrace_attribute_t
parameter_list|,
name|uint_t
parameter_list|,
specifier|const
name|dt_idops_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|ulong_t
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_ident_destroy
parameter_list|(
name|dt_ident_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_ident_morph
parameter_list|(
name|dt_ident_t
modifier|*
parameter_list|,
name|ushort_t
parameter_list|,
specifier|const
name|dt_idops_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dtrace_attribute_t
name|dt_ident_cook
parameter_list|(
name|struct
name|dt_node
modifier|*
parameter_list|,
name|dt_ident_t
modifier|*
parameter_list|,
name|struct
name|dt_node
modifier|*
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_ident_type_assign
parameter_list|(
name|dt_ident_t
modifier|*
parameter_list|,
name|ctf_file_t
modifier|*
parameter_list|,
name|ctf_id_t
parameter_list|)
function_decl|;
specifier|extern
name|dt_ident_t
modifier|*
name|dt_ident_resolve
parameter_list|(
name|dt_ident_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|size_t
name|dt_ident_size
parameter_list|(
name|dt_ident_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_ident_unref
parameter_list|(
specifier|const
name|dt_ident_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
specifier|const
name|char
modifier|*
name|dt_idkind_name
parameter_list|(
name|uint_t
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DT_IDENT_H */
end_comment

end_unit

