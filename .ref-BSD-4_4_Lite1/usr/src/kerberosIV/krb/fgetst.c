begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /mit/kerberos/src/lib/krb/RCS/fgetst.c,v $  * $Author: jtkohl $   *  * Copyright 1987, 1988 by the Massachusetts Institute of Technology.   *  * For copying and distribution information, please see the file  *<mit-copyright.h>.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_fgetst_c
index|[]
init|=
literal|"$Header: fgetst.c,v 4.0 89/01/23 10:08:31 jtkohl Exp $"
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

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * fgetst takes a file descriptor, a character pointer, and a count.  * It reads from the file it has either read "count" characters, or  * until it reads a null byte.  When finished, what has been read exists  * in "s". If "count" characters were actually read, the last is changed  * to a null, so the returned string is always null-terminated.  fgetst  * returns the number of characters read, including the null terminator.   */
end_comment

begin_macro
name|fgetst
argument_list|(
argument|f
argument_list|,
argument|s
argument_list|,
argument|n
argument_list|)
end_macro

begin_decl_stmt
name|FILE
modifier|*
name|f
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|count
operator|=
name|n
expr_stmt|;
name|int
name|ch
decl_stmt|;
comment|/* NOT char; otherwise you don't see EOF */
while|while
condition|(
operator|(
name|ch
operator|=
name|getc
argument_list|(
name|f
argument_list|)
operator|)
operator|!=
name|EOF
operator|&&
name|ch
operator|&&
operator|--
name|count
condition|)
block|{
operator|*
name|s
operator|++
operator|=
name|ch
expr_stmt|;
block|}
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

