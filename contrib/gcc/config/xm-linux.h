begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GCC for Intel i386 running Linux.    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by H.J. Lu (hjl@nynexst.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VPRINTF
end_define

begin_define
define|#
directive|define
name|HAVE_STRERROR
end_define

begin_define
define|#
directive|define
name|POSIX
end_define

begin_define
define|#
directive|define
name|DONT_DECLARE_SYS_SIGLIST
end_define

begin_comment
comment|/* We do have one, but I'd like to use the one come with gcc since    we have been doing that for a long time with USG defined.  H.J. */
end_comment

begin_define
define|#
directive|define
name|NO_STAB_H
end_define

begin_undef
undef|#
directive|undef
name|BSTRING
end_undef

begin_define
define|#
directive|define
name|BSTRING
end_define

begin_undef
undef|#
directive|undef
name|bcmp
end_undef

begin_undef
undef|#
directive|undef
name|bcopy
end_undef

begin_undef
undef|#
directive|undef
name|bzero
end_undef

begin_undef
undef|#
directive|undef
name|index
end_undef

begin_undef
undef|#
directive|undef
name|rindex
end_undef

end_unit

