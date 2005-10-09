begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Command line option handling.    Copyright (C) 2002, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_OPTS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_OPTS_H
end_define

begin_function_decl
specifier|extern
name|void
name|decode_options
parameter_list|(
name|unsigned
name|int
name|argc
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_input_filename
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|cl_option
block|{
specifier|const
name|char
modifier|*
name|opt_text
decl_stmt|;
specifier|const
name|char
modifier|*
name|help
decl_stmt|;
name|unsigned
name|short
name|back_chain
decl_stmt|;
name|unsigned
name|char
name|opt_len
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|cl_option
name|cl_options
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|int
name|cl_options_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|lang_names
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CL_JOINED
value|(1<< 24)
end_define

begin_comment
comment|/* If takes joined argument.  */
end_comment

begin_define
define|#
directive|define
name|CL_SEPARATE
value|(1<< 25)
end_define

begin_comment
comment|/* If takes a separate argument.  */
end_comment

begin_define
define|#
directive|define
name|CL_REJECT_NEGATIVE
value|(1<< 26)
end_define

begin_comment
comment|/* Reject no- form.  */
end_comment

begin_define
define|#
directive|define
name|CL_MISSING_OK
value|(1<< 27)
end_define

begin_comment
comment|/* Missing argument OK (joined).  */
end_comment

begin_define
define|#
directive|define
name|CL_UINTEGER
value|(1<< 28)
end_define

begin_comment
comment|/* Argument is an integer>=0.  */
end_comment

begin_define
define|#
directive|define
name|CL_COMMON
value|(1<< 29)
end_define

begin_comment
comment|/* Language-independent.  */
end_comment

begin_define
define|#
directive|define
name|CL_UNDOCUMENTED
value|(1<< 30)
end_define

begin_comment
comment|/* Do not output with --help.  */
end_comment

begin_comment
comment|/* Input file names.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
modifier|*
name|in_fnames
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The count of input filenames.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|num_in_fnames
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

