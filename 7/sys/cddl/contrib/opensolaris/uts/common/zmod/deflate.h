begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* deflate.h -- internal compression state  * Copyright (C) 1995-2004 Jean-loup Gailly  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment

begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEFLATE_H
end_ifndef

begin_define
define|#
directive|define
name|_DEFLATE_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|"zutil.h"
end_include

begin_comment
comment|/* define NO_GZIP when compiling if you want to disable gzip header and    trailer creation by deflate().  NO_GZIP would be used to avoid linking in    the crc code when it is not needed.  For shared libraries, gzip encoding    should be left enabled. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_GZIP
end_ifndef

begin_define
define|#
directive|define
name|GZIP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ===========================================================================  * Internal compression state.  */
end_comment

begin_define
define|#
directive|define
name|LENGTH_CODES
value|29
end_define

begin_comment
comment|/* number of length codes, not counting the special END_BLOCK code */
end_comment

begin_define
define|#
directive|define
name|LITERALS
value|256
end_define

begin_comment
comment|/* number of literal bytes 0..255 */
end_comment

begin_define
define|#
directive|define
name|L_CODES
value|(LITERALS+1+LENGTH_CODES)
end_define

begin_comment
comment|/* number of Literal or Length codes, including the END_BLOCK code */
end_comment

begin_define
define|#
directive|define
name|D_CODES
value|30
end_define

begin_comment
comment|/* number of distance codes */
end_comment

begin_define
define|#
directive|define
name|BL_CODES
value|19
end_define

begin_comment
comment|/* number of codes used to transfer the bit lengths */
end_comment

begin_define
define|#
directive|define
name|HEAP_SIZE
value|(2*L_CODES+1)
end_define

begin_comment
comment|/* maximum heap size */
end_comment

begin_define
define|#
directive|define
name|MAX_BITS
value|15
end_define

begin_comment
comment|/* All codes must not exceed MAX_BITS bits */
end_comment

begin_define
define|#
directive|define
name|INIT_STATE
value|42
end_define

begin_define
define|#
directive|define
name|EXTRA_STATE
value|69
end_define

begin_define
define|#
directive|define
name|NAME_STATE
value|73
end_define

begin_define
define|#
directive|define
name|COMMENT_STATE
value|91
end_define

begin_define
define|#
directive|define
name|HCRC_STATE
value|103
end_define

begin_define
define|#
directive|define
name|BUSY_STATE
value|113
end_define

begin_define
define|#
directive|define
name|FINISH_STATE
value|666
end_define

begin_comment
comment|/* Stream status */
end_comment

begin_comment
comment|/* Data structure describing a single value and its code string. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ct_data_s
block|{
union|union
block|{
name|ush
name|freq
decl_stmt|;
comment|/* frequency count */
name|ush
name|code
decl_stmt|;
comment|/* bit string */
block|}
name|fc
union|;
union|union
block|{
name|ush
name|dad
decl_stmt|;
comment|/* father node in Huffman tree */
name|ush
name|len
decl_stmt|;
comment|/* length of bit string */
block|}
name|dl
union|;
block|}
name|FAR
name|ct_data
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Freq
value|fc.freq
end_define

begin_define
define|#
directive|define
name|Code
value|fc.code
end_define

begin_define
define|#
directive|define
name|Dad
value|dl.dad
end_define

begin_define
define|#
directive|define
name|Len
value|dl.len
end_define

begin_typedef
typedef|typedef
name|struct
name|static_tree_desc_s
name|static_tree_desc
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|tree_desc_s
block|{
name|ct_data
modifier|*
name|dyn_tree
decl_stmt|;
comment|/* the dynamic tree */
name|int
name|max_code
decl_stmt|;
comment|/* largest code with non zero frequency */
name|static_tree_desc
modifier|*
name|stat_desc
decl_stmt|;
comment|/* the corresponding static tree */
block|}
name|FAR
name|tree_desc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ush
name|Pos
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Pos
name|FAR
name|Posf
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|IPos
typedef|;
end_typedef

