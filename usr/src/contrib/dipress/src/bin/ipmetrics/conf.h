begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1986, Xerox Corporation  *  * the structure to define a composition system  */
end_comment

begin_struct
struct|struct
name|CompositionSwitch
block|{
name|char
modifier|*
name|cs_systemName
decl_stmt|;
comment|/* string name of the composition system */
name|int
name|cs_readConfigFile
decl_stmt|;
comment|/* boolean: do we read the configuration file or not? */
name|int
function_decl|(
modifier|*
name|cs_initializationProc
function_decl|)
parameter_list|()
function_decl|;
comment|/* procedure to call before processing any font vectors */
name|int
function_decl|(
modifier|*
name|cs_fontProc
function_decl|)
parameter_list|()
function_decl|;
comment|/* procedure to call for each font vector */
name|int
function_decl|(
modifier|*
name|cs_cleanUpProc
function_decl|)
parameter_list|()
function_decl|;
comment|/* procedure to call after processing all font vectors */
block|}
struct|;
end_struct

end_unit

