begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * FORE Systems 200-Series Adapter Support  * ---------------------------------------  *  * Driver statistics definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FORE_STATS_H
end_ifndef

begin_define
define|#
directive|define
name|_FORE_STATS_H
end_define

begin_comment
comment|/*  * Fore Driver Statistics  */
end_comment

begin_struct
struct|struct
name|Stats_driver
block|{
name|u_long
name|drv_xm_notact
decl_stmt|;
comment|/* PDU drops out - VCC not active */
name|u_long
name|drv_xm_full
decl_stmt|;
comment|/* Xmit queue full */
name|u_long
name|drv_xm_maxpdu
decl_stmt|;
comment|/* PDU drops out - max segment/size */
name|u_long
name|drv_xm_segnoal
decl_stmt|;
comment|/* Non-aligned segments */
name|u_long
name|drv_xm_seglen
decl_stmt|;
comment|/* Padded length segments */
name|u_long
name|drv_xm_segdma
decl_stmt|;
comment|/* PDU drops out - no dma address */
name|u_long
name|drv_rv_novcc
decl_stmt|;
comment|/* PDU drops in - no VCC */
name|u_long
name|drv_rv_nosbf
decl_stmt|;
comment|/* No small buffers */
name|u_long
name|drv_rv_nomb
decl_stmt|;
comment|/* PDU drops in - no buffer */
name|u_long
name|drv_rv_ifull
decl_stmt|;
comment|/* PDU drops in - intr queue full */
name|u_long
name|drv_bf_segdma
decl_stmt|;
comment|/* Buffer supply - no dma address */
name|u_long
name|drv_cm_full
decl_stmt|;
comment|/* Command queue full */
name|u_long
name|drv_cm_nodma
decl_stmt|;
comment|/* Command failed - no dma address */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|Stats_driver
name|Stats_driver
typedef|;
end_typedef

begin_comment
comment|/*  * Fore Device Statistics  *  * This structure is used by pass all statistics (including CP maintained   * and driver maintained) data to user space (atm command).  */
end_comment

begin_struct
struct|struct
name|fore_stats
block|{
name|Fore_cp_stats
name|st_cpstat
decl_stmt|;
comment|/* CP stats */
name|Stats_driver
name|st_drv
decl_stmt|;
comment|/* Driver maintained stats */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fore_stats
name|Fore_stats
typedef|;
end_typedef

begin_define
define|#
directive|define
name|st_taxi
value|st_cpstat.st_cp_taxi
end_define

begin_define
define|#
directive|define
name|st_oc3
value|st_cpstat.st_cp_oc3
end_define

begin_define
define|#
directive|define
name|st_atm
value|st_cpstat.st_cp_atm
end_define

begin_define
define|#
directive|define
name|st_aal0
value|st_cpstat.st_cp_aal0
end_define

begin_define
define|#
directive|define
name|st_aal4
value|st_cpstat.st_cp_aal4
end_define

begin_define
define|#
directive|define
name|st_aal5
value|st_cpstat.st_cp_aal5
end_define

begin_define
define|#
directive|define
name|st_misc
value|st_cpstat.st_cp_misc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FORE_STATS_H */
end_comment

end_unit

