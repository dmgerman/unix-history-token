begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* script-c.h -- C interface for linker scripts in gold.  */
end_comment

begin_comment
comment|/* This file exists so that both the bison parser and script.cc can    include it, so that they can communicate back and forth.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_SCRIPT_C_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_SCRIPT_C_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|"yyscript.h"
comment|/* The bison parser function.  */
specifier|extern
name|int
name|yyparse
parameter_list|(
name|void
modifier|*
name|closure
parameter_list|)
function_decl|;
comment|/* Called by the bison parser skeleton to return the next token.  */
specifier|extern
name|int
name|yylex
parameter_list|(
name|YYSTYPE
modifier|*
parameter_list|,
name|void
modifier|*
name|closure
parameter_list|)
function_decl|;
comment|/* Called by the bison parser skeleton to report an error.  */
specifier|extern
name|void
name|yyerror
parameter_list|(
name|void
modifier|*
name|closure
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Called by the bison parser to add a file to the link.  */
specifier|extern
name|void
name|script_add_file
parameter_list|(
name|void
modifier|*
name|closure
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Called by the bison parser to start and stop a group.  */
specifier|extern
name|void
name|script_start_group
parameter_list|(
name|void
modifier|*
name|closure
parameter_list|)
function_decl|;
specifier|extern
name|void
name|script_end_group
parameter_list|(
name|void
modifier|*
name|closure
parameter_list|)
function_decl|;
comment|/* Called by the bison parser to start and end an AS_NEEDED list.  */
specifier|extern
name|void
name|script_start_as_needed
parameter_list|(
name|void
modifier|*
name|closure
parameter_list|)
function_decl|;
specifier|extern
name|void
name|script_end_as_needed
parameter_list|(
name|void
modifier|*
name|closure
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(GOLD_SCRIPT_C_H) */
end_comment

end_unit

