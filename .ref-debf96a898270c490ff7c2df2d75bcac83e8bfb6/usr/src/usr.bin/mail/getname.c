begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)getname.c	5.7 (Berkeley) %G%"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_comment
comment|/*  * Getname / getuserid for those with  * hashed passwd data base).  *  */
end_comment

begin_include
include|#
directive|include
file|"rcv.h"
end_include

begin_comment
comment|/*  * Search the passwd file for a uid.  Return name through ref parameter  * if found, indicating success with 0 return.  Return -1 on error.  */
end_comment

begin_function
name|char
modifier|*
name|getname
parameter_list|(
name|uid
parameter_list|)
block|{
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
if|if
condition|(
operator|(
name|pw
operator|=
name|getpwuid
argument_list|(
name|uid
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
name|NOSTR
return|;
return|return
name|pw
operator|->
name|pw_name
return|;
block|}
end_function

begin_comment
comment|/*  * Convert the passed name to a user id and return it.  Return -1  * on error.  */
end_comment

begin_macro
name|getuserid
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
name|name
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
if|if
condition|(
operator|(
name|pw
operator|=
name|getpwnam
argument_list|(
name|name
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|pw
operator|->
name|pw_uid
return|;
block|}
end_block

end_unit

