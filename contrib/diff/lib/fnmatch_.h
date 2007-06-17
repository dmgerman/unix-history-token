begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992, 1993, 1996, 1997, 1998, 1999, 2001, 2002, 2003    Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* We #undef these before defining them because some losing systems    (HP-UX A.08.07 for example) define these in<unistd.h>.  */
undef|#
directive|undef
name|FNM_PATHNAME
undef|#
directive|undef
name|FNM_NOESCAPE
undef|#
directive|undef
name|FNM_PERIOD
comment|/* Bits set in the FLAGS argument to `fnmatch'.  */
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
if|#
directive|if
operator|!
name|defined
name|_POSIX_C_SOURCE
operator|||
name|_POSIX_C_SOURCE
operator|<
literal|2
operator|||
name|defined
name|_GNU_SOURCE
define|#
directive|define
name|FNM_FILE_NAME
value|FNM_PATHNAME
comment|/* Preferred GNU name.  */
define|#
directive|define
name|FNM_LEADING_DIR
value|(1<< 3)
comment|/* Ignore `/...' after a match.  */
define|#
directive|define
name|FNM_CASEFOLD
value|(1<< 4)
comment|/* Compare without regard to case.  */
define|#
directive|define
name|FNM_EXTMATCH
value|(1<< 5)
comment|/* Use ksh-like extended matching. */
endif|#
directive|endif
comment|/* Value returned by `fnmatch' if STRING does not match PATTERN.  */
define|#
directive|define
name|FNM_NOMATCH
value|1
comment|/* This value is returned if the implementation does not support    `fnmatch'.  Since this is not the case here it will never be    returned but the conformance test suites still require the symbol    to be defined.  */
ifdef|#
directive|ifdef
name|_XOPEN_SOURCE
define|#
directive|define
name|FNM_NOSYS
value|(-1)
endif|#
directive|endif
comment|/* Match NAME against the filename pattern PATTERN,    returning zero if it matches, FNM_NOMATCH if not.  */
specifier|extern
name|int
name|fnmatch
parameter_list|(
specifier|const
name|char
modifier|*
name|__pattern
parameter_list|,
specifier|const
name|char
modifier|*
name|__name
parameter_list|,
name|int
name|__flags
parameter_list|)
function_decl|;
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

