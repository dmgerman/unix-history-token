begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Null garbage collection for the GNU compiler.    Copyright (C) 1998, 1999, 2000, 2003, 2004, 2005    Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/* This version is used by the gen* programs and certain language-specific    targets (such as java), where we don't really need GC at all.    This prevents problems with pulling in all the tree stuff.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GENERATOR_FILE
end_ifdef

begin_include
include|#
directive|include
file|"bconfig.h"
end_include

begin_else
else|#
directive|else
end_else

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
file|"ggc.h"
end_include

begin_decl_stmt
name|void
modifier|*
name|ggc_alloc_typed_stat
argument_list|(
expr|enum
name|gt_types_enum
name|ARG_UNUSED
argument_list|(
name|gte
argument_list|)
argument_list|,
name|size_t
name|size
name|MEM_STAT_DECL
argument_list|)
block|{
return|return
name|xmalloc
argument_list|(
name|size
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|void
modifier|*
name|ggc_alloc_stat
parameter_list|(
name|size_t
name|size
name|MEM_STAT_DECL
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
name|ggc_alloc_cleared_stat
parameter_list|(
name|size_t
name|size
name|MEM_STAT_DECL
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
name|ggc_realloc_stat
parameter_list|(
name|void
modifier|*
name|x
parameter_list|,
name|size_t
name|size
name|MEM_STAT_DECL
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

begin_function
name|void
name|ggc_free
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|free
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

