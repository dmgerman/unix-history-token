begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software developed by the Computer Systems  * Engineering group at Lawrence Berkeley Laboratory under DARPA  * contract BG 91-66 and contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fbio.h	8.2 (Berkeley) 10/30/93  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_FBIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_FBIO_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * Frame buffer ioctls (from Sprite, trimmed to essentials for X11).  */
end_comment

begin_comment
comment|/*  * Frame buffer type codes.  */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN1BW
value|0
end_define

begin_comment
comment|/* multibus mono */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN1COLOR
value|1
end_define

begin_comment
comment|/* multibus color */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN2BW
value|2
end_define

begin_comment
comment|/* memory mono */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN2COLOR
value|3
end_define

begin_comment
comment|/* color w/rasterop chips */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN2GP
value|4
end_define

begin_comment
comment|/* GP1/GP2 */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN5COLOR
value|5
end_define

begin_comment
comment|/* RoadRunner accelerator */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN3COLOR
value|6
end_define

begin_comment
comment|/* memory color */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_MEMCOLOR
value|7
end_define

begin_comment
comment|/* memory 24-bit */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN4COLOR
value|8
end_define

begin_comment
comment|/* memory color w/overlay */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_NOTSUN1
value|9
end_define

begin_comment
comment|/* reserved for customer */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_NOTSUN2
value|10
end_define

begin_comment
comment|/* reserved for customer */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_NOTSUN3
value|11
end_define

begin_comment
comment|/* reserved for customer */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUNFAST_COLOR
value|12
end_define

begin_comment
comment|/* accelerated 8bit */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUNROP_COLOR
value|13
end_define

begin_comment
comment|/* MEMCOLOR with rop h/w */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUNFB_VIDEO
value|14
end_define

begin_comment
comment|/* Simple video mixing */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_RESERVED5
value|15
end_define

begin_comment
comment|/* reserved, do not use */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_RESERVED4
value|16
end_define

begin_comment
comment|/* reserved, do not use */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_RESERVED3
value|17
end_define

begin_comment
comment|/* reserved, do not use */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_RESERVED2
value|18
end_define

begin_comment
comment|/* reserved, do not use */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_RESERVED1
value|19
end_define

begin_comment
comment|/* reserved, do not use */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_MDA
value|20
end_define

begin_define
define|#
directive|define
name|FBTYPE_HERCULES
value|21
end_define

begin_define
define|#
directive|define
name|FBTYPE_CGA
value|22
end_define

begin_define
define|#
directive|define
name|FBTYPE_EGA
value|23
end_define

begin_define
define|#
directive|define
name|FBTYPE_VGA
value|24
end_define

begin_define
define|#
directive|define
name|FBTYPE_PC98
value|25
end_define

begin_define
define|#
directive|define
name|FBTYPE_TGA
value|26
end_define

begin_define
define|#
directive|define
name|FBTYPE_TGA2
value|27
end_define

begin_define
define|#
directive|define
name|FBTYPE_LASTPLUSONE
value|28
end_define

begin_comment
comment|/* max number of fbs (change as add) */
end_comment

begin_comment
comment|/*  * Frame buffer descriptor as returned by FBIOGTYPE.  */
end_comment

