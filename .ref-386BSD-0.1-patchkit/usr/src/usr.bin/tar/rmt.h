begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Remote tape drive defines for tar.    Copyright (C) 1988 Free Software Foundation  This file is part of GNU Tar.  GNU Tar is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Tar is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Tar; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_REMOTE
end_ifdef

begin_define
define|#
directive|define
name|_isrmt
parameter_list|(
name|f
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|rmtopen
value|open
end_define

begin_define
define|#
directive|define
name|rmtaccess
value|access
end_define

begin_define
define|#
directive|define
name|rmtstat
value|stat
end_define

begin_define
define|#
directive|define
name|rmtcreat
value|creat
end_define

begin_define
define|#
directive|define
name|rmtlstat
value|lstat
end_define

begin_define
define|#
directive|define
name|rmtread
value|read
end_define

begin_define
define|#
directive|define
name|rmtwrite
value|write
end_define

begin_define
define|#
directive|define
name|rmtlseek
value|lseek
end_define

begin_define
define|#
directive|define
name|rmtclose
value|close
end_define

begin_define
define|#
directive|define
name|rmtioctl
value|ioctl
end_define

begin_define
define|#
directive|define
name|rmtdup
value|dup
end_define

begin_define
define|#
directive|define
name|rmtfstat
value|fstat
end_define

begin_define
define|#
directive|define
name|rmtfcntl
value|fcntl
end_define

begin_define
define|#
directive|define
name|rmtisatty
value|isatty
end_define

begin_function_decl
specifier|extern
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|USG
end_ifndef

begin_define
define|#
directive|define
name|strchr
value|index
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__REM_BIAS
value|128
end_define

begin_define
define|#
directive|define
name|RMTIOCTL
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|__rmt_path
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|strchr
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_remdev
parameter_list|(
name|path
parameter_list|)
value|((__rmt_path=strchr(path, ':'))&& strncmp(__rmt_path, ":/dev/", 6)==0)
end_define

begin_define
define|#
directive|define
name|_isrmt
parameter_list|(
name|fd
parameter_list|)
value|((fd)>= __REM_BIAS)
end_define

begin_define
define|#
directive|define
name|rmtopen
parameter_list|(
name|path
parameter_list|,
name|oflag
parameter_list|,
name|mode
parameter_list|)
value|(_remdev(path) ? __rmt_open(path, oflag, mode, __REM_BIAS) : open(path, oflag, mode))
end_define

begin_define
define|#
directive|define
name|rmtaccess
parameter_list|(
name|path
parameter_list|,
name|amode
parameter_list|)
value|(_remdev(path) ? 0 : access(path, amode))
end_define

begin_define
define|#
directive|define
name|rmtstat
parameter_list|(
name|path
parameter_list|,
name|buf
parameter_list|)
value|(_remdev(path) ? (errno = EOPNOTSUPP), -1 : stat(path, buf))
end_define

begin_define
define|#
directive|define
name|rmtcreat
parameter_list|(
name|path
parameter_list|,
name|mode
parameter_list|)
value|(_remdev(path) ? __rmt_open (path, 1 | O_CREAT, mode, __REM_BIAS) : creat(path, mode))
end_define

begin_define
define|#
directive|define
name|rmtlstat
parameter_list|(
name|path
parameter_list|,
name|buf
parameter_list|)
value|(_remdev(path) ? (errno = EOPNOTSUPP), -1 : lstat(path,buf))
end_define

begin_define
define|#
directive|define
name|rmtread
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
value|(_isrmt(fd) ? __rmt_read(fd - __REM_BIAS, buf, n) : read(fd, buf, n))
end_define

begin_define
define|#
directive|define
name|rmtwrite
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
value|(_isrmt(fd) ? __rmt_write(fd - __REM_BIAS, buf, n) : write(fd, buf, n))
end_define

begin_define
define|#
directive|define
name|rmtlseek
parameter_list|(
name|fd
parameter_list|,
name|off
parameter_list|,
name|wh
parameter_list|)
value|(_isrmt(fd) ? __rmt_lseek(fd - __REM_BIAS, off, wh) : lseek(fd, off, wh))
end_define

begin_define
define|#
directive|define
name|rmtclose
parameter_list|(
name|fd
parameter_list|)
value|(_isrmt(fd) ? __rmt_close(fd - __REM_BIAS) : close(fd))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|RMTIOCTL
end_ifdef

begin_define
define|#
directive|define
name|rmtioctl
parameter_list|(
name|fd
parameter_list|,
name|req
parameter_list|,
name|arg
parameter_list|)
value|(_isrmt(fd) ? __rmt_ioctl(fd - __REM_BIAS, req, arg) : ioctl(fd, req, arg))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|rmtioctl
parameter_list|(
name|fd
parameter_list|,
name|req
parameter_list|,
name|arg
parameter_list|)
value|(_isrmt(fd) ? (errno = EOPNOTSUPP), -1 : ioctl(fd, req, arg))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|rmtdup
parameter_list|(
name|fd
parameter_list|)
value|(_isrmt(fd) ? (errno = EOPNOTSUPP), -1 : dup(fd))
end_define

begin_define
define|#
directive|define
name|rmtfstat
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|)
value|(_isrmt(fd) ? (errno = EOPNOTSUPP), -1 : fstat(fd, buf))
end_define

begin_define
define|#
directive|define
name|rmtfcntl
parameter_list|(
name|fd
parameter_list|,
name|cmd
parameter_list|,
name|arg
parameter_list|)
value|(_isrmt(fd) ? (errno = EOPNOTSUPP), -1 : fcntl (fd, cmd, arg))
end_define

begin_define
define|#
directive|define
name|rmtisatty
parameter_list|(
name|fd
parameter_list|)
value|(_isrmt(fd) ? 0 : isatty(fd))
end_define

begin_undef
undef|#
directive|undef
name|RMTIOCTL
end_undef

begin_decl_stmt
specifier|extern
name|long
name|lseek
argument_list|()
decl_stmt|,
name|__rmt_lseek
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

