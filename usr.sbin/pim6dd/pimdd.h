begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1998 by the University of Oregon.  *  All rights reserved.  *  *  Permission to use, copy, modify, and distribute this software and  *  its documentation in source and binary forms for lawful  *  purposes and without fee is hereby granted, provided  *  that the above copyright notice appear in all copies and that both  *  the copyright notice and this permission notice appear in supporting  *  documentation, and that any documentation, advertising materials,  *  and other materials related to such distribution and use acknowledge  *  that the software was developed by the University of Oregon.  *  The name of the University of Oregon may not be used to endorse or   *  promote products derived from this software without specific prior   *  written permission.  *  *  THE UNIVERSITY OF OREGON DOES NOT MAKE ANY REPRESENTATIONS  *  ABOUT THE SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE.  THIS SOFTWARE IS  *  PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,  *  INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND   *  NON-INFRINGEMENT.  *  *  IN NO EVENT SHALL UO, OR ANY OTHER CONTRIBUTOR BE LIABLE FOR ANY  *  SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, WHETHER IN CONTRACT,  *  TORT, OR OTHER FORM OF ACTION, ARISING OUT OF OR IN CONNECTION WITH,  *  THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *  Other copyrights might apply to parts of this software and are so  *  noted when applicable.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to   *  Kurt Windisch (kurtw@antc.uoregon.edu)  *  *  $Id: pimdd.h,v 1.1.1.1 1999/08/08 23:30:53 itojun Exp $  */
end_comment

begin_comment
comment|/*  * Part of this program has been derived from PIM sparse-mode pimd.  * The pimd program is covered by the license in the accompanying file  * named "LICENSE.pimd".  *    * The pimd program is COPYRIGHT 1998 by University of Southern California.  *  * Part of this program has been derived from mrouted.  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE.mrouted".  *   * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<netinet6/pim6.h>
end_include

begin_define
define|#
directive|define
name|PIM_PROTOCOL_VERSION
value|2
end_define

begin_define
define|#
directive|define
name|PIMD_VERSION
value|PIM_PROTOCOL_VERSION
end_define

begin_define
define|#
directive|define
name|PIMD_SUBVERSION
value|1
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|PIM_CONSTANT
value|0x000eff00
end_define

begin_comment
comment|/* constant portion of 'group' field */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PIM_CONSTANT
value|0
end_define

begin_define
define|#
directive|define
name|PIMD_LEVEL
value|(PIM_CONSTANT | PIMD_VERSION | (PIMD_SUBVERSION<< 8))
end_define

begin_define
define|#
directive|define
name|INADDR_ALL_PIM_ROUTERS
value|(u_int32)0xe000000D
end_define

begin_comment
comment|/* 224.0.0.13 */
end_comment

begin_comment
comment|/* PIM protocol timers (in seconds) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TIMER_INTERVAL
end_ifndef

begin_define
define|#
directive|define
name|TIMER_INTERVAL
value|5
end_define

begin_comment
comment|/* virtual timer granularity */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIMER_INTERVAL */
end_comment

begin_define
define|#
directive|define
name|PIM_DATA_TIMEOUT
value|210
end_define

begin_define
define|#
directive|define
name|PIM_TIMER_HELLO_PERIOD
value|30
end_define

begin_define
define|#
directive|define
name|PIM_JOIN_PRUNE_HOLDTIME
value|210
end_define

begin_define
define|#
directive|define
name|PIM_RANDOM_DELAY_JOIN_TIMEOUT
value|3
end_define

begin_define
define|#
directive|define
name|PIM_GRAFT_RETRANS_PERIOD
value|3
end_define

begin_define
define|#
directive|define
name|PIM_TIMER_HELLO_HOLDTIME
value|(3.5 * PIM_TIMER_HELLO_PERIOD)
end_define

begin_define
define|#
directive|define
name|PIM_ASSERT_TIMEOUT
value|210
end_define

begin_comment
comment|/* Misc definitions */
end_comment

begin_define
define|#
directive|define
name|SINGLE_SRC_MSKLEN
value|32
end_define

begin_comment
comment|/* the single source mask length */
end_comment

begin_define
define|#
directive|define
name|SINGLE_GRP_MSKLEN
value|32
end_define

begin_comment
comment|/* the single group mask length  */
end_comment

