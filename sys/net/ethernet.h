begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Fundamental constants relating to ethernet.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_ETHERNET_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_ETHERNET_H_
end_define

begin_comment
comment|/*  * Somce basic Ethernet constants.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_ADDR_LEN
value|6
end_define

begin_comment
comment|/* length of an Ethernet address */
end_comment

begin_define
define|#
directive|define
name|ETHER_TYPE_LEN
value|2
end_define

begin_comment
comment|/* length of the Ethernet type field */
end_comment

begin_define
define|#
directive|define
name|ETHER_CRC_LEN
value|4
end_define

begin_comment
comment|/* length of the Ethernet CRC */
end_comment

begin_define
define|#
directive|define
name|ETHER_HDR_LEN
value|(ETHER_ADDR_LEN*2+ETHER_TYPE_LEN)
end_define

begin_define
define|#
directive|define
name|ETHER_MIN_LEN
value|64
end_define

begin_comment
comment|/* minimum frame len, including CRC */
end_comment

begin_define
define|#
directive|define
name|ETHER_MAX_LEN
value|1518
end_define

begin_comment
comment|/* maximum frame len, including CRC */
end_comment

begin_define
define|#
directive|define
name|ETHER_MAX_LEN_JUMBO
value|9018
end_define

begin_comment
comment|/* max jumbo frame len, including CRC */
end_comment

begin_define
define|#
directive|define
name|ETHER_VLAN_ENCAP_LEN
value|4
end_define

begin_comment
comment|/* len of 802.1Q VLAN encapsulation */
end_comment

begin_comment
comment|/*  * Mbuf adjust factor to force 32-bit alignment of IP header.  * Drivers should do m_adj(m, ETHER_ALIGN) when setting up a  * receive so the upper layers get the IP header properly aligned  * past the 14-byte Ethernet header.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

begin_comment
comment|/* driver adjust for IP hdr alignment */
end_comment

begin_comment
comment|/*  * Compute the maximum frame size based on ethertype (i.e. possible  * encapsulation) and whether or not an FCS is present.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_MAX_FRAME
parameter_list|(
name|ifp
parameter_list|,
name|etype
parameter_list|,
name|hasfcs
parameter_list|)
define|\
value|((ifp)->if_mtu + ETHER_HDR_LEN +				\ 	 ((hasfcs) ? ETHER_CRC_LEN : 0) +				\ 	 (((etype) == ETHERTYPE_VLAN) ? ETHER_VLAN_ENCAP_LEN : 0))
end_define

begin_comment
comment|/*  * Ethernet-specific mbuf flags.  */
end_comment

begin_define
define|#
directive|define
name|M_HASFCS
value|M_PROTO5
end_define

begin_comment
comment|/* FCS included at end of frame */
end_comment

begin_comment
comment|/*  * Ethernet CRC32 polynomials (big- and little-endian verions).  */
end_comment

begin_define
define|#
directive|define
name|ETHER_CRC_POLY_LE
value|0xedb88320
end_define

begin_define
define|#
directive|define
name|ETHER_CRC_POLY_BE
value|0x04c11db6
end_define

begin_comment
comment|/*  * A macro to validate a length with  */
end_comment

begin_define
define|#
directive|define
name|ETHER_IS_VALID_LEN
parameter_list|(
name|foo
parameter_list|)
define|\
value|((foo)>= ETHER_MIN_LEN&& (foo)<= ETHER_MAX_LEN)
end_define

begin_comment
comment|/*  * Structure of a 10Mb/s Ethernet header.  */
end_comment

begin_struct
struct|struct
name|ether_header
block|{
name|u_char
name|ether_dhost
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_char
name|ether_shost
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_short
name|ether_type
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * Structure of a 48-bit Ethernet address.  */
end_comment

begin_struct
struct|struct
name|ether_addr
block|{
name|u_char
name|octet
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CTASSERT
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|ether_header
argument_list|)
operator|==
name|ETHER_ADDR_LEN
operator|*
literal|2
operator|+
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|ether_addr
argument_list|)
operator|==
name|ETHER_ADDR_LEN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ETHER_IS_MULTICAST
parameter_list|(
name|addr
parameter_list|)
value|(*(addr)& 0x01)
end_define

