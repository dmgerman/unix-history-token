begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Mike Olson.  *  * %sccs.include.redist.c%  */
end_comment

begin_comment
comment|/*  *  @(#)btree.h	5.2 (Berkeley) %G%  */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|BTREE
typedef|;
end_typedef

begin_comment
comment|/* should really be (void *) */
end_comment

begin_comment
comment|/* #define	DEBUG */
end_comment

begin_define
define|#
directive|define
name|RET_ERROR
value|-1
end_define

begin_define
define|#
directive|define
name|RET_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|RET_SPECIAL
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef TRUE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef NULL */
end_comment

begin_comment
comment|/* these are defined in lrucache.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|lruinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|lruget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|lrugetnew
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lrusync
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lruwrite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lrurelease
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|lrufree
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* these are defined here */
end_comment

begin_function_decl
specifier|extern
name|BTREE
name|bt_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bt_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bt_delete
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bt_get
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bt_put
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bt_seq
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|bt_sync
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  *  Private types.  What you choose for these depends on how big you  *  want to let files get, and how big you want to let pages get.  */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|index_t
typedef|;
end_typedef

begin_comment
comment|/* so # bytes on a page fits in a long */
end_comment

begin_typedef
typedef|typedef
name|u_long
name|pgno_t
typedef|;
end_typedef

begin_comment
comment|/* so # of pages in a btree fits in a long */
end_comment

begin_comment
comment|/*  *  When we do searches, we push the parent page numbers onto a stack  *  as we descend the tree.  This is so that for insertions, we can  *  find our way back up to do internal page insertions and splits.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BTSTACK
block|{
name|pgno_t
name|bts_pgno
decl_stmt|;
name|struct
name|BTSTACK
modifier|*
name|bts_next
decl_stmt|;
block|}
name|BTSTACK
typedef|;
end_typedef

begin_comment
comment|/*  *  Every btree page has a header that looks like this.  Flags are given  *  in the #define's for the F_ flags (see below).  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BTHEADER
block|{
name|pgno_t
name|h_pgno
decl_stmt|;
comment|/* page number of this page */
name|pgno_t
name|h_prevpg
decl_stmt|;
comment|/* left sibling */
name|pgno_t
name|h_nextpg
decl_stmt|;
comment|/* right sibling */
define|#
directive|define
name|F_LEAF
value|0x01
comment|/* leaf page, contains user data */
define|#
directive|define
name|F_CONT
value|0x02
comment|/* continuation page (large items) */
define|#
directive|define
name|F_DIRTY
value|0x04
comment|/* need to write to disk */
define|#
directive|define
name|F_PRESERVE
value|0x08
comment|/* never delete this chain of pages */
name|u_long
name|h_flags
decl_stmt|;
comment|/* page state */
name|index_t
name|h_lower
decl_stmt|;
comment|/* lower bound of free space on page */
name|index_t
name|h_upper
decl_stmt|;
comment|/* upper bound of free space on page */
name|index_t
name|h_linp
index|[
literal|1
index|]
decl_stmt|;
comment|/* VARIABLE LENGTH DATA AT END OF STRUCT */
block|}
name|BTHEADER
typedef|;
end_typedef

begin_comment
comment|/*  *  HTBUCKETs are hash table buckets for looking up pages of in-memory  *  btrees by page number.  We use this indirection, rather than direct  *  pointers, so that the code for manipulating in-memory trees is the  *  same as that for manipulating on-disk trees.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|HTBUCKET
block|{
name|pgno_t
name|ht_pgno
decl_stmt|;
name|BTHEADER
modifier|*
name|ht_page
decl_stmt|;
name|struct
name|HTBUCKET
modifier|*
name|ht_next
decl_stmt|;
block|}
name|HTBUCKET
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|HTBUCKET
modifier|*
modifier|*
name|HTABLE
typedef|;
end_typedef

begin_comment
comment|/* minimum size we'll let a page be */
end_comment

begin_define
define|#
directive|define
name|MINPSIZE
value|512
end_define

begin_comment
comment|/* default cache size, in bytes */
end_comment

begin_define
define|#
directive|define
name|DEFCACHE
value|(20 * 1024)
end_define

begin_comment
comment|/* hash table size for in-memory trees */
end_comment

begin_define
define|#
directive|define
name|HTSIZE
value|128
end_define

begin_comment
comment|/* generate a hash key from a page number */
end_comment

begin_define
define|#
directive|define
name|HASHKEY
parameter_list|(
name|pgno
parameter_list|)
value|((pgno - 1) % HTSIZE)
end_define

