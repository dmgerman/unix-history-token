begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * gripes.h  *  * Copyright (c) 1990, 1991, John W. Eaton.  *  * You may distribute under the terms of the GNU General Public  * License as specified in the file COPYING that comes with the man  * distribution.  *  * John W. Eaton  * jwe@che.utexas.edu  * Department of Chemical Engineering  * The University of Texas at Austin  * Austin, Texas  78712  */
end_comment

begin_function_decl
specifier|extern
name|void
name|gripe_no_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_converting_name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_system_command
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_reading_man_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_not_found
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_invalid_section
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_manpath
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_incompatible
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_getting_mp_config
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_reading_mp_config
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_roff_command_from_file
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_roff_command_from_env
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gripe_roff_command_from_command_line
parameter_list|()
function_decl|;
end_function_decl

end_unit

