begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Support for complaint handling during symbol reading in GDB.    Copyright (C) 1990, 1991, 1992  Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"complaints.h"
end_include

begin_include
include|#
directive|include
file|"gdbcmd.h"
end_include

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_comment
comment|/* Structure to manage complaints about symbol file contents.  */
end_comment

begin_decl_stmt
name|struct
name|complaint
name|complaint_root
index|[
literal|1
index|]
init|=
block|{
block|{
operator|(
name|char
operator|*
operator|)
name|NULL
block|,
comment|/* Complaint message */
literal|0
block|,
comment|/* Complaint counter */
name|complaint_root
comment|/* Next complaint. */
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* How many complaints about a particular thing should be printed before    we stop whining about it?  Default is no whining at all, since so many    systems have ill-constructed symbol files.  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|stop_whining
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Should each complaint be self explanatory, or should we assume that    a series of complaints is being produced?    case 0:  self explanatory message.    case 1:  First message of a series that must start off with explanation.    case 2:  Subsequent message, when user already knows we are reading             symbols and we can just state our piece.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|complaint_series
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* External variables and functions referenced. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|info_verbose
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Functions to handle complaints during symbol reading.  */
end_comment

begin_comment
comment|/* Print a complaint about the input symbols, and link the complaint block    into a chain for later handling.  */
end_comment

begin_comment
comment|/* VARARGS */
end_comment

begin_function
name|void
name|complain
parameter_list|(
name|va_alist
parameter_list|)
function|va_dcl
block|{
name|va_list
name|args
decl_stmt|;
name|struct
name|complaint
modifier|*
name|complaint
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|complaint
operator|=
name|va_arg
argument_list|(
name|args
argument_list|,
expr|struct
name|complaint
operator|*
argument_list|)
expr_stmt|;
name|complaint
operator|->
name|counter
operator|++
expr_stmt|;
if|if
condition|(
name|complaint
operator|->
name|next
operator|==
name|NULL
condition|)
block|{
name|complaint
operator|->
name|next
operator|=
name|complaint_root
operator|->
name|next
expr_stmt|;
name|complaint_root
operator|->
name|next
operator|=
name|complaint
expr_stmt|;
block|}
if|if
condition|(
name|complaint
operator|->
name|counter
operator|>
name|stop_whining
condition|)
block|{
return|return;
block|}
name|wrap_here
argument_list|(
literal|""
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|complaint_series
operator|+
operator|(
name|info_verbose
operator|<<
literal|1
operator|)
condition|)
block|{
comment|/* Isolated messages, must be self-explanatory.  */
case|case
literal|0
case|:
name|begin_line
argument_list|()
expr_stmt|;
name|puts_filtered
argument_list|(
literal|"During symbol reading, "
argument_list|)
expr_stmt|;
name|wrap_here
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|vprintf_filtered
argument_list|(
name|complaint
operator|->
name|message
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|puts_filtered
argument_list|(
literal|".\n"
argument_list|)
expr_stmt|;
break|break;
comment|/* First of a series, without `set verbose'.  */
case|case
literal|1
case|:
name|begin_line
argument_list|()
expr_stmt|;
name|puts_filtered
argument_list|(
literal|"During symbol reading..."
argument_list|)
expr_stmt|;
name|vprintf_filtered
argument_list|(
name|complaint
operator|->
name|message
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|puts_filtered
argument_list|(
literal|"..."
argument_list|)
expr_stmt|;
name|wrap_here
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|complaint_series
operator|++
expr_stmt|;
break|break;
comment|/* Subsequent messages of a series, or messages under `set verbose'. 	 (We'll already have produced a "Reading in symbols for XXX..." 	 message and will clean up at the end with a newline.)  */
default|default:
name|vprintf_filtered
argument_list|(
name|complaint
operator|->
name|message
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|puts_filtered
argument_list|(
literal|"..."
argument_list|)
expr_stmt|;
name|wrap_here
argument_list|(
literal|""
argument_list|)
expr_stmt|;
block|}
comment|/* If GDB dumps core, we'd like to see the complaints first.  Presumably      GDB will not be sending so many complaints that this becomes a      performance hog.  */
name|gdb_flush
argument_list|(
name|gdb_stdout
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Clear out all complaint counters that have ever been incremented.    If sym_reading is 1, be less verbose about successive complaints,    since the messages are appearing all together during a command that    reads symbols (rather than scattered around as psymtabs get fleshed    out into symtabs at random times).  If noisy is 1, we are in a    noisy symbol reading command, and our caller will print enough    context for the user to figure it out.  */
end_comment

begin_function
name|void
name|clear_complaints
parameter_list|(
name|sym_reading
parameter_list|,
name|noisy
parameter_list|)
name|int
name|sym_reading
decl_stmt|;
name|int
name|noisy
decl_stmt|;
block|{
name|struct
name|complaint
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|p
operator|=
name|complaint_root
operator|->
name|next
init|;
name|p
operator|!=
name|complaint_root
condition|;
name|p
operator|=
name|p
operator|->
name|next
control|)
block|{
name|p
operator|->
name|counter
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|sym_reading
operator|&&
operator|!
name|noisy
operator|&&
name|complaint_series
operator|>
literal|1
condition|)
block|{
comment|/* Terminate previous series, since caller won't.  */
name|puts_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|complaint_series
operator|=
name|sym_reading
condition|?
literal|1
operator|+
name|noisy
else|:
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|void
name|_initialize_complaints
parameter_list|()
block|{
name|add_show_from_set
argument_list|(
name|add_set_cmd
argument_list|(
literal|"complaints"
argument_list|,
name|class_support
argument_list|,
name|var_zinteger
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|stop_whining
argument_list|,
literal|"Set max number of complaints about incorrect symbols."
argument_list|,
operator|&
name|setlist
argument_list|)
argument_list|,
operator|&
name|showlist
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

