begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Ian Dowse.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UFS_UFS_DIRHASH_H_
end_ifndef

begin_define
define|#
directive|define
name|_UFS_UFS_DIRHASH_H_
end_define

begin_comment
comment|/*  * For fast operations on large directories, we maintain a hash  * that maps the file name to the offset of the directory entry within  * the directory file.  *  * The hashing uses a dumb spillover to the next free slot on  * collisions, so we must keep the utilisation low to avoid  * long linear searches. Deleted entries that are not the last  * in a chain must be marked DIRHASH_DEL.  *  * We also maintain a information about free space in each block  * to speed up creations.  */
end_comment

begin_define
define|#
directive|define
name|DIRHASH_EMPTY
value|(-1)
end_define

begin_comment
comment|/* entry unused */
end_comment

begin_define
define|#
directive|define
name|DIRHASH_DEL
value|(-2)
end_define

begin_comment
comment|/* deleted entry; may be part of chain */
end_comment

begin_define
define|#
directive|define
name|DIRALIGN
value|4
end_define

begin_define
define|#
directive|define
name|DH_NFSTATS
value|(DIRECTSIZ(MAXNAMLEN + 1) / DIRALIGN)
end_define

begin_comment
comment|/* max DIRALIGN words in a directory entry */
end_comment

begin_comment
comment|/*  * Dirhash uses a score mechanism to achieve a hybrid between a  * least-recently-used and a least-often-used algorithm for entry  * recycling. The score is incremented when a directory is used, and  * decremented when the directory is a candidate for recycling. When  * the score reaches zero, the hash is recycled. Hashes are linked  * together on a TAILQ list, and hashes with higher scores filter  * towards the tail (most recently used) end of the list.  *  * New hash entries are given an inital score of DH_SCOREINIT and are  * placed at the most-recently-used end of the list. This helps a lot  * in the worst-case case scenario where every directory access is  * to a directory that is not hashed (i.e. the working set of hash  * candidates is much larger than the configured memry limit). In this  * case it limits the number of hash builds to 1/DH_SCOREINIT of the  * number of accesses.  */
end_comment

begin_define
define|#
directive|define
name|DH_SCOREINIT
value|8
end_define

begin_comment
comment|/* initial dh_score when dirhash built */
end_comment

begin_define
define|#
directive|define
name|DH_SCOREMAX
value|64
end_define

begin_comment
comment|/* max dh_score value */
end_comment

begin_comment
comment|/*  * The main hash table has 2 levels. It is an array of pointers to  * blocks of DH_NBLKOFF offsets.  */
end_comment

begin_define
define|#
directive|define
name|DH_BLKOFFSHIFT
value|8
end_define

begin_define
define|#
directive|define
name|DH_NBLKOFF
value|(1<< DH_BLKOFFSHIFT)
end_define

begin_define
define|#
directive|define
name|DH_BLKOFFMASK
value|(DH_NBLKOFF - 1)
end_define

begin_define
define|#
directive|define
name|DH_ENTRY
parameter_list|(
name|dh
parameter_list|,
name|slot
parameter_list|)
define|\
value|((dh)->dh_hash[(slot)>> DH_BLKOFFSHIFT][(slot)& DH_BLKOFFMASK])
end_define

begin_struct
struct|struct
name|dirhash
block|{
name|doff_t
modifier|*
modifier|*
name|dh_hash
decl_stmt|;
comment|/* the hash array (2-level) */
name|int
name|dh_narrays
decl_stmt|;
comment|/* number of entries in dh_hash */
name|int
name|dh_hlen
decl_stmt|;
comment|/* total slots in the 2-level hash array */
name|int
name|dh_hused
decl_stmt|;
comment|/* entries in use */
comment|/* Free space statistics. XXX assumes DIRBLKSIZ is 512. */
name|u_int8_t
modifier|*
name|dh_blkfree
decl_stmt|;
comment|/* free DIRALIGN words in each dir block */
name|int
name|dh_nblk
decl_stmt|;
comment|/* size of dh_blkfree array */
name|int
name|dh_dirblks
decl_stmt|;
comment|/* number of DIRBLKSIZ blocks in dir */
name|int
name|dh_firstfree
index|[
name|DH_NFSTATS
operator|+
literal|1
index|]
decl_stmt|;
comment|/* first blk with N words free */
name|int
name|dh_seqopt
decl_stmt|;
comment|/* sequential access optimisation enabled */
name|doff_t
name|dh_seqoff
decl_stmt|;
comment|/* sequential access optimisation offset */
name|int
name|dh_score
decl_stmt|;
comment|/* access count for this dirhash */
name|int
name|dh_onlist
decl_stmt|;
comment|/* true if on the ufsdirhash_list chain */
name|TAILQ_ENTRY
argument_list|(
argument|dirhash
argument_list|)
name|dh_list
expr_stmt|;
comment|/* chain of all dirhashes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Dirhash functions.  */
end_comment

begin_function_decl
name|int
name|ufsdirhash_build
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|doff_t
name|ufsdirhash_findfree
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|doff_t
name|ufsdirhash_enduseful
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufsdirhash_lookup
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|doff_t
modifier|*
parameter_list|,
name|struct
name|buf
modifier|*
modifier|*
parameter_list|,
name|doff_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufsdirhash_newblk
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|doff_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufsdirhash_add
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|direct
modifier|*
parameter_list|,
name|doff_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufsdirhash_remove
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|direct
modifier|*
parameter_list|,
name|doff_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufsdirhash_move
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|struct
name|direct
modifier|*
parameter_list|,
name|doff_t
parameter_list|,
name|doff_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufsdirhash_dirtrunc
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|doff_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufsdirhash_free
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ufsdirhash_checkblock
parameter_list|(
name|struct
name|inode
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|doff_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UFS_UFS_DIRHASH_H_ */
end_comment

end_unit

