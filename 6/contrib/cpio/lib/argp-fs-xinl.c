begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Real definitions for extern inline functions in argp-fmtstream.h    Copyright (C) 1997, 2003, 2004 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Written by Miles Bader<miles@gnu.ai.mit.edu>.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_define
define|#
directive|define
name|ARGP_FS_EI
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
file|"argp-fmtstream.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Not exported.  */
end_comment

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
operator|!
name|defined
argument_list|(
name|ARGP_FMTSTREAM_USE_LINEWRAP
argument_list|)
operator|&&
name|defined
argument_list|(
name|weak_alias
argument_list|)
end_if

begin_endif
unit|weak_alias (__argp_fmtstream_putc, argp_fmtstream_putc) weak_alias (__argp_fmtstream_puts, argp_fmtstream_puts) weak_alias (__argp_fmtstream_write, argp_fmtstream_write) weak_alias (__argp_fmtstream_set_lmargin, argp_fmtstream_set_lmargin) weak_alias (__argp_fmtstream_set_rmargin, argp_fmtstream_set_rmargin) weak_alias (__argp_fmtstream_set_wmargin, argp_fmtstream_set_wmargin) weak_alias (__argp_fmtstream_point, argp_fmtstream_point)
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

