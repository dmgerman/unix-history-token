begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Compaq as target machine.  NOT TESTED!    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tm-i386.h"
end_include

begin_comment
comment|/* Use the ATT assembler syntax.  */
end_comment

begin_include
include|#
directive|include
file|"tm-att386.h"
end_include

begin_comment
comment|/* By default, target has a 80387.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|""
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Di386 -Di80386 -Dunix"
end_define

begin_include
include|#
directive|include
file|"tm-i386.h"
end_include

begin_include
include|#
directive|include
file|"tm-att386.h"
end_include

end_unit

