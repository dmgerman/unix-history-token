begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Connectix QuickCam parallel-port camera video capture driver.  * Copyright (c) 1996, Paul Traina.  *  * This driver is based in part on work  * Copyright (c) 1996, Thomas Davis.  *  * QuickCam(TM) is a registered trademark of Connectix Inc.  * Use this driver at your own risk, it is not warranted by  * Connectix or the authors.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * The following information is hardware dependant.  It should not be used  * by user applications, see machine/qcam.h for the applications interface.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QCAMREG_H
end_ifndef

begin_define
define|#
directive|define
name|_QCAMREG_H
end_define

begin_comment
comment|/*  * Camera autodetection parameters  */
end_comment

begin_define
define|#
directive|define
name|QC_PROBELIMIT
value|30
end_define

begin_comment
comment|/* number of times to probe */
end_comment

begin_define
define|#
directive|define
name|QC_PROBECNTLOW
value|5
end_define

begin_comment
comment|/* minimum transitions */
end_comment

begin_define
define|#
directive|define
name|QC_PROBECNTHI
value|25
end_define

begin_comment
comment|/* maximum transitions */
end_comment

begin_comment
comment|/*  * QuickCam camera commands  */
end_comment

begin_define
define|#
directive|define
name|QC_BRIGHTNESS
value|0x0b
end_define

begin_define
define|#
directive|define
name|QC_CONTRAST
value|0x19
end_define

begin_define
define|#
directive|define
name|QC_WHITEBALANCE
value|0x1f
end_define

begin_define
define|#
directive|define
name|QC_XFERMODE
value|0x07
end_define

begin_define
define|#
directive|define
name|QC_XSIZE
value|0x13
end_define

begin_define
define|#
directive|define
name|QC_YSIZE
value|0x11
end_define

begin_define
define|#
directive|define
name|QC_YORG
value|0x0d
end_define

begin_define
define|#
directive|define
name|QC_XORG
value|0x0f
end_define

begin_comment
comment|/*  * XFERmode register flags  */
end_comment

begin_define
define|#
directive|define
name|QC_XFER_BIDIR
value|0x01
end_define

begin_comment
comment|/* bidirectional transfer */
end_comment

begin_define
define|#
directive|define
name|QC_XFER_6BPP
value|0x02
end_define

begin_comment
comment|/* 6 bits per pixel */
end_comment

begin_define
define|#
directive|define
name|QC_XFER_WIDE
value|0x00
end_define

begin_comment
comment|/* wide angle */
end_comment

begin_define
define|#
directive|define
name|QC_XFER_NARROW
value|0x04
end_define

begin_comment
comment|/* narrow */
end_comment

begin_define
define|#
directive|define
name|QC_XFER_TIGHT
value|0x08
end_define

begin_comment
comment|/* very narrow */
end_comment

begin_comment
comment|/*  * QuickCam default values (don't depend on these staying the same)  */
end_comment

begin_define
define|#
directive|define
name|QC_DEF_XSIZE
value|160
end_define

begin_define
define|#
directive|define
name|QC_DEF_YSIZE
value|120
end_define

begin_define
define|#
directive|define
name|QC_DEF_XORG
value|7
end_define

begin_define
define|#
directive|define
name|QC_DEF_YORG
value|1
end_define

begin_define
define|#
directive|define
name|QC_DEF_BPP
value|6
end_define

begin_define
define|#
directive|define
name|QC_DEF_CONTRAST
value|180
end_define

begin_define
define|#
directive|define
name|QC_DEF_BRIGHTNESS
value|180
end_define

begin_define
define|#
directive|define
name|QC_DEF_WHITEBALANCE
value|150
end_define

begin_define
define|#
directive|define
name|QC_DEF_ZOOM
value|QC_ZOOM_100
end_define

begin_comment
comment|/*  * QuickCam parallel port handshake constants  */
end_comment

begin_define
define|#
directive|define
name|QC_CTL_HIGHNIB
value|0x06
end_define

begin_define
define|#
directive|define
name|QC_CTL_LOWNIB
value|0x0e
end_define

begin_define
define|#
directive|define
name|QC_CTL_HIGHWORD
value|0x26
end_define

begin_define
define|#
directive|define
name|QC_CTL_LOWWORD
value|0x2f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _QCAMREG_H */
end_comment

end_unit

