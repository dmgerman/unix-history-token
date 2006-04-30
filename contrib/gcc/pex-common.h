begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Utilities to execute a program in a subprocess (possibly linked by pipes    with other subprocesses), and wait for it.  Shared logic.    Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2003    Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEX_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|PEX_COMMON_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_define
define|#
directive|define
name|install_error_msg
value|"installation problem, cannot exec `%s'"
end_define

begin_comment
comment|/* stdin file number.  */
end_comment

begin_define
define|#
directive|define
name|STDIN_FILE_NO
value|0
end_define

begin_comment
comment|/* stdout file number.  */
end_comment

begin_define
define|#
directive|define
name|STDOUT_FILE_NO
value|1
end_define

begin_comment
comment|/* value of `pipe': port index for reading.  */
end_comment

begin_define
define|#
directive|define
name|READ_PORT
value|0
end_define

begin_comment
comment|/* value of `pipe': port index for writing.  */
end_comment

begin_define
define|#
directive|define
name|WRITE_PORT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

