begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * 	Author: David B. Golub, Carnegie Mellon University  *	Date:	10/90  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DDB_DB_WATCH_
end_ifndef

begin_define
define|#
directive|define
name|_DDB_DB_WATCH_
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
comment|/*  * Watchpoint.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|db_watchpoint
block|{
name|vm_map_t
name|map
decl_stmt|;
comment|/* in this map */
name|db_addr_t
name|loaddr
decl_stmt|;
comment|/* from this address */
name|db_addr_t
name|hiaddr
decl_stmt|;
comment|/* to this address */
name|struct
name|db_watchpoint
modifier|*
name|link
decl_stmt|;
comment|/* link in in-use or free chain */
block|}
typedef|*
name|db_watchpoint_t
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|boolean_t
name|db_find_watchpoint
parameter_list|(
comment|/* vm_map_t map, db_addr_t addr, 				     db_regs_t *regs */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_set_watchpoint
parameter_list|(
comment|/* vm_map_t map, db_addr_t addr, vm_size_t size */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_delete_watchpoint
parameter_list|(
comment|/* vm_map_t map, db_addr_t addr */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|db_list_watchpoints
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|_DDB_DB_WATCH_
end_endif

end_unit

