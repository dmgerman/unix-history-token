begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	param.h	1.4	86/11/03	*/
end_comment

begin_comment
comment|/*  * Machine dependent constants for TAHOE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ENDIAN
end_ifndef

begin_comment
comment|/*  * Definitions for byte order,  * according to byte significance from low address to high.  */
end_comment

begin_define
define|#
directive|define
name|LITTLE
value|1234
end_define

begin_comment
comment|/* least-significant byte first (vax) */
end_comment

begin_define
define|#
directive|define
name|BIG
value|4321
end_define

begin_comment
comment|/* most-significant byte first */
end_comment

begin_define
define|#
directive|define
name|PDP
value|3412
end_define

begin_comment
comment|/* LSB first in word, MSW first in long (pdp) */
end_comment

begin_define
define|#
directive|define
name|ENDIAN
value|BIG
end_define

begin_comment
comment|/* byte order on tahoe */
end_comment

begin_define
define|#
directive|define
name|NBPG
value|1024
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
value|10
end_define

begin_comment
comment|/* LOG2(NBPG) */
end_comment

begin_define
define|#
directive|define
name|CLSIZE
value|1
end_define

begin_define
define|#
directive|define
name|CLSIZELOG2
value|0
end_define

begin_define
define|#
directive|define
name|SSIZE
value|2
end_define

begin_comment
comment|/* initial stack size/NBPG */
end_comment

begin_define
define|#
directive|define
name|SINCR
value|2
end_define

begin_comment
comment|/* increment of stack/NBPG */
end_comment

begin_define
define|#
directive|define
name|UPAGES
value|6
end_define

begin_comment
comment|/* pages of u-area (2 stack pages) */
end_comment

begin_define
define|#
directive|define
name|MAXCKEY
value|255
end_define

begin_comment
comment|/* maximal allowed code key */
end_comment

begin_define
define|#
directive|define
name|MAXDKEY
value|255
end_define

begin_comment
comment|/* maximal allowed data key */
end_comment

begin_define
define|#
directive|define
name|NCKEY
value|(MAXCKEY+1)
end_define

begin_comment
comment|/* # code keys, including 0 (reserved) */
end_comment

begin_define
define|#
directive|define
name|NDKEY
value|(MAXDKEY+1)
end_define

begin_comment
comment|/* # data keys, including 0 (reserved) */
end_comment

begin_comment
comment|/*  * Some macros for units conversion  */
end_comment

begin_comment
comment|/* Core clicks (1024 bytes) to segments and vice versa */
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
comment|/* Core clicks (1024 bytes) to disk blocks */
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
value|((x)<<PGSHIFT)
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
value|((x)<<PGSHIFT)
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
value|((((unsigned)(x)+NBPG-1)>> PGSHIFT))
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

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|{ register int N = 3*(n); while (--N> 0); }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

