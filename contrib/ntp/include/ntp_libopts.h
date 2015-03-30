begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_libopts.h  *  * Common code interfacing with Autogen's libopts command-line option  * processing.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_LIBOPTS_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_LIBOPTS_H
end_define

begin_include
include|#
directive|include
file|"autoopts/options.h"
end_include

begin_function_decl
specifier|extern
name|int
name|ntpOptionProcess
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ntpOptionPrintVersion
parameter_list|(
name|tOptions
modifier|*
parameter_list|,
name|tOptDesc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

