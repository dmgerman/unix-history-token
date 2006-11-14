begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for communicating with a remote tape drive.     Copyright (C) 1988, 1992, 1996, 1997, 2001, 2003, 2004 Free    Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rmt_command
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rmt_dev_name__
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|rmt_open__
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rmt_close__
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|rmt_read__
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|rmt_write__
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|rmt_lseek__
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rmt_ioctl__
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bool
name|force_local_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A filename is remote if it contains a colon not preceded by a slash,    to take care of `/:/' which is a shorthand for `/.../<CELL-NAME>/fs'    on machines running OSF's Distributing Computing Environment (DCE) and    Distributed File System (DFS).  However, when --force-local, a    filename is never remote.  */
end_comment

begin_define
define|#
directive|define
name|_remdev
parameter_list|(
name|dev_name
parameter_list|)
define|\
value|(!force_local_option&& (rmt_dev_name__ = strchr (dev_name, ':')) \&& rmt_dev_name__> (dev_name) \&& ! memchr (dev_name, '/', rmt_dev_name__ - (dev_name)))
end_define

begin_define
define|#
directive|define
name|_isrmt
parameter_list|(
name|fd
parameter_list|)
define|\
value|((fd)>= __REM_BIAS)
end_define

begin_define
define|#
directive|define
name|__REM_BIAS
value|(1<< 30)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|O_CREAT
end_ifndef

begin_define
define|#
directive|define
name|O_CREAT
value|01000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|rmtopen
parameter_list|(
name|dev_name
parameter_list|,
name|oflag
parameter_list|,
name|mode
parameter_list|,
name|command
parameter_list|)
define|\
value|(_remdev (dev_name) ? rmt_open__ (dev_name, oflag, __REM_BIAS, command) \    : open (dev_name, oflag, mode))
end_define

begin_define
define|#
directive|define
name|rmtaccess
parameter_list|(
name|dev_name
parameter_list|,
name|amode
parameter_list|)
define|\
value|(_remdev (dev_name) ? 0 : access (dev_name, amode))
end_define

begin_define
define|#
directive|define
name|rmtstat
parameter_list|(
name|dev_name
parameter_list|,
name|buffer
parameter_list|)
define|\
value|(_remdev (dev_name) ? (errno = EOPNOTSUPP), -1 : stat (dev_name, buffer))
end_define

begin_define
define|#
directive|define
name|rmtcreat
parameter_list|(
name|dev_name
parameter_list|,
name|mode
parameter_list|,
name|command
parameter_list|)
define|\
value|(_remdev (dev_name) \     ? rmt_open__ (dev_name, 1 | O_CREAT, __REM_BIAS, command) \     : creat (dev_name, mode))
end_define

begin_define
define|#
directive|define
name|rmtlstat
parameter_list|(
name|dev_name
parameter_list|,
name|muffer
parameter_list|)
define|\
value|(_remdev (dev_name) ? (errno = EOPNOTSUPP), -1 : lstat (dev_name, buffer))
end_define

begin_define
define|#
directive|define
name|rmtread
parameter_list|(
name|fd
parameter_list|,
name|buffer
parameter_list|,
name|length
parameter_list|)
define|\
value|(_isrmt (fd) ? rmt_read__ (fd - __REM_BIAS, buffer, length) \    : safe_read (fd, buffer, length))
end_define

begin_define
define|#
directive|define
name|rmtwrite
parameter_list|(
name|fd
parameter_list|,
name|buffer
parameter_list|,
name|length
parameter_list|)
define|\
value|(_isrmt (fd) ? rmt_write__ (fd - __REM_BIAS, buffer, length) \    : full_write (fd, buffer, length))
end_define

begin_define
define|#
directive|define
name|rmtlseek
parameter_list|(
name|fd
parameter_list|,
name|offset
parameter_list|,
name|where
parameter_list|)
define|\
value|(_isrmt (fd) ? rmt_lseek__ (fd - __REM_BIAS, offset, where) \    : lseek (fd, offset, where))
end_define

begin_define
define|#
directive|define
name|rmtclose
parameter_list|(
name|fd
parameter_list|)
define|\
value|(_isrmt (fd) ? rmt_close__ (fd - __REM_BIAS) : close (fd))
end_define

begin_define
define|#
directive|define
name|rmtioctl
parameter_list|(
name|fd
parameter_list|,
name|request
parameter_list|,
name|argument
parameter_list|)
define|\
value|(_isrmt (fd) ? rmt_ioctl__ (fd - __REM_BIAS, request, argument) \    : ioctl (fd, request, argument))
end_define

begin_define
define|#
directive|define
name|rmtdup
parameter_list|(
name|fd
parameter_list|)
define|\
value|(_isrmt (fd) ? (errno = EOPNOTSUPP), -1 : dup (fd))
end_define

begin_define
define|#
directive|define
name|rmtfstat
parameter_list|(
name|fd
parameter_list|,
name|buffer
parameter_list|)
define|\
value|(_isrmt (fd) ? (errno = EOPNOTSUPP), -1 : fstat (fd, buffer))
end_define

begin_define
define|#
directive|define
name|rmtfcntl
parameter_list|(
name|cd
parameter_list|,
name|command
parameter_list|,
name|argument
parameter_list|)
define|\
value|(_isrmt (fd) ? (errno = EOPNOTSUPP), -1 : fcntl (fd, command, argument))
end_define

begin_define
define|#
directive|define
name|rmtisatty
parameter_list|(
name|fd
parameter_list|)
define|\
value|(_isrmt (fd) ? 0 : isatty (fd))
end_define

end_unit

