begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MWLSTATS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MWLSTATS_H_
end_define

begin_include
include|#
directive|include
file|"bsdstat.h"
end_include

begin_comment
comment|/*  * mv statistics class.  */
end_comment

begin_struct
struct|struct
name|mwlstatfoo
block|{
name|struct
name|bsdstat
name|base
decl_stmt|;
name|BSDSTAT_DECL_METHODS
argument_list|(
expr|struct
name|mwlstatfoo
operator|*
argument_list|)
expr_stmt|;
comment|/* set the network interface name for collection */
name|void
function_decl|(
modifier|*
name|setifname
function_decl|)
parameter_list|(
name|struct
name|mwlstatfoo
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|ifname
parameter_list|)
function_decl|;
comment|/* set the mac address of the associated station/ap */
name|void
function_decl|(
modifier|*
name|setstamac
function_decl|)
parameter_list|(
name|struct
name|mwlstatfoo
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|mac
index|[]
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|mwlstatfoo
modifier|*
name|mwlstats_new
parameter_list|(
specifier|const
name|char
modifier|*
name|ifname
parameter_list|,
specifier|const
name|char
modifier|*
name|fmtstring
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MWLSTATS_H_ */
end_comment

end_unit

