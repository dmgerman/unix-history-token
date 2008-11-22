begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $Begemot: libunimsg/netnatm/msg/unimsglib.h,v 1.6 2004/07/08 08:22:07 brandt Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_MSG_UNIMSGLIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_MSG_UNIMSGLIB_H_
end_define

begin_include
include|#
directive|include
file|<netnatm/msg/uni_config.h>
end_include

begin_struct_decl
struct_decl|struct
name|uni_msg
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|uni_ierr_type
block|{
name|UNI_IERR_UNK
block|,
comment|/* unknown IE */
name|UNI_IERR_LEN
block|,
comment|/* length error */
name|UNI_IERR_BAD
block|,
comment|/* content error */
name|UNI_IERR_ACC
block|,
comment|/* access element content error */
name|UNI_IERR_MIS
block|,
comment|/* mandatory IE missing (not used here) */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|uni_ierr
block|{
name|enum
name|uni_ierr_type
name|err
decl_stmt|;
comment|/* what error */
name|enum
name|uni_ieact
name|act
decl_stmt|;
comment|/* the action indicator */
name|u_int
name|ie
range|:
literal|8
decl_stmt|;
comment|/* the ie type */
name|u_int
name|man
range|:
literal|1
decl_stmt|;
comment|/* mandatory flag */
name|u_int
name|epref
range|:
literal|1
decl_stmt|;
comment|/* Q.2971 9.5.3.2.1 low-pri epref */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Context buffer. Needed to reduce number of arguments to routines.  */
end_comment

begin_struct
struct|struct
name|unicx
block|{
comment|/* 	 * globals for error handling 	 */
name|u_int
name|errcnt
decl_stmt|;
comment|/* number of bad IEs */
name|struct
name|uni_ierr
name|err
index|[
name|UNI_MAX_ERRIE
index|]
decl_stmt|;
comment|/* the errors */
name|int
name|q2932
decl_stmt|;
comment|/* Enable GFP */
name|int
name|pnni
decl_stmt|;
comment|/* Enable PNNI */
name|int
name|git_hard
decl_stmt|;
comment|/* do hard check on GIT IE */
name|int
name|bearer_hard
decl_stmt|;
comment|/* do hard check on BEARER IE */
name|int
name|cause_hard
decl_stmt|;
comment|/* do hard check on cause */
name|int
name|multiline
decl_stmt|;
comment|/* printing mode */
name|u_int
name|tabsiz
decl_stmt|;
comment|/* tabulation size */
comment|/* 	 * Internal context of library -- don't touch 	 */
name|struct
name|uni_ie_repeat
name|repeat
decl_stmt|;
comment|/* repeat IE during decoding */
name|enum
name|uni_ietype
name|ielast
decl_stmt|;
comment|/* last IE seen for repeat handling */
specifier|const
name|char
modifier|*
name|prefix
index|[
literal|20
index|]
decl_stmt|;
name|u_int
name|nprefix
decl_stmt|;
name|int
name|doindent
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
name|size_t
name|bufsiz
decl_stmt|;
name|u_int
name|indent
decl_stmt|;
comment|/* indentation */
name|int
name|dont_init
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Functions for all messages  */
end_comment

begin_function_decl
name|void
name|uni_print_cref
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|struct
name|uni_cref
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_print_msghdr
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|struct
name|uni_msghdr
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_print
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|struct
name|uni_all
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_print_msg
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|u_int
name|_mtype
parameter_list|,
specifier|const
name|union
name|uni_msgall
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_encode
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|struct
name|uni_all
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_decode
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|struct
name|uni_all
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_decode_head
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|struct
name|uni_all
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_decode_body
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|struct
name|uni_all
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_encode_msg_hdr
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|struct
name|uni_msghdr
modifier|*
parameter_list|,
name|enum
name|uni_msgtype
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions for all information elements  */
end_comment

begin_function_decl
name|void
name|uni_print_ie
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|enum
name|uni_ietype
parameter_list|,
specifier|const
name|union
name|uni_ieall
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_check_ie
parameter_list|(
name|enum
name|uni_ietype
parameter_list|,
name|union
name|uni_ieall
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_encode_ie
parameter_list|(
name|enum
name|uni_ietype
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|union
name|uni_ieall
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_decode_ie_hdr
parameter_list|(
name|enum
name|uni_ietype
modifier|*
parameter_list|,
name|struct
name|uni_iehdr
modifier|*
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_encode_ie_hdr
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|enum
name|uni_ietype
parameter_list|,
name|struct
name|uni_iehdr
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uni_decode_ie_body
parameter_list|(
name|enum
name|uni_ietype
parameter_list|,
name|union
name|uni_ieall
modifier|*
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Context handling  */
end_comment

begin_function_decl
name|void
name|uni_initcx
parameter_list|(
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|uni_print_cx
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|unicx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|UNI_SAVE_IERR
parameter_list|(
name|CX
parameter_list|,
name|IETYPE
parameter_list|,
name|ACT
parameter_list|,
name|ERRCODE
parameter_list|)
define|\
value|(((CX)->errcnt< UNI_MAX_ERRIE) ?				\ 	 ((CX)->err[(CX)->errcnt].ie = (IETYPE),			\ 	  (CX)->err[(CX)->errcnt].act = (ACT),				\ 	  (CX)->err[(CX)->errcnt].err = (ERRCODE),			\ 	  (CX)->err[(CX)->errcnt].man = 0,				\ 	  (CX)->errcnt++,						\ 	  1) : 0)
end_define

begin_comment
comment|/*  * Traffic classification  */
end_comment

begin_enum
enum|enum
name|uni_traffic_class
block|{
name|UNI_TRAFFIC_CBR1
block|,
name|UNI_TRAFFIC_CBR2
block|,
name|UNI_TRAFFIC_CBR3
block|,
name|UNI_TRAFFIC_rtVBR1
block|,
name|UNI_TRAFFIC_rtVBR2
block|,
name|UNI_TRAFFIC_rtVBR3
block|,
name|UNI_TRAFFIC_rtVBR4
block|,
name|UNI_TRAFFIC_rtVBR5
block|,
name|UNI_TRAFFIC_rtVBR6
block|,
name|UNI_TRAFFIC_nrtVBR1
block|,
name|UNI_TRAFFIC_nrtVBR2
block|,
name|UNI_TRAFFIC_nrtVBR3
block|,
name|UNI_TRAFFIC_nrtVBR4
block|,
name|UNI_TRAFFIC_nrtVBR5
block|,
name|UNI_TRAFFIC_nrtVBR6
block|,
name|UNI_TRAFFIC_ABR
block|,
name|UNI_TRAFFIC_UBR1
block|,
name|UNI_TRAFFIC_UBR2
block|, }
enum|;
end_enum

begin_comment
comment|/* classify traffic */
end_comment

begin_function_decl
name|int
name|uni_classify_traffic
parameter_list|(
specifier|const
name|struct
name|uni_ie_bearer
modifier|*
parameter_list|,
specifier|const
name|struct
name|uni_ie_traffic
modifier|*
parameter_list|,
name|enum
name|uni_traffic_class
modifier|*
parameter_list|,
name|enum
name|uni_traffic_class
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