begin_define
define|#
directive|define
name|SINGLE_SRC_MSK6LEN
value|128
end_define

begin_comment
comment|/* the single source mask length for IPv6*/
end_comment

begin_define
define|#
directive|define
name|SINGLE_GRP_MSK6LEN
value|128
end_define

begin_comment
comment|/* the single group mask length  for IPv6*/
end_comment

begin_comment
comment|/* TODO: change? */
end_comment

begin_define
define|#
directive|define
name|PIM_GROUP_PREFIX_DEFAULT_MASKLEN
value|16
end_define

begin_comment
comment|/* The default group masklen if 					     * omitted in the config file. 					     */
end_comment

begin_define
define|#
directive|define
name|UCAST_ROUTING_CHECK_INTERVAL
value|20
end_define

begin_comment
comment|/* Unfortunately, if the unicast 					       * routing changes, the kernel 					       * or any of the existing 					       * unicast routing daemons 					       * don't send us a signal. 					       * Have to ask periodically the 					       * kernel for any route changes. 					       * Default: every 20 seconds. 					       * Sigh. 					       */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PHY_RATE_LIMIT
value|0
end_define

begin_comment
comment|/* default phyint rate limit  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_LOCAL_PREF
value|101
end_define

begin_comment
comment|/* Default assert preference */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_LOCAL_METRIC
value|1024
end_define

begin_comment
comment|/* Default assert metric */
end_comment

begin_comment
comment|/**************************************************************************  * PIM Encoded-Unicast, Encoded-Group and Encoded-Source Address formats  *  *************************************************************************/
end_comment

begin_comment
comment|/* Address families definition */
end_comment

begin_define
define|#
directive|define
name|ADDRF_RESERVED
value|0
end_define

begin_define
define|#
directive|define
name|ADDRF_IPv4
value|1
end_define

begin_define
define|#
directive|define
name|ADDRF_IPv6
value|2
end_define

begin_define
define|#
directive|define
name|ADDRF_NSAP
value|3
end_define

begin_define
define|#
directive|define
name|ADDRF_HDLC
value|4
end_define

begin_define
define|#
directive|define
name|ADDRF_BBN1822
value|5
end_define

begin_define
define|#
directive|define
name|ADDRF_802
value|6
end_define

begin_define
define|#
directive|define
name|ADDRF_ETHERNET
value|ADDRF_802
end_define

begin_define
define|#
directive|define
name|ADDRF_E163
value|7
end_define

begin_define
define|#
directive|define
name|ADDRF_E164
value|8
end_define

begin_define
define|#
directive|define
name|ADDRF_SMDS
value|ADDRF_E164
end_define

begin_define
define|#
directive|define
name|ADDRF_ATM
value|ADDRF_E164
end_define

begin_define
define|#
directive|define
name|ADDRF_F69
value|9
end_define

begin_define
define|#
directive|define
name|ADDRF_TELEX
value|ADDRF_F69
end_define

begin_define
define|#
directive|define
name|ADDRF_X121
value|10
end_define

begin_define
define|#
directive|define
name|ADDRF_X25
value|ADDRF_X121
end_define

begin_define
define|#
directive|define
name|ADDRF_IPX
value|11
end_define

begin_define
define|#
directive|define
name|ADDRF_APPLETALK
value|12
end_define

begin_define
define|#
directive|define
name|ADDRF_DECNET_IV
value|13
end_define

begin_define
define|#
directive|define
name|ADDRF_BANYAN
value|14
end_define

begin_define
define|#
directive|define
name|ADDRF_E164_NSAP
value|15
end_define

begin_comment
comment|/* Addresses Encoding Type (specific for each Address Family */
end_comment

begin_define
define|#
directive|define
name|ADDRT_IPv4
value|0
end_define

begin_define
define|#
directive|define
name|ADDRT_IPv6
value|0
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: the definition is for IPv4 only */
end_comment

begin_comment
comment|/* Encoded-Unicast: 6 bytes long */
end_comment

begin_comment
unit|typedef struct pim_encod_uni_addr_ {     u_int8      addr_family;     u_int8      encod_type;     u_int32     unicast_addr;
comment|/* XXX: Note the 32-bit boundary 				      * misalignment for  the unicast 				      * address when placed in the 				      * memory. Must read it byte-by-byte! 				      */
end_comment

begin_endif
unit|} pim_encod_uni_addr_t;
endif|#
directive|endif
end_endif

