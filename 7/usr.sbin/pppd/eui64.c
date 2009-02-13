begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*     eui64.c - EUI64 routines for IPv6CP.     Copyright (C) 1999  Tommi Komulainen<Tommi.Komulainen@iki.fi>      Redistribution and use in source and binary forms are permitted     provided that the above copyright notice and this paragraph are     duplicated in all such forms and that any documentation,     advertising materials, and other materials related to such     distribution and use acknowledge that the software was developed     by Tommi Komulainen.  The name of the author may not be used     to endorse or promote products derived from this software without     specific prior written permission.     THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR     IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED     WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.       $Id: eui64.c,v 1.3 1999/08/25 04:15:51 paulus Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|RCSID
value|"$Id: eui64.c,v 1.3 1999/08/25 04:15:51 paulus Exp $"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"pppd.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RCSID
end_ifdef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
name|RCSID
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * eui64_ntoa - Make an ascii representation of an interface identifier  */
end_comment

begin_function
name|char
modifier|*
name|eui64_ntoa
parameter_list|(
name|e
parameter_list|)
name|eui64_t
name|e
decl_stmt|;
block|{
specifier|static
name|char
name|buf
index|[
literal|32
index|]
decl_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
literal|32
argument_list|,
literal|"%02x%02x:%02x%02x:%02x%02x:%02x%02x"
argument_list|,
name|e
operator|.
name|e8
index|[
literal|0
index|]
argument_list|,
name|e
operator|.
name|e8
index|[
literal|1
index|]
argument_list|,
name|e
operator|.
name|e8
index|[
literal|2
index|]
argument_list|,
name|e
operator|.
name|e8
index|[
literal|3
index|]
argument_list|,
name|e
operator|.
name|e8
index|[
literal|4
index|]
argument_list|,
name|e
operator|.
name|e8
index|[
literal|5
index|]
argument_list|,
name|e
operator|.
name|e8
index|[
literal|6
index|]
argument_list|,
name|e
operator|.
name|e8
index|[
literal|7
index|]
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

end_unit

