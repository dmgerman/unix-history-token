begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)db.h	4.14 (Berkeley) 6/18/88  */
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
name|u_long
name|d_ttl
decl_stmt|;
comment|/* time to live */
name|short
name|d_flags
decl_stmt|;
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
name|short
name|d_mark
decl_stmt|;
comment|/* place to mark data */
name|short
name|d_size
decl_stmt|;
comment|/* size of data area */
name|u_long
name|d_nstime
decl_stmt|;
comment|/* NS response time, milliseconds */
name|char
name|d_data
index|[
name|MAXDATA
index|]
decl_stmt|;
comment|/* the data is malloc'ed to size */
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

begin_comment
comment|/*  * d_flags definitions  */
end_comment

begin_define
define|#
directive|define
name|DB_F_HINT
value|0x01
end_define

begin_comment
comment|/* databuf belongs to fcachetab */
end_comment

begin_struct
struct|struct
name|namebuf
block|{
name|char
modifier|*
name|n_dname
decl_stmt|;
comment|/* domain name */
name|u_int
name|n_hashval
decl_stmt|;
comment|/* hash value of n_dname */
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
value|0x01
end_define

begin_comment
comment|/* data should not exist */
end_comment

begin_define
define|#
directive|define
name|DB_MEXIST
value|0x02
end_define

begin_comment
comment|/* data must exist */
end_comment

begin_define
define|#
directive|define
name|DB_DELETE
value|0x04
end_define

begin_comment
comment|/* delete data if it exists */
end_comment

begin_define
define|#
directive|define
name|DB_NOTAUTH
value|0x08
end_define

begin_comment
comment|/* must not update authoritative data */
end_comment

begin_define
define|#
directive|define
name|DB_NOHINTS
value|0x10
end_define

begin_comment
comment|/* don't reflect update in fcachetab */
end_comment

begin_define
define|#
directive|define
name|DB_Z_CACHE
value|(0)
end_define

begin_comment
comment|/* cache-zone-only db_dump()  */
end_comment

begin_define
define|#
directive|define
name|DB_Z_ALL
value|(-1)
end_define

begin_comment
comment|/* normal db_dump() */
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

begin_define
define|#
directive|define
name|AUTH
value|-10
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

begin_decl_stmt
specifier|extern
name|struct
name|hashbuf
modifier|*
name|fcachetab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash table for cache read from file*/
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
name|databuf
modifier|*
name|rm_datum
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

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|realloc
argument_list|()
decl_stmt|,
modifier|*
name|calloc
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

