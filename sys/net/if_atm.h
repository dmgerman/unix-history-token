begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      $NetBSD: if_atm.h,v 1.7 1996/11/09 23:02:27 chuck Exp $       */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  *  * Copyright (c) 1996 Charles D. Cranor and Washington University.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Charles D. Cranor and  *	Washington University.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * net/if_atm.h  */
end_comment

begin_comment
comment|/*  * Classification of ATM cards.  */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|ATM_DEVICE_PCA200E
value|1
end_define

begin_comment
comment|/* Fore/Marconi PCA200-E */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_HE155
value|2
end_define

begin_comment
comment|/* Fore/Marconi HE155 */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_HE622
value|3
end_define

begin_comment
comment|/* Fore/Marconi HE622 */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_ENI155P
value|4
end_define

begin_comment
comment|/* Efficient networks 155p */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_ADP155P
value|5
end_define

begin_comment
comment|/* Adaptec 155p */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_FORELE25
value|6
end_define

begin_comment
comment|/* ForeRunnerLE 25 */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_FORELE155
value|7
end_define

begin_comment
comment|/* ForeRunnerLE 155 */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_NICSTAR25
value|8
end_define

begin_comment
comment|/* other 77211 25.6MBit */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_NICSTAR155
value|9
end_define

begin_comment
comment|/* other 77211 155MBit */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_IDTABR25
value|10
end_define

begin_comment
comment|/* 77252 based card 25MBit */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_IDTABR155
value|11
end_define

begin_comment
comment|/* 77252 based card 155MBit */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_PROATM25
value|12
end_define

begin_comment
comment|/* 77252 based ProSum card 25MBit */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_PROATM155
value|13
end_define

begin_comment
comment|/* 77252 based ProSum card 155MBit */
end_comment

begin_comment
comment|/* map to strings and vendors */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_NAMES
define|\
value|{ "Unknown",		"Unknown" },				\ 	{ "PCA200-E",		"Fore/Marconi" },			\ 	{ "HE155",		"Fore/Marconi" },			\ 	{ "HE622",		"Fore/Marconi" },			\ 	{ "ENI155p",		"Efficient Networks" },			\ 	{ "ADP155p",		"Adaptec" },				\ 	{ "ForeRunnerLE25",	"Fore/Marconi" },			\ 	{ "ForeRunnerLE155",	"Fore/Marconi" },			\ 	{ "IDT77211/25",	"IDT" },				\ 	{ "IDT77211/155",	"IDT" },				\ 	{ "IDT77252/25",	"IDT" },				\ 	{ "IDT77252/155",	"IDT" },				\ 	{ "ProATM/25",		"ProSum" },				\ 	{ "ProATM/155",		"ProSum" },
end_define

begin_comment
comment|/*  * This is the common link layer MIB for all ATM interfaces. Much of the  * information here is needed for ILMI. This will be augmented by statistics  * at some point.  */
end_comment