begin_comment
comment|/* Encoded-Unicast: 18 bytes long */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pim6_encod_uni_addr_
block|{
name|u_int8
name|addr_family
decl_stmt|;
name|u_int8
name|encod_type
decl_stmt|;
name|struct
name|in6_addr
name|unicast_addr
decl_stmt|;
comment|/* XXX: Note the 32-bit boundary 					  * misalignment for  the unicast 					  * address when placed in the 					  * memory. Must read it byte-by-byte! 					  */
block|}
name|pim6_encod_uni_addr_t
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: the definition is for IPv4 only */
end_comment

begin_comment
comment|/* Encoded-Group */
end_comment

begin_endif
unit|typedef struct pim_encod_grp_addr_ {     u_int8      addr_family;     u_int8      encod_type;     u_int8      reserved;     u_int8      masklen;     u_int32     mcast_addr; } pim_encod_grp_addr_t;
endif|#
directive|endif
end_endif

begin_comment
comment|/* Encoded-Group */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pim6_encod_grp_addr_
block|{
name|u_int8
name|addr_family
decl_stmt|;
name|u_int8
name|encod_type
decl_stmt|;
name|u_int8
name|reserved
decl_stmt|;
name|u_int8
name|masklen
decl_stmt|;
name|struct
name|in6_addr
name|mcast_addr
decl_stmt|;
block|}
name|pim6_encod_grp_addr_t
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX: the definition is for IPv4 only */
end_comment

begin_comment
comment|/* Encoded-Source */
end_comment

begin_endif
unit|typedef struct pim_encod_src_addr_ {     u_int8      addr_family;     u_int8      encod_type;     u_int8      flags;     u_int8      masklen;     u_int32     src_addr; } pim_encod_src_addr_t;
endif|#
directive|endif
end_endif

begin_comment
comment|/* Encoded-Source */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pim6_encod_src_addr_
block|{
name|u_int8
name|addr_family
decl_stmt|;
name|u_int8
name|encod_type
decl_stmt|;
name|u_int8
name|flags
decl_stmt|;
name|u_int8
name|masklen
decl_stmt|;
name|struct
name|in6_addr
name|src_addr
decl_stmt|;
block|}
name|pim6_encod_src_addr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USADDR_RP_BIT
value|0x1
end_define

begin_define
define|#
directive|define
name|USADDR_WC_BIT
value|0x2
end_define

begin_define
define|#
directive|define
name|USADDR_S_BIT
value|0x4
end_define

begin_comment
comment|/**************************************************************************  *                       PIM Messages formats                             *  *************************************************************************/
end_comment

begin_comment
comment|/* TODO: XXX: some structures are probably not used at all */
end_comment

begin_typedef
typedef|typedef
name|struct
name|pim
name|pim_header_t
typedef|;
end_typedef

begin_comment
comment|/* PIM Hello */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pim_hello_
block|{
name|u_int16
name|option_type
decl_stmt|;
comment|/* Option type */
name|u_int16
name|option_length
decl_stmt|;
comment|/* Length of the Option Value field in bytes */
block|}
name|pim_hello_t
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* PIM Join/Prune: XXX: all 32-bit addresses misaligned! */
end_comment

begin_endif
unit|typedef struct pim_jp_header_ {     pim_encod_uni_addr_t encod_upstream_nbr;     u_int8     reserved;     u_int8     num_groups;     u_int16    holdtime; } pim_jp_header_t;  typedef struct pim_jp_encod_grp_ {     pim_encod_grp_addr_t   encod_grp;     u_int16                number_join_src;     u_int16                number_prune_src; } pim_jp_encod_grp_t;
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PIM_ACTION_NOTHING
value|0
end_define

begin_define
define|#
directive|define
name|PIM_ACTION_JOIN
value|1
end_define

begin_define
define|#
directive|define
name|PIM_ACTION_PRUNE
value|2
end_define

begin_define
define|#
directive|define
name|PIM_IIF_SOURCE
value|1
end_define

begin_define
define|#
directive|define
name|PIM_IIF_RP
value|2
end_define

begin_define
define|#
directive|define
name|PIM_ASSERT_RPT_BIT
value|0x80000000
end_define