begin_comment
comment|/* is address mcast/bcast? */
end_comment

begin_comment
comment|/*  *  NOTE: 0x0000-0x05DC (0..1500) are generally IEEE 802.3 length fields.  *  However, there are some conflicts.  */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_8023
value|0x0004
end_define

begin_comment
comment|/* IEEE 802.3 packet */
end_comment

begin_comment
comment|/* 0x0101 .. 0x1FF	   Experimental */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PUP
value|0x0200
end_define

begin_comment
comment|/* Xerox PUP protocol - see 0A00 */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PUPAT
value|0x0200
end_define

begin_comment
comment|/* PUP Address Translation - see 0A01 */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SPRITE
value|0x0500
end_define

begin_comment
comment|/* ??? */
end_comment

begin_comment
comment|/* 0x0400	   Nixdorf */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NS
value|0x0600
end_define

begin_comment
comment|/* XNS */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NSAT
value|0x0601
end_define

begin_comment
comment|/* XNS Address Translation (3Mb only) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DLOG1
value|0x0660
end_define

begin_comment
comment|/* DLOG (?) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DLOG2
value|0x0661
end_define

begin_comment
comment|/* DLOG (?) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IP
value|0x0800
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_X75
value|0x0801
end_define

begin_comment
comment|/* X.75 Internet */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBS
value|0x0802
end_define

begin_comment
comment|/* NBS Internet */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ECMA
value|0x0803
end_define

begin_comment
comment|/* ECMA Internet */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_CHAOS
value|0x0804
end_define

begin_comment
comment|/* CHAOSnet */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_X25
value|0x0805
end_define

begin_comment
comment|/* X.25 Level 3 */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ARP
value|0x0806
end_define

begin_comment
comment|/* Address resolution protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NSCOMPAT
value|0x0807
end_define

begin_comment
comment|/* XNS Compatibility */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_FRARP
value|0x0808
end_define

begin_comment
comment|/* Frame Relay ARP (RFC1701) */
end_comment

begin_comment
comment|/* 0x081C	   Symbolics Private */
end_comment

begin_comment
comment|/* 0x0888 - 0x088A	   Xyplex */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_UBDEBUG
value|0x0900
end_define

begin_comment
comment|/* Ungermann-Bass network debugger */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IEEEPUP
value|0x0A00
end_define

begin_comment
comment|/* Xerox IEEE802.3 PUP */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IEEEPUPAT
value|0x0A01
end_define

begin_comment
comment|/* Xerox IEEE802.3 PUP Address Translation */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VINES
value|0x0BAD
end_define

begin_comment
comment|/* Banyan VINES */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VINESLOOP
value|0x0BAE
end_define

begin_comment
comment|/* Banyan VINES Loopback */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VINESECHO
value|0x0BAF
end_define

begin_comment
comment|/* Banyan VINES Echo */
end_comment

begin_comment
comment|/*		       0x1000 - 0x100F	   Berkeley Trailer */
end_comment

begin_comment
comment|/*  * The ETHERTYPE_NTRAILER packet types starting at ETHERTYPE_TRAIL have  * (type-ETHERTYPE_TRAIL)*512 bytes of data followed  * by an ETHER type (as given above) and then the (variable-length) header.  */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_TRAIL
value|0x1000
end_define

begin_comment
comment|/* Trailer packet */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NTRAILER
value|16
end_define

begin_define
define|#
directive|define
name|ETHERTYPE_DCA
value|0x1234
end_define

begin_comment
comment|/* DCA - Multicast */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VALID
value|0x1600
end_define

begin_comment
comment|/* VALID system protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DOGFIGHT
value|0x1989
end_define

begin_comment
comment|/* Artificial Horizons ("Aviator" dogfight simulator [on Sun]) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_RCL
value|0x1995
end_define

begin_comment
comment|/* Datapoint Corporation (RCL lan protocol) */
end_comment

begin_comment
comment|/* The following 3C0x types 					   are unregistered: */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPVCD
value|0x3C00
end_define

