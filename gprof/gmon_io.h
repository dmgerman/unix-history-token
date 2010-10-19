begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gmon_io.h     Copyright 2000, 2001, 2002, 2004 Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|gmon_io_h
end_ifndef

begin_define
define|#
directive|define
name|gmon_io_h
end_define

begin_comment
comment|/* Some platforms need to put stdin into binary mode, to read    binary files.  */
end_comment

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SETMODE
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|O_BINARY
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_O_BINARY
end_ifdef

begin_define
define|#
directive|define
name|O_BINARY
value|_O_BINARY
end_define

begin_define
define|#
directive|define
name|setmode
value|_setmode
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|O_BINARY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|O_BINARY
end_if

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_define
define|#
directive|define
name|SET_BINARY
parameter_list|(
name|f
parameter_list|)
value|do { if (!isatty(f)) setmode(f,O_BINARY); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INPUT_HISTOGRAM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|INPUT_CALL_GRAPH
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|INPUT_BB_COUNTS
value|(1<< 2)
end_define

begin_decl_stmt
specifier|extern
name|int
name|gmon_input
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* What input did we see?  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gmon_file_version
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File version are we dealing with.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|gmon_io_read_vma
parameter_list|(
name|FILE
modifier|*
name|ifp
parameter_list|,
name|bfd_vma
modifier|*
name|valp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gmon_io_read_32
parameter_list|(
name|FILE
modifier|*
name|ifp
parameter_list|,
name|unsigned
name|int
modifier|*
name|valp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gmon_io_read
parameter_list|(
name|FILE
modifier|*
name|ifp
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gmon_io_write_vma
parameter_list|(
name|FILE
modifier|*
name|ifp
parameter_list|,
name|bfd_vma
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gmon_io_write_32
parameter_list|(
name|FILE
modifier|*
name|ifp
parameter_list|,
name|unsigned
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gmon_io_write_8
parameter_list|(
name|FILE
modifier|*
name|ifp
parameter_list|,
name|unsigned
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gmon_io_write
parameter_list|(
name|FILE
modifier|*
name|ifp
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gmon_out_read
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gmon_out_write
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gmon_io_h */
end_comment

end_unit

