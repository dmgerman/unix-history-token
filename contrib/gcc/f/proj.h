begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* proj.h file for Gnu Fortran    Copyright (C) 1995, 1996, 2000, 2001 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_PROJ_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_PROJ_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_HCONFIG
end_ifdef

begin_include
include|#
directive|include
file|"hconfig.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_if
if|#
directive|if
operator|(
name|GCC_VERSION
operator|<
literal|2000
operator|)
end_if

begin_error
error|#
directive|error
literal|"You have to use gcc 2.x to build g77 (might be fixed in g77-0.6)."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include files everyone gets.<assert.h> is needed for assert().  */
end_comment

begin_include
include|#
directive|include
file|"assert.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|UNUSED
end_ifndef

begin_comment
comment|/* Compile with -DUNUSED= if cc doesn't support this. */
end_comment

begin_define
define|#
directive|define
name|UNUSED
value|ATTRIBUTE_UNUSED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (UNUSED) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|dmpout
end_ifndef

begin_define
define|#
directive|define
name|dmpout
value|stderr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_PROJ_H */
end_comment

end_unit

