begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1998 by the University of Southern California.  *  All rights reserved.  *  *  Permission to use, copy, modify, and distribute this software and  *  its documentation in source and binary forms for lawful  *  purposes and without fee is hereby granted, provided  *  that the above copyright notice appear in all copies and that both  *  the copyright notice and this permission notice appear in supporting  *  documentation, and that any documentation, advertising materials,  *  and other materials related to such distribution and use acknowledge  *  that the software was developed by the University of Southern  *  California and/or Information Sciences Institute.  *  The name of the University of Southern California may not  *  be used to endorse or promote products derived from this software  *  without specific prior written permission.  *  *  THE UNIVERSITY OF SOUTHERN CALIFORNIA DOES NOT MAKE ANY REPRESENTATIONS  *  ABOUT THE SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE.  THIS SOFTWARE IS  *  PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,  *  INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND  *  NON-INFRINGEMENT.  *  *  IN NO EVENT SHALL USC, OR ANY OTHER CONTRIBUTOR BE LIABLE FOR ANY  *  SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, WHETHER IN CONTRACT,  *  TORT, OR OTHER FORM OF ACTION, ARISING OUT OF OR IN CONNECTION WITH,  *  THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *  Other copyrights might apply to parts of this software and are so  *  noted when applicable.  */
end_comment

begin_comment
comment|/*  Questions concerning this software should be directed to  *  Mickael Hoerdt (hoerdt@clarinet.u-strasbg.fr) LSIIT Strasbourg.  *  */
end_comment

begin_comment
comment|/*  * This program has been derived from pim6dd.          * The pim6dd program is covered by the license in the accompanying file  * named "LICENSE.pim6dd".  */
end_comment

begin_comment
comment|/*  * This program has been derived from pimd.          * The pimd program is covered by the license in the accompanying file  * named "LICENSE.pimd".  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PIMD_H
end_ifndef

begin_define
define|#
directive|define
name|PIMD_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_define
define|#
directive|define
name|PIM_PROTOCOL_VERSION
value|2
end_define

begin_comment
comment|/* PIM protocol timers (in seconds) */
end_comment

begin_define
define|#
directive|define
name|PIM_REGISTER_SUPPRESSION_TIMEOUT
value|60
end_define

begin_define
define|#
directive|define
name|PIM_REGISTER_PROBE_TIME
value|5
end_define

begin_comment
comment|/* Used to send NULL_REGISTER */
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
name|PIM_JOIN_PRUNE_PERIOD
value|60
end_define

begin_define
define|#
directive|define
name|PIM_JOIN_PRUNE_HOLDTIME
value|(3.5 * PIM_JOIN_PRUNE_PERIOD)
end_define

begin_define
define|#
directive|define
name|PIM_RANDOM_DELAY_JOIN_TIMEOUT
value|4.5
end_define

begin_define
define|#
directive|define
name|PIM_DEFAULT_CAND_RP_ADV_PERIOD
value|60
end_define

begin_define
define|#
directive|define
name|PIM_DEFAULT_BOOTSTRAP_PERIOD
value|60
end_define

begin_define
define|#
directive|define
name|PIM_BOOTSTRAP_TIMEOUT
value|(2.5 * PIM_DEFAULT_BOOTSTRAP_PERIOD + 10)
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
value|180
end_define

begin_comment
comment|/* Misc definitions */
end_comment

begin_define
define|#
directive|define
name|PIM_DEFAULT_CAND_RP_PRIORITY
value|0
end_define

begin_comment
comment|/* 0 is the highest. Don't know                          		     * why this is the default.                          		     * See the PS version (Mar' 97),                          		     * pp.22 bottom of the spec.                          		     */
end_comment

begin_define
define|#
directive|define
name|PIM_DEFAULT_BSR_PRIORITY
value|0
end_define

begin_comment
comment|/* 0 is the lowest               */
end_comment

begin_define
define|#
directive|define
name|RP_DEFAULT_IPV6_HASHMASKLEN
value|126
end_define

begin_comment
comment|/* the default group msklen used                          		       *  by the hash function to 					       * calculate the group-to-RP                          		       * mapping 					       */
end_comment

begin_define
define|#
directive|define
name|SINGLE_SRC_MSK6LEN
value|128
end_define

begin_comment
comment|/* the single source mask length */
end_comment

