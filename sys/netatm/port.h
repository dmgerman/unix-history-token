begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * System Configuration  * --------------------  *  * Porting aides  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_PORT_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_PORT_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Kernel buffers  *  * KBuffer 		Typedef for a kernel buffer.  *  * KB_NEXT(bfr)		Access next buffer in chain (r/w).  * KB_LEN(bfr)		Access length of data in this buffer (r/w).  * KB_QNEXT(bfr)	Access next buffer in queue (r/w).  *  * KB_ALLOC(bfr, size, flags, type)  *			Allocates a new kernel buffer of at least size bytes.  * KB_ALLOCPKT(bfr, size, flags, type)  *			Allocates a new kernel packet header buffer of at  *			least size bytes.  * KB_ALLOCEXT(bfr, size, flags, type)  *			Allocates a new kernel buffer with external storage  *			of at least size bytes.  * KB_FREEONE(bfr, nxt)	Free buffer bfr and set next buffer in chain in nxt.  * KB_FREEALL(bfr)	Free bfr's entire buffer chain.  * KB_COPY(bfr, off, len, new, flags)  *			Copy len bytes of user data from buffer bfr starting at  *			byte offset off and return new buffer chain in new.  *			If len is KB_COPYALL, copy until end of chain.  * KB_COPYDATA(bfr, off, len, datap)  *			Copy data from buffer bfr starting at byte offset off  *			for len bytes into the data area pointed to by datap.  *			Returns the number of bytes not copied to datap.  * KB_PULLUP(bfr, n, new)  *			Get at least the first n bytes of data in the buffer   *			chain headed by bfr contiguous in the first buffer.  *			Returns the (potentially new) head of the chain in new.  *			On failure the chain is freed and NULL is returned.  * KB_LINKHEAD(new, head)  *			Link the kernel buffer new at the head of the buffer  *			chain headed by head.  If both new and head are  *			packet header buffers, new will become the packet  *			header for the chain.  * KB_LINK(new, prev)  *			Link the kernel buffer new into the buffer chain  *			after the buffer prev.  * KB_UNLINKHEAD(head, next)  *			Unlink the kernel buffer from the head of the buffer  *			chain headed by head.  The buffer head will be freed  *			and the new chain head will be placed in next.  * KB_UNLINK(old, prev, next)  *			Unlink the kernel buffer old with previous buffer prev  *			from its buffer chain.  The following buffer in the  *			chain will be placed in next and the buffer old will  *			be freed.  * KB_ISPKT(bfr)	Tests whether bfr is a packet header buffer.  * KB_ISEXT(bfr)	Tests whether bfr has external storage.  * KB_BFRSTART(bfr, x, t)  *			Sets x (cast to type t) to point to the start of the  *			buffer space in bfr.  * KB_BFREND(bfr, x, t)  *			Sets x (cast to type t) to point one byte past the end  *			of the buffer space in bfr.  * KB_BFRLEN(bfr)	Returns length of buffer space in bfr.  * KB_DATASTART(bfr, x, t)  *			Sets x (cast to type t) to point to the start of the  *			buffer data contained in bfr.  * KB_DATAEND(bfr, x, t)  *			Sets x (cast to type t) to point one byte past the end  *			of the buffer data contained in bfr.  * KB_HEADSET(bfr, n)	Sets the start address for buffer data in buffer bfr to  *			n bytes from the beginning of the buffer space.  * KB_HEADMOVE(bfr, n) 	Adjust buffer data controls to move data down (n> 0)   *			or up (n< 0) n bytes in the buffer bfr.  * KB_HEADADJ(bfr, n) 	Adjust buffer data controls to add (n> 0) or subtract  *			(n< 0) n bytes of data to/from the beginning of bfr.  * KB_TAILADJ(bfr, n)	Adjust buffer data controls to add (n> 0) or subtract  *			(n< 0) n bytes of data to/from the end of bfr.  * KB_TAILALIGN(bfr, n)	Set buffer data controls to place an object of size n  *			at the end of bfr, longword aligned.  * KB_HEADROOM(bfr, n)	Set n to the amount of buffer space available before  *			the start of data in bfr.  * KB_TAILROOM(bfr, n)	Set n to the amount of buffer space available after  *			the end of data in bfr.  * KB_PLENGET(bfr, n)	Set n to bfr's packet length.  * KB_PLENSET(bfr, n)	Set bfr's packet length to n.  * KB_PLENADJ(bfr, n)	Adjust total packet length by n bytes.  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|mbuf
name|KBuffer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KB_F_WAIT
value|M_TRYWAIT
end_define

