begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)memccpy.c	5.4 (Berkeley) 6/27/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_function
name|char
modifier|*
name|memccpy
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
specifier|register
name|char
modifier|*
name|t
decl_stmt|,
decl|*
name|f
decl_stmt|;
end_function

begin_expr_stmt
specifier|register
name|c
operator|,
name|n
expr_stmt|;
end_expr_stmt

begin_block
block|{
while|while
condition|(
operator|--
name|n
operator|>=
literal|0
condition|)
if|if
condition|(
operator|(
operator|*
name|t
operator|++
operator|=
operator|*
name|f
operator|++
operator|)
operator|==
name|c
condition|)
return|return
operator|(
name|t
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

