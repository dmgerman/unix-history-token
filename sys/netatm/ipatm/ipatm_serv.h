begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * IP Over ATM Support  * -------------------  *  * IP/ATM service interface definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IPATM_IPATM_SERV_H
end_ifndef

begin_define
define|#
directive|define
name|_IPATM_IPATM_SERV_H
end_define

begin_comment
comment|/*  * Structures specifying VCC parameters and pointers to all of the IP   * services offered by an external IP interface service provider.  */
end_comment

begin_struct
struct|struct
name|ip_vccparm
block|{
name|Aal_t
name|ivc_aal
decl_stmt|;
comment|/* AAL type */
name|Encaps_t
name|ivc_encaps
decl_stmt|;
comment|/* VCC encapsulation */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IPATM_VCCPARMS
value|4
end_define

begin_comment
comment|/* Number of parameter lists */
end_comment

begin_struct
struct|struct
name|ip_serv
block|{
comment|/* Interfaces to IP/ATM interface services */
name|int
function_decl|(
modifier|*
name|is_ifact
function_decl|)
comment|/* Interface activation */
parameter_list|(
name|struct
name|ip_nif
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|is_ifdact
function_decl|)
comment|/* Interface deactivation */
parameter_list|(
name|struct
name|ip_nif
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|is_ioctl
function_decl|)
comment|/* Interface ioctl */
parameter_list|(
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
comment|/* Interfaces to IP/ATM ARP services */
name|int
function_decl|(
modifier|*
name|is_arp_pvcopen
function_decl|)
comment|/* IP creating dynamic PVC */
parameter_list|(
name|struct
name|ipvcc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|is_arp_svcout
function_decl|)
comment|/* IP creating outgoing SVC */
parameter_list|(
name|struct
name|ipvcc
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|is_arp_svcin
function_decl|)
comment|/* IP creating incoming SVC */
parameter_list|(
name|struct
name|ipvcc
modifier|*
parameter_list|,
name|Atm_addr
modifier|*
parameter_list|,
name|Atm_addr
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|is_arp_svcact
function_decl|)
comment|/* IP SVC is active */
parameter_list|(
name|struct
name|ipvcc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|is_arp_close
function_decl|)
comment|/* IP closing VCC */
parameter_list|(
name|struct
name|ipvcc
modifier|*
parameter_list|)
function_decl|;
comment|/* Interfaces to IP/ATM broadcast services */
name|int
function_decl|(
modifier|*
name|is_bcast_output
function_decl|)
comment|/* IP broadcast packet output */
parameter_list|(
name|struct
name|ip_nif
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
comment|/* Interfaces to IP/ATM multicast services */
comment|/* Ordered list of parameters to try for IP/ATM VCC connections */
name|struct
name|ip_vccparm
name|is_vccparm
index|[
name|IPATM_VCCPARMS
index|]
decl_stmt|;
comment|/* List of vcc params */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ARP Interface  * ----------------  */
end_comment

begin_comment
comment|/*  * Common header for IP/ATM ARP mappings.  For each IP VCC created, the  * appropriate IP/ATM ARP server must assign one of these structures to   * indicate the address mapping.  This is the only IP-visible ARP structure.  * The servers may embed this structure at the beginning of their   * module-specific mappings.  */
end_comment

begin_struct
struct|struct
name|arpmap
block|{
name|struct
name|in_addr
name|am_dstip
decl_stmt|;
comment|/* Destination IP address */
name|Atm_addr
name|am_dstatm
decl_stmt|;
comment|/* Destination ATM address */
name|Atm_addr
name|am_dstatmsub
decl_stmt|;
comment|/* Destination ATM subaddress */
block|}
struct|;
end_struct

begin_comment
comment|/*  * is_arp_[ps]open() return codes and ipatm_arpnotify() event types  */
end_comment

begin_define
define|#
directive|define
name|MAP_PROCEEDING
value|1
end_define

begin_comment
comment|/* Lookup is proceeding (open only) */
end_comment

begin_define
define|#
directive|define
name|MAP_VALID
value|2
end_define

begin_comment
comment|/* Mapping is valid */
end_comment

begin_define
define|#
directive|define
name|MAP_INVALID
value|3
end_define

begin_comment
comment|/* Mapping is invalid */
end_comment

begin_define
define|#
directive|define
name|MAP_CHANGED
value|4
end_define

begin_comment
comment|/* Mapping has changed */
end_comment

begin_define
define|#
directive|define
name|MAP_FAILED
value|5
end_define

begin_comment
comment|/* Mapping request has failed */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IPATM_IPATM_SERV_H */
end_comment

end_unit

