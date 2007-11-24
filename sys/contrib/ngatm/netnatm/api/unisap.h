begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: libunimsg/netnatm/api/unisap.h,v 1.6 2005/05/23 11:49:17 brandt_h Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNATM_API_UNISAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNATM_API_UNISAP_H_
end_define

begin_include
include|#
directive|include
file|<netnatm/msg/uni_config.h>
end_include

begin_enum
enum|enum
name|unisve_tag
block|{
name|UNISVE_ABSENT
block|,
comment|/* Element is absent */
name|UNISVE_PRESENT
block|,
comment|/* Element is present with specific value */
name|UNISVE_ANY
comment|/* Any values is acceptable */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|unisve_addr
block|{
name|enum
name|unisve_tag
name|tag
decl_stmt|;
name|enum
name|uni_addr_type
name|type
decl_stmt|;
comment|/* type of address */
name|enum
name|uni_addr_plan
name|plan
decl_stmt|;
comment|/* addressing plan */
name|uint32_t
name|len
decl_stmt|;
comment|/* length of address */
name|u_char
name|addr
index|[
name|UNI_ADDR_MAXLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|unisve_selector
block|{
name|enum
name|unisve_tag
name|tag
decl_stmt|;
name|uint8_t
name|selector
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|unisve_blli_id2
block|{
name|enum
name|unisve_tag
name|tag
decl_stmt|;
name|u_int
name|proto
range|:
literal|5
decl_stmt|;
comment|/* the protocol */
name|u_int
name|user
range|:
literal|7
decl_stmt|;
comment|/* user specific protocol */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|unisve_blli_id3
block|{
name|enum
name|unisve_tag
name|tag
decl_stmt|;
name|u_int
name|proto
range|:
literal|5
decl_stmt|;
comment|/* L3 protocol */
name|u_int
name|user
range|:
literal|7
decl_stmt|;
comment|/* user specific protocol */
name|u_int
name|ipi
range|:
literal|8
decl_stmt|;
comment|/* ISO/IEC TR 9557 IPI */
name|u_int
name|oui
range|:
literal|24
decl_stmt|;
comment|/* IEEE 802.1 OUI */
name|u_int
name|pid
range|:
literal|16
decl_stmt|;
comment|/* IEEE 802.1 PID */
name|uint32_t
name|noipi
decl_stmt|;
comment|/* ISO/IEC TR 9557 per frame */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|unisve_bhli
block|{
name|enum
name|unisve_tag
name|tag
decl_stmt|;
name|enum
name|uni_bhli
name|type
decl_stmt|;
comment|/* type of info */
name|uint32_t
name|len
decl_stmt|;
comment|/* length of info */
name|uint8_t
name|info
index|[
literal|8
index|]
decl_stmt|;
comment|/* info itself */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uni_sap
block|{
name|struct
name|unisve_addr
name|addr
decl_stmt|;
name|struct
name|unisve_selector
name|selector
decl_stmt|;
name|struct
name|unisve_blli_id2
name|blli_id2
decl_stmt|;
name|struct
name|unisve_blli_id3
name|blli_id3
decl_stmt|;
name|struct
name|unisve_bhli
name|bhli
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|unisve_check_addr
parameter_list|(
specifier|const
name|struct
name|unisve_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_check_selector
parameter_list|(
specifier|const
name|struct
name|unisve_selector
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_check_blli_id2
parameter_list|(
specifier|const
name|struct
name|unisve_blli_id2
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_check_blli_id3
parameter_list|(
specifier|const
name|struct
name|unisve_blli_id3
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_check_bhli
parameter_list|(
specifier|const
name|struct
name|unisve_bhli
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_check_sap
parameter_list|(
specifier|const
name|struct
name|uni_sap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_overlap_addr
parameter_list|(
specifier|const
name|struct
name|unisve_addr
modifier|*
parameter_list|,
specifier|const
name|struct
name|unisve_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_overlap_selector
parameter_list|(
specifier|const
name|struct
name|unisve_selector
modifier|*
parameter_list|,
specifier|const
name|struct
name|unisve_selector
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_overlap_blli_id2
parameter_list|(
specifier|const
name|struct
name|unisve_blli_id2
modifier|*
parameter_list|,
specifier|const
name|struct
name|unisve_blli_id2
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_overlap_blli_id3
parameter_list|(
specifier|const
name|struct
name|unisve_blli_id3
modifier|*
parameter_list|,
specifier|const
name|struct
name|unisve_blli_id3
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_overlap_bhli
parameter_list|(
specifier|const
name|struct
name|unisve_bhli
modifier|*
parameter_list|,
specifier|const
name|struct
name|unisve_bhli
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_overlap_sap
parameter_list|(
specifier|const
name|struct
name|uni_sap
modifier|*
parameter_list|,
specifier|const
name|struct
name|uni_sap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_is_catchall
parameter_list|(
specifier|const
name|struct
name|uni_sap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unisve_match
parameter_list|(
specifier|const
name|struct
name|uni_sap
modifier|*
parameter_list|,
specifier|const
name|struct
name|uni_ie_called
modifier|*
parameter_list|,
specifier|const
name|struct
name|uni_ie_blli
modifier|*
parameter_list|,
specifier|const
name|struct
name|uni_ie_bhli
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|UNISVE_OK
init|=
literal|0
block|,
name|UNISVE_ERROR_BAD_TAG
block|,
name|UNISVE_ERROR_TYPE_PLAN_CONFLICT
block|,
name|UNISVE_ERROR_ADDR_SEL_CONFLICT
block|,
name|UNISVE_ERROR_ADDR_LEN
block|,
name|UNISVE_ERROR_BAD_ADDR_TYPE
block|,
name|UNISVE_ERROR_BAD_BHLI_TYPE
block|,
name|UNISVE_ERROR_BAD_BHLI_LEN
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|UNISVE_ERRSTR
define|\
value|"no error",					\ 	"bad SVE tag",					\ 	"bad address type/plan combination",		\ 	"bad address plan/selector tag combination",	\ 	"bad address length in SVE",			\ 	"unknown address type in SVE",			\ 	"bad BHLI type in SVE",				\ 	"BHLI info too long in SVE",
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

