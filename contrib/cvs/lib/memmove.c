begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* memmove -- copy memory regions of arbitary length    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  */
end_comment

begin_comment
comment|/*  NAME  	memmove -- copy memory regions of arbitary length  SYNOPSIS  	void memmove (void *out, const void *in, size_t n);  DESCRIPTION  	Copy LENGTH bytes from memory region pointed to by IN to memory 	region pointed to by OUT.  	Regions can be overlapping. */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|size_t
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
modifier|*
name|memmove
parameter_list|(
name|out
parameter_list|,
name|in
parameter_list|,
name|length
parameter_list|)
name|void
modifier|*
name|out
decl_stmt|;
specifier|const
name|void
modifier|*
name|in
decl_stmt|;
name|size_t
name|length
decl_stmt|;
block|{
name|bcopy
argument_list|(
name|in
argument_list|,
name|out
argument_list|,
name|length
argument_list|)
expr_stmt|;
return|return
name|out
return|;
block|}
end_function

end_unit

