begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ppp_comp.h - Definitions for doing PPP packet compression.  *  * Copyright (c) 1994 The Australian National University.  * All rights reserved.  *  * Permission to use, copy, modify, and distribute this software and its  * documentation is hereby granted, provided that the above copyright  * notice appears in all copies.  This software is provided without any  * warranty, express or implied. The Australian National University  * makes no representations about the suitability of this software for  * any purpose.  *  * IN NO EVENT SHALL THE AUSTRALIAN NATIONAL UNIVERSITY BE LIABLE TO ANY  * PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF  * THE AUSTRALIAN NATIONAL UNIVERSITY HAVE BEEN ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * THE AUSTRALIAN NATIONAL UNIVERSITY SPECIFICALLY DISCLAIMS ANY WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE AUSTRALIAN NATIONAL UNIVERSITY HAS NO  * OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS,  * OR MODIFICATIONS.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_PPP_COMP_H
end_ifndef

begin_define
define|#
directive|define
name|_NET_PPP_COMP_H
end_define

begin_comment
comment|/*  * The following symbols control whether we include code for  * various compression methods.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DO_BSD_COMPRESS
end_ifndef

begin_define
define|#
directive|define
name|DO_BSD_COMPRESS
value|1
end_define

begin_comment
comment|/* by default, include BSD-Compress */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DO_DEFLATE
end_ifndef

begin_define
define|#
directive|define
name|DO_DEFLATE
value|1
end_define

begin_comment
comment|/* by default, include Deflate */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DO_PREDICTOR_1
value|0
end_define

begin_define
define|#
directive|define
name|DO_PREDICTOR_2
value|0
end_define

begin_comment
comment|/*  * Structure giving methods for compression/decompression.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PACKETPTR
end_ifdef

begin_struct
struct|struct
name|compressor
block|{
name|int
name|compress_proto
decl_stmt|;
comment|/* CCP compression protocol number */
comment|/* Allocate space for a compressor (transmit side) */
name|void
operator|*
operator|(
operator|*
name|comp_alloc
operator|)
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|options
operator|,
name|int
name|opt_len
operator|)
argument_list|)
expr_stmt|;
comment|/* Free space used by a compressor */
name|void
argument_list|(
argument|*comp_free
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|state
operator|)
argument_list|)
expr_stmt|;
comment|/* Initialize a compressor */
name|int
argument_list|(
argument|*comp_init
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|state
operator|,
name|u_char
operator|*
name|options
operator|,
name|int
name|opt_len
operator|,
name|int
name|unit
operator|,
name|int
name|hdrlen
operator|,
name|int
name|debug
operator|)
argument_list|)
expr_stmt|;
comment|/* Reset a compressor */
name|void
argument_list|(
argument|*comp_reset
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|state
operator|)
argument_list|)
expr_stmt|;
comment|/* Compress a packet */
name|int
argument_list|(
argument|*compress
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|state
operator|,
name|PACKETPTR
operator|*
name|mret
operator|,
name|PACKETPTR
name|mp
operator|,
name|int
name|orig_len
operator|,
name|int
name|max_len
operator|)
argument_list|)
expr_stmt|;
comment|/* Return compression statistics */
name|void
argument_list|(
argument|*comp_stat
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|state
operator|,
expr|struct
name|compstat
operator|*
name|stats
operator|)
argument_list|)
expr_stmt|;
comment|/* Allocate space for a decompressor (receive side) */
name|void
operator|*
operator|(
operator|*
name|decomp_alloc
operator|)
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|options
operator|,
name|int
name|opt_len
operator|)
argument_list|)
expr_stmt|;
comment|/* Free space used by a decompressor */
name|void
argument_list|(
argument|*decomp_free
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|state
operator|)
argument_list|)
expr_stmt|;
comment|/* Initialize a decompressor */
name|int
argument_list|(
argument|*decomp_init
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|state
operator|,
name|u_char
operator|*
name|options
operator|,
name|int
name|opt_len
operator|,
name|int
name|unit
operator|,
name|int
name|hdrlen
operator|,
name|int
name|mru
operator|,
name|int
name|debug
operator|)
argument_list|)
expr_stmt|;
comment|/* Reset a decompressor */
name|void
argument_list|(
argument|*decomp_reset
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|state
operator|)
argument_list|)
expr_stmt|;
comment|/* Decompress a packet. */
name|int
argument_list|(
argument|*decompress
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|state
operator|,
name|PACKETPTR
name|mp
operator|,
name|PACKETPTR
operator|*
name|dmpp
operator|)
argument_list|)
expr_stmt|;
comment|/* Update state for an incompressible packet received */
name|void
argument_list|(
argument|*incomp
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|state
operator|,
name|PACKETPTR
name|mp
operator|)
argument_list|)
expr_stmt|;
comment|/* Return decompression statistics */
name|void
argument_list|(
argument|*decomp_stat
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
name|state
operator|,
expr|struct
name|compstat
operator|*
name|stats
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PACKETPTR */
end_comment

begin_comment
comment|/*  * Return values for decompress routine.  * We need to make these distinctions so that we can disable certain  * useful functionality, namely sending a CCP reset-request as a result  * of an error detected after decompression.  This is to avoid infringing  * a patent held by Motorola.  * Don't you just lurve software patents.  */
end_comment

begin_define
define|#
directive|define
name|DECOMP_OK
value|0
end_define

begin_comment
comment|/* everything went OK */
end_comment

begin_define
define|#
directive|define
name|DECOMP_ERROR
value|1
end_define

begin_comment
comment|/* error detected before decomp. */
end_comment

begin_define
define|#
directive|define
name|DECOMP_FATALERROR
value|2
end_define

begin_comment
comment|/* error detected after decomp. */
end_comment

begin_comment
comment|/*  * CCP codes.  */
end_comment

begin_define
define|#
directive|define
name|CCP_CONFREQ
value|1
end_define

begin_define
define|#
directive|define
name|CCP_CONFACK
value|2
end_define

begin_define
define|#
directive|define
name|CCP_TERMREQ
value|5
end_define

begin_define
define|#
directive|define
name|CCP_TERMACK
value|6
end_define

begin_define
define|#
directive|define
name|CCP_RESETREQ
value|14
end_define

begin_define
define|#
directive|define
name|CCP_RESETACK
value|15
end_define

begin_comment
comment|/*  * Max # bytes for a CCP option  */
end_comment

begin_define
define|#
directive|define
name|CCP_MAX_OPTION_LENGTH
value|32
end_define

begin_comment
comment|/*  * Parts of a CCP packet.  */
end_comment

begin_define
define|#
directive|define
name|CCP_CODE
parameter_list|(
name|dp
parameter_list|)
value|((dp)[0])
end_define

begin_define
define|#
directive|define
name|CCP_ID
parameter_list|(
name|dp
parameter_list|)
value|((dp)[1])
end_define

begin_define
define|#
directive|define
name|CCP_LENGTH
parameter_list|(
name|dp
parameter_list|)
value|(((dp)[2]<< 8) + (dp)[3])
end_define

begin_define
define|#
directive|define
name|CCP_HDRLEN
value|4
end_define

begin_define
define|#
directive|define
name|CCP_OPT_CODE
parameter_list|(
name|dp
parameter_list|)
value|((dp)[0])
end_define

begin_define
define|#
directive|define
name|CCP_OPT_LENGTH
parameter_list|(
name|dp
parameter_list|)
value|((dp)[1])
end_define

begin_define
define|#
directive|define
name|CCP_OPT_MINLEN
value|2
end_define

begin_comment
comment|/*  * Definitions for BSD-Compress.  */
end_comment

begin_define
define|#
directive|define
name|CI_BSD_COMPRESS
value|21
end_define

begin_comment
comment|/* config. option for BSD-Compress */
end_comment

begin_define
define|#
directive|define
name|CILEN_BSD_COMPRESS
value|3
end_define

begin_comment
comment|/* length of config. option */
end_comment

begin_comment
comment|/* Macros for handling the 3rd byte of the BSD-Compress config option. */
end_comment

begin_define
define|#
directive|define
name|BSD_NBITS
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x1F)
end_define

