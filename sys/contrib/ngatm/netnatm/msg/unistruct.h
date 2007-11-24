begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: libunimsg/netnatm/msg/unistruct.h,v 1.7 2004/07/16 18:42:22 brandt Exp $  *  * This file defines all structures that are used by  * API users.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_MSG_UNISTRUCT_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_MSG_UNISTRUCT_H_
end_define

begin_include
include|#
directive|include
file|<netnatm/msg/uni_config.h>
end_include

begin_comment
comment|/*  * define IE and MSG header  */
end_comment

begin_include
include|#
directive|include
file|<netnatm/msg/uni_hdr.h>
end_include

begin_comment
comment|/*  * define all IE's  */
end_comment

begin_comment
comment|/*************************************************************************  *  * Free FORM IE  */
end_comment

begin_struct
struct|struct
name|uni_ie_unrec
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|uint8_t
name|id
decl_stmt|;
comment|/* ID of this IE */
name|u_int
name|len
decl_stmt|;
comment|/* data length */
name|u_char
name|data
index|[
literal|128
index|]
decl_stmt|;
comment|/* arbitrary maximum length */
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * ATM adaptation layer parameters information element  */
end_comment

begin_enum
enum|enum
block|{
name|UNI_AAL_SUB_ID
init|=
literal|0x85
block|,
name|UNI_AAL_CBR_ID
init|=
literal|0x86
block|,
name|UNI_AAL_MULT_ID
init|=
literal|0x87
block|,
name|UNI_AAL_SCREC_ID
init|=
literal|0x88
block|,
name|UNI_AAL_ECM_ID
init|=
literal|0x89
block|,
name|UNI_AAL_BSIZE_ID
init|=
literal|0x8a
block|,
name|UNI_AAL_PART_ID
init|=
literal|0x8b
block|,
name|UNI_AAL_FWDCPCS_ID
init|=
literal|0x8c
block|,
name|UNI_AAL_BWDCPCS_ID
init|=
literal|0x81
block|,
name|UNI_AAL_MID_ID
init|=
literal|0x82
block|,
name|UNI_AAL_SSCS_ID
init|=
literal|0x84
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_aal
block|{
name|UNI_AAL_0
init|=
literal|0x00
block|,
comment|/* voice */
name|UNI_AAL_1
init|=
literal|0x01
block|,
name|UNI_AAL_2
init|=
literal|0x02
block|,
name|UNI_AAL_4
init|=
literal|0x03
block|,
comment|/* same as AAL 3 */
name|UNI_AAL_5
init|=
literal|0x05
block|,
name|UNI_AAL_USER
init|=
literal|0x10
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_aal1_subtype
block|{
name|UNI_AAL1_SUB_NULL
init|=
literal|0x00
block|,
name|UNI_AAL1_SUB_VOICE
init|=
literal|0x01
block|,
name|UNI_AAL1_SUB_CIRCUIT
init|=
literal|0x02
block|,
name|UNI_AAL1_SUB_HQAUDIO
init|=
literal|0x04
block|,
name|UNI_AAL1_SUB_VIDEO
init|=
literal|0x05
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_aal1_cbr
block|{
name|UNI_AAL1_CBR_64
init|=
literal|0x01
block|,
name|UNI_AAL1_CBR_1544
init|=
literal|0x04
block|,
name|UNI_AAL1_CBR_6312
init|=
literal|0x05
block|,
name|UNI_AAL1_CBR_32064
init|=
literal|0x06
block|,
name|UNI_AAL1_CBR_44736
init|=
literal|0x07
block|,
name|UNI_AAL1_CBR_97728
init|=
literal|0x08
block|,
name|UNI_AAL1_CBR_2048
init|=
literal|0x10
block|,
name|UNI_AAL1_CBR_8448
init|=
literal|0x11
block|,
name|UNI_AAL1_CBR_34368
init|=
literal|0x12
block|,
name|UNI_AAL1_CBR_139264
init|=
literal|0x13
block|,
name|UNI_AAL1_CBR_N64
init|=
literal|0x40
block|,
name|UNI_AAL1_CBR_N8
init|=
literal|0x41
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_aal1_screc
block|{
name|UNI_AAL1_SCREC_NULL
init|=
literal|0x00
block|,
comment|/* synchr. circuit transport */
name|UNI_AAL1_SCREC_SRTS
init|=
literal|0x01
block|,
comment|/* synchr. residual timestamp */
name|UNI_AAL1_SCREC_ACLK
init|=
literal|0x02
block|,
comment|/* adaptive clock */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|uni_aal1_ecm
block|{
name|UNI_AAL1_ECM_NULL
init|=
literal|0x00
block|,
comment|/* no error correction */
name|UNI_AAL1_ECM_LOSS
init|=
literal|0x01
block|,
comment|/* for loss sensitive signals */
name|UNI_AAL1_ECM_DELAY
init|=
literal|0x02
block|,
comment|/* for delay sensitive signals */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|uni_aal_sscs
block|{
name|UNI_AAL_SSCS_NULL
init|=
literal|0x00
block|,
comment|/* Null */
name|UNI_AAL_SSCS_SSCOPA
init|=
literal|0x01
block|,
comment|/* assured SSCOP */
name|UNI_AAL_SSCS_SSCOPU
init|=
literal|0x02
block|,
comment|/* unassured SSCOP */
name|UNI_AAL_SSCS_FRAME
init|=
literal|0x04
block|,
comment|/* frame relay */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_aal
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_aal
name|type
decl_stmt|;
comment|/* aal type */
union|union
block|{
define|#
directive|define
name|UNI_AAL1_MULT_P
value|0x01
define|#
directive|define
name|UNI_AAL1_SCREC_P
value|0x02
define|#
directive|define
name|UNI_AAL1_ECM_P
value|0x04
define|#
directive|define
name|UNI_AAL1_BSIZE_P
value|0x08
define|#
directive|define
name|UNI_AAL1_PART_P
value|0x10
struct|struct
block|{
name|enum
name|uni_aal1_subtype
name|subtype
decl_stmt|;
comment|/* AAL1 subtype */
name|enum
name|uni_aal1_cbr
name|cbr_rate
decl_stmt|;
comment|/* AAL1 CBR rate */
name|u_int
name|mult
decl_stmt|;
comment|/* AAL1 CBR mutliplier */
name|enum
name|uni_aal1_screc
name|screc
decl_stmt|;
comment|/* AAL1 source clock recovery */
name|enum
name|uni_aal1_ecm
name|ecm
decl_stmt|;
comment|/* AAL1 error correction */
name|u_int
name|bsize
decl_stmt|;
comment|/* AAL1 SDT blocksize */
name|u_int
name|part
decl_stmt|;
comment|/* AAL1 partial cell fill */
block|}
name|aal1
struct|;
define|#
directive|define
name|UNI_AAL4_CPCS_P
value|0x01
define|#
directive|define
name|UNI_AAL4_MID_P
value|0x02
define|#
directive|define
name|UNI_AAL4_SSCS_P
value|0x04
struct|struct
block|{
name|u_int
name|fwd_cpcs
decl_stmt|;
comment|/* max fwd cpcs blocksize */
name|u_int
name|bwd_cpcs
decl_stmt|;
comment|/* max bkw cpcs blocksize */
name|u_int
name|mid_low
decl_stmt|;
comment|/* MID low range */
name|u_int
name|mid_high
decl_stmt|;
comment|/* MID high range */
name|enum
name|uni_aal_sscs
name|sscs
decl_stmt|;
comment|/* sscs type */
block|}
name|aal4
struct|;
define|#
directive|define
name|UNI_AAL5_CPCS_P
value|0x01
define|#
directive|define
name|UNI_AAL5_SSCS_P
value|0x02
struct|struct
block|{
name|u_int
name|fwd_cpcs
decl_stmt|;
comment|/* max fwd cpcs blocksize */
name|u_int
name|bwd_cpcs
decl_stmt|;
comment|/* max bkw cpcs blocksize */
name|enum
name|uni_aal_sscs
name|sscs
decl_stmt|;
comment|/* sscs type */
block|}
name|aal5
struct|;
struct|struct
block|{
name|u_int
name|len
decl_stmt|;
comment|/* number of bytes */
name|u_char
name|user
index|[
literal|4
index|]
decl_stmt|;
comment|/* user data */
block|}
name|aalu
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Called party number information element  * Called party subaddress information element  * Calling party number information element  * Calling party subaddress information element  * Q.2951/UNI4.0 Connected number information element  * Q.2951/UNI4.0 Connected subaddress information element  */
end_comment

begin_enum
enum|enum
name|uni_addr_type
block|{
name|UNI_ADDR_UNKNOWN
init|=
literal|0x0
block|,
name|UNI_ADDR_INTERNATIONAL
init|=
literal|0x1
block|,
name|UNI_ADDR_NATIONAL
init|=
literal|0x2
block|,
comment|/* not sup */
name|UNI_ADDR_NETWORK
init|=
literal|0x3
block|,
comment|/* not sup */
name|UNI_ADDR_SUBSCR
init|=
literal|0x4
block|,
comment|/* not sup */
name|UNI_ADDR_ABBR
init|=
literal|0x6
block|,
comment|/* not sup */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|uni_addr_plan
block|{
comment|/* UNI_ADDR_UNKNOWN	= 0x0, */
comment|/* not sup */
name|UNI_ADDR_E164
init|=
literal|0x1
block|,
name|UNI_ADDR_ATME
init|=
literal|0x2
block|,
name|UNI_ADDR_DATA
init|=
literal|0x3
block|,
comment|/* not sup */
name|UNI_ADDR_PRIVATE
init|=
literal|0x9
block|,
comment|/* not sup */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|uni_subaddr_type
block|{
name|UNI_SUBADDR_NSAP
init|=
literal|0x0
block|,
name|UNI_SUBADDR_ATME
init|=
literal|0x1
block|,
name|UNI_SUBADDR_USER
init|=
literal|0x2
block|,
comment|/* not sup */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|uni_addr_pres
block|{
name|UNI_ADDR_PRES
init|=
literal|0x0
block|,
name|UNI_ADDR_RESTRICT
init|=
literal|0x1
block|,
name|UNI_ADDR_NONUMBER
init|=
literal|0x2
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_addr_screen
block|{
name|UNI_ADDR_SCREEN_NOT
init|=
literal|0x0
block|,
name|UNI_ADDR_SCREEN_PASSED
init|=
literal|0x1
block|,
name|UNI_ADDR_SCREEN_FAILED
init|=
literal|0x2
block|,
name|UNI_ADDR_SCREEN_NET
init|=
literal|0x3
block|, }
enum|;
end_enum

begin_comment
comment|/* don't use bitfields to get a defined structure layout */
end_comment

begin_struct
struct|struct
name|uni_addr
block|{
name|uint8_t
name|type
decl_stmt|;
name|uint8_t
name|plan
decl_stmt|;
name|uint8_t
name|len
decl_stmt|;
name|u_char
name|addr
index|[
name|UNI_ADDR_MAXLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_subaddr
block|{
name|enum
name|uni_subaddr_type
name|type
decl_stmt|;
name|u_int
name|len
decl_stmt|;
name|u_char
name|addr
index|[
name|UNI_SUBADDR_MAXLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie_called
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|struct
name|uni_addr
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie_calledsub
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|struct
name|uni_subaddr
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie_calling
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
define|#
directive|define
name|UNI_CALLING_SCREEN_P
value|0x0001
name|struct
name|uni_addr
name|addr
decl_stmt|;
name|enum
name|uni_addr_pres
name|pres
decl_stmt|;
name|enum
name|uni_addr_screen
name|screen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie_callingsub
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|struct
name|uni_subaddr
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie_conned
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
define|#
directive|define
name|UNI_CONNED_SCREEN_P
value|0x0001
name|struct
name|uni_addr
name|addr
decl_stmt|;
name|enum
name|uni_addr_pres
name|pres
decl_stmt|;
name|enum
name|uni_addr_screen
name|screen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie_connedsub
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|struct
name|uni_subaddr
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Broadband bearer capability descriptor  * On reception of an old bearer descriptor, it is automatically  * converted to a new, legal one.  */
end_comment

begin_enum
enum|enum
name|uni_bearer_class
block|{
name|UNI_BEARER_A
init|=
literal|0x01
block|,
name|UNI_BEARER_C
init|=
literal|0x03
block|,
name|UNI_BEARER_X
init|=
literal|0x10
block|,
name|UNI_BEARER_TVP
init|=
literal|0x30
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_bearer_atc
block|{
name|UNI_BEARER_ATC_CBR
init|=
literal|0x05
block|,
name|UNI_BEARER_ATC_CBR1
init|=
literal|0x07
block|,
name|UNI_BEARER_ATC_VBR
init|=
literal|0x09
block|,
name|UNI_BEARER_ATC_VBR1
init|=
literal|0x13
block|,
name|UNI_BEARER_ATC_NVBR
init|=
literal|0x0a
block|,
name|UNI_BEARER_ATC_NVBR1
init|=
literal|0x0b
block|,
name|UNI_BEARER_ATC_ABR
init|=
literal|0x0c
block|,
name|UNI_BEARER_ATCX_0
init|=
literal|0x00
block|,
name|UNI_BEARER_ATCX_1
init|=
literal|0x01
block|,
name|UNI_BEARER_ATCX_2
init|=
literal|0x02
block|,
name|UNI_BEARER_ATCX_4
init|=
literal|0x04
block|,
name|UNI_BEARER_ATCX_6
init|=
literal|0x06
block|,
name|UNI_BEARER_ATCX_8
init|=
literal|0x08
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_bearer_clip
block|{
name|UNI_BEARER_NOCLIP
init|=
literal|0x0
block|,
name|UNI_BEARER_CLIP
init|=
literal|0x1
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_bearer_cfg
block|{
name|UNI_BEARER_P2P
init|=
literal|0x0
block|,
name|UNI_BEARER_MP
init|=
literal|0x1
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_bearer
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
define|#
directive|define
name|UNI_BEARER_ATC_P
value|0x02
name|enum
name|uni_bearer_class
name|bclass
decl_stmt|;
comment|/* bearer class */
name|enum
name|uni_bearer_atc
name|atc
decl_stmt|;
comment|/* ATM transfer capability */
name|enum
name|uni_bearer_clip
name|clip
decl_stmt|;
comment|/* suspectibility to clipping */
name|enum
name|uni_bearer_cfg
name|cfg
decl_stmt|;
comment|/* u-plane configuration */
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Broadband higher layer information element  */
end_comment

begin_enum
enum|enum
name|uni_bhli
block|{
name|UNI_BHLI_ISO
init|=
literal|0x00
block|,
comment|/* IDO defined */
name|UNI_BHLI_USER
init|=
literal|0x01
block|,
comment|/* user specific */
name|UNI_BHLI_VENDOR
init|=
literal|0x03
block|,
comment|/* vendor specific */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_bhli
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_bhli
name|type
decl_stmt|;
name|u_char
name|info
index|[
literal|8
index|]
decl_stmt|;
name|u_int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Boradband lower layer information element  */
end_comment

begin_enum
enum|enum
block|{
name|UNI_BLLI_L1_ID
init|=
literal|0x1
block|,
name|UNI_BLLI_L2_ID
init|=
literal|0x2
block|,
name|UNI_BLLI_L3_ID
init|=
literal|0x3
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_blli_l2
block|{
name|UNI_BLLI_L2_BASIC
init|=
literal|0x01
block|,
name|UNI_BLLI_L2_Q921
init|=
literal|0x02
block|,
name|UNI_BLLI_L2_X25LL
init|=
literal|0x06
block|,
name|UNI_BLLI_L2_X25ML
init|=
literal|0x07
block|,
name|UNI_BLLI_L2_LABP
init|=
literal|0x08
block|,
name|UNI_BLLI_L2_HDLC_ARM
init|=
literal|0x09
block|,
name|UNI_BLLI_L2_HDLC_NRM
init|=
literal|0x0a
block|,
name|UNI_BLLI_L2_HDLC_ABM
init|=
literal|0x0b
block|,
name|UNI_BLLI_L2_LAN
init|=
literal|0x0c
block|,
name|UNI_BLLI_L2_X75
init|=
literal|0x0d
block|,
name|UNI_BLLI_L2_Q922
init|=
literal|0x0e
block|,
name|UNI_BLLI_L2_USER
init|=
literal|0x10
block|,
name|UNI_BLLI_L2_ISO7776
init|=
literal|0x11
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_blli_l2_mode
block|{
name|UNI_BLLI_L2NORM
init|=
literal|0x1
block|,
name|UNI_BLLI_L2EXT
init|=
literal|0x2
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_blli_l3
block|{
name|UNI_BLLI_L3_X25
init|=
literal|0x06
block|,
name|UNI_BLLI_L3_ISO8208
init|=
literal|0x07
block|,
name|UNI_BLLI_L3_X223
init|=
literal|0x08
block|,
name|UNI_BLLI_L3_CLMP
init|=
literal|0x09
block|,
name|UNI_BLLI_L3_T70
init|=
literal|0x0a
block|,
name|UNI_BLLI_L3_TR9577
init|=
literal|0x0b
block|,
name|UNI_BLLI_L3_H310
init|=
literal|0x0c
block|,
name|UNI_BLLI_L3_H321
init|=
literal|0x0d
block|,
name|UNI_BLLI_L3_USER
init|=
literal|0x10
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_blli_l3_mode
block|{
name|UNI_BLLI_L3NSEQ
init|=
literal|0x1
block|,
comment|/* normal sequence numbering */
name|UNI_BLLI_L3ESEQ
init|=
literal|0x2
block|,
comment|/* extended sequence numbering */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|uni_blli_l3_psiz
block|{
name|UNI_BLLI_L3_16
init|=
literal|0x4
block|,
comment|/* 16 byte packets */
name|UNI_BLLI_L3_32
init|=
literal|0x5
block|,
comment|/* 32 byte packets */
name|UNI_BLLI_L3_64
init|=
literal|0x6
block|,
comment|/* 64 byte packets */
name|UNI_BLLI_L3_128
init|=
literal|0x7
block|,
comment|/* 128 byte packets */
name|UNI_BLLI_L3_256
init|=
literal|0x8
block|,
comment|/* 256 byte packets */
name|UNI_BLLI_L3_512
init|=
literal|0x9
block|,
comment|/* 512 byte packets */
name|UNI_BLLI_L3_1024
init|=
literal|0xa
block|,
comment|/* 1024 byte packets */
name|UNI_BLLI_L3_2048
init|=
literal|0xb
block|,
comment|/* 2048 byte packets */
name|UNI_BLLI_L3_4096
init|=
literal|0xc
block|,
comment|/* 4096 byte packets */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|uni_blli_l3_ttype
block|{
name|UNI_BLLI_L3_TTYPE_RECV
init|=
literal|0x1
block|,
comment|/* receive only */
name|UNI_BLLI_L3_TTYPE_SEND
init|=
literal|0x2
block|,
comment|/* send only */
name|UNI_BLLI_L3_TTYPE_BOTH
init|=
literal|0x3
block|,
comment|/* both */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|uni_blli_l3_mux
block|{
name|UNI_BLLI_L3_MUX_NOMUX
init|=
literal|0
block|,
comment|/* no multiplexing */
name|UNI_BLLI_L3_MUX_TS
init|=
literal|1
block|,
comment|/* transport stream */
name|UNI_BLLI_L3_MUX_TSFEC
init|=
literal|2
block|,
comment|/* transport stream with FEC */
name|UNI_BLLI_L3_MUX_PS
init|=
literal|3
block|,
comment|/* program stream */
name|UNI_BLLI_L3_MUX_PSFEC
init|=
literal|4
block|,
comment|/* program stream with FEC */
name|UNI_BLLI_L3_MUX_H221
init|=
literal|5
block|,
comment|/* H.221 */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|uni_blli_l3_tcap
block|{
name|UNI_BLLI_L3_TCAP_NOIND
init|=
literal|0
block|,
comment|/* no indication */
name|UNI_BLLI_L3_TCAP_AAL1
init|=
literal|1
block|,
comment|/* only AAL1 */
name|UNI_BLLI_L3_TCAP_AAL5
init|=
literal|2
block|,
comment|/* only AAL5 */
name|UNI_BLLI_L3_TCAP_AAL15
init|=
literal|3
block|,
comment|/* AAL1 and AAL5 */
block|}
enum|;
end_enum

begin_comment
comment|/* Value for l3_ipi: */
end_comment

begin_enum
enum|enum
block|{
name|UNI_BLLI_L3_SNAP
init|=
literal|0x80
block|,
comment|/* IEEE 802.1 SNAP */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_blli
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
define|#
directive|define
name|UNI_BLLI_L1_P
value|0x0001
define|#
directive|define
name|UNI_BLLI_L2_P
value|0x0002
define|#
directive|define
name|UNI_BLLI_L2_Q933_P
value|0x0004
define|#
directive|define
name|UNI_BLLI_L2_WSIZ_P
value|0x0008
define|#
directive|define
name|UNI_BLLI_L2_USER_P
value|0x0010
define|#
directive|define
name|UNI_BLLI_L3_P
value|0x0020
define|#
directive|define
name|UNI_BLLI_L3_MODE_P
value|0x0040
define|#
directive|define
name|UNI_BLLI_L3_PSIZ_P
value|0x0080
define|#
directive|define
name|UNI_BLLI_L3_WSIZ_P
value|0x0100
define|#
directive|define
name|UNI_BLLI_L3_USER_P
value|0x0200
define|#
directive|define
name|UNI_BLLI_L3_IPI_P
value|0x0400
define|#
directive|define
name|UNI_BLLI_L3_SNAP_P
value|0x0800
define|#
directive|define
name|UNI_BLLI_L3_TTYPE_P
value|0x1000
define|#
directive|define
name|UNI_BLLI_L3_MUX_P
value|0x2000
name|u_int
name|l1
range|:
literal|5
decl_stmt|;
comment|/* layer 1 info */
name|enum
name|uni_blli_l2
name|l2
decl_stmt|;
comment|/* layer 2 info */
name|u_int
name|l2_q933
range|:
literal|2
decl_stmt|;
comment|/* layer 2 Q.933 use */
name|enum
name|uni_blli_l2_mode
name|l2_mode
decl_stmt|;
comment|/* layer 2 HDLC mode */
name|u_char
name|l2_user
decl_stmt|;
comment|/* layer 2 user info */
name|u_char
name|l2_wsiz
decl_stmt|;
comment|/* layer 2 window size */
name|enum
name|uni_blli_l3
name|l3
decl_stmt|;
comment|/* layer 3 info */
name|enum
name|uni_blli_l3_mode
name|l3_mode
decl_stmt|;
comment|/* layer 3 mode */
name|enum
name|uni_blli_l3_psiz
name|l3_psiz
decl_stmt|;
comment|/* layer 3 default packet size */
name|u_char
name|l3_wsiz
decl_stmt|;
comment|/* layer 3 window size */
name|u_char
name|l3_user
decl_stmt|;
comment|/* layer 3 user info */
name|u_char
name|l3_ipi
decl_stmt|;
comment|/* IPI byte */
name|u_int
name|oui
decl_stmt|;
comment|/* OUI bytes */
name|u_int
name|pid
decl_stmt|;
comment|/* PID bytes */
name|enum
name|uni_blli_l3_ttype
name|l3_ttype
decl_stmt|;
comment|/* terminal bytes */
name|enum
name|uni_blli_l3_tcap
name|l3_tcap
decl_stmt|;
comment|/* terminal capability */
name|enum
name|uni_blli_l3_mux
name|l3_fmux
decl_stmt|;
comment|/* forward muxing */
name|enum
name|uni_blli_l3_mux
name|l3_bmux
decl_stmt|;
comment|/* forward muxing */
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Transit network selection IE  */
end_comment

begin_struct
struct|struct
name|uni_ie_tns
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|u_char
name|net
index|[
name|UNI_TNS_MAXLEN
index|]
decl_stmt|;
name|u_int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Call state information element  */
end_comment

begin_enum
enum|enum
name|uni_callstate
block|{
name|UNI_CALLSTATE_U0
init|=
literal|0x00
block|,
name|UNI_CALLSTATE_N0
init|=
literal|0x00
block|,
name|UNI_CALLSTATE_NN0
init|=
literal|0x00
block|,
name|UNI_CALLSTATE_U1
init|=
literal|0x01
block|,
name|UNI_CALLSTATE_N1
init|=
literal|0x01
block|,
name|UNI_CALLSTATE_NN1
init|=
literal|0x01
block|,
name|UNI_CALLSTATE_U3
init|=
literal|0x03
block|,
name|UNI_CALLSTATE_N3
init|=
literal|0x03
block|,
name|UNI_CALLSTATE_NN3
init|=
literal|0x03
block|,
name|UNI_CALLSTATE_U4
init|=
literal|0x04
block|,
name|UNI_CALLSTATE_N4
init|=
literal|0x04
block|,
name|UNI_CALLSTATE_NN4
init|=
literal|0x04
block|,
name|UNI_CALLSTATE_U6
init|=
literal|0x06
block|,
name|UNI_CALLSTATE_N6
init|=
literal|0x06
block|,
name|UNI_CALLSTATE_NN6
init|=
literal|0x06
block|,
name|UNI_CALLSTATE_U7
init|=
literal|0x07
block|,
name|UNI_CALLSTATE_N7
init|=
literal|0x07
block|,
name|UNI_CALLSTATE_NN7
init|=
literal|0x07
block|,
name|UNI_CALLSTATE_U8
init|=
literal|0x08
block|,
name|UNI_CALLSTATE_N8
init|=
literal|0x08
block|,
name|UNI_CALLSTATE_U9
init|=
literal|0x09
block|,
name|UNI_CALLSTATE_N9
init|=
literal|0x09
block|,
name|UNI_CALLSTATE_NN9
init|=
literal|0x09
block|,
name|UNI_CALLSTATE_U10
init|=
literal|0x0a
block|,
name|UNI_CALLSTATE_N10
init|=
literal|0x0a
block|,
name|UNI_CALLSTATE_NN10
init|=
literal|0x0a
block|,
name|UNI_CALLSTATE_U11
init|=
literal|0x0b
block|,
name|UNI_CALLSTATE_N11
init|=
literal|0x0b
block|,
name|UNI_CALLSTATE_NN11
init|=
literal|0x0b
block|,
name|UNI_CALLSTATE_U12
init|=
literal|0x0c
block|,
name|UNI_CALLSTATE_N12
init|=
literal|0x0c
block|,
name|UNI_CALLSTATE_NN12
init|=
literal|0x0c
block|,
name|UNI_CALLSTATE_REST0
init|=
literal|0x00
block|,
name|UNI_CALLSTATE_REST1
init|=
literal|0x3d
block|,
name|UNI_CALLSTATE_REST2
init|=
literal|0x3e
block|,
name|UNI_CALLSTATE_U13
init|=
literal|0x0d
block|,
name|UNI_CALLSTATE_N13
init|=
literal|0x0d
block|,
name|UNI_CALLSTATE_U14
init|=
literal|0x0e
block|,
name|UNI_CALLSTATE_N14
init|=
literal|0x0e
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_callstate
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_callstate
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Cause information element  */
end_comment

begin_enum
enum|enum
name|uni_cause_loc
block|{
name|UNI_CAUSE_LOC_USER
init|=
literal|0x0
block|,
name|UNI_CAUSE_LOC_PRIVLOC
init|=
literal|0x1
block|,
name|UNI_CAUSE_LOC_PUBLOC
init|=
literal|0x2
block|,
name|UNI_CAUSE_LOC_TRANSIT
init|=
literal|0x3
block|,
name|UNI_CAUSE_LOC_PUBREM
init|=
literal|0x4
block|,
name|UNI_CAUSE_LOC_PRIVREM
init|=
literal|0x5
block|,
name|UNI_CAUSE_LOC_INTERNAT
init|=
literal|0x6
block|,
name|UNI_CAUSE_LOC_BEYOND
init|=
literal|0x7
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|UNI_DECLARE_CAUSE_VALUES
define|\
value|D(UNALL_NUM,	0x01
comment|/*  1*/
value|, COND,	Q.850,	"Unallocated (unassigned) number") \ D(NOROUTE_NET,	0x02
comment|/*  2*/
value|, TNS,	Q.850,	"No route to specified transit network") \ D(NOROUTE,	0x03
comment|/*  3*/
value|, COND,	Q.850,	"No route to destination") \ D(SPTONE,	0x04
comment|/*  4*/
value|, NONE,	Q.850,	"Send special information tone") \ D(BADTRUNK,	0x05
comment|/*  5*/
value|, NONE,	Q.850,	"Misdialled trunk prefix") \ D(BADCHAN,	0x06
comment|/*  6*/
value|, NONE,	Q.850,	"Channel unacceptable") \ D(CALLAWARDED,	0x07
comment|/*  7*/
value|, NONE,	Q.850,	"Call awarded and being delivered in an established channel") \ D(PREEMPT,	0x08
comment|/*  8*/
value|, NONE,	Q.850,	"Preemption") \ D(PREEMPT_RES,	0x09
comment|/*  9*/
value|, NONE,	Q.850,	"Preemption - circuit reserved for reuse") \ D(CLEARING,	0x10
comment|/* 16*/
value|, COND,	Q.850,	"Normal call clearing") \ D(BUSY,		0x11
comment|/* 17*/
value|, CCBS,	Q.850,	"User busy") \ D(NO_RESPONSE,	0x12
comment|/* 18*/
value|, NONE,	Q.850,	"No user responding") \ D(NO_RESP_ALERT,0x13
comment|/* 19*/
value|, NONE,	Q.850,	"No answer from user (user alerted)") \ D(ABSENT,	0x14
comment|/* 20*/
value|, NONE,	Q.850,	"Subscriber absent") \ D(REJECTED,	0x15
comment|/* 21*/
value|, REJ,	Q.850,	"Call rejected") \ D(NUMCHG,	0x16
comment|/* 22*/
value|, NUMBER,	Q.850,	"Number changed") \ D(REDIR,	0x17
comment|/* 23*/
value|, NONE,	Q.850,	"Redirection to new destination") \ N(CLIR_REJECTED,0x17
comment|/* 23*/
value|, NONE,	UNI4.0,	"User rejects call with calling line identification restriction (CLIR)") \ D(EXCHG_ERR,	0x19
comment|/* 25*/
value|, NONE,	Q.850,	"Exchange routing error") \ D(NOSEL_CLEAR,	0x1a
comment|/* 26*/
value|, NONE,	Q.850,	"Non-selected user clearing") \ D(DST_OOO,	0x1b
comment|/* 27*/
value|, NONE,	Q.850,	"Destination out of order") \ D(INV_ADDR,	0x1c
comment|/* 28*/
value|, NONE,	Q.850,	"Invalid number format (address incomplete)") \ D(FAC_REJ,	0x1d
comment|/* 29*/
value|, FAC,	Q.850,	"Facility rejected") \ D(STATUS,	0x1e
comment|/* 30*/
value|, NONE,	Q.850,	"Response to STATUS ENQUIRY") \ D(UNSPEC,	0x1f
comment|/* 31*/
value|, NONE,	Q.850,	"Normal, unspecified") \ D(TMY_PARTY,	0x20
comment|/* 32*/
value|, NONE,	Q.2971,	"Too many pending add party requests") \ D(NOCHAN,	0x22
comment|/* 34*/
value|, CCBS,	Q.850,	"No circuit/channel available") \ N(SOFT_NAVL,	0x22
comment|/* 34*/
value|, NONE,	PNNI1.0,"Requested called party soft PVPC or PVCC not available")\ D(VPCI_NAVL,	0x23
comment|/* 35*/
value|, NONE,	Q.2610,	"Requested VPCI/VCI not available") \ D(VPCI_FAIL,	0x24
comment|/* 36*/
value|, NONE,	Q.2610,	"VPCI/VPI assignment failure") \ D(CRATE_NAVL,	0x25
comment|/* 37*/
value|, CRATE,	Q.2610,	"User cell rate not available") \ D(NET_OOO,	0x26
comment|/* 38*/
value|, NONE,	Q.850,	"Network out of order") \ D(FRAME_OOS,	0x27
comment|/* 39*/
value|, NONE,	Q.850,	"Permanent frame mode connection out of service") \ D(FRAME_OP,	0x28
comment|/* 40*/
value|, NONE,	Q.850,	"Permanent frame mode connection operational") \ D(TEMP,		0x29
comment|/* 41*/
value|, NONE,	Q.850,	"Temporary failure") \ D(CONG,		0x2a
comment|/* 42*/
value|, NONE,	Q.850,	"Switching equipment congestion") \ D(ACC_DISC,	0x2b
comment|/* 43*/
value|, IE,	Q.850,	"Access information discarded") \ D(REQNOCHAN,	0x2c
comment|/* 44*/
value|, NONE,	Q.850,	"Requested circuit/channel not available") \ D(NOVPCI,	0x2d
comment|/* 45*/
value|, NONE,	Q.2610,	"No VPCI/VCI available") \ D(PREC_BLOCK,	0x2e
comment|/* 46*/
value|, NONE,	Q.850,	"Precedence call blocked") \ D(RESRC_NAVL,	0x2f
comment|/* 47*/
value|, NONE,	Q.850,	"Resource unavailable, unspecified") \ D(QOS_NAVL,	0x31
comment|/* 49*/
value|, COND,	Q.850,	"Quality of service not available") \ D(FAC_NOTSUB,	0x32
comment|/* 50*/
value|, FAC,	Q.850,	"Requested facility not subscribed") \ D(OUT_CUG,	0x35
comment|/* 53*/
value|, NONE,	Q.850,	"Outgoing calls barred within CUG") \ N(PGL_CHG,	0x35
comment|/* 53*/
value|, NONE,	PNNI1.0,"Call cleared due to change in PGL") \ D(IN_CUG,	0x37
comment|/* 55*/
value|, NONE,	Q.850,	"Incoming call barred within CUG") \ D(BEARER_NAUTH,	0x39
comment|/* 57*/
value|, ATTR,	Q.850,	"Bearer capability not authorized") \ D(BEARER_NAVL,	0x3a
comment|/* 58*/
value|, ATTR,	Q.850,	"Bearer capability not presently available") \ D(INCONS,	0x3e
comment|/* 62*/
value|, NONE,	Q.850,	"Inconsistency in designated outgoing access information and subscriber class") \ D(OPT_NAVL,	0x3f
comment|/* 63*/
value|, NONE,	Q.850,	"Service or option not available, unspecified") \ D(BEARER_NIMPL,	0x41
comment|/* 65*/
value|, ATTR,	Q.850,	"Bearer capability not implemented") \ D(CHANNEL_NIMPL,0x42
comment|/* 66*/
value|, CHANNEL,	Q.850,	"Channel type not implemented") \ D(FAC_NIMPL,	0x45
comment|/* 69*/
value|, FAC,	Q.850,	"Requested facility not implemented") \ D(RESTR_DIG,	0x46
comment|/* 70*/
value|, NONE,	Q.850,	"Only restricted digital information bearer capability is available") \ D(TRAFFIC_UNSUP,0x49
comment|/* 73*/
value|, NONE,	Q.2971,	"Unsupported combination of traffic parameters") \ N(AAL_UNSUP,	0x4c
comment|/* 78*/
value|, NONE,	UNI3.1,	"AAL parameters cannot be supported") \ D(CREF_INV,	0x51
comment|/* 81*/
value|, NONE,	Q.850,	"Invalid call reference value") \ D(CHANNEL_NEX,	0x52
comment|/* 82*/
value|, CHANID,	Q.850,	"Identified channel does not exist") \ D(SUSPENDED,	0x53
comment|/* 83*/
value|, NONE,	Q.850,	"A suspended call exists, but this call identity does not") \ D(CID_INUSE,	0x54
comment|/* 84*/
value|, NONE,	Q.850,	"Call identity in use") \ D(NOTSUSP,	0x55
comment|/* 85*/
value|, NONE,	Q.850,	"No call suspended") \ D(CLEARED,	0x56
comment|/* 86*/
value|, CAUSE,	Q.850,	"Call having requested call identity has been cleared") \ D(NOT_MEMBER,	0x57
comment|/* 87*/
value|, NONE,	Q.850,	"User not member of CUG") \ D(INCOMP,	0x58
comment|/* 88*/
value|, PARAM,	Q.850,	"Incompatible destination") \ D(ENDP_INV,	0x59
comment|/* 89*/
value|, IE,	UNI3.1,	"Invalid endpoint reference") \ D(NEX_CUG,	0x5a
comment|/* 90*/
value|, NONE,	Q.850,	"Non-existend CUG") \ D(TRANSIT_INV,	0x5b
comment|/* 91*/
value|, NONE,	Q.850,	"Invalid transit network selection") \ D(AALNOTSUPP,	0x5d
comment|/* 93*/
value|, NONE,	Q.2610,	"AAL parameters cannot be supported") \ D(INVMSG,	0x5f
comment|/* 95*/
value|, NONE,	Q.850,	"Invalid message, unspecified") \ D(MANDAT,	0x60
comment|/* 96*/
value|, IE,	Q.850,	"Mandatory information element is missing") \ D(MTYPE_NIMPL,	0x61
comment|/* 97*/
value|, MTYPE,	Q.850,	"Message type non-existent or not implemented") \ D(MSG_NOTCOMP,	0x62
comment|/* 98*/
value|, MTYPE,	Q.850,	"Message not compatible with call state or message type non-existent or not implemented") \ D(IE_NIMPL,	0x63
comment|/* 99*/
value|, IE,	Q.850,	"Information element/parameter non-existent or not implemented") \ D(IE_INV,	0x64
comment|/*100*/
value|, IE,	Q.850,	"Invalid information element contents") \ D(MSG_INCOMP,	0x65
comment|/*101*/
value|, MTYPE,	Q.850,	"Message not compatible with call state") \ D(RECOVER,	0x66
comment|/*102*/
value|, TIMER,	Q.850,	"Recovery on timer expiry") \ D(PARAM_NEX,	0x67
comment|/*103*/
value|, PARAM,	Q.850,	"Parameter non-existent or not implemented, passed on") \ N(BAD_LENGTH,	0x68
comment|/*104*/
value|, NONE,	UNI3.1,	"Incorrect message length") \ D(PARAM_UNREC,	0x6e
comment|/*110*/
value|, PARAM,	Q.850,	"Message with unrecognized parameter, discarded") \ D(PROTO,	0x6f
comment|/*111*/
value|, NONE,	Q.850,	"Protocol error, unspecified") \ D(INTERWORKING,	0x7f
comment|/*127*/
value|, NONE,	Q.850,	"Interworking, unspecified")
end_define

begin_define
define|#
directive|define
name|D
parameter_list|(
name|NAME
parameter_list|,
name|VAL
parameter_list|,
name|DIAG
parameter_list|,
name|STD
parameter_list|,
name|STR
parameter_list|)
value|UNI_CAUSE_##NAME = VAL,
end_define

begin_define
define|#
directive|define
name|N
parameter_list|(
name|NAME
parameter_list|,
name|VAL
parameter_list|,
name|DIAG
parameter_list|,
name|STD
parameter_list|,
name|STR
parameter_list|)
value|UNI_CAUSE_##NAME = VAL,
end_define

begin_enum
enum|enum
name|uni_cause
block|{
name|UNI_DECLARE_CAUSE_VALUES
block|}
enum|;
end_enum

begin_undef
undef|#
directive|undef
name|D
end_undef

begin_undef
undef|#
directive|undef
name|N
end_undef

begin_enum
enum|enum
name|uni_cause_class
block|{
name|UNI_CAUSE_CLASS_NORM
init|=
literal|0x0
block|,
name|UNI_CAUSE_CLASS_NORM1
init|=
literal|0x1
block|,
name|UNI_CAUSE_CLASS_RES
init|=
literal|0x2
block|,
name|UNI_CAUSE_CLASS_NAVL
init|=
literal|0x3
block|,
name|UNI_CAUSE_CLASS_NIMPL
init|=
literal|0x4
block|,
name|UNI_CAUSE_CLASS_INV
init|=
literal|0x5
block|,
name|UNI_CAUSE_CLASS_PROTO
init|=
literal|0x6
block|,
name|UNI_CAUSE_CLASS_INTER
init|=
literal|0x7
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_cause_pu
block|{
name|UNI_CAUSE_PU_PROVIDER
init|=
literal|0
block|,
name|UNI_CAUSE_PU_USER
init|=
literal|1
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_cause_na
block|{
name|UNI_CAUSE_NA_NORMAL
init|=
literal|0
block|,
name|UNI_CAUSE_NA_ABNORMAL
init|=
literal|1
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_cause_cond
block|{
name|UNI_CAUSE_COND_UNKNOWN
init|=
literal|0
block|,
name|UNI_CAUSE_COND_PERM
init|=
literal|1
block|,
name|UNI_CAUSE_COND_TRANS
init|=
literal|2
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_cause_reason
block|{
name|UNI_CAUSE_REASON_USER
init|=
literal|0x00
block|,
name|UNI_CAUSE_REASON_IEMISS
init|=
literal|0x01
block|,
name|UNI_CAUSE_REASON_IESUFF
init|=
literal|0x02
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_diag
block|{
name|UNI_DIAG_NONE
block|,
comment|/* no diagnostics */
name|UNI_DIAG_COND
block|,
comment|/* Condition */
name|UNI_DIAG_TNS
block|,
comment|/* Transit Network Selector */
name|UNI_DIAG_REJ
block|,
comment|/* Call Rejected */
name|UNI_DIAG_NUMBER
block|,
comment|/* New Destination */
name|UNI_DIAG_CRATE
block|,
comment|/* Traffic descriptor subfield */
name|UNI_DIAG_ATTR
block|,
comment|/* Attribute idendity */
name|UNI_DIAG_PARAM
block|,
comment|/* Parameter, same as one IE */
name|UNI_DIAG_TIMER
block|,
comment|/* timer in ASCII */
name|UNI_DIAG_MTYPE
block|,
comment|/* Message type */
name|UNI_DIAG_IE
block|,
comment|/* Information element */
name|UNI_DIAG_CHANID
block|,
comment|/* VPCI/VCI */
name|UNI_DIAG_CAUSE
init|=
name|UNI_DIAG_NONE
block|,
comment|/* Not specified */
name|UNI_DIAG_CHANNEL
init|=
name|UNI_DIAG_NONE
block|,
comment|/* For N-ISDN */
name|UNI_DIAG_CCBS
init|=
name|UNI_DIAG_NONE
block|,
comment|/* Not used in Q.931 */
name|UNI_DIAG_FAC
init|=
name|UNI_DIAG_NONE
block|,
comment|/* Not specified */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|UNI_CAUSE_TRAFFIC_N
init|=
literal|34
operator|-
literal|6
block|,
name|UNI_CAUSE_IE_N
init|=
literal|34
operator|-
literal|6
block|,
name|UNI_CAUSE_ATTR_N
init|=
operator|(
literal|34
operator|-
literal|6
operator|)
operator|/
literal|3
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_cause
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
define|#
directive|define
name|UNI_CAUSE_COND_P
value|0x0001
define|#
directive|define
name|UNI_CAUSE_REJ_P
value|0x0002
define|#
directive|define
name|UNI_CAUSE_REJ_USER_P
value|0x0004
define|#
directive|define
name|UNI_CAUSE_REJ_IE_P
value|0x0008
define|#
directive|define
name|UNI_CAUSE_IE_P
value|0x0010
define|#
directive|define
name|UNI_CAUSE_TRAFFIC_P
value|0x0020
define|#
directive|define
name|UNI_CAUSE_VPCI_P
value|0x0040
define|#
directive|define
name|UNI_CAUSE_MTYPE_P
value|0x0080
define|#
directive|define
name|UNI_CAUSE_TIMER_P
value|0x0100
define|#
directive|define
name|UNI_CAUSE_TNS_P
value|0x0200
define|#
directive|define
name|UNI_CAUSE_NUMBER_P
value|0x0400
define|#
directive|define
name|UNI_CAUSE_ATTR_P
value|0x0800
define|#
directive|define
name|UNI_CAUSE_PARAM_P
value|0x1000
name|enum
name|uni_cause_loc
name|loc
decl_stmt|;
name|enum
name|uni_cause
name|cause
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|enum
name|uni_cause_pu
name|pu
decl_stmt|;
name|enum
name|uni_cause_na
name|na
decl_stmt|;
name|enum
name|uni_cause_cond
name|cond
decl_stmt|;
block|}
name|cond
struct|;
struct|struct
block|{
name|enum
name|uni_cause_reason
name|reason
decl_stmt|;
name|enum
name|uni_cause_cond
name|cond
decl_stmt|;
name|u_int
name|user
decl_stmt|;
name|uint8_t
name|ie
decl_stmt|;
block|}
name|rej
struct|;
struct|struct
block|{
name|uint8_t
name|ie
index|[
name|UNI_CAUSE_IE_N
index|]
decl_stmt|;
name|u_int
name|len
decl_stmt|;
block|}
name|ie
struct|;
struct|struct
block|{
name|uint8_t
name|traffic
index|[
name|UNI_CAUSE_TRAFFIC_N
index|]
decl_stmt|;
name|u_int
name|len
decl_stmt|;
block|}
name|traffic
struct|;
struct|struct
block|{
name|uint16_t
name|vpci
decl_stmt|;
name|uint16_t
name|vci
decl_stmt|;
block|}
name|vpci
struct|;
name|uint8_t
name|mtype
decl_stmt|;
name|u_char
name|timer
index|[
literal|3
index|]
decl_stmt|;
name|struct
name|uni_ie_tns
name|tns
decl_stmt|;
name|struct
name|uni_ie_called
name|number
decl_stmt|;
comment|/* TNS does not fit */
name|uint8_t
name|param
decl_stmt|;
struct|struct
block|{
name|u_int
name|nattr
decl_stmt|;
name|u_char
name|attr
index|[
name|UNI_CAUSE_ATTR_N
index|]
index|[
literal|3
index|]
decl_stmt|;
block|}
name|attr
struct|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_function_decl
name|enum
name|uni_diag
name|uni_diag
parameter_list|(
name|enum
name|uni_cause
parameter_list|,
name|enum
name|uni_coding
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return a string for the cause (NULL if the coding/cause are illegal) */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|uni_ie_cause2str
parameter_list|(
name|enum
name|uni_coding
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*************************************************************************  *  * Connection identifier information element  */
end_comment

begin_enum
enum|enum
name|uni_connid_type
block|{
name|UNI_CONNID_VCI
init|=
literal|0
block|,
name|UNI_CONNID_ANYVCI
init|=
literal|1
block|,
name|UNI_CONNID_NOVCI
init|=
literal|4
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_connid_assoc
block|{
name|UNI_CONNID_ASSOC
init|=
literal|0
block|,
name|UNI_CONNID_NONASSOC
init|=
literal|1
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_connid
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_connid_assoc
name|assoc
decl_stmt|;
name|enum
name|uni_connid_type
name|type
decl_stmt|;
name|u_int
name|vpci
range|:
literal|16
decl_stmt|;
name|u_int
name|vci
range|:
literal|16
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * End point reference IE  */
end_comment

begin_struct
struct|struct
name|uni_ie_epref
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|u_int
name|flag
range|:
literal|1
decl_stmt|;
name|u_int
name|epref
range|:
literal|15
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * End point state IE  */
end_comment

begin_enum
enum|enum
name|uni_epstate
block|{
name|UNI_EPSTATE_NULL
init|=
literal|0x00
block|,
name|UNI_EPSTATE_ADD_INIT
init|=
literal|0x01
block|,
name|UNI_EPSTATE_ALERT_DLVD
init|=
literal|0x04
block|,
name|UNI_EPSTATE_ADD_RCVD
init|=
literal|0x06
block|,
name|UNI_EPSTATE_ALERT_RCVD
init|=
literal|0x07
block|,
name|UNI_EPSTATE_ACTIVE
init|=
literal|0x0a
block|,
name|UNI_EPSTATE_DROP_INIT
init|=
literal|0x0b
block|,
name|UNI_EPSTATE_DROP_RCVD
init|=
literal|0x0c
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_epstate
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_epstate
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Q.2932 Facility IE  */
end_comment

begin_enum
enum|enum
block|{
name|UNI_FACILITY_ROSE
init|=
literal|0x11
block|,
name|UNI_FACILITY_MAXAPDU
init|=
literal|128
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_facility
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|u_char
name|proto
decl_stmt|;
name|u_char
name|apdu
index|[
name|UNI_FACILITY_MAXAPDU
index|]
decl_stmt|;
name|u_int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Notification indicator  */
end_comment

begin_enum
enum|enum
block|{
name|UNI_NOTIFY_MAXLEN
init|=
literal|128
block|,
comment|/* maximum info length */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_notify
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|u_int
name|len
decl_stmt|;
name|u_char
name|notify
index|[
name|UNI_NOTIFY_MAXLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * QoS information element  */
end_comment

begin_enum
enum|enum
name|uni_qos
block|{
name|UNI_QOS_CLASS0
init|=
literal|0x00
block|,
name|UNI_QOS_CLASS1
init|=
literal|0x01
block|,
name|UNI_QOS_CLASS2
init|=
literal|0x02
block|,
name|UNI_QOS_CLASS3
init|=
literal|0x03
block|,
name|UNI_QOS_CLASS4
init|=
literal|0x04
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_qos
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_qos
name|fwd
decl_stmt|;
name|enum
name|uni_qos
name|bwd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Broadband repeat indicator information element  */
end_comment

begin_enum
enum|enum
name|uni_repeat_type
block|{
name|UNI_REPEAT_PRIDESC
init|=
literal|0x02
block|,
name|UNI_REPEAT_STACK
init|=
literal|0x0a
block|,
comment|/* PNNI */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_repeat
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_repeat_type
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Restart indicator information element  */
end_comment

begin_enum
enum|enum
name|uni_restart_type
block|{
name|UNI_RESTART_CHANNEL
init|=
literal|0x0
block|,
name|UNI_RESTART_PATH
init|=
literal|0x1
block|,
name|UNI_RESTART_ALL
init|=
literal|0x2
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_restart
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_restart_type
name|rclass
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Broadband sending complete indicator information element  */
end_comment

begin_struct
struct|struct
name|uni_ie_scompl
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * ATM traffic descriptor information element  */
end_comment

begin_enum
enum|enum
block|{
name|UNI_TRAFFIC_FMDCR_ID
init|=
literal|0x00
block|,
name|UNI_TRAFFIC_BMDCR_ID
init|=
literal|0x02
block|,
name|UNI_TRAFFIC_FPCR0_ID
init|=
literal|0x82
block|,
name|UNI_TRAFFIC_BPCR0_ID
init|=
literal|0x83
block|,
name|UNI_TRAFFIC_FPCR1_ID
init|=
literal|0x84
block|,
name|UNI_TRAFFIC_BPCR1_ID
init|=
literal|0x85
block|,
name|UNI_TRAFFIC_FSCR0_ID
init|=
literal|0x88
block|,
name|UNI_TRAFFIC_BSCR0_ID
init|=
literal|0x89
block|,
name|UNI_TRAFFIC_FSCR1_ID
init|=
literal|0x90
block|,
name|UNI_TRAFFIC_BSCR1_ID
init|=
literal|0x91
block|,
name|UNI_TRAFFIC_FABR1_ID
init|=
literal|0x92
block|,
name|UNI_TRAFFIC_BABR1_ID
init|=
literal|0x93
block|,
name|UNI_TRAFFIC_FMBS0_ID
init|=
literal|0xa0
block|,
name|UNI_TRAFFIC_BMBS0_ID
init|=
literal|0xa1
block|,
name|UNI_TRAFFIC_FMBS1_ID
init|=
literal|0xb0
block|,
name|UNI_TRAFFIC_BMBS1_ID
init|=
literal|0xb1
block|,
name|UNI_TRAFFIC_BEST_ID
init|=
literal|0xbe
block|,
name|UNI_TRAFFIC_MOPT_ID
init|=
literal|0xbf
block|,
name|UNI_TRAFFIC_FTAG
init|=
literal|0x01
block|,
name|UNI_TRAFFIC_BTAG
init|=
literal|0x02
block|,
name|UNI_TRAFFIC_FDISC
init|=
literal|0x80
block|,
name|UNI_TRAFFIC_BDISC
init|=
literal|0x40
block|,
name|UNI_MINTRAFFIC_FPCR0_ID
init|=
literal|0x82
block|,
name|UNI_MINTRAFFIC_BPCR0_ID
init|=
literal|0x83
block|,
name|UNI_MINTRAFFIC_FPCR1_ID
init|=
literal|0x84
block|,
name|UNI_MINTRAFFIC_BPCR1_ID
init|=
literal|0x85
block|,
name|UNI_MINTRAFFIC_FABR1_ID
init|=
literal|0x92
block|,
name|UNI_MINTRAFFIC_BABR1_ID
init|=
literal|0x93
block|,
name|UNI_MDCR_ORIGIN_USER
init|=
literal|0x00
block|,
name|UNI_MDCR_ORIGIN_NET
init|=
literal|0x01
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|UNI_TRAFFIC_FPCR0_P
value|0x0001
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_BPCR0_P
value|0x0002
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_FPCR1_P
value|0x0004
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_BPCR1_P
value|0x0008
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_FSCR0_P
value|0x0010
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_BSCR0_P
value|0x0020
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_FSCR1_P
value|0x0040
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_BSCR1_P
value|0x0080
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_FMBS0_P
value|0x0100
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_BMBS0_P
value|0x0200
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_FMBS1_P
value|0x0400
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_BMBS1_P
value|0x0800
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_BEST_P
value|0x1000
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_MOPT_P
value|0x2000
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_FABR1_P
value|0x4000
end_define

begin_define
define|#
directive|define
name|UNI_TRAFFIC_BABR1_P
value|0x8000
end_define

begin_struct
struct|struct
name|uni_xtraffic
block|{
name|u_int
name|fpcr0
decl_stmt|,
name|bpcr0
decl_stmt|;
name|u_int
name|fpcr1
decl_stmt|,
name|bpcr1
decl_stmt|;
name|u_int
name|fscr0
decl_stmt|,
name|bscr0
decl_stmt|;
name|u_int
name|fscr1
decl_stmt|,
name|bscr1
decl_stmt|;
name|u_int
name|fmbs0
decl_stmt|,
name|bmbs0
decl_stmt|;
name|u_int
name|fmbs1
decl_stmt|,
name|bmbs1
decl_stmt|;
name|u_int
name|fabr1
decl_stmt|,
name|babr1
decl_stmt|;
name|u_int
name|ftag
decl_stmt|,
name|btag
decl_stmt|;
name|u_int
name|fdisc
decl_stmt|,
name|bdisc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie_traffic
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|struct
name|uni_xtraffic
name|t
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie_atraffic
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|struct
name|uni_xtraffic
name|t
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Q.2961 minimum traffic descriptor  */
end_comment

begin_struct
struct|struct
name|uni_ie_mintraffic
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
define|#
directive|define
name|UNI_MINTRAFFIC_FPCR0_P
value|0x0001
define|#
directive|define
name|UNI_MINTRAFFIC_BPCR0_P
value|0x0002
define|#
directive|define
name|UNI_MINTRAFFIC_FPCR1_P
value|0x0004
define|#
directive|define
name|UNI_MINTRAFFIC_BPCR1_P
value|0x0008
define|#
directive|define
name|UNI_MINTRAFFIC_FABR1_P
value|0x0010
define|#
directive|define
name|UNI_MINTRAFFIC_BABR1_P
value|0x0020
name|u_int
name|fpcr0
decl_stmt|,
name|bpcr0
decl_stmt|;
name|u_int
name|fpcr1
decl_stmt|,
name|bpcr1
decl_stmt|;
name|u_int
name|fabr1
decl_stmt|,
name|babr1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * UNI4.0+ (af-cs-0147.000) Minimum Desired Cell Rate  */
end_comment

begin_struct
struct|struct
name|uni_ie_mdcr
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|u_int
name|origin
decl_stmt|;
name|u_int
name|fmdcr
decl_stmt|,
name|bmdcr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * User-user information information element  */
end_comment

begin_struct
struct|struct
name|uni_ie_uu
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|u_int
name|len
decl_stmt|;
name|u_char
name|uu
index|[
name|UNI_UU_MAXLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Generic identifier transport  */
end_comment

begin_enum
enum|enum
name|uni_git_std
block|{
name|UNI_GIT_STD_DSMCC
init|=
literal|0x01
block|,
comment|/* DSM-CC */
name|UNI_GIT_STD_H245
init|=
literal|0x02
block|,
comment|/* H.245 */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|uni_git_type
block|{
name|UNI_GIT_TYPE_SESS
init|=
literal|0x01
block|,
comment|/* session id */
name|UNI_GIT_TYPE_RES
init|=
literal|0x02
block|,
comment|/* resource id */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|UNI_GIT_MAXSESS
init|=
literal|20
block|,
comment|/* max session value length */
name|UNI_GIT_MAXRES
init|=
literal|4
block|,
comment|/* max resource value length */
name|UNI_GIT_MAXVAL
init|=
literal|20
block|,
comment|/* the maximum of the above */
name|UNI_GIT_MAXSUB
init|=
literal|2
block|,
comment|/* maximum number of og. 6 */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_git
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_git_std
name|std
decl_stmt|;
comment|/* identifier related standard/application */
name|u_int
name|numsub
decl_stmt|;
struct|struct
block|{
name|enum
name|uni_git_type
name|type
decl_stmt|;
name|u_int
name|len
decl_stmt|;
name|u_char
name|val
index|[
name|UNI_GIT_MAXVAL
index|]
decl_stmt|;
block|}
name|sub
index|[
name|UNI_GIT_MAXSUB
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * End-to-end transit delay  */
end_comment

begin_enum
enum|enum
block|{
name|UNI_EETD_CTD_ID
init|=
literal|0x01
block|,
comment|/* cumulative transit delay */
name|UNI_EETD_MTD_ID
init|=
literal|0x03
block|,
comment|/* maximum transit delay */
name|UNI_EETD_NET_ID
init|=
literal|0x0a
block|,
comment|/* network generated */
name|UNI_EETD_PMTD_ID
init|=
literal|0x0b
block|,
comment|/* PNNI acceptable forward maximum ctd */
name|UNI_EETD_PCTD_ID
init|=
literal|0x11
block|,
comment|/* PNNI cumulative forward maximum ctd */
name|UNI_EETD_ANYMAX
init|=
literal|0xffff
block|,
name|UNI_EETD_MAXVAL
init|=
literal|0xffff
block|,
comment|/* maximum value */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_eetd
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
define|#
directive|define
name|UNI_EETD_CUM_P
value|0x0001
define|#
directive|define
name|UNI_EETD_MAX_P
value|0x0002
define|#
directive|define
name|UNI_EETD_NET_P
value|0x0004
comment|/* UNI4.0 9.1.2.1 */
define|#
directive|define
name|UNI_EETD_PMTD_P
value|0x0008
comment|/* PNNI1.0 6.4.5.24 */
define|#
directive|define
name|UNI_EETD_PCTD_P
value|0x0010
comment|/* PNNI1.0 6.4.5.24 */
name|u_int
name|cumulative
decl_stmt|;
name|u_int
name|maximum
decl_stmt|;
name|u_int
name|pmtd
decl_stmt|;
name|u_int
name|pctd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *   * Leaf-initiated-join call identifier  */
end_comment

begin_enum
enum|enum
name|uni_lij_idtype
block|{
name|UNI_LIJ_IDTYPE_ROOT
init|=
literal|0x0
block|,
comment|/* root created */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_lij_callid
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_lij_idtype
name|type
decl_stmt|;
name|u_int
name|callid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * LIJ parameters  */
end_comment

begin_enum
enum|enum
name|uni_lij_screen
block|{
name|UNI_LIJ_SCREEN_NETJOIN
init|=
literal|0x0
block|,
comment|/* without root notification */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_lij_param
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_lij_screen
name|screen
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * LIJ sequence number  */
end_comment

begin_struct
struct|struct
name|uni_ie_lij_seqno
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|u_int
name|seqno
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Locking/Non-locking shift not supported  */
end_comment

begin_struct
struct|struct
name|uni_ie_lshift
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|u_int
name|set
range|:
literal|3
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie_nlshift
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|u_int
name|set
range|:
literal|3
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Externded QoS information element  */
end_comment

begin_enum
enum|enum
block|{
name|UNI_EXQOS_FACC_ID
init|=
literal|0x94
block|,
name|UNI_EXQOS_BACC_ID
init|=
literal|0x95
block|,
name|UNI_EXQOS_FCUM_ID
init|=
literal|0x96
block|,
name|UNI_EXQOS_BCUM_ID
init|=
literal|0x97
block|,
name|UNI_EXQOS_FCLR_ID
init|=
literal|0xa2
block|,
name|UNI_EXQOS_BCLR_ID
init|=
literal|0xa3
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|uni_exqos_origin
block|{
name|UNI_EXQOS_USER
init|=
literal|0
block|,
name|UNI_EXQOS_NET
init|=
literal|1
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|UNI_EXQOS_ANY_CDV
init|=
literal|0xffffff
block|,
name|UNI_EXQOS_ANY_CLR
init|=
literal|0xff
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_exqos
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
define|#
directive|define
name|UNI_EXQOS_FACC_P
value|0x0001
define|#
directive|define
name|UNI_EXQOS_BACC_P
value|0x0002
define|#
directive|define
name|UNI_EXQOS_FCUM_P
value|0x0004
define|#
directive|define
name|UNI_EXQOS_BCUM_P
value|0x0008
define|#
directive|define
name|UNI_EXQOS_FCLR_P
value|0x0010
define|#
directive|define
name|UNI_EXQOS_BCLR_P
value|0x0020
name|enum
name|uni_exqos_origin
name|origin
decl_stmt|;
name|u_int
name|facc
decl_stmt|;
name|u_int
name|bacc
decl_stmt|;
name|u_int
name|fcum
decl_stmt|;
name|u_int
name|bcum
decl_stmt|;
name|u_int
name|fclr
decl_stmt|;
name|u_int
name|bclr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Additional ABR parameters  * ABR setup parameters  */
end_comment

begin_enum
enum|enum
block|{
name|UNI_ABRADD_FADD_ID
init|=
literal|0xc2
block|,
name|UNI_ABRADD_BADD_ID
init|=
literal|0xc3
block|,
name|UNI_ABRSETUP_FICR_ID
init|=
literal|0xc2
block|,
name|UNI_ABRSETUP_BICR_ID
init|=
literal|0xc3
block|,
name|UNI_ABRSETUP_FTBE_ID
init|=
literal|0xc4
block|,
name|UNI_ABRSETUP_BTBE_ID
init|=
literal|0xc5
block|,
name|UNI_ABRSETUP_RMFRT_ID
init|=
literal|0xc6
block|,
name|UNI_ABRSETUP_FRIF_ID
init|=
literal|0xc8
block|,
name|UNI_ABRSETUP_BRIF_ID
init|=
literal|0xc9
block|,
name|UNI_ABRSETUP_FRDF_ID
init|=
literal|0xca
block|,
name|UNI_ABRSETUP_BRDF_ID
init|=
literal|0xcb
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_abr_rec
block|{
name|u_int
name|present
decl_stmt|;
define|#
directive|define
name|UNI_ABR_REC_NRM_P
value|0x80000000
define|#
directive|define
name|UNI_ABR_REC_TRM_P
value|0x40000000
define|#
directive|define
name|UNI_ABR_REC_CDF_P
value|0x20000000
define|#
directive|define
name|UNI_ABR_REC_ADTF_P
value|0x10000000
name|u_int
name|nrm
range|:
literal|3
decl_stmt|;
name|u_int
name|trm
range|:
literal|3
decl_stmt|;
name|u_int
name|cdf
range|:
literal|3
decl_stmt|;
name|u_int
name|adtf
range|:
literal|10
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie_abradd
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|struct
name|uni_abr_rec
name|fwd
decl_stmt|,
name|bwd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie_abrsetup
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
define|#
directive|define
name|UNI_ABRSETUP_FICR_P
value|0x0001
define|#
directive|define
name|UNI_ABRSETUP_BICR_P
value|0x0002
define|#
directive|define
name|UNI_ABRSETUP_FTBE_P
value|0x0004
define|#
directive|define
name|UNI_ABRSETUP_BTBE_P
value|0x0008
define|#
directive|define
name|UNI_ABRSETUP_FRIF_P
value|0x0010
define|#
directive|define
name|UNI_ABRSETUP_BRIF_P
value|0x0020
define|#
directive|define
name|UNI_ABRSETUP_FRDF_P
value|0x0040
define|#
directive|define
name|UNI_ABRSETUP_BRDF_P
value|0x0080
define|#
directive|define
name|UNI_ABRSETUP_RMFRT_P
value|0x0100
name|u_int
name|ficr
decl_stmt|,
name|bicr
decl_stmt|;
name|u_int
name|ftbe
decl_stmt|,
name|btbe
decl_stmt|;
name|u_int
name|rmfrt
decl_stmt|;
name|u_int
name|frif
decl_stmt|,
name|brif
decl_stmt|;
name|u_int
name|frdf
decl_stmt|,
name|brdf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Connection scope information element  */
end_comment

begin_enum
enum|enum
name|uni_cscope
block|{
name|UNI_CSCOPE_ORG
init|=
literal|0x01
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|UNI_CSCOPE_ORG_LOC
init|=
literal|0x01
block|,
name|UNI_CSCOPE_ORG_LOC_P1
init|=
literal|0x02
block|,
name|UNI_CSCOPE_ORG_LOC_P2
init|=
literal|0x03
block|,
name|UNI_CSCOPE_ORG_SITE_M1
init|=
literal|0x04
block|,
name|UNI_CSCOPE_ORG_SITE
init|=
literal|0x05
block|,
name|UNI_CSCOPE_ORG_SITE_P1
init|=
literal|0x06
block|,
name|UNI_CSCOPE_ORG_ORG_M1
init|=
literal|0x07
block|,
name|UNI_CSCOPE_ORG_ORG
init|=
literal|0x08
block|,
name|UNI_CSCOPE_ORG_ORG_P1
init|=
literal|0x09
block|,
name|UNI_CSCOPE_ORG_COMM_M1
init|=
literal|0x0a
block|,
name|UNI_CSCOPE_ORG_COMM
init|=
literal|0x0b
block|,
name|UNI_CSCOPE_ORG_COMM_P1
init|=
literal|0x0c
block|,
name|UNI_CSCOPE_ORG_REG
init|=
literal|0x0d
block|,
name|UNI_CSCOPE_ORG_INTER
init|=
literal|0x0e
block|,
name|UNI_CSCOPE_ORG_GLOBAL
init|=
literal|0x0f
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_cscope
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_cscope
name|type
decl_stmt|;
name|u_int
name|scope
range|:
literal|8
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * Connection scope information element  */
end_comment

begin_enum
enum|enum
name|uni_report
block|{
name|UNI_REPORT_MODCONF
init|=
literal|0x01
block|,
name|UNI_REPORT_CLOCK
init|=
literal|0x02
block|,
name|UNI_REPORT_EEAVAIL
init|=
literal|0x04
block|,
name|UNI_REPORT_EEREQ
init|=
literal|0x05
block|,
name|UNI_REPORT_EECOMPL
init|=
literal|0x06
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_report
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|enum
name|uni_report
name|report
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * PNNI Designated transit list information element  */
end_comment

begin_enum
enum|enum
block|{
name|UNI_DTL_LOGNP
init|=
literal|0x01
block|,
name|UNI_DTL_LOGNP_SIZE
init|=
literal|27
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_dtl
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
name|u_int
name|ptr
range|:
literal|16
decl_stmt|;
name|u_int
name|num
decl_stmt|;
struct|struct
block|{
name|u_char
name|node_level
decl_stmt|;
name|u_char
name|node_id
index|[
literal|21
index|]
decl_stmt|;
name|u_int
name|port_id
decl_stmt|;
block|}
name|dtl
index|[
name|UNI_DTL_MAXNUM
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * PNNI Crankback information element  */
end_comment

begin_enum
enum|enum
name|uni_crankback
block|{
name|UNI_CRANKBACK_IF
init|=
literal|0x02
block|,
name|UNI_CRANKBACK_NODE
init|=
literal|0x03
block|,
name|UNI_CRANKBACK_LINK
init|=
literal|0x04
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|UNI_CAUSE_NXNODE_UNREACH
init|=
literal|128
block|,
name|UNI_CAUSE_DTL_NOT_MY_ID
init|=
literal|160
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_crankback
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
define|#
directive|define
name|UNI_CRANKBACK_TOP_P
value|0x0001
define|#
directive|define
name|UNI_CRANKBACK_TOPX_P
value|0x0002
define|#
directive|define
name|UNI_CRANKBACK_QOS_P
value|0x0004
name|u_int
name|level
range|:
literal|8
decl_stmt|;
name|enum
name|uni_crankback
name|type
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_char
name|level
decl_stmt|;
name|u_char
name|id
index|[
literal|21
index|]
decl_stmt|;
block|}
name|node
struct|;
struct|struct
block|{
name|u_char
name|plevel
decl_stmt|;
name|u_char
name|pid
index|[
literal|21
index|]
decl_stmt|;
name|u_int
name|port
decl_stmt|;
name|u_char
name|slevel
decl_stmt|;
name|u_char
name|sid
index|[
literal|21
index|]
decl_stmt|;
block|}
name|link
struct|;
block|}
name|id
union|;
name|u_int
name|cause
range|:
literal|8
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u_int
name|dir
range|:
literal|8
decl_stmt|;
name|u_int
name|port
decl_stmt|;
name|u_int
name|avcr
decl_stmt|;
name|u_int
name|crm
decl_stmt|;
name|u_int
name|vf
decl_stmt|;
block|}
name|top
struct|;
struct|struct
block|{
name|u_int
name|ctd
range|:
literal|1
decl_stmt|;
name|u_int
name|cdv
range|:
literal|1
decl_stmt|;
name|u_int
name|clr
range|:
literal|1
decl_stmt|;
name|u_int
name|other
range|:
literal|1
decl_stmt|;
block|}
name|qos
struct|;
block|}
name|diag
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************  *  * PNNI Call_ing/called party soft PVPC/PVCC information element  */
end_comment

begin_enum
enum|enum
name|uni_soft_sel
block|{
name|UNI_SOFT_SEL_ANY
init|=
literal|0x00
block|,
name|UNI_SOFT_SEL_REQ
init|=
literal|0x02
block|,
name|UNI_SOFT_SEL_ASS
init|=
literal|0x04
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|uni_ie_calling_soft
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
define|#
directive|define
name|UNI_CALLING_SOFT_VCI_P
value|0x0001
name|u_int
name|vpi
range|:
literal|12
decl_stmt|;
name|u_int
name|vci
range|:
literal|16
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie_called_soft
block|{
name|struct
name|uni_iehdr
name|h
decl_stmt|;
define|#
directive|define
name|UNI_CALLED_SOFT_VPI_P
value|0x0001
define|#
directive|define
name|UNI_CALLED_SOFT_VCI_P
value|0x0002
name|enum
name|uni_soft_sel
name|sel
decl_stmt|;
name|u_int
name|vpi
range|:
literal|12
decl_stmt|;
name|u_int
name|vci
range|:
literal|16
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<netnatm/msg/uni_ie.h>
end_include

begin_include
include|#
directive|include
file|<netnatm/msg/uni_msg.h>
end_include

begin_struct
struct|struct
name|uni_all
block|{
name|enum
name|uni_msgtype
name|mtype
decl_stmt|;
name|union
name|uni_msgall
name|u
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_ie
block|{
name|enum
name|uni_ietype
name|ietype
decl_stmt|;
name|union
name|uni_ieall
name|u
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

