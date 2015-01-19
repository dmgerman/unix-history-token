begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 The TCPDUMP project  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Original code by Ola Martin Lykkja (ola.lykkja@q-free.com)  */
end_comment

begin_define
define|#
directive|define
name|NETDISSECT_REWORKED
end_define

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
file|<tcpdump-stdinc.h>
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_comment
comment|/*    ISO 29281:2009    Intelligent Transport Systems . Communications access for land mobiles (CALM)    CALM non-IP networking */
end_comment

begin_comment
comment|/*  * This is the top level routine of the printer.  'bp' points  * to the calm header of the packet.  */
end_comment

begin_function
name|void
name|calm_fast_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|eth
parameter_list|,
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
name|u_int
name|length
parameter_list|)
block|{
name|int
name|srcNwref
init|=
name|bp
index|[
literal|0
index|]
decl_stmt|;
name|int
name|dstNwref
init|=
name|bp
index|[
literal|1
index|]
decl_stmt|;
name|length
operator|-=
literal|2
expr_stmt|;
name|bp
operator|+=
literal|2
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"CALM FAST src:%s; "
operator|,
name|etheraddr_string
argument_list|(
name|ndo
argument_list|,
name|eth
operator|+
literal|6
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"SrcNwref:%d; "
operator|,
name|srcNwref
operator|)
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"DstNwref:%d; "
operator|,
name|dstNwref
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ndo
operator|->
name|ndo_vflag
condition|)
name|ND_DEFAULTPRINT
argument_list|(
name|bp
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Local Variables:  * c-style: whitesmith  * c-basic-offset: 8  * End:  */
end_comment

end_unit

