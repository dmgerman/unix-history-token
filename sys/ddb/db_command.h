begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  *	$Id$  */
end_comment

begin_comment
comment|/*  *	Author: David B. Golub, Carnegie Mellon University  *	Date:	7/90  */
end_comment

begin_comment
comment|/*  * Command loop declarations.  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|<machine/db_machdep.h>
end_include

begin_function_decl
specifier|extern
name|void
name|db_command_loop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_skip_to_eol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_error
parameter_list|(
comment|/* char * */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* report error */
end_comment

begin_decl_stmt
specifier|extern
name|db_addr_t
name|db_dot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current location */
end_comment

begin_decl_stmt
specifier|extern
name|db_addr_t
name|db_last_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last explicit address typed */
end_comment

begin_decl_stmt
specifier|extern
name|db_addr_t
name|db_prev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last address examined 					   or written */
end_comment

begin_decl_stmt
specifier|extern
name|db_addr_t
name|db_next
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next address to be examined 					   or written */
end_comment

end_unit

