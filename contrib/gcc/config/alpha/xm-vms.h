begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for openVMS/Alpha.    Copyright (C) 1996, 1997, 2001 Free Software Foundation, Inc.    Contributed by Klaus Kaempf (kkaempf@progis.de).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|long long
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDE_INT
value|64
end_define

begin_comment
comment|/* A couple of conditionals for execution machine are controlled here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VMS
end_ifndef

begin_define
define|#
directive|define
name|VMS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define a local equivalent (sort of) for unlink */
end_comment

begin_define
define|#
directive|define
name|unlink
value|remove
end_define

begin_comment
comment|/* Causes exit() to be redefined to __posix_exit() and    Posix compatible failure and success codes to be used */
end_comment

begin_define
define|#
directive|define
name|_POSIX_EXIT
value|1
end_define

begin_comment
comment|/* Open files in stream mode if not otherwise explicitly specified */
end_comment

begin_define
define|#
directive|define
name|__UNIX_FOPEN
value|1
end_define

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_define
define|#
directive|define
name|HOST_EXECUTABLE_SUFFIX
value|".exe"
end_define

begin_define
define|#
directive|define
name|HOST_OBJECT_SUFFIX
value|".obj"
end_define

begin_define
define|#
directive|define
name|DUMPFILE_FORMAT
value|"_%02d_"
end_define

end_unit