begin_define
define|#
directive|define
name|KB_F_NOWAIT
value|M_DONTWAIT
end_define

begin_define
define|#
directive|define
name|KB_T_HEADER
value|MT_HEADER
end_define

begin_define
define|#
directive|define
name|KB_T_DATA
value|MT_DATA
end_define

begin_define
define|#
directive|define
name|KB_COPYALL
value|M_COPYALL
end_define

begin_define
define|#
directive|define
name|KB_NEXT
parameter_list|(
name|bfr
parameter_list|)
value|(bfr)->m_next
end_define

begin_define
define|#
directive|define
name|KB_LEN
parameter_list|(
name|bfr
parameter_list|)
value|(bfr)->m_len
end_define

begin_define
define|#
directive|define
name|KB_QNEXT
parameter_list|(
name|bfr
parameter_list|)
value|(bfr)->m_nextpkt
end_define

begin_define
define|#
directive|define
name|KB_ALLOC
parameter_list|(
name|bfr
parameter_list|,
name|size
parameter_list|,
name|flags
parameter_list|,
name|type
parameter_list|)
value|{		\ 	if ((size)<= MLEN) {				\ 		MGET((bfr), (flags), (type));		\ 	} else						\ 		(bfr) = NULL;				\ }
end_define

begin_define
define|#
directive|define
name|KB_ALLOCPKT
parameter_list|(
name|bfr
parameter_list|,
name|size
parameter_list|,
name|flags
parameter_list|,
name|type
parameter_list|)
value|{		\ 	if ((size)<= MHLEN) {				\ 		MGETHDR((bfr), (flags), (type));	\ 	} else						\ 		(bfr) = NULL;				\ }
end_define

begin_define
define|#
directive|define
name|KB_ALLOCEXT
parameter_list|(
name|bfr
parameter_list|,
name|size
parameter_list|,
name|flags
parameter_list|,
name|type
parameter_list|)
value|{		\ 	if ((size)<= MCLBYTES)	{			\ 		MGET((bfr), (flags), (type));		\ 		if ((bfr) != NULL) {			\ 			MCLGET((bfr), (flags));		\ 			if (((bfr)->m_flags& M_EXT) == 0) {	\ 				m_freem((bfr));		\ 				(bfr) = NULL;		\ 			}				\ 		}					\ 	} else						\ 		(bfr) = NULL;				\ }
end_define

begin_define
define|#
directive|define
name|KB_FREEONE
parameter_list|(
name|bfr
parameter_list|,
name|nxt
parameter_list|)
value|{				\ 	(nxt) = m_free(bfr);				\ }
end_define

begin_define
define|#
directive|define
name|KB_FREEALL
parameter_list|(
name|bfr
parameter_list|)
value|{				\ 	m_freem(bfr);					\ }
end_define

begin_define
define|#
directive|define
name|KB_COPY
parameter_list|(
name|bfr
parameter_list|,
name|off
parameter_list|,
name|len
parameter_list|,
name|new
parameter_list|,
name|flags
parameter_list|)
value|{		\ 	(new) = m_copym((bfr), (off), (len), (flags));	\ }
end_define

begin_define
define|#
directive|define
name|KB_COPYDATA
parameter_list|(
name|bfr
parameter_list|,
name|off
parameter_list|,
name|len
parameter_list|,
name|datap
parameter_list|)
define|\
value|(m_copydata((bfr), (off), (len), (datap)), 0)
end_define

