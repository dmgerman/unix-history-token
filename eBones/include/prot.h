begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  * For copying and distribution information, please see the file  *<Copyright.MIT>.  *  * Include file with authentication protocol information.  *  *	from: prot.h,v 4.13 89/01/24 14:27:22 jtkohl Exp $  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<krb_conf.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PROT_DEFS
end_ifndef

begin_define
define|#
directive|define
name|PROT_DEFS
end_define

begin_define
define|#
directive|define
name|KRB_PORT
value|750
end_define

begin_comment
comment|/* PC's don't have 						 * /etc/services */
end_comment

begin_define
define|#
directive|define
name|KRB_PROT_VERSION
value|4
end_define

begin_define
define|#
directive|define
name|MAX_PKT_LEN
value|1000
end_define

begin_define
define|#
directive|define
name|MAX_TXT_LEN
value|1000
end_define

begin_define
define|#
directive|define
name|TICKET_GRANTING_TICKET
value|"krbtgt"
end_define

begin_comment
comment|/* Macro's to obtain various fields from a packet */
end_comment

begin_define
define|#
directive|define
name|pkt_version
parameter_list|(
name|packet
parameter_list|)
value|(unsigned int) *(packet->dat)
end_define

begin_define
define|#
directive|define
name|pkt_msg_type
parameter_list|(
name|packet
parameter_list|)
value|(unsigned int) *(packet->dat+1)
end_define

begin_define
define|#
directive|define
name|pkt_a_name
parameter_list|(
name|packet
parameter_list|)
value|(packet->dat+2)
end_define

begin_define
define|#
directive|define
name|pkt_a_inst
parameter_list|(
name|packet
parameter_list|)
define|\
value|(packet->dat+3+strlen((char *)pkt_a_name(packet)))
end_define

begin_define
define|#
directive|define
name|pkt_a_realm
parameter_list|(
name|packet
parameter_list|)
define|\
value|(pkt_a_inst(packet)+1+strlen((char *)pkt_a_inst(packet)))
end_define

begin_comment
comment|/* Macro to obtain realm from application request */
end_comment

begin_define
define|#
directive|define
name|apreq_realm
parameter_list|(
name|auth
parameter_list|)
value|(auth->dat + 3)
end_define

begin_define
define|#
directive|define
name|pkt_time_ws
parameter_list|(
name|packet
parameter_list|)
value|(char *) \         (packet->dat+5+strlen((char *)pkt_a_name(packet)) + \ 	 strlen((char *)pkt_a_inst(packet)) + \ 	 strlen((char *)pkt_a_realm(packet)))
end_define

begin_define
define|#
directive|define
name|pkt_no_req
parameter_list|(
name|packet
parameter_list|)
value|(unsigned short) \         *(packet->dat+9+strlen((char *)pkt_a_name(packet)) + \ 	  strlen((char *)pkt_a_inst(packet)) + \ 	  strlen((char *)pkt_a_realm(packet)))
end_define

begin_define
define|#
directive|define
name|pkt_x_date
parameter_list|(
name|packet
parameter_list|)
value|(char *) \         (packet->dat+10+strlen((char *)pkt_a_name(packet)) + \ 	 strlen((char *)pkt_a_inst(packet)) + \ 	 strlen((char *)pkt_a_realm(packet)))
end_define

begin_define
define|#
directive|define
name|pkt_err_code
parameter_list|(
name|packet
parameter_list|)
value|( (char *) \         (packet->dat+9+strlen((char *)pkt_a_name(packet)) + \ 	 strlen((char *)pkt_a_inst(packet)) + \ 	 strlen((char *)pkt_a_realm(packet))))
end_define

begin_define
define|#
directive|define
name|pkt_err_text
parameter_list|(
name|packet
parameter_list|)
define|\
value|(packet->dat+13+strlen((char *)pkt_a_name(packet)) + \ 	 strlen((char *)pkt_a_inst(packet)) + \ 	 strlen((char *)pkt_a_realm(packet)))
end_define

begin_comment
comment|/* Routines to create and read packets may be found in prot.c */
end_comment

begin_function_decl
name|KTEXT
name|create_auth_reply
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|KTEXT
name|create_death_packet
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|KTEXT
name|pkt_cipher
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Message types , always leave lsb for byte order */
end_comment

begin_define
define|#
directive|define
name|AUTH_MSG_KDC_REQUEST
value|1<<1
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_KDC_REPLY
value|2<<1
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_APPL_REQUEST
value|3<<1
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_APPL_REQUEST_MUTUAL
value|4<<1
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_ERR_REPLY
value|5<<1
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_PRIVATE
value|6<<1
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_SAFE
value|7<<1
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_APPL_ERR
value|8<<1
end_define

begin_define
define|#
directive|define
name|AUTH_MSG_DIE
value|63<<1
end_define

begin_comment
comment|/* values for kerb error codes */
end_comment

begin_define
define|#
directive|define
name|KERB_ERR_OK
value|0
end_define

begin_define
define|#
directive|define
name|KERB_ERR_NAME_EXP
value|1
end_define

begin_define
define|#
directive|define
name|KERB_ERR_SERVICE_EXP
value|2
end_define

begin_define
define|#
directive|define
name|KERB_ERR_AUTH_EXP
value|3
end_define

begin_define
define|#
directive|define
name|KERB_ERR_PKT_VER
value|4
end_define

begin_define
define|#
directive|define
name|KERB_ERR_NAME_MAST_KEY_VER
value|5
end_define

begin_define
define|#
directive|define
name|KERB_ERR_SERV_MAST_KEY_VER
value|6
end_define

begin_define
define|#
directive|define
name|KERB_ERR_BYTE_ORDER
value|7
end_define

begin_define
define|#
directive|define
name|KERB_ERR_PRINCIPAL_UNKNOWN
value|8
end_define

begin_define
define|#
directive|define
name|KERB_ERR_PRINCIPAL_NOT_UNIQUE
value|9
end_define

begin_define
define|#
directive|define
name|KERB_ERR_NULL_KEY
value|10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROT_DEFS */
end_comment

end_unit

