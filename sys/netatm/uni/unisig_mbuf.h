begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI 3.0/3.1 Signalling Manager  * ----------------------------------------  *  * Message buffer formats  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNI_SIG_MBUF_H
end_ifndef

begin_define
define|#
directive|define
name|_UNI_SIG_MBUF_H
end_define

begin_comment
comment|/*  * Structure for message encoding/decoding information.  */
end_comment

begin_struct
struct|struct
name|usfmt
block|{
name|KBuffer
modifier|*
name|usf_m_addr
decl_stmt|;
comment|/* Current buffer */
name|KBuffer
modifier|*
name|usf_m_base
decl_stmt|;
comment|/* First buffer in chain */
name|int
name|usf_loc
decl_stmt|;
comment|/* Offset in current buffer */
name|int
name|usf_op
decl_stmt|;
comment|/* Operation (see below) */
name|struct
name|unisig
modifier|*
name|usf_sig
decl_stmt|;
comment|/* UNI signalling instance */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|USF_ENCODE
value|1
end_define

begin_define
define|#
directive|define
name|USF_DECODE
value|2
end_define

begin_define
define|#
directive|define
name|USF_MIN_ALLOC
value|MHLEN
end_define

begin_comment
comment|/* Minimum encoding buffer size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNI_SIG_MBUF_H */
end_comment

end_unit

