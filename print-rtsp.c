begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  */
end_comment

begin_comment
comment|/* \summary: Real Time Streaming Protocol (RTSP) printer */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netdissect-stdinc.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"netdissect.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|rtspcmds
index|[]
init|=
block|{
literal|"DESCRIBE"
block|,
literal|"ANNOUNCE"
block|,
literal|"GET_PARAMETER"
block|,
literal|"OPTIONS"
block|,
literal|"PAUSE"
block|,
literal|"PLAY"
block|,
literal|"RECORD"
block|,
literal|"REDIRECT"
block|,
literal|"SETUP"
block|,
literal|"SET_PARAMETER"
block|,
literal|"TEARDOWN"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|rtsp_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|pptr
parameter_list|,
name|u_int
name|len
parameter_list|)
block|{
name|txtproto_print
argument_list|(
name|ndo
argument_list|,
name|pptr
argument_list|,
name|len
argument_list|,
literal|"rtsp"
argument_list|,
name|rtspcmds
argument_list|,
name|RESP_CODE_SECOND_TOKEN
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

