begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This routine is compatible with the Unix T/S system call uname,  * which figures out the name of the local system.  * However, we do it by reading the file /usr/include/whoami.h.  * This avoids having to recompile uucp for each site and hence  * avoids having to distribute the source to uucp to people who  * have only binary licenses.  */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|SccsId
init|=
literal|"@(#)uname.c	2.4	5/3/83"
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"params.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|UNAME
end_ifdef

begin_define
define|#
directive|define
name|DONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GHNAME
end_ifdef

begin_macro
name|uname
argument_list|(
argument|uptr
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|utsname
modifier|*
name|uptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|gethostname
argument_list|(
name|uptr
operator|->
name|nodename
argument_list|,
sizeof|sizeof
argument_list|(
name|uptr
operator|->
name|nodename
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

begin_define
define|#
directive|define
name|DONE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DONE
end_ifndef

begin_define
define|#
directive|define
name|HDRFILE
value|"/usr/include/whoami.h"
end_define

begin_macro
name|uname
argument_list|(
argument|uptr
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|utsname
modifier|*
name|uptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
name|FILE
modifier|*
name|fd
decl_stmt|;
name|fd
operator|=
name|fopen
argument_list|(
name|HDRFILE
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|fd
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Cannot open %s\n"
argument_list|,
name|HDRFILE
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
for|for
control|(
init|;
condition|;
control|)
block|{
comment|/* each line in the file */
if|if
condition|(
name|fgets
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
name|buf
argument_list|,
name|fd
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"no sysname in %s\n"
argument_list|,
name|HDRFILE
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sscanf
argument_list|(
name|buf
argument_list|,
literal|"#define sysname \"%[^\"]\""
argument_list|,
name|uptr
operator|->
name|nodename
argument_list|)
operator|==
literal|1
condition|)
block|{
name|fclose
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