begin_comment
comment|/* A Pos is an index in the character window. We use short instead of int to  * save space in the various tables. IPos is used only for parameter passing.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|internal_state
block|{
name|z_streamp
name|strm
decl_stmt|;
comment|/* pointer back to this zlib stream */
name|int
name|status
decl_stmt|;
comment|/* as the name implies */
name|Bytef
modifier|*
name|pending_buf
decl_stmt|;
comment|/* output still pending */
name|ulg
name|pending_buf_size
decl_stmt|;
comment|/* size of pending_buf */
name|Bytef
modifier|*
name|pending_out
decl_stmt|;
comment|/* next pending byte to output to the stream */
name|uInt
name|pending
decl_stmt|;
comment|/* nb of bytes in the pending buffer */
name|int
name|wrap
decl_stmt|;
comment|/* bit 0 true for zlib, bit 1 true for gzip */
name|gz_headerp
name|gzhead
decl_stmt|;
comment|/* gzip header information to write */
name|uInt
name|gzindex
decl_stmt|;
comment|/* where in extra, name, or comment */
name|Byte
name|method
decl_stmt|;
comment|/* STORED (for zip only) or DEFLATED */
name|int
name|last_flush
decl_stmt|;
comment|/* value of flush param for previous deflate call */
comment|/* used by deflate.c: */
name|uInt
name|w_size
decl_stmt|;
comment|/* LZ77 window size (32K by default) */
name|uInt
name|w_bits
decl_stmt|;
comment|/* log2(w_size)  (8..16) */
name|uInt
name|w_mask
decl_stmt|;
comment|/* w_size - 1 */
name|Bytef
modifier|*
name|window
decl_stmt|;
comment|/* Sliding window. Input bytes are read into the second half of the window,      * and move to the first half later to keep a dictionary of at least wSize      * bytes. With this organization, matches are limited to a distance of      * wSize-MAX_MATCH bytes, but this ensures that IO is always      * performed with a length multiple of the block size. Also, it limits      * the window size to 64K, which is quite useful on MSDOS.      * To do: use the user input buffer as sliding window.      */
name|ulg
name|window_size
decl_stmt|;
comment|/* Actual size of window: 2*wSize, except when the user input buffer      * is directly used as sliding window.      */
name|Posf
modifier|*
name|prev
decl_stmt|;
comment|/* Link to older string with same hash index. To limit the size of this      * array to 64K, this link is maintained only for the last 32K strings.      * An index in this array is thus a window index modulo 32K.      */
name|Posf
modifier|*
name|head
decl_stmt|;
comment|/* Heads of the hash chains or NIL. */
name|uInt
name|ins_h
decl_stmt|;
comment|/* hash index of string to be inserted */
name|uInt
name|hash_size
decl_stmt|;
comment|/* number of elements in hash table */
name|uInt
name|hash_bits
decl_stmt|;
comment|/* log2(hash_size) */
name|uInt
name|hash_mask
decl_stmt|;
comment|/* hash_size-1 */
name|uInt
name|hash_shift
decl_stmt|;
comment|/* Number of bits by which ins_h must be shifted at each input      * step. It must be such that after MIN_MATCH steps, the oldest      * byte no longer takes part in the hash key, that is:      *   hash_shift * MIN_MATCH>= hash_bits      */
name|long
name|block_start
decl_stmt|;
comment|/* Window position at the beginning of the current output block. Gets      * negative when the window is moved backwards.      */
name|uInt
name|match_length
decl_stmt|;
comment|/* length of best match */
name|IPos
name|prev_match
decl_stmt|;
comment|/* previous match */
name|int
name|match_available
decl_stmt|;
comment|/* set if previous match exists */
name|uInt
name|strstart
decl_stmt|;
comment|/* start of string to insert */
name|uInt
name|match_start
decl_stmt|;
comment|/* start of matching string */
name|uInt
name|lookahead
decl_stmt|;
comment|/* number of valid bytes ahead in window */
name|uInt
name|prev_length
decl_stmt|;
comment|/* Length of the best match at previous step. Matches not greater than this      * are discarded. This is used in the lazy match evaluation.      */
name|uInt
name|max_chain_length
decl_stmt|;
comment|/* To speed up deflation, hash chains are never searched beyond this      * length.  A higher limit improves compression ratio but degrades the      * speed.      */
name|uInt
name|max_lazy_match
decl_stmt|;
comment|/* Attempt to find a better match only when the current match is strictly      * smaller than this value. This mechanism is used only for compression      * levels>= 4.      */
define|#
directive|define
name|max_insert_length
value|max_lazy_match
comment|/* Insert new strings in the hash table only if the match length is not      * greater than this length. This saves time but degrades compression.      * max_insert_length is used only for compression levels<= 3.      */
name|int
name|level
decl_stmt|;
comment|/* compression level (1..9) */
name|int
name|strategy
decl_stmt|;
comment|/* favor or force Huffman coding*/
name|uInt
name|good_match
decl_stmt|;
comment|/* Use a faster search when the previous match is longer than this */
name|int
name|nice_match
decl_stmt|;
comment|/* Stop searching when current match exceeds this */
comment|/* used by trees.c: */
comment|/* Didn't use ct_data typedef below to supress compiler warning */
name|struct
name|ct_data_s
name|dyn_ltree
index|[
name|HEAP_SIZE
index|]
decl_stmt|;
comment|/* literal and length tree */
name|struct
name|ct_data_s
name|dyn_dtree
index|[
literal|2
operator|*
name|D_CODES
operator|+
literal|1
index|]
decl_stmt|;
comment|/* distance tree */
name|struct
name|ct_data_s
name|bl_tree
index|[
literal|2
operator|*
name|BL_CODES
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Huffman tree for bit lengths */
name|struct
name|tree_desc_s
name|l_desc
decl_stmt|;
comment|/* desc. for literal tree */
name|struct
name|tree_desc_s
name|d_desc
decl_stmt|;
comment|/* desc. for distance tree */
name|struct
name|tree_desc_s
name|bl_desc
decl_stmt|;
comment|/* desc. for bit length tree */
name|ush
name|bl_count
index|[
name|MAX_BITS
operator|+
literal|1
index|]
decl_stmt|;
comment|/* number of codes at each bit length for an optimal tree */
name|int
name|heap
index|[
literal|2
operator|*
name|L_CODES
operator|+
literal|1
index|]
decl_stmt|;
comment|/* heap used to build the Huffman trees */
name|int
name|heap_len
decl_stmt|;
comment|/* number of elements in the heap */
name|int
name|heap_max
decl_stmt|;
comment|/* element of largest frequency */
comment|/* The sons of heap[n] are heap[2*n] and heap[2*n+1]. heap[0] is not used.      * The same heap array is used to build all trees.      */
name|uch
name|depth
index|[
literal|2
operator|*
name|L_CODES
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Depth of each subtree used as tie breaker for trees of equal frequency      */
name|uchf
modifier|*
name|l_buf
decl_stmt|;
comment|/* buffer for literals or lengths */
name|uInt
name|lit_bufsize
decl_stmt|;
comment|/* Size of match buffer for literals/lengths.  There are 4 reasons for      * limiting lit_bufsize to 64K:      *   - frequencies can be kept in 16 bit counters      *   - if compression is not successful for the first block, all input      *     data is still in the window so we can still emit a stored block even      *     when input comes from standard input.  (This can also be done for      *     all blocks if lit_bufsize is not greater than 32K.)      *   - if compression is not successful for a file smaller than 64K, we can      *     even emit a stored file instead of a stored block (saving 5 bytes).      *     This is applicable only for zip (not gzip or zlib).      *   - creating new Huffman trees less frequently may not provide fast      *     adaptation to changes in the input data statistics. (Take for      *     example a binary file with poorly compressible code followed by      *     a highly compressible string table.) Smaller buffer sizes give      *     fast adaptation but have of course the overhead of transmitting      *     trees more frequently.      *   - I can't count above 4      */
name|uInt
name|last_lit
decl_stmt|;
comment|/* running index in l_buf */
name|ushf
modifier|*
name|d_buf
decl_stmt|;
comment|/* Buffer for distances. To simplify the code, d_buf and l_buf have      * the same number of elements. To use different lengths, an extra flag      * array would be necessary.      */
name|ulg
name|opt_len
decl_stmt|;
comment|/* bit length of current block with optimal trees */
name|ulg
name|static_len
decl_stmt|;
comment|/* bit length of current block with static trees */
name|uInt
name|matches
decl_stmt|;
comment|/* number of string matches in current block */
name|int
name|last_eob_len
decl_stmt|;
comment|/* bit length of EOB code for last block */
ifdef|#
directive|ifdef
name|DEBUG
name|ulg
name|compressed_len
decl_stmt|;
comment|/* total bit length of compressed file mod 2^32 */
name|ulg
name|bits_sent
decl_stmt|;
comment|/* bit length of compressed data sent mod 2^32 */
endif|#
directive|endif
name|ush
name|bi_buf
decl_stmt|;
comment|/* Output buffer. bits are inserted starting at the bottom (least      * significant bits).      */
name|int
name|bi_valid
decl_stmt|;
comment|/* Number of valid bits in bi_buf.  All bits above the last valid bit      * are always zero.      */
block|}
name|FAR
name|deflate_state
typedef|;
end_typedef

begin_comment
comment|/* Output a byte on the stream.  * IN assertion: there is enough room in pending_buf.  */
end_comment

begin_define
define|#
directive|define
name|put_byte
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|)
value|{s->pending_buf[s->pending++] = (c);}
end_define

