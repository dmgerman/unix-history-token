begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * Copyright (c) 2005-2006 Atheros Communications, Inc.  * All rights reserved.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AH_REGDOMAIN_H__
end_ifndef

begin_define
define|#
directive|define
name|__AH_REGDOMAIN_H__
end_define

begin_comment
comment|/*   * BMLEN defines the size of the bitmask used to hold frequency  * band specifications.  Note this must agree with the BM macro  * definition that's used to setup initializers.  See also further  * comments below.  */
end_comment

begin_define
define|#
directive|define
name|BMLEN
value|2
end_define

begin_comment
comment|/* 2 x 64 bits in each channel bitmask */
end_comment

begin_typedef
typedef|typedef
name|uint64_t
name|chanbmask_t
index|[
name|BMLEN
index|]
typedef|;
end_typedef

begin_comment
comment|/*  * The following describe the bit masks for different passive scan  * capability/requirements per regdomain.  */
end_comment

begin_define
define|#
directive|define
name|NO_PSCAN
value|0x0ULL
end_define

begin_comment
comment|/* NB: must be zero */
end_comment

begin_define
define|#
directive|define
name|PSCAN_FCC
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_FCC_T
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_ETSI
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_MKK1
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_MKK2
value|0x0000000000000010ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_MKKA
value|0x0000000000000020ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_MKKA_G
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_ETSIA
value|0x0000000000000080ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_ETSIB
value|0x0000000000000100ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_ETSIC
value|0x0000000000000200ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_WWR
value|0x0000000000000400ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_MKKA1
value|0x0000000000000800ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_MKKA1_G
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_MKKA2
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_MKKA2_G
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_MKK3
value|0x0000000000008000ULL
end_define

begin_define
define|#
directive|define
name|PSCAN_DEFER
value|0x7FFFFFFFFFFFFFFFULL
end_define

begin_define
define|#
directive|define
name|IS_ECM_CHAN
value|0x8000000000000000ULL
end_define

begin_comment
comment|/*  * The following are flags for different requirements per reg domain.  * These requirements are either inhereted from the reg domain pair or  * from the unitary reg domain if the reg domain pair flags value is 0  */
end_comment

begin_enum
enum|enum
block|{
name|NO_REQ
init|=
literal|0x00000000
block|,
comment|/* NB: must be zero */
name|DISALLOW_ADHOC_11A
init|=
literal|0x00000001
block|,
comment|/* adhoc not allowed in 5GHz */
name|DISALLOW_ADHOC_11A_TURB
init|=
literal|0x00000002
block|,
comment|/* not allowed w/ 5GHz turbo */
name|NEED_NFC
init|=
literal|0x00000004
block|,
comment|/* need noise floor check */
name|ADHOC_PER_11D
init|=
literal|0x00000008
block|,
comment|/* must receive 11d beacon */
name|LIMIT_FRAME_4MS
init|=
literal|0x00000020
block|,
comment|/* 4msec tx burst limit */
name|NO_HOSTAP
init|=
literal|0x00000040
block|,
comment|/* No HOSTAP mode opereation */
block|}
enum|;
end_enum

begin_comment
comment|/* Bit masks for DFS per regdomain */
end_comment

begin_enum
enum|enum
block|{
name|NO_DFS
init|=
literal|0x0000000000000000ULL
block|,
comment|/* NB: must be zero */
name|DFS_FCC3
init|=
literal|0x0000000000000001ULL
block|,
name|DFS_ETSI
init|=
literal|0x0000000000000002ULL
block|,
name|DFS_MKK4
init|=
literal|0x0000000000000004ULL
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* conformance test limits */
name|FCC
init|=
literal|0x10
block|,
name|MKK
init|=
literal|0x40
block|,
name|ETSI
init|=
literal|0x30
block|, }
enum|;
end_enum

