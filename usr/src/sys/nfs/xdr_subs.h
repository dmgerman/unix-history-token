begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * %sccs.include.redist.c%  *  *	@(#)xdr_subs.h	8.3 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NFS_XDR_SUBS_H_
end_ifndef

begin_define
define|#
directive|define
name|_NFS_XDR_SUBS_H_
end_define

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
name|fxdr_nfsv2time
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	(t)->ts_sec = ntohl(((struct nfsv2_time *)(f))->nfsv2_sec); \ 	if (((struct nfsv2_time *)(f))->nfsv2_usec != 0xffffffff) \ 		(t)->ts_nsec = 1000 * ntohl(((struct nfsv2_time *)(f))->nfsv2_usec); \ 	else \ 		(t)->ts_nsec = 0; \ }
end_define

begin_define
define|#
directive|define
name|txdr_nfsv2time
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	((struct nfsv2_time *)(t))->nfsv2_sec = htonl((f)->ts_sec); \ 	if ((f)->ts_nsec != -1) \ 		((struct nfsv2_time *)(t))->nfsv2_usec = htonl((f)->ts_nsec / 1000); \ 	else \ 		((struct nfsv2_time *)(t))->nfsv2_usec = 0xffffffff; \ }
end_define

begin_define
define|#
directive|define
name|fxdr_nfsv3time
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	(t)->ts_sec = ntohl(((struct nfsv3_time *)(f))->nfsv3_sec); \ 	(t)->ts_nsec = ntohl(((struct nfsv3_time *)(f))->nfsv3_nsec); \ }
end_define

begin_define
define|#
directive|define
name|txdr_nfsv3time
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	((struct nfsv3_time *)(t))->nfsv3_sec = htonl((f)->ts_sec); \ 	((struct nfsv3_time *)(t))->nfsv3_nsec = htonl((f)->ts_nsec); \ }
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

