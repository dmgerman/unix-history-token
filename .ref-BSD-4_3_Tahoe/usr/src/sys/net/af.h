begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)af.h	7.3 (Berkeley) 6/27/88  */
end_comment

begin_comment
comment|/*  * Address family routines,  * used in handling generic sockaddr structures.  *  * Hash routine is called  *	af_hash(addr, h);  *	struct sockaddr *addr; struct afhash *h;  * producing an afhash structure for addr.  *  * Netmatch routine is called  *	af_netmatch(addr1, addr2);  * where addr1 and addr2 are sockaddr *.  Returns 1 if network  * values match, 0 otherwise.  */
end_comment

begin_struct
struct|struct
name|afswitch
block|{
name|int
function_decl|(
modifier|*
name|af_hash
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|af_netmatch
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|afhash
block|{
name|u_int
name|afh_hosthash
decl_stmt|;
name|u_int
name|afh_nethash
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|afswitch
name|afswitch
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

