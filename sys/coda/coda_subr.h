begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   *             Coda: an Experimental Distributed File System  *                              Release 3.1  *   *           Copyright (c) 1987-1998 Carnegie Mellon University  *                          All Rights Reserved  *   * Permission  to  use, copy, modify and distribute this software and its  * documentation is hereby granted,  provided  that  both  the  copyright  * notice  and  this  permission  notice  appear  in  all  copies  of the  * software, derivative works or  modified  versions,  and  any  portions  * thereof, and that both notices appear in supporting documentation, and  * that credit is given to Carnegie Mellon University  in  all  documents  * and publicity pertaining to direct or indirect use of this code or its  * derivatives.  *   * CODA IS AN EXPERIMENTAL SOFTWARE SYSTEM AND IS  KNOWN  TO  HAVE  BUGS,  * SOME  OF  WHICH MAY HAVE SERIOUS CONSEQUENCES.  CARNEGIE MELLON ALLOWS  * FREE USE OF THIS SOFTWARE IN ITS "AS IS" CONDITION.   CARNEGIE  MELLON  * DISCLAIMS  ANY  LIABILITY  OF  ANY  KIND  FOR  ANY  DAMAGES WHATSOEVER  * RESULTING DIRECTLY OR INDIRECTLY FROM THE USE OF THIS SOFTWARE  OR  OF  * ANY DERIVATIVE WORK.  *   * Carnegie  Mellon  encourages  users  of  this  software  to return any  * improvements or extensions that  they  make,  and  to  grant  Carnegie  * Mellon the rights to redistribute these changes without encumbrance.  *   * 	@(#) src/sys/cfs/cfs_subr.h,v 1.1.1.1 1998/08/29 21:14:52 rvb Exp $   *  $Id: cfs_subr.h,v 1.2 1998/09/02 19:09:53 rvb Exp $  *   */
end_comment

begin_function_decl
name|struct
name|cnode
modifier|*
name|cfs_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfs_free
parameter_list|(
name|struct
name|cnode
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|cnode
modifier|*
name|cfs_find
parameter_list|(
name|ViceFid
modifier|*
name|fid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfs_flush
parameter_list|(
name|enum
name|dc_status
name|dcstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfs_testflush
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfs_checkunmounting
parameter_list|(
name|struct
name|mount
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfs_cacheprint
parameter_list|(
name|struct
name|mount
modifier|*
name|whoIam
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfs_debugon
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfs_debugoff
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfs_kill
parameter_list|(
name|struct
name|mount
modifier|*
name|whoIam
parameter_list|,
name|enum
name|dc_status
name|dcstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfs_save
parameter_list|(
name|struct
name|cnode
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cfs_unsave
parameter_list|(
name|struct
name|cnode
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

end_unit

