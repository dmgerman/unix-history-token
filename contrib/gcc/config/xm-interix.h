begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU compiler for processor running Interix    Copyright (C) 1993, 1995, 1999 Free Software Foundation, Inc.    Donn Terry, Softway Systems, Inc,    from code       Contributed by Douglas B. Rupp (drupp@cs.washington.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USG
end_ifndef

begin_define
define|#
directive|define
name|USG
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ONLY_INT_FIELDS
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|ONLY_INT_FIELDS
value|1
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
name|USE_PROTOTYPES
end_ifndef

begin_define
define|#
directive|define
name|USE_PROTOTYPES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If not compiled with GNU C, use the portable alloca.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|USE_C_ALLOCA
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NO_SYS_SIGLIST
value|1
end_define

begin_comment
comment|/* Our strategy for finding global constructors is a bit different, although    not a lot. */
end_comment

begin_define
define|#
directive|define
name|DO_GLOBAL_CTORS_BODY
define|\
value|do {									\   int i;								\   unsigned long nptrs;							\   func_ptr *p;								\   asm(									\        "     .section .ctor_head, \"rw\"\n"				\        "1:\n"								\        "     .text \n"							\        ASM_LOAD_ADDR(1b,%0)						\        : "=r" (p) : : "cc");						\   for (nptrs = 0; p[nptrs] != 0; nptrs++);				\   for (i = nptrs-1; i>= 0; i--)					\     p[i] ();								\ } while (0)
end_define

begin_define
define|#
directive|define
name|DO_GLOBAL_DTORS_BODY
define|\
value|do {									\   func_ptr *p;								\   asm(									\        "     .section .dtor_head, \"rw\"\n"				\        "1:\n"								\        "     .text \n"							\        ASM_LOAD_ADDR(1b,%0)						\        : "=r" (p) : : "cc");						\   while (*p)								\     {									\       p++;								\       (*(p-1)) ();							\     }									\ } while (0)
end_define

end_unit

