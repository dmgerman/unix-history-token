begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2012, Qualcomm Atheros, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the following conditions are met:  * 1. The materials contained herein are unmodified and are used  *    unmodified.  * 2. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following NO  *    ''WARRANTY'' disclaimer below (''Disclaimer''), without  *    modification.  * 3. Redistributions in binary form must reproduce at minimum a  *    disclaimer similar to the Disclaimer below and any redistribution  *    must be conditioned upon including a substantially similar  *    Disclaimer requirement for further binary redistribution.  * 4. Neither the names of the above-listed copyright holders nor the  *    names of any contributors may be used to endorse or promote  *    product derived from this software without specific prior written  *    permission.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT,  * MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE  * FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGES.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR9300_DEVID_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR9300_DEVID_H__
end_define

begin_comment
comment|/*  * AR9380 HAL device IDs.  */
end_comment

begin_comment
comment|/*  * MAC Version and Revision  */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_VERSION_AR9380
value|0x1C0
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_AR9580
value|0x1C0
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_AR9460
value|0x280
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_QCA9565
value|0x2c0
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_AR9330
value|0x200
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_AR9340
value|0x300
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_QCA9550
value|0x400
end_define

begin_define
define|#
directive|define
name|AR_SREV_VERSION_AR9485
value|0x240
end_define

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9380_10
value|0
end_define

begin_comment
comment|/* AR9380 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9380_20
value|2
end_define

begin_comment
comment|/* AR9380 2.0/2.1 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9380_22
value|3
end_define

begin_comment
comment|/* AR9380 2.2 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9580_10
value|4
end_define

begin_comment
comment|/* AR9580/Peacock 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9330_10
value|0
end_define

begin_comment
comment|/* AR9330 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9330_11
value|1
end_define

begin_comment
comment|/* AR9330 1.1 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9330_12
value|2
end_define

begin_comment
comment|/* AR9330 1.2 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9330_11_MASK
value|0xf
end_define

begin_comment
comment|/* AR9330 1.1 revision mask */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9485_10
value|0
end_define

begin_comment
comment|/* AR9485 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9485_11
value|1
end_define

begin_comment
comment|/* AR9485 1.1 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9340_10
value|0
end_define

begin_comment
comment|/* AR9340 1.0 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9340_11
value|1
end_define

begin_comment
comment|/* AR9340 1.1 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9340_12
value|2
end_define

begin_comment
comment|/* AR9340 1.2 */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9340_MASK
value|0xf
end_define

begin_comment
comment|/* AR9340 revision mask */
end_comment

begin_define
define|#
directive|define
name|AR_SREV_REVISION_AR9460_10
value|0
end_define

begin_comment
comment|/* AR946x 1.0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AR9300_DEVID_H__ */
end_comment

end_unit

