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
literal|"@(#)fdate_.c	5.2 (Berkeley) %G%"
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
comment|/*  * Return date and time in an ASCII string.  *  * calling sequence:  *	character*24 string  * 	call fdate(string)  * where:  *	the 24 character string will be filled with the date& time in  *	ascii form as described under ctime(3).  *	No 'newline' or NULL will be included.  */
end_comment

begin_macro
name|fdate_
argument_list|(
argument|s
argument_list|,
argument|strlen
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|strlen
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|ctime
argument_list|()
decl_stmt|,
modifier|*
name|c
decl_stmt|;
name|long
name|time
argument_list|()
decl_stmt|,
name|t
decl_stmt|;
name|t
operator|=
name|time
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|c
operator|=
name|ctime
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|c
index|[
literal|24
index|]
operator|=
literal|'\0'
expr_stmt|;
name|b_char
argument_list|(
name|c
argument_list|,
name|s
argument_list|,
name|strlen
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

