begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Header file for GDB-specific command-line stuff.    Copyright 1986, 1989, 1990, 1992 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GDBCMD_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|GDBCMD_H
value|1
end_define

begin_include
include|#
directive|include
file|"command.h"
end_include

begin_comment
comment|/* Chain containing all defined commands.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|cmdlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined info subcommands.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|infolist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined enable subcommands. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|enablelist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined disable subcommands. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|disablelist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined delete subcommands. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|deletelist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined toggle subcommands. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|togglelist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined stop subcommands. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|stoplist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined "enable breakpoint" subcommands. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|enablebreaklist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined set subcommands */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|setlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined unset subcommands */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|unsetlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined show subcommands.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|showlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined \"set history\".  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|sethistlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined \"show history\".  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|showhistlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined \"unset history\".  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|unsethistlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined maintenance subcommands. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|maintenancelist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined "maintenance info" subcommands. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|maintenanceinfolist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chain containing all defined "maintenance print" subcommands. */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|maintenanceprintlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|setprintlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|showprintlist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|setchecklist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|showchecklist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|execute_user_command
name|PARAMS
argument_list|(
operator|(
expr|struct
name|cmd_list_element
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|execute_command
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
name|enum
name|command_control_type
name|execute_control_command
name|PARAMS
argument_list|(
operator|(
expr|struct
name|command_line
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_command_line
name|PARAMS
argument_list|(
operator|(
expr|struct
name|command_line
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|noop_completer
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|filename_completer
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
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
comment|/* !defined (GDBCMD_H) */
end_comment

end_unit

