begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * %sccs.include.redist.c%  *  *	@(#)xdr_subs.h	7.7 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Macros used for conversion to/from xdr representation by nfs...  * These use the MACHINE DEPENDENT routines ntohl, htonl  * As defined by "XDR: External Data Representation Standard" RFC1014  *  * To simplify the implementation, we use ntohl/htonl even on big-endian  * machines, and count on them being `#define'd away.  Some of these  * might be slightly more efficient as quad_t copies on a big-endian,  * but we cannot count on their alignment anyway.  */
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
value|((t)ntohl((long)(v)))
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
name|fxdr_nfstime
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	(t)->ts_sec = ntohl(((struct nfsv2_time *)(f))->nfs_sec); \ 	(t)->ts_nsec = 1000 * ntohl(((struct nfsv2_time *)(f))->nfs_usec); \ }
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
value|{ \ 	((struct nfsv2_time *)(t))->nfs_sec = htonl((f)->ts_sec); \ 	((struct nfsv2_time *)(t))->nfs_usec = htonl((f)->ts_nsec) / 1000; \ }
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
value|{ \ 	(t)->ts_sec = ntohl(((struct nqnfs_time *)(f))->nq_sec); \ 	(t)->ts_nsec = ntohl(((struct nqnfs_time *)(f))->nq_nsec); \ }
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
value|{ \ 	((struct nqnfs_time *)(t))->nq_sec = htonl((f)->ts_sec); \ 	((struct nqnfs_time *)(t))->nq_nsec = htonl((f)->ts_nsec); \ }
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
value|{ \ 	((long *)(t))[_QUAD_HIGHWORD] = ntohl(((long *)(f))[0]); \ 	((long *)(t))[_QUAD_LOWWORD] = ntohl(((long *)(f))[1]); \ }
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
value|{ \ 	((long *)(t))[0] = htonl(((long *)(f))[_QUAD_HIGHWORD]); \ 	((long *)(t))[1] = htonl(((long *)(f))[_QUAD_LOWWORD]); \ }
end_define

end_unit

