begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    hosting on Windows32, using a Unix style C library and tools.    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (x86 Cygwin)");
end_define

begin_define
define|#
directive|define
name|EXTRA_OS_CPP_BUILTINS
parameter_list|()
end_define

begin_comment
comment|/* Nothing.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) %{posix:-D_POSIX_SOURCE} \   %{mno-win32:%{mno-cygwin: %emno-cygwin and mno-win32 are not compatible}} \   %{mno-cygwin:-D__MSVCRT__ -D__MINGW32__ %{!ansi:%{mthreads:-D_MT}}}\   %{!mno-cygwin:-D__CYGWIN32__ -D__CYGWIN__ %{!ansi:-Dunix} -D__unix__ -D__unix }\   %{mwin32|mno-cygwin:-DWIN32 -D_WIN32 -D__WIN32 -D__WIN32__ %{!ansi:-DWINNT}}\   %{!nostdinc:%{!mno-win32|mno-cygwin:-idirafter ../include/w32api%s -idirafter ../../include/w32api%s}}\ "
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"\   %{shared|mdll: %{mno-cygwin:dllcrt2%O%s}}\   %{!shared: %{!mdll: %{!mno-cygwin:crt0%O%s} %{mno-cygwin:crt2%O%s}\   %{pg:gcrt0%O%s}}}\ "
end_define

begin_comment
comment|/* Normally, -lgcc is not needed since everything in it is in the DLL, but we    want to allow things to be added to it when installing new versions of    GCC without making a new CYGWIN.DLL, so we leave it.  Profiling is handled    by calling the init function from main.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
define|\
value|"%{mno-cygwin: %{mthreads:-lmingwthrd} -lmingw32} -lgcc	\    %{mno-cygwin:-lmoldname -lmingwex -lmsvcrt}"
end_define

begin_comment
comment|/* We have to dynamic link to get to the system DLLs.  All of libc, libm and    the Unix stuff is in cygwin.dll.  The import library is called    'libcygwin.a'.  For Windows applications, include more libraries, but    always include kernel32.  We'd like to specific subsystem windows to    ld, but that doesn't work just yet.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"\   %{pg:-lgmon} \   %{!mno-cygwin:-lcygwin} \   %{mno-cygwin:%{mthreads:-lmingwthrd} -lmingw32} \   %{mwindows:-lgdi32 -lcomdlg32} \   -luser32 -lkernel32 -ladvapi32 -lshell32"
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\   %{mwindows:--subsystem windows} \   %{mconsole:--subsystem console} \   %{shared: %{mdll: %eshared and mdll are not compatible}} \   %{shared: --shared} %{mdll:--dll} \   %{static:-Bstatic} %{!static:-Bdynamic} \   %{shared|mdll: -e \     %{mno-cygwin:_DllMainCRTStartup@12} \     %{!mno-cygwin:__cygwin_dll_entry@12}}\   %{!mno-cygwin:--dll-search-prefix=cyg}"
end_define

begin_comment
comment|/* Allocate space for all of the machine-spec-specific stuff.    Allocate enough space for cygwin -> mingw32  munging plus    possible addition of "/mingw".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CYGWIN_MINGW_SUBDIR
end_ifndef

begin_define
define|#
directive|define
name|CYGWIN_MINGW_SUBDIR
value|"/mingw"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CYGWIN_MINGW_SUBDIR_LEN
value|(sizeof (CYGWIN_MINGW_SUBDIR) - 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GPLUSPLUS_INCLUDE_DIR
end_ifdef

begin_decl_stmt
name|char
name|cygwin_gplusplus_include_dir
index|[
sizeof|sizeof
argument_list|(
name|GPLUSPLUS_INCLUDE_DIR
argument_list|)
operator|+
literal|1
operator|+
operator|(
name|CYGWIN_MINGW_SUBDIR_LEN
operator|)
index|]
init|=
name|GPLUSPLUS_INCLUDE_DIR
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|GPLUSPLUS_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|GPLUSPLUS_INCLUDE_DIR
value|((const char *) cygwin_gplusplus_include_dir)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|GEN_CVT_ARRAY
end_ifndef

begin_define
define|#
directive|define
name|GEN_CVT_ARRAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GPLUSPLUS_TOOL_INCLUDE_DIR
end_ifdef

begin_decl_stmt
name|char
name|cygwin_gplusplus_tool_include_dir
index|[
sizeof|sizeof
argument_list|(
name|GPLUSPLUS_TOOL_INCLUDE_DIR
argument_list|)
operator|+
literal|1
operator|+
name|CYGWIN_MINGW_SUBDIR_LEN
index|]
init|=
name|GPLUSPLUS_TOOL_INCLUDE_DIR
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|GPLUSPLUS_TOOL_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|GPLUSPLUS_TOOL_INCLUDE_DIR
value|((const char *) cygwin_gplusplus_tool_include_dir)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|GEN_CVT_ARRAY
end_ifndef

begin_define
define|#
directive|define
name|GEN_CVT_ARRAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GPLUSPLUS_BACKWARD_INCLUDE_DIR
end_ifdef

begin_decl_stmt
name|char
name|cygwin_gplusplus_backward_include_dir
index|[
sizeof|sizeof
argument_list|(
name|GPLUSPLUS_BACKWARD_INCLUDE_DIR
argument_list|)
operator|+
literal|1
operator|+
name|CYGWIN_MINGW_SUBDIR_LEN
index|]
init|=
name|GPLUSPLUS_BACKWARD_INCLUDE_DIR
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|GPLUSPLUS_BACKWARD_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|GPLUSPLUS_BACKWARD_INCLUDE_DIR
value|((const char *) cygwin_gplusplus_backward_include_dir)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|GEN_CVT_ARRAY
end_ifndef

begin_define
define|#
directive|define
name|GEN_CVT_ARRAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|LOCAL_INCLUDE_DIR
end_ifdef

begin_decl_stmt
name|char
name|cygwin_local_include_dir
index|[
sizeof|sizeof
argument_list|(
name|LOCAL_INCLUDE_DIR
argument_list|)
operator|+
literal|1
operator|+
name|CYGWIN_MINGW_SUBDIR_LEN
index|]
init|=
name|LOCAL_INCLUDE_DIR
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|LOCAL_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|LOCAL_INCLUDE_DIR
value|((const char *) cygwin_local_include_dir)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|GEN_CVT_ARRAY
end_ifndef

begin_define
define|#
directive|define
name|GEN_CVT_ARRAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_INCLUDE_DIR
end_ifdef

begin_decl_stmt
name|char
name|cygwin_cross_include_dir
index|[
sizeof|sizeof
argument_list|(
name|CROSS_INCLUDE_DIR
argument_list|)
operator|+
literal|1
operator|+
name|CYGWIN_MINGW_SUBDIR_LEN
index|]
init|=
name|CROSS_INCLUDE_DIR
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|CROSS_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|CROSS_INCLUDE_DIR
value|((const char *) cygwin_cross_include_dir)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|GEN_CVT_ARRAY
end_ifndef

begin_define
define|#
directive|define
name|GEN_CVT_ARRAY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TOOL_INCLUDE_DIR
end_ifdef

begin_decl_stmt
name|char
name|cygwin_tool_include_dir
index|[
sizeof|sizeof
argument_list|(
name|TOOL_INCLUDE_DIR
argument_list|)
operator|+
literal|1
operator|+
name|CYGWIN_MINGW_SUBDIR_LEN
index|]
init|=
name|TOOL_INCLUDE_DIR
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|TOOL_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|TOOL_INCLUDE_DIR
value|((const char *) cygwin_tool_include_dir)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_undef
undef|#
directive|undef
name|STANDARD_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_DIR
value|"/usr/include"
end_define

begin_decl_stmt
name|char
name|cygwin_standard_include_dir
index|[
sizeof|sizeof
argument_list|(
name|STANDARD_INCLUDE_DIR
argument_list|)
operator|+
literal|1
operator|+
name|CYGWIN_MINGW_SUBDIR_LEN
index|]
init|=
name|STANDARD_INCLUDE_DIR
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|STANDARD_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_DIR
value|((const char *) cygwin_standard_include_dir)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|GEN_CVT_ARRAY
end_ifndef

begin_define
define|#
directive|define
name|GEN_CVT_ARRAY
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
name|GEN_CVT_ARRAY
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cvt_to_mingw
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|char
modifier|*
name|cvt_to_mingw
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|GPLUSPLUS_INCLUDE_DIR
name|cygwin_gplusplus_include_dir
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|GPLUSPLUS_TOOL_INCLUDE_DIR
name|cygwin_gplusplus_tool_include_dir
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|GPLUSPLUS_BACKWARD_INCLUDE_DIR
name|cygwin_gplusplus_backward_include_dir
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|LOCAL_INCLUDE_DIR
name|cygwin_local_include_dir
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|CROSS_INCLUDE_DIR
name|cygwin_cross_include_dir
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TOOL_INCLUDE_DIR
name|cygwin_tool_include_dir
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|STANDARD_INCLUDE_DIR
name|cygwin_standard_include_dir
block|,
endif|#
directive|endif
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|GEN_CVT_ARRAY
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*GEN_CVT_ARRAY*/
end_comment

