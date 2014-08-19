begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2005 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013 by Delphix. All rights reserved.  * Copyright (c) 2013 Joyent, Inc. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_DECL_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_DECL_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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

begin_include
include|#
directive|include
file|<stdio.h>
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
struct_decl|struct
name|dt_node
struct_decl|;
comment|/* forward declaration of dt_node_t */
typedef|typedef
struct|struct
name|dt_decl
block|{
name|ushort_t
name|dd_kind
decl_stmt|;
comment|/* declaration kind (CTF_K_* kind) */
name|ushort_t
name|dd_attr
decl_stmt|;
comment|/* attributes (DT_DA_* flags) */
name|ctf_file_t
modifier|*
name|dd_ctfp
decl_stmt|;
comment|/* CTF container for decl's type */
name|ctf_id_t
name|dd_type
decl_stmt|;
comment|/* CTF identifier for decl's type */
name|char
modifier|*
name|dd_name
decl_stmt|;
comment|/* string name of this decl (or NULL) */
name|struct
name|dt_node
modifier|*
name|dd_node
decl_stmt|;
comment|/* node for array size or parm list */
name|struct
name|dt_decl
modifier|*
name|dd_next
decl_stmt|;
comment|/* next declaration in list */
block|}
name|dt_decl_t
typedef|;
define|#
directive|define
name|DT_DA_SIGNED
value|0x0001
comment|/* signed integer value */
define|#
directive|define
name|DT_DA_UNSIGNED
value|0x0002
comment|/* unsigned integer value */
define|#
directive|define
name|DT_DA_SHORT
value|0x0004
comment|/* short integer value */
define|#
directive|define
name|DT_DA_LONG
value|0x0008
comment|/* long integer or double */
define|#
directive|define
name|DT_DA_LONGLONG
value|0x0010
comment|/* long long integer value */
define|#
directive|define
name|DT_DA_CONST
value|0x0020
comment|/* qualify type as const */
define|#
directive|define
name|DT_DA_RESTRICT
value|0x0040
comment|/* qualify type as restrict */
define|#
directive|define
name|DT_DA_VOLATILE
value|0x0080
comment|/* qualify type as volatile */
define|#
directive|define
name|DT_DA_PAREN
value|0x0100
comment|/* parenthesis tag */
define|#
directive|define
name|DT_DA_USER
value|0x0200
comment|/* user-land type specifier */
typedef|typedef
enum|enum
name|dt_dclass
block|{
name|DT_DC_DEFAULT
block|,
comment|/* no storage class specified */
name|DT_DC_AUTO
block|,
comment|/* automatic storage */
name|DT_DC_REGISTER
block|,
comment|/* register storage */
name|DT_DC_STATIC
block|,
comment|/* static storage */
name|DT_DC_EXTERN
block|,
comment|/* extern storage */
name|DT_DC_TYPEDEF
block|,
comment|/* type definition */
name|DT_DC_SELF
block|,
comment|/* thread-local storage */
name|DT_DC_THIS
comment|/* clause-local storage */
block|}
name|dt_dclass_t
typedef|;
typedef|typedef
struct|struct
name|dt_scope
block|{
name|dt_decl_t
modifier|*
name|ds_decl
decl_stmt|;
comment|/* pointer to top of decl stack */
name|struct
name|dt_scope
modifier|*
name|ds_next
decl_stmt|;
comment|/* pointer to next scope */
name|char
modifier|*
name|ds_ident
decl_stmt|;
comment|/* identifier for this scope (if any) */
name|ctf_file_t
modifier|*
name|ds_ctfp
decl_stmt|;
comment|/* CTF container for this scope */
name|ctf_id_t
name|ds_type
decl_stmt|;
comment|/* CTF id of enclosing type */
name|dt_dclass_t
name|ds_class
decl_stmt|;
comment|/* declaration class for this scope */
name|int
name|ds_enumval
decl_stmt|;
comment|/* most recent enumerator value */
block|}
name|dt_scope_t
typedef|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_alloc
parameter_list|(
name|ushort_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_decl_free
parameter_list|(
name|dt_decl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_decl_reset
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_push
parameter_list|(
name|dt_decl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_pop
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_pop_param
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_top
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_ident
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_decl_class
parameter_list|(
name|dt_dclass_t
parameter_list|)
function_decl|;
define|#
directive|define
name|DT_DP_VARARGS
value|0x1
comment|/* permit varargs in prototype */
define|#
directive|define
name|DT_DP_DYNAMIC
value|0x2
comment|/* permit dynamic type in prototype */
define|#
directive|define
name|DT_DP_VOID
value|0x4
comment|/* permit void type in prototype */
define|#
directive|define
name|DT_DP_ANON
value|0x8
comment|/* permit anonymous parameters */
specifier|extern
name|int
name|dt_decl_prototype
parameter_list|(
name|struct
name|dt_node
modifier|*
parameter_list|,
name|struct
name|dt_node
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_spec
parameter_list|(
name|ushort_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_attr
parameter_list|(
name|ushort_t
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_array
parameter_list|(
name|struct
name|dt_node
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_func
parameter_list|(
name|dt_decl_t
modifier|*
parameter_list|,
name|struct
name|dt_node
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_ptr
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_sou
parameter_list|(
name|uint_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_decl_member
parameter_list|(
name|struct
name|dt_node
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_decl_enum
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_decl_enumerator
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|dt_node
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_decl_type
parameter_list|(
name|dt_decl_t
modifier|*
parameter_list|,
name|dtrace_typeinfo_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_scope_create
parameter_list|(
name|dt_scope_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_scope_destroy
parameter_list|(
name|dt_scope_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_scope_push
parameter_list|(
name|ctf_file_t
modifier|*
parameter_list|,
name|ctf_id_t
parameter_list|)
function_decl|;
specifier|extern
name|dt_decl_t
modifier|*
name|dt_scope_pop
parameter_list|(
name|void
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
comment|/* _DT_DECL_H */
end_comment

end_unit

