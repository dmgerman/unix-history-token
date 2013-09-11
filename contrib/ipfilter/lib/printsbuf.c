begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 2012 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * $Id$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IPFILTER_SCAN
end_ifdef

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_include
include|#
directive|include
file|"netinet/ip_scan.h"
end_include

begin_function
name|void
name|printsbuf
parameter_list|(
name|buf
parameter_list|)
name|char
modifier|*
name|buf
decl_stmt|;
block|{
name|u_char
modifier|*
name|s
decl_stmt|;
name|int
name|i
decl_stmt|;
for|for
control|(
name|s
operator|=
operator|(
name|u_char
operator|*
operator|)
name|buf
operator|,
name|i
operator|=
name|ISC_TLEN
init|;
name|i
condition|;
name|i
operator|--
operator|,
name|s
operator|++
control|)
block|{
if|if
condition|(
name|ISPRINT
argument_list|(
operator|*
name|s
argument_list|)
condition|)
name|putchar
argument_list|(
operator|*
name|s
argument_list|)
expr_stmt|;
else|else
name|PRINTF
argument_list|(
literal|"\\%o"
argument_list|,
operator|*
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|printsbuf
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|printsbuf
parameter_list|(
name|buf
parameter_list|)
name|char
modifier|*
name|buf
decl_stmt|;
block|{
if|#
directive|if
literal|0
block|buf = buf;
comment|/* gcc -Wextra */
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

