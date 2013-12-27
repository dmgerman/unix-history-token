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
name|_DT_XLATOR_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_XLATOR_H
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

begin_include
include|#
directive|include
file|<dt_ident.h>
end_include

begin_include
include|#
directive|include
file|<dt_list.h>
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
typedef|typedef
struct|struct
name|dt_xlator
block|{
name|dt_list_t
name|dx_list
decl_stmt|;
comment|/* list forward/back pointers */
name|dt_idhash_t
modifier|*
name|dx_locals
decl_stmt|;
comment|/* hash of local scope identifiers */
name|dt_ident_t
modifier|*
name|dx_ident
decl_stmt|;
comment|/* identifier ref for input param */
name|dt_ident_t
name|dx_souid
decl_stmt|;
comment|/* fake identifier for sou output */
name|dt_ident_t
name|dx_ptrid
decl_stmt|;
comment|/* fake identifier for ptr output */
name|ctf_file_t
modifier|*
name|dx_src_ctfp
decl_stmt|;
comment|/* CTF container for input type */
name|ctf_id_t
name|dx_src_type
decl_stmt|;
comment|/* CTF reference for input type */
name|ctf_id_t
name|dx_src_base
decl_stmt|;
comment|/* CTF reference for input base */
name|ctf_file_t
modifier|*
name|dx_dst_ctfp
decl_stmt|;
comment|/* CTF container for output type */
name|ctf_id_t
name|dx_dst_type
decl_stmt|;
comment|/* CTF reference for output type */
name|ctf_id_t
name|dx_dst_base
decl_stmt|;
comment|/* CTF reference for output base */
name|struct
name|dt_node
modifier|*
name|dx_members
decl_stmt|;
comment|/* list of member translations */
name|uint_t
name|dx_nmembers
decl_stmt|;
comment|/* length of dx_members list */
name|dtrace_difo_t
modifier|*
modifier|*
name|dx_membdif
decl_stmt|;
comment|/* DIF for member expressions */
name|struct
name|dt_node
modifier|*
name|dx_nodes
decl_stmt|;
comment|/* list of parse tree nodes */
name|dtrace_hdl_t
modifier|*
name|dx_hdl
decl_stmt|;
comment|/* back pointer to containing handle */
name|ulong_t
name|dx_gen
decl_stmt|;
comment|/* generation number that created me */
name|id_t
name|dx_id
decl_stmt|;
comment|/* global translator id */
name|int
name|dx_arg
decl_stmt|;
comment|/* dynamic argument index */
block|}
name|dt_xlator_t
typedef|;
specifier|extern
name|dt_xlator_t
modifier|*
name|dt_xlator_create
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
specifier|const
name|dtrace_typeinfo_t
modifier|*
parameter_list|,
specifier|const
name|dtrace_typeinfo_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|dt_node
modifier|*
parameter_list|,
name|struct
name|dt_node
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_xlator_destroy
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dt_xlator_t
modifier|*
parameter_list|)
function_decl|;
define|#
directive|define
name|DT_XLATE_FUZZY
value|0x0
comment|/* lookup any matching translator */
define|#
directive|define
name|DT_XLATE_EXACT
value|0x1
comment|/* lookup only exact type matches */
define|#
directive|define
name|DT_XLATE_EXTERN
value|0x2
comment|/* extern translator if none exists */
specifier|extern
name|dt_xlator_t
modifier|*
name|dt_xlator_lookup
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|struct
name|dt_node
modifier|*
parameter_list|,
name|struct
name|dt_node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|dt_xlator_t
modifier|*
name|dt_xlator_lookup_id
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|id_t
parameter_list|)
function_decl|;
specifier|extern
name|dt_ident_t
modifier|*
name|dt_xlator_ident
parameter_list|(
name|dt_xlator_t
modifier|*
parameter_list|,
name|ctf_file_t
modifier|*
parameter_list|,
name|ctf_id_t
parameter_list|)
function_decl|;
specifier|extern
name|struct
name|dt_node
modifier|*
name|dt_xlator_member
parameter_list|(
name|dt_xlator_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_xlator_dynamic
parameter_list|(
specifier|const
name|dt_xlator_t
modifier|*
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
comment|/* _DT_XLATOR_H */
end_comment

end_unit

