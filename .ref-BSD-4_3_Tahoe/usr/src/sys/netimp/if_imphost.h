begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)if_imphost.h	7.6 (Berkeley) 6/29/88  */
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
name|u_short
name|h_timer
decl_stmt|;
comment|/* used to stay off deletion */
name|u_short
name|h_imp
decl_stmt|;
comment|/* host's imp number */
name|u_char
name|h_host
decl_stmt|;
comment|/* host's number on imp */
name|u_char
name|h_qcnt
decl_stmt|;
comment|/* size of holding q */
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
comment|/*  * A host structure is kept around (even when there are no  * references to it) for a spell to avoid constant reallocation  * and also to reflect IMP status back to sites which aren't  * directly connected to the IMP.  When structures are marked  * idle, a timer is started; when the timer expires the structure  * is deallocated.  A structure may be reused before the timer expires.  * A structure holds a reference on the containing mbuf when it is marked  * HF_INUSE.  */
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
comment|/*  * Mark a host structure free; used if host entry returned by hostlookup   * isn't needed.  h_rfnm must be zero.  */
end_comment

begin_define
define|#
directive|define
name|hostfree
parameter_list|(
name|hp
parameter_list|)
value|{ \ 	if ((hp)->h_timer == 0&& (hp)->h_qcnt == 0&& \ 	    (hp)->h_flags& HF_INUSE) \ 		hostrelease(hp); \ }
end_define

begin_comment
comment|/*  * Release a host entry when last rfnm is received.  */
end_comment

begin_define
define|#
directive|define
name|hostidle
parameter_list|(
name|hp
parameter_list|)
value|{ (hp)->h_timer = HOSTTIMER; }
end_define

begin_comment
comment|/*  * Host structures, as seen inside an mbuf.  * Hashing on the host and imp is used to  * select an index into the first mbuf.  Collisions  * are then resolved by searching successive  * mbuf's at the same index.  Reclamation is done  * automatically at the time a structure is freed.  */
end_comment

begin_define
define|#
directive|define
name|HPMBUF
value|((MLEN - sizeof(int)) / sizeof(struct host))
end_define

begin_comment
comment|/* don't need to swab as long as HPMBUF is odd */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|notdef
argument_list|)
operator|&&
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|HOSTHASH
parameter_list|(
name|imp
parameter_list|,
name|host
parameter_list|)
value|((unsigned)(ntohs(imp)+(host)) % HPMBUF)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HOSTHASH
parameter_list|(
name|imp
parameter_list|,
name|host
parameter_list|)
value|((unsigned)((imp)+(host)) % HPMBUF)
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

