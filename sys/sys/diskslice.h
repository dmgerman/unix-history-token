begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Bruce D. Evans.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id:  */
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
value|0
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
name|struct
name|dkbad_intern
modifier|*
name|ds_bad
decl_stmt|;
comment|/* bad sector table, if any */
name|struct
name|disklabel
modifier|*
name|ds_label
decl_stmt|;
comment|/* BSD label, if any */
name|u_char
name|ds_bopenmask
decl_stmt|;
comment|/* bdevs open */
name|u_char
name|ds_copenmask
decl_stmt|;
comment|/* cdevs open */
name|u_char
name|ds_openmask
decl_stmt|;
comment|/* [bc]devs open */
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
name|u_int
name|dss_nslices
decl_stmt|;
comment|/* actual dimension of dss_slices[] */
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
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_define
define|#
directive|define
name|dsgetbad
parameter_list|(
name|dev
parameter_list|,
name|ssp
parameter_list|)
value|(ssp->dss_slices[dkslice(dev)].ds_bad)
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
name|buf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|disklabel
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|ds_setgeom_t
name|__P
typedef|((struct
name|disklabel
modifier|*
name|lp
typedef|));
end_typedef

begin_decl_stmt
name|int
name|dscheck
name|__P
argument_list|(
operator|(
expr|struct
name|buf
operator|*
name|bp
operator|,
expr|struct
name|diskslices
operator|*
name|ssp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dsclose
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|int
name|mode
operator|,
expr|struct
name|diskslices
operator|*
name|ssp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dsinit
name|__P
argument_list|(
operator|(
name|char
operator|*
name|dname
operator|,
name|dev_t
name|dev
operator|,
name|d_strategy_t
operator|*
name|strat
operator|,
expr|struct
name|disklabel
operator|*
name|lp
operator|,
expr|struct
name|diskslices
operator|*
operator|*
name|sspp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dsioctl
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
name|int
name|cmd
operator|,
name|caddr_t
name|data
operator|,
name|int
name|flags
operator|,
expr|struct
name|diskslices
operator|*
name|ssp
operator|,
name|d_strategy_t
operator|*
name|strat
operator|,
name|ds_setgeom_t
operator|*
name|setgeom
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dsopen
name|__P
argument_list|(
operator|(
name|char
operator|*
name|dname
operator|,
name|dev_t
name|dev
operator|,
name|int
name|mode
operator|,
expr|struct
name|diskslices
operator|*
operator|*
name|sspp
operator|,
expr|struct
name|disklabel
operator|*
name|lp
operator|,
name|d_strategy_t
operator|*
name|strat
operator|,
name|ds_setgeom_t
operator|*
name|setgeom
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dswlabel
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
expr|struct
name|diskslices
operator|*
name|ssp
operator|,
name|int
name|wlabel
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DISKSLICE_H_ */
end_comment

end_unit

