begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
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

begin_comment
comment|/*  * Try to ensure that this system is supported  */
end_comment

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

begin_comment
comment|/* 4.3 BSD Net2 based */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sun
argument_list|)
end_elif

begin_comment
comment|/* SunOS4.x */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Ooops */
end_comment

begin_error
error|#
directive|error
literal|"Undefined/unsupported system type"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Kernel memory management  *  * KM_ALLOC(size, type, flags)  *			Returns an allocated kernel memory chunk of size bytes.  * KM_FREE(addr, size, type)  *			Free a kernel memory chunk of size bytes.  * KM_CMP(b1, b2, len)  *			Compares len bytes of data from b1 against b2.  * KM_COPY(from, to, len)  *			Copies len bytes of data from from to to.  * KM_ZERO(addr, len)  *			Zeros len bytes of data from addr.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

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

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_define
define|#
directive|define
name|KM_ALLOC
parameter_list|(
name|size
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|)
value|malloc((size), (type), (flags))
end_define

begin_define
define|#
directive|define
name|KM_FREE
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|,
name|type
parameter_list|)
value|free((addr), (type))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sun
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/kmem_alloc.h>
end_include

begin_define
define|#
directive|define
name|KM_ALLOC
parameter_list|(
name|size
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|)
value|kmem_alloc(size)
end_define

begin_define
define|#
directive|define
name|KM_FREE
parameter_list|(
name|addr
parameter_list|,
name|size
parameter_list|,
name|type
parameter_list|)
value|kmem_free((addr), (size))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
end_if

begin_define
define|#
directive|define
name|KM_CMP
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|len
parameter_list|)
value|bcmp((void *)(b1), (void *)(b2),\ 						(len))
end_define

begin_define
define|#
directive|define
name|KM_COPY
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|len
parameter_list|)
value|bcopy((void *)(from), (void *)(to),\ 						(len))
end_define

begin_define
define|#
directive|define
name|KM_ZERO
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|)
value|bzero((void *)(addr), (len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XM_COPY
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|,
name|l
parameter_list|)
value|KM_COPY((f), (t), (l))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * User-space memory management  *  * UM_ALLOC(size)	Returns an allocated kernel memory chunk of size bytes.  * UM_FREE(addr)	Free a kernel memory chunk of size bytes.  * UM_COPY(from, to, len)  *			Copies len bytes of data from from to to.  * UM_ZERO(addr, len)	Zeros len bytes of data from addr.  *  */
end_comment

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

begin_define
define|#
directive|define
name|UM_ALLOC
parameter_list|(
name|size
parameter_list|)
value|malloc((size_t)(size))
end_define

begin_define
define|#
directive|define
name|UM_FREE
parameter_list|(
name|addr
parameter_list|)
value|free((void *)(addr))
end_define

begin_define
define|#
directive|define
name|UM_COPY
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|len
parameter_list|)
value|bcopy((void *)(from), (void *)(to),\ 						(size_t)(len))
end_define

begin_define
define|#
directive|define
name|UM_ZERO
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|)
value|bzero((void *)(addr), (size_t)(len))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sun
argument_list|)
end_elif

begin_define
define|#
directive|define
name|UM_ALLOC
parameter_list|(
name|size
parameter_list|)
value|malloc(size)
end_define

begin_define
define|#
directive|define
name|UM_FREE
parameter_list|(
name|addr
parameter_list|)
value|free((char *)(addr))
end_define

begin_define
define|#
directive|define
name|UM_COPY
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|len
parameter_list|)
value|bcopy((char *)(from), (char *)(to), (len))
end_define

