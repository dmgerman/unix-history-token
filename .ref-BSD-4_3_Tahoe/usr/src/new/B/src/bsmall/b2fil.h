begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: b2fil.h,v 1.1 84/06/28 00:48:48 timo Exp $ */
end_comment

begin_comment
comment|/* File accessing */
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

begin_function_decl
name|value
name|f_uname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* devise a filename for a unit */
end_comment

begin_function_decl
name|value
name|f_tname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* devise a filename for a target */
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
comment|/*enquire if a file exists*/
end_comment

begin_function_decl
name|bool
name|f_interactive
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*enquire if a file is the keyboard/screen*/
end_comment

begin_comment
comment|/* Procedure lst_uhds(); */
end_comment

begin_comment
comment|/*list the headings of units*/
end_comment

begin_define
define|#
directive|define
name|FHW
value|'\''
end_define

begin_define
define|#
directive|define
name|FZR
value|'<'
end_define

begin_define
define|#
directive|define
name|FMN
value|'"'
end_define

begin_define
define|#
directive|define
name|FDY
value|'>'
end_define

end_unit

