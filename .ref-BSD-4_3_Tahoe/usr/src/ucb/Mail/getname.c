begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)getname.c	5.4 (Berkeley) 2/18/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* notdef */
end_comment

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

begin_macro
name|getname
argument_list|(
argument|uid
argument_list|,
argument|namebuf
argument_list|)
end_macro

begin_decl_stmt
name|char
name|namebuf
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
name|getpwuid
argument_list|(
name|uid
argument_list|)
operator|)
operator|==
name|NULL
condition|)
return|return
operator|-
literal|1
return|;
name|strcpy
argument_list|(
name|namebuf
argument_list|,
name|pw
operator|->
name|pw_name
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

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

