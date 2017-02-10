begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Original code by Hannes Gredler (hannes@juniper.net)  */
end_comment

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
file|<netdissect-stdinc.h>
end_include

begin_include
include|#
directive|include
file|"netdissect.h"
end_include

begin_include
include|#
directive|include
file|"l2vpn.h"
end_include

begin_comment
comment|/*  * BGP Layer 2 Encapsulation Types  *  * RFC 6624  *  * http://www.iana.org/assignments/bgp-parameters/bgp-parameters.xhtml#bgp-l2-encapsulation-types-registry  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|tok
name|l2vpn_encaps_values
index|[]
init|=
block|{
block|{
literal|0
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|1
block|,
literal|"Frame Relay"
block|}
block|,
block|{
literal|2
block|,
literal|"ATM AAL5 SDU VCC transport"
block|}
block|,
block|{
literal|3
block|,
literal|"ATM transparent cell transport"
block|}
block|,
block|{
literal|4
block|,
literal|"Ethernet (VLAN) Tagged Mode"
block|}
block|,
block|{
literal|5
block|,
literal|"Ethernet Raw Mode"
block|}
block|,
block|{
literal|6
block|,
literal|"Cisco HDLC"
block|}
block|,
block|{
literal|7
block|,
literal|"PPP"
block|}
block|,
block|{
literal|8
block|,
literal|"SONET/SDH Circuit Emulation Service over MPLS"
block|}
block|,
block|{
literal|9
block|,
literal|"ATM n-to-one VCC cell transport"
block|}
block|,
block|{
literal|10
block|,
literal|"ATM n-to-one VPC cell transport"
block|}
block|,
block|{
literal|11
block|,
literal|"IP layer 2 transport"
block|}
block|,
block|{
literal|15
block|,
literal|"Frame Relay Port mode"
block|}
block|,
block|{
literal|17
block|,
literal|"Structure-agnostic E1 over packet"
block|}
block|,
block|{
literal|18
block|,
literal|"Structure-agnostic T1 (DS1) over packet"
block|}
block|,
block|{
literal|19
block|,
literal|"VPLS"
block|}
block|,
block|{
literal|20
block|,
literal|"Structure-agnostic T3 (DS3) over packet"
block|}
block|,
block|{
literal|21
block|,
literal|"Nx64kbit/s Basic Service using Structure-aware"
block|}
block|,
block|{
literal|25
block|,
literal|"Frame Relay DLCI"
block|}
block|,
block|{
literal|40
block|,
literal|"Structure-agnostic E3 over packet"
block|}
block|,
block|{
literal|41
block|,
literal|"Octet-aligned playload for Structure-agnostic DS1 circuits"
block|}
block|,
block|{
literal|42
block|,
literal|"E1 Nx64kbit/s with CAS using Structure-aware"
block|}
block|,
block|{
literal|43
block|,
literal|"DS1 (ESF) Nx64kbit/s with CAS using Structure-aware"
block|}
block|,
block|{
literal|44
block|,
literal|"DS1 (SF) Nx64kbit/s with CAS using Structure-aware"
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
comment|/*  * MPLS Pseudowire Types  *  * RFC 4446  *  * http://www.iana.org/assignments/pwe3-parameters/pwe3-parameters.xhtml#pwe3-parameters-2  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|tok
name|mpls_pw_types_values
index|[]
init|=
block|{
block|{
literal|0x0000
block|,
literal|"Reserved"
block|}
block|,
block|{
literal|0x0001
block|,
literal|"Frame Relay DLCI (Martini Mode)"
block|}
block|,
block|{
literal|0x0002
block|,
literal|"ATM AAL5 SDU VCC transport"
block|}
block|,
block|{
literal|0x0003
block|,
literal|"ATM transparent cell transport"
block|}
block|,
block|{
literal|0x0004
block|,
literal|"Ethernet VLAN"
block|}
block|,
block|{
literal|0x0005
block|,
literal|"Ethernet"
block|}
block|,
block|{
literal|0x0006
block|,
literal|"Cisco-HDLC"
block|}
block|,
block|{
literal|0x0007
block|,
literal|"PPP"
block|}
block|,
block|{
literal|0x0008
block|,
literal|"SONET/SDH Circuit Emulation Service over MPLS"
block|}
block|,
block|{
literal|0x0009
block|,
literal|"ATM n-to-one VCC cell transport"
block|}
block|,
block|{
literal|0x000a
block|,
literal|"ATM n-to-one VPC cell transport"
block|}
block|,
block|{
literal|0x000b
block|,
literal|"IP Layer2 Transport"
block|}
block|,
block|{
literal|0x000c
block|,
literal|"ATM one-to-one VCC Cell Mode"
block|}
block|,
block|{
literal|0x000d
block|,
literal|"ATM one-to-one VPC Cell Mode"
block|}
block|,
block|{
literal|0x000e
block|,
literal|"ATM AAL5 PDU VCC transport"
block|}
block|,
block|{
literal|0x000f
block|,
literal|"Frame-Relay Port mode"
block|}
block|,
block|{
literal|0x0010
block|,
literal|"SONET/SDH Circuit Emulation over Packet"
block|}
block|,
block|{
literal|0x0011
block|,
literal|"Structure-agnostic E1 over Packet"
block|}
block|,
block|{
literal|0x0012
block|,
literal|"Structure-agnostic T1 (DS1) over Packet"
block|}
block|,
block|{
literal|0x0013
block|,
literal|"Structure-agnostic E3 over Packet"
block|}
block|,
block|{
literal|0x0014
block|,
literal|"Structure-agnostic T3 (DS3) over Packet"
block|}
block|,
block|{
literal|0x0015
block|,
literal|"CESoPSN basic mode"
block|}
block|,
block|{
literal|0x0016
block|,
literal|"TDMoIP basic mode"
block|}
block|,
block|{
literal|0x0017
block|,
literal|"CESoPSN TDM with CAS"
block|}
block|,
block|{
literal|0x0018
block|,
literal|"TDMoIP TDM with CAS"
block|}
block|,
block|{
literal|0x0019
block|,
literal|"Frame Relay DLCI"
block|}
block|,
block|{
literal|0x0040
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

