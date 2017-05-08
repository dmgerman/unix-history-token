begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2015 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $OpenPAM: openpam_features.c 938 2017-04-30 21:34:42Z des $  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<security/pam_appl.h>
end_include

begin_include
include|#
directive|include
file|"openpam_impl.h"
end_include

begin_define
define|#
directive|define
name|STRUCT_OPENPAM_FEATURE
parameter_list|(
name|name
parameter_list|,
name|descr
parameter_list|,
name|dflt
parameter_list|)
define|\
value|[OPENPAM_##name] = {				\ 		"OPENPAM_" #name,			\ 		descr,					\ 		dflt					\ 	}
end_define

begin_decl_stmt
name|struct
name|openpam_feature
name|openpam_features
index|[
name|OPENPAM_NUM_FEATURES
index|]
init|=
block|{
name|STRUCT_OPENPAM_FEATURE
argument_list|(
name|RESTRICT_SERVICE_NAME
argument_list|,
literal|"Disallow path separators in service names"
argument_list|,
literal|1
argument_list|)
block|,
name|STRUCT_OPENPAM_FEATURE
argument_list|(
name|VERIFY_POLICY_FILE
argument_list|,
literal|"Verify ownership and permissions of policy files"
argument_list|,
literal|1
argument_list|)
block|,
name|STRUCT_OPENPAM_FEATURE
argument_list|(
name|RESTRICT_MODULE_NAME
argument_list|,
literal|"Disallow path separators in module names"
argument_list|,
literal|0
argument_list|)
block|,
name|STRUCT_OPENPAM_FEATURE
argument_list|(
name|VERIFY_MODULE_FILE
argument_list|,
literal|"Verify ownership and permissions of module files"
argument_list|,
literal|1
argument_list|)
block|,
name|STRUCT_OPENPAM_FEATURE
argument_list|(
name|FALLBACK_TO_OTHER
argument_list|,
literal|"Fall back to \"other\" policy for empty chains"
argument_list|,
literal|1
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

end_unit

