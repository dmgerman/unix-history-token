begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for "naked" Intel 386 using a.out (or coff encap'd    a.out) object format and stabs debugging info.     Copyright (C) 1994, 2002 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (80386, BSD a.out syntax)");
end_define

begin_comment
comment|/* end of i386-aout.h */
end_comment

end_unit

