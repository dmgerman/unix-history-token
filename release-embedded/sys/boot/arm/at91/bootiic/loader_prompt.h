begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Filename: loader_prompt.h  *  * Definition of the interactive loader functions.  *  * Revision information:  *  * 20AUG2004	kb_admin	initial creation  *  * BEGIN_KBDD_BLOCK  * No warranty, expressed or implied, is included with this software.  It is  * provided "AS IS" and no warranty of any kind including statutory or aspects  * relating to merchantability or fitness for any purpose is provided.  All  * intellectual property rights of others is maintained with the respective  * owners.  This software is not copyrighted and is intended for reference  * only.  * END_BLOCK  *  * $FreeBSD$  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOADER_PROMPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_LOADER_PROMPT_H_
end_define

begin_define
define|#
directive|define
name|MAX_INPUT_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|MAX_COMMAND_PARAMS
value|10
end_define

begin_enum
enum|enum
block|{
name|COMMAND_INVALID
init|=
literal|0
block|,
name|COMMAND_COPY
block|,
name|COMMAND_DUMP
block|,
name|COMMAND_EXEC
block|,
name|COMMAND_HELP
block|,
name|COMMAND_LOCAL_IP
block|,
name|COMMAND_MAC
block|,
name|COMMAND_SERVER_IP
block|,
name|COMMAND_SET
block|,
name|COMMAND_TAG
block|,
name|COMMAND_TFTP
block|,
name|COMMAND_WRITE
block|,
name|COMMAND_XMODEM
block|,
name|COMMAND_FINAL_FLAG
block|}
name|e_cmd_t
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|command
decl_stmt|;
specifier|const
name|char
modifier|*
name|c_string
decl_stmt|;
block|}
name|command_entry_t
typedef|;
end_typedef

begin_function_decl
name|void
name|EnterInteractiveBootloader
parameter_list|(
name|int
function_decl|(
modifier|*
name|inputFunction
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|Bootloader
parameter_list|(
name|int
function_decl|(
modifier|*
name|inputFunction
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOADER_PROMPT_H_ */
end_comment

end_unit

