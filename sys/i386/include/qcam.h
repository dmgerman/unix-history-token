begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Connectix QuickCam parallel-port camera video capture driver.  * Copyright (c) 1996, Paul Traina.  *  * This driver is based in part on work  * Copyright (c) 1996, Thomas Davis.  *  * QuickCam(TM) is a registered trademark of Connectix Inc.  * Use this driver at your own risk, it is not warranted by  * Connectix or the authors.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * NOTE: this file contains the sole public interface between the driver  * and user applications.  Every effort should be made to retain comaptibility  * with the decided upon standard interface shared between Linux and  * FreeBSD.  Currently, FreeBSD uses a different (richer) interface than  * the Linux.  *  * WARNING WARNING: The contents of this structure is in flux,  *		    recompile often, the driver will change the version  *		    number when the interface changes for now...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QUICKCAM_H
end_ifndef

begin_define
define|#
directive|define
name|_QUICKCAM_H
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_IOR
end_ifndef

begin_comment
comment|/* SCO doesn't have _IOR/_IOW for ioctls, so fake it out to keep things clean*/
end_comment

begin_define
define|#
directive|define
name|_IOR
parameter_list|(
name|cat
parameter_list|,
name|func
parameter_list|,
name|data
parameter_list|)
value|(((cat)<< 8) | (func))
end_define

begin_define
define|#
directive|define
name|_IOW
parameter_list|(
name|cat
parameter_list|,
name|func
parameter_list|,
name|data
parameter_list|)
value|(((cat)<< 8) | (func))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ioctls  */
end_comment

begin_define
define|#
directive|define
name|QC_GET
value|_IOR('S', 1, struct qcam)
end_define

begin_comment
comment|/* get parameter structure */
end_comment

begin_define
define|#
directive|define
name|QC_SET
value|_IOW('S', 2, struct qcam)
end_define

begin_comment
comment|/* set parameter structure */
end_comment

begin_define
define|#
directive|define
name|QC_IOCTL_VERSION
value|3
end_define

begin_comment
comment|/* version of the structure */
end_comment

begin_struct
struct|struct
name|qcam
block|{
name|int
name|qc_version
decl_stmt|;
comment|/* version of qcam structure */
name|int
name|qc_xsize
decl_stmt|;
comment|/* size in pixels */
name|int
name|qc_ysize
decl_stmt|;
comment|/* size in pixels */
name|int
name|qc_xorigin
decl_stmt|;
comment|/* x origin */
name|int
name|qc_yorigin
decl_stmt|;
comment|/* y origin */
name|int
name|qc_bpp
decl_stmt|;
comment|/* bits per pixel (4 or 6) */
name|int
name|qc_zoom
decl_stmt|;
comment|/* zoom mode */
name|int
name|qc_exposure
decl_stmt|;
comment|/* length of exposure */
name|u_char
name|qc_brightness
decl_stmt|;
comment|/* 0..255 */
name|u_char
name|qc_whitebalance
decl_stmt|;
comment|/* 0..255 */
name|u_char
name|qc_contrast
decl_stmt|;
comment|/* 0..255 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|QC_MAX_XSIZE
value|320
end_define

begin_comment
comment|/* pixels */
end_comment

begin_define
define|#
directive|define
name|QC_MAX_YSIZE
value|240
end_define

begin_comment
comment|/* pixels */
end_comment

begin_comment
comment|/*  * zoom flags  */
end_comment

begin_define
define|#
directive|define
name|QC_ZOOM_100
value|0x00
end_define

begin_comment
comment|/* no zoom */
end_comment

begin_define
define|#
directive|define
name|QC_ZOOM_150
value|0x01
end_define

begin_comment
comment|/* 1.5x */
end_comment

begin_define
define|#
directive|define
name|QC_ZOOM_200
value|0x02
end_define

begin_comment
comment|/* 2.0x */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

