begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Wrapper code for Taylor UUCP on Amiga Unix (SVR4) for cron invoked UUCP */
end_comment

begin_comment
comment|/* processes.                                                              */
end_comment

begin_comment
comment|/* The problem:  Cron is not a "licensed" process. any process that grabs a     controlling terminal needs to be licensed.  Taylor UUCP needs controlling    terminals.  Taylor UUCP does relinquish the controlling terminal before     fork(), so the "UUCP" license is appropriate.     This simple program does the "right" thing, but *MUST* be SETUID ROOT */
end_comment

begin_comment
comment|/* Written by: Lawrence E. Rosenman<ler@lerami.lerctr.org> */
end_comment

begin_include
include|#
directive|include
file|<sys/sysm68k.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|char
modifier|*
name|envp
parameter_list|)
block|{
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
name|char
name|name
index|[
literal|256
index|]
decl_stmt|;
name|strcpy
argument_list|(
name|name
argument_list|,
literal|"/usr/local/lib/uucp/uucico"
argument_list|)
expr_stmt|;
if|if
condition|(
name|sysm68k
argument_list|(
name|_m68k_LIMUSER
argument_list|,
name|EUA_GET_LIC
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|/* are we unlicensed? */
if|if
condition|(
name|sysm68k
argument_list|(
name|_m68k_LIMUSER
argument_list|,
name|EUA_UUCP
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* yes, get a "uucp" license */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"sysm68k failed, errno=%d\n"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
comment|/* we didn't? crab it */
name|exit
argument_list|(
name|errno
argument_list|)
expr_stmt|;
block|}
block|}
name|pw
operator|=
name|getpwnam
argument_list|(
literal|"uucp"
argument_list|)
expr_stmt|;
comment|/* get the Password Entry for uucp */
if|if
condition|(
name|pw
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"User ID \"uucp\" doesn't exist.\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|setgid
argument_list|(
name|pw
operator|->
name|pw_gid
argument_list|)
expr_stmt|;
comment|/* set gid to uucp */
name|setuid
argument_list|(
name|pw
operator|->
name|pw_uid
argument_list|)
expr_stmt|;
comment|/* set uid to uucp */
name|argv
index|[
literal|0
index|]
operator|=
name|name
expr_stmt|;
comment|/* have PS not lie... */
name|execv
argument_list|(
literal|"/usr/local/lib/uucp/uucico"
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|/* go to the real program */
name|exit
argument_list|(
name|errno
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

