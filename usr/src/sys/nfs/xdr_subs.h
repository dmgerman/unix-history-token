begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Rick Macklem at The University of Guelph.  *  * %sccs.include.redist.c%  *  *	@(#)xdr_subs.h	7.4 (Berkeley) %G%  */
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
name|fxdr_time
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	((struct timeval *)(t))->tv_sec = \ 		ntohl(((struct timeval *)(f))->tv_sec); \ 	((struct timeval *)(t))->tv_usec = \ 		ntohl(((struct timeval *)(f))->tv_usec); \ }
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
name|txdr_time
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
value|{ \ 	((struct timeval *)(t))->tv_sec = \ 		htonl(((struct timeval *)(f))->tv_sec); \ 	((struct timeval *)(t))->tv_usec = \ 		htonl(((struct timeval *)(f))->tv_usec); \ }
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
name|fxdr_time
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
define|\
value|*((struct timeval *)(t)) = *((struct timeval *)(f))
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
name|txdr_time
parameter_list|(
name|f
parameter_list|,
name|t
parameter_list|)
define|\
value|*((struct timeval *)(t)) = *((struct timeval *)(f))
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

