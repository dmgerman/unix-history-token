begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI Support  * ---------------------  *  * SSCF UNI protocol definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNI_SSCF_UNI_H
end_ifndef

begin_define
define|#
directive|define
name|_UNI_SSCF_UNI_H
end_define

begin_comment
comment|/*  * SSCF_UNI API definitions  */
end_comment

begin_define
define|#
directive|define
name|SSCF_UNI_ESTIND_YES
value|1
end_define

begin_comment
comment|/* Allow new ESTABLISH_IND */
end_comment

begin_define
define|#
directive|define
name|SSCF_UNI_ESTIND_NO
value|2
end_define

begin_comment
comment|/* Disallow new ESTABLISH_IND */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNI_SSCF_UNI_H */
end_comment

end_unit