begin_comment
comment|/*  * THE following table is the mapping of regdomain pairs specified by  * an 8 bit regdomain value to the individual unitary reg domains  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|regDomainPair
block|{
name|HAL_REG_DOMAIN
name|regDmnEnum
decl_stmt|;
comment|/* 16 bit reg domain pair */
name|HAL_REG_DOMAIN
name|regDmn5GHz
decl_stmt|;
comment|/* 5GHz reg domain */
name|HAL_REG_DOMAIN
name|regDmn2GHz
decl_stmt|;
comment|/* 2GHz reg domain */
name|uint32_t
name|flags5GHz
decl_stmt|;
comment|/* Requirements flags (AdHoc 					   disallow, noise floor cal needed, 					   etc) */
name|uint32_t
name|flags2GHz
decl_stmt|;
comment|/* Requirements flags (AdHoc 					   disallow, noise floor cal needed, 					   etc) */
name|uint64_t
name|pscanMask
decl_stmt|;
comment|/* Passive Scan flags which 					   can override unitary domain 					   passive scan flags.  This 					   value is used as a mask on 					   the unitary flags*/
name|uint16_t
name|singleCC
decl_stmt|;
comment|/* Country code of single country if 					   a one-on-one mapping exists */
block|}
name|REG_DMN_PAIR_MAPPING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|HAL_CTRY_CODE
name|countryCode
decl_stmt|;
name|HAL_REG_DOMAIN
name|regDmnEnum
decl_stmt|;
block|}
name|COUNTRY_CODE_TO_ENUM_RD
typedef|;
end_typedef

begin_comment
comment|/*  * Frequency band collections are defined using bitmasks.  Each bit  * in a mask is the index of an entry in one of the following tables.  * Bitmasks are BMLEN*64 bits so if a table grows beyond that the bit  * vectors must be enlarged or the tables split somehow (e.g. split  * 1/2 and 1/4 rate channels into a separate table).  *  * Beware of ordering; the indices are defined relative to the preceding  * entry so if things get off there will be confusion.  A good way to  * check the indices is to collect them in a switch statement in a stub  * function so the compiler checks for duplicates.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|lowChannel
decl_stmt|;
comment|/* Low channel center in MHz */
name|uint16_t
name|highChannel
decl_stmt|;
comment|/* High Channel center in MHz */
name|uint8_t
name|powerDfs
decl_stmt|;
comment|/* Max power (dBm) for channel 					   range when using DFS */
name|uint8_t
name|antennaMax
decl_stmt|;
comment|/* Max allowed antenna gain */
name|uint8_t
name|channelBW
decl_stmt|;
comment|/* Bandwidth of the channel */
name|uint8_t
name|channelSep
decl_stmt|;
comment|/* Channel separation within 					   the band */
name|uint64_t
name|useDfs
decl_stmt|;
comment|/* Use DFS in the RegDomain 					   if corresponding bit is set */
name|uint64_t
name|usePassScan
decl_stmt|;
comment|/* Use Passive Scan in the RegDomain 					   if corresponding bit is set */
block|}
name|REG_DMN_FREQ_BAND
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|regDomain
block|{
name|uint16_t
name|regDmnEnum
decl_stmt|;
comment|/* value from EnumRd table */
name|uint8_t
name|conformanceTestLimit
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* Requirement flags (AdHoc disallow, 					   noise floor cal needed, etc) */
name|uint64_t
name|dfsMask
decl_stmt|;
comment|/* DFS bitmask for 5Ghz tables */
name|uint64_t
name|pscan
decl_stmt|;
comment|/* Bitmask for passive scan */
name|chanbmask_t
name|chan11a
decl_stmt|;
comment|/* 11a channels */
name|chanbmask_t
name|chan11a_turbo
decl_stmt|;
comment|/* 11a static turbo channels */
name|chanbmask_t
name|chan11a_dyn_turbo
decl_stmt|;
comment|/* 11a dynamic turbo channels */
name|chanbmask_t
name|chan11a_half
decl_stmt|;
comment|/* 11a 1/2 width channels */
name|chanbmask_t
name|chan11a_quarter
decl_stmt|;
comment|/* 11a 1/4 width channels */
name|chanbmask_t
name|chan11b
decl_stmt|;
comment|/* 11b channels */
name|chanbmask_t
name|chan11g
decl_stmt|;
comment|/* 11g channels */
name|chanbmask_t
name|chan11g_turbo
decl_stmt|;
comment|/* 11g dynamic turbo channels */
name|chanbmask_t
name|chan11g_half
decl_stmt|;
comment|/* 11g 1/2 width channels */
name|chanbmask_t
name|chan11g_quarter
decl_stmt|;
comment|/* 11g 1/4 width channels */
block|}
name|REG_DOMAIN
typedef|;
end_typedef

begin_struct
struct|struct
name|cmode
block|{
name|u_int
name|mode
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

