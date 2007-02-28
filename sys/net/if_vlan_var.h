begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1998 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_VLAN_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_VLAN_VAR_H_
value|1
end_define

begin_struct
struct|struct
name|ether_vlan_header
block|{
name|u_char
name|evl_dhost
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_char
name|evl_shost
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int16_t
name|evl_encap_proto
decl_stmt|;
name|u_int16_t
name|evl_tag
decl_stmt|;
name|u_int16_t
name|evl_proto
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EVL_VLID_MASK
value|0x0FFF
end_define

begin_define
define|#
directive|define
name|EVL_PRI_MASK
value|0xE000
end_define

begin_define
define|#
directive|define
name|EVL_VLANOFTAG
parameter_list|(
name|tag
parameter_list|)
value|((tag)& EVL_VLID_MASK)
end_define

begin_define
define|#
directive|define
name|EVL_PRIOFTAG
parameter_list|(
name|tag
parameter_list|)
value|(((tag)>> 13)& 7)
end_define

begin_define
define|#
directive|define
name|EVL_CFIOFTAG
parameter_list|(
name|tag
parameter_list|)
value|(((tag)>> 12)& 1)
end_define

begin_define
define|#
directive|define
name|EVL_MAKETAG
parameter_list|(
name|vlid
parameter_list|,
name|pri
parameter_list|,
name|cfi
parameter_list|)
define|\
value|((((((pri)& 7)<< 1) | ((cfi)& 1))<< 12) | ((vlid)& EVL_VLID_MASK))
end_define

begin_comment
comment|/* Set the VLAN ID in an mbuf packet header non-destructively. */
end_comment

begin_define
define|#
directive|define
name|EVL_APPLY_VLID
parameter_list|(
name|m
parameter_list|,
name|vlid
parameter_list|)
define|\
value|do {								\ 		if ((m)->m_flags& M_VLANTAG) {				\ 			(m)->m_pkthdr.ether_vtag&= EVL_VLID_MASK;	\ 			(m)->m_pkthdr.ether_vtag |= (vlid);		\ 		} else {						\ 			(m)->m_pkthdr.ether_vtag = (vlid);		\ 			(m)->m_flags |= M_VLANTAG;			\ 		}							\ 	} while (0)
end_define

begin_comment
comment|/* Set the priority ID in an mbuf packet header non-destructively. */
end_comment

begin_define
define|#
directive|define
name|EVL_APPLY_PRI
parameter_list|(
name|m
parameter_list|,
name|pri
parameter_list|)
define|\
value|do {								\ 		if ((m)->m_flags& M_VLANTAG) {				\ 			uint16_t __vlantag = (m)->m_pkthdr.ether_vtag;	\ 			(m)->m_pkthdr.ether_vtag |= EVL_MAKETAG(	\ 			    EVL_VLANOFTAG(__vlantag), (pri),		\ 			    EVL_CFIOFTAG(__vlantag));			\ 		} else {						\ 			(m)->m_pkthdr.ether_vtag =			\ 			    EVL_MAKETAG(0, (pri), 0);			\ 			(m)->m_flags |= M_VLANTAG;			\ 		}							\ 	} while (0)
end_define

begin_comment
comment|/* sysctl(3) tags, for compatibility purposes */
end_comment

begin_define
define|#
directive|define
name|VLANCTL_PROTO
value|1
end_define

begin_define
define|#
directive|define
name|VLANCTL_MAX
value|2
end_define

begin_comment
comment|/*  * Configuration structure for SIOCSETVLAN and SIOCGETVLAN ioctls.  */
end_comment

begin_struct
struct|struct
name|vlanreq
block|{
name|char
name|vlr_parent
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
name|u_short
name|vlr_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIOCSETVLAN
value|SIOCSIFGENERIC
end_define

begin_define
define|#
directive|define
name|SIOCGETVLAN
value|SIOCGIFGENERIC
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Drivers that are capable of adding and removing the VLAN header  * in hardware indicate they support this by marking IFCAP_VLAN_HWTAGGING  * in if_capabilities.  Drivers for hardware that is capable  * of handling larger MTU's that may include a software-appended  * VLAN header w/o lowering the normal MTU should mark IFCAP_VLAN_MTU  * in if_capabilities; this notifies the VLAN code it can leave the  * MTU on the vlan interface at the normal setting.  */
end_comment

begin_comment
comment|/*  * VLAN tags are stored in host byte order.  Byte swapping may be  * necessary.  *  * Drivers that support hardware VLAN tag stripping fill in the  * received VLAN tag (containing both vlan and priority information)  * into the ether_vtag mbuf packet header field:  *   *	m->m_pkthdr.ether_vtag = vlan_id;	// ntohs()?  *	m->m_flags |= M_VLANTAG;  *  * to mark the packet m with the specified VLAN tag.  *  * On output the driver should check the mbuf for the M_VLANTAG  * flag to see if a VLAN tag is present and valid:  *  *	if (m->m_flags& M_VLANTAG) {  *		... = m->m_pkthdr.ether_vtag;	// htons()?  *		... pass tag to hardware ...  *	}  *  * Note that a driver must indicate it supports hardware VLAN  * stripping/insertion by marking IFCAP_VLAN_HWTAGGING in  * if_capabilities.  */
end_comment

begin_define
define|#
directive|define
name|VLAN_CAPABILITIES
parameter_list|(
name|_ifp
parameter_list|)
value|do {				\ 	if ((_ifp)->if_vlantrunk != NULL) 			\ 		(*vlan_trunk_cap_p)(_ifp);			\ } while (0)
end_define

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|vlan_trunk_cap_p
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_VLAN_VAR_H_ */
end_comment

end_unit

