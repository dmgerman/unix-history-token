begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for interface to indent.c    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_struct
struct|struct
name|position
block|{
name|int
name|bufpos
decl_stmt|;
name|int
name|hpos
decl_stmt|;
name|int
name|vpos
decl_stmt|;
name|int
name|prevhpos
decl_stmt|;
name|int
name|contin
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|position
modifier|*
name|compute_motion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|position
modifier|*
name|vmotion
parameter_list|()
function_decl|;
end_function_decl

end_unit

