begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * ATM Forum UNI 3.0/3.1 Signalling Manager  * ----------------------------------------  *  * Message formats  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UNI_SIG_DECODE_H
end_ifndef

begin_define
define|#
directive|define
name|_UNI_SIG_DECODE_H
end_define

begin_comment
comment|/*  * Values specifying which IEs are required in messages  */
end_comment

begin_define
define|#
directive|define
name|IE_NA
value|0
end_define

begin_define
define|#
directive|define
name|IE_MAND
value|1
end_define

begin_define
define|#
directive|define
name|IE_OPT
value|2
end_define

begin_comment
comment|/*  * Structure for information element decoding information  */
end_comment

begin_struct
struct|struct
name|ie_ent
block|{
name|u_char
name|ident
decl_stmt|;
comment|/* IE identifier */
name|int
name|min_len
decl_stmt|;
comment|/* Min. length */
name|int
name|max_len
decl_stmt|;
comment|/* Max. length */
name|int
name|p_idx
decl_stmt|;
comment|/* IE pointer index in msg */
name|int
function_decl|(
modifier|*
name|decode
function_decl|)
comment|/* Decoding function */
parameter_list|(
name|struct
name|usfmt
modifier|*
parameter_list|,
name|struct
name|ie_generic
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Macro to give the offset of a field in a generic IE structure  */
end_comment

begin_define
define|#
directive|define
name|IE_OFFSET
parameter_list|(
name|f
parameter_list|)
define|\
value|((int)&((struct ie_generic *) 0)->f)
end_define

begin_comment
comment|/*  * Macro to give the size of a field in a generic IE structure  */
end_comment

begin_define
define|#
directive|define
name|IE_FSIZE
parameter_list|(
name|f
parameter_list|)
define|\
value|(sizeof(((struct ie_generic *) 0)->f))
end_define

begin_define
define|#
directive|define
name|IE_OFF_SIZE
parameter_list|(
name|f
parameter_list|)
value|IE_OFFSET(f),IE_FSIZE(f)
end_define

begin_comment
comment|/*  * Structure to define a field-driven decoding table (for AAL  * parameters and ATM user cell rate IEs)  */
end_comment

begin_struct
struct|struct
name|ie_decode_tbl
block|{
name|u_char
name|ident
decl_stmt|;
name|int
name|len
decl_stmt|;
name|int
name|f_offs
decl_stmt|;
name|int
name|f_size
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _UNI_SIG_DECODE_H */
end_comment

end_unit

