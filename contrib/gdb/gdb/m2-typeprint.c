begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Support for printing Modula 2 types for GDB, the GNU debugger.    Copyright 1986, 1988, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_comment
comment|/* Binary File Description */
end_comment

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
file|"expression.h"
end_include

begin_include
include|#
directive|include
file|"value.h"
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
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
file|"language.h"
end_include

begin_include
include|#
directive|include
file|"demangle.h"
end_include

begin_include
include|#
directive|include
file|"m2-lang.h"
end_include

begin_include
include|#
directive|include
file|"gdb_string.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_function
name|void
name|m2_print_type
parameter_list|(
name|type
parameter_list|,
name|varstring
parameter_list|,
name|stream
parameter_list|,
name|show
parameter_list|,
name|level
parameter_list|)
name|struct
name|type
modifier|*
name|type
decl_stmt|;
name|char
modifier|*
name|varstring
decl_stmt|;
name|GDB_FILE
modifier|*
name|stream
decl_stmt|;
name|int
name|show
decl_stmt|;
name|int
name|level
decl_stmt|;
block|{
specifier|extern
name|void
name|c_print_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|char
operator|*
operator|,
name|GDB_FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
name|c_print_type
argument_list|(
name|type
argument_list|,
name|varstring
argument_list|,
name|stream
argument_list|,
name|show
argument_list|,
name|level
argument_list|)
expr_stmt|;
comment|/* FIXME */
block|}
end_function

end_unit

