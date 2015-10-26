begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|MAIN_H
end_ifndef

begin_define
define|#
directive|define
name|MAIN_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_include
include|#
directive|include
file|<isc/net.h>
end_include

begin_include
include|#
directive|include
file|<ntp.h>
end_include

begin_include
include|#
directive|include
file|<ntp_unixtime.h>
end_include

begin_include
include|#
directive|include
file|<ntp_stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ntp_intres.h>
end_include

begin_include
include|#
directive|include
file|<ntp_debug.h>
end_include

begin_include
include|#
directive|include
file|<timevalops.h>
end_include

begin_include
include|#
directive|include
file|<sntp-opts.h>
end_include

begin_include
include|#
directive|include
file|"crypto.h"
end_include

begin_function_decl
name|void
name|set_li_vn_mode
parameter_list|(
name|struct
name|pkt
modifier|*
name|spkt
parameter_list|,
name|char
name|leap
parameter_list|,
name|char
name|version
parameter_list|,
name|char
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sntp_main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|generate_pkt
parameter_list|(
name|struct
name|pkt
modifier|*
name|x_pkt
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|tv_xmt
parameter_list|,
name|int
name|key_id
parameter_list|,
name|struct
name|key
modifier|*
name|pkt_key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|handle_pkt
parameter_list|(
name|int
name|rpktl
parameter_list|,
name|struct
name|pkt
modifier|*
name|rpkt
parameter_list|,
name|sockaddr_u
modifier|*
name|host
parameter_list|,
specifier|const
name|char
modifier|*
name|hostname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|offset_calculation
parameter_list|(
name|struct
name|pkt
modifier|*
name|rpkt
parameter_list|,
name|int
name|rpktl
parameter_list|,
name|struct
name|timeval
modifier|*
name|tv_dst
parameter_list|,
name|double
modifier|*
name|offset
parameter_list|,
name|double
modifier|*
name|precision
parameter_list|,
name|double
modifier|*
name|root_dispersion
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|on_wire
parameter_list|(
name|struct
name|addrinfo
modifier|*
name|host
parameter_list|,
name|struct
name|addrinfo
modifier|*
name|bcastaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_time
parameter_list|(
name|double
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAIN_H */
end_comment

end_unit

