begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for hosting on Windows NT.    using a unix style C library.    Copyright (C) 1995, 1996, 1997, 1998, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_define
define|#
directive|define
name|EXECUTABLE_SUFFIX
value|".exe"
end_define

begin_define
define|#
directive|define
name|NO_SYS_SIGLIST
value|1
end_define

begin_comment
comment|/* We support both "/" and "\" since everybody tests both but we    default to "/".  This is important because if gcc produces Win32    paths containing backslashes, make and configure may treat the    backslashes as escape characters.  Many Win32 programs use forward    slashes so using a forward slash shouldn't be problematic from the    perspective of wanting gcc to produce native Win32 paths. */
end_comment

begin_define
define|#
directive|define
name|DIR_SEPARATOR
value|'/'
end_define

begin_define
define|#
directive|define
name|DIR_SEPARATOR_2
value|'\\'
end_define

begin_comment
comment|/* Convert win32 style path lists to POSIX style for consistency. */
end_comment

begin_undef
undef|#
directive|undef
name|GET_ENV_PATH_LIST
end_undef

begin_define
define|#
directive|define
name|GET_ENV_PATH_LIST
parameter_list|(
name|VAR
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\   char *_epath;								\   char *_posixepath;							\   _epath = _posixepath = getenv (NAME);					\
comment|/* if we have a posix path list, convert to posix path list */
value|\   if (_epath != NULL&& *_epath != 0					\&& ! cygwin_posix_path_list_p (_epath))				\     {									\       char *p;								\       _posixepath = (char *) xmalloc					\ 	(cygwin_win32_to_posix_path_list_buf_size (_epath));		\       cygwin_win32_to_posix_path_list (_epath, _posixepath);		\     }									\   (VAR) = _posixepath;							\ } while (0)
end_define

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|':'
end_define

begin_comment
comment|/* This is needed so that protoize will compile.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|POSIX
end_ifndef

begin_define
define|#
directive|define
name|POSIX
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

