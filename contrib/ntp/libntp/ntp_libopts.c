begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_libopts.c  *  * Common code interfacing with Autogen's libopts command-line option  * processing.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|"ntp_libopts.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|Version
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* version.c for each program */
end_comment

begin_comment
comment|/*  * ntpOptionProcess() was a clone of libopts' optionProcess which  * overrode the --version output, appending detail from version.c  * which was not available at Autogen time.  This is now done via  * AutoOpts' version-proc = override in copyright.def, so this  * routine is a straightforward wrapper of optionProcess().  */
end_comment

begin_function
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
block|{
return|return
name|optionProcess
argument_list|(
name|pOpts
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * ntpOptionPrintVersion() replaces the stock optionPrintVersion() via  * version-proc = ntpOptionPrintVersion; in copyright.def.  It differs  * from the stock function by displaying the complete version string,  * including compile time which was unknown when Autogen ran.  *  * Like optionPrintVersion() this function must exit(0) rather than  * return.  */
end_comment

begin_function
name|void
name|ntpOptionPrintVersion
parameter_list|(
name|tOptions
modifier|*
name|pOpts
parameter_list|,
name|tOptDesc
modifier|*
name|pOD
parameter_list|)
block|{
name|UNUSED_ARG
argument_list|(
name|pOpts
argument_list|)
expr_stmt|;
name|UNUSED_ARG
argument_list|(
name|pOD
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|Version
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

