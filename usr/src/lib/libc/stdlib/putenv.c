begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)putenv.c	5.2 (Berkeley) %G%"
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
file|<stdlib.h>
end_include

begin_macro
name|putenv
argument_list|(
argument|str
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|equal
decl_stmt|;
name|int
name|rval
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|equal
operator|=
name|index
argument_list|(
name|str
argument_list|,
literal|'='
argument_list|)
operator|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
operator|*
name|equal
operator|=
literal|'\0'
expr_stmt|;
name|rval
operator|=
name|setenv
argument_list|(
name|str
argument_list|,
name|equal
operator|+
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
operator|*
name|equal
operator|=
literal|'='
expr_stmt|;
return|return
operator|(
name|rval
operator|)
return|;
block|}
end_block

end_unit