begin_comment
comment|/* PIM messages type */
end_comment

begin_define
define|#
directive|define
name|PIM_HELLO
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PIM_REGISTER
end_ifndef

begin_define
define|#
directive|define
name|PIM_REGISTER
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PIM_REGISTER_STOP
value|2
end_define

begin_define
define|#
directive|define
name|PIM_JOIN_PRUNE
value|3
end_define

begin_define
define|#
directive|define
name|PIM_BOOTSTRAP
value|4
end_define

begin_define
define|#
directive|define
name|PIM_ASSERT
value|5
end_define

begin_define
define|#
directive|define
name|PIM_GRAFT
value|6
end_define

begin_define
define|#
directive|define
name|PIM_GRAFT_ACK
value|7
end_define

begin_define
define|#
directive|define
name|PIM_CAND_RP_ADV
value|8
end_define

begin_define
define|#
directive|define
name|PIM_V2_HELLO
value|PIM_HELLO
end_define

begin_define
define|#
directive|define
name|PIM_V2_REGISTER
value|PIM_REGISTER
end_define

begin_define
define|#
directive|define
name|PIM_V2_REGISTER_STOP
value|PIM_REGISTER_STOP
end_define

begin_define
define|#
directive|define
name|PIM_V2_JOIN_PRUNE
value|PIM_JOIN_PRUNE
end_define

begin_define
define|#
directive|define
name|PIM_V2_BOOTSTRAP
value|PIM_BOOTSTRAP
end_define

begin_define
define|#
directive|define
name|PIM_V2_ASSERT
value|PIM_ASSERT
end_define

begin_define
define|#
directive|define
name|PIM_V2_GRAFT
value|PIM_GRAFT
end_define

begin_define
define|#
directive|define
name|PIM_V2_GRAFT_ACK
value|PIM_GRAFT_ACK
end_define

begin_define
define|#
directive|define
name|PIM_V2_CAND_RP_ADV
value|PIM_CAND_RP_ADV
end_define

begin_define
define|#
directive|define
name|PIM_V1_QUERY
value|0
end_define

begin_define
define|#
directive|define
name|PIM_V1_REGISTER
value|1
end_define

begin_define
define|#
directive|define
name|PIM_V1_REGISTER_STOP
value|2
end_define

begin_define
define|#
directive|define
name|PIM_V1_JOIN_PRUNE
value|3
end_define

begin_define
define|#
directive|define
name|PIM_V1_RP_REACHABILITY
value|4
end_define

begin_define
define|#
directive|define
name|PIM_V1_ASSERT
value|5
end_define

begin_define
define|#
directive|define
name|PIM_V1_GRAFT
value|6
end_define

begin_define
define|#
directive|define
name|PIM_V1_GRAFT_ACK
value|7
end_define

begin_comment
comment|/* Vartious options from PIM messages definitions */
end_comment

begin_comment
comment|/* PIM_HELLO definitions */
end_comment

begin_define
define|#
directive|define
name|PIM_MESSAGE_HELLO_HOLDTIME
value|1
end_define

begin_define
define|#
directive|define
name|PIM_MESSAGE_HELLO_HOLDTIME_LENGTH
value|2
end_define

begin_define
define|#
directive|define
name|PIM_MESSAGE_HELLO_HOLDTIME_FOREVER
value|0xffff
end_define

begin_define
define|#
directive|define
name|MASK_TO_MASKLEN
parameter_list|(
name|mask
parameter_list|,
name|masklen
parameter_list|)
define|\
value|do {                                                         \         register u_int32 tmp_mask = ntohl((mask));               \         register u_int8  tmp_masklen = sizeof((mask))<< 3;      \         for ( ; tmp_masklen> 0; tmp_masklen--, tmp_mask>>= 1)  \             if (tmp_mask& 0x1)                                  \                 break;                                           \         (masklen) = tmp_masklen;                                 \     } while (0)
end_define

begin_define
define|#
directive|define
name|MASKLEN_TO_MASK
parameter_list|(
name|masklen
parameter_list|,
name|mask
parameter_list|)
define|\
value|do {                                                                         \     (mask) = (masklen)? htonl(~0<< ((sizeof((mask))<< 3) - (masklen))) : 0;\ } while (0)
end_define

