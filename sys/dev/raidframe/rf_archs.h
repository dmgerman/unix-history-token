begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_archs.h,v 1.11 2001/01/26 04:43:16 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/* rf_archs.h -- defines for which architectures you want to  * include is some particular build of raidframe.  Unfortunately,  * it's difficult to exclude declustering, P+Q, and distributed  * sparing because the code is intermixed with RAID5 code.  This  * should be fixed.  *  * this is really intended only for use in the kernel, where I  * am worried about the size of the object module.  At user level and  * in the simulator, I don't really care that much, so all the  * architectures can be compiled together.  Note that by itself, turning  * off these defines does not affect the size of the executable; you  * have to edit the makefile for that.  *  * comment out any line below to eliminate that architecture.  * the list below includes all the modules that can be compiled  * out.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_ARCHS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_ARCHS_H_
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_EVENODD
value|1
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_RAID5_RS
value|1
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_PARITYLOGGING
value|1
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_CHAINDECLUSTER
value|1
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_INTERDECLUSTER
value|1
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_PARITY_DECLUSTERING
value|1
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_PARITY_DECLUSTERING_DS
value|1
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_RAID0
value|1
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_RAID1
value|1
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_RAID4
value|1
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_RAID5
value|1
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_RAID6
value|0
end_define

begin_define
define|#
directive|define
name|RF_INCLUDE_DECL_PQ
value|0
end_define

begin_define
define|#
directive|define
name|RF_MEMORY_REDZONES
value|0
end_define

begin_define
define|#
directive|define
name|RF_RECON_STATS
value|1
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_options.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_ARCHS_H_ */
end_comment

end_unit

