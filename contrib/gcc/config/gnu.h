begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration common to all targets running the GNU system.  */
end_comment

begin_comment
comment|/* Provide GCC options for standard feature-test macros.  */
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
value|"%{posix:-D_POSIX_SOURCE} %{bsd:-D_BSD_SOURCE}"
end_define

begin_comment
comment|/* Default C library spec.  Use -lbsd-compat for gcc -bsd.  */
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
value|"%{bsd:-lbsd-compat} %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}"
end_define

begin_comment
comment|/* Standard include directory.  In GNU, "/usr" is a four-letter word.  */
end_comment

begin_undef
undef|#
directive|undef
name|STANDARD_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_DIR
value|"/include"
end_define

begin_comment
comment|/* We have atexit.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* The system headers under GNU are C++-aware.  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

end_unit

