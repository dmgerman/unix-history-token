begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for Motorola 68000 COFF binaries having underscore with name.    Copyright 1990, 1991, 1992 Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SYM
value|m68kcoffun_vec
end_define

begin_define
define|#
directive|define
name|TARGET_NAME
value|"coff-m68k-un"
end_define

begin_define
define|#
directive|define
name|NAMES_HAVE_UNDERSCORE
end_define

begin_comment
comment|/* define this to not have multiple copy of m68k_rtype2howto    in the executable file */
end_comment

begin_define
define|#
directive|define
name|ONLY_DECLARE_RELOCS
end_define

begin_comment
comment|/* This magic number indicates that the names have underscores.    Other 68k magic numbers indicate that the names do not have    underscores.  */
end_comment

begin_define
define|#
directive|define
name|BADMAG
parameter_list|(
name|x
parameter_list|)
value|((x).f_magic != MC68KBCSMAGIC)
end_define

begin_include
include|#
directive|include
file|"coff-m68k.c"
end_include

end_unit

