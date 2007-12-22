begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Mike Olson.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)btree.h	8.11 (Berkeley) 8/17/94  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Macros to set/clear/test flags. */
end_comment

begin_define
define|#
directive|define
name|F_SET
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|(p)->flags |= (f)
end_define

begin_define
define|#
directive|define
name|F_CLR
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|(p)->flags&= ~(f)
end_define

begin_define
define|#
directive|define
name|F_ISSET
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|)
value|((p)->flags& (f))
end_define

begin_include
include|#
directive|include
file|<mpool.h>
end_include

begin_define
define|#
directive|define
name|DEFMINKEYPAGE
value|(2)
end_define

begin_comment
comment|/* Minimum keys per page */
end_comment

begin_define
define|#
directive|define
name|MINCACHE
value|(5)
end_define

begin_comment
comment|/* Minimum cached pages */
end_comment

begin_define
define|#
directive|define
name|MINPSIZE
value|(512)
end_define

begin_comment
comment|/* Minimum page size */
end_comment

begin_comment
comment|/*  * Page 0 of a btree file contains a copy of the meta-data.  This page is also  * used as an out-of-band page, i.e. page pointers that point to nowhere point  * to page 0.  Page 1 is the root of the btree.  */
end_comment

begin_define
define|#
directive|define
name|P_INVALID
value|0
end_define

begin_comment
comment|/* Invalid tree page number. */
end_comment

begin_define
define|#
directive|define
name|P_META
value|0
end_define

begin_comment
comment|/* Tree metadata page number. */
end_comment

begin_define
define|#
directive|define
name|P_ROOT
value|1
end_define

begin_comment
comment|/* Tree root page number. */
end_comment

begin_comment
comment|/*  * There are five page layouts in the btree: btree internal pages (BINTERNAL),  * btree leaf pages (BLEAF), recno internal pages (RINTERNAL), recno leaf pages  * (RLEAF) and overflow pages.  All five page types have a page header (PAGE).  * This implementation requires that values within structures NOT be padded.  * (ANSI C permits random padding.)  If your compiler pads randomly you'll have  * to do some work to get this package to run.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_page
block|{
name|pgno_t
name|pgno
decl_stmt|;
comment|/* this page's page number */
name|pgno_t
name|prevpg
decl_stmt|;
comment|/* left sibling */
name|pgno_t
name|nextpg
decl_stmt|;
comment|/* right sibling */
define|#
directive|define
name|P_BINTERNAL
value|0x01
comment|/* btree internal page */
define|#
directive|define
name|P_BLEAF
value|0x02
comment|/* leaf page */
define|#
directive|define
name|P_OVERFLOW
value|0x04
comment|/* overflow page */
define|#
directive|define
name|P_RINTERNAL
value|0x08
comment|/* recno internal page */
define|#
directive|define
name|P_RLEAF
value|0x10
comment|/* leaf page */
define|#
directive|define
name|P_TYPE
value|0x1f
comment|/* type mask */
define|#
directive|define
name|P_PRESERVE
value|0x20
comment|/* never delete this chain of pages */
name|u_int32_t
name|flags
decl_stmt|;
name|indx_t
name|lower
decl_stmt|;
comment|/* lower bound of free space on page */
name|indx_t
name|upper
decl_stmt|;
comment|/* upper bound of free space on page */
name|indx_t
name|linp
index|[
literal|1
index|]
decl_stmt|;
comment|/* indx_t-aligned VAR. LENGTH DATA */
block|}
name|PAGE
typedef|;
end_typedef

begin_comment
comment|/* First and next index. */
end_comment

begin_define
define|#
directive|define
name|BTDATAOFF
define|\
value|(sizeof(pgno_t) + sizeof(pgno_t) + sizeof(pgno_t) +		\ 	    sizeof(u_int32_t) + sizeof(indx_t) + sizeof(indx_t))
end_define

begin_define
define|#
directive|define
name|NEXTINDEX
parameter_list|(
name|p
parameter_list|)
value|(((p)->lower - BTDATAOFF) / sizeof(indx_t))
end_define

begin_comment
comment|/*  * For pages other than overflow pages, there is an array of offsets into the  * rest of the page immediately following the page header.  Each offset is to  * an item which is unique to the type of page.  The h_lower offset is just  * past the last filled-in index.  The h_upper offset is the first item on the  * page.  Offsets are from the beginning of the page.  *  * If an item is too big to store on a single page, a flag is set and the item  * is a { page, size } pair such that the page is the first page of an overflow  * chain with size bytes of item.  Overflow pages are simply bytes without any  * external structure.  *  * The page number and size fields in the items are pgno_t-aligned so they can  * be manipulated without copying.  (This presumes that 32 bit items can be  * manipulated on this system.)  */
end_comment

