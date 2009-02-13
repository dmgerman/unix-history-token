begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$OpenBSD: hifn7751var.h,v 1.42 2002/04/08 17:49:42 jason Exp $	*/
end_comment

begin_comment
comment|/*-  * Invertex AEON / Hifn 7751 driver  * Copyright (c) 1999 Invertex Inc. All rights reserved.  * Copyright (c) 1999 Theo de Raadt  * Copyright (c) 2000-2001 Network Security Technologies, Inc.  *			http://www.netsec.net  *  * Please send any comments, feedback, bug-fixes, or feature requests to  * software@invertex.com.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Effort sponsored in part by the Defense Advanced Research Projects  * Agency (DARPA) and Air Force Research Laboratory, Air Force  * Materiel Command, USAF, under agreement number F30602-01-2-0537.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HIFN7751VAR_H__
end_ifndef

begin_define
define|#
directive|define
name|__HIFN7751VAR_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Some configurable values for the driver.  By default command+result  * descriptor rings are the same size.  The src+dst descriptor rings  * are sized at 3.5x the number of potential commands.  Slower parts  * (e.g. 7951) tend to run out of src descriptors; faster parts (7811)  * src+cmd/result descriptors.  It's not clear that increasing the size  * of the descriptor rings helps performance significantly as other  * factors tend to come into play (e.g. copying misaligned packets).  */
end_comment

begin_define
define|#
directive|define
name|HIFN_D_CMD_RSIZE
value|24
end_define

begin_comment
comment|/* command descriptors */
end_comment

begin_define
define|#
directive|define
name|HIFN_D_SRC_RSIZE
value|((HIFN_D_CMD_RSIZE * 7) / 2)
end_define

begin_comment
comment|/* source descriptors */
end_comment

begin_define
define|#
directive|define
name|HIFN_D_RES_RSIZE
value|HIFN_D_CMD_RSIZE
end_define

begin_comment
comment|/* result descriptors */
end_comment

begin_define
define|#
directive|define
name|HIFN_D_DST_RSIZE
value|HIFN_D_SRC_RSIZE
end_define

begin_comment
comment|/* destination descriptors */
end_comment

begin_comment
comment|/*  *  Length values for cryptography  */
end_comment

begin_define
define|#
directive|define
name|HIFN_DES_KEY_LENGTH
value|8
end_define

begin_define
define|#
directive|define
name|HIFN_3DES_KEY_LENGTH
value|24
end_define

begin_define
define|#
directive|define
name|HIFN_MAX_CRYPT_KEY_LENGTH
value|HIFN_3DES_KEY_LENGTH
end_define

begin_define
define|#
directive|define
name|HIFN_IV_LENGTH
value|8
end_define

begin_define
define|#
directive|define
name|HIFN_AES_IV_LENGTH
value|16
end_define

begin_define
define|#
directive|define
name|HIFN_MAX_IV_LENGTH
value|HIFN_AES_IV_LENGTH
end_define

begin_comment
comment|/*  *  Length values for authentication  */
end_comment

begin_define
define|#
directive|define
name|HIFN_MAC_KEY_LENGTH
value|64
end_define

begin_define
define|#
directive|define
name|HIFN_MD5_LENGTH
value|16
end_define

begin_define
define|#
directive|define
name|HIFN_SHA1_LENGTH
value|20
end_define

begin_define
define|#
directive|define
name|HIFN_MAC_TRUNC_LENGTH
value|12
end_define

begin_define
define|#
directive|define
name|MAX_SCATTER
value|64
end_define

begin_comment
comment|/*  * Data structure to hold all 4 rings and any other ring related data.  */
end_comment

