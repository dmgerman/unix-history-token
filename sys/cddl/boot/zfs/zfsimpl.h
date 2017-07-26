begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 McAfee, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by Marshall  * Kirk McKusick and McAfee Research,, the Security Research Division of  * McAfee, Inc. under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as  * part of the DARPA CHATS research program  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2009 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_comment
comment|/*  * Copyright 2013 by Saso Kiselkov. All rights reserved.  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013 by Delphix. All rights reserved.  */
end_comment

begin_define
define|#
directive|define
name|MAXNAMELEN
value|256
end_define

begin_define
define|#
directive|define
name|_NOTE
parameter_list|(
name|s
parameter_list|)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|B_FALSE
block|,
name|B_TRUE
block|}
name|boolean_t
typedef|;
end_typedef

begin_comment
comment|/* CRC64 table */
end_comment

begin_define
define|#
directive|define
name|ZFS_CRC64_POLY
value|0xC96C5795D7870F42ULL
end_define

begin_comment
comment|/* ECMA-182, reflected form */
end_comment

begin_comment
comment|/*  * Macros for various sorts of alignment and rounding when the alignment  * is known to be a power of 2.  */
end_comment

begin_define
define|#
directive|define
name|P2ALIGN
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|((x)& -(align))
end_define

begin_define
define|#
directive|define
name|P2PHASE
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|((x)& ((align) - 1))
end_define

begin_define
define|#
directive|define
name|P2NPHASE
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|(-(x)& ((align) - 1))
end_define

begin_define
define|#
directive|define
name|P2ROUNDUP
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|(-(-(x)& -(align)))
end_define

begin_define
define|#
directive|define
name|P2END
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|)
value|(-(~(x)& -(align)))
end_define

begin_define
define|#
directive|define
name|P2PHASEUP
parameter_list|(
name|x
parameter_list|,
name|align
parameter_list|,
name|phase
parameter_list|)
value|((phase) - (((phase) - (x))& -(align)))
end_define

begin_define
define|#
directive|define
name|P2BOUNDARY
parameter_list|(
name|off
parameter_list|,
name|len
parameter_list|,
name|align
parameter_list|)
value|(((off) ^ ((off) + (len) - 1))> (align) - 1)
end_define

begin_comment
comment|/*  * General-purpose 32-bit and 64-bit bitfield encodings.  */
end_comment

begin_define
define|#
directive|define
name|BF32_DECODE
parameter_list|(
name|x
parameter_list|,
name|low
parameter_list|,
name|len
parameter_list|)
value|P2PHASE((x)>> (low), 1U<< (len))
end_define

begin_define
define|#
directive|define
name|BF64_DECODE
parameter_list|(
name|x
parameter_list|,
name|low
parameter_list|,
name|len
parameter_list|)
value|P2PHASE((x)>> (low), 1ULL<< (len))
end_define

begin_define
define|#
directive|define
name|BF32_ENCODE
parameter_list|(
name|x
parameter_list|,
name|low
parameter_list|,
name|len
parameter_list|)
value|(P2PHASE((x), 1U<< (len))<< (low))
end_define

begin_define
define|#
directive|define
name|BF64_ENCODE
parameter_list|(
name|x
parameter_list|,
name|low
parameter_list|,
name|len
parameter_list|)
value|(P2PHASE((x), 1ULL<< (len))<< (low))
end_define

begin_define
define|#
directive|define
name|BF32_GET
parameter_list|(
name|x
parameter_list|,
name|low
parameter_list|,
name|len
parameter_list|)
value|BF32_DECODE(x, low, len)
end_define

begin_define
define|#
directive|define
name|BF64_GET
parameter_list|(
name|x
parameter_list|,
name|low
parameter_list|,
name|len
parameter_list|)
value|BF64_DECODE(x, low, len)
end_define

begin_define
define|#
directive|define
name|BF32_SET
parameter_list|(
name|x
parameter_list|,
name|low
parameter_list|,
name|len
parameter_list|,
name|val
parameter_list|)
define|\
value|((x) ^= BF32_ENCODE((x>> low) ^ (val), low, len))
end_define

begin_define
define|#
directive|define
name|BF64_SET
parameter_list|(
name|x
parameter_list|,
name|low
parameter_list|,
name|len
parameter_list|,
name|val
parameter_list|)
define|\
value|((x) ^= BF64_ENCODE((x>> low) ^ (val), low, len))
end_define

begin_define
define|#
directive|define
name|BF32_GET_SB
parameter_list|(
name|x
parameter_list|,
name|low
parameter_list|,
name|len
parameter_list|,
name|shift
parameter_list|,
name|bias
parameter_list|)
define|\
value|((BF32_GET(x, low, len) + (bias))<< (shift))
end_define

begin_define
define|#
directive|define
name|BF64_GET_SB
parameter_list|(
name|x
parameter_list|,
name|low
parameter_list|,
name|len
parameter_list|,
name|shift
parameter_list|,
name|bias
parameter_list|)
define|\
value|((BF64_GET(x, low, len) + (bias))<< (shift))
end_define

begin_define
define|#
directive|define
name|BF32_SET_SB
parameter_list|(
name|x
parameter_list|,
name|low
parameter_list|,
name|len
parameter_list|,
name|shift
parameter_list|,
name|bias
parameter_list|,
name|val
parameter_list|)
define|\
value|BF32_SET(x, low, len, ((val)>> (shift)) - (bias))
end_define

begin_define
define|#
directive|define
name|BF64_SET_SB
parameter_list|(
name|x
parameter_list|,
name|low
parameter_list|,
name|len
parameter_list|,
name|shift
parameter_list|,
name|bias
parameter_list|,
name|val
parameter_list|)
define|\
value|BF64_SET(x, low, len, ((val)>> (shift)) - (bias))
end_define

begin_comment
comment|/*  * Macros to reverse byte order  */
end_comment

begin_define
define|#
directive|define
name|BSWAP_8
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_define
define|#
directive|define
name|BSWAP_16
parameter_list|(
name|x
parameter_list|)
value|((BSWAP_8(x)<< 8) | BSWAP_8((x)>> 8))
end_define

begin_define
define|#
directive|define
name|BSWAP_32
parameter_list|(
name|x
parameter_list|)
value|((BSWAP_16(x)<< 16) | BSWAP_16((x)>> 16))
end_define

begin_define
define|#
directive|define
name|BSWAP_64
parameter_list|(
name|x
parameter_list|)
value|((BSWAP_32(x)<< 32) | BSWAP_32((x)>> 32))
end_define

begin_comment
comment|/*  * Note: the boot loader can't actually read blocks larger than 128KB,  * due to lack of memory.  Therefore its SPA_MAXBLOCKSIZE is still 128KB.  */
end_comment

begin_define
define|#
directive|define
name|SPA_MINBLOCKSHIFT
value|9
end_define

begin_define
define|#
directive|define
name|SPA_MAXBLOCKSHIFT
value|17
end_define

begin_define
define|#
directive|define
name|SPA_MINBLOCKSIZE
value|(1ULL<< SPA_MINBLOCKSHIFT)
end_define

begin_define
define|#
directive|define
name|SPA_MAXBLOCKSIZE
value|(1ULL<< SPA_MAXBLOCKSHIFT)
end_define

begin_comment
comment|/*  * The DVA size encodings for LSIZE and PSIZE support blocks up to 32MB.  * The ASIZE encoding should be at least 64 times larger (6 more bits)  * to support up to 4-way RAID-Z mirror mode with worst-case gang block  * overhead, three DVAs per bp, plus one more bit in case we do anything  * else that expands the ASIZE.  */
end_comment

begin_define
define|#
directive|define
name|SPA_LSIZEBITS
value|16
end_define

begin_comment
comment|/* LSIZE up to 32M (2^16 * 512)	*/
end_comment

begin_define
define|#
directive|define
name|SPA_PSIZEBITS
value|16
end_define

begin_comment
comment|/* PSIZE up to 32M (2^16 * 512)	*/
end_comment

begin_define
define|#
directive|define
name|SPA_ASIZEBITS
value|24
end_define

begin_comment
comment|/* ASIZE up to 64 times larger	*/
end_comment

begin_comment
comment|/*  * All SPA data is represented by 128-bit data virtual addresses (DVAs).  * The members of the dva_t should be considered opaque outside the SPA.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dva
block|{
name|uint64_t
name|dva_word
index|[
literal|2
index|]
decl_stmt|;
block|}
name|dva_t
typedef|;
end_typedef

begin_comment
comment|/*  * Each block has a 256-bit checksum -- strong enough for cryptographic hashes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|zio_cksum
block|{
name|uint64_t
name|zc_word
index|[
literal|4
index|]
decl_stmt|;
block|}
name|zio_cksum_t
typedef|;
end_typedef

begin_comment
comment|/*  * Each block is described by its DVAs, time of birth, checksum, etc.  * The word-by-word, bit-by-bit layout of the blkptr is as follows:  *  *	64	56	48	40	32	24	16	8	0  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 0	|		vdev1		| GRID  |	  ASIZE		|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 1	|G|			 offset1				|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 2	|		vdev2		| GRID  |	  ASIZE		|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 3	|G|			 offset2				|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 4	|		vdev3		| GRID  |	  ASIZE		|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 5	|G|			 offset3				|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 6	|BDX|lvl| type	| cksum |E| comp|    PSIZE	|     LSIZE	|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 7	|			padding					|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 8	|			padding					|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 9	|			physical birth txg			|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * a	|			logical birth txg			|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * b	|			fill count				|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * c	|			checksum[0]				|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * d	|			checksum[1]				|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * e	|			checksum[2]				|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * f	|			checksum[3]				|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  *  * Legend:  *  * vdev		virtual device ID  * offset	offset into virtual device  * LSIZE	logical size  * PSIZE	physical size (after compression)  * ASIZE	allocated size (including RAID-Z parity and gang block headers)  * GRID		RAID-Z layout information (reserved for future use)  * cksum	checksum function  * comp		compression function  * G		gang block indicator  * B		byteorder (endianness)  * D		dedup  * X		encryption (on version 30, which is not supported)  * E		blkptr_t contains embedded data (see below)  * lvl		level of indirection  * type		DMU object type  * phys birth	txg of block allocation; zero if same as logical birth txg  * log. birth	transaction group in which the block was logically born  * fill count	number of non-zero blocks under this bp  * checksum[4]	256-bit checksum of the data this bp describes  */
end_comment

begin_comment
comment|/*  * "Embedded" blkptr_t's don't actually point to a block, instead they  * have a data payload embedded in the blkptr_t itself.  See the comment  * in blkptr.c for more details.  *  * The blkptr_t is laid out as follows:  *  *	64	56	48	40	32	24	16	8	0  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 0	|      payload                                                  |  * 1	|      payload                                                  |  * 2	|      payload                                                  |  * 3	|      payload                                                  |  * 4	|      payload                                                  |  * 5	|      payload                                                  |  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 6	|BDX|lvl| type	| etype |E| comp| PSIZE|              LSIZE	|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * 7	|      payload                                                  |  * 8	|      payload                                                  |  * 9	|      payload                                                  |  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * a	|			logical birth txg			|  *	+-------+-------+-------+-------+-------+-------+-------+-------+  * b	|      payload                                                  |  * c	|      payload                                                  |  * d	|      payload                                                  |  * e	|      payload                                                  |  * f	|      payload                                                  |  *	+-------+-------+-------+-------+-------+-------+-------+-------+  *  * Legend:  *  * payload		contains the embedded data  * B (byteorder)	byteorder (endianness)  * D (dedup)		padding (set to zero)  * X			encryption (set to zero; see above)  * E (embedded)		set to one  * lvl			indirection level  * type			DMU object type  * etype		how to interpret embedded data (BP_EMBEDDED_TYPE_*)  * comp			compression function of payload  * PSIZE		size of payload after compression, in bytes  * LSIZE		logical size of payload, in bytes  *			note that 25 bits is enough to store the largest  *			"normal" BP's LSIZE (2^16 * 2^9) in bytes  * log. birth		transaction group in which the block was logically born  *  * Note that LSIZE and PSIZE are stored in bytes, whereas for non-embedded  * bp's they are stored in units of SPA_MINBLOCKSHIFT.  * Generally, the generic BP_GET_*() macros can be used on embedded BP's.  * The B, D, X, lvl, type, and comp fields are stored the same as with normal  * BP's so the BP_SET_* macros can be used with them.  etype, PSIZE, LSIZE must  * be set with the BPE_SET_* macros.  BP_SET_EMBEDDED() should be called before  * other macros, as they assert that they are only used on BP's of the correct  * "embedded-ness".  */
end_comment

