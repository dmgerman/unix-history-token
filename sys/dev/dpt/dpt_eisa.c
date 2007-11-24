begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 2000 Matthew N. Dodd<winter@jurai.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<dev/eisa/eisaconf.h>
end_include

begin_include
include|#
directive|include
file|<cam/scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<dev/dpt/dpt.h>
end_include

begin_define
define|#
directive|define
name|DPT_EISA_IOSIZE
value|0x9
end_define

begin_define
define|#
directive|define
name|DPT_EISA_SLOT_OFFSET
value|0x0c00
end_define

begin_define
define|#
directive|define
name|DPT_EISA_EATA_REG_OFFSET
value|0x0088
end_define

begin_define
define|#
directive|define
name|DPT_EISA_DPT2402
value|0x12142402
end_define

begin_comment
comment|/* DPT PM2012A/9X	*/
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_DPTA401
value|0x1214A401
end_define

begin_comment
comment|/* DPT PM2012B/9X	*/
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_DPTA402
value|0x1214A402
end_define

begin_comment
comment|/* DPT PM2012B2/9X	*/
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_DPTA410
value|0x1214A410
end_define

begin_comment
comment|/* DPT PM2x22A/9X	*/
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_DPTA411
value|0x1214A411
end_define

begin_comment
comment|/* DPT Spectre		*/
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_DPTA412
value|0x1214A412
end_define

begin_comment
comment|/* DPT PM2021A/9X	*/
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_DPTA420
value|0x1214A420
end_define

begin_comment
comment|/* DPT Smart Cache IV (PM2042) */
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_DPTA501
value|0x1214A501
end_define

begin_comment
comment|/* DPT PM2012B1/9X"	*/
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_DPTA502
value|0x1214A502
end_define

begin_comment
comment|/* DPT PM2012Bx/9X	*/
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_DPTA701
value|0x1214A701
end_define

begin_comment
comment|/* DPT PM2011B1/9X	*/
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_DPTBC01
value|0x1214BC01
end_define

begin_comment
comment|/* DPT PM3011/7X ESDI	*/
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_DPT8200
value|0x12148200
end_define

begin_comment
comment|/* NEC EATA SCSI	*/
end_comment

begin_define
define|#
directive|define
name|DPT_EISA_DPT2408
value|0x12142408
end_define

begin_comment
comment|/* ATT EATA SCSI	*/
end_comment

begin_comment
comment|/* Function Prototypes */
end_comment

