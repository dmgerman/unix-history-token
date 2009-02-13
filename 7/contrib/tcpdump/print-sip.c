begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Original code by Hannes Gredler (hannes@juniper.net)  */
end_comment

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
name|_U_
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/print-sip.c,v 1.1 2004/07/27 17:04:20 hannes Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_include
include|#
directive|include
file|"udp.h"
end_include

begin_function
name|void
name|sip_print
parameter_list|(
specifier|register
specifier|const
name|u_char
modifier|*
name|pptr
parameter_list|,
specifier|register
name|u_int
name|len
parameter_list|)
block|{
name|u_int
name|idx
decl_stmt|;
name|printf
argument_list|(
literal|"SIP, length: %u%s"
argument_list|,
name|len
argument_list|,
name|vflag
condition|?
literal|"\n\t"
else|:
literal|""
argument_list|)
expr_stmt|;
comment|/* in non-verbose mode just lets print the protocol and length */
if|if
condition|(
name|vflag
operator|<
literal|1
condition|)
return|return;
for|for
control|(
name|idx
operator|=
literal|0
init|;
name|idx
operator|<
name|len
condition|;
name|idx
operator|++
control|)
block|{
if|if
condition|(
name|EXTRACT_16BITS
argument_list|(
name|pptr
operator|+
name|idx
argument_list|)
operator|!=
literal|0x0d0a
condition|)
block|{
comment|/* linefeed ? */
name|safeputchar
argument_list|(
operator|*
operator|(
name|pptr
operator|+
name|idx
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"\n\t"
argument_list|)
expr_stmt|;
name|idx
operator|+=
literal|1
expr_stmt|;
block|}
block|}
comment|/* do we want to see an additionally hexdump ? */
if|if
condition|(
name|vflag
operator|>
literal|1
condition|)
name|print_unknown_data
argument_list|(
name|pptr
argument_list|,
literal|"\n\t"
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

