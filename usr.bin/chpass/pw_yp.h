begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1995  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * NIS interface routines for chpass  *   * Written by Bill Paul<wpaul@ctr.columbia.edu>  * Center for Telecommunications Research  * Columbia University, New York City  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|YP
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|<rpc/auth.h>
end_include

begin_include
include|#
directive|include
file|<rpc/auth_unix.h>
end_include

begin_comment
comment|/* Four possible return codes from use_yp() */
end_comment

begin_define
define|#
directive|define
name|USER_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|USER_YP_ONLY
value|1
end_define

begin_define
define|#
directive|define
name|USER_LOCAL_ONLY
value|2
end_define

begin_define
define|#
directive|define
name|USER_YP_AND_LOCAL
value|3
end_define

begin_decl_stmt
specifier|extern
name|int
name|force_old
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_use_yp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|suser_override
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|passwd
name|local_password
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|passwd
name|yp_password
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|copy_yp_pass
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|yp_domain
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|yp_server
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|yp_submit
name|__P
argument_list|(
operator|(
expr|struct
name|passwd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|use_yp
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|uid_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|get_yp_master
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yp_in_pw_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Yucky.  */
end_comment

begin_define
define|#
directive|define
name|GETPWUID
parameter_list|(
name|X
parameter_list|)
define|\
value|_use_yp = use_yp(NULL, X, 1);					\ 									\ 	if (_use_yp == USER_UNKNOWN) {					\ 		errx(1, "unknown user: uid %u", X);			\ 	}								\ 									\ 	if (_use_yp == USER_YP_ONLY) {					\ 		if (!force_local) {					\ 			_use_yp = 1;					\ 			pw = (struct passwd *)&yp_password;		\ 		} else							\ 			errx(1, "unknown local user: uid %u", X);	\ 	} else if (_use_yp == USER_LOCAL_ONLY) {			\ 		if (!force_yp) {					\ 			_use_yp = 0;					\ 			pw = (struct passwd *)&local_password;		\ 		} else							\ 			errx(1, "unknown NIS user: uid %u", X);		\ 	} else if (_use_yp == USER_YP_AND_LOCAL) {			\ 		if (!force_local&& (force_yp || yp_in_pw_file)) {	\ 			_use_yp = 1;					\ 			pw = (struct passwd *)&yp_password;		\ 		} else {						\ 			_use_yp = 0;					\ 			pw = (struct passwd *)&local_password;		\ 		}							\ 	}
end_define

begin_define
define|#
directive|define
name|GETPWNAM
parameter_list|(
name|X
parameter_list|)
define|\
value|_use_yp = use_yp(X, 0, 0);					\ 									\ 	if (_use_yp == USER_UNKNOWN) {					\ 		errx(1, "unknown user: %s", X);				\ 	}								\ 									\ 	if (_use_yp == USER_YP_ONLY) {					\ 		if (!force_local) {					\ 			_use_yp = 1;					\ 			pw = (struct passwd *)&yp_password;		\ 		} else							\ 			errx(1, "unknown local user: %s.", X);		\ 	} else if (_use_yp == USER_LOCAL_ONLY) {			\ 		if (!force_yp) {					\ 			_use_yp = 0;					\ 			pw = (struct passwd *)&local_password;		\ 		} else							\ 			errx(1, "unknown NIS user: %s.", X);		\ 	} else if (_use_yp == USER_YP_AND_LOCAL) {			\ 		if (!force_local&& (force_yp || yp_in_pw_file)) {	\ 			_use_yp = 1;					\ 			pw = (struct passwd *)&yp_password;		\ 		} else {						\ 			_use_yp = 0;					\ 			pw = (struct passwd *)&local_password;		\ 		}							\ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* YP */
end_comment

end_unit

