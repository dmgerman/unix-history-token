begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * SSCOP miscellaneous definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNI_SSCOP_MISC_H
end_ifndef

begin_define
define|#
directive|define
name|_UNI_SSCOP_MISC_H
end_define

begin_comment
comment|/*  * SSCOP command definitions  */
end_comment

begin_define
define|#
directive|define
name|SSCOP_CMD_MIN
value|SSCOP_INIT
end_define

begin_comment
comment|/* Minimum SSCOP CMD value */
end_comment

begin_define
define|#
directive|define
name|SSCOP_CMD_MAX
value|SSCOP_RETRIEVECMP_IND
end_define

begin_comment
comment|/* Maximum SSCOP CMD value */
end_comment

begin_define
define|#
directive|define
name|SSCOP_CMD_SIZE
value|36
end_define

begin_comment
comment|/* Size of command lookup table */
end_comment

begin_comment
comment|/*  * Management Errors  */
end_comment

begin_define
define|#
directive|define
name|MAA_ERROR_MIN
value|'A'
end_define

begin_define
define|#
directive|define
name|MAA_ERROR_MAX
value|'X'
end_define

begin_define
define|#
directive|define
name|MAA_ERROR_INVAL
value|(MAA_ERROR_MAX + 1)
end_define

begin_define
define|#
directive|define
name|MAA_ERROR_COUNT
value|(MAA_ERROR_MAX - MAA_ERROR_MIN + 2)
end_define

begin_comment
comment|/*  * SSCOP Sequence Numbers  *  * SSCOP sequence numbers are 24 bit integers using modulo arithmetic.  * The macros below must be used to modify and compare such numbers.  * Comparison of sequence numbers is always relative to some base number (b).  */
end_comment

begin_typedef
typedef|typedef
name|u_int
name|sscop_seq
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SEQ_MOD
value|0xffffff
end_define

begin_define
define|#
directive|define
name|SEQ_VAL
parameter_list|(
name|v
parameter_list|)
value|((v)& SEQ_MOD)
end_define

begin_define
define|#
directive|define
name|SEQ_SET
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s) = SEQ_VAL(v))
end_define

begin_define
define|#
directive|define
name|SEQ_ADD
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SEQ_VAL((s) + (v)))
end_define

begin_define
define|#
directive|define
name|SEQ_SUB
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(SEQ_VAL((s) - (v)))
end_define

begin_define
define|#
directive|define
name|SEQ_INCR
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s) = SEQ_VAL((s) + (v)))
end_define

begin_define
define|#
directive|define
name|SEQ_DECR
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|((s) = SEQ_VAL((s) - (v)))
end_define

begin_define
define|#
directive|define
name|SEQ_EQ
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(SEQ_VAL(x) == SEQ_VAL(y))
end_define

begin_define
define|#
directive|define
name|SEQ_NEQ
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(SEQ_VAL(x) != SEQ_VAL(y))
end_define

begin_define
define|#
directive|define
name|SEQ_LT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|b
parameter_list|)
value|(SEQ_VAL((x) - (b))< SEQ_VAL((y) - (b)))
end_define

begin_define
define|#
directive|define
name|SEQ_LEQ
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|b
parameter_list|)
value|(SEQ_VAL((x) - (b))<= SEQ_VAL((y) - (b)))
end_define

begin_define
define|#
directive|define
name|SEQ_GT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|b
parameter_list|)
value|(SEQ_VAL((x) - (b))> SEQ_VAL((y) - (b)))
end_define

begin_define
define|#
directive|define
name|SEQ_GEQ
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|b
parameter_list|)
value|(SEQ_VAL((x) - (b))>= SEQ_VAL((y) - (b)))
end_define

begin_comment
comment|/*  * SSCOP Timers  *  * All of the SSCOP timer fields are maintained in terms of clock ticks.  * The timers tick 2 times per second.  */
end_comment

begin_define
define|#
directive|define
name|SSCOP_HZ
value|2
end_define

begin_comment
comment|/* SSCOP ticks per second */
end_comment

begin_define
define|#
directive|define
name|SSCOP_T_NUM
value|4
end_define

begin_comment
comment|/* Number of timers per connection */
end_comment

begin_define
define|#
directive|define
name|SSCOP_T_POLL
value|0
end_define

begin_comment
comment|/* Timer_POLL / Timer_KEEP-ALIVE */
end_comment

begin_define
define|#
directive|define
name|SSCOP_T_NORESP
value|1
end_define

begin_comment
comment|/* Timer_NO-RESPONSE */
end_comment

begin_define
define|#
directive|define
name|SSCOP_T_CC
value|2
end_define

begin_comment
comment|/* Timer_CC */
end_comment

begin_define
define|#
directive|define
name|SSCOP_T_IDLE
value|3
end_define

begin_comment
comment|/* Timer_IDLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNI_SSCOP_MISC_H */
end_comment

end_unit

