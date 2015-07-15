begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2007  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: os.c,v 1.8 2007/06/19 23:47:19 tbox Exp $ */
end_comment

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<isc/os.h>
end_include

begin_decl_stmt
specifier|static
name|BOOL
name|bInit
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|SYSTEM_INFO
name|SystemInfo
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|initialize_action
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|bInit
condition|)
return|return;
name|GetSystemInfo
argument_list|(
operator|&
name|SystemInfo
argument_list|)
expr_stmt|;
name|bInit
operator|=
name|TRUE
expr_stmt|;
block|}
end_function

begin_function
name|unsigned
name|int
name|isc_os_ncpus
parameter_list|(
name|void
parameter_list|)
block|{
name|long
name|ncpus
init|=
literal|1
decl_stmt|;
name|initialize_action
argument_list|()
expr_stmt|;
name|ncpus
operator|=
name|SystemInfo
operator|.
name|dwNumberOfProcessors
expr_stmt|;
if|if
condition|(
name|ncpus
operator|<=
literal|0
condition|)
name|ncpus
operator|=
literal|1
expr_stmt|;
return|return
operator|(
operator|(
name|unsigned
name|int
operator|)
name|ncpus
operator|)
return|;
block|}
end_function

end_unit