begin_define
define|#
directive|define
name|MASKLEN_TO_MASK6
parameter_list|(
name|masklen
parameter_list|,
name|mask6
parameter_list|)
define|\
value|do {\ 		u_char maskarray[8] = \ 		{0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff}; \ 		int bytelen, bitlen, i; \ 		memset(&(mask6), 0, sizeof(mask6));\ 		bytelen = (masklen) / 8;\ 		bitlen = (masklen) % 8;\ 		for (i = 0; i< bytelen; i++) \ 			(mask6).s6_addr[i] = 0xff;\ 		if (bitlen) \ 			(mask6).s6_addr[bytelen] = maskarray[bitlen - 1]; \ 	}while(0);
end_define

begin_comment
comment|/*  * A bunch of macros because of the lack of 32-bit boundary alignment.  * All because of one misalligned address format. Hopefully this will be  * fixed in PIMv3. (cp) must be (u_int8 *) .  */
end_comment

begin_comment
comment|/* Originates from Eddy Rusty's (eddy@isi.edu) PIM-SM implementation for  * gated.  */
end_comment

begin_comment
comment|/* PUT_NETLONG puts "network ordered" data to the datastream.  * PUT_HOSTLONG puts "host ordered" data to the datastream.  * GET_NETLONG gets the data and keeps it in "network order" in the memory  * GET_HOSTLONG gets the data, but in the memory it is in "host order"  * The same for all {PUT,GET}_{NET,HOST}{SHORT,LONG}  */
end_comment

begin_define
define|#
directive|define
name|GET_BYTE
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
value|((val) = *(cp)++)
end_define

begin_define
define|#
directive|define
name|PUT_BYTE
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
value|(*(cp)++ = (u_int8)(val))
end_define

begin_define
define|#
directive|define
name|GET_HOSTSHORT
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \                 register u_int16 Xv;            \                 Xv = (*(cp)++)<< 8;            \                 Xv |= *(cp)++;                  \                 (val) = Xv;                     \         } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_HOSTSHORT
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \                 register u_int16 Xv;            \                 Xv = (u_int16)(val);            \                 *(cp)++ = (u_int8)(Xv>> 8);    \                 *(cp)++ = (u_int8)Xv;           \         } while (0)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|&&
operator|(
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|)
end_if

begin_define
define|#
directive|define
name|GET_NETSHORT
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \                 register u_int16 Xv;            \                 Xv = *(cp)++;                   \                 Xv |= (*(cp)++)<< 8;           \                 (val) = Xv;                     \         } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_NETSHORT
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \                 register u_int16 Xv;            \                 Xv = (u_int16)(val);            \                 *(cp)++ = (u_int8)Xv;           \                 *(cp)++ = (u_int8)(Xv>> 8);    \         } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_NETSHORT
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
value|GET_HOSTSHORT(val, cp)
end_define

begin_define
define|#
directive|define
name|PUT_NETSHORT
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
value|PUT_HOSTSHORT(val, cp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* {GET,PUT}_NETSHORT */
end_comment

begin_define
define|#
directive|define
name|GET_HOSTLONG
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \                 register u_long Xv;             \                 Xv  = (*(cp)++)<< 24;          \                 Xv |= (*(cp)++)<< 16;          \                 Xv |= (*(cp)++)<<  8;          \                 Xv |= *(cp)++;                  \                 (val) = Xv;                     \         } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_HOSTLONG
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \                 register u_int32 Xv;            \                 Xv = (u_int32)(val);            \                 *(cp)++ = (u_int8)(Xv>> 24);   \                 *(cp)++ = (u_int8)(Xv>> 16);   \                 *(cp)++ = (u_int8)(Xv>>  8);   \                 *(cp)++ = (u_int8)Xv;           \         } while (0)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BYTE_ORDER
argument_list|)
operator|&&
operator|(
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|)
end_if

begin_define
define|#
directive|define
name|GET_NETLONG
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \                 register u_long Xv;             \                 Xv  = *(cp)++;                  \                 Xv |= (*(cp)++)<<  8;          \                 Xv |= (*(cp)++)<< 16;          \                 Xv |= (*(cp)++)<< 24;          \                 (val) = Xv;                     \         } while (0)
end_define