begin_define
define|#
directive|define
name|BPE_GET_ETYPE
parameter_list|(
name|bp
parameter_list|)
define|\
value|(ASSERT(BP_IS_EMBEDDED(bp)), \ 	BF64_GET((bp)->blk_prop, 40, 8))
end_define

begin_define
define|#
directive|define
name|BPE_SET_ETYPE
parameter_list|(
name|bp
parameter_list|,
name|t
parameter_list|)
value|do { \ 	ASSERT(BP_IS_EMBEDDED(bp)); \ 	BF64_SET((bp)->blk_prop, 40, 8, t); \ _NOTE(CONSTCOND) } while (0)
end_define

begin_define
define|#
directive|define
name|BPE_GET_LSIZE
parameter_list|(
name|bp
parameter_list|)
define|\
value|(ASSERT(BP_IS_EMBEDDED(bp)), \ 	BF64_GET_SB((bp)->blk_prop, 0, 25, 0, 1))
end_define

begin_define
define|#
directive|define
name|BPE_SET_LSIZE
parameter_list|(
name|bp
parameter_list|,
name|x
parameter_list|)
value|do { \ 	ASSERT(BP_IS_EMBEDDED(bp)); \ 	BF64_SET_SB((bp)->blk_prop, 0, 25, 0, 1, x); \ _NOTE(CONSTCOND) } while (0)
end_define

begin_define
define|#
directive|define
name|BPE_GET_PSIZE
parameter_list|(
name|bp
parameter_list|)
define|\
value|(ASSERT(BP_IS_EMBEDDED(bp)), \ 	BF64_GET_SB((bp)->blk_prop, 25, 7, 0, 1))
end_define

begin_define
define|#
directive|define
name|BPE_SET_PSIZE
parameter_list|(
name|bp
parameter_list|,
name|x
parameter_list|)
value|do { \ 	ASSERT(BP_IS_EMBEDDED(bp)); \ 	BF64_SET_SB((bp)->blk_prop, 25, 7, 0, 1, x); \ _NOTE(CONSTCOND) } while (0)
end_define

begin_typedef
typedef|typedef
enum|enum
name|bp_embedded_type
block|{
name|BP_EMBEDDED_TYPE_DATA
block|,
name|BP_EMBEDDED_TYPE_RESERVED
block|,
comment|/* Reserved for an unintegrated feature. */
name|NUM_BP_EMBEDDED_TYPES
init|=
name|BP_EMBEDDED_TYPE_RESERVED
block|}
name|bp_embedded_type_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BPE_NUM_WORDS
value|14
end_define

begin_define
define|#
directive|define
name|BPE_PAYLOAD_SIZE
value|(BPE_NUM_WORDS * sizeof (uint64_t))
end_define

begin_define
define|#
directive|define
name|BPE_IS_PAYLOADWORD
parameter_list|(
name|bp
parameter_list|,
name|wp
parameter_list|)
define|\
value|((wp) !=&(bp)->blk_prop&& (wp) !=&(bp)->blk_birth)
end_define

begin_define
define|#
directive|define
name|SPA_BLKPTRSHIFT
value|7
end_define

begin_comment
comment|/* blkptr_t is 128 bytes	*/
end_comment

begin_define
define|#
directive|define
name|SPA_DVAS_PER_BP
value|3
end_define

begin_comment
comment|/* Number of DVAs in a bp	*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|blkptr
block|{
name|dva_t
name|blk_dva
index|[
name|SPA_DVAS_PER_BP
index|]
decl_stmt|;
comment|/* Data Virtual Addresses */
name|uint64_t
name|blk_prop
decl_stmt|;
comment|/* size, compression, type, etc	    */
name|uint64_t
name|blk_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Extra space for the future	    */
name|uint64_t
name|blk_phys_birth
decl_stmt|;
comment|/* txg when block was allocated	    */
name|uint64_t
name|blk_birth
decl_stmt|;
comment|/* transaction group at birth	    */
name|uint64_t
name|blk_fill
decl_stmt|;
comment|/* fill count			    */
name|zio_cksum_t
name|blk_cksum
decl_stmt|;
comment|/* 256-bit checksum		    */
block|}
name|blkptr_t
typedef|;
end_typedef

begin_comment
comment|/*  * Macros to get and set fields in a bp or DVA.  */
end_comment

begin_define
define|#
directive|define
name|DVA_GET_ASIZE
parameter_list|(
name|dva
parameter_list|)
define|\
value|BF64_GET_SB((dva)->dva_word[0], 0, SPA_ASIZEBITS, SPA_MINBLOCKSHIFT, 0)
end_define

begin_define
define|#
directive|define
name|DVA_SET_ASIZE
parameter_list|(
name|dva
parameter_list|,
name|x
parameter_list|)
define|\
value|BF64_SET_SB((dva)->dva_word[0], 0, SPA_ASIZEBITS, \ 	SPA_MINBLOCKSHIFT, 0, x)
end_define

begin_define
define|#
directive|define
name|DVA_GET_GRID
parameter_list|(
name|dva
parameter_list|)
value|BF64_GET((dva)->dva_word[0], 24, 8)
end_define

begin_define
define|#
directive|define
name|DVA_SET_GRID
parameter_list|(
name|dva
parameter_list|,
name|x
parameter_list|)
value|BF64_SET((dva)->dva_word[0], 24, 8, x)
end_define

begin_define
define|#
directive|define
name|DVA_GET_VDEV
parameter_list|(
name|dva
parameter_list|)
value|BF64_GET((dva)->dva_word[0], 32, 32)
end_define

begin_define
define|#
directive|define
name|DVA_SET_VDEV
parameter_list|(
name|dva
parameter_list|,
name|x
parameter_list|)
value|BF64_SET((dva)->dva_word[0], 32, 32, x)
end_define

begin_define
define|#
directive|define
name|DVA_GET_OFFSET
parameter_list|(
name|dva
parameter_list|)
define|\
value|BF64_GET_SB((dva)->dva_word[1], 0, 63, SPA_MINBLOCKSHIFT, 0)
end_define

begin_define
define|#
directive|define
name|DVA_SET_OFFSET
parameter_list|(
name|dva
parameter_list|,
name|x
parameter_list|)
define|\
value|BF64_SET_SB((dva)->dva_word[1], 0, 63, SPA_MINBLOCKSHIFT, 0, x)
end_define

begin_define
define|#
directive|define
name|DVA_GET_GANG
parameter_list|(
name|dva
parameter_list|)
value|BF64_GET((dva)->dva_word[1], 63, 1)
end_define

begin_define
define|#
directive|define
name|DVA_SET_GANG
parameter_list|(
name|dva
parameter_list|,
name|x
parameter_list|)
value|BF64_SET((dva)->dva_word[1], 63, 1, x)
end_define

begin_define
define|#
directive|define
name|BP_GET_LSIZE
parameter_list|(
name|bp
parameter_list|)
define|\
value|(BP_IS_EMBEDDED(bp) ?	\ 	(BPE_GET_ETYPE(bp) == BP_EMBEDDED_TYPE_DATA ? BPE_GET_LSIZE(bp) : 0): \ 	BF64_GET_SB((bp)->blk_prop, 0, SPA_LSIZEBITS, SPA_MINBLOCKSHIFT, 1))
end_define

begin_define
define|#
directive|define
name|BP_SET_LSIZE
parameter_list|(
name|bp
parameter_list|,
name|x
parameter_list|)
value|do { \ 	ASSERT(!BP_IS_EMBEDDED(bp)); \ 	BF64_SET_SB((bp)->blk_prop, \ 	    0, SPA_LSIZEBITS, SPA_MINBLOCKSHIFT, 1, x); \ _NOTE(CONSTCOND) } while (0)
end_define

begin_define
define|#
directive|define
name|BP_GET_PSIZE
parameter_list|(
name|bp
parameter_list|)
define|\
value|BF64_GET_SB((bp)->blk_prop, 16, SPA_LSIZEBITS, SPA_MINBLOCKSHIFT, 1)
end_define

begin_define
define|#
directive|define
name|BP_SET_PSIZE
parameter_list|(
name|bp
parameter_list|,
name|x
parameter_list|)
define|\
value|BF64_SET_SB((bp)->blk_prop, 16, SPA_LSIZEBITS, SPA_MINBLOCKSHIFT, 1, x)
end_define

begin_define
define|#
directive|define
name|BP_GET_COMPRESS
parameter_list|(
name|bp
parameter_list|)
value|BF64_GET((bp)->blk_prop, 32, 7)
end_define

begin_define
define|#
directive|define
name|BP_SET_COMPRESS
parameter_list|(
name|bp
parameter_list|,
name|x
parameter_list|)
value|BF64_SET((bp)->blk_prop, 32, 7, x)
end_define

begin_define
define|#
directive|define
name|BP_GET_CHECKSUM
parameter_list|(
name|bp
parameter_list|)
value|BF64_GET((bp)->blk_prop, 40, 8)
end_define

begin_define
define|#
directive|define
name|BP_SET_CHECKSUM
parameter_list|(
name|bp
parameter_list|,
name|x
parameter_list|)
value|BF64_SET((bp)->blk_prop, 40, 8, x)
end_define

begin_define
define|#
directive|define
name|BP_GET_TYPE
parameter_list|(
name|bp
parameter_list|)
value|BF64_GET((bp)->blk_prop, 48, 8)
end_define

begin_define
define|#
directive|define
name|BP_SET_TYPE
parameter_list|(
name|bp
parameter_list|,
name|x
parameter_list|)
value|BF64_SET((bp)->blk_prop, 48, 8, x)
end_define

begin_define
define|#
directive|define
name|BP_GET_LEVEL
parameter_list|(
name|bp
parameter_list|)
value|BF64_GET((bp)->blk_prop, 56, 5)
end_define

begin_define
define|#
directive|define
name|BP_SET_LEVEL
parameter_list|(
name|bp
parameter_list|,
name|x
parameter_list|)
value|BF64_SET((bp)->blk_prop, 56, 5, x)
end_define

begin_define
define|#
directive|define
name|BP_IS_EMBEDDED
parameter_list|(
name|bp
parameter_list|)
value|BF64_GET((bp)->blk_prop, 39, 1)
end_define

begin_define
define|#
directive|define
name|BP_GET_DEDUP
parameter_list|(
name|bp
parameter_list|)
value|BF64_GET((bp)->blk_prop, 62, 1)
end_define

begin_define
define|#
directive|define
name|BP_SET_DEDUP
parameter_list|(
name|bp
parameter_list|,
name|x
parameter_list|)
value|BF64_SET((bp)->blk_prop, 62, 1, x)
end_define

begin_define
define|#
directive|define
name|BP_GET_BYTEORDER
parameter_list|(
name|bp
parameter_list|)
value|BF64_GET((bp)->blk_prop, 63, 1)
end_define

begin_define
define|#
directive|define
name|BP_SET_BYTEORDER
parameter_list|(
name|bp
parameter_list|,
name|x
parameter_list|)
value|BF64_SET((bp)->blk_prop, 63, 1, x)
end_define

begin_define
define|#
directive|define
name|BP_PHYSICAL_BIRTH
parameter_list|(
name|bp
parameter_list|)
define|\
value|((bp)->blk_phys_birth ? (bp)->blk_phys_birth : (bp)->blk_birth)
end_define

begin_define
define|#
directive|define
name|BP_GET_ASIZE
parameter_list|(
name|bp
parameter_list|)
define|\
value|(DVA_GET_ASIZE(&(bp)->blk_dva[0]) + DVA_GET_ASIZE(&(bp)->blk_dva[1]) + \ 		DVA_GET_ASIZE(&(bp)->blk_dva[2]))
end_define

begin_define
define|#
directive|define
name|BP_GET_UCSIZE
parameter_list|(
name|bp
parameter_list|)
define|\
value|((BP_GET_LEVEL(bp)> 0 || dmu_ot[BP_GET_TYPE(bp)].ot_metadata) ? \ 	BP_GET_PSIZE(bp) : BP_GET_LSIZE(bp));
end_define