begin_define
define|#
directive|define
name|KB_PULLUP
parameter_list|(
name|bfr
parameter_list|,
name|n
parameter_list|,
name|new
parameter_list|)
value|{			\ 	(new) = m_pullup((bfr), (n));			\ }
end_define

begin_define
define|#
directive|define
name|KB_LINKHEAD
parameter_list|(
name|new
parameter_list|,
name|head
parameter_list|)
value|{			\ 	if ((head)&& KB_ISPKT(new)&& KB_ISPKT(head)) {\ 		M_MOVE_PKTHDR((new), (head));		\ 	}						\ 	(new)->m_next = (head);				\ }
end_define

begin_define
define|#
directive|define
name|KB_LINK
parameter_list|(
name|new
parameter_list|,
name|prev
parameter_list|)
value|{				\ 	(new)->m_next = (prev)->m_next;			\ 	(prev)->m_next = (new);				\ }
end_define

begin_define
define|#
directive|define
name|KB_UNLINKHEAD
parameter_list|(
name|head
parameter_list|,
name|next
parameter_list|)
value|{			\ 	(next) = m_free((head));			\ 	(head) = NULL;					\ }
end_define

begin_define
define|#
directive|define
name|KB_UNLINK
parameter_list|(
name|old
parameter_list|,
name|prev
parameter_list|,
name|next
parameter_list|)
value|{			\ 	(next) = m_free((old));				\ 	(old) = NULL;					\ 	(prev)->m_next = (next);			\ }
end_define

begin_define
define|#
directive|define
name|KB_ISPKT
parameter_list|(
name|bfr
parameter_list|)
value|(((bfr)->m_flags& M_PKTHDR) != 0)
end_define

begin_define
define|#
directive|define
name|KB_ISEXT
parameter_list|(
name|bfr
parameter_list|)
value|(((bfr)->m_flags& M_EXT) != 0)
end_define

begin_define
define|#
directive|define
name|KB_BFRSTART
parameter_list|(
name|bfr
parameter_list|,
name|x
parameter_list|,
name|t
parameter_list|)
value|{			\ 	if ((bfr)->m_flags& M_EXT)			\ 		(x) = (t)((bfr)->m_ext.ext_buf);	\ 	else if ((bfr)->m_flags& M_PKTHDR)		\ 		(x) = (t)(&(bfr)->m_pktdat);		\ 	else						\ 		(x) = (t)((bfr)->m_dat);		\ }
end_define

begin_define
define|#
directive|define
name|KB_BFREND
parameter_list|(
name|bfr
parameter_list|,
name|x
parameter_list|,
name|t
parameter_list|)
value|{				\ 	if ((bfr)->m_flags& M_EXT)			\ 		(x) = (t)((bfr)->m_ext.ext_buf + (bfr)->m_ext.ext_size);\ 	else if ((bfr)->m_flags& M_PKTHDR)		\ 		(x) = (t)(&(bfr)->m_pktdat + MHLEN);	\ 	else						\ 		(x) = (t)((bfr)->m_dat + MLEN);		\ }
end_define

begin_define
define|#
directive|define
name|KB_BFRLEN
parameter_list|(
name|bfr
parameter_list|)
define|\
value|(((bfr)->m_flags& M_EXT) ? (bfr)->m_ext.ext_size :	\ 		(((bfr)->m_flags& M_PKTHDR) ? MHLEN : MLEN))
end_define

begin_define
define|#
directive|define
name|KB_DATASTART
parameter_list|(
name|bfr
parameter_list|,
name|x
parameter_list|,
name|t
parameter_list|)
value|{			\ 	(x) = mtod((bfr), t);				\ }
end_define

begin_define
define|#
directive|define
name|KB_DATAEND
parameter_list|(
name|bfr
parameter_list|,
name|x
parameter_list|,
name|t
parameter_list|)
value|{				\ 	(x) = (t)(mtod((bfr), caddr_t) + (bfr)->m_len);	\ }
end_define