begin_define
define|#
directive|define
name|SINGLE_GRP_MSK6LEN
value|128
end_define

begin_comment
comment|/* the single group mask length  */
end_comment

begin_comment
comment|/* TODO: change? */
end_comment

begin_define
define|#
directive|define
name|PIM_GROUP_PREFIX_DEFAULT_MASKLEN
value|8
end_define

begin_comment
comment|/* The default group masklen if                                              * omitted in the config file.                                              */
end_comment

begin_comment
comment|/* Datarate related definitions */
end_comment

begin_comment
comment|/* REG_RATE is used by the RP to switch to the shortest path instead of  * decapsulating Registers.  * DATA_RATE is the threshold for the last hop router to initiate  * switching to the shortest path.  */
end_comment

begin_comment
comment|/* TODO: XXX: probably no need for two different intervals.  */
end_comment

begin_define
define|#
directive|define
name|PIM_DEFAULT_REG_RATE
value|50000
end_define

begin_comment
comment|/* max # of register bits/s   */
end_comment

begin_define
define|#
directive|define
name|PIM_DEFAULT_REG_RATE_INTERVAL
value|20
end_define

begin_comment
comment|/* regrate probe interval     */
end_comment

begin_define
define|#
directive|define
name|PIM_DEFAULT_DATA_RATE
value|50000
end_define

begin_comment
comment|/* max # of data bits/s       */
end_comment

begin_define
define|#
directive|define
name|PIM_DEFAULT_DATA_RATE_INTERVAL
value|20
end_define

begin_comment
comment|/* datarate check interval    */
end_comment

begin_define
define|#
directive|define
name|DATA_RATE_CHECK_INTERVAL
value|20
end_define

begin_comment
comment|/* Data rate check interval   */
end_comment

begin_define
define|#
directive|define
name|REG_RATE_CHECK_INTERVAL
value|20
end_define

begin_comment
comment|/* PIM Reg. rate check interval*/
end_comment

begin_define
define|#
directive|define
name|UCAST_ROUTING_CHECK_INTERVAL
value|20
end_define

begin_comment
comment|/* Unfortunately, if the unicast                                                * routing changes, the kernel                                                * or any of the existing                                                * unicast routing daemons                                                * don't send us a signal.                                                * Have to ask periodically the                                                * kernel for any route changes.                                                * Default: every 20 seconds.                                                * Sigh.                                                */
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
name|DEFAULT_REG_RATE_LIMIT
value|0
end_define

begin_comment
comment|/* default register_vif rate limit  */
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
name|ADDRT_IPv6
value|0
end_define

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
comment|/* XXX: Note the 32-bit boundary                       * misalignment for  the unicast                       * address when placed in the                       * memory. Must read it byte-by-byte!                       */
block|}
name|pim6_encod_uni_addr_t
typedef|;
end_typedef

begin_comment
comment|/* XXX: sizeof(pim6_encod_uni_addr_t) does not work due to misalignment */
end_comment

begin_define
define|#
directive|define
name|PIM6_ENCODE_UNI_ADDR_LEN
value|18
end_define

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

begin_comment
comment|/* XXX: sizeof(pim6_encod_grp_addr_t) MAY NOT work due to an alignment problem */
end_comment

begin_define
define|#
directive|define
name|PIM6_ENCODE_GRP_ADDR_LEN
value|20
end_define

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

begin_comment
comment|/* XXX: sizeof(pim6_encod_src_addr_t) MAY NOT work due to an alignment problem */
end_comment

begin_define
define|#
directive|define
name|PIM6_ENCODE_SRC_ADDR_LEN
value|20
end_define

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

begin_comment
comment|/* PIM Register */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pim_register_
block|{
name|u_int32
name|reg_flags
decl_stmt|;
block|}
name|pim_register_t
typedef|;
end_typedef

begin_comment
comment|/* PIM Register-Stop */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pim_register_stop_
block|{
name|pim6_encod_grp_addr_t
name|encod_grp
decl_stmt|;
name|pim6_encod_uni_addr_t
name|encod_src
decl_stmt|;
comment|/* XXX: 18 bytes long, misaligned */
block|}
name|pim_register_stop_t
typedef|;
end_typedef

