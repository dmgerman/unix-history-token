begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Base configuration file for all NetBSD targets.    Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* TARGET_OS_CPP_BUILTINS() common to all NetBSD targets.  */
end_comment

begin_define
define|#
directive|define
name|NETBSD_OS_CPP_BUILTINS_COMMON
parameter_list|()
define|\
value|do						\     {						\       builtin_define ("__NetBSD__");		\       builtin_assert ("system=unix");		\       builtin_assert ("system=NetBSD");		\     }						\   while (0)
end_define

begin_comment
comment|/* TARGET_OS_CPP_BUILTINS() common to all LP64 NetBSD targets.  */
end_comment

begin_define
define|#
directive|define
name|NETBSD_OS_CPP_BUILTINS_LP64
parameter_list|()
define|\
value|do						\     {						\       builtin_define ("_LP64");			\     }						\   while (0)
end_define

begin_comment
comment|/* CPP_SPEC parts common to all NetBSD targets.  */
end_comment

begin_define
define|#
directive|define
name|NETBSD_CPP_SPEC
define|\
value|"%{posix:-D_POSIX_SOURCE} \    %{pthread:-D_REENTRANT -D_PTHREADS}"
end_define

begin_comment
comment|/* NETBSD_NATIVE is defined when gcc is integrated into the NetBSD    source tree so it can be configured appropriately without using    the GNU configure/build mechanism.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NETBSD_NATIVE
end_ifdef

begin_comment
comment|/* Look for the include files in the system-defined places.  */
end_comment

begin_undef
undef|#
directive|undef
name|GPLUSPLUS_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|GPLUSPLUS_INCLUDE_DIR
value|"/usr/include/g++"
end_define

begin_undef
undef|#
directive|undef
name|GCC_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|GCC_INCLUDE_DIR
value|"/usr/include"
end_define

begin_undef
undef|#
directive|undef
name|INCLUDE_DEFAULTS
end_undef

begin_define
define|#
directive|define
name|INCLUDE_DEFAULTS
define|\
value|{						\     { GPLUSPLUS_INCLUDE_DIR, "G++", 1, 1 },	\     { GCC_INCLUDE_DIR, "GCC", 0, 0 },		\     { 0, 0, 0, 0 }				\   }
end_define

begin_comment
comment|/* Under NetBSD, the normal location of the compiler back ends is the    /usr/libexec directory.  */
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
value|"/usr/libexec/"
end_define

begin_comment
comment|/* Under NetBSD, the normal location of the various *crt*.o files is the    /usr/lib directory.  */
end_comment

begin_undef
undef|#
directive|undef
name|STANDARD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|STANDARD_STARTFILE_PREFIX
value|"/usr/lib/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETBSD_NATIVE */
end_comment

begin_comment
comment|/* Provide a LIB_SPEC appropriate for NetBSD.  Here we:     1. Select the appropriate set of libs, depending on whether we're       profiling.     2. Include the pthread library if -pthread is specified (only       if threads are enabled).     3. Include the posix library if -posix is specified.     FIXME: Could eliminate the duplication here if we were allowed to    use string concatenation.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NETBSD_ENABLE_PTHREADS
end_ifdef

begin_define
define|#
directive|define
name|NETBSD_LIB_SPEC
define|\
value|"%{pthread:			\      %{!p:			\        %{!pg:-lpthread}}	\      %{p:-lpthread_p}		\      %{pg:-lpthread_p}}		\    %{posix:			\      %{!p:			\        %{!pg:-lposix}}		\      %{p:-lposix_p}		\      %{pg:-lposix_p}}		\    %{!shared:			\      %{!symbolic:		\        %{!p:			\ 	 %{!pg:-lc}}		\        %{p:-lc_p}		\        %{pg:-lc_p}}}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NETBSD_LIB_SPEC
define|\
value|"%{posix:			\      %{!p:			\        %{!pg:-lposix}}		\      %{p:-lposix_p}		\      %{pg:-lposix_p}}		\    %{!shared:			\      %{!symbolic:		\        %{!p:			\ 	 %{!pg:-lc}}		\        %{p:-lc_p}		\        %{pg:-lc_p}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|NETBSD_LIB_SPEC
end_define

begin_comment
comment|/* Provide a LIBGCC_SPEC appropriate for NetBSD.  We also want to exclude    libgcc with -symbolic.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NETBSD_NATIVE
end_ifdef

begin_define
define|#
directive|define
name|NETBSD_LIBGCC_SPEC
define|\
value|"%{!symbolic:			\      %{!shared:			\        %{!p:			\ 	 %{!pg: -lgcc}}}	\      %{shared: -lgcc_pic}	\      %{p: -lgcc_p}		\      %{pg: -lgcc_p}}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NETBSD_LIBGCC_SPEC
value|"%{!shared:%{!symbolic: -lgcc}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
value|NETBSD_LIBGCC_SPEC
end_define

begin_comment
comment|/* When building shared libraries, the initialization and finalization     functions for the library are .init and .fini respectively.  */
end_comment

