begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|rcsid
init|=
literal|"$Id: exec.c,v 1.4 1993/09/04 05:06:47 jkh Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * FreeBSD install - a package for the installation and maintainance  * of non-core utilities.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * Jordan K. Hubbard  * 18 July 1993  *  * Miscellaneous system routines.  *  */
end_comment

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_comment
comment|/*  * Unusual system() substitute.  Accepts format string and args,  * builds and executes command.  Returns exit code.  */
end_comment

begin_function
name|int
name|vsystem
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|args
decl_stmt|;
name|char
name|cmd
index|[
name|FILENAME_MAX
operator|*
literal|2
index|]
decl_stmt|;
comment|/* reasonable default for what I do */
name|int
name|ret
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vsprintf
argument_list|(
name|cmd
argument_list|,
name|fmt
argument_list|,
name|args
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|printf
argument_list|(
literal|"Executing %s\n"
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ret
operator|=
name|system
argument_list|(
name|cmd
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

end_unit