begin_struct
struct|struct
name|ifatm_mib
block|{
comment|/* configuration data */
name|uint8_t
name|device
decl_stmt|;
comment|/* type of card */
name|u_char
name|esi
index|[
literal|6
index|]
decl_stmt|;
comment|/* end system identifier (MAC) */
name|uint32_t
name|serial
decl_stmt|;
comment|/* card serial number */
name|uint32_t
name|hw_version
decl_stmt|;
comment|/* card version */
name|uint32_t
name|sw_version
decl_stmt|;
comment|/* firmware version (if any) */
name|uint32_t
name|pcr
decl_stmt|;
comment|/* supported peak cell rate */
name|uint32_t
name|media
decl_stmt|;
comment|/* physical media */
name|uint8_t
name|vpi_bits
decl_stmt|;
comment|/* number of used bits in VPI field */
name|uint8_t
name|vci_bits
decl_stmt|;
comment|/* number of used bits in VCI field */
name|uint16_t
name|max_vpcs
decl_stmt|;
comment|/* maximum number of VPCs */
name|uint32_t
name|max_vccs
decl_stmt|;
comment|/* maximum number of VCCs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Traffic parameters for ATM connections. This contains all parameters  * to accomodate UBR, UBR+MCR, CBR, VBR and ABR connections.  *  * Keep in sync with ng_atm.h  */
end_comment

begin_struct
struct|struct
name|atmio_tparam
block|{
name|uint32_t
name|pcr
decl_stmt|;
comment|/* 24bit: Peak Cell Rate */
name|uint32_t
name|scr
decl_stmt|;
comment|/* 24bit: VBR Sustainable Cell Rate */
name|uint32_t
name|mbs
decl_stmt|;
comment|/* 24bit: VBR Maximum burst size */
name|uint32_t
name|mcr
decl_stmt|;
comment|/* 24bit: ABR/VBR/UBR+MCR MCR */
name|uint32_t
name|icr
decl_stmt|;
comment|/* 24bit: ABR ICR */
name|uint32_t
name|tbe
decl_stmt|;
comment|/* 24bit: ABR TBE (1...2^24-1) */
name|uint8_t
name|nrm
decl_stmt|;
comment|/*  3bit: ABR Nrm */
name|uint8_t
name|trm
decl_stmt|;
comment|/*  3bit: ABR Trm */
name|uint16_t
name|adtf
decl_stmt|;
comment|/* 10bit: ABR ADTF */
name|uint8_t
name|rif
decl_stmt|;
comment|/*  4bit: ABR RIF */
name|uint8_t
name|rdf
decl_stmt|;
comment|/*  4bit: ABR RDF */
name|uint8_t
name|cdf
decl_stmt|;
comment|/*  3bit: ABR CDF */
block|}
struct|;
end_struct

begin_comment
comment|/*  * VCC parameters  *  * Keep in sync with ng_atm.h  */
end_comment

begin_struct
struct|struct
name|atmio_vcc
block|{
name|uint16_t
name|flags
decl_stmt|;
comment|/* VCC flags */
name|uint16_t
name|vpi
decl_stmt|;
name|uint16_t
name|vci
decl_stmt|;
name|uint16_t
name|rmtu
decl_stmt|;
comment|/* maximum receive PDU */
name|uint16_t
name|tmtu
decl_stmt|;
comment|/* maximum transmit PDU */
name|uint8_t
name|aal
decl_stmt|;
comment|/* aal type */
name|uint8_t
name|traffic
decl_stmt|;
comment|/* traffic type */
name|struct
name|atmio_tparam
name|tparam
decl_stmt|;
comment|/* traffic parameters */
block|}
struct|;
end_struct

begin_comment
comment|/* VCC flags */
end_comment

begin_define
define|#
directive|define
name|ATMIO_FLAG_LLCSNAP
value|0x0002
end_define

begin_comment
comment|/* same as ATM_PH_LLCSNAP */
end_comment

begin_define
define|#
directive|define
name|ATMIO_FLAG_NG
value|0x0010
end_define

begin_comment
comment|/* owned by netgraph */
end_comment

begin_define
define|#
directive|define
name|ATMIO_FLAG_HARP
value|0x0020
end_define

begin_comment
comment|/* owned by HARP */
end_comment

begin_define
define|#
directive|define
name|ATMIO_FLAG_NORX
value|0x0100
end_define

begin_comment
comment|/* not receiving on this VCC */
end_comment

begin_define
define|#
directive|define
name|ATMIO_FLAG_NOTX
value|0x0200
end_define

begin_comment
comment|/* not transmitting on this VCC */
end_comment

begin_define
define|#
directive|define
name|ATMIO_FLAG_PVC
value|0x0400
end_define

begin_comment
comment|/* this is a PVC */
end_comment

begin_define
define|#
directive|define
name|ATMIO_FLAG_ASYNC
value|0x0800
end_define

begin_comment
comment|/* async open/close */
end_comment

begin_define
define|#
directive|define
name|ATMIO_FLAGS
value|"\020\2LLCSNAP\5NG\6HARP\11NORX\12NOTX\13PVC\14ASYNC"
end_define

begin_define
define|#
directive|define
name|ATMIO_AAL_0
value|0
end_define

begin_comment
comment|/* pure cells */
end_comment

begin_define
define|#
directive|define
name|ATMIO_AAL_34
value|4
end_define

begin_comment
comment|/* AAL3 and 4 */
end_comment

begin_define
define|#
directive|define
name|ATMIO_AAL_5
value|5
end_define

begin_comment
comment|/* AAL5 */
end_comment

begin_define
define|#
directive|define
name|ATMIO_AAL_RAW
value|10
end_define

begin_comment
comment|/* whatever the card does */
end_comment

begin_define
define|#
directive|define
name|ATMIO_TRAFFIC_UBR
value|0
end_define

begin_define
define|#
directive|define
name|ATMIO_TRAFFIC_CBR
value|1
end_define

begin_define
define|#
directive|define
name|ATMIO_TRAFFIC_ABR
value|2
end_define

begin_define
define|#
directive|define
name|ATMIO_TRAFFIC_VBR
value|3
end_define

begin_comment
comment|/*  * VCC table  *  * Keep in sync with ng_atm.h  */
end_comment

begin_struct
struct|struct
name|atmio_vcctable
block|{
name|uint32_t
name|count
decl_stmt|;
comment|/* number of vccs */
name|struct
name|atmio_vcc
name|vccs
index|[
literal|0
index|]
decl_stmt|;
comment|/* array of VCCs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Peak cell rates for various physical media. Note, that there are  * different opinions on what the correct values are.  */
end_comment

begin_define
define|#
directive|define
name|ATM_RATE_25_6M
value|59259
end_define

begin_define
define|#
directive|define
name|ATM_RATE_155M
value|353208
end_define

begin_define
define|#
directive|define
name|ATM_RATE_622M
value|1412830
end_define

begin_define
define|#
directive|define
name|ATM_RATE_2_4G
value|5651320
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Common fields for all ATM interfaces. Each driver's softc must start with  * this structure.  */
end_comment

begin_struct
struct|struct
name|ifatm
block|{
name|struct
name|ifnet
name|ifnet
decl_stmt|;
comment|/* required by if_var.h */
name|struct
name|ifatm_mib
name|mib
decl_stmt|;
comment|/* exported data */
name|void
modifier|*
name|phy
decl_stmt|;
comment|/* usually SUNI */
name|void
modifier|*
name|ngpriv
decl_stmt|;
comment|/* netgraph link */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Keep structures in sync with ng_atm.h  *  * These are used by netgraph/harp to call the driver  * NATM uses the atm_pseudoioctl instead.  */
end_comment

begin_struct
struct|struct
name|atmio_openvcc
block|{
name|void
modifier|*
name|rxhand
decl_stmt|;
comment|/* handle argument */
name|struct
name|atmio_vcc
name|param
decl_stmt|;
comment|/* parameters */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atmio_closevcc
block|{
name|uint16_t
name|vpi
decl_stmt|;
name|uint16_t
name|vci
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_if

begin_define
define|#
directive|define
name|RTALLOC1
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|rtalloc1((A),(B))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|RTALLOC1
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|rtalloc1((A),(B),0UL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * pseudo header for packet transmission  */
end_comment

begin_struct
struct|struct
name|atm_pseudohdr
block|{
name|uint8_t
name|atm_ph
index|[
literal|4
index|]
decl_stmt|;
comment|/* flags+VPI+VCI1(msb)+VCI2(lsb) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATM_PH_FLAGS
parameter_list|(
name|X
parameter_list|)
value|((X)->atm_ph[0])
end_define

begin_define
define|#
directive|define
name|ATM_PH_VPI
parameter_list|(
name|X
parameter_list|)
value|((X)->atm_ph[1])
end_define

begin_define
define|#
directive|define
name|ATM_PH_VCI
parameter_list|(
name|X
parameter_list|)
value|((((X)->atm_ph[2])<< 8) | ((X)->atm_ph[3]))
end_define

begin_define
define|#
directive|define
name|ATM_PH_SETVCI
parameter_list|(
name|X
parameter_list|,
name|V
parameter_list|)
value|{ \ 	(X)->atm_ph[2] = ((V)>> 8)& 0xff; \ 	(X)->atm_ph[3] = ((V)& 0xff); \ }
end_define

begin_comment
comment|/* use AAL5? (0 == aal0) */
end_comment

begin_define
define|#
directive|define
name|ATM_PH_AAL5
value|0x01
end_define

begin_comment
comment|/* use the LLC SNAP encoding (iff aal5) */
end_comment

begin_define
define|#
directive|define
name|ATM_PH_LLCSNAP
value|ATMIO_FLAG_LLCSNAP
end_define

begin_define
define|#
directive|define
name|ATM_PH_DRIVER7
value|0x40
end_define

begin_comment
comment|/* reserve for driver's use */
end_comment

begin_define
define|#
directive|define
name|ATM_PH_DRIVER8
value|0x80
end_define

begin_comment
comment|/* reserve for driver's use */
end_comment

begin_define
define|#
directive|define
name|ATMMTU
value|9180
end_define

begin_comment
comment|/* ATM MTU size for IP */
end_comment

begin_comment
comment|/* XXX: could be 9188 with LLC/SNAP according 					to comer */
end_comment

begin_comment
comment|/* atm_pseudoioctl: turns on and off RX VCIs  [for internal use only!] */
end_comment

begin_struct
struct|struct
name|atm_pseudoioctl
block|{
name|struct
name|atm_pseudohdr
name|aph
decl_stmt|;
name|void
modifier|*
name|rxhand
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCATMENA
value|_IOWR('a', 123, struct atm_pseudoioctl)
end_define

begin_comment
comment|/* enable */
end_comment

begin_define
define|#
directive|define
name|SIOCATMDIS
value|_IOWR('a', 124, struct atm_pseudoioctl)
end_define

begin_comment
comment|/* disable */
end_comment

begin_define
define|#
directive|define
name|SIOCATMGETVCCS
value|_IOW('a', 125, struct atmio_vcctable)
end_define

begin_define
define|#
directive|define
name|SIOCATMOPENVCC
value|_IOR('a', 126, struct atmio_openvcc)
end_define

begin_define
define|#
directive|define
name|SIOCATMCLOSEVCC
value|_IOR('a', 127, struct atmio_closevcc)
end_define

begin_define
define|#
directive|define
name|SIOCATMGVCCS
value|_IOWR('i', 230, struct ifreq)
end_define

begin_comment
comment|/*  * XXX forget all the garbage in if_llc.h and do it the easy way  */
end_comment

begin_define
define|#
directive|define
name|ATMLLC_HDR
value|"\252\252\3\0\0\0"
end_define

begin_struct
struct|struct
name|atmllc
block|{
name|uint8_t
name|llchdr
index|[
literal|6
index|]
decl_stmt|;
comment|/* aa.aa.03.00.00.00 */
name|uint8_t
name|type
index|[
literal|2
index|]
decl_stmt|;
comment|/* "ethernet" type */
block|}
struct|;
end_struct

begin_comment
comment|/* ATM_LLC macros: note type code in host byte order */
end_comment

begin_define
define|#
directive|define
name|ATM_LLC_TYPE
parameter_list|(
name|X
parameter_list|)
value|(((X)->type[0]<< 8) | ((X)->type[1]))
end_define

begin_define
define|#
directive|define
name|ATM_LLC_SETTYPE
parameter_list|(
name|X
parameter_list|,
name|V
parameter_list|)
value|do {		\ 	(X)->type[0] = ((V)>> 8)& 0xff;	\ 	(X)->type[1] = ((V)& 0xff);		\     } while (0)
end_define

begin_comment
comment|/*  * Events that are emitted by the driver. Currently the only consumer  * of this is the netgraph node.  */
end_comment

begin_define
define|#
directive|define
name|ATMEV_FLOW_CONTROL
value|0x0001
end_define

begin_comment
comment|/* channel busy state changed */
end_comment

begin_define
define|#
directive|define
name|ATMEV_IFSTATE_CHANGED
value|0x0002
end_define

begin_comment
comment|/* up/down or carrier */
end_comment

begin_define
define|#
directive|define
name|ATMEV_VCC_CHANGED
value|0x0003
end_define

begin_comment
comment|/* PVC deleted/create */
end_comment

begin_define
define|#
directive|define
name|ATMEV_ACR_CHANGED
value|0x0004
end_define

begin_comment
comment|/* ABR ACR has changed */
end_comment

begin_struct
struct|struct
name|atmev_flow_control
block|{
name|uint16_t
name|vpi
decl_stmt|;
comment|/* channel that is changed */
name|uint16_t
name|vci
decl_stmt|;
name|u_int
name|busy
range|:
literal|1
decl_stmt|;
comment|/* != 0 -> ATM layer busy */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atmev_ifstate_changed
block|{
name|u_int
name|running
range|:
literal|1
decl_stmt|;
comment|/* interface is running now */
name|u_int
name|carrier
range|:
literal|1
decl_stmt|;
comment|/* carrier detected (or not) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atmev_vcc_changed
block|{
name|uint16_t
name|vpi
decl_stmt|;
comment|/* channel that is changed */
name|uint16_t
name|vci
decl_stmt|;
name|u_int
name|up
range|:
literal|1
decl_stmt|;
comment|/* 1 - created, 0 - deleted */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atmev_acr_changed
block|{
name|uint16_t
name|vpi
decl_stmt|;
comment|/* channel that is changed */
name|uint16_t
name|vci
decl_stmt|;
name|uint32_t
name|acr
decl_stmt|;
comment|/* new ACR */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|void
name|atm_ifattach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_ifdetach
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_input
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|atm_pseudohdr
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atm_output
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
name|struct
name|atmio_vcctable
modifier|*
name|atm_getvccs
parameter_list|(
name|struct
name|atmio_vcc
modifier|*
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|mtx
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atm_event
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ATMEV_SEND_FLOW_CONTROL
parameter_list|(
name|ATMIF
parameter_list|,
name|VPI
parameter_list|,
name|VCI
parameter_list|,
name|BUSY
parameter_list|)
define|\
value|do {								\ 		struct atmev_flow_control _arg;				\ 		_arg.vpi = (VPI);					\ 		_arg.vci = (VCI);					\ 		_arg.busy = (BUSY);					\ 		atm_event(&(ATMIF)->ifnet, ATMEV_FLOW_CONTROL,&_arg);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ATMEV_SEND_VCC_CHANGED
parameter_list|(
name|ATMIF
parameter_list|,
name|VPI
parameter_list|,
name|VCI
parameter_list|,
name|UP
parameter_list|)
define|\
value|do {								\ 		struct atmev_vcc_changed _arg;				\ 		_arg.vpi = (VPI);					\ 		_arg.vci = (VCI);					\ 		_arg.up = (UP);						\ 		atm_event(&(ATMIF)->ifnet, ATMEV_VCC_CHANGED,&_arg);	\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ATMEV_SEND_IFSTATE_CHANGED
parameter_list|(
name|ATMIF
parameter_list|,
name|CARRIER
parameter_list|)
define|\
value|do {								\ 		struct atmev_ifstate_changed _arg;			\ 		_arg.running = (((ATMIF)->ifnet.if_flags&		\ 		    IFF_RUNNING) != 0);					\ 		_arg.carrier = ((CARRIER) != 0);			\ 		atm_event(&(ATMIF)->ifnet, ATMEV_IFSTATE_CHANGED,&_arg); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ATMEV_SEND_ACR_CHANGED
parameter_list|(
name|ATMIF
parameter_list|,
name|VPI
parameter_list|,
name|VCI
parameter_list|,
name|ACR
parameter_list|)
define|\
value|do {								\ 		struct atmev_acr_changed _arg;				\ 		_arg.vpi = (VPI);					\ 		_arg.vci = (VCI);					\ 		_arg.acr= (ACR);					\ 		atm_event(&(ATMIF)->ifnet, ATMEV_ACR_CHANGED,&_arg);	\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

