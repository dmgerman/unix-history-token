begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2003 Silicon Graphics, Inc.  All Rights Reserved.  *  * This program is free software; you can redistribute it and/or modify it  * under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it would be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Further, this software is distributed without any warranty that it is  * free of the rightful claim of any third person regarding infringement  * or the like.	 Any license provided herein, whether implied or  * otherwise, applies only to this software file.  Patent licenses, if  * any, provided herein do not apply to combinations of this program with  * other software, or any other product whatsoever.  *  * You should have received a copy of the GNU General Public License along  * with this program; if not, write the Free Software Foundation, Inc., 59  * Temple Place - Suite 330, Boston MA 02111-1307, USA.  *  * Contact information: Silicon Graphics, Inc., 1600 Amphitheatre Pkwy,  * Mountain View, CA  94043, or:  *  * http://www.sgi.com  *  * For further information regarding this notice, see:  *  * http://oss.sgi.com/projects/GenInfo/SGIGPLNoticeExplan/  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XFS_BUF_H__
end_ifndef

begin_define
define|#
directive|define
name|__XFS_BUF_H__
end_define

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_comment
comment|/* XXX: move this into buf.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|B_MANAGED
end_ifndef

begin_define
define|#
directive|define
name|B_MANAGED
value|B_08000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|xfs_buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xfs_buf_iodone_t
function_decl|)
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* call-back function on I/O completion */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xfs_buf_relse_t
function_decl|)
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* call-back function on I/O completion */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|xfs_buf_bdstrat_t
function_decl|)
parameter_list|(
name|struct
name|xfs_buf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|xfs_buftarg
block|{
name|struct
name|cdev
modifier|*
name|dev
decl_stmt|;
name|struct
name|vnode
modifier|*
name|specvp
decl_stmt|;
block|}
name|xfs_buftarg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|buf
name|xfs_buf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|xfs_buf
value|buf
end_define

begin_comment
comment|/* These are just for xfs_syncsub... it sets an internal variable  * then passes it to VOP_FLUSH_PAGES or adds the flags to a newly gotten buf_t  */
end_comment

begin_define
define|#
directive|define
name|XFS_B_ASYNC
value|B_ASYNC
end_define

begin_define
define|#
directive|define
name|XFS_B_DELWRI
value|B_DELWRI
end_define

begin_define
define|#
directive|define
name|XFS_B_READ
value|BIO_READ
end_define

begin_define
define|#
directive|define
name|XFS_B_WRITE
value|BIO_WRITE
end_define

begin_define
define|#
directive|define
name|XFS_B_STALE
value|B_INVAL
end_define

begin_define
define|#
directive|define
name|XFS_BUF_LOCK
value|0
end_define

begin_define
define|#
directive|define
name|XFS_BUF_TRYLOCK
value|0
end_define

begin_define
define|#
directive|define
name|XFS_BUF_MAPPED
value|0
end_define

begin_define
define|#
directive|define
name|BUF_BUSY
value|0
end_define

begin_comment
comment|/* debugging routines might need this */
end_comment

begin_define
define|#
directive|define
name|XFS_BUF_BFLAGS
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ZEROFLAGS
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags = 0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_STALE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags |= XFS_B_STALE)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_UNSTALE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags&= ~XFS_B_STALE)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISSTALE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags& XFS_B_STALE)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SUPER_STALE
parameter_list|(
name|x
parameter_list|)
value|{(x)->b_flags |= XFS_B_STALE;\ 				(x)->b_flags&= ~(XFS_B_DELWRI|B_CACHE);}
end_define

begin_define
define|#
directive|define
name|XFS_BUF_MANAGE
value|B_MANAGED
end_define

begin_define
define|#
directive|define
name|XFS_BUF_UNMANAGE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags&= ~B_MANAGED)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_DELAYWRITE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags |= XFS_B_DELWRI)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_UNDELAYWRITE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags&= ~XFS_B_DELWRI)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISDELAYWRITE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags& XFS_B_DELWRI)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ERROR
parameter_list|(
name|x
parameter_list|,
name|no
parameter_list|)
value|xfs_buf_set_error((x), (no))
end_define

