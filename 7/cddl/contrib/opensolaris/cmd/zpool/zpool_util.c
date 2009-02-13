begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<libgen.h>
end_include

begin_include
include|#
directive|include
file|<libintl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|"zpool_util.h"
end_include

begin_comment
comment|/*  * Utility function to guarantee malloc() success.  */
end_comment

begin_function
name|void
modifier|*
name|safe_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
name|void
modifier|*
name|data
decl_stmt|;
if|if
condition|(
operator|(
name|data
operator|=
name|calloc
argument_list|(
literal|1
argument_list|,
name|size
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"internal error: out of memory\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|data
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Same as above, but for strdup()  */
end_comment

begin_function
name|char
modifier|*
name|safe_strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
name|char
modifier|*
name|ret
decl_stmt|;
if|if
condition|(
operator|(
name|ret
operator|=
name|strdup
argument_list|(
name|str
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"internal error: out of memory\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Display an out of memory error message and abort the current program.  */
end_comment

begin_function
name|void
name|zpool_no_memory
parameter_list|(
name|void
parameter_list|)
block|{
name|assert
argument_list|(
name|errno
operator|==
name|ENOMEM
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|gettext
argument_list|(
literal|"internal error: out of memory\n"
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

