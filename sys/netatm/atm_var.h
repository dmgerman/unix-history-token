begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * ATM system variables  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_ATM_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_ATM_VAR_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Global variable declarations  */
end_comment

begin_comment
comment|/* atm_aal5.c */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199506
operator|)
operator|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|atm_aal5_usrreqs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* atm_proto.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|domain
name|atmdomain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atm_subr.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|atm_pif
modifier|*
name|atm_interface_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|atm_ncm
modifier|*
name|atm_netconv_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Atm_endpoint
modifier|*
name|atm_endpoints
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
modifier|*
name|atm_pool_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stackq_entry
modifier|*
name|atm_stackq_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stackq_entry
modifier|*
name|atm_stackq_tail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|ifqueue
name|atm_intrq
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|atm_intr_index
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|atm_sock_stat
name|atm_sock_stat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atm_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atm_version
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atm_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|atm_debugtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atm_dev_print
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|atm_print_data
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sp_info
name|atm_attributes_pool
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* atm_usrreq.c */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199506
operator|)
operator|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|atm_dgram_usrreqs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Global function declarations  */
end_comment

begin_comment
comment|/* atm_aal5.c */
end_comment

begin_function_decl
name|int
name|atm_aal5_ctloutput
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_aal5_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_cm.c */
end_comment

begin_function_decl
name|int
name|atm_cm_connect
parameter_list|(
name|Atm_endpoint
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|Atm_attributes
modifier|*
parameter_list|,
name|Atm_connection
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_listen
parameter_list|(
name|Atm_endpoint
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|Atm_attributes
modifier|*
parameter_list|,
name|Atm_connection
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_addllc
parameter_list|(
name|Atm_endpoint
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|struct
name|attr_llc
modifier|*
parameter_list|,
name|Atm_connection
modifier|*
parameter_list|,
name|Atm_connection
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_addparty
parameter_list|(
name|Atm_connection
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|t_atm_sap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_dropparty
parameter_list|(
name|Atm_connection
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|t_atm_cause
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_release
parameter_list|(
name|Atm_connection
modifier|*
parameter_list|,
name|struct
name|t_atm_cause
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_abort
parameter_list|(
name|Atm_connvc
modifier|*
parameter_list|,
name|struct
name|t_atm_cause
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_incoming
parameter_list|(
name|struct
name|vccb
modifier|*
parameter_list|,
name|Atm_attributes
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_cm_connected
parameter_list|(
name|Atm_connvc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_cm_cleared
parameter_list|(
name|Atm_connvc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Atm_connection
modifier|*
name|atm_cm_match
parameter_list|(
name|Atm_attributes
modifier|*
parameter_list|,
name|Atm_connection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_cpcs_ctl
parameter_list|(
name|int
parameter_list|,
name|Atm_connection
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_cpcs_data
parameter_list|(
name|Atm_connection
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_saal_ctl
parameter_list|(
name|int
parameter_list|,
name|Atm_connection
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_saal_data
parameter_list|(
name|Atm_connection
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_sscop_ctl
parameter_list|(
name|int
parameter_list|,
name|Atm_connection
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_cm_sscop_data
parameter_list|(
name|Atm_connection
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_endpoint_register
parameter_list|(
name|Atm_endpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_endpoint_deregister
parameter_list|(
name|Atm_endpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_device.c */
end_comment

begin_function_decl
name|int
name|atm_dev_inst
parameter_list|(
name|struct
name|stack_defn
modifier|*
modifier|*
parameter_list|,
name|Atm_connvc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_dev_lower
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|atm_dev_alloc
parameter_list|(
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_dev_free
parameter_list|(
specifier|volatile
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun4m
argument_list|)
end_if

begin_function_decl
name|void
modifier|*
name|atm_dma_map
parameter_list|(
name|caddr_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_dma_free
parameter_list|(
name|caddr_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|KBuffer
modifier|*
name|atm_dev_compress
parameter_list|(
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Cmn_vcc
modifier|*
name|atm_dev_vcc_find
parameter_list|(
name|Cmn_unit
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_dev_pdu_print
parameter_list|(
name|Cmn_unit
modifier|*
parameter_list|,
name|Cmn_vcc
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_if.c */
end_comment

begin_function_decl
name|int
name|atm_physif_register
parameter_list|(
name|Cmn_unit
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|stack_defn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_physif_deregister
parameter_list|(
name|Cmn_unit
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_physif_freenifs
parameter_list|(
name|struct
name|atm_pif
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_netconv_register
parameter_list|(
name|struct
name|atm_ncm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_netconv_deregister
parameter_list|(
name|struct
name|atm_ncm
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_nif_attach
parameter_list|(
name|struct
name|atm_nif
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_nif_detach
parameter_list|(
name|struct
name|atm_nif
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_nif_setaddr
parameter_list|(
name|struct
name|atm_nif
modifier|*
parameter_list|,
name|struct
name|ifaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199103
operator|)
operator|)
end_if

begin_function_decl
name|int
name|atm_ifoutput
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|atm_ifoutput
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|struct
name|atm_pif
modifier|*
name|atm_pifname
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|atm_nif
modifier|*
name|atm_nifname
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_proto.c */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199506
operator|)
operator|)
end_if

begin_function_decl
name|int
name|atm_proto_notsupp1
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_proto_notsupp2
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_proto_notsupp3
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_proto_notsupp4
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* atm_signal.c */
end_comment

begin_function_decl
name|int
name|atm_sigmgr_register
parameter_list|(
name|struct
name|sigmgr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_sigmgr_deregister
parameter_list|(
name|struct
name|sigmgr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_sigmgr_attach
parameter_list|(
name|struct
name|atm_pif
modifier|*
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_sigmgr_detach
parameter_list|(
name|struct
name|atm_pif
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_stack_register
parameter_list|(
name|struct
name|stack_defn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_stack_deregister
parameter_list|(
name|struct
name|stack_defn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_create_stack
parameter_list|(
name|Atm_connvc
modifier|*
parameter_list|,
name|struct
name|stack_list
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_socket.c */
end_comment

begin_function_decl
name|int
name|atm_sock_attach
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_sock_detach
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_sock_bind
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_sock_listen
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|Atm_endpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_sock_connect
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|Atm_endpoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_sock_disconnect
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_sock_sockaddr
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_sock_peeraddr
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_sock_setopt
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|,
name|Atm_pcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_sock_getopt
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|,
name|Atm_pcb
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_sock_connected
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_sock_cleared
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|t_atm_cause
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_subr.c */
end_comment

begin_function_decl
name|void
name|atm_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|atm_allocate
parameter_list|(
name|struct
name|sp_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_release_pool
parameter_list|(
name|struct
name|sp_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_timeout
parameter_list|(
name|struct
name|atm_time
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|atm_time
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_untimeout
parameter_list|(
name|struct
name|atm_time
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_stack_enq
parameter_list|(
name|int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|Atm_connvc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_stack_drain
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_intr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_pdu_print
parameter_list|(
name|KBuffer
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* atm_usrreq.c */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
operator|(
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199506
operator|)
operator|)
operator|)
end_if

begin_function_decl
name|int
name|atm_dgram_usrreq
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETATM_ATM_VAR_H */
end_comment

end_unit

