begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Includes for memory limit warnings.    Copyright (C) 1990, 1993 Free Software Foundation, Inc.   This file is part of the GNU C Library.  The GNU C Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU C Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU C Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__osf__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__mips
argument_list|)
operator|||
name|defined
argument_list|(
name|mips
argument_list|)
operator|)
end_if

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__bsdi__
end_ifdef

begin_define
define|#
directive|define
name|BSD4_2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BSD4_2
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|USG
end_ifndef

begin_include
include|#
directive|include
file|<sys/vlimit.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not USG */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* if BSD4_2 */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4_2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|emacs
end_ifdef

begin_comment
comment|/* The important properties of this type are that 1) it's a pointer, and    2) arithmetic on it should work as if the size of the object pointed    to has a size of 1.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
name|POINTER
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|POINTER
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|SIZE
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|NULL
end_ifdef

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NULL
value|((POINTER) 0)
end_define

begin_function_decl
specifier|extern
name|POINTER
name|start_of_data
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DATA_SEG_BITS
end_ifdef

begin_define
define|#
directive|define
name|EXCEEDS_LISP_PTR
parameter_list|(
name|ptr
parameter_list|)
define|\
value|(((unsigned int) (ptr)& ~DATA_SEG_BITS)>> VALBITS)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXCEEDS_LISP_PTR
parameter_list|(
name|ptr
parameter_list|)
value|((unsigned int) (ptr)>> VALBITS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|DATA_SEG_BITS
end_ifndef

begin_decl_stmt
specifier|extern
name|char
name|etext
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|start_of_data
parameter_list|()
value|&etext
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not emacs */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|etext
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|start_of_data
parameter_list|()
value|&etext
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not emacs */
end_comment

begin_comment
comment|/* start of data space; can be changed by calling malloc_init */
end_comment

begin_decl_stmt
specifier|static
name|POINTER
name|data_space_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of bytes of writable memory we can expect to be able to get */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|lim_data
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|USG
end_ifdef

begin_function
specifier|static
name|void
name|get_lim_data
parameter_list|()
block|{
specifier|extern
name|long
name|ulimit
parameter_list|()
function_decl|;
name|lim_data
operator|=
operator|-
literal|1
expr_stmt|;
comment|/* Use the ulimit call, if we seem to have it.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ULIMIT_BREAK_VALUE
argument_list|)
operator|||
name|defined
argument_list|(
name|LINUX
argument_list|)
name|lim_data
operator|=
name|ulimit
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* If that didn't work, just use the macro's value.  */
ifdef|#
directive|ifdef
name|ULIMIT_BREAK_VALUE
if|if
condition|(
name|lim_data
operator|==
operator|-
literal|1
condition|)
name|lim_data
operator|=
name|ULIMIT_BREAK_VALUE
expr_stmt|;
endif|#
directive|endif
name|lim_data
operator|-=
operator|(
name|long
operator|)
name|data_space_start
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not USG */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BSD4_2
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__osf__
argument_list|)
end_if

begin_function
specifier|static
name|void
name|get_lim_data
parameter_list|()
block|{
name|lim_data
operator|=
name|vlimit
argument_list|(
name|LIM_DATA
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BSD4_2 */
end_comment

begin_function
specifier|static
name|void
name|get_lim_data
parameter_list|()
block|{
name|struct
name|rlimit
name|XXrlimit
decl_stmt|;
name|getrlimit
argument_list|(
name|RLIMIT_DATA
argument_list|,
operator|&
name|XXrlimit
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|RLIM_INFINITY
name|lim_data
operator|=
name|XXrlimit
operator|.
name|rlim_cur
operator|&
name|RLIM_INFINITY
expr_stmt|;
comment|/* soft limit */
else|#
directive|else
name|lim_data
operator|=
name|XXrlimit
operator|.
name|rlim_cur
expr_stmt|;
comment|/* soft limit */
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4_2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not USG */
end_comment

end_unit

