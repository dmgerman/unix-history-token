begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992 Free Software Foundation, Inc. This file is part of the GNU C Library.  The GNU C Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU C Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  */
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

begin_comment
comment|/* Bits set in the FLAGS argument to `fnmatch'.  */
end_comment

begin_undef
undef|#
directive|undef
name|FNM_PATHNAME
end_undef

begin_define
define|#
directive|define
name|FNM_PATHNAME
value|(1<< 0)
end_define

begin_comment
comment|/* No wildcard can ever match `/'.  */
end_comment

begin_undef
undef|#
directive|undef
name|FNM_NOESCAPE
end_undef

begin_define
define|#
directive|define
name|FNM_NOESCAPE
value|(1<< 1)
end_define

begin_comment
comment|/* Backslashes don't quote special chars.  */
end_comment

begin_undef
undef|#
directive|undef
name|FNM_PERIOD
end_undef

begin_define
define|#
directive|define
name|FNM_PERIOD
value|(1<< 2)
end_define

begin_comment
comment|/* Leading `.' is matched only explicitly.  */
end_comment

begin_undef
undef|#
directive|undef
name|__FNM_FLAGS
end_undef

begin_define
define|#
directive|define
name|__FNM_FLAGS
value|(FNM_PATHNAME|FNM_NOESCAPE|FNM_PERIOD)
end_define

begin_comment
comment|/* Value returned by `fnmatch' if STRING does not match PATTERN.  */
end_comment

begin_undef
undef|#
directive|undef
name|FNM_NOMATCH
end_undef

begin_define
define|#
directive|define
name|FNM_NOMATCH
value|1
end_define

begin_comment
comment|/* Match STRING against the filename pattern PATTERN,    returning zero if it matches, FNM_NOMATCH if not.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_function_decl
specifier|extern
name|int
name|fnmatch
parameter_list|(
specifier|const
name|char
modifier|*
name|pattern
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|int
name|fnmatch
parameter_list|()
function_decl|;
end_function_decl

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

