begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/nlpid.h,v 1.4 2004/10/19 15:27:55 hannes Exp $ (LBL) */
end_comment

begin_comment
comment|/*   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Original code by Hannes Gredler (hannes@juniper.net)  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tok
name|nlpid_values
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NLPID_NULLNS
value|0x00
end_define

begin_define
define|#
directive|define
name|NLPID_Q933
value|0x08
end_define

begin_comment
comment|/* ANSI T1.617 Annex D or ITU-T Q.933 Annex A */
end_comment

begin_define
define|#
directive|define
name|NLPID_LMI
value|0x09
end_define

begin_comment
comment|/* The original, aka Cisco, aka Gang of Four */
end_comment

begin_define
define|#
directive|define
name|NLPID_SNAP
value|0x80
end_define

begin_define
define|#
directive|define
name|NLPID_CLNP
value|0x81
end_define

begin_comment
comment|/* iso9577 */
end_comment

begin_define
define|#
directive|define
name|NLPID_ESIS
value|0x82
end_define

begin_comment
comment|/* iso9577 */
end_comment

begin_define
define|#
directive|define
name|NLPID_ISIS
value|0x83
end_define

begin_comment
comment|/* iso9577 */
end_comment

begin_define
define|#
directive|define
name|NLPID_CONS
value|0x84
end_define

begin_define
define|#
directive|define
name|NLPID_IDRP
value|0x85
end_define

begin_define
define|#
directive|define
name|NLPID_MFR
value|0xb1
end_define

begin_comment
comment|/* FRF.15 */
end_comment

begin_define
define|#
directive|define
name|NLPID_IP
value|0xcc
end_define

begin_define
define|#
directive|define
name|NLPID_PPP
value|0xcf
end_define

begin_define
define|#
directive|define
name|NLPID_X25_ESIS
value|0x8a
end_define

begin_define
define|#
directive|define
name|NLPID_IP6
value|0x8e
end_define

end_unit