begin_define
define|#
directive|define
name|LALIGN
parameter_list|(
name|n
parameter_list|)
value|(((n) + sizeof(pgno_t) - 1)& ~(sizeof(pgno_t) - 1))
end_define

begin_define
define|#
directive|define
name|NOVFLSIZE
value|(sizeof(pgno_t) + sizeof(u_int32_t))
end_define

begin_comment
comment|/*  * For the btree internal pages, the item is a key.  BINTERNALs are {key, pgno}  * pairs, such that the key compares less than or equal to all of the records  * on that page.  For a tree without duplicate keys, an internal page with two  * consecutive keys, a and b, will have all records greater than or equal to a  * and less than b stored on the page associated with a.  Duplicate keys are  * somewhat special and can cause duplicate internal and leaf page records and  * some minor modifications of the above rule.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_binternal
block|{
name|u_int32_t
name|ksize
decl_stmt|;
comment|/* key size */
name|pgno_t
name|pgno
decl_stmt|;
comment|/* page number stored on */
define|#
directive|define
name|P_BIGDATA
value|0x01
comment|/* overflow data */
define|#
directive|define
name|P_BIGKEY
value|0x02
comment|/* overflow key */
name|u_char
name|flags
decl_stmt|;
name|char
name|bytes
index|[
literal|1
index|]
decl_stmt|;
comment|/* data */
block|}
name|BINTERNAL
typedef|;
end_typedef

begin_comment
comment|/* Get the page's BINTERNAL structure at index indx. */
end_comment

begin_define
define|#
directive|define
name|GETBINTERNAL
parameter_list|(
name|pg
parameter_list|,
name|indx
parameter_list|)
define|\
value|((BINTERNAL *)((char *)(pg) + (pg)->linp[indx]))
end_define

begin_comment
comment|/* Get the number of bytes in the entry. */
end_comment

begin_define
define|#
directive|define
name|NBINTERNAL
parameter_list|(
name|len
parameter_list|)
define|\
value|LALIGN(sizeof(u_int32_t) + sizeof(pgno_t) + sizeof(u_char) + (len))
end_define

begin_comment
comment|/* Copy a BINTERNAL entry to the page. */
end_comment

begin_define
define|#
directive|define
name|WR_BINTERNAL
parameter_list|(
name|p
parameter_list|,
name|size
parameter_list|,
name|pgno
parameter_list|,
name|flags
parameter_list|)
value|{				\ 	*(u_int32_t *)p = size;						\ 	p += sizeof(u_int32_t);						\ 	*(pgno_t *)p = pgno;						\ 	p += sizeof(pgno_t);						\ 	*(u_char *)p = flags;						\ 	p += sizeof(u_char);						\ }
end_define

begin_comment
comment|/*  * For the recno internal pages, the item is a page number with the number of  * keys found on that page and below.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_rinternal
block|{
name|recno_t
name|nrecs
decl_stmt|;
comment|/* number of records */
name|pgno_t
name|pgno
decl_stmt|;
comment|/* page number stored below */
block|}
name|RINTERNAL
typedef|;
end_typedef

begin_comment
comment|/* Get the page's RINTERNAL structure at index indx. */
end_comment

begin_define
define|#
directive|define
name|GETRINTERNAL
parameter_list|(
name|pg
parameter_list|,
name|indx
parameter_list|)
define|\
value|((RINTERNAL *)((char *)(pg) + (pg)->linp[indx]))
end_define

begin_comment
comment|/* Get the number of bytes in the entry. */
end_comment

begin_define
define|#
directive|define
name|NRINTERNAL
define|\
value|LALIGN(sizeof(recno_t) + sizeof(pgno_t))
end_define

begin_comment
comment|/* Copy a RINTERAL entry to the page. */
end_comment

begin_define
define|#
directive|define
name|WR_RINTERNAL
parameter_list|(
name|p
parameter_list|,
name|nrecs
parameter_list|,
name|pgno
parameter_list|)
value|{					\ 	*(recno_t *)p = nrecs;						\ 	p += sizeof(recno_t);						\ 	*(pgno_t *)p = pgno;						\ }
end_define

