begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)qd_data.c	1.16	(ULTRIX)	7/2/86  */
end_comment

begin_comment
comment|/************************************************************************  *									*  *			Copyright (c) 1985, 1986 by			*  *		Digital Equipment Corporation, Maynard, MA		*  *			All rights reserved.				*  *									*  *   This software is furnished under a license and may be used and	*  *   copied  only  in accordance with the terms of such license and	*  *   with the  inclusion  of  the  above  copyright  notice.   This	*  *   software  or  any	other copies thereof may not be provided or	*  *   otherwise made available to any other person.  No title to and	*  *   ownership of the software is hereby transferred.			*  *									*  *   The information in this software is subject to change  without	*  *   notice  and should not be construed as a commitment by Digital	*  *   Equipment Corporation.						*  *									*  *   Digital assumes no responsibility for the use  or	reliability	*  *   of its software on equipment which is not supplied by Digital.	*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*  * qd_data.c  *  * Modification history  *  * QDSS data file  *  *  3-Jul-85 - longo  *  *	Created file.  *  * 15-Jul-85 - longo  *  *	Added "qdfont.h" include and moved "mouse_report" struct  *	and definitions in from "qduser.h".  *  * 18-Aug-85 - longo  *  *	Added "duart_imask" entry to qdflags for shadowing.  *  *  4-Sep-85 - longo  *  *	Added storage "QBAreg[]" for DMA support.  *  * 11-Sep-85 - longo  *  *	Added constant for event buffer size (now 1k).  *  * 17-Sep-85 - longo  *  *	Changes for DMA support.  *  * 18-Sep-85 - longo  *  *	Changes for scroll interrupt support.  *  *  2-Oct-85 - longo  *  *	Added color map write buffer shared RAM stuff and adder  *	interrupt enable register shadowing to qdflags.  *  *  4-Oct-85 - longo  *  *	Added kernel loop back state flag to qdflags.  *  * 16-Oct-85 - longo  *  *	Added "pntr_id" entry to qdflags struct.  *  * 22-Oct-85 - longo  *  *	Added buf structures for use by driver strategy routines.  *  * 23-Oct-85 - longo  *  *	Added "user_dma" entry to qdflag structure.  *  *  8-Nov-85 - longo  *  *	Added "selmask" entry to qdflags structure.  *  * 11-Nov-85 - longo  *  *	Changed "_vs_eventqueue" struct references to "qdinput".  *  * 25-Nov-85 - longo  *  *	Added "one_only" lock switch for single process access.  *  * 18-Mar-86 - jaw  *  *	Add routines to cpu switch for nexus/unibus addreses.  *	Also got rid of some globals like nexnum.  *	ka8800 cleanup.  *  * 19-Mar-86 - ricky palmer  *  *	Added "devio.h" to include list. V2.0  *  * 02-Jul-86 -  Brian Stevens  *  *	Added cursor structure for each display  *  */
end_comment

begin_include
include|#
directive|include
file|"qd.h"
end_include

begin_comment
comment|/* # of QDSS's the system is configured for */
end_comment

begin_include
include|#
directive|include
file|"../vax/pte.h"
end_include

begin_comment
comment|/* page table values */
end_comment

begin_include
include|#
directive|include
file|"../vax/mtpr.h"
end_include

begin_comment
comment|/* VAX register access stuff */
end_comment

begin_include
include|#
directive|include
file|"../sys/param.h"
end_include

begin_comment
comment|/* general system params& macros */
end_comment

begin_include
include|#
directive|include
file|"../sys/conf.h"
end_include

begin_comment
comment|/* "linesw" tty driver dispatch */
end_comment

begin_include
include|#
directive|include
file|"../sys/user.h"
end_include

begin_comment
comment|/* user structure (what else?) */
end_comment

begin_include
include|#
directive|include
file|"qdioctl.h"
end_include

begin_comment
comment|/* ioctl call values */
end_comment

begin_include
include|#
directive|include
file|"../sys/tty.h"
end_include

begin_include
include|#
directive|include
file|"../sys/map.h"
end_include

