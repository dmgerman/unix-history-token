begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  *	from: k_gethostname.c,v 4.1 88/12/01 14:04:42 jtkohl Exp $  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_endif
unit|static char rcsid[] = "$FreeBSD$";
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PC
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_comment
comment|/* teach me how to k_gethostname for your system here */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PC
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_typedef
typedef|typedef
name|long
name|in_name
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"custom.h"
end_include

begin_comment
comment|/* where is this file? */
end_comment

begin_extern
extern|extern get_custom(
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|LEN
value|64
end_define

begin_comment
comment|/* just a guess */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PC */
end_comment

begin_comment
comment|/*  * Return the local host's name in "name", up to "namelen" characters.  * "name" will be null-terminated if "namelen" is big enough.  * The return code is 0 on success, -1 on failure.  (The calling  * interface is identical to gethostname(2).)  *  * Currently defined for BSD 4.2 and PC.  The BSD version just calls  * gethostname(); the PC code was taken from "kinit.c", and may or may  * not work.  */
end_comment

begin_function
name|int
name|k_gethostname
parameter_list|(
name|name
parameter_list|,
name|namelen
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|namelen
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|BSD42
return|return
name|gethostname
argument_list|(
name|name
argument_list|,
name|namelen
argument_list|)
return|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PC
name|char
name|buf
index|[
name|LEN
index|]
decl_stmt|;
name|char
name|b1
decl_stmt|,
name|b2
decl_stmt|,
name|b3
decl_stmt|,
name|b4
decl_stmt|;
specifier|register
name|char
modifier|*
name|ptr
decl_stmt|;
name|get_custom
argument_list|()
expr_stmt|;
comment|/* should check for errors, 				 * return -1 on failure */
name|ptr
operator|=
operator|(
name|char
operator|*
operator|)
operator|&
operator|(
name|custom
operator|.
name|c_me
operator|)
expr_stmt|;
name|b1
operator|=
operator|*
name|ptr
operator|++
expr_stmt|;
name|b2
operator|=
operator|*
name|ptr
operator|++
expr_stmt|;
name|b3
operator|=
operator|*
name|ptr
operator|++
expr_stmt|;
name|b4
operator|=
operator|*
name|ptr
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"PC address %d.%d.%d.%d"
argument_list|,
name|b1
argument_list|,
name|b2
argument_list|,
name|b3
argument_list|,
name|b4
argument_list|)
expr_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|buf
argument_list|)
operator|>
name|namelen
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"gethostname: namelen too small; truncating"
argument_list|)
expr_stmt|;
name|strnpcy
argument_list|(
name|name
argument_list|,
name|buf
argument_list|,
name|namelen
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function

end_unit