begin_comment
comment|/* 3Com NBP virtual circuit datagram (like XNS SPP) not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPSCD
value|0x3C01
end_define

begin_comment
comment|/* 3Com NBP System control datagram not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPCREQ
value|0x3C02
end_define

begin_comment
comment|/* 3Com NBP Connect request (virtual cct) not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPCRSP
value|0x3C03
end_define

begin_comment
comment|/* 3Com NBP Connect repsonse not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPCC
value|0x3C04
end_define

begin_comment
comment|/* 3Com NBP Connect complete not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPCLREQ
value|0x3C05
end_define

begin_comment
comment|/* 3Com NBP Close request (virtual cct) not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPCLRSP
value|0x3C06
end_define

begin_comment
comment|/* 3Com NBP Close response not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPDG
value|0x3C07
end_define

begin_comment
comment|/* 3Com NBP Datagram (like XNS IDP) not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPDGB
value|0x3C08
end_define

begin_comment
comment|/* 3Com NBP Datagram broadcast not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPCLAIM
value|0x3C09
end_define

begin_comment
comment|/* 3Com NBP Claim NetBIOS name not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPDLTE
value|0x3C0A
end_define

begin_comment
comment|/* 3Com NBP Delete Netbios name not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPRAS
value|0x3C0B
end_define

begin_comment
comment|/* 3Com NBP Remote adaptor status request not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPRAR
value|0x3C0C
end_define

begin_comment
comment|/* 3Com NBP Remote adaptor response not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NBPRST
value|0x3C0D
end_define

begin_comment
comment|/* 3Com NBP Reset not registered */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PCS
value|0x4242
end_define

begin_comment
comment|/* PCS Basic Block Protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IMLBLDIAG
value|0x424C
end_define

begin_comment
comment|/* Information Modes Little Big LAN diagnostic */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DIDDLE
value|0x4321
end_define

begin_comment
comment|/* THD - Diddle */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IMLBL
value|0x4C42
end_define

begin_comment
comment|/* Information Modes Little Big LAN */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SIMNET
value|0x5208
end_define

begin_comment
comment|/* BBN Simnet Private */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DECEXPER
value|0x6000
end_define

begin_comment
comment|/* DEC Unassigned, experimental */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_MOPDL
value|0x6001
end_define

begin_comment
comment|/* DEC MOP dump/load */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_MOPRC
value|0x6002
end_define

begin_comment
comment|/* DEC MOP remote console */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DECnet
value|0x6003
end_define

begin_comment
comment|/* DEC DECNET Phase IV route */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DN
value|ETHERTYPE_DECnet
end_define

begin_comment
comment|/* libpcap, tcpdump */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_LAT
value|0x6004
end_define

begin_comment
comment|/* DEC LAT */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DECDIAG
value|0x6005
end_define

begin_comment
comment|/* DEC diagnostic protocol (at interface initialization?) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DECCUST
value|0x6006
end_define

begin_comment
comment|/* DEC customer protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SCA
value|0x6007
end_define

begin_comment
comment|/* DEC LAVC, SCA */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_AMBER
value|0x6008
end_define

begin_comment
comment|/* DEC AMBER */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DECMUMPS
value|0x6009
end_define

begin_comment
comment|/* DEC MUMPS */
end_comment

begin_comment
comment|/* 0x6010 - 0x6014	   3Com Corporation */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_TRANSETHER
value|0x6558
end_define

begin_comment
comment|/* Trans Ether Bridging (RFC1701)*/
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_RAWFR
value|0x6559
end_define

begin_comment
comment|/* Raw Frame Relay (RFC1701) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_UBDL
value|0x7000
end_define

begin_comment
comment|/* Ungermann-Bass download */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_UBNIU
value|0x7001
end_define

begin_comment
comment|/* Ungermann-Bass NIUs */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_UBDIAGLOOP
value|0x7002
end_define

begin_comment
comment|/* Ungermann-Bass diagnostic/loopback */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_UBNMC
value|0x7003
end_define

begin_comment
comment|/* Ungermann-Bass ??? (NMC to/from UB Bridge) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_UBBST
value|0x7005
end_define

begin_comment
comment|/* Ungermann-Bass Bridge Spanning Tree */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_OS9
value|0x7007
end_define

