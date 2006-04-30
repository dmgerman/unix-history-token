begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CPP Library.    Copyright (C) 1986, 1987, 1989, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2003 Free Software Foundation, Inc.    Contributed by Per Bothner, 1994-95.    Based on CCCP program by Paul Rubin, June 1986    Adapted to ANSI C, Richard Stallman, Jan 1987  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"cppdefault.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|STANDARD_INCLUDE_DIR
end_ifndef

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_DIR
value|"/usr/include"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STANDARD_INCLUDE_COMPONENT
end_ifndef

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_COMPONENT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CROSS_COMPILE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_SYSTEM_ROOT
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|LOCAL_INCLUDE_DIR
end_undef

begin_undef
undef|#
directive|undef
name|SYSTEM_INCLUDE_DIR
end_undef

begin_undef
undef|#
directive|undef
name|STANDARD_INCLUDE_DIR
end_undef

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|CROSS_INCLUDE_DIR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|const
name|struct
name|default_include
name|cpp_include_defaults
index|[]
ifdef|#
directive|ifdef
name|INCLUDE_DEFAULTS
init|=
name|INCLUDE_DEFAULTS
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_expr_stmt
operator|=
block|{
ifdef|#
directive|ifdef
name|GPLUSPLUS_INCLUDE_DIR
comment|/* Pick up GNU C++ generic include files.  */
block|{
name|GPLUSPLUS_INCLUDE_DIR
block|,
literal|"G++"
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|GPLUSPLUS_TOOL_INCLUDE_DIR
comment|/* Pick up GNU C++ target-dependent include files.  */
block|{
name|GPLUSPLUS_TOOL_INCLUDE_DIR
block|,
literal|"G++"
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|GPLUSPLUS_BACKWARD_INCLUDE_DIR
comment|/* Pick up GNU C++ backward and deprecated include files.  */
block|{
name|GPLUSPLUS_BACKWARD_INCLUDE_DIR
block|,
literal|"G++"
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LOCAL_INCLUDE_DIR
comment|/* /usr/local/include comes before the fixincluded header files.  */
block|{
name|LOCAL_INCLUDE_DIR
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PREFIX_INCLUDE_DIR
block|{
name|PREFIX_INCLUDE_DIR
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|GCC_INCLUDE_DIR
comment|/* This is the dir for fixincludes and for gcc's private headers.  */
block|{
name|GCC_INCLUDE_DIR
block|,
literal|"GCC"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CROSS_INCLUDE_DIR
comment|/* One place the target system's headers might be.  */
block|{
name|CROSS_INCLUDE_DIR
block|,
literal|"GCC"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TOOL_INCLUDE_DIR
comment|/* Another place the target system's headers might be.  */
block|{
name|TOOL_INCLUDE_DIR
block|,
literal|"BINUTILS"
block|,
literal|0
block|,
literal|1
block|,
literal|0
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SYSTEM_INCLUDE_DIR
comment|/* Some systems have an extra dir of include files.  */
block|{
name|SYSTEM_INCLUDE_DIR
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|}
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|STANDARD_INCLUDE_DIR
comment|/* /usr/include comes dead last.  */
block|{
name|STANDARD_INCLUDE_DIR
block|,
name|STANDARD_INCLUDE_COMPONENT
block|,
literal|0
block|,
literal|0
block|,
literal|1
block|}
block|,
endif|#
directive|endif
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no INCLUDE_DEFAULTS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GCC_INCLUDE_DIR
end_ifdef

begin_decl_stmt
specifier|const
name|char
name|cpp_GCC_INCLUDE_DIR
index|[]
init|=
name|GCC_INCLUDE_DIR
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|size_t
name|cpp_GCC_INCLUDE_DIR_len
init|=
sizeof|sizeof
name|GCC_INCLUDE_DIR
operator|-
literal|8
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|const
name|char
name|cpp_GCC_INCLUDE_DIR
index|[]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|size_t
name|cpp_GCC_INCLUDE_DIR_len
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_SYSTEM_ROOT
end_ifdef

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cpp_SYSROOT
init|=
name|TARGET_SYSTEM_ROOT
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cpp_SYSROOT
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

