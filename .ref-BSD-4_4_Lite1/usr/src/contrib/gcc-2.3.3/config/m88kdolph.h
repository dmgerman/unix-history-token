begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Motorola m88100 running the Dolphin UNIX System V/88 Release 3.2,    Version 3.5/5.60.    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"m88kv3.h"
end_include

begin_comment
comment|/* Don't output structure tag names when it causes a forward reference.    Symptom:    Error messages like    as: "/usr/tmp/cca22733.s": cannot reduce symbol table, unused symbols remain    when compiling some programs.    example program (C++): struct bad { bad(); }; bad::bad() {}     This problem seems to have gone away, perhaps with release 3.6 of the O/S    from Dolphin.  */
end_comment

begin_comment
comment|/* #undef SDB_ALLOW_FORWARD_REFERENCES */
end_comment

begin_comment
comment|/* Use T_ARG as T_VOID.  T_VOID is not defined in<syms.h> as it should be.  */
end_comment

begin_define
define|#
directive|define
name|T_VOID
value|T_ARG
end_define

end_unit