begin_define
define|#
directive|define
name|COLLECT_SHARED_INIT_FUNC
parameter_list|(
name|STREAM
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|do {									\     fprintf ((STREAM), "void __init() __asm__ (\".init\");");		\     fprintf ((STREAM), "void __init() {\n\t%s();\n}\n", (FUNC));	\   } while (0)
end_define

begin_define
define|#
directive|define
name|COLLECT_SHARED_FINI_FUNC
parameter_list|(
name|STREAM
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|do {									\     fprintf ((STREAM), "void __fini() __asm__ (\".fini\");");		\     fprintf ((STREAM), "void __fini() {\n\t%s();\n}\n", (FUNC));	\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|TARGET_HAS_F_SETLKW
end_undef

begin_define
define|#
directive|define
name|TARGET_HAS_F_SETLKW
end_define

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_MEM_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
value|1
end_define

begin_comment
comment|/* Handle #pragma weak and #pragma pack.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
value|1
end_define

begin_comment
comment|/* Define some types that are the same on all NetBSD platforms,    making them agree with<machine/ansi.h>.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_undef
undef|#
directive|undef
name|WINT_TYPE
end_undef

begin_define
define|#
directive|define
name|WINT_TYPE
value|"int"
end_define

begin_escape
end_escape

begin_comment
comment|/* Attempt to turn on execute permission for the stack.  This may be    used by TRANSFER_FROM_TRAMPOLINE of the target needs it (that is,    if the target machine can change execute permissions on a page).     There is no way to query the execute permission of the stack, so    we always issue the mprotect() call.     Note that we go out of our way to use namespace-non-invasive calls    here.  Unfortunately, there is no libc-internal name for mprotect().     Also note that no errors should be emitted by this code; it is considered    dangerous for library calls to send messages to stdout/stderr.  */
end_comment

begin_define
define|#
directive|define
name|NETBSD_ENABLE_EXECUTE_STACK
define|\
value|extern void __enable_execute_stack (void *);				\ void									\ __enable_execute_stack (addr)						\      void *addr;							\ {									\   extern int mprotect (void *, size_t, int);				\   extern int __sysctl (int *, unsigned int, void *, size_t *,		\ 		       void *, size_t);					\ 									\   static int size;							\   static long mask;							\ 									\   char *page, *end;							\ 									\   if (size == 0)							\     {									\       int mib[2];							\       size_t len;							\ 									\       mib[0] = 6;
comment|/* CTL_HW */
value|\       mib[1] = 7;
comment|/* HW_PAGESIZE */
value|\       len = sizeof (size);						\       (void) __sysctl (mib, 2,&size,&len, NULL, 0);			\       mask = ~((long) size - 1);					\     }									\ 									\   page = (char *) (((long) addr)& mask);				\   end  = (char *) ((((long) (addr + TRAMPOLINE_SIZE))& mask) + size);	\ 									\
comment|/* 7 == PROT_READ | PROT_WRITE | PROT_EXEC */
value|\   (void) mprotect (page, end - page, 7);				\ }
end_define

end_unit

