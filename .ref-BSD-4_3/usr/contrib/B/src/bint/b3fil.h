begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
end_comment

begin_comment
comment|/*   $Header: b3fil.h,v 1.4 85/08/22 16:43:58 timo Exp $ */
end_comment

begin_comment
comment|/* File accessing */
end_comment

begin_function_decl
name|bool
name|ws_writable
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* enquire if write permission in workspace */
end_comment

begin_function_decl
name|unsigned
name|f_size
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* size of a file */
end_comment

begin_function_decl
name|bool
name|f_exists
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* enquire if a file exists */
end_comment

begin_function_decl
name|value
name|f_save
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* temporarily copy a file to somewhere safe */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INTEGRATION
end_ifndef

begin_function_decl
name|bool
name|f_interactive
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* enquire if a file is the keyboard/screen */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|value
name|new_fname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* devise a filename for a unit or target */
end_comment

begin_decl_stmt
specifier|extern
name|value
name|file_names
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of file names */
end_comment

begin_comment
comment|/* Procedure f_edit(); */
end_comment

begin_comment
comment|/* call the editor for a file */
end_comment

begin_comment
comment|/* Procedure f_rename(); */
end_comment

begin_comment
comment|/* rename a file */
end_comment

begin_comment
comment|/* Procedure f_delete(); */
end_comment

begin_comment
comment|/* delete a file */
end_comment

end_unit

