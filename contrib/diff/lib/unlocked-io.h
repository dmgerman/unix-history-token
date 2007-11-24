begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Prefer faster, non-thread-safe stdio functions if available.     Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Jim Meyering.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNLOCKED_IO_H
end_ifndef

begin_define
define|#
directive|define
name|UNLOCKED_IO_H
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|USE_UNLOCKED_IO
end_ifndef

begin_define
define|#
directive|define
name|USE_UNLOCKED_IO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|USE_UNLOCKED_IO
end_if

begin_comment
comment|/* These are wrappers for functions/macros from the GNU C library, and    from other C libraries supporting POSIX's optional thread-safe functions.     The standard I/O functions are thread-safe.  These *_unlocked ones are    more efficient but not thread-safe.  That they're not thread-safe is    fine since all of the applications in this package are single threaded.     Also, some code that is shared with the GNU C library may invoke    the *_unlocked functions directly.  On hosts that lack those    functions, invoke the non-thread-safe versions instead.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|HAVE_DECL_CLEARERR_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|clearerr
end_undef

begin_define
define|#
directive|define
name|clearerr
parameter_list|(
name|x
parameter_list|)
value|clearerr_unlocked (x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|clearerr_unlocked
parameter_list|(
name|x
parameter_list|)
value|clearerr (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_FEOF_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|feof
end_undef

begin_define
define|#
directive|define
name|feof
parameter_list|(
name|x
parameter_list|)
value|feof_unlocked (x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|feof_unlocked
parameter_list|(
name|x
parameter_list|)
value|feof (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_FERROR_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|ferror
end_undef

begin_define
define|#
directive|define
name|ferror
parameter_list|(
name|x
parameter_list|)
value|ferror_unlocked (x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ferror_unlocked
parameter_list|(
name|x
parameter_list|)
value|ferror (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_FFLUSH_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|fflush
end_undef

begin_define
define|#
directive|define
name|fflush
parameter_list|(
name|x
parameter_list|)
value|fflush_unlocked (x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fflush_unlocked
parameter_list|(
name|x
parameter_list|)
value|fflush (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_FGETS_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|fgets
end_undef

begin_define
define|#
directive|define
name|fgets
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|fgets_unlocked (x,y,z)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fgets_unlocked
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|fgets (x,y,z)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_FPUTC_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|fputc
end_undef

begin_define
define|#
directive|define
name|fputc
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|fputc_unlocked (x,y)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fputc_unlocked
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|fputc (x,y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_FPUTS_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|fputs
end_undef

begin_define
define|#
directive|define
name|fputs
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|fputs_unlocked (x,y)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fputs_unlocked
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|fputs (x,y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_FREAD_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|fread
end_undef

begin_define
define|#
directive|define
name|fread
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|fread_unlocked (w,x,y,z)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fread_unlocked
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|fread (w,x,y,z)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_FWRITE_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|fwrite
end_undef

begin_define
define|#
directive|define
name|fwrite
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|fwrite_unlocked (w,x,y,z)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fwrite_unlocked
parameter_list|(
name|w
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|fwrite (w,x,y,z)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_GETC_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|getc
end_undef

begin_define
define|#
directive|define
name|getc
parameter_list|(
name|x
parameter_list|)
value|getc_unlocked (x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|getc_unlocked
parameter_list|(
name|x
parameter_list|)
value|getc (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_GETCHAR_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|getchar
end_undef

begin_define
define|#
directive|define
name|getchar
parameter_list|()
value|getchar_unlocked ()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|getchar_unlocked
parameter_list|()
value|getchar ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_PUTC_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|putc
end_undef

begin_define
define|#
directive|define
name|putc
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|putc_unlocked (x,y)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|putc_unlocked
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|putc (x,y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_DECL_PUTCHAR_UNLOCKED
end_if

begin_undef
undef|#
directive|undef
name|putchar
end_undef

begin_define
define|#
directive|define
name|putchar
parameter_list|(
name|x
parameter_list|)
value|putchar_unlocked (x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|putchar_unlocked
parameter_list|(
name|x
parameter_list|)
value|putchar (x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|flockfile
end_undef

begin_define
define|#
directive|define
name|flockfile
parameter_list|(
name|x
parameter_list|)
value|((void) 0)
end_define

begin_undef
undef|#
directive|undef
name|ftrylockfile
end_undef

begin_define
define|#
directive|define
name|ftrylockfile
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_undef
undef|#
directive|undef
name|funlockfile
end_undef

begin_define
define|#
directive|define
name|funlockfile
parameter_list|(
name|x
parameter_list|)
value|((void) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_UNLOCKED_IO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNLOCKED_IO_H */
end_comment

end_unit

