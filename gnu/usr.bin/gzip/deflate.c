begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* deflate.c -- compress data using the deflation algorithm  * Copyright (C) 1992-1993 Jean-loup Gailly  * This is free software; you can redistribute it and/or modify it under the  * terms of the GNU General Public License, see the file COPYING.  */
end_comment

begin_comment
comment|/*  *  PURPOSE  *  *      Identify new text as repetitions of old text within a fixed-  *      length sliding window trailing behind the new text.  *  *  DISCUSSION  *  *      The "deflation" process depends on being able to identify portions  *      of the input text which are identical to earlier input (within a  *      sliding window trailing behind the input currently being processed).  *  *      The most straightforward technique turns out to be the fastest for  *      most input files: try all possible matches and select the longest.  *      The key feature of this algorithm is that insertions into the string  *      dictionary are very simple and thus fast, and deletions are avoided  *      completely. Insertions are performed at each input character, whereas  *      string matches are performed only when the previous match ends. So it  *      is preferable to spend more time in matches to allow very fast string  *      insertions and avoid deletions. The matching algorithm for small  *      strings is inspired from that of Rabin& Karp. A brute force approach  *      is used to find longer strings when a small match has been found.  *      A similar algorithm is used in comic (by Jan-Mark Wams) and freeze  *      (by Leonid Broukhis).  *         A previous version of this file used a more sophisticated algorithm  *      (by Fiala and Greene) which is guaranteed to run in linear amortized  *      time, but has a larger average cost, uses more memory and is patented.  *      However the F&G algorithm may be faster for some highly redundant  *      files if the parameter max_chain_length (described below) is too large.  *  *  ACKNOWLEDGEMENTS  *  *      The idea of lazy evaluation of matches is due to Jan-Mark Wams, and  *      I found it in 'freeze' written by Leonid Broukhis.  *      Thanks to many info-zippers for bug reports and testing.  *  *  REFERENCES  *  *      APPNOTE.TXT documentation file in PKZIP 1.93a distribution.  *  *      A description of the Rabin and Karp algorithm is given in the book  *         "Algorithms" by R. Sedgewick, Addison-Wesley, p252.  *  *      Fiala,E.R., and Greene,D.H.  *         Data Compression with Finite Windows, Comm.ACM, 32,4 (1989) 490-595  *  *  INTERFACE  *  *      void lm_init (int pack_level, ush *flags)  *          Initialize the "longest match" routines for a new file  *  *      ulg deflate (void)  *          Processes a new input file and return its compressed length. Sets  *          the compressed length, crc, deflate flags and internal file  *          attributes.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"tailor.h"
end_include

begin_include
include|#
directive|include
file|"gzip.h"
end_include

begin_include
include|#
directive|include
file|"lzw.h"
end_include

begin_comment
comment|/* just for consistency checking */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RCSID
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ===========================================================================  * Configuration parameters  */
end_comment

begin_comment
comment|/* Compile with MEDIUM_MEM to reduce the memory requirements or  * with SMALL_MEM to use as little memory as possible. Use BIG_MEM if the  * entire input file can be held in memory (not possible on 16 bit systems).  * Warning: defining these symbols affects HASH_BITS (see below) and thus  * affects the compression ratio. The compressed output  * is still correct, and might even be smaller in some cases.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMALL_MEM
end_ifdef

begin_define
define|#
directive|define
name|HASH_BITS
value|13
end_define

begin_comment
comment|/* Number of bits used to hash strings */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MEDIUM_MEM
end_ifdef

begin_define
define|#
directive|define
name|HASH_BITS
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASH_BITS
end_ifndef

begin_define
define|#
directive|define
name|HASH_BITS
value|15
end_define

begin_comment
comment|/* For portability to 16 bit machines, do not use values above 15. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* To save space (see unlzw.c), we overlay prev+head with tab_prefix and  * window with tab_suffix. Check that we can do this:  */
end_comment

begin_if
if|#
directive|if
operator|(
name|WSIZE
operator|<<
literal|1
operator|)
operator|>
operator|(
literal|1
operator|<<
name|BITS
operator|)
end_if

begin_label
name|error
label|:
end_label

begin_decl_stmt
name|cannot
name|overlay
name|window
name|with
name|tab_suffix
name|and
name|prev
name|with
name|tab_prefix0
endif|#
directive|endif
if|#
directive|if
name|HASH_BITS
operator|>
name|BITS
operator|-
literal|1
name|error
range|:
name|cannot
name|overlay
name|head
name|with
name|tab_prefix1
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HASH_SIZE
value|(unsigned)(1<<HASH_BITS)
end_define

begin_define
define|#
directive|define
name|HASH_MASK
value|(HASH_SIZE-1)
end_define

begin_define
define|#
directive|define
name|WMASK
value|(WSIZE-1)
end_define

begin_comment
comment|/* HASH_SIZE and WSIZE must be powers of two */
end_comment

begin_define
define|#
directive|define
name|NIL
value|0
end_define

begin_comment
comment|/* Tail of hash chains */
end_comment

begin_define
define|#
directive|define
name|FAST
value|4
end_define

begin_define
define|#
directive|define
name|SLOW
value|2
end_define

begin_comment
comment|/* speed options for the general purpose bit flag */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TOO_FAR
end_ifndef

begin_define
define|#
directive|define
name|TOO_FAR
value|4096
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Matches of length 3 are discarded if their distance exceeds TOO_FAR */
end_comment

begin_comment
comment|/* ===========================================================================  * Local data used by the "longest match" routines.  */
end_comment

begin_typedef
typedef|typedef
name|ush
name|Pos
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

begin_comment
comment|/* DECLARE(uch, window, 2L*WSIZE); */
end_comment

