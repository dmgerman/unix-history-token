begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 david d `zoo' zuhn  * Copyright (c) 1994 Free Software Foundation, Inc.  * Copyright (c) 1992, Brian Berliner and Jeff Polk  * Copyright (c) 1989-1992, Brian Berliner  *   * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with this  CVS source distribution.  *   * version.c - the CVS version number  */
end_comment

begin_include
include|#
directive|include
file|"cvs.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|version_string
init|=
literal|"\nConcurrent Versions System (CVS) 1.9.26"
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|config_string
init|=
literal|" (client/server)\n"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|config_string
init|=
literal|" (client)\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|config_string
init|=
literal|" (server)\n"
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|config_string
init|=
literal|"\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

