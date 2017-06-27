begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2012-2013 Intel Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NVMECONTROL_H__
end_ifndef

begin_define
define|#
directive|define
name|__NVMECONTROL_H__
end_define

begin_include
include|#
directive|include
file|<dev/nvme/nvme.h>
end_include

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|nvme_fn_t
function_decl|)
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|nvme_function
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|nvme_fn_t
name|fn
decl_stmt|;
specifier|const
name|char
modifier|*
name|usage
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NVME_CTRLR_PREFIX
value|"nvme"
end_define

begin_define
define|#
directive|define
name|NVME_NS_PREFIX
value|"ns"
end_define

begin_define
define|#
directive|define
name|DEVLIST_USAGE
define|\
value|"       nvmecontrol devlist\n"
end_define

begin_define
define|#
directive|define
name|IDENTIFY_USAGE
define|\
value|"       nvmecontrol identify [-x [-v]]<controller id|namespace id>\n"
end_define

begin_define
define|#
directive|define
name|PERFTEST_USAGE
define|\
value|"       nvmecontrol perftest<-n num_threads><-o read|write>\n"	       \ "<-s size_in_bytes><-t time_in_seconds>\n"	       \ "<-i intr|wait> [-f refthread] [-p]\n"	       \ "<namespace id>\n"
end_define

begin_define
define|#
directive|define
name|RESET_USAGE
define|\
value|"       nvmecontrol reset<controller id>\n"
end_define

begin_define
define|#
directive|define
name|LOGPAGE_USAGE
define|\
value|"       nvmecontrol logpage<-p page_id> [-b] [-v vendor] [-x]<controller id|namespace id>\n"  \  #define FIRMWARE_USAGE							       \ "       nvmecontrol firmware [-s slot] [-f path_to_firmware] [-a]<controller id>\n"
end_define

begin_define
define|#
directive|define
name|POWER_USAGE
define|\
value|"       nvmecontrol power [-l] [-p new-state [-w workload-hint]]<controller id>\n"
end_define

begin_define
define|#
directive|define
name|WDC_USAGE
define|\
value|"       nvmecontrol wdc (cap-diag|drive-log|get-crash-dump|purge|purge-montior)\n"
end_define

begin_function_decl
name|void
name|devlist
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|identify
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perftest
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reset
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logpage
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|firmware
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|power
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wdc
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|open_dev
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
modifier|*
name|fd
parameter_list|,
name|int
name|show_error
parameter_list|,
name|int
name|exit_on_error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parse_ns_str
parameter_list|(
specifier|const
name|char
modifier|*
name|ns_str
parameter_list|,
name|char
modifier|*
name|ctrlr_str
parameter_list|,
name|int
modifier|*
name|nsid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_controller_data
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|nvme_controller_data
modifier|*
name|cdata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_namespace_data
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|nsid
parameter_list|,
name|struct
name|nvme_namespace_data
modifier|*
name|nsdata
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_hex
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|uint32_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_logpage
parameter_list|(
name|int
name|fd
parameter_list|,
name|uint8_t
name|log_page
parameter_list|,
name|int
name|nsid
parameter_list|,
name|void
modifier|*
name|payload
parameter_list|,
name|uint32_t
name|payload_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gen_usage
parameter_list|(
name|struct
name|nvme_function
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dispatch
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|struct
name|nvme_function
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Utility Routines */
end_comment

begin_comment
comment|/*  * 128-bit integer augments to standard values. On i386 this  * doesn't exist, so we use 64-bit values. So, on 32-bit i386,  * you'll get truncated values until someone implement 128bit  * ints in sofware.  */
end_comment

begin_define
define|#
directive|define
name|UINT128_DIG
value|39
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_typedef
typedef|typedef
name|uint64_t
name|uint128_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__uint128_t
name|uint128_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|__inline
name|uint128_t
name|to128
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|*
operator|(
name|uint128_t
operator|*
operator|)
name|p
return|;
block|}
end_function

begin_function_decl
name|uint64_t
name|le48dec
parameter_list|(
specifier|const
name|void
modifier|*
name|pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|uint128_to_str
parameter_list|(
name|uint128_t
name|u
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

