begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)if_imphost.h	7.1 (Berkeley) 6/4/86  */
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
name|u_char
name|h_qcnt
decl_stmt|;
comment|/* size of holding q */
name|u_char
name|h_timer
decl_stmt|;
comment|/* used to stay off deletion */
name|u_char
name|h_rfnm
decl_stmt|;
comment|/* # outstanding rfnm's */
name|u_char
name|h_flags
decl_stmt|;
comment|/* see below */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A host structure is kept around (even when there are no  * references to it) for a spell to avoid constant reallocation  * and also to reflect IMP status back to sites which aren't  * directly connected to the IMP.  When structures are marked  * free, a timer is started; when the timer expires the structure  * is scavenged.  */
end_comment

begin_define
define|#
directive|define
name|HF_INUSE
value|0x1
end_define

begin_define
define|#
directive|define
name|HF_DEAD
value|(1<<IMPTYPE_HOSTDEAD)
end_define

begin_define
define|#
directive|define
name|HF_UNREACH
value|(1<<IMPTYPE_HOSTUNREACH)
end_define

begin_define
define|#
directive|define
name|HOSTTIMER
value|128
end_define

begin_comment
comment|/* keep structure around awhile */
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

begin_if
if|#
directive|if
name|vax
end_if

begin_define
define|#
directive|define
name|HOSTHASH
parameter_list|(
name|a
parameter_list|)
value|((((a).s_addr>>24)+(a).s_addr) % HPMBUF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * In-line expansions for queuing operations on  * host message holding queue.  Queue is maintained  * as circular list with the head pointing to the  * last message in the queue.  */
end_comment

begin_define
define|#
directive|define
name|HOST_ENQUE
parameter_list|(
name|hp
parameter_list|,
name|m
parameter_list|)
value|{ \ 	register struct mbuf *n; \ 	(hp)->h_qcnt++; \ 	if ((n = (hp)->h_q) == 0) \ 		(hp)->h_q = (m)->m_act = (m); \ 	else { \ 		(m)->m_act = n->m_act; \ 		(hp)->h_q = n->m_act = (m); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|HOST_DEQUE
parameter_list|(
name|hp
parameter_list|,
name|m
parameter_list|)
value|{ \ 	if ((m) = (hp)->h_q) { \ 		if ((m)->m_act == (m)) \ 			(hp)->h_q = 0; \ 		else { \ 			(m) = (m)->m_act; \ 			(hp)->h_q->m_act = (m)->m_act; \ 		} \ 		(hp)->h_qcnt--; \ 		(m)->m_act = 0; \ 	} \ }
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
name|hostlookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|host
modifier|*
name|hostenter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|hostdeque
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