begin_define
define|#
directive|define
name|BP_GET_NDVAS
parameter_list|(
name|bp
parameter_list|)
define|\
value|(!!DVA_GET_ASIZE(&(bp)->blk_dva[0]) + \ 	!!DVA_GET_ASIZE(&(bp)->blk_dva[1]) + \ 	!!DVA_GET_ASIZE(&(bp)->blk_dva[2]))
end_define

begin_define
define|#
directive|define
name|DVA_EQUAL
parameter_list|(
name|dva1
parameter_list|,
name|dva2
parameter_list|)
define|\
value|((dva1)->dva_word[1] == (dva2)->dva_word[1]&& \ 	(dva1)->dva_word[0] == (dva2)->dva_word[0])
end_define

begin_define
define|#
directive|define
name|ZIO_CHECKSUM_EQUAL
parameter_list|(
name|zc1
parameter_list|,
name|zc2
parameter_list|)
define|\
value|(0 == (((zc1).zc_word[0] - (zc2).zc_word[0]) | \ 	((zc1).zc_word[1] - (zc2).zc_word[1]) | \ 	((zc1).zc_word[2] - (zc2).zc_word[2]) | \ 	((zc1).zc_word[3] - (zc2).zc_word[3])))
end_define

begin_define
define|#
directive|define
name|DVA_IS_VALID
parameter_list|(
name|dva
parameter_list|)
value|(DVA_GET_ASIZE(dva) != 0)
end_define

begin_define
define|#
directive|define
name|ZIO_SET_CHECKSUM
parameter_list|(
name|zcp
parameter_list|,
name|w0
parameter_list|,
name|w1
parameter_list|,
name|w2
parameter_list|,
name|w3
parameter_list|)
define|\
value|{						\ 	(zcp)->zc_word[0] = w0;			\ 	(zcp)->zc_word[1] = w1;			\ 	(zcp)->zc_word[2] = w2;			\ 	(zcp)->zc_word[3] = w3;			\ }
end_define

begin_define
define|#
directive|define
name|BP_IDENTITY
parameter_list|(
name|bp
parameter_list|)
value|(&(bp)->blk_dva[0])
end_define

begin_define
define|#
directive|define
name|BP_IS_GANG
parameter_list|(
name|bp
parameter_list|)
value|DVA_GET_GANG(BP_IDENTITY(bp))
end_define

begin_define
define|#
directive|define
name|DVA_IS_EMPTY
parameter_list|(
name|dva
parameter_list|)
value|((dva)->dva_word[0] == 0ULL&&  \ 	(dva)->dva_word[1] == 0ULL)
end_define

begin_define
define|#
directive|define
name|BP_IS_HOLE
parameter_list|(
name|bp
parameter_list|)
value|DVA_IS_EMPTY(BP_IDENTITY(bp))
end_define

begin_define
define|#
directive|define
name|BP_IS_OLDER
parameter_list|(
name|bp
parameter_list|,
name|txg
parameter_list|)
value|(!BP_IS_HOLE(bp)&& (bp)->blk_birth< (txg))
end_define

begin_define
define|#
directive|define
name|BP_ZERO
parameter_list|(
name|bp
parameter_list|)
define|\
value|{						\ 	(bp)->blk_dva[0].dva_word[0] = 0;	\ 	(bp)->blk_dva[0].dva_word[1] = 0;	\ 	(bp)->blk_dva[1].dva_word[0] = 0;	\ 	(bp)->blk_dva[1].dva_word[1] = 0;	\ 	(bp)->blk_dva[2].dva_word[0] = 0;	\ 	(bp)->blk_dva[2].dva_word[1] = 0;	\ 	(bp)->blk_prop = 0;			\ 	(bp)->blk_pad[0] = 0;			\ 	(bp)->blk_pad[1] = 0;			\ 	(bp)->blk_phys_birth = 0;		\ 	(bp)->blk_birth = 0;			\ 	(bp)->blk_fill = 0;			\ 	ZIO_SET_CHECKSUM(&(bp)->blk_cksum, 0, 0, 0, 0);	\ }
end_define

begin_define
define|#
directive|define
name|BPE_NUM_WORDS
value|14
end_define

begin_define
define|#
directive|define
name|BPE_PAYLOAD_SIZE
value|(BPE_NUM_WORDS * sizeof (uint64_t))
end_define

begin_define
define|#
directive|define
name|BPE_IS_PAYLOADWORD
parameter_list|(
name|bp
parameter_list|,
name|wp
parameter_list|)
define|\
value|((wp) !=&(bp)->blk_prop&& (wp) !=&(bp)->blk_birth)
end_define

begin_comment
comment|/*  * Embedded checksum  */
end_comment

begin_define
define|#
directive|define
name|ZEC_MAGIC
value|0x210da7ab10c7a11ULL
end_define

begin_typedef
typedef|typedef
struct|struct
name|zio_eck
block|{
name|uint64_t
name|zec_magic
decl_stmt|;
comment|/* for validation, endianness	*/
name|zio_cksum_t
name|zec_cksum
decl_stmt|;
comment|/* 256-bit checksum		*/
block|}
name|zio_eck_t
typedef|;
end_typedef

begin_comment
comment|/*  * Gang block headers are self-checksumming and contain an array  * of block pointers.  */
end_comment

begin_define
define|#
directive|define
name|SPA_GANGBLOCKSIZE
value|SPA_MINBLOCKSIZE
end_define

begin_define
define|#
directive|define
name|SPA_GBH_NBLKPTRS
value|((SPA_GANGBLOCKSIZE - \ 	sizeof (zio_eck_t)) / sizeof (blkptr_t))
end_define

begin_define
define|#
directive|define
name|SPA_GBH_FILLER
value|((SPA_GANGBLOCKSIZE - \ 	sizeof (zio_eck_t) - \ 	(SPA_GBH_NBLKPTRS * sizeof (blkptr_t))) /\ 	sizeof (uint64_t))
end_define

begin_typedef
typedef|typedef
struct|struct
name|zio_gbh
block|{
name|blkptr_t
name|zg_blkptr
index|[
name|SPA_GBH_NBLKPTRS
index|]
decl_stmt|;
name|uint64_t
name|zg_filler
index|[
name|SPA_GBH_FILLER
index|]
decl_stmt|;
name|zio_eck_t
name|zg_tail
decl_stmt|;
block|}
name|zio_gbh_phys_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VDEV_RAIDZ_MAXPARITY
value|3
end_define

begin_define
define|#
directive|define
name|VDEV_PAD_SIZE
value|(8<< 10)
end_define

begin_comment
comment|/* 2 padding areas (vl_pad1 and vl_pad2) to skip */
end_comment

begin_define
define|#
directive|define
name|VDEV_SKIP_SIZE
value|VDEV_PAD_SIZE * 2
end_define

begin_define
define|#
directive|define
name|VDEV_PHYS_SIZE
value|(112<< 10)
end_define

begin_define
define|#
directive|define
name|VDEV_UBERBLOCK_RING
value|(128<< 10)
end_define

begin_define
define|#
directive|define
name|VDEV_UBERBLOCK_SHIFT
parameter_list|(
name|vd
parameter_list|)
define|\
value|MAX((vd)->v_top->v_ashift, UBERBLOCK_SHIFT)
end_define

begin_define
define|#
directive|define
name|VDEV_UBERBLOCK_COUNT
parameter_list|(
name|vd
parameter_list|)
define|\
value|(VDEV_UBERBLOCK_RING>> VDEV_UBERBLOCK_SHIFT(vd))
end_define

begin_define
define|#
directive|define
name|VDEV_UBERBLOCK_OFFSET
parameter_list|(
name|vd
parameter_list|,
name|n
parameter_list|)
define|\
value|offsetof(vdev_label_t, vl_uberblock[(n)<< VDEV_UBERBLOCK_SHIFT(vd)])
end_define

begin_define
define|#
directive|define
name|VDEV_UBERBLOCK_SIZE
parameter_list|(
name|vd
parameter_list|)
value|(1ULL<< VDEV_UBERBLOCK_SHIFT(vd))
end_define

begin_typedef
typedef|typedef
struct|struct
name|vdev_phys
block|{
name|char
name|vp_nvlist
index|[
name|VDEV_PHYS_SIZE
operator|-
sizeof|sizeof
argument_list|(
name|zio_eck_t
argument_list|)
index|]
decl_stmt|;
name|zio_eck_t
name|vp_zbt
decl_stmt|;
block|}
name|vdev_phys_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vdev_label
block|{
name|char
name|vl_pad1
index|[
name|VDEV_PAD_SIZE
index|]
decl_stmt|;
comment|/*  8K  */
name|char
name|vl_pad2
index|[
name|VDEV_PAD_SIZE
index|]
decl_stmt|;
comment|/*  8K  */
name|vdev_phys_t
name|vl_vdev_phys
decl_stmt|;
comment|/* 112K	*/
name|char
name|vl_uberblock
index|[
name|VDEV_UBERBLOCK_RING
index|]
decl_stmt|;
comment|/* 128K	*/
block|}
name|vdev_label_t
typedef|;
end_typedef

begin_comment
comment|/* 256K total */
end_comment

begin_comment
comment|/*  * vdev_dirty() flags  */
end_comment

begin_define
define|#
directive|define
name|VDD_METASLAB
value|0x01
end_define

begin_define
define|#
directive|define
name|VDD_DTL
value|0x02
end_define

begin_comment
comment|/*  * Size and offset of embedded boot loader region on each label.  * The total size of the first two labels plus the boot area is 4MB.  */
end_comment

begin_define
define|#
directive|define
name|VDEV_BOOT_OFFSET
value|(2 * sizeof (vdev_label_t))
end_define

begin_define
define|#
directive|define
name|VDEV_BOOT_SIZE
value|(7ULL<< 19)
end_define

begin_comment
comment|/* 3.5M	*/
end_comment

begin_comment
comment|/*  * Size of label regions at the start and end of each leaf device.  */
end_comment

begin_define
define|#
directive|define
name|VDEV_LABEL_START_SIZE
value|(2 * sizeof (vdev_label_t) + VDEV_BOOT_SIZE)
end_define

begin_define
define|#
directive|define
name|VDEV_LABEL_END_SIZE
value|(2 * sizeof (vdev_label_t))
end_define

begin_define
define|#
directive|define
name|VDEV_LABELS
value|4
end_define

