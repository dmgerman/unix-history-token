begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 david d `zoo' zuhn  * Copyright (c) 1994 Free Software Foundation, Inc.  * Copyright (c) 1992, Brian Berliner and Jeff Polk  * Copyright (c) 1989-1992, Brian Berliner  *  * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with this  CVS source distribution.  *  * version.c - the CVS version number  */
end_comment

begin_include
include|#
directive|include
file|"cvs.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$CVSid: @(#)version.c 1.15 94/10/03 $"
decl_stmt|;
end_decl_stmt

begin_macro
name|USE
argument_list|(
argument|rcsid
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|version_string
init|=
literal|"\nConcurrent Versions System (CVS) 1.4 Alpha-2\n"
decl_stmt|;
end_decl_stmt

end_unit

