begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/oui.h,v 1.3 2005/04/06 20:13:13 hannes Exp $ (LBL) */
end_comment

begin_comment
comment|/*   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Original code by Hannes Gredler (hannes@juniper.net)  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tok
name|oui_values
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tok
name|smi_values
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|OUI_ENCAP_ETHER
value|0x000000
end_define

begin_comment
comment|/* encapsulated Ethernet */
end_comment

begin_define
define|#
directive|define
name|OUI_CISCO
value|0x00000c
end_define

begin_comment
comment|/* Cisco protocols */
end_comment

begin_define
define|#
directive|define
name|OUI_CISCO_90
value|0x0000f8
end_define

begin_comment
comment|/* Cisco bridging */
end_comment

begin_define
define|#
directive|define
name|OUI_RFC2684
value|0x0080c2
end_define

begin_comment
comment|/* RFC 2684 bridged Ethernet */
end_comment

begin_define
define|#
directive|define
name|OUI_APPLETALK
value|0x080007
end_define

begin_comment
comment|/* Appletalk */
end_comment

begin_define
define|#
directive|define
name|OUI_JUNIPER
value|0x009069
end_define

begin_comment
comment|/* Juniper */
end_comment

begin_define
define|#
directive|define
name|SMI_ACC
value|5
end_define

begin_define
define|#
directive|define
name|SMI_CISCO
value|9
end_define

begin_define
define|#
directive|define
name|SMI_SHIVA
value|166
end_define

begin_define
define|#
directive|define
name|SMI_LIVINGSTON
value|307
end_define

begin_define
define|#
directive|define
name|SMI_MICROSOFT
value|311
end_define

begin_define
define|#
directive|define
name|SMI_3COM
value|429
end_define

begin_define
define|#
directive|define
name|SMI_ASCEND
value|529
end_define

begin_define
define|#
directive|define
name|SMI_BAY
value|1584
end_define

begin_define
define|#
directive|define
name|SMI_FOUNDRY
value|1991
end_define

begin_define
define|#
directive|define
name|SMI_VERSANET
value|2180
end_define

begin_define
define|#
directive|define
name|SMI_REDBACK
value|2352
end_define

begin_define
define|#
directive|define
name|SMI_JUNIPER
value|2636
end_define

begin_define
define|#
directive|define
name|SMI_APTIS
value|2637
end_define

begin_define
define|#
directive|define
name|SMI_COSINE
value|3085
end_define

begin_define
define|#
directive|define
name|SMI_SHASTA
value|3199
end_define

begin_define
define|#
directive|define
name|SMI_NOMADIX
value|3309
end_define

begin_define
define|#
directive|define
name|SMI_UNISPHERE
value|4874
end_define

begin_define
define|#
directive|define
name|SMI_ISSANNI
value|5948
end_define

begin_define
define|#
directive|define
name|SMI_QUINTUM
value|6618
end_define

begin_define
define|#
directive|define
name|SMI_COLUBRIS
value|8744
end_define

begin_define
define|#
directive|define
name|SMI_COLUMBIA_UNIVERSITY
value|11862
end_define

begin_define
define|#
directive|define
name|SMI_THE3GPP
value|10415
end_define

end_unit

