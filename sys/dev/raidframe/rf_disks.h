begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_disks.h,v 1.8 2000/03/27 03:25:17 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * rf_disks.h -- header file for code related to physical disks  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_DISKS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_DISKS_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_archs.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_bsd.h>
end_include

begin_comment
comment|/*  * A physical disk can be in one of several states:  * IF YOU ADD A STATE, CHECK TO SEE IF YOU NEED TO MODIFY RF_DEAD_DISK() BELOW.  */
end_comment

begin_enum
enum|enum
name|RF_DiskStatus_e
block|{
name|rf_ds_optimal
block|,
comment|/* no problems */
name|rf_ds_failed
block|,
comment|/* reconstruction ongoing */
name|rf_ds_reconstructing
block|,
comment|/* reconstruction complete to spare, dead disk 				 * not yet replaced */
name|rf_ds_dist_spared
block|,
comment|/* reconstruction complete to distributed 				 * spare space, dead disk not yet replaced */
name|rf_ds_spared
block|,
comment|/* reconstruction complete to distributed 				 * spare space, dead disk not yet replaced */
name|rf_ds_spare
block|,
comment|/* an available spare disk */
name|rf_ds_used_spare
comment|/* a spare which has been used, and hence is 				 * not available */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|RF_DiskStatus_e
name|RF_DiskStatus_t
typedef|;
end_typedef

begin_struct
struct|struct
name|RF_RaidDisk_s
block|{
name|char
name|devname
index|[
literal|56
index|]
decl_stmt|;
comment|/* name of device file */
name|RF_DiskStatus_t
name|status
decl_stmt|;
comment|/* whether it is up or down */
name|RF_RowCol_t
name|spareRow
decl_stmt|;
comment|/* if in status "spared", this identifies the 				 * spare disk */
name|RF_RowCol_t
name|spareCol
decl_stmt|;
comment|/* if in status "spared", this identifies the 				 * spare disk */
name|RF_SectorCount_t
name|numBlocks
decl_stmt|;
comment|/* number of blocks, obtained via READ 					 * CAPACITY */
name|int
name|blockSize
decl_stmt|;
name|RF_SectorCount_t
name|partitionSize
decl_stmt|;
comment|/* The *actual* and *full* size of  					   the partition, from the disklabel */
name|int
name|auto_configured
decl_stmt|;
comment|/* 1 if this component was autoconfigured. 				   0 otherwise. */
name|dev_t
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * An RF_DiskOp_t ptr is really a pointer to a UAGT_CCB, but I want  * to isolate the cam layer from all other layers, so I typecast to/from  * RF_DiskOp_t * (i.e. void *) at the interfaces.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|RF_DiskOp_t
typedef|;
end_typedef

begin_comment
comment|/* if a disk is in any of these states, it is inaccessible */
end_comment

begin_define
define|#
directive|define
name|RF_DEAD_DISK
parameter_list|(
name|_dstat_
parameter_list|)
value|(((_dstat_) == rf_ds_spared) || \ 	((_dstat_) == rf_ds_reconstructing) || ((_dstat_) == rf_ds_failed) || \ 	((_dstat_) == rf_ds_dist_spared))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<dev/raidframe/rf_bsd.h>
end_include

begin_function_decl
name|int
name|rf_ConfigureDisks
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|,
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_Config_t
modifier|*
name|cfgPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ConfigureSpareDisks
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|,
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_Config_t
modifier|*
name|cfgPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_ConfigureDisk
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|RF_RaidDisk_t
modifier|*
name|diskPtr
parameter_list|,
name|RF_RowCol_t
name|row
parameter_list|,
name|RF_RowCol_t
name|col
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_AutoConfigureDisks
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_Config_t
modifier|*
name|cfgPtr
parameter_list|,
name|RF_AutoConfig_t
modifier|*
name|auto_config
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_CheckLabels
parameter_list|(
name|RF_Raid_t
modifier|*
parameter_list|,
name|RF_Config_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_add_hot_spare
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_SingleComponent_t
modifier|*
name|sparePtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_remove_hot_spare
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_SingleComponent_t
modifier|*
name|sparePtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_delete_component
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_SingleComponent_t
modifier|*
name|component
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_incorporate_hot_spare
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_SingleComponent_t
modifier|*
name|component
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
comment|/* !_RF__RF_DISKS_H_ */
end_comment

end_unit

