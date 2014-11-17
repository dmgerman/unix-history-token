begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_PROVIDER_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_PROVIDER_H
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
file|<dt_impl.h>
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
typedef|typedef
struct|struct
name|dt_provider
block|{
name|dt_list_t
name|pv_list
decl_stmt|;
comment|/* list forward/back pointers */
name|struct
name|dt_provider
modifier|*
name|pv_next
decl_stmt|;
comment|/* pointer to next provider in hash */
name|dtrace_providerdesc_t
name|pv_desc
decl_stmt|;
comment|/* provider name and attributes */
name|dt_idhash_t
modifier|*
name|pv_probes
decl_stmt|;
comment|/* probe defs (if user-declared) */
name|dt_node_t
modifier|*
name|pv_nodes
decl_stmt|;
comment|/* parse node allocation list */
name|ulong_t
modifier|*
name|pv_xrefs
decl_stmt|;
comment|/* translator reference bitmap */
name|ulong_t
name|pv_xrmax
decl_stmt|;
comment|/* number of valid bits in pv_xrefs */
name|ulong_t
name|pv_gen
decl_stmt|;
comment|/* generation # that created me */
name|dtrace_hdl_t
modifier|*
name|pv_hdl
decl_stmt|;
comment|/* pointer to containing dtrace_hdl */
name|uint_t
name|pv_flags
decl_stmt|;
comment|/* flags (see below) */
block|}
name|dt_provider_t
typedef|;
define|#
directive|define
name|DT_PROVIDER_INTF
value|0x1
comment|/* provider interface declaration */
define|#
directive|define
name|DT_PROVIDER_IMPL
value|0x2
comment|/* provider implementation is loaded */
typedef|typedef
struct|struct
name|dt_probe_iter
block|{
name|dtrace_probedesc_t
name|pit_desc
decl_stmt|;
comment|/* description storage */
name|dtrace_hdl_t
modifier|*
name|pit_hdl
decl_stmt|;
comment|/* libdtrace handle */
name|dt_provider_t
modifier|*
name|pit_pvp
decl_stmt|;
comment|/* current provider */
specifier|const
name|char
modifier|*
name|pit_pat
decl_stmt|;
comment|/* caller's name pattern (or NULL) */
name|dtrace_probe_f
modifier|*
name|pit_func
decl_stmt|;
comment|/* caller's function */
name|void
modifier|*
name|pit_arg
decl_stmt|;
comment|/* caller's argument */
name|uint_t
name|pit_matches
decl_stmt|;
comment|/* number of matches */
block|}
name|dt_probe_iter_t
typedef|;
typedef|typedef
struct|struct
name|dt_probe_instance
block|{
name|char
modifier|*
name|pi_fname
decl_stmt|;
comment|/* function name */
name|char
modifier|*
name|pi_rname
decl_stmt|;
comment|/* mangled relocation name */
name|uint32_t
modifier|*
name|pi_offs
decl_stmt|;
comment|/* offsets into the function */
name|uint32_t
modifier|*
name|pi_enoffs
decl_stmt|;
comment|/* is-enabled offsets */
name|uint_t
name|pi_noffs
decl_stmt|;
comment|/* number of offsets */
name|uint_t
name|pi_maxoffs
decl_stmt|;
comment|/* size of pi_offs allocation */
name|uint_t
name|pi_nenoffs
decl_stmt|;
comment|/* number of is-enabled offsets */
name|uint_t
name|pi_maxenoffs
decl_stmt|;
comment|/* size of pi_enoffs allocation */
name|struct
name|dt_probe_instance
modifier|*
name|pi_next
decl_stmt|;
comment|/* next instance in the list */
block|}
name|dt_probe_instance_t
typedef|;
typedef|typedef
struct|struct
name|dt_probe
block|{
name|dt_provider_t
modifier|*
name|pr_pvp
decl_stmt|;
comment|/* pointer to containing provider */
name|dt_ident_t
modifier|*
name|pr_ident
decl_stmt|;
comment|/* pointer to probe identifier */
specifier|const
name|char
modifier|*
name|pr_name
decl_stmt|;
comment|/* pointer to name component */
name|dt_node_t
modifier|*
name|pr_nargs
decl_stmt|;
comment|/* native argument list */
name|dt_node_t
modifier|*
modifier|*
name|pr_nargv
decl_stmt|;
comment|/* native argument vector */
name|uint_t
name|pr_nargc
decl_stmt|;
comment|/* native argument count */
name|dt_node_t
modifier|*
name|pr_xargs
decl_stmt|;
comment|/* translated argument list */
name|dt_node_t
modifier|*
modifier|*
name|pr_xargv
decl_stmt|;
comment|/* translated argument vector */
name|uint_t
name|pr_xargc
decl_stmt|;
comment|/* translated argument count */
name|uint8_t
modifier|*
name|pr_mapping
decl_stmt|;
comment|/* translated argument mapping */
name|dt_probe_instance_t
modifier|*
name|pr_inst
decl_stmt|;
comment|/* list of functions and offsets */
name|dtrace_typeinfo_t
modifier|*
name|pr_argv
decl_stmt|;
comment|/* output argument types */
name|int
name|pr_argc
decl_stmt|;
comment|/* output argument count */
block|}
name|dt_probe_t
typedef|;
specifier|extern
name|dt_provider_t
modifier|*
name|dt_provider_lookup
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_provider_t
modifier|*
name|dt_provider_create
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_provider_destroy
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dt_provider_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_provider_xref
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dt_provider_t
modifier|*
parameter_list|,
name|id_t
parameter_list|)
function_decl|;
specifier|extern
name|dt_probe_t
modifier|*
name|dt_probe_create
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dt_ident_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|dt_node_t
modifier|*
parameter_list|,
name|uint_t
parameter_list|,
name|dt_node_t
modifier|*
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|dt_probe_t
modifier|*
name|dt_probe_info
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
specifier|const
name|dtrace_probedesc_t
modifier|*
parameter_list|,
name|dtrace_probeinfo_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dt_probe_t
modifier|*
name|dt_probe_lookup
parameter_list|(
name|dt_provider_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_probe_declare
parameter_list|(
name|dt_provider_t
modifier|*
parameter_list|,
name|dt_probe_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_probe_destroy
parameter_list|(
name|dt_probe_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_probe_define
parameter_list|(
name|dt_provider_t
modifier|*
parameter_list|,
name|dt_probe_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
specifier|extern
name|dt_node_t
modifier|*
name|dt_probe_tag
parameter_list|(
name|dt_probe_t
modifier|*
parameter_list|,
name|uint_t
parameter_list|,
name|dt_node_t
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
comment|/* _DT_PROVIDER_H */
end_comment

end_unit

