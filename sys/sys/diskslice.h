begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Bruce D. Evans.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: diskslice.h,v 1.20 1997/02/22 09:45:06 peter Exp $  */
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
name|KERNEL
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

begin_comment
comment|/* upcoming change from julian.. early warning of probable form */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

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
name|void
modifier|*
name|ds_bdev
decl_stmt|;
comment|/* devfs token for whole slice */
name|void
modifier|*
name|ds_cdev
decl_stmt|;
comment|/* devfs token for raw whole slice */
ifdef|#
directive|ifdef
name|MAXPARTITIONS
comment|/* XXX don't depend on disklabel.h */
if|#
directive|if
name|MAXPARTITIONS
operator|!=
literal|8
comment|/* but check consistency if possible */
error|#
directive|error
literal|"inconsistent MAXPARTITIONS"
endif|#
directive|endif
else|#
directive|else
define|#
directive|define
name|MAXPARTITIONS
value|8
endif|#
directive|endif
name|void
modifier|*
name|ds_bdevs
index|[
name|MAXPARTITIONS
index|]
decl_stmt|;
comment|/* XXX s.b. in label */
name|void
modifier|*
name|ds_cdevs
index|[
name|MAXPARTITIONS
index|]
decl_stmt|;
comment|/* XXX s.b. in label */
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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* switch table for slice handlers (sample only) */
end_comment

begin_struct
struct|struct
name|slice_switch
block|{
name|int
function_decl|(
modifier|*
name|slice_load
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|slice_check
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|slice_gone
function_decl|)
parameter_list|()
function_decl|;
comment|/* 	 * etc. 	 * each  routine is called with the address of the private data 	 * and the minor number.. 	 * Other arguments as needed 	 */
block|}
struct|;
end_struct

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
name|dkbad_intern
modifier|*
name|ds_bad
decl_stmt|;
comment|/* bad sector table, if any */
name|void
modifier|*
name|ds_date
decl_stmt|;
comment|/* Slice type specific data */
block|struct
name|slice_switch
operator|*
switch|switch
empty_stmt|;
comment|/* switch table for type handler */
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

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|diskslices
block|{
name|struct
name|bdevsw
modifier|*
name|dss_bdevsw
decl_stmt|;
comment|/* for containing device */
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
name|void
name|dsgone
name|__P
argument_list|(
operator|(
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
name|void
argument_list|(
operator|*
name|strat
argument_list|)
argument_list|(
expr|struct
name|buf
operator|*
name|bp
argument_list|)
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
name|char
operator|*
name|dname
operator|,
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
operator|*
name|sspp
operator|,
name|void
argument_list|(
operator|*
name|strat
argument_list|)
argument_list|(
expr|struct
name|buf
operator|*
name|bp
argument_list|)
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
name|dsisopen
name|__P
argument_list|(
operator|(
expr|struct
name|diskslices
operator|*
name|ssp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|dsname
name|__P
argument_list|(
operator|(
name|char
operator|*
name|dname
operator|,
name|int
name|unit
operator|,
name|int
name|slice
operator|,
name|int
name|part
operator|,
name|char
operator|*
name|partname
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
name|void
argument_list|(
operator|*
name|strat
argument_list|)
argument_list|(
expr|struct
name|buf
operator|*
name|bp
argument_list|)
operator|,
name|ds_setgeom_t
operator|*
name|setgeom
operator|,
expr|struct
name|bdevsw
operator|*
name|bdevsw
operator|,
expr|struct
name|cdevsw
operator|*
name|cdevsw
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dssize
name|__P
argument_list|(
operator|(
name|dev_t
name|dev
operator|,
expr|struct
name|diskslices
operator|*
operator|*
name|sspp
operator|,
name|int
argument_list|(
argument|*dopen
argument_list|)
operator|(
name|dev_t
name|dev
operator|,
name|int
name|oflags
operator|,
name|int
name|devtype
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
operator|,
name|int
argument_list|(
argument|*dclose
argument_list|)
operator|(
name|dev_t
name|dev
operator|,
name|int
name|fflag
operator|,
name|int
name|devtype
operator|,
expr|struct
name|proc
operator|*
name|p
operator|)
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

