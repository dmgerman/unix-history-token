begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* __fpending.c -- return the number of pending output bytes on a stream    Copyright (C) 2000 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Jim Meyering. */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"__fpending.h"
end_include

begin_function
name|size_t
name|__fpending
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|)
block|{
return|return
name|PENDING_OUTPUT_N_BYTES
return|;
block|}
end_function

end_unit

