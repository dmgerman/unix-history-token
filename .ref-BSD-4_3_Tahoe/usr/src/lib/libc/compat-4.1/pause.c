begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)pause.c	5.4 (Berkeley) 2/27/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LIBC_SCCS and not lint
end_endif

begin_comment
comment|/*  * Backwards compatible pause.  */
end_comment

begin_macro
name|pause
argument_list|()
end_macro

begin_block
block|{
name|long
name|sigblock
parameter_list|()
function_decl|;
name|sigpause
argument_list|(
name|sigblock
argument_list|(
literal|0L
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

