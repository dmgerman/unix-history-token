begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_mcpair.h,v 1.6 2000/09/21 01:45:46 oster Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Mark Holland  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/* rf_mcpair.h  * see comments in rf_mcpair.c  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_MCPAIR_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_MCPAIR_H_
end_define

begin_include
include|#
directive|include
file|<dev/raidframe/rf_types.h>
end_include

begin_include
include|#
directive|include
file|<dev/raidframe/rf_threadstuff.h>
end_include

begin_struct
struct|struct
name|RF_MCPair_s
block|{
name|RF_DECLARE_MUTEX
argument_list|(
argument|mutex
argument_list|)
name|RF_DECLARE_COND
argument_list|(
argument|cond
argument_list|)
name|int
name|flag
decl_stmt|;
name|RF_MCPair_t
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RF_WAIT_MCPAIR
parameter_list|(
name|_mcp
parameter_list|)
define|\
value|RF_LTSLEEP(&((_mcp)->cond), PRIBIO, "mcpair", 0,&((_mcp)->mutex))
end_define

begin_function_decl
name|int
name|rf_ConfigureMCPair
parameter_list|(
name|RF_ShutdownList_t
modifier|*
modifier|*
name|listp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|RF_MCPair_t
modifier|*
name|rf_AllocMCPair
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_FreeMCPair
parameter_list|(
name|RF_MCPair_t
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_MCPairWakeupFunc
parameter_list|(
name|RF_MCPair_t
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_MCPAIR_H_ */
end_comment

end_unit

