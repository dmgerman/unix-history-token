begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI 3.0/3.1 Signalling Manager  * ----------------------------------------  *  * Protocol control blocks  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNISIG_H
end_ifndef

begin_define
define|#
directive|define
name|_UNISIG_H
end_define

begin_comment
comment|/*  * ATM Forum UNI 3.0/3.1 Signalling  */
end_comment

begin_define
define|#
directive|define
name|UNISIG_SIG_VPI
value|0
end_define

begin_comment
comment|/* Signalling VPI */
end_comment

begin_define
define|#
directive|define
name|UNISIG_SIG_VCI
value|5
end_define

begin_comment
comment|/* Signalling VCI */
end_comment

begin_define
define|#
directive|define
name|STACK_SSCF
value|"uni_sscf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNISIG_H */
end_comment

end_unit

