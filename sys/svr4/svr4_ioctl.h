begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_IOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_IOCTL_H_
end_define

begin_define
define|#
directive|define
name|SVR4_IOC_VOID
value|0x20000000
end_define

begin_define
define|#
directive|define
name|SVR4_IOC_OUT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SVR4_IOC_IN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SVR4_IOC_INOUT
value|(SVR4_IOC_IN|SVR4_IOC_OUT)
end_define

begin_define
define|#
directive|define
name|SVR4_IOC
parameter_list|(
name|inout
parameter_list|,
name|group
parameter_list|,
name|num
parameter_list|,
name|len
parameter_list|)
define|\
value|(inout | ((len& 0xff)<< 16) | ((group)<< 8) | (num))
end_define

begin_define
define|#
directive|define
name|SVR4_XIOC
value|('X'<< 8)
end_define

begin_define
define|#
directive|define
name|SVR4_IO
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|)
value|SVR4_IOC(SVR4_IOC_VOID,	(g), (n), 0)
end_define

begin_define
define|#
directive|define
name|SVR4_IOR
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|SVR4_IOC(SVR4_IOC_OUT,	(g), (n), sizeof(t))
end_define

begin_define
define|#
directive|define
name|SVR4_IOW
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|SVR4_IOC(SVR4_IOC_IN,	(g), (n), sizeof(t))
end_define

begin_define
define|#
directive|define
name|SVR4_IOWR
parameter_list|(
name|g
parameter_list|,
name|n
parameter_list|,
name|t
parameter_list|)
value|SVR4_IOC(SVR4_IOC_INOUT,(g), (n), sizeof(t))
end_define

begin_decl_stmt
name|int
name|svr4_stream_ti_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
name|register_t
operator|*
operator|,
name|int
operator|,
name|u_long
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svr4_stream_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
name|register_t
operator|*
operator|,
name|int
operator|,
name|u_long
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svr4_term_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
name|register_t
operator|*
operator|,
name|int
operator|,
name|u_long
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svr4_ttold_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
name|register_t
operator|*
operator|,
name|int
operator|,
name|u_long
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svr4_fil_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
name|register_t
operator|*
operator|,
name|int
operator|,
name|u_long
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|svr4_sock_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|file
operator|*
operator|,
expr|struct
name|proc
operator|*
operator|,
name|register_t
operator|*
operator|,
name|int
operator|,
name|u_long
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_IOCTL_H_ */
end_comment

end_unit

