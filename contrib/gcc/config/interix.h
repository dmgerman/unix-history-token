begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for    Interix    Copyright (C) 1994, 1995, 1999 Free Software Foundation, Inc.    Donn Terry, Softway Systems, Inc. (donn@softway.com)    Modified from code       Contributed by Douglas B. Rupp (drupp@cs.washington.edu).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* POSIX/Uni-thread only for now.  Look at the winnt version for windows/multi thread */
end_comment

begin_comment
comment|/* We need multiple -lc -lcpsx because they mutually refer;    that should go away someday */
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
value|"\  %{!shared:%{!dynamic:-lc -lcpsx -lc -lcpsx %$INTERIX_ROOT/usr/lib/psxdll.a \  %$INTERIX_ROOT/usr/lib/psxdll2.a \  }} \  %{!G:%{!dynamic:-lc -lcpsx -lc -lcpsx %$INTERIX_ROOT/usr/lib/psxdll.a \  %$INTERIX_ROOT/usr/lib/psxdll2.a \  }} \  %{dynamic:-lc %$INTERIX_ROOT/usr/lib/psxdll.a \  %$INTERIX_ROOT/usr/lib/psxdll2.a \  } \  %{v}"
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{!shared:-stack 0x400000,0x10000} \  		   -subsystem posix \ 		   %{g} \ 		   %{dynamic:-Bdynamic} \ 		   %{static:-Bstatic} \ 		   %{shared:--shared -Bdynamic} \ 		   %{G:--shared -Bdynamic} \ 		   %{symbolic:--shared -Bsymbolic -Bdynamic} \ 		   %{soname*:--soname %*} \    		   %{rpath*:--rpath %*} \ 		   "
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
define|\
value|"%{!shared:%{pg:gcrt0%O%s}%{!pg:%{p:mcrt0%O%s}%{!p:crt0%O%s}}} %{shared:crti%O%s}"
end_define

begin_undef
undef|#
directive|undef
name|WORD_SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|((DEFAULT_WORD_SWITCH_TAKES_ARG (STR)					\  || !strcmp(STR, "rpath"))						\&& strcmp (STR, "Tdata")&& strcmp (STR, "Ttext")			\&& strcmp (STR, "Tbss"))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* don't do this until we can sort out the default path issues. MK */
end_comment

begin_undef
undef|#
directive|undef
name|STANDARD_EXEC_PREFIX
end_undef

begin_define
define|#
directive|define
name|STANDARD_EXEC_PREFIX
value|""
end_define

begin_undef
undef|#
directive|undef
name|STANDARD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|STANDARD_STARTFILE_PREFIX
value|""
end_define

begin_undef
undef|#
directive|undef
name|TOOLDIR_BASE_PREFIX
end_undef

begin_define
define|#
directive|define
name|TOOLDIR_BASE_PREFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_undef
undef|#
directive|undef
name|STDC_VALUE
end_undef

begin_define
define|#
directive|define
name|STDC_VALUE
value|0
end_define

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_undef
undef|#
directive|undef
name|HANDLE_PRAGMA_WEAK
end_undef

begin_comment
comment|/* until the link format can handle it */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_comment
comment|/* TARGET_DEFAULT from configure */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_UNSIGNED
value|1
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|16
end_define

begin_comment
comment|/* For the sake of libgcc2.c, indicate target supports atexit.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

end_unit

