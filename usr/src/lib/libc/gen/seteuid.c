begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)seteuid.c	5.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_macro
name|seteuid
argument_list|(
argument|euid
argument_list|)
end_macro

begin_decl_stmt
name|int
name|euid
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|setreuid
argument_list|(
operator|-
literal|1
argument_list|,
name|euid
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

