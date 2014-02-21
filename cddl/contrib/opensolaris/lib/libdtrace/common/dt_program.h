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
name|_DT_PROGRAM_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_PROGRAM_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

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
file|<dtrace.h>
include|#
directive|include
file|<dt_list.h>
typedef|typedef
struct|struct
name|dt_stmt
block|{
name|dt_list_t
name|ds_list
decl_stmt|;
comment|/* list forward/back pointers */
name|dtrace_stmtdesc_t
modifier|*
name|ds_desc
decl_stmt|;
comment|/* pointer to statement description */
block|}
name|dt_stmt_t
typedef|;
struct|struct
name|dtrace_prog
block|{
name|dt_list_t
name|dp_list
decl_stmt|;
comment|/* list forward/back pointers */
name|dt_list_t
name|dp_stmts
decl_stmt|;
comment|/* linked list of dt_stmt_t's */
name|ulong_t
modifier|*
modifier|*
name|dp_xrefs
decl_stmt|;
comment|/* array of translator reference bitmaps */
name|uint_t
name|dp_xrefslen
decl_stmt|;
comment|/* length of dp_xrefs array */
name|uint8_t
name|dp_dofversion
decl_stmt|;
comment|/* DOF version this program requires */
block|}
struct|;
specifier|extern
name|dtrace_prog_t
modifier|*
name|dt_program_create
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_program_destroy
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dtrace_prog_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|dtrace_ecbdesc_t
modifier|*
name|dt_ecbdesc_create
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
specifier|const
name|dtrace_probedesc_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_ecbdesc_release
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|dtrace_ecbdesc_t
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
comment|/* _DT_PROGRAM_H */
end_comment

end_unit

