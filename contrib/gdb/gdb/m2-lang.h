begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Modula 2 language support definitions for GDB, the GNU debugger.    Copyright 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|m2_parse
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Defined in m2-exp.y */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|m2_error
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Defined in m2-exp.y */
end_comment

begin_decl_stmt
specifier|extern
name|void
comment|/* Defined in m2-typeprint.c */
name|m2_print_type
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
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|m2_val_print
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
name|int
operator|,
name|CORE_ADDR
operator|,
name|GDB_FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|val_prettyprint
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

