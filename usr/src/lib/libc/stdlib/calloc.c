begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)calloc.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_function
name|char
modifier|*
name|calloc
parameter_list|(
name|nelem
parameter_list|,
name|elsize
parameter_list|)
name|u_int
name|nelem
decl_stmt|,
name|elsize
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|;
name|elsize
operator|*=
name|nelem
expr_stmt|;
if|if
condition|(
name|p
operator|=
name|malloc
argument_list|(
name|elsize
argument_list|)
condition|)
name|bzero
argument_list|(
name|p
argument_list|,
name|elsize
argument_list|)
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|cfree
argument_list|(
argument|p
argument_list|,
argument|nelem
argument_list|,
argument|elsize
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|nelem
decl_stmt|,
name|elsize
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

