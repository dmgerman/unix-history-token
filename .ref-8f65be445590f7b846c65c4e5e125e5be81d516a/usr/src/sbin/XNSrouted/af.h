begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)af.h	5.1 (Berkeley) 6/4/85 (routed/af.h)  *  *	@(#)af.h	5.2 (Berkeley) %G%  */
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
comment|/* tells if address for host or net */
name|int
function_decl|(
modifier|*
name|af_ishost
function_decl|)
parameter_list|()
function_decl|;
comment|/* tells if address is valid */
name|int
function_decl|(
modifier|*
name|af_canon
function_decl|)
parameter_list|()
function_decl|;
comment|/* canonicalize address for compares */
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
index|[
name|AF_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table proper */
end_comment

end_unit