begin_define
define|#
directive|define
name|UM_ZERO
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|)
value|bzero((char *)(addr), (len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XM_COPY
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|,
name|l
parameter_list|)
value|UM_COPY((f), (t), (l))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATM_KERNEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATM_KERNEL
end_ifdef

begin_comment
comment|/*  * Kernel buffers  *  * KBuffer 		Typedef for a kernel buffer.  *  * KB_NEXT(bfr)		Access next buffer in chain (r/w).  * KB_LEN(bfr)		Access length of data in this buffer (r/w).  * KB_QNEXT(bfr)	Access next buffer in queue (r/w).  *  * KB_ALLOC(bfr, size, flags, type)  *			Allocates a new kernel buffer of at least size bytes.  * KB_ALLOCPKT(bfr, size, flags, type)  *			Allocates a new kernel packet header buffer of at  *			least size bytes.  * KB_ALLOCEXT(bfr, size, flags, type)  *			Allocates a new kernel buffer with external storage  *			of at least size bytes.  * KB_FREEONE(bfr, nxt)	Free buffer bfr and set next buffer in chain in nxt.  * KB_FREEALL(bfr)	Free bfr's entire buffer chain.  * KB_COPY(bfr, off, len, new, flags)  *			Copy len bytes of user data from buffer bfr starting at  *			byte offset off and return new buffer chain in new.  *			If len is KB_COPYALL, copy until end of chain.  * KB_COPYDATA(bfr, off, len, datap)  *			Copy data from buffer bfr starting at byte offset off  *			for len bytes into the data area pointed to by datap.  *			Returns the number of bytes not copied to datap.  * KB_PULLUP(bfr, n, new)  *			Get at least the first n bytes of data in the buffer   *			chain headed by bfr contiguous in the first buffer.  *			Returns the (potentially new) head of the chain in new.  *			On failure the chain is freed and NULL is returned.  * KB_LINKHEAD(new, head)  *			Link the kernel buffer new at the head of the buffer  *			chain headed by head.  If both new and head are  *			packet header buffers, new will become the packet  *			header for the chain.  * KB_LINK(new, prev)  *			Link the kernel buffer new into the buffer chain  *			after the buffer prev.  * KB_UNLINKHEAD(head, next)  *			Unlink the kernel buffer from the head of the buffer  *			chain headed by head.  The buffer head will be freed  *			and the new chain head will be placed in next.  * KB_UNLINK(old, prev, next)  *			Unlink the kernel buffer old with previous buffer prev  *			from its buffer chain.  The following buffer in the  *			chain will be placed in next and the buffer old will  *			be freed.  * KB_ISPKT(bfr)	Tests whether bfr is a packet header buffer.  * KB_ISEXT(bfr)	Tests whether bfr has external storage.  * KB_BFRSTART(bfr, x, t)  *			Sets x (cast to type t) to point to the start of the  *			buffer space in bfr.  * KB_BFREND(bfr, x, t)  *			Sets x (cast to type t) to point one byte past the end  *			of the buffer space in bfr.  * KB_BFRLEN(bfr)	Returns length of buffer space in bfr.  * KB_DATASTART(bfr, x, t)  *			Sets x (cast to type t) to point to the start of the  *			buffer data contained in bfr.  * KB_DATAEND(bfr, x, t)  *			Sets x (cast to type t) to point one byte past the end  *			of the buffer data contained in bfr.  * KB_HEADSET(bfr, n)	Sets the start address for buffer data in buffer bfr to  *			n bytes from the beginning of the buffer space.  * KB_HEADMOVE(bfr, n) 	Adjust buffer data controls to move data down (n> 0)   *			or up (n< 0) n bytes in the buffer bfr.  * KB_HEADADJ(bfr, n) 	Adjust buffer data controls to add (n> 0) or subtract  *			(n< 0) n bytes of data to/from the beginning of bfr.  * KB_TAILADJ(bfr, n)	Adjust buffer data controls to add (n> 0) or subtract  *			(n< 0) n bytes of data to/from the end of bfr.  * KB_TAILALIGN(bfr, n)	Set buffer data controls to place an object of size n  *			at the end of bfr, longword aligned.  * KB_HEADROOM(bfr, n)	Set n to the amount of buffer space available before  *			the start of data in bfr.  * KB_TAILROOM(bfr, n)	Set n to the amount of buffer space available after  *			the end of data in bfr.  * KB_PLENGET(bfr, n)	Set n to bfr's packet length.  * KB_PLENSET(bfr, n)	Set bfr's packet length to n.  * KB_PLENADJ(bfr, n)	Adjust total packet length by n bytes.  *  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
end_if

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
value|M_WAIT
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

begin_if
if|#
directive|if
name|BSD
operator|>=
literal|199103
end_if

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
value|{			\ 	if ((head)&& KB_ISPKT(new)&& KB_ISPKT(head)) {\ 		M_COPY_PKTHDR((new), (head));		\ 		(head)->m_flags&= ~M_PKTHDR;		\ 	}						\ 	(new)->m_next = (head);				\ }
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
value|{			\ 	MFREE((head), (next));				\ }
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
value|{			\ 	MFREE((old), (next));				\ 	(prev)->m_next = (next);			\ }
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
value|{				\ 	(bfr)->m_len = (n);				\ 	if ((bfr)->m_flags& M_EXT)			\ 		(bfr)->m_data = (caddr_t)(((u_int)(bfr)->m_ext.ext_buf	\ 			+ (bfr)->m_ext.ext_size - (n))& ~(sizeof(long) - 1));\ 	else						\ 		(bfr)->m_data = (caddr_t)(((u_int)(bfr)->m_dat + MLEN - (n)) \& ~(sizeof(long) - 1));		\ }
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
comment|/* n = M_LEADINGSPACE(bfr) XXX */
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! BSD>= 199103 */
end_comment

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
value|(bfr)->m_act
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
value|{		\ 	if ((size)<= MLEN) {				\ 		MGET((bfr), (flags), (type));		\ 	} else						\ 		(bfr) = NULL;				\ }
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
value|{		\ 	if ((size)<= MCLBYTES)	{			\ 		MGET((bfr), (flags), (type));		\ 		if ((bfr) != NULL) {			\ 			MCLGET(bfr);			\ 			if ((bfr)->m_len != MCLBYTES) {	\ 				m_freem((bfr));		\ 				(bfr) = NULL;		\ 			}				\ 		}					\ 	} else						\ 		(bfr) = NULL;				\ }
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
value|{		\ 	(new) = m_copy((bfr), (off), (len));		\ }
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
value|m_cpytoc((bfr), (off), (len), (datap))
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
value|{			\ 	(new)->m_next = (head);				\ }
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
value|{			\ 	MFREE((head), (next));				\ }
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
value|{			\ 	MFREE((old), (next));				\ 	(prev)->m_next = (next);			\ }
end_define

begin_define
define|#
directive|define
name|KB_ISPKT
parameter_list|(
name|bfr
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|KB_ISEXT
parameter_list|(
name|bfr
parameter_list|)
value|M_HASCL(bfr)
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
value|{			\ 	if (M_HASCL(bfr)) {				\ 		if ((bfr)->m_cltype == MCL_STATIC)	\ 			(x) = (t)(mtod((bfr), int)& ~(MCLBYTES - 1));	\ 		else					\ 			(x) = (t)NULL;			\ 	} else						\ 		(x) = (t)((bfr)->m_dat);		\ }
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
value|{				\ 	if (M_HASCL(bfr)) {				\ 		if ((bfr)->m_cltype == MCL_STATIC)	\ 			(x) = (t)((mtod((bfr), int)& ~(MCLBYTES - 1))	\ 				+ MCLBYTES);		\ 		else					\ 			(x) = (t)NULL;			\ 	} else						\ 		(x) = (t)((bfr)->m_dat + MLEN);		\ }
end_define

begin_define
define|#
directive|define
name|KB_BFRLEN
parameter_list|(
name|bfr
parameter_list|)
define|\
value|(M_HASCL(bfr) ? (((bfr)->m_cltype == MCL_STATIC) ? MCLBYTES : 0) : MLEN)
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
value|{				\ 	if (M_HASCL(bfr)) {				\
comment|/* Assume cluster buffer is empty XXX */
value|\ 		(bfr)->m_off += (n);			\ 	} else						\ 		(bfr)->m_off = MMINOFF + (n);		\ }
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
value|{				\ 	(bfr)->m_off += (n);				\ }
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
value|{				\ 	(bfr)->m_len += (n);				\ 	(bfr)->m_off -= (n);				\ }
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
value|{				\ 	(bfr)->m_len = (n);				\ 	if (M_HASCL(bfr)) {				\ 		if ((bfr)->m_cltype == MCL_STATIC)	\ 			(bfr)->m_off = (int)(((mtod((bfr), int)		\& ~(MCLBYTES - 1)) + MCLBYTES - (n))	\& ~(sizeof(long) - 1)) - (int)(bfr);	\
comment|/* Out of luck for loaned buffers */
value|\ 	} else						\ 		(bfr)->m_off = (MMAXOFF - (n))& ~(sizeof(long) - 1);	\ }
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
value|{				\ 	if (M_HASCL(bfr)) {				\ 		if ((bfr)->m_cltype == MCL_STATIC)	\ 			(n) = mtod((bfr), int)& (MCLBYTES - 1);	\ 		else					\ 			(n) = 0;			\ 	} else						\ 		(n) = (bfr)->m_off - MMINOFF;		\ }
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
value|{				\ 	if (M_HASCL(bfr)) {				\ 		if ((bfr)->m_cltype == MCL_STATIC)	\ 			(n) = MCLBYTES - ((mtod((bfr), int) + (bfr)->m_len) \& (MCLBYTES - 1));	\ 		else					\ 			(n) = 0;			\ 	} else						\ 		(n) = MMAXOFF - ((bfr)->m_off + (bfr)->m_len);	\ }
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
value|{				\ 	struct mbuf	*zz;				\ 	for ((n) = 0, zz = (bfr); zz; zz = zz->m_next)	\ 		(n) += zz->m_len;			\ }
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
value|{				\ }
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
value|{				\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! BSD>= 199103 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(BSD) */
end_comment

begin_comment
comment|/*  * Kernel time  *  * KTimeout_ret		Typedef for timeout() function return  *  * KT_TIME(t)		Sets t to the current time.  *  */
end_comment

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
literal|199306
operator|)
operator|)
end_if

begin_typedef
typedef|typedef
name|void
name|KTimeout_ret
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|KTimeout_ret
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|KT_TIME
parameter_list|(
name|t
parameter_list|)
value|microtime(&t)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sun
argument_list|)
end_elif

