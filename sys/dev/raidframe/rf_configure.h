begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_configure.h,v 1.4 1999/03/02 03:18:49 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/********************************  *  * rf_configure.h  *  * header file for raidframe configuration in the kernel version only.  * configuration is invoked via ioctl rather than at boot time  *  *******************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_CONFIGURE_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_CONFIGURE_H_
end_define

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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the raidframe configuration, passed down through an ioctl.  * the driver can be reconfigured (with total loss of data) at any time,  * but it must be shut down first.  */
end_comment

begin_struct
struct|struct
name|RF_Config_s
block|{
name|RF_RowCol_t
name|numRow
decl_stmt|,
name|numCol
decl_stmt|,
name|numSpare
decl_stmt|;
comment|/* number of rows, columns, 						 * and spare disks */
name|dev_t
name|devs
index|[
name|RF_MAXROW
index|]
index|[
name|RF_MAXCOL
index|]
decl_stmt|;
comment|/* device numbers for disks 						 * comprising array */
name|char
name|devnames
index|[
name|RF_MAXROW
index|]
index|[
name|RF_MAXCOL
index|]
index|[
literal|50
index|]
decl_stmt|;
comment|/* device names */
name|dev_t
name|spare_devs
index|[
name|RF_MAXSPARE
index|]
decl_stmt|;
comment|/* device numbers for spare 						 * disks */
name|char
name|spare_names
index|[
name|RF_MAXSPARE
index|]
index|[
literal|50
index|]
decl_stmt|;
comment|/* device names */
name|RF_SectorNum_t
name|sectPerSU
decl_stmt|;
comment|/* sectors per stripe unit */
name|RF_StripeNum_t
name|SUsPerPU
decl_stmt|;
comment|/* stripe units per parity unit */
name|RF_StripeNum_t
name|SUsPerRU
decl_stmt|;
comment|/* stripe units per reconstruction unit */
name|RF_ParityConfig_t
name|parityConfig
decl_stmt|;
comment|/* identifies the RAID architecture to 					 * be used */
name|RF_DiskQueueType_t
name|diskQueueType
decl_stmt|;
comment|/* 'f' = fifo, 'c' = cvscan, 						 * not used in kernel */
name|char
name|maxOutstandingDiskReqs
decl_stmt|;
comment|/* # concurrent reqs to be sent to a 					 * disk.  not used in kernel. */
name|char
name|debugVars
index|[
name|RF_MAXDBGV
index|]
index|[
literal|50
index|]
decl_stmt|;
comment|/* space for specifying debug 						 * variables& their values */
name|unsigned
name|int
name|layoutSpecificSize
decl_stmt|;
comment|/* size in bytes of 						 * layout-specific info */
name|void
modifier|*
name|layoutSpecific
decl_stmt|;
comment|/* a pointer to a layout-specific structure to 				 * be copied in */
name|int
name|force
decl_stmt|;
comment|/* if !0, ignore many fatal 						   configuration conditions */
comment|/*  	   "force" is used to override cases where the component labels would  	   indicate that configuration should not proceed without user  	   intervention 	 */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|int
name|rf_MakeConfig
parameter_list|(
name|char
modifier|*
name|configname
parameter_list|,
name|RF_Config_t
modifier|*
name|cfgPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_MakeLayoutSpecificNULL
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
name|RF_Config_t
modifier|*
name|cfgPtr
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_MakeLayoutSpecificDeclustered
parameter_list|(
name|FILE
modifier|*
name|configfp
parameter_list|,
name|RF_Config_t
modifier|*
name|cfgPtr
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|rf_ReadSpareTable
parameter_list|(
name|RF_SparetWait_t
modifier|*
name|req
parameter_list|,
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_CONFIGURE_H_ */
end_comment

end_unit

