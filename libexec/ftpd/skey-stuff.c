begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Author: Wietse Venema, Eindhoven University of Technology.   *  *	$Id: skey-stuff.c,v 1.3 1996/09/22 21:53:34 wosch Exp $  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
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
parameter_list|,
name|sflag
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
name|int
modifier|*
name|sflag
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
name|char
modifier|*
name|username
init|=
name|pwd
condition|?
name|pwd
operator|->
name|pw_name
else|:
literal|":"
decl_stmt|;
comment|/* Display s/key challenge where appropriate. */
operator|*
name|sflag
operator|=
name|skeychallenge
argument_list|(
operator|&
name|skey
argument_list|,
name|username
argument_list|,
name|buf
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%s required for %s."
argument_list|,
name|pwok
condition|?
literal|"Password"
else|:
literal|"S/Key password"
argument_list|,
name|name
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

