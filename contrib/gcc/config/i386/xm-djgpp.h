begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for Intel 80386 running DJGPP.    Copyright (C) 1988, 1996, 1998, 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Use semicolons to separate elements of a path.  */
end_comment

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|';'
end_define

begin_define
define|#
directive|define
name|HOST_EXECUTABLE_SUFFIX
value|".exe"
end_define

begin_comment
comment|/* Even though we support "/", allow "\" since everybody tests both.  */
end_comment

begin_define
define|#
directive|define
name|DIR_SEPARATOR
value|'/'
end_define

begin_define
define|#
directive|define
name|DIR_SEPARATOR_2
value|'\\'
end_define

begin_comment
comment|/* Allow test for DOS drive names.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DOS_BASED_FILE_SYSTEM
end_define

begin_comment
comment|/* System dependent initialization for collect2    to tell system() to act like Unix.  */
end_comment

begin_define
define|#
directive|define
name|COLLECT2_HOST_INITIALIZATION
define|\
value|do { __system_flags |= (__system_allow_multiple_cmds			\ 		          | __system_emulate_chdir); } while (0)
end_define

begin_comment
comment|/* Define a version appropriate for DOS.  */
end_comment

begin_undef
undef|#
directive|undef
name|XREF_FILE_NAME
end_undef

begin_define
define|#
directive|define
name|XREF_FILE_NAME
parameter_list|(
name|xref_file
parameter_list|,
name|file
parameter_list|)
define|\
value|do { \     const char xref_ext[] = ".gxref"; \     strcpy (xref_file, file); \     s = basename (xref_file); \     t = strchr (s, '.'); \     if (t) \       strcpy (t, xref_ext); \     else \       strcat (xref_file, xref_ext); \   } while (0)
end_define

begin_comment
comment|/* Change /dev/env/DJDIR/prefix/dir/ to canonical form so gcc_exec_prefix    is set properly in 'gcc.c'. It also helps to cut down the number of times    the value of the DJGPP environment variable 'DJDIR' is evaluated.  */
end_comment

begin_undef
undef|#
directive|undef
name|GCC_DRIVER_HOST_INITIALIZATION
end_undef

begin_define
define|#
directive|define
name|GCC_DRIVER_HOST_INITIALIZATION
define|\
value|do { \
comment|/* If the environment variable DJDIR is not defined, then DJGPP is not \        installed correctly and GCC will quickly become confused with the \        default prefix settings. Report the problem now so the user doesn't \        receive deceptive "file not found" error messages later.  */
value|\     char *djdir = getenv ("DJDIR"); \     if (djdir == NULL) \       { \
comment|/* DJDIR is automatically defined by the DJGPP environment config \            file pointed to by the environment variable DJGPP. Examine DJGPP \            to try and figure out what's wrong.  */
value|\         char *djgpp = getenv ("DJGPP"); \         if (djgpp == NULL) \           fatal ("environment variable DJGPP not defined"); \         else if (access (djgpp, R_OK) == 0) \           fatal ("environment variable DJGPP points to missing file '%s'", \                  djgpp); \         else \           fatal ("environment variable DJGPP points to corrupt file '%s'", \                   djgpp); \       } \     standard_exec_prefix = update_path (standard_exec_prefix, NULL); \     standard_bindir_prefix = update_path (standard_bindir_prefix, NULL); \     standard_startfile_prefix = update_path (standard_startfile_prefix, NULL); \   } while (0)
end_define

begin_comment
comment|/* Canonicalize paths containing '/dev/env/'; used in prefix.c.    _fixpath is a djgpp-specific function to canonicalize a path.    "/dev/env/DJDIR" evaluates to "c:/djgpp" if DJDIR is "c:/djgpp" for    example.  It removes any trailing '/', so add it back.  */
end_comment

begin_comment
comment|/* We cannot free PATH below as it can point to string constant  */
end_comment

begin_define
define|#
directive|define
name|UPDATE_PATH_HOST_CANONICALIZE
parameter_list|(
name|PATH
parameter_list|)
define|\
value|if (memcmp ((PATH), "/dev/env/", sizeof("/dev/env/") - 1) == 0) \     {						\       static char fixed_path[FILENAME_MAX + 1];	\ 						\       _fixpath ((PATH), fixed_path);		\       strcat (fixed_path, "/");			\       (PATH) = xstrdup (fixed_path);		\     }
end_define

end_unit

