begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for i386 a.out binaries under BSD.    Copyright 1990, 1991, 1992, 1993, 1994 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This data should be correct for the format used under all the various    BSD ports for 386 machines.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
end_define

begin_comment
comment|/* ZMAGIC files never have the header in the text.  */
end_comment

begin_define
define|#
directive|define
name|N_HEADER_IN_TEXT
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_comment
comment|/* ZMAGIC files start at address 0.  This does not apply to QMAGIC.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|0
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
value|bfd_arch_i386
end_define

begin_define
define|#
directive|define
name|MACHTYPE_OK
parameter_list|(
name|mtype
parameter_list|)
value|((mtype) == M_386 || (mtype) == M_UNKNOWN)
end_define

begin_define
define|#
directive|define
name|MY
parameter_list|(
name|OP
parameter_list|)
value|CAT(i386bsd_,OP)
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-i386-bsd"
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
file|"libaout.h"
end_include

begin_include
include|#
directive|include
file|"aout-target.h"
end_include

end_unit

