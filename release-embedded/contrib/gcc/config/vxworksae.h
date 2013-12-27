begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common VxWorks AE target definitions for GNU compiler.    Copyright (C) 2004, 2005 Free Software Foundation, Inc.    Contributed by CodeSourcery, LLC.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This header should be included after including vx-common.h.  */
end_comment

begin_comment
comment|/* Most of the definitions below this point are versions of the    vxworks.h definitions, without the -mrtp bits.  */
end_comment

begin_comment
comment|/* The directory containing the VxWorks AE target headers.  */
end_comment

begin_define
define|#
directive|define
name|VXWORKSAE_TARGET_DIR
define|\
value|"/home/tornado/vxworks-ae/latest/target"
end_define

begin_comment
comment|/* Include target/vThreads/h or target/h (depending on the compilation    mode), and then target/val/h (in either mode).  The macros defined    are in the user's namespace, but the VxWorks headers require    them.  */
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
value|"					\  %{!nostdinc:%{isystem*}}						\  %{mvthreads:-DVTHREADS=1						\ 	 %{!nostdinc:-isystem " VXWORKSAE_TARGET_DIR "/vThreads/h}}	\  %{!mvthreads:-DAE653_BUILD=1						\ 	 %{!nostdinc:-isystem " VXWORKSAE_TARGET_DIR "/h}}		\  %{!nostdinc:-isystem " VXWORKSAE_TARGET_DIR "/val/h}"
end_define

begin_undef
undef|#
directive|undef
name|VXWORKS_LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|VXWORKS_LIB_SPEC
value|""
end_define

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
value|"-r %{v:-V}"
end_define

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
value|"-lgcc"
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
value|""
end_define

begin_define
define|#
directive|define
name|VXWORKS_KIND
value|VXWORKS_KIND_AE
end_define

end_unit

