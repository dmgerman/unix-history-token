begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for OpenBSD/m88k a.out binaries.    Copyright 2004 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
value|4096
end_define

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_m88k
end_define

begin_define
define|#
directive|define
name|DEFAULT_MID
value|M_88K_OPENBSD
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
value|CONCAT2 (m88kopenbsd_,OP)
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-m88k-openbsd"
end_define

begin_include
include|#
directive|include
file|"netbsd.h"
end_include

end_unit

