begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)getent.c	5.1 (Berkeley) %G%"
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
comment|/*  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|getent
argument_list|(
argument|cp
argument_list|,
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|char
modifier|*
name|getstr
parameter_list|(
name|cp
parameter_list|,
name|cpp
parameter_list|)
name|char
modifier|*
name|cp
decl_stmt|,
decl|*
modifier|*
name|cpp
decl_stmt|;
end_function

begin_block
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

