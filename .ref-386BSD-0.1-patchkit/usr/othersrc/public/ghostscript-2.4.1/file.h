begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* file.h */
end_comment

begin_comment
comment|/* Common declarations for zfile.c and zfileio.c */
end_comment

begin_comment
comment|/* Requires stream.h */
end_comment

begin_comment
comment|/* File objects store a pointer to a stream in value.pfile. */
end_comment

begin_comment
comment|/* A file object is valid if its buffer size is non-zero. */
end_comment

begin_comment
comment|/* The value.pfile of an invalid file object points to an invalid stream. */
end_comment

begin_define
define|#
directive|define
name|fptr
parameter_list|(
name|pref
parameter_list|)
value|(pref)->value.pfile
end_define

begin_define
define|#
directive|define
name|make_file
parameter_list|(
name|pref
parameter_list|,
name|a
parameter_list|,
name|s
parameter_list|)
define|\
value|make_tav(pref,t_file,a,pfile,s)
end_define

begin_comment
comment|/* The standard files.  0 is %stdin, 1 is %stdout. */
end_comment

begin_decl_stmt
specifier|extern
name|stream
name|std_files
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An invalid file. */
end_comment

begin_decl_stmt
specifier|extern
name|stream
name|invalid_file_entry
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macros for checking file validity */
end_comment

begin_define
define|#
directive|define
name|check_file_access
parameter_list|(
name|svar
parameter_list|,
name|op
parameter_list|,
name|acc
parameter_list|)
define|\
value|{	svar = fptr(op);
comment|/* do first, acc may refer to it */
value|\ 	if ( !(acc) ) return e_invalidaccess;\    }
end_define

begin_define
define|#
directive|define
name|check_file_ref
parameter_list|(
name|svar
parameter_list|,
name|op
parameter_list|,
name|acc
parameter_list|)
define|\
value|{	if ( !r_has_type(op, t_file) ) return e_typecheck;\ 	check_file_access(svar,op,acc);\    }
end_define

begin_define
define|#
directive|define
name|check_file
parameter_list|(
name|svar
parameter_list|,
name|op
parameter_list|)
value|check_file_ref(svar,op,s_is_valid(svar))
end_define

begin_define
define|#
directive|define
name|check_read_file
parameter_list|(
name|svar
parameter_list|,
name|op
parameter_list|)
define|\
value|{	check_read_type(*(op), t_file);\ 	check_file_access(svar,op,s_is_reading(svar));\    }
end_define

begin_define
define|#
directive|define
name|check_write_file
parameter_list|(
name|svar
parameter_list|,
name|op
parameter_list|)
define|\
value|{	check_write_type(*(op), t_file);\ 	check_file_access(svar,op,s_is_writing(svar));\    }
end_define

end_unit

