begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ppp.h - PPP global declarations.  *  * Copyright (c) 1989 Carnegie Mellon University.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by Carnegie Mellon University.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PPP_H__
end_ifndef

begin_define
define|#
directive|define
name|__PPP_H__
end_define

begin_define
define|#
directive|define
name|NUM_PPP
value|1
end_define

begin_comment
comment|/* One PPP interface supported (per process) */
end_comment

begin_comment
comment|/*  * Data Link Layer header = Address, Control, Protocol.  */
end_comment

begin_define
define|#
directive|define
name|ALLSTATIONS
value|0xff
end_define

begin_comment
comment|/* All-Stations Address */
end_comment

begin_define
define|#
directive|define
name|UI
value|0x03
end_define

begin_comment
comment|/* Unnumbered Information */
end_comment

begin_define
define|#
directive|define
name|LCP
value|0xc021
end_define

begin_comment
comment|/* Link Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_IPCP
value|0x8021
end_define

begin_comment
comment|/* IP Control Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_PAP
value|0xc023
end_define

begin_comment
comment|/* User/Password Authentication Protocol */
end_comment

begin_define
define|#
directive|define
name|PPP_CHAP
value|0xc223
end_define

begin_comment
comment|/* Crytpographic Handshake Protocol */
end_comment

begin_define
define|#
directive|define
name|LQR
value|0xc025
end_define

begin_comment
comment|/* Link Quality Report protocol */
end_comment

begin_define
define|#
directive|define
name|IP_VJ_COMP
value|0x002d
end_define

begin_comment
comment|/* VJ TCP compressed IP packet */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PPP_HDRLEN
end_ifndef

begin_define
define|#
directive|define
name|PPP_HDRLEN
value|(sizeof (u_char) + sizeof (u_char) + sizeof (u_short))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MTU
value|1500
end_define

begin_comment
comment|/* Default MTU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PPP_H__ */
end_comment

end_unit

