begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Product specific probe and attach routines for:  *      294X and aic7870 motherboard SCSI controllers  *  * Copyright (c) 1995 Justin T. Gibbs  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    Justin T. Gibbs.  * 4. Modifications may be freely made to this file if the above conditions  *    are met.  *  *	$Id: aic7870.c,v 1.2 1995/01/16 16:31:57 gibbs Exp $  */
end_comment

begin_include
include|#
directive|include
file|<pci.h>
end_include

begin_if
if|#
directive|if
name|NPCI
operator|>
literal|0
end_if

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
file|<i386/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<i386/scsi/aic7xxx.h>
end_include

begin_define
define|#
directive|define
name|PCI_BASEADR0
value|PCI_MAP_REG_START
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_ADAPTEC_2940
value|0x71789004ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_ADAPTEC_AIC7870
value|0x70789004ul
end_define

begin_decl_stmt
specifier|static
name|char
modifier|*
name|aic7870_probe
name|__P
argument_list|(
operator|(
name|pcici_t
name|tag
operator|,
name|pcidi_t
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|aic7870_attach
name|__P
argument_list|(
operator|(
name|pcici_t
name|config_id
operator|,
name|int
name|unit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_long
name|aic7870_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pci_driver
name|ahc_device
init|=
block|{
name|aic7870_probe
block|,
name|aic7870_attach
block|,
operator|&
name|aic7870_count
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|char
modifier|*
name|aic7870_probe
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|pcidi_t
name|type
parameter_list|)
block|{
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|PCI_DEVICE_ID_ADAPTEC_2940
case|:
return|return
operator|(
literal|"Adaptec 294X SCSI host adapter"
operator|)
return|;
break|break;
case|case
name|PCI_DEVICE_ID_ADAPTEC_AIC7870
case|:
return|return
operator|(
literal|"Adaptec aic7870 SCSI host adapter"
operator|)
return|;
break|break;
default|default:
break|break;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|void
name|aic7870_attach
parameter_list|(
name|config_id
parameter_list|,
name|unit
parameter_list|)
name|pcici_t
name|config_id
decl_stmt|;
name|int
name|unit
decl_stmt|;
block|{
name|u_long
name|io_port
decl_stmt|;
if|if
condition|(
operator|!
operator|(
name|io_port
operator|=
name|pci_conf_read
argument_list|(
name|config_id
argument_list|,
name|PCI_BASEADR0
argument_list|)
operator|)
condition|)
return|return;
name|io_port
operator|-=
literal|0xc01ul
expr_stmt|;
comment|/* 	printf("io_port = 0x%lx\n", io_port); 				 * Make the offsets the same as for EISA  				 * The first bit of PCI_BASEADR0 is always 				 * set hence we subtract 0xc01 instead of the 				 * 0xc00 that you would expect. 				 */
if|if
condition|(
name|ahcprobe
argument_list|(
name|unit
argument_list|,
name|io_port
argument_list|,
name|AHC_294
argument_list|)
condition|)
block|{
name|ahc_unit
operator|++
expr_stmt|;
if|if
condition|(
name|ahc_attach
argument_list|(
name|unit
argument_list|)
condition|)
comment|/* 			 * To be compatible with the isa style of  			 * interrupt handler, we pass the unit number 			 * not a pointer to our per device structure. 			 */
name|pci_map_int
argument_list|(
name|config_id
argument_list|,
name|ahcintr
argument_list|,
operator|(
name|void
operator|*
operator|)
name|unit
argument_list|,
operator|&
name|bio_imask
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NPCI> 0 */
end_comment

end_unit