begin_define
define|#
directive|define
name|KB_HEADSET
parameter_list|(
name|bfr
parameter_list|,
name|n
parameter_list|)
value|{				\ 	if ((bfr)->m_flags& M_EXT)			\ 		(bfr)->m_data = (bfr)->m_ext.ext_buf + (n);	\ 	else if ((bfr)->m_flags& M_PKTHDR)		\ 		(bfr)->m_data = (bfr)->m_pktdat + (n);	\ 	else						\ 		(bfr)->m_data = (bfr)->m_dat + (n);	\ }
end_define

begin_define
define|#
directive|define
name|KB_HEADMOVE
parameter_list|(
name|bfr
parameter_list|,
name|n
parameter_list|)
value|{				\ 	(bfr)->m_data += (n);				\ }
end_define

begin_define
define|#
directive|define
name|KB_HEADADJ
parameter_list|(
name|bfr
parameter_list|,
name|n
parameter_list|)
value|{				\ 	(bfr)->m_len += (n);				\ 	(bfr)->m_data -= (n);				\ }
end_define

begin_define
define|#
directive|define
name|KB_TAILADJ
parameter_list|(
name|bfr
parameter_list|,
name|n
parameter_list|)
value|{				\ 	(bfr)->m_len += (n);				\ }
end_define

begin_define
define|#
directive|define
name|KB_TAILALIGN
parameter_list|(
name|bfr
parameter_list|,
name|n
parameter_list|)
value|{				\ 	(bfr)->m_len = (n);				\ 	if ((bfr)->m_flags& M_EXT)			\ 		(bfr)->m_data = (caddr_t)(((uintptr_t)(bfr)->m_ext.ext_buf \ 			+ (bfr)->m_ext.ext_size - (n))& ~(sizeof(long) - 1));\ 	else						\ 		(bfr)->m_data = (caddr_t)(((uintptr_t)(bfr)->m_dat + MLEN - (n)) \& ~(sizeof(long) - 1));		\ }
end_define

begin_define
define|#
directive|define
name|KB_HEADROOM
parameter_list|(
name|bfr
parameter_list|,
name|n
parameter_list|)
value|{				\
comment|/* N = m_leadingspace(BFR) XXX */
value|\ 	(n) = ((bfr)->m_flags& M_EXT ? (bfr)->m_data - (bfr)->m_ext.ext_buf : \ 		(bfr)->m_flags& M_PKTHDR ? (bfr)->m_data - (bfr)->m_pktdat : \ 			(bfr)->m_data - (bfr)->m_dat);	\ }
end_define

begin_define
define|#
directive|define
name|KB_TAILROOM
parameter_list|(
name|bfr
parameter_list|,
name|n
parameter_list|)
value|{				\ 	(n) = M_TRAILINGSPACE(bfr);			\ }
end_define

begin_define
define|#
directive|define
name|KB_PLENGET
parameter_list|(
name|bfr
parameter_list|,
name|n
parameter_list|)
value|{				\ 	(n) = (bfr)->m_pkthdr.len;			\ }
end_define

begin_define
define|#
directive|define
name|KB_PLENSET
parameter_list|(
name|bfr
parameter_list|,
name|n
parameter_list|)
value|{				\ 	(bfr)->m_pkthdr.len = (n);			\ }
end_define

begin_define
define|#
directive|define
name|KB_PLENADJ
parameter_list|(
name|bfr
parameter_list|,
name|n
parameter_list|)
value|{				\ 	(bfr)->m_pkthdr.len += (n);			\ }
end_define

begin_comment
comment|/*  * Kernel time  *  * KTimeout_ret		Typedef for timeout() function return  *  * KT_TIME(t)		Sets t to the current time.  *  */
end_comment

begin_typedef
typedef|typedef
name|void
name|KTimeout_ret
typedef|;
end_typedef

begin_define
define|#
directive|define
name|KT_TIME
parameter_list|(
name|t
parameter_list|)
value|microtime(&t)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX
end_ifndef

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|max((a),(b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MIN
end_ifndef

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|min((a),(b))
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
comment|/* _NETATM_PORT_H */
end_comment

end_unit