begin_comment
comment|/* For the btree leaf pages, the item is a key and data pair. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_bleaf
block|{
name|u_int32_t
name|ksize
decl_stmt|;
comment|/* size of key */
name|u_int32_t
name|dsize
decl_stmt|;
comment|/* size of data */
name|u_char
name|flags
decl_stmt|;
comment|/* P_BIGDATA, P_BIGKEY */
name|char
name|bytes
index|[
literal|1
index|]
decl_stmt|;
comment|/* data */
block|}
name|BLEAF
typedef|;
end_typedef

begin_comment
comment|/* Get the page's BLEAF structure at index indx. */
end_comment

begin_define
define|#
directive|define
name|GETBLEAF
parameter_list|(
name|pg
parameter_list|,
name|indx
parameter_list|)
define|\
value|((BLEAF *)((char *)(pg) + (pg)->linp[indx]))
end_define

begin_comment
comment|/* Get the number of bytes in the entry. */
end_comment

begin_define
define|#
directive|define
name|NBLEAF
parameter_list|(
name|p
parameter_list|)
value|NBLEAFDBT((p)->ksize, (p)->dsize)
end_define

begin_comment
comment|/* Get the number of bytes in the user's key/data pair. */
end_comment

begin_define
define|#
directive|define
name|NBLEAFDBT
parameter_list|(
name|ksize
parameter_list|,
name|dsize
parameter_list|)
define|\
value|LALIGN(sizeof(u_int32_t) + sizeof(u_int32_t) + sizeof(u_char) +	\ 	    (ksize) + (dsize))
end_define

begin_comment
comment|/* Copy a BLEAF entry to the page. */
end_comment

begin_define
define|#
directive|define
name|WR_BLEAF
parameter_list|(
name|p
parameter_list|,
name|key
parameter_list|,
name|data
parameter_list|,
name|flags
parameter_list|)
value|{					\ 	*(u_int32_t *)p = key->size;					\ 	p += sizeof(u_int32_t);						\ 	*(u_int32_t *)p = data->size;					\ 	p += sizeof(u_int32_t);						\ 	*(u_char *)p = flags;						\ 	p += sizeof(u_char);						\ 	memmove(p, key->data, key->size);				\ 	p += key->size;							\ 	memmove(p, data->data, data->size);				\ }
end_define

begin_comment
comment|/* For the recno leaf pages, the item is a data entry. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_rleaf
block|{
name|u_int32_t
name|dsize
decl_stmt|;
comment|/* size of data */
name|u_char
name|flags
decl_stmt|;
comment|/* P_BIGDATA */
name|char
name|bytes
index|[
literal|1
index|]
decl_stmt|;
block|}
name|RLEAF
typedef|;
end_typedef

begin_comment
comment|/* Get the page's RLEAF structure at index indx. */
end_comment

begin_define
define|#
directive|define
name|GETRLEAF
parameter_list|(
name|pg
parameter_list|,
name|indx
parameter_list|)
define|\
value|((RLEAF *)((char *)(pg) + (pg)->linp[indx]))
end_define

begin_comment
comment|/* Get the number of bytes in the entry. */
end_comment

begin_define
define|#
directive|define
name|NRLEAF
parameter_list|(
name|p
parameter_list|)
value|NRLEAFDBT((p)->dsize)
end_define

begin_comment
comment|/* Get the number of bytes from the user's data. */
end_comment

begin_define
define|#
directive|define
name|NRLEAFDBT
parameter_list|(
name|dsize
parameter_list|)
define|\
value|LALIGN(sizeof(u_int32_t) + sizeof(u_char) + (dsize))
end_define

begin_comment
comment|/* Copy a RLEAF entry to the page. */
end_comment

begin_define
define|#
directive|define
name|WR_RLEAF
parameter_list|(
name|p
parameter_list|,
name|data
parameter_list|,
name|flags
parameter_list|)
value|{					\ 	*(u_int32_t *)p = data->size;					\ 	p += sizeof(u_int32_t);						\ 	*(u_char *)p = flags;						\ 	p += sizeof(u_char);						\ 	memmove(p, data->data, data->size);				\ }
end_define

begin_comment
comment|/*  * A record in the tree is either a pointer to a page and an index in the page  * or a page number and an index.  These structures are used as a cursor, stack  * entry and search returns as well as to pass records to other routines.  *  * One comment about searches.  Internal page searches must find the largest  * record less than key in the tree so that descents work.  Leaf page searches  * must find the smallest record greater than key so that the returned index  * is the record's correct position for insertion.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_epgno
block|{
name|pgno_t
name|pgno
decl_stmt|;
comment|/* the page number */
name|indx_t
name|index
decl_stmt|;
comment|/* the index on the page */
block|}
name|EPGNO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_epg
block|{
name|PAGE
modifier|*
name|page
decl_stmt|;
comment|/* the (pinned) page */
name|indx_t
name|index
decl_stmt|;
comment|/* the index on the page */
block|}
name|EPG
typedef|;
end_typedef

