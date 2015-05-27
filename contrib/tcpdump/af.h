begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998-2006 The TCPDUMP project  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Original code by Hannes Gredler (hannes@juniper.net)  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|af_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|bsd_af_values
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RFC1700 address family numbers */
end_comment

begin_define
define|#
directive|define
name|AFNUM_INET
value|1
end_define

begin_define
define|#
directive|define
name|AFNUM_INET6
value|2
end_define

begin_define
define|#
directive|define
name|AFNUM_NSAP
value|3
end_define

begin_define
define|#
directive|define
name|AFNUM_HDLC
value|4
end_define

begin_define
define|#
directive|define
name|AFNUM_BBN1822
value|5
end_define

begin_define
define|#
directive|define
name|AFNUM_802
value|6
end_define

begin_define
define|#
directive|define
name|AFNUM_E163
value|7
end_define

begin_define
define|#
directive|define
name|AFNUM_E164
value|8
end_define

begin_define
define|#
directive|define
name|AFNUM_F69
value|9
end_define

begin_define
define|#
directive|define
name|AFNUM_X121
value|10
end_define

begin_define
define|#
directive|define
name|AFNUM_IPX
value|11
end_define

begin_define
define|#
directive|define
name|AFNUM_ATALK
value|12
end_define

begin_define
define|#
directive|define
name|AFNUM_DECNET
value|13
end_define

begin_define
define|#
directive|define
name|AFNUM_BANYAN
value|14
end_define

begin_define
define|#
directive|define
name|AFNUM_E164NSAP
value|15
end_define

begin_define
define|#
directive|define
name|AFNUM_VPLS
value|25
end_define

begin_comment
comment|/* draft-kompella-ppvpn-l2vpn */
end_comment

begin_define
define|#
directive|define
name|AFNUM_L2VPN
value|196
end_define

begin_comment
comment|/* still to be approved by IANA */
end_comment

begin_comment
comment|/*  * BSD AF_ values.  *  * Unfortunately, the BSDs don't all use the same value for AF_INET6,  * so, because we want to be able to read captures from all of the BSDs,  * we check for all of them.  */
end_comment

begin_define
define|#
directive|define
name|BSD_AFNUM_INET
value|2
end_define

begin_define
define|#
directive|define
name|BSD_AFNUM_NS
value|6
end_define

begin_comment
comment|/* XEROX NS protocols */
end_comment

begin_define
define|#
directive|define
name|BSD_AFNUM_ISO
value|7
end_define

begin_define
define|#
directive|define
name|BSD_AFNUM_APPLETALK
value|16
end_define

begin_define
define|#
directive|define
name|BSD_AFNUM_IPX
value|23
end_define

begin_define
define|#
directive|define
name|BSD_AFNUM_INET6_BSD
value|24
end_define

begin_comment
comment|/* OpenBSD (and probably NetBSD), BSD/OS */
end_comment

begin_define
define|#
directive|define
name|BSD_AFNUM_INET6_FREEBSD
value|28
end_define

begin_define
define|#
directive|define
name|BSD_AFNUM_INET6_DARWIN
value|30
end_define

end_unit