begin_comment
comment|/* PIM Join/Prune: XXX: all 128-bit addresses misaligned! */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pim_jp_header_
block|{
name|pim6_encod_uni_addr_t
name|encod_upstream_nbr
decl_stmt|;
name|u_int8
name|reserved
decl_stmt|;
name|u_int8
name|num_groups
decl_stmt|;
name|u_int16
name|holdtime
decl_stmt|;
block|}
name|pim_jp_header_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pim_jp_encod_grp_
block|{
name|pim6_encod_grp_addr_t
name|encod_grp
decl_stmt|;
name|u_int16
name|number_join_src
decl_stmt|;
name|u_int16
name|number_prune_src
decl_stmt|;
block|}
name|pim_jp_encod_grp_t
typedef|;
end_typedef

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

begin_comment
comment|/* PIM_REGISTER definitions */
end_comment

begin_define
define|#
directive|define
name|PIM_MESSAGE_REGISTER_BORDER_BIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PIM_MESSAGE_REGISTER_NULL_REGISTER_BIT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MASK_TO_MASKLEN6
parameter_list|(
name|mask
parameter_list|,
name|masklen
parameter_list|)
define|\
value|do { \ 			register u_int32 tmp_mask;							\ 			register u_int8  tmp_masklen = sizeof((mask))<<3;	\ 			int i;  \ 			int kl; \ 			for(i=0;i<4;i++)									\ 			{													\ 				tmp_mask=ntohl(*(u_int32_t *)&mask.s6_addr[i * 4]); \ 				for(kl=32; tmp_masklen>0&& kl>0 ; tmp_masklen--, kl-- , tmp_mask>>=1) \ 					if( tmp_mask& 0x1)			\ 						break;   	\ 			} \ 			(masklen) =tmp_masklen;	\ 		} while (0)
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
value|do {\          u_char maskarray[8] = \          {0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff}; \          int bytelen, bitlen, i; \          memset(&(mask6), 0, sizeof(mask6));\          bytelen = (masklen) / 8;\          bitlen = (masklen) % 8;\          for (i = 0; i< bytelen; i++) \              (mask6).s6_addr[i] = 0xff;\          if (bitlen) \              (mask6).s6_addr[bytelen] = maskarray[bitlen - 1]; \      }while(0);
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
value|do {                                    \                  register u_int16 Xv;            \                  Xv = (u_int16)(val);            \                  *(cp)++ = (u_int8)(Xv>> 8);    \                  *(cp)++ = (u_int8)Xv;           \          } while (0)
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
name|GET_ESADDR6
parameter_list|(
name|esa
parameter_list|,
name|cp
parameter_list|)
comment|/* XXX: hard coding */
define|\
value|do {                                    \             (esa)->addr_family = *(cp)++;       \             (esa)->encod_type  = *(cp)++;       \             (esa)->flags       = *(cp)++;       \             (esa)->masklen     = *(cp)++;       \              memcpy(&(esa)->src_addr, (cp), sizeof(struct in6_addr)); \          (cp) += sizeof(struct in6_addr);   \         } while(0)
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
value|do {                                    \             int i; \             struct in6_addr maskaddr; \         MASKLEN_TO_MASK6(masklen, maskaddr); \             *(cp)++ = ADDRF_IPv6;
comment|/* family */
value|\             *(cp)++ = ADDRT_IPv6;
comment|/* type   */
value|\             *(cp)++ = (flags);
comment|/* flags  */
value|\             *(cp)++ = (masklen);                \             for (i = 0; i< sizeof(struct in6_addr); i++, (cp)++) \                 *(cp) = maskaddr.s6_addr[i]& (addr).s6_addr[i]; \         } while(0)
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
value|do {                                    \             (ega)->addr_family = *(cp)++;       \             (ega)->encod_type  = *(cp)++;       \             (ega)->reserved    = *(cp)++;       \             (ega)->masklen     = *(cp)++;       \              memcpy(&(ega)->mcast_addr, (cp), sizeof(struct in6_addr)); \         (cp) += sizeof(struct in6_addr);    \         } while(0)
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
value|do {                                    \              int i; \              struct in6_addr maskaddr; \          MASKLEN_TO_MASK6(masklen, maskaddr); \              *(cp)++ = ADDRF_IPv6;
comment|/* family */
value|\              *(cp)++ = ADDRT_IPv6;
comment|/* type   */
value|\              *(cp)++ = (reserved);
comment|/* reserved; should be 0 */
value|\              *(cp)++ = (masklen);                \              for (i = 0; i< sizeof(struct in6_addr); i++, (cp)++) \                  *(cp) = maskaddr.s6_addr[i]& (addr).s6_addr[i]; \          } while(0)
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
value|do {                                    \          (eua)->addr_family = *(cp)++;  \          (eua)->encod_type  = *(cp)++;  \              memcpy(&(eua)->unicast_addr, (cp), sizeof(struct in6_addr)); \          (cp) += sizeof(struct in6_addr);   \         } while(0)
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
value|do {                                    \              *(cp)++ = ADDRF_IPv6;
comment|/* family */
value|\              *(cp)++ = ADDRT_IPv6;
comment|/* type   */
value|\              memcpy((cp),&(addr), sizeof(struct in6_addr)); \              (cp) += sizeof(struct in6_addr); \          } while(0)
end_define