begin_comment
comment|/*  * About cursors.  The cursor (and the page that contained the key/data pair  * that it referenced) can be deleted, which makes things a bit tricky.  If  * there are no duplicates of the cursor key in the tree (i.e. B_NODUPS is set  * or there simply aren't any duplicates of the key) we copy the key that it  * referenced when it's deleted, and reacquire a new cursor key if the cursor  * is used again.  If there are duplicates keys, we move to the next/previous  * key, and set a flag so that we know what happened.  NOTE: if duplicate (to  * the cursor) keys are added to the tree during this process, it is undefined  * if they will be returned or not in a cursor scan.  *  * The flags determine the possible states of the cursor:  *  * CURS_INIT	The cursor references *something*.  * CURS_ACQUIRE	The cursor was deleted, and a key has been saved so that  *		we can reacquire the right position in the tree.  * CURS_AFTER, CURS_BEFORE  *		The cursor was deleted, and now references a key/data pair  *		that has not yet been returned, either before or after the  *		deleted key/data pair.  * XXX  * This structure is broken out so that we can eventually offer multiple  * cursors as part of the DB interface.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_cursor
block|{
name|EPGNO
name|pg
decl_stmt|;
comment|/* B: Saved tree reference. */
name|DBT
name|key
decl_stmt|;
comment|/* B: Saved key, or key.data == NULL. */
name|recno_t
name|rcursor
decl_stmt|;
comment|/* R: recno cursor (1-based) */
define|#
directive|define
name|CURS_ACQUIRE
value|0x01
comment|/*  B: Cursor needs to be reacquired. */
define|#
directive|define
name|CURS_AFTER
value|0x02
comment|/*  B: Unreturned cursor after key. */
define|#
directive|define
name|CURS_BEFORE
value|0x04
comment|/*  B: Unreturned cursor before key. */
define|#
directive|define
name|CURS_INIT
value|0x08
comment|/* RB: Cursor initialized. */
name|u_int8_t
name|flags
decl_stmt|;
block|}
name|CURSOR
typedef|;
end_typedef

begin_comment
comment|/*  * The metadata of the tree.  The nrecs field is used only by the RECNO code.  * This is because the btree doesn't really need it and it requires that every  * put or delete call modify the metadata.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_btmeta
block|{
name|u_int32_t
name|magic
decl_stmt|;
comment|/* magic number */
name|u_int32_t
name|version
decl_stmt|;
comment|/* version */
name|u_int32_t
name|psize
decl_stmt|;
comment|/* page size */
name|u_int32_t
name|free
decl_stmt|;
comment|/* page number of first free page */
name|u_int32_t
name|nrecs
decl_stmt|;
comment|/* R: number of records */
define|#
directive|define
name|SAVEMETA
value|(B_NODUPS | R_RECNO)
name|u_int32_t
name|flags
decl_stmt|;
comment|/* bt_flags& SAVEMETA */
block|}
name|BTMETA
typedef|;
end_typedef