begin_function_decl
specifier|static
specifier|const
name|char
modifier|*
name|dpt_eisa_match
parameter_list|(
name|eisa_id_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|dpt_eisa_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|dpt_eisa_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|int
name|dpt_eisa_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
name|u_int32_t
name|io_base
decl_stmt|;
name|dpt_conf_t
modifier|*
name|conf
decl_stmt|;
name|desc
operator|=
name|dpt_eisa_match
argument_list|(
name|eisa_get_id
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|desc
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
name|desc
argument_list|)
expr_stmt|;
name|io_base
operator|=
operator|(
name|eisa_get_slot
argument_list|(
name|dev
argument_list|)
operator|*
name|EISA_SLOT_SIZE
operator|)
operator|+
name|DPT_EISA_SLOT_OFFSET
operator|+
name|DPT_EISA_EATA_REG_OFFSET
expr_stmt|;
name|conf
operator|=
name|dpt_pio_get_conf
argument_list|(
name|io_base
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|conf
condition|)
block|{
name|printf
argument_list|(
literal|"dpt: dpt_pio_get_conf() failed.\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
name|eisa_add_iospace
argument_list|(
name|dev
argument_list|,
name|io_base
argument_list|,
name|DPT_EISA_IOSIZE
argument_list|,
name|RESVADDR_NONE
argument_list|)
expr_stmt|;
name|eisa_add_intr
argument_list|(
name|dev
argument_list|,
name|conf
operator|->
name|IRQ
argument_list|,
operator|(
name|conf
operator|->
name|IRQ_TR
condition|?
name|EISA_TRIGGER_LEVEL
else|:
name|EISA_TRIGGER_EDGE
operator|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|dpt_eisa_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|dpt_softc_t
modifier|*
name|dpt
decl_stmt|;
name|int
name|s
decl_stmt|;
name|int
name|error
init|=
literal|0
decl_stmt|;
name|dpt
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|dpt
operator|->
name|io_rid
operator|=
literal|0
expr_stmt|;
name|dpt
operator|->
name|io_type
operator|=
name|SYS_RES_IOPORT
expr_stmt|;
name|dpt
operator|->
name|irq_rid
operator|=
literal|0
expr_stmt|;
name|error
operator|=
name|dpt_alloc_resources
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
goto|goto
name|bad
goto|;
block|}
name|dpt_alloc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
comment|/* Allocate a dmatag representing the capabilities of this attachment */
comment|/* XXX Should be a child of the EISA bus dma tag */
if|if
condition|(
name|bus_dma_tag_create
argument_list|(
comment|/* parent    */
name|NULL
argument_list|,
comment|/* alignemnt */
literal|1
argument_list|,
comment|/* boundary  */
literal|0
argument_list|,
comment|/* lowaddr   */
name|BUS_SPACE_MAXADDR_32BIT
argument_list|,
comment|/* highaddr  */
name|BUS_SPACE_MAXADDR
argument_list|,
comment|/* filter    */
name|NULL
argument_list|,
comment|/* filterarg */
name|NULL
argument_list|,
comment|/* maxsize   */
name|BUS_SPACE_MAXSIZE_32BIT
argument_list|,
comment|/* nsegments */
operator|~
literal|0
argument_list|,
comment|/* maxsegsz  */
name|BUS_SPACE_MAXSIZE_32BIT
argument_list|,
comment|/* flags     */
literal|0
argument_list|,
comment|/* lockfunc  */
name|busdma_lock_mutex
argument_list|,
comment|/* lockarg   */
operator|&
name|Giant
argument_list|,
operator|&
name|dpt
operator|->
name|parent_dmat
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|error
operator|=
name|ENXIO
expr_stmt|;
goto|goto
name|bad
goto|;
block|}
name|s
operator|=
name|splcam
argument_list|()
expr_stmt|;
if|if
condition|(
name|dpt_init
argument_list|(
name|dpt
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|error
operator|=
name|ENXIO
expr_stmt|;
goto|goto
name|bad
goto|;
block|}
comment|/* Register with the XPT */
name|dpt_attach
argument_list|(
name|dpt
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
if|if
condition|(
name|bus_setup_intr
argument_list|(
name|dev
argument_list|,
name|dpt
operator|->
name|irq_res
argument_list|,
name|INTR_TYPE_CAM
operator||
name|INTR_ENTROPY
argument_list|,
name|dpt_intr
argument_list|,
name|dpt
argument_list|,
operator|&
name|dpt
operator|->
name|ih
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Unable to register interrupt handler\n"
argument_list|)
expr_stmt|;
name|error
operator|=
name|ENXIO
expr_stmt|;
goto|goto
name|bad
goto|;
block|}
return|return
operator|(
name|error
operator|)
return|;
name|bad
label|:
name|dpt_release_resources
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|dpt_free
argument_list|(
name|dpt
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|dpt_eisa_match
parameter_list|(
name|type
parameter_list|)
name|eisa_id_t
name|type
decl_stmt|;
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|DPT_EISA_DPT2402
case|:
case|case
name|DPT_EISA_DPTA401
case|:
case|case
name|DPT_EISA_DPTA402
case|:
case|case
name|DPT_EISA_DPTA410
case|:
case|case
name|DPT_EISA_DPTA411
case|:
case|case
name|DPT_EISA_DPTA412
case|:
case|case
name|DPT_EISA_DPTA420
case|:
case|case
name|DPT_EISA_DPTA501
case|:
case|case
name|DPT_EISA_DPTA502
case|:
case|case
name|DPT_EISA_DPTA701
case|:
case|case
name|DPT_EISA_DPTBC01
case|:
case|case
name|DPT_EISA_DPT8200
case|:
case|case
name|DPT_EISA_DPT2408
case|:
return|return
operator|(
literal|"DPT SCSI Host Bus Adapter"
operator|)
return|;
break|break;
default|default:
break|break;
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|dpt_eisa_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|dpt_eisa_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|dpt_eisa_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|dpt_detach
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|dpt_eisa_driver
init|=
block|{
literal|"dpt"
block|,
name|dpt_eisa_methods
block|,
sizeof|sizeof
argument_list|(
name|dpt_softc_t
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|dpt
argument_list|,
name|eisa
argument_list|,
name|dpt_eisa_driver
argument_list|,
name|dpt_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|dpt
argument_list|,
name|eisa
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|dpt
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

