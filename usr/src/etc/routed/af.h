begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)af.h	5.6 (Berkeley) 6/18/88  */
end_comment

begin_comment
comment|/*  * Routing table management daemon.  */
end_comment

begin_comment
comment|/*  * Per address family routines.  */
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
comment|/* returns keys based on address */
name|int
function_decl|(
modifier|*
name|af_netmatch
function_decl|)
parameter_list|()
function_decl|;
comment|/* verifies net # matching */
name|int
function_decl|(
modifier|*
name|af_output
function_decl|)
parameter_list|()
function_decl|;
comment|/* interprets address for sending */
name|int
function_decl|(
modifier|*
name|af_portmatch
function_decl|)
parameter_list|()
function_decl|;
comment|/* packet from some other router? */
name|int
function_decl|(
modifier|*
name|af_portcheck
function_decl|)
parameter_list|()
function_decl|;
comment|/* packet from privileged peer? */
name|int
function_decl|(
modifier|*
name|af_checkhost
function_decl|)
parameter_list|()
function_decl|;
comment|/* tells if address is valid */
name|int
function_decl|(
modifier|*
name|af_rtflags
function_decl|)
parameter_list|()
function_decl|;
comment|/* get flags for route (host or net) */
name|int
function_decl|(
modifier|*
name|af_sendroute
function_decl|)
parameter_list|()
function_decl|;
comment|/* check bounds of subnet broadcast */
name|int
function_decl|(
modifier|*
name|af_canon
function_decl|)
parameter_list|()
function_decl|;
comment|/* canonicalize address for compares */
name|char
modifier|*
function_decl|(
modifier|*
name|af_format
function_decl|)
parameter_list|()
function_decl|;
comment|/* convert address to string */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure returned by af_hash routines.  */
end_comment

begin_struct
struct|struct
name|afhash
block|{
name|u_int
name|afh_hosthash
decl_stmt|;
comment|/* host based hash */
name|u_int
name|afh_nethash
decl_stmt|;
comment|/* network based hash */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|afswitch
name|afswitch
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table proper */
end_comment

begin_decl_stmt
name|int
name|af_max
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of entries in table */
end_comment

end_unit

