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
name|_NVPAIR_IMPL_H
end_ifndef

begin_define
define|#
directive|define
name|_NVPAIR_IMPL_H
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
file|<sys/nvpair.h>
comment|/*  * The structures here provided for information and debugging purposes only  * may be changed in the future.  */
comment|/*  * implementation linked list for pre-packed data  */
typedef|typedef
name|struct
name|i_nvp
name|i_nvp_t
typedef|;
struct|struct
name|i_nvp
block|{
union|union
block|{
name|uint64_t
name|_nvi_align
decl_stmt|;
comment|/* ensure alignment */
struct|struct
block|{
name|i_nvp_t
modifier|*
name|_nvi_next
decl_stmt|;
comment|/* pointer to next nvpair */
name|i_nvp_t
modifier|*
name|_nvi_prev
decl_stmt|;
comment|/* pointer to prev nvpair */
block|}
name|_nvi
struct|;
block|}
name|_nvi_un
union|;
name|nvpair_t
name|nvi_nvp
decl_stmt|;
comment|/* nvpair */
block|}
struct|;
define|#
directive|define
name|nvi_next
value|_nvi_un._nvi._nvi_next
define|#
directive|define
name|nvi_prev
value|_nvi_un._nvi._nvi_prev
typedef|typedef
struct|struct
block|{
name|i_nvp_t
modifier|*
name|nvp_list
decl_stmt|;
comment|/* linked list of nvpairs */
name|i_nvp_t
modifier|*
name|nvp_last
decl_stmt|;
comment|/* last nvpair */
name|i_nvp_t
modifier|*
name|nvp_curr
decl_stmt|;
comment|/* current walker nvpair */
name|nv_alloc_t
modifier|*
name|nvp_nva
decl_stmt|;
comment|/* pluggable allocator */
name|uint32_t
name|nvp_stat
decl_stmt|;
comment|/* internal state */
block|}
name|nvpriv_t
typedef|;
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
comment|/* _NVPAIR_IMPL_H */
end_comment

end_unit

