begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -I%S/Inputs %s
end_comment

begin_comment
comment|// As long as none of this crashes, we don't care about comments in
end_comment

begin_comment
comment|// preprocessor directives.
end_comment

begin_include
include|#
directive|include
file|"annotate-comments-preprocessor.h"
end_include

begin_comment
comment|/* Aaa. */
end_comment

begin_comment
comment|/* Bbb. */
end_comment

begin_include
include|#
directive|include
file|"annotate-comments-preprocessor.h"
end_include

begin_comment
comment|/* Aaa. */
end_comment

begin_include
include|#
directive|include
file|"annotate-comments-preprocessor.h"
end_include

begin_comment
comment|/** Aaa. */
end_comment

begin_include
include|#
directive|include
file|"annotate-comments-preprocessor.h"
end_include

begin_comment
comment|/**< Aaa. */
end_comment

begin_include
include|#
directive|include
file|"annotate-comments-preprocessor.h"
end_include

begin_comment
comment|// Aaa.
end_comment

begin_include
include|#
directive|include
file|"annotate-comments-preprocessor.h"
end_include

begin_comment
comment|/// Aaa.
end_comment

begin_include
include|#
directive|include
file|"annotate-comments-preprocessor.h"
end_include

begin_comment
comment|///< Aaa.
end_comment

begin_define
define|#
directive|define
name|A0
value|0
end_define

begin_define
define|#
directive|define
name|A1
value|1
end_define

begin_comment
comment|/* Aaa. */
end_comment

begin_define
define|#
directive|define
name|A2
value|1
end_define

begin_comment
comment|/** Aaa. */
end_comment

begin_define
define|#
directive|define
name|A3
value|1
end_define

begin_comment
comment|/**< Aaa. */
end_comment

begin_define
define|#
directive|define
name|A4
value|1
end_define

begin_comment
comment|// Aaa.
end_comment

begin_define
define|#
directive|define
name|A5
value|1
end_define

begin_comment
comment|/// Aaa.
end_comment

begin_define
define|#
directive|define
name|A6
value|1
end_define

begin_comment
comment|///< Aaa.
end_comment

begin_decl_stmt
name|int
name|A
index|[]
init|=
block|{
name|A0
block|,
name|A1
block|,
name|A2
block|,
name|A3
block|,
name|A4
block|,
name|A5
block|,
name|A6
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|A0
end_if

begin_comment
comment|/** Aaa. */
end_comment

begin_function_decl
name|int
name|f
parameter_list|(
name|int
name|a1
index|[
name|A1
index|]
parameter_list|,
name|int
name|a2
index|[
name|A2
index|]
parameter_list|,
name|int
name|a3
index|[
name|A3
index|]
parameter_list|,
name|int
name|a4
index|[
name|A4
index|]
parameter_list|,
name|int
name|a5
index|[
name|A5
index|]
parameter_list|,
name|int
name|a6
index|[
name|A6
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** Aaa. */
end_comment

begin_if
if|#
directive|if
name|A1
end_if

begin_comment
comment|/** Aaa. */
end_comment

begin_function_decl
name|int
name|g
parameter_list|(
name|int
name|a1
index|[
name|A1
index|]
parameter_list|,
name|int
name|a2
index|[
name|A2
index|]
parameter_list|,
name|int
name|a3
index|[
name|A3
index|]
parameter_list|,
name|int
name|a4
index|[
name|A4
index|]
parameter_list|,
name|int
name|a5
index|[
name|A5
index|]
parameter_list|,
name|int
name|a6
index|[
name|A6
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Aaa. */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_comment
comment|/** Aaa. */
end_comment

begin_define
define|#
directive|define
name|FOO
define|\
value|do {           \
comment|/* Aaa. */
value|\
comment|/** Aaa. */
value|\
comment|/**< Aaa. */
value|\     ;            \   } while(0)
end_define

begin_function
name|void
name|h
parameter_list|(
name|void
parameter_list|)
block|{
name|FOO
expr_stmt|;
block|}
end_function

end_unit

