begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This software is Copyright (c) 1986 by Rick Adams.  *  * Permission is hereby granted to copy, reproduce, redistribute or  * otherwise use this software as long as: there is no monetary  * profit gained specifically from the use or reproduction or this  * software, it is not sold, rented, traded or otherwise marketed, and  * this copyright notice is included prominently in any copy  * made.  *  * The author make no claims as to the fitness or correctness of  * this software for any use whatsoever, and it is provided as is.   * Any use of this software is at the user's own risk.  *  * This routine is compatible with the Unix T/S system call uname,  * which figures out the name of the local system.  * However, we do it by reading the file /usr/include/whoami.h.  * This avoids having to recompile uucp for each site and hence  * avoids having to distribute the source to uucp to people who  * have only binary licenses.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCCSID
end_ifdef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|SccsId
init|=
literal|"@(#)uname.c	2.9	1/20/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCCSID */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"../common/conf.h"
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

begin_comment
comment|/* UNAME */
end_comment

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
name|char
modifier|*
name|uptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|gethostname
argument_list|(
name|uptr
argument_list|,
literal|256
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

begin_ifdef
ifdef|#
directive|ifdef
name|UUNAME
end_ifdef

begin_macro
name|uname
argument_list|(
argument|uptr
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|uptr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
modifier|*
name|uucpf
decl_stmt|;
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
comment|/* uucp name is stored in /etc/uucpname or /local/uucpname */
if|if
condition|(
operator|(
operator|(
name|uucpf
operator|=
name|fopen
argument_list|(
literal|"/etc/uucpname"
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
operator|&&
operator|(
name|uucpf
operator|=
name|fopen
argument_list|(
literal|"/local/uucpname"
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|==
name|NULL
operator|)
operator|||
name|fgets
argument_list|(
name|uptr
argument_list|,
literal|256
argument_list|,
name|uucpf
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
literal|"/etc/uucpname"
argument_list|)
expr_stmt|;
return|return;
block|}
name|p
operator|=
name|index
argument_list|(
name|uptr
argument_list|,
literal|'\n'
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
condition|)
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|uucpf
operator|!=
name|NULL
condition|)
name|fclose
argument_list|(
name|uucpf
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

begin_comment
comment|/* UUNAME */
end_comment

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
name|char
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

