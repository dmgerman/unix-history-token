begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Product specific probe and attach routines for:  *      3940, 2940, aic7870, and aic7850 SCSI controllers  *  * Copyright (c) 1995 Justin T. Gibbs  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author  *    Justin T. Gibbs.  * 4. Modifications may be freely made to this file if the above conditions  *    are met.  *  *	$Id: aic7870.c,v 1.15 1995/10/08 17:46:11 gibbs Exp $  */
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
file|<sys/malloc.h>
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
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
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
name|PCI_DEVICE_ID_ADAPTEC_2940U
value|0x81789004ul
end_define

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_ADAPTEC_3940
value|0x72789004ul
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

begin_define
define|#
directive|define
name|PCI_DEVICE_ID_ADAPTEC_AIC7850
value|0x50789004ul
end_define

begin_define
define|#
directive|define
name|DEVCONFIG
value|0x40
end_define

begin_define
define|#
directive|define
name|MPORTMODE
value|0x00000400ul
end_define

begin_comment
comment|/* aic7870 only */
end_comment

begin_define
define|#
directive|define
name|RAMPSM
value|0x00000200ul
end_define

begin_comment
comment|/* aic7870 only */
end_comment

begin_define
define|#
directive|define
name|VOLSENSE
value|0x00000100ul
end_define

begin_define
define|#
directive|define
name|DEVCONFIG7
value|0x00000080ul
end_define

begin_define
define|#
directive|define
name|MRDCEN
value|0x00000040ul
end_define

begin_define
define|#
directive|define
name|EXTSCBTIME
value|0x00000020ul
end_define

begin_comment
comment|/* aic7870 only */
end_comment

begin_define
define|#
directive|define
name|EXTSCBPEN
value|0x00000010ul
end_define

begin_comment
comment|/* aic7870 only */
end_comment

begin_define
define|#
directive|define
name|BERREN
value|0x00000008ul
end_define

begin_define
define|#
directive|define
name|DACEN
value|0x00000004ul
end_define

begin_define
define|#
directive|define
name|STPWLEVEL
value|0x00000002ul
end_define

begin_define
define|#
directive|define
name|DIFACTNEGEN
value|0x00000001ul
end_define

begin_comment
comment|/* aic7870 only */
end_comment

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
specifier|static
name|u_char
name|aic3940_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|pci_device
name|ahc_device
init|=
block|{
literal|"ahc"
block|,
name|aic7870_probe
block|,
name|aic7870_attach
block|,
operator|&
name|aic7870_count
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DATA_SET
argument_list|(
name|pcidevice_set
argument_list|,
name|ahc_device
argument_list|)
expr_stmt|;
end_expr_stmt

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
name|PCI_DEVICE_ID_ADAPTEC_3940
case|:
return|return
operator|(
literal|"Adaptec 3940 SCSI host adapter"
operator|)
return|;
break|break;
case|case
name|PCI_DEVICE_ID_ADAPTEC_2940U
case|:
return|return
operator|(
literal|"Adaptec 2940 Ultra SCSI host adapter"
operator|)
return|;
break|break;
case|case
name|PCI_DEVICE_ID_ADAPTEC_2940
case|:
return|return
operator|(
literal|"Adaptec 2940 SCSI host adapter"
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
case|case
name|PCI_DEVICE_ID_ADAPTEC_AIC7850
case|:
return|return
operator|(
literal|"Adaptec aic7850 SCSI host adapter"
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
name|unsigned
name|opri
init|=
literal|0
decl_stmt|;
name|ahc_type
name|ahc_t
init|=
name|AHC_NONE
decl_stmt|;
name|ahc_flag
name|ahc_f
init|=
name|AHC_FNONE
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
comment|/* 	 * Make the offsets the same as for EISA 	 * The first bit of PCI_BASEADR0 is always 	 * set hence we subtract 0xc01 instead of the 	 * 0xc00 that you would expect. 	 */
name|io_port
operator|-=
literal|0xc01ul
expr_stmt|;
switch|switch
condition|(
name|pci_conf_read
argument_list|(
name|config_id
argument_list|,
name|PCI_ID_REG
argument_list|)
condition|)
block|{
case|case
name|PCI_DEVICE_ID_ADAPTEC_3940
case|:
name|ahc_t
operator|=
name|AHC_394
expr_stmt|;
name|aic3940_count
operator|++
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|aic3940_count
operator|&
literal|0x01
operator|)
condition|)
comment|/* Even count implies second channel */
name|ahc_f
operator||=
name|AHC_CHNLB
expr_stmt|;
break|break;
case|case
name|PCI_DEVICE_ID_ADAPTEC_2940U
case|:
case|case
name|PCI_DEVICE_ID_ADAPTEC_2940
case|:
name|ahc_t
operator|=
name|AHC_294
expr_stmt|;
break|break;
case|case
name|PCI_DEVICE_ID_ADAPTEC_AIC7870
case|:
name|ahc_t
operator|=
name|AHC_AIC7870
expr_stmt|;
break|break;
case|case
name|PCI_DEVICE_ID_ADAPTEC_AIC7850
case|:
name|ahc_t
operator|=
name|AHC_AIC7850
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
name|ahc_t
operator|&
name|AHC_AIC7870
condition|)
block|{
name|u_long
name|devconfig
init|=
name|pci_conf_read
argument_list|(
name|config_id
argument_list|,
name|DEVCONFIG
argument_list|)
decl_stmt|;
if|if
condition|(
name|devconfig
operator|&
name|RAMPSM
condition|)
block|{
comment|/* 			 * External SRAM present.  Have the probe walk 			 * the SCBs to see how much SRAM we have and set 			 * the number of SCBs accordingly. 			 */
name|ahc_f
operator||=
name|AHC_EXTSCB
expr_stmt|;
block|}
block|}
if|if
condition|(
name|ahcprobe
argument_list|(
name|unit
argument_list|,
name|io_port
argument_list|,
name|ahc_t
argument_list|,
name|ahc_f
argument_list|)
condition|)
block|{
name|ahc_unit
operator|++
expr_stmt|;
comment|/* 		 * To be compatible with the isa style of 		 * interrupt handler, we pass the unit number 		 * not a pointer to our per device structure. 		 */
if|if
condition|(
operator|!
operator|(
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
operator|)
condition|)
block|{
name|free
argument_list|(
name|ahcdata
index|[
name|unit
index|]
argument_list|,
name|M_TEMP
argument_list|)
expr_stmt|;
name|ahcdata
index|[
name|unit
index|]
operator|=
name|NULL
expr_stmt|;
return|return;
block|}
comment|/* 		 * Since ahc_attach will poll, protect ourself 		 * from the registered interrupt handler. 		 */
name|opri
operator|=
name|splbio
argument_list|()
expr_stmt|;
name|ahc_attach
argument_list|(
name|unit
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|opri
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

