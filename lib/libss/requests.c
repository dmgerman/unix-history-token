begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Various minor routines...  *  * Copyright 1987, 1988, 1989 by MIT  *  * For copyright information, see copyright.h.  */
end_comment

begin_include
include|#
directive|include
file|"copyright.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ss_internal.h"
end_include

begin_define
define|#
directive|define
name|DECLARE
parameter_list|(
name|name
parameter_list|)
value|name(argc,argv,sci_idx)int argc,sci_idx;char **argv;
end_define

begin_comment
comment|/*  * ss_self_identify -- assigned by default to the "." request  */
end_comment

begin_function
name|void
name|DECLARE
parameter_list|(
name|ss_self_identify
parameter_list|)
block|{
specifier|register
name|ss_data
modifier|*
name|info
init|=
name|ss_info
argument_list|(
name|sci_idx
argument_list|)
decl_stmt|;
name|printf
argument_list|(
literal|"%s version %s\n"
argument_list|,
name|info
operator|->
name|subsystem_name
argument_list|,
name|info
operator|->
name|subsystem_version
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * ss_subsystem_name -- print name of subsystem  */
end_comment

begin_function
name|void
name|DECLARE
parameter_list|(
name|ss_subsystem_name
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|ss_info
argument_list|(
name|sci_idx
argument_list|)
operator|->
name|subsystem_name
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * ss_subsystem_version -- print version of subsystem  */
end_comment

begin_function
name|void
name|DECLARE
parameter_list|(
name|ss_subsystem_version
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|ss_info
argument_list|(
name|sci_idx
argument_list|)
operator|->
name|subsystem_version
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * ss_unimplemented -- routine not implemented (should be  * set up as (dont_list,dont_summarize))  */
end_comment

begin_function
name|void
name|DECLARE
parameter_list|(
name|ss_unimplemented
parameter_list|)
block|{
name|ss_perror
argument_list|(
name|sci_idx
argument_list|,
name|SS_ET_UNIMPLEMENTED
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

