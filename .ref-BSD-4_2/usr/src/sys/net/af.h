begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	af.h	6.1	83/07/29	*/
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