begin_comment
comment|/* Sliding window. Input bytes are read into the second half of the window,  * and move to the first half later to keep a dictionary of at least WSIZE  * bytes. With this organization, matches are limited to a distance of  * WSIZE-MAX_MATCH bytes, but this ensures that IO is always  * performed with a length multiple of the block size. Also, it limits  * the window size to 64K, which is quite useful on MSDOS.  * To do: limit the window size to WSIZE+BSZ if SMALL_MEM (the code would  * be less efficient).  */
end_comment

begin_comment
comment|/* DECLARE(Pos, prev, WSIZE); */
end_comment

begin_comment
comment|/* Link to older string with same hash index. To limit the size of this  * array to 64K, this link is maintained only for the last 32K strings.  * An index in this array is thus a window index modulo 32K.  */
end_comment

begin_comment
comment|/* DECLARE(Pos, head, 1<<HASH_BITS); */
end_comment

begin_comment
comment|/* Heads of the hash chains or NIL. */
end_comment

begin_decl_stmt
name|ulg
name|window_size
init|=
operator|(
name|ulg
operator|)
literal|2
operator|*
name|WSIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* window size, 2*WSIZE except for MMAP or BIG_MEM, where it is the  * input file length plus MIN_LOOKAHEAD.  */
end_comment

begin_decl_stmt
name|long
name|block_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* window position at the beginning of the current output block. Gets  * negative when the window is moved backwards.  */
end_comment

begin_decl_stmt
name|local
name|unsigned
name|ins_h
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash index of string to be inserted */
end_comment

begin_define
define|#
directive|define
name|H_SHIFT
value|((HASH_BITS+MIN_MATCH-1)/MIN_MATCH)
end_define

begin_comment
comment|/* Number of bits by which ins_h and del_h must be shifted at each  * input step. It must be such that after MIN_MATCH steps, the oldest  * byte no longer takes part in the hash key, that is:  *   H_SHIFT * MIN_MATCH>= HASH_BITS  */
end_comment

begin_decl_stmt
name|unsigned
name|int
name|near
name|prev_length
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Length of the best match at previous step. Matches not greater than this  * are discarded. This is used in the lazy match evaluation.  */
end_comment

begin_decl_stmt
name|unsigned
name|near
name|strstart
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of string to insert */
end_comment

begin_decl_stmt
name|unsigned
name|near
name|match_start
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start of matching string */
end_comment

begin_decl_stmt
name|local
name|int
name|eofile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag set at end of input file */
end_comment

begin_decl_stmt
name|local
name|unsigned
name|lookahead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of valid bytes ahead in window */
end_comment

begin_decl_stmt
name|unsigned
name|near
name|max_chain_length
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* To speed up deflation, hash chains are never searched beyond this length.  * A higher limit improves compression ratio but degrades the speed.  */
end_comment

begin_decl_stmt
name|local
name|unsigned
name|int
name|max_lazy_match
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Attempt to find a better match only when the current match is strictly  * smaller than this value. This mechanism is used only for compression  * levels>= 4.  */
end_comment

begin_define
define|#
directive|define
name|max_insert_length
value|max_lazy_match
end_define

begin_comment
comment|/* Insert new strings in the hash table only if the match length  * is not greater than this length. This saves time but degrades compression.  * max_insert_length is used only for compression levels<= 3.  */
end_comment

begin_decl_stmt
name|local
name|int
name|compr_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* compression level (1..9) */
end_comment

begin_decl_stmt
name|unsigned
name|near
name|good_match
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use a faster search when the previous match is longer than this */
end_comment

begin_comment
comment|/* Values for max_lazy_match, good_match and max_chain_length, depending on  * the desired pack level (0..9). The values given below have been tuned to  * exclude worst case performance for pathological files. Better values may be  * found for specific files.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|config
block|{
name|ush
name|good_length
decl_stmt|;
comment|/* reduce lazy search above this match length */
name|ush
name|max_lazy
decl_stmt|;
comment|/* do not perform lazy search above this match length */
name|ush
name|nice_length
decl_stmt|;
comment|/* quit search above this match length */
name|ush
name|max_chain
decl_stmt|;
block|}
name|config
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|FULL_SEARCH
end_ifdef

