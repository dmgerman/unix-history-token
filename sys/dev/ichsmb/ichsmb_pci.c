begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ichsmb_pci.c  *  * Author: Archie Cobbs<archie@freebsd.org>  * Copyright (c) 2000 Whistle Communications, Inc.  * All rights reserved.  * Author: Archie Cobbs<archie@freebsd.org>  *  * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *  * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  */
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

begin_comment
comment|/*  * Support for the SMBus controller logical device which is part of the  * Intel 81801AA/AB/BA/CA/DC/EB (ICH/ICH[02345]) I/O controller hub chips.  */
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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
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
file|<sys/syslog.h>
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
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<dev/smbus/smbconf.h>
end_include

begin_include
include|#
directive|include
file|<dev/ichsmb/ichsmb_var.h>
end_include

begin_include
include|#
directive|include
file|<dev/ichsmb/ichsmb_reg.h>
end_include

begin_comment
comment|/* PCI unique identifiers */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_INTEL
value|0x8086
end_define

begin_define
define|#
directive|define
name|ID_82801AA
value|0x2413
end_define

begin_define
define|#
directive|define
name|ID_82801AB
value|0x2423
end_define

begin_define
define|#
directive|define
name|ID_82801BA
value|0x2443
end_define

begin_define
define|#
directive|define
name|ID_82801CA
value|0x2483
end_define

begin_define
define|#
directive|define
name|ID_82801DC
value|0x24C3
end_define

begin_define
define|#
directive|define
name|ID_82801EB
value|0x24D3
end_define

begin_define
define|#
directive|define
name|ID_82801FB
value|0x266A
end_define

begin_define
define|#
directive|define
name|ID_82801GB
value|0x27da
end_define

begin_define
define|#
directive|define
name|ID_82801H
value|0x283e
end_define

begin_define
define|#
directive|define
name|ID_82801I
value|0x2930
end_define

begin_define
define|#
directive|define
name|ID_EP80579
value|0x5032
end_define

begin_define
define|#
directive|define
name|ID_82801JI
value|0x3a30
end_define

begin_define
define|#
directive|define
name|ID_82801JD
value|0x3a60
end_define

begin_define
define|#
directive|define
name|ID_PCH
value|0x3b30
end_define

begin_define
define|#
directive|define
name|ID_6300ESB
value|0x25a4
end_define

begin_define
define|#
directive|define
name|ID_631xESB
value|0x269b
end_define

begin_define
define|#
directive|define
name|ID_DH89XXCC
value|0x2330
end_define

begin_define
define|#
directive|define
name|ID_PATSBURG
value|0x1d22
end_define

begin_define
define|#
directive|define
name|ID_CPT
value|0x1c22
end_define

begin_define
define|#
directive|define
name|ID_PPT
value|0x1e22
end_define

begin_define
define|#
directive|define
name|ID_AVOTON
value|0x1f3c
end_define

begin_define
define|#
directive|define
name|ID_COLETOCRK
value|0x23B0
end_define

begin_define
define|#
directive|define
name|ID_LPT
value|0x8c22
end_define

begin_define
define|#
directive|define
name|ID_LPTLP
value|0x9c22
end_define

begin_define
define|#
directive|define
name|ID_WCPT
value|0x8ca2
end_define

begin_define
define|#
directive|define
name|ID_WCPTLP
value|0x9ca2
end_define

begin_define
define|#
directive|define
name|ID_BAYTRAIL
value|0x0f12
end_define

begin_define
define|#
directive|define
name|ID_BRASWELL
value|0x2292
end_define

begin_define
define|#
directive|define
name|ID_WELLSBURG
value|0x8d22
end_define

begin_define
define|#
directive|define
name|ID_SRPT
value|0xa123
end_define

begin_define
define|#
directive|define
name|ID_SRPTLP
value|0x9d23
end_define

begin_define
define|#
directive|define
name|ID_DENVERTON
value|0x19df
end_define

begin_define
define|#
directive|define
name|ID_BROXTON
value|0x5ad4
end_define

begin_define
define|#
directive|define
name|ID_LEWISBURG
value|0xa1a3
end_define

begin_define
define|#
directive|define
name|ID_LEWISBURG2
value|0xa223
end_define

begin_define
define|#
directive|define
name|ID_KABYLAKE
value|0xa2a3
end_define

