begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Support for GDB maintenance commands.    Copyright (C) 1992 Free Software Foundation, Inc.    Written by Fred Fish at Cygnus Support.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_if
if|#
directive|if
name|MAINTENANCE_CMDS
end_if

begin_comment
comment|/* Entire file goes away if not including maint cmds */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"command.h"
end_include

begin_include
include|#
directive|include
file|"gdbcmd.h"
end_include

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"gdbtypes.h"
end_include

begin_include
include|#
directive|include
file|"demangle.h"
end_include

begin_decl_stmt
specifier|static
name|void
name|maintenance_command
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

begin_decl_stmt
specifier|static
name|void
name|maintenance_dump_me
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

begin_decl_stmt
specifier|static
name|void
name|maintenance_demangle
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
comment|/*  LOCAL FUNCTION  	maintenance_command -- access the maintenance subcommands  SYNOPSIS  	void maintenance_command (char *args, int from_tty)  DESCRIPTION  */
end_comment

begin_function
specifier|static
name|void
name|maintenance_command
parameter_list|(
name|args
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
name|printf
argument_list|(
literal|"\"maintenance\" must be followed by the name of a maintenance command.\n"
argument_list|)
expr_stmt|;
name|help_list
argument_list|(
name|maintenancelist
argument_list|,
literal|"maintenance "
argument_list|,
operator|-
literal|1
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|void
name|maintenance_dump_me
parameter_list|(
name|args
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
if|if
condition|(
name|query
argument_list|(
literal|"Should GDB dump core? "
argument_list|)
condition|)
block|{
name|signal
argument_list|(
name|SIGQUIT
argument_list|,
name|SIG_DFL
argument_list|)
expr_stmt|;
name|kill
argument_list|(
name|getpid
argument_list|()
argument_list|,
name|SIGQUIT
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  Someday we should allow demangling for things other than just     explicit strings.  For example, we might want to be able to     specify the address of a string in either GDB's process space     or the debuggee's process space, and have gdb fetch and demangle     that string.  If we have a char* pointer "ptr" that points to     a string, we might want to be able to given just the name and     have GDB demangle and print what it points to, etc.  (FIXME) */
end_comment

begin_function
specifier|static
name|void
name|maintenance_demangle
parameter_list|(
name|args
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
name|char
modifier|*
name|demangled
decl_stmt|;
if|if
condition|(
name|args
operator|==
name|NULL
operator|||
operator|*
name|args
operator|==
literal|'\0'
condition|)
block|{
name|printf
argument_list|(
literal|"\"maintenance demangle\" takes an argument to demangle.\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|demangled
operator|=
name|cplus_demangle
argument_list|(
name|args
argument_list|,
name|DMGL_ANSI
operator||
name|DMGL_PARAMS
argument_list|)
expr_stmt|;
if|if
condition|(
name|demangled
operator|!=
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|demangled
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|demangled
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"Can't demangle \"%s\"\n"
argument_list|,
name|args
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/* The "maintenance info" command is defined as a prefix, with allow_unknown 0.    Therefore, its own definition is called only for "maintenance info" with    no args.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|void
name|maintenance_info_command
parameter_list|(
name|arg
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|arg
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
name|printf
argument_list|(
literal|"\"maintenance info\" must be followed by the name of an info command.\n"
argument_list|)
expr_stmt|;
name|help_list
argument_list|(
name|maintenanceinfolist
argument_list|,
literal|"maintenance info "
argument_list|,
operator|-
literal|1
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* The "maintenance print" command is defined as a prefix, with allow_unknown    0.  Therefore, its own definition is called only for "maintenance print"    with no args.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|void
name|maintenance_print_command
parameter_list|(
name|arg
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|arg
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
name|printf
argument_list|(
literal|"\"maintenance print\" must be followed by the name of a print command.\n"
argument_list|)
expr_stmt|;
name|help_list
argument_list|(
name|maintenanceprintlist
argument_list|,
literal|"maintenance print "
argument_list|,
operator|-
literal|1
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  GLOBAL FUNCTION  	_initialize_maint_cmds -- initialize the process file system stuff  SYNOPSIS  	void _initialize_maint_cmds (void)  DESCRIPTION  	Do required initializations during gdb startup for using the 	/proc file system interface.  */
end_comment

begin_function
name|void
name|_initialize_maint_cmds
parameter_list|()
block|{
name|add_prefix_cmd
argument_list|(
literal|"maintenance"
argument_list|,
name|class_maintenance
argument_list|,
name|maintenance_command
argument_list|,
literal|"Commands for use by GDB maintainers.\n\ Includes commands to dump specific internal GDB structures in\n\ a human readable form, to cause GDB to deliberately dump core,\n\ to test internal functions such as the C++ demangler, etc."
argument_list|,
operator|&
name|maintenancelist
argument_list|,
literal|"maintenance "
argument_list|,
literal|0
argument_list|,
operator|&
name|cmdlist
argument_list|)
expr_stmt|;
name|add_com_alias
argument_list|(
literal|"mt"
argument_list|,
literal|"maintenance"
argument_list|,
name|class_maintenance
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|add_prefix_cmd
argument_list|(
literal|"info"
argument_list|,
name|class_maintenance
argument_list|,
name|maintenance_info_command
argument_list|,
literal|"Commands for showing internal info about the program being debugged."
argument_list|,
operator|&
name|maintenanceinfolist
argument_list|,
literal|"maintenance info "
argument_list|,
literal|0
argument_list|,
operator|&
name|maintenancelist
argument_list|)
expr_stmt|;
name|add_prefix_cmd
argument_list|(
literal|"print"
argument_list|,
name|class_maintenance
argument_list|,
name|maintenance_print_command
argument_list|,
literal|"Maintenance command for printing GDB internal state."
argument_list|,
operator|&
name|maintenanceprintlist
argument_list|,
literal|"maintenance print "
argument_list|,
literal|0
argument_list|,
operator|&
name|maintenancelist
argument_list|)
expr_stmt|;
name|add_cmd
argument_list|(
literal|"dump-me"
argument_list|,
name|class_maintenance
argument_list|,
name|maintenance_dump_me
argument_list|,
literal|"Get fatal error; make debugger dump its core.\n\ GDB sets it's handling of SIGQUIT back to SIG_DFL and then sends\n\ itself a SIGQUIT signal."
argument_list|,
operator|&
name|maintenancelist
argument_list|)
expr_stmt|;
name|add_cmd
argument_list|(
literal|"demangle"
argument_list|,
name|class_maintenance
argument_list|,
name|maintenance_demangle
argument_list|,
literal|"Demangle a C++ mangled name.\n\ Call internal GDB demangler routine to demangle a C++ link name\n\ and prints the result."
argument_list|,
operator|&
name|maintenancelist
argument_list|)
expr_stmt|;
name|add_cmd
argument_list|(
literal|"type"
argument_list|,
name|class_maintenance
argument_list|,
name|maintenance_print_type
argument_list|,
literal|"Print a type chain for a given symbol.\n\ For each node in a type chain, print the raw data for each member of\n\ the type structure, and the interpretation of the data."
argument_list|,
operator|&
name|maintenanceprintlist
argument_list|)
expr_stmt|;
name|add_cmd
argument_list|(
literal|"symbols"
argument_list|,
name|class_maintenance
argument_list|,
name|maintenance_print_symbols
argument_list|,
literal|"Print dump of current symbol definitions.\n\ Entries in the full symbol table are dumped to file OUTFILE.\n\ If a SOURCE file is specified, dump only that file's symbols."
argument_list|,
operator|&
name|maintenanceprintlist
argument_list|)
expr_stmt|;
name|add_cmd
argument_list|(
literal|"msymbols"
argument_list|,
name|class_maintenance
argument_list|,
name|maintenance_print_msymbols
argument_list|,
literal|"Print dump of current minimal symbol definitions.\n\ Entries in the minimal symbol table are dumped to file OUTFILE.\n\ If a SOURCE file is specified, dump only that file's minimal symbols."
argument_list|,
operator|&
name|maintenanceprintlist
argument_list|)
expr_stmt|;
name|add_cmd
argument_list|(
literal|"psymbols"
argument_list|,
name|class_maintenance
argument_list|,
name|maintenance_print_psymbols
argument_list|,
literal|"Print dump of current partial symbol definitions.\n\ Entries in the partial symbol table are dumped to file OUTFILE.\n\ If a SOURCE file is specified, dump only that file's partial symbols."
argument_list|,
operator|&
name|maintenanceprintlist
argument_list|)
expr_stmt|;
name|add_cmd
argument_list|(
literal|"objfiles"
argument_list|,
name|class_maintenance
argument_list|,
name|maintenance_print_objfiles
argument_list|,
literal|"Print dump of current object file definitions."
argument_list|,
operator|&
name|maintenanceprintlist
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAINTENANCE_CMDS */
end_comment

end_unit

