begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for PowerPC NetBSD systems.    Copyright 2001 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Under NetBSD, the normal location of the various *crt*.o files is    the /usr/lib directory [from config/netbsd.h].  */
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
comment|/* FIXME: Should this macro be treated the same as for the other    spec's?  */
end_comment

begin_comment
comment|/* NOTE: -dc and -dp are equivalent yet NetBSD's CC passes both both!    NetBSD's CC also passes -O1 but we can skip that.  NetBSD explictly    sets ``-e _start'', since LD knows this, skip it.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SHLIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SHLIB_SPEC
value|"\ %{shared:-shared} \ %{!shared: %{static:-dc -dp -static}} \ %{!shared: %{!static:-dc -dp}} \ "
end_define

begin_comment
comment|/* Override the defaults.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_DEFAULT_SPEC
value|"%(lib_netbsd)"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_DEFAULT_SPEC
value|"%(startfile_netbsd)"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_DEFAULT_SPEC
value|"%(endfile_netbsd)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_START_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_START_DEFAULT_SPEC
value|"%(link_start_netbsd)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_OS_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_OS_DEFAULT_SPEC
value|"%(link_os_netbsd)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_OS_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_OS_DEFAULT_SPEC
value|"%(cpp_os_netbsd)"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (PowerPC NetBSD/ELF)");
end_define

begin_comment
comment|/* For backward compatibility, we must continue to use the AIX    structure return convention.  */
end_comment

begin_undef
undef|#
directive|undef
name|DRAFT_V4_STRUCT_RET
end_undef

begin_define
define|#
directive|define
name|DRAFT_V4_STRUCT_RET
value|1
end_define

end_unit

