begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	db.h	4.3	86/06/04	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California  *	All Rights Reserved  */
end_comment

begin_comment
comment|/*  * Global structures and variables for data base routines.  */
end_comment

begin_define
define|#
directive|define
name|INVBLKSZ
value|7
end_define

begin_comment
comment|/* # of namebuf pointers per block */
end_comment

begin_define
define|#
directive|define
name|INVHASHSZ
value|919
end_define

begin_comment
comment|/* size of inverse hash table */
end_comment

begin_comment
comment|/* max length of data in RR data field */
end_comment

begin_define
define|#
directive|define
name|MAXDATA
value|256
end_define

begin_comment
comment|/*  * Hash table structures.  */
end_comment

begin_struct
struct|struct
name|databuf
block|{
name|struct
name|databuf
modifier|*
name|d_next
decl_stmt|;
comment|/* linked list */
name|short
name|d_refcount
decl_stmt|;
comment|/* reference count */
name|short
name|d_zone
decl_stmt|;
comment|/* zone number */
name|short
name|d_class
decl_stmt|;
comment|/* class number */
name|short
name|d_type
decl_stmt|;
comment|/* type number */
name|u_long
name|d_ttl
decl_stmt|;
comment|/* time to live */
name|int
name|d_size
decl_stmt|;
comment|/* size of data area */
name|char
name|d_data
index|[
name|MAXDATA
index|]
decl_stmt|;
comment|/* malloc'ed as needed */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DATASIZE
parameter_list|(
name|n
parameter_list|)
value|(sizeof(struct databuf) - MAXDATA + n)
end_define

begin_struct
struct|struct
name|namebuf
block|{
name|char
modifier|*
name|n_dname
decl_stmt|;
comment|/* domain name */
name|struct
name|namebuf
modifier|*
name|n_next
decl_stmt|;
comment|/* linked list */
name|struct
name|databuf
modifier|*
name|n_data
decl_stmt|;
comment|/* data records */
name|struct
name|namebuf
modifier|*
name|n_parent
decl_stmt|;
comment|/* parent domain */
name|struct
name|hashbuf
modifier|*
name|n_hash
decl_stmt|;
comment|/* hash table for children */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|invbuf
block|{
name|struct
name|invbuf
modifier|*
name|i_next
decl_stmt|;
comment|/* linked list */
name|struct
name|namebuf
modifier|*
name|i_dname
index|[
name|INVBLKSZ
index|]
decl_stmt|;
comment|/* domain name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hashbuf
block|{
name|int
name|h_size
decl_stmt|;
comment|/* size of hash table */
name|int
name|h_cnt
decl_stmt|;
comment|/* number of entries */
name|struct
name|namebuf
modifier|*
name|h_tab
index|[
literal|1
index|]
decl_stmt|;
comment|/* malloc'ed as needed */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HASHSIZE
parameter_list|(
name|s
parameter_list|)
value|(s*sizeof(struct namebuf *) + 2*sizeof(int))
end_define

begin_define
define|#
directive|define
name|HASHSHIFT
value|3
end_define

begin_define
define|#
directive|define
name|HASHMASK
value|0x1f
end_define

begin_comment
comment|/*  * Flags to updatedb  */
end_comment

begin_define
define|#
directive|define
name|DB_NODATA
value|0x1
end_define

begin_comment
comment|/* data should not exist */
end_comment

begin_define
define|#
directive|define
name|DB_MEXIST
value|0x2
end_define

begin_comment
comment|/* data must exist */
end_comment

begin_define
define|#
directive|define
name|DB_DELETE
value|0x4
end_define

begin_comment
comment|/* delete data if it exists */
end_comment

begin_comment
comment|/*  * Error return codes  */
end_comment

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_define
define|#
directive|define
name|NONAME
value|-1
end_define

begin_define
define|#
directive|define
name|NOCLASS
value|-2
end_define

begin_define
define|#
directive|define
name|NOTYPE
value|-3
end_define

begin_define
define|#
directive|define
name|NODATA
value|-4
end_define

begin_define
define|#
directive|define
name|DATAEXISTS
value|-5
end_define

begin_define
define|#
directive|define
name|NODBFILE
value|-6
end_define

begin_define
define|#
directive|define
name|TOOMANYZONES
value|-7
end_define

begin_define
define|#
directive|define
name|GOODDB
value|-8
end_define

begin_define
define|#
directive|define
name|NEWDB
value|-9
end_define

begin_decl_stmt
specifier|extern
name|struct
name|hashbuf
modifier|*
name|hashtab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root hash table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|invbuf
modifier|*
name|invtab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inverse hash table */
end_comment

begin_function_decl
specifier|extern
name|struct
name|namebuf
modifier|*
name|nlookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|namebuf
modifier|*
name|savename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|databuf
modifier|*
name|savedata
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|hashbuf
modifier|*
name|savehash
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|invbuf
modifier|*
name|saveinv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|savestr
parameter_list|()
function_decl|;
end_function_decl

end_unit

