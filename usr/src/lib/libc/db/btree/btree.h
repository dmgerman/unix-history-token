begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Mike Olson.  *  * %sccs.include.redist.c%  *  *	@(#)btree.h	5.4 (Berkeley) %G%  */
end_comment

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
comment|/*  * There are five page layouts in the btree: btree internal pages (BINTERNAL),  * btree leaf pages (BLEAF), recno internal pages (RINTERNAL), recno leaf pages  * (RLEAF) and overflow pages.  All five page types have a page header (PAGE).  * This implementation requires that longs within structures are NOT padded.  * (ANSI C permits random padding.)  If your compiler pads randomly you'll have  * to do some work to get this package to run.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|PAGE
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
name|u_long
name|flags
decl_stmt|;
name|index_t
name|lower
decl_stmt|;
comment|/* lower bound of free space on page */
name|index_t
name|upper
decl_stmt|;
comment|/* upper bound of free space on page */
name|index_t
name|linp
index|[
literal|1
index|]
decl_stmt|;
comment|/* long-aligned VARIABLE LENGTH DATA */
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
value|(sizeof(PAGE) - sizeof(index_t))
end_define

begin_define
define|#
directive|define
name|NEXTINDEX
parameter_list|(
name|p
parameter_list|)
value|(((p)->lower - BTDATAOFF) / sizeof(index_t))
end_define

begin_comment
comment|/*  * For pages other than overflow pages, there is an array of offsets into the  * rest of the page immediately following the page header.  Each offset is to  * an item which is unique to the type of page.  The h_lower offset is just  * past the last filled-in index.  The h_upper offset is the first item on the  * page.  Offsets are from the beginning of the page.  *  * If an item is too big to store on a single page, a flag is set and the item  * is a { page, size } pair such that the page is the first page of an overflow  * chain with size bytes of item.  Overflow pages are simply bytes without any  * external structure.  *  * The size and page number fields in the items are long aligned so they can be  * manipulated without copying.  */
end_comment

begin_define
define|#
directive|define
name|LALIGN
parameter_list|(
name|n
parameter_list|)
value|(((n) + sizeof(u_long) - 1)& ~(sizeof(u_long) - 1))
end_define

begin_define
define|#
directive|define
name|NOVFLSIZE
value|(sizeof(pgno_t) + sizeof(size_t))
end_define

begin_comment
comment|/*  * For the btree internal pages, the item is a key.  BINTERNALs are {key, pgno}  * pairs, such that the key compares less than or equal to all of the records  * on that page.  For a tree without duplicate keys, an internal page with two  * consecutive keys, a and b, will have all records greater than or equal to a  * and less than b stored on the page associated with a.  Duplicate keys are  * somewhat special and can cause duplicate internal and leaf page records and  * some minor modifications of the above rule.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BINTERNAL
block|{
name|size_t
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
value|LALIGN(sizeof(size_t) + sizeof(pgno_t) + sizeof(u_char) + (len))
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
value|{ \ 	*((size_t *)p)++ = size; \ 	*((pgno_t *)p)++ = pgno; \ 	*((u_char *)p)++ = flags; \ }
end_define

begin_comment
comment|/*  * For the recno internal pages, the item is a page number with the number of  * keys found on that page and below.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|RINTERNAL
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
value|{ \ 	*((recno_t *)p)++ = nrecs; \ 	*(pgno_t *)p = pgno; \ }
end_define

begin_comment
comment|/* For the btree leaf pages, the item is a key and data pair. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BLEAF
block|{
name|size_t
name|ksize
decl_stmt|;
comment|/* size of key */
name|size_t
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
value|LALIGN(sizeof(size_t) + sizeof(size_t) + sizeof(u_char) + \ 	    (ksize) + (dsize))
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
value|{ \ 	*((size_t *)p)++ = key->size; \ 	*((size_t *)p)++ = data->size; \ 	*((u_char *)p)++ = flags; \ 	bcopy(key->data, p, key->size); \ 	p += key->size; \ 	bcopy(data->data, p, data->size); \ }
end_define

begin_comment
comment|/* For the recno leaf pages, the item is a data entry. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|RLEAF
block|{
name|size_t
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
value|LALIGN(sizeof(size_t) + sizeof(u_char) + (dsize))
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
value|{ \ 	*((size_t *)p)++ = data->size; \ 	*((u_char *)p)++ = flags; \ 	bcopy(data->data, p, data->size); \ }
end_define

begin_comment
comment|/*  * A record in the tree is either a pointer to a page and an index in the page  * or a page number and an index.  These structures are used as a cursor, stack  * entry and search returns as well as to pass records to other routines.  *  * One comment about searches.  Internal page searches must find the largest  * record less than key in the tree so that descents work.  Leaf page searches  * must find the smallest record greater than key so that the returned index  * is the record's correct position for insertion.  *  * One comment about cursors.  The cursor key is never removed from the tree,  * even if deleted.  This is because it is quite difficult to decide where the  * cursor should be when other keys have been inserted/deleted in the tree;  * duplicate keys make it impossible.  This scheme does require extra work  * though, to make sure that we don't perform an operation on a deleted key.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|EPGNO
block|{
name|pgno_t
name|pgno
decl_stmt|;
comment|/* the page number */
name|index_t
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
name|EPG
block|{
name|PAGE
modifier|*
name|page
decl_stmt|;
comment|/* the (pinned) page */
name|index_t
name|index
decl_stmt|;
comment|/* the index on the page */
block|}
name|EPG
typedef|;
end_typedef

begin_comment
comment|/*  * The metadata of the tree.  The m_nrecs field is used only by the RECNO code.  * This is because the btree doesn't really need it and it requires that every  * put or delete call modify the metadata.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BTMETA
block|{
name|u_long
name|m_magic
decl_stmt|;
comment|/* magic number */
name|u_long
name|m_version
decl_stmt|;
comment|/* version */
name|u_long
name|m_psize
decl_stmt|;
comment|/* page size */
name|u_long
name|m_free
decl_stmt|;
comment|/* page number of first free page */
name|u_long
name|m_nrecs
decl_stmt|;
comment|/* R: number of records */
define|#
directive|define
name|SAVEMETA
value|(BTF_NODUPS | BTF_RECNO)
name|u_long
name|m_flags
decl_stmt|;
comment|/* bt_flags& SAVEMETA */
name|u_long
name|m_lorder
decl_stmt|;
comment|/* byte order */
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
name|BTREE
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
name|EPGNO
name|bt_bcursor
decl_stmt|;
comment|/* B: btree cursor */
name|recno_t
name|bt_rcursor
decl_stmt|;
comment|/* R: recno cursor (1-based) */
define|#
directive|define
name|BT_POP
parameter_list|(
name|t
parameter_list|)
value|(t->bt_sp ? t->bt_stack + --t->bt_sp : NULL)
define|#
directive|define
name|BT_CLR
parameter_list|(
name|t
parameter_list|)
value|(t->bt_sp = 0)
name|EPGNO
modifier|*
name|bt_stack
decl_stmt|;
comment|/* stack of parent pages */
name|u_int
name|bt_sp
decl_stmt|;
comment|/* current stack pointer */
name|u_int
name|bt_maxstack
decl_stmt|;
comment|/* largest stack */
name|char
modifier|*
name|bt_kbuf
decl_stmt|;
comment|/* key buffer */
name|size_t
name|bt_kbufsz
decl_stmt|;
comment|/* key buffer size */
name|char
modifier|*
name|bt_dbuf
decl_stmt|;
comment|/* data buffer */
name|size_t
name|bt_dbufsz
decl_stmt|;
comment|/* data buffer size */
name|int
name|bt_fd
decl_stmt|;
comment|/* tree file descriptor */
name|FILE
modifier|*
name|bt_rfp
decl_stmt|;
comment|/* R: record FILE pointer */
name|int
name|bt_rfd
decl_stmt|;
comment|/* R: record file descriptor */
name|pgno_t
name|bt_free
decl_stmt|;
comment|/* XXX next free page */
name|index_t
name|bt_psize
decl_stmt|;
comment|/* page size */
name|index_t
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
block|, }
name|bt_order
enum|;
name|EPGNO
name|bt_last
decl_stmt|;
comment|/* last insert */
comment|/* B: key comparison function */
name|int
argument_list|(
argument|*bt_cmp
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
name|DBT
operator|*
operator|,
specifier|const
name|DBT
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* B: prefix comparison function */
name|int
argument_list|(
argument|*bt_pfx
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
name|DBT
operator|*
operator|,
specifier|const
name|DBT
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* R: recno input function */
name|int
argument_list|(
argument|*bt_irec
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|BTREE
operator|*
operator|,
name|recno_t
operator|)
argument_list|)
expr_stmt|;
name|recno_t
name|bt_nrecs
decl_stmt|;
comment|/* R: number of records */
name|caddr_t
name|bt_smap
decl_stmt|;
comment|/* R: start of mapped space */
name|caddr_t
name|bt_emap
decl_stmt|;
comment|/* R: end of mapped space */
name|size_t
name|bt_reclen
decl_stmt|;
comment|/* R: fixed record length */
name|u_char
name|bt_bval
decl_stmt|;
comment|/* R: delimiting byte/pad character */
define|#
directive|define
name|BTF_DELCRSR
value|0x001
comment|/* cursor has been deleted */
define|#
directive|define
name|BTF_FIXEDLEN
value|0x002
comment|/* fixed length records */
define|#
directive|define
name|BTF_INMEM
value|0x004
comment|/* in-memory tree */
define|#
directive|define
name|BTF_METADIRTY
value|0x008
comment|/* B: need to write metadata */
define|#
directive|define
name|BTF_MODIFIED
value|0x010
comment|/* tree modified */
define|#
directive|define
name|BTF_NODUPS
value|0x020
comment|/* B: no duplicate keys permitted */
define|#
directive|define
name|BTF_RDONLY
value|0x040
comment|/* read-only tree */
define|#
directive|define
name|BTF_RECNO
value|0x080
comment|/* record oriented tree */
define|#
directive|define
name|BTF_SEQINIT
value|0x100
comment|/* sequential scan initialized */
name|u_long
name|bt_flags
decl_stmt|;
comment|/* btree state */
block|}
name|BTREE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISSET
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|)
value|((t)->bt_flags& (f))
end_define

begin_define
define|#
directive|define
name|NOTSET
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|)
value|(!((t)->bt_flags& (f)))
end_define

begin_define
define|#
directive|define
name|SET
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|)
value|((t)->bt_flags |= (f))
end_define

begin_define
define|#
directive|define
name|UNSET
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|)
value|((t)->bt_flags&= ~(f))
end_define

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

