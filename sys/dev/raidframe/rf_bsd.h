begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_netbsd.h,v 1.12 2000/05/28 22:53:49 oster Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996, 1997, 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Greg Oster; Jason R. Thorpe.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_BSD_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_BSD_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/namei.h>
end_include

begin_include
include|#
directive|include
file|<sys/vnode.h>
end_include

begin_include
include|#
directive|include
file|"opt_raid.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RAID_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|rf_printf
parameter_list|(
name|lvl
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {							\ 		if (lvl<= RAID_DEBUG) printf(fmt, ##args);	\ 	} while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* DEBUG */
end_comment

begin_define
define|#
directive|define
name|rf_printf
parameter_list|(
name|lvl
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|{ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_comment
comment|/* The per-component label information that the user can set */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|RF_ComponentInfo_s
block|{
name|int
name|row
decl_stmt|;
comment|/* the row number of this component */
name|int
name|column
decl_stmt|;
comment|/* the column number of this component */
name|int
name|serial_number
decl_stmt|;
comment|/* a user-specified serial number for this 				 RAID set */
block|}
name|RF_ComponentInfo_t
typedef|;
end_typedef

begin_comment
comment|/* The per-component label information */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|RF_ComponentLabel_s
block|{
name|int
name|version
decl_stmt|;
comment|/* The version of this label. */
name|int
name|serial_number
decl_stmt|;
comment|/* a user-specified serial number for this 				 RAID set */
name|int
name|mod_counter
decl_stmt|;
comment|/* modification counter.  Changed (usually 				 by incrementing) every time the label  				 is changed */
name|int
name|row
decl_stmt|;
comment|/* the row number of this component */
name|int
name|column
decl_stmt|;
comment|/* the column number of this component */
name|int
name|num_rows
decl_stmt|;
comment|/* number of rows in this RAID set */
name|int
name|num_columns
decl_stmt|;
comment|/* number of columns in this RAID set */
name|int
name|clean
decl_stmt|;
comment|/* 1 when clean, 0 when dirty */
name|int
name|status
decl_stmt|;
comment|/* rf_ds_optimal, rf_ds_dist_spared, whatever. */
comment|/* stuff that will be in version 2 of the label */
name|int
name|sectPerSU
decl_stmt|;
comment|/* Sectors per Stripe Unit */
name|int
name|SUsPerPU
decl_stmt|;
comment|/* Stripe Units per Parity Units */
name|int
name|SUsPerRU
decl_stmt|;
comment|/* Stripe Units per Reconstruction Units */
name|int
name|parityConfig
decl_stmt|;
comment|/* '0' == RAID0, '1' == RAID1, etc. */
name|int
name|maxOutstanding
decl_stmt|;
comment|/* maxOutstanding disk requests */
name|int
name|blockSize
decl_stmt|;
comment|/* size of component block.  				 (disklabel->d_secsize) */
name|int
name|numBlocks
decl_stmt|;
comment|/* number of blocks on this component.  May 			         be smaller than the partition size. */
name|int
name|partitionSize
decl_stmt|;
comment|/* number of blocks on this *partition*.  				 Must exactly match the partition size 				 from the disklabel. */
name|int
name|future_use
index|[
literal|33
index|]
decl_stmt|;
comment|/* Future expansion */
name|int
name|autoconfigure
decl_stmt|;
comment|/* automatically configure this RAID set.  				 0 == no, 1 == yes */
name|int
name|root_partition
decl_stmt|;
comment|/* Use this set as / 				 0 == no, 1 == yes*/
name|int
name|last_unit
decl_stmt|;
comment|/* last unit number (e.g. 0 for /dev/raid0)  				 of this component.  Used for autoconfigure 				 only. */
name|int
name|config_order
decl_stmt|;
comment|/* 0 .. n.  The order in which the component 				 should be auto-configured.  E.g. 0 is will  				 done first, (and would become raid0). 				 This may be in conflict with last_unit!!?! */
comment|/* Not currently used. */
name|int
name|future_use2
index|[
literal|44
index|]
decl_stmt|;
comment|/* More future expansion */
block|}
name|RF_ComponentLabel_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|RF_SingleComponent_s
block|{
name|int
name|row
decl_stmt|;
name|int
name|column
decl_stmt|;
name|char
name|component_name
index|[
literal|50
index|]
decl_stmt|;
comment|/* name of the component */
block|}
name|RF_SingleComponent_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|raidcinfo
block|{
name|struct
name|vnode
modifier|*
name|ci_vp
decl_stmt|;
comment|/* component device's vnode */
name|dev_t
name|ci_dev
decl_stmt|;
comment|/* component device's dev_t */
name|RF_ComponentLabel_t
name|ci_label
decl_stmt|;
comment|/* components RAIDframe label */
if|#
directive|if
literal|0
block|size_t  ci_size;
comment|/* size */
block|char   *ci_path;
comment|/* path to component */
block|size_t  ci_pathlen;
comment|/* length of component path */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* XXX probably belongs in a different .h file. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|RF_AutoConfig_s
block|{
name|char
name|devname
index|[
literal|56
index|]
decl_stmt|;
comment|/* the name of this component */
name|int
name|flag
decl_stmt|;
comment|/* a general-purpose flag */
name|dev_t
name|dev
decl_stmt|;
comment|/* the device for this component */
name|struct
name|vnode
modifier|*
name|vp
decl_stmt|;
comment|/* Mr. Vnode Pointer */
name|RF_ComponentLabel_t
modifier|*
name|clabel
decl_stmt|;
comment|/* the label */
name|struct
name|RF_AutoConfig_s
modifier|*
name|next
decl_stmt|;
comment|/* the next autoconfig structure  				         in this set. */
block|}
name|RF_AutoConfig_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|RF_ConfigSet_s
block|{
name|struct
name|RF_AutoConfig_s
modifier|*
name|ac
decl_stmt|;
comment|/* all of the autoconfig structures for 				       this config set. */
name|int
name|rootable
decl_stmt|;
comment|/* Set to 1 if this set can be root */
name|struct
name|RF_ConfigSet_s
modifier|*
name|next
decl_stmt|;
block|}
name|RF_ConfigSet_t
typedef|;
end_typedef

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
comment|/* _RF__RF_BSD_H_ */
end_comment

end_unit

