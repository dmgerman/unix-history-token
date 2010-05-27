begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -DGNU_KEYWORDS -std=gnu89 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -DGNU_KEYWORDS -std=c99 -fgnu-keywords -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=c99 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -std=gnu89 -fno-gnu-keywords -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|GNU_KEYWORDS
asm|asm ("ret" : :);
else|#
directive|else
name|int
name|asm
decl_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

