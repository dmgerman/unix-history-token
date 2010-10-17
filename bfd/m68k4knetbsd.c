begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for NetBSD/m68k a.out-ish binaries.    Copyright 1990, 1991, 1992, 1995, 1998, 2001, 2003    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_IS_BIG_ENDIAN_P
end_define

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_m68k
end_define

begin_define
define|#
directive|define
name|DEFAULT_MID
value|M_68K4K_NETBSD
end_define

begin_comment
comment|/* Do not "beautify" the CONCAT* macro args.  Traditional C will not    remove whitespace added here, and thus will fail to concatenate    the tokens.  */
end_comment

begin_define
define|#
directive|define
name|MY
parameter_list|(
name|OP
parameter_list|)
value|CONCAT2 (m68k4knetbsd_,OP)
end_define

begin_comment
comment|/* This needs to start with a.out so GDB knows it is an a.out variant.  */
end_comment

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-m68k4k-netbsd"
end_define

begin_include
include|#
directive|include
file|"netbsd.h"
end_include

end_unit