begin_comment
comment|/* resource allocation map struct */
end_comment

begin_include
include|#
directive|include
file|"../sys/buf.h"
end_include

begin_comment
comment|/* buf structs */
end_comment

begin_include
include|#
directive|include
file|"../sys/vm.h"
end_include

begin_comment
comment|/* includes 'vm' header files */
end_comment

begin_include
include|#
directive|include
file|"../sys/clist.h"
end_include

begin_comment
comment|/* char list handling structs */
end_comment

begin_include
include|#
directive|include
file|"../sys/file.h"
end_include

begin_comment
comment|/* file I/O definitions */
end_comment

begin_include
include|#
directive|include
file|"../sys/uio.h"
end_include

begin_comment
comment|/* write/read call structs */
end_comment

begin_include
include|#
directive|include
file|"../sys/kernel.h"
end_include

begin_comment
comment|/* clock handling structs */
end_comment

begin_include
include|#
directive|include
file|"../vax/cpu.h"
end_include

begin_comment
comment|/* per cpu (pcpu) struct */
end_comment

begin_include
include|#
directive|include
file|"../vaxuba/ubareg.h"
end_include

begin_comment
comment|/* uba& 'qba' register structs */
end_comment

begin_include
include|#
directive|include
file|"../vaxuba/ubavar.h"
end_include

begin_comment
comment|/* uba structs& uba map externs */
end_comment

begin_include
include|#
directive|include
file|"qduser.h"
end_include

begin_comment
comment|/* definitions shared with my client */
end_comment

begin_include
include|#
directive|include
file|"qdreg.h"
end_include

begin_comment
comment|/* QDSS device register structures */
end_comment

begin_comment
comment|/*----------------------------------------------------------- * QDSS driver status flags for tracking operational state */
end_comment

begin_struct
struct|struct
name|qdflags
block|{
name|u_int
name|inuse
decl_stmt|;
comment|/* which minor dev's are in use now */
name|u_int
name|config
decl_stmt|;
comment|/* I/O page register content */
name|u_int
name|mapped
decl_stmt|;
comment|/* user mapping status word */
name|u_int
name|kernel_loop
decl_stmt|;
comment|/* if kernel console is redirected */
name|u_int
name|user_dma
decl_stmt|;
comment|/* DMA from user space in progress */
name|u_short
name|pntr_id
decl_stmt|;
comment|/* type code of pointing device */
name|u_short
name|duart_imask
decl_stmt|;
comment|/* shadowing for duart intrpt mask reg */
name|u_short
name|adder_ie
decl_stmt|;
comment|/* shadowing for adder intrpt enbl reg */
name|u_short
name|curs_acc
decl_stmt|;
comment|/* cursor acceleration factor */
name|u_short
name|curs_thr
decl_stmt|;
comment|/* cursor acceleration threshold level */
name|u_short
name|tab_res
decl_stmt|;
comment|/* tablet resolution factor */
name|u_short
name|selmask
decl_stmt|;
comment|/* mask for active qd select entries */
block|}
struct|;
end_struct

begin_comment
comment|/* bit definitions for "inuse" entry  */
end_comment

begin_define
define|#
directive|define
name|CONS_DEV
value|0x01
end_define

begin_define
define|#
directive|define
name|ALTCONS_DEV
value|0x02
end_define

begin_define
define|#
directive|define
name|GRAPHIC_DEV
value|0x04
end_define

begin_comment
comment|/* bit definitions for 'mapped' member of flag structure */
end_comment

begin_define
define|#
directive|define
name|MAPDEV
value|0x01
end_define

begin_comment
comment|/* hardware is mapped */
end_comment

begin_define
define|#
directive|define
name|MAPDMA
value|0x02
end_define

begin_comment
comment|/* DMA buffer mapped */
end_comment

begin_define
define|#
directive|define
name|MAPEQ
value|0x04
end_define

begin_comment
comment|/* event queue buffer mapped */
end_comment

begin_define
define|#
directive|define
name|MAPSCR
value|0x08
end_define

begin_comment
comment|/* scroll param area mapped */
end_comment

