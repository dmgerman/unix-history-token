begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)setruid.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_macro
name|setruid
argument_list|(
argument|ruid
argument_list|)
end_macro

begin_decl_stmt
name|int
name|ruid
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|setreuid
argument_list|(
name|ruid
argument_list|,
operator|-
literal|1
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

