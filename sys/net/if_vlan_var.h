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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|vlan_mc_entry
block|{
name|struct
name|ether_addr
name|mc_addr
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|vlan_mc_entry
argument_list|)
name|mc_entries
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ifvlan
block|{
name|struct
name|arpcom
name|ifv_ac
decl_stmt|;
comment|/* make this an interface */
name|struct
name|ifnet
modifier|*
name|ifv_p
decl_stmt|;
comment|/* parent inteface of this vlan */
struct|struct
name|ifv_linkmib
block|{
name|int
name|ifvm_parent
decl_stmt|;
name|u_int16_t
name|ifvm_proto
decl_stmt|;
comment|/* encapsulation ethertype */
name|u_int16_t
name|ifvm_tag
decl_stmt|;
comment|/* tag to apply on packets leaving if */
block|}
name|ifv_mib
struct|;
name|SLIST_HEAD
argument_list|(
argument|__vlan_mchead
argument_list|,
argument|vlan_mc_entry
argument_list|)
name|vlan_mc_listhead
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|ifvlan
argument_list|)
name|ifv_list
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ifv_if
value|ifv_ac.ac_if
end_define

begin_define
define|#
directive|define
name|ifv_tag
value|ifv_mib.ifvm_tag
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

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
name|EVL_VLANOFTAG
parameter_list|(
name|tag
parameter_list|)
value|((tag)& 4095)
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
name|EVL_ENCAPLEN
value|4
end_define

begin_comment
comment|/* length in octets of encapsulation */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_VLAN_VAR_H_ */
end_comment

end_unit

