begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Null garbage collection for the GNU compiler.    Copyright (C) 1998, 1999, 2000, 2003    Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_comment
comment|/* This version is used by the gen* programs, where we don't really    need GC at all.  This prevents problems with pulling in all the    tree stuff.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"ggc.h"
end_include

begin_decl_stmt
name|struct
name|alloc_zone
modifier|*
name|rtl_zone
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|alloc_zone
modifier|*
name|garbage_zone
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_function
name|void
modifier|*
name|ggc_alloc_typed
parameter_list|(
name|enum
name|gt_types_enum
name|gte
name|ATTRIBUTE_UNUSED
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
return|return
name|xmalloc
argument_list|(
name|size
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|ggc_alloc
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
return|return
name|xmalloc
argument_list|(
name|size
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|ggc_alloc_zone
parameter_list|(
name|size_t
name|size
parameter_list|,
name|struct
name|alloc_zone
modifier|*
name|zone
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
return|return
name|xmalloc
argument_list|(
name|size
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|ggc_alloc_cleared
parameter_list|(
name|size_t
name|size
parameter_list|)
block|{
return|return
name|xcalloc
argument_list|(
name|size
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|ggc_realloc
parameter_list|(
name|void
modifier|*
name|x
parameter_list|,
name|size_t
name|size
parameter_list|)
block|{
return|return
name|xrealloc
argument_list|(
name|x
argument_list|,
name|size
argument_list|)
return|;
block|}
end_function

end_unit

