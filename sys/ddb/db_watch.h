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
name|_DDB_DB_WATCH_H_
end_ifndef

begin_define
define|#
directive|define
name|_DDB_DB_WATCH_H_
end_define

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DDB_DB_WATCH_H_ */
end_comment

end_unit

