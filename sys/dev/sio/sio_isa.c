begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<machine/bus_pio.h>
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
file|<isa/isareg.h>
end_include

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|sio_isa_attach
name|__P
argument_list|(
operator|(
name|device_t
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|sio_isa_probe
name|__P
argument_list|(
operator|(
name|device_t
name|dev
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
literal|0x0005d041
block|,
literal|"Standard PC COM port"
block|}
block|,
comment|/* PNP0500 */
block|{
literal|0x0105d041
block|,
literal|"16550A-compatible COM port"
block|}
block|,
comment|/* PNP0501 */
block|{
literal|0x0205d041
block|,
literal|"Multiport serial device (non-intelligent 16550)"
block|}
block|,
comment|/* PNP0502 */
block|{
literal|0x1005d041
block|,
literal|"Generic IRDA-compatible device"
block|}
block|,
comment|/* PNP0510 */
block|{
literal|0x1105d041
block|,
literal|"Generic IRDA-compatible device"
block|}
block|,
comment|/* PNP0511 */
comment|/* Devices that do not have a compatid */
block|{
literal|0x12206804
block|,
name|NULL
block|}
block|,
comment|/* ACH2012 - 5634BTS 56K Video Ready Modem */
block|{
literal|0x7602a904
block|,
name|NULL
block|}
block|,
comment|/* AEI0276 - 56K v.90 Fax Modem (LKT) */
block|{
literal|0x00007905
block|,
name|NULL
block|}
block|,
comment|/* AKY0000 - 56K Plug&Play Modem */
block|{
literal|0x01405407
block|,
name|NULL
block|}
block|,
comment|/* AZT4001 - AZT3000 PnP SOUND DEVICE, MODEM */
block|{
literal|0x56039008
block|,
name|NULL
block|}
block|,
comment|/* BDP0356 - Best Data 56x2 */
block|{
literal|0x56159008
block|,
name|NULL
block|}
block|,
comment|/* BDP1556 - B.D. Smart One 56SPS,Voice Modem*/
block|{
literal|0x36339008
block|,
name|NULL
block|}
block|,
comment|/* BDP3336 - Best Data Prods. 336F */
block|{
literal|0x0014490a
block|,
name|NULL
block|}
block|,
comment|/* BRI1400 - Boca 33.6 PnP */
block|{
literal|0x0015490a
block|,
name|NULL
block|}
block|,
comment|/* BRI1500 - Internal Fax Data */
block|{
literal|0x0034490a
block|,
name|NULL
block|}
block|,
comment|/* BRI3400 - Internal ACF Modem */
block|{
literal|0x0094490a
block|,
name|NULL
block|}
block|,
comment|/* BRI9400 - Boca K56Flex PnP */
block|{
literal|0x00b4490a
block|,
name|NULL
block|}
block|,
comment|/* BRIB400 - Boca 56k PnP */
block|{
literal|0x0030320d
block|,
name|NULL
block|}
block|,
comment|/* CIR3000 - Cirrus Logic V43 */
block|{
literal|0x0100440e
block|,
name|NULL
block|}
block|,
comment|/* CRD0001 - Cardinal MVP288IV ? */
block|{
literal|0x01308c0e
block|,
name|NULL
block|}
block|,
comment|/* CTL3001 - Creative Labs Phoneblaster */
block|{
literal|0x36033610
block|,
name|NULL
block|}
block|,
comment|/* DAV0336 - DAVICOM 336PNP MODEM */
block|{
literal|0x0000aa1a
block|,
name|NULL
block|}
block|,
comment|/* FUJ0000 - FUJITSU Modem 33600 PNP/I2 */
block|{
literal|0x1200c31e
block|,
name|NULL
block|}
block|,
comment|/* GVC0012 - VF1128HV-R9 (win modem?) */
block|{
literal|0x0303c31e
block|,
name|NULL
block|}
block|,
comment|/* GVC0303 - MaxTech 33.6 PnP D/F/V */
block|{
literal|0x0505c31e
block|,
name|NULL
block|}
block|,
comment|/* GVC0505 - GVC 56k Faxmodem */
block|{
literal|0x0116c31e
block|,
name|NULL
block|}
block|,
comment|/* GVC1601 - Rockwell V.34 Plug& Play Modem */
block|{
literal|0x0050c31e
block|,
name|NULL
block|}
block|,
comment|/* GVC5000 - some GVC modem */
block|{
literal|0x3800f91e
block|,
name|NULL
block|}
block|,
comment|/* GWY0038 - Telepath with v.90 */
block|{
literal|0x9062f91e
block|,
name|NULL
block|}
block|,
comment|/* GWY6290 - Telepath with x2 Technology */
block|{
literal|0x8100e425
block|,
name|NULL
block|}
block|,
comment|/* IOD0081 - I-O DATA DEVICE,INC. IFML-560 */
block|{
literal|0x71004d24
block|,
name|NULL
block|}
block|,
comment|/* IBM0071 - IBM ThinkPad 240 IrDA controller*/
block|{
literal|0x21002534
block|,
name|NULL
block|}
block|,
comment|/* MAE0021 - Jetstream Int V.90 56k Voice Series 2*/
block|{
literal|0x0000f435
block|,
name|NULL
block|}
block|,
comment|/* MOT0000 - Motorola ModemSURFR 33.6 Intern */
block|{
literal|0x5015f435
block|,
name|NULL
block|}
block|,
comment|/* MOT1550 - Motorola ModemSURFR 56K Modem */
block|{
literal|0xf015f435
block|,
name|NULL
block|}
block|,
comment|/* MOT15F0 - Motorola VoiceSURFR 56K Modem */
block|{
literal|0x6045f435
block|,
name|NULL
block|}
block|,
comment|/* MOT4560 - Motorola ? */
block|{
literal|0x61e7a338
block|,
name|NULL
block|}
block|,
comment|/* NECE761 - 33.6Modem */
block|{
literal|0x08804f3f
block|,
name|NULL
block|}
block|,
comment|/* OZO8008 - Zoom  (33.6k Modem) */
block|{
literal|0x0f804f3f
block|,
name|NULL
block|}
block|,
comment|/* OZO800f - Zoom 2812 (56k Modem) */
block|{
literal|0x39804f3f
block|,
name|NULL
block|}
block|,
comment|/* OZO8039 - Zoom 56k flex */
block|{
literal|0x00914f3f
block|,
name|NULL
block|}
block|,
comment|/* OZO9100 - Zoom 2919 (K56 Faxmodem) */
block|{
literal|0x3024a341
block|,
name|NULL
block|}
block|,
comment|/* PMC2430 - Pace 56 Voice Internal Modem */
block|{
literal|0x1000eb49
block|,
name|NULL
block|}
block|,
comment|/* ROK0010 - Rockwell ? */
block|{
literal|0x1200b23d
block|,
name|NULL
block|}
block|,
comment|/* RSS0012 - OMRON ME5614ISA */
block|{
literal|0x5002734a
block|,
name|NULL
block|}
block|,
comment|/* RSS0250 - 5614Jx3(G) Internal Modem */
block|{
literal|0x6202734a
block|,
name|NULL
block|}
block|,
comment|/* RSS0262 - 5614Jx3[G] V90+K56Flex Modem */
block|{
literal|0x1010104d
block|,
name|NULL
block|}
block|,
comment|/* SHP1010 - Rockwell 33600bps Modem */
block|{
literal|0x10f0a34d
block|,
name|NULL
block|}
block|,
comment|/* SMCF010 - SMC IrCC*/
block|{
literal|0xc100ad4d
block|,
name|NULL
block|}
block|,
comment|/* SMM00C1 - Leopard 56k PnP */
block|{
literal|0x9012b04e
block|,
name|NULL
block|}
block|,
comment|/* SUP1290 - Supra ? */
block|{
literal|0x1013b04e
block|,
name|NULL
block|}
block|,
comment|/* SUP1310 - SupraExpress 336i PnP */
block|{
literal|0x8013b04e
block|,
name|NULL
block|}
block|,
comment|/* SUP1380 - SupraExpress 288i PnP Voice */
block|{
literal|0x8113b04e
block|,
name|NULL
block|}
block|,
comment|/* SUP1381 - SupraExpress 336i PnP Voice */
block|{
literal|0x5016b04e
block|,
name|NULL
block|}
block|,
comment|/* SUP1650 - Supra 336i Sp Intl */
block|{
literal|0x7016b04e
block|,
name|NULL
block|}
block|,
comment|/* SUP1670 - Supra 336i V+ Intl */
block|{
literal|0x7420b04e
block|,
name|NULL
block|}
block|,
comment|/* SUP2070 - Supra ? */
block|{
literal|0x8020b04e
block|,
name|NULL
block|}
block|,
comment|/* SUP2080 - Supra ? */
block|{
literal|0x8420b04e
block|,
name|NULL
block|}
block|,
comment|/* SUP2084 - SupraExpress 56i PnP */
block|{
literal|0x7121b04e
block|,
name|NULL
block|}
block|,
comment|/* SUP2171 - SupraExpress 56i Sp? */
block|{
literal|0x8024b04e
block|,
name|NULL
block|}
block|,
comment|/* SUP2480 - Supra ? */
block|{
literal|0x01007256
block|,
name|NULL
block|}
block|,
comment|/* USR0001 - U.S. Robotics Inc., Sportster W */
block|{
literal|0x02007256
block|,
name|NULL
block|}
block|,
comment|/* USR0002 - U.S. Robotics Inc. Sportster 33. */
block|{
literal|0x04007256
block|,
name|NULL
block|}
block|,
comment|/* USR0004 - USR Sportster 14.4k */
block|{
literal|0x06007256
block|,
name|NULL
block|}
block|,
comment|/* USR0006 - USR Sportster 33.6k */
block|{
literal|0x11007256
block|,
name|NULL
block|}
block|,
comment|/* USR0011 - USR ? */
block|{
literal|0x01017256
block|,
name|NULL
block|}
block|,
comment|/* USR0101 - USR ? */
block|{
literal|0x30207256
block|,
name|NULL
block|}
block|,
comment|/* USR2030 - U.S.Robotics Inc. Sportster 560 */
block|{
literal|0x50207256
block|,
name|NULL
block|}
block|,
comment|/* USR2050 - U.S.Robotics Inc. Sportster 33. */
block|{
literal|0x70207256
block|,
name|NULL
block|}
block|,
comment|/* USR2070 - U.S.Robotics Inc. Sportster 560 */
block|{
literal|0x30307256
block|,
name|NULL
block|}
block|,
comment|/* USR3030 - U.S. Robotics 56K FAX INT */
block|{
literal|0x31307256
block|,
name|NULL
block|}
block|,
comment|/* USR3031 - U.S. Robotics 56K FAX INT */
block|{
literal|0x50307256
block|,
name|NULL
block|}
block|,
comment|/* USR3050 - U.S. Robotics 56K FAX INT */
block|{
literal|0x70307256
block|,
name|NULL
block|}
block|,
comment|/* USR3070 - U.S. Robotics 56K Voice INT */
block|{
literal|0x90307256
block|,
name|NULL
block|}
block|,
comment|/* USR3090 - USR ? */
block|{
literal|0x70917256
block|,
name|NULL
block|}
block|,
comment|/* USR9170 - U.S. Robotics 56K FAX INT */
block|{
literal|0x90917256
block|,
name|NULL
block|}
block|,
comment|/* USR9190 - USR 56k Voice INT */
block|{
literal|0x0300695c
block|,
name|NULL
block|}
block|,
comment|/* WCI0003 - Fax/Voice/Modem/Speakphone/Asvd */
block|{
literal|0x01a0896a
block|,
name|NULL
block|}
block|,
comment|/* ZTIA001 - Zoom Internal V90 Faxmodem */
block|{
literal|0x61f7896a
block|,
name|NULL
block|}
block|,
comment|/* ZTIF761 - Zoom ComStar 33.6 */
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

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|sio
argument_list|,
name|acpi
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

