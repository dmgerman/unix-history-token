begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD backend for sparc little-endian aout binaries.    Copyright 1996 Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-sparc-little"
end_define

begin_define
define|#
directive|define
name|MY
parameter_list|(
name|OP
parameter_list|)
value|CAT(sparcle_aout_,OP)
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"bfdlink.h"
end_include

begin_include
include|#
directive|include
file|"libaout.h"
end_include

begin_define
define|#
directive|define
name|MACHTYPE_OK
parameter_list|(
name|mtype
parameter_list|)
value|((mtype) == M_SPARC || (mtype) == M_SPARCLET)
end_define

begin_comment
comment|/* Include the usual a.out support.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_IS_LITTLE_ENDIAN_P
end_define

begin_include
include|#
directive|include
file|"aoutf1.h"
end_include

end_unit

