begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CPP Library.    Copyright (C) 1986, 1987, 1989, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000 Free Software Foundation, Inc.    Contributed by Per Bothner, 1994-95.    Based on CCCP program by Paul Rubin, June 1986    Adapted to ANSI C, Richard Stallman, Jan 1987  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CPPDEFAULT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_CPPDEFAULT_H
end_define

begin_comment
comment|/* This header contains declarations and/or #defines for all the    hard-wired defaults in cpp.  Note it's used by both cpplib and    tradcpp.  */
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_COMPILE
end_ifdef

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

begin_comment
comment|/* We let tm.h override the types used here, to handle trivial differences    such as the choice of unsigned int or long unsigned int for size_t.    When machines start needing nontrivial differences in the size type,    it would be best to do something here to figure out automatically    from other information what type to use.  */
end_comment

begin_comment
comment|/* The string value for __SIZE_TYPE__.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The string value for __PTRDIFF_TYPE__.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PTRDIFF_TYPE
end_ifndef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"long int"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The string value for __WCHAR_TYPE__.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WCHAR_TYPE
end_ifndef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"int"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The string value for __WINT_TYPE__.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINT_TYPE
end_ifndef

begin_define
define|#
directive|define
name|WINT_TYPE
value|"unsigned int"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The string value for __USER_LABEL_PREFIX__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USER_LABEL_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The string value for __REGISTER_PREFIX__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGISTER_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|REGISTER_PREFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the default list of directories to search for include files.    It may be overridden by the various -I and -ixxx options.     #include "file" looks in the same directory as the current file,    then this list.    #include<file> just looks in this list.     All these directories are treated as `system' include directories    (they are not subject to pedantic warnings in some cases).  */
end_comment

begin_struct
struct|struct
name|default_include
block|{
specifier|const
name|char
modifier|*
specifier|const
name|fname
decl_stmt|;
comment|/* The name of the directory.  */
specifier|const
name|char
modifier|*
specifier|const
name|component
decl_stmt|;
comment|/* The component containing the directory 				   (see update_path in prefix.c) */
specifier|const
name|int
name|cplusplus
decl_stmt|;
comment|/* Only look here if we're compiling C++.  */
specifier|const
name|int
name|cxx_aware
decl_stmt|;
comment|/* Includes in this directory don't need to 				   be wrapped in extern "C" when compiling 				   C++.  */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|default_include
name|cpp_include_defaults
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|cpp_GCC_INCLUDE_DIR
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|size_t
name|cpp_GCC_INCLUDE_DIR_len
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_CPPDEFAULT_H */
end_comment

end_unit

