begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * SSCOP protocol definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNI_SSCOP_H
end_ifndef

begin_define
define|#
directive|define
name|_UNI_SSCOP_H
end_define

begin_comment
comment|/*  * SSCOP Version  */
end_comment

begin_enum
enum|enum
name|sscop_vers
block|{
name|SSCOP_VERS_QSAAL
block|,
comment|/* Version = Q.SAAL1 */
name|SSCOP_VERS_Q2110
comment|/* Version = Q.2110 */
block|}
enum|;
end_enum

begin_comment
comment|/*  * SSCOP API definitions  */
end_comment

begin_define
define|#
directive|define
name|SSCOP_UU_NULL
value|0
end_define

begin_comment
comment|/* User-to-User Info = null */
end_comment

begin_define
define|#
directive|define
name|SSCOP_RN_TOTAL
value|-1
end_define

begin_comment
comment|/* Retrieval Number = Total */
end_comment

begin_define
define|#
directive|define
name|SSCOP_RN_UNKNOWN
value|-2
end_define

begin_comment
comment|/* Retrieval Number = Unknown */
end_comment

begin_define
define|#
directive|define
name|SSCOP_BR_YES
value|1
end_define

begin_comment
comment|/* Buffer Release = Yes */
end_comment

begin_define
define|#
directive|define
name|SSCOP_BR_NO
value|2
end_define

begin_comment
comment|/* Buffer Release = No */
end_comment

begin_define
define|#
directive|define
name|SSCOP_SOURCE_SSCOP
value|1
end_define

begin_comment
comment|/* Source = SSCOP */
end_comment

begin_define
define|#
directive|define
name|SSCOP_SOURCE_USER
value|2
end_define

begin_comment
comment|/* Source = User */
end_comment

begin_define
define|#
directive|define
name|SSCOP_SOURCE_LAST
value|3
end_define

begin_comment
comment|/* Source = from last END */
end_comment

begin_comment
comment|/*  * Connection parameters for an SSCOP entity.  * Passed via an SSCOP_INIT stack call argument.  */
end_comment

begin_struct
struct|struct
name|sscop_parms
block|{
name|u_short
name|sp_maxinfo
decl_stmt|;
comment|/* k - max information field size */
name|u_short
name|sp_maxuu
decl_stmt|;
comment|/* j - max SSCOP-UU field size */
name|short
name|sp_maxcc
decl_stmt|;
comment|/* MaxCC - max value of VT(CC) */
name|short
name|sp_maxpd
decl_stmt|;
comment|/* MaxPD - max value of VT(PD) */
name|u_short
name|sp_timecc
decl_stmt|;
comment|/* Timer_CC value (ticks) */
name|u_short
name|sp_timekeep
decl_stmt|;
comment|/* Timer_KEEPALIVE value (ticks) */
name|u_short
name|sp_timeresp
decl_stmt|;
comment|/* Timer_NO-RESPONSE value (ticks) */
name|u_short
name|sp_timepoll
decl_stmt|;
comment|/* Timer_POLL value (ticks) */
name|u_short
name|sp_timeidle
decl_stmt|;
comment|/* Timer_IDLE value (ticks) */
name|short
name|sp_rcvwin
decl_stmt|;
comment|/* Receiver window size */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNI_SSCOP_H */
end_comment

end_unit

