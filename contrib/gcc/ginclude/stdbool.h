begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1998, 1999, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you include this header file into source    files compiled by GCC, this header file does not by itself cause    the resulting executable to be covered by the GNU General Public    License.  This exception does not however invalidate any other    reasons why the executable file might be covered by the GNU General    Public License.  */
end_comment

begin_comment
comment|/*  * ISO C Standard:  7.16  Boolean type and values<stdbool.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STDBOOL_H
end_ifndef

begin_define
define|#
directive|define
name|_STDBOOL_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_define
define|#
directive|define
name|bool
value|_Bool
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __cplusplus */
end_comment

begin_comment
comment|/* Supporting<stdbool.h> in C++ is a GCC extension.  */
end_comment

begin_define
define|#
directive|define
name|_Bool
value|bool
end_define

begin_define
define|#
directive|define
name|bool
value|bool
end_define

begin_define
define|#
directive|define
name|false
value|false
end_define

begin_define
define|#
directive|define
name|true
value|true
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_comment
comment|/* Signal that all the definitions are present.  */
end_comment

begin_define
define|#
directive|define
name|__bool_true_false_are_defined
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* stdbool.h */
end_comment

end_unit

