begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_INTTAB_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_INTTAB_H
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
struct|struct
name|dt_inthash
block|{
name|struct
name|dt_inthash
modifier|*
name|inh_hash
decl_stmt|;
comment|/* next dt_inthash in hash chain */
name|struct
name|dt_inthash
modifier|*
name|inh_next
decl_stmt|;
comment|/* next dt_inthash in output table */
name|uint64_t
name|inh_value
decl_stmt|;
comment|/* value associated with this element */
name|uint_t
name|inh_index
decl_stmt|;
comment|/* index associated with this element */
name|uint_t
name|inh_flags
decl_stmt|;
comment|/* flags (see below) */
block|}
name|dt_inthash_t
typedef|;
typedef|typedef
struct|struct
name|dt_inttab
block|{
name|dtrace_hdl_t
modifier|*
name|int_hdl
decl_stmt|;
comment|/* pointer back to library handle */
name|dt_inthash_t
modifier|*
modifier|*
name|int_hash
decl_stmt|;
comment|/* array of hash buckets */
name|uint_t
name|int_hashlen
decl_stmt|;
comment|/* size of hash bucket array */
name|uint_t
name|int_nelems
decl_stmt|;
comment|/* number of elements hashed */
name|dt_inthash_t
modifier|*
name|int_head
decl_stmt|;
comment|/* head of table in index order */
name|dt_inthash_t
modifier|*
name|int_tail
decl_stmt|;
comment|/* tail of table in index order */
name|uint_t
name|int_index
decl_stmt|;
comment|/* next index to hand out */
block|}
name|dt_inttab_t
typedef|;
define|#
directive|define
name|DT_INT_PRIVATE
value|0
comment|/* only a single ref for this entry */
define|#
directive|define
name|DT_INT_SHARED
value|1
comment|/* multiple refs can share entry */
specifier|extern
name|dt_inttab_t
modifier|*
name|dt_inttab_create
parameter_list|(
name|dtrace_hdl_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_inttab_destroy
parameter_list|(
name|dt_inttab_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|dt_inttab_insert
parameter_list|(
name|dt_inttab_t
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|uint_t
parameter_list|)
function_decl|;
specifier|extern
name|uint_t
name|dt_inttab_size
parameter_list|(
specifier|const
name|dt_inttab_t
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|dt_inttab_write
parameter_list|(
specifier|const
name|dt_inttab_t
modifier|*
parameter_list|,
name|uint64_t
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
comment|/* _DT_INTTAB_H */
end_comment

end_unit

