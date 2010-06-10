begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Rick Macklem, University of Guelph  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_NFSKPIPORT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_NFSKPIPORT_H_
end_define

begin_comment
comment|/*  * These definitions are needed since the generic code is now using Darwin8  * KPI stuff. (I know, seems a bit silly, but I want the code to build on  * Darwin8 and hopefully subsequent releases from Apple.)  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|mount
modifier|*
name|mount_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|vfs_statfs
parameter_list|(
name|m
parameter_list|)
value|(&((m)->mnt_stat))
end_define

begin_define
define|#
directive|define
name|vfs_flags
parameter_list|(
name|m
parameter_list|)
value|((m)->mnt_flag)
end_define

begin_typedef
typedef|typedef
name|struct
name|vnode
modifier|*
name|vnode_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|vnode_mount
parameter_list|(
name|v
parameter_list|)
value|((v)->v_mount)
end_define

begin_define
define|#
directive|define
name|vnode_vtype
parameter_list|(
name|v
parameter_list|)
value|((v)->v_type)
end_define

begin_typedef
typedef|typedef
name|struct
name|mbuf
modifier|*
name|mbuf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|mbuf_freem
parameter_list|(
name|m
parameter_list|)
value|m_freem(m)
end_define

begin_define
define|#
directive|define
name|mbuf_data
parameter_list|(
name|m
parameter_list|)
value|mtod((m), void *)
end_define

begin_define
define|#
directive|define
name|mbuf_len
parameter_list|(
name|m
parameter_list|)
value|((m)->m_len)
end_define

begin_define
define|#
directive|define
name|mbuf_next
parameter_list|(
name|m
parameter_list|)
value|((m)->m_next)
end_define

begin_define
define|#
directive|define
name|mbuf_setlen
parameter_list|(
name|m
parameter_list|,
name|l
parameter_list|)
value|((m)->m_len = (l))
end_define

begin_define
define|#
directive|define
name|mbuf_setnext
parameter_list|(
name|m
parameter_list|,
name|p
parameter_list|)
value|((m)->m_next = (p))
end_define

begin_define
define|#
directive|define
name|mbuf_pkthdr_len
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.len)
end_define

begin_define
define|#
directive|define
name|mbuf_pkthdr_setlen
parameter_list|(
name|m
parameter_list|,
name|l
parameter_list|)
value|((m)->m_pkthdr.len = (l))
end_define

begin_define
define|#
directive|define
name|mbuf_pkthdr_setrcvif
parameter_list|(
name|m
parameter_list|,
name|p
parameter_list|)
value|((m)->m_pkthdr.rcvif = (p))
end_define

begin_comment
comment|/*  * This stuff is needed by Darwin for handling the uio structure.  */
end_comment

begin_define
define|#
directive|define
name|CAST_USER_ADDR_T
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_define
define|#
directive|define
name|CAST_DOWN
parameter_list|(
name|c
parameter_list|,
name|a
parameter_list|)
value|((c) (a))
end_define

begin_define
define|#
directive|define
name|uio_uio_resid
parameter_list|(
name|p
parameter_list|)
value|((p)->uio_resid)
end_define

begin_define
define|#
directive|define
name|uio_uio_resid_add
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((p)->uio_resid += (v))
end_define

begin_define
define|#
directive|define
name|uio_uio_resid_set
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((p)->uio_resid = (v))
end_define

begin_define
define|#
directive|define
name|uio_iov_base
parameter_list|(
name|p
parameter_list|)
value|((p)->uio_iov->iov_base)
end_define

begin_define
define|#
directive|define
name|uio_iov_base_add
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|do {					\ 	char *pp;							\ 	pp = (char *)(p)->uio_iov->iov_base;				\ 	pp += (v);							\ 	(p)->uio_iov->iov_base = (void *)pp;				\     } while (0)
end_define

begin_define
define|#
directive|define
name|uio_iov_len
parameter_list|(
name|p
parameter_list|)
value|((p)->uio_iov->iov_len)
end_define

begin_define
define|#
directive|define
name|uio_iov_len_add
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|((p)->uio_iov->iov_len += (v))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NFS_NFSKPIPORT_H */
end_comment

end_unit

