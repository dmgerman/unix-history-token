begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_comment
comment|/* **  This program checks to see if your version of setgid works. **  Compile it, make it set-group-ID guest, and run it as yourself (NOT as **  root and not as member of the group guest). ** **  Compilation is trivial -- just "cc t_dropgid.c".  Make it set-group-ID **  guest and then execute it as a non-root user. */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|id
index|[]
init|=
literal|"@(#)$Id: t_dropgid.c,v 1.6 2001/09/28 16:36:28 ca Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! lint */
end_comment

begin_function
specifier|static
name|void
name|printgids
parameter_list|(
name|str
parameter_list|,
name|r
parameter_list|,
name|e
parameter_list|)
name|char
modifier|*
name|str
decl_stmt|;
name|gid_t
name|r
decl_stmt|,
name|e
decl_stmt|;
block|{
name|printf
argument_list|(
literal|"%s (should be %d/%d): r/egid=%d/%d\n"
argument_list|,
name|str
argument_list|,
operator|(
name|int
operator|)
name|r
argument_list|,
operator|(
name|int
operator|)
name|e
argument_list|,
operator|(
name|int
operator|)
name|getgid
argument_list|()
argument_list|,
operator|(
name|int
operator|)
name|getegid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* define only one of these */
end_comment

begin_if
if|#
directive|if
name|HASSETEGID
end_if

begin_define
define|#
directive|define
name|SETGIDCALL
value|"setegid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASSETEGID */
end_comment

begin_if
if|#
directive|if
name|HASSETREGID
end_if

begin_define
define|#
directive|define
name|SETGIDCALL
value|"setregid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASSETREGID */
end_comment

begin_if
if|#
directive|if
name|HASSETRESGID
end_if

begin_define
define|#
directive|define
name|SETGIDCALL
value|"setresgid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HASSETRESGID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SETGIDCALL
end_ifndef

begin_define
define|#
directive|define
name|SETGIDCALL
value|"setgid"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SETGIDCALL */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|fail
init|=
literal|0
decl_stmt|;
name|int
name|res
decl_stmt|;
name|gid_t
name|realgid
init|=
name|getgid
argument_list|()
decl_stmt|;
name|gid_t
name|effgid
init|=
name|getegid
argument_list|()
decl_stmt|;
name|char
modifier|*
name|prg
init|=
name|argv
index|[
literal|0
index|]
decl_stmt|;
name|printgids
argument_list|(
literal|"initial gids"
argument_list|,
name|realgid
argument_list|,
name|effgid
argument_list|)
expr_stmt|;
if|if
condition|(
name|effgid
operator|==
name|realgid
condition|)
block|{
name|printf
argument_list|(
literal|"SETUP ERROR: re-run set-group-ID guest\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Use chgrp(1) and chmod(1)\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"For example, do this as root "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"(nobody is the name of a group in this example):\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"# chgrp nobody %s\n"
argument_list|,
name|prg
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"# chmod g+s nobody %s\n"
argument_list|,
name|prg
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|HASSETREGID
name|res
operator|=
name|setregid
argument_list|(
name|realgid
argument_list|,
name|realgid
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"setregid(%d)=%d %s\n"
argument_list|,
operator|(
name|int
operator|)
name|realgid
argument_list|,
name|res
argument_list|,
name|res
operator|<
literal|0
condition|?
literal|"failure"
else|:
literal|"ok"
argument_list|)
expr_stmt|;
name|printgids
argument_list|(
literal|"after setregid()"
argument_list|,
name|realgid
argument_list|,
name|realgid
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HASSETREGID */
if|#
directive|if
name|HASSETRESGID
name|res
operator|=
name|setresgid
argument_list|(
name|realgid
argument_list|,
name|realgid
argument_list|,
name|realgid
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"setresgid(%d)=%d %s\n"
argument_list|,
operator|(
name|int
operator|)
name|realgid
argument_list|,
name|res
argument_list|,
name|res
operator|<
literal|0
condition|?
literal|"failure"
else|:
literal|"ok"
argument_list|)
expr_stmt|;
name|printgids
argument_list|(
literal|"after setresgid()"
argument_list|,
name|realgid
argument_list|,
name|realgid
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HASSETRESGID */
if|#
directive|if
name|HASSETEGID
name|res
operator|=
name|setegid
argument_list|(
name|realgid
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"setegid(%d)=%d %s\n"
argument_list|,
operator|(
name|int
operator|)
name|realgid
argument_list|,
name|res
argument_list|,
name|res
operator|<
literal|0
condition|?
literal|"failure"
else|:
literal|"ok"
argument_list|)
expr_stmt|;
name|printgids
argument_list|(
literal|"after setegid()"
argument_list|,
name|realgid
argument_list|,
name|realgid
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* HASSETEGID */
name|res
operator|=
name|setgid
argument_list|(
name|realgid
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"setgid(%d)=%d %s\n"
argument_list|,
operator|(
name|int
operator|)
name|realgid
argument_list|,
name|res
argument_list|,
name|res
operator|<
literal|0
condition|?
literal|"failure"
else|:
literal|"ok"
argument_list|)
expr_stmt|;
name|printgids
argument_list|(
literal|"after setgid()"
argument_list|,
name|realgid
argument_list|,
name|realgid
argument_list|)
expr_stmt|;
if|if
condition|(
name|getegid
argument_list|()
operator|!=
name|realgid
condition|)
block|{
name|fail
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"MAYDAY!  Wrong effective gid\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|getgid
argument_list|()
operator|!=
name|realgid
condition|)
block|{
name|fail
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"MAYDAY!  Wrong real gid\n"
argument_list|)
expr_stmt|;
block|}
comment|/* do activity here */
if|if
condition|(
name|setgid
argument_list|(
name|effgid
argument_list|)
operator|==
literal|0
condition|)
block|{
name|fail
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"MAYDAY!  setgid(%d) succeeded (should have failed)\n"
argument_list|,
name|effgid
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"setgid(%d) failed (this is correct)\n"
argument_list|,
name|effgid
argument_list|)
expr_stmt|;
block|}
name|printgids
argument_list|(
literal|"after setgid() to egid"
argument_list|,
name|realgid
argument_list|,
name|realgid
argument_list|)
expr_stmt|;
if|if
condition|(
name|getegid
argument_list|()
operator|!=
name|realgid
condition|)
block|{
name|fail
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"MAYDAY!  Wrong effective gid\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|getgid
argument_list|()
operator|!=
name|realgid
condition|)
block|{
name|fail
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"MAYDAY!  Wrong real gid\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|fail
operator|>
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\nThis system cannot use %s to give up set-group-ID rights\n"
argument_list|,
name|SETGIDCALL
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|HASSETEGID
name|printf
argument_list|(
literal|"Maybe compile with -DHASSETEGID and try again\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* !HASSETEGID */
if|#
directive|if
operator|!
name|HASSETREGID
name|printf
argument_list|(
literal|"Maybe compile with -DHASSETREGID and try again\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* !HASSETREGID */
if|#
directive|if
operator|!
name|HASSETRESGID
name|printf
argument_list|(
literal|"Maybe compile with -DHASSETRESGID and try again\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* !HASSETRESGID */
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"\nIt is possible to use %s on this system\n"
argument_list|,
name|SETGIDCALL
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

