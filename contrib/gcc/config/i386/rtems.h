begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for rtems targeting an Intel i386 using coff.    Copyright (C) 1996, 1997, 2000 Free Software Foundation, Inc.    Contributed by Joel Sherrill (joel@OARcorp.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/i386-coff.h"
end_include

begin_comment
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Drtems -D__rtems__ -Asystem=rtems"
end_define

begin_comment
comment|/* Generate calls to memcpy, memcmp and memset.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_MEM_FUNCTIONS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Get machine-independent configuration parameters for RTEMS.  */
end_comment

begin_include
include|#
directive|include
file|<rtems.h>
end_include

begin_comment
comment|/* end of i386/rtems.h */
end_comment

end_unit

