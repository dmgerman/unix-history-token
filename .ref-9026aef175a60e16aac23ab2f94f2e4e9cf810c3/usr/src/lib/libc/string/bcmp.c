begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)bcmp.c	8.1 (Berkeley) %G%"
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
comment|/*  * bcmp -- vax cmpc3 instruction  */
end_comment

begin_function
name|int
name|bcmp
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|length
parameter_list|)
specifier|const
name|void
modifier|*
name|b1
decl_stmt|,
decl|*
name|b2
decl_stmt|;
end_function

begin_decl_stmt
specifier|register
name|size_t
name|length
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|p1
decl_stmt|,
modifier|*
name|p2
decl_stmt|;
if|if
condition|(
name|length
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|p1
operator|=
operator|(
name|char
operator|*
operator|)
name|b1
expr_stmt|;
name|p2
operator|=
operator|(
name|char
operator|*
operator|)
name|b2
expr_stmt|;
do|do
if|if
condition|(
operator|*
name|p1
operator|++
operator|!=
operator|*
name|p2
operator|++
condition|)
break|break;
do|while
condition|(
operator|--
name|length
condition|)
do|;
return|return
operator|(
name|length
operator|)
return|;
block|}
end_block

end_unit

