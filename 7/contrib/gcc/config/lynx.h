begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target independent definitions for LynxOS.    Copyright (C) 1993, 1994, 1995, 1996, 1999, 2000, 2002, 2003, 2004    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* In this file we set up defaults that can be chosen by<target>/lynx.h files.  A target-specific lynx.h file can decide    either to define and override these definitions or to use them by    ensuring they are undefined at this point.  If we were to #undef    them here we might accidentally disable some target-specific    defines.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXTRA_OS_LYNX_TARGET_SPECS
end_ifndef

begin_define
define|#
directive|define
name|EXTRA_OS_LYNX_TARGET_SPECS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EXTRA_OS_LYNX_SPECS
end_ifndef

begin_define
define|#
directive|define
name|EXTRA_OS_LYNX_SPECS
define|\
value|{ "cpp_os_lynx", CPP_OS_LYNX_SPEC }, \   { "lib_os_lynx", LIB_OS_LYNX_SPEC }, \   { "link_os_lynx", LINK_OS_LYNX_SPEC }, \   { "startfile_os_lynx", STARTFILE_OS_LYNX_SPEC }, \   { "endfile_os_lynx", ENDFILE_OS_LYNX_SPEC }, \   EXTRA_OS_LYNX_TARGET_SPECS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_EXTRA_SPECS
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
value|EXTRA_OS_LYNX_SPECS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) %(cpp_os_lynx)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%(lib_os_lynx)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%(link_os_lynx)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STARTFILE_SPEC
end_ifndef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%(startfile_os_lynx)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENDFILE_SPEC
end_ifndef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"%(endfile_os_lynx)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_OS_LYNX_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CPP_OS_LYNX_SPEC
define|\
value|"%{mthreads: \    %{mlegacy-threads: \      %ecannot use mthreads and mlegacy-threads together}} \  %{mthreads: -D_MULTITHREADED} \  %{mlegacy-threads: -D_THREADS_POSIX4ad4} \  -Asystem=lynx -Asystem=unix -D__Lynx__ -D__unix__"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_OS_LYNX_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LIB_OS_LYNX_SPEC
define|\
value|"%{mlegacy-threads:-lposix-pre1c} -lm -lc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We link static executables for LynxOS by default unless -mshared is    used when linking an executable.  Along the same line, we link to    shared libraries when linking a shared object by default unless    -static is used.     We have to pass in our -L options here otherwise the translated    startfile directories (%D) will take priority over this.    Furthermore since we have to pass in -L options here we have to    make sure that -L options provided by the user take priority over    everything we specify.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_OS_LYNX_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LINK_OS_LYNX_SPEC
define|\
value|"%{shared} %{static} \  %{mshared: %{static: %ecannot use mshared and static together}} \  %{!mshared: %{!shared: %{!static: -static}}} \  %{L*} \  %{mthreads: \    %{mshared: -L/lib/thread/shlib -rpath /lib/thread/shlib} \    %{shared: \      %{!static: -L/lib/thread/shlib -rpath /lib/thread/shlib} \    %{!mshared: -L/lib/thread}} \    %{shared: %{static: -L/lib/thread}}} \  %{!mthreads: \    %{mshared: -L/lib/shlib -rpath /lib/shlib} \    %{shared: -L/lib/shlib -rpath /lib/shlib}} \  %{mlegacy-threads:-lposix-pre1c} -lm -lc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STARTFILE_OS_LYNX_SPEC
end_ifndef

begin_define
define|#
directive|define
name|STARTFILE_OS_LYNX_SPEC
define|\
value|"%{!shared: \    %{!mthreads: \      %{p:gcrt1.o%s} %{pg:gcrt1.o%s} \      %{!p:%{!pg:crt1.o%s}}} \    %{mthreads: \      %{p:thread/gcrt1.o%s} %{pg:thread/gcrt1.o%s} \      %{!p:%{!pg:thread/crt1.o%s }}}}\  %{mthreads: thread/crti.o%s} %{!mthreads: crti.o%s} \  %{!shared: crtbegin.o%s} \  %{shared: crtbeginS.o%s}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ENDFILE_OS_LYNX_SPEC
end_ifndef

begin_define
define|#
directive|define
name|ENDFILE_OS_LYNX_SPEC
define|\
value|"%{!shared: crtend.o%s} \  %{shared: crtendS.o%s} \  %{mthreads: thread/crtn.o%s} %{!mthreads: crtn.o%s}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the actual types of some ANSI-mandated types.  */
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
value|"unsigned int"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PTRDIFF_TYPE
end_ifndef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WCHAR_TYPE
end_ifndef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"long int"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WCHAR_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define ASM_OUTPUT_ALIGN to use the .balign directive rather that    the .align directive with GAS.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|do							\     {							\       if ((LOG) != 0)					\ 	fprintf ((FILE), "\t.balign %d\n", 1<< (LOG));	\     }							\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Keep the *_DEBUGGING_INFO defines from elfos.h except that stabs is    the default on LynxOS.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PREFERRED_DEBUGGING_TYPE
end_ifndef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We have C++ support in our system headers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_IMPLICIT_EXTERN_C
end_ifndef

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_POSIX_IO
end_ifndef

begin_define
define|#
directive|define
name|TARGET_POSIX_IO
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

