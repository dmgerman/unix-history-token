begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* S-record download support for GDB, the GNU debugger.    Copyright 1995, 1996, 2000 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_struct_decl
struct_decl|struct
name|serial
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|load_srec
parameter_list|(
name|struct
name|serial
modifier|*
name|desc
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|bfd_vma
name|load_offset
parameter_list|,
name|int
name|maxrecsize
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|hashmark
parameter_list|,
name|int
function_decl|(
modifier|*
name|waitack
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* S-record capability flags */
end_comment

begin_comment
comment|/* Which record types are supported */
end_comment

begin_define
define|#
directive|define
name|SREC_2_BYTE_ADDR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|SREC_3_BYTE_ADDR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SREC_4_BYTE_ADDR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SREC_TERM_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|SREC_ALL
value|(SREC_2_BYTE_ADDR | SREC_3_BYTE_ADDR | SREC_4_BYTE_ADDR \ 		  | ((SREC_2_BYTE_ADDR | SREC_3_BYTE_ADDR | SREC_4_BYTE_ADDR) \<< SREC_TERM_SHIFT))
end_define

begin_define
define|#
directive|define
name|SREC_BINARY
value|0x00000040
end_define

begin_comment
comment|/* Supports binary form of S-records */
end_comment

end_unit

