begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_copyback.h,v 1.3 1999/02/05 00:06:06 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_copyback.h  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Jim Zelenka  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_COPYBACK_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_COPYBACK_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|RF_CopybackDesc_s
block|{
name|RF_Raid_t
modifier|*
name|raidPtr
decl_stmt|;
name|RF_RowCol_t
name|frow
decl_stmt|;
name|RF_RowCol_t
name|fcol
decl_stmt|;
name|RF_RowCol_t
name|spRow
decl_stmt|;
name|RF_RowCol_t
name|spCol
decl_stmt|;
name|int
name|status
decl_stmt|;
name|RF_StripeNum_t
name|stripeAddr
decl_stmt|;
name|RF_SectorCount_t
name|sectPerSU
decl_stmt|;
name|RF_SectorCount_t
name|sectPerStripe
decl_stmt|;
name|char
modifier|*
name|databuf
decl_stmt|;
name|RF_DiskQueueData_t
modifier|*
name|readreq
decl_stmt|;
name|RF_DiskQueueData_t
modifier|*
name|writereq
decl_stmt|;
name|struct
name|timeval
name|starttime
decl_stmt|;
name|RF_MCPair_t
modifier|*
name|mcpair
decl_stmt|;
block|}
name|RF_CopybackDesc_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|rf_copyback_in_progress
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|rf_ConfigureCopyback
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_CopybackReconstructedData
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_ContinueCopyback
parameter_list|(
name|RF_CopybackDesc_t
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_COPYBACK_H_ */
end_comment

end_unit

