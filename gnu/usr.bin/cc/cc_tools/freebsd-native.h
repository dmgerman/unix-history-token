begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: freebsd-native.h,v 1.1 1999/04/28 18:48:05 obrien Exp $ */
end_comment

begin_comment
comment|/* FREEBSD_NATIVE is defined when gcc is integrated into the FreeBSD    source tree so it can be configured appropriately without using    the GNU configure/build mechanism. */
end_comment

begin_comment
comment|/* Look for the include files in the system-defined places.  */
end_comment

begin_define
define|#
directive|define
name|GPLUSPLUS_INCLUDE_DIR
value|"/usr/include/g++"
end_define

begin_define
define|#
directive|define
name|GCC_INCLUDE_DIR
value|"/usr/include"
end_define

begin_comment
comment|/* Now that GCC knows what the include path applies to, put the G++ one first.    C++ can now have include files that override the default C ones.  */
end_comment

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
value|{						\     { GPLUSPLUS_INCLUDE_DIR, "C++", 1, 1 },	\     { GCC_INCLUDE_DIR, "GCC", 0, 0 },		\     { 0, 0, 0, 0 }				\   }
end_define

begin_comment
comment|/* Under FreeBSD, the normal location of the compiler back ends is the    /usr/libexec directory.  */
end_comment

begin_undef
undef|#
directive|undef
name|STANDARD_EXEC_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|TOOLDIR_BASE_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_define
define|#
directive|define
name|STANDARD_EXEC_PREFIX
value|"/usr/libexec/"
end_define

begin_define
define|#
directive|define
name|TOOLDIR_BASE_PREFIX
value|"/usr/libexec/"
end_define

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/usr/libexec/"
end_define

begin_comment
comment|/* Under FreeBSD, the normal location of the various *crt*.o files is the    /usr/lib directory.  */
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

begin_comment
comment|/* FreeBSD is 4.4BSD derived */
end_comment

begin_define
define|#
directive|define
name|bsd4_4
end_define

begin_comment
comment|/* Tell gcc to locate libgcc.a for us according to the -m rules.  */
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
value|"%{!shared:%{!pthread:%{!kthread:libgcc.a%s}}%{pthread|kthread:libgcc_r.a%s}}"
end_define

end_unit

