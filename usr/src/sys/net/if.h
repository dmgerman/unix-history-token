begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if.h	4.3	81/11/26	*/
end_comment

begin_comment
comment|/*  * Definitions for network interfaces.  */
end_comment

begin_struct
struct|struct
name|ifqueue
block|{
name|struct
name|mbuf
modifier|*
name|ifq_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|ifq_tail
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure defining a queue for a network interface.  *  * (Would like to call this struct ``if'', but C isn't PL/1.)  */
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
name|if_mtu
decl_stmt|;
comment|/* maximum transmission unit */
name|short
name|if_net
decl_stmt|;
comment|/* network number of interface */
name|int
name|if_host
index|[
literal|2
index|]
decl_stmt|;
comment|/* local net host number */
name|struct
name|in_addr
name|if_addr
decl_stmt|;
comment|/* internet address of interface */
name|struct
name|ifqueue
name|if_snd
decl_stmt|;
comment|/* output queue */
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
name|int
name|if_collisions
decl_stmt|;
name|int
name|if_ierrors
decl_stmt|;
name|int
name|if_oerrors
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|if_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IF_ENQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(m)->m_act = 0; \ 	if ((ifq)->ifq_tail == 0) \ 		(ifq)->ifq_head = (ifq)->ifq_tail =  m; \ 	else \ 		(ifq)->ifq_tail->m_act = m; \ }
end_define

begin_define
define|#
directive|define
name|IF_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|{ \ 	(m) = (ifq)->ifq_head; \ 	if (m) { \ 		if (((ifq)->ifq_head = (m)->m_act) == 0) \ 			(ifq)->ifq_tail = 0; \ 		(m)->m_act = 0; \ 	} \ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_decl_stmt
name|struct
name|ifqueue
name|ipintrq
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ip packet input queue */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
decl_stmt|,
modifier|*
name|if_gatewayfor
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

