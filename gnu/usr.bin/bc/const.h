begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* const.h: Constants for bc. */
end_comment

begin_comment
comment|/*  This file is part of bc written for MINIX.     Copyright (C) 1991, 1992, 1993, 1994 Free Software Foundation, Inc.      This program is free software; you can redistribute it and/or modify     it under the terms of the GNU General Public License as published by     the Free Software Foundation; either version 2 of the License , or     (at your option) any later version.      This program is distributed in the hope that it will be useful,     but WITHOUT ANY WARRANTY; without even the implied warranty of     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     GNU General Public License for more details.      You should have received a copy of the GNU General Public License     along with this program; see the file COPYING.  If not, write to     the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.      You may contact the author by:        e-mail:  phil@cs.wwu.edu       us-mail:  Philip A. Nelson                 Computer Science Department, 9062                 Western Washington University                 Bellingham, WA 98226-9062  *************************************************************************/
end_comment

begin_comment
comment|/* Define INT_MAX and LONG_MAX if not defined.  Assuming 32 bits... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_LIMITS
end_ifdef

begin_define
define|#
directive|define
name|INT_MAX
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|LONG_MAX
value|0x7FFFFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define constants in some reasonable size.  The next 4 constants are    POSIX constants. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|BC_BASE_MAX
value|INT_MAX
end_define

begin_define
define|#
directive|define
name|BC_SCALE_MAX
value|INT_MAX
end_define

begin_define
define|#
directive|define
name|BC_STRING_MAX
value|INT_MAX
end_define

begin_comment
comment|/* Definitions for arrays. */
end_comment

begin_define
define|#
directive|define
name|BC_DIM_MAX
value|65535
end_define

begin_comment
comment|/* this should be NODE_SIZE^NODE_DEPTH-1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NODE_SIZE
value|16
end_define

begin_comment
comment|/* Must be a power of 2. */
end_comment

begin_define
define|#
directive|define
name|NODE_MASK
value|0xf
end_define

begin_comment
comment|/* Must be NODE_SIZE-1. */
end_comment

begin_define
define|#
directive|define
name|NODE_SHIFT
value|4
end_define

begin_comment
comment|/* Number of 1 bits in NODE_MASK. */
end_comment

begin_define
define|#
directive|define
name|NODE_DEPTH
value|4
end_define

begin_comment
comment|/* Other BC limits defined but not part of POSIX. */
end_comment

begin_define
define|#
directive|define
name|BC_LABEL_GROUP
value|64
end_define

begin_define
define|#
directive|define
name|BC_LABEL_LOG
value|6
end_define

begin_define
define|#
directive|define
name|BC_MAX_SEGS
value|16
end_define

begin_comment
comment|/* Code segments. */
end_comment

begin_define
define|#
directive|define
name|BC_SEG_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|BC_SEG_LOG
value|10
end_define

begin_comment
comment|/* Maximum number of variables, arrays and functions and the    allocation increment for the dynamic arrays. */
end_comment

begin_define
define|#
directive|define
name|MAX_STORE
value|32767
end_define

begin_define
define|#
directive|define
name|STORE_INCR
value|32
end_define

begin_comment
comment|/* Other interesting constants. */
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/* for use with lookup (). */
end_comment

begin_define
define|#
directive|define
name|SIMPLE
value|0
end_define

begin_define
define|#
directive|define
name|ARRAY
value|1
end_define

begin_define
define|#
directive|define
name|FUNCT
value|2
end_define

begin_define
define|#
directive|define
name|FUNCTDEF
value|3
end_define

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|CONST
value|const
end_define

begin_define
define|#
directive|define
name|VOID
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CONST
end_define

begin_define
define|#
directive|define
name|VOID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include the version definition. */
end_comment

begin_include
include|#
directive|include
file|"version.h"
end_include

end_unit

