begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Yoshihiro TAKAHASHI.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/timepps.h>
end_include

begin_include
include|#
directive|include
file|<dev/sio/siovar.h>
end_include

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

begin_function_decl
specifier|static
name|int
name|sio_isa_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|sio_isa_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|device_method_t
name|sio_isa_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|sio_isa_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|sio_isa_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|siodetach
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
name|sio_isa_driver
init|=
block|{
name|sio_driver_name
block|,
name|sio_isa_methods
block|,
literal|0
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|isa_pnp_id
name|sio_ids
index|[]
init|=
block|{
block|{
literal|0x0100e4a5
block|,
literal|"RSA-98III"
block|}
block|,
block|{
literal|0x4180a3b8
block|,
name|NULL
block|}
block|,
comment|/* NEC8041 - PC-9821CB-B04 */
block|{
literal|0x0181a3b8
block|,
name|NULL
block|}
block|,
comment|/* NEC8101 - PC-9821CB2-B04 */
block|{
literal|0x5181a3b8
block|,
name|NULL
block|}
block|,
comment|/* NEC8151 - Internal FAX/Modem for Cx3, Cb3 */
block|{
literal|0x9181a3b8
block|,
name|NULL
block|}
block|,
comment|/* NEC8191 - NEC PC-9801-120 */
block|{
literal|0xe181a3b8
block|,
name|NULL
block|}
block|,
comment|/* NEC81E1 - Internal FAX/Modem */
block|{
literal|0x1182a3b8
block|,
name|NULL
block|}
block|,
comment|/* NEC8211 - PC-9801-123 */
block|{
literal|0x3182a3b8
block|,
name|NULL
block|}
block|,
comment|/* NEC8231 - Internal FAX/Modem(Voice) */
block|{
literal|0x4182a3b8
block|,
name|NULL
block|}
block|,
comment|/* NEC8241 - NEC PC-9821NR-B05 */
block|{
literal|0x5182a3b8
block|,
name|NULL
block|}
block|,
comment|/* NEC8251 - Internel FAX/Modem */
block|{
literal|0x7182a3b8
block|,
name|NULL
block|}
block|,
comment|/* NEC8271 - NEC PC-9801-125 */
block|{
literal|0x11802fbf
block|,
name|NULL
block|}
block|,
comment|/* OYO8011 - Internal FAX/Modem for ValueStar(Ring) */
block|{
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|sio_isa_probe
parameter_list|(
name|dev
parameter_list|)
name|device_t
name|dev
decl_stmt|;
block|{
name|int
name|logical_id
decl_stmt|;
comment|/* Check isapnp ids */
if|if
condition|(
name|ISA_PNP_PROBE
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|sio_ids
argument_list|)
operator|==
name|ENXIO
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|logical_id
operator|=
name|isa_get_logicalid
argument_list|(
name|dev
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|logical_id
condition|)
block|{
case|case
literal|0x0100e4a5
case|:
comment|/* RSA-98III */
name|SET_FLAG
argument_list|(
name|dev
argument_list|,
name|SET_IFTYPE
argument_list|(
name|COM_IF_RSA98III
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
literal|0x4180a3b8
case|:
comment|/* PC-9821CB-B04 */
case|case
literal|0x0181a3b8
case|:
comment|/* PC-9821CB2-B04 */
case|case
literal|0x5181a3b8
case|:
comment|/* for Cx3, Cb3 internal */
case|case
literal|0x9181a3b8
case|:
comment|/* PC-9801-120 */
case|case
literal|0xe181a3b8
case|:
comment|/* Internal FAX/Modem */
case|case
literal|0x1182a3b8
case|:
comment|/* PC-9801-123 */
case|case
literal|0x3182a3b8
case|:
comment|/* FAX/Voice/Modem internal */
case|case
literal|0x4182a3b8
case|:
comment|/* PC-9821NR-B05 */
case|case
literal|0x5182a3b8
case|:
comment|/* FAX/Modem internal */
case|case
literal|0x7182a3b8
case|:
comment|/* PC-9801-125 */
case|case
literal|0x11802fbf
case|:
comment|/* for ValueStar internal */
name|SET_FLAG
argument_list|(
name|dev
argument_list|,
name|SET_IFTYPE
argument_list|(
name|COM_IF_NS16550
argument_list|)
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|sioprobe
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|,
literal|0UL
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|sio_isa_attach
parameter_list|(
name|dev
parameter_list|)
name|device_t
name|dev
decl_stmt|;
block|{
return|return
operator|(
name|sioattach
argument_list|(
name|dev
argument_list|,
literal|0
argument_list|,
literal|0UL
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|sio
argument_list|,
name|isa
argument_list|,
name|sio_isa_driver
argument_list|,
name|sio_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

