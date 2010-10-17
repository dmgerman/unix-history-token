begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for NewsOS3 (Sony, 68k) binaries.    Copyright 1990, 1991, 1994, 1995, 2000, 2001, 2003    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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
name|TEXT_START_ADDR
value|0
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
value|CONCAT2 (newsos3_,OP)
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-newsos3"
end_define

begin_define
define|#
directive|define
name|ENTRY_CAN_BE_ZERO
end_define

begin_define
define|#
directive|define
name|N_SHARED_LIB
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_comment
comment|/* Avoids warning when compiled with -Wall.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_m68k
end_define

begin_define
define|#
directive|define
name|TARGET_IS_BIG_ENDIAN_P
end_define

begin_define
define|#
directive|define
name|N_HEADER_IN_TEXT
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"libbfd.h"
end_include

begin_include
include|#
directive|include
file|"aout/aout64.h"
end_include

begin_include
include|#
directive|include
file|"aout/stab_gnu.h"
end_include

begin_include
include|#
directive|include
file|"aout/ar.h"
end_include

begin_include
include|#
directive|include
file|"libaout.h"
end_include

begin_comment
comment|/* BFD a.out internal data structures */
end_comment

begin_include
include|#
directive|include
file|"aout-target.h"
end_include

end_unit

