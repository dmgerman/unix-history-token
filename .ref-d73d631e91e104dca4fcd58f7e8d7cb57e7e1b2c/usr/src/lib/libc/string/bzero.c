begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)bzero.c	5.5 (Berkeley) %G%"
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
file|<string.h>
end_include

begin_comment
comment|/*  * bzero -- vax movc5 instruction  */
end_comment

begin_function
name|void
name|bzero
parameter_list|(
name|b
parameter_list|,
name|length
parameter_list|)
specifier|register
name|char
modifier|*
name|b
decl_stmt|;
specifier|register
name|size_t
name|length
decl_stmt|;
block|{
while|while
condition|(
name|length
operator|--
condition|)
operator|*
name|b
operator|++
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function

end_unit