begin_comment
comment|/*  *  Disk btrees have a file descriptor, and may also have an lru buffer  *  cache, if the user asked for one.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BTDISK
block|{
name|int
name|d_fd
decl_stmt|;
name|char
modifier|*
name|d_cache
decl_stmt|;
block|}
name|BTDISK
typedef|;
end_typedef

begin_comment
comment|/*  *  Cursors keep track of the current location in a sequential scan of  *  the database.  Since btrees impose a total ordering on keys, we can  *  walk forward or backward through the database from any point.  Cursors  *  survive updates to the tree, and can be used to delete a particular  *  record.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|CURSOR
block|{
name|pgno_t
name|c_pgno
decl_stmt|;
comment|/* pgno of current item in scan */
name|index_t
name|c_index
decl_stmt|;
comment|/* index of current item in scan */
name|char
modifier|*
name|c_key
decl_stmt|;
comment|/* current key, used for updates */
define|#
directive|define
name|CRSR_BEFORE
value|0x01
name|u_char
name|c_flags
decl_stmt|;
comment|/* to handle updates properly */
block|}
name|CURSOR
typedef|;
end_typedef

begin_comment
comment|/*  *  The private btree data structure.  The user passes a pointer to one of  *  these when we are to manipulate a tree, but the BTREE type is opaque  *  to him.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BTREEDATA_P
block|{
name|char
modifier|*
name|bt_fname
decl_stmt|;
comment|/* NULL for in-memory trees */
union|union
block|{
name|BTDISK
name|bt_d
decl_stmt|;
comment|/* for on-disk btrees */
name|HTABLE
name|bt_ht
decl_stmt|;
comment|/* hash table for mem trees */
block|}
name|bt_s
union|;
name|size_t
name|bt_psize
decl_stmt|;
comment|/* page size for btree pages */
name|int
function_decl|(
modifier|*
name|bt_compare
function_decl|)
parameter_list|()
function_decl|;
comment|/* key comparison function */
name|pgno_t
name|bt_npages
decl_stmt|;
comment|/* number of pages in tree */
name|BTHEADER
modifier|*
name|bt_curpage
decl_stmt|;
comment|/* current page contents */
name|pgno_t
name|bt_free
decl_stmt|;
comment|/* free pg list for big data */
name|CURSOR
name|bt_cursor
decl_stmt|;
comment|/* cursor for scans */
name|BTSTACK
modifier|*
name|bt_stack
decl_stmt|;
comment|/* parent stack for inserts */
name|u_long
name|bt_lorder
decl_stmt|;
comment|/* byte order (endian.h) */
define|#
directive|define
name|BTF_METAOK
value|0x01
comment|/* meta-data written to start of file */
define|#
directive|define
name|BTF_SEQINIT
value|0x02
comment|/* we have called bt_seq */
define|#
directive|define
name|BTF_ISWRITE
value|0x04
comment|/* tree was opened for write */
define|#
directive|define
name|BTF_NODUPS
value|0x08
comment|/* tree created for unique keys */
name|u_long
name|bt_flags
decl_stmt|;
comment|/* btree state */
block|}
name|BTREEDATA_P
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|BTREEDATA_P
modifier|*
name|BTREE_P
typedef|;
end_typedef

begin_comment
comment|/*  *  The first thing in a btree file is a BTMETA structure.  The rest of  *  the first page is empty, so that all disk operations are page-aligned.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BTMETA
block|{
name|u_long
name|m_magic
decl_stmt|;
name|u_long
name|m_version
decl_stmt|;
name|size_t
name|m_psize
decl_stmt|;
name|pgno_t
name|m_free
decl_stmt|;
name|u_long
name|m_flags
decl_stmt|;
name|u_long
name|m_lorder
decl_stmt|;
block|}
name|BTMETA
typedef|;
end_typedef

begin_define
define|#
directive|define
name|P_NONE
value|0
end_define

begin_comment
comment|/* invalid page number in tree */
end_comment

begin_define
define|#
directive|define
name|P_ROOT
value|1
end_define

begin_comment
comment|/* page number of root pg in btree */
end_comment

begin_define
define|#
directive|define
name|NORELEASE
value|0
end_define

begin_comment
comment|/* don't release a page during write */
end_comment

begin_define
define|#
directive|define
name|RELEASE
value|1
end_define

begin_comment
comment|/* release a page during write */
end_comment

begin_define
define|#
directive|define
name|INSERT
value|0
end_define

begin_comment
comment|/* doing an insert operation */
end_comment

begin_define
define|#
directive|define
name|DELETE
value|1
end_define

begin_comment
comment|/* doing a delete operation */
end_comment

begin_comment
comment|/* get the next free index on a btree page */
end_comment

begin_define
define|#
directive|define
name|NEXTINDEX
parameter_list|(
name|p
parameter_list|)
value|((((int)(p)->h_lower) - ((int)((((char *)(&(p)->h_linp[0]))) - ((char *) (p)))))/(sizeof(index_t)))
end_define

begin_comment
comment|/* is a BTITEM actually on the btree page? */
end_comment

begin_define
define|#
directive|define
name|VALIDITEM
parameter_list|(
name|t
parameter_list|,
name|i
parameter_list|)
value|((i)->bti_index< NEXTINDEX((t)->bt_curpage))
end_define

begin_comment
comment|/* guarantee longword alignment so structure refs work */
end_comment

begin_define
define|#
directive|define
name|LONGALIGN
parameter_list|(
name|p
parameter_list|)
value|(((long)(p) + 3)& ~ 0x03)
end_define

