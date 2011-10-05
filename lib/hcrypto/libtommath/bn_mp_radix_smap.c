begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_RADIX_SMAP_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* chars used in radix conversions */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|mp_s_rmap
init|=
literal|"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_radix_smap.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