begin_comment
comment|/* number of bits requested */
end_comment

begin_define
define|#
directive|define
name|BSD_VERSION
parameter_list|(
name|x
parameter_list|)
value|((x)>> 5)
end_define

begin_comment
comment|/* version of option format */
end_comment

begin_define
define|#
directive|define
name|BSD_CURRENT_VERSION
value|1
end_define

begin_comment
comment|/* current version number */
end_comment

begin_define
define|#
directive|define
name|BSD_MAKE_OPT
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|(((v)<< 5) | (n))
end_define

begin_define
define|#
directive|define
name|BSD_MIN_BITS
value|9
end_define

begin_comment
comment|/* smallest code size supported */
end_comment

begin_define
define|#
directive|define
name|BSD_MAX_BITS
value|15
end_define

begin_comment
comment|/* largest code size supported */
end_comment

begin_comment
comment|/*  * Definitions for Deflate.  */
end_comment

begin_define
define|#
directive|define
name|CI_DEFLATE
value|26
end_define

begin_comment
comment|/* config option for Deflate */
end_comment

begin_define
define|#
directive|define
name|CI_DEFLATE_DRAFT
value|24
end_define

begin_comment
comment|/* value used in original draft RFC */
end_comment

begin_define
define|#
directive|define
name|CILEN_DEFLATE
value|4
end_define

begin_comment
comment|/* length of its config option */
end_comment

begin_define
define|#
directive|define
name|DEFLATE_MIN_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|DEFLATE_MAX_SIZE
value|15
end_define

begin_define
define|#
directive|define
name|DEFLATE_METHOD_VAL
value|8
end_define

begin_define
define|#
directive|define
name|DEFLATE_SIZE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4) + DEFLATE_MIN_SIZE)
end_define

begin_define
define|#
directive|define
name|DEFLATE_METHOD
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0F)
end_define

begin_define
define|#
directive|define
name|DEFLATE_MAKE_OPT
parameter_list|(
name|w
parameter_list|)
value|((((w) - DEFLATE_MIN_SIZE)<< 4) \ 				 + DEFLATE_METHOD_VAL)
end_define

begin_define
define|#
directive|define
name|DEFLATE_CHK_SEQUENCE
value|0
end_define

begin_comment
comment|/*  * Definitions for other, as yet unsupported, compression methods.  */
end_comment

begin_define
define|#
directive|define
name|CI_PREDICTOR_1
value|1
end_define

begin_comment
comment|/* config option for Predictor-1 */
end_comment

begin_define
define|#
directive|define
name|CILEN_PREDICTOR_1
value|2
end_define

begin_comment
comment|/* length of its config option */
end_comment

begin_define
define|#
directive|define
name|CI_PREDICTOR_2
value|2
end_define

begin_comment
comment|/* config option for Predictor-2 */
end_comment

begin_define
define|#
directive|define
name|CILEN_PREDICTOR_2
value|2
end_define

begin_comment
comment|/* length of its config option */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_PPP_COMP_H */
end_comment

end_unit

