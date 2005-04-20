begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Original code by Hannes Gredler (hannes@juniper.net)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
name|_U_
init|=
literal|"@(#) $Header: /tcpdump/master/tcpdump/oui.c,v 1.2.2.1 2004/02/06 14:38:51 hannes Exp $ (LBL)"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<tcpdump-stdinc.h>
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"oui.h"
end_include

begin_comment
comment|/* FIXME complete OUI list using a script */
end_comment

begin_decl_stmt
name|struct
name|tok
name|oui_values
index|[]
init|=
block|{
block|{
literal|0x009069
block|,
literal|"Juniper"
block|}
block|,
block|{
literal|0x00000c
block|,
literal|"Cisco"
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list taken from ethereal/packet-radius.c */
end_comment

begin_decl_stmt
name|struct
name|tok
name|smi_values
index|[]
init|=
block|{
block|{
name|SMI_ACC
block|,
literal|"ACC"
block|}
block|,
block|{
name|SMI_CISCO
block|,
literal|"Cisco"
block|}
block|,
block|{
name|SMI_SHIVA
block|,
literal|"Shiva"
block|}
block|,
block|{
name|SMI_MICROSOFT
block|,
literal|"Microsoft"
block|}
block|,
block|{
name|SMI_LIVINGSTON
block|,
literal|"Livingston"
block|}
block|,
block|{
name|SMI_3COM
block|,
literal|"3Com"
block|}
block|,
block|{
name|SMI_ASCEND
block|,
literal|"Ascend"
block|}
block|,
block|{
name|SMI_BAY
block|,
literal|"Bay Networks"
block|}
block|,
block|{
name|SMI_FOUNDRY
block|,
literal|"Foundry"
block|}
block|,
block|{
name|SMI_VERSANET
block|,
literal|"Versanet"
block|}
block|,
block|{
name|SMI_REDBACK
block|,
literal|"Redback"
block|}
block|,
block|{
name|SMI_JUNIPER
block|,
literal|"Juniper Networks"
block|}
block|,
block|{
name|SMI_APTIS
block|,
literal|"Aptis"
block|}
block|,
block|{
name|SMI_COSINE
block|,
literal|"CoSine Communications"
block|}
block|,
block|{
name|SMI_SHASTA
block|,
literal|"Shasta"
block|}
block|,
block|{
name|SMI_NOMADIX
block|,
literal|"Nomadix"
block|}
block|,
block|{
name|SMI_UNISPHERE
block|,
literal|"Unisphere Networks"
block|}
block|,
block|{
name|SMI_ISSANNI
block|,
literal|"Issanni Communications"
block|}
block|,
block|{
name|SMI_QUINTUM
block|,
literal|"Quintum"
block|}
block|,
block|{
name|SMI_COLUBRIS
block|,
literal|"Colubris"
block|}
block|,
block|{
name|SMI_COLUMBIA_UNIVERSITY
block|,
literal|"Columbia University"
block|}
block|,
block|{
name|SMI_THE3GPP
block|,
literal|"3GPP"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

end_unit

