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
literal|"@(#) $Header: /tcpdump/master/tcpdump/l2vpn.c,v 1.1 2004/06/15 09:42:40 hannes Exp $ (LBL)"
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

begin_include
include|#
directive|include
file|"l2vpn.h"
end_include

begin_comment
comment|/* draft-ietf-pwe3-iana-allocation-04 */
end_comment

begin_decl_stmt
name|struct
name|tok
name|l2vpn_encaps_values
index|[]
init|=
block|{
block|{
literal|0x00
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|0x01
block|,
literal|"Frame Relay"
block|}
block|,
block|{
literal|0x02
block|,
literal|"ATM AAL5 VCC transport"
block|}
block|,
block|{
literal|0x03
block|,
literal|"ATM transparent cell transport"
block|}
block|,
block|{
literal|0x04
block|,
literal|"Ethernet VLAN"
block|}
block|,
block|{
literal|0x05
block|,
literal|"Ethernet"
block|}
block|,
block|{
literal|0x06
block|,
literal|"Cisco-HDLC"
block|}
block|,
block|{
literal|0x07
block|,
literal|"PPP"
block|}
block|,
block|{
literal|0x08
block|,
literal|"SONET/SDH Circuit Emulation Service over MPLS"
block|}
block|,
block|{
literal|0x09
block|,
literal|"ATM n-to-one VCC cell transport"
block|}
block|,
block|{
literal|0x0a
block|,
literal|"ATM n-to-one VPC cell transport"
block|}
block|,
block|{
literal|0x0b
block|,
literal|"IP Layer2 Transport"
block|}
block|,
block|{
literal|0x0c
block|,
literal|"ATM one-to-one VCC Cell Mode"
block|}
block|,
block|{
literal|0x0d
block|,
literal|"ATM one-to-one VPC Cell Mode"
block|}
block|,
block|{
literal|0x0e
block|,
literal|"ATM AAL5 PDU VCC transport"
block|}
block|,
block|{
literal|0x0f
block|,
literal|"Frame-Relay Port mode"
block|}
block|,
block|{
literal|0x10
block|,
literal|"SONET/SDH Circuit Emulation over Packet"
block|}
block|,
block|{
literal|0x11
block|,
literal|"Structure-agnostic E1 over Packet"
block|}
block|,
block|{
literal|0x12
block|,
literal|"Structure-agnostic T1 (DS1) over Packet"
block|}
block|,
block|{
literal|0x13
block|,
literal|"Structure-agnostic E3 over Packet"
block|}
block|,
block|{
literal|0x14
block|,
literal|"Structure-agnostic T3 (DS3) over Packet"
block|}
block|,
block|{
literal|0x15
block|,
literal|"CESoPSN basic mode"
block|}
block|,
block|{
literal|0x16
block|,
literal|"TDMoIP basic mode"
block|}
block|,
block|{
literal|0x17
block|,
literal|"CESoPSN TDM with CAS"
block|}
block|,
block|{
literal|0x18
block|,
literal|"TDMoIP TDM with CAS"
block|}
block|,
block|{
literal|0x40
block|,
literal|"IP-interworking"
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

