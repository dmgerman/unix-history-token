begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by NAI Labs, the  * Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL_MEDIATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_KERNEL_MEDIATE_H_
end_define

begin_include
include|#
directive|include
file|"kernel_interface.h"
end_include

begin_function_decl
name|int
name|mediate_subject_level_subject
parameter_list|(
specifier|const
name|char
modifier|*
name|op_s
parameter_list|,
specifier|const
name|lomac_subject_t
modifier|*
name|p_subject_one
parameter_list|,
name|level_t
name|level_one
parameter_list|,
name|lomac_subject_t
modifier|*
name|p_subject_two
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mediate_subject_object
parameter_list|(
specifier|const
name|char
modifier|*
name|op_s
parameter_list|,
name|lomac_subject_t
modifier|*
name|p_subject
parameter_list|,
specifier|const
name|lomac_object_t
modifier|*
name|p_object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mediate_subject_object_open
parameter_list|(
name|lomac_subject_t
modifier|*
name|p_subject
parameter_list|,
specifier|const
name|lomac_object_t
modifier|*
name|p_object
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int mediate_subject_path( const char *op_s, const lomac_subject_t *p_subject, 			  const char *path_s ); int mediate_path_path( const char *op_s, const lomac_subject_t *p_subject, 		       const char *canabsname_one_s,  		       const char *canabsname_two_s );
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|mediate_subject_at_level
parameter_list|(
specifier|const
name|char
modifier|*
name|op_s
parameter_list|,
name|lomac_subject_t
modifier|*
name|p_subject
parameter_list|,
specifier|const
name|level_t
name|target_level
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|int mediate_object_at_level( const char *op_s, 			     const lomac_subject_t *p_subject, 			     const lomac_object_t *p_object, 			     const level_t target_level );
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

