begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_dagflags.h,v 1.3 1999/02/05 00:06:08 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/**************************************************************************************  *  * dagflags.h -- flags that can be given to DoAccess  * I pulled these out of dag.h because routines that call DoAccess may need these flags,  * but certainly do not need the declarations related to the DAG data structures.  *  **************************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_DAGFLAGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_DAGFLAGS_H_
end_define

begin_comment
comment|/*  * Bitmasks for the "flags" parameter (RF_RaidAccessFlags_t) used  * by DoAccess, SelectAlgorithm, and the DAG creation routines.  *  * If USE_DAG or USE_ASM is specified, neither the DAG nor the ASM  * will be modified, which means that you can't SUPRESS if you  * specify USE_DAG.  */
end_comment

begin_define
define|#
directive|define
name|RF_DAG_FLAGS_NONE
value|0
end_define

begin_comment
comment|/* no flags */
end_comment

begin_define
define|#
directive|define
name|RF_DAG_SUPPRESS_LOCKS
value|(1<<0)
end_define

begin_comment
comment|/* supress all stripe locks in 						 * the DAG */
end_comment

begin_define
define|#
directive|define
name|RF_DAG_RETURN_ASM
value|(1<<1)
end_define

begin_comment
comment|/* create an ASM and return it 						 * instead of freeing it */
end_comment

begin_define
define|#
directive|define
name|RF_DAG_RETURN_DAG
value|(1<<2)
end_define

begin_comment
comment|/* create a DAG and return it 						 * instead of freeing it */
end_comment

begin_define
define|#
directive|define
name|RF_DAG_NONBLOCKING_IO
value|(1<<3)
end_define

begin_comment
comment|/* cause DoAccess to be 						 * non-blocking */
end_comment

begin_define
define|#
directive|define
name|RF_DAG_ACCESS_COMPLETE
value|(1<<4)
end_define

begin_comment
comment|/* the access is complete */
end_comment

begin_define
define|#
directive|define
name|RF_DAG_DISPATCH_RETURNED
value|(1<<5)
end_define

begin_comment
comment|/* used to handle the case 						 * where the dag invokes no 						 * I/O */
end_comment

begin_define
define|#
directive|define
name|RF_DAG_TEST_ACCESS
value|(1<<6)
end_define

begin_comment
comment|/* this access came through 						 * rf_ioctl instead of 						 * rf_strategy */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_DAGFLAGS_H_ */
end_comment

end_unit

