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

begin_comment
comment|/* map to strings and vendors */
end_comment

begin_define
define|#
directive|define
name|ATM_DEVICE_NAMES
define|\
value|{ "Unknown",	"Unknown" },				\ 	{ "PCA200-E",	"Fore/Marconi" },			\ 	{ "HE155",	"Fore/Marconi" },			\ 	{ "HE622",	"Fore/Marconi" },			\ 	{ "ENI155p",	"Efficient Networks" },			\ 	{ "ADP155p",	"Adaptec" },
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
comment|/*  * Peak cell rates for various physical media. Note, that there are  * different opinions on what the correct values are.  */
end_comment

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
name|ATM_RATE_24G
value|5651320
end_define

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
name|u_int8_t
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

begin_define
define|#
directive|define
name|ATM_PH_AAL5
value|0x01
end_define

begin_comment
comment|/* use AAL5? (0 == aal0) */
end_comment

begin_define
define|#
directive|define
name|ATM_PH_LLCSNAP
value|0x02
end_define

begin_comment
comment|/* use the LLC SNAP encoding (iff aal5) */
end_comment

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
comment|/* user's ioctl hook for raw atm mode */
end_comment

begin_define
define|#
directive|define
name|SIOCRAWATM
value|_IOWR('a', 122, int)
end_define

begin_comment
comment|/* set driver's raw mode */
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
name|u_int8_t
name|llchdr
index|[
literal|6
index|]
decl_stmt|;
comment|/* aa.aa.03.00.00.00 */
name|u_int8_t
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
value|{ \ 	(X)->type[0] = ((V)>> 8)& 0xff; \ 	(X)->type[1] = ((V)& 0xff); \ }
end_define

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

begin_endif
endif|#
directive|endif
end_endif

end_unit

