begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  *	$Id$  */
end_comment

begin_comment
comment|/*  *	Author: David B. Golub, Carnegie Mellon University  *	Date:	7/90  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DDB_DB_BREAK_H_
end_ifndef

begin_define
define|#
directive|define
name|_DDB_DB_BREAK_H_
end_define

begin_include
include|#
directive|include
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<machine/db_machdep.h>
end_include

begin_comment
comment|/*  * Breakpoint.  */
end_comment

begin_struct
struct|struct
name|db_breakpoint
block|{
name|vm_map_t
name|map
decl_stmt|;
comment|/* in this map */
name|db_addr_t
name|address
decl_stmt|;
comment|/* set here */
name|int
name|init_count
decl_stmt|;
comment|/* number of times to skip bkpt */
name|int
name|count
decl_stmt|;
comment|/* current count */
name|int
name|flags
decl_stmt|;
comment|/* flags: */
define|#
directive|define
name|BKPT_SINGLE_STEP
value|0x2
comment|/* to simulate single step */
define|#
directive|define
name|BKPT_TEMP
value|0x4
comment|/* temporary */
name|int
name|bkpt_inst
decl_stmt|;
comment|/* saved instruction at bkpt */
name|struct
name|db_breakpoint
modifier|*
name|link
decl_stmt|;
comment|/* link in in-use or free chain */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|db_breakpoint
modifier|*
name|db_breakpoint_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|db_breakpoint_t
name|db_find_breakpoint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|db_breakpoint_t
name|db_find_breakpoint_here
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_set_breakpoints
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_clear_breakpoints
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|db_breakpoint_t
name|db_set_temp_breakpoint
parameter_list|(
comment|/* db_addr_t addr */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_delete_temp_breakpoint
parameter_list|(
comment|/* db_breakpoint_t bkpt */
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|_DDB_DB_BREAK_H_
end_endif

end_unit

