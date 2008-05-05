begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<contrib/rdma/ib_verbs.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/*  * Krping header stuffs...  */
end_comment

begin_struct
struct|struct
name|krping_stats
block|{
name|unsigned
name|send_bytes
decl_stmt|;
name|unsigned
name|send_msgs
decl_stmt|;
name|unsigned
name|recv_bytes
decl_stmt|;
name|unsigned
name|recv_msgs
decl_stmt|;
name|unsigned
name|write_bytes
decl_stmt|;
name|unsigned
name|write_msgs
decl_stmt|;
name|unsigned
name|read_bytes
decl_stmt|;
name|unsigned
name|read_msgs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * These states are used to signal events between the completion handler  * and the main client or server thread.  *  * Once CONNECTED, they cycle through RDMA_READ_ADV, RDMA_WRITE_ADV,   * and RDMA_WRITE_COMPLETE for each ping.  */
end_comment

begin_enum
enum|enum
name|test_state
block|{
name|IDLE
init|=
literal|1
block|,
name|CONNECT_REQUEST
block|,
name|ADDR_RESOLVED
block|,
name|ROUTE_RESOLVED
block|,
name|CONNECTED
block|,
name|RDMA_READ_ADV
block|,
name|RDMA_READ_COMPLETE
block|,
name|RDMA_WRITE_ADV
block|,
name|RDMA_WRITE_COMPLETE
block|,
name|ERROR
block|}
enum|;
end_enum

begin_struct
struct|struct
name|krping_rdma_info
block|{
name|uint64_t
name|buf
decl_stmt|;
name|uint32_t
name|rkey
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Control block struct.  */
end_comment

begin_struct
struct|struct
name|krping_cb
block|{
name|int
name|server
decl_stmt|;
comment|/* 0 iff client */
name|struct
name|ib_cq
modifier|*
name|cq
decl_stmt|;
name|struct
name|ib_pd
modifier|*
name|pd
decl_stmt|;
name|struct
name|ib_qp
modifier|*
name|qp
decl_stmt|;
name|struct
name|ib_mr
modifier|*
name|dma_mr
decl_stmt|;
name|int
name|use_dmamr
decl_stmt|;
name|struct
name|ib_recv_wr
name|rq_wr
decl_stmt|;
comment|/* recv work request record */
name|struct
name|ib_sge
name|recv_sgl
decl_stmt|;
comment|/* recv single SGE */
name|struct
name|krping_rdma_info
name|recv_buf
decl_stmt|;
comment|/* malloc'd buffer */
name|struct
name|ib_mr
modifier|*
name|recv_mr
decl_stmt|;
name|struct
name|ib_send_wr
name|sq_wr
decl_stmt|;
comment|/* send work requrest record */
name|struct
name|ib_sge
name|send_sgl
decl_stmt|;
name|struct
name|krping_rdma_info
name|send_buf
decl_stmt|;
comment|/* single send buf */
name|struct
name|ib_mr
modifier|*
name|send_mr
decl_stmt|;
name|struct
name|ib_send_wr
name|rdma_sq_wr
decl_stmt|;
comment|/* rdma work request record */
name|struct
name|ib_sge
name|rdma_sgl
decl_stmt|;
comment|/* rdma single SGE */
name|char
modifier|*
name|rdma_buf
decl_stmt|;
comment|/* used as rdma sink */
name|u64
name|rdma_addr
decl_stmt|;
name|struct
name|ib_mr
modifier|*
name|rdma_mr
decl_stmt|;
name|uint32_t
name|remote_rkey
decl_stmt|;
comment|/* remote guys RKEY */
name|uint64_t
name|remote_addr
decl_stmt|;
comment|/* remote guys TO */
name|uint32_t
name|remote_len
decl_stmt|;
comment|/* remote guys LEN */
name|char
modifier|*
name|start_buf
decl_stmt|;
comment|/* rdma read src */
name|u64
name|start_addr
decl_stmt|;
name|struct
name|ib_mr
modifier|*
name|start_mr
decl_stmt|;
name|enum
name|test_state
name|state
decl_stmt|;
comment|/* used for cond/signalling */
name|struct
name|mtx
name|lock
decl_stmt|;
name|struct
name|krping_stats
name|stats
decl_stmt|;
name|uint16_t
name|port
decl_stmt|;
comment|/* dst port in NBO */
name|struct
name|in_addr
name|addr
decl_stmt|;
comment|/* dst addr in NBO */
name|char
modifier|*
name|addr_str
decl_stmt|;
comment|/* dst addr string */
name|int
name|verbose
decl_stmt|;
comment|/* verbose logging */
name|int
name|count
decl_stmt|;
comment|/* ping count */
name|int
name|size
decl_stmt|;
comment|/* ping data size */
name|int
name|validate
decl_stmt|;
comment|/* validate ping data */
comment|/* CM stuff */
name|struct
name|rdma_cm_id
modifier|*
name|cm_id
decl_stmt|;
comment|/* connection on client side,*/
comment|/* listener on service side. */
name|struct
name|rdma_cm_id
modifier|*
name|child_cm_id
decl_stmt|;
comment|/* connection on server side */
name|TAILQ_ENTRY
argument_list|(
argument|krping_cb
argument_list|)
name|list
expr_stmt|;
name|int
name|rlat
decl_stmt|;
comment|/* run read latency test */
name|int
name|wlat
decl_stmt|;
comment|/* run write latency test */
name|int
name|bw
decl_stmt|;
comment|/* run write bw test */
name|int
name|duplex
decl_stmt|;
comment|/* run write bw full duplex test */
name|int
name|poll
decl_stmt|;
comment|/* poll vs block in rlat */
name|int
name|txdepth
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|uint64_t
name|get_cycles
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int32_t
name|low
decl_stmt|,
name|high
decl_stmt|;
asm|__asm __volatile("rdtsc" : "=a" (low), "=d" (high));
return|return
operator|(
name|low
operator||
operator|(
operator|(
name|u_int64_t
operator|)
name|high
operator|<<
literal|32
operator|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|htonll
parameter_list|(
name|x
parameter_list|)
value|htobe64((x))
end_define

begin_define
define|#
directive|define
name|ntohll
parameter_list|(
name|x
parameter_list|)
value|be64toh((x))
end_define

begin_typedef
typedef|typedef
name|uint64_t
name|cycles_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|krping_mutex
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|krping_cb_list
argument_list|,
name|krping_cb
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|krping_cb_list
name|krping_cbs
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|krping_doit
parameter_list|(
name|char
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|krping_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

