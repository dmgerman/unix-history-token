begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"$Header: talkto.c,v 1.7.0.1 85/03/18 20:56:55 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	talkto(auth, uniq) struct auth_f *auth; struct id_d *uniq;  *	see if the author is a local user (by checking the sys field of  *	the note to see where it was written) and then grab his name from  *	the auth structure. If he is not "Anonymous", and is local then  *	we do a 'write name' command to talk with him.  *  *	Ray Essick	December 1981  */
end_comment

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

begin_decl_stmt
specifier|static
name|char
modifier|*
name|command
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_macro
name|talkto
argument_list|(
argument|auth
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|auth_f
modifier|*
name|auth
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|cmdline
index|[
name|CMDLEN
index|]
decl_stmt|;
comment|/* build the command in here */
if|if
condition|(
name|strcmp
argument_list|(
literal|"Anonymous"
argument_list|,
name|auth
operator|->
name|aname
argument_list|)
operator|==
literal|0
condition|)
return|return;
comment|/*  *	with 4.2 and later -- we might want to let this go on past  *	since the talk(1) program works across machine boundaries.  */
if|if
condition|(
name|strcmp
argument_list|(
name|Authsystem
argument_list|,
name|auth
operator|->
name|asystem
argument_list|)
operator|!=
literal|0
condition|)
return|return;
comment|/* hard to talk to other machine */
if|if
condition|(
name|command
operator|==
name|NULL
operator|&&
operator|(
name|command
operator|=
name|getenv
argument_list|(
literal|"WRITE"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
name|command
operator|=
name|WRITE
expr_stmt|;
comment|/* assign default */
name|sprintf
argument_list|(
name|cmdline
argument_list|,
literal|"%s %s"
argument_list|,
name|command
argument_list|,
name|auth
operator|->
name|aname
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|cmdline
argument_list|)
expr_stmt|;
comment|/* let him know what doing */
ifndef|#
directive|ifndef
name|FASTFORK
name|dounix
argument_list|(
name|cmdline
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* run the command */
else|#
directive|else
name|dounix
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|,
name|command
argument_list|,
name|auth
operator|->
name|aname
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|printf
argument_list|(
literal|"--Hit any key to continue--"
argument_list|)
expr_stmt|;
name|gchar
argument_list|()
expr_stmt|;
comment|/* grab character and drop it */
block|}
end_block

end_unit

