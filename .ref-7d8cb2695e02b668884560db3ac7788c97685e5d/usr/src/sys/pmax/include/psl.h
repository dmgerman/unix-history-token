begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)psl.h	7.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<machine/machConst.h>
end_include

begin_define
define|#
directive|define
name|PSL_LOWIPL
value|(MACH_INT_MASK | MACH_SR_INT_ENA_CUR)
end_define

begin_define
define|#
directive|define
name|PSL_USERSET
value|(	\ 	MACH_SR_KU_OLD |	\ 	MACH_SR_INT_ENA_OLD |	\ 	MACH_SR_KU_PREV |	\ 	MACH_SR_INT_ENA_PREV |	\ 	MACH_INT_MASK)
end_define

begin_define
define|#
directive|define
name|PSL_USERCLR
value|(	\ 	MACH_SR_COP_USABILITY |	\ 	MACH_SR_BOOT_EXC_VEC |	\ 	MACH_SR_TLB_SHUTDOWN |	\ 	MACH_SR_PARITY_ERR |	\ 	MACH_SR_CACHE_MISS |	\ 	MACH_SR_PARITY_ZERO |	\ 	MACH_SR_SWAP_CACHES |	\ 	MACH_SR_ISOL_CACHES |	\ 	MACH_SR_KU_CUR |	\ 	MACH_SR_INT_ENA_CUR |	\ 	MACH_SR_MBZ)
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
value|((ps)& MACH_SR_KU_PREV)
end_define

begin_define
define|#
directive|define
name|BASEPRI
parameter_list|(
name|ps
parameter_list|)
value|(((ps)& (MACH_INT_MASK | MACH_SR_INT_ENA_PREV)) \ 			== (MACH_INT_MASK | MACH_SR_INT_ENA_PREV))
end_define

end_unit