begin_comment
comment|/* OS/9 Microware */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_OS9NET
value|0x7009
end_define

begin_comment
comment|/* OS/9 Net? */
end_comment

begin_comment
comment|/* 0x7020 - 0x7029	   LRT (England) (now Sintrom) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_RACAL
value|0x7030
end_define

begin_comment
comment|/* Racal-Interlan */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PRIMENTS
value|0x7031
end_define

begin_comment
comment|/* Prime NTS (Network Terminal Service) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_CABLETRON
value|0x7034
end_define

begin_comment
comment|/* Cabletron */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_CRONUSVLN
value|0x8003
end_define

begin_comment
comment|/* Cronus VLN */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_CRONUS
value|0x8004
end_define

begin_comment
comment|/* Cronus Direct */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_HP
value|0x8005
end_define

begin_comment
comment|/* HP Probe */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NESTAR
value|0x8006
end_define

begin_comment
comment|/* Nestar */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ATTSTANFORD
value|0x8008
end_define

begin_comment
comment|/* AT&T/Stanford (local use) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_EXCELAN
value|0x8010
end_define

begin_comment
comment|/* Excelan */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SG_DIAG
value|0x8013
end_define

begin_comment
comment|/* SGI diagnostic type */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SG_NETGAMES
value|0x8014
end_define

begin_comment
comment|/* SGI network games */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SG_RESV
value|0x8015
end_define

begin_comment
comment|/* SGI reserved type */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SG_BOUNCE
value|0x8016
end_define

begin_comment
comment|/* SGI bounce server */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_APOLLODOMAIN
value|0x8019
end_define

begin_comment
comment|/* Apollo DOMAIN */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_TYMSHARE
value|0x802E
end_define

begin_comment
comment|/* Tymeshare */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_TIGAN
value|0x802F
end_define

begin_comment
comment|/* Tigan, Inc. */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_REVARP
value|0x8035
end_define

begin_comment
comment|/* Reverse addr resolution protocol */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_AEONIC
value|0x8036
end_define

begin_comment
comment|/* Aeonic Systems */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IPXNEW
value|0x8037
end_define

begin_comment
comment|/* IPX (Novell Netware?) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_LANBRIDGE
value|0x8038
end_define

begin_comment
comment|/* DEC LANBridge */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DSMD
value|0x8039
end_define

begin_comment
comment|/* DEC DSM/DDP */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ARGONAUT
value|0x803A
end_define

begin_comment
comment|/* DEC Argonaut Console */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VAXELN
value|0x803B
end_define

begin_comment
comment|/* DEC VAXELN */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DECDNS
value|0x803C
end_define

begin_comment
comment|/* DEC DNS Naming Service */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ENCRYPT
value|0x803D
end_define

begin_comment
comment|/* DEC Ethernet Encryption */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DECDTS
value|0x803E
end_define

begin_comment
comment|/* DEC Distributed Time Service */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DECLTM
value|0x803F
end_define

begin_comment
comment|/* DEC LAN Traffic Monitor */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DECNETBIOS
value|0x8040
end_define

begin_comment
comment|/* DEC PATHWORKS DECnet NETBIOS Emulation */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DECLAST
value|0x8041
end_define

begin_comment
comment|/* DEC Local Area System Transport */
end_comment

begin_comment
comment|/* 0x8042	   DEC Unassigned */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PLANNING
value|0x8044
end_define

begin_comment
comment|/* Planning Research Corp. */
end_comment

begin_comment
comment|/* 0x8046 - 0x8047	   AT&T */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DECAM
value|0x8048
end_define

begin_comment
comment|/* DEC Availability Manager for Distributed Systems DECamds (but someone at DEC says not) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_EXPERDATA
value|0x8049
end_define

begin_comment
comment|/* ExperData */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VEXP
value|0x805B
end_define

begin_comment
comment|/* Stanford V Kernel exp. */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VPROD
value|0x805C
end_define

begin_comment
comment|/* Stanford V Kernel prod. */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ES
value|0x805D
end_define

begin_comment
comment|/* Evans& Sutherland */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_LITTLE
value|0x8060
end_define

