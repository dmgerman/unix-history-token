begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for m68k binaries under LynxOS.    Copyright (C) 1990, 1991, 1992 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
end_define

begin_define
define|#
directive|define
name|N_SHARED_LIB
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|TARGET_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_m68k
end_define

begin_define
define|#
directive|define
name|MY
parameter_list|(
name|OP
parameter_list|)
value|CAT(m68klynx_aout_,OP)
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-m68k-lynx"
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"libbfd.h"
end_include

begin_include
include|#
directive|include
file|"libaout.h"
end_include

begin_include
include|#
directive|include
file|"aout/aout64.h"
end_include

begin_define
define|#
directive|define
name|TARGET_IS_BIG_ENDIAN_P
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LYNX_CORE
end_ifdef

begin_function_decl
name|char
modifier|*
name|lynx_core_file_failing_command
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lynx_core_file_failing_signal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|boolean
name|lynx_core_file_matches_executable_p
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|bfd_target
modifier|*
name|lynx_core_file_p
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MY_core_file_failing_command
value|lynx_core_file_failing_command
end_define

begin_define
define|#
directive|define
name|MY_core_file_failing_signal
value|lynx_core_file_failing_signal
end_define

begin_define
define|#
directive|define
name|MY_core_file_matches_executable_p
value|lynx_core_file_matches_executable_p
end_define

begin_define
define|#
directive|define
name|MY_core_file_p
value|lynx_core_file_p
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LYNX_CORE */
end_comment

begin_include
include|#
directive|include
file|"aout-target.h"
end_include

end_unit

