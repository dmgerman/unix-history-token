begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions relating to the special __do_global_init function used    for getting g++ file-scope static objects constructed.  This file    will get included either by libgcc2.c (for systems that don't support    a .init section) or by crtstuff.c (for those that do).     Written by Ron Guilmette (rfg@netcom.com)  Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*	This file contains definitions and declarations of things 	relating to the normal start-up-time invocation of C++ 	file-scope static object constructors.  These declarations 	and definitions are used by *both* libgcc2.c and by crtstuff.c.  	Note that this file should only be compiled with GCC. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ATEXIT
end_ifdef

begin_function_decl
specifier|extern
name|void
name|atexit
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ON_EXIT
parameter_list|(
name|FUNC
parameter_list|,
name|ARG
parameter_list|)
value|atexit ((FUNC))
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_function_decl
specifier|extern
name|void
name|on_exit
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ON_EXIT
parameter_list|(
name|FUNC
parameter_list|,
name|ARG
parameter_list|)
value|on_exit ((FUNC), (ARG))
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
comment|/*  Declare a pointer to void function type.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|func_ptr
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Declare the set of symbols use as begin and end markers for the lists    of global object constructors and global object destructors.  */
end_comment

begin_decl_stmt
specifier|extern
name|func_ptr
name|__CTOR_LIST__
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|func_ptr
name|__DTOR_LIST__
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare the routine which need to get invoked at program exit time.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__do_global_dtors
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Define a macro with the code which needs to be executed at program    start-up time.  This macro is used in two places in crtstuff.c (for    systems which support a .init section) and in one place in libgcc2.c    (for those system which do *not* support a .init section).  For all    three places where this code might appear, it must be identical, so    we define it once here as a macro to avoid various instances getting    out-of-sync with one another.  */
end_comment

begin_comment
comment|/* The first word may or may not contain the number of pointers in the table.    In all cases, the table is null-terminated.    We ignore the first word and scan up to the null.  */
end_comment

begin_comment
comment|/* Some systems use a different strategy for finding the ctors.    For example, svr3.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DO_GLOBAL_CTORS_BODY
end_ifndef

begin_define
define|#
directive|define
name|DO_GLOBAL_CTORS_BODY
define|\
value|do {									\   func_ptr *p;								\   for (p = __CTOR_LIST__ + 1; *p; )					\     (*p++) ();								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

