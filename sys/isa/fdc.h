begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from:	@(#)fd.c	7.4 (Berkeley) 5/25/91  * $FreeBSD$  *  */
end_comment

begin_enum
enum|enum
name|fdc_type
block|{
name|FDC_NE765
block|,
name|FDC_I82077
block|,
name|FDC_NE72065
block|,
name|FDC_UNKNOWN
init|=
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/***********************************************************************\ * Per controller structure.						* \***********************************************************************/
end_comment

begin_struct
struct|struct
name|fdc_data
block|{
name|int
name|fdcu
decl_stmt|;
comment|/* our unit number */
name|int
name|dmachan
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|FDC_ATTACHED
value|0x01
define|#
directive|define
name|FDC_STAT_VALID
value|0x08
define|#
directive|define
name|FDC_HAS_FIFO
value|0x10
define|#
directive|define
name|FDC_NEEDS_RESET
value|0x20
define|#
directive|define
name|FDC_NODMA
value|0x40
define|#
directive|define
name|FDC_ISPNP
value|0x80
define|#
directive|define
name|FDC_ISPCMCIA
value|0x100
name|struct
name|fd_data
modifier|*
name|fd
decl_stmt|;
name|int
name|fdu
decl_stmt|;
comment|/* the active drive	*/
name|int
name|state
decl_stmt|;
name|int
name|retry
decl_stmt|;
ifndef|#
directive|ifndef
name|PC98
name|int
name|fdout
decl_stmt|;
comment|/* mirror of the w/o digital output reg */
endif|#
directive|endif
name|u_int
name|status
index|[
literal|7
index|]
decl_stmt|;
comment|/* copy of the registers */
name|enum
name|fdc_type
name|fdct
decl_stmt|;
comment|/* chip version of FDC */
name|int
name|fdc_errs
decl_stmt|;
comment|/* number of logged errors */
name|struct
name|buf_queue_head
name|head
decl_stmt|;
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
comment|/* active buffer */
name|int
name|dma_overruns
decl_stmt|;
comment|/* number of DMA overruns */
ifdef|#
directive|ifdef
name|PC98
name|struct
name|resource
modifier|*
name|res_ioport
decl_stmt|,
modifier|*
name|res_fdsio
decl_stmt|,
modifier|*
name|res_fdemsio
decl_stmt|;
name|struct
name|resource
modifier|*
name|res_irq
decl_stmt|,
modifier|*
name|res_drq
decl_stmt|;
name|int
name|rid_ioport
decl_stmt|,
name|rid_irq
decl_stmt|,
name|rid_drq
decl_stmt|;
else|#
directive|else
name|struct
name|resource
modifier|*
name|res_ioport
decl_stmt|,
modifier|*
name|res_ctl
decl_stmt|,
modifier|*
name|res_irq
decl_stmt|,
modifier|*
name|res_drq
decl_stmt|;
name|int
name|rid_ioport
decl_stmt|,
name|rid_ctl
decl_stmt|,
name|rid_irq
decl_stmt|,
name|rid_drq
decl_stmt|;
endif|#
directive|endif
name|int
name|port_off
decl_stmt|;
name|bus_space_tag_t
name|portt
decl_stmt|;
name|bus_space_handle_t
name|porth
decl_stmt|;
ifdef|#
directive|ifdef
name|PC98
name|bus_space_tag_t
name|sc_fdsiot
decl_stmt|;
name|bus_space_handle_t
name|sc_fdsioh
decl_stmt|;
name|bus_space_tag_t
name|sc_fdemsiot
decl_stmt|;
name|bus_space_handle_t
name|sc_fdemsioh
decl_stmt|;
else|#
directive|else
name|bus_space_tag_t
name|ctlt
decl_stmt|;
name|bus_space_handle_t
name|ctlh
decl_stmt|;
endif|#
directive|endif
name|void
modifier|*
name|fdc_intr
decl_stmt|;
name|struct
name|device
modifier|*
name|fdc_dev
decl_stmt|;
ifndef|#
directive|ifndef
name|PC98
name|void
function_decl|(
modifier|*
name|fdctl_wr
function_decl|)
parameter_list|(
name|struct
name|fdc_data
modifier|*
name|fdc
parameter_list|,
name|u_int8_t
name|v
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/***********************************************************************\ * Throughout this file the following conventions will be used:		* * fd is a pointer to the fd_data struct for the drive in question	* * fdc is a pointer to the fdc_data struct for the controller		* * fdu is the floppy drive unit number					* * fdcu is the floppy controller unit number				* * fdsu is the floppy drive unit number on that controller. (sub-unit)	* \***********************************************************************/
end_comment

begin_typedef
typedef|typedef
name|int
name|fdu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|fdcu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|fdsu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fd_data
modifier|*
name|fd_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|fdc_data
modifier|*
name|fdc_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|fdc_type
name|fdc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FDUNIT
parameter_list|(
name|s
parameter_list|)
value|(((s)>> 6)& 3)
end_define

begin_define
define|#
directive|define
name|FDTYPE
parameter_list|(
name|s
parameter_list|)
value|((s)& 0x3f)
end_define

begin_comment
comment|/*  * fdc maintains a set (1!) of ivars per child of each controller.  */
end_comment

begin_enum
enum|enum
name|fdc_device_ivars
block|{
name|FDC_IVAR_FDUNIT
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Simple access macros for the ivars.  */
end_comment

begin_define
define|#
directive|define
name|FDC_ACCESSOR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|T
parameter_list|)
define|\
value|static __inline T fdc_get_ ## A(device_t dev)				\ {									\ 	uintptr_t v;							\ 	BUS_READ_IVAR(device_get_parent(dev), dev, FDC_IVAR_ ## B,&v);	\ 	return (T) v;							\ }
end_define

begin_macro
name|FDC_ACCESSOR
argument_list|(
argument|fdunit
argument_list|,
argument|FDUNIT
argument_list|,
argument|int
argument_list|)
end_macro

end_unit

