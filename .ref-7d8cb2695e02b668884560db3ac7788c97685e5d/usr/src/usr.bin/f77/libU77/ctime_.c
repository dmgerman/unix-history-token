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
literal|"@(#)ctime_.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * convert system time to ascii string  *  * calling sequence:  *	character*24 string, ctime  *	integer clock  *	string = ctime (clock)  * where:  *	string will receive the ascii equivalent of the integer clock time.  */
end_comment

begin_function_decl
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|ctime_
argument_list|(
argument|str
argument_list|,
argument|len
argument_list|,
argument|clock
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|len
decl_stmt|,
modifier|*
name|clock
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|s
init|=
name|ctime
argument_list|(
name|clock
argument_list|)
decl_stmt|;
name|s
index|[
literal|24
index|]
operator|=
literal|'\0'
expr_stmt|;
name|b_char
argument_list|(
name|s
argument_list|,
name|str
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