begin_define
define|#
directive|define
name|XFS_BUF_GETERROR
parameter_list|(
name|x
parameter_list|)
value|xfs_buf_get_error(x)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISERROR
parameter_list|(
name|x
parameter_list|)
value|(((x)->b_ioflags& BIO_ERROR) != 0)
end_define

begin_function
name|void
specifier|static
name|__inline__
name|xfs_buf_set_error
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|,
name|int
name|err
parameter_list|)
block|{
name|bp
operator|->
name|b_ioflags
operator||=
name|BIO_ERROR
expr_stmt|;
name|bp
operator|->
name|b_error
operator|=
name|err
expr_stmt|;
block|}
end_function

begin_function
name|int
specifier|static
name|__inline__
name|xfs_buf_get_error
parameter_list|(
name|struct
name|buf
modifier|*
name|bp
parameter_list|)
block|{
return|return
name|XFS_BUF_ISERROR
argument_list|(
name|bp
argument_list|)
condition|?
operator|(
name|bp
operator|->
name|b_error
condition|?
name|bp
operator|->
name|b_error
else|:
name|EIO
operator|)
else|:
literal|0
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_BUF_DONE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags |= B_CACHE)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_UNDONE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags&= ~B_CACHE)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISDONE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags& B_CACHE)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_BUSY
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags |= BUF_BUSY)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_UNBUSY
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags&= ~BUF_BUSY)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISBUSY
parameter_list|(
name|x
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ASYNC
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags |=  B_ASYNC)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_UNASYNC
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags&= ~B_ASYNC)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISASYNC
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags&   B_ASYNC)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_FLUSH
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags |=  B_00800000)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_UNFLUSH
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags&= ~B_00800000)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISFLUSH
parameter_list|(
name|x
parameter_list|)
value|((x)->b_flags&   B_00800000)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SHUT
parameter_list|(
name|x
parameter_list|)
value|printf("XFS_BUF_SHUT not implemented yet\n")
end_define

