begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * ATM address family definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_ATM_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_ATM_H
end_define

begin_comment
comment|/*  * The definitions in this file are intended to conform to the   * specifications defined in:  *  *	The Open Group, Networking Services (XNS) Issue 5  *  *	ATM Transport Protocol Information for Sockets  *  * which is Copyright (c) 1997, The Open Group.  *  * All extensions contained in this file to the base specification   * are denoted with a comment string of "XNS_EXT".  */
end_comment

begin_comment
comment|/*  * ATM socket protocols  */
end_comment

begin_define
define|#
directive|define
name|ATM_PROTO_AAL5
value|0x5301
end_define

begin_comment
comment|/* AAL type 5 protocol */
end_comment

begin_define
define|#
directive|define
name|ATM_PROTO_SSCOP
value|0x5302
end_define

begin_comment
comment|/* SSCOP protocol      */
end_comment

begin_comment
comment|/*  * ATM address defintions  */
end_comment

begin_comment
comment|/*  * General format of an ATM address  */
end_comment

begin_define
define|#
directive|define
name|ATM_ADDR_LEN
value|20
end_define

begin_comment
comment|/* Size of address field (XNS_EXT) */
end_comment

begin_struct
struct|struct
name|t_atm_addr
block|{
name|int8_t
name|address_format
decl_stmt|;
comment|/* Address format (see below) */
name|u_int8_t
name|address_length
decl_stmt|;
comment|/* Length of address field */
name|u_int8_t
name|address
index|[
name|ATM_ADDR_LEN
index|]
decl_stmt|;
comment|/* Address field */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|t_atm_addr
name|Atm_addr
typedef|;
end_typedef

begin_comment
comment|/* XNS_EXT */
end_comment

begin_comment
comment|/*  * ATM address formats  */
end_comment

begin_define
define|#
directive|define
name|T_ATM_ABSENT
value|(-1)
end_define

begin_comment
comment|/* No address present */
end_comment

begin_define
define|#
directive|define
name|T_ATM_ENDSYS_ADDR
value|1
end_define

begin_comment
comment|/* ATM Endsystem */
end_comment

begin_define
define|#
directive|define
name|T_ATM_NSAP_ADDR
value|1
end_define

begin_comment
comment|/* NSAP */
end_comment

begin_define
define|#
directive|define
name|T_ATM_E164_ADDR
value|2
end_define

begin_comment
comment|/* E.164 */
end_comment

begin_define
define|#
directive|define
name|T_ATM_SPANS_ADDR
value|3
end_define

begin_comment
comment|/* FORE SPANS (XNS_EXT) */
end_comment

begin_define
define|#
directive|define
name|T_ATM_PVC_ADDR
value|4
end_define

begin_comment
comment|/* PVC (VPI,VCI) (XNS_EXT) */
end_comment

begin_comment
comment|/*  * ATM Endsystem / NSAP address format  */
end_comment

begin_struct
struct|struct
name|atm_addr_nsap
block|{
comment|/* XNS_EXT */
name|u_char
name|aan_afi
decl_stmt|;
comment|/* Authority and Format Identifier */
comment|/* (see below) */
name|u_char
name|aan_afspec
index|[
literal|12
index|]
decl_stmt|;
comment|/* AFI specific fields */
name|u_char
name|aan_esi
index|[
literal|6
index|]
decl_stmt|;
comment|/* End System Identifier */
name|u_char
name|aan_sel
decl_stmt|;
comment|/* Selector */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atm_addr_nsap
name|Atm_addr_nsap
typedef|;
end_typedef

begin_comment
comment|/*  * AFI codes  */
end_comment

begin_define
define|#
directive|define
name|AFI_DCC
value|0x39
end_define

begin_comment
comment|/* DCC ATM Format (XNS_EXT) */
end_comment

begin_define
define|#
directive|define
name|AFI_ICD
value|0x47
end_define

begin_comment
comment|/* ICD ATM Format (XNS_EXT) */
end_comment

begin_define
define|#
directive|define
name|AFI_E164
value|0x45
end_define

begin_comment
comment|/* E.164 ATM Format (XNS_EXT) */
end_comment

begin_comment
comment|/*  * E.164 address format  */
end_comment

begin_struct
struct|struct
name|atm_addr_e164
block|{
comment|/* XNS_EXT */
name|u_char
name|aae_addr
index|[
literal|15
index|]
decl_stmt|;
comment|/* E.164 address */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atm_addr_e164
name|Atm_addr_e164
typedef|;
end_typedef

begin_comment
comment|/*  * SPANS address format  */
end_comment

begin_struct
struct|struct
name|atm_addr_spans
block|{
comment|/* XNS_EXT */
name|u_char
name|aas_addr
index|[
literal|8
index|]
decl_stmt|;
comment|/* See SPANS code for specific fields */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atm_addr_spans
name|Atm_addr_spans
typedef|;
end_typedef

begin_comment
comment|/*  * PVC address format  */
end_comment

begin_struct
struct|struct
name|atm_addr_pvc
block|{
comment|/* XNS_EXT */
name|u_int8_t
name|aap_vpi
index|[
literal|2
index|]
decl_stmt|;
comment|/* VPI */
name|u_int8_t
name|aap_vci
index|[
literal|2
index|]
decl_stmt|;
comment|/* VCI */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atm_addr_pvc
name|Atm_addr_pvc
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATM_PVC_GET_VPI
parameter_list|(
name|addr
parameter_list|)
comment|/* XNS_EXT */
define|\
value|((u_int16_t)(((addr)->aap_vpi[0]<< 8) | (addr)->aap_vpi[1]))
end_define

begin_define
define|#
directive|define
name|ATM_PVC_GET_VCI
parameter_list|(
name|addr
parameter_list|)
comment|/* XNS_EXT */
define|\
value|((u_int16_t)(((addr)->aap_vci[0]<< 8) | (addr)->aap_vci[1]))
end_define

begin_define
define|#
directive|define
name|ATM_PVC_SET_VPI
parameter_list|(
name|addr
parameter_list|,
name|vpi
parameter_list|)
value|{
comment|/* XNS_EXT */
value|\ 	(addr)->aap_vpi[0] = ((vpi)>> 8)& 0xff;		\ 	(addr)->aap_vpi[1] = (vpi)& 0xff;			\ }
end_define

begin_define
define|#
directive|define
name|ATM_PVC_SET_VCI
parameter_list|(
name|addr
parameter_list|,
name|vci
parameter_list|)
value|{
comment|/* XNS_EXT */
value|\ 	(addr)->aap_vci[0] = ((vci)>> 8)& 0xff;		\ 	(addr)->aap_vci[1] = (vci)& 0xff;			\ }
end_define

begin_comment
comment|/*  * ATM service access point (SAP)  *  * A SAP address consists of SAP Vector Elements (SVE).  Each SVE consists   * of the following fields:  * 	o tag - defines the interpretation of the SVE;  * 	o length - the length of the SVE value field;  * 	o value - the value associated with the SVE;  *  * All of the possible SAP field values are either defined below  * or in the corresponding option value definitions.  */
end_comment

begin_comment
comment|/*  * ATM Address and Selector SVE  */
end_comment

begin_struct
struct|struct
name|t_atm_sap_addr
block|{
name|int8_t
name|SVE_tag_addr
decl_stmt|;
comment|/* SVE tag (address) */
name|int8_t
name|SVE_tag_selector
decl_stmt|;
comment|/* SVE tag (selector) */
comment|/* Address/selector value */
name|int8_t
name|address_format
decl_stmt|;
comment|/* Address format */
name|u_int8_t
name|address_length
decl_stmt|;
comment|/* Length of address field */
name|u_int8_t
name|address
index|[
name|ATM_ADDR_LEN
index|]
decl_stmt|;
comment|/* Address field */
block|}
struct|;
end_struct

begin_comment
comment|/*  * B-LLI Layer 2 SVE  */
end_comment

begin_struct
struct|struct
name|t_atm_sap_layer2
block|{
name|int8_t
name|SVE_tag
decl_stmt|;
comment|/* SVE tag */
name|u_int8_t
name|ID_type
decl_stmt|;
comment|/* Layer 2 protocol discriminator */
union|union
block|{
comment|/* Layer 2 protocol */
name|u_int8_t
name|simple_ID
decl_stmt|;
comment|/* ITU */
name|u_int8_t
name|user_defined_ID
decl_stmt|;
comment|/* User-defined */
block|}
name|ID
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * B-LLI Layer 3 SVE  */
end_comment

begin_struct
struct|struct
name|t_atm_sap_layer3
block|{
name|int8_t
name|SVE_tag
decl_stmt|;
comment|/* SVE tag */
name|u_int8_t
name|ID_type
decl_stmt|;
comment|/* Layer 3 protocol discriminator */
union|union
block|{
comment|/* Layer 3 protocol */
name|u_int8_t
name|simple_ID
decl_stmt|;
comment|/* ITU */
name|u_int8_t
name|IPI_ID
decl_stmt|;
comment|/* ISO IPI */
struct|struct
block|{
comment|/* IEEE 802.1 SNAP ID */
name|u_int8_t
name|OUI
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|PID
index|[
literal|2
index|]
decl_stmt|;
block|}
name|SNAP_ID
struct|;
name|u_int8_t
name|user_defined_ID
decl_stmt|;
comment|/* User-defined */
block|}
name|ID
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * B_HLI SVE  */
end_comment

begin_struct
struct|struct
name|t_atm_sap_appl
block|{
name|int8_t
name|SVE_tag
decl_stmt|;
comment|/* SVE tag */
name|u_int8_t
name|ID_type
decl_stmt|;
comment|/* High Layer type discriminator */
union|union
block|{
comment|/* High Layer type */
name|u_int8_t
name|ISO_ID
index|[
literal|8
index|]
decl_stmt|;
comment|/* ISO */
struct|struct
block|{
comment|/* Vendor-specific */
name|u_int8_t
name|OUI
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|app_ID
index|[
literal|4
index|]
decl_stmt|;
block|}
name|vendor_ID
struct|;
name|u_int8_t
name|user_defined_ID
index|[
literal|8
index|]
decl_stmt|;
comment|/* User-defined */
block|}
name|ID
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ATM SAP (protocol) address structure  */
end_comment

begin_struct
struct|struct
name|t_atm_sap
block|{
name|struct
name|t_atm_sap_addr
name|t_atm_sap_addr
decl_stmt|;
name|struct
name|t_atm_sap_layer2
name|t_atm_sap_layer2
decl_stmt|;
name|struct
name|t_atm_sap_layer3
name|t_atm_sap_layer3
decl_stmt|;
name|struct
name|t_atm_sap_appl
name|t_atm_sap_appl
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * SVE Tag values  */
end_comment

begin_define
define|#
directive|define
name|T_ATM_ABSENT
value|(-1)
end_define

begin_comment
comment|/* Value field invalid; match none */
end_comment

begin_define
define|#
directive|define
name|T_ATM_PRESENT
value|(-2)
end_define

begin_comment
comment|/* Value field valid; match value */
end_comment

begin_define
define|#
directive|define
name|T_ATM_ANY
value|(-3)
end_define

begin_comment
comment|/* Value field invalid; match any */
end_comment

begin_comment
comment|/*  * ATM socket address  */
end_comment

begin_struct
struct|struct
name|sockaddr_atm
block|{
comment|/* XNS_EXT */
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
operator|(
name|BSD
operator|>=
literal|199103
operator|)
operator|)
name|u_char
name|satm_len
decl_stmt|;
comment|/* Length of socket structure */
name|u_char
name|satm_family
decl_stmt|;
comment|/* Address family */
else|#
directive|else
name|u_short
name|satm_family
decl_stmt|;
comment|/* Address family */
endif|#
directive|endif
name|struct
name|t_atm_sap
name|satm_addr
decl_stmt|;
comment|/* Protocol address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ATM socket options for use with [gs]etsockopt()  */
end_comment

begin_define
define|#
directive|define
name|T_ATM_SIGNALING
value|0x5301
end_define

begin_comment
comment|/* Option level */
end_comment

begin_define
define|#
directive|define
name|T_ATM_AAL5
value|1
end_define

begin_comment
comment|/* ATM adaptation layer 5      */
end_comment

begin_define
define|#
directive|define
name|T_ATM_TRAFFIC
value|2
end_define

begin_comment
comment|/* ATM traffic descriptor      */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BEARER_CAP
value|3
end_define

begin_comment
comment|/* ATM service capabilities    */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BHLI
value|4
end_define

begin_comment
comment|/* Higher-layer protocol       */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI
value|5
end_define

begin_comment
comment|/* Lower-layer protocol        */
end_comment

begin_define
define|#
directive|define
name|T_ATM_DEST_ADDR
value|6
end_define

begin_comment
comment|/* Call responder's address    */
end_comment

begin_define
define|#
directive|define
name|T_ATM_DEST_SUB
value|7
end_define

begin_comment
comment|/* Call responder's subaddress */
end_comment

begin_define
define|#
directive|define
name|T_ATM_ORIG_ADDR
value|8
end_define

begin_comment
comment|/* Call initiator's address    */
end_comment

begin_define
define|#
directive|define
name|T_ATM_ORIG_SUB
value|9
end_define

begin_comment
comment|/* Call initiator's subaddress */
end_comment

begin_define
define|#
directive|define
name|T_ATM_CALLER_ID
value|10
end_define

begin_comment
comment|/* Caller's ID attributes      */
end_comment

begin_define
define|#
directive|define
name|T_ATM_CAUSE
value|11
end_define

begin_comment
comment|/* Cause of disconection       */
end_comment

begin_define
define|#
directive|define
name|T_ATM_QOS
value|12
end_define

begin_comment
comment|/* Quality of service          */
end_comment

begin_define
define|#
directive|define
name|T_ATM_TRANSIT
value|13
end_define

begin_comment
comment|/* Choice of public carrier    */
end_comment

begin_define
define|#
directive|define
name|T_ATM_ADD_LEAF
value|14
end_define

begin_comment
comment|/* Add leaf to connection      */
end_comment

begin_define
define|#
directive|define
name|T_ATM_DROP_LEAF
value|15
end_define

begin_comment
comment|/* Remove leaf from connection */
end_comment

begin_define
define|#
directive|define
name|T_ATM_LEAF_IND
value|16
end_define

begin_comment
comment|/* Indication of leaf status   */
end_comment

begin_define
define|#
directive|define
name|T_ATM_NET_INTF
value|17
end_define

begin_comment
comment|/* Network interface XNS_EXT   */
end_comment

begin_define
define|#
directive|define
name|T_ATM_LLC
value|18
end_define

begin_comment
comment|/* LLC multiplexing XNS_EXT    */
end_comment

begin_define
define|#
directive|define
name|T_ATM_APP_NAME
value|19
end_define

begin_comment
comment|/* Application name XNS_EXT    */
end_comment

begin_comment
comment|/*  * Common socket option values  *  * See API specification for individual option applicability/meaning  */
end_comment

begin_define
define|#
directive|define
name|T_ATM_ABSENT
value|(-1)
end_define

begin_comment
comment|/* No option value present */
end_comment

begin_define
define|#
directive|define
name|T_ATM_NULL
value|0
end_define

begin_comment
comment|/* Option value is null */
end_comment

begin_define
define|#
directive|define
name|T_NO
value|0
end_define

begin_comment
comment|/* Option is not requested */
end_comment

begin_define
define|#
directive|define
name|T_YES
value|1
end_define

begin_comment
comment|/* Option is requested */
end_comment

begin_comment
comment|/*  * T_ATM_AAL5 option value structure  */
end_comment

begin_struct
struct|struct
name|t_atm_aal5
block|{
name|int32_t
name|forward_max_SDU_size
decl_stmt|;
name|int32_t
name|backward_max_SDU_size
decl_stmt|;
name|int32_t
name|SSCS_type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_AAL5 option values  */
end_comment

begin_comment
comment|/* SSCS_type */
end_comment

begin_define
define|#
directive|define
name|T_ATM_SSCS_SSCOP_REL
value|1
end_define

begin_comment
comment|/* SSCOP assured operation */
end_comment

begin_define
define|#
directive|define
name|T_ATM_SSCS_SSCOP_UNREL
value|2
end_define

begin_comment
comment|/* SSCOP non-assured operation */
end_comment

begin_define
define|#
directive|define
name|T_ATM_SSCS_FR
value|4
end_define

begin_comment
comment|/* Frame relay */
end_comment

begin_comment
comment|/*  * T_ATM_TRAFFIC option value structure  */
end_comment

begin_struct
struct|struct
name|t_atm_traffic_substruct
block|{
name|int32_t
name|PCR_high_priority
decl_stmt|;
name|int32_t
name|PCR_all_traffic
decl_stmt|;
name|int32_t
name|SCR_high_priority
decl_stmt|;
name|int32_t
name|SCR_all_traffic
decl_stmt|;
name|int32_t
name|MBS_high_priority
decl_stmt|;
name|int32_t
name|MBS_all_traffic
decl_stmt|;
name|int32_t
name|tagging
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t_atm_traffic
block|{
name|struct
name|t_atm_traffic_substruct
name|forward
decl_stmt|;
name|struct
name|t_atm_traffic_substruct
name|backward
decl_stmt|;
name|u_int8_t
name|best_effort
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_BEARER_CAP option value structure  */
end_comment

begin_struct
struct|struct
name|t_atm_bearer
block|{
name|u_int8_t
name|bearer_class
decl_stmt|;
name|u_int8_t
name|traffic_type
decl_stmt|;
name|u_int8_t
name|timing_requirements
decl_stmt|;
name|u_int8_t
name|clipping_susceptibility
decl_stmt|;
name|u_int8_t
name|connection_configuration
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_BEARER_CAP option values  */
end_comment

begin_comment
comment|/* bearer_class */
end_comment

begin_define
define|#
directive|define
name|T_ATM_CLASS_A
value|0x01
end_define

begin_comment
comment|/* Bearer class A                 */
end_comment

begin_define
define|#
directive|define
name|T_ATM_CLASS_C
value|0x03
end_define

begin_comment
comment|/* Bearer class C                 */
end_comment

begin_define
define|#
directive|define
name|T_ATM_CLASS_X
value|0x10
end_define

begin_comment
comment|/* Bearer class X                 */
end_comment

begin_comment
comment|/* traffic_type */
end_comment

begin_define
define|#
directive|define
name|T_ATM_CBR
value|0x01
end_define

begin_comment
comment|/* Constant bit rate              */
end_comment

begin_define
define|#
directive|define
name|T_ATM_VBR
value|0x02
end_define

begin_comment
comment|/* Variable bit rate              */
end_comment

begin_comment
comment|/* timing_requirements */
end_comment

begin_define
define|#
directive|define
name|T_ATM_END_TO_END
value|0x01
end_define

begin_comment
comment|/* End-to-end timing required     */
end_comment

begin_define
define|#
directive|define
name|T_ATM_NO_END_TO_END
value|0x02
end_define

begin_comment
comment|/* End-to-end timing not required */
end_comment

begin_comment
comment|/* connection_configuration */
end_comment

begin_define
define|#
directive|define
name|T_ATM_1_TO_1
value|0x00
end_define

begin_comment
comment|/* Point-to-point connection      */
end_comment

begin_define
define|#
directive|define
name|T_ATM_1_TO_MANY
value|0x01
end_define

begin_comment
comment|/* Point-to-multipoint connection */
end_comment

begin_comment
comment|/*  * T_ATM_BHLI option value structure  */
end_comment

begin_struct
struct|struct
name|t_atm_bhli
block|{
name|int32_t
name|ID_type
decl_stmt|;
union|union
block|{
name|u_int8_t
name|ISO_ID
index|[
literal|8
index|]
decl_stmt|;
struct|struct
block|{
name|u_int8_t
name|OUI
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|app_ID
index|[
literal|4
index|]
decl_stmt|;
block|}
name|vendor_ID
struct|;
name|u_int8_t
name|user_defined_ID
index|[
literal|8
index|]
decl_stmt|;
block|}
name|ID
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_BHLI option values  */
end_comment

begin_comment
comment|/* ID_type */
end_comment

begin_define
define|#
directive|define
name|T_ATM_ISO_APP_ID
value|0
end_define

begin_comment
comment|/* ISO codepoint             */
end_comment

begin_define
define|#
directive|define
name|T_ATM_USER_APP_ID
value|1
end_define

begin_comment
comment|/* User-specific codepoint   */
end_comment

begin_define
define|#
directive|define
name|T_ATM_VENDOR_APP_ID
value|3
end_define

begin_comment
comment|/* Vendor-specific codepoint */
end_comment

begin_comment
comment|/*  * T_ATM_BLLI option value structure  */
end_comment

begin_struct
struct|struct
name|t_atm_blli
block|{
struct|struct
block|{
name|int8_t
name|ID_type
decl_stmt|;
union|union
block|{
name|u_int8_t
name|simple_ID
decl_stmt|;
name|u_int8_t
name|user_defined_ID
decl_stmt|;
block|}
name|ID
union|;
name|int8_t
name|mode
decl_stmt|;
name|int8_t
name|window_size
decl_stmt|;
block|}
name|layer_2_protocol
struct|;
struct|struct
block|{
name|int8_t
name|ID_type
decl_stmt|;
union|union
block|{
name|u_int8_t
name|simple_ID
decl_stmt|;
name|int32_t
name|IPI_ID
decl_stmt|;
struct|struct
block|{
name|u_int8_t
name|OUI
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|PID
index|[
literal|2
index|]
decl_stmt|;
block|}
name|SNAP_ID
struct|;
name|u_int8_t
name|user_defined_ID
decl_stmt|;
block|}
name|ID
union|;
name|int8_t
name|mode
decl_stmt|;
name|int8_t
name|packet_size
decl_stmt|;
name|int8_t
name|window_size
decl_stmt|;
block|}
name|layer_3_protocol
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_BLLI option values  */
end_comment

begin_comment
comment|/* layer_[23]_protocol.ID_type */
end_comment

begin_define
define|#
directive|define
name|T_ATM_SIMPLE_ID
value|1
end_define

begin_comment
comment|/* ID via ITU encoding    */
end_comment

begin_define
define|#
directive|define
name|T_ATM_IPI_ID
value|2
end_define

begin_comment
comment|/* ID via ISO/IEC TR 9577 */
end_comment

begin_define
define|#
directive|define
name|T_ATM_SNAP_ID
value|3
end_define

begin_comment
comment|/* ID via SNAP            */
end_comment

begin_define
define|#
directive|define
name|T_ATM_USER_ID
value|4
end_define

begin_comment
comment|/* ID via user codepoints */
end_comment

begin_comment
comment|/* layer_[23]_protocol.mode */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI_NORMAL_MODE
value|1
end_define

begin_define
define|#
directive|define
name|T_ATM_BLLI_EXTENDED_MODE
value|2
end_define

begin_comment
comment|/* layer_2_protocol.simple_ID */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI2_I1745
value|1
end_define

begin_comment
comment|/* I.1745           */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI2_Q921
value|2
end_define

begin_comment
comment|/* Q.921            */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI2_X25_LINK
value|6
end_define

begin_comment
comment|/* X.25, link layer */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI2_X25_MLINK
value|7
end_define

begin_comment
comment|/* X.25, multilink  */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI2_LAPB
value|8
end_define

begin_comment
comment|/* Extended LAPB    */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI2_HDLC_ARM
value|9
end_define

begin_comment
comment|/* I.4335, ARM      */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI2_HDLC_NRM
value|10
end_define

begin_comment
comment|/* I.4335, NRM      */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI2_HDLC_ABM
value|11
end_define

begin_comment
comment|/* I.4335, ABM      */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI2_I8802
value|12
end_define

begin_comment
comment|/* I.8802           */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI2_X75
value|13
end_define

begin_comment
comment|/* X.75             */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI2_Q922
value|14
end_define

begin_comment
comment|/* Q.922            */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI2_I7776
value|17
end_define

begin_comment
comment|/* I.7776           */
end_comment

begin_comment
comment|/* layer_3_protocol.simple_ID */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI3_X25
value|6
end_define

begin_comment
comment|/* X.25             */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI3_I8208
value|7
end_define

begin_comment
comment|/* I.8208           */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI3_X223
value|8
end_define

begin_comment
comment|/* X.223            */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI3_I8473
value|9
end_define

begin_comment
comment|/* I.8473           */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI3_T70
value|10
end_define

begin_comment
comment|/* T.70             */
end_comment

begin_define
define|#
directive|define
name|T_ATM_BLLI3_I9577
value|11
end_define

begin_comment
comment|/* I.9577           */
end_comment

begin_comment
comment|/* layer_3_protocol.packet_size */
end_comment

begin_define
define|#
directive|define
name|T_ATM_PACKET_SIZE_16
value|4
end_define

begin_define
define|#
directive|define
name|T_ATM_PACKET_SIZE_32
value|5
end_define

begin_define
define|#
directive|define
name|T_ATM_PACKET_SIZE_64
value|6
end_define

begin_define
define|#
directive|define
name|T_ATM_PACKET_SIZE_128
value|7
end_define

begin_define
define|#
directive|define
name|T_ATM_PACKET_SIZE_256
value|8
end_define

begin_define
define|#
directive|define
name|T_ATM_PACKET_SIZE_512
value|9
end_define

begin_define
define|#
directive|define
name|T_ATM_PACKET_SIZE_1024
value|10
end_define

begin_define
define|#
directive|define
name|T_ATM_PACKET_SIZE_2048
value|11
end_define

begin_define
define|#
directive|define
name|T_ATM_PACKET_SIZE_4096
value|12
end_define

begin_comment
comment|/*  * T_ATM_CALLER_ID option value structure  */
end_comment

begin_struct
struct|struct
name|t_atm_caller_id
block|{
name|int8_t
name|presentation
decl_stmt|;
name|u_int8_t
name|screening
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_CALLER_ID option values  */
end_comment

begin_comment
comment|/* presentation */
end_comment

begin_define
define|#
directive|define
name|T_ATM_PRES_ALLOWED
value|0
end_define

begin_define
define|#
directive|define
name|T_ATM_PRES_RESTRICTED
value|1
end_define

begin_define
define|#
directive|define
name|T_ATM_PRES_UNAVAILABLE
value|2
end_define

begin_comment
comment|/* screening */
end_comment

begin_define
define|#
directive|define
name|T_ATM_USER_ID_NOT_SCREENED
value|0
end_define

begin_define
define|#
directive|define
name|T_ATM_USER_ID_PASSED_SCREEN
value|1
end_define

begin_define
define|#
directive|define
name|T_ATM_USER_ID_FAILED_SCREEN
value|2
end_define

begin_define
define|#
directive|define
name|T_ATM_NETWORK_PROVIDED_ID
value|3
end_define

begin_comment
comment|/*  * T_ATM_CAUSE option value structure  */
end_comment

begin_struct
struct|struct
name|t_atm_cause
block|{
name|int8_t
name|coding_standard
decl_stmt|;
name|u_int8_t
name|location
decl_stmt|;
name|u_int8_t
name|cause_value
decl_stmt|;
name|u_int8_t
name|diagnostics
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_CAUSE option values  */
end_comment

begin_comment
comment|/* coding_standard */
end_comment

begin_define
define|#
directive|define
name|T_ATM_ITU_CODING
value|0
end_define

begin_define
define|#
directive|define
name|T_ATM_NETWORK_CODING
value|3
end_define

begin_comment
comment|/* location */
end_comment

begin_define
define|#
directive|define
name|T_ATM_LOC_USER
value|0
end_define

begin_define
define|#
directive|define
name|T_ATM_LOC_LOCAL_PRIVATE_NET
value|1
end_define

begin_define
define|#
directive|define
name|T_ATM_LOC_LOCAL_PUBLIC_NET
value|2
end_define

begin_define
define|#
directive|define
name|T_ATM_LOC_TRANSIT_NET
value|3
end_define

begin_define
define|#
directive|define
name|T_ATM_LOC_REMOTE_PUBLIC_NET
value|4
end_define

begin_define
define|#
directive|define
name|T_ATM_LOC_REMOTE_PRIVATE_NET
value|5
end_define

begin_define
define|#
directive|define
name|T_ATM_LOC_INTERNATIONAL_NET
value|7
end_define

begin_define
define|#
directive|define
name|T_ATM_LOC_BEYOND_INTERWORKING
value|10
end_define

begin_comment
comment|/* cause_value */
end_comment

begin_define
define|#
directive|define
name|T_ATM_CAUSE_UNALLOCATED_NUMBER
value|1
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_NO_ROUTE_TO_TRANSIT_NETWORK
value|2
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_NO_ROUTE_TO_DESTINATION
value|3
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_NORMAL_CALL_CLEARING
value|16
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_USER_BUSY
value|17
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_NO_USER_RESPONDING
value|18
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_CALL_REJECTED
value|21
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_NUMBER_CHANGED
value|22
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_ALL_CALLS_WITHOUT_CALLER_ID_REJECTED
value|23
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_DESTINATION_OUT_OF_ORDER
value|27
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_INVALID_NUMBER_FORMAT
value|28
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_RESPONSE_TO_STATUS_ENQUIRY
value|30
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_UNSPECIFIED_NORMAL
value|31
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_REQUESTED_VPCI_VCI_NOT_AVAILABLE
value|35
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_VPCI_VCI_ASSIGNMENT_FAILURE
value|36
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_USER_CELL_RATE_NOT_AVAILABLE
value|37
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_NETWORK_OUT_OF_ORDER
value|38
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_TEMPORARY_FAILURE
value|41
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_ACCESS_INFO_DISCARDED
value|43
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_NO_VPCI_VCI_AVAILABLE
value|45
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_UNSPECIFIED_RESOURCE_UNAVAILABLE
value|47
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_QUALITY_OF_SERVICE_UNAVAILABLE
value|49
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_BEARER_CAPABILITY_NOT_AUTHORIZED
value|57
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_BEARER_CAPABILITY_UNAVAILABLE
value|58
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_SERVICE_OR_OPTION_UNAVAILABLE
value|63
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_BEARER_CAPABILITY_NOT_IMPLEMENTED
value|65
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_INVALID_TRAFFIC_PARAMETERS
value|73
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_AAL_PARAMETERS_NOT_SUPPORTED
value|78
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_INVALID_CALL_REFERENCE_VALUE
value|81
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_IDENTIFIED_CHANNEL_DOES_NOT_EXIST
value|82
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_INCOMPATIBLE_DESTINATION
value|88
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_INVALID_ENDPOINT_REFERENCE
value|89
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_INVALID_TRANSIT_NETWORK_SELECTION
value|91
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_TOO_MANY_PENDING_ADD_PARTY_REQUESTS
value|92
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_MANDITORY_INFO_ELEMENT_MISSING
value|96
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_MESSAGE_TYPE_NOT_IMPLEMENTED
value|97
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_INFO_ELEMENT_NOT_IMPLEMENTED
value|99
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_INVALID_INFO_ELEMENT_CONTENTS
value|100
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_MESSAGE_INCOMPATIBLE_WITH_CALL_STATE
value|101
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_RECOVERY_ON_TIMER_EXPIRY
value|102
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_INCORRECT_MESSAGE_LENGTH
value|104
end_define

begin_define
define|#
directive|define
name|T_ATM_CAUSE_UNSPECIFIED_PROTOCOL_ERROR
value|111
end_define

begin_comment
comment|/*  * T_ATM_QOS option value structure  */
end_comment

begin_struct
struct|struct
name|t_atm_qos_substruct
block|{
name|int32_t
name|qos_class
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t_atm_qos
block|{
name|int8_t
name|coding_standard
decl_stmt|;
name|struct
name|t_atm_qos_substruct
name|forward
decl_stmt|;
name|struct
name|t_atm_qos_substruct
name|backward
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_QOS option values  */
end_comment

begin_comment
comment|/* qos_class */
end_comment

begin_define
define|#
directive|define
name|T_ATM_QOS_CLASS_0
value|0
end_define

begin_define
define|#
directive|define
name|T_ATM_QOS_CLASS_1
value|1
end_define

begin_define
define|#
directive|define
name|T_ATM_QOS_CLASS_2
value|2
end_define

begin_define
define|#
directive|define
name|T_ATM_QOS_CLASS_3
value|3
end_define

begin_define
define|#
directive|define
name|T_ATM_QOS_CLASS_4
value|4
end_define

begin_comment
comment|/*  * T_ATM_TRANSIT structure  */
end_comment

begin_define
define|#
directive|define
name|T_ATM_MAX_NET_ID
value|4
end_define

begin_comment
comment|/* XNS_EXT */
end_comment

begin_struct
struct|struct
name|t_atm_transit
block|{
name|u_int8_t
name|length
decl_stmt|;
name|u_int8_t
name|network_id
index|[
name|T_ATM_MAX_NET_ID
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_ADD_LEAF option value structure  */
end_comment

begin_struct
struct|struct
name|t_atm_add_leaf
block|{
name|int32_t
name|leaf_ID
decl_stmt|;
name|struct
name|t_atm_addr
name|leaf_address
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_DROP_LEAF option value structure  */
end_comment

begin_struct
struct|struct
name|t_atm_drop_leaf
block|{
name|int32_t
name|leaf_ID
decl_stmt|;
name|int32_t
name|reason
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_LEAF_IND option value structure  */
end_comment

begin_struct
struct|struct
name|t_atm_leaf_ind
block|{
name|int32_t
name|status
decl_stmt|;
name|int32_t
name|leaf_ID
decl_stmt|;
name|int32_t
name|reason
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_LEAF_IND option values  */
end_comment

begin_comment
comment|/* status */
end_comment

begin_define
define|#
directive|define
name|T_LEAF_NOCHANGE
value|0
end_define

begin_define
define|#
directive|define
name|T_LEAF_CONNECTED
value|1
end_define

begin_define
define|#
directive|define
name|T_LEAF_DISCONNECTED
value|2
end_define

begin_comment
comment|/*  * T_ATM_NET_INTF option value structure	(XNS_EXT)  */
end_comment

begin_struct
struct|struct
name|t_atm_net_intf
block|{
comment|/* XNS_EXT */
name|char
name|net_intf
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_LLC option value structure		(XNS_EXT)  */
end_comment

begin_define
define|#
directive|define
name|T_ATM_LLC_MIN_LEN
value|3
end_define

begin_define
define|#
directive|define
name|T_ATM_LLC_MAX_LEN
value|8
end_define

begin_struct
struct|struct
name|t_atm_llc
block|{
comment|/* XNS_EXT */
name|u_int8_t
name|flags
decl_stmt|;
comment|/* LLC flags (see below) */
name|u_int8_t
name|llc_len
decl_stmt|;
comment|/* Length of LLC information */
name|u_int8_t
name|llc_info
index|[
name|T_ATM_LLC_MAX_LEN
index|]
decl_stmt|;
comment|/* LLC information */
block|}
struct|;
end_struct

begin_comment
comment|/*  * T_ATM_LLC option values  */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|T_ATM_LLC_SHARING
value|0x01
end_define

begin_comment
comment|/* LLC sharing allowed */
end_comment

begin_comment
comment|/*  * T_ATM_APP_NAME option value structure	(XNS_EXT)  */
end_comment

begin_define
define|#
directive|define
name|T_ATM_APP_NAME_LEN
value|8
end_define

begin_struct
struct|struct
name|t_atm_app_name
block|{
comment|/* XNS_EXT */
name|char
name|app_name
index|[
name|T_ATM_APP_NAME_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETATM_ATM_H */
end_comment

end_unit

