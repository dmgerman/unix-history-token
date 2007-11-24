begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * log.h - Used only under Windows NT by msyslog.c  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINNT_LOG_H
end_ifndef

begin_define
define|#
directive|define
name|WINNT_LOG_H
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|/* function declarations */
end_comment

begin_function_decl
name|void
name|addSourceToRegistry
parameter_list|(
name|LPSTR
name|pszAppname
parameter_list|,
name|LPSTR
name|pszMsgDLL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reportAnIEvent
parameter_list|(
name|DWORD
name|dwIdEvent
parameter_list|,
name|WORD
name|cStrings
parameter_list|,
name|LPTSTR
modifier|*
name|pszStrings
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reportAnWEvent
parameter_list|(
name|DWORD
name|dwIdEvent
parameter_list|,
name|WORD
name|cStrings
parameter_list|,
name|LPTSTR
modifier|*
name|pszStrings
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reportAnEEvent
parameter_list|(
name|DWORD
name|dwIdEvent
parameter_list|,
name|WORD
name|cStrings
parameter_list|,
name|LPTSTR
modifier|*
name|pszStrings
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MAX_MSG_LENGTH
value|1024
end_define

begin_define
define|#
directive|define
name|MSG_ID_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|MAX_INSERT_STRS
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINNT_LOG_H */
end_comment

end_unit

