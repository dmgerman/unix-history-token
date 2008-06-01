begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common VxWorks target definitions for GNU compiler.    Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.    Contributed by Wind River Systems.    Rewritten by CodeSourcery, LLC.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* In kernel mode, VxWorks provides all the libraries itself, as well as    the functionality of startup files, etc.  In RTP mode, it behaves more    like a traditional Unix, with more external files.  Most of our specs    must be aware of the difference.  */
end_comment

begin_comment
comment|/* The directory containing the VxWorks target headers.  */
end_comment

begin_define
define|#
directive|define
name|VXWORKS_TARGET_DIR
value|"/home/tornado/base6/target"
end_define

begin_comment
comment|/* Since we provide a default -isystem, expand -isystem on the command    line early.  */
end_comment

begin_undef
undef|#
directive|undef
name|VXWORKS_ADDITIONAL_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|VXWORKS_ADDITIONAL_CPP_SPEC
value|" 					\  %{!nostdinc:%{isystem*}}						\  %{mrtp: -D__RTP__=1							\ 	 %{!nostdinc:-isystem " VXWORKS_TARGET_DIR "/usr/h}}		\  %{!mrtp:-D_WRS_KERNEL=1						\ 	 %{!nostdinc:-isystem " VXWORKS_TARGET_DIR "/h}}"
end_define

begin_comment
comment|/* The references to __init and __fini will be satisfied by    libc_internal.a.  */
end_comment

begin_undef
undef|#
directive|undef
name|VXWORKS_LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|VXWORKS_LIB_SPEC
define|\
value|"%{mrtp:%{shared:-u " USER_LABEL_PREFIX "__init -u " USER_LABEL_PREFIX "__fini} \ 	%{!shared:%{non-static:-u " USER_LABEL_PREFIX "_STI__6__rtld -ldl} \ 		  --start-group -lc -lgcc -lc_internal -lnet -ldsi	\ 		  --end-group}}"
end_define

begin_comment
comment|/* The no-op spec for "-shared" below is present because otherwise GCC    will treat it as an unrecognized option.  */
end_comment

begin_undef
undef|#
directive|undef
name|VXWORKS_LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|VXWORKS_LINK_SPEC
define|\
value|"%{!mrtp:-r}						\  %{!shared:						\    %{mrtp:-q %{h*}					\           %{R*} %{!Wl,-T*: %{!T*: %(link_start) }}	\           %(link_target) %(link_os)}}			\  %{v:-V}						\  %{shared:-shared}					\  %{Bstatic:-Bstatic}					\  %{Bdynamic:-Bdynamic}					\  %{!Xbind-lazy:-z now}					\  %{Xbind-now:%{Xbind-lazy:				\    %e-Xbind-now and -Xbind-lazy are incompatible}}	\  %{mrtp:%{!shared:%{!non-static:-static}		\  		  %{non-static:--force-dynamic --export-dynamic}}}"
end_define

begin_comment
comment|/* For VxWorks, the system provides libc_internal.a.  This is a superset    of libgcc.a; we want to use it.  Make sure not to dynamically export    any of its symbols, though.  Always look for libgcc.a first so that    we get the latest versions of the GNU intrinsics during our builds.  */
end_comment

begin_undef
undef|#
directive|undef
name|VXWORKS_LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|VXWORKS_LIBGCC_SPEC
define|\
value|"-lgcc %{mrtp:--exclude-libs=libc_internal,libgcc -lc_internal}"
end_define

begin_undef
undef|#
directive|undef
name|VXWORKS_STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|VXWORKS_STARTFILE_SPEC
value|"%{mrtp:%{!shared:crt0.o%s}}"
end_define

begin_define
define|#
directive|define
name|VXWORKS_ENDFILE_SPEC
value|""
end_define

begin_comment
comment|/* We can use .ctors/.dtors sections only in RTP mode.    Unfortunately this must be an integer constant expression;    fix up in override_options.  */
end_comment

begin_undef
undef|#
directive|undef
name|VXWORKS_OVERRIDE_OPTIONS
end_undef

begin_define
define|#
directive|define
name|VXWORKS_OVERRIDE_OPTIONS
value|do { \   targetm.have_ctors_dtors = TARGET_VXWORKS_RTP; \ } while (0)
end_define

begin_comment
comment|/* The VxWorks runtime uses a clever trick to get the sentinel entry    (-1) inserted at the beginning of the .ctors segment.  This trick    will not work if we ever generate any entries in plain .ctors    sections; we must always use .ctors.PRIORITY.  */
end_comment

begin_define
define|#
directive|define
name|ALWAYS_NUMBER_CTORS_SECTIONS
value|1
end_define

begin_comment
comment|/* The name of the symbol for the table of GOTs in a particular    RTP.  */
end_comment

begin_define
define|#
directive|define
name|VXWORKS_GOTT_BASE
value|"__GOTT_BASE__"
end_define

begin_comment
comment|/* The name of the symbol for the index into the table of GOTs for the    GOT associated with the current shared library.  */
end_comment

begin_define
define|#
directive|define
name|VXWORKS_GOTT_INDEX
value|"__GOTT_INDEX__"
end_define

begin_define
define|#
directive|define
name|VXWORKS_KIND
value|VXWORKS_KIND_NORMAL
end_define

end_unit

