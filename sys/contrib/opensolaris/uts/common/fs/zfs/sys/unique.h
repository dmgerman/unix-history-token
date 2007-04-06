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
name|_SYS_UNIQUE_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UNIQUE_H
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
file|<sys/zfs_context.h>
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
comment|/* The number of significant bits in each unique value. */
define|#
directive|define
name|UNIQUE_BITS
value|56
name|void
name|unique_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Return a new unique value. */
name|uint64_t
name|unique_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Return a unique value, which equals the one passed in if possible. */
name|uint64_t
name|unique_insert
parameter_list|(
name|uint64_t
name|value
parameter_list|)
function_decl|;
comment|/* Indicate that this value no longer needs to be uniquified against. */
name|void
name|unique_remove
parameter_list|(
name|uint64_t
name|value
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
comment|/* _SYS_UNIQUE_H */
end_comment

end_unit

