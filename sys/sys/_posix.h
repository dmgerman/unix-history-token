begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__POSIX_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__POSIX_H_
end_define

begin_comment
comment|/*-  * Copyright (c) 1998 HD Associates, Inc.  * All rights reserved.  * contact: dufault@hda.com  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: $  */
end_comment

begin_comment
comment|/*  * This is a stand alone header file to set up for feature specification  * defined to take place before the inclusion of any standard header.  * It should only handle pre-processor defines.  *  * See section B.2.7 of 1003.1b-1993   *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_VERSION
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_VERSION
value|199009L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test for visibility of pre-existing POSIX.4 features that should really  * be conditional.  If _POSIX_C_SOURCE and _POSIX_SOURCE are not  * defined then permit the pre-existing features to show up:  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIX4_VISIBLE_HISTORICALLY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test for visibility of additional POSIX.4 features:  */
end_comment

begin_if
if|#
directive|if
name|_POSIX_VERSION
operator|>=
literal|199309L
operator|&&
expr|\
operator|(
operator|!
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
operator|||
name|_POSIX_C_SOURCE
operator|>=
literal|199309L
operator|)
end_if

begin_define
define|#
directive|define
name|_POSIX4_VISIBLE
end_define

begin_define
define|#
directive|define
name|_POSIX4_VISIBLE_HISTORICALLY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I'm not sure if I'm allowed to do this, but at least initially  * it may catch some teething problems:  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
operator|&&
operator|(
name|_POSIX_C_SOURCE
operator|>
name|_POSIX_VERSION
operator|)
end_if

begin_error
error|#
directive|error
error|_POSIX_C_SOURCE> _POSIX_VERSION
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|POSIX4_VISIBLE
value|You missed the leading _!!
end_define

begin_define
define|#
directive|define
name|POSIX4_VISIBLE_FORCEABLY
value|You left the old define in the code!!
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS__POSIX_H_ */
end_comment

end_unit

