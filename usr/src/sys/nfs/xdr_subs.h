begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * %sccs.include.redist.c%  *  *	@(#)xdr_subs.h	7.5 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Macros used for conversion to/from xdr representation by nfs...  * These use the MACHINE DEPENDENT routines ntohl, htonl  * As defined by "XDR: External Data Representation Standard" RFC1014  */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|fxdr_unsigned
parameter_list|(
name|t
parameter_list|,
name|v
parameter_list|)
value|((t)ntohl((long)(v)))
end_define

begin_define
define|#
directive|define
name|fxdr_nfstime
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	(t)->ts_sec = \ 		ntohl(((struct nfsv2_time *)(f))->nfs_sec); \ 	(t)->ts_nsec = 1000 * \ 		ntohl(((struct nfsv2_time *)(f))->nfs_usec); \ }
end_define

begin_define
define|#
directive|define
name|fxdr_nqtime
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	(t)->ts_sec = \ 		ntohl(((struct nqnfs_time *)(f))->nq_sec); \ 	(t)->ts_nsec = \ 		ntohl(((struct nqnfs_time *)(f))->nq_nsec); \ }
end_define

begin_comment
comment|/*  * To handle quad conversions, define a struct of two longs and use  * ntohl and htonl. Maybe someday there should be ntohq and htonq?  */
end_comment

begin_union
union|union
name|_hq
block|{
name|quad_t
name|hq
decl_stmt|;
struct|struct
block|{
name|long
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|lq
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|fxdr_hyper
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	((union _hq *)(t))->lq.val[1] = ntohl(((union _hq *)(f))->lq.val[0]); \ 	((union _hq *)(t))->lq.val[0] = ntohl(((union _hq *)(f))->lq.val[1]); \ }
end_define

begin_define
define|#
directive|define
name|txdr_hyper
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	((union _hq *)(t))->lq.val[0] = htonl(((union _hq *)(f))->lq.val[1]); \ 	((union _hq *)(t))->lq.val[1] = htonl(((union _hq *)(f))->lq.val[0]); \ }
end_define

begin_define
define|#
directive|define
name|txdr_unsigned
parameter_list|(
name|v
parameter_list|)
value|(htonl((long)(v)))
end_define

begin_define
define|#
directive|define
name|txdr_nqtime
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	((struct nqnfs_time *)(t))->nq_sec = \ 		htonl((f)->ts_sec); \ 	((struct nqnfs_time *)(t))->nq_nsec = \ 		htonl((f)->ts_nsec); \ }
end_define

begin_define
define|#
directive|define
name|txdr_nfstime
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	((struct nfsv2_time *)(t))->nfs_sec = \ 		htonl((f)->ts_sec); \ 	((struct nfsv2_time *)(t))->nfs_usec = \ 		htonl((f)->ts_nsec) / 1000; \ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* BIG_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|fxdr_unsigned
parameter_list|(
name|t
parameter_list|,
name|v
parameter_list|)
value|((t)(v))
end_define

begin_define
define|#
directive|define
name|fxdr_nqtime
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
define|\
value|*(t) = *((struct timespec *)(f))
end_define

begin_define
define|#
directive|define
name|fxdr_nfstime
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	(t)->ts_sec = ((struct nfsv2_time *)(f))->nfs_sec; \ 	(t)->ts_nsec = ((struct nfsv2_time *)(f))->nfs_usec * 1000; \ }
end_define

begin_define
define|#
directive|define
name|fxdr_hyper
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
define|\
value|*((quad_t *)(t)) = *((quad_t *)(f))
end_define

begin_define
define|#
directive|define
name|txdr_unsigned
parameter_list|(
name|v
parameter_list|)
value|((long)(v))
end_define

begin_define
define|#
directive|define
name|txdr_nqtime
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
define|\
value|*(t) = *((struct timespec *)(f))
end_define

begin_define
define|#
directive|define
name|txdr_nfstime
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	((struct nfsv2_time *)(t))->nfs_sec = (f)->ts_sec; \ 	((struct nfsv2_time *)(t))->nfs_usec = (f)->ts_nsec / 1000; \ }
end_define

begin_define
define|#
directive|define
name|txdr_hyper
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
define|\
value|*((quad_t *)(t)) = *((quad_t *)(f))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENDIAN */
end_comment

end_unit

