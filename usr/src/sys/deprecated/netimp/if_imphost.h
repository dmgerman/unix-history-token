begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_imphost.h	4.1	82/02/06	*/
end_comment

begin_comment
comment|/*  * Host structure used with IMP's.  * Used to hold outgoing packets which  * would exceed allowed RFNM count.  *  * These structures are packed into  * mbuf's and kept as small as possible.  */
end_comment

begin_struct
struct|struct
name|host
block|{
name|struct
name|mbuf
modifier|*
name|h_q
decl_stmt|;
comment|/* holding queue */
name|struct
name|in_addr
name|h_addr
decl_stmt|;
comment|/* host's address */
name|u_short
name|h_status
decl_stmt|;
comment|/* host status */
name|u_char
name|h_rfnm
decl_stmt|;
comment|/* # outstanding rfnm's */
name|u_char
name|h_refcnt
decl_stmt|;
comment|/* reference count */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HOSTS_DOWN
value|0
end_define

begin_comment
comment|/* host believed down */
end_comment

begin_define
define|#
directive|define
name|HOSTS_UP
value|128
end_define

begin_comment
comment|/* host up */
end_comment

begin_comment
comment|/*  * Host structures, as seen inside an mbuf.  * Hashing on the host address is used to  * select an index into the first mbuf.  Collisions  * are then resolved by searching successive  * mbuf's at the same index.  Reclamation is done  * automatically at the time a structure is free'd.  */
end_comment

begin_define
define|#
directive|define
name|HPMBUF
value|((MLEN - sizeof(int)) / sizeof(struct host))
end_define

begin_define
define|#
directive|define
name|HOSTHASH
parameter_list|(
name|a
parameter_list|)
value|((a.s_addr) % HPMBUF)
end_define

begin_struct
struct|struct
name|hmbuf
block|{
name|int
name|hm_count
decl_stmt|;
comment|/* # of struct's in use */
name|struct
name|host
name|hm_hosts
index|[
name|HPMBUF
index|]
decl_stmt|;
comment|/* data structures proper */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|struct
name|host
modifier|*
name|h_lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|host
modifier|*
name|h_enter
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

