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
comment|/*  * Definition of dummynet data structures. In the structures, I decided  * not to use the macros in<sys/queue.h> in the hope of making the code  * easier to port to other architectures. The type of lists and queue we  * use here is pretty simple anyways.  */
end_comment

begin_comment
comment|/*  * We start with a heap, which is used in the scheduler to decide when  * to transmit packets etc.  *  * The key for the heap is used for two different values:  *  * 1. timer ticks- max 10K/second, so 32 bits are enough;  *  * 2. virtual times. These increase in steps of len/x, where len is the  *    packet length, and x is either the weight of the flow, or the  *    sum of all weights.  *    If we limit to max 1000 flows and a max weight of 100, then  *    x needs 17 bits. The packet size is 16 bits, so we can easily  *    overflow if we do not allow errors.  * So we use a key "dn_key" which is 64 bits. Some macros are used to  * compare key values and handle wraparounds.  * MAX64 returns the largest of two key values.  * MY_M is used as a shift count when doing fixed point arithmetic  * (a better name would be useful...).  */
end_comment

begin_typedef
typedef|typedef
name|u_int64_t
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
value|((int64_t)((a)-(b))< 0)
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
value|((int64_t)((a)-(b))<= 0)
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
value|((int64_t)((a)-(b))> 0)
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
value|((int64_t)((a)-(b))>= 0)
end_define

begin_define
define|#
directive|define
name|MAX64
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(( (int64_t) ( (y)-(x) ))> 0 ) ? (y) : (x)
end_define

begin_define
define|#
directive|define
name|MY_M
value|16
end_define

begin_comment
comment|/* number of left shift to obtain a larger precision */
end_comment

begin_comment
comment|/*  * XXX With this scaling, max 1000 flows, max weight 100, 1Gbit/s, the  * virtual time wraps every 15 days.  */
end_comment

begin_comment
comment|/*  * The OFFSET_OF macro is used to return the offset of a field within  * a structure. It is used by the heap management routines.  */
end_comment

begin_define
define|#
directive|define
name|OFFSET_OF
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
value|((int)&( ((type *)0)->field) )
end_define

begin_comment
comment|/*  * A heap entry is made of a key and a pointer to the actual  * object stored in the heap.  * The heap is an array of dn_heap_entry entries, dynamically allocated.  * Current size is "size", with "elements" actually in use.  * The heap normally supports only ordered insert and extract from the top.  * If we want to extract an object from the middle of the heap, we  * have to know where the object itself is located in the heap (or we  * need to scan the whole array). To this purpose, an object has a  * field (int) which contains the index of the object itself into the  * heap. When the object is moved, the field must also be updated.  * The offset of the index in the object is stored in the 'offset'  * field in the heap descriptor. The assumption is that this offset  * is non-zero if we want to support extract from the middle.  */
end_comment

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
name|int
name|offset
decl_stmt|;
comment|/* XXX if> 0 this is the offset of direct ptr to obj */
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
comment|/*  * struct dn_pkt identifies a packet in the dummynet queue. The  * first part is really an m_hdr for implementation purposes, and some  * fields are saved there. When passing the packet back to the ip_input/  * ip_output()/bdg_forward, the struct is prepended to the mbuf chain with type  * MT_DUMMYNET, and contains the pointer to the matching rule.  *  * Note: there is no real need to make this structure contain an m_hdr,  * in the future this should be changed to a normal data structure.  */
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

begin_comment
comment|/*  * Overall structure of dummynet (with WF2Q+):  In dummynet, packets are selected with the firewall rules, and passed to two different objects: PIPE or QUEUE.  A QUEUE is just a queue with configurable size and queue management policy. It is also associated with a mask (to discriminate among different flows), a weight (used to give different shares of the bandwidth to different flows) and a "pipe", which essentially supplies the transmit clock for all queues associated with that pipe.  A PIPE emulates a fixed-bandwidth link, whose bandwidth is configurable.  The "clock" for a pipe can come from either an internal timer, or from the transmit interrupt of an interface. A pipe is also associated with one (or more, if masks are used) queue, where all packets for that pipe are stored.  The bandwidth available on the pipe is shared by the queues associated with that pipe (only one in case the packet is sent to a PIPE) according to the WF2Q+ scheduling algorithm and the configured weights.  In general, incoming packets are stored in the appropriate queue, which is then placed into one of a few heaps managed by a scheduler to decide when the packet should be extracted. The scheduler (a function called dummynet()) is run at every timer tick, and grabs queues from the head of the heaps when they are ready for processing.  There are three data structures definining a pipe and associated queues:   + dn_pipe, which contains the main configuration parameters related    to delay and bandwidth;  + dn_flow_set, which contains WF2Q+ configuration, flow    masks, plr and RED configuration;  + dn_flow_queue, which is the per-flow queue (containing the packets)  Multiple dn_flow_set can be linked to the same pipe, and multiple dn_flow_queue can be linked to the same dn_flow_set. All data structures are linked in a linear list which is used for housekeeping purposes.  During configuration, we create and initialize the dn_flow_set and dn_pipe structures (a dn_pipe also contains a dn_flow_set).  At runtime: packets are sent to the appropriate dn_flow_set (either WFQ ones, or the one embedded in the dn_pipe for fixed-rate flows), which in turn dispatches them to the appropriate dn_flow_queue (created dynamically according to the masks).  The transmit clock for fixed rate flows (ready_event()) selects the dn_flow_queue to be used to transmit the next packet. For WF2Q, wfq_ready_event() extract a pipe which in turn selects the right flow using a number of heaps defined into the pipe itself.   *  */
end_comment

