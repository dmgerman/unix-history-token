begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Simulate breakpoints by patching locations in the target system, for GDB.    Copyright 1990, 1991, 1995 Free Software Foundation, Inc.    Contributed by Cygnus Support.  Written by John Gilmore.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/* Either BREAKPOINT should be defined, or both of LITTLE_BREAKPOINT,    BIG_BREAKPOINT should be defined.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BREAKPOINT
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|LITTLE_BREAKPOINT
argument_list|)
operator|&&
name|defined
argument_list|(
name|BIG_BREAKPOINT
argument_list|)
operator|)
end_if

begin_comment
comment|/* This file is only useful if BREAKPOINT is set.  If not, we punt.  */
end_comment

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"breakpoint.h"
end_include

begin_include
include|#
directive|include
file|"inferior.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_comment
comment|/* If the target isn't bi-endian, just pretend it is.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BREAKPOINT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LITTLE_BREAKPOINT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BIG_BREAKPOINT
argument_list|)
end_if

begin_define
define|#
directive|define
name|LITTLE_BREAKPOINT
value|BREAKPOINT
end_define

begin_define
define|#
directive|define
name|BIG_BREAKPOINT
value|BREAKPOINT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the sequence of bytes we insert for a breakpoint.  On some    machines, breakpoints are handled by the target environment and we    don't have to worry about them here.  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|big_break_insn
index|[]
init|=
name|BIG_BREAKPOINT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|little_break_insn
index|[]
init|=
name|LITTLE_BREAKPOINT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* FIXME: We assume big and little breakpoints are the same size.  */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT_LEN
value|(sizeof (big_break_insn))
end_define

begin_comment
comment|/* Insert a breakpoint on targets that don't have any better breakpoint    support.  We read the contents of the target location and stash it,    then overwrite it with a breakpoint instruction.  ADDR is the target    location in the target machine.  CONTENTS_CACHE is a pointer to     memory allocated for saving the target contents.  It is guaranteed    by the caller to be long enough to save BREAKPOINT_LEN bytes (this    is accomplished via BREAKPOINT_MAX).  */
end_comment

begin_function
name|int
name|memory_insert_breakpoint
parameter_list|(
name|addr
parameter_list|,
name|contents_cache
parameter_list|)
name|CORE_ADDR
name|addr
decl_stmt|;
name|char
modifier|*
name|contents_cache
decl_stmt|;
block|{
name|int
name|val
decl_stmt|;
name|val
operator|=
name|target_read_memory
argument_list|(
name|addr
argument_list|,
name|contents_cache
argument_list|,
name|BREAKPOINT_LEN
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|TARGET_BYTE_ORDER
operator|==
name|BIG_ENDIAN
condition|)
name|val
operator|=
name|target_write_memory
argument_list|(
name|addr
argument_list|,
operator|(
name|char
operator|*
operator|)
name|big_break_insn
argument_list|,
name|BREAKPOINT_LEN
argument_list|)
expr_stmt|;
else|else
name|val
operator|=
name|target_write_memory
argument_list|(
name|addr
argument_list|,
operator|(
name|char
operator|*
operator|)
name|little_break_insn
argument_list|,
name|BREAKPOINT_LEN
argument_list|)
expr_stmt|;
block|}
return|return
name|val
return|;
block|}
end_function

begin_function
name|int
name|memory_remove_breakpoint
parameter_list|(
name|addr
parameter_list|,
name|contents_cache
parameter_list|)
name|CORE_ADDR
name|addr
decl_stmt|;
name|char
modifier|*
name|contents_cache
decl_stmt|;
block|{
return|return
name|target_write_memory
argument_list|(
name|addr
argument_list|,
name|contents_cache
argument_list|,
name|BREAKPOINT_LEN
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* FIXME: This is a hack and should depend on the debugging target.    See comment in breakpoint.c where this is used.  */
end_comment

begin_decl_stmt
name|int
name|memory_breakpoint_size
init|=
name|BREAKPOINT_LEN
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BREAKPOINT */
end_comment

begin_decl_stmt
name|char
name|nogo
index|[]
init|=
literal|"Breakpoints not implemented for this target."
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|memory_insert_breakpoint
parameter_list|(
name|addr
parameter_list|,
name|contents_cache
parameter_list|)
name|CORE_ADDR
name|addr
decl_stmt|;
name|char
modifier|*
name|contents_cache
decl_stmt|;
block|{
name|error
argument_list|(
name|nogo
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|/* lint */
block|}
end_function

begin_function
name|int
name|memory_remove_breakpoint
parameter_list|(
name|addr
parameter_list|,
name|contents_cache
parameter_list|)
name|CORE_ADDR
name|addr
decl_stmt|;
name|char
modifier|*
name|contents_cache
decl_stmt|;
block|{
name|error
argument_list|(
name|nogo
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
comment|/* lint */
block|}
end_function

begin_decl_stmt
name|int
name|memory_breakpoint_size
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BREAKPOINT */
end_comment

end_unit

