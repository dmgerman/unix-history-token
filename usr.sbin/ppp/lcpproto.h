begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	    Written by Toshiharu OHNO (tony-o@iij.ad.jp)  *  *   Copyright (C) 1993, Internet Initiative Japan, Inc. All rights reserverd.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the Internet Initiative Japan.  The name of the  * IIJ may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $Id: lcpproto.h,v 1.4.6.2 1997/08/25 00:34:30 brian Exp $  *  *	TODO:  */
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

end_unit