begin_struct
specifier|static
specifier|const
struct|struct
name|ichsmb_device
block|{
name|uint16_t
name|id
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|ichsmb_devices
index|[]
init|=
block|{
block|{
name|ID_82801AA
block|,
literal|"Intel 82801AA (ICH) SMBus controller"
block|}
block|,
block|{
name|ID_82801AB
block|,
literal|"Intel 82801AB (ICH0) SMBus controller"
block|}
block|,
block|{
name|ID_82801BA
block|,
literal|"Intel 82801BA (ICH2) SMBus controller"
block|}
block|,
block|{
name|ID_82801CA
block|,
literal|"Intel 82801CA (ICH3) SMBus controller"
block|}
block|,
block|{
name|ID_82801DC
block|,
literal|"Intel 82801DC (ICH4) SMBus controller"
block|}
block|,
block|{
name|ID_82801EB
block|,
literal|"Intel 82801EB (ICH5) SMBus controller"
block|}
block|,
block|{
name|ID_82801FB
block|,
literal|"Intel 82801FB (ICH6) SMBus controller"
block|}
block|,
block|{
name|ID_82801GB
block|,
literal|"Intel 82801GB (ICH7) SMBus controller"
block|}
block|,
block|{
name|ID_82801H
block|,
literal|"Intel 82801H (ICH8) SMBus controller"
block|}
block|,
block|{
name|ID_82801I
block|,
literal|"Intel 82801I (ICH9) SMBus controller"
block|}
block|,
block|{
name|ID_82801GB
block|,
literal|"Intel 82801GB (ICH7) SMBus controller"
block|}
block|,
block|{
name|ID_82801H
block|,
literal|"Intel 82801H (ICH8) SMBus controller"
block|}
block|,
block|{
name|ID_82801I
block|,
literal|"Intel 82801I (ICH9) SMBus controller"
block|}
block|,
block|{
name|ID_EP80579
block|,
literal|"Intel EP80579 SMBus controller"
block|}
block|,
block|{
name|ID_82801JI
block|,
literal|"Intel 82801JI (ICH10) SMBus controller"
block|}
block|,
block|{
name|ID_82801JD
block|,
literal|"Intel 82801JD (ICH10) SMBus controller"
block|}
block|,
block|{
name|ID_PCH
block|,
literal|"Intel PCH SMBus controller"
block|}
block|,
block|{
name|ID_6300ESB
block|,
literal|"Intel 6300ESB (ICH) SMBus controller"
block|}
block|,
block|{
name|ID_631xESB
block|,
literal|"Intel 631xESB/6321ESB (ESB2) SMBus controller"
block|}
block|,
block|{
name|ID_DH89XXCC
block|,
literal|"Intel DH89xxCC SMBus controller"
block|}
block|,
block|{
name|ID_PATSBURG
block|,
literal|"Intel Patsburg SMBus controller"
block|}
block|,
block|{
name|ID_CPT
block|,
literal|"Intel Cougar Point SMBus controller"
block|}
block|,
block|{
name|ID_PPT
block|,
literal|"Intel Panther Point SMBus controller"
block|}
block|,
block|{
name|ID_AVOTON
block|,
literal|"Intel Avoton SMBus controller"
block|}
block|,
block|{
name|ID_LPT
block|,
literal|"Intel Lynx Point SMBus controller"
block|}
block|,
block|{
name|ID_LPTLP
block|,
literal|"Intel Lynx Point-LP SMBus controller"
block|}
block|,
block|{
name|ID_WCPT
block|,
literal|"Intel Wildcat Point SMBus controller"
block|}
block|,
block|{
name|ID_WCPTLP
block|,
literal|"Intel Wildcat Point-LP SMBus controller"
block|}
block|,
block|{
name|ID_BAYTRAIL
block|,
literal|"Intel Baytrail SMBus controller"
block|}
block|,
block|{
name|ID_BRASWELL
block|,
literal|"Intel Braswell SMBus controller"
block|}
block|,
block|{
name|ID_COLETOCRK
block|,
literal|"Intel Coleto Creek SMBus controller"
block|}
block|,
block|{
name|ID_WELLSBURG
block|,
literal|"Intel Wellsburg SMBus controller"
block|}
block|,
block|{
name|ID_SRPT
block|,
literal|"Intel Sunrise Point-H SMBus controller"
block|}
block|,
block|{
name|ID_SRPTLP
block|,
literal|"Intel Sunrise Point-LP SMBus controller"
block|}
block|,
block|{
name|ID_DENVERTON
block|,
literal|"Intel Denverton SMBus controller"
block|}
block|,
block|{
name|ID_BROXTON
block|,
literal|"Intel Broxton SMBus controller"
block|}
block|,
block|{
name|ID_LEWISBURG
block|,
literal|"Intel Lewisburg SMBus controller"
block|}
block|,
block|{
name|ID_LEWISBURG2
block|,
literal|"Intel Lewisburg SMBus controller"
block|}
block|,
block|{
name|ID_KABYLAKE
block|,
literal|"Intel Kaby Lake SMBus controller"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|, }
struct|;
end_struct

begin_comment
comment|/* Internal functions */
end_comment

begin_function_decl
specifier|static
name|int
name|ichsmb_pci_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|ichsmb_pci_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*Use generic one for now*/
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static int	ichsmb_pci_detach(device_t dev);
endif|#
directive|endif
end_endif

begin_comment
comment|/* Device methods */
end_comment

begin_decl_stmt
specifier|static
name|device_method_t
name|ichsmb_pci_methods
index|[]
init|=
block|{
comment|/* Device interface */
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|ichsmb_pci_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|ichsmb_pci_attach
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_detach
argument_list|,
name|ichsmb_detach
argument_list|)
block|,
comment|/* SMBus methods */
name|DEVMETHOD
argument_list|(
name|smbus_callback
argument_list|,
name|ichsmb_callback
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|smbus_quick
argument_list|,
name|ichsmb_quick
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|smbus_sendb
argument_list|,
name|ichsmb_sendb
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|smbus_recvb
argument_list|,
name|ichsmb_recvb
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|smbus_writeb
argument_list|,
name|ichsmb_writeb
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|smbus_writew
argument_list|,
name|ichsmb_writew
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|smbus_readb
argument_list|,
name|ichsmb_readb
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|smbus_readw
argument_list|,
name|ichsmb_readw
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|smbus_pcall
argument_list|,
name|ichsmb_pcall
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|smbus_bwrite
argument_list|,
name|ichsmb_bwrite
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|smbus_bread
argument_list|,
name|ichsmb_bread
argument_list|)
block|,
name|DEVMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|ichsmb_pci_driver
init|=
block|{
literal|"ichsmb"
block|,
name|ichsmb_pci_methods
block|,
expr|sizeof
operator|(
expr|struct
name|ichsmb_softc
operator|)
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|ichsmb_pci_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|ichsmb
argument_list|,
name|pci
argument_list|,
name|ichsmb_pci_driver
argument_list|,
name|ichsmb_pci_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|int
name|ichsmb_pci_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
specifier|const
name|struct
name|ichsmb_device
modifier|*
name|device
decl_stmt|;
if|if
condition|(
name|pci_get_vendor
argument_list|(
name|dev
argument_list|)
operator|!=
name|PCI_VENDOR_INTEL
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
for|for
control|(
name|device
operator|=
name|ichsmb_devices
init|;
name|device
operator|->
name|name
operator|!=
name|NULL
condition|;
name|device
operator|++
control|)
block|{
if|if
condition|(
name|pci_get_device
argument_list|(
name|dev
argument_list|)
operator|==
name|device
operator|->
name|id
condition|)
block|{
name|device_set_desc
argument_list|(
name|dev
argument_list|,
name|device
operator|->
name|name
argument_list|)
expr_stmt|;
return|return
operator|(
name|ichsmb_probe
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
block|}
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ichsmb_pci_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
specifier|const
name|sc_p
name|sc
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
name|int
name|error
decl_stmt|;
comment|/* Initialize private state */
name|bzero
argument_list|(
name|sc
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|sc
argument_list|)
argument_list|)
expr_stmt|;
name|sc
operator|->
name|ich_cmd
operator|=
operator|-
literal|1
expr_stmt|;
name|sc
operator|->
name|dev
operator|=
name|dev
expr_stmt|;
comment|/* Allocate an I/O range */
name|sc
operator|->
name|io_rid
operator|=
name|ICH_SMB_BASE
expr_stmt|;
name|sc
operator|->
name|io_res
operator|=
name|bus_alloc_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IOPORT
argument_list|,
operator|&
name|sc
operator|->
name|io_rid
argument_list|,
literal|0
argument_list|,
operator|~
literal|0
argument_list|,
literal|16
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|io_res
operator|==
name|NULL
condition|)
name|sc
operator|->
name|io_res
operator|=
name|bus_alloc_resource
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IOPORT
argument_list|,
operator|&
name|sc
operator|->
name|io_rid
argument_list|,
literal|0ul
argument_list|,
operator|~
literal|0ul
argument_list|,
literal|32
argument_list|,
name|RF_ACTIVE
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|io_res
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"can't map I/O\n"
argument_list|)
expr_stmt|;
name|error
operator|=
name|ENXIO
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
comment|/* Allocate interrupt */
name|sc
operator|->
name|irq_rid
operator|=
literal|0
expr_stmt|;
name|sc
operator|->
name|irq_res
operator|=
name|bus_alloc_resource_any
argument_list|(
name|dev
argument_list|,
name|SYS_RES_IRQ
argument_list|,
operator|&
name|sc
operator|->
name|irq_rid
argument_list|,
name|RF_ACTIVE
operator||
name|RF_SHAREABLE
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|irq_res
operator|==
name|NULL
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"can't get IRQ\n"
argument_list|)
expr_stmt|;
name|error
operator|=
name|ENXIO
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
comment|/* Enable device */
name|pci_write_config
argument_list|(
name|dev
argument_list|,
name|ICH_HOSTC
argument_list|,
name|ICH_HOSTC_HST_EN
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Done */
name|error
operator|=
name|ichsmb_attach
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|fail
goto|;
return|return
operator|(
literal|0
operator|)
return|;
name|fail
label|:
comment|/* Attach failed, release resources */
name|ichsmb_release_resources
argument_list|(
name|sc
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|MODULE_DEPEND
argument_list|(
name|ichsmb
argument_list|,
name|pci
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
name|ichsmb
argument_list|,
name|smbus
argument_list|,
name|SMBUS_MINVER
argument_list|,
name|SMBUS_PREFVER
argument_list|,
name|SMBUS_MAXVER
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MODULE_VERSION
argument_list|(
name|ichsmb
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

