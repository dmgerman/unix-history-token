begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: itereg.h 1.3 92/01/21$  *  *	@(#)itereg.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Offsets into the display ROM that is part of the first 4K of each  * display device.  */
end_comment

begin_define
define|#
directive|define
name|FONTROM
value|0x3B
end_define

begin_comment
comment|/* Offset of font information structure. */
end_comment

begin_define
define|#
directive|define
name|FONTADDR
value|0x4
end_define

begin_comment
comment|/* Offset from FONTROM to font address. */
end_comment

begin_define
define|#
directive|define
name|FONTHEIGHT
value|0x0
end_define

begin_comment
comment|/* Offset from font address to font height. */
end_comment

begin_define
define|#
directive|define
name|FONTWIDTH
value|0x2
end_define

begin_comment
comment|/* Offset from font address to font width. */
end_comment

begin_define
define|#
directive|define
name|FONTDATA
value|0xA
end_define

begin_comment
comment|/* Offset from font address to font glyphs. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|hp300
end_ifdef

begin_define
define|#
directive|define
name|FBBASE
value|((volatile u_char *)ip->fbbase)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FBBASE
value|((volatile u_long *)ip->fbbase)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

