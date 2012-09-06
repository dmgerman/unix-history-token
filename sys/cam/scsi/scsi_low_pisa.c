begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NecBSD: scsi_low_pisa.c,v 1.13.18.1 2001/06/08 06:27:48 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*-  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1995, 1996, 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *  Copyright (c) 1995, 1996, 1997, 1998  *	Naofumi HONDA. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bio.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_low.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_low_pisa.h>
end_include

begin_function
name|int
name|scsi_low_deactivate_pisa
parameter_list|(
name|sc
parameter_list|)
name|struct
name|scsi_low_softc
modifier|*
name|sc
decl_stmt|;
block|{
if|if
condition|(
name|scsi_low_deactivate
argument_list|(
name|sc
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|EBUSY
return|;
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|scsi_low_activate_pisa
parameter_list|(
name|sc
parameter_list|,
name|flags
parameter_list|)
name|struct
name|scsi_low_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|{
name|sc
operator|->
name|sl_cfgflags
operator|=
operator|(
operator|(
name|sc
operator|->
name|sl_cfgflags
operator|&
literal|0xffff0000
operator|)
operator||
operator|(
name|flags
operator|&
literal|0x00ff
operator|)
operator|)
expr_stmt|;
if|if
condition|(
name|scsi_low_activate
argument_list|(
name|sc
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|EBUSY
return|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|moduledata_t
name|scsi_low_moduledata
init|=
block|{
literal|"scsi_low"
block|,
name|NULL
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DECLARE_MODULE
argument_list|(
name|scsi_low
argument_list|,
name|scsi_low_moduledata
argument_list|,
name|SI_SUB_DRIVERS
argument_list|,
name|SI_ORDER_MIDDLE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|scsi_low
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|scsi_low
argument_list|,
name|cam
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