begin_define
define|#
directive|define
name|KT_TIME
parameter_list|(
name|t
parameter_list|)
value|uniqtime(&t)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KT_TIME
parameter_list|(
name|t
parameter_list|)
value|((t) = time)
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
comment|/* ATM_KERNEL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTOHL
end_ifndef

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|NTOHL
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|NTOHS
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|HTONL
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|HTONS
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NTOHL
parameter_list|(
name|x
parameter_list|)
value|(x) = ntohl((u_long)(x))
end_define

begin_define
define|#
directive|define
name|NTOHS
parameter_list|(
name|x
parameter_list|)
value|(x) = ntohs((u_short)(x))
end_define

begin_define
define|#
directive|define
name|HTONL
parameter_list|(
name|x
parameter_list|)
value|(x) = htonl((u_long)(x))
end_define

begin_define
define|#
directive|define
name|HTONS
parameter_list|(
name|x
parameter_list|)
value|(x) = htons((u_short)(x))
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
comment|/* NTOHL */
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

begin_if
if|#
directive|if
operator|(
operator|!
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199306
operator|)
operator|)
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__BIT_TYPES_DEFINED__
end_ifndef

begin_define
define|#
directive|define
name|__BIT_TYPES_DEFINED__
end_define

begin_typedef
typedef|typedef
name|char
name|int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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

