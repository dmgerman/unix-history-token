begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*------------------------------------------------------------------  * octeon_fau.c        Fetch& Add Block  *  *------------------------------------------------------------------  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<mips/cavium/octeon_pcmap_regs.h>
end_include

begin_include
include|#
directive|include
file|"octeon_fau.h"
end_include

begin_comment
comment|/*  * oct_fau_init  *  * How do we initialize FAU unit. I don't even think we can reset it.  */
end_comment

begin_function
name|void
name|octeon_fau_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/*  * oct_fau_enable  *  * Let the Fetch/Add unit roll  */
end_comment

begin_function
name|void
name|octeon_fau_enable
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|/*  * oct_fau_disable  *  * disable fau  *  * Don't know if we can even do that.  */
end_comment

begin_function
name|void
name|octeon_fau_disable
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

end_unit