begin_struct
struct|struct
name|fbtype
block|{
name|int
name|fb_type
decl_stmt|;
comment|/* as defined above */
name|int
name|fb_height
decl_stmt|;
comment|/* in pixels */
name|int
name|fb_width
decl_stmt|;
comment|/* in pixels */
name|int
name|fb_depth
decl_stmt|;
comment|/* bits per pixel */
name|int
name|fb_cmsize
decl_stmt|;
comment|/* size of color map (entries) */
name|int
name|fb_size
decl_stmt|;
comment|/* total size in bytes */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FBIOGTYPE
value|_IOR('F', 0, struct fbtype)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/*  * General purpose structure for passing info in and out of frame buffers  * (used for gp1) -- unsupported.  */
end_comment

begin_struct
struct|struct
name|fbinfo
block|{
name|int
name|fb_physaddr
decl_stmt|;
comment|/* physical frame buffer address */
name|int
name|fb_hwwidth
decl_stmt|;
comment|/* fb board width */
name|int
name|fb_hwheight
decl_stmt|;
comment|/* fb board height */
name|int
name|fb_addrdelta
decl_stmt|;
comment|/* phys addr diff between boards */
name|u_char
modifier|*
name|fb_ropaddr
decl_stmt|;
comment|/* fb virtual addr */
name|int
name|fb_unit
decl_stmt|;
comment|/* minor devnum of fb */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FBIOGINFO
value|_IOR('F', 2, struct fbinfo)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Color map I/O.  */
end_comment

begin_struct
struct|struct
name|fbcmap
block|{
name|int
name|index
decl_stmt|;
comment|/* first element (0 origin) */
name|int
name|count
decl_stmt|;
comment|/* number of elements */
name|u_char
modifier|*
name|red
decl_stmt|;
comment|/* red color map elements */
name|u_char
modifier|*
name|green
decl_stmt|;
comment|/* green color map elements */
name|u_char
modifier|*
name|blue
decl_stmt|;
comment|/* blue color map elements */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FBIOPUTCMAP
value|_IOW('F', 3, struct fbcmap)
end_define

begin_define
define|#
directive|define
name|FBIOGETCMAP
value|_IOW('F', 4, struct fbcmap)
end_define

begin_comment
comment|/*  * Set/get attributes.  */
end_comment

begin_define
define|#
directive|define
name|FB_ATTR_NDEVSPECIFIC
value|8
end_define

begin_comment
comment|/* no. of device specific values */
end_comment

begin_define
define|#
directive|define
name|FB_ATTR_NEMUTYPES
value|4
end_define

begin_comment
comment|/* no. of emulation types */
end_comment

begin_struct
struct|struct
name|fbsattr
block|{
name|int
name|flags
decl_stmt|;
comment|/* flags; see below */
name|int
name|emu_type
decl_stmt|;
comment|/* emulation type (-1 if unused) */
name|int
name|dev_specific
index|[
name|FB_ATTR_NDEVSPECIFIC
index|]
decl_stmt|;
comment|/* catchall */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FB_ATTR_AUTOINIT
value|1
end_define

begin_comment
comment|/* emulation auto init flag */
end_comment

begin_define
define|#
directive|define
name|FB_ATTR_DEVSPECIFIC
value|2
end_define

begin_comment
comment|/* dev. specific stuff valid flag */
end_comment

begin_struct
struct|struct
name|fbgattr
block|{
name|int
name|real_type
decl_stmt|;
comment|/* real device type */
name|int
name|owner
decl_stmt|;
comment|/* PID of owner, 0 if myself */
name|struct
name|fbtype
name|fbtype
decl_stmt|;
comment|/* fbtype info for real device */
name|struct
name|fbsattr
name|sattr
decl_stmt|;
comment|/* see above */
name|int
name|emu_types
index|[
name|FB_ATTR_NEMUTYPES
index|]
decl_stmt|;
comment|/* possible emulations */
comment|/* (-1 if unused) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FBIOSATTR
value|_IOW('F', 5, struct fbsattr)
end_define

begin_define
define|#
directive|define
name|FBIOGATTR
value|_IOR('F', 6, struct fbgattr)
end_define

begin_comment
comment|/*  * Video control.  */
end_comment

begin_define
define|#
directive|define
name|FBVIDEO_OFF
value|0
end_define

begin_define
define|#
directive|define
name|FBVIDEO_ON
value|1
end_define

begin_define
define|#
directive|define
name|FBIOSVIDEO
value|_IOW('F', 7, int)
end_define

begin_define
define|#
directive|define
name|FBIOGVIDEO
value|_IOR('F', 8, int)
end_define

begin_comment
comment|/* vertical retrace */
end_comment

begin_define
define|#
directive|define
name|FBIOVERTICAL
value|_IO('F', 9)
end_define

begin_comment
comment|/*  * Hardware cursor control (for, e.g., CG6).  A rather complex and icky  * interface that smells like VMS, but there it is....  */
end_comment

begin_struct
struct|struct
name|fbcurpos
block|{
name|short
name|x
decl_stmt|;
name|short
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fbcursor
block|{
name|short
name|set
decl_stmt|;
comment|/* flags; see below */
name|short
name|enable
decl_stmt|;
comment|/* nonzero => cursor on, 0 => cursor off */
name|struct
name|fbcurpos
name|pos
decl_stmt|;
comment|/* position on display */
name|struct
name|fbcurpos
name|hot
decl_stmt|;
comment|/* hot-spot within cursor */
name|struct
name|fbcmap
name|cmap
decl_stmt|;
comment|/* cursor color map */
name|struct
name|fbcurpos
name|size
decl_stmt|;
comment|/* number of valid bits in image& mask */
name|caddr_t
name|image
decl_stmt|;
comment|/* cursor image bits */
name|caddr_t
name|mask
decl_stmt|;
comment|/* cursor mask bits */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FB_CUR_SETCUR
value|0x01
end_define

begin_comment
comment|/* set on/off (i.e., obey fbcursor.enable) */
end_comment

begin_define
define|#
directive|define
name|FB_CUR_SETPOS
value|0x02
end_define

begin_comment
comment|/* set position */
end_comment

begin_define
define|#
directive|define
name|FB_CUR_SETHOT
value|0x04
end_define

begin_comment
comment|/* set hot-spot */
end_comment

begin_define
define|#
directive|define
name|FB_CUR_SETCMAP
value|0x08
end_define

begin_comment
comment|/* set cursor color map */
end_comment

begin_define
define|#
directive|define
name|FB_CUR_SETSHAPE
value|0x10
end_define

begin_comment
comment|/* set size& bits */
end_comment

begin_define
define|#
directive|define
name|FB_CUR_SETALL
value|(FB_CUR_SETCUR | FB_CUR_SETPOS | FB_CUR_SETHOT | \ 			 FB_CUR_SETCMAP | FB_CUR_SETSHAPE)
end_define

begin_comment
comment|/* controls for cursor attributes& shape (including position) */
end_comment

begin_define
define|#
directive|define
name|FBIOSCURSOR
value|_IOW('F', 24, struct fbcursor)
end_define

begin_define
define|#
directive|define
name|FBIOGCURSOR
value|_IOWR('F', 25, struct fbcursor)
end_define

begin_comment
comment|/* controls for cursor position only */
end_comment

begin_define
define|#
directive|define
name|FBIOSCURPOS
value|_IOW('F', 26, struct fbcurpos)
end_define

begin_define
define|#
directive|define
name|FBIOGCURPOS
value|_IOW('F', 27, struct fbcurpos)
end_define

begin_comment
comment|/* get maximum cursor size */
end_comment

begin_define
define|#
directive|define
name|FBIOGCURMAX
value|_IOR('F', 28, struct fbcurpos)
end_define

begin_comment
comment|/*  * Video board information  */
end_comment

begin_struct
struct|struct
name|brd_info
block|{
name|u_short
name|accessible_width
decl_stmt|;
comment|/* accessible bytes in scanline */
name|u_short
name|accessible_height
decl_stmt|;
comment|/* number of accessible scanlines */
name|u_short
name|line_bytes
decl_stmt|;
comment|/* number of bytes/scanline */
name|u_short
name|hdb_capable
decl_stmt|;
comment|/* can this thing hardware db? */
name|u_short
name|vmsize
decl_stmt|;
comment|/* video memory size */
name|u_char
name|boardrev
decl_stmt|;
comment|/* board revision # */
name|u_char
name|pad0
decl_stmt|;
name|u_long
name|pad1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FBIOGXINFO
value|_IOR('F', 39, struct brd_info)
end_define

begin_comment
comment|/*  * Monitor information  */
end_comment

begin_struct
struct|struct
name|mon_info
block|{
name|u_long
name|mon_type
decl_stmt|;
comment|/* bit array */
define|#
directive|define
name|MON_TYPE_STEREO
value|0x8
comment|/* stereo display */
define|#
directive|define
name|MON_TYPE_0_OFFSET
value|0x4
comment|/* black level 0 ire instead of 7.5 */
define|#
directive|define
name|MON_TYPE_OVERSCAN
value|0x2
comment|/* overscan */
define|#
directive|define
name|MON_TYPE_GRAY
value|0x1
comment|/* greyscale monitor */
name|u_long
name|pixfreq
decl_stmt|;
comment|/* pixel frequency in Hz */
name|u_long
name|hfreq
decl_stmt|;
comment|/* horizontal freq in Hz */
name|u_long
name|vfreq
decl_stmt|;
comment|/* vertical freq in Hz */
name|u_long
name|vsync
decl_stmt|;
comment|/* vertical sync in scanlines */
name|u_long
name|hsync
decl_stmt|;
comment|/* horizontal sync in pixels */
comment|/* these are in pixel units */
name|u_short
name|hfporch
decl_stmt|;
comment|/* horizontal front porch */
name|u_short
name|hbporch
decl_stmt|;
comment|/* horizontal back porch */
name|u_short
name|vfporch
decl_stmt|;
comment|/* vertical front porch */
name|u_short
name|vbporch
decl_stmt|;
comment|/* vertical back porch */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FBIOMONINFO
value|_IOR('F', 40, struct mon_info)
end_define

begin_comment
comment|/*  * Color map I/O.  */
end_comment

begin_struct
struct|struct
name|fbcmap_i
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|FB_CMAP_BLOCK
value|(1<< 0)
comment|/* wait for vertical refresh */
define|#
directive|define
name|FB_CMAP_KERNEL
value|(1<< 1)
comment|/* called within kernel */
name|int
name|id
decl_stmt|;
comment|/* color map id */
name|int
name|index
decl_stmt|;
comment|/* first element (0 origin) */
name|int
name|count
decl_stmt|;
comment|/* number of elements */
name|u_char
modifier|*
name|red
decl_stmt|;
comment|/* red color map elements */
name|u_char
modifier|*
name|green
decl_stmt|;
comment|/* green color map elements */
name|u_char
modifier|*
name|blue
decl_stmt|;
comment|/* blue color map elements */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FBIOPUTCMAPI
value|_IOW('F', 41, struct fbcmap_i)
end_define

begin_define
define|#
directive|define
name|FBIOGETCMAPI
value|_IOW('F', 42, struct fbcmap_i)
end_define

begin_comment
comment|/* The new style frame buffer ioctls. */
end_comment

begin_comment
comment|/* video mode information block */
end_comment

begin_struct
struct|struct
name|video_info
block|{
name|int
name|vi_mode
decl_stmt|;
comment|/* mode number, see below */
name|int
name|vi_flags
decl_stmt|;
define|#
directive|define
name|V_INFO_COLOR
value|(1<< 0)
define|#
directive|define
name|V_INFO_GRAPHICS
value|(1<< 1)
define|#
directive|define
name|V_INFO_LINEAR
value|(1<< 2)
define|#
directive|define
name|V_INFO_VESA
value|(1<< 3)
name|int
name|vi_width
decl_stmt|;
name|int
name|vi_height
decl_stmt|;
name|int
name|vi_cwidth
decl_stmt|;
name|int
name|vi_cheight
decl_stmt|;
name|int
name|vi_depth
decl_stmt|;
name|int
name|vi_planes
decl_stmt|;
name|vm_offset_t
name|vi_window
decl_stmt|;
comment|/* physical address */
name|size_t
name|vi_window_size
decl_stmt|;
name|size_t
name|vi_window_gran
decl_stmt|;
name|vm_offset_t
name|vi_buffer
decl_stmt|;
comment|/* physical address */
name|size_t
name|vi_buffer_size
decl_stmt|;
name|int
name|vi_mem_model
decl_stmt|;
define|#
directive|define
name|V_INFO_MM_OTHER
value|(-1)
define|#
directive|define
name|V_INFO_MM_TEXT
value|0
define|#
directive|define
name|V_INFO_MM_PLANAR
value|1
define|#
directive|define
name|V_INFO_MM_PACKED
value|2
define|#
directive|define
name|V_INFO_MM_DIRECT
value|3
define|#
directive|define
name|V_INFO_MM_CGA
value|100
define|#
directive|define
name|V_INFO_MM_HGC
value|101
define|#
directive|define
name|V_INFO_MM_VGAX
value|102
comment|/* for MM_PACKED and MM_DIRECT only */
name|int
name|vi_pixel_size
decl_stmt|;
comment|/* in bytes */
comment|/* for MM_DIRECT only */
name|int
name|vi_pixel_fields
index|[
literal|4
index|]
decl_stmt|;
comment|/* RGB and reserved fields */
name|int
name|vi_pixel_fsizes
index|[
literal|4
index|]
decl_stmt|;
comment|/* reserved */
name|u_char
name|vi_reserved
index|[
literal|64
index|]
decl_stmt|;
name|vm_offset_t
name|vi_registers
decl_stmt|;
comment|/* physical address */
name|vm_offset_t
name|vi_registers_size
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|video_info
name|video_info_t
typedef|;
end_typedef

begin_comment
comment|/* adapter infromation block */
end_comment

begin_struct
struct|struct
name|video_adapter
block|{
name|int
name|va_index
decl_stmt|;
name|int
name|va_type
decl_stmt|;
define|#
directive|define
name|KD_OTHER
value|0
comment|/* unknown */
define|#
directive|define
name|KD_MONO
value|1
comment|/* monochrome adapter */
define|#
directive|define
name|KD_HERCULES
value|2
comment|/* hercules adapter */
define|#
directive|define
name|KD_CGA
value|3
comment|/* color graphics adapter */
define|#
directive|define
name|KD_EGA
value|4
comment|/* enhanced graphics adapter */
define|#
directive|define
name|KD_VGA
value|5
comment|/* video graphics adapter */
define|#
directive|define
name|KD_PC98
value|6
comment|/* PC-98 display */
define|#
directive|define
name|KD_TGA
value|7
comment|/* TGA */
define|#
directive|define
name|KD_TGA2
value|8
comment|/* TGA2 */
name|char
modifier|*
name|va_name
decl_stmt|;
name|int
name|va_unit
decl_stmt|;
name|int
name|va_minor
decl_stmt|;
name|int
name|va_flags
decl_stmt|;
define|#
directive|define
name|V_ADP_COLOR
value|(1<< 0)
define|#
directive|define
name|V_ADP_MODECHANGE
value|(1<< 1)
define|#
directive|define
name|V_ADP_STATESAVE
value|(1<< 2)
define|#
directive|define
name|V_ADP_STATELOAD
value|(1<< 3)
define|#
directive|define
name|V_ADP_FONT
value|(1<< 4)
define|#
directive|define
name|V_ADP_PALETTE
value|(1<< 5)
define|#
directive|define
name|V_ADP_BORDER
value|(1<< 6)
define|#
directive|define
name|V_ADP_VESA
value|(1<< 7)
define|#
directive|define
name|V_ADP_BOOTDISPLAY
value|(1<< 8)
define|#
directive|define
name|V_ADP_PROBED
value|(1<< 16)
define|#
directive|define
name|V_ADP_INITIALIZED
value|(1<< 17)
define|#
directive|define
name|V_ADP_REGISTERED
value|(1<< 18)
define|#
directive|define
name|V_ADP_ATTACHED
value|(1<< 19)
name|vm_offset_t
name|va_io_base
decl_stmt|;
name|int
name|va_io_size
decl_stmt|;
name|vm_offset_t
name|va_crtc_addr
decl_stmt|;
name|vm_offset_t
name|va_mem_base
decl_stmt|;
name|int
name|va_mem_size
decl_stmt|;
name|vm_offset_t
name|va_window
decl_stmt|;
comment|/* virtual address */
name|size_t
name|va_window_size
decl_stmt|;
name|size_t
name|va_window_gran
decl_stmt|;
name|u_int
name|va_window_orig
decl_stmt|;
name|vm_offset_t
name|va_buffer
decl_stmt|;
comment|/* virtual address */
name|size_t
name|va_buffer_size
decl_stmt|;
name|int
name|va_initial_mode
decl_stmt|;
name|int
name|va_initial_bios_mode
decl_stmt|;
name|int
name|va_mode
decl_stmt|;
name|struct
name|video_info
name|va_info
decl_stmt|;
name|int
name|va_line_width
decl_stmt|;
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
name|va_disp_start
struct|;
name|void
modifier|*
name|va_token
decl_stmt|;
name|int
name|va_model
decl_stmt|;
name|int
name|va_little_bitian
decl_stmt|;
name|int
name|va_little_endian
decl_stmt|;
name|int
name|va_buffer_alias
decl_stmt|;
name|vm_offset_t
name|va_registers
decl_stmt|;
comment|/* virtual address */
name|vm_offset_t
name|va_registers_size
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|video_adapter
name|video_adapter_t
typedef|;
end_typedef

begin_struct
struct|struct
name|video_adapter_info
block|{
name|int
name|va_index
decl_stmt|;
name|int
name|va_type
decl_stmt|;
name|char
name|va_name
index|[
literal|16
index|]
decl_stmt|;
name|int
name|va_unit
decl_stmt|;
name|int
name|va_flags
decl_stmt|;
name|vm_offset_t
name|va_io_base
decl_stmt|;
name|int
name|va_io_size
decl_stmt|;
name|vm_offset_t
name|va_crtc_addr
decl_stmt|;
name|vm_offset_t
name|va_mem_base
decl_stmt|;
name|int
name|va_mem_size
decl_stmt|;
name|vm_offset_t
name|va_window
decl_stmt|;
comment|/* virtual address */
name|size_t
name|va_window_size
decl_stmt|;
name|size_t
name|va_window_gran
decl_stmt|;
name|vm_offset_t
name|va_unused0
decl_stmt|;
name|size_t
name|va_buffer_size
decl_stmt|;
name|int
name|va_initial_mode
decl_stmt|;
name|int
name|va_initial_bios_mode
decl_stmt|;
name|int
name|va_mode
decl_stmt|;
name|int
name|va_line_width
decl_stmt|;
struct|struct
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
name|va_disp_start
struct|;
name|u_int
name|va_window_orig
decl_stmt|;
comment|/* reserved */
name|u_char
name|va_reserved
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|video_adapter_info
name|video_adapter_info_t
typedef|;
end_typedef

begin_comment
comment|/* some useful video adapter index */
end_comment

begin_define
define|#
directive|define
name|V_ADP_PRIMARY
value|0
end_define

begin_define
define|#
directive|define
name|V_ADP_SECONDARY
value|1
end_define

begin_comment
comment|/* video mode numbers */
end_comment

begin_define
define|#
directive|define
name|M_B40x25
value|0
end_define

begin_comment
comment|/* black& white 40 columns */
end_comment

begin_define
define|#
directive|define
name|M_C40x25
value|1
end_define

begin_comment
comment|/* color 40 columns */
end_comment

begin_define
define|#
directive|define
name|M_B80x25
value|2
end_define

begin_comment
comment|/* black& white 80 columns */
end_comment

begin_define
define|#
directive|define
name|M_C80x25
value|3
end_define

begin_comment
comment|/* color 80 columns */
end_comment

begin_define
define|#
directive|define
name|M_BG320
value|4
end_define

begin_comment
comment|/* black& white graphics 320x200 */
end_comment

begin_define
define|#
directive|define
name|M_CG320
value|5
end_define

begin_comment
comment|/* color graphics 320x200 */
end_comment

begin_define
define|#
directive|define
name|M_BG640
value|6
end_define

begin_comment
comment|/* black& white graphics 640x200 hi-res */
end_comment

begin_define
define|#
directive|define
name|M_EGAMONO80x25
value|7
end_define

begin_comment
comment|/* ega-mono 80x25 */
end_comment

begin_define
define|#
directive|define
name|M_CG320_D
value|13
end_define

begin_comment
comment|/* ega mode D */
end_comment

begin_define
define|#
directive|define
name|M_CG640_E
value|14
end_define

begin_comment
comment|/* ega mode E */
end_comment

begin_define
define|#
directive|define
name|M_EGAMONOAPA
value|15
end_define

begin_comment
comment|/* ega mode F */
end_comment

begin_define
define|#
directive|define
name|M_CG640x350
value|16
end_define

begin_comment
comment|/* ega mode 10 */
end_comment

begin_define
define|#
directive|define
name|M_ENHMONOAPA2
value|17
end_define

begin_comment
comment|/* ega mode F with extended memory */
end_comment

begin_define
define|#
directive|define
name|M_ENH_CG640
value|18
end_define

begin_comment
comment|/* ega mode 10* */
end_comment

begin_define
define|#
directive|define
name|M_ENH_B40x25
value|19
end_define

begin_comment
comment|/* ega enhanced black& white 40 columns */
end_comment

begin_define
define|#
directive|define
name|M_ENH_C40x25
value|20
end_define

begin_comment
comment|/* ega enhanced color 40 columns */
end_comment

begin_define
define|#
directive|define
name|M_ENH_B80x25
value|21
end_define

begin_comment
comment|/* ega enhanced black& white 80 columns */
end_comment

begin_define
define|#
directive|define
name|M_ENH_C80x25
value|22
end_define

begin_comment
comment|/* ega enhanced color 80 columns */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C40x25
value|23
end_define

begin_comment
comment|/* vga 8x16 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C80x25
value|24
end_define

begin_comment
comment|/* vga 8x16 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M80x25
value|25
end_define

begin_comment
comment|/* vga 8x16 font on mono */
end_comment

begin_define
define|#
directive|define
name|M_VGA11
value|26
end_define

begin_comment
comment|/* vga 640x480 2 colors */
end_comment

begin_define
define|#
directive|define
name|M_BG640x480
value|26
end_define

begin_define
define|#
directive|define
name|M_VGA12
value|27
end_define

begin_comment
comment|/* vga 640x480 16 colors */
end_comment

begin_define
define|#
directive|define
name|M_CG640x480
value|27
end_define

begin_define
define|#
directive|define
name|M_VGA13
value|28
end_define

begin_comment
comment|/* vga 320x200 256 colors */
end_comment

begin_define
define|#
directive|define
name|M_VGA_CG320
value|28
end_define

begin_define
define|#
directive|define
name|M_VGA_C80x50
value|30
end_define

begin_comment
comment|/* vga 8x8 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M80x50
value|31
end_define

begin_comment
comment|/* vga 8x8 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C80x30
value|32
end_define

begin_comment
comment|/* vga 8x16 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M80x30
value|33
end_define

begin_comment
comment|/* vga 8x16 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C80x60
value|34
end_define

begin_comment
comment|/* vga 8x8 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M80x60
value|35
end_define

begin_comment
comment|/* vga 8x8 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_CG640
value|36
end_define

begin_comment
comment|/* vga 640x400 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_MODEX
value|37
end_define

begin_comment
comment|/* vga 320x240 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C90x25
value|40
end_define

begin_comment
comment|/* vga 8x16 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M90x25
value|41
end_define

begin_comment
comment|/* vga 8x16 font on mono */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C90x30
value|42
end_define

begin_comment
comment|/* vga 8x16 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M90x30
value|43
end_define

begin_comment
comment|/* vga 8x16 font on mono */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C90x43
value|44
end_define

begin_comment
comment|/* vga 8x8 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M90x43
value|45
end_define

begin_comment
comment|/* vga 8x8 font on mono */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C90x50
value|46
end_define

begin_comment
comment|/* vga 8x8 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M90x50
value|47
end_define

begin_comment
comment|/* vga 8x8 font on mono */
end_comment

begin_define
define|#
directive|define
name|M_VGA_C90x60
value|48
end_define

begin_comment
comment|/* vga 8x8 font on color */
end_comment

begin_define
define|#
directive|define
name|M_VGA_M90x60
value|49
end_define

begin_comment
comment|/* vga 8x8 font on mono */
end_comment

begin_define
define|#
directive|define
name|M_ENH_B80x43
value|0x70
end_define

begin_comment
comment|/* ega black& white 80x43 */
end_comment

begin_define
define|#
directive|define
name|M_ENH_C80x43
value|0x71
end_define

begin_comment
comment|/* ega color 80x43 */
end_comment

begin_define
define|#
directive|define
name|M_PC98_80x25
value|98
end_define

begin_comment
comment|/* PC98 text 80x25 */
end_comment

begin_define
define|#
directive|define
name|M_PC98_80x30
value|99
end_define

begin_comment
comment|/* PC98 text 80x30 */
end_comment

begin_define
define|#
directive|define
name|M_PC98_EGC640x400
value|100
end_define

begin_comment
comment|/* PC98 graphic 640x400 16 colors */
end_comment

begin_define
define|#
directive|define
name|M_PC98_PEGC640x400
value|101
end_define

begin_comment
comment|/* PC98 graphic 640x400 256 colors */
end_comment

begin_define
define|#
directive|define
name|M_PC98_PEGC640x480
value|102
end_define

begin_comment
comment|/* PC98 graphic 640x480 256 colors */
end_comment

begin_define
define|#
directive|define
name|M_HGC_P0
value|0xe0
end_define

begin_comment
comment|/* hercules graphics - page 0 @ B0000 */
end_comment

begin_define
define|#
directive|define
name|M_HGC_P1
value|0xe1
end_define

begin_comment
comment|/* hercules graphics - page 1 @ B8000 */
end_comment

begin_define
define|#
directive|define
name|M_MCA_MODE
value|0xff
end_define

begin_comment
comment|/* monochrome adapter mode */
end_comment

begin_define
define|#
directive|define
name|M_TEXT_80x25
value|200
end_define

begin_comment
comment|/* generic text modes */
end_comment

begin_define
define|#
directive|define
name|M_TEXT_80x30
value|201
end_define

begin_define
define|#
directive|define
name|M_TEXT_80x43
value|202
end_define

begin_define
define|#
directive|define
name|M_TEXT_80x50
value|203
end_define

begin_define
define|#
directive|define
name|M_TEXT_80x60
value|204
end_define

begin_define
define|#
directive|define
name|M_TEXT_132x25
value|205
end_define

begin_define
define|#
directive|define
name|M_TEXT_132x30
value|206
end_define

begin_define
define|#
directive|define
name|M_TEXT_132x43
value|207
end_define

begin_define
define|#
directive|define
name|M_TEXT_132x50
value|208
end_define

begin_define
define|#
directive|define
name|M_TEXT_132x60
value|209
end_define

begin_define
define|#
directive|define
name|M_VESA_BASE
value|0x100
end_define

begin_comment
comment|/* VESA mode number base */
end_comment

begin_define
define|#
directive|define
name|M_VESA_CG640x400
value|0x100
end_define

begin_comment
comment|/* 640x400, 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_CG640x480
value|0x101
end_define

begin_comment
comment|/* 640x480, 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_800x600
value|0x102
end_define

begin_comment
comment|/* 800x600, 16 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_CG800x600
value|0x103
end_define

begin_comment
comment|/* 800x600, 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_1024x768
value|0x104
end_define

begin_comment
comment|/* 1024x768, 16 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_CG1024x768
value|0x105
end_define

begin_comment
comment|/* 1024x768, 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_1280x1024
value|0x106
end_define

begin_comment
comment|/* 1280x1024, 16 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_CG1280x1024
value|0x107
end_define

begin_comment
comment|/* 1280x1024, 256 color */
end_comment

begin_define
define|#
directive|define
name|M_VESA_C80x60
value|0x108
end_define

begin_comment
comment|/* 8x8 font */
end_comment

begin_define
define|#
directive|define
name|M_VESA_C132x25
value|0x109
end_define

begin_comment
comment|/* 8x16 font */
end_comment

begin_define
define|#
directive|define
name|M_VESA_C132x43
value|0x10a
end_define

begin_comment
comment|/* 8x14 font */
end_comment

begin_define
define|#
directive|define
name|M_VESA_C132x50
value|0x10b
end_define

begin_comment
comment|/* 8x8 font */
end_comment

begin_define
define|#
directive|define
name|M_VESA_C132x60
value|0x10c
end_define

begin_comment
comment|/* 8x8 font */
end_comment

begin_define
define|#
directive|define
name|M_VESA_32K_320
value|0x10d
end_define

begin_comment
comment|/* 320x200, 5:5:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_64K_320
value|0x10e
end_define

begin_comment
comment|/* 320x200, 5:6:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_FULL_320
value|0x10f
end_define

begin_comment
comment|/* 320x200, 8:8:8 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_32K_640
value|0x110
end_define

begin_comment
comment|/* 640x480, 5:5:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_64K_640
value|0x111
end_define

begin_comment
comment|/* 640x480, 5:6:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_FULL_640
value|0x112
end_define

begin_comment
comment|/* 640x480, 8:8:8 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_32K_800
value|0x113
end_define

begin_comment
comment|/* 800x600, 5:5:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_64K_800
value|0x114
end_define

begin_comment
comment|/* 800x600, 5:6:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_FULL_800
value|0x115
end_define

begin_comment
comment|/* 800x600, 8:8:8 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_32K_1024
value|0x116
end_define

begin_comment
comment|/* 1024x768, 5:5:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_64K_1024
value|0x117
end_define

begin_comment
comment|/* 1024x768, 5:6:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_FULL_1024
value|0x118
end_define

begin_comment
comment|/* 1024x768, 8:8:8 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_32K_1280
value|0x119
end_define

begin_comment
comment|/* 1280x1024, 5:5:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_64K_1280
value|0x11a
end_define

begin_comment
comment|/* 1280x1024, 5:6:5 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_FULL_1280
value|0x11b
end_define

begin_comment
comment|/* 1280x1024, 8:8:8 */
end_comment

begin_define
define|#
directive|define
name|M_VESA_MODE_MAX
value|0x1ff
end_define

begin_struct
struct|struct
name|video_display_start
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|video_display_start
name|video_display_start_t
typedef|;
end_typedef

begin_struct
struct|struct
name|video_color_palette
block|{
name|int
name|index
decl_stmt|;
comment|/* first element (zero-based) */
name|int
name|count
decl_stmt|;
comment|/* number of elements */
name|u_char
modifier|*
name|red
decl_stmt|;
comment|/* red */
name|u_char
modifier|*
name|green
decl_stmt|;
comment|/* green */
name|u_char
modifier|*
name|blue
decl_stmt|;
comment|/* blue */
name|u_char
modifier|*
name|transparent
decl_stmt|;
comment|/* may be NULL */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|video_color_palette
name|video_color_palette_t
typedef|;
end_typedef

begin_comment
comment|/* adapter info. */
end_comment

begin_define
define|#
directive|define
name|FBIO_ADAPTER
value|_IOR('F', 100, int)
end_define

begin_define
define|#
directive|define
name|FBIO_ADPTYPE
value|_IOR('F', 101, int)
end_define

begin_define
define|#
directive|define
name|FBIO_ADPINFO
value|_IOR('F', 102, struct video_adapter_info)
end_define

begin_comment
comment|/* video mode control */
end_comment

begin_define
define|#
directive|define
name|FBIO_MODEINFO
value|_IOWR('F', 103, struct video_info)
end_define

begin_define
define|#
directive|define
name|FBIO_FINDMODE
value|_IOWR('F', 104, struct video_info)
end_define

begin_define
define|#
directive|define
name|FBIO_GETMODE
value|_IOR('F', 105, int)
end_define

begin_define
define|#
directive|define
name|FBIO_SETMODE
value|_IOW('F', 106, int)
end_define

begin_comment
comment|/* get/set frame buffer window origin */
end_comment

begin_define
define|#
directive|define
name|FBIO_GETWINORG
value|_IOR('F', 107, u_int)
end_define

begin_define
define|#
directive|define
name|FBIO_SETWINORG
value|_IOW('F', 108, u_int)
end_define

begin_comment
comment|/* get/set display start address */
end_comment

begin_define
define|#
directive|define
name|FBIO_GETDISPSTART
value|_IOR('F', 109, video_display_start_t)
end_define

begin_define
define|#
directive|define
name|FBIO_SETDISPSTART
value|_IOW('F', 110, video_display_start_t)
end_define

begin_comment
comment|/* get/set scan line width */
end_comment

begin_define
define|#
directive|define
name|FBIO_GETLINEWIDTH
value|_IOR('F', 111, u_int)
end_define

begin_define
define|#
directive|define
name|FBIO_SETLINEWIDTH
value|_IOW('F', 112, u_int)
end_define

begin_comment
comment|/* color palette control */
end_comment

begin_define
define|#
directive|define
name|FBIO_GETPALETTE
value|_IOW('F', 113, video_color_palette_t)
end_define

begin_define
define|#
directive|define
name|FBIO_SETPALETTE
value|_IOW('F', 114, video_color_palette_t)
end_define

begin_comment
comment|/* blank display */
end_comment

begin_define
define|#
directive|define
name|V_DISPLAY_ON
value|0
end_define

begin_define
define|#
directive|define
name|V_DISPLAY_BLANK
value|1
end_define

begin_define
define|#
directive|define
name|V_DISPLAY_STAND_BY
value|2
end_define

begin_define
define|#
directive|define
name|V_DISPLAY_SUSPEND
value|3
end_define

begin_define
define|#
directive|define
name|FBIO_BLANK
value|_IOW('F', 115, int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_FBIO_H_ */
end_comment

end_unit

