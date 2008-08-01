begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: bsd-statvfs.c,v 1.1 2008/06/08 17:32:29 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008 Darren Tucker<dtucker@zip.com.au>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER  * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING  * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STATVFS
end_ifndef

begin_function
name|int
name|statvfs
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|statvfs
modifier|*
name|buf
parameter_list|)
block|{
name|errno
operator|=
name|ENOSYS
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FSTATVFS
end_ifndef

begin_function
name|int
name|fstatvfs
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|statvfs
modifier|*
name|buf
parameter_list|)
block|{
name|errno
operator|=
name|ENOSYS
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

