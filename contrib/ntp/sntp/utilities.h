begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|UTILITIES_H
end_ifndef

begin_define
define|#
directive|define
name|UTILITIES_H
end_define

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"ntp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"lib_strbuf.h"
end_include

begin_define
define|#
directive|define
name|HLINE
value|"--------------------------------------------------------------------------------\n"
end_define

begin_define
define|#
directive|define
name|PHLINE
value|fprintf(output, HLINE);
end_define

begin_define
define|#
directive|define
name|STDLINE
value|printf(HLINE);
end_define

begin_function_decl
name|void
name|pkt_output
parameter_list|(
name|struct
name|pkt
modifier|*
name|dpkg
parameter_list|,
name|int
name|pkt_length
parameter_list|,
name|FILE
modifier|*
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|l_fp_output
parameter_list|(
name|l_fp
modifier|*
name|ts
parameter_list|,
name|FILE
modifier|*
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|l_fp_output_bin
parameter_list|(
name|l_fp
modifier|*
name|ts
parameter_list|,
name|FILE
modifier|*
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|l_fp_output_dec
parameter_list|(
name|l_fp
modifier|*
name|ts
parameter_list|,
name|FILE
modifier|*
name|output
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|addrinfo_to_str
parameter_list|(
specifier|const
name|struct
name|addrinfo
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ss_to_str
parameter_list|(
name|sockaddr_u
modifier|*
name|saddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tv_to_str
parameter_list|(
specifier|const
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|hostnameaddr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|sockaddr_u
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTILITIES_H */
end_comment

end_unit

