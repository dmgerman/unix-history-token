begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Bruce D. Evans.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DISKSLICE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DISKSLICE_H_
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

begin_define
define|#
directive|define
name|BASE_SLICE
value|2
end_define

begin_define
define|#
directive|define
name|COMPATIBILITY_SLICE
value|0
end_define

begin_define
define|#
directive|define
name|DIOCGSLICEINFO
value|_IOR('d', 111, struct diskslices)
end_define

begin_define
define|#
directive|define
name|DIOCSYNCSLICEINFO
value|_IOW('d', 112, int)
end_define

begin_define
define|#
directive|define
name|MAX_SLICES
value|32
end_define

begin_define
define|#
directive|define
name|WHOLE_DISK_SLICE
value|1
end_define

begin_struct
struct|struct
name|diskslice
block|{
name|u_long
name|ds_offset
decl_stmt|;
comment|/* starting sector */
name|u_long
name|ds_size
decl_stmt|;
comment|/* number of sectors */
name|int
name|ds_type
decl_stmt|;
comment|/* (foreign) slice type */
ifdef|#
directive|ifdef
name|PC98
name|int
name|ds_subtype
decl_stmt|;
comment|/* sub slice type */
name|u_char
name|ds_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* slice name */
endif|#
directive|endif
name|struct
name|disklabel
modifier|*
name|ds_label
decl_stmt|;
comment|/* BSD label, if any */
name|u_char
name|ds_openmask
decl_stmt|;
comment|/* devs open */
name|u_char
name|ds_wlabel
decl_stmt|;
comment|/* nonzero if label is writable */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|diskslices
block|{
name|struct
name|cdevsw
modifier|*
name|dss_cdevsw
decl_stmt|;
comment|/* for containing device */
name|int
name|dss_first_bsd_slice
decl_stmt|;
comment|/* COMPATIBILITY_SLICE is mapped here */
name|u_int
name|dss_nslices
decl_stmt|;
comment|/* actual dimension of dss_slices[] */
name|u_int
name|dss_oflags
decl_stmt|;
comment|/* copy of flags for "first" open */
name|int
name|dss_secmult
decl_stmt|;
comment|/* block to sector multiplier */
name|int
name|dss_secshift
decl_stmt|;
comment|/* block to sector shift (or -1) */
name|int
name|dss_secsize
decl_stmt|;
comment|/* sector size */
name|struct
name|diskslice
name|dss_slices
index|[
name|MAX_SLICES
index|]
decl_stmt|;
comment|/* actually usually less */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Flags for dsopen(). */
end_comment

begin_define
define|#
directive|define
name|DSO_NOLABELS
value|1
end_define

begin_define
define|#
directive|define
name|DSO_ONESLICE
value|2
end_define

begin_define
define|#
directive|define
name|DSO_COMPATLABEL
value|4
end_define

begin_define
define|#
directive|define
name|dsgetlabel
parameter_list|(
name|dev
parameter_list|,
name|ssp
parameter_list|)
value|(ssp->dss_slices[dkslice(dev)].ds_label)
end_define

begin_struct_decl
struct_decl|struct
name|bio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|disklabel
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|dscheck
parameter_list|(
name|struct
name|bio
modifier|*
name|bp
parameter_list|,
name|struct
name|diskslices
modifier|*
name|ssp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dsclose
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|diskslices
modifier|*
name|ssp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dsgone
parameter_list|(
name|struct
name|diskslices
modifier|*
modifier|*
name|sspp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dsinit
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|disklabel
modifier|*
name|lp
parameter_list|,
name|struct
name|diskslices
modifier|*
modifier|*
name|sspp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dsioctl
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|diskslices
modifier|*
modifier|*
name|sspp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dsisopen
parameter_list|(
name|struct
name|diskslices
modifier|*
name|ssp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|diskslices
modifier|*
name|dsmakeslicestruct
parameter_list|(
name|int
name|nslices
parameter_list|,
name|struct
name|disklabel
modifier|*
name|lp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|dsname
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|unit
parameter_list|,
name|int
name|slice
parameter_list|,
name|int
name|part
parameter_list|,
name|char
modifier|*
name|partname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dsopen
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|mode
parameter_list|,
name|u_int
name|flags
parameter_list|,
name|struct
name|diskslices
modifier|*
modifier|*
name|sspp
parameter_list|,
name|struct
name|disklabel
modifier|*
name|lp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dssize
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|diskslices
modifier|*
modifier|*
name|sspp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DISKSLICE_H_ */
end_comment

end_unit

