begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1998 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/*  * Drivers that are capable of adding and removing the VLAN header  * in hardware indicate they support this by marking IFCAP_VLAN_HWTAGGING  * in if_capabilities.  Drivers for hardware that is also capable  * of handling larger MTU's that may include a software-appended  * VLAN header w/o lowering the normal MTU should mark IFCAP_VLA_MTU  * in if_capabilities; this notfies the VLAN code it can leave the  * MTU on the vlan interface at the normal setting.  */
end_comment

begin_comment
comment|/*  * Drivers that support hardware VLAN tagging pass a packet's tag  * up through the stack by appending a packet tag with this value.  * Output is handled likewise, the driver must locate the packet  * tag to extract the VLAN tag.  The following macros are used to  * do this work.  On input, do:  *  *	VLAN_INPUT_TAG(ifp, m, tag,);  *  * to mark the packet m with the specified VLAN tag.  The last  * parameter provides code to execute in case of an error.  On  * output the driver should check ifnet to see if any VLANs are  * in use and only then check for a packet tag; this is done with:  *  *	struct m_tag *mtag;  *	mtag = VLAN_OUTPUT_TAG(ifp, m);  *	if (mtag != NULL) {  *		... = VLAN_TAG_VALUE(mtag);  *		... pass tag to hardware ...  *	}  *  * Note that a driver must indicate it supports hardware VLAN  * tagging by marking IFCAP_VLAN_HWTAGGING in if_capabilities.  */
end_comment

begin_define
define|#
directive|define
name|MTAG_VLAN
value|1035328035
end_define

begin_define
define|#
directive|define
name|MTAG_VLAN_TAG
value|0
end_define

begin_comment
comment|/* tag of VLAN interface */
end_comment

begin_define
define|#
directive|define
name|VLAN_INPUT_TAG
parameter_list|(
name|_ifp
parameter_list|,
name|_m
parameter_list|,
name|_t
parameter_list|,
name|_errcase
parameter_list|)
value|do {		\ 	struct m_tag *mtag;					\ 	mtag = m_tag_alloc(MTAG_VLAN, MTAG_VLAN_TAG,		\ 			   sizeof (u_int), M_NOWAIT);		\ 	if (mtag == NULL) {					\ 		(_ifp)->if_ierrors++;				\ 		m_freem(_m);					\ 		_errcase;					\ 	}							\ 	*(u_int *)(mtag+1) = (_t);				\ 	m_tag_prepend((_m), mtag);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|VLAN_OUTPUT_TAG
parameter_list|(
name|_ifp
parameter_list|,
name|_m
parameter_list|)
define|\
value|((_ifp)->if_nvlans != 0 ?				\ 		m_tag_locate((_m), MTAG_VLAN, MTAG_VLAN_TAG, NULL) : NULL)
end_define

begin_define
define|#
directive|define
name|VLAN_TAG_VALUE
parameter_list|(
name|_mt
parameter_list|)
value|(*(u_int *)((_mt)+1))
end_define

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