begin_comment
comment|/* Little Machines */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_COUNTERPOINT
value|0x8062
end_define

begin_comment
comment|/* Counterpoint Computers */
end_comment

begin_comment
comment|/* 0x8065 - 0x8066	   Univ. of Mass @ Amherst */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VEECO
value|0x8067
end_define

begin_comment
comment|/* Veeco Integrated Auto. */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_GENDYN
value|0x8068
end_define

begin_comment
comment|/* General Dynamics */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ATT
value|0x8069
end_define

begin_comment
comment|/* AT&T */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_AUTOPHON
value|0x806A
end_define

begin_comment
comment|/* Autophon */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_COMDESIGN
value|0x806C
end_define

begin_comment
comment|/* ComDesign */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_COMPUGRAPHIC
value|0x806D
end_define

begin_comment
comment|/* Compugraphic Corporation */
end_comment

begin_comment
comment|/* 0x806E - 0x8077	   Landmark Graphics Corp. */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_MATRA
value|0x807A
end_define

begin_comment
comment|/* Matra */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DDE
value|0x807B
end_define

begin_comment
comment|/* Dansk Data Elektronik */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_MERIT
value|0x807C
end_define

begin_comment
comment|/* Merit Internodal (or Univ of Michigan?) */
end_comment

begin_comment
comment|/* 0x807D - 0x807F	   Vitalink Communications */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VLTLMAN
value|0x8080
end_define

begin_comment
comment|/* Vitalink TransLAN III Management */
end_comment

begin_comment
comment|/* 0x8081 - 0x8083	   Counterpoint Computers */
end_comment

begin_comment
comment|/* 0x8088 - 0x808A	   Xyplex */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ATALK
value|0x809B
end_define

begin_comment
comment|/* AppleTalk */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_AT
value|ETHERTYPE_ATALK
end_define

begin_comment
comment|/* old NetBSD */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_APPLETALK
value|ETHERTYPE_ATALK
end_define

begin_comment
comment|/* HP-UX */
end_comment

begin_comment
comment|/* 0x809C - 0x809E	   Datability */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SPIDER
value|0x809F
end_define

begin_comment
comment|/* Spider Systems Ltd. */
end_comment

begin_comment
comment|/* 0x80A3	   Nixdorf */
end_comment

begin_comment
comment|/* 0x80A4 - 0x80B3	   Siemens Gammasonics Inc. */
end_comment

begin_comment
comment|/* 0x80C0 - 0x80C3	   DCA (Digital Comm. Assoc.) Data Exchange Cluster */
end_comment

begin_comment
comment|/* 0x80C4 - 0x80C5	   Banyan Systems */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PACER
value|0x80C6
end_define

begin_comment
comment|/* Pacer Software */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_APPLITEK
value|0x80C7
end_define

begin_comment
comment|/* Applitek Corporation */
end_comment

begin_comment
comment|/* 0x80C8 - 0x80CC	   Intergraph Corporation */
end_comment

begin_comment
comment|/* 0x80CD - 0x80CE	   Harris Corporation */
end_comment

begin_comment
comment|/* 0x80CF - 0x80D2	   Taylor Instrument */
end_comment

begin_comment
comment|/* 0x80D3 - 0x80D4	   Rosemount Corporation */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SNA
value|0x80D5
end_define

begin_comment
comment|/* IBM SNA Services over Ethernet */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VARIAN
value|0x80DD
end_define

begin_comment
comment|/* Varian Associates */
end_comment

begin_comment
comment|/* 0x80DE - 0x80DF	   TRFS (Integrated Solutions Transparent Remote File System) */
end_comment

begin_comment
comment|/* 0x80E0 - 0x80E3	   Allen-Bradley */
end_comment

begin_comment
comment|/* 0x80E4 - 0x80F0	   Datability */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_RETIX
value|0x80F2
end_define

begin_comment
comment|/* Retix */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_AARP
value|0x80F3
end_define

begin_comment
comment|/* AppleTalk AARP */
end_comment

begin_comment
comment|/* 0x80F4 - 0x80F5	   Kinetics */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_APOLLO
value|0x80F7
end_define

begin_comment
comment|/* Apollo Computer */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VLAN
value|0x8100
end_define

