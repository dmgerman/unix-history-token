begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD backend for SunOS style a.out with flags set to 0    Copyright 1990, 1991, 1992, 1993, 1994, 1995    Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-zero-big"
end_define

begin_define
define|#
directive|define
name|MY
parameter_list|(
name|OP
parameter_list|)
value|CAT(aout0_big_,OP)
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_define
define|#
directive|define
name|MY_exec_hdr_flags
value|0
end_define

begin_define
define|#
directive|define
name|MACHTYPE_OK
parameter_list|(
name|mtype
parameter_list|)
define|\
value|((mtype) == M_UNKNOWN || (mtype) == M_68010 || (mtype) == M_68020)
end_define

begin_comment
comment|/* Include the usual a.out support.  */
end_comment

begin_include
include|#
directive|include
file|"aoutf1.h"
end_include

end_unit

