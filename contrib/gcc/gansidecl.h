begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ANSI and traditional C compatibility macros.    Copyright (C) 1996, 1997, 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file mimics some of the support provided by include/ansidecl.h    in binutils and gdb releases.    ??? Over time the two should be merged into one.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ANSIDECL_H
end_ifndef

begin_define
define|#
directive|define
name|ANSIDECL_H
end_define

begin_comment
comment|/* Add prototype support.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROTO
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
condition|?
name|USE_PROTOTYPES
expr|:
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|ARGS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VPROTO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|PVPROTO
parameter_list|(
name|ARGS
parameter_list|)
value|ARGS
end_define

begin_define
define|#
directive|define
name|VPROTO
parameter_list|(
name|ARGS
parameter_list|)
value|ARGS
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|va_list
parameter_list|,
name|var
parameter_list|)
value|va_start(va_list,var)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PVPROTO
parameter_list|(
name|ARGS
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|VPROTO
parameter_list|(
name|ARGS
parameter_list|)
value|(va_alist) va_dcl
end_define

begin_define
define|#
directive|define
name|VA_START
parameter_list|(
name|va_list
parameter_list|,
name|var
parameter_list|)
value|va_start(va_list)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
operator|)
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_UNUSED
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_UNUSED
value|__attribute__ ((__unused__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTRIBUTE_UNUSED */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ATTRIBUTE_PRINTF
end_ifndef

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|__attribute__ ((format (__printf__, m, n)))
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_1
value|ATTRIBUTE_PRINTF(1, 2)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_2
value|ATTRIBUTE_PRINTF(2, 3)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_3
value|ATTRIBUTE_PRINTF(3, 4)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_4
value|ATTRIBUTE_PRINTF(4, 5)
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE_PRINTF_5
value|ATTRIBUTE_PRINTF(5, 6)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTRIBUTE_PRINTF */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GENERIC_PTR
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
condition|?
name|USE_PROTOTYPES
expr|:
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|GENERIC_PTR
value|void *
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GENERIC_PTR
value|char *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NULL_PTR
end_ifndef

begin_define
define|#
directive|define
name|NULL_PTR
value|((GENERIC_PTR) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|PTR
value|void *
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTR
value|char *
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|const
end_ifndef

begin_define
define|#
directive|define
name|const
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
comment|/* ! __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANSIDECL_H */
end_comment

end_unit

