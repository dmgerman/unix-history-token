begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Julian Elischer (julian@tfs.com)  * for TRW Financial Systems for use under the MACH(2.5) operating system.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with  * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  *      $Id$  */
end_comment

begin_comment
comment|/*  * Bulogic/Bustek 32 bit Addressing Mode SCSI driver.  *  * NOTE: 1. Some bt5xx card can NOT handle 32 bit addressing mode.  *       2. OLD bt445s Revision A,B,C,D(nowired) + any firmware version  *          has broken busmaster for handling 32 bit addressing on H/W bus  *	    side.  *  *       3. Extended probing still needs confirmation from our user base, due  *	    to several H/W and firmware dependencies. If you have a problem  *	    with extended probing, please contact 'amurai@spec.co.jp'  *  *						amurai@spec.co.jp 94/6/16  */
end_comment

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
file|<scsi/scsi_all.h>
end_include

begin_include
include|#
directive|include
file|<scsi/scsiconf.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_include
include|#
directive|include
file|<i386/scsi/btreg.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|bt_isa_probe
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|bt_isa_attach
name|__P
argument_list|(
operator|(
expr|struct
name|isa_device
operator|*
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|isa_driver
name|btdriver
init|=
block|{
name|bt_isa_probe
block|,
name|bt_isa_attach
block|,
literal|"bt"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Check if the device can be found at the port given  * and if so, set it up ready for further work  * as an argument, takes the isa_device structure from  * autoconf.c  */
end_comment

begin_function
specifier|static
name|int
name|bt_isa_probe
parameter_list|(
name|dev
parameter_list|)
name|struct
name|isa_device
modifier|*
name|dev
decl_stmt|;
block|{
comment|/* 	 * find unit and check we have that many defined 	 */
name|int
name|unit
init|=
name|bt_unit
decl_stmt|;
name|struct
name|bt_data
modifier|*
name|bt
decl_stmt|;
comment|/* 	 * We ignore the unit number assigned by config to allow 	 * consistant numbering between PCI/EISA/ISA devices. 	 * This is a total kludge until we have a configuration 	 * manager. 	 */
name|dev
operator|->
name|id_unit
operator|=
name|bt_unit
expr_stmt|;
comment|/* 	 * Allocate a storage area for us 	 */
name|bt
operator|=
name|bt_alloc
argument_list|(
name|unit
argument_list|,
name|dev
operator|->
name|id_iobase
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|bt
condition|)
return|return
literal|0
return|;
comment|/* 	 * Try initialise a unit at this location 	 * sets up dma and bus speed, loads bt->bt_int 	 */
if|if
condition|(
name|bt_init
argument_list|(
name|bt
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|bt_free
argument_list|(
name|bt
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* 	 * If it's there, put in it's interrupt vectors 	 */
name|dev
operator|->
name|id_unit
operator|=
name|unit
expr_stmt|;
name|dev
operator|->
name|id_irq
operator|=
operator|(
literal|1
operator|<<
name|bt
operator|->
name|bt_int
operator|)
expr_stmt|;
name|dev
operator|->
name|id_drq
operator|=
name|bt
operator|->
name|bt_dma
expr_stmt|;
name|bt_unit
operator|++
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * Attach all the sub-devices we can find  */
end_comment

begin_function
specifier|static
name|int
name|bt_isa_attach
parameter_list|(
name|dev
parameter_list|)
name|struct
name|isa_device
modifier|*
name|dev
decl_stmt|;
block|{
name|int
name|unit
init|=
name|dev
operator|->
name|id_unit
decl_stmt|;
name|struct
name|bt_data
modifier|*
name|bt
init|=
name|btdata
index|[
name|unit
index|]
decl_stmt|;
return|return
operator|(
name|bt_attach
argument_list|(
name|bt
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Handle an ISA interrupt.  * XXX should go away as soon as ISA interrupt handlers  * take a (void *) arg.  */
end_comment

begin_function
name|void
name|bt_isa_intr
parameter_list|(
name|unit
parameter_list|)
name|int
name|unit
decl_stmt|;
block|{
name|struct
name|bt_data
modifier|*
name|arg
init|=
name|btdata
index|[
name|unit
index|]
decl_stmt|;
name|bt_intr
argument_list|(
operator|(
name|void
operator|*
operator|)
name|arg
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

