begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1996 by Thomas Davis  * Copyright (C) 1996 by Scott Laird  *  * Permission is hereby granted, free of charge, to any person obtaining  * a copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sublicense, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *  * The above copyright notice and this permission notice shall be  * included in all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  * IN NO EVENT SHALL SCOTT LAIRD BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * NOTE: this file contains the sole public interface between the driver  * and user applications.  Every effort should be made to retain comaptibility  * with the decided upon standard interface shared between Linux and  * FreeBSD.  Currently, FreeBSD uses a different (richer) interface than  * the Linux.  *  * WARNING WARNING: The contents of this structure is in flux,  *		    recompile often, the driver will change the version  *		    number when the interface changes for now...  */
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

