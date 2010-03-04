begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  *  Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights  *  reserved.  *  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions are  *  met:  *  *      * Redistributions of source code must retain the above copyright  *        notice, this list of conditions and the following disclaimer.  *  *      * Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials provided  *        with the distribution.  *  *      * Neither the name of Cavium Networks nor the names of  *        its contributors may be used to endorse or promote products  *        derived from this software without specific prior written  *        permission.  *  *  TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  *  AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS  *  OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH  *  RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY  *  REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT  *  DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES  *  OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR  *  PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET  *  POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT  *  OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  *  *  *  For any questions regarding licensing please contact marketing@caviumnetworks.com  *  ***********************license end**************************************/
end_comment

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