begin_comment
comment|/* IEEE 802.1Q VLAN tagging (XXX conflicts) */
end_comment

begin_comment
comment|/* 0x80FF - 0x8101	   Wellfleet Communications (XXX conflicts) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_BOFL
value|0x8102
end_define

begin_comment
comment|/* Wellfleet; BOFL (Breath OF Life) pkts [every 5-10 secs.] */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_WELLFLEET
value|0x8103
end_define

begin_comment
comment|/* Wellfleet Communications */
end_comment

begin_comment
comment|/* 0x8107 - 0x8109	   Symbolics Private */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_TALARIS
value|0x812B
end_define

begin_comment
comment|/* Talaris */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_WATERLOO
value|0x8130
end_define

begin_comment
comment|/* Waterloo Microsystems Inc. (XXX which?) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_HAYES
value|0x8130
end_define

begin_comment
comment|/* Hayes Microcomputers (XXX which?) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VGLAB
value|0x8131
end_define

begin_comment
comment|/* VG Laboratory Systems */
end_comment

begin_comment
comment|/* 0x8132 - 0x8137	   Bridge Communications */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IPX
value|0x8137
end_define

begin_comment
comment|/* Novell (old) NetWare IPX (ECONFIG E option) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NOVELL
value|0x8138
end_define

begin_comment
comment|/* Novell, Inc. */
end_comment

begin_comment
comment|/* 0x8139 - 0x813D	   KTI */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_MUMPS
value|0x813F
end_define

begin_comment
comment|/* M/MUMPS data sharing */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_AMOEBA
value|0x8145
end_define

begin_comment
comment|/* Vrije Universiteit (NL) Amoeba 4 RPC (obsolete) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_FLIP
value|0x8146
end_define

begin_comment
comment|/* Vrije Universiteit (NL) FLIP (Fast Local Internet Protocol) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VURESERVED
value|0x8147
end_define

begin_comment
comment|/* Vrije Universiteit (NL) [reserved] */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_LOGICRAFT
value|0x8148
end_define

begin_comment
comment|/* Logicraft */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NCD
value|0x8149
end_define

begin_comment
comment|/* Network Computing Devices */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ALPHA
value|0x814A
end_define

begin_comment
comment|/* Alpha Micro */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SNMP
value|0x814C
end_define

begin_comment
comment|/* SNMP over Ethernet (see RFC1089) */
end_comment

begin_comment
comment|/* 0x814D - 0x814E	   BIIN */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_TEC
value|0x814F
end_define

begin_comment
comment|/* Technically Elite Concepts */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_RATIONAL
value|0x8150
end_define

begin_comment
comment|/* Rational Corp */
end_comment

begin_comment
comment|/* 0x8151 - 0x8153	   Qualcomm */
end_comment

begin_comment
comment|/* 0x815C - 0x815E	   Computer Protocol Pty Ltd */
end_comment

begin_comment
comment|/* 0x8164 - 0x8166	   Charles River Data Systems */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_XTP
value|0x817D
end_define

begin_comment
comment|/* Protocol Engines XTP */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SGITW
value|0x817E
end_define

begin_comment
comment|/* SGI/Time Warner prop. */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_HIPPI_FP
value|0x8180
end_define

begin_comment
comment|/* HIPPI-FP encapsulation */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_STP
value|0x8181
end_define

begin_comment
comment|/* Scheduled Transfer STP, HIPPI-ST */
end_comment

begin_comment
comment|/* 0x8182 - 0x8183	   Reserved for HIPPI-6400 */
end_comment

begin_comment
comment|/* 0x8184 - 0x818C	   SGI prop. */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_MOTOROLA
value|0x818D
end_define

begin_comment
comment|/* Motorola */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NETBEUI
value|0x8191
end_define

begin_comment
comment|/* PowerLAN NetBIOS/NetBEUI (PC) */
end_comment

begin_comment
comment|/* 0x819A - 0x81A3	   RAD Network Devices */
end_comment

begin_comment
comment|/* 0x81B7 - 0x81B9	   Xyplex */
end_comment

begin_comment
comment|/* 0x81CC - 0x81D5	   Apricot Computers */
end_comment

