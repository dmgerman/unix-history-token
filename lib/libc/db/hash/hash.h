begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Margo Seltzer.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)hash.h	8.3 (Berkeley) 5/31/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Operations */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HASH_GET
block|,
name|HASH_PUT
block|,
name|HASH_PUTNEW
block|,
name|HASH_DELETE
block|,
name|HASH_FIRST
block|,
name|HASH_NEXT
block|}
name|ACTION
typedef|;
end_typedef

begin_comment
comment|/* Buffer Management structures */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_bufhead
name|BUFHEAD
typedef|;
end_typedef

begin_struct
struct|struct
name|_bufhead
block|{
name|BUFHEAD
modifier|*
name|prev
decl_stmt|;
comment|/* LRU links */
name|BUFHEAD
modifier|*
name|next
decl_stmt|;
comment|/* LRU links */
name|BUFHEAD
modifier|*
name|ovfl
decl_stmt|;
comment|/* Overflow page buffer header */
name|u_int32_t
name|addr
decl_stmt|;
comment|/* Address of this page */
name|char
modifier|*
name|page
decl_stmt|;
comment|/* Actual page data */
name|char
name|flags
decl_stmt|;
define|#
directive|define
name|BUF_MOD
value|0x0001
define|#
directive|define
name|BUF_DISK
value|0x0002
define|#
directive|define
name|BUF_BUCKET
value|0x0004
define|#
directive|define
name|BUF_PIN
value|0x0008
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IS_BUCKET
parameter_list|(
name|X
parameter_list|)
value|((X)& BUF_BUCKET)
end_define

begin_typedef
typedef|typedef
name|BUFHEAD
modifier|*
modifier|*
name|SEGMENT
typedef|;
end_typedef

begin_comment
comment|/* Hash Table Information */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hashhdr
block|{
comment|/* Disk resident portion */
name|int
name|magic
decl_stmt|;
comment|/* Magic NO for hash tables */
name|int
name|version
decl_stmt|;
comment|/* Version ID */
name|u_int32_t
name|lorder
decl_stmt|;
comment|/* Byte Order */
name|int
name|bsize
decl_stmt|;
comment|/* Bucket/Page Size */
name|int
name|bshift
decl_stmt|;
comment|/* Bucket shift */
name|int
name|dsize
decl_stmt|;
comment|/* Directory Size */
name|int
name|ssize
decl_stmt|;
comment|/* Segment Size */
name|int
name|sshift
decl_stmt|;
comment|/* Segment shift */
name|int
name|ovfl_point
decl_stmt|;
comment|/* Where overflow pages are being  					 * allocated */
name|int
name|last_freed
decl_stmt|;
comment|/* Last overflow page freed */
name|int
name|max_bucket
decl_stmt|;
comment|/* ID of Maximum bucket in use */
name|int
name|high_mask
decl_stmt|;
comment|/* Mask to modulo into entire table */
name|int
name|low_mask
decl_stmt|;
comment|/* Mask to modulo into lower half of  					 * table */
name|int
name|ffactor
decl_stmt|;
comment|/* Fill factor */
name|int
name|nkeys
decl_stmt|;
comment|/* Number of keys in hash table */
name|int
name|hdrpages
decl_stmt|;
comment|/* Size of table header */
name|int
name|h_charkey
decl_stmt|;
comment|/* value of hash(CHARKEY) */
define|#
directive|define
name|NCACHED
value|32
comment|/* number of bit maps and spare  					 * points */
name|int
name|spares
index|[
name|NCACHED
index|]
decl_stmt|;
comment|/* spare pages for overflow */
name|u_int16_t
name|bitmaps
index|[
name|NCACHED
index|]
decl_stmt|;
comment|/* address of overflow page  						 * bitmaps */
block|}
name|HASHHDR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|htab
block|{
comment|/* Memory resident data structure */
name|HASHHDR
name|hdr
decl_stmt|;
comment|/* Header */
name|int
name|nsegs
decl_stmt|;
comment|/* Number of allocated segments */
name|int
name|exsegs
decl_stmt|;
comment|/* Number of extra allocated  					 * segments */
name|u_int32_t
comment|/* Hash function */
function_decl|(
modifier|*
name|hash
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|int
name|flags
decl_stmt|;
comment|/* Flag values */
name|int
name|fp
decl_stmt|;
comment|/* File pointer */
name|char
modifier|*
name|tmp_buf
decl_stmt|;
comment|/* Temporary Buffer for BIG data */
name|char
modifier|*
name|tmp_key
decl_stmt|;
comment|/* Temporary Buffer for BIG keys */
name|BUFHEAD
modifier|*
name|cpage
decl_stmt|;
comment|/* Current page */
name|int
name|cbucket
decl_stmt|;
comment|/* Current bucket */
name|int
name|cndx
decl_stmt|;
comment|/* Index of next item on cpage */
name|int
name|error
decl_stmt|;
comment|/* Error Number -- for DBM  					 * compatibility */
name|int
name|new_file
decl_stmt|;
comment|/* Indicates if fd is backing store  					 * or no */
name|int
name|save_file
decl_stmt|;
comment|/* Indicates whether we need to flush  					 * file at 					 * exit */
name|u_int32_t
modifier|*
name|mapp
index|[
name|NCACHED
index|]
decl_stmt|;
comment|/* Pointers to page maps */
name|int
name|nmaps
decl_stmt|;
comment|/* Initial number of bitmaps */
name|int
name|nbufs
decl_stmt|;
comment|/* Number of buffers left to  					 * allocate */
name|BUFHEAD
name|bufhead
decl_stmt|;
comment|/* Header of buffer lru list */
name|SEGMENT
modifier|*
name|dir
decl_stmt|;
comment|/* Hash Bucket directory */
block|}
name|HTAB
typedef|;
end_typedef

begin_comment
comment|/*  * Constants  */
end_comment

begin_define
define|#
directive|define
name|MAX_BSIZE
value|65536
end_define

begin_comment
comment|/* 2^16 */
end_comment

begin_define
define|#
directive|define
name|MIN_BUFFERS
value|6
end_define

begin_define
define|#
directive|define
name|MINHDRSIZE
value|512
end_define

begin_define
define|#
directive|define
name|DEF_BUFSIZE
value|65536
end_define

begin_comment
comment|/* 64 K */
end_comment

begin_define
define|#
directive|define
name|DEF_BUCKET_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|DEF_BUCKET_SHIFT
value|12
end_define

begin_comment
comment|/* log2(BUCKET) */
end_comment

begin_define
define|#
directive|define
name|DEF_SEGSIZE
value|256
end_define

begin_define
define|#
directive|define
name|DEF_SEGSIZE_SHIFT
value|8
end_define

begin_comment
comment|/* log2(SEGSIZE)	 */
end_comment

begin_define
define|#
directive|define
name|DEF_DIRSIZE
value|256
end_define

begin_define
define|#
directive|define
name|DEF_FFACTOR
value|65536
end_define

begin_define
define|#
directive|define
name|MIN_FFACTOR
value|4
end_define

begin_define
define|#
directive|define
name|SPLTMAX
value|8
end_define

begin_define
define|#
directive|define
name|CHARKEY
value|"%$sniglet^&"
end_define

begin_define
define|#
directive|define
name|NUMKEY
value|1038583
end_define

begin_define
define|#
directive|define
name|BYTE_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|INT_TO_BYTE
value|2
end_define

begin_define
define|#
directive|define
name|INT_BYTE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|ALL_SET
value|((u_int32_t)0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|ALL_CLEAR
value|0
end_define

begin_define
define|#
directive|define
name|PTROF
parameter_list|(
name|X
parameter_list|)
value|((BUFHEAD *)((ptrdiff_t)(X)&~0x3))
end_define

begin_define
define|#
directive|define
name|ISMOD
parameter_list|(
name|X
parameter_list|)
value|((u_int32_t)(ptrdiff_t)(X)&0x1)
end_define

begin_define
define|#
directive|define
name|DOMOD
parameter_list|(
name|X
parameter_list|)
value|((X) = (char *)((ptrdiff_t)(X)|0x1))
end_define

begin_define
define|#
directive|define
name|ISDISK
parameter_list|(
name|X
parameter_list|)
value|((u_int32_t)(ptrdiff_t)(X)&0x2)
end_define

begin_define
define|#
directive|define
name|DODISK
parameter_list|(
name|X
parameter_list|)
value|((X) = (char *)((ptrdiff_t)(X)|0x2))
end_define

begin_define
define|#
directive|define
name|BITS_PER_MAP
value|32
end_define

begin_comment
comment|/* Given the address of the beginning of a big map, clear/set the nth bit */
end_comment

begin_define
define|#
directive|define
name|CLRBIT
parameter_list|(
name|A
parameter_list|,
name|N
parameter_list|)
value|((A)[(N)/BITS_PER_MAP]&= ~(1<<((N)%BITS_PER_MAP)))
end_define

begin_define
define|#
directive|define
name|SETBIT
parameter_list|(
name|A
parameter_list|,
name|N
parameter_list|)
value|((A)[(N)/BITS_PER_MAP] |= (1<<((N)%BITS_PER_MAP)))
end_define

begin_define
define|#
directive|define
name|ISSET
parameter_list|(
name|A
parameter_list|,
name|N
parameter_list|)
value|((A)[(N)/BITS_PER_MAP]& (1<<((N)%BITS_PER_MAP)))
end_define

begin_comment
comment|/* Overflow management */
end_comment

begin_comment
comment|/*  * Overflow page numbers are allocated per split point.  At each doubling of  * the table, we can allocate extra pages.  So, an overflow page number has  * the top 5 bits indicate which split point and the lower 11 bits indicate  * which page at that split point is indicated (pages within split points are  * numberered starting with 1).  */
end_comment

begin_define
define|#
directive|define
name|SPLITSHIFT
value|11
end_define

begin_define
define|#
directive|define
name|SPLITMASK
value|0x7FF
end_define

begin_define
define|#
directive|define
name|SPLITNUM
parameter_list|(
name|N
parameter_list|)
value|(((u_int32_t)(N))>> SPLITSHIFT)
end_define

begin_define
define|#
directive|define
name|OPAGENUM
parameter_list|(
name|N
parameter_list|)
value|((N)& SPLITMASK)
end_define

begin_define
define|#
directive|define
name|OADDR_OF
parameter_list|(
name|S
parameter_list|,
name|O
parameter_list|)
value|((u_int32_t)((u_int32_t)(S)<< SPLITSHIFT) + (O))
end_define

begin_define
define|#
directive|define
name|BUCKET_TO_PAGE
parameter_list|(
name|B
parameter_list|)
define|\
value|(B) + hashp->HDRPAGES + ((B) ? hashp->SPARES[__log2((B)+1)-1] : 0)
end_define

begin_define
define|#
directive|define
name|OADDR_TO_PAGE
parameter_list|(
name|B
parameter_list|)
define|\
value|BUCKET_TO_PAGE ( (1<< SPLITNUM((B))) -1 ) + OPAGENUM((B));
end_define

begin_comment
comment|/*  * page.h contains a detailed description of the page format.  *  * Normally, keys and data are accessed from offset tables in the top of  * each page which point to the beginning of the key and data.  There are  * four flag values which may be stored in these offset tables which indicate  * the following:  *  *  * OVFLPAGE	Rather than a key data pair, this pair contains  *		the address of an overflow page.  The format of  *		the pair is:  *		    OVERFLOW_PAGE_NUMBER OVFLPAGE  *  * PARTIAL_KEY	This must be the first key/data pair on a page  *		and implies that page contains only a partial key.  *		That is, the key is too big to fit on a single page  *		so it starts on this page and continues on the next.  *		The format of the page is:  *		    KEY_OFF PARTIAL_KEY OVFL_PAGENO OVFLPAGE  *  *		    KEY_OFF -- offset of the beginning of the key  *		    PARTIAL_KEY -- 1  *		    OVFL_PAGENO - page number of the next overflow page  *		    OVFLPAGE -- 0  *  * FULL_KEY	This must be the first key/data pair on the page.  It  *		is used in two cases.  *  *		Case 1:  *		    There is a complete key on the page but no data  *		    (because it wouldn't fit).  The next page contains  *		    the data.  *  *		    Page format it:  *		    KEY_OFF FULL_KEY OVFL_PAGENO OVFL_PAGE  *  *		    KEY_OFF -- offset of the beginning of the key  *		    FULL_KEY -- 2  *		    OVFL_PAGENO - page number of the next overflow page  *		    OVFLPAGE -- 0  *  *		Case 2:  *		    This page contains no key, but part of a large  *		    data field, which is continued on the next page.  *  *		    Page format it:  *		    DATA_OFF FULL_KEY OVFL_PAGENO OVFL_PAGE  *  *		    KEY_OFF -- offset of the beginning of the data on  *				this page  *		    FULL_KEY -- 2  *		    OVFL_PAGENO - page number of the next overflow page  *		    OVFLPAGE -- 0  *  * FULL_KEY_DATA  *		This must be the first key/data pair on the page.  *		There are two cases:  *  *		Case 1:  *		    This page contains a key and the beginning of the  *		    data field, but the data field is continued on the  *		    next page.  *  *		    Page format is:  *		    KEY_OFF FULL_KEY_DATA OVFL_PAGENO DATA_OFF  *  *		    KEY_OFF -- offset of the beginning of the key  *		    FULL_KEY_DATA -- 3  *		    OVFL_PAGENO - page number of the next overflow page  *		    DATA_OFF -- offset of the beginning of the data  *  *		Case 2:  *		    This page contains the last page of a big data pair.  *		    There is no key, only the  tail end of the data  *		    on this page.  *  *		    Page format is:  *		    DATA_OFF FULL_KEY_DATA<OVFL_PAGENO><OVFLPAGE>  *  *		    DATA_OFF -- offset of the beginning of the data on  *				this page  *		    FULL_KEY_DATA -- 3  *		    OVFL_PAGENO - page number of the next overflow page  *		    OVFLPAGE -- 0  *  *		    OVFL_PAGENO and OVFLPAGE are optional (they are  *		    not present if there is no next page).  */
end_comment

begin_define
define|#
directive|define
name|OVFLPAGE
value|0
end_define

begin_define
define|#
directive|define
name|PARTIAL_KEY
value|1
end_define

begin_define
define|#
directive|define
name|FULL_KEY
value|2
end_define

begin_define
define|#
directive|define
name|FULL_KEY_DATA
value|3
end_define

begin_define
define|#
directive|define
name|REAL_KEY
value|4
end_define

begin_comment
comment|/* Short hands for accessing structure */
end_comment

begin_define
define|#
directive|define
name|BSIZE
value|hdr.bsize
end_define

begin_define
define|#
directive|define
name|BSHIFT
value|hdr.bshift
end_define

begin_define
define|#
directive|define
name|DSIZE
value|hdr.dsize
end_define

begin_define
define|#
directive|define
name|SGSIZE
value|hdr.ssize
end_define

begin_define
define|#
directive|define
name|SSHIFT
value|hdr.sshift
end_define

begin_define
define|#
directive|define
name|LORDER
value|hdr.lorder
end_define

begin_define
define|#
directive|define
name|OVFL_POINT
value|hdr.ovfl_point
end_define

begin_define
define|#
directive|define
name|LAST_FREED
value|hdr.last_freed
end_define

begin_define
define|#
directive|define
name|MAX_BUCKET
value|hdr.max_bucket
end_define

begin_define
define|#
directive|define
name|FFACTOR
value|hdr.ffactor
end_define

begin_define
define|#
directive|define
name|HIGH_MASK
value|hdr.high_mask
end_define

begin_define
define|#
directive|define
name|LOW_MASK
value|hdr.low_mask
end_define

begin_define
define|#
directive|define
name|NKEYS
value|hdr.nkeys
end_define

begin_define
define|#
directive|define
name|HDRPAGES
value|hdr.hdrpages
end_define

begin_define
define|#
directive|define
name|SPARES
value|hdr.spares
end_define

begin_define
define|#
directive|define
name|BITMAPS
value|hdr.bitmaps
end_define

begin_define
define|#
directive|define
name|VERSION
value|hdr.version
end_define

begin_define
define|#
directive|define
name|MAGIC
value|hdr.magic
end_define

begin_define
define|#
directive|define
name|NEXT_FREE
value|hdr.next_free
end_define

begin_define
define|#
directive|define
name|H_CHARKEY
value|hdr.h_charkey
end_define

end_unit

