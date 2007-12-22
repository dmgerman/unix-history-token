begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Filename: env_vars.h  *  * Definition of environment variables, structures, and other globals.  *  * Revision information:  *  * 20AUG2004	kb_admin	initial creation  *  * BEGIN_KBDD_BLOCK  * No warranty, expressed or implied, is included with this software.  It is  * provided "AS IS" and no warranty of any kind including statutory or aspects  * relating to merchantability or fitness for any purpose is provided.  All  * intellectual property rights of others is maintained with the respective  * owners.  This software is not copyrighted and is intended for reference  * only.  * END_BLOCK  *  * $FreeBSD$  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ENV_VARS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ENV_VARS_H_
end_define

begin_comment
comment|/* each environment variable is a string following the standard command	*/
end_comment

begin_comment
comment|/* definition used by the interactive loader in the following format:	*/
end_comment

begin_comment
comment|/*<command><parm1><parm2> ...					*/
end_comment

begin_comment
comment|/* all environment variables (or commands) are stored in a string	*/
end_comment

begin_comment
comment|/* format: NULL-terminated.						*/
end_comment

begin_comment
comment|/* this implies that commands can never utilize 0-values: actual 0, not	*/
end_comment

begin_comment
comment|/* the string '0'.  this is not an issue as the string '0' is handled	*/
end_comment

begin_comment
comment|/* by the command parse routine.					*/
end_comment

begin_comment
comment|/* the following defines the maximum size of the environment for 	*/
end_comment

begin_comment
comment|/* including variables.							*/
end_comment

begin_comment
comment|/* this value must match that declared in the low-level file that	*/
end_comment

begin_comment
comment|/* actually reserves the space for the non-volatile environment.	*/
end_comment

begin_define
define|#
directive|define
name|MAX_ENV_SIZE_BYTES
value|0x100
end_define

begin_define
define|#
directive|define
name|MAX_BOOT_COMMANDS
value|10
end_define

begin_comment
comment|/* C-style reference section						*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_function_decl
specifier|extern
name|void
name|WriteCommandTable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SetBootCommand
parameter_list|(
name|int
name|index
parameter_list|,
name|char
modifier|*
name|command
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DumpBootCommands
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LoadBootCommands
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ExecuteEnvironmentFunctions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ENV_VARS_H_ */
end_comment

end_unit