begin_comment
comment|/* 0x81D6 - 0x81DD	   Artisoft Lantastic */
end_comment

begin_comment
comment|/* 0x81E6 - 0x81EF	   Polygon */
end_comment

begin_comment
comment|/* 0x81F0 - 0x81F2	   Comsat Labs */
end_comment

begin_comment
comment|/* 0x81F3 - 0x81F5	   SAIC */
end_comment

begin_comment
comment|/* 0x81F6 - 0x81F8	   VG Analytical */
end_comment

begin_comment
comment|/* 0x8203 - 0x8205	   QNX Software Systems Ltd. */
end_comment

begin_comment
comment|/* 0x8221 - 0x8222	   Ascom Banking Systems */
end_comment

begin_comment
comment|/* 0x823E - 0x8240	   Advanced Encryption Systems */
end_comment

begin_comment
comment|/* 0x8263 - 0x826A	   Charles River Data Systems */
end_comment

begin_comment
comment|/* 0x827F - 0x8282	   Athena Programming */
end_comment

begin_comment
comment|/* 0x829A - 0x829B	   Inst Ind Info Tech */
end_comment

begin_comment
comment|/* 0x829C - 0x82AB	   Taurus Controls */
end_comment

begin_comment
comment|/* 0x82AC - 0x8693	   Walker Richer& Quinn */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ACCTON
value|0x8390
end_define

begin_comment
comment|/* Accton Technologies (unregistered) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_TALARISMC
value|0x852B
end_define

begin_comment
comment|/* Talaris multicast */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_KALPANA
value|0x8582
end_define

begin_comment
comment|/* Kalpana */
end_comment

begin_comment
comment|/* 0x8694 - 0x869D	   Idea Courier */
end_comment

begin_comment
comment|/* 0x869E - 0x86A1	   Computer Network Tech */
end_comment

begin_comment
comment|/* 0x86A3 - 0x86AC	   Gateway Communications */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SECTRA
value|0x86DB
end_define

begin_comment
comment|/* SECTRA */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IPV6
value|0x86DD
end_define

begin_comment
comment|/* IP protocol version 6 */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DELTACON
value|0x86DE
end_define

begin_comment
comment|/* Delta Controls */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_ATOMIC
value|0x86DF
end_define

begin_comment
comment|/* ATOMIC */
end_comment

begin_comment
comment|/* 0x86E0 - 0x86EF	   Landis& Gyr Powers */
end_comment

begin_comment
comment|/* 0x8700 - 0x8710	   Motorola */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_RDP
value|0x8739
end_define

begin_comment
comment|/* Control Technology Inc. RDP Without IP */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_MICP
value|0x873A
end_define

begin_comment
comment|/* Control Technology Inc. Mcast Industrial Ctrl Proto. */
end_comment

begin_comment
comment|/* 0x873B - 0x873C	   Control Technology Inc. Proprietary */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_TCPCOMP
value|0x876B
end_define

begin_comment
comment|/* TCP/IP Compression (RFC1701) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_IPAS
value|0x876C
end_define

begin_comment
comment|/* IP Autonomous Systems (RFC1701) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SECUREDATA
value|0x876D
end_define

begin_comment
comment|/* Secure Data (RFC1701) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_FLOWCONTROL
value|0x8808
end_define

begin_comment
comment|/* 802.3x flow control packet */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PPP
value|0x880B
end_define

begin_comment
comment|/* PPP (obsolete by PPPOE) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_HITACHI
value|0x8820
end_define

begin_comment
comment|/* Hitachi Cable (Optoelectronic Systems Laboratory) */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_MPLS
value|0x8847
end_define

begin_comment
comment|/* MPLS Unicast */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_MPLS_MCAST
value|0x8848
end_define

begin_comment
comment|/* MPLS Multicast */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_AXIS
value|0x8856
end_define

begin_comment
comment|/* Axis Communications AB proprietary bootstrap/config */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PPPOEDISC
value|0x8863
end_define

begin_comment
comment|/* PPP Over Ethernet Discovery Stage */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PPPOE
value|0x8864
end_define

