begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996 - 2001 Brian Somers<brian@Awfulhak.org>  *          based on work by Toshiharu OHNO<tony-o@iij.ad.jp>  *                           Internet Initiative Japan, Inc (IIJ)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *  Definition of protocol numbers  */
end_comment

begin_define
define|#
directive|define
name|PROTO_IP
value|0x0021
end_define

begin_comment
comment|/* IP */
end_comment

begin_define
define|#
directive|define
name|PROTO_VJUNCOMP
value|0x002f
end_define

begin_comment
comment|/* VJ Uncompressed */
end_comment

begin_define
define|#
directive|define
name|PROTO_VJCOMP
value|0x002d
end_define

begin_comment
comment|/* VJ Compressed */
end_comment

begin_define
define|#
directive|define
name|PROTO_MP
value|0x003d
end_define

begin_comment
comment|/* Multilink fragment */
end_comment

begin_define
define|#
directive|define
name|PROTO_ICOMPD
value|0x00fb
end_define

begin_comment
comment|/* Individual link compressed */
end_comment

begin_define
define|#
directive|define
name|PROTO_COMPD
value|0x00fd
end_define

begin_comment
comment|/* Compressed datagram */
end_comment

begin_define
define|#
directive|define
name|PROTO_COMPRESSIBLE
parameter_list|(
name|p
parameter_list|)
value|(((p)& 0xffe1) == 0x21)
end_define

begin_define
define|#
directive|define
name|PROTO_IPCP
value|0x8021
end_define

begin_define
define|#
directive|define
name|PROTO_ICCP
value|0x80fb
end_define

begin_define
define|#
directive|define
name|PROTO_CCP
value|0x80fd
end_define

begin_define
define|#
directive|define
name|PROTO_LCP
value|0xc021
end_define

begin_define
define|#
directive|define
name|PROTO_PAP
value|0xc023
end_define

begin_define
define|#
directive|define
name|PROTO_CBCP
value|0xc029
end_define

begin_define
define|#
directive|define
name|PROTO_LQR
value|0xc025
end_define

begin_define
define|#
directive|define
name|PROTO_CHAP
value|0xc223
end_define

begin_struct_decl
struct_decl|struct
name|lcp
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|proto_WrapperOctets
parameter_list|(
name|struct
name|lcp
modifier|*
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|proto_Prepend
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|u_short
parameter_list|,
name|unsigned
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|layer
name|protolayer
decl_stmt|;
end_decl_stmt

end_unit

