begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for NetBSD/ARM a.out-ish binaries.    Copyright 1999, 2000, 2001, 2002, 2005    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
end_define

begin_undef
undef|#
directive|undef
name|TARGET_IS_BIG_ENDIAN_P
end_undef

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|TARGET_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_arm
end_define

begin_define
define|#
directive|define
name|DEFAULT_MID
value|M_ARM6_NETBSD
end_define

begin_comment
comment|/*#define MACHTYPE_OK(mtype) ((mtype) == M_ARM6_NETBSD)*/
end_comment

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
value|CONCAT2 (armnetbsd_, OP)
end_define

begin_comment
comment|/* This needs to start with a.out so GDB knows it is an a.out variant.  */
end_comment

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-arm-netbsd"
end_define

begin_include
include|#
directive|include
file|"netbsd.h"
end_include

end_unit

