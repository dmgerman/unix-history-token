begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if.h	4.1	81/11/18	*/
end_comment

begin_comment
comment|/*  * Structure defining a network interface.  *  * (Would like to call this struct ``if'', but C isn't PL/1.)  */
end_comment

begin_struct
struct|struct
name|ifnet
block|{
name|short
name|if_unit
decl_stmt|;
comment|/* sub-unit for lower level driver */
name|short
name|if_flags
decl_stmt|;
comment|/* state flags */
name|short
name|if_mtu
decl_stmt|;
comment|/* maximum transmission unit */
name|short
name|if_net
decl_stmt|;
comment|/* network number of interface */
name|struct
name|in_addr
name|if_addr
decl_stmt|;
comment|/* internet address of interface */
struct|struct
name|ifbuf
block|{
name|short
name|ib_mbcnt
decl_stmt|;
comment|/* mbufs on chain */
name|short
name|ib_mbhiwat
decl_stmt|;
comment|/* mbufs permitted on chain */
name|struct
name|mbuf
modifier|*
name|ib_hd
decl_stmt|;
comment|/* head of chain */
name|struct
name|mbuf
modifier|*
name|ib_tl
decl_stmt|;
comment|/* tail of chain */
block|}
name|if_snd
struct|,
name|if_rcv
struct|;
struct|struct
name|ifsw
block|{
name|int
function_decl|(
modifier|*
name|if_output
function_decl|)
parameter_list|()
function_decl|;
comment|/* output routine */
name|int
function_decl|(
modifier|*
name|if_ubareset
function_decl|)
parameter_list|()
function_decl|;
comment|/* uba reset routine */
block|}
modifier|*
name|if_sw
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* bits in if_flags */
end_comment

begin_define
define|#
directive|define
name|IF_OACTIVE
value|1
end_define

begin_comment
comment|/* output in progress */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|ifnet
modifier|*
name|ifnet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ifnet
modifier|*
name|if_ifwithaddr
argument_list|()
decl_stmt|,
modifier|*
name|if_ifonnetof
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

