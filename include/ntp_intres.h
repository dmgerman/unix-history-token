begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_intres.h - client interface to blocking-worker name resolution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_INTRES_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_INTRES_H
end_define

begin_include
include|#
directive|include
file|<ntp_worker.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|WORKER
end_ifdef

begin_define
define|#
directive|define
name|INITIAL_DNS_RETRY
value|2
end_define

begin_comment
comment|/* seconds between queries */
end_comment

begin_comment
comment|/*  * you call getaddrinfo_sometime(name, service,&hints, retry, callback_func, context);  * later (*callback_func)(rescode, gai_errno, context, name, service, hints, ai_result) is called.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|gai_sometime_callback
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|addrinfo
modifier|*
parameter_list|,
specifier|const
name|struct
name|addrinfo
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|getaddrinfo_sometime
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|addrinfo
modifier|*
parameter_list|,
name|int
parameter_list|,
name|gai_sometime_callback
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * In gai_sometime_callback routines, the resulting addrinfo list is  * only available until the callback returns.  To hold on to the list  * of addresses after the callback returns, use copy_addrinfo_list():  *  * struct addrinfo *copy_addrinfo_list(const struct addrinfo *);  */
end_comment

begin_comment
comment|/*  * you call getnameinfo_sometime(sockaddr, namelen, servlen, flags, callback_func, context);  * later (*callback_func)(rescode, gni_errno, sockaddr, flags, name, service, context) is called.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|gni_sometime_callback
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|sockaddr_u
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|getnameinfo_sometime
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|gni_sometime_callback
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WORKER */
end_comment

begin_comment
comment|/* intres_timeout_req() is provided by the client, ntpd or sntp. */
end_comment

begin_function_decl
specifier|extern
name|void
name|intres_timeout_req
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_INTRES_H */
end_comment

end_unit

