begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration fragment for hosts running a version of OpenBSD.    Copyright (C) 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file gets included by all architectures. It holds stuff    that ought to be defined when hosting a compiler on an OpenBSD    machine, independently of the architecture. It's included by    ${cpu_type}/xm-openbsd.h, not included directly.  */
end_comment

begin_comment
comment|/* OpenBSD is trying to be POSIX-compliant, to the point of fixing    problems that may occur with gcc's interpretation.  */
end_comment

begin_undef
undef|#
directive|undef
name|POSIX
end_undef

begin_define
define|#
directive|define
name|POSIX
end_define

begin_comment
comment|/* Ensure we get gnu C's defaults.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

