begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999 FreeBSD(98) port team.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"opt_gdc.h"
end_include

begin_include
include|#
directive|include
file|"opt_fb.h"
end_include

begin_include
include|#
directive|include
file|"opt_syscons.h"
end_include

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
file|<sys/conf.h>
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
file|<sys/fbio.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

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
file|<dev/fb/fbreg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|LINE30
end_ifdef

begin_include
include|#
directive|include
file|<pc98/pc98/pc98.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<pc98/pc98/pc98_machdep.h>
end_include

begin_include
include|#
directive|include
file|<isa/isavar.h>
end_include

begin_define
define|#
directive|define
name|TEXT_GDC
value|0x60
end_define

begin_define
define|#
directive|define
name|GRAPHIC_GDC
value|0xa0
end_define

begin_define
define|#
directive|define
name|ROW
value|25
end_define

begin_define
define|#
directive|define
name|COL
value|80
end_define

begin_define
define|#
directive|define
name|DRIVER_NAME
value|"gdc"
end_define

begin_comment
comment|/* cdev driver declaration */
end_comment

begin_define
define|#
directive|define
name|GDC_UNIT
parameter_list|(
name|dev
parameter_list|)
value|minor(dev)
end_define

begin_define
define|#
directive|define
name|GDC_MKMINOR
parameter_list|(
name|unit
parameter_list|)
value|(unit)
end_define

begin_typedef
typedef|typedef
struct|struct
name|gdc_softc
block|{
name|video_adapter_t
modifier|*
name|adp
decl_stmt|;
name|struct
name|resource
modifier|*
name|res_tgdc
decl_stmt|,
modifier|*
name|res_ggdc
decl_stmt|;
name|struct
name|resource
modifier|*
name|res_egc
decl_stmt|,
modifier|*
name|res_pegc
decl_stmt|,
modifier|*
name|res_grcg
decl_stmt|,
modifier|*
name|res_kcg
decl_stmt|;
name|struct
name|resource
modifier|*
name|res_tmem
decl_stmt|,
modifier|*
name|res_gmem1
decl_stmt|,
modifier|*
name|res_gmem2
decl_stmt|;
ifdef|#
directive|ifdef
name|FB_INSTALL_CDEV
name|genfb_softc_t
name|gensc
decl_stmt|;
endif|#
directive|endif
block|}
name|gdc_softc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GDC_SOFTC
parameter_list|(
name|unit
parameter_list|)
define|\
value|((gdc_softc_t *)devclass_get_softc(gdc_devclass, unit))
end_define