begin_define
define|#
directive|define
name|MAPCOLOR
value|0x10
end_define

begin_comment
comment|/* color map writing buffer mapped */
end_comment

begin_comment
comment|/* bit definitions for 'selmask' member of qdflag structure */
end_comment

begin_define
define|#
directive|define
name|SEL_READ
value|0x01
end_define

begin_comment
comment|/* read select is active */
end_comment

begin_define
define|#
directive|define
name|SEL_WRITE
value|0x02
end_define

begin_comment
comment|/* write select is active */
end_comment

begin_comment
comment|/*---------------------------------------------- * constants used in shared memory operations */
end_comment

begin_define
define|#
directive|define
name|EVENT_BUFSIZE
value|1024
end_define

begin_comment
comment|/* # of bytes per device's event buffer */
end_comment

begin_define
define|#
directive|define
name|MAXEVENTS
value|( (EVENT_BUFSIZE - sizeof(struct qdinput))	 \ 		     / sizeof(struct _vs_event) )
end_define

begin_define
define|#
directive|define
name|DMA_BUFSIZ
value|(1024 * 3)
end_define

begin_define
define|#
directive|define
name|COLOR_BUFSIZ
value|((sizeof(struct color_buf) + 512)& ~0x01FF)
end_define

begin_comment
comment|/*******************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BINARY
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|uba_device
modifier|*
name|qdinfo
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* array of pntrs to each QDSS */
end_comment

begin_comment
comment|/* uba structure  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tty
name|qd_tty
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|qd_softc
name|qd_softc
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*---------------------------------------------------------- * static storage used by multiple functions in this code  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Qbus_unmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Qbus mapper release key */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|qdflags
name|qdflags
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* QDSS device status flags */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|qdmap
name|qdmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* QDSS register map structure */
end_comment

begin_decl_stmt
specifier|extern
name|caddr_t
name|qdbase
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base address of each QDSS unit */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|buf
name|qdbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buf structs used by strategy */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|one_only
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock for single process access */
end_comment

begin_comment
comment|/*----------------------------- * shared memory allocation  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|event_shared
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reserve event buf space */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|qdinput
modifier|*
name|eq_header
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* event buf header ptrs */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|DMA_shared
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reserve DMA buf space */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|DMAreq_header
modifier|*
name|DMAheader
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DMA buf header ptrs */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|scroll_shared
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reserve space for scroll structs */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|scroll
modifier|*
name|scroll
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointers to scroll structures */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|color_shared
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reserve space: color bufs */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|color_buf
modifier|*
name|color_buf
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointers to color bufs */
end_comment

begin_comment
comment|/*-------------------------------- * mouse input event structures */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mouse_report
name|last_rep
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mouse_report
name|current_rep
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*---------------------------- * input event "select" use */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|proc
modifier|*
name|rsel
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process waiting for select */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|DMAbuf_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*---------------------------- * console cursor structure */
end_comment

begin_decl_stmt
name|struct
name|_vs_cursor
name|cursor
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*********************************************************************/
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*-------------------------------------------------------------------------- * reference to an array of "uba_device" structures built by the auto * configuration program.  The uba_device structure decribes the device * sufficiently for the driver to talk to it.  The auto configuration code * fills in the uba_device structures (located in ioconf.c) from user * maintained info.  */
end_comment

begin_decl_stmt
name|struct
name|uba_device
modifier|*
name|qdinfo
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* array of pntrs to each QDSS's */
end_comment

begin_comment
comment|/* uba structures  */
end_comment

