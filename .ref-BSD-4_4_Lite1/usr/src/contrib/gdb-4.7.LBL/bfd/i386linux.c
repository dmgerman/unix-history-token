begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for linux flavored i386 a.out binaries.    Copyright (C) 1990, 1991 Free Software Foundation, Inc. This file is part of BFD, the Binary File Descriptor library. This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* The reason for the text segment offset is to align things suitably    for demand paging.  However, for unknown reason Linux's text segment    is offset by 1024, while the true page size is 4096.  The former    is the one we care about here. */
end_comment

begin_define
define|#
directive|define
name|PAGE_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|0x0
end_define

begin_define
define|#
directive|define
name|ARCH
value|32
end_define

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
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

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_i386
end_define

begin_define
define|#
directive|define
name|MY
parameter_list|(
name|OP
parameter_list|)
value|CAT(i386linux_,OP)
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-i386(linux)"
end_define

begin_include
include|#
directive|include
file|"aout-target.h"
end_include

end_unit

