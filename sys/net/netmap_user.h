begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2011 Matteo Landi, Luigi Rizzo. All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *   *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *      documentation and/or other materials provided with the  *      distribution.  *   *   3. Neither the name of the authors nor the names of their contributors  *      may be used to endorse or promote products derived from this  *      software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY MATTEO LANDI AND CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MATTEO LANDI OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  *  * This header contains the macros used to manipulate netmap structures  * and packets in userspace. See netmap(4) for more information.  *  * The address of the struct netmap_if, say nifp, is computed from the  * value returned from ioctl(.., NIOCREG, ...) and the mmap region:  *	ioctl(fd, NIOCREG,&req);  *	mem = mmap(0, ... );  *	nifp = NETMAP_IF(mem, req.nr_nifp);  *		(so simple, we could just do it manually)  *  * From there:  *	struct netmap_ring *NETMAP_TXRING(nifp, index)  *	struct netmap_ring *NETMAP_RXRING(nifp, index)  *		we can access ring->nr_cur, ring->nr_avail, ring->nr_flags  *  *	ring->slot[i] gives us the i-th slot (we can access  *		directly plen, flags, bufindex)  *  *	char *buf = NETMAP_BUF(ring, x) returns a pointer to  *		the buffer numbered x  *  * Since rings are circular, we have macros to compute the next index  *	i = NETMAP_RING_NEXT(ring, i);  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_NETMAP_USER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_NETMAP_USER_H_
end_define

begin_define
define|#
directive|define
name|_NETMAP_OFFSET
parameter_list|(
name|type
parameter_list|,
name|ptr
parameter_list|,
name|offset
parameter_list|)
define|\
value|((type)(void *)((char *)(ptr) + (offset)))
end_define

begin_define
define|#
directive|define
name|NETMAP_IF
parameter_list|(
name|b
parameter_list|,
name|o
parameter_list|)
value|_NETMAP_OFFSET(struct netmap_if *, b, o)
end_define

begin_define
define|#
directive|define
name|NETMAP_TXRING
parameter_list|(
name|nifp
parameter_list|,
name|index
parameter_list|)
value|_NETMAP_OFFSET(struct netmap_ring *, \ 	nifp, (nifp)->ring_ofs[index] )
end_define

begin_define
define|#
directive|define
name|NETMAP_RXRING
parameter_list|(
name|nifp
parameter_list|,
name|index
parameter_list|)
value|_NETMAP_OFFSET(struct netmap_ring *,	\ 	nifp, (nifp)->ring_ofs[index + (nifp)->ni_tx_rings + 1] )
end_define

begin_define
define|#
directive|define
name|NETMAP_BUF
parameter_list|(
name|ring
parameter_list|,
name|index
parameter_list|)
define|\
value|((char *)(ring) + (ring)->buf_ofs + ((index)*(ring)->nr_buf_size))
end_define

begin_define
define|#
directive|define
name|NETMAP_BUF_IDX
parameter_list|(
name|ring
parameter_list|,
name|buf
parameter_list|)
define|\
value|( ((char *)(buf) - ((char *)(ring) + (ring)->buf_ofs) ) / \ 		(ring)->nr_buf_size )
end_define

begin_define
define|#
directive|define
name|NETMAP_RING_NEXT
parameter_list|(
name|r
parameter_list|,
name|i
parameter_list|)
define|\
value|((i)+1 == (r)->num_slots ? 0 : (i) + 1 )
end_define

begin_define
define|#
directive|define
name|NETMAP_RING_FIRST_RESERVED
parameter_list|(
name|r
parameter_list|)
define|\
value|( (r)->cur< (r)->reserved ?			\ 	  (r)->cur + (r)->num_slots - (r)->reserved :	\ 	  (r)->cur - (r)->reserved )
end_define

begin_comment
comment|/*  * Return 1 if the given tx ring is empty.  */
end_comment

begin_define
define|#
directive|define
name|NETMAP_TX_RING_EMPTY
parameter_list|(
name|r
parameter_list|)
value|((r)->avail>= (r)->num_slots - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_NETMAP_USER_H_ */
end_comment

end_unit

