begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* ostack.h */
end_comment

begin_comment
comment|/* Definitions for Ghostscript operand stack */
end_comment

begin_comment
comment|/********************************  * NOTE: on MS-DOS systems, the operand stack is stored in the data segment.  * This leads to large performance gains, at the expense of having to swap  * the stack explicitly when switching contexts or handling segment under-  * or overflow (none of which are implemented yet!).  ********************************/
end_comment

begin_typedef
typedef|typedef
name|ref
name|_ds
modifier|*
name|os_ptr
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|os_ptr
name|osbot
decl_stmt|,
name|osp
decl_stmt|,
name|ostop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macro to ensure enough room on the operand stack */
end_comment

begin_define
define|#
directive|define
name|check_ostack
parameter_list|(
name|n
parameter_list|)
define|\
value|if ( ostop - osp< (n) ) return e_stackoverflow
end_define

end_unit

