begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Author: Wietse Venema, Eindhoven University of Technology.   */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: skey-stuff.c,v 1.6.2.2 1997/12/12 07:20:40 charnier Exp $"
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
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<skey.h>
end_include

begin_comment
comment|/* skey_challenge - additional password prompt stuff */
end_comment

begin_function
name|char
modifier|*
name|skey_challenge
parameter_list|(
name|name
parameter_list|,
name|pwd
parameter_list|,
name|pwok
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|passwd
modifier|*
name|pwd
decl_stmt|;
name|int
name|pwok
decl_stmt|;
block|{
specifier|static
name|char
name|buf
index|[
literal|128
index|]
decl_stmt|;
name|struct
name|skey
name|skey
decl_stmt|;
comment|/* Display s/key challenge where appropriate. */
operator|*
name|buf
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|pwd
operator|==
name|NULL
operator|||
name|skeychallenge
argument_list|(
operator|&
name|skey
argument_list|,
name|pwd
operator|->
name|pw_name
argument_list|,
name|buf
argument_list|)
condition|)
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"Password required for %s."
argument_list|,
name|name
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|pwok
condition|)
name|strcat
argument_list|(
name|buf
argument_list|,
literal|" (s/key required)"
argument_list|)
expr_stmt|;
return|return
operator|(
name|buf
operator|)
return|;
block|}
end_function

end_unit

