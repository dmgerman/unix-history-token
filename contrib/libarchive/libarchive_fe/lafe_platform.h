begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This header is the first thing included in any of the libarchive_fe  * source files.  As far as possible, platform-specific issues should  * be dealt with here and not within individual source files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LAFE_PLATFORM_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|LAFE_PLATFORM_H_INCLUDED
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLATFORM_CONFIG_H
argument_list|)
end_if

begin_comment
comment|/* Use hand-built config.h in environments that need it. */
end_comment

begin_include
include|#
directive|include
include|PLATFORM_CONFIG_H
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Read config.h or die trying. */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get a real definition for __FBSDID if we can */
end_comment

begin_if
if|#
directive|if
name|HAVE_SYS_CDEFS_H
end_if

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If not, define it so as to avoid dangling semicolons. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FBSDID
end_ifndef

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|a
parameter_list|)
value|struct _undefined_hack
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

