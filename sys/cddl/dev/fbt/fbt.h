begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  *  * Portions Copyright 2006-2008 John Birrell jb@freebsd.org  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FBT_H_
end_ifndef

begin_define
define|#
directive|define
name|_FBT_H_
end_define

begin_include
include|#
directive|include
file|"fbt_isa.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|fbt_probe
block|{
name|struct
name|fbt_probe
modifier|*
name|fbtp_hashnext
decl_stmt|;
name|fbt_patchval_t
modifier|*
name|fbtp_patchpoint
decl_stmt|;
name|int8_t
name|fbtp_rval
decl_stmt|;
name|fbt_patchval_t
name|fbtp_patchval
decl_stmt|;
name|fbt_patchval_t
name|fbtp_savedval
decl_stmt|;
name|uintptr_t
name|fbtp_roffset
decl_stmt|;
name|dtrace_id_t
name|fbtp_id
decl_stmt|;
specifier|const
name|char
modifier|*
name|fbtp_name
decl_stmt|;
name|modctl_t
modifier|*
name|fbtp_ctl
decl_stmt|;
name|int
name|fbtp_loadcnt
decl_stmt|;
name|int
name|fbtp_primary
decl_stmt|;
name|int
name|fbtp_invop_cnt
decl_stmt|;
name|int
name|fbtp_symindx
decl_stmt|;
name|struct
name|fbt_probe
modifier|*
name|fbtp_next
decl_stmt|;
block|}
name|fbt_probe_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|linker_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|linker_symval
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|fbt_invop
parameter_list|(
name|uintptr_t
parameter_list|,
name|uintptr_t
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fbt_patch_tracepoint
parameter_list|(
name|fbt_probe_t
modifier|*
parameter_list|,
name|fbt_patchval_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fbt_provide_module_function
parameter_list|(
name|struct
name|linker_file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|linker_symval
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|dtrace_provider_id_t
name|fbt_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fbt_probe_t
modifier|*
modifier|*
name|fbt_probetab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fbt_probetab_mask
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FBT_ADDR2NDX
parameter_list|(
name|addr
parameter_list|)
value|((((uintptr_t)(addr))>> 4)& fbt_probetab_mask)
end_define

begin_define
define|#
directive|define
name|FBT_PROBETAB_SIZE
value|0x8000
end_define

begin_comment
comment|/* 32k entries -- 128K total */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_FBT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

