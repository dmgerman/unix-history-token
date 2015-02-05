begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND INTERNET SOFTWARE CONSORTIUM  * DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL  * INTERNET SOFTWARE CONSORTIUM BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING  * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,  * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTSERVICE_H
end_ifndef

begin_define
define|#
directive|define
name|NTSERVICE_H
end_define

begin_define
define|#
directive|define
name|NTP_DISPLAY_NAME
value|"NetworkTimeProtocol"
end_define

begin_define
define|#
directive|define
name|NTP_SERVICE_NAME
value|"ntpd"
end_define

begin_function_decl
name|void
name|ntservice_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UpdateSCM
parameter_list|(
name|DWORD
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|WINAPI
name|ServiceControl
parameter_list|(
name|DWORD
name|dwCtrlCode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ntservice_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOL
name|ntservice_systemisshuttingdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOL
name|WINAPI
name|OnConsoleEvent
parameter_list|(
name|DWORD
name|dwCtrlType
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTSERVICE_H */
end_comment

end_unit

