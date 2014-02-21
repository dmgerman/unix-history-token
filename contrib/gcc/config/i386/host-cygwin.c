begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Cygwin host-specific hook definitions.  Copyright (C) 2004 Free Software Foundation, Inc.   This file is part of GCC.   GCC is free software; you can redistribute it and/or modify it  under the terms of the GNU General Public License as published  by the Free Software Foundation; either version 2, or (at your  option) any later version.   GCC is distributed in the hope that it will be useful, but WITHOUT  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public  License for more details.   You should have received a copy of the GNU General Public License  along with GCC; see the file COPYING. If not, write to the  Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,  MA 02110-1301, USA. */
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
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|"hosthooks.h"
end_include

begin_include
include|#
directive|include
file|"hosthooks-def.h"
end_include

begin_include
include|#
directive|include
file|"toplev.h"
end_include

begin_include
include|#
directive|include
file|"diagnostic.h"
end_include

begin_function_decl
specifier|static
name|void
modifier|*
name|cygwin_gt_pch_get_address
parameter_list|(
name|size_t
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|size_t
name|cygwin_gt_pch_alloc_granularity
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|HOST_HOOKS_GT_PCH_GET_ADDRESS
end_undef

begin_define
define|#
directive|define
name|HOST_HOOKS_GT_PCH_GET_ADDRESS
value|cygwin_gt_pch_get_address
end_define

begin_undef
undef|#
directive|undef
name|HOST_HOOKS_GT_PCH_ALLOC_GRANULARITY
end_undef

begin_define
define|#
directive|define
name|HOST_HOOKS_GT_PCH_ALLOC_GRANULARITY
value|cygwin_gt_pch_alloc_granularity
end_define

begin_comment
comment|/* Granularity for reserving address space.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|size_t
name|va_granularity
init|=
literal|0x10000
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  Return the alignment required for allocating virtual memory. */
end_comment

begin_function
specifier|static
name|size_t
name|cygwin_gt_pch_alloc_granularity
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|va_granularity
return|;
block|}
end_function

begin_comment
comment|/* Identify an address that's likely to be free in a subsequent invocation    of the compiler.  The area should be able to hold SIZE bytes.  FD is an    open file descriptor if the host would like to probe with mmap.  */
end_comment

begin_function
specifier|static
name|void
modifier|*
name|cygwin_gt_pch_get_address
parameter_list|(
name|size_t
name|sz
parameter_list|,
name|int
name|fd
parameter_list|)
block|{
name|void
modifier|*
name|base
decl_stmt|;
name|off_t
name|p
init|=
name|lseek
argument_list|(
name|fd
argument_list|,
literal|0
argument_list|,
name|SEEK_CUR
argument_list|)
decl_stmt|;
if|if
condition|(
name|p
operator|==
operator|(
name|off_t
operator|)
operator|-
literal|1
condition|)
name|fatal_error
argument_list|(
literal|"can't get position in PCH file: %m"
argument_list|)
expr_stmt|;
comment|/* Cygwin requires that the underlying file be at least       as large as the requested mapping.  */
if|if
condition|(
operator|(
name|size_t
operator|)
name|p
operator|<
name|sz
condition|)
block|{
if|if
condition|(
name|ftruncate
argument_list|(
name|fd
argument_list|,
name|sz
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|fatal_error
argument_list|(
literal|"can't extend PCH file: %m"
argument_list|)
expr_stmt|;
block|}
name|base
operator|=
name|mmap
argument_list|(
name|NULL
argument_list|,
name|sz
argument_list|,
name|PROT_READ
operator||
name|PROT_WRITE
argument_list|,
name|MAP_PRIVATE
argument_list|,
name|fd
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|base
operator|==
name|MAP_FAILED
condition|)
name|base
operator|=
name|NULL
expr_stmt|;
else|else
name|munmap
argument_list|(
name|base
argument_list|,
name|sz
argument_list|)
expr_stmt|;
if|if
condition|(
name|lseek
argument_list|(
name|fd
argument_list|,
name|p
argument_list|,
name|SEEK_SET
argument_list|)
operator|==
operator|(
name|off_t
operator|)
operator|-
literal|1
condition|)
name|fatal_error
argument_list|(
literal|"can't set position in PCH file: %m"
argument_list|)
expr_stmt|;
return|return
name|base
return|;
block|}
end_function

begin_decl_stmt
specifier|const
name|struct
name|host_hooks
name|host_hooks
init|=
name|HOST_HOOKS_INITIALIZER
decl_stmt|;
end_decl_stmt

end_unit

