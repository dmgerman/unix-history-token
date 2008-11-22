begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Juniper Networks  * Author: Alfred Perlstein  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice(s), this list of conditions and the following disclaimer as  *    the first lines of this file unmodified other than the possible   *    addition of one or more copyright notices.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice(s), this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER(S) BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCK_PROFILE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LOCK_PROFILE_H_
end_define

begin_comment
comment|/* temp stubs for lock profiling, not supported in 6.x (yet) */
end_comment

begin_define
define|#
directive|define
name|lock_profile_obtain_lock_success
parameter_list|(
name|lock_object
parameter_list|,
name|a0
parameter_list|,
name|a1
parameter_list|,
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|do { ; } while (0)
end_define

begin_define
define|#
directive|define
name|lock_profile_release_lock
parameter_list|(
name|lock_object
parameter_list|)
define|\
value|do { ; } while (0)
end_define

begin_define
define|#
directive|define
name|lock_profile_obtain_lock_failed
parameter_list|(
name|lock_object
parameter_list|,
name|contested
parameter_list|,
name|waittime
parameter_list|)
define|\
value|do { ; } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

