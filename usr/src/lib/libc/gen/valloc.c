begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)valloc.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_function_decl
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|char
modifier|*
name|valloc
parameter_list|(
name|i
parameter_list|)
name|int
name|i
decl_stmt|;
block|{
name|int
name|valsiz
init|=
name|getpagesize
argument_list|()
decl_stmt|,
name|j
decl_stmt|;
name|char
modifier|*
name|cp
init|=
name|malloc
argument_list|(
name|i
operator|+
operator|(
name|valsiz
operator|-
literal|1
operator|)
argument_list|)
decl_stmt|;
name|j
operator|=
operator|(
operator|(
name|int
operator|)
name|cp
operator|+
operator|(
name|valsiz
operator|-
literal|1
operator|)
operator|)
operator|&
operator|~
operator|(
name|valsiz
operator|-
literal|1
operator|)
expr_stmt|;
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|j
operator|)
return|;
block|}
end_function

end_unit

