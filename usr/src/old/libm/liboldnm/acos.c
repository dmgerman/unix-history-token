begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)acos.c	5.1 (Berkeley) 5/8/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/* acos(arg) return the arccos, 	respectively of their arguments.  	Arctan is called after appropriate range reduction. */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function_decl
name|double
name|atan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|double
name|asin
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|double
name|pio2
init|=
literal|1.570796326794896619
decl_stmt|;
end_decl_stmt

begin_function
name|double
name|acos
parameter_list|(
name|arg
parameter_list|)
name|double
name|arg
decl_stmt|;
block|{
asm|asm("	bispsw	$0xe0");
if|if
condition|(
name|arg
operator|>
literal|1.
operator|||
name|arg
operator|<
operator|-
literal|1.
condition|)
block|{
name|errno
operator|=
name|EDOM
expr_stmt|;
return|return
operator|(
literal|0.
operator|)
return|;
block|}
return|return
operator|(
name|pio2
operator|-
name|asin
argument_list|(
name|arg
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

