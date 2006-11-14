begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Obstack wrapper for GDB.     Copyright 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GDB_OBSTACK_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|GDB_OBSTACK_H
value|1
end_define

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_comment
comment|/* Unless explicitly specified, GDB obstacks always use xmalloc() and    xfree().  */
end_comment

begin_comment
comment|/* Note: ezannoni 2004-02-09: One could also specify the allocation    functions using a special init function for each obstack,    obstack_specify_allocation.  However we just use obstack_init and    let these defines here do the job.  While one could argue the    superiority of one approach over the other, we just chose one    throughout.  */
end_comment

begin_define
define|#
directive|define
name|obstack_chunk_alloc
value|xmalloc
end_define

begin_define
define|#
directive|define
name|obstack_chunk_free
value|xfree
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

