begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Real definitions for extern inline functions in argp.h    Copyright (C) 1997, 1998, 2004 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Written by Miles Bader<miles@gnu.ai.mit.edu>.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|_LIBC
operator|||
name|defined
name|HAVE_FEATURES_H
end_if

begin_include
include|#
directive|include
file|<features.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__USE_EXTERN_INLINES
end_ifndef

begin_define
define|#
directive|define
name|__USE_EXTERN_INLINES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ARGP_EI
end_define

begin_undef
undef|#
directive|undef
name|__OPTIMIZE__
end_undef

begin_define
define|#
directive|define
name|__OPTIMIZE__
value|1
end_define

begin_include
include|#
directive|include
file|"argp.h"
end_include

begin_comment
comment|/* Add weak aliases.  */
end_comment

begin_if
if|#
directive|if
name|_LIBC
operator|-
literal|0
operator|&&
name|defined
argument_list|(
name|weak_alias
argument_list|)
end_if

begin_macro
name|weak_alias
argument_list|(
argument|__argp_usage
argument_list|,
argument|argp_usage
argument_list|)
end_macro

begin_macro
name|weak_alias
argument_list|(
argument|__option_is_short
argument_list|,
argument|_option_is_short
argument_list|)
end_macro

begin_macro
name|weak_alias
argument_list|(
argument|__option_is_end
argument_list|,
argument|_option_is_end
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

