begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for communicating with a remote tape drive.    Copyright 1988, 1992, 1996, 1997, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rmt_path__
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rmt_open__
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rmt_close__
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|rmt_read__
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ssize_t
name|rmt_write__
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|off_t
name|rmt_lseek__
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|off_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|rmt_ioctl__
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
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
name|Path
parameter_list|)
define|\
value|(!force_local_option&& (rmt_path__ = strchr (Path, ':')) \&& rmt_path__> (Path)&& ! memchr (Path, rmt_path__ - (Path), '/'))
end_define

begin_define
define|#
directive|define
name|_isrmt
parameter_list|(
name|Fd
parameter_list|)
define|\
value|((Fd)>= __REM_BIAS)
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
name|Path
parameter_list|,
name|Oflag
parameter_list|,
name|Mode
parameter_list|,
name|Command
parameter_list|)
define|\
value|(_remdev (Path) ? rmt_open__ (Path, Oflag, __REM_BIAS, Command) \    : open (Path, Oflag, Mode))
end_define

begin_define
define|#
directive|define
name|rmtaccess
parameter_list|(
name|Path
parameter_list|,
name|Amode
parameter_list|)
define|\
value|(_remdev (Path) ? 0 : access (Path, Amode))
end_define

begin_define
define|#
directive|define
name|rmtstat
parameter_list|(
name|Path
parameter_list|,
name|Buffer
parameter_list|)
define|\
value|(_remdev (Path) ? (errno = EOPNOTSUPP), -1 : stat (Path, Buffer))
end_define

begin_define
define|#
directive|define
name|rmtcreat
parameter_list|(
name|Path
parameter_list|,
name|Mode
parameter_list|,
name|Command
parameter_list|)
define|\
value|(_remdev (Path) \     ? rmt_open__ (Path, 1 | O_CREAT, __REM_BIAS, Command) \     : creat (Path, Mode))
end_define

begin_define
define|#
directive|define
name|rmtlstat
parameter_list|(
name|Path
parameter_list|,
name|Buffer
parameter_list|)
define|\
value|(_remdev (Path) ? (errno = EOPNOTSUPP), -1 : lstat (Path, Buffer))
end_define

begin_define
define|#
directive|define
name|rmtread
parameter_list|(
name|Fd
parameter_list|,
name|Buffer
parameter_list|,
name|Length
parameter_list|)
define|\
value|(_isrmt (Fd) ? rmt_read__ (Fd - __REM_BIAS, Buffer, Length) \    : safe_read (Fd, Buffer, Length))
end_define

begin_define
define|#
directive|define
name|rmtwrite
parameter_list|(
name|Fd
parameter_list|,
name|Buffer
parameter_list|,
name|Length
parameter_list|)
define|\
value|(_isrmt (Fd) ? rmt_write__ (Fd - __REM_BIAS, Buffer, Length) \    : full_write (Fd, Buffer, Length))
end_define

begin_define
define|#
directive|define
name|rmtlseek
parameter_list|(
name|Fd
parameter_list|,
name|Offset
parameter_list|,
name|Where
parameter_list|)
define|\
value|(_isrmt (Fd) ? rmt_lseek__ (Fd - __REM_BIAS, Offset, Where) \    : lseek (Fd, Offset, Where))
end_define

begin_define
define|#
directive|define
name|rmtclose
parameter_list|(
name|Fd
parameter_list|)
define|\
value|(_isrmt (Fd) ? rmt_close__ (Fd - __REM_BIAS) : close (Fd))
end_define

begin_define
define|#
directive|define
name|rmtioctl
parameter_list|(
name|Fd
parameter_list|,
name|Request
parameter_list|,
name|Argument
parameter_list|)
define|\
value|(_isrmt (Fd) ? rmt_ioctl__ (Fd - __REM_BIAS, Request, Argument) \    : ioctl (Fd, Request, Argument))
end_define

begin_define
define|#
directive|define
name|rmtdup
parameter_list|(
name|Fd
parameter_list|)
define|\
value|(_isrmt (Fd) ? (errno = EOPNOTSUPP), -1 : dup (Fd))
end_define

begin_define
define|#
directive|define
name|rmtfstat
parameter_list|(
name|Fd
parameter_list|,
name|Buffer
parameter_list|)
define|\
value|(_isrmt (Fd) ? (errno = EOPNOTSUPP), -1 : fstat (Fd, Buffer))
end_define

begin_define
define|#
directive|define
name|rmtfcntl
parameter_list|(
name|Fd
parameter_list|,
name|Command
parameter_list|,
name|Argument
parameter_list|)
define|\
value|(_isrmt (Fd) ? (errno = EOPNOTSUPP), -1 : fcntl (Fd, Command, Argument))
end_define

begin_define
define|#
directive|define
name|rmtisatty
parameter_list|(
name|Fd
parameter_list|)
define|\
value|(_isrmt (Fd) ? 0 : isatty (Fd))
end_define

end_unit