begin_comment
comment|/*  * per flow queue. This contains the flow identifier, the queue  * of packets, counters, and parameters used to support both RED and  * WF2Q+.  */
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
name|dn_pkt
modifier|*
name|head
decl_stmt|,
modifier|*
name|tail
decl_stmt|;
comment|/* queue of packets */
name|u_int
name|len
decl_stmt|;
name|u_int
name|len_bytes
decl_stmt|;
name|long
name|numbytes
decl_stmt|;
comment|/* credit for transmission (dynamic queues) */
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
comment|/* RED parameters */
name|int
name|avg
decl_stmt|;
comment|/* average queue length est. (scaled) */
name|int
name|count
decl_stmt|;
comment|/* arrivals since last RED drop */
name|int
name|random
decl_stmt|;
comment|/* random value (scaled) */
name|u_int32_t
name|q_time
decl_stmt|;
comment|/* start of queue idle time */
comment|/* WF2Q+ support */
name|struct
name|dn_flow_set
modifier|*
name|fs
decl_stmt|;
comment|/* parent flow set */
name|int
name|heap_pos
decl_stmt|;
comment|/* position (index) of struct in heap */
name|dn_key
name|sched_time
decl_stmt|;
comment|/* current time when queue enters ready_heap */
name|dn_key
name|S
decl_stmt|,
name|F
decl_stmt|;
comment|/* start-time, finishing time */
comment|/* setting F< S means the timestamp is invalid. We only need      * to test this when the queue is empty.      */
block|}
struct|;
end_struct

begin_comment
comment|/*  * flow_set descriptor. Contains the "template" parameters for the  * queue configuration, and pointers to the hash table of dn_flow_queue's.  *  * The hash table is an array of lists -- we identify the slot by  * hashing the flow-id, then scan the list looking for a match.  * The size of the hash table (buckets) is configurable on a per-queue  * basis.  */
end_comment

