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
file|<ctf_impl.h>
end_include

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_include
include|#
directive|include
file|<sys/kobj_impl.h>
end_include

begin_comment
comment|/*  * This module is used both during the normal operation of the kernel (i.e.  * after kmem has been initialized) and during boot (before unix`_start has  * been called).  kobj_alloc is able to tell the difference between the two  * cases, and as such must be used instead of kmem_alloc.  */
end_comment

begin_function
name|void
modifier|*
name|ctf_data_alloc
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
name|void
modifier|*
name|buf
init|=
name|kobj_alloc
argument_list|(
name|size
argument_list|,
name|KM_NOWAIT
operator||
name|KM_SCRATCH
argument_list|)
decl_stmt|;
if|if
condition|(
name|buf
operator|==
name|NULL
condition|)
return|return
operator|(
name|MAP_FAILED
operator|)
return|;
return|return
operator|(
name|buf
operator|)
return|;
block|}
end_function

begin_function
name|void
name|ctf_data_free
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|kobj_free
argument_list|(
name|buf
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|ctf_data_protect
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
comment|/* we don't support this operation in the kernel */
block|}
end_function

begin_function
name|void
modifier|*
name|ctf_alloc
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
return|return
operator|(
name|kobj_alloc
argument_list|(
name|size
argument_list|,
name|KM_NOWAIT
operator||
name|KM_TMP
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
name|ctf_free
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
name|kobj_free
argument_list|(
name|buf
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
specifier|const
name|char
modifier|*
name|ctf_strerror
parameter_list|(
name|int
name|err
parameter_list|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
comment|/* we don't support this operation in the kernel */
block|}
end_function

begin_comment
comment|/*PRINTFLIKE1*/
end_comment

begin_function
name|void
name|ctf_dprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
if|if
condition|(
name|_libctf_debug
condition|)
block|{
name|va_list
name|alist
decl_stmt|;
name|va_start
argument_list|(
name|alist
argument_list|,
name|format
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"ctf DEBUG: "
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|vprintf
argument_list|(
name|format
argument_list|,
name|alist
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|alist
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

