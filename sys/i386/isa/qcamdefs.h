begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Connectix QuickCam parallel-port camera video capture driver.  * Copyright (c) 1996, Paul Traina.  *  * This driver is based in part on work  * Copyright (c) 1996, Thomas Davis.  *  * QuickCam(TM) is a registered trademark of Connectix Inc.  * Use this driver at your own risk, it is not warranted by  * Connectix or the authors.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * The information in this file is private and shared between various  * parts of the QuickCam(TM) driver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QCAM_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|_QCAM_DEFS_H
value|1
end_define

begin_decl_stmt
specifier|extern
name|int
name|qcam_debug
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|qcam_softc
block|{
if|#
directive|if
name|defined
argument_list|(
name|bsdi
argument_list|)
operator|&&
name|defined
argument_list|(
name|KERNEL
argument_list|)
comment|/* must be first in structure */
name|struct
name|device
name|sc_dev
decl_stmt|;
comment|/* kernel configuration */
endif|#
directive|endif
comment|/* bsdi KERNEL */
name|u_char
modifier|*
name|buffer
decl_stmt|;
comment|/* frame buffer */
name|u_char
modifier|*
name|buffer_end
decl_stmt|;
comment|/* end of frame buffer */
name|u_int
name|flags
decl_stmt|;
name|u_int
name|iobase
decl_stmt|;
name|int
name|unit
decl_stmt|;
comment|/* device */
name|void
function_decl|(
modifier|*
name|scanner
function_decl|)
parameter_list|(
name|struct
name|qcam_softc
modifier|*
parameter_list|)
function_decl|;
name|int
name|init_req
decl_stmt|;
comment|/* initialization required */
name|int
name|x_size
decl_stmt|;
comment|/* pixels */
name|int
name|y_size
decl_stmt|;
comment|/* pixels */
name|int
name|x_origin
decl_stmt|;
comment|/* ?? units */
name|int
name|y_origin
decl_stmt|;
comment|/* ?? units */
name|int
name|zoom
decl_stmt|;
comment|/* 0=none, 1=1.5x, 2=2x */
name|int
name|bpp
decl_stmt|;
comment|/* 4 or 6 */
name|int
name|exposure
decl_stmt|;
comment|/* time to open shutter */
name|u_char
name|xferparms
decl_stmt|;
comment|/* calcualted transfer params */
name|u_char
name|contrast
decl_stmt|;
name|u_char
name|brightness
decl_stmt|;
name|u_char
name|whitebalance
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|defined
argument_list|(
name|KERNEL
argument_list|)
ifdef|#
directive|ifdef
name|DEVFS
name|void
modifier|*
name|devfs_token
decl_stmt|;
comment|/* device filesystem handle */
endif|#
directive|endif
comment|/* DEVFS */
endif|#
directive|endif
comment|/* __FreeBSD__ KERNEL */
block|}
struct|;
end_struct

begin_comment
comment|/* flags in softc */
end_comment

begin_define
define|#
directive|define
name|QC_OPEN
value|0x01
end_define

begin_comment
comment|/* device open */
end_comment

begin_define
define|#
directive|define
name|QC_ALIVE
value|0x02
end_define

begin_comment
comment|/* probed and attached */
end_comment

begin_define
define|#
directive|define
name|QC_BIDIR_HW
value|0x04
end_define

begin_comment
comment|/* bidir parallel port */
end_comment

begin_define
define|#
directive|define
name|QC_FORCEUNI
value|0x08
end_define

begin_comment
comment|/* ...but force unidir mode */
end_comment

begin_define
define|#
directive|define
name|QC_MAXFRAMEBUFSIZE
value|(QC_MAX_XSIZE*QC_MAX_YSIZE)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_comment
comment|/* Linux is backwards from *BSD */
end_comment

begin_define
define|#
directive|define
name|read_data
parameter_list|(
name|P
parameter_list|)
value|inb((P))
end_define

begin_define
define|#
directive|define
name|read_data_word
parameter_list|(
name|P
parameter_list|)
value|inw((P))
end_define

begin_define
define|#
directive|define
name|read_status
parameter_list|(
name|P
parameter_list|)
value|inb((P)+1)
end_define

begin_define
define|#
directive|define
name|write_data
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|outb((V), (P)+0)
end_define

begin_define
define|#
directive|define
name|write_status
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|outb((V), (P)+1)
end_define

begin_define
define|#
directive|define
name|write_control
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|outb((V), (P)+2)
end_define

begin_define
define|#
directive|define
name|LONGDELAY
parameter_list|(
name|n
parameter_list|)
value|tsleep((n)/1000)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FreeBSD/NetBSD/BSDI */
end_comment

begin_define
define|#
directive|define
name|read_data
parameter_list|(
name|P
parameter_list|)
value|inb((P))
end_define

begin_define
define|#
directive|define
name|read_data_word
parameter_list|(
name|P
parameter_list|)
value|inw((P))
end_define

begin_define
define|#
directive|define
name|read_status
parameter_list|(
name|P
parameter_list|)
value|inb((P)+1)
end_define

begin_define
define|#
directive|define
name|write_data
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|outb((P)+0, (V))
end_define

begin_define
define|#
directive|define
name|write_status
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|outb((P)+1, (V))
end_define

begin_define
define|#
directive|define
name|write_control
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|outb((P)+2, (V))
end_define

begin_define
define|#
directive|define
name|LONGDELAY
parameter_list|(
name|n
parameter_list|)
value|DELAY(n)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|n
parameter_list|)
value|usleep(n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|QC_TIMEOUT_INIT
value|60000
end_define

begin_comment
comment|/* timeout for first 						   read of scan */
end_comment

begin_define
define|#
directive|define
name|QC_TIMEOUT_CMD
value|5000
end_define

begin_comment
comment|/* timeout for control cmds */
end_comment

begin_define
define|#
directive|define
name|QC_TIMEOUT
value|400
end_define

begin_comment
comment|/* timeout on scan reads */
end_comment

begin_comment
comment|/* This value could be OS 						   dependant */
end_comment

begin_define
define|#
directive|define
name|QC_DEF_EXPOSURE
value|200
end_define

begin_comment
comment|/* default exposure */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|qcam_detect
name|__P
argument_list|(
operator|(
name|u_int
name|port
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|qcam_reset
name|__P
argument_list|(
operator|(
expr|struct
name|qcam_softc
operator|*
name|qs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|qcam_scan
name|__P
argument_list|(
operator|(
expr|struct
name|qcam_softc
operator|*
name|qs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|qcam_default
name|__P
argument_list|(
operator|(
expr|struct
name|qcam_softc
operator|*
name|qs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|qcam_ioctl_get
name|__P
argument_list|(
operator|(
expr|struct
name|qcam_softc
operator|*
name|qs
operator|,
expr|struct
name|qcam
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|qcam_ioctl_set
name|__P
argument_list|(
operator|(
expr|struct
name|qcam_softc
operator|*
name|qs
operator|,
expr|struct
name|qcam
operator|*
name|info
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _QCAM_DEFS_H */
end_comment

end_unit