begin_define
define|#
directive|define
name|PUT_NETLONG
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \                 register u_int32 Xv;            \                 Xv = (u_int32)(val);            \                 *(cp)++ = (u_int8)Xv;           \                 *(cp)++ = (u_int8)(Xv>>  8);   \                 *(cp)++ = (u_int8)(Xv>> 16);   \                 *(cp)++ = (u_int8)(Xv>> 24);   \         } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GET_NETLONG
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
value|GET_HOSTLONG(val, cp)
end_define

begin_define
define|#
directive|define
name|PUT_NETLONG
parameter_list|(
name|val
parameter_list|,
name|cp
parameter_list|)
value|PUT_HOSTLONG(val, cp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* {GET,PUT}_HOSTLONG */
end_comment

begin_define
define|#
directive|define
name|GET_ESADDR
parameter_list|(
name|esa
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \             (esa)->addr_family = *(cp)++;       \             (esa)->encod_type  = *(cp)++;       \             (esa)->flags       = *(cp)++;       \             (esa)->masklen     = *(cp)++;       \             GET_NETLONG((esa)->src_addr, (cp)); \         } while(0)
end_define

begin_define
define|#
directive|define
name|GET_ESADDR6
parameter_list|(
name|esa
parameter_list|,
name|cp
parameter_list|)
comment|/* XXX: hard coding */
define|\
value|do {                                    \             (esa)->addr_family = *(cp)++;       \             (esa)->encod_type  = *(cp)++;       \             (esa)->flags       = *(cp)++;       \             (esa)->masklen     = *(cp)++;       \              memcpy(&(esa)->src_addr, (cp), sizeof(struct in6_addr)); \ 	     (cp) += sizeof(struct in6_addr);	\         } while(0)
end_define

begin_define
define|#
directive|define
name|PUT_ESADDR
parameter_list|(
name|addr
parameter_list|,
name|masklen
parameter_list|,
name|flags
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \             u_int32 mask;                       \             MASKLEN_TO_MASK((masklen), mask);   \             *(cp)++ = ADDRF_IPv4;
comment|/* family */
value|\             *(cp)++ = ADDRT_IPv4;
comment|/* type   */
value|\             *(cp)++ = (flags);
comment|/* flags  */
value|\             *(cp)++ = (masklen);                \             PUT_NETLONG((addr)& mask, (cp));   \         } while(0)
end_define

begin_define
define|#
directive|define
name|PUT_ESADDR6
parameter_list|(
name|addr
parameter_list|,
name|masklen
parameter_list|,
name|flags
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \             int i; \             struct in6_addr maskaddr; \ 	    MASKLEN_TO_MASK6(masklen, maskaddr); \             *(cp)++ = ADDRF_IPv6;
comment|/* family */
value|\             *(cp)++ = ADDRT_IPv6;
comment|/* type   */
value|\             *(cp)++ = (flags);
comment|/* flags  */
value|\             *(cp)++ = (masklen);                \             for (i = 0; i< sizeof(struct in6_addr); i++, (cp)++) \ 	            *(cp) = maskaddr.s6_addr[i]& (addr).s6_addr[i]; \         } while(0)
end_define

begin_define
define|#
directive|define
name|GET_EGADDR
parameter_list|(
name|ega
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \             (ega)->addr_family = *(cp)++;       \             (ega)->encod_type  = *(cp)++;       \             (ega)->reserved    = *(cp)++;       \             (ega)->masklen     = *(cp)++;       \             GET_NETLONG((ega)->mcast_addr, (cp)); \         } while(0)
end_define

begin_define
define|#
directive|define
name|GET_EGADDR6
parameter_list|(
name|ega
parameter_list|,
name|cp
parameter_list|)
comment|/* XXX: hard coding */
define|\
value|do {                                    \             (ega)->addr_family = *(cp)++;       \             (ega)->encod_type  = *(cp)++;       \             (ega)->reserved    = *(cp)++;       \             (ega)->masklen     = *(cp)++;       \              memcpy(&(ega)->mcast_addr, (cp), sizeof(struct in6_addr)); \ 	    (cp) += sizeof(struct in6_addr);	\         } while(0)
end_define

begin_define
define|#
directive|define
name|PUT_EGADDR
parameter_list|(
name|addr
parameter_list|,
name|masklen
parameter_list|,
name|reserved
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \             u_int32 mask;                       \             MASKLEN_TO_MASK((masklen), mask);   \             *(cp)++ = ADDRF_IPv4;
comment|/* family */
value|\             *(cp)++ = ADDRT_IPv4;
comment|/* type   */
value|\             *(cp)++ = (reserved);
comment|/* reserved; should be 0 */
value|\             *(cp)++ = (masklen);                \             PUT_NETLONG((addr)& mask, (cp)); \         } while(0)
end_define

begin_define
define|#
directive|define
name|PUT_EGADDR6
parameter_list|(
name|addr
parameter_list|,
name|masklen
parameter_list|,
name|reserved
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \             int i; \             struct in6_addr maskaddr; \ 	    MASKLEN_TO_MASK6(masklen, maskaddr); \             *(cp)++ = ADDRF_IPv6;
comment|/* family */
value|\             *(cp)++ = ADDRT_IPv6;
comment|/* type   */
value|\             *(cp)++ = (reserved);
comment|/* reserved; should be 0 */
value|\             *(cp)++ = (masklen);                \             for (i = 0; i< sizeof(struct in6_addr); i++, (cp)++) \ 	            *(cp) = maskaddr.s6_addr[i]& (addr).s6_addr[i]; \         } while(0)
end_define

begin_define
define|#
directive|define
name|GET_EUADDR
parameter_list|(
name|eua
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \             (eua)->addr_family = *(cp)++;       \             (eua)->encod_type  = *(cp)++;       \             GET_NETLONG((eua)->unicast_addr, (cp)); \         } while(0)
end_define

begin_define
define|#
directive|define
name|GET_EUADDR6
parameter_list|(
name|eua
parameter_list|,
name|cp
parameter_list|)
comment|/* XXX hard conding */
define|\
value|do {                                    \ 	     (eua)->addr_family = *(cp)++;	\ 	     (eua)->encod_type  = *(cp)++;	\              memcpy(&(eua)->unicast_addr, (cp), sizeof(struct in6_addr)); \ 	     (cp) += sizeof(struct in6_addr);	\         } while(0)
end_define

begin_define
define|#
directive|define
name|PUT_EUADDR
parameter_list|(
name|addr
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \             *(cp)++ = ADDRF_IPv4;
comment|/* family */
value|\             *(cp)++ = ADDRT_IPv4;
comment|/* type   */
value|\             PUT_NETLONG((addr), (cp));          \         } while(0)
end_define

begin_define
define|#
directive|define
name|PUT_EUADDR6
parameter_list|(
name|addr
parameter_list|,
name|cp
parameter_list|)
define|\
value|do {                                    \             *(cp)++ = ADDRF_IPv6;
comment|/* family */
value|\             *(cp)++ = ADDRT_IPv6;
comment|/* type   */
value|\             memcpy((cp),&(addr), sizeof(struct in6_addr)); \             (cp) += sizeof(struct in6_addr); \         } while(0)
end_define

begin_comment
comment|/* TODO: Currently not used. Probably not need at all. Delete! */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOSUCHDEF
end_ifdef

begin_comment
comment|/* This is completely IGMP related stuff? */
end_comment

begin_define
define|#
directive|define
name|PIM_LEAF_TIMEOUT
value|(3.5 * IGMP_QUERY_INTERVAL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOSUCHDEF */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__bsdi__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_comment
comment|/*  * Struct used to communicate from kernel to multicast router  * note the convenient similarity to an IP packet  */
end_comment

begin_struct
struct|struct
name|igmpmsg
block|{
name|u_long
name|unused1
decl_stmt|;
name|u_long
name|unused2
decl_stmt|;
name|u_char
name|im_msgtype
decl_stmt|;
comment|/* what type of message     */
define|#
directive|define
name|IGMPMSG_NOCACHE
value|1
define|#
directive|define
name|IGMPMSG_WRONGVIF
value|2
define|#
directive|define
name|IGMPMSG_WHOLEPKT
value|3
comment|/* used for user level encap*/
name|u_char
name|im_mbz
decl_stmt|;
comment|/* must be zero             */
name|u_char
name|im_vif
decl_stmt|;
comment|/* vif rec'd on             */
name|u_char
name|unused3
decl_stmt|;
name|struct
name|in_addr
name|im_src
decl_stmt|,
name|im_dst
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

