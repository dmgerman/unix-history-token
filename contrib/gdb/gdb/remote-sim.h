begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file defines the interface between the simulator and gdb.    Copyright (C) 1993, 1994 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|REMOTE_SIM_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|REMOTE_SIM_H
value|1
end_define

begin_include
include|#
directive|include
file|"callback.h"
end_include

begin_comment
comment|/* This file is used when building stand-alone simulators, so isolate this    file from gdb.  */
end_comment

begin_comment
comment|/* Pick up CORE_ADDR_TYPE if defined (from gdb), otherwise use same value as    gdb does (unsigned int - from defs.h).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CORE_ADDR_TYPE
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|SIM_ADDR
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|CORE_ADDR_TYPE
name|SIM_ADDR
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Callbacks.    The simulator may use the following callbacks (gdb routines) which the    standalone program must provide.     void printf_filtered (char *msg, ...);    void error /-* noreturn *-/ (char *msg, ...);    void *xmalloc (long size);    int sim_callback_write_stdout (char *, int len);     The new way of doing I/O is to use the pointer provided by GDB    via the sim_set_callbacks call, look in callbacks.c to see what    can be done. */
end_comment

begin_comment
comment|/* Main simulator entry points ...     All functions that can get an error must call the gdb routine `error',    they can only return upon success.  */
end_comment

begin_comment
comment|/* Initialize the simulator.  This function is called when the simulator    is selected from the command line. ARGS is passed from the command line    and can be used to select whatever run time options the simulator provides.    ARGS is the raw character string and must be parsed by the simulator,    which is trivial to do with the buildargv function in libiberty.    It is ok to do nothing.  */
end_comment

begin_decl_stmt
name|void
name|sim_open
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|args
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Terminate usage of the simulator.  This may involve freeing target memory    and closing any open files and mmap'd areas.  You cannot assume sim_kill    has already been called.    QUITTING is non-zero if we cannot hang on errors.  */
end_comment

begin_decl_stmt
name|void
name|sim_close
name|PARAMS
argument_list|(
operator|(
name|int
name|quitting
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Load program PROG into the simulator.    Return non-zero if you wish the caller to handle it    (it is done this way because most simulators can use gr_load_image,    but defining it as a callback seems awkward).  */
end_comment

begin_decl_stmt
name|int
name|sim_load
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|prog
operator|,
name|int
name|from_tty
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prepare to run the simulated program.    START_ADDRESS is, yes, you guessed it, the start address of the program.    ARGV and ENV are NULL terminated lists of pointers.    Gdb will set the start address via sim_store_register as well, but    standalone versions of existing simulators are not set up to cleanly call    sim_store_register, so the START_ADDRESS argument is there as a    workaround.  */
end_comment

begin_decl_stmt
name|void
name|sim_create_inferior
name|PARAMS
argument_list|(
operator|(
name|SIM_ADDR
name|start_address
operator|,
name|char
operator|*
operator|*
name|argv
operator|,
name|char
operator|*
operator|*
name|env
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Kill the running program.    This may involve closing any open files and deleting any mmap'd areas.  */
end_comment

begin_decl_stmt
name|void
name|sim_kill
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read LENGTH bytes of the simulated program's memory and store in BUF.    Result is number of bytes read, or zero if error.  */
end_comment

begin_decl_stmt
name|int
name|sim_read
name|PARAMS
argument_list|(
operator|(
name|SIM_ADDR
name|mem
operator|,
name|unsigned
name|char
operator|*
name|buf
operator|,
name|int
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Store LENGTH bytes from BUF in the simulated program's memory.    Result is number of bytes write, or zero if error.  */
end_comment

begin_decl_stmt
name|int
name|sim_write
name|PARAMS
argument_list|(
operator|(
name|SIM_ADDR
name|mem
operator|,
name|unsigned
name|char
operator|*
name|buf
operator|,
name|int
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fetch register REGNO and store the raw value in BUF.  */
end_comment

begin_decl_stmt
name|void
name|sim_fetch_register
name|PARAMS
argument_list|(
operator|(
name|int
name|regno
operator|,
name|unsigned
name|char
operator|*
name|buf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Store register REGNO from BUF (in raw format).  */
end_comment

begin_decl_stmt
name|void
name|sim_store_register
name|PARAMS
argument_list|(
operator|(
name|int
name|regno
operator|,
name|unsigned
name|char
operator|*
name|buf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print some interesting information about the simulator.    VERBOSE is non-zero for the wordy version.  */
end_comment

begin_decl_stmt
name|void
name|sim_info
name|PARAMS
argument_list|(
operator|(
name|int
name|verbose
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Fetch why the program stopped.    SIGRC will contain either the argument to exit() or the signal number.  */
end_comment

begin_enum
enum|enum
name|sim_stop
block|{
name|sim_exited
block|,
name|sim_stopped
block|,
name|sim_signalled
block|}
enum|;
end_enum

begin_decl_stmt
name|void
name|sim_stop_reason
name|PARAMS
argument_list|(
operator|(
expr|enum
name|sim_stop
operator|*
name|reason
operator|,
name|int
operator|*
name|sigrc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Run (or resume) the program.  */
end_comment

begin_decl_stmt
name|void
name|sim_resume
name|PARAMS
argument_list|(
operator|(
name|int
name|step
operator|,
name|int
name|siggnal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Passthru for other commands that the simulator might support. */
end_comment

begin_decl_stmt
name|void
name|sim_do_command
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|cmd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Callbacks for the simulator to use. */
end_comment

begin_decl_stmt
name|int
name|sim_callback_write_stdout
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Provide simulator with a standard host_callback_struct. */
end_comment

begin_decl_stmt
name|void
name|sim_set_callbacks
name|PARAMS
argument_list|(
operator|(
expr|struct
name|host_callback_struct
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (REMOTE_SIM_H) */
end_comment

end_unit

