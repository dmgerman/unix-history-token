begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright (c) 1996 Wolfgang Helbig<helbig@ba-stuttgart.de>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Absolutely no warranty of function or purpose is made by the author.  * 4. Modifications may be freely made to this file if the above conditions  *    are met.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The sole purpose of this code currently is to tell the ISA wdc driver,  * whether there is a CMD640 IDE chip attached to the PCI bus.  */
end_comment

begin_include
include|#
directive|include
file|"pci.h"
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
file|"opt_wd.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CMD640
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
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
file|<i386/isa/wdc_p.h>
end_include

begin_comment
comment|/*  * PCI-ID's of IDE-Controller  */
end_comment

begin_define
define|#
directive|define
name|CMD640B_PCI_ID
value|0x06401095
end_define

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|wdc_pci_probe
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
specifier|static
name|void
name|wdc_pci_attach
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
name|wdc_pci_count
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pci_device
name|wdc_pci_driver
init|=
block|{
literal|"wdc"
block|,
name|wdc_pci_probe
block|,
name|wdc_pci_attach
block|,
operator|&
name|wdc_pci_count
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
name|wdc_pci_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|wdc_pci_probe
parameter_list|(
name|pcici_t
name|tag
parameter_list|,
name|pcidi_t
name|type
parameter_list|)
block|{
if|if
condition|(
name|type
operator|==
name|CMD640B_PCI_ID
condition|)
return|return
literal|"CMD 640B IDE"
return|;
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|wdc_pci_attach
parameter_list|(
name|pcici_t
name|config_id
parameter_list|,
name|int
name|unit
parameter_list|)
block|{
if|if
condition|(
name|pci_conf_read
argument_list|(
name|config_id
argument_list|,
name|PCI_ID_REG
argument_list|)
operator|==
name|CMD640B_PCI_ID
condition|)
name|wdc_pci
argument_list|(
name|Q_CMD640B
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CMD640 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NPCI> 0 */
end_comment

end_unit

