begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GCC for Sparc v9 running 64-bit native.    Copyright (C) 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<sparc/xm-sysv4.h>
end_include

begin_comment
comment|/* This describes the machine the compiler is hosted on.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__arch64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc_v9__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparcv9
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HOST_BITS_PER_LONG
end_undef

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONG
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

