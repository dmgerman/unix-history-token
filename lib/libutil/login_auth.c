begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 by  * Sean Eric Fagan<sef@kithrup.com>  * David Nugent<davidn@blaze.net.au>  * All rights reserved.  *  * Portions copyright (c) 1995,1997 by  * Berkeley Software Design, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, is permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. This work was done expressly for inclusion into FreeBSD.  Other use  *    is permitted provided this notation is included.  * 4. Absolutely no warranty of function or purpose is made by the authors.  * 5. Modifications may be freely made to this file providing the above  *    conditions are met.  *  * Low-level routines relating to the user capabilities database  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<login_cap.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_comment
comment|/*  * auth_checknologin()  * Checks for the existance of a nologin file in the login_cap  * capability<lc>.  If there isn't one specified, then it checks  * to see if this class should just ignore nologin files.  Lastly,  * it tries to print out the default nologin file, and, if such  * exists, it exits.  */
end_comment

begin_function
name|void
name|auth_checknologin
parameter_list|(
name|login_cap_t
modifier|*
name|lc
parameter_list|)
block|{
name|char
modifier|*
name|file
decl_stmt|;
comment|/* Do we ignore a nologin file? */
if|if
condition|(
name|login_getcapbool
argument_list|(
name|lc
argument_list|,
literal|"ignorenologin"
argument_list|,
literal|0
argument_list|)
condition|)
return|return;
comment|/* Note that<file> will be "" if there is no nologin capability */
if|if
condition|(
operator|(
name|file
operator|=
name|login_getcapstr
argument_list|(
name|lc
argument_list|,
literal|"nologin"
argument_list|,
literal|""
argument_list|,
name|NULL
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/*    * *file is true IFF there was a "nologin" capability    * Note that auth_cat() returns 1 only if the specified    * file exists, and is readable.  E.g., /.nologin exists.    */
if|if
condition|(
operator|(
operator|*
name|file
operator|&&
name|auth_cat
argument_list|(
name|file
argument_list|)
operator|)
operator|||
name|auth_cat
argument_list|(
name|_PATH_NOLOGIN
argument_list|)
condition|)
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * auth_cat()  * Checks for the readability of<file>; if it can be opened for  * reading, it prints it out to stdout, and then exits.  Otherwise,  * it returns 0 (meaning no nologin file).  */
end_comment

begin_function
name|int
name|auth_cat
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|)
block|{
name|int
name|fd
decl_stmt|,
name|count
decl_stmt|;
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
if|if
condition|(
operator|(
name|fd
operator|=
name|open
argument_list|(
name|file
argument_list|,
name|O_RDONLY
argument_list|)
operator|)
operator|<
literal|0
condition|)
return|return
literal|0
return|;
while|while
condition|(
operator|(
name|count
operator|=
name|read
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|)
operator|)
operator|>
literal|0
condition|)
operator|(
name|void
operator|)
name|write
argument_list|(
name|fileno
argument_list|(
name|stdout
argument_list|)
argument_list|,
name|buf
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|5
argument_list|)
expr_stmt|;
comment|/* wait an arbitrary time to drain */
return|return
literal|1
return|;
block|}
end_function

end_unit

