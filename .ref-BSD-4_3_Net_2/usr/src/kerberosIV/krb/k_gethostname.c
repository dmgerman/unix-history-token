begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/k_gethostname.c,v $  * $Author: kfall $  *  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_k_gethostname_c
index|[]
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/k_gethostname.c,v 4.2 90/06/23 03:10:52 kfall Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_comment
comment|/*  * Return the local host's name in "name", up to "namelen" characters.  * "name" will be null-terminated if "namelen" is big enough.  * The return code is 0 on success, -1 on failure.  (The calling  * interface is identical to gethostname(2).)  *  * Currently defined for BSD 4.2 and PC.  The BSD version just calls  * gethostname(); the PC code was taken from "kinit.c", and may or may  * not work.  */
end_comment

begin_macro
name|k_gethostname
argument_list|(
argument|name
argument_list|,
argument|namelen
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|namelen
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|gethostname
argument_list|(
name|name
argument_list|,
name|namelen
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