begin_struct
struct|struct
name|hifn_dma
block|{
comment|/* 	 *  Descriptor rings.  We add +1 to the size to accomidate the 	 *  jump descriptor. 	 */
name|struct
name|hifn_desc
name|cmdr
index|[
name|HIFN_D_CMD_RSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|hifn_desc
name|srcr
index|[
name|HIFN_D_SRC_RSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|hifn_desc
name|dstr
index|[
name|HIFN_D_DST_RSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|hifn_desc
name|resr
index|[
name|HIFN_D_RES_RSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|hifn_command
modifier|*
name|hifn_commands
index|[
name|HIFN_D_RES_RSIZE
index|]
decl_stmt|;
name|u_char
name|command_bufs
index|[
name|HIFN_D_CMD_RSIZE
index|]
index|[
name|HIFN_MAX_COMMAND
index|]
decl_stmt|;
name|u_char
name|result_bufs
index|[
name|HIFN_D_CMD_RSIZE
index|]
index|[
name|HIFN_MAX_RESULT
index|]
decl_stmt|;
name|u_int32_t
name|slop
index|[
name|HIFN_D_CMD_RSIZE
index|]
decl_stmt|;
name|u_int64_t
name|test_src
decl_stmt|,
name|test_dst
decl_stmt|;
comment|/* 	 *  Our current positions for insertion and removal from the desriptor 	 *  rings.  	 */
name|int
name|cmdi
decl_stmt|,
name|srci
decl_stmt|,
name|dsti
decl_stmt|,
name|resi
decl_stmt|;
specifier|volatile
name|int
name|cmdu
decl_stmt|,
name|srcu
decl_stmt|,
name|dstu
decl_stmt|,
name|resu
decl_stmt|;
name|int
name|cmdk
decl_stmt|,
name|srck
decl_stmt|,
name|dstk
decl_stmt|,
name|resk
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hifn_session
block|{
name|int
name|hs_used
decl_stmt|;
name|int
name|hs_mlen
decl_stmt|;
name|u_int8_t
name|hs_iv
index|[
name|HIFN_MAX_IV_LENGTH
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HIFN_RING_SYNC
parameter_list|(
name|sc
parameter_list|,
name|r
parameter_list|,
name|i
parameter_list|,
name|f
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->sc_dmat, (sc)->sc_dmamap, (f))
end_define

begin_define
define|#
directive|define
name|HIFN_CMDR_SYNC
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|,
name|f
parameter_list|)
value|HIFN_RING_SYNC((sc), cmdr, (i), (f))
end_define

begin_define
define|#
directive|define
name|HIFN_RESR_SYNC
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|,
name|f
parameter_list|)
value|HIFN_RING_SYNC((sc), resr, (i), (f))
end_define

begin_define
define|#
directive|define
name|HIFN_SRCR_SYNC
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|,
name|f
parameter_list|)
value|HIFN_RING_SYNC((sc), srcr, (i), (f))
end_define

begin_define
define|#
directive|define
name|HIFN_DSTR_SYNC
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|,
name|f
parameter_list|)
value|HIFN_RING_SYNC((sc), dstr, (i), (f))
end_define

begin_define
define|#
directive|define
name|HIFN_CMD_SYNC
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|,
name|f
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->sc_dmat, (sc)->sc_dmamap, (f))
end_define

begin_define
define|#
directive|define
name|HIFN_RES_SYNC
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|,
name|f
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->sc_dmat, (sc)->sc_dmamap, (f))
end_define

begin_comment
comment|/*  * Holds data specific to a single HIFN board.  */
end_comment

begin_struct
struct|struct
name|hifn_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* device backpointer */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* per-instance lock */
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
comment|/* parent DMA tag decriptor */
name|struct
name|resource
modifier|*
name|sc_bar0res
decl_stmt|;
name|bus_space_handle_t
name|sc_sh0
decl_stmt|;
comment|/* bar0 bus space handle */
name|bus_space_tag_t
name|sc_st0
decl_stmt|;
comment|/* bar0 bus space tag */
name|bus_size_t
name|sc_bar0_lastreg
decl_stmt|;
comment|/* bar0 last reg written */
name|struct
name|resource
modifier|*
name|sc_bar1res
decl_stmt|;
name|bus_space_handle_t
name|sc_sh1
decl_stmt|;
comment|/* bar1 bus space handle */
name|bus_space_tag_t
name|sc_st1
decl_stmt|;
comment|/* bar1 bus space tag */
name|bus_size_t
name|sc_bar1_lastreg
decl_stmt|;
comment|/* bar1 last reg written */
name|struct
name|resource
modifier|*
name|sc_irq
decl_stmt|;
name|void
modifier|*
name|sc_intrhand
decl_stmt|;
comment|/* interrupt handle */
name|u_int32_t
name|sc_dmaier
decl_stmt|;
name|u_int32_t
name|sc_drammodel
decl_stmt|;
comment|/* 1=dram, 0=sram */
name|u_int32_t
name|sc_pllconfig
decl_stmt|;
comment|/* 7954/7955/7956 PLL config */
name|struct
name|hifn_dma
modifier|*
name|sc_dma
decl_stmt|;
name|bus_dmamap_t
name|sc_dmamap
decl_stmt|;
name|bus_dma_segment_t
name|sc_dmasegs
index|[
literal|1
index|]
decl_stmt|;
name|bus_addr_t
name|sc_dma_physaddr
decl_stmt|;
comment|/* physical address of sc_dma */
name|int
name|sc_dmansegs
decl_stmt|;
name|int32_t
name|sc_cid
decl_stmt|;
name|int
name|sc_maxses
decl_stmt|;
name|int
name|sc_nsessions
decl_stmt|;
name|struct
name|hifn_session
modifier|*
name|sc_sessions
decl_stmt|;
name|int
name|sc_ramsize
decl_stmt|;
name|int
name|sc_flags
decl_stmt|;
define|#
directive|define
name|HIFN_HAS_RNG
value|0x1
comment|/* includes random number generator */
define|#
directive|define
name|HIFN_HAS_PUBLIC
value|0x2
comment|/* includes public key support */
define|#
directive|define
name|HIFN_HAS_AES
value|0x4
comment|/* includes AES support */
define|#
directive|define
name|HIFN_IS_7811
value|0x8
comment|/* Hifn 7811 part */
define|#
directive|define
name|HIFN_IS_7956
value|0x10
comment|/* Hifn 7956/7955 don't have SDRAM */
name|struct
name|callout
name|sc_rngto
decl_stmt|;
comment|/* for polling RNG */
name|struct
name|callout
name|sc_tickto
decl_stmt|;
comment|/* for managing DMA */
name|int
name|sc_rngfirst
decl_stmt|;
name|int
name|sc_rnghz
decl_stmt|;
comment|/* RNG polling frequency */
name|struct
name|rndtest_state
modifier|*
name|sc_rndtest
decl_stmt|;
comment|/* RNG test state */
name|void
function_decl|(
modifier|*
name|sc_harvest
function_decl|)
parameter_list|(
name|struct
name|rndtest_state
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|int
name|sc_c_busy
decl_stmt|;
comment|/* command ring busy */
name|int
name|sc_s_busy
decl_stmt|;
comment|/* source data ring busy */
name|int
name|sc_d_busy
decl_stmt|;
comment|/* destination data ring busy */
name|int
name|sc_r_busy
decl_stmt|;
comment|/* result ring busy */
name|int
name|sc_active
decl_stmt|;
comment|/* for initial countdown */
name|int
name|sc_needwakeup
decl_stmt|;
comment|/* ops q'd wating on resources */
name|int
name|sc_curbatch
decl_stmt|;
comment|/* # ops submitted w/o int */
name|int
name|sc_suspended
decl_stmt|;
ifdef|#
directive|ifdef
name|HIFN_VULCANDEV
name|struct
name|cdev
modifier|*
name|sc_pkdev
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HIFN_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|HIFN_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_comment
comment|/*  *  hifn_command_t  *  *  This is the control structure used to pass commands to hifn_encrypt().  *  *  flags  *  -----  *  Flags is the bitwise "or" values for command configuration.  A single  *  encrypt direction needs to be set:  *  *	HIFN_ENCODE or HIFN_DECODE  *  *  To use cryptography, a single crypto algorithm must be included:  *  *	HIFN_CRYPT_3DES or HIFN_CRYPT_DES  *  *  To use authentication is used, a single MAC algorithm must be included:  *  *	HIFN_MAC_MD5 or HIFN_MAC_SHA1  *  *  By default MD5 uses a 16 byte hash and SHA-1 uses a 20 byte hash.  *  If the value below is set, hash values are truncated or assumed  *  truncated to 12 bytes:  *  *	HIFN_MAC_TRUNC  *  *  Keys for encryption and authentication can be sent as part of a command,  *  or the last key value used with a particular session can be retrieved  *  and used again if either of these flags are not specified.  *  *	HIFN_CRYPT_NEW_KEY, HIFN_MAC_NEW_KEY  *  *  session_num  *  -----------  *  A number between 0 and 2048 (for DRAM models) or a number between   *  0 and 768 (for SRAM models).  Those who don't want to use session  *  numbers should leave value at zero and send a new crypt key and/or  *  new MAC key on every command.  If you use session numbers and  *  don't send a key with a command, the last key sent for that same  *  session number will be used.  *  *  Warning:  Using session numbers and multiboard at the same time  *            is currently broken.  *  *  mbuf  *  ----  *  Either fill in the mbuf pointer and npa=0 or  *	 fill packp[] and packl[] and set npa to> 0  *   *  mac_header_skip  *  ---------------  *  The number of bytes of the source_buf that are skipped over before  *  authentication begins.  This must be a number between 0 and 2^16-1  *  and can be used by IPsec implementers to skip over IP headers.  *  *** Value ignored if authentication not used ***  *  *  crypt_header_skip  *  -----------------  *  The number of bytes of the source_buf that are skipped over before  *  the cryptographic operation begins.  This must be a number between 0  *  and 2^16-1.  For IPsec, this number will always be 8 bytes larger  *  than the auth_header_skip (to skip over the ESP header).  *  *** Value ignored if cryptography not used ***  *  */
end_comment

begin_struct
struct|struct
name|hifn_operand
block|{
union|union
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|struct
name|uio
modifier|*
name|io
decl_stmt|;
block|}
name|u
union|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|bus_size_t
name|mapsize
decl_stmt|;
name|int
name|nsegs
decl_stmt|;
name|bus_dma_segment_t
name|segs
index|[
name|MAX_SCATTER
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hifn_command
block|{
name|u_int16_t
name|session_num
decl_stmt|;
name|u_int16_t
name|base_masks
decl_stmt|,
name|cry_masks
decl_stmt|,
name|mac_masks
decl_stmt|;
name|u_int8_t
name|iv
index|[
name|HIFN_MAX_IV_LENGTH
index|]
decl_stmt|,
modifier|*
name|ck
decl_stmt|,
name|mac
index|[
name|HIFN_MAC_KEY_LENGTH
index|]
decl_stmt|;
name|int
name|cklen
decl_stmt|;
name|int
name|sloplen
decl_stmt|,
name|slopidx
decl_stmt|;
name|struct
name|hifn_operand
name|src
decl_stmt|;
name|struct
name|hifn_operand
name|dst
decl_stmt|;
name|struct
name|hifn_softc
modifier|*
name|softc
decl_stmt|;
name|struct
name|cryptop
modifier|*
name|crp
decl_stmt|;
name|struct
name|cryptodesc
modifier|*
name|enccrd
decl_stmt|,
modifier|*
name|maccrd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|src_m
value|src.u.m
end_define

begin_define
define|#
directive|define
name|src_io
value|src.u.io
end_define

begin_define
define|#
directive|define
name|src_map
value|src.map
end_define

begin_define
define|#
directive|define
name|src_mapsize
value|src.mapsize
end_define

begin_define
define|#
directive|define
name|src_segs
value|src.segs
end_define

begin_define
define|#
directive|define
name|src_nsegs
value|src.nsegs
end_define

begin_define
define|#
directive|define
name|dst_m
value|dst.u.m
end_define

begin_define
define|#
directive|define
name|dst_io
value|dst.u.io
end_define

begin_define
define|#
directive|define
name|dst_map
value|dst.map
end_define

begin_define
define|#
directive|define
name|dst_mapsize
value|dst.mapsize
end_define

begin_define
define|#
directive|define
name|dst_segs
value|dst.segs
end_define

begin_define
define|#
directive|define
name|dst_nsegs
value|dst.nsegs
end_define

begin_comment
comment|/*  *  Return values for hifn_crypto()  */
end_comment

begin_define
define|#
directive|define
name|HIFN_CRYPTO_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|HIFN_CRYPTO_BAD_INPUT
value|(-1)
end_define

begin_define
define|#
directive|define
name|HIFN_CRYPTO_RINGS_FULL
value|(-2)
end_define

begin_comment
comment|/**************************************************************************  *  *  Function:  hifn_crypto  *  *  Purpose:   Called by external drivers to begin an encryption on the  *             HIFN board.  *  *  Blocking/Non-blocking Issues  *  ============================  *  The driver cannot block in hifn_crypto (no calls to tsleep) currently.  *  hifn_crypto() returns HIFN_CRYPTO_RINGS_FULL if there is not enough  *  room in any of the rings for the request to proceed.  *  *  Return Values  *  =============  *  0 for success, negative values on error  *  *  Defines for negative error codes are:  *    *    HIFN_CRYPTO_BAD_INPUT  :  The passed in command had invalid settings.  *    HIFN_CRYPTO_RINGS_FULL :  All DMA rings were full and non-blocking  *                              behaviour was requested.  *  *************************************************************************/
end_comment

begin_comment
comment|/*  * Convert back and forth from 'sid' to 'card' and 'session'  */
end_comment

begin_define
define|#
directive|define
name|HIFN_CARD
parameter_list|(
name|sid
parameter_list|)
value|(((sid)& 0xf0000000)>> 28)
end_define

begin_define
define|#
directive|define
name|HIFN_SESSION
parameter_list|(
name|sid
parameter_list|)
value|((sid)& 0x000007ff)
end_define

begin_define
define|#
directive|define
name|HIFN_SID
parameter_list|(
name|crd
parameter_list|,
name|ses
parameter_list|)
value|(((crd)<< 28) | ((ses)& 0x7ff))
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
name|hifn_stats
block|{
name|u_int64_t
name|hst_ibytes
decl_stmt|;
name|u_int64_t
name|hst_obytes
decl_stmt|;
name|u_int32_t
name|hst_ipackets
decl_stmt|;
name|u_int32_t
name|hst_opackets
decl_stmt|;
name|u_int32_t
name|hst_invalid
decl_stmt|;
name|u_int32_t
name|hst_nomem
decl_stmt|;
comment|/* malloc or one of hst_nomem_* */
name|u_int32_t
name|hst_abort
decl_stmt|;
name|u_int32_t
name|hst_noirq
decl_stmt|;
comment|/* IRQ for no reason */
name|u_int32_t
name|hst_totbatch
decl_stmt|;
comment|/* ops submitted w/o interrupt */
name|u_int32_t
name|hst_maxbatch
decl_stmt|;
comment|/* max ops submitted together */
name|u_int32_t
name|hst_unaligned
decl_stmt|;
comment|/* unaligned src caused copy */
comment|/* 	 * The following divides hst_nomem into more specific buckets. 	 */
name|u_int32_t
name|hst_nomem_map
decl_stmt|;
comment|/* bus_dmamap_create failed */
name|u_int32_t
name|hst_nomem_load
decl_stmt|;
comment|/* bus_dmamap_load_* failed */
name|u_int32_t
name|hst_nomem_mbuf
decl_stmt|;
comment|/* MGET* failed */
name|u_int32_t
name|hst_nomem_mcl
decl_stmt|;
comment|/* MCLGET* failed */
name|u_int32_t
name|hst_nomem_cr
decl_stmt|;
comment|/* out of command/result descriptor */
name|u_int32_t
name|hst_nomem_sd
decl_stmt|;
comment|/* out of src/dst descriptors */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HIFN7751VAR_H__ */
end_comment

end_unit

