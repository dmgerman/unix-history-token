begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)machparam.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_comment
comment|/*  * Machine dependent constants for vax.  */
end_comment

begin_define
define|#
directive|define
name|NBPG
value|512
end_define

begin_comment
comment|/* bytes/page */
end_comment

begin_define
define|#
directive|define
name|PGOFSET
value|(NBPG-1)
end_define

begin_comment
comment|/* byte offset into page */
end_comment

begin_define
define|#
directive|define
name|PGSHIFT
value|9
end_define

begin_comment
comment|/* LOG2(NBPG) */
end_comment

begin_define
define|#
directive|define
name|CLSIZE
value|2
end_define

begin_define
define|#
directive|define
name|CLSIZELOG2
value|1
end_define

begin_define
define|#
directive|define
name|SSIZE
value|4
end_define

begin_comment
comment|/* initial stack size/NBPG */
end_comment

begin_define
define|#
directive|define
name|SINCR
value|4
end_define

begin_comment
comment|/* increment of stack/NBPG */
end_comment

begin_define
define|#
directive|define
name|UPAGES
value|10
end_define

begin_comment
comment|/* pages of u-area */
end_comment

begin_comment
comment|/*  * Some macros for units conversion  */
end_comment

begin_comment
comment|/* Core clicks (512 bytes) to segments and vice versa */
end_comment

begin_define
define|#
directive|define
name|ctos
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|stoc
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* Core clicks (512 bytes) to disk blocks */
end_comment

begin_define
define|#
directive|define
name|ctod
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|dtoc
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|dtob
parameter_list|(
name|x
parameter_list|)
value|((x)<<9)
end_define

begin_comment
comment|/* clicks to bytes */
end_comment

begin_define
define|#
directive|define
name|ctob
parameter_list|(
name|x
parameter_list|)
value|((x)<<9)
end_define

begin_comment
comment|/* bytes to clicks */
end_comment

begin_define
define|#
directive|define
name|btoc
parameter_list|(
name|x
parameter_list|)
value|((((unsigned)(x)+511)>>9))
end_define

begin_comment
comment|/*  * Macros to decode processor status word.  */
end_comment

begin_define
define|#
directive|define
name|USERMODE
parameter_list|(
name|ps
parameter_list|)
value|(((ps)& PSL_CURMOD) == PSL_CURMOD)
end_define

begin_define
define|#
directive|define
name|BASEPRI
parameter_list|(
name|ps
parameter_list|)
value|(((ps)& PSL_IPL) == 0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_decl_stmt
name|int
name|cpuspeed
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register int N = cpuspeed * (n); while (--N> 0); }
end_define

begin_else
else|#
directive|else
else|KERNEL
end_else

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register int N = (n); while (--N> 0); }
end_define

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

end_unit

