begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"parms.h"
end_include

begin_include
include|#
directive|include
file|"structs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: gname.c,v 1.7.0.1 85/03/17 20:55:37 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*   * 	get the user id ( and his name from th password file )  *	the easy way - with system calls.  */
end_comment

begin_macro
name|getname
argument_list|(
argument|who_me
argument_list|,
argument|anon
argument_list|)
end_macro

begin_comment
comment|/* anon=true for anonymous */
end_comment

begin_decl_stmt
name|struct
name|auth_f
modifier|*
name|who_me
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|char
name|name
index|[
name|PASSWDLEN
index|]
decl_stmt|;
comment|/* must contain the /etc/passwd entry */
specifier|register
name|count
expr_stmt|;
specifier|register
name|char
modifier|*
name|s
decl_stmt|,
modifier|*
name|d
decl_stmt|;
specifier|static
name|int
name|gotname
init|=
literal|0
decl_stmt|;
comment|/* whether we have done a getpw */
specifier|static
name|int
name|gotstat
init|=
literal|0
decl_stmt|;
comment|/* status getpw returned */
if|if
condition|(
name|gotname
operator|==
literal|0
operator|&&
name|anon
operator|==
literal|0
condition|)
comment|/* grab name if we will require it */
block|{
name|gotstat
operator|=
name|getpw
argument_list|(
name|globuid
argument_list|,
name|name
argument_list|)
expr_stmt|;
comment|/* grab it */
name|gotname
operator|=
literal|1
expr_stmt|;
comment|/* set flag saying we have it */
block|}
if|if
condition|(
name|gotstat
operator|||
name|anon
condition|)
block|{
name|s
operator|=
literal|"Anonymous:"
expr_stmt|;
name|who_me
operator|->
name|aid
operator|=
name|Anonuid
expr_stmt|;
block|}
else|else
block|{
name|s
operator|=
name|name
expr_stmt|;
name|who_me
operator|->
name|aid
operator|=
name|globuid
expr_stmt|;
block|}
name|d
operator|=
name|who_me
operator|->
name|aname
expr_stmt|;
comment|/* copy his name */
name|count
operator|=
name|NAMESZ
expr_stmt|;
while|while
condition|(
operator|(
operator|(
operator|*
name|d
operator|++
operator|=
operator|*
name|s
operator|++
operator|)
operator|!=
literal|':'
operator|)
operator|&&
operator|--
name|count
condition|)
empty_stmt|;
operator|*
operator|--
name|d
operator|=
literal|'\0'
expr_stmt|;
name|s
operator|=
name|Authsystem
expr_stmt|;
comment|/* copy his system */
name|d
operator|=
name|who_me
operator|->
name|asystem
expr_stmt|;
name|count
operator|=
name|HOMESYSSZ
expr_stmt|;
while|while
condition|(
operator|(
operator|(
operator|*
name|d
operator|++
operator|=
operator|*
name|s
operator|++
operator|)
operator|)
operator|!=
literal|'\0'
operator|&&
operator|--
name|count
condition|)
empty_stmt|;
comment|/* move system */
operator|*
operator|--
name|d
operator|=
literal|'\0'
expr_stmt|;
block|}
end_block

end_unit

