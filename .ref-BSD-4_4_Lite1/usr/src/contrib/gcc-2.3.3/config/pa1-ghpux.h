begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for HP PA-RISC 1.1    Copyright (C) 1991 Free Software Foundation, Inc.    Contributed by Tim Moore (moore@defmacro.cs.utah.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This is the same as pa-hpux.h, except that we generate snake code by    default and we have to deal with assembler weirdness. */
end_comment

begin_define
define|#
directive|define
name|HP_FP_ARG_DESCRIPTOR_REVERSED
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|1
end_define

begin_comment
comment|/* TARGET_SNAKE */
end_comment

begin_include
include|#
directive|include
file|"pa-ghpux.h"
end_include

end_unit

