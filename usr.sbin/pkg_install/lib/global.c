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
name|rcsid
index|[]
init|=
literal|"$Id: global.c,v 1.5 1997/02/22 16:09:48 peter Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * FreeBSD install - a package for the installation and maintainance  * of non-core utilities.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * Jordan K. Hubbard   * 18 July 1993  *  * Semi-convenient place to stick some needed globals.  *  */
end_comment

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_comment
comment|/* These are global for all utils */
end_comment

begin_decl_stmt
name|Boolean
name|Verbose
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Boolean
name|Fake
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Boolean
name|Force
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|AutoAnswer
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

end_unit

