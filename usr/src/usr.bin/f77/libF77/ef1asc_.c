begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)ef1asc_.c	5.2 (Berkeley) 4/12/91"
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
comment|/* EFL support routine to copy string b to string a */
end_comment

begin_define
define|#
directive|define
name|M
value|( (long) (sizeof(long) - 1) )
end_define

begin_define
define|#
directive|define
name|EVEN
parameter_list|(
name|x
parameter_list|)
value|( ( (x)+ M)& (~M) )
end_define

begin_macro
name|ef1asc_
argument_list|(
argument|a
argument_list|,
argument|la
argument_list|,
argument|b
argument_list|,
argument|lb
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|a
decl_stmt|,
modifier|*
name|b
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|int
modifier|*
name|la
decl_stmt|,
modifier|*
name|lb
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|s_copy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|a
argument_list|,
operator|(
name|char
operator|*
operator|)
name|b
argument_list|,
name|EVEN
argument_list|(
operator|*
name|la
argument_list|)
argument_list|,
operator|*
name|lb
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

