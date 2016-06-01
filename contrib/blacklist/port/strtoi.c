begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: strtoi.c,v 1.3 2015/01/22 03:10:50 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2005 The DragonFly Project.  All rights reserved.  * Copyright (c) 2003 Citrus Project,  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Created by Kamil Rytarowski, based on ID:  * NetBSD: src/common/lib/libc/stdlib/strtoul.c,v 1.3 2008/08/20 19:58:34 oster Exp  */
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
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: strtoi.c,v 1.3 2015/01/22 03:10:50 christos Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<lib/libkern/libkern.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_STANDALONE
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<lib/libkern/libkern.h>
end_include

begin_include
include|#
directive|include
file|<lib/libsa/stand.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_FUNCNAME
value|strtoi
end_define

begin_define
define|#
directive|define
name|__TYPE
value|intmax_t
end_define

begin_define
define|#
directive|define
name|__WRAPPED
value|strtoimax
end_define

begin_if
if|#
directive|if
operator|!
name|HAVE_STRTOI
end_if

begin_include
include|#
directive|include
file|"_strtoi.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

