begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)exit_.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_macro
name|exit_
argument_list|(
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|long
modifier|*
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|exitcode
decl_stmt|;
if|#
directive|if
name|vax
if|if
condition|(
name|nargs
argument_list|()
operator|==
literal|0
condition|)
name|exitcode
operator|=
literal|0
expr_stmt|;
else|else
endif|#
directive|endif
endif|vax
name|exitcode
operator|=
operator|*
name|n
expr_stmt|;
comment|/* take any segmentation violation here */
name|f_exit
argument_list|()
expr_stmt|;
name|_cleanup
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|exitcode
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