begin_decl_stmt
name|struct
name|tty
name|qd_tty
index|[
name|NQD
operator|*
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* teletype structures for each.. */
end_comment

begin_comment
comment|/* ..possible minor device */
end_comment

begin_decl_stmt
name|struct
name|qd_softc
name|qd_softc
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*---------------------------------------------------------- * static storage used by multiple functions in this code  */
end_comment

begin_decl_stmt
name|int
name|Qbus_unmap
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Qbus mapper release code */
end_comment

begin_decl_stmt
name|struct
name|qdflags
name|qdflags
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* QDSS device status flags */
end_comment

begin_decl_stmt
name|struct
name|qdmap
name|qdmap
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* QDSS register map structure */
end_comment

begin_decl_stmt
name|caddr_t
name|qdbase
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base address of each QDSS unit */
end_comment

begin_decl_stmt
name|struct
name|buf
name|qdbuf
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buf structs used by strategy */
end_comment

begin_decl_stmt
name|char
name|one_only
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* lock for single process access */
end_comment

begin_comment
comment|/*------------------------------------------------------------------------ * the array "event_shared[]" is made up of a number of event queue buffers * equal to the number of QDSS's configured into the running kernel (NQD). * Each event queue buffer begins with an event queue header (struct qdinput) * followed by a group of event queue entries (struct _vs_event).  The array * "*eq_header[]" is an array of pointers to the start of each event queue * buffer in "event_shared[]".  */
end_comment

begin_define
define|#
directive|define
name|EQSIZE
value|((EVENT_BUFSIZE * NQD) + 512)
end_define

begin_decl_stmt
name|char
name|event_shared
index|[
name|EQSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reserve space for event bufs */
end_comment

begin_decl_stmt
name|struct
name|qdinput
modifier|*
name|eq_header
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* event queue header pntrs */
end_comment

begin_comment
comment|/*-------------------------------------------------------------------------- * This allocation method reserves enough memory pages for NQD shared DMA I/O * buffers.  Each buffer must consume an integral number of memory pages to * guarantee that a following buffer will begin on a page boundary.  Also, * enough space is allocated so that the FIRST I/O buffer can start at the * 1st page boundary after "&DMA_shared".  Page boundaries are used so that * memory protections can be turned on/off for individual buffers. */
end_comment

begin_define
define|#
directive|define
name|IOBUFSIZE
value|((DMA_BUFSIZ * NQD) + 512)
end_define

begin_decl_stmt
name|char
name|DMA_shared
index|[
name|IOBUFSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reserve I/O buffer space */
end_comment

begin_decl_stmt
name|struct
name|DMAreq_header
modifier|*
name|DMAheader
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DMA buffer header pntrs */
end_comment

begin_comment
comment|/*------------------------------------------------------------------------- * The driver assists a client in scroll operations by loading dragon * registers from an interrupt service routine.	The loading is done using * parameters found in memory shrade between the driver and it's client. * The scroll parameter structures are ALL loacted in the same memory page * for reasons of memory economy.  */
end_comment

begin_decl_stmt
name|char
name|scroll_shared
index|[
literal|2
operator|*
literal|512
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reserve space for scroll structs */
end_comment

begin_decl_stmt
name|struct
name|scroll
modifier|*
name|scroll
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointers to scroll structures */
end_comment

begin_comment
comment|/*----------------------------------------------------------------------- * the driver is programmable to provide the user with color map write * services at VSYNC interrupt time.  At interrupt time the driver loads * the color map with any user-requested load data found in shared memory */
end_comment

begin_define
define|#
directive|define
name|COLOR_SHARED
value|((COLOR_BUFSIZ * NQD) + 512)
end_define

begin_decl_stmt
name|char
name|color_shared
index|[
name|COLOR_SHARED
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reserve space: color bufs */
end_comment

begin_decl_stmt
name|struct
name|color_buf
modifier|*
name|color_buf
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointers to color bufs */
end_comment

begin_comment
comment|/*-------------------------------- * mouse input event structures */
end_comment

begin_decl_stmt
name|struct
name|mouse_report
name|last_rep
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mouse_report
name|current_rep
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*---------------------------- * input event "select" use */
end_comment

begin_decl_stmt
name|struct
name|proc
modifier|*
name|rsel
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* process waiting for select */
end_comment

begin_comment
comment|/*---------------------------- * console cursor structure */
end_comment

begin_decl_stmt
name|struct
name|_vs_cursor
name|cursor
index|[
name|NQD
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/************************************************************************/
end_comment

begin_decl_stmt
name|int
name|nNQD
init|=
name|NQD
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|DMAbuf_size
init|=
name|DMA_BUFSIZ
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

