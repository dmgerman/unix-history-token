begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: krb-archaeology.h,v 1.2 1997/12/05 02:04:44 joda Exp $  *  * Most of the cruft in this file is probably:  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KRB_ARCHAEOLOGY_H__
end_ifndef

begin_define
define|#
directive|define
name|__KRB_ARCHAEOLOGY_H__
end_define

begin_comment
comment|/* Compare x and y in VAX byte order, result is -1, 0 or 1. */
end_comment

begin_define
define|#
directive|define
name|krb_lsb_antinet_ulong_less
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) == (y)) ? 0 :  krb_lsb_antinet_ulong_cmp(x, y))
end_define

begin_define
define|#
directive|define
name|krb_lsb_antinet_ushort_less
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) == (y)) ? 0 : krb_lsb_antinet_ushort_cmp(x, y))
end_define

begin_function_decl
name|int
name|krb_lsb_antinet_ulong_cmp
parameter_list|(
name|u_int32_t
name|x
parameter_list|,
name|u_int32_t
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|krb_lsb_antinet_ushort_cmp
parameter_list|(
name|u_int16_t
name|x
parameter_list|,
name|u_int16_t
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|lsb_time
parameter_list|(
name|time_t
name|t
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|src
parameter_list|,
name|struct
name|sockaddr_in
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

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
comment|/*  * macros for byte swapping; also scratch space  * u_quad  0-->7, 1-->6, 2-->5, 3-->4, 4-->3, 5-->2, 6-->1, 7-->0  * u_int32_t  0-->3, 1-->2, 2-->1, 3-->0  * u_int16_t 0-->1, 1-->0  */
end_comment

begin_define
define|#
directive|define
name|swap_u_16
parameter_list|(
name|x
parameter_list|)
value|{\  u_int32_t   _krb_swap_tmp[4];\  swab(((char *) x) +0, ((char *)  _krb_swap_tmp) +14 ,2); \  swab(((char *) x) +2, ((char *)  _krb_swap_tmp) +12 ,2); \  swab(((char *) x) +4, ((char *)  _krb_swap_tmp) +10 ,2); \  swab(((char *) x) +6, ((char *)  _krb_swap_tmp) +8  ,2); \  swab(((char *) x) +8, ((char *)  _krb_swap_tmp) +6 ,2); \  swab(((char *) x) +10,((char *)  _krb_swap_tmp) +4 ,2); \  swab(((char *) x) +12,((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *) x) +14,((char *)  _krb_swap_tmp) +0 ,2); \  memcpy(x, _krb_swap_tmp, 16);\                             }
end_define

begin_define
define|#
directive|define
name|swap_u_12
parameter_list|(
name|x
parameter_list|)
value|{\  u_int32_t   _krb_swap_tmp[4];\  swab(( char *) x,     ((char *)  _krb_swap_tmp) +10 ,2); \  swab(((char *) x) +2, ((char *)  _krb_swap_tmp) +8 ,2); \  swab(((char *) x) +4, ((char *)  _krb_swap_tmp) +6 ,2); \  swab(((char *) x) +6, ((char *)  _krb_swap_tmp) +4 ,2); \  swab(((char *) x) +8, ((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *) x) +10,((char *)  _krb_swap_tmp) +0 ,2); \  memcpy(x, _krb_swap_tmp, 12);\                             }
end_define

begin_define
define|#
directive|define
name|swap_C_Block
parameter_list|(
name|x
parameter_list|)
value|{\  u_int32_t   _krb_swap_tmp[4];\  swab(( char *) x,    ((char *)  _krb_swap_tmp) +6 ,2); \  swab(((char *) x) +2,((char *)  _krb_swap_tmp) +4 ,2); \  swab(((char *) x) +4,((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *) x) +6,((char *)  _krb_swap_tmp)    ,2); \  memcpy(x, _krb_swap_tmp, 8);\                             }
end_define

begin_define
define|#
directive|define
name|swap_u_quad
parameter_list|(
name|x
parameter_list|)
value|{\  u_int32_t   _krb_swap_tmp[4];\  swab(( char *)&x,    ((char *)  _krb_swap_tmp) +6 ,2); \  swab(((char *)&x) +2,((char *)  _krb_swap_tmp) +4 ,2); \  swab(((char *)&x) +4,((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *)&x) +6,((char *)  _krb_swap_tmp)    ,2); \  memcpy(x, _krb_swap_tmp, 8);\                             }
end_define

begin_define
define|#
directive|define
name|swap_u_long
parameter_list|(
name|x
parameter_list|)
value|{\  u_int32_t   _krb_swap_tmp[4];\  swab((char *)&x,    ((char *)  _krb_swap_tmp) +2 ,2); \  swab(((char *)&x) +2,((char *)  _krb_swap_tmp),2); \  x = _krb_swap_tmp[0];   \                            }
end_define

begin_define
define|#
directive|define
name|swap_u_short
parameter_list|(
name|x
parameter_list|)
value|{\  u_int16_t	_krb_swap_sh_tmp; \  swab((char *)&x,    (&_krb_swap_sh_tmp) ,2); \  x = (u_int16_t) _krb_swap_sh_tmp; \                             }
end_define

begin_comment
comment|/* Kerberos ticket flag field bit definitions */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_ORDER
value|0
end_define

begin_comment
comment|/* bit 0 --> lsb */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_1
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_2
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_3
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_4
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_5
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_6
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|K_FLAG_7
end_define

begin_comment
comment|/* reserved, bit 7 --> msb */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KRB_ARCHAEOLOGY_H__ */
end_comment

end_unit

