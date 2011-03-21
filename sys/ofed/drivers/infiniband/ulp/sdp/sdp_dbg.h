begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_SDP_DBG_H_
end_ifndef

begin_define
define|#
directive|define
name|_SDP_DBG_H_
end_define

begin_define
define|#
directive|define
name|SDPSTATS_ON
end_define

begin_comment
comment|//#define GETNSTIMEODAY_SUPPORTED
end_comment

begin_define
define|#
directive|define
name|_sdp_printk
parameter_list|(
name|func
parameter_list|,
name|line
parameter_list|,
name|level
parameter_list|,
name|sk
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|do {								\ 	printk(level "%s:%d %p sdp_sock(%d:%d %d:%d): " format "\n",	\ 	       func, line, sk ? sdp_sk(sk) : NULL,		\ 	       curproc->p_pid, PCPU_GET(cpuid),			\ 	       (sk)&& sdp_sk(sk) ? ntohs(sdp_sk(sk)->lport) : -1,	\ 	       (sk)&& sdp_sk(sk) ? ntohs(sdp_sk(sk)->fport) : -1, ## arg);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|sdp_printk
parameter_list|(
name|level
parameter_list|,
name|sk
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|_sdp_printk(__func__, __LINE__, level, sk, format, ## arg)
end_define

begin_define
define|#
directive|define
name|sdp_warn
parameter_list|(
name|sk
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|sdp_printk(KERN_WARNING, sk, format , ## arg)
end_define

begin_define
define|#
directive|define
name|SDP_MODPARAM_SINT
parameter_list|(
name|var
parameter_list|,
name|def_val
parameter_list|,
name|msg
parameter_list|)
define|\
value|static int var = def_val; \ 	module_param_named(var, var, int, 0644); \ 	MODULE_PARM_DESC(var, msg " [" #def_val "]"); \  #define SDP_MODPARAM_INT(var, def_val, msg) \ 	int var = def_val; \ 	module_param_named(var, var, int, 0644); \ 	MODULE_PARM_DESC(var, msg " [" #def_val "]"); \  #ifdef SDP_PROFILING
end_define

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|sdpprf_log
block|{
name|int
name|idx
decl_stmt|;
name|int
name|pid
decl_stmt|;
name|int
name|cpu
decl_stmt|;
name|int
name|sk_num
decl_stmt|;
name|int
name|sk_dport
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mb
decl_stmt|;
name|char
name|msg
index|[
literal|256
index|]
decl_stmt|;
name|unsigned
name|long
name|long
name|time
decl_stmt|;
specifier|const
name|char
modifier|*
name|func
decl_stmt|;
name|int
name|line
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SDPPRF_LOG_SIZE
value|0x20000
end_define

begin_comment
comment|/* must be a power of 2 */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sdpprf_log
name|sdpprf_log
index|[
name|SDPPRF_LOG_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sdpprf_log_count
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|GETNSTIMEODAY_SUPPORTED
end_ifdef

begin_function
specifier|static
specifier|inline
name|unsigned
name|long
name|long
name|current_nsec
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|timespec
name|tv
decl_stmt|;
name|getnstimeofday
argument_list|(
operator|&
name|tv
argument_list|)
expr_stmt|;
return|return
name|tv
operator|.
name|tv_sec
operator|*
name|NSEC_PER_SEC
operator|+
name|tv
operator|.
name|tv_nsec
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|current_nsec
parameter_list|()
value|jiffies_to_usecs(jiffies)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|sdp_prf1
parameter_list|(
name|sk
parameter_list|,
name|s
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
value|({ \ 	struct sdpprf_log *l = \&sdpprf_log[sdpprf_log_count++& (SDPPRF_LOG_SIZE - 1)]; \ 	preempt_disable(); \ 	l->idx = sdpprf_log_count - 1; \ 	l->pid = current->pid; \ 	l->sk_num = (sk) ? inet_sk(sk)->num : -1;                 \ 	l->sk_dport = (sk) ? ntohs(inet_sk(sk)->dport) : -1; \ 	l->cpu = smp_processor_id(); \ 	l->mb = s; \ 	snprintf(l->msg, sizeof(l->msg) - 1, format, ## arg); \ 	l->time = current_nsec(); \ 	l->func = __func__; \ 	l->line = __LINE__; \ 	preempt_enable(); \ 	1; \ })
end_define

begin_comment
comment|//#define sdp_prf(sk, s, format, arg...)
end_comment

begin_define
define|#
directive|define
name|sdp_prf
parameter_list|(
name|sk
parameter_list|,
name|s
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
value|sdp_prf1(sk, s, format, ## arg)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sdp_prf1
parameter_list|(
name|sk
parameter_list|,
name|s
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|sdp_prf
parameter_list|(
name|sk
parameter_list|,
name|s
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_INFINIBAND_SDP_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|sdp_debug_level
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sdp_dbg
parameter_list|(
name|sk
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|do {                                                 \ 		if (sdp_debug_level> 0)                     \ 		sdp_printk(KERN_WARNING, sk, format , ## arg); \ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_INFINIBAND_SDP_DEBUG */
end_comment

begin_define
define|#
directive|define
name|sdp_dbg
parameter_list|(
name|priv
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|do { (void) (priv); } while (0)
end_define

begin_define
define|#
directive|define
name|sock_ref
parameter_list|(
name|sk
parameter_list|,
name|msg
parameter_list|,
name|sock_op
parameter_list|)
value|sock_op(sk)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_INFINIBAND_SDP_DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_INFINIBAND_SDP_DEBUG_DATA
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|sdp_data_debug_level
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sdp_dbg_data
parameter_list|(
name|sk
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|do {                                                 		\ 		if (sdp_data_debug_level& 0x2)                		\ 			sdp_printk(KERN_WARNING, sk, format , ## arg); 	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SDP_DUMP_PACKET
parameter_list|(
name|sk
parameter_list|,
name|str
parameter_list|,
name|mb
parameter_list|,
name|h
parameter_list|)
define|\
value|do {                                                 		\ 		if (sdp_data_debug_level& 0x1)                		\ 			dump_packet(sk, str, mb, h); 			\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sdp_dbg_data
parameter_list|(
name|priv
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|SDP_DUMP_PACKET
parameter_list|(
name|sk
parameter_list|,
name|str
parameter_list|,
name|mb
parameter_list|,
name|h
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SOCK_REF_RESET
value|"RESET"
end_define

begin_define
define|#
directive|define
name|SOCK_REF_ALIVE
value|"ALIVE"
end_define

begin_comment
comment|/* sock_alloc -> destruct_sock */
end_comment

begin_define
define|#
directive|define
name|SOCK_REF_CLONE
value|"CLONE"
end_define

begin_define
define|#
directive|define
name|SOCK_REF_CMA
value|"CMA"
end_define

begin_comment
comment|/* sdp_cma_handler() is expected to be invoked */
end_comment

begin_define
define|#
directive|define
name|SOCK_REF_SEQ
value|"SEQ"
end_define

begin_comment
comment|/* during proc read */
end_comment

begin_define
define|#
directive|define
name|SOCK_REF_DREQ_TO
value|"DREQ_TO"
end_define

begin_comment
comment|/* dreq timeout is pending */
end_comment

begin_define
define|#
directive|define
name|SOCK_REF_ZCOPY
value|"ZCOPY"
end_define

begin_comment
comment|/* zcopy send in process */
end_comment

begin_define
define|#
directive|define
name|SOCK_REF_RDMA_RD
value|"RDMA_RD"
end_define

begin_comment
comment|/* RDMA read in process */
end_comment

begin_define
define|#
directive|define
name|sock_hold
parameter_list|(
name|sk
parameter_list|,
name|msg
parameter_list|)
value|sock_ref(sk, msg, sock_hold)
end_define

begin_define
define|#
directive|define
name|sock_put
parameter_list|(
name|sk
parameter_list|,
name|msg
parameter_list|)
value|sock_ref(sk, msg, sock_put)
end_define

begin_define
define|#
directive|define
name|__sock_put
parameter_list|(
name|sk
parameter_list|,
name|msg
parameter_list|)
value|sock_ref(sk, msg, __sock_put)
end_define

begin_define
define|#
directive|define
name|ENUM2STR
parameter_list|(
name|e
parameter_list|)
value|[e] = #e
end_define

begin_function
specifier|static
specifier|inline
name|char
modifier|*
name|sdp_state_str
parameter_list|(
name|int
name|state
parameter_list|)
block|{
specifier|static
name|char
modifier|*
name|state2str
index|[]
init|=
block|{
name|ENUM2STR
argument_list|(
name|TCPS_ESTABLISHED
argument_list|)
block|,
name|ENUM2STR
argument_list|(
name|TCPS_SYN_SENT
argument_list|)
block|,
name|ENUM2STR
argument_list|(
name|TCPS_SYN_RECEIVED
argument_list|)
block|,
name|ENUM2STR
argument_list|(
name|TCPS_FIN_WAIT_1
argument_list|)
block|,
name|ENUM2STR
argument_list|(
name|TCPS_FIN_WAIT_2
argument_list|)
block|,
name|ENUM2STR
argument_list|(
name|TCPS_TIME_WAIT
argument_list|)
block|,
name|ENUM2STR
argument_list|(
name|TCPS_CLOSED
argument_list|)
block|,
name|ENUM2STR
argument_list|(
name|TCPS_CLOSE_WAIT
argument_list|)
block|,
name|ENUM2STR
argument_list|(
name|TCPS_LAST_ACK
argument_list|)
block|,
name|ENUM2STR
argument_list|(
name|TCPS_LISTEN
argument_list|)
block|,
name|ENUM2STR
argument_list|(
name|TCPS_CLOSING
argument_list|)
block|, 	}
decl_stmt|;
if|if
condition|(
name|state
operator|<
literal|0
operator|||
name|state
operator|>=
name|ARRAY_SIZE
argument_list|(
name|state2str
argument_list|)
condition|)
return|return
literal|"unknown"
return|;
return|return
name|state2str
index|[
name|state
index|]
return|;
block|}
end_function

begin_struct_decl
struct_decl|struct
name|sdp_bsdh
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_INFINIBAND_SDP_DEBUG_DATA
end_ifdef

begin_function_decl
name|void
name|_dump_packet
parameter_list|(
specifier|const
name|char
modifier|*
name|func
parameter_list|,
name|int
name|line
parameter_list|,
name|struct
name|socket
modifier|*
name|sk
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|struct
name|mbuf
modifier|*
name|mb
parameter_list|,
specifier|const
name|struct
name|sdp_bsdh
modifier|*
name|h
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|dump_packet
parameter_list|(
name|sk
parameter_list|,
name|str
parameter_list|,
name|mb
parameter_list|,
name|h
parameter_list|)
define|\
value|_dump_packet(__func__, __LINE__, sk, str, mb, h)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