begin_decl_stmt
specifier|static
name|bus_addr_t
name|gdc_iat
index|[]
init|=
block|{
literal|0
block|,
literal|2
block|,
literal|4
block|,
literal|6
block|,
literal|8
block|,
literal|10
block|,
literal|12
block|,
literal|14
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|gdc_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|int
name|gdc_probe_unit
parameter_list|(
name|int
name|unit
parameter_list|,
name|gdc_softc_t
modifier|*
name|sc
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|gdc_attach_unit
parameter_list|(
name|int
name|unit
parameter_list|,
name|gdc_softc_t
modifier|*
name|sc
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|gdc_alloc_resource
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|gdc_release_resource
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|FB_INSTALL_CDEV
end_if

begin_decl_stmt
specifier|static
name|d_open_t
name|gdcopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_close_t
name|gdcclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_read_t
name|gdcread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_write_t
name|gdcwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_ioctl_t
name|gdcioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_mmap_t
name|gdcmmap
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|gdc_cdevsw
init|=
block|{
operator|.
name|d_open
operator|=
name|gdcopen
block|,
operator|.
name|d_close
operator|=
name|gdcclose
block|,
operator|.
name|d_read
operator|=
name|gdcread
block|,
operator|.
name|d_write
operator|=
name|gdcwrite
block|,
operator|.
name|d_ioctl
operator|=
name|gdcioctl
block|,
operator|.
name|d_mmap
operator|=
name|gdcmmap
block|,
operator|.
name|d_name
operator|=
name|DRIVER_NAME
block|,
operator|.
name|d_maj
operator|=
operator|-
literal|1
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FB_INSTALL_CDEV */
end_comment

begin_function
specifier|static
name|void
name|gdc_identify
parameter_list|(
name|driver_t
modifier|*
name|driver
parameter_list|,
name|device_t
name|parent
parameter_list|)
block|{
name|BUS_ADD_CHILD
argument_list|(
name|parent
argument_list|,
name|ISA_ORDER_SPECULATIVE
argument_list|,
name|DRIVER_NAME
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|gdcprobe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
comment|/* Check isapnp ids */
if|if
condition|(
name|isa_get_vendorid
argument_list|(
name|dev
argument_list|)
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
literal|"Generic GDC"
argument_list|)
expr_stmt|;
name|error
operator|=
name|gdc_alloc_resource
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|error
operator|=
name|gdc_probe_unit
argument_list|(
name|device_get_unit
argument_list|(
name|dev
argument_list|)
argument_list|,
name|device_get_softc
argument_list|(
name|dev
argument_list|)
argument_list|,
name|device_get_flags
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
name|gdc_release_resource
argument_list|(
name|dev
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
name|int
name|gdc_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|gdc_softc_t
modifier|*
name|sc
decl_stmt|;
name|int
name|error
decl_stmt|;
name|error
operator|=
name|gdc_alloc_resource
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
return|return
operator|(
name|error
operator|)
return|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
name|error
operator|=
name|gdc_attach_unit
argument_list|(
name|device_get_unit
argument_list|(
name|dev
argument_list|)
argument_list|,
name|sc
argument_list|,
name|device_get_flags
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|gdc_release_resource
argument_list|(
name|dev
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
ifdef|#
directive|ifdef
name|FB_INSTALL_CDEV
comment|/* attach a virtual frame buffer device */
name|error
operator|=
name|fb_attach
argument_list|(
argument|GDC_MKMINOR(device_get_unit(dev), 				  sc->adp,&gdc_cdevsw); 	if (error) { 		gdc_release_resource(dev); 		return error; 	}
endif|#
directive|endif
comment|/* FB_INSTALL_CDEV */
argument|if (bootverbose) 		(*vidsw[sc->adp->va_index]->diag)(sc->adp, bootverbose);  	return
literal|0
argument|; }  static int gdc_probe_unit(int unit, gdc_softc_t *sc, int flags) { 	video_switch_t *sw;  	sw = vid_get_switch(DRIVER_NAME); 	if (sw == NULL) 		return ENXIO; 	return (*sw->probe)(unit,&sc->adp, NULL, flags); }  static int gdc_attach_unit(int unit, gdc_softc_t *sc, int flags) { 	video_switch_t *sw;  	sw = vid_get_switch(DRIVER_NAME); 	if (sw == NULL) 		return ENXIO; 	return (*sw->init)(unit, sc->adp, flags); }   static int gdc_alloc_resource(device_t dev) { 	int rid; 	gdc_softc_t *sc;  	sc = device_get_softc(dev);
comment|/* TEXT GDC */
argument|rid =
literal|0
argument|; 	bus_set_resource(dev, SYS_RES_IOPORT, rid, TEXT_GDC,
literal|1
argument|); 	sc->res_tgdc = isa_alloc_resourcev(dev, SYS_RES_IOPORT,&rid, 					   gdc_iat,
literal|8
argument|, RF_ACTIVE); 	if (sc->res_tgdc == NULL) { 		gdc_release_resource(dev); 		return (ENXIO); 	} 	isa_load_resourcev(sc->res_tgdc, gdc_iat,
literal|8
argument|);
comment|/* GRAPHIC GDC */
argument|rid =
literal|8
argument|; 	bus_set_resource(dev, SYS_RES_IOPORT, rid, GRAPHIC_GDC,
literal|1
argument|); 	sc->res_ggdc = isa_alloc_resourcev(dev, SYS_RES_IOPORT,&rid, 					   gdc_iat,
literal|8
argument|, RF_ACTIVE); 	if (sc->res_ggdc == NULL) { 		gdc_release_resource(dev); 		return (ENXIO); 	} 	isa_load_resourcev(sc->res_ggdc, gdc_iat,
literal|8
argument|);
comment|/* EGC */
argument|rid =
literal|16
argument|; 	bus_set_resource(dev, SYS_RES_IOPORT, rid,
literal|0x4a0
argument|,
literal|1
argument|); 	sc->res_egc = isa_alloc_resourcev(dev, SYS_RES_IOPORT,&rid, 					   gdc_iat,
literal|8
argument|, RF_ACTIVE); 	if (sc->res_egc == NULL) { 		gdc_release_resource(dev); 		return (ENXIO); 	} 	isa_load_resourcev(sc->res_egc, gdc_iat,
literal|8
argument|);
comment|/* PEGC */
argument|rid =
literal|24
argument|; 	bus_set_resource(dev, SYS_RES_IOPORT, rid,
literal|0x9a0
argument|,
literal|1
argument|); 	sc->res_pegc = isa_alloc_resourcev(dev, SYS_RES_IOPORT,&rid, 					   gdc_iat,
literal|8
argument|, RF_ACTIVE); 	if (sc->res_pegc == NULL) { 		gdc_release_resource(dev); 		return (ENXIO); 	} 	isa_load_resourcev(sc->res_pegc, gdc_iat,
literal|8
argument|);
comment|/* CRTC/GRCG */
argument|rid =
literal|32
argument|; 	bus_set_resource(dev, SYS_RES_IOPORT, rid,
literal|0x70
argument|,
literal|1
argument|); 	sc->res_grcg = isa_alloc_resourcev(dev, SYS_RES_IOPORT,&rid, 					   gdc_iat,
literal|8
argument|, RF_ACTIVE); 	if (sc->res_grcg == NULL) { 		gdc_release_resource(dev); 		return (ENXIO); 	} 	isa_load_resourcev(sc->res_grcg, gdc_iat,
literal|8
argument|);
comment|/* KCG */
argument|rid =
literal|40
argument|; 	bus_set_resource(dev, SYS_RES_IOPORT, rid,
literal|0xa1
argument|,
literal|1
argument|); 	sc->res_kcg = isa_alloc_resourcev(dev, SYS_RES_IOPORT,&rid, 					  gdc_iat,
literal|8
argument|, RF_ACTIVE); 	if (sc->res_kcg == NULL) { 		gdc_release_resource(dev); 		return (ENXIO); 	} 	isa_load_resourcev(sc->res_kcg, gdc_iat,
literal|8
argument|);
comment|/* TEXT Memory */
argument|rid =
literal|0
argument|; 	sc->res_tmem = bus_alloc_resource(dev, SYS_RES_MEMORY,&rid,
literal|0xa0000
argument|,
literal|0xa4fff
argument|,
literal|0x5000
argument|, RF_ACTIVE); 	if (sc->res_tmem == NULL) { 		gdc_release_resource(dev); 		return (ENXIO); 	}
comment|/* GRAPHIC Memory */
argument|rid =
literal|1
argument|; 	sc->res_gmem1 = bus_alloc_resource(dev, SYS_RES_MEMORY,&rid,
literal|0xa8000
argument|,
literal|0xbffff
argument|,
literal|0x18000
argument|, 					   RF_ACTIVE); 	if (sc->res_gmem1 == NULL) { 		gdc_release_resource(dev); 		return (ENXIO); 	} 	rid =
literal|2
argument|; 	sc->res_gmem2 = bus_alloc_resource(dev, SYS_RES_MEMORY,&rid,
literal|0xe0000
argument|,
literal|0xe7fff
argument|,
literal|0x8000
argument|, 					   RF_ACTIVE); 	if (sc->res_gmem2 == NULL) { 		gdc_release_resource(dev); 		return (ENXIO); 	}  	return (
literal|0
argument|); }  static int gdc_release_resource(device_t dev) { 	gdc_softc_t *sc;  	sc = device_get_softc(dev);  	if (sc->res_tgdc) 		bus_release_resource(dev, SYS_RES_IOPORT,
literal|0
argument|, sc->res_tgdc); 	if (sc->res_ggdc) 		bus_release_resource(dev, SYS_RES_IOPORT,
literal|8
argument|, sc->res_ggdc); 	if (sc->res_egc) 		bus_release_resource(dev, SYS_RES_IOPORT,
literal|16
argument|, sc->res_egc); 	if (sc->res_pegc) 		bus_release_resource(dev, SYS_RES_IOPORT,
literal|24
argument|, sc->res_pegc); 	if (sc->res_grcg) 		bus_release_resource(dev, SYS_RES_IOPORT,
literal|32
argument|, sc->res_grcg); 	if (sc->res_kcg) 		bus_release_resource(dev, SYS_RES_IOPORT,
literal|40
argument|, sc->res_kcg);  	if (sc->res_tmem) 		bus_release_resource(dev, SYS_RES_MEMORY,
literal|0
argument|, sc->res_tmem); 	if (sc->res_gmem1) 		bus_release_resource(dev, SYS_RES_MEMORY,
literal|1
argument|, sc->res_gmem1); 	if (sc->res_gmem2) 		bus_release_resource(dev, SYS_RES_MEMORY,
literal|2
argument|, sc->res_gmem2);  	return (
literal|0
argument|); }
comment|/* cdev driver functions */
ifdef|#
directive|ifdef
name|FB_INSTALL_CDEV
argument|static int gdcopen(dev_t dev, int flag, int mode, struct thread *td) {     gdc_softc_t *sc;      sc = GDC_SOFTC(GDC_UNIT(dev));     if (sc == NULL) 	return ENXIO;     if (mode& (O_CREAT | O_APPEND | O_TRUNC)) 	return ENODEV;      return genfbopen(&sc->gensc, sc->adp, flag, mode, td); }  static int gdcclose(dev_t dev, int flag, int mode, struct thread *td) {     gdc_softc_t *sc;      sc = GDC_SOFTC(GDC_UNIT(dev));     return genfbclose(&sc->gensc, sc->adp, flag, mode, td); }  static int gdcread(dev_t dev, struct uio *uio, int flag) {     gdc_softc_t *sc;      sc = GDC_SOFTC(GDC_UNIT(dev));     return genfbread(&sc->gensc, sc->adp, uio, flag); }  static int gdcwrite(dev_t dev, struct uio *uio, int flag) {     gdc_softc_t *sc;      sc = GDC_SOFTC(GDC_UNIT(dev));     return genfbread(&sc->gensc, sc->adp, uio, flag); }  static int gdcioctl(dev_t dev, u_long cmd, caddr_t arg, int flag, struct thread *td) {     gdc_softc_t *sc;      sc = GDC_SOFTC(GDC_UNIT(dev));     return genfbioctl(&sc->gensc, sc->adp, cmd, arg, flag, td); }  static int gdcmmap(dev_t dev, vm_offset_t offset, vm_paddr_t *paddr, int prot) {     gdc_softc_t *sc;      sc = GDC_SOFTC(GDC_UNIT(dev));     return genfbmmap(&sc->gensc, sc->adp, offset, paddr, prot); }
endif|#
directive|endif
comment|/* FB_INSTALL_CDEV */
argument|static device_method_t gdc_methods[] = { 	DEVMETHOD(device_identify,	gdc_identify)
argument_list|,
argument|DEVMETHOD(device_probe,		gdcprobe)
argument_list|,
argument|DEVMETHOD(device_attach,	gdc_attach)
argument_list|,
argument|{
literal|0
argument_list|,
literal|0
argument|} };  static driver_t gdcdriver = { 	DRIVER_NAME
argument_list|,
argument|gdc_methods
argument_list|,
argument|sizeof(gdc_softc_t)
argument_list|,
argument|};  DRIVER_MODULE(gdc, isa, gdcdriver, gdc_devclass,
literal|0
argument|,
literal|0
argument|);
comment|/* LOW-LEVEL */
include|#
directive|include
file|<pc98/pc98/30line.h>
define|#
directive|define
name|TEXT_BUF_BASE
value|0x000a0000
define|#
directive|define
name|TEXT_BUF_SIZE
value|0x00008000
define|#
directive|define
name|GRAPHICS_BUF_BASE
value|0x000a8000
define|#
directive|define
name|GRAPHICS_BUF_SIZE
value|0x00040000
define|#
directive|define
name|VIDEO_BUF_BASE
value|0x000a0000
define|#
directive|define
name|VIDEO_BUF_SIZE
value|0x00048000
define|#
directive|define
name|probe_done
parameter_list|(
name|adp
parameter_list|)
value|((adp)->va_flags& V_ADP_PROBED)
define|#
directive|define
name|init_done
parameter_list|(
name|adp
parameter_list|)
value|((adp)->va_flags& V_ADP_INITIALIZED)
define|#
directive|define
name|config_done
parameter_list|(
name|adp
parameter_list|)
value|((adp)->va_flags& V_ADP_REGISTERED)
comment|/*   * NOTE: `va_window' should have a virtual address, but is initialized  * with a physical address in the following table, they will be  * converted at run-time.  */
argument|static video_adapter_t adapter_init_value[] = {     {
literal|0
argument_list|,
argument|KD_PC98
argument_list|,
literal|"gdc"
argument_list|,
comment|/* va_type, va_name */
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* va_unit, va_minor */
argument|V_ADP_COLOR | V_ADP_MODECHANGE | V_ADP_BORDER
argument_list|,
argument|TEXT_GDC
argument_list|,
literal|16
argument_list|,
argument|TEXT_GDC
argument_list|,
comment|/* va_io*, XXX */
argument|VIDEO_BUF_BASE
argument_list|,
argument|VIDEO_BUF_SIZE
argument_list|,
comment|/* va_mem* */
argument|TEXT_BUF_BASE
argument_list|,
argument|TEXT_BUF_SIZE
argument_list|,
argument|TEXT_BUF_SIZE
argument_list|,
literal|0
argument_list|,
comment|/* va_window* */
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* va_buffer, va_buffer_size */
literal|0
argument_list|,
argument|M_PC98_80x25
argument_list|,
literal|0
argument_list|,
comment|/* va_*mode* */
argument|}
argument_list|,
argument|};  static video_adapter_t	biosadapter[
literal|1
argument|];
comment|/* video driver declarations */
argument|static int			gdc_configure(int flags); static int			gdc_err(video_adapter_t *adp, ...); static vi_probe_t		gdc_probe; static vi_init_t		gdc_init; static vi_get_info_t		gdc_get_info; static vi_query_mode_t		gdc_query_mode; static vi_set_mode_t		gdc_set_mode; static vi_set_border_t		gdc_set_border; static vi_save_state_t		gdc_save_state; static vi_load_state_t		gdc_load_state; static vi_read_hw_cursor_t	gdc_read_hw_cursor; static vi_set_hw_cursor_t	gdc_set_hw_cursor; static vi_set_hw_cursor_shape_t	gdc_set_hw_cursor_shape; static vi_blank_display_t	gdc_blank_display; static vi_mmap_t		gdc_mmap_buf; static vi_ioctl_t		gdc_dev_ioctl; static vi_clear_t		gdc_clear; static vi_fill_rect_t		gdc_fill_rect; static vi_bitblt_t		gdc_bitblt; static vi_diag_t		gdc_diag; static vi_save_palette_t	gdc_save_palette; static vi_load_palette_t	gdc_load_palette; static vi_set_win_org_t		gdc_set_origin;  static video_switch_t gdcvidsw = { 	gdc_probe
argument_list|,
argument|gdc_init
argument_list|,
argument|gdc_get_info
argument_list|,
argument|gdc_query_mode
argument_list|,
argument|gdc_set_mode
argument_list|,
argument|(vi_save_font_t *)gdc_err
argument_list|,
argument|(vi_load_font_t *)gdc_err
argument_list|,
argument|(vi_show_font_t *)gdc_err
argument_list|,
argument|gdc_save_palette
argument_list|,
argument|gdc_load_palette
argument_list|,
argument|gdc_set_border
argument_list|,
argument|gdc_save_state
argument_list|,
argument|gdc_load_state
argument_list|,
argument|gdc_set_origin
argument_list|,
argument|gdc_read_hw_cursor
argument_list|,
argument|gdc_set_hw_cursor
argument_list|,
argument|gdc_set_hw_cursor_shape
argument_list|,
argument|gdc_blank_display
argument_list|,
argument|gdc_mmap_buf
argument_list|,
argument|gdc_dev_ioctl
argument_list|,
argument|gdc_clear
argument_list|,
argument|gdc_fill_rect
argument_list|,
argument|gdc_bitblt
argument_list|,
argument|(int (*)(void))gdc_err
argument_list|,
argument|(int (*)(void))gdc_err
argument_list|,
argument|gdc_diag
argument_list|,
argument|};  VIDEO_DRIVER(gdc, gdcvidsw, gdc_configure);
comment|/* GDC BIOS standard video modes */
define|#
directive|define
name|EOT
value|(-1)
define|#
directive|define
name|NA
value|(-2)
argument|static video_info_t bios_vmode[] = {     { M_PC98_80x25
argument_list|,
argument|V_INFO_COLOR
argument_list|,
literal|80
argument_list|,
literal|25
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
argument|TEXT_BUF_BASE
argument_list|,
argument|TEXT_BUF_SIZE
argument_list|,
argument|TEXT_BUF_SIZE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
argument|V_INFO_MM_TEXT }
argument_list|,
ifdef|#
directive|ifdef
name|LINE30
argument|{ M_PC98_80x30
argument_list|,
argument|V_INFO_COLOR
argument_list|,
literal|80
argument_list|,
literal|30
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
argument|TEXT_BUF_BASE
argument_list|,
argument|TEXT_BUF_SIZE
argument_list|,
argument|TEXT_BUF_SIZE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
argument|V_INFO_MM_TEXT }
argument_list|,
endif|#
directive|endif
ifndef|#
directive|ifndef
name|GDC_NOGRAPHICS
argument|{ M_PC98_EGC640x400
argument_list|,
argument|V_INFO_COLOR | V_INFO_GRAPHICS
argument_list|,
literal|640
argument_list|,
literal|400
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|,
literal|4
argument_list|,
literal|4
argument_list|,
argument|GRAPHICS_BUF_BASE
argument_list|,
argument|GRAPHICS_BUF_SIZE
argument_list|,
argument|GRAPHICS_BUF_SIZE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
argument|V_INFO_MM_PLANAR }
argument_list|,
argument|{ M_PC98_PEGC640x400
argument_list|,
argument|V_INFO_COLOR | V_INFO_GRAPHICS | V_INFO_VESA
argument_list|,
literal|640
argument_list|,
literal|400
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|,
literal|8
argument_list|,
literal|1
argument_list|,
argument|GRAPHICS_BUF_BASE
argument_list|,
literal|0x00008000
argument_list|,
literal|0x00008000
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
argument|V_INFO_MM_PACKED
argument_list|,
literal|1
argument|}
argument_list|,
ifdef|#
directive|ifdef
name|LINE30
argument|{ M_PC98_PEGC640x480
argument_list|,
argument|V_INFO_COLOR | V_INFO_GRAPHICS | V_INFO_VESA
argument_list|,
literal|640
argument_list|,
literal|480
argument_list|,
literal|8
argument_list|,
literal|16
argument_list|,
literal|8
argument_list|,
literal|1
argument_list|,
argument|GRAPHICS_BUF_BASE
argument_list|,
literal|0x00008000
argument_list|,
literal|0x00008000
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
argument|V_INFO_MM_PACKED
argument_list|,
literal|1
argument|}
argument_list|,
endif|#
directive|endif
endif|#
directive|endif
argument|{ EOT }
argument_list|,
argument|};  static int		gdc_init_done = FALSE;
comment|/* local functions */
argument|static int map_gen_mode_num(int type, int color, int mode); static int probe_adapters(void);
define|#
directive|define
name|prologue
parameter_list|(
name|adp
parameter_list|,
name|flag
parameter_list|,
name|err
parameter_list|)
define|\
value|if (!gdc_init_done || !((adp)->va_flags& (flag)))	\ 	    return (err)
comment|/* a backdoor for the console driver */
argument|static int gdc_configure(int flags) {     probe_adapters();     biosadapter[
literal|0
argument|].va_flags |= V_ADP_INITIALIZED;     if (!config_done(&biosadapter[
literal|0
argument|])) { 	if (vid_register(&biosadapter[
literal|0
argument|])<
literal|0
argument|) 	    return
literal|1
argument|; 	biosadapter[
literal|0
argument|].va_flags |= V_ADP_REGISTERED;     }      return
literal|1
argument|; }
comment|/* local subroutines */
comment|/* map a generic video mode to a known mode number */
argument|static int map_gen_mode_num(int type, int color, int mode) {     static struct { 	int from; 	int to;     } mode_map[] = { 	{ M_TEXT_80x25
argument_list|,
argument|M_PC98_80x25
argument_list|,
argument|}
argument_list|,
ifdef|#
directive|ifdef
name|LINE30
argument|{ M_TEXT_80x30
argument_list|,
argument|M_PC98_80x30
argument_list|,
argument|}
argument_list|,
endif|#
directive|endif
argument|};     int i;      for (i =
literal|0
argument|; i< sizeof(mode_map)/sizeof(mode_map[
literal|0
argument|]); ++i) {         if (mode_map[i].from == mode)             return mode_map[i].to;     }     return mode; }  static int verify_adapter(video_adapter_t *adp) {
ifndef|#
directive|ifndef
name|GDC_NOGRAPHICS
argument|int i;      if (PC98_SYSTEM_PARAMETER(
literal|0x45c
argument|)&
literal|0x40
argument|) {
comment|/* PEGC exists */
argument|adp->va_flags |= V_ADP_VESA;
comment|/* XXX */
argument|} else { 	for (i =
literal|0
argument|; bios_vmode[i].vi_mode != EOT; ++i) { 	    if (bios_vmode[i].vi_flags& V_INFO_VESA) 		bios_vmode[i].vi_mode = NA; 	}     }
endif|#
directive|endif
argument|return
literal|0
argument|; }
comment|/* probe video adapters and return the number of detected adapters */
argument|static int probe_adapters(void) {     video_info_t info;
comment|/* do this test only once */
argument|if (gdc_init_done) 	return
literal|1
argument|;     gdc_init_done = TRUE;      biosadapter[
literal|0
argument|] = adapter_init_value[
literal|0
argument|];     biosadapter[
literal|0
argument|].va_flags |= V_ADP_PROBED;     biosadapter[
literal|0
argument|].va_mode =  	biosadapter[
literal|0
argument|].va_initial_mode = biosadapter[
literal|0
argument|].va_initial_bios_mode;      if ((PC98_SYSTEM_PARAMETER(
literal|0x597
argument|)&
literal|0x80
argument|) || 	(PC98_SYSTEM_PARAMETER(
literal|0x458
argument|)&
literal|0x80
argument|)) { 	gdc_FH = (inb(
literal|0x9a8
argument|)&
literal|1
argument|) ? _31KHZ : _24KHZ;     } else { 	gdc_FH = _24KHZ;     }      gdc_get_info(&biosadapter[
literal|0
argument|], biosadapter[
literal|0
argument|].va_initial_mode,&info);     initialize_gdc(T25_G400, info.vi_flags& V_INFO_GRAPHICS);      biosadapter[
literal|0
argument|].va_window = BIOS_PADDRTOVADDR(info.vi_window);     biosadapter[
literal|0
argument|].va_window_size = info.vi_window_size;     biosadapter[
literal|0
argument|].va_window_gran = info.vi_window_gran;     biosadapter[
literal|0
argument|].va_buffer =
literal|0
argument|;     biosadapter[
literal|0
argument|].va_buffer_size =
literal|0
argument|;     if (info.vi_flags& V_INFO_GRAPHICS) { 	switch (info.vi_depth/info.vi_planes) { 	case
literal|1
argument|: 	    biosadapter[
literal|0
argument|].va_line_width = info.vi_width/
literal|8
argument|; 	    break; 	case
literal|2
argument|: 	    biosadapter[
literal|0
argument|].va_line_width = info.vi_width/
literal|4
argument|; 	    break; 	case
literal|4
argument|: 	    biosadapter[
literal|0
argument|].va_line_width = info.vi_width/
literal|2
argument|; 	    break; 	case
literal|8
argument|: 	default:
comment|/* shouldn't happen */
argument|biosadapter[
literal|0
argument|].va_line_width = info.vi_width; 	    break; 	}     } else { 	biosadapter[
literal|0
argument|].va_line_width = info.vi_width;     }     bcopy(&info,&biosadapter[
literal|0
argument|].va_info, sizeof(info));      verify_adapter(&biosadapter[
literal|0
argument|]);      return
literal|1
argument|; }  static void master_gdc_cmd(unsigned int cmd) {     while ( (inb(TEXT_GDC)&
literal|2
argument|) !=
literal|0
argument|);     outb(TEXT_GDC+
literal|2
argument|, cmd); }  static void master_gdc_prm(unsigned int pmtr) {     while ( (inb(TEXT_GDC)&
literal|2
argument|) !=
literal|0
argument|);     outb(TEXT_GDC, pmtr); }  static void master_gdc_word_prm(unsigned int wpmtr) {     master_gdc_prm(wpmtr&
literal|0x00ff
argument|);     master_gdc_prm((wpmtr>>
literal|8
argument|)&
literal|0x00ff
argument|); }
ifdef|#
directive|ifdef
name|LINE30
argument|static void master_gdc_fifo_empty(void) {     while ( (inb(TEXT_GDC)&
literal|4
argument|) ==
literal|0
argument|);      }
endif|#
directive|endif
argument|static void master_gdc_wait_vsync(void) {     while ( (inb(TEXT_GDC)&
literal|0x20
argument|) !=
literal|0
argument|);               while ( (inb(TEXT_GDC)&
literal|0x20
argument|) ==
literal|0
argument|);           }  static void gdc_cmd(unsigned int cmd) {     while ( (inb(GRAPHIC_GDC)&
literal|2
argument|) !=
literal|0
argument|);     outb( GRAPHIC_GDC+
literal|2
argument|, cmd); }
ifdef|#
directive|ifdef
name|LINE30
argument|static void gdc_prm(unsigned int pmtr) {     while ( (inb(GRAPHIC_GDC)&
literal|2
argument|) !=
literal|0
argument|);     outb( GRAPHIC_GDC, pmtr); }  static void gdc_word_prm(unsigned int wpmtr) {     gdc_prm(wpmtr&
literal|0x00ff
argument|);     gdc_prm((wpmtr>>
literal|8
argument|)&
literal|0x00ff
argument|); }  static void gdc_fifo_empty(void) {     while ( (inb(GRAPHIC_GDC)&
literal|0x04
argument|) ==
literal|0
argument|);           }
endif|#
directive|endif
argument|static void gdc_wait_vsync(void) {     while ( (inb(GRAPHIC_GDC)&
literal|0x20
argument|) !=
literal|0
argument|);               while ( (inb(GRAPHIC_GDC)&
literal|0x20
argument|) ==
literal|0
argument|);           }
ifdef|#
directive|ifdef
name|LINE30
argument|static int check_gdc_clock(void) {     if ((inb(IO_SYSPORT)&
literal|0x80
argument|) ==
literal|0
argument|){        	return _5MHZ;     } else {        	return _2_5MHZ;     } }
endif|#
directive|endif
argument|static void initialize_gdc(unsigned int mode, int isGraph) {
ifdef|#
directive|ifdef
name|LINE30
comment|/* start 30line initialize */
argument|int m_mode
argument_list|,
argument|s_mode
argument_list|,
argument|gdc_clock
argument_list|,
argument|hsync_clock;      gdc_clock = check_gdc_clock();     m_mode = (mode == T25_G400) ? _25L : _30L;     s_mode =
literal|2
argument|*mode+gdc_clock;     gdc_INFO = m_mode;      master_gdc_wait_vsync();      if ((PC98_SYSTEM_PARAMETER(
literal|0x597
argument|)&
literal|0x80
argument|) || 	(PC98_SYSTEM_PARAMETER(
literal|0x458
argument|)&
literal|0x80
argument|)) { 	if (PC98_SYSTEM_PARAMETER(
literal|0x481
argument|)&
literal|0x08
argument|) { 	    hsync_clock = (m_mode == _25L) ? gdc_FH : _31KHZ; 	    outb(
literal|0x9a8
argument|, (hsync_clock == _31KHZ) ?
literal|1
argument|:
literal|0
argument|); 	} else { 	    hsync_clock = gdc_FH; 	}     } else { 	hsync_clock = _24KHZ;     }      if ((gdc_clock == _2_5MHZ)&& 	(slave_param[hsync_clock][s_mode][GDC_LF]>
literal|400
argument|)) { 	outb(
literal|0x6a
argument|,
literal|0x83
argument|); 	outb(
literal|0x6a
argument|,
literal|0x85
argument|); 	gdc_clock = _5MHZ; 	s_mode =
literal|2
argument|*mode+gdc_clock;     }      master_gdc_cmd(_GDC_RESET);     master_gdc_cmd(_GDC_MASTER);     gdc_cmd(_GDC_RESET);     gdc_cmd(_GDC_SLAVE);
comment|/* GDC Master */
argument|master_gdc_cmd(_GDC_SYNC);     master_gdc_prm(
literal|0x00
argument|);
comment|/* flush less */
comment|/* text& graph */
argument|master_gdc_prm(master_param[hsync_clock][m_mode][GDC_CR]);     master_gdc_word_prm(((master_param[hsync_clock][m_mode][GDC_HFP]<<
literal|10
argument|)  		     + (master_param[hsync_clock][m_mode][GDC_VS]<<
literal|5
argument|)  		     + master_param[hsync_clock][m_mode][GDC_HS]));     master_gdc_prm(master_param[hsync_clock][m_mode][GDC_HBP]);     master_gdc_prm(master_param[hsync_clock][m_mode][GDC_VFP]);     master_gdc_word_prm(((master_param[hsync_clock][m_mode][GDC_VBP]<<
literal|10
argument|)         		     + (master_param[hsync_clock][m_mode][GDC_LF])));     master_gdc_fifo_empty();     master_gdc_cmd(_GDC_PITCH);     master_gdc_prm(MasterPCH);     master_gdc_fifo_empty();
comment|/* GDC slave */
argument|gdc_cmd(_GDC_SYNC);     gdc_prm(
literal|0x06
argument|);     gdc_prm(slave_param[hsync_clock][s_mode][GDC_CR]);     gdc_word_prm((slave_param[hsync_clock][s_mode][GDC_HFP]<<
literal|10
argument|)  		+ (slave_param[hsync_clock][s_mode][GDC_VS]<<
literal|5
argument|)  		+ (slave_param[hsync_clock][s_mode][GDC_HS]));     gdc_prm(slave_param[hsync_clock][s_mode][GDC_HBP]);     gdc_prm(slave_param[hsync_clock][s_mode][GDC_VFP]);     gdc_word_prm((slave_param[hsync_clock][s_mode][GDC_VBP]<<
literal|10
argument|)  		+ (slave_param[hsync_clock][s_mode][GDC_LF]));     gdc_fifo_empty();     gdc_cmd(_GDC_PITCH);     gdc_prm(SlavePCH[gdc_clock]);     gdc_fifo_empty();
comment|/* set Master GDC scroll param */
argument|master_gdc_wait_vsync();     master_gdc_wait_vsync();     master_gdc_wait_vsync();     master_gdc_cmd(_GDC_SCROLL);     master_gdc_word_prm(
literal|0
argument|);     master_gdc_word_prm((master_param[hsync_clock][m_mode][GDC_LF]<<
literal|4
argument|) 			|
literal|0x0000
argument|);     master_gdc_fifo_empty();
comment|/* set Slave GDC scroll param */
argument|gdc_wait_vsync();     gdc_cmd(_GDC_SCROLL);     gdc_word_prm(
literal|0
argument|);     if (gdc_clock == _5MHZ) { 	gdc_word_prm((SlaveScrlLF[mode]<<
literal|4
argument|)  |
literal|0x4000
argument|);     } else { 	gdc_word_prm(SlaveScrlLF[mode]<<
literal|4
argument|);     }     gdc_fifo_empty();      gdc_word_prm(
literal|0
argument|);     if (gdc_clock == _5MHZ) { 	gdc_word_prm((SlaveScrlLF[mode]<<
literal|4
argument|)  |
literal|0x4000
argument|);     } else { 	gdc_word_prm(SlaveScrlLF[mode]<<
literal|4
argument|);     }     gdc_fifo_empty();
comment|/* sync start */
argument|gdc_cmd(isGraph ? _GDC_START : _GDC_STOP);      gdc_wait_vsync();     gdc_wait_vsync();     gdc_wait_vsync();      master_gdc_cmd(isGraph ? _GDC_STOP : _GDC_START);
else|#
directive|else
argument|master_gdc_wait_vsync();     master_gdc_cmd(isGraph ? _GDC_STOP : _GDC_START);
comment|/* text */
argument|gdc_wait_vsync();     gdc_cmd(isGraph ? _GDC_START : _GDC_STOP);
comment|/* graphics */
endif|#
directive|endif
argument|}
ifndef|#
directive|ifndef
name|GDC_NOGRAPHICS
argument|static u_char b_palette[] = {
comment|/* R     G     B */
literal|0x00
argument_list|,
literal|0x00
argument_list|,
literal|0x00
argument_list|,
comment|/* 0 */
literal|0x00
argument_list|,
literal|0x00
argument_list|,
literal|0x7f
argument_list|,
comment|/* 1 */
literal|0x7f
argument_list|,
literal|0x00
argument_list|,
literal|0x00
argument_list|,
comment|/* 2 */
literal|0x7f
argument_list|,
literal|0x00
argument_list|,
literal|0x7f
argument_list|,
comment|/* 3 */
literal|0x00
argument_list|,
literal|0x7f
argument_list|,
literal|0x00
argument_list|,
comment|/* 4 */
literal|0x00
argument_list|,
literal|0x7f
argument_list|,
literal|0x7f
argument_list|,
comment|/* 5 */
literal|0x7f
argument_list|,
literal|0x7f
argument_list|,
literal|0x00
argument_list|,
comment|/* 6 */
literal|0x7f
argument_list|,
literal|0x7f
argument_list|,
literal|0x7f
argument_list|,
comment|/* 7 */
literal|0x40
argument_list|,
literal|0x40
argument_list|,
literal|0x40
argument_list|,
comment|/* 8 */
literal|0x00
argument_list|,
literal|0x00
argument_list|,
literal|0xff
argument_list|,
comment|/* 9 */
literal|0xff
argument_list|,
literal|0x00
argument_list|,
literal|0x00
argument_list|,
comment|/* 10 */
literal|0xff
argument_list|,
literal|0x00
argument_list|,
literal|0xff
argument_list|,
comment|/* 11 */
literal|0x00
argument_list|,
literal|0xff
argument_list|,
literal|0x00
argument_list|,
comment|/* 12 */
literal|0x00
argument_list|,
literal|0xff
argument_list|,
literal|0xff
argument_list|,
comment|/* 13 */
literal|0xff
argument_list|,
literal|0xff
argument_list|,
literal|0x00
argument_list|,
comment|/* 14 */
literal|0xff
argument_list|,
literal|0xff
argument_list|,
literal|0xff
argument_list|,
comment|/* 15 */
argument|};
endif|#
directive|endif
argument|static int gdc_load_palette(video_adapter_t *adp, u_char *palette) {
ifndef|#
directive|ifndef
name|GDC_NOGRAPHICS
argument|int i;      if (adp->va_info.vi_flags& V_INFO_VESA) { 	gdc_wait_vsync(); 	for (i =
literal|0
argument|; i<
literal|256
argument|; ++i) { 	    outb(
literal|0xa8
argument|, i); 	    outb(
literal|0xac
argument|, *palette++);
comment|/* R */
argument|outb(
literal|0xaa
argument|, *palette++);
comment|/* G */
argument|outb(
literal|0xae
argument|, *palette++);
comment|/* B */
argument|}     } else {
comment|/* 	 * XXX - Even though PC-98 text color is independent of palette, 	 * we should set palette in text mode. 	 * Because the background color of text mode is palette 0's one. 	 */
argument|outb(
literal|0x6a
argument|,
literal|1
argument|);
comment|/* 16 colors mode */
argument|bcopy(palette, b_palette, sizeof(b_palette));  	gdc_wait_vsync(); 	for (i =
literal|0
argument|; i<
literal|16
argument|; ++i) { 	    outb(
literal|0xa8
argument|, i); 	    outb(
literal|0xac
argument|, *palette++>>
literal|4
argument|);
comment|/* R */
argument|outb(
literal|0xaa
argument|, *palette++>>
literal|4
argument|);
comment|/* G */
argument|outb(
literal|0xae
argument|, *palette++>>
literal|4
argument|);
comment|/* B */
argument|}     }
endif|#
directive|endif
argument|return
literal|0
argument|; }  static int gdc_save_palette(video_adapter_t *adp, u_char *palette) {
ifndef|#
directive|ifndef
name|GDC_NOGRAPHICS
argument|int i;      if (adp->va_info.vi_flags& V_INFO_VESA) { 	for (i =
literal|0
argument|; i<
literal|256
argument|; ++i) { 	    outb(
literal|0xa8
argument|, i); 	    *palette++ = inb(
literal|0xac
argument|);
comment|/* R */
argument|*palette++ = inb(
literal|0xaa
argument|);
comment|/* G */
argument|*palette++ = inb(
literal|0xae
argument|);
comment|/* B */
argument|}     } else { 	bcopy(b_palette, palette, sizeof(b_palette));     }
endif|#
directive|endif
argument|return
literal|0
argument|; }  static int gdc_set_origin(video_adapter_t *adp, off_t offset) {
ifndef|#
directive|ifndef
name|GDC_NOGRAPHICS
argument|if (adp->va_info.vi_flags& V_INFO_VESA) { 	writew(BIOS_PADDRTOVADDR(
literal|0x000e0004
argument|), offset>>
literal|15
argument|);     }
endif|#
directive|endif
argument|return
literal|0
argument|; }
comment|/* entry points */
argument|static int gdc_err(video_adapter_t *adp, ...) {     return ENODEV; }  static int gdc_probe(int unit, video_adapter_t **adpp, void *arg, int flags) {     probe_adapters();     if (unit>=
literal|1
argument|) 	return ENXIO;      *adpp =&biosadapter[unit];      return
literal|0
argument|; }  static int gdc_init(int unit, video_adapter_t *adp, int flags) {     if ((unit>=
literal|1
argument|) || (adp == NULL) || !probe_done(adp)) 	return ENXIO;      if (!init_done(adp)) {
comment|/* nothing to do really... */
argument|adp->va_flags |= V_ADP_INITIALIZED;     }      if (!config_done(adp)) { 	if (vid_register(adp)<
literal|0
argument|) 		return ENXIO; 	adp->va_flags |= V_ADP_REGISTERED;     }      return
literal|0
argument|; }
comment|/*  * get_info():  * Return the video_info structure of the requested video mode.  */
argument|static int gdc_get_info(video_adapter_t *adp, int mode, video_info_t *info) {     int i;      if (!gdc_init_done) 	return ENXIO;      mode = map_gen_mode_num(adp->va_type, adp->va_flags& V_ADP_COLOR, mode);     for (i =
literal|0
argument|; bios_vmode[i].vi_mode != EOT; ++i) { 	if (bios_vmode[i].vi_mode == NA) 	    continue; 	if (mode == bios_vmode[i].vi_mode) { 	    *info = bios_vmode[i]; 	    info->vi_buffer_size = info->vi_window_size*info->vi_planes; 	    return
literal|0
argument|; 	}     }     return EINVAL; }
comment|/*  * query_mode():  * Find a video mode matching the requested parameters.  * Fields filled with 0 are considered "don't care" fields and  * match any modes.  */
argument|static int gdc_query_mode(video_adapter_t *adp, video_info_t *info) {     int i;      if (!gdc_init_done) 	return ENXIO;      for (i =
literal|0
argument|; bios_vmode[i].vi_mode != EOT; ++i) { 	if (bios_vmode[i].vi_mode == NA) 	    continue;  	if ((info->vi_width !=
literal|0
argument|)&& (info->vi_width != bios_vmode[i].vi_width)) 		continue; 	if ((info->vi_height !=
literal|0
argument|)&& (info->vi_height != bios_vmode[i].vi_height)) 		continue; 	if ((info->vi_cwidth !=
literal|0
argument|)&& (info->vi_cwidth != bios_vmode[i].vi_cwidth)) 		continue; 	if ((info->vi_cheight !=
literal|0
argument|)&& (info->vi_cheight != bios_vmode[i].vi_cheight)) 		continue; 	if ((info->vi_depth !=
literal|0
argument|)&& (info->vi_depth != bios_vmode[i].vi_depth)) 		continue; 	if ((info->vi_planes !=
literal|0
argument|)&& (info->vi_planes != bios_vmode[i].vi_planes)) 		continue;
comment|/* XXX: should check pixel format, memory model */
argument|if ((info->vi_flags !=
literal|0
argument|)&& (info->vi_flags != bios_vmode[i].vi_flags)) 		continue;
comment|/* verify if this mode is supported on this adapter */
argument|if (gdc_get_info(adp, bios_vmode[i].vi_mode, info)) 		continue; 	return
literal|0
argument|;     }     return ENODEV; }
comment|/*  * set_mode():  * Change the video mode.  */
argument|static int gdc_set_mode(video_adapter_t *adp, int mode) {     video_info_t info;      prologue(adp, V_ADP_MODECHANGE, ENODEV);      mode = map_gen_mode_num(adp->va_type,  			    adp->va_flags& V_ADP_COLOR, mode);     if (gdc_get_info(adp, mode,&info)) 	return EINVAL;      switch (info.vi_mode) {
ifndef|#
directive|ifndef
name|GDC_NOGRAPHICS
argument|case M_PC98_PEGC640x480:
comment|/* PEGC 640x480 */
argument|initialize_gdc(T30_G480, info.vi_flags& V_INFO_GRAPHICS); 	    break; 	case M_PC98_PEGC640x400:
comment|/* PEGC 640x400 */
argument|case M_PC98_EGC640x400:
comment|/* EGC GRAPHICS */
endif|#
directive|endif
argument|case M_PC98_80x25:
comment|/* VGA TEXT */
argument|initialize_gdc(T25_G400, info.vi_flags& V_INFO_GRAPHICS); 	    break; 	case M_PC98_80x30:
comment|/* VGA TEXT */
argument|initialize_gdc(T30_G400, info.vi_flags& V_INFO_GRAPHICS); 	    break; 	default: 	    break;     }
ifndef|#
directive|ifndef
name|GDC_NOGRAPHICS
argument|if (info.vi_flags& V_INFO_VESA) { 	outb(
literal|0x6a
argument|,
literal|0x07
argument|);
comment|/* enable mode F/F change */
argument|outb(
literal|0x6a
argument|,
literal|0x21
argument|);
comment|/* enhanced graphics */
argument|if (info.vi_height>
literal|400
argument|) 	    outb(
literal|0x6a
argument|,
literal|0x69
argument|);
comment|/* 800 lines */
argument|writeb(BIOS_PADDRTOVADDR(
literal|0x000e0100
argument|),
literal|0
argument|);
comment|/* packed pixel */
argument|} else { 	if (adp->va_flags& V_ADP_VESA) { 	    outb(
literal|0x6a
argument|,
literal|0x07
argument|);
comment|/* enable mode F/F change */
argument|outb(
literal|0x6a
argument|,
literal|0x20
argument|);
comment|/* normal graphics */
argument|outb(
literal|0x6a
argument|,
literal|0x68
argument|);
comment|/* 400 lines */
argument|} 	outb(
literal|0x6a
argument|,
literal|1
argument|);
comment|/* 16 colors */
argument|}
endif|#
directive|endif
argument|adp->va_mode = mode;     adp->va_flags&= ~V_ADP_COLOR;     adp->va_flags |=  	(info.vi_flags& V_INFO_COLOR) ? V_ADP_COLOR :
literal|0
argument|;
if|#
directive|if
literal|0
argument|adp->va_crtc_addr = 	(adp->va_flags& V_ADP_COLOR) ? COLOR_CRTC : MONO_CRTC;
endif|#
directive|endif
argument|adp->va_window = BIOS_PADDRTOVADDR(info.vi_window);     adp->va_window_size = info.vi_window_size;     adp->va_window_gran = info.vi_window_gran;     if (info.vi_buffer_size ==
literal|0
argument|) {     	adp->va_buffer =
literal|0
argument|;     	adp->va_buffer_size =
literal|0
argument|;     } else {     	adp->va_buffer = BIOS_PADDRTOVADDR(info.vi_buffer);     	adp->va_buffer_size = info.vi_buffer_size;     }     if (info.vi_flags& V_INFO_GRAPHICS) { 	switch (info.vi_depth/info.vi_planes) { 	case
literal|1
argument|: 	    adp->va_line_width = info.vi_width/
literal|8
argument|; 	    break; 	case
literal|2
argument|: 	    adp->va_line_width = info.vi_width/
literal|4
argument|; 	    break; 	case
literal|4
argument|: 	    adp->va_line_width = info.vi_width/
literal|2
argument|; 	    break; 	case
literal|8
argument|: 	default:
comment|/* shouldn't happen */
argument|adp->va_line_width = info.vi_width; 	    break; 	}     } else { 	adp->va_line_width = info.vi_width;     }     bcopy(&info,&adp->va_info, sizeof(info));
comment|/* move hardware cursor out of the way */
argument|(*vidsw[adp->va_index]->set_hw_cursor)(adp, -
literal|1
argument|, -
literal|1
argument|);      return
literal|0
argument|; }
comment|/*  * set_border():  * Change the border color.  */
argument|static int gdc_set_border(video_adapter_t *adp, int color) {     outb(
literal|0x6c
argument|, color<<
literal|4
argument|);                                                      return
literal|0
argument|; }
comment|/*  * save_state():  * Read video card register values.  */
argument|static int gdc_save_state(video_adapter_t *adp, void *p, size_t size) {     return ENODEV; }
comment|/*  * load_state():  * Set video card registers at once.  */
argument|static int gdc_load_state(video_adapter_t *adp, void *p) {     return ENODEV; }
comment|/*  * read_hw_cursor():  * Read the position of the hardware text cursor.  */
argument|static int gdc_read_hw_cursor(video_adapter_t *adp, int *col, int *row) {     u_int16_t off;     int s;      if (!gdc_init_done) 	return ENXIO;      if (adp->va_info.vi_flags& V_INFO_GRAPHICS) 	return ENODEV;      s = spltty();     master_gdc_cmd(
literal|0xe0
argument|);
comment|/* _GDC_CSRR */
argument|while((inb(TEXT_GDC +
literal|0
argument|)&
literal|0x1
argument|) ==
literal|0
argument|) {}
comment|/* GDC wait */
argument|off = inb(TEXT_GDC +
literal|2
argument|);
comment|/* EADl */
argument|off |= (inb(TEXT_GDC +
literal|2
argument|)<<
literal|8
argument|);
comment|/* EADh */
argument|inb(TEXT_GDC +
literal|2
argument|);
comment|/* dummy */
argument|inb(TEXT_GDC +
literal|2
argument|);
comment|/* dummy */
argument|inb(TEXT_GDC +
literal|2
argument|);
comment|/* dummy */
argument|splx(s);      if (off>= ROW*COL) 	off =
literal|0
argument|;     *row = off / adp->va_info.vi_width;     *col = off % adp->va_info.vi_width;      return
literal|0
argument|; }
comment|/*  * set_hw_cursor():  * Move the hardware text cursor.  If col and row are both -1,   * the cursor won't be shown.  */
argument|static int gdc_set_hw_cursor(video_adapter_t *adp, int col, int row) {     u_int16_t off;     int s;      if (!gdc_init_done) 	return ENXIO;      if ((col == -
literal|1
argument|)&& (row == -
literal|1
argument|)) { 	off = -
literal|1
argument|;     } else { 	if (adp->va_info.vi_flags& V_INFO_GRAPHICS) 	    return ENODEV; 	off = row*adp->va_info.vi_width + col;     }      s = spltty();     master_gdc_cmd(
literal|0x49
argument|);
comment|/* _GDC_CSRW */
argument|master_gdc_word_prm(off);     splx(s);      return
literal|0
argument|; }
comment|/*  * set_hw_cursor_shape():  * Change the shape of the hardware text cursor.  If the height is zero  * or negative, the cursor won't be shown.  */
argument|static int gdc_set_hw_cursor_shape(video_adapter_t *adp, int base, int height, 			int celsize, int blink) {     int start;     int end;     int s;      if (!gdc_init_done) 	return ENXIO;      start = celsize - (base + height);     end = celsize - base -
literal|1
argument|;
if|#
directive|if
literal|0
comment|/*      * muPD7220 GDC has anomaly that if end == celsize - 1 then start      * must be 0, otherwise the cursor won't be correctly shown       * in the first row in the screen.  We shall set end to celsize - 2;      * if end == celsize -1&& start> 0. XXX      */
argument|if ((end == celsize - 1)&& (start> 0)&& (start< end)) 	--end;
endif|#
directive|endif
argument|s = spltty();     master_gdc_cmd(
literal|0x4b
argument|);
comment|/* _GDC_CSRFORM */
argument|master_gdc_prm(((height>
literal|0
argument|) ?
literal|0x80
argument|:
literal|0
argument|)
comment|/* cursor on/off */
argument|| ((celsize -
literal|1
argument|)&
literal|0x1f
argument|));
comment|/* cel size */
argument|master_gdc_word_prm(((end&
literal|0x1f
argument|)<<
literal|11
argument|)
comment|/* end line */
argument|| (
literal|12
argument|<<
literal|6
argument|)
comment|/* blink rate */
argument|| (blink ?
literal|0
argument|:
literal|0x20
argument|)
comment|/* blink on/off */
argument|| (start&
literal|0x1f
argument|));
comment|/* start line */
argument|splx(s);      return
literal|0
argument|; }
comment|/*  * blank_display()  * Put the display in power save/power off mode.  */
argument|static int gdc_blank_display(video_adapter_t *adp, int mode) {     int s;     static int standby =
literal|0
argument|;      if (!gdc_init_done) 	return ENXIO;      s = splhigh();     switch (mode) {     case V_DISPLAY_SUSPEND:     case V_DISPLAY_STAND_BY: 	outb(
literal|0x09a2
argument|,
literal|0x80
argument||
literal|0x40
argument|);
comment|/* V/H-SYNC mask */
argument|if (inb(
literal|0x09a2
argument|) == (
literal|0x80
argument||
literal|0x40
argument|)) 	    standby =
literal|1
argument|;
comment|/* FALLTHROUGH */
argument|case V_DISPLAY_BLANK: 	if (epson_machine_id ==
literal|0x20
argument|) { 	    outb(
literal|0x43f
argument|,
literal|0x42
argument|); 	    outb(
literal|0xc17
argument|, inb(
literal|0xc17
argument|)& ~
literal|0x08
argument|);
comment|/* turn off side light */
argument|outb(
literal|0xc16
argument|, inb(
literal|0xc16
argument|)& ~
literal|0x02
argument|);
comment|/* turn off back light */
argument|outb(
literal|0x43f
argument|,
literal|0x40
argument|); 	} else { 	    while (!(inb(TEXT_GDC)&
literal|0x20
argument|))
comment|/* V-SYNC wait */
argument|; 	    outb(TEXT_GDC +
literal|8
argument|,
literal|0x0e
argument|);
comment|/* DISP off */
argument|} 	break;      case V_DISPLAY_ON: 	if (epson_machine_id ==
literal|0x20
argument|) { 	    outb(
literal|0x43f
argument|,
literal|0x42
argument|); 	    outb(
literal|0xc17
argument|, inb(
literal|0xc17
argument|) |
literal|0x08
argument|); 	    outb(
literal|0xc16
argument|, inb(
literal|0xc16
argument|) |
literal|0x02
argument|); 	    outb(
literal|0x43f
argument|,
literal|0x40
argument|); 	} else { 	    while (!(inb(TEXT_GDC)&
literal|0x20
argument|))
comment|/* V-SYNC wait */
argument|; 	    outb(TEXT_GDC +
literal|8
argument|,
literal|0x0f
argument|);
comment|/* DISP on */
argument|} 	if (standby) { 	    outb(
literal|0x09a2
argument|,
literal|0x00
argument|);
comment|/* V/H-SYNC unmask */
argument|standby =
literal|0
argument|; 	} 	break;     }     splx(s);     return
literal|0
argument|; }
comment|/*  * mmap():  * Mmap frame buffer.  */
argument|static int gdc_mmap_buf(video_adapter_t *adp, vm_offset_t offset, vm_offset_t *paddr, 	     int prot) {
comment|/* FIXME: is this correct? XXX */
argument|if (offset> VIDEO_BUF_SIZE - PAGE_SIZE) 	return -
literal|1
argument|;     *paddr = adp->va_info.vi_window + offset;     return
literal|0
argument|; }
ifndef|#
directive|ifndef
name|GDC_NOGRAPHICS
argument|static void planar_fill(video_adapter_t *adp, int val) {      outb(
literal|0x7c
argument|,
literal|0x80
argument|);
comment|/* GRCG on& TDW mode */
argument|outb(
literal|0x7e
argument|,
literal|0
argument|);
comment|/* tile B */
argument|outb(
literal|0x7e
argument|,
literal|0
argument|);
comment|/* tile R */
argument|outb(
literal|0x7e
argument|,
literal|0
argument|);
comment|/* tile G */
argument|outb(
literal|0x7e
argument|,
literal|0
argument|);
comment|/* tile I */
argument|fillw_io(
literal|0
argument|, adp->va_window,
literal|0x8000
argument|/
literal|2
argument|);
comment|/* XXX */
argument|outb(
literal|0x7c
argument|,
literal|0
argument|);
comment|/* GRCG off */
argument|}  static void packed_fill(video_adapter_t *adp, int val) {     int length;     int at;
comment|/* position in the frame buffer */
argument|int l;      at =
literal|0
argument|;     length = adp->va_line_width*adp->va_info.vi_height;     while (length>
literal|0
argument|) { 	l = imin(length, adp->va_window_size); 	(*vidsw[adp->va_index]->set_win_org)(adp, at); 	bzero_io(adp->va_window, l); 	length -= l; 	at += l;     } }  static int gdc_clear(video_adapter_t *adp) {      switch (adp->va_info.vi_mem_model) {     case V_INFO_MM_TEXT:
comment|/* do nothing? XXX */
argument|break;     case V_INFO_MM_PLANAR: 	planar_fill(adp,
literal|0
argument|); 	break;     case V_INFO_MM_PACKED: 	packed_fill(adp,
literal|0
argument|); 	break;     }      return
literal|0
argument|; }
else|#
directive|else
comment|/* GDC_NOGRAPHICS */
argument|static int gdc_clear(video_adapter_t *adp) {      return
literal|0
argument|; }
endif|#
directive|endif
comment|/* GDC_NOGRAPHICS */
argument|static int gdc_fill_rect(video_adapter_t *adp, int val, int x, int y, int cx, int cy) {     return ENODEV; }  static int gdc_bitblt(video_adapter_t *adp,...) {
comment|/* FIXME */
argument|return ENODEV; }  static int gdc_dev_ioctl(video_adapter_t *adp, u_long cmd, caddr_t arg) {     switch (cmd) {     case FBIO_GETWINORG:
comment|/* get frame buffer window origin */
argument|*(u_int *)arg =
literal|0
argument|; 	return
literal|0
argument|;      case FBIO_SETWINORG:
comment|/* set frame buffer window origin */
argument|case FBIO_SETDISPSTART:
comment|/* set display start address */
argument|case FBIO_SETLINEWIDTH:
comment|/* set scan line length in pixel */
argument|case FBIO_GETPALETTE:
comment|/* get color palette */
argument|case FBIO_SETPALETTE:
comment|/* set color palette */
argument|case FBIOGETCMAP:
comment|/* get color palette */
argument|case FBIOPUTCMAP:
comment|/* set color palette */
argument|return ENODEV;      case FBIOGTYPE:
comment|/* get frame buffer type info. */
argument|((struct fbtype *)arg)->fb_type = fb_type(adp->va_type); 	((struct fbtype *)arg)->fb_height = adp->va_info.vi_height; 	((struct fbtype *)arg)->fb_width = adp->va_info.vi_width; 	((struct fbtype *)arg)->fb_depth = adp->va_info.vi_depth; 	if ((adp->va_info.vi_depth<=
literal|1
argument|) || (adp->va_info.vi_depth>
literal|8
argument|)) 	    ((struct fbtype *)arg)->fb_cmsize =
literal|0
argument|; 	else 	    ((struct fbtype *)arg)->fb_cmsize =
literal|1
argument|<< adp->va_info.vi_depth; 	((struct fbtype *)arg)->fb_size = adp->va_buffer_size; 	return
literal|0
argument|;      default: 	return fb_commonioctl(adp, cmd, arg);     } }
comment|/*  * diag():  * Print some information about the video adapter and video modes,  * with requested level of details.  */
argument|static int gdc_diag(video_adapter_t *adp, int level) {
if|#
directive|if
name|FB_DEBUG
operator|>
literal|1
argument|int i;
endif|#
directive|endif
argument|if (!gdc_init_done) 	return ENXIO;      fb_dump_adp_info(DRIVER_NAME, adp, level);
if|#
directive|if
name|FB_DEBUG
operator|>
literal|1
argument|for (i =
literal|0
argument|; bios_vmode[i].vi_mode != EOT; ++i) { 	 if (bios_vmode[i].vi_mode == NA) 	    continue; 	 if (get_mode_param(bios_vmode[i].vi_mode) == NULL) 	    continue; 	 fb_dump_mode_info(DRIVER_NAME, adp,&bios_vmode[i], level);     }
endif|#
directive|endif
argument|return
literal|0
argument|; }
end_function

end_unit