begin_struct
struct|struct
name|dn_flow_set
block|{
name|struct
name|dn_flow_set
modifier|*
name|next
decl_stmt|;
comment|/* next flow set in all_flow_sets list */
name|u_short
name|fs_nr
decl_stmt|;
comment|/* flow_set number       */
name|u_short
name|flags_fs
decl_stmt|;
define|#
directive|define
name|DN_HAVE_FLOW_MASK
value|0x0001
define|#
directive|define
name|DN_IS_PIPE
value|0x4000
define|#
directive|define
name|DN_IS_QUEUE
value|0x8000
define|#
directive|define
name|DN_IS_RED
value|0x0002
define|#
directive|define
name|DN_IS_GENTLE_RED
value|0x0004
define|#
directive|define
name|DN_QSIZE_IS_BYTES
value|0x0008
comment|/* queue measured in bytes */
name|struct
name|dn_pipe
modifier|*
name|pipe
decl_stmt|;
comment|/* pointer to parent pipe */
name|u_short
name|parent_nr
decl_stmt|;
comment|/* parent pipe#, 0 if local to a pipe */
name|int
name|weight
decl_stmt|;
comment|/* WFQ queue weight */
name|int
name|qsize
decl_stmt|;
comment|/* queue size in slots or bytes */
name|int
name|plr
decl_stmt|;
comment|/* pkt loss rate (2^31-1 means 100%) */
name|struct
name|ipfw_flow_id
name|flow_mask
decl_stmt|;
comment|/* hash table of queues onto this flow_set */
name|int
name|rq_size
decl_stmt|;
comment|/* number of slots */
name|int
name|rq_elements
decl_stmt|;
comment|/* active elements */
name|struct
name|dn_flow_queue
modifier|*
modifier|*
name|rq
decl_stmt|;
comment|/* array of rq_size entries */
name|u_int32_t
name|last_expired
decl_stmt|;
comment|/* do not expire too frequently */
comment|/* XXX some RED parameters as well ? */
name|int
name|backlogged
decl_stmt|;
comment|/* #active queues for this flowset */
comment|/* RED parameters */
define|#
directive|define
name|SCALE_RED
value|16
define|#
directive|define
name|SCALE
parameter_list|(
name|x
parameter_list|)
value|( (x)<< SCALE_RED )
define|#
directive|define
name|SCALE_VAL
parameter_list|(
name|x
parameter_list|)
value|( (x)>> SCALE_RED )
define|#
directive|define
name|SCALE_MUL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|( ( (x) * (y) )>> SCALE_RED )
name|int
name|w_q
decl_stmt|;
comment|/* queue weight (scaled) */
name|int
name|max_th
decl_stmt|;
comment|/* maximum threshold for queue (scaled) */
name|int
name|min_th
decl_stmt|;
comment|/* minimum threshold for queue (scaled) */
name|int
name|max_p
decl_stmt|;
comment|/* maximum value for p_b (scaled) */
name|u_int
name|c_1
decl_stmt|;
comment|/* max_p/(max_th-min_th) (scaled) */
name|u_int
name|c_2
decl_stmt|;
comment|/* max_p*min_th/(max_th-min_th) (scaled) */
name|u_int
name|c_3
decl_stmt|;
comment|/* for GRED, (1-max_p)/max_th (scaled) */
name|u_int
name|c_4
decl_stmt|;
comment|/* for GRED, 1 - 2*max_p (scaled) */
name|u_int
modifier|*
name|w_q_lookup
decl_stmt|;
comment|/* lookup table for computing (1-w_q)^t */
name|u_int
name|lookup_depth
decl_stmt|;
comment|/* depth of lookup table */
name|int
name|lookup_step
decl_stmt|;
comment|/* granularity inside the lookup table */
name|int
name|lookup_weight
decl_stmt|;
comment|/* equal to (1-w_q)^t / (1-w_q)^(t+1) */
name|int
name|avg_pkt_size
decl_stmt|;
comment|/* medium packet size */
name|int
name|max_pkt_size
decl_stmt|;
comment|/* max packet size */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Pipe descriptor. Contains global parameters, delay-line queue,  * and the flow_set used for fixed-rate queues.  *   * For WF2Q support it also has 4 heaps holding dn_flow_queue:  *   not_eligible_heap, for queues whose start time is higher  *	than the virtual time. Sorted by start time.  *   scheduler_heap, for queues eligible for scheduling. Sorted by  *	finish time.  *   backlogged_heap, all flows in the two heaps above, sorted by  *	start time. This is used to compute the virtual time.  *   idle_heap, all flows that are idle and can be removed. We  *	do that on each tick so we do not slow down too much  *	operations during forwarding.  *  */
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
name|int
name|pipe_nr
decl_stmt|;
comment|/* number	*/
name|int
name|bandwidth
decl_stmt|;
comment|/* really, bytes/tick.	*/
name|int
name|delay
decl_stmt|;
comment|/* really, ticks	*/
name|struct
name|dn_pkt
modifier|*
name|head
decl_stmt|,
modifier|*
name|tail
decl_stmt|;
comment|/* packets in delay line */
comment|/* WF2Q+ */
name|struct
name|dn_heap
name|scheduler_heap
decl_stmt|;
comment|/* top extract - key Finish time*/
name|struct
name|dn_heap
name|not_eligible_heap
decl_stmt|;
comment|/* top extract- key Start time */
name|struct
name|dn_heap
name|idle_heap
decl_stmt|;
comment|/* random extract - key Start=Finish time */
name|dn_key
name|V
decl_stmt|;
comment|/* virtual time */
name|int
name|sum
decl_stmt|;
comment|/* sum of weights of all active sessions */
name|int
name|numbytes
decl_stmt|;
comment|/* bit i can transmit (more or less). */
name|dn_key
name|sched_time
decl_stmt|;
comment|/* first time pipe is scheduled in ready_heap */
comment|/* the tx clock can come from an interface. In this case, the      * name is below, and the pointer is filled when the rule is      * configured. We identify this by setting the if_name to a      * non-empty string.      */
name|char
name|if_name
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|int
name|ready
decl_stmt|;
comment|/* set if ifp != NULL and we got a signal from it */
name|struct
name|dn_flow_set
name|fs
decl_stmt|;
comment|/* used with fixed-rate flows */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_typedef
typedef|typedef
name|int
name|ip_dn_ctl_t
parameter_list|(
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* raw_ip.c */
end_comment

begin_typedef
typedef|typedef
name|void
name|ip_dn_ruledel_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* ip_fw.c */
end_comment

begin_typedef
typedef|typedef
name|int
name|ip_dn_io_t
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
name|ip_fw
modifier|*
name|rule
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* ip_{in,out}put.c, bridge.c */
end_comment

begin_decl_stmt
specifier|extern
name|ip_dn_ctl_t
modifier|*
name|ip_dn_ctl_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ip_dn_ruledel_t
modifier|*
name|ip_dn_ruledel_ptr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ip_dn_io_t
modifier|*
name|ip_dn_io_ptr
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DUMMYNET_LOADED
value|(ip_dn_io_ptr != NULL)
end_define

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

