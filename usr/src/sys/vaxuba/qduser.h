begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  * 		@(#)qduser.h	1.4  Berkeley  6/3/88  */
end_comment

begin_comment
comment|/* derived from: @(#)qduser.h	6.1	(ULTRIX)	11/24/87       */
end_comment

begin_comment
comment|/************************************************************************  *									*  *			Copyright (c) 1986 by				*  *		Digital Equipment Corporation, Maynard, MA		*  *			All rights reserved.				*  *									*  *   This software is furnished under a license and may be used and	*  *   copied  only  in accordance with the terms of such license and	*  *   with the  inclusion  of  the  above  copyright  notice.   This	*  *   software  or  any  other copies thereof may not be provided or	*  *   otherwise made available to any other person.  No title to and	*  *   ownership of the software is hereby transferred.			*  *									*  *   The information in this software is subject to change  without	*  *   notice  and should not be construed as a commitment by Digital	*  *   Equipment Corporation.						*  *									*  *   Digital assumes no responsibility for the use  or  reliability	*  *   of its software on equipment which is not supplied by Digital.	*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** * *	QDUSER... *	This file defines values shared between the driver and a client * ***************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** *	revision history: **************************************************************************** * * 21 jul 86  ram    fixed define of CURSOR_MIN_Y * 25 nov 85  longo  added macro and bit defines for DMA error flags * 11 nov 85  longo  renamed _vs_eventqueue to "qdinput" struct * 23 oct 85  longo  added more defines to the DMA stuff * 17 oct 85  longo  changed "struct rgb" chars to be unsigned * 16 oct 85  longo  added new TABLET support definitions * 15 oct 85  longo  re-wrote DMA queue access macros * 08 oct 85  longo  added status flag manipulation macros to DMA stuff * 02 oct 85  longo  added support for color map write buffer loading * 26 sep 85  longo  removed adder sertup params from DMA request struct * 23 sep 85  longo  added DMA queue access macros * 30 aug 85  longo  fixed crock in "qdiobuf" struct compile-time sizing. Also *		    removed DMAcontrol struct from DMA buffer for field test * 26 aug 85  longo  put in conditional include of "qevent.h" for user prg's * 18 jul 85  longo  changed semantics so that head is tail and tail is head * 12 jul 85  longo  moved "mouse_report" struct and defs over to qd_data.c * 11 jul 85  longo  added device coordinate to gate array cursor coordinate *		    transformation macros * 03 jul 85  longo  changed kernel typdef's for data types to long-hand * 10 may 85  longo  created * ***************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"qevent.h"
end_include

begin_comment
comment|/* include event struct defs */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<vaxuba/qevent.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*--------------------- * QDSS device map */
end_comment

begin_struct
struct|struct
name|qdmap
block|{
comment|/* map of register blocks in QDSS */
name|char
modifier|*
name|template
decl_stmt|;
name|char
modifier|*
name|adder
decl_stmt|;
name|char
modifier|*
name|dga
decl_stmt|;
name|char
modifier|*
name|duart
decl_stmt|;
name|char
modifier|*
name|memcsr
decl_stmt|;
name|char
modifier|*
name|red
decl_stmt|;
name|char
modifier|*
name|blue
decl_stmt|;
name|char
modifier|*
name|green
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*-------------------------------------------- * DGA CSR bit definitions and register map */
end_comment

begin_define
define|#
directive|define
name|DMADONE
value|0x8000
end_define

begin_comment
comment|/* DMA done status */
end_comment

begin_define
define|#
directive|define
name|SET_DONE_FIFO
value|0x4000
end_define

begin_comment
comment|/* set DMADONE when FIFO empty.. */
end_comment

begin_comment
comment|/* ..AND count = 0 */
end_comment

begin_define
define|#
directive|define
name|PTOB_ENB
value|0x0600
end_define

begin_comment
comment|/* host-to-bitmap DMA xfer */
end_comment

begin_define
define|#
directive|define
name|BTOP_ENB
value|0x0400
end_define

begin_comment
comment|/* bitmap-to-host DMA xfer */
end_comment

begin_define
define|#
directive|define
name|DL_ENB
value|0x0200
end_define

begin_comment
comment|/* display list DMA xfer */
end_comment

begin_define
define|#
directive|define
name|HALT
value|0x0000
end_define

begin_comment
comment|/* halt DGA */
end_comment

begin_define
define|#
directive|define
name|BYTE_DMA
value|0x0100
end_define

begin_comment
comment|/* byte/word DMA xfer */
end_comment

begin_define
define|#
directive|define
name|DMA_ERR
value|0x0080
end_define

begin_comment
comment|/* DMA error bits */
end_comment

begin_define
define|#
directive|define
name|PARITY_ERR
value|0x0040
end_define

begin_comment
comment|/* memory parity error in DMA */
end_comment

begin_define
define|#
directive|define
name|BUS_ERR
value|0x0020
end_define

begin_comment
comment|/* bus timeout error in DMA */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_IE
value|0x0004
end_define

begin_comment
comment|/* global interrupt enable */
end_comment

begin_define
define|#
directive|define
name|DMA_IE
value|0x0002
end_define

begin_comment
comment|/* DMA interrupt enable */
end_comment

begin_define
define|#
directive|define
name|CURS_ENB
value|0x0001
end_define

begin_comment
comment|/* cursor enable */
end_comment

begin_comment
comment|/* QDSS memcsr bit definitions */
end_comment

begin_define
define|#
directive|define
name|UNBLANK
value|0x0020
end_define

begin_define
define|#
directive|define
name|SYNC_ON
value|0x0008
end_define

begin_struct
struct|struct
name|dga
block|{
name|unsigned
name|short
name|csr
decl_stmt|;
name|unsigned
name|short
name|adrs_lo
decl_stmt|;
comment|/* destination address of bitmap to */
name|unsigned
name|short
name|adrs_hi
decl_stmt|;
comment|/*   host DMA */
name|unsigned
name|short
name|bytcnt_lo
decl_stmt|;
comment|/* byte length of requested DMA */
name|unsigned
name|short
name|bytcnt_hi
decl_stmt|;
comment|/* (WO = bytcnt) (RO = fifo count) */
name|unsigned
name|short
name|fifo
decl_stmt|;
comment|/* FIFO register */
name|unsigned
name|short
name|x_cursor
decl_stmt|;
comment|/* cursor position registers */
name|unsigned
name|short
name|y_cursor
decl_stmt|;
name|unsigned
name|short
name|ivr
decl_stmt|;
comment|/* interrupt vector register */
name|unsigned
name|short
name|memadr
decl_stmt|;
comment|/* memory base address register */
block|}
struct|;
end_struct

begin_comment
comment|/*------------------------------------------------------------------------- * macros to transform device coordinates to hardware cursor coordinates */
end_comment

begin_define
define|#
directive|define
name|CURS_MIN_X
value|232
end_define

begin_comment
comment|/* device coordinate x = 0 */
end_comment

begin_define
define|#
directive|define
name|CURS_MIN_Y
value|16
end_define

begin_comment
comment|/* device coordinate y = 0 */
end_comment

begin_define
define|#
directive|define
name|TRANX
parameter_list|(
name|x
parameter_list|)
value|( -(((int)(x)+CURS_MIN_X)& ~0x0003) | \ 		   (((int)(x)+CURS_MIN_X)& 0x0003) )
end_define

begin_define
define|#
directive|define
name|TRANY
parameter_list|(
name|y
parameter_list|)
value|( -((y)+CURS_MIN_Y) )
end_define

begin_comment
comment|/********************************************************************* * *	EVENT QUEUE DEFINITIONS * ********************************************************************** * most of the event queue definitions are found in "qevent.h".  But a * few things not found there are here.  */
end_comment

begin_comment
comment|/* The event queue header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|qdinput
block|{
name|struct
name|_vs_eventqueue
name|header
decl_stmt|;
comment|/* event queue ring handling */
comment|/* for VS100 and QVSS compatability reasons, additions to this 	    *  structure must be made below this point.  */
name|struct
name|_vs_cursor
name|curs_pos
decl_stmt|;
comment|/* current mouse position */
name|struct
name|_vs_box
name|curs_box
decl_stmt|;
comment|/* cursor reporting box */
block|}
empty_stmt|;
end_typedef

begin_comment
comment|/* vse_key field.  definitions for mouse buttons */
end_comment

begin_define
define|#
directive|define
name|VSE_LEFT_BUTTON
value|0
end_define

begin_define
define|#
directive|define
name|VSE_MIDDLE_BUTTON
value|1
end_define

begin_define
define|#
directive|define
name|VSE_RIGHT_BUTTON
value|2
end_define

begin_comment
comment|/* vse_key field.  definitions for mouse buttons */
end_comment

begin_define
define|#
directive|define
name|VSE_T_LEFT_BUTTON
value|0
end_define

begin_define
define|#
directive|define
name|VSE_T_FRONT_BUTTON
value|1
end_define

begin_define
define|#
directive|define
name|VSE_T_RIGHT_BUTTON
value|2
end_define

begin_define
define|#
directive|define
name|VSE_T_BACK_BUTTON
value|4
end_define

begin_define
define|#
directive|define
name|VSE_T_BARREL_BUTTON
value|VSE_T_LEFT_BUTTON
end_define

begin_define
define|#
directive|define
name|VSE_T_TIP_BUTTON
value|VSE_T_FRONT_BUTTON
end_define

begin_comment
comment|/*-------------------------------------------------------------------------- *   These are the macros to be used for loading and extracting from the event * queue.  It is presumed that the macro user will only use the access macros * if the event queue is non-empty ( ISEMPTY(eq) == FALSE ), and that the * driver will only load the event queue after checking that it is not full * ( ISFULL(eq) == FALSE ).  ("eq" is a pointer to the event queue header.) * *   Before an event access session for a particular event, the macro users * must use the xxxBEGIN macro, and the xxxEND macro after an event is through * with.  As seen below, the xxxBEGIN and xxxEND macros maintain the event * queue access mechanism. * * First, the macros to be used by the event queue reader  */
end_comment

begin_define
define|#
directive|define
name|ISEMPTY
parameter_list|(
name|eq
parameter_list|)
value|((eq)->header.head == (eq)->header.tail)
end_define

begin_define
define|#
directive|define
name|GETBEGIN
parameter_list|(
name|eq
parameter_list|)
value|(&(eq)->header.events[(eq)->header.head])
end_define

begin_define
define|#
directive|define
name|GET_X
parameter_list|(
name|event
parameter_list|)
value|((event)->vse_x)
end_define

begin_comment
comment|/* get x position */
end_comment

begin_define
define|#
directive|define
name|GET_Y
parameter_list|(
name|event
parameter_list|)
value|((event)->vse_y)
end_define

begin_comment
comment|/* get y position */
end_comment

begin_define
define|#
directive|define
name|GET_TIME
parameter_list|(
name|event
parameter_list|)
value|((event)->vse_time)
end_define

begin_comment
comment|/* get time */
end_comment

begin_define
define|#
directive|define
name|GET_TYPE
parameter_list|(
name|event
parameter_list|)
value|((event)->vse_type)
end_define

begin_comment
comment|/* get entry type */
end_comment

begin_define
define|#
directive|define
name|GET_KEY
parameter_list|(
name|event
parameter_list|)
value|((event)->vse_key)
end_define

begin_comment
comment|/* get keycode */
end_comment

begin_define
define|#
directive|define
name|GET_DIR
parameter_list|(
name|event
parameter_list|)
value|((event)->vse_direction)
end_define

begin_comment
comment|/* get direction */
end_comment

begin_define
define|#
directive|define
name|GET_DEVICE
parameter_list|(
name|event
parameter_list|)
value|((event)->vse_device)
end_define

begin_comment
comment|/* get device */
end_comment

begin_define
define|#
directive|define
name|GETEND
parameter_list|(
name|eq
parameter_list|)
value|(++(eq)->header.head>= (eq)->header.size ? \ 			   (eq)->header.head = 0 : 0 )
end_define

begin_comment
comment|/*------------------------------------------------ * macros to be used by the event queue loader  */
end_comment

begin_comment
comment|/* ISFULL yields TRUE if queue is full */
end_comment

begin_define
define|#
directive|define
name|ISFULL
parameter_list|(
name|eq
parameter_list|)
value|((eq)->header.tail+1 == (eq)->header.head ||   \ 			 ((eq)->header.tail+1 == (eq)->header.size&&  \ 			  (eq)->header.head == 0))
end_define

begin_comment
comment|/* get address of the billet for NEXT event */
end_comment

begin_define
define|#
directive|define
name|PUTBEGIN
parameter_list|(
name|eq
parameter_list|)
value|(&(eq)->header.events[(eq)->header.tail])
end_define

begin_define
define|#
directive|define
name|PUT_X
parameter_list|(
name|event
parameter_list|,
name|value
parameter_list|)
value|((event)->vse_x = value)
end_define

begin_comment
comment|/* put X pos */
end_comment

begin_define
define|#
directive|define
name|PUT_Y
parameter_list|(
name|event
parameter_list|,
name|value
parameter_list|)
value|((event)->vse_y = value)
end_define

begin_comment
comment|/* put Y pos */
end_comment

begin_define
define|#
directive|define
name|PUT_TIME
parameter_list|(
name|event
parameter_list|,
name|value
parameter_list|)
value|((event)->vse_time = value)
end_define

begin_comment
comment|/* put time */
end_comment

begin_define
define|#
directive|define
name|PUT_TYPE
parameter_list|(
name|event
parameter_list|,
name|value
parameter_list|)
value|((event)->vse_type = value)
end_define

begin_comment
comment|/* put type */
end_comment

begin_define
define|#
directive|define
name|PUT_KEY
parameter_list|(
name|event
parameter_list|,
name|value
parameter_list|)
value|((event)->vse_key = value)
end_define

begin_comment
comment|/* put input key */
end_comment

begin_define
define|#
directive|define
name|PUT_DIR
parameter_list|(
name|event
parameter_list|,
name|value
parameter_list|)
value|((event)->vse_direction = value)
end_define

begin_comment
comment|/* put dir */
end_comment

begin_define
define|#
directive|define
name|PUT_DEVICE
parameter_list|(
name|event
parameter_list|,
name|value
parameter_list|)
value|((event)->vse_device = value)
end_define

begin_comment
comment|/* put dev */
end_comment

begin_define
define|#
directive|define
name|PUTEND
parameter_list|(
name|eq
parameter_list|)
value|(++(eq)->header.tail>= (eq)->header.size ?  \ 			(eq)->header.tail = 0 : 0)
end_define

begin_comment
comment|/****************************************************************** * *	DMA I/O DEFINITIONS * ******************************************************************/
end_comment

begin_comment
comment|/*--------------------------------------------------------------------- * The DMA request queue is implemented as a ring buffer of "DMAreq"   structures.  The queue is accessed using ring indices located in the   "DMAreq_header" structure.  Access is implemented using access macros   similar to the event queue access macros above.  */
end_comment

begin_struct
struct|struct
name|DMAreq
block|{
name|short
name|DMAtype
decl_stmt|;
comment|/* DMA type code (for QDSS) */
name|short
name|DMAdone
decl_stmt|;
comment|/* DMA done parameter */
name|char
modifier|*
name|bufp
decl_stmt|;
comment|/* virtual adrs of buffer */
name|int
name|length
decl_stmt|;
comment|/* transfer buffer length */
block|}
struct|;
end_struct

begin_comment
comment|/* DMA type command codes */
end_comment

begin_define
define|#
directive|define
name|DISPLIST
value|1
end_define

begin_comment
comment|/* display list DMA */
end_comment

begin_define
define|#
directive|define
name|PTOB
value|2
end_define

begin_comment
comment|/* 1 plane Qbus to bitmap DMA */
end_comment

begin_define
define|#
directive|define
name|BTOP
value|3
end_define

begin_comment
comment|/* 1 plane bitmap to Qbus DMA */
end_comment

begin_comment
comment|/* DMA done notification code */
end_comment

begin_define
define|#
directive|define
name|FIFO_EMPTY
value|0x01
end_define

begin_comment
comment|/* DONE when FIFO becomes empty */
end_comment

begin_define
define|#
directive|define
name|COUNT_ZERO
value|0x02
end_define

begin_comment
comment|/* DONE when count becomes zero */
end_comment

begin_define
define|#
directive|define
name|WORD_PACK
value|0x04
end_define

begin_comment
comment|/* program the gate array for word packing */
end_comment

begin_define
define|#
directive|define
name|BYTE_PACK
value|0x08
end_define

begin_comment
comment|/* program gate array for byte packing */
end_comment

begin_define
define|#
directive|define
name|REQUEST_DONE
value|0x100
end_define

begin_comment
comment|/* clear when driver has processed request */
end_comment

begin_define
define|#
directive|define
name|HARD_ERROR
value|0x200
end_define

begin_comment
comment|/* DMA hardware error occurred */
end_comment

begin_comment
comment|/* DMA request queue is a ring buffer of request structures */
end_comment

begin_struct
struct|struct
name|DMAreq_header
block|{
name|int
name|QBAreg
decl_stmt|;
comment|/* cookie Qbus map reg for this buffer */
name|short
name|status
decl_stmt|;
comment|/* master DMA status word */
name|int
name|shared_size
decl_stmt|;
comment|/* size of shared memory in bytes */
name|struct
name|DMAreq
modifier|*
name|DMAreq
decl_stmt|;
comment|/* start address of request queue */
name|int
name|used
decl_stmt|;
comment|/* # of queue entries currently used */
name|int
name|size
decl_stmt|;
comment|/* # of "DMAreq"'s in the request queue */
name|int
name|oldest
decl_stmt|;
comment|/* index to oldest queue'd request */
name|int
name|newest
decl_stmt|;
comment|/* index to newest queue'd request */
block|}
struct|;
end_struct

begin_comment
comment|/* bit definitions for DMAstatus word in DMAreq_header */
end_comment

begin_define
define|#
directive|define
name|DMA_ACTIVE
value|0x0004
end_define

begin_comment
comment|/* DMA in progress */
end_comment

begin_define
define|#
directive|define
name|DMA_ERROR
value|0x0080
end_define

begin_comment
comment|/* DMA hardware error */
end_comment

begin_define
define|#
directive|define
name|DMA_IGNORE
value|0x0002
end_define

begin_comment
comment|/* flag to ignore this interrupt */
end_comment

begin_comment
comment|/*------------------------------------------ * macros for DMA request queue fiddling  */
end_comment

begin_comment
comment|/* DMA status set/check macros */
end_comment

begin_define
define|#
directive|define
name|DMA_SETACTIVE
parameter_list|(
name|header
parameter_list|)
value|((header)->status |= DMA_ACTIVE)
end_define

begin_define
define|#
directive|define
name|DMA_CLRACTIVE
parameter_list|(
name|header
parameter_list|)
value|((header)->status&= ~DMA_ACTIVE)
end_define

begin_define
define|#
directive|define
name|DMA_ISACTIVE
parameter_list|(
name|header
parameter_list|)
value|((header)->status& DMA_ACTIVE)
end_define

begin_define
define|#
directive|define
name|DMA_SETERROR
parameter_list|(
name|header
parameter_list|)
value|((header)->status |= DMA_ERROR)
end_define

begin_define
define|#
directive|define
name|DMA_CLRERROR
parameter_list|(
name|header
parameter_list|)
value|((header)->status&= ~DMA_ERROR)
end_define

begin_define
define|#
directive|define
name|DMA_ISERROR
parameter_list|(
name|header
parameter_list|)
value|((header)->status& DMA_ERROR)
end_define

begin_define
define|#
directive|define
name|DMA_SETIGNORE
parameter_list|(
name|header
parameter_list|)
value|((header)->status |= DMA_IGNORE)
end_define

begin_define
define|#
directive|define
name|DMA_CLRIGNORE
parameter_list|(
name|header
parameter_list|)
value|((header)->status&= ~DMA_IGNORE)
end_define

begin_define
define|#
directive|define
name|DMA_ISIGNORE
parameter_list|(
name|header
parameter_list|)
value|((header)->status& DMA_IGNORE)
end_define

begin_comment
comment|/* yields TRUE if queue is empty (ISEMPTY) or full (ISFULL) */
end_comment

begin_define
define|#
directive|define
name|DMA_ISEMPTY
parameter_list|(
name|header
parameter_list|)
value|((header)->used == 0)
end_define

begin_define
define|#
directive|define
name|DMA_ISFULL
parameter_list|(
name|header
parameter_list|)
value|((header)->used>= (header)->size)
end_define

begin_comment
comment|/* returns address of the billet for next (PUT) 	 * or oldest (GET) request */
end_comment

begin_define
define|#
directive|define
name|DMA_PUTBEGIN
parameter_list|(
name|header
parameter_list|)
value|(&(header)->DMAreq[(header)->newest])
end_define

begin_define
define|#
directive|define
name|DMA_GETBEGIN
parameter_list|(
name|header
parameter_list|)
value|(&(header)->DMAreq[(header)->oldest])
end_define

begin_comment
comment|/* does queue access pointer maintenance */
end_comment

begin_define
define|#
directive|define
name|DMA_GETEND
parameter_list|(
name|header
parameter_list|)
value|(++(header)->oldest>= (header)->size    \ 				  ? (header)->oldest = 0 : 0);		 \ 				--(header)->used;
end_define

begin_define
define|#
directive|define
name|DMA_PUTEND
parameter_list|(
name|header
parameter_list|)
value|(++(header)->newest>= (header)->size    \ 				  ? (header)->newest = 0 : 0);		 \ 				++(header)->used;
end_define

begin_comment
comment|/****************************************************************** * *	COLOR MAP WRITE BUFFER DEFINITIONS * ******************************************************************/
end_comment

begin_struct
struct|struct
name|rgb
block|{
name|unsigned
name|char
name|offset
decl_stmt|;
comment|/* color map address for load */
name|unsigned
name|char
name|red
decl_stmt|;
comment|/* data for red map */
name|unsigned
name|char
name|green
decl_stmt|;
comment|/* data for green map */
name|unsigned
name|char
name|blue
decl_stmt|;
comment|/* data for blue map */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|color_buf
block|{
name|char
name|status
decl_stmt|;
comment|/* load request/service status */
name|short
name|count
decl_stmt|;
comment|/* number of entries to br loaded */
name|struct
name|rgb
name|rgb
index|[
literal|256
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LOAD_COLOR_MAP
value|0x0001
end_define

begin_comment
comment|/****************************************************************** * *	SCROLL ASSIST DEFINITIONS * ******************************************************************/
end_comment

begin_struct
struct|struct
name|scroll
block|{
name|short
name|status
decl_stmt|;
name|short
name|viper_constant
decl_stmt|;
name|short
name|y_scroll_constant
decl_stmt|;
name|short
name|y_offset
decl_stmt|;
name|short
name|x_index_pending
decl_stmt|;
name|short
name|y_index_pending
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LOAD_REGS
value|0x0001
end_define

begin_define
define|#
directive|define
name|LOAD_INDEX
value|0x0002
end_define

begin_comment
comment|/****************************************************************** * *	MOUSE/TABLET/KBD PROGRAMMING DEFINITIONS * ******************************************************************/
end_comment

begin_comment
comment|/*----------------------------------- * LK201 programmming definitions  */
end_comment

begin_define
define|#
directive|define
name|LK_UPDOWN
value|0x86
end_define

begin_comment
comment|/* bits for setting lk201 modes */
end_comment

begin_define
define|#
directive|define
name|LK_AUTODOWN
value|0x82
end_define

begin_define
define|#
directive|define
name|LK_DOWN
value|0x80
end_define

begin_define
define|#
directive|define
name|LK_DEFAULTS
value|0xD3
end_define

begin_comment
comment|/* reset (some) default settings */
end_comment

begin_define
define|#
directive|define
name|LK_AR_ENABLE
value|0xE3
end_define

begin_comment
comment|/* global auto repeat enable */
end_comment

begin_define
define|#
directive|define
name|LK_CL_ENABLE
value|0x1B
end_define

begin_comment
comment|/* keyclick enable */
end_comment

begin_define
define|#
directive|define
name|LK_KBD_ENABLE
value|0x8B
end_define

begin_comment
comment|/* keyboard enable */
end_comment

begin_define
define|#
directive|define
name|LK_BELL_ENABLE
value|0x23
end_define

begin_comment
comment|/* the bell */
end_comment

begin_define
define|#
directive|define
name|LK_RING_BELL
value|0xA7
end_define

begin_comment
comment|/* ring keyboard bell */
end_comment

begin_define
define|#
directive|define
name|LK_LED_ENABLE
value|0x13
end_define

begin_comment
comment|/* light led */
end_comment

begin_define
define|#
directive|define
name|LK_LED_DISABLE
value|0x11
end_define

begin_comment
comment|/* turn off led */
end_comment

begin_define
define|#
directive|define
name|LED_1
value|0x81
end_define

begin_comment
comment|/* led bits */
end_comment

begin_define
define|#
directive|define
name|LED_2
value|0x82
end_define

begin_define
define|#
directive|define
name|LED_3
value|0x84
end_define

begin_define
define|#
directive|define
name|LED_4
value|0x88
end_define

begin_define
define|#
directive|define
name|LED_ALL
value|0x8F
end_define

begin_define
define|#
directive|define
name|LK_LED_HOLD
value|LED_4
end_define

begin_define
define|#
directive|define
name|LK_LED_LOCK
value|LED_3
end_define

begin_define
define|#
directive|define
name|LK_LED_COMPOSE
value|LED_2
end_define

begin_define
define|#
directive|define
name|LK_LED_WAIT
value|LED_1
end_define

begin_define
define|#
directive|define
name|LK_KDOWN_ERROR
value|0x3D
end_define

begin_comment
comment|/* key down on powerup error */
end_comment

begin_define
define|#
directive|define
name|LK_POWER_ERROR
value|0x3E
end_define

begin_comment
comment|/* keyboard failure on powerup test */
end_comment

begin_define
define|#
directive|define
name|LK_OUTPUT_ERROR
value|0xB5
end_define

begin_comment
comment|/* keystrokes lost during inhibit */
end_comment

begin_define
define|#
directive|define
name|LK_INPUT_ERROR
value|0xB6
end_define

begin_comment
comment|/* garbage command to keyboard */
end_comment

begin_define
define|#
directive|define
name|LK_LOWEST
value|0x56
end_define

begin_comment
comment|/* lowest significant keycode */
end_comment

begin_define
define|#
directive|define
name|LK_DIV6_START
value|0xAD
end_define

begin_comment
comment|/* start of div 6 */
end_comment

begin_define
define|#
directive|define
name|LK_DIV5_END
value|0xB2
end_define

begin_comment
comment|/* end of div 5 */
end_comment

begin_define
define|#
directive|define
name|LAST_PARAM
value|0x80
end_define

begin_comment
comment|/* "no more params" bit */
end_comment

begin_struct
struct|struct
name|prgkbd
block|{
name|short
name|cmd
decl_stmt|;
comment|/* LK201 command opcode */
name|short
name|param1
decl_stmt|;
comment|/* 1st cmd parameter (can be null) */
name|short
name|param2
decl_stmt|;
comment|/* 2nd cmd parameter (can be null) */
block|}
struct|;
end_struct

begin_comment
comment|/*------------------------- * "special" LK-201 keys */
end_comment

begin_define
define|#
directive|define
name|SHIFT
value|174
end_define

begin_define
define|#
directive|define
name|LOCK
value|176
end_define

begin_define
define|#
directive|define
name|REPEAT
value|180
end_define

begin_define
define|#
directive|define
name|CNTRL
value|175
end_define

begin_define
define|#
directive|define
name|ALLUP
value|179
end_define

begin_comment
comment|/*-------------------------------- * cursor programming structure */
end_comment

begin_struct
struct|struct
name|prg_cursor
block|{
name|unsigned
name|short
name|acc_factor
decl_stmt|;
comment|/* cursor aceleration factor */
name|unsigned
name|short
name|threshold
decl_stmt|;
comment|/* threshold to trigger acc at */
block|}
struct|;
end_struct

begin_comment
comment|/*--------------------- * mouse definitions */
end_comment

begin_define
define|#
directive|define
name|INC_STREAM_MODE
value|'R'
end_define

begin_comment
comment|/* stream mode reports (55 hz) */
end_comment

begin_define
define|#
directive|define
name|PROMPT_MODE
value|'D'
end_define

begin_comment
comment|/* report when prompted */
end_comment

begin_define
define|#
directive|define
name|REQUEST_POS
value|'P'
end_define

begin_comment
comment|/* request position report */
end_comment

begin_define
define|#
directive|define
name|SELF_TEST
value|'T'
end_define

begin_comment
comment|/* request self test */
end_comment

begin_define
define|#
directive|define
name|MOUSE_ID
value|0x2
end_define

begin_comment
comment|/* mouse ID in lo 4 bits */
end_comment

begin_define
define|#
directive|define
name|START_FRAME
value|0x80
end_define

begin_comment
comment|/* start of report frame bit */
end_comment

begin_define
define|#
directive|define
name|X_SIGN
value|0x10
end_define

begin_comment
comment|/* position sign bits */
end_comment

begin_define
define|#
directive|define
name|Y_SIGN
value|0x08
end_define

begin_define
define|#
directive|define
name|RIGHT_BUTTON
value|0x01
end_define

begin_comment
comment|/* mouse buttons */
end_comment

begin_define
define|#
directive|define
name|MIDDLE_BUTTON
value|0x02
end_define

begin_define
define|#
directive|define
name|LEFT_BUTTON
value|0x04
end_define

begin_comment
comment|/* mouse report structure definition */
end_comment

begin_struct
struct|struct
name|mouse_report
block|{
name|char
name|state
decl_stmt|;
comment|/* buttons and sign bits */
name|short
name|dx
decl_stmt|;
comment|/* delta X since last change */
name|short
name|dy
decl_stmt|;
comment|/* delta Y since last change */
name|char
name|bytcnt
decl_stmt|;
comment|/* mouse report byte count */
block|}
struct|;
end_struct

begin_comment
comment|/*----------------------------------------- * tablet command/interface definitions  */
end_comment

begin_define
define|#
directive|define
name|T_STREAM
value|'R'
end_define

begin_comment
comment|/* continuous stream report mode */
end_comment

begin_define
define|#
directive|define
name|T_POINT
value|'D'
end_define

begin_comment
comment|/* enter report-on-request mode */
end_comment

begin_define
define|#
directive|define
name|T_REQUEST
value|'P'
end_define

begin_comment
comment|/* request position report */
end_comment

begin_define
define|#
directive|define
name|T_BAUD
value|'B'
end_define

begin_comment
comment|/* increase baud to 9600 from 4800 */
end_comment

begin_define
define|#
directive|define
name|T_RATE_55
value|'K'
end_define

begin_comment
comment|/* report rate: 55/sec */
end_comment

begin_define
define|#
directive|define
name|T_RATE_72
value|'L'
end_define

begin_comment
comment|/* report rate: 72/sec */
end_comment

begin_define
define|#
directive|define
name|T_RATE_120
value|'M'
end_define

begin_comment
comment|/* report rate: 120/sec (9600 only) */
end_comment

begin_define
define|#
directive|define
name|T_TEST
value|SELF_TEST
end_define

begin_comment
comment|/* do self test */
end_comment

begin_define
define|#
directive|define
name|TABLET_ID
value|0x4
end_define

begin_comment
comment|/* tablet ID in lo 4 bits */
end_comment

begin_define
define|#
directive|define
name|T_START_FRAME
value|0x80
end_define

begin_comment
comment|/* start of report frame bit */
end_comment

begin_define
define|#
directive|define
name|T_PROXIMITY
value|0x01
end_define

begin_comment
comment|/* state pointer in proximity */
end_comment

begin_define
define|#
directive|define
name|T_LEFT_BUTTON
value|0x02
end_define

begin_comment
comment|/* puck buttons */
end_comment

begin_define
define|#
directive|define
name|T_FRONT_BUTTON
value|0x04
end_define

begin_define
define|#
directive|define
name|T_RIGHT_BUTTON
value|0x08
end_define

begin_define
define|#
directive|define
name|T_BACK_BUTTON
value|0x10
end_define

begin_define
define|#
directive|define
name|T_BARREL_BUTTON
value|T_LEFT_BUTTON
end_define

begin_comment
comment|/* stylus buttons */
end_comment

begin_define
define|#
directive|define
name|T_TIP_BUTTON
value|T_FRONT_BUTTON
end_define

end_unit

