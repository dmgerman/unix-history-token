begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: rf_evenodd_dagfuncs.h,v 1.2 1999/02/05 00:06:11 oster Exp $	*/
end_comment

begin_comment
comment|/*  * rf_evenodd_dagfuncs.h  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chang-Ming Wu  *  * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND  * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RF__RF_EVENODD_DAGFUNCS_H_
end_ifndef

begin_define
define|#
directive|define
name|_RF__RF_EVENODD_DAGFUNCS_H_
end_define

begin_decl_stmt
specifier|extern
name|RF_RedFuncs_t
name|rf_EOSmallWriteEFuncs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|RF_RedFuncs_t
name|rf_EOSmallWritePFuncs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|RF_RedFuncs_t
name|rf_eoERecoveryFuncs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|RF_RedFuncs_t
name|rf_eoPRecoveryFuncs
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|rf_RegularPEFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_RegularONEFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_SimpleONEFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_RegularESubroutine
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|,
name|char
modifier|*
name|ebuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_RegularEFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_DegrESubroutine
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|,
name|char
modifier|*
name|ebuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_Degraded_100_EOFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_e_EncOneSect
parameter_list|(
name|RF_RowCol_t
name|srcLogicCol
parameter_list|,
name|char
modifier|*
name|srcSecbuf
parameter_list|,
name|RF_RowCol_t
name|destLogicCol
parameter_list|,
name|char
modifier|*
name|destSecbuf
parameter_list|,
name|int
name|bytesPerSector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_e_encToBuf
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|RF_RowCol_t
name|srcLogicCol
parameter_list|,
name|char
modifier|*
name|srcbuf
parameter_list|,
name|RF_RowCol_t
name|destLogicCol
parameter_list|,
name|char
modifier|*
name|destbuf
parameter_list|,
name|int
name|numSector
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_RecoveryEFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_EO_DegradedWriteEFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rf_doubleEOdecode
parameter_list|(
name|RF_Raid_t
modifier|*
name|raidPtr
parameter_list|,
name|char
modifier|*
modifier|*
name|rrdbuf
parameter_list|,
name|char
modifier|*
modifier|*
name|dest
parameter_list|,
name|RF_RowCol_t
modifier|*
name|fcol
parameter_list|,
name|char
modifier|*
name|pbuf
parameter_list|,
name|char
modifier|*
name|ebuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_EvenOddDoubleRecoveryFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rf_EOWriteDoubleRecoveryFunc
parameter_list|(
name|RF_DagNode_t
modifier|*
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|rf_EUCol
parameter_list|(
name|_layoutPtr_
parameter_list|,
name|_addr_
parameter_list|)
define|\
value|( (_addr_)%( (_layoutPtr_)->dataSectorsPerStripe ) )/((_layoutPtr_)->sectorsPerStripeUnit)
end_define

begin_define
define|#
directive|define
name|rf_EO_Mod
parameter_list|(
name|_int1_
parameter_list|,
name|_int2_
parameter_list|)
define|\
value|( ((_int1_)< 0)? (((_int1_)+(_int2_))%(_int2_)) : (_int1_)%(_int2_) )
end_define

begin_define
define|#
directive|define
name|rf_OffsetOfNextEUBoundary
parameter_list|(
name|_offset_
parameter_list|,
name|sec_per_eu
parameter_list|)
value|((_offset_)/(sec_per_eu) + 1)*(sec_per_eu)
end_define

begin_define
define|#
directive|define
name|RF_EO_MATRIX_DIM
value|17
end_define

begin_comment
comment|/*  * RF_EO_MATRIX_DIM should be a prime number: and "bytesPerSector" should be  * dividable by ( RF_EO_MATRIX_DIM - 1) to fully encode and utilize the space  * in a sector, this number could also be 17. Tha later case doesn't apply  * for disk array larger than 17 columns totally.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RF__RF_EVENODD_DAGFUNCS_H_ */
end_comment

end_unit

