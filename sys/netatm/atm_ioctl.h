begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * PF_ATM socket ioctl definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_ATM_IOCTL_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_ATM_IOCTL_H
end_define

begin_comment
comment|/*  * Structure for PF_ATM configure (AIOCCFG) socket ioctls  */
end_comment

begin_struct
struct|struct
name|atmcfgreq
block|{
name|int
name|acr_opcode
decl_stmt|;
comment|/* Sub-operation */
union|union
block|{
struct|struct
block|{
comment|/* Configure - attach */
name|char
name|acru_att_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|u_char
name|acru_att_proto
decl_stmt|;
comment|/* Signalling protocol */
block|}
name|acru_att
struct|;
struct|struct
block|{
comment|/* Configure - detach */
name|char
name|acru_det_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
block|}
name|acru_det
struct|;
block|}
name|acr_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|acr_att_intf
value|acr_u.acru_att.acru_att_intf
end_define

begin_define
define|#
directive|define
name|acr_att_proto
value|acr_u.acru_att.acru_att_proto
end_define

begin_define
define|#
directive|define
name|acr_det_intf
value|acr_u.acru_det.acru_det_intf
end_define

begin_comment
comment|/*  * Structure for PF_ATM set (AIOCSET) socket ioctls  */
end_comment

begin_struct
struct|struct
name|atmsetreq
block|{
name|int
name|asr_opcode
decl_stmt|;
comment|/* Sub-operation */
union|union
block|{
comment|/* ARP server */
struct|struct
block|{
name|char
name|asru_arp_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|Atm_addr
name|asru_arp_addr
decl_stmt|;
comment|/* ARP srvr address */
name|Atm_addr
name|asru_arp_subaddr
decl_stmt|;
comment|/* ARP srvr subaddr */
name|caddr_t
name|asru_arp_pbuf
decl_stmt|;
comment|/* Prefix buffer addr */
name|int
name|asru_arp_plen
decl_stmt|;
comment|/* Prefix buffer len */
block|}
name|asru_asrvr
struct|;
comment|/* MAC address */
struct|struct
block|{
name|char
name|asru_mac_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|struct
name|mac_addr
name|asru_mac_addr
decl_stmt|;
comment|/* MAC address */
block|}
name|asru_mac
struct|;
comment|/* Network interface */
struct|struct
block|{
name|char
name|asru_nif_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|char
name|asru_nif_pref
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* I/f prefix name */
name|int
name|asru_nif_cnt
decl_stmt|;
comment|/* Number of i/fs */
block|}
name|asru_nif
struct|;
comment|/* NSAP prefix */
struct|struct
block|{
name|char
name|asru_prf_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|u_char
name|asru_prf_pref
index|[
literal|13
index|]
decl_stmt|;
comment|/* NSAP prefix */
block|}
name|asru_prf
struct|;
block|}
name|asr_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|asr_arp_intf
value|asr_u.asru_asrvr.asru_arp_intf
end_define

begin_define
define|#
directive|define
name|asr_arp_addr
value|asr_u.asru_asrvr.asru_arp_addr
end_define

begin_define
define|#
directive|define
name|asr_arp_pbuf
value|asr_u.asru_asrvr.asru_arp_pbuf
end_define

begin_define
define|#
directive|define
name|asr_arp_plen
value|asr_u.asru_asrvr.asru_arp_plen
end_define

begin_define
define|#
directive|define
name|asr_arp_subaddr
value|asr_u.asru_asrvr.asru_arp_subaddr
end_define

begin_define
define|#
directive|define
name|asr_mac_intf
value|asr_u.asru_mac.asru_mac_intf
end_define

begin_define
define|#
directive|define
name|asr_mac_addr
value|asr_u.asru_mac.asru_mac_addr
end_define

begin_define
define|#
directive|define
name|asr_nif_intf
value|asr_u.asru_nif.asru_nif_intf
end_define

begin_define
define|#
directive|define
name|asr_nif_pref
value|asr_u.asru_nif.asru_nif_pref
end_define

begin_define
define|#
directive|define
name|asr_nif_cnt
value|asr_u.asru_nif.asru_nif_cnt
end_define

begin_define
define|#
directive|define
name|asr_prf_intf
value|asr_u.asru_prf.asru_prf_intf
end_define

begin_define
define|#
directive|define
name|asr_prf_pref
value|asr_u.asru_prf.asru_prf_pref
end_define

begin_comment
comment|/*  * Structure for PF_ATM add (AIOCADD) socket ioctls  */
end_comment

begin_struct
struct|struct
name|atmaddreq
block|{
name|int
name|aar_opcode
decl_stmt|;
comment|/* Sub-operation */
union|union
block|{
comment|/* Add PVC */
struct|struct
block|{
name|char
name|aaru_pvc_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|u_short
name|aaru_pvc_vpi
decl_stmt|;
comment|/* VPI value */
name|u_short
name|aaru_pvc_vci
decl_stmt|;
comment|/* VCI value */
name|struct
name|sockaddr
name|aaru_pvc_dst
decl_stmt|;
comment|/* Destination addr */
name|Sap_t
name|aaru_pvc_sap
decl_stmt|;
comment|/* Endpoint SAP */
name|Aal_t
name|aaru_pvc_aal
decl_stmt|;
comment|/* AAL */
name|Encaps_t
name|aaru_pvc_encaps
decl_stmt|;
comment|/* Encapsulation */
name|u_char
name|aaru_pvc_flags
decl_stmt|;
comment|/* Flags (see below) */
block|}
name|aaru_add_pvc
struct|;
comment|/* Add ARP table entry */
struct|struct
block|{
name|char
name|aaru_arp_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|struct
name|sockaddr
name|aaru_arp_dst
decl_stmt|;
comment|/* IP addr */
name|Atm_addr
name|aaru_arp_addr
decl_stmt|;
comment|/* ATM addr */
name|u_char
name|aaru_arp_origin
decl_stmt|;
comment|/* Entry origin */
block|}
name|aaru_add_arp
struct|;
block|}
name|aar_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|aar_pvc_intf
value|aar_u.aaru_add_pvc.aaru_pvc_intf
end_define

begin_define
define|#
directive|define
name|aar_pvc_vpi
value|aar_u.aaru_add_pvc.aaru_pvc_vpi
end_define

begin_define
define|#
directive|define
name|aar_pvc_vci
value|aar_u.aaru_add_pvc.aaru_pvc_vci
end_define

begin_define
define|#
directive|define
name|aar_pvc_dst
value|aar_u.aaru_add_pvc.aaru_pvc_dst
end_define

begin_define
define|#
directive|define
name|aar_pvc_sap
value|aar_u.aaru_add_pvc.aaru_pvc_sap
end_define

begin_define
define|#
directive|define
name|aar_pvc_aal
value|aar_u.aaru_add_pvc.aaru_pvc_aal
end_define

begin_define
define|#
directive|define
name|aar_pvc_encaps
value|aar_u.aaru_add_pvc.aaru_pvc_encaps
end_define

begin_define
define|#
directive|define
name|aar_pvc_flags
value|aar_u.aaru_add_pvc.aaru_pvc_flags
end_define

begin_define
define|#
directive|define
name|aar_arp_intf
value|aar_u.aaru_add_arp.aaru_arp_intf
end_define

begin_define
define|#
directive|define
name|aar_arp_dst
value|aar_u.aaru_add_arp.aaru_arp_dst
end_define

begin_define
define|#
directive|define
name|aar_arp_addr
value|aar_u.aaru_add_arp.aaru_arp_addr
end_define

begin_define
define|#
directive|define
name|aar_arp_origin
value|aar_u.aaru_add_arp.aaru_arp_origin
end_define

begin_comment
comment|/* PVC flags */
end_comment

begin_define
define|#
directive|define
name|PVC_DYN
value|0x01
end_define

begin_comment
comment|/* Dest addr is dynamic */
end_comment

begin_comment
comment|/*  * Structure for PF_ATM delete (AIOCDEL) socket ioctls  */
end_comment

begin_struct
struct|struct
name|atmdelreq
block|{
name|int
name|adr_opcode
decl_stmt|;
comment|/* Sub-operation */
union|union
block|{
comment|/* Delete PVC */
struct|struct
block|{
name|char
name|adru_pvc_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|u_short
name|adru_pvc_vpi
decl_stmt|;
comment|/* VPI value */
name|u_short
name|adru_pvc_vci
decl_stmt|;
comment|/* VCI value */
block|}
name|adru_del_pvc
struct|;
comment|/* Delete SVC */
struct|struct
block|{
name|char
name|adru_svc_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|u_short
name|adru_svc_vpi
decl_stmt|;
comment|/* VPI value */
name|u_short
name|adru_svc_vci
decl_stmt|;
comment|/* VCI value */
block|}
name|adru_del_svc
struct|;
comment|/* Delete ARP table entry */
struct|struct
block|{
name|char
name|adru_arp_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|struct
name|sockaddr
name|adru_arp_dst
decl_stmt|;
comment|/* IP addr */
block|}
name|adru_del_arp
struct|;
block|}
name|adr_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|adr_pvc_intf
value|adr_u.adru_del_pvc.adru_pvc_intf
end_define

begin_define
define|#
directive|define
name|adr_pvc_vpi
value|adr_u.adru_del_pvc.adru_pvc_vpi
end_define

begin_define
define|#
directive|define
name|adr_pvc_vci
value|adr_u.adru_del_pvc.adru_pvc_vci
end_define

begin_define
define|#
directive|define
name|adr_svc_intf
value|adr_u.adru_del_svc.adru_svc_intf
end_define

begin_define
define|#
directive|define
name|adr_svc_vpi
value|adr_u.adru_del_svc.adru_svc_vpi
end_define

begin_define
define|#
directive|define
name|adr_svc_vci
value|adr_u.adru_del_svc.adru_svc_vci
end_define

begin_define
define|#
directive|define
name|adr_arp_intf
value|adr_u.adru_del_arp.adru_arp_intf
end_define

begin_define
define|#
directive|define
name|adr_arp_dst
value|adr_u.adru_del_arp.adru_arp_dst
end_define

begin_comment
comment|/*  * Structure for PF_ATM information (AIOCINFO) socket ioctls  */
end_comment

begin_struct
struct|struct
name|atminfreq
block|{
name|int
name|air_opcode
decl_stmt|;
comment|/* Sub-operation */
name|caddr_t
name|air_buf_addr
decl_stmt|;
comment|/* Buffer for returned info */
name|int
name|air_buf_len
decl_stmt|;
comment|/* Buffer length */
union|union
block|{
comment|/* Vendor info */
name|char
name|airu_vinfo_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
comment|/* IP VCC */
name|struct
name|sockaddr
name|airu_ip_addr
decl_stmt|;
comment|/* Destination host */
comment|/* ARP table */
struct|struct
block|{
name|struct
name|sockaddr
name|airu_arp_addr
decl_stmt|;
comment|/* Destination host */
name|u_char
name|airu_arp_flags
decl_stmt|;
comment|/* Flags (see below) */
block|}
name|airu_arp
struct|;
comment|/* ARP server */
name|char
name|airu_asrv_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
comment|/* Interface */
name|char
name|airu_int_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
comment|/* VCC */
name|char
name|airu_vcc_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
comment|/* Configuration */
name|char
name|airu_cfg_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
comment|/* Network interface */
name|char
name|airu_netif_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
comment|/* Physical interface statistics */
name|char
name|airu_physt_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
block|}
name|air_u
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|air_vinfo_intf
value|air_u.airu_vinfo_intf
end_define

begin_define
define|#
directive|define
name|air_ip_addr
value|air_u.airu_ip_addr
end_define

begin_define
define|#
directive|define
name|air_arp_addr
value|air_u.airu_arp.airu_arp_addr
end_define

begin_define
define|#
directive|define
name|air_arp_flags
value|air_u.airu_arp.airu_arp_flags
end_define

begin_define
define|#
directive|define
name|air_asrv_intf
value|air_u.airu_asrv_intf
end_define

begin_define
define|#
directive|define
name|air_int_intf
value|air_u.airu_int_intf
end_define

begin_define
define|#
directive|define
name|air_vcc_intf
value|air_u.airu_vcc_intf
end_define

begin_define
define|#
directive|define
name|air_cfg_intf
value|air_u.airu_cfg_intf
end_define

begin_define
define|#
directive|define
name|air_netif_intf
value|air_u.airu_netif_intf
end_define

begin_define
define|#
directive|define
name|air_physt_intf
value|air_u.airu_physt_intf
end_define

begin_comment
comment|/* ARP table info flags */
end_comment

begin_define
define|#
directive|define
name|ARP_RESET_REF
value|0x01
end_define

begin_comment
comment|/* Reset refresh status */
end_comment

begin_comment
comment|/*  * Structures returned by information requests  */
end_comment

begin_comment
comment|/*  * Vendor-specific interface information  */
end_comment

begin_struct
struct|struct
name|air_vinfo_rsp
block|{
name|char
name|avsp_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|int
name|avsp_len
decl_stmt|;
comment|/* Length of returned 							Vendor Info block */
comment|/* Vendor info ... */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ARP table information  */
end_comment

begin_struct
struct|struct
name|air_arp_rsp
block|{
name|struct
name|sockaddr
name|aap_arp_addr
decl_stmt|;
comment|/* Destination host */
name|char
name|aap_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|u_char
name|aap_flags
decl_stmt|;
comment|/* Flags (see below) */
name|u_char
name|aap_origin
decl_stmt|;
comment|/* Entry origin (see below) */
name|u_char
name|aap_age
decl_stmt|;
comment|/* Aging timeout (minutes) */
name|Atm_addr
name|aap_addr
decl_stmt|;
comment|/* ATM address */
name|Atm_addr
name|aap_subaddr
decl_stmt|;
comment|/* ATM subaddress */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ARP entry flags  */
end_comment

begin_define
define|#
directive|define
name|ARPF_VALID
value|0x01
end_define

begin_comment
comment|/* Entry is valid */
end_comment

begin_define
define|#
directive|define
name|ARPF_REFRESH
value|0x02
end_define

begin_comment
comment|/* Entry has been refreshed */
end_comment

begin_comment
comment|/*  * ARP entry origin  */
end_comment

begin_define
define|#
directive|define
name|ARP_ORIG_PERM
value|50
end_define

begin_comment
comment|/* Permanent entry */
end_comment

begin_comment
comment|/*  * IP VCC information  */
end_comment

begin_struct
struct|struct
name|air_ip_vcc_rsp
block|{
name|struct
name|sockaddr
name|aip_dst_addr
decl_stmt|;
comment|/* Destination host */
name|char
name|aip_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|u_short
name|aip_vpi
decl_stmt|;
comment|/* VPI value */
name|u_short
name|aip_vci
decl_stmt|;
comment|/* VCI value */
name|u_char
name|aip_sig_proto
decl_stmt|;
comment|/* Signalling protocol */
name|u_char
name|aip_flags
decl_stmt|;
comment|/* Flags (IVF_*) */
name|u_char
name|aip_state
decl_stmt|;
comment|/* IP VCC state */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ARP server information  */
end_comment

begin_struct
struct|struct
name|air_asrv_rsp
block|{
name|char
name|asp_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|Atm_addr
name|asp_addr
decl_stmt|;
comment|/* Server ATM address */
name|Atm_addr
name|asp_subaddr
decl_stmt|;
comment|/* Server ATM subaddress */
name|int
name|asp_state
decl_stmt|;
comment|/* Server state */
name|int
name|asp_nprefix
decl_stmt|;
comment|/* Number of prefix entries */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Interface information  */
end_comment

begin_struct
struct|struct
name|air_int_rsp
block|{
name|char
name|anp_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|Atm_addr
name|anp_addr
decl_stmt|;
comment|/* ATM address */
name|Atm_addr
name|anp_subaddr
decl_stmt|;
comment|/* ATM subaddress */
name|u_char
name|anp_sig_proto
decl_stmt|;
comment|/* Signalling protocol */
name|u_char
name|anp_sig_state
decl_stmt|;
comment|/* Signalling protocol state */
name|char
name|anp_nif_pref
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Netif prefix */
name|int
name|anp_nif_cnt
decl_stmt|;
comment|/* No. of netifs */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Network interface information  */
end_comment

begin_struct
struct|struct
name|air_netif_rsp
block|{
name|char
name|anp_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|struct
name|sockaddr
name|anp_proto_addr
decl_stmt|;
comment|/* Protocol address */
name|char
name|anp_phy_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
block|}
struct|;
end_struct

begin_comment
comment|/*  * VCC information  */
end_comment

begin_define
define|#
directive|define
name|O_CNT
value|8
end_define

begin_struct
struct|struct
name|air_vcc_rsp
block|{
name|char
name|avp_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|u_short
name|avp_vpi
decl_stmt|;
comment|/* VPI value */
name|u_short
name|avp_vci
decl_stmt|;
comment|/* VCI value */
name|u_char
name|avp_type
decl_stmt|;
comment|/* Type (SVC or PVC) */
name|u_char
name|avp_aal
decl_stmt|;
comment|/* AAL */
name|u_char
name|avp_sig_proto
decl_stmt|;
comment|/* Signalling protocol */
name|Encaps_t
name|avp_encaps
decl_stmt|;
comment|/* Encapsulation */
name|u_char
name|avp_state
decl_stmt|;
comment|/* State (sig mgr specific) */
name|char
name|avp_owners
index|[
operator|(
name|T_ATM_APP_NAME_LEN
operator|+
literal|1
operator|)
operator|*
name|O_CNT
index|]
decl_stmt|;
comment|/* VCC users */
name|Atm_addr
name|avp_daddr
decl_stmt|;
comment|/* Address of far end */
name|Atm_addr
name|avp_dsubaddr
decl_stmt|;
comment|/* Subaddress of far end */
name|long
name|avp_ipdus
decl_stmt|;
comment|/* PDUs received from VCC */
name|long
name|avp_opdus
decl_stmt|;
comment|/* PDUs sent to VCC */
name|long
name|avp_ibytes
decl_stmt|;
comment|/* Bytes received from VCC */
name|long
name|avp_obytes
decl_stmt|;
comment|/* Bytes sent to VCC */
name|long
name|avp_ierrors
decl_stmt|;
comment|/* Errors receiving from VCC */
name|long
name|avp_oerrors
decl_stmt|;
comment|/* Errors sending to VCC */
name|time_t
name|avp_tstamp
decl_stmt|;
comment|/* State transition timestamp */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Adapter configuration information  */
end_comment

begin_struct
struct|struct
name|air_cfg_rsp
block|{
name|char
name|acp_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|Atm_config
name|acp_cfg
decl_stmt|;
comment|/* Config info */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|acp_vendor
value|acp_cfg.ac_vendor
end_define

begin_define
define|#
directive|define
name|acp_vendapi
value|acp_cfg.ac_vendapi
end_define

begin_define
define|#
directive|define
name|acp_device
value|acp_cfg.ac_device
end_define

begin_define
define|#
directive|define
name|acp_media
value|acp_cfg.ac_media
end_define

begin_define
define|#
directive|define
name|acp_serial
value|acp_cfg.ac_serial
end_define

begin_define
define|#
directive|define
name|acp_bustype
value|acp_cfg.ac_bustype
end_define

begin_define
define|#
directive|define
name|acp_busslot
value|acp_cfg.ac_busslot
end_define

begin_define
define|#
directive|define
name|acp_ram
value|acp_cfg.ac_ram
end_define

begin_define
define|#
directive|define
name|acp_ramsize
value|acp_cfg.ac_ramsize
end_define

begin_define
define|#
directive|define
name|acp_macaddr
value|acp_cfg.ac_macaddr
end_define

begin_define
define|#
directive|define
name|acp_hard_vers
value|acp_cfg.ac_hard_vers
end_define

begin_define
define|#
directive|define
name|acp_firm_vers
value|acp_cfg.ac_firm_vers
end_define

begin_comment
comment|/*  * Version information  */
end_comment

begin_struct
struct|struct
name|air_version_rsp
block|{
name|int
name|avp_version
decl_stmt|;
comment|/* Software version */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Physical interface statistics  */
end_comment

begin_struct
struct|struct
name|air_phy_stat_rsp
block|{
name|char
name|app_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Interface name */
name|long
name|app_ipdus
decl_stmt|;
comment|/* PDUs received from I/F */
name|long
name|app_opdus
decl_stmt|;
comment|/* PDUs sent to I/F */
name|long
name|app_ibytes
decl_stmt|;
comment|/* Bytes received from I/F */
name|long
name|app_obytes
decl_stmt|;
comment|/* Bytes sent to I/F */
name|long
name|app_ierrors
decl_stmt|;
comment|/* Errors receiving from I/F */
name|long
name|app_oerrors
decl_stmt|;
comment|/* Errors sending to I/F */
name|long
name|app_cmderrors
decl_stmt|;
comment|/* I/F command errors */
block|}
struct|;
end_struct

begin_comment
comment|/*  * PF_ATM sub-operation codes  */
end_comment

begin_define
define|#
directive|define
name|AIOCS_CFG_ATT
value|1
end_define

begin_define
define|#
directive|define
name|AIOCS_CFG_DET
value|2
end_define

begin_define
define|#
directive|define
name|AIOCS_ADD_PVC
value|32
end_define

begin_define
define|#
directive|define
name|AIOCS_ADD_ARP
value|33
end_define

begin_define
define|#
directive|define
name|AIOCS_DEL_PVC
value|64
end_define

begin_define
define|#
directive|define
name|AIOCS_DEL_SVC
value|65
end_define

begin_define
define|#
directive|define
name|AIOCS_DEL_ARP
value|66
end_define

begin_define
define|#
directive|define
name|AIOCS_SET_ASV
value|96
end_define

begin_define
define|#
directive|define
name|AIOCS_SET_NIF
value|97
end_define

begin_define
define|#
directive|define
name|AIOCS_SET_PRF
value|98
end_define

begin_define
define|#
directive|define
name|AIOCS_SET_MAC
value|99
end_define

begin_define
define|#
directive|define
name|AIOCS_INF_VST
value|160
end_define

begin_define
define|#
directive|define
name|AIOCS_INF_IPM
value|161
end_define

begin_define
define|#
directive|define
name|AIOCS_INF_ARP
value|162
end_define

begin_define
define|#
directive|define
name|AIOCS_INF_ASV
value|163
end_define

begin_define
define|#
directive|define
name|AIOCS_INF_INT
value|164
end_define

begin_define
define|#
directive|define
name|AIOCS_INF_VCC
value|165
end_define

begin_define
define|#
directive|define
name|AIOCS_INF_CFG
value|166
end_define

begin_define
define|#
directive|define
name|AIOCS_INF_NIF
value|167
end_define

begin_define
define|#
directive|define
name|AIOCS_INF_PIS
value|168
end_define

begin_define
define|#
directive|define
name|AIOCS_INF_VER
value|169
end_define

begin_comment
comment|/*  * PF_ATM ioctls  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|AIOCCFG
value|_IOW(A, 128, struct atmcfgreq)
end_define

begin_comment
comment|/* Configure i/f */
end_comment

begin_define
define|#
directive|define
name|AIOCADD
value|_IOW(A, 129, struct atmaddreq)
end_define

begin_comment
comment|/* Add (e.g. PVC) */
end_comment

begin_define
define|#
directive|define
name|AIOCDEL
value|_IOW(A, 130, struct atmdelreq)
end_define

begin_comment
comment|/* Delete */
end_comment

begin_define
define|#
directive|define
name|AIOCSET
value|_IOW(A, 132, struct atmsetreq)
end_define

begin_comment
comment|/* Set (e.g. net i/f) */
end_comment

begin_define
define|#
directive|define
name|AIOCINFO
value|_IOWR(A, 133, struct atminfreq)
end_define

begin_comment
comment|/* Show kernel info */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AIOCCFG
value|_IOW('A', 128, struct atmcfgreq)
end_define

begin_comment
comment|/* Configure i/f */
end_comment

begin_define
define|#
directive|define
name|AIOCADD
value|_IOW('A', 129, struct atmaddreq)
end_define

begin_comment
comment|/* Add (e.g. PVC) */
end_comment

begin_define
define|#
directive|define
name|AIOCDEL
value|_IOW('A', 130, struct atmdelreq)
end_define

begin_comment
comment|/* Delete */
end_comment

begin_define
define|#
directive|define
name|AIOCSET
value|_IOW('A', 132, struct atmsetreq)
end_define

begin_comment
comment|/* Set (e.g. net i/f) */
end_comment

begin_define
define|#
directive|define
name|AIOCINFO
value|_IOWR('A', 133, struct atminfreq)
end_define

begin_comment
comment|/* Show kernel info */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETATM_ATM_IOCTL_H */
end_comment

end_unit

