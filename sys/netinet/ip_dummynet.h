begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2000 Luigi Rizzo, Universita` di Pisa  * Portions Copyright (c) 2000 Akamba Corp.  * All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IP_DUMMYNET_H
end_ifndef

begin_define
define|#
directive|define
name|_IP_DUMMYNET_H
end_define

begin_comment
comment|/*  * Definition of dummynet data structures.  * We first start with the heap which is used by the scheduler.  *  * Each list contains a set of parameters identifying the pipe, and  * a set of packets queued on the pipe itself.  *  * I could have used queue macros, but the management i have  * is pretty simple and this makes the code more portable.  */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|dn_key
typedef|;
end_typedef

begin_comment
comment|/* sorting key */
end_comment

begin_define
define|#
directive|define
name|DN_KEY_LT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))< 0)
end_define

begin_define
define|#
directive|define
name|DN_KEY_LEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))<= 0)
end_define

begin_define
define|#
directive|define
name|DN_KEY_GT
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))> 0)
end_define

begin_define
define|#
directive|define
name|DN_KEY_GEQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((int)((a)-(b))>= 0)
end_define

begin_struct
struct|struct
name|dn_heap_entry
block|{
name|dn_key
name|key
decl_stmt|;
comment|/* sorting key. Topmost element is smallest one */
name|void
modifier|*
name|object
decl_stmt|;
comment|/* object pointer */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dn_heap
block|{
name|int
name|size
decl_stmt|;
name|int
name|elements
decl_stmt|;
name|struct
name|dn_heap_entry
modifier|*
name|p
decl_stmt|;
comment|/* really an array of "size" entries */
block|}
struct|;
end_struct

begin_comment
comment|/*  * MT_DUMMYNET is a new (fake) mbuf type that is prepended to the  * packet when it comes out of a pipe. The definition  * ought to go in /sys/sys/mbuf.h but here it is less intrusive.  */
end_comment

begin_define
define|#
directive|define
name|MT_DUMMYNET
value|MT_CONTROL
end_define

begin_comment
comment|/*  * struct dn_pkt identifies a packet in the dummynet queue. The  * first part is really an m_hdr for implementation purposes, and some  * fields are saved there. When passing the packet back to the ip_input/  * ip_output(), the struct is prepended to the mbuf chain with type  * MT_DUMMYNET, and contains the pointer to the matching rule.  */
end_comment

begin_struct
struct|struct
name|dn_pkt
block|{
name|struct
name|m_hdr
name|hdr
decl_stmt|;
define|#
directive|define
name|dn_next
value|hdr.mh_nextpkt
comment|/* next element in queue */
define|#
directive|define
name|DN_NEXT
parameter_list|(
name|x
parameter_list|)
value|(struct dn_pkt *)(x)->dn_next
define|#
directive|define
name|dn_m
value|hdr.mh_next
comment|/* packet to be forwarded */
comment|/* #define dn_dst	hdr.mh_len -* dst, for ip_output		*/
define|#
directive|define
name|dn_dir
value|hdr.mh_flags
comment|/* action when pkt extracted from a queue */
define|#
directive|define
name|DN_TO_IP_OUT
value|1
define|#
directive|define
name|DN_TO_IP_IN
value|2
define|#
directive|define
name|DN_TO_BDG_FWD
value|3
name|dn_key
name|output_time
decl_stmt|;
comment|/* when the pkt is due for delivery */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* interface, for ip_output		*/
name|struct
name|sockaddr_in
modifier|*
name|dn_dst
decl_stmt|;
name|struct
name|route
name|ro
decl_stmt|;
comment|/* route, for ip_output. MUST COPY	*/
name|int
name|flags
decl_stmt|;
comment|/* flags, for ip_output (IPv6 ?) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dn_queue
block|{
name|struct
name|dn_pkt
modifier|*
name|head
decl_stmt|,
modifier|*
name|tail
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * We use per flow queues. Hashing is used to select the right slot,  * then we scan the list to match the flow-id.  * The pipe is shared as it is only a delay line and thus one is enough.  */
end_comment

begin_struct
struct|struct
name|dn_flow_queue
block|{
name|struct
name|dn_flow_queue
modifier|*
name|next
decl_stmt|;
name|struct
name|ipfw_flow_id
name|id
decl_stmt|;
name|struct
name|dn_pipe
modifier|*
name|p
decl_stmt|;
comment|/* parent pipe */
name|struct
name|dn_queue
name|r
decl_stmt|;
name|long
name|numbytes
decl_stmt|;
name|u_int
name|len
decl_stmt|;
name|u_int
name|len_bytes
decl_stmt|;
name|u_int64_t
name|tot_pkts
decl_stmt|;
comment|/* statistics counters	*/
name|u_int64_t
name|tot_bytes
decl_stmt|;
name|u_int32_t
name|drops
decl_stmt|;
name|int
name|hash_slot
decl_stmt|;
comment|/* debugging/diagnostic */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Pipe descriptor. Contains global parameters, delay-line queue,  * and the hash array of the per-flow queues.  */
end_comment

begin_struct
struct|struct
name|dn_pipe
block|{
comment|/* a pipe */
name|struct
name|dn_pipe
modifier|*
name|next
decl_stmt|;
name|u_short
name|pipe_nr
decl_stmt|;
comment|/* number	*/
name|u_short
name|flags
decl_stmt|;
comment|/* to speed up things	*/
define|#
directive|define
name|DN_HAVE_FLOW_MASK
value|8
name|int
name|bandwidth
decl_stmt|;
comment|/* really, bytes/tick.	*/
name|int
name|queue_size
decl_stmt|;
name|int
name|queue_size_bytes
decl_stmt|;
name|int
name|delay
decl_stmt|;
comment|/* really, ticks	*/
name|int
name|plr
decl_stmt|;
comment|/* pkt loss rate (2^31-1 means 100%) */
name|struct
name|dn_queue
name|p
decl_stmt|;
name|struct
name|ipfw_flow_id
name|flow_mask
decl_stmt|;
name|int
name|rq_size
decl_stmt|;
name|int
name|rq_elements
decl_stmt|;
name|struct
name|dn_flow_queue
modifier|*
modifier|*
name|rq
decl_stmt|;
comment|/* array of rq_size entries */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_IPFW
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|int
name|ip_dn_ctl_t
name|__P
typedef|((struct
name|sockopt
modifier|*
typedef|)) ;
end_typedef

begin_decl_stmt
specifier|extern
name|ip_dn_ctl_t
modifier|*
name|ip_dn_ctl_ptr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|dn_rule_delete
parameter_list|(
name|void
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* used in ip_fw.c */
end_comment

begin_function_decl
name|int
name|dummynet_io
parameter_list|(
name|int
name|pipe
parameter_list|,
name|int
name|dir
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|route
modifier|*
name|ro
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|dst
parameter_list|,
name|struct
name|ip_fw_chain
modifier|*
name|rule
parameter_list|,
name|int
name|flags
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
comment|/* _IP_DUMMYNET_H */
end_comment

end_unit

