begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// defstd.h -- define standard symbols for gold   -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_DEFSTD_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_DEFSTD_H
end_define

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_decl_stmt
name|namespace
name|gold
block|{
specifier|extern
name|void
name|define_standard_symbols
parameter_list|(
name|Symbol_table
modifier|*
parameter_list|,
specifier|const
name|Layout
modifier|*
parameter_list|,
name|Target
modifier|*
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_DEFSTD_H)
end_comment

end_unit

