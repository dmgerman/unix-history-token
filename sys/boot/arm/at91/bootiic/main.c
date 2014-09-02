begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  * Filename: main.c  *  * Basic entry points for top-level functions  *  * Revision information:  *  * 20AUG2004	kb_admin	initial creation  * 12JAN2005	kb_admin	cosmetic changes  * 29APR2005	kb_admin	modified boot delay  *  * BEGIN_KBDD_BLOCK  * No warranty, expressed or implied, is included with this software.  It is  * provided "AS IS" and no warranty of any kind including statutory or aspects  * relating to merchantability or fitness for any purpose is provided.  All  * intellectual property rights of others is maintained with the respective  * owners.  This software is not copyrighted and is intended for reference  * only.  * END_BLOCK  *  * $FreeBSD$  ******************************************************************************/
end_comment

begin_include
include|#
directive|include
file|"env_vars.h"
end_include

begin_include
include|#
directive|include
file|"at91rm9200_lowlevel.h"
end_include

begin_include
include|#
directive|include
file|"loader_prompt.h"
end_include

begin_include
include|#
directive|include
file|"emac.h"
end_include

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_function_decl
name|int
name|main
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * .KB_C_FN_DEFINITION_START  * int main(void)  *  This global function waits at least one second, but not more than two   * seconds, for input from the serial port.  If no response is recognized,  * it acts according to the parameters specified by the environment.  For   * example, the function might boot an operating system.  Do not return  * from this function.  * .KB_C_FN_DEFINITION_END  */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|InitEEPROM
argument_list|()
expr_stmt|;
name|EMAC_Init
argument_list|()
expr_stmt|;
name|LoadBootCommands
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|"\n\rKB9202(www.kwikbyte.com)\n\rAuto boot..\n\r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|getc
argument_list|(
literal|1
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|ExecuteEnvironmentFunctions
argument_list|()
expr_stmt|;
name|Bootloader
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

end_unit