begin_enum
enum|enum
name|zio_checksum
block|{
name|ZIO_CHECKSUM_INHERIT
init|=
literal|0
block|,
name|ZIO_CHECKSUM_ON
block|,
name|ZIO_CHECKSUM_OFF
block|,
name|ZIO_CHECKSUM_LABEL
block|,
name|ZIO_CHECKSUM_GANG_HEADER
block|,
name|ZIO_CHECKSUM_ZILOG
block|,
name|ZIO_CHECKSUM_FLETCHER_2
block|,
name|ZIO_CHECKSUM_FLETCHER_4
block|,
name|ZIO_CHECKSUM_SHA256
block|,
name|ZIO_CHECKSUM_ZILOG2
block|,
name|ZIO_CHECKSUM_FUNCTIONS
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|ZIO_CHECKSUM_ON_VALUE
value|ZIO_CHECKSUM_FLETCHER_4
end_define

begin_define
define|#
directive|define
name|ZIO_CHECKSUM_DEFAULT
value|ZIO_CHECKSUM_ON
end_define

begin_enum
enum|enum
name|zio_compress
block|{
name|ZIO_COMPRESS_INHERIT
init|=
literal|0
block|,
name|ZIO_COMPRESS_ON
block|,
name|ZIO_COMPRESS_OFF
block|,
name|ZIO_COMPRESS_LZJB
block|,
name|ZIO_COMPRESS_EMPTY
block|,
name|ZIO_COMPRESS_GZIP_1
block|,
name|ZIO_COMPRESS_GZIP_2
block|,
name|ZIO_COMPRESS_GZIP_3
block|,
name|ZIO_COMPRESS_GZIP_4
block|,
name|ZIO_COMPRESS_GZIP_5
block|,
name|ZIO_COMPRESS_GZIP_6
block|,
name|ZIO_COMPRESS_GZIP_7
block|,
name|ZIO_COMPRESS_GZIP_8
block|,
name|ZIO_COMPRESS_GZIP_9
block|,
name|ZIO_COMPRESS_ZLE
block|,
name|ZIO_COMPRESS_LZ4
block|,
name|ZIO_COMPRESS_FUNCTIONS
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|ZIO_COMPRESS_ON_VALUE
value|ZIO_COMPRESS_LZJB
end_define

begin_define
define|#
directive|define
name|ZIO_COMPRESS_DEFAULT
value|ZIO_COMPRESS_OFF
end_define

begin_comment
comment|/* nvlist pack encoding */
end_comment

begin_define
define|#
directive|define
name|NV_ENCODE_NATIVE
value|0
end_define

begin_define
define|#
directive|define
name|NV_ENCODE_XDR
value|1
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|DATA_TYPE_UNKNOWN
init|=
literal|0
block|,
name|DATA_TYPE_BOOLEAN
block|,
name|DATA_TYPE_BYTE
block|,
name|DATA_TYPE_INT16
block|,
name|DATA_TYPE_UINT16
block|,
name|DATA_TYPE_INT32
block|,
name|DATA_TYPE_UINT32
block|,
name|DATA_TYPE_INT64
block|,
name|DATA_TYPE_UINT64
block|,
name|DATA_TYPE_STRING
block|,
name|DATA_TYPE_BYTE_ARRAY
block|,
name|DATA_TYPE_INT16_ARRAY
block|,
name|DATA_TYPE_UINT16_ARRAY
block|,
name|DATA_TYPE_INT32_ARRAY
block|,
name|DATA_TYPE_UINT32_ARRAY
block|,
name|DATA_TYPE_INT64_ARRAY
block|,
name|DATA_TYPE_UINT64_ARRAY
block|,
name|DATA_TYPE_STRING_ARRAY
block|,
name|DATA_TYPE_HRTIME
block|,
name|DATA_TYPE_NVLIST
block|,
name|DATA_TYPE_NVLIST_ARRAY
block|,
name|DATA_TYPE_BOOLEAN_VALUE
block|,
name|DATA_TYPE_INT8
block|,
name|DATA_TYPE_UINT8
block|,
name|DATA_TYPE_BOOLEAN_ARRAY
block|,
name|DATA_TYPE_INT8_ARRAY
block|,
name|DATA_TYPE_UINT8_ARRAY
block|}
name|data_type_t
typedef|;
end_typedef

begin_comment
comment|/*  * On-disk version number.  */
end_comment

begin_define
define|#
directive|define
name|SPA_VERSION_1
value|1ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_2
value|2ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_3
value|3ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_4
value|4ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_5
value|5ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_6
value|6ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_7
value|7ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_8
value|8ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_9
value|9ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_10
value|10ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_11
value|11ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_12
value|12ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_13
value|13ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_14
value|14ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_15
value|15ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_16
value|16ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_17
value|17ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_18
value|18ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_19
value|19ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_20
value|20ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_21
value|21ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_22
value|22ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_23
value|23ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_24
value|24ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_25
value|25ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_26
value|26ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_27
value|27ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_28
value|28ULL
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_5000
value|5000ULL
end_define

begin_comment
comment|/*  * When bumping up SPA_VERSION, make sure GRUB ZFS understands the on-disk  * format change. Go to usr/src/grub/grub-0.97/stage2/{zfs-include/, fsys_zfs*},  * and do the appropriate changes.  Also bump the version number in  * usr/src/grub/capability.  */
end_comment

begin_define
define|#
directive|define
name|SPA_VERSION
value|SPA_VERSION_5000
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_STRING
value|"5000"
end_define

begin_comment
comment|/*  * Symbolic names for the changes that caused a SPA_VERSION switch.  * Used in the code when checking for presence or absence of a feature.  * Feel free to define multiple symbolic names for each version if there  * were multiple changes to on-disk structures during that version.  *  * NOTE: When checking the current SPA_VERSION in your code, be sure  *       to use spa_version() since it reports the version of the  *       last synced uberblock.  Checking the in-flight version can  *       be dangerous in some cases.  */
end_comment

begin_define
define|#
directive|define
name|SPA_VERSION_INITIAL
value|SPA_VERSION_1
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_DITTO_BLOCKS
value|SPA_VERSION_2
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_SPARES
value|SPA_VERSION_3
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_RAID6
value|SPA_VERSION_3
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_BPLIST_ACCOUNT
value|SPA_VERSION_3
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_RAIDZ_DEFLATE
value|SPA_VERSION_3
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_DNODE_BYTES
value|SPA_VERSION_3
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_ZPOOL_HISTORY
value|SPA_VERSION_4
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_GZIP_COMPRESSION
value|SPA_VERSION_5
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_BOOTFS
value|SPA_VERSION_6
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_SLOGS
value|SPA_VERSION_7
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_DELEGATED_PERMS
value|SPA_VERSION_8
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_FUID
value|SPA_VERSION_9
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_REFRESERVATION
value|SPA_VERSION_9
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_REFQUOTA
value|SPA_VERSION_9
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_UNIQUE_ACCURATE
value|SPA_VERSION_9
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_L2CACHE
value|SPA_VERSION_10
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_NEXT_CLONES
value|SPA_VERSION_11
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_ORIGIN
value|SPA_VERSION_11
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_DSL_SCRUB
value|SPA_VERSION_11
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_SNAP_PROPS
value|SPA_VERSION_12
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_USED_BREAKDOWN
value|SPA_VERSION_13
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_PASSTHROUGH_X
value|SPA_VERSION_14
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_USERSPACE
value|SPA_VERSION_15
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_STMF_PROP
value|SPA_VERSION_16
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_RAIDZ3
value|SPA_VERSION_17
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_USERREFS
value|SPA_VERSION_18
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_HOLES
value|SPA_VERSION_19
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_ZLE_COMPRESSION
value|SPA_VERSION_20
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_DEDUP
value|SPA_VERSION_21
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_RECVD_PROPS
value|SPA_VERSION_22
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_SLIM_ZIL
value|SPA_VERSION_23
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_SA
value|SPA_VERSION_24
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_SCAN
value|SPA_VERSION_25
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_DIR_CLONES
value|SPA_VERSION_26
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_DEADLISTS
value|SPA_VERSION_26
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_FAST_SNAP
value|SPA_VERSION_27
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_MULTI_REPLACE
value|SPA_VERSION_28
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_BEFORE_FEATURES
value|SPA_VERSION_28
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_FEATURES
value|SPA_VERSION_5000
end_define

begin_define
define|#
directive|define
name|SPA_VERSION_IS_SUPPORTED
parameter_list|(
name|v
parameter_list|)
define|\
value|(((v)>= SPA_VERSION_INITIAL&& (v)<= SPA_VERSION_BEFORE_FEATURES) || \ 	((v)>= SPA_VERSION_FEATURES&& (v)<= SPA_VERSION))
end_define

begin_comment
comment|/*  * The following are configuration names used in the nvlist describing a pool's  * configuration.  */
end_comment

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_VERSION
value|"version"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_POOL_NAME
value|"name"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_POOL_STATE
value|"state"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_POOL_TXG
value|"txg"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_POOL_GUID
value|"pool_guid"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_CREATE_TXG
value|"create_txg"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_TOP_GUID
value|"top_guid"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_VDEV_TREE
value|"vdev_tree"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_TYPE
value|"type"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_CHILDREN
value|"children"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_ID
value|"id"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_GUID
value|"guid"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_PATH
value|"path"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_DEVID
value|"devid"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_METASLAB_ARRAY
value|"metaslab_array"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_METASLAB_SHIFT
value|"metaslab_shift"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_ASHIFT
value|"ashift"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_ASIZE
value|"asize"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_DTL
value|"DTL"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_STATS
value|"stats"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_WHOLE_DISK
value|"whole_disk"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_ERRCOUNT
value|"error_count"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_NOT_PRESENT
value|"not_present"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_SPARES
value|"spares"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_IS_SPARE
value|"is_spare"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_NPARITY
value|"nparity"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_HOSTID
value|"hostid"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_HOSTNAME
value|"hostname"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_IS_LOG
value|"is_log"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_TIMESTAMP
value|"timestamp"
end_define

begin_comment
comment|/* not stored on disk */
end_comment

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_FEATURES_FOR_READ
value|"features_for_read"
end_define

begin_comment
comment|/*  * The persistent vdev state is stored as separate values rather than a single  * 'vdev_state' entry.  This is because a device can be in multiple states, such  * as offline and degraded.  */
end_comment

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_OFFLINE
value|"offline"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_FAULTED
value|"faulted"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_DEGRADED
value|"degraded"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_REMOVED
value|"removed"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_FRU
value|"fru"
end_define

begin_define
define|#
directive|define
name|ZPOOL_CONFIG_AUX_STATE
value|"aux_state"
end_define

begin_define
define|#
directive|define
name|VDEV_TYPE_ROOT
value|"root"
end_define

begin_define
define|#
directive|define
name|VDEV_TYPE_MIRROR
value|"mirror"
end_define

begin_define
define|#
directive|define
name|VDEV_TYPE_REPLACING
value|"replacing"
end_define

begin_define
define|#
directive|define
name|VDEV_TYPE_RAIDZ
value|"raidz"
end_define

begin_define
define|#
directive|define
name|VDEV_TYPE_DISK
value|"disk"
end_define

begin_define
define|#
directive|define
name|VDEV_TYPE_FILE
value|"file"
end_define

begin_define
define|#
directive|define
name|VDEV_TYPE_MISSING
value|"missing"
end_define

begin_define
define|#
directive|define
name|VDEV_TYPE_HOLE
value|"hole"
end_define

begin_define
define|#
directive|define
name|VDEV_TYPE_SPARE
value|"spare"
end_define

begin_define
define|#
directive|define
name|VDEV_TYPE_LOG
value|"log"
end_define

begin_define
define|#
directive|define
name|VDEV_TYPE_L2CACHE
value|"l2cache"
end_define

begin_comment
comment|/*  * This is needed in userland to report the minimum necessary device size.  */
end_comment

begin_define
define|#
directive|define
name|SPA_MINDEVSIZE
value|(64ULL<< 20)
end_define

begin_comment
comment|/*  * The location of the pool configuration repository, shared between kernel and  * userland.  */
end_comment

begin_define
define|#
directive|define
name|ZPOOL_CACHE
value|"/boot/zfs/zpool.cache"
end_define

begin_comment
comment|/*  * vdev states are ordered from least to most healthy.  * A vdev that's CANT_OPEN or below is considered unusable.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|vdev_state
block|{
name|VDEV_STATE_UNKNOWN
init|=
literal|0
block|,
comment|/* Uninitialized vdev			*/
name|VDEV_STATE_CLOSED
block|,
comment|/* Not currently open			*/
name|VDEV_STATE_OFFLINE
block|,
comment|/* Not allowed to open			*/
name|VDEV_STATE_REMOVED
block|,
comment|/* Explicitly removed from system	*/
name|VDEV_STATE_CANT_OPEN
block|,
comment|/* Tried to open, but failed		*/
name|VDEV_STATE_FAULTED
block|,
comment|/* External request to fault device	*/
name|VDEV_STATE_DEGRADED
block|,
comment|/* Replicated vdev with unhealthy kids	*/
name|VDEV_STATE_HEALTHY
comment|/* Presumed good			*/
block|}
name|vdev_state_t
typedef|;
end_typedef

begin_comment
comment|/*  * vdev aux states.  When a vdev is in the CANT_OPEN state, the aux field  * of the vdev stats structure uses these constants to distinguish why.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|vdev_aux
block|{
name|VDEV_AUX_NONE
block|,
comment|/* no error				*/
name|VDEV_AUX_OPEN_FAILED
block|,
comment|/* ldi_open_*() or vn_open() failed	*/
name|VDEV_AUX_CORRUPT_DATA
block|,
comment|/* bad label or disk contents		*/
name|VDEV_AUX_NO_REPLICAS
block|,
comment|/* insufficient number of replicas	*/
name|VDEV_AUX_BAD_GUID_SUM
block|,
comment|/* vdev guid sum doesn't match		*/
name|VDEV_AUX_TOO_SMALL
block|,
comment|/* vdev size is too small		*/
name|VDEV_AUX_BAD_LABEL
block|,
comment|/* the label is OK but invalid		*/
name|VDEV_AUX_VERSION_NEWER
block|,
comment|/* on-disk version is too new		*/
name|VDEV_AUX_VERSION_OLDER
block|,
comment|/* on-disk version is too old		*/
name|VDEV_AUX_SPARED
comment|/* hot spare used in another pool	*/
block|}
name|vdev_aux_t
typedef|;
end_typedef

