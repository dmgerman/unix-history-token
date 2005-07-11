begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Original code by Hannes Gredler (hannes@juniper.net)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
name|_U_
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/gmpls.c,v 1.5.2.1 2005/05/19 06:44:02 guy Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<tcpdump-stdinc.h>
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_comment
comment|/* rfc3471 */
end_comment

begin_decl_stmt
name|struct
name|tok
name|gmpls_link_prot_values
index|[]
init|=
block|{
block|{
literal|0x01
block|,
literal|"Extra Traffic"
block|}
block|,
block|{
literal|0x02
block|,
literal|"Unprotected"
block|}
block|,
block|{
literal|0x04
block|,
literal|"Shared"
block|}
block|,
block|{
literal|0x08
block|,
literal|"Dedicated 1:1"
block|}
block|,
block|{
literal|0x10
block|,
literal|"Dedicated 1+1"
block|}
block|,
block|{
literal|0x20
block|,
literal|"Enhanced"
block|}
block|,
block|{
literal|0x40
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|0x80
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rfc3471 */
end_comment

begin_decl_stmt
name|struct
name|tok
name|gmpls_switch_cap_values
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|"Packet-Switch Capable-1"
block|}
block|,
block|{
literal|2
block|,
literal|"Packet-Switch Capable-2"
block|}
block|,
block|{
literal|3
block|,
literal|"Packet-Switch Capable-3"
block|}
block|,
block|{
literal|4
block|,
literal|"Packet-Switch Capable-4"
block|}
block|,
block|{
literal|51
block|,
literal|"Layer-2 Switch Capable"
block|}
block|,
block|{
literal|100
block|,
literal|"Time-Division-Multiplex"
block|}
block|,
block|{
literal|150
block|,
literal|"Lambda-Switch Capable"
block|}
block|,
block|{
literal|200
block|,
literal|"Fiber-Switch Capable"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rfc3471 */
end_comment

begin_decl_stmt
name|struct
name|tok
name|gmpls_encoding_values
index|[]
init|=
block|{
block|{
literal|1
block|,
literal|"Packet"
block|}
block|,
block|{
literal|2
block|,
literal|"Ethernet V2/DIX"
block|}
block|,
block|{
literal|3
block|,
literal|"ANSI/ETSI PDH"
block|}
block|,
block|{
literal|4
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|5
block|,
literal|"SDH ITU-T G.707/SONET ANSI T1.105"
block|}
block|,
block|{
literal|6
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|7
block|,
literal|"Digital Wrapper"
block|}
block|,
block|{
literal|8
block|,
literal|"Lambda (photonic)"
block|}
block|,
block|{
literal|9
block|,
literal|"Fiber"
block|}
block|,
block|{
literal|10
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|11
block|,
literal|"FiberChannel"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* rfc3471 */
end_comment

begin_decl_stmt
name|struct
name|tok
name|gmpls_payload_values
index|[]
init|=
block|{
block|{
literal|0
block|,
literal|"Unknown"
block|}
block|,
block|{
literal|1
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|2
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|3
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|4
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|5
block|,
literal|"Asynchronous mapping of E4"
block|}
block|,
block|{
literal|6
block|,
literal|"Asynchronous mapping of DS3/T3"
block|}
block|,
block|{
literal|7
block|,
literal|"Asynchronous mapping of E3"
block|}
block|,
block|{
literal|8
block|,
literal|"Bit synchronous mapping of E3"
block|}
block|,
block|{
literal|9
block|,
literal|"Byte synchronous mapping of E3"
block|}
block|,
block|{
literal|10
block|,
literal|"Asynchronous mapping of DS2/T2"
block|}
block|,
block|{
literal|11
block|,
literal|"Bit synchronous mapping of DS2/T2"
block|}
block|,
block|{
literal|12
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|13
block|,
literal|"Asynchronous mapping of E1"
block|}
block|,
block|{
literal|14
block|,
literal|"Byte synchronous mapping of E1"
block|}
block|,
block|{
literal|15
block|,
literal|"Byte synchronous mapping of 31 * DS0"
block|}
block|,
block|{
literal|16
block|,
literal|"Asynchronous mapping of DS1/T1"
block|}
block|,
block|{
literal|17
block|,
literal|"Bit synchronous mapping of DS1/T1"
block|}
block|,
block|{
literal|18
block|,
literal|"Byte synchronous mapping of DS1/T1"
block|}
block|,
block|{
literal|19
block|,
literal|"VC-11 in VC-12"
block|}
block|,
block|{
literal|20
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|21
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|22
block|,
literal|"DS1 SF Asynchronous"
block|}
block|,
block|{
literal|23
block|,
literal|"DS1 ESF Asynchronous"
block|}
block|,
block|{
literal|24
block|,
literal|"DS3 M23 Asynchronous"
block|}
block|,
block|{
literal|25
block|,
literal|"DS3 C-Bit Parity Asynchronous"
block|}
block|,
block|{
literal|26
block|,
literal|"VT/LOVC"
block|}
block|,
block|{
literal|27
block|,
literal|"STS SPE/HOVC"
block|}
block|,
block|{
literal|28
block|,
literal|"POS - No Scrambling, 16 bit CRC"
block|}
block|,
block|{
literal|29
block|,
literal|"POS - No Scrambling, 32 bit CRC"
block|}
block|,
block|{
literal|30
block|,
literal|"POS - Scrambling, 16 bit CRC"
block|}
block|,
block|{
literal|31
block|,
literal|"POS - Scrambling, 32 bit CRC"
block|}
block|,
block|{
literal|32
block|,
literal|"ATM mapping"
block|}
block|,
block|{
literal|33
block|,
literal|"Ethernet PHY"
block|}
block|,
block|{
literal|34
block|,
literal|"SONET/SDH"
block|}
block|,
block|{
literal|35
block|,
literal|"Reserved (SONET deprecated)"
block|}
block|,
block|{
literal|36
block|,
literal|"Digital Wrapper"
block|}
block|,
block|{
literal|37
block|,
literal|"Lambda"
block|}
block|,
block|{
literal|38
block|,
literal|"ANSI/ETSI PDH"
block|}
block|,
block|{
literal|39
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|40
block|,
literal|"Link Access Protocol SDH (X.85 and X.86)"
block|}
block|,
block|{
literal|41
block|,
literal|"FDDI"
block|}
block|,
block|{
literal|42
block|,
literal|"DQDB (ETSI ETS 300 216)"
block|}
block|,
block|{
literal|43
block|,
literal|"FiberChannel-3 (Services)"
block|}
block|,
block|{
literal|44
block|,
literal|"HDLC"
block|}
block|,
block|{
literal|45
block|,
literal|"Ethernet V2/DIX (only)"
block|}
block|,
block|{
literal|46
block|,
literal|"Ethernet 802.3 (only)"
block|}
block|,
comment|/* draft-ietf-ccamp-gmpls-g709-04.txt */
block|{
literal|47
block|,
literal|"G.709 ODUj"
block|}
block|,
block|{
literal|48
block|,
literal|"G.709 OTUk(v)"
block|}
block|,
block|{
literal|49
block|,
literal|"CBR/CBRa"
block|}
block|,
block|{
literal|50
block|,
literal|"CBRb"
block|}
block|,
block|{
literal|51
block|,
literal|"BSOT"
block|}
block|,
block|{
literal|52
block|,
literal|"BSNT"
block|}
block|,
block|{
literal|53
block|,
literal|"IP/PPP (GFP)"
block|}
block|,
block|{
literal|54
block|,
literal|"Ethernet MAC (framed GFP)"
block|}
block|,
block|{
literal|55
block|,
literal|"Ethernet PHY (transparent GFP)"
block|}
block|,
block|{
literal|56
block|,
literal|"ESCON"
block|}
block|,
block|{
literal|57
block|,
literal|"FICON"
block|}
block|,
block|{
literal|58
block|,
literal|"Fiber Channel"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Link Type values used by LMP Service Discovery (specifically, the Client   * Port Service Attributes Object). See UNI 1.0 section 9.4.2 for details.  */
end_comment

begin_decl_stmt
name|struct
name|tok
name|lmp_sd_service_config_cpsa_link_type_values
index|[]
init|=
block|{
block|{
literal|5
block|,
literal|"SDH ITU-T G.707"
block|}
block|,
block|{
literal|6
block|,
literal|"SONET ANSI T1.105"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Signal Type values for SDH links used by LMP Service Discovery (specifically,   * the Client Port Service Attributes Object). See UNI 1.0 section 9.4.2 for   * details.  */
end_comment

begin_decl_stmt
name|struct
name|tok
name|lmp_sd_service_config_cpsa_signal_type_sdh_values
index|[]
init|=
block|{
block|{
literal|5
block|,
literal|"VC-3"
block|}
block|,
block|{
literal|6
block|,
literal|"VC-4"
block|}
block|,
block|{
literal|7
block|,
literal|"STM-0"
block|}
block|,
block|{
literal|8
block|,
literal|"STM-1"
block|}
block|,
block|{
literal|9
block|,
literal|"STM-4"
block|}
block|,
block|{
literal|10
block|,
literal|"STM-16"
block|}
block|,
block|{
literal|11
block|,
literal|"STM-64"
block|}
block|,
block|{
literal|12
block|,
literal|"STM-256"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * Signal Type values for SONET links used by LMP Service Discovery (specifically,   * the Client Port Service Attributes Object). See UNI 1.0 section 9.4.2 for   * details.  */
end_comment

begin_decl_stmt
name|struct
name|tok
name|lmp_sd_service_config_cpsa_signal_type_sonet_values
index|[]
init|=
block|{
block|{
literal|5
block|,
literal|"STS-1 SPE"
block|}
block|,
block|{
literal|6
block|,
literal|"STS-3c SPE"
block|}
block|,
block|{
literal|7
block|,
literal|"STS-1"
block|}
block|,
block|{
literal|8
block|,
literal|"STM-3"
block|}
block|,
block|{
literal|9
block|,
literal|"STM-12"
block|}
block|,
block|{
literal|10
block|,
literal|"STM-48"
block|}
block|,
block|{
literal|11
block|,
literal|"STM-192"
block|}
block|,
block|{
literal|12
block|,
literal|"STM-768"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DIFFSERV_BC_MODEL_RDM
value|0
end_define

begin_comment
comment|/* draft-ietf-tewg-diff-te-proto-07 */
end_comment

begin_define
define|#
directive|define
name|DIFFSERV_BC_MODEL_MAM
value|1
end_define

begin_comment
comment|/* draft-ietf-tewg-diff-te-proto-07 */
end_comment

begin_define
define|#
directive|define
name|DIFFSERV_BC_MODEL_EXTD_MAM
value|254
end_define

begin_comment
comment|/* experimental */
end_comment

begin_decl_stmt
name|struct
name|tok
name|diffserv_te_bc_values
index|[]
init|=
block|{
block|{
name|DIFFSERV_BC_MODEL_RDM
block|,
literal|"Russian dolls"
block|}
block|,
block|{
name|DIFFSERV_BC_MODEL_MAM
block|,
literal|"Maximum allocation"
block|}
block|,
block|{
name|DIFFSERV_BC_MODEL_EXTD_MAM
block|,
literal|"Maximum allocation with E-LSP support"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