begin_comment
comment|/* get a particular datum (or idatum) off a page */
end_comment

begin_define
define|#
directive|define
name|GETDATUM
parameter_list|(
name|h
parameter_list|,
name|i
parameter_list|)
value|(((char *) h) + h->h_linp[i])
end_define

begin_comment
comment|/* is a {key,datum} too big to put on a single page? */
end_comment

begin_define
define|#
directive|define
name|TOOBIG
parameter_list|(
name|t
parameter_list|,
name|sz
parameter_list|)
value|(sz>= t->bt_psize / 5)
end_define

begin_comment
comment|/* is this a disk tree or a memory tree? */
end_comment

begin_define
define|#
directive|define
name|ISDISK
parameter_list|(
name|t
parameter_list|)
value|(t->bt_fname != (char *) NULL)
end_define

begin_comment
comment|/* does the disk tree use a cache? */
end_comment

begin_define
define|#
directive|define
name|ISCACHE
parameter_list|(
name|t
parameter_list|)
value|(t->bt_s.bt_d.d_cache != (char *) NULL)
end_define

begin_comment
comment|/*  *  DATUMs are for user data -- one appears on leaf pages for every  *  tree entry.  The d_bytes[] array contains the key first, then the data.  *  *  If either the key or the datum is too big to store on a single page,  *  a bit is set in the flags entry, and the d_bytes[] array contains a  *  pgno pointing to the page at which the data is actually stored.  *  *  Note on alignment:  every DATUM is guaranteed to be longword aligned  *  on the disk page.  In order to force longword alignment of user key  *  and data values, we must guarantee that the d_bytes[] array starts  *  on a longword boundary.  This is the reason that d_flags is a u_long,  *  rather than a u_char (it really only needs to be two bits big).  This  *  is necessary because we call the user's comparison function with a  *  pointer to the start of the d_bytes array.  We don't need to force  *  longword alignment of the data following the key, since that is copied  *  to a longword-aligned buffer before being returned to the user.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|DATUM
block|{
name|size_t
name|d_ksize
decl_stmt|;
comment|/* size of key */
name|size_t
name|d_dsize
decl_stmt|;
comment|/* size of data */
define|#
directive|define
name|D_BIGDATA
value|0x01
comment|/* indirect datum ptr flag */
define|#
directive|define
name|D_BIGKEY
value|0x02
comment|/* indirect key ptr flag */
name|u_long
name|d_flags
decl_stmt|;
comment|/* flags (indirect bit) */
name|char
name|d_bytes
index|[
literal|1
index|]
decl_stmt|;
comment|/* VARIABLE LENGTH DATA AT END OF STRUCT */
block|}
name|DATUM
typedef|;
end_typedef

begin_comment
comment|/* BTITEMs are used to return (page, index, datum) tuples from searches */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|BTITEM
block|{
name|pgno_t
name|bti_pgno
decl_stmt|;
name|index_t
name|bti_index
decl_stmt|;
name|DATUM
modifier|*
name|bti_datum
decl_stmt|;
block|}
name|BTITEM
typedef|;
end_typedef

begin_comment
comment|/*  *  IDATUMs are for data stored on internal pages.  This is the (key, pgno)  *  pair, such that key 'key' is the first entry on page 'pgno'.  If our  *  internal page contains keys (a) and (b) next to each other, then all  *  items>= to (a) and< (b) go on the same page as (a).  There are some  *  gotchas with duplicate keys, however.  See the split code for details.  *  *  If a key is too big to fit on a single page, then the i_bytes[] array  *  contains a pgno pointing to the start of a chain that actually stores  *  the bytes.  Since items on internal pages are never deleted from the  *  tree, these indirect chains are marked as special, so that they won't  *  be deleted if the corresponding leaf item is deleted.  *  *  As for DATUMs, IDATUMs have a u_long flag entry (rather than u_char)  *  in order to guarantee that user keys are longword aligned on the disk  *  page.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|IDATUM
block|{
name|size_t
name|i_size
decl_stmt|;
name|pgno_t
name|i_pgno
decl_stmt|;
name|u_long
name|i_flags
decl_stmt|;
comment|/* see DATUM.d_flags, above */
name|char
name|i_bytes
index|[
literal|1
index|]
decl_stmt|;
comment|/* VARIABLE LENGTH DATA AT END OF STRUCT */
block|}
name|IDATUM
typedef|;
end_typedef

begin_comment
comment|/* all private interfaces have a leading _ in their names */
end_comment

begin_function_decl
specifier|extern
name|BTITEM
modifier|*
name|_bt_search
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BTITEM
modifier|*
name|_bt_searchr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BTHEADER
modifier|*
name|_bt_allocpg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|index_t
name|_bt_binsrch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bt_isonpage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BTITEM
modifier|*
name|_bt_first
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bt_release
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bt_wrtmeta
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bt_delindir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bt_pgout
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bt_pgin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bt_fixscan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bt_indirect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bt_crsrdel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bt_push
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pgno_t
name|_bt_pop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|strcmp
parameter_list|()
function_decl|;
end_function_decl

end_unit