begin_function_decl
name|void
name|mingw_scan
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|GCC_DRIVER_HOST_INITIALIZATION
define|\
value|do \ { \   mingw_scan(argc, argv, (char **)&spec_machine); \   } \ while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GCC_DRIVER_HOST_INITIALIZATION
define|\
value|do \ { \   char *cprefix = concat (tooldir_base_prefix, spec_machine, \ 			  dir_separator_str, NULL); \   if (!IS_ABSOLUTE_PATH (cprefix)) \     cprefix = concat (standard_exec_prefix, spec_machine, dir_separator_str, \ 		      spec_version, dir_separator_str, tooldir_prefix, NULL); \   add_prefix (&exec_prefixes,\ 	      concat (cprefix, "../../../../", spec_machine, "/bin/", NULL), \ 	      "BINUTILS", PREFIX_PRIORITY_LAST, 0, NULL); \   add_prefix (&exec_prefixes, cprefix, \ 	      "BINUTILS", PREFIX_PRIORITY_LAST, 0, NULL); \   add_prefix (&startfile_prefixes,\ 	      concat (standard_startfile_prefix, "w32api", NULL),\ 	      "GCC", PREFIX_PRIORITY_LAST, 0, NULL);\   mingw_scan(argc, argv,&spec_machine); \   } \ while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

