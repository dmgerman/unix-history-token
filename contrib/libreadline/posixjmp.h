begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* posixjmp.h -- wrapper for setjmp.h with changes for POSIX systems. */
end_comment

begin_comment
comment|/* Copyright (C) 1987,1991 Free Software Foundation, Inc.     This file is part of GNU Bash, the Bourne Again SHell.     Bash is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     Bash is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with Bash; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIXJMP_H_
end_ifndef

begin_define
define|#
directive|define
name|_POSIXJMP_H_
end_define

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/* This *must* be included *after* config.h */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_POSIX_SIGSETJMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|procenv_t
value|sigjmp_buf
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__OPENNT
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|setjmp
end_undef

begin_define
define|#
directive|define
name|setjmp
parameter_list|(
name|x
parameter_list|)
value|sigsetjmp((x), 1)
end_define

begin_undef
undef|#
directive|undef
name|longjmp
end_undef

begin_define
define|#
directive|define
name|longjmp
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|siglongjmp((x), (n))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__OPENNT */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|procenv_t
value|jmp_buf
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
comment|/* _POSIXJMP_H_ */
end_comment

end_unit

