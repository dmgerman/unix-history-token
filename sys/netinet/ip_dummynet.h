begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Luigi Rizzo  *  * Redistribution and use in source forms, with and without modification,  * are permitted provided that this entire comment appears intact.  *  * Redistribution in binary form may occur without any restrictions.  * Obviously, it would be nice if you gave credit where credit is due  * but requiring it would be too onerous.  *  * This software is provided ``AS IS'' without any warranties of any kind.  *  * $FreeBSD$  */
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
comment|/*  * Definition of dummynet data structures.  * Dummynet handles a list of pipes, each one identified by a unique  * number (hopefully the list is short so we use a linked list).  *  * Each list contains a set of parameters identifying the pipe, and  * a set of packets queued on the pipe itself.  *  * I could have used queue macros, but the management i have  * is pretty simple and this makes the code more portable.  */
end_comment

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
name|dn_m
value|hdr.mh_next
comment|/* packet to be forwarded */
define|#
directive|define
name|dn_dst
value|hdr.mh_len
comment|/* dst, for ip_output			*/
define|#
directive|define
name|dn_dir
value|hdr.mh_flags
comment|/* IP_FW_F_IN or IP_FW_F_OUT		*/
name|int
name|delay
decl_stmt|;
comment|/* stays queued until delay=0		*/
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* interface, for ip_output		*/
name|struct
name|route
name|ro
decl_stmt|;
comment|/* route, for ip_output. MUST COPY	*/
ifdef|#
directive|ifdef
name|DUMMYNET_DEBUG
name|struct
name|timeval
name|beg
decl_stmt|,
name|mid
decl_stmt|;
comment|/* testing only */
name|int
name|act_delay
decl_stmt|;
comment|/* testing only */
name|int
name|in_delay
decl_stmt|;
comment|/* testing only */
endif|#
directive|endif
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
comment|/*  * descriptor of a pipe. The flags field will be used to speed up the  * forwarding code paths, in case some of the parameters are not  * used.  */
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
name|DN_HAVE_BW
value|1
define|#
directive|define
name|DN_HAVE_QUEUE
value|2
define|#
directive|define
name|DN_HAVE_DELAY
value|4
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
name|r
decl_stmt|;
name|int
name|r_len
decl_stmt|;
comment|/* elements in r_queue */
name|int
name|r_len_bytes
decl_stmt|;
comment|/* bytes in r_queue */
name|int
name|r_drops
decl_stmt|;
comment|/* drops from r_queue */
name|struct
name|dn_queue
name|p
decl_stmt|;
name|int
name|ticks_from_last_insert
decl_stmt|;
name|long
name|numbytes
decl_stmt|;
comment|/* which can send or receive */
comment|/* 990421 -- numbytes is scaled by 8*hz */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following is used to define a new mbuf type that is  * prepended to the packet when it comes out of a pipe. The definition  * ought to go in /sys/sys/mbuf.h but here it is less intrusive.  */
end_comment

begin_define
define|#
directive|define
name|MT_DUMMYNET
value|MT_CONTROL
end_define

begin_comment
comment|/*  * what to do of a packet when it comes out of a pipe  */
end_comment

begin_define
define|#
directive|define
name|DN_TO_IP_OUT
value|1
end_define

begin_define
define|#
directive|define
name|DN_TO_IP_IN
value|2
end_define

begin_define
define|#
directive|define
name|DN_TO_BDG_FWD
value|3
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|void
name|ip_dn_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* called in ip_input.c */
end_comment

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

