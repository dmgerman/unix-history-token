begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Free Software Foundation, Inc.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with this library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FNMATCH_H
end_ifndef

begin_define
define|#
directive|define
name|_FNMATCH_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__FreeBSD__
include|#
directive|include
file|<sys/cdefs.h>
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|__STDC__
operator|)
undef|#
directive|undef
name|__P
define|#
directive|define
name|__P
parameter_list|(
name|args
parameter_list|)
value|args
else|#
directive|else
comment|/* Not C++ or ANSI C.  */
undef|#
directive|undef
name|__P
define|#
directive|define
name|__P
parameter_list|(
name|args
parameter_list|)
value|()
undef|#
directive|undef
name|const
define|#
directive|define
name|const
endif|#
directive|endif
comment|/* C++ or ANSI C.  */
endif|#
directive|endif
comment|/* Bits set in the FLAGS argument to `fnmatch'.  */
ifdef|#
directive|ifdef
name|FNM_PATHNAME
comment|/* Because it is already defined in<unistd.h> */
undef|#
directive|undef
name|FNM_PATHNAME
endif|#
directive|endif
define|#
directive|define
name|FNM_PATHNAME
value|(1<< 0)
comment|/* No wildcard can ever match `/'.  */
define|#
directive|define
name|FNM_NOESCAPE
value|(1<< 1)
comment|/* Backslashes don't quote special chars.  */
define|#
directive|define
name|FNM_PERIOD
value|(1<< 2)
comment|/* Leading `.' is matched only explicitly.  */
define|#
directive|define
name|__FNM_FLAGS
value|(FNM_PATHNAME|FNM_NOESCAPE|FNM_PERIOD|FNM_LEADING_DIR)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
operator|||
name|_POSIX_C_SOURCE
operator|<
literal|2
operator|||
name|defined
argument_list|(
name|_BSD_SOURCE
argument_list|)
define|#
directive|define
name|FNM_LEADING_DIR
value|(1<< 3)
comment|/* Ignore `/...' after a match.  */
define|#
directive|define
name|FNM_FILE_NAME
value|FNM_PATHNAME
endif|#
directive|endif
comment|/* Value returned by `fnmatch' if STRING does not match PATTERN.  */
define|#
directive|define
name|FNM_NOMATCH
value|1
comment|/* Match STRING against the filename pattern PATTERN,    returning zero if it matches, FNM_NOMATCH if not.  */
specifier|extern
name|int
name|fnmatch
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|__pattern
operator|,
specifier|const
name|char
operator|*
name|__string
operator|,
name|int
name|__flags
operator|)
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* fnmatch.h */
end_comment

end_unit

