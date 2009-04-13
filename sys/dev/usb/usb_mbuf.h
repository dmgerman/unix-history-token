begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Hans Petter Selasky. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_USB2_MBUF_H_
end_ifndef

begin_define
define|#
directive|define
name|_USB2_MBUF_H_
end_define

begin_comment
comment|/*  * The following structure defines a minimum re-implementation of the  * mbuf system in the kernel.  */
end_comment

begin_struct
struct|struct
name|usb2_mbuf
block|{
name|uint8_t
modifier|*
name|cur_data_ptr
decl_stmt|;
name|uint8_t
modifier|*
name|min_data_ptr
decl_stmt|;
name|struct
name|usb2_mbuf
modifier|*
name|usb2_nextpkt
decl_stmt|;
name|struct
name|usb2_mbuf
modifier|*
name|usb2_next
decl_stmt|;
name|usb2_size_t
name|cur_data_len
decl_stmt|;
name|usb2_size_t
name|max_data_len
decl_stmt|;
name|uint8_t
name|last_packet
range|:
literal|1
decl_stmt|;
name|uint8_t
name|unused
range|:
literal|7
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * The following structure defines a minimum re-implementation of the  * ifqueue structure in the kernel.  */
end_comment

begin_struct
struct|struct
name|usb2_ifqueue
block|{
name|struct
name|usb2_mbuf
modifier|*
name|ifq_head
decl_stmt|;
name|struct
name|usb2_mbuf
modifier|*
name|ifq_tail
decl_stmt|;
name|usb2_size_t
name|ifq_len
decl_stmt|;
name|usb2_size_t
name|ifq_maxlen
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USB_IF_ENQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do {		\     (m)->usb2_nextpkt = NULL;			\     if ((ifq)->ifq_tail == NULL)		\         (ifq)->ifq_head = (m);			\     else					\         (ifq)->ifq_tail->usb2_nextpkt = (m);	\     (ifq)->ifq_tail = (m);			\     (ifq)->ifq_len++;				\   } while (0)
end_define

begin_define
define|#
directive|define
name|USB_IF_DEQUEUE
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do {				\     (m) = (ifq)->ifq_head;					\     if (m) {							\         if (((ifq)->ifq_head = (m)->usb2_nextpkt) == NULL) {	\ 	     (ifq)->ifq_tail = NULL;				\ 	}							\ 	(m)->usb2_nextpkt = NULL;				\ 	(ifq)->ifq_len--;					\     }								\   } while (0)
end_define

begin_define
define|#
directive|define
name|USB_IF_PREPEND
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|do {		\       (m)->usb2_nextpkt = (ifq)->ifq_head;	\       if ((ifq)->ifq_tail == NULL) {		\ 	  (ifq)->ifq_tail = (m);		\       }						\       (ifq)->ifq_head = (m);			\       (ifq)->ifq_len++;				\   } while (0)
end_define

begin_define
define|#
directive|define
name|USB_IF_QFULL
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len>= (ifq)->ifq_maxlen)
end_define

begin_define
define|#
directive|define
name|USB_IF_QLEN
parameter_list|(
name|ifq
parameter_list|)
value|((ifq)->ifq_len)
end_define

begin_define
define|#
directive|define
name|USB_IF_POLL
parameter_list|(
name|ifq
parameter_list|,
name|m
parameter_list|)
value|((m) = (ifq)->ifq_head)
end_define

begin_define
define|#
directive|define
name|USB_MBUF_RESET
parameter_list|(
name|m
parameter_list|)
value|do {			\     (m)->cur_data_ptr = (m)->min_data_ptr;	\     (m)->cur_data_len = (m)->max_data_len;	\     (m)->last_packet = 0;			\   } while (0)
end_define

begin_comment
comment|/* prototypes */
end_comment

begin_function_decl
name|void
modifier|*
name|usb2_alloc_mbufs
parameter_list|(
name|struct
name|malloc_type
modifier|*
name|type
parameter_list|,
name|struct
name|usb2_ifqueue
modifier|*
name|ifq
parameter_list|,
name|usb2_size_t
name|block_size
parameter_list|,
name|uint16_t
name|nblocks
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _USB2_MBUF_H_ */
end_comment

end_unit