begin_comment
comment|/*  * pool state.  The following states are written to disk as part of the normal  * SPA lifecycle: ACTIVE, EXPORTED, DESTROYED, SPARE.  The remaining states are  * software abstractions used at various levels to communicate pool state.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|pool_state
block|{
name|POOL_STATE_ACTIVE
init|=
literal|0
block|,
comment|/* In active use		*/
name|POOL_STATE_EXPORTED
block|,
comment|/* Explicitly exported		*/
name|POOL_STATE_DESTROYED
block|,
comment|/* Explicitly destroyed		*/
name|POOL_STATE_SPARE
block|,
comment|/* Reserved for hot spare use	*/
name|POOL_STATE_UNINITIALIZED
block|,
comment|/* Internal spa_t state		*/
name|POOL_STATE_UNAVAIL
block|,
comment|/* Internal libzfs state	*/
name|POOL_STATE_POTENTIALLY_ACTIVE
comment|/* Internal libzfs state	*/
block|}
name|pool_state_t
typedef|;
end_typedef

begin_comment
comment|/*  * The uberblock version is incremented whenever an incompatible on-disk  * format change is made to the SPA, DMU, or ZAP.  *  * Note: the first two fields should never be moved.  When a storage pool  * is opened, the uberblock must be read off the disk before the version  * can be checked.  If the ub_version field is moved, we may not detect  * version mismatch.  If the ub_magic field is moved, applications that  * expect the magic number in the first word won't work.  */
end_comment

begin_define
define|#
directive|define
name|UBERBLOCK_MAGIC
value|0x00bab10c
end_define

begin_comment
comment|/* oo-ba-bloc!	*/
end_comment

begin_define
define|#
directive|define
name|UBERBLOCK_SHIFT
value|10
end_define

begin_comment
comment|/* up to 1K	*/
end_comment

