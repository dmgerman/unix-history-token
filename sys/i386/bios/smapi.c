begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Matthew N. Dodd<winter@jurai.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_comment
comment|/* And all this for BIOS_PADDRTOVADDR() */
end_comment

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/md_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/pc/bios.h>
end_include

begin_include
include|#
directive|include
file|<machine/smapi.h>
end_include

begin_define
define|#
directive|define
name|SMAPI_START
value|0xf0000
end_define

begin_define
define|#
directive|define
name|SMAPI_STEP
value|0x10
end_define

begin_define
define|#
directive|define
name|SMAPI_OFF
value|0
end_define

begin_define
define|#
directive|define
name|SMAPI_LEN
value|4
end_define

begin_define
define|#
directive|define
name|SMAPI_SIG
value|"$SMB"
end_define

begin_define
define|#
directive|define
name|RES2HDR
parameter_list|(
name|res
parameter_list|)
value|((struct smapi_bios_header *)rman_get_virtual(res))
end_define

begin_define
define|#
directive|define
name|ADDR2HDR
parameter_list|(
name|addr
parameter_list|)
value|((struct smapi_bios_header *)BIOS_PADDRTOVADDR(addr))
end_define

begin_struct
struct|struct
name|smapi_softc
block|{
name|dev_t
name|cdev
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|u_int32_t
name|smapi32_entry
decl_stmt|;
name|struct
name|smapi_bios_header
modifier|*
name|header
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|u_long
name|smapi32_offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|smapi32_segment
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SMAPI32_SEGMENT
value|0x18
end_define

begin_decl_stmt
name|devclass_t
name|smapi_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_ioctl_t
name|smapi_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|smapi_cdevsw
init|=
block|{
operator|.
name|d_open
operator|=
name|nullopen
block|,
operator|.
name|d_close
operator|=
name|nullclose
block|,
operator|.
name|d_ioctl
operator|=
name|smapi_ioctl
block|,
operator|.
name|d_name
operator|=
literal|"smapi"
block|,
operator|.
name|d_maj
operator|=
name|MAJOR_AUTO
block|,
operator|.
name|d_flags
operator|=
name|D_MEM
block|, }
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|smapi_identify
parameter_list|(
name|driver_t
modifier|*
parameter_list|,
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|smapi_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|smapi_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|smapi_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|smapi_modevent
parameter_list|(
name|module_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|smapi_header_cksum
parameter_list|(
name|struct
name|smapi_bios_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|smapi32
parameter_list|(
name|struct
name|smapi_bios_parameter
modifier|*
parameter_list|,
name|struct
name|smapi_bios_parameter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|smapi32_new
parameter_list|(
name|u_long
parameter_list|,
name|u_short
parameter_list|,
name|struct
name|smapi_bios_parameter
modifier|*
parameter_list|,
name|struct
name|smapi_bios_parameter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|int
name|smapi_ioctl
parameter_list|(
name|dev
parameter_list|,
name|cmd
parameter_list|,
name|data
parameter_list|,
name|fflag
parameter_list|,
name|td
parameter_list|)
name|dev_t
name|dev
decl_stmt|;
name|u_long
name|cmd
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
name|int
name|fflag
decl_stmt|;
name|d_thread_t
modifier|*
name|td
decl_stmt|;
block|{
name|struct
name|smapi_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|error
decl_stmt|;
name|error
operator|=
literal|0
expr_stmt|;
name|sc
operator|=
name|devclass_get_softc
argument_list|(
name|smapi_devclass
argument_list|,
name|minor
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|==
name|NULL
condition|)
block|{
name|error
operator|=
name|ENXIO
expr_stmt|;
goto|goto
name|fail
goto|;
block|}
switch|switch
condition|(
name|cmd
condition|)
block|{
case|case
name|SMAPIOGHEADER
case|:
name|bcopy
argument_list|(
operator|(
name|caddr_t
operator|)
name|sc
operator|->
name|header
argument_list|,
name|data
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|smapi_bios_header
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|SMAPIOCGFUNCTION
case|:
if|#
directive|if
literal|1
name|smapi32_segment
operator|=
name|SMAPI32_SEGMENT
expr_stmt|;
name|smapi32_offset
operator|=
name|sc
operator|->
name|smapi32_entry
expr_stmt|;
name|error
operator|=
name|smapi32
argument_list|(
else|#
directive|else
argument|error = smapi32_new(sc->smapi32_entry, SMAPI32_SEGMENT,
endif|#
directive|endif
argument|(struct smapi_bios_parameter *)data, 				(struct smapi_bios_parameter *)data); 		break; 	default: 		error = ENOTTY; 	}  fail: 	return (error); }  static int smapi_header_cksum (struct smapi_bios_header *header) { 	u_int8_t *ptr; 	u_int8_t cksum; 	int i;  	ptr = (u_int8_t *)header; 	cksum =
literal|0
argument|; 	for (i =
literal|0
argument|; i< header->length; i++) { 		cksum += ptr[i];	 	}  	return (cksum); }  static void smapi_identify (driver_t *driver, device_t parent) { 	device_t child; 	u_int32_t addr; 	int length; 	int rid;  	if (!device_is_alive(parent)) 		return;  	addr = bios_sigsearch(SMAPI_START, SMAPI_SIG, SMAPI_LEN,                               SMAPI_STEP, SMAPI_OFF); 	if (addr !=
literal|0
argument|) { 		rid =
literal|0
argument|; 		length = ADDR2HDR(addr)->length;  		child = BUS_ADD_CHILD(parent,
literal|0
argument|,
literal|"smapi"
argument|, -
literal|1
argument|); 		device_set_driver(child, driver); 		bus_set_resource(child, SYS_RES_MEMORY, rid, addr, length); 		device_set_desc(child,
literal|"SMAPI BIOS"
argument|); 	}  	return; }  static int smapi_probe (device_t dev) { 	struct resource *res; 	int rid; 	int error;  	error =
literal|0
argument|; 	rid =
literal|0
argument|; 	res = bus_alloc_resource(dev, SYS_RES_MEMORY,&rid,
literal|0ul
argument|, ~
literal|0ul
argument|,
literal|1
argument|, RF_ACTIVE); 	if (res == NULL) { 		device_printf(dev,
literal|"Unable to allocate memory resource.\n"
argument|); 		error = ENOMEM; 		goto bad; 	}  	if (smapi_header_cksum(RES2HDR(res))) { 		device_printf(dev,
literal|"SMAPI header checksum failed.\n"
argument|); 		error = ENXIO; 		goto bad; 	}  bad: 	if (res) 		bus_release_resource(dev, SYS_RES_MEMORY, rid, res); 	return (error); }  static int smapi_attach (device_t dev) { 	struct smapi_softc *sc; 	int error;  	sc = device_get_softc(dev); 	error =
literal|0
argument|;  	sc->dev = dev; 	sc->rid =
literal|0
argument|; 	sc->res = bus_alloc_resource(dev, SYS_RES_MEMORY,&sc->rid,
literal|0ul
argument|, ~
literal|0ul
argument|,
literal|1
argument|, RF_ACTIVE); 	if (sc->res == NULL) { 		device_printf(dev,
literal|"Unable to allocate memory resource.\n"
argument|); 		error = ENOMEM; 		goto bad; 	} 	sc->header = (struct smapi_bios_header *)rman_get_virtual(sc->res); 	sc->smapi32_entry = (u_int32_t)BIOS_PADDRTOVADDR( 					sc->header->prot32_segment + 					sc->header->prot32_offset);          sc->cdev = make_dev(&smapi_cdevsw, 			device_get_unit(sc->dev), 			UID_ROOT, GID_WHEEL,
literal|0600
argument|,
literal|"%s%d"
argument|, 			smapi_cdevsw.d_name, 			device_get_unit(sc->dev));  	device_printf(dev,
literal|"Version: %d.%02d, Length: %d, Checksum: 0x%02x\n"
argument|, 		bcd2bin(sc->header->version_major), 		bcd2bin(sc->header->version_minor), 		sc->header->length, 		sc->header->checksum); 	device_printf(dev,
literal|"Information=0x%b\n"
argument|, 		sc->header->information,
literal|"\020"
literal|"\001REAL_VM86"
literal|"\002PROTECTED_16"
literal|"\003PROTECTED_32"
argument|);  	if (bootverbose) { 		if (sc->header->information& SMAPI_REAL_VM86) 			device_printf(dev,
literal|"Real/VM86 mode: Segment 0x%04x, Offset 0x%04x\n"
argument|, 				sc->header->real16_segment, 				sc->header->real16_offset); 		if (sc->header->information& SMAPI_PROT_16BIT) 			device_printf(dev,
literal|"16-bit Protected mode: Segment 0x%08x, Offset 0x%04x\n"
argument|, 				sc->header->prot16_segment, 				sc->header->prot16_offset); 		if (sc->header->information& SMAPI_PROT_32BIT) 			device_printf(dev,
literal|"32-bit Protected mode: Segment 0x%08x, Offset 0x%08x\n"
argument|, 				sc->header->prot32_segment, 				sc->header->prot32_offset); 	}  	return (
literal|0
argument|); bad: 	if (sc->res) 		bus_release_resource(dev, SYS_RES_MEMORY, sc->rid, sc->res); 	return (error); }  static int smapi_detach (device_t dev) { 	struct smapi_softc *sc;  	sc = device_get_softc(dev);  	destroy_dev(sc->cdev);  	if (sc->res) 		bus_release_resource(dev, SYS_RES_MEMORY, sc->rid, sc->res);  	return (
literal|0
argument|); }  static int smapi_modevent (mod, what, arg)         module_t        mod;         int             what;         void *          arg; { 	device_t *	devs; 	int		count; 	int		i;  	switch (what) { 	case MOD_LOAD: 		break; 	case MOD_UNLOAD: 		devclass_get_devices(smapi_devclass,&devs,&count); 		for (i =
literal|0
argument|; i< count; i++) { 			device_delete_child(device_get_parent(devs[i]), devs[i]); 		} 		break; 	default: 		break; 	}  	return (
literal|0
argument|); }  static device_method_t smapi_methods[] = {
comment|/* Device interface */
argument|DEVMETHOD(device_identify,      smapi_identify)
argument_list|,
argument|DEVMETHOD(device_probe,         smapi_probe)
argument_list|,
argument|DEVMETHOD(device_attach,        smapi_attach)
argument_list|,
argument|DEVMETHOD(device_detach,        smapi_detach)
argument_list|,
argument|{
literal|0
argument_list|,
literal|0
argument|} };  static driver_t smapi_driver = {
literal|"smapi"
argument_list|,
argument|smapi_methods
argument_list|,
argument|sizeof(struct smapi_softc)
argument_list|,
argument|};  DRIVER_MODULE(smapi, nexus, smapi_driver, smapi_devclass, smapi_modevent,
literal|0
argument|); MODULE_VERSION(smapi,
literal|1
argument|);
end_function

end_unit

