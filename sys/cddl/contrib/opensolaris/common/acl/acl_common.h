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
name|_ACL_ACL_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|_ACL_ACL_UTILS_H
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/acl.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
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
specifier|extern
name|ace_t
name|trivial_acl
index|[
literal|6
index|]
decl_stmt|;
specifier|extern
name|int
name|acltrivial
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|void
name|adjust_ace_pair
parameter_list|(
name|ace_t
modifier|*
name|pair
parameter_list|,
name|mode_t
name|mode
parameter_list|)
function_decl|;
specifier|extern
name|int
name|ace_trivial
parameter_list|(
name|ace_t
modifier|*
name|acep
parameter_list|,
name|int
name|aclcnt
parameter_list|)
function_decl|;
name|void
name|ksort
parameter_list|(
name|caddr_t
name|v
parameter_list|,
name|int
name|n
parameter_list|,
name|int
name|s
parameter_list|,
name|int
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
name|int
name|cmp2acls
parameter_list|(
name|void
modifier|*
name|a
parameter_list|,
name|void
modifier|*
name|b
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
comment|/* _ACL_ACL_UTILS_H */
end_comment

end_unit

