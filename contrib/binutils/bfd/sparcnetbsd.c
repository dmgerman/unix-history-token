begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for NetBSD/sparc a.out-ish binaries.    Copyright 1990, 1991, 1992, 1994, 1995, 1997, 1998, 2000    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
end_define

begin_define
define|#
directive|define
name|TARGET_IS_BIG_ENDIAN_P
end_define

begin_comment
comment|/* SPARC chips use either 4K or 8K pages, but object files always    assume 8K page alignment so they will work on either one.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|0x2000
end_define

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_sparc
end_define

begin_define
define|#
directive|define
name|DEFAULT_MID
value|M_SPARC_NETBSD
end_define

begin_define
define|#
directive|define
name|MY
parameter_list|(
name|OP
parameter_list|)
value|CAT(sparcnetbsd_,OP)
end_define

begin_comment
comment|/* This needs to start with a.out so GDB knows it is an a.out variant.  */
end_comment

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-sparc-netbsd"
end_define

begin_include
include|#
directive|include
file|"netbsd.h"
end_include

end_unit