begin_comment
comment|/* The in-memory btree/recno data structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_btree
block|{
name|MPOOL
modifier|*
name|bt_mp
decl_stmt|;
comment|/* memory pool cookie */
name|DB
modifier|*
name|bt_dbp
decl_stmt|;
comment|/* pointer to enclosing DB */
name|EPG
name|bt_cur
decl_stmt|;
comment|/* current (pinned) page */
name|PAGE
modifier|*
name|bt_pinned
decl_stmt|;
comment|/* page pinned across calls */
name|CURSOR
name|bt_cursor
decl_stmt|;
comment|/* cursor */
define|#
directive|define
name|BT_PUSH
parameter_list|(
name|t
parameter_list|,
name|p
parameter_list|,
name|i
parameter_list|)
value|{						\ 	t->bt_sp->pgno = p; 						\ 	t->bt_sp->index = i; 						\ 	++t->bt_sp;							\ }
define|#
directive|define
name|BT_POP
parameter_list|(
name|t
parameter_list|)
value|(t->bt_sp == t->bt_stack ? NULL : --t->bt_sp)
define|#
directive|define
name|BT_CLR
parameter_list|(
name|t
parameter_list|)
value|(t->bt_sp = t->bt_stack)
name|EPGNO
name|bt_stack
index|[
literal|50
index|]
decl_stmt|;
comment|/* stack of parent pages */
name|EPGNO
modifier|*
name|bt_sp
decl_stmt|;
comment|/* current stack pointer */
name|DBT
name|bt_rkey
decl_stmt|;
comment|/* returned key */
name|DBT
name|bt_rdata
decl_stmt|;
comment|/* returned data */
name|int
name|bt_fd
decl_stmt|;
comment|/* tree file descriptor */
name|pgno_t
name|bt_free
decl_stmt|;
comment|/* next free page */
name|u_int32_t
name|bt_psize
decl_stmt|;
comment|/* page size */
name|indx_t
name|bt_ovflsize
decl_stmt|;
comment|/* cut-off for key/data overflow */
name|int
name|bt_lorder
decl_stmt|;
comment|/* byte order */
comment|/* sorted order */
enum|enum
block|{
name|NOT
block|,
name|BACK
block|,
name|FORWARD
block|}
name|bt_order
enum|;
name|EPGNO
name|bt_last
decl_stmt|;
comment|/* last insert */
comment|/* B: key comparison function */
name|int
function_decl|(
modifier|*
name|bt_cmp
function_decl|)
parameter_list|(
specifier|const
name|DBT
modifier|*
parameter_list|,
specifier|const
name|DBT
modifier|*
parameter_list|)
function_decl|;
comment|/* B: prefix comparison function */
name|size_t
function_decl|(
modifier|*
name|bt_pfx
function_decl|)
parameter_list|(
specifier|const
name|DBT
modifier|*
parameter_list|,
specifier|const
name|DBT
modifier|*
parameter_list|)
function_decl|;
comment|/* R: recno input function */
name|int
function_decl|(
modifier|*
name|bt_irec
function_decl|)
parameter_list|(
name|struct
name|_btree
modifier|*
parameter_list|,
name|recno_t
parameter_list|)
function_decl|;
name|FILE
modifier|*
name|bt_rfp
decl_stmt|;
comment|/* R: record FILE pointer */
name|int
name|bt_rfd
decl_stmt|;
comment|/* R: record file descriptor */
name|caddr_t
name|bt_cmap
decl_stmt|;
comment|/* R: current point in mapped space */
name|caddr_t
name|bt_smap
decl_stmt|;
comment|/* R: start of mapped space */
name|caddr_t
name|bt_emap
decl_stmt|;
comment|/* R: end of mapped space */
name|size_t
name|bt_msize
decl_stmt|;
comment|/* R: size of mapped region. */
name|recno_t
name|bt_nrecs
decl_stmt|;
comment|/* R: number of records */
name|size_t
name|bt_reclen
decl_stmt|;
comment|/* R: fixed record length */
name|u_char
name|bt_bval
decl_stmt|;
comment|/* R: delimiting byte/pad character */
comment|/*  * NB:  * B_NODUPS and R_RECNO are stored on disk, and may not be changed.  */
define|#
directive|define
name|B_INMEM
value|0x00001
comment|/* in-memory tree */
define|#
directive|define
name|B_METADIRTY
value|0x00002
comment|/* need to write metadata */
define|#
directive|define
name|B_MODIFIED
value|0x00004
comment|/* tree modified */
define|#
directive|define
name|B_NEEDSWAP
value|0x00008
comment|/* if byte order requires swapping */
define|#
directive|define
name|B_RDONLY
value|0x00010
comment|/* read-only tree */
define|#
directive|define
name|B_NODUPS
value|0x00020
comment|/* no duplicate keys permitted */
define|#
directive|define
name|R_RECNO
value|0x00080
comment|/* record oriented tree */
define|#
directive|define
name|R_CLOSEFP
value|0x00040
comment|/* opened a file pointer */
define|#
directive|define
name|R_EOF
value|0x00100
comment|/* end of input file reached. */
define|#
directive|define
name|R_FIXLEN
value|0x00200
comment|/* fixed length records */
define|#
directive|define
name|R_MEMMAPPED
value|0x00400
comment|/* memory mapped file. */
define|#
directive|define
name|R_INMEM
value|0x00800
comment|/* in-memory file */
define|#
directive|define
name|R_MODIFIED
value|0x01000
comment|/* modified file */
define|#
directive|define
name|R_RDONLY
value|0x02000
comment|/* read-only file */
define|#
directive|define
name|B_DB_LOCK
value|0x04000
comment|/* DB_LOCK specified. */
define|#
directive|define
name|B_DB_SHMEM
value|0x08000
comment|/* DB_SHMEM specified. */
define|#
directive|define
name|B_DB_TXN
value|0x10000
comment|/* DB_TXN specified. */
name|u_int32_t
name|flags
decl_stmt|;
block|}
name|BTREE
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

