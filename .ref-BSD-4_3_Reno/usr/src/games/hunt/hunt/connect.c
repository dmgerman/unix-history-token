begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)connect.c	5.2 (Berkeley) 6/27/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  *  Hunt  *  Copyright (c) 1985 Conrad C. Huang, Gregory S. Couch, Kenneth C.R.C. Arnold  *  San Francisco, California  */
end_comment

begin_include
include|#
directive|include
file|"hunt.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_macro
name|do_connect
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|long
name|uid
decl_stmt|;
specifier|extern
name|char
modifier|*
name|ttyname
parameter_list|()
function_decl|;
name|uid
operator|=
name|htonl
argument_list|(
name|getuid
argument_list|()
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|write
argument_list|(
name|Socket
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|uid
argument_list|,
sizeof|sizeof
name|uid
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|write
argument_list|(
name|Socket
argument_list|,
name|name
argument_list|,
name|NAMELEN
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|Buf
argument_list|,
name|ttyname
argument_list|(
name|fileno
argument_list|(
name|stderr
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|write
argument_list|(
name|Socket
argument_list|,
name|Buf
argument_list|,
name|NAMELEN
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MONITOR
operator|(
name|void
operator|)
name|write
argument_list|(
name|Socket
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|Am_monitor
argument_list|,
sizeof|sizeof
name|Am_monitor
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|MONITOR
block|}
end_block

end_unit

