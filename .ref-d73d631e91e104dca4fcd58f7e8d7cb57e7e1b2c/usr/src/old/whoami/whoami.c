begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1988 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)whoami.c	5.4 (Berkeley) %G%"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_function
name|main
parameter_list|()
block|{
name|struct
name|passwd
modifier|*
name|p
decl_stmt|,
modifier|*
name|getpwuid
argument_list|()
decl_stmt|;
name|uid_t
name|uid
decl_stmt|;
name|uid
operator|=
name|geteuid
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|p
operator|=
name|getpwuid
argument_list|(
name|uid
argument_list|)
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"whoami: no login associated with uid %u.\n"
argument_list|,
name|uid
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|p
operator|->
name|pw_name
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