begin_define
define|#
directive|define
name|MIN_LOOKAHEAD
value|(MAX_MATCH+MIN_MATCH+1)
end_define

begin_comment
comment|/* Minimum amount of lookahead, except at the end of the input file.  * See deflate.c for comments about the MIN_MATCH+1.  */
end_comment

begin_define
define|#
directive|define
name|MAX_DIST
parameter_list|(
name|s
parameter_list|)
value|((s)->w_size-MIN_LOOKAHEAD)
end_define

begin_comment
comment|/* In order to simplify the code, particularly on 16 bit machines, match  * distances are limited to MAX_DIST instead of WSIZE.  */
end_comment

begin_comment
comment|/* in trees.c */
end_comment

begin_decl_stmt
name|void
name|_tr_init
name|OF
argument_list|(
operator|(
name|deflate_state
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_tr_tally
name|OF
argument_list|(
operator|(
name|deflate_state
operator|*
name|s
operator|,
name|unsigned
name|dist
operator|,
name|unsigned
name|lc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_tr_flush_block
name|OF
argument_list|(
operator|(
name|deflate_state
operator|*
name|s
operator|,
name|charf
operator|*
name|buf
operator|,
name|ulg
name|stored_len
operator|,
name|int
name|eof
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_tr_align
name|OF
argument_list|(
operator|(
name|deflate_state
operator|*
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|_tr_stored_block
name|OF
argument_list|(
operator|(
name|deflate_state
operator|*
name|s
operator|,
name|charf
operator|*
name|buf
operator|,
name|ulg
name|stored_len
operator|,
name|int
name|eof
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|d_code
parameter_list|(
name|dist
parameter_list|)
define|\
value|((dist)< 256 ? _dist_code[dist] : _dist_code[256+((dist)>>7)])
end_define

begin_comment
comment|/* Mapping from a distance to a distance code. dist is the distance - 1 and  * must not have side effects. _dist_code[256] and _dist_code[257] are never  * used.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_comment
comment|/* Inline versions of _tr_tally for speed: */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GEN_TREES_H
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|STDC
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|uch
name|_length_code
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uch
name|_dist_code
index|[]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
specifier|const
name|uch
name|_length_code
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|uch
name|_dist_code
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_tr_tally_lit
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|flush
parameter_list|)
define|\
value|{ uch cc = (c); \     s->d_buf[s->last_lit] = 0; \     s->l_buf[s->last_lit++] = cc; \     s->dyn_ltree[cc].Freq++; \     flush = (s->last_lit == s->lit_bufsize-1); \    }
end_define

begin_define
define|#
directive|define
name|_tr_tally_dist
parameter_list|(
name|s
parameter_list|,
name|distance
parameter_list|,
name|length
parameter_list|,
name|flush
parameter_list|)
define|\
value|{ uch len = (length); \     ush dist = (distance); \     s->d_buf[s->last_lit] = dist; \     s->l_buf[s->last_lit++] = len; \     dist--; \     s->dyn_ltree[_length_code[len]+LITERALS+1].Freq++; \     s->dyn_dtree[d_code(dist)].Freq++; \     flush = (s->last_lit == s->lit_bufsize-1); \   }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_tr_tally_lit
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|flush
parameter_list|)
value|flush = _tr_tally(s, 0, c)
end_define

begin_define
define|#
directive|define
name|_tr_tally_dist
parameter_list|(
name|s
parameter_list|,
name|distance
parameter_list|,
name|length
parameter_list|,
name|flush
parameter_list|)
define|\
value|flush = _tr_tally(s, distance, length)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEFLATE_H */
end_comment

end_unit