begin_struct
struct|struct
name|uberblock
block|{
name|uint64_t
name|ub_magic
decl_stmt|;
comment|/* UBERBLOCK_MAGIC		*/
name|uint64_t
name|ub_version
decl_stmt|;
comment|/* SPA_VERSION			*/
name|uint64_t
name|ub_txg
decl_stmt|;
comment|/* txg of last sync		*/
name|uint64_t
name|ub_guid_sum
decl_stmt|;
comment|/* sum of all vdev guids	*/
name|uint64_t
name|ub_timestamp
decl_stmt|;
comment|/* UTC time of last sync	*/
name|blkptr_t
name|ub_rootbp
decl_stmt|;
comment|/* MOS objset_phys_t		*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags.  */
end_comment

begin_define
define|#
directive|define
name|DNODE_MUST_BE_ALLOCATED
value|1
end_define

begin_define
define|#
directive|define
name|DNODE_MUST_BE_FREE
value|2
end_define

begin_comment
comment|/*  * Fixed constants.  */
end_comment

begin_define
define|#
directive|define
name|DNODE_SHIFT
value|9
end_define

begin_comment
comment|/* 512 bytes */
end_comment

begin_define
define|#
directive|define
name|DN_MIN_INDBLKSHIFT
value|12
end_define

begin_comment
comment|/* 4k */
end_comment

begin_define
define|#
directive|define
name|DN_MAX_INDBLKSHIFT
value|14
end_define

begin_comment
comment|/* 16k */
end_comment

begin_define
define|#
directive|define
name|DNODE_BLOCK_SHIFT
value|14
end_define

begin_comment
comment|/* 16k */
end_comment

begin_define
define|#
directive|define
name|DNODE_CORE_SIZE
value|64
end_define

begin_comment
comment|/* 64 bytes for dnode sans blkptrs */
end_comment

begin_define
define|#
directive|define
name|DN_MAX_OBJECT_SHIFT
value|48
end_define

begin_comment
comment|/* 256 trillion (zfs_fid_t limit) */
end_comment

begin_define
define|#
directive|define
name|DN_MAX_OFFSET_SHIFT
value|64
end_define

begin_comment
comment|/* 2^64 bytes in a dnode */
end_comment

begin_comment
comment|/*  * Derived constants.  */
end_comment

begin_define
define|#
directive|define
name|DNODE_SIZE
value|(1<< DNODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|DN_MAX_NBLKPTR
value|((DNODE_SIZE - DNODE_CORE_SIZE)>> SPA_BLKPTRSHIFT)
end_define

begin_define
define|#
directive|define
name|DN_MAX_BONUSLEN
value|(DNODE_SIZE - DNODE_CORE_SIZE - (1<< SPA_BLKPTRSHIFT))
end_define

begin_define
define|#
directive|define
name|DN_MAX_OBJECT
value|(1ULL<< DN_MAX_OBJECT_SHIFT)
end_define

begin_define
define|#
directive|define
name|DNODES_PER_BLOCK_SHIFT
value|(DNODE_BLOCK_SHIFT - DNODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|DNODES_PER_BLOCK
value|(1ULL<< DNODES_PER_BLOCK_SHIFT)
end_define

begin_define
define|#
directive|define
name|DNODES_PER_LEVEL_SHIFT
value|(DN_MAX_INDBLKSHIFT - SPA_BLKPTRSHIFT)
end_define

begin_comment
comment|/* The +2 here is a cheesy way to round up */
end_comment

begin_define
define|#
directive|define
name|DN_MAX_LEVELS
value|(2 + ((DN_MAX_OFFSET_SHIFT - SPA_MINBLOCKSHIFT) / \ 	(DN_MIN_INDBLKSHIFT - SPA_BLKPTRSHIFT)))
end_define

begin_define
define|#
directive|define
name|DN_BONUS
parameter_list|(
name|dnp
parameter_list|)
value|((void*)((dnp)->dn_bonus + \ 	(((dnp)->dn_nblkptr - 1) * sizeof (blkptr_t))))
end_define

begin_define
define|#
directive|define
name|DN_USED_BYTES
parameter_list|(
name|dnp
parameter_list|)
value|(((dnp)->dn_flags& DNODE_FLAG_USED_BYTES) ? \ 	(dnp)->dn_used : (dnp)->dn_used<< SPA_MINBLOCKSHIFT)
end_define

begin_define
define|#
directive|define
name|EPB
parameter_list|(
name|blkshift
parameter_list|,
name|typeshift
parameter_list|)
value|(1<< (blkshift - typeshift))
end_define

begin_comment
comment|/* Is dn_used in bytes?  if not, it's in multiples of SPA_MINBLOCKSIZE */
end_comment

begin_define
define|#
directive|define
name|DNODE_FLAG_USED_BYTES
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DNODE_FLAG_USERUSED_ACCOUNTED
value|(1<<1)
end_define

begin_comment
comment|/* Does dnode have a SA spill blkptr in bonus? */
end_comment

begin_define
define|#
directive|define
name|DNODE_FLAG_SPILL_BLKPTR
value|(1<<2)
end_define

begin_typedef
typedef|typedef
struct|struct
name|dnode_phys
block|{
name|uint8_t
name|dn_type
decl_stmt|;
comment|/* dmu_object_type_t */
name|uint8_t
name|dn_indblkshift
decl_stmt|;
comment|/* ln2(indirect block size) */
name|uint8_t
name|dn_nlevels
decl_stmt|;
comment|/* 1=dn_blkptr->data blocks */
name|uint8_t
name|dn_nblkptr
decl_stmt|;
comment|/* length of dn_blkptr */
name|uint8_t
name|dn_bonustype
decl_stmt|;
comment|/* type of data in bonus buffer */
name|uint8_t
name|dn_checksum
decl_stmt|;
comment|/* ZIO_CHECKSUM type */
name|uint8_t
name|dn_compress
decl_stmt|;
comment|/* ZIO_COMPRESS type */
name|uint8_t
name|dn_flags
decl_stmt|;
comment|/* DNODE_FLAG_* */
name|uint16_t
name|dn_datablkszsec
decl_stmt|;
comment|/* data block size in 512b sectors */
name|uint16_t
name|dn_bonuslen
decl_stmt|;
comment|/* length of dn_bonus */
name|uint8_t
name|dn_pad2
index|[
literal|4
index|]
decl_stmt|;
comment|/* accounting is protected by dn_dirty_mtx */
name|uint64_t
name|dn_maxblkid
decl_stmt|;
comment|/* largest allocated block ID */
name|uint64_t
name|dn_used
decl_stmt|;
comment|/* bytes (or sectors) of disk space */
name|uint64_t
name|dn_pad3
index|[
literal|4
index|]
decl_stmt|;
name|blkptr_t
name|dn_blkptr
index|[
literal|1
index|]
decl_stmt|;
name|uint8_t
name|dn_bonus
index|[
name|DN_MAX_BONUSLEN
operator|-
sizeof|sizeof
argument_list|(
name|blkptr_t
argument_list|)
index|]
decl_stmt|;
name|blkptr_t
name|dn_spill
decl_stmt|;
block|}
name|dnode_phys_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|dmu_object_byteswap
block|{
name|DMU_BSWAP_UINT8
block|,
name|DMU_BSWAP_UINT16
block|,
name|DMU_BSWAP_UINT32
block|,
name|DMU_BSWAP_UINT64
block|,
name|DMU_BSWAP_ZAP
block|,
name|DMU_BSWAP_DNODE
block|,
name|DMU_BSWAP_OBJSET
block|,
name|DMU_BSWAP_ZNODE
block|,
name|DMU_BSWAP_OLDACL
block|,
name|DMU_BSWAP_ACL
block|,
comment|/* 	 * Allocating a new byteswap type number makes the on-disk format 	 * incompatible with any other format that uses the same number. 	 * 	 * Data can usually be structured to work with one of the 	 * DMU_BSWAP_UINT* or DMU_BSWAP_ZAP types. 	 */
name|DMU_BSWAP_NUMFUNCS
block|}
name|dmu_object_byteswap_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DMU_OT_NEWTYPE
value|0x80
end_define

begin_define
define|#
directive|define
name|DMU_OT_METADATA
value|0x40
end_define

begin_define
define|#
directive|define
name|DMU_OT_BYTESWAP_MASK
value|0x3f
end_define

begin_comment
comment|/*  * Defines a uint8_t object type. Object types specify if the data  * in the object is metadata (boolean) and how to byteswap the data  * (dmu_object_byteswap_t).  */
end_comment

begin_define
define|#
directive|define
name|DMU_OT
parameter_list|(
name|byteswap
parameter_list|,
name|metadata
parameter_list|)
define|\
value|(DMU_OT_NEWTYPE | \ 	((metadata) ? DMU_OT_METADATA : 0) | \ 	((byteswap)& DMU_OT_BYTESWAP_MASK))
end_define

begin_typedef
typedef|typedef
enum|enum
name|dmu_object_type
block|{
name|DMU_OT_NONE
block|,
comment|/* general: */
name|DMU_OT_OBJECT_DIRECTORY
block|,
comment|/* ZAP */
name|DMU_OT_OBJECT_ARRAY
block|,
comment|/* UINT64 */
name|DMU_OT_PACKED_NVLIST
block|,
comment|/* UINT8 (XDR by nvlist_pack/unpack) */
name|DMU_OT_PACKED_NVLIST_SIZE
block|,
comment|/* UINT64 */
name|DMU_OT_BPLIST
block|,
comment|/* UINT64 */
name|DMU_OT_BPLIST_HDR
block|,
comment|/* UINT64 */
comment|/* spa: */
name|DMU_OT_SPACE_MAP_HEADER
block|,
comment|/* UINT64 */
name|DMU_OT_SPACE_MAP
block|,
comment|/* UINT64 */
comment|/* zil: */
name|DMU_OT_INTENT_LOG
block|,
comment|/* UINT64 */
comment|/* dmu: */
name|DMU_OT_DNODE
block|,
comment|/* DNODE */
name|DMU_OT_OBJSET
block|,
comment|/* OBJSET */
comment|/* dsl: */
name|DMU_OT_DSL_DIR
block|,
comment|/* UINT64 */
name|DMU_OT_DSL_DIR_CHILD_MAP
block|,
comment|/* ZAP */
name|DMU_OT_DSL_DS_SNAP_MAP
block|,
comment|/* ZAP */
name|DMU_OT_DSL_PROPS
block|,
comment|/* ZAP */
name|DMU_OT_DSL_DATASET
block|,
comment|/* UINT64 */
comment|/* zpl: */
name|DMU_OT_ZNODE
block|,
comment|/* ZNODE */
name|DMU_OT_OLDACL
block|,
comment|/* Old ACL */
name|DMU_OT_PLAIN_FILE_CONTENTS
block|,
comment|/* UINT8 */
name|DMU_OT_DIRECTORY_CONTENTS
block|,
comment|/* ZAP */
name|DMU_OT_MASTER_NODE
block|,
comment|/* ZAP */
name|DMU_OT_UNLINKED_SET
block|,
comment|/* ZAP */
comment|/* zvol: */
name|DMU_OT_ZVOL
block|,
comment|/* UINT8 */
name|DMU_OT_ZVOL_PROP
block|,
comment|/* ZAP */
comment|/* other; for testing only! */
name|DMU_OT_PLAIN_OTHER
block|,
comment|/* UINT8 */
name|DMU_OT_UINT64_OTHER
block|,
comment|/* UINT64 */
name|DMU_OT_ZAP_OTHER
block|,
comment|/* ZAP */
comment|/* new object types: */
name|DMU_OT_ERROR_LOG
block|,
comment|/* ZAP */
name|DMU_OT_SPA_HISTORY
block|,
comment|/* UINT8 */
name|DMU_OT_SPA_HISTORY_OFFSETS
block|,
comment|/* spa_his_phys_t */
name|DMU_OT_POOL_PROPS
block|,
comment|/* ZAP */
name|DMU_OT_DSL_PERMS
block|,
comment|/* ZAP */
name|DMU_OT_ACL
block|,
comment|/* ACL */
name|DMU_OT_SYSACL
block|,
comment|/* SYSACL */
name|DMU_OT_FUID
block|,
comment|/* FUID table (Packed NVLIST UINT8) */
name|DMU_OT_FUID_SIZE
block|,
comment|/* FUID table size UINT64 */
name|DMU_OT_NEXT_CLONES
block|,
comment|/* ZAP */
name|DMU_OT_SCAN_QUEUE
block|,
comment|/* ZAP */
name|DMU_OT_USERGROUP_USED
block|,
comment|/* ZAP */
name|DMU_OT_USERGROUP_QUOTA
block|,
comment|/* ZAP */
name|DMU_OT_USERREFS
block|,
comment|/* ZAP */
name|DMU_OT_DDT_ZAP
block|,
comment|/* ZAP */
name|DMU_OT_DDT_STATS
block|,
comment|/* ZAP */
name|DMU_OT_SA
block|,
comment|/* System attr */
name|DMU_OT_SA_MASTER_NODE
block|,
comment|/* ZAP */
name|DMU_OT_SA_ATTR_REGISTRATION
block|,
comment|/* ZAP */
name|DMU_OT_SA_ATTR_LAYOUTS
block|,
comment|/* ZAP */
name|DMU_OT_SCAN_XLATE
block|,
comment|/* ZAP */
name|DMU_OT_DEDUP
block|,
comment|/* fake dedup BP from ddt_bp_create() */
name|DMU_OT_NUMTYPES
block|,
comment|/* 	 * Names for valid types declared with DMU_OT(). 	 */
name|DMU_OTN_UINT8_DATA
init|=
name|DMU_OT
argument_list|(
name|DMU_BSWAP_UINT8
argument_list|,
name|B_FALSE
argument_list|)
block|,
name|DMU_OTN_UINT8_METADATA
init|=
name|DMU_OT
argument_list|(
name|DMU_BSWAP_UINT8
argument_list|,
name|B_TRUE
argument_list|)
block|,
name|DMU_OTN_UINT16_DATA
init|=
name|DMU_OT
argument_list|(
name|DMU_BSWAP_UINT16
argument_list|,
name|B_FALSE
argument_list|)
block|,
name|DMU_OTN_UINT16_METADATA
init|=
name|DMU_OT
argument_list|(
name|DMU_BSWAP_UINT16
argument_list|,
name|B_TRUE
argument_list|)
block|,
name|DMU_OTN_UINT32_DATA
init|=
name|DMU_OT
argument_list|(
name|DMU_BSWAP_UINT32
argument_list|,
name|B_FALSE
argument_list|)
block|,
name|DMU_OTN_UINT32_METADATA
init|=
name|DMU_OT
argument_list|(
name|DMU_BSWAP_UINT32
argument_list|,
name|B_TRUE
argument_list|)
block|,
name|DMU_OTN_UINT64_DATA
init|=
name|DMU_OT
argument_list|(
name|DMU_BSWAP_UINT64
argument_list|,
name|B_FALSE
argument_list|)
block|,
name|DMU_OTN_UINT64_METADATA
init|=
name|DMU_OT
argument_list|(
name|DMU_BSWAP_UINT64
argument_list|,
name|B_TRUE
argument_list|)
block|,
name|DMU_OTN_ZAP_DATA
init|=
name|DMU_OT
argument_list|(
name|DMU_BSWAP_ZAP
argument_list|,
name|B_FALSE
argument_list|)
block|,
name|DMU_OTN_ZAP_METADATA
init|=
name|DMU_OT
argument_list|(
argument|DMU_BSWAP_ZAP
argument_list|,
argument|B_TRUE
argument_list|)
block|}
name|dmu_object_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|dmu_objset_type
block|{
name|DMU_OST_NONE
block|,
name|DMU_OST_META
block|,
name|DMU_OST_ZFS
block|,
name|DMU_OST_ZVOL
block|,
name|DMU_OST_OTHER
block|,
comment|/* For testing only! */
name|DMU_OST_ANY
block|,
comment|/* Be careful! */
name|DMU_OST_NUMTYPES
block|}
name|dmu_objset_type_t
typedef|;
end_typedef

begin_comment
comment|/*  * header for all bonus and spill buffers.  * The header has a fixed portion with a variable number  * of "lengths" depending on the number of variable sized  * attribues which are determined by the "layout number"  */
end_comment

begin_define
define|#
directive|define
name|SA_MAGIC
value|0x2F505A
end_define

begin_comment
comment|/* ZFS SA */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|sa_hdr_phys
block|{
name|uint32_t
name|sa_magic
decl_stmt|;
name|uint16_t
name|sa_layout_info
decl_stmt|;
comment|/* Encoded with hdrsize and layout number */
name|uint16_t
name|sa_lengths
index|[
literal|1
index|]
decl_stmt|;
comment|/* optional sizes for variable length attrs */
comment|/* ... Data follows the lengths.  */
block|}
name|sa_hdr_phys_t
typedef|;
end_typedef

begin_comment
comment|/*  * sa_hdr_phys -> sa_layout_info  *  * 16      10       0  * +--------+-------+  * | hdrsz  |layout |  * +--------+-------+  *  * Bits 0-10 are the layout number  * Bits 11-16 are the size of the header.  * The hdrsize is the number * 8  *  * For example.  * hdrsz of 1 ==> 8 byte header  *          2 ==> 16 byte header  *  */
end_comment

begin_define
define|#
directive|define
name|SA_HDR_LAYOUT_NUM
parameter_list|(
name|hdr
parameter_list|)
value|BF32_GET(hdr->sa_layout_info, 0, 10)
end_define

begin_define
define|#
directive|define
name|SA_HDR_SIZE
parameter_list|(
name|hdr
parameter_list|)
value|BF32_GET_SB(hdr->sa_layout_info, 10, 16, 3, 0)
end_define

begin_define
define|#
directive|define
name|SA_HDR_LAYOUT_INFO_ENCODE
parameter_list|(
name|x
parameter_list|,
name|num
parameter_list|,
name|size
parameter_list|)
define|\
value|{ \ 	BF32_SET_SB(x, 10, 6, 3, 0, size); \ 	BF32_SET(x, 0, 10, num); \ }
end_define

begin_define
define|#
directive|define
name|SA_MODE_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|SA_SIZE_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|SA_GEN_OFFSET
value|16
end_define

begin_define
define|#
directive|define
name|SA_UID_OFFSET
value|24
end_define

begin_define
define|#
directive|define
name|SA_GID_OFFSET
value|32
end_define

begin_define
define|#
directive|define
name|SA_PARENT_OFFSET
value|40
end_define

begin_define
define|#
directive|define
name|SA_SYMLINK_OFFSET
value|160
end_define

begin_comment
comment|/*  * Intent log header - this on disk structure holds fields to manage  * the log.  All fields are 64 bit to easily handle cross architectures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|zil_header
block|{
name|uint64_t
name|zh_claim_txg
decl_stmt|;
comment|/* txg in which log blocks were claimed */
name|uint64_t
name|zh_replay_seq
decl_stmt|;
comment|/* highest replayed sequence number */
name|blkptr_t
name|zh_log
decl_stmt|;
comment|/* log chain */
name|uint64_t
name|zh_claim_seq
decl_stmt|;
comment|/* highest claimed sequence number */
name|uint64_t
name|zh_pad
index|[
literal|5
index|]
decl_stmt|;
block|}
name|zil_header_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OBJSET_PHYS_SIZE
value|2048
end_define

begin_typedef
typedef|typedef
struct|struct
name|objset_phys
block|{
name|dnode_phys_t
name|os_meta_dnode
decl_stmt|;
name|zil_header_t
name|os_zil_header
decl_stmt|;
name|uint64_t
name|os_type
decl_stmt|;
name|uint64_t
name|os_flags
decl_stmt|;
name|char
name|os_pad
index|[
name|OBJSET_PHYS_SIZE
operator|-
sizeof|sizeof
argument_list|(
name|dnode_phys_t
argument_list|)
operator|*
literal|3
operator|-
sizeof|sizeof
argument_list|(
name|zil_header_t
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|*
literal|2
index|]
decl_stmt|;
name|dnode_phys_t
name|os_userused_dnode
decl_stmt|;
name|dnode_phys_t
name|os_groupused_dnode
decl_stmt|;
block|}
name|objset_phys_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dsl_dir_phys
block|{
name|uint64_t
name|dd_creation_time
decl_stmt|;
comment|/* not actually used */
name|uint64_t
name|dd_head_dataset_obj
decl_stmt|;
name|uint64_t
name|dd_parent_obj
decl_stmt|;
name|uint64_t
name|dd_clone_parent_obj
decl_stmt|;
name|uint64_t
name|dd_child_dir_zapobj
decl_stmt|;
comment|/* 	 * how much space our children are accounting for; for leaf 	 * datasets, == physical space used by fs + snaps 	 */
name|uint64_t
name|dd_used_bytes
decl_stmt|;
name|uint64_t
name|dd_compressed_bytes
decl_stmt|;
name|uint64_t
name|dd_uncompressed_bytes
decl_stmt|;
comment|/* Administrative quota setting */
name|uint64_t
name|dd_quota
decl_stmt|;
comment|/* Administrative reservation setting */
name|uint64_t
name|dd_reserved
decl_stmt|;
name|uint64_t
name|dd_props_zapobj
decl_stmt|;
name|uint64_t
name|dd_pad
index|[
literal|21
index|]
decl_stmt|;
comment|/* pad out to 256 bytes for good measure */
block|}
name|dsl_dir_phys_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dsl_dataset_phys
block|{
name|uint64_t
name|ds_dir_obj
decl_stmt|;
name|uint64_t
name|ds_prev_snap_obj
decl_stmt|;
name|uint64_t
name|ds_prev_snap_txg
decl_stmt|;
name|uint64_t
name|ds_next_snap_obj
decl_stmt|;
name|uint64_t
name|ds_snapnames_zapobj
decl_stmt|;
comment|/* zap obj of snaps; ==0 for snaps */
name|uint64_t
name|ds_num_children
decl_stmt|;
comment|/* clone/snap children; ==0 for head */
name|uint64_t
name|ds_creation_time
decl_stmt|;
comment|/* seconds since 1970 */
name|uint64_t
name|ds_creation_txg
decl_stmt|;
name|uint64_t
name|ds_deadlist_obj
decl_stmt|;
name|uint64_t
name|ds_used_bytes
decl_stmt|;
name|uint64_t
name|ds_compressed_bytes
decl_stmt|;
name|uint64_t
name|ds_uncompressed_bytes
decl_stmt|;
name|uint64_t
name|ds_unique_bytes
decl_stmt|;
comment|/* only relevant to snapshots */
comment|/* 	 * The ds_fsid_guid is a 56-bit ID that can change to avoid 	 * collisions.  The ds_guid is a 64-bit ID that will never 	 * change, so there is a small probability that it will collide. 	 */
name|uint64_t
name|ds_fsid_guid
decl_stmt|;
name|uint64_t
name|ds_guid
decl_stmt|;
name|uint64_t
name|ds_flags
decl_stmt|;
name|blkptr_t
name|ds_bp
decl_stmt|;
name|uint64_t
name|ds_pad
index|[
literal|8
index|]
decl_stmt|;
comment|/* pad out to 320 bytes for good measure */
block|}
name|dsl_dataset_phys_t
typedef|;
end_typedef

begin_comment
comment|/*  * The names of zap entries in the DIRECTORY_OBJECT of the MOS.  */
end_comment

begin_define
define|#
directive|define
name|DMU_POOL_DIRECTORY_OBJECT
value|1
end_define

begin_define
define|#
directive|define
name|DMU_POOL_CONFIG
value|"config"
end_define

begin_define
define|#
directive|define
name|DMU_POOL_FEATURES_FOR_READ
value|"features_for_read"
end_define

begin_define
define|#
directive|define
name|DMU_POOL_ROOT_DATASET
value|"root_dataset"
end_define

begin_define
define|#
directive|define
name|DMU_POOL_SYNC_BPLIST
value|"sync_bplist"
end_define

begin_define
define|#
directive|define
name|DMU_POOL_ERRLOG_SCRUB
value|"errlog_scrub"
end_define

begin_define
define|#
directive|define
name|DMU_POOL_ERRLOG_LAST
value|"errlog_last"
end_define

begin_define
define|#
directive|define
name|DMU_POOL_SPARES
value|"spares"
end_define

begin_define
define|#
directive|define
name|DMU_POOL_DEFLATE
value|"deflate"
end_define

begin_define
define|#
directive|define
name|DMU_POOL_HISTORY
value|"history"
end_define

begin_define
define|#
directive|define
name|DMU_POOL_PROPS
value|"pool_props"
end_define

begin_define
define|#
directive|define
name|ZAP_MAGIC
value|0x2F52AB2ABULL
end_define

begin_define
define|#
directive|define
name|FZAP_BLOCK_SHIFT
parameter_list|(
name|zap
parameter_list|)
value|((zap)->zap_block_shift)
end_define

begin_define
define|#
directive|define
name|ZAP_MAXCD
value|(uint32_t)(-1)
end_define

begin_define
define|#
directive|define
name|ZAP_HASHBITS
value|28
end_define

begin_define
define|#
directive|define
name|MZAP_ENT_LEN
value|64
end_define

begin_define
define|#
directive|define
name|MZAP_NAME_LEN
value|(MZAP_ENT_LEN - 8 - 4 - 2)
end_define

begin_define
define|#
directive|define
name|MZAP_MAX_BLKSHIFT
value|SPA_MAXBLOCKSHIFT
end_define

begin_define
define|#
directive|define
name|MZAP_MAX_BLKSZ
value|(1<< MZAP_MAX_BLKSHIFT)
end_define

begin_typedef
typedef|typedef
struct|struct
name|mzap_ent_phys
block|{
name|uint64_t
name|mze_value
decl_stmt|;
name|uint32_t
name|mze_cd
decl_stmt|;
name|uint16_t
name|mze_pad
decl_stmt|;
comment|/* in case we want to chain them someday */
name|char
name|mze_name
index|[
name|MZAP_NAME_LEN
index|]
decl_stmt|;
block|}
name|mzap_ent_phys_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|mzap_phys
block|{
name|uint64_t
name|mz_block_type
decl_stmt|;
comment|/* ZBT_MICRO */
name|uint64_t
name|mz_salt
decl_stmt|;
name|uint64_t
name|mz_pad
index|[
literal|6
index|]
decl_stmt|;
name|mzap_ent_phys_t
name|mz_chunk
index|[
literal|1
index|]
decl_stmt|;
comment|/* actually variable size depending on block size */
block|}
name|mzap_phys_t
typedef|;
end_typedef

begin_comment
comment|/*  * The (fat) zap is stored in one object. It is an array of  * 1<<FZAP_BLOCK_SHIFT byte blocks. The layout looks like one of:  *  * ptrtbl fits in first block:  * 	[zap_phys_t zap_ptrtbl_shift< 6] [zap_leaf_t] ...  *  * ptrtbl too big for first block:  * 	[zap_phys_t zap_ptrtbl_shift>= 6] [zap_leaf_t] [ptrtbl] ...  *  */
end_comment

begin_define
define|#
directive|define
name|ZBT_LEAF
value|((1ULL<< 63) + 0)
end_define

begin_define
define|#
directive|define
name|ZBT_HEADER
value|((1ULL<< 63) + 1)
end_define

begin_define
define|#
directive|define
name|ZBT_MICRO
value|((1ULL<< 63) + 3)
end_define

begin_comment
comment|/* any other values are ptrtbl blocks */
end_comment

begin_comment
comment|/*  * the embedded pointer table takes up half a block:  * block size / entry size (2^3) / 2  */
end_comment

begin_define
define|#
directive|define
name|ZAP_EMBEDDED_PTRTBL_SHIFT
parameter_list|(
name|zap
parameter_list|)
value|(FZAP_BLOCK_SHIFT(zap) - 3 - 1)
end_define

begin_comment
comment|/*  * The embedded pointer table starts half-way through the block.  Since  * the pointer table itself is half the block, it starts at (64-bit)  * word number (1<<ZAP_EMBEDDED_PTRTBL_SHIFT(zap)).  */
end_comment

begin_define
define|#
directive|define
name|ZAP_EMBEDDED_PTRTBL_ENT
parameter_list|(
name|zap
parameter_list|,
name|idx
parameter_list|)
define|\
value|((uint64_t *)(zap)->zap_phys) \ 	[(idx) + (1<<ZAP_EMBEDDED_PTRTBL_SHIFT(zap))]
end_define

begin_comment
comment|/*  * TAKE NOTE:  * If zap_phys_t is modified, zap_byteswap() must be modified.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|zap_phys
block|{
name|uint64_t
name|zap_block_type
decl_stmt|;
comment|/* ZBT_HEADER */
name|uint64_t
name|zap_magic
decl_stmt|;
comment|/* ZAP_MAGIC */
struct|struct
name|zap_table_phys
block|{
name|uint64_t
name|zt_blk
decl_stmt|;
comment|/* starting block number */
name|uint64_t
name|zt_numblks
decl_stmt|;
comment|/* number of blocks */
name|uint64_t
name|zt_shift
decl_stmt|;
comment|/* bits to index it */
name|uint64_t
name|zt_nextblk
decl_stmt|;
comment|/* next (larger) copy start block */
name|uint64_t
name|zt_blks_copied
decl_stmt|;
comment|/* number source blocks copied */
block|}
name|zap_ptrtbl
struct|;
name|uint64_t
name|zap_freeblk
decl_stmt|;
comment|/* the next free block */
name|uint64_t
name|zap_num_leafs
decl_stmt|;
comment|/* number of leafs */
name|uint64_t
name|zap_num_entries
decl_stmt|;
comment|/* number of entries */
name|uint64_t
name|zap_salt
decl_stmt|;
comment|/* salt to stir into hash function */
comment|/* 	 * This structure is followed by padding, and then the embedded 	 * pointer table.  The embedded pointer table takes up second 	 * half of the block.  It is accessed using the 	 * ZAP_EMBEDDED_PTRTBL_ENT() macro. 	 */
block|}
name|zap_phys_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|zap_table_phys
name|zap_table_phys_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|fat_zap
block|{
name|int
name|zap_block_shift
decl_stmt|;
comment|/* block size shift */
name|zap_phys_t
modifier|*
name|zap_phys
decl_stmt|;
block|}
name|fat_zap_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ZAP_LEAF_MAGIC
value|0x2AB1EAF
end_define

begin_comment
comment|/* chunk size = 24 bytes */
end_comment

begin_define
define|#
directive|define
name|ZAP_LEAF_CHUNKSIZE
value|24
end_define

begin_comment
comment|/*  * The amount of space available for chunks is:  * block size (1<<l->l_bs) - hash entry size (2) * number of hash  * entries - header space (2*chunksize)  */
end_comment

begin_define
define|#
directive|define
name|ZAP_LEAF_NUMCHUNKS
parameter_list|(
name|l
parameter_list|)
define|\
value|(((1<<(l)->l_bs) - 2*ZAP_LEAF_HASH_NUMENTRIES(l)) / \ 	ZAP_LEAF_CHUNKSIZE - 2)
end_define

begin_comment
comment|/*  * The amount of space within the chunk available for the array is:  * chunk size - space for type (1) - space for next pointer (2)  */
end_comment

begin_define
define|#
directive|define
name|ZAP_LEAF_ARRAY_BYTES
value|(ZAP_LEAF_CHUNKSIZE - 3)
end_define

begin_define
define|#
directive|define
name|ZAP_LEAF_ARRAY_NCHUNKS
parameter_list|(
name|bytes
parameter_list|)
define|\
value|(((bytes)+ZAP_LEAF_ARRAY_BYTES-1)/ZAP_LEAF_ARRAY_BYTES)
end_define

begin_comment
comment|/*  * Low water mark:  when there are only this many chunks free, start  * growing the ptrtbl.  Ideally, this should be larger than a  * "reasonably-sized" entry.  20 chunks is more than enough for the  * largest directory entry (MAXNAMELEN (256) byte name, 8-byte value),  * while still being only around 3% for 16k blocks.  */
end_comment

begin_define
define|#
directive|define
name|ZAP_LEAF_LOW_WATER
value|(20)
end_define

begin_comment
comment|/*  * The leaf hash table has block size / 2^5 (32) number of entries,  * which should be more than enough for the maximum number of entries,  * which is less than block size / CHUNKSIZE (24) / minimum number of  * chunks per entry (3).  */
end_comment

begin_define
define|#
directive|define
name|ZAP_LEAF_HASH_SHIFT
parameter_list|(
name|l
parameter_list|)
value|((l)->l_bs - 5)
end_define

begin_define
define|#
directive|define
name|ZAP_LEAF_HASH_NUMENTRIES
parameter_list|(
name|l
parameter_list|)
value|(1<< ZAP_LEAF_HASH_SHIFT(l))
end_define

begin_comment
comment|/*  * The chunks start immediately after the hash table.  The end of the  * hash table is at l_hash + HASH_NUMENTRIES, which we simply cast to a  * chunk_t.  */
end_comment

begin_define
define|#
directive|define
name|ZAP_LEAF_CHUNK
parameter_list|(
name|l
parameter_list|,
name|idx
parameter_list|)
define|\
value|((zap_leaf_chunk_t *) \ 	((l)->l_phys->l_hash + ZAP_LEAF_HASH_NUMENTRIES(l)))[idx]
end_define

begin_define
define|#
directive|define
name|ZAP_LEAF_ENTRY
parameter_list|(
name|l
parameter_list|,
name|idx
parameter_list|)
value|(&ZAP_LEAF_CHUNK(l, idx).l_entry)
end_define

begin_typedef
typedef|typedef
enum|enum
name|zap_chunk_type
block|{
name|ZAP_CHUNK_FREE
init|=
literal|253
block|,
name|ZAP_CHUNK_ENTRY
init|=
literal|252
block|,
name|ZAP_CHUNK_ARRAY
init|=
literal|251
block|,
name|ZAP_CHUNK_TYPE_MAX
init|=
literal|250
block|}
name|zap_chunk_type_t
typedef|;
end_typedef

begin_comment
comment|/*  * TAKE NOTE:  * If zap_leaf_phys_t is modified, zap_leaf_byteswap() must be modified.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|zap_leaf_phys
block|{
struct|struct
name|zap_leaf_header
block|{
name|uint64_t
name|lh_block_type
decl_stmt|;
comment|/* ZBT_LEAF */
name|uint64_t
name|lh_pad1
decl_stmt|;
name|uint64_t
name|lh_prefix
decl_stmt|;
comment|/* hash prefix of this leaf */
name|uint32_t
name|lh_magic
decl_stmt|;
comment|/* ZAP_LEAF_MAGIC */
name|uint16_t
name|lh_nfree
decl_stmt|;
comment|/* number free chunks */
name|uint16_t
name|lh_nentries
decl_stmt|;
comment|/* number of entries */
name|uint16_t
name|lh_prefix_len
decl_stmt|;
comment|/* num bits used to id this */
comment|/* above is accessable to zap, below is zap_leaf private */
name|uint16_t
name|lh_freelist
decl_stmt|;
comment|/* chunk head of free list */
name|uint8_t
name|lh_pad2
index|[
literal|12
index|]
decl_stmt|;
block|}
name|l_hdr
struct|;
comment|/* 2 24-byte chunks */
comment|/* 	 * The header is followed by a hash table with 	 * ZAP_LEAF_HASH_NUMENTRIES(zap) entries.  The hash table is 	 * followed by an array of ZAP_LEAF_NUMCHUNKS(zap) 	 * zap_leaf_chunk structures.  These structures are accessed 	 * with the ZAP_LEAF_CHUNK() macro. 	 */
name|uint16_t
name|l_hash
index|[
literal|1
index|]
decl_stmt|;
block|}
name|zap_leaf_phys_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|zap_leaf_chunk
block|{
struct|struct
name|zap_leaf_entry
block|{
name|uint8_t
name|le_type
decl_stmt|;
comment|/* always ZAP_CHUNK_ENTRY */
name|uint8_t
name|le_value_intlen
decl_stmt|;
comment|/* size of ints */
name|uint16_t
name|le_next
decl_stmt|;
comment|/* next entry in hash chain */
name|uint16_t
name|le_name_chunk
decl_stmt|;
comment|/* first chunk of the name */
name|uint16_t
name|le_name_numints
decl_stmt|;
comment|/* bytes in name, incl null */
name|uint16_t
name|le_value_chunk
decl_stmt|;
comment|/* first chunk of the value */
name|uint16_t
name|le_value_numints
decl_stmt|;
comment|/* value length in ints */
name|uint32_t
name|le_cd
decl_stmt|;
comment|/* collision differentiator */
name|uint64_t
name|le_hash
decl_stmt|;
comment|/* hash value of the name */
block|}
name|l_entry
struct|;
struct|struct
name|zap_leaf_array
block|{
name|uint8_t
name|la_type
decl_stmt|;
comment|/* always ZAP_CHUNK_ARRAY */
name|uint8_t
name|la_array
index|[
name|ZAP_LEAF_ARRAY_BYTES
index|]
decl_stmt|;
name|uint16_t
name|la_next
decl_stmt|;
comment|/* next blk or CHAIN_END */
block|}
name|l_array
struct|;
struct|struct
name|zap_leaf_free
block|{
name|uint8_t
name|lf_type
decl_stmt|;
comment|/* always ZAP_CHUNK_FREE */
name|uint8_t
name|lf_pad
index|[
name|ZAP_LEAF_ARRAY_BYTES
index|]
decl_stmt|;
name|uint16_t
name|lf_next
decl_stmt|;
comment|/* next in free list, or CHAIN_END */
block|}
name|l_free
struct|;
block|}
name|zap_leaf_chunk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|zap_leaf
block|{
name|int
name|l_bs
decl_stmt|;
comment|/* block size shift */
name|zap_leaf_phys_t
modifier|*
name|l_phys
decl_stmt|;
block|}
name|zap_leaf_t
typedef|;
end_typedef

