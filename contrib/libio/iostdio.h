begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (C) 1993 Free Software Foundation  This file is part of the GNU IO Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this library; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_comment
comment|/* This file defines a stdio-like environment, except that it avoid    link-time name clashes with an existing stdio.    It allows for testing the libio using stdio-using programs    with an incompatible libc.a.    It is not predantically correct - e.g. some macros are used    that may evaluate a stream argument more than once.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOSTDIO_H
end_ifndef

begin_define
define|#
directive|define
name|_IOSTDIO_H
end_define

begin_include
include|#
directive|include
file|"iolibio.h"
end_include

begin_typedef
typedef|typedef
name|_IO_FILE
name|FILE
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|EOF
end_ifndef

begin_define
define|#
directive|define
name|EOF
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BUFSIZ
end_ifndef

begin_define
define|#
directive|define
name|BUFSIZ
value|1024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #define size_t, fpos_t L_tmpname TMP_MAX */
end_comment

begin_define
define|#
directive|define
name|_IOFBF
value|0
end_define

begin_comment
comment|/* Fully buffered. */
end_comment

begin_define
define|#
directive|define
name|_IOLBF
value|1
end_define

begin_comment
comment|/* Line buffered. */
end_comment

begin_define
define|#
directive|define
name|_IONBF
value|2
end_define

begin_comment
comment|/* No buffering. */
end_comment

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_define
define|#
directive|define
name|stdin
value|_IO_stdin
end_define

begin_define
define|#
directive|define
name|stdout
value|_IO_stdout
end_define

begin_define
define|#
directive|define
name|stderr
value|_IO_stderr
end_define

begin_define
define|#
directive|define
name|getc
parameter_list|(
name|_fp
parameter_list|)
value|_IO_getc(_fp)
end_define

begin_define
define|#
directive|define
name|putc
parameter_list|(
name|_ch
parameter_list|,
name|_fp
parameter_list|)
value|_IO_putc(_ch, _fp)
end_define

begin_define
define|#
directive|define
name|clearerr
value|_IO_clearerr
end_define

begin_define
define|#
directive|define
name|fclose
value|_IO_fclose
end_define

begin_define
define|#
directive|define
name|feof
value|_IO_feof
end_define

begin_define
define|#
directive|define
name|ferror
value|_IO_ferror
end_define

begin_define
define|#
directive|define
name|fflush
value|_IO_fflush
end_define

begin_define
define|#
directive|define
name|fgetc
parameter_list|(
name|__fp
parameter_list|)
value|_IO_getc(_fp)
end_define

begin_define
define|#
directive|define
name|fgetpos
value|_IO_fgetpos
end_define

begin_define
define|#
directive|define
name|fgets
value|_IO_fgets
end_define

begin_define
define|#
directive|define
name|fopen
value|_IO_fopen
end_define

begin_define
define|#
directive|define
name|fprintf
value|_IO_fprintf
end_define

begin_define
define|#
directive|define
name|fputc
parameter_list|(
name|_ch
parameter_list|,
name|_fp
parameter_list|)
value|_IO_putc(_ch, _fp)
end_define

begin_define
define|#
directive|define
name|fputs
value|_IO_fputs
end_define

begin_define
define|#
directive|define
name|fread
value|_IO_fread
end_define

begin_define
define|#
directive|define
name|freopen
value|_IO_freopen
end_define

begin_define
define|#
directive|define
name|fscanf
value|_IO_fscanf
end_define

begin_define
define|#
directive|define
name|fseek
value|_IO_fseek
end_define

begin_define
define|#
directive|define
name|fsetpos
value|_IO_fsetpos
end_define

begin_define
define|#
directive|define
name|ftell
value|_IO_ftell
end_define

begin_define
define|#
directive|define
name|fwrite
value|_IO_fwrite
end_define

begin_define
define|#
directive|define
name|gets
value|_IO_gets
end_define

begin_define
define|#
directive|define
name|perror
value|_IO_perror
end_define

begin_define
define|#
directive|define
name|printf
value|_IO_printf
end_define

begin_define
define|#
directive|define
name|puts
value|_IO_puts
end_define

begin_define
define|#
directive|define
name|rewind
value|_IO_rewind
end_define

begin_define
define|#
directive|define
name|scanf
value|_IO_scanf
end_define

begin_define
define|#
directive|define
name|setbuf
value|_IO_setbuf
end_define

begin_define
define|#
directive|define
name|setbuffer
value|_IO_setbuffer
end_define

begin_define
define|#
directive|define
name|setvbuf
value|_IO_setvbuf
end_define

begin_define
define|#
directive|define
name|sprintf
value|_IO_sprintf
end_define

begin_define
define|#
directive|define
name|sscanf
value|_IO_sscanf
end_define

begin_define
define|#
directive|define
name|ungetc
value|_IO_ungetc
end_define

begin_define
define|#
directive|define
name|vfprintf
value|_IO_vfprintf
end_define

begin_define
define|#
directive|define
name|vprintf
parameter_list|(
name|__fmt
parameter_list|,
name|__args
parameter_list|)
value|vfprintf(stdout, __fmt, __args)
end_define

begin_define
define|#
directive|define
name|vsprintf
value|_IO_vsprintf
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* We can use the libc versions of these, since they don't pass FILE*s. */
end_comment

begin_define
define|#
directive|define
name|remove
value|??? __P((const char*))
end_define

begin_define
define|#
directive|define
name|rename
value|??? __P((const char* _old, const char* _new))
end_define

begin_define
define|#
directive|define
name|tmpfile
value|??? __P((void))
end_define

begin_define
define|#
directive|define
name|tmpnam
value|??? __P((char*))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
operator|||
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|fdopen
value|_IO_fdopen
end_define

begin_define
define|#
directive|define
name|fileno
value|_IO_fileno
end_define

begin_define
define|#
directive|define
name|popen
value|_IO_popen
end_define

begin_define
define|#
directive|define
name|pclose
value|_IO_pclose
end_define

begin_define
define|#
directive|define
name|setbuf
value|_IO_setbuf
end_define

begin_define
define|#
directive|define
name|setlinebuf
value|_IO_setlinebuf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IOSTDIO_H */
end_comment

end_unit

