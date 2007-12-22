begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dbxout.h - Various declarations for functions found in dbxout.c    Copyright (C) 1998, 1999, 2000, 2003, 2004    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_DBXOUT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_DBXOUT_H
end_define

begin_function_decl
specifier|extern
name|int
name|dbxout_symbol
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dbxout_parms
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dbxout_reg_parms
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dbxout_syms
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Language description for N_SO stabs.  */
end_comment

begin_define
define|#
directive|define
name|N_SO_AS
value|1
end_define

begin_define
define|#
directive|define
name|N_SO_C
value|2
end_define

begin_define
define|#
directive|define
name|N_SO_ANSI_C
value|3
end_define

begin_define
define|#
directive|define
name|N_SO_CC
value|4
end_define

begin_comment
comment|/* c++*/
end_comment

begin_define
define|#
directive|define
name|N_SO_FORTRAN
value|5
end_define

begin_define
define|#
directive|define
name|N_SO_PASCAL
value|6
end_define

begin_define
define|#
directive|define
name|N_SO_FORTRAN90
value|7
end_define

begin_define
define|#
directive|define
name|N_SO_OBJC
value|50
end_define

begin_define
define|#
directive|define
name|N_SO_OBJCPLUS
value|51
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_DBXOUT_H */
end_comment

end_unit