begin_comment
comment|/* PPP Over Ethernet Session Stage */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_LANPROBE
value|0x8888
end_define

begin_comment
comment|/* HP LanProbe test? */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PAE
value|0x888e
end_define

begin_comment
comment|/* EAPOL PAE/802.1x */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_LOOPBACK
value|0x9000
end_define

begin_comment
comment|/* Loopback: used to test interfaces */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_LBACK
value|ETHERTYPE_LOOPBACK
end_define

begin_comment
comment|/* DEC MOP loopback */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_XNSSM
value|0x9001
end_define

begin_comment
comment|/* 3Com (Formerly Bridge Communications), XNS Systems Management */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_TCPSM
value|0x9002
end_define

begin_comment
comment|/* 3Com (Formerly Bridge Communications), TCP/IP Systems Management */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_BCLOOP
value|0x9003
end_define

begin_comment
comment|/* 3Com (Formerly Bridge Communications), loopback detection */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_DEBNI
value|0xAAAA
end_define

begin_comment
comment|/* DECNET? Used by VAX 6220 DEBNI */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_SONIX
value|0xFAF5
end_define

begin_comment
comment|/* Sonix Arpeggio */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_VITAL
value|0xFF00
end_define

begin_comment
comment|/* BBN VITAL-LanBridge cache wakeups */
end_comment

begin_comment
comment|/* 0xFF00 - 0xFFOF	   ISC Bunker Ramo */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_MAX
value|0xFFFF
end_define

begin_comment
comment|/* Maximum valid ethernet type, reserved */
end_comment

begin_comment
comment|/*  * The ETHERTYPE_NTRAILER packet types starting at ETHERTYPE_TRAIL have  * (type-ETHERTYPE_TRAIL)*512 bytes of data followed  * by an ETHER type (as given above) and then the (variable-length) header.  */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_TRAIL
value|0x1000
end_define

begin_comment
comment|/* Trailer packet */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_NTRAILER
value|16
end_define

begin_define
define|#
directive|define
name|ETHERMTU
value|(ETHER_MAX_LEN-ETHER_HDR_LEN-ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|ETHERMIN
value|(ETHER_MIN_LEN-ETHER_HDR_LEN-ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|ETHERMTU_JUMBO
value|(ETHER_MAX_LEN_JUMBO - ETHER_HDR_LEN - ETHER_CRC_LEN)
end_define

begin_comment
comment|/*  * The ETHER_BPF_MTAP macro should be used by drivers which support hardware  * offload for VLAN tag processing.  It will check the mbuf to see if it has  * M_VLANTAG set, and if it does, will pass the packet along to  * ether_vlan_mtap.  This function will re-insert VLAN tags for the duration  * of the tap, so they show up properly for network analyzers.  */
end_comment

begin_define
define|#
directive|define
name|ETHER_BPF_MTAP
parameter_list|(
name|_ifp
parameter_list|,
name|_m
parameter_list|)
value|do {					\ 	if (bpf_peers_present((_ifp)->if_bpf)) {			\ 		M_ASSERTVALID(_m);					\ 		if (((_m)->m_flags& M_VLANTAG) != 0)			\ 			ether_vlan_mtap((_ifp)->if_bpf, (_m), NULL, 0);	\ 		else							\ 			bpf_mtap((_ifp)->if_bpf, (_m));			\ 	}								\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|bpf_if
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|uint32_t
name|ether_crc32_le
parameter_list|(
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|ether_crc32_be
parameter_list|(
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ether_demux
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ether_ifattach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ether_ifdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ether_ioctl
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ether_output
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|rtentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ether_output_frame
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ether_sprintf
parameter_list|(
specifier|const
name|u_int8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ether_vlan_mtap
parameter_list|(
name|struct
name|bpf_if
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/*  * Ethernet address conversion/parsing routines.  */
end_comment

begin_function_decl
name|__BEGIN_DECLS
name|struct
name|ether_addr
modifier|*
name|ether_aton
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ether_hostton
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|ether_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ether_line
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|ether_addr
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ether_ntoa
parameter_list|(
specifier|const
name|struct
name|ether_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ether_ntohost
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|ether_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_ETHERNET_H_ */
end_comment

end_unit

