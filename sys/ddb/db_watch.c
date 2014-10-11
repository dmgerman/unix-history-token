begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * 	Author: Richard P. Draves, Carnegie Mellon University  *	Date:	10/90  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<ddb/ddb.h>
end_include

begin_include
include|#
directive|include
file|<ddb/db_watch.h>
end_include

begin_comment
comment|/*  * Watchpoints.  */
end_comment

begin_decl_stmt
specifier|static
name|boolean_t
name|db_watchpoints_inserted
init|=
name|TRUE
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NWATCHPOINTS
value|100
end_define

begin_decl_stmt
specifier|static
name|struct
name|db_watchpoint
name|db_watch_table
index|[
name|NWATCHPOINTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|db_watchpoint_t
name|db_next_free_watchpoint
init|=
operator|&
name|db_watch_table
index|[
literal|0
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|db_watchpoint_t
name|db_free_watchpoints
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|db_watchpoint_t
name|db_watchpoint_list
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|db_watchpoint_t
name|db_watchpoint_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|db_watchpoint_free
parameter_list|(
name|db_watchpoint_t
name|watch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|db_delete_watchpoint
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
name|db_addr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|notused
end_ifdef

begin_function_decl
specifier|static
name|boolean_t
name|db_find_watchpoint
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
name|db_addr_t
name|addr
parameter_list|,
name|db_regs_t
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|void
name|db_list_watchpoints
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|db_set_watchpoint
parameter_list|(
name|vm_map_t
name|map
parameter_list|,
name|db_addr_t
name|addr
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|db_watchpoint_t
name|db_watchpoint_alloc
parameter_list|()
block|{
specifier|register
name|db_watchpoint_t
name|watch
decl_stmt|;
if|if
condition|(
operator|(
name|watch
operator|=
name|db_free_watchpoints
operator|)
operator|!=
literal|0
condition|)
block|{
name|db_free_watchpoints
operator|=
name|watch
operator|->
name|link
expr_stmt|;
return|return
operator|(
name|watch
operator|)
return|;
block|}
if|if
condition|(
name|db_next_free_watchpoint
operator|==
operator|&
name|db_watch_table
index|[
name|NWATCHPOINTS
index|]
condition|)
block|{
name|db_printf
argument_list|(
literal|"All watchpoints used.\n"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
name|watch
operator|=
name|db_next_free_watchpoint
expr_stmt|;
name|db_next_free_watchpoint
operator|++
expr_stmt|;
return|return
operator|(
name|watch
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|db_watchpoint_free
parameter_list|(
name|watch
parameter_list|)
specifier|register
name|db_watchpoint_t
name|watch
decl_stmt|;
block|{
name|watch
operator|->
name|link
operator|=
name|db_free_watchpoints
expr_stmt|;
name|db_free_watchpoints
operator|=
name|watch
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|db_set_watchpoint
parameter_list|(
name|map
parameter_list|,
name|addr
parameter_list|,
name|size
parameter_list|)
name|vm_map_t
name|map
decl_stmt|;
name|db_addr_t
name|addr
decl_stmt|;
name|vm_size_t
name|size
decl_stmt|;
block|{
specifier|register
name|db_watchpoint_t
name|watch
decl_stmt|;
if|if
condition|(
name|map
operator|==
name|NULL
condition|)
block|{
name|db_printf
argument_list|(
literal|"No map.\n"
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* 	 *	Should we do anything fancy with overlapping regions? 	 */
for|for
control|(
name|watch
operator|=
name|db_watchpoint_list
init|;
name|watch
operator|!=
literal|0
condition|;
name|watch
operator|=
name|watch
operator|->
name|link
control|)
if|if
condition|(
name|db_map_equal
argument_list|(
name|watch
operator|->
name|map
argument_list|,
name|map
argument_list|)
operator|&&
operator|(
name|watch
operator|->
name|loaddr
operator|==
name|addr
operator|)
operator|&&
operator|(
name|watch
operator|->
name|hiaddr
operator|==
name|addr
operator|+
name|size
operator|)
condition|)
block|{
name|db_printf
argument_list|(
literal|"Already set.\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|watch
operator|=
name|db_watchpoint_alloc
argument_list|()
expr_stmt|;
if|if
condition|(
name|watch
operator|==
literal|0
condition|)
block|{
name|db_printf
argument_list|(
literal|"Too many watchpoints.\n"
argument_list|)
expr_stmt|;
return|return;
block|}
name|watch
operator|->
name|map
operator|=
name|map
expr_stmt|;
name|watch
operator|->
name|loaddr
operator|=
name|addr
expr_stmt|;
name|watch
operator|->
name|hiaddr
operator|=
name|addr
operator|+
name|size
expr_stmt|;
name|watch
operator|->
name|link
operator|=
name|db_watchpoint_list
expr_stmt|;
name|db_watchpoint_list
operator|=
name|watch
expr_stmt|;
name|db_watchpoints_inserted
operator|=
name|FALSE
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|db_delete_watchpoint
parameter_list|(
name|map
parameter_list|,
name|addr
parameter_list|)
name|vm_map_t
name|map
decl_stmt|;
name|db_addr_t
name|addr
decl_stmt|;
block|{
specifier|register
name|db_watchpoint_t
name|watch
decl_stmt|;
specifier|register
name|db_watchpoint_t
modifier|*
name|prev
decl_stmt|;
for|for
control|(
name|prev
operator|=
operator|&
name|db_watchpoint_list
init|;
operator|(
name|watch
operator|=
operator|*
name|prev
operator|)
operator|!=
literal|0
condition|;
name|prev
operator|=
operator|&
name|watch
operator|->
name|link
control|)
if|if
condition|(
name|db_map_equal
argument_list|(
name|watch
operator|->
name|map
argument_list|,
name|map
argument_list|)
operator|&&
operator|(
name|watch
operator|->
name|loaddr
operator|<=
name|addr
operator|)
operator|&&
operator|(
name|addr
operator|<
name|watch
operator|->
name|hiaddr
operator|)
condition|)
block|{
operator|*
name|prev
operator|=
name|watch
operator|->
name|link
expr_stmt|;
name|db_watchpoint_free
argument_list|(
name|watch
argument_list|)
expr_stmt|;
return|return;
block|}
name|db_printf
argument_list|(
literal|"Not set.\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|db_list_watchpoints
parameter_list|()
block|{
specifier|register
name|db_watchpoint_t
name|watch
decl_stmt|;
if|if
condition|(
name|db_watchpoint_list
operator|==
literal|0
condition|)
block|{
name|db_printf
argument_list|(
literal|"No watchpoints set\n"
argument_list|)
expr_stmt|;
return|return;
block|}
ifdef|#
directive|ifdef
name|__LP64__
name|db_printf
argument_list|(
literal|" Map                Address          Size\n"
argument_list|)
expr_stmt|;
else|#
directive|else
name|db_printf
argument_list|(
literal|" Map        Address  Size\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|watch
operator|=
name|db_watchpoint_list
init|;
name|watch
operator|!=
literal|0
condition|;
name|watch
operator|=
name|watch
operator|->
name|link
control|)
ifdef|#
directive|ifdef
name|__LP64__
name|db_printf
argument_list|(
literal|"%s%16p  %16lx  %lx\n"
argument_list|,
else|#
directive|else
argument|db_printf(
literal|"%s%8p  %8lx  %lx\n"
argument|,
endif|#
directive|endif
argument|db_map_current(watch->map) ?
literal|"*"
argument|:
literal|" "
argument|, 		      (void *)watch->map, (long)watch->loaddr, 		      (long)watch->hiaddr - (long)watch->loaddr); }
comment|/* Delete watchpoint */
comment|/*ARGSUSED*/
argument|void db_deletewatch_cmd(addr, have_addr, count, modif) 	db_expr_t	addr; 	boolean_t	have_addr; 	db_expr_t	count; 	char *		modif; { 	db_delete_watchpoint(db_map_addr(addr), addr); }
comment|/* Set watchpoint */
comment|/*ARGSUSED*/
argument|void db_watchpoint_cmd(addr, have_addr, count, modif) 	db_expr_t	addr; 	boolean_t	have_addr; 	db_expr_t	count; 	char *		modif; { 	vm_size_t	size; 	db_expr_t	value;  	if (db_expression(&value)) 	    size = (vm_size_t) value; 	else 	    size =
literal|4
argument|; 	db_skip_to_eol();  	db_set_watchpoint(db_map_addr(addr), addr, size); }
comment|/*  * At least one non-optional show-command must be implemented using  * DB_SHOW_COMMAND() so that db_show_cmd_set gets created.  Here is one.  */
argument|DB_SHOW_COMMAND(watches, db_listwatch_cmd) { 	db_list_watchpoints(); 	db_md_list_watchpoints(); }  void db_set_watchpoints() { 	register db_watchpoint_t	watch;  	if (!db_watchpoints_inserted) { 	    for (watch = db_watchpoint_list; 	         watch !=
literal|0
argument|; 	         watch = watch->link) 		pmap_protect(watch->map->pmap, 			     trunc_page(watch->loaddr), 			     round_page(watch->hiaddr), 			     VM_PROT_READ);  	    db_watchpoints_inserted = TRUE; 	} }  void db_clear_watchpoints() { 	db_watchpoints_inserted = FALSE; }
ifdef|#
directive|ifdef
name|notused
argument|static boolean_t db_find_watchpoint(map, addr, regs) 	vm_map_t	map; 	db_addr_t	addr; 	db_regs_t	*regs; { 	register db_watchpoint_t watch; 	db_watchpoint_t found =
literal|0
argument|;  	for (watch = db_watchpoint_list; 	     watch !=
literal|0
argument|; 	     watch = watch->link) 	    if (db_map_equal(watch->map, map)) { 		if ((watch->loaddr<= addr)&& 		    (addr< watch->hiaddr)) 		    return (TRUE); 		else if ((trunc_page(watch->loaddr)<= addr)&& 			 (addr< round_page(watch->hiaddr))) 		    found = watch; 	    }
comment|/* 	 *	We didn't hit exactly on a watchpoint, but we are 	 *	in a protected region.  We want to single-step 	 *	and then re-protect. 	 */
argument|if (found) { 	    db_watchpoints_inserted = FALSE; 	    db_single_step(regs); 	}  	return (FALSE); }
endif|#
directive|endif
comment|/* Delete hardware watchpoint */
comment|/*ARGSUSED*/
argument|void db_deletehwatch_cmd(addr, have_addr, count, modif) 	db_expr_t	addr; 	boolean_t	have_addr; 	db_expr_t	count; 	char *		modif; { 	int rc;  	if (count<
literal|0
argument|) 		count =
literal|4
argument|;  	rc = db_md_clr_watchpoint(addr, count); 	if (rc<
literal|0
argument|) 		db_printf(
literal|"hardware watchpoint could not be deleted\n"
argument|); }
comment|/* Set hardware watchpoint */
comment|/*ARGSUSED*/
argument|void db_hwatchpoint_cmd(addr, have_addr, count, modif) 	db_expr_t	addr; 	boolean_t	have_addr; 	db_expr_t	count; 	char *		modif; { 	int rc;  	if (count<
literal|0
argument|) 		count =
literal|4
argument|;  	rc = db_md_set_watchpoint(addr, count); 	if (rc<
literal|0
argument|) 		db_printf(
literal|"hardware watchpoint could not be set\n"
argument|); }
end_function

end_unit

