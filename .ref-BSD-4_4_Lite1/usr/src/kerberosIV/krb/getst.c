begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /mit/kerberos/src/lib/krb/RCS/getst.c,v $  * $Author: jtkohl $  *  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_getst_c
index|[]
init|=
literal|"$Header: getst.c,v 4.5 88/11/15 16:31:39 jtkohl Exp $"
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
comment|/*  * getst() takes a file descriptor, a string and a count.  It reads  * from the file until either it has read "count" characters, or until  * it reads a null byte.  When finished, what has been read exists in  * the given string "s".  If "count" characters were actually read, the  * last is changed to a null, so the returned string is always null-  * terminated.  getst() returns the number of characters read, including  * the null terminator.  */
end_comment

begin_macro
name|getst
argument_list|(
argument|fd
argument_list|,
argument|s
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|count
operator|=
name|n
expr_stmt|;
while|while
condition|(
name|read
argument_list|(
name|fd
argument_list|,
name|s
argument_list|,
literal|1
argument_list|)
operator|>
literal|0
operator|&&
operator|--
name|count
condition|)
if|if
condition|(
operator|*
name|s
operator|++
operator|==
literal|'\0'
condition|)
return|return
operator|(
name|n
operator|-
name|count
operator|)
return|;
operator|*
name|s
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|n
operator|-
name|count
operator|)
return|;
block|}
end_block

end_unit