begin_define
define|#
directive|define
name|nice_match
value|MAX_MATCH
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|near
name|nice_match
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stop searching when current match exceeds this */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|local
name|config
name|configuration_table
index|[
literal|10
index|]
init|=
block|{
comment|/*      good lazy nice chain */
comment|/* 0 */
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* store only */
comment|/* 1 */
block|{
literal|4
block|,
literal|4
block|,
literal|8
block|,
literal|4
block|}
block|,
comment|/* maximum speed, no lazy matches */
comment|/* 2 */
block|{
literal|4
block|,
literal|5
block|,
literal|16
block|,
literal|8
block|}
block|,
comment|/* 3 */
block|{
literal|4
block|,
literal|6
block|,
literal|32
block|,
literal|32
block|}
block|,
comment|/* 4 */
block|{
literal|4
block|,
literal|4
block|,
literal|16
block|,
literal|16
block|}
block|,
comment|/* lazy matches */
comment|/* 5 */
block|{
literal|8
block|,
literal|16
block|,
literal|32
block|,
literal|32
block|}
block|,
comment|/* 6 */
block|{
literal|8
block|,
literal|16
block|,
literal|128
block|,
literal|128
block|}
block|,
comment|/* 7 */
block|{
literal|8
block|,
literal|32
block|,
literal|128
block|,
literal|256
block|}
block|,
comment|/* 8 */
block|{
literal|32
block|,
literal|128
block|,
literal|258
block|,
literal|1024
block|}
block|,
comment|/* 9 */
block|{
literal|32
block|,
literal|258
block|,
literal|258
block|,
literal|4096
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum compression */
end_comment

begin_comment
comment|/* Note: the deflate() code requires max_lazy>= MIN_MATCH and max_chain>= 4  * For deflate_fast() (levels<= 3) good is ignored and lazy has a different  * meaning.  */
end_comment

begin_define
define|#
directive|define
name|EQUAL
value|0
end_define

begin_comment
comment|/* result of memcmp for equal strings */
end_comment

begin_comment
comment|/* ===========================================================================  *  Prototypes for local functions.  */
end_comment

begin_decl_stmt
name|local
name|void
name|fill_window
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|local
name|ulg
name|deflate_fast
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|longest_match
name|OF
argument_list|(
operator|(
name|IPos
name|cur_match
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ASMV
end_ifdef

begin_decl_stmt
name|void
name|match_init
name|OF
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* asm code initialization */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
name|local
name|void
name|check_match
name|OF
argument_list|(
operator|(
name|IPos
name|start
operator|,
name|IPos
name|match
operator|,
name|int
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ===========================================================================  * Update a hash value with the given input byte  * IN  assertion: all calls to to UPDATE_HASH are made with consecutive  *    input characters, so that a running hash key can be computed from the  *    previous key instead of complete recalculation each time.  */
end_comment

begin_define
define|#
directive|define
name|UPDATE_HASH
parameter_list|(
name|h
parameter_list|,
name|c
parameter_list|)
value|(h = (((h)<<H_SHIFT) ^ (c))& HASH_MASK)
end_define

begin_comment
comment|/* ===========================================================================  * Insert string s in the dictionary and set match_head to the previous head  * of the hash chain (the most recent string with same hash key). Return  * the previous length of the hash chain.  * IN  assertion: all calls to to INSERT_STRING are made with consecutive  *    input characters and the first MIN_MATCH bytes of s are valid  *    (except for the last MIN_MATCH-1 bytes of the input file).  */
end_comment

begin_define
define|#
directive|define
name|INSERT_STRING
parameter_list|(
name|s
parameter_list|,
name|match_head
parameter_list|)
define|\
value|(UPDATE_HASH(ins_h, window[(s) + MIN_MATCH-1]), \     prev[(s)& WMASK] = match_head = head[ins_h], \     head[ins_h] = (s))
end_define

begin_comment
comment|/* ===========================================================================  * Initialize the "longest match" routines for a new file  */
end_comment

begin_function
name|void
name|lm_init
parameter_list|(
name|pack_level
parameter_list|,
name|flags
parameter_list|)
name|int
name|pack_level
decl_stmt|;
comment|/* 0: store, 1: best speed, 9: best compression */
name|ush
modifier|*
name|flags
decl_stmt|;
comment|/* general purpose bit flag */
block|{
specifier|register
name|unsigned
name|j
decl_stmt|;
if|if
condition|(
name|pack_level
operator|<
literal|1
operator|||
name|pack_level
operator|>
literal|9
condition|)
name|error
argument_list|(
literal|"bad pack level"
argument_list|)
expr_stmt|;
name|compr_level
operator|=
name|pack_level
expr_stmt|;
comment|/* Initialize the hash table. */
if|#
directive|if
name|defined
argument_list|(
name|MAXSEG_64K
argument_list|)
operator|&&
name|HASH_BITS
operator|==
literal|15
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|HASH_SIZE
condition|;
name|j
operator|++
control|)
name|head
index|[
name|j
index|]
operator|=
name|NIL
expr_stmt|;
else|#
directive|else
name|memzero
argument_list|(
operator|(
name|char
operator|*
operator|)
name|head
argument_list|,
name|HASH_SIZE
operator|*
sizeof|sizeof
argument_list|(
operator|*
name|head
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* prev will be initialized on the fly */
comment|/* Set the default configuration parameters:      */
name|max_lazy_match
operator|=
name|configuration_table
index|[
name|pack_level
index|]
operator|.
name|max_lazy
expr_stmt|;
name|good_match
operator|=
name|configuration_table
index|[
name|pack_level
index|]
operator|.
name|good_length
expr_stmt|;
ifndef|#
directive|ifndef
name|FULL_SEARCH
name|nice_match
operator|=
name|configuration_table
index|[
name|pack_level
index|]
operator|.
name|nice_length
expr_stmt|;
endif|#
directive|endif
name|max_chain_length
operator|=
name|configuration_table
index|[
name|pack_level
index|]
operator|.
name|max_chain
expr_stmt|;
if|if
condition|(
name|pack_level
operator|==
literal|1
condition|)
block|{
operator|*
name|flags
operator||=
name|FAST
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|pack_level
operator|==
literal|9
condition|)
block|{
operator|*
name|flags
operator||=
name|SLOW
expr_stmt|;
block|}
comment|/* ??? reduce max_chain_length for binary files */
name|strstart
operator|=
literal|0
expr_stmt|;
name|block_start
operator|=
literal|0L
expr_stmt|;
ifdef|#
directive|ifdef
name|ASMV
name|match_init
argument_list|()
expr_stmt|;
comment|/* initialize the asm code */
endif|#
directive|endif
name|lookahead
operator|=
name|read_buf
argument_list|(
operator|(
name|char
operator|*
operator|)
name|window
argument_list|,
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|<=
literal|2
condition|?
operator|(
name|unsigned
operator|)
name|WSIZE
else|:
literal|2
operator|*
name|WSIZE
argument_list|)
expr_stmt|;
if|if
condition|(
name|lookahead
operator|==
literal|0
operator|||
name|lookahead
operator|==
operator|(
name|unsigned
operator|)
name|EOF
condition|)
block|{
name|eofile
operator|=
literal|1
operator|,
name|lookahead
operator|=
literal|0
expr_stmt|;
return|return;
block|}
name|eofile
operator|=
literal|0
expr_stmt|;
comment|/* Make sure that we always have enough lookahead. This is important      * if input comes from a device such as a tty.      */
while|while
condition|(
name|lookahead
operator|<
name|MIN_LOOKAHEAD
operator|&&
operator|!
name|eofile
condition|)
name|fill_window
argument_list|()
expr_stmt|;
name|ins_h
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|MIN_MATCH
operator|-
literal|1
condition|;
name|j
operator|++
control|)
name|UPDATE_HASH
argument_list|(
name|ins_h
argument_list|,
name|window
index|[
name|j
index|]
argument_list|)
expr_stmt|;
comment|/* If lookahead< MIN_MATCH, ins_h is garbage, but this is      * not important since only literal bytes will be emitted.      */
block|}
end_function

begin_comment
comment|/* ===========================================================================  * Set match_start to the longest match starting at the given string and  * return its length. Matches shorter or equal to prev_length are discarded,  * in which case the result is equal to prev_length and match_start is  * garbage.  * IN assertions: cur_match is the head of the hash chain for the current  *   string (strstart) and its distance is<= MAX_DIST, and prev_length>= 1  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASMV
end_ifndef

begin_comment
comment|/* For MSDOS, OS/2 and 386 Unix, an optimized version is in match.asm or  * match.s. The code is functionally equivalent, so you can use the C version  * if desired.  */
end_comment

begin_function
name|int
name|longest_match
parameter_list|(
name|cur_match
parameter_list|)
name|IPos
name|cur_match
decl_stmt|;
comment|/* current match */
block|{
name|unsigned
name|chain_length
init|=
name|max_chain_length
decl_stmt|;
comment|/* max hash chain length */
specifier|register
name|uch
modifier|*
name|scan
init|=
name|window
operator|+
name|strstart
decl_stmt|;
comment|/* current string */
specifier|register
name|uch
modifier|*
name|match
decl_stmt|;
comment|/* matched string */
specifier|register
name|int
name|len
decl_stmt|;
comment|/* length of current match */
name|int
name|best_len
init|=
name|prev_length
decl_stmt|;
comment|/* best match length so far */
name|IPos
name|limit
init|=
name|strstart
operator|>
operator|(
name|IPos
operator|)
name|MAX_DIST
condition|?
name|strstart
operator|-
operator|(
name|IPos
operator|)
name|MAX_DIST
else|:
name|NIL
decl_stmt|;
comment|/* Stop when cur_match becomes<= limit. To simplify the code,      * we prevent matches with the string of window index 0.      */
comment|/* The code is optimized for HASH_BITS>= 8 and MAX_MATCH-2 multiple of 16.  * It is easy to get rid of this optimization if necessary.  */
if|#
directive|if
name|HASH_BITS
operator|<
literal|8
operator|||
name|MAX_MATCH
operator|!=
literal|258
name|error
label|:
name|Code
name|too
name|clever
endif|#
directive|endif
ifdef|#
directive|ifdef
name|UNALIGNED_OK
comment|/* Compare two bytes at a time. Note: this is not always beneficial.      * Try with and without -DUNALIGNED_OK to check.      */
specifier|register
name|uch
modifier|*
name|strend
init|=
name|window
operator|+
name|strstart
operator|+
name|MAX_MATCH
operator|-
literal|1
decl_stmt|;
specifier|register
name|ush
name|scan_start
init|=
operator|*
operator|(
name|ush
operator|*
operator|)
name|scan
decl_stmt|;
specifier|register
name|ush
name|scan_end
init|=
operator|*
operator|(
name|ush
operator|*
operator|)
operator|(
name|scan
operator|+
name|best_len
operator|-
literal|1
operator|)
decl_stmt|;
else|#
directive|else
specifier|register
name|uch
modifier|*
name|strend
init|=
name|window
operator|+
name|strstart
operator|+
name|MAX_MATCH
decl_stmt|;
specifier|register
name|uch
name|scan_end1
init|=
name|scan
index|[
name|best_len
operator|-
literal|1
index|]
decl_stmt|;
specifier|register
name|uch
name|scan_end
init|=
name|scan
index|[
name|best_len
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* Do not waste too much time if we already have a good match: */
if|if
condition|(
name|prev_length
operator|>=
name|good_match
condition|)
block|{
name|chain_length
operator|>>=
literal|2
expr_stmt|;
block|}
name|Assert
argument_list|(
name|strstart
operator|<=
name|window_size
operator|-
name|MIN_LOOKAHEAD
argument_list|,
literal|"insufficient lookahead"
argument_list|)
expr_stmt|;
do|do
block|{
name|Assert
argument_list|(
name|cur_match
operator|<
name|strstart
argument_list|,
literal|"no future"
argument_list|)
expr_stmt|;
name|match
operator|=
name|window
operator|+
name|cur_match
expr_stmt|;
comment|/* Skip to next match if the match length cannot increase          * or if the match length is less than 2:          */
if|#
directive|if
operator|(
name|defined
argument_list|(
name|UNALIGNED_OK
argument_list|)
operator|&&
name|MAX_MATCH
operator|==
literal|258
operator|)
comment|/* This code assumes sizeof(unsigned short) == 2. Do not use          * UNALIGNED_OK if your compiler uses a different size.          */
if|if
condition|(
operator|*
operator|(
name|ush
operator|*
operator|)
operator|(
name|match
operator|+
name|best_len
operator|-
literal|1
operator|)
operator|!=
name|scan_end
operator|||
operator|*
operator|(
name|ush
operator|*
operator|)
name|match
operator|!=
name|scan_start
condition|)
continue|continue;
comment|/* It is not necessary to compare scan[2] and match[2] since they are          * always equal when the other bytes match, given that the hash keys          * are equal and that HASH_BITS>= 8. Compare 2 bytes at a time at          * strstart+3, +5, ... up to strstart+257. We check for insufficient          * lookahead only every 4th comparison; the 128th check will be made          * at strstart+257. If MAX_MATCH-2 is not a multiple of 8, it is          * necessary to put more guard bytes at the end of the window, or          * to check more often for insufficient lookahead.          */
name|scan
operator|++
operator|,
name|match
operator|++
expr_stmt|;
do|do
block|{         }
do|while
condition|(
operator|*
operator|(
name|ush
operator|*
operator|)
operator|(
name|scan
operator|+=
literal|2
operator|)
operator|==
operator|*
operator|(
name|ush
operator|*
operator|)
operator|(
name|match
operator|+=
literal|2
operator|)
operator|&&
operator|*
operator|(
name|ush
operator|*
operator|)
operator|(
name|scan
operator|+=
literal|2
operator|)
operator|==
operator|*
operator|(
name|ush
operator|*
operator|)
operator|(
name|match
operator|+=
literal|2
operator|)
operator|&&
operator|*
operator|(
name|ush
operator|*
operator|)
operator|(
name|scan
operator|+=
literal|2
operator|)
operator|==
operator|*
operator|(
name|ush
operator|*
operator|)
operator|(
name|match
operator|+=
literal|2
operator|)
operator|&&
operator|*
operator|(
name|ush
operator|*
operator|)
operator|(
name|scan
operator|+=
literal|2
operator|)
operator|==
operator|*
operator|(
name|ush
operator|*
operator|)
operator|(
name|match
operator|+=
literal|2
operator|)
operator|&&
name|scan
operator|<
name|strend
condition|)
do|;
comment|/* The funny "do {}" generates better code on most compilers */
comment|/* Here, scan<= window+strstart+257 */
name|Assert
argument_list|(
name|scan
operator|<=
name|window
operator|+
call|(
name|unsigned
call|)
argument_list|(
name|window_size
operator|-
literal|1
argument_list|)
argument_list|,
literal|"wild scan"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|scan
operator|==
operator|*
name|match
condition|)
name|scan
operator|++
expr_stmt|;
name|len
operator|=
operator|(
name|MAX_MATCH
operator|-
literal|1
operator|)
operator|-
call|(
name|int
call|)
argument_list|(
name|strend
operator|-
name|scan
argument_list|)
expr_stmt|;
name|scan
operator|=
name|strend
operator|-
operator|(
name|MAX_MATCH
operator|-
literal|1
operator|)
expr_stmt|;
else|#
directive|else
comment|/* UNALIGNED_OK */
if|if
condition|(
name|match
index|[
name|best_len
index|]
operator|!=
name|scan_end
operator|||
name|match
index|[
name|best_len
operator|-
literal|1
index|]
operator|!=
name|scan_end1
operator|||
operator|*
name|match
operator|!=
operator|*
name|scan
operator|||
operator|*
operator|++
name|match
operator|!=
name|scan
index|[
literal|1
index|]
condition|)
continue|continue;
comment|/* The check at best_len-1 can be removed because it will be made          * again later. (This heuristic is not always a win.)          * It is not necessary to compare scan[2] and match[2] since they          * are always equal when the other bytes match, given that          * the hash keys are equal and that HASH_BITS>= 8.          */
name|scan
operator|+=
literal|2
operator|,
name|match
operator|++
expr_stmt|;
comment|/* We check for insufficient lookahead only every 8th comparison;          * the 256th check will be made at strstart+258.          */
do|do
block|{         }
do|while
condition|(
operator|*
operator|++
name|scan
operator|==
operator|*
operator|++
name|match
operator|&&
operator|*
operator|++
name|scan
operator|==
operator|*
operator|++
name|match
operator|&&
operator|*
operator|++
name|scan
operator|==
operator|*
operator|++
name|match
operator|&&
operator|*
operator|++
name|scan
operator|==
operator|*
operator|++
name|match
operator|&&
operator|*
operator|++
name|scan
operator|==
operator|*
operator|++
name|match
operator|&&
operator|*
operator|++
name|scan
operator|==
operator|*
operator|++
name|match
operator|&&
operator|*
operator|++
name|scan
operator|==
operator|*
operator|++
name|match
operator|&&
operator|*
operator|++
name|scan
operator|==
operator|*
operator|++
name|match
operator|&&
name|scan
operator|<
name|strend
condition|)
do|;
name|len
operator|=
name|MAX_MATCH
operator|-
call|(
name|int
call|)
argument_list|(
name|strend
operator|-
name|scan
argument_list|)
expr_stmt|;
name|scan
operator|=
name|strend
operator|-
name|MAX_MATCH
expr_stmt|;
endif|#
directive|endif
comment|/* UNALIGNED_OK */
if|if
condition|(
name|len
operator|>
name|best_len
condition|)
block|{
name|match_start
operator|=
name|cur_match
expr_stmt|;
name|best_len
operator|=
name|len
expr_stmt|;
if|if
condition|(
name|len
operator|>=
name|nice_match
condition|)
break|break;
ifdef|#
directive|ifdef
name|UNALIGNED_OK
name|scan_end
operator|=
operator|*
operator|(
name|ush
operator|*
operator|)
operator|(
name|scan
operator|+
name|best_len
operator|-
literal|1
operator|)
expr_stmt|;
else|#
directive|else
name|scan_end1
operator|=
name|scan
index|[
name|best_len
operator|-
literal|1
index|]
expr_stmt|;
name|scan_end
operator|=
name|scan
index|[
name|best_len
index|]
expr_stmt|;
endif|#
directive|endif
block|}
block|}
do|while
condition|(
operator|(
name|cur_match
operator|=
name|prev
index|[
name|cur_match
operator|&
name|WMASK
index|]
operator|)
operator|>
name|limit
operator|&&
operator|--
name|chain_length
operator|!=
literal|0
condition|)
do|;
return|return
name|best_len
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASMV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/* ===========================================================================  * Check that the match at match_start is indeed a match.  */
end_comment

begin_function
name|local
name|void
name|check_match
parameter_list|(
name|start
parameter_list|,
name|match
parameter_list|,
name|length
parameter_list|)
name|IPos
name|start
decl_stmt|,
name|match
decl_stmt|;
name|int
name|length
decl_stmt|;
block|{
comment|/* check that the match is indeed a match */
if|if
condition|(
name|memcmp
argument_list|(
operator|(
name|char
operator|*
operator|)
name|window
operator|+
name|match
argument_list|,
operator|(
name|char
operator|*
operator|)
name|window
operator|+
name|start
argument_list|,
name|length
argument_list|)
operator|!=
name|EQUAL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" start %d, match %d, length %d\n"
argument_list|,
name|start
argument_list|,
name|match
argument_list|,
name|length
argument_list|)
expr_stmt|;
name|error
argument_list|(
literal|"invalid match"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|verbose
operator|>
literal|1
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\\[%d,%d]"
argument_list|,
name|start
operator|-
name|match
argument_list|,
name|length
argument_list|)
expr_stmt|;
do|do
block|{
name|putc
argument_list|(
name|window
index|[
name|start
operator|++
index|]
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|length
operator|!=
literal|0
condition|)
do|;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|check_match
parameter_list|(
name|start
parameter_list|,
name|match
parameter_list|,
name|length
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ===========================================================================  * Fill the window when the lookahead becomes insufficient.  * Updates strstart and lookahead, and sets eofile if end of input file.  * IN assertion: lookahead< MIN_LOOKAHEAD&& strstart + lookahead> 0  * OUT assertions: at least one byte has been read, or eofile is set;  *    file reads are performed for at least two bytes (required for the  *    translate_eol option).  */
end_comment

begin_function
name|local
name|void
name|fill_window
parameter_list|()
block|{
specifier|register
name|unsigned
name|n
decl_stmt|,
name|m
decl_stmt|;
name|unsigned
name|more
init|=
call|(
name|unsigned
call|)
argument_list|(
name|window_size
operator|-
operator|(
name|ulg
operator|)
name|lookahead
operator|-
operator|(
name|ulg
operator|)
name|strstart
argument_list|)
decl_stmt|;
comment|/* Amount of free space at the end of the window. */
comment|/* If the window is almost full and there is insufficient lookahead,      * move the upper half to the lower one to make room in the upper half.      */
if|if
condition|(
name|more
operator|==
operator|(
name|unsigned
operator|)
name|EOF
condition|)
block|{
comment|/* Very unlikely, but possible on 16 bit machine if strstart == 0          * and lookahead == 1 (input done one byte at time)          */
name|more
operator|--
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strstart
operator|>=
name|WSIZE
operator|+
name|MAX_DIST
condition|)
block|{
comment|/* By the IN assertion, the window is not empty so we can't confuse          * more == 0 with more == 64K on a 16 bit machine.          */
name|Assert
argument_list|(
name|window_size
operator|==
operator|(
name|ulg
operator|)
literal|2
operator|*
name|WSIZE
argument_list|,
literal|"no sliding with BIG_MEM"
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|window
argument_list|,
operator|(
name|char
operator|*
operator|)
name|window
operator|+
name|WSIZE
argument_list|,
operator|(
name|unsigned
operator|)
name|WSIZE
argument_list|)
expr_stmt|;
name|match_start
operator|-=
name|WSIZE
expr_stmt|;
name|strstart
operator|-=
name|WSIZE
expr_stmt|;
comment|/* we now have strstart>= MAX_DIST: */
name|block_start
operator|-=
operator|(
name|long
operator|)
name|WSIZE
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|HASH_SIZE
condition|;
name|n
operator|++
control|)
block|{
name|m
operator|=
name|head
index|[
name|n
index|]
expr_stmt|;
name|head
index|[
name|n
index|]
operator|=
call|(
name|Pos
call|)
argument_list|(
name|m
operator|>=
name|WSIZE
condition|?
name|m
operator|-
name|WSIZE
else|:
name|NIL
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|WSIZE
condition|;
name|n
operator|++
control|)
block|{
name|m
operator|=
name|prev
index|[
name|n
index|]
expr_stmt|;
name|prev
index|[
name|n
index|]
operator|=
call|(
name|Pos
call|)
argument_list|(
name|m
operator|>=
name|WSIZE
condition|?
name|m
operator|-
name|WSIZE
else|:
name|NIL
argument_list|)
expr_stmt|;
comment|/* If n is not on any hash chain, prev[n] is garbage but              * its value will never be used.              */
block|}
name|more
operator|+=
name|WSIZE
expr_stmt|;
block|}
comment|/* At this point, more>= 2 */
if|if
condition|(
operator|!
name|eofile
condition|)
block|{
name|n
operator|=
name|read_buf
argument_list|(
operator|(
name|char
operator|*
operator|)
name|window
operator|+
name|strstart
operator|+
name|lookahead
argument_list|,
name|more
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|==
literal|0
operator|||
name|n
operator|==
operator|(
name|unsigned
operator|)
name|EOF
condition|)
block|{
name|eofile
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
name|lookahead
operator|+=
name|n
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/* ===========================================================================  * Flush the current block, with given end-of-file flag.  * IN assertion: strstart is set to the end of the current match.  */
end_comment

begin_define
define|#
directive|define
name|FLUSH_BLOCK
parameter_list|(
name|eof
parameter_list|)
define|\
value|flush_block(block_start>= 0L ? (char*)&window[(unsigned)block_start] : \                 (char*)NULL, (long)strstart - block_start, (eof))
end_define

begin_comment
comment|/* ===========================================================================  * Processes a new input file and return its compressed length. This  * function does not perform lazy evaluationof matches and inserts  * new strings in the dictionary only for unmatched strings or for short  * matches. It is used only for the fast compression options.  */
end_comment

begin_function
name|local
name|ulg
name|deflate_fast
parameter_list|()
block|{
name|IPos
name|hash_head
decl_stmt|;
comment|/* head of the hash chain */
name|int
name|flush
decl_stmt|;
comment|/* set if current block must be flushed */
name|unsigned
name|match_length
init|=
literal|0
decl_stmt|;
comment|/* length of best match */
name|prev_length
operator|=
name|MIN_MATCH
operator|-
literal|1
expr_stmt|;
while|while
condition|(
name|lookahead
operator|!=
literal|0
condition|)
block|{
comment|/* Insert the string window[strstart .. strstart+2] in the          * dictionary, and set hash_head to the head of the hash chain:          */
name|INSERT_STRING
argument_list|(
name|strstart
argument_list|,
name|hash_head
argument_list|)
expr_stmt|;
comment|/* Find the longest match, discarding those<= prev_length.          * At this point we have always match_length< MIN_MATCH          */
if|if
condition|(
name|hash_head
operator|!=
name|NIL
operator|&&
name|strstart
operator|-
name|hash_head
operator|<=
name|MAX_DIST
condition|)
block|{
comment|/* To simplify the code, we prevent matches with the string              * of window index 0 (in particular we have to avoid a match              * of the string with itself at the start of the input file).              */
name|match_length
operator|=
name|longest_match
argument_list|(
name|hash_head
argument_list|)
expr_stmt|;
comment|/* longest_match() sets match_start */
if|if
condition|(
name|match_length
operator|>
name|lookahead
condition|)
name|match_length
operator|=
name|lookahead
expr_stmt|;
block|}
if|if
condition|(
name|match_length
operator|>=
name|MIN_MATCH
condition|)
block|{
name|check_match
argument_list|(
name|strstart
argument_list|,
name|match_start
argument_list|,
name|match_length
argument_list|)
expr_stmt|;
name|flush
operator|=
name|ct_tally
argument_list|(
name|strstart
operator|-
name|match_start
argument_list|,
name|match_length
operator|-
name|MIN_MATCH
argument_list|)
expr_stmt|;
name|lookahead
operator|-=
name|match_length
expr_stmt|;
comment|/* Insert new strings in the hash table only if the match length              * is not too large. This saves time but degrades compression.              */
if|if
condition|(
name|match_length
operator|<=
name|max_insert_length
condition|)
block|{
name|match_length
operator|--
expr_stmt|;
comment|/* string at strstart already in hash table */
do|do
block|{
name|strstart
operator|++
expr_stmt|;
name|INSERT_STRING
argument_list|(
name|strstart
argument_list|,
name|hash_head
argument_list|)
expr_stmt|;
comment|/* strstart never exceeds WSIZE-MAX_MATCH, so there are                      * always MIN_MATCH bytes ahead. If lookahead< MIN_MATCH                      * these bytes are garbage, but it does not matter since                      * the next lookahead bytes will be emitted as literals.                      */
block|}
do|while
condition|(
operator|--
name|match_length
operator|!=
literal|0
condition|)
do|;
name|strstart
operator|++
expr_stmt|;
block|}
else|else
block|{
name|strstart
operator|+=
name|match_length
expr_stmt|;
name|match_length
operator|=
literal|0
expr_stmt|;
name|ins_h
operator|=
name|window
index|[
name|strstart
index|]
expr_stmt|;
name|UPDATE_HASH
argument_list|(
name|ins_h
argument_list|,
name|window
index|[
name|strstart
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
if|#
directive|if
name|MIN_MATCH
operator|!=
literal|3
name|Call
name|UPDATE_HASH
argument_list|()
name|MIN_MATCH
operator|-
literal|3
name|more
name|times
endif|#
directive|endif
block|}
block|}
else|else
block|{
comment|/* No match, output a literal byte */
name|Tracevv
argument_list|(
operator|(
name|stderr
operator|,
literal|"%c"
operator|,
name|window
index|[
name|strstart
index|]
operator|)
argument_list|)
expr_stmt|;
name|flush
operator|=
name|ct_tally
argument_list|(
literal|0
argument_list|,
name|window
index|[
name|strstart
index|]
argument_list|)
expr_stmt|;
name|lookahead
operator|--
expr_stmt|;
name|strstart
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|flush
condition|)
name|FLUSH_BLOCK
argument_list|(
literal|0
argument_list|)
operator|,
name|block_start
operator|=
name|strstart
expr_stmt|;
comment|/* Make sure that we always have enough lookahead, except          * at the end of the input file. We need MAX_MATCH bytes          * for the next match, plus MIN_MATCH bytes to insert the          * string following the next match.          */
while|while
condition|(
name|lookahead
operator|<
name|MIN_LOOKAHEAD
operator|&&
operator|!
name|eofile
condition|)
name|fill_window
argument_list|()
expr_stmt|;
block|}
return|return
name|FLUSH_BLOCK
argument_list|(
literal|1
argument_list|)
return|;
comment|/* eof */
block|}
end_function

begin_comment
comment|/* ===========================================================================  * Same as above, but achieves better compression. We use a lazy  * evaluation for matches: a match is finally adopted only if there is  * no better match at the next window position.  */
end_comment

begin_function
name|ulg
name|deflate
parameter_list|()
block|{
name|IPos
name|hash_head
decl_stmt|;
comment|/* head of hash chain */
name|IPos
name|prev_match
decl_stmt|;
comment|/* previous match */
name|int
name|flush
decl_stmt|;
comment|/* set if current block must be flushed */
name|int
name|match_available
init|=
literal|0
decl_stmt|;
comment|/* set if previous match exists */
specifier|register
name|unsigned
name|match_length
init|=
name|MIN_MATCH
operator|-
literal|1
decl_stmt|;
comment|/* length of best match */
ifdef|#
directive|ifdef
name|DEBUG
specifier|extern
name|long
name|isize
decl_stmt|;
comment|/* byte length of input file, for debug only */
endif|#
directive|endif
if|if
condition|(
name|compr_level
operator|<=
literal|3
condition|)
return|return
name|deflate_fast
argument_list|()
return|;
comment|/* optimized for speed */
comment|/* Process the input block. */
while|while
condition|(
name|lookahead
operator|!=
literal|0
condition|)
block|{
comment|/* Insert the string window[strstart .. strstart+2] in the          * dictionary, and set hash_head to the head of the hash chain:          */
name|INSERT_STRING
argument_list|(
name|strstart
argument_list|,
name|hash_head
argument_list|)
expr_stmt|;
comment|/* Find the longest match, discarding those<= prev_length.          */
name|prev_length
operator|=
name|match_length
operator|,
name|prev_match
operator|=
name|match_start
expr_stmt|;
name|match_length
operator|=
name|MIN_MATCH
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|hash_head
operator|!=
name|NIL
operator|&&
name|prev_length
operator|<
name|max_lazy_match
operator|&&
name|strstart
operator|-
name|hash_head
operator|<=
name|MAX_DIST
condition|)
block|{
comment|/* To simplify the code, we prevent matches with the string              * of window index 0 (in particular we have to avoid a match              * of the string with itself at the start of the input file).              */
name|match_length
operator|=
name|longest_match
argument_list|(
name|hash_head
argument_list|)
expr_stmt|;
comment|/* longest_match() sets match_start */
if|if
condition|(
name|match_length
operator|>
name|lookahead
condition|)
name|match_length
operator|=
name|lookahead
expr_stmt|;
comment|/* Ignore a length 3 match if it is too distant: */
if|if
condition|(
name|match_length
operator|==
name|MIN_MATCH
operator|&&
name|strstart
operator|-
name|match_start
operator|>
name|TOO_FAR
condition|)
block|{
comment|/* If prev_match is also MIN_MATCH, match_start is garbage                  * but we will ignore the current match anyway.                  */
name|match_length
operator|--
expr_stmt|;
block|}
block|}
comment|/* If there was a match at the previous step and the current          * match is not better, output the previous match:          */
if|if
condition|(
name|prev_length
operator|>=
name|MIN_MATCH
operator|&&
name|match_length
operator|<=
name|prev_length
condition|)
block|{
name|check_match
argument_list|(
name|strstart
operator|-
literal|1
argument_list|,
name|prev_match
argument_list|,
name|prev_length
argument_list|)
expr_stmt|;
name|flush
operator|=
name|ct_tally
argument_list|(
name|strstart
operator|-
literal|1
operator|-
name|prev_match
argument_list|,
name|prev_length
operator|-
name|MIN_MATCH
argument_list|)
expr_stmt|;
comment|/* Insert in hash table all strings up to the end of the match.              * strstart-1 and strstart are already inserted.              */
name|lookahead
operator|-=
name|prev_length
operator|-
literal|1
expr_stmt|;
name|prev_length
operator|-=
literal|2
expr_stmt|;
do|do
block|{
name|strstart
operator|++
expr_stmt|;
name|INSERT_STRING
argument_list|(
name|strstart
argument_list|,
name|hash_head
argument_list|)
expr_stmt|;
comment|/* strstart never exceeds WSIZE-MAX_MATCH, so there are                  * always MIN_MATCH bytes ahead. If lookahead< MIN_MATCH                  * these bytes are garbage, but it does not matter since the                  * next lookahead bytes will always be emitted as literals.                  */
block|}
do|while
condition|(
operator|--
name|prev_length
operator|!=
literal|0
condition|)
do|;
name|match_available
operator|=
literal|0
expr_stmt|;
name|match_length
operator|=
name|MIN_MATCH
operator|-
literal|1
expr_stmt|;
name|strstart
operator|++
expr_stmt|;
if|if
condition|(
name|flush
condition|)
name|FLUSH_BLOCK
argument_list|(
literal|0
argument_list|)
operator|,
name|block_start
operator|=
name|strstart
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|match_available
condition|)
block|{
comment|/* If there was no match at the previous position, output a              * single literal. If there was a match but the current match              * is longer, truncate the previous match to a single literal.              */
name|Tracevv
argument_list|(
operator|(
name|stderr
operator|,
literal|"%c"
operator|,
name|window
index|[
name|strstart
operator|-
literal|1
index|]
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ct_tally
argument_list|(
literal|0
argument_list|,
name|window
index|[
name|strstart
operator|-
literal|1
index|]
argument_list|)
condition|)
block|{
name|FLUSH_BLOCK
argument_list|(
literal|0
argument_list|)
operator|,
name|block_start
operator|=
name|strstart
expr_stmt|;
block|}
name|strstart
operator|++
expr_stmt|;
name|lookahead
operator|--
expr_stmt|;
block|}
else|else
block|{
comment|/* There is no previous match to compare with, wait for              * the next step to decide.              */
name|match_available
operator|=
literal|1
expr_stmt|;
name|strstart
operator|++
expr_stmt|;
name|lookahead
operator|--
expr_stmt|;
block|}
name|Assert
argument_list|(
name|strstart
operator|<=
name|isize
operator|&&
name|lookahead
operator|<=
name|isize
argument_list|,
literal|"a bit too far"
argument_list|)
expr_stmt|;
comment|/* Make sure that we always have enough lookahead, except          * at the end of the input file. We need MAX_MATCH bytes          * for the next match, plus MIN_MATCH bytes to insert the          * string following the next match.          */
while|while
condition|(
name|lookahead
operator|<
name|MIN_LOOKAHEAD
operator|&&
operator|!
name|eofile
condition|)
name|fill_window
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|match_available
condition|)
name|ct_tally
argument_list|(
literal|0
argument_list|,
name|window
index|[
name|strstart
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
return|return
name|FLUSH_BLOCK
argument_list|(
literal|1
argument_list|)
return|;
comment|/* eof */
block|}
end_function

end_unit

