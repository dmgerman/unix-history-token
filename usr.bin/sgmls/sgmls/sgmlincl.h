begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SGMLINCL.H: Include file for parser core. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SGMLINCL
end_ifndef

begin_comment
comment|/* Don't include this file more than once. */
end_comment

begin_define
define|#
directive|define
name|SGMLINCL
value|1
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"std.h"
end_include

begin_include
include|#
directive|include
file|"entity.h"
end_include

begin_comment
comment|/* Templates for entity control blocks. */
end_comment

begin_include
include|#
directive|include
file|"action.h"
end_include

begin_comment
comment|/* Action names for all parsing. */
end_comment

begin_include
include|#
directive|include
file|"adl.h"
end_include

begin_comment
comment|/* Definitions for attribute list processing. */
end_comment

begin_include
include|#
directive|include
file|"error.h"
end_include

begin_comment
comment|/* Symbols for error codes. */
end_comment

begin_include
include|#
directive|include
file|"etype.h"
end_include

begin_comment
comment|/* Definitions for element type processing. */
end_comment

begin_include
include|#
directive|include
file|"keyword.h"
end_include

begin_comment
comment|/* Definitions for keyword processing. */
end_comment

begin_include
include|#
directive|include
file|"lextoke.h"
end_include

begin_comment
comment|/* Symbols for tokenization lexical classes. */
end_comment

begin_include
include|#
directive|include
file|"source.h"
end_include

begin_comment
comment|/* Templates for source entity control blocks. */
end_comment

begin_include
include|#
directive|include
file|"synxtrn.h"
end_include

begin_comment
comment|/* Declarations for concrete syntax constants. */
end_comment

begin_include
include|#
directive|include
file|"sgmlxtrn.h"
end_include

begin_comment
comment|/* External variable declarations. */
end_comment

begin_include
include|#
directive|include
file|"trace.h"
end_include

begin_comment
comment|/* Declarations for internal trace functions. */
end_comment

begin_include
include|#
directive|include
file|"sgmlmain.h"
end_include

begin_include
include|#
directive|include
file|"sgmlaux.h"
end_include

begin_include
include|#
directive|include
file|"sgmlfnsm.h"
end_include

begin_comment
comment|/* ANSI C: Declarations for SGML functions. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef SGMLINCL */
end_comment

end_unit

