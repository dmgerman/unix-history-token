begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define constants for communication with parse.y.    Copyright (C) 1987 Free Software Foundation, Inc.    Hacked by Michael Tiemann (tiemann@mcc.com)  This file is part of GNU CC.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU CC General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU CC, but only under the conditions described in the GNU CC General Public License.   A copy of this license is supposed to have been given to you along with GNU CC so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_enum
enum|enum
name|rid
block|{
name|RID_UNUSED
block|,
name|RID_INT
block|,
name|RID_CHAR
block|,
name|RID_FLOAT
block|,
name|RID_DOUBLE
block|,
name|RID_VOID
block|,
name|RID_UNUSED1
block|,
comment|/* C++ extension */
name|RID_CLASS
block|,
name|RID_RECORD
block|,
name|RID_UNION
block|,
name|RID_ENUM
block|,
name|RID_LONGLONG
block|,
name|RID_UNSIGNED
block|,
name|RID_SHORT
block|,
name|RID_LONG
block|,
name|RID_AUTO
block|,
name|RID_STATIC
block|,
name|RID_EXTERN
block|,
name|RID_REGISTER
block|,
name|RID_TYPEDEF
block|,
name|RID_SIGNED
block|,
name|RID_CONST
block|,
name|RID_VOLATILE
block|,
name|RID_INLINE
block|,
name|RID_NOALIAS
block|,
comment|/* extensions */
name|RID_FRIEND
block|,
name|RID_VIRTUAL
block|,
name|RID_EXCEPTION
block|,
name|RID_RAISES
block|,
name|RID_MAX
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|RID_FIRST_MODIFIER
value|RID_UNSIGNED
end_define

end_unit

