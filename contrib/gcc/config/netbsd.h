begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* NETBSD_NATIVE is defined when gcc is integrated into the NetBSD    source tree so it can be configured appropriately without using    the GNU configure/build mechanism. */
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
comment|/* Provide a CPP_SPEC appropriate for NetBSD.  Currently we just deal with    the GCC option `-posix'.  */
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
value|"%(cpp_cpu) %{posix:-D_POSIX_SOURCE}"
end_define

begin_comment
comment|/* Provide a LIB_SPEC appropriate for NetBSD.  Just select the appropriate    libc, depending on whether we're doing profiling; if `-posix' is specified,    link against the appropriate libposix first.  Don't include libc when    linking a shared library.  */
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
define|\
value|"%{posix:			\      %{!p:			\        %{!pg:-lposix}}		\      %{p:-lposix_p}		\      %{pg:-lposix_p}}		\    %{!shared:			\      %{!symbolic:		\        %{!p:			\ 	 %{!pg:-lc}}		\        %{p:-lc_p}		\        %{pg:-lc_p}}}"
end_define

begin_comment
comment|/* Provide a LIBGCC_SPEC appropriate for NetBSD.  We also want to exclude    libgcc with -symbolic.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|NETBSD_NATIVE
end_ifdef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
define|\
value|"%{!symbolic:			\      %{!shared:			\        %{!p:			\ 	 %{!pg: -lgcc}}}		\      %{shared: -lgcc_pic}	\      %{p: -lgcc_p}		\      %{pg: -lgcc_p}}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBGCC_SPEC
value|"%{!shared:%{!symbolic: -lgcc}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* Allow #sccs in preprocessor.  */
end_comment

begin_undef
undef|#
directive|undef
name|SCCS_DIRECTIVE
end_undef

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
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
end_define

end_unit

