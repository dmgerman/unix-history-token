begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  ARM RISCiX(stabs) version.    Copyright (C) 1993 Free Software Foundation, Inc.    Contributed by Richard Earnshaw (rwe11@cl.cam.ac.uk), based on original 	      work by Pieter `Tiggr' Schoenmakers (rcpieter@win.tue.nl)    	      and Martin Simmons (@harleqn.co.uk).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Limit the length of a stabs entry (for the broken Acorn assembler) */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_CONTIN_LENGTH
end_undef

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|80
end_define

begin_comment
comment|/* The native RISCiX assembler does not support stabs of any kind; because    the native assembler is not used by the compiler, Acorn didn't feel it was    necessary to put them in!      However, this file assumes that we have an assembler that does have stabs,    so we put them back in.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Unfortunately dbx doesn't understand these */
end_comment

begin_comment
comment|/* Dbx on RISCiX is so broken that I've given up trying to support it.    lets just support gdb. */
end_comment

begin_comment
comment|/* #define DEFAULT_GDB_EXTENSIONS 0 */
end_comment

begin_comment
comment|/* RISCiX dbx doesn't accept xrefs */
end_comment

begin_comment
comment|/* #define DBX_NO_XREFS 1 */
end_comment

end_unit

