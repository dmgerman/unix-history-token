begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: lcpproto.h,v 1.7 1997/06/09 03:27:25 brian Exp $  *  *	TODO:  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LCPPROTO_H_
end_ifndef

begin_define
define|#
directive|define
name|_LCPPROTO_H_
end_define

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
name|PROTO_LQR
value|0xc025
end_define

begin_define
define|#
directive|define
name|PROTO_CHAP
value|0xc223
end_define

begin_function_decl
specifier|extern
name|void
name|LcpInput
parameter_list|(
name|struct
name|mbuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|PapInput
parameter_list|(
name|struct
name|mbuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LqpInput
parameter_list|(
name|struct
name|mbuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ChapInput
parameter_list|(
name|struct
name|mbuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IpInput
parameter_list|(
name|struct
name|mbuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|VjCompInput
parameter_list|(
name|struct
name|mbuf
modifier|*
name|bp
parameter_list|,
name|int
name|proto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IpcpInput
parameter_list|(
name|struct
name|mbuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LqrInput
parameter_list|(
name|struct
name|mbuf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

