begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Simulate breakpoints by patching locations in the target system, for GDB.    Copyright 1990, 1991 Free Software Foundation, Inc.    Contributed by Cygnus Support.  Written by John Gilmore.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BREAKPOINT
end_ifdef

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
comment|/* This is the sequence of bytes we insert for a breakpoint.  On some    machines, breakpoints are handled by the target environment and we    don't have to worry about them here.  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|break_insn
index|[]
init|=
name|BREAKPOINT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is only to check that BREAKPOINT fits in BREAKPOINT_MAX bytes.  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|check_break_insn_size
index|[
name|BREAKPOINT_MAX
index|]
init|=
name|BREAKPOINT
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Insert a breakpoint on targets that don't have any better breakpoint    support.  We read the contents of the target location and stash it,    then overwrite it with a breakpoint instruction.  ADDR is the target    location in the target machine.  CONTENTS_CACHE is a pointer to     memory allocated for saving the target contents.  It is guaranteed    by the caller to be long enough to save sizeof BREAKPOINT bytes (this    is accomplished via BREAKPOINT_MAX).  */
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
sizeof|sizeof
name|break_insn
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|==
literal|0
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
name|break_insn
argument_list|,
sizeof|sizeof
name|break_insn
argument_list|)
expr_stmt|;
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
sizeof|sizeof
name|break_insn
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
sizeof|sizeof
argument_list|(
name|break_insn
argument_list|)
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

