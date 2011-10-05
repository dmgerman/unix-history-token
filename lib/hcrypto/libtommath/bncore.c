begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BNCORE_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* Known optimal configurations   CPU                    /Compiler     /MUL CUTOFF/SQR CUTOFF -------------------------------------------------------------  Intel P4 Northwood     /GCC v3.4.1   /        88/       128/LTM 0.32 ;-)  AMD Athlon64           /GCC v3.4.4   /        80/       120/LTM 0.35  */
end_comment

begin_decl_stmt
name|int
name|KARATSUBA_MUL_CUTOFF
init|=
literal|80
decl_stmt|,
comment|/* Min. number of digits before Karatsuba multiplication is used. */
name|KARATSUBA_SQR_CUTOFF
init|=
literal|120
decl_stmt|,
comment|/* Min. number of digits before Karatsuba squaring is used. */
name|TOOM_MUL_CUTOFF
init|=
literal|350
decl_stmt|,
comment|/* no optimal values of these are known yet so set em high */
name|TOOM_SQR_CUTOFF
init|=
literal|400
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bncore.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.5 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

