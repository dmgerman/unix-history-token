begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Mark Nudleman  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Mark Nudleman.  *   * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)help.c	5.3 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"less.h"
end_include

begin_comment
comment|/*  * Display some help.  * Just invoke another "less" to display the help file.  *  * {{ This makes this function very simple, and makes changing the  *    help file very easy, but it may present difficulties on  *    (non-Unix) systems which do not supply the "system()" function. }}  */
end_comment

begin_function
name|public
name|void
name|help
parameter_list|()
block|{
name|char
name|cmd
index|[
name|MAXPATHLEN
operator|+
literal|100
index|]
decl_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|cmd
argument_list|,
literal|"-less -m '-PmHELP -- ?eEND -- Press g to see it again:Press RETURN for more., or q when done ' %s"
argument_list|,
name|HELPFILE
argument_list|)
expr_stmt|;
name|lsystem
argument_list|(
name|cmd
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

