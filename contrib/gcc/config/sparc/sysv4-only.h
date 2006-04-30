begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target macros for GCC for SPARC running System V.4    Copyright (C) 2003    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Provide a set of pre-definitions and pre-assertions appropriate for    the SPARC running svr4.  __svr4__ is our extension.  */
end_comment

begin_comment
comment|/* Target OS builtins.  */
end_comment

begin_expr_stmt
unit|\
operator|#
name|define
name|TARGET_OS_CPP_BUILTINS
argument_list|()
end_expr_stmt

begin_do
unit|\
do|do						\
block|{						\
name|builtin_define_std
argument_list|(
literal|"sparc"
argument_list|)
expr_stmt|;
block|\
name|builtin_define_std
argument_list|(
literal|"unix"
argument_list|)
expr_stmt|;
block|\
name|builtin_define
argument_list|(
literal|"__svr4__"
argument_list|)
expr_stmt|;
block|\
name|builtin_assert
argument_list|(
literal|"system=unix"
argument_list|)
expr_stmt|;
block|\
name|builtin_assert
argument_list|(
literal|"system=svr4"
argument_list|)
expr_stmt|;
block|\     }
do|\   while
condition|(
literal|0
condition|)
end_do

end_unit

