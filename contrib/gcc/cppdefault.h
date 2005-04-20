begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CPP Library.    Copyright (C) 1986, 1987, 1989, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2003 Free Software Foundation, Inc.    Contributed by Per Bothner, 1994-95.    Based on CCCP program by Paul Rubin, June 1986    Adapted to ANSI C, Richard Stallman, Jan 1987  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|char
name|cplusplus
decl_stmt|;
comment|/* Only look here if we're compiling C++.  */
specifier|const
name|char
name|cxx_aware
decl_stmt|;
comment|/* Includes in this directory don't need to 				   be wrapped in extern "C" when compiling 				   C++.  */
specifier|const
name|char
name|add_sysroot
decl_stmt|;
comment|/* FNAME should be prefixed by 				   cpp_SYSROOT.  */
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

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cpp_SYSROOT
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

