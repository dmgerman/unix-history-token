begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* proj.h file for Gnu Fortran    Copyright (C) 1995, 1996 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_H_f_proj
end_ifndef

begin_define
define|#
directive|define
name|_H_f_proj
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_HCONFIG
end_ifdef

begin_include
include|#
directive|include
file|"hconfig.j"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"config.j"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"system.j"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
operator|(
name|__GNUC__
operator|<
literal|2
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

begin_ifndef
ifndef|#
directive|ifndef
name|BUILT_WITH_270
end_ifndef

begin_if
if|#
directive|if
operator|(
name|__GNUC__
operator|>
literal|2
operator|)
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|7
operator|)
end_if

begin_define
define|#
directive|define
name|BUILT_WITH_270
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUILT_WITH_270
value|0
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
comment|/* !defined (BUILT_WITH_270) */
end_comment

begin_comment
comment|/* Include files everyone gets.<assert.h> is needed for assert().<stddef.h> is needed for offsetof, but technically also NULL,    size_t, ptrdiff_t, and so on.  */
end_comment

begin_include
include|#
directive|include
file|"assert.j"
end_include

begin_if
if|#
directive|if
name|HAVE_STDDEF_H
end_if

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Generally useful definitions. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|false
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|true
argument_list|)
name|false
init|=
literal|0
block|,
name|true
init|=
literal|1
block|,
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FALSE
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|TRUE
argument_list|)
name|FALSE
init|=
literal|0
block|,
name|TRUE
init|=
literal|1
block|,
endif|#
directive|endif
name|Doggone_Trailing_Comma_Dont_Work
init|=
literal|1
block|}
name|bool
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a)/sizeof(a[0]))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|UNUSED
end_ifndef

begin_comment
comment|/* Compile with -DUNUSED= if cc doesn't support this. */
end_comment

begin_if
if|#
directive|if
name|BUILT_WITH_270
end_if

begin_define
define|#
directive|define
name|UNUSED
value|__attribute__ ((unused))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !BUILT_WITH_270 */
end_comment

begin_define
define|#
directive|define
name|UNUSED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !BUILT_WITH_270 */
end_comment

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

end_unit

