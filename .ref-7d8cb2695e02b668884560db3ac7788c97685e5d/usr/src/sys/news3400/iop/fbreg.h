begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: fbreg.h,v 4.300 91/06/27 20:43:07 root Rel41 $ SONY  *  *	@(#)fbreg.h	7.3 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_struct
struct|struct
name|fb_softc
block|{
name|int
name|fbs_state
decl_stmt|;
name|int
name|fbs_device
decl_stmt|;
name|lScrType
name|fbs_type
decl_stmt|;
name|int
name|fbs_flag
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|news3200
argument_list|)
operator|||
name|defined
argument_list|(
name|news3400
argument_list|)
end_if

begin_define
define|#
directive|define
name|splfb
value|spl3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|news3800
end_ifdef

begin_define
define|#
directive|define
name|splfb
value|spl4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * state of fbstate  */
end_comment

begin_define
define|#
directive|define
name|FB_BUSY
value|01
end_define

begin_comment
comment|/* fb is busy */
end_comment

begin_define
define|#
directive|define
name|FB_WANTED
value|02
end_define

begin_comment
comment|/* fb is wanted */
end_comment

begin_define
define|#
directive|define
name|FB_WAIT
value|04
end_define

begin_comment
comment|/* fb is waiting for command complete */
end_comment

begin_define
define|#
directive|define
name|FB_DELAY
value|010
end_define

begin_comment
comment|/* fb is busy, but not wait (inner ioctl) */
end_comment

begin_define
define|#
directive|define
name|FB_DELAY2
value|020
end_define

begin_comment
comment|/* fb is busy, but not wait (outer ioctl) */
end_comment

begin_comment
comment|/*  * physical page map for IOP  */
end_comment

begin_define
define|#
directive|define
name|FB_MAX_IO
value|(2048*1024)
end_define

begin_comment
comment|/* 2048 KB */
end_comment

begin_define
define|#
directive|define
name|NFBMAP
value|(FB_MAX_IO / NBPG + 1)
end_define

begin_comment
comment|/* maximum number of pages */
end_comment

begin_struct
struct|struct
name|fb_map
block|{
name|caddr_t
name|fm_vaddr
decl_stmt|;
comment|/* virtual address */
name|unsigned
name|fm_offset
decl_stmt|;
comment|/* offset into first page */
name|unsigned
name|fm_count
decl_stmt|;
comment|/* byte counts */
name|caddr_t
name|fm_addr
index|[
name|NFBMAP
index|]
decl_stmt|;
comment|/* first addr into page */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|fb_map
name|fbmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * fbreg definition  */
end_comment

begin_struct
struct|struct
name|fbreg
block|{
name|u_char
name|fb_command
decl_stmt|;
comment|/* command byte */
name|u_char
name|fb_result
decl_stmt|;
comment|/* result byte */
name|u_char
name|fb_device
decl_stmt|;
comment|/* device type */
name|u_char
name|fb_unit
decl_stmt|;
comment|/* unit no */
union|union
block|{
name|lBitblt
name|_fb_bitblt
decl_stmt|;
comment|/* bitblt command */
name|lBatchBitblt
name|_fb_batchbitblt
decl_stmt|;
comment|/* batch bitblt command */
name|lTileBitblt
name|_fb_tilebitblt
decl_stmt|;
comment|/* tile bitblt command */
name|lBitblt3
name|_fb_bitblt3
decl_stmt|;
comment|/* 3 operand bitblt command */
name|lPrimLine
name|_fb_polyline
decl_stmt|;
comment|/* (disjoint) polyline */
name|lPrimRect
name|_fb_rectangle
decl_stmt|;
comment|/* rectangle */
name|lPrimFill
name|_fb_fillscan
decl_stmt|;
comment|/* fill pattern */
name|lPrimMarker
name|_fb_polymarker
decl_stmt|;
comment|/* polymarker */
name|lPrimText
name|_fb_text
decl_stmt|;
comment|/* text display */
name|lPrimDot
name|_fb_polydot
decl_stmt|;
comment|/* polydot */
name|lScrType
name|_fb_scrtype
decl_stmt|;
comment|/* screen type */
name|lCursor2
name|_fb_cursor
decl_stmt|;
comment|/* cursor area */
name|lPalette
name|_fb_palette
decl_stmt|;
comment|/* get/set palette */
name|lPoint
name|_fb_point
decl_stmt|;
name|int
name|_fb_data
decl_stmt|;
name|lVideoCtl
name|_fb_videoctl
decl_stmt|;
name|lVideoStatus
name|_fb_videostatus
decl_stmt|;
name|lFbIoctl
name|_fb_ioctl
decl_stmt|;
block|}
name|fb_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|fb_bitblt
value|fb_un._fb_bitblt
end_define

begin_define
define|#
directive|define
name|fb_batchbitblt
value|fb_un._fb_batchbitblt
end_define

begin_define
define|#
directive|define
name|fb_tilebitblt
value|fb_un._fb_tilebitblt
end_define

begin_define
define|#
directive|define
name|fb_bitblt3
value|fb_un._fb_bitblt3
end_define

begin_define
define|#
directive|define
name|fb_polyline
value|fb_un._fb_polyline
end_define

begin_define
define|#
directive|define
name|fb_rectangle
value|fb_un._fb_rectangle
end_define

begin_define
define|#
directive|define
name|fb_fillscan
value|fb_un._fb_fillscan
end_define

begin_define
define|#
directive|define
name|fb_polymarker
value|fb_un._fb_polymarker
end_define

begin_define
define|#
directive|define
name|fb_text
value|fb_un._fb_text
end_define

begin_define
define|#
directive|define
name|fb_polydot
value|fb_un._fb_polydot
end_define

begin_define
define|#
directive|define
name|fb_scrtype
value|fb_un._fb_scrtype
end_define

begin_define
define|#
directive|define
name|fb_cursor
value|fb_un._fb_cursor
end_define

begin_define
define|#
directive|define
name|fb_palette
value|fb_un._fb_palette
end_define

begin_define
define|#
directive|define
name|fb_point
value|fb_un._fb_point
end_define

begin_define
define|#
directive|define
name|fb_data
value|fb_un._fb_data
end_define

begin_define
define|#
directive|define
name|fb_videoctl
value|fb_un._fb_videoctl
end_define

begin_define
define|#
directive|define
name|fb_videostatus
value|fb_un._fb_videostatus
end_define

begin_define
define|#
directive|define
name|fb_fbioctl
value|fb_un._fb_ioctl
end_define

begin_comment
comment|/* command definiton */
end_comment

begin_define
define|#
directive|define
name|FB_CPROBE
value|0
end_define

begin_comment
comment|/* probe */
end_comment

begin_define
define|#
directive|define
name|FB_CATTACH
value|1
end_define

begin_comment
comment|/* attach */
end_comment

begin_define
define|#
directive|define
name|FB_COPEN
value|2
end_define

begin_comment
comment|/* read from Frame Buffer */
end_comment

begin_define
define|#
directive|define
name|FB_CCLOSE
value|3
end_define

begin_comment
comment|/* write to Frame Buffer */
end_comment

begin_define
define|#
directive|define
name|FB_CBITBLT
value|4
end_define

begin_comment
comment|/* bitblt */
end_comment

begin_define
define|#
directive|define
name|FB_CBATCHBITBLT
value|5
end_define

begin_comment
comment|/* bitblt */
end_comment

begin_define
define|#
directive|define
name|FB_CSETSCR
value|6
end_define

begin_comment
comment|/* set display screen */
end_comment

begin_define
define|#
directive|define
name|FB_CGETSCR
value|7
end_define

begin_comment
comment|/* get display screen */
end_comment

begin_define
define|#
directive|define
name|FB_CSETDIM
value|8
end_define

begin_comment
comment|/* set dimmer level */
end_comment

begin_define
define|#
directive|define
name|FB_CGETDIM
value|9
end_define

begin_comment
comment|/* get dimmer level */
end_comment

begin_define
define|#
directive|define
name|FB_CDRAW
value|10
end_define

begin_comment
comment|/* graphic primitive drawing */
end_comment

begin_define
define|#
directive|define
name|FB_CPOLYLINE
value|11
end_define

begin_define
define|#
directive|define
name|FB_CDJPOLYLINE
value|12
end_define

begin_define
define|#
directive|define
name|FB_CRECTANGLE
value|13
end_define

begin_define
define|#
directive|define
name|FB_CFILLSCAN
value|14
end_define

begin_define
define|#
directive|define
name|FB_CPOLYMARKER
value|15
end_define

begin_define
define|#
directive|define
name|FB_CTEXT
value|16
end_define

begin_define
define|#
directive|define
name|FB_CPOLYDOT
value|17
end_define

begin_define
define|#
directive|define
name|FB_CSETSCRMODE
value|18
end_define

begin_define
define|#
directive|define
name|FB_CGETSCRMODE
value|19
end_define

begin_define
define|#
directive|define
name|FB_CGETSCRTYPE
value|20
end_define

begin_comment
comment|/* get screen type (b/w or color8 or...) */
end_comment

begin_define
define|#
directive|define
name|FB_CSETPALETTE
value|21
end_define

begin_define
define|#
directive|define
name|FB_CGETPALETTE
value|22
end_define

begin_define
define|#
directive|define
name|FB_CSELPALETTE
value|23
end_define

begin_comment
comment|/* select current palette */
end_comment

begin_define
define|#
directive|define
name|FB_CSETDADDR
value|24
end_define

begin_comment
comment|/* set display address */
end_comment

begin_define
define|#
directive|define
name|FB_CTILEBITBLT
value|30
end_define

begin_comment
comment|/* tile bitblt */
end_comment

begin_define
define|#
directive|define
name|FB_CBITBLT3
value|31
end_define

begin_comment
comment|/* 3 operand bitblt */
end_comment

begin_define
define|#
directive|define
name|FB_CSETCURSOR
value|50
end_define

begin_define
define|#
directive|define
name|FB_CUNSETCURSOR
value|51
end_define

begin_define
define|#
directive|define
name|FB_CSHOWCURSOR
value|52
end_define

begin_define
define|#
directive|define
name|FB_CHIDECURSOR
value|53
end_define

begin_define
define|#
directive|define
name|FB_CSETXY
value|54
end_define

begin_define
define|#
directive|define
name|FB_CAUTODIM
value|55
end_define

begin_define
define|#
directive|define
name|FB_CSETVIDEO
value|60
end_define

begin_define
define|#
directive|define
name|FB_CGETVIDEO
value|61
end_define

begin_define
define|#
directive|define
name|FB_CSETPMODE
value|62
end_define

begin_define
define|#
directive|define
name|FB_CGETPMODE
value|63
end_define

begin_define
define|#
directive|define
name|FB_CGETPAGE
value|70
end_define

begin_define
define|#
directive|define
name|FB_CIOCTL
value|80
end_define

begin_comment
comment|/* result definiton */
end_comment

begin_define
define|#
directive|define
name|FB_ROK
value|0
end_define

begin_comment
comment|/* OK */
end_comment

begin_define
define|#
directive|define
name|FB_RERROR
value|1
end_define

begin_comment
comment|/* some error occurred */
end_comment

begin_define
define|#
directive|define
name|FBUNIT
parameter_list|(
name|dev
parameter_list|)
value|(minor(dev)& 0x7f)
end_define

begin_define
define|#
directive|define
name|FBVIDEO
parameter_list|(
name|dev
parameter_list|)
value|(minor(dev)& 0x80)
end_define

begin_define
define|#
directive|define
name|FBPRI
value|(PRIBIO+1)
end_define

begin_define
define|#
directive|define
name|ASROM_SIZE
value|0x10000
end_define

begin_comment
comment|/* size of auto-select ROM */
end_comment

begin_define
define|#
directive|define
name|ASREG_SIZE
value|0x10000
end_define

begin_comment
comment|/* size of auto-select control reg. */
end_comment

begin_define
define|#
directive|define
name|ASREG_SIZE2
value|0x40000
end_define

begin_comment
comment|/* size of 2nd area */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

