begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This source code is a product of Sun Microsystems, Inc. and is provided  * for unrestricted use provided that this legend is included on all tape  * media and as a part of the software program in whole or part.  Users  * may copy or modify this source code without charge, but are not authorized  * to license or distribute it to anyone else except as part of a product or  * program developed by the user.  *  * THIS PROGRAM CONTAINS SOURCE CODE COPYRIGHTED BY SUN MICROSYSTEMS, INC.  * SUN MICROSYSTEMS, INC., MAKES NO REPRESENTATIONS ABOUT THE SUITABLITY  * OF SUCH SOURCE CODE FOR ANY PURPOSE.  IT IS PROVIDED "AS IS" WITHOUT  * EXPRESS OR IMPLIED WARRANTY OF ANY KIND.  SUN MICROSYSTEMS, INC. DISCLAIMS  * ALL WARRANTIES WITH REGARD TO SUCH SOURCE CODE, INCLUDING ALL IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  IN  * NO EVENT SHALL SUN MICROSYSTEMS, INC. BE LIABLE FOR ANY SPECIAL, INDIRECT,  * INCIDENTAL, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM USE OF SUCH SOURCE CODE, REGARDLESS OF THE THEORY OF LIABILITY.  *   * This source code is provided with no support and without any obligation on  * the part of Sun Microsystems, Inc. to assist in its use, correction,   * modification or enhancement.  *  * SUN MICROSYSTEMS, INC. SHALL HAVE NO LIABILITY WITH RESPECT TO THE  * INFRINGEMENT OF COPYRIGHTS, TRADE SECRETS OR ANY PATENTS BY THIS  * SOURCE CODE OR ANY PART THEREOF.  *  * Sun Microsystems, Inc.  * 2550 Garcia Avenue  * Mountain View, California 94043  */
end_comment

begin_comment
comment|/* @(#)dl.c 1.1 89/09/04 SMI */
end_comment

begin_comment
comment|/*  * Copyright (c) 1989, 1991 Sun Microsystems, Inc.  */
end_comment

begin_comment
comment|/*  * Stub library for programmer's interface to the dynamic linker.  Used  * to satisfy ld processing, and serves as a precedence place-holder at  * execution-time.  If these routines are actually called, it is considered  * a program-terminating error -- the dynamic linker has gotten very confused.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|static
name|char
name|error
index|[]
init|=
literal|"%s: stub interception failed\n"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
modifier|*
name|dlopen
parameter_list|(
name|file
parameter_list|,
name|mode
parameter_list|)
name|char
modifier|*
name|file
decl_stmt|;
comment|/* file to be added */
name|int
name|mode
decl_stmt|;
comment|/* mode of addition */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|error
argument_list|,
literal|"dlopen"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
comment|/*NOTREACHED*/
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|void
modifier|*
name|dlsym
parameter_list|(
name|dl
parameter_list|,
name|cp
parameter_list|)
name|void
modifier|*
name|dl
decl_stmt|;
comment|/* object to be searched */
name|char
modifier|*
name|cp
decl_stmt|;
comment|/* symbol to be retrieved */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|error
argument_list|,
literal|"dlsym"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
comment|/*NOTREACHED*/
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|dlclose
parameter_list|(
name|dl
parameter_list|)
name|void
modifier|*
name|dl
decl_stmt|;
comment|/* object to be removed */
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|error
argument_list|,
literal|"dlclose"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
comment|/*NOTREACHED*/
block|}
end_function

begin_function
name|char
modifier|*
name|dlerror
parameter_list|()
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|error
argument_list|,
literal|"dlerror"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
comment|/*NOTREACHED*/
block|}
end_function

end_unit