begin_comment
comment|/* Used if no relaible unicast routing information available */
end_comment

begin_define
define|#
directive|define
name|UCAST_DEFAULT_SOURCE_METRIC
value|1024
end_define

begin_define
define|#
directive|define
name|UCAST_DEFAULT_SOURCE_PREFERENCE
value|1024
end_define

begin_define
define|#
directive|define
name|DEFAULT_LOCAL_PREF
value|101
end_define

begin_comment
comment|/* assert pref par defaut */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_LOCAL_METRIC
value|1024
end_define

begin_comment
comment|/* assert metrique par default */
end_comment

begin_comment
comment|/*    * TODO: recalculate the messages sizes, probably with regard to the MTU  * TODO: cleanup  */
end_comment

begin_define
define|#
directive|define
name|MAX_JP_MESSAGE_SIZE
value|8192
end_define

begin_define
define|#
directive|define
name|MAX_JP_MESSAGE_POOL_NUMBER
value|8
end_define

begin_define
define|#
directive|define
name|MAX_JOIN_LIST_SIZE
value|1500
end_define

begin_define
define|#
directive|define
name|MAX_PRUNE_LIST_SIZE
value|1500
end_define

begin_define
define|#
directive|define
name|STAR_STAR_RP_MSK6LEN
value|8
end_define

begin_comment
comment|/* Masklen for                              			* ff00 ::                              			* to encode (*,*,RP)                              			*/
end_comment

begin_comment
comment|/* interface independent statistics */
end_comment

begin_struct
struct|struct
name|pim6dstat
block|{
comment|/* incoming PIM6 packets on this interface */
name|u_quad_t
name|in_pim6_register
decl_stmt|;
name|u_quad_t
name|in_pim6_register_stop
decl_stmt|;
name|u_quad_t
name|in_pim6_cand_rp
decl_stmt|;
name|u_quad_t
name|in_pim6_graft
decl_stmt|;
comment|/* for dense mode only */
name|u_quad_t
name|in_pim6_graft_ack
decl_stmt|;
comment|/* for dense mode only  */
comment|/* outgoing PIM6 packets on this interface */
name|u_quad_t
name|out_pim6_register
decl_stmt|;
name|u_quad_t
name|out_pim6_register_stop
decl_stmt|;
name|u_quad_t
name|out_pim6_cand_rp
decl_stmt|;
comment|/* SPT transition */
name|u_quad_t
name|pim6_trans_spt_forward
decl_stmt|;
name|u_quad_t
name|pim6_trans_spt_rp
decl_stmt|;
comment|/* occurrences of timeouts */
name|u_quad_t
name|pim6_bootstrap_timo
decl_stmt|;
comment|/* pim_bootstrap_timer */
name|u_quad_t
name|pim6_rpgrp_timo
decl_stmt|;
comment|/* rp_grp_entry_ptr->holdtime */
name|u_quad_t
name|pim6_rtentry_timo
decl_stmt|;
comment|/* routing entry */
comment|/* kernel internals */
name|u_quad_t
name|kern_add_cache
decl_stmt|;
name|u_quad_t
name|kern_add_cache_fail
decl_stmt|;
name|u_quad_t
name|kern_del_cache
decl_stmt|;
name|u_quad_t
name|kern_del_cache_fail
decl_stmt|;
name|u_quad_t
name|kern_sgcnt_fail
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|pim6dstat
name|pim6dstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