begin_comment
comment|/*  * Define special zfs pflags  */
end_comment

begin_define
define|#
directive|define
name|ZFS_XATTR
value|0x1
end_define

begin_comment
comment|/* is an extended attribute */
end_comment

begin_define
define|#
directive|define
name|ZFS_INHERIT_ACE
value|0x2
end_define

begin_comment
comment|/* ace has inheritable ACEs */
end_comment

begin_define
define|#
directive|define
name|ZFS_ACL_TRIVIAL
value|0x4
end_define

begin_comment
comment|/* files ACL is trivial */
end_comment

begin_define
define|#
directive|define
name|MASTER_NODE_OBJ
value|1
end_define

begin_comment
comment|/*  * special attributes for master node.  */
end_comment

begin_define
define|#
directive|define
name|ZFS_FSID
value|"FSID"
end_define

begin_define
define|#
directive|define
name|ZFS_UNLINKED_SET
value|"DELETE_QUEUE"
end_define

begin_define
define|#
directive|define
name|ZFS_ROOT_OBJ
value|"ROOT"
end_define

begin_define
define|#
directive|define
name|ZPL_VERSION_OBJ
value|"VERSION"
end_define

begin_define
define|#
directive|define
name|ZFS_PROP_BLOCKPERPAGE
value|"BLOCKPERPAGE"
end_define

