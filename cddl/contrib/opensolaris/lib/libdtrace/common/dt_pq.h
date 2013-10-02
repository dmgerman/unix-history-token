begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * This file and its contents are supplied under the terms of the  * Common Development and Distribution License ("CDDL"), version 1.0.  * You may only use this file in accordance with the terms of version  * 1.0 of the CDDL.  *  * A full copy of the text of the CDDL should have accompanied this  * source.  A copy of the CDDL is also available via the Internet at  * http://www.illumos.org/license/CDDL.  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2012 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_PQ_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_PQ_H
end_define

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
typedef|typedef
name|uint64_t
function_decl|(
modifier|*
name|dt_pq_value_f
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
struct|struct
name|dt_pq
block|{
name|dtrace_hdl_t
modifier|*
name|dtpq_hdl
decl_stmt|;
comment|/* dtrace handle */
name|void
modifier|*
modifier|*
name|dtpq_items
decl_stmt|;
comment|/* array of elements */
name|uint_t
name|dtpq_size
decl_stmt|;
comment|/* count of allocated elements */
name|uint_t
name|dtpq_last
decl_stmt|;
comment|/* next free slot */
name|dt_pq_value_f
name|dtpq_value
decl_stmt|;
comment|/* callback to get the value */
name|void
modifier|*
name|dtpq_arg
decl_stmt|;
comment|/* callback argument */
block|}
name|dt_pq_t
typedef|;
specifier|extern
name|dt_pq_t
modifier|*
name|dt_pq_init
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|,
name|uint_t
name|size
parameter_list|,
name|dt_pq_value_f
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_pq_fini
parameter_list|(
name|dt_pq_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_pq_insert
parameter_list|(
name|dt_pq_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|dt_pq_pop
parameter_list|(
name|dt_pq_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
modifier|*
name|dt_pq_walk
parameter_list|(
name|dt_pq_t
modifier|*
parameter_list|,
name|uint_t
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
comment|/* _DT_PQ_H */
end_comment

end_unit

