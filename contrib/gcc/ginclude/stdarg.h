begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1997, 1998, 1999, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you include this header file into source    files compiled by GCC, this header file does not by itself cause    the resulting executable to be covered by the GNU General Public    License.  This exception does not however invalidate any other    reasons why the executable file might be covered by the GNU General    Public License.  */
end_comment

begin_comment
comment|/*  * ISO C Standard:  7.15  Variable arguments<stdarg.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STDARG_H
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_ANSI_STDARG_H_
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__need___va_list
end_ifndef

begin_define
define|#
directive|define
name|_STDARG_H
end_define

begin_define
define|#
directive|define
name|_ANSI_STDARG_H_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __need___va_list */
end_comment

begin_undef
undef|#
directive|undef
name|__need___va_list
end_undef

begin_comment
comment|/* Define __gnuc_va_list.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC_VA_LIST
end_ifndef

begin_define
define|#
directive|define
name|__GNUC_VA_LIST
end_define

begin_typedef
typedef|typedef
name|__builtin_va_list
name|__gnuc_va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the standard macros for the user,    if this invocation was from the user program.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_STDARG_H
end_ifdef

begin_comment
comment|/* Note that the type used in va_arg is supposed to match the    actual type **after default promotions**.    Thus, va_arg (..., short) is not valid.  */
end_comment

begin_define
define|#
directive|define
name|va_start
parameter_list|(
name|v
parameter_list|,
name|l
parameter_list|)
value|__builtin_stdarg_start((v),l)
end_define

begin_define
define|#
directive|define
name|va_end
value|__builtin_va_end
end_define

begin_define
define|#
directive|define
name|va_arg
value|__builtin_va_arg
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
operator|||
name|__STDC_VERSION__
operator|+
literal|0
operator|>=
literal|199900L
end_if

begin_define
define|#
directive|define
name|va_copy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|__builtin_va_copy((d),(s))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__va_copy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|__builtin_va_copy((d),(s))
end_define

begin_comment
comment|/* Define va_list, if desired, from __gnuc_va_list. */
end_comment

begin_comment
comment|/* We deliberately do not define va_list when called from    stdio.h, because ANSI C says that stdio.h is not supposed to define    va_list.  stdio.h needs to have access to that data type,     but must not use that name.  It should use the name __gnuc_va_list,    which is safe because it is reserved for the implementation.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_HIDDEN_VA_LIST
end_ifdef

begin_comment
comment|/* On OSF1, this means varargs.h is "half-loaded".  */
end_comment

begin_undef
undef|#
directive|undef
name|_VA_LIST
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_VA_LIST
end_ifdef

begin_undef
undef|#
directive|undef
name|_BSD_VA_LIST
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|_SCO_DS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__VA_LIST
argument_list|)
operator|)
end_if

begin_comment
comment|/* SVR4.2 uses _VA_LIST for an internal alias for va_list,    so we must avoid testing it and setting it here.    SVR4 uses _VA_LIST as a flag in stdarg.h, but we should    have no conflict with that.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__i860__
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST
value|va_list
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
comment|/* __i860__ */
end_comment

begin_typedef
typedef|typedef
name|__gnuc_va_list
name|va_list
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_SCO_DS
end_ifdef

begin_define
define|#
directive|define
name|__VA_LIST
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
comment|/* _VA_LIST_ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __svr4__ || _SCO_DS */
end_comment

begin_comment
comment|/* The macro _VA_LIST_ is the same thing used by this file in Ultrix.    But on BSD NET2 we must not test or define or undef it.    (Note that the comments in NET 2's ansi.h    are incorrect for _VA_LIST_--see stdio.h!)  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_VA_LIST_
argument_list|)
operator|||
name|defined
argument_list|(
name|__BSD_NET2__
argument_list|)
operator|||
name|defined
argument_list|(
name|____386BSD____
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sequent__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|WINNT
argument_list|)
end_if

begin_comment
comment|/* The macro _VA_LIST_DEFINED is used in Windows NT 3.5  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_DEFINED
end_ifndef

begin_comment
comment|/* The macro _VA_LIST is used in SCO Unix 3.2.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST
end_ifndef

begin_comment
comment|/* The macro _VA_LIST_T_H is used in the Bull dpx2  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_T_H
end_ifndef

begin_comment
comment|/* The macro __va_list__ is used by BeOS.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__va_list__
end_ifndef

begin_typedef
typedef|typedef
name|__gnuc_va_list
name|va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __va_list__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _VA_LIST_T_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _VA_LIST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _VA_LIST_DEFINED */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|__BSD_NET2__
argument_list|)
operator|||
name|defined
argument_list|(
name|____386BSD____
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sequent__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|_VA_LIST_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_VA_LIST_T_H
end_ifndef

begin_define
define|#
directive|define
name|_VA_LIST_T_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__va_list__
end_ifndef

begin_define
define|#
directive|define
name|__va_list__
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
comment|/* not _VA_LIST_, except on certain systems */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __svr4__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _STDARG_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _ANSI_STDARG_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _STDARG_H */
end_comment

end_unit