begin_define
define|#
directive|define
name|ZFS_PROP_NOGROWBLOCKS
value|"NOGROWBLOCKS"
end_define

begin_define
define|#
directive|define
name|ZFS_FLAG_BLOCKPERPAGE
value|0x1
end_define

begin_define
define|#
directive|define
name|ZFS_FLAG_NOGROWBLOCKS
value|0x2
end_define

begin_comment
comment|/*  * ZPL version - rev'd whenever an incompatible on-disk format change  * occurs.  Independent of SPA/DMU/ZAP versioning.  */
end_comment

begin_define
define|#
directive|define
name|ZPL_VERSION
value|1ULL
end_define

begin_comment
comment|/*  * The directory entry has the type (currently unused on Solaris) in the  * top 4 bits, and the object number in the low 48 bits.  The "middle"  * 12 bits are unused.  */
end_comment

begin_define
define|#
directive|define
name|ZFS_DIRENT_TYPE
parameter_list|(
name|de
parameter_list|)
value|BF64_GET(de, 60, 4)
end_define

begin_define
define|#
directive|define
name|ZFS_DIRENT_OBJ
parameter_list|(
name|de
parameter_list|)
value|BF64_GET(de, 0, 48)
end_define

begin_define
define|#
directive|define
name|ZFS_DIRENT_MAKE
parameter_list|(
name|type
parameter_list|,
name|obj
parameter_list|)
value|(((uint64_t)type<< 60) | obj)
end_define

begin_typedef
typedef|typedef
struct|struct
name|ace
block|{
name|uid_t
name|a_who
decl_stmt|;
comment|/* uid or gid */
name|uint32_t
name|a_access_mask
decl_stmt|;
comment|/* read,write,... */
name|uint16_t
name|a_flags
decl_stmt|;
comment|/* see below */
name|uint16_t
name|a_type
decl_stmt|;
comment|/* allow or deny */
block|}
name|ace_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ACE_SLOT_CNT
value|6
end_define

begin_typedef
typedef|typedef
struct|struct
name|zfs_znode_acl
block|{
name|uint64_t
name|z_acl_extern_obj
decl_stmt|;
comment|/* ext acl pieces */
name|uint32_t
name|z_acl_count
decl_stmt|;
comment|/* Number of ACEs */
name|uint16_t
name|z_acl_version
decl_stmt|;
comment|/* acl version */
name|uint16_t
name|z_acl_pad
decl_stmt|;
comment|/* pad */
name|ace_t
name|z_ace_data
index|[
name|ACE_SLOT_CNT
index|]
decl_stmt|;
comment|/* 6 standard ACEs */
block|}
name|zfs_znode_acl_t
typedef|;
end_typedef

begin_comment
comment|/*  * This is the persistent portion of the znode.  It is stored  * in the "bonus buffer" of the file.  Short symbolic links  * are also stored in the bonus buffer.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|znode_phys
block|{
name|uint64_t
name|zp_atime
index|[
literal|2
index|]
decl_stmt|;
comment|/*  0 - last file access time */
name|uint64_t
name|zp_mtime
index|[
literal|2
index|]
decl_stmt|;
comment|/* 16 - last file modification time */
name|uint64_t
name|zp_ctime
index|[
literal|2
index|]
decl_stmt|;
comment|/* 32 - last file change time */
name|uint64_t
name|zp_crtime
index|[
literal|2
index|]
decl_stmt|;
comment|/* 48 - creation time */
name|uint64_t
name|zp_gen
decl_stmt|;
comment|/* 64 - generation (txg of creation) */
name|uint64_t
name|zp_mode
decl_stmt|;
comment|/* 72 - file mode bits */
name|uint64_t
name|zp_size
decl_stmt|;
comment|/* 80 - size of file */
name|uint64_t
name|zp_parent
decl_stmt|;
comment|/* 88 - directory parent (`..') */
name|uint64_t
name|zp_links
decl_stmt|;
comment|/* 96 - number of links to file */
name|uint64_t
name|zp_xattr
decl_stmt|;
comment|/* 104 - DMU object for xattrs */
name|uint64_t
name|zp_rdev
decl_stmt|;
comment|/* 112 - dev_t for VBLK& VCHR files */
name|uint64_t
name|zp_flags
decl_stmt|;
comment|/* 120 - persistent flags */
name|uint64_t
name|zp_uid
decl_stmt|;
comment|/* 128 - file owner */
name|uint64_t
name|zp_gid
decl_stmt|;
comment|/* 136 - owning group */
name|uint64_t
name|zp_pad
index|[
literal|4
index|]
decl_stmt|;
comment|/* 144 - future */
name|zfs_znode_acl_t
name|zp_acl
decl_stmt|;
comment|/* 176 - 263 ACL */
comment|/* 	 * Data may pad out any remaining bytes in the znode buffer, eg: 	 * 	 * |<---------------------- dnode_phys (512) ------------------------>| 	 * |<-- dnode (192) --->|<----------- "bonus" buffer (320) ---------->| 	 *			|<---- znode (264) ---->|<---- data (56) ---->| 	 * 	 * At present, we only use this space to store symbolic links. 	 */
block|}
name|znode_phys_t
typedef|;
end_typedef

begin_comment
comment|/*  * In-core vdev representation.  */
end_comment

begin_struct_decl
struct_decl|struct
name|vdev
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|vdev_phys_read_t
parameter_list|(
name|struct
name|vdev
modifier|*
name|vdev
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|bytes
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vdev_read_t
parameter_list|(
name|struct
name|vdev
modifier|*
name|vdev
parameter_list|,
specifier|const
name|blkptr_t
modifier|*
name|bp
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|off_t
name|offset
parameter_list|,
name|size_t
name|bytes
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument|vdev_list
argument_list|,
argument|vdev
argument_list|)
name|vdev_list_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vdev
block|{
name|STAILQ_ENTRY
argument_list|(
argument|vdev
argument_list|)
name|v_childlink
expr_stmt|;
comment|/* link in parent's child list */
name|STAILQ_ENTRY
argument_list|(
argument|vdev
argument_list|)
name|v_alllink
expr_stmt|;
comment|/* link in global vdev list */
name|vdev_list_t
name|v_children
decl_stmt|;
comment|/* children of this vdev */
specifier|const
name|char
modifier|*
name|v_name
decl_stmt|;
comment|/* vdev name */
name|uint64_t
name|v_guid
decl_stmt|;
comment|/* vdev guid */
name|int
name|v_id
decl_stmt|;
comment|/* index in parent */
name|int
name|v_ashift
decl_stmt|;
comment|/* offset to block shift */
name|int
name|v_nparity
decl_stmt|;
comment|/* # parity for raidz */
name|struct
name|vdev
modifier|*
name|v_top
decl_stmt|;
comment|/* parent vdev */
name|int
name|v_nchildren
decl_stmt|;
comment|/* # children */
name|vdev_state_t
name|v_state
decl_stmt|;
comment|/* current state */
name|vdev_phys_read_t
modifier|*
name|v_phys_read
decl_stmt|;
comment|/* read from raw leaf vdev */
name|vdev_read_t
modifier|*
name|v_read
decl_stmt|;
comment|/* read from vdev */
name|void
modifier|*
name|v_read_priv
decl_stmt|;
comment|/* private data for read function */
block|}
name|vdev_t
typedef|;
end_typedef

begin_comment
comment|/*  * In-core pool representation.  */
end_comment

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument|spa_list
argument_list|,
argument|spa
argument_list|)
name|spa_list_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|spa
block|{
name|STAILQ_ENTRY
argument_list|(
argument|spa
argument_list|)
name|spa_link
expr_stmt|;
comment|/* link in global pool list */
name|char
modifier|*
name|spa_name
decl_stmt|;
comment|/* pool name */
name|uint64_t
name|spa_guid
decl_stmt|;
comment|/* pool guid */
name|uint64_t
name|spa_txg
decl_stmt|;
comment|/* most recent transaction */
name|struct
name|uberblock
name|spa_uberblock
decl_stmt|;
comment|/* best uberblock so far */
name|vdev_list_t
name|spa_vdevs
decl_stmt|;
comment|/* list of all toplevel vdevs */
name|objset_phys_t
name|spa_mos
decl_stmt|;
comment|/* MOS for this pool */
name|int
name|spa_inited
decl_stmt|;
comment|/* initialized */
block|}
name|spa_t
typedef|;
end_typedef

begin_function_decl
specifier|static
name|void
name|decode_embedded_bp_compressed
parameter_list|(
specifier|const
name|blkptr_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