begin_define
define|#
directive|define
name|XFS_BUF_UNSHUT
parameter_list|(
name|x
parameter_list|)
value|printf("XFS_BUF_UNSHUT not implemented yet\n")
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISSHUT
parameter_list|(
name|x
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_HOLD
parameter_list|(
name|x
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_UNHOLD
parameter_list|(
name|x
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISHOLD
parameter_list|(
name|x
parameter_list|)
value|BUF_REFCNT(x)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_READ
parameter_list|(
name|x
parameter_list|)
value|((x)->b_iocmd = BIO_READ)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_UNREAD
parameter_list|(
name|x
parameter_list|)
value|((x)->b_iocmd = 0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISREAD
parameter_list|(
name|x
parameter_list|)
value|((x)->b_iocmd == BIO_READ)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_WRITE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_iocmd = BIO_WRITE)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_UNWRITE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_iocmd = 0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISWRITE
parameter_list|(
name|x
parameter_list|)
value|((x)->b_iocmd == BIO_WRITE)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISUNINITIAL
parameter_list|(
name|x
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_UNUNINITIAL
parameter_list|(
name|x
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_IODONE_FUNC
parameter_list|(
name|x
parameter_list|)
value|(x)->b_iodone
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_IODONE_FUNC
parameter_list|(
name|x
parameter_list|,
name|f
parameter_list|)
value|(x)->b_iodone = (f)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_CLR_IODONE_FUNC
parameter_list|(
name|x
parameter_list|)
value|(x)->b_iodone = NULL
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_BDSTRAT_FUNC
parameter_list|(
name|x
parameter_list|,
name|f
parameter_list|)
value|do { if(f != NULL) {} } while(0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_CLR_BDSTRAT_FUNC
parameter_list|(
name|x
parameter_list|)
value|((void)0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_BP_ISMAPPED
parameter_list|(
name|bp
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_FSPRIVATE
parameter_list|(
name|buf
parameter_list|,
name|type
parameter_list|)
define|\
value|((type)(buf)->b_fsprivate1)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_FSPRIVATE
parameter_list|(
name|buf
parameter_list|,
name|value
parameter_list|)
define|\
value|(buf)->b_fsprivate1 = (void *)(value)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_FSPRIVATE2
parameter_list|(
name|buf
parameter_list|,
name|type
parameter_list|)
define|\
value|((type)(buf)->b_fsprivate2)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_FSPRIVATE2
parameter_list|(
name|buf
parameter_list|,
name|value
parameter_list|)
define|\
value|(buf)->b_fsprivate2 = (void *)(value)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_FSPRIVATE3
parameter_list|(
name|buf
parameter_list|,
name|type
parameter_list|)
define|\
value|((type)(buf)->b_fsprivate3)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_FSPRIVATE3
parameter_list|(
name|buf
parameter_list|,
name|value
parameter_list|)
define|\
value|(buf)->b_fsprivate3 = (void *)(value)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_START
parameter_list|(
name|buf
parameter_list|)
define|\
value|printf("XFS_BUF_SET_START: %s:%d\n", __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_BRELSE_FUNC
parameter_list|(
name|buf
parameter_list|,
name|value
parameter_list|)
define|\
value|do { \ 		printf("XFS_BUF_SET_BRELSE_FUNC: %s:%d\n", \ 		        __FILE__, __LINE__); \ 		if (value != NULL ) {} \ 	} while(0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_PTR
parameter_list|(
name|bp
parameter_list|)
value|(xfs_caddr_t)((bp)->b_data)
end_define

begin_function
specifier|static
name|__inline
name|xfs_caddr_t
name|xfs_buf_offset
parameter_list|(
name|xfs_buf_t
modifier|*
name|bp
parameter_list|,
name|size_t
name|offset
parameter_list|)
block|{
return|return
name|XFS_BUF_PTR
argument_list|(
name|bp
argument_list|)
operator|+
name|offset
return|;
block|}
end_function

begin_define
define|#
directive|define
name|XFS_BUF_SET_PTR
parameter_list|(
name|bp
parameter_list|,
name|val
parameter_list|,
name|count
parameter_list|)
define|\
value|do { \ 					(bp)->b_data = (val); \ 					(bp)->b_bcount = (count); \ 				} while(0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ADDR
parameter_list|(
name|bp
parameter_list|)
value|((bp)->b_blkno)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_ADDR
parameter_list|(
name|bp
parameter_list|,
name|blk
parameter_list|)
define|\
value|((bp)->b_blkno = blk)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_OFFSET
parameter_list|(
name|bp
parameter_list|)
value|((bp)->b_offset)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_OFFSET
parameter_list|(
name|bp
parameter_list|,
name|off
parameter_list|)
define|\
value|((bp)->b_offset = off)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_COUNT
parameter_list|(
name|bp
parameter_list|)
value|((bp)->b_bcount)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_COUNT
parameter_list|(
name|bp
parameter_list|,
name|cnt
parameter_list|)
define|\
value|((bp)->b_bcount = cnt)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SIZE
parameter_list|(
name|bp
parameter_list|)
value|((bp)->b_bufsize)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_SIZE
parameter_list|(
name|bp
parameter_list|,
name|cnt
parameter_list|)
define|\
value|((bp)->b_bufsize = cnt)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_VTYPE_REF
parameter_list|(
name|bp
parameter_list|,
name|type
parameter_list|,
name|ref
parameter_list|)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_VTYPE
parameter_list|(
name|bp
parameter_list|,
name|type
parameter_list|)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_REF
parameter_list|(
name|bp
parameter_list|,
name|ref
parameter_list|)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_VALUSEMA
parameter_list|(
name|bp
parameter_list|)
value|(BUF_REFCNT(bp)? 0 : 1)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_CPSEMA
parameter_list|(
name|bp
parameter_list|)
define|\
value|(BUF_LOCK(bp, LK_EXCLUSIVE|LK_CANRECURSE | LK_SLEEPFAIL, NULL) == 0)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_PSEMA
parameter_list|(
name|bp
parameter_list|,
name|x
parameter_list|)
value|BUF_LOCK(bp, LK_EXCLUSIVE|LK_CANRECURSE, NULL)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_VSEMA
parameter_list|(
name|bp
parameter_list|)
value|BUF_UNLOCK(bp)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_V_IODONESEMA
parameter_list|(
name|bp
parameter_list|)
value|bdone(bp)
end_define

begin_comment
comment|/* setup the buffer target from a buftarg structure */
end_comment

begin_define
define|#
directive|define
name|XFS_BUF_SET_TARGET
parameter_list|(
name|bp
parameter_list|,
name|target
parameter_list|)
define|\
value|xfs_buf_set_target(bp, target)
end_define

begin_function_decl
name|void
name|xfs_buf_set_target
parameter_list|(
name|xfs_buf_t
modifier|*
parameter_list|,
name|xfs_buftarg_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_buftarg_t
modifier|*
name|xfs_buf_get_target
parameter_list|(
name|xfs_buf_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return the dev_t being used */
end_comment

begin_define
define|#
directive|define
name|XFS_BUF_TARGET
parameter_list|(
name|bp
parameter_list|)
value|xfs_buf_get_target(bp)
end_define

begin_define
define|#
directive|define
name|XFS_BUFTARG_NAME
parameter_list|(
name|targp
parameter_list|)
value|devtoname((targp)->dev)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_VTYPE_REF
parameter_list|(
name|bp
parameter_list|,
name|type
parameter_list|,
name|ref
parameter_list|)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_VTYPE
parameter_list|(
name|bp
parameter_list|,
name|type
parameter_list|)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_SET_REF
parameter_list|(
name|bp
parameter_list|,
name|ref
parameter_list|)
end_define

begin_define
define|#
directive|define
name|XFS_BUF_ISPINNED
parameter_list|(
name|bp
parameter_list|)
value|xfs_ispin(bp)
end_define

begin_function_decl
name|xfs_buf_t
modifier|*
name|xfs_buf_read_flags
parameter_list|(
name|xfs_buftarg_t
modifier|*
parameter_list|,
name|xfs_daddr_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|xfs_buf_read
parameter_list|(
name|target
parameter_list|,
name|blkno
parameter_list|,
name|len
parameter_list|,
name|flags
parameter_list|)
define|\
value|xfs_buf_read_flags(target, blkno, len, \                        XFS_BUF_LOCK | XFS_BUF_MAPPED)
end_define

begin_function_decl
name|xfs_buf_t
modifier|*
name|xfs_buf_get_flags
parameter_list|(
name|xfs_buftarg_t
modifier|*
parameter_list|,
name|xfs_daddr_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|xfs_buf_get
parameter_list|(
name|target
parameter_list|,
name|blkno
parameter_list|,
name|len
parameter_list|,
name|flags
parameter_list|)
define|\
value|xfs_buf_get_flags(target, blkno, len, \                        XFS_BUF_LOCK | XFS_BUF_MAPPED)
end_define

begin_define
define|#
directive|define
name|xfs_bdwrite
parameter_list|(
name|mp
parameter_list|,
name|bp
parameter_list|)
value|bdwrite(bp)
end_define

begin_comment
comment|/* 	{ ((bp)->b_vp == NULL) ? (bp)->b_bdstrat = xfs_bdstrat_cb: 0; \ 		(bp)->b_fsprivate3 = (mp); bdwrite(bp);} */
end_comment

begin_define
define|#
directive|define
name|xfs_bawrite
parameter_list|(
name|mp
parameter_list|,
name|bp
parameter_list|)
value|bawrite(bp)
end_define

begin_comment
comment|/* 	{ ((bp)->b_vp == NULL) ? (bp)->b_bdstrat = xfs_bdstrat_cb: 0; \ 		(bp)->b_fsprivate3 = (mp); bawrite(bp);} */
end_comment

begin_define
define|#
directive|define
name|xfs_buf_relse
parameter_list|(
name|bp
parameter_list|)
value|brelse(bp)
end_define

begin_define
define|#
directive|define
name|xfs_bp_mapin
parameter_list|(
name|bp
parameter_list|)
value|bp_mapin(bp)
end_define

begin_define
define|#
directive|define
name|xfs_xfsd_list_evict
parameter_list|(
name|x
parameter_list|)
value|_xfs_xfsd_list_evict(x)
end_define

begin_define
define|#
directive|define
name|xfs_buftrace
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|CTR2(KTR_BUF, "%s bp %p flags %X", bp, bp->b_flags)
end_define

begin_define
define|#
directive|define
name|xfs_biodone
parameter_list|(
name|bp
parameter_list|)
value|bufdone_finish(bp)
end_define

begin_define
define|#
directive|define
name|xfs_incore
parameter_list|(
name|xfs_buftarg
parameter_list|,
name|blkno
parameter_list|,
name|len
parameter_list|,
name|lockit
parameter_list|)
define|\
value|incore(&xfs_buftarg->specvp->v_bufobj, blkno);
end_define

begin_define
define|#
directive|define
name|xfs_biomove
parameter_list|(
name|pb
parameter_list|,
name|off
parameter_list|,
name|len
parameter_list|,
name|data
parameter_list|,
name|rw
parameter_list|)
define|\
value|panic("%s:%d: xfs_biomove NI", __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|xfs_biozero
parameter_list|(
name|pb
parameter_list|,
name|off
parameter_list|,
name|len
parameter_list|)
define|\
value|panic("%s:%d: xfs_biozero NI", __FILE__, __LINE__)
end_define

begin_comment
comment|/* already a function xfs_bwrite... fix this */
end_comment

begin_define
define|#
directive|define
name|XFS_bdwrite
parameter_list|(
name|bp
parameter_list|)
value|bdwrite(bp)
end_define

begin_define
define|#
directive|define
name|xfs_iowait
parameter_list|(
name|bp
parameter_list|)
value|bufwait(bp)
end_define

begin_define
define|#
directive|define
name|xfs_binval
parameter_list|(
name|buftarg
parameter_list|)
value|printf("binval(buftarg.dev) NI\n")
end_define

begin_define
define|#
directive|define
name|XFS_bflush
parameter_list|(
name|buftarg
parameter_list|)
value|printf("bflush(buftarg.dev) NI\n")
end_define

begin_define
define|#
directive|define
name|XFS_bdstrat
parameter_list|(
name|bp
parameter_list|)
value|printf("XFS_bdstrat NI\n")
end_define

begin_define
define|#
directive|define
name|xfs_incore_relse
parameter_list|(
name|buftarg
parameter_list|,
name|delwri_only
parameter_list|,
name|wait
parameter_list|)
define|\
value|printf("incore_relse(buftarg.dev,delwri_only,wait) NI\n")
end_define

begin_define
define|#
directive|define
name|xfs_incore_match
parameter_list|(
name|buftarg
parameter_list|,
name|blkno
parameter_list|,
name|len
parameter_list|,
name|field
parameter_list|,
name|value
parameter_list|)
define|\
value|printf("incore_match(buftarg.dev,blkno,len,field,value) NI \n")
end_define

begin_function_decl
name|void
name|xfs_baread
parameter_list|(
name|xfs_buftarg_t
modifier|*
name|targp
parameter_list|,
name|xfs_daddr_t
name|ioff
parameter_list|,
name|size_t
name|isize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pdflush
parameter_list|(
name|struct
name|vnode
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|XFS_pdflush
parameter_list|(
name|vnode
parameter_list|,
name|flags
parameter_list|)
define|\
value|pdflush(vnode,flags)
end_define

begin_struct_decl
struct_decl|struct
name|xfs_mount
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|XFS_bwrite
parameter_list|(
name|xfs_buf_t
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_buf_t
modifier|*
name|xfs_buf_get_empty
parameter_list|(
name|size_t
parameter_list|,
name|xfs_buftarg_t
modifier|*
name|targ
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|xfs_buf_t
modifier|*
name|xfs_buf_get_noaddr
parameter_list|(
name|size_t
parameter_list|,
name|xfs_buftarg_t
modifier|*
name|targ
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_buf_free
parameter_list|(
name|xfs_buf_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_buf_iorequest
parameter_list|(
name|struct
name|xfs_buf
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|XFS_freerbuf
parameter_list|(
name|xfs_buf_t
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|XFS_nfreerbuf
parameter_list|(
name|xfs_buf_t
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_bpin
parameter_list|(
name|xfs_buf_t
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_bunpin
parameter_list|(
name|xfs_buf_t
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|xfs_ispin
parameter_list|(
name|xfs_buf_t
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xfs_bwait_unpin
parameter_list|(
name|xfs_buf_t
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

