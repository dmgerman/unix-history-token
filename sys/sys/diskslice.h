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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* switch table for slice handlers (sample only) */
end_comment

begin_decl_stmt
name|struct
name|slice_switch
argument_list|(
name|int
argument_list|(
operator|*
name|slice_load
argument_list|)
argument_list|()
argument_list|;
name|int
argument_list|(
argument|*slice_check(); 	int	(*slice_gone)();
comment|/* 	 * etc. 	 * each  routine is called with the address of the private data 	 * and the minor number.. 	 * Other arguments as needed 	 */
argument|};  struct	diskslice { 	u_long	ds_offset;
comment|/* starting sector */
argument|u_long	ds_size;
comment|/* number of sectors */
argument|int	ds_type;
comment|/* (foreign) slice type */
argument|struct dkbad_intern *ds_bad;
comment|/* bad sector table, if any */
argument|void	*ds_date;
comment|/* Slice type specific data */
argument|struct slice_switch *switch;
comment|/* switch table for type handler */
argument|u_char	ds_bopenmask;
comment|/* bdevs open */
argument|u_char	ds_copenmask;
comment|/* cdevs open */
argument|u_char	ds_openmask;
comment|/* [bc]devs open */
argument|u_char	ds_wlabel;
comment|/* nonzero if label is writable */
argument|};
endif|#
directive|endif
argument|struct diskslices { 	int	dss_first_bsd_slice;
comment|/* COMPATIBILTY_SLICE is mapped here */
argument|u_int	dss_nslices;
comment|/* actual dimension of dss_slices[] */
argument|struct diskslice 		dss_slices[MAX_SLICES];
comment|/* actually usually less */
argument|};
ifdef|#
directive|ifdef
name|KERNEL
include|#
directive|include
file|<sys/conf.h>
define|#
directive|define
name|dsgetbad
parameter_list|(
name|dev
parameter_list|,
name|ssp
parameter_list|)
value|(ssp->dss_slices[dkslice(dev)].ds_bad)
define|#
directive|define
name|dsgetlabel
parameter_list|(
name|dev
parameter_list|,
name|ssp
parameter_list|)
value|(ssp->dss_slices[dkslice(dev)].ds_label)
argument|struct buf; struct disklabel;  typedef int ds_setgeom_t __P((struct disklabel *lp));  int	dscheck __P((struct buf *bp, struct diskslices *ssp)); void	dsclose __P((dev_t dev, int mode, struct diskslices *ssp)); void	dsgone __P((struct diskslices **sspp)); int	dsinit __P((char *dname, dev_t dev, d_strategy_t *strat, 		    struct disklabel *lp, struct diskslices **sspp)); int	dsioctl __P((char *dname, dev_t dev, int cmd, caddr_t data, int flags, 		     struct diskslices **sspp, d_strategy_t *strat, 		     ds_setgeom_t *setgeom)); int	dsisopen __P((struct diskslices *ssp)); char	*dsname __P((char *dname, int unit, int slice, int part, 		     char *partname)); int	dsopen __P((char *dname, dev_t dev, int mode, struct diskslices **sspp, 		    struct disklabel *lp, d_strategy_t *strat, 		    ds_setgeom_t *setgeom)); int	dssize __P((dev_t dev, struct diskslices **sspp, d_open_t dopen, 		    d_close_t dclose));
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

