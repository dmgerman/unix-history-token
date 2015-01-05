begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: openssl-compat.c,v 1.19 2014/07/02 05:28:07 djm Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2005 Darren Tucker<dtucker@zip.com.au>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER  * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING  * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_define
define|#
directive|define
name|SSH_DONT_OVERLOAD_OPENSSL_FUNCS
end_define

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OPENSSL_ENGINE
end_ifdef

begin_include
include|#
directive|include
file|<openssl/engine.h>
end_include

begin_include
include|#
directive|include
file|<openssl/conf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_include
include|#
directive|include
file|"openssl-compat.h"
end_include

begin_comment
comment|/*  * OpenSSL version numbers: MNNFFPPS: major minor fix patch status  * We match major, minor, fix and status (not patch) for<1.0.0.  * After that, we acceptable compatible fix versions (so we  * allow 1.0.1 to work with 1.0.0). Going backwards is only allowed  * within a patch series.  */
end_comment

begin_function
name|int
name|ssh_compatible_openssl
parameter_list|(
name|long
name|headerver
parameter_list|,
name|long
name|libver
parameter_list|)
block|{
name|long
name|mask
decl_stmt|,
name|hfix
decl_stmt|,
name|lfix
decl_stmt|;
comment|/* exact match is always OK */
if|if
condition|(
name|headerver
operator|==
name|libver
condition|)
return|return
literal|1
return|;
comment|/* for versions< 1.0.0, major,minor,fix,status must match */
if|if
condition|(
name|headerver
operator|<
literal|0x1000000f
condition|)
block|{
name|mask
operator|=
literal|0xfffff00fL
expr_stmt|;
comment|/* major,minor,fix,status */
return|return
operator|(
name|headerver
operator|&
name|mask
operator|)
operator|==
operator|(
name|libver
operator|&
name|mask
operator|)
return|;
block|}
comment|/* 	 * For versions>= 1.0.0, major,minor,status must match and library 	 * fix version must be equal to or newer than the header. 	 */
name|mask
operator|=
literal|0xfff0000fL
expr_stmt|;
comment|/* major,minor,status */
name|hfix
operator|=
operator|(
name|headerver
operator|&
literal|0x000ff000
operator|)
operator|>>
literal|12
expr_stmt|;
name|lfix
operator|=
operator|(
name|libver
operator|&
literal|0x000ff000
operator|)
operator|>>
literal|12
expr_stmt|;
if|if
condition|(
operator|(
name|headerver
operator|&
name|mask
operator|)
operator|==
operator|(
name|libver
operator|&
name|mask
operator|)
operator|&&
name|lfix
operator|>=
name|hfix
condition|)
return|return
literal|1
return|;
return|return
literal|0
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OPENSSL_ENGINE
end_ifdef

begin_function
name|void
name|ssh_OpenSSL_add_all_algorithms
parameter_list|(
name|void
parameter_list|)
block|{
name|OpenSSL_add_all_algorithms
argument_list|()
expr_stmt|;
comment|/* Enable use of crypto hardware */
name|ENGINE_load_builtin_engines
argument_list|()
expr_stmt|;
name|ENGINE_register_all_complete
argument_list|()
expr_stmt|;
name|OPENSSL_config
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

