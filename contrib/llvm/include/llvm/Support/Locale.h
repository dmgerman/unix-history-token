begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_LOCALE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_LOCALE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
name|namespace
name|locale
block|{
name|int
name|columnWidth
parameter_list|(
name|StringRef
name|s
parameter_list|)
function_decl|;
name|bool
name|isPrint
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
block|}
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_LOCALE_H
end_comment

end_unit

