begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2003 Networks Associates Technology, Inc.  * Copyright (c) 2004-2011 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * This software was developed for the FreeBSD Project by ThinkSec AS and  * Network Associates Laboratories, the Security Research Division of  * Network Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $OpenPAM: openpam_debug.h 938 2017-04-30 21:34:42Z des $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENPAM_DEBUG_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|OPENPAM_DEBUG_H_INCLUDED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OPENPAM_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|ENTER
parameter_list|()
value|openpam_log(PAM_LOG_LIBDEBUG, "entering")
end_define

begin_define
define|#
directive|define
name|ENTERI
parameter_list|(
name|i
parameter_list|)
value|do { \ 	int i_ = (i); \ 	if (i_> 0&& i_< PAM_NUM_ITEMS) \ 		openpam_log(PAM_LOG_LIBDEBUG, "entering: %s", pam_item_name[i_]); \ 	else \ 		openpam_log(PAM_LOG_LIBDEBUG, "entering: %d", i_); \ } while (0)
end_define

begin_define
define|#
directive|define
name|ENTERN
parameter_list|(
name|n
parameter_list|)
value|do { \ 	int n_ = (n); \ 	openpam_log(PAM_LOG_LIBDEBUG, "entering: %d", n_); \ } while (0)
end_define

begin_define
define|#
directive|define
name|ENTERS
parameter_list|(
name|s
parameter_list|)
value|do { \ 	const char *s_ = (s); \ 	if (s_ == NULL) \ 		openpam_log(PAM_LOG_LIBDEBUG, "entering: NULL"); \ 	else \ 		openpam_log(PAM_LOG_LIBDEBUG, "entering: '%s'", s_); \ } while (0)
end_define

begin_define
define|#
directive|define
name|ENTERF
parameter_list|(
name|f
parameter_list|)
value|do { \ 	int f_ = (f); \ 	if (f_>= 0&& f_<= OPENPAM_NUM_FEATURES) \ 		openpam_log(PAM_LOG_LIBDEBUG, "entering: %s", \ 		    openpam_features[f_].name); \ 	else \ 		openpam_log(PAM_LOG_LIBDEBUG, "entering: %d", f_); \ } while (0)
end_define

begin_define
define|#
directive|define
name|RETURNV
parameter_list|()
value|openpam_log(PAM_LOG_LIBDEBUG, "returning")
end_define

begin_define
define|#
directive|define
name|RETURNC
parameter_list|(
name|c
parameter_list|)
value|do { \ 	int c_ = (c); \ 	if (c_>= 0&& c_< PAM_NUM_ERRORS) \ 		openpam_log(PAM_LOG_LIBDEBUG, "returning %s", pam_err_name[c_]); \ 	else \ 		openpam_log(PAM_LOG_LIBDEBUG, "returning %d!", c_); \ 	return (c_); \ } while (0)
end_define

begin_define
define|#
directive|define
name|RETURNN
parameter_list|(
name|n
parameter_list|)
value|do { \ 	int n_ = (n); \ 	openpam_log(PAM_LOG_LIBDEBUG, "returning %d", n_); \ 	return (n_); \ } while (0)
end_define

begin_define
define|#
directive|define
name|RETURNP
parameter_list|(
name|p
parameter_list|)
value|do { \ 	void *p_ = (p); \ 	if (p_ == NULL) \ 		openpam_log(PAM_LOG_LIBDEBUG, "returning NULL"); \ 	else \ 		openpam_log(PAM_LOG_LIBDEBUG, "returning %p", p_); \ 	return (p_); \ } while (0)
end_define

begin_define
define|#
directive|define
name|RETURNS
parameter_list|(
name|s
parameter_list|)
value|do { \ 	const char *s_ = (s); \ 	if (s_ == NULL) \ 		openpam_log(PAM_LOG_LIBDEBUG, "returning NULL"); \ 	else \ 		openpam_log(PAM_LOG_LIBDEBUG, "returning '%s'", s_); \ 	return (s_); \ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ENTER
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ENTERI
parameter_list|(
name|i
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ENTERN
parameter_list|(
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ENTERS
parameter_list|(
name|s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ENTERF
parameter_list|(
name|f
parameter_list|)
end_define

begin_define
define|#
directive|define
name|RETURNV
parameter_list|()
value|return
end_define

begin_define
define|#
directive|define
name|RETURNC
parameter_list|(
name|c
parameter_list|)
value|return (c)
end_define

begin_define
define|#
directive|define
name|RETURNN
parameter_list|(
name|n
parameter_list|)
value|return (n)
end_define

begin_define
define|#
directive|define
name|RETURNP
parameter_list|(
name|p
parameter_list|)
value|return (p)
end_define

begin_define
define|#
directive|define
name|RETURNS
parameter_list|(
name|s
parameter_list|)
value|return (s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

