begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
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
file|"libuutil_common.h"
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_LP64
end_ifdef

begin_define
define|#
directive|define
name|TMPPATHFMT
value|"%s/uu%ld"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _LP64 */
end_comment

begin_define
define|#
directive|define
name|TMPPATHFMT
value|"%s/uu%lld"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LP64 */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|uu_open_tmp
parameter_list|(
specifier|const
name|char
modifier|*
name|dir
parameter_list|,
name|uint_t
name|uflags
parameter_list|)
block|{
name|int
name|f
decl_stmt|;
name|char
modifier|*
name|fname
init|=
name|uu_zalloc
argument_list|(
name|PATH_MAX
argument_list|)
decl_stmt|;
if|if
condition|(
name|fname
operator|==
name|NULL
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
for|for
control|(
init|;
condition|;
control|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|fname
argument_list|,
name|PATH_MAX
argument_list|,
literal|"%s/uu%lld"
argument_list|,
name|dir
argument_list|,
name|gethrtime
argument_list|()
argument_list|)
expr_stmt|;
name|f
operator|=
name|open
argument_list|(
name|fname
argument_list|,
name|O_CREAT
operator||
name|O_EXCL
operator||
name|O_RDWR
argument_list|,
literal|0600
argument_list|)
expr_stmt|;
if|if
condition|(
name|f
operator|>=
literal|0
operator|||
name|errno
operator|!=
name|EEXIST
condition|)
break|break;
block|}
if|if
condition|(
name|f
operator|>=
literal|0
condition|)
operator|(
name|void
operator|)
name|unlink
argument_list|(
name|fname
argument_list|)
expr_stmt|;
name|uu_free
argument_list|(
name|fname
argument_list|)
expr_stmt|;
return|return
operator|(
name|f
operator|)
return|;
block|}
end_function

end_unit

